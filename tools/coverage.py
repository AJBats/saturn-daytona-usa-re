#!/usr/bin/env python3
"""Coverage statistics — what % of code has been analyzed/named/verified.

Reports coverage metrics across multiple dimensions:
  - Function naming (human-readable vs FUN_/sym_/DAT_ placeholders)
  - L3 uplift (mnemonic disassembly vs raw bytes)
  - SDK identification (matched against SGL library signatures)
  - HW register classification (tagged by hardware subsystem)
  - String data identification
  - Code vs data classification (functions vs data tables)
  - Byte coverage (what fraction of APROG.BIN is in known functions)

Usage:
  python tools/coverage.py
  python tools/coverage.py --map reimpl/build/daytona.map --binary reimpl/build/APROG.BIN
  python tools/coverage.py --db build/function_db.json
  python tools/coverage.py --output build/coverage.json
"""

import os
import re
import sys
import json
from collections import defaultdict


def load_map(map_path):
    """Load symbol map, return dict of addr -> name for code-range symbols."""
    symbols = {}
    with open(map_path) as f:
        for line in f:
            line = line.strip()
            m = re.match(r'0x([0-9a-fA-F]+)\s+(\S+)', line)
            if m:
                addr = int(m.group(1), 16)
                name = m.group(2)
                if name.startswith('PROVIDE'):
                    continue
                symbols[addr] = name
    return symbols


def classify_name(name):
    """Classify a symbol name into categories."""
    if name.startswith('FUN_'):
        return 'unnamed_function'
    elif name.startswith('sym_'):
        return 'unnamed_sublabel'
    elif name.startswith('DAT_'):
        return 'unnamed_data'
    elif name.startswith('loc_'):
        return 'unnamed_location'
    else:
        return 'named'


def count_src_files(src_dir):
    """Count source files by type in src/ directory."""
    stats = {'total': 0, 'asm': 0, 'c': 0, 'data_fallback': 0}
    for f in os.listdir(src_dir):
        if f.endswith('.s'):
            stats['total'] += 1
            stats['asm'] += 1
        elif f.endswith('.c'):
            stats['total'] += 1
            stats['c'] += 1
    return stats


def compute_function_sizes(symbols, binary_size, base_addr=0x06004000):
    """Estimate function sizes from symbol spacing."""
    code_range = base_addr + binary_size
    sorted_addrs = sorted(a for a in symbols.keys() if base_addr <= a < code_range)

    sizes = {}
    for i, addr in enumerate(sorted_addrs):
        if i + 1 < len(sorted_addrs):
            sizes[addr] = sorted_addrs[i + 1] - addr
        else:
            sizes[addr] = code_range - addr
    return sizes


