#!/usr/bin/env python3
"""map_named_to_fun.py -- Map named functions to FUN_ addresses.

For each named function in reimpl/src/*.c that doesn't have a FUN_ alias,
attempts to find the matching FUN_xxxxxxxx address using:
  1. File header comments (name -- FUN_xxx)
  2. Position between known FUN_ functions in the same file
  3. Constant fingerprinting against Ghidra decomp files in src/FUN_*.c
  4. Function call fingerprinting

Outputs:
  - Mapping report: which named functions map to which FUN_ addresses
  - Optionally adds __attribute__((alias("FUN_xxx"))) declarations

Usage:
    python3 tools/map_named_to_fun.py [--apply] [--verbose]
"""

import os
import re
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REIMPL_SRC = os.path.join(PROJ, "reimpl", "src")
GHIDRA_SRC = os.path.join(PROJ, "src")
SYMS_FILE = os.path.join(PROJ, "build", "aprog_syms.txt")

APPLY = "--apply" in sys.argv
VERBOSE = "--verbose" in sys.argv

# Skip these "named" functions -- they're C keywords, not function names
SKIP_NAMES = {
    'if', 'while', 'for', 'return', 'switch', 'else', 'do', 'case',
    'int', 'void', 'char', 'short', 'unsigned', 'long', 'signed',
    'extern', 'static', 'struct', 'union', 'enum', 'typedef',
    'main', 'sizeof',
}

BASE_ADDR = 0x06003000
END_ADDR = BASE_ADDR + 394896


def load_syms():
    """Load all known FUN_ addresses from aprog_syms.txt."""
    syms = {}
    with open(SYMS_FILE) as f:
        for line in f:
            m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            if m:
                name = m.group(1).upper()
                addr = int(m.group(2), 16)
                syms[name] = addr
    return syms


def find_existing_aliases():
    """Find all named → FUN_ mappings already in the source code."""
    aliases = {}  # named -> FUN_XXXXXXXX

    for fname in sorted(os.listdir(REIMPL_SRC)):
        if not fname.endswith('.c'):
            continue
        fpath = os.path.join(REIMPL_SRC, fname)
        with open(fpath, errors='replace') as f:
            content = f.read()

        # Pattern: alias declarations
        for m in re.finditer(
            r'(\w+)\s*\([^)]*\)\s*__attribute__\s*\(\s*\(\s*alias\s*\(\s*"(\w+)"\s*\)',
            content
        ):
            sym1, sym2 = m.group(1), m.group(2)
            if sym1.startswith('FUN_') and not sym2.startswith('FUN_'):
                aliases[sym2] = sym1.upper()
            elif sym2.startswith('FUN_') and not sym1.startswith('FUN_'):
                aliases[sym1] = sym2.upper()

        # Pattern: ASM blocks with both named and FUN_ labels
        # Find blocks with ".global _named\n" and "_FUN_xxx:\n"
        asm_blocks = re.finditer(
            r'__asm__\s*\((.*?)\);',
            content, re.DOTALL
        )
        for block in asm_blocks:
            body = block.group(1)
            named_labels = re.findall(r'\.global\s+_([a-z][a-z_0-9]+)', body)
            fun_labels = re.findall(r'\.global\s+_(FUN_[0-9A-Fa-f]+)', body)
            if named_labels and fun_labels:
                for named in named_labels:
                    if named not in SKIP_NAMES:
                        # Use the first FUN_ label in the same block
                        aliases[named] = fun_labels[0].upper()

    return aliases


