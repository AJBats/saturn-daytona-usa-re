/* vdp1_cmd_list_mgr -- Render heading interpolation & display list finalization
 * Translation unit: 0x0602CDF6 - 0x0602D08A
 *
 * Called as step 17 of the per-car render pipeline (render_orchestrator).
 * After VDP1 display commands have been submitted, this function computes
 * smooth heading interpolation for the renderer:
 *
 *   1. Compute angular difference between car heading fields (+0x58, +0x5C)
 *   2. Use sin/cos/atan2/fpdiv to derive a steering correction angle
 *   3. Scale the correction by a magic constant (rad-to-angle conversion)
 *   4. Update car heading copies (+0x30, +0x28) used by the camera/renderer
 *   5. Blend lateral velocity components (+0x60, +0x64) toward new heading
 *   6. Smooth the heading at +0x30 with exponential damping toward +0x28
 *   7. Compare heading against reference (+0x25C) -- if divergence exceeds
 *      threshold 0x0444, increment an out-of-range counter at +0x258
 *   8. Clamp final heading correction within +/-0x3C
 *
 * Inputs:
 *   r0  = car struct base pointer (preserved across sub-calls)
 *   r14 = car struct base pointer (alias)
 *
 * Car struct fields accessed:
 *   +0x0C  (CAR_ACCEL)        -- acceleration / distance accumulator
 *   +0x28  (CAR_HEADING2)     -- target heading copy (smoothed output)
 *   +0x2C                     -- heading target (written by correction logic)
 *   +0x30  (CAR_HEADING3)     -- heading copy (angular tracking)
 *   +0x40  (CAR_FIELD_40)     -- general field (loaded as base angle)
 *   +0x58                     -- angular bound A
 *   +0x5C                     -- angular bound B (limit)
 *   +0x60  (CAR_VEL_LATERAL_A)-- lateral velocity component A
 *   +0x64  (CAR_VEL_LATERAL_B)-- lateral velocity component B
 *   +0xD0  (CAR_YAW_DELTA)   -- yaw angle delta per frame
 *   +0x154                    -- angular rate storage
 *   +0x252                    -- heading mode flag
 *   +0x258                    -- heading out-of-range counter
 *   +0x25C (CAR_HEADING_REF)  -- heading reference angle
 *
 * External calls: sin_lookup, cos_lookup, atan2, fpdiv_setup
 * Global data:    sym_06063EEC+4 (camera heading smoothed value)
 */

    .section .text.FUN_0602CDF6


    .global vdp1_cmd_list_mgr
    .type vdp1_cmd_list_mgr, @function
vdp1_cmd_list_mgr:
    sts.l pr, @-r15                     ! save return address
    mov.w   DAT_0602ce44, r7            ! r7 = 0x4000 (quarter-turn, 16.16 fxp 0.25)
    mov #0x0, r6                        ! r6 = 0 (direction flag: 0=normal)
    mov.w   DAT_0602ce46, r1            ! r1 = 0x0040 (offset: CAR_FIELD_40)
    mov.w   DAT_0602ce48, r2            ! r2 = 0x0058 (offset: angular bound A)
    mov.l @(r0, r1), r3                 ! r3 = car[0x40] (base angle)
    mov.l @(r0, r2), r4                 ! r4 = car[0x58] (angular bound A)
    mov.w   DAT_0602ce4a, r1            ! r1 = 0x005C (offset: angular bound B)
    mov.l @(r0, r1), r5                 ! r5 = car[0x5C] (angular limit)
    add r3, r4                          ! r4 = base + bound_A (combined angle)
    cmp/gt r5, r4                       ! combined > limit?
    bt      .L_within_limit             ! if so, skip direction flip
    neg r7, r7                          ! r7 = -0x4000 (negate quarter-turn)
    mov #0x1, r6                        ! r6 = 1 (direction flag: reversed)
