
    .section .text.FUN_0602E338


    .global FUN_0602E338
    .type FUN_0602E338, @function
FUN_0602E338:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x13    /* mov.l .L_pool_0602E390, r4 */
    .byte   0xDD, 0x14    /* mov.l .L_pool_0602E394, r13 */
