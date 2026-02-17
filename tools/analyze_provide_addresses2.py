#!/usr/bin/env python3
"""Deeper analysis of PROVIDE addresses -- breakdown of outside region."""

import re
import sys

BINARY_START = 0x06003000
BINARY_END   = 0x06063690

ld_path = sys.argv[1] if len(sys.argv) > 1 else "reimpl/sawyer_free.ld"

with open(ld_path, "r") as f:
    lines = f.readlines()

pattern = re.compile(r'PROVIDE\s*\(\s*(sym_|DAT_|loc_)(\S+)\s*=\s*0x([0-9A-Fa-f]+)\s*\)', re.IGNORECASE)

below = []       # < 0x06003000
inside = []      # 0x06003000 - 0x06063690
just_above = []  # 0x06063690 - 0x06070000 (right after binary, likely BSS/data)
ram_data = []    # 0x06070000+ (clearly RAM/data)

for lineno, line in enumerate(lines, 1):
    m = pattern.search(line)
    if m:
        prefix = m.group(1)
        name = prefix + m.group(2)
        addr = int(m.group(3), 16)
        entry = (addr, name, lineno)
        if addr < BINARY_START:
            below.append(entry)
        elif addr <= BINARY_END:
            inside.append(entry)
        elif addr < 0x06070000:
            just_above.append(entry)
        else:
            ram_data.append(entry)

total = len(below) + len(inside) + len(just_above) + len(ram_data)

print(f"Binary range: 0x{BINARY_START:08X} - 0x{BINARY_END:08X}")
print(f"Total PROVIDE lines: {total}")
print(f"")
print(f"  Below binary  (< 0x06003000):    {len(below):4d}  (BIOS/vector area)")
print(f"  INSIDE binary (0x06003000-690):   {len(inside):4d}  *** STALE IF BINARY SHIFTS ***")
print(f"  Just above    (0x06063690-70000): {len(just_above):4d}  (BSS/initialized data)")
print(f"  RAM/data      (0x06070000+):      {len(ram_data):4d}  (work RAM, safe)")

# Inside breakdown by sub-region
if inside:
    # How many are in code vs. literal pool?
    # Rough heuristic: addresses at odd offsets or between functions are likely literal pools
    dat_inside = [e for e in inside if e[1].startswith("DAT_")]
    sym_inside = [e for e in inside if e[1].startswith("sym_")]
    print(f"\n  INSIDE detail:")
    print(f"    DAT_ symbols: {len(dat_inside)} (inline literals/data embedded in code)")
    print(f"    sym_ symbols: {len(sym_inside)} (code references / misc)")

# Below breakdown
if below:
    dat_below = [e for e in below if e[1].startswith("DAT_")]
    sym_below = [e for e in below if e[1].startswith("sym_")]
    print(f"\n  BELOW detail:")
    print(f"    DAT_ symbols: {len(dat_below)}")
    print(f"    sym_ symbols: {len(sym_below)}")
    for addr, name, lineno in sorted(below):
        print(f"      0x{addr:08X}  {name}")

# Just above breakdown
if just_above:
    print(f"\n  JUST ABOVE detail ({len(just_above)} symbols from 0x06063690 to 0x06070000):")
    for addr, name, lineno in sorted(just_above)[:30]:
        print(f"      0x{addr:08X}  {name}")
    if len(just_above) > 30:
        print(f"      ... and {len(just_above)-30} more")

# Summary of the problem
print(f"\n{'='*70}")
print(f"SUMMARY: {len(inside)} PROVIDE addresses will become STALE")
print(f"if the binary layout changes (padding, reordering, etc.)")
print(f"  - {len(dat_inside)} are DAT_ (inline data/literal pools)")
print(f"  - {len(sym_inside)} are sym_ (code/misc references)")
print(f"{'='*70}")
