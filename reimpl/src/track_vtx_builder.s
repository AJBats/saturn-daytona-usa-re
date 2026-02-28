/* track_vtx_builder -- Minimap rotated bounding-box vertex builder
 *
 * Computes 4 rotated corner vertices for a car's minimap icon, producing
 * 2D screen-space coordinates stored into the per-car vertex table at
 * sym_06085490.
 *
 * Algorithm:
 *   1. Select vertex half-extents based on game state (wider in attract mode)
 *   2. Look up the car's heading angle from the slot data table (sym_06084FC8)
 *   3. sincos_pair(angle) -> sin/cos for rotation
 *   4. Loop 4 corners: rotate each extent pair through fpmul to get world-space
 *      X deltas, compute Y deltas similarly with a second sincos pass (the car
 *      heading angle is optionally biased by +0.5 FP when a direction-flip flag
 *      at sym_06078663 is set)
 *   5. Adjust Y deltas via fpdiv_setup / sym_06034FE0 (geometry transform)
 *   6. Final loop: convert world deltas to screen-space 16-bit vertices via
 *      fpmul(delta, scale) passed through swap_sign_ext (>>16 with sign)
 *   7. Write results to the per-car vertex buffer at sym_06085490
 *
 * Input:  r4 = car slot index (0-3)
 * Uses:   fpmul, sincos_pair, fpdiv_setup, swap_sign_ext, sym_06034FE0
 * Output: vertex table entries at sym_06085490 updated for this car
 *
 * Stack frame layout (0xFF74 = -140 bytes):
 *   sp+0x00..0x03: sin output from sincos_pair
 *   sp+0x04..0x07: cos output from sincos_pair
 *   sp+0x08..0x0B: scratch / saved values
 *   sp+0x0C:       car slot index (byte)
 *   sp+0x10..0x17: scratch
 *   sp+0x18..0x1B: saved angle
 *   sp+0x1C..0x23: Y extents array (4 x 16-bit: -h, -h, +h, +h)
 *   sp+0x24..0x2B: X extents array (4 x 16-bit: -w, +w, +w, -w)
 *   sp+0x2C..0x3B: X delta results (4 x 32-bit)
 *   sp+0x3C..0x4B: Z delta results (4 x 32-bit, cleared to 0)
 *   sp+0x4C..0x5B: Y delta results (4 x 32-bit)
 *   sp+0x5C..0x6B: scratch area for second pass
 *   sp+0x6C..0x7B: scratch area for corner Z values
 *   sp+0x7C..0x8B: X result output (4 x 32-bit)
 *
 * Translation unit: 0x06016DD8 - 0x060170FC
 */

    .section .text.FUN_06016DD8


    .global track_vtx_builder
    .type track_vtx_builder, @function
track_vtx_builder:
    mov.l r14, @-r15                   ! save r14 (callee-saved)
    mov.l r13, @-r15                   ! save r13
    mov.l r12, @-r15                   ! save r12
    mov #0x4, r13                      ! r13 = 4 (corner count / loop limit)
    mov.l r11, @-r15                   ! save r11
    mov.l r10, @-r15                   ! save r10
    mov.l r9, @-r15                    ! save r9
    mov.l r8, @-r15                    ! save r8
    sts.l pr, @-r15                    ! save return address
    mov.w   .L_wpool_frame_size_neg, r0 ! r0 = 0xFF74 (-140) — stack frame size
    add r0, r15                        ! allocate 140-byte stack frame
    mov r15, r8                        ! r8 = frame base (will become Y extents ptr)
    mov r15, r9                        ! r9 = frame base (will become Y deltas ptr)
    mov r15, r10                       ! r10 = frame base (will become Z deltas ptr)
    mov.l   .L_pool_fn_fpmul, r14     ! r14 = &fpmul (cached for repeated jsr)
    mov r4, r0                         ! r0 = car slot index (arg0)
    add #0x1C, r8                      ! r8 = &frame[0x1C] — Y extents array base
    add #0x4C, r9                      ! r9 = &frame[0x4C] — Y deltas array base
    add #0x3C, r10                     ! r10 = &frame[0x3C] — Z deltas array base
    mov #0x10, r4                      ! r4 = 0x10 (default X half-extent = 16)
    mov.b r0, @(12, r15)              ! frame[0x0C] = car slot index (byte)
    mov.l   .L_pool_game_state, r0    ! r0 = &game_state (g_game_state)
    mov.l @r0, r0                      ! r0 = current game state value
    cmp/eq #0x15, r0                   ! is game state == 0x15 (attract mode)?
    bf/s    .L_extents_ready           ! if not attract: keep defaults, branch
    mov #0xC, r5                       ! r5 = 0x0C (default Y half-extent = 12) [delay]
    mov #0x20, r4                      ! attract mode: X half-extent = 32 (wider)
    mov #0x18, r5                      ! attract mode: Y half-extent = 24 (taller)
