/* transition_medium_c -- per-frame course tilemap/palette transition handler
 * Translation unit: 0x0600FED0 - 0x0600FFD0
 *
 * Called every frame during a medium screen transition (e.g., attract mode
 * or course preview). Manages a countdown timer and performs two phases:
 *
 *   Phase 1 (countdown > 153): Fade palette colors at VDP2 CRAM +0x520/+0x540
 *     via throttle_input_proc (palette interpolation between two CRAM regions).
 *
 *   Phase 2 (countdown == 153): One-time course-specific asset load.
 *     Reads the course index from sym_0607EAD8 (0=Beginner, 1=Advanced,
 *     2=Expert) and for the selected course:
 *       a) Copies a 16-color palette (32 bytes) into VDP2 CRAM +0x4A0
 *          via memcpy_word_idx (tile writer).
 *       b) DMA-transfers course tilemap data from VRAM source to +0x34000
 *          via dma_memory_transfer.
 *       c) Copies scroll plane tile data via memcpy_word_idx with mode 4.
 *
 *   Countdown reset: When countdown reaches 0x78 (120), reset it to 0
 *     (signals transition complete to the state machine).
 *
 * Course tilemap sources (VDP2 VRAM):
 *   Course 0: src=+0x61CEC, dest tiles=+0x60000, palette=sym_0604872C
 *   Course 1: src=+0x665D4, dest tiles=+0x609A4, palette=sym_0604874C
 *   Course 2: src=+0x6A9CC, dest tiles=+0x61348, palette=sym_0604876C
 *
 * Args: none (reads state from globals)
 * Returns: void
 * Calls: throttle_input_proc, sym_06028400 (tile_writer),
 *         dma_memory_transfer, memcpy_word_idx
 */

    .section .text.FUN_0600FED0


    .global transition_medium_c
    .type transition_medium_c, @function
transition_medium_c:
    mov.l r14, @-r15               ! save r14
    mov.l r13, @-r15               ! save r13
    mov.l r12, @-r15               ! save r12
    mov.l r11, @-r15               ! save r11
    mov.l r10, @-r15               ! save r10
    mov.l r9, @-r15                ! save r9
    mov.l r8, @-r15                ! save r8
    sts.l pr, @-r15                ! save return address
    mov.l   _pool_countdown_ptr, r14  ! r14 = &countdown_timer (sym_0607EBCC)
    mov.l @r14, r3                 ! r3 = current countdown value
    add #-0x1, r3                  ! decrement countdown
    mov r3, r2                     ! r2 = decremented countdown (for comparison)
    mov.l r3, @r14                 ! store decremented countdown
    mov.w   _wpool_fade_threshold, r3  ! r3 = 0x99 (153 = fade phase threshold)
    cmp/gt r3, r2                  ! is countdown > 153? (still in fade phase)
    bf      .check_trigger_frame   ! if not, skip palette fade
    mov.l   _pool_cram_fade_dst, r5   ! r5 = VDP2 CRAM +0x540 (fade destination palette)
    mov.l   _pool_fn_palette_interp, r3  ! r3 = throttle_input_proc (palette interpolation)
    mov r5, r4                     ! r4 = CRAM +0x540 (will be shifted by -0x20 for source)
    jsr @r3                        ! throttle_input_proc(CRAM+0x520, CRAM+0x540)
    add #-0x20, r4                 ! r4 = CRAM +0x520 (fade source palette, delay slot)
.check_trigger_frame:
    mov.l @r14, r2                 ! r2 = current countdown value (re-read after decrement)
    mov.w   _wpool_fade_threshold, r3  ! r3 = 0x99 (153)
    cmp/eq r3, r2                  ! has countdown reached exactly 153?
    bf      .check_countdown_reset ! if not, skip one-time course asset load
    mov.l   _pool_cram_palette_dst, r8   ! r8 = VDP2 CRAM +0x4A0 (course palette destination)
    mov.l   _pool_fn_tile_writer, r9     ! r9 = memcpy_word_idx (word-indexed copy)
    mov.l   _pool_fn_dma_transfer, r10   ! r10 = dma_memory_transfer
    mov.l   _pool_fn_palette_copy, r11   ! r11 = sym_06028400 (tile_writer / palette loader)
    mov.l   _pool_vram_tilemap_dst, r12  ! r12 = VDP2 VRAM +0x34000 (tilemap destination)
    mov.w   _wpool_copy_size, r13  ! r13 = 0x5A00 (23040 bytes = tilemap copy size)
    mov.l   _pool_course_index_ptr, r0   ! r0 = &course_index (sym_0607EAD8)
    bra     .dispatch_course       ! jump to course index dispatch
    mov.l @r0, r0                  ! r0 = course_index value (0/1/2, delay slot)
