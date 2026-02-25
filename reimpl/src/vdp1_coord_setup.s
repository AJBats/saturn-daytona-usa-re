/* vdp1_coord_setup -- VDP1 Coordinate Transform for Per-Car Rendering
 * Translation unit: 0x0602CA84 - 0x0602CCEC
 *
 * Step 15 of the per-car render orchestrator (render_orchestrator.s).
 * Called after vdp1_color_setup, before display submission.
 *
 * Computes the VDP1 screen-space coordinate origin offsets for a car's
 * sprite rendering, based on camera-relative velocity decomposition and
 * perspective scaling.
 *
 * r0 = car/render state base pointer (preserved in r14).
 * r14 = car base pointer (aliased from r0 early, restored for callees).
 *
 * Algorithm:
 *   1. Load velocity state (car+0x100, car+0x104) and negate both.
 *   2. Scale -vel_state_y by horizontal factor (0x03700000 ~880 FP16.16)
 *      and vertical factor (0x02D00000 ~720 FP16.16) via 64-bit multiply,
 *      extracting middle 32 bits for each (r6 = horiz, r7 = vert).
 *   3. Load angular velocity components (car+0x60, car+0x64) and multiply
 *      angular_vel_a by -vel_state_x. If the products have matching signs,
 *      negate r6 before summing (rounding toward zero). Sum into r6 (X coord).
 *   4. Similarly multiply angular_vel_b by -vel_state_x. If signs match
 *      with the vertical product, negate r7. Sum into r7 (Y coord), store
 *      to car+0x148 (frame counter / coord Y output).
 *   5. Load blend_result_a (car+0xEC) and final_blend (car+0xF8). Compute
 *      abs(difference) as separation distance. Blend separation into X coord
 *      at 25% weight (shar x2 = /4).
 *   6. Compute X coordinate scale: if display_scale_x (car+0x140) > blended X,
 *      set scale to 1.0 (0x00010000). Otherwise call fpdiv_setup to get the
 *      ratio (blended_x / display_scale_x). Store to car+0x108.
 *   7. Negate blend_result_a, add final_blend, subtract force_aux (car+0xF4)
 *      to get raw Y offset. Compute vertical separation from blend_result_b
 *      (car+0xF0) and decel_coeff (car+0x11C). Blend at 25% into Y.
 *   8. Compute Y coordinate scale: same fpdiv_setup pattern, store to car+0x10C.
 *   9. If vertical was within range (r10=1) and Y scale < 0x0000CCCC (~0.8 FP),
 *      and gear_rotation (car+0xD8) <= 0, call sym_0602CCD0 to boost timer.
 *  10. Compute yaw-based screen position from -Y_offset - force_aux,
 *      arithmetic shift right 3 times, store to obj_data (car+0x40).
 *  11. If clip_flags (car+0x0150, word) non-zero, adjust render_param_a/b
 *      (car+0x58, car+0x5C) and zero angular velocity (car+0x60, car+0x64).
 *  12. If collision_state (car+0x0250, word) non-zero, zero obj_data and
 *      angular velocities, set depth_offset (car+0x110) to -1.0 (0xFFFF0000).
 *  13. Call vdp1_attr_setup (BSR to next TU at 0x0602CCEC).
 *  14. Final: multiply perspective_scale (car+0x108) and coord_scale_y
 *      (car+0x10C) with a screen-space conversion factor, arithmetic shift
 *      right 8 to produce final pixel offset, store to car+0xFC (accel_delta).
 *
 * Contains two functions:
 *   vdp1_coord_setup (0x0602CA84) -- main coordinate transform
 *   sym_0602CCD0                  -- timer boost helper (boosts car+0x152
 *                                    if speed > 0x14 and render_type <= 4)
 */

    .section .text.FUN_0602CA84


    .global vdp1_coord_setup
    .type vdp1_coord_setup, @function
