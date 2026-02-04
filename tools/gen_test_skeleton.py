#!/usr/bin/env python3
"""
gen_test_skeleton.py - Generate draft C test files from Ghidra decompilation output.

For a given function name, extracts the Ghidra decompilation from decomp_all.txt,
cross-references with aprog.s disassembly for pool constant resolution, applies
automatic transformations for GCC 2.6.3 compatibility, and outputs a .c file in tests/.

Usage:
    python gen_test_skeleton.py FUN_06012E62              # Generate one function
    python gen_test_skeleton.py --batch LEAF 8             # Generate all LEAF functions <=8 insns
    python gen_test_skeleton.py --batch CALL 6             # Generate all CALL functions <=6 insns
    python gen_test_skeleton.py --list LEAF 15             # List candidates without generating
    python gen_test_skeleton.py FUN_06012E62 --force       # Overwrite existing .c file
"""

import sys
import os
import re
import argparse

# Project root is one level up from tools/
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
PROJECT_ROOT = os.path.dirname(SCRIPT_DIR)

DECOMP_FILE = os.path.join(PROJECT_ROOT, "ghidra_project", "decomp_all.txt")
APROG_FILE = os.path.join(PROJECT_ROOT, "build", "aprog.s")
SRCDIR = os.path.join(PROJECT_ROOT, "src")
TESTS_DIR = os.path.join(PROJECT_ROOT, "tests")

# ---------------------------------------------------------------------------
# Type replacement map: Ghidra types -> C89 types
# ---------------------------------------------------------------------------
TYPE_REPLACEMENTS = [
    # Order matters: longer/more-specific first
    ("undefined8", "long long"),   # 64-bit - flag with TODO
    ("undefined4", "int"),
    ("undefined2", "short"),
    ("undefined1", "char"),
    ("undefined", "char"),         # bare 'undefined' when used as type
    ("ulonglong", "unsigned long long"),
    ("longlong", "long long"),
    ("uint", "unsigned int"),
    ("ushort", "unsigned short"),
    ("byte", "unsigned char"),
    ("bool", "int"),
]


def strip_cr(text):
    """Strip carriage returns for CRLF handling."""
    return text.replace('\r', '')


# ---------------------------------------------------------------------------
# Parse decomp_all.txt into a dict of {func_name: {header, body, ...}}
# ---------------------------------------------------------------------------
def parse_decomp_file(filepath):
    """Parse the Ghidra decompilation file.

    Returns dict: func_name_upper -> {
        'name': original name (lowercase),
        'addr': address string,
        'size': int,
        'insns': int,
        'type': 'LEAF' or 'CALL',
        'header_line': the FUNC ... line,
        'signature': the C function signature line,
        'body': full body text including signature
    }
    """
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        text = strip_cr(f.read())

    functions = {}
    # Split on the ===== delimiters
    # Pattern: line of ====, FUNC line, line of ====, blank, body, blank(s)
    header_re = re.compile(
        r'^FUNC\s+(\S+)\s+addr=(0x[0-9a-fA-F]+)\s+size=(\d+)\s+insns=(\d+)\s+type=(\S+)',
        re.MULTILINE
    )

    # Find all FUNC headers
    headers = list(header_re.finditer(text))

    for i, m in enumerate(headers):
        func_name = m.group(1)
        addr = m.group(2)
        size = int(m.group(3))
        insns = int(m.group(4))
        func_type = m.group(5)

        # Body starts after the second ==== line following the FUNC line
        # Find the end of the ==== line after FUNC
        body_start = text.find('\n', m.end()) + 1  # skip to after ==== line
        # Skip the ==== line itself
        next_newline = text.find('\n', body_start)
        if next_newline != -1:
            body_start = next_newline + 1

        # Body ends at the next ==== block or end of file
        if i + 1 < len(headers):
            # Find the ===== line before the next FUNC header
            next_header_pos = headers[i + 1].start()
            # Back up to find the ==== line before it
            body_end = text.rfind('=' * 10, m.end(), next_header_pos)
            if body_end != -1:
                # rfind may land in the middle of a === line; back up to
                # the newline that precedes the entire === line
                line_start = text.rfind('\n', 0, body_end)
                if line_start != -1:
                    body_end = line_start
            else:
                body_end = next_header_pos
        else:
            body_end = len(text)

        body = text[body_start:body_end].strip()

        # Normalize the function name to uppercase for lookup
        func_name_upper = func_name.upper()
        # But also handle names that aren't FUN_ prefixed (like 'security_check')
        if not func_name_upper.startswith("FUN_"):
            func_name_upper = func_name

        functions[func_name_upper] = {
            'name': func_name,
            'addr': addr,
            'size': size,
            'insns': insns,
            'type': func_type,
            'header_line': m.group(0),
            'body': body,
        }

    return functions


