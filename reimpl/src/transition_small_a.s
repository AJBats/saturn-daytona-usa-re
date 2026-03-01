
    .section .text.FUN_0600F822


    .global transition_small_a
    .type transition_small_a, @function
transition_small_a:
    sts.l pr, @-r15
    .byte   0xD5, 0x0C    /* mov.l .L_pool_sound_id, r5 */
    .byte   0xD3, 0x0D    /* mov.l .L_pool_fn_sound_cmd, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x0C    /* mov.l .L_pool_fn_anim_ui, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x0C    /* mov.l .L_pool_fn_hud_course, r3 */
    jsr @r3
    nop
    mov #0x78, r2
    .byte   0xD3, 0x0B    /* mov.l .L_pool_countdown_timer, r3 */
    mov.w r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x0A    /* mov.l .L_pool_game_state, r3 */
    lds.l @r15+, pr
    rts
    mov.b r2, @r3
    .4byte  0x0800FFFF                   /* unreferenced pool data (padding) */
    .4byte  sym_06085FF4                 /* unreferenced pool: &2p_mode_flag */
    .4byte  g_pad_state                 /* unreferenced pool: &input_state */
    .4byte  sym_06078663                 /* unreferenced pool data */
.L_pool_sound_id:
    .4byte  0xAB1101FF                   /* sound ID: transition sound */
.L_pool_fn_sound_cmd:
    .4byte  sound_cmd_dispatch           /* sound command dispatcher */
.L_pool_fn_anim_ui:
    .4byte  anim_ui_transition           /* UI animation transition function */
.L_pool_fn_hud_course:
    .4byte  hud_course_render            /* HUD course rendering function */
.L_pool_countdown_timer:
    .4byte  sym_0607887C                 /* &transition countdown timer (16-bit word) */
.L_pool_game_state:
    .4byte  sym_0607887F                 /* &game state byte (0x3 = race setup) */
