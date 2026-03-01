
    .section .text.FUN_0602CDF6


    .global vdp1_cmd_list_mgr
    .type vdp1_cmd_list_mgr, @function
vdp1_cmd_list_mgr:
    sts.l pr, @-r15
    mov.w   DAT_0602ce44, r7
    mov #0x0, r6
    mov.w   DAT_0602ce46, r1
    mov.w   DAT_0602ce48, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    mov.w   DAT_0602ce4a, r1
    mov.l @(r0, r1), r5
    add r3, r4
    cmp/gt r5, r4
    bt      .L_within_limit
    neg r7, r7
    mov #0x1, r6
.L_within_limit:
    mov.l @(r0, r2), r4
    add r7, r3
    add r3, r4
    mov r4, r8
    add r7, r5
    mov r5, r9
    sub r5, r4
    mov.l r7, @-r15
    mov.l r9, @-r15
    .byte   0xDD, 0x09    /* mov.l .L_sin_lookup_a, r13 */
    mov.l r8, @-r15
    jsr @r13
    mov.l r6, @-r15
    mov r0, r5
    jsr @r13
    mov r9, r4
    .byte   0xD7, 0x07    /* mov.l .L_angle_scale_factor, r7 */
    dmuls.l r7, r0
    tst r5, r5
    sts mach, r0
    sts macl, r4
    xtrct r0, r4
    bf      .L_sin_nonzero
    bra     .L_zero_delta
    mov.l @r15+, r5

    .global DAT_0602ce44
DAT_0602ce44:
    .2byte  0x4000

    .global DAT_0602ce46
DAT_0602ce46:
    .2byte  0x0040

    .global DAT_0602ce48
DAT_0602ce48:
    .2byte  0x0058

    .global DAT_0602ce4a
DAT_0602ce4a:
    .2byte  0x005C
.L_sin_lookup_a:
    .4byte  sin_lookup
.L_angle_scale_factor:
    .4byte  0x0002C000
.L_sin_nonzero:
    .byte   0xD0, 0x12    /* mov.l .L_fpdiv_setup_a, r0 */
    jsr @r0
    nop
    cmp/pz r0
    bt      .L_abs_div_result
    neg r0, r0
.L_abs_div_result:
    mov r0, r10
    jsr @r13
    mov r8, r4
    dmuls.l r10, r0
    mov r8, r4
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    mov r3, r11
    .byte   0xD0, 0x0C    /* mov.l .L_cos_lookup, r0 */
    jsr @r0
    nop
    dmuls.l r10, r0
    shlr r7
    sts mach, r0
    sts macl, r5
    xtrct r0, r5
    add r7, r5
    .byte   0xD0, 0x08    /* mov.l .L_atan2_func, r0 */
    jsr @r0
    mov r3, r4
    mov r0, r4
    mov r0, r7
    jsr @r13
    nop
    mov r0, r5
    mov r11, r4
    tst r5, r5
    bf      .L_heading_valid
    bra     .L_zero_delta
    mov.l @r15+, r5
    .2byte  0x0000
.L_fpdiv_setup_a:
    .4byte  fpdiv_setup
.L_cos_lookup:
    .4byte  cos_lookup
.L_atan2_func:
    .4byte  atan2
.L_heading_valid:
    .byte   0xD0, 0x08    /* mov.l .L_fpdiv_setup_b, r0 */
    jsr @r0
    nop
    cmp/pz r0
    bt      .L_magnitude_positive
    neg r0, r0
.L_magnitude_positive:
    mov.l @r15+, r9
    tst r9, r9
    bt      .L_direction_normal
    neg r0, r0
.L_direction_normal:
    mov r0, r5
    mov r14, r0
    mov.l @(12, r0), r4
    tst r5, r5
    bf      .L_compute_correction
    bra     .L_zero_delta
    nop
    .2byte  0x0000
.L_fpdiv_setup_b:
    .4byte  fpdiv_setup
