"""
split_binary.py - Convert APROG.BIN into a re-assemblable GAS-syntax .s file for SH-2.

This script reads the raw SH-2 binary and produces:
  1. aprog.s       - GAS assembly source using .byte pairs for every byte in the binary.
                     Function boundaries are marked with labels. Known instruction
                     patterns are annotated in comments for readability.
  2. aprog_syms.txt - Symbol file listing all detected function addresses.
  3. aprog.ld      - Minimal linker script that places .text at 0x06003000.

Design rationale:
  - Every byte is emitted literally via .byte 0xHI, 0xLO pairs, guaranteeing a
    byte-identical round-trip regardless of assembler endianness settings.
  - Function boundaries are detected by scanning for the two standard SH-2 GCC
    prologue patterns (mov.l r14,@-r15 = 0x2FE6, sts.l pr,@-r15 = 0x4F22).
  - Each function gets a global label (e.g. FUN_060030FC:) that can be referenced
    by other translation units or by the linker script.
  - Comments decode a subset of well-known SH-2 instructions for human readability.
    This is purely cosmetic and does not affect the assembled output.

Usage:
    python scripts/split_binary.py

Inputs:
    build/disc/files/APROG.BIN

Outputs:
    build/aprog.s
    build/aprog_syms.txt
    build/aprog.ld
"""

import os
import struct
import sys
import time

# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
PROJECT_DIR = os.path.join(SCRIPT_DIR, "..")

APROG_BIN = os.path.join(PROJECT_DIR, "build", "disc", "files", "APROG.BIN")
OUTPUT_ASM = os.path.join(PROJECT_DIR, "build", "aprog.s")
OUTPUT_SYMS = os.path.join(PROJECT_DIR, "build", "aprog_syms.txt")
OUTPUT_LD = os.path.join(PROJECT_DIR, "build", "aprog.ld")

BASE_ADDR = 0x06003000

# SH-2 register names (for comment decoding)
SH2_REGS = ["r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
            "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"]


# ---------------------------------------------------------------------------
# SH-2 instruction decoder (for comments only -- does NOT affect output bytes)
# ---------------------------------------------------------------------------

