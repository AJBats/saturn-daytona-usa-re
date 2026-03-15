
    .section .text.FUN_060329BC


    .global FUN_060329BC
    .type FUN_060329BC, @function
FUN_060329BC:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x42    /* mov.l .L_pool_06032AD0, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x31    /* mov.l .L_pool_06032A90, r0 */
