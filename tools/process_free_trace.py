#!/usr/bin/env python3
"""process_free_trace.py — Remove +4 address offsets from a free build trace.

Reads a unified trace and subtracts 4 from any address >= 0x060030FC
in M/S (SH-2) event lines. Everything else (cycles, IRQ/CMD/BUF/DRV events)
is left untouched.

Usage:
    python tools/process_free_trace.py <input> <output>
"""

import sys

CODE_SHIFT_START = 0x060030FC
CODE_SHIFT_END   = 0x06080000   # end of high work RAM (512 KB)
SHIFT = 4


def should_shift(addr):
    """Only shift addresses in the relocated code region of high work RAM."""
    return CODE_SHIFT_START <= addr < CODE_SHIFT_END


def process_line(line):
    stripped = line.rstrip('\n\r')
    if not stripped or stripped.startswith('#'):
        return line

    parts = stripped.split()
    if len(parts) < 4:
        return line

    event_type = parts[1]
    if event_type not in ('M', 'S'):
        return line

    # Format: <cycle> M/S <addr1> <addr2>
    try:
        addr1 = int(parts[2], 16)
        addr2 = int(parts[3], 16)
    except ValueError:
        return line

    new_addr1 = addr1 - SHIFT if should_shift(addr1) else addr1
    new_addr2 = addr2 - SHIFT if should_shift(addr2) else addr2

    # Only rewrite if something actually changed
    if new_addr1 == addr1 and new_addr2 == addr2:
        return line

    return f"{parts[0]} {parts[1]} {new_addr1:08X} {new_addr2:08X}\n"


def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input_trace> <output_trace>")
        sys.exit(1)

    input_path = sys.argv[1]
    output_path = sys.argv[2]

    count = 0
    modified = 0
    with open(input_path, 'r') as fin, open(output_path, 'w', newline='\n') as fout:
        for line in fin:
            processed = process_line(line)
            if processed != line:
                modified += 1
            fout.write(processed)
            count += 1
            if count % 1000000 == 0:
                print(f"  {count:,} lines processed, {modified:,} modified...")

    print(f"Done: {count:,} lines, {modified:,} addresses shifted by -{SHIFT}")


if __name__ == '__main__':
    main()
