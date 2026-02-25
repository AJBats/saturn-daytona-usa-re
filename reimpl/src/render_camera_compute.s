/* render_camera_compute -- Camera Viewport Computation & Smoothing
 * Translation unit: 0x0602EFF0 - 0x0602F214
 *
 * Three functions called from the per-car rendering orchestrator (FUN_0602EEB8):
 *
 * render_camera_compute (0x0602EFF0):
 *   Computes camera viewport extent for the current frame.
 *   Reads a signed camera movement delta from the camera object,
 *   takes absolute value, subtracts a dead-zone constant, clamps to
 *   [0, max_extent], restores sign, then scales by 0xFF and divides
 *   through HW divider (FUN_0602ECCC) three times to produce
 *   horizontal, vertical, and depth viewport parameters.
 *
 * sym_0602F0E8 — Frame Buffer Smoothing (0x0602F0E8):
 *   Exponential smoothing on the camera tracking value.
 *   Scales camera[0xB0] up by 8 bits, adds to running average at
 *   camera[0xD0], arithmetic-shifts right (decay). Then copies
 *   computed viewport to active viewport if rendering is unlocked.
 *   If locked, clears fields and performs track-position wrapping
 *   within [0, 0x71C).
 *
 * sym_0602F17C — Camera State Machine (0x0602F17C):
 *   Per-frame counter convergence toward zero, then course-aware
 *   camera boundary checking. Reads a course-segment index,
 *   looks up boundary values from tables at sym_060477AC / sym_0604779C,
 *   and triggers viewport adjustment if the camera is outside bounds.
 *   Uses dmuls.l fixed-point math for position scaling.
 *
 * Camera object pointer: sym_0607E944 (dereferenced to get base address).
 * HW divider helper: FUN_0602ECCC (disables IRQs, uses SH-2 DVSR/DVDNT).
 */

    .section .text.FUN_0602EFF0


    .global render_camera_compute
    .type render_camera_compute, @function
render_camera_compute:
    mov.l r14, @-r15                       ! save r14
    sts.l pr, @-r15                        ! save return address
    mov.l   .L_camera_state_ptr, r0           ! r0 = &camera_state_ptr
    mov.l @r0, r0                          ! r0 = camera_obj base
    mov #0x0, r1                           ! clear r1
    mov #0x0, r2                           ! clear r2
    mov #0x0, r3                           ! clear r3
    mov #0x0, r4                           ! clear r4
    mov #0x0, r7                           ! clear r7
    mov r0, r14                            ! r14 = camera_obj
    mov.w   DAT_0602f01e, r1              ! r1 = 0xAC (delta field offset)
    mov.l @(r0, r1), r1                    ! r1 = camera[0xAC] (movement delta)
    mov r1, r6                             ! r6 = delta (preserve original sign)
    mov.w   .L_dead_zone_threshold, r2         ! r2 = 0x05 (dead-zone threshold)
    mov.w   .L_max_extent_range, r3         ! r3 = 0x50 (max extent range)
    cmp/pz r1                              ! delta >= 0?
    bt      .L_skip_abs                    ! yes -> skip negation
    neg r1, r1                             ! r1 = abs(delta)
.L_skip_abs:
    sub r2, r1                             ! r1 = abs(delta) - dead_zone
    cmp/pz r1                              ! result >= 0?
    bt      .L_clamp_upper                    ! yes -> clamp upper
    bra     .L_scale_and_divide                    ! no -> clamp to zero
    mov #0x0, r1                           ! (delay) r1 = 0

    .global DAT_0602f01e
DAT_0602f01e:
    .2byte  0x00AC
.L_dead_zone_threshold:
    .2byte  0x0005
.L_max_extent_range:
    .2byte  0x0050
.L_camera_state_ptr:
    .4byte  sym_0607E944
.L_clamp_upper:
    sub r2, r3                             ! r3 = max_extent - dead_zone
    cmp/gt r1, r3                          ! max > clamped_delta?
    bt      .L_check_sign                    ! yes -> no clamp needed
    mov r3, r1                             ! clamp r1 to max
.L_check_sign:
    cmp/pz r6                              ! original delta >= 0?
    bt      .L_scale_and_divide                    ! yes -> keep positive
    neg r1, r1                             ! restore negative sign