vdp1_coord_setup:
    sts.l pr, @-r15                     ! save return address
    mov.w   DAT_0602cb04, r1            ! r1 = 0x0104 (offset: vel_state_y)
    mov.l @(r0, r1), r2                 ! r2 = car.vel_state_y
    neg r2, r2                          ! r2 = -vel_state_y
    mov.w   DAT_0602cb06, r1            ! r1 = 0x0100 (offset: vel_state_x)
    mov.l   .L_pool_horiz_scale, r4     ! r4 = 0x03700000 (~880.0 FP16.16 horizontal factor)
    mov.l @(r0, r1), r5                 ! r5 = car.vel_state_x
    neg r5, r5                          ! r5 = -vel_state_x
    dmuls.l r4, r5                      ! MAC = horiz_scale * (-vel_state_x)
    mov r0, r14                         ! r14 = car base pointer (preserve for later)
    sts mach, r4                        ! r4 = MAC high 32 bits
    sts macl, r6                        ! r6 = MAC low 32 bits
    xtrct r4, r6                        ! r6 = mid-32 = horiz-scaled vel_x (16.16 FP)
    mov.l   .L_pool_vert_scale, r4      ! r4 = 0x02D00000 (~720.0 FP16.16 vertical factor)
    dmuls.l r4, r5                      ! MAC = vert_scale * (-vel_state_x)
    sts mach, r4                        ! r4 = MAC high 32 bits
    sts macl, r7                        ! r7 = MAC low 32 bits
    xtrct r4, r7                        ! r7 = mid-32 = vert-scaled vel_x (16.16 FP)
    mov.w   DAT_0602cb08, r1            ! r1 = 0x0060 (offset: angular_vel_a)
    mov.l @(r0, r1), r4                 ! r4 = car.angular_vel_a
    dmuls.l r4, r2                      ! MAC = angular_vel_a * (-vel_state_y)
    mov.w   DAT_0602cb0a, r3            ! r3 = 0x0064 (offset: angular_vel_b)
    mov.l @(r0, r3), r8                 ! r8 = car.angular_vel_b
    sts mach, r4                        ! r4 = MAC high 32 bits
    sts macl, r5                        ! r5 = MAC low 32 bits
    xtrct r4, r5                        ! r5 = mid-32 = ang_a * (-vel_y) (16.16 FP)
    dmuls.l r8, r2                      ! MAC = angular_vel_b * (-vel_state_y)
    mov r5, r12                         ! r12 = angular product A
    xor r6, r12                         ! r12 = product_A XOR horiz_scaled (sign compare)
    cmp/pz r12                          ! same sign? (XOR >= 0)
    bf      .L_x_signs_differ           ! if signs differ, skip negation of r6
    neg r6, r6                          ! signs agree: negate horiz component (round toward 0)
.L_x_signs_differ:
    add r5, r6                          ! r6 = ang_product_A + adjusted_horiz = X coord raw
    mov.l r6, @-r15                     ! push X coord raw onto stack
    sts mach, r8                        ! r8 = MAC high 32 bits (from ang_b * -vel_y)
    sts macl, r2                        ! r2 = MAC low 32 bits
    xtrct r8, r2                        ! r2 = mid-32 = ang_b * (-vel_y) (16.16 FP)
    mov r2, r12                         ! r12 = angular product B
    xor r7, r12                         ! r12 = product_B XOR vert_scaled (sign compare)
    cmp/pz r12                          ! same sign? (XOR >= 0)
    bf      .L_y_signs_differ           ! if signs differ, skip negation of r7
    neg r7, r7                          ! signs agree: negate vert component (round toward 0)
