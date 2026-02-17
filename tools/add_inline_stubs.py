#!/usr/bin/env python3
"""add_inline_stubs.py -- Add inline rts/nop stubs for missing functions.

Instead of a separate missing_stubs.c file, each function gets an inline
__asm__ stub appended to its proper batch file. This keeps everything
organized and eliminates the need for a standalone stubs file.

The stubs are exactly 4 bytes (rts + nop) and placed at the original address
via .text.FUN_XXXXXXXX sections. They can't cause overlaps.

Usage:
    python tools/add_inline_stubs.py
"""

import os
import re
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
APROG_S = os.path.join(PROJDIR, "build", "aprog.s")
ELF = os.path.join(PROJDIR, "reimpl", "build", "daytona.elf")
NM = os.path.join(PROJDIR, "tools", "sh-elf", "bin", "sh-elf-nm")
REIMPL_DIR = os.path.join(PROJDIR, "reimpl", "src")


def get_aprog_functions():
    """Extract all FUN_ labels from aprog.s (normalized to uppercase)."""
    funcs = set()
    with open(APROG_S, "r") as f:
        for line in f:
            m = re.match(r'^(FUN_[0-9a-fA-F]+):', line)
            if m:
                funcs.add(m.group(1).upper())
    return funcs


def get_elf_symbols():
    """Extract all FUN_ symbols from reimpl ELF (normalized to uppercase)."""
    result = subprocess.run(
        ["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
         f'"{NM.replace(os.sep, "/").replace("D:", "/mnt/d")}" '
         f'"{ELF.replace(os.sep, "/").replace("D:", "/mnt/d")}" | tr -d "\\r"'],
        capture_output=True, text=True
    )
    syms = set()
    for line in result.stdout.splitlines():
        parts = line.split()
        if len(parts) >= 3 and parts[2].startswith("_FUN_"):
            syms.add(parts[2][1:].upper())
    return syms


def classify_address(addr_int):
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


def make_stub_asm(func):
    """Generate an inline asm stub for a function."""
    return (
        f'\n/* {func} -- Class 4 stub (rts/nop, no source available) */\n'
        f'__asm__(\n'
        f'    ".section .text.{func}, \\"ax\\"\\n"\n'
        f'    ".balign 2\\n"\n'
        f'    ".global _{func}\\n"\n'
        f'    ".type _{func}, @function\\n"\n'
        f'    "_{func}:\\n"\n'
        f'    ".word 0x000B\\n"  /* rts */\n'
        f'    ".word 0x0009\\n"  /* nop (delay slot) */\n'
        f');\n'
    )


def main():
    print("Finding missing functions...")
    aprog_funcs = get_aprog_functions()
    elf_syms = get_elf_symbols()
    missing = sorted(aprog_funcs - elf_syms)
    print(f"  {len(missing)} functions missing from reimpl")

    if not missing:
        print("Nothing to do!")
        return

    # Group by batch file
    groups = {}
    for func in missing:
        addr_int = int(func.replace("FUN_", ""), 16)
        group = classify_address(addr_int)
        if group not in groups:
            groups[group] = []
        groups[group].append(func)

    print(f"  Distributing across {len(groups)} batch files\n")

    total = 0
    for group in sorted(groups.keys()):
        funcs = groups[group]
        batch_path = os.path.join(REIMPL_DIR, f"batch_{group}.c")

        if not os.path.exists(batch_path):
            print(f"  WARNING: {batch_path} doesn't exist, creating it")
            with open(batch_path, "w", newline="\n") as f:
                f.write(f"/* batch_{group}.c -- Auto-generated stubs */\n")

        # Append stubs
        with open(batch_path, "a", newline="\n") as f:
            for func in funcs:
                f.write(make_stub_asm(func))

        total += len(funcs)
        print(f"  {batch_path}: +{len(funcs)} stubs ({', '.join(funcs)})")

    print(f"\nAdded {total} inline stubs across {len(groups)} batch files")
    print("missing_stubs.c is no longer needed")


if __name__ == "__main__":
    main()
