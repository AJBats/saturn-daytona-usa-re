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
    """Parse ELF section headers directly from the binary file.

    Reads ELF32 section headers to find claimed address ranges.
    No external tools needed — pure Python ELF parsing.
    Returns sorted list of (start, end) tuples.
    """
    with open(ELF_FILE, "rb") as f:
        # ELF header
        magic = f.read(4)
        assert magic == b'\x7fELF', f"Not an ELF file: {ELF_FILE}"
        ei_class = struct.unpack('B', f.read(1))[0]  # 1=32bit, 2=64bit
        ei_data = struct.unpack('B', f.read(1))[0]    # 1=LE, 2=BE
        assert ei_class == 1, "Expected 32-bit ELF"

        endian = '>' if ei_data == 2 else '<'

        # Read relevant ELF header fields
        f.seek(32)  # e_shoff
        e_shoff = struct.unpack(endian + 'I', f.read(4))[0]
        f.seek(46)  # e_shentsize
        e_shentsize = struct.unpack(endian + 'H', f.read(2))[0]
        e_shnum = struct.unpack(endian + 'H', f.read(2))[0]

        # Parse section headers
        claimed = []
        for i in range(e_shnum):
            f.seek(e_shoff + i * e_shentsize)
            sh_data = f.read(e_shentsize)
            # Section header: name(4) type(4) flags(4) addr(4) offset(4) size(4) ...
            sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size = struct.unpack(
                endian + 'IIIIII', sh_data[:24]
            )

            # SHT_PROGBITS=1 (code/data), SHF_ALLOC=2
            if sh_type == 1 and (sh_flags & 2) and sh_size > 0:
                if 0x06003000 <= sh_addr < 0x060A0000:
                    claimed.append((sh_addr, sh_addr + sh_size))

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


def find_overflow_section():
    """Find the .text.overflow section address and size from ELF."""
    result = subprocess.run([OBJDUMP, "-h", ELF_FILE],
                          capture_output=True, text=True)
    for line in result.stdout.split('\n'):
        if '.text.overflow' in line:
            # objdump -h format: IDX NAME SIZE VMA LMA OFFSET ALIGN
            m = re.match(r'\s*\d+\s+\.text\.overflow\s+([0-9a-f]+)\s+([0-9a-f]+)',
                        line)
            if m:
                size = int(m.group(1), 16)
                vma = int(m.group(2), 16)
                return vma, size
    return None, None


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

    # NOTE: .text.overflow contains named C functions that are called at runtime.
    # Overwriting it with original data bytes would destroy those functions and
    # cause crashes. The overflow section must be preserved until functions are
    # properly relocated via linker script or ASM imports.

    with open(OUR_BIN, "wb") as f:
        f.write(ours)

    print(f"\nPatched: {OUR_BIN} ({len(ours)} bytes)")
    print(f"Total bytes restored from original: {total_patched}")


if __name__ == "__main__":
    main()
