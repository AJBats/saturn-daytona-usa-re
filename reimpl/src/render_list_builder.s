
    .section .text.FUN_06022820


    .global render_list_builder
    .type render_list_builder, @function
render_list_builder:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    add #-0x2C, r15
    mov #0x0, r7
    mov.w   .L_coord_lower_bound, r6
    mov r15, r14
    add #0x24, r14
    mov r14, r3
    mov.l r3, @(28, r15)
    mov.w @r5, r2
    mov.w r2, @r3
    add #0x2, r3
    mov.l r3, @(12, r15)
    mov r5, r2
    add #0x2, r2
    mov.l r2, @(20, r15)
    mov.w @r2, r1
    mov.w r1, @r3
    mov r14, r3
    add #0x4, r3
    mov.l r3, @(24, r15)
    mov r5, r2
    add #0x4, r2
    mov.l r2, @(8, r15)
    mov.w @r2, r1
    mov.w r1, @r3
    add #0x6, r14
    mov.l r14, @(32, r15)
    mov r5, r3
    add #0x6, r3
    mov.l r3, @(16, r15)
    mov.w @r3, r2
    mov.w r2, @r14
    mov r4, r12
    add #0x4, r12
    mov r4, r3
    add #0x8, r3
    mov.l r3, @r15
    mov r4, r2
    add #0xC, r2
    mov r4, r10
    add #0x18, r10
    mov r4, r11
    add #0x1C, r11
    mov r2, r13
    mov r4, r8
    add #0x10, r8
    mov r4, r9
    add #0x14, r9
    mov.l r13, @(4, r15)
