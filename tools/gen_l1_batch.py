#!/usr/bin/env python3
"""Generate L1 reimpl C files from decomp src/*.c files.

Groups functions by address range into themed files.
Strips comments (cc1 can't handle them).
Fixes common Ghidra output issues.
"""

import os
import re
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(PROJ, "src")
REIMPL_DIR = os.path.join(PROJ, "reimpl", "src")

def get_done_functions():
    """Get set of FUN_ names already in reimpl."""
    done = set()
    for fname in os.listdir(REIMPL_DIR):
        if not fname.endswith(".c"):
            continue
        path = os.path.join(REIMPL_DIR, fname)
        with open(path, "r", errors="replace") as f:
            content = f.read()
        for m in re.finditer(r'FUN_([0-9A-Fa-f]{8})', content):
            done.add(m.group(1).lower())
    return done

def read_src_file(addr):
    """Read a src/FUN_XXXXXXXX.c file, return cleaned content."""
    # Try both cases
    for case_addr in [addr, addr.upper(), addr.lower()]:
        path = os.path.join(SRC_DIR, f"FUN_{case_addr}.c")
        if os.path.exists(path):
            with open(path, "r", errors="replace") as f:
                content = f.read()
            return content.replace("\r\n", "\n").replace("\r", "\n")
    return None

def strip_comments(content):
    """Remove C comments since cc1 can't handle them."""
    # Remove /* ... */ comments
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
    # Remove // comments
    content = re.sub(r'//[^\n]*', '', content)
    return content

def normalize_function(content, addr):
    """Clean up Ghidra output for compilation."""
    content = strip_comments(content)

    # Fix function name case to be consistent
    content = re.sub(
        rf'FUN_{addr}',
        f'FUN_{addr}',
        content,
        flags=re.IGNORECASE
    )

    return content.strip() + "\n"

def classify_address(addr_int):
    """Classify function by address range into a subsystem group."""
    if 0x06002000 <= addr_int < 0x06004000:
        return "system_low"
    elif 0x06004000 <= addr_int < 0x06006000:
        return "game_init"
    elif 0x06005000 <= addr_int < 0x06008000:
        return "game_core"
    elif 0x06008000 <= addr_int < 0x0600A000:
        return "state_machine"
    elif 0x0600A000 <= addr_int < 0x0600C000:
        return "game_logic_a"
    elif 0x0600C000 <= addr_int < 0x0600E000:
        return "game_logic_b"
    elif 0x0600E000 <= addr_int < 0x06010000:
        return "game_logic_c"
    elif 0x06010000 <= addr_int < 0x06012000:
        return "subsystem_10"
    elif 0x06012000 <= addr_int < 0x06014000:
        return "subsystem_12"
    elif 0x06014000 <= addr_int < 0x06016000:
        return "subsystem_14"
    elif 0x06016000 <= addr_int < 0x06018000:
        return "subsystem_16"
    elif 0x06018000 <= addr_int < 0x0601A000:
        return "subsystem_18"
    elif 0x0601A000 <= addr_int < 0x0601C000:
        return "subsystem_1a"
    elif 0x0601C000 <= addr_int < 0x0601E000:
        return "subsystem_1c"
    elif 0x0601E000 <= addr_int < 0x06020000:
        return "subsystem_1e"
    elif 0x06020000 <= addr_int < 0x06022000:
        return "rendering_20"
    elif 0x06022000 <= addr_int < 0x06026000:
        return "rendering_22"
    elif 0x06026000 <= addr_int < 0x06028000:
        return "math_util_26"
    elif 0x06028000 <= addr_int < 0x0602A000:
        return "vdp_cmd_28"
    elif 0x0602A000 <= addr_int < 0x0602E000:
        return "render_pipe_2a"
    elif 0x0602E000 <= addr_int < 0x06030000:
        return "render_pipe_2e"
    elif 0x06030000 <= addr_int < 0x06032000:
        return "scene_30"
    elif 0x06032000 <= addr_int < 0x06034000:
        return "scene_32"
    elif 0x06034000 <= addr_int < 0x06036000:
        return "cd_system_34"
    elif 0x06036000 <= addr_int < 0x06038000:
        return "cd_system_36"
    elif 0x06038000 <= addr_int < 0x0603A000:
        return "obj_system_38"
    elif 0x0603A000 <= addr_int < 0x0603C000:
        return "obj_system_3a"
    elif 0x0603C000 <= addr_int < 0x0603E000:
        return "obj_system_3c"
    elif 0x0603E000 <= addr_int < 0x06040000:
        return "obj_system_3e"
    elif 0x06040000 <= addr_int < 0x06042000:
        return "session_40"
    elif 0x06042000 <= addr_int < 0x06044000:
        return "session_42"
    else:
        return "misc"

def main():
    done = get_done_functions()
    print(f"Already translated: {len(done)} functions")

    # Find all remaining src files
    remaining = {}
    for fname in sorted(os.listdir(SRC_DIR)):
        m = re.match(r'FUN_([0-9A-Fa-f]{8})\.c$', fname, re.IGNORECASE)
        if not m:
            continue
        addr = m.group(1).lower()
        if addr in done:
            continue
        remaining[addr] = fname

    print(f"Remaining to translate: {len(remaining)} functions")

    # Group by subsystem
    groups = {}
    for addr in sorted(remaining.keys()):
        addr_int = int(addr, 16)
        group = classify_address(addr_int)
        if group not in groups:
            groups[group] = []
        groups[group].append(addr)

    print(f"\nGroups:")
    for group in sorted(groups.keys()):
        print(f"  {group}: {len(groups[group])} functions")

    # Generate reimpl files
    total_written = 0
    for group in sorted(groups.keys()):
        addrs = groups[group]
        outpath = os.path.join(REIMPL_DIR, f"batch_{group}.c")

        # Skip if file already exists
        if os.path.exists(outpath):
            print(f"  SKIP {outpath} (already exists)")
            continue

        lines = []
        extern_lines = []
        func_lines = []

        for addr in addrs:
            content = read_src_file(addr)
            if content is None:
                print(f"  WARNING: can't read FUN_{addr}")
                continue

            content = normalize_function(content, addr)

            # Separate externs from function body
            for line in content.split("\n"):
                stripped = line.strip()
                if stripped.startswith("extern "):
                    if stripped not in extern_lines:
                        extern_lines.append(stripped)
                else:
                    func_lines.append(line)

        # Build output file
        out = []
        if extern_lines:
            for e in sorted(set(extern_lines)):
                out.append(e)
            out.append("")

        out.extend(func_lines)

        content = "\n".join(out)
        # Clean up excessive blank lines
        while "\n\n\n" in content:
            content = content.replace("\n\n\n", "\n\n")

        with open(outpath, "w", newline="\n") as f:
            f.write(content)

        total_written += len(addrs)
        print(f"  WROTE {outpath}: {len(addrs)} functions")

    print(f"\nTotal newly written: {total_written} functions")

if __name__ == "__main__":
    main()