.L_compute_correction:
    .byte   0xD0, 0x09    /* mov.l .L_fpdiv_setup_c, r0 */
    jsr @r0
    nop
    .byte   0xD5, 0x09    /* mov.l .L_rad_to_angle, r5 */
    mov #0x0, r2
    cmp/pz r0
    bt      .L_ratio_positive
    mov #0x1, r2
    neg r0, r0
.L_ratio_positive:
    dmuls.l r0, r5
    nop
    sts mach, r0
    sts macl, r5
    xtrct r0, r5
    tst r2, r2
    bt/s    .L_apply_correction
    shlr16 r5
    neg r5, r5
.L_apply_correction:
    bra     .L_update_heading
    nop
.L_fpdiv_setup_c:
    .4byte  fpdiv_setup
.L_rad_to_angle:
    .4byte  0x28BE60DB
.L_zero_delta:
    mov #0x0, r5
    mov r8, r7
.L_update_heading:
    mov r14, r0
    mov.l @(48, r0), r2
    add r5, r2
    exts.w r2, r2
    .byte   0xD3, 0x09    /* mov.l .L_angular_rate_offset, r3 */
    mov.l r2, @(48, r0)
    mov.l r5, @(r0, r3)
    mov.l @r15+, r8
    mov.l @r15+, r9
    cmp/eq r8, r9
    bf/s    .L_angles_differ
    mov.l @r15+, r6
    mov r8, r7
.L_angles_differ:
    sub r6, r7
    mov.w   .L_heading_mode_offset, r1
    mov.w @(r0, r1), r2
    mov #0x1, r4
    cmp/eq r4, r2
    bt      .L_mode_1_heading
    .byte   0xD3, 0x03    /* mov.l .L_heading_target_offset, r3 */
    bra     .L_store_heading_target
    mov.l r7, @(r0, r3)
.L_heading_mode_offset:
    .2byte  0x0252
    .2byte  0x0000
.L_angular_rate_offset:
    .4byte  0x00000154
.L_heading_target_offset:
    .4byte  0x0000002C
.L_mode_1_heading:
    .byte   0xD3, 0x28    /* mov.l .L_heading_alt_offset, r3 */
    mov.l @(r0, r3), r7
.L_store_heading_target:
    mov.l @(48, r0), r2
    add r7, r2
    exts.w r2, r2
    mov.l @(40, r0), r4
    mov.l r2, @(40, r0)
    sub r4, r2
    mov r2, r4
    mov.l @(12, r0), r2
    .byte   0xD0, 0x24    /* mov.l .L_sin_lookup_b, r0 */
    jsr @r0
    nop
    dmuls.l r2, r0
    .byte   0xD3, 0x23    /* mov.l .L_lateral_scale_a, r3 */
    sts mach, r0
    sts macl, r5
    xtrct r0, r5
    dmuls.l r3, r5
    .byte   0xD3, 0x22    /* mov.l .L_lateral_scale_b, r3 */
    sts mach, r2
    sts macl, r5
    xtrct r2, r5
    dmuls.l r3, r5
    mov r14, r0
    sts mach, r3
    sts macl, r5
    xtrct r3, r5
    mov r5, r6
    mov.w   DAT_0602cfda, r1
    mov.w   DAT_0602cfdc, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    sub r3, r5
    sub r4, r6
    shar r5
    shar r6
    shar r5
    shar r6
    add r3, r5
    add r4, r6
    mov.l r5, @(r0, r1)
    mov.l r6, @(r0, r2)
    mov.l @(48, r0), r3
    mov.l @(40, r0), r4
    sub r4, r3
    exts.w r3, r3
    shar r3
    shar r3
    add r4, r3
    mov.w   DAT_0602cfde, r1
    .byte   0xD2, 0x13    /* mov.l .L_camera_heading_ptr, r2 */
    add #0x4, r2
    mov.l @(r0, r1), r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    add r4, r3
    mov.l @r2, r6
    mov r6, r4
    mov r6, r7
    mov.w   DAT_0602cfe0, r8
    cmp/pz r7
    bt      .L_smooth_positive
    neg r7, r7
