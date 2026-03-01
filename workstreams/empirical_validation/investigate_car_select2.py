#!/usr/bin/env python3
"""One-off: deeper investigation of car_select_input.

1. Check g_game_state at frame 3625 to confirm which state we're in
2. Try earlier stop point (right after circuit select C at ~frame 2700)
3. Watchpoint on sym_06085FF0 at that earlier point during DOWN
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

def replay_to_frame(bot, target_frame, trace_events):
    """Replay trace events up to (but not including) target_frame."""
    for frame, action, arg in trace_events:
        if frame >= target_frame:
            break
        if action == "input":
            bot.input_press(arg)
        elif action == "input_release":
            bot.input_release(arg)
        elif action == "screenshot":
            pass  # skip screenshots during replay
        # Advance to the next event's frame
    # Advance to target
    remaining = target_frame - bot.current_frame
    if remaining > 0:
        bot.frame_advance(remaining)
    return True

def main():
    addr_to_name, name_to_addr = load_symbols()

    game_state_addr = sym_hex(name_to_addr, "g_game_state")
    index_addr = sym_hex(name_to_addr, "sym_06085FF0")
    lock_addr = sym_hex(name_to_addr, "sym_06085FF3")
    func_addr = sym_hex(name_to_addr, "car_select_input")
    pad_addr = sym_hex(name_to_addr, "g_pad_state")
    print(f"g_game_state: 0x{game_state_addr}")
    print(f"sym_06085FF0 (index): 0x{index_addr}")
    print(f"sym_06085FF3 (lock): 0x{lock_addr}")
    print(f"car_select_input: 0x{func_addr}")
    print(f"g_pad_state: 0x{pad_addr}")

    trace_events = parse_trace(TRACE_FILE)

    results_dir = os.path.join(PROJECT, "build", "investigation_results", "car_select2")
    os.makedirs(results_dir, exist_ok=True)
    ipc_dir = os.path.join(results_dir, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

    # === SESSION 1: Check state at frame 3625 ===
    print("\n=== SESSION 1: Check game state at frame 3625 ===")
    bot = MednafenBot(ipc_dir, wsl_path(cue_path))
    if not bot.start(timeout=30):
        print("FAIL: Could not start")
        return
    if not replay_to_state(bot, "car", trace_events):
        print("FAIL: Could not replay")
        bot.quit()
        return

    print(f"At frame {bot.current_frame}")
    dump_bytes(bot, game_state_addr, 4, results_dir, "game_state_at_3625")
    dump_bytes(bot, index_addr, 8, results_dir, "car_vars_at_3625")

    # Also check what call_trace shows for 3 idle frames
    ct_path = os.path.join(results_dir, "calltrace_3625.txt")
    bot.call_trace(wsl_path(ct_path))
    bot.frame_advance(3)
    bot.call_trace_stop()
    print(f"Call trace saved to {ct_path}")

    # Check if car_select_input appears in the call trace
    if os.path.exists(ct_path):
        func_addr_lower = func_addr.lower()
        found = False
        with open(ct_path) as f:
            for line in f:
                if func_addr_lower in line.lower():
                    found = True
                    break
        print(f"  car_select_input (0x{func_addr}) in call trace: {found}")

    bot.quit()

    # === SESSION 2: Try earlier frame (right after entering car select) ===
    # Car select starts after circuit C at ~frame 2700, let's try frame 3000
    # which should be solidly in car select based on golden trace
    print("\n=== SESSION 2: Try frame 3100 (mid car select) ===")
    ipc_dir2 = os.path.join(results_dir, "ipc2")
    os.makedirs(ipc_dir2, exist_ok=True)
    bot2 = MednafenBot(ipc_dir2, wsl_path(cue_path))
    if not bot2.start(timeout=30):
        print("FAIL: Could not start")
        return

    # Replay but stop at frame 3100 instead of 3625
    if not replay_to_state(bot2, "circuit", trace_events):
        print("FAIL: Could not replay to circuit")
        bot2.quit()
        return

    # Now advance to 3100 with remaining trace events
    print(f"At circuit (frame {bot2.current_frame}), continuing to 3100...")
    for frame, action, arg in trace_events:
        if frame < bot2.current_frame:
            continue
        if frame >= 3100:
            break
        advance = frame - bot2.current_frame
        if advance > 0:
            bot2.frame_advance(advance)
        if action == "input":
            bot2.input_press(arg)
        elif action == "input_release":
            bot2.input_release(arg)
    remaining = 3100 - bot2.current_frame
    if remaining > 0:
        bot2.frame_advance(remaining)

    print(f"At frame {bot2.current_frame}")
    dump_bytes(bot2, game_state_addr, 4, results_dir, "game_state_at_3100")
    dump_bytes(bot2, index_addr, 8, results_dir, "car_vars_at_3100")
    dump_bytes(bot2, lock_addr, 4, results_dir, "lock_at_3100")

    # Check call trace
    ct_path2 = os.path.join(results_dir, "calltrace_3100.txt")
    bot2.call_trace(wsl_path(ct_path2))
    bot2.frame_advance(3)
    bot2.call_trace_stop()
    if os.path.exists(ct_path2):
        func_addr_lower = func_addr.lower()
        found = False
        with open(ct_path2) as f:
            for line in f:
                if func_addr_lower in line.lower():
                    found = True
                    break
        print(f"  car_select_input (0x{func_addr}) in call trace at 3100: {found}")

    # Now try watchpoint on index during DOWN
    print(f"\n--- Watchpoint on sym_06085FF0 at frame ~3103, DOWN press ---")
    bot2.set_watchpoint(index_addr)
    bot2.input_press("DOWN")
    bot2.frame_advance(5)
    bot2.input_release("DOWN")
    hits = bot2.read_watchpoint_hits()
    print_wp_hits(hits, addr_to_name, "WATCHPOINT: DOWN at ~3103")
    dump_bytes(bot2, index_addr, 8, results_dir, "car_vars_after_down_3100")
    bot2.clear_watchpoint()

    # Also try C button (confirm) watchpoint on g_game_state
    print(f"\n--- Watchpoint on g_game_state during C press ---")
    bot2.set_watchpoint(game_state_addr)
    bot2.input_press("C")
    bot2.frame_advance(5)
    bot2.input_release("C")
    hits2 = bot2.read_watchpoint_hits()
    print_wp_hits(hits2, addr_to_name, "WATCHPOINT: C on g_game_state")
    bot2.clear_watchpoint()

    bot2.quit()
    print("\nDone.")

if __name__ == "__main__":
    main()
