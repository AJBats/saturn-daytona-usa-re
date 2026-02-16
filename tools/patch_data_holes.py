#!/usr/bin/env python3
"""patch_data_holes.py -- Fill unclaimed regions with original binary data.

After linking, our reimpl binary has zero-filled gaps where the original binary
had data tables (filename strings, parameter tables, lookup tables, etc.).
The linker_stubs.c DAT_ symbols only cover individual 4-byte pool constants,
not multi-byte data regions.

This tool:
  1. Reads section headers from the ELF to find claimed address ranges
  2. For unclaimed (gap) regions, copies original binary bytes into our output
  3. Preserves all our code and data -- only patches gaps

Usage: python3 tools/patch_data_holes.py [--dry-run]
"""

import os
import re
import struct
import subprocess
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ORIG_BIN = os.path.join(PROJ, "build", "disc", "files", "APROG.BIN")
OUR_BIN = os.path.join(PROJ, "reimpl", "build", "APROG.BIN")
ELF_FILE = os.path.join(PROJ, "reimpl", "build", "daytona.elf")
OBJDUMP = os.path.join(PROJ, "tools", "sh-elf", "bin", "sh-elf-objdump")
BASE_ADDR = 0x06003000

DRY_RUN = "--dry-run" in sys.argv


def parse_elf_sections():
    """Parse ELF section headers to find claimed address ranges.

    Uses objdump -h to get section name, size, VMA for all sections.
    Returns sorted list of (start, end) tuples.
    """
    result = subprocess.run(
        [OBJDUMP, "-h", ELF_FILE],
        capture_output=True, text=True
    )

    claimed = []
    for line in result.stdout.splitlines():
        # Format: idx name  size  VMA  LMA  file_off  2**align
        # Example:  3 .func_FUN_06003218 00000054  06003218  06003218  00003218  2**0
        parts = line.strip().split()
        if len(parts) >= 6:
            try:
                idx = int(parts[0])
                name = parts[1]
                size = int(parts[2], 16)
                vma = int(parts[3], 16)

                if size > 0 and 0x06003000 <= vma < 0x060A0000:
                    claimed.append((vma, vma + size))
            except (ValueError, IndexError):
                continue

    # Merge overlapping ranges
    claimed.sort()
    merged = []
    for start, end in claimed:
        if merged and start <= merged[-1][1]:
            merged[-1] = (merged[-1][0], max(merged[-1][1], end))
        else:
            merged.append((start, end))

    return merged


def find_gaps(claimed, bin_start, bin_end):
    """Find address ranges NOT covered by any claimed section."""
    gaps = []
    pos = bin_start

    for claim_start, claim_end in claimed:
        if claim_start > pos and claim_start <= bin_end:
            gap_end = min(claim_start, bin_end)
            if gap_end > pos:
                gaps.append((pos, gap_end))
        pos = max(pos, claim_end)

    if pos < bin_end:
        gaps.append((pos, bin_end))

    return gaps


def main():
    with open(ORIG_BIN, "rb") as f:
        orig = bytearray(f.read())
    with open(OUR_BIN, "rb") as f:
        ours = bytearray(f.read())

    orig_end = BASE_ADDR + len(orig)
    our_end = BASE_ADDR + len(ours)

    print(f"Original: {len(orig)} bytes (0x{BASE_ADDR:08X}-0x{orig_end:08X})")
    print(f"Ours:     {len(ours)} bytes (0x{BASE_ADDR:08X}-0x{our_end:08X})")

    # Parse ELF sections
    claimed = parse_elf_sections()
    print(f"Claimed regions: {len(claimed)}")

    # Show a few claimed ranges
    for start, end in claimed[:5]:
        print(f"  0x{start:08X}-0x{end:08X} ({end-start} bytes)")
    if len(claimed) > 5:
        print(f"  ... and {len(claimed)-5} more")

    # Find gaps within the original binary's address range
    gaps = find_gaps(claimed, BASE_ADDR, min(orig_end, our_end))
    print(f"\nGap regions: {len(gaps)}")

    # Patch gaps with original data
    total_patched = 0
    total_nonzero = 0
    patches = []

    for gap_start, gap_end in gaps:
        off_start = gap_start - BASE_ADDR
        off_end = gap_end - BASE_ADDR
        gap_size = gap_end - gap_start

        orig_chunk = orig[off_start:off_end]
        ours_chunk = ours[off_start:off_end]

        # Count non-zero bytes in original that are zero in ours
        patch_bytes = sum(1 for i in range(gap_size)
                        if orig_chunk[i] != 0 and ours_chunk[i] == 0)

        if patch_bytes > 0:
            patches.append((gap_start, gap_end, gap_size, patch_bytes))
            total_patched += gap_size
            total_nonzero += patch_bytes

    print(f"\nPatching {len(patches)} gap regions "
          f"({total_patched} bytes total, {total_nonzero} non-zero bytes from original):")

    for addr, end, size, nonzero in patches[:40]:
        off = addr - BASE_ADDR
        preview = orig[off:off + min(16, size)].hex()
        try:
            raw = orig[off:off + min(32, size)]
            ascii_preview = "".join(chr(b) if 32 <= b < 127 else "." for b in raw)
        except:
            ascii_preview = ""
        print(f"  0x{addr:08X}-0x{end:08X} ({size:5d}B, {nonzero:4d} nonzero) "
              f"{preview}... [{ascii_preview}]")

    if len(patches) > 40:
        print(f"  ... and {len(patches) - 40} more")

    if DRY_RUN:
        print(f"\n[DRY RUN] Would patch {total_patched} bytes. No changes made.")
        return

    # Apply patches
    for addr, end, size, _ in patches:
        off = addr - BASE_ADDR
        ours[off:off + size] = orig[off:off + size]

    with open(OUR_BIN, "wb") as f:
        f.write(ours)

    print(f"\nPatched: {OUR_BIN} ({len(ours)} bytes)")
    print(f"Total bytes restored from original: {total_patched}")


if __name__ == "__main__":
    main()
