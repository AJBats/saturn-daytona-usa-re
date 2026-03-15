
    .section .text.FUN_0603262E


    .global FUN_0603262E
    .type FUN_0603262E, @function
FUN_0603262E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x0C    /* mov.l .L_pool_06032668, r0 */
    mov.l @(r0, r14), r1
    .byte   0xD2, 0x12    /* mov.l .L_pool_06032684, r2 */
    add r2, r1
    mov.l r1, @(r0, r14)
    .byte   0xD0, 0x11    /* mov.l .L_pool_06032688, r0 */
