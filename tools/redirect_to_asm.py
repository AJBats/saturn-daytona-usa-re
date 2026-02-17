#!/usr/bin/env python3
"""redirect_to_asm.py -- Redirect named C functions to their FUN_ ASM imports.

For functions that have both:
  1. A named C implementation (e.g., state_0_handler in pre_race_state_handlers.c)
  2. An ASM byte import for the corresponding FUN_ address

This tool wraps the C implementation in #if 0 and adds a reverse alias:
  extern void FUN_060088CC(void);
  void state_0_handler(void) __attribute__((alias("FUN_060088CC")));

This eliminates the C code from the binary, reducing overflow, while the
state_handlers[] array still works (pointing to the ASM import's code).

Usage:
  python redirect_to_asm.py --scan     # Show what would be redirected
  python redirect_to_asm.py --apply    # Apply redirections
"""

import re
import os
import glob
import sys

SRC_DIR = os.path.join(os.path.dirname(__file__), '..', 'reimpl', 'src')

# State handler address map (from main.c jump table comments)
STATE_HANDLER_MAP = {
    'state_0_handler':  'FUN_060088CC',
    'state_1_handler':  'FUN_0600890A',
    'state_2_handler':  'FUN_06008938',
    'state_3_handler':  'FUN_06008A18',
    'state_4_handler':  'FUN_06008CCC',
    'state_5_handler':  'FUN_06008D74',
    'state_6_handler':  'FUN_06008B04',
    'state_7_handler':  'FUN_06008B34',
    'state_8_handler':  'FUN_06008B78',
    'state_9_handler':  'FUN_06008B9C',
    'state_10_handler': 'FUN_06008BD8',
    'state_11_handler': 'FUN_06008BFC',
    'state_12_handler': 'FUN_06008E00',
    'state_13_handler': 'FUN_06008E48',
    'state_14_handler': 'FUN_06008EBC',
    'state_15_handler': 'FUN_06009098',
    'state_16_handler': 'FUN_06009290',
    'state_17_handler': 'FUN_060092D0',
    'state_18_handler': 'FUN_060096DC',
    'state_19_handler': 'FUN_06009788',
    'state_20_handler': 'FUN_06009A60',
    'state_21_handler': 'FUN_06009C48',
    'state_22_handler': 'FUN_06009E60',
    'state_23_handler': 'FUN_06009F10',
    'state_24_handler': 'FUN_06009CFC',
    'state_25_handler': 'FUN_06009D4E',
    'state_26_handler': 'FUN_06009DD0',
    'state_27_handler': 'FUN_06009E02',
    'state_28_handler': 'FUN_06009508',
    'state_29_handler': 'FUN_0600955E',
    'state_30_handler': 'FUN_06008C14',
    'state_31_handler': 'FUN_06008C76',
}

# Known named functions with their FUN_ addresses (hand-written reimpl files)
# These are functions that have C implementations AND ASM imports for the same address
NAMED_FUNCTION_MAP = {
    # From stubs.c / init chain
    'system_init':            'FUN_060030FC',
    'course_system_init':     'FUN_0603BF7C',
    'game_subsystem_init':    'FUN_06012CF4',
    'game_subsystem_init2':   'FUN_06012E6A',
    'cd_system_init':         'FUN_06018EE4',
    'object_system_init':     'FUN_06005174',

    # From game_state_utils.c
    'vdp_system_init_b':      'FUN_060149CC',

    # From vdp1_cmd.c
    'vdp2_scroll_setup':      'FUN_06004A98',
    'vdp2_scroll_update':     'FUN_060055BC',
    'vdp_system_init_a':      'FUN_0601492C',

    # From sound_channel.c
    'vdp1_texture_palette_init': 'FUN_06026CE0',

    # From scu_dma.c
    'scu_dma_transfer':       'FUN_0602766C',

    # From cd_command.c
    'cd_status_read':         'FUN_06018EAC',

    # From per_frame_setup.c (if it has a FUN_ address)
    'per_frame_setup':        'FUN_060032D4',
}


def find_asm_imports():
    """Find all FUN_ addresses that have ASM byte imports."""
    asm_funs = set()
    for cfile in glob.glob(os.path.join(SRC_DIR, '*.c')):
        with open(cfile, 'r') as f:
            content = f.read()
        # Find .global _FUN_XXXXXX in active (not #if 0) asm blocks
        for m in re.finditer(r'\.global\s+_FUN_([0-9a-fA-F]{6,8})', content):
            addr = m.group(1).upper()
            # Check if this is inside #if 0 ... #endif
            pos = m.start()
            # Simple heuristic: count #if 0 and #endif before this position
            before = content[:pos]
            if0_count = len(re.findall(r'#if\s+0', before))
            endif_count = len(re.findall(r'#endif', before))
            if if0_count <= endif_count:
                asm_funs.add(f'FUN_{addr}')
    return asm_funs


