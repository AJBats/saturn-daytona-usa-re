
    .section .text.FUN_06009C48


    .global state_post_race_cleanup
    .type state_post_race_cleanup, @function
state_post_race_cleanup:
    sts.l pr, @-r15
    mov.l   .L_fn_util_wrapper, r3
    jsr @r3
    nop
    mov.l   .L_camera_active_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_skip_camera_special
    mov.l   .L_fn_camera_special, r3
    jsr @r3
    nop
    mov.l   .L_race_end_state, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_skip_camera_special
    mov.l   .L_fn_replay_camera, r3
    jsr @r3
    nop
.L_skip_camera_special:
    mov.l   .L_fn_update_dispatch, r3
    jsr @r3
    nop
    mov.l   .L_fn_car_proximity, r3
    jsr @r3
    nop
    mov.l   .L_fn_camera_system, r3
    jsr @r3
    nop
    mov.l   .L_camera_eye_pos, r6
    mov.l   .L_camera_target_vec, r5
    mov.l   .L_camera_up_vec, r4
    mov.l   .L_fn_camera_orient, r3
    jsr @r3
    mov.l @r6, r6
    mov.l   .L_fn_scene_master, r3
    jsr @r3
    nop
    mov.l   .L_extended_display_flag, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_skip_extended_display
    mov.l   .L_fn_extended_display, r3
    jsr @r3
    nop
.L_skip_extended_display:
    mov.l   .L_player_car_ptr, r2
    mov.w   .L_off_car_replay, r0
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    cmp/pl r3
    bf      .L_skip_replay_record
    .byte   0xB1, 0xEA    /* bsr 0x0600A084 (replay_record */
    nop
.L_skip_replay_record:
    mov.l   .L_fn_frame_end_commit, r3
    jmp @r3
    lds.l @r15+, pr
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
