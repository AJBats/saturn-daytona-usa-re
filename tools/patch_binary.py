#!/usr/bin/env python3
"""
Patch compiled test functions into APROG.BIN and optionally into the disc ISO.

Workflow:
  1. For each function: compile C → assemble → link at correct address → extract bytes
  2. Compare against original bytes (report match level)
  3. Patch into a copy of APROG.BIN
  4. Optionally patch the ISO disc image

Usage:
  python3 patch_binary.py                    # Dry run: show what would be patched
  python3 patch_binary.py --patch            # Patch APROG.BIN and ISO
  python3 patch_binary.py --patch --unsafe   # Also patch L1-only matches (register diffs)
  python3 patch_binary.py FUN_0600D266       # Single function detail view
"""

import subprocess
import struct
import os
import sys
import re
import shutil
import tempfile
import argparse

PROJDIR = '/mnt/d/Projects/SaturnReverseTest'
CC1 = f'{PROJDIR}/tools/gcc26-build/cc1'
SH_AS = f'{PROJDIR}/tools/sh-elf/bin/sh-elf-as'
SH_LD = f'{PROJDIR}/tools/sh-elf/bin/sh-elf-ld'
SH_OBJCOPY = f'{PROJDIR}/tools/sh-elf/bin/sh-elf-objcopy'
SH_OBJDUMP = f'{PROJDIR}/tools/sh-elf/bin/sh-elf-objdump'
ORIG_BIN = f'{PROJDIR}/build/disc/files/APROG.BIN'
SYMFILE = f'{PROJDIR}/build/aprog_syms.txt'
TESTDIR = f'{PROJDIR}/tests'
OUTPUT_BIN = f'{PROJDIR}/build/aprog_patched.bin'
ORIG_ISO = f'{PROJDIR}/build/disc/daytona_data.iso'
OUTPUT_ISO = f'{PROJDIR}/build/disc/daytona_patched.iso'
BASE_ADDR = 0x06003000
ISO_APROG_OFFSET = 0xA800  # Byte offset of APROG.BIN in ISO


def load_symbols():
    """Load function addresses from symbol file, return sorted list of (name, addr)."""
    syms = []
    with open(SYMFILE, 'r') as f:
        for line in f:
            line = line.strip().replace('\r', '')
            m = re.match(r'(FUN_[0-9A-Fa-f]+)\s*=\s*(0x[0-9A-Fa-f]+);', line)
            if m:
                syms.append((m.group(1), int(m.group(2), 16)))
    syms.sort(key=lambda x: x[1])
    return syms


def get_func_addr(func_name):
    """Extract function address from name like FUN_0600D266."""
    m = re.match(r'FUN_([0-9A-Fa-f]+)', func_name)
    if m:
        return int(m.group(1), 16)
    return None


def get_func_size(all_addrs, func_addr):
    """Get function slot size (bytes until next known boundary)."""
    for a in all_addrs:
        if a > func_addr:
            return a - func_addr
    return None


def get_flags_for_func(func_name):
    """Read per-function compiler flags from .flags file, or return defaults."""
    flags_file = os.path.join(TESTDIR, f'{func_name}.flags')
    if os.path.exists(flags_file):
        with open(flags_file, 'r') as f:
            return f.read().strip().replace('\r', '').split()
    return ['-O2', '-m2', '-mbsr']


def extract_extern_symbols(s_file):
    """Extract external symbol references from .s file."""
    symbols = {}
    with open(s_file, 'r') as f:
        content = f.read()

    for m in re.finditer(r'\.long\s+(_\w+)', content):
        sym = m.group(1)
        addr_match = re.search(r'_.*?([0-9a-fA-F]{6,8})$', sym)
        if addr_match:
            addr = int(addr_match.group(1), 16)
            if addr >= 0x06000000 or addr >= 0x002A0000:
                symbols[sym] = addr

    for m in re.finditer(r'(?:bra|bsr)\s+(_\w+)', content):
        sym = m.group(1)
        addr_match = re.search(r'_.*?([0-9a-fA-F]{6,8})$', sym)
        if addr_match:
            addr = int(addr_match.group(1), 16)
            if addr >= 0x06000000 or addr >= 0x002A0000:
                symbols[sym] = addr

    return symbols


