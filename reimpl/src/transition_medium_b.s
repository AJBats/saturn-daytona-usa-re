
    .section .text.FUN_0600FE38


    .global transition_medium_b
    .type transition_medium_b, @function
transition_medium_b:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   _pool_countdown_ptr, r4
    mov.l @r4, r3
    add #-0x1, r3
    mov.l r3, @r4
    mov.w   _wpool_trigger_frame, r2
    cmp/eq r2, r3
    bf      .L_every_frame
    mov.l   _pool_tilemap_src, r2
    mov.l r2, @r15
    mov.l   _pool_dma_src, r4
    mov.l   _pool_fn_dma_transfer, r3
    jsr @r3
    mov r2, r5
    mov.l   _pool_tile_entry, r7
    mov #0x0, r6
    mov.l @r15, r5
    mov.l   _pool_tile_offset, r3
    mov.l @(4, r7), r7
    add r3, r7
    mov.l   _pool_fn_tile_writer, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r2
    mov.l   _pool_transition_state, r3
    mov.l r2, @r3
    mov #0x10, r2
    mov.l   _pool_game_state_byte, r3
    mov.b r2, @r3
.L_every_frame:
    mov.l   _pool_split_tile_data, r7
    mov.w   _wpool_tile_size, r6
    mov.w   _wpool_tile_data_size, r5
    mov.l   _pool_fn_display_channel, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_vdp2_cram_0x1E0, r4
    mov.l   _pool_fn_palette_fade, r3
    jsr @r3
    nop
    mov.l   .L_vdp2_cram_0x520, r4
    add #0x4, r15
    mov.l   _pool_fn_palette_fade, r3
    jmp @r3
    lds.l @r15+, pr
_wpool_trigger_frame:
    .2byte  0x00AB                 /* countdown trigger threshold (171 frames) */
_wpool_tile_size:
    .2byte  0x0090                 /* split-screen tile size */
_wpool_tile_data_size:
    .2byte  0x07A2                 /* split-screen tile data size */
_pool_countdown_ptr:
    .4byte  sym_0607EBCC           /* &state_countdown (32-bit, WRAM High) */
_pool_tilemap_src:
    .4byte  sym_06094FA8           /* tilemap source data (WRAM) */
_pool_dma_src:
    .4byte  sym_060EFB24           /* DMA source: VDP2 tilemap data */
_pool_fn_dma_transfer:
    .4byte  dma_memory_transfer    /* DMA memory-to-memory transfer */
_pool_tile_entry:
    .4byte  sym_06063838           /* tile table entry (struct base) */
_pool_tile_offset:
    .4byte  0x00009000             /* tile data offset (+0x9000) */
_pool_fn_tile_writer:
    .4byte  sym_06028400           /* display list loader / tile writer */
_pool_transition_state:
    .4byte  sym_06078864           /* transition state word (32-bit) */
_pool_game_state_byte:
    .4byte  sym_0607887F           /* game_state_byte (8-bit) */
_pool_split_tile_data:
    .4byte  sym_0605ACE4           /* split-screen tile data source */
_pool_fn_display_channel:
    .4byte  sym_060284AE           /* display channel handler / tile writer */
.L_vdp2_cram_0x1E0:
    .4byte  0x25F001E0             /* VDP2 color RAM +0x1E0 */
_pool_fn_palette_fade:
    .4byte  sym_06011F1C           /* palette_color_fade (from dual_hud_render) */
.L_vdp2_cram_0x520:
    .4byte  0x25F00520             /* VDP2 color RAM +0x520 */
