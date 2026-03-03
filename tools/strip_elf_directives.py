#!/usr/bin/env python3
"""Strip ELF-specific directives (.type, .size) from all .s files.

These are metadata annotations that don't affect code generation.
Cygnus AS (COFF) doesn't support them, and sh-elf-as works fine without them.
"""

import os
import re
import sys

def process_file(path):
    with open(path, 'r') as f:
        content = f.read()

    # Remove .type lines: "    .type func_name, @function"
    new_content = re.sub(
        r'^\s*\.type\s+\S+,\s*@\S+\s*\n',
        '',
        content,
        flags=re.MULTILINE
    )

    # Remove .size lines: "    .size func_name, . - func_name"
    new_content = re.sub(
        r'^\s*\.size\s+\S+,\s*.+\n',
        '',
        new_content,
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
    unchanged = 0

    for subdir in ['src', 'retail', 'src/mods', 'src/mods/re_tests']:
        dir_path = os.path.join(reimpl_dir, subdir)
        if not os.path.isdir(dir_path):
            continue
        for fname in sorted(os.listdir(dir_path)):
            if not fname.endswith('.s'):
                continue
            fpath = os.path.join(dir_path, fname)
            if process_file(fpath):
                changed += 1
            else:
                unchanged += 1

    print(f"Changed: {changed} files")
    print(f"Unchanged: {unchanged} files")

if __name__ == '__main__':
    main()
