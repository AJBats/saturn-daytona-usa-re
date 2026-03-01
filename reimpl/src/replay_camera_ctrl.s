
    .section .text.FUN_0601DBB8


    .global replay_camera_ctrl
    .type replay_camera_ctrl, @function
replay_camera_ctrl:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l   .L_car_array_base, r8
    mov.l   .L_replay_data_offset, r9
    mov.l   .L_cam_angle_ptr, r10
    mov.l   .L_fn_display_list_copy, r11
    mov.l   .L_cam_mode_ptr, r12
    mov.l   .L_cam_active_flag, r13
    mov.l   .L_cam_frame_counter_ptr, r14
    mov.l   .L_replay_enabled_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_replay_active
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     camera_cleanup_reset
    mov.l @r15+, r14
.L_replay_active:
    mov.b @r13, r0
    extu.b r0, r0
    tst r0, r0
    .word 0x0029
    mov.l   .L_race_event_bitfield, r3
    mov.l @r3, r3
    and r3, r0
    tst #0x1, r0
    bt      .L_check_mode_flags
    bra     .L_init_camera_mode
    nop
    .2byte  0xFFFF
.L_car_array_base:
    .4byte  sym_06078900
.L_replay_data_offset:
    .4byte  0x00009000
.L_cam_angle_ptr:
    .4byte  sym_0608706C
.L_fn_display_list_copy:
    .4byte  sym_06028400
.L_cam_mode_ptr:
    .4byte  sym_06087074
.L_cam_active_flag:
    .4byte  sym_06087068
.L_cam_frame_counter_ptr:
    .4byte  sym_06087070
.L_replay_enabled_flag:
    .4byte  sym_060786AC
.L_race_event_bitfield:
    .4byte  sym_0607EBF4
.L_check_mode_flags:
    mov.b @r13, r0
    extu.b r0, r0
    tst r0, r0
    .word 0x0029
    mov.l   .L_race_state_flags, r3
    mov.l @r3, r3
    and r3, r0
    mov r0, r3
    mov r8, r0
    mov.b @(3, r0), r0
    tst #0x8, r0
    .word 0x0229
    add #-0x1, r2
    neg r2, r2
    tst r2, r2
    .word 0x0029
    and r3, r0
    tst #0x1, r0
    bt      .L_check_active_state
.L_init_camera_mode:
    mov #0x1, r3
    mov.b r3, @r13
    mov.w   DAT_0601dd30, r2
    mov.l   .L_cam_countdown_timer, r3
    mov.w r2, @r3
    mov #0x0, r2
    mov.l   .L_cam_interp_counter, r3
    mov.b r2, @r3
    mov #0x3, r3
    mov.l   .L_race_timer_value, r2
    mov.l @r2, r2
    mov.l r2, @r14
    mov.l   .L_cam_mode_table_a, r4
    mov.l r3, @r12
    mov.l   .L_race_end_state, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_compute_cam_params
    mov.l   .L_cam_mode_table_b, r4
    mov #0x6, r3
    mov.l r3, @r12
.L_compute_cam_params:
    mov.w   .L_car_lap_count_off, r0
    mov.l   .L_fn_fixed_divide, r3
    mov.l @(r0, r8), r1
    add #-0x1, r1
    jsr @r3
    mov.l @r12, r0
    shll2 r0
    mov #0x9, r3
    mov.l @(r0, r4), r2
    mov.l r2, @r10
    mov.l   .L_cam_state_byte, r2
    mov.b r3, @r2
    mov.l @r14, r3
    mov.l @r10, r2
    cmp/hs r2, r3
    bt      .L_check_active_state
    mov #0xA, r2
    mov.l   .L_cam_state_byte, r3
    mov.b r2, @r3
    mov.l @r14, r2
    mov.l r2, @r10
    mov.w   .L_car_lap_count_off, r0
    mov.l   .L_fn_fixed_divide, r3
    mov.l @(r0, r8), r1
    add #-0x1, r1
    jsr @r3
    mov.l @r12, r0
    shll2 r0
    mov.l @r14, r2
    mov.l r2, @(r0, r4)
