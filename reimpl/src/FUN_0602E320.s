
    .section .text.FUN_0602E320


    .global FUN_0602E320
    .type FUN_0602E320, @function
FUN_0602E320:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xDD, 0x17    /* mov.l .L_pool_0602E388, r13 */
