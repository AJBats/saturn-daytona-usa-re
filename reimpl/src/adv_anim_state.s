/* adv_anim_state -- Advanced HUD Animation State Machine
 * Translation unit: 0x06010760 - 0x06010994  (564 bytes)
 *
 * Drives directional animation for multi-frame HUD elements based on
 * analog input thresholds. Companion to multi_state_anim (0x060104E0),
 * sharing the same DMA result / frame index variables.
 *
 * Flow:
 *   1. Dispatch on game_mode byte (sym_0605AB16) to set max_frames:
 *      modes 1,2,4 → 5;  modes 3,5,6 → 7;  mode 7 → 9;  default → 3.
 *      Special overrides: overlay_flags==7 → 11, overlay_flags==15 → 13.
 *   2. Read input word (sym_06063D9C), XOR with 0xFFFF, mask low byte.
 *      - If input > 0x90: advance forward — set direction = -1.0 (16.16),
 *        increment frame counter, wrap at max_frames, store DMA params.
 *      - If input < 0x70: advance backward — set direction = +1.0 (16.16),
 *        decrement frame counter, clamp at 0, store DMA params.
 *   3. Toggle flag (sym_060788A8) selects which DMA result pair receives
 *      the update (A: sym_06078894/A0, B: sym_06078898/A4).
 *   4. For frames < 10: look up tile data from sym_0605D05C table,
 *      compute VRAM offset, and call memcpy_word_idx for DMA transfer.
 *   5. For frames >= 10 in range [0x70..0x90]: look up palette data from
 *      sym_0605CA9C, compute VDP2 CRAM destination, call memcpy_word_idx.
 *
 * Registers on entry: none (reads globals directly)
 * Calls: memcpy_word_idx
 * Called by: HUD update dispatcher (per-frame)
 */

    .section .text.FUN_06010760


    .global adv_anim_state
    .type adv_anim_state, @function
adv_anim_state:
    mov.l r14, @-r15                         ! save r14
    mov.l r13, @-r15                         ! save r13
    mov.l r12, @-r15                         ! save r12
    mov.l r11, @-r15                         ! save r11
    mov.l r10, @-r15                         ! save r10
    mov.l r9, @-r15                          ! save r9
    mov.l r8, @-r15                          ! save r8
    sts.l pr, @-r15                          ! save return address
    mov #0x1, r8                             ! r8 = 1 (constant: toggle ON)
    mov #0x0, r9                             ! r9 = 0 (constant: toggle OFF / zero)
    mov.l   .L_ptr_memcpy_word_idx, r10      ! r10 = &memcpy_word_idx (call target)
    mov.l   .L_ptr_toggle_flag, r12          ! r12 = &toggle_flag (byte at sym_060788A8)
    mov.l   .L_ptr_frame_mirror, r13         ! r13 = &frame_mirror (dword at sym_06078868)
    mov.l   .L_ptr_frame_counter, r14        ! r14 = &frame_counter (dword at sym_0607EADC)
    mov.l   .L_ptr_game_mode, r0             ! r0 = &game_mode byte
    bra     .L_dispatch_game_mode            ! branch to mode dispatch
    mov.b @r0, r0                            ! (delay) r0 = *game_mode
.L_mode_frames_5:
    bra     .L_check_overlay_special         ! -> check overlay special cases
    mov #0x5, r4                             ! (delay) max_frames = 5
.L_mode_frames_7:
    bra     .L_check_overlay_special         ! -> check overlay special cases
    mov #0x7, r4                             ! (delay) max_frames = 7
.L_mode_frames_9:
    bra     .L_check_overlay_special         ! -> check overlay special cases
    mov #0x9, r4                             ! (delay) max_frames = 9
.L_mode_frames_3:
    bra     .L_check_overlay_special         ! -> check overlay special cases (default)
    mov #0x3, r4                             ! (delay) max_frames = 3
.L_dispatch_game_mode:
    cmp/eq #0x1, r0                          ! game_mode == 1?
    bt      .L_mode_frames_5                 ! yes -> max_frames = 5
    cmp/eq #0x2, r0                          ! game_mode == 2?
    bt      .L_mode_frames_5                 ! yes -> max_frames = 5
    cmp/eq #0x3, r0                          ! game_mode == 3?
    bt      .L_mode_frames_7                 ! yes -> max_frames = 7
    cmp/eq #0x4, r0                          ! game_mode == 4?
    bt      .L_mode_frames_5                 ! yes -> max_frames = 5
    cmp/eq #0x5, r0                          ! game_mode == 5?
    bt      .L_mode_frames_7                 ! yes -> max_frames = 7
    cmp/eq #0x6, r0                          ! game_mode == 6?
    bt      .L_mode_frames_7                 ! yes -> max_frames = 7
    cmp/eq #0x7, r0                          ! game_mode == 7?
    bt      .L_mode_frames_9                 ! yes -> max_frames = 9
    bra     .L_mode_frames_3                 ! default -> max_frames = 3
    nop                                      ! (delay)
    .2byte  0xFFFF                           ! alignment padding