.L_within_limit:
    mov.l @(r0, r2), r4                 ! r4 = car[0x58] (reload bound A)
    add r7, r3                          ! r3 = base_angle +/- 0x4000
    add r3, r4                          ! r4 = adjusted angle + bound_A
    mov r4, r8                          ! r8 = adjusted angle (save for later)
    add r7, r5                          ! r5 = limit +/- 0x4000
    mov r5, r9                          ! r9 = adjusted limit (save for later)
    sub r5, r4                          ! r4 = angle - limit (difference for sin)
    mov.l r7, @-r15                     ! push quarter-turn offset
    mov.l r9, @-r15                     ! push adjusted limit
    .byte   0xDD, 0x09    /* mov.l .L_sin_lookup_a, r13 */
    mov.l r8, @-r15                     ! push adjusted angle
    jsr @r13                            ! call sin_lookup(r4 = angle diff)
    mov.l r6, @-r15                     ! push direction flag (delay slot)
    mov r0, r5                          ! r5 = sin(angle_diff) result
    jsr @r13                            ! call sin_lookup(r4 = adjusted_limit)
    mov r9, r4                          ! r4 = adjusted limit (delay slot)
    .byte   0xD7, 0x07    /* mov.l .L_angle_scale_factor, r7 */
    dmuls.l r7, r0                      ! 64-bit: scale * sin(limit)
    tst r5, r5                          ! test sin(angle_diff) == 0?
    sts mach, r0                        ! r0 = high 32 bits of product
    sts macl, r4                        ! r4 = low 32 bits of product
    xtrct r0, r4                        ! r4 = middle 32 bits (16.16 scaled result)
    bf      .L_sin_nonzero              ! if sin != 0, proceed with trig calc
    bra     .L_zero_delta               ! sin == 0: no heading correction needed
    mov.l @r15+, r5                     ! pop direction flag (delay slot)

    .global DAT_0602ce44
DAT_0602ce44:
    .2byte  0x4000                      ! quarter-turn constant (16384 = 90 deg in angle16)

    .global DAT_0602ce46
DAT_0602ce46:
    .2byte  0x0040                      ! car struct offset: CAR_FIELD_40

    .global DAT_0602ce48
DAT_0602ce48:
    .2byte  0x0058                      ! car struct offset: angular bound A

    .global DAT_0602ce4a
DAT_0602ce4a:
    .2byte  0x005C                      ! car struct offset: angular bound B (limit)
.L_sin_lookup_a:
    .4byte  sin_lookup                  ! -> sin lookup function
.L_angle_scale_factor:
    .4byte  0x0002C000                  ! angle scaling constant (fixed-point)
.L_sin_nonzero:
    .byte   0xD0, 0x12    /* mov.l .L_fpdiv_setup_a, r0 */
    jsr @r0                             ! call fpdiv_setup(r4=scaled_sin, r5=sin_diff)
    nop                                 ! delay slot
    cmp/pz r0                           ! result >= 0?
    bt      .L_abs_div_result           ! if positive, skip negation
    neg r0, r0                          ! r0 = abs(division result)
