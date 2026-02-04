#!/usr/bin/env python3
"""Analyze what makes passing functions pass - characteristics of successful matches"""
import subprocess
import os
import re

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"
TMPDIR = "/tmp/pass_analysis"

os.makedirs(TMPDIR, exist_ok=True)

results = []

for fname in sorted(os.listdir(SRCDIR)):
    if not fname.endswith('.c'):
        continue
    base = fname[:-2]
    expfile = os.path.join(TDIR, base + '.expected')
    if not os.path.exists(expfile):
        continue

    flags = "-O2 -m2 -mbsr"
    flagsfile = os.path.join(TDIR, base + '.flags')
    if os.path.exists(flagsfile):
        with open(flagsfile) as f:
            flags = f.read().strip().replace('\r', '')

    cfile = os.path.join(SRCDIR, fname)
    with open(cfile) as f:
        csrc = f.read().replace('\r', '')

    cleanc = os.path.join(TMPDIR, base + '_clean.c')
    with open(cleanc, 'w') as f:
        f.write(csrc)

    outfile = os.path.join(TMPDIR, base + '.s')
    cmd = f"{CC1} -quiet {flags} {cleanc} -o {outfile}"
    subprocess.run(cmd, shell=True, capture_output=True)

    with open(outfile) as f:
        asm = f.read().replace('\r', '')
    asm_lines = []
    for line in asm.split('\n'):
        if line.startswith('\t') and re.match(r'\t[a-z]', line):
            asm_lines.append(line.strip())
    ops = [l.split()[0] for l in asm_lines]

    with open(expfile) as f:
        expected = [l.strip() for l in f.read().replace('\r', '').split('\n') if l.strip()]

    diffs = 0
    for i in range(min(len(ops), len(expected))):
        if ops[i] != expected[i]:
            diffs += 1
    diffs += abs(len(ops) - len(expected))
    delta = len(ops) - len(expected)

    is_pass = (diffs == 0)

    # Analyze characteristics
    has_call = any('bsr' in l or 'jsr' in l for l in asm_lines)
    has_branch = any('bt' in l or 'bf' in l or 'bra' in l for l in asm_lines)
    has_loop = any('dt' in l for l in asm_lines)
    has_callee_save = any('mov.l' in l and '@-r15' in l and not 'pr' in l for l in asm_lines)
    uses_custom_flags = (flags != "-O2 -m2 -mbsr")
    insn_count = len(ops)

    # Check C source characteristics
    has_extern = 'extern' in csrc
    has_loop_c = 'while' in csrc or 'for' in csrc or 'do' in csrc
    has_if = 'if' in csrc
    has_volatile = 'volatile' in csrc
    num_stmts = csrc.count(';')

    results.append({
        'name': base, 'pass': is_pass, 'diffs': diffs, 'delta': delta,
        'insns': insn_count, 'has_call': has_call, 'has_branch': has_branch,
        'has_loop': has_loop, 'has_callee_save': has_callee_save,
        'custom_flags': uses_custom_flags, 'has_extern': has_extern,
        'has_loop_c': has_loop_c, 'has_if': has_if, 'has_volatile': has_volatile,
        'stmts': num_stmts, 'flags': flags
    })

# Print passing functions characteristics
passes = [r for r in results if r['pass']]
fails = [r for r in results if not r['pass']]

print(f"PASSING FUNCTIONS ({len(passes)} total):")
print(f"{'Name':<20s} {'Insns':>5s} {'Call':>4s} {'Branch':>6s} {'Loop':>4s} {'CalSave':>7s} {'CFlags':>6s} {'Extern':>6s} {'If':>3s} {'Stmts':>5s} {'Flags'}")
for r in sorted(passes, key=lambda x: x['insns']):
    print(f"{r['name']:<20s} {r['insns']:>5d} {'Y' if r['has_call'] else 'N':>4s} {'Y' if r['has_branch'] else 'N':>6s} {'Y' if r['has_loop'] else 'N':>4s} {'Y' if r['has_callee_save'] else 'N':>7s} {'Y' if r['custom_flags'] else 'N':>6s} {'Y' if r['has_extern'] else 'N':>6s} {'Y' if r['has_if'] else 'N':>3s} {r['stmts']:>5d} {r['flags']}")

print(f"\nCharacteristics summary:")
print(f"  With calls: {sum(1 for r in passes if r['has_call'])} / {len(passes)}")
print(f"  With branches: {sum(1 for r in passes if r['has_branch'])} / {len(passes)}")
print(f"  With loops: {sum(1 for r in passes if r['has_loop'])} / {len(passes)}")
print(f"  With callee-save: {sum(1 for r in passes if r['has_callee_save'])} / {len(passes)}")
print(f"  Custom flags: {sum(1 for r in passes if r['custom_flags'])} / {len(passes)}")
print(f"  With externs: {sum(1 for r in passes if r['has_extern'])} / {len(passes)}")
print(f"  With if/branches: {sum(1 for r in passes if r['has_if'])} / {len(passes)}")
print(f"  Avg insn count: {sum(r['insns'] for r in passes)/len(passes):.1f}")
print(f"  Insn range: {min(r['insns'] for r in passes)}-{max(r['insns'] for r in passes)}")

# Compare with failing
print(f"\nFailing characteristics ({len(fails)} total):")
print(f"  With calls: {sum(1 for r in fails if r['has_call'])} / {len(fails)}")
print(f"  With branches: {sum(1 for r in fails if r['has_branch'])} / {len(fails)}")
print(f"  With loops: {sum(1 for r in fails if r['has_loop'])} / {len(fails)}")
print(f"  With callee-save: {sum(1 for r in fails if r['has_callee_save'])} / {len(fails)}")
print(f"  Custom flags: {sum(1 for r in fails if r['custom_flags'])} / {len(fails)}")
print(f"  Avg insn count: {sum(r['insns'] for r in fails)/len(fails):.1f}")
print(f"  Insn range: {min(r['insns'] for r in fails)}-{max(r['insns'] for r in fails)}")

# Show delta distribution for fails
print(f"\nFailing delta distribution:")
deltas = {}
for r in fails:
    d = r['delta']
    deltas[d] = deltas.get(d, 0) + 1
for d in sorted(deltas.keys()):
    count = deltas[d]
    print(f"  delta={d:+d}: {count} functions")
