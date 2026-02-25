/* graphics_mode_setup -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06010BC4 - 0x06010D94
 *
 * Graphics Mode Setup — Race Rendering Pipeline Configuration
 *
 * Configures the 3D rendering pipeline for race mode. Initializes scroll
 * position accumulators, render budget, secondary SH-2 callback pointer,
 * and VDP hardware registers, then dispatches vdp_mode_select to set up
 * the per-channel transform chain.
 *
 * Two paths based on display-active flag (sym_06085FF4):
 *
 *   Path A (display active, bf branch):
 *     1. Advance rotation angle by 0x100 (sym_06078878)
 *     2. Accumulate scroll deltas into X/Y accumulators (sym_06078894/98)
 *     3. If scroll delta >= 0: check X or Y accumulator overflow
 *        (positive → clamp to zero if exceeded)
 *     4. If scroll delta < 0: check X or Y accumulator underflow
 *        (negative → clamp to zero if underflowed)
 *     5. Call lap_progress_indicator (BSR 0x060111E2)
 *     6. Advance render budget by 0x30
 *     7. Call mat_vec_transform (sym_060270D0) for coordinate setup
 *     8. Store config: active flag, scroll Y, fixed-point params,
 *        race_position_track callback, 0xFFFF to VDP2 TVMD
 *     9. Call vdp_mode_select with config vector
 *    10. Poll hardware status register for render complete
 *    11. Call sym_0603C000 (render finalize)
 *    12. Restore render budget by -0x30
 *
 *   Path B (display inactive, early exit):
 *     1. Store state counter flag
 *     2. Advance rotation angle by 0x100
 *     3. Call position_ranking_display (BSR 0x06011310)
 *     4. Same render budget / VDP / callback setup with alternate values
 *     5. Call vdp_mode_select, poll, finalize, restore budget
 *
 * Registers (callee-saved):
 *   r9  = 0x1 (active flag constant)
 *   r10 = &scroll_x_accum (sym_06078894)
 *   r11 = &scroll_y_accum (sym_06078898)
 *   r12 = &render_budget (sym_0608A52C)
 *   r13 = &hw_status_reg (sym_0604483C), low byte read
 *   r14 = 0x0080 (bit 7 mask for hardware poll)
 *
 * Called by: race start initialization (FUN_060120C8)
 * Calls: lap_progress_indicator, position_ranking_display,
 *        mat_vec_transform, vdp_mode_select, sym_0603C000
 */

    .section .text.FUN_06010BC4


    .global graphics_mode_setup
    .type graphics_mode_setup, @function
graphics_mode_setup:
    mov.l r14, @-r15                     ! save r14
    mov.l r13, @-r15                     ! save r13
    mov.l r12, @-r15                     ! save r12
    mov.l r11, @-r15                     ! save r11
    mov.l r10, @-r15                     ! save r10
    mov.l r9, @-r15                      ! save r9
    sts.l pr, @-r15                      ! save return address
    mov #0x1, r9                         ! r9 = 0x1 (active flag constant)
    mov.l   .L_ptr_scroll_x_accum, r10   ! r10 = &scroll_x_accum
    mov.l   .L_ptr_scroll_y_accum, r11   ! r11 = &scroll_y_accum
    mov.l   .L_ptr_render_budget, r12    ! r12 = &render_budget
    mov.w   .L_hw_status_addr_lo, r13    ! r13 = 0xFE11 (hw status reg addr low)
    mov.w   DAT_06010c4e, r14            ! r14 = 0x0080 (bit 7 poll mask)
    mov.w   .L_rotation_step, r6         ! r6 = 0x0100 (rotation angle step)
    mov.l   .L_ptr_rotation_angle, r5    ! r5 = &rotation_angle
    mov.l   .L_ptr_display_active, r0    ! r0 = &display_active_flag
    mov.b @r0, r0                        ! r0 = *display_active_flag (byte)
    tst r0, r0                           ! T = (display_active == 0)?
    bf/s    .L_display_active_path       ! if display active, go to path A
    mov #0x0, r4                         ! r4 = 0 (zero constant, delay slot)
    bra     .L_display_inactive_path     ! else go to path B (inactive)
    nop                                  ! (delay slot)
