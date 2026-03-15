#!/usr/bin/env python3
"""Interactive car select trace — launches visible Mednafen, loads car
select save state, records call trace + input trace while you switch cars.

Usage:
    python workstreams/car_flip_benchmark/car_select_trace.py

Press LEFT/RIGHT to switch car selection. Close window or Ctrl+C when done.
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
    "daytona_rebuilt.de440c102ec0826964f11d287fa25ac0.mc0",
)
CUE = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
OUTPUT_DIR = os.path.join(PROJECT, "workstreams", "car_flip_benchmark")


def main():
    if not os.path.exists(SAVE_STATE):
        print(f"Save state not found: {SAVE_STATE}")
        sys.exit(1)

    call_trace_path = os.path.join(OUTPUT_DIR, "carsel_call_trace.txt")
    input_trace_path = os.path.join(OUTPUT_DIR, "carsel_input_trace.txt")

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
        print("Loading car select save state...")
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
        print("  Let it idle a few seconds, then press LEFT/RIGHT")
        print("  to switch car selection a few times.")
        print("  Close Mednafen window or Ctrl+C when done.")
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
    for name, path in [("Call trace", os.path.join(OUTPUT_DIR, "carsel_call_trace.txt")),
                        ("Input trace", os.path.join(OUTPUT_DIR, "carsel_input_trace.txt"))]:
        if os.path.exists(path):
            size = os.path.getsize(path)
            lines = sum(1 for _ in open(path))
            print(f"  {name}: {path} ({lines} lines, {size:,} bytes)")
        else:
            print(f"  {name}: NOT FOUND")


if __name__ == "__main__":
    main()
