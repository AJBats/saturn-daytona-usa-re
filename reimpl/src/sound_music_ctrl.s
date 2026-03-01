
    .section .text.FUN_06030548


    .global sound_music_ctrl
    .type sound_music_ctrl, @function
sound_music_ctrl:
    sts.l pr, @-r15
    mov.l @r14, r14
    mov.w   DAT_0603056a, r1
    add r14, r1
    mov.l @r1, r3
    mov.l @(4, r1), r4
    mov.l @(8, r1), r5
    mov.l @(12, r1), r6
    mov r3, r2
    or r4, r2
    or r5, r2
    or r6, r2
    mov.w   .L_chan_flag_bit, r7
    tst r7, r2
    bf      .L_any_channel_active
    bra     .L_return
    nop

    .global DAT_0603056a
DAT_0603056a:
    .2byte  0x0120
.L_chan_flag_bit:
    .2byte  0x0080
    .2byte  0x0000
    .4byte  sym_06030FBE
    .4byte  sym_0607E940
.L_any_channel_active:
    and r3, r4
    and r5, r6
    and r4, r6
    mov.w   .L_one, r2
    tst r2, r6
    bt      .L_not_all_playing
    bra     .L_return
    nop
.L_one:
    .2byte  0x0001                      /* 1 */
.L_not_all_playing:
    mov.w   .L_mono_flag_bit, r2
    tst r2, r6
    bt      .L_check_reset_flag
    mov.l   .L_speaker_front_right_a, r7
    mov #0x0, r4
    bra     .L_mono_channel_path
    mov.l @(16, r7), r6
.L_mono_flag_bit:
    .2byte  0x0080
    .2byte  0x0000
.L_speaker_front_right_a:
    .4byte  sym_06063EC4
.L_check_reset_flag:
    mov.w   DAT_060305ae, r2
    tst r2, r6
    bt      .L_build_channel_mask
    mov.w   DAT_060305b0, r0
    mov #0xF, r2
    bra     .L_return
    mov.w r2, @(r0, r14)

    .global DAT_060305ae
DAT_060305ae:
    .2byte  0x0004

    .global DAT_060305b0
DAT_060305b0:
    .2byte  0x016C
.L_build_channel_mask:
    mov #0x0, r12
    mov.w   DAT_06030602, r5
    mov.l @r1, r4
    tst r5, r4
    bt      .L_test_ch1
    add #0x1, r12
.L_test_ch1:
    mov.l @(4, r1), r4
    tst r5, r4
    bt      .L_test_ch2
    add #0x2, r12
.L_test_ch2:
    mov.l @(8, r1), r4
    tst r5, r4
    bt      .L_test_ch3
    add #0x4, r12
.L_test_ch3:
    mov.l @(12, r1), r4
    tst r5, r4
    bt      .L_dispatch_by_mask
    add #0x8, r12
.L_dispatch_by_mask:
    mov.w   DAT_06030604, r7
    mov #0x8, r4
    add r14, r7
    mov.l r4, @r7
    mov #0x3, r7
    cmp/eq r7, r12
    bt      .L_both_front
    mov #0xC, r7
    cmp/eq r7, r12
    bt      .L_both_rear
    mov #0x5, r7
    mov r7, r5
    and r12, r7
    cmp/eq r5, r7
    bt      .L_single_rear
    tst r7, r7
    bt      .L_single_front
    mov #0xA, r5
    tst r12, r5
    bt      .L_single_rear
    bra     .L_single_front
    nop

    .global DAT_06030602
DAT_06030602:
    .2byte  0x0080

    .global DAT_06030604
DAT_06030604:
    .2byte  0x0208
.L_both_rear:
    mov.l   .L_speaker_front_right_b, r7
    mov.w   DAT_0603063a, r4
    mov.l @(16, r7), r5
    mov.l @(48, r14), r2
    add r4, r5
    sub r5, r2
    cmp/pz r2
    mov.l @(16, r7), r5
    bt      .L_rear_abs_done
    neg r2, r2
.L_rear_abs_done:
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_rear_proximity_ok
    mov r4, r3
    shll r4
    add r4, r3
    cmp/gt r3, r2
    bt      .L_rear_proximity_ok
    add r4, r5
.L_rear_proximity_ok:
    mov.w   DAT_0603063a, r4
    mov.l   .L_music_target_pos_a, r3
    add r4, r5
    mov.w r5, @r3
    mov #0x2, r4
    bra     .L_multi_tracking_entry
    mov.l @(16, r7), r5

    .global DAT_0603063a
DAT_0603063a:
    .2byte  0x4000
.L_speaker_front_right_b:
    .4byte  sym_06063EC4
.L_music_target_pos_a:
    .4byte  sym_06030FBC
.L_both_front:
    mov #0x1, r5
    mov.l @(48, r14), r2
    shll16 r5
    shlr r5
    mov.l   .L_speaker_rear_left, r7
    add r5, r2
    mov.w   DAT_06030680, r4
    mov.l @(16, r7), r5
    add r4, r5
    sub r5, r2
    cmp/pz r2
    mov.l @(16, r7), r5
    bt      .L_front_abs_done
    neg r2, r2