def find_named_functions():
    """Find all named (non-FUN_) function definitions in reimpl/src/*.c."""
    named_funcs = {}  # name -> (file, line_num, return_type, body_lines)

    func_def_re = re.compile(
        r'^(?:static\s+)?'
        r'(void|int|unsigned\s+int|unsigned\s+char|unsigned\s+short|'
        r'char|short|long|long\s+long)\s*\*?\s*'
        r'([a-z_][a-z_0-9]+)\s*\(',
        re.MULTILINE
    )

    for fname in sorted(os.listdir(REIMPL_SRC)):
        if not fname.endswith('.c'):
            continue
        fpath = os.path.join(REIMPL_SRC, fname)
        with open(fpath, errors='replace') as f:
            lines = f.readlines()

        # Track #if 0 nesting to skip disabled code
        in_if0 = 0
        for i, line in enumerate(lines):
            if re.match(r'\s*#if\s+0', line):
                in_if0 += 1
            elif in_if0 > 0 and re.match(r'\s*#endif', line):
                in_if0 -= 1

            if in_if0 > 0:
                continue

            m = func_def_re.match(line)
            if not m:
                continue

            ret_type = m.group(1)
            name = m.group(2)

            if name in SKIP_NAMES:
                continue

            # Extract body lines (up to 20 lines or closing brace)
            body = []
            brace_depth = 0
            for j in range(i, min(i + 30, len(lines))):
                body.append(lines[j])
                brace_depth += lines[j].count('{') - lines[j].count('}')
                if brace_depth <= 0 and j > i:
                    break

            named_funcs[name] = (fname, i + 1, ret_type, body)

    return named_funcs


def extract_constants(body_lines):
    """Extract hex constants from function body for fingerprinting."""
    constants = set()
    body_text = ''.join(body_lines)

    # Find hex constants: 0x06xxxxxx (Saturn addresses)
    for m in re.finditer(r'0x(06[0-9a-fA-F]{6})', body_text):
        constants.add(int(m.group(1), 16))

    # Find hex constants: 0x25xxxxxx (VDP addresses)
    for m in re.finditer(r'0x(25[0-9a-fA-F]{6})', body_text):
        constants.add(int(m.group(1), 16))

    # Find hex constants: 0x060Axxxx (data area)
    for m in re.finditer(r'0x(060[aA][0-9a-fA-F]{4})', body_text):
        constants.add(int(m.group(1), 16))

    return constants


def extract_callees(body_lines):
    """Extract function callees from body for fingerprinting."""
    callees = set()
    body_text = ''.join(body_lines)

    # Find FUN_ calls
    for m in re.finditer(r'(FUN_[0-9a-fA-F]+)\s*\(', body_text):
        callees.add(m.group(1).upper())

    return callees


def build_ghidra_fingerprints():
    """Build fingerprint database from Ghidra decomp files in src/."""
    fingerprints = {}  # FUN_XXXXXXXX -> {constants, callees, ret_type, param_count}

    if not os.path.isdir(GHIDRA_SRC):
        return fingerprints

    for fname in sorted(os.listdir(GHIDRA_SRC)):
        m = re.match(r'(FUN_[0-9a-fA-F]+)\.c$', fname)
        if not m:
            continue
        fun_name = m.group(1).upper()
        fpath = os.path.join(GHIDRA_SRC, fname)

        with open(fpath, errors='replace') as f:
            content = f.read()
            lines = content.split('\n')

        constants = extract_constants(lines)
        callees = extract_callees(lines)

        # Get return type and param count
        ret_type = 'void'
        param_count = 0
        func_def = re.search(
            r'(void|int|unsigned|char|short|long)\s*\*?\s*' + fun_name + r'\s*\(([^)]*)\)',
            content, re.IGNORECASE
        )
        if func_def:
            ret_type = func_def.group(1)
            params = func_def.group(2).strip()
            if params and params != 'void':
                param_count = len(params.split(','))

        fingerprints[fun_name] = {
            'constants': constants,
            'callees': callees,
            'ret_type': ret_type,
            'param_count': param_count,
        }

    return fingerprints


def find_neighbor_fun_addrs(fname, line_num, lines_content):
    """Find the FUN_ addresses of neighboring functions in the same file."""
    lines = lines_content.split('\n')

    # Find FUN_ function definitions before and after the named function
    fun_before = None
    fun_after = None

    # Pattern for FUN_ function definitions (not inside #if 0, not extern)
    fun_def_re = re.compile(
        r'^(?:void|int|unsigned|char|short|long)\s*\*?\s*(FUN_[0-9a-fA-F]+)\s*\('
    )

    in_if0 = 0
    for i, line in enumerate(lines):
        if re.match(r'\s*#if\s+0', line):
            in_if0 += 1
        elif in_if0 > 0 and re.match(r'\s*#endif', line):
            in_if0 -= 1

        if in_if0 > 0:
            continue

        # Skip extern declarations
        if line.strip().startswith('extern'):
            continue

        m = fun_def_re.match(line)
        if m:
            fun_name = m.group(1).upper()
            hex_part = fun_name[4:]
            try:
                addr = int(hex_part, 16)
            except ValueError:
                continue

            if i < line_num - 1:
                fun_before = addr
            elif i > line_num - 1 and fun_after is None:
                fun_after = addr

    return fun_before, fun_after


