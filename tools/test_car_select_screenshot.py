#!/usr/bin/env python3
"""Navigate to car select screen and take a screenshot.

Uses MednafenBot to boot the disc, navigate through menus
(attract → title → mode select → circuit select → car select),
and capture a screenshot of the car select screen.

Usage:
    python tools/test_car_select_screenshot.py [-v] [--re-tests]

    --re-tests: Use B to confirm on circuit select (Goal 2 swaps C/B)
"""

import os
import sys
import time
import argparse

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from test_boot_auto import MednafenBot, wsl_path

def make_trace(circuit_confirm="C"):
    """Build navigation trace. circuit_confirm is "C" (vanilla) or "B" (RE_TESTS Goal 2)."""
    return [
        # Boot through BIOS
        (162,  "input START"),
        (167,  "input_release START"),
        # Attract → title
        (1174, "input START"),
        (1180, "input_release START"),
        # Title → mode select
        (1360, "input START"),
        (1365, "input_release START"),
        # Wait for mode select to settle, then press C to confirm (ARCADE mode)
        # Mode select: C = confirm (unaffected by RE_TESTS Goal 2)
        (1510, "input C"),
        (1515, "input_release C"),
        # Wait for circuit select screen to load (~150 frames)
        # Circuit select: C = confirm (vanilla), B = confirm (RE_TESTS Goal 2 swaps C/B)
        (1700, f"input {circuit_confirm}"),
        (1705, f"input_release {circuit_confirm}"),
        # Wait for car select screen to load (~200 frames)
        # Take screenshot at car select
        (1950, "screenshot car_select"),
        # Wait a bit more for the car to spin, take another
        (2100, "screenshot car_select_2"),
        (2250, "screenshot car_select_3"),
    ]


def run_navigation(verbose=False, re_tests=False):
    """Navigate to car select and take screenshots."""
    cue_win = os.path.join(
        PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue"
    )
    cue_wsl = wsl_path(cue_win)

    ipc_dir = os.path.join(PROJECT, "build", "car_select_ipc")
    screenshot_dir = os.path.join(PROJECT, "build", "screenshots", "car_select_test")
    os.makedirs(ipc_dir, exist_ok=True)
    os.makedirs(screenshot_dir, exist_ok=True)

    # Delete pre-existing screenshots to avoid stale file detection
    for name in ["car_select", "car_select_2", "car_select_3"]:
        path = os.path.join(screenshot_dir, f"{name}.png")
        if os.path.exists(path):
            os.remove(path)

    circuit_confirm = "B" if re_tests else "C"
    trace = make_trace(circuit_confirm)

    bot = MednafenBot(ipc_dir, cue_wsl, verbose=verbose)

    print("Launching WSL Mednafen...")
    if not bot.start(timeout=45):
        print("FAIL: Mednafen did not start in 45s")
        return False

    confirm_note = f" (circuit confirm={circuit_confirm})" if re_tests else ""
    print(f"Mednafen ready. Navigating to car select...{confirm_note}")

    current_frame = 0
    screenshots_taken = []

    for target_frame, action in trace:
        frames_to_advance = target_frame - current_frame
        if frames_to_advance > 0:
            ack = bot.send_and_wait(
                f"frame_advance {frames_to_advance}",
                "done frame_advance",
                timeout=120,
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

            # Wait for file to appear (DrvFS latency)
            deadline = time.time() + 5
            while time.time() < deadline and not os.path.exists(screenshot_path):
                time.sleep(0.2)

            if os.path.exists(screenshot_path):
                print(f"  Frame {target_frame}: screenshot saved -> {screenshot_path}")
                screenshots_taken.append(screenshot_path)
            else:
                print(f"  Frame {target_frame}: screenshot file not found!")

    # Check for fatal CPU errors
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
    parser = argparse.ArgumentParser(description="Car select screenshot test")
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
