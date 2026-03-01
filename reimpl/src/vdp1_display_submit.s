/* VERIFIED: sym_0602D814 (in this TU) writes car struct +0x0C during racing
 * Method: watchpoint on sym_06078900+0x0C during LEFT steering
 *   PC=0x0602D826 (sym_0602D814+0xE), PR=render_orchestrator+0xE4
 *   wrote 0x00043364 -> 0x00043483 (car state field, possibly speed or heading)
 *   Called from render_orchestrator pipeline.
 * Date: 2026-02-28
 */

    .section .text.FUN_0602D43C


    .global vdp1_display_submit
    .type vdp1_display_submit, @function
vdp1_display_submit:
    sts.l pr, @-r15
    mov r14, r0
    mov.w   DAT_0602d48a, r1
    mov #0x0, r12
    mov.l @(r0, r1), r10
    mov.w   .L_off_draw_count, r11
    mov.w   DAT_0602d48e, r2
    mov.w @(r0, r2), r7
    cmp/pl r7
    bt      .L_load_draw_count
    mov.w   .L_max_abs_range, r3
    mov.l   .L_max_draw_distance, r5
    neg r3, r4
    mov.l @(8, r0), r7
    mov.w   .L_frame_threshold, r8
    cmp/gt r7, r8
    bt      .L_load_draw_count
    mov.w   .L_off_obj_data, r2
    mov.l @(r0, r2), r9
    tst r9, r9
    bt      .L_load_draw_count
    mov.w   DAT_0602d496, r2
    mov.l @(r0, r2), r9
    cmp/gt r5, r9
    bt      .L_load_draw_count
    mov r10, r8
    cmp/gt r3, r10
    bt      .L_abs_distance_ready
    cmp/ge r4, r10
    bt      .L_load_draw_count
    neg r8, r8
.L_abs_distance_ready:
    sub r3, r8
    mov #0x4, r1
    mov #0xA, r2
    cmp/gt r1, r8
    bt      .L_check_max_draw
    mov r1, r8
    bra     .L_store_draw_count
    nop

    .global DAT_0602d48a
DAT_0602d48a:
    .2byte  0x0154
.L_off_draw_count:
    .2byte  0x0168

    .global DAT_0602d48e
DAT_0602d48e:
    .2byte  0x0166
.L_max_abs_range:
    .2byte  0x02F8
.L_frame_threshold:
    .2byte  0x00F0
.L_off_obj_data:
    .2byte  0x0040

    .global DAT_0602d496
DAT_0602d496:
    .2byte  0x010C
.L_max_draw_distance:
    .4byte  0x00006800                  /* far clip distance threshold */
.L_check_max_draw:
    cmp/gt r8, r2
    bt      .L_store_draw_count
    mov r2, r8
.L_store_draw_count:
    mov.w r8, @(r0, r11)
.L_load_draw_count:
    mov.w @(r0, r11), r3
    mov r3, r12
    cmp/pl r3
    bf      .L_compute_cos_scale
    mov.w   DAT_0602d542, r1
    mov.l @(r0, r1), r4
    tst r4, r4
    bf      .L_decrement_draw
    add #-0x2, r3
.L_decrement_draw:
    add #-0x1, r3
    mov.w r3, @(r0, r11)
    mov.l   .L_perspective_base, r4
    mov r4, r2
    mov #0x0, r5
    shll16 r3
    sub r3, r2
    mov r2, r3
    cmp/pz r2
    bf      .L_skip_perspective
    mov.w   DAT_0602d544, r1
    mov.l @(r0, r1), r5
    dmuls.l r3, r5
    sts mach, r3
    sts macl, r5
    xtrct r3, r5
    mov.w   .L_hw_div_base_a, r2
    mov r5, r3
    mov.l r4, @(0, r2)
    shlr16 r3
    exts.w r3, r3
    mov.l r3, @(16, r2)
    shll16 r5
    mov.l r5, @(20, r2)
    mov.l @(28, r2), r5
.L_skip_perspective:
    mov.w   DAT_0602d544, r1
    bsr     .L_vis_counter_decay
    mov.l r5, @(r0, r1)