# ---------------------------------------------------------------------------
# Parse aprog.s for pool value annotations and per-function disassembly
# ---------------------------------------------------------------------------
def parse_pool_values(filepath):
    """Parse pool value annotations from aprog.s.

    Returns dict: pool_address_upper -> value_string
    e.g., '06012E94' -> '0x002A0000'
    """
    pool_map = {}
    # Pattern: {[0xADDRESS] = 0xVALUE}
    pool_re = re.compile(r'\{\[0x([0-9A-Fa-f]+)\]\s*=\s*(0x[0-9A-Fa-f]+)\}')

    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        for line in f:
            line = line.replace('\r', '')
            for m in pool_re.finditer(line):
                addr = m.group(1).upper()
                value = m.group(2)
                pool_map[addr] = value

    return pool_map


def extract_disassembly(filepath, func_addr_hex, func_size):
    """Extract disassembly lines for a function from aprog.s.

    func_addr_hex: e.g., '06012E62' (no 0x prefix, uppercase)
    func_size: size in bytes

    Returns list of comment strings like:
        '06012E62: mov.l @(0x30,PC),r5  {0x002A0000}'
    """
    start_addr = int(func_addr_hex, 16)
    end_addr = start_addr + func_size

    lines = []
    # Pattern to extract the address and instruction from comments
    # e.g., /* 06012E62: mov.l @(0x30,PC),r5  {[0x06012E94] = 0x002A0000} */
    comment_re = re.compile(
        r'/\*\s*([0-9A-Fa-f]{8}):\s*(.*?)\s*\*/'
    )

    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        for line in f:
            line = line.replace('\r', '')
            m = comment_re.search(line)
            if m:
                addr_str = m.group(1)
                try:
                    addr = int(addr_str, 16)
                except ValueError:
                    continue
                if start_addr <= addr < end_addr:
                    insn_text = m.group(2).strip()
                    # Clean up pool annotation for display
                    lines.append("{}: {}".format(addr_str.upper(), insn_text))

    return lines


# ---------------------------------------------------------------------------
# Resolve PTR_DAT_, PTR_PTR_, PTR_s_, PTR_FUN_, DAT_ references
# ---------------------------------------------------------------------------
def resolve_pool_refs(body, pool_map):
    """Resolve pool constant references in the decompilation body.

    - PTR_DAT_XXXXXXXX -> look up pool at XXXXXXXX, replace with value
    - PTR_PTR_XXXXXXXX -> same as PTR_DAT (just a pointer-to-pointer)
    - PTR_s_..._XXXXXXXX -> string pointer, look up pool value
    - PTR_FUN_XXXXXXXX -> function pointer, look up pool value
    - DAT_XXXXXXXX -> inline constant (halfword), typically cast with (int)

    Returns (modified_body, unresolved_refs, resolved_refs)
    """
    unresolved = set()
    resolved = {}  # ref_name -> value

    # Pattern for PTR_ references: PTR_DAT_XXXXXXXX, PTR_PTR_XXXXXXXX,
    # PTR_FUN_XXXXXXXX, PTR_s_..._XXXXXXXX, PTR_LAB_XXXXXXXX,
    # PTR_CD_HIRQ_XXXXXXXX, etc.
    # The address is always the last 8 hex digits before any suffix.
    ptr_ref_re = re.compile(r'(PTR_\w+?_([0-9A-Fa-f]{8}))(?!\w)')

    # Also handle ._0_2_ suffix (Ghidra's partial-field accessor)
    partial_re = re.compile(r'(PTR_\w+?_([0-9A-Fa-f]{8})\._0_2_)')

    # Handle DAT_XXXXXXXX (inline data, typically 2-byte constants within the function)
    dat_re = re.compile(r'(?<!PTR_)DAT_([0-9A-Fa-f]{8})')

    # First pass: resolve PTR_ references with ._0_2_ suffix
    for m in partial_re.finditer(body):
        full_ref = m.group(1)
        addr = m.group(2).upper()
        if addr in pool_map:
            val = pool_map[addr]
            # ._0_2_ means take lower 16 bits as signed short
            resolved[full_ref] = val
        else:
            unresolved.add(full_ref)

    # Second pass: resolve regular PTR_ references
    for m in ptr_ref_re.finditer(body):
        full_ref = m.group(1)
        addr = m.group(2).upper()
        # Skip if already handled as partial
        if full_ref + "._0_2_" in resolved or full_ref + "._0_2_" in unresolved:
            # Don't double-process the base of a partial ref
            pass
        if full_ref in resolved:
            continue
        if addr in pool_map:
            val = pool_map[addr]
            resolved[full_ref] = val
        else:
            unresolved.add(full_ref)

    # Third pass: DAT_ references (inline constants without PTR_ prefix)
    for m in dat_re.finditer(body):
        ref = "DAT_" + m.group(1)
        addr = m.group(1).upper()
        if addr in pool_map:
            resolved[ref] = pool_map[addr]
        else:
            unresolved.add(ref)

    return resolved, unresolved


