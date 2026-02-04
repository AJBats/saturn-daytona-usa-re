#!/usr/bin/env python3
"""Bulk fix remaining compile errors in src/*.c files.

Round 2 fixes:
1. Bare dereference with cast: (type)*0xADDR -> (type)*(int *)0xADDR
   (remove overly restrictive lookbehind)
2. Bare subscript with cast: (type)0xADDR[N] -> (type)((int *)0xADDR)[N]
   (remove overly restrictive lookbehind)
3. Complex double-indirect: (**(void **)(complex_expr))(args)
   -> (*(int(*)())(*(int *)(complex_expr)))(args)
   (handle nested parens properly)
4. switchD_ references: replace with extern int array
5. stack0x... references: declare as local int
"""

import re
import os
import glob
import sys

def find_matching_paren(text, start):
    """Find the matching closing paren for the opening paren at position start."""
    depth = 0
    i = start
    while i < len(text):
        if text[i] == '(':
            depth += 1
        elif text[i] == ')':
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1

def fix_complex_double_indirect(text):
    """Fix (**(void **)(complex_expr))(args) patterns with nested parens.

    Converts to (*(int(*)())(*(int *)(complex_expr)))(args)
    """
    result = []
    i = 0
    changes = 0
    while i < len(text):
        # Look for (**(void **) - use regex directly for robustness
        if text[i] == '(' and text[i+1:i+3] == '**':
            m = re.match(r'\(\*\*\s*\(void\s*\*\*\)\s*', text[i:])
            if m:
                prefix_end = i + m.end()  # position after (void **)

                # Now find the matching ) for the outer (
                # The outer ( is at position i
                close = find_matching_paren(text, i)
                if close > 0 and close < len(text) - 1 and text[close + 1] == '(':
                    # Extract the expression between (void **) and the closing )
                    expr = text[prefix_end:close]
                    # Find the matching ) for the call args
                    args_close = find_matching_paren(text, close + 1)
                    if args_close > 0:
                        args = text[close+2:args_close]
                        # Build replacement: (*(int(*)())(*(int *)EXPR))(ARGS)
                        replacement = '(*(int(*)())(*(int *)' + expr + '))(' + args + ')'
                        result.append(replacement)
                        i = args_close + 1
                        changes += 1
                        continue
        result.append(text[i])
        i += 1
    return ''.join(result), changes

def fix_bare_deref(text):
    """Fix *0xADDR -> *(int *)0xADDR without restrictive lookbehind.

    The regex \*(0xHEX) only matches when * is directly before 0x,
    which naturally avoids already-cast cases like *(int *)0xADDR.
    """
    # Remove old lookbehind, just match *0xADDR directly
    # But avoid matching inside already-cast expressions
    new_text = re.sub(r'\*(0x[0-9A-Fa-f]+)\b', r'*(int *)\1', text)
    # Clean up any double-casting that might result
    new_text = re.sub(r'\*\(int \*\)\(int \*\)', '*(int *)', new_text)
    changes = len(re.findall(r'\*(0x[0-9A-Fa-f]+)\b', text)) - len(re.findall(r'\*(0x[0-9A-Fa-f]+)\b', new_text))
    # Count actual changes
    changes = 0
    for old, new in zip(text.split('\n'), new_text.split('\n')):
        if old != new:
            changes += 1
    return new_text, changes

def fix_bare_subscript(text):
    """Fix 0xADDR[N] -> ((int *)0xADDR)[N] without restrictive lookbehind."""
    new_text = re.sub(r'(0x[0-9A-Fa-f]+)\[', r'((int *)\1)[', text)
    # Clean up double-casting
    new_text = re.sub(r'\(\(int \*\)\(int \*\)', '((int *)', new_text)
    changes = 0
    for old, new in zip(text.split('\n'), new_text.split('\n')):
        if old != new:
            changes += 1
    return new_text, changes

