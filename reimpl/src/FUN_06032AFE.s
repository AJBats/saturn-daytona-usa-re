
    .section .text.FUN_06032AFE


    .global FUN_06032AFE
    .type FUN_06032AFE, @function
FUN_06032AFE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x8A    /* mov.l .L_pool_06032D30, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x8A    /* mov.l .L_pool_06032D34, r0 */