.L_display_active_path:
    mov.w @r5, r3                        ! r3 = current rotation angle (16-bit)
    add r6, r3                           ! r3 += 0x100 (advance rotation)
    mov.w r3, @r5                        ! store updated rotation angle
    mov.l   .L_ptr_scroll_delta, r5      ! r5 = &scroll_delta
    mov.l @r10, r2                       ! r2 = scroll_x_accum
    mov.l @r5, r3                        ! r3 = scroll_delta
    add r3, r2                           ! r2 = scroll_x_accum + delta
    mov.l r2, @r10                       ! store updated scroll_x_accum
    mov.l @r11, r2                       ! r2 = scroll_y_accum
    mov.l @r5, r3                        ! r3 = scroll_delta
    add r3, r2                           ! r2 = scroll_y_accum + delta
    mov.l r2, @r11                       ! store updated scroll_y_accum
    mov.l   .L_ptr_scroll_dir_byte, r6   ! r6 = &scroll_direction_byte
    mov.l @r5, r2                        ! r2 = scroll_delta value
    cmp/pz r2                            ! T = (scroll_delta >= 0)?
    bf      .L_scroll_delta_negative     ! if negative, go to negative path
    mov.b @r6, r0                        ! r0 = scroll_direction byte
    bra     .L_dispatch_positive         ! dispatch positive overflow check
    extu.b r0, r0                        ! r0 = zero-extend to 32-bit (delay slot)
.L_check_scroll_x_pos:
    mov.l @r10, r2                       ! r2 = scroll_x_accum
    cmp/pz r2                            ! T = (scroll_x >= 0)?
    bf      .L_setup_render_params       ! if negative (no overflow), skip clamp
    mov.l r4, @r10                       ! scroll_x_accum = 0 (clamp)
    bra     .L_setup_render_params       ! continue to render setup
    mov.l r4, @r5                        ! scroll_delta = 0 (delay slot)
.L_check_scroll_y_pos:
    mov.l @r11, r2                       ! r2 = scroll_y_accum
    cmp/pz r2                            ! T = (scroll_y >= 0)?
    bf      .L_setup_render_params       ! if negative (no overflow), skip clamp
    mov.l r4, @r11                       ! scroll_y_accum = 0 (clamp)
    bra     .L_setup_render_params       ! continue to render setup
    mov.l r4, @r5                        ! scroll_delta = 0 (delay slot)
.L_dispatch_positive:
    cmp/eq #0x0, r0                      ! T = (direction == 0)?
    bt      .L_check_scroll_x_pos        ! if 0, check X axis overflow
    cmp/eq #0x1, r0                      ! T = (direction == 1)?
    bt      .L_check_scroll_y_pos        ! if 1, check Y axis overflow
    bra     .L_setup_render_params       ! else skip clamping
    nop                                  ! (delay slot)
.L_scroll_delta_negative:
    mov.b @r6, r0                        ! r0 = scroll_direction byte
    bra     .L_dispatch_negative         ! dispatch negative underflow check
    extu.b r0, r0                        ! r0 = zero-extend to 32-bit (delay slot)
.L_check_scroll_x_neg:
    mov.l @r10, r2                       ! r2 = scroll_x_accum
    cmp/pl r2                            ! T = (scroll_x > 0)?
    bt      .L_setup_render_params       ! if positive (no underflow), skip clamp
    mov.l r4, @r10                       ! scroll_x_accum = 0 (clamp)
    bra     .L_setup_render_params       ! continue to render setup
    mov.l r4, @r5                        ! scroll_delta = 0 (delay slot)
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
    mov.l @r11, r2                       ! r2 = scroll_y_accum
    cmp/pl r2                            ! T = (scroll_y > 0)?
    bt      .L_setup_render_params       ! if positive (no underflow), skip clamp
    mov.l r4, @r11                       ! scroll_y_accum = 0 (clamp)
    bra     .L_setup_render_params       ! continue to render setup
    mov.l r4, @r5                        ! scroll_delta = 0 (delay slot)
