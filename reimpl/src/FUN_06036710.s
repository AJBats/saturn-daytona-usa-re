
    .section .text.FUN_06036710


    .global FUN_06036710
    .type FUN_06036710, @function
FUN_06036710:
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xD3, 0x22    /* mov.l .L_pool_060367A0, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x55, r3
    extu.w r14, r14
    extu.b r13, r13
    mov r15, r5
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.w r0, @(2, r2)
    mov r15, r2
    mov r13, r0
    mov.l r12, @(4, r3)
    mov.b r0, @(4, r2)
    .byte   0xD3, 0x1B    /* mov.l .L_pool_060367A4, r3 */
    jsr @r3
    mov #0x40, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0603674A
    .type FUN_0603674A, @function
FUN_0603674A:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r6, r14
    mov.l r12, @-r15
    mov r5, r13
