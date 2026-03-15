
    .section .text.FUN_0603B168


    .global FUN_0603B168
    .type FUN_0603B168, @function
FUN_0603B168:
    sts.l pr, @-r15
    add #-0x14, r15
    mov.l r4, @(12, r15)
    mov.l r6, @(16, r15)
    mov.l r7, @(8, r15)
    mov #0x0, r7
    mov.l @(24, r15), r3
    mov r7, r6
    mov.l r3, @-r15
    mov.l @(20, r15), r3
    mov.l r3, @-r15
    mov r15, r3
    add #0xC, r3
    mov.l r3, @-r15
    mov r15, r2
    add #0xC, r2
    mov.l r2, @-r15
    mov.l @(28, r15), r4
    .reloc ., R_SH_IND12W, FUN_0603BE9C - 4
    .2byte 0xB000    /* bsr FUN_0603BE9C (linker-resolved) */
    mov.l @r4, r4
    mov.l @(40, r15), r3
    mov.l @r3, r0
    and #0x9F, r0
    mov.l r0, @r3
    mov.l @(24, r15), r3
    mov.l @(16, r15), r2
    mov.l @(20, r15), r1
    add #-0x1, r2
    shll8 r2
    shll2 r2
    shll r2
    add r1, r2
    mov.l r2, @r3
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    add #0x24, r15
    lds.l @r15+, pr
    rts
    nop
