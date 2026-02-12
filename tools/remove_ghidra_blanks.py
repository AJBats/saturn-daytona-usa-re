#!/usr/bin/env python3
"""Remove Ghidra-inserted blank lines from L1 function bodies.

Ghidra decompiler output inserts a blank line between every statement,
doubling the line count. This script removes consecutive blank lines
within function bodies in batch_*.c files, preserving:
- Blank lines between functions (1 max)
- Blank lines around comments
- Already-elevated L2 functions (those with header comments)
- Forwarding wrapper one-liners
"""
import re, os, sys

src_dir = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'reimpl', 'src')

# Match function definition start (both K&R and ANSI style)
FUNC_DEF_RE = re.compile(
    r'^(?:(?:static\s+)?(?:void|int|unsigned int|char\s*\*|short|long long|unsigned short|unsigned char)\s+)'
    r'(FUN_([0-9a-fA-F]+))\s*\('
)

# L2 header comment pattern
L2_HEADER_RE = re.compile(r'^/\*\s+\w+.*--')

# Forwarding wrapper pattern (single line body calling another function)
FORWARDING_RE = re.compile(r'^\s*(?:return\s+)?FUN_[0-9a-fA-F]+\s*\(')

def is_l1_function(lines, func_start_idx):
    """Check if a function is still L1 (raw Ghidra output).

    L2 functions have a header comment immediately before them,
    or have been significantly restructured.
    """
    # Check for L2 header comment above
    for i in range(func_start_idx - 1, max(func_start_idx - 3, -1), -1):
        if i < 0:
            break
        line = lines[i].strip()
        if line.startswith('/*') and '--' in line:
            return False  # Has L2 header
        if line and not line.startswith('/*') and not line.startswith('*') and not line.endswith('*/'):
            break

    return True

def find_function_body(lines, start_idx):
    """Find the opening and closing braces of a function body."""
    brace_depth = 0
    body_start = None

    i = start_idx
    while i < len(lines):
        line = lines[i]
        for ch in line:
            if ch == '{':
                if brace_depth == 0:
                    body_start = i
                brace_depth += 1
            elif ch == '}':
                brace_depth -= 1
                if brace_depth == 0:
                    return body_start, i
        i += 1

    return body_start, None

def is_only_blanks_pattern(body_lines):
    """Check if the blank line pattern matches Ghidra's style.

    Ghidra inserts blanks between almost every statement.
    We detect this by checking if >30% of body lines are blank.
    """
    if len(body_lines) < 4:
        return False

    blank_count = sum(1 for l in body_lines if l.strip() == '')
    return blank_count > len(body_lines) * 0.25

def remove_interior_blanks(body_lines):
    """Remove blank lines within a function body, keeping one after
    variable declarations and before the closing brace."""
    result = []
    in_declarations = True
    prev_was_blank = False

    for i, line in enumerate(body_lines):
        stripped = line.strip()

        # Always keep the opening brace line
        if i == 0:
            result.append(line)
            continue

        # Always keep the closing brace line
        if i == len(body_lines) - 1:
            # Remove trailing blank before closing brace
            while result and result[-1].strip() == '':
                result.pop()
            result.append(line)
            continue

        # Skip blank lines (we'll add them back strategically)
        if stripped == '':
            prev_was_blank = True
            continue

        # Detect end of declarations section
        if in_declarations:
            # Declaration lines: type var; or type var = expr;
            is_decl = (stripped.startswith(('int ', 'char ', 'unsigned ', 'short ',
                                          'long ', 'void ', 'char *'))
                       and stripped.endswith(';')
                       and '(' not in stripped
                       and '=' not in stripped.split(';')[0].split('=')[0] + ';'
                       ) or (
                       stripped.startswith(('int ', 'char ', 'unsigned ', 'short ',
                                          'long ', 'char *'))
                       and '= 0;' in stripped
                       )

            if not is_decl and not stripped.startswith('/*'):
                in_declarations = False
                # Add one blank after declarations if we had any
                if result and result[-1].strip() != '' and result[-1].strip() != '{':
                    result.append('\n')

        prev_was_blank = False
        result.append(line)

    return result

def process_file(path, fname, dry_run=False):
    with open(path, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    # Find all L1 functions and their body ranges
    functions_to_clean = []
    i = 0
    while i < len(lines):
        m = FUNC_DEF_RE.match(lines[i])
        if m and is_l1_function(lines, i):
            body_start, body_end = find_function_body(lines, i)
            if body_start is not None and body_end is not None:
                body_lines = lines[body_start:body_end + 1]

                # Skip tiny functions (1-3 line bodies = wrappers)
                non_blank = [l for l in body_lines if l.strip()]
                if len(non_blank) <= 3:
                    i = body_end + 1
                    continue

                # Skip if not Ghidra blank pattern
                if is_only_blanks_pattern(body_lines):
                    functions_to_clean.append({
                        'func': m.group(1),
                        'body_start': body_start,
                        'body_end': body_end,
                        'orig_lines': len(body_lines),
                        'blank_lines': sum(1 for l in body_lines if l.strip() == ''),
                    })

                i = body_end + 1
                continue
        i += 1

    if not functions_to_clean:
        return 0, 0

    # Process from bottom up to preserve line numbers
    total_removed = 0
    for func in reversed(functions_to_clean):
        body_lines = lines[func['body_start']:func['body_end'] + 1]
        cleaned = remove_interior_blanks(body_lines)
        removed = len(body_lines) - len(cleaned)
        total_removed += removed

        # Replace in the lines array
        lines[func['body_start']:func['body_end'] + 1] = cleaned

    if not dry_run and total_removed > 0:
        with open(path, 'w', encoding='utf-8', newline='\n') as f:
            f.writelines(lines)

    return len(functions_to_clean), total_removed

def main():
    dry_run = '--dry-run' in sys.argv

    total_funcs = 0
    total_lines = 0

    for fname in sorted(os.listdir(src_dir)):
        if not fname.startswith('batch_') or not fname.endswith('.c'):
            continue
        path = os.path.join(src_dir, fname)
        funcs, removed = process_file(path, fname, dry_run)
        if funcs > 0:
            print(f"  {fname}: {funcs} functions, {removed} blank lines removed")
            total_funcs += funcs
            total_lines += removed

    mode = "DRY RUN" if dry_run else "APPLIED"
    print(f"\n{mode}: {total_funcs} functions cleaned, {total_lines} blank lines removed")

if __name__ == '__main__':
    main()
