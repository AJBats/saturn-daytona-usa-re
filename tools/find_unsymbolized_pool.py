#!/usr/bin/env python3
"""
Scan .s files in reimpl/src/ for unsymbolized constant pool entries.

Finds groups of 4 consecutive bytes in the CONSTANT POOL region that decode
(big-endian) to a 32-bit value in 0x06000000-0x060FFFFF (Work RAM High).

Distinguishes between:
  - Instruction code region (before first pool/data marker)
  - Constant pool entries (interleaved with .4byte directives)
  - Labeled data blocks (inside DAT_/sym_ global labels)

RESEARCH ONLY - does not modify any files.
"""

import os
import re
import sys
from collections import defaultdict

SRC_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                       "reimpl", "src")
SYMS_FILE = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                         "build", "aprog_syms.txt")

def load_known_symbols():
    """Load all known symbols from aprog_syms.txt and .s file .4byte references."""
    symbols = {}  # addr -> symbol_name

    # Load from aprog_syms.txt
    if os.path.exists(SYMS_FILE):
        with open(SYMS_FILE, "r") as f:
            for line in f:
                line = line.strip()
                m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+);', line)
                if m:
                    name = m.group(1)
                    addr = int(m.group(2), 16)
                    symbols[addr] = name

    # Also scan all .s files for .4byte references to collect sym_ names
    for fname in os.listdir(SRC_DIR):
        if not fname.endswith(".s"):
            continue
        fpath = os.path.join(SRC_DIR, fname)
        with open(fpath, "r") as f:
            for line in f:
                line = line.strip()
                m = re.match(r'\.4byte\s+((?:FUN|DAT|sym|PTR)_([0-9A-Fa-f]+))', line)
                if m:
                    name = m.group(1)
                    addr = int(m.group(2), 16)
                    if addr not in symbols:
                        symbols[addr] = name

    # Also check linker_stubs.c for symbol definitions
    linker_stubs = os.path.join(SRC_DIR, "linker_stubs.c")
    if os.path.exists(linker_stubs):
        with open(linker_stubs, "r") as f:
            for line in f:
                m = re.match(r'\w+\s+((?:FUN|DAT|sym|PTR)_([0-9A-Fa-f]+))', line)
                if m:
                    name = m.group(1)
                    addr = int(m.group(2), 16)
                    if addr not in symbols:
                        symbols[addr] = name

    return symbols


def parse_byte_values(line):
    """Parse a .byte line, return list of byte values or None."""
    line = line.strip()
    m = re.match(r'\.byte\s+(.*)', line)
    if not m:
        return None
    parts = m.group(1).split(',')
    try:
        return [int(p.strip(), 0) for p in parts]
    except ValueError:
        return None


def classify_regions(lines):
    """
    Classify each line into regions:
      'code'      - instruction bytes (before first pool/data indicator)
      'pool'      - constant pool region (interleaved .4byte and .byte)
      'data'      - labeled data block (DAT_/sym_ global labels)
      'other'     - labels, directives, etc.

    Strategy:
    - Lines before the first .4byte or labeled data section are 'code'
    - After seeing a .4byte or label, we're in pool/data territory
    - A .global DAT_/sym_ label starts a 'data' region
    - .4byte lines are 'pool'
    - .byte lines between .4byte lines (in pool region) are 'pool'
    - .byte lines after a DAT_/sym_ label are 'data'
    - If we see code-like patterns (long runs of .byte with no .4byte nearby),
      we may be back in code (for multi-part functions with inline pools)
    """
    n = len(lines)
    regions = ['other'] * n

    # First pass: identify key markers
    first_pool_or_data = None
    for i, line in enumerate(lines):
        stripped = line.strip()
        if re.match(r'\.4byte\s+', stripped):
            if first_pool_or_data is None:
                first_pool_or_data = i
            regions[i] = 'pool_4byte'
        elif re.match(r'\.global\s+(DAT_|sym_)', stripped):
            if first_pool_or_data is None:
                first_pool_or_data = i
            regions[i] = 'data_label'
        elif re.match(r'^(DAT_|sym_)\w+:', stripped):
            regions[i] = 'data_label'
        elif re.match(r'\.global\s+FUN_', stripped):
            regions[i] = 'fun_label'
        elif re.match(r'^FUN_\w+:', stripped):
            regions[i] = 'fun_label'
        elif parse_byte_values(stripped) is not None:
            regions[i] = 'bytes'

    if first_pool_or_data is None:
        # No pool at all - everything is code
        for i in range(n):
            if regions[i] == 'bytes':
                regions[i] = 'code'
        return regions

    # Second pass: classify byte regions
    # Before first pool/data marker: code
    # After: need to determine if pool or data
    in_data_block = False

    for i in range(n):
        stripped = lines[i].strip()

        if regions[i] == 'data_label':
            in_data_block = True
            regions[i] = 'data'
            continue

        if regions[i] == 'fun_label':
            in_data_block = False
            regions[i] = 'other'
            continue

        if regions[i] == 'pool_4byte':
            in_data_block = False
            regions[i] = 'pool'
            continue

        if regions[i] == 'bytes':
            if i < first_pool_or_data:
                regions[i] = 'code'
            elif in_data_block:
                regions[i] = 'data'
            else:
                # After pool region started, .byte lines near .4byte are pool entries
                # Check if there's a .4byte within +/- 10 lines
                nearby_4byte = False
                for j in range(max(0, i-10), min(n, i+10)):
                    if lines[j].strip().startswith('.4byte'):
                        nearby_4byte = True
                        break
                if nearby_4byte:
                    regions[i] = 'pool'
                else:
                    # Could be back in code after an inline pool
                    # Heuristic: if there's a long run of .byte (>20 lines) with no
                    # .4byte, it's probably code
                    run_start = i
                    while run_start > 0 and regions[run_start-1] in ('bytes', 'code'):
                        run_start -= 1
                    run_end = i
                    while run_end < n-1 and (regions[run_end+1] == 'bytes' or parse_byte_values(lines[run_end+1].strip()) is not None):
                        run_end += 1
                    run_len = run_end - run_start + 1
                    if run_len > 20:
                        regions[i] = 'code'
                    else:
                        regions[i] = 'pool'

    return regions