.L_smooth_positive:
    cmp/gt r7, r8
    bt      .L_apply_smoothed
    xor r3, r4
    cmp/pz r4
    bt      .L_apply_smoothed
    cmp/pz r6
    bt      .L_negative_sign_ext
    extu.w r6, r6
    bra     .L_apply_smoothed
    nop

    .global DAT_0602cfda
DAT_0602cfda:
    .2byte  0x0060

    .global DAT_0602cfdc
DAT_0602cfdc:
    .2byte  0x0064

    .global DAT_0602cfde
DAT_0602cfde:
    .2byte  0x00D0

    .global DAT_0602cfe0
DAT_0602cfe0:
    .2byte  0x4000
    .2byte  0x0000
.L_heading_alt_offset:
    .4byte  0x0000002C
.L_sin_lookup_b:
    .4byte  sin_lookup
.L_lateral_scale_a:
    .4byte  0x0028D0FA
.L_lateral_scale_b:
    .4byte  0x03200000
.L_camera_heading_ptr:
    .4byte  sym_06063EEC
.L_negative_sign_ext:
    .byte   0xD4, 0x0B    /* mov.l .L_fp_neg_one, r4 */
    or r4, r6
.L_apply_smoothed:
    add r6, r3
    shar r3
    mov.l r3, @r2
    mov.w   DAT_0602d020, r2
    mov.l @(48, r0), r4
    mov.l @(r0, r2), r5
    sub r5, r4
    mov.w   .L_oor_counter_offset, r6
    mov.w   .L_divergence_threshold, r8
    cmp/gt r8, r4
    bt      .L_heading_out_of_range
    neg r8, r8
    cmp/ge r4, r8
    bt      .L_heading_out_of_range
    mov.l @(r0, r6), r3
    add #0x1, r3
    bra     .L_check_counter_limit
    mov.l r3, @(r0, r6)

    .global DAT_0602d020
DAT_0602d020:
    .2byte  0x025C
.L_oor_counter_offset:
    .2byte  0x0258
.L_divergence_threshold:
    .2byte  0x0444
    .2byte  0x0000
.L_fp_neg_one:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_heading_out_of_range:
    mov.w   DAT_0602d04e, r7
    cmp/pz r5
    bt      .L_ref_positive
    neg r7, r7
.L_ref_positive:
    add r7, r5
    mov.l @(48, r0), r4
    sub r5, r4
    mov.w   DAT_0602d050, r8
    cmp/gt r8, r4
    bt      .L_reset_counter
    neg r8, r8
    cmp/ge r4, r8
    bt      .L_reset_counter
    mov.l @(r0, r6), r3
    add #0x1, r3
    bra     .L_check_counter_limit
    mov.l r3, @(r0, r6)

    .global DAT_0602d04e
DAT_0602d04e:
    .2byte  0x8000

    .global DAT_0602d050
DAT_0602d050:
    .2byte  0x0444
.L_reset_counter:
    mov #0x0, r3
    bra     .L_done
    mov.l r3, @(r0, r6)
.L_check_counter_limit:
    mov.w   DAT_0602d074, r4
    cmp/gt r3, r4
    bt      .L_done
    mov.w   DAT_0602d076, r6
    mov.l @(r0, r6), r3
    sub r3, r5
    mov.w   DAT_0602d078, r6
    mov.l @(48, r0), r4
    neg r6, r7
    cmp/gt r7, r5
    bt      .L_check_upper_clamp
    mov r7, r5
    bra     .L_apply_heading_clamp
    nop

    .global DAT_0602d074
DAT_0602d074:
    .2byte  0x0002

    .global DAT_0602d076
DAT_0602d076:
    .2byte  0x0028

    .global DAT_0602d078
DAT_0602d078:
    .2byte  0x003C
.L_check_upper_clamp:
    cmp/ge r5, r6
    bt      .L_apply_heading_clamp
    mov r6, r5
.L_apply_heading_clamp:
    add r5, r4
    mov.l r4, @(48, r0)
.L_done:
    lds.l @r15+, pr
    rts
    nop
