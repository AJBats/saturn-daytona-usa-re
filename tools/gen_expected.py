#!/usr/bin/env python3
"""
gen_expected.py - Extract expected opcode mnemonics from SH-2 disassembly.

Parses build/aprog.s to extract instruction mnemonics for each function,
writing one-mnemonic-per-line .expected files into tests/.

Usage:
    python gen_expected.py                  # Generate all .expected files
    python gen_expected.py FUN_06035C4E     # Generate one specific function
    python gen_expected.py --list           # List all functions with instruction counts
    python gen_expected.py --check          # Compare generated vs existing .expected files
    python gen_expected.py --force          # Overwrite existing .expected files
    python gen_expected.py --ghidra         # Generate .expected files from Ghidra decomp
    python gen_expected.py --ghidra --force # Ghidra mode, overwrite existing files

The script finds functions two ways:
  1. From build/aprog_syms.txt (ordered symbol table)
  2. From function header comments in build/aprog.s

The --ghidra mode uses ghidra_project/decomp_all.txt instead, which provides
explicit function addresses and sizes. This covers ~880 functions, including
~363 that are not in aprog_syms.txt. Ghidra size is used as the end boundary
instead of "next function start", giving precise function boundaries.

For each function, it extracts instructions from the function start address
until it encounters:
  - A .word entry after seeing rts + delay slot (constant pool data)
  - The start of the next function
"""

import os
import re
import sys


def get_project_root():
    """Return the project root directory (parent of tools/)."""
    script_dir = os.path.dirname(os.path.abspath(__file__))
    return os.path.dirname(script_dir)


def parse_syms(syms_path):
    """Parse aprog_syms.txt and return list of (name, address) sorted by address."""
    functions = []
    pattern = re.compile(r'^(FUN_[0-9A-Fa-f]+)\s*=\s*0x([0-9A-Fa-f]+)\s*;')
    with open(syms_path, 'r') as f:
        for line in f:
            line = line.replace('\r', '')
            m = pattern.match(line.strip())
            if m:
                name = m.group(1)
                addr = int(m.group(2), 16)
                functions.append((name, addr))
    functions.sort(key=lambda x: x[1])
    return functions


def parse_asm_functions(asm_path):
    """Parse aprog.s function headers and return list of (name, address) sorted by address."""
    functions = []
    # Match: /* FUN_XXXXXXXX  (0xXXXXXXXX)  */
    pattern = re.compile(r'/\*\s+(FUN_([0-9A-Fa-f]+))\s+\(0x[0-9A-Fa-f]+\)')
    with open(asm_path, 'r') as f:
        for line in f:
            line = line.replace('\r', '')
            m = pattern.search(line)
            if m:
                name = m.group(1)
                addr = int(m.group(2), 16)
                functions.append((name, addr))
    functions.sort(key=lambda x: x[1])
    return functions


def parse_ghidra_funcs(decomp_path):
    """Parse Ghidra decomp_all.txt for function addresses and sizes.

    Looks for header lines like:
        FUNC FUN_06012e7c  addr=0x06012e7c  size=8  insns=4  type=LEAF

    Returns dict: uppercase_name -> {'addr': int, 'size': int, 'insns': int, 'type': str}
    """
    functions = {}
    header_re = re.compile(
        r'^FUNC\s+(\S+)\s+addr=(0x[0-9a-fA-F]+)\s+size=(\d+)\s+insns=(\d+)\s+type=(\S+)',
        re.MULTILINE
    )

    with open(decomp_path, 'r', encoding='utf-8', errors='replace') as f:
        text = f.read().replace('\r', '')

    for m in header_re.finditer(text):
        func_name = m.group(1)
        addr = int(m.group(2), 16)
        size = int(m.group(3))
        insns = int(m.group(4))
        func_type = m.group(5)

        # Normalize to uppercase for consistent file naming
        func_name_upper = func_name.upper()
        if not func_name_upper.startswith("FUN_"):
            func_name_upper = func_name

        functions[func_name_upper] = {
            'addr': addr,
            'size': size,
            'insns': insns,
            'type': func_type,
        }

    return functions


def normalize_mnemonic(mnemonic):
    """Normalize instruction mnemonic: bf/s -> bf.s, bt/s -> bt.s."""
    mnemonic = mnemonic.replace('bf/s', 'bf.s')
    mnemonic = mnemonic.replace('bt/s', 'bt.s')
    return mnemonic