def scan_file(fpath, known_symbols):
    """Scan a single .s file for unsymbolized 0x06xxxxxx pool entries."""
    pool_results = []
    data_results = []
    code_results = []
    symbolized_count = 0

    with open(fpath, "r") as f:
        lines = f.readlines()

    # Count .4byte symbolized entries
    for line in lines:
        stripped = line.strip()
        if re.match(r'\.4byte\s+(FUN|DAT|sym|PTR)_', stripped):
            symbolized_count += 1

    # Classify regions
    regions = classify_regions(lines)

    # Now scan for 0x06xxxxxx in .byte sequences, tracking which region they're in
    i = 0
    while i < len(lines):
        bvals = parse_byte_values(lines[i].strip())
        if bvals is None:
            i += 1
            continue

        # Collect consecutive .byte lines with their region
        byte_stream = []  # list of (line_number, byte_value, region)
        while i < len(lines):
            bvals = parse_byte_values(lines[i].strip())
            if bvals is None:
                break
            reg = regions[i]
            for bv in bvals:
                byte_stream.append((i + 1, bv, reg))
            i += 1

        # Scan for 4-byte groups at 2-byte aligned offsets
        for j in range(0, len(byte_stream) - 3, 2):
            b0 = byte_stream[j][1]
            b1 = byte_stream[j+1][1]
            b2 = byte_stream[j+2][1]
            b3 = byte_stream[j+3][1]

            val = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3

            if 0x06000000 <= val <= 0x060FFFFF:
                line_start = byte_stream[j][0]
                line_end = byte_stream[j+3][0]
                # Use the region of the first byte
                region = byte_stream[j][2]
                sym_name = known_symbols.get(val)

                entry = {
                    'line_start': line_start,
                    'line_end': line_end,
                    'addr': val,
                    'symbol': sym_name,
                    'bytes': [b0, b1, b2, b3],
                    'region': region,
                }

                if region == 'pool':
                    pool_results.append(entry)
                elif region == 'data':
                    data_results.append(entry)
                else:
                    code_results.append(entry)

    return pool_results, data_results, code_results, symbolized_count


