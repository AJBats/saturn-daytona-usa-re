
    .section .text.FUN_0600FED0


    .global transition_medium_c
    .type transition_medium_c, @function
transition_medium_c:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   _pool_countdown_ptr, r14
    mov.l @r14, r3
    add #-0x1, r3
    mov r3, r2
    mov.l r3, @r14
    mov.w   _wpool_fade_threshold, r3
    cmp/gt r3, r2
    bf      .check_trigger_frame
    mov.l   _pool_cram_fade_dst, r5
    mov.l   _pool_fn_palette_interp, r3
    mov r5, r4
    jsr @r3
    add #-0x20, r4
.check_trigger_frame:
    mov.l @r14, r2
    mov.w   _wpool_fade_threshold, r3
    cmp/eq r3, r2
    bf      .check_countdown_reset
    mov.l   _pool_cram_palette_dst, r8
    mov.l   _pool_fn_tile_writer, r9
    mov.l   _pool_fn_dma_transfer, r10
    mov.l   _pool_fn_palette_copy, r11
    mov.l   _pool_vram_tilemap_dst, r12
    mov.w   _wpool_copy_size, r13
    mov.l   _pool_course_index_ptr, r0
    bra     .dispatch_course
    mov.l @r0, r0
.course_0_beginner:
    mov #0x20, r6
    mov.l   _pool_palette_course_0, r5
    jsr @r11
    mov r8, r4
    mov.l   _pool_vram_src_course_0, r4
    jsr @r10
    mov r12, r5
    mov r13, r7
    mov.l   _pool_vram_tiles_course_0, r5
    bra     .do_tile_copy
    mov #0x0, r6
.course_1_advanced:
    mov #0x20, r6
    mov.l   _pool_palette_course_1, r5
    jsr @r11
    mov r8, r4
    mov.l   _pool_vram_src_course_1, r4
    jsr @r10
    mov r12, r5
    mov r13, r7
    mov.l   _pool_vram_tiles_course_1, r5
    bra     .do_tile_copy
    mov #0x0, r6
.course_2_expert:
    mov #0x20, r6
    mov.l   _pool_palette_course_2, r5
    jsr @r11
    mov r8, r4
    mov.l   _pool_vram_src_course_2, r4
    jsr @r10
    mov r12, r5
    mov r13, r7
    mov #0x0, r6
    mov.l   _pool_vram_tiles_course_2, r5
.do_tile_copy:
    jsr @r9
    mov #0x4, r4
    bra     .check_countdown_reset
    nop
_wpool_fade_threshold:
    .2byte  0x0099                 /* countdown threshold: 153 (fade → asset load boundary) */
_wpool_copy_size:
    .2byte  0x5A00                 /* tilemap copy size: 23040 bytes */
_pool_countdown_ptr:
    .4byte  sym_0607EBCC           /* &countdown_timer (attract mode countdown, 32-bit) */
_pool_cram_fade_dst:
    .4byte  0x25F00540             /* VDP2 color RAM +0x540 (fade destination palette) */
_pool_fn_palette_interp:
    .4byte  throttle_input_proc    /* palette color interpolation function */
_pool_cram_palette_dst:
    .4byte  0x25F004A0             /* VDP2 color RAM +0x4A0 (course palette destination) */
_pool_fn_tile_writer:
    .4byte  sym_06028400           /* tile_writer / display list loader */
_pool_fn_dma_transfer:
    .4byte  dma_memory_transfer    /* DMA memory-to-memory transfer */
_pool_fn_palette_copy:
    .4byte  memcpy_word_idx        /* word-indexed memory copy */
_pool_vram_tilemap_dst:
    .4byte  0x25E34000             /* VDP2 VRAM +0x34000 (tilemap destination) */
_pool_course_index_ptr:
    .4byte  sym_0607EAD8           /* &course_index (0=Beginner, 1=Advanced, 2=Expert) */
_pool_palette_course_0:
    .4byte  sym_0604872C           /* course 0 palette data (16 colors, 32 bytes) */
_pool_vram_src_course_0:
    .4byte  0x25E61CEC             /* VDP2 VRAM +0x61CEC (course 0 tilemap source) */
_pool_vram_tiles_course_0:
    .4byte  0x25E60000             /* VDP2 VRAM +0x60000 (course 0 tile destination) */
_pool_palette_course_1:
    .4byte  sym_0604874C           /* course 1 palette data (16 colors, 32 bytes) */
_pool_vram_src_course_1:
    .4byte  0x25E665D4             /* VDP2 VRAM +0x665D4 (course 1 tilemap source) */
_pool_vram_tiles_course_1:
    .4byte  0x25E609A4             /* VDP2 VRAM +0x609A4 (course 1 tile destination) */
_pool_palette_course_2:
    .4byte  sym_0604876C           /* course 2 palette data (16 colors, 32 bytes) */
_pool_vram_src_course_2:
    .4byte  0x25E6A9CC             /* VDP2 VRAM +0x6A9CC (course 2 tilemap source) */
_pool_vram_tiles_course_2:
    .4byte  0x25E61348             /* VDP2 VRAM +0x61348 (course 2 tile destination) */
.dispatch_course:
    cmp/eq #0x0, r0
    bt      .course_0_beginner
    cmp/eq #0x1, r0
    bt      .course_1_advanced
    cmp/eq #0x2, r0
    bt      .course_2_expert
.check_countdown_reset:
    mov.l @r14, r0
    cmp/eq #0x78, r0
    bf      .epilogue
    mov #0x0, r3
    mov.l r3, @r14
.epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