def preprocess_bsr_bra(s_file):
    """Replace external BSR/BRA with local stubs (assembler can't relocate these)."""
    with open(s_file, 'r') as f:
        content = f.read()

    local_labels = set(re.findall(r'^(\w+):', content, re.MULTILINE))

    ext_refs = set()
    for m in re.finditer(r'\t(bsr|bra)\t(_\w+)', content):
        sym = m.group(2)
        if sym not in local_labels:
            ext_refs.add(sym)

    if not ext_refs:
        return False

    for sym in sorted(ext_refs):
        stub = '.Lstub' + sym
        content = content.replace(f'\tbsr\t{sym}', f'\tbsr\t{stub}')
        content = content.replace(f'\tbra\t{sym}', f'\tbra\t{stub}')

    stub_defs = '\n'.join(f'.Lstub{sym}:' for sym in sorted(ext_refs))
    content = re.sub(
        r'(\t\.align\s+\d+\n)',
        rf'\1{stub_defs}\n',
        content,
        count=1
    )

    with open(s_file, 'w') as f:
        f.write(content)
    return True


def compile_function(func_name, func_addr, tmpdir):
    """Compile, assemble, link a function. Returns (bytes, insn_count, pool_bytes, error)."""
    c_file = os.path.join(TESTDIR, f'{func_name}.c')
    if not os.path.exists(c_file):
        return None, 0, None, f'no C source'

    # Strip CRLF
    src = open(c_file, 'rb').read().replace(b'\r\n', b'\n')
    clean_c = os.path.join(tmpdir, 'test.c')
    open(clean_c, 'wb').write(src)

    # Get flags
    flags = get_flags_for_func(func_name)

    # Compile
    s_file = os.path.join(tmpdir, 'test.s')
    result = subprocess.run(
        [CC1, '-quiet'] + flags + [clean_c, '-o', s_file],
        capture_output=True, text=True
    )
    if result.returncode != 0:
        return None, 0, None, f'compile error: {result.stderr[:200]}'

    # Count instructions
    insn_count = 0
    with open(s_file, 'r') as f:
        for line in f:
            if re.match(r'^\t[a-z]', line):
                insn_count += 1

    # Extract extern symbols and preprocess BSR/BRA
    ext_syms = extract_extern_symbols(s_file)
    preprocess_bsr_bra(s_file)

    # Generate linker script
    ld_script = os.path.join(tmpdir, 'link.ld')
    with open(ld_script, 'w') as f:
        f.write(f"SECTIONS {{\n")
        f.write(f"  .text 0x{func_addr:08X} : {{ *(.text) *(.rodata) }}\n")
        f.write(f"}}\n")
        for sym, addr in ext_syms.items():
            f.write(f"{sym} = 0x{addr:08X};\n")

    # Assemble
    o_file = os.path.join(tmpdir, 'test.o')
    result = subprocess.run(
        [SH_AS, '--big', '-o', o_file, s_file],
        capture_output=True, text=True
    )
    if result.returncode != 0:
        return None, insn_count, None, f'assemble error: {result.stderr[:200]}'

    # Link
    elf_file = os.path.join(tmpdir, 'test.elf')
    result = subprocess.run(
        [SH_LD, '-T', ld_script, '-o', elf_file, o_file],
        capture_output=True, text=True
    )
    if result.returncode != 0:
        return None, insn_count, None, f'link error: {result.stderr[:200]}'

    # Extract binary
    bin_file = os.path.join(tmpdir, 'test.bin')
    subprocess.run(
        [SH_OBJCOPY, '-O', 'binary', '-j', '.text', elf_file, bin_file],
        capture_output=True
    )
    if not os.path.exists(bin_file):
        return None, insn_count, None, 'objcopy failed'

    func_bytes = open(bin_file, 'rb').read()

    # Split: instruction bytes vs pool constant bytes
    # Instructions are insn_count * 2 bytes, rest is pool constants
    code_size = insn_count * 2
    code_bytes = func_bytes[:code_size]
    pool_bytes = func_bytes[code_size:]

    return code_bytes, insn_count, pool_bytes, None


def classify_insn(word):
    """Classify SH-2 instruction, return (type, mask) for structural comparison."""
    top4 = (word >> 12) & 0xF
    if top4 == 0xD:
        return 'mov.l_pool', 0xFF00
    if top4 == 0x9:
        return 'mov.w_pool', 0xFF00
    if top4 == 0xA:
        return 'bra', 0xF000
    if top4 == 0xB:
        return 'bsr', 0xF000
    top8 = (word >> 8) & 0xFF
    if top8 in (0x8B, 0x89, 0x8F, 0x8D):
        return 'branch', 0xFF00
    return 'other', 0xFFFF


