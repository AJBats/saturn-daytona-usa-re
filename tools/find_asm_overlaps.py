#!/usr/bin/env python3
"""
Find C functions that overlap with existing ASM-imported functions.

Scans batch_*.c files for function definitions at addresses that fall
within the byte range of ASM-imported functions in asm_*.c files.
These overlapping C functions are bloated Ghidra duplicates that could
be replaced by adding sub-entry labels to the ASM imports.
"""

import re
import os
import sys
import glob


def parse_asm_functions(asm_dir):
    """Parse all asm_*.c files to find ASM-imported function ranges."""
    asm_funcs = {}  # {label: (start_addr, size_bytes, file)}

    for filepath in glob.glob(os.path.join(asm_dir, 'asm_*.c')):
        with open(filepath, 'r') as f:
            content = f.read()

        # Find all function blocks
        # Pattern: .global _FUN_XXXXXXXX ... .size _FUN_XXXXXXXX, .-_FUN_XXXXXXXX
        current_label = None
        word_count = 0

        for line in content.split('\n'):
            # Start of function
            m = re.search(r'"_?(FUN_[0-9A-Fa-f]+):\\n"', line)
            if m and '.global' not in line:
                current_label = m.group(1).upper()
                word_count = 0
                continue

            if current_label:
                if '".word ' in line:
                    word_count += 1
                elif '.size' in line and current_label in line.upper().replace('_FUN_', 'FUN_'):
                    # End of function
                    addr = int(current_label.replace('FUN_', ''), 16)
                    size = word_count * 2
                    asm_funcs[current_label] = (addr, size, os.path.basename(filepath))
                    current_label = None

    return asm_funcs


def parse_c_functions(c_dir):
    """Parse batch_*.c files to find C function definitions and their addresses."""
    c_funcs = []  # [(label, addr, file, line_num, line_count)]

    for filepath in sorted(glob.glob(os.path.join(c_dir, 'batch_*.c'))):
        with open(filepath, 'r') as f:
            lines = f.readlines()

        i = 0
        while i < len(lines):
            line = lines[i]
            # Match function definitions (not extern declarations)
            m = re.match(r'^(?:unsigned\s+int|int|void|long\s+long|short|char|unsigned\s+short)\s+(FUN_[0-9a-f]+)\s*\(', line)
            if m:
                func_name = m.group(1)
                addr = int(func_name.replace('FUN_', ''), 16)

                # Count lines until closing brace
                brace_depth = 0
                func_lines = 0
                for j in range(i, len(lines)):
                    for ch in lines[j]:
                        if ch == '{':
                            brace_depth += 1
                        elif ch == '}':
                            brace_depth -= 1
                    func_lines += 1
                    if brace_depth == 0 and j > i:
                        break

                c_funcs.append((func_name, addr, os.path.basename(filepath), i + 1, func_lines))
                i += func_lines
            else:
                i += 1

    return c_funcs


def find_overlaps(asm_funcs, c_funcs):
    """Find C functions whose addresses fall within ASM-imported functions."""
    overlaps = []

    for c_label, c_addr, c_file, c_line, c_lines in c_funcs:
        # Check if this C function's address is inside any ASM function
        for asm_label, (asm_addr, asm_size, asm_file) in asm_funcs.items():
            if asm_addr <= c_addr < asm_addr + asm_size:
                # Check if it's NOT the same function (exact match = both exist)
                if c_label.upper() != asm_label.upper():
                    offset = c_addr - asm_addr
                    overlaps.append({
                        'c_label': c_label,
                        'c_addr': c_addr,
                        'c_file': c_file,
                        'c_line': c_line,
                        'c_lines': c_lines,
                        'asm_label': asm_label,
                        'asm_addr': asm_addr,
                        'asm_size': asm_size,
                        'asm_file': asm_file,
                        'offset': offset,
                    })
                break

    return overlaps


def main():
    src_dir = sys.argv[1] if len(sys.argv) > 1 else 'reimpl/src'

    print("Scanning ASM imports...")
    asm_funcs = parse_asm_functions(src_dir)
    print("  Found %d ASM-imported functions" % len(asm_funcs))

    print("\nScanning C function definitions...")
    c_funcs = parse_c_functions(src_dir)
    print("  Found %d C function definitions" % len(c_funcs))

    print("\nFinding overlaps...")
    overlaps = find_overlaps(asm_funcs, c_funcs)

    if not overlaps:
        print("  No overlapping functions found")
        return

    # Group by C file
    by_file = {}
    for o in overlaps:
        by_file.setdefault(o['c_file'], []).append(o)

    total_lines = 0
    for c_file in sorted(by_file.keys()):
        file_overlaps = by_file[c_file]
        file_lines = sum(o['c_lines'] for o in file_overlaps)
        total_lines += file_lines
        print("\n  %s: %d overlapping functions (%d lines)" % (c_file, len(file_overlaps), file_lines))
        for o in sorted(file_overlaps, key=lambda x: x['c_addr']):
            print("    %s (0x%08X, %d lines) -> inside %s (offset 0x%X)" % (
                o['c_label'], o['c_addr'], o['c_lines'], o['asm_label'], o['offset']))

    print("\n  Total: %d overlapping functions, %d lines of removable C code" % (len(overlaps), total_lines))


if __name__ == '__main__':
    main()
