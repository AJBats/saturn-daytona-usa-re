#!/usr/bin/env python3
"""Fix **(void **) patterns in source files using balanced paren matching.

The naive replacement of **(void **) with *(int(*)())(*(int *) breaks paren
balance. This script properly handles the rewrite by:
1. First reverting the broken replacement (*(int(*)())(*(int *) back to **(void **))
2. Then properly rewriting with balanced parens.
"""

import re
import os
import glob


def revert_broken_replacement(text):
    """Revert the broken naive replacement back to **(void **)."""
    # The broken replacement changed:
    #   (**(void **)(expr))(args) to (*(int(*)())(*(int *)(expr))(args)
    # We need to put it back to (**(void **)(expr))(args)
    # Then properly fix it.
    count = 0
    # Pattern: *(int(*)())(*(int *) -> **(void **)
    old = '*(int(*)())(*(int *)'
    new = '**(void **)'
    while old in text:
        text = text.replace(old, new, 1)
        count += 1
    return text, count


def find_matching_close(text, start):
    """Find matching ) for ( at start position."""
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


def fix_double_indirect_calls(text):
    """Properly fix all (**(void **)EXPR)(ARGS) patterns.

    Converts to (*(int(*)())(*(int *)EXPR))(ARGS)
    The key is adding the extra ) to close the outer expression.
    """
    changes = 0
    result = []
    i = 0

    while i < len(text):
        # Look for (**  followed by (void **)
        if text[i] == '(' and i + 2 < len(text) and text[i+1] == '*' and text[i+2] == '*':
            m = re.match(r'\(\*\*\s*\(void\s*\*\*\)\s*', text[i:])
            if m:
                after_cast = i + m.end()  # position after (**(void **)

                # Find the matching ) for the outer (
                outer_close = find_matching_close(text, i)
                if outer_close > 0 and outer_close + 1 < len(text) and text[outer_close + 1] == '(':
                    # Extract inner expression
                    inner_expr = text[after_cast:outer_close]
                    # Find matching ) for the call args
                    args_open = outer_close + 1
                    args_close = find_matching_close(text, args_open)
                    if args_close > 0:
                        args = text[args_open + 1:args_close]
                        # Build: (*(int(*)())(*(int *)EXPR))(ARGS)
                        replacement = '(*(int(*)())(*(int *)' + inner_expr + '))(' + args + ')'
                        result.append(replacement)
                        i = args_close + 1
                        changes += 1
                        continue

        # Also handle patterns where ** is not at ( start
        # e.g., iVar = (**(void **)(expr))(args)
        # This is covered by the above since ( is the start

        result.append(text[i])
        i += 1

    return ''.join(result), changes


def process_file(filepath):
    """Fix a single file."""
    with open(filepath, 'r') as f:
        text = f.read()

    original = text

    # Step 1: Revert any broken replacements
    text, reverted = revert_broken_replacement(text)

    # Step 2: Now properly fix all **(void **) patterns
    text, fixed = fix_double_indirect_calls(text)

    if text != original:
        with open(filepath, 'w') as f:
            f.write(text)
        return True, reverted, fixed
    return False, 0, 0


def main():
    srcdir = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'src')
    files = sorted(glob.glob(os.path.join(srcdir, '*.c')))

    total_changed = 0
    total_reverted = 0
    total_fixed = 0

    for filepath in files:
        changed, reverted, fixed = process_file(filepath)
        if changed:
            total_changed += 1
            base = os.path.basename(filepath)
            print('  {}: reverted={}, fixed={}'.format(base, reverted, fixed))
            total_reverted += reverted
            total_fixed += fixed

    print('\n=== SUMMARY ===')
    print('Files modified: {} / {}'.format(total_changed, len(files)))
    print('Reverted broken: {}'.format(total_reverted))
    print('Properly fixed: {}'.format(total_fixed))


if __name__ == '__main__':
    main()
