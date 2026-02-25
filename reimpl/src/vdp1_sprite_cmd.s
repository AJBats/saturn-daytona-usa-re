/* vdp1_sprite_cmd -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0602D08A - 0x0602D43C
 *
 * VDP1 sprite command parameter generator.
 *
 * vdp1_sprite_cmd (0x0602D08A):
 *   Computes per-object sprite display parameters for VDP1 rendering.
 *   r14 = base pointer to car/object render state structure.
 *   Steps:
 *     1. Calculate draw count from object Z distance and visibility state
 *     2. Compute perspective scale via fixed-point multiply + cos_lookup
 *     3. Compute lateral offset via squared distance + atan_piecewise
 *     4. Apply visibility-gated steering correction with cos_lookup
 *     5. Accumulate damped lateral offset into render state
 *     6. Compute angular velocity from target vs current, with damping
 *     7. Final lateral velocity clamp with drift render flag injection
 *
 * Uses SH-2 hardware divider (0xFF00) for 64/32-bit fixed-point divisions.
 * Calls cos_lookup, atan_piecewise, and hw_divide (sym_0602ECCC).
 * BSR to vis_counter_decay (0x0602D7E4) manages visibility frame counter.
 */

    .section .text.FUN_0602D08A


    .global vdp1_sprite_cmd
    .type vdp1_sprite_cmd, @function
vdp1_sprite_cmd:
    sts.l pr, @-r15                 ! save return address
    mov r14, r0                     ! r0 = render state base ptr
    mov.w   DAT_0602d0d4, r1       ! r1 = offset 0x154 (Z distance field)
    mov.l @(r0, r1), r10           ! r10 = object Z distance
    mov.w   .L_off_draw_count, r11 ! r11 = offset 0x168 (draw count field)
    mov.w   DAT_0602d0d8, r2       ! r2 = offset 0x166 (visibility counter)
    mov.w @(r0, r2), r7            ! r7 = visibility counter
    cmp/pl r7                       ! if vis counter > 0...
    bt      .L_begin_perspective    ! ...skip draw count calc
    mov.w   .L_max_abs_range_x, r3 ! r3 = 0x2E0 (max X range)
    .byte   0xD5, 0x10    /* mov.l .L_max_z_distance, r5 */  ! r5 = 0x300 (max Z range)
    mov.l @(8, r0), r7             ! r7 = frame counter
    mov.w   DAT_0602d0dc, r8       ! r8 = 0x104 (frame threshold)
    neg r3, r4                      ! r4 = -0x2E0 (neg X range)
    neg r5, r6                      ! r6 = -0x300 (neg Z range)
    cmp/gt r7, r8                   ! if frame < threshold...
    bt      .L_begin_perspective    ! ...skip draw count calc
    mov.w   DAT_0602d0de, r2       ! r2 = offset 0x5C (lateral velocity)
    mov.l @(r0, r2), r9            ! r9 = lateral velocity
    cmp/gt r5, r9                   ! if lat_vel > max Z...
    bt      .L_begin_perspective    ! ...object too far, skip
    cmp/gt r9, r6                   ! if -max Z > lat_vel...
    bt      .L_begin_perspective    ! ...object too far, skip
    mov r10, r8                     ! r8 = Z distance (copy)
    cmp/gt r3, r10                  ! if Z > max X range...
    bt      .L_z_dist_positive      ! ...Z is positive and large
    cmp/ge r4, r10                  ! if Z >= -max X range...
    bt      .L_begin_perspective    ! ...Z near zero, skip
    neg r8, r8                      ! r8 = abs(Z distance)
.L_z_dist_positive:
    sub r3, r8                      ! r8 = Z_dist - max_range (excess distance)
    mov #0x4, r1                    ! r1 = 4 (min draw count)
    mov #0xF, r2                    ! r2 = 15 (max draw count)
    cmp/gt r1, r8                   ! if excess > 4...
    bt      .L_check_draw_max       ! ...check upper bound
    mov r1, r8                      ! clamp to min draw count = 4
    bra     .L_store_draw_count     ! store clamped value
    nop

    .global DAT_0602d0d4
DAT_0602d0d4:
    .2byte  0x0154
.L_off_draw_count:
    .2byte  0x0168

    .global DAT_0602d0d8
DAT_0602d0d8:
    .2byte  0x0166
.L_max_abs_range_x:
    .2byte  0x02E0

    .global DAT_0602d0dc
