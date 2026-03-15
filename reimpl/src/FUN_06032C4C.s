
    .section .text.FUN_06032C4C


    .global FUN_06032C4C
    .type FUN_06032C4C, @function
FUN_06032C4C:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x47    /* mov.l .L_pool_06032D74, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x34    /* mov.l .L_pool_06032D2C, r0 */
