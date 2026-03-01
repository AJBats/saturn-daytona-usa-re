
    .section .text.FUN_0600955E


    .global state_results_screen
    .type state_results_screen, @function
state_results_screen:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xDE, 0x0D    /* mov.l .L_game_state_ptr, r14 — game state dispatch */
    .byte   0xD3, 0x18    /* mov.l .L_status_word, r3 — input status word */
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_start_button_mask, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_abort
    mov #0x1D, r3
    .byte   0xD2, 0x15    /* mov.l .L_timer_target, r2 — countdown timer */
    mov.l r3, @r2
    mov #0x12, r3
    mov.l r3, @r14
.L_check_abort:
    .byte   0xD4, 0x06    /* mov.l .L_race_event_flags, r4 — event bitfield */
    mov.l @r4, r0
    tst #0x1, r0
    bt      .L_check_timer
    mov #-0x2, r3
    mov.l @r4, r2
    and r3, r2
    mov.l r2, @r4
    mov #0x14, r3
    mov.l r3, @r14
    bra     .L_render_pipeline
    nop
.L_start_button_mask:
    .2byte  0x0800                        /* start button bit mask */
.L_race_event_flags:
    .4byte  sym_0607EBF4               /* race event bitfield (32-bit) */
.L_game_state_ptr:
    .4byte  g_game_state               /* current game state dispatch pointer */
    .4byte  sym_0607EAD0               /* (adjacent pool: race timer) */
    .4byte  sym_0607EBD0               /* (adjacent pool: frame counter) */
    .4byte  race_update_abort          /* (adjacent pool: abort handler) */
    .4byte  camera_system              /* (adjacent pool: camera system) */
    .4byte  sym_06063E24               /* (adjacent pool: camera yaw ptr) */
    .4byte  sym_06063EEC               /* (adjacent pool: camera pitch ptr) */
    .4byte  sym_06063EF8               /* (adjacent pool: camera params ptr) */
    .4byte  camera_orient_calc         /* (adjacent pool: camera orient fn) */
    .4byte  scene_update               /* (adjacent pool: scene update) */
    .4byte  frame_end_commit           /* (adjacent pool: frame commit) */
.L_status_word:
    .4byte  sym_06063D9A               /* input status word (16-bit) */
.L_timer_target:
    .4byte  sym_0607EACC               /* countdown timer target (32-bit) */
.L_check_timer:
    .byte   0xD0, 0x2C    /* mov.l .L_race_timer, r0 — race timer */
    mov.l @r0, r0
    tst r0, r0
    bf      .L_render_pipeline
    .byte   0xD4, 0x2B    /* mov.l .L_frame_counter, r4 — frame counter */
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
.L_render_pipeline:
    .byte   0xD0, 0x2A    /* mov.l .L_overlay_active, r0 — overlay flag */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_call_race_ending
    .byte   0xD3, 0x29    /* mov.l .L_fn_menu_overlay, r3 */
    jsr @r3
    mov #0x0, r4
.L_call_race_ending:
    .byte   0xD3, 0x29    /* mov.l .L_fn_race_ending, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x28    /* mov.l .L_fn_camera_system, r3 */
    jsr @r3
    nop
    .byte   0xD6, 0x28    /* mov.l .L_camera_yaw_ptr, r6 */
    .byte   0xD5, 0x28    /* mov.l .L_camera_pitch_ptr, r5 */
    .byte   0xD4, 0x29    /* mov.l .L_camera_params_ptr, r4 */
    .byte   0xD3, 0x29    /* mov.l .L_fn_camera_orient, r3 */
    jsr @r3
    mov.l @r6, r6
    .byte   0xD3, 0x29    /* mov.l .L_fn_scene_update, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x28    /* mov.l .L_special_render_flag, r0 — check special render */
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_check_geom_render
    .byte   0xD3, 0x27    /* mov.l .L_fn_special_render, r3 */
    jsr @r3
    nop
