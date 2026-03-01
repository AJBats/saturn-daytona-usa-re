
    .section .text.FUN_06008EBC


    .global state_race_setup
    .type state_race_setup, @function
state_race_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov #0x3, r13
    mov.l   .L_fn_race_resource_init, r3
    jsr @r3
    mov #0x0, r14
    extu.b r14, r2
    mov.l   .L_race_result_byte, r3
    mov #0x1, r6
    mov #0x8, r0
    mov.b r2, @r3
    extu.b r6, r1
    mov.l   .L_race_active_flag, r3
    mov.b r1, @r3
    mov.l   .L_physics_frame_count, r3
    mov.l r0, @r3
    mov.l   .L_game_mode_word, r0
    mov.l   .L_fp_half, r3
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq r3, r0
    bf      .L_subsys_init
    mov.l   .L_special_mode_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_subsys_init
    mov.l   .L_overlay_active, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_subsys_init
    mov.l   .L_status_word, r4
    mov.l   .L_course_index, r5
    mov.l   .L_course_mask_a, r2
    mov.w @r4, r4
    mov.w @r2, r2
    exts.w r4, r3
    extu.w r2, r2
    and r2, r3
    tst r3, r3
    bt      .L_check_mask_b
    bra     .L_subsys_init
    mov.b r14, @r5
.L_check_mask_b:
    exts.w r4, r2
    mov.l   .L_course_mask_b, r3
    mov.w @r3, r3
    extu.w r3, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_mask_c
    exts.b r6, r6
    bra     .L_subsys_init
    mov.b r6, @r5
.L_check_mask_c:
    exts.w r4, r2
    mov.l   .L_course_mask_c, r3
    mov.w @r3, r3
    extu.w r3, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_mask_d
    mov #0x2, r3
    mov.b r3, @r5
    bra     .L_subsys_init
    nop
.L_fn_race_resource_init:
    .4byte  race_resource_init         /* course/car resource loader */
.L_race_result_byte:
    .4byte  sym_06078635               /* race result (0=in progress) */
.L_race_active_flag:
    .4byte  sym_06078634               /* race active flag (1=active) */
.L_physics_frame_count:
    .4byte  sym_0607ED88               /* physics warmup frame counter */
.L_game_mode_word:
    .4byte  sym_0607865E               /* game mode selector (16-bit) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_special_mode_flag:
    .4byte  sym_0605AD08               /* special game mode flag */
.L_overlay_active:
    .4byte  sym_0605AB18               /* menu overlay active flag (byte) */
.L_status_word:
    .4byte  g_pad_state               /* input/status register (16-bit) */
.L_course_index:
    .4byte  sym_06078648               /* current course index (byte) */
.L_course_mask_a:
    .4byte  sym_06078656               /* course 0 selection bit mask */
.L_course_mask_b:
    .4byte  sym_06078658               /* course 1 selection bit mask */
.L_course_mask_c:
    .4byte  sym_0607865A               /* course 2 selection bit mask */
.L_check_mask_d:
    exts.w r4, r4
    mov.l   .L_course_mask_d, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r2, r4
    tst r4, r4
    bt      .L_subsys_init
    exts.b r13, r3
    mov.b r3, @r5
.L_subsys_init:
    mov.l   .L_fn_vdp2_config, r3
    jsr @r3
    nop
    mov.l   .L_fn_geom_finalize, r3
    jsr @r3
    nop
    exts.b r13, r2
    mov.l   .L_sound_mode, r4
    mov.b r2, @r4
    mov.l   .L_race_result_ref, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_race_master_init
    mov.l   .L_mode_register, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_race_master_init
    mov #0x4, r3
    mov.b r3, @r4
