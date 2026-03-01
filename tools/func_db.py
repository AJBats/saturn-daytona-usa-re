#!/usr/bin/env python3
"""Persistent function database — aggregates all RE tool outputs.

Maintains a JSON database keyed by address, storing per-function metadata:
- name, aliases, tags, library source
- SDK matches, HW register tags, string references
- callers/callees (from call traces)
- confidence level, notes

Each tool can update the database incrementally. The database persists
across sessions and serves as Claude's starting context.

Usage:
  # Import from symbol map (initial population)
  python tools/func_db.py init --map reimpl/build/daytona.map

  # Merge SDK match results
  python tools/func_db.py merge-sdk build/sdk_matches_filtered.json

  # Merge HW tag results
  python tools/func_db.py merge-hw build/hw_tags.json

  # Merge string scan results
  python tools/func_db.py merge-strings build/string_scan_results.txt

  # Query a function
  python tools/func_db.py query 0x060433D0

  # Show statistics
  python tools/func_db.py stats

  # Export summary
  python tools/func_db.py export --output build/func_summary.txt
"""

import os
import re
import sys
import json
from collections import defaultdict

DB_PATH = 'build/function_db.json'


def load_db(path=DB_PATH):
    """Load or create the function database."""
    if os.path.exists(path):
        with open(path) as f:
            return json.load(f)
    return {'functions': {}, 'metadata': {'version': 1}}


def save_db(db, path=DB_PATH):
    """Save the function database."""
    os.makedirs(os.path.dirname(path) or '.', exist_ok=True)
    with open(path, 'w') as f:
        json.dump(db, f, indent=2, sort_keys=True)


def normalize_addr(addr):
    """Normalize address to 0x-prefixed hex string."""
    if isinstance(addr, int):
        return f"0x{addr:08X}"
    if isinstance(addr, str):
        addr = addr.strip()
        if addr.startswith('0x') or addr.startswith('0X'):
            return f"0x{int(addr, 16):08X}"
        return f"0x{int(addr, 16):08X}"
    return str(addr)


def get_or_create(db, addr_key):
    """Get or create a function entry."""
    if addr_key not in db['functions']:
        db['functions'][addr_key] = {
            'name': None,
            'tags': [],
            'sdk_matches': [],
            'hw_tags': [],
            'strings': [],
            'notes': [],
        }
    return db['functions'][addr_key]


def cmd_init(args):
    """Initialize database from symbol map (replaces existing DB)."""
    db = {'functions': {}, 'metadata': {'version': 1}}
    count = 0

    with open(args.map) as f:
        for line in f:
            line = line.strip()
            # Standard format: 0xADDR name
            m = re.match(r'0x([0-9a-fA-F]+)\s+(\S+)', line)
            if m:
                addr = int(m.group(1), 16)
                name = m.group(2)
                if name.startswith('PROVIDE'):
                    continue
                # Only include WRAM-H range (code area)
                if not (0x06004000 <= addr <= 0x06100000):
                    continue

                addr_key = normalize_addr(addr)
                entry = get_or_create(db, addr_key)
                if entry['name'] is None:
                    entry['name'] = name
                count += 1

    save_db(db, args.db)
    print(f"Initialized {count} functions from {args.map}")
    print(f"Database: {args.db}")


def cmd_merge_sdk(args):
    """Merge SDK signature match results."""
    db = load_db(args.db)

    with open(args.json_file) as f:
        sdk_data = json.load(f)

    count = 0
    for match_type in ('exact_matches', 'fuzzy_matches'):
        matches = sdk_data.get(match_type, {})
        for sdk_name, info in matches.items():
            if match_type == 'exact_matches':
                addrs = info.get('addresses', [])
                library = info.get('library', '?')
                similarity = 1.0
            else:
                match_entries = info.get('matches', [])
                addrs = [m['address'] for m in match_entries[:1]]
                library = info.get('library', '?')
                similarity = float(match_entries[0]['similarity']) if match_entries else 0

            for addr_str in addrs:
                addr_key = normalize_addr(addr_str)
                entry = get_or_create(db, addr_key)

                # Add SDK match
                sdk_entry = {
                    'sdk_name': sdk_name,
                    'library': library,
                    'match_type': 'exact' if match_type == 'exact_matches' else 'fuzzy',
                    'similarity': similarity,
                    'num_hits': len(addrs),
                }
                # Avoid duplicates
                existing = [s for s in entry['sdk_matches'] if s['sdk_name'] == sdk_name]
                if not existing:
                    entry['sdk_matches'].append(sdk_entry)
                    count += 1

                # Add 'sdk' tag
                if 'sdk' not in entry['tags']:
                    entry['tags'].append('sdk')

    save_db(db, args.db)
    print(f"Merged {count} SDK matches into database")