.L_check_active_state:
    mov.b @r13, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_update_cam_timer
    bra     .L_epilogue_return
    nop
.L_update_cam_timer:
    mov.l   .L_cam_interp_counter, r3
    mov.l   .L_cam_interp_counter, r2
    mov.b @r3, r3
    add #0x30, r3
    mov.b r3, @r2
    extu.b r3, r3
    mov.w   DAT_0601dd34, r1
    cmp/ge r1, r3
    bt      .L_timer_expired
    mov.l   .L_replay_buf_a, r2
    mov.l r2, @(4, r15)
    mov r2, r7
    mov.w   .L_disp_chan_pos_x, r6
    mov.w   .L_car_lap_count_off, r0
    mov.l   .L_fn_fixed_divide, r3
    mov.l @(4, r7), r7
    mov.l @(r0, r8), r1
    add r9, r7
    add #-0x1, r1
    jsr @r3
    mov.l @r12, r0
    mov #0xE, r5
    mov.l   .L_cam_param_table, r3
    mul.l r5, r0
    sts macl, r5
    add r3, r5
    jsr @r11
    mov #0x8, r4
    mov.l   .L_replay_buf_b, r2
    mov.l r2, @r15
    mov r2, r7
    mov.l   .L_cam_state_byte, r3
    mov.w   .L_disp_chan_angle, r6
    mov.l   .L_replay_buf_base, r5
    mov.l @(4, r7), r7
    mov.b @r3, r3
    mov.l @r5, r5
    extu.b r3, r3
    shll8 r3
    shll2 r3
    shll2 r3
    add r3, r7
    jsr @r11
    mov #0x8, r4
    mov.l @r15, r7
    mov.l @(4, r7), r7
    add r9, r7
    mov.w   .L_disp_chan_speed, r6
    bra     .L_copy_replay_data
    nop

    .global DAT_0601dd30
DAT_0601dd30:
    .2byte  0x00A0
.L_car_lap_count_off:
    .2byte  0x0230

    .global DAT_0601dd34
DAT_0601dd34:
    .2byte  0x00C0
.L_disp_chan_pos_x:
    .2byte  0x07C8
.L_disp_chan_angle:
    .2byte  0x0842
.L_disp_chan_speed:
    .2byte  0x0942
.L_race_state_flags:
    .4byte  sym_0607EABC
.L_cam_countdown_timer:
    .4byte  sym_0608706A
.L_cam_interp_counter:
    .4byte  sym_0605DFED
.L_race_timer_value:
    .4byte  sym_060786A0
.L_cam_mode_table_a:
    .4byte  sym_0605DDB4
.L_race_end_state:
    .4byte  sym_0607EAD8
.L_cam_mode_table_b:
    .4byte  sym_0605DDD4
.L_fn_fixed_divide:
    .4byte  sym_060350B0
.L_cam_state_byte:
    .4byte  sym_0608707C
.L_replay_buf_a:
    .4byte  sym_060639F8
.L_cam_param_table:
    .4byte  sym_0605E008
.L_replay_buf_b:
    .4byte  sym_060639E0
.L_replay_buf_base:
    .4byte  sym_060639D8
.L_copy_replay_data:
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r11
    mov #0x8, r4
    bsr     hud_element_pos
    mov.l @r10, r4
    mov.l @(4, r15), r7
    mov.w   DAT_0601de24, r6
    mov.l   .L_hud_element_table, r5
    mov.l @(4, r7), r7
    add r9, r7
    jsr @r11
    mov #0x8, r4
    mov.l @r14, r3
    mov.l   .L_max_frame_count, r2
    cmp/hs r2, r3
    bf      .L_use_frame_counter
    mov.l   .L_max_frame_count, r4
    bsr     hud_element_pos
    nop
    bra     .L_copy_speed_channel
    nop
