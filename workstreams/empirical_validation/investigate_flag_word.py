#!/usr/bin/env python3
"""One-off: watchpoint on sym_0605B6D8 during menu idle.

Purpose: Determine who writes to the flag word that button_input_read dispatches.
This tells us empirically whether it's button data or something else.
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from investigate import (
    MednafenBot, load_symbols, sym_hex, resolve_symbol,
    parse_trace, replay_to_state, GAME_STATES, TRACE_FILE, wsl_path,
    PROJECT,
)

def main():
    addr_to_name, name_to_addr = load_symbols()

    # Get runtime address of sym_0605B6D8
    flag_addr = sym_hex(name_to_addr, "sym_0605B6D8")
    if not flag_addr:
        print("ERROR: sym_0605B6D8 not found in symbol table")
        return
    print(f"sym_0605B6D8 runtime address: 0x{flag_addr}")

    # Also look up button_input_read address for reference
    bir_addr = sym_hex(name_to_addr, "button_input_read")
    print(f"button_input_read runtime address: 0x{bir_addr}")

    # Parse trace
    trace_events = parse_trace(TRACE_FILE)

    # Launch emulator
    results_dir = os.path.join(PROJECT, "build", "investigation_results", "flag_word")
    os.makedirs(results_dir, exist_ok=True)
    ipc_dir = os.path.join(results_dir, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    bot = MednafenBot(ipc_dir, wsl_path(cue_path))

    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Could not start Mednafen")
        return

    print("Replaying to menu state...")
    if not replay_to_state(bot, "menu", trace_events):
        print("FAIL: Could not replay to menu")
        bot.quit()
        return

    print(f"At menu (frame {bot.current_frame}). Setting watchpoint on 0x{flag_addr}...")
    bot.set_watchpoint(flag_addr)

    # Advance 5 frames idle
    print("Advancing 5 frames (idle)...")
    bot.frame_advance(5)

    hits = bot.read_watchpoint_hits()
    print(f"\n=== WATCHPOINT HITS on sym_0605B6D8 (5 idle frames) ===")
    print(f"Total hits: {len(hits)}")

    for h in hits:
        # Parse and resolve addresses
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
        print()

    # Now also check: what value does sym_0605B6D8 have RIGHT NOW?
    bot.clear_watchpoint()

    # Dump the 4 bytes at the flag address
    dump_path = os.path.join(results_dir, "flag_dump.bin")
    bot.dump_mem_bin(flag_addr, "4", dump_path)
    if os.path.exists(dump_path):
        with open(dump_path, "rb") as f:
            data = f.read(4)
        val = int.from_bytes(data, "big")
        print(f"Current value of sym_0605B6D8: 0x{val:08X}")

    bot.quit()
    print("Done.")

if __name__ == "__main__":
    main()
