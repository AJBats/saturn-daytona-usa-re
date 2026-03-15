
    .section .text.FUN_06032B0C


    .global FUN_06032B0C
    .type FUN_06032B0C, @function
FUN_06032B0C:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x88    /* mov.l .L_pool_06032D38, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x88    /* mov.l .L_pool_06032D3C, r0 */
