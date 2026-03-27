#!/usr/bin/env python3
"""Validate cross-section pool merge groups for contiguity.

Reads the map file to check that all sections in a merge group
are adjacent (no other sections between them).
"""

import re
from pathlib import Path
from collections import defaultdict

PROJECT = Path(__file__).resolve().parent.parent
MAP_FILE = PROJECT / 'reimpl' / 'build' / 'daytona.map'
PAIRS_FILE = PROJECT / 'tools' / 'pool_merge_pairs.txt'


def parse_map_sections():
    """Parse linker map file for .text.FUN_* sections."""
    sections = []
    with open(MAP_FILE) as f:
        lines = f.readlines()

    i = 0
    while i < len(lines):
        m = re.match(r'\s*\.text\.(FUN_[0-9A-Fa-f]+)\s*$', lines[i])
        if m:
            sec_name = m.group(1)
            if i + 1 < len(lines):
                m2 = re.match(r'\s*0x([0-9a-f]+)\s+0x([0-9a-f]+)', lines[i + 1])
                if m2:
                    addr = int(m2.group(1), 16)
                    size = int(m2.group(2), 16)
                    sections.append((addr, size, sec_name))
        i += 1

    sections.sort()
    return sections


def build_groups(pairs):
    """Union-Find to build connected components."""
    parent = {}

    def find(x):
        while parent.get(x, x) != x:
            parent[x] = parent.get(parent[x], parent[x])
            x = parent[x]
        return x

    def union(a, b):
        a, b = find(a), find(b)
        if a != b:
            parent[a] = b

    all_nodes = set()
    for a, b in pairs:
        union(a, b)
        all_nodes.add(a)
        all_nodes.add(b)

    groups = defaultdict(list)
    for n in all_nodes:
        groups[find(n)].append(n)

    return [sorted(members) for members in groups.values() if len(members) >= 2]


def main():
    sections = parse_map_sections()
    section_order = [name for _, _, name in sections]
    section_idx = {name: i for i, name in enumerate(section_order)}

    # Read pairs
    pairs = []
    with open(PAIRS_FILE) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            parts = line.split()
            if len(parts) == 2:
                pairs.append((parts[0], parts[1]))

    groups = build_groups(pairs)

    contiguous = []
    non_contiguous = []

    for members in groups:
        indices = []
        missing = []
        for m in members:
            if m in section_idx:
                indices.append(section_idx[m])
            else:
                missing.append(m)

        if missing:
            non_contiguous.append((members, f'missing from map: {missing}'))
            continue

        indices.sort()
        min_idx, max_idx = min(indices), max(indices)
        expected = set(range(min_idx, max_idx + 1))
        actual = set(indices)
        gaps = expected - actual

        if not gaps:
            contiguous.append(members)
        else:
            gap_names = [section_order[i] for i in sorted(gaps)]
            non_contiguous.append((members, gap_names))

    # Print results
    print(f'Contiguous groups: {len(contiguous)} ({sum(len(g) for g in contiguous)} files)')
    print(f'Non-contiguous groups: {len(non_contiguous)}')
    print()

    print('=== CONTIGUOUS (safe to merge) ===')
    for members in sorted(contiguous, key=lambda m: -len(m)):
        print(f'  [{len(members):2d}] {" ".join(members)}')

    if non_contiguous:
        print()
        print('=== NON-CONTIGUOUS (have gaps) ===')
        for members, gaps in sorted(non_contiguous, key=lambda x: -len(x[0])):
            if isinstance(gaps, str):
                print(f'  [{len(members):2d}] {gaps}')
            else:
                print(f'  [{len(members):2d}] {len(gaps)} gap(s): {" ".join(gaps[:5])}{"..." if len(gaps)>5 else ""}')
            print(f'       members: {" ".join(members[:8])}{"..." if len(members)>8 else ""}')

    # Write contiguous groups as batch file
    out = PROJECT / 'tools' / 'pool_merge_groups.txt'
    with open(out, 'w') as f:
        f.write('# Cross-section pool merge groups (contiguous, validated)\n')
        f.write(f'# {len(contiguous)} groups, {sum(len(g) for g in contiguous)} files\n')
        for members in sorted(contiguous, key=lambda m: int(m[0][4:], 16)):
            f.write(' '.join(members) + '\n')
    print(f'\nWrote {out}')


if __name__ == '__main__':
    main()
