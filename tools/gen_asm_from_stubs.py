#!/usr/bin/env python3
"""gen_asm_from_stubs.py -- Convert stub functions to ASM imports.

Reads the original binary (aprog.bin) and generates inline ASM for
functions that are currently empty stubs in extern_stubs.c.
"""

import os
import re
import struct

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BINARY_PATH = os.path.join(PROJ, "build", "disc", "files", "APROG.BIN")
SYMS_FILE = os.path.join(PROJ, "build", "aprog_syms.txt")
EXTERN_STUBS = os.path.join(PROJ, "reimpl", "src", "extern_stubs.c")
STUBS_FILE = os.path.join(PROJ, "reimpl", "src", "stubs.c")
OUTPUT = os.path.join(PROJ, "reimpl", "src", "asm_restored_stubs.c")

BASE_ADDR = 0x06003000


def parse_syms():
    """Parse aprog_syms.txt -> dict of name -> (addr, size)."""
    syms = []
    with open(SYMS_FILE) as f:
        for line in f:
            m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            if m:
                syms.append((int(m.group(2), 16), m.group(1)))
    syms.sort()
    sizes = {}
    for i, (addr, name) in enumerate(syms):
        next_addr = syms[i + 1][0] if i + 1 < len(syms) else BASE_ADDR + 394896
        sizes[name.upper()] = (addr, next_addr - addr)
    return sizes


def find_stub_functions():
    """Find all FUN_ functions in extern_stubs.c and empty stubs in stubs.c."""
    stubs = {}

    # Parse extern_stubs.c for all FUN_ functions (they're all stubs)
    with open(EXTERN_STUBS) as f:
        for line in f:
            m = re.match(r'(?:void|int)\s+(FUN_[0-9A-Fa-f]+)\s*\(', line)
            if m:
                stubs[m.group(1).upper()] = ('extern_stubs.c', line.strip())

    # Parse stubs.c for empty stub functions (only empty ones!)
    with open(STUBS_FILE) as f:
        content = f.read()
    for m in re.finditer(r'void\s+(\w+)\s*\((?:void)?\)\s*\{\s*\}', content):
        func_name = m.group(1)
        # Need to map named functions to their FUN_ address
        stubs[func_name.upper()] = ('stubs.c', m.group(0).strip())

    return stubs


def generate_asm_import(name, addr, size, binary):
    """Generate inline ASM for a function from original binary bytes."""
    offset = addr - BASE_ADDR
    if offset < 0 or offset + size > len(binary):
        return None

    lines = []
    lines.append('/* %s @ 0x%08X (%d bytes) — restored from original binary */' % (name, addr, size))
    lines.append('__asm__(')
    lines.append('    ".balign 2\\n"')
    lines.append('    ".global _%s\\n"' % name)
    lines.append('    ".type _%s, @function\\n"' % name)
    lines.append('    "_%s:\\n"' % name)

    # Emit .word entries for each 16-bit word
    for i in range(0, size, 2):
        if i + 2 <= size:
            word = struct.unpack('>H', binary[offset + i:offset + i + 2])[0]
            lines.append('    ".word 0x%04X\\n"' % word)
        else:
            # Odd byte at end
            lines.append('    ".byte 0x%02X\\n"' % binary[offset + i])

    lines.append(');')
    lines.append('')
    return '\n'.join(lines)


def main():
    # Read binary
    with open(BINARY_PATH, 'rb') as f:
        binary = f.read()

    # Parse symbols
    sym_sizes = parse_syms()

    # Find stubs
    stubs = find_stub_functions()
    print("Found %d stub functions" % len(stubs))

    # Map named stubs to FUN_ addresses
    # Read stubs.c to find address comments
    name_to_addr = {}
    with open(STUBS_FILE) as f:
        prev_comment_addr = None
        for line in f:
            # Look for comments like "/* 0x06034E58: ..."
            m = re.search(r'/\*\s*0x([0-9A-Fa-f]+):', line)
            if m:
                prev_comment_addr = int(m.group(1), 16)
            # Look for function definitions following the comment
            m = re.match(r'void\s+(\w+)\s*\(', line)
            if m and prev_comment_addr:
                func_name = m.group(1).upper()
                name_to_addr[func_name] = prev_comment_addr
            if line.strip() and not line.strip().startswith('/*') and not line.strip().startswith('*'):
                if not re.match(r'void\s+\w+\s*\(', line):
                    prev_comment_addr = None

    # Generate ASM imports
    generated = []
    skipped = []

    for name, (source, orig_line) in sorted(stubs.items()):
        # Try to find the address
        if name in sym_sizes:
            addr, size = sym_sizes[name]
        elif name in name_to_addr:
            addr = name_to_addr[name]
            # Find the FUN_ name for this address
            fun_name = None
            for sn, (sa, ss) in sym_sizes.items():
                if sa == addr:
                    fun_name = sn
                    size = ss
                    break
            if fun_name is None:
                skipped.append((name, 'address 0x%08X not in syms' % addr))
                continue
            name = fun_name  # Use the canonical FUN_ name
        else:
            skipped.append((name, 'not in symbol table'))
            continue

        asm = generate_asm_import(name, addr, size, binary)
        if asm:
            generated.append((name, addr, size, asm))
            print("  Generated: %s @ 0x%08X (%d bytes)" % (name, addr, size))
        else:
            skipped.append((name, 'out of binary range'))

    # Write output
    output_lines = []
    output_lines.append('/* asm_restored_stubs.c -- Original binary bytes for former stub functions')
    output_lines.append(' *')
    output_lines.append(' * AUTO-GENERATED by tools/gen_asm_from_stubs.py')
    output_lines.append(' * These functions were empty stubs; now they have the original binary bytes.')
    output_lines.append(' */')
    output_lines.append('')

    for name, addr, size, asm in generated:
        output_lines.append(asm)

    with open(OUTPUT, 'w', newline='\n') as f:
        f.write('\n'.join(output_lines) + '\n')

    print()
    print("Generated: %d functions in %s" % (len(generated), OUTPUT))
    if skipped:
        print("Skipped: %d" % len(skipped))
        for name, reason in skipped:
            print("  %s: %s" % (name, reason))

    print()
    print("IMPORTANT: Remove the corresponding stubs from extern_stubs.c and stubs.c")
    print("to avoid duplicate symbol errors.")


if __name__ == "__main__":
    main()