.L_y_signs_differ:
    add r2, r7                          ! r7 = ang_product_B + adjusted_vert = Y coord raw
    mov.w   DAT_0602cb0c, r1            ! r1 = 0x0148 (offset: coord_y_output)
    mov.l r7, @(r0, r1)                 ! car.coord_y_output = Y coord raw
    mov.w   DAT_0602cb0e, r1            ! r1 = 0x00EC (offset: blend_result_a)
    mov.w   .L_wpool_off_final_blend, r2 ! r2 = 0x00F8 (offset: final_blend)
    mov.l @(r0, r1), r3                 ! r3 = car.blend_result_a
    mov r3, r8                          ! r8 = blend_result_a (save for later)
    mov.l @(r0, r2), r4                 ! r4 = car.final_blend
    mov r4, r9                          ! r9 = final_blend (save for later)
    sub r4, r3                          ! r3 = blend_result_a - final_blend (separation)
    cmp/pz r3                           ! is separation >= 0?
    bt      .L_sep_positive             ! if positive, keep as-is
    neg r3, r3                          ! negate: r3 = abs(separation)
.L_sep_positive:
    cmp/pz r6                           ! is X coord raw >= 0?
    bt      .L_x_positive               ! if positive, keep as-is
    neg r6, r6                          ! negate: r6 = abs(X coord raw)
.L_x_positive:
    cmp/ge r6, r3                       ! is abs(separation) >= abs(X coord)?
    bt      .L_sep_dominates_x          ! if separation larger, blend separation into X
    shar r3                             ! r3 = separation / 2 (25% blend: divide by 4)
    shar r3                             ! r3 = separation / 4
    bra     .L_compute_x_scale          ! skip to X scale computation
    add r3, r6                          ! (delay) r6 = abs(X) + separation/4 (blended X)

    .global DAT_0602cb04
DAT_0602cb04:
    .2byte  0x0104                      /* car+0x104: vel_state_y (longword, 16.16 FP) */

    .global DAT_0602cb06
DAT_0602cb06:
    .2byte  0x0100                      /* car+0x100: vel_state_x (longword, 16.16 FP) */

    .global DAT_0602cb08
DAT_0602cb08:
    .2byte  0x0060                      /* car+0x60: angular_vel_a (longword) */

    .global DAT_0602cb0a
DAT_0602cb0a:
    .2byte  0x0064                      /* car+0x64: angular_vel_b (longword) */

    .global DAT_0602cb0c
DAT_0602cb0c:
    .2byte  0x0148                      /* car+0x148: coord_y_output (longword) */

    .global DAT_0602cb0e
DAT_0602cb0e:
    .2byte  0x00EC                      /* car+0xEC: blend_result_a (longword, 70% blend) */
.L_wpool_off_final_blend:
    .2byte  0x00F8                      /* car+0xF8: final_blend output (longword) */
    .2byte  0x0000                      /* alignment padding */
.L_pool_horiz_scale:
    .4byte  0x03700000                  /* ~880.0 FP16.16 (horizontal scale factor) */
.L_pool_vert_scale:
    .4byte  0x02D00000                  /* ~720.0 FP16.16 (vertical scale factor) */
.L_sep_dominates_x:
    shar r6                             ! r6 = abs(X) / 2 (25% blend: divide by 4)
    shar r6                             ! r6 = abs(X) / 4
    add r3, r6                          ! r6 = abs(sep) + abs(X)/4 (blended X, sep dominant)
.L_compute_x_scale:
    mov.l   .L_fp_one, r10              ! r10 = 0x00010000 (1.0 in 16.16 FP, default scale)
    mov.w   DAT_0602cb72, r1            ! r1 = 0x0140 (offset: display_scale_x)
    mov.l @(r0, r1), r4                 ! r4 = car.display_scale_x
    cmp/gt r6, r4                       ! is display_scale_x > blended_x?
    bt      .L_store_x_scale            ! if display exceeds blended, keep scale = 1.0
    mov.l   .L_fn_fpdiv_a, r0           ! r0 = &fpdiv_setup
    jsr @r0                             ! r0 = fpdiv_setup(r4=display_scale_x, r5=blended_x)
    mov r6, r5                          ! (delay) r5 = blended_x (divisor)
    mov r0, r10                         ! r10 = computed X scale factor
    mov r14, r0                         ! r0 = car base pointer (restore)
