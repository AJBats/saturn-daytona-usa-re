
    .section .text.FUN_06010BC4


    .global graphics_mode_setup
    .type graphics_mode_setup, @function
graphics_mode_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov #0x1, r9
    mov.l   .L_ptr_scroll_x_accum, r10
    mov.l   .L_ptr_scroll_y_accum, r11
    mov.l   .L_ptr_render_budget, r12
    mov.w   .L_hw_status_addr_lo, r13
    mov.w   DAT_06010c4e, r14
    mov.w   .L_rotation_step, r6
    mov.l   .L_ptr_rotation_angle, r5
    mov.l   .L_ptr_display_active, r0
    mov.b @r0, r0
    tst r0, r0
    bf/s    .L_display_active_path
    mov #0x0, r4
    bra     .L_display_inactive_path
    nop
.L_display_active_path:
    mov.w @r5, r3
    add r6, r3
    mov.w r3, @r5
    mov.l   .L_ptr_scroll_delta, r5
    mov.l @r10, r2
    mov.l @r5, r3
    add r3, r2
    mov.l r2, @r10
    mov.l @r11, r2
    mov.l @r5, r3
    add r3, r2
    mov.l r2, @r11
    mov.l   .L_ptr_scroll_dir_byte, r6
    mov.l @r5, r2
    cmp/pz r2
    bf      .L_scroll_delta_negative
    mov.b @r6, r0
    bra     .L_dispatch_positive
    extu.b r0, r0
.L_check_scroll_x_pos:
    mov.l @r10, r2
    cmp/pz r2
    bf      .L_setup_render_params
    mov.l r4, @r10
    bra     .L_setup_render_params
    mov.l r4, @r5
.L_check_scroll_y_pos:
    mov.l @r11, r2
    cmp/pz r2
    bf      .L_setup_render_params
    mov.l r4, @r11
    bra     .L_setup_render_params
    mov.l r4, @r5
.L_dispatch_positive:
    cmp/eq #0x0, r0
    bt      .L_check_scroll_x_pos
    cmp/eq #0x1, r0
    bt      .L_check_scroll_y_pos
    bra     .L_setup_render_params
    nop
.L_scroll_delta_negative:
    mov.b @r6, r0
    bra     .L_dispatch_negative
    extu.b r0, r0
.L_check_scroll_x_neg:
    mov.l @r10, r2
    cmp/pl r2
    bt      .L_setup_render_params
    mov.l r4, @r10
    bra     .L_setup_render_params
    mov.l r4, @r5
.L_hw_status_addr_lo:
    .2byte  0xFE11                       /* hw status register addr low 16 bits */

    .global DAT_06010c4e
DAT_06010c4e:
    .2byte  0x0080                       /* bit 7 poll mask for hw status */
.L_rotation_step:
    .2byte  0x0100                       /* rotation angle step per frame */
    .2byte  0xFFFF                       /* padding */
    .4byte  0xAB110BFF                   /* unreferenced pool data */
    .4byte  sym_0607EAB8                 /* unreferenced pool ptr */
    .4byte  sym_0604483C                 /* hw status register full addr */
.L_ptr_scroll_x_accum:
    .4byte  sym_06078894                 /* scroll X position accumulator */
.L_ptr_scroll_y_accum:
    .4byte  sym_06078898                 /* scroll Y position accumulator */
.L_ptr_render_budget:
    .4byte  sym_0608A52C                 /* render budget counter */
.L_ptr_rotation_angle:
    .4byte  sym_06078878                 /* current Y rotation angle (16-bit) */
.L_ptr_display_active:
    .4byte  sym_06085FF4                 /* display active flag (byte) */
.L_ptr_scroll_delta:
    .4byte  sym_0607889C                 /* per-frame scroll delta */
.L_ptr_scroll_dir_byte:
    .4byte  sym_060788A8                 /* scroll direction / split-screen flag */
.L_check_scroll_y_neg:
    mov.l @r11, r2
    cmp/pl r2
    bt      .L_setup_render_params
    mov.l r4, @r11
    bra     .L_setup_render_params
    mov.l r4, @r5
.L_dispatch_negative:
    cmp/eq #0x0, r0
    bt      .L_check_scroll_x_neg
    cmp/eq #0x1, r0
    bt      .L_check_scroll_y_neg
