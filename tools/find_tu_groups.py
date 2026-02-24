#!/usr/bin/env python3
"""Find TU consolidation groups by analyzing cross-section BSR/BRA references.

Scans all reimpl/src/*.s L3 files for:
1. TU address ranges (from file headers)
2. BSR/BRA byte pairs targeting external addresses

Builds a directed graph of file->file references, finds connected components,
and reports consolidation candidates ordered by byte-branch reduction potential.
"""

import re
import os
import sys
from collections import defaultdict
from pathlib import Path

def parse_l3_files(src_dir):
    """Parse all L3 files for address ranges and BSR/BRA targets."""
    files = {}  # filename -> {start, end, bsr_targets, bra_targets}

    for path in sorted(Path(src_dir).glob("*.s")):
        name = path.stem
        start = end = None
        bsr_targets = []
        bra_targets = []

        with open(path, "r", encoding="utf-8", errors="replace") as f:
            for line in f:
                # Parse TU range from header
                m = re.search(r'Translation unit:\s*0x([0-9A-Fa-f]+)\s*-\s*0x([0-9A-Fa-f]+)', line)
                if m:
                    start = int(m.group(1), 16)
                    end = int(m.group(2), 16)

                # Parse BSR/BRA byte pairs
                m = re.search(r'/\*\s*(bsr|bra)\s+0x([0-9A-Fa-f]+)\s+\(external\)', line)
                if m:
                    kind = m.group(1)
                    target = int(m.group(2), 16)
                    if kind == 'bsr':
                        bsr_targets.append(target)
                    else:
                        bra_targets.append(target)

        if start is not None:
            files[name] = {
                'start': start,
                'end': end,
                'path': str(path),
                'bsr_targets': bsr_targets,
                'bra_targets': bra_targets,
            }

    return files


def build_address_map(files):
    """Build address -> filename lookup."""
    # Sort files by start address for binary search
    sorted_files = sorted(files.items(), key=lambda x: x[1]['start'])

    def find_file_for_addr(addr):
        """Find which file contains an address."""
        for name, info in sorted_files:
            if info['start'] <= addr < info['end']:
                return name
        return None

    return find_file_for_addr


def find_connected_components(files, find_file):
    """Find connected components in the BSR/BRA reference graph."""
    # Build adjacency list (undirected)
    adj = defaultdict(set)

    for name, info in files.items():
        for target in info['bsr_targets'] + info['bra_targets']:
            target_file = find_file(target)
            if target_file and target_file != name:
                adj[name].add(target_file)
                adj[target_file].add(name)

    # BFS to find connected components
    visited = set()
    components = []

    for name in files:
        if name in visited or name not in adj:
            continue
        # BFS
        component = set()
        queue = [name]
        while queue:
            node = queue.pop(0)
            if node in visited:
                continue
            visited.add(node)
            component.add(node)
            for neighbor in adj[node]:
                if neighbor not in visited:
                    queue.append(neighbor)
        components.append(component)

    return components


def count_resolvable_branches(component, files, find_file):
    """Count how many BSR/BRA would become resolvable if component is merged."""
    count = 0
    for name in component:
        info = files[name]
        for target in info['bsr_targets'] + info['bra_targets']:
            target_file = find_file(target)
            if target_file and target_file in component and target_file != name:
                count += 1
    return count


