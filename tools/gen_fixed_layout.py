#!/usr/bin/env python3
"""gen_fixed_layout.py -- Generate fixed-address binary layout for boot.

Generates:
  1. reimpl/saturn_fixed.ld   -- linker script pinning functions at original addresses
  2. Patches reimpl/src/asm_*.c -- adds .section directives to ASM imports
  3. reimpl/src/trampolines.s  -- trampoline stubs for overflowing C functions
                                  that are referenced by ASM constant pools

Usage:
    python3 tools/gen_fixed_layout.py [--dry-run]
"""

import os
import re
import sys
import struct
import subprocess

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SYMS_FILE = os.path.join(PROJ, "build", "aprog_syms.txt")
SRC_DIR = os.path.join(PROJ, "reimpl", "src")
ELF_PATH = os.path.join(PROJ, "reimpl", "build", "daytona.elf")
NM_PATH = os.path.join(PROJ, "tools", "sh-elf", "bin", "sh-elf-nm")
LD_OUTPUT = os.path.join(PROJ, "reimpl", "saturn_fixed.ld")
TRAMPOLINE_OUTPUT = os.path.join(PROJ, "reimpl", "src", "trampolines.s")

BASE_ADDR = 0x06003000
APROG_SIZE = 394896
END_ADDR = BASE_ADDR + APROG_SIZE
TRAMPOLINE_SIZE = 10  # mov.l + jmp + nop + .long = 2+2+2+4 = 10 bytes


def parse_syms():
    """Parse aprog_syms.txt -> list of (addr, name) sorted by address."""
    syms = []
    with open(SYMS_FILE) as f:
        for line in f:
            m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            if m:
                syms.append((int(m.group(2), 16), m.group(1)))
    syms.sort()
    return syms


def compute_sizes(syms):
    """Compute original size of each function."""
    sizes = {}
    for i, (addr, name) in enumerate(syms):
        next_addr = syms[i + 1][0] if i + 1 < len(syms) else END_ADDR
        sizes[name] = (addr, next_addr - addr)
    return sizes


def find_asm_globals():
    """Find all FUN_ names defined in asm_*.c files (ASM imports + C wrappers).

    Catches both:
    - Inline ASM: .global _FUN_XXXX
    - C wrapper functions: void FUN_XXXX(void) { ... }
    """
    asm_globals = set()
    for fname in os.listdir(SRC_DIR):
        if fname.startswith('asm_') and fname.endswith('.c'):
            with open(os.path.join(SRC_DIR, fname)) as f:
                for line in f:
                    # ASM imports: .global _FUN_XXXX
                    m = re.search(r'\.global\s+_?(FUN_[0-9A-Fa-f]+)', line)
                    if m:
                        asm_globals.add(m.group(1).upper())
                    # C wrapper functions: void FUN_XXXX(...) or int FUN_XXXX(...)
                    m = re.search(r'(?:void|int|unsigned)\s+(FUN_[0-9A-Fa-f]+)\s*\(', line)
                    if m:
                        asm_globals.add(m.group(1).upper())
    return asm_globals


def scan_extra_fun_addrs(known_addrs):
    """Scan ALL source files for FUN_ addresses not in aprog_syms.txt.

    Returns list of (addr, name) for extra FUN_ functions found in C code.
    Only includes addresses within the binary range (0x06003000-END_ADDR).
    """
    extra = {}  # addr -> name

    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.endswith('.c'):
            continue
        filepath = os.path.join(SRC_DIR, fname)
        with open(filepath, errors='replace') as f:
            content = f.read()

        # Find FUN_ function definitions (C code)
        # Match any line where FUN_xxxxxxxx appears as a function definition
        # (preceded by a C type, possibly with * for pointer return)
        for m in re.finditer(
            r'(?:^|\n)\s*(?:(?:void|int|unsigned|char|short|long|struct\s+\w+)'
            r'[\s\*]+)(FUN_([0-9a-fA-F]{6,8}))\s*\(',
            content
        ):
            fun_name = m.group(1)
            hex_part = m.group(2)
            try:
                addr = int(hex_part, 16)
            except ValueError:
                continue
            if BASE_ADDR <= addr < END_ADDR and addr not in known_addrs:
                upper_name = 'FUN_' + hex_part.upper()
                extra[addr] = upper_name

        # Find FUN_ in inline ASM .global directives (batch_*.c files too)
        for m in re.finditer(r'\.global\s+_?(FUN_([0-9a-fA-F]{6,8}))', content):
            hex_part = m.group(2)
            try:
                addr = int(hex_part, 16)
            except ValueError:
                continue
            if BASE_ADDR <= addr < END_ADDR and addr not in known_addrs:
                upper_name = 'FUN_' + hex_part.upper()
                extra[addr] = upper_name

    return sorted(extra.items())