.L_compute_cos_scale:
    mov.w   DAT_0602d548, r1
    mov.l @(r0, r1), r4
    mov.l   .L_fn_cos_lookup_a, r0
    jsr @r0
    nop
    shll16 r10
    dmuls.l r0, r10
    sts mach, r0
    sts macl, r10
    xtrct r0, r10
    shlr16 r10
    exts.w r10, r10
    neg r10, r10
    mov r14, r0
    mov.w   DAT_0602d54a, r1
    mov.w   DAT_0602d544, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.w   .L_off_scale_factor, r2
    mov.w @(r0, r2), r3
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    shll8 r3
    shlr16 r4
    shlr8 r4
    or r3, r4
    mov.l @(12, r0), r2
    mov.l   .L_min_distance_sq, r3
    cmp/ge r3, r2
    bt      .L_compute_sq_distance
    mov #0x0, r3
    mov.l   .L_fp_quarter, r6
    cmp/ge r3, r4
    bt      .L_angle_sign_ready
    neg r6, r6
.L_angle_sign_ready:
    bra     .L_drift_correction
    mov.l r3, @-r15

    .global DAT_0602d542
DAT_0602d542:
    .2byte  0x011C

    .global DAT_0602d544
DAT_0602d544:
    .2byte  0x010C
.L_hw_div_base_a:
    .2byte  0xFF00                      /* -> 0xFFFFFF00 (SH-2 hw divider) */

    .global DAT_0602d548
DAT_0602d548:
    .2byte  0x005C

    .global DAT_0602d54a
DAT_0602d54a:
    .2byte  0x0144
.L_off_scale_factor:
    .2byte  0x00CE
    .2byte  0x0000
.L_perspective_base:
    .4byte  0x000A0000                  /* 10.0 in 16.16 fixed-point */
.L_fn_cos_lookup_a:
    .4byte  cos_lookup
.L_min_distance_sq:
    .4byte  0x00000100                  /* 256 — min sq_dist for atan path */
.L_fp_quarter:
    .4byte  0x00004000                  /* 0.25 (16.16 fixed-point) */
.L_compute_sq_distance:
    mov r2, r3
    dmuls.l r2, r3
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    mov.l r3, @-r15
    mov.w   .L_hw_div_base_b, r2
    mov r4, r1
    mov.l r3, @(0, r2)
    shlr16 r1
    exts.w r1, r1
    mov.l r1, @(16, r2)
    shll16 r4
    mov.l r4, @(20, r2)
    mov.l   .L_fn_atan_piecewise_a, r0
    mov.l @(28, r2), r4
    jsr @r0
    nop
    cmp/eq #0x0, r0
    bf      .L_store_angle_result
    mov.w   DAT_0602d5f2, r4
    add r14, r4
    mov.b @r4, r0
.L_store_angle_result:
    mov r0, r6
.L_drift_correction:
    mov r14, r0
    mov.w   DAT_0602d5f4, r1
    mov #0x0, r8
    mov.w @(r0, r1), r2
    cmp/pl r2
    bf      .L_apply_steer_scale
    mov.l @(8, r0), r2
    mov #0x46, r4
    cmp/ge r4, r2
    bt      .L_apply_steer_scale
    mov.w   .L_off_obj_data_b, r1
    mov.l @(r0, r1), r2
    mov.w   .L_off_lateral_vel, r3
    mov.l @(r0, r3), r4
    xor r2, r4
    cmp/pz r4
    bt      .L_apply_steer_scale
    mov #0x1, r8
    shar r2
    mov #0x9, r5
    muls.w r2, r5
    shll16 r6
    sts macl, r4
    mov.l   .L_fn_cos_lookup_b, r0
    jsr @r0
    nop
    dmuls.l r0, r6
    sts mach, r2
    sts macl, r6
    xtrct r2, r6
    shlr16 r6
    exts.w r6, r6
    cmp/pz r6
    bt      .L_apply_steer_scale
    mov #0x0, r6
.L_apply_steer_scale:
    mov.w   .L_off_lateral_vel, r3
    mov r14, r0
    mov.l @(r0, r3), r5
    mov #0x3, r4
    muls.w r4, r6
    neg r5, r5
    sts macl, r6
    cmp/pz r5
    bf      .L_clamp_neg_lateral
    cmp/gt r5, r6
    bt      .L_use_lateral_limit
    bra     .L_compute_steer_accum
    nop