.L_ptr_memcpy_word_idx:
    .4byte  memcpy_word_idx                  /* word-indexed memcpy routine */
.L_ptr_toggle_flag:
    .4byte  sym_060788A8                     /* DMA pair toggle flag (byte) */
.L_ptr_frame_mirror:
    .4byte  sym_06078868                     /* frame mirror / sprite index (dword) */
.L_ptr_frame_counter:
    .4byte  sym_0607EADC                     /* animation frame counter (dword) */
.L_ptr_game_mode:
    .4byte  sym_0605AB16                     /* game mode byte (1-7) */
.L_check_overlay_special:
    mov.l   .L_ptr_overlay_flags, r0         ! r0 = &overlay_flags byte
    mov.b @r0, r0                            ! r0 = *overlay_flags
    cmp/eq #0x7, r0                          ! overlay_flags == 7?
    bf      .L_check_overlay_15              ! no -> check for 15
    mov #0xB, r4                             ! yes -> override max_frames = 11
.L_check_overlay_15:
    mov.l   .L_ptr_overlay_flags, r0         ! r0 = &overlay_flags byte
    mov.b @r0, r0                            ! r0 = *overlay_flags
    cmp/eq #0xF, r0                          ! overlay_flags == 15?
    bf      .L_read_input                    ! no -> proceed to input reading
    mov #0xD, r4                             ! yes -> override max_frames = 13
.L_read_input:
    mov.l   .L_ptr_input_word, r0            ! r0 = &input_word (sym_06063D9C)
    mov.l   .L_mask_low16, r3                ! r3 = 0x0000FFFF
    mov.w @r0, r0                            ! r0 = *input_word (16-bit)
    extu.w r0, r0                            ! zero-extend to 32-bit
    xor r3, r0                               ! r0 = ~input (invert low 16 bits)
    and #0xFF, r0                            ! r0 = inverted low byte only
    mov.w   .L_threshold_fwd, r3             ! r3 = 0x0090 (forward threshold)
    extu.w r0, r11                           ! r11 = input_value (unsigned)
    cmp/gt r3, r11                           ! input_value > 0x90?
    bf      .L_check_backward                ! no -> check backward threshold
    mov.l   .L_fp_neg_one, r3                ! r3 = -1.0 (16.16 fixed-point)
    mov.l   .L_ptr_anim_direction, r2        ! r2 = &anim_direction
    mov.l r3, @r2                            ! *anim_direction = -1.0 (animate forward)
    mov #0x1E, r3                            ! r3 = 30
    mov.l   .L_ptr_timer_value, r2           ! r2 = &timer_value
    mov.l r3, @r2                            ! *timer_value = 30 (frame hold time)
    mov.l @r14, r3                           ! r3 = *frame_counter
    add #0x1, r3                             ! r3 = frame_counter + 1
    mov r3, r2                               ! r2 = new frame value
    mov.l r3, @r14                           ! *frame_counter = r3
    cmp/gt r4, r2                            ! new_frame > max_frames?
    bf      .L_fwd_store_dma                 ! no -> store DMA params
    mov.l r9, @r14                           ! yes -> *frame_counter = 0 (wrap)
.L_fwd_store_dma:
    mov.l   .L_fp_fwd_dma_size, r5           ! r5 = 0x000C0000 (12.0 — fwd DMA size)
    mov.b @r12, r0                           ! r0 = *toggle_flag
    extu.b r0, r0                            ! zero-extend to 32 bits
    tst r0, r0                               ! toggle_flag == 0?
    bt      .L_fwd_toggle_off                ! yes -> store to pair B, set toggle ON
    extu.b r9, r3                            ! r3 = 0
    mov.b r3, @r12                           ! *toggle_flag = 0 (clear toggle)
    mov.l   .L_ptr_dma_result_a, r3          ! r3 = &dma_result_a (sym_06078894)
    mov.l r5, @r3                            ! *dma_result_a = fwd DMA size
    mov.l @r14, r2                           ! r2 = *frame_counter
    mov.l   .L_ptr_frame_idx_a, r3           ! r3 = &frame_idx_a (sym_060788A0)
    mov.l r2, @r3                            ! *frame_idx_a = frame_counter
    bra     .L_check_backward                ! -> check backward threshold
    nop                                      ! (delay)
