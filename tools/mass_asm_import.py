#!/usr/bin/env python3
"""mass_asm_import.py -- Mass-import original ASM bytes for all C lifts with wrong bytes.

Compares compiled binary with original, finds all functions that produce
incorrect code, then wraps their C definitions in #if 0 and adds __asm__
import blocks with exact original bytes.

Usage:
    python tools/mass_asm_import.py                # Dry run (report only)
    python tools/mass_asm_import.py --apply        # Apply changes
    python tools/mass_asm_import.py --apply --limit 50  # Apply first 50
"""

import os
import re
import struct
import sys
from collections import defaultdict

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ELF_FILE = os.path.join(PROJ, "reimpl", "build", "daytona.elf")
ORIG_BIN = os.path.join(PROJ, "build", "disc", "files", "APROG.BIN")
OUR_BIN = os.path.join(PROJ, "reimpl", "build", "APROG.BIN")
APROG_S = os.path.join(PROJ, "build", "aprog.s")
SRC_DIR = os.path.join(PROJ, "reimpl", "src")
BASE_ADDR = 0x06003000

APPLY = "--apply" in sys.argv
LIMIT = None
for i, arg in enumerate(sys.argv):
    if arg == "--limit" and i + 1 < len(sys.argv):
        LIMIT = int(sys.argv[i + 1])


def parse_elf_sections():
    """Parse ELF section headers with names."""
    with open(ELF_FILE, "rb") as f:
        magic = f.read(4)
        assert magic == b'\x7fELF'
        f.read(1)  # ei_class
        ei_data = struct.unpack('B', f.read(1))[0]
        endian = '>' if ei_data == 2 else '<'

        f.seek(32)
        e_shoff = struct.unpack(endian + 'I', f.read(4))[0]
        f.seek(46)
        e_shentsize = struct.unpack(endian + 'H', f.read(2))[0]
        e_shnum = struct.unpack(endian + 'H', f.read(2))[0]
        e_shstrndx = struct.unpack(endian + 'H', f.read(2))[0]

        # Read string table
        f.seek(e_shoff + e_shstrndx * e_shentsize + 16)
        strtab_off = struct.unpack(endian + 'I', f.read(4))[0]
        strtab_size = struct.unpack(endian + 'I', f.read(4))[0]
        f.seek(strtab_off)
        strtab = f.read(strtab_size)

        sections = []
        for i in range(e_shnum):
            f.seek(e_shoff + i * e_shentsize)
            sh_data = f.read(e_shentsize)
            sh_name_idx, sh_type, sh_flags, sh_addr, sh_offset, sh_size = struct.unpack(
                endian + 'IIIIII', sh_data[:24])

            name_end = strtab.index(b'\0', sh_name_idx) if sh_name_idx < len(strtab) else sh_name_idx
            name = strtab[sh_name_idx:name_end].decode('ascii', errors='replace')

            if sh_type == 1 and (sh_flags & 2) and sh_size > 0:
                if BASE_ADDR <= sh_addr < 0x060A0000:
                    sections.append((name, sh_addr, sh_size))

    return sections


def find_wrong_functions():
    """Compare binary to find functions with incorrect bytes."""
    orig = open(ORIG_BIN, "rb").read()
    ours = open(OUR_BIN, "rb").read()
    sections = parse_elf_sections()

    wrong = []
    for name, addr, size in sections:
        off = addr - BASE_ADDR
        if off < 0 or off + size > len(orig) or off + size > len(ours):
            continue

        o = orig[off:off + size]
        u = ours[off:off + size]
        if o != u:
            diff_count = sum(1 for a, b in zip(o, u) if a != b)
            # Extract function name from section name
            # Section names like .func_FUN_06003000 or .text.FUN_06003000
            m = re.search(r'(FUN_[0-9a-fA-F]+)', name)
            if m:
                func_name = m.group(1).upper()
                wrong.append((func_name, addr, size, diff_count))

    return wrong


