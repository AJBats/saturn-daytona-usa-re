#!/usr/bin/env python3
"""
find_stale_byte_refs.py - Scan .s files for stale absolute addresses in .byte sequences.

Finds sequences of 2 consecutive .byte lines whose combined 4 bytes
form a big-endian 32-bit value in the code range 0x06003000-0x06063690.

These are constant pool entries that should be .4byte SYMBOL references
but are instead raw bytes that won't relocate correctly when code is
rearranged or grows.

Each .byte line contains 2 bytes. Two consecutive .byte lines = 4 bytes = one pool entry.
SH-2 constant pool entries are always 4-byte aligned within the function.
"""

import os
import re
import glob
import sys

SRC_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "reimpl", "src")
CODE_RANGE_START = 0x06003000
CODE_RANGE_END   = 0x06063690

# Pattern to match .byte lines with exactly 2 hex bytes
BYTE_PATTERN = re.compile(r'^\s*\.byte\s+(0x[0-9A-Fa-f]{2})\s*,\s*(0x[0-9A-Fa-f]{2})\s*$')
FOURBYTE_PATTERN = re.compile(r'^\s*\.4byte\s+')
TWOBYTE_PATTERN = re.compile(r'^\s*\.(2byte|short)\s+')
ALIGN_PATTERN = re.compile(r'^\s*\.align\s+')


def parse_byte_line(line):
    """Parse a .byte line, return (byte1, byte2) as ints or None."""
    m = BYTE_PATTERN.match(line)
    if m:
        return (int(m.group(1), 16), int(m.group(2), 16))
    return None


def is_data_emitting(line):
    """Check if a line emits data bytes (not a label, directive, etc.)."""
    stripped = line.strip()
    if not stripped:
        return False
    if stripped.startswith('.byte'):
        return True
    if stripped.startswith('.4byte') or stripped.startswith('.long'):
        return True
    if stripped.startswith('.2byte') or stripped.startswith('.short'):
        return True
    return False


def scan_file(filepath):
    """Scan a single .s file for stale addresses. Returns list of findings."""
    findings = []

    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    # Strip line endings
    lines = [l.rstrip('\r\n') for l in lines]

    # Track byte offset from the start of the section to determine alignment.
    # We walk every line and accumulate the byte offset for data-emitting lines.
    byte_offset = 0
    byte_line_info = []  # list of (line_number_1indexed, byte_hi, byte_lo, byte_offset)

    for i, line in enumerate(lines):
        stripped = line.strip()

        # Check for .align directives (may insert padding)
        align_m = ALIGN_PATTERN.match(stripped)
        if align_m:
            # .align N means align to 2^N boundary (GAS default for some targets)
            # For simplicity, we'll just track the pattern and note it
            # In practice, these are rare in raw byte dumps
            pass

        parsed = parse_byte_line(line)
        if parsed is not None:
            byte_line_info.append((i + 1, parsed[0], parsed[1], byte_offset))
            byte_offset += 2
        elif FOURBYTE_PATTERN.match(stripped):
            byte_offset += 4
        elif TWOBYTE_PATTERN.match(stripped):
            byte_offset += 2
        # Labels (.global, FUN_xxx:, loc_xxx:, etc.) and directives don't emit bytes

    # Now check every pair of consecutive entries in byte_line_info.
    # Two consecutive .byte lines form a 4-byte pool entry if:
    #   1. Their byte offsets are consecutive (off2 == off1 + 2)
    #   2. The first one starts at a 4-byte-aligned offset (off1 % 4 == 0)
    for idx in range(len(byte_line_info) - 1):
        ln1, b1_hi, b1_lo, off1 = byte_line_info[idx]
        ln2, b2_hi, b2_lo, off2 = byte_line_info[idx + 1]

        # Must be consecutive in byte stream
        if off2 != off1 + 2:
            continue

        # Must be 4-byte aligned
        if off1 % 4 != 0:
            continue

        # Combine into big-endian 32-bit value
        value = (b1_hi << 24) | (b1_lo << 16) | (b2_hi << 8) | b2_lo

        if CODE_RANGE_START <= value <= CODE_RANGE_END:
            findings.append({
                'line1': ln1,
                'line2': ln2,
                'value': value,
                'offset': off1,
                'bytes': f"0x{b1_hi:02X}, 0x{b1_lo:02X}, 0x{b2_hi:02X}, 0x{b2_lo:02X}",
                'line1_text': lines[ln1 - 1].strip(),
                'line2_text': lines[ln2 - 1].strip(),
            })

    return findings


def main():
    s_files = sorted(glob.glob(os.path.join(SRC_DIR, "*.s")))

    if not s_files:
        print(f"ERROR: No .s files found in {SRC_DIR}")
        sys.exit(1)

    print(f"Scanning {len(s_files)} .s files in {SRC_DIR}")
    print(f"Code range: 0x{CODE_RANGE_START:08X} - 0x{CODE_RANGE_END:08X}")
    print("=" * 90)

    total_stale = 0
    files_with_stale = 0
    all_findings = []

    for filepath in s_files:
        filename = os.path.basename(filepath)
        findings = scan_file(filepath)

        if findings:
            files_with_stale += 1
            total_stale += len(findings)

            print(f"\n  {filename}: {len(findings)} stale address(es)")
            print("  " + "-" * 70)

            for f in findings:
                addr_str = f"0x{f['value']:08X}"
                print(f"    Lines {f['line1']:>4}-{f['line2']:<4}  offset=0x{f['offset']:04X}  "
                      f"value={addr_str}  [{f['bytes']}]")
                print(f"      L{f['line1']}: {f['line1_text']}")
                print(f"      L{f['line2']}: {f['line2_text']}")

            all_findings.extend([(os.path.basename(filepath), f) for f in findings])

    print("\n" + "=" * 90)
    print(f"SUMMARY: {total_stale} stale address(es) in {files_with_stale} file(s) "
          f"(out of {len(s_files)} .s files scanned)")

    if all_findings:
        print(f"\nAll stale addresses:")
        print(f"  {'File':<30} {'Lines':<14} {'Offset':<10} {'Stale Address':<14} {'Suggested Symbol'}")
        print("  " + "-" * 90)
        for filename, f in all_findings:
            # Suggest symbol: if address matches a known function, use FUN_ prefix
            addr = f['value']
            if addr % 2 == 0:
                sym = f"FUN_{addr:08X}"
            else:
                sym = f"loc_{addr:08X}"
            print(f"  {filename:<30} {f['line1']:>4}-{f['line2']:<8} 0x{f['offset']:04X}     "
                  f"0x{addr:08X}     {sym}")

        # Unique address values
        unique_addrs = sorted(set(f['value'] for _, f in all_findings))
        print(f"\n{len(unique_addrs)} unique stale address value(s):")
        for addr in unique_addrs:
            count = sum(1 for _, f in all_findings if f['value'] == addr)
            if addr % 2 == 0:
                sym = f"FUN_{addr:08X}"
            else:
                sym = f"loc_{addr:08X}"
            print(f"  0x{addr:08X}  (appears {count}x)  ->  .4byte {sym}")
    else:
        print("\nNo stale addresses found. All code-range references appear to be symbolized.")


if __name__ == '__main__':
    main()