DAT_0602d0dc:
    .2byte  0x0104

    .global DAT_0602d0de
DAT_0602d0de:
    .2byte  0x005C
.L_max_z_distance:
    .4byte  0x00000300                  /* max Z distance for draw count */
.L_check_draw_max:
    cmp/gt r8, r2                   ! if max(15) > excess...
    bt      .L_store_draw_count     ! ...excess is in range
    mov r2, r8                      ! clamp to max draw count = 15
.L_store_draw_count:
    mov.w r8, @(r0, r11)           ! write draw count to state[0x168]
.L_begin_perspective:
    mov.w @(r0, r11), r3           ! r3 = current draw count
    cmp/pl r3                       ! if draw count > 0...
    bf      .L_compute_persp_scale  ! ...else skip to perspective calc
    mov.w   DAT_0602d186, r1       ! r1 = offset 0x11C (direction flag)
    mov.l @(r0, r1), r4            ! r4 = direction flag
    cmp/pz r4                       ! if direction >= 0...
    bt      .L_dec_draw_count       ! ...decrement by 1 only
    add #-0x2, r3                   ! facing away: extra decrement
.L_dec_draw_count:
    add #-0x1, r3                   ! decrement draw count by 1
    mov.w r3, @(r0, r11)           ! write back decremented count
    .byte   0xD4, 0x24    /* mov.l .L_mask_nibble4, r4 */  ! r4 = 0xF0000 (nibble mask)
    mov r4, r2                      ! r2 = mask copy
    mov #0x0, r5                    ! r5 = 0 (default perspective scale)
    shll16 r3                       ! r3 = draw_count << 16 (fixed-point)
    sub r3, r2                      ! r2 = mask - scaled_count (inverse)
    mov r2, r3                      ! r3 = inverse draw factor
    cmp/pz r2                       ! if inverse >= 0...
    bf      .L_skip_hw_div          ! ...else skip hw divide path
    mov.w   DAT_0602d188, r1       ! r1 = offset 0x10C (angular velocity)
    mov.l @(r0, r1), r5            ! r5 = angular velocity
    dmuls.l r3, r5                  ! MACH:MACL = inverse * angular_vel
    sts mach, r3                    ! r3 = high 32 bits
    sts macl, r5                    ! r5 = low 32 bits
    xtrct r3, r5                    ! r5 = middle 32 bits (16.16 product)
    mov.w   .L_hw_div_base_a, r2   ! r2 = 0xFF00 (hw divider DVSR)
    mov r5, r3                      ! r3 = product copy
    mov.l r4, @(0, r2)             ! DVSR = mask (divisor)
    shlr16 r3                       ! r3 = product >> 16 (integer part)
    exts.w r3, r3                   ! sign-extend to 32 bits
    mov.l r3, @(16, r2)            ! DVDNTH = high dividend
    shll16 r5                       ! r5 = product << 16 (fractional)
    mov.l r5, @(20, r2)            ! DVDNTL = low dividend (starts divide)
    mov.l @(28, r2), r5            ! r5 = DVDNTL_SHADOW (division result)
.L_skip_hw_div:
    mov.w   DAT_0602d188, r1       ! r1 = offset 0x10C (angular velocity)
    .byte   0xB3, 0x58    /* bsr 0x0602D7E4 (external) */  ! bsr vis_counter_decay
    mov.l r5, @(r0, r1)            ! (delay) store perspective scale