def scan_named_context_map():
    """Scan source files for named → FUN_ mappings using broader heuristics.

    Finds mappings from:
    1. __attribute__((alias("..."))) declarations (authoritative)
    2. Named function defs immediately after #if 0 /* FUN_xxx */ blocks
    3. Comments like /* was FUN_xxx */ or /* replaces FUN_xxx */
    """
    named_to_fun = {}  # named -> FUN_XXXXXXXX

    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.endswith('.c'):
            continue
        filepath = os.path.join(SRC_DIR, fname)
        with open(filepath, errors='replace') as f:
            lines = f.readlines()
            content = ''.join(lines)

        # Method 1: alias declarations (most reliable)
        for m in re.finditer(
            r'(?:void|int|unsigned\s+int|char\s*\*?|short)\s+'
            r'(\w+)\s*\([^)]*\)\s*__attribute__\s*\(\s*\(\s*alias\s*\(\s*"(\w+)"\s*\)',
            content
        ):
            sym1, sym2 = m.group(1), m.group(2)
            if sym1.startswith('FUN_') and not sym2.startswith('FUN_'):
                named_to_fun[sym2] = sym1.upper()
            elif sym2.startswith('FUN_') and not sym1.startswith('FUN_'):
                named_to_fun[sym1] = sym2.upper()

        # Method 2: #if 0 /* FUN_xxx ... */ followed by named function def
        for i, line in enumerate(lines):
            m = re.match(r'\s*#if\s+0\s*/\*\s*(FUN_[0-9a-fA-F]+)', line)
            if not m:
                continue
            fun_name = m.group(1).upper()

            # Look ahead for #endif, then a named function def
            for j in range(i + 1, min(i + 50, len(lines))):
                if re.match(r'\s*#endif', lines[j]):
                    # Look for named function def in the next few lines
                    for k in range(j + 1, min(j + 5, len(lines))):
                        fm = re.match(
                            r'\s*(?:void|int|unsigned\s+(?:int|short|char|long)|char|short|long)\s+'
                            r'([a-z_][a-z0-9_]+)\s*\(',
                            lines[k]
                        )
                        if fm:
                            name = fm.group(1)
                            skip = {'if', 'while', 'for', 'return', 'switch',
                                    'int', 'void', 'char', 'short', 'unsigned'}
                            if name not in skip and name not in named_to_fun:
                                named_to_fun[name] = fun_name
                    break

        # Method 3: REMOVED alias comments (from fix_alias_conflicts.py)
        # Pattern: /* REMOVED: conflicting alias */ // void FUN_XXX(...) __attribute__((alias("name")));
        for m in re.finditer(
            r'/\*\s*REMOVED:.*?\*/\s*//\s*(?:void|int|unsigned\s+int|char\s*\*?|short)\s+'
            r'(\w+)\s*\([^)]*\)\s*__attribute__\s*\(\s*\(\s*alias\s*\(\s*"(\w+)"\s*\)',
            content
        ):
            sym1, sym2 = m.group(1), m.group(2)
            if sym1.startswith('FUN_') and not sym2.startswith('FUN_'):
                if sym2 not in named_to_fun:
                    named_to_fun[sym2] = sym1.upper()
            elif sym2.startswith('FUN_') and not sym1.startswith('FUN_'):
                if sym1 not in named_to_fun:
                    named_to_fun[sym1] = sym2.upper()

        # Method 4: #if 0 /* name -- redirected to ASM import via linker PROVIDE */
        # These are functions wrapped by redirect_named_to_asm.py
        for i, line in enumerate(lines):
            m = re.match(r'\s*#if\s+0\s*/\*\s+([a-z_][a-z0-9_]+)\s+--\s+redirected', line)
            if not m:
                continue
            name = m.group(1)
            # The PROVIDE mapping is in the linker script, but we can also check
            # the function def inside the #if 0 block for the address
            # Skip -- these are already handled by PROVIDE in the linker script

        # Method 5: Comment-based address before function def
        # Pattern: /* 0xXXXXXXXX: description */\nvoid name(...)
        for i, line in enumerate(lines):
            m = re.match(r'\s*/\*\s*(?:0x)?(060[0-9a-fA-F]{5}):', line)
            if not m:
                continue
            addr = int(m.group(1), 16)
            fun_name = 'FUN_%08X' % addr
            # Look for function def in the next lines (up to 75 — doc blocks can be long)
            for k in range(i + 1, min(i + 75, len(lines))):
                fm = re.match(
                    r'\s*(?:void|int|unsigned\s+(?:int|short|char|long)|char|short|long)\s+'
                    r'([a-z_][a-z0-9_]+)\s*\(',
                    lines[k]
                )
                if fm:
                    name = fm.group(1)
                    skip = {'if', 'while', 'for', 'return', 'switch',
                            'int', 'void', 'char', 'short', 'unsigned'}
                    if name not in skip:
                        # Method 5 is authoritative — override Method 2 heuristic
                        named_to_fun[name] = fun_name
                    break

    return named_to_fun


