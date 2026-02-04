#!/usr/bin/env python3
"""Assess coverage gap between src/, tests/, and Ghidra decomps."""
import os
import re

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
GHIDRA = "/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt"

# 1. Current C sources
src_funcs = set()
for f in os.listdir(SRCDIR):
    if f.endswith('.c'):
        src_funcs.add(f[:-2])

# 2. Expected files
expected_funcs = set()
for f in os.listdir(TDIR):
    if f.endswith('.expected'):
        expected_funcs.add(f[:-9])

# 3. Ghidra decomps - extract function names and addresses
ghidra_funcs = {}  # name -> {addr, size, insns, type}
with open(GHIDRA) as fh:
    for line in fh:
        line = line.strip().replace('\r', '')
        m = re.match(r'^FUNC (\S+)\s+addr=(0x[0-9a-fA-F]+)\s+size=(\d+)\s+insns=(\d+)\s+type=(\S+)', line)
        if m:
            name = m.group(1)
            addr = m.group(2)
            size = int(m.group(3))
            insns = int(m.group(4))
            ftype = m.group(5)
            # Convert named functions to FUN_ format using address
            fun_name = f"FUN_{addr[2:].upper()}" if not name.startswith('FUN_') else name.upper()
            # Actually keep original name, map to FUN_ style
            ghidra_funcs[name] = {
                'addr': addr,
                'fun_name': f"FUN_{addr[2:].lower()}",
                'size': size,
                'insns': insns,
                'type': ftype,
            }

# Build FUN_ name set from Ghidra
ghidra_fun_names = set()
for name, info in ghidra_funcs.items():
    ghidra_fun_names.add(info['fun_name'])

print(f"=== COVERAGE ASSESSMENT ===")
print(f"C sources in src/:        {len(src_funcs)}")
print(f"Expected files in tests/: {len(expected_funcs)}")
print(f"Ghidra decomps:           {len(ghidra_funcs)}")
print()

# Overlaps
have_both = ghidra_fun_names & expected_funcs
have_all_three = have_both & src_funcs

have_ghidra_expected_no_src = have_both - src_funcs
have_ghidra_no_src = ghidra_fun_names - src_funcs
have_expected_no_src = expected_funcs - src_funcs
have_src_no_expected = src_funcs - expected_funcs

print(f"=== OVERLAPS ===")
print(f"Have ghidra + expected + src:     {len(have_all_three)}")
print(f"Have ghidra + expected, no src:   {len(have_ghidra_expected_no_src)}  <-- BEST CANDIDATES")
print(f"Have ghidra, no src:              {len(have_ghidra_no_src)}")
print(f"Have expected, no src:            {len(have_expected_no_src)}")
print(f"Have src, no expected:            {len(have_src_no_expected)}")
print()

# Size distribution of best candidates
print(f"=== BEST CANDIDATES BY SIZE (ghidra+expected, no src) ===")
size_dist = {}
for fun_name in sorted(have_ghidra_expected_no_src):
    # Find in ghidra_funcs by fun_name
    for name, info in ghidra_funcs.items():
        if info['fun_name'] == fun_name:
            insns = info['insns']
            bucket = insns // 10 * 10
            if bucket not in size_dist:
                size_dist[bucket] = []
            size_dist[bucket].append((fun_name, insns, info['type']))
            break

for bucket in sorted(size_dist.keys()):
    items = size_dist[bucket]
    leaf = sum(1 for _, _, t in items if t == 'LEAF')
    call = sum(1 for _, _, t in items if t == 'CALL')
    print(f"  {bucket:3d}-{bucket+9:3d} insns: {len(items):3d} functions ({leaf} LEAF, {call} CALL)")

print()

# Type distribution of ALL ghidra funcs without src
print(f"=== ALL GHIDRA FUNCS WITHOUT SRC ===")
types = {}
for name, info in ghidra_funcs.items():
    if info['fun_name'] not in src_funcs:
        t = info['type']
        if t not in types:
            types[t] = 0
        types[t] += 1
for t in sorted(types.keys(), key=lambda x: -types[x]):
    print(f"  {t}: {types[t]}")

print()

# Src files without expected (special cases)
if have_src_no_expected:
    print(f"=== SRC WITHOUT EXPECTED (need .expected generated) ===")
    for f in sorted(have_src_no_expected):
        print(f"  {f}")
