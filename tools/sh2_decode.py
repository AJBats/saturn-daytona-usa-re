#!/usr/bin/env python3
"""Decode SH-2 .byte pairs from retail .s files into mnemonics.
Used for L3 uplift research. Reads one consolidated retail file and
produces a mapping of addresses to mnemonics + pool references."""

import re, sys, struct

def _hex_imm(val):
    """Format a signed immediate as hex: #0x4, #-0x1, #0x80."""
    if val < 0:
        return f"#-0x{-val:X}"
    return f"#0x{val:X}"

def decode_sh2(opcode, pc):
    """Decode a 16-bit SH-2 opcode. Returns (mnemonic, pool_target_or_None)."""
    hi = (opcode >> 12) & 0xF
    lo = opcode & 0xF
    rn = (opcode >> 8) & 0xF
    rm = (opcode >> 4) & 0xF

    if opcode == 0x0009: return "nop", None
    if opcode == 0x000B: return "rts", None
    if opcode == 0x0008: return "clrt", None
    if opcode == 0x0018: return "sett", None
    if opcode == 0x0019: return "div0u", None
    if opcode == 0x001B: return "sleep", None
    if opcode == 0x002B: return "rte", None
    if opcode == 0x000A: return "sts mach, r0", None
    if opcode == 0x001A: return "sts macl, r0", None
    if opcode == 0x0028: return "clrmac", None

    # 0000nnnn00001010 = sts mach, Rn
    if hi == 0 and lo == 0xA and rm == 0:
        return f"sts mach, r{rn}", None
    # 0000nnnn00011010 = sts macl, Rn
    if hi == 0 and lo == 0xA and rm == 1:
        return f"sts macl, r{rn}", None
    # 0000nnnn00101010 = sts pr, Rn
    if hi == 0 and lo == 0xA and rm == 2:
        return f"sts pr, r{rn}", None
    # 0000nnnn00101001 = movt Rn
    if hi == 0 and lo == 9 and rm == 2:
        return f"movt r{rn}", None
    # 0000nnnn00000010 = stc sr, Rn
    if hi == 0 and lo == 2 and rm == 0:
        return f"stc sr, r{rn}", None
    # 0000nnnn00010010 = stc gbr, Rn
    if hi == 0 and lo == 2 and rm == 1:
        return f"stc gbr, r{rn}", None
    # 0000nnnn00100010 = stc vbr, Rn
    if hi == 0 and lo == 2 and rm == 2:
        return f"stc vbr, r{rn}", None
    # 0000mmmm00000011 = bsrf Rm (delayed branch)
    if hi == 0 and lo == 3 and rm == 0:
        return f"bsrf r{rn}", None
    # 0000mmmm00100011 = braf Rm (delayed branch)
    if hi == 0 and lo == 3 and rm == 2:
        return f"braf r{rn}", None

    # mov.l Rm, @(disp,Rn): 0001nnnnmmmmdddd
    if hi == 1:
        disp = lo
        return f"mov.l r{rm}, @({disp * 4}, r{rn})", None

    # 0010 group
    if hi == 2:
        if lo == 0: return f"mov.b r{rm}, @r{rn}", None
        if lo == 1: return f"mov.w r{rm}, @r{rn}", None
        if lo == 2: return f"mov.l r{rm}, @r{rn}", None
        if lo == 4: return f"mov.b r{rm}, @-r{rn}", None
        if lo == 5: return f"mov.w r{rm}, @-r{rn}", None
        if lo == 6: return f"mov.l r{rm}, @-r{rn}", None
        if lo == 7: return f"div0s r{rm}, r{rn}", None
        if lo == 8: return f"tst r{rm}, r{rn}", None
        if lo == 9: return f"and r{rm}, r{rn}", None
        if lo == 0xA: return f"xor r{rm}, r{rn}", None
        if lo == 0xB: return f"or r{rm}, r{rn}", None
        if lo == 0xC: return f"cmp/str r{rm}, r{rn}", None
        if lo == 0xD: return f"xtrct r{rm}, r{rn}", None
        if lo == 0xE: return f"mulu.w r{rm}, r{rn}", None
        if lo == 0xF: return f"muls.w r{rm}, r{rn}", None

    # 0011 group
    if hi == 3:
        if lo == 0: return f"cmp/eq r{rm}, r{rn}", None
        if lo == 2: return f"cmp/hs r{rm}, r{rn}", None
        if lo == 3: return f"cmp/ge r{rm}, r{rn}", None
        if lo == 4: return f"div1 r{rm}, r{rn}", None
        if lo == 5: return f"dmulu.l r{rm}, r{rn}", None
        if lo == 6: return f"cmp/hi r{rm}, r{rn}", None
        if lo == 7: return f"cmp/gt r{rm}, r{rn}", None
        if lo == 8: return f"sub r{rm}, r{rn}", None
        if lo == 0xA: return f"subc r{rm}, r{rn}", None
        if lo == 0xB: return f"subv r{rm}, r{rn}", None
        if lo == 0xC: return f"add r{rm}, r{rn}", None
        if lo == 0xD: return f"dmuls.l r{rm}, r{rn}", None
        if lo == 0xE: return f"addc r{rm}, r{rn}", None
        if lo == 0xF: return f"addv r{rm}, r{rn}", None

    # 0100 group
    if hi == 4:
        sub = opcode & 0xFF
        if sub == 0x0B: return f"jsr @r{rn}", None
        if sub == 0x2B: return f"jmp @r{rn}", None
        if sub == 0x00: return f"shll r{rn}", None
        if sub == 0x01: return f"shlr r{rn}", None
        if sub == 0x04: return f"rotl r{rn}", None
        if sub == 0x05: return f"rotr r{rn}", None
        if sub == 0x08: return f"shll2 r{rn}", None
        if sub == 0x09: return f"shlr2 r{rn}", None
        if sub == 0x10: return f"dt r{rn}", None
        if sub == 0x11: return f"cmp/pz r{rn}", None
        if sub == 0x15: return f"cmp/pl r{rn}", None
        if sub == 0x18: return f"shll8 r{rn}", None
        if sub == 0x19: return f"shlr8 r{rn}", None
        if sub == 0x20: return f"shal r{rn}", None
        if sub == 0x21: return f"shar r{rn}", None
        if sub == 0x24: return f"rotcl r{rn}", None
        if sub == 0x25: return f"rotcr r{rn}", None
        if sub == 0x1B: return f"tas.b @r{rn}", None
        if sub == 0x28: return f"shll16 r{rn}", None
        if sub == 0x29: return f"shlr16 r{rn}", None
        # sts.l system_reg, @-Rn (push)
        if lo == 0x2 and rm == 0x0: return f"sts.l mach, @-r{rn}", None
        if lo == 0x2 and rm == 0x1: return f"sts.l macl, @-r{rn}", None
        if lo == 0x2 and rm == 0x2: return f"sts.l pr, @-r{rn}", None
        # lds.l @Rm+, system_reg (pop)
        if lo == 0x6 and rm == 0x0: return f"lds.l @r{rn}+, mach", None
        if lo == 0x6 and rm == 0x1: return f"lds.l @r{rn}+, macl", None
        if lo == 0x6 and rm == 0x2: return f"lds.l @r{rn}+, pr", None
        # lds Rm, system_reg (register)
        if lo == 0xA and rm == 0x0: return f"lds r{rn}, mach", None
        if lo == 0xA and rm == 0x1: return f"lds r{rn}, macl", None
        if lo == 0xA and rm == 0x2: return f"lds r{rn}, pr", None
        # stc.l control_reg, @-Rn (push)
        if lo == 0x3 and rm == 0x0: return f"stc.l sr, @-r{rn}", None
        if lo == 0x3 and rm == 0x1: return f"stc.l gbr, @-r{rn}", None
        if lo == 0x3 and rm == 0x2: return f"stc.l vbr, @-r{rn}", None
        # ldc.l @Rm+, control_reg (pop)
        if lo == 0x7 and rm == 0x0: return f"ldc.l @r{rn}+, sr", None
        if lo == 0x7 and rm == 0x1: return f"ldc.l @r{rn}+, gbr", None
        if lo == 0x7 and rm == 0x2: return f"ldc.l @r{rn}+, vbr", None
        # ldc Rm, control_reg (register)
        if lo == 0xE and rm == 0x0: return f"ldc r{rn}, sr", None
        if lo == 0xE and rm == 0x1: return f"ldc r{rn}, gbr", None
        if lo == 0xE and rm == 0x2: return f"ldc r{rn}, vbr", None
        # shad/shld
        if lo == 0xC: return f"shad r{rm}, r{rn}", None
        if lo == 0xD: return f"shld r{rm}, r{rn}", None
        # mac.w @Rm+, @Rn+
        if lo == 0xF: return f"mac.w @r{rm}+, @r{rn}+", None

    # 0101 group: mov.l @(disp,Rm),Rn
    if hi == 5:
        disp = lo
        return f"mov.l @({disp * 4}, r{rm}), r{rn}", None

    # 0110 group
    if hi == 6:
        if lo == 0: return f"mov.b @r{rm}, r{rn}", None
        if lo == 1: return f"mov.w @r{rm}, r{rn}", None
        if lo == 2: return f"mov.l @r{rm}, r{rn}", None
        if lo == 3: return f"mov r{rm}, r{rn}", None
        if lo == 4: return f"mov.b @r{rm}+, r{rn}", None
        if lo == 5: return f"mov.w @r{rm}+, r{rn}", None
        if lo == 6: return f"mov.l @r{rm}+, r{rn}", None
        if lo == 7: return f"not r{rm}, r{rn}", None
        if lo == 8: return f"swap.b r{rm}, r{rn}", None
        if lo == 9: return f"swap.w r{rm}, r{rn}", None
        if lo == 0xA: return f"negc r{rm}, r{rn}", None
        if lo == 0xB: return f"neg r{rm}, r{rn}", None
        if lo == 0xC: return f"extu.b r{rm}, r{rn}", None
        if lo == 0xD: return f"extu.w r{rm}, r{rn}", None
        if lo == 0xE: return f"exts.b r{rm}, r{rn}", None
        if lo == 0xF: return f"exts.w r{rm}, r{rn}", None

    # 0111: add #imm, Rn
    if hi == 7:
        imm = opcode & 0xFF
        if imm > 127: imm -= 256
        return f"add {_hex_imm(imm)}, r{rn}", None

    # 1000 group
    if hi == 8:
        sub = (opcode >> 8) & 0xF
        if sub == 0: # mov.b R0, @(disp, Rn)
            disp = opcode & 0xF
            return f"mov.b r0, @({disp}, r{rm})", None
        if sub == 1: # mov.w R0, @(disp, Rn)
            disp = opcode & 0xF
            return f"mov.w r0, @({disp * 2}, r{rm})", None
        if sub == 4: # mov.b @(disp, Rm), R0
            disp = opcode & 0xF
            return f"mov.b @({disp}, r{rm}), r0", None
        if sub == 5: # mov.w @(disp, Rm), R0
            disp = opcode & 0xF
            return f"mov.w @({disp * 2}, r{rm}), r0", None
        if sub == 8: # cmp/eq #imm, R0
            imm = opcode & 0xFF
            if imm > 127: imm -= 256
            return f"cmp/eq {_hex_imm(imm)}, r0", None
        if sub == 9: # bt
            disp = opcode & 0xFF
            if disp > 127: disp -= 256
            target = pc + 4 + disp * 2
            return f"bt 0x{target:08X}", None
        if sub == 0xB: # bf
            disp = opcode & 0xFF
            if disp > 127: disp -= 256
            target = pc + 4 + disp * 2
            return f"bf 0x{target:08X}", None
        if sub == 0xD: # bt/s
            disp = opcode & 0xFF
            if disp > 127: disp -= 256
            target = pc + 4 + disp * 2
            return f"bt/s 0x{target:08X}", None
        if sub == 0xF: # bf/s
            disp = opcode & 0xFF
            if disp > 127: disp -= 256
            target = pc + 4 + disp * 2
            return f"bf/s 0x{target:08X}", None

    # 1001: mov.w @(disp,PC),Rn
    if hi == 9:
        disp = opcode & 0xFF
        target = pc + 4 + disp * 2
        return f"mov.w @(0x{target:08X}), r{rn}", target

    # 1010: bra
    if hi == 0xA:
        disp = opcode & 0xFFF
        if disp > 0x7FF: disp -= 0x1000
        target = pc + 4 + disp * 2
        return f"bra 0x{target:08X}", None

    # 1011: bsr
    if hi == 0xB:
        disp = opcode & 0xFFF
        if disp > 0x7FF: disp -= 0x1000
        target = pc + 4 + disp * 2
        return f"bsr 0x{target:08X}", None

    # 1100 group
    if hi == 0xC:
        sub = (opcode >> 8) & 0xF
        if sub == 0: return f"mov.b r0, @({opcode & 0xFF}, gbr)", None
        if sub == 1: return f"mov.w r0, @({(opcode & 0xFF) * 2}, gbr)", None
        if sub == 2: return f"mov.l r0, @({(opcode & 0xFF) * 4}, gbr)", None
        if sub == 4: return f"mov.b @({opcode & 0xFF}, gbr), r0", None
        if sub == 5: return f"mov.w @({(opcode & 0xFF) * 2}, gbr), r0", None
        if sub == 6: return f"mov.l @({(opcode & 0xFF) * 4}, gbr), r0", None
        if sub == 3: return f"trapa #0x{opcode & 0xFF:X}", None
        if sub == 7: # mova @(disp,PC), R0
            disp = opcode & 0xFF
            target = (pc & 0xFFFFFFFC) + 4 + disp * 4
            return f"mova @(0x{target:08X}), r0", target
        if sub == 8: return f"tst #0x{opcode & 0xFF:X}, r0", None
        if sub == 9: return f"and #0x{opcode & 0xFF:X}, r0", None
        if sub == 0xA: return f"xor #0x{opcode & 0xFF:X}, r0", None
        if sub == 0xB: return f"or #0x{opcode & 0xFF:X}, r0", None
        if sub == 0xC: return f"tst.b #0x{opcode & 0xFF:X}, @(r0, gbr)", None
        if sub == 0xD: return f"and.b #0x{opcode & 0xFF:X}, @(r0, gbr)", None
        if sub == 0xE: return f"xor.b #0x{opcode & 0xFF:X}, @(r0, gbr)", None
        if sub == 0xF: return f"or.b #0x{opcode & 0xFF:X}, @(r0, gbr)", None

    # 1101: mov.l @(disp,PC),Rn
    if hi == 0xD:
        disp = opcode & 0xFF
        target = (pc & 0xFFFFFFFC) + 4 + disp * 4
        return f"mov.l @(0x{target:08X}), r{rn}", target

    # 1110: mov #imm, Rn
    if hi == 0xE:
        imm = opcode & 0xFF
        if imm > 127: imm -= 256
        return f"mov {_hex_imm(imm)}, r{rn}", None

    # 0000 group misc
    if hi == 0:
        if lo == 4: return f"mov.b r{rm}, @(r0, r{rn})", None
        if lo == 5: return f"mov.w r{rm}, @(r0, r{rn})", None
        if lo == 6: return f"mov.l r{rm}, @(r0, r{rn})", None
        if lo == 7: return f"mul.l r{rm}, r{rn}", None
        if lo == 0xC: return f"mov.b @(r0, r{rm}), r{rn}", None
        if lo == 0xD: return f"mov.w @(r0, r{rm}), r{rn}", None
        if lo == 0xE: return f"mov.l @(r0, r{rm}), r{rn}", None
        if lo == 0xF: return f"mac.l @r{rm}+, @r{rn}+", None

    return f".word 0x{opcode:04X} /* UNKNOWN */", None


