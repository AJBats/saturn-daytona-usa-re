#!/usr/bin/env python3
"""Verify RE_TEST #2: C/B swap on circuit select.

Expected: B confirms (dispatch_state changes), C backs out (g_game_state -> 6).
"""

import os
import sys

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from investigate import MednafenBot, wsl_path

SAVE_STATE = os.path.join(PROJECT, "build", "save_states", "circuit_select_slot0.mc0")
CUE_PATH = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
IPC_DIR = os.path.join(PROJECT, "build", "debug_ipc")


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


def read_state(bot):
    d = read_mem(bot, 0x0607887F, 1)
    g = read_mem(bot, 0x0605AD10, 4)
    c = read_mem(bot, 0x0607EADB, 1)
    return {
        "dispatch": d[0] if d else "?",
        "g_game_state": int.from_bytes(g, 'big') if g else "?",
        "circuit": c[0] if c else "?",
    }


def test_button(bot, state_wsl, button, label, hold=15, after=10):
    """Load state, press button, report changes."""
    ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
    if not ack or "error" in ack:
        print(f"  {label}: FAIL load_state")
        return
    bot.frame_advance(1)
    before = read_state(bot)

    bot.input_press(button)
    bot.frame_advance(hold)
    bot.input_release(button)
    bot.frame_advance(after)
    after_state = read_state(bot)

    changes = []
    for key in before:
        if before[key] != after_state[key]:
            changes.append(f"{key}: {before[key]} -> {after_state[key]}")

    status = "CHANGED" if changes else "no change"
    print(f"  {label:20s}: {status}")
    for c in changes:
        print(f"    {c}")


def main():
    bot = MednafenBot(IPC_DIR, wsl_path(CUE_PATH))
    print("Starting Mednafen (RE_TESTS=1 MODS=1 build)...")
    if not bot.start(timeout=30):
        print("FAIL: Mednafen did not start")
        return

    bot.frame_advance(1)
    state_wsl = wsl_path(SAVE_STATE)

    # Try loading save state
    ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
    if not ack or "error" in ack:
        print(f"FAIL: load_state: {ack}")
        bot.quit()
        return

    bot.frame_advance(1)
    initial = read_state(bot)
    print(f"Initial state: {initial}")

    if initial["dispatch"] != 1:
        print(f"WARNING: Not at circuit select (dispatch={initial['dispatch']})")
        bot.quit()
        return

    print("\n=== Button Tests (modded build: B=confirm, C=back) ===\n")

    # Test B (should now CONFIRM)
    test_button(bot, state_wsl, "B", "B (expect CONFIRM)")

    # Test C (should now BACK)
    test_button(bot, state_wsl, "C", "C (expect BACK)")

    # Sanity: A should still do nothing
    test_button(bot, state_wsl, "A", "A (expect nothing)")

    # Sanity: LEFT/RIGHT should still work
    test_button(bot, state_wsl, "RIGHT", "RIGHT (expect circuit+1)")
    test_button(bot, state_wsl, "LEFT", "LEFT (expect no change, already 0)")

    bot.quit()
    print("\nDone.")


if __name__ == "__main__":
    main()
