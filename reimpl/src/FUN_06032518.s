
    .section .text.FUN_06032518


    .global FUN_06032518
    .type FUN_06032518, @function
FUN_06032518:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603253C - 4
    .2byte 0xB000    /* bsr FUN_0603253C (linker-resolved) */
    nop
    lds.l @r15+, pr
