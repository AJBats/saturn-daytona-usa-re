#!/usr/bin/env python3
"""
Add global labels for sub-entry points within ASM-imported functions.

Ghidra splits large original binary functions into multiple C "functions"
at internal label offsets, inlining the shared body into each. Since the
original binary functions are already imported as ASM (.word sequences),
we can add global labels at the correct byte offsets and remove the
bloated C duplicates.

This tool modifies asm_rendering.c to insert .global labels at specified
byte offsets within existing ASM function blocks.
"""

import re
import sys

# Sub-entry points to add: parent_label -> [(child_label, byte_offset), ...]
ENTRIES = {
    'FUN_06029740': [
        ('FUN_0602a134', 0x9F4),
        ('FUN_0602a214', 0xAD4),
        ('FUN_0602a754', 0x1014),
        ('FUN_0602a834', 0x10F4),
    ],
    'FUN_0602A840': [
        ('FUN_0602aaa0', 0x260),
        ('FUN_0602ab00', 0x2C0),
        ('FUN_0602ab3a', 0x2FA),
        ('FUN_0602abb8', 0x378),
    ],
    'FUN_0602ABC4': [
        ('FUN_0602ae24', 0x260),
        ('FUN_0602ae84', 0x2C0),
        ('FUN_0602aebe', 0x2FA),
        ('FUN_0602af3c', 0x378),
    ],
    'FUN_0602AF48': [
        ('FUN_0602b1d6', 0x28E),
        ('FUN_0602b258', 0x310),
        ('FUN_0602b298', 0x350),
        ('FUN_0602b328', 0x3E0),
    ],
    'FUN_0602B334': [
        ('FUN_0602b546', 0x212),
        ('FUN_0602b55a', 0x226),
        ('FUN_0602b55e', 0x22A),
        ('FUN_0602b572', 0x23E),
        ('FUN_0602b58e', 0x25A),
        ('FUN_0602b5a2', 0x26E),
        ('FUN_0602b5be', 0x28A),
        ('FUN_0602b5ce', 0x29A),
        ('FUN_0602b5d2', 0x29E),
        ('FUN_0602b8dc', 0x5A8),
        ('FUN_0602b9e0', 0x6AC),
    ],
    'FUN_0602B9EC': [
        ('FUN_0602bc7a', 0x28E),
        ('FUN_0602bcfc', 0x310),
        ('FUN_0602bd3c', 0x350),
        ('FUN_0602bdcc', 0x3E0),
    ],
    'FUN_0602BDD8': [
        ('FUN_0602c380', 0x5A8),
    ],
}


def process_file(filepath, dry_run=False):
    with open(filepath, 'r') as f:
        lines = f.readlines()

    total_labels_added = 0
    new_lines = []
    i = 0

    while i < len(lines):
        line = lines[i]

        # Check if this line is a parent function label
        parent_found = None
        for parent_label in ENTRIES:
            # Match the label line: '    "_FUN_XXXXXXXX:\n"'
            if ('_%s:\\n"' % parent_label) in line:
                parent_found = parent_label
                break

        if parent_found is None:
            new_lines.append(line)
            i += 1
            continue

        # Found a parent function label. Now we need to insert sub-entry labels
        # at the correct byte offsets within the .word sequence.
        entries = sorted(ENTRIES[parent_found], key=lambda x: x[1])

        # Build a map of word_index -> labels to insert BEFORE that word
        label_map = {}
        for child_label, byte_offset in entries:
            word_index = byte_offset // 2
            if word_index not in label_map:
                label_map[word_index] = []
            label_map[word_index].append(child_label)

        # Output the label line
        new_lines.append(line)
        i += 1

        # Now process .word lines, counting words
        word_count = 0
        while i < len(lines):
            wline = lines[i]

            # Check if this is a .word line
            if '".word ' in wline:
                # Check if we need to insert labels before this word
                if word_count in label_map:
                    for child_label in label_map[word_count]:
                        # Get the indentation from the current line
                        indent_match = re.match(r'^(\s*)', wline)
                        indent = indent_match.group(1) if indent_match else '    '
                        new_lines.append('%s".global _%s\\n"\n' % (indent, child_label))
                        new_lines.append('%s"_%s:\\n"\n' % (indent, child_label))
                        total_labels_added += 1
                        print("  Added label _%s at offset 0x%X (word %d) in %s" % (
                            child_label, word_count * 2, word_count, parent_found))

                new_lines.append(wline)
                word_count += 1
                i += 1
            elif '.size' in wline:
                # End of function block - output and break
                new_lines.append(wline)
                i += 1
                break
            else:
                # Other directive or line - just output
                new_lines.append(wline)
                i += 1

        # Verify all labels were placed
        for child_label, byte_offset in entries:
            expected_word = byte_offset // 2
            if expected_word >= word_count:
                print("  WARNING: offset 0x%X for %s exceeds function size (%d words = 0x%X bytes)" % (
                    byte_offset, child_label, word_count, word_count * 2))

    if not dry_run and total_labels_added > 0:
        with open(filepath, 'w', newline='\n') as f:
            f.writelines(new_lines)

    return total_labels_added


def main():
    if len(sys.argv) < 2:
        print("Usage: %s <asm_rendering.c> [--dry-run]" % sys.argv[0])
        sys.exit(1)

    filepath = sys.argv[1]
    dry_run = '--dry-run' in sys.argv

    if dry_run:
        print("DRY RUN - no files will be modified")

    count = process_file(filepath, dry_run)
    print("\nDone: %d labels added" % count)


if __name__ == '__main__':
    main()