def parse_instructions(asm_path):
    """Parse aprog.s and return dict of address -> (mnemonic, is_word, operands).

    Each entry maps a hex address to:
      - mnemonic: the instruction mnemonic
      - is_word: True if this is a .word constant pool entry
      - operands: the rest of the disassembly line after the mnemonic
    """
    instructions = {}

    # Match: .byte 0xNN, 0xNN  /* XXXXXXXX: MNEMONIC REST */
    # The address is 8 hex chars, followed by colon, then the mnemonic and operands
    pattern = re.compile(
        r'/\*\s*([0-9A-Fa-f]{8}):\s+'  # address
        r'(\S+)'                        # mnemonic (first non-space token)
        r'(.*?)\s*\*/'                  # operands (rest until closing comment)
    )

    with open(asm_path, 'r') as f:
        for line in f:
            line = line.replace('\r', '')
            m = pattern.search(line)
            if m:
                addr = int(m.group(1), 16)
                mnemonic = m.group(2)
                operands = m.group(3).strip()
                is_word = (mnemonic == '.word')
                if not is_word:
                    mnemonic = normalize_mnemonic(mnemonic)
                instructions[addr] = (mnemonic, is_word, operands)

    return instructions


# Mnemonics that are "terminal" -- after seeing one of these + delay slot,
# the function code ends (remaining bytes are constant pool or next function).
TERMINAL_MNEMONICS = {'rts', 'jmp', 'bra'}

# Branch/jump mnemonics whose operand is a branch target address
BRANCH_MNEMONICS = {
    'bt', 'bf', 'bt.s', 'bf.s',
    'bra', 'bsr',
}


def collect_branch_targets(instructions, start_addr, end_addr):
    """Collect all branch target addresses within a function's address range.

    Scans instructions from start_addr to end_addr, looking for branch
    instructions and extracting their target addresses. Returns a set of
    target addresses that are within [start_addr, end_addr).
    """
    targets = set()
    branch_target_re = re.compile(r'0x([0-9A-Fa-f]+)')

    addr = start_addr
    while addr < end_addr:
        if addr not in instructions:
            addr += 2
            continue
        mnemonic, is_word, operands = instructions[addr]
        if not is_word and mnemonic in BRANCH_MNEMONICS:
            m = branch_target_re.search(operands)
            if m:
                target = int(m.group(1), 16)
                if start_addr <= target < end_addr:
                    targets.add(target)
        addr += 2

    return targets


def extract_function_opcodes(instructions, start_addr, end_addr):
    """Extract opcode mnemonics for a function from start_addr to end_addr.

    Uses a two-pass approach:
    1. First pass: collect all branch targets within the function range to
       determine which addresses after a terminal instruction are reachable.
    2. Second pass: extract instructions, stopping after rts/jmp/bra + delay
       slot when no remaining branch targets point beyond that position.

    This correctly handles:
    - Simple functions: rts + delay slot, then constant pool data
    - Functions with conditional returns: bt/bf jumps past rts, code continues
    - Embedded functions: stop at first rts + delay slot

    Returns list of mnemonic strings.
    """
    # Pass 1: Collect branch targets to determine code extent.
    # We do a preliminary scan looking for branches. We need to be careful:
    # constant pool data can look like instructions. We use a conservative
    # approach -- scan until we see rts+delay with no forward branch targets.
    #
    # We iteratively expand the scan range: start with scanning until the
    # first rts+delay, then if branches target beyond that, expand.
    branch_targets = set()
    branch_target_re = re.compile(r'0x([0-9A-Fa-f]+)')

    # Determine the code extent by tracking terminal instructions and
    # forward branch targets
    code_end = start_addr  # will be updated as we find more code
    addr = start_addr
    pending_delay = False
    found_terminal = False

    while addr < end_addr:
        if addr not in instructions:
            if found_terminal and not pending_delay:
                break
            addr += 2
            continue

        mnemonic, is_word, operands = instructions[addr]

        if is_word:
            if found_terminal and not pending_delay:
                break
            # .word before any terminal -- could be alignment. Stop scanning.
            if not found_terminal:
                addr += 2
                continue
            break

        # This is a real instruction (non-.word)
        # Extract branch targets
        if mnemonic in BRANCH_MNEMONICS:
            m = branch_target_re.search(operands)
            if m:
                target = int(m.group(1), 16)
                if target >= start_addr and target < end_addr:
                    branch_targets.add(target)

        if pending_delay:
            pending_delay = False
            code_end = addr + 2  # include delay slot

            # Check if any branch target points beyond our current position
            has_forward_target = any(t > addr for t in branch_targets)
            if not has_forward_target:
                # No forward branches -- function ends here
                break
            else:
                # There are forward branches -- continue scanning
                found_terminal = False
                addr += 2
                continue

        if mnemonic in TERMINAL_MNEMONICS:
            found_terminal = True
            pending_delay = True

        addr += 2

    if not found_terminal:
        # Never found a terminal -- use entire range up to end_addr
        code_end = end_addr

    # Pass 2: Extract opcodes from start_addr to code_end
    opcodes = []
    addr = start_addr
    while addr < code_end:
        if addr not in instructions:
            addr += 2
            continue
        mnemonic, is_word, operands = instructions[addr]
        if is_word:
            # Skip .word entries within the code range
            addr += 2
            continue
        opcodes.append(mnemonic)
        addr += 2

    return opcodes