.L_fwd_toggle_off:
    mov.b r8, @r12                           ! *toggle_flag = 1 (set toggle)
    mov.l   .L_ptr_dma_result_b, r3          ! r3 = &dma_result_b (sym_06078898)
    mov.l r5, @r3                            ! *dma_result_b = fwd DMA size
    mov.l @r14, r2                           ! r2 = *frame_counter
    mov.l   .L_ptr_frame_idx_b, r3           ! r3 = &frame_idx_b (sym_060788A4)
    mov.l r2, @r3                            ! *frame_idx_b = frame_counter
.L_check_backward:
    extu.w r11, r2                           ! r2 = input_value (unsigned)
    mov #0x70, r3                            ! r3 = 0x70 (backward threshold)
    cmp/ge r3, r2                            ! input_value >= 0x70?
    bt      .L_update_frame_output           ! yes -> dead zone, skip to output
    mov.l   .L_fp_one, r3                    ! r3 = +1.0 (16.16 fixed-point)
    mov.l   .L_ptr_anim_direction, r2        ! r2 = &anim_direction
    mov.l r3, @r2                            ! *anim_direction = +1.0 (animate backward)
    mov #0x1E, r3                            ! r3 = 30
    mov.l   .L_ptr_timer_value, r2           ! r2 = &timer_value
    mov.l r3, @r2                            ! *timer_value = 30 (frame hold time)
    mov.l @r14, r3                           ! r3 = *frame_counter
    add #-0x1, r3                            ! r3 = frame_counter - 1
    mov.l r3, @r14                           ! *frame_counter = r3
    mov r3, r2                               ! r2 = new frame value
    cmp/pz r2                                ! new_frame >= 0?
    bt      .L_bwd_store_dma                 ! yes -> store DMA params
    mov.l r4, @r14                           ! no -> *frame_counter = max_frames (wrap)
.L_bwd_store_dma:
    mov.l   .L_fp_bwd_dma_size, r4           ! r4 = 0xFFF40000 (-12.0 — bwd DMA size)
    mov.b @r12, r0                           ! r0 = *toggle_flag
    extu.b r0, r0                            ! zero-extend to 32 bits
    tst r0, r0                               ! toggle_flag == 0?
    bt      .L_bwd_toggle_off                ! yes -> store to pair B, set toggle ON
    extu.b r9, r3                            ! r3 = 0
    mov.b r3, @r12                           ! *toggle_flag = 0 (clear toggle)
    mov.l   .L_ptr_dma_result_a, r3          ! r3 = &dma_result_a
    mov.l r4, @r3                            ! *dma_result_a = bwd DMA size
    mov.l @r14, r2                           ! r2 = *frame_counter
    mov.l   .L_ptr_frame_idx_a, r3           ! r3 = &frame_idx_a
    mov.l r2, @r3                            ! *frame_idx_a = frame_counter
    bra     .L_update_frame_output           ! -> update frame output
    nop                                      ! (delay)
.L_threshold_fwd:
    .2byte  0x0090                           /* forward input threshold (> this = fwd) */
    .2byte  0xFFFF                           /* alignment padding */
.L_ptr_overlay_flags:
    .4byte  sym_0605AB17                     /* overlay flags byte */
.L_ptr_input_word:
    .4byte  sym_06063D9C                     /* input state word (button/analog) */
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_fp_neg_one:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_ptr_anim_direction:
    .4byte  sym_0607889C                     /* per-frame scroll delta (16.16 fp) */
.L_ptr_timer_value:
    .4byte  sym_0605AA9C                     /* animation hold timer (frames) */
.L_fp_fwd_dma_size:
    .4byte  0x000C0000                       /* +12.0 (16.16 fp) — forward DMA size */
.L_ptr_dma_result_a:
    .4byte  sym_06078894                     /* scroll X position accumulator */
.L_ptr_frame_idx_a:
    .4byte  sym_060788A0                     /* game state counter (pair A) */
.L_ptr_dma_result_b:
    .4byte  sym_06078898                     /* scroll Y position accumulator */
.L_ptr_frame_idx_b:
    .4byte  sym_060788A4                     /* frame index (pair B) */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_fp_bwd_dma_size:
    .4byte  0xFFF40000                       /* -12.0 (16.16 fp) — backward DMA size */