.L_compute_persp_scale:
    mov.w   DAT_0602d18c, r1       ! r1 = offset 0x5C (lateral velocity)
    mov.l @(r0, r1), r4            ! r4 = lateral velocity (cos_lookup arg)
    .byte   0xDD, 0x17    /* mov.l .L_fn_cos_lookup_a, r13 */  ! r13 = cos_lookup ptr
    jsr @r13                        ! r0 = cos(lateral_velocity)
    shll16 r10                      ! (delay) r10 = Z_dist << 16 (fixed-point)
    dmuls.l r0, r10                 ! MACH:MACL = cos_result * Z_dist_fp
    sts mach, r0                    ! r0 = high product
    sts macl, r10                   ! r10 = low product
    xtrct r0, r10                   ! r10 = middle 32 bits (16.16)
    shlr16 r10                      ! r10 = integer part
    exts.w r10, r10                 ! sign-extend perspective scale
    neg r10, r10                    ! negate for screen coords
    mov r14, r0                     ! r0 = render state base ptr
    mov.w   DAT_0602d18e, r1       ! r1 = offset 0x144 (target angle)
    mov.w   DAT_0602d188, r2       ! r2 = offset 0x10C (angular velocity)
    mov.l @(r0, r1), r3            ! r3 = target angle
    mov.l @(r0, r2), r4            ! r4 = angular velocity
    dmuls.l r3, r4                  ! MACH:MACL = angle * angular_vel
    sts mach, r3                    ! r3 = high product
    sts macl, r4                    ! r4 = low product
    xtrct r3, r4                    ! r4 = 16.16 fixed-point product
    mov.w   .L_off_steer_coeff, r2 ! r2 = offset 0xCE (steering coefficient)
    mov.w @(r0, r2), r3            ! r3 = steering coefficient (16-bit)
    dmuls.l r3, r4                  ! MACH:MACL = steer_coeff * angle_product
    sts mach, r3                    ! r3 = high product
    sts macl, r4                    ! r4 = low product
    shll8 r3                        ! r3 <<= 8 (align for 8.24 extract)
    shlr16 r4                       ! r4 >>= 16
    shlr8 r4                        ! r4 >>= 8 (total >>= 24)
    or r3, r4                       ! r4 = combined 8.24 result
    mov.l @(12, r0), r2            ! r2 = state[0xC] (distance squared)
    .byte   0xD3, 0x0A    /* mov.l .L_dist_sq_threshold, r3 */  ! r3 = 0x100 (threshold)
    cmp/ge r3, r2                   ! if dist_sq >= threshold...
    bt      .L_large_dist_path      ! ...use squared distance path
    mov #0x0, r3                    ! r3 = 0 (zero for small dist)
    .byte   0xD6, 0x09    /* mov.l .L_fp_quarter, r6 */  ! r6 = 0x4000 (0.25 fp)
    cmp/ge r3, r4                   ! if angle_product >= 0...
    bt      .L_offset_sign_ok       ! ...keep positive quarter
    neg r6, r6                      ! negate for negative offset
.L_offset_sign_ok:
    bra     .L_begin_steer_correct  ! go to steering correction
    mov.l r3, @-r15                 ! (delay) push zero (dist_sq flag)

    .global DAT_0602d186
DAT_0602d186:
    .2byte  0x011C

    .global DAT_0602d188
DAT_0602d188:
    .2byte  0x010C
.L_hw_div_base_a:
    .2byte  0xFF00

    .global DAT_0602d18c
DAT_0602d18c:
    .2byte  0x005C

    .global DAT_0602d18e
DAT_0602d18e:
    .2byte  0x0144
.L_off_steer_coeff:
    .2byte  0x00CE
    .2byte  0x0000
.L_mask_nibble4:
    .4byte  0x000F0000                  /* nibble 4 mask */
.L_fn_cos_lookup_a:
    .4byte  cos_lookup
.L_dist_sq_threshold:
    .4byte  0x00000100                  /* distance^2 threshold for large path */
.L_fp_quarter:
    .4byte  0x00004000                  /* 0.25 (16.16 fixed-point) */
.L_large_dist_path:
    mov r2, r3                      ! r3 = distance squared
    dmuls.l r2, r3                  ! MACH:MACL = dist_sq * dist_sq
    sts mach, r2                    ! r2 = high product
    sts macl, r3                    ! r3 = low product
    xtrct r2, r3                    ! r3 = dist^4 (16.16 fixed-point)
    mov.l r3, @-r15                 ! push dist^4 (nonzero = large dist flag)
    mov.w   .L_hw_div_base_b, r2   ! r2 = 0xFF00 (hw divider DVSR)
    mov r4, r1                      ! r1 = angle product (dividend)
    mov.l r3, @(0, r2)             ! DVSR = dist^4 (divisor)
    shlr16 r1                       ! r1 = angle_product >> 16
    exts.w r1, r1                   ! sign-extend high dividend
    mov.l r1, @(16, r2)            ! DVDNTH = high dividend
    shll16 r4                       ! r4 = angle_product << 16
    mov.l r4, @(20, r2)            ! DVDNTL = low dividend (starts divide)
    .byte   0xDD, 0x1F    /* mov.l .L_fn_atan_a, r13 */  ! r13 = atan_piecewise ptr
    mov.l @(28, r2), r4            ! r4 = division result (quotient)
    jsr @r13                        ! r0 = atan(quotient)
    nop
    cmp/eq #0x0, r0                 ! if atan result == 0...
    bf      .L_atan_result_a        ! ...else use atan result
    mov.w   DAT_0602d236, r4       ! r4 = offset 0x7F (fallback angle byte)
    add r14, r4                     ! r4 = &state[0x7F]
    mov.b @r4, r0                   ! r0 = fallback angle from state