def main():
    import argparse
    parser = argparse.ArgumentParser(description='Coverage statistics')
    parser.add_argument('--map', default='reimpl/build/daytona.map',
                        help='Symbol map file')
    parser.add_argument('--binary', default='reimpl/build/APROG.BIN',
                        help='Binary file for size calculation')
    parser.add_argument('--src-dir', default='reimpl/src',
                        help='Source directory')
    parser.add_argument('--retail-dir', default='reimpl/retail',
                        help='Retail directory')
    parser.add_argument('--db', default='build/function_db.json',
                        help='Function database (if available)')
    parser.add_argument('--output', '-o', help='Output JSON file')
    args = parser.parse_args()

    # Load data
    symbols = load_map(args.map)
    binary_size = os.path.getsize(args.binary) if os.path.exists(args.binary) else 0

    # Function database (optional)
    func_db = None
    if os.path.exists(args.db):
        with open(args.db) as f:
            func_db = json.load(f)

    # Source file counts
    src_stats = count_src_files(args.src_dir) if os.path.isdir(args.src_dir) else {}
    retail_count = len([f for f in os.listdir(args.retail_dir) if f.endswith('.s')]) if os.path.isdir(args.retail_dir) else 0

    # Symbol classification
    base_addr = 0x06004000
    code_symbols = {a: n for a, n in symbols.items() if base_addr <= a < base_addr + binary_size}

    name_classes = defaultdict(int)
    for name in code_symbols.values():
        cls = classify_name(name)
        name_classes[cls] += 1

    total_symbols = len(code_symbols)
    named = name_classes.get('named', 0)
    unnamed_func = name_classes.get('unnamed_function', 0)
    unnamed_sub = name_classes.get('unnamed_sublabel', 0)
    unnamed_data = name_classes.get('unnamed_data', 0)
    unnamed_loc = name_classes.get('unnamed_location', 0)

    # Function size analysis
    sizes = compute_function_sizes(code_symbols, binary_size, base_addr)
    total_bytes_covered = sum(sizes.values())
    named_bytes = sum(sizes.get(a, 0) for a, n in code_symbols.items() if classify_name(n) == 'named')

    # DB enrichment stats
    db_stats = {}
    if func_db:
        funcs = func_db.get('functions', {})
        db_stats = {
            'total_entries': len(funcs),
            'with_sdk': sum(1 for f in funcs.values() if f.get('sdk_matches')),
            'with_hw': sum(1 for f in funcs.values() if f.get('hw_tags')),
            'with_strings': sum(1 for f in funcs.values() if f.get('strings')),
            'with_any_tag': sum(1 for f in funcs.values() if f.get('tags')),
        }

    # Print report
    print(f"\n{'='*60}")
    print(f"  COVERAGE STATISTICS")
    print(f"{'='*60}")
    print(f"\n  Binary: {args.binary} ({binary_size:,} bytes)")
    print(f"  Base address: 0x{base_addr:08X}")
    print(f"  Symbol map: {total_symbols} symbols in code range")

    print(f"\n--- Symbol Naming ---")
    print(f"  Human-named:      {named:>5d}  ({100*named/max(total_symbols,1):5.1f}%)")
    print(f"  FUN_ (unnamed):   {unnamed_func:>5d}  ({100*unnamed_func/max(total_symbols,1):5.1f}%)")
    print(f"  sym_ (sublabels): {unnamed_sub:>5d}  ({100*unnamed_sub/max(total_symbols,1):5.1f}%)")
    print(f"  DAT_ (data):      {unnamed_data:>5d}  ({100*unnamed_data/max(total_symbols,1):5.1f}%)")
    print(f"  loc_ (locations): {unnamed_loc:>5d}  ({100*unnamed_loc/max(total_symbols,1):5.1f}%)")
    print(f"  Total:            {total_symbols:>5d}")

    print(f"\n--- Byte Coverage ---")
    print(f"  Total code bytes: {total_bytes_covered:>8,d}")
    print(f"  Named bytes:      {named_bytes:>8,d}  ({100*named_bytes/max(total_bytes_covered,1):5.1f}%)")
    print(f"  Unnamed bytes:    {total_bytes_covered - named_bytes:>8,d}  ({100*(total_bytes_covered-named_bytes)/max(total_bytes_covered,1):5.1f}%)")

    print(f"\n--- Source Files ---")
    if src_stats:
        print(f"  L3 assembly:      {src_stats.get('asm', 0):>5d}")
        print(f"  C reimpl:         {src_stats.get('c', 0):>5d}")
        print(f"  Total src/:       {src_stats.get('total', 0):>5d}")
    if retail_count:
        print(f"  Retail .s files:  {retail_count:>5d}")

    if db_stats:
        print(f"\n--- Function Database Enrichment ---")
        print(f"  DB entries:       {db_stats['total_entries']:>5d}")
        print(f"  SDK identified:   {db_stats['with_sdk']:>5d}")
        print(f"  HW tagged:        {db_stats['with_hw']:>5d}")
        print(f"  String data:      {db_stats['with_strings']:>5d}")
        print(f"  Any tag:          {db_stats['with_any_tag']:>5d}")

    # Size distribution
    func_sizes = [(a, sizes[a]) for a in sizes if classify_name(code_symbols[a]) in ('named', 'unnamed_function')]
    if func_sizes:
        func_sizes.sort(key=lambda x: -x[1])
        print(f"\n--- Largest Functions (top 10) ---")
        for addr, sz in func_sizes[:10]:
            name = code_symbols[addr]
            print(f"  0x{addr:08X}  {name:<40s}  {sz:>6d} bytes")

    # Save JSON
    if args.output:
        output = {
            'binary_size': binary_size,
            'total_symbols': total_symbols,
            'naming': {
                'named': named,
                'unnamed_function': unnamed_func,
                'unnamed_sublabel': unnamed_sub,
                'unnamed_data': unnamed_data,
                'unnamed_location': unnamed_loc,
                'named_pct': round(100 * named / max(total_symbols, 1), 1),
            },
            'byte_coverage': {
                'total_bytes': total_bytes_covered,
                'named_bytes': named_bytes,
                'named_pct': round(100 * named_bytes / max(total_bytes_covered, 1), 1),
            },
            'source_files': src_stats,
            'retail_files': retail_count,
            'db_enrichment': db_stats,
        }
        os.makedirs(os.path.dirname(args.output) or '.', exist_ok=True)
        with open(args.output, 'w') as f:
            json.dump(output, f, indent=2)
        print(f"\nWrote {args.output}")


if __name__ == '__main__':
    main()
