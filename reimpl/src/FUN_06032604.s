
    .section .text.FUN_06032604


    .global FUN_06032604
    .type FUN_06032604, @function
FUN_06032604:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x19    /* mov.l .L_pool_06032674, r13 */
    mov.l @r13, r13
    mov.l r7, @-r15
    .byte   0xD0, 0x15    /* mov.l .L_pool_06032668, r0 */
    mov.l @(r0, r14), r4
    .byte   0xD0, 0x18    /* mov.l .L_pool_06032678, r0 */
