#!/usr/bin/env python3
"""
Scan reimpl .s files for unsymbolized pool entries that contain code addresses.

A code address is in the range 0x06003000-0x0605FFFF.
Pool entries that reference code addresses MUST be symbolized as .4byte FUN_XXXXXXXX
so they shift correctly in the free-layout build.

Strategy:
  1. Find consecutive .byte pairs that form a 32-bit value in code range
  2. Filter out entries in DAT_ labeled data sections (these are structured data, not pool)
  3. Filter out entries in data tables (repeating patterns with small values mixed in)
  4. Check if the address corresponds to a known function/symbol
  5. Check if the entry is at a 4-byte aligned position (required for pool constants)
  6. Check if the entry is after an rts/bra/jmp (typical pool placement)

Output: all candidates with classification (LIKELY POOL, DATA TABLE, UNKNOWN)
"""

import os
import sys
import re
import glob

SRC_DIR = r"d:\Projects\SaturnReverseTest\reimpl\src"

# Code range
CODE_START = 0x06003000
CODE_END   = 0x0605FFFF

# Load known symbols from .s file names (FUN_XXXXXXXX.s)
def load_known_symbols():
    """Load known function entry points from .s file names."""
    symbols = set()
    pattern = os.path.join(SRC_DIR, "FUN_*.s")
    for f in glob.glob(pattern):
        base = os.path.basename(f)
        m = re.match(r'FUN_([0-9A-Fa-f]{8})\.s', base)
        if m:
            symbols.add(int(m.group(1), 16))
    return symbols

def parse_byte_line(line):
    """Parse a .byte line and return the two byte values, or None."""
    line = line.strip()
    m = re.match(r'\.byte\s+0x([0-9A-Fa-f]{2})\s*,\s*0x([0-9A-Fa-f]{2})', line)
    if m:
        return int(m.group(1), 16), int(m.group(2), 16)
    return None

def is_label(line):
    """Check if line is a label definition."""
    return bool(re.match(r'\s*(loc|DAT|FUN|sym)_[0-9A-Fa-f]+:', line.strip()))

def is_dat_label(line):
    """Check if line is a DAT_ label (data section)."""
    return bool(re.match(r'\s*DAT_[0-9A-Fa-f]+:', line.strip()))

def get_label_addr(line):
    """Extract address from any label."""
    m = re.match(r'\s*(?:loc|DAT|FUN|sym)_([0-9A-Fa-f]{8}):', line.strip())
    if m:
        return int(m.group(1), 16)
    return None

def is_4byte_line(line):
    """Check if line is a .4byte directive."""
    return bool(re.match(r'\s*\.4byte\s+', line.strip()))

def is_rts_nop(b):
    """Check if byte pair is rts (0x000B) or nop (0x0009)."""
    if b is None:
        return False
    return (b[0] == 0x00 and b[1] == 0x0B) or (b[0] == 0x00 and b[1] == 0x09)

