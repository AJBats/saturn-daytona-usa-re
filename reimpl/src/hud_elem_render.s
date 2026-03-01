
    .section .text.FUN_0601503A


    .global hud_layout_mgr
    .type hud_layout_mgr, @function
hud_layout_mgr:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xD3, 0x0B    /* mov.l .L_disable_flag_a, r3 */
    mov.b @r3, r3
    tst r3, r3
    .word 0x0029
    .byte   0xD1, 0x0A    /* mov.l .L_disable_flag_b, r1 */
    mov.l @r1, r1
    tst r1, r1
    .word 0x0129
    or r1, r0
    .byte   0xD3, 0x09    /* mov.l .L_disable_flag_c, r3 */
    .byte   0xD1, 0x09    /* mov.l .L_disable_flag_d, r1 */
    mov.b @r3, r3
    mov.l @r1, r1
    or r3, r0
    tst r1, r1
    .word 0x0129
    or r1, r0
    tst r0, r0
    bt      .L_flags_clear
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    bra     race_data_dispatch
    mov.l @r15+, r14
.L_disable_flag_a:
    .4byte  sym_06085FF4
.L_disable_flag_b:
    .4byte  sym_0607EBF4
.L_disable_flag_c:
    .4byte  sym_06078635
.L_disable_flag_d:
    .4byte  sym_0607EAE0
.L_flags_clear:
    .byte   0xD2, 0x23    /* mov.l .L_frame_counter, r2 */
    mov.w   .L_threshold_frame_count, r3
    mov.l @r2, r2
    cmp/hs r3, r2
    bt/s    .L_above_threshold
    mov #0x0, r13
    .byte   0xD3, 0x21    /* mov.l .L_fn_channel_setup_a, r3 */
    jsr @r3
    mov #0xC, r4
    .byte   0xD3, 0x21    /* mov.l .L_fn_channel_setup_b, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x20    /* mov.l .L_fn_gameover_channel, r3 */
    jsr @r3
    nop
    mov #0x60, r6
    mov.w   .L_sprite_pos_a, r5
    .byte   0xDE, 0x1F    /* mov.l .L_fn_sprite_register, r14 */
    .byte   0xD7, 0x1F    /* mov.l .L_sprite_gfx_a, r7 */
    jsr @r14
    mov #0xC, r4
    mov #0x60, r6
    mov.w   .L_sprite_pos_b, r5
    .byte   0xD7, 0x1E    /* mov.l .L_sprite_gfx_b, r7 */
    jsr @r14
    mov #0xC, r4
    .byte   0xD7, 0x1D    /* mov.l .L_sprite_gfx_c, r7 */
    mov #0x60, r6
    mov.w   .L_sprite_pos_c, r5
    jsr @r14
    mov #0xC, r4
    .byte   0xD7, 0x1C    /* mov.l .L_sprite_gfx_d, r7 */
    mov.w   .L_sprite_size_small, r6
    mov.w   .L_sprite_pos_d, r5
    jsr @r14
    mov #0xC, r4
    mov.b @r15, r4
    .byte   0xD3, 0x1A    /* mov.l .L_fn_hud_config, r3 */
    jsr @r3
    extu.b r4, r4
    extu.b r13, r2
    .byte   0xD3, 0x19    /* mov.l .L_hud_counter, r3 */
    mov.b r2, @r3
    mov #0xE, r1
    .byte   0xD3, 0x18    /* mov.l .L_hud_anim_step, r3 */
    mov.b r1, @r3
    mov #0xA, r1
    .byte   0xD3, 0x18    /* mov.l .L_hud_config_byte, r3 */
    mov.b r1, @r3
    exts.b r13, r13
    .byte   0xD3, 0x17    /* mov.l .L_hud_anim_state, r3 */
    mov.b r13, @r3
    bra     .L_layout_return
    nop
.L_above_threshold:
    .byte   0xD3, 0x16    /* mov.l .L_race_display_ctrl, r3 */
    mov.w r13, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    bra     race_data_dispatch
    mov.l @r15+, r14
