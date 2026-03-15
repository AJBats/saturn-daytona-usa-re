
    .section .text.FUN_0602E678


    .global FUN_0602E678
    .type FUN_0602E678, @function
FUN_0602E678:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov r0, r7
    mov.l @r15+, r4
    sub r6, r4
    mov r4, r5
    .byte   0xDD, 0x0B    /* mov.l .L_pool_0602E6B8, r13 */