def _find_containing(db, addr):
    """Find the DB entry whose address is closest <= addr."""
    import bisect
    all_addrs = sorted(int(k, 16) for k in db['functions'].keys())
    idx = bisect.bisect_right(all_addrs, addr) - 1
    if idx >= 0 and addr - all_addrs[idx] < 0x2000:
        return normalize_addr(all_addrs[idx])
    return None


def cmd_merge_hw(args):
    """Merge HW register tag results."""
    db = load_db(args.db)

    with open(args.json_file) as f:
        hw_data = json.load(f)

    # Build name→addr lookup from DB
    name_to_addr = {}
    for addr_key, entry in db['functions'].items():
        name = entry.get('name', '')
        if name:
            name_to_addr[name] = addr_key

    count = 0
    functions = hw_data.get('functions', {})
    for tu_name, info in functions.items():
        addr_key = name_to_addr.get(tu_name)

        # For FUN_XXXXXXXX names, extract address directly
        if not addr_key:
            m = re.match(r'FUN_([0-9a-fA-F]+)', tu_name)
            if m:
                addr = int(m.group(1), 16)
                addr_key = normalize_addr(addr)
                if addr_key not in db['functions']:
                    addr_key = _find_containing(db, addr)

        if not addr_key:
            continue

        entry = get_or_create(db, addr_key)
        tag_set = info.get('tag_set', [])
        for tag in tag_set:
            if tag not in entry['hw_tags']:
                entry['hw_tags'].append(tag)
                count += 1
        if tag_set and 'hw_access' not in entry['tags']:
            entry['tags'].append('hw_access')

    save_db(db, args.db)
    print(f"Merged {count} HW tags into database")


def cmd_merge_strings(args):
    """Merge string scan results from text output."""
    db = load_db(args.db)

    count = 0
    with open(args.text_file, 'r') as f:
        for line in f:
            # Format: "  0x060456D0  ' TO SKIP REPLAY   '"
            m = re.match(r'\s+0x([0-9a-fA-F]+)\s+[\'"](.+?)[\'"]', line)
            if m:
                addr = int(m.group(1), 16)
                string_val = m.group(2)
                addr_key = normalize_addr(addr)

                entry = get_or_create(db, addr_key)
                if string_val not in entry['strings']:
                    entry['strings'].append(string_val)
                    count += 1
                if 'string_data' not in entry['tags']:
                    entry['tags'].append('string_data')

    save_db(db, args.db)
    print(f"Merged {count} string references into database")


def cmd_query(args):
    """Query a function by address."""
    db = load_db(args.db)
    addr_key = normalize_addr(args.address)

    entry = db['functions'].get(addr_key)
    if not entry:
        # Try nearby addresses
        target = int(args.address, 0)
        for key, val in db['functions'].items():
            key_addr = int(key, 16)
            if abs(key_addr - target) < 0x100:
                print(f"Near match: {key}")
                entry = val
                addr_key = key
                break

    if not entry:
        print(f"No entry for {addr_key}")
        return

    print(f"\n{'='*60}")
    print(f"Address: {addr_key}")
    print(f"Name:    {entry.get('name', '?')}")
    print(f"Tags:    {', '.join(entry.get('tags', []))}")

    if entry.get('sdk_matches'):
        print(f"\nSDK Matches:")
        for s in entry['sdk_matches']:
            sim = f" ({s['similarity']:.3f})" if s['match_type'] == 'fuzzy' else ''
            print(f"  {s['sdk_name']} [{s['library']}] {s['match_type']}{sim}")

    if entry.get('hw_tags'):
        print(f"\nHW Tags: {', '.join(entry['hw_tags'])}")

    if entry.get('strings'):
        print(f"\nStrings:")
        for s in entry['strings'][:10]:
            print(f"  '{s}'")

    if entry.get('notes'):
        print(f"\nNotes:")
        for n in entry['notes']:
            print(f"  {n}")


