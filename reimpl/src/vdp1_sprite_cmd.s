
    .section .text.FUN_0602D08A


    .global vdp1_sprite_cmd
    .type vdp1_sprite_cmd, @function
vdp1_sprite_cmd:
    sts.l pr, @-r15
    mov r14, r0
    mov.w   DAT_0602d0d4, r1
    mov.l @(r0, r1), r10
    mov.w   .L_off_draw_count, r11
    mov.w   DAT_0602d0d8, r2
    mov.w @(r0, r2), r7
    cmp/pl r7
    bt      .L_begin_perspective
    mov.w   .L_max_abs_range_x, r3
    .byte   0xD5, 0x10    /* mov.l .L_max_z_distance, r5 */
    mov.l @(8, r0), r7
    mov.w   DAT_0602d0dc, r8
    neg r3, r4
    neg r5, r6
    cmp/gt r7, r8
    bt      .L_begin_perspective
    mov.w   DAT_0602d0de, r2
    mov.l @(r0, r2), r9
    cmp/gt r5, r9
    bt      .L_begin_perspective
    cmp/gt r9, r6
    bt      .L_begin_perspective
    mov r10, r8
    cmp/gt r3, r10
    bt      .L_z_dist_positive
    cmp/ge r4, r10
    bt      .L_begin_perspective
    neg r8, r8
.L_z_dist_positive:
    sub r3, r8
    mov #0x4, r1
    mov #0xF, r2
    cmp/gt r1, r8
    bt      .L_check_draw_max
    mov r1, r8
    bra     .L_store_draw_count
    nop

    .global DAT_0602d0d4
DAT_0602d0d4:
    .2byte  0x0154
.L_off_draw_count:
    .2byte  0x0168

    .global DAT_0602d0d8
DAT_0602d0d8:
    .2byte  0x0166
.L_max_abs_range_x:
    .2byte  0x02E0

    .global DAT_0602d0dc
DAT_0602d0dc:
    .2byte  0x0104

    .global DAT_0602d0de
DAT_0602d0de:
    .2byte  0x005C
.L_max_z_distance:
    .4byte  0x00000300                  /* max Z distance for draw count */
.L_check_draw_max:
    cmp/gt r8, r2
    bt      .L_store_draw_count
    mov r2, r8
.L_store_draw_count:
    mov.w r8, @(r0, r11)
.L_begin_perspective:
    mov.w @(r0, r11), r3
    cmp/pl r3
    bf      .L_compute_persp_scale
    mov.w   DAT_0602d186, r1
    mov.l @(r0, r1), r4
    cmp/pz r4
    bt      .L_dec_draw_count
    add #-0x2, r3
.L_dec_draw_count:
    add #-0x1, r3
    mov.w r3, @(r0, r11)
    .byte   0xD4, 0x24    /* mov.l .L_mask_nibble4, r4 */
    mov r4, r2
    mov #0x0, r5
    shll16 r3
    sub r3, r2
    mov r2, r3
    cmp/pz r2
    bf      .L_skip_hw_div
    mov.w   DAT_0602d188, r1
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
.L_skip_hw_div:
    mov.w   DAT_0602d188, r1
    .byte   0xB3, 0x58    /* bsr 0x0602D7E4 (external) */
    mov.l r5, @(r0, r1)
.L_compute_persp_scale:
    mov.w   DAT_0602d18c, r1
    mov.l @(r0, r1), r4
    .byte   0xDD, 0x17    /* mov.l .L_fn_cos_lookup_a, r13 */
    jsr @r13
    shll16 r10
    dmuls.l r0, r10
    sts mach, r0
    sts macl, r10
    xtrct r0, r10
    shlr16 r10
    exts.w r10, r10
    neg r10, r10
    mov r14, r0
    mov.w   DAT_0602d18e, r1
    mov.w   DAT_0602d188, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.w   .L_off_steer_coeff, r2
    mov.w @(r0, r2), r3
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    shll8 r3
    shlr16 r4
    shlr8 r4
    or r3, r4
    mov.l @(12, r0), r2
    .byte   0xD3, 0x0A    /* mov.l .L_dist_sq_threshold, r3 */
    cmp/ge r3, r2
    bt      .L_large_dist_path
    mov #0x0, r3
    .byte   0xD6, 0x09    /* mov.l .L_fp_quarter, r6 */
    cmp/ge r3, r4
    bt      .L_offset_sign_ok
    neg r6, r6