.L_layout_return:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_threshold_frame_count:
    .2byte  0x2A94
.L_sprite_pos_a:
    .2byte  0x0320
.L_sprite_pos_b:
    .2byte  0x051E
.L_sprite_pos_c:
    .2byte  0x0532
.L_sprite_size_small:
    .2byte  0x0090
.L_sprite_pos_d:
    .2byte  0x051C
.L_frame_counter:
    .4byte  sym_0607ED88
.L_fn_channel_setup_a:
    .4byte  sym_0602853E
.L_fn_channel_setup_b:
    .4byte  sym_06028560
.L_fn_gameover_channel:
    .4byte  gameover_channel_setup
.L_fn_sprite_register:
    .4byte  sym_060284AE
.L_sprite_gfx_a:
    .4byte  sym_06044C78
.L_sprite_gfx_b:
    .4byte  sym_06044C80
.L_sprite_gfx_c:
    .4byte  sym_06044C84
.L_sprite_gfx_d:
    .4byte  sym_06044C88
.L_fn_hud_config:
    .4byte  sym_060172E4
.L_hud_counter:
    .4byte  sym_06085F8C
.L_hud_anim_step:
    .4byte  sym_06085F8D
.L_hud_config_byte:
    .4byte  sym_06085F8E
.L_hud_anim_state:
    .4byte  sym_06085F8B
.L_race_display_ctrl:
    .4byte  sym_0607ED8C

    .global hud_elem_render
    .type hud_elem_render, @function
hud_elem_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x1, r10
    mov.l r9, @-r15
    sts.l pr, @-r15
    .byte   0xD9, 0x29    /* mov.l .L_hud_config_byte_r, r9 */
    .byte   0xDC, 0x2A    /* mov.l .L_game_status_flags, r12 */
    .byte   0xDE, 0x2A    /* mov.l .L_hud_anim_state_r, r14 */
    .byte   0xDB, 0x2B    /* mov.l .L_hud_anim_step_r, r11 */
    .byte   0xD2, 0x2B    /* mov.l .L_fp_half, r2 */
    mov.w @(2, r12), r0
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt/s    .L_check_flag_4000
    mov #0x0, r13
    .byte   0xD7, 0x28    /* mov.l .L_sprite_gfx_e, r7 */
    mov.w   .L_sprite_size_r, r6
    mov.b @r9, r5
    mov.b @r11, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    .byte   0xD3, 0x24    /* mov.l .L_fn_sprite_register_r, r3 */
    jsr @r3
    mov #0xC, r4
    mov.b r10, @r14
    mov #0x18, r3
    mov.b r3, @r11
    extu.b r13, r2
    .byte   0xD3, 0x21    /* mov.l .L_hud_counter_r, r3 */
    mov.b r2, @r3
    bra     .L_check_flag_0200
    nop
.L_check_flag_4000:
    mov.w @(2, r12), r0
    mov.w   .L_flag_0x4000, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_check_flag_0200
    .byte   0xD7, 0x1A    /* mov.l .L_sprite_gfx_e, r7 */
    mov.w   .L_sprite_size_r, r6
    mov.b @r9, r5
    mov.b @r11, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    .byte   0xD3, 0x15    /* mov.l .L_fn_sprite_register_r, r3 */
    jsr @r3
    mov #0xC, r4
    mov #0xE, r2
    mov.b r2, @r11
    exts.b r13, r3
    mov.b r3, @r14
    extu.b r13, r2
    .byte   0xD3, 0x12    /* mov.l .L_hud_counter_r, r3 */
    mov.b r2, @r3
.L_check_flag_0200:
    mov.w @(2, r12), r0
    mov.w   .L_flag_0x0200, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_check_flag_0100
    mov.b @r9, r0
    extu.b r0, r0
    cmp/eq #0xC, r0
    bf      .L_after_config_inc
    mov.b @r14, r2
    add #0x2, r2
    mov.b r2, @r14