def get_elf_func_sizes(elf_path=None):
    """Get compiled function sizes from our ELF via nm."""
    if elf_path is None:
        elf_path = ELF_PATH
    result = subprocess.run(
        [NM_PATH, '-S', '--size-sort', elf_path],
        capture_output=True, text=True
    )
    funcs = {}
    for line in result.stdout.splitlines():
        parts = line.strip().split()
        if len(parts) >= 4 and parts[2].lower() == 't':
            funcs[parts[3]] = int(parts[1], 16)
    return funcs


def build_c_func_map():
    """Scan C source files for function-to-FUN_ mappings.

    Returns dict: c_func_name -> FUN_XXXX (uppercase)
    Also returns dict: FUN_XXXX -> c_func_name (for renamed functions)
    """
    # Map from alias target to FUN_ name
    alias_map = {}  # c_name -> FUN_name
    reverse_map = {}  # FUN_name -> c_name

    for fname in os.listdir(SRC_DIR):
        if not fname.endswith('.c'):
            continue
        filepath = os.path.join(SRC_DIR, fname)
        with open(filepath) as f:
            content = f.read()

        # Find alias declarations: void FUN_XXXX() __attribute__((alias("c_name")));
        for m in re.finditer(
            r'(?:void|int|unsigned\s+int|char\s*\*?)\s+(FUN_[0-9A-Fa-f]+)\s*\([^)]*\)\s*'
            r'__attribute__\s*\(\s*\(\s*alias\s*\(\s*"(\w+)"\s*\)',
            content
        ):
            fun_name = m.group(1).upper()
            c_name = m.group(2)
            alias_map[c_name] = fun_name
            reverse_map[fun_name] = c_name

    return alias_map, reverse_map


def scan_asm_constant_pools(asm_globals):
    """Scan ASM imports for 32-bit constant pool values that match function addresses.

    Returns set of addresses referenced by ASM constant pools.
    """
    # Build set of all known function addresses
    syms = parse_syms()
    known_addrs = {addr for addr, name in syms}

    referenced_addrs = set()

    for fname in os.listdir(SRC_DIR):
        if not (fname.startswith('asm_') and fname.endswith('.c')):
            continue
        filepath = os.path.join(SRC_DIR, fname)
        words = []
        with open(filepath) as f:
            for line in f:
                m = re.search(r'\.word\s+0x([0-9A-Fa-f]{4})', line)
                if m:
                    words.append(int(m.group(1), 16))

        # Check consecutive word pairs for 32-bit addresses
        for i in range(len(words) - 1):
            addr32 = (words[i] << 16) | words[i + 1]
            if addr32 in known_addrs:
                referenced_addrs.add(addr32)

    return referenced_addrs


