
    .section .text.FUN_0603B60C


    .global FUN_0603B60C
    .type FUN_0603B60C, @function
FUN_0603B60C:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    mov.l   .L_0603B62C, r3
    jsr @r3
    mov.l @(8, r4), r4
    mov.l r0, @r15
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xB000    /* bsr FUN_0603B93C (linker-resolved) */
    mov #0x0, r4
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
    .4byte  FUN_0603F970
.L_0603B62C:
    .4byte  sym_0603F9FA
