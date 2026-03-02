#!/usr/bin/env python3
"""Verify RE_TEST #2: C/B swap on circuit select — fresh boot test.

Can't use save states (they restore vanilla code into WRAM).
Must boot from scratch and replay to circuit select.
"""

import os
import sys

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from investigate import MednafenBot, wsl_path, load_trace_events, GAME_STATES

CUE_PATH = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
IPC_DIR = os.path.join(PROJECT, "build", "debug_ipc")
TRACE_FILE = os.path.join(PROJECT, "build", "debug_ipc", "traces", "golden_trace.txt")


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


def boot_to_circuit_select(bot):
    """Boot from scratch and navigate to circuit select screen."""
    # Boot sequence: advance past BIOS, attract, title
    print("  Booting (300 frames)...")
    bot.frame_advance(300)

    # Skip attract mode - press START
    print("  Pressing START to skip attract...")
    bot.input_press("START")
    bot.frame_advance(5)
    bot.input_release("START")
    bot.frame_advance(120)

    # Title screen - press START
    print("  Pressing START at title...")
    bot.input_press("START")
    bot.frame_advance(5)
    bot.input_release("START")
    bot.frame_advance(120)

    # Mode select - press C to confirm (C is still confirm on mode select)
    # Actually with RE_TESTS=1, mode select has swapped UP/DOWN but C still confirms
    print("  Pressing C on mode select...")
    bot.input_press("C")
    bot.frame_advance(5)
    bot.input_release("C")
    bot.frame_advance(120)

    state = read_state(bot)
    print(f"  State after navigation: {state}")
    return state["dispatch"] == 1


def main():
    bot = MednafenBot(IPC_DIR, wsl_path(CUE_PATH))
    print("Starting Mednafen (RE_TESTS=1 MODS=1 build)...")
    if not bot.start(timeout=30):
        print("FAIL: Mednafen did not start")
        return

    # Try using golden trace if available
    if os.path.exists(TRACE_FILE):
        print("Using golden trace for replay...")
        events = load_trace_events(TRACE_FILE)
        stop_frame = GAME_STATES["menu"]["stop_before_frame"]

        for frame, action, arg in events:
            if frame >= stop_frame:
                break
            delta = frame - bot.current_frame
            if delta > 0:
                bot.frame_advance(delta)
            if action == "input":
                bot.input_press(arg)
            elif action == "input_release":
                bot.input_release(arg)

        # Now at mode select. Press C to go to circuit select.
        bot.frame_advance(10)
        bot.input_press("C")
        bot.frame_advance(5)
        bot.input_release("C")
        bot.frame_advance(120)
    else:
        print("No golden trace, using manual boot...")
        if not boot_to_circuit_select(bot):
            print("FAIL: Could not reach circuit select")
            bot.quit()
            return

    state = read_state(bot)
    print(f"\nAt circuit select: {state}")

    if state["dispatch"] != 1:
        print(f"Not at circuit select (dispatch={state['dispatch']}). Trying more frames...")
        bot.frame_advance(120)
        state = read_state(bot)
        print(f"After more frames: {state}")
        if state["dispatch"] != 1:
            print("FAIL: Could not reach circuit select")
            bot.quit()
            return

    # Verify the mod is in place by reading the pool values
    back_mask = read_mem(bot, 0x0601030C, 2)
    confirm_mask = read_mem(bot, 0x0601038C, 2)
    if back_mask and confirm_mask:
        import struct
        bm = struct.unpack(">H", back_mask)[0]
        cm = struct.unpack(">H", confirm_mask)[0]
        print(f"\nPool values in memory:")
        print(f"  BACK mask   (0x0601030C): 0x{bm:04X} {'(C - MODDED)' if bm == 0x0200 else '(B - VANILLA)'}")
        print(f"  CONFIRM mask(0x0601038C): 0x{cm:04X} {'(B - MODDED)' if cm == 0x0100 else '(C - VANILLA)'}")

    # Save state for future use
    save_path = os.path.join(PROJECT, "build", "save_states", "circuit_select_modded.mc0")
    save_wsl = wsl_path(save_path)
    ack = bot.send_and_wait(f"save_state {save_wsl}", "save_state", timeout=15)
    if ack:
        print(f"\nSaved modded state to {save_path}")

    # Now test buttons
    print("\n=== Button Tests ===\n")

    # Save current state for reloading
    modded_state_wsl = save_wsl

    # Test B (should now be CONFIRM)
    print("Test B (expect CONFIRM - dispatch changes):")
    before = read_state(bot)
    bot.input_press("B")
    bot.frame_advance(15)
    bot.input_release("B")
    bot.frame_advance(10)
    after = read_state(bot)
    for key in before:
        if before[key] != after[key]:
            print(f"  {key}: {before[key]} -> {after[key]}")
    if before == after:
        print("  no change")

    # Reload modded state
    bot.send_and_wait(f"load_state {modded_state_wsl}", "load_state", timeout=15)
    bot.frame_advance(1)

    # Test C (should now be BACK)
    print("\nTest C (expect BACK - g_game_state changes):")
    before = read_state(bot)
    bot.input_press("C")
    bot.frame_advance(15)
    bot.input_release("C")
    bot.frame_advance(10)
    after = read_state(bot)
    for key in before:
        if before[key] != after[key]:
            print(f"  {key}: {before[key]} -> {after[key]}")
    if before == after:
        print("  no change")

    # Reload and test A (should still do nothing)
    bot.send_and_wait(f"load_state {modded_state_wsl}", "load_state", timeout=15)
    bot.frame_advance(1)

    print("\nTest A (expect nothing):")
    before = read_state(bot)
    bot.input_press("A")
    bot.frame_advance(15)
    bot.input_release("A")
    bot.frame_advance(10)
    after = read_state(bot)
    for key in before:
        if before[key] != after[key]:
            print(f"  {key}: {before[key]} -> {after[key]}")
    if before == after:
        print("  no change")

    bot.quit()
    print("\nDone.")


if __name__ == "__main__":
    main()
