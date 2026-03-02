#!/usr/bin/env python3
"""Verify circuit index variable by pressing LEFT/RIGHT sequentially.

Tests hypothesis: sym_0607EAD8+3 (0x0607EADB) is the circuit index.
Expected: RIGHT increments, LEFT decrements, wraps at 0 and 2.
"""

import os
import sys

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from investigate import MednafenBot, wsl_path

SAVE_STATE = os.path.join(PROJECT, "build", "save_states", "circuit_select_slot0.mc0")
CUE_PATH = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
IPC_DIR = os.path.join(PROJECT, "build", "debug_ipc")

# Candidate addresses to monitor
CANDIDATES = [
    (0x0607EADB, 1, "sym_0607EAD8+3"),
    (0x0607EADF, 1, "sym_0607EADC+3"),
    (0x0607864F, 1, "sym_0607864C+3 (frame counter?)"),
]


def read_mem(bot, addr, size):
    """Read memory region via dump_mem_bin to temp file, return bytes."""
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


def read_candidates(bot):
    """Read all candidate addresses and return dict of values."""
    values = {}
    for addr, size, label in CANDIDATES:
        data = read_mem(bot, addr, size)
        if data:
            values[label] = data[0] if size == 1 else int.from_bytes(data, 'big')
    return values


def press_and_read(bot, button, frames=5):
    """Press button, advance frames, release, advance 1 more, read values."""
    bot.input_press(button)
    bot.frame_advance(frames)
    bot.input_release(button)
    bot.frame_advance(1)
    return read_candidates(bot)


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

    # Read initial values
    vals = read_candidates(bot)
    print(f"Initial: {vals}")

    # Sequence: RIGHT, RIGHT, RIGHT, LEFT, LEFT, LEFT
    for button in ["RIGHT", "RIGHT", "RIGHT", "LEFT", "LEFT", "LEFT"]:
        vals = press_and_read(bot, button)
        print(f"After {button:5s}: {vals}")

    # Also test A, B, C buttons from initial state
    print("\n--- Button actions from initial state ---")
    for button in ["A", "B", "C"]:
        # Reload save state
        bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
        bot.frame_advance(1)

        vals_before = read_candidates(bot)
        vals_after = press_and_read(bot, button, frames=3)

        changes = []
        for key in vals_before:
            if vals_before[key] != vals_after[key]:
                changes.append(f"{key}: {vals_before[key]} -> {vals_after[key]}")
        if changes:
            print(f"  {button}: {', '.join(changes)}")
        else:
            print(f"  {button}: no changes in candidates")

    # Also do broader scan for A/B/C — check game_state
    print("\n--- Game state after A/B/C ---")
    for button in ["A", "B", "C"]:
        bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
        bot.frame_advance(1)

        # Read game state before
        gs_before = read_mem(bot, 0x0605AD10, 1)

        bot.input_press(button)
        bot.frame_advance(5)
        bot.input_release(button)
        bot.frame_advance(1)

        gs_after = read_mem(bot, 0x0605AD10, 1)
        gs_b = gs_before[0] if gs_before else "?"
        gs_a = gs_after[0] if gs_after else "?"
        print(f"  {button}: game_state {gs_b} -> {gs_a}")

    bot.quit()
    print("\nDone.")


if __name__ == "__main__":
    main()
