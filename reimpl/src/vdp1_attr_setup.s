/* vdp1_attr_setup -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0602CCEC - 0x0602CDF6
 *
 * VDP1 drawing attribute setup for per-car rendering.
 * Called from vdp1_coord_setup as step 14 of the render orchestrator,
 * after coordinate transformation and before final command list assembly.
 *
 * r14 = car/render state base pointer (set by caller, preserved).
 * r0  = car base pointer (aliased to r14 on entry).
 *
 * vdp1_attr_setup (0x0602CCEC):
 *   Computes depth-based attribute scaling for VDP1 polygon rendering.
 *   Determines how much the car's draw attributes (scale, priority, mesh)
 *   are affected by distance from the camera.
 *
 *   1. Early exit if car+0x08 (frame count / active flag) <= 0.
 *   2. Compute depth ratio: max_speed (0x2134) shifted left 16 minus
 *      drive_speed (car+0xE0), divided by decel_coeff (car+0x11C)
 *      using fpdiv_setup (16.16 fixed-point hardware divide).
 *   3. Multiply depth ratio by intensity (car+0x0144) and by the
 *      product of perspective_scale (car+0x010C) * intensity.
 *   4. Read display flag (car+0x00DC) as scaling index into attr table
 *      (sym_0602E938). Special render types (>= 0xA, == 2, == 3) with
 *      small scaling index skip the table lookup entirely.
 *   5. Table lookup produces a threshold; if depth ratio exceeds it,
 *      call sprite system entry (0x0602D7E4) to configure VDP1 attrs.
 *   6. If render_mode (car+0x016C) <= 0, recompute depth_offset
 *      (car+0x0110) from drive_speed and a large FP constant (0x23280000).
 *   7. Final clamping: perspective_scale minus depth_offset is clamped
 *      to [0x10000, 0x2B85] range. If depth_offset >= 0, subtract 0x05C2.
 *      Store results back to perspective_scale, depth_offset, and car+0x00C0.
 */

    .section .text.FUN_0602CCEC


    .global vdp1_attr_setup
    .type vdp1_attr_setup, @function
vdp1_attr_setup:
    sts.l pr, @-r15              ! save return address
    mov #0x0, r7                 ! r7 = 0 (default draw param / scale index)
    mov.l @(8, r14), r3          ! r3 = car+0x08 (active flag / frame count)
    cmp/pl r3                    ! is car active (> 0)?
    bf      .L_clamp_and_store   ! if not active, skip to final clamping
    mov.w   .L_max_speed_hi, r5  ! r5 = 0x2134 (max speed, high 16 bits)
    mov.w   .L_off_drive_speed, r1 ! r1 = 0xE0 (drive_speed offset)
    shll16 r5                    ! r5 = 0x21340000 (max speed in 16.16 FP)
    mov.l @(r0, r1), r3          ! r3 = car.drive_speed (16.16 FP)
    shll16 r3                    ! r3 = drive_speed << 16 (shift to high word)
    mov r5, r4                   ! r4 = max_speed (numerator for divide)
    sub r3, r4                   ! r4 = max_speed - (drive_speed << 16) = depth numerator
    mov.w   .L_off_decel_coeff, r2 ! r2 = 0x011C (decel_coeff offset)
    mov.l   .L_fpdiv_setup_ptr, r13 ! r13 = &fpdiv_setup (kept for repeated calls)
    jsr @r13                     ! r0 = fpdiv_setup(r4=numerator, r5=denom) -- delay slot loads r6
    mov.l @(r0, r2), r6          ! (delay) r6 = car.decel_coeff (divisor for first fpdiv)
    dmuls.l r0, r6               ! MAC = depth_ratio * decel_coeff (scale result)
    mov.w   .L_off_persp_scale, r1 ! r1 = 0x010C (perspective_scale offset)
    mov.w   .L_off_intensity, r2 ! r2 = 0x0144 (intensity offset)
    sts mach, r0                 ! r0 = MAC high (upper 32 bits of 64-bit product)
    sts macl, r4                 ! r4 = MAC low (lower 32 bits)
    xtrct r0, r4                 ! r4 = middle 32 bits = scaled depth value (16.16 FP)
    add r14, r1                  ! r1 = &car.perspective_scale (absolute addr)
    add r14, r2                  ! r2 = &car.intensity (absolute addr)
    mov.l @r1, r5                ! r5 = car.perspective_scale
    mov.l @r2, r6                ! r6 = car.intensity
    dmuls.l r6, r5               ! MAC = perspective_scale * intensity
    sts mach, r6                 ! r6 = MAC high
    sts macl, r5                 ! r5 = MAC low
    xtrct r6, r5                 ! r5 = perspective_scale * intensity (16.16 FP)
    mov.w   .L_off_display_flag, r1 ! r1 = 0xDC (display_flag offset)
    add r14, r1                  ! r1 = &car.display_flag
    jsr @r13                     ! r0 = fpdiv_setup(r4=scaled_depth, r5=persp*intensity)
    mov.w @r1, r7                ! (delay) r7 = car.display_flag (16-bit, used as table index)
    mov.w   .L_off_render_type, r4 ! r4 = 0x7C (render_type offset)
    mov.l   .L_attr_table_base, r1 ! r1 = attr table base (sym_0602E938)
    add r14, r4                  ! r4 = &car.render_type
    mov.w @r4, r4                ! r4 = car.render_type (16-bit)
    mov #0xA, r5                 ! r5 = 0xA (special render type threshold)
    cmp/ge r5, r4                ! is render_type >= 0xA?
    bt      .L_check_scale_min   ! if so, check minimum scale before skipping table
    mov #0x2, r5                 ! r5 = 0x2
    cmp/eq r5, r4                ! is render_type == 2?
    bt      .L_check_scale_min   ! if type 2, check minimum scale
    add #0x1, r5                 ! r5 = 0x3
    cmp/eq r5, r4                ! is render_type == 3?
    bf      .L_table_lookup      ! if not type 2, 3, or >= 0xA, do normal table lookup