def compare_bytes(our_bytes, orig_bytes, insn_count):
    """Compare instruction bytes. Returns (level, details_str).
    level: 3=byte-perfect, 2=structural, 1=mnemonic-only, 0=different"""
    if len(our_bytes) < insn_count * 2 or len(orig_bytes) < insn_count * 2:
        return 0, 'size mismatch'

    full_match = 0
    struct_match = 0
    diffs = []

    for i in range(insn_count):
        off = i * 2
        our_w = struct.unpack('>H', our_bytes[off:off+2])[0]
        orig_w = struct.unpack('>H', orig_bytes[off:off+2])[0]
        _, mask = classify_insn(orig_w)

        if our_w == orig_w:
            full_match += 1
            struct_match += 1
        elif (our_w & mask) == (orig_w & mask):
            struct_match += 1
            diffs.append(f'  [{i}] disp: {our_w:04x} vs {orig_w:04x}')
        else:
            diffs.append(f'  [{i}] DIFF: {our_w:04x} vs {orig_w:04x}')

    if full_match == insn_count:
        return 3, f'byte-perfect ({insn_count} insns)'
    if struct_match == insn_count:
        disp_count = insn_count - full_match
        return 2, f'structural ({full_match}/{insn_count} exact, {disp_count} disp-only)'
    detail = f'{full_match}/{insn_count} exact, {struct_match}/{insn_count} structural'
    return 1 if struct_match > insn_count * 0.8 else 0, detail


def can_patch_with_disp_fix(our_bytes, orig_bytes, insn_count):
    """For L2 structural matches, create patched bytes using our code with original displacements.
    Returns fixed bytes or None."""
    if len(our_bytes) < insn_count * 2 or len(orig_bytes) < insn_count * 2:
        return None

    fixed = bytearray(our_bytes[:insn_count * 2])

    for i in range(insn_count):
        off = i * 2
        our_w = struct.unpack('>H', our_bytes[off:off+2])[0]
        orig_w = struct.unpack('>H', orig_bytes[off:off+2])[0]
        _, mask = classify_insn(orig_w)

        if our_w == orig_w:
            continue
        elif (our_w & mask) == (orig_w & mask):
            # Structural match — use original displacement bits
            fixed_w = (our_w & mask) | (orig_w & ~mask)
            struct.pack_into('>H', fixed, off, fixed_w)
        else:
            # Real difference — can't auto-fix
            return None

    return bytes(fixed)


