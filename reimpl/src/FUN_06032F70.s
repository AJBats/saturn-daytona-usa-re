
    .section .text.FUN_06032F70


    .global FUN_06032F70
    .type FUN_06032F70, @function
FUN_06032F70:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x25    /* mov.l .L_pool_06033010, r0 */
