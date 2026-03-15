
    .section .text.FUN_06032286


    .global FUN_06032286
    .type FUN_06032286, @function
FUN_06032286:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032304 - 4
    .2byte 0xB000    /* bsr FUN_06032304 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x12    /* mov.l .L_pool_060322D8, r4 */
