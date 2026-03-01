
    .section .text.FUN_06009098


    .global state_race_main
    .type state_race_main, @function
state_race_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_race_points, r8
    mov.l   .L_car_struct_ptr, r9
    mov.l   .L_game_state, r10
    mov.l   .L_race_state_flag, r11
    mov.l   .L_car_array_base, r14
    mov.l   .L_traffic_light_state, r3
    mov.w @r3, r2
    mov.w   .L_bit11_mask, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt/s    .L_after_light_check
    mov #0x10, r13
    mov #0xF, r3
    mov.l   .L_race_event_flag, r2
    mov.l r3, @r2
    mov #0x12, r3
    mov.l r3, @r10
.L_after_light_check:
    mov.l   .L_countdown_timer, r2
    mov.l   .L_countdown_timer, r3
    mov.l @r2, r2
    add #-0x1, r2
    mov.l r2, @r3
    mov.l   .L_menu_overlay_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_after_menu_overlay
    mov.l   .L_fn_menu_overlay, r3
    jsr @r3
    mov #0x0, r4
.L_after_menu_overlay:
    mov.w @r11, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_init_car_loop
    mov.l   .L_fn_state_notify, r3
    jsr @r3
    nop
.L_init_car_loop:
    mov #0x0, r12
    mov.l   .L_car_data_default, r2
    bra     .L_car_loop_cond
    mov.l r2, @r15
.L_car_loop_body:
    mov.l   .L_car_update_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_subsystem_calls
    extu.b r12, r12
    tst r12, r12
    bf      .L_swap_car_out
    mov #0x1, r3
    mov.w r3, @r11
    mov.l @r15, r2
    mov.l r2, @r14
    mov r2, r3
    bra     .L_subsystem_calls
    mov.l r2, @r9
.L_bit11_mask:
    .2byte  0x0800                        /* traffic light change bit mask */
.L_race_points:
    .4byte  sym_0607ED88               /* race score/points counter */
.L_car_struct_ptr:
    .4byte  sym_0607E940               /* current car struct pointer variable */
.L_game_state:
    .4byte  g_game_state               /* game phase state (0x10/0x12/0x15) */
.L_race_state_flag:
    .4byte  sym_0607ED8C               /* per-frame race state flag (16-bit) */
.L_car_array_base:
    .4byte  sym_0607E944               /* car array base pointer variable */
.L_traffic_light_state:
    .4byte  sym_06063D9A               /* traffic light state register */
.L_race_event_flag:
    .4byte  sym_0607EACC               /* race event flag (0xF on light change) */
.L_countdown_timer:
    .4byte  sym_0607EBCC               /* race countdown timer (decremented per frame) */
.L_menu_overlay_flag:
    .4byte  sym_0605AB18               /* menu overlay active flag (byte) */
.L_fn_menu_overlay:
    .4byte  menu_overlay_render        /* draw menu overlay */
.L_fn_state_notify:
    .4byte  sym_060033E6               /* state change notification handler */
.L_car_data_default:
    .4byte  sym_06078B68               /* default car data pointer */
.L_car_update_flag:
    .4byte  sym_06078635               /* per-car update trigger flag (byte) */
.L_swap_car_out:
    mov #0x0, r2
    mov.w r2, @r11
    mov.l   .L_car_array_start, r3
    mov.l r3, @r14
    mov r3, r2
    mov.l r3, @r9
    mov.l @r8, r3
    add #-0x2, r3
    mov.l r3, @r8
.L_subsystem_calls:
    mov.l   .L_fn_frame_update, r3
    jsr @r3
    nop
    mov.l   .L_fn_camera_compute, r3
    jsr @r3
    nop
    mov.l   .L_fn_render_prep, r3
    jsr @r3
    nop
    mov.l   .L_fn_race_state, r3
    jsr @r3
    nop
    mov.l   .L_race_end_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_check_timeout
    mov.l   .L_fn_race_end_handler, r3
    jsr @r3
    nop
    mov.l   .L_countdown_timer_2, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_car_loop_next
    bra     .L_car_loop_next
    mov.l r13, @r10
.L_check_timeout:
    mov.l   .L_race_timeout, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_car_loop_next
    mov.l r13, @r10
.L_car_loop_next:
    add #0x1, r12
