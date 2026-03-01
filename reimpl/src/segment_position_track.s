
    .section .text.FUN_06005ECC


    .global segment_position_track
    .type segment_position_track, @function
segment_position_track:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x1C, r15
    mov.l   .L_geom_ch3_data, r8
    mov.l   .L_geom_ch0_data, r9
    mov.l   .L_geom_ch2_data, r10
    mov.l   .L_geom_ch1_data, r12
    mov.l   .L_car_array_base_ptr, r14
    mov.l @r14, r14
    mov.l @(16, r14), r13
    mov.l @(20, r14), r3
    mov.l r3, @r15
    mov.l   .L_fn_pre_transform_setup, r3
    jsr @r3
    mov.l @(24, r14), r11
    mov.l   .L_fn_transform_push, r3
    jsr @r3
    nop
    mov.l @(32, r14), r4
    mov.l   .L_rotation_angle_src, r2
    mov.l   .L_fn_mat_rot_y, r3
    mov.l @r2, r2
    jsr @r3
    add r2, r4
    mov.l   .L_xform_params_ch1, r4
    mov.l   .L_fn_mat_vec_transform, r3
    jsr @r3
    mov r9, r5
    mov.l   .L_xform_params_ch0, r4
    mov.l   .L_fn_mat_vec_transform, r3
    jsr @r3
    mov r12, r5
    mov.l   .L_xform_params_ch3, r4
    mov.l   .L_fn_mat_vec_transform, r3
    jsr @r3
    mov r8, r5
    mov.l   .L_xform_params_ch2, r4
    mov.l   .L_fn_mat_vec_transform, r3
    jsr @r3
    mov r10, r5
    mov.l   .L_geom_ch4_data, r5
    mov.l   .L_xform_params_ch4, r4
    mov.l   .L_fn_mat_vec_transform, r3
    jsr @r3
    nop
    mov.l   .L_geom_ch5_data, r5
    mov.l   .L_xform_params_ch5, r4
    mov.l   .L_fn_mat_vec_transform, r3
    jsr @r3
    nop
    mov.l   .L_geom_ch7_data, r5
    mov.l   .L_xform_params_ch7, r4
    mov.l   .L_fn_mat_vec_transform, r3
    jsr @r3
    nop
    mov.l   .L_geom_ch6_data, r5
    mov.l   .L_xform_params_ch6, r4
    mov.l   .L_fn_mat_vec_transform, r3
    jsr @r3
    nop
    mov.l @r9, r2
    add r13, r2
    mov.l r2, @r9
    mov.l @r15, r3
    mov.l @(4, r9), r2
    add r3, r2
    mov.l r2, @(4, r9)
    mov.l @(8, r9), r3
    add r11, r3
    mov.l r3, @(8, r9)
    mov.l @r12, r2
    add r13, r2
    mov.l r2, @r12
    mov.l @r15, r3
    mov.l @(4, r12), r2
    add r3, r2
    mov.l r2, @(4, r12)
    mov.l @(8, r12), r3
    add r11, r3
    mov.l r3, @(8, r12)
    mov.l @r8, r2
    add r13, r2
    mov.l r2, @r8
    mov.l @r15, r3
    mov.l @(4, r8), r2
    add r3, r2
    mov.l r2, @(4, r8)
    mov.l @(8, r8), r3
    add r11, r3
    mov.l r3, @(8, r8)
    mov.l @r10, r2
    add r13, r2
    mov.l r2, @r10
    mov.l @r15, r3
    mov.l @(4, r10), r2
    add r3, r2
    mov.l r2, @(4, r10)
    mov.l @(8, r10), r3
    add r11, r3
    mov.l r3, @(8, r10)
    mov.l   .L_geom_ch4_data, r4
    mov.l @r4, r2
    add r13, r2
    mov.l r2, @r4
    mov.l @(8, r4), r3
    add r11, r3
    mov.l r3, @(8, r4)
    mov.l   .L_geom_ch5_data, r4
    mov.l @r4, r2
    add r13, r2
    mov.l r2, @r4
    mov.l @(8, r4), r3
    add r11, r3
    bra     .L_continue_delta_accum
    nop
    .2byte  0xFFFF
.L_geom_ch3_data:
    .4byte  sym_06063E88                /* geometry channel 3 position data */
.L_geom_ch0_data:
    .4byte  sym_06063E4C                /* geometry channel 0 position data */
.L_geom_ch2_data:
    .4byte  sym_06063E74                /* geometry channel 2 position data */
.L_geom_ch1_data:
    .4byte  sym_06063E60                /* geometry channel 1 position data */
.L_car_array_base_ptr:
    .4byte  sym_0607E944                /* car array base pointer (ptr-to-ptr) */
