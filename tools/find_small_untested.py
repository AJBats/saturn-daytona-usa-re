#!/usr/bin/env python3
"""Find small untested functions (2-5 insns) that might be easy to pass"""
import os
import re

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
GHIDRA = "/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt"

# Get list of already-tested functions
tested = set()
for f in os.listdir(SRCDIR):
    if f.endswith('.c'):
        tested.add(f[:-2])

# Get all expected files
untested_small = []
for f in sorted(os.listdir(TDIR)):
    if not f.endswith('.expected'):
        continue
    base = f[:-9]
    if base in tested:
        continue

    expfile = os.path.join(TDIR, f)
    with open(expfile) as fh:
        opcodes = [l.strip() for l in fh.read().replace('\r', '').split('\n') if l.strip()]

    if len(opcodes) < 2 or len(opcodes) > 5:
        continue

    # Check for problematic patterns
    ops_str = ' '.join(opcodes)
    has_jsr = 'jsr' in ops_str
    has_jmp = 'jmp' in ops_str
    has_bsr = 'bsr' in ops_str
    has_bra = 'bra' in ops_str

    untested_small.append({
        'name': base,
        'count': len(opcodes),
        'opcodes': opcodes,
        'has_call': has_jsr or has_bsr,
        'has_jump': has_jmp or has_bra,
    })

print(f"Untested functions with 2-5 expected insns: {len(untested_small)}")
print()

# Load Ghidra data
ghidra_funcs = {}
if os.path.exists(GHIDRA):
    with open(GHIDRA) as f:
        content = f.read().replace('\r', '')
    lines = content.split('\n')
    i = 0
    while i < len(lines):
        if lines[i].startswith('FUNC '):
            parts = lines[i].split()
            fname = parts[1]
            # Collect decomp until next FUNC
            j = i + 1
            decomp_lines = []
            while j < len(lines) and not lines[j].startswith('FUNC '):
                decomp_lines.append(lines[j])
                j += 1
            ghidra_funcs[fname.lower()] = '\n'.join(decomp_lines)
            i = j
        else:
            i += 1

print("Sorted by instruction count:")
for item in sorted(untested_small, key=lambda x: (x['count'], x['name'])):
    name = item['name']
    ops = item['opcodes']
    call_str = " [CALL]" if item['has_call'] else ""
    jump_str = " [JUMP]" if item['has_jump'] else ""

    # Check Ghidra
    ghidra_key = name.lower().replace('fun_', 'FUN_').lower()
    # Try both cases
    has_ghidra = ghidra_key in ghidra_funcs or name.lower() in ghidra_funcs
    ghidra_str = " [GHIDRA]" if has_ghidra else ""

    print(f"  {name} ({len(ops)} insns): {' '.join(ops)}{call_str}{jump_str}{ghidra_str}")

    # Show Ghidra decomp if available and short
    for key in [ghidra_key, name.lower()]:
        if key in ghidra_funcs:
            decomp = ghidra_funcs[key].strip()
            if len(decomp) < 300:
                for dl in decomp.split('\n')[:8]:
                    print(f"       | {dl}")
            break
