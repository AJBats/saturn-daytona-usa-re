#!/usr/bin/env python3
"""Convert all source files from ELF (sh-elf-as) syntax to COFF (Cygnus AS) syntax.

One-shot migration — after this, source files are Cygnus-native and no
preprocessor is needed.

Changes:
  .2byte  -> .short
  .4byte  -> .long
  bf/s    -> bf.s
  bt/s    -> bt.s
  muls.w  -> muls
  mulu.w  -> mulu
  .section .text.startup -> .text  (only _start.s)
"""

import glob
import os
import sys

REIMPL = os.path.join(os.path.dirname(__file__), '..', 'reimpl')

REPLACEMENTS = [
    ('.2byte', '.short'),
    ('.4byte', '.long'),
    ('bf/s', 'bf.s'),
    ('bt/s', 'bt.s'),
    ('muls.w', 'muls'),
    ('mulu.w', 'mulu'),
    ('.section .text.startup', '\t.text'),
]


def convert_file(path):
    with open(path, 'r') as f:
        content = f.read()

    original = content
    for old, new in REPLACEMENTS:
        content = content.replace(old, new)

    if content != original:
        with open(path, 'w') as f:
            f.write(content)
        return True
    return False


def main():
    patterns = [
        os.path.join(REIMPL, 'src', '*.s'),
        os.path.join(REIMPL, 'retail', '*.s'),
        os.path.join(REIMPL, 'src', 'mods', '*.s'),
        os.path.join(REIMPL, 'src', 'mods', '*.c'),
        os.path.join(REIMPL, 'src', 'mods', 're_tests', '*.s'),
        os.path.join(REIMPL, 'src', 'mods', 'retests', '*.c'),  # future-proof
    ]

    files = []
    for p in patterns:
        files.extend(glob.glob(p))

    changed = 0
    for f in sorted(files):
        if convert_file(f):
            changed += 1

    print(f'{changed}/{len(files)} files converted')


if __name__ == '__main__':
    main()
