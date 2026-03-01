
    .section .text.FUN_06007370


    .global main_loop_timing
    .type main_loop_timing, @function
main_loop_timing:
    sts.l pr, @-r15
    mov.l   .L_display_table, r14
    mov.l   .L_config_store, r2
    mov.l r3, @r2
    mov.w   DAT_06007412, r3
    mov.l   .L_timing_constant, r2
    mov.l r3, @r2
    mov.l   .L_fn_scroll_update, r3
    jsr @r3
    mov r14, r4
    mov #0x0, r6
    mov #0x2, r5
    mov.l   .L_fn_polygon_setup, r3
    jsr @r3
    mov r6, r4
    mov #0x0, r6
    mov.w   DAT_06007414, r2
    mov r6, r5
    mov.l r2, @-r15
    mov.w   DAT_06007416, r7
    mov.l   .L_fn_screen_coord, r3
    jsr @r3
    mov r6, r4
    mov.l   .L_mask_low16, r4
    mov.l   .L_fn_display_param, r3
    jsr @r3
    add #0x4, r15
    mov.l   .L_fn_display_init, r3
    jsr @r3
    nop
    mov.w   .L_tile_copy_size, r6
    mov.l   .L_tile_data_src, r5
    mov.l   .L_tile_index, r4
    mov.l @r14, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r3, r4
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3
    nop
    mov.l   .L_display_mode_flags, r0
    mov.l @r0, r0
    tst #0x1, r0
    bt      .L_060073E2
    mov.w   .L_tile_copy_size_b, r6
    mov.l   .L_tile_data_src_b, r5
    mov.l   .L_tile_index, r4
    mov.l @r14, r3
    mov.w   .L_tile_offset_b, r2
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r3, r4
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3
    add r2, r4
.L_060073E2:
    mov #0x60, r6
    mov.l   .L_dma_dest, r5
    mov.l   .L_fn_dma_transfer, r3
    jsr @r3
    mov.l @r14, r4
    mov #0x3, r2
    mov.l   .L_display_mode, r3
    mov.l r2, @r3
    mov.l @r14, r2
    mov.l   .L_fp_half, r3
    add #0x60, r2
    mov.w r3, @r2
    mov.l   .L_fn_scene_setup, r3
    jsr @r3
    nop
    mov.l   .L_scene_data_dest, r5
    mov.l   .L_scene_tile_src, r4
    mov.l   .L_fn_dma_memory, r3
    jsr @r3
    nop
    lds.l @r15+, pr
    mov.l   .L_fn_camera_finalize, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_06007412
DAT_06007412:
    .2byte  0x2468                        /* timing/scroll constant */

    .global DAT_06007414
DAT_06007414:
    .2byte  0x00DF                        /* 223 = screen bottom Y coordinate */

    .global DAT_06007416
DAT_06007416:
    .2byte  0x015F                        /* 351 = screen right X coordinate */
.L_tile_copy_size:
    .2byte  0x03C0                        /* primary tile copy: 960 bytes */
.L_tile_copy_size_b:
    .2byte  0x0080                        /* secondary tile copy: 128 bytes */
.L_tile_offset_b:
    .2byte  0x0300                        /* secondary tile destination offset */
    .2byte  0xFFFF
.L_display_table:
    .4byte  sym_06063F5C               /* display/scroll base table (ptr) */
.L_config_store:
    .4byte  sym_0606A4F4               /* config parameter store (32-bit) */
.L_timing_constant:
    .4byte  sym_0606A4EC               /* timing register (32-bit) */
.L_fn_scroll_update:
    .4byte  vdp2_scroll_update         /* VDP2 scroll position update */
.L_fn_polygon_setup:
    .4byte  polygon_param_setup        /* polygon rendering parameter setup */
.L_fn_screen_coord:
    .4byte  sym_060393FC               /* screen coordinate bounds setup */
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_fn_display_param:
    .4byte  display_param_set          /* display parameter configuration */
.L_fn_display_init:
    .4byte  sym_06012E00               /* display initialization */
.L_tile_data_src:
    .4byte  0x002A0000                  /* primary tile data source address */
.L_tile_index:
    .4byte  sym_06059FFC               /* tile index value (ptr, *8 for offset) */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx            /* word-indexed memory copy */
.L_display_mode_flags:
    .4byte  sym_0607EAB8               /* display mode flags (bit 0 = extended) */
.L_tile_data_src_b:
    .4byte  sym_06059F78               /* secondary tile data source */
.L_dma_dest:
    .4byte  sym_0605A018               /* DMA destination address */
.L_fn_dma_transfer:
    .4byte  dma_transfer               /* SCU DMA transfer */
.L_display_mode:
    .4byte  sym_0605A008               /* display mode state (32-bit) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 / 0x8000 (scroll midpoint) */
.L_fn_scene_setup:
    .4byte  scene_setup_master         /* master scene setup */
.L_scene_data_dest:
    .4byte  sym_0606B178               /* scene data DMA destination */
.L_scene_tile_src:
    .4byte  0x002A3457                  /* scene tile data source address */
.L_fn_dma_memory:
    .4byte  dma_memory_transfer        /* DMA memory transfer */
.L_fn_camera_finalize:
    .4byte  sym_06026CE0               /* camera state finalization */
