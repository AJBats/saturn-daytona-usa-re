
    .section .text.FUN_06006A9C


    .global scene_path_a
    .type scene_path_a, @function
scene_path_a:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x30, r15
    mov.l   .L_render_state_base, r8
    mov.l   .L_render_params, r9
    mov.l   .L_scene_mode_ptr, r14
    mov.l   .L_table_a_base, r4
    mov.l @r14, r0
    shll2 r0
    shll r0
    mov.l @(r0, r4), r3
    mov.l r3, @(12, r15)
    mov.l @r14, r0
    shll r0
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r4), r2
    mov.l r2, @(4, r15)
    mov.l   .L_table_b_base, r4
    mov.l @r14, r0
    shll2 r0
    shll2 r0
    mov.l @(r0, r4), r1
    mov.l r1, @(32, r15)
    mov.l @r14, r5
    shll2 r5
    mov r5, r0
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r4), r3
    mov r5, r0
    mov.l r3, @(36, r15)
    add #0x2, r0
    shll2 r0
    mov.l @(r0, r4), r2
    mov r5, r0
    mov.l r2, @(20, r15)
    add #0x3, r0
    shll2 r0
    mov.l @(r0, r4), r1
    mov.l r1, @(24, r15)
    mov.l   .L_camera_state, r5
    mov.l   .L_grid_bias, r3
    mov.l @r5, r4
    add r3, r4
    shlr16 r4
    shlr2 r4
    shlr2 r4
    shlr r4
    mov.l @(8, r5), r2
    neg r2, r2
    add #-0x1, r3
    add r3, r2
    mov r2, r5
    shlr16 r5
    shlr2 r5
    shlr2 r5
    shlr r5
    mov #-0x2, r6
    mov r5, r2
    mov r6, r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r4, r2
    mov.l r2, @(28, r15)
    mov.l r3, @(44, r15)
    mov #0x2, r3
    mov.l r3, @(16, r15)
    mov.l r3, @(40, r15)
    mov #0x3E, r3
    cmp/hs r3, r5
    bf      .L_check_row_near_edge
    mov #0x3F, r3
    sub r5, r3
    mov.l r3, @(16, r15)
    bra     .L_check_col_far_edge
    nop
.L_check_row_near_edge:
    mov #0x1, r2
    cmp/hi r2, r5
    bt      .L_check_col_far_edge
    neg r5, r6
.L_check_col_far_edge:
    mov #0x3E, r2
    cmp/hs r2, r4
    bf      .L_check_col_near_edge
    mov #0x3F, r2
    sub r4, r2
    bra     .L_scale_loop_bounds
    mov.l r2, @(40, r15)
    .2byte  0xFFFF
.L_render_state_base:
    .4byte  sym_060620D4
.L_render_params:
    .4byte  sym_06089E44
.L_scene_mode_ptr:
    .4byte  sym_0607EAD8
.L_table_a_base:
    .4byte  sym_06062248
.L_table_b_base:
    .4byte  sym_06062260
.L_camera_state:
    .4byte  sym_06063DF8
.L_grid_bias:
    .4byte  0x04000000
.L_check_col_near_edge:
    mov #0x1, r2
    cmp/hi r2, r4
    bt      .L_scale_loop_bounds
    neg r4, r4
    mov.l r4, @(44, r15)
.L_scale_loop_bounds:
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @(16, r15), r3
    shll2 r3
    shll2 r3
    shll2 r3
    mov.l r3, @(16, r15)
    bra     .L_outer_loop_test
    mov r6, r10
.L_outer_loop_body:
    bra     .L_inner_loop_test
    mov.l @(44, r15), r12
.L_inner_loop_body:
    mov r10, r0
    cmp/eq #-0x80, r0
    bt      .L_process_cell
    mov.w   DAT_06006c1e, r3
    cmp/eq r3, r10
    bt      .L_process_cell
    mov r12, r0
    cmp/eq #-0x2, r0
    bt      .L_process_cell
    mov r12, r0
    cmp/eq #0x2, r0
    bf      .L_inner_loop_next
    bra     .L_process_cell
    nop