.L_use_frame_counter:
    bsr     hud_element_pos
    mov.l @r14, r4
.L_copy_speed_channel:
    mov.l   .L_replay_buf_a_2, r7
    mov.w   DAT_0601de26, r6
    mov.l   .L_hud_element_table, r5
    mov.l @(4, r7), r7
    add r9, r7
    jsr @r11
    mov #0x8, r4
    bra     .L_decrement_countdown
    nop
.L_timer_expired:
    bsr     camera_cleanup_reset
    nop
.L_decrement_countdown:
    mov.l   .L_cam_countdown_timer_2, r2
    mov.l   .L_cam_countdown_timer_2, r3
    mov.w @r2, r2
    add #-0x1, r2
    mov.w r2, @r3
    extu.w r2, r2
    cmp/pl r2
    bt      .L_epilogue_return
    mov #0x0, r3
    mov.b r3, @r13
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     camera_cleanup_reset
    mov.l @r15+, r14
.L_epilogue_return:
    add #0x8, r15
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

    .global camera_cleanup_reset
    .type camera_cleanup_reset, @function
camera_cleanup_reset:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_display_channel_base, r14
    mov.w   .L_chan_size_0x90, r6
    mov.w   .L_chan_a_elem_id, r5
    mov.l   .L_fn_display_list_render, r3
    mov r14, r7
    jsr @r3
    mov #0x8, r4
    mov r14, r7
    mov.w   .L_chan_size_0x90, r6
    mov.w   .L_chan_b_elem_id, r5
    mov.l   .L_fn_display_list_render, r3
    jsr @r3
    mov #0x8, r4
    mov r14, r7
    mov.l   .L_mask_0xE000, r6
    mov.w   .L_chan_c_elem_id, r5
    mov #0x8, r4
    lds.l @r15+, pr
    mov.l   .L_fn_render_dispatch, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_0601de24
DAT_0601de24:
    .2byte  0x08C4
DAT_0601de26:
    .2byte  0x09C4
.L_chan_size_0x90:
    .2byte  0x0090
.L_chan_a_elem_id:
    .2byte  0x07C2
.L_chan_b_elem_id:
    .2byte  0x08C2
.L_chan_c_elem_id:
    .2byte  0x09C2
.L_hud_element_table:
    .4byte  sym_0605DFF4
.L_max_frame_count:
    .4byte  0x000927BF
.L_replay_buf_a_2:
    .4byte  sym_060639F8
.L_cam_countdown_timer_2:
    .4byte  sym_0608706A
.L_display_channel_base:
    .4byte  sym_0605ACE3
.L_fn_display_list_render:
    .4byte  sym_060284AE
.L_mask_0xE000:
    .4byte  0x0000E000                  /* bits 15:13 mask */
.L_fn_render_dispatch:
    .4byte  sym_060283E0

    .global camera_event_handler
    .type camera_event_handler, @function
camera_event_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_frame_counter, r4
    mov.l   .L_max_frame_count_evt, r2
    mov.l @r4, r4
    mov r4, r3
    shll2 r4
    add r3, r4
    cmp/hs r2, r4
    bf      .L_use_raw_frame
    mov.l   .L_max_frame_count_evt, r4
    bsr     hud_element_pos
    nop
    bra     .L_setup_position_display
    nop
.L_use_raw_frame:
    bsr     hud_element_pos
    nop
