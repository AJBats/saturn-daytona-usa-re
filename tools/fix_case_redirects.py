#!/usr/bin/env python3
"""Fix case mismatch bugs: replace uppercase no-op stubs with forwarding calls.

Problem: asm_*.c has UPPERCASE stubs like `void FUN_0600330A(void) { }`
         batch_*.c has lowercase implementations like `void FUN_0600330a(...)`
         Callers use UPPERCASE, so they hit no-ops instead of real code.

Fix: Change each uppercase stub to forward to the lowercase implementation.
"""
import re, os

src_dir = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'reimpl', 'src')

# Pattern for single-line stub definitions in asm_*.c
# Matches: type FUN_HEXADDR(...) { ... }
STUB_RE = re.compile(
    r'^((?:void|int|unsigned int|char \*|short|unsigned short|long long)\s+)'
    r'(FUN_([0-9A-Fa-f]+))'
    r'\s*\(([^)]*)\)\s*\{[^}]*\}\s*$'
)

# Pattern for function definitions in batch_*.c (K&R or ANSI style)
BATCH_FUNC_RE = re.compile(
    r'^(?:\w[\w *]*\s+)(FUN_([0-9a-fA-F]+))\s*\('
)

HAS_HEX_LETTERS = re.compile(r'[A-Fa-f]')

def find_batch_functions(src_dir):
    """Build a map of lowercase hex addresses -> (filename, func_name, line_num)."""
    batch_funcs = {}
    for fname in sorted(os.listdir(src_dir)):
        if not fname.startswith('batch_') or not fname.endswith('.c'):
            continue
        path = os.path.join(src_dir, fname)
        with open(path, 'r', encoding='utf-8', errors='replace') as f:
            lines = f.readlines()

        for i, line in enumerate(lines):
            # Skip externs
            if line.strip().startswith('extern'):
                continue
            m = BATCH_FUNC_RE.match(line)
            if m:
                func_name = m.group(1)
                hex_addr = m.group(2).upper()
                # Check it's a real function (has opening brace nearby)
                has_brace = False
                for j in range(i, min(i + 5, len(lines))):
                    if '{' in lines[j]:
                        has_brace = True
                        break
                if has_brace:
                    batch_funcs[hex_addr] = (fname, func_name, i + 1)

    return batch_funcs

def find_stubs(src_dir):
    """Find all single-line stubs in asm_*.c files."""
    stubs = []
    for fname in sorted(os.listdir(src_dir)):
        if not fname.startswith('asm_') or not fname.endswith('.c'):
            continue
        path = os.path.join(src_dir, fname)
        with open(path, 'r', encoding='utf-8', errors='replace') as f:
            lines = f.readlines()

        for i, line in enumerate(lines):
            m = STUB_RE.match(line)
            if not m:
                continue
            ret_type = m.group(1).strip()
            func_name = m.group(2)
            hex_addr = m.group(3)
            params_str = m.group(4).strip()

            # Only care about addresses with hex letters (case can differ)
            if not HAS_HEX_LETTERS.search(hex_addr):
                continue

            stubs.append({
                'file': fname,
                'line': i,
                'ret_type': ret_type,
                'func_name': func_name,
                'hex_addr': hex_addr.upper(),
                'params_str': params_str,
                'original_line': line,
            })

    return stubs

def parse_params(params_str):
    """Parse parameter string into a list of (type, name) tuples."""
    if not params_str or params_str == 'void':
        return []
    params = []
    for p in params_str.split(','):
        p = p.strip()
        # Remove (void)name patterns
        p = re.sub(r'\(void\)\s*', '', p)
        # Split type and name
        parts = p.rsplit(' ', 1)
        if len(parts) == 2:
            params.append((parts[0].strip(), parts[1].strip()))
        else:
            params.append(('int', p.strip()))
    return params

def main():
    batch_funcs = find_batch_functions(src_dir)
    stubs = find_stubs(src_dir)

    # Find mismatches
    mismatches = []
    for stub in stubs:
        hex_addr = stub['hex_addr']
        if hex_addr in batch_funcs:
            batch_fname, batch_func_name, batch_line = batch_funcs[hex_addr]
            # Only a mismatch if the names differ in case
            if stub['func_name'] != batch_func_name:
                stub['batch_file'] = batch_fname
                stub['batch_func'] = batch_func_name
                stub['batch_line'] = batch_line
                mismatches.append(stub)

    print(f"Found {len(mismatches)} case mismatch bugs to fix\n")

    if not mismatches:
        return

    # Group by asm file
    by_file = {}
    for m in mismatches:
        by_file.setdefault(m['file'], []).append(m)

    # Process each asm file
    for asm_fname, file_mismatches in sorted(by_file.items()):
        path = os.path.join(src_dir, asm_fname)
        with open(path, 'r', encoding='utf-8', errors='replace') as f:
            lines = f.readlines()

        # Sort by line number descending (modify from bottom up)
        file_mismatches.sort(key=lambda x: x['line'], reverse=True)

        for m in file_mismatches:
            line_idx = m['line']
            params = parse_params(m['params_str'])
            batch_func = m['batch_func']
            ret_type = m['ret_type']

            # Build the extern declaration
            if params:
                param_types = ', '.join(p[0] for p in params)
                param_names = ', '.join(p[1] for p in params)
            else:
                param_types = 'void'
                param_names = ''

            extern_decl = f"extern {ret_type} {batch_func}({param_types});\n"

            # Build the forwarding wrapper
            if ret_type == 'void':
                if param_names:
                    wrapper = f"{ret_type} {m['func_name']}({m['params_str']}) {{ {batch_func}({param_names}); }}\n"
                else:
                    wrapper = f"{ret_type} {m['func_name']}(void) {{ {batch_func}(); }}\n"
            else:
                if param_names:
                    wrapper = f"{ret_type} {m['func_name']}({m['params_str']}) {{ return {batch_func}({param_names}); }}\n"
                else:
                    wrapper = f"{ret_type} {m['func_name']}(void) {{ return {batch_func}(); }}\n"

            # Replace the stub line with extern + wrapper
            lines[line_idx] = extern_decl + wrapper

            print(f"  {asm_fname}:{line_idx+1}: {m['func_name']} -> {batch_func} ({m['batch_file']}:{m['batch_line']})")

        # Write back
        with open(path, 'w', encoding='utf-8', newline='\n') as f:
            f.writelines(lines)

        print(f"  Updated {asm_fname} ({len(file_mismatches)} fixes)")
        print()

if __name__ == '__main__':
    main()