.L_after_config_inc:
    mov.b @r14, r0
    cmp/eq #0x1, r0
    bf      .L_state_dispatch
    bra     .L_disable_display
    nop
.L_sprite_size_r:
    .2byte  0x0090
.L_flag_0x4000:
    .2byte  0x4000
.L_flag_0x0200:
    .2byte  0x0200
.L_hud_config_byte_r:
    .4byte  sym_06085F8E
.L_game_status_flags:
    .4byte  g_pad_state
.L_hud_anim_state_r:
    .4byte  sym_06085F8B
.L_hud_anim_step_r:
    .4byte  sym_06085F8D
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_sprite_gfx_e:
    .4byte  sym_06044C8C
.L_fn_sprite_register_r:
    .4byte  sym_060284AE
.L_hud_counter_r:
    .4byte  sym_06085F8C
.L_state_dispatch:
    mov.b @r14, r2
    tst r2, r2
    bf      .L_check_state_2
    .byte   0xD2, 0x29    /* mov.l .L_race_display_ctrl_r, r2 */
    mov #0x8, r0
    mov.w r10, @r2
    .byte   0xD2, 0x28    /* mov.l .L_render_flag_a, r2 */
    mov.l r10, @r2
    .byte   0xD2, 0x28    /* mov.l .L_pause_display_flag, r2 */
    mov.w r10, @r2
    .byte   0xD2, 0x28    /* mov.l .L_frame_counter_r, r2 */
    mov.l r0, @r2
    bsr     race_data_dispatch
    nop
    mov #0xE, r3
    .byte   0xD2, 0x27    /* mov.l .L_render_mode, r2 */
    mov.l r3, @r2
    bra     .L_state_done
    nop
.L_check_state_2:
    mov.b @r14, r0
    cmp/eq #0x2, r0
    bf      .L_check_state_3
    .byte   0xD3, 0x24    /* mov.l .L_fn_geom_render_util, r3 */
    jsr @r3
    nop
    bra     .L_state_done
    nop
.L_check_state_3:
    mov.b @r14, r0
    cmp/eq #0x3, r0
    bf      .L_state_done
    .byte   0xD3, 0x21    /* mov.l .L_fn_geom_output_finalize, r3 */
    jsr @r3
    nop
.L_state_done:
    bra     .L_render_epilogue
    nop
.L_check_flag_0100:
    mov.w @(2, r12), r0
    mov.w   .L_flag_0x0100, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_render_epilogue
.L_disable_display:
    .byte   0xD2, 0x15    /* mov.l .L_race_display_ctrl_r, r2 */
    mov #0x8, r1
    mov.w r13, @r2
    .byte   0xD2, 0x16    /* mov.l .L_pause_display_flag, r2 */
    mov.w r13, @r2
    .byte   0xD2, 0x16    /* mov.l .L_frame_counter_r, r2 */
    mov.l r1, @r2
    bsr     race_data_dispatch
    nop
.L_render_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     .L_anim_counter_tick
    mov.l @r15+, r14
.L_anim_counter_tick:
    .byte   0xD4, 0x14    /* mov.l .L_hud_counter_anim, r4 */
    mov.b @r4, r3
    add #0x40, r3
    mov.b r3, @r4
    mov.b @r4, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_counter_nonzero
    .byte   0xD7, 0x11    /* mov.l .L_sprite_gfx_e_alt, r7 */
    mov.w   .L_sprite_size_anim, r6
    .byte   0xD5, 0x11    /* mov.l .L_hud_config_byte_a, r5 */
    .byte   0xD3, 0x11    /* mov.l .L_hud_anim_step_a, r3 */
    mov.b @r5, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    .byte   0xD3, 0x0D    /* mov.l .L_fn_sprite_register_a, r3 */
    jmp @r3
    mov #0xC, r4
.L_flag_0x0100:
    .2byte  0x0100
