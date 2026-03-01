#!/usr/bin/env python3
"""One-off: check pad state + breakpoint on car_select_input at car select.

1. At car select state (frame 3100, g_game_state=0x0D), dump pad state during DOWN press
2. Set breakpoint on car_select_input, advance 1 frame — does it hit?
3. Also check what value the lock flag branch check produces
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from investigate import (
    MednafenBot, load_symbols, sym_hex, resolve_symbol,
    parse_trace, replay_to_state, GAME_STATES, TRACE_FILE, wsl_path,
    PROJECT,
)

def dump_bytes(bot, addr_hex, size, results_dir, label):
    dump_path = os.path.join(results_dir, f"dump_{label}.bin")
    bot.dump_mem_bin(addr_hex, str(size), dump_path)
    if os.path.exists(dump_path):
        with open(dump_path, "rb") as f:
            data = f.read(size)
        hex_str = " ".join(f"{b:02X}" for b in data)
        print(f"  {label}: {hex_str}")
        return data
    return None

def main():
    addr_to_name, name_to_addr = load_symbols()

    pad_addr = sym_hex(name_to_addr, "g_pad_state")
    func_addr = sym_hex(name_to_addr, "car_select_input")
    lock_addr = sym_hex(name_to_addr, "sym_06085FF3")
    index_addr = sym_hex(name_to_addr, "sym_06085FF0")
    game_state_addr = sym_hex(name_to_addr, "g_game_state")
    state_active_addr = sym_hex(name_to_addr, "state_car_select_active")
    print(f"g_pad_state: 0x{pad_addr}")
    print(f"car_select_input: 0x{func_addr}")
    print(f"sym_06085FF3 (lock): 0x{lock_addr}")
    print(f"sym_06085FF0 (index): 0x{index_addr}")
    print(f"g_game_state: 0x{game_state_addr}")
    print(f"state_car_select_active: 0x{state_active_addr}")

    trace_events = parse_trace(TRACE_FILE)

    results_dir = os.path.join(PROJECT, "build", "investigation_results", "car_select4")
    os.makedirs(results_dir, exist_ok=True)
    ipc_dir = os.path.join(results_dir, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

    # Replay to circuit, then continue to car select
    bot = MednafenBot(ipc_dir, wsl_path(cue_path))
    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Could not start")
        return

    print("Replaying to circuit...")
    if not replay_to_state(bot, "circuit", trace_events):
        print("FAIL: Could not replay")
        bot.quit()
        return

    # Continue to 3100
    for frame, action, arg in trace_events:
        if frame < bot.current_frame:
            continue
        if frame >= 3100:
            break
        advance = frame - bot.current_frame
        if advance > 0:
            bot.frame_advance(advance)
        if action == "input":
            bot.input_press(arg)
        elif action == "input_release":
            bot.input_release(arg)
    remaining = 3100 - bot.current_frame
    if remaining > 0:
        bot.frame_advance(remaining)

    print(f"\nAt frame {bot.current_frame}")

    # --- Test 1: Check pad state while pressing DOWN ---
    print("\n--- TEST 1: Pad state during DOWN press ---")
    dump_bytes(bot, pad_addr, 16, results_dir, "pad_before_down")
    bot.input_press("DOWN")
    bot.frame_advance(2)
    dump_bytes(bot, pad_addr, 16, results_dir, "pad_during_down")
    bot.input_release("DOWN")
    bot.frame_advance(1)
    dump_bytes(bot, pad_addr, 16, results_dir, "pad_after_down")

    # --- Test 2: Breakpoint on car_select_input ---
    print(f"\n--- TEST 2: Breakpoint on car_select_input (0x{func_addr}) ---")
    bot.set_breakpoint(func_addr)
    bot.frame_advance(3)
    print(f"After 3 frames with BP, at frame {bot.current_frame}")
    # If frame didn't advance far, it means BP hit and paused
    bot.clear_breakpoints()

    # --- Test 3: Breakpoint on state_car_select_active ---
    if state_active_addr:
        print(f"\n--- TEST 3: Breakpoint on state_car_select_active (0x{state_active_addr}) ---")
        bot.set_breakpoint(state_active_addr)
        bot.frame_advance(3)
        print(f"After 3 frames with BP, at frame {bot.current_frame}")
        bot.clear_breakpoints()
    else:
        print("\n--- TEST 3: state_car_select_active not found ---")

    # --- Test 4: Check game_state at several frames to understand the state machine ---
    print(f"\n--- TEST 4: g_game_state scan ---")
    dump_bytes(bot, game_state_addr, 4, results_dir, "game_state_current")

    # Also check: what state was mode select?
    print("\n  For reference, let's check game_state at other known frames")
    bot.quit()

    # Session 2: Check game_state at mode select
    ipc_dir2 = os.path.join(results_dir, "ipc2")
    os.makedirs(ipc_dir2, exist_ok=True)
    bot2 = MednafenBot(ipc_dir2, wsl_path(cue_path))
    if not bot2.start(timeout=30):
        print("FAIL")
        return
    if not replay_to_state(bot2, "menu", trace_events):
        print("FAIL")
        bot2.quit()
        return
    print(f"  Mode select (frame {bot2.current_frame}):")
    dump_bytes(bot2, game_state_addr, 4, results_dir, "game_state_mode_select")
    bot2.quit()

    # Session 3: Check game_state at circuit select
    ipc_dir3 = os.path.join(results_dir, "ipc3")
    os.makedirs(ipc_dir3, exist_ok=True)
    bot3 = MednafenBot(ipc_dir3, wsl_path(cue_path))
    if not bot3.start(timeout=30):
        print("FAIL")
        return
    if not replay_to_state(bot3, "circuit", trace_events):
        print("FAIL")
        bot3.quit()
        return
    print(f"  Circuit select (frame {bot3.current_frame}):")
    dump_bytes(bot3, game_state_addr, 4, results_dir, "game_state_circuit")
    bot3.quit()

    # Session 4: Check right after circuit C press (~frame 2800)
    ipc_dir4 = os.path.join(results_dir, "ipc4")
    os.makedirs(ipc_dir4, exist_ok=True)
    bot4 = MednafenBot(ipc_dir4, wsl_path(cue_path))
    if not bot4.start(timeout=30):
        print("FAIL")
        return
    if not replay_to_state(bot4, "circuit", trace_events):
        print("FAIL")
        bot4.quit()
        return
    # Apply C press (frame 2763)
    for frame, action, arg in trace_events:
        if frame < bot4.current_frame:
            continue
        if frame >= 2800:
            break
        advance = frame - bot4.current_frame
        if advance > 0:
            bot4.frame_advance(advance)
        if action == "input":
            bot4.input_press(arg)
        elif action == "input_release":
            bot4.input_release(arg)
    remaining = 2800 - bot4.current_frame
    if remaining > 0:
        bot4.frame_advance(remaining)
    print(f"  After circuit C (~frame {bot4.current_frame}):")
    dump_bytes(bot4, game_state_addr, 4, results_dir, "game_state_after_circuit_C")
    dump_bytes(bot4, index_addr, 4, results_dir, "index_after_circuit_C")
    dump_bytes(bot4, lock_addr, 4, results_dir, "lock_after_circuit_C")

    # Try DOWN at this earlier point
    print(f"\n--- Watchpoint on sym_06085FF0 at frame ~2800 during DOWN ---")
    bot4.set_watchpoint(index_addr)
    bot4.input_press("DOWN")
    bot4.frame_advance(5)
    bot4.input_release("DOWN")
    from investigate_flag_word import print_wp_hits
    hits = bot4.read_watchpoint_hits()
    print(f"\n=== WATCHPOINT: DOWN at ~2800 ===")
    print(f"Total hits: {len(hits)}")
    for h in hits:
        parts = {}
        for token in h.split():
            if "=" in token:
                k, v = token.split("=", 1)
                parts[k] = v
        pc = parts.get("pc", "?")
        pr = parts.get("pr", "?")
        old_val = parts.get("old", "?")
        new_val = parts.get("new", "?")
        pc_sym = resolve_symbol(pc, addr_to_name) if pc != "?" else "?"
        print(f"  WRITE: PC=0x{pc} ({pc_sym})")
        print(f"         {old_val} -> {new_val}")
    bot4.clear_watchpoint()

    bot4.quit()
    print("\nDone.")

if __name__ == "__main__":
    main()