.L_front_abs_done:
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_front_proximity_ok
    mov r4, r3
    shll r4
    add r4, r3
    cmp/gt r3, r2
    bt      .L_front_proximity_ok
    add r4, r5
.L_front_proximity_ok:
    mov.w   DAT_06030680, r4
    add r4, r5
    mov.l   .L_music_target_pos_b, r3
    mov #0x0, r4
    mov.w r5, @r3
    bra     .L_multi_tracking_entry
    mov.l @(16, r7), r5

    .global DAT_06030680
DAT_06030680:
    .2byte  0x4000
    .2byte  0x0000
.L_speaker_rear_left:
    .4byte  sym_06063E9C
.L_music_target_pos_b:
    .4byte  sym_06030FBC
.L_single_front:
    mov #0x2, r4
    tst r4, r12
    mov.l   .L_speaker_front_left, r7
    mov #0x1, r13
    bf      .L_front_speaker_chosen
    mov.l   .L_speaker_rear_right, r7
    mov #0x3, r13
.L_front_speaker_chosen:
    mov.w   DAT_060306c8, r4
    mov.l @(16, r7), r5
    mov.l @(48, r14), r2
    sub r5, r2
    cmp/pz r2
    bt      .L_front_single_abs_done
    neg r2, r2
.L_front_single_abs_done:
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_front_single_prox_ok
    mov r4, r3
    shll r4
    add r4, r3
    cmp/gt r3, r2
    bt      .L_front_single_prox_ok
    add r4, r5
.L_front_single_prox_ok:
    mov.w   DAT_060306c8, r4
    add r4, r5
    mov.l   .L_music_target_pos_c, r3
    mov.w r5, @r3
    mov.l @(16, r7), r5
    bra     .L_multi_tracking_entry
    mov r13, r4

    .global DAT_060306c8
DAT_060306c8:
    .2byte  0x4000
    .2byte  0x0000
.L_speaker_front_left:
    .4byte  sym_06063EB0
.L_speaker_rear_right:
    .4byte  sym_06063ED8
.L_music_target_pos_c:
    .4byte  sym_06030FBC
.L_single_rear:
    mov #0x1, r4
    mov.l   .L_speaker_rear_left_b, r7
    mov #0x0, r13
    tst r4, r12
    bf      .L_rear_speaker_chosen
    mov.l   .L_speaker_front_right_c, r7
    mov #0x2, r13
.L_rear_speaker_chosen:
    mov.w   DAT_06030714, r4
    mov.l @(16, r7), r5
    mov.l @(48, r14), r2
    sub r5, r2
    cmp/pz r2
    bt      .L_rear_single_abs_done
    neg r2, r2
.L_rear_single_abs_done:
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_rear_single_prox_ok
    mov r4, r3
    shll r4
    add r4, r3
    cmp/gt r3, r2
    bt      .L_rear_single_prox_ok
    add r4, r5
.L_rear_single_prox_ok:
    mov.w   DAT_06030716, r4
    add r4, r5
    mov.l   .L_music_target_pos_d, r3
    mov.w r5, @r3
    mov.l @(16, r7), r5
    bra     .L_multi_tracking_entry
    mov r13, r4

    .global DAT_06030714
DAT_06030714:
    .2byte  0x4000

    .global DAT_06030716
DAT_06030716:
    .2byte  0xC000
.L_speaker_rear_left_b:
    .4byte  sym_06063E9C
.L_speaker_front_right_c:
    .4byte  sym_06063EC4
.L_music_target_pos_d:
    .4byte  sym_06030FBC
.L_return:
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    rts
    mov.l @r15+, r12
.L_check_position_changed:
    mov.w   DAT_06030742, r1
    add r14, r1
    mov.l @r1, r2
    cmp/eq r2, r5
    bf      .L_position_changed
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    rts
    mov.l @r15+, r12

    .global DAT_06030742
DAT_06030742:
    .2byte  0x0080
.L_position_changed:
    mov.l r5, @r1
    mov.l r5, @-r15
    mov.l   .L_chan_dispatch_table, r2
    shll2 r4
    add r4, r2
    mov.l @r2, r1
    jmp @r1
    mov #0x0, r12
.L_chan_dispatch_table:
    .4byte  sym_06030F1C

    .global loc_06030758
loc_06030758:
    mov.l   .L_channel_priority_0, r0
    mov #0x8, r5
    mov.b r5, @r0
    mov.l   .L_channel_active_0, r0
    mov #0x1, r5
    mov.b r5, @r0
    mov.w   .L_ch0_bit_pattern, r5
    mov.w   .L_ch_mix_flags_offset_0, r0
    mov.l @(8, r14), r6
    mov #0x64, r2
    cmp/ge r6, r2
    mov.l @(r0, r14), r2
    bt      .L_ch0_skip_mix
    or r5, r2
.L_ch0_skip_mix:
    mov.l r2, @(r0, r14)
    bra     .L_compute_tracking
    mov.l @(16, r7), r6
