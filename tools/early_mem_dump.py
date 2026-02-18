#!/usr/bin/env python3
"""early_mem_dump.py -- Dump memory at 0x06003000 right after BIOS loads APROG.

Boots a disc in Mednafen, sets breakpoint at 0x06003000 (APROG entry point),
waits for the BIOS to load and jump there, then dumps the full APROG region.
Compares the dump byte-by-byte against on-disk binaries to determine which
binary is actually in RAM.

This tests hypothesis #3 from sawyer_l2.md: "The free binary isn't actually
executing — some unknown mechanism causes the production binary to be loaded."

Usage:
    python tools/early_mem_dump.py                  # dump reimpl disc
    python tools/early_mem_dump.py --disc prod      # dump production disc
    python tools/early_mem_dump.py --disc both      # dump both and compare
"""

import os
import sys
import time
import struct
import argparse

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, win_to_wsl

# Paths
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
BIN_PROD = os.path.join(PROJDIR, "build", "aprog.bin")
BIN_REIMPL = os.path.join(PROJDIR, "reimpl", "build", "APROG.BIN")
TMPDIR = os.path.join(PROJDIR, ".tmp")

APROG_BASE = 0x06003000


def dump_at_entry(name, cue_path, dump_size):
    """Boot a disc, break at APROG entry, dump memory. Returns bytes."""
    ipc_dir = os.path.join(TMPDIR, f"dump_{name}")
    inst = MednafenInstance(name, cue_path, ipc_dir)

    print(f"\n--- Booting {name} disc ---")
    inst.start()

    # Set breakpoint at APROG entry point
    print(f"  Setting breakpoint at 0x{APROG_BASE:08X}...")
    inst.breakpoint(APROG_BASE)

    # Continue — BIOS will load APROG and jump to entry
    print(f"  Waiting for BIOS to load APROG and hit entry point...")
    ack = inst.continue_exec()
    print(f"  {ack}")

    # Dump the full APROG region
    dump_path = os.path.join(ipc_dir, "aprog_dump.bin")
    print(f"  Dumping {dump_size} bytes from 0x{APROG_BASE:08X}...")
    inst.dump_mem_bin(APROG_BASE, dump_size, dump_path)
    time.sleep(0.3)

    # Also dump registers for context
    ack = inst.dump_regs()
    print(f"  Registers: {ack}")

    # Read the dump
    try:
        with open(dump_path, "rb") as f:
            data = f.read()
        print(f"  Got {len(data)} bytes")
    except FileNotFoundError:
        print(f"  ERROR: dump file not created at {dump_path}")
        data = None

    inst.quit()
    return data


def compare_against_file(dump, filepath, label, offset=0):
    """Compare memory dump against an on-disk binary file.

    offset: skip this many bytes at start of file (e.g. 0 for prod, 0 for reimpl)
    Returns (match_count, total_bytes, first_diff_offset)
    """
    try:
        with open(filepath, "rb") as f:
            file_data = f.read()
    except FileNotFoundError:
        print(f"  {label}: FILE NOT FOUND ({filepath})")
        return (0, 0, 0)

    file_data = file_data[offset:]
    compare_len = min(len(dump), len(file_data))

    matches = 0
    first_diff = -1
    diff_count = 0
    sample_diffs = []

    for i in range(compare_len):
        if dump[i] == file_data[i]:
            matches += 1
        else:
            diff_count += 1
            if first_diff == -1:
                first_diff = i
            if len(sample_diffs) < 10:
                sample_diffs.append((i, dump[i], file_data[i]))

    pct = (matches / compare_len * 100) if compare_len > 0 else 0
    status = "PERFECT MATCH" if diff_count == 0 else f"{diff_count} differences"

    print(f"  {label}: {matches}/{compare_len} bytes match ({pct:.2f}%) — {status}")
    if diff_count > 0 and first_diff >= 0:
        print(f"    First diff at offset 0x{first_diff:X} (addr 0x{APROG_BASE + first_diff:08X})")
        for off, mem_byte, file_byte in sample_diffs:
            print(f"      0x{APROG_BASE + off:08X}: mem=0x{mem_byte:02X} file=0x{file_byte:02X}")
        if diff_count > 10:
            print(f"      ... and {diff_count - 10} more")

    return (matches, compare_len, first_diff)


