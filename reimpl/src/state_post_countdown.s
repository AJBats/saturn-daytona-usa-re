
    .section .text.FUN_06009290


    .global state_post_countdown
    .type state_post_countdown, @function
state_post_countdown:
    sts.l pr, @-r15
    mov #0x11, r3
    mov.l   .L_game_state_var, r2
    mov.l r3, @r2
    mov.l   .L_race_end_state, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_race_active
    mov.l   .L_fn_race_cleanup, r3
    jsr @r3
    nop
    bra     .L_set_display_mode
    nop
.L_race_active:
    mov.l   .L_fn_race_dispatch, r3
    jsr @r3
    nop
.L_set_display_mode:
    mov #0x4, r2
    mov.l   .L_display_mode_word, r3
    lds.l @r15+, pr
    rts
    mov.w r2, @r3
    .2byte  0xFFFF
.L_game_state_var:
    .4byte  g_game_state
.L_race_end_state:
    .4byte  sym_0607EAD8
.L_fn_race_cleanup:
    .4byte  race_cleanup_handler
.L_fn_race_dispatch:
    .4byte  sym_06012198
.L_display_mode_word:
    .4byte  sym_0605A016
