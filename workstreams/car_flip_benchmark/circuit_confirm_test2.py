#!/usr/bin/env python3
"""Test confirm/back buttons after letting circuit select settle.

Hypothesis: transition animation needs to complete before B (back) is accepted.
Also tests the flag variable that gates the button check in transition_handler_a.
"""

import os
import sys

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from investigate import MednafenBot, wsl_path

SAVE_STATE = os.path.join(PROJECT, "build", "save_states", "circuit_select_slot0.mc0")
CUE_PATH = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
IPC_DIR = os.path.join(PROJECT, "build", "debug_ipc")

WATCH_ADDRS = [
    (0x0607887F, 1, "dispatch_state"),
    (0x0607EADB, 1, "circuit_idx"),
    (0x06078634, 1, "mode_byte"),
    (0x06078635, 1, "display_flag"),
    (0x0605AB18, 1, "sym_0605AB18"),  # guard in game_state_dispatch
]


def read_mem(bot, addr, size):
    tmp = os.path.join(IPC_DIR, "tmp_memdump.bin")
    if os.path.exists(tmp):
        os.remove(tmp)
    ack = bot.dump_mem_bin(f"{addr:X}", f"{size:X}", tmp)
    if not ack:
        return None
    try:
        with open(tmp, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def read_all(bot):
    vals = {}
    for addr, size, label in WATCH_ADDRS:
        data = read_mem(bot, addr, size)
        if data:
            vals[label] = data[0]
    return vals


def main():
    bot = MednafenBot(IPC_DIR, wsl_path(CUE_PATH))
    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Mednafen did not start")
        return

    bot.frame_advance(1)
    state_wsl = wsl_path(SAVE_STATE)
    ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
    if not ack or "error" in ack:
        print(f"FAIL: {ack}")
        bot.quit()
        return

    bot.frame_advance(1)
    print(f"At save state: {read_all(bot)}")

    # Let it settle for varying amounts of frames, checking state
    for wait in [30, 60, 120, 180]:
        ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
        bot.frame_advance(wait)
        vals = read_all(bot)
        print(f"After {wait:3d} idle frames: {vals}")

    print()

    # Now test buttons after 120 frames of settling
    for button in ["A", "B", "C", "START"]:
        ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
        bot.frame_advance(120)  # let animation complete
        before = read_all(bot)

        bot.input_press(button)
        bot.frame_advance(15)
        bot.input_release(button)
        bot.frame_advance(10)
        after = read_all(bot)

        changes = []
        for key in before:
            if before[key] != after[key]:
                changes.append(f"{key}: {before[key]} -> {after[key]}")
        if changes:
            print(f"  {button:5s} (after 120f settle): {', '.join(changes)}")
        else:
            print(f"  {button:5s} (after 120f settle): no changes")

    bot.quit()
    print("\nDone.")


if __name__ == "__main__":
    main()
