#!/usr/bin/env python3
"""One-off: use DebugSession to trace car_select_input at mode select vs car select.

Simpler approach: call trace at different states, search for car_select_input addr.
Also check: at mode select, set watchpoint on sym_06085FF0 during DOWN.
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
    lock_addr = sym_hex(name_to_addr, "sym_06085FF3")
    game_state_addr = sym_hex(name_to_addr, "g_game_state")
    print(f"car_select_input: 0x{func_addr}")
    print(f"sym_06085FF0: 0x{index_addr}")
    print(f"sym_06085FF3: 0x{lock_addr}")
    print(f"g_game_state: 0x{game_state_addr}")

    trace_events = parse_trace(TRACE_FILE)

    results_dir = os.path.join(PROJECT, "build", "investigation_results", "car_select5")
    os.makedirs(results_dir, exist_ok=True)
    ipc_dir = os.path.join(results_dir, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

    # === TEST AT MODE SELECT (frame 1537) ===
    print("\n=== AT MODE SELECT (frame 1537) ===")
    bot = MednafenBot(ipc_dir, wsl_path(cue_path))
    if not bot.start(timeout=30):
        print("FAIL"); return
    if not replay_to_state(bot, "menu", trace_events):
        print("FAIL"); bot.quit(); return

    print(f"At frame {bot.current_frame}")
    dump_bytes(bot, game_state_addr, 4, results_dir, "gs_menu")
    dump_bytes(bot, index_addr, 8, results_dir, "idx_menu")
    dump_bytes(bot, lock_addr, 4, results_dir, "lock_menu")

    # Watchpoint on sym_06085FF0 during DOWN at mode select
    print("\n--- Watchpoint on sym_06085FF0 during DOWN at mode select ---")
    bot.set_watchpoint(index_addr)
    bot.input_press("DOWN")
    bot.frame_advance(5)
    bot.input_release("DOWN")
    hits = bot.read_watchpoint_hits()
    print_wp_hits(hits, addr_to_name, "DOWN at mode select")
    dump_bytes(bot, index_addr, 8, results_dir, "idx_menu_after_down")
    bot.clear_watchpoint()

    # Watchpoint on broader area: sym_06085FF0 to sym_06085FF7 (8 bytes)
    # Try watching the 4-byte word at sym_06085FF4 too
    print("\n--- Also watch sym_06085FF4 during DOWN ---")
    ff4_addr = sym_hex(name_to_addr, "sym_06085FF4")
    if ff4_addr:
        bot.set_watchpoint(ff4_addr)
        bot.input_press("DOWN")
        bot.frame_advance(5)
        bot.input_release("DOWN")
        hits2 = bot.read_watchpoint_hits()
        print_wp_hits(hits2, addr_to_name, "DOWN on sym_06085FF4")
        bot.clear_watchpoint()

    # Also try: what DOES get written during DOWN? Watch g_game_state
    print("\n--- Watch g_game_state during DOWN ---")
    bot.set_watchpoint(game_state_addr)
    bot.input_press("DOWN")
    bot.frame_advance(5)
    bot.input_release("DOWN")
    hits3 = bot.read_watchpoint_hits()
    print_wp_hits(hits3, addr_to_name, "DOWN on g_game_state")
    bot.clear_watchpoint()

    # Memory diff on wider range
    print("\n--- Memory diff: 0x06085FE0 - 0x06086020 during DOWN ---")
    before_path = os.path.join(results_dir, "mem_before.bin")
    bot.dump_mem_bin("06085FE0", "64", before_path)
    bot.input_press("DOWN")
    bot.frame_advance(5)
    bot.input_release("DOWN")
    after_path = os.path.join(results_dir, "mem_after.bin")
    bot.dump_mem_bin("06085FE0", "64", after_path)

    if os.path.exists(before_path) and os.path.exists(after_path):
        with open(before_path, "rb") as f:
            before = f.read()
        with open(after_path, "rb") as f:
            after = f.read()
        changes = []
        for i in range(min(len(before), len(after))):
            if before[i] != after[i]:
                addr = 0x06085FE0 + i
                changes.append((addr, before[i], after[i]))
        if changes:
            print(f"  {len(changes)} bytes changed:")
            for addr, old, new in changes:
                print(f"    0x{addr:08X}: 0x{old:02X} -> 0x{new:02X}")
        else:
            print("  No changes in range 0x06085FE0 - 0x06086020")

    bot.quit()
    print("\nDone.")

if __name__ == "__main__":
    main()