.L_offset_sign_ok:
    bra     .L_begin_steer_correct
    mov.l r3, @-r15

    .global DAT_0602d186
DAT_0602d186:
    .2byte  0x011C

    .global DAT_0602d188
DAT_0602d188:
    .2byte  0x010C
.L_hw_div_base_a:
    .2byte  0xFF00

    .global DAT_0602d18c
DAT_0602d18c:
    .2byte  0x005C

    .global DAT_0602d18e
DAT_0602d18e:
    .2byte  0x0144
.L_off_steer_coeff:
    .2byte  0x00CE
    .2byte  0x0000
.L_mask_nibble4:
    .4byte  0x000F0000                  /* nibble 4 mask */
.L_fn_cos_lookup_a:
    .4byte  cos_lookup
.L_dist_sq_threshold:
    .4byte  0x00000100                  /* distance^2 threshold for large path */
.L_fp_quarter:
    .4byte  0x00004000                  /* 0.25 (16.16 fixed-point) */
.L_large_dist_path:
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
    .byte   0xDD, 0x1F    /* mov.l .L_fn_atan_a, r13 */
    mov.l @(28, r2), r4
    jsr @r13
    nop
    cmp/eq #0x0, r0
    bf      .L_atan_result_a
    mov.w   DAT_0602d236, r4
    add r14, r4
    mov.b @r4, r0
.L_atan_result_a:
    mov r0, r6
.L_begin_steer_correct:
    mov r14, r0
    mov.w   DAT_0602d238, r1
    mov #0x0, r8
    mov.w @(r0, r1), r2
    cmp/pl r2
    bf      .L_begin_lateral_clamp
    mov.l @(8, r0), r2
    mov #0x46, r4
    cmp/ge r4, r2
    bt      .L_begin_lateral_clamp
    mov.w   .L_off_target_lat_pos, r1
    mov.w   .L_off_lateral_vel, r3
    mov.l @(r0, r1), r2
    mov.l @(r0, r3), r4
    xor r2, r4
    cmp/pz r4
    bt      .L_begin_lateral_clamp
    mov #0x1, r8
    shar r2
    mov #0x9, r5
    muls.w r2, r5
    shll16 r6
    sts macl, r4
    .byte   0xD0, 0x10    /* mov.l .L_fn_cos_lookup_b, r0 */
    jsr @r0
    nop
    dmuls.l r0, r6
    sts mach, r2
    sts macl, r6
    xtrct r2, r6
    shlr16 r6
    exts.w r6, r6
    cmp/pz r6
    bt      .L_begin_lateral_clamp
    mov #0x0, r6
.L_begin_lateral_clamp:
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
    bra     .L_accum_lateral_offset
    nop
.L_hw_div_base_b:
    .2byte  0xFF00

    .global DAT_0602d236
DAT_0602d236:
    .2byte  0x007F

    .global DAT_0602d238
DAT_0602d238:
    .2byte  0x0166
.L_off_target_lat_pos:
    .2byte  0x0040
.L_off_lateral_vel:
    .2byte  0x005C
    .2byte  0x0000
.L_fn_atan_a:
    .4byte  atan_piecewise
.L_fn_cos_lookup_b:
    .4byte  cos_lookup
.L_clamp_neg_lateral:
    neg r6, r6
    cmp/gt r6, r5
    bt      .L_use_lateral_limit
    bra     .L_accum_lateral_offset
    mov #0x0, r7
.L_use_lateral_limit:
    mov r5, r6