def find_overflows(orig_sizes, asm_globals, elf_sizes, reverse_map=None):
    """Find C functions that overflow their original slot.

    Returns list of (fun_name, orig_addr, orig_size, our_size).
    """
    if reverse_map is None:
        reverse_map = {}
    overflows = []
    for fun_name, (orig_addr, orig_size) in orig_sizes.items():
        if fun_name.upper() in asm_globals:
            continue

        # Try to find our compiled size via multiple name variants
        our_size = None
        candidates = [fun_name, '_' + fun_name,
                      fun_name.lower(), '_' + fun_name.lower(),
                      fun_name.upper(), '_' + fun_name.upper()]
        # Also try the C alias name if this function was renamed
        if fun_name.upper() in reverse_map:
            c_name = reverse_map[fun_name.upper()]
            candidates.extend([c_name, '_' + c_name])

        for try_name in candidates:
            if try_name in elf_sizes:
                our_size = elf_sizes[try_name]
                break

        if our_size is not None and our_size > orig_size:
            overflows.append((fun_name, orig_addr, orig_size, our_size))

    return overflows


def find_redirected_named_functions(reverse_map):
    """Find named functions wrapped in #if 0 /* name -- redirected to ASM import via linker PROVIDE */.

    Returns list of (named_sym, FUN_sym) tuples for PROVIDE alias generation.
    """
    provides = []
    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.endswith('.c'):
            continue
        with open(os.path.join(SRC_DIR, fname)) as f:
            content = f.read()
        for m in re.finditer(
            r'#if\s+0\s*/\*\s*(\w+)\s+--\s+redirected\s+to\s+ASM\s+import\s+via\s+linker\s+PROVIDE',
            content
        ):
            named = m.group(1)
            # Find the FUN_ address from reverse_map or context
            fun = None
            for fun_name, c_name in reverse_map.items():
                if c_name == named:
                    fun = fun_name
                    break
            if not fun:
                # Try to find from the #if 0 block content
                pos = m.end()
                block_end = content.find('#endif', pos)
                if block_end > 0:
                    block = content[pos:block_end]
                    fm = re.search(r'(FUN_[0-9A-Fa-f]+)', block)
                    if fm:
                        fun = fm.group(1).upper()
            if fun:
                provides.append((named, fun))
    return provides


