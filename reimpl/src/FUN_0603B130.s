
    .section .text.FUN_0603B130


    .global FUN_0603B130
    .type FUN_0603B130, @function
FUN_0603B130:
    mov.l r14, @-r15
    mov.l @(24, r15), r2
    mov.l r2, @-r15
    mov.l @(20, r15), r3
    mov.l r3, @-r15
    mov.l @(20, r15), r7
    mov.l @(28, r15), r4
    .reloc ., R_SH_IND12W, FUN_0603BE9C - 4
    .2byte 0xB000    /* bsr FUN_0603BE9C (linker-resolved) */
    mov.l @r4, r4
    add #0x10, r15
    mov.l @r15, r0
    tst #0x8, r0
    bt      .L_0603B15C
    bra     .L_0603B14E
    nop
.L_0603B14E:
    mov.l @r15, r0
    tst #0x4, r0
    bt      .L_0603B15C
    bra     .L_0603B158
    nop
.L_0603B158:
    mov.l @(4, r15), r2
    mov.l r14, @r2
.L_0603B15C:
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    add #0x14, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
