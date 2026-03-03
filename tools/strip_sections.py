#!/usr/bin/env python3
"""Strip .section .text.FUN_* directives -> .text in all src/ and retail/ .s files.

Part of the Cygnus AS migration: COFF has 8-char section name limit,
so per-function sections won't work. We use plain .text and control
function order via sorted .o filenames on the LD command line.

_start.s uses .text.startup and is left unchanged.
"""

import os
import re
import sys

def process_file(path):
    with open(path, 'r') as f:
        content = f.read()

    # Replace .section .text.FUN_XXXXXXXX with .text
    new_content = re.sub(
        r'^\s*\.section\s+\.text\.FUN_[0-9A-Fa-f]+\s*$',
        '\t.text',
        content,
        flags=re.MULTILINE
    )

    if new_content != content:
        with open(path, 'w') as f:
            f.write(new_content)
        return True
    return False

def main():
    reimpl_dir = os.path.join(os.path.dirname(__file__), '..', 'reimpl')

    changed = 0
    skipped = 0

    for subdir in ['src', 'retail']:
        dir_path = os.path.join(reimpl_dir, subdir)
        for fname in sorted(os.listdir(dir_path)):
            if not fname.endswith('.s'):
                continue
            if fname == '_start.s':
                skipped += 1
                continue

            fpath = os.path.join(dir_path, fname)
            if process_file(fpath):
                changed += 1
            else:
                skipped += 1

    # Also check src/mods/ and src/mods/re_tests/
    for mods_dir in ['src/mods', 'src/mods/re_tests']:
        dir_path = os.path.join(reimpl_dir, mods_dir)
        if not os.path.isdir(dir_path):
            continue
        for fname in sorted(os.listdir(dir_path)):
            if not fname.endswith('.s'):
                continue
            fpath = os.path.join(dir_path, fname)
            if process_file(fpath):
                changed += 1

    print(f"Changed: {changed} files")
    print(f"Skipped: {skipped} files")

if __name__ == '__main__':
    main()
