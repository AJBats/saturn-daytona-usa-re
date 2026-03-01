
    .section .text.FUN_060078DC


    .global frame_end_commit
    .type frame_end_commit, @function
frame_end_commit:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.w   DAT_060079ce, r9
    mov.l   .L_sprite_index_table, r10
    mov.l   .L_frame_counter, r12
    mov.l   .L_timing_accumulator, r13
    mov.l   .L_commit_count, r14
    mov.l @r13, r3
    sub r9, r3
    mov.l r3, @r13
    mov.l @r14, r2
    cmp/hs r9, r2
    bt      .L_skip_dma_transfer
    mov.l @r13, r6
    mov.l   .L_sprite_staging, r5
    mov.l @r14, r4
    mov r6, r2
    extu.w r4, r4
    shll2 r6
    shll2 r2
    mov r4, r3
    shll r6
    shll2 r2
    shll2 r4
    shll2 r3
    add r2, r6
    shll r4
    shll2 r3
    mov.l   .L_sprite_data_base, r2
    add r3, r4
    extu.w r4, r4
    mov.l   .L_fn_memcpy_long, r3
    jsr @r3
    add r2, r4
    mov.l @r13, r6
    mov.w   .L_double_budget, r5
    mov.l @r14, r4
    mov.l   .L_fn_memcpy_word, r3
    shll r6
    add r10, r5
    shll r4
    jsr @r3
    add r10, r4
.L_skip_dma_transfer:
    mov.l @r13, r2
    mov r10, r5
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov.l r9, @r13
    mov.l   .L_fn_cmd_header_build, r3
    jsr @r3
    mov.l @r14, r4
    mov #0x20, r6
    mov.l   .L_phase_flag, r5
    mov.l   .L_vdp1_cmd_base, r11
    mov.l   .L_phase_data_base, r3
    mov.l   .L_fn_dma_transfer, r2
    mov.w @r5, r5
    shll2 r5
    shll2 r5
    shll r5
    add r3, r5
    jsr @r2
    mov.l @r11, r4
    mov.l   .L_vdp1_dma_buf, r3
    mov.l   .L_vdp1_write_ptr, r2
    mov.l r3, @r2
    mov.l @r12, r3
    add #0x1, r3
    mov.l r3, @r12
    bsr     vdp1_sprite_builder
    nop
    mov #0x1, r2
    mov.l   .L_frame_ready_flag, r3
    mov.l r2, @r3
    mov.l   .L_fn_subsys_update, r3
    jsr @r3
    nop
    mov.l @r12, r6
    mov.l   .L_vdp1_dma_buf, r5
    mov.l @r11, r4
    mov.l   .L_fn_dma_transfer, r3
    add #-0x1, r6
    shll2 r6
    shll2 r6
    shll r6
    jsr @r3
    add #0x20, r4
    mov.l @r12, r0
    mov.l @r11, r3
    mov.l   .L_vdp1_draw_end, r2
    shll2 r0
    shll2 r0
    shll r0
    add r3, r0
    mov.w r2, @r0
    mov.l   .L_display_flags, r4
    mov.l   .L_flag_frame_commit, r3
    mov.l @r4, r2
    or r3, r2
    mov r2, r0
    or #0x4, r0
    mov.l r0, @r4
    mov.l   .L_race_mode_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_clear_frame_flag
    mov.l   .L_flag_race_extra, r3
    mov.l @r4, r2
    or r3, r2
    mov.l r2, @r4
.L_clear_frame_flag:
    mov #0x0, r11
    mov.l   .L_frame_ready_flag, r3
    mov.l r11, @r3
    bra     .L_cleanup_return
    nop

    .global DAT_060079ce
DAT_060079ce:
    .2byte  0x0258
.L_double_budget:
    .2byte  0x04B0
    .2byte  0xFFFF
.L_sprite_index_table:
    .4byte  sym_0606A4F8
.L_frame_counter:
    .4byte  sym_0605A008
.L_timing_accumulator:
    .4byte  sym_060620D4
.L_commit_count:
    .4byte  sym_060620D0
.L_sprite_staging:
    .4byte  sym_0608E460
.L_sprite_data_base:
    .4byte  sym_0608AC20
.L_fn_memcpy_long:
    .4byte  memcpy_long_idx
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx
.L_fn_cmd_header_build:
    .4byte  sym_0602C494
.L_vdp1_cmd_base:
    .4byte  sym_06063F5C
.L_phase_flag:
    .4byte  sym_0605A016
.L_phase_data_base:
    .4byte  sym_0605A018
.L_fn_dma_transfer:
    .4byte  dma_transfer
.L_vdp1_dma_buf:
    .4byte  sym_0606BDFC
.L_vdp1_write_ptr:
    .4byte  sym_060785FC
.L_frame_ready_flag:
    .4byte  sym_0605A00C
.L_fn_subsys_update:
    .4byte  sym_060394C2
.L_vdp1_draw_end:
    .4byte  0x00008000                  /* VDP1 CMDCTRL draw-end marker */
