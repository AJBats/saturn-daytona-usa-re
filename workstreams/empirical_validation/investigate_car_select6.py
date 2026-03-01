#!/usr/bin/env python3
"""One-off: test LEFT/RIGHT at car select state.

Golden trace shows LEFT/RIGHT used at car select (frames 3142, 3403).
Previous experiments tried DOWN — wrong button for this screen.
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
        old_val = parts.get("old", "?")
        new_val = parts.get("new", "?")
        pc_sym = resolve_symbol(pc, addr_to_name) if pc != "?" else "?"
        print(f"  WRITE: PC=0x{pc} ({pc_sym})  {old_val} -> {new_val}")

def main():
    addr_to_name, name_to_addr = load_symbols()

    func_addr = sym_hex(name_to_addr, "car_select_input")
    index_addr = sym_hex(name_to_addr, "sym_06085FF0")
    game_state_addr = sym_hex(name_to_addr, "g_game_state")
    pad_addr = sym_hex(name_to_addr, "g_pad_state")
    print(f"car_select_input: 0x{func_addr}")
    print(f"sym_06085FF0: 0x{index_addr}")
    print(f"g_game_state: 0x{game_state_addr}")

    trace_events = parse_trace(TRACE_FILE)

    results_dir = os.path.join(PROJECT, "build", "investigation_results", "car_select6")
    os.makedirs(results_dir, exist_ok=True)
    ipc_dir = os.path.join(results_dir, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

    # Replay to just before the car select RIGHT press (frame 3142)
    # Stop at frame 3130 — should be on car select screen
    print("=== Replay to frame 3130 (car select, before RIGHT press) ===")
    bot = MednafenBot(ipc_dir, wsl_path(cue_path))
    if not bot.start(timeout=30):
        print("FAIL"); return
    if not replay_to_state(bot, "circuit", trace_events):
        print("FAIL"); bot.quit(); return

    # Continue from circuit to frame 3130
    for frame, action, arg in trace_events:
        if frame < bot.current_frame:
            continue
        if frame >= 3130:
            break
        advance = frame - bot.current_frame
        if advance > 0:
            bot.frame_advance(advance)
        if action == "input":
            bot.input_press(arg)
        elif action == "input_release":
            bot.input_release(arg)
    remaining = 3130 - bot.current_frame
    if remaining > 0:
        bot.frame_advance(remaining)

    print(f"At frame {bot.current_frame}")
    dump_bytes(bot, game_state_addr, 4, results_dir, "gs_3130")
    dump_bytes(bot, index_addr, 8, results_dir, "idx_3130")

    # --- Test RIGHT ---
    print("\n--- Watchpoint on sym_06085FF0 during RIGHT (5 frames) ---")
    bot.set_watchpoint(index_addr)
    bot.input_press("RIGHT")
    bot.frame_advance(5)
    bot.input_release("RIGHT")
    hits = bot.read_watchpoint_hits()
    print_wp_hits(hits, addr_to_name, "RIGHT on car select")
    dump_bytes(bot, index_addr, 8, results_dir, "idx_after_right")
    bot.clear_watchpoint()

    # Check pad state during RIGHT
    print("\n--- Pad state during RIGHT ---")
    bot.input_press("RIGHT")
    bot.frame_advance(1)
    dump_bytes(bot, pad_addr, 8, results_dir, "pad_during_right")
    bot.input_release("RIGHT")
    bot.frame_advance(1)

    # --- Test LEFT ---
    print("\n--- Watchpoint on sym_06085FF0 during LEFT (5 frames) ---")
    bot.set_watchpoint(index_addr)
    bot.input_press("LEFT")
    bot.frame_advance(5)
    bot.input_release("LEFT")
    hits2 = bot.read_watchpoint_hits()
    print_wp_hits(hits2, addr_to_name, "LEFT on car select")
    dump_bytes(bot, index_addr, 8, results_dir, "idx_after_left")
    bot.clear_watchpoint()

    # --- Test C (confirm) ---
    print("\n--- Watchpoint on g_game_state during C (5 frames) ---")
    bot.set_watchpoint(game_state_addr)
    bot.input_press("C")
    bot.frame_advance(5)
    bot.input_release("C")
    hits3 = bot.read_watchpoint_hits()
    print_wp_hits(hits3, addr_to_name, "C on g_game_state at car select")
    bot.clear_watchpoint()

    # --- Broad memory diff during RIGHT ---
    print("\n--- Memory diff: 0x06085F00 - 0x06086100 during RIGHT ---")
    before_path = os.path.join(results_dir, "mem_before.bin")
    bot.dump_mem_bin("06085F00", "512", before_path)
    bot.input_press("RIGHT")
    bot.frame_advance(5)
    bot.input_release("RIGHT")
    after_path = os.path.join(results_dir, "mem_after.bin")
    bot.dump_mem_bin("06085F00", "512", after_path)

    if os.path.exists(before_path) and os.path.exists(after_path):
        with open(before_path, "rb") as f:
            before = f.read()
        with open(after_path, "rb") as f:
            after = f.read()
        changes = []
        for i in range(min(len(before), len(after))):
            if before[i] != after[i]:
                addr = 0x06085F00 + i
                changes.append((addr, before[i], after[i]))
        if changes:
            print(f"  {len(changes)} bytes changed:")
            for addr, old, new in changes[:20]:
                print(f"    0x{addr:08X}: 0x{old:02X} -> 0x{new:02X}")
            if len(changes) > 20:
                print(f"    ... and {len(changes)-20} more")
        else:
            print("  No changes in range")

    bot.quit()
    print("\nDone.")

if __name__ == "__main__":
    main()
