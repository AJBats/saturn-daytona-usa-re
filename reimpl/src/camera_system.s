
    .section .text.FUN_0600BB94


    .global camera_system
    .type camera_system, @function
camera_system:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_fn_cmd_queue_commit, r8
    mov.l   .L_camera_heading_ptr, r9
    mov.l   .L_camera_z_offset_ptr, r10
    mov.l   .L_camera_up_vec, r11
    mov.l   .L_camera_target_ptr, r12
    mov.l   .L_player_car_ptr, r14
    mov.l @r14, r14
    mov.l   .L_camera_state_b, r7
    mov #0x2, r6
    mov.w   DAT_0600bc2c, r5
    mov #0x1, r4
    mov.l   .L_camera_eye_pos, r13
    mov.l   .L_camera_mode_ptr, r0
    mov.b @r0, r0
    bra     .L_mode_dispatch
    extu.b r0, r0
.L_mode1_entry:
    mov.l   .L_scene_active_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_mode1_idle
    bra     .L_camera_exit
    nop
.L_mode1_idle:
    mov.l @r7, r3
    cmp/hi r4, r3
    bt      .L_mode1_update
    mov.l @(32, r14), r3
    mov.w   DAT_0600bc2e, r0
    mov.l @(r0, r14), r2
    add r2, r3
    mov.l r3, @(4, r12)
.L_mode1_update:
    mov.l   .L_camera_scroll_val, r4
    .byte   0xB3, 0xE0    /* bsr 0x0600C3A8 (external) */
    mov.w @r4, r4
    bra     .L_camera_exit
    nop
.L_mode7_entry:
    mov.w   .L_gear_state_offset_a, r0
    mov #0x30, r3
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_mode7_check_28
    bra     .L_mode7_apply
    nop
.L_mode7_check_28:
    mov #0x28, r3
    mov.w   .L_gear_state_offset_a, r0
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_mode7_check_10
    mov.l @r13, r2
    sub r5, r2
    bra     .L_mode7_apply
    mov.l r2, @r13
.L_mode7_check_10:
    mov.w   .L_gear_state_offset_a, r0
    mov #0x10, r3
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_mode7_check_8
    bra     .L_mode7_apply
    nop
.L_mode7_check_8:
    mov #0x8, r3
    mov.w   .L_gear_state_offset_a, r0
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_mode7_gear_check
    mov.l @r13, r2
    add r5, r2
    bra     .L_mode7_apply
    mov.l r2, @r13

    .global DAT_0600bc2c
DAT_0600bc2c:
    .2byte  0x2C00

    .global DAT_0600bc2e
DAT_0600bc2e:
    .2byte  0x01D8
.L_gear_state_offset_a:
    .2byte  0x01BC
    .2byte  0xFFFF
.L_fn_cmd_queue_commit:
    .4byte  sym_06038520
.L_camera_heading_ptr:
    .4byte  sym_06063E28
.L_camera_z_offset_ptr:
    .4byte  sym_06063E30
.L_camera_up_vec:
    .4byte  sym_06063EF8
.L_camera_target_ptr:
    .4byte  sym_06063EEC
.L_player_car_ptr:
    .4byte  sym_0607E944
.L_camera_state_b:
    .4byte  sym_06063E20
.L_camera_eye_pos:
    .4byte  sym_06063E24
.L_camera_mode_ptr:
    .4byte  sym_06078654
.L_scene_active_flag:
    .4byte  sym_0605A1C4
.L_camera_scroll_val:
    .4byte  sym_06063D9A
.L_mode7_gear_check:
    mov.w   DAT_0600bcee, r0
    mov.l @(r0, r14), r5
    mov r5, r0
    cmp/eq #0x8, r0
    bt      .L_mode7_cinematic_init
    mov r5, r0
    cmp/eq #0x7, r0
    bf      .L_mode7_apply
.L_mode7_cinematic_init:
    mov.l   .L_camera_state_a, r3
    mov #0x0, r5
    mov.l r6, @r3
    mov.l   .L_cinematic_config_a, r3
    mov.l r4, @r3
    mov.l   .L_fn_channel_nibble, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_cinematic_eye_y, r2
    mov.l r2, @r13
    mov.l   .L_cinematic_heading_val, r3
    mov.l   .L_camera_heading_store, r2
    mov.l r3, @r2
    mov.l   .L_cinematic_base_offset, r3
    mov.l r3, @r9
    mov.l   .L_fp_sixteen, r2
    mov.l   .L_camera_zoom_factor, r3
    mov.l r2, @r3
    mov #0x0, r2
    mov.l r2, @r10