def generate_linker_script(syms, orig_sizes, asm_globals, overflows_needing_trampoline,
                           overflows_free, alias_map, reverse_map, sub_entries=None):
    """Generate saturn_fixed.ld with per-function sections at original addresses."""
    trampoline_funs = {o[0].upper() for o in overflows_needing_trampoline}
    free_overflow_funs = {o[0].upper() for o in overflows_free}

    lines = []
    lines.append('/* saturn_fixed.ld -- Fixed-address linker script for Daytona USA reimpl')
    lines.append(' * AUTO-GENERATED by tools/gen_fixed_layout.py -- do not edit manually')
    lines.append(' *')
    lines.append(' * Places every function at its original address in the production binary.')
    lines.append(' * Overflowing C functions go in the OVERFLOW section with trampolines')
    lines.append(' * at their original addresses.')
    lines.append(' */')
    lines.append('')
    lines.append('OUTPUT_FORMAT("elf32-sh")')
    lines.append('OUTPUT_ARCH(sh)')
    lines.append('ENTRY(_start)')
    lines.append('')
    lines.append('MEMORY')
    lines.append('{')
    lines.append('    HWRAM (rwx) : ORIGIN = 0x06003000, LENGTH = 0xE0000')
    lines.append('    LWRAM (rw)  : ORIGIN = 0x00200000, LENGTH = 0x100000')
    lines.append('}')
    lines.append('')
    lines.append('SECTIONS')
    lines.append('{')

    # Startup section at 0x06003000 (contains _start from start.s)
    lines.append('    /* Entry point -- _start + boot() */')
    lines.append('    .text.startup 0x%08X :' % BASE_ADDR)
    lines.append('    {')
    lines.append('        *(.text.startup)')
    lines.append('    } > HWRAM')
    lines.append('')

    if sub_entries is None:
        sub_entries = set()

    # Per-function sections
    for addr, name in syms:
        upper_name = name.upper()

        # Skip sub-entries -- they live inside their parent's section
        if upper_name in sub_entries:
            continue

        section_name = '.text.%s' % name

        # Build the input section list
        input_sections = []

        # If this function needs a trampoline (overflow + ASM-referenced),
        # the trampoline goes here instead of the real function.
        # Also always include the standard FUN_ section -- ASM byte imports
        # create .text.FUN_XXXXXXXX sections that must land at the correct address.
        if upper_name in trampoline_funs:
            input_sections.append('*(.text.trampoline_%s)' % name)
            input_sections.append('*(%s)' % section_name)
            # Also lowercase hex variant
            lower_hex = name[:4] + name[4:].lower()
            if lower_hex != name:
                input_sections.append('*(.text.%s)' % lower_hex)
            # Also capture named alias section (e.g. .text.car_palette_load_primary
            # when FUN_060039C8 is an alias of car_palette_load_primary). Without
            # this, GCC puts code in .text.named_function which goes to overflow.
            if upper_name in reverse_map:
                c_name = reverse_map[upper_name]
                input_sections.append('*(.text.%s)' % c_name)
        elif upper_name in free_overflow_funs:
            # Overflowing but not ASM-referenced -- the C code will land in
            # the overflow catchall. But still include the standard FUN_ glob
            # so ASM byte imports (if any) land at the correct address.
            input_sections.append('*(%s)' % section_name)
            lower_hex = name[:4] + name[4:].lower()
            if lower_hex != name:
                input_sections.append('*(.text.%s)' % lower_hex)
            # Also capture named alias section
            if upper_name in reverse_map:
                c_name = reverse_map[upper_name]
                input_sections.append('*(.text.%s)' % c_name)
        else:
            # Include the FUN_ section at the original address.
            input_sections.append('*(%s)' % section_name)
            # Also include lowercase hex variant -- Ghidra L1 lifts use lowercase
            # (e.g., .text.FUN_06005ecc vs .text.FUN_06005ECC)
            lower_hex = name[:4] + name[4:].lower()
            if lower_hex != name:
                input_sections.append('*(.text.%s)' % lower_hex)
            # Also include the C alias section if this function was renamed
            # (e.g., system_init -> FUN_060030FC). GCC -ffunction-sections puts
            # code in .text.system_init, not .text.FUN_060030FC.
            if upper_name in reverse_map:
                c_name = reverse_map[upper_name]
                input_sections.append('*(.text.%s)' % c_name)

        lines.append('    .func_%s 0x%08X : SUBALIGN(1)' % (name, addr))
        lines.append('    {')
        for inp in input_sections:
            lines.append('        %s' % inp)
        lines.append('    } > HWRAM')

    # PROVIDE aliases for named functions redirected to ASM imports
    provides = find_redirected_named_functions(reverse_map)
    if provides:
        lines.append('')
        lines.append('    /* Named function PROVIDE aliases -- auto-generated')
        lines.append('     * Maps named C symbols to their FUN_ ASM import addresses.')
        lines.append('     * Active only when the named C function is wrapped in #if 0.')
        lines.append('     */')
        for named, fun in sorted(provides, key=lambda x: x[1]):
            lines.append('    PROVIDE(_%s = _%s);' % (named, fun))

    lines.append('')
    lines.append('    /* Overflow area for C functions that exceed their original slot */')
    lines.append('    .text.overflow :')
    lines.append('    {')
    lines.append('        *(.text.overflow)')
    lines.append('        *(.text.*)')
    lines.append('        *(.text)')
    lines.append('    } > HWRAM')
    lines.append('')
    lines.append('    .rodata :')
    lines.append('    {')
    lines.append('        *(.rodata .rodata.*)')
    lines.append('    } > HWRAM')
    lines.append('')
    lines.append('    .data :')
    lines.append('    {')
    lines.append('        *(.data .data.*)')
    lines.append('    } > HWRAM')
    lines.append('')
    lines.append('    .bss :')
    lines.append('    {')
    lines.append('        __bss_start = .;')
    lines.append('        *(.bss .bss.*)')
    lines.append('        *(COMMON)')
    lines.append('        __bss_end = .;')
    lines.append('    } > HWRAM')
    lines.append('')
    lines.append('    _end = .;')
    lines.append('')
    lines.append('    /DISCARD/ :')
    lines.append('    {')
    lines.append('        *(.comment)')
    lines.append('        *(.note.*)')
    lines.append('        *(.eh_frame)')
    lines.append('    }')
    lines.append('}')

    return '\n'.join(lines) + '\n'


