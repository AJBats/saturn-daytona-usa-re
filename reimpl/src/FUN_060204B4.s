
    .section .text.FUN_060204B4


    .global FUN_060204B4
    .type FUN_060204B4, @function
FUN_060204B4:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD3, 0x16    /* mov.l .L_pool_06020514, r3 */
    jsr @r3
    mov.b r4, @r15
    .byte   0xD3, 0x16    /* mov.l .L_pool_06020518, r3 */
    jsr @r3
    nop
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .reloc ., R_SH_IND12W, FUN_06020DEE - 4
    .2byte 0xA000    /* bra FUN_06020DEE (linker-resolved) */
    lds.l @r15+, pr

    .global sym_060204CE
sym_060204CE:
    mov #0x0, r5
