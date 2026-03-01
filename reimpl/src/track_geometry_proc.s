
    .section .text.FUN_06017814


    .global track_geometry_proc
    .type track_geometry_proc, @function
track_geometry_proc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_track_counter_x, r8
    mov.l   .L_track_counter_y, r9
    mov.l   .L_track_counter_z, r10
    mov.l   .L_track_state_idx, r12
    mov.l   .L_track_counter_ry, r13
    mov.l   .L_track_counter_rz, r14
    mov.l   .L_fn_frame_sync, r3
    jsr @r3
    mov #0x0, r11
    mov.w   .L_timer_decrement, r2
    mov.l   .L_y_rot_timer, r3
    mov.l @r3, r3
    sub r2, r3
    mov.l   .L_y_rot_timer, r2
    mov.l r3, @r2
    mov.l   .L_track_pos_z, r6
    mov.l   .L_track_pos_y, r5
    mov.l   .L_track_pos_x, r4
    mov.l   .L_fn_pos_setup, r3
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_y_rot_timer, r4
    mov.l   .L_fn_mat_rot_y, r3
    jsr @r3
    mov.l @r4, r4
    mov #0x8, r5
    mov.l   .L_wram_low, r2
    mov.l   .L_wram_buf_y_rot, r3
    mov r2, r4
    add r3, r4
    mov.l   .L_fn_buffer_init, r3
    jsr @r3
    mov.l r2, @r15
    mov #0x6, r6
    mov.l @r15, r2
    mov.l   .L_wram_buf_y_load, r3
    add r3, r2
    mov.l r2, @r15
    mov.l   .L_geom_count, r5
    mov.l   .L_fn_buffer_load, r3
    mov.w @r5, r5
    jsr @r3
    mov r2, r4
    mov.l   .L_fn_buffer_finalize, r3
    jsr @r3
    nop
    mov.l   .L_fn_frame_sync, r3
    jsr @r3
    nop
    mov.w @r8, r0
    extu.w r0, r0
    cmp/eq #0xA, r0
    bf      .L_no_reset
    extu.w r11, r2
    mov.w r2, @r8
    mov.w   DAT_060178ac, r3
    mov.l   .L_z_rot_timer, r2
    mov.l @r2, r2
    sub r3, r2
    mov.l   .L_z_rot_timer, r3
    mov.l r2, @r3
    bra     .L_z_rot_phase
    nop
.L_timer_decrement:
    .2byte  0x0333

    .global DAT_060178ac
DAT_060178ac:
    .2byte  0x1CCB
    .2byte  0xFFFF
.L_track_counter_x:
    .4byte  sym_0605BE18
.L_track_counter_y:
    .4byte  sym_0605BE24
.L_track_counter_z:
    .4byte  sym_0605BE1A
.L_track_state_idx:
    .4byte  sym_0605BE26
.L_track_counter_ry:
    .4byte  sym_0605BE22
.L_track_counter_rz:
    .4byte  sym_0605BE20
.L_fn_frame_sync:
    .4byte  sym_06026DBC
.L_y_rot_timer:
    .4byte  sym_06085FAC
.L_track_pos_z:
    .4byte  sym_06048130
.L_track_pos_y:
    .4byte  sym_0604812C
.L_track_pos_x:
    .4byte  sym_06048128
.L_fn_pos_setup:
    .4byte  sym_06026E2E
.L_fn_mat_rot_y:
    .4byte  mat_rot_y
.L_wram_low:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_wram_buf_y_rot:
    .4byte  0x00037D88
.L_fn_buffer_init:
    .4byte  sym_06031D8C
.L_wram_buf_y_load:
    .4byte  0x00037DE8
.L_geom_count:
    .4byte  sym_06089E98
.L_fn_buffer_load:
    .4byte  sym_06031A28
.L_fn_buffer_finalize:
    .4byte  sym_06026DF8
.L_z_rot_timer:
    .4byte  sym_06085FBC
