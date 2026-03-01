
    .section .text.FUN_06006CDC


    .global scene_path_b
    .type scene_path_b, @function
scene_path_b:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x3C, r15
    mov.l   .L_sort_buf_idx_ptr, r10
    mov.l   .L_player_mode_ptr, r13
    mov.w   DAT_06006da6, r14
    mov.l   .L_cam_heading_ptr, r4
    mov.w   .L_heading_bias, r3
    mov.l   .L_mask_low16, r2
    mov.l   .L_dispatch_table_a, r5
    mov.l @r13, r0
    mov.l @r4, r4
    shll2 r0
    add r3, r4
    shll r0
    and r2, r4
    mov.l @(r0, r5), r3
    shlr8 r4
    mov.l r3, @(12, r15)
    shlr2 r4
    mov.l @r13, r0
    shlr2 r4
    shll r0
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r5), r2
    mov.l r2, @(16, r15)
    mov.w   .L_row_stride, r1
    mul.l r1, r4
    sts macl, r4
    mov.l   .L_vis_table_base_offset, r0
    add r0, r4
    mov.w   .L_vis_table_extra_offset, r1
    add r1, r4
    mov.l r4, @(36, r15)
    mov.l   .L_dispatch_table_b, r4
    mov.l @r13, r0
    shll2 r0
    shll2 r0
    mov.l @(r0, r4), r1
    mov.l r1, @(40, r15)
    mov.l @r13, r5
    shll2 r5
    mov r5, r0
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r4), r3
    mov.l r3, @(48, r15)
    mov r5, r0
    add #0x2, r0
    shll2 r0
    mov.l @(r0, r4), r2
    mov.l r2, @(44, r15)
    mov r5, r0
    add #0x3, r0
    shll2 r0
    mov.l @(r0, r4), r1
    mov.l r1, @(24, r15)
    mov.l   .L_cam_orient_data, r5
    mov.l   .L_column_rounding, r3
    mov.l @r5, r4
    mov.l @(8, r5), r2
    add r3, r4
    neg r2, r2
    shlr16 r4
    add #-0x1, r3
    shlr2 r4
    add r3, r2
    shlr2 r4
    mov r2, r5
    shlr r4
    shlr16 r5
    shlr2 r5
    shlr2 r5
    shlr r5
    mov r5, r2
    shll2 r2
    shll2 r2
    shll2 r2
    add r4, r2
    mov.l r2, @r15
    mov #0x0, r3
    mov.l r3, @(52, r15)
    mov r3, r6
    mov #0xB, r3
    mov.l r3, @(28, r15)
    mov.l r3, @(56, r15)
    mov #0x3B, r3
    cmp/hs r3, r5
    bf      .L_check_end_col_low
    mov #0x45, r3
    sub r5, r3
    bra     .L_clamp_start_col
    mov.l r3, @(56, r15)

    .global DAT_06006da6
DAT_06006da6:
    .2byte  0x0640
.L_heading_bias:
    .2byte  0x0800
.L_row_stride:
    .2byte  0x00F2
.L_vis_table_extra_offset:
    .2byte  0x2000
    .2byte  0xFFFF
.L_sort_buf_idx_ptr:
    .4byte  sym_060620D4
.L_player_mode_ptr:
    .4byte  sym_0607EAD8
.L_cam_heading_ptr:
    .4byte  sym_06063EF0
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_dispatch_table_a:
    .4byte  sym_06062248
.L_vis_table_base_offset:
    .4byte  0x002F0000                  /* vis table base address offset */
.L_dispatch_table_b:
    .4byte  sym_06062260
.L_cam_orient_data:
    .4byte  sym_06063DF8
.L_column_rounding:
    .4byte  0x04000000                  /* angle-to-column rounding bias */
.L_check_end_col_low:
    mov #0x5, r3
    cmp/hs r3, r5
    bt      .L_clamp_start_col
    mov #0x5, r6
    sub r5, r6
.L_clamp_start_col:
    mov #0x3B, r3
    cmp/hs r3, r4
    bf      .L_check_start_col_low
    mov #0x45, r3
    sub r4, r3
    bra     .L_ranges_ready
    mov.l r3, @(28, r15)
.L_check_start_col_low:
    mov #0x5, r3
    cmp/hs r3, r4
    bt      .L_ranges_ready
    mov #0x5, r3
    sub r4, r3
    mov.l r3, @(52, r15)
.L_ranges_ready:
    mov.l   .L_render_param_ptr, r8
    bra     .L_outer_loop_test
    mov.l r6, @(8, r15)
.L_outer_loop_body:
    mov.l @(52, r15), r2
    mov.l r2, @(4, r15)
    mov.l @(8, r15), r3
    mov #0xB, r2
    mul.l r2, r3
    sts macl, r3
    bra     .L_inner_loop_test
    mov.l r3, @(32, r15)
