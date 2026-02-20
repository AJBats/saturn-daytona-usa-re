#!/usr/bin/env python3
"""capture_insn_traces.py — Capture per-instruction traces for retail + free builds.

Captures every SH-2 instruction around the first unified trace divergence point
(line 901455) for both retail and free builds, enabling cycle-by-cycle comparison.

Usage:
    python tools/capture_insn_traces.py
"""

import os
import re
import sys
import time
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE_RETAIL = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)",
                          "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TRACEDIR = os.path.join(PROJDIR, "build", "traces")
TMPDIR = os.path.join(PROJDIR, ".tmp")

# Capture window: unified trace lines around the divergence
# Line 901455 is where the 23-cycle delta first appears (frame boundary)
START_LINE = 901450
STOP_LINE = 901460

# We need enough frames to reach unified line ~901455.
# 520 frames = 896K lines (not enough). 1000 frames = 5.68M lines.
# Use 540 to have margin (901455 / (896155/520) * 1.05 ~ 550).
NUM_FRAMES = 550


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


def run_capture(name, cue_path, insn_trace_path):
    """Run one emulator instance, capturing insn trace around the divergence."""
    ipc_dir = os.path.join(TMPDIR, f"insn_ipc_{name}")
    insn_wsl = win_to_wsl(insn_trace_path)

    print(f"\n{'='*60}")
    print(f"  INSN TRACE CAPTURE — {name}")
    print(f"  CUE:    {cue_path}")
    print(f"  Output: {insn_trace_path}")
    print(f"  Window: unified lines {START_LINE} to {STOP_LINE}")
    print(f"{'='*60}")

    emu = MednafenInstance(name, cue_path, ipc_dir)

    print("\nLaunching Mednafen...")
    emu.start()

    print("Setting deterministic mode...")
    emu.send("deterministic")

    # Enable unified trace (needed for line counting)
    unified_path = os.path.join(TRACEDIR, f"unified_{name}_insn.txt")
    unified_wsl = win_to_wsl(unified_path)
    print(f"Enabling unified trace for line counting -> {unified_wsl}")
    emu.send(f"unified_trace {unified_wsl}")

    # Enable insn trace with range
    print(f"Enabling insn trace: lines {START_LINE} to {STOP_LINE} -> {insn_wsl}")
    ack = emu.send(f"insn_trace {insn_wsl} {START_LINE} {STOP_LINE}")
    print(f"  {ack}")

    # Advance frames
    print(f"\nAdvancing {NUM_FRAMES} frames...")
    t0 = time.time()
    BATCH = 50
    for start in range(0, NUM_FRAMES, BATCH):
        n = min(BATCH, NUM_FRAMES - start)
        try:
            ack = emu.frame_advance(n, timeout=120)
        except TimeoutError:
            print(f"\n  *** HANG at frame ~{start}")
            break
        cyc = extract_cycle(ack)
        done = start + n
        elapsed = time.time() - t0
        fps = done / elapsed if elapsed > 0 else 0
        print(f"  frame {done:5d}/{NUM_FRAMES}  cycle={cyc}  ({fps:.1f} fps)")

    # Stop traces
    print("\nStopping traces...")
    try:
        emu.send("insn_trace_stop")
        emu.send("unified_trace_stop")
    except Exception as e:
        print(f"  stop error: {e}")

    emu.quit()

    elapsed = time.time() - t0
    if os.path.exists(insn_trace_path):
        size_kb = os.path.getsize(insn_trace_path) / 1024
        print(f"  Done — {elapsed:.1f}s, insn trace: {size_kb:.1f} KB")
    else:
        print(f"  WARNING: insn trace not found at {insn_trace_path}")

    return insn_trace_path


def main():
    os.makedirs(TRACEDIR, exist_ok=True)
    kill_stale()

    retail_insn = os.path.join(TRACEDIR, "insn_retail_wide.txt")
    free_insn = os.path.join(TRACEDIR, "insn_free_wide.txt")

    # Capture retail
    run_capture("retail", CUE_RETAIL, retail_insn)

    # Kill stale before second run
    kill_stale()

    # Capture free
    if not os.path.exists(CUE_FREE):
        print(f"\nERROR: Free build disc not found at {CUE_FREE}")
        print("Run: make -C reimpl free-disc")
        sys.exit(1)
    run_capture("free", CUE_FREE, free_insn)

    # Quick preview
    print(f"\n{'='*60}")
    print("  CAPTURE COMPLETE")
    print(f"  Retail: {retail_insn}")
    print(f"  Free:   {free_insn}")
    print(f"{'='*60}")

    for path, name in [(retail_insn, "RETAIL"), (free_insn, "FREE")]:
        if os.path.exists(path):
            with open(path, "r") as f:
                lines = f.readlines()
            print(f"\n  {name}: {len(lines)} lines")
            # Show first/last few data lines
            data = [l for l in lines if not l.startswith("#")]
            if data:
                print(f"    First: {data[0].rstrip()}")
                print(f"    Last:  {data[-1].rstrip()}")


if __name__ == "__main__":
    main()