def find_named_function_files():
    """Find which files contain named function definitions."""
    func_files = {}  # name -> (file, line_num)

    for cfile in sorted(glob.glob(os.path.join(SRC_DIR, '*.c'))):
        basename = os.path.basename(cfile)
        with open(cfile, 'r') as f:
            lines = f.readlines()

        in_if0 = 0
        for i, line in enumerate(lines):
            stripped = line.strip()
            if stripped.startswith('#if 0'):
                in_if0 += 1
            elif stripped.startswith('#endif') and in_if0 > 0:
                in_if0 -= 1

            if in_if0 > 0:
                continue

            # Match function definitions
            m = re.match(r'^(?:void|int|unsigned|short|char|long)\s+(\w+)\s*\(', line)
            if m:
                name = m.group(1)
                if not name.startswith('FUN_'):
                    func_files[name] = (basename, i + 1)

    return func_files


def verify_asm_import_exists(fun_name, asm_imports):
    """Check if a FUN_ has an active ASM import."""
    return fun_name in asm_imports


def scan():
    """Scan and report what can be redirected."""
    asm_imports = find_asm_imports()
    func_files = find_named_function_files()

    print(f"Found {len(asm_imports)} ASM imports")
    print(f"Found {len(func_files)} named function definitions")
    print()

    # Check state handlers
    print("=== State Handlers ===")
    can_redirect = 0
    for name, fun in sorted(STATE_HANDLER_MAP.items()):
        has_asm = fun in asm_imports
        has_def = name in func_files
        status = "OK" if has_asm and has_def else "SKIP"
        if has_asm and has_def:
            can_redirect += 1
            file_info = func_files[name]
            print(f"  {name} -> {fun} [{file_info[0]}:{file_info[1]}]")
        else:
            reason = []
            if not has_asm:
                reason.append(f"no ASM for {fun}")
            if not has_def:
                reason.append("no C def")
            print(f"  {name} -> {fun} SKIP ({', '.join(reason)})")
    print(f"\nCan redirect: {can_redirect}/{len(STATE_HANDLER_MAP)} state handlers")

    # Check other named functions
    print("\n=== Other Named Functions ===")
    other_count = 0
    for name, fun in sorted(NAMED_FUNCTION_MAP.items()):
        has_asm = fun in asm_imports
        has_def = name in func_files
        if has_asm and has_def:
            other_count += 1
            file_info = func_files[name]
            print(f"  {name} -> {fun} [{file_info[0]}:{file_info[1]}]")
        else:
            reason = []
            if not has_asm:
                reason.append(f"no ASM for {fun}")
            if not has_def:
                reason.append("no C def")
            print(f"  {name} -> {fun} SKIP ({', '.join(reason)})")
    print(f"\nCan redirect: {other_count}/{len(NAMED_FUNCTION_MAP)} named functions")


def apply_state_handler_redirects(asm_imports, dry_run=True):
    """Add reverse aliases for state handlers and wrap C code in #if 0."""

    # Group by file
    files_to_modify = {
        'pre_race_state_handlers.c': {},  # name -> fun
        'race_state_handlers.c': {},
    }

    func_files = find_named_function_files()

    for name, fun in STATE_HANDLER_MAP.items():
        if fun not in asm_imports:
            continue
        if name not in func_files:
            continue
        filename = func_files[name][0]
        if filename in files_to_modify:
            files_to_modify[filename][name] = fun

    for filename, redirects in files_to_modify.items():
        if not redirects:
            continue

        filepath = os.path.join(SRC_DIR, filename)
        with open(filepath, 'r') as f:
            content = f.read()

        # For each function, wrap in #if 0 and add alias
        for name, fun in sorted(redirects.items()):
            # Find the function definition
            # Pattern: void state_X_handler(void)\n{
            pattern = re.compile(
                rf'((?:/\*[\s\S]*?\*/\s*)?)(void\s+{re.escape(name)}\s*\([^)]*\)\s*\{{)',
                re.MULTILINE
            )
            m = pattern.search(content)
            if not m:
                print(f"  WARNING: Could not find {name} in {filename}")
                continue

            # Find the matching closing brace
            start = m.start(2)
            brace_count = 0
            end = start
            for i in range(start, len(content)):
                if content[i] == '{':
                    brace_count += 1
                elif content[i] == '}':
                    brace_count -= 1
                    if brace_count == 0:
                        end = i + 1
                        break

            # Check if already redirected
            if f'__attribute__((alias("{fun}")))' in content[max(0,start-200):start]:
                print(f"  {name} already redirected in {filename}")
                continue

            # Build replacement
            func_body = content[m.start(2):end]
            comment_block = m.group(1)

            replacement = f"""{comment_block}/* Redirected to ASM import -- C reimpl preserved below */
extern void {fun}(void);
void {name}(void) __attribute__((alias("{fun}")));
#if 0 /* {name} -- C reimpl (L2+), ASM import used for binary match */
{func_body}
#endif"""

            content = content[:m.start()] + replacement + content[end:]
            print(f"  Redirected {name} -> {fun} in {filename}")

        if not dry_run:
            with open(filepath, 'w') as f:
                f.write(content)


if __name__ == '__main__':
    if '--apply' in sys.argv:
        asm_imports = find_asm_imports()
        print("Applying state handler redirects...")
        apply_state_handler_redirects(asm_imports, dry_run=False)
    else:
        scan()
