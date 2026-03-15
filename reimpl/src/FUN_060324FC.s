
    .section .text.FUN_060324FC


    .global FUN_060324FC
    .type FUN_060324FC, @function
FUN_060324FC:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603268C - 4
    .2byte 0xB000    /* bsr FUN_0603268C (linker-resolved) */
    nop
    lds.l @r15+, pr
