#!/usr/bin/env python3
"""Find duplicate function definitions across reimpl source files."""

import os
import re

REIMPL_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "reimpl", "src")

def main():
    func_locations = {}  # func_name -> [(file, line)]

    for fname in sorted(os.listdir(REIMPL_DIR)):
        if not fname.endswith('.c'):
            continue
        filepath = os.path.join(REIMPL_DIR, fname)
        with open(filepath, 'r', errors='replace') as f:
            in_if0 = False
            for i, line in enumerate(f, 1):
                stripped = line.strip()
                if stripped == '#if 0':
                    in_if0 = True
                elif stripped == '#endif':
                    in_if0 = False
                if in_if0:
                    continue
                if stripped.startswith('extern'):
                    continue
                # Match function definitions
                m = re.match(r'^(?:(?:unsigned\s+)?(?:long\s+long|int|short|char|void)(?:\s*\*)*\s+)?(FUN_[0-9A-Fa-f]+)\s*\(', stripped)
                if m:
                    func = m.group(1).upper()
                    if func not in func_locations:
                        func_locations[func] = []
                    func_locations[func].append((fname, i))

    # Find duplicates
    dups = {k: v for k, v in func_locations.items() if len(v) > 1}

    if dups:
        print(f"Found {len(dups)} duplicate function definitions:\n")
        for func in sorted(dups):
            locations = dups[func]
            print(f"  {func}:")
            for fname, line in locations:
                print(f"    {fname}:{line}")
    else:
        print("No duplicate function definitions found.")

if __name__ == "__main__":
    main()
