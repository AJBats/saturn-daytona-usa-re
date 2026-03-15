
    .section .text.FUN_06032504


    .global FUN_06032504
    .type FUN_06032504, @function
FUN_06032504:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032584 - 4
    .2byte 0xB000    /* bsr FUN_06032584 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_06032538 - 4
    .2byte 0xA000    /* bra FUN_06032538 (linker-resolved) */
    nop