.L_store_x_scale:
    mov.w   DAT_0602cb74, r1            ! r1 = 0x0108 (offset: coord_scale_x)
    mov.l r10, @(r0, r1)                ! car.coord_scale_x = X scale factor
    neg r8, r8                          ! r8 = -blend_result_a
    mov.w   DAT_0602cb76, r1            ! r1 = 0x00F4 (offset: force_aux)
    mov.l @(r0, r1), r2                 ! r2 = car.force_aux (heading contribution)
    add r9, r2                          ! r2 = force_aux + final_blend
    sub r2, r8                          ! r8 = -blend_result_a - (force_aux + final_blend) = raw Y offset
    mov.l @r15+, r6                     ! pop X coord raw from stack
    mov.l r8, @-r15                     ! push raw Y offset onto stack
    mov.l r2, @-r15                     ! push (force_aux + final_blend) onto stack
    mov.w   DAT_0602cb78, r1            ! r1 = 0x00F0 (offset: blend_result_b)
    mov.l @(r0, r1), r3                 ! r3 = car.blend_result_b (50% blend)
    mov.w   DAT_0602cb7a, r2            ! r2 = 0x011C (offset: decel_coeff)
    mov.l @(r0, r2), r4                 ! r4 = car.decel_coeff
    sub r4, r3                          ! r3 = blend_result_b - decel_coeff (vert separation)
    mov r3, r6                          ! r6 = vert separation (save for later)
    mov #0x0, r10                       ! r10 = 0 (flag: Y was NOT within range)
    cmp/pz r7                           ! is Y coord raw >= 0?
    bt      .L_y_abs_done               ! if positive, keep as-is
    neg r7, r7                          ! negate: r7 = abs(Y coord raw)
.L_y_abs_done:
    sub r9, r3                          ! r3 = (blend_b - decel) - final_blend
    cmp/pz r3                           ! is adjusted separation >= 0?
    bf      .L_neg_vert_sep             ! if negative, handle separately
    cmp/ge r7, r3                       ! is adj_sep >= abs(Y)?
    bf      .L_y_sep_small              ! if separation < Y, blend at 25%
    mov #0x1, r10                       ! r10 = 1 (flag: Y is within range)
    shar r7                             ! r7 = abs(Y) / 2 (25% blend)
    shar r7                             ! r7 = abs(Y) / 4
    bra     .L_compute_y_scale          ! skip to Y scale computation
    add r7, r3                          ! (delay) r3 = adj_sep + abs(Y)/4 (blended Y)

    .global DAT_0602cb72
DAT_0602cb72:
    .2byte  0x0140                      /* car+0x140: display_scale_x (longword, 16.16 FP) */

    .global DAT_0602cb74
DAT_0602cb74:
    .2byte  0x0108                      /* car+0x108: coord_scale_x (longword, 16.16 FP) */

    .global DAT_0602cb76
DAT_0602cb76:
    .2byte  0x00F4                      /* car+0xF4: force_aux (heading contribution) */

    .global DAT_0602cb78
DAT_0602cb78:
    .2byte  0x00F0                      /* car+0xF0: blend_result_b (longword, 50% blend) */

    .global DAT_0602cb7a
DAT_0602cb7a:
    .2byte  0x011C                      /* car+0x11C: decel_coeff (longword, 16.16 FP) */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_fn_fpdiv_a:
    .4byte  fpdiv_setup                 /* 16.16 fixed-point hardware divide (r4/r5 -> r0) */
.L_y_sep_small:
    shar r3                             ! r3 = adj_sep / 2 (25% blend)
    shar r3                             ! r3 = adj_sep / 4
    bra     .L_compute_y_scale          ! skip to Y scale computation
    add r7, r3                          ! (delay) r3 = abs(Y) + adj_sep/4 (blended Y)