def scan_file(filepath, known_symbols):
    """Scan a single .s file for unsymbolized code address pool entries."""
    findings = []

    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    # First pass: identify data sections (DAT_ labels) and their extent
    in_dat_section = False
    dat_lines = set()
    for i, line in enumerate(lines):
        if is_dat_label(line):
            in_dat_section = True
        elif re.match(r'\s*\.(global|section|type)', line.strip()):
            # .global preceding a DAT_ label is also data context
            if i + 1 < len(lines) and is_dat_label(lines[i + 1]):
                dat_lines.add(i)
                continue
            # Other directives may end the data section
            if not re.match(r'\s*\.global\s+DAT_', line.strip()):
                in_dat_section = False
        elif is_label(line) and not is_dat_label(line):
            # A non-DAT label might end or might not end the section
            pass

        if in_dat_section:
            dat_lines.add(i)

    # Track current label address
    current_label_addr = None
    current_label_type = None  # 'FUN', 'DAT', 'loc', 'sym'

    for i in range(len(lines) - 1):
        # Track label
        la = get_label_addr(lines[i])
        if la is not None:
            current_label_addr = la
            if 'DAT_' in lines[i]:
                current_label_type = 'DAT'
            elif 'FUN_' in lines[i]:
                current_label_type = 'FUN'
            elif 'loc_' in lines[i]:
                current_label_type = 'loc'
            elif 'sym_' in lines[i]:
                current_label_type = 'sym'

        # Parse current and next line as .byte pairs
        b1 = parse_byte_line(lines[i])
        b2 = parse_byte_line(lines[i + 1])

        if b1 is None or b2 is None:
            continue

        # Form big-endian 32-bit value
        value = (b1[0] << 24) | (b1[1] << 16) | (b2[0] << 8) | b2[1]

        if not (CODE_START <= value <= CODE_END):
            continue

        # Determine classification
        classification = "UNKNOWN"
        reasons = []

        # Check alignment: pool constants must be at 4-byte aligned addresses
        # Each .byte line = 2 bytes. Line position relative to label gives offset.
        is_aligned = (value & 1) == 0
        if not is_aligned:
            reasons.append("odd address (not even-aligned)")

        # Check if in a DAT_ section
        in_data = i in dat_lines or (i + 1) in dat_lines
        if in_data:
            classification = "DATA_SECTION"
            reasons.append("inside DAT_ labeled section")

        # Check if it matches a known function entry point
        is_known_func = value in known_symbols
        if is_known_func:
            reasons.append(f"MATCHES known function FUN_{value:08X}")

        # Check if preceded by rts/nop (typical pool placement)
        # Look back up to 4 lines for rts
        preceded_by_rts = False
        for j in range(max(0, i-4), i):
            bj = parse_byte_line(lines[j])
            if is_rts_nop(bj):
                preceded_by_rts = True
                break
        if preceded_by_rts:
            reasons.append("preceded by rts/nop (pool-like)")

        # Check if surrounded by other data-like bytes (small values, incrementing patterns)
        # This is a heuristic for data tables
        nearby_bytes = []
        for j in range(max(0, i-3), min(len(lines), i+5)):
            bj = parse_byte_line(lines[j])
            if bj:
                nearby_bytes.extend(bj)
        if nearby_bytes:
            # Data tables tend to have mostly small values
            small_count = sum(1 for b in nearby_bytes if b < 0x10)
            if small_count > len(nearby_bytes) * 0.6:
                if classification == "UNKNOWN":
                    classification = "DATA_TABLE"
                reasons.append(f"surrounded by small values ({small_count}/{len(nearby_bytes)} < 0x10)")

        # Check if 4-byte aligned relative to current label
        if current_label_addr is not None:
            # Count bytes from label to this line
            byte_offset = 0
            for j in range(i - 1, -1, -1):
                la2 = get_label_addr(lines[j])
                if la2 is not None:
                    break
                bj = parse_byte_line(lines[j])
                if bj:
                    byte_offset += 2
            addr_of_entry = current_label_addr + byte_offset
            if addr_of_entry % 4 == 0:
                reasons.append(f"4-byte aligned at ~{addr_of_entry:#010x}")
            else:
                reasons.append(f"NOT 4-byte aligned at ~{addr_of_entry:#010x}")
                if classification == "UNKNOWN":
                    classification = "MISALIGNED"

        # Check if followed by .4byte entries (mixed data/pool section)
        followed_by_4byte = False
        for j in range(i + 2, min(len(lines), i + 6)):
            if is_4byte_line(lines[j]):
                followed_by_4byte = True
                break
        if followed_by_4byte:
            reasons.append("near .4byte entries (mixed data section)")

        # Final classification
        if classification == "UNKNOWN":
            if is_known_func and is_aligned:
                classification = "LIKELY_POOL"
            elif preceded_by_rts and is_aligned:
                classification = "POSSIBLE_POOL"
            else:
                classification = "LIKELY_DATA"

        findings.append({
            'file': os.path.basename(filepath),
            'filepath': filepath,
            'line': i + 1,
            'value': value,
            'classification': classification,
            'reasons': reasons,
            'is_known_func': is_known_func,
            'current_label': f"{current_label_type}_{current_label_addr:08X}" if current_label_addr else "???",
            'context_before': [l.rstrip() for l in lines[max(0,i-3):i]],
            'line1': lines[i].rstrip(),
            'line2': lines[i+1].rstrip(),
            'context_after': [l.rstrip() for l in lines[i+2:min(len(lines),i+5)]],
        })

    return findings