.L_clip_loop:
    mov.w @r5, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_edge0_done
    mov.l @(28, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_edge0_done
    mov.l @r4, r14
    mov.l @r12, r13
    mov r14, r3
    mov r13, r2
    shll r14
    shll r13
    add r3, r14
    mov.l @(20, r15), r3
    mov.w @r3, r3
    extu.w r3, r3
    tst r3, r3
    bf/s    .L_edge0_try_vtx3
    add r2, r13
    mov.l @r15, r3
    mov.l @(4, r15), r2
    mov.l @r3, r3
    add r3, r14
    mov.l @r2, r3
    shar r14
    add r3, r13
    shar r14
    shar r13
    mov.l r14, @r4
    shar r13
    bra     .L_edge0_bounds_check
    mov.l r13, @r12
.L_coord_lower_bound:
    .2byte  0xFE6B
.L_edge0_try_vtx3:
    mov.l @(16, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_edge0_bounds_check
    mov.l @r10, r3
    mov.l @r11, r2
    add r3, r14
    add r2, r13
    shar r14
    shar r13
    shar r14
    mov.l r14, @r4
    shar r13
    mov.l r13, @r12
.L_edge0_bounds_check:
    mov.l @r4, r14
    cmp/ge r6, r14
    bf      .L_edge0_done
    mov.w   .L_x_upper_bound_0, r2
    cmp/gt r2, r14
    bt      .L_edge0_done
    mov.l @r12, r14
    cmp/ge r6, r14
    bf      .L_edge0_done
    mov.w   .L_y_upper_bound_0, r3
    cmp/gt r3, r14
    bt      .L_edge0_done
    mov.l @(28, r15), r3
    exts.w r7, r2
    mov.w r2, @r3
.L_edge0_done:
    mov.l @(20, r15), r3
    mov.w @r3, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_edge1_done
    mov.l @(12, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_edge1_done
    mov.l @r15, r14
    mov.l @(4, r15), r13
    mov.l @(8, r15), r2
    mov.l @r14, r14
    mov.l @r13, r13
    mov r14, r3
    shll r14
    add r3, r14
    mov r13, r3
    shll r13
    add r3, r13
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_edge1_try_vtx0
    mov.l @r8, r3
    mov.l @r9, r2
    add r3, r14
    add r2, r13
    shar r14
    mov.l @r15, r3
    shar r13
    shar r14
    mov.l r14, @r3
    mov.l @(4, r15), r3
    shar r13
    mov.l r13, @r3
    bra     .L_edge1_bounds_check
    nop
.L_x_upper_bound_0:
    .2byte  0x0195
.L_y_upper_bound_0:
    .2byte  0x0131
.L_edge1_try_vtx0:
    mov.w @r5, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_edge1_bounds_check
    mov.l @r4, r3
    mov.l @r12, r2
    add r3, r14
    add r2, r13
    shar r14
    mov.l @r15, r3
    shar r13
    shar r14
    mov.l r14, @r3
    mov.l @(4, r15), r3
    shar r13
    mov.l r13, @r3
.L_edge1_bounds_check:
    mov.l @r15, r14
    mov.l @r14, r14
    cmp/ge r6, r14
    bf      .L_edge1_done
    mov.w   .L_x_upper_bound_1, r2
    cmp/gt r2, r14
    bt      .L_edge1_done
    mov.l @(4, r15), r14
    mov.l @r14, r14
    cmp/ge r6, r14
    bf      .L_edge1_done
    mov.w   .L_y_upper_bound_1, r2
    cmp/gt r2, r14
    bt      .L_edge1_done
    mov.l @(12, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_edge1_done:
    mov.l @(8, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_edge2_done
    mov.l @(24, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_edge2_done
    mov.l @r8, r14
    mov.l @r9, r13
    mov r14, r3
    mov r13, r2
    shll r14
    shll r13
    add r3, r14
    mov.l @(16, r15), r3
    mov.w @r3, r3
    extu.w r3, r3
    tst r3, r3
    bf/s    .L_edge2_try_vtx1
    add r2, r13
    mov.l @r10, r3
    mov.l @r11, r2
    add r3, r14
    add r2, r13
    shar r14
    shar r13
    shar r14
    mov.l r14, @r8
    shar r13
    bra     .L_edge2_bounds_check
    mov.l r13, @r9
.L_x_upper_bound_1:
    .2byte  0x0195
.L_y_upper_bound_1:
    .2byte  0x0131
.L_edge2_try_vtx1:
    mov.l @(20, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_edge2_bounds_check
    mov.l @r15, r3
    mov.l @(4, r15), r2
    mov.l @r3, r3
    add r3, r14
    mov.l @r2, r3
    shar r14
    add r3, r13
    shar r14
    shar r13
    mov.l r14, @r8
    shar r13
    mov.l r13, @r9
.L_edge2_bounds_check:
    mov.l @r8, r14
    cmp/ge r6, r14
    bf      .L_edge2_done
    mov.w   .L_x_upper_bound_2, r3
    cmp/gt r3, r14
    bt      .L_edge2_done
    mov.l @r9, r14
    cmp/ge r6, r14
    bf      .L_edge2_done
    mov.w   .L_y_upper_bound_2, r2
    cmp/gt r2, r14
    bt      .L_edge2_done
    mov.l @(24, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_edge2_done:
    mov.l @(16, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_edge3_done
    mov.l @(32, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_edge3_done
    mov.l @r10, r13
    mov.l @r11, r14
    mov r13, r3
    mov r14, r2
    shll r13
    shll r14
    add r3, r13
    mov.w @r5, r3
    extu.w r3, r3
    tst r3, r3
    bf/s    .L_edge3_try_vtx2
    add r2, r14
    mov.l @r4, r3
    mov.l @r12, r2
    add r3, r13
    add r2, r14
    shar r13
    shar r14
    shar r13
    mov.l r13, @r10
    shar r14
    bra     .L_edge3_bounds_check
    mov.l r14, @r11
.L_x_upper_bound_2:
    .2byte  0x0195
.L_y_upper_bound_2:
    .2byte  0x0131
.L_edge3_try_vtx2:
    mov.l @(8, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_edge3_bounds_check
    mov.l @r8, r3
    mov.l @r9, r2
    add r3, r13
    add r2, r14
    shar r13
    shar r14
    shar r13
    mov.l r13, @r10
    shar r14
    mov.l r14, @r11
.L_edge3_bounds_check:
    mov.l @r10, r14
    cmp/ge r6, r14
    bf      .L_edge3_done
    mov.w   .L_x_upper_bound_3, r2
    cmp/gt r2, r14
    bt      .L_edge3_done
    mov.l @r11, r14
    cmp/ge r6, r14
    bf      .L_edge3_done
    mov.w   .L_y_upper_bound_3, r3
    cmp/gt r3, r14
    bt      .L_edge3_done
    mov.l @(32, r15), r3
    exts.w r7, r2
    mov.w r2, @r3
.L_edge3_done:
    mov.l @(28, r15), r3
    mov.l @(12, r15), r2
    mov.l @(24, r15), r1
    mov.w @r3, r3
    mov.w @r2, r2
    or r2, r3
    mov.w @r1, r2
    or r2, r3
    mov.l @(32, r15), r1
    mov.w @r1, r2
    or r2, r3
    tst r3, r3
    bf      .L_not_converged
    bra     .L_epilogue
    nop
.L_not_converged:
    bra     .L_clip_loop
    nop
.L_epilogue:
    add #0x2C, r15
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_x_upper_bound_3:
    .2byte  0x0195
.L_y_upper_bound_3:
    .2byte  0x0131