def apply_pool_substitutions(body, resolved, unresolved):
    """Apply pool constant substitutions to the body text.

    Returns modified body text.
    """
    # Sort by length descending so longer matches go first (avoid partial matches)
    for ref in sorted(resolved.keys(), key=len, reverse=True):
        val = resolved[ref]
        # For ._0_2_ partial refs, the value needs to be treated as lower 16 bits
        if "._0_2_" in ref:
            try:
                int_val = int(val, 16)
                # Extract lower 16 bits, sign-extend
                short_val = int_val & 0xFFFF
                if short_val >= 0x8000:
                    short_val -= 0x10000
                body = body.replace(ref, str(short_val))
            except ValueError:
                body = body.replace(ref, val)
        else:
            body = body.replace(ref, val)

    return body


# ---------------------------------------------------------------------------
# Type replacement
# ---------------------------------------------------------------------------
def apply_type_replacements(body):
    """Replace Ghidra-specific types with C89 equivalents."""
    for ghidra_type, c_type in TYPE_REPLACEMENTS:
        # Use word-boundary matching to avoid partial replacements
        # But we need to be careful: 'undefined' should not match inside 'undefined4'
        # Since we process longer ones first, this should be fine
        body = re.sub(r'\b' + re.escape(ghidra_type) + r'\b', c_type, body)
    return body


# ---------------------------------------------------------------------------
# Convert function signature from ANSI to K&R
# ---------------------------------------------------------------------------
def convert_to_knr(signature):
    """Convert ANSI-style function signature to K&R style for GCC 2.6.3.

    Input:  'void FUN_X(int param_1, short param_2)'
    Output: ('void FUN_X(param_1, param_2)',
             ['    int param_1;', '    short param_2;'])

    Input:  'void FUN_X(void)' or 'void FUN_X()'
    Output: ('void FUN_X()', [])
    """
    # Match: return_type FUNC_NAME(params)
    sig_re = re.compile(r'^(\S+(?:\s*\*)*)\s+(\w+)\s*\((.*)\)\s*$')
    m = sig_re.match(signature.strip())
    if not m:
        # Try multi-word return types like 'unsigned int'
        sig_re2 = re.compile(r'^(.+?)\s+(\w+)\s*\((.*)\)\s*$')
        m = sig_re2.match(signature.strip())
        if not m:
            return signature, []

    ret_type = m.group(1).strip()
    func_name = m.group(2)
    params_str = m.group(3).strip()

    # void parameter means no params
    if params_str == 'void' or params_str == '':
        return "{} {}()".format(ret_type, func_name), []

    # Parse individual parameters
    # Handle nested parens (function pointers) by tracking depth
    params = []
    depth = 0
    current = []
    for ch in params_str:
        if ch == '(' :
            depth += 1
            current.append(ch)
        elif ch == ')':
            depth -= 1
            current.append(ch)
        elif ch == ',' and depth == 0:
            params.append(''.join(current).strip())
            current = []
        else:
            current.append(ch)
    if current:
        params.append(''.join(current).strip())

    # Extract param names and build K&R declarations
    param_names = []
    param_decls = []
    for p in params:
        p = p.strip()
        if not p:
            continue
        # Extract the parameter name (last word, possibly with * prefix)
        # e.g., 'int *param_1' -> name='param_1', decl='int *param_1'
        # e.g., 'short param_2' -> name='param_2', decl='short param_2'
        parts = p.split()
        if parts:
            name = parts[-1]
            # Strip leading * from name (pointer types)
            while name.startswith('*'):
                name = name[1:]
            param_names.append(name)
            param_decls.append("    {};".format(p))

    knr_sig = "{} {}({})".format(ret_type, func_name, ", ".join(param_names))
    return knr_sig, param_decls