.L_abs_div_result:
    mov r0, r10                         ! r10 = |quotient| (magnitude)
    jsr @r13                            ! call sin_lookup(r4=adjusted_angle)
    mov r8, r4                          ! r4 = adjusted angle (delay slot)
    dmuls.l r10, r0                     ! 64-bit: magnitude * sin(adjusted_angle)
    mov r8, r4                          ! r4 = adjusted angle (for cos call)
    sts mach, r0                        ! r0 = high 32 of product
    sts macl, r3                        ! r3 = low 32 of product
    xtrct r0, r3                        ! r3 = 16.16 result (X component)
    mov r3, r11                         ! r11 = X component (save)
    .byte   0xD0, 0x0C    /* mov.l .L_cos_lookup, r0 */
    jsr @r0                             ! call cos_lookup(r4=adjusted_angle)
    nop                                 ! delay slot
    dmuls.l r10, r0                     ! 64-bit: magnitude * cos(adjusted_angle)
    shlr r7                             ! r7 = angle_scale >> 1 (rounding bias)
    sts mach, r0                        ! r0 = high 32 of product
    sts macl, r5                        ! r5 = low 32 of product
    xtrct r0, r5                        ! r5 = 16.16 result (Y component)
    add r7, r5                          ! r5 += rounding bias
    .byte   0xD0, 0x08    /* mov.l .L_atan2_func, r0 */
    jsr @r0                             ! call atan2(r4=X, r5=Y) -> heading angle
    mov r3, r4                          ! r4 = X component (delay slot)
    mov r0, r4                          ! r4 = atan2 result (new heading angle)
    mov r0, r7                          ! r7 = atan2 result (save copy)
    jsr @r13                            ! call sin_lookup(r4=heading_angle)
    nop                                 ! delay slot
    mov r0, r5                          ! r5 = sin(heading_angle)
    mov r11, r4                         ! r4 = X component
    tst r5, r5                          ! test sin(heading) == 0?
    bf      .L_heading_valid            ! if nonzero, heading is valid
    bra     .L_zero_delta               ! sin == 0: degenerate, skip correction
    mov.l @r15+, r5                     ! pop direction flag (delay slot)
    .2byte  0x0000                      ! alignment padding
.L_fpdiv_setup_a:
    .4byte  fpdiv_setup                 ! -> fixed-point division setup
.L_cos_lookup:
    .4byte  cos_lookup                  ! -> cos lookup function
.L_atan2_func:
    .4byte  atan2                       ! -> atan2 function
.L_heading_valid:
    .byte   0xD0, 0x08    /* mov.l .L_fpdiv_setup_b, r0 */
    jsr @r0                             ! call fpdiv_setup(r4=X_comp, r5=sin_heading)
    nop                                 ! delay slot
    cmp/pz r0                           ! quotient >= 0?
    bt      .L_magnitude_positive       ! if positive, skip negation
    neg r0, r0                          ! r0 = abs(quotient)
.L_magnitude_positive:
    mov.l @r15+, r9                     ! pop direction flag into r9
    tst r9, r9                          ! direction == 0 (normal)?
    bt      .L_direction_normal         ! if normal, keep positive
    neg r0, r0                          ! reversed direction: negate magnitude
.L_direction_normal:
    mov r0, r5                          ! r5 = signed magnitude
    mov r14, r0                         ! r0 = car struct base
    mov.l @(12, r0), r4                 ! r4 = car[0x0C] (CAR_ACCEL)
    tst r5, r5                          ! magnitude == 0?
    bf      .L_compute_correction       ! if nonzero, compute correction angle
    bra     .L_zero_delta               ! magnitude == 0: no correction
    nop                                 ! delay slot
    .2byte  0x0000                      ! alignment padding
.L_fpdiv_setup_b:
    .4byte  fpdiv_setup                 ! -> fixed-point division setup
.L_compute_correction:
    .byte   0xD0, 0x09    /* mov.l .L_fpdiv_setup_c, r0 */
    jsr @r0                             ! call fpdiv_setup(r4=accel, r5=magnitude)
    nop                                 ! delay slot
    .byte   0xD5, 0x09    /* mov.l .L_rad_to_angle, r5 */
    mov #0x0, r2                        ! r2 = 0 (sign flag: positive)
    cmp/pz r0                           ! quotient >= 0?
    bt      .L_ratio_positive           ! if positive, skip sign tracking
    mov #0x1, r2                        ! r2 = 1 (sign flag: negative)
    neg r0, r0                          ! r0 = abs(quotient)
.L_ratio_positive:
    dmuls.l r0, r5                      ! 64-bit: |quotient| * rad_to_angle
    nop                                 ! pipeline stall
    sts mach, r0                        ! r0 = high 32 of product
    sts macl, r5                        ! r5 = low 32 of product
    xtrct r0, r5                        ! r5 = 16.16 result
    tst r2, r2                          ! was quotient positive?
    bt/s    .L_apply_correction         ! if positive, use as-is
    shlr16 r5                           ! r5 >>= 16 (extract integer angle, delay slot)
    neg r5, r5                          ! negate to restore original sign
