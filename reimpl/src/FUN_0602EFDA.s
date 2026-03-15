
    .section .text.FUN_0602EFDA


    .global FUN_0602EFDA
    .type FUN_0602EFDA, @function
FUN_0602EFDA:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    rts
    mov r14, r0

    .global DAT_0602efe6
DAT_0602efe6:
    .word 0x0100
    mov.b r0, @(r0, r1)
    .word 0x0000
    .4byte  FUN_06027358
