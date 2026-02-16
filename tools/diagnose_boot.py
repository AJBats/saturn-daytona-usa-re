#!/usr/bin/env python3
"""diagnose_boot.py — Dump memory and registers from both production and reimpl at early boot.

Launches both Mednafen instances, pauses immediately, and dumps:
1. Memory at 0x06003000 (game entry point) — first 256 bytes
2. CPU registers
3. Memory at 0x06000000 (low work RAM start) — first 256 bytes

This helps diagnose whether the reimpl binary is even loaded correctly.
"""

import os
import sys
import time
import struct

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
# Reuse MednafenInstance from parallel_compare
from parallel_compare import MednafenInstance, read_regs_bin, compare_regs, win_to_wsl

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")


def dump_mem_region(inst, addr, size, win_path):
    """Dump memory region and return bytes."""
    wsl_path = win_to_wsl(win_path)
    inst.send(f"dump_mem_bin {addr:X} {size:X} {wsl_path}")
    time.sleep(0.2)
    try:
        with open(win_path, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def hex_dump(data, base_addr, max_lines=16):
    """Print hex dump."""
    for i in range(0, min(len(data), max_lines * 16), 16):
        hex_str = " ".join(f"{b:02X}" for b in data[i:i+16])
        ascii_str = "".join(chr(b) if 32 <= b < 127 else "." for b in data[i:i+16])
        print(f"  {base_addr + i:08X}: {hex_str:<48s} {ascii_str}")


def compare_memory(data_a, data_b, base_addr, label_a="prod", label_b="reimpl"):
    """Compare two memory dumps, showing first differences."""
    if data_a == data_b:
        print(f"  Memory at 0x{base_addr:08X}: IDENTICAL ({len(data_a)} bytes)")
        return True

    # Find first difference
    for i in range(min(len(data_a), len(data_b))):
        if data_a[i] != data_b[i]:
            print(f"  Memory at 0x{base_addr:08X}: DIFFERS at offset +0x{i:X} (addr 0x{base_addr + i:08X})")
            # Show context around difference
            start = max(0, (i // 16) * 16 - 16)
            end = min(len(data_a), start + 64)
            print(f"  {label_a}:")
            hex_dump(data_a[start:end], base_addr + start, 4)
            print(f"  {label_b}:")
            hex_dump(data_b[start:end], base_addr + start, 4)

            # Count total differences
            total_diff = sum(1 for j in range(min(len(data_a), len(data_b)))
                           if data_a[j] != data_b[j])
            print(f"  Total differing bytes: {total_diff} / {min(len(data_a), len(data_b))}")
            return False

    if len(data_a) != len(data_b):
        print(f"  Memory at 0x{base_addr:08X}: Different sizes ({len(data_a)} vs {len(data_b)})")
        return False

    return True


def main():
    ipc_a = os.path.join(TMPDIR, "emu_prod")
    ipc_b = os.path.join(TMPDIR, "emu_reimpl")

    prod = MednafenInstance("prod", CUE_PROD, ipc_a)
    reimpl = MednafenInstance("reimpl", CUE_REIMPL, ipc_b)

    print("Starting emulators...")
    prod.start()
    reimpl.start()

    # Let BIOS initialize, then pause
    print("Waiting for BIOS init (3s)...")
    time.sleep(3)
    print("Pausing...")
    ack_a = prod.pause()
    ack_b = reimpl.pause()
    print(f"  prod:   {ack_a}")
    print(f"  reimpl: {ack_b}")

    # Dump registers
    print("\n=== CPU Registers ===")
    regs_path_a = os.path.join(ipc_a, "regs.bin")
    regs_path_b = os.path.join(ipc_b, "regs.bin")
    prod.dump_regs_bin(regs_path_a)
    reimpl.dump_regs_bin(regs_path_b)
    time.sleep(0.2)
    regs_a = read_regs_bin(regs_path_a)
    regs_b = read_regs_bin(regs_path_b)

    if regs_a and regs_b:
        print(f"  {'Register':<6s}  {'Production':>12s}  {'Reimpl':>12s}  {'Match':>5s}")
        print(f"  {'------':<6s}  {'----------':>12s}  {'------':>12s}  {'-----':>5s}")
        for name in ["PC", "SR", "PR", "GBR", "VBR", "MACH"] + [f"R{i}" for i in range(16)]:
            va = regs_a.get(name, 0)
            vb = regs_b.get(name, 0)
            match = "OK" if va == vb else "DIFF"
            print(f"  {name:<6s}  0x{va:08X}    0x{vb:08X}    {match}")

    # Memory dumps at key locations
    regions = [
        (0x06003000, 0x100, "Game entry point (main)"),
        (0x06003000, 0x1000, "First 4KB of game code"),
        (0x06000000, 0x100, "Low work RAM start"),
        (0x06001000, 0x100, "Stack area"),
    ]

    for addr, size, desc in regions:
        print(f"\n=== Memory: {desc} (0x{addr:08X}, {size} bytes) ===")
        path_a = os.path.join(ipc_a, f"mem_{addr:08X}.bin")
        path_b = os.path.join(ipc_b, f"mem_{addr:08X}.bin")
        data_a = dump_mem_region(prod, addr, size, path_a)
        data_b = dump_mem_region(reimpl, addr, size, path_b)

        if data_a is None or data_b is None:
            print("  ERROR: Could not dump memory")
            continue

        compare_memory(data_a, data_b, addr)

    # Also check the larger game code region
    print(f"\n=== Memory comparison: full game code (0x06003000, 64KB) ===")
    path_a = os.path.join(ipc_a, "mem_full_code.bin")
    path_b = os.path.join(ipc_b, "mem_full_code.bin")
    data_a = dump_mem_region(prod, 0x06003000, 0x10000, path_a)
    data_b = dump_mem_region(reimpl, 0x06003000, 0x10000, path_b)
    if data_a and data_b:
        matching = sum(1 for i in range(min(len(data_a), len(data_b))) if data_a[i] == data_b[i])
        total = min(len(data_a), len(data_b))
        pct = 100.0 * matching / total if total else 0
        print(f"  {matching}/{total} bytes match ({pct:.1f}%)")

        # Find first difference
        for i in range(total):
            if data_a[i] != data_b[i]:
                print(f"  First difference at 0x{0x06003000 + i:08X} (offset +0x{i:X})")
                print(f"    prod:   {data_a[i]:02X}")
                print(f"    reimpl: {data_b[i]:02X}")
                break

    prod.quit()
    reimpl.quit()
    print("\nDone.")


if __name__ == "__main__":
    main()
