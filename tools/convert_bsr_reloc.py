#!/usr/bin/env python3
"""
Convert hardcoded BSR/BRA .byte pairs to .reloc + .2byte directives.

Scans reimpl/src/*.s for patterns like:
    .byte 0xBX, 0xYY    /* bsr 0xADDRESS (comment) */
    .byte 0xAX, 0xYY    /* bra 0xADDRESS (comment) */

Converts to:
    .reloc ., R_SH_IND12W, symbol_name - 4
    .2byte 0xB000        /* bsr symbol_name (linker-resolved) */

The linker fills in the correct 12-bit displacement at link time.

Usage:
    python tools/convert_bsr_reloc.py                    # dry run (show changes)
    python tools/convert_bsr_reloc.py --apply            # apply changes
    python tools/convert_bsr_reloc.py --apply FILE.s     # apply to one file
"""

import re
import os
import sys
import glob

REIMPL_DIR = os.path.join(os.path.dirname(__file__), '..', 'reimpl')
SRC_DIR = os.path.join(REIMPL_DIR, 'src')
RETAIL_DIR = os.path.join(REIMPL_DIR, 'retail')


def build_address_to_symbol_map():
    """Build map from address -> global symbol name.

    Two sources:
    1. Section start address -> first named global (for renamed functions)
    2. FUN_XXXXXXXX globals -> address extracted from hex in name (for sub-functions)
    """
    symbols = {}
    for d in [SRC_DIR, RETAIL_DIR]:
        for filepath in sorted(glob.glob(os.path.join(d, '*.s'))):
            section_addr = None
            with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
                for line in f:
                    line = line.strip()
                    m = re.match(r'\.section\s+\.text\.(?:FUN_)?([0-9A-Fa-f]+)', line)
                    if m:
                        section_addr = int(m.group(1), 16)
                    m = re.match(r'\.global\s+(\w+)', line)
                    if m:
                        sym = m.group(1)
                        # Skip data/sublabel symbols — we want function entries
                        if sym.startswith('DAT_') or sym.startswith('sym_'):
                            continue
                        # Named function at section start
                        if section_addr:
                            symbols[section_addr] = sym
                            section_addr = None
                        # FUN_XXXXXXXX sub-function — extract address from name
                        fm = re.match(r'FUN_([0-9A-Fa-f]{8})$', sym)
                        if fm:
                            addr = int(fm.group(1), 16)
                            if addr not in symbols:
                                symbols[addr] = sym
    return symbols


# Pattern: .byte 0xBX, 0xYY  /* bsr 0xADDR ... */ or .byte 0xAX, 0xYY /* bra 0xADDR ... */
BSR_BRA_RE = re.compile(
    r'^(\s*)\.byte\s+0x([ABab][0-9A-Fa-f]),\s*0x([0-9A-Fa-f]{2})'
    r'\s+/\*\s*(bsr|bra)\s+(?:0x)?([0-9A-Fa-f]+)\b'
    r'(.*?)\*/'
)


def convert_file(filepath, addr_map, apply=False):
    """Convert BSR/BRA .byte pairs in a single file. Returns (changes, errors)."""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    changes = []
    errors = []
    new_lines = []

    for i, line in enumerate(lines):
        m = BSR_BRA_RE.match(line)
        if m:
            indent = m.group(1)
            hi_byte = m.group(2).upper()
            lo_byte = m.group(3).upper()
            branch_type = m.group(4).lower()  # bsr or bra
            target_addr = int(m.group(5), 16)

            # Look up target symbol
            sym = addr_map.get(target_addr)
            if sym is None:
                errors.append(f"  {os.path.basename(filepath)}:{i+1}: no symbol for target 0x{target_addr:08X}")
                new_lines.append(line)
                continue

            # BSR = 0xBnnn, BRA = 0xAnnn
            opcode_base = '0xB000' if branch_type == 'bsr' else '0xA000'

            reloc_line = f"{indent}.reloc ., R_SH_IND12W, {sym} - 4\n"
            byte_line = f"{indent}.2byte {opcode_base}{' ' * (10 - len(opcode_base))}/* {branch_type} {sym} (linker-resolved) */\n"

            new_lines.append(reloc_line)
            new_lines.append(byte_line)
            changes.append(f"  {os.path.basename(filepath)}:{i+1}: {branch_type} 0x{target_addr:08X} -> {sym}")
        else:
            new_lines.append(line)

    if apply and changes:
        with open(filepath, 'w', encoding='utf-8', newline='\n') as f:
            f.writelines(new_lines)

    return changes, errors


def main():
    apply = '--apply' in sys.argv
    args = [a for a in sys.argv[1:] if not a.startswith('--')]

    addr_map = build_address_to_symbol_map()
    print(f"Symbol map: {len(addr_map)} functions")

    # Determine which files to process
    if args:
        files = args
    else:
        files = sorted(glob.glob(os.path.join(SRC_DIR, '*.s')))
        # Also check mods subdirectories
        files += sorted(glob.glob(os.path.join(SRC_DIR, 'mods', '*.s')))
        files += sorted(glob.glob(os.path.join(SRC_DIR, 'mods', 're_tests', '*.s')))

    total_changes = 0
    total_errors = 0

    for filepath in files:
        if not os.path.exists(filepath):
            print(f"  SKIP: {filepath} not found")
            continue
        changes, errors = convert_file(filepath, addr_map, apply=apply)
        total_changes += len(changes)
        total_errors += len(errors)
        for c in changes:
            print(c)
        for e in errors:
            print(f"  ERROR: {e}")

    print(f"\n{'Applied' if apply else 'Would convert'}: {total_changes} BSR/BRA pairs")
    if total_errors:
        print(f"Errors (no symbol found): {total_errors}")

    if not apply and total_changes > 0:
        print("\nRun with --apply to make changes.")


if __name__ == '__main__':
    main()