.L_setup_render_params:
    .byte   0xB2, 0xA7    /* bsr 0x060111E2 — call lap_progress_indicator */
    nop
    mov.l @r12, r2
    mov.l   .L_ptr_mat_vec_transform, r3
    add #0x30, r2
    jsr @r3
    mov.l r2, @r12
    mov.l   .L_ptr_active_flag_store, r3
    mov.l r9, @r3
    mov.l @r11, r2
    mov.l   .L_ptr_scroll_y_store, r3
    mov.l r2, @r3
    mov.l   .L_val_neg_z_pos, r2
    mov.l   .L_ptr_cfg_z_pos, r3
    mov.l r2, @r3
    mov.l   .L_val_x_pos, r2
    mov.l   .L_ptr_cfg_x_pos, r3
    mov.l r2, @r3
    mov.l   .L_ptr_race_pos_track, r2
    mov.l   .L_ptr_secondary_callback, r3
    mov.l r2, @r3
    mov.l   .L_mask_low16, r2
    mov.l   .L_ptr_vdp2_tvmd, r3
    mov.w r2, @r3
    mov.l   .L_val_x_pos, r7
    mov.l   .L_val_neg_z_pos, r6
    mov.l @r10, r5
    .byte   0xB0, 0x65    /* bsr 0x06010D94 — call vdp_mode_select */
    mov #0x0, r4
.L_poll_hw_status_a:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_poll_hw_status_a
    mov.b @r13, r0
    mov.l   .L_ptr_render_finalize, r3
    and #0xF, r0
    jsr @r3
    mov.b r0, @r13
    bra     .L_epilogue
    nop
.L_display_inactive_path:
    mov.l   .L_ptr_state_counter, r7
    mov.l r9, @r7
    mov.w @r5, r2
    add r6, r2
    .byte   0xB3, 0x11    /* bsr 0x06011310 — call position_ranking_display */
    mov.w r2, @r5
    mov.l @r12, r2
    mov.l   .L_ptr_mat_vec_transform, r3
    add #0x30, r2
    jsr @r3
    mov.l r2, @r12
    mov.l   .L_ptr_active_flag_store, r3
    mov.l r9, @r3
    mov.l   .L_val_scroll_y_alt, r2
    mov.l   .L_ptr_scroll_y_store, r3
    mov.l r2, @r3
    mov.l   .L_fp_neg_one, r2
    mov.l   .L_ptr_cfg_z_pos, r3
    mov.l r2, @r3
    mov.l   .L_val_x_pos_alt, r2
    mov.l   .L_ptr_cfg_x_pos, r3
    mov.l r2, @r3
    mov.l   .L_ptr_race_pos_track, r2
    mov.l   .L_ptr_secondary_callback, r3
    mov.l r2, @r3
    mov.l   .L_mask_low16, r2
    mov.l   .L_ptr_vdp2_tvmd, r3
    mov.w r2, @r3
    mov.l   .L_val_x_pos_alt, r7
    mov.l   .L_fp_neg_one, r6
    mov.l   .L_val_y_pos_alt, r5
    .byte   0xB0, 0x38    /* bsr 0x06010D94 — call vdp_mode_select */
    mov #0x0, r4
.L_poll_hw_status_b:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_poll_hw_status_b
    mov.b @r13, r0
    mov.l   .L_ptr_render_finalize, r3
    and #0xF, r0
    jsr @r3
    mov.b r0, @r13
.L_epilogue:
    mov.l @r12, r2
    add #-0x30, r2
    mov.l r2, @r12
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF                       /* padding */
.L_ptr_mat_vec_transform:
    .4byte  sym_060270D0                 /* mat_vec_transform function */
.L_ptr_active_flag_store:
    .4byte  sym_0607884C                 /* rendering active flag */
.L_ptr_scroll_y_store:
    .4byte  sym_06078850                 /* scroll Y parameter output */
.L_val_neg_z_pos:
    .4byte  0xFFFF3334                   /* -0.8 (16.16 fixed-point Z position) */
.L_ptr_cfg_z_pos:
    .4byte  sym_06078854                 /* config Z position output */
.L_val_x_pos:
    .4byte  0x00063333                   /* 6.2 (16.16 fixed-point X position) */
.L_ptr_cfg_x_pos:
    .4byte  sym_06078858                 /* config X position output */
.L_ptr_race_pos_track:
    .4byte  race_position_track          /* secondary SH-2 callback function */
.L_ptr_secondary_callback:
    .4byte  sym_06063574                 /* secondary SH-2 callback pointer */
.L_mask_low16:
    .4byte  0x0000FFFF                   /* low 16-bit mask (0xFFFF for VDP2) */
.L_ptr_vdp2_tvmd:
    .4byte  0x21000000                   /* VDP2 TVMD register (cache-through) */
.L_ptr_render_finalize:
    .4byte  sym_0603C000                 /* render finalize function */
.L_ptr_state_counter:
    .4byte  sym_060788A0                 /* game state counter */
.L_val_scroll_y_alt:
    .4byte  0x00038000                   /* 3.5 (16.16 fixed-point Y, path B) */
.L_fp_neg_one:
    .4byte  0xFFFF0000                   /* -1.0 (16.16 fixed-point Z, path B) */
.L_val_x_pos_alt:
    .4byte  0x0006B333                   /* 6.7 (16.16 fixed-point X, path B) */
.L_val_y_pos_alt:
    .4byte  0xFFFC8000                   /* -3.5 (16.16 fixed-point Y, path B) */
