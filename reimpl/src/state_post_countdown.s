
    .section .text.FUN_06009290


    .global state_post_countdown
    .type state_post_countdown, @function
state_post_countdown:
    sts.l pr, @-r15
    mov #0x11, r3
    mov.l   .L_060092BC, r2
    mov.l r3, @r2
    mov.l   .L_060092C0, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_060092AA
    mov.l   .L_060092C4, r3
    jsr @r3
    nop
    bra     .L_060092B0
    nop
.L_060092AA:
    mov.l   .L_060092C8, r3
    jsr @r3
    nop
.L_060092B0:
    mov #0x4, r2
    mov.l   .L_060092CC, r3
    lds.l @r15+, pr
    rts
    mov.w r2, @r3
    .2byte  0xFFFF
.L_060092BC:
    .4byte  g_game_state
.L_060092C0:
    .4byte  sym_0607EAD8
.L_060092C4:
    .4byte  race_cleanup_handler
.L_060092C8:
    .4byte  sym_06012198
.L_060092CC:
    .4byte  sym_0605A016
