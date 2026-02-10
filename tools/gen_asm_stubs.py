#!/usr/bin/env python3
"""Generate C stubs for ASM-only functions.

For the L1 pass, these are no-op stubs so the linker can resolve
function pointer references. The actual translation happens in L2.

Groups functions by address range, same as the decomp batch files.
"""

import os
import re

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REIMPL_DIR = os.path.join(PROJ, "reimpl", "src")

def get_aprog_functions():
    """Get all function labels from aprog.s."""
    funcs = set()
    aprog_path = os.path.join(PROJ, "build", "aprog.s")
    with open(aprog_path, 'r', errors='replace') as f:
        for line in f:
            line = line.strip()
            m = re.match(r'^(FUN_[0-9A-Fa-f]{8}):$', line)
            if m:
                funcs.add(m.group(1).upper())
    return funcs

def get_decomp_functions():
    """Get functions that have decomp C source."""
    funcs = set()
    src_dir = os.path.join(PROJ, "src")
    for fname in os.listdir(src_dir):
        m = re.match(r'(FUN_[0-9A-Fa-f]{8})\.c$', fname, re.IGNORECASE)
        if m:
            funcs.add(m.group(1).upper())
    return funcs

def get_reimpl_defined():
    """Get functions already defined in reimpl (not just referenced)."""
    defined = set()
    for fname in os.listdir(REIMPL_DIR):
        if not fname.endswith('.c'):
            continue
        filepath = os.path.join(REIMPL_DIR, fname)
        with open(filepath, 'r', errors='replace') as f:
            content = f.read()
        # Match function definitions (not externs, not inside #if 0)
        in_if0 = False
        for line in content.split('\n'):
            stripped = line.strip()
            if stripped == '#if 0':
                in_if0 = True
            elif stripped == '#endif':
                in_if0 = False
            if in_if0:
                continue
            if stripped.startswith('extern'):
                continue
            m = re.match(r'^(?:(?:unsigned\s+)?(?:long\s+long|int|short|char|void)(?:\s*\*)*\s+)?(FUN_[0-9A-Fa-f]+)\s*\(', stripped)
            if m:
                defined.add(m.group(1).upper())
    return defined

def get_linker_stub_functions():
    """Get functions defined in linker_stubs.c."""
    defined = set()
    path = os.path.join(REIMPL_DIR, 'linker_stubs.c')
    if os.path.exists(path):
        with open(path, 'r', errors='replace') as f:
            for line in f:
                m = re.search(r'\b(FUN_[0-9A-Fa-f]+)\b', line)
                if m and not line.strip().startswith('extern'):
                    defined.add(m.group(1).upper())
    return defined

def classify_address(addr_str):
    addr_int = int(addr_str.replace('FUN_', ''), 16)
    if 0x06008800 <= addr_int < 0x0600A000:
        return "asm_state_handlers"
    elif 0x06003000 <= addr_int < 0x06006000:
        return "asm_system_low"
    elif 0x06006000 <= addr_int < 0x06008800:
        return "asm_game_core"
    elif 0x0600A000 <= addr_int < 0x0600E000:
        return "asm_game_logic"
    elif 0x0600E000 <= addr_int < 0x06014000:
        return "asm_subsystems_0e_14"
    elif 0x06014000 <= addr_int < 0x06020000:
        return "asm_subsystems_14_20"
    elif 0x06020000 <= addr_int < 0x06030000:
        return "asm_rendering"
    elif 0x06030000 <= addr_int < 0x06040000:
        return "asm_scene_cd_obj"
    elif 0x06040000 <= addr_int < 0x06044000:
        return "asm_session"
    else:
        return "asm_misc"

def main():
    aprog = get_aprog_functions()
    decomp = get_decomp_functions()
    reimpl = get_reimpl_defined()
    linker_stubs = get_linker_stub_functions()

    print(f"aprog.s functions: {len(aprog)}")
    print(f"decomp functions: {len(decomp)}")
    print(f"reimpl defined: {len(reimpl)}")
    print(f"linker stub functions: {len(linker_stubs)}")

    # Find ASM-only functions not yet defined
    asm_only_needed = []
    for addr in sorted(aprog):
        if addr in decomp:
            continue  # Has decomp source, handled by batch files
        if addr in reimpl:
            continue  # Already in reimpl
        if addr in linker_stubs:
            continue  # Already has linker stub
        asm_only_needed.append(addr)

    print(f"ASM-only needing stubs: {len(asm_only_needed)}")

    # Group by category
    groups = {}
    for addr in asm_only_needed:
        group = classify_address(addr)
        if group not in groups:
            groups[group] = []
        groups[group].append(addr)

    for group in sorted(groups):
        print(f"  {group}: {len(groups[group])}")

    # Generate stub files
    total = 0
    for group in sorted(groups):
        addrs = groups[group]
        outpath = os.path.join(REIMPL_DIR, f"{group}.c")

        if os.path.exists(outpath):
            print(f"  SKIP {outpath} (exists)")
            continue

        lines = []
        for addr in sorted(addrs):
            lines.append(f'void {addr}(void) {{ }}')

        with open(outpath, 'w', newline='\n') as f:
            f.write('\n'.join(lines) + '\n')

        total += len(addrs)
        print(f"  WROTE {outpath}: {len(addrs)} stubs")

    print(f"\nTotal stubs written: {total}")

if __name__ == "__main__":
    main()