.L_mode7_apply:
    mov.l   .L_camera_scroll_val_b, r4
    .byte   0xB3, 0x85    /* bsr 0x0600C3A8 (external) */
    mov.w @r4, r4
    bra     .L_camera_exit
    nop
.L_mode4_entry:
    mov.w   DAT_0600bcee, r0
    mov.l @(r0, r14), r0
    tst r0, r0
    bf      .L_mode4_speed_check
    bra     .L_mode4_finalize
    mov.l r6, @r7
.L_mode4_speed_check:
    mov #0x30, r3
    mov.w   DAT_0600bcee, r0
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_mode4_check_28
    bra     .L_mode4_finalize
    nop
.L_mode4_check_28:
    mov.w   DAT_0600bcee, r0
    mov #0x28, r3
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_mode4_check_10
    mov.l @r13, r2
    sub r5, r2
    bra     .L_mode4_finalize
    mov.l r2, @r13
.L_mode4_check_10:
    mov #0x10, r3
    mov.w   DAT_0600bcee, r0
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_mode4_check_8
    bra     .L_mode4_finalize
    nop
.L_mode4_check_8:
    mov.w   DAT_0600bcee, r0
    mov #0x8, r3
    mov.l @(r0, r14), r2
    cmp/gt r3, r2
    bf      .L_mode4_gear_check
    mov.l @r13, r2
    add r5, r2
    bra     .L_mode4_finalize
    mov.l r2, @r13

    .global DAT_0600bcee
DAT_0600bcee:
    .2byte  0x01BC
.L_camera_state_a:
    .4byte  sym_06063E1C
.L_cinematic_config_a:
    .4byte  sym_06059F30
.L_fn_channel_nibble:
    .4byte  channel_nibble_config
.L_cinematic_eye_y:
    .4byte  0x00058000
.L_cinematic_heading_val:
    .4byte  0x0000F300
.L_camera_heading_store:
    .4byte  sym_06063E34
.L_cinematic_base_offset:
    .4byte  0x006E0000
.L_fp_sixteen:
    .4byte  0x00100000                  /* 16.0 (16.16 fixed-point) */
.L_camera_zoom_factor:
    .4byte  sym_06063E2C
.L_camera_scroll_val_b:
    .4byte  sym_06063D9A
.L_mode4_gear_check:
    mov.w   DAT_0600bdac, r0
    mov.l @(r0, r14), r5
    mov r5, r0
    cmp/eq #0x8, r0
    bt      .L_mode4_cinematic_init
    mov r5, r0
    cmp/eq #0x7, r0
    bf      .L_mode4_finalize
.L_mode4_cinematic_init:
    mov.l   .L_camera_state_a_b, r3
    mov #0x0, r5
    mov.l r6, @r3
    mov.l   .L_cinematic_config_a_b, r3
    mov.l r4, @r3
    mov.l   .L_fn_channel_nibble_b, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_cinematic_eye_y_b, r2
    mov.l r2, @r13
    mov.l   .L_cinematic_heading_b, r3
    mov.l   .L_camera_heading_store_b, r2
    mov.l r3, @r2
    mov.l   .L_cinematic_offset_b, r3
    mov.l r3, @r9
    mov.l   .L_fp_sixteen_b, r2
    mov.l   .L_camera_zoom_b, r3
    mov.l r2, @r3
    mov #0x0, r2
    mov.l r2, @r10
.L_mode4_finalize:
    mov.l @(32, r14), r3
    mov.w   DAT_0600bdae, r0
    mov.l @(r0, r14), r2
    sub r2, r3
    mov.l r3, @(4, r12)
    mov.l @(r0, r14), r3
    mov.l   .L_fp_half, r2
    neg r3, r3
    add r2, r3
    shar r3
    shar r3
    shar r3
    shar r3
    mov.l @(r0, r14), r1
    add r3, r1
    bra     .L_camera_exit
    mov.l r1, @(r0, r14)
.L_mode6_entry:
    mov #0x3, r2
    mov.l r2, @r7
.L_mode0_nop:
    bra     .L_camera_exit
    nop
.L_mode_dispatch:
    cmp/eq #0x0, r0
    bt      .L_mode0_nop
    cmp/eq #0x1, r0
    bf      .L_mode_not_1
    bra     .L_mode1_entry
    nop
.L_mode_not_1:
    cmp/eq #0x4, r0
    bt      .L_mode4_entry
    cmp/eq #0x6, r0
    bt      .L_mode6_entry
    cmp/eq #0x7, r0
    bf      .L_camera_exit
    bra     .L_mode7_entry
    nop
