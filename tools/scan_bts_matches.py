#!/usr/bin/env python3
"""Scan failures: how many match if we also convert bt.s->bt, bf.s->bf?"""
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

def neutralize_bts(opcodes):
    """Convert bt.s->bt and bf.s->bf"""
    return [op.replace('bt.s','bt').replace('bf.s','bf') for op in opcodes]

tested = set()
for f in os.listdir(SRCDIR):
    if f.endswith('.c'):
        tested.add(f[:-2])

results = {"default_match":[], "nobsr_match":[], "nobsr_neutralize_match":[],
           "default_neutralize_match":[], "nobsr_closer":[], "default_closer":[]}

for name in sorted(tested):
    exp_path = os.path.join(TDIR, name + ".expected")
    if not os.path.exists(exp_path):
        continue
    expected = get_expected(name)

    # Default flags
    default_opcodes = compile_and_get_opcodes(name, "-O2 -m2 -mbsr")
    if default_opcodes is None:
        continue
    if default_opcodes == expected:
        # Already passing - check if neutralizing bts would break it
        continue

    # No-BSR
    nobsr_opcodes = compile_and_get_opcodes(name, "-O2 -m2")
    if nobsr_opcodes is None:
        continue

    # Test 4 variants for opcode match:
    # 1. default + neutralize
    default_neut = neutralize_bts(default_opcodes)
    exp_neut = neutralize_bts(expected)
    if default_neut == exp_neut:
        results["default_neutralize_match"].append(name)

    # 2. nobsr + neutralize
    nobsr_neut = neutralize_bts(nobsr_opcodes)
    if nobsr_neut == exp_neut:
        results["nobsr_neutralize_match"].append(name)

    # 3. nobsr raw match
    if nobsr_opcodes == expected:
        results["nobsr_match"].append(name)

    # Check default raw diffs vs neutralized diffs
    default_diffs = sum(1 for i in range(min(len(default_opcodes), len(expected)))
                       if default_opcodes[i] != expected[i])
    default_diffs += abs(len(default_opcodes) - len(expected))

    default_neut_diffs = sum(1 for i in range(min(len(default_neut), len(exp_neut)))
                            if default_neut[i] != exp_neut[i])
    default_neut_diffs += abs(len(default_neut) - len(exp_neut))

    nobsr_diffs = sum(1 for i in range(min(len(nobsr_opcodes), len(expected)))
                     if nobsr_opcodes[i] != expected[i])
    nobsr_diffs += abs(len(nobsr_opcodes) - len(expected))

    nobsr_neut_diffs = sum(1 for i in range(min(len(nobsr_neut), len(exp_neut)))
                          if nobsr_neut[i] != exp_neut[i])
    nobsr_neut_diffs += abs(len(nobsr_neut) - len(exp_neut))

    if default_neut_diffs < default_diffs:
        results["default_closer"].append((name, default_diffs, default_neut_diffs))
    if nobsr_neut_diffs < nobsr_diffs:
        results["nobsr_closer"].append((name, nobsr_diffs, nobsr_neut_diffs))

# Also check if any passing functions would BREAK with neutralization
# (i.e., they pass because of bt.s/bf.s matching expected bt.s/bf.s)
broken = []
for name in sorted(tested):
    exp_path = os.path.join(TDIR, name + ".expected")
    if not os.path.exists(exp_path):
        continue
    expected = get_expected(name)
    default_opcodes = compile_and_get_opcodes(name, "-O2 -m2 -mbsr")
    if default_opcodes is None or default_opcodes != expected:
        continue
    # Currently passing. Check if it uses bt.s/bf.s
    has_bts = any('bt.s' in op or 'bf.s' in op for op in default_opcodes)
    exp_has_bts = any('bt.s' in op or 'bf.s' in op for op in expected)
    if has_bts and exp_has_bts:
        broken.append(name)

print("ANALYSIS: bt.s/bf.s neutralization impact")
print("="*60)

print(f"\nMATCH with -O2 -m2 (raw): {len(results['nobsr_match'])}")
for n in results["nobsr_match"]:
    print(f"  {n}")

print(f"\nMATCH with -O2 -m2 + bt.s→bt neutralize: {len(results['nobsr_neutralize_match'])}")
for n in results["nobsr_neutralize_match"]:
    marker = " (NEW)" if n not in results["nobsr_match"] else ""
    print(f"  {n}{marker}")

print(f"\nMATCH with -O2 -m2 -mbsr + bt.s→bt neutralize: {len(results['default_neutralize_match'])}")
for n in results["default_neutralize_match"]:
    print(f"  {n}")

print(f"\nIMPROVED with -O2 -m2 -mbsr + neutralize: {len(results['default_closer'])}")
for n, old, new in results["default_closer"][:15]:
    print(f"  {n}: {old} diffs -> {new}")

print(f"\nIMPROVED with -O2 -m2 + neutralize: {len(results['nobsr_closer'])}")
for n, old, new in results["nobsr_closer"][:15]:
    print(f"  {n}: {old} diffs -> {new}")

print(f"\nPassing functions that use bt.s/bf.s (would need bt.s→bt to be selective): {len(broken)}")
for n in broken:
    print(f"  {n}")
