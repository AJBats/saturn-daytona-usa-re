
    .section .text.FUN_06008B34


    .global state_course_select_active
    .type state_course_select_active, @function
state_course_select_active:
    sts.l pr, @-r15
    mov.l   .L_pool_course_select_input, r3
    jsr @r3
    nop
    mov.l   .L_pool_course_select_draw, r3
    jsr @r3
    nop
    mov.l   .L_pool_display_update, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_state_tracker, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
    .2byte  0xFFFF
    .4byte  handler_init_reset
    .4byte  g_game_state
    .4byte  track_poly_start
    .4byte  obj_render_update
.L_pool_display_update:
    .4byte  sym_06026CE0
.L_pool_state_tracker:
    .4byte  sym_06059F44
    .4byte  sym_0605A016
.L_pool_course_select_input:
    .4byte  course_select_input
.L_pool_course_select_draw:
    .4byte  course_select_draw
