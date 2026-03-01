
    .section .text.FUN_06007E08


    .global vblank_frame_handler
    .type vblank_frame_handler, @function
vblank_frame_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    add #-0x24, r15
    mov.w   .L_coord_lower_bound, r7
    mov r15, r6
    add #0x1C, r6
    mov #0x0, r14


.L_classify_loop:
    mov r14, r0
    mov #0x0, r3
    cmp/gt r0, r3
    mov r3, r2
    addc r3, r0
    shar r0
    shll r0
    mov.w r2, @(r0, r6)
    mov r14, r0
    mov.w   .L_vis_x_min, r3
    shll2 r0
    mov.l @(r0, r4), r13
    cmp/gt r3, r13
    bf      .L_next_vertex
    mov.w   .L_vis_x_max, r3
    cmp/ge r3, r13
    bt      .L_next_vertex
    mov r14, r0
    mov #-0x7F, r3
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r4), r13
    cmp/gt r3, r13
    bf      .L_next_vertex
    mov #0x51, r3
    cmp/ge r3, r13
    bt      .L_next_vertex
    mov r14, r0
    mov #0x0, r3
    cmp/gt r0, r3
    addc r3, r0
    shar r0
    shll r0
    mov #0x1, r2
    mov.w r2, @(r0, r6)
.L_next_vertex:
    add #0x2, r14
    mov #0x8, r3
    cmp/ge r3, r14
    bf      .L_classify_loop


    mov.w @r5, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_check_edge1
    mov.w @(2, r6), r0
    mov r0, r3
    extu.w r3, r3
    mov.w @(6, r6), r0
    mov r0, r2
    extu.w r2, r2
    cmp/eq r2, r3
    bf      .L_setup_interp
    mov.l @(12, r4), r2
    mov.l @(28, r4), r3
    cmp/ge r3, r2
    bt      .L_edge0_y_ge
    mov #0x1, r0
    mov.w r0, @(2, r6)
    bra     .L_edge0_store
    mov #0x0, r0
.L_edge0_y_ge:
    mov #0x0, r2
    mov r2, r0
    mov.w r0, @(2, r6)
    mov #0x1, r3
    mov r3, r0
.L_edge0_store:
    bra     .L_setup_interp
    mov.w r0, @(6, r6)

.L_check_edge1:
    mov.w @(2, r5), r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_check_edge2
    mov.w @(4, r6), r0
    mov.w @r6, r2
    mov r0, r3
    extu.w r2, r2
    extu.w r3, r3
    cmp/eq r2, r3
    bf      .L_setup_interp
    mov.l @(20, r4), r2
    mov.l @(4, r4), r3
    cmp/ge r3, r2
    bt      .L_edge1_y_ge
    mov #0x1, r0
    mov.w r0, @(4, r6)
    mov #0x0, r3
    mov.w r3, @r6
    bra     .L_edge1_done
    nop
.L_edge1_y_ge:
    mov #0x0, r2
    mov r2, r0
    mov.w r0, @(4, r6)
    mov #0x1, r3
    mov.w r3, @r6
.L_edge1_done:
    bra     .L_setup_interp
    nop

.L_coord_lower_bound:
    .2byte  0xFE6B
.L_vis_x_min:
    .2byte  0xFF58
.L_vis_x_max:
    .2byte  0x00A8

.L_check_edge2:
    mov.w @(4, r5), r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_check_edge3
    mov.w @(6, r6), r0
    mov r0, r3
    extu.w r3, r3
    mov.w @(2, r6), r0
    mov r0, r2
    extu.w r2, r2
    cmp/eq r2, r3
    bf      .L_setup_interp
    mov.l @(28, r4), r2
    mov.l @(12, r4), r3
    cmp/ge r3, r2
    bt      .L_edge2_y_ge
    mov #0x1, r0
    mov.w r0, @(6, r6)
    bra     .L_edge2_done
    mov #0x0, r0
.L_edge2_y_ge:
    mov #0x0, r2
    mov r2, r0
    mov.w r0, @(6, r6)
    mov #0x1, r3
    mov r3, r0
.L_edge2_done:
    bra     .L_setup_interp
    mov.w r0, @(2, r6)

.L_check_edge3:
    mov.w @r6, r2
    mov.w @(4, r6), r0
    extu.w r2, r2
    mov r0, r3
    extu.w r3, r3
    cmp/eq r3, r2
    bf      .L_setup_interp
    mov.l @(4, r4), r2
    mov.l @(20, r4), r3
    cmp/ge r3, r2
    bt      .L_edge3_y_ge
    mov #0x1, r3
    mov.w r3, @r6
    mov #0x0, r2
    bra     .L_edge3_store
    mov r2, r0
.L_edge3_y_ge:
    mov #0x0, r2
    mov.w r2, @r6
    mov #0x1, r3
    mov r3, r0
.L_edge3_store:
    mov.w r0, @(4, r6)


.L_setup_interp:
    mov r6, r3
    add #0x2, r3
    mov.l r3, @(8, r15)
    mov r4, r11
    add #0x8, r11
    mov r4, r12
    add #0x4, r12
    mov r4, r10
    add #0xC, r10
    mov r6, r2
    add #0x6, r2
    mov.l r2, @(12, r15)
    mov r4, r14
    add #0x18, r14
    mov r4, r13
    add #0x1C, r13
    mov r5, r3
    add #0x2, r3
    mov.l r3, @(24, r15)
    mov r6, r1
    add #0x4, r1
    mov.l r1, @(16, r15)
    mov r4, r8
    add #0x10, r8
    mov r4, r9
    add #0x14, r9
    mov r6, r3
    mov.l r3, @(4, r15)
    mov r5, r2
    add #0x4, r2
    mov.l r2, @(20, r15)