.L_extents_ready:
    ! --- Store X extents: [-w, +w, +w, -w] at frame[0x24..0x2B] ---
    exts.w r4, r2                      ! r2 = X half-extent (sign-extended to 32-bit)
    neg r2, r2                         ! r2 = -X half-extent
    exts.w r2, r2                      ! r2 = -w (sign-extended 16-bit)
    mov #0x24, r0                      ! r0 = offset 0x24 into frame
    mov.w r2, @(r0, r15)              ! frame[0x24] = -w (corner 0 X extent)
    mov #0x26, r0                      ! r0 = offset 0x26
    mov.w r4, @(r0, r15)              ! frame[0x26] = +w (corner 1 X extent)
    mov #0x28, r0                      ! r0 = offset 0x28
    mov.w r4, @(r0, r15)              ! frame[0x28] = +w (corner 2 X extent)
    exts.w r4, r4                      ! r4 = +w (sign-extended)
    neg r4, r4                         ! r4 = -w
    exts.w r4, r4                      ! r4 = -w (sign-extended 16-bit)
    mov #0x2A, r0                      ! r0 = offset 0x2A
    mov.w r4, @(r0, r15)              ! frame[0x2A] = -w (corner 3 X extent)
    ! --- Store Y extents: [-h, -h, +h, +h] at frame[0x1C..0x23] ---
    exts.w r5, r3                      ! r3 = Y half-extent (sign-extended)
    neg r3, r3                         ! r3 = -h
    mov.w r3, @r8                      ! frame[0x1C] = -h (corner 0 Y extent)
    exts.w r5, r2                      ! r2 = +h (sign-extended)
    neg r2, r2                         ! r2 = -h
    exts.w r2, r0                      ! r0 = -h (sign-extended 16-bit)
    mov.w r0, @(2, r8)                ! frame[0x1E] = -h (corner 1 Y extent)
    mov r5, r0                         ! r0 = +h
    mov.w r0, @(4, r8)                ! frame[0x20] = +h (corner 2 Y extent)
    mov.w r0, @(6, r8)                ! frame[0x22] = +h (corner 3 Y extent)
    ! --- Compute sin/cos of car heading angle ---
    mov r15, r6                        ! r6 = frame base
    add #0x4, r6                       ! r6 = &frame[0x04] — cos output ptr
    mov r15, r5                        ! r5 = &frame[0x00] — sin output ptr
    mov.b @(12, r15), r0              ! r0 = car slot index
    mov r0, r4                         ! r4 = slot index
    extu.b r4, r4                      ! r4 = slot index (zero-extended byte)
    mov r4, r3                         ! r3 = slot index copy
    shll2 r4                           ! r4 = slot * 4
    shll2 r3                           ! r3 = slot * 4
    mov.l   .L_pool_slot_data_base, r2 ! r2 = slot data table base (sym_06084FC8)
    shll2 r3                           ! r3 = slot * 16
    shll2 r3                           ! r3 = slot * 64 (not used directly — overflow index calc)
    add r3, r4                         ! r4 = slot * 4 + slot * 64 = slot * 68 (but sign-extended below)
    exts.w r4, r4                      ! r4 = slot_offset (sign-extended to 32-bit)
    mov.l   .L_pool_fn_sincos, r3     ! r3 = &sincos_pair
    add r2, r4                         ! r4 = &slot_data[slot] (base + offset)
    jsr @r3                            ! sincos_pair(angle, &sin, &cos)
    mov.l @(48, r4), r4               ! r4 = slot_data[slot].angle (+48) [delay slot]
    ! --- Loop 1: Compute rotated X and Y deltas for 4 corners ---
    mov #0x0, r12                      ! r12 = corner index = 0