def find_sub_entries(syms):
    """Find functions whose address falls within another function's range.

    These are sub-entry points (alternate entry into a parent function).
    They should NOT get their own section -- they're labels within the parent.

    Returns set of FUN_ names that are sub-entries.
    """
    sub_entries = set()
    sorted_syms = sorted(syms)

    for i, (addr, name) in enumerate(sorted_syms):
        # Look at the previous function -- does this address fall within it?
        if i > 0:
            prev_addr, prev_name = sorted_syms[i - 1]
            # If the distance to the next function after prev is > distance to us,
            # then we're inside prev's range
            if i + 1 < len(sorted_syms):
                next_after_prev = sorted_syms[i + 1][0] if i + 1 < len(sorted_syms) else END_ADDR
            else:
                next_after_prev = END_ADDR

            # Check if the PREVIOUS function extends past our address
            # by seeing if the next function after us has a larger gap
            prev_size_if_no_sub = addr - prev_addr
            # A sub-entry typically has a very small gap to the parent
            # More robustly: check if prev function's actual ASM content
            # continues past our address

        # Simple heuristic: check if any function in the sorted list has
        # the same first few words (shares code). For now, use address gaps:
        # if the gap between consecutive functions is <= 30 bytes and the
        # second function's size (to next) is larger than its gap, it's likely
        # a sub-entry.
        pass

    # Better approach: parse the ASM files to find which .global labels
    # appear WITHOUT a preceding .balign (i.e., they're mid-function labels)
    for fname in sorted(os.listdir(SRC_DIR)):
        if not (fname.startswith('asm_') and fname.endswith('.c')):
            continue
        filepath = os.path.join(SRC_DIR, fname)
        with open(filepath) as f:
            raw_lines = f.readlines()

        # Clean lines first: strip section directives and alignment padding
        # that may have been inserted by previous tool runs (idempotency)
        lines = []
        for line in raw_lines:
            if '.section .text.FUN_' in line:
                continue
            if 'alignment padding' in line and '.short' in line:
                continue
            lines.append(line)

        # Walk through lines looking for .global _FUN_ without a .balign within
        # the preceding non-blank lines (sub-entries are inserted directly without .balign)
        for i, line in enumerate(lines):
            gm = re.search(r'\.global\s+_(FUN_[0-9A-Fa-f]+)', line)
            if not gm:
                continue
            fun_name = gm.group(1).upper()

            # Scan backward skipping blank lines -- look for .balign among the
            # preceding 6 non-blank lines (blank lines from stripping don't count)
            has_balign = False
            non_blank_seen = 0
            for j in range(i - 1, max(0, i - 20) - 1, -1):
                stripped = lines[j].strip()
                if not stripped:
                    continue
                if '.balign' in stripped:
                    has_balign = True
                    break
                non_blank_seen += 1
                if non_blank_seen >= 6:
                    break

            if not has_balign:
                sub_entries.add(fun_name)

    return sub_entries


def patch_asm_files(sub_entries=None):
    """Add .section directives to each function in asm_*.c files.

    For each non-sub-entry function, inserts a .section directive immediately
    before the .global line. This ensures alignment padding (.balign, .short)
    stays in the PREVIOUS section and doesn't inflate the new function's size.

    Idempotent: strips any existing .section directives before adding new ones.
    """
    if sub_entries is None:
        sub_entries = set()
    changes = {}

    for fname in sorted(os.listdir(SRC_DIR)):
        if not (fname.startswith('asm_') and fname.endswith('.c')):
            continue
        filepath = os.path.join(SRC_DIR, fname)
        with open(filepath) as f:
            content = f.read()

        original = content

        # First pass: strip existing section directives, .size directives, and
        # inter-function alignment padding (not needed with fixed-address sections)
        lines = content.split('\n')
        clean_lines = []
        for line in lines:
            # Strip previously inserted .section directives
            if '.section .text.FUN_' in line or '.section .text.asm_' in line:
                continue
            # Strip .size directives (break across section boundaries)
            if '.size' in line and re.search(r'\.size\s+_FUN_', line):
                continue
            # Strip alignment padding .short entries -- these inflate sections
            # (they were needed for sequential layout but not fixed-address)
            if 'alignment padding' in line and '.short' in line:
                continue
            clean_lines.append(line)

        # Second pass: insert section directives BEFORE each .global _FUN_
        # This places the .section after any .balign/.short padding, so the
        # padding stays in the previous section and the new section starts
        # exactly at the function label.
        new_lines = []
        for line in clean_lines:
            gm = re.search(r'\.global\s+_(FUN_[0-9A-Fa-f]+)', line)
            if gm:
                fun_name = gm.group(1)
                if fun_name.upper() not in sub_entries:
                    section_directive = '    ".section .text.%s, \\"ax\\"\\n"\n' % fun_name
                    new_lines.append(section_directive)
            new_lines.append(line)

        new_content = '\n'.join(new_lines)

        if new_content != original:
            changes[filepath] = new_content

    return changes