.L_display_flags:
    .4byte  sym_0605B6D8
.L_flag_frame_commit:
    .4byte  0x20000000
.L_race_mode_flag:
    .4byte  sym_0607EAE0
.L_flag_race_extra:
    .4byte  0x08000000
.L_cleanup_return:
    mov.l   .L_fn_display_update, r3
    jsr @r3
    nop
    mov.l r11, @r14
    mov.l r11, @r12
    mov.l   .L_results_flag_src, r4
    mov.l   .L_results_flag_dest, r3
    mov.l @r4, r2
    mov.l r2, @r3
    mov.l r11, @r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global render_pass_extra
    .type render_pass_extra, @function
render_pass_extra:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_display_state, r5
    mov.w   DAT_06007a92, r4
    mov.w   DAT_06007a94, r0
    mov.l @r5, r3
    mov.l @(r0, r3), r2
    cmp/gt r4, r2
    bf      .L_use_obj_count
    bra     .L_calc_scale
    mov r4, r13
.L_use_obj_count:
    mov.l @r5, r13
    mov.w   DAT_06007a94, r0
    mov.l @(r0, r13), r13
.L_calc_scale:
    mov.l   .L_fn_fpmul, r14
    mov.l   .L_scale_factor, r5
    jsr @r14
    mov r13, r4
    mov.w   DAT_06007a96, r4
    add r0, r4
    mov.l   .L_widescreen_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_narrow_mode
    bra     .L_setup_coords
    mov #0x24, r11

    .global DAT_06007a92
DAT_06007a92:
    .2byte  0x2134

    .global DAT_06007a94
DAT_06007a94:
    .2byte  0x00E4

    .global DAT_06007a96
DAT_06007a96:
    .2byte  0x7000
.L_fn_display_update:
    .4byte  sym_06026CE0
.L_results_flag_src:
    .4byte  sym_06059F44
.L_results_flag_dest:
    .4byte  sym_0606BDF8
.L_display_state:
    .4byte  sym_0607E944
.L_fn_fpmul:
    .4byte  fpmul
.L_scale_factor:
    .4byte  0x0000D1B7
.L_widescreen_flag:
    .4byte  sym_06085FF4
.L_narrow_mode:
    mov #0x34, r11
.L_setup_coords:
    mov r15, r6
    mov.l   .L_fn_sincos, r3
    add #0x4, r6
    jsr @r3
    mov r15, r5
    mov.l   .L_fn_sign_extend, r12
    mov.l   .L_sprite_cmd_base, r13
    mov.l   .L_fp_screen_width, r4
    jsr @r14
    mov.l @r15, r5
    jsr @r12
    neg r0, r4
    add #0x8, r0
    exts.w r0, r0
    mov.w r0, @(8, r13)
    mov.l   .L_fp_screen_width, r4
    jsr @r14
    mov.l @(4, r15), r5
    jsr @r12
    mov r0, r4
    add r11, r0
    exts.w r0, r0
    mov.w r0, @(10, r13)
    mov.l   .L_fp_screen_height, r10
    mov.l   .L_fp_two, r4
    jsr @r14
    mov.l @(4, r15), r5
    mov r0, r8
    mov.l @r15, r5
    jsr @r14
    mov r10, r4
    mov r8, r4
    jsr @r12
    sub r0, r4
    add #0x8, r0
    exts.w r0, r0
    mov.w r0, @(12, r13)
    mov.l   .L_fp_two, r4
    jsr @r14
    mov.l @r15, r5
    mov r0, r8
    mov.l @(4, r15), r5
    jsr @r14
    mov r10, r4
    mov r8, r4
    jsr @r12
    add r0, r4
    add r11, r0
    exts.w r0, r0
    mov.w r0, @(14, r13)
    mov.l   .L_fp_coord_offset, r4
    jsr @r14
    mov.l @r15, r5
    jsr @r12
    neg r0, r4
    add #0x8, r0
    exts.w r0, r0
    mov.w r0, @(16, r13)
    mov.l   .L_fp_coord_offset, r4
    jsr @r14
    mov.l @(4, r15), r5
    jsr @r12
    mov r0, r4
    add r11, r0
    exts.w r0, r0
    mov.w r0, @(18, r13)
    mov.l   .L_fp_neg_two, r4
    jsr @r14
    mov.l @(4, r15), r5
    mov r0, r8
    mov.l @r15, r5
    jsr @r14
    mov r10, r4
    mov r8, r4
    jsr @r12
    sub r0, r4
    add #0x8, r0
    exts.w r0, r0
    mov.w r0, @(20, r13)
    mov.l   .L_fp_neg_two, r4
    jsr @r14
    mov.l @r15, r5
    mov r0, r8
    mov.l @(4, r15), r5
    jsr @r14
    mov r10, r4
    mov r8, r4
    jsr @r12
    add r0, r4
    add r11, r0
    mov.w r0, @(22, r13)
    mov.l   .L_vdp1_cmd_color, r0
    mov.w r0, @(6, r13)
    mov.l   .L_cmd_write_ptr, r14
    mov.l   .L_fn_cmd_copy, r3
    mov.l @r14, r5
    jsr @r3
    mov r13, r4
    mov.l   .L_cmd_counter, r4
    mov.l @r4, r2
    add #0x1, r2
    mov.l r2, @r4
    mov.l @r14, r3
    add #0x20, r3
    mov.l r3, @r14
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_fn_sincos:
    .4byte  sincos_pair
