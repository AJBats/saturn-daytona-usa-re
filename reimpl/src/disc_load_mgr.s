
    .section .text.FUN_0601B170


    .global disc_load_mgr
    .type disc_load_mgr, @function
disc_load_mgr:
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_race_state_a, r3
    mov.l r8, @r3
    mov.w   DAT_0601b246, r2
    mov.l   .L_race_timer_init, r3
    mov.l r2, @r3
    mov.l   .L_car_array_base, r4
    mov.l   .L_fn_vdp2_scroll_update, r3
    jsr @r3
    nop
    mov r8, r6
    mov r8, r5
    mov.w   DAT_0601b248, r2
    mov.l r2, @-r15
    mov.w   DAT_0601b24a, r7
    mov.l   .L_fn_screen_coord_setup, r3
    jsr @r3
    mov r8, r4
    mov.l   .L_dma_config, r3
    mov.l r8, @r3
    mov.l   .L_car_array_base, r2
    mov.l   .L_fp_half, r3
    mov.l @r2, r2
    mov.w r3, @r2
    mov.l   .L_fn_cd_texture_load, r3
    jsr @r3
    nop
    mov.w   .L_memcpy_size, r6
    mov.l   .L_cdrom_base, r14
    mov.l   .L_game_state_index, r4
    mov.l   .L_car_array_base, r3
    mov.l   .L_fn_memcpy_word_idx, r2
    mov r14, r5
    mov.l @r4, r4
    mov.l @r3, r3
    shll2 r4
    shll r4
    jsr @r2
    add r3, r4
    mov.w   .L_spr_slot_a, r10
    mov #0x78, r6
    mov.l   .L_fn_vdp1_sprite, r12
    mov.w   .L_spr_size_param, r13
    mov.w   .L_cdrom_offset_a, r7
    mov r13, r5
    add r14, r7
    mov.l r7, @(12, r15)
    jsr @r12
    mov r10, r4
    mov.w   DAT_0601b254, r11
    mov #0x7C, r6
    mov r13, r5
    mov.w   DAT_0601b256, r7
    add r14, r7
    mov.l r7, @(4, r15)
    jsr @r12
    mov r11, r4
    mov.w   .L_spr_slot_c, r9
    mov r13, r5
    mov.w   DAT_0601b25a, r7
    add r14, r7
    mov.l r7, @(8, r15)
    mov.w   .L_spr_flags_small, r6
    jsr @r12
    mov r9, r4
    mov.l   .L_fn_obj_register, r14
    mov.w   DAT_0601b25e, r6
    mov.w   DAT_0601b260, r4
    jsr @r14
    mov r10, r5
    mov r11, r5
    mov.w   DAT_0601b262, r6
    mov r6, r4
    jsr @r14
    add #0x7D, r4
    mov.w   .L_obj_flags_c, r6
    mov r9, r5
    mov r6, r4
    jsr @r14
    add #0x7A, r4
    mov #0x78, r6
    mov r13, r5
    mov.l @(12, r15), r7
    jsr @r12
    mov r10, r4
    mov.l @(4, r15), r7
    mov #0x7C, r6
    mov r13, r5
    jsr @r12
    mov r11, r4
    mov r13, r5
    mov.l @(8, r15), r7
    mov.w   .L_spr_flags_small, r6
    jsr @r12
    mov r9, r4
    mov.w   DAT_0601b25e, r6
    mov.w   DAT_0601b260, r4
    jsr @r14
    mov r10, r5
    mov.w   DAT_0601b262, r6
    mov r11, r5
    mov r6, r4
    jsr @r14
    add #0x7D, r4
    bra     .L_second_pass
    nop

    .global DAT_0601b246
DAT_0601b246:
    .2byte  0x20D8                          /* timing init constant (8408 decimal) */

    .global DAT_0601b248
DAT_0601b248:
    .2byte  0x00DF                          /* screen height - 1 (223) */

    .global DAT_0601b24a
DAT_0601b24a:
    .2byte  0x015F                          /* screen width - 1 (351) */
.L_memcpy_size:
    .2byte  0x0640                          /* memcpy byte count (1600) */
.L_spr_slot_a:
    .2byte  0x0101                          /* VDP1 sprite slot A */
.L_spr_size_param:
    .2byte  0x0B40                          /* sprite dimension param */
.L_cdrom_offset_a:
    .2byte  0x4B46                          /* CD-ROM data offset for sprite A */

    .global DAT_0601b254
DAT_0601b254:
    .2byte  0x0102                          /* VDP1 sprite slot B */

    .global DAT_0601b256
DAT_0601b256:
    .2byte  0x5313                          /* CD-ROM data offset for sprite B */
.L_spr_slot_c:
    .2byte  0x0103                          /* VDP1 sprite slot C */

    .global DAT_0601b25a
