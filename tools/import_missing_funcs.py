#!/usr/bin/env python3
"""import_missing_funcs.py -- Import missing functions from src/*.c into reimpl batch files.

These 69 functions have Ghidra decomp code in src/FUN_XXXXXXXX.c but were never
migrated to reimpl/src/ because gen_l1_batch.py skips existing batch files.

This script:
1. Reads each src/FUN_XXXXXXXX.c file
2. Strips comments (reimpl builds with modern GCC, comments are fine, but
   we strip them for consistency with existing batch files)
3. Appends the function to the appropriate existing batch_*.c file
4. Regenerates missing_stubs.c with only the 6 true orphans

Usage:
    python tools/import_missing_funcs.py
"""

import os
import re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(PROJDIR, "src")
REIMPL_DIR = os.path.join(PROJDIR, "reimpl", "src")

# 69 functions with src/*.c files but missing from reimpl
FUNCTIONS_WITH_SOURCE = [
    "FUN_06003578", "FUN_06003A3C", "FUN_06004670", "FUN_06005198", "FUN_06005294",
    "FUN_06005788", "FUN_06005928", "FUN_06006868", "FUN_06009FFC", "FUN_0600A392",
    "FUN_060127E0", "FUN_06012CF4", "FUN_06012E6A", "FUN_06012F80", "FUN_06013E3C",
    "FUN_06013FC4", "FUN_06014868", "FUN_0601492C", "FUN_06016DD8", "FUN_06017814",
    "FUN_06018278", "FUN_06018EE4", "FUN_0601A80C", "FUN_0601B6DC", "FUN_0601B7F4",
    "FUN_0601BA50", "FUN_0601C3E4", "FUN_0601E2B4", "FUN_06020414", "FUN_06022140",
    "FUN_0602382C", "FUN_06025070", "FUN_06025148", "FUN_060256CC", "FUN_06025BF4",
    "FUN_0602F99C", "FUN_06034C68", "FUN_06036E90", "FUN_06036F0C", "FUN_060370E4",
    "FUN_06037660", "FUN_06038300", "FUN_06038642", "FUN_0603950C", "FUN_06039808",
    "FUN_0603A01C", "FUN_0603A0B0", "FUN_0603AFD0", "FUN_0603C104", "FUN_0603C1A8",
    "FUN_0603C728", "FUN_0603CD5C", "FUN_0603F148", "FUN_0603FACE", "FUN_0603FC60",
    "FUN_060400D6", "FUN_0604077C", "FUN_060409E6", "FUN_06040C98", "FUN_06041034",
    "FUN_060414D0", "FUN_060418BE", "FUN_06041B3C", "FUN_06041D6C", "FUN_06041EE8",
    "FUN_06042088", "FUN_06042134", "FUN_060423CC", "FUN_060429EC",
]

# 6 orphan functions with no source anywhere
ORPHAN_FUNCTIONS = [
    "FUN_06006F3C", "FUN_06007268", "FUN_06008EBC",
    "FUN_06009098", "FUN_06009290", "FUN_060092D0",
]

# Address range to batch file mapping (same as gen_l1_batch.py)
def classify_address(addr_int):
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


def read_src_file(func_name):
    """Read src/FUN_XXXXXXXX.c, return content."""
    path = os.path.join(SRC_DIR, f"{func_name}.c")
    if not os.path.exists(path):
        # Try lowercase
        path = os.path.join(SRC_DIR, f"{func_name.lower()}.c")
    if not os.path.exists(path):
        return None
    with open(path, "r", errors="replace") as f:
        return f.read().replace("\r\n", "\n").replace("\r", "\n")


def strip_comments(content):
    """Remove C comments."""
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
    content = re.sub(r'//[^\n]*', '', content)
    return content


def get_existing_externs(batch_path):
    """Get set of extern declarations already in a batch file."""
    externs = set()
    if os.path.exists(batch_path):
        with open(batch_path, "r", errors="replace") as f:
            for line in f:
                stripped = line.strip()
                if stripped.startswith("extern "):
                    externs.add(stripped)
    return externs


