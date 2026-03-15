
    .section .text.FUN_0602E22C


    .global FUN_0602E22C
    .type FUN_0602E22C, @function
FUN_0602E22C:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x20    /* mov.l .L_pool_0602E2B8, r13 */