def generate_trampolines(overflows_needing_trampoline, reverse_map):
    """Generate trampolines.s with jump stubs for overflowing functions.

    Each trampoline is placed in .text.trampoline_FUN_XXXX section.
    The linker script maps this section to the original address.
    The trampoline loads the real function address and jumps to it.
    """
    lines = []
    lines.append('! trampolines.s -- Auto-generated trampoline stubs')
    lines.append('! Redirects from original addresses to overflow area')
    lines.append('! Generated by tools/gen_fixed_layout.py')
    lines.append('')

    for fun_name, orig_addr, orig_size, our_size in overflows_needing_trampoline:
        if orig_size < TRAMPOLINE_SIZE:
            # Too small for trampoline -- generate original bytes (rts; nop)
            lines.append('    .section .text.trampoline_%s, "ax"' % fun_name)
            lines.append('    .balign 2')
            # 4-byte stub: rts; nop
            lines.append('    .word 0x000B  ! rts')
            lines.append('    .word 0x0009  ! nop')
            lines.append('')
            continue

        # Determine the real function name to jump to
        upper_name = fun_name.upper()
        if upper_name in reverse_map:
            target = '_' + reverse_map[upper_name]
        else:
            target = '_' + fun_name

        lines.append('    .section .text.trampoline_%s, "ax"' % fun_name)
        lines.append('    .balign 4')
        lines.append('    ! Trampoline: %s @ 0x%08X (orig=%d, ours=%d)' % (
            fun_name, orig_addr, orig_size, our_size))
        lines.append('    mov.l 1f, r0')
        lines.append('    jmp @r0')
        lines.append('    nop')
        lines.append('    .align 2')
        lines.append('1:  .long %s' % target)
        lines.append('')

    return '\n'.join(lines) + '\n'


