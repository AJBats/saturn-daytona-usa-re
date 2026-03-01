
    .section .text.FUN_06008A18


    .global state_attract_active
    .type state_attract_active, @function
state_attract_active:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_attract_countdown_ptr, r14
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov.l   .L_fn_per_frame_tick, r3
    jsr @r3
    nop
    mov.l   .L_attract_cycle_counter_ptr, r4
    mov.l @r14, r2
    cmp/pz r2
    bf      .L_timer_expired_or_start
    mov.l   .L_button_state_ptr, r2
    mov.w @r2, r3
    mov.w   .L_start_button_mask, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_attract_gameplay_loop
.L_timer_expired_or_start:
    mov.l @r14, r3
    cmp/pz r3
    bf      .L_timer_expired_inc_cycle
    mov.l   .L_fn_handler_init_reset, r3
    jsr @r3
    nop
    bra     .L_transition_to_state4
    nop
.L_timer_expired_inc_cycle:
    mov.l @r4, r2
    mov #0x3, r3
    add #0x1, r2
    mov.l r2, @r4
    cmp/hs r3, r2
    bf      .L_transition_to_state4
    mov #0x0, r3
    mov.l r3, @r4
.L_transition_to_state4:
    mov #0x4, r2
    mov.l   .L_game_state_ptr, r3
    mov.l r2, @r3
    mov #0x3, r2
    mov.l   .L_handler_mode_ptr, r3
    mov.w r2, @r3
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_attract_gameplay_loop:
    mov.l @r4, r0
    cmp/eq #0x2, r0
    bf      .L_skip_special_camera
    mov.l   .L_fn_camera_attract_init, r3
    jsr @r3
    nop
.L_skip_special_camera:
    mov.l   .L_fn_geom_display_ctrl, r3
    jsr @r3
    nop
    mov.l   .L_fn_race_countdown, r3
    jsr @r3
    nop
    mov.l   .L_fn_car_proximity, r3
    jsr @r3
    nop
    mov.l   .L_fn_perspective_project, r3
    jsr @r3
    nop
    mov #0x15, r5
    mov.l   .L_fn_dlist_slot_select, r3
    jsr @r3
    mov.l @r14, r4
    mov.l   .L_fn_scene_master, r3
    jsr @r3
    nop
    mov.l @r14, r2
    mov.w   .L_early_attract_threshold, r3
    cmp/gt r3, r2
    bt      .L_frame_commit
    mov.l   .L_fn_attract_phase_dispatch, r3
    jsr @r3
    nop
.L_frame_commit:
    lds.l @r15+, pr
    mov.l   .L_fn_frame_end_commit, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0x4F26                              /* dead code: unreachable lds.l @r15+, pr */
    .4byte  0x000B6EF6                          /* dead code: unreachable rts + mov.l @r15+, r14 */
.L_start_button_mask:
    .2byte  0x0800                              /* Start button bitmask */
.L_early_attract_threshold:
    .2byte  0x0244                              /* 580 frames (~9.7s remaining = first ~5.7s of attract) */
.L_attract_countdown_ptr:
    .4byte  sym_0607EBCC                        /* attract mode countdown timer (32-bit, init 920) */
.L_fn_per_frame_tick:
    .4byte  sym_0600A1F6                        /* per_frame_game_tick — general per-frame update */
.L_attract_cycle_counter_ptr:
    .4byte  sym_0607EAD8                        /* attract cycle counter (0-2, wraps mod 3) */
.L_button_state_ptr:
    .4byte  sym_06063D9A                        /* button state register (16-bit) */
.L_fn_handler_init_reset:
    .4byte  handler_init_reset                  /* handler_init_reset — prepare for mode select */
.L_game_state_ptr:
    .4byte  g_game_state                        /* game state variable (32-bit) */
.L_handler_mode_ptr:
    .4byte  sym_06087804                        /* handler mode (16-bit) */
.L_fn_camera_attract_init:
    .4byte  camera_attract_init                 /* camera_attract_init — special camera for 3rd cycle */
.L_fn_geom_display_ctrl:
    .4byte  geom_display_ctrl_b                 /* geom_display_ctrl_b — geometry display update */
.L_fn_race_countdown:
    .4byte  race_countdown_update               /* race_countdown_update — countdown state update */
.L_fn_car_proximity:
    .4byte  car_proximity_check                 /* car_proximity_check — car-to-car proximity */
.L_fn_perspective_project:
    .4byte  perspective_project                 /* perspective_project — 3D projection / rendering */
.L_fn_dlist_slot_select:
    .4byte  sym_0600338C                        /* dlist_slot_select — display list slot dispatch */
.L_fn_scene_master:
    .4byte  scene_master                        /* scene_master — master scene rendering orchestrator */
.L_fn_attract_phase_dispatch:
    .4byte  sym_0601AEB6                        /* attract_phase_dispatch — early attract phase logic */
.L_fn_frame_end_commit:
    .4byte  frame_end_commit                    /* frame_end_commit — finalize and commit frame */
