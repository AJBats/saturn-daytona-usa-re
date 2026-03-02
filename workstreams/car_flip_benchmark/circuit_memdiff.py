#!/usr/bin/env python3
"""Find which memory addresses change when LEFT/RIGHT is pressed on circuit select.

Loads save state, captures memory snapshot, presses button, captures again, diffs.
Scans a broad WRAM region to find the circuit selection variable.
"""

import os
import sys
import struct

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from investigate import MednafenBot, wsl_path, load_symbols

SAVE_STATE = os.path.join(PROJECT, "build", "save_states", "circuit_select_slot0.mc0")
CUE_PATH = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
IPC_DIR = os.path.join(PROJECT, "build", "debug_ipc")


def read_mem(bot, addr, size):
    """Read memory region via dump_mem_bin to temp file, return bytes."""
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


def diff_regions(before, after, base_addr, symbols=None):
    """Find all byte differences between two memory snapshots."""
    changes = []
    for i in range(min(len(before), len(after))):
        if before[i] != after[i]:
            addr = base_addr + i
            sym = ""
            if symbols:
                # Check if this address has a symbol name
                from bisect import bisect_right
                addrs = sorted(symbols.keys())
                idx = bisect_right(addrs, addr) - 1
                if idx >= 0 and addr - addrs[idx] < 64:
                    sym = f" ({symbols[addrs[idx]]}+0x{addr-addrs[idx]:X})"
            changes.append((addr, before[i], after[i], sym))
    return changes


def main():
    addr_to_name, _ = load_symbols()
    bot = MednafenBot(IPC_DIR, wsl_path(CUE_PATH))
    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Mednafen did not start")
        return

    bot.frame_advance(1)
    state_wsl = wsl_path(SAVE_STATE)

    # Regions to scan — focused on areas likely to contain UI state
    regions = [
        (0x06063D90, 0x40, "g_pad_state area"),
        (0x06078600, 0x100, "circuit mask/state area"),
        (0x0605A000, 0x200, "game state area"),
        (0x0605AB00, 0x100, "display flags area"),
        (0x0607EA00, 0x200, "runtime state area"),
    ]

    for button in ["LEFT", "RIGHT"]:
        print(f"\n{'='*60}")
        print(f"  Button: {button}")
        print(f"{'='*60}")

        # Reload save state for clean comparison
        ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
        if not ack or "error" in ack:
            print(f"FAIL: {ack}")
            bot.quit()
            return

        bot.frame_advance(1)

        # Capture BEFORE snapshots
        before = {}
        for addr, size, label in regions:
            before[addr] = read_mem(bot, addr, size)

        # Press button and advance frames
        bot.input_press(button)
        bot.frame_advance(5)
        bot.input_release(button)
        bot.frame_advance(1)

        # Capture AFTER snapshots
        all_changes = []
        for addr, size, label in regions:
            after = read_mem(bot, addr, size)
            if before[addr] and after:
                changes = diff_regions(before[addr], after, addr, addr_to_name)
                if changes:
                    print(f"\n  [{label}] {len(changes)} changes:")
                    for ch_addr, old, new, sym in changes:
                        print(f"    0x{ch_addr:08X}: 0x{old:02X} -> 0x{new:02X}{sym}")

        # Check transition_handler_a's pool variables specifically
        # sym_06063750 (from pool), sym_0607EADC, sym_0607EBCC
        extra_addrs = [
            (0x06063748, 0x10, "sym_06063750 area"),
            (0x06078880, 0x20, "sym_06078888 area"),
        ]
        for addr, size, label in extra_addrs:
            b = read_mem(bot, addr, size)
            if b:
                bef = before.get(addr)
                if not bef:
                    # Read before from a fresh load
                    pass
                else:
                    changes = diff_regions(bef, b, addr, addr_to_name)
                    if changes:
                        print(f"\n  [{label}] {len(changes)} changes:")
                        for ch_addr, old, new, sym in changes:
                            print(f"    0x{ch_addr:08X}: 0x{old:02X} -> 0x{new:02X}{sym}")

    bot.quit()
    print("\n\nDone.")


if __name__ == "__main__":
    main()
