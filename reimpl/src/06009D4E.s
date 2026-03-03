
    .section .text.FUN_06009D4E


    .global state_post_race_display
    .type state_post_race_display, @function
state_post_race_display:
    sts.l pr, @-r15
    .byte   0xD3, 0x16    /* mov.l .L_pool_06009DB5, r3 */
    jsr @r3
    nop
    .byte   0xD2, 0x16    /* mov.l .L_pool_06009DB9, r2 */
    mov.b @r2, r2
    tst r2, r2
    bf      .L_06009D76

    .byte   0xD3, 0x15    /* mov.l .L_pool_06009DBD, r3 */
    jsr @r3
    nop
    .byte   0xD6, 0x14    /* mov.l .L_pool_06009DC1, r6 */
    .byte   0xD5, 0x15    /* mov.l .L_pool_06009DC5, r5 */
    .byte   0xD4, 0x15    /* mov.l .L_pool_06009DC9, r4 */
    .byte   0xD3, 0x16    /* mov.l .L_pool_06009DCD, r3 */
    jsr @r3
    mov.l @r6, r6
    .byte   0xD3, 0x15    /* mov.l .L_pool_06009DD1, r3 */
    jsr @r3
    nop

.L_06009D76:
    .byte   0xD3, 0x15    /* mov.l .L_pool_06009DD5, r3 */
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
.L_pool_06009DB5:
    .4byte  ai_waypoint_pathfind
.L_pool_06009DB9:
    .4byte  sym_06085F8A
.L_pool_06009DBD:
    .4byte  camera_system
.L_pool_06009DC1:
    .4byte  sym_06063E24
.L_pool_06009DC5:
    .4byte  sym_06063EEC
.L_pool_06009DC9:
    .4byte  sym_06063EF8
.L_pool_06009DCD:
    .4byte  camera_orient_calc
.L_pool_06009DD1:
    .4byte  scene_master
.L_pool_06009DD5:
    .4byte  frame_end_commit