.course_0_beginner:
    mov #0x20, r6                  ! r6 = 0x20 (32 bytes = 16 colors, palette size)
    mov.l   _pool_palette_course_0, r5   ! r5 = sym_0604872C (beginner course palette data)
    jsr @r11                       ! tile_writer(CRAM+0x4A0, palette_0, 32) — load palette
    mov r8, r4                     ! r4 = CRAM +0x4A0 (palette destination, delay slot)
    mov.l   _pool_vram_src_course_0, r4  ! r4 = VDP2 VRAM +0x61CEC (course 0 tilemap source)
    jsr @r10                       ! dma_memory_transfer(VRAM+0x61CEC, VRAM+0x34000)
    mov r12, r5                    ! r5 = VRAM +0x34000 (tilemap destination, delay slot)
    mov r13, r7                    ! r7 = 0x5A00 (copy size)
    mov.l   _pool_vram_tiles_course_0, r5  ! r5 = VDP2 VRAM +0x60000 (course 0 tile destination)
    bra     .do_tile_copy          ! jump to shared tile copy path
    mov #0x0, r6                   ! r6 = 0 (tile offset, delay slot)
.course_1_advanced:
    mov #0x20, r6                  ! r6 = 0x20 (32 bytes = palette size)
    mov.l   _pool_palette_course_1, r5   ! r5 = sym_0604874C (advanced course palette data)
    jsr @r11                       ! tile_writer(CRAM+0x4A0, palette_1, 32) — load palette
    mov r8, r4                     ! r4 = CRAM +0x4A0 (palette destination, delay slot)
    mov.l   _pool_vram_src_course_1, r4  ! r4 = VDP2 VRAM +0x665D4 (course 1 tilemap source)
    jsr @r10                       ! dma_memory_transfer(VRAM+0x665D4, VRAM+0x34000)
    mov r12, r5                    ! r5 = VRAM +0x34000 (tilemap destination, delay slot)
    mov r13, r7                    ! r7 = 0x5A00 (copy size)
    mov.l   _pool_vram_tiles_course_1, r5  ! r5 = VDP2 VRAM +0x609A4 (course 1 tile destination)
    bra     .do_tile_copy          ! jump to shared tile copy path
    mov #0x0, r6                   ! r6 = 0 (tile offset, delay slot)
.course_2_expert:
    mov #0x20, r6                  ! r6 = 0x20 (32 bytes = palette size)
    mov.l   _pool_palette_course_2, r5   ! r5 = sym_0604876C (expert course palette data)
    jsr @r11                       ! tile_writer(CRAM+0x4A0, palette_2, 32) — load palette
    mov r8, r4                     ! r4 = CRAM +0x4A0 (palette destination, delay slot)
    mov.l   _pool_vram_src_course_2, r4  ! r4 = VDP2 VRAM +0x6A9CC (course 2 tilemap source)
    jsr @r10                       ! dma_memory_transfer(VRAM+0x6A9CC, VRAM+0x34000)
    mov r12, r5                    ! r5 = VRAM +0x34000 (tilemap destination, delay slot)
    mov r13, r7                    ! r7 = 0x5A00 (copy size)
    mov #0x0, r6                   ! r6 = 0 (tile offset)
    mov.l   _pool_vram_tiles_course_2, r5  ! r5 = VDP2 VRAM +0x61348 (course 2 tile destination)
.do_tile_copy:
    jsr @r9                        ! memcpy_word_idx(4, tiles_dst, 0, 0x5A00) — copy tile data
    mov #0x4, r4                   ! r4 = 4 (display channel / copy mode, delay slot)
    bra     .check_countdown_reset ! done with course load, check reset
    nop                            ! (delay slot)
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
    cmp/eq #0x0, r0                ! is course_index == 0 (Beginner)?
    bt      .course_0_beginner     ! if so, load beginner course assets
    cmp/eq #0x1, r0                ! is course_index == 1 (Advanced)?
    bt      .course_1_advanced     ! if so, load advanced course assets
    cmp/eq #0x2, r0                ! is course_index == 2 (Expert)?
    bt      .course_2_expert       ! if so, load expert course assets
.check_countdown_reset:
    mov.l @r14, r0                 ! r0 = current countdown value
    cmp/eq #0x78, r0               ! has countdown reached 120? (transition complete)
    bf      .epilogue              ! if not, skip reset
    mov #0x0, r3                   ! r3 = 0 (reset value)
    mov.l r3, @r14                 ! countdown_timer = 0 (signal transition done)
.epilogue:
    lds.l @r15+, pr                ! restore return address
    mov.l @r15+, r8                ! restore r8
    mov.l @r15+, r9                ! restore r9
    mov.l @r15+, r10               ! restore r10
    mov.l @r15+, r11               ! restore r11
    mov.l @r15+, r12               ! restore r12
    mov.l @r15+, r13               ! restore r13
    rts                            ! return
    mov.l @r15+, r14               ! restore r14 (delay slot)
