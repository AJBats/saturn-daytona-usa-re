
    .section .text.FUN_06009788


    .global state_time_extend_active
    .type state_time_extend_active, @function
state_time_extend_active:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_mask_nibble3, r8
    mov.l   .L_render_flags, r10
    mov.l   .L_special_render_flag, r11
    mov.l   .L_time_value_byte, r12
    mov.l   .L_input_data, r4
    mov.w @(2, r4), r0
    mov r0, r3
    mov.w r3, @r15
    mov.w @r4, r3
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_overlay_active, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_skip_overlay
    mov.l   .L_fn_menu_overlay, r3
    jsr @r3
    mov #0x0, r4
.L_skip_overlay:
    mov.l   .L_extend_mode_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_setup_persistent
    mov.w @r15, r3
    mov.l   .L_btn_up_mask, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_check_down
    mov #0x63, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_display_time_value
    mov.b @r12, r2
    add #0x1, r2
    bra     .L_display_time_value
    mov.b r2, @r12
.L_mask_nibble3:
    .4byte  0x0000F000                  /* nibble 3 mask */
.L_render_flags:
    .4byte  sym_0605B6D8               /* render mode flags (32-bit) */
.L_special_render_flag:
    .4byte  sym_0607ED8C               /* special render enable (16-bit) */
.L_time_value_byte:
    .4byte  sym_06078649               /* time extend value (byte, 0-99) */
.L_input_data:
    .4byte  g_pad_state               /* input data (pressed + held) */
.L_overlay_active:
    .4byte  sym_0605AB18               /* overlay active flag (byte) */
.L_fn_menu_overlay:
    .4byte  menu_overlay_render        /* menu overlay render function */
.L_extend_mode_flag:
    .4byte  sym_0607864A               /* time extend mode flag (byte) */
.L_btn_up_mask:
    .4byte  0x00008000                  /* Up button mask */
.L_check_down:
    mov.w @r15, r2
    mov.w   .L_btn_down_mask, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_display_time_value
    mov #0x1, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/gt r2, r3
    bf      .L_display_time_value
    mov.b @r12, r2
    add #-0x1, r2
    mov.b r2, @r12
.L_display_time_value:
    mov.b @r12, r7
    mov r8, r6
    mov.w   .L_hud_sprite_a, r5
    mov.l   .L_fn_hud_number, r3
    extu.b r7, r7
    jsr @r3
    mov #0x8, r4
    mov r8, r6
    mov.w   .L_hud_sprite_b, r5
    mov.l   .L_extend_gfx_data_a, r7
    mov.l   .L_fn_geom_dispatch, r3
    jsr @r3
    mov #0x8, r4
.L_setup_persistent:
    mov.w   .L_hud_coord_a, r9
    mov.w   .L_hud_coord_b, r13
    mov.l   .L_fn_geom_render, r14
    mov.w @r15, r2
    mov.w   .L_btn_start_mask, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_check_end_extend
    mov #0x14, r2
    mov.l   .L_extend_timer, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/ge r2, r3
    bf      .L_check_end_extend
    mov.l   .L_extend_trigger, r0
    mov.b @r0, r0
    cmp/eq #0x1, r0
    bt      .L_check_end_extend
    mov.l   .L_snd_cmd_extend, r5
    mov.l   .L_fn_sound_dispatch, r3
    jsr @r3
    mov #0x0, r4
    mov r13, r6
    mov.l   .L_extend_text_data, r2
    mov.l r2, @r15
    mov r2, r7
    mov.w   .L_text_sprite_a, r5
    add #0x3B, r7
    jsr @r14
    mov #0x8, r4
    mov r13, r6
    mov r9, r5
    mov.l @r15, r7
    add #0x28, r7
    jsr @r14
    mov #0x8, r4
    mov r13, r6
    mov.w   .L_text_sprite_b, r5
    mov.l @r15, r7
    add #0x2E, r7
    jsr @r14
    mov #0x8, r4
    mov.l   .L_countdown_timer, r3
    mov.l   .L_game_state, r2
    mov.l @r3, r3
    mov.l r3, @r2
    mov.l   .L_extend_lap_byte, r3
    mov.l   .L_lap_count, r2
    mov.b @r3, r3
    mov.b r3, @r2
    mov.l   .L_extend_trigger, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_clear_trigger
    bra     .L_end_of_frame
    nop
