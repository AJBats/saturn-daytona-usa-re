
    .section .text.FUN_0600AC44


    .global render_obj_absolute
    .type render_obj_absolute, @function
render_obj_absolute:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov r5, r13
    mov.l r11, @-r15
    shll2 r13
    mov.l r10, @-r15
    mov r4, r10
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_0600AD38, r3
    add r3, r13
    mov.b @(3, r13), r0
    mov r0, r2
    extu.b r2, r2
    mov #0x48, r0
    mov.l r2, @(8, r15)
    mov.l @(r0, r10), r3
    mov #0x40, r0
    neg r3, r3
    mov.l r3, @(4, r15)
    mov.l @(r0, r10), r3
    shll r3
    mov.l r3, @r15
    mov.b @r13, r2
    mov.l   .L_0600AD3C, r1
    extu.b r2, r2
    jsr @r1
    mov.l r2, @(12, r15)
    mov.l   .L_0600AD40, r14
    mov.l   .L_0600AD44, r3
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    neg r6, r6
    jsr @r3
    mov.l @r14, r4
    mov.l   .L_0600AD48, r3
    jsr @r3
    mov.l @r15, r4
    mov.l   .L_0600AD4C, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov.l   .L_0600AD50, r11
    mov.l @(12, r15), r14
    mov.l   .L_0600AD54, r5
    mov.l   .L_0600AD58, r3
    shll2 r14
    add r14, r5
    mov r14, r4
    mov.l @r5, r5
    add r11, r4
    jsr @r3
    mov.l @r4, r4
    mov r14, r4
    mov.l   .L_0600AD68, r2
    mov.l   .L_0600AD5C, r8
    mov.l   .L_0600AD60, r6
    mov.l @(8, r15), r9
    mov.l   .L_0600AD64, r3
    add r8, r4
    add r14, r6
    shll r9
    mov.l @r6, r6
    add r3, r9
    mov.w @r9, r5
    extu.w r5, r5
    jsr @r2
    mov.l @r4, r4
    mov.l   .L_0600AD6C, r14
    mov.l @r14, r3
    add #-0x30, r3
    mov.l r3, @r14
    mov.b @(1, r13), r0
    mov.l   .L_0600AD3C, r3
    mov r0, r2
    extu.b r2, r2
    jsr @r3
    mov.l r2, @(8, r15)
    mov.l   .L_0600AD70, r12
    mov.l   .L_0600AD44, r3
    mov.l @(8, r12), r6
    mov.l @(4, r12), r5
    neg r6, r6
    jsr @r3
    mov.l @r12, r4
    mov.l   .L_0600AD48, r3
    jsr @r3
    mov.l @r15, r4
    mov.l   .L_0600AD4C, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov.l @(8, r15), r12
    mov.l   .L_0600AD54, r5
    mov.l   .L_0600AD58, r3
    shll2 r12
    add r12, r5
    mov r12, r4
    mov.l @r5, r5
    add r11, r4
    jsr @r3
    mov.l @r4, r4
    mov r12, r4
    mov.l   .L_0600AD68, r3
    mov.l   .L_0600AD60, r6
    mov.w @r9, r5
    add r8, r4
    add r12, r6
    extu.w r5, r5
    mov.l @r6, r6
    jsr @r3
    mov.l @r4, r4
    mov.l @r14, r2
    add #-0x30, r2
    mov.l r2, @r14
    mov #0x50, r0
    mov.l @(r0, r10), r3
    neg r3, r3
    bra     .L_0600AD74
    nop
    .2byte  0xFFFF
.L_0600AD38:
    .4byte  sym_0605A1D5
.L_0600AD3C:
    .4byte  sym_06027080
.L_0600AD40:
    .4byte  sym_06044640
.L_0600AD44:
    .4byte  sym_060270F2
.L_0600AD48:
    .4byte  mat_rot_xy_b
.L_0600AD4C:
    .4byte  mat_rot_xz_b
.L_0600AD50:
    .4byte  sym_0606212C
.L_0600AD54:
    .4byte  sym_060621D8
.L_0600AD58:
    .4byte  sym_06032158
.L_0600AD5C:
    .4byte  sym_060620D8
.L_0600AD60:
    .4byte  sym_06062180
.L_0600AD64:
    .4byte  sym_06089E44
.L_0600AD68:
    .4byte  sym_06031DF4
.L_0600AD6C:
    .4byte  sym_0608A52C
.L_0600AD70:
    .4byte  sym_0604464C
.L_0600AD74:
    mov.l r3, @r15
    mov.b @(2, r13), r0
    .byte   0xD1, 0x2C    /* mov.l .L_pool_0600AE2C, r1 */
    mov r0, r2
    extu.b r2, r2
    jsr @r1
    mov.l r2, @(4, r15)
    .byte   0xDD, 0x2B    /* mov.l .L_pool_0600AE30, r13 */
    .byte   0xD3, 0x2B    /* mov.l .L_pool_0600AE34, r3 */
    mov.l @(8, r13), r6
    mov.l @(4, r13), r5
    neg r6, r6
    jsr @r3
    mov.l @r13, r4
    .byte   0xD3, 0x29    /* mov.l .L_pool_0600AE38, r3 */
    jsr @r3
    mov.l @r15, r4
    mov.l @(4, r15), r13
    .byte   0xD5, 0x28    /* mov.l .L_pool_0600AE3C, r5 */
    .byte   0xD3, 0x29    /* mov.l .L_pool_0600AE40, r3 */
    shll2 r13
    add r13, r5
    add r13, r11
    mov.l @r5, r5
    jsr @r3
    mov.l @r11, r4
    .byte   0xD6, 0x26    /* mov.l .L_pool_0600AE44, r6 */
    add r13, r8
    .byte   0xD3, 0x26    /* mov.l .L_pool_0600AE48, r3 */
    mov.w @r9, r5
    add r13, r6
    extu.w r5, r5
    mov.l @r6, r6
    jsr @r3
    mov.l @r8, r4
    mov.l @r14, r2
    add #-0x30, r2
    mov.l r2, @r14
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
