#!/usr/bin/env python3
"""
Binary-level comparison of compiled test functions against original binary.

Comparison levels:
  Level 1: Mnemonic only (like test_harness.sh)
  Level 2: Structural match (opcodes + registers, masking PC-relative displacements)
  Level 3: Full byte match (every bit identical)

For Level 2, the following instruction bits are MASKED (not compared):
  - mov.l @(d,PC),Rn: displacement bits (lower 8 bits)
  - mov.w @(d,PC),Rn: displacement bits (lower 8 bits)
  - bra disp: displacement bits (lower 12 bits)
  - bsr disp: displacement bits (lower 12 bits)
  - bf/bt/bf.s/bt.s disp: displacement bits (lower 8 bits)

This means Level 2 catches register allocation errors and wrong opcodes,
but correctly ignores literal pool placement differences.

Usage: python3 binary_diff.py [function_name]
"""

import subprocess
import struct
import os
import sys
import re
import tempfile
import shutil

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CC1 = f'{PROJDIR}/tools/gcc26-build/cc1'
AS = f'{PROJDIR}/tools/sh-elf/bin/sh-elf-as'
LD = f'{PROJDIR}/tools/sh-elf/bin/sh-elf-ld'
OBJCOPY = f'{PROJDIR}/tools/sh-elf/bin/sh-elf-objcopy'
OBJDUMP = f'{PROJDIR}/tools/sh-elf/bin/sh-elf-objdump'
BINARY = f'{PROJDIR}/build/aprog.bin'
APROG_S = f'{PROJDIR}/build/aprog.s'
SYMFILE = f'{PROJDIR}/build/aprog_syms.txt'
SRCDIR = f'{PROJDIR}/src'
TESTDIR = f'{PROJDIR}/tests'
BASE_ADDR = 0x06003000


def load_symbols():
    """Load function addresses from symbol file."""
    syms = {}
    with open(SYMFILE, 'r') as f:
        for line in f:
            line = line.strip().replace('\r', '')
            m = re.match(r'(FUN_[0-9A-Fa-f]+)\s*=\s*(0x[0-9A-Fa-f]+);', line)
            if m:
                syms[m.group(1)] = int(m.group(2), 16)
    return syms


def get_next_func_addr(syms, func_addr):
    """Get the address of the next function after func_addr."""
    sorted_addrs = sorted(set(syms.values()))
    for a in sorted_addrs:
        if a > func_addr:
            return a
    return func_addr + 256


def extract_original_insns(func_addr, num_insns):
    """Extract original instruction text from aprog.s."""
    insns = []
    with open(APROG_S, 'r') as f:
        found = False
        for line in f:
            line = line.rstrip('\r\n')
            m = re.search(r'/\*\s*([0-9a-fA-F]{8}):\s*(.+?)\s*\*/', line)
            if m:
                line_addr = int(m.group(1), 16)
                insn_text = m.group(2)
                insn_text = re.sub(r'\s*\{.*?\}', '', insn_text).strip()
                if line_addr == func_addr:
                    found = True
                if found:
                    if insn_text.startswith('.word'):
                        continue
                    insns.append((line_addr, insn_text))
                    if len(insns) >= num_insns:
                        break
    return insns


def extract_original_bytes(func_addr, size):
    """Extract raw bytes from original binary."""
    offset = func_addr - BASE_ADDR
    with open(BINARY, 'rb') as f:
        f.seek(offset)
        return f.read(size)


def extract_extern_symbols(s_file):
    """Extract external symbol references from .s file and map to addresses.
    Returns dict of {asm_symbol: address}."""
    symbols = {}
    with open(s_file, 'r') as f:
        content = f.read()

    # Find .long references (literal pool entries)
    for m in re.finditer(r'\.long\s+(_\w+)', content):
        sym = m.group(1)
        # Extract hex address from symbol name (last 6-8 hex chars)
        addr_match = re.search(r'_.*?([0-9a-fA-F]{6,8})$', sym)
        if addr_match:
            addr = int(addr_match.group(1), 16)
            # Validate it's a plausible address
            if addr >= 0x06000000 or addr >= 0x002A0000:
                symbols[sym] = addr

    # Find bra/bsr references
    for m in re.finditer(r'(?:bra|bsr)\s+(_\w+)', content):
        sym = m.group(1)
        addr_match = re.search(r'_.*?([0-9a-fA-F]{6,8})$', sym)
        if addr_match:
            addr = int(addr_match.group(1), 16)
            if addr >= 0x06000000 or addr >= 0x002A0000:
                symbols[sym] = addr

    # Also handle integer literals in .long (e.g., ".long 2752512")
    for m in re.finditer(r'\.long\s+(\d+)\s*$', content, re.MULTILINE):
        pass  # These are resolved constants, no symbol needed

    return symbols


