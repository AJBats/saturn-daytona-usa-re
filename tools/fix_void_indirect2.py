#!/usr/bin/env python3
"""Fix all remaining **(void **) patterns properly.

Strategy:
1. Find (**(void **)
2. Find the inner expression (with balanced parens)
3. Find the call (ARGS)
4. Handle extra ) from previous broken fixes
5. Rewrite to (*(int(*)())(*(int *)EXPR))(ARGS)
"""

import re
import os
import glob


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


def fix_all_void_double_indirect(text):
    """Fix all (**(void **)EXPR)(ARGS) and (**(void **)EXPR))(ARGS) patterns."""
    changes = 0
    result = []
    i = 0

    while i < len(text):
        # Look for (**  followed by (void **)
        if (text[i] == '(' and i + 2 < len(text) and
                text[i+1] == '*' and text[i+2] == '*'):
            m = re.match(r'\(\*\*\s*\(void\s*\*\*\)\s*', text[i:])
            if m:
                after_cast = i + m.end()

                # Find the matching ) for the outer (
                outer_close = find_matching_close(text, i)
                if outer_close > 0:
                    inner_expr = text[after_cast:outer_close]

                    # Check what follows the outer close
                    # Could be: )(ARGS) or ))(ARGS) or )\n  (ARGS)
                    next_pos = outer_close + 1
                    # Skip any extra ) chars and whitespace/newlines
                    while next_pos < len(text) and text[next_pos] in ')  \t\n\r':
                        next_pos += 1

                    if next_pos < len(text) and text[next_pos] == '(':
                        # Found the call
                        args_close = find_matching_close(text, next_pos)
                        if args_close > 0:
                            args = text[next_pos + 1:args_close]
                            # Build: (*(int(*)())(*(int *)EXPR))(ARGS)
                            replacement = '(*(int(*)())(*(int *)' + inner_expr + '))(' + args + ')'
                            result.append(replacement)
                            i = args_close + 1
                            changes += 1
                            continue

        result.append(text[i])
        i += 1

    return ''.join(result), changes


def process_file(filepath):
    """Fix a single file."""
    with open(filepath, 'r') as f:
        text = f.read()

    original = text
    text, fixed = fix_all_void_double_indirect(text)

    if text != original:
        with open(filepath, 'w') as f:
            f.write(text)
        return True, fixed
    return False, 0


def main():
    srcdir = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'src')
    files = sorted(glob.glob(os.path.join(srcdir, '*.c')))

    total_changed = 0
    total_fixed = 0

    for filepath in files:
        changed, fixed = process_file(filepath)
        if changed:
            total_changed += 1
            base = os.path.basename(filepath)
            print('  {}: fixed={}'.format(base, fixed))
            total_fixed += fixed

    print('\n=== SUMMARY ===')
    print('Files modified: {} / {}'.format(total_changed, len(files)))
    print('Total fixed: {}'.format(total_fixed))


if __name__ == '__main__':
    main()