.L_apply_correction:
    bra     .L_update_heading           ! jump to heading update
    nop                                 ! delay slot
.L_fpdiv_setup_c:
    .4byte  fpdiv_setup                 ! -> fixed-point division setup
.L_rad_to_angle:
    .4byte  0x28BE60DB                  ! radian-to-angle16 conversion constant
.L_zero_delta:
    mov #0x0, r5                        ! r5 = 0 (no heading correction)
    mov r8, r7                          ! r7 = adjusted angle (passthrough)
.L_update_heading:
    mov r14, r0                         ! r0 = car struct base
    mov.l @(48, r0), r2                 ! r2 = car[0x30] (CAR_HEADING3)
    add r5, r2                          ! r2 += heading correction delta
    exts.w r2, r2                       ! sign-extend to 32-bit (angle wrapping)
    .byte   0xD3, 0x09    /* mov.l .L_angular_rate_offset, r3 */
    mov.l r2, @(48, r0)                 ! car[0x30] = updated heading copy
    mov.l r5, @(r0, r3)                 ! car[0x154] = angular rate (correction delta)
    mov.l @r15+, r8                     ! pop saved adjusted angle
    mov.l @r15+, r9                     ! pop saved adjusted limit
    cmp/eq r8, r9                       ! adjusted_angle == adjusted_limit?
    bf/s    .L_angles_differ            ! if different, keep computed heading
    mov.l @r15+, r6                     ! pop quarter-turn offset (delay slot)
    mov r8, r7                          ! angles equal: use adjusted_angle as heading
.L_angles_differ:
    sub r6, r7                          ! r7 -= quarter_turn (undo earlier offset)
    mov.w   .L_heading_mode_offset, r1  ! r1 = 0x0252 (heading mode flag offset)
    mov.w @(r0, r1), r2                 ! r2 = car[0x252] (heading mode)
    mov #0x1, r4                        ! r4 = 1
    cmp/eq r4, r2                       ! heading mode == 1?
    bt      .L_mode_1_heading           ! if mode 1, use alternate heading source
    .byte   0xD3, 0x03    /* mov.l .L_heading_target_offset, r3 */
    bra     .L_store_heading_target     ! store computed heading
    mov.l r7, @(r0, r3)                 ! car[0x2C] = heading target (delay slot)
.L_heading_mode_offset:
    .2byte  0x0252                      ! car struct offset: heading mode flag
    .2byte  0x0000                      ! alignment padding
.L_angular_rate_offset:
    .4byte  0x00000154                  ! car struct offset: angular rate storage
.L_heading_target_offset:
    .4byte  0x0000002C                  ! car struct offset: heading target (+0x2C)
.L_mode_1_heading:
    .byte   0xD3, 0x28    /* mov.l .L_heading_alt_offset, r3 */
    mov.l @(r0, r3), r7                 ! r7 = car[0x2C] (use stored heading target)