def main():
    parser = argparse.ArgumentParser(description="Early memory dump at APROG entry")
    parser.add_argument("--disc", choices=["prod", "reimpl", "both"], default="reimpl",
                        help="Which disc to boot (default: reimpl)")
    args = parser.parse_args()

    MednafenInstance.kill_stale()

    # Determine dump size — use the larger of the two binaries
    prod_size = os.path.getsize(BIN_PROD) if os.path.exists(BIN_PROD) else 0
    reimpl_size = os.path.getsize(BIN_REIMPL) if os.path.exists(BIN_REIMPL) else 0
    dump_size = max(prod_size, reimpl_size)
    print(f"Production binary: {prod_size} bytes")
    print(f"Reimpl binary:     {reimpl_size} bytes")
    print(f"Dump size:         {dump_size} bytes")

    results = {}

    if args.disc in ("reimpl", "both"):
        dump = dump_at_entry("reimpl", CUE_REIMPL, dump_size)
        if dump:
            print(f"\n=== Comparing reimpl disc memory against on-disk binaries ===")
            r_prod = compare_against_file(dump, BIN_PROD, "vs production binary")
            r_reimpl = compare_against_file(dump, BIN_REIMPL, "vs reimpl binary")
            results["reimpl"] = (dump, r_prod, r_reimpl)

            # Verdict
            prod_match = r_prod[0] == r_prod[1] and r_prod[1] > 0
            reimpl_match = r_reimpl[0] == r_reimpl[1] and r_reimpl[1] > 0
            print(f"\n  VERDICT for reimpl disc:")
            if reimpl_match:
                print(f"    RAM matches the REIMPL binary — free-layout is executing correctly!")
            elif prod_match:
                print(f"    RAM matches the PRODUCTION binary — something loaded the wrong binary!")
            else:
                # Check which is closer
                if r_prod[1] > 0 and r_reimpl[1] > 0:
                    prod_pct = r_prod[0] / r_prod[1] * 100
                    reimpl_pct = r_reimpl[0] / r_reimpl[1] * 100
                    closer = "production" if prod_pct > reimpl_pct else "reimpl"
                    print(f"    RAM matches NEITHER binary perfectly")
                    print(f"    Closer to {closer} (prod={prod_pct:.2f}%, reimpl={reimpl_pct:.2f}%)")

            # Save dump for offline analysis
            save_path = os.path.join(TMPDIR, "reimpl_aprog_dump.bin")
            with open(save_path, "wb") as f:
                f.write(dump)
            print(f"\n  Dump saved to {save_path}")

    if args.disc in ("prod", "both"):
        dump = dump_at_entry("prod", CUE_PROD, dump_size)
        if dump:
            print(f"\n=== Comparing prod disc memory against on-disk binaries ===")
            r_prod = compare_against_file(dump, BIN_PROD, "vs production binary")
            results["prod"] = (dump, r_prod, None)

            prod_match = r_prod[0] == r_prod[1] and r_prod[1] > 0
            print(f"\n  VERDICT for prod disc:")
            if prod_match:
                print(f"    RAM matches production binary — sanity check PASSED")
            else:
                print(f"    RAM does NOT match production binary — something unexpected!")

            save_path = os.path.join(TMPDIR, "prod_aprog_dump.bin")
            with open(save_path, "wb") as f:
                f.write(dump)
            print(f"\n  Dump saved to {save_path}")

    # If we dumped both, also compare the two memory dumps directly
    if "prod" in results and "reimpl" in results:
        dump_p = results["prod"][0]
        dump_r = results["reimpl"][0]
        compare_len = min(len(dump_p), len(dump_r))
        diffs = sum(1 for i in range(compare_len) if dump_p[i] != dump_r[i])
        print(f"\n=== Direct comparison: prod dump vs reimpl dump ===")
        if diffs == 0:
            print(f"  IDENTICAL — both discs load the same bytes to 0x{APROG_BASE:08X}")
            print(f"  This confirms: the free-layout shift is NOT reaching memory")
        else:
            print(f"  {diffs} differences in {compare_len} bytes")
            # Show first few
            shown = 0
            for i in range(compare_len):
                if dump_p[i] != dump_r[i] and shown < 10:
                    print(f"    0x{APROG_BASE + i:08X}: prod=0x{dump_p[i]:02X} reimpl=0x{dump_r[i]:02X}")
                    shown += 1

    print("\nDone.")


if __name__ == "__main__":
    main()