.L_ch0_bit_pattern:
    .2byte  0x0011
.L_ch_mix_flags_offset_0:
    .2byte  0x0214
    .2byte  0x0000
.L_channel_priority_0:
    .4byte  sym_0607866D
.L_channel_active_0:
    .4byte  sym_06089595

    .global loc_06030788
loc_06030788:
    mov.l   .L_channel_priority_1, r0
    mov #0x4, r5
    mov.b r5, @r0
    mov.l   .L_channel_active_1, r0
    mov #0x1, r5
    mov.b r5, @r0
    mov.w   .L_ch1_bit_pattern, r5
    mov.w   .L_ch_mix_flags_offset_1, r0
    mov.l @(8, r14), r6
    mov #0x64, r2
    cmp/ge r6, r2
    mov.l @(r0, r14), r2
    bt      .L_ch1_skip_mix
    or r5, r2
.L_ch1_skip_mix:
    mov.l r2, @(r0, r14)
    bra     .L_compute_tracking
    mov.l @(16, r7), r6
.L_ch1_bit_pattern:
    .2byte  0x0022
.L_ch_mix_flags_offset_1:
    .2byte  0x0214
    .2byte  0x0000
.L_channel_priority_1:
    .4byte  sym_0607866D
.L_channel_active_1:
    .4byte  sym_06089595

    .global loc_060307B8
loc_060307B8:
    mov.l   .L_channel_priority_2, r0
    mov #0x2, r5
    mov.b r5, @r0
    mov.l   .L_channel_active_2, r0
    mov #0x1, r5
    mov.b r5, @r0
    mov.w   .L_ch2_bit_pattern, r5
    mov.w   .L_ch_mix_flags_offset_2, r0
    mov.l @(8, r14), r6
    mov #0x64, r2
    cmp/ge r6, r2
    mov.l @(r0, r14), r4
    bt      .L_ch2_skip_mix
    or r5, r4
.L_ch2_skip_mix:
    mov.l r4, @(r0, r14)
    bra     .L_compute_tracking
    mov.l @(16, r7), r6
.L_ch2_bit_pattern:
    .2byte  0x0044
.L_ch_mix_flags_offset_2:
    .2byte  0x0214
    .2byte  0x0000
.L_channel_priority_2:
    .4byte  sym_0607866D
.L_channel_active_2:
    .4byte  sym_06089595

    .global loc_060307E8
loc_060307E8:
    mov.l   .L_channel_priority_3, r0
    mov #0x1, r5
    mov.b r5, @r0
    mov.l   .L_channel_active_3, r0
    mov #0x1, r5
    mov.b r5, @r0
    mov.w   .L_ch3_bit_pattern, r5
    mov.w   .L_ch_mix_flags_offset_3, r0
    mov.l @(8, r14), r6
    mov #0x64, r2
    cmp/ge r6, r2
    mov.l @(r0, r14), r4
    bt      .L_ch3_skip_mix
    or r5, r4
.L_ch3_skip_mix:
    mov.l r4, @(r0, r14)
    mov.l @(16, r7), r6
.L_compute_tracking:
    mov.l @(40, r14), r5
    mov.w @(14, r7), r0
    mov r0, r3
    mov r5, r4
    mov.l r3, @-r15
    sub r6, r4
    mov #0x1, r1
    shll16 r1
    exts.w r4, r4
    shlr r1
    cmp/pz r4
    bt      .L_heading_wrap_done
    add r1, r4
.L_heading_wrap_done:
    shlr r1
    cmp/ge r4, r1
    bt      .L_heading_normalized
    shll r1
    sub r1, r4
.L_heading_normalized:
    mov r4, r1
    shar r1
    mov.w   .L_blend_result_offset, r0
    shar r1
    add r1, r4
    mov.l r4, @(r0, r14)
    sub r4, r5
    add #-0x4, r0
    mov r5, r7
    mov.l r5, @(r0, r14)
    mov.w   .L_frame_count_val, r4
    add #0x8, r0
    mov.w r4, @(r0, r14)
    mov.w   .L_steer_state_offset, r0
    mov #0x0, r13
    mov.l @(r0, r14), r5
    tst r5, r5
    bf      .L_begin_angle_math
    mov.w   .L_channel_mode_offset, r0
    mov.l @(r0, r14), r0
    and #0xF, r0
    shll r0
    mov.l   .L_fade_threshold_lo, r1
    mov.w @(r0, r1), r4
    mov.l   .L_fade_threshold_hi, r1
    mov.w @(r0, r1), r5
    mov.l @(8, r14), r0
    cmp/ge r4, r0
    bf      .L_below_lo_threshold
    mov.l   .L_music_ctrl_flag_a, r0
    mov.w @r0, r0
    tst r0, r0
    bf      .L_set_direction_bit
    mov.l   .L_force_steer_impact_a, r0
    jsr @r0
    mov.l r7, @-r15
    bra     .L_begin_angle_math
    mov.l @r15+, r7
.L_ch3_bit_pattern:
    .2byte  0x0088
