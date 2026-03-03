	.text
    .global state_course_select_active
state_course_select_active:
    sts.l pr, @-r15
    mov.l   .L_pool_06008B70, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008B74, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008B64, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06008B68, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
    .short  0xFFFF
    .long  handler_init_reset
    .long  g_game_state
    .long  track_poly_start
    .long  obj_render_update
.L_pool_06008B64:
    .long  sym_06026CE0
.L_pool_06008B68:
    .long  sym_06059F44
    .long  sym_0605A016
.L_pool_06008B70:
    .long  course_select_input
.L_pool_06008B74:
    .long  course_select_draw