.L_hw_div_base_b:
    .2byte  0xFF00                      /* -> 0xFFFFFF00 (SH-2 hw divider) */

    .global DAT_0602d5f2
DAT_0602d5f2:
    .2byte  0x007F

    .global DAT_0602d5f4
DAT_0602d5f4:
    .2byte  0x0166
.L_off_obj_data_b:
    .2byte  0x0040
.L_off_lateral_vel:
    .2byte  0x005C
    .2byte  0x0000
.L_fn_atan_piecewise_a:
    .4byte  atan_piecewise
.L_fn_cos_lookup_b:
    .4byte  cos_lookup
.L_clamp_neg_lateral:
    neg r6, r6
    cmp/gt r6, r5
    bt      .L_use_lateral_limit
    bra     .L_compute_steer_accum
    mov #0x0, r7
.L_use_lateral_limit:
    mov r5, r6
.L_compute_steer_accum:
    neg r6, r11
    mov r14, r0
    mov.w   .L_off_steer_accum, r1
    mov.l @(r0, r1), r5
    sub r11, r10
    sub r5, r10
    add r10, r5
    mov.w   .L_steer_clamp_max, r3
    neg r3, r4
    cmp/gt r4, r5
    bt      .L_check_steer_max
    mov r4, r5
    bra     .L_steer_clamped
    nop
.L_off_steer_accum:
    .2byte  0x0178
.L_steer_clamp_max:
    .2byte  0x0300
.L_check_steer_max:
    cmp/gt r5, r3
    bt      .L_steer_clamped
    mov r3, r5
.L_steer_clamped:
    mov.l r5, @(r0, r1)
    mov.w   DAT_0602d67c, r2
    mov.l @(r0, r2), r3
    mov r3, r6
    add r3, r5
    sub r5, r6
    neg r6, r6
    shar r6
    shar r6
    shar r6
    sub r6, r5
    mov.l r5, @(r0, r2)
    mov.w   .L_off_orient_angle, r1
    mov.w   .L_off_forward_vel, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.w   DAT_0602d682, r2
    mov.w @(r0, r2), r3
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    shll8 r3
    shlr16 r4
    shlr8 r4
    or r3, r4
    mov.l @r15+, r3
    tst r3, r3
    bf      .L_compute_orient_atan
    mov.l   .L_fp_quarter_b, r6
    bra     .L_speed_range_clamp
    nop

    .global DAT_0602d67c
DAT_0602d67c:
    .2byte  0x005C
.L_off_orient_angle:
    .2byte  0x0140
.L_off_forward_vel:
    .2byte  0x0108

    .global DAT_0602d682
DAT_0602d682:
    .2byte  0x00CC
.L_fp_quarter_b:
    .4byte  0x00004000                  /* 0.25 (16.16 fixed-point) */
.L_compute_orient_atan:
    mov.w   .L_hw_div_base_c, r2
    mov r4, r1
    mov.l r3, @(0, r2)
    shlr16 r1
    exts.w r1, r1
    mov.l r1, @(16, r2)
    shll16 r4
    mov.l r4, @(20, r2)
    mov.l @(28, r2), r4
    mov.l   .L_fn_atan_piecewise_b, r0
    jsr @r0
    nop
    cmp/eq #0x0, r0
    bf      .L_orient_angle_ready
    mov.w   .L_off_fallback_angle_b, r4
    add r14, r4
    mov.b @r4, r0
.L_orient_angle_ready:
    mov r0, r6
.L_speed_range_clamp:
    mov r14, r0
    mov #0x32, r3
    mov.w   DAT_0602d6c2, r4
    mov.l @(8, r0), r7
    cmp/gt r3, r7
    bt      .L_check_speed_max
    mov r3, r7
    bra     .L_speed_clamped
    nop
.L_hw_div_base_c:
    .2byte  0xFF00                      /* -> 0xFFFFFF00 (SH-2 hw divider) */
.L_off_fallback_angle_b:
    .2byte  0x007E

    .global DAT_0602d6c2
DAT_0602d6c2:
    .2byte  0x00FA
.L_fn_atan_piecewise_b:
    .4byte  atan_piecewise
