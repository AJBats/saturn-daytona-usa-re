#!/usr/bin/env python3
"""Consolidate retail .s files for a translation unit into one file.

Usage:
    python tools/consolidate_tu.py <name> <start_addr> <end_addr> [--description DESC]

Example:
    python tools/consolidate_tu.py game_update_loop 0x06033BC8 0x06034E20 --description "Per-frame car update (display, physics, AI)"
    python tools/consolidate_tu.py secondary_input_handler 0x06034E20 0x06036144 --description "SMPC commands, secondary SH-2 main loop, input processing"

Output: reimpl/retail/<name>.s
"""

import argparse
import os
import re
import sys

RETAIL_DIR = os.path.join(os.path.dirname(__file__), '..', 'reimpl', 'retail')


def get_section_addresses(filepath):
    """Extract all FUN_ section addresses from a file."""
    addrs = []
    with open(filepath, 'r') as f:
        for line in f:
            m = re.search(r'\.section\s+\.text\.FUN_([0-9A-Fa-f]+)', line)
            if m:
                addrs.append(int(m.group(1), 16))
    return addrs


def main():
    parser = argparse.ArgumentParser(description='Consolidate retail .s files for a translation unit')
    parser.add_argument('name', help='TU name (e.g., game_update_loop)')
    parser.add_argument('start', help='Start address (inclusive, e.g., 0x06033BC8)')
    parser.add_argument('end', help='End address (exclusive, e.g., 0x06034E20)')
    parser.add_argument('--description', '-d', default='', help='One-line TU description')
    parser.add_argument('--dry-run', action='store_true', help='List files without writing')
    args = parser.parse_args()

    tu_start = int(args.start, 16)
    tu_end = int(args.end, 16)
    tu_name = args.name
    output = os.path.join(RETAIL_DIR, f'{tu_name}.s')

    # Collect all .s files whose lowest section address falls in the TU range
    # Skip files that are already consolidated TUs (multi-section files with a
    # different stem name that happens to overlap our range)
    output_name = os.path.basename(output)
    files = []
    skipped_consolidated = []
    for name in os.listdir(RETAIL_DIR):
        if not name.endswith('.s') or name == output_name:
            continue
        path = os.path.join(RETAIL_DIR, name)
        addrs = get_section_addresses(path)
        if not addrs:
            continue
        lowest = min(addrs)
        if tu_start <= lowest < tu_end:
            # Check if this file contains sections OUTSIDE our range too
            # (it's already a consolidated TU file we shouldn't absorb)
            outside = [a for a in addrs if a < tu_start or a >= tu_end]
            if outside:
                skipped_consolidated.append((lowest, name, path))
                continue
            files.append((lowest, name, path))

    files.sort(key=lambda x: x[0])

    if not files:
        print(f"ERROR: No files found in range 0x{tu_start:08X} - 0x{tu_end:08X}")
        sys.exit(1)

    size_bytes = tu_end - tu_start
    print(f"TU: {tu_name}")
    print(f"Range: 0x{tu_start:08X} - 0x{tu_end:08X} (~{size_bytes:,} bytes)")
    print(f"Found {len(files)} files")

    if skipped_consolidated:
        print(f"\nSkipped {len(skipped_consolidated)} already-consolidated files:")
        for addr, name, _ in skipped_consolidated:
            print(f"  0x{addr:08X} {name}")

    print(f"\nFiles to consolidate:")
    for addr, name, _ in files:
        print(f"  0x{addr:08X} {name}")

    if args.dry_run:
        print("\n(dry run — no files written)")
        return

    # Build header
    desc = f' -- {args.description}' if args.description else ''
    header = f"""\
/* {tu_name}{desc}
 *
 * Translation unit: 0x{tu_start:08X} - 0x{tu_end:08X} (~{size_bytes:,} bytes, {len(files)} functions)
 * Reconstructed from cross-section pool sharing analysis.
 *
 * Each function retains its own .section directive for retail byte-identical
 * builds. The free-build src/ file uses a single section for all functions.
 */

"""

    # Write consolidated file
    with open(output, 'w', newline='\n') as out:
        out.write(header)
        for i, (addr, name, path) in enumerate(files):
            with open(path, 'r') as f:
                content = f.read()
            content = content.rstrip() + '\n'
            out.write(content)
            out.write('\n')

    total_sections = 0
    with open(output, 'r') as f:
        for line in f:
            if '.section .text.FUN_' in line:
                total_sections += 1

    print(f"\nWritten to: {output}")
    print(f"Total sections: {total_sections}")


if __name__ == '__main__':
    main()
