#!/usr/bin/env python3
"""One-off: find car select game state + test input at correct frame.

We know g_game_state=0x0D at frame 3625 (past car select).
Try frame 3100 which should be mid-car-select per golden trace.
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

def print_wp_hits(hits, addr_to_name, label):
    print(f"\n=== {label} ===")
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
        pr_sym = resolve_symbol(pr, addr_to_name) if pr != "?" else "?"
        print(f"  WRITE: PC=0x{pc} ({pc_sym})")
        print(f"         PR=0x{pr} ({pr_sym})")
        print(f"         {old_val} -> {new_val}")

def main():
    addr_to_name, name_to_addr = load_symbols()

    game_state_addr = sym_hex(name_to_addr, "g_game_state")
    index_addr = sym_hex(name_to_addr, "sym_06085FF0")
    lock_addr = sym_hex(name_to_addr, "sym_06085FF3")
    func_addr = sym_hex(name_to_addr, "car_select_input")
    print(f"g_game_state: 0x{game_state_addr}")
    print(f"sym_06085FF0 (index): 0x{index_addr}")
    print(f"sym_06085FF3 (lock): 0x{lock_addr}")
    print(f"car_select_input: 0x{func_addr}")

    trace_events = parse_trace(TRACE_FILE)

    results_dir = os.path.join(PROJECT, "build", "investigation_results", "car_select3")
    os.makedirs(results_dir, exist_ok=True)

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

    # Replay to circuit (frame 2688), then continue to frame 3100
    ipc_dir = os.path.join(results_dir, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)
    bot = MednafenBot(ipc_dir, wsl_path(cue_path))
    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Could not start")
        return

    print("Replaying to circuit state...")
    if not replay_to_state(bot, "circuit", trace_events):
        print("FAIL: Could not replay to circuit")
        bot.quit()
        return

    # Continue replaying trace events from circuit to frame 3100
    print(f"At circuit (frame {bot.current_frame}), continuing to ~3100...")
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
    dump_bytes(bot, game_state_addr, 4, results_dir, "game_state_3100")
    dump_bytes(bot, index_addr, 8, results_dir, "car_vars_3100")
    dump_bytes(bot, lock_addr, 4, results_dir, "lock_3100")

    # If game state looks right, try button inputs
    print("\n--- Watchpoint on sym_06085FF0 during DOWN (5 frames) ---")
    bot.set_watchpoint(index_addr)
    bot.input_press("DOWN")
    bot.frame_advance(5)
    bot.input_release("DOWN")
    hits = bot.read_watchpoint_hits()
    print_wp_hits(hits, addr_to_name, "WATCHPOINT: DOWN at ~3100")
    dump_bytes(bot, index_addr, 8, results_dir, "car_vars_after_down")
    bot.clear_watchpoint()

    # Try LEFT
    print("\n--- Watchpoint on sym_06085FF0 during LEFT (5 frames) ---")
    bot.set_watchpoint(index_addr)
    bot.input_press("LEFT")
    bot.frame_advance(5)
    bot.input_release("LEFT")
    hits2 = bot.read_watchpoint_hits()
    print_wp_hits(hits2, addr_to_name, "WATCHPOINT: LEFT at ~3100")
    dump_bytes(bot, index_addr, 8, results_dir, "car_vars_after_left")
    bot.clear_watchpoint()

    # Try RIGHT
    print("\n--- Watchpoint on sym_06085FF0 during RIGHT (5 frames) ---")
    bot.set_watchpoint(index_addr)
    bot.input_press("RIGHT")
    bot.frame_advance(5)
    bot.input_release("RIGHT")
    hits3 = bot.read_watchpoint_hits()
    print_wp_hits(hits3, addr_to_name, "WATCHPOINT: RIGHT at ~3100")
    dump_bytes(bot, index_addr, 8, results_dir, "car_vars_after_right")
    bot.clear_watchpoint()

    # Also check: does g_game_state change if we press C?
    print("\n--- Watchpoint on g_game_state during C (5 frames) ---")
    dump_bytes(bot, game_state_addr, 4, results_dir, "game_state_before_C")
    bot.set_watchpoint(game_state_addr)
    bot.input_press("C")
    bot.frame_advance(5)
    bot.input_release("C")
    hits4 = bot.read_watchpoint_hits()
    print_wp_hits(hits4, addr_to_name, "WATCHPOINT: C on g_game_state")
    dump_bytes(bot, game_state_addr, 4, results_dir, "game_state_after_C")
    bot.clear_watchpoint()

    bot.quit()
    print("\nDone.")

if __name__ == "__main__":
    main()