.L_bwd_toggle_off:
    mov.b r8, @r12                           ! *toggle_flag = 1 (set toggle)
    mov.l   .L_ptr_dma_result_b2, r3         ! r3 = &dma_result_b (sym_06078898)
    mov.l r4, @r3                            ! *dma_result_b = bwd DMA size
    mov.l @r14, r2                           ! r2 = *frame_counter
    mov.l   .L_ptr_frame_idx_b2, r3          ! r3 = &frame_idx_b (sym_060788A4)
    mov.l r2, @r3                            ! *frame_idx_b = frame_counter
.L_update_frame_output:
    mov.l @r14, r2                           ! r2 = *frame_counter
    mov.l r2, @r13                           ! *frame_mirror = frame_counter
    mov r2, r3                               ! r3 = frame_counter
    and r8, r3                               ! r3 = frame_counter & 1 (odd/even bit)
    mov.l   .L_ptr_frame_output, r2          ! r2 = &frame_output (sym_0607EAB8)
    mov.l r3, @r2                            ! *frame_output = frame_counter & 1
    mov.l @r13, r1                           ! r1 = *frame_mirror
    mov #0xA, r2                             ! r2 = 10
    cmp/hs r2, r1                            ! frame >= 10? (unsigned)
    bt      .L_palette_section               ! yes -> skip tile DMA, do palette only
    mov.b @r12, r0                           ! r0 = *toggle_flag
    extu.b r0, r0                            ! zero-extend
    tst r0, r0                               ! toggle_flag == 0?
    bt      .L_tile_lookup_toggle_off        ! yes -> toggle-off path
    mov.w   DAT_0601096e, r6                 ! r6 = 0x00C0 (tile block size = 192 bytes)
    mov.l @r13, r5                           ! r5 = *frame_mirror (frame index)
    mov.l   .L_ptr_tile_table, r3            ! r3 = tile_table base (sym_0605D05C)
    mov.l   .L_ptr_game_state_idx, r4        ! r4 = &game_state_idx (sym_06059FFC)
    shll2 r5                                 ! r5 = frame * 4 (dword index)
    mov.l @r4, r4                            ! r4 = *game_state_idx
    add r3, r5                               ! r5 = &tile_table[frame]
    shll2 r4                                 ! r4 = state * 4
    mov.l @r5, r5                            ! r5 = tile_table[frame] (src addr)
    shll r4                                  ! r4 = state * 8
    mov.l   .L_ptr_car_struct_base, r2       ! r2 = &car_struct_base ptr (sym_06063F5C)
    mov.l @r2, r2                            ! r2 = *car_struct_base
    add r2, r4                               ! r4 = car_struct_base + state*8 (dst base)
    mov r6, r1                               ! r1 = 0x00C0 (tile block size)
    add #0x40, r1                            ! r1 = 0x0100 (dst offset with extra 64)
    bra     .L_call_memcpy_tile              ! -> call memcpy
    add r1, r4                               ! (delay) r4 = dst + 0x0100
.L_tile_lookup_toggle_off:
    mov.w   DAT_0601096e, r6                 ! r6 = 0x00C0 (tile block size = 192 bytes)
    mov.l @r13, r5                           ! r5 = *frame_mirror (frame index)
    mov.l   .L_ptr_tile_table, r3            ! r3 = tile_table base
    mov.l   .L_ptr_game_state_idx, r4        ! r4 = &game_state_idx
    shll2 r5                                 ! r5 = frame * 4
    mov.l @r4, r4                            ! r4 = *game_state_idx
    add r3, r5                               ! r5 = &tile_table[frame]
    shll2 r4                                 ! r4 = state * 4
    mov.l @r5, r5                            ! r5 = tile_table[frame] (src addr)
    shll r4                                  ! r4 = state * 8
    mov.l   .L_ptr_car_struct_base, r2       ! r2 = &car_struct_base ptr
    mov.l @r2, r2                            ! r2 = *car_struct_base
    add r2, r4                               ! r4 = car_struct_base + state*8
    add #0x40, r4                            ! r4 = dst + 0x40 (64-byte offset)
.L_call_memcpy_tile:
    jsr @r10                                 ! call memcpy_word_idx(dst=r4, src=r5, cnt=r6)
    nop                                      ! (delay)
