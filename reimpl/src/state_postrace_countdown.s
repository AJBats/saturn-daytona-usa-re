
    .section .text.FUN_06009E02


    .global state_postrace_countdown
    .type state_postrace_countdown, @function
state_postrace_countdown:
    sts.l pr, @-r15
    .byte   0xD4, 0x0E    /* mov.l .L_pool_06009E46, r4 */
    mov.l @r4, r3
    add #-0x1, r3
    tst r3, r3
    bf/s    .L_countdown_not_expired
    mov.l r3, @r4
    mov #0x1E, r3
    .byte   0xD2, 0x0A    /* mov.l .L_pool_06009E42, r2 */
    mov.l r3, @r2
.L_countdown_not_expired:
    .byte   0xD3, 0x0F    /* mov.l .L_pool_06009E5A, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x07    /* mov.l .L_pool_06009E42, r0 */
    mov.l @r0, r0
    cmp/eq #0x1B, r0
    bt      .L_skip_handler_init
    .byte   0xD3, 0x0C    /* mov.l .L_pool_06009E5E, r3 */
    jsr @r3
    nop
.L_skip_handler_init:
    mov #0x1, r2
    .byte   0xD3, 0x0B    /* mov.l .L_pool_06009E62, r3 */
    lds.l @r15+, pr
    rts
    mov.b r2, @r3
    .4byte  0x0258FFFF
    .4byte  race_variant_a
.L_pool_06009E42:
    .4byte  g_game_state
.L_pool_06009E46:
    .4byte  sym_0607EBCC
    .4byte  sym_06028560
    .4byte  game_init_master
    .4byte  sym_0605A016
    .4byte  handler_dispatch
.L_pool_06009E5A:
    .4byte  gfx_frame_dispatch
.L_pool_06009E5E:
    .4byte  handler_init_reset
.L_pool_06009E62:
    .4byte  sym_0607864B
