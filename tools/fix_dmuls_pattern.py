#!/usr/bin/env python3
"""
Replace Ghidra's manual 32x32->64 signed multiply pattern with proper C.

Ghidra expands SH-2 dmuls.l (signed 32x32->64-bit multiply) into ~15 lines
of manual unsigned 16x16 multiplies with carry chain and sign correction.
This inflates render pipeline code by ~10x.

This tool detects and replaces the pattern with:
    { long long _m = (long long)(int)a * (int)b;
      result_hi = (unsigned int)((unsigned long long)_m >> 32);
      result_lo = (unsigned int)_m; }

The pattern detected is:
    <xor> = <a> ^ <b>;
    if ((int)<a> < 0) { <a> = -<a>; }
    if ((int)<b> < 0) { <b> = -<b>; }
    <t1> = (<b> & 0xffff) * (<a> & 0xffff);
    <t2> = (<b> >> 0x10) * (<a> & 0xffff);
    <t3> = 0;
    <t4> = <t2> + (<b> & 0xffff) * (<a> >> 0x10);
    if (<t2> != 0) { <t3> = 0x10000; }
    <lo> = <t1> + (<t4> << 16);
    <hi> = <t3> + (unsigned int)(<lo> < <t1>) + (<t4> >> 0x10) + ...;
    if ((int)-(unsigned int)((int)<xor> < 0) < 0) {
      <hi> = ~<hi>;
      if (<lo> == 0) { <hi> = <hi> + 1; }
      else { <lo> = ~<lo> + 1; }
    }
"""

import re
import sys
import os

# Unique counter for temp variables to avoid name collisions
_mul_counter = 0

def find_dmuls_patterns(lines):
    """Find all dmuls patterns and return list of (start_line, end_line, info) tuples."""
    patterns = []
    i = 0
    while i < len(lines):
        # Look for the sign correction line which is the most unique marker
        line = lines[i].strip()
        m = re.match(r'if \(\(int\)-\(unsigned int\)\(\(int\)(\w+) < 0\) < 0\) \{', line)
        if not m:
            i += 1
            continue

        xor_var = m.group(1)
        sign_correct_line = i

        # Find the end of the sign correction block (closing brace)
        # Pattern:
        #   if ((int)-(unsigned int)((int)<xor> < 0) < 0) {
        #     <hi> = ~<hi>;
        #     if (<lo> == 0) {
        #       <hi> = <hi> + 1;
        #     }
        #     else {
        #       <lo> = ~<lo> + 1;
        #     }
        #   }
        # That's 9 lines from the if to the closing }

        # Find hi and lo variables from the sign correction block
        hi_var = None
        lo_var = None

        if sign_correct_line + 1 < len(lines):
            m2 = re.match(r'\s*(\w+) = ~(\w+);', lines[sign_correct_line + 1].strip())
            if m2:
                hi_var = m2.group(1)

        if sign_correct_line + 2 < len(lines):
            m3 = re.match(r'\s*if \((\w+) == 0\) \{', lines[sign_correct_line + 2].strip())
            if m3:
                lo_var = m3.group(1)

        if not hi_var or not lo_var:
            i += 1
            continue

        # Find the end of the sign correction block
        end_line = sign_correct_line
        brace_depth = 0
        for j in range(sign_correct_line, min(sign_correct_line + 12, len(lines))):
            for ch in lines[j]:
                if ch == '{':
                    brace_depth += 1
                elif ch == '}':
                    brace_depth -= 1
                    if brace_depth == 0:
                        end_line = j
                        break
            if brace_depth == 0 and end_line > sign_correct_line:
                break

        if end_line == sign_correct_line:
            i += 1
            continue

        # Now search backwards to find the XOR line: <xor_var> = <a> ^ <b>;
        xor_line = None
        a_orig = None
        b_orig = None
        a_var = None
        b_var = None

        for j in range(sign_correct_line - 1, max(sign_correct_line - 25, -1), -1):
            stripped = lines[j].strip()
            m4 = re.match(r'(\w+) = (.+?) \^ (.+?);$', stripped)
            if m4 and m4.group(1) == xor_var:
                xor_line = j
                a_orig = m4.group(2).strip()
                b_orig = m4.group(3).strip()
                break

        if xor_line is None:
            i += 1
            continue

        # Find the abs() lines after the XOR to identify which vars get modified
        # Pattern: if ((int)<a> < 0) { <a> = -<a>; }
        abs_a_line = None
        abs_b_line = None

        for j in range(xor_line + 1, min(xor_line + 5, len(lines))):
            stripped = lines[j].strip()
            m5 = re.match(r'if \(\(int\)(\w+) < 0\) \{', stripped)
            if m5:
                if abs_a_line is None:
                    abs_a_line = j
                    a_var = m5.group(1)
                else:
                    abs_b_line = j
                    b_var = m5.group(1)
                    break

        if abs_a_line is None or abs_b_line is None:
            i += 1
            continue

        # Verify: the abs lines should modify variables that were used in the XOR
        # a_orig and b_orig might be complex expressions; a_var and b_var are the
        # simple variable names that get abs'd

        # The start of the pattern is the XOR line
        start_line = xor_line

        # Get the indentation from the XOR line
        indent_match = re.match(r'^(\s*)', lines[xor_line])
        indent = indent_match.group(1) if indent_match else '    '

        patterns.append({
            'start': start_line,
            'end': end_line,
            'xor_var': xor_var,
            'a_orig': a_orig,
            'b_orig': b_orig,
            'a_var': a_var,
            'b_var': b_var,
            'hi_var': hi_var,
            'lo_var': lo_var,
            'indent': indent,
        })

        i = end_line + 1

    return patterns


