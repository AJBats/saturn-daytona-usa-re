#!/usr/bin/env python3
"""Integration test: dump_region → action → dump_region → mem_diff.

Boots to menu, dumps WRAM, presses DOWN, dumps again, diffs.
This exercises the full Strategy C pipeline.

Usage:
    python workstreams/enhance_re_tooling/test_mem_diff_live.py
"""

import os
import sys
import time
import tempfile
import subprocess

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from investigate import MednafenBot, wsl_path, parse_trace, replay_to_state

TRACE_FILE = os.path.join(PROJECT, "build", "golden_trace", "arcade_full.txt")
CUE_FILE = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
MAP_FILE = os.path.join(PROJECT, "reimpl", "build", "daytona.map")


def main():
    cue_wsl = wsl_path(CUE_FILE)
    dump_dir = tempfile.mkdtemp(prefix="memdiff_test_")
    ipc_dir = tempfile.mkdtemp(prefix="memdiff_ipc_")

    bot = MednafenBot(ipc_dir, cue_wsl)
    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Mednafen didn't start")
        return 1

    # Replay to menu
    print("Replaying to menu state...")
    events = parse_trace(TRACE_FILE)
    if not replay_to_state(bot, "menu", events):
        print("FAIL: Could not replay to menu state")
        return 1
    print(f"At menu (frame {bot.current_frame})")

    # Dump WRAM (before)
    before_path = os.path.join(dump_dir, "wram_before.bin")
    wsl_before = wsl_path(before_path)
    bot.send_and_wait(f"dump_region wram_high {wsl_before}", "ok dump_region", timeout=30)
    deadline = time.time() + 5
    while time.time() < deadline and not os.path.exists(before_path):
        time.sleep(0.1)
    print(f"Before dump: {os.path.getsize(before_path)} bytes")

    # Advance a few frames idle (baseline)
    bot.frame_advance(5)

    # Press DOWN and advance
    bot.input_press("DOWN")
    bot.frame_advance(5)
    bot.input_release("DOWN")
    bot.frame_advance(2)

    # Dump WRAM (after)
    after_path = os.path.join(dump_dir, "wram_after.bin")
    wsl_after = wsl_path(after_path)
    bot.send_and_wait(f"dump_region wram_high {wsl_after}", "ok dump_region", timeout=30)
    deadline = time.time() + 5
    while time.time() < deadline and not os.path.exists(after_path):
        time.sleep(0.1)
    print(f"After dump: {os.path.getsize(after_path)} bytes")

    # Quit emulator
    try:
        bot.send_and_wait("quit", "quit", timeout=5)
    except Exception:
        pass

    # Run mem_diff
    print("\n--- Running mem_diff ---")
    diff_json = os.path.join(dump_dir, "diff.json")
    result = subprocess.run(
        [sys.executable, os.path.join(PROJECT, "tools", "mem_diff.py"),
         before_path, after_path,
         "--base-addr", "0x06000000",
         "--map", MAP_FILE,
         "--top", "30",
         "-o", diff_json],
        capture_output=True, text=True
    )
    print(result.stdout)
    if result.stderr:
        print("STDERR:", result.stderr[:300])

    # Also run mem_scan delta to find increased values
    print("\n--- Running mem_scan delta (changed, 16-bit) ---")
    result2 = subprocess.run(
        [sys.executable, os.path.join(PROJECT, "tools", "mem_scan.py"),
         "delta", before_path, after_path,
         "-m", "changed", "-w", "16", "-b", "0x06000000"],
        capture_output=True, text=True
    )
    lines = result2.stdout.strip().split("\n")
    # Print first and last few lines
    for line in lines[:5]:
        print(line)
    if len(lines) > 10:
        print(f"  ... ({len(lines) - 10} more lines) ...")
        for line in lines[-5:]:
            print(line)

    # Verify diff.json exists and has content
    if os.path.exists(diff_json):
        import json
        with open(diff_json) as f:
            dj = json.load(f)
        num_changes = dj['summary']['num_ranges']
        total_bytes = dj['summary']['total_bytes_changed']
        print(f"\nDiff JSON: {num_changes} ranges, {total_bytes} bytes changed")
        if num_changes > 0:
            print("PASS: Memory diff pipeline works end-to-end")
            return 0
        else:
            print("FAIL: No changes detected (game state didn't change?)")
            return 1
    else:
        print("FAIL: diff.json not created")
        return 1


if __name__ == "__main__":
    sys.exit(main())
