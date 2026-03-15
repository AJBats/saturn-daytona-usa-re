
    .section .text.FUN_060334D2


    .global FUN_060334D2
    .type FUN_060334D2, @function
FUN_060334D2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
