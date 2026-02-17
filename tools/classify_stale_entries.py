#!/usr/bin/env python3
"""
classify_stale_entries.py - Analyze "stale" 4-byte values in free-layout binary

Compares production binary (build/aprog.bin, 394896 bytes) against free-layout
binary (reimpl/build/APROG.BIN, 394900 bytes) to find 4-byte values in the code
address range that did NOT shift by +4 as expected.

Layout:
  - Production: address = 0x06003000 + offset
  - Free-layout: _start at offset 0x00-0xFB (same as prod), then 4-byte pad at
    0xFC-0xFF, then everything else at prod_offset + 4
  - So for offset >= 0xFC in prod: free_offset = prod_offset + 4
  - A "stale" value: prod has big-endian value V in code range at offset i,
    and free has same value V at offset i+4, instead of V+4

Binary is big-endian (SH-2).
"""

import struct
import os
import re
import glob
from collections import defaultdict

# Configuration
BASE_ADDR = 0x06003000
CODE_START = 0x06003000
CODE_END = 0x06063690  # end of code region (0x06003000 + 0x60690)
# Wider range: any value in work RAM could be a pointer
ADDR_RANGE_LO = 0x06003000  # start of code
ADDR_RANGE_HI = 0x060FFFFF  # end of work RAM (generous upper bound)
SHIFT = 4
START_SECTION_END = 0xFC  # _start ends here (prod offset), pad starts

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PROD_BIN = os.path.join(PROJ, "build", "aprog.bin")
FREE_BIN = os.path.join(PROJ, "reimpl", "build", "APROG.BIN")
SYMS_FILE = os.path.join(PROJ, "build", "aprog_syms.txt")
MAP_FILE = os.path.join(PROJ, "reimpl", "build", "daytona.map")
ASM_DIR = os.path.join(PROJ, "reimpl", "src")


def load_binary(path):
    with open(path, "rb") as f:
        return f.read()


def read_u32_be(data, offset):
    """Read a 32-bit big-endian value at the given offset."""
    return struct.unpack(">I", data[offset:offset+4])[0]


def load_symbols(syms_file):
    """Load function symbols from aprog_syms.txt. Returns sorted list of (addr, name)."""
    syms = []
    with open(syms_file, "r") as f:
        for line in f:
            line = line.strip().replace('\r', '')
            m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+);', line)
            if m:
                name = m.group(1)
                addr = int(m.group(2), 16)
                syms.append((addr, name))
    syms.sort()
    return syms


def load_map_symbols(map_file):
    """Load all symbols from linker map for address->function lookup.
    Returns sorted list of (addr, name, size) for .text sections.

    Map format is two lines:
      .text.FUN_060030FC
                    0x06003100      0x11c build/FUN_060030FC.o
    """
    syms = []
    pending_name = None
    with open(map_file, "r") as f:
        for line in f:
            line = line.rstrip().replace('\r', '')
            # Check for section header line
            m_sect = re.match(r'\s*\.text\.(FUN_[0-9A-Fa-f]+)\s*$', line)
            if m_sect:
                pending_name = m_sect.group(1)
                continue
            # Check for address/size line following a section header
            if pending_name:
                m_addr = re.match(r'\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+', line)
                if m_addr:
                    addr = int(m_addr.group(1), 16)
                    size = int(m_addr.group(2), 16)
                    syms.append((addr, pending_name, size))
                pending_name = None
    syms.sort()
    return syms


def find_containing_function(addr, map_syms):
    """Find which function contains the given address using map data."""
    for i in range(len(map_syms) - 1, -1, -1):
        func_addr, func_name, func_size = map_syms[i]
        if func_addr <= addr < func_addr + func_size:
            return func_name, func_addr
    return "UNKNOWN", 0


def value_to_bytes_be(val):
    """Convert a 32-bit value to 4 big-endian bytes."""
    return [(val >> 24) & 0xFF, (val >> 16) & 0xFF, (val >> 8) & 0xFF, val & 0xFF]