# ---------------------------------------------------------------------------
# Extract extern declarations needed
# ---------------------------------------------------------------------------
def extract_extern_functions(body):
    """Find all FUN_XXXXXXXX calls in the body and generate extern declarations.

    Returns list of extern declaration strings.
    """
    # Match function calls: FUN_XXXXXXXX(
    func_call_re = re.compile(r'\bFUN_([0-9A-Fa-f]+)\s*\(')
    called_funcs = set()
    for m in func_call_re.finditer(body):
        called_funcs.add("FUN_" + m.group(1).lower())

    # Don't declare the function itself
    return sorted(called_funcs)


def extract_extern_data_refs(body, resolved, unresolved):
    """Generate extern declarations for unresolved data references.

    Returns list of extern declaration strings with TODO comments.
    """
    externs = []
    for ref in sorted(unresolved):
        externs.append("/* TODO: resolve pool constant {} */".format(ref))
        externs.append("extern int {};".format(ref))
    return externs


# ---------------------------------------------------------------------------
# Clean up Ghidra-specific artifacts
# ---------------------------------------------------------------------------
def cleanup_ghidra_artifacts(body):
    """Remove or fix Ghidra-specific code artifacts."""
    # Remove casts to (code *) - Ghidra artifact for function pointers
    body = re.sub(r'\(code\s*\*\)', '', body)

    # Remove casts to (code **)
    body = re.sub(r'\(code\s*\*\*\)', '(void **)', body)

    # Clean up double-deref indirect calls: (**(void **)ADDR)(args)
    # These remain as TODO items since they need manual resolution

    return body


def fix_ghidra_artifacts(text):
    """Post-process complete C source to fix patterns that prevent cc1 compilation.

    Applied to the final output text (not just the body). Handles:
    - Indirect calls through constant addresses: (*0xADDR)(args)
    - Double-indirect calls: (**(void **)0xADDR)(args)
    - Variable-based indirect calls: (*puVar1)(args)
    - Bare integer dereferences: *0xADDR, 0xADDR[N]
    - extern void FUN_ -> extern int FUN_ (void value not ignored fix)
    - true/false -> 1/0
    - Sub-field references: var._0_2_ -> var
    - Trailing commas in parameter lists
    """
    # 1. Indirect call through constant address: (*0xADDR)(args) -> (*(void(*)())0xADDR)(args)
    text = re.sub(r'\(\*\s*(0x[0-9A-Fa-f]+)\)\s*\(', r'(*(void(*)())\1)(', text)

    # 2. Double-indirect: (**(void **)0xADDR)( -> (*(void(*)())(*(int *)0xADDR))(
    text = re.sub(r'\(\*\*\s*\(void\s*\*\*\)\s*(0x[0-9A-Fa-f]+)\)\s*\(',
                  r'(*(void(*)())(*(int *)\1))(', text)
    # Also with parenthesized expression
    text = re.sub(r'\(\*\*\s*\(void\s*\*\*\)\s*(\([^)]+\))\)\s*\(',
                  r'(*(void(*)())(*(int *)\1))(', text)

    # 3. Variable-based indirect call: (*varname)( -> (*(void(*)())varname)(
    text = re.sub(r'\(\*([a-zA-Z_]\w*)\)\s*\(', r'(*(void(*)())\1)(', text)

    # 4. Bare dereference: *0xADDR -> *(int *)0xADDR (not preceded by ) from cast)
    text = re.sub(r'(?<!\))\*(0x[0-9A-Fa-f]+)\b', r'*(int *)\1', text)

    # 5. Bare subscript: 0xADDR[N] -> ((int *)0xADDR)[N]
    text = re.sub(r'(?<!\))(0x[0-9A-Fa-f]+)\[', r'((int *)\1)[', text)

    # 6. extern void FUN_ -> extern int FUN_ (fix void value not ignored)
    text = re.sub(r'^extern void (FUN_[0-9A-Fa-f]+)\s*\(', r'extern int \1(', text,
                  flags=re.MULTILINE)

    # 7. true/false -> 1/0
    text = re.sub(r'\btrue\b', '1', text)
    text = re.sub(r'\bfalse\b', '0', text)

    # 8. Sub-field references: var._0_2_ -> var
    text = re.sub(r'\b(\w+)\._(\d+)_(\d+)_\b', r'\1', text)

    # 9. Trailing comma before ) or before newline+{
    text = re.sub(r',\s*\)', ')', text)
    text = re.sub(r',\s*\n\{', '\n{', text)

    return text


