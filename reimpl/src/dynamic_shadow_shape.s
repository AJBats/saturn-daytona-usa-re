
    .section .text.FUN_06036AA4


    .global dynamic_shadow_shape
    .type dynamic_shadow_shape, @function
dynamic_shadow_shape:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r4
    .byte   0xD3, 0x23    /* mov.l .L_pool_06036B38, r3 */
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x72, r3
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    add #0x8, r5
    mov.b r3, @r2
    .byte   0xD3, 0x1F    /* mov.l .L_pool_06036B3C, r3 */
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.w @(2, r2), r0
    mov r0, r3
    extu.w r3, r3
    mov.l r3, @r13
    mov r15, r3
    mov.b @(4, r3), r0
    mov r15, r3
    mov r0, r2
    extu.b r2, r2
    mov r4, r0
    mov.l r2, @r12
    mov.l @(4, r3), r2
    .byte   0xD3, 0x17    /* mov.l .L_pool_06036B40, r3 */
    and r3, r2
    mov.l r2, @r14
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
