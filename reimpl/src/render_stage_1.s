
    .section .text.FUN_0601C978


    .global render_stage_1
    .type render_stage_1, @function
render_stage_1:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov #0x0, r13
    add #-0x4, r15
    mov.l   .L_p_palette_intensity, r14
    mov.l   .L_p_render_state_var, r3
    mov.l r13, @r3
    mov.l   .L_p_render_cycle_flag, r3
    mov.b r13, @r3
    mov.w   DAT_0601ca3a, r1
    mov.l   .L_fn_display_disable, r3
    jsr @r3
    mov.w r1, @r14
    mov.l   .L_fn_channels_clear, r3
    jsr @r3
    nop
    mov.l   .L_fn_display_update, r3
    jsr @r3
    nop
    mov.l   .L_p_state_tracker, r3
    mov.l r13, @r3
    mov.l   .L_fn_audio_display_init, r3
    jsr @r3
    nop
    mov.w   DAT_0601ca3c, r2
    mov.l   .L_p_frame_countdown, r3
    mov.l r2, @r3
    mov.l   .L_p_stage_counter, r3
    mov.l r13, @r3
    mov.l   .L_p_dma_pending, r3
    mov.l r13, @r3
    mov.l   .L_vdp2_cram_0x200, r5
    mov #0x20, r4
.L_cram_copy_bank1:
    mov.w @r14, r3
    add #-0x2, r4
    mov.w r3, @r5
    add #0x2, r5
    mov.w @r14, r3
    mov r5, r2
    add #0x2, r5
    tst r4, r4
    bf/s    .L_cram_copy_bank1
    mov.w r3, @r2
    mov.l   .L_vdp2_cram_0x400, r5
    mov #0x20, r4
.L_cram_copy_bank2:
    mov.w @r14, r2
    add #-0x2, r4
    mov.w r2, @r5
    add #0x2, r5
    mov.w @r14, r2
    mov r5, r3
    add #0x2, r5
    tst r4, r4
    bf/s    .L_cram_copy_bank2
    mov.w r2, @r3
    mov.l   .L_palette_src_cram0, r5
    mov.l   .L_vdp2_cram_0x000, r4
    mov.l   .L_fn_dma_transfer, r3
    jsr @r3
    mov #0x40, r6
    mov #0x9, r7
    mov.l   .L_tile_src_a, r5
    mov.l   .L_vdp2_vram_0x70E40, r4
    mov.l   .L_fn_vram_tile_copy, r3
    jsr @r3
    mov #0x0, r6
    mov #0x9, r7
    mov.l   .L_tile_src_b, r5
    mov.l   .L_vdp2_vram_0x7B168, r4
    mov.l   .L_fn_vram_tile_copy, r3
    jsr @r3
    mov #0x0, r6
    mov.l   .L_p_scroll_config_a, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_w_scroll_extent, r6
    mov.l   .L_fn_scroll_setup, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    mov.l   .L_p_scroll_config_b, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_w_scroll_extent, r6
    mov.l   .L_fn_scroll_setup, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x0, r4
    mov.l   .L_fn_channel_nibble_cfg, r13
    mov.w   .L_w_channel_init_mask, r4
    bra     .L_channel_config_loop
    mov #0x0, r5

    .global DAT_0601ca3a
DAT_0601ca3a:
    .2byte  0x77BD                              /* initial palette intensity value */

    .global DAT_0601ca3c
DAT_0601ca3c:
    .2byte  0x012C                              /* 300 — frame countdown initial value */
.L_w_scroll_extent:
    .2byte  0x0518                              /* 1304 — scroll extent / pixel range */
.L_w_channel_init_mask:
    .2byte  0x0100                              /* channel 8 mask (first nibble cfg call) */
    .2byte  0xFFFF                              /* alignment padding */
.L_p_palette_intensity:
    .4byte  sym_06086028                        /* &palette_intensity (word) */
.L_p_render_state_var:
    .4byte  sym_0608602C                        /* &render_state_var (long) */
.L_p_render_cycle_flag:
    .4byte  sym_06086030                        /* &render_cycle_flag (byte) */
.L_fn_display_disable:
    .4byte  sym_060149E0                        /* display_disable — clear bit 15 */
.L_fn_channels_clear:
    .4byte  display_channels_clear              /* clear all display channels */
.L_fn_display_update:
    .4byte  sym_06026CE0                        /* display_update — refresh display state */
.L_p_state_tracker:
    .4byte  sym_06059F44                        /* &state_tracker (long) */
.L_fn_audio_display_init:
    .4byte  audio_display_init                  /* audio + display subsystem init */
.L_p_frame_countdown:
    .4byte  sym_0608601C                        /* &frame_countdown (long) */
.L_p_stage_counter:
    .4byte  sym_06086020                        /* &stage_counter (long) */
.L_p_dma_pending:
    .4byte  sym_06086024                        /* &dma_pending_flag (long) */
.L_vdp2_cram_0x200:
    .4byte  0x25F00200                          /* VDP2 color RAM bank 1 (+0x200) */
.L_vdp2_cram_0x400:
    .4byte  0x25F00400                          /* VDP2 color RAM bank 2 (+0x400) */
.L_palette_src_cram0:
    .4byte  sym_0604880C                        /* palette source data for CRAM bank 0 DMA */
.L_vdp2_cram_0x000:
    .4byte  0x25F00000                          /* VDP2 color RAM bank 0 (+0x000) */
.L_fn_dma_transfer:
    .4byte  dma_transfer                        /* SCU DMA transfer function */
.L_tile_src_a:
    .4byte  0x00014000                          /* tile pattern source A (WRAM offset) */
.L_vdp2_vram_0x70E40:
    .4byte  0x25E70E40                          /* VDP2 VRAM tile dest A (+0x70E40) */
.L_fn_vram_tile_copy:
    .4byte  sym_0600511E                        /* vram_tile_copy — pattern data transfer */
.L_tile_src_b:
    .4byte  0x00016BC0                          /* tile pattern source B (WRAM offset) */
.L_vdp2_vram_0x7B168:
    .4byte  0x25E7B168                          /* VDP2 VRAM tile dest B (+0x7B168) */
.L_p_scroll_config_a:
    .4byte  sym_06063958                        /* &scroll_config_a struct (8 bytes) */
.L_fn_scroll_setup:
    .4byte  sym_06028400                        /* scroll_setup — configure scroll plane */
.L_p_scroll_config_b:
    .4byte  sym_06063960                        /* &scroll_config_b struct (8 bytes) */
.L_fn_channel_nibble_cfg:
    .4byte  channel_nibble_config               /* display channel nibble configurator */
.L_channel_config_loop:
    jsr @r13
    nop
    mov #0x1, r5
    jsr @r13
    mov #0x4, r4
    mov #0x2, r5
    jsr @r13
    mov #0x8, r4
    mov #0x0, r5
    jsr @r13
    mov #0x10, r4
    mov #0x0, r5
    jsr @r13
    mov #0x20, r4
    .byte   0xD6, 0x21    /* mov.l r6, sym_06086028 */
    .byte   0xD4, 0x22    /* mov.l r4, 0x25F00FFE */
    .byte   0xD3, 0x22    /* mov.l r3, tilemap_dma_update */
    jsr @r3
    mov #0x1, r5
    .byte   0xD4, 0x22    /* mov.l r4, sym_0605B6D8 */
    .byte   0xD2, 0x22    /* mov.l r2, 0x40000000 */
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    .byte   0xD3, 0x21    /* mov.l r3, sym_06026CE0 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x20    /* mov.l r3, sym_06059F44 */
    mov.l r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