DAT_0601b25a:
    .2byte  0x5B86                          /* CD-ROM data offset for sprite C */
.L_spr_flags_small:
    .2byte  0x0080                          /* small sprite type flags */

    .global DAT_0601b25e
DAT_0601b25e:
    .2byte  0x0084                          /* object flags for slot A */

    .global DAT_0601b260
DAT_0601b260:
    .2byte  0x0104                          /* object slot ID for A registration */

    .global DAT_0601b262
DAT_0601b262:
    .2byte  0x0088                          /* object flags for slot B */
.L_obj_flags_c:
    .2byte  0x008C                          /* object flags for slot C */
    .2byte  0xFFFF                          /* alignment padding */
.L_race_state_a:
    .4byte  sym_0606A4F4                    /* race state config parameter (32-bit) */
.L_race_timer_init:
    .4byte  sym_0606A4EC                    /* timing register (32-bit) */
.L_car_array_base:
    .4byte  sym_06063F5C                    /* car struct array base pointer */
.L_fn_vdp2_scroll_update:
    .4byte  vdp2_scroll_update              /* scroll plane setup function */
.L_fn_screen_coord_setup:
    .4byte  sym_060393FC                    /* screen coordinate bounds setup */
.L_dma_config:
    .4byte  sym_0605A008                    /* DMA configuration state word */
.L_fp_half:
    .4byte  0x00008000                      /* 0.5 (16.16 fixed-point) */
.L_fn_cd_texture_load:
    .4byte  sym_06012E00                    /* CD texture loader entry point */
.L_cdrom_base:
    .4byte  0x002A0000                      /* CD-ROM memory-mapped base address */
.L_game_state_index:
    .4byte  sym_06059FFC                    /* current game state index */
.L_fn_memcpy_word_idx:
    .4byte  memcpy_word_idx                 /* word-indexed memory copy */
.L_fn_vdp1_sprite:
    .4byte  vdp1_sprite_render              /* VDP1 sprite registration */
.L_fn_obj_register:
    .4byte  sym_06007540                    /* game object registration */
.L_second_pass:
    mov.w   DAT_0601b38a, r6
    mov r9, r5
    mov r6, r4
    jsr @r14
    add #0x7A, r4
    mov #0x78, r6
    mov r13, r5
    mov.l @(12, r15), r7
    jsr @r12
    mov r10, r4
    mov.l @(4, r15), r7
    mov #0x7C, r6
    mov r13, r5
    jsr @r12
    mov r11, r4
    mov r13, r5
    mov.l @(8, r15), r7
    mov.w   DAT_0601b38c, r6
    jsr @r12
    mov r9, r4
    mov.w   DAT_0601b38e, r6
    mov.w   DAT_0601b390, r4
    jsr @r14
    mov r10, r5
    mov.w   DAT_0601b392, r6
    mov r11, r5
    mov r6, r4
    jsr @r14
    add #0x7D, r4
    mov r9, r5
    mov.w   DAT_0601b38a, r6
    mov r6, r4
    jsr @r14
    add #0x7A, r4
    mov r8, r3
    mov.l   .L_vdp2_scroll_word, r2
    mov.w r3, @r2
    mov.l   .L_render_mode_flags, r13
    mov.l   .L_fp_min, r3
    mov.l @r13, r2
    or r3, r2
    mov.l   .L_fn_display_update, r3
    jsr @r3
    mov.l r2, @r13
    mov.l   .L_fn_display_update, r3
    jsr @r3
    nop
    mov.l   .L_palette_src_a, r5
    mov.l   .L_vdp2_cram_0x540, r4
    mov.l   .L_fn_dma_transfer, r3
    jsr @r3
    mov #0x40, r6
    mov.l   .L_palette_src_b, r5
    mov.l   .L_vdp2_cram_0x1A0, r4
    mov.l   .L_fn_dma_transfer, r3
    jsr @r3
    mov #0x20, r6
    mov #0x9, r7
    mov.l   .L_tile_size_a, r5
    mov.l   .L_vdp2_vram_0x6F9C4, r4
    mov.l   .L_fn_vram_tile_copy, r3
    jsr @r3
    mov r8, r6
    mov.l   .L_tilemap_src, r5
    mov.l   .L_vdp2_vram_0x75DDC, r4
    mov.l   .L_fn_dma_mem_transfer, r3
    add r8, r5
    jsr @r3
    mov.l r5, @(4, r15)
    mov r8, r6
    mov.l @(4, r15), r5
    mov.l   .L_dma_block_size, r7
    mov.l   .L_fn_display_list_load, r3
    jsr @r3
    mov #0x4, r4
    mov r8, r6
    mov r8, r5
    mov.l   .L_fn_display_channel_b, r3
    jsr @r3
    mov #0x10, r4
    mov r8, r6
    mov r8, r5
    mov.l   .L_fn_display_channel_b, r3
    jsr @r3
    mov #0x20, r4
    mov.l   .L_fn_channel_nibble_cfg, r14
    mov.w   .L_channel_id, r4
    jsr @r14
    mov #0x7, r5
    mov r8, r5
    jsr @r14
    mov #0x4, r4
    mov #0x1, r5
    jsr @r14
    mov #0x8, r4
    mov #0x6, r5
    jsr @r14
    mov #0x10, r4
    mov #0x5, r5
    jsr @r14
    mov #0x20, r4
    mov r8, r5
    jsr @r14
    mov #0x1, r4
    mov.l   .L_fn_display_layer_cfg, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_fn_render_state_commit, r3
    jsr @r3
    nop
    mov.l   .L_fp_0x4000_0000, r2
    mov.l @r13, r3
    or r2, r3
    mov.l r3, @r13
    mov r8, r2
    mov.l   .L_disc_state_flag_b, r3
    mov.b r2, @r3
    bra     .L_cleanup_and_exit
    nop

    .global DAT_0601b38a
