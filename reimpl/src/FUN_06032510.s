
    .section .text.FUN_06032510


    .global FUN_06032510
    .type FUN_06032510, @function
FUN_06032510:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032E6C - 4
    .2byte 0xB000    /* bsr FUN_06032E6C (linker-resolved) */
    nop
    lds.l @r15+, pr
