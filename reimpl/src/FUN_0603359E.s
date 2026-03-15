
    .section .text.FUN_0603359E


    .global FUN_0603359E
    .type FUN_0603359E, @function
FUN_0603359E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r13
    mov r2, r4
    mov r8, r5
    .byte   0xD0, 0x10    /* mov.l .L_pool_060335F0, r0 */