.L_check_geom_render:
    .byte   0xD0, 0x26    /* mov.l .L_geom_render_flag, r0 — check geom flag */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_check_car_timer
    .byte   0xD7, 0x25    /* mov.l .L_geom_data_ptr, r7 — geometry data */
    .byte   0xD6, 0x25    /* mov.l .L_mask_nibble3, r6 — 0xF000 */
    mov.w   .L_tile_size, r5
    .byte   0xD3, 0x25    /* mov.l .L_fn_geom_dispatch, r3 */
    jsr @r3
    mov #0x8, r4
.L_check_car_timer:
    .byte   0xD2, 0x25    /* mov.l .L_car_state_ptr, r2 — car state base */
    mov.w   .L_car_timer_offset, r0
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    cmp/pl r3
    bf      .L_frame_commit
    .byte   0xB5, 0x21    /* bsr 0x0600A084 (external sub-function) */
    nop
.L_frame_commit:
    .byte   0xD3, 0x22    /* mov.l .L_fn_frame_commit, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x1F    /* mov.l .L_car_state_ptr, r0 */
    mov.w   .L_car_flags_offset, r1
    mov.l @r0, r0
    mov.l @(r0, r1), r0
    tst #0xCC, r0
    bf      .L_check_race_complete
    .byte   0xD3, 0x1E    /* mov.l .L_display_layer_data, r3 — layer params */
    mov.l r3, @r15
    mov r3, r7
    mov r3, r5
    mov.w   .L_layer_priority, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    .byte   0xD3, 0x1C    /* mov.l .L_fn_layer_setup, r3 */
    jsr @r3
    mov #0x4, r4
.L_check_race_complete:
    .byte   0xD0, 0x1B    /* mov.l .L_race_complete_flag, r0 */
    mov.l @r0, r0
    tst r0, r0
    bf      .L_epilogue
    mov #0x11, r3
    mov.l r3, @r14
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_tile_size:
    .2byte  0x0082                        /* geometry tile size parameter */
.L_car_timer_offset:
    .2byte  0x00BC                        /* car struct offset: timer value */
.L_car_flags_offset:
    .2byte  0x0214                        /* car struct offset: flags word */
.L_layer_priority:
    .2byte  0x0900                        /* display layer priority value */
.L_race_timer:
    .4byte  sym_0607EAD0               /* race timer (32-bit) */
.L_frame_counter:
    .4byte  sym_0607EBD0               /* frame counter (32-bit) */
.L_overlay_active:
    .4byte  sym_0605AB18               /* overlay active flag (byte) */
.L_fn_menu_overlay:
    .4byte  menu_overlay_render        /* menu overlay render function */
.L_fn_race_ending:
    .4byte  race_update_ending         /* race ending update */
.L_fn_camera_system:
    .4byte  camera_system              /* camera system update */
.L_camera_yaw_ptr:
    .4byte  sym_06063E24               /* camera yaw data pointer */
.L_camera_pitch_ptr:
    .4byte  sym_06063EEC               /* camera pitch data pointer */
.L_camera_params_ptr:
    .4byte  sym_06063EF8               /* camera parameters pointer */
.L_fn_camera_orient:
    .4byte  camera_orient_calc         /* camera orientation calculation */
.L_fn_scene_update:
    .4byte  scene_update               /* 3D scene update */
.L_special_render_flag:
    .4byte  sym_0607ED8C               /* special render enable (16-bit) */
.L_fn_special_render:
    .4byte  sym_060033E6               /* special render function */
.L_geom_render_flag:
    .4byte  sym_06086030               /* geometry render enable (byte) */
.L_geom_data_ptr:
    .4byte  sym_0605A1C8               /* geometry data pointer */
.L_mask_nibble3:
    .4byte  0x0000F000                  /* nibble 3 mask */
.L_fn_geom_dispatch:
    .4byte  sym_060283E0               /* geometry render dispatch */
.L_car_state_ptr:
    .4byte  sym_0607E944               /* car state base pointer */
.L_fn_frame_commit:
    .4byte  frame_end_commit           /* frame end commit */
.L_display_layer_data:
    .4byte  sym_06063798               /* display layer parameters */
.L_fn_layer_setup:
    .4byte  sym_06028400               /* display layer setup */
.L_race_complete_flag:
    .4byte  sym_0605A1C4               /* race complete flag (32-bit) */