.L_atan_result_a:
    mov r0, r6                      ! r6 = final angle offset
.L_begin_steer_correct:
    mov r14, r0                     ! r0 = render state base ptr
    mov.w   DAT_0602d238, r1       ! r1 = offset 0x166 (visibility counter)
    mov #0x0, r8                    ! r8 = 0 (correction-applied flag)
    mov.w @(r0, r1), r2            ! r2 = visibility counter
    cmp/pl r2                       ! if vis counter > 0...
    bf      .L_begin_lateral_clamp  ! ...else skip steering correction
    mov.l @(8, r0), r2             ! r2 = frame counter
    mov #0x46, r4                   ! r4 = 70 (min frames for steer correct)
    cmp/ge r4, r2                   ! if frame >= 70...
    bt      .L_begin_lateral_clamp  ! ...too early, skip correction
    mov.w   .L_off_target_lat_pos, r1 ! r1 = offset 0x40 (target lateral pos)
    mov.w   .L_off_lateral_vel, r3 ! r3 = offset 0x5C (lateral velocity)
    mov.l @(r0, r1), r2            ! r2 = target lateral position
    mov.l @(r0, r3), r4            ! r4 = current lateral velocity
    xor r2, r4                      ! check sign mismatch (opposite dirs)
    cmp/pz r4                       ! if same sign...
    bt      .L_begin_lateral_clamp  ! ...no correction needed
    mov #0x1, r8                    ! r8 = 1 (correction applied)
    shar r2                         ! r2 = target_lat / 2
    mov #0x9, r5                    ! r5 = 9 (steering gain)
    muls.w r2, r5                   ! MACL = (target/2) * 9
    shll16 r6                       ! r6 = angle_offset << 16 (fixed-point)
    sts macl, r4                    ! r4 = steering correction factor
    .byte   0xD0, 0x10    /* mov.l .L_fn_cos_lookup_b, r0 */  ! r0 = cos_lookup ptr
    jsr @r0                         ! r0 = cos(correction_factor)
    nop
    dmuls.l r0, r6                  ! MACH:MACL = cos * angle_offset_fp
    sts mach, r2                    ! r2 = high product
    sts macl, r6                    ! r6 = low product
    xtrct r2, r6                    ! r6 = 16.16 fixed-point result
    shlr16 r6                       ! r6 = integer part
    exts.w r6, r6                   ! sign-extend corrected offset
    cmp/pz r6                       ! if corrected >= 0...
    bt      .L_begin_lateral_clamp  ! ...positive is ok
    mov #0x0, r6                    ! clamp negative to zero
.L_begin_lateral_clamp:
    mov.w   .L_off_lateral_vel, r3 ! r3 = offset 0x5C (lateral velocity)
    mov r14, r0                     ! r0 = render state base ptr
    mov.l @(r0, r3), r5            ! r5 = lateral velocity
    mov #0x3, r4                    ! r4 = 3 (scale factor)
    muls.w r4, r6                   ! MACL = 3 * corrected_offset
    neg r5, r5                      ! r5 = -lateral_velocity
    sts macl, r6                    ! r6 = scaled correction
    cmp/pz r5                       ! if -lat_vel >= 0 (vel was negative)...
    bf      .L_clamp_neg_lateral    ! ...else clamp negative path
    cmp/gt r5, r6                   ! if scaled > -lat_vel...
    bt      .L_use_lateral_limit    ! ...use lateral vel as limit
    bra     .L_accum_lateral_offset ! else use scaled correction
    nop
.L_hw_div_base_b:
    .2byte  0xFF00

    .global DAT_0602d236
DAT_0602d236:
    .2byte  0x007F

    .global DAT_0602d238
DAT_0602d238:
    .2byte  0x0166
.L_off_target_lat_pos:
    .2byte  0x0040
.L_off_lateral_vel:
    .2byte  0x005C
    .2byte  0x0000
.L_fn_atan_a:
    .4byte  atan_piecewise
.L_fn_cos_lookup_b:
    .4byte  cos_lookup