def parse_retail_file(filepath):
    """Parse a retail .s file, extracting sections with their bytes."""
    sections = []
    current_section = None
    current_bytes = bytearray()
    current_globals = []

    with open(filepath, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('/*') or line.startswith('*') or line.startswith(' *'):
                continue

            m = re.match(r'\.section\s+\.text\.(FUN_([0-9A-Fa-f]+))', line)
            if m:
                if current_section:
                    sections.append((current_section, current_bytes, current_globals))
                current_section = int(m.group(2), 16)
                current_bytes = bytearray()
                current_globals = []
                continue

            m = re.match(r'\.global\s+(\S+)', line)
            if m:
                name = m.group(1)
                offset = len(current_bytes)
                current_globals.append((offset, name))
                continue

            if line.startswith('.type') or ':' in line and not line.startswith('.'):
                continue

            m = re.match(r'\.byte\s+0x([0-9A-Fa-f]+)\s*,\s*0x([0-9A-Fa-f]+)', line)
            if m:
                current_bytes.append(int(m.group(1), 16))
                current_bytes.append(int(m.group(2), 16))
                continue

            m = re.match(r'\.4byte\s+(\S+)', line)
            if m:
                sym = m.group(1)
                # Mark as 4-byte symbol ref (placeholder bytes)
                offset = len(current_bytes)
                current_bytes.extend(b'\x00\x00\x00\x00')  # placeholder
                current_globals.append((offset, f"__4byte__{sym}"))
                continue

    if current_section:
        sections.append((current_section, current_bytes, current_globals))
    return sections


def disassemble_sections(sections):
    """Disassemble all sections and identify pool targets."""
    pool_targets = {}  # address -> label or value
    all_branch_targets = set()

    # First pass: identify all pool loads and branch targets
    for base_addr, data, globals_list in sections:
        # Build a map of 4byte references
        fourbyte_map = {}
        for off, name in globals_list:
            if name.startswith("__4byte__"):
                fourbyte_map[off] = name[9:]  # strip prefix

        i = 0
        while i < len(data) - 1:
            pc = base_addr + i
            opcode = (data[i] << 8) | data[i + 1]
            mnemonic, target = decode_sh2(opcode, pc)

            if target is not None:
                pool_targets[target] = None  # will resolve later

            if 'bf ' in mnemonic or 'bt ' in mnemonic or 'bra ' in mnemonic or 'bsr ' in mnemonic:
                if 'bf/s' in mnemonic or 'bt/s' in mnemonic:
                    m = re.search(r'0x([0-9A-Fa-f]+)', mnemonic)
                else:
                    m = re.search(r'0x([0-9A-Fa-f]+)', mnemonic)
                if m:
                    all_branch_targets.add(int(m.group(1), 16))

            i += 2

    # Resolve pool targets
    for target_addr in pool_targets:
        for base_addr, data, globals_list in sections:
            end_addr = base_addr + len(data)
            if base_addr <= target_addr < end_addr:
                off = target_addr - base_addr
                # Check if this is a .4byte symbol
                fourbyte_map = {}
                for goff, name in globals_list:
                    if name.startswith("__4byte__"):
                        fourbyte_map[goff] = name[9:]
                if off in fourbyte_map:
                    pool_targets[target_addr] = ('sym', fourbyte_map[off])
                else:
                    # Read 4 bytes as literal
                    if off + 4 <= len(data):
                        val = struct.unpack('>I', data[off:off+4])[0]
                        pool_targets[target_addr] = ('lit', val)
                    else:
                        pool_targets[target_addr] = ('unknown', off)

    # Second pass: print disassembly
    print("=" * 70)
    print("DISASSEMBLY")
    print("=" * 70)

    for base_addr, data, globals_list in sections:
        print(f"\n--- Section .text.FUN_{base_addr:08X} ({len(data)} bytes) ---")

        # Build maps
        global_labels = {}
        fourbyte_map = {}
        for off, name in globals_list:
            if name.startswith("__4byte__"):
                fourbyte_map[off] = name[9:]
            else:
                global_labels[off] = name

        i = 0
        while i < len(data):
            pc = base_addr + i

            # Print any labels at this offset
            if i in global_labels:
                name = global_labels[i]
                print(f"\n    .global {name}")
                print(f"{name}:")

            # Check if this is in the branch targets
            if pc in all_branch_targets:
                print(f"  .L_{pc:08X}:")

            # Check if this is a pool target (data, not code)
            if pc in pool_targets:
                val = pool_targets[pc]
                if val and val[0] == 'sym':
                    print(f"  0x{pc:08X}: .4byte {val[1]}  /* pool entry */")
                    i += 4
                    continue
                elif val and val[0] == 'lit':
                    print(f"  0x{pc:08X}: .4byte 0x{val[1]:08X}  /* literal {val[1]} */")
                    i += 4
                    continue

            # Check for .4byte in source
            if i in fourbyte_map:
                sym = fourbyte_map[i]
                print(f"  0x{pc:08X}: .4byte {sym}")
                i += 4
                continue

            if i + 1 >= len(data):
                print(f"  0x{pc:08X}: .byte 0x{data[i]:02X}  /* trailing byte */")
                i += 1
                continue

            opcode = (data[i] << 8) | data[i + 1]
            mnemonic, target = decode_sh2(opcode, pc)

            # Annotate pool references
            annotation = ""
            if target is not None and target in pool_targets:
                val = pool_targets[target]
                if val and val[0] == 'sym':
                    annotation = f"  /* -> {val[1]} */"
                elif val and val[0] == 'lit':
                    annotation = f"  /* -> 0x{val[1]:08X} ({val[1]}) */"

            print(f"  0x{pc:08X}: {mnemonic}{annotation}")
            i += 2

    # Print pool summary
    print("\n" + "=" * 70)
    print("POOL ENTRY SUMMARY")
    print("=" * 70)
    for addr in sorted(pool_targets.keys()):
        val = pool_targets[addr]
        if val:
            if val[0] == 'sym':
                print(f"  0x{addr:08X}: .4byte {val[1]}")
            elif val[0] == 'lit':
                print(f"  0x{addr:08X}: .4byte 0x{val[1]:08X} ({val[1]})")
            else:
                print(f"  0x{addr:08X}: {val}")

    print(f"\nBranch targets: {sorted([f'0x{x:08X}' for x in all_branch_targets])}")


if __name__ == '__main__':
    filepath = sys.argv[1] if len(sys.argv) > 1 else 'reimpl/retail/ai_rotation_helpers.s'
    sections = parse_retail_file(filepath)
    print(f"Parsed {len(sections)} sections")
    for addr, data, globs in sections:
        labels = [n for _, n in globs if not n.startswith('__4byte__')]
        print(f"  0x{addr:08X}: {len(data)} bytes, globals: {labels}")
    disassemble_sections(sections)