.L_palette_section:
    extu.w r11, r4                           ! r4 = input_value (unsigned)
    mov #0x70, r3                            ! r3 = 0x70 (lower dead zone bound)
    cmp/ge r3, r4                            ! input_value >= 0x70?
    bf      .L_palette_frame_check           ! no (below 0x70) -> do palette update
    mov.w   .L_threshold_bwd_hi, r3          ! r3 = 0x0090 (upper dead zone bound)
    cmp/gt r3, r4                            ! input_value > 0x90?
    bf      .L_epilogue                      ! no (in dead zone 0x70..0x90) -> return
.L_palette_frame_check:
    mov.l @r13, r3                           ! r3 = *frame_mirror
    mov #0xC, r2                             ! r2 = 12
    cmp/hs r2, r3                            ! frame >= 12? (unsigned)
    bt      .L_palette_high_frame            ! yes -> use adjusted index
    mov.l @r13, r5                           ! r5 = *frame_mirror (frame index)
    shll2 r5                                 ! r5 = frame * 4
    shll2 r5                                 ! r5 = frame * 16
    shll2 r5                                 ! r5 = frame * 64 (palette entry size)
    mov.l   .L_ptr_palette_table, r3         ! r3 = palette_table base (sym_0605CA9C)
    add r3, r5                               ! r5 = &palette_table[frame] (src)
    bra     .L_palette_compute_cram          ! -> compute CRAM destination
    mov #0x40, r6                            ! (delay) r6 = 64 (copy size in bytes)
.L_palette_high_frame:
    mov #0x40, r6                            ! r6 = 64 (copy size in bytes)
    mov.l @r13, r5                           ! r5 = *frame_mirror
    add #-0x2, r5                            ! r5 = frame - 2 (adjust for high frames)
    shll2 r5                                 ! r5 = (frame-2) * 4
    shll2 r5                                 ! r5 = (frame-2) * 16
    shll2 r5                                 ! r5 = (frame-2) * 64
    mov.l   .L_ptr_palette_table, r3         ! r3 = palette_table base
    add r3, r5                               ! r5 = &palette_table[frame-2] (src)
.L_palette_compute_cram:
    mov.l   .L_ptr_frame_output, r4          ! r4 = &frame_output (sym_0607EAB8)
    mov.l   .L_vdp2_cram_0x000, r2           ! r2 = 0x25F00000 (VDP2 CRAM base)
    mov.l @r4, r4                            ! r4 = *frame_output (0 or 1)
    shll r4                                  ! r4 = frame_output * 2
    add #0x23, r4                            ! r4 = frame_output * 2 + 0x23
    shll2 r4                                 ! r4 <<= 2
    shll2 r4                                 ! r4 <<= 2
    shll r4                                  ! r4 <<= 1 (total: *2+0x23 << 5 = CRAM offset)
    jsr @r10                                 ! call memcpy_word_idx(dst=r4, src=r5, cnt=r6)
    add r2, r4                               ! (delay) r4 = VDP2_CRAM_base + offset
.L_epilogue:
    lds.l @r15+, pr                          ! restore return address
    mov.l @r15+, r8                          ! restore r8
    mov.l @r15+, r9                          ! restore r9
    mov.l @r15+, r10                         ! restore r10
    mov.l @r15+, r11                         ! restore r11
    mov.l @r15+, r12                         ! restore r12
    mov.l @r15+, r13                         ! restore r13
    rts                                      ! return
    mov.l @r15+, r14                         ! (delay) restore r14

    .global DAT_0601096e
DAT_0601096e:
    .2byte  0x00C0                           /* tile block size (192 bytes) */
.L_threshold_bwd_hi:
    .2byte  0x0090                           /* upper dead zone bound for palette skip */
    .2byte  0xFFFF                           /* alignment padding */
.L_ptr_dma_result_b2:
    .4byte  sym_06078898                     /* scroll Y accumulator (pair B, 2nd ref) */
.L_ptr_frame_idx_b2:
    .4byte  sym_060788A4                     /* frame index pair B (2nd ref) */
.L_ptr_frame_output:
    .4byte  sym_0607EAB8                     /* frame output (odd/even selector) */
.L_ptr_tile_table:
    .4byte  sym_0605D05C                     /* tile data lookup table base */
.L_ptr_game_state_idx:
    .4byte  sym_06059FFC                     /* current game state index */
.L_ptr_car_struct_base:
    .4byte  sym_06063F5C                     /* car struct array base pointer */
.L_ptr_palette_table:
    .4byte  sym_0605CA9C                     /* 64-byte palette entry table base */
.L_vdp2_cram_0x000:
    .4byte  0x25F00000                       /* VDP2 color RAM base address */
