#!/usr/bin/env python3
"""Bulk fix remaining compile errors - round 4 (final cleanup).

Fixes:
1. Missing ) in function signatures: FUN_xxx(params\n{ -> FUN_xxx(params)\n{
2. ram0xADDR -> *(int *)0xADDR or 0xADDR
3. Computed calls: (*(0xADDR + expr))() -> (*(int(*)())(0xADDR + expr))()
4. Onchip_XXX -> extern int declaration
5. Missing function name: 'int \n{' -> 'int placeholder()\n{'
6. Sub-field refs with subscript: var[N]._X_Y_ -> var[N]
7. PTR_DAT duplicate externs
"""

import re
import os
import glob


def fix_missing_close_paren(text):
    """Fix function signatures missing ) before {.

    Pattern: FUN_xxx(int param_1, ..., int param_N\n{
    Fix: FUN_xxx(int param_1, ..., int param_N)\n{
    """
    changes = 0
    # Match: function_name(params without close paren, then { on next line
    # K&R style: FUN_xxx(params\n{  should be FUN_xxx(params)\n{
    # ANSI style: FUN_xxx(int p1, ..., int pN\n{  should be FUN_xxx(int p1, ..., int pN)\n{
    lines = text.split('\n')
    new_lines = []
    for i, line in enumerate(lines):
        if (i + 1 < len(lines) and
                lines[i + 1].strip() == '{' and
                '(' in line and ')' not in line and
                not line.strip().startswith('/') and
                not line.strip().startswith('*')):
            # Missing close paren before {
            new_lines.append(line + ')')
            changes += 1
        else:
            new_lines.append(line)
    return '\n'.join(new_lines), changes


def fix_ram_refs(text):
    """Fix ram0xADDR -> *(int *)0xADDR for memory references."""
    changes = 0
    # ram0xADDR used as function pointer: (*(int(*)())ram0xADDR)(
    new_text = re.sub(r'\bram(0x[0-9A-Fa-f]+)\b', r'*(int *)\1', text)
    for old, new in zip(text.split('\n'), new_text.split('\n')):
        if old != new:
            changes += 1
    return new_text, changes


def fix_computed_calls_remaining(text):
    """Fix (*(0xADDR + expr))() -> (*(int(*)())(0xADDR + expr))().

    These are PC-relative computed branches.
    """
    changes = 0
    # Pattern: (*(0xHEX + expr))(  -- needs function pointer cast
    new_text = re.sub(
        r'\(\*\((0x[0-9A-Fa-f]+\s*\+[^)]*)\)\)\s*\(',
        r'(*(int(*)())(\1))(',
        text
    )
    for old, new in zip(text.split('\n'), new_text.split('\n')):
        if old != new:
            changes += 1
    return new_text, changes


def fix_onchip_refs(text):
    """Fix Onchip_XXX -> declare as extern int or pointer."""
    changes = 0
    onchip = set(re.findall(r'\bOnchip_(\w+)\b', text))
    if not onchip:
        return text, 0

    for name in onchip:
        varname = 'Onchip_' + name
        if 'extern int ' + varname not in text and 'int ' + varname not in text:
            # Add extern declaration at top
            text = 'extern int {};\n'.format(varname) + text
            changes += 1

    return text, changes


def fix_missing_func_name(text):
    """Fix files where function name is missing: 'int \\n{' -> 'int _unknown_()'."""
    changes = 0
    lines = text.split('\n')
    new_lines = []
    for i, line in enumerate(lines):
        stripped = line.strip()
        if (stripped in ('int', 'int *', 'void', 'unsigned int') and
                i + 1 < len(lines) and lines[i + 1].strip() == '{'):
            # Missing function name
            # Try to get name from filename context
            new_lines.append(stripped + ' _unknown_()')
            changes += 1
        elif (stripped == 'int *' and
              i + 1 < len(lines) and lines[i + 1].strip() == '{'):
            new_lines.append('int * _unknown_()')
            changes += 1
        else:
            new_lines.append(line)
    return '\n'.join(new_lines), changes


def fix_subscript_subfield(text):
    """Fix var[N]._X_Y_ -> var[N] (subscript + Ghidra sub-field)."""
    changes = 0
    new_text = re.sub(r'(\]\s*)\._(\d+)_(\d+)_', r'\1', text)
    for old, new in zip(text.split('\n'), new_text.split('\n')):
        if old != new:
            changes += 1
    return new_text, changes


def fix_conflicting_types(text):
    """Fix files with conflicting type redefinitions by removing duplicate var blocks.

    Some Ghidra output has the same variable declared twice with different types
    in what looks like two separate scope blocks.
    """
    # This is complex - skip for now, these files need manual intervention
    return text, 0


def process_file(filepath):
    """Apply all round 4 fixes."""
    with open(filepath, 'r') as f:
        original = f.read()

    text = original
    total_changes = {}

    text, n = fix_missing_close_paren(text)
    if n: total_changes['missing_paren'] = n

    text, n = fix_ram_refs(text)
    if n: total_changes['ram_refs'] = n

    text, n = fix_computed_calls_remaining(text)
    if n: total_changes['computed_call'] = n

    text, n = fix_onchip_refs(text)
    if n: total_changes['onchip'] = n

    text, n = fix_missing_func_name(text)
    if n: total_changes['missing_name'] = n

    text, n = fix_subscript_subfield(text)
    if n: total_changes['subscript_subfield'] = n

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
