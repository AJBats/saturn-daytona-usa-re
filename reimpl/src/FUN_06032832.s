
    .section .text.FUN_06032832


    .global FUN_06032832
    .type FUN_06032832, @function
FUN_06032832:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x96    /* mov.l .L_pool_06032A94, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x96    /* mov.l .L_pool_06032A98, r0 */
