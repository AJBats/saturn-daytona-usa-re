
    .section .text.FUN_0600EB14


    .global race_init_master
    .type race_init_master, @function
race_init_master:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x0, r14
    mov.w   DAT_0600ebd8, r6
    mov.l   .L_car_array_base, r4
    mov r14, r5
.L_0600EB20:
    mov.l r14, @r4
    add #0x1, r5
    cmp/hs r6, r5
    bf/s    .L_0600EB20
    add #0x4, r4
    mov.l   .L_fn_camera_reset, r3
    jsr @r3
    nop
    mov.l   .L_fn_view_matrix_reset, r3
    jsr @r3
    nop
    mov.l   .L_fn_car_array_init, r3
    jsr @r3
    nop
    mov #0x1, r5
    mov.l   .L_car_array_base, r4
    mov.w   .L_car_enable_offset, r0
    mov.l r5, @(r0, r4)
    add #0x4, r0
    mov.l r5, @(r0, r4)
    add #0x4, r0
    mov.l r5, @(r0, r4)
    add #0x4, r0
    mov.l r5, @(r0, r4)
    extu.w r14, r3
    mov.l   .L_hud_overlay_flag, r2
    mov.w r3, @r2
    mov.l   .L_race_timer_a, r2
    mov.l r14, @r2
    mov.l   .L_race_timer_b, r2
    mov.l r14, @r2
    mov.l   .L_race_timer_c, r2
    mov.l r14, @r2
    mov.l   .L_frame_counter, r2
    mov.l r14, @r2
    mov #0x0, r1
    mov.l   .L_race_event_flags, r2
    mov.l r1, @r2
    mov #0x5, r1
    mov.l   .L_lap_count, r2
    mov.b r1, @r2
    mov.l   .L_race_complete_flag, r2
    mov.l r14, @r2
    mov.l   .L_physics_state_a, r2
    mov.l r14, @r2
    mov.l   .L_checkpoint_state_a, r2
    mov.l r14, @r2
    mov.l   .L_checkpoint_state_b, r2
    mov.l r14, @r2
    exts.b r14, r1
    mov.l   .L_race_mode_byte, r2
    mov.b r1, @r2
    exts.b r14, r0
    mov.l   .L_ai_state_byte, r2
    mov.b r0, @r2
    mov.l   .L_collision_state, r3
    mov.l r14, @r3
    mov.l   .L_physics_state_b, r3
    mov.l r14, @r3
    mov.l   .L_race_phase_byte, r3
    mov.b r14, @r3
    mov.l   .L_countdown_state, r3
    mov.l r14, @r3
    mov.l   .L_render_state, r3
    mov.l r14, @r3
    mov #0x0, r1
    mov.l   .L_display_state, r3
    mov.l r1, @r3
    extu.w r14, r1
    mov.l   .L_score_display_a, r3
    mov.w r1, @r3
    extu.b r14, r0
    mov.l   .L_score_display_b, r3
    mov.b r0, @r3
    mov.l   .L_transition_byte, r3
    mov.b r14, @r3
    mov #0x0, r1
    mov.l   .L_replay_state, r3
    mov.l r1, @r3
    mov.l   .L_replay_buffer, r3
    mov.l r14, @r3
    mov.l   .L_input_state_byte, r3
    mov.b r14, @r3
    extu.b r14, r0
    mov.l   .L_sound_state_byte, r3
    mov.b r0, @r3
    mov.l   .L_timing_registers, r4
    mov.w r14, @r4
    extu.w r14, r0
    mov.w r0, @(2, r4)
    bra     .L_0600EC58
    nop

    .global DAT_0600ebd8
DAT_0600ebd8:
    .2byte  0x1810                        /* dword count = 40 cars × 0x268/4 */
.L_car_enable_offset:
    .2byte  0x0120                        /* offset to car slot enable flags */
.L_car_array_base:
    .4byte  sym_06078900               /* car data array (40 × 0x268 bytes) */
.L_fn_camera_reset:
    .4byte  sym_06026E02               /* camera state reset */
.L_fn_view_matrix_reset:
    .4byte  sym_060270C6               /* view matrix reset */
.L_fn_car_array_init:
    .4byte  car_array_init             /* car array structure initialization */
.L_hud_overlay_flag:
    .4byte  sym_06063F46               /* HUD overlay enable flag (16-bit) */
.L_race_timer_a:
    .4byte  sym_0607EAE4               /* race timer A (32-bit) */
.L_race_timer_b:
    .4byte  sym_0607EAE8               /* race timer B (32-bit) */
.L_race_timer_c:
    .4byte  sym_0607EAEC               /* race timer C (32-bit) */
.L_frame_counter:
    .4byte  sym_0607EBD0               /* frame counter (32-bit) */
.L_race_event_flags:
    .4byte  sym_0607EBF4               /* race event bitfield (32-bit) */
.L_lap_count:
    .4byte  sym_06078654               /* lap count (byte, default 5) */
.L_race_complete_flag:
    .4byte  sym_0605A1C4               /* race complete flag (32-bit) */
.L_physics_state_a:
    .4byte  sym_06082A30               /* physics state A (32-bit) */
.L_checkpoint_state_a:
    .4byte  sym_0607EABC               /* checkpoint state A (32-bit) */
.L_checkpoint_state_b:
    .4byte  sym_0607EAC0               /* checkpoint state B (32-bit) */
.L_race_mode_byte:
    .4byte  sym_06083260               /* race mode (byte) */
.L_ai_state_byte:
    .4byte  sym_06082A26               /* AI state (byte) */
.L_collision_state:
    .4byte  sym_060788FC               /* collision state (32-bit) */
.L_physics_state_b:
    .4byte  sym_06082A38               /* physics state B (32-bit) */
.L_race_phase_byte:
    .4byte  sym_06083261               /* race phase (byte) */
.L_countdown_state:
    .4byte  sym_0608325C               /* countdown state (32-bit) */
.L_render_state:
    .4byte  sym_06083258               /* render state (32-bit) */
.L_display_state:
    .4byte  sym_0605A21C               /* display state (32-bit) */
.L_score_display_a:
    .4byte  sym_06086058               /* score display A (16-bit) */
.L_score_display_b:
    .4byte  sym_0608605A               /* score display B (byte) */
.L_transition_byte:
    .4byte  sym_0605DE3C               /* transition state (byte) */
.L_replay_state:
    .4byte  sym_060786A8               /* replay state (32-bit) */
.L_replay_buffer:
    .4byte  sym_060786BC               /* replay buffer pointer (32-bit) */
.L_input_state_byte:
    .4byte  sym_06085FCC               /* input state (byte) */
.L_sound_state_byte:
    .4byte  sym_06087060               /* sound state (byte) */
.L_timing_registers:
    .4byte  sym_0602FD98               /* timing registers (5 × 16-bit) */
.L_0600EC58:
    extu.w r14, r0
    mov.w r0, @(4, r4)
    extu.w r14, r0
    mov.w r0, @(6, r4)
    extu.w r14, r0
    mov.l   .L_fn_track_obj_placement, r3
    jsr @r3
    mov.w r0, @(8, r4)
    lds.l @r15+, pr
    mov.l   .L_fn_scroll_reset, r3
    jmp @r3
    mov.l @r15+, r14
.L_fn_track_obj_placement:
    .4byte  track_obj_placement        /* track object placement */
.L_fn_scroll_reset:
    .4byte  sym_06018634               /* scroll position reset (track_utility_misc) */
