
    .section .text.FUN_0603B5F2


    .global FUN_0603B5F2
    .type FUN_0603B5F2, @function
FUN_0603B5F2:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l @r4, r4
    mov.l @(40, r4), r3
    mov.l r3, @r15
    mov.l r5, @(40, r4)
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
