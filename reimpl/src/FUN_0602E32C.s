
    .section .text.FUN_0602E32C


    .global FUN_0602E32C
    .type FUN_0602E32C, @function
FUN_0602E32C:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xDD, 0x15    /* mov.l .L_pool_0602E38C, r13 */