.L_clear_trigger:
    mov #0x0, r3
    mov #0xF, r6
    mov.l   .L_extend_trigger, r2
    mov.b r3, @r2
    mov.b @r12, r5
    extu.b r5, r5
    mov.l r5, @r15
    mov.l   .L_fn_handler_dispatch, r3
    jsr @r3
    mov r5, r4
    mov.l   .L_extend_gfx_data_b, r7
    mov r8, r6
    mov.w   .L_hud_sprite_b, r5
    mov.l   .L_fn_geom_dispatch, r3
    jsr @r3
    mov #0x8, r4
    bra     .L_end_of_frame
    nop
.L_btn_down_mask:
    .2byte  0x4000                        /* Down button mask */
.L_hud_sprite_a:
    .2byte  0x0CCC                        /* HUD sprite parameter A */
.L_hud_sprite_b:
    .2byte  0x0CB8                        /* HUD sprite parameter B */
.L_hud_coord_a:
    .2byte  0x0694                        /* HUD coordinate A */
.L_hud_coord_b:
    .2byte  0x0090                        /* HUD coordinate B */
.L_btn_start_mask:
    .2byte  0x0800                        /* Start button mask */
.L_text_sprite_a:
    .2byte  0x0526                        /* text sprite parameter A */
.L_text_sprite_b:
    .2byte  0x079C                        /* text sprite parameter B */
.L_fn_hud_number:
    .4byte  hud_number_display         /* HUD number display function */
.L_extend_gfx_data_a:
    .4byte  sym_060446E0               /* time extend graphics data A */
.L_fn_geom_dispatch:
    .4byte  sym_060283E0               /* geometry render dispatch */
.L_fn_geom_render:
    .4byte  sym_060284AE               /* geometry element render */
.L_extend_timer:
    .4byte  sym_06078650               /* time extend timer (16-bit) */
.L_extend_trigger:
    .4byte  sym_0607864A               /* time extend trigger flag (byte) */
.L_snd_cmd_extend:
    .4byte  0xAE0004FF                  /* sound command: time extend */
.L_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch         /* sound command dispatcher */
.L_extend_text_data:
    .4byte  sym_0605AC9C               /* time extend text/sprite data */
.L_countdown_timer:
    .4byte  sym_0607EACC               /* countdown timer (32-bit) */
.L_game_state:
    .4byte  g_game_state               /* game state dispatch value */
.L_extend_lap_byte:
    .4byte  sym_06078652               /* extend mode lap byte */
.L_lap_count:
    .4byte  sym_06078654               /* current lap count */
.L_fn_handler_dispatch:
    .4byte  handler_dispatch           /* handler dispatch function */
.L_extend_gfx_data_b:
    .4byte  sym_060446EC               /* time extend graphics data B */
.L_check_end_extend:
    mov #0x70, r4
    mov.w @(4, r15), r0
    mov r0, r2
    extu.w r2, r2
    and r4, r2
    cmp/eq r4, r2
    bf      .L_normal_frame_render
    .byte   0xB4, 0x43    /* bsr 0x0600A1B8 (external: end extend helper) */
    nop
    mov.l   .L_fp_min, r2
    mov.l @r10, r3
    or r2, r3
    mov.l r3, @r10
    mov.w @r11, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_exit_no_special
    mov #0x1, r3
    mov.l   .L_race_event_flags, r2
    mov.l r3, @r2
    mov #0x2, r3
    mov #0x18, r2
    mov.w r3, @r11
    mov.l   .L_game_state_b, r3
    mov.l r2, @r3
    mov.l   .L_fn_camera_finalize, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_anim_state, r3
    mov.l r2, @r3
    bra     .L_end_of_frame
    nop
.L_exit_no_special:
    mov #0x1, r2
    mov.l   .L_game_sub_state, r3
    mov.l r2, @r3
    mov #0xE, r2
    mov.l   .L_game_state_b, r3
    mov.l r2, @r3
    bra     .L_end_of_frame
    nop
