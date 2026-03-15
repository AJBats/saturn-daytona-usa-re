
    .section .text.FUN_06033086


    .global FUN_06033086
    .type FUN_06033086, @function
FUN_06033086:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033330 - 4
    .2byte 0xB000    /* bsr FUN_06033330 (linker-resolved) */
    nop
    lds.l @r15+, pr