.L_no_reset:
    mov.w   .L_z_timer_step, r2
    mov.l   .L_z_rot_timer_2, r3
    mov.l @r3, r3
    add r2, r3
    mov.l   .L_z_rot_timer_2, r2
    mov.l r3, @r2
.L_z_rot_phase:
    mov.l   .L_track_rot_z, r6
    mov.l   .L_track_rot_y, r5
    mov.l   .L_track_rot_x, r4
    mov.l   .L_fn_pos_setup_2, r3
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_z_rot_timer_2, r4
    mov.l   .L_fn_mat_rot_z, r3
    jsr @r3
    mov.l @r4, r4
    mov #0x4, r5
    mov.l   .L_wram_low_2, r2
    mov.l   .L_wram_buf_z_rot, r3
    mov r2, r4
    add r3, r4
    mov.l   .L_fn_buffer_init_2, r3
    jsr @r3
    mov.l r2, @r15
    mov #0x1, r6
    mov.l   .L_geom_count_2, r5
    mov.l @r15, r4
    mov.l   .L_wram_buf_z_load, r2
    mov.l   .L_fn_buffer_load_2, r3
    mov.w @r5, r5
    jsr @r3
    add r2, r4
    mov.l   .L_fn_buffer_final_2, r3
    jsr @r3
    nop
    mov.w @r8, r2
    mov.l   .L_fn_frame_sync_2, r3
    add #0x1, r2
    jsr @r3
    mov.w r2, @r8
    mov #0x4, r5
    mov.l @r15, r4
    mov.l   .L_wram_buf_extra, r2
    mov.l   .L_fn_buffer_init_2, r3
    jsr @r3
    add r2, r4
    mov #0x1, r6
    mov.w @r8, r0
    mov.l   .L_anim_count_table, r3
    mov.l @r15, r4
    mov.l   .L_wram_buf_anim, r2
    extu.w r0, r0
    add r2, r4
    and #0x4, r0
    mov.l   .L_fn_buffer_load_2, r2
    shar r0
    shar r0
    mov r0, r5
    add #0x2A, r5
    shll r5
    add r3, r5
    jsr @r2
    mov.w @r5, r5
    mov.l   .L_fn_buffer_final_2, r3
    jsr @r3
    nop
    mov.l   .L_race_progress, r2
    mov.l   .L_lap_count, r3
    mov.w   .L_progress_offset, r0
    mov.l @r2, r2
    mov.l @r3, r3
    mov.l @(r0, r2), r2
    add #-0x1, r3
    cmp/hs r3, r2
    bf      .L_check_abort
    mov #0x2, r2
    bra     .L_post_state_check
    mov.w r2, @r10
.L_check_abort:
    mov.l   .L_abort_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_set_state_1
    extu.w r11, r3
    mov.w r3, @r10
    bra     .L_post_state_check
    nop
.L_z_timer_step:
    .2byte  0x0333
.L_progress_offset:
    .2byte  0x021C
    .2byte  0xFFFF
.L_z_rot_timer_2:
    .4byte  sym_06085FBC
.L_track_rot_z:
    .4byte  sym_0604813C
.L_track_rot_y:
    .4byte  sym_06048138
.L_track_rot_x:
    .4byte  sym_06048134
.L_fn_pos_setup_2:
    .4byte  sym_06026E2E
.L_fn_mat_rot_z:
    .4byte  mat_rot_z
.L_wram_low_2:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_wram_buf_z_rot:
    .4byte  0x00037E78
.L_fn_buffer_init_2:
    .4byte  sym_06031D8C
.L_geom_count_2:
    .4byte  sym_06089E98
.L_wram_buf_z_load:
    .4byte  0x00037EA8
.L_fn_buffer_load_2:
    .4byte  sym_06031A28
.L_fn_buffer_final_2:
    .4byte  sym_06026DF8
.L_fn_frame_sync_2:
    .4byte  sym_06026DBC
