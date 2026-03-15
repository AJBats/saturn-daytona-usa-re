
    .section .text.FUN_06032FC6


    .global FUN_06032FC6
    .type FUN_06032FC6, @function
FUN_06032FC6:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x06    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x10    /* mov.l .L_pool_06033014, r0 */
