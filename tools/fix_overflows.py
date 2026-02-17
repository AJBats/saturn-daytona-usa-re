#!/usr/bin/env python3
"""fix_overflows.py -- Replace overflowing C functions with original binary bytes.

For every function that compiles larger than its original slot, replace the
C implementation with original bytes from aprog.s as inline __asm__ blocks.
This eliminates ALL overflow issues since original bytes are exact-fit.

Also handles duplicate definitions: if an ASM import already exists alongside
a C definition, disables the C definition.

Usage:
    python tools/fix_overflows.py                # Dry run
    python tools/fix_overflows.py --apply        # Apply changes
"""

import argparse
import os
import re
import subprocess
import sys

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
APROG_S = os.path.join(PROJDIR, "build", "aprog.s")
REIMPL_SRC = os.path.join(PROJDIR, "reimpl", "src")
ELF = os.path.join(PROJDIR, "reimpl", "build", "daytona.elf")
OBJDUMP_WSL = "/mnt/d/Projects/SaturnReverseTest/tools/sh-elf/bin/sh-elf-objdump"
ELF_WSL = "/mnt/d/Projects/SaturnReverseTest/reimpl/build/daytona.elf"

DATA_REGIONS = {"FUN_06046E48"}


def parse_aprog_functions():
    """Parse aprog.s: extract byte sequences for every function."""
    functions = {}
    current_func = None
    current_bytes = []

    with open(APROG_S, "r") as f:
        for line in f:
            m = re.match(r'^(FUN_[0-9a-fA-F]+):', line)
            if m:
                if current_func and current_bytes:
                    functions[current_func] = current_bytes
                current_func = m.group(1).upper()
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


def get_original_slots():
    """Get function slot sizes from aprog.s."""
    funcs = []
    with open(APROG_S, "r") as f:
        for line in f:
            m = re.match(r'^(FUN_[0-9a-fA-F]+):', line)
            if m:
                name = m.group(1).upper()
                addr = int(name.replace("FUN_", ""), 16)
                funcs.append((addr, name))
    funcs.sort()

    slots = {}
    for i, (addr, name) in enumerate(funcs):
        if i + 1 < len(funcs):
            slots[name] = funcs[i + 1][0] - addr
        else:
            slots[name] = 0x06063690 - addr
    return slots


def get_elf_sections():
    """Get compiled section sizes from ELF."""
    result = subprocess.run(
        ["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
         f'{OBJDUMP_WSL} -h {ELF_WSL} | tr -d "\\r"'],
        capture_output=True, text=True
    )
    sections = {}
    for line in result.stdout.splitlines():
        m = re.match(r'\s*\d+\s+\.func_(FUN_[0-9A-Fa-f]+)\s+([0-9a-f]+)', line.strip())
        if m:
            name = m.group(1).upper()
            size = int(m.group(2), 16)
            sections[name] = size
    return sections


def find_overflow_functions(slots, elf_sections):
    """Find functions that compile larger than their original slot."""
    overflows = []
    for name, slot_size in slots.items():
        if name in DATA_REGIONS:
            continue
        compiled = elf_sections.get(name, 0)
        if compiled > slot_size and slot_size > 0:
            over = compiled - slot_size
            overflows.append((name, slot_size, compiled, over))
    overflows.sort(key=lambda x: x[3], reverse=True)
    return overflows


def find_asm_import(func_name):
    """Check if function already has an ASM import in reimpl/src/."""
    for fname in os.listdir(REIMPL_SRC):
        if not fname.endswith(".c"):
            continue
        fpath = os.path.join(REIMPL_SRC, fname)
        with open(fpath, "r", errors="replace") as f:
            content = f.read()
        if f"/* {func_name} -- original binary" in content:
            return fname
    return None


