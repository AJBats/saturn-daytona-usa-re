
    .section .text.FUN_06015FC2


    .global results_screen_render
    .type results_screen_render, @function
results_screen_render:
    sts.l pr, @-r15
    shll2 r3
    .byte   0xDD, 0x3D    /* mov.l .L_pool_elem_array_base, r13 */ ! r13 = element array base (sym_06084FC8)
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(48, r4), r2
    mov.l @(56, r4), r3
    cmp/eq r3, r2
    bt/s    .L_y_interp_done
    mov #0x0, r12
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(24, r4), r2
    mov.l @(48, r4), r3
    add r2, r3
    mov.l r3, @(48, r4)
    mov.l @(24, r4), r2
    cmp/pz r2
    .word 0x0029
    xor #0x1, r0
    mov.l @(56, r4), r2
    cmp/gt r2, r3
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r0
    tst r0, r0
    bt      .L_check_y_clamp_positive
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(56, r4), r2
    mov.l r2, @(48, r4)
.L_check_y_clamp_positive:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(24, r4), r2
    cmp/pz r2
    .word 0x0029
    mov.l @(48, r4), r3
    mov.l @(56, r4), r2
    cmp/ge r2, r3
    .word 0x0129
    and r1, r0
    tst r0, r0
    bt      .L_y_interp_done
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(56, r4), r2
    mov.l r2, @(48, r4)
.L_y_interp_done:
    extu.b r14, r11
    mov r11, r3
    shll2 r11
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r11
    exts.w r11, r11
    add r13, r11
    mov.l @(16, r11), r2
    mov.l @(4, r11), r3
    add r2, r3
    mov r3, r4
    mov.l r3, @(4, r11)
    mov.l @(52, r11), r2
    .byte   0xD3, 0x10    /* mov.l .L_pool_int_abs, r3 */ ! r3 = int_abs function address
    jsr @r3
    sub r2, r4
    .byte   0xD2, 0x10    /* mov.l .L_pool_distance_threshold, r2 */ ! r2 = 0x000F0000 (15.0 in 16.16 FP)
    cmp/gt r2, r0
    bt      .L_x_interp_done
    extu.b r14, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r13, r2
    mov.l @(16, r2), r2
    cmp/pz r2
    bt      .L_x_vel_positive
    extu.b r14, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r13, r2
    .byte   0xD1, 0x05    /* mov.l .L_pool_neg_velocity, r1 */ ! r1 = 0xFFFC0000 (-4.0 in 16.16 FP)
    mov.w   .L_wpool_neg_speed_adj, r4
    bra     .L_apply_speed_damping
    mov.l r1, @(16, r2)
.L_wpool_neg_speed_adj:
    .2byte  0xF800
.L_pool_elem_array_base:
    .4byte  sym_06084FC8
.L_pool_int_abs:
    .4byte  sym_06035438
.L_pool_distance_threshold:
    .4byte  0x000F0000                  /* nibble 4 mask */ ! 15.0 in 16.16 FP — distance threshold for damping
.L_pool_neg_velocity:
    .4byte  0xFFFC0000
.L_x_vel_positive:
    extu.b r14, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r13, r2
    .byte   0xD1, 0x47    /* mov.l .L_pool_pos_velocity, r1 */ ! r1 = 0x00040000 (+4.0 in 16.16 FP)
    mov.l r1, @(16, r2)
    mov.w   .L_wpool_pos_speed_adj, r4
.L_apply_speed_damping:
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l @(28, r3), r0
    tst r0, r0
    bt      .L_apply_single_damp
    extu.b r14, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r13, r5
    mov.l @(16, r5), r2
    shll r2
    mov.l r2, @(16, r5)
    shll r4
.L_apply_single_damp:
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l @(16, r3), r1
    sub r4, r1
    mov.l r1, @(16, r3)
.L_x_interp_done:
    extu.b r14, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r13, r5
    mov.l @(16, r5), r2
    cmp/pz r2
    .word 0x0029
    xor #0x1, r0
    mov.l @(4, r5), r3
    mov.l @(52, r5), r2
    cmp/gt r2, r3
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r0
    tst r0, r0
    bt/s    .L_check_x_clamp_positive
    mov #0x1, r4
    extu.b r14, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r13, r5
    mov.l @(52, r5), r2
    mov.l r2, @(4, r5)
    bra     .L_render_element
    extu.b r4, r12
.L_check_x_clamp_positive:
    extu.b r14, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r13, r5
    mov.l @(16, r5), r2
    cmp/pz r2
    .word 0x0029
    mov.l @(4, r5), r3
    mov.l @(52, r5), r2
    cmp/ge r2, r3
    .word 0x0129
    and r1, r0
    tst r0, r0
    bt      .L_render_element
    extu.b r14, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r13, r5
    mov.l @(52, r5), r2
    mov.l r2, @(4, r5)
    extu.b r4, r12
.L_render_element:
    .byte   0xB6, 0x10    /* bsr 0x06016DD8 (external) */ ! call track_vtx_builder (compute vertex positions)
    extu.b r14, r4
    extu.b r12, r12
    tst r12, r12
    bt      .L_epilogue
    extu.b r14, r4
    mov #0x41, r0
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.b @(r0, r4), r2
    add #0x1, r2
    mov.b r2, @(r0, r4)
    mov #0x3, r2
    mov.b @(r0, r4), r3
    extu.b r3, r3
    cmp/gt r2, r3
    bf      .L_decrement_phase
    extu.b r14, r14
    mov r14, r2
    shll2 r14
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r14
    exts.w r14, r14
    add r13, r14
    bra     .L_write_phase
    mov #0x2, r0
.L_wpool_pos_speed_adj:
    .2byte  0x0800
    .2byte  0xFFFF
.L_pool_pos_velocity:
    .4byte  0x00040000                  /* 4.0 (16.16 fixed-point) */ ! +4.0 base positive X velocity
.L_decrement_phase:
    extu.b r14, r14
    mov r14, r2
    shll2 r14
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r14
    exts.w r14, r14
    add r13, r14
    mov.b @(2, r14), r0
    mov r0, r3
    add #-0x1, r3
    mov r3, r0
.L_write_phase:
    mov.b r0, @(2, r14)
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