def main():
    known_symbols = load_known_symbols()
    print(f"Loaded {len(known_symbols)} known function symbols")

    pattern = os.path.join(SRC_DIR, "*.s")
    s_files = sorted(glob.glob(pattern))
    print(f"Scanning {len(s_files)} .s files in {SRC_DIR}")
    print(f"Looking for unsymbolized code addresses in range {CODE_START:#010x}-{CODE_END:#010x}")
    print("=" * 80)

    all_findings = []
    for filepath in s_files:
        findings = scan_file(filepath, known_symbols)
        all_findings.extend(findings)

    if not all_findings:
        print("\nNo unsymbolized code addresses found! All clear.")
        return

    # Separate by classification
    likely_pool = [f for f in all_findings if f['classification'] in ('LIKELY_POOL', 'POSSIBLE_POOL')]
    data_section = [f for f in all_findings if f['classification'] == 'DATA_SECTION']
    data_table = [f for f in all_findings if f['classification'] == 'DATA_TABLE']
    misaligned = [f for f in all_findings if f['classification'] == 'MISALIGNED']
    likely_data = [f for f in all_findings if f['classification'] == 'LIKELY_DATA']

    def print_findings(findings, header):
        if not findings:
            return
        print(f"\n{'='*80}")
        print(f" {header} ({len(findings)} entries)")
        print(f"{'='*80}\n")
        for f in findings:
            print(f"  FILE: {f['file']}  (line {f['line']})")
            print(f"  Value: {f['value']:#010x}  [{f['classification']}]")
            print(f"  Label context: {f['current_label']}")
            print(f"  Known function: {'YES' if f['is_known_func'] else 'no'}")
            print(f"  Reasons: {'; '.join(f['reasons'])}")
            for cl in f['context_before']:
                print(f"      {cl}")
            print(f"  >>> {f['line1']}")
            print(f"  >>> {f['line2']}")
            for cl in f['context_after']:
                print(f"      {cl}")
            print()

    # Print LIKELY_POOL first (these need action)
    print_findings(likely_pool, "LIKELY POOL CONSTANTS (NEED SYMBOLIZATION)")

    # Then POSSIBLE_POOL
    # print_findings(possible_pool, "POSSIBLE POOL CONSTANTS (REVIEW)")

    # Then data sections (informational)
    print_findings(data_section, "DATA SECTION ENTRIES (safe - structured data)")
    print_findings(data_table, "DATA TABLE ENTRIES (safe - small-value tables)")
    print_findings(misaligned, "MISALIGNED ENTRIES (safe - not valid pool constants)")
    print_findings(likely_data, "LIKELY DATA ENTRIES (safe - context suggests data)")

    # Summary
    print("\n" + "=" * 80)
    print("SUMMARY:")
    print(f"  LIKELY POOL (need fix):   {len(likely_pool)}")
    print(f"  DATA SECTION (safe):      {len(data_section)}")
    print(f"  DATA TABLE (safe):        {len(data_table)}")
    print(f"  MISALIGNED (safe):        {len(misaligned)}")
    print(f"  LIKELY DATA (safe):       {len(likely_data)}")
    print(f"  TOTAL candidates:         {len(all_findings)}")

if __name__ == '__main__':
    main()