def generate_replacement(info, counter):
    """Generate the replacement code for a dmuls pattern."""
    indent = info['indent']
    a = info['a_orig']
    b = info['b_orig']
    hi = info['hi_var']
    lo = info['lo_var']

    # Use a unique temp variable name
    tmp = '_m%d' % counter

    # Generate compact replacement
    replacement = [
        '%s{ long long %s = (long long)(int)%s * (int)%s;' % (indent, tmp, a, b),
        '%s  %s = (unsigned int)((unsigned long long)%s >> 32);' % (indent, hi, tmp),
        '%s  %s = (unsigned int)%s; }' % (indent, lo, tmp),
    ]

    return replacement


def process_file(filepath, dry_run=False):
    """Process a C file, replacing dmuls patterns."""
    global _mul_counter

    with open(filepath, 'r') as f:
        lines = f.readlines()

    # Strip line endings for processing
    lines = [line.rstrip('\n').rstrip('\r') for line in lines]

    patterns = find_dmuls_patterns(lines)

    if not patterns:
        print("  No patterns found in %s" % filepath)
        return 0

    print("  Found %d dmuls patterns in %s" % (len(patterns), filepath))

    # Process patterns in reverse order to preserve line numbers
    replacements_made = 0
    for info in reversed(patterns):
        start = info['start']
        end = info['end']

        replacement = generate_replacement(info, _mul_counter)
        _mul_counter += 1

        # Replace lines[start:end+1] with replacement
        lines[start:end+1] = replacement
        replacements_made += 1

    if not dry_run:
        with open(filepath, 'w', newline='\n') as f:
            for line in lines:
                f.write(line + '\n')

    original_count = sum(1 for p in patterns for _ in range(p['end'] - p['start'] + 1))
    new_count = len(patterns) * 3
    print("  Replaced %d patterns: %d lines -> %d lines (saved %d lines)" % (
        replacements_made, original_count, new_count, original_count - new_count))

    return replacements_made


def main():
    if len(sys.argv) < 2:
        print("Usage: %s <file.c> [--dry-run]" % sys.argv[0])
        print("  Replaces Ghidra dmuls.l emulation with proper C multiply.")
        sys.exit(1)

    filepath = sys.argv[1]
    dry_run = '--dry-run' in sys.argv

    if dry_run:
        print("DRY RUN - no files will be modified")

    count = process_file(filepath, dry_run)

    if count > 0:
        print("\nDone: %d replacements" % count)
    else:
        print("\nNo replacements made")


if __name__ == '__main__':
    main()
