
    .section .text.FUN_0600FB78


    .global transition_large_results
    .type transition_large_results, @function
transition_large_results:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_game_status_base, r11
    mov.l   .L_fn_graphics_mode, r3
    jsr @r3
    nop
    mov.l   .L_fn_dual_hud_dispatch, r3
    jsr @r3
    nop
    mov.l   .L_two_player_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_two_player_active
    bra     .L_single_player_path
    nop
.L_two_player_active:
    mov.w   .L_name_y_offset, r10
    mov.w   .L_name_x_offset, r12
    mov.l   .L_fn_text_render, r13
    mov.l   .L_fn_display_channel_config, r14
    mov.l   .L_split_display_slot, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_render_car_stats
    bra     .L_render_split_defaults
    nop
.L_render_car_stats:
    mov.w   .L_stat_color_code, r8
    mov.l   .L_str_acceleration, r7
    mov.w   .L_accel_x_pos, r5
    mov r8, r6
    jsr @r14
    mov #0xC, r4
    mov.l   .L_display_slot_a, r9
    mov r8, r6
    mov.w   .L_car_name_a_x_pos, r5
    mov.l   .L_car_name_table_a, r3
    mov.l @r9, r7
    shll2 r7
    add r3, r7
    mov.l @r7, r7
    jsr @r14
    mov #0xC, r4
    mov.l   .L_str_grip, r7
    mov r8, r6
    mov.w   .L_grip_x_pos, r5
    jsr @r14
    mov #0xC, r4
    mov r8, r6
    mov.w   .L_car_name_b_x_pos, r5
    mov.l @r9, r7
    mov.l   .L_car_name_table_b, r3
    shll2 r7
    add r3, r7
    mov.l @r7, r7
    jsr @r14
    mov #0xC, r4
    mov.l @r9, r2
    mov #0x9, r3
    cmp/hi r3, r2
    bf      .L_check_timer_mode
    mov #0xB, r2
    mov.l   .L_transmission_flag, r4
    mov.l @r9, r3
    cmp/hi r2, r3
    bf      .L_check_trans_subtitle
    mov.l @r4, r0
    cmp/eq #0x1, r0
    bf      .L_use_mt_car_name
    mov.l   .L_str_car_at_name, r7
    bra     .L_render_car_name
    nop
.L_use_mt_car_name:
    mov.l   .L_str_car_mt_name, r7
.L_render_car_name:
    mov r10, r6
    mov r12, r5
    jsr @r13
    mov #0xC, r4
    bra     .L_check_timer_mode
    nop
.L_check_trans_subtitle:
    mov.l @r4, r0
    cmp/eq #0x1, r0
    bf      .L_use_mt_car_sub
    mov.l   .L_str_car_at_sub, r7
    bra     .L_render_car_subtitle
    nop
.L_name_y_offset:
    .2byte  0x0090
.L_name_x_offset:
    .2byte  0x07A2
.L_stat_color_code:
    .2byte  0x2000
.L_accel_x_pos:
    .2byte  0x0686
.L_car_name_a_x_pos:
    .2byte  0x06A0
.L_grip_x_pos:
    .2byte  0x0706
.L_car_name_b_x_pos:
    .2byte  0x0720
    .2byte  0xFFFF
.L_game_status_base:
    .4byte  g_pad_state
.L_fn_graphics_mode:
    .4byte  graphics_mode_setup
.L_fn_dual_hud_dispatch:
    .4byte  sym_06011EB4
.L_two_player_flag:
    .4byte  sym_06085FF4
.L_fn_text_render:
    .4byte  sym_060284AE
.L_fn_display_channel_config:
    .4byte  sym_060283E0
.L_split_display_slot:
    .4byte  sym_0607889C
.L_str_acceleration:
    .4byte  sym_06044750
.L_display_slot_a:
    .4byte  sym_06078868
.L_car_name_table_a:
    .4byte  sym_0605AB28
.L_str_grip:
    .4byte  sym_0604475D