.L_setup_position_display:
    mov.l   .L_replay_struct_base, r12
    mov.l   .L_fn_display_list_copy_evt, r14
    mov.w   DAT_0601df14, r0
    mov.l   .L_replay_data_offset_evt, r2
    mov.w   DAT_0601df16, r6
    mov.l   .L_hud_element_table_evt, r5
    mov.l @(r0, r12), r7
    add r2, r7
    jsr @r14
    mov #0x8, r4
    mov.l   .L_car_array_base_evt, r13
    mov.w   DAT_0601df18, r0
    mov.l   .L_total_race_frames, r2
    mov r13, r4
    mov.l @r2, r2
    mov.l @(r0, r4), r3
    cmp/hs r2, r3
    .word 0x0029
    xor #0x1, r0
    mov.w   DAT_0601df1a, r1
    add r4, r1
    mov.l @r1, r1
    tst r1, r1
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r0
    tst r0, r0
    bt      .L_evt_return
    mov.l   .L_race_end_state_evt, r4
    mov.l   .L_attract_timer, r3
    mov.l   .L_cam_target_array, r2
    mov.w   DAT_0601df18, r0
    mov.l @r4, r4
    mov.l @r3, r3
    shll r4
    add r3, r4
    shll2 r4
    mov.l @(r0, r13), r3
    add r2, r4
    mov.l @r4, r4
    mov.l r3, @(4, r4)
    mov.w   DAT_0601df1c, r7
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_extended_data_offset, r3
    mov.w   .L_evt_disp_chan_pos, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_blink_counter, r4
    mov.b @r4, r3
    add #0x40, r3
    mov.b r3, @r4
    mov.b @r4, r0
    extu.b r0, r0
    shlr2 r0
    shlr2 r0
    shlr2 r0
    shlr r0
    tst #0x1, r0
    bf      .L_blink_off_tail
    mov.w   DAT_0601df18, r0
    bsr     hud_element_pos
    mov.l @(r0, r13), r4
    mov.w   DAT_0601df14, r0
    mov.l   .L_extended_data_offset, r2
    mov.w   .L_evt_disp_chan_angle, r6
    mov.l   .L_hud_element_table_evt, r5
    mov.l @(r0, r12), r7
    add r2, r7
    jsr @r14
    mov #0x8, r4
    bra     .L_evt_return
    nop

    .global DAT_0601df14
DAT_0601df14:
    .2byte  0x02AC

    .global DAT_0601df16
DAT_0601df16:
    .2byte  0x0644

    .global DAT_0601df18
DAT_0601df18:
    .2byte  0x0240

    .global DAT_0601df1a
DAT_0601df1a:
    .2byte  0x021C

    .global DAT_0601df1c
DAT_0601df1c:
    .2byte  0x0278
.L_evt_disp_chan_pos:
    .2byte  0x03C2
.L_evt_disp_chan_angle:
    .2byte  0x0444
    .2byte  0xFFFF
.L_frame_counter:
    .4byte  sym_0607EBD0
.L_max_frame_count_evt:
    .4byte  0x000927BF
.L_replay_struct_base:
    .4byte  sym_06063750
.L_fn_display_list_copy_evt:
    .4byte  sym_06028400
.L_replay_data_offset_evt:
    .4byte  0x00009000
.L_hud_element_table_evt:
    .4byte  sym_0605DFF4
.L_car_array_base_evt:
    .4byte  sym_06078900
.L_total_race_frames:
    .4byte  sym_06086008
.L_race_end_state_evt:
    .4byte  sym_0607EAD8
.L_attract_timer:
    .4byte  sym_0607EAE0
.L_cam_target_array:
    .4byte  sym_0605DE24
.L_extended_data_offset:
    .4byte  0x0000A000
.L_blink_counter:
    .4byte  sym_0605DFEC
.L_blink_off_tail:
    mov.l   .L_display_channel_base_evt, r7
    mov.l   .L_mask_0xE000_evt, r6
    mov.w   .L_evt_tail_elem_id, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_render_dispatch_evt, r3
    jmp @r3
    mov.l @r15+, r14
.L_evt_return:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_evt_tail_elem_id:
    .2byte  0x0442
.L_display_channel_base_evt:
    .4byte  sym_0605ACE3
.L_mask_0xE000_evt:
    .4byte  0x0000E000                  /* bits 15:13 mask */
.L_fn_render_dispatch_evt:
    .4byte  sym_060283E0

    .global camera_special_mode
    .type camera_special_mode, @function