.L_neg_vert_sep:
    neg r3, r3                          ! r3 = abs(adj_sep) (was negative)
    cmp/ge r7, r3                       ! is abs(adj_sep) >= abs(Y)?
    bt      .L_neg_sep_dominates        ! if separation dominates, blend abs(Y) at 25%
    shar r3                             ! r3 = abs(adj_sep) / 2 (25% blend)
    shar r3                             ! r3 = abs(adj_sep) / 4
    bra     .L_compute_y_scale          ! skip to Y scale computation
    add r7, r3                          ! (delay) r3 = abs(Y) + abs(adj_sep)/4 (blended Y)
.L_neg_sep_dominates:
    shar r7                             ! r7 = abs(Y) / 2 (25% blend)
    shar r7                             ! r7 = abs(Y) / 4
    add r7, r3                          ! r3 = abs(adj_sep) + abs(Y)/4 (blended Y)
.L_compute_y_scale:
    mov #0x1, r11                       ! r11 = 1 (will become 0x00010000 = 1.0 default)
    mov.w   DAT_0602cc9c, r1            ! r1 = 0x0144 (offset: display_scale_y)
    shll16 r11                          ! r11 = 0x00010000 (1.0 in 16.16 FP, default Y scale)
    mov.l @(r0, r1), r4                 ! r4 = car.display_scale_y
    cmp/ge r3, r4                       ! is display_scale_y >= blended_y?
    bt      .L_store_y_scale            ! if display exceeds blended, keep scale = 1.0
    mov.l   .L_fn_fpdiv_b, r0           ! r0 = &fpdiv_setup
    jsr @r0                             ! r0 = fpdiv_setup(r4=display_scale_y, r5=blended_y)
    mov r3, r5                          ! (delay) r5 = blended_y (divisor)
    mov r0, r11                         ! r11 = computed Y scale factor
    mov r14, r0                         ! r0 = car base pointer (restore)
.L_store_y_scale:
    mov.w   DAT_0602cc9e, r1            ! r1 = 0x010C (offset: coord_scale_y)
    mov.l r11, @(r0, r1)                ! car.coord_scale_y = Y scale factor
    tst r10, r10                        ! was Y within range? (r10 == 0 means no)
    bt      .L_skip_timer_boost         ! if not in range, skip timer boost check
    mov.l   .L_pool_min_y_scale, r2     ! r2 = 0x0000CCCC (~0.8 in 16.16 FP)
    cmp/gt r2, r11                      ! is Y_scale > 0.8?
    bt      .L_skip_timer_boost         ! if scale > 0.8, skip (not close enough)
    mov.w   DAT_0602cca0, r1            ! r1 = 0x00D8 (offset: gear_rotation)
    mov.l @(r0, r1), r2                 ! r2 = car.gear_rotation
    cmp/pl r2                           ! is gear_rotation > 0?
    bt      .L_skip_timer_boost         ! if positive, skip boost (already active)
    bsr     sym_0602CCD0                ! call timer boost helper
    nop                                 ! delay slot
    mov r14, r0                         ! r0 = car base pointer (restore after BSR)
