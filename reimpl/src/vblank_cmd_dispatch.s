
    .section .text.FUN_06039050


    .global vblank_cmd_dispatch
    .type vblank_cmd_dispatch, @function
vblank_cmd_dispatch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_vdp1_fbcr, r12
    mov.l   .L_pool_fbcr_shadow, r13
    mov.l   .L_pool_cmd_state, r14
    mov.l   .L_pool_interlace_enable, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_dispatch_cmd
    mov.l   .L_pool_vdp2_tvstat, r4
    mov.w @r4, r4
    extu.w r4, r0
    tst #0x2, r0
    bt      .L_even_field
    mov.w @r13, r0
    extu.w r0, r0
    bra     .L_write_fbcr
    or #0xC, r0
.L_even_field:
    mov.w @r13, r0
    extu.w r0, r0
    or #0x8, r0
.L_write_fbcr:
    extu.w r0, r0
    bra     .L_epilogue
    mov.w r0, @r12
    .2byte  0xFFFF
    .4byte  sym_060635B8
    .4byte  sym_060635BC
.L_pool_vdp1_fbcr:
    .4byte  0x25D00002                  /* VDP1 FBCR — framebuffer control */
.L_pool_fbcr_shadow:
    .4byte  sym_060A4C92
.L_pool_cmd_state:
    .4byte  sym_060A4C84
.L_pool_interlace_enable:
    .4byte  sym_060A4C94
.L_pool_vdp2_tvstat:
    .4byte  0x25F80004                  /* VDP2 TVSTAT — TV status */
.L_dispatch_cmd:
    mov.l @r14, r0
    tst r0, r0
    bt      .L_epilogue
    mov.l @r14, r0
    cmp/eq #0x2, r0
    bf      .L_not_cmd2
    mov.l   .L_pool_frame_ready, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_not_cmd2
    mov.l   .L_pool_draw_end_wait, r3
    jsr @r3
    nop
.L_not_cmd2:
    mov.l @r14, r0
    cmp/eq #0x3, r0
    bf      .L_default_fbcr_write
    mov.l   .L_pool_tvmr_shadow, r3
    mov.w @r3, r3
    mov.l   .L_pool_vdp1_tvmr, r2
    mov.w r3, @r2
    bra     .L_clear_state
    nop
.L_default_fbcr_write:
    mov.w @r13, r0
    extu.w r0, r0
    or #0x3, r0
    extu.w r0, r0
    mov.w r0, @r12
.L_clear_state:
    mov #0x0, r4
    mov.l   .L_pool_game_state, r3
    mov.l r4, @r3
    mov.l r4, @r14
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_frame_ready:
    .4byte  sym_060635CC
.L_pool_draw_end_wait:
    .4byte  sym_060394C2
.L_pool_tvmr_shadow:
    .4byte  sym_060A4C90
.L_pool_vdp1_tvmr:
    .4byte  0x25D00000                  /* VDP1 TVMR — TV mode */
.L_pool_game_state:
    .4byte  sym_060635C4