.L_corner_loop_top:
    extu.b r12, r11                    ! r11 = corner index (zero-extended)
    mov r15, r3                        ! r3 = frame base
    extu.b r12, r4                     ! r4 = corner index
    shll2 r11                          ! r11 = corner * 4 (32-bit offset)
    add #0x7C, r3                      ! r3 = &frame[0x7C] — X result array base
    shll r4                            ! r4 = corner * 2 (16-bit offset into extents)
    add r11, r3                        ! r3 = &x_result[corner]
    mov.l r3, @-r15                    ! push &x_result[corner] onto stack
    mov r15, r3                        ! r3 = adjusted sp
    mov.l @(8, r15), r5               ! r5 = sin value (from frame[0x00], adjusted for push)
    add #0x28, r3                      ! r3 = &frame[0x24] (X extents base, adjusted)
    mov.l r4, @(12, r15)              ! save corner*2 for Y extent lookup later
    add r3, r4                         ! r4 = &x_extent[corner] (X extent for this corner)
    mov.l r4, @(20, r15)              ! save &x_extent[corner]
    mov.w @r4, r4                      ! r4 = x_extent[corner] (16-bit)
    jsr @r14                           ! fpmul(x_extent << 16, sin)
    shll16 r4                          ! r4 = x_extent << 16 (convert to 16.16 FP) [delay]
    mov.l r0, @-r15                    ! push fpmul result (x_extent * sin)
    mov.l @(8, r15), r5               ! r5 = sin value again
    mov.l @(16, r15), r4              ! r4 = corner*2 (saved earlier)
    add r8, r4                         ! r4 = &y_extent[corner] (Y extents at r8)
    mov.l r4, @(28, r15)              ! save &y_extent[corner]
    mov.w @r4, r4                      ! r4 = y_extent[corner] (16-bit)
    jsr @r14                           ! fpmul(y_extent << 16, sin)
    shll16 r4                          ! r4 = y_extent << 16 (16.16 FP) [delay]
    mov.l @r15+, r3                    ! pop x_extent * sin
    add r3, r0                         ! r0 = x_extent*sin + y_extent*sin = X delta
    mov.l @r15+, r2                    ! pop &x_result[corner]
    mov.l r0, @r2                      ! x_result[corner] = X delta
    ! --- Compute Y delta for this corner (using cos) ---
    mov r15, r3                        ! r3 = frame base
    add #0x6C, r3                      ! r3 = &frame[0x6C] — Z scratch area base
    add r11, r3                        ! r3 = &z_scratch[corner]
    mov.l r3, @-r15                    ! push &z_scratch[corner]
    mov.l @(8, r15), r5               ! r5 = cos value (from frame[0x04], adjusted)
    mov.l @(24, r15), r4              ! r4 = &x_extent[corner] (saved earlier)
    mov.w @r4, r4                      ! r4 = x_extent[corner] (16-bit)
    jsr @r14                           ! fpmul(x_extent << 16, cos)
    shll16 r4                          ! r4 = x_extent << 16 [delay]
    mov.l r0, @-r15                    ! push x_extent * cos
    mov.l @(8, r15), r5               ! r5 = cos value again
    mov.l @(24, r15), r4              ! r4 = &y_extent[corner]
    mov.w @r4, r4                      ! r4 = y_extent[corner] (16-bit)
    jsr @r14                           ! fpmul(y_extent << 16, cos)
    shll16 r4                          ! r4 = y_extent << 16 [delay]
    add #0x1, r12                      ! corner_index++
    mov.l @r15+, r3                    ! pop x_extent * cos
    sub r0, r3                         ! r3 = x_extent*cos - y_extent*cos = Y delta
    mov.l @r15+, r2                    ! pop &z_scratch[corner]
    mov.l r3, @r2                      ! z_scratch[corner] = Y delta
    ! --- Clear Z delta for this corner ---
    mov r15, r3                        ! r3 = frame base
    mov #0x0, r2                       ! r2 = 0
    add #0x5C, r3                      ! r3 = &frame[0x5C] — Z clear area
    add r3, r11                        ! r11 = &z_clear[corner]
    mov.l r2, @r11                     ! z_clear[corner] = 0 (no Z delta)
    extu.b r12, r3                     ! r3 = corner_index (zero-extended)
    cmp/ge r13, r3                     ! corner_index >= 4?
    bra     .L_corner_loop_check       ! branch to loop check (past literal pool)
    nop                                ! (delay slot)
