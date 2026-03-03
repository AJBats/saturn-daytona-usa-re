

    .section .text.FUN_06007268


    .global vblank_out_handler
    .type vblank_out_handler, @function
vblank_out_handler:
    sts.l pr, @-r15
    mov.l   .L_pool_060072C0, r3
    mov.l   .L_pool_060072C0, r2
    mov.l @r3, r3
    add #0x1, r3
    mov.l r3, @r2
    mov #0x3, r3
    mov.l   .L_pool_060072C4, r2
    mov.l r3, @r2
    mov.l   .L_pool_060072C8, r3
    jsr @r3
    nop
    mov.l   .L_pool_060072CC, r2
    mov.l   .L_pool_060072D0, r3
    mov.l   .L_pool_060072C0, r1
    mov.l @r2, r2
    mov.l @r1, r1
    add r3, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r2, r1
    bt      .L_06007298
    bra     .L_060072B6
    nop
.L_06007298:
    mov.l   .L_pool_060072D4, r5
    mov.l @r5, r0
    tst r0, r0
    bt      .L_060072B6
    mov.l   .L_pool_060072D8, r0
    mov.w @r0, r0
    extu.w r0, r0
    or #0x3, r0
    extu.w r0, r0
    mov.l   .L_060072DC, r3
    mov.w r0, @r3
    mov #0x0, r4
    mov.l   .L_pool_060072E0, r3
    mov.l r4, @r3
    mov.l r4, @r5
.L_060072B6:
    mov #0x4, r2
    mov.l   .L_pool_060072C4, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
.L_pool_060072C0:
    .4byte  sym_06059F44
.L_pool_060072C4:
    .4byte  sym_06059F54
.L_pool_060072C8:
    .4byte  controller_input_update
.L_pool_060072CC:
    .4byte  g_game_state
.L_pool_060072D0:
    .4byte  sym_06059F58
.L_pool_060072D4:
    .4byte  sym_06063F58
.L_pool_060072D8:
    .4byte  sym_060A4C92
.L_060072DC:
    .4byte  0x25D00002
.L_pool_060072E0:
    .4byte  sym_060635C4

    .global sym_060072E4
sym_060072E4:
    mov.l r15, @-r15
