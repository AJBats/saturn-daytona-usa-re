#!/usr/bin/env python3
"""Parse patch_binary.py dry run output and generate sorted candidate list for additive boot testing.

Reads from stdin (pipe from patch_binary.py --level 0) and outputs:
1. Sorted candidate list file (DIFF functions that fit in slot, smallest first)
2. Summary stats
"""

import re
import sys
import os

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TESTDIR = os.path.join(PROJDIR, 'tests')

# Determine if function is LEAF (no callee-save push) by checking the .c source
def is_leaf_function(func_name):
    """Check if a function's .expected file suggests LEAF (no sts.l/pra save)."""
    expected_file = os.path.join(TESTDIR, f'{func_name}.expected')
    if not os.path.exists(expected_file):
        return True  # assume leaf if no info
    with open(expected_file, 'r') as f:
        content = f.read()
    # LEAF = no sts.l pr,@-r15 (PR save)
    return 'sts.l' not in content

def main():
    lines = sys.stdin.read().splitlines()

    candidates = []  # (func_name, insn_count, code_size, pool_size, slot_size, is_leaf, detail)
    l3_funcs = []
    l2_funcs = []
    l1_funcs = []
    err_funcs = []
    overflow_funcs = []

    for line in lines:
        line = line.strip()
        if not line:
            continue

        # Parse: "  DIFF  FUN_XXXXXXXX  detail  code=N pool=N slot=N"
        m = re.match(r'(L[123]|DIFF|ERR)\s+(FUN_[0-9A-Fa-f]+)\s+(.*)', line)
        if not m:
            continue

        tag = m.group(1)
        func_name = m.group(2)
        rest = m.group(3)

        if tag == 'ERR':
            err_funcs.append(func_name)
            continue

        # Extract sizes
        code_m = re.search(r'code=(\d+)', rest)
        pool_m = re.search(r'pool=(\d+)', rest)
        slot_m = re.search(r'slot=(\d+)', rest)

        if not (code_m and pool_m and slot_m):
            continue

        code_size = int(code_m.group(1))
        pool_size = int(pool_m.group(1))
        slot_size = int(slot_m.group(1))
        insn_count = code_size // 2

        total = code_size + pool_size

        if tag == 'L3':
            l3_funcs.append(func_name)
        elif tag == 'L2':
            l2_funcs.append(func_name)
        elif tag == 'L1':
            l1_funcs.append(func_name)
        elif tag == 'DIFF':
            if 'size mismatch' in rest:
                overflow_funcs.append((func_name, insn_count, total, slot_size))
                continue
            if total > slot_size:
                overflow_funcs.append((func_name, insn_count, total, slot_size))
                continue

            leaf = is_leaf_function(func_name)

            # Extract match detail for interest
            detail_m = re.search(r'(\d+)/(\d+)\s+exact,\s+(\d+)/(\d+)\s+structural', rest)
            if detail_m:
                exact = int(detail_m.group(1))
                total_insns = int(detail_m.group(2))
                structural = int(detail_m.group(3))
                match_pct = (structural / total_insns * 100) if total_insns > 0 else 0
                detail = f'{exact}/{total_insns} exact, {structural}/{total_insns} structural ({match_pct:.0f}%)'
            else:
                detail = rest.split('code=')[0].strip()
                match_pct = 0

            candidates.append((func_name, insn_count, code_size, pool_size, slot_size, leaf, detail, match_pct))

    # Sort: leaf before call, then by instruction count ascending
    candidates.sort(key=lambda x: (0 if x[5] else 1, x[1]))

    # Output sorted list
    print(f"# Additive Boot Test Candidates")
    print(f"# Generated from patch_binary.py dry run")
    print(f"# Sort: LEAF first, then by instruction count (smallest first)")
    print(f"#")
    print(f"# Baseline: {len(l3_funcs)} L3 + {len(l2_funcs)} L2 = {len(l3_funcs) + len(l2_funcs)} functions")
    print(f"# Candidates: {len(candidates)} DIFF functions that fit in slot")
    print(f"# L1 functions: {len(l1_funcs)}")
    print(f"# Overflow: {len(overflow_funcs)} (code+pool > slot)")
    print(f"# Errors: {len(err_funcs)}")
    print(f"#")
    print(f"# Format: FUNC_NAME  insns  code  pool  slot  type  match%  detail")
    print()

    for func_name, insn_count, code_size, pool_size, slot_size, leaf, detail, match_pct in candidates:
        ftype = "LEAF" if leaf else "CALL"
        print(f"{func_name}  {insn_count:4d}  {code_size:5d}  {pool_size:4d}  {slot_size:5d}  {ftype}  {match_pct:5.1f}%  {detail}")

    # Also write just the function names for --include-funcs
    names_file = os.path.join(PROJDIR, 'build', 'candidates.txt')
    os.makedirs(os.path.dirname(names_file), exist_ok=True)
    with open(names_file, 'w') as f:
        for func_name, insn_count, code_size, pool_size, slot_size, leaf, detail, match_pct in candidates:
            f.write(f'{func_name}\n')
    print(f"\n# Function names written to: {names_file}", file=sys.stderr)


if __name__ == '__main__':
    main()