.L_wpool_frame_size_neg:
    .2byte  0xFF74                     /* -140: stack frame allocation size */
.L_pool_fn_fpmul:
    .4byte  fpmul                      /* 16.16 fixed-point multiply */
.L_pool_game_state:
    .4byte  g_game_state               /* game state variable (0-31) */
.L_pool_slot_data_base:
    .4byte  sym_06084FC8               /* per-car slot data array base */
.L_pool_fn_sincos:
    .4byte  sincos_pair                /* sincos_pair(angle, &sin, &cos) */
.L_corner_loop_check:
    bf      .L_corner_loop_top         ! if corner_index < 4: loop again
    ! === Phase 2: Save original angle, optionally bias, compute second sincos ===
    mov.b @(12, r15), r0              ! r0 = car slot index
    mov.l   .L_pool_slot_data_base_b, r1 ! r1 = slot data table base
    mov r0, r3                         ! r3 = slot index
    extu.b r3, r3                      ! r3 = slot index (byte)
    mov r3, r2                         ! r2 = slot index copy
    shll2 r3                           ! r3 = slot * 4
    shll2 r2                           ! r2 = slot * 4
    shll2 r2                           ! r2 = slot * 16
    shll2 r2                           ! r2 = slot * 64
    add r2, r3                         ! r3 = slot * 68 (struct stride)
    exts.w r3, r3                      ! r3 = slot_offset (sign-extended)
    add r1, r3                         ! r3 = &slot_data[slot]
    mov.l @(44, r3), r2               ! r2 = slot_data[slot].angle (+44) — save original
    mov.l r2, @(24, r15)              ! frame[0x18] = saved original angle
    mov.l   .L_pool_dir_flip_flag, r0 ! r0 = &direction_flip_flag (sym_06078663)
    mov.b @r0, r0                      ! r0 = direction flip flag (byte)
    tst r0, r0                         ! is flip flag zero?
    bt      .L_no_angle_bias           ! if zero: skip angle bias
    ! --- Bias angle by +0.5 (16.16 FP) for reversed direction ---
    mov.b @(12, r15), r0              ! r0 = car slot index
    mov r0, r3                         ! r3 = slot index
    extu.b r3, r3                      ! r3 = slot index (byte)
    mov r3, r2                         ! r2 = slot index copy
    shll2 r3                           ! r3 = slot * 4
    shll2 r2                           ! r2 = slot * 4
    shll2 r2                           ! r2 = slot * 16
    shll2 r2                           ! r2 = slot * 64
    add r2, r3                         ! r3 = slot * 68
    exts.w r3, r3                      ! r3 = slot_offset (sign-extended)
    mov.l   .L_pool_slot_data_base_b, r1 ! r1 = slot data table base
    add r1, r3                         ! r3 = &slot_data[slot]
    mov.l   .L_fp_half, r2            ! r2 = 0x00008000 (0.5 in 16.16 FP)
    mov.l @(44, r3), r1               ! r1 = slot_data[slot].angle
    add r2, r1                         ! r1 = angle + 0.5 (biased heading)
    mov.l r1, @(44, r3)               ! slot_data[slot].angle = biased angle (temporary)
