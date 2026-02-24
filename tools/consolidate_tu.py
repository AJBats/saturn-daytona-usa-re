#!/usr/bin/env python3
"""Consolidate multiple singleton retail files into multi-function TU files.

Analyzes BSR/BRA cross-references to find groups of files that were originally
compiled together, merges their retail .s files, and regenerates L3 src files.

Usage:
    # Dry-run: show what would be consolidated
    python tools/consolidate_tu.py --dry-run

    # Full consolidation
    python tools/consolidate_tu.py

    # Manual: merge specific files into a named TU
    python tools/consolidate_tu.py --name sound_dispatch \\
        --files sound_cmd_dispatch sound_write_direct snd_channel_a_body ...
"""

import argparse
import os
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

REIMPL_DIR = Path(__file__).resolve().parent.parent / 'reimpl'
RETAIL_DIR = REIMPL_DIR / 'retail'
SRC_DIR = REIMPL_DIR / 'src'
TOOLS_DIR = Path(__file__).resolve().parent


# ---------------------------------------------------------------------------
# Analysis: find connected components via BSR/BRA cross-references
# ---------------------------------------------------------------------------

def parse_l3_files():
    """Parse all L3 src files for address ranges and BSR/BRA targets."""
    files = {}
    for path in sorted(SRC_DIR.glob("*.s")):
        name = path.stem
        start = end = None
        bsr_targets = []
        bra_targets = []
        with open(path, "r", encoding="utf-8", errors="replace") as f:
            for line in f:
                m = re.search(
                    r'Translation unit:\s*0x([0-9A-Fa-f]+)\s*-\s*0x([0-9A-Fa-f]+)',
                    line)
                if m:
                    start = int(m.group(1), 16)
                    end = int(m.group(2), 16)
                m = re.search(
                    r'/\*\s*(bsr|bra)\s+0x([0-9A-Fa-f]+)\s+\(external\)', line)
                if m:
                    target = int(m.group(2), 16)
                    if m.group(1) == 'bsr':
                        bsr_targets.append(target)
                    else:
                        bra_targets.append(target)
        if start is not None:
            files[name] = {
                'start': start, 'end': end,
                'bsr_targets': bsr_targets, 'bra_targets': bra_targets,
            }
    return files


def build_address_map(files):
    """Return a function that maps an address to the file containing it."""
    sorted_files = sorted(files.items(), key=lambda x: x[1]['start'])
    def find(addr):
        for name, info in sorted_files:
            if info['start'] <= addr < info['end']:
                return name
        return None
    return find


def find_components(files, find_file):
    """Find connected components in the BSR/BRA reference graph."""
    adj = defaultdict(set)
    for name, info in files.items():
        for target in info['bsr_targets'] + info['bra_targets']:
            tf = find_file(target)
            if tf and tf != name:
                adj[name].add(tf)
                adj[tf].add(name)

    visited = set()
    components = []
    for name in files:
        if name in visited or name not in adj:
            continue
        comp = set()
        queue = [name]
        while queue:
            node = queue.pop(0)
            if node in visited:
                continue
            visited.add(node)
            comp.add(node)
            for nb in adj[node]:
                if nb not in visited:
                    queue.append(nb)
        components.append(comp)
    return components


def find_gap_files(component, files):
    """Find files sitting in address gaps between component members."""
    comp_sorted = sorted(component, key=lambda n: files[n]['start'])
    if len(comp_sorted) < 2:
        return set()
    lo = files[comp_sorted[0]]['start']
    hi = files[comp_sorted[-1]]['end']
    return {n for n, info in files.items()
            if n not in component and lo <= info['start'] < hi}


def count_resolvable(component, files, find_file):
    """Count BSR/BRA that would become assembler-resolved after merge."""
    return sum(
        1 for name in component
        for t in files[name]['bsr_targets'] + files[name]['bra_targets']
        if (tf := find_file(t)) and tf in component and tf != name
    )


def choose_name(group, files):
    """Pick a TU name: the file with the largest address span.

    The caller should override this for groups where the auto-name is poor.
    """
    return max(group, key=lambda n: files[n]['end'] - files[n]['start'])


# ---------------------------------------------------------------------------
# Merge & regenerate
# ---------------------------------------------------------------------------

def merge_retail(stems):
    """Merge multiple retail .s files into one string, sorted by address.

    KEEPS all .section directives — the retail build needs them for
    byte-identical placement. The L3 generator handles multi-section
    input and produces a single-section output for free builds.
    """
    parts = []
    for stem in stems:
        path = RETAIL_DIR / f"{stem}.s"
        if not path.exists():
            print(f"  WARNING: {path} not found, skipping")
            continue
        content = path.read_text(encoding='utf-8', errors='replace')
        m = re.search(r'\.section\s+\.text\.FUN_([0-9A-Fa-f]+)', content)
        addr = int(m.group(1), 16) if m else 0
        parts.append((addr, stem, content))

    parts.sort(key=lambda x: x[0])
    return '\n'.join(c.rstrip() for _, _, c in parts) + '\n'