def decode_sh2_insn(word, addr, data, file_offset, file_len):
    """
    Attempt to decode a 16-bit SH-2 instruction into a human-readable mnemonic
    string.  Returns None if the pattern is not recognized (the caller will
    fall back to a plain hex comment).

    This is intentionally partial -- we only decode the most useful patterns
    for navigating the disassembly.  Correctness of *output bytes* does not
    depend on this function at all.
    """
    hi4 = (word >> 12) & 0xF
    lo4 = word & 0xF
    lo8 = word & 0xFF
    hi8 = (word >> 8) & 0xFF
    rn = (word >> 8) & 0xF
    rm = (word >> 4) & 0xF

    # ---- 0000 nnnn mmmm 0111  mul.l Rm, Rn
    # ---- Special opcodes in 0x0xxx range
    if word == 0x0009:
        return "nop"
    if word == 0x000B:
        return "rts"
    if word == 0x0019:
        return "div0u"
    if word == 0x002B:
        return "rte"
    if word == 0x0008:
        return "clrt"
    if word == 0x0018:
        return "sett"
    if word == 0x0028:
        return "clrmac"
    if word == 0x0038:
        return "ldtlb"
    if word == 0x0048:
        return "clrs"
    if word == 0x0058:
        return "sets"

    # ---- mov.l Rm,@-Rn  (0010 nnnn mmmm 0110)
    if hi4 == 0x2 and lo4 == 0x6:
        return "mov.l %s,@-%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.l @Rm+,Rn  (0110 nnnn mmmm 0110)
    if hi4 == 0x6 and lo4 == 0x6:
        return "mov.l @%s+,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.l Rm,@Rn  (0010 nnnn mmmm 0010)
    if hi4 == 0x2 and lo4 == 0x2:
        return "mov.l %s,@%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov Rm,Rn  (0110 nnnn mmmm 0011)
    if hi4 == 0x6 and lo4 == 0x3:
        return "mov %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov #imm,Rn  (1110 nnnn iiii iiii)
    if hi4 == 0xE:
        imm = lo8
        if imm & 0x80:
            imm -= 256
        return "mov #%d,%s" % (imm, SH2_REGS[rn])

    # ---- add Rm,Rn  (0011 nnnn mmmm 1100)
    if hi4 == 0x3 and lo4 == 0xC:
        return "add %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- add #imm,Rn  (0111 nnnn iiii iiii)
    if hi4 == 0x7:
        imm = lo8
        if imm & 0x80:
            imm -= 256
        return "add #%d,%s" % (imm, SH2_REGS[rn])

    # ---- cmp/eq #imm,r0 (1000 1000 iiii iiii)
    if hi8 == 0x88:
        imm = lo8
        if imm & 0x80:
            imm -= 256
        return "cmp/eq #%d,r0" % imm

    # ---- cmp/eq Rm,Rn  (0011 nnnn mmmm 0000)
    if hi4 == 0x3 and lo4 == 0x0:
        return "cmp/eq %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- cmp/hs Rm,Rn  (0011 nnnn mmmm 0010)
    if hi4 == 0x3 and lo4 == 0x2:
        return "cmp/hs %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- cmp/ge Rm,Rn  (0011 nnnn mmmm 0011)
    if hi4 == 0x3 and lo4 == 0x3:
        return "cmp/ge %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- cmp/gt Rm,Rn  (0011 nnnn mmmm 0111)
    if hi4 == 0x3 and lo4 == 0x7:
        return "cmp/gt %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- cmp/hi Rm,Rn  (0011 nnnn mmmm 0110)
    if hi4 == 0x3 and lo4 == 0x6:
        return "cmp/hi %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- cmp/pl Rn  (0100 nnnn 0001 0101)
    if hi4 == 0x4 and lo8 == 0x15:
        return "cmp/pl %s" % SH2_REGS[rn]

    # ---- cmp/pz Rn  (0100 nnnn 0001 0001)
    if hi4 == 0x4 and lo8 == 0x11:
        return "cmp/pz %s" % SH2_REGS[rn]

    # ---- tst Rm,Rn  (0010 nnnn mmmm 1000)
    if hi4 == 0x2 and lo4 == 0x8:
        return "tst %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- tst #imm,r0  (1100 1000 iiii iiii)
    if hi8 == 0xC8:
        return "tst #0x%02X,r0" % lo8

    # ---- and Rm,Rn  (0010 nnnn mmmm 1001)
    if hi4 == 0x2 and lo4 == 0x9:
        return "and %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- or Rm,Rn  (0010 nnnn mmmm 1011)
    if hi4 == 0x2 and lo4 == 0xB:
        return "or %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- xor Rm,Rn  (0010 nnnn mmmm 1010)
    if hi4 == 0x2 and lo4 == 0xA:
        return "xor %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- not Rm,Rn  (0110 nnnn mmmm 0111)
    if hi4 == 0x6 and lo4 == 0x7:
        return "not %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- neg Rm,Rn  (0110 nnnn mmmm 1011)
    if hi4 == 0x6 and lo4 == 0xB:
        return "neg %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- sub Rm,Rn  (0011 nnnn mmmm 1000)
    if hi4 == 0x3 and lo4 == 0x8:
        return "sub %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- extu.b Rm,Rn  (0110 nnnn mmmm 1100)
    if hi4 == 0x6 and lo4 == 0xC:
        return "extu.b %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- extu.w Rm,Rn  (0110 nnnn mmmm 1101)
    if hi4 == 0x6 and lo4 == 0xD:
        return "extu.w %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- exts.b Rm,Rn  (0110 nnnn mmmm 1110)
    if hi4 == 0x6 and lo4 == 0xE:
        return "exts.b %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- exts.w Rm,Rn  (0110 nnnn mmmm 1111)
    if hi4 == 0x6 and lo4 == 0xF:
        return "exts.w %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- swap.b Rm,Rn  (0110 nnnn mmmm 1000)
    if hi4 == 0x6 and lo4 == 0x8:
        return "swap.b %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- swap.w Rm,Rn  (0110 nnnn mmmm 1001)
    if hi4 == 0x6 and lo4 == 0x9:
        return "swap.w %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- shll Rn  (0100 nnnn 0000 0000)
    if hi4 == 0x4 and lo8 == 0x00:
        return "shll %s" % SH2_REGS[rn]

    # ---- shlr Rn  (0100 nnnn 0000 0001)
    if hi4 == 0x4 and lo8 == 0x01:
        return "shlr %s" % SH2_REGS[rn]

    # ---- shal Rn  (0100 nnnn 0010 0000)
    if hi4 == 0x4 and lo8 == 0x20:
        return "shal %s" % SH2_REGS[rn]

    # ---- shar Rn  (0100 nnnn 0010 0001)
    if hi4 == 0x4 and lo8 == 0x21:
        return "shar %s" % SH2_REGS[rn]

    # ---- shll2 Rn  (0100 nnnn 0000 1000)
    if hi4 == 0x4 and lo8 == 0x08:
        return "shll2 %s" % SH2_REGS[rn]

    # ---- shlr2 Rn  (0100 nnnn 0000 1001)
    if hi4 == 0x4 and lo8 == 0x09:
        return "shlr2 %s" % SH2_REGS[rn]

    # ---- shll8 Rn  (0100 nnnn 0001 1000)
    if hi4 == 0x4 and lo8 == 0x18:
        return "shll8 %s" % SH2_REGS[rn]

    # ---- shlr8 Rn  (0100 nnnn 0001 1001)
    if hi4 == 0x4 and lo8 == 0x19:
        return "shlr8 %s" % SH2_REGS[rn]

    # ---- shll16 Rn  (0100 nnnn 0010 1000)
    if hi4 == 0x4 and lo8 == 0x28:
        return "shll16 %s" % SH2_REGS[rn]

    # ---- shlr16 Rn  (0100 nnnn 0010 1001)
    if hi4 == 0x4 and lo8 == 0x29:
        return "shlr16 %s" % SH2_REGS[rn]

    # ---- rotl Rn  (0100 nnnn 0000 0100)
    if hi4 == 0x4 and lo8 == 0x04:
        return "rotl %s" % SH2_REGS[rn]

    # ---- rotr Rn  (0100 nnnn 0000 0101)
    if hi4 == 0x4 and lo8 == 0x05:
        return "rotr %s" % SH2_REGS[rn]

    # ---- dt Rn  (0100 nnnn 0001 0000)
    if hi4 == 0x4 and lo8 == 0x10:
        return "dt %s" % SH2_REGS[rn]

    # ---- sts.l pr,@-Rn  (0100 nnnn 0010 0010)
    if hi4 == 0x4 and lo8 == 0x22:
        return "sts.l pr,@-%s" % SH2_REGS[rn]

    # ---- lds.l @Rn+,pr  (0100 nnnn 0010 0110)
    if hi4 == 0x4 and lo8 == 0x26:
        return "lds.l @%s+,pr" % SH2_REGS[rn]

    # ---- sts pr,Rn  (0000 nnnn 0010 1010)
    if hi4 == 0x0 and lo8 == 0x2A:
        return "sts pr,%s" % SH2_REGS[rn]

    # ---- lds Rm,pr  (0100 nnnn 0010 1010)
    if hi4 == 0x4 and lo8 == 0x2A:
        return "lds %s,pr" % SH2_REGS[rn]

    # ---- sts.l mach,@-Rn  (0100 nnnn 0000 0010)
    if hi4 == 0x4 and lo8 == 0x02:
        return "sts.l mach,@-%s" % SH2_REGS[rn]

    # ---- sts.l macl,@-Rn  (0100 nnnn 0001 0010)
    if hi4 == 0x4 and lo8 == 0x12:
        return "sts.l macl,@-%s" % SH2_REGS[rn]

    # ---- lds.l @Rn+,mach  (0100 nnnn 0000 0110)
    if hi4 == 0x4 and lo8 == 0x06:
        return "lds.l @%s+,mach" % SH2_REGS[rn]

    # ---- lds.l @Rn+,macl  (0100 nnnn 0001 0110)
    if hi4 == 0x4 and lo8 == 0x16:
        return "lds.l @%s+,macl" % SH2_REGS[rn]

    # ---- jsr @Rn  (0100 nnnn 0000 1011)
    if hi4 == 0x4 and lo8 == 0x0B:
        return "jsr @%s" % SH2_REGS[rn]

    # ---- jmp @Rn  (0100 nnnn 0010 1011)
    if hi4 == 0x4 and lo8 == 0x2B:
        return "jmp @%s" % SH2_REGS[rn]

    # ---- bra disp  (1010 dddd dddd dddd)
    if hi4 == 0xA:
        disp = word & 0xFFF
        if disp & 0x800:
            disp -= 0x1000
        target = addr + 4 + disp * 2
        return "bra 0x%08X" % target

    # ---- bsr disp  (1011 dddd dddd dddd)
    if hi4 == 0xB:
        disp = word & 0xFFF
        if disp & 0x800:
            disp -= 0x1000
        target = addr + 4 + disp * 2
        return "bsr 0x%08X" % target

    # ---- bt disp  (1000 1001 dddd dddd)
    if hi8 == 0x89:
        disp = lo8
        if disp & 0x80:
            disp -= 256
        target = addr + 4 + disp * 2
        return "bt 0x%08X" % target

    # ---- bf disp  (1000 1011 dddd dddd)
    if hi8 == 0x8B:
        disp = lo8
        if disp & 0x80:
            disp -= 256
        target = addr + 4 + disp * 2
        return "bf 0x%08X" % target

    # ---- bt/s disp  (1000 1101 dddd dddd)
    if hi8 == 0x8D:
        disp = lo8
        if disp & 0x80:
            disp -= 256
        target = addr + 4 + disp * 2
        return "bt/s 0x%08X" % target

    # ---- bf/s disp  (1000 1111 dddd dddd)
    if hi8 == 0x8F:
        disp = lo8
        if disp & 0x80:
            disp -= 256
        target = addr + 4 + disp * 2
        return "bf/s 0x%08X" % target

    # ---- mov.l @(disp,PC),Rn  (1101 nnnn dddd dddd)
    if hi4 == 0xD:
        disp = lo8
        pool_addr = (addr & ~3) + 4 + disp * 4
        pool_off = pool_addr - BASE_ADDR
        if 0 <= pool_off <= file_len - 4:
            val = struct.unpack_from(">I", data, pool_off)[0]
            return "mov.l @(0x%X,PC),%s  {[0x%08X] = 0x%08X}" % (
                disp * 4, SH2_REGS[rn], pool_addr, val)
        return "mov.l @(0x%X,PC),%s" % (disp * 4, SH2_REGS[rn])

    # ---- mov.w @(disp,PC),Rn  (1001 nnnn dddd dddd)
    if hi4 == 0x9:
        disp = lo8
        pool_addr = addr + 4 + disp * 2
        return "mov.w @(0x%X,PC),%s" % (disp * 2, SH2_REGS[rn])

    # ---- mov.l @(disp,Rm),Rn  (0101 nnnn mmmm dddd)
    if hi4 == 0x5:
        disp = lo4
        return "mov.l @(0x%X,%s),%s" % (disp * 4, SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.l Rm,@(disp,Rn)  (0001 nnnn mmmm dddd)
    if hi4 == 0x1:
        disp = lo4
        return "mov.l %s,@(0x%X,%s)" % (SH2_REGS[rm], disp * 4, SH2_REGS[rn])

    # ---- mov.w Rm,@Rn  (0010 nnnn mmmm 0001)
    if hi4 == 0x2 and lo4 == 0x1:
        return "mov.w %s,@%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.b Rm,@Rn  (0010 nnnn mmmm 0000)
    if hi4 == 0x2 and lo4 == 0x0:
        return "mov.b %s,@%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.b @Rm,Rn  (0110 nnnn mmmm 0000)
    if hi4 == 0x6 and lo4 == 0x0:
        return "mov.b @%s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.w @Rm,Rn  (0110 nnnn mmmm 0001)
    if hi4 == 0x6 and lo4 == 0x1:
        return "mov.w @%s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.l @Rm,Rn  (0110 nnnn mmmm 0010)
    if hi4 == 0x6 and lo4 == 0x2:
        return "mov.l @%s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.b @Rm+,Rn  (0110 nnnn mmmm 0100)
    if hi4 == 0x6 and lo4 == 0x4:
        return "mov.b @%s+,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.w @Rm+,Rn  (0110 nnnn mmmm 0101)
    if hi4 == 0x6 and lo4 == 0x5:
        return "mov.w @%s+,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.b Rm,@-Rn  (0010 nnnn mmmm 0100)
    if hi4 == 0x2 and lo4 == 0x4:
        return "mov.b %s,@-%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.w Rm,@-Rn  (0010 nnnn mmmm 0101)
    if hi4 == 0x2 and lo4 == 0x5:
        return "mov.w %s,@-%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.b @(R0,Rm),Rn  (0000 nnnn mmmm 1100)
    if hi4 == 0x0 and lo4 == 0xC:
        return "mov.b @(r0,%s),%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.w @(R0,Rm),Rn  (0000 nnnn mmmm 1101)
    if hi4 == 0x0 and lo4 == 0xD:
        return "mov.w @(r0,%s),%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.l @(R0,Rm),Rn  (0000 nnnn mmmm 1110)
    if hi4 == 0x0 and lo4 == 0xE:
        return "mov.l @(r0,%s),%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.b Rm,@(R0,Rn)  (0000 nnnn mmmm 0100)
    if hi4 == 0x0 and lo4 == 0x4:
        return "mov.b %s,@(r0,%s)" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.w Rm,@(R0,Rn)  (0000 nnnn mmmm 0101)
    if hi4 == 0x0 and lo4 == 0x5:
        return "mov.w %s,@(r0,%s)" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.l Rm,@(R0,Rn)  (0000 nnnn mmmm 0110)
    if hi4 == 0x0 and lo4 == 0x6:
        return "mov.l %s,@(r0,%s)" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mov.b R0,@(disp,GBR)  (1100 0000 dddd dddd)
    if hi8 == 0xC0:
        return "mov.b r0,@(0x%X,GBR)" % lo8

    # ---- mov.w R0,@(disp,GBR)  (1100 0001 dddd dddd)
    if hi8 == 0xC1:
        return "mov.w r0,@(0x%X,GBR)" % (lo8 * 2)

    # ---- mov.l R0,@(disp,GBR)  (1100 0010 dddd dddd)
    if hi8 == 0xC2:
        return "mov.l r0,@(0x%X,GBR)" % (lo8 * 4)

    # ---- mov.b @(disp,GBR),R0  (1100 0100 dddd dddd)
    if hi8 == 0xC4:
        return "mov.b @(0x%X,GBR),r0" % lo8

    # ---- mov.w @(disp,GBR),R0  (1100 0101 dddd dddd)
    if hi8 == 0xC5:
        return "mov.w @(0x%X,GBR),r0" % (lo8 * 2)

    # ---- mov.l @(disp,GBR),R0  (1100 0110 dddd dddd)
    if hi8 == 0xC6:
        return "mov.l @(0x%X,GBR),r0" % (lo8 * 4)

    # ---- mova @(disp,PC),R0  (1100 0111 dddd dddd)
    if hi8 == 0xC7:
        disp = lo8
        target = (addr & ~3) + 4 + disp * 4
        return "mova @(0x%X,PC),r0  {0x%08X}" % (disp * 4, target)

    # ---- mul.l Rm,Rn  (0000 nnnn mmmm 0111)
    if hi4 == 0x0 and lo4 == 0x7:
        return "mul.l %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- muls.w Rm,Rn  (0010 nnnn mmmm 1111)
    if hi4 == 0x2 and lo4 == 0xF:
        return "muls.w %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mulu.w Rm,Rn  (0010 nnnn mmmm 1110)
    if hi4 == 0x2 and lo4 == 0xE:
        return "mulu.w %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- dmuls.l Rm,Rn  (0011 nnnn mmmm 1101)
    if hi4 == 0x3 and lo4 == 0xD:
        return "dmuls.l %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- dmulu.l Rm,Rn  (0011 nnnn mmmm 0101)
    if hi4 == 0x3 and lo4 == 0x5:
        return "dmulu.l %s,%s" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mac.l @Rm+,@Rn+  (0000 nnnn mmmm 1111)
    if hi4 == 0x0 and lo4 == 0xF:
        return "mac.l @%s+,@%s+" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- mac.w @Rm+,@Rn+  (0100 nnnn mmmm 1111)
    if hi4 == 0x4 and lo4 == 0xF:
        return "mac.w @%s+,@%s+" % (SH2_REGS[rm], SH2_REGS[rn])

    # ---- sts mach,Rn  (0000 nnnn 0000 1010)
    if hi4 == 0x0 and lo8 == 0x0A:
        return "sts mach,%s" % SH2_REGS[rn]

    # ---- sts macl,Rn  (0000 nnnn 0001 1010)
    if hi4 == 0x0 and lo8 == 0x1A:
        return "sts macl,%s" % SH2_REGS[rn]

    # ---- mov.b R0,@(disp,Rn)  (1000 0000 nnnn dddd)
    if (word >> 12) == 0x8 and ((word >> 8) & 0xF) == 0x0:
        rn2 = (word >> 4) & 0xF
        disp2 = word & 0xF
        return "mov.b r0,@(0x%X,%s)" % (disp2, SH2_REGS[rn2])

    # ---- mov.w R0,@(disp,Rn)  (1000 0001 nnnn dddd)
    if (word >> 12) == 0x8 and ((word >> 8) & 0xF) == 0x1:
        rn2 = (word >> 4) & 0xF
        disp2 = word & 0xF
        return "mov.w r0,@(0x%X,%s)" % (disp2 * 2, SH2_REGS[rn2])

    # ---- mov.b @(disp,Rm),R0  (1000 0100 mmmm dddd)
    if (word >> 12) == 0x8 and ((word >> 8) & 0xF) == 0x4:
        rm2 = (word >> 4) & 0xF
        disp2 = word & 0xF
        return "mov.b @(0x%X,%s),r0" % (disp2, SH2_REGS[rm2])

    # ---- mov.w @(disp,Rm),R0  (1000 0101 mmmm dddd)
    if (word >> 12) == 0x8 and ((word >> 8) & 0xF) == 0x5:
        rm2 = (word >> 4) & 0xF
        disp2 = word & 0xF
        return "mov.w @(0x%X,%s),r0" % (disp2 * 2, SH2_REGS[rm2])

    # ---- mov.l @(disp,GBR),R0 -- handled above

    # ---- trapa #imm  (1100 0011 iiii iiii)
    if hi8 == 0xC3:
        return "trapa #0x%02X" % lo8

    # ---- or #imm,r0  (1100 1011 iiii iiii)
    if hi8 == 0xCB:
        return "or #0x%02X,r0" % lo8

    # ---- and #imm,r0  (1100 1001 iiii iiii)
    if hi8 == 0xC9:
        return "and #0x%02X,r0" % lo8

    # ---- xor #imm,r0  (1100 1010 iiii iiii)
    if hi8 == 0xCA:
        return "xor #0x%02X,r0" % lo8

    # ---- ldc Rm,SR  (0100 mmmm 0000 1110)
    if hi4 == 0x4 and lo8 == 0x0E:
        return "ldc %s,sr" % SH2_REGS[rn]

    # ---- stc SR,Rn  (0000 nnnn 0000 0010)
    if hi4 == 0x0 and lo8 == 0x02:
        return "stc sr,%s" % SH2_REGS[rn]

    # ---- ldc Rm,GBR  (0100 mmmm 0001 1110)
    if hi4 == 0x4 and lo8 == 0x1E:
        return "ldc %s,gbr" % SH2_REGS[rn]

    # ---- stc GBR,Rn  (0000 nnnn 0001 0010)
    if hi4 == 0x0 and lo8 == 0x12:
        return "stc gbr,%s" % SH2_REGS[rn]

    # ---- ldc Rm,VBR  (0100 mmmm 0010 1110)
    if hi4 == 0x4 and lo8 == 0x2E:
        return "ldc %s,vbr" % SH2_REGS[rn]

    # ---- stc VBR,Rn  (0000 nnnn 0010 0010)
    if hi4 == 0x0 and lo8 == 0x22:
        return "stc vbr,%s" % SH2_REGS[rn]

    # ---- sleep  (0000 0000 0001 1011)
    if word == 0x001B:
        return "sleep"

    return None


# ---------------------------------------------------------------------------
# Function boundary detection
# ---------------------------------------------------------------------------

def find_function_entries(data, base_addr):
    """
    Scan for function entry points using prologue patterns.

    Uses the same algorithm as categorize_functions.py for consistency:
      - mov.l r14,@-r15  (0x2FE6)  always starts a new function
      - sts.l pr,@-r15   (0x4F22)  starts a new function UNLESS preceded by
        another register push (mov.l rN,@-r15), in which case it is part of
        the same prologue.

    Returns a sorted list of file offsets (NOT addresses).
    """
    entries = []
    i = 0
    while i < len(data) - 1:
        hi = data[i]
        lo = data[i + 1]

        # mov.l r14,@-r15  = 0x2FE6
        if hi == 0x2F and lo == 0xE6:
            entries.append(i)
            i += 2
            continue

        # sts.l pr,@-r15  = 0x4F22
        if hi == 0x4F and lo == 0x22:
            # Check if preceding instruction was a register push (mov.l rN,@-r15).
            # If so, this is part of the same prologue, not a new function.
            if i >= 2:
                prev_hi = data[i - 2]
                prev_lo = data[i - 1]
                is_push = (prev_hi & 0xF0) == 0x20 and (prev_hi & 0x0F) == 0x0F and (prev_lo & 0x0F) == 0x06
                if is_push:
                    i += 2
                    continue
            entries.append(i)

        i += 2

    return sorted(set(entries))


# ---------------------------------------------------------------------------
# Constant pool scanner (for cross-reference comments)
# ---------------------------------------------------------------------------

def build_constant_pool_xrefs(data, base_addr, func_offsets):
    """
    Scan every mov.l @(disp,PC),Rn instruction and record what 32-bit value
    it loads.  If that value looks like a code address (falls within the known
    address range), record it so we can annotate it as a cross-reference.

    Returns a dict mapping file_offset -> 32-bit value, for pool entries that
    reference code addresses.
    """
    end_addr = base_addr + len(data)
    func_set = set(base_addr + off for off in func_offsets)
    xrefs = {}

    for i in range(0, len(data) - 1, 2):
        word = (data[i] << 8) | data[i + 1]
        if (word >> 12) == 0xD:  # mov.l @(disp,PC),Rn
            disp = word & 0xFF
            insn_addr = base_addr + i
            pool_addr = (insn_addr & ~3) + 4 + disp * 4
            pool_off = pool_addr - base_addr
            if 0 <= pool_off <= len(data) - 4:
                val = struct.unpack_from(">I", data, pool_off)[0]
                if base_addr <= val < end_addr:
                    xrefs[pool_off] = val

    return xrefs


# ---------------------------------------------------------------------------
# Assembly output generation
# ---------------------------------------------------------------------------

def generate_asm(data, base_addr, func_offsets, pool_xrefs, output_path):
    """
    Generate the .s file.

    Every byte pair in the binary becomes a `.byte 0xHI, 0xLO` directive.
    Function boundaries get labels and separator comments.
    Known instruction patterns get mnemonic comments for readability.
    Constant pool entries that reference code addresses get xref comments.
    """
    file_len = len(data)
    end_addr = base_addr + file_len

    # Build a set for O(1) lookup of function boundary offsets
    func_set = set(func_offsets)

    # Build set of function addresses for labeling xrefs
    func_addr_set = set(base_addr + off for off in func_offsets)

    # Pre-compute label names for all functions
    func_labels = {}
    for off in func_offsets:
        addr = base_addr + off
        func_labels[off] = "FUN_%08X" % addr

    # Open output and write header
    total_lines_estimate = file_len // 2 + len(func_offsets) * 4 + 20
    print("  Writing assembly to: %s" % output_path)
    print("  Estimated output lines: ~%d" % total_lines_estimate)

    with open(output_path, "w", newline="\n") as f:
        # --- File header ---
        f.write("/* ================================================================\n")
        f.write(" * aprog.s - Disassembled APROG.BIN for Sega Saturn (SH-2)\n")
        f.write(" *\n")
        f.write(" * AUTO-GENERATED by split_binary.py -- do not edit by hand yet.\n")
        f.write(" * Every byte pair is emitted literally via .byte directives to\n")
        f.write(" * guarantee a byte-identical round-trip.\n")
        f.write(" *\n")
        f.write(" * Base address : 0x%08X\n" % base_addr)
        f.write(" * End address  : 0x%08X\n" % end_addr)
        f.write(" * Binary size  : %d bytes (0x%X)\n" % (file_len, file_len))
        f.write(" * Functions    : %d detected\n" % len(func_offsets))
        f.write(" * ================================================================ */\n")
        f.write("\n")
        f.write("    .section .text\n")
        f.write("    .org 0x0\n")
        f.write("\n")
        f.write("/* Entry point of APROG.BIN (0x%08X) */\n" % base_addr)
        f.write("    .global _start\n")
        f.write("_start:\n")
        f.write("\n")

        # --- Emit body ---
        # We always process 2 bytes at a time (SH-2 is 16-bit instruction aligned).
        # If the file has an odd trailing byte (shouldn't happen), handle it.
        next_func_idx = 0
        bytes_written = 0
        last_progress = -1

        i = 0
        while i < file_len:
            # Progress reporting (every 10%)
            pct = (i * 100) // file_len
            if pct // 10 > last_progress:
                last_progress = pct // 10
                print("  ... %d%% (%d / %d bytes)" % (pct, i, file_len))

            # Check if we are at a function boundary
            if i in func_set:
                label = func_labels[i]
                addr = base_addr + i
                f.write("\n")
                f.write("/* ------------------------------------------------------------ */\n")
                f.write("/* %s  (0x%08X)                                    */\n" % (label, addr))
                f.write("/* ------------------------------------------------------------ */\n")
                f.write("    .global %s\n" % label)
                f.write("    .type %s, @function\n" % label)
                f.write("%s:\n" % label)

            # Emit the byte pair
            if i + 1 < file_len:
                hi = data[i]
                lo = data[i + 1]
                word = (hi << 8) | lo
                addr = base_addr + i

                # Build comment
                # First, try instruction decode
                mnemonic = decode_sh2_insn(word, addr, data, i, file_len)
                if mnemonic is not None:
                    comment = "%08X: %s" % (addr, mnemonic)
                else:
                    comment = "%08X: .word 0x%04X" % (addr, word)

                # Check if this is a 32-bit constant pool entry with a code xref
                if i in pool_xrefs:
                    target = pool_xrefs[i]
                    target_off = target - base_addr
                    if target_off in func_set:
                        comment += "  -> %s" % func_labels[target_off]
                # Also check the second half of a pool entry (offset+2)
                if (i - 2) in pool_xrefs:
                    pass  # already annotated on first half

                f.write("    .byte 0x%02X, 0x%02X  /* %s */\n" % (hi, lo, comment))
                i += 2
            else:
                # Odd trailing byte (shouldn't happen for SH-2 but handle gracefully)
                hi = data[i]
                addr = base_addr + i
                f.write("    .byte 0x%02X           /* %08X: trailing byte */\n" % (hi, addr))
                i += 1

    print("  ... 100%% done")


# ---------------------------------------------------------------------------
# Symbol file generation
# ---------------------------------------------------------------------------

def generate_symbols(base_addr, func_offsets, output_path):
    """
    Generate a symbol file in linker-script-compatible format.
    Each line: SYMBOL = 0xADDRESS;
    """
    print("  Writing symbols to: %s" % output_path)
    with open(output_path, "w", newline="\n") as f:
        f.write("/* Auto-generated symbol table for APROG.BIN */\n")
        f.write("/* %d function symbols */\n\n" % len(func_offsets))
        for off in func_offsets:
            addr = base_addr + off
            f.write("FUN_%08X = 0x%08X;\n" % (addr, addr))
    print("  %d symbols written" % len(func_offsets))


# ---------------------------------------------------------------------------
# Linker script generation
# ---------------------------------------------------------------------------

def generate_linker_script(base_addr, output_path):
    """
    Generate a minimal linker script that places .text at the correct base
    address for APROG.BIN.
    """
    print("  Writing linker script to: %s" % output_path)
    with open(output_path, "w", newline="\n") as f:
        f.write("/* ================================================================\n")
        f.write(" * aprog.ld - Linker script for APROG.BIN reassembly\n")
        f.write(" *\n")
        f.write(" * Usage:\n")
        f.write(" *   sh-elf-as -big -o aprog.o aprog.s\n")
        f.write(" *   sh-elf-ld -T aprog.ld -o aprog.elf aprog.o\n")
        f.write(" *   sh-elf-objcopy -O binary aprog.elf aprog.bin\n")
        f.write(" *\n")
        f.write(" * The resulting aprog.bin should be byte-identical to the original\n")
        f.write(" * APROG.BIN.\n")
        f.write(" * ================================================================ */\n")
        f.write("\n")
        f.write("OUTPUT_FORMAT(\"elf32-sh\")\n")
        f.write("OUTPUT_ARCH(sh)\n")
        f.write("ENTRY(_start)\n")
        f.write("\n")
        f.write("SECTIONS\n")
        f.write("{\n")
        f.write("    . = 0x%08X;\n" % base_addr)
        f.write("\n")
        f.write("    .text : {\n")
        f.write("        *(.text)\n")
        f.write("    }\n")
        f.write("\n")
        f.write("    /DISCARD/ : {\n")
        f.write("        *(.comment)\n")
        f.write("        *(.note*)\n")
        f.write("        *(.eh_frame)\n")
        f.write("    }\n")
        f.write("}\n")


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    print("=" * 65)
    print("  split_binary.py - APROG.BIN -> Re-assemblable GAS source")
    print("=" * 65)
    print()

    t_start = time.time()

    # --- Read input ---
    print("[1/5] Reading APROG.BIN ...")
    if not os.path.isfile(APROG_BIN):
        print("ERROR: Cannot find %s" % APROG_BIN)
        sys.exit(1)

    with open(APROG_BIN, "rb") as f:
        data = f.read()

    file_size = len(data)
    print("  File size: %d bytes (0x%X)" % (file_size, file_size))
    print("  Address range: 0x%08X - 0x%08X" % (BASE_ADDR, BASE_ADDR + file_size))
    if file_size % 2 != 0:
        print("  WARNING: File size is odd -- trailing byte will be handled.")
    print()

    # --- Detect function boundaries ---
    print("[2/5] Scanning for function prologues ...")
    func_offsets = find_function_entries(data, BASE_ADDR)
    print("  Found %d function entry points" % len(func_offsets))
    if func_offsets:
        print("  First: 0x%08X  (offset 0x%X)" % (BASE_ADDR + func_offsets[0], func_offsets[0]))
        print("  Last:  0x%08X  (offset 0x%X)" % (BASE_ADDR + func_offsets[-1], func_offsets[-1]))
    print()

    # --- Build constant pool cross-references ---
    print("[3/5] Building constant pool cross-references ...")
    pool_xrefs = build_constant_pool_xrefs(data, BASE_ADDR, func_offsets)
    print("  Found %d pool entries referencing code addresses" % len(pool_xrefs))
    print()

    # --- Ensure output directory exists ---
    output_dir = os.path.dirname(OUTPUT_ASM)
    if not os.path.isdir(output_dir):
        os.makedirs(output_dir)

    # --- Generate .s file ---
    print("[4/5] Generating assembly source ...")
    generate_asm(data, BASE_ADDR, func_offsets, pool_xrefs, OUTPUT_ASM)
    asm_size = os.path.getsize(OUTPUT_ASM)
    print("  Assembly file size: %d bytes (%.1f MB)" % (asm_size, asm_size / (1024 * 1024)))
    print()

    # --- Generate symbol file ---
    print("[5/5] Generating symbol and linker files ...")
    generate_symbols(BASE_ADDR, func_offsets, OUTPUT_SYMS)
    generate_linker_script(BASE_ADDR, OUTPUT_LD)
    print()

    # --- Summary ---
    t_elapsed = time.time() - t_start
    print("=" * 65)
    print("  SUMMARY")
    print("=" * 65)
    print("  Input:      %s" % APROG_BIN)
    print("  Input size: %d bytes (0x%X)" % (file_size, file_size))
    print("  Base addr:  0x%08X" % BASE_ADDR)
    print("  Functions:  %d detected" % len(func_offsets))
    print("  Pool xrefs: %d code references in constant pools" % len(pool_xrefs))
    print()
    print("  Output files:")
    print("    %-40s  %d bytes" % (OUTPUT_ASM, os.path.getsize(OUTPUT_ASM)))
    print("    %-40s  %d bytes" % (OUTPUT_SYMS, os.path.getsize(OUTPUT_SYMS)))
    print("    %-40s  %d bytes" % (OUTPUT_LD, os.path.getsize(OUTPUT_LD)))
    print()
    print("  To reassemble (byte-identical round-trip):")
    print("    sh-elf-as -big -o aprog.o aprog.s")
    print("    sh-elf-ld -T aprog.ld -o aprog.elf aprog.o")
    print("    sh-elf-objcopy -O binary aprog.elf aprog.bin")
    print()
    print("  Time elapsed: %.1f seconds" % t_elapsed)
    print("=" * 65)


if __name__ == "__main__":
    main()