.L_check_speed_max:
    cmp/gt r7, r4
    bt      .L_speed_clamped
    mov r4, r7
.L_speed_clamped:
    sub r3, r4
    sub r3, r7
    mov.l   .L_fn_hw_divide, r12
    shll8 r7
    mov r4, r0
    jsr @r12
    mov r7, r1
    mov r14, r0
    mov #0x2, r3
    mov #0x3, r4
    muls.w r4, r1
    shll8 r3
    sts macl, r7
    add r3, r7
    mov.w   .L_off_obj_data_c, r1
    mov.w   DAT_0602d732, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    mov r4, r13
    mov r3, r5
    sub r4, r5
    mov.l r7, @-r15
    muls.w r6, r7
    sts macl, r6
    neg r4, r4
    mov r5, r7
    shlr8 r6
    xor r3, r7
    cmp/pz r7
    bt      .L_clamp_angular_vel
    mov.l   .L_half_circle_angle, r4
    cmp/pz r3
    bt      .L_wrap_angle_offset
    neg r4, r4
.L_wrap_angle_offset:
    sub r4, r3
    neg r3, r3
    dmuls.l r3, r6
    mov.l   .L_fn_hw_divide, r12
    mov r4, r0
    jsr @r12
    sts macl, r1
    mov r0, r6
    mov r14, r0
.L_clamp_angular_vel:
    cmp/pz r5
    bf      .L_clamp_neg_angular
    cmp/gt r5, r6
    bt      .L_use_angular_limit
    bra     .L_final_angular_scale
    nop
.L_off_obj_data_c:
    .2byte  0x0040

    .global DAT_0602d732
DAT_0602d732:
    .2byte  0x005C
.L_fn_hw_divide:
    .4byte  sym_0602ECCC
.L_half_circle_angle:
    .4byte  0x00000FE0                  /* ~180 degrees in angle units */
.L_clamp_neg_angular:
    neg r6, r6
    cmp/gt r6, r5
    bt      .L_use_angular_limit
    bra     .L_final_angular_scale
    nop
.L_use_angular_limit:
    mov r5, r6
.L_final_angular_scale:
    shll8 r6
    mov.l   .L_fn_hw_divide_b, r12
    mov.l @r15+, r0
    jsr @r12
    mov r6, r1
    mov r0, r6
    mov r14, r0
    sub r5, r6
    mov.w   DAT_0602d790, r1
    mov.l @(r0, r1), r3
    sub r6, r3
    neg r3, r3
    shar r3
    shar r3
    shar r3
    sub r3, r6
    mov.l r6, @(r0, r1)
    mov.l @(8, r0), r3
    mov.w   .L_min_frame_for_drift, r4
    cmp/ge r3, r4
    mov.w   .L_off_lateral_vel_b, r7
    bt      .L_final_vel_clamp
    mov.l @(r0, r7), r6
    mov.l   .L_neg_lateral_threshold, r5
    cmp/ge r6, r5
    bt      .L_set_near_flag
    neg r5, r5
    cmp/gt r6, r5
    bt      .L_final_vel_clamp
    mov.l @(0, r0), r2
    mov.l   .L_flag_cache_through, r3
    or r3, r2
    mov.l   .L_flag_priority_a, r3
    or r3, r2
    bra     .L_final_vel_clamp
    mov.l r2, @(0, r0)

    .global DAT_0602d790
DAT_0602d790:
    .2byte  0x0058
.L_min_frame_for_drift:
    .2byte  0x0041
.L_off_lateral_vel_b:
    .2byte  0x005C
    .2byte  0x0000
.L_fn_hw_divide_b:
    .4byte  sym_0602ECCC
.L_neg_lateral_threshold:
    .4byte  0xFFFFCD80                  /* -0x3280 lateral distance threshold */
.L_flag_cache_through:
    .4byte  0x20000000                  /* cache-through render flag */
.L_flag_priority_a:
    .4byte  0x40000000                  /* 0.25 (2.30) or 16384.0 (16.16) */
.L_set_near_flag:
    mov.l @(0, r0), r2
    mov.l   .L_flag_render_near, r3
    or r3, r2
    mov.l   .L_flag_priority_b, r3
    or r3, r2
    bra     .L_final_vel_clamp
    mov.l r2, @(0, r0)
    .2byte  0x0000
