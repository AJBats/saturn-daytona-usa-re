    .section .text.FUN_06008B9C


    .global FUN_06008B9C
    .type FUN_06008B9C, @function
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
    .2byte  0xFFFF
    .4byte  g_game_state
    .4byte  car_select_setup
.L_pool_06008BC4:
    .4byte  sym_06026CE0
.L_pool_06008BC8:
    .4byte  sym_06059F44
    .4byte  sym_0605A016
.L_pool_06008BD0:
    .4byte  FUN_06019A48
.L_pool_06008BD4:
    .4byte  FUN_06019928