.L_accum_lateral_offset:
    neg r6, r11
    mov r14, r0
    mov.w   .L_off_accum_lateral, r1
    mov.l @(r0, r1), r5
    sub r11, r10
    sub r5, r10
    add r10, r5
    .byte   0xD3, 0x04    /* mov.l .L_max_lateral_range, r3 */
    neg r3, r4
    cmp/gt r4, r5
    bt      .L_check_upper_lateral
    mov r4, r5
    bra     .L_store_lateral
    nop
.L_off_accum_lateral:
    .2byte  0x0178
    .2byte  0x0000
.L_max_lateral_range:
    .4byte  0x00000300                  /* max lateral accumulator range */
.L_check_upper_lateral:
    cmp/gt r5, r3
    bt      .L_store_lateral
    mov r3, r5
.L_store_lateral:
    mov.l r5, @(r0, r1)
    mov.w   DAT_0602d2c4, r2
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
    mov.w   .L_off_target_angle_b, r1
    mov.w   .L_off_angular_vel_b, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.w   DAT_0602d2ca, r2
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
    bf      .L_do_atan_b
    .byte   0xD6, 0x03    /* mov.l .L_fp_quarter_b, r6 */
    bra     .L_begin_angular_vel
    nop

    .global DAT_0602d2c4
DAT_0602d2c4:
    .2byte  0x005C
.L_off_target_angle_b:
    .2byte  0x0140
.L_off_angular_vel_b:
    .2byte  0x0108

    .global DAT_0602d2ca
DAT_0602d2ca:
    .2byte  0x00CC
.L_fp_quarter_b:
    .4byte  0x00004000                  /* 0.25 (16.16 fixed-point) */
.L_do_atan_b:
    mov.w   .L_hw_div_base_c, r2
    mov r4, r1
    mov.l r3, @(0, r2)
    shlr16 r1
    exts.w r1, r1
    mov.l r1, @(16, r2)
    shll16 r4
    mov.l r4, @(20, r2)
    .byte   0xD0, 0x0A    /* mov.l .L_fn_atan_b, r0 */
    mov.l @(28, r2), r4
    jsr @r0
    nop
    cmp/eq #0x0, r0
    bf      .L_atan_result_b
    mov.w   .L_off_fallback_angle, r4
    add r14, r4
    mov.b @r4, r0
.L_atan_result_b:
    mov r0, r6
.L_begin_angular_vel:
    mov r14, r0
    mov #0x32, r3
    mov.w   DAT_0602d30a, r4
    mov.l @(8, r0), r7
    cmp/gt r3, r7
    bt      .L_check_frame_upper
    mov r3, r7
    bra     .L_compute_angular_div
    nop
.L_hw_div_base_c:
    .2byte  0xFF00
.L_off_fallback_angle:
    .2byte  0x007E

    .global DAT_0602d30a
DAT_0602d30a:
    .2byte  0x00FA
.L_fn_atan_b:
    .4byte  atan_piecewise
.L_check_frame_upper:
    cmp/gt r7, r4
    bt      .L_compute_angular_div
    mov r4, r7
.L_compute_angular_div:
    sub r3, r4
    sub r3, r7
    .byte   0xDC, 0x1C    /* mov.l .L_fn_hw_divide_a, r12 */
    shll8 r7
    mov r4, r0
    jsr @r12
    mov r7, r1
    mov r14, r0
    mov #0x2, r3
    mov #0x4, r4
    muls.w r4, r1
    shll8 r3
    sts macl, r7
    add r3, r7
    mov.l r7, @-r15
    mov.w   .L_off_target_lat_b, r1
    mov.l @(r0, r1), r3
    mov.w   DAT_0602d38a, r2
    mov.l @(r0, r2), r4
    mov r3, r5
    sub r4, r5
    muls.w r6, r7
    sts macl, r6
    shar r6
    neg r4, r4
    shar r6
    mov r5, r7
    shar r6
    xor r3, r7
    shar r6
    shar r6
    shar r6
    shar r6
    shar r6
    cmp/pz r7
    bt      .L_clamp_angular_vel
    .byte   0xD4, 0x0C    /* mov.l .L_half_circle_angle, r4 */
    cmp/pz r3
    bt      .L_wrap_angle_offset
    neg r4, r4
