
    .section .text.FUN_06032520


    .global FUN_06032520
    .type FUN_06032520, @function
FUN_06032520:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603268C - 4
    .2byte 0xB000    /* bsr FUN_0603268C (linker-resolved) */
    nop
    lds.l @r15+, pr
