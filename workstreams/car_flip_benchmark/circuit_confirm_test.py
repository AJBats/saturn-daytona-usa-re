#!/usr/bin/env python3
"""Find which buttons are confirm/back on circuit select screen.

Tests A, B, C, START with enough frames for state transitions.
Monitors sym_0607887F (game state dispatch variable).
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
    (0x0607887F, 1, "sym_0607887F (dispatch state)"),
    (0x0607EADB, 1, "circuit index 1"),
    (0x0607EADF, 1, "circuit index 2"),
    (0x0605AD10, 1, "g_game_state"),
    (0x06078635, 1, "sym_06078635 (display flag)"),
    (0x06078634, 1, "sym_06078634 (mode byte)"),
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
            vals[label] = data[0] if size == 1 else int.from_bytes(data, 'big')
    return vals


def test_button(bot, state_wsl, button, hold_frames=10, after_frames=5):
    """Test a button press with enough frames for state transition."""
    ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
    if not ack or "error" in ack:
        return None, None

    bot.frame_advance(1)
    before = read_all(bot)

    bot.input_press(button)
    bot.frame_advance(hold_frames)
    bot.input_release(button)
    bot.frame_advance(after_frames)

    after = read_all(bot)
    return before, after


def main():
    bot = MednafenBot(IPC_DIR, wsl_path(CUE_PATH))
    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Mednafen did not start")
        return

    bot.frame_advance(1)
    state_wsl = wsl_path(SAVE_STATE)

    # Quick initial state check
    ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
    bot.frame_advance(1)
    initial = read_all(bot)
    print(f"Initial state: {initial}\n")

    # Test each button
    for button in ["A", "B", "C", "START", "X", "Y", "Z"]:
        before, after = test_button(bot, state_wsl, button, hold_frames=15, after_frames=10)
        if before is None:
            print(f"  {button}: FAILED")
            continue

        changes = []
        for key in before:
            if before[key] != after[key]:
                changes.append(f"{key}: {before[key]} -> {after[key]}")
        if changes:
            print(f"  {button}: {', '.join(changes)}")
        else:
            print(f"  {button}: no changes")

    bot.quit()
    print("\nDone.")


if __name__ == "__main__":
    main()
