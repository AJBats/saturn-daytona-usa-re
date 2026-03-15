
    .section .text.FUN_0602E220


    .global FUN_0602E220
    .type FUN_0602E220, @function
FUN_0602E220:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xDD, 0x22    /* mov.l .L_pool_0602E2B4, r13 */