DAT_0601b38a:
    .2byte  0x008C                          /* object flags for slot C (second pass) */

    .global DAT_0601b38c
DAT_0601b38c:
    .2byte  0x0080                          /* sprite flags small (second pass) */

    .global DAT_0601b38e
DAT_0601b38e:
    .2byte  0x0084                          /* object flags for slot A (second pass) */

    .global DAT_0601b390
DAT_0601b390:
    .2byte  0x0104                          /* object slot ID A (second pass) */

    .global DAT_0601b392
DAT_0601b392:
    .2byte  0x0088                          /* object flags for slot B (second pass) */
.L_channel_id:
    .2byte  0x0100                          /* display channel group ID */
    .2byte  0xFFFF                          /* alignment padding */
.L_vdp2_scroll_word:
    .4byte  sym_0605AAA0                    /* VDP2 scroll position state (16-bit) */
.L_render_mode_flags:
    .4byte  sym_0605B6D8                    /* render mode flags (32-bit bitmask) */
.L_fp_min:
    .4byte  0x80000000                      /* sign bit (bit 31) */
.L_fn_display_update:
    .4byte  sym_06026CE0                    /* display update / camera state finalization */
.L_palette_src_a:
    .4byte  sym_0604842C                    /* palette data source A (WRAM) */
.L_vdp2_cram_0x540:
    .4byte  0x25F00540                      /* VDP2 color RAM +0x540 */
.L_fn_dma_transfer:
    .4byte  dma_transfer                    /* DMA transfer routine */
.L_palette_src_b:
    .4byte  sym_060487EC                    /* palette data source B (WRAM) */
.L_vdp2_cram_0x1A0:
    .4byte  0x25F001A0                      /* VDP2 color RAM +0x1A0 */
.L_tile_size_a:
    .4byte  0x00017700                      /* tile data size (96000 bytes) */
.L_vdp2_vram_0x6F9C4:
    .4byte  0x25E6F9C4                      /* VDP2 VRAM tile destination A */
.L_fn_vram_tile_copy:
    .4byte  sym_0600511E                    /* VRAM tile data copy routine */
.L_tilemap_src:
    .4byte  sym_06094FA8                    /* tilemap source data (WRAM) */
.L_vdp2_vram_0x75DDC:
    .4byte  0x25E75DDC                      /* VDP2 VRAM tilemap destination B */
.L_fn_dma_mem_transfer:
    .4byte  dma_memory_transfer             /* DMA memory-to-memory transfer */
.L_dma_block_size:
    .4byte  0x0000B000                      /* DMA block size (45056 bytes) */
.L_fn_display_list_load:
    .4byte  sym_06028400                    /* display list loader */
.L_fn_display_channel_b:
    .4byte  display_channel_b               /* display channel B setup */
.L_fn_channel_nibble_cfg:
    .4byte  channel_nibble_config           /* channel priority nibble configuration */
.L_fn_display_layer_cfg:
    .4byte  sym_0602853E                    /* display layer configuration */
.L_fn_render_state_commit:
    .4byte  sym_06028560                    /* render state commit / flush */
.L_fp_0x4000_0000:
    .4byte  0x40000000                      /* bit 30 — "ready" flag */
.L_disc_state_flag_b:
    .4byte  sym_0608600D                    /* disc error code (byte: 0=none) */
.L_cleanup_and_exit:
    .byte   0xD3, 0x19    /* mov.l r3, sym_0608600C */
    mov.b r2, @r3
    .byte   0xD3, 0x19    /* mov.l r3, sym_0608600E */
    mov.b r2, @r3
    mov #0xF, r6
    mov #0x4, r5
    mov r5, r4
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x14    /* mov.l r3, handler_dispatch */
    jmp @r3
    mov.l @r15+, r14