.L_ch_mix_flags_offset_3:
    .2byte  0x0214
.L_blend_result_offset:
    .2byte  0x024C
.L_frame_count_val:
    .2byte  0x000A
.L_steer_state_offset:
    .2byte  0x00BC
.L_channel_mode_offset:
    .2byte  0x01D4
.L_channel_priority_3:
    .4byte  sym_0607866D
.L_channel_active_3:
    .4byte  sym_06089595
.L_fade_threshold_lo:
    .4byte  sym_06030F74
.L_fade_threshold_hi:
    .4byte  sym_06030F98
.L_music_ctrl_flag_a:
    .4byte  sym_06030FBE
.L_force_steer_impact_a:
    .4byte  force_steer_impact
.L_below_lo_threshold:
    cmp/ge r0, r5
    bt      .L_begin_angle_math
    mov.l   .L_music_ctrl_flag_b, r0
    mov.w @r0, r0
    tst r0, r0
    bf      .L_set_direction_bit
    mov.l   .L_force_steer_calc_a, r0
    jsr @r0
    mov.l r7, @-r15
    bra     .L_begin_angle_math
    mov.l @r15+, r7
    .2byte  0x0000
.L_music_ctrl_flag_b:
    .4byte  sym_06030FBE
.L_force_steer_calc_a:
    .4byte  force_steer_calc
.L_set_direction_bit:
    mov.l @(0, r14), r0
    mov.l   .L_direction_flag, r4
    or r4, r0
    mov.l r0, @(0, r14)
.L_begin_angle_math:
    mov.l @r15+, r3
    mov.l @r15+, r4
    mov #0x1, r13
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r4, @-r15
    mov.l   .L_speaker_config_a, r1
    mov #0x34, r2
    muls.w r2, r3
    mov.l r13, @-r15
    sts macl, r2
    add r2, r1
    mov #0x1, r13
    mov.l @(16, r1), r8
    shll16 r13
    mov.l @(20, r1), r10
    mov.l @(16, r14), r5
    shll8 r13
    dmuls.l r8, r5
    mov.l @(24, r14), r6
    mov.l @(0, r1), r0
    sts mach, r4
    sts macl, r5
    tst r0, r13
    xtrct r4, r5
    shlr8 r0
    mov #0x0, r9
    and #0x1, r0
    bf/s    .L_angle_dir_set
    add r10, r5
    add r6, r5
    mov #0x1, r9
.L_angle_dir_set:
    mov #0x0, r6
    cmp/pl r5
    bt      .L_sign_positive
    mov #0x1, r6
.L_sign_positive:
    mov #0x0, r4
    cmp/eq r0, r6
    bt      .L_quadrant_match
    mov #0x1, r4
.L_quadrant_match:
    mov.l r4, @-r15
    mov r8, r0
    cmp/eq #0x0, r0
    bf/s    .L_cos_nonzero
    mov r9, r0
    bra     .L_cos_zero_path
    nop
.L_direction_flag:
    .4byte  0x08000000
.L_speaker_config_a:
    .4byte  sym_060A6000
.L_cos_nonzero:
    cmp/eq #0x0, r0
    bf      .L_both_nonzero
    bra     .L_sin_zero_path
    nop
.L_cos_zero_path:
    mov.l @(24, r14), r5
    add r10, r5
    cmp/pl r5
    bt      .L_cos_zero_abs_done
    neg r5, r5
.L_cos_zero_abs_done:
    bra     .L_finalize_blend
    nop
.L_sin_zero_path:
    neg r10, r4
    mov.l   .L_fpdiv_setup_a, r0
    jsr @r0
    mov r8, r5
    mov.l @(16, r14), r5
    sub r0, r5
    cmp/pl r5
    bt      .L_sin_zero_abs_done
    neg r5, r5
.L_sin_zero_abs_done:
    bra     .L_finalize_blend
    nop
.L_fpdiv_setup_a:
    .4byte  fpdiv_setup
.L_both_nonzero:
    mov.l @(24, r14), r2
    add r10, r2
    neg r8, r3
    dmuls.l r2, r3
    mov #0x1, r5
    shll16 r5
    mov.w   .L_max_signed_16, r4
    sts mach, r2
    sts macl, r3
    cmp/gt r2, r4
    bf      .L_large_angle_path
    neg r4, r4
    cmp/gt r4, r2
    bt      .L_small_angle_path
.L_large_angle_path:
    shll8 r2
    shlr16 r3
    shlr8 r3
    or r2, r3
    mov.l @(16, r14), r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    add r3, r4
    neg r8, r2
    dmuls.l r2, r2
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    mov.l   .L_fpdiv_setup_b, r0
    jsr @r0
    add r2, r5
    shll8 r0
    bra     .L_blend_crossfade
    nop
.L_max_signed_16:
    .2byte  0x7FFF
.L_fpdiv_setup_b:
    .4byte  fpdiv_setup
