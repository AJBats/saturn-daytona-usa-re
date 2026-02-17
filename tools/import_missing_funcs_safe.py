#!/usr/bin/env python3
"""import_missing_funcs_safe.py -- Safely import missing functions into reimpl.

SAFE import: appends function BODIES ONLY to batch files.
- Does NOT add extern declarations (avoids conflicts with existing code)
- Fixes Ghidra artifacts ONLY in the imported function body
- Does NOT modify any existing code in the batch file
- Overlaps from larger code are expected and acceptable (same as all L1 code)

Usage:
    python tools/import_missing_funcs_safe.py
"""

import os
import re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(PROJDIR, "src")
REIMPL_DIR = os.path.join(PROJDIR, "reimpl", "src")

# 69 functions with src/*.c source code
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

# 6 orphan functions (no source anywhere) -- inline asm stubs
ORPHAN_FUNCTIONS = [
    "FUN_06006F3C", "FUN_06007268", "FUN_06008EBC",
    "FUN_06009098", "FUN_06009290", "FUN_060092D0",
]


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


def read_src_file(func_name):
    """Read src/FUN_XXXXXXXX.c, return content."""
    for name in [func_name, func_name.upper(), func_name.lower()]:
        path = os.path.join(SRC_DIR, f"{name}.c")
        if os.path.exists(path):
            with open(path, "r", errors="replace") as f:
                return f.read().replace("\r\n", "\n").replace("\r", "\n")
    return None


def strip_comments(content):
    """Remove C comments."""
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
    content = re.sub(r'//[^\n]*', '', content)
    return content


def fix_ghidra_in_body(body):
    """Fix common Ghidra artifacts WITHIN a function body only."""
    # *(int)ptr -> *(int *)ptr
    body = re.sub(r'\*\((int|short|char|unsigned int|unsigned short|unsigned char)\)(\w)',
                  r'*(\1 *)\2', body)
    # (char)ADDR[idx] -> ((char *)ADDR)[idx]
    body = re.sub(r'\((char|int|short)\)(0x[0-9a-fA-F]+)\[',
                  r'((\1 *)\2)[', body)
    # puVar = 0xADDR; where puVar is char* -> puVar = (char *)0xADDR;
    body = re.sub(r'(puVar\d+)\s*=\s*(0x[0-9a-fA-F]+);',
                  r'\1 = (char *)\2;', body)
    return body


def extract_body_only(content, func_name):
    """Extract just the function body, no externs.

    Returns the function signature + body, stripping extern declarations.
    Also applies targeted Ghidra fixes to the body only.
    """
    content = strip_comments(content)

    lines = content.split("\n")
    body_lines = []
    in_body = False
    brace_depth = 0

    for line in lines:
        stripped = line.strip()

        # Skip extern declarations entirely
        if stripped.startswith("extern "):
            continue

        # Skip empty lines before function start
        if not in_body and stripped == "":
            continue

        # Detect function start (return type + name)
        if not in_body and re.match(r'(int|void|char|short|unsigned|long|\w+\s*\*)', stripped):
            in_body = True

        if in_body:
            body_lines.append(line)
            brace_depth += line.count('{') - line.count('}')

            # Function complete when braces balance
            if brace_depth == 0 and '{' in ''.join(body_lines):
                break

    body = "\n".join(body_lines).strip()

    # Apply targeted Ghidra fixes
    body = fix_ghidra_in_body(body)

    return body


def make_orphan_stub(func):
    """Generate an inline asm stub for an orphan function."""
    return (
        f'\n/* {func} -- Class 4 stub (no source exists) */\n'
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
    # --- Phase 1: Import 69 functions with source ---
    groups = {}
    for func in FUNCTIONS_WITH_SOURCE:
        addr = int(func.replace("FUN_", ""), 16)
        group = classify_address(addr)
        if group not in groups:
            groups[group] = []
        groups[group].append(func)

    print(f"Importing {len(FUNCTIONS_WITH_SOURCE)} functions into {len(groups)} batch files")
    print("(body only, no extern modifications)\n")

    total_imported = 0
    broken = []

    for group in sorted(groups.keys()):
        funcs = groups[group]
        batch_path = os.path.join(REIMPL_DIR, f"batch_{group}.c")

        if not os.path.exists(batch_path):
            print(f"  WARNING: {batch_path} doesn't exist!")
            continue

        append_text = ""
        count = 0

        for func in funcs:
            content = read_src_file(func)
            if content is None:
                print(f"  WARNING: can't read {func}")
                continue

            body = extract_body_only(content, func)
            if not body:
                print(f"  WARNING: empty body for {func}")
                continue

            # Check for severe artifacts that would cause compile errors
            has_severe = False
            if re.search(r'\*\((int|char|short)\)\(', body):
                has_severe = True
            if re.search(r'&\((int|char)\)', body):
                has_severe = True

            if has_severe:
                broken.append(func)
                # Use inline asm stub instead
                append_text += make_orphan_stub(func)
                count += 1
                continue

            append_text += f"\n/* --- {func} (L1 import from src/{func}.c) --- */\n\n"
            append_text += body + "\n"
            count += 1

        if append_text:
            with open(batch_path, "a", newline="\n") as f:
                f.write(append_text)
            print(f"  {os.path.basename(batch_path)}: +{count} functions")
            total_imported += count

    # --- Phase 2: Orphan stubs (no source anywhere) ---
    orphan_groups = {}
    for func in ORPHAN_FUNCTIONS:
        addr = int(func.replace("FUN_", ""), 16)
        group = classify_address(addr)
        if group not in orphan_groups:
            orphan_groups[group] = []
        orphan_groups[group].append(func)

    for group in sorted(orphan_groups.keys()):
        funcs = orphan_groups[group]
        batch_path = os.path.join(REIMPL_DIR, f"batch_{group}.c")

        with open(batch_path, "a", newline="\n") as f:
            for func in funcs:
                f.write(make_orphan_stub(func))

        total_imported += len(funcs)
        print(f"  {os.path.basename(batch_path)}: +{len(funcs)} orphan stubs")

    print(f"\nTotal: {total_imported} functions added")
    if broken:
        print(f"\n{len(broken)} functions had severe Ghidra artifacts (using asm stubs):")
        for f in broken:
            print(f"  {f}")
    print("\nDone. No existing code was modified.")


if __name__ == "__main__":
    main()