.L_camera_exit:
    mov.l   .L_camera_dir_flip, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_dir_negative
    mov.l @(4, r12), r13
    shll8 r13
    shll2 r13
    mov.l   .L_positive_y_base, r3
    add r3, r13
    bra     .L_apply_camera_path
    nop

    .global DAT_0600bdac
DAT_0600bdac:
    .2byte  0x01BC

    .global DAT_0600bdae
DAT_0600bdae:
    .2byte  0x0244
.L_camera_state_a_b:
    .4byte  sym_06063E1C
.L_cinematic_config_a_b:
    .4byte  sym_06059F30
.L_fn_channel_nibble_b:
    .4byte  channel_nibble_config
.L_cinematic_eye_y_b:
    .4byte  0x00058000
.L_cinematic_heading_b:
    .4byte  0x0000F300
.L_camera_heading_store_b:
    .4byte  sym_06063E34
.L_cinematic_offset_b:
    .4byte  0x006E0000
.L_fp_sixteen_b:
    .4byte  0x00100000                  /* 16.0 (16.16 fixed-point) */
.L_camera_zoom_b:
    .4byte  sym_06063E2C
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_camera_dir_flip:
    .4byte  sym_06078663
.L_positive_y_base:
    .4byte  0x01A00000
.L_dir_negative:
    mov.l @(4, r12), r13
    shll8 r13
    shll2 r13
    neg r13, r13
    mov.l   .L_negative_y_base, r3
    add r3, r13
.L_apply_camera_path:
    mov.l   .L_alt_camera_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_standard_camera
    mov.l   .L_fn_cmd_queue_write, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r6
    mov.l @r9, r5
    mov.l   .L_fn_scene_data_write, r3
    jsr @r3
    mov r13, r4
    jsr @r8
    nop
    mov r15, r6
    mov r15, r5
    mov.l   .L_fn_sincos_pair, r3
    add #0x4, r6
    jsr @r3
    mov.l @(4, r12), r4
    mov.l @(16, r14), r2
    mov.l @r15, r3
    sub r3, r2
    mov.l   .L_xz_adjust_x, r1
    mov.l @r1, r1
    add r1, r2
    mov.l r2, @r11
    mov.l @(20, r14), r3
    mov.l @r10, r2
    add r2, r3
    mov.l r3, @(4, r11)
    mov.l @(24, r14), r3
    mov.l @(4, r15), r2
    add r2, r3
    mov.l   .L_xz_adjust_z, r1
    mov.l @r1, r1
    add r1, r3
    bra     .L_camera_return
    mov.l r3, @(8, r11)
.L_standard_camera:
    mov.w   .L_car_gear_offset_c, r0
    mov.l @(r0, r14), r0
    tst r0, r0
    bf      .L_standard_with_scroll
    mov.l   .L_fn_scene_fallback, r3
    jsr @r3
    nop
    bra     .L_standard_render
    nop
.L_car_gear_offset_c:
    .2byte  0x01BC
    .2byte  0xFFFF
.L_negative_y_base:
    .4byte  0xFFA00000
.L_alt_camera_flag:
    .4byte  sym_06082A30
.L_fn_cmd_queue_write:
    .4byte  sym_0603850C
.L_fn_scene_data_write:
    .4byte  scene_data_write_abs
.L_fn_sincos_pair:
    .4byte  sincos_pair
.L_xz_adjust_x:
    .4byte  sym_06082A70
.L_xz_adjust_z:
    .4byte  sym_06082A78
.L_fn_scene_fallback:
    .4byte  scene_fallback_render
.L_standard_with_scroll:
    mov.w   DAT_0600bf3c, r4
    mov.l   .L_zoom_store_x, r3
    mov.l r4, @r3
    mov.l   .L_zoom_store_y, r3
    mov.l r4, @r3
.L_standard_render:
    mov.l   .L_fn_cmd_queue_write_b, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r6
    mov.l @r9, r5
    mov.l   .L_fn_scene_data_write_b, r3
    jsr @r3
    mov r13, r4
    jsr @r8
    nop
    mov.l @(28, r14), r13
    shll8 r13
    cmp/pz r13
    bt      .L_speed_scaled
    shll r13