def match_by_header_comment(fname, name):
    """Try to find FUN_ address from file header comments."""
    fpath = os.path.join(REIMPL_SRC, fname)
    with open(fpath, errors='replace') as f:
        header = f.read(2000)  # First 2KB

    # Pattern: name -- FUN_xxxxxxxx or FUN_xxxxxxxx -- name
    for m in re.finditer(
        r'(?:' + re.escape(name) + r')\s*(?:--|-|:)\s*(FUN_[0-9a-fA-F]+)',
        header
    ):
        return m.group(1).upper()

    for m in re.finditer(
        r'(FUN_[0-9a-fA-F]+)\s*(?:--|-|:)\s*(?:' + re.escape(name) + r')',
        header
    ):
        return m.group(1).upper()

    # Pattern: name -- description (address) or * FUN_xxx ... name
    for m in re.finditer(
        r'(FUN_[0-9a-fA-F]+)\s*[(\[][^)\]]*' + re.escape(name),
        header
    ):
        return m.group(1).upper()

    return None


def match_by_fingerprint(name, body_lines, ghidra_fps, syms, fun_before, fun_after):
    """Match a named function to a FUN_ address using constant fingerprinting."""
    my_constants = extract_constants(body_lines)
    my_callees = extract_callees(body_lines)

    if not my_constants and not my_callees:
        return None, 0

    best_match = None
    best_score = 0

    for fun_name, fp in ghidra_fps.items():
        # Filter by address range if we have neighbors
        addr = syms.get(fun_name)
        if addr is None:
            try:
                addr = int(fun_name[4:], 16)
            except ValueError:
                continue

        if fun_before and addr < fun_before:
            continue
        if fun_after and addr > fun_after:
            continue

        # Score based on shared constants
        shared_consts = my_constants & fp['constants']
        shared_callees = my_callees & fp['callees']

        # Weight: each shared constant is 2 points, each shared callee is 3 points
        score = len(shared_consts) * 2 + len(shared_callees) * 3

        if score > best_score:
            best_score = score
            best_match = fun_name

    return best_match, best_score


def match_by_if0_block(fname, line_num):
    """Check if there's a #if 0 FUN_xxx block just above the named function."""
    fpath = os.path.join(REIMPL_SRC, fname)
    with open(fpath, errors='replace') as f:
        lines = f.readlines()

    # Look backward from line_num for #endif, then #if 0 /* FUN_xxx */
    for i in range(line_num - 2, max(0, line_num - 10), -1):
        if re.match(r'\s*#endif', lines[i]):
            # Found #endif, now look for #if 0 with FUN_ above
            for j in range(i - 1, max(0, i - 200), -1):
                m = re.match(r'\s*#if\s+0\s*/\*\s*(FUN_[0-9a-fA-F]+)', lines[j])
                if m:
                    return m.group(1).upper()
                # If we hit another function definition, stop
                if re.match(r'^(?:void|int|unsigned|char|short|long)\s+\w+\s*\(', lines[j]):
                    break
            break

    return None


def generate_alias_line(name, fun_name, ret_type):
    """Generate an alias declaration line."""
    # Determine return type for alias
    if ret_type in ('void', 'int', 'char', 'short', 'long'):
        alias_type = ret_type
    elif 'unsigned' in ret_type:
        alias_type = ret_type
    else:
        alias_type = 'void'

    return '%s %s(void) __attribute__((alias("%s")));\n' % (alias_type, fun_name, name)


