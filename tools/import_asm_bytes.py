#!/usr/bin/env python3
"""import_asm_bytes.py -- Replace stub functions with original binary bytes.

Reads original machine code from build/aprog.s and replaces rts/nop stub
functions in reimpl/src/ with inline assembly containing the exact original
bytes. This is guaranteed correct — it's literally the production binary.

Targets only stub functions where the compiled size is <= 12 bytes AND the
original slot size is larger (i.e., the stub is missing real code). Functions
that are genuinely 4-byte rts/nop in the original are left alone.

Usage:
    python tools/import_asm_bytes.py                # Dry run (show what would change)
    python tools/import_asm_bytes.py --apply        # Actually modify files
    python tools/import_asm_bytes.py --apply --rebuild  # Modify, rebuild, re-audit
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
OBJDUMP = os.path.join(PROJDIR, "tools", "sh-elf", "bin", "sh-elf-objdump")

# Known data regions — not real functions
DATA_REGIONS = {"FUN_06046E48"}


def wsl_path(p):
    p = p.replace("\\", "/")
    if len(p) >= 2 and p[1] == ":":
        return "/mnt/" + p[0].lower() + p[2:]
    return p


def parse_aprog_functions():
    """Parse aprog.s: extract byte sequences for every function.

    Returns dict: {func_name: [byte_list], ...}
    """
    functions = {}
    current_func = None
    current_bytes = []

    with open(APROG_S, "r") as f:
        for line in f:
            # Function label
            m = re.match(r'^(FUN_[0-9a-fA-F]+):', line)
            if m:
                # Save previous function
                if current_func and current_bytes:
                    functions[current_func] = current_bytes
                current_func = m.group(1).upper()
                current_bytes = []
                continue

            # Byte directive: .byte 0xHH, 0xHH
            if current_func:
                m = re.match(r'\s+\.byte\s+0x([0-9a-fA-F]+),\s*0x([0-9a-fA-F]+)', line)
                if m:
                    current_bytes.append(int(m.group(1), 16))
                    current_bytes.append(int(m.group(2), 16))

    # Save last function
    if current_func and current_bytes:
        functions[current_func] = current_bytes

    return functions


def get_original_slots():
    """Get function addresses and slot sizes from aprog.s labels."""
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
            slot_size = funcs[i + 1][0] - addr
        else:
            slot_size = 0x06063690 - addr
        slots[name] = slot_size

    return slots


def get_elf_sections():
    """Get compiled section sizes from reimpl ELF."""
    if not os.path.exists(ELF):
        return {}

    result = subprocess.run(
        ["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
         f'"{wsl_path(OBJDUMP)}" -h "{wsl_path(ELF)}" | tr -d "\\r"'],
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


def find_stub_functions(slots, elf_sections):
    """Find functions that are stubs (compiled <= 12 bytes, original is larger)."""
    stubs = []
    for name, slot_size in slots.items():
        if name in DATA_REGIONS:
            continue
        compiled = elf_sections.get(name, 0)
        if compiled <= 12 and slot_size > compiled:
            deficit = slot_size - compiled
            stubs.append((name, slot_size, compiled, deficit))

    stubs.sort(key=lambda x: x[3], reverse=True)
    return stubs


def find_stub_in_files(func_name):
    """Find which reimpl/src/ file contains this function's stub.

    Returns (filepath, start_line, end_line) or None.
    """
    for fname in os.listdir(REIMPL_SRC):
        if not fname.endswith(".c"):
            continue
        fpath = os.path.join(REIMPL_SRC, fname)
        with open(fpath, "r", errors="replace") as f:
            lines = f.readlines()

        for i, line in enumerate(lines):
            # Match inline asm stub containing this function
            if func_name in line and ("__asm__" in line or ".global" in line or
                                       "Class 4 stub" in line or "rts/nop" in line or
                                       "stub" in line.lower()):
                # Find the asm block boundaries
                start = i
                # Search backwards for __asm__( or the comment
                while start > 0:
                    if "__asm__(" in lines[start] or "/* " + func_name in lines[start]:
                        break
                    start -= 1

                # Search forward for ");
                end = i
                while end < len(lines) - 1:
                    if ");" in lines[end]:
                        end += 1
                        break
                    end += 1

                return (fpath, start, end)

            # Also match C void stubs: void FUN_XXXXXXXX() { }
            if re.match(rf'(void|int)\s+{func_name}\s*\(', line):
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
                return (fpath, start, end)

    return None


def generate_asm_block(func_name, byte_data, slot_size):
    """Generate an inline __asm__ block with original binary bytes.

    Uses .byte directives (not .word) for exact byte-level fidelity.
    Groups bytes into lines of 16 for readability.
    """
    lines = []
    lines.append(f"/* {func_name} -- original binary ({len(byte_data)} bytes) */")
    lines.append("__asm__(")
    lines.append(f'    ".section .text.{func_name}, \\"ax\\"\\n"')
    lines.append(f'    ".balign 2\\n"')
    lines.append(f'    ".global _{func_name}\\n"')
    lines.append(f'    ".type _{func_name}, @function\\n"')
    lines.append(f'    "_{func_name}:\\n"')

    # Emit bytes in groups of 16
    for i in range(0, len(byte_data), 16):
        chunk = byte_data[i:i+16]
        byte_str = ", ".join(f"0x{b:02X}" for b in chunk)
        addr = int(func_name.replace("FUN_", ""), 16) + i
        lines.append(f'    ".byte {byte_str}\\n"  /* 0x{addr:08X} */')

    lines.append(");")
    return "\n".join(lines)


def replace_stub_in_file(fpath, start, end, new_block):
    """Replace lines [start:end] in file with new_block."""
    with open(fpath, "r", errors="replace") as f:
        lines = f.readlines()

    new_lines = lines[:start] + [new_block + "\n\n"] + lines[end:]

    with open(fpath, "w", newline="\n") as f:
        f.writelines(new_lines)


def classify_batch(addr_int):
    """Map address to batch file group name."""
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
    parser = argparse.ArgumentParser(description="Import original binary bytes for stub functions")
    parser.add_argument("--apply", action="store_true", help="Actually modify files (default: dry run)")
    parser.add_argument("--rebuild", action="store_true", help="Rebuild after applying (implies --apply)")
    parser.add_argument("--limit", type=int, default=0, help="Limit to N functions (0=all)")
    args = parser.parse_args()

    if args.rebuild:
        args.apply = True

    print("Parsing aprog.s for original function bytes...")
    aprog_funcs = parse_aprog_functions()
    print(f"  {len(aprog_funcs)} functions with byte data")

    print("Reading original slot sizes...")
    slots = get_original_slots()

    print("Reading ELF section sizes...")
    elf_sections = get_elf_sections()

    print("Finding stub functions...")
    stubs = find_stub_functions(slots, elf_sections)
    print(f"  {len(stubs)} stubs with missing code\n")

    if args.limit:
        stubs = stubs[:args.limit]
        print(f"  (limited to {args.limit} functions)\n")

    replaced = 0
    appended = 0
    skipped = 0
    total_bytes = 0

    for func_name, slot_size, compiled, deficit in stubs:
        # Get original bytes
        if func_name not in aprog_funcs:
            print(f"  SKIP {func_name}: no bytes in aprog.s")
            skipped += 1
            continue

        byte_data = aprog_funcs[func_name]
        # Trim to slot size (bytes after the slot belong to the next function)
        if len(byte_data) > slot_size:
            byte_data = byte_data[:slot_size]

        if len(byte_data) == 0:
            print(f"  SKIP {func_name}: empty byte data")
            skipped += 1
            continue

        # Find existing stub in reimpl source
        location = find_stub_in_files(func_name)
        new_block = generate_asm_block(func_name, byte_data, slot_size)

        if location:
            fpath, start, end = location
            fname = os.path.basename(fpath)
            if args.apply:
                replace_stub_in_file(fpath, start, end, new_block)
                print(f"  REPLACE {func_name} in {fname} ({len(byte_data)} bytes, was {compiled}B)")
            else:
                print(f"  WOULD REPLACE {func_name} in {fname} ({len(byte_data)} bytes, was {compiled}B)")
            replaced += 1
        else:
            # Function not found in any file — append to appropriate batch file
            addr_int = int(func_name.replace("FUN_", ""), 16)
            group = classify_batch(addr_int)
            batch_path = os.path.join(REIMPL_SRC, f"batch_{group}.c")

            if not os.path.exists(batch_path):
                # Try asm file
                batch_path = os.path.join(REIMPL_SRC, f"asm_{group}.c")

            if args.apply and os.path.exists(batch_path):
                with open(batch_path, "a", newline="\n") as f:
                    f.write("\n" + new_block + "\n")
                print(f"  APPEND {func_name} to {os.path.basename(batch_path)} ({len(byte_data)} bytes)")
            elif args.apply:
                print(f"  SKIP {func_name}: no target file for group {group}")
                skipped += 1
                continue
            else:
                print(f"  WOULD APPEND {func_name} to batch_{group}.c ({len(byte_data)} bytes)")
            appended += 1

        total_bytes += len(byte_data)

    print(f"\n{'='*50}")
    print(f"{'Applied' if args.apply else 'Dry run'}: {replaced} replaced, {appended} appended, {skipped} skipped")
    print(f"Total bytes imported: {total_bytes:,}")

    if not args.apply:
        print("\nRun with --apply to make changes.")


if __name__ == "__main__":
    main()
