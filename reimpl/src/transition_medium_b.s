/* transition_medium_b -- per-frame transition tick for medium screen wipe
 * Translation unit: 0x0600FE38 - 0x0600FED0
 *
 * Called every frame during a medium screen transition (e.g., between
 * mode select and car select, or between car select and course select).
 * Decrements the state countdown timer and, on the trigger frame (0xAB),
 * performs a one-time setup:
 *   1. DMA tilemap source data into VDP2 VRAM via dma_memory_transfer
 *   2. Load display tiles via tile_writer with +0x9000 data offset
 *   3. Clear transition state word and set game_state_byte = 0x10
 *
 * Every frame (including the trigger frame):
 *   4. Update split-screen tile display via display_channel_handler
 *   5. Fade palette at VDP2 CRAM +0x1E0 via palette_color_fade
 *   6. Tail-call palette_color_fade for VDP2 CRAM +0x520
 *
 * Args: none (reads state from globals)
 * Returns: via tail-call to palette_color_fade
 */

    .section .text.FUN_0600FE38


    .global transition_medium_b
    .type transition_medium_b, @function
transition_medium_b:
    sts.l pr, @-r15                ! save return address
    add #-0x4, r15                 ! allocate 4 bytes of stack
    mov.l   _pool_countdown_ptr, r4   ! r4 = &state_countdown
    mov.l @r4, r3                  ! r3 = state_countdown value
    add #-0x1, r3                  ! decrement countdown
    mov.l r3, @r4                  ! store decremented countdown
    mov.w   _wpool_trigger_frame, r2  ! r2 = 0xAB (trigger frame threshold)
    cmp/eq r2, r3                  ! has countdown reached trigger frame?
    bf      .L_every_frame         ! if not, skip one-time setup
    mov.l   _pool_tilemap_src, r2  ! r2 = tilemap source address (WRAM)
    mov.l r2, @r15                 ! save tilemap source on stack
    mov.l   _pool_dma_src, r4      ! r4 = DMA source data (VDP2 tilemap)
    mov.l   _pool_fn_dma_transfer, r3  ! r3 = dma_memory_transfer
    jsr @r3                        ! dma_memory_transfer(dma_src, tilemap_src)
    mov r2, r5                     ! r5 = tilemap_src (delay slot)
    mov.l   _pool_tile_entry, r7   ! r7 = &tile_table_entry (struct base)
    mov #0x0, r6                   ! r6 = 0 (tile size param)
    mov.l @r15, r5                 ! r5 = tilemap source (from stack)
    mov.l   _pool_tile_offset, r3  ! r3 = 0x9000 (tile data offset)
    mov.l @(4, r7), r7             ! r7 = tile_entry[+4] = tile data ptr
    add r3, r7                     ! r7 = tile_data + 0x9000
    mov.l   _pool_fn_tile_writer, r3  ! r3 = tile_writer function
    jsr @r3                        ! tile_writer(0x4, tilemap_src, 0, tile_data+0x9000)
    mov #0x4, r4                   ! r4 = 0x4 (display channel, delay slot)
    mov #0x0, r2                   ! r2 = 0 (clear value)
    mov.l   _pool_transition_state, r3  ! r3 = &transition_state
    mov.l r2, @r3                  ! transition_state = 0 (reset)
    mov #0x10, r2                  ! r2 = 0x10 (new game state)
    mov.l   _pool_game_state_byte, r3  ! r3 = &game_state_byte
    mov.b r2, @r3                  ! game_state_byte = 0x10
.L_every_frame:
    mov.l   _pool_split_tile_data, r7  ! r7 = split-screen tile data source
    mov.w   _wpool_tile_size, r6   ! r6 = 0x0090 (tile size)
    mov.w   _wpool_tile_data_size, r5  ! r5 = 0x07A2 (tile data size)
    mov.l   _pool_fn_display_channel, r3  ! r3 = display_channel_handler
    jsr @r3                        ! display_channel_handler(0xC, tile_data_size, tile_size, split_tile_data)
    mov #0xC, r4                   ! r4 = 0xC (display channel, delay slot)
    mov.l   .L_vdp2_cram_0x1E0, r4  ! r4 = VDP2 CRAM +0x1E0 (palette addr A)
    mov.l   _pool_fn_palette_fade, r3  ! r3 = palette_color_fade
    jsr @r3                        ! palette_color_fade(0x25F001E0)
    nop                            ! (delay slot — no further args needed)
    mov.l   .L_vdp2_cram_0x520, r4  ! r4 = VDP2 CRAM +0x520 (palette addr B)
    add #0x4, r15                  ! free stack frame
    mov.l   _pool_fn_palette_fade, r3  ! r3 = palette_color_fade
    jmp @r3                        ! tail-call palette_color_fade(0x25F00520)
    lds.l @r15+, pr                ! restore return address (delay slot)
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