def main():
    print("=== map_named_to_fun.py ===\n")

    # Load known symbols
    syms = load_syms()
    print("Loaded %d symbols from aprog_syms.txt" % len(syms))

    # Find existing aliases
    existing = find_existing_aliases()
    print("Found %d existing named → FUN_ aliases" % len(existing))

    # Find all named functions
    named = find_named_functions()
    print("Found %d named function definitions" % len(named))

    # Filter to those without aliases
    unmapped = {n: v for n, v in named.items() if n not in existing}
    print("Unmapped (no alias): %d\n" % len(unmapped))

    # Build Ghidra fingerprint database
    print("Building Ghidra fingerprint database...")
    ghidra_fps = build_ghidra_fingerprints()
    print("  %d Ghidra decomp files indexed\n" % len(ghidra_fps))

    # Try to map each unnamed function
    mappings = {}  # name -> (fun_name, method, score)
    unmapped_list = []

    for name in sorted(unmapped.keys()):
        fname, line_num, ret_type, body = unmapped[name]

        # Method 1: Header comments
        result = match_by_header_comment(fname, name)
        if result:
            mappings[name] = (result, 'header_comment', 100)
            continue

        # Method 2: #if 0 block above
        result = match_by_if0_block(fname, line_num)
        if result:
            mappings[name] = (result, 'if0_block', 90)
            continue

        # Method 3: Fingerprint matching
        fpath = os.path.join(REIMPL_SRC, fname)
        with open(fpath, errors='replace') as f:
            content = f.read()
        fun_before, fun_after = find_neighbor_fun_addrs(fname, line_num, content)

        result, score = match_by_fingerprint(
            name, body, ghidra_fps, syms, fun_before, fun_after
        )
        if result and score >= 4:
            mappings[name] = (result, 'fingerprint', score)
            continue

        unmapped_list.append((name, fname, line_num, fun_before, fun_after))

    # Report
    print("=== Results ===\n")
    print("Mapped: %d" % len(mappings))
    print("Still unmapped: %d\n" % len(unmapped_list))

    by_method = {}
    for name, (fun, method, score) in mappings.items():
        by_method.setdefault(method, []).append((name, fun, score))

    for method in sorted(by_method.keys()):
        items = by_method[method]
        print("  %s: %d mappings" % (method, len(items)))
        if VERBOSE:
            for name, fun, score in sorted(items):
                fname = unmapped[name][0]
                print("    %s → %s (score=%d, %s)" % (name, fun, score, fname))

    if unmapped_list:
        print("\nStill unmapped:")
        for name, fname, line_num, before, after in sorted(unmapped_list):
            before_str = "0x%08X" % before if before else "?"
            after_str = "0x%08X" % after if after else "?"
            print("  %s (%s:%d) range=[%s, %s]" % (
                name, fname, line_num, before_str, after_str))

    # Apply aliases if requested
    if APPLY and mappings:
        print("\n=== Applying aliases ===\n")
        apply_aliases(mappings, unmapped)
    elif mappings:
        print("\nUse --apply to add alias declarations to source files.")

    return 0


def apply_aliases(mappings, named_info):
    """Add alias declarations to source files."""
    # Group by file
    by_file = {}
    for name, (fun_name, method, score) in mappings.items():
        fname = named_info[name][0]
        by_file.setdefault(fname, []).append((name, fun_name, named_info[name]))

    for fname in sorted(by_file.keys()):
        fpath = os.path.join(REIMPL_SRC, fname)
        with open(fpath, errors='replace') as f:
            content = f.read()

        original = content

        for name, fun_name, (_, line_num, ret_type, _) in sorted(by_file[fname], key=lambda x: -x[2][1]):
            # Check if alias already exists
            if fun_name in content and 'alias' in content and name in content:
                continue

            # Find the closing brace of the function
            lines = content.split('\n')
            brace_depth = 0
            func_end = line_num - 1
            for i in range(line_num - 1, min(line_num + 100, len(lines))):
                brace_depth += lines[i].count('{') - lines[i].count('}')
                if brace_depth <= 0 and i > line_num - 1:
                    func_end = i
                    break

            # Insert alias after the function
            alias_line = generate_alias_line(name, fun_name, ret_type)
            lines.insert(func_end + 1, alias_line)
            content = '\n'.join(lines)

        if content != original:
            with open(fpath, 'w', newline='\n') as f:
                f.write(content)
            count = len(by_file[fname])
            print("  %s: added %d aliases" % (fname, count))


if __name__ == '__main__':
    sys.exit(main())
