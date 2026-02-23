#!/usr/bin/env python3
"""Consolidate retail .s files for a translation unit into one file.

Usage: python tools/consolidate_tu.py
Output: reimpl/retail/game_update_loop.s
"""

import os
import re

RETAIL_DIR = os.path.join(os.path.dirname(__file__), '..', 'reimpl', 'retail')
OUTPUT = os.path.join(RETAIL_DIR, 'game_update_loop.s')

# TU range (inclusive start, exclusive end)
TU_START = 0x06033BC8
TU_END   = 0x06034E20

HEADER = """\
/* game_update_loop — Per-frame car update (display, physics, AI)
 *
 * Translation unit: 0x06033BC8 - 0x06034E20 (~4,700 bytes, ~100 functions)
 * Reconstructed from cross-section pool sharing analysis (2026-02-23).
 *
 * Original Sega source: one large C file covering display selector thunks,
 * score/time rendering, physics integration (position, velocity, perspective),
 * AI steering/rotation/braking/throttle, waypoint following, collision,
 * checkpoint/lap tracking, and recovery handling.
 *
 * Each function retains its own .section directive for retail byte-identical
 * builds. The free-build src/ file uses a single section for all functions.
 */

"""

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
    # Collect all .s files and their lowest section address
    output_name = os.path.basename(OUTPUT)
    files = []
    for name in os.listdir(RETAIL_DIR):
        if not name.endswith('.s') or name == output_name:
            continue
        path = os.path.join(RETAIL_DIR, name)
        addrs = get_section_addresses(path)
        if not addrs:
            continue
        lowest = min(addrs)
        if TU_START <= lowest < TU_END:
            files.append((lowest, name, path))

    files.sort(key=lambda x: x[0])

    print(f"Found {len(files)} files in TU range")
    print(f"Address range: 0x{files[0][0]:08X} - 0x{files[-1][0]:08X}")

    # Write consolidated file
    with open(OUTPUT, 'w', newline='\n') as out:
        out.write(HEADER)
        for i, (addr, name, path) in enumerate(files):
            with open(path, 'r') as f:
                content = f.read()
            # Strip trailing whitespace/newlines, normalize
            content = content.rstrip() + '\n'
            out.write(content)
            out.write('\n')

    total_sections = 0
    with open(OUTPUT, 'r') as f:
        for line in f:
            if '.section .text.FUN_' in line:
                total_sections += 1

    print(f"Written to: {OUTPUT}")
    print(f"Total sections: {total_sections}")
    print(f"\nFiles included:")
    for addr, name, _ in files:
        print(f"  0x{addr:08X} {name}")

if __name__ == '__main__':
    main()