.L_check_scale_min:
    mov #0x2, r5                 ! r5 = 2 (minimum scale index)
    cmp/ge r7, r5                ! is 2 >= display_flag (scale index)?
    bt      .L_clamp_and_store   ! if scale index <= 2, skip attr setup entirely
.L_table_lookup:
    shll2 r4                     ! r4 = render_type * 4
    shll r7                      ! r7 = display_flag * 2 (word index into row)
    shll r4                      ! r4 = render_type * 8 (row stride in table)
    add r1, r7                   ! r7 = &table[0] + display_flag * 2 (column offset)
    add r4, r7                   ! r7 = &table[render_type][display_flag] (final addr)
    mov.w @r7, r4                ! r4 = table entry (16-bit threshold value)
    mov #0x0, r7                 ! r7 = 0 (reset draw param for later store)
    extu.w r4, r4                ! r4 = zero-extend threshold to 32 bits
    mov r0, r5                   ! r5 = depth ratio (result of last fpdiv)
    mov.l r4, @-r15              ! push threshold onto stack
    jsr @r13                     ! r0 = fpdiv_setup(r4=threshold, r5=depth_ratio)
    mov.l r5, @-r15              ! (delay) push depth ratio onto stack
    mov.w   .L_off_attr_result, r1 ! r1 = 0x0264 (attr_result offset)
    add r14, r1                  ! r1 = &car.attr_result
    mov.l r0, @r1                ! car.attr_result = normalized depth/threshold ratio
    mov.l @r15+, r5              ! pop depth ratio
    mov.l @r15+, r4              ! pop threshold
    cmp/gt r5, r4                ! is threshold > depth ratio?
    bt      .L_clamp_and_store   ! if threshold exceeds depth, skip sprite attr config
    .byte   0xB5, 0x35    /* bsr 0x0602D7E4 (external) */  ! call sprite system attr config
    mov r14, r0                  ! (delay) r0 = car base pointer for callee
    mov.w   .L_off_render_mode, r1 ! r1 = 0x016C (render_mode offset)
    add r14, r1                  ! r1 = &car.render_mode
    mov.w @r1, r2                ! r2 = car.render_mode (16-bit)
    cmp/pl r2                    ! is render_mode > 0?
    bt      .L_clamp_and_store   ! if positive, skip depth recalc (mode already active)
    mov.w   .L_off_drive_speed, r1 ! r1 = 0xE0 (drive_speed offset)
    add r14, r1                  ! r1 = &car.drive_speed
    mov.l @r1, r7                ! r7 = car.drive_speed
    mov r7, r4                   ! r4 = drive_speed (numerator for fpdiv)
    mov.l   .L_depth_scale_fp, r5 ! r5 = 0x23280000 (large FP scale constant)
    shll r7                      ! r7 = drive_speed * 2 (for draw_param output)
    shll16 r4                    ! r4 = drive_speed << 16 (shift for FP divide)
    mov.w   .L_off_depth_offset, r6 ! r6 = 0x0110 (depth_offset offset)
    jsr @r13                     ! r0 = fpdiv_setup(r4=drive_speed<<16, r5=depth_scale)
    add r14, r6                  ! (delay) r6 = &car.depth_offset
    mov.l r0, @r6                ! car.depth_offset = drive_speed / depth_scale (16.16 FP)
