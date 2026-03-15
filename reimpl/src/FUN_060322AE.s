
    .section .text.FUN_060322AE


    .global FUN_060322AE
    .type FUN_060322AE, @function
FUN_060322AE:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032304 - 4
    .2byte 0xB000    /* bsr FUN_06032304 (linker-resolved) */
    nop
    lds.l @r15+, pr