.L_sprite_size_anim:
    .2byte  0x0090
    .2byte  0xFFFF
.L_race_display_ctrl_r:
    .4byte  sym_0607ED8C
.L_render_flag_a:
    .4byte  sym_0605AD08
.L_pause_display_flag:
    .4byte  sym_06085F92
.L_frame_counter_r:
    .4byte  sym_0607ED88
.L_render_mode:
    .4byte  g_game_state
.L_fn_geom_render_util:
    .4byte  geom_render_util
.L_fn_geom_output_finalize:
    .4byte  geom_output_finalize
.L_hud_counter_anim:
    .4byte  sym_06085F8C
.L_sprite_gfx_e_alt:
    .4byte  sym_06044C8C
.L_hud_config_byte_a:
    .4byte  sym_06085F8E
.L_hud_anim_step_a:
    .4byte  sym_06085F8D
.L_fn_sprite_register_a:
    .4byte  sym_060284AE
.L_counter_nonzero:
    .byte   0xD7, 0x08    /* mov.l .L_sprite_gfx_d_alt, r7 */
    mov.w   .L_sprite_size_alt, r6
    .byte   0xD5, 0x08    /* mov.l .L_hud_config_byte_b, r5 */
    .byte   0xD3, 0x09    /* mov.l .L_hud_anim_step_b, r3 */
    mov.b @r5, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    .byte   0xD3, 0x05    /* mov.l .L_fn_sprite_register_b, r3 */
    jmp @r3
    mov #0xC, r4
.L_sprite_size_alt:
    .2byte  0x0090
    .2byte  0xFFFF
.L_sprite_gfx_d_alt:
    .4byte  sym_06044C88
.L_hud_config_byte_b:
    .4byte  sym_06085F8E
.L_hud_anim_step_b:
    .4byte  sym_06085F8D
.L_fn_sprite_register_b:
    .4byte  sym_060284AE

    .global race_data_dispatch
    .type race_data_dispatch, @function
race_data_dispatch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.w   .L_channel_id_0x100, r12
    .byte   0xDE, 0x36    /* mov.l .L_fn_channel_nibble_config, r14 */
    .byte   0xD3, 0x36    /* mov.l .L_fn_handler_init_reset, r3 */
    jsr @r3
    mov #0x0, r13
    mov r13, r5
    jsr @r14
    mov r12, r4
    .byte   0xD3, 0x34    /* mov.l .L_hud_state_byte, r3 */
    mov #0x1E, r1
    mov.b r13, @r3
    .byte   0xD3, 0x34    /* mov.l .L_render_mode_d, r3 */
    mov.l r1, @r3
    .byte   0xD3, 0x34    /* mov.l .L_fn_vblank_helper, r3 */
    jsr @r3
    nop
    .byte   0xD2, 0x33    /* mov.l .L_pause_flag_a, r2 */
    .byte   0xD3, 0x34    /* mov.l .L_pause_flag_b, r3 */
    mov.b @r2, r2
    mov.b @r3, r3
    extu.b r2, r2
    extu.b r3, r3
    or r3, r2
    tst r2, r2
    bt      .L_after_pause_check
    .byte   0xD3, 0x31    /* mov.l .L_pause_display_flag_d, r3 */
    mov.w @r3, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_set_pause_mode
    .byte   0xD3, 0x2F    /* mov.l .L_fn_course_config_render, r3 */
    jsr @r3
    nop
.L_set_pause_mode:
    mov #0x1A, r2
    .byte   0xD3, 0x28    /* mov.l .L_render_mode_d, r3 */
    mov.l r2, @r3
