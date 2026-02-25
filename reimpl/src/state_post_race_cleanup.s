/* state_post_race_cleanup -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06009C48 - 0x06009CFC
 *
 * Post-race cleanup state handler — runs each frame after the race has
 * ended and results are being finalized. Simpler than the main race loop:
 * no player input, no countdown timers, no HUD — just the core subsystems
 * needed to keep the scene alive during the cleanup/transition phase.
 *
 * Per-frame sequence:
 *   1. util_wrapper() — general-purpose per-frame utility
 *   2. If camera_active_flag != 0:
 *      a. camera_special_mode() — update camera for post-race flyover
 *      b. If race_end_state != 0: replay_camera_ctrl() — replay camera
 *   3. update_mode_dispatch() — dispatch mode-specific updates
 *   4. car_proximity_check() — update car proximity detection
 *   5. camera_system() — main camera pipeline
 *   6. camera_orient_calc(up_vec, target_vec, *eye_pos) — build view matrix
 *   7. scene_master() — render scene
 *   8. If extended_display_flag != 0: extended_display_handler()
 *   9. If car.replay_data > 0: replay_record() — record replay frame
 *  10. Tail-call frame_end_commit() — finalize frame
 */

    .section .text.FUN_06009C48


    .global state_post_race_cleanup
    .type state_post_race_cleanup, @function
state_post_race_cleanup:
    sts.l pr, @-r15                         ! save return address
    mov.l   .L_fn_util_wrapper, r3          ! r3 = &util_wrapper
    jsr @r3                                 ! util_wrapper() — per-frame utility
    nop                                     ! (delay slot)
    mov.l   .L_camera_active_flag, r0       ! r0 = &camera_active_flag
    mov.l @r0, r0                           ! r0 = camera_active_flag (dword)
    tst r0, r0                              ! camera active?
    bt      .L_skip_camera_special          ! if zero → skip camera special modes
    mov.l   .L_fn_camera_special, r3        ! r3 = &camera_special_mode
    jsr @r3                                 ! camera_special_mode() — post-race flyover
    nop                                     ! (delay slot)
    mov.l   .L_race_end_state, r0           ! r0 = &race_end_state
    mov.l @r0, r0                           ! r0 = race_end_state (0/1/2)
    tst r0, r0                              ! race ended?
    bt      .L_skip_camera_special          ! if zero → skip replay camera
    mov.l   .L_fn_replay_camera, r3         ! r3 = &replay_camera_ctrl
    jsr @r3                                 ! replay_camera_ctrl() — replay camera
    nop                                     ! (delay slot)
.L_skip_camera_special:
    mov.l   .L_fn_update_dispatch, r3       ! r3 = &update_mode_dispatch
    jsr @r3                                 ! update_mode_dispatch() — mode updates
    nop                                     ! (delay slot)
    mov.l   .L_fn_car_proximity, r3         ! r3 = &car_proximity_check
    jsr @r3                                 ! car_proximity_check() — collision detect
    nop                                     ! (delay slot)
    mov.l   .L_fn_camera_system, r3         ! r3 = &camera_system
    jsr @r3                                 ! camera_system() — main camera pipeline
    nop                                     ! (delay slot)
    mov.l   .L_camera_eye_pos, r6           ! r6 = &camera_eye_pos_ptr
    mov.l   .L_camera_target_vec, r5        ! r5 = &camera_target (look-at target)
    mov.l   .L_camera_up_vec, r4            ! r4 = &camera_up_vec
    mov.l   .L_fn_camera_orient, r3         ! r3 = &camera_orient_calc
    jsr @r3                                 ! camera_orient_calc(up, target, *eye)
    mov.l @r6, r6                           ! (delay slot) r6 = dereference eye ptr
    mov.l   .L_fn_scene_master, r3          ! r3 = &scene_master
    jsr @r3                                 ! scene_master() — render scene
    nop                                     ! (delay slot)
    mov.l   .L_extended_display_flag, r0    ! r0 = &extended_display_flag
    mov.w @r0, r0                           ! r0 = extended_display_flag (16-bit)
    extu.w r0, r0                           ! zero-extend to 32 bits
    tst r0, r0                              ! extended display active?
    bt      .L_skip_extended_display        ! if zero → skip
    mov.l   .L_fn_extended_display, r3      ! r3 = &extended_display_handler
    jsr @r3                                 ! extended_display_handler()
    nop                                     ! (delay slot)
.L_skip_extended_display:
    mov.l   .L_player_car_ptr, r2           ! r2 = &player_car_struct_ptr
    mov.w   .L_off_car_replay, r0           ! r0 = 0xBC (car struct replay offset)
    mov.l @r2, r2                           ! r2 = player car struct base
    mov.l @(r0, r2), r3                     ! r3 = car[+0xBC] (replay data ptr/flag)
    cmp/pl r3                               ! replay_data > 0?
    bf      .L_skip_replay_record           ! if not positive → skip recording
    .byte   0xB1, 0xEA    /* bsr 0x0600A084 (replay_record — external) */
    nop                                     ! (delay slot)
.L_skip_replay_record:
    mov.l   .L_fn_frame_end_commit, r3      ! r3 = &frame_end_commit
    jmp @r3                                 ! tail-call frame_end_commit()
    lds.l @r15+, pr                         ! (delay slot) restore return address
.L_off_car_replay:
    .2byte  0x00BC                           /* car struct replay data offset */
.L_fn_util_wrapper:
    .4byte  util_wrapper                     /* per-frame utility wrapper */
.L_camera_active_flag:
    .4byte  sym_0607EAE0                     /* camera active flag (dword) */
.L_fn_camera_special:
    .4byte  camera_special_mode              /* post-race camera flyover */
.L_race_end_state:
    .4byte  sym_0607EAD8                     /* race end state (0/1/2) */
.L_fn_replay_camera:
    .4byte  replay_camera_ctrl               /* replay camera controller */
.L_fn_update_dispatch:
    .4byte  update_mode_dispatch             /* mode-specific update dispatch */
.L_fn_car_proximity:
    .4byte  car_proximity_check              /* car proximity/collision detect */
.L_fn_camera_system:
    .4byte  camera_system                    /* main camera pipeline */
.L_camera_eye_pos:
    .4byte  sym_06063E24                     /* camera eye position (ptr to vec3) */
.L_camera_target_vec:
    .4byte  sym_06063EEC                     /* camera look-at target vector */
.L_camera_up_vec:
    .4byte  sym_06063EF8                     /* camera up vector */
.L_fn_camera_orient:
    .4byte  camera_orient_calc               /* camera orientation matrix calc */
.L_fn_scene_master:
    .4byte  scene_master                     /* master scene render pipeline */
.L_extended_display_flag:
    .4byte  sym_0607ED8C                     /* extended display enable (16-bit) */
.L_fn_extended_display:
    .4byte  sym_060033E6                     /* extended display handler */
.L_player_car_ptr:
    .4byte  sym_0607E944                     /* player car struct pointer */
.L_fn_frame_end_commit:
    .4byte  frame_end_commit                 /* frame end commit (tail-call) */