def preprocess_bsr_bra(s_file):
    """Replace external BSR/BRA references with local stub labels.
    The SH assembler cannot generate relocations for BSR/BRA (12-bit
    displacement), so external references cause assembly failure.
    We replace them with local stub labels that assemble correctly.
    Level 2 comparison masks BSR/BRA displacements anyway."""
    with open(s_file, 'r') as f:
        content = f.read()

    # Find locally defined labels
    local_labels = set(re.findall(r'^(\w+):', content, re.MULTILINE))

    # Find external BSR/BRA references
    ext_refs = set()
    for m in re.finditer(r'\t(bsr|bra)\t(_\w+)', content):
        sym = m.group(2)
        if sym not in local_labels:
            ext_refs.add(sym)

    if not ext_refs:
        return False

    # Replace each external reference with a local stub label
    for sym in sorted(ext_refs):
        stub = '.Lstub' + sym  # e.g. .Lstub_FUN_0600DE54
        content = content.replace(f'\tbsr\t{sym}', f'\tbsr\t{stub}')
        content = content.replace(f'\tbra\t{sym}', f'\tbra\t{stub}')

    # Insert stub label definitions right after .align 1 in .text
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


def get_flags_for_func(func_name):
    """Read per-function compiler flags from .flags file, or return defaults."""
    flags_file = os.path.join(TESTDIR, f'{func_name}.flags')
    # Also check src/ for backwards compatibility
    if not os.path.exists(flags_file):
        flags_file = os.path.join(SRCDIR, f'{func_name}.flags')
    if os.path.exists(flags_file):
        with open(flags_file, 'r') as f:
            return f.read().strip().replace('\r', '').split()
    return ['-O2', '-m2', '-mbsr']


def compile_and_link(c_file, func_addr, syms, tmpdir, func_name=None):
    """Compile, assemble, and link at the correct address.
    Returns (elf_file, s_file, error_string)."""
    # Strip CRLF
    src = open(c_file, 'rb').read().replace(b'\r\n', b'\n')
    clean_c = os.path.join(tmpdir, 'test.c')
    open(clean_c, 'wb').write(src)

    # Get per-function flags
    flags = get_flags_for_func(func_name) if func_name else ['-O2', '-m2', '-mbsr']

    # Compile
    s_file = os.path.join(tmpdir, 'test.s')
    result = subprocess.run(
        [CC1, '-quiet'] + flags + [clean_c, '-o', s_file],
        capture_output=True, text=True
    )
    if result.returncode != 0:
        return None, s_file, f"compile error: {result.stderr[:200]}"

    # Extract extern symbols for linker (before BSR/BRA preprocessing)
    ext_syms = extract_extern_symbols(s_file)

    # Pre-process BSR/BRA: replace external refs with local stubs
    # so the assembler can resolve them (SH-ELF as doesn't support
    # BSR/BRA relocations for undefined symbols)
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
        [AS, '--big', '-o', o_file, s_file],
        capture_output=True, text=True
    )
    if result.returncode != 0:
        return None, s_file, f"assemble error: {result.stderr[:200]}"

    # Link
    elf_file = os.path.join(tmpdir, 'test.elf')
    result = subprocess.run(
        [LD, '-T', ld_script, '-o', elf_file, o_file],
        capture_output=True, text=True
    )
    if result.returncode != 0:
        return None, s_file, f"link error: {result.stderr[:200]}"

    return elf_file, s_file, None


def disassemble_elf(elf_file):
    """Disassemble linked ELF, return list of (addr, bytes_hex, insn_text)."""
    result = subprocess.run(
        [OBJDUMP, '-d', elf_file],
        capture_output=True, text=True
    )
    insns = []
    for line in result.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s+(.+)', line)
        if m:
            addr = int(m.group(1), 16)
            byteshex = m.group(2).strip()
            insn_text = m.group(3).strip()
            insn_text = re.sub(r'\t!.*$', '', insn_text)
            insn_text = re.sub(r'\t+', ' ', insn_text)
            insns.append((addr, byteshex, insn_text))
    return insns