# ---------------------------------------------------------------------------
# Assess compilability
# ---------------------------------------------------------------------------
def assess_compilability(body):
    """Check if the decompilation looks like it could compile.

    Returns (score, issues) where score is 0-100 and issues is a list of strings.
    """
    issues = []
    score = 100

    # Check for indirect function calls via pointers
    if re.search(r'\(\*\*?\(', body):
        issues.append("indirect_calls")
        score -= 30

    # Check for code* casts
    if 'code *' in body or 'code *' in body:
        issues.append("code_ptr_casts")
        score -= 10

    # Check for ._0_2_ partial field access
    if '._0_2_' in body:
        issues.append("partial_field_access")
        score -= 15

    # Check for undefined8 (64-bit)
    if 'undefined8' in body:
        issues.append("undefined8")
        score -= 20

    # Check for unresolved PTR_ references (will be caught later, but estimate)
    ptr_count = len(re.findall(r'PTR_(?:DAT|PTR|FUN|s_\w+)_[0-9A-Fa-f]{8}', body))
    if ptr_count > 5:
        issues.append("many_pool_refs({})".format(ptr_count))
        score -= min(ptr_count * 3, 30)

    # Check for DAT_ inline refs
    dat_count = len(re.findall(r'(?<!PTR_)DAT_[0-9A-Fa-f]{8}', body))
    if dat_count > 0:
        issues.append("inline_dat_refs({})".format(dat_count))
        score -= min(dat_count * 5, 20)

    # Check for array/struct casts that are complex
    if re.search(r'\*\s*\(.*\*\*\)', body):
        issues.append("double_ptr_deref")
        score -= 10

    return max(0, score), issues