def search_asm_files(asm_dir, stale_values):
    """Search .s files for .4byte and .byte references to stale values.
    Returns dict: value -> { '4byte': [(file, line)], 'byte': [(file, line)] }
    """
    results = defaultdict(lambda: {'4byte': [], 'byte': []})

    # Build lookup sets
    # For .4byte, we need the address as a symbol name
    # For .byte, we need the 4 individual bytes

    value_to_sym = {}
    for val in stale_values:
        sym = "0x%08X" % val
        value_to_sym[val] = sym

    s_files = glob.glob(os.path.join(asm_dir, "*.s"))

    for s_file in s_files:
        basename = os.path.basename(s_file)
        try:
            with open(s_file, "r") as f:
                lines = f.readlines()
        except Exception:
            continue

        for i, line in enumerate(lines):
            line = line.strip().replace('\r', '')

            # Check for .4byte references
            m4 = re.match(r'\.4byte\s+(\w+)', line)
            if m4:
                sym_name = m4.group(1)
                # Try to extract address from symbol name
                addr_m = re.match(r'(?:FUN_|sym_|loc_|DAT_)([0-9A-Fa-f]+)', sym_name)
                if addr_m:
                    sym_addr = int(addr_m.group(1), 16)
                    if sym_addr in stale_values:
                        results[sym_addr]['4byte'].append((basename, i+1))

            # Check for .byte sequences that encode a stale value
            # Pattern: .byte 0xHH, 0xHH on consecutive lines (2 bytes per line)
            # So a 4-byte value spans 2 lines of .byte directives
            mb = re.match(r'\.byte\s+0x([0-9A-Fa-f]{2}),\s*0x([0-9A-Fa-f]{2})', line)
            if mb and i + 1 < len(lines):
                b0 = int(mb.group(1), 16)
                b1 = int(mb.group(2), 16)
                next_line = lines[i+1].strip().replace('\r', '')
                mb2 = re.match(r'\.byte\s+0x([0-9A-Fa-f]{2}),\s*0x([0-9A-Fa-f]{2})', next_line)
                if mb2:
                    b2 = int(mb2.group(1), 16)
                    b3 = int(mb2.group(2), 16)
                    val = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3
                    if val in stale_values:
                        results[val]['byte'].append((basename, i+1))

    return results


def classify_value(val, in_4byte, in_byte):
    """Classify a stale value.

    Returns: (classification, reason)

    Heuristics for distinguishing real addresses from data that starts with 0x06:
    - Real SH-2 addresses: 0x06003000-0x06063690 (code), 0x06063690-0x0607FFFF (data/BSS)
    - Data bytes: sequences like 0x06, 0x04, 0x0E, 0x0D that form 0x06040E0D
    - Masks: 0x0600FFFF, 0x0601FFFF, 0x0602FFFF
    - Repeating patterns: 0x06010001, 0x06020002, etc.
    """
    b0 = (val >> 24) & 0xFF  # always 0x06 for values in our range
    b1 = (val >> 16) & 0xFF
    b2 = (val >> 8) & 0xFF
    b3 = val & 0xFF

    # Check for mask-like patterns (0x06xxFFFF)
    if (val & 0xFFFF) == 0xFFFF:
        return "DATA_CONSTANT", "mask pattern (0x%08X ends in 0xFFFF)" % val

    # Check for repeating pattern data (low bytes match high bytes)
    # e.g., 0x06010001, 0x06030003, 0x06050005
    high_byte = (val >> 16) & 0xFF
    low_short = val & 0xFFFF
    if low_short < 0x0100 and high_byte == low_short:
        return "PATTERN_DATA", "pattern: high=0x%02X matches low=0x%04X" % (high_byte, low_short)

    # Check for "small byte sequence" pattern:
    # If all 4 bytes are small (< 0x20 or so), this is likely data bytes, not an address
    # Real addresses have b1 in {0x00-0x0F} (Saturn work RAM) but b2 and b3 are larger
    # Data bytes tend to all be small values
    if b1 <= 0x0F and b2 <= 0x0F and b3 <= 0x0F:
        return "PATTERN_DATA", "all bytes small (0x%02X,0x%02X,0x%02X,0x%02X) - likely data" % (b0, b1, b2, b3)

    # Check for addresses below code start
    if val < CODE_START:
        return "PATTERN_DATA", "below code start (0x%08X < 0x%08X)" % (val, CODE_START)

    # If it's found as .4byte in source, the linker should have relocated it
    if in_4byte:
        return "ABS_SYMBOL", "found as .4byte but PROVIDE symbol is absolute (not relocatable)"

    # If it's in .byte sequences, it's a genuine unsymbolized reference
    if in_byte:
        # But check if it's really plausible as an address
        if CODE_START <= val <= CODE_END:
            return "GENUINE_STALE", "found as .byte in code range (needs .4byte symbolization)"
        elif CODE_END < val <= 0x0607FFFF:
            return "GENUINE_STALE", "found as .byte in data/BSS range (needs .4byte symbolization)"
        else:
            # Beyond reasonable data range - might be data constant
            return "DATA_CONSTANT", "found as .byte but val 0x%08X beyond data range" % val

    # Value is in code address range but not found in source
    if CODE_START <= val <= CODE_END:
        return "GENUINE_STALE", "in code range, not found in .s files (may be in .c or data)"

    # Values in data/BSS range (after code, before end of work RAM)
    if CODE_END < val <= 0x0607FFFF:
        return "GENUINE_STALE", "in data/BSS range, not found in .s files"

    # Values in work RAM but far from code/data
    if 0x06003000 <= val <= 0x060FFFFF:
        return "GENUINE_STALE", "in work RAM range (distant reference?)"

    return "UNKNOWN", "could not classify"


