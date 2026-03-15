
    .section .text.FUN_06032FB0


    .global FUN_06032FB0
    .type FUN_06032FB0, @function
FUN_06032FB0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x0C    /* mov.l .L_pool_06032FEC, r4 */
    .byte   0xD0, 0x18    /* mov.l .L_pool_0603301C, r0 */
