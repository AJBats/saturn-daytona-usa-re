#!/usr/bin/env python3
"""unified_trace.py — Capture unified SH2+CDB trace of Daytona USA builds.

Runs any Daytona USA disc image in our deterministic debug Mednafen,
capturing both SH-2 call trace (Master + Slave) and CD Block events into
one chronologically interleaved log file.

Usage:
    python tools/unified_trace_retail.py [--frames N]
    python tools/unified_trace_retail.py --cue path/to/disc.cue --name free --frames 1000
    python tools/unified_trace_retail.py --hang-timeout 30  # detect hangs

Output: build/traces/unified_<name>_<N>f.txt
"""

import argparse
import os
import re
import sys
import time
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE_RETAIL = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)",
                          "Daytona USA (USA).cue")
TRACEDIR = os.path.join(PROJDIR, "build", "traces")
TMPDIR = os.path.join(PROJDIR, ".tmp")


def win_to_wsl(path):
    path = path.replace("\\", "/")
    if len(path) >= 2 and path[1] == ":":
        drive = path[0].lower()
        return f"/mnt/{drive}{path[2:]}"
    return path


class MednafenInstance:
    def __init__(self, name, cue_path, ipc_dir):
        self.name = name
        self.cue_path = cue_path
        self.ipc_dir = ipc_dir
        self.ipc_dir_wsl = win_to_wsl(ipc_dir)
        self.action_file = os.path.join(ipc_dir, "mednafen_action.txt")
        self.ack_file = os.path.join(ipc_dir, "mednafen_ack.txt")
        self.process = None
        self.last_ack = ""
        self._cmd_seq = 0

    def start(self):
        os.makedirs(self.ipc_dir, exist_ok=True)
        for f in [self.action_file, self.ack_file]:
            if os.path.exists(f):
                os.remove(f)
        home_wsl = f"/tmp/mdfn_home_{self.name}"
        # Clean slate: nuke any prior home dir so NVRAM/save state doesn't
        # persist between runs (backup RAM differences cause cycle drift).
        setup_cmd = (
            f'rm -rf "{home_wsl}" && '
            f'mkdir -p "{home_wsl}/.mednafen/firmware" '
            f'"{home_wsl}/.mednafen/pgconfig" '
            f'"{home_wsl}/.mednafen/cheats" '
            f'"{home_wsl}/.mednafen/snaps" '
            f'"{home_wsl}/.mednafen/sav" && '
            f'cp /root/.mednafen/firmware/* "{home_wsl}/.mednafen/firmware/" 2>/dev/null; true'
        )
        subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c", setup_cmd],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        mednafen_wsl = win_to_wsl(MEDNAFEN)
        cue_wsl = win_to_wsl(self.cue_path)
        launch_cmd = (
            f'export HOME="{home_wsl}" DISPLAY=:0; '
            f'rm -f "{home_wsl}/.mednafen/mednafen.lck"; '
            f'"{mednafen_wsl}" '
            f'--sound 0 --automation "{self.ipc_dir_wsl}" "{cue_wsl}"'
        )
        self.log_path = os.path.join(self.ipc_dir, "mednafen_stdout.log")
        self._log_file = open(self.log_path, "w")
        self.process = subprocess.Popen(
            ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", launch_cmd],
            stdout=self._log_file, stderr=subprocess.PIPE,
        )
        ack = self._wait_ack("ready", timeout=30)
        print(f"  [{self.name}] {ack}")

    def _write_action(self, cmd):
        self._cmd_seq += 1
        padding = "." * (self._cmd_seq % 16)
        tmp = self.action_file + ".tmp"
        with open(tmp, "w", newline="\n") as f:
            f.write(f"# {self._cmd_seq}{padding}\n")
            f.write(cmd + "\n")
        if os.path.exists(self.action_file):
            os.remove(self.action_file)
        os.rename(tmp, self.action_file)

    def send(self, cmd, timeout=30):
        self.last_ack = self._read_ack() or ""
        self._write_action(cmd)
        if self.process and self.process.poll() is not None:
            raise RuntimeError(f"[{self.name}] exited (code={self.process.returncode})")
        return self._wait_ack_change(timeout=timeout)

    def _read_ack(self):
        try:
            with open(self.ack_file, "r") as f:
                return f.read().strip()
        except (FileNotFoundError, IOError):
            return None

    def _wait_ack(self, contains, timeout=30):
        deadline = time.time() + timeout
        while time.time() < deadline:
            ack = self._read_ack()
            if ack and contains in ack:
                return ack
            time.sleep(0.1)
        raise TimeoutError(f"[{self.name}] Timeout waiting for '{contains}'")

    def _wait_ack_change(self, timeout=30):
        deadline = time.time() + timeout
        while time.time() < deadline:
            ack = self._read_ack()
            if ack and ack != self.last_ack:
                self.last_ack = ack
                return ack
            time.sleep(0.05)
        raise TimeoutError(f"[{self.name}] Timeout (last ack: {self.last_ack[:80]})")

    def frame_advance(self, n=1, timeout=None):
        t = timeout or max(60, n * 2)
        ack = self.send(f"frame_advance {n}", timeout=t)
        if ack.startswith("ok frame_advance"):
            ack = self._wait_ack_change(timeout=t)
        return ack

    def quit(self):
        try:
            self.send("quit", timeout=5)
        except Exception:
            pass
        if self.process:
            self.process.terminate()
            try:
                self.process.wait(timeout=5)
            except Exception:
                self.process.kill()
        if hasattr(self, '_log_file'):
            self._log_file.close()


