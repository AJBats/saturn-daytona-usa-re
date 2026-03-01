
    .section .text.FUN_06008E48


    .global state_pre_race
    .type state_pre_race, @function
state_pre_race:
    sts.l pr, @-r15
    mov.l   .L_06008EB0, r3
    mov.l @r3, r3
    cmp/pz r3
    bt      .L_06008E68
    mov #0xE, r3
    mov.l   .L_06008E8C, r2
    mov.l r3, @r2
    mov.l   .L_06008EA0, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_06008EA4, r3
    mov.l r2, @r3
    bra     .L_06008E6E
    nop
.L_06008E68:
    mov.l   .L_06008EB4, r3
    jsr @r3
    nop
.L_06008E6E:
    mov.l   .L_06008E8C, r0
    mov.l @r0, r0
    cmp/eq #0xD, r0
    bt      .L_06008E7C
    mov.l   .L_06008EB8, r3
    jmp @r3
    lds.l @r15+, pr
.L_06008E7C:
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xFFFF
    .4byte  race_resource_init
    .4byte  race_prep_init
.L_06008E8C:
    .4byte  g_game_state               /* game phase state */
    .4byte  car_physics_init           /* (unreferenced pool entry) */
    .4byte  obj_render_update          /* (unreferenced pool entry) */
    .4byte  sym_0605B6D8               /* (unreferenced — render flags) */
    .4byte  0x40000000                 /* (unreferenced — render flag bit 30) */
.L_06008EA0:
    .4byte  sym_06026CE0               /* initialization finalization function */
.L_06008EA4:
    .4byte  sym_06059F44               /* camera follow mode flag */
    .4byte  sym_0605A016               /* (unreferenced — game state word) */
    .4byte  handler_dispatch           /* (unreferenced pool entry) */
.L_06008EB0:
    .4byte  sym_0607EBCC               /* race countdown timer */
.L_06008EB4:
    .4byte  game_state_dispatch        /* main game state machine dispatcher */
.L_06008EB8:
    .4byte  handler_init_reset         /* initialization pipeline continuation */
