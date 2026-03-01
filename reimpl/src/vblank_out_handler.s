

    .section .text.FUN_06007268


    .global vblank_out_handler
    .type vblank_out_handler, @function
vblank_out_handler:
    sts.l pr, @-r15
    mov.l   .L_pool_vblank_out_ctr, r3
    mov.l   .L_pool_vblank_out_ctr, r2
    mov.l @r3, r3
    add #0x1, r3
    mov.l r3, @r2
    mov #0x3, r3
    mov.l   .L_pool_phase_flag, r2
    mov.l r3, @r2
    mov.l   .L_pool_viewport_calc, r3
    jsr @r3
    nop
    mov.l   .L_pool_game_state, r2
    mov.l   .L_pool_frame_targets, r3
    mov.l   .L_pool_vblank_out_ctr, r1
    mov.l @r2, r2
    mov.l @r1, r1
    add r3, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r2, r1
    bt      .check_swap
    bra     .done
    nop
.check_swap:
    mov.l   .L_pool_display_mode, r5
    mov.l @r5, r0
    tst r0, r0
    bt      .done
    mov.l   .L_pool_fbcr_shadow, r0
    mov.w @r0, r0
    extu.w r0, r0
    or #0x3, r0
    extu.w r0, r0
    mov.l   .L_vdp1_fbcr, r3
    mov.w r0, @r3
    mov #0x0, r4
    mov.l   .L_pool_frame_ready, r3
    mov.l r4, @r3
    mov.l r4, @r5
.done:
    mov #0x4, r2
    mov.l   .L_pool_phase_flag, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
.L_pool_vblank_out_ctr:
    .4byte  sym_06059F44
.L_pool_phase_flag:
    .4byte  sym_06059F54
.L_pool_viewport_calc:
    .4byte  controller_input_update
.L_pool_game_state:
    .4byte  g_game_state
.L_pool_frame_targets:
    .4byte  sym_06059F58
.L_pool_display_mode:
    .4byte  sym_06063F58
.L_pool_fbcr_shadow:
    .4byte  sym_060A4C92
.L_vdp1_fbcr:
    .4byte  0x25D00002                  /* VDP1 FBCR — framebuffer control */
.L_pool_frame_ready:
    .4byte  sym_060635C4

    .global sym_060072E4
sym_060072E4:
    mov.l r15, @-r15