.L_inner_loop_body:
    mov.l @(32, r15), r0
    mov.l @(4, r15), r3
    mov.l @(36, r15), r2
    add r3, r0
    shll r0
    mov.w @(r0, r2), r9
    tst r9, r9
    bf      .L_cell_visible
    bra     .L_next_column
    nop
.L_cell_visible:
    exts.w r9, r4
    mov.l @r15, r3
    mov.l @(40, r15), r12
    mov.l @(44, r15), r2
    add r3, r4
    shll r4
    add r4, r12
    mov.w @r12, r12
    add r2, r4
    exts.w r12, r1
    cmp/pl r1
    bf/s    .L_pass_a_done
    mov.w @r4, r11
    exts.w r9, r0
    mov.l @r15, r3
    mov.l @(48, r15), r2
    mov.l @r13, r1
    add r3, r0
    shll2 r1
    shll2 r0
    mov.l   .L_pipeline_state_arr, r3
    shll r1
    mov.l @(r0, r2), r0
    add r3, r1
    exts.w r12, r3
    mov.l @r1, r1
    add r1, r0
    mov.l r0, @(20, r15)
    mov.l @r10, r1
    add r1, r3
    cmp/hs r14, r3
    bf      .L_pass_a_no_wrap
    mov.l @r10, r2
    mov r14, r12
    sub r2, r12
    exts.w r12, r12
.L_pass_a_no_wrap:
    mov.l @r13, r0
    cmp/eq #0x2, r0
    bt      .L_pass_a_mode_2
    exts.w r12, r7
    mov.w @r8, r6
    mov.l @(12, r15), r5
    mov.l   .L_fn_scene_process_b, r3
    extu.w r6, r6
    jsr @r3
    mov.l @(20, r15), r4
    bra     .L_pass_a_done
    nop
    .2byte  0xFFFF
.L_render_param_ptr:
    .4byte  sym_06089E96
.L_pipeline_state_arr:
    .4byte  sym_06062230
.L_fn_scene_process_b:
    .4byte  sym_0602ABB8
.L_pass_a_mode_2:
    exts.w r12, r7
    mov.w @r8, r6
    mov.l @(12, r15), r5
    mov.l   .L_fn_scene_proc_d, r3
    extu.w r6, r6
    jsr @r3
    mov.l @(20, r15), r4
.L_pass_a_done:
    exts.w r11, r2
    cmp/pl r2
    bf      .L_next_column
    exts.w r9, r0
    mov.l @r15, r2
    mov.l @r13, r12
    mov.l   .L_pipeline_state_arr_b, r3
    mov.l @(24, r15), r1
    add r2, r0
    shll r12
    shll2 r0
    add #0x1, r12
    shll2 r12
    add r3, r12
    mov.l @r12, r12
    mov.l @(r0, r1), r3
    exts.w r11, r0
    add r3, r12
    mov.l @r10, r3
    add r3, r0
    cmp/hs r14, r0
    bf      .L_pass_b_no_wrap
    mov.l @r10, r3
    mov r14, r11
    sub r3, r11
    exts.w r11, r11
.L_pass_b_no_wrap:
    mov.l @r13, r0
    cmp/eq #0x2, r0
    bt      .L_pass_b_mode_2
    exts.w r11, r7
    mov.w @r8, r6
    mov.l @(16, r15), r5
    mov.l   .L_fn_scene_process_b_2, r3
    extu.w r6, r6
    jsr @r3
    mov r12, r4
    bra     .L_next_column
    nop
.L_pass_b_mode_2:
    exts.w r11, r7
    mov.w @r8, r6
    mov.l @(16, r15), r5
    mov.l   .L_fn_scene_proc_d, r3
    extu.w r6, r6
    jsr @r3
    mov r12, r4
.L_next_column:
    mov.l @(4, r15), r2
    add #0x1, r2
    mov.l r2, @(4, r15)
.L_inner_loop_test:
    mov.l @(4, r15), r3
    mov.l @(28, r15), r2
    cmp/hs r2, r3
    bf      .L_inner_loop_body
    mov.l @(8, r15), r2
    add #0x1, r2
    mov.l r2, @(8, r15)
.L_outer_loop_test:
    mov.l @(8, r15), r3
    mov.l @(56, r15), r2
    cmp/hs r2, r3
    bt      .L_epilogue
    bra     .L_outer_loop_body
    nop
.L_epilogue:
    add #0x3C, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_fn_scene_proc_d:
    .4byte  sym_0602B9E0
.L_pipeline_state_arr_b:
    .4byte  sym_06062230
.L_fn_scene_process_b_2:
    .4byte  sym_0602ABB8