.L_clamp_neg_lateral:
    neg r6, r6                      ! r6 = abs(scaled correction)
    cmp/gt r6, r5                   ! if -lat_vel > abs(scaled)...
    bt      .L_use_lateral_limit    ! ...use lateral vel as limit
    bra     .L_accum_lateral_offset ! else use scaled correction
    mov #0x0, r7                    ! (delay) r7 = 0 (unused)
.L_use_lateral_limit:
    mov r5, r6                      ! r6 = -lateral_velocity (limit)
.L_accum_lateral_offset:
    neg r6, r11                     ! r11 = -correction (to subtract)
    mov r14, r0                     ! r0 = render state base ptr
    mov.w   .L_off_accum_lateral, r1 ! r1 = offset 0x178 (accum lateral)
    mov.l @(r0, r1), r5            ! r5 = accumulated lateral offset
    sub r11, r10                    ! r10 = persp_scale + correction
    sub r5, r10                     ! r10 = delta from current accum
    add r10, r5                     ! r5 = new accumulated lateral
    .byte   0xD3, 0x04    /* mov.l .L_max_lateral_range, r3 */  ! r3 = 0x300 (max)
    neg r3, r4                      ! r4 = -0x300 (min)
    cmp/gt r4, r5                   ! if accum > -max...
    bt      .L_check_upper_lateral  ! ...check upper bound
    mov r4, r5                      ! clamp to -max
    bra     .L_store_lateral        ! store clamped value
    nop
.L_off_accum_lateral:
    .2byte  0x0178
    .2byte  0x0000
.L_max_lateral_range:
    .4byte  0x00000300                  /* max lateral accumulator range */
.L_check_upper_lateral:
    cmp/gt r5, r3                   ! if max > accum...
    bt      .L_store_lateral        ! ...accum is in range
    mov r3, r5                      ! clamp to +max
.L_store_lateral:
    mov.l r5, @(r0, r1)            ! store clamped lateral to state[0x178]
    mov.w   DAT_0602d2c4, r2       ! r2 = offset 0x5C (lateral velocity)
    mov.l @(r0, r2), r3            ! r3 = current lateral velocity
    mov r3, r6                      ! r6 = copy of lateral velocity
    add r3, r5                      ! r5 = accum + velocity (sum)
    sub r5, r6                      ! r6 = velocity - sum (error)
    neg r6, r6                      ! r6 = sum - velocity (correction)
    shar r6                         ! r6 >>= 1
    shar r6                         ! r6 >>= 2
    shar r6                         ! r6 >>= 3 (1/8 damping)
    sub r6, r5                      ! r5 = sum - damping correction
    mov.l r5, @(r0, r2)            ! store damped lateral to state[0x5C]
    mov.w   .L_off_target_angle_b, r1 ! r1 = offset 0x140 (target angle B)
    mov.w   .L_off_angular_vel_b, r2 ! r2 = offset 0x108 (angular vel B)
    mov.l @(r0, r1), r3            ! r3 = target angle B
    mov.l @(r0, r2), r4            ! r4 = angular velocity B
    dmuls.l r3, r4                  ! MACH:MACL = angle_B * angular_vel_B
    sts mach, r3                    ! r3 = high product
    sts macl, r4                    ! r4 = low product
    xtrct r3, r4                    ! r4 = 16.16 fixed-point product
    mov.w   DAT_0602d2ca, r2       ! r2 = offset 0xCC (steering coeff B)
    mov.w @(r0, r2), r3            ! r3 = steering coefficient B (16-bit)
    dmuls.l r3, r4                  ! MACH:MACL = steer_B * angle_product
    sts mach, r3                    ! r3 = high product
    sts macl, r4                    ! r4 = low product
    shll8 r3                        ! r3 <<= 8 (align for 8.24 extract)
    shlr16 r4                       ! r4 >>= 16
    shlr8 r4                        ! r4 >>= 8 (total >>= 24)
    or r3, r4                       ! r4 = combined angle product B
    mov.l @r15+, r3                 ! pop dist_sq flag (0 = small, nonzero = large)
    tst r3, r3                      ! if flag is nonzero...
    bf      .L_do_atan_b            ! ...do atan for angular computation
    .byte   0xD6, 0x03    /* mov.l .L_fp_quarter_b, r6 */  ! r6 = 0x4000 (0.25 fp)
    bra     .L_begin_angular_vel    ! skip atan, use default quarter
    nop

    .global DAT_0602d2c4