.L_fn_sign_extend:
    .4byte  swap_sign_ext
.L_sprite_cmd_base:
    .4byte  sym_06078604
.L_fp_screen_width:
    .4byte  0x00970000
.L_fp_screen_height:
    .4byte  0x00900000
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_fp_coord_offset:
    .4byte  0x00890000
.L_fp_neg_two:
    .4byte  0xFFFE0000                  /* -2.0 (16.16 fixed-point) */
.L_vdp1_cmd_color:
    .4byte  0x0000A3FF
.L_cmd_write_ptr:
    .4byte  sym_060785FC
.L_fn_cmd_copy:
    .4byte  sym_060280C4
.L_cmd_counter:
    .4byte  sym_0605A008

    .global vdp1_sprite_builder
    .type vdp1_sprite_builder, @function
vdp1_sprite_builder:
    mov.l r14, @-r15
    mov #0x0, r4
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_sprite_cmd, r8
    mov.l   .L_sprite_total, r9
    mov.l   .L_vdp1_draw_end_b, r10
    mov.l   .L_sprite_data, r13
    mov.l   .L_sprite_write_ptr, r14
    mov.l   .L_loop_counter_addr, r3
    mov.l r4, @r3
    mov.l   .L_sprite_enable_flag, r5
    mov.l   .L_vdp1_status, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst #0x8, r0
    bt      .L_clear_enable
    mov #0x1, r3
    mov.l r3, @r5
    bra     .L_begin_loop
    nop
.L_clear_enable:
    mov.l r4, @r5
.L_begin_loop:
    mov.l   .L_loop_counter_addr, r11
    bra     .L_check_count
    mov.l @r11, r11
.L_process_sprite:
    mov r11, r12
    mov.l   .L_sprite_idx_table, r3
    shll r12
    add r3, r12
    mov.w @r12, r12
    extu.w r12, r12
    extu.w r12, r0
    mov r0, r2
    shll2 r0
    shll2 r2
    shll r0
    shll2 r2
    add r2, r0
    extu.w r0, r0
    add r13, r0
    mov.w @(6, r0), r0
    extu.w r0, r0
    cmp/eq #0x9, r0
    bf      .L_normal_sprite
    mov r10, r6
    extu.w r12, r4
    mov.l @r14, r5
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    extu.w r4, r4
    mov.l   .L_fn_sprite_cmd_special, r3
    jsr @r3
    add r13, r4
    bra     .L_advance_ptr
    nop
.L_normal_sprite:
    mov.l @r14, r5
    extu.w r12, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    extu.w r4, r4
    jsr @r8
    add r13, r4
.L_advance_ptr:
    add #0x1, r11
    mov.l @r14, r2
    add #0x20, r2
    mov.l r2, @r14
.L_check_count:
    mov.l @r9, r3
    cmp/hs r3, r11
    bf      .L_process_sprite
    mov.l   .L_total_counter, r4
    mov.l @r9, r3
    mov.l @r4, r2
    add r3, r2
    mov.l r2, @r4
    mov.l   .L_game_state_flags, r3
    mov.l   .L_hud_render_mask, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_finalize
    mov.l   .L_fn_hud_render, r3
    jsr @r3
    nop
    bsr     render_pass_extra
    nop
.L_finalize:
    mov.l   .L_fn_post_sprite, r3
    jsr @r3
    nop
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_vdp2_update, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_fn_sprite_cmd:
    .4byte  sym_060280F8
.L_sprite_total:
    .4byte  sym_060620D0
.L_vdp1_draw_end_b:
    .4byte  0x00008000                  /* VDP1 CMDCTRL draw-end marker */
.L_sprite_data:
    .4byte  sym_0608AC20
.L_sprite_write_ptr:
    .4byte  sym_060785FC
.L_loop_counter_addr:
    .4byte  sym_06078620
.L_sprite_enable_flag:
    .4byte  sym_0607861C
.L_vdp1_status:
    .4byte  sym_06063DA0
.L_sprite_idx_table:
    .4byte  sym_0606A4F8
.L_fn_sprite_cmd_special:
    .4byte  sym_060281B8
.L_total_counter:
    .4byte  sym_0605A008
.L_game_state_flags:
    .4byte  sym_0607EBC4
.L_hud_render_mask:
    .4byte  0x20228000
.L_fn_hud_render:
    .4byte  sym_060333D8
.L_fn_post_sprite:
    .4byte  post_sprite_cleanup
.L_fn_vdp2_update:
    .4byte  vdp2_frame_update