camera_special_mode:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_extended_data_offset_spc, r9
    mov.l   .L_max_frame_count_spc, r10
    mov.w   .L_replay_struct_off_spc, r11
    mov.l   .L_replay_struct_base_spc, r12
    mov.l   .L_cam_position_ptr, r13
    mov.l   .L_fn_display_list_copy_spc, r14
    mov.l   .L_car_array_base_spc, r3
    mov r11, r0
    add #-0x68, r0
    mov.l @(r0, r3), r2
    mov.l   .L_total_race_frames_spc, r3
    mov.l @r3, r3
    cmp/hs r3, r2
    bt      .L_setup_hud_position
    mov.w   DAT_0601e024, r7
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_spc_disp_chan_pos, r6
    mov.l @r15, r5
    add r9, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_car_array_base_spc, r4
    mov.w   DAT_0601e028, r0
    bsr     hud_element_pos
    mov.l @(r0, r4), r4
    mov r12, r7
    mov.w   DAT_0601e02a, r6
    mov.l   .L_hud_element_table_spc, r5
    add r11, r7
    mov.l @(4, r7), r7
    add r9, r7
    jsr @r14
    mov #0x8, r4
.L_setup_hud_position:
    bsr     hud_element_pos
    mov.l @r13, r4
    mov r12, r7
    mov.l   .L_replay_data_offset_spc, r3
    mov.w   DAT_0601e02c, r6
    mov.l   .L_hud_element_table_spc, r5
    add r11, r7
    mov.l @(4, r7), r7
    add r3, r7
    jsr @r14
    mov #0x8, r4
    mov.l @r13, r2
    mov.l   .L_replay_length_limit, r3
    mov.l @r3, r3
    cmp/hs r3, r2
    bt      .L_spc_return
    mov.w   DAT_0601e02e, r7
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_spc_disp_chan_extra, r6
    mov.l @r15, r5
    add r9, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.l @r13, r3
    cmp/hs r10, r3
    bf      .L_use_cam_position
    bsr     hud_element_pos
    mov r10, r4
    bra     .L_copy_angle_data
    nop
.L_replay_struct_off_spc:
    .2byte  0x02A8

    .global DAT_0601e024
DAT_0601e024:
    .2byte  0x0278
.L_spc_disp_chan_pos:
    .2byte  0x03C2

    .global DAT_0601e028
DAT_0601e028:
    .2byte  0x0240

    .global DAT_0601e02a
DAT_0601e02a:
    .2byte  0x0444

    .global DAT_0601e02c
DAT_0601e02c:
    .2byte  0x0644

    .global DAT_0601e02e
DAT_0601e02e:
    .2byte  0x0280
.L_spc_disp_chan_extra:
    .2byte  0x04C2
    .2byte  0xFFFF
.L_extended_data_offset_spc:
    .4byte  0x0000A000
.L_max_frame_count_spc:
    .4byte  0x000927BF
.L_replay_struct_base_spc:
    .4byte  sym_06063750
.L_cam_position_ptr:
    .4byte  sym_0607863C
.L_fn_display_list_copy_spc:
    .4byte  sym_06028400
.L_car_array_base_spc:
    .4byte  sym_06078900
.L_total_race_frames_spc:
    .4byte  sym_06086008
.L_hud_element_table_spc:
    .4byte  sym_0605DFF4
.L_replay_data_offset_spc:
    .4byte  0x00009000
.L_replay_length_limit:
    .4byte  sym_06086004
.L_use_cam_position:
    bsr     hud_element_pos
    mov.l @r13, r4
.L_copy_angle_data:
    mov r12, r7
    mov.l   .L_replay_data_offset_spc2, r3
    mov.w   DAT_0601e0e2, r6
    mov.l   .L_hud_element_table_spc2, r5
    add r11, r7
    mov.l @(4, r7), r7
    add r3, r7
    jsr @r14
    mov #0x8, r4
    mov.l   .L_blink_counter_spc, r4
    mov.b @r4, r2
    add #0x40, r2
    mov.b r2, @r4
    mov.b @r4, r0
    extu.b r0, r0
    shlr2 r0
    shlr2 r0
    shlr2 r0
    shlr r0
    tst #0x1, r0
    bf      .L_spc_blink_off_tail
    mov.l @r13, r3
    cmp/hs r10, r3
    bf      .L_use_cam_pos_blink
    bsr     hud_element_pos
    mov r10, r4
    bra     .L_copy_speed_blink
    nop