def cmd_stats(args):
    """Show database statistics."""
    db = load_db(args.db)
    funcs = db['functions']

    total = len(funcs)
    named = sum(1 for f in funcs.values() if f.get('name') and not f['name'].startswith(('FUN_', 'sym_', 'DAT_', 'loc_')))
    with_sdk = sum(1 for f in funcs.values() if f.get('sdk_matches'))
    with_hw = sum(1 for f in funcs.values() if f.get('hw_tags'))
    with_strings = sum(1 for f in funcs.values() if f.get('strings'))
    with_tags = sum(1 for f in funcs.values() if f.get('tags'))

    # Tag distribution
    tag_counts = defaultdict(int)
    for f in funcs.values():
        for t in f.get('tags', []):
            tag_counts[t] += 1

    # SDK library distribution
    lib_counts = defaultdict(int)
    for f in funcs.values():
        for s in f.get('sdk_matches', []):
            lib_counts[s['library']] += 1

    print(f"\n{'='*50}")
    print(f"Function Database Statistics")
    print(f"{'='*50}")
    print(f"Total entries:          {total}")
    print(f"Human-named:            {named} ({100*named/max(total,1):.1f}%)")
    print(f"With SDK matches:       {with_sdk}")
    print(f"With HW tags:           {with_hw}")
    print(f"With string data:       {with_strings}")
    print(f"With any tag:           {with_tags}")

    if tag_counts:
        print(f"\nTag distribution:")
        for tag, count in sorted(tag_counts.items(), key=lambda x: -x[1]):
            print(f"  {tag:<20s}  {count:>5d}")

    if lib_counts:
        print(f"\nSDK library matches:")
        for lib, count in sorted(lib_counts.items(), key=lambda x: -x[1]):
            print(f"  {lib:<20s}  {count:>5d}")


def cmd_export(args):
    """Export a human-readable summary."""
    db = load_db(args.db)

    lines = []
    lines.append("# Function Database Export")
    lines.append(f"# Entries: {len(db['functions'])}")
    lines.append("")

    for addr_key in sorted(db['functions'].keys()):
        entry = db['functions'][addr_key]
        name = entry.get('name', '?')
        tags = ', '.join(entry.get('tags', []))
        sdk = ', '.join(s['sdk_name'] for s in entry.get('sdk_matches', []))
        hw = ', '.join(entry.get('hw_tags', []))

        parts = [f"{addr_key}  {name}"]
        if tags:
            parts.append(f"[{tags}]")
        if sdk:
            parts.append(f"sdk:{sdk}")
        if hw:
            parts.append(f"hw:{hw}")
        lines.append('  '.join(parts))

    output = '\n'.join(lines)
    if args.output:
        with open(args.output, 'w') as f:
            f.write(output)
        print(f"Exported to {args.output}")
    else:
        print(output)


def main():
    import argparse
    parser = argparse.ArgumentParser(description='Persistent function database')
    parser.add_argument('--db', default=DB_PATH, help='Database file path')
    subparsers = parser.add_subparsers(dest='command')

    # init
    p = subparsers.add_parser('init', help='Initialize from symbol map')
    p.add_argument('--map', default='reimpl/build/daytona.map', help='Symbol map file')

    # merge-sdk
    p = subparsers.add_parser('merge-sdk', help='Merge SDK match results')
    p.add_argument('json_file', help='SDK match JSON file')

    # merge-hw
    p = subparsers.add_parser('merge-hw', help='Merge HW tag results')
    p.add_argument('json_file', help='HW tag JSON file')

    # merge-strings
    p = subparsers.add_parser('merge-strings', help='Merge string scan results')
    p.add_argument('text_file', help='String scan text output file')

    # query
    p = subparsers.add_parser('query', help='Query a function')
    p.add_argument('address', help='Function address (hex)')

    # stats
    subparsers.add_parser('stats', help='Show statistics')

    # export
    p = subparsers.add_parser('export', help='Export summary')
    p.add_argument('--output', '-o', help='Output file')

    args = parser.parse_args()

    if args.command == 'init':
        cmd_init(args)
    elif args.command == 'merge-sdk':
        cmd_merge_sdk(args)
    elif args.command == 'merge-hw':
        cmd_merge_hw(args)
    elif args.command == 'merge-strings':
        cmd_merge_strings(args)
    elif args.command == 'query':
        cmd_query(args)
    elif args.command == 'stats':
        cmd_stats(args)
    elif args.command == 'export':
        cmd_export(args)
    else:
        parser.print_help()


if __name__ == '__main__':
    main()
