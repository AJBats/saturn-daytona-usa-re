#!/usr/bin/env python3
"""Exhaustively try all flag combinations on all failing functions"""
import os
import subprocess

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"

# All flag combinations to try
FLAG_COMBOS = [
    ("-O2 -m2 -mbsr", "default"),
    ("-O2 -m2", "no-bsr"),
    ("-O2 -m2 -mbsr -mnofill", "nofill"),
    ("-O2 -m2 -mnofill", "no-bsr+nofill"),
    ("-O2 -m2 -mbsr -mno-bsr-fill", "no-bsr-fill"),
    ("-O2 -m2 -mbsr -mno-rts-fill", "no-rts-fill"),
    ("-O2 -m2 -mno-rts-fill", "no-bsr+no-rts-fill"),
    ("-O2 -m2 -mbsr -mno-bsr-fill -mno-rts-fill", "no-bsr-fill+no-rts-fill"),
]

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

def get_current_flags(name):
    """Get the flags currently used by harness"""
    flagfile = os.path.join(TDIR, name + ".flags")
    if os.path.exists(flagfile):
        with open(flagfile) as f:
            return f.read().replace('\r', '').strip()
    return "-O2 -m2 -mbsr"

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

    # Get current result
    current_flags = get_current_flags(name)
    current_opcodes = compile_and_get_opcodes(name, current_flags)
    if current_opcodes is None:
        continue
    if current_opcodes == expected:
        continue  # Already passing

    current_diffs = sum(1 for i in range(min(len(current_opcodes), len(expected)))
                       if current_opcodes[i] != expected[i])
    current_diffs += abs(len(current_opcodes) - len(expected))
    current_delta = len(current_opcodes) - len(expected)

    # Try all flag combinations
    best_flags = None
    best_diffs = current_diffs
    best_delta = current_delta
    best_match = False

    for flags, label in FLAG_COMBOS:
        if flags == current_flags:
            continue  # Skip current flags
        opcodes = compile_and_get_opcodes(name, flags)
        if opcodes is None:
            continue
        if opcodes == expected:
            new_matches.append((name, flags, label))
            best_match = True
            break
        else:
            diffs = sum(1 for i in range(min(len(opcodes), len(expected)))
                       if opcodes[i] != expected[i])
            diffs += abs(len(opcodes) - len(expected))
            if diffs < best_diffs:
                best_diffs = diffs
                best_delta = len(opcodes) - len(expected)
                best_flags = flags

    if not best_match and best_flags and best_diffs < current_diffs:
        improvements.append((name, current_flags, current_diffs, current_delta,
                           best_flags, best_diffs, best_delta))

print("=" * 70)
print("COMPREHENSIVE FLAG SCAN RESULTS")
print("=" * 70)

print(f"\nNEW MATCHES (can be fixed with .flags): {len(new_matches)}")
for name, flags, label in new_matches:
    print(f"  {name}: flags='{flags}' ({label})")

print(f"\nIMPROVEMENTS (fewer diffs with different flags): {len(improvements)}")
improvements.sort(key=lambda x: x[5])
for name, cur_flags, cur_diffs, cur_delta, best_flags, best_diffs, best_delta in improvements[:20]:
    print(f"  {name}: {cur_diffs} diffs -> {best_diffs} diffs (delta {cur_delta:+d} -> {best_delta:+d})")
    print(f"    current: {cur_flags}")
    print(f"    better:  {best_flags}")