DAT_0602d2c4:
    .2byte  0x005C
.L_off_target_angle_b:
    .2byte  0x0140
.L_off_angular_vel_b:
    .2byte  0x0108

    .global DAT_0602d2ca
DAT_0602d2ca:
    .2byte  0x00CC
.L_fp_quarter_b:
    .4byte  0x00004000                  /* 0.25 (16.16 fixed-point) */
.L_do_atan_b:
    mov.w   .L_hw_div_base_c, r2   ! r2 = 0xFF00 (hw divider DVSR)
    mov r4, r1                      ! r1 = angle product B (dividend)
    mov.l r3, @(0, r2)             ! DVSR = dist^4 (divisor)
    shlr16 r1                       ! r1 = angle_product >> 16
    exts.w r1, r1                   ! sign-extend high dividend
    mov.l r1, @(16, r2)            ! DVDNTH = high dividend
    shll16 r4                       ! r4 = angle_product << 16
    mov.l r4, @(20, r2)            ! DVDNTL = low dividend (starts divide)
    .byte   0xD0, 0x0A    /* mov.l .L_fn_atan_b, r0 */  ! r0 = atan_piecewise ptr
    mov.l @(28, r2), r4            ! r4 = division result (quotient)
    jsr @r0                         ! r0 = atan(quotient)
    nop
    cmp/eq #0x0, r0                 ! if atan result == 0...
    bf      .L_atan_result_b        ! ...else use atan result
    mov.w   .L_off_fallback_angle, r4 ! r4 = offset 0x7E (fallback angle B)
    add r14, r4                     ! r4 = &state[0x7E]
    mov.b @r4, r0                   ! r0 = fallback angle from state
.L_atan_result_b:
    mov r0, r6                      ! r6 = final angle for angular vel
.L_begin_angular_vel:
    mov r14, r0                     ! r0 = render state base ptr
    mov #0x32, r3                   ! r3 = 50 (min frame clamp)
    mov.w   DAT_0602d30a, r4       ! r4 = 0xFA (250, max frame clamp)
    mov.l @(8, r0), r7             ! r7 = frame counter
    cmp/gt r3, r7                   ! if frame > 50...
    bt      .L_check_frame_upper    ! ...check upper bound
    mov r3, r7                      ! clamp to min = 50
    bra     .L_compute_angular_div  ! proceed to divide
    nop
.L_hw_div_base_c:
    .2byte  0xFF00
.L_off_fallback_angle:
    .2byte  0x007E

    .global DAT_0602d30a
DAT_0602d30a:
    .2byte  0x00FA
.L_fn_atan_b:
    .4byte  atan_piecewise
.L_check_frame_upper:
    cmp/gt r7, r4                   ! if max(250) > frame...
    bt      .L_compute_angular_div  ! ...frame is in range
    mov r4, r7                      ! clamp to max = 250
.L_compute_angular_div:
    sub r3, r4                      ! r4 = max_frame - 50 (divisor range)
    sub r3, r7                      ! r7 = clamped_frame - 50 (dividend)
    .byte   0xDC, 0x1C    /* mov.l .L_fn_hw_divide_a, r12 */  ! r12 = hw_divide ptr
    shll8 r7                        ! r7 = dividend << 8 (fixed-point)
    mov r4, r0                      ! r0 = divisor (for hw_divide)
    jsr @r12                        ! r0 = (frame-50) / (max-50) (normalized)
    mov r7, r1                      ! (delay) r1 = dividend
    mov r14, r0                     ! r0 = render state base ptr
    mov #0x2, r3                    ! r3 = 2
    mov #0x4, r4                    ! r4 = 4 (scale factor)
    muls.w r4, r1                   ! MACL = 4 * normalized_ratio
    shll8 r3                        ! r3 = 0x200 (bias offset)
    sts macl, r7                    ! r7 = scaled ratio
    add r3, r7                      ! r7 = scaled + 0x200 (draw param)
    mov.l r7, @-r15                 ! push draw param for later
    mov.w   .L_off_target_lat_b, r1 ! r1 = offset 0x40 (target lateral B)
    mov.l @(r0, r1), r3            ! r3 = target lateral position B
    mov.w   DAT_0602d38a, r2       ! r2 = offset 0x5C (lateral velocity)
    mov.l @(r0, r2), r4            ! r4 = current lateral velocity
    mov r3, r5                      ! r5 = target (copy for delta)
    sub r4, r5                      ! r5 = target - current (delta)
    muls.w r6, r7                   ! MACL = angle * draw_param
    sts macl, r6                    ! r6 = angle * draw_param
    shar r6                         ! r6 >>= 1
    neg r4, r4                      ! r4 = -current_velocity
    shar r6                         ! r6 >>= 2
    mov r5, r7                      ! r7 = delta (for sign check)
    shar r6                         ! r6 >>= 3
    xor r3, r7                      ! check sign mismatch (target vs delta)
    shar r6                         ! r6 >>= 4
    shar r6                         ! r6 >>= 5
    shar r6                         ! r6 >>= 6
    shar r6                         ! r6 >>= 7
    shar r6                         ! r6 >>= 8 (scale down by 256)
    cmp/pz r7                       ! if same sign (no wrap needed)...
    bt      .L_clamp_angular_vel    ! ...go to clamping
    .byte   0xD4, 0x0C    /* mov.l .L_half_circle_angle, r4 */  ! r4 = 0xFE0 (half circle)
    cmp/pz r3                       ! if target >= 0...
    bt      .L_wrap_angle_offset    ! ...use positive half circle
    neg r4, r4                      ! else negate for wrap direction
