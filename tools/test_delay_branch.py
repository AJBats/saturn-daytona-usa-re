#!/usr/bin/env python3
"""Test -fno-delayed-branch on delta=-1 functions to see if unfilling delay slots helps"""
import os
import subprocess

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"

def compile_and_get_opcodes(name, flags):
    """Compile with given flags, return opcodes list"""
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

def compare(opcodes, expected):
    if opcodes == expected:
        return "MATCH"
    delta = len(opcodes) - len(expected)
    diffs = sum(1 for i in range(min(len(opcodes), len(expected)))
                if opcodes[i] != expected[i])
    diffs += abs(len(opcodes) - len(expected))
    return f"delta={delta:+d}, {diffs} diffs"

# Test functions that might benefit from -fno-delayed-branch
# These are delta=-1 functions where our delay slot fill saves 1 nop
test_functions = [
    "FUN_06033504",  # rts delay slot fill
    "FUN_0600DE40",  # bsr delay slot fill
    "FUN_0600DE54",  # bsr delay slot fill
    "FUN_060054EA",  # rts delay slot fill
    "FUN_0603B734",  # rts delay slot fill
    "FUN_0603EF54",  # rts delay slot fill
    "FUN_0603F520",  # delay slot
    "FUN_06014A42",  # tail call (bra vs jmp)
    "FUN_060349B6",  # bsr vs jsr
    "FUN_06042BBE",  # instruction reorder
    "FUN_06042BEE",  # instruction reorder
    "FUN_06041310",  # bt.s/bf.s vs bt/bf
    "FUN_06038520",  # bf.s vs bf
    "FUN_06035438",  # bt vs bf branch sense
    "FUN_0603F1E0",  # different shift sequence
    "FUN_0603EFD4",  # different compute order
]

flag_combos = [
    ("-O2 -m2 -mbsr", "default"),
    ("-O2 -m2 -mbsr -fno-delayed-branch", "no-delay"),
    ("-O2 -m2 -fno-delayed-branch", "no-bsr,no-delay"),
    ("-O2 -m2", "no-bsr"),
]

print(f"{'Function':<20s} {'default':<20s} {'no-delay':<20s} {'no-bsr,no-delay':<20s} {'no-bsr':<20s}")
print("-" * 100)

for name in test_functions:
    if not os.path.exists(os.path.join(SRCDIR, name + ".c")):
        continue
    if not os.path.exists(os.path.join(TDIR, name + ".expected")):
        continue

    expected = get_expected(name)
    results = []
    for flags, label in flag_combos:
        opcodes = compile_and_get_opcodes(name, flags)
        if opcodes is None:
            results.append("ERROR")
        else:
            results.append(compare(opcodes, expected))

    print(f"{name:<20s} {results[0]:<20s} {results[1]:<20s} {results[2]:<20s} {results[3]:<20s}")

# Show detailed output for any MATCHes
print("\n\nDetailed output for any matches or improvements:")
for name in test_functions:
    if not os.path.exists(os.path.join(SRCDIR, name + ".c")):
        continue
    if not os.path.exists(os.path.join(TDIR, name + ".expected")):
        continue

    expected = get_expected(name)
    for flags, label in flag_combos:
        opcodes = compile_and_get_opcodes(name, flags)
        if opcodes is not None and opcodes == expected:
            print(f"\n  *** {name} MATCHES with flags: {flags}")
            for i, (o, e) in enumerate(zip(opcodes, expected)):
                print(f"    [{i:2d}] {o:12s} | {e}")