def build_function_map(sym_funcs, asm_funcs):
    """Merge function lists from sym table and asm headers, sorted by address.

    Returns a list of (name, address) with duplicates removed, sorted by address.
    Also returns a dict of name -> address for quick lookup.
    """
    seen_addrs = {}
    for name, addr in sym_funcs:
        if addr not in seen_addrs:
            seen_addrs[addr] = name
    for name, addr in asm_funcs:
        if addr not in seen_addrs:
            seen_addrs[addr] = name

    all_funcs = [(name, addr) for addr, name in seen_addrs.items()]
    all_funcs.sort(key=lambda x: x[1])

    name_to_addr = {name: addr for name, addr in all_funcs}
    return all_funcs, name_to_addr


def get_end_addr(all_funcs, idx):
    """Get the end address for function at index idx.

    The end address is the start of the next function (exclusive).
    For the last function, use a large upper bound.
    """
    if idx + 1 < len(all_funcs):
        return all_funcs[idx + 1][1]
    # Last function -- use a generous upper bound
    return all_funcs[idx][1] + 0x10000


def generate_expected(func_name, start_addr, end_addr, instructions):
    """Generate the list of opcode mnemonics for a function."""
    return extract_function_opcodes(instructions, start_addr, end_addr)


def write_expected_file(tests_dir, func_name, opcodes, force=False):
    """Write a .expected file. Returns status string."""
    filepath = os.path.join(tests_dir, func_name + '.expected')
    content = '\n'.join(opcodes) + '\n'

    if os.path.exists(filepath) and not force:
        # Check if existing content matches (normalize bf/s -> bf.s, bt/s -> bt.s)
        with open(filepath, 'r') as f:
            existing = f.read().replace('\r', '')
        existing_normalized = existing.replace('bf/s', 'bf.s').replace('bt/s', 'bt.s')
        if existing_normalized == content:
            return 'matched'
        else:
            return 'skipped (exists, use --force to overwrite)'

    with open(filepath, 'w', newline='\n') as f:
        f.write(content)
    return 'created'


