
    .section .text.FUN_0602E214


    .global FUN_0602E214
    .type FUN_0602E214, @function
FUN_0602E214:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xDD, 0x24    /* mov.l .L_pool_0602E2B0, r13 */