.L_flag_render_near:
    .4byte  0x10000000                  /* near-object render flag */
.L_flag_priority_b:
    .4byte  0x40000000                  /* 0.25 (2.30) or 16384.0 (16.16) */
.L_final_vel_clamp:
    mov.l @(r0, r7), r6
    mov.l   .L_vel_clamp_limit, r3
    cmp/ge r6, r3
    bt      .L_vel_exceeded_clamp
    neg r3, r3
    cmp/ge r6, r3
    bt      .L_return
.L_vel_exceeded_clamp:
    mov r3, r6
    mov #0x1, r4
    mov.w   .L_off_clamp_flag, r1
    mov.w r4, @(r0, r1)
.L_return:
    lds.l @r15+, pr
    rts
    mov.l r6, @(r0, r7)
.L_off_clamp_flag:
    .2byte  0x00D4
    .2byte  0x0000
.L_vel_clamp_limit:
    .4byte  0xFFFFCC00                  /* -0x3400 velocity clamp limit */
.L_vis_counter_decay:
    mov.l r3, @-r15
    mov.l @(8, r0), r3
    mov.w   .L_off_vis_counter, r1
    cmp/pl r3
    bf      .L_vis_decay_done
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov #0x3, r4
    mov.w @(r0, r1), r3
    cmp/gt r4, r3
    bt      .L_vis_write_counter
    mov.l   .L_vis_reset_value, r5
    tst r3, r3
    bt      .L_vis_nonzero_adjust
    add #-0x3, r5
.L_vis_nonzero_adjust:
    mov.w r5, @(r0, r1)
.L_vis_write_counter:
    mov.l @r15+, r5
    mov.l @r15+, r4
.L_vis_decay_done:
    rts
    mov.l @r15+, r3
.L_off_vis_counter:
    .2byte  0x0166
    .2byte  0x0000
.L_vis_reset_value:
    .4byte  0x0000000A                  /* 10 = visibility counter reset */

    .global sym_0602D814
sym_0602D814:
    mov r14, r0
    mov.l @(12, r0), r4
    mov.w   DAT_0602d862, r2
    mov.l @(r0, r2), r3
    add r3, r4
    mov.l r4, @(12, r0)
    cmp/pz r4
    bt      sym_0602D82A
    mov #0x0, r3
    mov.l r3, @(12, r0)
    mov.l r3, @(r0, r2)

    .global sym_0602D82A
sym_0602D82A:
    mov.w   DAT_0602d864, r2
    mov.l @(12, r0), r3
    mov.w @(r0, r2), r4
    mov.l   .L_decay_curve_table, r5
    shll2 r4
    add r5, r4
    mov.l @r4, r4
    mov.l   .L_decay_scale_factor, r5
    dmuls.l r3, r4
    nop
    nop
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    dmuls.l r4, r5
    mov.w   DAT_0602d866, r1
    mov #0x0, r3
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
    shlr16 r5
    mov r5, r6
    mov.l   .L_max_intensity, r4
    cmp/gt r3, r5
    bt      .L_check_max_intensity
    mov r3, r5
    bra     .L_intensity_clamped
    nop

    .global DAT_0602d862
DAT_0602d862:
    .2byte  0x00FC

    .global DAT_0602d864
DAT_0602d864:
    .2byte  0x00DC

    .global DAT_0602d866
DAT_0602d866:
    .2byte  0x00E0
.L_decay_curve_table:
    .4byte  sym_060477BC
.L_decay_scale_factor:
    .4byte  0x0221AC91                  /* global intensity scale constant */
.L_max_intensity:
    .4byte  0x00002134                  /* max display intensity value */
.L_check_max_intensity:
    cmp/gt r5, r4
    bt      .L_intensity_clamped
    mov r4, r5
.L_intensity_clamped:
    mov.l r5, @(r0, r1)
    sub r5, r6
    cmp/pz r6
    bt      .L_store_residual
    mov #0x0, r6
.L_store_residual:
    mov.w   DAT_0602d88c, r1
    mov.l r6, @(r0, r1)
    rts
    nop

    .global DAT_0602d88c
DAT_0602d88c:
    .2byte  0x00E8

    .global sym_0602D88E
sym_0602D88E:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