def main():
    # Group functions by batch file
    groups = {}
    for func in FUNCTIONS_WITH_SOURCE:
        addr = int(func.replace("FUN_", ""), 16)
        group = classify_address(addr)
        if group not in groups:
            groups[group] = []
        groups[group].append(func)

    print(f"Importing {len(FUNCTIONS_WITH_SOURCE)} functions into {len(groups)} batch files:\n")

    total_imported = 0
    for group in sorted(groups.keys()):
        funcs = groups[group]
        batch_path = os.path.join(REIMPL_DIR, f"batch_{group}.c")
        exists = os.path.exists(batch_path)

        # Collect externs and function bodies
        new_externs = []
        new_bodies = []
        existing_externs = get_existing_externs(batch_path) if exists else set()

        for func in funcs:
            content = read_src_file(func)
            if content is None:
                print(f"  WARNING: can't read {func}")
                continue

            content = strip_comments(content)

            # Separate externs from function body
            extern_lines = []
            body_lines = []
            for line in content.split("\n"):
                stripped = line.strip()
                if stripped.startswith("extern "):
                    if stripped not in existing_externs and stripped not in [e for e in new_externs]:
                        new_externs.append(stripped)
                        existing_externs.add(stripped)
                else:
                    body_lines.append(line)

            # Clean up body
            body = "\n".join(body_lines).strip()
            if body:
                new_bodies.append(f"\n/* --- {func} (imported from src/{func}.c) --- */\n\n{body}\n")

        if not new_bodies:
            continue

        if exists:
            # Append to existing file
            with open(batch_path, "r", errors="replace") as f:
                existing = f.read()

            # Add new externs at the top (after existing externs)
            if new_externs:
                # Find insertion point: after last extern line
                lines = existing.split("\n")
                insert_idx = 0
                for i, line in enumerate(lines):
                    if line.strip().startswith("extern "):
                        insert_idx = i + 1
                # If no externs found, insert at the very beginning
                if insert_idx == 0:
                    insert_idx = 0

                for ext in sorted(set(new_externs)):
                    lines.insert(insert_idx, ext)
                    insert_idx += 1

                existing = "\n".join(lines)

            # Append function bodies at end
            with open(batch_path, "w", newline="\n") as f:
                f.write(existing.rstrip("\n") + "\n")
                for body in new_bodies:
                    f.write(body)

            print(f"  APPEND {batch_path}: +{len(funcs)} functions")
        else:
            # Create new file
            out = []
            if new_externs:
                for e in sorted(set(new_externs)):
                    out.append(e)
                out.append("")

            for body in new_bodies:
                out.append(body)

            with open(batch_path, "w", newline="\n") as f:
                f.write("\n".join(out))

            print(f"  CREATE {batch_path}: {len(funcs)} functions")

        total_imported += len(funcs)

    print(f"\nImported {total_imported} functions total")

    # Now regenerate missing_stubs.c with ONLY the 6 orphans
    print(f"\nRegenerating missing_stubs.c with {len(ORPHAN_FUNCTIONS)} orphan stubs...")
    stubs_path = os.path.join(REIMPL_DIR, "missing_stubs.c")

    lines = []
    lines.append("/* missing_stubs.c -- rts/nop stubs for 6 orphan functions.")
    lines.append(" *")
    lines.append(" * These functions exist in the original binary but have NO source code")
    lines.append(" * anywhere -- not in src/*.c (old decomp) nor reimpl/src/ (reimpl).")
    lines.append(" * They are likely hand-written ASM by Sega AM2 that Ghidra could not")
    lines.append(" * decompile (interrupt handlers, state machines, etc).")
    lines.append(" *")
    lines.append(f" * Generated by tools/import_missing_funcs.py ({len(ORPHAN_FUNCTIONS)} stubs)")
    lines.append(" */")
    lines.append("")
    lines.append("__asm__(")

    for func in ORPHAN_FUNCTIONS:
        addr = func.replace("FUN_", "0x")
        lines.append(f'    /* {func} @ {addr} */')
        lines.append(f'    ".section .text.{func}, \\"ax\\"\\n"')
        lines.append(f'    ".balign 2\\n"')
        lines.append(f'    ".global _{func}\\n"')
        lines.append(f'    ".type _{func}, @function\\n"')
        lines.append(f'    "_{func}:\\n"')
        lines.append(f'    ".word 0x000B\\n"  /* rts */')
        lines.append(f'    ".word 0x0009\\n"  /* nop (delay slot) */')
        lines.append(f'')

    lines.append(");")
    lines.append("")

    with open(stubs_path, "w", newline="\n") as f:
        f.write("\n".join(lines))

    print(f"  Wrote {stubs_path}: {len(ORPHAN_FUNCTIONS)} stubs")
    print("\nDone!")


if __name__ == "__main__":
    main()
