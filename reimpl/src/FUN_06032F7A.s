
    .section .text.FUN_06032F7A


    .global FUN_06032F7A
    .type FUN_06032F7A, @function
FUN_06032F7A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x24    /* mov.l .L_pool_06033014, r0 */