.L_small_angle_path:
    xtrct r2, r3
    mov.l @(16, r14), r4
    add r3, r4
    neg r8, r2
    dmuls.l r2, r2
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    mov.l   .L_fpdiv_setup_c, r0
    jsr @r0
    add r2, r5
.L_blend_crossfade:
    mov r0, r2
    neg r8, r3
    dmuls.l r3, r2
    neg r10, r5
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    add r2, r5
    mov.l @(16, r14), r2
    mov.l @(24, r14), r3
    sub r2, r0
    sub r3, r5
    cmp/pl r0
    bt      .L_x_abs_done
    neg r0, r0
.L_x_abs_done:
    cmp/pl r5
    bt      .L_y_abs_done
    neg r5, r5
.L_y_abs_done:
    cmp/gt r0, r5
    bt      .L_y_dominates
    shar r5
    shar r5
    bra     .L_blend_done
    add r0, r5
    .2byte  0x0000
.L_fpdiv_setup_c:
    .4byte  fpdiv_setup
.L_y_dominates:
    shar r0
    shar r0
    add r0, r5
.L_blend_done:
    bra     .L_finalize_blend
    nop

    .global sym_06030A06
sym_06030A06:
    mov.l   .L_car_data_ptr, r1
    mov.l @r1, r3
    mov.w   .L_timeout_offset, r0
    mov.w @(r0, r3), r4
    tst r4, r4
    bt      .L_timeout_return
    add #-0x1, r4
    tst r4, r4
    bf/s    .L_timeout_return
    mov.w r4, @(r0, r3)
    mov.l   .L_fp_neg_one, r5
    mov.w   DAT_06030a40, r6
    mov.w   .L_channel_state_offset, r0
    add r3, r6
    mov.l r5, @r6
    mov.l @(r0, r3), r4
    mov.l   .L_wram_low, r5
    tst r5, r4
    bt      .L_timeout_return
    mov.w   DAT_06030a44, r0
    mov.w   DAT_06030a46, r2
    add r3, r2
    mov.l @r2, r4
    mov.l r4, @(r0, r3)
    mov.l @(48, r3), r5
    mov.l r5, @(40, r3)
.L_timeout_return:
    rts
    nop
.L_timeout_offset:
    .2byte  0x0250

    .global DAT_06030a40
DAT_06030a40:
    .2byte  0x0080
.L_channel_state_offset:
    .2byte  0x0160

    .global DAT_06030a44
DAT_06030a44:
    .2byte  0x01E4

    .global DAT_06030a46
DAT_06030a46:
    .2byte  0x01EC
.L_car_data_ptr:
    .4byte  sym_0607E940
.L_fp_neg_one:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_wram_low:
    .4byte  0x00200000                  /* Work RAM Low base */
    .4byte  0x53E34321
    .4byte  0x1E3352E5
    .4byte  0xD109D30A
    .4byte  0x11211321
    .4byte  0xD109D30A
    .4byte  0x11211321
    .4byte  0x9409D109
    .4byte  0x21429406
    .4byte  0xD1082142
    .4byte  0x4F266EF6
    .4byte  0x6DF6000B
    .4byte  0x6CF60006
    .4byte  sym_06063E4C
    .4byte  sym_06063E60
    .4byte  sym_06063E74
    .4byte  sym_06063E88
    .4byte  sym_0607EAE8
    .4byte  sym_0607EAEC
.L_mono_channel_path:
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @(40, r14), r5
    mov r5, r4
    sub r6, r4
    mov.w   DAT_06030b24, r1
    exts.w r4, r4
    extu.w r1, r1
    cmp/pl r4
    bt      .L_mono_wrap_done
    add r1, r4
.L_mono_wrap_done:
    shlr r1
    cmp/ge r4, r1
    bt      .L_mono_normalized
    shll r1
    sub r1, r4
.L_mono_normalized:
    mov r4, r1
    shar r1
    shar r1
    add r1, r4
    mov.w   DAT_06030b26, r0
    mov.l r4, @(r0, r14)
    sub r4, r5
    add #-0x4, r0
    mov.l r5, @(r0, r14)
    mov.w   DAT_06030b28, r4
    add #0x8, r0
    mov.w r4, @(r0, r14)
    mov.l   .L_channel_priority_mono, r0
    mov #0xF, r5
    mov.b r5, @r0
    mov.l   .L_channel_active_mono, r0
    mov #0x1, r1
    mov.b r1, @r0
    mov.w   DAT_06030b2a, r0
    mov.w   .L_mono_mix_bits, r1
    mov.l @(r0, r14), r2
    or r1, r2
    mov.l r2, @(r0, r14)
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.w @(14, r7), r0
    mov.l   .L_speaker_config_mono, r1
    mov #0x34, r2
    muls.w r2, r0
    sts macl, r2
    add r2, r1
    mov.l @(16, r1), r8
    mov.l   .L_music_ctrl_flag_mono, r2
    mov.w @r2, r2
    mov.l   .L_force_steer_impact_mono, r0
    mov.l @(20, r1), r10
    mov.l r6, @-r15
    mov.l @r1, r13
    mov.l   .L_minit, r6
    mov #0x0, r9
    tst r6, r13
    bf      .L_mono_dir_set
    mov #0x1, r9