def generate_l3(tu_name):
    """Run generate_l3_tu.py on the merged retail file."""
    cmd = [
        sys.executable,
        str(TOOLS_DIR / 'generate_l3_tu.py'),
        '--input', str(RETAIL_DIR / f'{tu_name}.s'),
        '--output', str(SRC_DIR / f'{tu_name}.s'),
        tu_name,
    ]
    r = subprocess.run(cmd, capture_output=True, text=True,
                       encoding='utf-8', errors='replace')
    if r.returncode != 0:
        print(f"  L3 GENERATION FAILED:\n{r.stderr}")
        return False
    return True


# ---------------------------------------------------------------------------
# Main logic
# ---------------------------------------------------------------------------

def plan_groups(min_branches=2):
    """Analyze and return consolidation plan as a list of dicts.

    Only merges BSR/BRA-connected files (no gap filling). Connected components
    are disjoint by construction, so no file appears in multiple groups.
    """
    files = parse_l3_files()
    find_file = build_address_map(files)
    components = find_components(files, find_file)

    groups = []
    for comp in components:
        if len(comp) < 2:
            continue
        n = count_resolvable(comp, files, find_file)
        if n < min_branches:
            continue

        sorted_comp = sorted(comp, key=lambda name: files[name]['start'])
        tu_name = choose_name(comp, files)

        groups.append({
            'comp': comp,
            'full': comp,  # no gaps — just the component
            'sorted': sorted_comp,
            'tu_name': tu_name,
            'n_branches': n,
            'addr_start': files[sorted_comp[0]]['start'],
            'addr_end': files[sorted_comp[-1]]['end'],
        })

    groups.sort(key=lambda g: g['n_branches'], reverse=True)
    return groups, files


def check_overlap(groups):
    """Detect files that appear in multiple groups' full sets."""
    file_to_groups = defaultdict(list)
    for i, g in enumerate(groups):
        for f in g['full']:
            file_to_groups[f].append(i)
    conflicts = {f: gs for f, gs in file_to_groups.items() if len(gs) > 1}
    return conflicts


def execute_consolidation(groups, files, dry_run=False):
    """Execute the consolidation plan."""
    conflicts = check_overlap(groups)
    if conflicts:
        print(f"\nWARNING: {len(conflicts)} files appear in multiple groups!")
        for f, gs in sorted(conflicts.items()):
            gnames = [groups[i]['tu_name'] for i in gs]
            print(f"  {f} -> groups: {', '.join(gnames)}")
        print("  Resolving: each file goes to the group where it's a BSR/BRA member (not gap)")

    # Track which files have been claimed
    claimed = set()
    stats = {'merged': 0, 'branches': 0, 'groups': 0}

    for g in groups:
        available = g['sorted']
        tu_name = g['tu_name']
        to_remove = [f for f in available if f != tu_name]

        if dry_run:
            print(f"  [{g['n_branches']:3d} branches] {len(available):3d} files -> {tu_name}")
            for f in available:
                tag = " [TU]" if f == tu_name else ""
                print(f"    0x{files[f]['start']:08X} {f}{tag}")
        else:
            print(f"\n--- {tu_name}: {len(available)} files, {g['n_branches']} branches ---")

            # 1. Merge retail
            merged = merge_retail(available)
            retail_out = RETAIL_DIR / f"{tu_name}.s"
            retail_out.write_text(merged, encoding='utf-8', newline='\n')

            # 2. Generate L3
            if not generate_l3(tu_name):
                print(f"  FAILED -- skipping group")
                continue

            # 3. Remove old files
            removed = 0
            for name in to_remove:
                for d in [RETAIL_DIR, SRC_DIR]:
                    p = d / f"{name}.s"
                    if p.exists():
                        p.unlink()
                        removed += 1
            print(f"  OK: merged {len(available)} files, removed {removed} old files")

            stats['merged'] += len(available)
            stats['branches'] += g['n_branches']
            stats['groups'] += 1

    return stats


def main():
    ap = argparse.ArgumentParser(description='TU consolidation tool')
    ap.add_argument('--dry-run', action='store_true',
                    help='Show plan without executing')
    ap.add_argument('--min-branches', type=int, default=2,
                    help='Min resolvable branches per group (default: 2)')
    ap.add_argument('--name', help='Manual: TU name')
    ap.add_argument('--files', nargs='+', help='Manual: file stems to merge')
    args = ap.parse_args()

    if args.name and args.files:
        # Manual mode
        print(f"Manual consolidation: {len(args.files)} files -> {args.name}")
        merged = merge_retail(args.files)
        (RETAIL_DIR / f"{args.name}.s").write_text(merged, encoding='utf-8',
                                                    newline='\n')
        if generate_l3(args.name):
            print("  L3 generated OK")
            for f in args.files:
                if f != args.name:
                    print(f"  Remove: retail/{f}.s, src/{f}.s")
        return

    # Auto mode
    print("Analyzing BSR/BRA cross-references...")
    groups, files = plan_groups(min_branches=args.min_branches)
    print(f"Found {len(groups)} groups ({sum(len(g['full']) for g in groups)} files, "
          f"{sum(g['n_branches'] for g in groups)} branches)")

    stats = execute_consolidation(groups, files, dry_run=args.dry_run)

    print(f"\n{'='*60}")
    if args.dry_run:
        print("DRY RUN complete. Use without --dry-run to execute.")
    else:
        print(f"Done: {stats['groups']} groups, {stats['merged']} files merged, "
              f"{stats['branches']} branches resolved")


if __name__ == '__main__':
    main()