.L_no_angle_bias:
    ! --- Second sincos_pair call with (possibly biased) angle ---
    mov r15, r6                        ! r6 = frame base
    mov r15, r5                        ! r5 = &frame[0x00] — sin output ptr
    mov.b @(12, r15), r0              ! r0 = car slot index
    mov.l   .L_pool_slot_data_base_b, r2 ! r2 = slot data table base
    add #0x4, r6                       ! r6 = &frame[0x04] — cos output ptr
    mov r0, r4                         ! r4 = slot index
    extu.b r4, r4                      ! r4 = slot index (byte)
    mov r4, r3                         ! r3 = slot index copy
    shll2 r4                           ! r4 = slot * 4
    shll2 r3                           ! r3 = slot * 4
    shll2 r3                           ! r3 = slot * 16
    shll2 r3                           ! r3 = slot * 64
    add r3, r4                         ! r4 = slot * 68
    exts.w r4, r4                      ! r4 = slot_offset (sign-extended)
    mov.l   .L_pool_fn_sincos_b, r3   ! r3 = &sincos_pair
    add r2, r4                         ! r4 = &slot_data[slot]
    jsr @r3                            ! sincos_pair(biased_angle, &sin, &cos)
    mov.l @(44, r4), r4               ! r4 = slot_data[slot].angle (+44) [delay]
    ! === Phase 3: Compute Y deltas using second sincos values ===
    mov #0x0, r11                      ! r11 = corner index = 0
.L_y_delta_loop_top:
    extu.b r11, r12                    ! r12 = corner index (zero-extended)
    mov r15, r3                        ! r3 = frame base
    shll2 r12                          ! r12 = corner * 4 (32-bit offset)
    add #0x2C, r3                      ! r3 = &frame[0x2C] — X delta array base
    add r12, r3                        ! r3 = &x_delta[corner]
    mov.l r3, @(8, r15)               ! save &x_delta[corner] at frame[0x08]
    mov.l r3, @-r15                    ! push &x_delta[corner]
    mov.l @(4, r15), r5               ! r5 = sin value (from frame[0x00], adjusted)
    mov.w   DAT_06016ffa, r4          ! r4 = 0x0080 (offset to X result area on stack)
    add r15, r4                        ! r4 = sp + 0x80
    add r12, r4                        ! r4 = &x_result[corner] (stack-relative)
    mov.l r4, @(24, r15)              ! save &x_result[corner]
    jsr @r14                           ! fpmul(x_result[corner], sin)
    mov.l @r4, r4                      ! r4 = x_result[corner] value [delay]
    mov.l r0, @-r15                    ! push fpmul result (x_result * sin)
    mov r15, r4                        ! r4 = adjusted sp
    mov.l @(12, r15), r5              ! r5 = cos value (from frame[0x04], adjusted)
    add #0x64, r4                      ! r4 = sp + 0x64
    add r12, r4                        ! r4 = &z_scratch[corner] (stack-relative)
    mov.l r4, @(24, r15)              ! save &z_scratch[corner]
    jsr @r14                           ! fpmul(z_scratch[corner], cos)
    mov.l @r4, r4                      ! r4 = z_scratch[corner] value [delay]
    mov.l @r15+, r3                    ! pop x_result * sin
    add r3, r0                         ! r0 = x_result*sin + z_scratch*cos
    mov.l @r15+, r2                    ! pop &x_delta[corner]
    mov r12, r3                        ! r3 = corner * 4
    mov.l r0, @r2                      ! x_delta[corner] = combined X delta
    add r9, r3                         ! r3 = &y_delta[corner] (r9 + corner*4)
    mov.l r3, @-r15                    ! push &y_delta[corner]
    mov.l @(8, r15), r5               ! r5 = sin value
    mov.l @(24, r15), r4              ! r4 = &z_scratch[corner]
    jsr @r14                           ! fpmul(z_scratch[corner], sin)
    mov.l @r4, r4                      ! r4 = z_scratch[corner] value [delay]
    mov.l r0, @-r15                    ! push z_scratch * sin
    mov.l @(8, r15), r5               ! r5 = cos value
    mov.l @(24, r15), r4              ! r4 = &x_result[corner]
    jsr @r14                           ! fpmul(x_result[corner], cos)
    mov.l @r4, r4                      ! r4 = x_result[corner] value [delay]
    mov.l @r15+, r3                    ! pop z_scratch * sin
    sub r0, r3                         ! r3 = z_scratch*sin - x_result*cos = Y delta
    mov.l @r15+, r2                    ! pop &y_delta[corner]
    mov.l r3, @r2                      ! y_delta[corner] = Y delta
    ! --- Copy Z delta from first pass ---
    mov r12, r3                        ! r3 = corner * 4
    mov r15, r2                        ! r2 = frame base
    add r10, r3                        ! r3 = &z_delta[corner] (r10 + corner*4)
    add #0x6C, r2                      ! r2 = &frame[0x6C] — Z scratch from pass 1
    add r12, r2                        ! r2 = &z_scratch_pass1[corner]
    mov.l @r2, r1                      ! r1 = z_scratch_pass1[corner]
    mov.l r1, @r3                      ! z_delta[corner] = z_scratch value from pass 1
    ! --- Check if x_delta[corner] is non-zero for Y adjustment ---
    mov.l @(8, r15), r3               ! r3 = &x_delta[corner] (saved earlier)
    mov.l @r3, r0                      ! r0 = x_delta[corner]
    tst r0, r0                         ! is x_delta zero?
    bt      .L_y_delta_next            ! if zero: skip Y adjustment (avoid div by zero)
    ! --- Adjust Y delta via division and geometry transform ---
    extu.b r11, r12                    ! r12 = corner index (byte)
    shll2 r12                          ! r12 = corner * 4
    mov r12, r3                        ! r3 = corner * 4
    add r9, r3                         ! r3 = &y_delta[corner]
    mov.l r3, @(20, r15)              ! save &y_delta[corner]
    mov.l r3, @-r15                    ! push &y_delta[corner]
    mov.l @r3, r2                      ! r2 = y_delta[corner] value
    mov r15, r5                        ! r5 = adjusted sp
    mov.l r2, @(12, r15)              ! save y_delta value
    add #0x30, r5                      ! r5 = sp + 0x30
    add r12, r5                        ! r5 = &x_delta_pass2[corner] (adjusted stack)
    mov.l r5, @(20, r15)              ! save &x_delta_pass2[corner]
    mov.l @(12, r15), r4              ! r4 = y_delta[corner] (dividend)
    mov.l   .L_pool_fn_fpdiv, r2     ! r2 = &fpdiv_setup
    jsr @r2                            ! fpdiv_setup(y_delta, x_delta_pass2)
    mov.l @r5, r5                      ! r5 = x_delta_pass2[corner] (divisor) [delay]
    mov.l @(12, r15), r3              ! r3 = original y_delta value
    add r3, r0                         ! r0 = quotient + y_delta (adjusted result)
    mov.l @r15+, r3                    ! pop &y_delta[corner]
    mov.l r0, @r3                      ! y_delta[corner] = adjusted value
    ! --- Apply geometry transform to Z delta ---
    add r10, r12                       ! r12 = &z_delta[corner] (r10 + corner*4)
    mov.l r12, @(20, r15)             ! save &z_delta[corner]
    mov r12, r3                        ! r3 = &z_delta[corner]
    mov.l @r3, r2                      ! r2 = z_delta[corner] value
    mov.l r2, @(8, r15)               ! save z_delta value
    mov.l @(16, r15), r5              ! r5 = x_delta_pass2 ptr (saved)
    bra     .L_adjust_y_delta          ! jump to Y delta adjustment code
    nop                                ! (delay slot)

    .global DAT_06016ffa
