#!/usr/bin/env python3
"""gen_asm_real.py -- Replace ASM-only no-op stubs with real binary bytes.

Reads build/aprog.s for disassembly annotations and function boundaries.
Replaces empty function stubs in reimpl/src/asm_*.c with file-scope __asm__()
blocks containing .word directives with disassembly comments.

Approach:
  - File-scope __asm__() avoids GCC prologue/epilogue (naked not on SH)
  - Raw .word bytes are bit-perfect including constant pool data
  - Each function gets .balign for correct mov.l pool alignment
  - Disassembly from aprog.s added as C comments for readability
  - Preserves: moved-to comments, forwarding wrappers, aliases, externs
"""

import os
import re
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
APROG_S = os.path.join(PROJ, "build", "aprog.s")
SRC_DIR = os.path.join(PROJ, "reimpl", "src")
BASE_ADDR = 0x06003000

BYTE_RE = re.compile(
    r'\s+\.byte\s+0x([0-9a-fA-F]{2}),\s*0x([0-9a-fA-F]{2})'
    r'(?:\s*/\*\s*(.*?)\s*\*/)?'
)
LABEL_RE = re.compile(r'^(FUN_[0-9A-Fa-f]{8}|main|_start):\s*$')


def parse_aprog_all():
    """Parse aprog.s in a single pass.

    Returns:
      func_data: dict of UPPER_LABEL -> list of (high_byte, low_byte, comment)
      label_addrs: dict of UPPER_LABEL -> int address
    """
    func_data = {}
    label_addrs = {}
    current_label = None
    current_insns = []

    with open(APROG_S, 'r', errors='replace') as f:
        for line in f:
            line = line.rstrip('\n').rstrip('\r')

            m = LABEL_RE.match(line)
            if m:
                # Save previous function
                if current_label:
                    func_data[current_label.upper()] = current_insns

                name = m.group(1)
                current_label = name
                current_insns = []

                # Extract address
                if name.startswith('FUN_'):
                    label_addrs[name.upper()] = int(name[4:], 16)
                elif name in ('main', '_start'):
                    label_addrs[name] = BASE_ADDR
                continue

            if current_label:
                bm = BYTE_RE.match(line)
                if bm:
                    b1 = int(bm.group(1), 16)
                    b2 = int(bm.group(2), 16)
                    comment = bm.group(3) or ''
                    current_insns.append((b1, b2, comment))

    # Save last function
    if current_label:
        func_data[current_label.upper()] = current_insns

    return func_data, label_addrs


def format_asm_block(func_name, addr, insns, aliases=None):
    """Format a file-scope __asm__() block for a function.

    Note: sh-elf-gcc prepends '_' to all C symbols. Assembly symbols must
    also use the '_' prefix to be found by the linker.
    """
    if not insns:
        return None

    # sh-elf-gcc uses underscore prefix for C ABI symbols
    sym = f'_{func_name}'
    alias_syms = [f'_{a}' for a in aliases] if aliases else []

    parts = []
    parts.append('__asm__(')

    # Alignment: preserve original alignment modulo 4
    # mov.l @(disp,PC) uses (PC & ~3), so functions at addr%4==2 need 2-byte offset
    if addr % 4 == 2:
        parts.append('    ".balign 4\\n"')
        parts.append('    ".short 0x0009\\n"  /* alignment padding */')
    else:
        parts.append('    ".balign 4\\n"')

    # Symbol declarations
    parts.append(f'    ".global {sym}\\n"')
    parts.append(f'    ".type {sym}, @function\\n"')
    for a in alias_syms:
        parts.append(f'    ".global {a}\\n"')

    # Label
    parts.append(f'    "{sym}:\\n"')
    for a in alias_syms:
        parts.append(f'    "{a}:\\n"')

    # Instruction words
    for b1, b2, comment in insns:
        word = (b1 << 8) | b2
        if comment:
            # Strip address prefix: "060201B8: mov.l r14,@-r15" -> "mov.l r14,@-r15"
            cm = re.sub(r'^[0-9a-fA-F]+:\s*', '', comment)
            # Sanitize for C comment
            cm = cm.replace('/*', '').replace('*/', '')
            if len(cm) > 80:
                cm = cm[:77] + '...'
            parts.append(f'    ".word 0x{word:04X}\\n"  /* {cm} */')
        else:
            parts.append(f'    ".word 0x{word:04X}\\n"')

    # Size directive
    parts.append(f'    ".size {sym}, .-{sym}\\n"')
    parts.append(');')

    return '\n'.join(parts)