.L_use_cam_pos_blink:
    bsr     hud_element_pos
    mov.l @r13, r4
.L_copy_speed_blink:
    mov r12, r7
    mov.w   DAT_0601e0e4, r6
    mov.l   .L_hud_element_table_spc2, r5
    add r11, r7
    mov.l @(4, r7), r7
    add r9, r7
    jsr @r14
    mov #0x8, r4
    bra     .L_spc_return
    nop
.L_spc_blink_off_tail:
    mov.l   .L_display_channel_base_spc, r7
    mov.l   .L_mask_0xE000_spc, r6
    mov.w   .L_spc_tail_elem_id, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_render_dispatch_spc, r3
    jmp @r3
    mov.l @r15+, r14
.L_spc_return:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0601E0DE
sym_0601E0DE:
    rts
    nop

    .global DAT_0601e0e2
DAT_0601e0e2:
    .2byte  0x0644

    .global DAT_0601e0e4
DAT_0601e0e4:
    .2byte  0x0544
.L_spc_tail_elem_id:
    .2byte  0x0542
.L_replay_data_offset_spc2:
    .4byte  0x00009000
.L_hud_element_table_spc2:
    .4byte  sym_0605DFF4
.L_blink_counter_spc:
    .4byte  sym_0605DFEC
.L_display_channel_base_spc:
    .4byte  sym_0605ACE3
.L_mask_0xE000_spc:
    .4byte  0x0000E000                  /* bits 15:13 mask */
.L_fn_render_dispatch_spc:
    .4byte  sym_060283E0

    .global geom_matrix_setup
    .type geom_matrix_setup, @function
geom_matrix_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_replay_struct_base_geom, r13
    mov.l   .L_fn_display_list_copy_geom, r14
    mov.l   .L_fp_half, r12
    mov.l   .L_attract_timer_geom, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_load_alt_palette
    mov.l   .L_nbg3_palette_src, r5
    mov.l   .L_vdp2_cram_0x100, r4
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3
    mov #0x20, r6
    mov r13, r7
    add #0x10, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_0601e162, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_0601e164, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    add r12, r7
    mov.w   DAT_0601e166, r6
    mov.l @r15, r5
    bra     .L_final_hud_copy
    mov.l @r5, r5
.L_load_alt_palette:
    mov.l   .L_alt_palette_src, r5
    mov.l   .L_vdp2_cram_0x100, r4
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3
    mov #0x20, r6
    mov.l   .L_course_variant, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_use_default_struct
    mov.w   .L_variant1_struct_off, r7
    bra     .L_setup_hud_channels
    nop

    .global DAT_0601e162
DAT_0601e162:
    .2byte  0x0344

    .global DAT_0601e164
DAT_0601e164:
    .2byte  0x0270

    .global DAT_0601e166
DAT_0601e166:
    .2byte  0x06C6
.L_variant1_struct_off:
    .2byte  0x00F8
    .2byte  0xFFFF
.L_replay_struct_base_geom:
    .4byte  sym_06063750
.L_fn_display_list_copy_geom:
    .4byte  sym_06028400
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_attract_timer_geom:
    .4byte  sym_0607EAE0
.L_nbg3_palette_src:
    .4byte  sym_0604892C
.L_vdp2_cram_0x100:
    .4byte  0x25F00100                  /* VDP2 color RAM +0x100 */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx
.L_alt_palette_src:
    .4byte  sym_0605DFCC
.L_course_variant:
    .4byte  sym_06078644
.L_use_default_struct:
    mov.w   DAT_0601e238, r7
