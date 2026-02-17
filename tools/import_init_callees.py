#!/usr/bin/env python3
"""import_init_callees.py -- Generate ASM import blocks for broken init callees.

Extracts original bytes from build/aprog.s for specific functions and
generates __asm__ blocks to replace broken Ghidra C lifts.

Usage: python tools/import_init_callees.py
"""

import os
import re

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
APROG_S = os.path.join(PROJ, "build", "aprog.s")

# Target functions: init callees with incorrect C lifts
TARGETS = [
    "FUN_06012CF4",
    "FUN_06012E6A",
    "FUN_0601492C",
    "FUN_06018EE4",
]


def parse_aprog_functions(targets):
    """Parse aprog.s: extract byte sequences for target functions."""
    functions = {}
    current_func = None
    current_bytes = []

    with open(APROG_S, "r") as f:
        for line in f:
            # Function label: FUN_0600XXXX:
            m = re.match(r'^(FUN_[0-9a-fA-F]+):', line)
            if m:
                if current_func and current_bytes:
                    functions[current_func] = current_bytes
                name = m.group(1).upper()
                if name in targets:
                    current_func = name
                    current_bytes = []
                else:
                    current_func = None
                    current_bytes = []
                continue

            # Byte pair: .byte 0xHH, 0xHH
            if current_func:
                m = re.match(r'\s+\.byte\s+0x([0-9a-fA-F]+),\s*0x([0-9a-fA-F]+)', line)
                if m:
                    current_bytes.append(int(m.group(1), 16))
                    current_bytes.append(int(m.group(2), 16))

    # Don't forget last function
    if current_func and current_bytes:
        functions[current_func] = current_bytes

    return functions


def generate_asm_block(func_name, byte_data):
    """Generate __asm__ block for a function."""
    lines = []
    lines.append(f"/* {func_name} -- original binary ({len(byte_data)} bytes) */")
    lines.append("__asm__(")
    lines.append(f'    ".section .text.{func_name}, \\"ax\\"\\n"')
    lines.append(f'    ".balign 2\\n"')
    lines.append(f'    ".global _{func_name}\\n"')
    lines.append(f'    ".type _{func_name}, @function\\n"')
    lines.append(f'    "_{func_name}:\\n"')

    # Emit bytes in groups of 16
    addr = int(func_name.replace("FUN_", ""), 16)
    for i in range(0, len(byte_data), 16):
        chunk = byte_data[i:i+16]
        byte_str = ", ".join(f"0x{b:02X}" for b in chunk)
        lines.append(f'    ".byte {byte_str}\\n"  /* 0x{addr + i:08X} */')

    lines.append(");")
    return "\n".join(lines)


def main():
    target_set = set(TARGETS)
    functions = parse_aprog_functions(target_set)

    print(f"Extracted {len(functions)} of {len(TARGETS)} target functions:\n")

    for name in TARGETS:
        if name not in functions:
            print(f"  WARNING: {name} not found in aprog.s!")
            continue

        byte_data = functions[name]
        print(f"  {name}: {len(byte_data)} bytes")
        print()
        print(generate_asm_block(name, byte_data))
        print()
        print("---")
        print()


if __name__ == "__main__":
    main()