def disassemble_obj(o_file):
    """Disassemble .o file (unlinked)."""
    result = subprocess.run(
        [OBJDUMP, '-d', o_file],
        capture_output=True, text=True
    )
    insns = []
    for line in result.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s+(.+)', line)
        if m:
            offset = int(m.group(1), 16)
            byteshex = m.group(2).strip()
            insn_text = m.group(3).strip()
            insn_text = re.sub(r'\t!.*$', '', insn_text)
            insn_text = re.sub(r'\d+\s*<\w+>', '<ref>', insn_text)
            insn_text = re.sub(r'\t+', ' ', insn_text)
            insns.append((offset, byteshex, insn_text))
    return insns


def extract_linked_bytes(elf_file, tmpdir):
    """Extract .text bytes from linked ELF."""
    bin_file = os.path.join(tmpdir, 'test.bin')
    subprocess.run(
        [OBJCOPY, '-O', 'binary', '-j', '.text', elf_file, bin_file],
        capture_output=True
    )
    if os.path.exists(bin_file):
        return open(bin_file, 'rb').read()
    return b''


def extract_unlinked_bytes(o_file, tmpdir):
    """Extract .text bytes from unlinked .o file."""
    bin_file = os.path.join(tmpdir, 'test_unlinked.bin')
    subprocess.run(
        [OBJCOPY, '-O', 'binary', '-j', '.text', o_file, bin_file],
        capture_output=True
    )
    if os.path.exists(bin_file):
        return open(bin_file, 'rb').read()
    return b''


def classify_sh_insn(word):
    """Classify an SH-2 instruction and return (type, mask).
    mask: bits that should match for structural comparison (1=compare, 0=ignore).
    """
    # Top 4 bits determine instruction format
    top4 = (word >> 12) & 0xF

    if top4 == 0xD:
        # 1101nnnndddddddd: mov.l @(disp,PC),Rn
        return 'mov.l_pool', 0xFF00  # compare opcode+register, mask displacement
    if top4 == 0x9:
        # 1001nnnndddddddd: mov.w @(disp,PC),Rn
        return 'mov.w_pool', 0xFF00  # compare opcode+register, mask displacement
    if top4 == 0xA:
        # 1010dddddddddddd: bra disp
        return 'bra', 0xF000  # compare opcode only, mask 12-bit displacement
    if top4 == 0xB:
        # 1011dddddddddddd: bsr disp
        return 'bsr', 0xF000  # compare opcode only, mask displacement

    # 8-bit branch instructions
    top8 = (word >> 8) & 0xFF
    if top8 == 0x8B:
        return 'bf', 0xFF00   # bf disp
    if top8 == 0x89:
        return 'bt', 0xFF00   # bt disp
    if top8 == 0x8F:
        return 'bf.s', 0xFF00  # bf/s disp
    if top8 == 0x8D:
        return 'bt.s', 0xFF00  # bt/s disp

    # Everything else: compare all bits
    return 'other', 0xFFFF


def get_mnemonic(text):
    """Extract mnemonic from instruction text."""
    text = text.strip().replace('bf/s', 'bf.s').replace('bt/s', 'bt.s')
    return text.split()[0] if text else ''


