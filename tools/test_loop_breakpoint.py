#!/usr/bin/env python3
"""Test whether FUN_0600B6A0 is called during racing.

Sets a breakpoint at FUN_0600B6A0, advances 1 frame during racing.
If the breakpoint fires, the function is being called.

Usage:
    python tools/test_loop_breakpoint.py [--re-tests] [-v]
"""

import os
import sys
import time
import argparse

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from test_boot_auto import MednafenBot, wsl_path

RENDER_CS0_LOOP = "0600B6A0"


def wait_for_any(bot, keywords, timeout=30):
    """Wait for ack containing any of the given keywords. Returns (keyword, content)."""
    deadline = time.time() + timeout
    last_content = None
    while time.time() < deadline:
        if bot.proc and bot.proc.poll() is not None:
            return None, None
        if os.path.exists(bot.ack_file):
            try:
                with open(bot.ack_file) as f:
                    content = f.read().strip()
            except (IOError, PermissionError):
                time.sleep(0.05)
                continue
            if content != last_content:
                last_content = content
                if bot.verbose:
                    print(f"  [ack] {content[:120]}")
            if content != bot.last_ack:
                for kw in keywords:
                    if kw in content:
                        bot.last_ack = content
                        return kw, content
        time.sleep(0.05)
    return None, None


def run_test(re_tests=False, verbose=False):
    cue_win = os.path.join(
        PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue"
    )
    cue_wsl = wsl_path(cue_win)

    ipc_dir = os.path.join(PROJECT, "build", "loop_bp_ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    circuit_confirm = "B" if re_tests else "C"

    nav_trace = [
        (162,  "input START"),
        (167,  "input_release START"),
        (1174, "input START"),
        (1180, "input_release START"),
        (1360, "input START"),
        (1365, "input_release START"),
        (1510, "input C"),
        (1515, "input_release C"),
        (1700, f"input {circuit_confirm}"),
        (1705, f"input_release {circuit_confirm}"),
        (1900, "input START"),
        (1905, "input_release START"),
    ]

    bot = MednafenBot(ipc_dir, cue_wsl, verbose=verbose)

    print("Launching Mednafen...")
    if not bot.start(timeout=45):
        print("FAIL: Mednafen did not start")
        return False

    print(f"Navigating to race... (circuit confirm={circuit_confirm})")

    current_frame = 0
    for target_frame, action in nav_trace:
        delta = target_frame - current_frame
        if delta > 0:
            ack = bot.send_and_wait(
                f"frame_advance {delta}", "done frame_advance", timeout=180,
            )
            if not ack:
                print(f"FAIL: frame_advance to {target_frame} timed out")
                bot.quit()
                return False
            current_frame = target_frame
        parts = action.split()
        if parts[0] == "input":
            bot.send_and_wait(f"input {parts[1]}", "ok input")
        elif parts[0] == "input_release":
            bot.send_and_wait(f"input_release {parts[1]}", "ok input_release")

    # Advance to rolling start
    print("Advancing to rolling start (frame 4200)...")
    ack = bot.send_and_wait(
        f"frame_advance {4200 - current_frame}", "done frame_advance", timeout=180,
    )
    if not ack:
        print("FAIL: could not reach rolling start")
        bot.quit()
        return False
    current_frame = 4200

    # Set breakpoint at FUN_0600B6A0
    print(f"Setting breakpoint at FUN_0600B6A0 (0x{RENDER_CS0_LOOP})...")
    ack = bot.send_and_wait(f"breakpoint {RENDER_CS0_LOOP}", "ok breakpoint", timeout=10)
    if not ack:
        print("FAIL: could not set breakpoint")
        bot.quit()
        return False
    print(f"  {ack}")

    # Advance 1 frame — if BP fires, we get "break" instead of "done frame_advance"
    print("Advancing 1 frame with breakpoint active...")
    bot.send(f"frame_advance 1")

    kw, content = wait_for_any(bot, ["break pc=", "done frame_advance"], timeout=30)

    if kw is None:
        print("FAIL: timeout waiting for frame advance or break")
    elif "break" in (kw or ""):
        print(f"  BREAKPOINT HIT: {content}")
        print(f"\n  ==> FUN_0600B6A0 IS being called during racing")
        # Clear BP and let execution continue
        bot.send_and_wait("breakpoint_clear", "ok breakpoint_clear", timeout=5)
    elif "done frame_advance" in (kw or ""):
        print(f"  Frame completed without hitting breakpoint")
        print(f"\n  ==> FUN_0600B6A0 is NOT being called during racing")

    bot.quit()
    return True


def main():
    parser = argparse.ArgumentParser(description="Loop breakpoint test")
    parser.add_argument("--re-tests", action="store_true")
    parser.add_argument("-v", "--verbose", action="store_true")
    args = parser.parse_args()

    run_test(re_tests=args.re_tests, verbose=args.verbose)


if __name__ == "__main__":
    main()
