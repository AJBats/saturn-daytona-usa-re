
    .section .text.FUN_0603274C


    .global FUN_0603274C
    .type FUN_0603274C, @function
FUN_0603274C:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x26    /* mov.l .L_pool_060327F0, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x21    /* mov.l .L_pool_060327E0, r0 */