.L_store_heading_target:
    mov.l @(48, r0), r2                 ! r2 = car[0x30] (current heading3)
    add r7, r2                          ! r2 += heading target
    exts.w r2, r2                       ! sign-extend (angle wrapping)
    mov.l @(40, r0), r4                 ! r4 = car[0x28] (CAR_HEADING2, old value)
    mov.l r2, @(40, r0)                 ! car[0x28] = new blended heading
    sub r4, r2                          ! r2 = heading_delta (new - old)
    mov r2, r4                          ! r4 = heading_delta (for multiply)
    mov.l @(12, r0), r2                 ! r2 = car[0x0C] (CAR_ACCEL)
    .byte   0xD0, 0x24    /* mov.l .L_sin_lookup_b, r0 */
    jsr @r0                             ! call sin_lookup(r4=heading_delta)
    nop                                 ! delay slot
    dmuls.l r2, r0                      ! 64-bit: accel * sin(heading_delta)
    .byte   0xD3, 0x23    /* mov.l .L_lateral_scale_a, r3 */
    sts mach, r0                        ! r0 = high 32 of product
    sts macl, r5                        ! r5 = low 32 of product
    xtrct r0, r5                        ! r5 = 16.16 lateral velocity component
    dmuls.l r3, r5                      ! 64-bit: lateral * scale_A (0x0028D0FA)
    .byte   0xD3, 0x22    /* mov.l .L_lateral_scale_b, r3 */
    sts mach, r2                        ! r2 = high 32 of product
    sts macl, r5                        ! r5 = low 32 of product
    xtrct r2, r5                        ! r5 = rescaled lateral velocity
    dmuls.l r3, r5                      ! 64-bit: rescaled * scale_B (0x03200000)
    mov r14, r0                         ! r0 = car struct base
    sts mach, r3                        ! r3 = high 32 of product
    sts macl, r5                        ! r5 = low 32 of product
    xtrct r3, r5                        ! r5 = final lateral velocity increment
    mov r5, r6                          ! r6 = copy of lateral increment
    mov.w   DAT_0602cfda, r1            ! r1 = 0x0060 (offset: CAR_VEL_LATERAL_A)
    mov.w   DAT_0602cfdc, r2            ! r2 = 0x0064 (offset: CAR_VEL_LATERAL_B)
    mov.l @(r0, r1), r3                 ! r3 = car[0x60] (lateral vel A, current)
    mov.l @(r0, r2), r4                 ! r4 = car[0x64] (lateral vel B, current)
    sub r3, r5                          ! r5 = new_lateral_A - current_A (delta A)
    sub r4, r6                          ! r6 = new_lateral_B - current_B (delta B)
    shar r5                             ! r5 >>= 1 (smooth: blend 25%)
    shar r6                             ! r6 >>= 1
    shar r5                             ! r5 >>= 2
    shar r6                             ! r6 >>= 2
    add r3, r5                          ! r5 = current_A + delta_A/4 (blended A)
    add r4, r6                          ! r6 = current_B + delta_B/4 (blended B)
    mov.l r5, @(r0, r1)                 ! car[0x60] = blended lateral vel A
    mov.l r6, @(r0, r2)                 ! car[0x64] = blended lateral vel B
    mov.l @(48, r0), r3                 ! r3 = car[0x30] (heading3, current)
    mov.l @(40, r0), r4                 ! r4 = car[0x28] (heading2, target)
    sub r4, r3                          ! r3 = heading3 - heading2 (heading error)
    exts.w r3, r3                       ! sign-extend (angle wrapping)
    shar r3                             ! r3 >>= 1 (smooth: blend 25%)
    shar r3                             ! r3 >>= 2
    add r4, r3                          ! r3 = heading2 + error/4 (smoothed heading)
    mov.w   DAT_0602cfde, r1            ! r1 = 0x00D0 (offset: CAR_YAW_DELTA)
    .byte   0xD2, 0x13    /* mov.l .L_camera_heading_ptr, r2 */
    add #0x4, r2                        ! r2 = &sym_06063EEC + 4 (camera smooth val)
    mov.l @(r0, r1), r4                 ! r4 = car[0xD0] (yaw delta per frame)
    shar r4                             ! r4 >>= 1
    shar r4                             ! r4 >>= 2
    shar r4                             ! r4 >>= 3
    shar r4                             ! r4 >>= 4
    shar r4                             ! r4 >>= 5 (yaw_delta / 32)
    add r4, r3                          ! r3 += yaw_delta/32 (yaw correction)
    mov.l @r2, r6                       ! r6 = camera_smooth_val (previous frame)
    mov r6, r4                          ! r4 = camera_smooth_val (for sign check)
    mov r6, r7                          ! r7 = camera_smooth_val (for abs compare)
    mov.w   DAT_0602cfe0, r8            ! r8 = 0x4000 (threshold: quarter-turn)
    cmp/pz r7                           ! camera_smooth >= 0?
    bt      .L_smooth_positive          ! if positive, skip abs
    neg r7, r7                          ! r7 = abs(camera_smooth)