.L_clamp_and_store:
    mov r14, r0                  ! r0 = car base pointer
    mov.w   .L_off_persp_scale, r1 ! r1 = 0x010C (perspective_scale offset)
    mov.w   .L_off_depth_offset, r2 ! r2 = 0x0110 (depth_offset offset)
    mov.l @(r0, r1), r3          ! r3 = car.perspective_scale
    mov.l @(r0, r2), r4          ! r4 = car.depth_offset
    sub r4, r3                   ! r3 = perspective_scale - depth_offset (net depth)
    mov #0x1, r5                 ! r5 = 1
    mov.w   .L_min_depth_threshold, r6 ! r6 = 0x2B85 (minimum depth threshold)
    shll16 r5                    ! r5 = 0x10000 (1.0 in 16.16 FP = upper clamp)
    cmp/gt r6, r3                ! is net_depth > min_threshold?
    bt      .L_clamp_upper       ! if above minimum, check upper bound
    mov r6, r3                   ! clamp: net_depth = min_threshold (floor)
    bra     .L_apply_depth_offset ! skip upper clamp check
    nop                          ! (delay) nop
.L_max_speed_hi:
    .2byte  0x2134               /* 0x2134 = max drive speed (high 16 bits) */
.L_off_drive_speed:
    .2byte  0x00E0               /* car+0xE0 = drive_speed (longword, 16.16 FP) */
.L_off_decel_coeff:
    .2byte  0x011C               /* car+0x11C = decel_coeff (longword, 16.16 FP) */
.L_off_persp_scale:
    .2byte  0x010C               /* car+0x10C = perspective_scale (longword, 16.16 FP) */
.L_off_intensity:
    .2byte  0x0144               /* car+0x144 = color intensity (longword, 16.16 FP) */
.L_off_display_flag:
    .2byte  0x00DC               /* car+0xDC = display flag (word, table column index) */
.L_off_render_type:
    .2byte  0x007C               /* car+0x7C = render type (word, table row selector) */
.L_off_attr_result:
    .2byte  0x0264               /* car+0x264 = attr_result output (longword) */
.L_off_render_mode:
    .2byte  0x016C               /* car+0x16C = render_mode timer (word) */
.L_off_depth_offset:
    .2byte  0x0110               /* car+0x110 = depth_offset (longword, 16.16 FP) */
.L_min_depth_threshold:
    .2byte  0x2B85               /* 0x2B85 = 11141 (minimum net depth, signed) */
.L_fpdiv_setup_ptr:
    .4byte  fpdiv_setup          /* 16.16 fixed-point hardware divide (r4/r5 -> r0) */
.L_attr_table_base:
    .4byte  sym_0602E938         /* attr threshold table base (rows=type, cols=flag) */
.L_depth_scale_fp:
    .4byte  0x23280000           /* 0x23280000 = large FP denominator for depth calc */
.L_clamp_upper:
    cmp/ge r3, r5                ! is 0x10000 >= net_depth (above upper limit)?
    bt      .L_apply_depth_offset ! if within upper bound, proceed to depth offset
    mov r5, r3                   ! clamp: net_depth = 0x10000 (ceiling)
.L_apply_depth_offset:
    cmp/pz r4                    ! is depth_offset >= 0?
    bf      .L_store_results     ! if negative, skip decay subtraction
    mov.w   .L_depth_decay_step, r5 ! r5 = 0x05C2 (per-frame depth decay amount)
    sub r5, r4                   ! r4 = depth_offset - 0x05C2 (decay toward zero)
    mov.l r4, @(r0, r2)         ! store updated depth_offset back to car+0x0110
.L_store_results:
    mov.l r3, @(r0, r1)         ! store clamped perspective_scale to car+0x010C
    mov.w   .L_off_draw_param, r2 ! r2 = 0xC0 (draw_param offset)
    lds.l @r15+, pr              ! restore return address
    rts                          ! return to caller
    mov.l r7, @(r0, r2)         ! (delay) store draw_param (r7) to car+0x00C0
.L_depth_decay_step:
    .2byte  0x05C2               /* 0x05C2 = 1474 (depth offset decay per frame) */
.L_off_draw_param:
    .2byte  0x00C0               /* car+0xC0 = draw_param output (longword) */