# ---------------------------------------------------------------------------
# Main generation logic
# ---------------------------------------------------------------------------
def generate_skeleton(func_name, functions, pool_map, force=False):
    """Generate a test skeleton .c file for the given function.

    Returns (output_path, status_message) or (None, error_message).
    """
    func_name_upper = func_name.upper()

    # Try uppercase first (standard FUN_ names), then original case (named funcs)
    if func_name_upper in functions:
        func_key = func_name_upper
    elif func_name in functions:
        func_key = func_name
    elif func_name.lower() in functions:
        func_key = func_name.lower()
    else:
        return None, "Function {} not found in decomp_all.txt".format(func_name)

    func_info = functions[func_key]
    output_file = os.path.join(SRCDIR, "{}.c".format(func_key))

    if os.path.exists(output_file) and not force:
        return None, "File {} already exists (use --force to overwrite)".format(output_file)

    # Extract disassembly for the comment header
    addr_hex = func_info['addr'].replace('0x', '').upper()
    asm_lines = extract_disassembly(APROG_FILE, addr_hex, func_info['size'])

    # Get the decompilation body
    body = func_info['body']

    # Resolve pool references
    resolved, unresolved = resolve_pool_refs(body, pool_map)

    # Apply type replacements FIRST (before pool substitution, so types in casts
    # get replaced even if they surround pool refs)
    body = apply_type_replacements(body)

    # Apply pool substitutions
    body = apply_pool_substitutions(body, resolved, unresolved)

    # Clean up Ghidra artifacts
    body = cleanup_ghidra_artifacts(body)

    # Split body into signature and function body
    # The body starts with the function signature, then the block
    lines = body.split('\n')

    # Find the function signature line (first non-empty line)
    sig_line = ''
    sig_idx = 0
    for i, line in enumerate(lines):
        stripped = line.strip()
        if stripped and not stripped.startswith('/*') and not stripped.startswith('*'):
            sig_line = stripped
            sig_idx = i
            break

    # Find the opening brace
    brace_idx = sig_idx
    for i in range(sig_idx, len(lines)):
        if '{' in lines[i]:
            brace_idx = i
            break

    # The signature might span multiple lines (return type on one, name+params on next)
    if '(' not in sig_line:
        # Signature spans sig_idx and sig_idx+1
        if sig_idx + 1 < len(lines):
            sig_line = sig_line + ' ' + lines[sig_idx + 1].strip()

    # Convert signature to K&R
    knr_sig, knr_decls = convert_to_knr(sig_line)

    # Extract the function body (everything between { and final })
    body_content = '\n'.join(lines[brace_idx:])
    # Collapse runs of 3+ blank lines into 1 blank line
    body_content = re.sub(r'\n{3,}', '\n\n', body_content)

    # Determine the function's own name for filtering extern declarations
    own_name = func_info['name']

    # Extract extern function declarations
    called_funcs = extract_extern_functions(body_content)
    called_funcs = [f for f in called_funcs if f != own_name and f != own_name.lower()]

    # Extract extern data declarations for unresolved refs
    data_externs = extract_extern_data_refs(body_content, resolved, unresolved)

    # Detect indirect call TODOs
    indirect_calls = re.findall(r'\(\*[^)]*\)\s*\(', body_content)
    has_indirect_calls = len(indirect_calls) > 0

    # Build the output file
    out_lines = []

    # NOTE: cc1 is the compiler proper and does NOT handle C comments.
    # All comments must be omitted since files go directly to cc1, not cpp+cc1.

    out_lines.append("")

    # Extern declarations for data
    if data_externs:
        for decl in data_externs:
            out_lines.append(decl)
        out_lines.append("")

    # Extern declarations for called functions
    if called_funcs:
        for func in called_funcs:
            out_lines.append("extern int {}();".format(func))
        out_lines.append("")

    # NOTE: No TODO comments - cc1 cannot handle C comments

    # Function signature (K&R style)
    out_lines.append(knr_sig)
    if knr_decls:
        for decl in knr_decls:
            out_lines.append(decl)

    # Function body
    out_lines.append(body_content)

    out_lines.append("")

    # Write the output file with Unix line endings
    os.makedirs(SRCDIR, exist_ok=True)
    output_text = '\n'.join(out_lines)

    # Post-processing: fix Ghidra artifacts that prevent cc1 compilation
    output_text = fix_ghidra_artifacts(output_text)

    with open(output_file, 'w', encoding='utf-8', newline='\n') as f:
        f.write(output_text)

    return output_file, "Generated {} ({} insns, {} unresolved refs)".format(
        output_file, func_info['insns'], len(unresolved))


# ---------------------------------------------------------------------------
# List mode
# ---------------------------------------------------------------------------
def list_candidates(functions, pool_map, func_type, max_insns):
    """List candidate functions for generation.

    Shows: function name, address, insns, type, .c exists, compilability.
    """
    candidates = []
    for func_name_upper, info in sorted(functions.items(), key=lambda x: x[1]['insns']):
        if info['type'] != func_type:
            continue
        if info['insns'] > max_insns:
            continue
        candidates.append(info)

    if not candidates:
        print("No {} functions with <= {} insns found.".format(func_type, max_insns))
        return

    print("{:<20s} {:>10s} {:>6s} {:>6s}  {:>6s}  {:s}".format(
        "Function", "Address", "Size", "Insns", "Exists", "Compilability"))
    print("-" * 80)

    for info in candidates:
        name_upper = info['name'].upper()
        if not name_upper.startswith("FUN_"):
            name_upper = info['name']
        c_file = os.path.join(SRCDIR, "{}.c".format(name_upper))
        exists = "YES" if os.path.exists(c_file) else "no"

        # Assess compilability
        body = info['body']
        body = apply_type_replacements(body)
        _, unresolved = resolve_pool_refs(body, pool_map)
        score, issues = assess_compilability(body)

        issues_str = ", ".join(issues) if issues else "OK"
        if unresolved:
            issues_str += ", unresolved({})".format(len(unresolved))

        print("{:<20s} {:>10s} {:>6d} {:>6d}  {:>6s}  [{:3d}] {:s}".format(
            name_upper, info['addr'], info['size'], info['insns'],
            exists, score, issues_str))

    total = len(candidates)
    existing = sum(1 for info in candidates
                   if os.path.exists(os.path.join(SRCDIR,
                       "{}.c".format(info['name'].upper()
                           if info['name'].upper().startswith("FUN_")
                           else info['name']))))
    print("\nTotal: {} candidates, {} already have .c files, {} remaining".format(
        total, existing, total - existing))


