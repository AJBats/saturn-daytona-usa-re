
    .section .text.FUN_060092D0


    .global state_post_lap
    .type state_post_lap, @function
state_post_lap:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_course_state_ptr, r13
    mov.l   .L_next_game_state, r14
    mov.l   .L_input_buttons, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_btn_start_mask, r3
    and r3, r2
    tst r2, r2
    bt      .L_start_not_pressed
    mov #0x11, r3
    mov.l   .L_transition_state, r2
    mov.l r3, @r2
    mov #0x12, r3
    mov.l r3, @r14
.L_start_not_pressed:
    mov.l   .L_fn_race_frame_proc, r3
    jsr @r3
    nop
    mov.l   .L_timing_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_check_event_flags
    mov.l   .L_race_active_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_check_event_flags
    mov.l   .L_countdown_timer, r3
    mov.l   .L_countdown_timer, r2
    mov.l @r3, r3
    add #-0x1, r3
    cmp/pl r3
    bt/s    .L_check_event_flags
    mov.l r3, @r2
    mov.l   .L_fn_transition_prepare, r3
    jsr @r3
    nop
    mov.l   .L_player_car_ptr, r2
    mov.l @r2, r2
    mov.w   .L_off_car_score, r0
    mov.l @(r0, r2), r3
    mov.l   .L_score_store, r1
    mov.l r3, @r1
    mov #0x18, r3
    mov.l r3, @r14
.L_check_event_flags:
    mov.l   .L_race_event_flags, r4
    mov.l @r4, r0
    tst #0x1, r0
    bt      .L_check_idle_counter
    mov #-0x2, r3
    mov.l @r4, r2
    and r3, r2
    mov.l   .L_fn_transition_prepare, r3
    jsr @r3
    mov.l r2, @r4
    mov #0x14, r2
    mov.l   .L_fn_handler_init_reset, r3
    jsr @r3
    mov.l r2, @r14
    bra     .L_check_sound_trigger
    nop
.L_btn_start_mask:
    .2byte  0x0800
.L_off_car_score:
    .2byte  0x0240
.L_course_state_ptr:
    .4byte  sym_0607EAD8
.L_next_game_state:
    .4byte  g_game_state
.L_input_buttons:
    .4byte  sym_06063D9A
.L_transition_state:
    .4byte  sym_0607EACC
.L_fn_race_frame_proc:
    .4byte  sym_0600A33C
.L_timing_flag:
    .4byte  sym_06085FF4
.L_race_active_flag:
    .4byte  sym_0607EAD0
.L_countdown_timer:
    .4byte  sym_0607EAAC
.L_fn_transition_prepare:
    .4byte  sym_060192CA
.L_player_car_ptr:
    .4byte  sym_0607E944
.L_score_store:
    .4byte  sym_06078638
.L_race_event_flags:
    .4byte  sym_0607EBF4
.L_fn_handler_init_reset:
    .4byte  handler_init_reset
.L_check_idle_counter:
    mov.l   .L_race_active_flag_2, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_check_sound_trigger
    mov.l   .L_idle_frame_counter, r4
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
.L_check_sound_trigger:
    mov.l   .L_sound_timer, r2
    mov.w @r2, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_check_replay_mode
    mov.l   .L_countdown_timer_2, r3
    mov.w   .L_sound_trigger_val, r2
    mov.l @r3, r3
    cmp/eq r2, r3
    bf      .L_check_replay_mode
    mov.l   .L_snd_cmd_lap_complete, r5
    mov.l   .L_fn_sound_dispatch, r3
    jsr @r3
    mov #0x0, r4
    mov #0x28, r2
    mov.l   .L_sound_timer, r3
    mov.w r2, @r3
.L_check_replay_mode:
    mov.l   .L_replay_mode_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_check_camera
    mov.l @r13, r0
    tst r0, r0
    bt      .L_call_race_init
    mov.l   .L_fn_race_cleanup, r3
    jsr @r3
    nop
    bra     .L_check_camera
    nop
.L_sound_trigger_val:
    .2byte  0x00C8
.L_race_active_flag_2:
    .4byte  sym_0607EAD0
.L_idle_frame_counter:
    .4byte  sym_0607EBD0
.L_sound_timer:
    .4byte  sym_06086054
.L_countdown_timer_2:
    .4byte  sym_0607EAAC
.L_snd_cmd_lap_complete:
    .4byte  0xAE1134FF
.L_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch
.L_replay_mode_flag:
    .4byte  sym_06078636