.L_wram_buf_extra:
    .4byte  0x00037EC0
.L_anim_count_table:
    .4byte  sym_06089E44
.L_wram_buf_anim:
    .4byte  0x00037EF0
.L_race_progress:
    .4byte  sym_0607E940
.L_lap_count:
    .4byte  sym_06063F28
.L_abort_flag:
    .4byte  sym_06078636
.L_set_state_1:
    mov #0x1, r2
    mov.w r2, @r10
.L_post_state_check:
    mov.l   .L_fn_frame_sync_3, r3
    jsr @r3
    nop
    mov.w @r10, r5
    extu.w r5, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_geom_table_a, r3
    mov.l @r15, r4
    mov.l   .L_geom_table_b, r2
    mov.l   .L_fn_buffer_init_3, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.w @r10, r6
    extu.w r6, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_geom_table_c, r3
    mov.l   .L_geom_count_3, r5
    mov.l @r15, r4
    mov.l   .L_geom_table_d, r2
    mov.l   .L_fn_buffer_load_3, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    jsr @r1
    mov.l @r4, r4
    mov.l   .L_fn_buffer_final_3, r3
    jsr @r3
    nop
    mov.l   .L_input_active_flag, r4
    mov.l   .L_attract_mode_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_reset_all_flags
    mov.l   .L_game_mode, r3
    mov.l   .L_mode_mask, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_reset_all_flags
    mov.l   .L_button_state, r5
    mov.w @r5, r5
    extu.w r5, r0
    tst #0x40, r0
    bt      .L_clear_input
    mov.w @r4, r0
    tst r0, r0
    bf      .L_to_state_dispatch
    mov #0x1, r3
    mov.w r3, @r4
    mov.w @r12, r2
    add #0x1, r2
    mov.w r2, @r12
    mov.w @r12, r0
    and #0x3, r0
    bra     .L_to_state_dispatch
    mov.w r0, @r12
.L_clear_input:
    exts.w r11, r2
    bra     .L_to_state_dispatch
    mov.w r2, @r4
.L_reset_all_flags:
    exts.w r11, r2
    mov.l   .L_sound_trigger_flag, r3
    mov.w r2, @r3
    exts.w r11, r1
    mov.w r1, @r12
    exts.w r11, r3
    mov.w r3, @r4
.L_to_state_dispatch:
    bra     .L_state_dispatch
    mov.w @r12, r0
.L_state_0:
    mov.w @r9, r2
    add #-0x1, r2
    mov.w r2, @r9
    mov.w @r13, r3
    add #-0x2, r3
    mov.w r3, @r13
    bra     .L_dec_rz_counter
    nop
.L_state_3:
    mov.l   .L_counter_rz_ptr, r4
    bsr     track_state_handler
    nop
    mov.l   .L_sound_trigger_flag, r0
    mov.w @r0, r0
    tst r0, r0
    bf      .L_clamp_counters
    bsr     .L_sound_trigger_check
    nop
    bra     .L_clamp_counters
    nop
    .2byte  0xFFFF
.L_fn_frame_sync_3:
    .4byte  sym_06026DBC
.L_geom_table_a:
    .4byte  sym_060622B4
.L_geom_table_b:
    .4byte  sym_06062290
.L_fn_buffer_init_3:
    .4byte  sym_06031D8C
.L_geom_table_c:
    .4byte  sym_060622A8
.L_geom_count_3:
    .4byte  sym_06089E98
.L_geom_table_d:
    .4byte  sym_0606229C
.L_fn_buffer_load_3:
    .4byte  sym_06031A28
.L_fn_buffer_final_3:
    .4byte  sym_06026DF8
.L_input_active_flag:
    .4byte  sym_0605BE2A
.L_attract_mode_flag:
    .4byte  sym_0607EAD0
.L_game_mode:
    .4byte  sym_0607EBC4
.L_mode_mask:
    .4byte  0x000A0000