# ---------------------------------------------------------------------------
# Batch mode
# ---------------------------------------------------------------------------
def batch_generate(functions, pool_map, func_type, max_insns, force=False):
    """Generate skeletons for all functions matching criteria.

    Skips functions that already have .c files (unless --force).
    """
    generated = 0
    skipped = 0
    errors = 0

    candidates = []
    for func_name_upper, info in sorted(functions.items(), key=lambda x: x[1]['insns']):
        if info['type'] != func_type:
            continue
        if info['insns'] > max_insns:
            continue
        candidates.append((func_name_upper, info))

    for func_name_upper, info in candidates:
        output_path, msg = generate_skeleton(func_name_upper, functions, pool_map, force)
        if output_path:
            print("  OK: {}".format(msg))
            generated += 1
        else:
            if "already exists" in msg:
                skipped += 1
            else:
                print("  ERR: {}".format(msg))
                errors += 1

    print("\nBatch complete: {} generated, {} skipped (existing), {} errors".format(
        generated, skipped, errors))


def batch_generate_all(functions, pool_map, force=False):
    """Generate skeletons for ALL functions in decomp_all.txt.

    Skips functions that already have .c files (unless --force).
    """
    generated = 0
    skipped = 0
    errors = 0

    candidates = sorted(functions.items(), key=lambda x: x[1]['insns'])

    print("Generating skeletons for ALL {} functions...".format(len(candidates)))
    for func_name_upper, info in candidates:
        output_path, msg = generate_skeleton(func_name_upper, functions, pool_map, force)
        if output_path:
            print("  OK: {}".format(msg))
            generated += 1
        else:
            if "already exists" in msg:
                skipped += 1
            else:
                print("  ERR: {}".format(msg))
                errors += 1

    print("\nBatch complete: {} generated, {} skipped (existing), {} errors".format(
        generated, skipped, errors))


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------
def main():
    parser = argparse.ArgumentParser(
        description="Generate test skeleton .c files from Ghidra decompilation")
    parser.add_argument('args', nargs='*',
        help="Function name (e.g., FUN_06012E62) or --batch/--list TYPE MAX_INSNS")
    parser.add_argument('--force', action='store_true',
        help="Overwrite existing .c files")
    parser.add_argument('--batch', nargs=2, metavar=('TYPE', 'MAX_INSNS'),
        help="Generate all functions of TYPE with <= MAX_INSNS instructions")
    parser.add_argument('--list', nargs=2, metavar=('TYPE', 'MAX_INSNS'),
        help="List candidate functions without generating")
    parser.add_argument('--batch-all', action='store_true',
        help="Generate skeletons for ALL functions in decomp_all.txt")

    args = parser.parse_args()

    # Verify input files exist
    if not os.path.exists(DECOMP_FILE):
        print("ERROR: Decompilation file not found: {}".format(DECOMP_FILE))
        sys.exit(1)
    if not os.path.exists(APROG_FILE):
        print("ERROR: Disassembly file not found: {}".format(APROG_FILE))
        sys.exit(1)

    print("Parsing decompilation file...")
    functions = parse_decomp_file(DECOMP_FILE)
    print("  Found {} functions".format(len(functions)))

    print("Parsing pool values from disassembly...")
    pool_map = parse_pool_values(APROG_FILE)
    print("  Found {} pool entries".format(len(pool_map)))

    if args.list:
        func_type = args.list[0].upper()
        max_insns = int(args.list[1])
        list_candidates(functions, pool_map, func_type, max_insns)
    elif args.batch_all:
        batch_generate_all(functions, pool_map, args.force)
    elif args.batch:
        func_type = args.batch[0].upper()
        max_insns = int(args.batch[1])
        print("Generating skeletons for {} functions with <= {} insns...".format(
            func_type, max_insns))
        batch_generate(functions, pool_map, func_type, max_insns, args.force)
    elif args.args:
        for func_name in args.args:
            output_path, msg = generate_skeleton(func_name, functions, pool_map, args.force)
            if output_path:
                print("OK: {}".format(msg))
            else:
                print("ERROR: {}".format(msg))
    else:
        parser.print_help()
        sys.exit(1)


if __name__ == '__main__':
    main()
