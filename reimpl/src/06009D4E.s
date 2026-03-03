	.text
    .global state_post_race_display
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

    .long  sym_0605A016
    .long  display_mode_init
    .long  race_state_pair_2
    .long  g_game_state
    .long  sym_06078654
    .long  gameover_channel_setup
    .long  obj_render_update
    .long  sym_0607E944
    .long  sym_0605B6D8
    .long  0x40000000
    .long  sym_06026CE0
    .long  sym_06059F44
.L_pool_06009DB5:
    .long  ai_waypoint_pathfind
.L_pool_06009DB9:
    .long  sym_06085F8A
.L_pool_06009DBD:
    .long  camera_system
.L_pool_06009DC1:
    .long  sym_06063E24
.L_pool_06009DC5:
    .long  sym_06063EEC
.L_pool_06009DC9:
    .long  sym_06063EF8
.L_pool_06009DCD:
    .long  camera_orient_calc
.L_pool_06009DD1:
    .long  scene_master
.L_pool_06009DD5:
    .long  frame_end_commit
