
    .section .text.FUN_06039250


    .global vdp2_scroll_update
    .type vdp2_scroll_update, @function
vdp2_scroll_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r4, r14
    stc sr, r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov r0, r13
    stc sr, r0
    mov.w   DAT_060392e6, r3
    and r3, r0
    or #0xF0, r0
    ldc r0, sr
    bsr     .L_interlace_flag_set
    mov #0x0, r4
    mov #0x0, r6
    mov #0x0, r5
    bsr     polygon_param_setup
    mov #0x0, r4
    mov.l   .L_fbcr_cached, r2
    mov #0x0, r6
    mov.l   .L_vdp1_fbcr, r3
    mov.w @r2, r2
    mov.w r2, @r3
    mov #0x2, r2
    mov.l   .L_vdp1_ptmr, r3
    mov.w r2, @r3
    mov.l   .L_erase_color, r2
    mov.l   .L_vdp1_ewdr, r3
    mov.w r2, @r3
    mov #0x0, r2
    mov.l   .L_vdp1_ewlr, r3
    mov.w r2, @r3
    mov.l   .L_erase_lower_right, r2
    mov.l   .L_vdp1_ewrr, r3
    mov.w r2, @r3
    mov.l   .L_display_height, r2
    mov.l @r2, r2
    add #-0x1, r2
    extu.w r2, r2
    mov.l r2, @-r15
    mov.l   .L_display_width, r7
    mov.l   .L_erase_color, r4
    mov.l @r7, r7
    add #-0x1, r7
    extu.w r7, r7
    bsr     sym_060393FC
    mov #0x0, r5
    add #0x4, r15
    mov.l   .L_vdp1_vram_base, r2
    mov.l r2, @r14
    mov r2, r3
    mov.w   .L_cmd_byte_0x80, r2
    mov.b r2, @r3
    mov.l @r14, r3
    add #0x1, r3
    mov #0x0, r2
    mov.b r2, @r3
    mov r13, r0
    and #0xF, r0
    shll2 r0
    shll2 r0
    stc sr, r3
    mov.w   DAT_060392e6, r2
    and r2, r3
    or r3, r0
    ldc r0, sr
    mov #0x1, r3
    mov.l   .L_frame_ready_flag, r2
    mov.l r3, @r2
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_060392e6
DAT_060392e6:
    .2byte  0xFF0F                      /* SR mask: clear IRQ level bits */
.L_cmd_byte_0x80:
    .2byte  0x0080                      /* VDP1 VRAM cmd byte 0: 0x80 (normal sprite) */
    .2byte  0xFFFF                      /* alignment padding */
.L_fbcr_cached:
    .4byte  sym_060A4C92               /* cached FBCR / interlace value */
.L_vdp1_fbcr:
    .4byte  0x25D00002                  /* VDP1 FBCR -- framebuffer control */
.L_vdp1_ptmr:
    .4byte  0x25D00004                  /* VDP1 PTMR -- plot trigger */
.L_erase_color:
    .4byte  0x00008000                  /* erase fill: 0x8000 (black in RGB555) */
.L_vdp1_ewdr:
    .4byte  0x25D00006                  /* VDP1 EWDR -- erase fill color */
.L_vdp1_ewlr:
    .4byte  0x25D00008                  /* VDP1 EWLR -- erase upper-left */
.L_erase_lower_right:
    .4byte  0x0000FFFF                  /* default lower-right (full screen) */
.L_vdp1_ewrr:
    .4byte  0x25D0000A                  /* VDP1 EWRR -- erase lower-right */
.L_display_height:
    .4byte  sym_060A4C8C               /* cached display height */
.L_display_width:
    .4byte  sym_060A4C88               /* cached display width */
.L_vdp1_vram_base:
    .4byte  0x25C00000                  /* VDP1 VRAM base address */
.L_frame_ready_flag:
    .4byte  sym_060635CC               /* frame-ready flag (1 = setup complete) */

    .global polygon_param_setup
    .type polygon_param_setup, @function
