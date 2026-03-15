
    .section .text.FUN_0603288A


    .global FUN_0603288A
    .type FUN_0603288A, @function
FUN_0603288A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x84    /* mov.l .L_pool_06032AA4, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x7E    /* mov.l .L_pool_06032A90, r0 */
