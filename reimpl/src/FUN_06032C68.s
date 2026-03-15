
    .section .text.FUN_06032C68


    .global FUN_06032C68
    .type FUN_06032C68, @function
FUN_06032C68:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x42    /* mov.l .L_pool_06032D7C, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x31    /* mov.l .L_pool_06032D3C, r0 */