.L_scale_and_divide:
    mov r0, r14                            ! r14 = camera_obj
    mov.w   .L_scale_factor_ff, r2         ! r2 = 0xFF (scale factor)
    muls.w r1, r2                          ! macl = delta * 0xFF
    mov.w   .L_horiz_divisor, r0         ! r0 = 0x96 (divisor for horiz)
    sts macl, r1                           ! r1 = scaled delta
    .byte   0xBE, 0x44    /* bsr 0x0602ECCC (external) */  ! HW divide: r0 = r1/r0
    nop                                    ! (delay)
    mov r0, r2                             ! r2 = horiz viewport result
    mov r14, r0                            ! r0 = camera_obj
    mov.w   DAT_0602f064, r6             ! r6 = 0xB0 (horiz dest offset)
    mov.w   DAT_0602f066, r1             ! r1 = 0xB4 (horiz prev offset)
    mov.l @(r0, r6), r4                    ! r4 = old camera[0xB0]
    mov.l r2, @(r0, r6)                   ! camera[0xB0] = new horiz value
    mov.l r4, @(r0, r1)                   ! camera[0xB4] = old value (smoothing)
    mov.w   .L_viewport_width_offset, r3         ! r3 = 0x74 (viewport width offset)
    mov.l @(r0, r3), r1                    ! r1 = camera[0x74] (viewport width)
    mov.l   .L_max_horiz_extent, r2          ! r2 = 0xB8 (max viewport extent)
    cmp/ge r1, r2                          ! max >= width?
    bt      .L_check_horiz_lower                    ! yes -> check lower bound
    bra     .L_vert_viewport_calc                    ! no -> clamp to max
    mov r2, r1                             ! (delay) r1 = max
.L_scale_factor_ff:
    .2byte  0x00FF
.L_horiz_divisor:
    .2byte  0x0096

    .global DAT_0602f064
DAT_0602f064:
    .2byte  0x00B0

    .global DAT_0602f066
DAT_0602f066:
    .2byte  0x00B4
.L_viewport_width_offset:
    .2byte  0x0074
    .2byte  0x0000
.L_max_horiz_extent:
    .4byte  0x000000B8
.L_check_horiz_lower:
    mov.l   .L_min_viewport_extent, r2          ! r2 = 0x38 (min viewport extent)
    cmp/ge r1, r2                          ! min >= width?
    bf      .L_vert_viewport_calc                    ! no -> width in range
    mov r2, r1                             ! clamp to min
.L_vert_viewport_calc:
    mov.l   .L_min_viewport_extent, r2          ! r2 = 0x38 (min extent base)
    sub r2, r1                             ! r1 = width - 0x38
    mov.w   .L_vert_scale_ff, r3         ! r3 = 0xFF (scale factor)
    mulu.w r3, r1                          ! macl = (width-0x38) * 0xFF
    mov.l r0, @-r15                        ! save camera_obj on stack
    mov.l   .L_vert_store_offset, r3          ! r3 = 0x78 (vert store offset)
    sts macl, r1                           ! r1 = scaled value
    mov.l   .L_vert_divisor, r0          ! r0 = 0x80 (divisor for vert)
    .byte   0xBE, 0x20    /* bsr 0x0602ECCC (external) */  ! HW divide: vert dimension
    nop                                    ! (delay)
    mov.l @r15+, r0                        ! restore camera_obj
    mov.l @(r0, r3), r2                    ! r2 = old camera[0x78]
    mov.l r1, @(r0, r3)                   ! camera[0x78] = new vert value
    mov.w   .L_depth_field_offset, r3         ! r3 = 0x90 (depth field offset)
    mov.l @(r0, r3), r1                    ! r1 = camera[0x90] (depth param)
    mov.l   .L_max_depth_extent, r2          ! r2 = 0x98 (max depth extent)
    cmp/ge r1, r2                          ! max >= depth?
    bt      .L_check_depth_lower                    ! yes -> check lower bound
    bra     .L_depth_viewport_calc                    ! no -> clamp to max
    mov r2, r1                             ! (delay) r1 = max
.L_vert_scale_ff:
    .2byte  0x00FF
.L_depth_field_offset:
    .2byte  0x0090
.L_min_viewport_extent:
    .4byte  0x00000038
.L_vert_store_offset:
    .4byte  0x00000078
.L_vert_divisor:
    .4byte  0x00000080
.L_max_depth_extent:
    .4byte  0x00000098