def is_noop_stub(line):
    """Check if a line is a no-op function stub."""
    stripped = line.strip()
    if not stripped or stripped.startswith('/*') or stripped.startswith('//'):
        return False
    if stripped.startswith('extern'):
        return False
    if stripped.startswith('#'):
        return False
    if '__attribute__' in stripped and 'alias' in stripped:
        return False

    # Must have { } on the same line (single-line function)
    if '{' not in stripped or '}' not in stripped:
        return False

    # Extract the body between { and }
    brace_start = stripped.index('{')
    brace_end = stripped.rindex('}')
    body = stripped[brace_start + 1:brace_end].strip()

    # Check for forwarding calls (these are NOT no-ops)
    if re.search(r'\bFUN_[0-9a-fA-F]+\s*\(', body):
        return False
    # Check for any function call that's not a (void) cast
    if re.search(r'\b[a-zA-Z_]\w*\s*\([^)]*\)', body):
        # Has something that looks like a call — check if it's all (void) casts
        stripped_body = re.sub(r'\(void\)\w+;?\s*', '', body).strip()
        if stripped_body and stripped_body != 'return 0;':
            return False

    # No-op bodies
    if body == '':
        return True
    if re.match(r'^(\(void\)\w+;\s*)+$', body):
        return True
    if body == 'return 0;':
        return True

    return False


def extract_func_name(line):
    """Extract function name from a definition line."""
    m = re.match(
        r'^(?:(?:static\s+)?(?:unsigned\s+)?(?:void|int|short|long\s+long|char)\s*\*?\s+)'
        r'(\w+)\s*\(',
        line.strip()
    )
    if m:
        return m.group(1)
    return None


