#!/usr/bin/env python3
"""One-off: verify car_select_input handles button input on car select screen.

Experiments:
1. Replay to car select, check lock flag (sym_06085FF3)
2. Advance frames until lock clears (transition animation)
3. Watchpoint on sym_06085FF0 (selection index) during DOWN press
4. Watchpoint on sym_06085FF0 during LEFT press
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from investigate import (
    MednafenBot, load_symbols, sym_hex, resolve_symbol,
    parse_trace, replay_to_state, GAME_STATES, TRACE_FILE, wsl_path,
    PROJECT,
)

def dump_byte(bot, addr_hex, results_dir, label):
    dump_path = os.path.join(results_dir, f"byte_{label}.bin")
    bot.dump_mem_bin(addr_hex, "4", dump_path)
    if os.path.exists(dump_path):
        with open(dump_path, "rb") as f:
            data = f.read(4)
        val = int.from_bytes(data, "big")
        byte0 = (val >> 24) & 0xFF
        print(f"  {label}: 0x{val:08X} (byte[0]=0x{byte0:02X})")
        return val
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

    # Look up runtime addresses
    lock_addr = sym_hex(name_to_addr, "sym_06085FF3")
    index_addr = sym_hex(name_to_addr, "sym_06085FF0")
    func_addr = sym_hex(name_to_addr, "car_select_input")
    print(f"sym_06085FF3 (lock flag): 0x{lock_addr}")
    print(f"sym_06085FF0 (index): 0x{index_addr}")
    print(f"car_select_input: 0x{func_addr}")

    trace_events = parse_trace(TRACE_FILE)

    results_dir = os.path.join(PROJECT, "build", "investigation_results", "car_select")
    os.makedirs(results_dir, exist_ok=True)
    ipc_dir = os.path.join(results_dir, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    bot = MednafenBot(ipc_dir, wsl_path(cue_path))

    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Could not start Mednafen")
        return

    print("Replaying to car select state...")
    if not replay_to_state(bot, "car", trace_events):
        print("FAIL: Could not replay to car select")
        bot.quit()
        return

    # --- Check lock flag at initial frame ---
    print(f"\n--- EXPERIMENT 1: Lock flag check at frame {bot.current_frame} ---")
    dump_byte(bot, lock_addr, results_dir, "lock_initial")
    dump_byte(bot, index_addr, results_dir, "index_initial")

    # --- Advance 120 frames to let transition animation complete ---
    print("\nAdvancing 120 frames to let transition settle...")
    bot.frame_advance(120)
    print(f"Now at frame {bot.current_frame}")
    dump_byte(bot, lock_addr, results_dir, "lock_after_120")
    dump_byte(bot, index_addr, results_dir, "index_after_120")

    # --- Check if lock is clear ---
    dump_path = os.path.join(results_dir, "byte_lock_after_120.bin")
    if os.path.exists(dump_path):
        with open(dump_path, "rb") as f:
            data = f.read(4)
        lock_val = data[0]  # First byte at the address
        if lock_val != 0:
            print(f"WARNING: Lock flag still set (0x{lock_val:02X}) after 120 frames!")
            print("Trying 120 more frames...")
            bot.frame_advance(120)
            dump_byte(bot, lock_addr, results_dir, "lock_after_240")

    # --- EXPERIMENT 2: Watchpoint on index during DOWN press ---
    print(f"\n--- EXPERIMENT 2: Watchpoint on sym_06085FF0 during DOWN ---")
    bot.set_watchpoint(index_addr)
    print("Pressing DOWN and advancing 5 frames...")
    bot.input_press("DOWN")
    bot.frame_advance(5)
    bot.input_release("DOWN")

    hits = bot.read_watchpoint_hits()
    print_wp_hits(hits, addr_to_name, "WATCHPOINT: DOWN on car select (5 frames)")
    dump_byte(bot, index_addr, results_dir, "index_after_down")
    bot.clear_watchpoint()

    # --- EXPERIMENT 3: Watchpoint on index during LEFT press ---
    print(f"\n--- EXPERIMENT 3: Watchpoint on sym_06085FF0 during LEFT ---")
    bot.set_watchpoint(index_addr)
    print("Pressing LEFT and advancing 5 frames...")
    bot.input_press("LEFT")
    bot.frame_advance(5)
    bot.input_release("LEFT")

    hits2 = bot.read_watchpoint_hits()
    print_wp_hits(hits2, addr_to_name, "WATCHPOINT: LEFT on car select (5 frames)")
    dump_byte(bot, index_addr, results_dir, "index_after_left")
    bot.clear_watchpoint()

    # --- EXPERIMENT 4: Breakpoint on car_select_input during idle ---
    print(f"\n--- EXPERIMENT 4: Breakpoint on car_select_input during 3 idle frames ---")
    bot.set_breakpoint(func_addr)
    bot.frame_advance(3)
    # Check if breakpoint was hit (we'll see from the frame advance behavior)
    print(f"After 3 idle frames, now at frame {bot.current_frame}")
    bot.clear_breakpoint()

    bot.quit()
    print("\nDone.")

if __name__ == "__main__":
    main()