.L_smooth_positive:
    cmp/gt r7, r8                       ! threshold > |camera_smooth|?
    bt      .L_apply_smoothed           ! if small, apply smoothed heading directly
    xor r3, r4                          ! r4 = smooth XOR new_heading (sign compare)
    cmp/pz r4                           ! same sign?
    bt      .L_apply_smoothed           ! if same sign, no sign-extension needed
    cmp/pz r6                           ! camera_smooth >= 0?
    bt      .L_negative_sign_ext        ! if positive, apply negative sign extension
    extu.w r6, r6                       ! clear upper 16 bits (positive clamp)
    bra     .L_apply_smoothed           ! continue with clamped value
    nop                                 ! delay slot

    .global DAT_0602cfda
DAT_0602cfda:
    .2byte  0x0060                      ! car struct offset: CAR_VEL_LATERAL_A

    .global DAT_0602cfdc
DAT_0602cfdc:
    .2byte  0x0064                      ! car struct offset: CAR_VEL_LATERAL_B

    .global DAT_0602cfde
DAT_0602cfde:
    .2byte  0x00D0                      ! car struct offset: CAR_YAW_DELTA

    .global DAT_0602cfe0
DAT_0602cfe0:
    .2byte  0x4000                      ! threshold: quarter-turn (16384)
    .2byte  0x0000                      ! alignment padding
.L_heading_alt_offset:
    .4byte  0x0000002C                  ! car struct offset: heading target (+0x2C)
.L_sin_lookup_b:
    .4byte  sin_lookup                  ! -> sin lookup function
.L_lateral_scale_a:
    .4byte  0x0028D0FA                  ! lateral velocity scale A (fixed-point)
.L_lateral_scale_b:
    .4byte  0x03200000                  ! lateral velocity scale B (fixed-point)
.L_camera_heading_ptr:
    .4byte  sym_06063EEC                ! -> camera heading smooth state
.L_negative_sign_ext:
    .byte   0xD4, 0x0B    /* mov.l .L_fp_neg_one, r4 */
    or r4, r6                           ! set upper 16 bits to 0xFFFF (sign-extend neg)
.L_apply_smoothed:
    add r6, r3                          ! r3 += camera_smooth (heading + smooth bias)
    shar r3                             ! r3 >>= 1 (average with bias)
    mov.l r3, @r2                       ! store updated camera smooth value
    mov.w   DAT_0602d020, r2            ! r2 = 0x025C (offset: CAR_HEADING_REF)
    mov.l @(48, r0), r4                 ! r4 = car[0x30] (current heading3)
    mov.l @(r0, r2), r5                 ! r5 = car[0x25C] (heading reference)
    sub r5, r4                          ! r4 = heading3 - heading_ref (divergence)
    mov.w   .L_oor_counter_offset, r6   ! r6 = 0x0258 (offset: out-of-range counter)
    mov.w   .L_divergence_threshold, r8 ! r8 = 0x0444 (divergence threshold)
    cmp/gt r8, r4                       ! divergence > +threshold?
    bt      .L_heading_out_of_range     ! if so, heading is out of range
    neg r8, r8                          ! r8 = -0x0444 (negative threshold)
    cmp/ge r4, r8                       ! -threshold >= divergence? (div < -thresh)
    bt      .L_heading_out_of_range     ! if so, heading is out of range
    mov.l @(r0, r6), r3                 ! r3 = car[0x258] (OOR counter)
    add #0x1, r3                        ! r3++ (increment counter)
    bra     .L_check_counter_limit      ! check if counter hit limit
    mov.l r3, @(r0, r6)                 ! store updated counter (delay slot)

    .global DAT_0602d020
DAT_0602d020:
    .2byte  0x025C                      ! car struct offset: CAR_HEADING_REF
.L_oor_counter_offset:
    .2byte  0x0258                      ! car struct offset: OOR counter
.L_divergence_threshold:
    .2byte  0x0444                      ! heading divergence threshold (angle16)
    .2byte  0x0000                      ! alignment padding
