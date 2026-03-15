
    .section .text.FUN_060337BE


    .global FUN_060337BE
    .type FUN_060337BE, @function
FUN_060337BE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
