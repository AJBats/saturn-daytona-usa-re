
    .section .text.FUN_06038F78


    .global vblank_display_write
    .type vblank_display_write, @function
vblank_display_write:
    sts.l pr, @-r15
    mov.l   .L_fn_scene_dispatch, r11
    mov.l   .L_ptr_cmd_state, r12
    mov.l   .L_ptr_game_state, r13
    mov.l   .L_ptr_frame_counter, r14
    mov.l r10, @r12
    mov.l   .L_ptr_fb_mode_sel, r4
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_check_mode3
    mov.l @r13, r0
    tst r0, r0
    bt      .L_epilogue
    jsr @r11
    nop
    mov #0x2, r3
    mov.l r3, @r12
    bra     .L_epilogue
    nop
.L_check_mode3:
    mov.l   .L_ptr_fbcr_shadow, r6
    mov.l   .L_vdp1_fbcr, r5
    mov.w @r4, r0
    extu.w r0, r0
    cmp/eq #0x3, r0
    bf      .L_check_mode0
    mov.l @r13, r0
    tst r0, r0
    bt      .L_epilogue
    mov.l   .L_ptr_tvmr_shadow, r0
    mov.l   .L_vdp1_tvmr, r3
    mov.w @r0, r0
    extu.w r0, r0
    or #0x8, r0
    mov.w r0, @r3
    mov.w @r6, r0
    extu.w r0, r0
    or #0x3, r0
    jsr @r11
    mov.w r0, @r5
    mov #0x3, r3
    mov.l r3, @r12
    bra     .L_epilogue
    nop
.L_check_mode0:
    mov.w @r4, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_mode1_fbswap
    jsr @r11
    nop
    bra     .L_epilogue
    mov.l r10, @r13
.L_fn_scene_dispatch:
    .4byte  scene_data_dispatch
.L_ptr_cmd_state:
    .4byte  sym_060A4C84
.L_ptr_game_state:
    .4byte  sym_060635C4
.L_ptr_frame_counter:
    .4byte  sym_060635C0
.L_ptr_fb_mode_sel:
    .4byte  sym_060635B4
.L_ptr_fbcr_shadow:
    .4byte  sym_060A4C92
.L_vdp1_fbcr:
    .4byte  0x25D00002                  /* VDP1 FBCR — framebuffer control */
.L_ptr_tvmr_shadow:
    .4byte  sym_060A4C90
.L_vdp1_tvmr:
    .4byte  0x25D00000                  /* VDP1 TVMR — TV mode */
.L_mode1_fbswap:
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
    .byte   0xD0, 0x1F    /* mov.l .L_pool_06039088, r0 — &fb_swap_enable (sym_060635B8, cross-TU pool) */
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_check_delay
    .byte   0xD2, 0x1E    /* mov.l .L_pool_0603908C, r2 — &fb_swap_delay (sym_060635BC, cross-TU pool) */
    mov.l @r14, r3
    mov.l @r2, r2
    add #-0x1, r2
    cmp/gt r3, r2
    bt      .L_check_delay
    mov.w @r6, r0
    extu.w r0, r0
    or #0x2, r0
    extu.w r0, r0
    mov.w r0, @r5
.L_check_delay:
    .byte   0xD3, 0x18    /* mov.l .L_pool_0603908C, r3 — &fb_swap_delay (sym_060635BC, cross-TU pool) */
    mov.l @r14, r2
    mov.l @r3, r3
    cmp/gt r2, r3
    bt      .L_epilogue
    mov.l @r13, r0
    tst r0, r0
    bt      .L_reset_counter
    jsr @r11
    nop
    mov #0x1, r3
    mov.l r3, @r12
.L_reset_counter:
    mov.l r10, @r14
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
