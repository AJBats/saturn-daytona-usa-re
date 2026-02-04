#!/usr/bin/env python3
"""Find untested functions that actually end with rts (proper standalone functions)"""
import os

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"

# Get list of already-tested functions
tested = set()
for f in os.listdir(SRCDIR):
    if f.endswith('.c'):
        tested.add(f[:-2])

# Find untested functions with rts at second-to-last position
# (rts is followed by delay slot instruction)
candidates = []
for f in sorted(os.listdir(TDIR)):
    if not f.endswith('.expected'):
        continue
    base = f[:-9]
    if base in tested:
        continue

    expfile = os.path.join(TDIR, f)
    with open(expfile) as fh:
        opcodes = [l.strip() for l in fh.read().replace('\r', '').split('\n') if l.strip()]

    if len(opcodes) < 2:
        continue

    # Check if second-to-last opcode is rts
    has_rts = False
    rts_pos = -1
    for i, op in enumerate(opcodes):
        if op == 'rts':
            has_rts = True
            rts_pos = i

    # Also check for bra (tail call) as last meaningful instruction
    has_tail = opcodes[-1] in ('bra',) or (len(opcodes) >= 2 and opcodes[-2] in ('bra',))

    if has_rts or has_tail:
        ending = "rts" if has_rts else "bra"
        candidates.append({
            'name': base,
            'count': len(opcodes),
            'opcodes': opcodes,
            'ending': ending,
            'rts_pos': rts_pos,
        })

# Sort by size
candidates.sort(key=lambda x: x['count'])

# Count by size
size_counts = {}
for c in candidates:
    sz = c['count']
    size_counts[sz] = size_counts.get(sz, 0) + 1

print(f"Untested functions ending with rts/bra: {len(candidates)}")
print(f"\nBy size:")
for sz in sorted(size_counts.keys()):
    if sz <= 15:
        print(f"  {sz} insns: {size_counts[sz]}")

print(f"\nSmall candidates (2-8 insns):")
for c in candidates:
    if c['count'] > 8:
        continue
    ops = ' '.join(c['opcodes'])
    has_call = 'bsr' in ops or 'jsr' in ops
    call_str = " [CALL]" if has_call else " [LEAF]"
    print(f"  {c['name']} ({c['count']} insns): {ops}{call_str}")