DAT_06016ffa:
    .2byte  0x0080                     /* 128: stack offset to X result area */
.L_pool_slot_data_base_b:
    .4byte  sym_06084FC8               /* per-car slot data array base (dup) */
.L_pool_dir_flip_flag:
    .4byte  sym_06078663               /* direction flip flag (byte) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_fn_sincos_b:
    .4byte  sincos_pair                /* sincos_pair (dup pool entry) */
.L_pool_fn_fpdiv:
    .4byte  fpdiv_setup                /* 16.16 fixed-point divide */
.L_adjust_y_delta:
    mov.l @r5, r5                      ! r5 = divisor value (deref ptr)
    mov.l   .L_pool_fn_fpdiv_c, r3   ! r3 = &fpdiv_setup
    jsr @r3                            ! fpdiv_setup(z_delta, divisor)
    mov r2, r4                         ! r4 = z_delta value (dividend) [delay]
    mov r0, r1                         ! r1 = quotient result
    mov.l   .L_pool_fn_geom_xform, r2 ! r2 = &geometry_transform (sym_06034FE0)
    jsr @r2                            ! geometry_transform(quotient, 6)
    mov #0x6, r0                       ! r0 = 6 (shift/scale parameter) [delay]
    mov.l @(8, r15), r3               ! r3 = saved z_delta value
    sub r0, r3                         ! r3 = z_delta - transform_result
    mov.l r3, @r12                     ! z_delta[corner] = adjusted z_delta