.L_fn_race_cleanup:
    .4byte  race_cleanup_handler
.L_call_race_init:
    mov.l   .L_fn_race_init_helper, r3
    jsr @r3
    nop
.L_check_camera:
    mov.l   .L_camera_active_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_check_menu_overlay
    mov.l   .L_fn_camera_event, r3
    jsr @r3
    nop
    mov.l @r13, r0
    tst r0, r0
    bt      .L_check_menu_overlay
    mov.l   .L_fn_replay_camera, r3
    jsr @r3
    nop
.L_check_menu_overlay:
    mov.l   .L_menu_active_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_check_lap_complete
    mov.l   .L_fn_menu_overlay, r3
    jsr @r3
    mov #0x0, r4
.L_check_lap_complete:
    mov.l   .L_lap_complete_status, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_check_attract_camera
    mov #0x1C, r3
    mov.l r3, @r14
.L_check_attract_camera:
    mov.l @r13, r0
    cmp/eq #0x2, r0
    bf      .L_per_frame_updates
    mov.l   .L_fn_camera_attract, r3
    jsr @r3
    nop
.L_per_frame_updates:
    mov.l   .L_fn_car_iteration, r3
    jsr @r3
    nop
    mov.l   .L_fn_car_proximity, r3
    jsr @r3
    nop
    mov.l   .L_fn_camera_system, r3
    jsr @r3
    nop
    mov.l   .L_camera_eye_pos, r6
    mov.l   .L_camera_target_pos, r5
    mov.l   .L_camera_up_vec, r4
    mov.l   .L_fn_camera_orient, r3
    jsr @r3
    mov.l @r6, r6
    mov.l   .L_fn_snd_race_update, r3
    jsr @r3
    nop
    mov.l   .L_fn_scene_master, r3
    jsr @r3
    nop
    mov.l   .L_extended_display_flag, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_check_minimap
    mov.l   .L_fn_extended_display, r3
    jsr @r3
    nop
.L_check_minimap:
    mov.l   .L_minimap_enable_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_check_replay_data
    mov.l   .L_minimap_data_ptr, r7
    mov.l   .L_mask_nibble3, r6
    mov.w   .L_minimap_param, r5
    mov.l   .L_fn_minimap_render, r3
    jsr @r3
    mov #0x8, r4
.L_check_replay_data:
    mov.l   .L_player_car_ptr_2, r2
    mov.w   .L_off_car_replay, r0
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    cmp/pl r3
    bf      .L_epilogue
    .byte   0xB5, 0xF7    /* bsr 0x0600A084 (replay_record */
    nop
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_fn_frame_end_commit, r3
    jmp @r3
    mov.l @r15+, r14
.L_minimap_param:
    .2byte  0x0082
.L_off_car_replay:
    .2byte  0x00BC
.L_fn_race_init_helper:
    .4byte  sym_06012198
.L_camera_active_flag:
    .4byte  sym_0607EAE0
.L_fn_camera_event:
    .4byte  camera_event_handler
.L_fn_replay_camera:
    .4byte  replay_camera_ctrl
.L_menu_active_flag:
    .4byte  sym_0605AB18
.L_fn_menu_overlay:
    .4byte  menu_overlay_render
.L_lap_complete_status:
    .4byte  sym_0605A1C4
.L_fn_camera_attract:
    .4byte  camera_attract_init
.L_fn_car_iteration:
    .4byte  car_iteration_loop
.L_fn_car_proximity:
    .4byte  car_proximity_check
.L_fn_camera_system:
    .4byte  camera_system
.L_camera_eye_pos:
    .4byte  sym_06063E24
.L_camera_target_pos:
    .4byte  sym_06063EEC
.L_camera_up_vec:
    .4byte  sym_06063EF8
.L_fn_camera_orient:
    .4byte  camera_orient_calc
.L_fn_snd_race_update:
    .4byte  snd_race_update
.L_fn_scene_master:
    .4byte  scene_master
.L_extended_display_flag:
    .4byte  sym_0607ED8C
.L_fn_extended_display:
    .4byte  sym_060033E6
.L_minimap_enable_flag:
    .4byte  sym_06086030
.L_minimap_data_ptr:
    .4byte  sym_0605A1C8
.L_mask_nibble3:
    .4byte  0x0000F000
.L_fn_minimap_render:
    .4byte  sym_060283E0
.L_player_car_ptr_2:
    .4byte  sym_0607E944
.L_fn_frame_end_commit:
    .4byte  frame_end_commit