polygon_param_setup:
    mov.l r14, @-r15
    extu.w r4, r1
    mov #0x7, r3
    mov.l   .L_cached_height_b, r14
    mov.l   .L_cached_tvmr, r2
    and r1, r3
    mov.w r3, @r2
    mov.l   .L_vdp1_tvmr, r2
    mov.w r3, @r2
    extu.w r5, r3
    mov #0x7, r2
    cmp/gt r2, r3
    bf/s    .L_res_index_valid
    mov #0x0, r7
    extu.w r7, r5
.L_res_index_valid:
    extu.w r5, r4
    mov.l   .L_res_table, r3
    shll2 r4
    add r3, r4
    mov.w @r4, r2
    mov.l   .L_cached_width_b, r3
    mov.l r2, @r3
    mov.w @(2, r4), r0
    mov r0, r2
    mov.l r0, @r14
    extu.w r6, r0
    cmp/eq #0x1, r0
    bf      .L_no_interlace_double
    mov.l @r14, r2
    shll r2
    mov.l r2, @r14
.L_no_interlace_double:
    mov r1, r0
    cmp/eq #0x1, r0
    bt      .L_set_hires_flag
    mov r1, r0
    cmp/eq #0x3, r0
    bf      .L_clear_hires_flag
.L_set_hires_flag:
    mov #0x1, r3
    mov.l   .L_hires_flag, r2
    mov.w r3, @r2
    bra     .L_check_highcolor
    nop
.L_clear_hires_flag:
    extu.w r7, r2
    mov.l   .L_hires_flag, r3
    mov.w r2, @r3
.L_check_highcolor:
    extu.w r6, r6
    tst r6, r6
    bt      .L_no_highcolor
    mov #0x8, r3
    mov.l   .L_highcolor_flag, r2
    mov.w r3, @r2
    bra     .L_clear_reserved
    nop
.L_no_highcolor:
    extu.w r7, r2
    mov.l   .L_highcolor_flag, r3
    mov.w r2, @r3
.L_clear_reserved:
    extu.w r7, r2
    mov.l   .L_reserved_param, r3
    mov.w r2, @r3
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_cached_height_b:
    .4byte  sym_060A4C8C               /* cached display height */
.L_cached_tvmr:
    .4byte  sym_060A4C90               /* cached TVMR value */
.L_vdp1_tvmr:
    .4byte  0x25D00000                  /* VDP1 TVMR -- TV mode */
.L_res_table:
    .4byte  sym_060635E0               /* resolution table (8 entries: W,H) */
.L_cached_width_b:
    .4byte  sym_060A4C88               /* cached display width */
.L_hires_flag:
    .4byte  sym_060635DE               /* high-res mode flag */
.L_highcolor_flag:
    .4byte  sym_060A4C94               /* high-color interlace enable */
.L_reserved_param:
    .4byte  sym_060A4C96               /* reserved display parameter */
    .4byte  0xD31C6331
    .4byte  0x2431D21C
    .4byte  0x6222622D
    .4byte  0x60238141
    .4byte  0xD31A6332
    .4byte  0x633D6033
    .4byte  0x8142D319
    .4byte  0x63316033
    .4byte  0x8143D318
    .4byte  0x63316033
    .4byte  0x8144D317
    .4byte  0x63316033
    .4byte  0x8145D316
    .4byte  0x63316033
    .4byte  0x8146D315
    .4byte  0x63316033
    .4byte  0x000B8147

    .global sym_060393FC
sym_060393FC:
    mov.w @(2, r15), r0
    mov.l   .L_ew_color_var, r3
    mov r0, r1
    mov.w r4, @r3
    mov.l   .L_ew_top_y, r3
    mov.w r5, @r3
    mov.l   .L_ew_top_x, r3
    mov.w r6, @r3
    mov.l   .L_ew_bot_x, r3
    mov.w r7, @r3
    mov.l   .L_ew_bot_y, r3
    mov.w r1, @r3
    mov.l   .L_vdp1_ewdr_b, r3
    mov.w r4, @r3
    mov.l   .L_hires_flag_b, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_top_y_normal
    extu.w r5, r5
    shlr2 r5
    bra     .L_check_interlace_top
    shlr2 r5
    .2byte  0xFFFF
    .4byte  sym_060635B4               /* VDP framebuffer mode selector (unreferenced pool) */
    .4byte  sym_060635B8               /* framebuffer swap enable (unreferenced pool) */
    .4byte  sym_060635BC               /* framebuffer swap delay (unreferenced pool) */
