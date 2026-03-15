
    .section .text.FUN_06040954


    .global FUN_06040954
    .type FUN_06040954, @function
FUN_06040954:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06040964 - 4
    .2byte 0xB000    /* bsr FUN_06040964 (linker-resolved) */
    nop
    shll8 r0
    lds.l @r15+, pr
    shll2 r0
    rts
    shll r0