def compare_instructions(our_bytes, orig_bytes, num_insns):
    """Compare instruction bytes with smart masking.
    Returns (full_match_count, structural_match_count, total, details)."""
    details = []
    full_match = 0
    struct_match = 0
    total = min(num_insns, len(our_bytes) // 2, len(orig_bytes) // 2)

    for i in range(total):
        off = i * 2
        our_word = struct.unpack('>H', our_bytes[off:off+2])[0]
        orig_word = struct.unpack('>H', orig_bytes[off:off+2])[0]

        insn_type, mask = classify_sh_insn(orig_word)

        full_eq = (our_word == orig_word)
        struct_eq = ((our_word & mask) == (orig_word & mask))

        if full_eq:
            full_match += 1
            struct_match += 1
            details.append((i, our_word, orig_word, insn_type, 'MATCH'))
        elif struct_eq:
            struct_match += 1
            details.append((i, our_word, orig_word, insn_type, 'DISP'))
        else:
            details.append((i, our_word, orig_word, insn_type, 'DIFF'))

    return full_match, struct_match, total, details


def compile_to_asm_only(c_file, tmpdir):
    """Just compile to .s, for operand comparison when assembly/link fails."""
    src = open(c_file, 'rb').read().replace(b'\r\n', b'\n')
    clean_c = os.path.join(tmpdir, 'test.c')
    open(clean_c, 'wb').write(src)
    s_file = os.path.join(tmpdir, 'test.s')
    result = subprocess.run(
        [CC1, '-quiet', '-O2', '-m2', '-mbsr', clean_c, '-o', s_file],
        capture_output=True, text=True
    )
    if result.returncode != 0:
        return None, f"compile error: {result.stderr[:200]}"
    return s_file, None


def extract_asm_insns(s_file):
    """Extract instruction mnemonics+operands from GCC .s output."""
    insns = []
    with open(s_file, 'r') as f:
        for line in f:
            line = line.rstrip('\r\n')
            # Instructions start with tab and lowercase letter
            if re.match(r'^\t[a-z]', line):
                insn = line.strip()
                # Normalize bf/s notation
                insn = insn.replace('bf/s', 'bf.s').replace('bt/s', 'bt.s')
                insns.append(insn)
    return insns


def normalize_for_compare(text):
    """Normalize instruction text for operand comparison."""
    text = text.strip()
    # Normalize whitespace FIRST for consistent regex matching
    text = re.sub(r'[\t ]+', ' ', text)
    # Mask literal pool references (disasm format)
    text = re.sub(r'@\(0x[0-9a-fA-F]+,PC\)', '@(<d>,PC)', text)
    text = re.sub(r'@\(\d+,pc\)', '@(<d>,PC)', text, flags=re.I)
    # Mask branch targets (hex addresses)
    text = re.sub(r'0x[0-9a-fA-F]{4,8}', '<target>', text)
    # Mask GCC label references
    text = re.sub(r'\bL\d+\b', '<label>', text)
    # Mask _symbol references
    text = re.sub(r'_\w+', '<sym>', text)
    # Unify PC-relative load formats:
    #   GCC:   mov.l <label>,rN  or  mov.l <sym>,rN
    #   Disasm: mov.l @(<d>,PC),rN
    text = re.sub(r'(mov\.[lw]) (?:<label>|<sym>),', r'\1 @(<d>,PC),', text)
    # Unify branch target formats:
    #   GCC:   bsr <sym>  /  bra <sym>
    #   Disasm: bsr <target>  /  bra <target>
    text = re.sub(r'(bsr|bra) (?:<target>|<sym>)', r'\1 <target>', text)
    return text


def run_test(func_name, syms, verbose=False):
    """Run comparison for one test function."""
    c_file = os.path.join(SRCDIR, f'{func_name}.c')
    expected_file = os.path.join(TESTDIR, f'{func_name}.expected')

    if not os.path.exists(c_file) or not os.path.exists(expected_file):
        return {'status': 'skip', 'reason': 'missing files'}

    # Read expected mnemonics
    with open(expected_file, 'r') as f:
        expected_mnemonics = [l.strip().replace('\r', '').replace('bf/s', 'bf.s').replace('bt/s', 'bt.s')
                              for l in f if l.strip()]
    exp_count = len(expected_mnemonics)

    # Get function address
    m = re.match(r'FUN_([0-9A-Fa-f]+)', func_name)
    func_addr = int(m.group(1), 16) if m else syms.get(func_name)
    if func_addr is None:
        return {'status': 'skip', 'reason': 'no address'}

    tmpdir = tempfile.mkdtemp(prefix='bindiff_')
    try:
        # Try full compile → assemble → link
        elf_file, s_file, link_err = compile_and_link(c_file, func_addr, syms, tmpdir, func_name)

        # Get our assembly instructions (always available after compile)
        if s_file and os.path.exists(s_file):
            our_asm_insns = extract_asm_insns(s_file)
        else:
            return {'status': 'error', 'reason': link_err or 'no .s file'}

        our_mnemonics = [get_mnemonic(i) for i in our_asm_insns]
        our_count = len(our_asm_insns)

        # Get original instructions from aprog.s
        orig_insns = extract_original_insns(func_addr, exp_count)
        orig_texts = [text for _, text in orig_insns]

        # === Level 1: Mnemonic comparison ===
        mnemonic_match = (our_mnemonics == expected_mnemonics)

        # === Operand comparison (works even without linking) ===
        operand_diffs = []
        for i in range(min(len(our_asm_insns), len(orig_texts))):
            our_norm = normalize_for_compare(our_asm_insns[i])
            orig_norm = normalize_for_compare(orig_texts[i])
            our_mnem = get_mnemonic(our_asm_insns[i])
            orig_mnem = get_mnemonic(orig_texts[i])
            if our_mnem != orig_mnem:
                operand_diffs.append((i, 'mnemonic', orig_texts[i], our_asm_insns[i]))
            elif our_norm != orig_norm:
                operand_diffs.append((i, 'operand', orig_texts[i], our_asm_insns[i]))

        # === Byte comparison (only if linking succeeded) ===
        linked = elf_file is not None
        byte_result = None
        our_disasm = []

        if linked:
            # Get linked disassembly first (more reliable than raw extraction)
            our_disasm = disassemble_elf(elf_file)

            # Build our_bytes from disassembly to avoid alignment padding issues.
            # The linker may add padding before the function for alignment,
            # so extract_linked_bytes can return shifted bytes.  Using
            # disassembly bytes guarantees we get the right instruction encoding.
            func_disasm = [d for d in our_disasm if d[0] >= func_addr]
            our_bytes = b''
            for _, bytes_hex, _ in func_disasm[:exp_count]:
                our_bytes += bytes.fromhex(bytes_hex.replace(' ', ''))

            orig_bytes = extract_original_bytes(func_addr, exp_count * 2)

            if our_bytes and orig_bytes:
                full_match, struct_match, total, byte_details = \
                    compare_instructions(our_bytes, orig_bytes, exp_count)
                byte_result = {
                    'full_match': full_match,
                    'struct_match': struct_match,
                    'total': total,
                    'details': byte_details,
                    'our_bytes': our_bytes,
                    'orig_bytes': orig_bytes,
                }

        result = {
            'status': 'tested',
            'func_addr': func_addr,
            'our_count': our_count,
            'exp_count': exp_count,
            'mnemonic_match': mnemonic_match,
            'operand_diffs': operand_diffs,
            'linked': linked,
            'link_err': link_err,
            'byte_result': byte_result,
            'our_asm': our_asm_insns,
            'orig_texts': orig_texts,
            'our_disasm': our_disasm,
        }

        if verbose:
            print(f"\n{'='*78}")
            print(f"  {func_name}  (0x{func_addr:08X})")
            print(f"{'='*78}")
            delta = our_count - exp_count
            print(f"  Instructions: ours={our_count} orig={exp_count} delta={delta:+d}")
            print(f"  Mnemonic match: {'YES' if mnemonic_match else 'NO'}")
            print(f"  Linked: {'YES' if linked else 'NO'} {('(' + link_err + ')') if link_err else ''}")

            if byte_result:
                br = byte_result
                print(f"  Byte comparison: {br['full_match']}/{br['total']} full match, "
                      f"{br['struct_match']}/{br['total']} structural match")

            print()

            # Side-by-side: original disasm vs our disasm (or asm)
            max_i = max(our_count, exp_count)
            print(f"  {'#':>3}  {'Original':42s}  {'Ours':42s}  Byte")
            print(f"  {'─'*3}  {'─'*42}  {'─'*42}  {'─'*12}")

            for i in range(max_i):
                orig_txt = orig_texts[i] if i < len(orig_texts) else '---'

                # Use linked disasm if available, otherwise raw asm
                if our_disasm and i < len(our_disasm):
                    our_txt = our_disasm[i][2]
                elif i < len(our_asm_insns):
                    our_txt = our_asm_insns[i]
                else:
                    our_txt = '---'

                # Byte status
                if byte_result and i < len(byte_result['details']):
                    d = byte_result['details'][i]
                    _, our_w, orig_w, itype, status = d
                    if status == 'MATCH':
                        byte_str = f'{orig_w:04x} OK'
                    elif status == 'DISP':
                        byte_str = f'{our_w:04x}~{orig_w:04x}'
                    else:
                        byte_str = f'{our_w:04x}!{orig_w:04x}'
                elif i < our_count and i < exp_count:
                    byte_str = 'no link'
                elif i >= exp_count:
                    byte_str = 'EXTRA'
                else:
                    byte_str = 'MISSING'

                print(f"  {i:3d}  {orig_txt:42s}  {our_txt:42s}  {byte_str}")

        return result

    finally:
        shutil.rmtree(tmpdir, ignore_errors=True)


def main():
    syms = load_symbols()

    verbose_func = sys.argv[1] if len(sys.argv) > 1 else None

    # Find all test functions (C source in src/, expected opcodes in tests/)
    test_funcs = []
    for fname in sorted(os.listdir(SRCDIR)):
        if fname.endswith('.c'):
            base = fname[:-2]
            if os.path.exists(os.path.join(TESTDIR, f'{base}.expected')):
                test_funcs.append(base)

    if verbose_func:
        if verbose_func in test_funcs:
            run_test(verbose_func, syms, verbose=True)
        else:
            print(f"Unknown function: {verbose_func}")
            print(f"Available: {', '.join(test_funcs)}")
        return

    # Run all tests
    print("=" * 78)
    print("  Binary-Level Comparison Test Harness")
    print("  Levels: L1=Mnemonic  L2=Structural  L3=Byte-perfect")
    print("=" * 78)
    print()

    counts = {'byte_match': 0, 'struct_match': 0, 'mnem_match': 0,
              'tested': 0, 'linked': 0, 'skipped': 0}
    all_results = []

    for func_name in test_funcs:
        r = run_test(func_name, syms)
        if r['status'] != 'tested':
            counts['skipped'] += 1
            print(f"  SKIP        {func_name:20s}  ({r.get('reason', '?')})")
            continue

        counts['tested'] += 1
        delta = r['our_count'] - r['exp_count']

        # Classify
        is_mnem = r['mnemonic_match']
        is_linked = r['linked']
        br = r['byte_result']

        if is_linked:
            counts['linked'] += 1

        is_byte = False
        is_struct = False
        struct_detail = ''

        if br:
            is_byte = (br['full_match'] == br['total'] == r['exp_count'] and r['our_count'] == r['exp_count'])
            is_struct = (br['struct_match'] == br['total'] == r['exp_count'] and r['our_count'] == r['exp_count'])
            disp_diffs = sum(1 for d in br['details'] if d[4] == 'DISP')
            real_diffs = sum(1 for d in br['details'] if d[4] == 'DIFF')
            struct_detail = f' struct={br["struct_match"]}/{br["total"]} byte={br["full_match"]}/{br["total"]}'
            if disp_diffs:
                struct_detail += f' disp={disp_diffs}'
            if real_diffs:
                struct_detail += f' REAL={real_diffs}'

        if is_byte:
            tag = 'L3:BYTE'
            counts['byte_match'] += 1
            counts['struct_match'] += 1
            counts['mnem_match'] += 1
        elif is_struct:
            tag = 'L2:STRUCT'
            counts['struct_match'] += 1
            counts['mnem_match'] += 1
        elif is_mnem:
            tag = 'L1:MNEM'
            counts['mnem_match'] += 1
        else:
            tag = 'DIFF'

        reg_diffs = sum(1 for d in r['operand_diffs'] if d[1] == 'operand')
        opc_diffs = sum(1 for d in r['operand_diffs'] if d[1] == 'mnemonic')

        detail = f'delta={delta:+d}'
        if reg_diffs:
            detail += f' reg={reg_diffs}'
        if opc_diffs:
            detail += f' opc={opc_diffs}'
        if not is_linked:
            detail += ' (no link)'
        detail += struct_detail

        print(f"  {tag:12s}  {func_name:20s}  {detail}")
        all_results.append((func_name, tag, r))

    t = counts['tested']
    l = counts['linked']
    print()
    print("=" * 78)
    print(f"  Results ({t} tested, {counts['skipped']} skipped, {l} linked):")
    print(f"    L3 Byte-perfect:  {counts['byte_match']:2d}/{t}  ({100*counts['byte_match']//t if t else 0}%)")
    print(f"    L2 Structural:    {counts['struct_match']:2d}/{t}  ({100*counts['struct_match']//t if t else 0}%)")
    print(f"    L1 Mnemonic:      {counts['mnem_match']:2d}/{t}  ({100*counts['mnem_match']//t if t else 0}%)")
    print("=" * 78)


if __name__ == '__main__':
    main()
