
    .section .text.FUN_0602E344


    .global FUN_0602E344
    .type FUN_0602E344, @function
FUN_0602E344:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x10    /* mov.l .L_pool_0602E390, r4 */
    .byte   0xDD, 0x12    /* mov.l .L_pool_0602E398, r13 */