.L_mono_dir_set:
    tst r2, r2
    bf      .L_mono_set_direction
    jsr @r0
    mov.l r5, @-r15
    bra     .L_mono_write_target
    mov.l @r15+, r5

    .global DAT_06030b24
DAT_06030b24:
    .2byte  0x8000

    .global DAT_06030b26
DAT_06030b26:
    .2byte  0x024C

    .global DAT_06030b28
DAT_06030b28:
    .2byte  0x000A

    .global DAT_06030b2a
DAT_06030b2a:
    .2byte  0x0214
.L_mono_mix_bits:
    .2byte  0x00CC
    .2byte  0x0000
.L_channel_priority_mono:
    .4byte  sym_0607866D
.L_channel_active_mono:
    .4byte  sym_06089595
.L_speaker_config_mono:
    .4byte  sym_060A6000
.L_music_ctrl_flag_mono:
    .4byte  sym_06030FBE
.L_force_steer_impact_mono:
    .4byte  force_steer_impact
.L_minit:
    .4byte  0x01000000                  /* MINIT — primary SH-2 init comm */
.L_mono_set_direction:
    mov.l   .L_direction_flag_mono, r0
    mov.l @(0, r14), r2
    or r0, r2
    mov.l r2, @(0, r14)
.L_mono_write_target:
    mov.l   .L_music_target_pos_mono, r0
    mov #0x0, r3
    mov.w r5, @r0
    mov.l r3, @-r15
    mov.l r3, @-r15
    bra     .L_dispatch_angle_path
    nop
    .2byte  0x0000
.L_direction_flag_mono:
    .4byte  0x08000000
.L_music_target_pos_mono:
    .4byte  sym_06030FBC
.L_multi_tracking_entry:
    mov #0x0, r13
    mov.l @(40, r14), r0
    mov r5, r6
    sub r0, r6
    exts.w r6, r6
    mov.l   .L_proximity_max, r2
    mov.l   .L_fp_sixteenth, r3
    cmp/ge r6, r3
    bt      .L_in_proximity_range
    cmp/ge r2, r6
    bt      .L_in_proximity_range
    bra     .L_check_position_changed
    nop
    .2byte  0x0000
.L_proximity_max:
    .4byte  0x00006FFF
.L_fp_sixteenth:
    .4byte  0x00001000                  /* 0.0625 (16.16 fixed-point) */
.L_in_proximity_range:
    neg r2, r2
    neg r3, r3
    cmp/ge r3, r6
    bt      .L_in_negative_range
    cmp/ge r6, r2
    bt      .L_in_negative_range
    bra     .L_check_position_changed
    nop
.L_in_negative_range:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l   .L_channel_active_sel, r0
    mov #0x1, r9
    mov.b r9, @r0
    mov.w   .L_music_mode_offset, r8
    mov #0x4, r9
    add r14, r8
    mov.w r9, @r8
    mov r4, r0
    cmp/eq #0x0, r0
    bt      .L_select_rear_left
    cmp/eq #0x1, r0
    bt      .L_select_front_left
    cmp/eq #0x2, r0
    bt      .L_select_front_right
    bra     .L_select_rear_right
    nop
.L_music_mode_offset:
    .2byte  0x0150
.L_channel_active_sel:
    .4byte  sym_06089595
.L_select_rear_left:
    mov.l @(0, r14), r0
    mov.w   .L_sel_flag_rear_left, r4
    or r4, r0
    mov.l r0, @(0, r14)
    mov #0x0, r4
    mov.w   .L_speaker_select_offset_0, r0
    mov.l r4, @(r0, r14)
    mov.l   .L_speaker_rear_left_sel, r1
    mov.w @(14, r1), r0
    mov r0, r3
    bra     .L_front_speaker_setup
    mov.l @(16, r1), r4
.L_sel_flag_rear_left:
    .2byte  0x0040
.L_speaker_select_offset_0:
    .2byte  0x0260
.L_speaker_rear_left_sel:
    .4byte  sym_06063E9C
.L_select_front_right:
    mov.l @(0, r14), r0
    mov.w   .L_sel_flag_front_right, r4
    or r4, r0
    mov.l r0, @(0, r14)
    mov #0x1, r4
    mov.w   .L_speaker_select_offset_1, r0
    mov.l r4, @(r0, r14)
    mov.l   .L_speaker_front_right_sel, r1
    mov.w @(14, r1), r0
    mov r0, r3
    bra     .L_front_speaker_setup
    mov.l @(16, r1), r4
.L_sel_flag_front_right:
    .2byte  0x0100
.L_speaker_select_offset_1:
    .2byte  0x0260
.L_speaker_front_right_sel:
    .4byte  sym_06063EC4