.L_normal_frame_render:
    mov.l   .L_extend_timer_b, r4
    mov.w @r4, r0
    add #0x1, r0
    mov.w r0, @r4
    extu.w r0, r0
    tst #0x10, r0
    bt      .L_flash_off_phase
    mov r13, r6
    mov r9, r5
    mov.l   .L_extend_text_data_b, r3
    mov.l r3, @r15
    mov r3, r7
    jsr @r14
    mov #0x8, r4
    mov.l @r15, r7
    mov r13, r6
    mov.w   .L_text_sprite_c, r5
    jsr @r14
    mov #0x8, r4
    bra     .L_end_of_frame
    nop
.L_flash_off_phase:
    mov.w @r11, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_normal_gfx_path
    mov r13, r6
    mov r9, r5
    mov.l   .L_extend_gfx_special, r7
    jsr @r14
    mov #0x8, r4
    mov.l   .L_extend_gfx_alt_a, r7
    bra     .L_render_second_gfx
    nop
.L_text_sprite_c:
    .2byte  0x0794                        /* text sprite parameter C */
    .2byte  0xFFFF
.L_fp_min:
    .4byte  0x80000000                  /* min negative / sign bit */
.L_race_event_flags:
    .4byte  sym_0607EBF4               /* race event bitfield (32-bit) */
.L_game_state_b:
    .4byte  g_game_state               /* game state dispatch value */
.L_fn_camera_finalize:
    .4byte  sym_06026CE0               /* camera state finalization */
.L_anim_state:
    .4byte  sym_06059F44               /* animation state (32-bit) */
.L_game_sub_state:
    .4byte  sym_0605AD08               /* game sub-state (32-bit) */
.L_extend_timer_b:
    .4byte  sym_06078650               /* time extend timer (16-bit) */
.L_extend_text_data_b:
    .4byte  sym_0605ACC4               /* extend text/sprite data */
.L_extend_gfx_special:
    .4byte  sym_060446FC               /* extend special graphics */
.L_extend_gfx_alt_a:
    .4byte  sym_06044718               /* extend alt graphics A */
.L_normal_gfx_path:
    mov.l   .L_extend_gfx_normal, r7
    mov r13, r6
    mov r9, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_extend_gfx_alt_b, r7
.L_render_second_gfx:
    mov r13, r6
    mov.w   .L_sprite_param_d, r5
    jsr @r14
    mov #0x8, r4
.L_end_of_frame:
    mov.w @r11, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_check_geom_render
    mov.l   .L_fn_special_render, r3
    jsr @r3
    nop
.L_check_geom_render:
    mov.l   .L_geom_render_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_camera_finalize
    mov r8, r6
    mov.w   .L_geom_tile_size, r5
    mov.l   .L_geom_data_ptr, r7
    mov.l   .L_fn_geom_dispatch_b, r3
    jsr @r3
    mov #0x8, r4
.L_camera_finalize:
    mov.l @r10, r0
    mov.l   .L_fn_camera_finalize_b, r3
    or #0x4, r0
    jsr @r3
    mov.l r0, @r10
    mov #0x0, r2
    mov.l   .L_anim_state_b, r3
    mov.l r2, @r3
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_sprite_param_d:
    .2byte  0x079C                        /* sprite parameter D */
.L_geom_tile_size:
    .2byte  0x0082                        /* geometry tile size parameter */
.L_extend_gfx_normal:
    .4byte  sym_060446FC               /* extend normal graphics */
.L_extend_gfx_alt_b:
    .4byte  sym_0604472C               /* extend alt graphics B */
.L_fn_special_render:
    .4byte  sym_060033E6               /* special render function */
.L_geom_render_flag:
    .4byte  sym_06086030               /* geometry render enable (byte) */
.L_geom_data_ptr:
    .4byte  sym_0605A1C8               /* geometry data pointer */
.L_fn_geom_dispatch_b:
    .4byte  sym_060283E0               /* geometry render dispatch */
.L_fn_camera_finalize_b:
    .4byte  sym_06026CE0               /* camera state finalization */
.L_anim_state_b:
    .4byte  sym_06059F44               /* animation state (32-bit) */