.L_process_cell:
    mov r10, r2
    mov.l @(28, r15), r3
    add r12, r2
    add r3, r2
    mov r2, r4
    mov.l r2, @r15
    shll r4
    mov.l @(32, r15), r13
    mov.l @(20, r15), r3
    add r4, r13
    add r3, r4
    mov.w @r13, r13
    exts.w r13, r2
    cmp/pl r2
    bf/s    .L_check_seg_b
    mov.w @r4, r11
    mov.l @r14, r3
    mov.l   .L_seg_offset_table, r2
    mov.l @r15, r0
    mov.l @(36, r15), r1
    shll2 r3
    shll2 r0
    shll r3
    mov.l @(r0, r1), r0
    add r2, r3
    mov.l @r3, r3
    exts.w r13, r2
    add r0, r3
    mov.l r3, @(8, r15)
    mov.l @r8, r0
    add r0, r2
    mov.w   .L_max_distance, r0
    cmp/hs r0, r2
    bf      .L_dispatch_render_a
    mov.w   .L_max_distance, r13
    mov.l @r8, r3
    sub r3, r13
    exts.w r13, r13
.L_dispatch_render_a:
    mov.l @r14, r0
    cmp/eq #0x2, r0
    bt      .L_render_a_mode2
    exts.w r13, r7
    mov r9, r6
    mov.l @(12, r15), r5
    mov.l   .L_render_poly_a, r3
    add #0x52, r6
    mov.w @r6, r6
    extu.w r6, r6
    jsr @r3
    mov.l @(8, r15), r4
    bra     .L_check_seg_b
    nop

    .global DAT_06006c1e
DAT_06006c1e:
    .2byte  0x0080
.L_max_distance:
    .2byte  0x0640
    .2byte  0xFFFF
.L_seg_offset_table:
    .4byte  sym_06062230
.L_render_poly_a:
    .4byte  sym_0602A214
.L_render_a_mode2:
    exts.w r13, r7
    mov r9, r6
    mov.l @(12, r15), r5
    mov.l   .L_vdp1_finalize_fn, r3
    add #0x52, r6
    mov.w @r6, r6
    extu.w r6, r6
    jsr @r3
    mov.l @(8, r15), r4
.L_check_seg_b:
    exts.w r11, r2
    cmp/pl r2
    bf      .L_inner_loop_next
    exts.w r11, r1
    mov.l @r14, r13
    mov.l   .L_seg_offset_table_b, r3
    mov.l @r15, r0
    mov.l @(24, r15), r2
    shll r13
    shll2 r0
    add #0x1, r13
    mov.l @(r0, r2), r0
    shll2 r13
    add r3, r13
    mov.l @r13, r13
    add r0, r13
    mov.l @r8, r0
    add r0, r1
    mov.w   DAT_06006cca, r0
    cmp/hs r0, r1
    bf      .L_dispatch_render_b
    mov.w   DAT_06006cca, r11
    mov.l @r8, r3
    sub r3, r11
    exts.w r11, r11
.L_dispatch_render_b:
    mov.l @r14, r0
    cmp/eq #0x2, r0
    bt      .L_render_b_mode2
    exts.w r11, r7
    mov r9, r6
    mov.l @(4, r15), r5
    mov.l   .L_render_poly_b, r3
    add #0x52, r6
    mov.w @r6, r6
    extu.w r6, r6
    jsr @r3
    mov r13, r4
    bra     .L_inner_loop_next
    nop
.L_render_b_mode2:
    exts.w r11, r7
    mov r9, r6
    mov.l @(4, r15), r5
    mov.l   .L_render_poly_b_alt, r3
    add #0x52, r6
    mov.w @r6, r6
    extu.w r6, r6
    jsr @r3
    mov r13, r4
.L_inner_loop_next:
    add #0x1, r12
.L_inner_loop_test:
    mov.l @(40, r15), r2
    cmp/ge r2, r12
    bt      .L_outer_loop_next
    bra     .L_inner_loop_body
    nop
.L_outer_loop_next:
    add #0x40, r10
.L_outer_loop_test:
    mov.l @(16, r15), r2
    cmp/ge r2, r10
    bt      .L_epilogue
    bra     .L_outer_loop_body
    nop
.L_epilogue:
    add #0x30, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06006cca
DAT_06006cca:
    .2byte  0x0640
.L_vdp1_finalize_fn:
    .4byte  vdp1_list_finalize
.L_seg_offset_table_b:
    .4byte  sym_06062230
.L_render_poly_b:
    .4byte  sym_0602ABB8
.L_render_poly_b_alt:
    .4byte  sym_0602B9E0
