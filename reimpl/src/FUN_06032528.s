
    .section .text.FUN_06032528


    .global FUN_06032528
    .type FUN_06032528, @function
FUN_06032528:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032584 - 4
    .2byte 0xB000    /* bsr FUN_06032584 (linker-resolved) */
    nop
    lds.l @r15+, pr
