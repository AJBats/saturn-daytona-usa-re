
    .section .text.FUN_06009F10


    .global state_demo_setup
    .type state_demo_setup, @function
state_demo_setup:
    sts.l pr, @-r15
    .byte   0xB1, 0xBF    /* bsr 0x0600A294 (external update sub) */
    nop
    mov.l   .L_attract_countdown, r4
    mov.l @r4, r2
    add #-0x1, r2
    mov.l r2, @r4
    mov r2, r3
    cmp/pz r3
    bt      .L_demo_running
    mov.l   .L_car_state_ptr, r4
    mov.l   .L_demo_param_a, r2
    mov.w   .L_off_demo_param_a, r0
    mov.l @r4, r3
    mov.b @r2, r2
    mov.l r2, @(r0, r3)
    add #0x1C, r0
    mov.l @r4, r3
    mov.l   .L_demo_param_b, r2
    mov.l @r2, r2
    mov.l r2, @(r0, r3)
    mov.l   .L_course_select_src, r3
    mov.l   .L_replay_course, r2
    mov.l @r3, r3
    mov.l r3, @r2
    mov #0x18, r3
    mov.l   .L_game_state, r2
    mov.l r3, @r2
    mov #0x3, r3
    mov.l   .L_display_timer, r2
    lds.l @r15+, pr
    rts
    mov.w r3, @r2
.L_demo_running:
    mov.l   .L_race_end_state, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_skip_score_render
    mov.l   .L_fn_score_render, r3
    jsr @r3
    nop
.L_skip_score_render:
    mov.l   .L_fn_geom_ctrl, r3
    jsr @r3
    nop
    mov.l   .L_display_timer, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x3, r0
    bt      .L_simplified_exit
    mov.l   .L_car_array_base, r3
    add #0x1, r3
    mov.b @r3, r0
    and #0x7F, r0
    or #0x80, r0
    mov.b r0, @r3
    mov.l   .L_fn_countdown, r3
    jsr @r3
    nop
    mov.l   .L_fn_proximity, r3
    jsr @r3
    nop
    mov.l   .L_fn_perspective, r3
    jsr @r3
    nop
    mov.l   .L_fn_scene_master, r3
    jsr @r3
    nop
    mov.l   .L_fn_frame_commit, r3
    jmp @r3
    lds.l @r15+, pr
.L_simplified_exit:
    mov #0x0, r2
    mov.l   .L_anim_state, r3
    mov.l r2, @r3
    mov.l   .L_fn_camera_finalize, r3
    jmp @r3
    lds.l @r15+, pr
    .2byte  0x4F26                        /* (dead code / alignment) */
    .4byte  0x000B0009
.L_off_demo_param_a:
    .2byte  0x0224                        /* car struct offset: demo param A */
    .2byte  0xFFFF
.L_attract_countdown:
    .4byte  sym_0607EBCC               /* attract mode countdown (32-bit) */
.L_car_state_ptr:
    .4byte  sym_0607E944               /* car state base pointer */
.L_demo_param_a:
    .4byte  sym_06078637               /* demo parameter A (byte) */
.L_demo_param_b:
    .4byte  sym_06078638               /* demo parameter B (32-bit ptr) */
.L_course_select_src:
    .4byte  sym_0607863C               /* course selection source */
.L_replay_course:
    .4byte  sym_060786A4               /* replay course store */
.L_game_state:
    .4byte  g_game_state               /* game state dispatch value */
.L_display_timer:
    .4byte  sym_06087804               /* display timer (16-bit) */
.L_race_end_state:
    .4byte  sym_0607EAD8               /* race end state (0/1/2) */
.L_fn_score_render:
    .4byte  disp_score_renderer        /* score display renderer */
.L_fn_geom_ctrl:
    .4byte  geom_display_ctrl_b        /* geometry display control */
.L_car_array_base:
    .4byte  sym_06078900               /* car data array base */
.L_fn_countdown:
    .4byte  race_countdown_update      /* race countdown timer update */
.L_fn_proximity:
    .4byte  car_proximity_check        /* car proximity/collision check */
.L_fn_perspective:
    .4byte  perspective_project        /* 3D perspective projection */
.L_fn_scene_master:
    .4byte  scene_master               /* scene rendering master */
.L_fn_frame_commit:
    .4byte  frame_end_commit           /* frame end commit */
.L_anim_state:
    .4byte  sym_0605A00C               /* animation state (32-bit) */
.L_fn_camera_finalize:
    .4byte  sym_06026CE0               /* camera state finalization */
