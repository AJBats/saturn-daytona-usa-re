	.text
    .global FUN_06008B9C
FUN_06008B9C:
    sts.l pr, @-r15
    mov.l   .L_pool_06008BD0, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008BD4, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008BC4, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06008BC8, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
    .short  0xFFFF
    .long  g_game_state
    .long  car_select_setup
.L_pool_06008BC4:
    .long  sym_06026CE0
.L_pool_06008BC8:
    .long  sym_06059F44
    .long  sym_0605A016
.L_pool_06008BD0:
    .long  FUN_06019A48
.L_pool_06008BD4:
    .long  FUN_06019928