def main():
    print("=" * 80)
    print("UNSYMBOLIZED CONSTANT POOL ANALYSIS (v2 - with region classification)")
    print("Scanning .s files in reimpl/src/ for raw 0x06xxxxxx .byte sequences")
    print("=" * 80)
    print()

    known_symbols = load_known_symbols()
    print(f"Loaded {len(known_symbols)} known symbols")
    print()

    all_pool = []
    all_data = []
    all_code = []
    total_symbolized = 0
    files_with_pool_unsym = set()
    file_count = 0

    s_files = sorted([f for f in os.listdir(SRC_DIR) if f.endswith(".s")])

    for fname in s_files:
        fpath = os.path.join(SRC_DIR, fname)
        pool, data, code, sym_count = scan_file(fpath, known_symbols)
        file_count += 1
        total_symbolized += sym_count

        if pool:
            files_with_pool_unsym.add(fname)
            for r in pool:
                all_pool.append((fname, r))
        for r in data:
            all_data.append((fname, r))
        for r in code:
            all_code.append((fname, r))

    # =========================================================================
    # POOL ENTRIES - the main focus
    # =========================================================================
    print("=" * 80)
    print("CONSTANT POOL: Unsymbolized 0x06xxxxxx entries (ACTIONABLE)")
    print("These are .byte sequences in the constant pool region that should")
    print("likely be .4byte SYMBOL directives.")
    print("=" * 80)

    if all_pool:
        current_file = None
        for fname, r in all_pool:
            if fname != current_file:
                current_file = fname
                print(f"\n  {fname}:")

            addr_str = f"0x{r['addr']:08X}"
            byte_str = ", ".join(f"0x{b:02X}" for b in r['bytes'])
            lines_str = f"L{r['line_start']}-L{r['line_end']}"

            if r['symbol']:
                status = f"-> {r['symbol']} (KNOWN)"
            else:
                status = "-> NO SYMBOL"

            print(f"    {lines_str:14s}  {addr_str}  ({byte_str})  {status}")
    else:
        print("\n  (none found)")

    # =========================================================================
    # DATA ENTRIES - for reference
    # =========================================================================
    print()
    print("=" * 80)
    print("LABELED DATA BLOCKS: 0x06xxxxxx values in DAT_/sym_ regions")
    print("These are inside labeled data structures - likely intentional data values")
    print("that happen to look like WRAM-H addresses. May or may not be pointers.")
    print("=" * 80)

    if all_data:
        current_file = None
        for fname, r in all_data:
            if fname != current_file:
                current_file = fname
                print(f"\n  {fname}:")

            addr_str = f"0x{r['addr']:08X}"
            lines_str = f"L{r['line_start']}-L{r['line_end']}"

            if r['symbol']:
                status = f"-> {r['symbol']} (KNOWN)"
            else:
                status = "-> NO SYMBOL"

            print(f"    {lines_str:14s}  {addr_str}  {status}")
    else:
        print("\n  (none found)")

    # =========================================================================
    # CODE ENTRIES - false positives
    # =========================================================================
    print()
    print("=" * 80)
    print(f"INSTRUCTION CODE: 0x06xxxxxx byte patterns in code region (FALSE POSITIVES)")
    print("These are SH-2 instruction bytes, NOT pool entries.")
    print("=" * 80)

    if all_code:
        # Just summarize
        by_file = defaultdict(int)
        by_addr = defaultdict(int)
        for fname, r in all_code:
            by_file[fname] += 1
            by_addr[r['addr']] += 1

        print(f"\n  Total false positives in code: {len(all_code)}")
        print(f"  Files affected: {len(by_file)}")
        print(f"\n  Top recurring instruction patterns:")
        for addr, count in sorted(by_addr.items(), key=lambda x: -x[1])[:10]:
            print(f"    0x{addr:08X}  ({count} occurrences)")
    else:
        print("\n  (none)")

    # =========================================================================
    # SUMMARY
    # =========================================================================
    print()
    print("=" * 80)
    print("OVERALL SUMMARY")
    print("=" * 80)
    print(f"  Total .s files scanned:                {file_count}")
    print(f"  Total .4byte symbolized pool entries:   {total_symbolized}")
    print()
    print(f"  POOL region unsymbolized 0x06xxxxxx:    {len(all_pool)}")
    pool_with_sym = sum(1 for _, r in all_pool if r['symbol'])
    pool_without = sum(1 for _, r in all_pool if not r['symbol'])
    print(f"    - with known symbol (easy fix):       {pool_with_sym}")
    print(f"    - no known symbol (needs new sym):    {pool_without}")
    print(f"  Files with pool unsymbolized entries:   {len(files_with_pool_unsym)}")
    print()
    print(f"  DATA region 0x06xxxxxx values:          {len(all_data)}")
    print(f"    (intentional data, not pool entries)")
    print()
    print(f"  CODE region false positives:            {len(all_code)}")
    print(f"    (instruction bytes, not addresses)")
    print()

    # Symbolization rate
    total_pool = total_symbolized + len(all_pool)
    if total_pool > 0:
        rate = total_symbolized / total_pool * 100
        print(f"  Pool symbolization rate:  {total_symbolized}/{total_pool} ({rate:.1f}%)")
    print()

    # List actionable pool entries
    if all_pool:
        print("-" * 80)
        print("ACTIONABLE: Pool entries that need .4byte conversion")
        print("-" * 80)
        seen = set()
        for fname, r in all_pool:
            key = (fname, r['line_start'], r['addr'])
            if key in seen:
                continue
            seen.add(key)
            sym = r['symbol'] or "(needs new sym_)"
            print(f"  {fname:30s}  L{r['line_start']:5d}  0x{r['addr']:08X}  {sym}")
        print()


if __name__ == "__main__":
    main()
