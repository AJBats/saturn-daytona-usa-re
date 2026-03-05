#!/usr/bin/env python3
"""Navigate into an actual race and take in-race screenshots.

Extends the car select navigation to press START at car select,
wait through the loading/countdown, and capture screenshots during
actual racing with 3D car objects visible.

Usage:
    python tools/test_race_screenshot.py [-v] [--re-tests]
"""

import os
import sys
import time
import argparse

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from test_boot_auto import MednafenBot, wsl_path


def make_trace(circuit_confirm="C"):
    """Build navigation trace all the way to in-race with accelerator held."""
    return [
        # Boot through BIOS
        (162,  "input START"),
        (167,  "input_release START"),
        # Attract -> title
        (1174, "input START"),
        (1180, "input_release START"),
        # Title -> mode select
        (1360, "input START"),
        (1365, "input_release START"),
        # Mode select: C = confirm (ARCADE mode)
        (1510, "input C"),
        (1515, "input_release C"),
        # Circuit select: confirm
        (1700, f"input {circuit_confirm}"),
        (1705, f"input_release {circuit_confirm}"),
        # Car select: press START to begin race immediately
        (1900, "input START"),
        (1905, "input_release START"),
        # Hold accelerator (A button) early so we keep up with the pack
        (4100, "input A"),
        # Rolling start happens ~frame 4300-4500, all cars bunched together
        # Capture RIGHT during rolling start when opponents are close
        (4350, "screenshot race_rolling_1"),
        (4450, "screenshot race_rolling_2"),
        (4550, "screenshot race_rolling_3"),
        # Shortly after start — cars still relatively close
        (4800, "screenshot race_early_1"),
        (5100, "screenshot race_early_2"),
        (5500, "screenshot race_mid"),
        # Release A at end
        (5550, "input_release A"),
    ]


def run_navigation(verbose=False, re_tests=False):
    """Navigate to race and take screenshots."""
    cue_win = os.path.join(
        PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue"
    )
    cue_wsl = wsl_path(cue_win)

    ipc_dir = os.path.join(PROJECT, "build", "race_screenshot_ipc")
    screenshot_dir = os.path.join(PROJECT, "build", "screenshots", "race_test")
    os.makedirs(ipc_dir, exist_ok=True)
    os.makedirs(screenshot_dir, exist_ok=True)

    # Delete pre-existing screenshots
    import glob as _glob
    for f in _glob.glob(os.path.join(screenshot_dir, "race_*.png")):
        os.remove(f)

    circuit_confirm = "B" if re_tests else "C"
    trace = make_trace(circuit_confirm)

    bot = MednafenBot(ipc_dir, cue_wsl, verbose=verbose)

    print("Launching WSL Mednafen...")
    if not bot.start(timeout=45):
        print("FAIL: Mednafen did not start in 45s")
        return False

    confirm_note = f" (circuit confirm={circuit_confirm})" if re_tests else ""
    print(f"Mednafen ready. Navigating to race...{confirm_note}")

    current_frame = 0
    screenshots_taken = []

    for target_frame, action in trace:
        frames_to_advance = target_frame - current_frame
        if frames_to_advance > 0:
            ack = bot.send_and_wait(
                f"frame_advance {frames_to_advance}",
                "done frame_advance",
                timeout=180,
            )
            if not ack:
                print(f"FAIL: frame_advance to {target_frame} timed out")
                bot.quit()
                return False
            current_frame = target_frame

        parts = action.split()
        cmd_type = parts[0]

        if cmd_type == "input":
            button = parts[1]
            ack = bot.send_and_wait(f"input {button}", "ok input")
            if not ack:
                print(f"FAIL: input {button} at frame {target_frame} timed out")
                bot.quit()
                return False
            print(f"  Frame {target_frame}: pressed {button}")

        elif cmd_type == "input_release":
            button = parts[1]
            bot.send_and_wait(f"input_release {button}", "ok input_release")

        elif cmd_type == "screenshot":
            stage_name = parts[1]
            screenshot_path = os.path.join(screenshot_dir, f"{stage_name}.png")
            screenshot_path_wsl = wsl_path(screenshot_path)

            ack = bot.send_and_wait(
                f"screenshot {screenshot_path_wsl}",
                "ok screenshot",
            )
            if not ack:
                print(f"FAIL: screenshot {stage_name} timed out")
                continue

            deadline = time.time() + 5
            while time.time() < deadline and not os.path.exists(screenshot_path):
                time.sleep(0.2)

            if os.path.exists(screenshot_path):
                print(f"  Frame {target_frame}: screenshot saved -> {screenshot_path}")
                screenshots_taken.append(screenshot_path)
            else:
                print(f"  Frame {target_frame}: screenshot file not found!")

    cpu_errors = bot.check_stderr()
    if cpu_errors:
        print(f"\nFATAL: {len(cpu_errors)} CPU error(s) detected:")
        for err in cpu_errors[:10]:
            print(f"  {err}")

    bot.quit()

    print(f"\nDone. {len(screenshots_taken)} screenshots captured:")
    for path in screenshots_taken:
        print(f"  {path}")

    return len(screenshots_taken) > 0


def main():
    parser = argparse.ArgumentParser(description="In-race screenshot test")
    parser.add_argument(
        "-v", "--verbose", action="store_true",
        help="Verbose IPC logging"
    )
    parser.add_argument(
        "--re-tests", action="store_true",
        help="RE_TESTS build: use B to confirm on circuit select (Goal 2 C/B swap)"
    )
    args = parser.parse_args()

    success = run_navigation(verbose=args.verbose, re_tests=args.re_tests)
    return 0 if success else 1


if __name__ == "__main__":
    sys.exit(main())
