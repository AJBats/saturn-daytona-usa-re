#!/usr/bin/env python3
"""Disable functions with compilation errors by wrapping in #if 0.

Compiles each batch file, finds errors, identifies which functions they're in,
and wraps those functions in #if 0 / #endif with a stub replacement.
"""

import os
import re
import subprocess
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REIMPL_DIR = os.path.join(PROJ, "reimpl", "src")
GCC = "/mnt/d/Projects/SaturnReverseTest/tools/sh-elf/bin/sh-elf-gcc"
CFLAGS = "-m2 -mb -O2 -Wall -nostdlib -ffreestanding -fno-builtin -I/mnt/d/Projects/SaturnReverseTest/reimpl/include -fsyntax-only"

def get_errors(filepath):
    """Compile a file and return list of (line_number, error_message)."""
    wsl_path = filepath.replace("\\", "/").replace("d:", "/mnt/d").replace("D:", "/mnt/d")
    cmd = f'wsl -d Ubuntu -- {GCC} {CFLAGS} {wsl_path} 2>&1'
    try:
        result = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=30)
        output = result.stdout + result.stderr
    except subprocess.TimeoutExpired:
        return []

    errors = []
    for line in output.split('\n'):
        m = re.search(r':(\d+):\d+: error:', line)
        if m:
            errors.append(int(m.group(1)))
    return sorted(set(errors))

def find_function_boundaries(content):
    """Find start/end line numbers for each function definition."""
    lines = content.split('\n')
    functions = []
    i = 0
    while i < len(lines):
        line = lines[i]
        stripped = line.strip()
        # Skip externs and blank lines
        if stripped.startswith('extern') or not stripped:
            i += 1
            continue

        # Look for function definition: type FUN_XXX( or FUN_XXX(param)
        m = re.match(r'^(?:(?:unsigned\s+)?(?:long\s+long|int|short|char|void)(?:\s*\*)*\s+)?(FUN_[0-9A-Fa-f]+)\s*\(', stripped)
        if not m:
            # K&R style: FUN_XXX(param_1, param_2)
            m = re.match(r'^(FUN_[0-9A-Fa-f]+)\s*\(', stripped)

        if m:
            func_name = m.group(1)
            func_start = i

            # Find the opening brace
            brace_depth = 0
            found_open = False
            j = i
            while j < len(lines):
                for ch in lines[j]:
                    if ch == '{':
                        brace_depth += 1
                        found_open = True
                    elif ch == '}':
                        brace_depth -= 1
                        if found_open and brace_depth == 0:
                            functions.append((func_name, func_start, j))
                            i = j + 1
                            found_open = False
                            break
                else:
                    j += 1
                    continue
                break
            else:
                i += 1
                continue
            continue
        i += 1
    return functions

def disable_broken_functions(filepath):
    """Wrap functions with errors in #if 0 and add stub."""
    with open(filepath, 'r', errors='replace') as f:
        content = f.read()

    error_lines = get_errors(filepath)
    if not error_lines:
        return 0

    functions = find_function_boundaries(content)
    lines = content.split('\n')

    # Find which functions contain error lines
    broken_funcs = set()
    for err_line in error_lines:
        err_idx = err_line - 1  # 0-indexed
        for func_name, start, end in functions:
            if start <= err_idx <= end:
                broken_funcs.add(func_name)
                break

    if not broken_funcs:
        print(f"  WARNING: {os.path.basename(filepath)} has errors but can't identify functions")
        return 0

    # Wrap broken functions in #if 0
    modifications = []
    for func_name, start, end in functions:
        if func_name in broken_funcs:
            modifications.append((func_name, start, end))

    # Apply modifications in reverse order to preserve line numbers
    for func_name, start, end in reversed(sorted(modifications, key=lambda x: x[1])):
        # Find the return type line (may be before the function name)
        actual_start = start
        # Check if previous non-blank line has the return type
        if start > 0:
            prev = start - 1
            while prev >= 0 and lines[prev].strip() == '':
                prev -= 1
            if prev >= 0:
                prev_stripped = lines[prev].strip()
                # If previous line looks like just a return type
                if prev_stripped in ['void', 'int', 'unsigned int', 'short', 'char', 'char *',
                                     'unsigned short', 'unsigned char', 'long long']:
                    actual_start = prev

        # Extract function signature to create a stub
        # Determine return type
        func_line = lines[start].strip()
        ret_type = 'int'
        for t in ['void', 'unsigned int', 'unsigned short', 'short', 'char *', 'char',
                   'long long', 'int']:
            if func_line.startswith(t + ' '):
                ret_type = t
                break

        # Get parameter list
        params_match = re.search(r'\(([^)]*)\)', func_line)
        params = params_match.group(1) if params_match else ''

        # Create stub
        if ret_type == 'void':
            stub = f'{ret_type} {func_name}({params}) {{ }}'
        else:
            stub = f'{ret_type} {func_name}({params}) {{ return 0; }}'

        # Wrap in #if 0
        lines[actual_start] = f'#if 0\n{lines[actual_start]}'
        lines[end] = f'{lines[end]}\n#endif\n{stub}'

    with open(filepath, 'w', newline='\n') as f:
        f.write('\n'.join(lines))

    print(f"  {os.path.basename(filepath)}: disabled {len(broken_funcs)} functions: {', '.join(sorted(broken_funcs))}")
    return len(broken_funcs)

def main():
    total = 0
    for fname in sorted(os.listdir(REIMPL_DIR)):
        if not fname.startswith('batch_') or not fname.endswith('.c'):
            continue
        filepath = os.path.join(REIMPL_DIR, fname)
        total += disable_broken_functions(filepath)
    print(f"\nTotal disabled: {total} functions")

if __name__ == "__main__":
    main()
