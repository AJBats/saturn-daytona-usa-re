
    .section .text.FUN_06009D4E


    .global state_post_race_display
    .type state_post_race_display, @function
state_post_race_display:
    sts.l pr, @-r15
    .byte   0xD3, 0x16    /* mov.l .L_pool_results_display, r3 */  ! r3 = &ai_waypoint_pathfind (results display logic)
    jsr @r3
    nop
    .byte   0xD2, 0x16    /* mov.l .L_pool_display_enable, r2 */  ! r2 = &sym_06085F8A (display enable flag address)
    mov.b @r2, r2
    tst r2, r2
    bf      .L_skip_display_pipeline

    .byte   0xD3, 0x15    /* mov.l .L_pool_camera_system, r3 */  ! r3 = &camera_system (multi-mode camera controller)
    jsr @r3
    nop
    .byte   0xD6, 0x14    /* mov.l .L_pool_camera_struct, r6 */  ! r6 = sym_06063E24 (camera struct base address)
    .byte   0xD5, 0x15    /* mov.l .L_pool_camera_heading, r5 */  ! r5 = sym_06063EEC (camera parameter B — smoothed heading)
    .byte   0xD4, 0x15    /* mov.l .L_pool_camera_param_a, r4 */  ! r4 = sym_06063EF8 (camera parameter A)
    .byte   0xD3, 0x16    /* mov.l .L_pool_camera_orient, r3 */  ! r3 = &camera_orient_calc (display commit function)
    jsr @r3
    mov.l @r6, r6
    .byte   0xD3, 0x15    /* mov.l .L_pool_scene_master, r3 */  ! r3 = &scene_master (master scene rendering orchestrator)
    jsr @r3
    nop

.L_skip_display_pipeline:
    .byte   0xD3, 0x15    /* mov.l .L_pool_frame_end, r3 */  ! r3 = &frame_end_commit (frame timing / sync)
    jmp @r3
    lds.l @r15+, pr

    .4byte  sym_0605A016
    .4byte  display_mode_init
    .4byte  race_state_pair_2
    .4byte  g_game_state
    .4byte  sym_06078654
    .4byte  gameover_channel_setup
    .4byte  obj_render_update
    .4byte  sym_0607E944
    .4byte  sym_0605B6D8
    .4byte  0x40000000
    .4byte  sym_06026CE0
    .4byte  sym_06059F44
.L_pool_results_display:
    .4byte  ai_waypoint_pathfind
.L_pool_display_enable:
    .4byte  sym_06085F8A
.L_pool_camera_system:
    .4byte  camera_system
.L_pool_camera_struct:
    .4byte  sym_06063E24
.L_pool_camera_heading:
    .4byte  sym_06063EEC
.L_pool_camera_param_a:
    .4byte  sym_06063EF8
.L_pool_camera_orient:
    .4byte  camera_orient_calc
.L_pool_scene_master:
    .4byte  scene_master
.L_pool_frame_end:
    .4byte  frame_end_commit