.L_race_master_init:
    mov.l   .L_fn_race_init, r3
    jsr @r3
    nop
    mov.l   .L_hud_variant, r4
    mov.l   .L_fn_hud_post_update, r3
    mov.b @r4, r4
    jsr @r3
    extu.b r4, r4
    mov.l   .L_fn_hud_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_disp_init, r3
    jsr @r3
    nop
    mov.w   .L_countdown_initial, r2
    mov.l   .L_countdown_timer, r3
    mov.l r2, @r3
    mov.l   .L_race_end_state, r4
    mov.l   .L_variant_table, r3
    mov.l   .L_fn_variant_dispatch, r2
    mov.l @r4, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov.l   .L_fn_race_start_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_bg_layer_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_geom_matrix, r3
    jsr @r3
    nop
    mov.l   .L_overlay_active_2, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_final_state_setup
    mov.l   .L_fn_menu_overlay, r3
    jsr @r3
    mov #0x1, r4
.L_final_state_setup:
    mov #0xF, r2
    mov.l   .L_game_state, r3
    mov.l r2, @r3
    mov.l   .L_render_flags, r4
    mov.l   .L_render_flag_bit, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov.l   .L_fn_init_finalize, r3
    jsr @r3
    nop
    mov.l   .L_camera_follow_flag, r3
    mov.l r14, @r3
    mov.l   .L_state_word, r3
    mov.w r13, @r3
    mov.l   .L_course_loaded, r3
    mov.b r14, @r3
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_countdown_initial:
    .2byte  0x0096                        /* 150 frames countdown */
    .2byte  0xFFFF                        /* padding for 4-byte alignment */
.L_course_mask_d:
    .4byte  sym_0607865C               /* course 3 selection bit mask */
.L_fn_vdp2_config:
    .4byte  vdp2_config_extended       /* VDP2 extended configuration */
.L_fn_geom_finalize:
    .4byte  geom_output_finalize       /* geometry output finalization */
.L_sound_mode:
    .4byte  sym_06078662               /* sound mode (3=normal, 4=enhanced) */
.L_race_result_ref:
    .4byte  sym_06078635               /* race result byte (dup for reach) */
.L_mode_register:
    .4byte  sym_0607ED8C               /* mode register (16-bit) */
.L_fn_race_init:
    .4byte  race_init_master           /* race state machine initialization */
.L_hud_variant:
    .4byte  sym_0607ED91               /* HUD variant index (byte) */
.L_fn_hud_post_update:
    .4byte  hud_post_update            /* HUD post-update handler */
.L_fn_hud_init:
    .4byte  hud_subsystem_init         /* HUD subsystem initialization */
.L_fn_disp_init:
    .4byte  disp_init_setup            /* display initialization */
.L_countdown_timer:
    .4byte  sym_0607EBCC               /* race countdown timer */
.L_race_end_state:
    .4byte  sym_0607EAD8               /* race end state (dispatch index) */
.L_variant_table:
    .4byte  sym_0605E158               /* race variant function table */
.L_fn_variant_dispatch:
    .4byte  sym_060054EA               /* variant setup dispatch function */
.L_fn_race_start_init:
    .4byte  race_start_init            /* race start sequence initialization */
.L_fn_bg_layer_init:
    .4byte  bg_layer_init              /* background layer initialization */
.L_fn_geom_matrix:
    .4byte  geom_matrix_setup          /* geometry matrix initialization */
.L_overlay_active_2:
    .4byte  sym_0605AB18               /* overlay active flag (dup for reach) */
.L_fn_menu_overlay:
    .4byte  menu_overlay_render        /* menu overlay renderer */
.L_game_state:
    .4byte  g_game_state               /* game phase state */
.L_render_flags:
    .4byte  sym_0605B6D8               /* global render flags */
.L_render_flag_bit:
    .4byte  0x40000000                  /* bit 30: race render enable */
.L_fn_init_finalize:
    .4byte  sym_06026CE0               /* initialization finalization */
.L_camera_follow_flag:
    .4byte  sym_06059F44               /* camera follow mode flag */
.L_state_word:
    .4byte  sym_0605A016               /* game state word (16-bit) */
.L_course_loaded:
    .4byte  sym_0607864A               /* course loaded flag (byte) */