.L_wrap_angle_offset:
    sub r4, r3
    neg r3, r3
    dmuls.l r3, r6
    .byte   0xDC, 0x07    /* mov.l .L_fn_hw_divide_a, r12 */
    mov r4, r0
    mov.l r1, @-r15
    jsr @r12
    sts macl, r1
    mov r0, r6
    mov.l @r15+, r1
    mov r14, r0
.L_clamp_angular_vel:
    cmp/pz r5
    bf      .L_clamp_neg_angular
    cmp/gt r5, r6
    bt      .L_use_angular_limit
    bra     .L_final_angular_scale
    nop
.L_off_target_lat_b:
    .2byte  0x0040

    .global DAT_0602d38a
DAT_0602d38a:
    .2byte  0x005C
.L_fn_hw_divide_a:
    .4byte  sym_0602ECCC                /* hw_divide_protected */
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
    .byte   0xDC, 0x12    /* mov.l .L_fn_hw_divide_b, r12 */
    mov.l @r15+, r0
    jsr @r12
    mov r6, r1
    mov r0, r6
    mov r14, r0
    sub r5, r6
    mov.w   DAT_0602d3e8, r1
    mov.l @(r0, r1), r3
    sub r6, r3
    neg r3, r3
    shar r3
    shar r3
    shar r3
    sub r3, r6
    mov.l r6, @(r0, r1)
    mov.l @(8, r0), r3
    mov #0x41, r4
    cmp/ge r3, r4
    bt      .L_final_vel_clamp
    mov.w   DAT_0602d3ea, r7
    mov.l @(r0, r7), r6
    .byte   0xD5, 0x08    /* mov.l .L_neg_lateral_threshold, r5 */
    cmp/ge r6, r5
    bt      .L_set_near_flag
    neg r5, r5
    cmp/gt r6, r5
    bt      .L_final_vel_clamp
    mov.l @(0, r0), r2
    .byte   0xD3, 0x05    /* mov.l .L_flag_cache_through, r3 */
    or r3, r2
    .byte   0xD3, 0x05    /* mov.l .L_flag_priority_a, r3 */
    or r3, r2
    bra     .L_final_vel_clamp
    mov.l r2, @(0, r0)

    .global DAT_0602d3e8
DAT_0602d3e8:
    .2byte  0x0058

    .global DAT_0602d3ea
DAT_0602d3ea:
    .2byte  0x005C
.L_fn_hw_divide_b:
    .4byte  sym_0602ECCC                /* hw_divide_protected */
.L_neg_lateral_threshold:
    .4byte  0xFFFFCD80                  /* -0x3280 lateral distance threshold */
.L_flag_cache_through:
    .4byte  0x20000000                  /* cache-through render flag */
.L_flag_priority_a:
    .4byte  0x40000000                  /* far render priority flag */
.L_set_near_flag:
    mov.l @(0, r0), r2
    .byte   0xD3, 0x03    /* mov.l .L_flag_render_near, r3 */
    or r3, r2
    .byte   0xD3, 0x03    /* mov.l .L_flag_priority_b, r3 */
    or r3, r2
    bra     .L_final_vel_clamp
    mov.l r2, @(0, r0)
    .2byte  0x0000
.L_flag_render_near:
    .4byte  0x10000000                  /* near-object render flag */
.L_flag_priority_b:
    .4byte  0x40000000                  /* near render priority flag */
.L_final_vel_clamp:
    mov.w   DAT_0602d432, r7
    mov.l @(r0, r7), r6
    .byte   0xD3, 0x07    /* mov.l .L_vel_clamp_limit, r3 */
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

    .global DAT_0602d432
DAT_0602d432:
    .2byte  0x005C
.L_off_clamp_flag:
    .2byte  0x00D4
    .2byte  0x0000
.L_vel_clamp_limit:
    .4byte  0xFFFFCC00                  /* -0x3400 velocity clamp limit */
