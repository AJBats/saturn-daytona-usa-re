
    .section .text.FUN_0603853C


    .global scene_data_write_abs
    .type scene_data_write_abs, @function
scene_data_write_abs:
    mov.l r14, @-r15
    mov.l   .L_pool_color_accum_ptr, r14
    mov.l   .L_pool_scene_buf_a, r7
    mov.l   .L_pool_scene_mode, r0
    bra     .L_dispatch_mode
    mov.l @r0, r0
.L_mode_04_set_pos_xy:
    mov.l r4, @r7
    bra     .L_return
    mov.l r5, @(4, r7)
.L_mode_08_set_scale_xy:
    mov.l r4, @(16, r7)
    bra     .L_return
    mov.l r5, @(20, r7)
.L_mode_10_set_hi16_xy_a:
    shlr16 r4
    exts.w r4, r4
    extu.w r4, r4
    mov #0x20, r0
    mov.w r4, @(r0, r7)
    shlr16 r5
    exts.w r5, r5
    extu.w r5, r5
    bra     .L_store_hi16_y
    mov #0x22, r0
.L_mode_20_set_hi16_xy_b:
    shlr16 r4
    exts.w r4, r4
    extu.w r4, r4
    mov #0x24, r0
    mov.w r4, @(r0, r7)
    shlr16 r5
    exts.w r5, r5
    extu.w r5, r5
    mov #0x26, r0
.L_store_hi16_y:
    bra     .L_return
    mov.w r5, @(r0, r7)
.L_mode_01_set_view_chan1:
    mov #0x44, r0
    mov.l   .L_pool_scene_view_ch1, r7
    mov.l r4, @(r0, r7)
    mov #0x48, r0
    mov.l r5, @(r0, r7)
    mov.l   .L_pool_scene_a_src, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_ch1_clear_accum
    mov.l   .L_pool_scene_a_flag, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_ch1_store_color
    mov.l   .L_pool_xform_flag_a, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_ch1_clear_accum
.L_ch1_store_color:
    bra     .L_ch1_check_tailcall
    mov.l r6, @r14
.L_ch1_clear_accum:
    mov #0x0, r2
    mov.l r2, @r14
.L_ch1_check_tailcall:
    mov.l @r14, r0
    tst r0, r0
    bt      .L_return
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
    mov.l   .L_pool_scene_color_matrix_ch1, r3
    jmp @r3
    mov.l @r15+, r14
.L_mode_02_set_view_chan2:
    mov #0x44, r0
    mov.l   .L_pool_scene_view_ch2, r7
    mov.l r4, @(r0, r7)
    mov #0x48, r0
    mov.l r5, @(r0, r7)
    mov.l   .L_pool_scene_b_src, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_ch2_clear_accum
    mov.l   .L_pool_scene_b_flag, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_ch2_store_color
    mov.l   .L_pool_xform_flag_b, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_ch2_clear_accum
.L_ch2_store_color:
    bra     .L_ch2_check_tailcall
    mov.l r6, @(4, r14)
.L_pool_color_accum_ptr:
    .4byte  sym_060A4C78
.L_pool_scene_buf_a:
    .4byte  sym_060A3DF8
.L_pool_scene_mode:
    .4byte  sym_060635A8
.L_pool_scene_view_ch1:
    .4byte  sym_060A3E68
.L_pool_scene_a_src:
    .4byte  sym_060A4C44
.L_pool_scene_a_flag:
    .4byte  sym_060A4C4C
.L_pool_xform_flag_a:
    .4byte  sym_060A4C70
.L_pool_scene_color_matrix_ch1:
    .4byte  scene_color_matrix
.L_pool_scene_view_ch2:
    .4byte  sym_060A3EE8
.L_pool_scene_b_src:
    .4byte  sym_060A4C48
.L_pool_scene_b_flag:
    .4byte  sym_060A4C50
.L_pool_xform_flag_b:
    .4byte  sym_060A4C74
.L_ch2_clear_accum:
    mov #0x0, r2
    mov.l r2, @(4, r14)
.L_ch2_check_tailcall:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_return
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
    .byte   0xD3, 0x21    /* mov.l .L_pool_scene_color_matrix_ch2, r3 */  ! r3 = &scene_color_matrix (pool in scene_data_write_add TU)
    jmp @r3
    mov.l @r15+, r14
.L_dispatch_mode:
    cmp/eq #0x1, r0
    bt      .L_mode_01_set_view_chan1
    cmp/eq #0x2, r0
    bt      .L_mode_02_set_view_chan2
    cmp/eq #0x4, r0
    bt      .L_mode_04_set_pos_xy
    cmp/eq #0x8, r0
    bt      .L_mode_08_set_scale_xy
    cmp/eq #0x10, r0
    bt      .L_mode_10_set_hi16_xy_a
    cmp/eq #0x20, r0
    bt      .L_mode_20_set_hi16_xy_b
.L_return:
    rts
    mov.l @r15+, r14