.L_check_depth_lower:
    mov.l   .L_min_depth_extent, r2          ! r2 = 0x38 (min depth extent)
    cmp/ge r1, r2                          ! min >= depth?
    bf      .L_depth_viewport_calc                    ! no -> depth in range
    mov r2, r1                             ! clamp to min
.L_depth_viewport_calc:
    mov.l   .L_min_depth_extent, r2          ! r2 = 0x38 (min extent base)
    sub r2, r1                             ! r1 = depth - 0x38
    mov.w   .L_depth_scale_ff, r3         ! r3 = 0xFF (scale factor)
    mulu.w r3, r1                          ! macl = (depth-0x38) * 0xFF
    mov.l r0, @-r15                        ! save camera_obj on stack
    sts macl, r1                           ! r1 = scaled value
    mov.w   .L_depth_divisor, r0         ! r0 = 0x60 (divisor for depth)
    .byte   0xBD, 0xFF    /* bsr 0x0602ECCC (external) */  ! HW divide: depth dimension
    nop                                    ! (delay)
    mov.l @r15+, r0                        ! restore camera_obj
    mov.w   .L_depth_store_offset, r3         ! r3 = 0x94 (depth store offset)
    mov.l r1, @(r0, r3)                   ! camera[0x94] = depth result
    lds.l @r15+, pr                        ! restore return address
    mov.l @r15+, r14                       ! restore r14
    rts                                    ! return
    nop                                    ! (delay)
.L_depth_scale_ff:
    .2byte  0x00FF
.L_depth_divisor:
    .2byte  0x0060
.L_depth_store_offset:
    .2byte  0x0094
    .2byte  0x0000
.L_min_depth_extent:
    .4byte  0x00000038

    .global sym_0602F0E8
sym_0602F0E8:
    mov.l   .L_smooth_cam_ptr, r2          ! r2 = &camera_state_ptr
    mov.l @r2, r0                          ! r0 = camera_obj base
    mov.w   DAT_0602f11e, r1             ! r1 = 0xB0 (raw tracking offset)
    mov.l @(r0, r1), r2                    ! r2 = camera[0xB0] (raw tracking value)
    shll8 r2                               ! r2 <<= 8 (scale up for smoothing)
    mov.w   DAT_0602f120, r3             ! r3 = 0xD0 (running average offset)
    mov.l @(r0, r3), r4                    ! r4 = camera[0xD0] (previous average)
    add r4, r2                             ! r2 = scaled_raw + prev_average
    shar r2                                ! r2 >>= 1 (exponential decay)
    mov.l r2, @(r0, r3)                   ! camera[0xD0] = new smoothed value
    mov.w   DAT_0602f122, r1             ! r1 = 0xB8 (render lock flag offset)
    mov.l @(r0, r1), r3                    ! r3 = camera[0xB8]
    tst r3, r3                             ! lock flag == 0?
    bf      .L_render_locked                    ! nonzero -> rendering locked, skip
    mov.w   DAT_0602f124, r2             ! r2 = 0x1BC (secondary lock offset)
    mov.l @(r0, r2), r4                    ! r4 = camera[0x1BC]
    tst r4, r4                             ! secondary lock == 0?
    bf      .L_render_locked                    ! nonzero -> skip viewport copy
    mov.w   DAT_0602f126, r1             ! r1 = 0x94 (computed viewport offset)
    mov.l @(r0, r1), r2                    ! r2 = camera[0x94] (computed value)
    mov.l   .L_active_viewport_offset, r3          ! r3 = 0x84 (active viewport offset)
    mov.l r2, @(r0, r3)                   ! camera[0x84] = computed viewport
    mov.w   DAT_0602f128, r1             ! r1 = 0x78 (secondary source offset)
    mov.l @(r0, r1), r2                    ! r2 = camera[0x78]
    mov.w   DAT_0602f12a, r3             ! r3 = 0x68 (secondary dest offset)
    rts                                    ! return
    mov.l r2, @(r0, r3)                   ! (delay) camera[0x68] = camera[0x78]

    .global DAT_0602f11e
DAT_0602f11e:
    .2byte  0x00B0

    .global DAT_0602f120
DAT_0602f120:
    .2byte  0x00D0

    .global DAT_0602f122
DAT_0602f122:
    .2byte  0x00B8

    .global DAT_0602f124
DAT_0602f124:
    .2byte  0x01BC

    .global DAT_0602f126