.L_y_delta_next:
    add #0x1, r11                      ! corner_index++
    extu.b r11, r3                     ! r3 = corner_index (byte)
    cmp/ge r13, r3                     ! corner_index >= 4?
    bf      .L_y_delta_loop_top        ! if not: loop again
    ! === Phase 4: Restore original angle to slot data ===
    mov.b @(12, r15), r0              ! r0 = car slot index
    mov.l   .L_pool_slot_data_base_c, r1 ! r1 = slot data table base
    mov r0, r3                         ! r3 = slot index
    extu.b r3, r3                      ! r3 = slot index (byte)
    mov r3, r2                         ! r2 = slot index copy
    shll2 r3                           ! r3 = slot * 4
    shll2 r2                           ! r2 = slot * 4
    shll2 r2                           ! r2 = slot * 16
    shll2 r2                           ! r2 = slot * 64
    add r2, r3                         ! r3 = slot * 68
    exts.w r3, r3                      ! r3 = slot_offset (sign-extended)
    mov.l @(24, r15), r2              ! r2 = saved original angle (from frame[0x18])
    add r1, r3                         ! r3 = &slot_data[slot]
    mov.l r2, @(44, r3)               ! slot_data[slot].angle = original angle (restored)
    ! === Phase 5: Compute output vertex table pointer ===
    mov.b @(12, r15), r0              ! r0 = car slot index
    mov r0, r3                         ! r3 = slot index
    extu.b r3, r3                      ! r3 = slot index (byte)
    mov r3, r2                         ! r2 = slot index copy
    shll2 r3                           ! r3 = slot * 4
    shll r3                            ! r3 = slot * 8
    shll2 r2                           ! r2 = slot * 4
    shll2 r2                           ! r2 = slot * 16
    add r2, r3                         ! r3 = slot * 8 + slot * 16 = slot * 24
    exts.w r3, r3                      ! r3 = vtx_offset (sign-extended)
    mov.l   .L_pool_vtx_table_base, r1 ! r1 = vertex table base (sym_06085490)
    add r1, r3                         ! r3 = &vtx_table[slot]
    add #0x8, r3                       ! r3 = &vtx_table[slot] + 8 (skip header)
    mov.l r3, @(16, r15)              ! save output vertex ptr at frame[0x10]
    ! --- Compute slot data pointer for scale factors ---
    mov #0x0, r11                      ! r11 = corner index = 0
    mov.b @(12, r15), r0              ! r0 = car slot index
    mov r0, r12                        ! r12 = slot index
    extu.b r12, r12                    ! r12 = slot index (byte)
    mov r12, r2                        ! r2 = slot index copy
    shll2 r12                          ! r12 = slot * 4
    shll2 r2                           ! r2 = slot * 4
    shll2 r2                           ! r2 = slot * 16
    shll2 r2                           ! r2 = slot * 64
    add r2, r12                        ! r12 = slot * 68
    exts.w r12, r12                    ! r12 = slot_offset (sign-extended)
    mov.l   .L_pool_slot_data_base_c, r1 ! r1 = slot data table base
    add r1, r12                        ! r12 = &slot_data[slot] (cached for loop)
    ! === Phase 6: Convert deltas to screen-space vertex coordinates ===
