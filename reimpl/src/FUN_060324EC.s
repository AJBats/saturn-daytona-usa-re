
    .section .text.FUN_060324EC


    .global FUN_060324EC
    .type FUN_060324EC, @function
FUN_060324EC:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032E6C - 4
    .2byte 0xB000    /* bsr FUN_06032E6C (linker-resolved) */
    nop
    lds.l @r15+, pr
