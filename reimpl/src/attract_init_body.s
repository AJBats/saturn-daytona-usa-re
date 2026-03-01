
    .section .text.FUN_0600893C


    .global attract_init_body
    .type attract_init_body, @function
attract_init_body:
    sts.l pr, @-r15
    mov #0x0, r14
    mov.l   .L_course_select_byte, r2
    extu.b r14, r0
    mov.b r3, @r2
    mov.l   .L_demo_flag_a, r2
    mov.b r14, @r2
    mov.l   .L_special_render_flag, r2
    mov.w r14, @r2
    mov.l   .L_demo_flag_b, r2
    mov.l   .L_fn_vdp2_config, r3
    jsr @r3
    mov.b r0, @r2
    mov.l   .L_fn_race_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_hud_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_vdp1_init, r3
    jsr @r3
    nop
    mov.l   .L_advanced_display_flag, r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bf      .L_06008978
    mov.l   .L_fn_vdp_advanced, r3
    jsr @r3
    nop
.L_06008978:
    extu.w r14, r2
    mov.l   .L_display_timer, r3
    mov.w r2, @r3
    mov.l   .L_attract_countdown, r4
    mov.w   .L_countdown_initial, r1
    mov.l r1, @r4
    mov.l   .L_attract_timer, r3
    mov.l r14, @r3
    mov.l   .L_race_end_state, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_06008996
    mov.l @r4, r3
    add #-0x3C, r3
    mov.l r3, @r4
.L_06008996:
    mov.l   .L_fn_course_data, r3
    jsr @r3
    nop
    mov.l   .L_render_flags, r4
    mov.l   .L_attract_mode_bit, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov #0x3, r2
    mov.l   .L_game_state, r3
    mov.l r2, @r3
    mov.l   .L_fn_camera_finalize, r3
    jsr @r3
    nop
    mov #0x4, r2
    mov.l   .L_anim_state, r3
    mov.l r14, @r3
    mov.l   .L_display_mode_word, r3
    mov.w r2, @r3
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_countdown_initial:
    .2byte  0x0398                        /* 920 frames (~15.3s at 60fps) */
.L_course_select_byte:
    .4byte  sym_06078634               /* course selection (byte) */
.L_demo_flag_a:
    .4byte  sym_06078635               /* demo flag A (byte) */
.L_special_render_flag:
    .4byte  sym_0607ED8C               /* special render enable (16-bit) */
.L_demo_flag_b:
    .4byte  sym_0607864B               /* demo flag B (byte) */
.L_fn_vdp2_config:
    .4byte  vdp2_config_extended       /* VDP2 extended mode configuration */
.L_fn_race_init:
    .4byte  race_init_master           /* master race initialization */
.L_fn_hud_init:
    .4byte  hud_subsystem_init         /* HUD subsystem initialization */
.L_fn_vdp1_init:
    .4byte  vdp1_init                  /* VDP1 sprite engine reset */
.L_advanced_display_flag:
    .4byte  sym_06063DA0               /* advanced display enable (16-bit) */
.L_fn_vdp_advanced:
    .4byte  vdp_init_advanced          /* advanced VDP initialization */
.L_display_timer:
    .4byte  sym_06087804               /* display timer (16-bit) */
.L_attract_countdown:
    .4byte  sym_0607EBCC               /* attract mode countdown (32-bit) */
.L_attract_timer:
    .4byte  sym_0607EAE0               /* attract timer (32-bit) */
.L_race_end_state:
    .4byte  sym_0607EAD8               /* race end state (0/1/2) */
.L_fn_course_data:
    .4byte  course_data_handler        /* course data loader/handler */
.L_render_flags:
    .4byte  sym_0605B6D8               /* render mode flags (32-bit) */
.L_attract_mode_bit:
    .4byte  0x40000000                  /* attract mode flag bit */
.L_game_state:
    .4byte  g_game_state               /* game state dispatch value */
.L_fn_camera_finalize:
    .4byte  sym_06026CE0               /* camera state finalization */
.L_anim_state:
    .4byte  sym_06059F44               /* animation state (32-bit) */
.L_display_mode_word:
    .4byte  sym_0605A016               /* display mode (16-bit) */
