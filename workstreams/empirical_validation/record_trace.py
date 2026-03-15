#!/usr/bin/env python3
"""Record an input trace for replay testing.

Launches Mednafen with automation mode, shows the window, and records
every button press/release with the exact frame number. Play through
the game normally, then close Mednafen. The trace file can be used to
build frame-precise replay scripts.

Usage:
    python tools/record_trace.py                     # default: rebuilt disc
    python tools/record_trace.py vanilla             # original disc
    python tools/record_trace.py --output my_trace   # custom output name

Output:
    build/traces/<name>.txt — raw input trace (frame + PRESS/RELEASE + BUTTON)

Controls (WASD layout, matching Windows Mednafen config):
    W/A/S/D     = D-pad (UP/LEFT/DOWN/RIGHT)
    J           = A button (gas / confirm)
    K           = B button (brake)
    L           = C button (view change)
    Enter       = START
    U           = X button
    I           = Y button
    O           = Z button
    Numpad 7    = L trigger
    Numpad 9    = R trigger

    To reconfigure: press Alt+Shift+1 in Mednafen
    Escape      = quit
"""

import os
import sys
import time
import argparse

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "mednafen"))
from mednafen_bot import MednafenBot


def main():
    parser = argparse.ArgumentParser(description="Record input trace for replay")
    parser.add_argument(
        "disc", nargs="?", default="rebuilt",
        help="vanilla, rebuilt, or path to CUE file"
    )
    parser.add_argument(
        "--output", "-o", default=None,
        help="Trace output name (without extension). Default: auto-timestamped"
    )
    args = parser.parse_args()

    # Resolve disc path
    if args.disc == "vanilla":
        cue_win = os.path.join(
            PROJECT, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue"
        )
    elif args.disc == "rebuilt":
        cue_win = os.path.join(
            PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue"
        )
    else:
        cue_win = args.disc

    if not os.path.exists(cue_win):
        print(f"ERROR: Disc not found: {cue_win}")
        if args.disc == "rebuilt":
            print("Run: make -C reimpl disc")
        return 1

    # Trace output path
    trace_dir = os.path.join(PROJECT, "build", "traces")
    os.makedirs(trace_dir, exist_ok=True)

    if args.output:
        trace_name = args.output
    else:
        timestamp = time.strftime("%Y%m%d_%H%M%S")
        trace_name = f"trace_{timestamp}"

    trace_path = os.path.join(trace_dir, f"{trace_name}.txt")

    # IPC directory
    ipc_dir = os.path.join(PROJECT, "build", "trace_ipc")

    print(f"Launching Mednafen...")
    print(f"  Disc: {args.disc}")
    print(f"  Trace: {trace_path}")
    print()

    # Controls: configured in mednafen home config.
    # First run: press Alt+Shift+1 in Mednafen to configure, then it saves.
    # Windows Mednafen config is at external_resources/mednafen-1.32.1-win64/mednafen.cfg
    # for reference (WASD + JKL layout).

    bot = MednafenBot(ipc_dir, cue_win, show=True)
    if not bot.start():
        print("ERROR: Mednafen did not start in 45s")
        return 1

    # Start input trace
    ack = bot.send_and_wait(f"input_trace {trace_path}", "ok input_trace")
    if ack:
        print("Input trace recording started.")
    else:
        print("WARNING: input_trace command may not have been acknowledged")

    # Unpause — let the user play
    bot.send_and_wait("run", "ok run")

    print()
    print("=" * 50)
    print("  RECORDING — play the game normally!")
    print()
    print("  Controls (WASD layout):")
    print("    W/A/S/D = D-pad (UP/LEFT/DOWN/RIGHT)")
    print("    J       = A (gas/confirm)")
    print("    K       = B (brake)")
    print("    L       = C (view)")
    print("    Enter   = START")
    print()
    print("  Take screenshots at key moments too!")
    print("  Close Mednafen when done (Escape)")
    print("=" * 50)
    print()

    # Wait for Mednafen to exit
    try:
        if bot.proc:
            bot.proc.wait()
    except KeyboardInterrupt:
        print("\nInterrupted — shutting down...")
        bot.quit()

    # Report results
    print()
    if os.path.exists(trace_path):
        with open(trace_path) as f:
            lines = [l for l in f if l.strip() and not l.startswith("#")]
        print(f"Trace saved: {trace_path}")
        print(f"  {len(lines)} input events recorded")

        # Show summary
        if lines:
            first = lines[0].strip()
            last = lines[-1].strip()
            print(f"  First: {first}")
            print(f"  Last:  {last}")
    else:
        print("WARNING: No trace file found. The recording may not have worked.")
        print(f"  Expected: {trace_path}")
        return 1

    print()
    print("Next step: use this trace to build a replay script")
    print(f"  python tools/build_replay.py {trace_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