def extract_cycle(ack_str):
    m = re.search(r'cycle=(\d+)', ack_str)
    return int(m.group(1)) if m else None


def kill_stale():
    subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
                    "pkill -9 -f 'mednafen.*--automation' 2>/dev/null; true"],
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    time.sleep(0.5)


def main():
    parser = argparse.ArgumentParser(description="Unified trace of Daytona USA builds")
    parser.add_argument("--frames", type=int, default=1000, help="Number of frames to capture")
    parser.add_argument("--cue", type=str, default=None, help="Path to .cue file (default: retail)")
    parser.add_argument("--name", type=str, default="retail", help="Build name for output file")
    parser.add_argument("--hang-timeout", type=int, default=60,
                        help="Seconds before declaring a hang on frame_advance (default: 60)")
    args = parser.parse_args()

    max_frames = args.frames
    cue_path = os.path.abspath(args.cue) if args.cue else CUE_RETAIL
    build_name = args.name
    hang_timeout = args.hang_timeout

    os.makedirs(TRACEDIR, exist_ok=True)
    out_file = os.path.join(TRACEDIR, f"unified_{build_name}_{max_frames}f.txt")
    out_wsl = win_to_wsl(out_file)
    ipc_dir = os.path.join(TMPDIR, f"unified_ipc_{build_name}")

    print("=" * 60)
    print(f"  UNIFIED TRACE — {build_name} — {max_frames} frames")
    print(f"  CUE:    {cue_path}")
    print(f"  Output: {out_file}")
    print(f"  Hang timeout: {hang_timeout}s per batch")
    print("=" * 60)

    kill_stale()
    os.makedirs(TMPDIR, exist_ok=True)

    emu = MednafenInstance(build_name.upper(), cue_path, ipc_dir)

    print("\nLaunching Mednafen...")
    emu.start()

    print("Setting deterministic mode (fixed RTC)...")
    ack = emu.send("deterministic")
    print(f"  {ack}")

    print(f"Enabling unified trace -> {out_wsl}")
    ack = emu.send(f"unified_trace {out_wsl}")
    print(f"  {ack}")

    print(f"\nAdvancing {max_frames} frames...")
    t0 = time.time()

    hung = False
    hang_frame = None
    frames_done = 0
    BATCH = 50
    for start in range(0, max_frames, BATCH):
        n = min(BATCH, max_frames - start)
        try:
            ack = emu.frame_advance(n, timeout=hang_timeout)
        except TimeoutError:
            hung = True
            hang_frame = start  # last completed batch boundary
            print(f"\n  *** HANG DETECTED at frame ~{start} (timeout after {hang_timeout}s)")
            print(f"  Stopping trace with data captured so far...")
            break
        cyc = extract_cycle(ack)
        elapsed = time.time() - t0
        done = start + n
        frames_done = done
        fps = done / elapsed if elapsed > 0 else 0
        print(f"  frame {done:5d}/{max_frames}  cycle={cyc}  ({fps:.1f} frames/sec)")

    print("\nStopping trace...")
    try:
        ack = emu.send("unified_trace_stop")
        print(f"  {ack}")
    except Exception as e:
        print(f"  trace stop failed (expected if hung): {e}")

    emu.quit()

    elapsed = time.time() - t0
    # Check output size
    if os.path.exists(out_file):
        size_mb = os.path.getsize(out_file) / (1024 * 1024)
        print(f"\n{'=' * 60}")
        if hung:
            print(f"  HUNG at frame ~{hang_frame} — {elapsed:.1f}s elapsed")
        else:
            print(f"  DONE — {elapsed:.1f}s elapsed, {frames_done} frames")
        print(f"  Output: {out_file} ({size_mb:.1f} MB)")
        print(f"{'=' * 60}")
    else:
        print(f"\n  WARNING: output file not found at {out_file}")
        print(f"  Check WSL path: {out_wsl}")

if __name__ == "__main__":
    main()