.L_fp_neg_one:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_heading_out_of_range:
    mov.w   DAT_0602d04e, r7            ! r7 = 0x8000 (half-circle correction)
    cmp/pz r5                           ! heading_ref >= 0?
    bt      .L_ref_positive             ! if positive, keep correction positive
    neg r7, r7                          ! r7 = -0x8000 (flip correction sign)
.L_ref_positive:
    add r7, r5                          ! r5 = heading_ref +/- half-circle (wrap)
    mov.l @(48, r0), r4                 ! r4 = car[0x30] (current heading3)
    sub r5, r4                          ! r4 = heading3 - wrapped_ref (new divergence)
    mov.w   DAT_0602d050, r8            ! r8 = 0x0444 (re-check threshold)
    cmp/gt r8, r4                       ! still exceeds +threshold?
    bt      .L_reset_counter            ! if so, reset counter
    neg r8, r8                          ! r8 = -0x0444
    cmp/ge r4, r8                       ! still exceeds -threshold?
    bt      .L_reset_counter            ! if so, reset counter
    mov.l @(r0, r6), r3                 ! r3 = car[0x258] (OOR counter)
    add #0x1, r3                        ! r3++ (increment counter)
    bra     .L_check_counter_limit      ! check counter limit
    mov.l r3, @(r0, r6)                 ! store updated counter (delay slot)

    .global DAT_0602d04e
DAT_0602d04e:
    .2byte  0x8000                      ! half-circle angle (32768 = 180 deg)

    .global DAT_0602d050
DAT_0602d050:
    .2byte  0x0444                      ! heading divergence threshold (re-check)
.L_reset_counter:
    mov #0x0, r3                        ! r3 = 0 (reset counter)
    bra     .L_done                     ! exit function
    mov.l r3, @(r0, r6)                 ! car[0x258] = 0 (delay slot)
.L_check_counter_limit:
    mov.w   DAT_0602d074, r4            ! r4 = 0x0002 (counter limit)
    cmp/gt r3, r4                       ! limit > counter? (counter < 2?)
    bt      .L_done                     ! if counter < 2, no correction needed
    mov.w   DAT_0602d076, r6            ! r6 = 0x0028 (offset: CAR_HEADING2)
    mov.l @(r0, r6), r3                 ! r3 = car[0x28] (CAR_HEADING2)
    sub r3, r5                          ! r5 = heading_ref - heading2 (correction)
    mov.w   DAT_0602d078, r6            ! r6 = 0x003C (heading clamp limit)
    mov.l @(48, r0), r4                 ! r4 = car[0x30] (heading3, for update)
    neg r6, r7                          ! r7 = -0x003C (negative clamp)
    cmp/gt r7, r5                       ! correction > -clamp? (not too negative?)
    bt      .L_check_upper_clamp        ! if above lower bound, check upper
    mov r7, r5                          ! clamp to -0x003C (lower bound)
    bra     .L_apply_heading_clamp      ! apply the clamped correction
    nop                                 ! delay slot

    .global DAT_0602d074
DAT_0602d074:
    .2byte  0x0002                      ! OOR counter limit (2 frames)

    .global DAT_0602d076
DAT_0602d076:
    .2byte  0x0028                      ! car struct offset: CAR_HEADING2

    .global DAT_0602d078
DAT_0602d078:
    .2byte  0x003C                      ! heading correction clamp limit (+/-60)
.L_check_upper_clamp:
    cmp/ge r5, r6                       ! clamp >= correction? (not too positive?)
    bt      .L_apply_heading_clamp      ! if within upper bound, apply
    mov r6, r5                          ! clamp to +0x003C (upper bound)
.L_apply_heading_clamp:
    add r5, r4                          ! r4 = heading3 + clamped correction
    mov.l r4, @(48, r0)                 ! car[0x30] = corrected heading
.L_done:
    lds.l @r15+, pr                     ! restore return address
    rts                                 ! return to caller
    nop                                 ! delay slot