.L_dispatch_negative:
    cmp/eq #0x0, r0                      ! T = (direction == 0)?
    bt      .L_check_scroll_x_neg        ! if 0, check X axis underflow
    cmp/eq #0x1, r0                      ! T = (direction == 1)?
    bt      .L_check_scroll_y_neg        ! if 1, check Y axis underflow
.L_setup_render_params:
    .byte   0xB2, 0xA7    /* bsr 0x060111E2 — call lap_progress_indicator */
    nop                                  ! (delay slot)
    mov.l @r12, r2                       ! r2 = render_budget
    mov.l   .L_ptr_mat_vec_transform, r3 ! r3 = &mat_vec_transform
    add #0x30, r2                        ! r2 += 0x30 (allocate 48 bytes)
    jsr @r3                              ! call mat_vec_transform
    mov.l r2, @r12                       ! store updated budget (delay slot)
    mov.l   .L_ptr_active_flag_store, r3 ! r3 = &active_flag
    mov.l r9, @r3                        ! active_flag = 1
    mov.l @r11, r2                       ! r2 = scroll_y_accum
    mov.l   .L_ptr_scroll_y_store, r3    ! r3 = &scroll_y_param
    mov.l r2, @r3                        ! scroll_y_param = scroll_y_accum
    mov.l   .L_val_neg_z_pos, r2         ! r2 = 0xFFFF3334 (-0.8 fixed-point Z)
    mov.l   .L_ptr_cfg_z_pos, r3         ! r3 = &cfg_z_position
    mov.l r2, @r3                        ! cfg_z_position = -0.8
    mov.l   .L_val_x_pos, r2             ! r2 = 0x00063333 (6.2 fixed-point X)
    mov.l   .L_ptr_cfg_x_pos, r3         ! r3 = &cfg_x_position
    mov.l r2, @r3                        ! cfg_x_position = 6.2
    mov.l   .L_ptr_race_pos_track, r2    ! r2 = &race_position_track (callback)
    mov.l   .L_ptr_secondary_callback, r3 ! r3 = &secondary_callback_ptr
    mov.l r2, @r3                        ! secondary_callback = race_position_track
    mov.l   .L_mask_low16, r2            ! r2 = 0x0000FFFF
    mov.l   .L_ptr_vdp2_tvmd, r3         ! r3 = 0x21000000 (VDP2 TVMD register)
    mov.w r2, @r3                        ! VDP2_TVMD = 0xFFFF (enable all displays)
    mov.l   .L_val_x_pos, r7             ! r7 = 0x00063333 (X position arg)
    mov.l   .L_val_neg_z_pos, r6         ! r6 = 0xFFFF3334 (Z position arg)
    mov.l @r10, r5                       ! r5 = scroll_x_accum (Y position arg)
    .byte   0xB0, 0x65    /* bsr 0x06010D94 — call vdp_mode_select */
    mov #0x0, r4                         ! r4 = 0 (mode index, delay slot)
.L_poll_hw_status_a:
    mov.b @r13, r2                       ! r2 = hw_status byte
    extu.b r2, r2                        ! r2 = zero-extend to 32-bit
    and r14, r2                          ! r2 = status & 0x80 (isolate bit 7)
    cmp/eq r14, r2                       ! T = (bit 7 set)?
    bf      .L_poll_hw_status_a          ! busy-wait until bit 7 = 1
    mov.b @r13, r0                       ! r0 = hw_status byte (final read)
    mov.l   .L_ptr_render_finalize, r3   ! r3 = &render_finalize
    and #0xF, r0                         ! r0 = status & 0x0F (clear upper bits)
    jsr @r3                              ! call render_finalize
    mov.b r0, @r13                       ! store cleared status (delay slot)
    bra     .L_epilogue                  ! jump to epilogue
    nop                                  ! (delay slot)