def main():
    src_dir = os.path.join(os.path.dirname(__file__), '..', 'reimpl', 'src')

    print("Parsing L3 files...")
    files = parse_l3_files(src_dir)
    print(f"  Parsed {len(files)} files with TU ranges")

    find_file = build_address_map(files)

    print("\nFinding connected components...")
    components = find_connected_components(files, find_file)

    # Score each component by resolvable branches
    scored = []
    for comp in components:
        n_branches = count_resolvable_branches(comp, files, find_file)
        scored.append((n_branches, comp))

    scored.sort(reverse=True)

    # Count stats
    total_files_in_groups = sum(len(c) for _, c in scored)
    total_resolvable = sum(n for n, _ in scored)
    singleton_bsr = 0
    for name, info in files.items():
        for target in info['bsr_targets'] + info['bra_targets']:
            target_file = find_file(target)
            if target_file is None:
                singleton_bsr += 1  # target in game_update_loop or other already-consolidated TU

    print(f"\n{'='*70}")
    print(f"TU CONSOLIDATION ANALYSIS")
    print(f"{'='*70}")
    print(f"Total L3 files: {len(files)}")
    print(f"Files with cross-TU branches: {total_files_in_groups}")
    print(f"Connected components (TU groups): {len(scored)}")
    print(f"Total resolvable BSR/BRA: {total_resolvable}")
    print(f"BSR/BRA targeting unknown addresses: {singleton_bsr}")
    print()

    # Print groups
    for i, (n_branches, comp) in enumerate(scored):
        if len(comp) < 2:
            continue

        # Sort by address for readability
        sorted_comp = sorted(comp, key=lambda n: files[n]['start'])
        addr_start = min(files[n]['start'] for n in comp)
        addr_end = max(files[n]['end'] for n in comp)

        print(f"--- Group {i+1}: {len(comp)} files, {n_branches} resolvable branches ---")
        print(f"    Address range: 0x{addr_start:08X} - 0x{addr_end:08X} ({addr_end - addr_start} bytes)")
        for name in sorted_comp:
            info = files[name]
            n_bsr = len([t for t in info['bsr_targets'] if find_file(t) and find_file(t) in comp and find_file(t) != name])
            n_bra = len([t for t in info['bra_targets'] if find_file(t) and find_file(t) in comp and find_file(t) != name])
            marker = ""
            if n_bsr + n_bra > 0:
                marker = f"  ({n_bsr} bsr, {n_bra} bra -> group)"
            print(f"    {name:40s} 0x{info['start']:08X}-0x{info['end']:08X}{marker}")

        # Show what each file references
        print(f"    Cross-references:")
        for name in sorted_comp:
            info = files[name]
            targets = set()
            for t in info['bsr_targets'] + info['bra_targets']:
                tf = find_file(t)
                if tf and tf in comp and tf != name:
                    targets.add(tf)
            if targets:
                print(f"      {name} -> {', '.join(sorted(targets))}")
        print()

    # Summary of 1-file "groups" (self-referencing only)
    single_count = sum(1 for n, c in scored if len(c) == 1)
    if single_count:
        print(f"({single_count} single-file groups with only self-references, omitted)")

    # Also check for contiguous address ranges that could be merged
    print(f"\n{'='*70}")
    print(f"CONTIGUITY CHECK")
    print(f"{'='*70}")
    for i, (n_branches, comp) in enumerate(scored[:20]):
        if len(comp) < 2:
            continue
        sorted_comp = sorted(comp, key=lambda n: files[n]['start'])
        gaps = []
        for j in range(len(sorted_comp) - 1):
            a = sorted_comp[j]
            b = sorted_comp[j + 1]
            gap = files[b]['start'] - files[a]['end']
            if gap > 0:
                # Find what's in the gap
                gap_files = []
                for name, info in files.items():
                    if name not in comp and files[a]['end'] <= info['start'] < files[b]['start']:
                        gap_files.append(name)
                gaps.append((a, b, gap, gap_files))

        if gaps:
            print(f"\nGroup {i+1} has {len(gaps)} gaps:")
            for a, b, gap, gap_files in gaps:
                print(f"  {a} -> {b}: {gap} bytes gap ({len(gap_files)} files in gap)")
                for gf in sorted(gap_files, key=lambda n: files[n]['start']):
                    print(f"    {gf:40s} 0x{files[gf]['start']:08X}-0x{files[gf]['end']:08X}")
        else:
            print(f"\nGroup {i+1}: CONTIGUOUS (no gaps)")


if __name__ == '__main__':
    main()