.L_button_state:
    .4byte  g_pad_state
.L_sound_trigger_flag:
    .4byte  sym_0605BE28
.L_counter_rz_ptr:
    .4byte  sym_0605BE20
.L_state_2:
    mov.l   .L_counter_ry_ptr, r4
    bsr     track_state_handler
    nop
    mov.l   .L_sound_done_flag, r2
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_dec_rz_counter
    bsr     .L_counter_match_sound
    nop
.L_dec_rz_counter:
    mov.w @r14, r2
    add #-0x3, r2
    bra     .L_clamp_counters
    mov.w r2, @r14
.L_state_1:
    mov.l   .L_counter_y_ptr, r4
    bsr     track_state_handler
    nop
    mov.w @r13, r2
    add #-0x2, r2
    mov.w r2, @r13
    mov.w @r14, r3
    add #-0x3, r3
    mov.w r3, @r14
    bra     .L_clamp_counters
    nop
.L_state_dispatch:
    cmp/eq #0x0, r0
    bt      .L_state_0
    cmp/eq #0x1, r0
    bt      .L_state_1
    cmp/eq #0x2, r0
    bt      .L_state_2
    cmp/eq #0x3, r0
    bt      .L_state_3
.L_clamp_counters:
    mov.w @r9, r2
    cmp/pl r2
    bt      .L_clamp_rz
    mov #0x30, r2
    mov.w r2, @r9
.L_clamp_rz:
    mov.w @r14, r3
    cmp/pl r3
    bt      .L_clamp_ry
    mov #0x30, r3
    mov.w r3, @r14
.L_clamp_ry:
    mov.w @r13, r2
    cmp/pl r2
    bt      .L_output_compute
    mov #0x30, r2
    mov.w r2, @r13
.L_output_compute:
    mov.l   .L_geom_base_addr, r6
    mov.l   .L_offset_table, r5
    mov.l   .L_output_table, r4
    mov.w   DAT_06017bd4, r0
    mov.w @r9, r2
    mov.w @(r0, r5), r3
    mov r2, r1
    extu.w r3, r3
    mov.l @r6, r0
    shll r2
    shll2 r3
    add r1, r2
    shll r3
    add r0, r2
    add r4, r3
    mov.l r2, @r3
    mov.w   DAT_06017bd6, r0
    mov.w @r13, r2
    mov.w @(r0, r5), r3
    mov r2, r1
    extu.w r3, r3
    shll2 r3
    shll r3
    add r4, r3
    shll r2
    add r1, r2
    mov.l @r6, r0
    add r0, r2
    mov.l r2, @r3
    mov.w   DAT_06017bd8, r0
    mov.w @(r0, r5), r3
    extu.w r3, r3
    mov.w @r14, r2
    mov.l @r6, r0
    shll2 r3
    mov r2, r1
    shll r3
    shll r2
    add r4, r3
    add r1, r2
    add r0, r2
    mov.l r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06017bd4
DAT_06017bd4:
    .2byte  0x151A

    .global DAT_06017bd6
DAT_06017bd6:
    .2byte  0x151C

    .global DAT_06017bd8
DAT_06017bd8:
    .2byte  0x151E
    .2byte  0xFFFF
.L_counter_ry_ptr:
    .4byte  sym_0605BE22
.L_sound_done_flag:
    .4byte  sym_06085FCC
.L_counter_y_ptr:
    .4byte  sym_0605BE24
.L_geom_base_addr:
    .4byte  sym_0606A4F0
.L_offset_table:
    .4byte  sym_060684EC
.L_output_table:
    .4byte  sym_06063F64
.L_sound_trigger_check:
    mov.l   .L_game_mode_2, r3
    mov.l   .L_fp_two, r2
    mov.l @r3, r3
    cmp/eq r2, r3
    bt      .L_mode_is_2
    rts
    nop
.L_mode_is_2:
    mov.l   .L_counter_y_val, r5
    mov.l   .L_counter_ry_val, r2
    mov.w @r5, r4
    mov.w @r2, r2
    cmp/eq r2, r4
    bf      .L_snd_check_done
    mov.l   .L_counter_rz_val, r2
    mov.w @r2, r2
    cmp/eq r2, r4
    bf      .L_snd_check_done
    mov.l   .L_snd_trigger_ptr, r7
    mov.l   .L_geom_accum, r4
    mov.w @r5, r0
    cmp/eq #0x2A, r0
    bf/s    .L_check_thresh_12
    mov #0x1, r6
    mov.w   DAT_06017c52, r2
    mov.l @r4, r3
    add r2, r3
    mov.l r3, @r4
    exts.w r6, r6
    mov.w r6, @r7
    mov.l   .L_snd_cmd_17, r5
    mov.l   .L_fn_sound_dispatch, r3
    jmp @r3
    mov #0x0, r4
.L_check_thresh_12:
    mov.w @r5, r0
    cmp/eq #0x12, r0
    bf      .L_snd_check_done
    mov.l @r4, r2
    add #0x64, r2
    mov.l r2, @r4
    exts.w r6, r6
    mov.w r6, @r7
    mov.l   .L_snd_cmd_17, r5
    mov.l   .L_fn_sound_dispatch, r3
    jmp @r3
    mov #0x0, r4
.L_snd_check_done:
    rts
    nop

    .global DAT_06017c52
DAT_06017c52:
    .2byte  0x008C
.L_game_mode_2:
    .4byte  sym_0607EBC4
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_counter_y_val:
    .4byte  sym_0605BE24
.L_counter_ry_val:
    .4byte  sym_0605BE22
.L_counter_rz_val:
    .4byte  sym_0605BE20
.L_snd_trigger_ptr:
    .4byte  sym_0605BE28
.L_geom_accum:
    .4byte  sym_0607EAAC
.L_snd_cmd_17:
    .4byte  0xAE1117FF
.L_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch
.L_counter_match_sound:
    mov.l   .L_counter_y_chk, r4
    mov.l   .L_counter_ry_chk, r2
    mov.w @r4, r3
    mov.w @r2, r2
    cmp/eq r2, r3
    bf      .L_no_match
    mov.w @r4, r0
    cmp/eq #0x2A, r0
    bf      .L_no_match
    mov #0x1, r2
    mov.l   .L_snd_done_byte, r3
    mov.b r2, @r3
    mov.l   .L_snd_cmd_18, r5
    mov.l   .L_fn_sound_dispatch_2, r3
    jmp @r3
    mov #0x0, r4
.L_no_match:
    rts
    nop

    .global track_state_handler
    .type track_state_handler, @function
track_state_handler:
    sts.l pr, @-r15
    mov.w @r4, r1
    mov.l   .L_fn_div, r3
    extu.w r1, r1
    jsr @r3
    mov #0x6, r0
    extu.w r0, r5
    mov #0x4, r3
    cmp/ge r3, r5
    bt      .L_div_large
    mov.w @r4, r3
    extu.w r3, r3
    extu.w r5, r5
    sub r5, r3
    extu.w r3, r3
    mov.w r3, @r4
    bra     .L_div_done
    nop
.L_div_large:
    mov.w @r4, r2
    extu.w r2, r2
    extu.w r5, r5
    sub r5, r2
    add #0x6, r2
    extu.w r2, r2
    mov.w r2, @r4
.L_div_done:
    lds.l @r15+, pr
    rts
    nop
.L_counter_y_chk:
    .4byte  sym_0605BE24
.L_counter_ry_chk:
    .4byte  sym_0605BE22
.L_snd_done_byte:
    .4byte  sym_06085FCC
.L_snd_cmd_18:
    .4byte  0xAE1118FF
.L_fn_sound_dispatch_2:
    .4byte  sound_cmd_dispatch
.L_fn_div:
    .4byte  sym_06035C2C
