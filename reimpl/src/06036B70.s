
    .section .text.FUN_06036B70


    .global particle_spawner
    .type particle_spawner, @function
particle_spawner:
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xD3, 0x18    /* mov.l .L_pool_06036BD8, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov r15, r3
    extu.b r13, r13
    mov.l r14, @r2
    mov r13, r0
    mov #0x74, r2
    mov.b r2, @r3
    mov r15, r3
    mov r15, r2
    mov.l r12, @(4, r3)
    mov.b r0, @(4, r2)
    .byte   0x94, 0x1D    /* mov.w .L_wpool_06036BCE, r4 */
    .byte   0xD3, 0x12    /* mov.l .L_pool_06036BDC, r3 */
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