.L_select_front_left:
    mov.l @(0, r14), r0
    mov.w   .L_sel_flag_front_left, r4
    or r4, r0
    mov.l r0, @(0, r14)
    mov #0x2, r4
    mov.w   .L_speaker_select_offset_2, r0
    mov.l r4, @(r0, r14)
    mov.l   .L_speaker_front_left_sel, r1
    mov.w @(14, r1), r0
    mov r0, r3
    bra     .L_rear_speaker_setup
    mov.l @(16, r1), r4
.L_sel_flag_front_left:
    .2byte  0x0080
.L_speaker_select_offset_2:
    .2byte  0x0260
.L_speaker_front_left_sel:
    .4byte  sym_06063EB0
.L_select_rear_right:
    mov.l @(0, r14), r0
    mov.w   .L_sel_flag_rear_right, r4
    or r4, r0
    mov.l r0, @(0, r14)
    mov #0x3, r4
    mov.w   .L_speaker_select_offset_3, r0
    mov.l r4, @(r0, r14)
    mov.l   .L_speaker_rear_right_sel, r1
    mov.w @(14, r1), r0
    mov r0, r3
    bra     .L_rear_speaker_setup
    mov.l @(16, r1), r4
.L_sel_flag_rear_right:
    .2byte  0x0200
.L_speaker_select_offset_3:
    .2byte  0x0260
.L_speaker_rear_right_sel:
    .4byte  sym_06063ED8
.L_front_speaker_setup:
    mov.l r4, @-r15
    mov.l   .L_fade_state_a, r2
    mov.b @r2, r5
    tst r5, r5
    bf      .L_fade_init_done
    mov #0x5, r6
    mov.b r6, @r2
.L_fade_init_done:
    mov.l @(40, r14), r5
    sub r4, r5
    cmp/pz r5
    bt      .L_dist_abs_done
    neg r5, r5
.L_dist_abs_done:
    mov.w   DAT_06030cca, r6
    cmp/gt r5, r6
    bt      .L_front_prox_ok
    mov r6, r2
    shll r6
    add r6, r2
    cmp/gt r2, r5
    bt      .L_front_prox_ok
    add r6, r4
.L_front_prox_ok:
    exts.w r4, r4
    mov.l r4, @(48, r14)
    mov.l r4, @(40, r14)
    mov.l   .L_speaker_config_b, r1
    mov #0x34, r2
    muls.w r2, r3
    mov.l r13, @-r15
    sts macl, r2
    add r2, r1
    mov #0x1, r13
    mov.l @(16, r1), r8
    shll16 r13
    mov.l @(20, r1), r10
.L_angle_math_common:
    mov.l @(16, r14), r5
    shll8 r13
    dmuls.l r8, r5
    mov.l @(24, r14), r6
    mov.l @(0, r1), r0
    sts mach, r4
    sts macl, r5
    tst r0, r13
    xtrct r4, r5
    shlr8 r0
    mov #0x0, r9
    and #0x1, r0
    bf/s    .L_angle_dir_set_b
    add r10, r5
    add r6, r5
    mov #0x1, r9
.L_angle_dir_set_b:
    mov #0x0, r6
    cmp/pl r5
    bt      .L_sign_positive_b
    mov #0x1, r6
.L_sign_positive_b:
    mov #0x0, r4
    cmp/eq r0, r6
    bt      .L_quadrant_match_b
    mov #0x1, r4
.L_quadrant_match_b:
    mov.l r4, @-r15
.L_dispatch_angle_path:
    mov r8, r0
    cmp/eq #0x0, r0
    bf/s    .L_cos_nonzero_b
    mov r9, r0
    bra     .L_cos_zero_path_b
    nop

    .global DAT_06030cca
DAT_06030cca:
    .2byte  0x4000
.L_fade_state_a:
    .4byte  sym_0602FD9B
.L_speaker_config_b:
    .4byte  sym_060A6000
.L_cos_nonzero_b:
    cmp/eq #0x0, r0
    bf      .L_both_nonzero_b
    bra     .L_sin_zero_path_b
    nop
.L_rear_speaker_setup:
    mov.l r4, @-r15
    mov.l   .L_fade_state_b, r2
    mov.b @r2, r5
    tst r5, r5
    bf      .L_rear_fade_init_done
    mov #0x5, r6
    mov.b r6, @r2
.L_rear_fade_init_done:
    mov.l @(40, r14), r5
    sub r4, r5
    cmp/pz r5
    bt      .L_rear_dist_abs_done
    neg r5, r5
.L_rear_dist_abs_done:
    mov.w   DAT_06030d22, r6
    cmp/gt r5, r6
    bt      .L_rear_prox_ok
    mov r6, r2
    shll r6
    add r6, r2
    cmp/gt r2, r5
    bt      .L_rear_prox_ok
    add r6, r4
.L_rear_prox_ok:
    exts.w r4, r4
    mov.l r4, @(48, r14)
    mov.l r4, @(40, r14)
    mov.l   .L_speaker_config_c, r1
    mov #0x34, r2
    mov.l r13, @-r15
    muls.w r2, r3
    sts macl, r2
    add r2, r1
    mov #0x1, r13
    mov.l @(16, r1), r8
    shll16 r13
    bra     .L_angle_math_common
    mov.l @(20, r1), r10

    .global DAT_06030d22