.L_car_name_table_b:
    .4byte  sym_0605AB60
.L_transmission_flag:
    .4byte  sym_06078644
.L_str_car_at_name:
    .4byte  sym_06044878
.L_str_car_mt_name:
    .4byte  sym_06044888
.L_str_car_at_sub:
    .4byte  sym_06044898
.L_use_mt_car_sub:
    mov.l   .L_str_car_mt_sub, r7
.L_render_car_subtitle:
    mov r10, r6
    mov r12, r5
    jsr @r13
    mov #0xC, r4
.L_check_timer_mode:
    mov.w @(6, r11), r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_not_timer_mode
    mov.l   .L_anim_countdown, r4
    mov.l @r4, r0
    tst r0, r0
    bf      .L_decrement_countdown
    .byte   0xB5, 0x63    /* bsr 0x06010760 (external) */  ! countdown == 0: call timer-expired handler
    nop
    bra     .L_check_start_button
    nop
.L_decrement_countdown:
    mov.l @r4, r2
    add #-0x1, r2
    bra     .L_check_start_button
    mov.l r2, @r4
.L_not_timer_mode:
    mov.w @(2, r11), r0
    .byte   0xB4, 0x1A    /* bsr 0x060104E0 (external) */  ! call alternate dispatch handler
    mov r0, r4
    bra     .L_check_start_button
    nop
.L_render_split_defaults:
    mov.l   .L_str_default_tile_a, r2
    mov #0x0, r6
    mov.l r2, @r15
    mov r2, r7
    mov.w   .L_alt_accel_x_pos, r5
    jsr @r14
    mov #0xC, r4
    mov #0x0, r6
    mov.w   .L_alt_grip_x_pos, r5
    mov.l @r15, r7
    jsr @r14
    mov #0xC, r4
    mov.l   .L_str_default_tile_b, r7
    mov r10, r6
    mov r12, r5
    jsr @r13
    mov #0xC, r4
    bra     .L_check_start_button
    nop
.L_single_player_path:
    mov.l   .L_fn_anim_transition, r3
    jsr @r3
    mov #0x1, r4
    mov.w @(6, r11), r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_sp_not_timer_mode
    .byte   0xB3, 0xC4    /* bsr 0x06010470 (external) */  ! call 1P timer dispatch
    nop
    bra     .L_check_start_button
    nop
.L_sp_not_timer_mode:
    mov.w @(2, r11), r0
    .byte   0xB3, 0x63    /* bsr 0x060103B8 (external) */  ! call 1P alternate dispatch
    mov r0, r4
.L_check_start_button:
    mov r11, r2
    mov.l r2, @r15
    mov r2, r3
    mov.w @r3, r2
    mov r2, r0
    mov.w r0, @(4, r15)
    mov.w @(4, r15), r0
    mov.w   .L_button_start_mask, r2
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_clear_start_flag
    mov #0x1, r3
    mov.l   .L_start_pressed_flag, r2
    mov.l r3, @r2
    bra     .L_epilogue
    nop
.L_clear_start_flag:
    mov #0x0, r3
    mov.l   .L_start_pressed_flag, r2
    mov.l r3, @r2
.L_epilogue:
    mov.l @r15, r4
    add #0x2, r4
    mov.w @r4, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA6, 0xB7    /* bra 0x06010AA4 (external) */  ! tail-call state dispatch
    mov.l @r15+, r14
.L_alt_accel_x_pos:
    .2byte  0x0686
.L_alt_grip_x_pos:
    .2byte  0x0706
.L_button_start_mask:
    .2byte  0x0800
.L_str_car_mt_sub:
    .4byte  sym_060448A8
.L_anim_countdown:
    .4byte  sym_0605AA9C
.L_str_default_tile_a:
    .4byte  sym_0605ACE1
.L_str_default_tile_b:
    .4byte  sym_0605ACE3
.L_fn_anim_transition:
    .4byte  anim_ui_transition
.L_start_pressed_flag:
    .4byte  sym_0607EAE0
