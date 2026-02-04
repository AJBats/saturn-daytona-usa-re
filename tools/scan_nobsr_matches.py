#!/usr/bin/env python3
"""Scan ALL failing functions to find which ones MATCH with -O2 -m2 (no -mbsr)"""
import os
import subprocess

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"

def compile_and_get_opcodes(name, flags):
    cfile = os.path.join(SRCDIR, name + ".c")
    with open(cfile) as f:
        src = f.read().replace('\r', '')
    with open("/tmp/test_src.c", "w") as f:
        f.write(src)

    result = subprocess.run(
        [CC1, "-quiet"] + flags.split() + ["/tmp/test_src.c", "-o", "/tmp/test_out.s"],
        capture_output=True, text=True, timeout=10
    )
    if result.returncode != 0:
        return None

    opcodes = []
    with open("/tmp/test_out.s") as f:
        for line in f:
            line = line.rstrip()
            if line.startswith('\t') and line.strip():
                parts = line.strip().split()
                if parts and parts[0][0].isalpha():
                    opcodes.append(parts[0].rstrip(','))
    return opcodes

def get_expected(name):
    path = os.path.join(TDIR, name + ".expected")
    with open(path) as f:
        return [l.strip().replace('bf/s','bf.s').replace('bt/s','bt.s')
                for l in f.read().replace('\r', '').split('\n') if l.strip()]

# Find all test functions
tested = set()
for f in os.listdir(SRCDIR):
    if f.endswith('.c'):
        tested.add(f[:-2])

new_matches = []
improvements = []

for name in sorted(tested):
    exp_path = os.path.join(TDIR, name + ".expected")
    if not os.path.exists(exp_path):
        continue
    expected = get_expected(name)

    # Check if already passing with default flags
    default_opcodes = compile_and_get_opcodes(name, "-O2 -m2 -mbsr")
    if default_opcodes is None:
        continue
    if default_opcodes == expected:
        continue  # Already passing

    default_delta = len(default_opcodes) - len(expected)
    default_diffs = sum(1 for i in range(min(len(default_opcodes), len(expected)))
                       if default_opcodes[i] != expected[i])
    default_diffs += abs(len(default_opcodes) - len(expected))

    # Try without -mbsr
    nobsr_opcodes = compile_and_get_opcodes(name, "-O2 -m2")
    if nobsr_opcodes is None:
        continue

    if nobsr_opcodes == expected:
        new_matches.append(name)
        print(f"MATCH  {name}")
    else:
        nobsr_delta = len(nobsr_opcodes) - len(expected)
        nobsr_diffs = sum(1 for i in range(min(len(nobsr_opcodes), len(expected)))
                        if nobsr_opcodes[i] != expected[i])
        nobsr_diffs += abs(len(nobsr_opcodes) - len(expected))

        if nobsr_diffs < default_diffs:
            improvements.append((name, default_delta, default_diffs, nobsr_delta, nobsr_diffs))

# Also check currently-passing functions for regressions with -O2 -m2
regressions = []
for name in sorted(tested):
    exp_path = os.path.join(TDIR, name + ".expected")
    if not os.path.exists(exp_path):
        continue
    expected = get_expected(name)

    default_opcodes = compile_and_get_opcodes(name, "-O2 -m2 -mbsr")
    if default_opcodes is None or default_opcodes != expected:
        continue  # Not currently passing

    # Check if it would regress without -mbsr
    nobsr_opcodes = compile_and_get_opcodes(name, "-O2 -m2")
    if nobsr_opcodes != expected:
        regressions.append(name)

print(f"\n{'='*60}")
print(f"NEW MATCHES with -O2 -m2 (no -mbsr): {len(new_matches)}")
for n in new_matches:
    print(f"  {n}")

print(f"\nIMPROVEMENTS (fewer diffs): {len(improvements)}")
for n, dd, ddf, nd, ndf in improvements:
    print(f"  {n}: {ddf} diffs -> {ndf} diffs (delta {dd:+d} -> {nd:+d})")

print(f"\nREGRESSIONS (currently pass, would fail without -mbsr): {len(regressions)}")
for n in regressions:
    print(f"  {n}")