.L_skip_timer_boost:
    neg r6, r6                          ! r6 = -vert_separation
    mov.l @r15+, r2                     ! pop (force_aux + final_blend) from stack
    sub r2, r6                          ! r6 = -vert_sep - (force_aux + final_blend) = Y offset
    mov.l r6, @-r15                     ! push Y offset onto stack
    mov.w   DAT_0602cca2, r1            ! r1 = 0x00D0 (offset: yaw_deflection)
    mov.l @(r0, r1), r2                 ! r2 = car.yaw_deflection
    neg r2, r2                          ! r2 = -yaw_deflection
    shar r2                             ! r2 >>= 1 (arithmetic shift: /2)
    mov.w   DAT_0602cca4, r1            ! r1 = 0x0040 (offset: obj_data)
    shar r2                             ! r2 >>= 1 (total /4)
    shar r2                             ! r2 >>= 1 (total /8)
    mov.l r2, @(r0, r1)                 ! car.obj_data = -yaw_deflection / 8
    mov.w   DAT_0602cca6, r1            ! r1 = 0x0150 (offset: clip_flags, word)
    mov.w @(r0, r1), r2                 ! r2 = car.clip_flags (16-bit)
    tst r2, r2                          ! are clip flags zero?
    bt      .L_check_collision_state    ! if zero, skip clip adjustment
    mov.w   DAT_0602cca8, r1            ! r1 = 0x0058 (offset: render_param_a)
    mov.w   DAT_0602ccaa, r2            ! r2 = 0x005C (offset: render_param_b)
    mov.l @(r0, r1), r3                 ! r3 = car.render_param_a
    mov.l @(r0, r2), r4                 ! r4 = car.render_param_b
    mov r3, r7                          ! r7 = render_param_a (save original)
    sub r4, r3                          ! r3 = param_a - param_b
    sub r7, r3                          ! r3 = (param_a - param_b) - param_a = -param_b
    neg r4, r11                         ! r11 = -render_param_b
    shar r3                             ! r3 >>= 1 (/2)
    shar r11                            ! r11 >>= 1 (/2)
    shar r3                             ! r3 >>= 1 (total /4 of -param_b)
    shar r11                            ! r11 >>= 1 (total /4 of -param_b)
    add r3, r7                          ! r7 = param_a + (-param_b)/4 (adjusted param_a)
    add r4, r11                         ! r11 = param_b + (-param_b)/4 = param_b * 3/4
    mov.l r7, @(r0, r1)                 ! car.render_param_a = adjusted param_a
    mov.l r11, @(r0, r2)                ! car.render_param_b = adjusted param_b
    mov #0x0, r11                       ! r11 = 0
    mov.w   DAT_0602ccac, r1            ! r1 = 0x0060 (offset: angular_vel_a)
    mov.w   DAT_0602ccae, r2            ! r2 = 0x0064 (offset: angular_vel_b)
    mov.l r11, @(r0, r1)                ! car.angular_vel_a = 0 (clear on clip)
    mov.l r11, @(r0, r2)                ! car.angular_vel_b = 0 (clear on clip)
.L_check_collision_state:
    mov.w   DAT_0602ccb0, r1            ! r1 = 0x0250 (offset: collision_state, word)
    mov #0x0, r11                       ! r11 = 0
    mov.w @(r0, r1), r4                 ! r4 = car.collision_state (16-bit)
    tst r4, r4                          ! is collision state zero?
    bt      .L_call_attr_setup          ! if zero, proceed to attr setup
    mov.w   DAT_0602cca4, r1            ! r1 = 0x0040 (offset: obj_data)
    mov.w   DAT_0602cca8, r2            ! r2 = 0x0058 (offset: render_param_a)
    mov.w   DAT_0602ccaa, r3            ! r3 = 0x005C (offset: render_param_b)
    mov.l r11, @(r0, r1)                ! car.obj_data = 0 (clear on collision)
    mov.l r11, @(r0, r2)                ! car.render_param_a = 0 (clear on collision)
    mov.l r11, @(r0, r3)                ! car.render_param_b = 0 (clear on collision)
    mov.w   DAT_0602ccac, r1            ! r1 = 0x0060 (offset: angular_vel_a)
    mov.w   DAT_0602ccae, r2            ! r2 = 0x0064 (offset: angular_vel_b)
    mov.l r11, @(r0, r1)                ! car.angular_vel_a = 0 (clear on collision)
    mov.l r11, @(r0, r2)                ! car.angular_vel_b = 0 (clear on collision)
    mov.l   .L_fp_neg_one, r2           ! r2 = 0xFFFF0000 (-1.0 in 16.16 FP)
    mov.w   DAT_0602ccb2, r1            ! r1 = 0x0110 (offset: depth_offset)
    mov.l r2, @(r0, r1)                 ! car.depth_offset = -1.0 (mark invalid)