def main():
    dry_run = '--dry-run' in sys.argv

    # Allow specifying an alternate ELF for sizing (e.g., from a sequential build)
    elf_override = None
    for arg in sys.argv[1:]:
        if arg.startswith('--elf='):
            elf_override = arg[6:]

    print("=== gen_fixed_layout.py ===")
    print()

    # Step 1: Parse function symbols
    print("Parsing function symbols...")
    syms = parse_syms()
    known_addrs = {addr for addr, name in syms}
    print("  %d functions from aprog_syms.txt, range 0x%08X-0x%08X" % (
        len(syms), syms[0][0], syms[-1][0]))

    # Step 1b: Scan source files for extra FUN_ addresses not in aprog_syms.txt
    print("Scanning source files for extra FUN_ addresses...")
    extra_syms = scan_extra_fun_addrs(known_addrs)
    if extra_syms:
        print("  %d extra FUN_ addresses found in source code" % len(extra_syms))
    else:
        print("  No extra FUN_ addresses found")

    # Keep original syms separate for sub-entry detection (extra FUN_ addresses
    # are always independent functions, not sub-entries)
    orig_syms = list(syms)
    syms = sorted(set(syms) | set(extra_syms))

    orig_sizes = compute_sizes(syms)

    # Step 2: Find ASM imports
    print("Finding ASM imports...")
    asm_globals = find_asm_globals()
    print("  %d ASM-imported functions" % len(asm_globals))

    # Step 3: Get compiled sizes from ELF
    elf_path = elf_override or ELF_PATH
    print("Reading compiled function sizes from ELF: %s" % elf_path)
    elf_sizes = get_elf_func_sizes(elf_path)
    if not elf_sizes:
        print("  ERROR: No function sizes found! Build with sequential layout first.")
        return 1
    print("  %d function symbols in ELF" % len(elf_sizes))

    # Step 4: Build C function name mappings (alias-based)
    print("Scanning C source for function name mappings...")
    alias_map, reverse_map = build_c_func_map()
    print("  %d renamed functions with aliases" % len(alias_map))

    # Step 4a: Scan for broader named → FUN_ context mappings
    print("Scanning for named → FUN_ context mappings...")
    context_map = scan_named_context_map()
    # Merge context map into reverse_map (alias takes priority)
    context_added = 0
    for named, fun in context_map.items():
        if fun not in reverse_map:
            reverse_map[fun] = named
            alias_map[named] = fun
            context_added += 1
    print("  %d context mappings found, %d new (merged into alias map)" % (
        len(context_map), context_added))

    # Step 4b: Sub-entry detection disabled -- the asm file patching introduces
    # blank lines that break the .balign detection heuristic. Empty sections for
    # true sub-entries are harmless (linker creates a zero-size section at the
    # parent's address). Better to have a few empty sections than to miss placing
    # functions correctly.
    print("Sub-entry detection: DISABLED (empty sections are harmless)")
    sub_entries = set()

    # Step 5: Find overflows
    print("Analyzing function size overflows...")
    overflows = find_overflows(orig_sizes, asm_globals, elf_sizes, reverse_map)
    print("  %d C functions overflow their original slot" % len(overflows))

    # Step 6: ALL overflow functions get trampolines
    #
    # Previously, only overflows referenced by ASM constant pools got trampolines.
    # This was wrong: start.s wasn't scanned, and the "free overflow" functions
    # left empty sections at their original addresses — unreachable dead zones.
    # A trampoline is only 10 bytes and sits in otherwise-unused space.
    # CLASS 3 FIX: every overflow function gets a trampoline. No exceptions.
    print("All %d overflow functions will get trampolines (Class 3 fix)..." % len(overflows))

    overflows_needing_trampoline = list(overflows)
    overflows_free = []

    tiny_trampolines = [o for o in overflows_needing_trampoline if o[2] < TRAMPOLINE_SIZE]
    if tiny_trampolines:
        print("  %d have slots too small for trampoline (<10 bytes) -- will use rts;nop stub" %
              len(tiny_trampolines))
        for name, addr, orig_sz, our_sz in tiny_trampolines:
            print("    %s @ 0x%08X: orig=%d ours=%d" % (name, addr, orig_sz, our_sz))

    print()

    # Step 7: Generate linker script
    print("Generating fixed-address linker script...")
    ld_content = generate_linker_script(
        syms, orig_sizes, asm_globals,
        overflows_needing_trampoline, overflows_free,
        alias_map, reverse_map, sub_entries
    )

    if dry_run:
        print("  [DRY RUN] Would write %s (%d bytes)" % (LD_OUTPUT, len(ld_content)))
    else:
        with open(LD_OUTPUT, 'w', newline='\n') as f:
            f.write(ld_content)
        print("  Wrote %s (%d bytes)" % (LD_OUTPUT, len(ld_content)))

    # Step 8: Patch ASM files with section directives
    print("Patching ASM files with section directives...")
    asm_patches = patch_asm_files(sub_entries)
    for filepath, content in asm_patches.items():
        if dry_run:
            print("  [DRY RUN] Would patch %s" % os.path.basename(filepath))
        else:
            with open(filepath, 'w', newline='\n') as f:
                f.write(content)
            print("  Patched %s" % os.path.basename(filepath))

    # Step 9: Generate trampolines
    if overflows_needing_trampoline:
        print("Generating trampolines...")
        trampoline_content = generate_trampolines(overflows_needing_trampoline, reverse_map)
        if dry_run:
            print("  [DRY RUN] Would write %s" % TRAMPOLINE_OUTPUT)
        else:
            with open(TRAMPOLINE_OUTPUT, 'w', newline='\n') as f:
                f.write(trampoline_content)
            print("  Wrote %s (%d trampolines)" % (
                TRAMPOLINE_OUTPUT, len(overflows_needing_trampoline)))
    else:
        print("No trampolines needed.")

    print()
    print("=== DONE ===")
    print()
    print("Next steps:")
    print("  1. Add -ffunction-sections to CFLAGS in reimpl/Makefile")
    print("  2. Change linker script from saturn.ld to saturn_fixed.ld")
    print("  3. make clean && make")
    print()

    return 0


if __name__ == "__main__":
    sys.exit(main())
