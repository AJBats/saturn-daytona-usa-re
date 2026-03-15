#!/usr/bin/env python3
"""Interactive steering trace — launches visible Mednafen, loads race
save state, records call trace + input trace while you drive.

Usage:
    python workstreams/car_flip_benchmark/steering_trace.py

Press LEFT/RIGHT to steer. Press Escape in Mednafen to quit.
The script stops tracing and saves output when Mednafen exits.
"""

import os
import sys
import time
import tempfile

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "mednafen"))
from mednafen_bot import MednafenBot

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

SAVE_STATE = os.path.join(
    PROJECT, "build", "save_states",
    "daytona_rebuilt.8180a74b2162ad4393a9630de58615e3.mc0",
)
CUE = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
OUTPUT_DIR = os.path.join(PROJECT, "workstreams", "car_flip_benchmark")


def main():
    if not os.path.exists(SAVE_STATE):
        print(f"Save state not found: {SAVE_STATE}")
        sys.exit(1)

    call_trace_path = os.path.join(OUTPUT_DIR, "steering_call_trace.txt")
    input_trace_path = os.path.join(OUTPUT_DIR, "steering_input_trace.txt")

    with tempfile.TemporaryDirectory() as ipc_dir:
        bot = MednafenBot(ipc_dir, CUE, show=True, sound=True, verbose=True)
        print("Launching Mednafen...")
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
        bot.send(f"load_state {SAVE_STATE}")
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
            while bot.proc and bot.proc.poll() is None:
                time.sleep(0.5)
        except KeyboardInterrupt:
            print("\nCtrl+C — shutting down Mednafen...")

        bot.quit()
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
