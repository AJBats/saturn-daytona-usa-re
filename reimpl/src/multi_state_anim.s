/* multi_state_anim -- Multi-State HUD Animation Handler
 * Translation unit: 0x060104E0 - 0x06010760  (640 bytes)
 *
 * Drives cyclic animation for multi-frame HUD elements (lap counter,
 * difficulty selector, race menu items). Dispatches on game mode (1-7)
 * to set the max frame count (3/5/7/9), with special-case overrides
 * for modes 7 and 15 (11/13 frames).
 *
 * Input r4 (flags word):
 *   bit 15 (0x8000) = advance animation forward  (increment frame)
 *   bit 14 (0x4000) = advance animation backward  (decrement frame)
 *   bits 15:14 (0xC000) = palette copy to VDP2 CRAM
 *
 * On each direction change the function:
 *   - Updates the animation direction in sym_0607889C (+1.0 or -1.0)
 *   - Wraps the frame counter (stored at sym_0607EADC)
 *   - Reads the toggle flag at sym_060788A8; if set, builds a
 *     DMA parameter block on the stack and calls the SCU DMA
 *     transfer (sym_060359E4 / sym_060357B8) to stream new tile data
 *   - Stores DMA source and frame index to sym_06078894/98 or
 *     sym_06078898/A4 depending on the toggle state
 *
 * For palette updates (bits 15:14):
 *   - Indexes into a 64-byte palette table at sym_0605CA9C
 *   - Computes VDP2 CRAM destination: (frame & 1) * 2 + 0x23 → address
 *   - Tail-calls memcpy_word_idx to copy palette block
 *
 * Called by: HUD update dispatcher (per-frame)
 * Calls: sym_060359E4 (DMA param setup), sym_060357B8 (DMA execute),
 *        dma_transfer, memcpy_word_idx
 */

    .section .text.FUN_060104E0


    .global multi_state_anim
    .type multi_state_anim, @function
multi_state_anim:
    mov.l r14, @-r15            ! save r14
    mov.l r13, @-r15            ! save r13
    mov.l r12, @-r15            ! save r12
    mov.l r11, @-r15            ! save r11
    mov.l r10, @-r15            ! save r10
    mov.l r9, @-r15             ! save r9
    mov.l r8, @-r15             ! save r8
    sts.l pr, @-r15             ! save return address
    mov.l   .L_ptr_frame_output, r8  ! r8 = &frame_output (sym_0607EAB8)
    mov #0x0, r9                ! r9 = 0 (constant: zero / clear value)
    mov #0x1, r10               ! r10 = 1 (constant: one / increment)
    mov.l   .L_ptr_toggle_flag, r12  ! r12 = &toggle_flag (sym_060788A8)
    mov.l   .L_ptr_frame_mirror, r13 ! r13 = &frame_mirror (sym_06078868)
    mov.l   .L_ptr_frame_counter, r14 ! r14 = &frame_counter (sym_0607EADC)
    mov r4, r11                 ! r11 = flags (input param)
    mov.l   .L_ptr_game_mode, r0  ! r0 = &game_mode byte (sym_0605AB16)
    bra     .L_dispatch_mode    ! jump to mode dispatch switch
    mov.b @r0, r0              ! (delay) r0 = *game_mode
.L_mode_5_frames:
    bra     .L_check_overrides  ! -> check special mode overrides
    mov #0x5, r4               ! (delay) max_frames = 5
    .4byte  0x00C0FFFF
.L_ptr_frame_counter:
    .4byte  sym_0607EADC
    .4byte  sym_06063D9C
    .4byte  0x0000FFFF
.L_ptr_frame_output:
    .4byte  sym_0607EAB8
.L_ptr_frame_mirror:
    .4byte  sym_06078868
    .4byte  dma_transfer
    .4byte  sym_0605D084
    .4byte  sym_06078884
    .4byte  sym_0605D060
    .4byte  sym_0605D05C
    .4byte  sym_0605D088
    .4byte  sym_06078880
.L_ptr_toggle_flag:
    .4byte  sym_060788A8
.L_ptr_game_mode:
    .4byte  sym_0605AB16
.L_mode_7_frames:
    bra     .L_check_overrides  ! -> check special mode overrides
    mov #0x7, r4               ! (delay) max_frames = 7
.L_mode_9_frames:
    bra     .L_check_overrides  ! -> check special mode overrides
    mov #0x9, r4               ! (delay) max_frames = 9