.L_wrap_angle_offset:
    sub r4, r3                      ! r3 = target - half_circle (wrapped)
    neg r3, r3                      ! r3 = half_circle - target
    dmuls.l r3, r6                  ! MACH:MACL = wrapped_delta * scaled_angle
    .byte   0xDC, 0x07    /* mov.l .L_fn_hw_divide_a, r12 */  ! r12 = hw_divide ptr
    mov r4, r0                      ! r0 = half_circle (divisor)
    mov.l r1, @-r15                 ! save r1 (offset)
    jsr @r12                        ! r0 = wrapped_ratio
    sts macl, r1                    ! (delay) r1 = product low (dividend)
    mov r0, r6                      ! r6 = wrapped angular velocity
    mov.l @r15+, r1                 ! restore r1 (offset)
    mov r14, r0                     ! r0 = render state base ptr
.L_clamp_angular_vel:
    cmp/pz r5                       ! if delta >= 0...
    bf      .L_clamp_neg_angular    ! ...else check negative path
    cmp/gt r5, r6                   ! if angular_vel > delta...
    bt      .L_use_angular_limit    ! ...clamp to delta
    bra     .L_final_angular_scale  ! else use angular velocity as-is
    nop
.L_off_target_lat_b:
    .2byte  0x0040

    .global DAT_0602d38a
DAT_0602d38a:
    .2byte  0x005C
.L_fn_hw_divide_a:
    .4byte  sym_0602ECCC                /* hw_divide_protected */
.L_half_circle_angle:
    .4byte  0x00000FE0                  /* ~180 degrees in angle units */
.L_clamp_neg_angular:
    neg r6, r6                      ! r6 = abs(angular_vel)
    cmp/gt r6, r5                   ! if -delta > abs(vel)...
    bt      .L_use_angular_limit    ! ...clamp to delta
    bra     .L_final_angular_scale  ! else use angular velocity
    nop
.L_use_angular_limit:
    mov r5, r6                      ! r6 = delta (clamped limit)
