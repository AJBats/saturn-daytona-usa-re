
    .section .text.FUN_060104E0


    .global multi_state_anim
    .type multi_state_anim, @function
multi_state_anim:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_ptr_frame_output, r8
    mov #0x0, r9
    mov #0x1, r10
    mov.l   .L_ptr_toggle_flag, r12
    mov.l   .L_ptr_frame_mirror, r13
    mov.l   .L_ptr_frame_counter, r14
    mov r4, r11
    mov.l   .L_ptr_game_mode, r0
    bra     .L_dispatch_mode
    mov.b @r0, r0
.L_mode_5_frames:
    bra     .L_check_overrides
    mov #0x5, r4
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
    bra     .L_check_overrides
    mov #0x7, r4
.L_mode_9_frames:
    bra     .L_check_overrides
    mov #0x9, r4
.L_mode_default:
    bra     .L_check_overrides
    mov #0x3, r4
.L_dispatch_mode:
    cmp/eq #0x1, r0
    bt      .L_mode_5_frames
    cmp/eq #0x2, r0
    bt      .L_mode_5_frames
    cmp/eq #0x3, r0
    bt      .L_mode_7_frames
    cmp/eq #0x4, r0
    bt      .L_mode_5_frames
    cmp/eq #0x5, r0
    bt      .L_mode_7_frames
    cmp/eq #0x6, r0
    bt      .L_mode_7_frames
    cmp/eq #0x7, r0
    bt      .L_mode_9_frames
    bra     .L_mode_default
    nop
.L_check_overrides:
    mov.l   .L_ptr_overlay_flags, r0
    mov.b @r0, r0
    cmp/eq #0x7, r0
    bf      .L_check_mode_15
    mov #0xB, r4
.L_check_mode_15:
    mov.l   .L_ptr_overlay_flags, r0
    mov.b @r0, r0
    cmp/eq #0xF, r0
    bf      .L_check_direction
    mov #0xD, r4
.L_check_direction:
    mov.l   .L_ptr_anim_direction, r5
    extu.w r11, r2
    mov.l   .L_fp_half, r3
    and r3, r2
    tst r2, r2
    bt      .L_check_reverse
    mov.l   .L_fp_neg_one, r3
    mov.l r3, @r5
    mov.l @r14, r2
    add #0x1, r2
    mov r2, r3
    mov.l r2, @r14
    cmp/gt r4, r3
    bf      .L_fwd_check_toggle
    mov.l r9, @r14
.L_fwd_check_toggle:
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_fwd_toggle_off
    extu.b r9, r3
    mov #0x0, r2
    mov.b r3, @r12
    mov #0x0, r3
    add #-0x8, r15
    mov.l r2, @-r15
    mov.l   .L_dma_src_addr, r2
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l   .L_dma_dst_addr, r3
    mov.l r3, @-r15
    mov r15, r2
    mov.l   .L_fn_dma_param_setup, r3
    add #0x10, r2
    jsr @r3
    mov.l r2, @-r15
    mov.l   .L_fn_dma_execute, r2
    jsr @r2
    nop
    mov.l   .L_ptr_dma_result_a, r3
    mov.l r0, @r3
    mov.l @r14, r2
    mov.l   .L_ptr_frame_idx_a, r3
    mov.l r2, @r3
    bra     .L_update_output
    nop
.L_fwd_toggle_off:
    extu.b r10, r2
    mov #0x0, r3
    mov.b r2, @r12
    add #-0x8, r15
    mov #0x0, r2
    mov.l r3, @-r15
    mov.l   .L_dma_src_addr, r3
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l   .L_dma_dst_addr, r2
    mov.l r2, @-r15
    mov r15, r3
    mov.l   .L_fn_dma_param_setup, r2
    add #0x10, r3
    jsr @r2
    mov.l r3, @-r15
    mov.l   .L_fn_dma_execute, r3
    jsr @r3
    nop
    mov.l   .L_ptr_dma_result_b, r3
    mov.l r0, @r3
    mov.l @r14, r2
    mov.l   .L_ptr_frame_idx_b, r3
    mov.l r2, @r3
    bra     .L_update_output
    nop
.L_check_reverse:
    extu.w r11, r2
    mov.w   DAT_0601064a, r3
    and r3, r2
    tst r2, r2
    bt      .L_update_output
    mov.l   .L_fp_one, r3
    mov.l r3, @r5
    mov.l @r14, r2
    add #-0x1, r2
    mov r2, r3
    mov.l r2, @r14
    cmp/pz r3
    bt      .L_rev_check_toggle
    mov.l r4, @r14
.L_rev_check_toggle:
    mov.l   .L_reverse_offset, r4
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_rev_toggle_off
    extu.b r9, r3
    mov.b r3, @r12
    mov.l   .L_ptr_dma_result_a, r3
    mov.l r4, @r3
    mov.l @r14, r2
    mov.l   .L_ptr_frame_idx_a, r3
    mov.l r2, @r3
    bra     .L_update_output
    nop

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
    mov.b r10, @r12
    mov.l   .L_ptr_dma_result_b2, r3
    mov.l r4, @r3
    mov.l @r14, r2
    mov.l   .L_ptr_frame_idx_b2, r3
    mov.l r2, @r3
.L_update_output:
    mov.l @r14, r2
    mov.l r2, @r13
    mov r2, r3
    and r10, r3
    mov.l r3, @r8
    mov #0xA, r3
    mov.l @r13, r2
    cmp/hs r3, r2
    bt      .L_check_palette
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_tile_toggle_off
    mov.w   .L_dma_size, r6
    mov.l @r13, r5
    shll2 r5
    mov.l   .L_ptr_tile_table, r3
    add r3, r5
    mov.l   .L_ptr_dma_dst_on, r4
    bra     .L_do_tile_dma
    mov.l @r5, r5
.L_tile_toggle_off:
    mov.w   .L_dma_size, r6
    mov.l @r13, r5
    shll2 r5
    mov.l   .L_ptr_tile_table, r3
    add r3, r5
    mov.l @r5, r5
    mov.l   .L_ptr_dma_dst_off, r4
.L_do_tile_dma:
    mov.l   .L_fn_dma_transfer, r2
    jsr @r2
    mov.l @r4, r4
.L_check_palette:
    extu.w r11, r11
    mov.l   .L_mask_0xC000, r3
    and r3, r11
    tst r11, r11
    bt      .L_epilogue_rts
    mov #0xC, r2
    mov.l @r13, r3
    cmp/hs r2, r3
    bt      .L_pal_high_frame
    mov.l @r13, r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov.l   .L_ptr_palette_table, r3
    add r3, r5
    bra     .L_calc_cram_dest
    mov #0x40, r6
.L_pal_high_frame:
    mov #0x40, r6
    mov.l @r13, r5
    add #-0x2, r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov.l   .L_ptr_palette_table, r3
    add r3, r5
.L_calc_cram_dest:
    mov.l @r8, r4
    shll r4
    add #0x23, r4
    shll2 r4
    shll2 r4
    shll r4
    mov.l   .L_vdp2_cram_0x000, r2
    add r2, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_memcpy_word, r2
    jmp @r2
    mov.l @r15+, r14
.L_epilogue_rts:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
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