def process_file(filepath, fname, func_data, label_addrs, dry_run=False):
    """Process one asm_*.c file, replacing no-op stubs with real ASM."""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    # First pass: collect alias mappings
    alias_map = {}  # FUN_UPPER -> [alias_names]
    alias_lines_to_remove = set()

    for i, line in enumerate(lines):
        stripped = line.strip()
        if '__attribute__' not in stripped or 'alias' not in stripped:
            continue

        m = re.search(r'alias\s*\(\s*"(\w+)"\s*\)', stripped)
        if not m:
            continue
        alias_target = m.group(1)

        m2 = re.match(r'^\w[\w\s*]*\s+(\w+)\s*\(', stripped)
        if not m2:
            continue
        declared_func = m2.group(1)

        if alias_target.upper().startswith('FUN_') and len(alias_target) >= 12:
            fun_key = alias_target.upper()
            alias_map.setdefault(fun_key, []).append(declared_func)
            alias_lines_to_remove.add(i)
        elif declared_func.upper().startswith('FUN_') and len(declared_func) >= 12:
            fun_key = declared_func.upper()
            alias_map.setdefault(fun_key, []).append(alias_target)
            alias_lines_to_remove.add(i)

    # Second pass: process lines
    new_lines = []
    stubs_replaced = 0
    stubs_skipped = 0
    aliases_handled = 0
    replaced_funcs = set()

    for i, line in enumerate(lines):
        # Skip alias lines whose parent stub will be/was replaced
        if i in alias_lines_to_remove:
            # We'll check after processing if the parent was actually replaced
            # For now, tentatively skip (we'll add back if parent wasn't replaced)
            continue

        if not is_noop_stub(line):
            new_lines.append(line)
            continue

        func_name = extract_func_name(line)
        if not func_name:
            new_lines.append(line)
            continue

        # Resolve FUN_ address
        fun_key = None
        if func_name.upper().startswith('FUN_') and len(func_name) >= 12:
            fun_key = func_name.upper()
        else:
            # Named function — find FUN_ via alias
            for line2 in lines:
                s2 = line2.strip()
                if 'alias' not in s2 or func_name not in s2:
                    continue
                am = re.search(r'alias\s*\(\s*"(\w+)"\s*\)', s2)
                if am:
                    t = am.group(1)
                    if t.upper().startswith('FUN_') and len(t) >= 12:
                        fun_key = t.upper()
                        break
                    # Maybe the declared func IS the FUN_
                    am2 = re.match(r'^\w[\w\s*]*\s+(FUN_[0-9a-fA-F]{8})\s*\(', s2)
                    if am2:
                        fun_key = am2.group(1).upper()
                        break
            if not fun_key:
                for key, als in alias_map.items():
                    if func_name in als:
                        fun_key = key
                        break

        if not fun_key or fun_key not in func_data:
            new_lines.append(line)
            stubs_skipped += 1
            continue

        addr = label_addrs.get(fun_key)
        if addr is None:
            new_lines.append(line)
            stubs_skipped += 1
            continue

        insns = func_data[fun_key]
        if not insns:
            new_lines.append(line)
            stubs_skipped += 1
            continue

        # Collect aliases
        aliases_list = alias_map.get(fun_key, [])

        # Determine primary name and extra globals
        if not func_name.upper().startswith('FUN_'):
            primary = func_name
            extra = [fun_key] + [a for a in aliases_list if a != func_name]
        else:
            primary = fun_key
            extra = aliases_list if aliases_list else None

        asm_block = format_asm_block(primary, addr, insns, extra)
        if asm_block:
            new_lines.append(asm_block + '\n')
            stubs_replaced += 1
            replaced_funcs.add(fun_key)
            aliases_handled += len(extra) if extra else 0
        else:
            new_lines.append(line)
            stubs_skipped += 1

    # Add back alias lines whose parent was NOT replaced
    # We need to re-scan and insert them
    orphan_aliases = []
    for i in sorted(alias_lines_to_remove):
        stripped = lines[i].strip()
        # Find the FUN_ key for this alias
        m = re.search(r'alias\s*\(\s*"(\w+)"\s*\)', stripped)
        if m:
            t = m.group(1)
            m2 = re.match(r'^\w[\w\s*]*\s+(\w+)\s*\(', stripped)
            if m2:
                declared = m2.group(1)
                key = t.upper() if t.upper().startswith('FUN_') else declared.upper()
                if key not in replaced_funcs:
                    orphan_aliases.append(lines[i])

    if orphan_aliases:
        # Append orphan aliases at the end
        new_lines.extend(orphan_aliases)

    if not dry_run and stubs_replaced > 0:
        with open(filepath, 'w', encoding='utf-8', newline='\n') as f:
            f.writelines(new_lines)

    return stubs_replaced, stubs_skipped, aliases_handled


def main():
    dry_run = '--dry-run' in sys.argv

    print("Parsing aprog.s (single pass)...")
    func_data, label_addrs = parse_aprog_all()
    print(f"Found {len(func_data)} functions with instruction data")

    total_replaced = 0
    total_skipped = 0
    total_aliases = 0

    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.startswith('asm_') or not fname.endswith('.c'):
            continue

        filepath = os.path.join(SRC_DIR, fname)
        replaced, skipped, aliases = process_file(
            filepath, fname, func_data, label_addrs, dry_run
        )

        if replaced > 0 or skipped > 0:
            print(f"  {fname}: {replaced} replaced, {skipped} skipped, {aliases} aliases")

        total_replaced += replaced
        total_skipped += skipped
        total_aliases += aliases

    mode = "DRY RUN" if dry_run else "APPLIED"
    print(f"\n{mode}: {total_replaced} stubs replaced with real ASM")
    print(f"  Skipped (no address/no data): {total_skipped}")
    print(f"  Aliases handled: {total_aliases}")


if __name__ == "__main__":
    main()
