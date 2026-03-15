
    .section .text.FUN_06032824


    .global FUN_06032824
    .type FUN_06032824, @function
FUN_06032824:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x97    /* mov.l .L_pool_06032A8C, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x97    /* mov.l .L_pool_06032A90, r0 */