def find_c_definition(func_name):
    """Find C function definition location.

    Returns list of (filename, start_line, end_line) tuples.
    """
    results = []
    func_lower = func_name.lower()

    for fname in sorted(os.listdir(REIMPL_SRC)):
        if not fname.endswith(".c"):
            continue
        fpath = os.path.join(REIMPL_SRC, fname)
        with open(fpath, "r", errors="replace") as f:
            lines = f.readlines()

        in_asm = False
        in_if0 = 0
        i = 0
        while i < len(lines):
            line = lines[i]

            # Track #if 0 blocks
            if re.match(r'#if\s+0', line):
                in_if0 += 1
            if '#endif' in line and in_if0 > 0:
                in_if0 -= 1
                i += 1
                continue
            if in_if0 > 0:
                i += 1
                continue

            # Skip inside asm blocks
            if '__asm__(' in line:
                in_asm = True
            if in_asm:
                if ');' in line:
                    in_asm = False
                i += 1
                continue

            # Match C function definition
            if re.match(rf'^(?:void|int|unsigned int|unsigned short|short|char|int \*|unsigned int \*)\s+{func_lower}\s*\(', line, re.IGNORECASE):
                start = i
                end = i
                brace_depth = 0
                found_brace = False
                while end < len(lines):
                    brace_depth += lines[end].count('{') - lines[end].count('}')
                    if '{' in lines[end]:
                        found_brace = True
                    if found_brace and brace_depth == 0:
                        end += 1
                        break
                    end += 1
                results.append((fname, start, end))
                i = end
                continue

            # Also match alias definitions
            if re.match(rf'^(?:void|int|unsigned int|int \*)\s+{func_lower}\s*\(.*__attribute__.*alias', line, re.IGNORECASE):
                results.append((fname, i, i + 1))

            i += 1

    return results


def generate_asm_block(func_name, byte_data):
    """Generate inline __asm__ block with original binary bytes."""
    lines = []
    lines.append(f"/* {func_name} -- original binary ({len(byte_data)} bytes) */")
    lines.append("__asm__(")
    lines.append(f'    ".section .text.{func_name}, \\"ax\\"\\n"')
    lines.append(f'    ".balign 2\\n"')
    lines.append(f'    ".global _{func_name}\\n"')
    lines.append(f'    ".type _{func_name}, @function\\n"')
    lines.append(f'    "_{func_name}:\\n"')

    for i in range(0, len(byte_data), 16):
        chunk = byte_data[i:i+16]
        byte_str = ", ".join(f"0x{b:02X}" for b in chunk)
        addr = int(func_name.replace("FUN_", ""), 16) + i
        lines.append(f'    ".byte {byte_str}\\n"  /* 0x{addr:08X} */')

    lines.append(");")
    return "\n".join(lines)


def disable_c_function(fname, start, end, func_name, apply=False):
    """Wrap C function in #if 0."""
    fpath = os.path.join(REIMPL_SRC, fname)
    with open(fpath, "r", errors="replace") as f:
        lines = f.readlines()

    # Check if already disabled
    for check_line in range(max(0, start-3), start):
        if '#if 0' in lines[check_line]:
            return False  # Already disabled

    lines[start] = f"#if 0 /* {func_name} -- replaced by ASM import */\n" + lines[start]
    lines[end-1] = lines[end-1].rstrip() + "\n#endif\n"

    if apply:
        with open(fpath, "w", newline="\n") as f:
            f.writelines(lines)

    return True


def append_asm_to_file(fname, asm_block, apply=False):
    """Append ASM block to file."""
    fpath = os.path.join(REIMPL_SRC, fname)
    if apply:
        with open(fpath, "a", newline="\n") as f:
            f.write("\n" + asm_block + "\n")


def classify_batch(addr_int):
    """Map address to batch file."""
    ranges = [
        (0x06002000, 0x06004000, "system_low"),
        (0x06004000, 0x06006000, "game_init"),
        (0x06005000, 0x06008000, "game_core"),
        (0x06008000, 0x0600A000, "state_machine"),
        (0x0600A000, 0x0600C000, "game_logic_a"),
        (0x0600C000, 0x0600E000, "game_logic_b"),
        (0x0600E000, 0x06010000, "game_logic_c"),
        (0x06010000, 0x06012000, "subsystem_10"),
        (0x06012000, 0x06014000, "subsystem_12"),
        (0x06014000, 0x06016000, "subsystem_14"),
        (0x06016000, 0x06018000, "subsystem_16"),
        (0x06018000, 0x0601A000, "subsystem_18"),
        (0x0601A000, 0x0601C000, "subsystem_1a"),
        (0x0601C000, 0x0601E000, "subsystem_1c"),
        (0x0601E000, 0x06020000, "subsystem_1e"),
        (0x06020000, 0x06022000, "rendering_20"),
        (0x06022000, 0x06026000, "rendering_22"),
        (0x06026000, 0x06028000, "math_util_26"),
        (0x06028000, 0x0602A000, "vdp_cmd_28"),
        (0x0602A000, 0x0602E000, "render_pipe_2a"),
        (0x0602E000, 0x06030000, "render_pipe_2e"),
        (0x06030000, 0x06032000, "scene_30"),
        (0x06032000, 0x06034000, "scene_32"),
        (0x06034000, 0x06036000, "cd_system_34"),
        (0x06036000, 0x06038000, "cd_system_36"),
        (0x06038000, 0x0603A000, "obj_system_38"),
        (0x0603A000, 0x0603C000, "obj_system_3a"),
        (0x0603C000, 0x0603E000, "obj_system_3c"),
        (0x0603E000, 0x06040000, "obj_system_3e"),
        (0x06040000, 0x06042000, "session_40"),
        (0x06042000, 0x06044000, "session_42"),
    ]
    for lo, hi, name in ranges:
        if lo <= addr_int < hi:
            return name
    return "misc"


