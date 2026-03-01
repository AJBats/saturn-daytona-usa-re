
    .section .text.FUN_06008E48


    .global state_pre_race
    .type state_pre_race, @function
state_pre_race:
    sts.l pr, @-r15
    mov.l   .L_countdown_timer, r3
    mov.l @r3, r3
    cmp/pz r3
    bt      .L_dispatch_state
    mov #0xE, r3
    mov.l   .L_game_state, r2
    mov.l r3, @r2
    mov.l   .L_fn_init_finalize, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_camera_follow_flag, r3
    mov.l r2, @r3
    bra     .L_check_state_done
    nop
.L_dispatch_state:
    mov.l   .L_fn_game_state_dispatch, r3
    jsr @r3
    nop
.L_check_state_done:
    mov.l   .L_game_state, r0
    mov.l @r0, r0
    cmp/eq #0xD, r0
    bt      .L_return
    mov.l   .L_fn_handler_init_reset, r3
    jmp @r3
    lds.l @r15+, pr
.L_return:
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xFFFF
    .4byte  race_resource_init
    .4byte  race_prep_init
.L_game_state:
    .4byte  g_game_state               /* game phase state */
    .4byte  car_physics_init           /* (unreferenced pool entry) */
    .4byte  obj_render_update          /* (unreferenced pool entry) */
    .4byte  sym_0605B6D8               /* (unreferenced — render flags) */
    .4byte  0x40000000                 /* (unreferenced — render flag bit 30) */
.L_fn_init_finalize:
    .4byte  sym_06026CE0               /* initialization finalization function */
.L_camera_follow_flag:
    .4byte  sym_06059F44               /* camera follow mode flag */
    .4byte  sym_0605A016               /* (unreferenced — game state word) */
    .4byte  handler_dispatch           /* (unreferenced pool entry) */
.L_countdown_timer:
    .4byte  sym_0607EBCC               /* race countdown timer */
.L_fn_game_state_dispatch:
    .4byte  game_state_dispatch        /* main game state machine dispatcher */
.L_fn_handler_init_reset:
    .4byte  handler_init_reset         /* initialization pipeline continuation */