.L_car_loop_cond:
    extu.b r12, r3
    mov.l   .L_car_count, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r2, r3
    bf      .L_car_loop_body
    mov.l   .L_terrain_mode, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_sprite_path
    mov.l   .L_fn_terrain_lookup, r3
    jsr @r3
    nop
    bra     .L_scene_prep
    nop
.L_sprite_path:
    mov.l   .L_fn_sprite_xform, r3
    jsr @r3
    nop
.L_scene_prep:
    mov.l   .L_fn_scene_prep, r3
    jsr @r3
    nop
    mov.l   .L_camera_mode, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_simple_perspective
    mov.l   .L_fn_camera_system, r3
    jsr @r3
    nop
    mov.l   .L_camera_param_a, r6
    mov.l   .L_camera_param_b, r5
    mov.l   .L_camera_param_c, r4
    mov.l   .L_fn_camera_orient, r3
    jsr @r3
    mov.l @r6, r6
    bra     .L_after_camera
    nop
.L_simple_perspective:
    mov.l   .L_fn_perspective, r3
    jsr @r3
    nop
.L_after_camera:
    mov.l   .L_fn_scene_master, r3
    jsr @r3
    nop
    mov.l   .L_debug_display_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_epilogue
    mov.l   .L_debug_display_data, r7
    mov.l   .L_mask_nibble3, r6
    mov.w   .L_debug_vdp1_offset, r5
    mov.l   .L_fn_debug_draw, r3
    jsr @r3
    mov #0x8, r4
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_frame_end, r3
    jmp @r3
    mov.l @r15+, r14
.L_debug_vdp1_offset:
    .2byte  0x0082                        /* VDP1 cmd offset for debug display */
.L_car_array_start:
    .4byte  sym_06078900               /* car array start (first car struct) */
.L_fn_frame_update:
    .4byte  sym_060302C6               /* per-car frame update (physics/state) */
.L_fn_camera_compute:
    .4byte  render_camera_compute      /* camera matrix computation */
.L_fn_render_prep:
    .4byte  sym_0602F0E8               /* pre-render state preparation */
.L_fn_race_state:
    .4byte  race_state_update          /* race progress (laps, checkpoints) */
.L_race_end_flag:
    .4byte  sym_0607EAD8               /* race end trigger flag */
.L_fn_race_end_handler:
    .4byte  sym_0600C302               /* race end sequence handler */
.L_countdown_timer_2:
    .4byte  sym_0607EBCC               /* countdown timer (dup for reach) */
.L_race_timeout:
    .4byte  sym_0607EAD0               /* race timeout counter */
.L_car_count:
    .4byte  sym_06078634               /* total car count (byte) */
.L_terrain_mode:
    .4byte  sym_06083255               /* terrain rendering mode flag (byte) */
.L_fn_terrain_lookup:
    .4byte  terrain_data_lookup        /* terrain-based rendering */
.L_fn_sprite_xform:
    .4byte  sprite_transform           /* sprite-based rendering */
.L_fn_scene_prep:
    .4byte  sym_06012198               /* scene data preparation */
.L_camera_mode:
    .4byte  sym_06078654               /* camera mode (1=full, else=simple) */
.L_fn_camera_system:
    .4byte  camera_system              /* full camera system update */
.L_camera_param_a:
    .4byte  sym_06063E24               /* camera parameter table A (ptr) */
.L_camera_param_b:
    .4byte  sym_06063EEC               /* camera parameter B */
.L_camera_param_c:
    .4byte  sym_06063EF8               /* camera parameter C */
.L_fn_camera_orient:
    .4byte  camera_orient_calc         /* camera orientation computation */
.L_fn_perspective:
    .4byte  perspective_project        /* simple perspective projection */
.L_fn_scene_master:
    .4byte  scene_master               /* master scene renderer */
.L_debug_display_flag:
    .4byte  sym_06086030               /* debug HUD display flag (byte) */
.L_debug_display_data:
    .4byte  sym_0605A1C8               /* debug display data struct */
.L_mask_nibble3:
    .4byte  0x0000F000                  /* nibble 3 mask */
.L_fn_debug_draw:
    .4byte  sym_060283E0               /* debug HUD draw function */
.L_fn_frame_end:
    .4byte  frame_end_commit           /* frame end / VDP commit */
