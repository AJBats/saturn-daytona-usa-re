#!/usr/bin/env python3
"""Map all game RAM addresses used in the reimpl code.

Scans all batch_*.c files for hardcoded addresses in the game RAM range
(0x0605xxxx - 0x060Axxxx) and generates a reference map showing how
each address is used.
"""

import os
import re
from collections import defaultdict

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REIMPL_DIR = os.path.join(PROJ, "reimpl", "src")

def main():
    # Scan all source files
    addr_refs = defaultdict(int)
    addr_types = defaultdict(set)  # addr -> set of access types (read/write/cast type)

    for fname in sorted(os.listdir(REIMPL_DIR)):
        if not fname.endswith('.c'):
            continue
        filepath = os.path.join(REIMPL_DIR, fname)
        with open(filepath, 'r', errors='replace') as f:
            content = f.read()

        # Find all game RAM addresses
        for m in re.finditer(r'0x(060[0-9A-Fa-f]{5})', content):
            addr = int(m.group(1), 16)
            if 0x06050000 <= addr <= 0x060AFFFF:
                addr_hex = f'0x{addr:08X}'
                addr_refs[addr_hex] += 1

                # Try to determine access type from context
                ctx_start = max(0, m.start() - 50)
                ctx = content[ctx_start:m.end() + 20]
                if '*(int *)' in ctx or '*(volatile int *)' in ctx:
                    addr_types[addr_hex].add('int')
                elif '*(short *)' in ctx or '*(volatile short *)' in ctx:
                    addr_types[addr_hex].add('short')
                elif '*(char *)' in ctx or '*(volatile char *)' in ctx:
                    addr_types[addr_hex].add('char')

    # Classify by memory region
    regions = {
        (0x06050000, 0x06060000): "System globals",
        (0x06060000, 0x06065000): "Frame/timing state",
        (0x06065000, 0x06070000): "VDP/rendering state",
        (0x06070000, 0x06078000): "Game objects (misc)",
        (0x06078000, 0x06080000): "Car data (40 slots @ 0x268)",
        (0x06080000, 0x06088000): "Object state A",
        (0x06088000, 0x06090000): "Object state B",
        (0x06090000, 0x06098000): "Rendering pipeline",
        (0x06098000, 0x060A0000): "Scene/track data",
        (0x060A0000, 0x060A8000): "CD/session state",
    }

    # Sort and output
    sorted_addrs = sorted(addr_refs.keys())

    print(f"# Game RAM Address Map")
    print(f"# Total unique addresses: {len(sorted_addrs)}")
    print(f"# Total references: {sum(addr_refs.values())}")
    print()

    for (start, end), name in sorted(regions.items()):
        region_addrs = [a for a in sorted_addrs if start <= int(a, 16) < end]
        if not region_addrs:
            continue
        total_refs = sum(addr_refs[a] for a in region_addrs)
        print(f"## {name} (0x{start:08X}-0x{end:08X}): {len(region_addrs)} addrs, {total_refs} refs")
        print()

        # Show top addresses by reference count
        top = sorted(region_addrs, key=lambda a: -addr_refs[a])[:20]
        print(f"| Address | Refs | Types | Likely Purpose |")
        print(f"|---------|------|-------|----------------|")
        for addr in top:
            types = ', '.join(sorted(addr_types.get(addr, {'?'})))
            purpose = ''
            addr_int = int(addr, 16)
            # Known addresses
            if addr_int == 0x06078900:
                purpose = 'Car struct base (40 slots)'
            elif addr_int == 0x0607E940:
                purpose = 'Current car ptr (player?)'
            elif addr_int == 0x0607E944:
                purpose = 'Current car ptr (target?)'
            elif 0x06078900 <= addr_int < 0x06078900 + 40 * 0x268:
                offset = addr_int - 0x06078900
                slot = offset // 0x268
                field = offset % 0x268
                purpose = f'Car[{slot}]+0x{field:X}'
            elif addr_int == 0x060635AC:
                purpose = 'VDP1 batch flag'
            elif addr_int == 0x060635C4:
                purpose = 'VBlank sync flag'
            print(f"| {addr} | {addr_refs[addr]:4d} | {types:5s} | {purpose} |")
        print()

if __name__ == "__main__":
    main()
