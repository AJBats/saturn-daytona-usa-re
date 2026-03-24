#!/usr/bin/env python3
"""Build TU groups from contiguous non-4-byte-aligned functions.

A function at a non-4-byte-aligned address was originally an inner member
of a TU (the linker always starts sections at 4-byte boundaries). We group
non-aligned functions with their IMMEDIATELY PRECEDING aligned head — but
ONLY if they are contiguous (no other function sections between them).

Usage:
    python tools/build_tu_groups.py > tools/tu_groups_align.txt
"""

import re
import sys
from pathlib import Path

PROJECT = Path(__file__).resolve().parent.parent
SRC_DIR = PROJECT / 'reimpl' / 'src'


def get_all_function_addrs():
    """Get sorted list of (addr, name) for all FUN_*.s files in src/."""
    funcs = []
    for p in SRC_DIR.glob('FUN_????????.s'):
        name = p.stem
        m = re.match(r'FUN_([0-9A-Fa-f]{8})', name)
        if m:
            addr = int(m.group(1), 16)
            funcs.append((addr, name))
    funcs.sort()
    return funcs


def build_groups():
    """Build contiguous TU groups."""
    funcs = get_all_function_addrs()
    groups = []
    current_head = None
    current_members = []

    for addr, name in funcs:
        if addr % 4 == 0:
            # 4-byte aligned = potential section head
            if current_head and current_members:
                groups.append((current_head, current_members))
            current_head = name
            current_members = []
        else:
            # Non-4-byte aligned = inner TU member
            # Only group if IMMEDIATELY follows the current head (contiguous)
            if current_head is not None:
                current_members.append(name)
            else:
                # No head yet — orphan non-aligned function
                sys.stderr.write(f"WARNING: orphan non-aligned {name}\n")

    # Don't forget the last group
    if current_head and current_members:
        groups.append((current_head, current_members))

    return groups


def main():
    groups = build_groups()
    print(f"# TU groups from contiguous 4-byte alignment analysis")
    print(f"# {len(groups)} groups, {sum(len(m) for _, m in groups)} non-aligned members")
    print(f"# Only CONTIGUOUS non-4-byte-aligned functions merged into aligned predecessors")
    for head, members in groups:
        print(f"{head} {' '.join(members)}")


if __name__ == "__main__":
    main()