.L_fn_pre_transform_setup:
    .4byte  sym_06026DBC                /* per-object pre-transform setup */
.L_fn_transform_push:
    .4byte  sym_06026E0C                /* push/save current transform state */
.L_rotation_angle_src:
    .4byte  sym_06063F10                /* global Y-rotation angle offset */
.L_fn_mat_rot_y:
    .4byte  mat_rot_y                   /* build Y-axis rotation matrix */
.L_xform_params_ch1:
    .4byte  sym_0604464C                /* channel 1 XYZ transform params */
.L_fn_mat_vec_transform:
    .4byte  mat_vec_transform           /* matrix-vector transform */
.L_xform_params_ch0:
    .4byte  sym_06044640                /* channel 0 XYZ transform params */
.L_xform_params_ch3:
    .4byte  sym_06044658                /* channel 3 XYZ transform params */
.L_xform_params_ch2:
    .4byte  sym_06044664                /* channel 2 XYZ transform params */
.L_geom_ch4_data:
    .4byte  sym_06063E9C                /* geometry channel 4 position data */
.L_xform_params_ch4:
    .4byte  sym_06044688                /* channel 4 XYZ transform params */
.L_geom_ch5_data:
    .4byte  sym_06063EB0                /* geometry channel 5 position data */
.L_xform_params_ch5:
    .4byte  sym_0604467C                /* channel 5 XYZ transform params */
.L_geom_ch7_data:
    .4byte  sym_06063ED8                /* geometry channel 7 position data */
.L_xform_params_ch7:
    .4byte  sym_06044694                /* channel 7 XYZ transform params */
.L_geom_ch6_data:
    .4byte  sym_06063EC4                /* geometry channel 6 position data */
.L_xform_params_ch6:
    .4byte  sym_060446A0                /* channel 6 XYZ transform params */
.L_continue_delta_accum:
    mov.l r3, @(8, r4)
    mov r9, r6
    mov.l   .L_geom_ch7_data_2, r4
    add #0xE, r6
    mov.l @r4, r2
    add r13, r2
    mov.l r2, @r4
    mov.l @(8, r4), r3
    add r11, r3
    mov.l r3, @(8, r4)
    mov.l   .L_geom_ch6_data_2, r4
    mov.l @r4, r2
    add r13, r2
    mov.l r2, @r4
    mov.l @(8, r4), r3
    add r11, r3
    mov.l r3, @(8, r4)
    mov.l r6, @-r15
    mov.l @(8, r9), r5
    mov.l   .L_fn_atan2_xy, r3
    jsr @r3
    mov.l @r9, r4
    mov r0, r4
    mov r9, r5
    mov.l   .L_fn_scene_render_alt, r3
    jsr @r3
    mov.l @r15+, r6
    mov r12, r6
    add #0xE, r6
    mov.l r6, @-r15
    mov.l @(8, r12), r5
    mov.l   .L_fn_atan2_xy, r3
    jsr @r3
    mov.l @r12, r4
    mov r0, r4
    mov r12, r5
    mov.l   .L_fn_scene_render_alt, r3
    jsr @r3
    mov.l @r15+, r6
    mov r8, r6
    add #0xE, r6
    mov.l r6, @-r15
    mov.l @(8, r8), r5
    mov.l   .L_fn_atan2_xy, r3
    jsr @r3
    mov.l @r8, r4
    mov r0, r4
    mov r8, r5
    mov.l   .L_fn_scene_render_alt, r3
    jsr @r3
    mov.l @r15+, r6
    mov r10, r6
    add #0xE, r6
    mov.l r6, @-r15
    mov.l @(8, r10), r5
    mov.l   .L_fn_atan2_xy, r3
    jsr @r3
    mov.l @r10, r4
    mov r0, r4
    mov r10, r5
    mov.l   .L_fn_scene_render_alt, r3
    jsr @r3
    mov.l @r15+, r6
    mov r15, r5
    mov.l @(4, r12), r2
    mov.l @(4, r9), r3
    mov.l @(4, r8), r1
    add r3, r2
    add r1, r2
    mov.l @(4, r10), r3
    add r3, r2
    mov r2, r3
    shar r3
    shar r3
    mov.l r3, @r15
    mov.l r3, @(20, r14)
    mov.l   .L_xform_params_avg, r4
    mov.l   .L_fn_mat_vec_transform_2, r3
    jsr @r3
    add #0x10, r5
    mov.l @(16, r15), r2
    mov r15, r6
    add r13, r2
    add #0x4, r6
    mov.l r2, @(16, r15)
    mov.l @r15, r3
    mov.l @(20, r15), r2
    add r3, r2
    mov.l r2, @(20, r15)
    mov.l @(24, r15), r2
    add r11, r2
    mov.l r2, @(24, r15)
    mov.l r6, @-r15
    mov r15, r5
    add #0x14, r5
    mov.l r5, @-r15
    mov.l @(32, r15), r5
    mov.l   .L_fn_atan2_xy, r2
    jsr @r2
    mov.l @(24, r15), r4
    mov r0, r4
    mov.l @r15+, r5
    mov.l   .L_fn_scene_render_alt, r3
    jsr @r3
    mov.l @r15+, r6
    mov.l @r15, r2
    mov.l @(20, r15), r3
    cmp/eq r3, r2
    bt      .L_use_close_scale
    mov.l   .L_attract_cycle_counter, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_use_wide_scale
    mov.w   DAT_06006116, r0
    mov.w   .L_min_segment_threshold, r2
    mov.l @(r0, r14), r3
    cmp/ge r2, r3
    bf      .L_use_wide_scale
