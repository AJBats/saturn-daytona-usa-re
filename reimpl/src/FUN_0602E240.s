
    .section .text.FUN_0602E240


    .global FUN_0602E240
    .type FUN_0602E240, @function
FUN_0602E240:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x1D    /* mov.l .L_pool_0602E2C0, r13 */