.L_setup_hud_channels:
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_0601e23a, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_replay_data_offset_geom, r12
    mov.w   DAT_0601e23c, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_geom_chan_a_elem, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_0601e240, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_geom_chan_b_elem, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_0601e244, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_geom_chan_c_elem, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_fn_cam_path_lookup, r3
    jsr @r3
    nop
    mov.l   .L_total_race_frames_geom, r4
    bsr     hud_element_pos
    mov.l @r4, r4
    mov.w   DAT_0601e248, r11
    mov.w   DAT_0601e24a, r6
    mov.l   .L_hud_element_table_geom, r5
    add r13, r11
    mov.l @(4, r11), r7
    add r12, r7
    jsr @r14
    mov #0x8, r4
    mov.l   .L_replay_length_limit_geom, r4
    bsr     hud_element_pos
    mov.l @r4, r4
    mov.l @(4, r11), r7
    mov.w   DAT_0601e24c, r6
    mov.l   .L_hud_element_table_geom, r5
    add r12, r7
    jsr @r14
    mov #0x8, r4
    bsr     hud_element_pos
    mov #0x0, r4
    mov.l @(4, r11), r7
    add r12, r7
    mov.w   DAT_0601e24e, r6
    mov.l   .L_hud_element_table_geom, r5
.L_final_hud_copy:
    jsr @r14
    mov #0x8, r4
    mov #0x0, r4
    mov.l   .L_cam_active_reset, r3
    mov.b r4, @r3
    mov.l   .L_hud_state_clear, r3
    mov.l r4, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601e238
DAT_0601e238:
    .2byte  0x0100

    .global DAT_0601e23a
DAT_0601e23a:
    .2byte  0x00C4

    .global DAT_0601e23c
DAT_0601e23c:
    .2byte  0x0278
.L_geom_chan_a_elem:
    .2byte  0x03C2

    .global DAT_0601e240
DAT_0601e240:
    .2byte  0x0280
.L_geom_chan_b_elem:
    .2byte  0x04C2

    .global DAT_0601e244
DAT_0601e244:
    .2byte  0x0290
.L_geom_chan_c_elem:
    .2byte  0x05C2

    .global DAT_0601e248
DAT_0601e248:
    .2byte  0x02A8

    .global DAT_0601e24a
DAT_0601e24a:
    .2byte  0x0444

    .global DAT_0601e24c
DAT_0601e24c:
    .2byte  0x0544

    .global DAT_0601e24e
DAT_0601e24e:
    .2byte  0x0644
.L_replay_data_offset_geom:
    .4byte  0x00009000
.L_fn_cam_path_lookup:
    .4byte  sym_0601AB8C
.L_total_race_frames_geom:
    .4byte  sym_06086008
.L_hud_element_table_geom:
    .4byte  sym_0605DFF4
.L_replay_length_limit_geom:
    .4byte  sym_06086004
.L_cam_active_reset:
    .4byte  sym_06087068
.L_hud_state_clear:
    .4byte  sym_0605DFF0

    .global hud_element_pos
    .type hud_element_pos, @function
hud_element_pos:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_hud_pos_output, r12
    mov.l   .L_frame_data_ptr, r13
    mov.l   .L_fn_anim_frame_transform, r3
    jsr @r3
    mov #0x8, r14
    mov.l r0, @r13
    mov #0x0, r4
.L_unpack_loop:
    extu.b r4, r2
    extu.b r4, r0
    mov.l @r13, r3
    shll r2
    add #0x1, r4
    mov.b @(r0, r3), r1
    add r12, r2
    extu.b r1, r1
    extu.b r4, r3
    mov r1, r0
    mov.w r0, @(4, r2)
    cmp/ge r14, r3
    bf      .L_unpack_loop
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_hud_pos_output:
    .4byte  sym_0605DFF4
.L_frame_data_ptr:
    .4byte  sym_06087064
.L_fn_anim_frame_transform:
    .4byte  anim_frame_transform
