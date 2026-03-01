
    .section .text.FUN_0600B1A0


    .global course_obj_transform
    .type course_obj_transform, @function
course_obj_transform:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_ptr_config_struct, r11
    mov.l @r11, r11
    mov.l   .L_ptr_car_array_base, r14
    mov.l @r14, r14
    mov.l   .L_ptr_current_car, r3
    mov.l r14, @r3
    mov.l   .L_ptr_race_variant, r0
    bra     .L_dispatch_variant
    mov.l @r0, r0
.L_variant_0:
    mov.l   .L_ptr_rot_src_state0, r13
    mov.l   .L_ptr_rot_dst_state0, r12
    bra     .L_run_transform_chain
    nop
.L_variant_1:
    mov.l   .L_ptr_rot_src_state1, r13
    mov.l   .L_ptr_rot_dst_state1, r12
    bra     .L_run_transform_chain
    nop
.L_variant_2:
    mov.l   .L_ptr_rot_src_state2, r13
    mov.l   .L_ptr_rot_dst_state2, r12
    bra     .L_run_transform_chain
    nop
    .2byte  0xFFFF
    .4byte  sym_06083258
    .4byte  sym_060621D8
    .4byte  sym_0606212C
    .4byte  sym_06032158
    .4byte  sym_06062180
    .4byte  sym_06089E44
    .4byte  sym_060620D8
    .4byte  sym_06031DF4
    .4byte  sym_0607EBC4
    .4byte  0x20020000
    .4byte  master_ctrl_dispatch
    .4byte  sym_0608A52C
.L_ptr_config_struct:
    .4byte  sym_0607EB8C
.L_ptr_car_array_base:
    .4byte  sym_0607E944
.L_ptr_current_car:
    .4byte  sym_0607E940
.L_ptr_race_variant:
    .4byte  sym_0607EAD8
.L_ptr_rot_src_state0:
    .4byte  sym_06063488
.L_ptr_rot_dst_state0:
    .4byte  sym_06063434
.L_ptr_rot_src_state1:
    .4byte  sym_060634A4
.L_ptr_rot_dst_state1:
    .4byte  sym_06063450
.L_ptr_rot_src_state2:
    .4byte  sym_060634C0
.L_ptr_rot_dst_state2:
    .4byte  sym_0606346C
.L_dispatch_variant:
    cmp/eq #0x0, r0
    bt      .L_variant_0
    cmp/eq #0x1, r0
    bt      .L_variant_1
    cmp/eq #0x2, r0
    bt      .L_variant_2
.L_run_transform_chain:
    mov.l   .L_fn_pre_transform_setup, r3
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.l   .L_fn_transform_dispatch, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov.l   .L_fn_mat_rot_y, r3
    jsr @r3
    mov.l @(32, r14), r4
    mov.l   .L_fn_mat_rot_z, r3
    jsr @r3
    mov.l @(36, r14), r4
    mov.l   .L_fn_mat_rot_x, r3
    jsr @r3
    mov.l @(28, r14), r4
    mov.w   .L_off_car_extra_rot, r0
    mov.l   .L_fn_mat_rot_y, r3
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r2
    jsr @r3
    add r2, r4
    mov.l   .L_ptr_cam_follow_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_epilogue
    mov.l   .L_ptr_scale_src_vec, r5
    mov.l   .L_fn_vec_copy_a, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(24, r13), r4
    mov.l   .L_ptr_rot_data_src, r6
    mov.l   .L_ptr_mode_scale_factor, r2
    mov.l @r6, r6
    mov r2, r5
    mov.l r2, @(4, r15)
    mov.w @r5, r5
    mov.l   .L_fn_vec_copy_b, r3
    jsr @r3
    mov.l @(24, r12), r4
    mov #0x0, r6
    mov.w   .L_off_car_pos_y, r0
    mov.l   .L_fn_transform_dispatch, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   .L_off_car_rot_z_alt, r0
    mov.l   .L_fn_mat_rot_z, r3
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   .L_off_car_xform_alt, r0
    mov.l   .L_ptr_lod_offset_base, r2
    mov.l   .L_fn_mat_rot_x, r3
    mov.l @(r0, r14), r4
    mov.l @r2, r2
    jsr @r3
    add r2, r4
    mov.l @(12, r11), r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_ptr_rot_chain_a, r3
    mov.l @r15, r4
    mov.l   .L_fn_vec_copy_a, r2
    add r3, r5
    add r13, r4
    mov.l @r5, r5
    jsr @r2
    mov.l @r4, r4
    mov.l @(12, r11), r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_ptr_rot_chain_b, r3
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l   .L_fn_vec_copy_b, r2
    add r3, r6
    mov.w @r5, r5
    add r12, r4
    mov.l @r6, r6
    jsr @r2
    mov.l @r4, r4
    .byte   0xB9, 0x97    /* bsr camera_collision_avoid (dual-obj renderer) */
    nop
.L_epilogue:
    mov.l   .L_ptr_anim_counter, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_off_car_extra_rot:
    .2byte  0x01D8
.L_off_car_pos_y:
    .2byte  0x01B4
.L_off_car_rot_z_alt:
    .2byte  0x01D0
.L_off_car_xform_alt:
    .2byte  0x01C8
.L_fn_pre_transform_setup:
    .4byte  sym_06026DBC
.L_fn_transform_dispatch:
    .4byte  sym_06026E2E
.L_fn_mat_rot_y:
    .4byte  mat_rot_y
.L_fn_mat_rot_z:
    .4byte  mat_rot_z
.L_fn_mat_rot_x:
    .4byte  mat_rot_x
.L_ptr_cam_follow_flag:
    .4byte  sym_06059F30
.L_ptr_scale_src_vec:
    .4byte  sym_06063510
.L_fn_vec_copy_a:
    .4byte  sym_06031D8C
.L_ptr_rot_data_src:
    .4byte  sym_060634F4
.L_ptr_mode_scale_factor:
    .4byte  sym_06089E98
.L_fn_vec_copy_b:
    .4byte  sym_06031A28
.L_ptr_lod_offset_base:
    .4byte  sym_06083258
.L_ptr_rot_chain_a:
    .4byte  sym_060634F8
.L_ptr_rot_chain_b:
    .4byte  sym_060634DC
.L_ptr_anim_counter:
    .4byte  sym_06089EDC