DAT_0602f126:
    .2byte  0x0094

    .global DAT_0602f128
DAT_0602f128:
    .2byte  0x0078

    .global DAT_0602f12a
DAT_0602f12a:
    .2byte  0x0068
.L_smooth_cam_ptr:
    .4byte  sym_0607E944
.L_active_viewport_offset:
    .4byte  0x00000084
.L_render_locked:
    mov #0x0, r5                           ! r5 = 0
    mov.w   DAT_0602f15a, r1             ! r1 = 0x166 (word field offset)
    mov.w r5, @(r0, r1)                   ! camera[0x166] = 0 (clear word field)
    mov.w   DAT_0602f15c, r5             ! r5 = 0x38 (reset constant)
    mov.w   DAT_0602f15e, r1             ! r1 = 0x90 (first clear offset)
    mov.l r5, @(r0, r1)                   ! camera[0x90] = 0x38
    mov.w   DAT_0602f160, r1             ! r1 = 0x74 (second clear offset)
    mov.l r5, @(r0, r1)                   ! camera[0x74] = 0x38
    mov #0x0, r5                           ! r5 = 0
    mov.w   .L_smooth_pos_offset, r1         ! r1 = 0xD0 (smoothed position offset)
    mov.l @(r0, r1), r4                    ! r4 = camera[0xD0] (track position)
    mov.l   .L_track_length, r2          ! r2 = 0x71C (track length)
    cmp/pz r4                              ! position >= 0?
    bt      .L_check_upper_wrap                    ! yes -> check upper wrap
    add r2, r4                             ! position += track_length (wrap forward)
    cmp/pz r4                              ! now positive?
    bt      .L_reset_pos_zero                    ! yes -> clamp to zero
    bra     .L_store_wrapped_pos                    ! still negative -> store as-is
    nop                                    ! (delay)

    .global DAT_0602f15a
DAT_0602f15a:
    .2byte  0x0166

    .global DAT_0602f15c
DAT_0602f15c:
    .2byte  0x0038

    .global DAT_0602f15e
DAT_0602f15e:
    .2byte  0x0090

    .global DAT_0602f160
DAT_0602f160:
    .2byte  0x0074
.L_smooth_pos_offset:
    .2byte  0x00D0
.L_track_length:
    .4byte  0x0000071C
.L_check_upper_wrap:
    sub r2, r4                             ! position -= track_length (wrap back)
    cmp/pz r4                              ! still positive?
    bt      .L_reset_pos_zero                    ! yes -> wrapped past end, clamp to 0
.L_store_wrapped_pos:
    mov.l r4, @(r0, r1)                   ! camera[0xD0] = wrapped position
    rts                                    ! return
    nop                                    ! (delay)
.L_reset_pos_zero:
    mov #0x0, r5                           ! r5 = 0
    mov.l r5, @(r0, r1)                   ! camera[0xD0] = 0 (reset position)
    rts                                    ! return
    nop                                    ! (delay)

    .global sym_0602F17C
sym_0602F17C:
    mov r0, r14                            ! r14 = camera_obj
    mov #0x0, r5                           ! r5 = 0
    mov.w   .L_frame_counter_offset, r8         ! r8 = 0xD8 (frame counter offset)
    mov.l @(r0, r8), r2                    ! r2 = camera[0xD8] (frame counter)
    tst r2, r2                             ! counter == 0?
    bt      .L_counter_store                    ! yes -> already at zero
    cmp/pz r2                              ! counter > 0?
    bf      .L_counter_inc                    ! negative -> skip decrement
    add #-0x2, r2                          ! positive: decrement by 2
.L_counter_inc:
    add #0x1, r2                           ! converge toward zero (+1)
.L_counter_store:
    mov.l r2, @(r0, r8)                   ! camera[0xD8] = adjusted counter
    mov.w   DAT_0602f1bc, r9             ! r9 = 0xDC (course segment index offset)
    mov.w @(r0, r9), r2                    ! r2 = camera[0xDC] (course segment)
    mov.w   DAT_0602f1be, r3             ! r3 = 0xE0 (camera position offset)
    shll2 r2                               ! r2 = segment * 4 (table index)
    mov.l @(r0, r3), r4                    ! r4 = camera[0xE0] (camera position)
    mov.l @(8, r0), r7                     ! r7 = camera[0x08] (mode flag)
    tst r7, r7                             ! mode == 0?
    bt      .L_use_default_table                    ! yes -> use default table
    mov.l   .L_boundary_table_a, r6          ! r6 = &course_boundary_table_A
    add r2, r6                             ! r6 -> table_A[segment]
    mov.l @r6, r6                          ! r6 = boundary_A value
    cmp/gt r6, r4                          ! cam_pos > boundary_A?
    bt      .L_adjust_forward                    ! yes -> adjust viewport forward