.L_call_attr_setup:
    .byte   0xB0, 0x54    /* bsr 0x0602CCEC (external) */ ! call vdp1_attr_setup
    nop                                 ! delay slot
    mov.l @r15+, r9                     ! pop Y offset from stack
    mov.l @r15+, r5                     ! pop raw Y offset from stack
    mov.w   DAT_0602ccb4, r1            ! r1 = 0x0108 (offset: coord_scale_x)
    mov.l @(r0, r1), r4                 ! r4 = car.coord_scale_x
    mov.w   DAT_0602cc9e, r1            ! r1 = 0x010C (offset: coord_scale_y)
    mov.l @(r0, r1), r2                 ! r2 = car.coord_scale_y
    mov.w   DAT_0602ccb6, r1            ! r1 = 0x0114 (offset: lighting_output)
    mov.l @(r0, r1), r3                 ! r3 = car.lighting_output
    mov.l   .L_pool_screen_conv_320, r1 ! r1 = 0x00000140 (320 = screen width factor)
    mov.w   DAT_0602ccb8, r10           ! r10 = 0x007C (offset: render_type)
    mov.w @(r0, r10), r10               ! r10 = car.render_type (16-bit)
    mov #0x4, r6                        ! r6 = 4
    cmp/eq r6, r10                      ! is render_type == 4?
    bt      .L_final_multiply           ! if type 4, use 320 as conversion factor
    mov #0x5, r6                        ! r6 = 5
    cmp/eq r6, r10                      ! is render_type == 5?
    bt      .L_final_multiply           ! if type 5, use 320 as conversion factor
    mov.l   .L_pool_screen_conv_256, r1 ! r1 = 0x00000100 (256 = alternate screen factor)
.L_final_multiply:
    dmuls.l r4, r5                      ! MAC = coord_scale_x * raw_Y_offset
    sts mach, r4                        ! r4 = MAC high 32 bits
    sts macl, r6                        ! r6 = MAC low 32 bits
    xtrct r4, r6                        ! r6 = mid-32 = scaled X (16.16 FP)
    dmuls.l r9, r2                      ! MAC = Y_offset * coord_scale_y
    sts mach, r9                        ! r9 = MAC high 32 bits
    sts macl, r2                        ! r2 = MAC low 32 bits
    xtrct r9, r2                        ! r2 = mid-32 = scaled Y (16.16 FP)
    add r2, r6                          ! r6 = scaled_X + scaled_Y (combined coord offset)
    sub r3, r6                          ! r6 = combined - lighting_output (adjust for light)
    dmuls.l r6, r1                      ! MAC = adjusted_offset * screen_conv_factor
    mov.w   DAT_0602ccba, r4            ! r4 = 0x00FC (offset: accel_delta / speed_delta)
    sts mach, r6                        ! r6 = MAC high 32 bits
    sts macl, r3                        ! r3 = MAC low 32 bits
    xtrct r6, r3                        ! r3 = mid-32 = screen-space offset (16.16 FP)
    shar r3                             ! r3 >>= 1 (/2)
    shar r3                             ! r3 >>= 1 (/4)
    shar r3                             ! r3 >>= 1 (/8)
    shar r3                             ! r3 >>= 1 (/16)
    shar r3                             ! r3 >>= 1 (/32)
    shar r3                             ! r3 >>= 1 (/64)
    shar r3                             ! r3 >>= 1 (/128)
    shar r3                             ! r3 >>= 1 (/256 total = shift right 8)
    lds.l @r15+, pr                     ! restore return address
    rts                                 ! return to caller
    mov.l r3, @(r0, r4)                 ! (delay) car.accel_delta = final pixel offset

    .global DAT_0602cc9c
DAT_0602cc9c:
    .2byte  0x0144                      /* car+0x144: display_scale_y (longword, 16.16 FP) */

    .global DAT_0602cc9e
DAT_0602cc9e:
    .2byte  0x010C                      /* car+0x10C: coord_scale_y (longword, 16.16 FP) */

    .global DAT_0602cca0
DAT_0602cca0:
    .2byte  0x00D8                      /* car+0xD8: gear_rotation state (longword) */

    .global DAT_0602cca2