def main():
    parser = argparse.ArgumentParser(description='Patch compiled functions into APROG.BIN')
    parser.add_argument('function', nargs='?', help='Single function to detail')
    parser.add_argument('--patch', action='store_true', help='Actually create patched files')
    parser.add_argument('--unsafe', action='store_true', help='Include L1-only matches')
    parser.add_argument('--level', type=int, default=2,
                        help='Minimum match level to patch (3=byte, 2=structural, 1=mnemonic)')
    args = parser.parse_args()

    syms = load_symbols()

    # Find test functions
    test_funcs = []
    for fname in sorted(os.listdir(TESTDIR)):
        if fname.endswith('.c'):
            base = fname[:-2]
            if os.path.exists(os.path.join(TESTDIR, f'{base}.expected')):
                test_funcs.append(base)

    if args.function:
        test_funcs = [args.function]

    # Build combined address list from syms + test function names
    all_addrs = sorted(set(
        [addr for _, addr in syms] +
        [get_func_addr(f) for f in test_funcs if get_func_addr(f) is not None]
    ))

    # Load original binary
    orig_data = open(ORIG_BIN, 'rb').read()
    patched_data = bytearray(orig_data)
    patch_count = 0
    total_bytes_patched = 0

    results = {'L3': [], 'L2': [], 'L1': [], 'DIFF': [], 'ERR': []}

    print("=" * 78)
    print("  APROG.BIN Function Patcher")
    print(f"  Original: {len(orig_data)} bytes")
    print(f"  Test functions: {len(test_funcs)}")
    print(f"  Mode: {'PATCH' if args.patch else 'DRY RUN'}")
    print("=" * 78)
    print()

    for func_name in test_funcs:
        func_addr = get_func_addr(func_name)
        if func_addr is None:
            print(f"  ERR   {func_name:20s}  cannot extract address")
            results['ERR'].append(func_name)
            continue

        slot_size = get_func_size(all_addrs, func_addr)
        if slot_size is None:
            slot_size = 256  # Fallback for last function

        # Compile function
        tmpdir = tempfile.mkdtemp(prefix='patch_')
        try:
            code_bytes, insn_count, pool_bytes, err = compile_function(
                func_name, func_addr, tmpdir)
        finally:
            shutil.rmtree(tmpdir, ignore_errors=True)

        if err:
            print(f"  ERR   {func_name:20s}  {err}")
            results['ERR'].append(func_name)
            continue

        # Get original bytes for this function region
        file_offset = func_addr - BASE_ADDR
        orig_func_bytes = orig_data[file_offset:file_offset + slot_size]

        # Compare instruction bytes
        level, detail = compare_bytes(code_bytes, orig_func_bytes, insn_count)

        total_compiled = len(code_bytes) + (len(pool_bytes) if pool_bytes else 0)
        size_info = f'code={len(code_bytes)} pool={len(pool_bytes) if pool_bytes else 0} slot={slot_size}'

        if level == 3:
            tag = 'L3'
            results['L3'].append(func_name)
        elif level == 2:
            tag = 'L2'
            results['L2'].append(func_name)
        elif level >= 1:
            tag = 'L1'
            results['L1'].append(func_name)
        else:
            tag = 'DIFF'
            results['DIFF'].append(func_name)

        patchable = ''
        if level == 3:
            # Byte perfect — check if code + pool fits in slot
            if total_compiled <= slot_size:
                patchable = ' [PATCHABLE]'
            else:
                patchable = f' [OVERFLOW: {total_compiled} > {slot_size}]'
        elif level == 2:
            # Try displacement fixup
            fixed = can_patch_with_disp_fix(code_bytes, orig_func_bytes, insn_count)
            if fixed:
                patchable = ' [PATCHABLE w/ disp fix]'
            else:
                patchable = ' [disp fix failed]'

        print(f"  {tag:5s} {func_name:20s}  {detail}  {size_info}{patchable}")

        # Actually patch if requested
        if args.patch and level >= args.level:
            if level == 3 and total_compiled <= slot_size:
                # Write our compiled output (code + pool constants)
                patch_region = code_bytes + pool_bytes
                # Pad with original bytes if our output is shorter
                if len(patch_region) < slot_size:
                    patch_region += orig_func_bytes[len(patch_region):]
                patched_data[file_offset:file_offset + len(patch_region)] = patch_region
                patch_count += 1
                total_bytes_patched += len(code_bytes)
            elif level == 2:
                fixed = can_patch_with_disp_fix(code_bytes, orig_func_bytes, insn_count)
                if fixed:
                    # Write fixed code bytes, keep original pool constants
                    patched_data[file_offset:file_offset + len(fixed)] = fixed
                    patch_count += 1
                    total_bytes_patched += len(fixed)

    print()
    print("=" * 78)
    print(f"  Summary:")
    print(f"    L3 Byte-perfect:  {len(results['L3']):3d}  ({', '.join(results['L3']) if results['L3'] else 'none'})")
    print(f"    L2 Structural:    {len(results['L2']):3d}")
    print(f"    L1 Mnemonic:      {len(results['L1']):3d}")
    print(f"    DIFF:             {len(results['DIFF']):3d}")
    print(f"    Errors:           {len(results['ERR']):3d}")

    if args.patch:
        print(f"\n  Patched: {patch_count} functions, {total_bytes_patched} bytes")

        # Verify patched binary
        if patched_data == bytearray(orig_data):
            print("  Result: IDENTICAL to original (all patches were no-ops)")
        else:
            diff_count = sum(1 for a, b in zip(patched_data, orig_data) if a != b)
            print(f"  Result: {diff_count} bytes differ from original")

        # Write patched APROG.BIN
        open(OUTPUT_BIN, 'wb').write(patched_data)
        print(f"  Written: {OUTPUT_BIN}")

        # Patch ISO
        if os.path.exists(ORIG_ISO):
            iso_data = bytearray(open(ORIG_ISO, 'rb').read())
            iso_data[ISO_APROG_OFFSET:ISO_APROG_OFFSET + len(patched_data)] = patched_data
            open(OUTPUT_ISO, 'wb').write(iso_data)
            print(f"  Written: {OUTPUT_ISO}")
        else:
            print(f"  ISO not found at {ORIG_ISO}, skipped")

    print("=" * 78)


if __name__ == '__main__':
    main()