.L_use_default_table:
    mov.l   .L_boundary_table_b, r6          ! r6 = &course_boundary_table_B
    add r2, r6                             ! r6 -> table_B[segment]
    mov.l @r6, r6                          ! r6 = boundary_B value
    cmp/ge r4, r6                          ! boundary_B >= cam_pos?
    bt      .L_adjust_backward                    ! yes -> adjust viewport backward
    .byte   0xA0, 0x35    /* bra 0x0602F224 (external) */  ! within bounds -> exit
    nop                                    ! (delay)
.L_frame_counter_offset:
    .2byte  0x00D8

    .global DAT_0602f1bc
DAT_0602f1bc:
    .2byte  0x00DC

    .global DAT_0602f1be
DAT_0602f1be:
    .2byte  0x00E0
.L_boundary_table_a:
    .4byte  sym_060477AC
.L_boundary_table_b:
    .4byte  sym_0604779C
.L_adjust_forward:
    mov #0x5, r1                           ! r1 = 5 (forward adjustment step)
    mov.l r1, @(r0, r8)                   ! camera[0xD8] = 5 (set counter)
    mov.w @(r0, r9), r1                    ! r1 = course segment index
    mov r1, r3                             ! r3 = old segment (for table lookup)
    add #0x1, r1                           ! increment segment
    mov.w r1, @(r0, r9)                   ! camera[0xDC] = new segment index
    mov.w   DAT_0602f1f2, r8             ! r8 = 0xE0 (camera position offset)
    mov.l @(r0, r8), r5                    ! r5 = camera[0xE0] (position)
    mov.l   .L_speed_table_fwd, r2          ! r2 = &course_speed_table
    shll16 r5                              ! r5 <<= 16 (fixed-point scale up)
    shll2 r3                               ! r3 = old_segment * 4
    add r2, r3                             ! r3 -> speed_table[old_segment]
    mov.l @r3, r4                          ! r4 = speed factor
    dmuls.l r4, r5                         ! MACH:MACL = factor * position
    sts mach, r4                           ! r4 = high 32 bits
    sts macl, r1                           ! r1 = low 32 bits
    xtrct r4, r1                           ! r1 = middle 32 bits (fixed-point result)
    mov #0x0, r2                           ! r2 = 0
    shlr16 r1                              ! r1 >>= 16 (extract integer part)
    .byte   0xA0, 0x19    /* bra 0x0602F224 (external) */  ! exit via shared path
    mov.l r1, @(r0, r8)                   ! (delay) camera[0xE0] = scaled position

    .global DAT_0602f1f2
DAT_0602f1f2:
    .2byte  0x00E0
.L_speed_table_fwd:
    .4byte  sym_060477CC
.L_adjust_backward:
    mov #-0x5, r1                          ! r1 = -5 (backward adjustment step)
    mov.l r1, @(r0, r8)                   ! camera[0xD8] = -5 (set counter)
    mov.w @(r0, r9), r1                    ! r1 = course segment index
    add #-0x1, r1                          ! decrement segment
    mov r1, r3                             ! r3 = new segment (for table lookup)
    mov.w r1, @(r0, r9)                   ! camera[0xDC] = new segment index
    .byte   0x98, 0x22    /* mov.w .L_wpool_0602F24C, r8 */  ! r8 = position offset (external pool)
    mov.l @(r0, r8), r4                    ! r4 = camera position
    shll16 r4                              ! r4 <<= 16 (fixed-point scale up)
    .byte   0xD2, 0x12    /* mov.l .L_pool_0602F254, r2 */   ! r2 = &course_speed_table (external pool)
    shll2 r3                               ! r3 = new_segment * 4
    add r2, r3                             ! r3 -> speed_table[new_segment]
    mov.l @r3, r5                          ! r5 = speed factor
    .byte   0xDC, 0x11    /* mov.l .L_pool_0602F258, r12 */  ! r12 = continuation addr (external pool)
