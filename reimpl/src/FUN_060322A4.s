
    .section .text.FUN_060322A4


    .global FUN_060322A4
    .type FUN_060322A4, @function
FUN_060322A4:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032304 - 4
    .2byte 0xB000    /* bsr FUN_06032304 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x0D    /* mov.l .L_pool_060322E4, r4 */
