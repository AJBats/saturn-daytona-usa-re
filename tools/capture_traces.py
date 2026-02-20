#!/usr/bin/env python3
"""capture_traces.py — Capture unified traces for two disc images.

Boots each disc in deterministic mode, enables unified tracing from frame 0,
advances exactly N frames, stops trace, and quits.

Usage:
    python tools/capture_traces.py --frames 1000
"""

import os
import sys
import time
import subprocess
import argparse

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE_REBUILT = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_RETAIL = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)",
                          "Daytona USA (USA).cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")
TRACEDIR = os.path.join(PROJDIR, "build", "traces")


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
        print(f"    [{self.name}] {ack}")

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


def kill_stale():
    subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
                    "pkill -9 -f 'mednafen.*--automation' 2>/dev/null; true"],
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    time.sleep(0.5)


def capture_trace(name, cue_path, trace_path, num_frames):
    """Boot a disc, enable unified trace, advance N frames, stop."""
    print(f"\n{'='*60}")
    print(f"  CAPTURING: {name}")
    print(f"  CUE: {cue_path}")
    print(f"  Trace: {trace_path}")
    print(f"  Frames: {num_frames}")
    print(f"{'='*60}")

    ipc_dir = os.path.join(TMPDIR, f"trace_{name}")
    emu = MednafenInstance(name, cue_path, ipc_dir)

    kill_stale()
    emu.start()

    # Set deterministic mode FIRST (before any frames run)
    print("    Setting deterministic mode...")
    emu.send("deterministic")

    # Enable unified trace
    trace_wsl = win_to_wsl(trace_path)
    print(f"    Enabling unified trace -> {trace_wsl}")
    ack = emu.send(f"unified_trace {trace_wsl}")
    print(f"    {ack}")

    # Advance frames in batches
    BATCH = 50
    print(f"    Advancing {num_frames} frames (batches of {BATCH})...")
    t0 = time.time()
    for start in range(0, num_frames, BATCH):
        n = min(BATCH, num_frames - start)
        try:
            emu.frame_advance(n, timeout=120)
        except TimeoutError:
            print(f"    *** HANG at frame ~{start}")
            break
        done = start + n
        if done % 200 == 0 or done >= num_frames:
            elapsed = time.time() - t0
            print(f"    frame {done}/{num_frames} ({elapsed:.1f}s)")

    # Stop trace
    print("    Stopping unified trace...")
    emu.send("unified_trace_stop")

    elapsed = time.time() - t0
    emu.quit()

    # Report
    if os.path.exists(trace_path):
        size = os.path.getsize(trace_path)
        # Count lines quickly
        with open(trace_path, "rb") as f:
            lines = sum(1 for _ in f)
        print(f"    Done: {size:,} bytes, {lines:,} lines ({elapsed:.1f}s)")
    else:
        print(f"    WARNING: trace file not created!")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--frames", type=int, default=1000,
                        help="Number of frames to capture (default: 1000)")
    args = parser.parse_args()

    os.makedirs(TRACEDIR, exist_ok=True)

    print("="*60)
    print("  TRACE CAPTURE — Padded Retail vs Free")
    print("="*60)

    # Trace 1: Padded retail (currently on rebuilt disc)
    capture_trace(
        "padded_retail",
        CUE_REBUILT,
        os.path.join(TRACEDIR, f"unified_padded_retail_{args.frames}f.txt"),
        args.frames,
    )

    # Now inject the free binary and capture its trace
    print(f"\n{'='*60}")
    print("  INJECTING FREE BINARY FOR TRACE 2")
    print(f"{'='*60}")

    free_bin = os.path.join(PROJDIR, "reimpl", "build", "APROG.BIN")
    if not os.path.exists(free_bin):
        print(f"  ERROR: {free_bin} not found. Run 'make -C reimpl free' first.")
        sys.exit(1)

    # Verify it's the free build (should be 394900 bytes)
    free_size = os.path.getsize(free_bin)
    print(f"  Free binary: {free_bin} ({free_size} bytes)")
    if free_size != 394900:
        print(f"  WARNING: Expected 394900 bytes, got {free_size}!")

    result = subprocess.run(
        ["python", os.path.join(PROJDIR, "tools", "inject_binary.py"), free_bin],
        capture_output=True, text=True
    )
    if result.returncode != 0:
        print(f"  Injection failed:\n{result.stderr}")
        sys.exit(1)
    print("  Injection OK")

    # Trace 2: Free build
    capture_trace(
        "free_nofixes",
        CUE_REBUILT,
        os.path.join(TRACEDIR, f"unified_free_nofixes_{args.frames}f.txt"),
        args.frames,
    )

    # Summary
    print(f"\n{'='*60}")
    print("  CAPTURE COMPLETE")
    print(f"{'='*60}")
    for name in [f"unified_padded_retail_{args.frames}f.txt",
                 f"unified_free_nofixes_{args.frames}f.txt"]:
        path = os.path.join(TRACEDIR, name)
        if os.path.exists(path):
            size = os.path.getsize(path)
            with open(path, "rb") as f:
                lines = sum(1 for _ in f)
            print(f"  {name}: {size:,} bytes, {lines:,} lines")
    print(f"\n  Next: compare with tools/compare_traces.py")


if __name__ == "__main__":
    main()