.L_mode_default:
    bra     .L_check_overrides  ! -> check special mode overrides (fallthrough)
    mov #0x3, r4               ! (delay) max_frames = 3 (default)
.L_dispatch_mode:
    cmp/eq #0x1, r0             ! mode == 1?
    bt      .L_mode_5_frames    !   yes -> 5 frames
    cmp/eq #0x2, r0             ! mode == 2?
    bt      .L_mode_5_frames    !   yes -> 5 frames
    cmp/eq #0x3, r0             ! mode == 3?
    bt      .L_mode_7_frames    !   yes -> 7 frames
    cmp/eq #0x4, r0             ! mode == 4?
    bt      .L_mode_5_frames    !   yes -> 5 frames
    cmp/eq #0x5, r0             ! mode == 5?
    bt      .L_mode_7_frames    !   yes -> 7 frames
    cmp/eq #0x6, r0             ! mode == 6?
    bt      .L_mode_7_frames    !   yes -> 7 frames
    cmp/eq #0x7, r0             ! mode == 7?
    bt      .L_mode_9_frames    !   yes -> 9 frames
    bra     .L_mode_default     ! all others -> 3 frames (default)
    nop                         ! (delay)
.L_check_overrides:
    mov.l   .L_ptr_overlay_flags, r0  ! r0 = &overlay_flags_hi (sym_0605AB17)
    mov.b @r0, r0              ! r0 = overlay_flags_hi byte
    cmp/eq #0x7, r0             ! flags == 0x7?
    bf      .L_check_mode_15    !   no -> check mode 15
    mov #0xB, r4               !   yes -> override max_frames = 11
.L_check_mode_15:
    mov.l   .L_ptr_overlay_flags, r0  ! r0 = &overlay_flags_hi (reload)
    mov.b @r0, r0              ! r0 = overlay_flags_hi byte
    cmp/eq #0xF, r0             ! flags == 0xF?
    bf      .L_check_direction  !   no -> proceed to direction check
    mov #0xD, r4               !   yes -> override max_frames = 13
.L_check_direction:
    mov.l   .L_ptr_anim_direction, r5  ! r5 = &anim_direction (sym_0607889C)
    extu.w r11, r2              ! r2 = flags (zero-extend to 16-bit)
    mov.l   .L_fp_half, r3     ! r3 = 0x8000 (bit 15 mask)
    and r3, r2                  ! r2 = flags & 0x8000
    tst r2, r2                  ! bit 15 set? (forward flag)
    bt      .L_check_reverse    !   no -> check reverse direction
    mov.l   .L_fp_neg_one, r3  ! r3 = -1.0 (0xFFFF0000 fixed-point)
    mov.l r3, @r5              ! anim_direction = -1.0 (forward playback)
    mov.l @r14, r2              ! r2 = frame_counter
    add #0x1, r2               ! r2 = frame_counter + 1
    mov r2, r3                  ! r3 = new frame value (for compare)
    mov.l r2, @r14              ! frame_counter = r2
    cmp/gt r4, r3               ! frame > max_frames?
    bf      .L_fwd_check_toggle !   no -> check toggle state
    mov.l r9, @r14              ! yes -> wrap: frame_counter = 0
.L_fwd_check_toggle:
    mov.b @r12, r0              ! r0 = toggle_flag byte
    extu.b r0, r0               ! zero-extend to 32-bit
    tst r0, r0                  ! toggle == 0?
    bt      .L_fwd_toggle_off   !   yes -> toggle is off path
    extu.b r9, r3               ! r3 = 0 (clear value)
    mov #0x0, r2               ! r2 = 0
    mov.b r3, @r12              ! toggle_flag = 0 (clear toggle)
    mov #0x0, r3               ! r3 = 0
    add #-0x8, r15              ! allocate 8 bytes on stack (pad)
    mov.l r2, @-r15             ! push 0 (DMA param[4])
    mov.l   .L_dma_src_addr, r2 ! r2 = 0x40280000 (VDP1 VRAM src)
    mov.l r2, @-r15             ! push DMA source address
    mov.l r3, @-r15             ! push 0 (DMA param[2])
    mov.l   .L_dma_dst_addr, r3 ! r3 = 0x40F00000 (VDP1 VRAM dst)
    mov.l r3, @-r15             ! push DMA dest address
    mov r15, r2                 ! r2 = current SP (params start)
    mov.l   .L_fn_dma_param_setup, r3 ! r3 = &dma_param_setup
    add #0x10, r2               ! r2 = SP + 0x10 (output buffer)
    jsr @r3                    ! call dma_param_setup(output, ...)
    mov.l r2, @-r15             ! (delay) push output ptr
    mov.l   .L_fn_dma_execute, r2 ! r2 = &dma_execute
    jsr @r2                    ! call dma_execute() -> r0 = result
    nop                         ! (delay)
    mov.l   .L_ptr_dma_result_a, r3 ! r3 = &dma_result_a (sym_06078894)
    mov.l r0, @r3              ! dma_result_a = DMA result
    mov.l @r14, r2              ! r2 = frame_counter
    mov.l   .L_ptr_frame_idx_a, r3 ! r3 = &frame_idx_a (sym_060788A0)
    mov.l r2, @r3              ! frame_idx_a = frame_counter
    bra     .L_update_output    ! -> update output and continue
    nop                         ! (delay)
