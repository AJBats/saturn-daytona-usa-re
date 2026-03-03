#!/usr/bin/env python3
"""Interactive steering trace — launches visible WSL Mednafen, loads race
save state, records call trace + input trace while you drive.

Usage:
    python workstreams/car_flip_benchmark/steering_trace.py

Press LEFT/RIGHT to steer. Press Escape in Mednafen to quit.
The script stops tracing and saves output when Mednafen exits.
"""

import os
import sys
import time
import subprocess
import tempfile

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

SAVE_STATE = os.path.join(
    PROJECT, "build", "save_states",
    "daytona_rebuilt.8180a74b2162ad4393a9630de58615e3.mc0",
)
CUE = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
OUTPUT_DIR = os.path.join(PROJECT, "workstreams", "car_flip_benchmark")


def wsl_path(win_path):
    drive = win_path[0].lower()
    rest = win_path[2:].replace("\\", "/")
    return f"/mnt/{drive}{rest}"


class MednafenBot:
    def __init__(self, ipc_dir):
        self.ipc_dir = ipc_dir
        self.action_file = os.path.join(ipc_dir, "mednafen_action.txt")
        self.ack_file = os.path.join(ipc_dir, "mednafen_ack.txt")
        self.seq = 0
        self.proc = None

    def start(self, timeout=30):
        for f in [self.action_file, self.ack_file]:
            if os.path.exists(f):
                os.remove(f)

        mednafen_wsl = wsl_path(os.path.join(PROJECT, "mednafen", "src", "mednafen"))
        ipc_wsl = wsl_path(self.ipc_dir)
        cue_wsl = wsl_path(CUE)

        # Sound ON, automation enabled, visible window
        launch_cmd = (
            f'export DISPLAY=:0; '
            f'rm -f "$HOME/.mednafen/mednafen.lck"; '
            f'"{mednafen_wsl}" '
            f'--automation "{ipc_wsl}" "{cue_wsl}"'
        )

        self.proc = subprocess.Popen(
            ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", launch_cmd],
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )

        deadline = time.time() + timeout
        while time.time() < deadline:
            if os.path.exists(self.ack_file):
                with open(self.ack_file) as f:
                    if "ready" in f.read():
                        return True
            time.sleep(0.2)
        return False

    def send(self, cmd):
        self.seq += 1
        padding = "." * (self.seq % 16)
        tmp = self.action_file + ".tmp"
        with open(tmp, "w", newline="\n") as f:
            f.write(f"# {self.seq}{padding}\n")
            f.write(cmd + "\n")
        if os.path.exists(self.action_file):
            os.remove(self.action_file)
        os.rename(tmp, self.action_file)

    def wait_ack(self, keyword, timeout=30):
        deadline = time.time() + timeout
        while time.time() < deadline:
            if self.proc and self.proc.poll() is not None:
                return None
            if os.path.exists(self.ack_file):
                try:
                    with open(self.ack_file) as f:
                        content = f.read().strip()
                    if keyword in content:
                        return content
                except (IOError, PermissionError):
                    pass
            time.sleep(0.1)
        return None

    def alive(self):
        return self.proc and self.proc.poll() is None


def main():
    if not os.path.exists(SAVE_STATE):
        print(f"Save state not found: {SAVE_STATE}")
        sys.exit(1)

    call_trace_path = wsl_path(os.path.join(OUTPUT_DIR, "steering_call_trace.txt"))
    input_trace_path = wsl_path(os.path.join(OUTPUT_DIR, "steering_input_trace.txt"))
    state_wsl = wsl_path(SAVE_STATE)

    with tempfile.TemporaryDirectory() as ipc_dir:
        bot = MednafenBot(ipc_dir)
        print("Launching WSL Mednafen (visible, with sound)...")
        if not bot.start():
            print("Failed to start Mednafen")
            sys.exit(1)
        print("Mednafen ready.")

        # Unpause and show window
        bot.send("continue")
        bot.wait_ack("continue")
        bot.send("show_window")
        bot.wait_ack("show_window")
        print("Window visible.")

        # Load save state
        print("Loading race start save state...")
        bot.send(f"load_state {state_wsl}")
        ack = bot.wait_ack("load_state")
        if not ack or "error" in ack:
            print(f"Failed to load state: {ack}")
            sys.exit(1)
        print(f"  {ack}")

        # Start traces
        bot.send(f"call_trace {call_trace_path}")
        ack = bot.wait_ack("call_trace")
        print(f"  Call trace: {ack}")

        bot.send(f"input_trace {input_trace_path}")
        ack = bot.wait_ack("input_trace")
        print(f"  Input trace: {ack}")

        print()
        print("=" * 60)
        print("  TRACING ACTIVE — you have control!")
        print("  Steer with LEFT/RIGHT. Let the car coast (no gas).")
        print("  Close Mednafen window or press Escape when done.")
        print("=" * 60)
        print()

        # Wait for user to close Mednafen (Ctrl+C to force quit)
        try:
            while bot.alive():
                time.sleep(0.5)
        except KeyboardInterrupt:
            print("\nCtrl+C — killing Mednafen...")
            bot.proc.terminate()
            try:
                bot.proc.wait(timeout=3)
            except subprocess.TimeoutExpired:
                bot.proc.kill()
                bot.proc.wait()

        print("Mednafen exited.")

    # Check output
    call_out = os.path.join(OUTPUT_DIR, "steering_call_trace.txt")
    input_out = os.path.join(OUTPUT_DIR, "steering_input_trace.txt")

    for path, label in [(call_out, "Call trace"), (input_out, "Input trace")]:
        if os.path.exists(path):
            size = os.path.getsize(path)
            lines = sum(1 for _ in open(path))
            print(f"  {label}: {path} ({lines} lines, {size:,} bytes)")
        else:
            print(f"  {label}: NOT FOUND")


if __name__ == "__main__":
    main()
