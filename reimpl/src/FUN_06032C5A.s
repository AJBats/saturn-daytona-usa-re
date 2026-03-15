
    .section .text.FUN_06032C5A


    .global FUN_06032C5A
    .type FUN_06032C5A, @function
FUN_06032C5A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x45    /* mov.l .L_pool_06032D78, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x33    /* mov.l .L_pool_06032D34, r0 */