def fix_switch_data_refs(text):
    """Fix switchD_ADDR::switchdataD_ADDR references.

    Pattern: (&switchD_06026332::switchdataD_06026338)[uVar5]
    Replace with: ((int *)0x06026338)[uVar5]

    The switchdataD address IS the address of the switch table data.
    """
    changes = 0
    # Pattern: (&switchD_ADDR::switchdataD_ADDR)[expr]
    def replace_switchdata(m):
        nonlocal changes
        changes += 1
        addr = m.group(2)
        expr = m.group(3)
        return '((int *)0x' + addr + ')[' + expr + ']'

    new_text = re.sub(
        r'\(&switchD_[0-9A-Fa-f]+::switchdataD_([0-9A-Fa-f]+)\)\[([^\]]*)\]',
        lambda m: '((int *)0x' + m.group(1) + ')[' + m.group(2) + ']',
        text
    )
    changes = len(re.findall(r'&switchD_[0-9A-Fa-f]+::switchdataD_', text))
    return new_text, changes

def fix_stack_refs(text):
    """Fix stack0xffffffXX references by declaring them as local variables.

    Pattern: &stack0xffffffec -> use a local array
    """
    changes = 0
    # Find all stack references
    stack_refs = set(re.findall(r'stack(0x[0-9A-Fa-f]+)', text))
    if not stack_refs:
        return text, 0

    # For each stack ref, add a declaration at the top of the function body
    for ref in stack_refs:
        varname = 'stack' + ref
        # Declare as int if not already declared
        if 'int ' + varname not in text:
            # Find the opening { of the function body
            # Add declaration after it
            m = re.search(r'^(\w[^{]*)\{', text, re.MULTILINE)
            if m:
                insert_pos = m.end()
                text = text[:insert_pos] + '\n  int ' + varname + ';' + text[insert_pos:]
                changes += 1

    return text, changes

def fix_void_value_remaining(text):
    """Fix remaining void value issues from non-FUN_ extern void declarations.

    Pattern: extern void somefunc() where return value is used
    Also: void funcname() definitions where return value is used internally
    """
    changes = 0
    # Fix extern void for non-FUN_ functions too
    new_text = re.sub(r'^extern void (\w+)\s*\(', r'extern int \1(', text, flags=re.MULTILINE)
    for old, new in zip(text.split('\n'), new_text.split('\n')):
        if old != new:
            changes += 1
    return new_text, changes

def fix_dat_double_deref(text):
    """Fix (**DAT_ADDR)() patterns - Ghidra global function pointer.

    Pattern: (**DAT_06002db8)()
    Fix: (*(int(*)())(*(int *)&DAT_06002db8))()
    But DAT_ is likely just an address, so: (*(int(*)())(*(int *)0x06002db8))()
    """
    changes = 0
    def replace_dat(m):
        nonlocal changes
        changes += 1
        addr = m.group(1)
        return '(*(int(*)())(*(int *)0x' + addr + '))'

    new_text = re.sub(r'\(\*\*DAT_([0-9A-Fa-f]+)\)', replace_dat, text)
    # Also declare DAT_ externs if still referenced
    dat_refs = re.findall(r'\bDAT_([0-9A-Fa-f]+)\b', new_text)
    return new_text, changes

def process_file(filepath):
    """Apply all fixes to a single file. Returns (changed, fix_counts)."""
    with open(filepath, 'r') as f:
        original = f.read()

    text = original
    total_changes = {}

    # Fix 1: Complex double-indirect (must come before bare deref)
    text, n = fix_complex_double_indirect(text)
    if n: total_changes['double_indirect'] = n

    # Fix 2: DAT_ double deref
    text, n = fix_dat_double_deref(text)
    if n: total_changes['dat_deref'] = n

    # Fix 3: Bare dereference (remove lookbehind issue)
    text, n = fix_bare_deref(text)
    if n: total_changes['bare_deref'] = n

    # Fix 4: Bare subscript (remove lookbehind issue)
    text, n = fix_bare_subscript(text)
    if n: total_changes['bare_subscript'] = n

    # Fix 5: switchD_ references
    text, n = fix_switch_data_refs(text)
    if n: total_changes['switch_data'] = n

    # Fix 6: stack references
    text, n = fix_stack_refs(text)
    if n: total_changes['stack_refs'] = n

    # Fix 7: Remaining extern void
    text, n = fix_void_value_remaining(text)
    if n: total_changes['void_value'] = n

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
                print(f"  {base}: {fixes}")
            for k, v in fixes.items():
                fix_totals[k] = fix_totals.get(k, 0) + v

    print(f"\n=== SUMMARY ===")
    print(f"Files modified: {total_changed} / {len(files)}")
    for k, v in sorted(fix_totals.items(), key=lambda x: -x[1]):
        print(f"  {k}: {v} fixes")

if __name__ == '__main__':
    main()