def main():
    print("=" * 80)
    print("STALE ENTRY CLASSIFIER")
    print("=" * 80)

    # Load binaries
    prod = load_binary(PROD_BIN)
    free = load_binary(FREE_BIN)
    print(f"\nProduction binary: {len(prod)} bytes ({PROD_BIN})")
    print(f"Free-layout binary: {len(free)} bytes ({FREE_BIN})")
    print(f"Size difference: {len(free) - len(prod)} bytes (expected: {SHIFT})")

    assert len(free) - len(prod) == SHIFT, "Size difference is not 4!"

    # Load symbols
    prod_syms = load_symbols(SYMS_FILE)
    print(f"Loaded {len(prod_syms)} function symbols from aprog_syms.txt")

    map_syms = load_map_symbols(MAP_FILE)
    print(f"Loaded {len(map_syms)} section entries from daytona.map")

    # Phase 1: Find all stale values
    print(f"\n{'=' * 80}")
    print("PHASE 1: Scanning for stale 4-byte values")
    print(f"{'=' * 80}")
    print(f"Scan range: prod offset 0x{START_SECTION_END:06X} to 0x{len(prod) - 4:06X}")
    print(f"Narrow address range (code only): 0x{CODE_START:08X} - 0x{CODE_END:08X}")
    print(f"Wide address range (work RAM):    0x{ADDR_RANGE_LO:08X} - 0x{ADDR_RANGE_HI:08X}")
    print()

    stale_entries = []  # (prod_offset, prod_addr, value)

    # Scan every 2-byte boundary in the entire binary after _start
    # (SH-2 instructions are 2 bytes, pool entries are 4 bytes)

    scan_start = START_SECTION_END  # 0xFC - first offset after _start
    scan_end = len(prod)  # scan entire binary

    for offset in range(scan_start, scan_end - 3, 2):  # step by 2 (SH-2 instruction width)
        prod_val = read_u32_be(prod, offset)
        free_val = read_u32_be(free, offset + SHIFT)

        # Check if prod value is in the work RAM address range
        if ADDR_RANGE_LO <= prod_val <= ADDR_RANGE_HI:
            # It's a potential address reference
            # In the free binary, if it was relocated, it should be prod_val + SHIFT
            # If it's "stale", the free binary still has prod_val (not prod_val + SHIFT)
            if free_val == prod_val:
                # Stale! The value didn't shift
                prod_addr = BASE_ADDR + offset
                stale_entries.append((offset, prod_addr, prod_val))
            elif free_val == prod_val + SHIFT:
                # Correctly relocated, not stale
                pass
            # else: some other difference (not relevant here)

    # Deduplicate: if offset and offset+2 both find the same stale entry,
    # keep only the 4-byte-aligned one (or the first one)
    # Actually, overlapping 4-byte reads at 2-byte steps can cause duplicates
    # where the same 4-byte pool entry is found at both aligned offsets.
    # Filter to keep only 4-byte aligned entries, plus any 2-byte misaligned ones
    # that don't overlap with an aligned entry.
    seen_offsets = set()
    filtered = []
    for offset, addr, val in stale_entries:
        if offset % 4 == 0:
            seen_offsets.add(offset)
            filtered.append((offset, addr, val))
    for offset, addr, val in stale_entries:
        if offset % 4 != 0:
            # Check if this overlaps with a 4-byte-aligned entry
            aligned_before = offset - (offset % 4)
            aligned_after = aligned_before + 4
            if aligned_before not in seen_offsets and aligned_after not in seen_offsets:
                filtered.append((offset, addr, val))
                seen_offsets.add(offset)
            elif aligned_before in seen_offsets or aligned_after in seen_offsets:
                # Skip - overlaps with aligned entry
                pass
            else:
                filtered.append((offset, addr, val))
                seen_offsets.add(offset)

    filtered.sort()
    stale_entries = filtered

    print(f"Found {len(stale_entries)} stale entries (after dedup)")

    # Collect unique stale values for ASM search
    stale_value_set = set(val for _, _, val in stale_entries)
    print(f"Unique stale values: {len(stale_value_set)}")

    # Phase 2: Search ASM files
    print(f"\n{'=' * 80}")
    print("PHASE 2: Searching .s files for stale values")
    print(f"{'=' * 80}")

    asm_results = search_asm_files(ASM_DIR, stale_value_set)

    found_4byte = sum(1 for v in asm_results if asm_results[v]['4byte'])
    found_byte = sum(1 for v in asm_results if asm_results[v]['byte'])
    print(f"Values found as .4byte: {found_4byte}")
    print(f"Values found as .byte: {found_byte}")
    print(f"Values not found in .s: {len(stale_value_set) - len(asm_results)}")

    # Phase 3: Classify and print details
    print(f"\n{'=' * 80}")
    print("PHASE 3: Classification of all stale entries")
    print(f"{'=' * 80}")

    classifications = defaultdict(list)

    for offset, addr, val in stale_entries:
        # Find containing function
        # The addr is in prod space. For the map (free space), addr would be addr + 4
        # But let's look up in prod syms first
        func_name, func_addr = find_containing_function(addr + SHIFT, map_syms)

        in_4byte = bool(asm_results.get(val, {}).get('4byte', []))
        in_byte = bool(asm_results.get(val, {}).get('byte', []))

        classification, reason = classify_value(val, in_4byte, in_byte)
        classifications[classification].append((offset, addr, val, func_name, func_addr, in_4byte, in_byte, reason))

    # Print all entries grouped by classification
    for cls in ["GENUINE_STALE", "ABS_SYMBOL", "DATA_CONSTANT", "PATTERN_DATA", "UNKNOWN"]:
        entries = classifications.get(cls, [])
        if not entries:
            continue

        print(f"\n--- {cls} ({len(entries)} entries) ---")
        for offset, addr, val, func_name, func_addr, in_4byte, in_byte, reason in entries:
            source_info = ""
            if in_4byte:
                locs = asm_results[val]['4byte']
                source_info = " [.4byte in: " + ", ".join(f"{f}:{l}" for f, l in locs[:3]) + "]"
            if in_byte:
                locs = asm_results[val]['byte']
                source_info += " [.byte in: " + ", ".join(f"{f}:{l}" for f, l in locs[:3]) + "]"

            print(f"  offset=0x{offset:06X}  addr=0x{addr:08X}  val=0x{val:08X}  "
                  f"in={func_name}+0x{addr + SHIFT - func_addr:X}  "
                  f"reason: {reason}{source_info}")

    # Phase 4: Summary
    print(f"\n{'=' * 80}")
    print("SUMMARY")
    print(f"{'=' * 80}")

    print(f"\nTotal stale entries: {len(stale_entries)}")
    print(f"Unique stale values: {len(stale_value_set)}")
    print()

    for cls in ["GENUINE_STALE", "ABS_SYMBOL", "DATA_CONSTANT", "PATTERN_DATA", "UNKNOWN"]:
        count = len(classifications.get(cls, []))
        if count:
            print(f"  {cls:20s}: {count:4d}")

    # Print value frequency
    print(f"\n--- Value frequency (top 20) ---")
    val_freq = defaultdict(int)
    for _, _, val in stale_entries:
        val_freq[val] += 1
    for val, count in sorted(val_freq.items(), key=lambda x: -x[1])[:20]:
        in_4byte = bool(asm_results.get(val, {}).get('4byte', []))
        in_byte = bool(asm_results.get(val, {}).get('byte', []))
        src = []
        if in_4byte: src.append(".4byte")
        if in_byte: src.append(".byte")
        src_str = " (" + ", ".join(src) + ")" if src else ""
        print(f"  0x{val:08X}: {count:3d} occurrences{src_str}")

    # Print all unique stale values sorted
    print(f"\n--- All unique stale values ({len(stale_value_set)}) ---")
    for val in sorted(stale_value_set):
        in_4byte = bool(asm_results.get(val, {}).get('4byte', []))
        in_byte = bool(asm_results.get(val, {}).get('byte', []))
        freq = val_freq[val]
        src = []
        if in_4byte: src.append(".4byte")
        if in_byte: src.append(".byte")
        src_str = " (" + ", ".join(src) + ")" if src else ""
        print(f"  0x{val:08X}  freq={freq:3d}{src_str}")


if __name__ == "__main__":
    main()
