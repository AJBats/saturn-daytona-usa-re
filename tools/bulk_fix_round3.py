#!/usr/bin/env python3
"""Bulk fix remaining compile errors - round 3.

Fixes:
1. UNK_ADDR references: &UNK_00000002 -> (void *)0x00000002
2. Arithmetic subscript: (0xADDR + expr)[N] -> ((char *)(0xADDR + expr))[N]
3. Computed function call: (*(0xADDR + expr))(args) -> (*(int(*)())(0xADDR + expr))(args)
4. Double-deref variable: (**varname)(args) -> (*(int(*)())(*(int *)varname))(args)
5. CONCAT macros: CONCAT13(a,b) -> ((a) << 24 | (b)), etc.
6. _local/_uStack vars: declare as int
7. auStack array calls: (*auStack_XX[expr])(args) -> (*(int(*)())auStack_XX[expr])(args)
"""

import re
import os
import glob
import sys


def fix_unk_refs(text):
    """Fix &UNK_ADDR -> (void *)0xADDR and UNK_ADDR -> 0xADDR."""
    changes = 0
    # &UNK_00000002 -> (void *)0x00000002
    new_text = re.sub(r'&UNK_([0-9A-Fa-f]+)', r'(void *)0x\1', text)
    # Plain UNK_00000002 (without &) -> 0x00000002
    new_text = re.sub(r'\bUNK_([0-9A-Fa-f]+)\b', r'0x\1', new_text)
    for old, new in zip(text.split('\n'), new_text.split('\n')):
        if old != new:
            changes += 1
    return new_text, changes


def fix_arithmetic_subscript(text):
    """Fix (arithmetic_expr)[N] where expr starts with 0xADDR + ...

    Pattern: (0xADDR + stuff)[N] -> ((char *)(0xADDR + stuff))[N]
    The key is that (expr)[N] means byte-subscript from the address.
    """
    changes = 0
    # Match (0xADDR + ...) followed by [
    # Need to find balanced parens: ( stuff_with_0x )[
    lines = text.split('\n')
    new_lines = []
    for line in lines:
        new_line = line
        # Look for pattern: (0xHEX + stuff)[
        # Simple approach: find )[digits_or_expr] where the paren contents start with 0x
        # Use a different regex: find occurrences of )[N] or )[expr] that need cast
        # Pattern: (0x... + ...)[  -- the paren group starts with 0x
        m_iter = list(re.finditer(r'\(0x[0-9A-Fa-f]+\s*[+\-]', new_line))
        for m in reversed(m_iter):
            start = m.start()
            # Find the matching close paren
            depth = 0
            j = start
            close = -1
            while j < len(new_line):
                if new_line[j] == '(':
                    depth += 1
                elif new_line[j] == ')':
                    depth -= 1
                    if depth == 0:
                        close = j
                        break
                j += 1
            if close > 0 and close + 1 < len(new_line) and new_line[close + 1] == '[':
                # Check it's not already cast: ((char *)...)[ or ((int *)...)[
                if start > 0 and new_line[start-1] == '(' and start > 1 and new_line[start-2:start] in ('* ', '*)'):
                    continue  # Already has a pointer cast
                # Wrap with (char *): ((char *)(expr))[
                inner = new_line[start:close+1]
                new_line = new_line[:start] + '((char *)' + inner + ')' + new_line[close+1:]
                changes += 1

        new_lines.append(new_line)
    return '\n'.join(new_lines), changes


def fix_computed_call(text):
    """Fix (*(0xADDR + expr))(args) -> (*(int(*)())(0xADDR + expr))(args).

    Pattern: call through computed address without function pointer cast.
    """
    changes = 0
    # Pattern: (*(0xHEX + expr))(
    # This means: compute address, deref, call. Need function pointer cast.
    # Match: (* followed by (0x...) then )(
    lines = text.split('\n')
    new_lines = []
    for line in lines:
        # Find (*(0xHEX + ...) or (*(0xHEX ...))( patterns
        # Look for (*(0x and add int(*)() cast
        new_line = re.sub(
            r'\(\*\s*\((0x[0-9A-Fa-f]+\s*[+\-][^)]*)\)\s*\)\s*\(',
            r'(*(int(*)())(\1))(',
            line
        )
        if new_line != line:
            changes += 1
        new_lines.append(new_line)
    return '\n'.join(new_lines), changes


def fix_double_deref_var(text):
    """Fix (**varname)(args) -> (*(int(*)())(*(int *)varname))(args).

    Pattern: double-deref through a pointer variable for function calls.
    """
    changes = 0
    # (**varname)( -> (*(int(*)())(*(int *)varname))(
    new_text = re.sub(
        r'\(\*\*([a-zA-Z_]\w*)\)\s*\(',
        r'(*(int(*)())(*(int *)\1))(',
        text
    )
    for old, new in zip(text.split('\n'), new_text.split('\n')):
        if old != new:
            changes += 1
    return new_text, changes


