
    .section .text.FUN_0603358E


    .global FUN_0603358E
    .type FUN_0603358E, @function
FUN_0603358E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r14
    mov r3, r4
    mov r7, r5
    .byte   0xD0, 0x14    /* mov.l .L_pool_060335F0, r0 */
