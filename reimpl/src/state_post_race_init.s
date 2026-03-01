
    .section .text.FUN_06009CFC


    .global state_post_race_init
    .type state_post_race_init, @function
state_post_race_init:
    sts.l pr, @-r15

    mov #0x3, r3
    .byte   0xD2, 0x1E    /* mov.l .L_pool_phase_flag, r2 */  /* &sym_0605A016 (phase flag) */
    mov.w r3, @r2

    .byte   0xD3, 0x1E    /* mov.l .L_pool_fn_display_mode_init, r3 */  /* &display_mode_init (FUN_06014A74) */
    jsr @r3
    nop

    .byte   0xD3, 0x1E    /* mov.l .L_pool_fn_race_state_pair_2, r3 */  /* &race_state_pair_2 (FUN_06019058) */
    jsr @r3
    nop

    .byte   0xB2, 0x52    /* bsr 0x0600A1B8 (external) */  ! FUN_0600A1B8 -- special input handler
    nop

    mov #0x19, r2
    .byte   0xD3, 0x1C    /* mov.l .L_pool_state_var, r3 */  /* &g_game_state (game state variable) */
    mov.l r2, @r3

    mov #0x6, r2
    .byte   0xD3, 0x1B    /* mov.l .L_pool_difficulty, r3 */  /* &sym_06078654 (difficulty byte) */
    mov.b r2, @r3

    .byte   0xD3, 0x1B    /* mov.l .L_pool_fn_gameover_ch_setup, r3 */  /* &gameover_channel_setup (FUN_060032D4) */
    jsr @r3
    nop
    .byte   0xD3, 0x1B    /* mov.l .L_pool_fn_obj_render_update, r3 */  /* &obj_render_update (FUN_060210F6) */
    jsr @r3
    nop

    .byte   0xD2, 0x1A    /* mov.l .L_pool_car_ptr, r2 */  /* &sym_0607E944 (car state pointer) */
    mov #0x0, r3
    mov.l @r2, r2
    mov.l r3, @(8, r2)

    .byte   0xD4, 0x19    /* mov.l .L_pool_display_flags, r4 */  /* &sym_0605B6D8 (display flags) */
    .byte   0xD2, 0x1A    /* mov.l .L_pool_const_bit30, r2 */  /* 0x40000000 (bit 30 mask) */
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4

    .byte   0xD3, 0x19    /* mov.l .L_pool_fn_camera_finalize, r3 */  /* &sym_06026CE0 (camera state finalization) */
    jsr @r3
    nop

    mov #0x0, r2
    .byte   0xD3, 0x18    /* mov.l .L_pool_results_flag, r3 */  /* &sym_06059F44 (results flag) */
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
