#!/usr/bin/env python3
"""Module boundary scanner for Daytona USA APROG.BIN disassembly.

Identifies groups of functions that share constant pool entries,
indicating they were compiled from the same C source file.

Usage:
    python tools/module_scanner.py [--verbose]

Reads: build/aprog.s (objdump-annotated disassembly)
Output: Module groups with shared pool dependencies
"""

import re
import sys
from collections import defaultdict
from pathlib import Path

APROG = Path(__file__).parent.parent / "build" / "aprog.s"

# Regex patterns for build/aprog.s format
RE_FUNC_HEADER = re.compile(r'^/\* (FUN_[0-9A-Fa-f]+)\s+\(0x([0-9A-Fa-f]+)\)')
RE_FUNC_LABEL = re.compile(r'^(FUN_[0-9A-Fa-f]+):')
RE_MOV_L_PC = re.compile(
    r'/\*\s*([0-9A-Fa-f]+):\s*mov\.l\s+@\(0x[0-9A-Fa-f]+,PC\),r\d+\s+'
    r'\{\[0x([0-9A-Fa-f]+)\]\s*=\s*0x([0-9A-Fa-f]+)\}'
)
RE_MOV_W_PC = re.compile(
    r'/\*\s*([0-9A-Fa-f]+):\s*mov\.w\s+@\(0x([0-9A-Fa-f]+),PC\),r\d+'
)


def parse_aprog(path):
    """Parse build/aprog.s to extract functions and their pool references."""
    functions = []  # [(name, start_addr, end_addr)]
    mov_l_refs = []  # [(instr_addr, target_addr, value, func_name)]
    mov_w_refs = []  # [(instr_addr, target_addr, func_name)]

    current_func = None
    current_addr = None

    with open(path, 'r') as f:
        for line in f:
            # Function header
            m = RE_FUNC_HEADER.match(line)
            if m:
                name = m.group(1)
                addr = int(m.group(2), 16)
                # Close previous function
                if current_func:
                    functions.append((current_func, current_addr, addr))
                current_func = name
                current_addr = addr
                continue

            # mov.l @(disp,PC),Rn with {[target] = value}
            m = RE_MOV_L_PC.search(line)
            if m and current_func:
                instr_addr = int(m.group(1), 16)
                target_addr = int(m.group(2), 16)
                value = int(m.group(3), 16)
                mov_l_refs.append((instr_addr, target_addr, value, current_func))
                continue

            # mov.w @(disp,PC),Rn — compute target from instruction addr + disp
            m = RE_MOV_W_PC.search(line)
            if m and current_func:
                instr_addr = int(m.group(1), 16)
                disp_str = m.group(2)
                target_addr = instr_addr + 4 + int(disp_str, 16)
                mov_w_refs.append((instr_addr, target_addr, current_func))

    # Close last function (estimate end from last known address)
    if current_func:
        functions.append((current_func, current_addr, current_addr + 0x100))

    return functions, mov_l_refs, mov_w_refs


def find_owner(addr, func_ranges):
    """Binary search for which function owns an address."""
    lo, hi = 0, len(func_ranges) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        name, start, end = func_ranges[mid]
        if addr < start:
            hi = mid - 1
        elif addr >= end:
            lo = mid + 1
        else:
            return name
    return None


def build_modules(functions, mov_l_refs, mov_w_refs, verbose=False):
    """Group functions into modules based on shared pool references."""

    func_ranges = sorted(functions, key=lambda x: x[1])

    # Build cross-function reference map
    # edge: func_A -> func_B means A has a mov.l that targets an address in B's range
    cross_refs = defaultdict(set)  # func -> set of funcs it references pools in
    cross_ref_details = []  # for verbose output

    for instr_addr, target_addr, value, src_func in mov_l_refs:
        owner = find_owner(target_addr, func_ranges)
        if owner and owner != src_func:
            cross_refs[src_func].add(owner)
            cross_ref_details.append((src_func, owner, instr_addr, target_addr, value))

    mov_w_cross = 0
    for instr_addr, target_addr, src_func in mov_w_refs:
        owner = find_owner(target_addr, func_ranges)
        if owner and owner != src_func:
            cross_refs[src_func].add(owner)
            mov_w_cross += 1

    # Build connected components (union-find)
    parent = {}

    def find(x):
        while parent.get(x, x) != x:
            parent[x] = parent.get(parent[x], parent[x])
            x = parent[x]
        return x

    def union(a, b):
        ra, rb = find(a), find(b)
        if ra != rb:
            parent[ra] = rb

    # Initialize all functions
    for name, _, _ in func_ranges:
        parent[name] = name

    # Union functions that share pool references
    for src_func, targets in cross_refs.items():
        for tgt_func in targets:
            union(src_func, tgt_func)

    # Collect modules
    modules = defaultdict(list)
    for name, start, end in func_ranges:
        root = find(name)
        modules[root].append((name, start, end))

    # Sort each module by address
    for root in modules:
        modules[root].sort(key=lambda x: x[1])

    return modules, cross_refs, cross_ref_details, mov_w_cross


