#!/usr/bin/env python3
"""One-off: watchpoint on sym_06085FF0 at MODE SELECT during DOWN.

The investigation_log showed car_select_input called 10x at mode select.
Let's verify it writes sym_06085FF0 there too, or if the call trace was misleading.

Also: try a wider memory diff at mode select during DOWN to see what
car_select_input ACTUALLY modifies (if anything).
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

    index_addr = sym_hex(name_to_addr, "sym_06085FF0")
    func_addr = sym_hex(name_to_addr, "car_select_input")
    print(f"sym_06085FF0: 0x{index_addr}")
    print(f"car_select_input: 0x{func_addr}")

    trace_events = parse_trace(TRACE_FILE)

    results_dir = os.path.join(PROJECT, "build", "investigation_results", "car_select7")
    os.makedirs(results_dir, exist_ok=True)
    ipc_dir = os.path.join(results_dir, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

    print("\n=== At mode select (frame 1537) ===")
    bot = MednafenBot(ipc_dir, wsl_path(cue_path))
    if not bot.start(timeout=30):
        print("FAIL"); return
    if not replay_to_state(bot, "menu", trace_events):
        print("FAIL"); bot.quit(); return

    # Idle 3 frames to stabilize
    bot.frame_advance(3)
    print(f"At frame {bot.current_frame}")

    # EXPERIMENT: Memory diff on broad range 0x06085F00-0x06086100 during idle
    print("\n--- Memory diff 0x06085F00-0x06086100: 3 idle frames ---")
    before_path = os.path.join(results_dir, "mem_idle_before.bin")
    bot.dump_mem_bin("06085F00", "512", before_path)
    bot.frame_advance(3)
    after_path = os.path.join(results_dir, "mem_idle_after.bin")
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
            print(f"  {len(changes)} bytes changed during idle:")
            for addr, old, new in changes[:20]:
                sym = resolve_symbol(addr, addr_to_name) if addr in addr_to_name else f"0x{addr:08X}"
                print(f"    0x{addr:08X} ({sym}): 0x{old:02X} -> 0x{new:02X}")
        else:
            print("  No changes during idle")

    # EXPERIMENT: What does the function tail-call dispatch table look like?
    # The function loads a function pointer from a table indexed by sym_06085FF0
    # Table base is at pool entry .L_pool_06019C0C
    # Let me check what's at 0x06019C0C in the pool (retail address)
    # In free build: need to find actual pool entry value
    print("\n--- Dump function pointer table (8 entries * 4 bytes) ---")
    # The pool reference is .byte 0xD3, 0x17 at line 201 in the source
    # This is mov.l @(disp*4, PC), r3 where disp=0x17=23
    # At retail address 0x06019B9A + some offset...
    # Actually let me just dump what's AT sym_06085FF0 as a 4-byte pointer table
    # Wait, the table isn't at sym_06085FF0. The table is pointed to by a pool entry.
    # I need to read the pool entry value first.

    # Let me try a different approach: just check if car_select_input PC appears
    # in the call trace during idle
    print("\n--- Checking if car_select_input appears in 5-frame call trace ---")
    # Use the file-based call trace approach from investigate.py
    ct_wsl = wsl_path(os.path.join(results_dir, "calltrace_menu.txt"))
    bot.send_cmd(f"call_trace {ct_wsl}")
    bot.frame_advance(5)
    bot.send_cmd("call_trace_stop")

    ct_path = os.path.join(results_dir, "calltrace_menu.txt")
    if os.path.exists(ct_path):
        func_hex = func_addr.lower()
        count = 0
        with open(ct_path) as f:
            for line in f:
                if func_hex in line.lower():
                    count += 1
        print(f"  car_select_input (0x{func_addr}) in call trace: {count} occurrences")
    else:
        print(f"  Call trace file not found")

    bot.quit()
    print("\nDone.")

if __name__ == "__main__":
    main()
