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
import subprocess
import argparse

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def wsl_path(win_path):
    """Convert Windows path to WSL path."""
    drive = win_path[0].lower()
    rest = win_path[2:].replace("\\", "/")
    return f"/mnt/{drive}{rest}"


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
    trace_path_wsl = wsl_path(trace_path)

    # IPC directory
    ipc_dir = os.path.join(PROJECT, "build", "trace_ipc")
    os.makedirs(ipc_dir, exist_ok=True)
    ipc_dir_wsl = wsl_path(ipc_dir)

    action_file = os.path.join(ipc_dir, "mednafen_action.txt")
    ack_file = os.path.join(ipc_dir, "mednafen_ack.txt")

    # Clean IPC files
    for f in [action_file, ack_file]:
        if os.path.exists(f):
            os.remove(f)

    # Launch Mednafen
    mednafen_wsl = wsl_path(os.path.join(PROJECT, "mednafen", "src", "mednafen"))
    cue_wsl = wsl_path(cue_win)

    # Controls: configured in ~/.mednafen/mednafen.cfg (WSL side).
    # First run: press Alt+Shift+1 in Mednafen to configure, then it saves.
    # Windows Mednafen config is at external_resources/mednafen-1.32.1-win64/mednafen.cfg
    # for reference (WASD + JKL layout).

    launch_cmd = (
        f'export DISPLAY=:0; '
        f'rm -f "$HOME/.mednafen/mednafen.lck"; '
        f'"{mednafen_wsl}" '
        f'--automation "{ipc_dir_wsl}" "{cue_wsl}"'
    )

    print(f"Launching Mednafen...")
    print(f"  Disc: {args.disc}")
    print(f"  Trace: {trace_path}")
    print()

    proc = subprocess.Popen(
        ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", launch_cmd],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )

    # Wait for ready
    deadline = time.time() + 30
    ready = False
    while time.time() < deadline:
        if os.path.exists(ack_file):
            try:
                with open(ack_file) as f:
                    content = f.read().strip()
                if "ready" in content:
                    ready = True
                    break
            except (IOError, PermissionError):
                pass
        time.sleep(0.2)

    if not ready:
        print("ERROR: Mednafen did not start in 30s")
        proc.kill()
        return 1

    # Helper to send commands
    seq = [0]
    last_ack = [""]

    def send(cmd, timeout=10):
        seq[0] += 1
        padding = "." * (seq[0] % 16)
        tmp = action_file + ".tmp"
        with open(tmp, "w", newline="\n") as f:
            f.write(f"# {seq[0]}{padding}\n")
            f.write(cmd + "\n")
        if os.path.exists(action_file):
            os.remove(action_file)
        os.rename(tmp, action_file)

        # Wait for ack change
        last_ack[0] = ""
        try:
            with open(ack_file) as f:
                last_ack[0] = f.read().strip()
        except (IOError, FileNotFoundError):
            pass

        dl = time.time() + timeout
        while time.time() < dl:
            try:
                with open(ack_file) as f:
                    content = f.read().strip()
                if content != last_ack[0]:
                    last_ack[0] = content
                    return content
            except (IOError, PermissionError):
                pass
            time.sleep(0.05)
        return None

    # Show window
    send("show_window")

    # Start input trace
    ack = send(f"input_trace {trace_path_wsl}")
    if ack:
        print("Input trace recording started.")
    else:
        print("WARNING: input_trace command may not have been acknowledged")

    # Unpause — let the user play
    send("run")

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
        proc.wait()
    except KeyboardInterrupt:
        print("\nInterrupted — shutting down...")
        send("quit")
        try:
            proc.wait(timeout=5)
        except subprocess.TimeoutExpired:
            proc.kill()

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