def fix_concat_macros(text):
    """Fix CONCAT macros: CONCAT13(a,b), CONCAT22(a,b), etc."""
    changes = 0
    # CONCAT13(a,b) = concatenate 1-byte and 3-byte values = (a << 24) | (b & 0xFFFFFF)
    # CONCAT22(a,b) = concatenate 2-byte and 2-byte = (a << 16) | (b & 0xFFFF)
    # CONCAT31(a,b) = (a << 8) | (b & 0xFF)
    # CONCAT44(a,b) = (a << 32) | b  (but that's 64-bit, unusual)
    # CONCAT11(a,b) = (a << 8) | (b & 0xFF)

    concat_shifts = {
        'CONCAT11': (8, 0xFF),
        'CONCAT12': (16, 0xFFFF),
        'CONCAT13': (24, 0xFFFFFF),
        'CONCAT21': (8, 0xFF),
        'CONCAT22': (16, 0xFFFF),
        'CONCAT31': (8, 0xFF),
    }

    for macro, (shift, mask) in concat_shifts.items():
        pattern = macro + r'\s*\(([^,]+),\s*([^)]+)\)'
        def make_replacement(shift, mask):
            def replace(m):
                a = m.group(1).strip()
                b = m.group(2).strip()
                return '(({}) << {} | ({}) & 0x{:X})'.format(a, shift, b, mask)
            return replace
        new_text = re.sub(pattern, make_replacement(shift, mask), text)
        if new_text != text:
            changes += 1
            text = new_text

    return text, changes


def fix_underscore_locals(text):
    """Declare _local_XX and _uStack_XX variables."""
    changes = 0
    # Find undeclared _local_XX or _uStack_XX
    local_vars = set(re.findall(r'\b(_local_[0-9a-fA-F]+)\b', text))
    stack_vars = set(re.findall(r'\b(_uStack_[0-9a-fA-F]+)\b', text))
    all_vars = local_vars | stack_vars

    if not all_vars:
        return text, 0

    # Check if they're already declared
    for var in list(all_vars):
        # If already declared (as int varname or char* varname etc), skip
        if re.search(r'(int|char|short|long|unsigned)\s+' + re.escape(var) + r'\b', text):
            all_vars.discard(var)

    if not all_vars:
        return text, 0

    # Find the function body opening {
    # Insert declarations after first {
    m = re.search(r'\{', text)
    if m:
        insert_pos = m.end()
        decls = '\n'.join('  int {};'.format(v) for v in sorted(all_vars))
        text = text[:insert_pos] + '\n' + decls + text[insert_pos:]
        changes = len(all_vars)

    return text, changes


def fix_array_call(text):
    """Fix (*auStack_XX[expr])(args) -> (*(int(*)())auStack_XX[expr])(args).

    Pattern: deref array element and call as function.
    """
    changes = 0
    # (*identifier[expr])(args)
    new_text = re.sub(
        r'\(\*([a-zA-Z_]\w*\[[^\]]+\])\)\s*\(',
        r'(*(int(*)())\1)(',
        text
    )
    for old, new in zip(text.split('\n'), new_text.split('\n')):
        if old != new:
            changes += 1
    return new_text, changes


def fix_remaining_void_double_indirect(text):
    """Fix (**(void **)(complex_expr))(args) patterns that round 2 missed.

    Look for any remaining **(void **) patterns and fix them.
    """
    changes = 0
    # Find remaining **(void **) patterns
    pattern = r'\*\*\s*\(void\s*\*\*\)'
    if not re.search(pattern, text):
        return text, 0

    # Replace **(void **) with *(int(*)())(*(int *) everywhere
    # This changes double-deref to single-deref with function pointer cast
    result = []
    i = 0
    while i < len(text):
        m = re.match(r'\*\*\s*\(void\s*\*\*\)', text[i:])
        if m:
            result.append('*(int(*)())(*(int *)')
            i += m.end()
            changes += 1
        else:
            result.append(text[i])
            i += 1
    return ''.join(result), changes


def process_file(filepath):
    """Apply all round 3 fixes to a single file."""
    with open(filepath, 'r') as f:
        original = f.read()

    text = original
    total_changes = {}

    # Fix 1: UNK_ references
    text, n = fix_unk_refs(text)
    if n: total_changes['unk_refs'] = n

    # Fix 2: Arithmetic subscript
    text, n = fix_arithmetic_subscript(text)
    if n: total_changes['arith_subscript'] = n

    # Fix 3: Computed function call
    text, n = fix_computed_call(text)
    if n: total_changes['computed_call'] = n

    # Fix 4: Double-deref variable
    text, n = fix_double_deref_var(text)
    if n: total_changes['double_deref_var'] = n

    # Fix 5: CONCAT macros
    text, n = fix_concat_macros(text)
    if n: total_changes['concat'] = n

    # Fix 6: Underscore local variables
    text, n = fix_underscore_locals(text)
    if n: total_changes['underscore_locals'] = n

    # Fix 7: Array element calls
    text, n = fix_array_call(text)
    if n: total_changes['array_call'] = n

    # Fix 8: Remaining void** double-indirect
    text, n = fix_remaining_void_double_indirect(text)
    if n: total_changes['void_double_indirect'] = n

    if text != original:
        with open(filepath, 'w') as f:
            f.write(text)
        return True, total_changes
    return False, {}


def main():
    srcdir = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'src')
    files = sorted(glob.glob(os.path.join(srcdir, '*.c')))

    total_changed = 0
    fix_totals = {}

    for filepath in files:
        changed, fixes = process_file(filepath)
        if changed:
            total_changed += 1
            base = os.path.basename(filepath)
            if fixes:
                print('  {}: {}'.format(base, fixes))
            for k, v in fixes.items():
                fix_totals[k] = fix_totals.get(k, 0) + v

    print('\n=== SUMMARY ===')
    print('Files modified: {} / {}'.format(total_changed, len(files)))
    for k, v in sorted(fix_totals.items(), key=lambda x: -x[1]):
        print('  {}: {} fixes'.format(k, v))


if __name__ == '__main__':
    main()