.L_final_angular_scale:
    shll8 r6                        ! r6 <<= 8 (fixed-point dividend)
    .byte   0xDC, 0x12    /* mov.l .L_fn_hw_divide_b, r12 */  ! r12 = hw_divide ptr
    mov.l @r15+, r0                 ! r0 = draw_param (divisor, from stack)
    jsr @r12                        ! r0 = angular_vel / draw_param
    mov r6, r1                      ! (delay) r1 = dividend
    mov r0, r6                      ! r6 = scaled angular velocity
    mov r14, r0                     ! r0 = render state base ptr
    sub r5, r6                      ! r6 -= delta (smooth correction)
    mov.w   DAT_0602d3e8, r1       ! r1 = offset 0x58 (damped angular)
    mov.l @(r0, r1), r3            ! r3 = previous damped angular
    sub r6, r3                      ! r3 = previous - new (error)
    neg r3, r3                      ! r3 = new - previous
    shar r3                         ! r3 >>= 1
    shar r3                         ! r3 >>= 2
    shar r3                         ! r3 >>= 3 (1/8 damping)
    sub r3, r6                      ! apply damping correction
    mov.l r6, @(r0, r1)            ! store damped angular to state[0x58]
    mov.l @(8, r0), r3             ! r3 = frame counter
    mov #0x41, r4                   ! r4 = 65 (min frame for drift flags)
    cmp/ge r3, r4                   ! if frame < 65...
    bt      .L_final_vel_clamp      ! ...skip drift flag check
    mov.w   DAT_0602d3ea, r7       ! r7 = offset 0x5C (lateral velocity)
    mov.l @(r0, r7), r6            ! r6 = lateral velocity
    .byte   0xD5, 0x08    /* mov.l .L_neg_lateral_threshold, r5 */  ! r5 = -0x3280
    cmp/ge r6, r5                   ! if vel >= -threshold (near object)...
    bt      .L_set_near_flag        ! ...set near render flag
    neg r5, r5                      ! r5 = +0x3280
    cmp/gt r6, r5                   ! if vel < +threshold...
    bt      .L_final_vel_clamp      ! ...skip flag setting
    mov.l @(0, r0), r2             ! r2 = render flags word
    .byte   0xD3, 0x05    /* mov.l .L_flag_cache_through, r3 */  ! r3 = 0x20000000
    or r3, r2                       ! set cache-through flag
    .byte   0xD3, 0x05    /* mov.l .L_flag_priority_a, r3 */  ! r3 = 0x40000000
    or r3, r2                       ! set far render priority flag
    bra     .L_final_vel_clamp      ! go to velocity clamping
    mov.l r2, @(0, r0)             ! (delay) store flags

    .global DAT_0602d3e8
DAT_0602d3e8:
    .2byte  0x0058

    .global DAT_0602d3ea
DAT_0602d3ea:
    .2byte  0x005C
.L_fn_hw_divide_b:
    .4byte  sym_0602ECCC                /* hw_divide_protected */
.L_neg_lateral_threshold:
    .4byte  0xFFFFCD80                  /* -0x3280 lateral distance threshold */
.L_flag_cache_through:
    .4byte  0x20000000                  /* cache-through render flag */
.L_flag_priority_a:
    .4byte  0x40000000                  /* far render priority flag */
.L_set_near_flag:
    mov.l @(0, r0), r2             ! r2 = render flags word
    .byte   0xD3, 0x03    /* mov.l .L_flag_render_near, r3 */  ! r3 = 0x10000000
    or r3, r2                       ! set near-object render flag
    .byte   0xD3, 0x03    /* mov.l .L_flag_priority_b, r3 */  ! r3 = 0x40000000
    or r3, r2                       ! set near priority flag
    bra     .L_final_vel_clamp      ! go to velocity clamping
    mov.l r2, @(0, r0)             ! (delay) store flags
    .2byte  0x0000
.L_flag_render_near:
    .4byte  0x10000000                  /* near-object render flag */
.L_flag_priority_b:
    .4byte  0x40000000                  /* near render priority flag */
.L_final_vel_clamp:
    mov.w   DAT_0602d432, r7       ! r7 = offset 0x5C (lateral velocity)
    mov.l @(r0, r7), r6            ! r6 = lateral velocity
    .byte   0xD3, 0x07    /* mov.l .L_vel_clamp_limit, r3 */  ! r3 = -0x3400 (clamp)
    cmp/ge r6, r3                   ! if vel >= -clamp (near limit)...
    bt      .L_vel_exceeded_clamp   ! ...clamp and set flag
    neg r3, r3                      ! r3 = +0x3400
    cmp/ge r6, r3                   ! if vel >= +clamp...
    bt      .L_return               ! ...within range, return
.L_vel_exceeded_clamp:
    mov r3, r6                      ! clamp velocity to limit
    mov #0x1, r4                    ! r4 = 1 (flag value)
    mov.w   .L_off_clamp_flag, r1  ! r1 = offset 0xD4 (clamp flag)
    mov.w r4, @(r0, r1)            ! set clamp-occurred flag
.L_return:
    lds.l @r15+, pr                 ! restore return address
    rts                             ! return
    mov.l r6, @(r0, r7)            ! (delay) store clamped velocity

    .global DAT_0602d432
DAT_0602d432:
    .2byte  0x005C
.L_off_clamp_flag:
    .2byte  0x00D4
    .2byte  0x0000
.L_vel_clamp_limit:
    .4byte  0xFFFFCC00                  /* -0x3400 velocity clamp limit */
