
    .section .text.FUN_06032F20


    .global FUN_06032F20
    .type FUN_06032F20, @function
FUN_06032F20:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x39    /* mov.l .L_pool_06033010, r0 */


    .global FUN_06032F2A
    .type FUN_06032F2A, @function
FUN_06032F2A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x38    /* mov.l .L_pool_06033014, r0 */
