
    .section .text.FUN_0600B340


    .global scene_render_coord
    .type scene_render_coord, @function
scene_render_coord:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_ptr_camera_state, r11
    mov.l @r11, r11
    mov.l   .L_ptr_car_array_base, r14
    mov.l @r14, r14
    mov.l   .L_ptr_cur_car_struct, r3
    mov.l r14, @r3
    mov.l   .L_ptr_course_index, r0
    bra     .L_course_dispatch
    mov.l @r0, r0
.L_course_0:
    mov.l   .L_ptr_cs0_dist_tbl, r13
    mov.l   .L_ptr_cs0_render_tbl, r12
    bra     .L_tables_selected
    nop
.L_course_1:
    mov.l   .L_ptr_cs1_dist_tbl, r13
    mov.l   .L_ptr_cs1_render_tbl, r12
    bra     .L_tables_selected
    nop
.L_course_2:
    mov.l   .L_ptr_cs2_dist_tbl, r13
    mov.l   .L_ptr_cs2_render_tbl, r12
    bra     .L_tables_selected
    nop
    .2byte  0xFFFF
.L_ptr_camera_state:
    .4byte  sym_0607EB8C
.L_ptr_car_array_base:
    .4byte  sym_0607E944
.L_ptr_cur_car_struct:
    .4byte  sym_0607E940
.L_ptr_course_index:
    .4byte  sym_0607EAD8
.L_ptr_cs0_dist_tbl:
    .4byte  sym_06063488
.L_ptr_cs0_render_tbl:
    .4byte  sym_06063434
.L_ptr_cs1_dist_tbl:
    .4byte  sym_060634A4
.L_ptr_cs1_render_tbl:
    .4byte  sym_06063450
.L_ptr_cs2_dist_tbl:
    .4byte  sym_060634C0
.L_ptr_cs2_render_tbl:
    .4byte  sym_0606346C
.L_course_dispatch:
    cmp/eq #0x0, r0
    bt      .L_course_0
    cmp/eq #0x1, r0
    bt      .L_course_1
    cmp/eq #0x2, r0
    bt      .L_course_2
.L_tables_selected:
    mov.l   .L_fn_transform_init, r3
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.l   .L_fn_set_position, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov.l   .L_fn_rot_xy, r3
    jsr @r3
    mov.l @(32, r14), r4
    mov.l   .L_fn_rot_yz, r3
    jsr @r3
    mov.l @(36, r14), r4
    mov.l   .L_fn_rot_xz, r3
    jsr @r3
    mov.l @(28, r14), r4
    mov.w   DAT_0600b47a, r0
    mov.l   .L_fn_rot_xy, r3
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r2
    jsr @r3
    add r2, r4
    mov.l   .L_ptr_secondary_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_decrement_budget
    mov.l   .L_ptr_lod_dist_param, r5
    mov.l   .L_fn_dist_check, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(24, r13), r4
    mov.l   .L_ptr_lod_scale_param, r6
    mov.l   .L_ptr_sprite_index_tbl, r2
    mov.l @r6, r6
    mov r2, r5
    mov.l r2, @(4, r15)
    mov.w @r5, r5
    mov.l   .L_fn_render_submit, r3
    extu.w r5, r5
    jsr @r3
    mov.l @(24, r12), r4
    mov #0x0, r6
    mov.w   DAT_0600b47c, r0
    mov.l   .L_fn_set_position, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   DAT_0600b47e, r0
    mov.l   .L_fn_rot_yz, r3
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   .L_off_cam_pitch_b, r0
    mov.l   .L_ptr_height_offset, r2
    mov.l   .L_fn_rot_xz, r3
    mov.l @(r0, r14), r4
    mov.l @r2, r2
    jsr @r3
    add r2, r4
    mov.l @(12, r11), r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_ptr_dist_tbl_indexed, r3
    mov.l @r15, r4
    mov.l   .L_fn_dist_check, r2
    add r3, r5
    add r13, r4
    mov.l @r5, r5
    jsr @r2
    mov.l @r4, r4
    mov.l @(12, r11), r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_ptr_render_tbl_indexed, r3
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l   .L_fn_render_submit, r2
    add r3, r6
    mov.w @r5, r5
    add r12, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r2
    mov.l @r4, r4
    .byte   0xB9, 0x89    /* bsr 0x0600A76C (secondary_geom_proc) */
    nop
.L_decrement_budget:
    mov.l   .L_ptr_render_budget, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    mov.l   .L_ptr_early_exit_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_normal_return
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA0, 0x2C    /* bra 0x0600B4D2 (camera_lerp, external) */
    mov.l @r15+, r14

    .global DAT_0600b47a
DAT_0600b47a:
    .2byte  0x01D8

    .global DAT_0600b47c
DAT_0600b47c:
    .2byte  0x01B4

    .global DAT_0600b47e
DAT_0600b47e:
    .2byte  0x01D0
.L_off_cam_pitch_b:
    .2byte  0x01C8
    .2byte  0xFFFF
.L_fn_transform_init:
    .4byte  sym_06027080
.L_fn_set_position:
    .4byte  sym_060270F2
.L_fn_rot_xy:
    .4byte  mat_rot_xy_b
.L_fn_rot_yz:
    .4byte  mat_rot_yz_b
.L_fn_rot_xz:
    .4byte  mat_rot_xz_b
.L_ptr_secondary_flag:
    .4byte  sym_06059F30
.L_ptr_lod_dist_param:
    .4byte  sym_06063510
.L_fn_dist_check:
    .4byte  sym_06032158
.L_ptr_lod_scale_param:
    .4byte  sym_060634F4
.L_ptr_sprite_index_tbl:
    .4byte  sym_06089E98
.L_fn_render_submit:
    .4byte  sym_06031DF4
.L_ptr_height_offset:
    .4byte  sym_06083258
.L_ptr_dist_tbl_indexed:
    .4byte  sym_060634F8
.L_ptr_render_tbl_indexed:
    .4byte  sym_060634DC
.L_ptr_render_budget:
    .4byte  sym_0608A52C
.L_ptr_early_exit_flag:
    .4byte  sym_0607867C
.L_normal_return:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