.L_display_inactive_path:
    mov.l   .L_ptr_state_counter, r7     ! r7 = &state_counter
    mov.l r9, @r7                        ! state_counter = 1
    mov.w @r5, r2                        ! r2 = current rotation angle
    add r6, r2                           ! r2 += 0x100 (advance rotation)
    .byte   0xB3, 0x11    /* bsr 0x06011310 — call position_ranking_display */
    mov.w r2, @r5                        ! store updated rotation angle (delay slot)
    mov.l @r12, r2                       ! r2 = render_budget
    mov.l   .L_ptr_mat_vec_transform, r3 ! r3 = &mat_vec_transform
    add #0x30, r2                        ! r2 += 0x30 (allocate 48 bytes)
    jsr @r3                              ! call mat_vec_transform
    mov.l r2, @r12                       ! store updated budget (delay slot)
    mov.l   .L_ptr_active_flag_store, r3 ! r3 = &active_flag
    mov.l r9, @r3                        ! active_flag = 1
    mov.l   .L_val_scroll_y_alt, r2      ! r2 = 0x00038000 (3.5 fixed-point Y)
    mov.l   .L_ptr_scroll_y_store, r3    ! r3 = &scroll_y_param
    mov.l r2, @r3                        ! scroll_y_param = 3.5
    mov.l   .L_fp_neg_one, r2            ! r2 = 0xFFFF0000 (-1.0 fixed-point Z)
    mov.l   .L_ptr_cfg_z_pos, r3         ! r3 = &cfg_z_position
    mov.l r2, @r3                        ! cfg_z_position = -1.0
    mov.l   .L_val_x_pos_alt, r2         ! r2 = 0x0006B333 (6.7 fixed-point X)
    mov.l   .L_ptr_cfg_x_pos, r3         ! r3 = &cfg_x_position
    mov.l r2, @r3                        ! cfg_x_position = 6.7
    mov.l   .L_ptr_race_pos_track, r2    ! r2 = &race_position_track (callback)
    mov.l   .L_ptr_secondary_callback, r3 ! r3 = &secondary_callback_ptr
    mov.l r2, @r3                        ! secondary_callback = race_position_track
    mov.l   .L_mask_low16, r2            ! r2 = 0x0000FFFF
    mov.l   .L_ptr_vdp2_tvmd, r3         ! r3 = 0x21000000 (VDP2 TVMD register)
    mov.w r2, @r3                        ! VDP2_TVMD = 0xFFFF (enable all displays)
    mov.l   .L_val_x_pos_alt, r7         ! r7 = 0x0006B333 (X position arg)
    mov.l   .L_fp_neg_one, r6            ! r6 = 0xFFFF0000 (Z position arg)
    mov.l   .L_val_y_pos_alt, r5         ! r5 = 0xFFFC8000 (Y position arg)
    .byte   0xB0, 0x38    /* bsr 0x06010D94 — call vdp_mode_select */
    mov #0x0, r4                         ! r4 = 0 (mode index, delay slot)
.L_poll_hw_status_b:
    mov.b @r13, r2                       ! r2 = hw_status byte
    extu.b r2, r2                        ! r2 = zero-extend to 32-bit
    and r14, r2                          ! r2 = status & 0x80 (isolate bit 7)
    cmp/eq r14, r2                       ! T = (bit 7 set)?
    bf      .L_poll_hw_status_b          ! busy-wait until bit 7 = 1
    mov.b @r13, r0                       ! r0 = hw_status byte (final read)
    mov.l   .L_ptr_render_finalize, r3   ! r3 = &render_finalize
    and #0xF, r0                         ! r0 = status & 0x0F (clear upper bits)
    jsr @r3                              ! call render_finalize
    mov.b r0, @r13                       ! store cleared status (delay slot)
.L_epilogue:
    mov.l @r12, r2                       ! r2 = render_budget
    add #-0x30, r2                       ! r2 -= 0x30 (deallocate 48 bytes)
    mov.l r2, @r12                       ! store restored budget
    lds.l @r15+, pr                      ! restore return address
    mov.l @r15+, r9                      ! restore r9
    mov.l @r15+, r10                     ! restore r10
    mov.l @r15+, r11                     ! restore r11
    mov.l @r15+, r12                     ! restore r12
    mov.l @r15+, r13                     ! restore r13
    rts                                  ! return to caller
    mov.l @r15+, r14                     ! restore r14 (delay slot)
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
