
    .section .text.FUN_06008C76


    .global state_memory_route
    .type state_memory_route, @function
state_memory_route:
    sts.l pr, @-r15
    .byte   0xD3, 0x10    /* mov.l .L_pool_06008CBC, r3 */
    jsr @r3
    nop
    tst r0, r0
    bt      .L_06008CAC
    .byte   0xD4, 0x0F    /* mov.l .L_pool_06008CC0, r4 */
    .byte   0xD0, 0x0B    /* mov.l .L_pool_06008CB4, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_06008CA2
    mov #0x4, r3
    mov.l r3, @r4
    .byte   0xD3, 0x0C    /* mov.l .L_pool_06008CC4, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x0B    /* mov.l .L_pool_06008CC8, r3 */
    jsr @r3
    nop
    bra     .L_06008CA6
    nop
.L_06008CA2:
    mov #0x6, r2
    mov.l r2, @r4
.L_06008CA6:
    mov #0x0, r3
    .byte   0xD2, 0x02    /* mov.l .L_pool_06008CB4, r2 */
    mov.b r3, @r2
.L_06008CAC:
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xFFFF
.L_pool_06008CBA:
    .4byte  sym_0605E0A2                  /* preview_camera_flag (byte) */
    .4byte  sym_0605A016                  /* display_mode (16-bit, fb resolution selector) */
.L_pool_06008CC2:
    .4byte  geom_output_dispatch          /* VDP2 status check / geometry dispatch */
.L_pool_06008CC6:
    .4byte  g_game_state                  /* game_state_dispatch (32-bit) */
.L_pool_06008CCA:
    .4byte  sym_060149E0                  /* disable_display -- clear bit 15 */
.L_pool_06008CCE:
    .4byte  sym_06026CE0                  /* camera_finalize -- render/display update */
