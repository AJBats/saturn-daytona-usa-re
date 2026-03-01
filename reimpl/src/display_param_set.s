
    .section .text.FUN_06038E54


    .global display_param_set
    .type display_param_set, @function
display_param_set:
    mov.l r14, @-r15
    extu.w r4, r3
    mov.l r13, @-r15
    mov #0x3, r13
    mov.l r11, @-r15
    mov.l   .L_ptr_display_mode, r11
    mov.l   .L_ptr_fbcr_shadow, r14
    mov.l   .L_vdp1_fbcr, r7
    mov.l   .L_ptr_fb_mode_sel, r5
    mov.l   .L_ptr_swap_enable, r1
    mov.l   .L_mask_low16, r2
    cmp/eq r2, r3
    bf/s    .L_not_all_on
    mov #0x0, r6

    mov #0x2, r2
    mov.w r2, @r5
    mov.l r6, @r1
    mov.w @r14, r3
    extu.w r3, r3
    or r13, r3
    extu.w r3, r3
    mov.w r3, @r7
    extu.w r4, r4
    bra     .L_epilogue
    mov.l r4, @r11

.L_not_all_on:
    extu.w r4, r2
    mov.l   .L_const_fffe, r3
    cmp/eq r3, r2
    bf      .L_not_partial_on

    extu.w r13, r3
    mov.w r3, @r5
    mov.l r6, @r1
    mov.w @r14, r2
    extu.w r2, r2
    or r13, r2
    extu.w r2, r2
    mov.w r2, @r7
    extu.w r4, r4
    bra     .L_epilogue
    mov.l r4, @r11

.L_not_partial_on:
    extu.w r4, r2
    mov.w   DAT_06038efa, r3
    and r3, r2
    tst r2, r2
    bt      .L_swap_enable_set
    bra     .L_swap_done
    mov.l r6, @r1

.L_swap_enable_set:
    mov #0x1, r2
    mov.l r2, @r1

.L_swap_done:
    mov.w   DAT_06038efc, r3
    and r3, r4
    extu.w r4, r4
    tst r4, r4
    bt      .L_fb_mode_zero

    extu.w r4, r0
    cmp/eq #0x1, r0
    bf      .L_fb_mode_not_one
    bra     .L_write_fb_mode_sel
    extu.w r6, r2

.L_fb_mode_not_one:
    mov #0x1, r2

.L_write_fb_mode_sel:
    bra     .L_store_mode_and_check
    mov.w r2, @r5

.L_fb_mode_zero:
    extu.w r6, r2
    mov.w r2, @r5

.L_store_mode_and_check:
    extu.w r4, r4
    mov.l r4, @r11
    mov.w @r5, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_fbcr_set_manual

    mov.w @r14, r3
    mov.w r3, @r7
    bra     .L_epilogue
    nop

.L_fbcr_set_manual:
    mov.w @r14, r2
    extu.w r2, r2
    or r13, r2
    extu.w r2, r2
    mov.w r2, @r7

.L_epilogue:
    mov.l @r15+, r11
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06038efa
DAT_06038efa:
    .2byte  0x4000

    .global DAT_06038efc
DAT_06038efc:
    .2byte  0x7FFF
    .2byte  0xFFFF
.L_ptr_display_mode:
    .4byte  sym_060635BC
.L_ptr_fbcr_shadow:
    .4byte  sym_060A4C92
.L_vdp1_fbcr:
    .4byte  0x25D00002                  /* VDP1 FBCR — framebuffer control */
.L_ptr_fb_mode_sel:
    .4byte  sym_060635B4
.L_ptr_swap_enable:
    .4byte  sym_060635B8
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_const_fffe:
    .4byte  0x0000FFFE
    .4byte  0xD40DD00E
    .4byte  0x60022008
    .4byte  0x8904E301
    .4byte  0x24326042
    .4byte  0x20088BFC
    .4byte  0x000B0009

    .global sym_06038F34
sym_06038F34:
    mov #0x0, r4
    mov #0x1, r1
    mov.l   .L_rst_fb_mode_sel, r2
    mov.w r4, @r2
    mov.l   .L_rst_swap_enable, r2
    mov.l r1, @r2
    mov.l   .L_rst_display_mode, r2
    mov.l r4, @r2
    mov.l   .L_rst_frame_counter, r2
    mov.l r4, @r2
    mov.l   .L_rst_game_state, r2
    mov.l r4, @r2
    mov.l   .L_rst_display_ext, r2
    rts
    mov.l r4, @r2
    .2byte  0xFFFF
.L_rst_game_state:
    .4byte  sym_060635C4
.L_rst_display_mode:
    .4byte  sym_060635BC
.L_rst_fb_mode_sel:
    .4byte  sym_060635B4
.L_rst_swap_enable:
    .4byte  sym_060635B8
.L_rst_frame_counter:
    .4byte  sym_060635C0
.L_rst_display_ext:
    .4byte  sym_060635C8