.L_fwd_toggle_off:
    extu.b r10, r2              ! r2 = 1 (set value)
    mov #0x0, r3               ! r3 = 0
    mov.b r2, @r12              ! toggle_flag = 1 (set toggle)
    add #-0x8, r15              ! allocate 8 bytes on stack (pad)
    mov #0x0, r2               ! r2 = 0
    mov.l r3, @-r15             ! push 0 (DMA param[4])
    mov.l   .L_dma_src_addr, r3 ! r3 = 0x40280000 (VDP1 VRAM src)
    mov.l r3, @-r15             ! push DMA source address
    mov.l r2, @-r15             ! push 0 (DMA param[2])
    mov.l   .L_dma_dst_addr, r2 ! r2 = 0x40F00000 (VDP1 VRAM dst)
    mov.l r2, @-r15             ! push DMA dest address
    mov r15, r3                 ! r3 = current SP (params start)
    mov.l   .L_fn_dma_param_setup, r2 ! r2 = &dma_param_setup
    add #0x10, r3               ! r3 = SP + 0x10 (output buffer)
    jsr @r2                    ! call dma_param_setup(output, ...)
    mov.l r3, @-r15             ! (delay) push output ptr
    mov.l   .L_fn_dma_execute, r3 ! r3 = &dma_execute
    jsr @r3                    ! call dma_execute() -> r0 = result
    nop                         ! (delay)
    mov.l   .L_ptr_dma_result_b, r3 ! r3 = &dma_result_b (sym_06078898)
    mov.l r0, @r3              ! dma_result_b = DMA result
    mov.l @r14, r2              ! r2 = frame_counter
    mov.l   .L_ptr_frame_idx_b, r3 ! r3 = &frame_idx_b (sym_060788A4)
    mov.l r2, @r3              ! frame_idx_b = frame_counter
    bra     .L_update_output    ! -> update output and continue
    nop                         ! (delay)
.L_check_reverse:
    extu.w r11, r2              ! r2 = flags (zero-extend to 16-bit)
    mov.w   DAT_0601064a, r3   ! r3 = 0x4000 (bit 14 mask)
    and r3, r2                  ! r2 = flags & 0x4000
    tst r2, r2                  ! bit 14 set? (reverse flag)
    bt      .L_update_output    !   no -> skip to output update
    mov.l   .L_fp_one, r3     ! r3 = +1.0 (0x00010000 fixed-point)
    mov.l r3, @r5              ! anim_direction = +1.0 (reverse playback)
    mov.l @r14, r2              ! r2 = frame_counter
    add #-0x1, r2              ! r2 = frame_counter - 1
    mov r2, r3                  ! r3 = new frame value (for compare)
    mov.l r2, @r14              ! frame_counter = r2
    cmp/pz r3                   ! frame >= 0?
    bt      .L_rev_check_toggle !   yes -> check toggle state
    mov.l r4, @r14              ! no -> wrap: frame_counter = max_frames