DAT_06030d22:
    .2byte  0x4000
.L_fade_state_b:
    .4byte  sym_0602FD9C
.L_speaker_config_c:
    .4byte  sym_060A6000
.L_cos_zero_path_b:
    mov.l @(24, r14), r5
    add r10, r5
    cmp/pl r5
    bt      .L_cos_zero_abs_done_b
    neg r5, r5
.L_cos_zero_abs_done_b:
    bra     .L_finalize_blend
    nop
.L_sin_zero_path_b:
    neg r10, r4
    mov.l   .L_fpdiv_setup_d, r0
    jsr @r0
    mov r8, r5
    mov.l @(16, r14), r5
    sub r0, r5
    cmp/pl r5
    bt      .L_sin_zero_abs_done_b
    neg r5, r5
.L_sin_zero_abs_done_b:
    bra     .L_finalize_blend
    nop
.L_fpdiv_setup_d:
    .4byte  fpdiv_setup
.L_both_nonzero_b:
    mov.l @(24, r14), r2
    add r10, r2
    neg r8, r3
    dmuls.l r2, r3
    mov #0x1, r5
    shll16 r5
    mov.w   DAT_06030da2, r4
    sts mach, r2
    sts macl, r3
    cmp/gt r2, r4
    bf      .L_large_angle_path_b
    neg r4, r4
    cmp/gt r4, r2
    bt      .L_small_angle_path_b
.L_large_angle_path_b:
    shll8 r2
    shlr16 r3
    shlr8 r3
    or r2, r3
    mov.l @(16, r14), r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    add r3, r4
    neg r8, r2
    dmuls.l r2, r2
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    mov.l   .L_fpdiv_setup_e, r0
    jsr @r0
    add r2, r5
    shll8 r0
    bra     .L_blend_crossfade_b
    nop

    .global DAT_06030da2
DAT_06030da2:
    .2byte  0x7FFF
.L_fpdiv_setup_e:
    .4byte  fpdiv_setup
.L_small_angle_path_b:
    xtrct r2, r3
    mov.l @(16, r14), r4
    add r3, r4
    neg r8, r2
    dmuls.l r2, r2
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    mov.l   .L_fpdiv_setup_f, r0
    jsr @r0
    add r2, r5
.L_blend_crossfade_b:
    mov r0, r2
    neg r8, r3
    dmuls.l r3, r2
    neg r10, r5
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    add r2, r5
    mov.l @(16, r14), r2
    mov.l @(24, r14), r3
    sub r2, r0
    sub r3, r5
    cmp/pl r0
    bt      .L_x_abs_done_b
    neg r0, r0
.L_x_abs_done_b:
    cmp/pl r5
    bt      .L_y_abs_done_b
    neg r5, r5
.L_y_abs_done_b:
    cmp/gt r0, r5
    bt      .L_y_dominates_b
    shar r5
    shar r5
    bra     .L_blend_done_b
    add r0, r5
    .2byte  0x0000
.L_fpdiv_setup_f:
    .4byte  fpdiv_setup
.L_y_dominates_b:
    shar r0
    shar r0
    add r0, r5
.L_blend_done_b:
    bra     .L_finalize_blend
    nop
.L_finalize_blend:
    mov.l   .L_music_target_pos_final, r9
    mov.l @r15+, r3
    mov.l @r15+, r13
    mov.w @r9, r9
    mov.l @r15+, r2
    tst r13, r13
    bt      .L_no_sin_blend
    mov.l @(48, r14), r4
    mov.l   .L_sin_lookup, r0
    mov.l   .L_sin_scale_factor, r10
    jsr @r0
    sub r2, r4
    cmp/pz r0
    bt      .L_sin_abs_done
    neg r0, r0
.L_sin_abs_done:
    dmuls.l r0, r10
    sts mach, r0
    sts macl, r2
    bra     .L_apply_direction
    xtrct r0, r2
    .2byte  0x0000
.L_music_target_pos_final:
    .4byte  sym_06030FBC
.L_sin_lookup:
    .4byte  sin_lookup
.L_sin_scale_factor:
    .4byte  0x00038000
.L_no_sin_blend:
    mov.l   .L_default_blend_weight, r2
.L_apply_direction:
    cmp/pl r3
    bt/s    .L_subtract_blend
    mov r9, r4
    add r5, r2
    bra     .L_write_final_output
    nop
    .2byte  0x0000
.L_default_blend_weight:
    .4byte  0x00013333
.L_subtract_blend:
    sub r5, r2
    cmp/pl r2
    bt      .L_write_final_output
    .byte   0xA0, 0x3D    /* bra 0x06030ECC (external) */
    nop
.L_write_final_output:
    neg r4, r4
    mov r4, r10
    mov r2, r3
    mov r3, r9
    mov.l @(16, r14), r5
    mov.l @(24, r14), r6
    mov.l r5, @(56, r14)
    mov.l r6, @(60, r14)
    .byte   0xD0, 0x13    /* mov.l .L_pool_06030EB0, r0 */
