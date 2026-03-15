
    .section .text.FUN_06033432


    .global FUN_06033432
    .type FUN_06033432, @function
FUN_06033432:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033700 - 4
    .2byte 0xB000    /* bsr FUN_06033700 (linker-resolved) */
    nop
    lds.l @r15+, pr