.L_speed_scaled:
    mov.l   .L_fn_cmd_queue_write_b, r3
    jsr @r3
    mov #0x8, r4
    mov #0x0, r6
    mov.l   .L_scroll_plane_sel, r0
    mov.l   .L_scroll_table_base, r3
    mov.l   .L_camera_zoom_ref, r2
    mov.w @r0, r0
    mov.l @r2, r2
    extu.w r0, r0
    add r13, r2
    and #0xC, r0
    mov r0, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    shll8 r5
    shll r5
    add r2, r5
    mov.l   .L_fn_scene_data_write_b, r2
    jsr @r2
    mov r6, r4
    jsr @r8
    nop
    mov.l   .L_fn_obj_state_mgr, r3
    jsr @r3
    nop
    mov r15, r6
    mov r15, r5
    mov.l   .L_fn_sincos_pair_b, r3
    add #0x4, r6
    jsr @r3
    mov.l @(4, r12), r4
    mov.l @(16, r14), r2
    mov.l @r15, r3
    sub r3, r2
    mov.l r2, @r11
    mov.l @(20, r14), r3
    mov.l @r10, r2
    add r2, r3
    mov.l r3, @(4, r11)
    mov.l @(24, r14), r3
    mov.l @(4, r15), r2
    add r2, r3
    mov.l r3, @(8, r11)
    bsr     .L_heading_smooth
    nop
    mov.l @(4, r12), r4
    mov.l @(32, r14), r2
    mov.l   .L_fn_cos_lookup, r3
    jsr @r3
    sub r2, r4
    mov r0, r5
    mov r0, r2
    mov.l   .L_smooth_factor_store, r3
    shar r2
    shar r2
    shar r2
    shar r2
    shar r2
    shar r2
    shar r2
    neg r2, r2
    mov.l r2, @r3
    mov.l   .L_fn_fpmul, r3
    jsr @r3
    mov.l @(36, r14), r4
    mov r0, r4
    mov.l @(8, r12), r2
    add r2, r4
    shar r4
    mov.l r4, @(8, r12)
.L_camera_return:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0600bf3c
DAT_0600bf3c:
    .2byte  0x6666
    .2byte  0xFFFF
.L_zoom_store_x:
    .4byte  sym_06063F04
.L_zoom_store_y:
    .4byte  sym_06063F08
.L_fn_cmd_queue_write_b:
    .4byte  sym_0603850C
.L_fn_scene_data_write_b:
    .4byte  scene_data_write_abs
.L_scroll_plane_sel:
    .4byte  sym_06063F46
.L_scroll_table_base:
    .4byte  sym_0605BDCC
.L_camera_zoom_ref:
    .4byte  sym_06063E2C
.L_fn_obj_state_mgr:
    .4byte  obj_state_manager
.L_fn_sincos_pair_b:
    .4byte  sincos_pair
.L_fn_cos_lookup:
    .4byte  cos_lookup
.L_smooth_factor_store:
    .4byte  sym_06078668
.L_fn_fpmul:
    .4byte  fpmul
.L_heading_smooth:
    sts.l macl, @-r15
    mov.l   .L_hs_player_car_ptr, r4
    mov.w   DAT_0600bfe2, r3
    mov.l   .L_hs_heading_store, r2
    mov.l   .L_hs_target_heading, r5
    mov.l @r4, r4
    mov.l @r2, r2
    mov.l @(28, r4), r4
    exts.w r4, r4
    mul.l r3, r4
    exts.w r2, r3
    sts macl, r4
    mov.l   .L_hs_state_a, r2
    shar r4
    mov.l @r2, r2
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    add r3, r4
    mov.l   .L_hs_state_b, r3
    mov.l @r3, r3
    cmp/eq r3, r2
    bf/s    .L_hs_snap
    exts.w r4, r4
    mov.l @r5, r3
    exts.w r4, r4
    mov.w   .L_hs_blend_old, r1
    mov.w   .L_hs_blend_new, r2
    exts.w r3, r3
    mul.l r2, r3
    sts macl, r3
    mul.l r1, r4
    sts macl, r4
    add r4, r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    mov.l r3, @r5
    bra     .L_hs_done
    nop
.L_hs_snap:
    exts.w r4, r4
    mov.l r4, @r5
.L_hs_done:
    rts
    lds.l @r15+, macl

    .global DAT_0600bfe2
DAT_0600bfe2:
    .2byte  0x0384
.L_hs_blend_new:
    .2byte  0x0320
.L_hs_blend_old:
    .2byte  0x00E0
.L_hs_player_car_ptr:
    .4byte  sym_0607E944
.L_hs_heading_store:
    .4byte  sym_06063E34
.L_hs_target_heading:
    .4byte  sym_06063EEC
.L_hs_state_a:
    .4byte  sym_06063E1C
.L_hs_state_b:
    .4byte  sym_06063E20
