
    .section .text.FUN_060324F4


    .global FUN_060324F4
    .type FUN_060324F4, @function
FUN_060324F4:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603253C - 4
    .2byte 0xB000    /* bsr FUN_0603253C (linker-resolved) */
    nop
    lds.l @r15+, pr