def main():
    verbose = '--verbose' in sys.argv

    print(f"Reading {APROG}...")
    functions, mov_l_refs, mov_w_refs = parse_aprog(APROG)
    print(f"  Functions: {len(functions)}")
    print(f"  mov.l @(disp,PC) refs: {len(mov_l_refs)}")
    print(f"  mov.w @(disp,PC) refs: {len(mov_w_refs)}")

    print("\nBuilding module map...")
    modules, cross_refs, cross_ref_details, mov_w_cross = build_modules(
        functions, mov_l_refs, mov_w_refs, verbose
    )

    # Stats
    singletons = sum(1 for m in modules.values() if len(m) == 1)
    multi = {k: v for k, v in modules.items() if len(v) > 1}

    print(f"\n{'='*60}")
    print(f"MODULE BOUNDARY ANALYSIS")
    print(f"{'='*60}")
    print(f"Total functions:       {len(functions)}")
    print(f"Total modules:         {len(modules)}")
    print(f"  Singletons (1 func): {singletons}")
    print(f"  Multi-func modules:  {len(multi)}")
    print(f"Cross-func mov.l refs: {len(cross_ref_details)}")
    print(f"Cross-func mov.w refs: {mov_w_cross}")

    # List multi-function modules sorted by size (largest first)
    print(f"\n{'='*60}")
    print(f"MULTI-FUNCTION MODULES (sorted by function count)")
    print(f"{'='*60}")

    sorted_multi = sorted(multi.items(), key=lambda x: len(x[1]), reverse=True)
    for root, funcs in sorted_multi:
        addr_range = f"0x{funcs[0][1]:08X}-0x{funcs[-1][2]:08X}"
        total_bytes = funcs[-1][2] - funcs[0][1]
        print(f"\n  Module ({len(funcs)} funcs, {total_bytes} bytes) @ {addr_range}:")
        for name, start, end in funcs:
            size = end - start
            print(f"    {name}  0x{start:08X}  ({size} bytes)")

    # List singletons as L3 candidates
    print(f"\n{'='*60}")
    print(f"SINGLETON FUNCTIONS (self-contained, ideal L3 candidates)")
    print(f"{'='*60}")

    singleton_list = []
    for root, funcs in modules.items():
        if len(funcs) == 1:
            name, start, end = funcs[0]
            size = end - start
            singleton_list.append((name, start, size))

    singleton_list.sort(key=lambda x: x[2])  # sort by size

    # Show size distribution
    sizes = [s for _, _, s in singleton_list]
    small = sum(1 for s in sizes if s <= 32)
    medium = sum(1 for s in sizes if 32 < s <= 128)
    large = sum(1 for s in sizes if 128 < s <= 512)
    huge = sum(1 for s in sizes if s > 512)

    print(f"\n  Size distribution:")
    print(f"    <=32 bytes:  {small}")
    print(f"    33-128:      {medium}")
    print(f"    129-512:     {large}")
    print(f"    >512:        {huge}")

    # Show medium-sized singletons (good L3 candidates)
    print(f"\n  Medium singletons (33-128 bytes) — best L3 starting candidates:")
    for name, start, size in singleton_list:
        if 33 <= size <= 128:
            print(f"    {name}  0x{start:08X}  ({size} bytes)")

    if verbose:
        print(f"\n{'='*60}")
        print(f"CROSS-FUNCTION POOL REFERENCES (mov.l)")
        print(f"{'='*60}")
        for src, tgt, iaddr, taddr, val in sorted(cross_ref_details):
            print(f"  {src} @ 0x{iaddr:08X} -> [{tgt} + 0x{taddr:08X}] = 0x{val:08X}")


if __name__ == '__main__':
    main()