def main():
    parser = argparse.ArgumentParser(description="Fix overflow functions with original bytes")
    parser.add_argument("--apply", action="store_true", help="Actually modify files")
    parser.add_argument("--limit", type=int, default=0, help="Limit to N functions")
    args = parser.parse_args()

    print("Parsing aprog.s...")
    aprog_funcs = parse_aprog_functions()
    print(f"  {len(aprog_funcs)} functions with bytes")

    print("Reading slot sizes...")
    slots = get_original_slots()

    print("Reading ELF sections...")
    elf_sections = get_elf_sections()
    print(f"  {len(elf_sections)} sections")

    print("Finding overflows...")
    overflows = find_overflow_functions(slots, elf_sections)
    print(f"  {len(overflows)} overflow functions\n")

    if args.limit:
        overflows = overflows[:args.limit]

    fixed = 0
    disabled_only = 0
    added_asm = 0
    skipped = 0

    for func_name, slot_size, compiled, over in overflows:
        if func_name not in aprog_funcs:
            print(f"  SKIP {func_name}: no bytes in aprog.s")
            skipped += 1
            continue

        byte_data = aprog_funcs[func_name]
        if len(byte_data) > slot_size:
            byte_data = byte_data[:slot_size]

        has_asm = find_asm_import(func_name)
        c_defs = find_c_definition(func_name)

        if has_asm and c_defs:
            # Both exist — disable C definition
            for fname, start, end in c_defs:
                if args.apply:
                    did = disable_c_function(fname, start, end, func_name, apply=True)
                    if did:
                        print(f"  DISABLE {func_name} C def in {fname} (has ASM in {has_asm})")
                else:
                    print(f"  WOULD DISABLE {func_name} C def in {fname} (has ASM in {has_asm})")
            disabled_only += 1
            fixed += 1

        elif has_asm and not c_defs:
            # ASM exists, no C def — should be fine, why overflow?
            print(f"  NOTE {func_name}: has ASM in {has_asm}, no C def, but overflow={over}")
            skipped += 1

        elif not has_asm and c_defs:
            # C exists, no ASM — add ASM import, disable C
            asm_block = generate_asm_block(func_name, byte_data)

            # Disable all C definitions
            for fname, start, end in c_defs:
                if args.apply:
                    did = disable_c_function(fname, start, end, func_name, apply=True)
                    if did:
                        print(f"  DISABLE {func_name} C def in {fname}")
                else:
                    print(f"  WOULD DISABLE {func_name} C def in {fname}")

            # Add ASM to the first C def's file
            target_file = c_defs[0][0]
            if args.apply:
                append_asm_to_file(target_file, asm_block, apply=True)
                print(f"  ADD ASM {func_name} to {target_file} ({len(byte_data)} bytes, was {compiled}B)")
            else:
                print(f"  WOULD ADD ASM {func_name} to {target_file} ({len(byte_data)} bytes, was {compiled}B)")
            added_asm += 1
            fixed += 1

        else:
            # No ASM, no C def found — append ASM to batch file
            asm_block = generate_asm_block(func_name, byte_data)
            addr_int = int(func_name.replace("FUN_", ""), 16)
            group = classify_batch(addr_int)
            batch_path = f"batch_{group}.c"

            if args.apply:
                append_asm_to_file(batch_path, asm_block, apply=True)
                print(f"  APPEND ASM {func_name} to {batch_path} ({len(byte_data)} bytes)")
            else:
                print(f"  WOULD APPEND ASM {func_name} to {batch_path} ({len(byte_data)} bytes)")
            added_asm += 1
            fixed += 1

    print(f"\n{'='*50}")
    verb = "Applied" if args.apply else "Dry run"
    print(f"{verb}: {fixed} fixed ({disabled_only} C disabled, {added_asm} ASM added), {skipped} skipped")


if __name__ == "__main__":
    main()