.L_screen_vtx_loop_top:
    extu.b r11, r3                     ! r3 = corner index (byte)
    extu.b r11, r0                     ! r0 = corner index (byte)
    mov.l @(16, r15), r2              ! r2 = output vertex ptr
    shll r3                            ! r3 = corner * 2
    shll2 r0                           ! r0 = corner * 4 (32-bit index into deltas)
    shll r3                            ! r3 = corner * 4 (stride into output: 4 bytes per vtx)
    add r2, r3                         ! r3 = &out_vtx[corner] (output ptr)
    mov.l r3, @(12, r15)              ! save &out_vtx[corner]
    mov.l r3, @-r15                    ! push &out_vtx[corner]
    mov.l @(12, r12), r5              ! r5 = slot_data[slot].scale (+12)
    mov.l r0, @(12, r15)              ! save corner*4 (delta array index)
    jsr @r14                           ! fpmul(x_delta[corner], scale)
    mov.l @(r0, r9), r4               ! r4 = y_delta[corner] (r9 + corner*4) [delay]
    mov.l @(4, r12), r4               ! r4 = slot_data[slot].x_offset (+4)
    mov.l   .L_pool_fn_swap_sign_ext, r3 ! r3 = &swap_sign_ext
    jsr @r3                            ! swap_sign_ext(x_offset + fpmul_result)
    add r0, r4                         ! r4 = x_offset + scaled_delta [delay]
    exts.w r0, r0                      ! r0 = screen X (sign-extended 16-bit)
    mov.l @r15+, r2                    ! pop &out_vtx[corner]
    mov.w r0, @r2                      ! out_vtx[corner].x = screen X coordinate
    ! --- Compute screen Y coordinate ---
    mov.l @(12, r15), r3              ! r3 = corner*4 (saved delta index)
    add #0x2, r3                       ! r3 = output offset + 2 (Y field)
    mov.l r3, @-r15                    ! push &out_vtx[corner].y
    mov.l @(12, r12), r5              ! r5 = slot_data[slot].scale (+12)
    mov.l @(12, r15), r4              ! r4 = corner*4
    add r10, r4                        ! r4 = &z_delta[corner] (r10 + corner*4)
    jsr @r14                           ! fpmul(z_delta[corner], scale)
    mov.l @r4, r4                      ! r4 = z_delta[corner] value [delay]
    mov.l @(8, r12), r4               ! r4 = slot_data[slot].y_offset (+8)
    mov.l   .L_pool_fn_swap_sign_ext, r3 ! r3 = &swap_sign_ext
    jsr @r3                            ! swap_sign_ext(y_offset + fpmul_result)
    add r0, r4                         ! r4 = y_offset + scaled_delta [delay]
    exts.w r0, r0                      ! r0 = screen Y (sign-extended 16-bit)
    add #0x1, r11                      ! corner_index++
    mov.l @r15+, r2                    ! pop &out_vtx[corner].y
    extu.b r11, r3                     ! r3 = corner_index (byte)
    mov.w r0, @r2                      ! out_vtx[corner].y = screen Y coordinate
    cmp/ge r13, r3                     ! corner_index >= 4?
    bf      .L_screen_vtx_loop_top     ! if not: loop again
    ! === Epilogue: deallocate frame and restore registers ===
    mov.w   .L_wpool_frame_size_pos, r1 ! r1 = 0x008C (+140) — frame dealloc size
    add r1, r15                        ! deallocate stack frame
    lds.l @r15+, pr                    ! restore return address
    mov.l @r15+, r8                    ! restore r8
    mov.l @r15+, r9                    ! restore r9
    mov.l @r15+, r10                   ! restore r10
    mov.l @r15+, r11                   ! restore r11
    mov.l @r15+, r12                   ! restore r12
    mov.l @r15+, r13                   ! restore r13
    rts                                ! return to caller
    mov.l @r15+, r14                   ! restore r14 [delay slot]
.L_wpool_frame_size_pos:
    .2byte  0x008C                     /* +140: stack frame deallocation size */
    .2byte  0xFFFF                     /* padding to 4-byte alignment */
.L_pool_fn_fpdiv_c:
    .4byte  fpdiv_setup                /* 16.16 fixed-point divide (dup) */
.L_pool_fn_geom_xform:
    .4byte  sym_06034FE0               /* geometry transform helper */
.L_pool_slot_data_base_c:
    .4byte  sym_06084FC8               /* per-car slot data array base (dup) */
.L_pool_vtx_table_base:
    .4byte  sym_06085490               /* per-car vertex output table */
.L_pool_fn_swap_sign_ext:
    .4byte  swap_sign_ext              /* swap.w + exts.w (>>16 with sign) */
