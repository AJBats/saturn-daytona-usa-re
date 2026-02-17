#!/usr/bin/env python3
"""Analyze PROVIDE addresses in linker script to find those inside binary range."""

import re
import sys

BINARY_START = 0x06003000
BINARY_END   = 0x06063690  # 394896 bytes from 0x06003000

ld_path = sys.argv[1] if len(sys.argv) > 1 else "reimpl/sawyer_free.ld"

with open(ld_path, "r") as f:
    lines = f.readlines()

# Match PROVIDE lines for sym_, DAT_, loc_ prefixes
pattern = re.compile(r'PROVIDE\s*\(\s*(sym_|DAT_|loc_)(\S+)\s*=\s*0x([0-9A-Fa-f]+)\s*\)', re.IGNORECASE)

inside = []
outside = []

for lineno, line in enumerate(lines, 1):
    m = pattern.search(line)
    if m:
        prefix = m.group(1)
        name = prefix + m.group(2)
        addr = int(m.group(3), 16)
        if BINARY_START <= addr <= BINARY_END:
            inside.append((addr, name, lineno))
        else:
            outside.append((addr, name, lineno))

inside.sort(key=lambda x: x[0])
outside.sort(key=lambda x: x[0])

print(f"Binary range: 0x{BINARY_START:08X} - 0x{BINARY_END:08X}")
print(f"Total PROVIDE lines matched: {len(inside) + len(outside)}")
print(f"  INSIDE binary range:  {len(inside)}")
print(f"  OUTSIDE binary range: {len(outside)}")

# Breakdown by prefix
for label, lst in [("INSIDE", inside), ("OUTSIDE", outside)]:
    dat_count = sum(1 for _, n, _ in lst if n.startswith("DAT_"))
    sym_count = sum(1 for _, n, _ in lst if n.startswith("sym_"))
    loc_count = sum(1 for _, n, _ in lst if n.startswith("loc_"))
    print(f"\n  {label} breakdown: DAT_={dat_count}, sym_={sym_count}, loc_={loc_count}")

print(f"\n{'='*70}")
print(f"ALL {len(inside)} PROVIDE addresses INSIDE binary range (0x{BINARY_START:08X}-0x{BINARY_END:08X}):")
print(f"{'='*70}")
for addr, name, lineno in inside:
    offset = addr - BINARY_START
    print(f"  0x{addr:08X}  (+0x{offset:05X})  {name}  (line {lineno})")

print(f"\n{'='*70}")
print(f"OUTSIDE binary range ({len(outside)} symbols):")
print(f"{'='*70}")
# Show first 30 and last 20 if many
if len(outside) <= 60:
    for addr, name, lineno in outside:
        print(f"  0x{addr:08X}  {name}  (line {lineno})")
else:
    print(f"  (showing first 30 and last 20 of {len(outside)})")
    for addr, name, lineno in outside[:30]:
        print(f"  0x{addr:08X}  {name}  (line {lineno})")
    print(f"  ...")
    for addr, name, lineno in outside[-20:]:
        print(f"  0x{addr:08X}  {name}  (line {lineno})")

# Address range summary for outside
if outside:
    print(f"\n  Outside range: 0x{outside[0][0]:08X} - 0x{outside[-1][0]:08X}")