.L_rev_check_toggle:
    mov.l   .L_reverse_offset, r4 ! r4 = 0xFFF40000 (-12.0 fixed-point offset)
    mov.b @r12, r0              ! r0 = toggle_flag byte
    extu.b r0, r0               ! zero-extend to 32-bit
    tst r0, r0                  ! toggle == 0?
    bt      .L_rev_toggle_off   !   yes -> toggle is off path
    extu.b r9, r3               ! r3 = 0 (clear value)
    mov.b r3, @r12              ! toggle_flag = 0 (clear toggle)
    mov.l   .L_ptr_dma_result_a, r3 ! r3 = &dma_result_a (sym_06078894)
    mov.l r4, @r3              ! dma_result_a = reverse offset
    mov.l @r14, r2              ! r2 = frame_counter
    mov.l   .L_ptr_frame_idx_a, r3 ! r3 = &frame_idx_a (sym_060788A0)
    mov.l r2, @r3              ! frame_idx_a = frame_counter
    bra     .L_update_output    ! -> update output and continue
    nop                         ! (delay)

    .global DAT_0601064a
DAT_0601064a:
    .2byte  0x4000
.L_ptr_overlay_flags:
    .4byte  sym_0605AB17
.L_ptr_anim_direction:
    .4byte  sym_0607889C
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_fp_neg_one:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_dma_src_addr:
    .4byte  0x40280000
.L_dma_dst_addr:
    .4byte  0x40F00000
.L_fn_dma_param_setup:
    .4byte  sym_060359E4
.L_fn_dma_execute:
    .4byte  sym_060357B8
.L_ptr_dma_result_a:
    .4byte  sym_06078894
.L_ptr_frame_idx_a:
    .4byte  sym_060788A0
.L_ptr_dma_result_b:
    .4byte  sym_06078898
.L_ptr_frame_idx_b:
    .4byte  sym_060788A4
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_reverse_offset:
    .4byte  0xFFF40000
.L_rev_toggle_off:
    mov.b r10, @r12             ! toggle_flag = 1 (set toggle)
    mov.l   .L_ptr_dma_result_b2, r3 ! r3 = &dma_result_b (sym_06078898)
    mov.l r4, @r3              ! dma_result_b = reverse offset
    mov.l @r14, r2              ! r2 = frame_counter
    mov.l   .L_ptr_frame_idx_b2, r3 ! r3 = &frame_idx_b (sym_060788A4)
    mov.l r2, @r3              ! frame_idx_b = frame_counter
.L_update_output:
    mov.l @r14, r2              ! r2 = frame_counter
    mov.l r2, @r13              ! frame_mirror = frame_counter
    mov r2, r3                  ! r3 = frame_counter
    and r10, r3                 ! r3 = frame & 1 (low bit = odd/even)
    mov.l r3, @r8              ! frame_output = frame & 1
    mov #0xA, r3               ! r3 = 10 (tile DMA threshold)
    mov.l @r13, r2              ! r2 = frame_mirror
    cmp/hs r3, r2               ! frame >= 10?
    bt      .L_check_palette    !   yes -> skip tile DMA, go to palette
    mov.b @r12, r0              ! r0 = toggle_flag byte
    extu.b r0, r0               ! zero-extend to 32-bit
    tst r0, r0                  ! toggle == 0?
    bt      .L_tile_toggle_off  !   yes -> toggle off path
    mov.w   .L_dma_size, r6   ! r6 = 0xC0 (192 bytes DMA size)
    mov.l @r13, r5              ! r5 = frame_mirror (index)
    shll2 r5                    ! r5 = frame * 4 (dword offset)
    mov.l   .L_ptr_tile_table, r3 ! r3 = tile_table base (sym_0605D05C)
    add r3, r5                  ! r5 = &tile_table[frame]
    mov.l   .L_ptr_dma_dst_on, r4 ! r4 = &dma_dst_on (sym_06078880)
    bra     .L_do_tile_dma      ! -> call dma_transfer
    mov.l @r5, r5              ! (delay) r5 = tile_table[frame] (src ptr)
.L_tile_toggle_off:
    mov.w   .L_dma_size, r6   ! r6 = 0xC0 (192 bytes DMA size)
    mov.l @r13, r5              ! r5 = frame_mirror (index)
    shll2 r5                    ! r5 = frame * 4 (dword offset)
    mov.l   .L_ptr_tile_table, r3 ! r3 = tile_table base (sym_0605D05C)
    add r3, r5                  ! r5 = &tile_table[frame]
    mov.l @r5, r5              ! r5 = tile_table[frame] (src ptr)
    mov.l   .L_ptr_dma_dst_off, r4 ! r4 = &dma_dst_off (sym_06078884)
.L_do_tile_dma:
    mov.l   .L_fn_dma_transfer, r2 ! r2 = &dma_transfer
    jsr @r2                    ! call dma_transfer(dst=@r4, src=r5, size=r6)
    mov.l @r4, r4              ! (delay) r4 = *dma_dst (destination addr)