.L_use_close_scale:
    mov.l @(4, r9), r5
    mov.l @(4, r12), r2
    mov.l   .L_fp_half, r4
    mov.l   .L_fn_fpmul, r3
    jsr @r3
    add r2, r5
    mov.l   .L_close_angle_scale, r13
    bra     .L_compute_lateral_angles
    mov r0, r11

    .global DAT_06006116
DAT_06006116:
    .2byte  0x01EC                      /* car array offset for segment distance */
.L_min_segment_threshold:
    .2byte  0x00DC                      /* 220 — min segment distance for close scale */
    .2byte  0xFFFF                      /* alignment padding */
.L_geom_ch7_data_2:
    .4byte  sym_06063ED8                /* geometry channel 7 (dup for pool 2) */
.L_geom_ch6_data_2:
    .4byte  sym_06063EC4                /* geometry channel 6 (dup for pool 2) */
.L_fn_atan2_xy:
    .4byte  sym_06006838                /* atan2(x, z) — heading computation */
.L_fn_scene_render_alt:
    .4byte  scene_render_alt            /* store heading + trigger render update */
.L_xform_params_avg:
    .4byte  sym_060446AC                /* averaged position transform params */
.L_fn_mat_vec_transform_2:
    .4byte  mat_vec_transform           /* matrix-vector transform (dup) */
.L_attract_cycle_counter:
    .4byte  sym_0607EAD8                /* attract mode cycle counter (0/1/2) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_fn_fpmul:
    .4byte  fpmul                       /* 16.16 fixed-point multiply */
.L_close_angle_scale:
    .4byte  0x0002CCCC                  /* ~2.8 (16.16) — close angle scale */
.L_use_wide_scale:
    mov.l @(20, r15), r11
    mov.l   .L_wide_angle_scale, r13
.L_compute_lateral_angles:
    mov.l @(4, r10), r5
    mov.l @(4, r8), r3
    mov.l   .L_fp_half_2, r4
    add r3, r5
    mov.l   .L_fn_fpmul_2, r3
    jsr @r3
    nop
    mov.l r0, @(8, r15)
    mov.l @(4, r10), r5
    mov.l @(4, r9), r3
    mov.l   .L_fp_half_2, r4
    add r3, r5
    mov.l   .L_fn_fpmul_2, r3
    jsr @r3
    nop
    mov.l r0, @r15
    mov.l @(4, r8), r5
    mov.l @(4, r12), r3
    mov.l   .L_fp_half_2, r4
    add r3, r5
    mov.l   .L_fn_fpmul_2, r3
    jsr @r3
    nop
    mov r11, r4
    mov.l r0, @(12, r15)
    mov.l @(8, r15), r3
    sub r3, r4
    mov.l   .L_fn_atan2, r3
    jsr @r3
    mov r13, r5
    mov.l r0, @(28, r14)
    mov.l @r15, r4
    mov.l @(12, r15), r2
    mov.l   .L_pitch_divisor, r5
    mov.l   .L_fn_atan2, r3
    jsr @r3
    sub r2, r4
    mov.l r0, @(36, r14)
    mov.l   .L_position_counter, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    add #0x1C, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wide_angle_scale:
    .4byte  0x000D6666                  /* ~13.4 (16.16) — wide angle scale */
.L_fp_half_2:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_fn_fpmul_2:
    .4byte  fpmul                       /* 16.16 fixed-point multiply (dup) */
.L_fn_atan2:
    .4byte  atan2                       /* atan2(y, x) — angle computation */
.L_pitch_divisor:
    .4byte  0x00011998                  /* ~1.1 (16.16) — pitch angle divisor */
.L_position_counter:
    .4byte  sym_06089EDC                /* global position counter (decremented by 0x30) */