DAT_0602cca2:
    .2byte  0x00D0                      /* car+0xD0: yaw_deflection (longword) */

    .global DAT_0602cca4
DAT_0602cca4:
    .2byte  0x0040                      /* car+0x40: obj_data pointer (longword) */

    .global DAT_0602cca6
DAT_0602cca6:
    .2byte  0x0150                      /* car+0x150: clip_flags (word) */

    .global DAT_0602cca8
DAT_0602cca8:
    .2byte  0x0058                      /* car+0x58: render_param_a (longword) */

    .global DAT_0602ccaa
DAT_0602ccaa:
    .2byte  0x005C                      /* car+0x5C: render_param_b (longword) */

    .global DAT_0602ccac
DAT_0602ccac:
    .2byte  0x0060                      /* car+0x60: angular_vel_a (longword) */

    .global DAT_0602ccae
DAT_0602ccae:
    .2byte  0x0064                      /* car+0x64: angular_vel_b (longword) */

    .global DAT_0602ccb0
DAT_0602ccb0:
    .2byte  0x0250                      /* car+0x250: collision_state (word) */

    .global DAT_0602ccb2
DAT_0602ccb2:
    .2byte  0x0110                      /* car+0x110: depth_offset (longword, 16.16 FP) */

    .global DAT_0602ccb4
DAT_0602ccb4:
    .2byte  0x0108                      /* car+0x108: coord_scale_x (longword, 16.16 FP) */

    .global DAT_0602ccb6
DAT_0602ccb6:
    .2byte  0x0114                      /* car+0x114: lighting_output (longword) */

    .global DAT_0602ccb8
DAT_0602ccb8:
    .2byte  0x007C                      /* car+0x7C: render_type (word) */

    .global DAT_0602ccba
DAT_0602ccba:
    .2byte  0x00FC                      /* car+0xFC: accel_delta / speed_delta (longword) */
.L_fn_fpdiv_b:
    .4byte  fpdiv_setup                 /* 16.16 fixed-point hardware divide (r4/r5 -> r0) */
.L_pool_min_y_scale:
    .4byte  0x0000CCCC                  /* ~0.8 in 16.16 FP (min Y scale threshold) */
.L_fp_neg_one:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_pool_screen_conv_320:
    .4byte  0x00000140                  /* 320 = screen width conversion factor */
.L_pool_screen_conv_256:
    .4byte  0x00000100                  /* 256 = alternate screen width factor */

/* sym_0602CCD0 -- Timer boost helper
 *
 * Called from vdp1_coord_setup when the Y coordinate scale is small (< 0.8)
 * and gear_rotation is not active. Bumps the effect timer (car+0x152) to 0xA
 * if the car is fast enough (speed > 0x14) and render_type <= 4.
 *
 * r0 = car base pointer.
 */
    .global sym_0602CCD0
sym_0602CCD0:
    mov.w   .L_wpool_off_timer_b, r7   ! r7 = 0x0152 (offset: timer_b effect duration)
    mov.w @(r0, r7), r3                 ! r3 = car.timer_b (16-bit)
    mov #0x4, r4                        ! r4 = 4 (max render_type for boost)
    cmp/gt r4, r3                       ! is timer_b > 4?
    bt      .L_timer_boost_done         ! if already high enough, skip
    mov.l @(8, r0), r3                  ! r3 = car.speed (at car+0x08)
    mov #0x14, r4                       ! r4 = 0x14 (minimum speed threshold)
    cmp/ge r3, r4                       ! is 0x14 >= speed? (speed <= 0x14?)
    bt      .L_timer_boost_done         ! if too slow, skip boost
    mov #0xA, r4                        ! r4 = 0xA (boost value for timer)
    mov.w r4, @(r0, r7)                 ! car.timer_b = 0xA (boost effect duration)
.L_timer_boost_done:
    rts                                 ! return to caller
    nop                                 ! delay slot
.L_wpool_off_timer_b:
    .2byte  0x0152                      /* car+0x152: timer_b effect duration (word) */