def main():
    project_root = get_project_root()
    syms_path = os.path.join(project_root, 'build', 'aprog_syms.txt')
    asm_path = os.path.join(project_root, 'build', 'aprog.s')
    tests_dir = os.path.join(project_root, 'tests')

    # Parse arguments
    force = '--force' in sys.argv
    list_mode = '--list' in sys.argv
    check_mode = '--check' in sys.argv
    ghidra_mode = '--ghidra' in sys.argv

    # Collect specific function names (non-flag arguments)
    specific_funcs = []
    for arg in sys.argv[1:]:
        if not arg.startswith('-'):
            specific_funcs.append(arg)

    # Ensure tests directory exists
    os.makedirs(tests_dir, exist_ok=True)

    # --ghidra mode: generate .expected files from Ghidra decomp_all.txt
    if ghidra_mode:
        decomp_path = os.path.join(project_root, 'ghidra_project', 'decomp_all.txt')
        if not os.path.exists(decomp_path):
            print(f'ERROR: Ghidra decompilation file not found: {decomp_path}')
            sys.exit(1)

        print('Parsing Ghidra decompilation file...')
        ghidra_funcs = parse_ghidra_funcs(decomp_path)
        print(f'  Found {len(ghidra_funcs)} functions in decomp_all.txt')

        print('Parsing instructions from aprog.s...')
        instructions = parse_instructions(asm_path)
        print(f'  Found {len(instructions)} instruction entries')

        # Count how many already have .expected files
        existing_expected = set()
        if os.path.isdir(tests_dir):
            for fname in os.listdir(tests_dir):
                if fname.endswith('.expected'):
                    existing_expected.add(fname[:-len('.expected')])

        # Filter to only functions that need .expected files
        if specific_funcs:
            # If specific functions given with --ghidra, only process those
            targets = {}
            for name in specific_funcs:
                name_upper = name.upper()
                if name_upper in ghidra_funcs:
                    targets[name_upper] = ghidra_funcs[name_upper]
                elif name in ghidra_funcs:
                    targets[name] = ghidra_funcs[name]
                else:
                    print(f'  WARNING: {name} not found in decomp_all.txt')
        else:
            targets = ghidra_funcs

        # Sort by address for deterministic output
        sorted_targets = sorted(targets.items(), key=lambda x: x[1]['addr'])

        print(f'  {len(existing_expected)} existing .expected files in tests/')
        if not force:
            new_count = sum(1 for name, _ in sorted_targets
                           if name not in existing_expected)
            print(f'  {new_count} new .expected files to generate')
        print()

        created = 0
        skipped = 0
        matched = 0
        errors = 0

        for func_name, info in sorted_targets:
            start_addr = info['addr']
            end_addr = start_addr + info['size']
            opcodes = extract_function_opcodes(instructions, start_addr, end_addr)

            if not opcodes:
                errors += 1
                continue

            status = write_expected_file(tests_dir, func_name, opcodes, force=force)

            if status == 'created':
                created += 1
            elif status == 'matched':
                matched += 1
            elif 'skipped' in status:
                skipped += 1

        print(f'Ghidra mode summary:')
        print(f'  {created} created, {matched} matched, '
              f'{skipped} skipped (existing), {errors} empty/errors')
        print(f'  Total functions processed: {len(sorted_targets)}')
        return

    print('Parsing symbol table...')
    sym_funcs = parse_syms(syms_path)
    print(f'  Found {len(sym_funcs)} symbols in aprog_syms.txt')

    print('Parsing assembly function headers...')
    asm_funcs = parse_asm_functions(asm_path)
    print(f'  Found {len(asm_funcs)} function headers in aprog.s')

    all_funcs, name_to_addr = build_function_map(sym_funcs, asm_funcs)
    print(f'  Total unique functions: {len(all_funcs)}')

    print('Parsing instructions from aprog.s...')
    instructions = parse_instructions(asm_path)
    print(f'  Found {len(instructions)} instruction entries')
    print()

    # If specific functions requested that aren't in the map, try to parse
    # the address from the function name itself (FUN_XXXXXXXX format)
    if specific_funcs:
        for func_name in specific_funcs:
            if func_name not in name_to_addr:
                # Try to extract address from the name
                m = re.match(r'FUN_([0-9A-Fa-f]+)', func_name)
                if m:
                    addr = int(m.group(1), 16)
                    name_to_addr[func_name] = addr
                    # Insert into all_funcs in sorted order
                    all_funcs.append((func_name, addr))
                    all_funcs.sort(key=lambda x: x[1])
                    print(f'  Note: {func_name} not in symbol table, using address 0x{addr:08X}')
                else:
                    print(f'  ERROR: {func_name} not found and cannot parse address from name')
                    sys.exit(1)

    # Build index for quick lookup
    func_index = {name: i for i, (name, _) in enumerate(all_funcs)}

    # Determine which functions to process
    if specific_funcs:
        targets = [(name, name_to_addr[name]) for name in specific_funcs]
    else:
        targets = all_funcs

    # Process functions
    if list_mode:
        print(f'{"Function":<20s}  {"Address":>10s}  {"Insns":>5s}')
        print('-' * 40)
        for name, addr in targets:
            idx = func_index[name]
            end = get_end_addr(all_funcs, idx)
            opcodes = generate_expected(name, addr, end, instructions)
            print(f'{name:<20s}  0x{addr:08X}  {len(opcodes):5d}')
        return

    if check_mode:
        # Find ALL existing .expected files, including embedded functions.
        # For embedded functions, we create a SEPARATE function list that
        # includes only that embedded function (so it doesn't change the
        # boundaries of formal functions).
        check_targets = []
        embedded_funcs = []
        for fname in sorted(os.listdir(tests_dir)):
            if fname.endswith('.expected'):
                func_name = fname[:-len('.expected')]
                m = re.match(r'FUN_([0-9A-Fa-f]+)', func_name)
                if m:
                    addr = int(m.group(1), 16)
                    check_targets.append((func_name, addr))
                    if func_name not in name_to_addr:
                        embedded_funcs.append((func_name, addr))

        matches = 0
        mismatches = 0
        for name, addr in check_targets:
            filepath = os.path.join(tests_dir, name + '.expected')

            if name in name_to_addr:
                # Formal function -- use existing boundaries
                idx = func_index[name]
                end = get_end_addr(all_funcs, idx)
            else:
                # Embedded function -- create a temporary list with just
                # this function inserted, to determine its end boundary
                temp_funcs = list(all_funcs) + [(name, addr)]
                temp_funcs.sort(key=lambda x: x[1])
                temp_idx = next(i for i, (n, _) in enumerate(temp_funcs) if n == name)
                if temp_idx + 1 < len(temp_funcs):
                    end = temp_funcs[temp_idx + 1][1]
                else:
                    end = addr + 0x10000

            opcodes = generate_expected(name, addr, end, instructions)
            generated = '\n'.join(opcodes) + '\n'

            with open(filepath, 'r') as f:
                existing = f.read().replace('\r', '')
            # Normalize bf/s -> bf.s, bt/s -> bt.s (same as test harness)
            existing = existing.replace('bf/s', 'bf.s').replace('bt/s', 'bt.s')

            if existing == generated:
                matches += 1
                print(f'  OK     {name}  ({len(opcodes)} insns)')
            else:
                mismatches += 1
                # Show the difference
                existing_lines = existing.strip().split('\n')
                generated_lines = [o for o in opcodes]
                print(f'  DIFF   {name}  (existing={len(existing_lines)} generated={len(generated_lines)})')
                # Show first few differences
                max_lines = max(len(existing_lines), len(generated_lines))
                diffs_shown = 0
                for i in range(min(max_lines, 50)):
                    e = existing_lines[i] if i < len(existing_lines) else '<missing>'
                    g = generated_lines[i] if i < len(generated_lines) else '<missing>'
                    if e != g:
                        print(f'         line {i+1}: existing="{e}" generated="{g}"')
                        diffs_shown += 1
                        if diffs_shown >= 5:
                            break

        print()
        print(f'Checked {len(check_targets)} existing .expected files:')
        print(f'  {matches} match, {mismatches} mismatch')
        return

    # Generate mode
    created = 0
    skipped = 0
    matched = 0
    errors = 0

    for name, addr in targets:
        idx = func_index[name]
        end = get_end_addr(all_funcs, idx)
        opcodes = generate_expected(name, addr, end, instructions)

        if not opcodes:
            if specific_funcs:
                print(f'WARNING  {name}  (no instructions found at 0x{addr:08X})')
            errors += 1
            continue

        status = write_expected_file(tests_dir, name, opcodes, force=force)

        if status == 'created':
            created += 1
            if specific_funcs or len(targets) <= 30:
                print(f'CREATED  {name}  ({len(opcodes)} insns)')
        elif status == 'matched':
            matched += 1
            if specific_funcs or len(targets) <= 30:
                print(f'MATCHED  {name}  ({len(opcodes)} insns)')
        elif 'skipped' in status:
            skipped += 1
            if specific_funcs or len(targets) <= 30:
                print(f'SKIPPED  {name}  ({len(opcodes)} insns, {status})')
        else:
            print(f'{status}  {name}  ({len(opcodes)} insns)')

    if not specific_funcs:
        print()
        print(f'Summary: {created} created, {matched} matched, '
              f'{skipped} skipped, {errors} empty/errors')
        print(f'Total functions processed: {len(targets)}')

    # For single-function mode, also print the opcodes
    if len(specific_funcs) == 1:
        name = specific_funcs[0]
        addr = name_to_addr[name]
        idx = func_index[name]
        end = get_end_addr(all_funcs, idx)
        opcodes = generate_expected(name, addr, end, instructions)
        print()
        print(f'Opcodes for {name} (0x{addr:08X}):')
        for i, op in enumerate(opcodes):
            print(f'  {i+1:3d}: {op}')


if __name__ == '__main__':
    main()
