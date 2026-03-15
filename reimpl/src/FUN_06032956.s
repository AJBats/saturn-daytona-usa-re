
    .section .text.FUN_06032956


    .global FUN_06032956
    .type FUN_06032956, @function
FUN_06032956:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x58    /* mov.l .L_pool_06032AC0, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x4B    /* mov.l .L_pool_06032A90, r0 */