.L_check_palette:
    extu.w r11, r11             ! r11 = flags (zero-extend to 16-bit)
    mov.l   .L_mask_0xC000, r3 ! r3 = 0xC000 (bits 15:14 mask)
    and r3, r11                 ! r11 = flags & 0xC000
    tst r11, r11                ! either bit 15 or 14 set?
    bt      .L_epilogue_rts     !   no -> return (no palette update)
    mov #0xC, r2               ! r2 = 12 (palette frame threshold)
    mov.l @r13, r3              ! r3 = frame_mirror
    cmp/hs r2, r3               ! frame >= 12?
    bt      .L_pal_high_frame   !   yes -> use adjusted palette index
    mov.l @r13, r5              ! r5 = frame_mirror (palette index)
    shll2 r5                    ! r5 *= 4
    shll2 r5                    ! r5 *= 4 (total: *16)
    shll2 r5                    ! r5 *= 4 (total: *64 = 0x40 per entry)
    mov.l   .L_ptr_palette_table, r3 ! r3 = palette_table base (sym_0605CA9C)
    add r3, r5                  ! r5 = &palette_table[frame * 64]
    bra     .L_calc_cram_dest   ! -> calculate CRAM destination
    mov #0x40, r6              ! (delay) r6 = 64 bytes (palette size)
.L_pal_high_frame:
    mov #0x40, r6              ! r6 = 64 bytes (palette size)
    mov.l @r13, r5              ! r5 = frame_mirror
    add #-0x2, r5              ! r5 = frame - 2 (adjusted index)
    shll2 r5                    ! r5 *= 4
    shll2 r5                    ! r5 *= 4 (total: *16)
    shll2 r5                    ! r5 *= 4 (total: *64 = 0x40 per entry)
    mov.l   .L_ptr_palette_table, r3 ! r3 = palette_table base (sym_0605CA9C)
    add r3, r5                  ! r5 = &palette_table[(frame-2) * 64]
.L_calc_cram_dest:
    mov.l @r8, r4               ! r4 = frame_output (0 or 1)
    shll r4                     ! r4 *= 2
    add #0x23, r4               ! r4 = (frame_output * 2) + 0x23
    shll2 r4                    ! r4 *= 4
    shll2 r4                    ! r4 *= 4 (total: *32)
    shll r4                     ! r4 *= 2 (total: *64 → CRAM bank offset)
    mov.l   .L_vdp2_cram_0x000, r2 ! r2 = 0x25F00000 (VDP2 CRAM base)
    add r2, r4                  ! r4 = VDP2 CRAM dest address
    lds.l @r15+, pr             ! restore return address
    mov.l @r15+, r8             ! restore r8
    mov.l @r15+, r9             ! restore r9
    mov.l @r15+, r10            ! restore r10
    mov.l @r15+, r11            ! restore r11
    mov.l @r15+, r12            ! restore r12
    mov.l @r15+, r13            ! restore r13
    mov.l   .L_fn_memcpy_word, r2 ! r2 = &memcpy_word_idx
    jmp @r2                    ! tail-call memcpy_word_idx(cram_dst, pal_src, size)
    mov.l @r15+, r14            ! (delay) restore r14
.L_epilogue_rts:
    lds.l @r15+, pr             ! restore return address
    mov.l @r15+, r8             ! restore r8
    mov.l @r15+, r9             ! restore r9
    mov.l @r15+, r10            ! restore r10
    mov.l @r15+, r11            ! restore r11
    mov.l @r15+, r12            ! restore r12
    mov.l @r15+, r13            ! restore r13
    rts                         ! return
    mov.l @r15+, r14            ! (delay) restore r14
.L_dma_size:
    .2byte  0x00C0
.L_ptr_dma_result_b2:
    .4byte  sym_06078898
.L_ptr_frame_idx_b2:
    .4byte  sym_060788A4
.L_ptr_tile_table:
    .4byte  sym_0605D05C
.L_ptr_dma_dst_on:
    .4byte  sym_06078880
.L_ptr_dma_dst_off:
    .4byte  sym_06078884
.L_fn_dma_transfer:
    .4byte  dma_transfer
.L_mask_0xC000:
    .4byte  0x0000C000                  /* bits 15:14 mask */
.L_ptr_palette_table:
    .4byte  sym_0605CA9C
.L_vdp2_cram_0x000:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx
