
    .section .text.FUN_06010760


    .global adv_anim_state
    .type adv_anim_state, @function
adv_anim_state:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov #0x1, r8
    mov #0x0, r9
    mov.l   .L_ptr_memcpy_word_idx, r10
    mov.l   .L_ptr_toggle_flag, r12
    mov.l   .L_ptr_frame_mirror, r13
    mov.l   .L_ptr_frame_counter, r14
    mov.l   .L_ptr_game_mode, r0
    bra     .L_dispatch_game_mode
    mov.b @r0, r0
.L_mode_frames_5:
    bra     .L_check_overlay_special
    mov #0x5, r4
.L_mode_frames_7:
    bra     .L_check_overlay_special
    mov #0x7, r4
.L_mode_frames_9:
    bra     .L_check_overlay_special
    mov #0x9, r4
.L_mode_frames_3:
    bra     .L_check_overlay_special
    mov #0x3, r4
.L_dispatch_game_mode:
    cmp/eq #0x1, r0
    bt      .L_mode_frames_5
    cmp/eq #0x2, r0
    bt      .L_mode_frames_5
    cmp/eq #0x3, r0
    bt      .L_mode_frames_7
    cmp/eq #0x4, r0
    bt      .L_mode_frames_5
    cmp/eq #0x5, r0
    bt      .L_mode_frames_7
    cmp/eq #0x6, r0
    bt      .L_mode_frames_7
    cmp/eq #0x7, r0
    bt      .L_mode_frames_9
    bra     .L_mode_frames_3
    nop
    .2byte  0xFFFF
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
    mov.l   .L_ptr_overlay_flags, r0
    mov.b @r0, r0
    cmp/eq #0x7, r0
    bf      .L_check_overlay_15
    mov #0xB, r4
.L_check_overlay_15:
    mov.l   .L_ptr_overlay_flags, r0
    mov.b @r0, r0
    cmp/eq #0xF, r0
    bf      .L_read_input
    mov #0xD, r4
.L_read_input:
    mov.l   .L_ptr_input_word, r0
    mov.l   .L_mask_low16, r3
    mov.w @r0, r0
    extu.w r0, r0
    xor r3, r0
    and #0xFF, r0
    mov.w   .L_threshold_fwd, r3
    extu.w r0, r11
    cmp/gt r3, r11
    bf      .L_check_backward
    mov.l   .L_fp_neg_one, r3
    mov.l   .L_ptr_anim_direction, r2
    mov.l r3, @r2
    mov #0x1E, r3
    mov.l   .L_ptr_timer_value, r2
    mov.l r3, @r2
    mov.l @r14, r3
    add #0x1, r3
    mov r3, r2
    mov.l r3, @r14
    cmp/gt r4, r2
    bf      .L_fwd_store_dma
    mov.l r9, @r14
.L_fwd_store_dma:
    mov.l   .L_fp_fwd_dma_size, r5
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_fwd_toggle_off
    extu.b r9, r3
    mov.b r3, @r12
    mov.l   .L_ptr_dma_result_a, r3
    mov.l r5, @r3
    mov.l @r14, r2
    mov.l   .L_ptr_frame_idx_a, r3
    mov.l r2, @r3
    bra     .L_check_backward
    nop
.L_fwd_toggle_off:
    mov.b r8, @r12
    mov.l   .L_ptr_dma_result_b, r3
    mov.l r5, @r3
    mov.l @r14, r2
    mov.l   .L_ptr_frame_idx_b, r3
    mov.l r2, @r3
.L_check_backward:
    extu.w r11, r2
    mov #0x70, r3
    cmp/ge r3, r2
    bt      .L_update_frame_output
    mov.l   .L_fp_one, r3
    mov.l   .L_ptr_anim_direction, r2
    mov.l r3, @r2
    mov #0x1E, r3
    mov.l   .L_ptr_timer_value, r2
    mov.l r3, @r2
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov r3, r2
    cmp/pz r2
    bt      .L_bwd_store_dma
    mov.l r4, @r14
.L_bwd_store_dma:
    mov.l   .L_fp_bwd_dma_size, r4
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_bwd_toggle_off
    extu.b r9, r3
    mov.b r3, @r12
    mov.l   .L_ptr_dma_result_a, r3
    mov.l r4, @r3
    mov.l @r14, r2
    mov.l   .L_ptr_frame_idx_a, r3
    mov.l r2, @r3
    bra     .L_update_frame_output
    nop
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
    mov.b r8, @r12
    mov.l   .L_ptr_dma_result_b2, r3
    mov.l r4, @r3
    mov.l @r14, r2
    mov.l   .L_ptr_frame_idx_b2, r3
    mov.l r2, @r3
.L_update_frame_output:
    mov.l @r14, r2
    mov.l r2, @r13
    mov r2, r3
    and r8, r3
    mov.l   .L_ptr_frame_output, r2
    mov.l r3, @r2
    mov.l @r13, r1
    mov #0xA, r2
    cmp/hs r2, r1
    bt      .L_palette_section
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_tile_lookup_toggle_off
    mov.w   DAT_0601096e, r6
    mov.l @r13, r5
    mov.l   .L_ptr_tile_table, r3
    mov.l   .L_ptr_game_state_idx, r4
    shll2 r5
    mov.l @r4, r4
    add r3, r5
    shll2 r4
    mov.l @r5, r5
    shll r4
    mov.l   .L_ptr_car_struct_base, r2
    mov.l @r2, r2
    add r2, r4
    mov r6, r1
    add #0x40, r1
    bra     .L_call_memcpy_tile
    add r1, r4
.L_tile_lookup_toggle_off:
    mov.w   DAT_0601096e, r6
    mov.l @r13, r5
    mov.l   .L_ptr_tile_table, r3
    mov.l   .L_ptr_game_state_idx, r4
    shll2 r5
    mov.l @r4, r4
    add r3, r5
    shll2 r4
    mov.l @r5, r5
    shll r4
    mov.l   .L_ptr_car_struct_base, r2
    mov.l @r2, r2
    add r2, r4
    add #0x40, r4
.L_call_memcpy_tile:
    jsr @r10
    nop
.L_palette_section:
    extu.w r11, r4
    mov #0x70, r3
    cmp/ge r3, r4
    bf      .L_palette_frame_check
    mov.w   .L_threshold_bwd_hi, r3
    cmp/gt r3, r4
    bf      .L_epilogue
.L_palette_frame_check:
    mov.l @r13, r3
    mov #0xC, r2
    cmp/hs r2, r3
    bt      .L_palette_high_frame
    mov.l @r13, r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov.l   .L_ptr_palette_table, r3
    add r3, r5
    bra     .L_palette_compute_cram
    mov #0x40, r6
.L_palette_high_frame:
    mov #0x40, r6
    mov.l @r13, r5
    add #-0x2, r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov.l   .L_ptr_palette_table, r3
    add r3, r5
.L_palette_compute_cram:
    mov.l   .L_ptr_frame_output, r4
    mov.l   .L_vdp2_cram_0x000, r2
    mov.l @r4, r4
    shll r4
    add #0x23, r4
    shll2 r4
    shll2 r4
    shll r4
    jsr @r10
    add r2, r4
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

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