.L_after_pause_check:
    .byte   0xD3, 0x2D    /* mov.l .L_fn_vdp2_loop_ctrl, r3 */
    jsr @r3
    nop
    mov #0x0, r5
    jsr @r14
    mov r12, r4
    mov #0x1, r5
    jsr @r14
    mov #0x4, r4
    mov #0x6, r5
    jsr @r14
    mov #0x10, r4
    .byte   0xD3, 0x28    /* mov.l .L_fn_display_sync, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x28    /* mov.l .L_obj_clear_word, r3 */
    mov.l r13, @r3
    .byte   0xD3, 0x28    /* mov.l .L_fn_obj_dispatch, r3 */
    jsr @r3
    nop
    mov #0x3, r2
    .byte   0xD3, 0x27    /* mov.l .L_obj_mode_word, r3 */
    mov.w r2, @r3
    .byte   0xD3, 0x27    /* mov.l .L_fn_obj_data_compact, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x26    /* mov.l .L_fn_frame_end_commit, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x24    /* mov.l .L_fn_obj_data_compact, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x23    /* mov.l .L_fn_frame_end_commit, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x23    /* mov.l .L_fn_channel_setup_d, r3 */
    jsr @r3
    mov #0x4, r4
    .byte   0xD3, 0x21    /* mov.l .L_fn_channel_setup_d, r3 */
    jsr @r3
    mov #0xC, r4
    .byte   0xD3, 0x21    /* mov.l .L_fn_channel_setup_e, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x20    /* mov.l .L_fn_gameover_channel_d, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x20    /* mov.l .L_display_flags_word, r4 */
    mov.l @r4, r0
    or #0x4, r0
    mov.l r0, @r4
    .byte   0xD3, 0x16    /* mov.l .L_obj_clear_word, r3 */
    mov.l r13, @r3
    .byte   0xD3, 0x16    /* mov.l .L_fn_obj_dispatch, r3 */
    jsr @r3
    nop
    mov #0x4, r5
    jsr @r14
    mov r12, r4
    mov #0x0, r5
    jsr @r14
    mov #0x4, r4
    .byte   0xD2, 0x19    /* mov.l .L_jump_table_index, r2 */
    mov.l @r2, r2
    shll2 r2
    .byte   0xD3, 0x19    /* mov.l .L_jump_table_base, r3 */
    add r3, r2
    mov.l @r2, r2
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    jmp @r2
    mov.l @r15+, r14
.L_channel_id_0x100:
    .2byte  0x0100
.L_fn_channel_nibble_config:
    .4byte  channel_nibble_config
.L_fn_handler_init_reset:
    .4byte  handler_init_reset
.L_hud_state_byte:
    .4byte  sym_06085F8A
.L_render_mode_d:
    .4byte  g_game_state
.L_fn_vblank_helper:
    .4byte  sym_0601ABC6
.L_pause_flag_a:
    .4byte  sym_06085FF8
.L_pause_flag_b:
    .4byte  sym_06085FF9
.L_pause_display_flag_d:
    .4byte  sym_06085F92
.L_fn_course_config_render:
    .4byte  course_config_render
.L_fn_vdp2_loop_ctrl:
    .4byte  vdp2_loop_ctrl
.L_fn_display_sync:
    .4byte  sym_060149E0
.L_obj_clear_word:
    .4byte  sym_0605A00C
.L_fn_obj_dispatch:
    .4byte  sym_06026CE0
.L_obj_mode_word:
    .4byte  sym_0605A016
.L_fn_obj_data_compact:
    .4byte  obj_data_compact
.L_fn_frame_end_commit:
    .4byte  frame_end_commit
.L_fn_channel_setup_d:
    .4byte  sym_0602853E
.L_fn_channel_setup_e:
    .4byte  sym_06028560
.L_fn_gameover_channel_d:
    .4byte  gameover_channel_setup
.L_display_flags_word:
    .4byte  sym_0605B6D8
.L_jump_table_index:
    .4byte  sym_0607EAD8
.L_jump_table_base:
    .4byte  sym_0605B724

    .global loc_06015474
loc_06015474:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r4
    extu.b r4, r4
    .byte   0xD3, 0x1A    /* mov.l .L_fn_thunk_target, r3 */
    jmp @r3
    add #0x4, r15
