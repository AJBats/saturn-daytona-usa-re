	.text
    .global state_pre_race
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
    .short  0xFFFF
    .long  race_resource_init
    .long  race_prep_init
.L_06008E8C:
    .long  g_game_state
    .long  car_physics_init
    .long  obj_render_update
    .long  sym_0605B6D8
    .long  0x40000000
.L_06008EA0:
    .long  sym_06026CE0
.L_06008EA4:
    .long  sym_06059F44
    .long  sym_0605A016
    .long  handler_dispatch
.L_06008EB0:
    .long  sym_0607EBCC
.L_06008EB4:
    .long  game_state_dispatch
.L_06008EB8:
    .long  handler_init_reset