def parse_aprog_functions(targets):
    """Extract byte sequences from aprog.s for target functions."""
    target_set = set(t.upper() for t in targets)
    functions = {}
    current_func = None
    current_bytes = []

    with open(APROG_S, "r") as f:
        for line in f:
            m = re.match(r'^(FUN_[0-9a-fA-F]+):', line)
            if m:
                if current_func and current_bytes:
                    functions[current_func] = current_bytes
                name = m.group(1).upper()
                if name in target_set:
                    current_func = name
                    current_bytes = []
                else:
                    current_func = None
                    current_bytes = []
                continue

            if current_func:
                m = re.match(r'\s+\.byte\s+0x([0-9a-fA-F]+),\s*0x([0-9a-fA-F]+)', line)
                if m:
                    current_bytes.append(int(m.group(1), 16))
                    current_bytes.append(int(m.group(2), 16))

    if current_func and current_bytes:
        functions[current_func] = current_bytes

    return functions


def generate_asm_block(func_name, byte_data):
    """Generate __asm__ import block."""
    func_upper = func_name.upper()
    func_lower = "FUN_" + func_name[4:].lower()
    addr = int(func_name.replace("FUN_", ""), 16)

    lines = []
    lines.append(f"/* {func_upper} -- original binary ({len(byte_data)} bytes) */")
    lines.append("__asm__(")
    lines.append(f'    ".section .text.{func_upper}, \\"ax\\"\\n"')
    lines.append(f'    ".balign 2\\n"')
    lines.append(f'    ".global _{func_upper}\\n"')
    if func_lower != func_upper:
        lines.append(f'    ".global _{func_lower}\\n"')
    lines.append(f'    ".type _{func_upper}, @function\\n"')
    lines.append(f'    "_{func_upper}:\\n"')
    if func_lower != func_upper:
        lines.append(f'    "_{func_lower}:\\n"')

    for i in range(0, len(byte_data), 16):
        chunk = byte_data[i:i + 16]
        byte_str = ", ".join(f"0x{b:02X}" for b in chunk)
        lines.append(f'    ".byte {byte_str}\\n"  /* 0x{addr + i:08X} */')

    lines.append(");")
    return "\n".join(lines)


def find_function_in_sources(func_name):
    """Find a C function definition in reimpl/src/*.c files.

    Returns (filepath, start_line, end_line) or None.
    start_line is the line with 'void/int FUN_...()'
    end_line is the closing '}'
    """
    func_lower = "FUN_" + func_name[4:].lower()
    func_upper = func_name.upper()

    # Patterns to match function definitions
    patterns = [
        re.compile(rf'^(void|int|unsigned|char)\s+{re.escape(func_lower)}\s*\('),
        re.compile(rf'^(void|int|unsigned|char)\s+{re.escape(func_upper)}\s*\('),
    ]

    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.endswith('.c'):
            continue
        filepath = os.path.join(SRC_DIR, fname)
        with open(filepath, 'r', errors='replace') as f:
            lines = f.readlines()

        for i, line in enumerate(lines):
            for pat in patterns:
                if pat.search(line):
                    # Check if this is inside #if 0
                    in_if0 = False
                    for j in range(i - 1, max(i - 5, -1), -1):
                        if '#if 0' in lines[j]:
                            in_if0 = True
                            break
                        if '#endif' in lines[j] or '#if' in lines[j]:
                            break

                    if in_if0:
                        continue  # Already disabled

                    # Check if this is inside __asm__ (already ASM imported)
                    if '__asm__' in line or '.byte' in line:
                        continue

                    # Find the closing brace
                    brace_count = 0
                    end_line = None
                    for j in range(i, len(lines)):
                        brace_count += lines[j].count('{') - lines[j].count('}')
                        if brace_count == 0 and '{' in ''.join(lines[i:j + 1]):
                            end_line = j
                            break

                    if end_line is not None:
                        return (filepath, i, end_line)

    return None


def find_preceding_comment_or_extern(lines, func_start):
    """Find where the function's comment block or extern declarations start."""
    start = func_start
    for i in range(func_start - 1, max(func_start - 20, -1), -1):
        line = lines[i].strip()
        if line.startswith('/*') or line.startswith('*') or line.startswith('extern') or line == '':
            # Check if this is a section comment for THIS function
            if '--- FUN_' in line or 'FUN_' in line:
                start = i
            elif line.startswith('extern'):
                start = i
            elif line == '' and start == func_start:
                continue  # Skip blank lines before function
            elif line == '':
                continue
            else:
                break
        else:
            break
    return start


def apply_asm_import(filepath, func_start, func_end, func_name, asm_block, lines):
    """Wrap C function in #if 0 and add ASM import block."""
    func_upper = func_name.upper()

    # Find where to insert #if 0 (before the function definition)
    if0_line = func_start

    # Check for preceding comment that should be outside #if 0
    # Look for "--- FUN_XXXXXXXX" comment
    comment_start = None
    for i in range(func_start - 1, max(func_start - 5, -1), -1):
        if lines[i].strip().startswith('/*') and 'FUN_' in lines[i]:
            comment_start = i
            break

    # Insert #if 0 after the comment (if any), before the function
    insert_if0 = func_start

    # Check if there are extern declarations right before that belong to this function
    extern_start = func_start
    for i in range(func_start - 1, max(func_start - 10, -1), -1):
        line = lines[i].strip()
        if line.startswith('extern'):
            extern_start = i
        elif line == '':
            continue
        else:
            break

    # Insert #if 0 before extern declarations
    insert_if0 = extern_start

    # Build new content
    new_lines = lines[:insert_if0]
    new_lines.append(f"#if 0 /* {func_upper} -- replaced by ASM import */\n")
    new_lines.extend(lines[insert_if0:func_end + 1])
    new_lines.append("#endif\n")
    new_lines.append("\n")
    new_lines.append(asm_block + "\n")
    new_lines.append("\n")
    new_lines.extend(lines[func_end + 1:])

    return new_lines


def main():
    print("Finding functions with wrong bytes...")
    wrong_funcs = find_wrong_functions()
    print(f"Found {len(wrong_funcs)} functions with incorrect bytes\n")

    if LIMIT:
        wrong_funcs = wrong_funcs[:LIMIT]
        print(f"Limited to {LIMIT} functions\n")

    # Extract original bytes from aprog.s
    target_names = [f[0] for f in wrong_funcs]
    print(f"Extracting original bytes from aprog.s for {len(target_names)} functions...")
    aprog_bytes = parse_aprog_functions(target_names)
    print(f"Extracted bytes for {len(aprog_bytes)} functions\n")

    # Find C definitions and apply imports
    applied = 0
    skipped_no_source = 0
    skipped_already_asm = 0
    skipped_no_bytes = 0
    file_modifications = defaultdict(list)  # filepath -> [(func_start, func_end, func_name, asm_block)]

    for func_name, addr, size, diff_count in wrong_funcs:
        if func_name not in aprog_bytes:
            skipped_no_bytes += 1
            continue

        byte_data = aprog_bytes[func_name]
        result = find_function_in_sources(func_name)

        if result is None:
            skipped_no_source += 1
            if not APPLY:
                print(f"  SKIP {func_name}: no active C definition found")
            continue

        filepath, func_start, func_end = result
        asm_block = generate_asm_block(func_name, byte_data)

        file_modifications[filepath].append((func_start, func_end, func_name, asm_block))
        applied += 1

    print(f"\nResults:")
    print(f"  Will import: {applied}")
    print(f"  Skipped (no source): {skipped_no_source}")
    print(f"  Skipped (no bytes): {skipped_no_bytes}")
    print(f"  Files to modify: {len(file_modifications)}")

    if not APPLY:
        print(f"\nDry run complete. Use --apply to make changes.")
        print(f"\nFunctions to import:")
        for func_name, addr, size, diff_count in wrong_funcs:
            if func_name in aprog_bytes:
                result = find_function_in_sources(func_name)
                if result:
                    filepath, _, _ = result
                    fname = os.path.basename(filepath)
                    print(f"  {func_name} ({len(aprog_bytes[func_name])}B) in {fname}")
        return

    # Apply changes -- process files from bottom to top to preserve line numbers
    for filepath in sorted(file_modifications.keys()):
        mods = file_modifications[filepath]
        # Sort by func_start DESCENDING so we modify from bottom up
        mods.sort(key=lambda x: x[0], reverse=True)

        with open(filepath, 'r', errors='replace') as f:
            lines = f.readlines()

        for func_start, func_end, func_name, asm_block in mods:
            lines = apply_asm_import(filepath, func_start, func_end, func_name, asm_block, lines)

        with open(filepath, 'w', newline='\n') as f:
            f.writelines(lines)

        print(f"  Modified: {os.path.basename(filepath)} ({len(mods)} functions)")

    print(f"\nDone! {applied} functions imported.")
    print(f"Rebuild with: cd reimpl && make clean && make")


if __name__ == "__main__":
    main()
