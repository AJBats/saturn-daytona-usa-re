#!/usr/bin/env python3
"""One-off: watchpoint on sym_0605B6D8 — button press test + racing state test.

Part 2: Check if button presses write to the flag word (they shouldn't if it's
not button data), and check the value during racing (where call graphs show
button_input_read has outgoing calls).
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from investigate import (
    MednafenBot, load_symbols, sym_hex, resolve_symbol,
    parse_trace, replay_to_state, GAME_STATES, TRACE_FILE, wsl_path,
    PROJECT,
)

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

def dump_value(bot, addr_hex, results_dir, label):
    dump_path = os.path.join(results_dir, f"flag_{label}.bin")
    bot.dump_mem_bin(addr_hex, "4", dump_path)
    if os.path.exists(dump_path):
        with open(dump_path, "rb") as f:
            data = f.read(4)
        val = int.from_bytes(data, "big")
        print(f"  Value of sym_0605B6D8 ({label}): 0x{val:08X}")
        return val
    return None

def main():
    addr_to_name, name_to_addr = load_symbols()
    flag_addr = sym_hex(name_to_addr, "sym_0605B6D8")
    print(f"sym_0605B6D8 runtime address: 0x{flag_addr}")

    trace_events = parse_trace(TRACE_FILE)

    results_dir = os.path.join(PROJECT, "build", "investigation_results", "flag_word2")
    os.makedirs(results_dir, exist_ok=True)
    ipc_dir = os.path.join(results_dir, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    bot = MednafenBot(ipc_dir, wsl_path(cue_path))

    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Could not start Mednafen")
        return

    # === EXPERIMENT 1: Button press on menu ===
    print("\n--- EXPERIMENT 1: DOWN press on menu ---")
    print("Replaying to menu state...")
    if not replay_to_state(bot, "menu", trace_events):
        print("FAIL: Could not replay to menu")
        bot.quit()
        return

    bot.set_watchpoint(flag_addr)
    print("Pressing DOWN and advancing 3 frames...")
    bot.input_press("DOWN")
    bot.frame_advance(3)
    bot.input_release("DOWN")

    hits = bot.read_watchpoint_hits()
    print_wp_hits(hits, addr_to_name, "WATCHPOINT: DOWN press on menu (3 frames)")
    dump_value(bot, flag_addr, results_dir, "menu_after_down")

    bot.clear_watchpoint()
    bot.quit()

    # === EXPERIMENT 2: Racing state ===
    print("\n\n--- EXPERIMENT 2: Racing state (idle) ---")
    ipc_dir2 = os.path.join(results_dir, "ipc2")
    os.makedirs(ipc_dir2, exist_ok=True)
    bot2 = MednafenBot(ipc_dir2, wsl_path(cue_path))
    print("Starting Mednafen (2nd session)...")
    if not bot2.start(timeout=30):
        print("FAIL: Could not start Mednafen")
        return

    print("Replaying to race state...")
    if not replay_to_state(bot2, "race", trace_events):
        print("FAIL: Could not replay to race")
        bot2.quit()
        return

    # First check current value
    dump_value(bot2, flag_addr, results_dir, "race_initial")

    # Set watchpoint and advance 3 frames
    bot2.set_watchpoint(flag_addr)
    print("Advancing 3 frames (idle racing)...")
    bot2.frame_advance(3)

    hits2 = bot2.read_watchpoint_hits()
    print_wp_hits(hits2, addr_to_name, "WATCHPOINT: Racing idle (3 frames)")
    dump_value(bot2, flag_addr, results_dir, "race_after_3frames")

    bot2.clear_watchpoint()
    bot2.quit()

    print("\nDone.")

if __name__ == "__main__":
    main()