.L_interp_loop:
    mov.w @r5, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_interp_dir1

    mov.l @(8, r15), r3
    mov.w @r3, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_blend_v0_toward_v3
    mov.l @r4, r3
    mov.l @r11, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r4
    mov.l @r12, r3
    mov.l @r10, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r12
    bra     .L_bounds_check_v0
    nop
.L_blend_v0_toward_v3:
    mov.l @(12, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_bounds_check_v0
    mov.l @r4, r3
    mov.l @r14, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r4
    mov.l @r12, r3
    mov.l @r13, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r12
.L_bounds_check_v0:
    mov.l @r4, r3
    mov.l r3, @r15
    cmp/ge r7, r3
    bt      .L_v0_x_above_min
    bra     .L_loop_continue
    nop
.L_v0_x_above_min:
    mov.l @r15, r2
    mov.w   .L_x_upper_bound_a, r3
    cmp/gt r3, r2
    bf      .L_v0_check_y
    bra     .L_loop_continue
    nop
.L_v0_check_y:
    mov.l @r12, r2
    mov r2, r3
    cmp/ge r7, r3
    bf/s    .L_v0_out_of_range
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_y_upper_bound_a, r3
    cmp/gt r3, r2
    bt      .L_v0_out_of_range
    bra     .L_converged
    nop
.L_v0_out_of_range:
    bra     .L_loop_continue
    nop

.L_interp_dir1:
    mov.l @(24, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_interp_dir2
    mov.l @(16, r15), r3
    mov.w @r3, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_blend_v1_toward_v0
    mov.l @r11, r3
    mov.l @r8, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r11
    mov.l @r10, r3
    mov.l @r9, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r10
    bra     .L_bounds_check_v1
    nop
.L_x_upper_bound_a:
    .2byte  0x0195
.L_y_upper_bound_a:
    .2byte  0x0131
.L_blend_v1_toward_v0:
    mov.l @(4, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_bounds_check_v1
    mov.l @r11, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r11
    mov.l @r10, r3
    mov.l @r12, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r10
.L_bounds_check_v1:
    mov.l @r11, r3
    mov.l r3, @r15
    cmp/ge r7, r3
    bt      .L_v1_x_above_min
    bra     .L_loop_continue
    nop
.L_v1_x_above_min:
    mov.l @r15, r2
    mov.w   .L_x_upper_bound_b, r3
    cmp/gt r3, r2
    bf      .L_v1_check_y
    bra     .L_loop_continue
    nop
.L_v1_check_y:
    mov.l @r10, r2
    mov r2, r3
    cmp/ge r7, r3
    bf/s    .L_v1_out_of_range
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_y_upper_bound_b, r3
    cmp/gt r3, r2
    bt      .L_v1_out_of_range
    bra     .L_converged
    nop
.L_v1_out_of_range:
    bra     .L_loop_continue
    nop

.L_interp_dir2:
    mov.l @(20, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_interp_dir3
    mov.l @(12, r15), r3
    mov.w @r3, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_blend_v2_toward_v1
    mov.l @r8, r3
    mov.l @r14, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r8
    mov.l @r9, r3
    mov.l @r13, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r9
    bra     .L_bounds_check_v2
    nop
.L_x_upper_bound_b:
    .2byte  0x0195
.L_y_upper_bound_b:
    .2byte  0x0131
.L_blend_v2_toward_v1:
    mov.l @(8, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_bounds_check_v2
    mov.l @r8, r3
    mov.l @r11, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r8
    mov.l @r9, r3
    mov.l @r10, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r9
.L_bounds_check_v2:
    mov.l @r8, r3
    mov.l r3, @r15
    cmp/ge r7, r3
    bf      .L_loop_continue
    mov.l @r15, r2
    mov.w   .L_x_upper_bound_c, r3
    cmp/gt r3, r2
    bt      .L_loop_continue
    mov.l @r9, r2
    mov r2, r3
    cmp/ge r7, r3
    bf/s    .L_v2_out_of_range
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_y_upper_bound_c, r3
    cmp/gt r3, r2
    bt      .L_v2_out_of_range
    bra     .L_converged
    nop
.L_v2_out_of_range:
    bra     .L_loop_continue
    nop

.L_interp_dir3:
    mov.l @(4, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_blend_v3_toward_v2
    mov.l @r14, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r14
    mov.l @r13, r3
    mov.l @r12, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r13
    bra     .L_bounds_check_v3
    nop
.L_blend_v3_toward_v2:
    mov.l @(16, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_bounds_check_v3
    mov.l @r14, r3
    mov.l @r8, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r14
    mov.l @r13, r3
    mov.l @r9, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    shar r3
    shar r3
    mov.l r3, @r13
.L_bounds_check_v3:
    mov.l @r14, r3
    mov.l r3, @r15
    cmp/ge r7, r3
    bf      .L_loop_continue
    mov.l @r15, r2
    mov.w   .L_x_upper_bound_c, r3
    cmp/gt r3, r2
    bt      .L_loop_continue
    mov.l @r13, r2
    mov r2, r3
    cmp/ge r7, r3
    bf/s    .L_loop_continue
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_y_upper_bound_c, r3
    cmp/gt r3, r2
    bt      .L_loop_continue
    bra     .L_converged
    nop
.L_x_upper_bound_c:
    .2byte  0x0195
.L_y_upper_bound_c:
    .2byte  0x0131
.L_loop_continue:
    bra     .L_interp_loop
    nop

.L_converged:
    add #0x24, r15
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0x0000