.L_ew_color_var:
    .4byte  sym_060635D4               /* erase window color working var */
.L_ew_top_y:
    .4byte  sym_060635D6               /* erase window top-left Y */
.L_ew_top_x:
    .4byte  sym_060635D8               /* erase window top-left X */
.L_ew_bot_x:
    .4byte  sym_060635DA               /* erase window bottom-right X */
.L_ew_bot_y:
    .4byte  sym_060635DC               /* erase window bottom-right Y */
.L_vdp1_ewdr_b:
    .4byte  0x25D00006                  /* VDP1 EWDR -- erase fill color */
.L_hires_flag_b:
    .4byte  sym_060635DE               /* high-res mode flag */
.L_top_y_normal:
    extu.w r5, r5
    shlr2 r5
    shlr r5
.L_check_interlace_top:
    mov.l   .L_highcolor_interlace, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_top_x_normal
    extu.w r6, r6
    shlr r6
.L_top_x_normal:
    extu.w r5, r5
    extu.w r6, r6
    mov.l   .L_ewlr_working, r3
    shll8 r5
    shll r5
    add r6, r5
    extu.w r5, r5
    mov.w r5, @r3
    mov.l   .L_ewlr_working, r2
    mov.l   .L_vdp1_ewlr_b, r3
    mov.w @r2, r2
    mov.w r2, @r3
    mov.l   .L_hires_flag_c, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt/s    .L_bot_x_normal
    add #0x1, r7
    extu.w r7, r7
    shlr2 r7
    bra     .L_check_interlace_bot
    shlr2 r7
.L_bot_x_normal:
    extu.w r7, r7
    shlr2 r7
    shlr r7
.L_check_interlace_bot:
    mov.l   .L_highcolor_interlace, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_bot_y_normal
    extu.w r1, r1
    shlr r1
.L_bot_y_normal:
    extu.w r7, r7
    extu.w r1, r1
    mov.l   .L_ewrr_working, r3
    shll8 r7
    shll r7
    add r1, r7
    extu.w r7, r7
    mov.w r7, @r3
    mov.l   .L_ewrr_working, r2
    mov.l   .L_vdp1_ewrr_b, r3
    mov.w @r2, r2
    rts
    mov.w r2, @r3

    .global sym_060394C2
sym_060394C2:
    mov.l   .L_vdp1_edsr, r5
    mov #0x2, r4
.L_poll_edsr:
    mov.w @r5, r2
    extu.w r2, r2
    and r4, r2
    tst r2, r2
    bt      .L_poll_edsr
    rts
    nop
.L_highcolor_interlace:
    .4byte  sym_060A4C94               /* high-color interlace enable */
.L_ewlr_working:
    .4byte  sym_060635D0               /* EWLR packed working value */
.L_vdp1_ewlr_b:
    .4byte  0x25D00008                  /* VDP1 EWLR -- erase upper-left */
.L_hires_flag_c:
    .4byte  sym_060635DE               /* high-res mode flag */
.L_ewrr_working:
    .4byte  sym_060635D2               /* EWRR packed working value */
.L_vdp1_ewrr_b:
    .4byte  0x25D0000A                  /* VDP1 EWRR -- erase lower-right */
.L_vdp1_edsr:
    .4byte  0x25D00010                  /* VDP1 EDSR -- draw end status */
.L_interlace_flag_set:
    tst r4, r4
    bt      .L_clear_interlace
    mov #0x10, r3
    mov.l   .L_interlace_cached, r2
    mov.w r3, @r2
    bra     .L_interlace_done
    nop
.L_clear_interlace:
    mov #0x0, r2
    mov.l   .L_interlace_cached, r3
    mov.w r2, @r3
.L_interlace_done:
    rts
    nop
.L_interlace_cached:
    .4byte  sym_060A4C92               /* cached FBCR / interlace flag */
