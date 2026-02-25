/* vdp1_display_list_setup -- VDP1 Display List Scale Computation
 * Translation unit: 0x0602C690 - 0x0602C884
 *
 * Step 12 of the per-car render orchestrator (render_orchestrator / 0x0602EEB8).
 * Called after orientation sin/cos, before VDP1 color setup and coord setup.
 *
 * Computes per-car VDP1 display list X and Y scale factors from:
 *   - Activation flag weights (car+0x120..0x12C flag words)
 *   - Car velocity components (car+0x60, car+0x64 negated)
 *   - Current velocity state (car+0x100, car+0x104)
 *   - Speed delta (car+0xFC)
 *   - Heading angle via sin_lookup (car+0x1C, half-angle index)
 *
 * Algorithm:
 *   1. Compute X-axis weight by OR-combining flag words at car+0x120/0x124,
 *      passing through activation_weight_calc to get weighted sum.
 *   2. Compute Y-axis weight similarly from car+0x128/0x12C.
 *   3. Negate velocity components (car+0x60, car+0x64).
 *   4. Load velocity state (car+0x100, car+0x104); zero r9 if sign mismatch.
 *   5. Scale velocity by horizontal factor 0x03700000 (~880.0 FP16.16)
 *      and vertical factor 0x02D00000 (~720.0 FP16.16).
 *   6. Look up sin(heading/2) via sin_lookup table (index from car+0x1C >> 1).
 *   7. Combine sin result, speed delta, and activation weights through
 *      fixed-point multiply chain with normalization constant 0x251B1285.
 *   8. Scale by X-weight (r10) and Y-weight (r11) with factor 0x00028000
 *      (~2.5 FP16.16).
 *   9. Clamp X scale to [0x01600000, 0x0C080000] (~352..3080 FP16.16).
 *  10. Clamp Y scale to [0x01200000, 0x09D80000] (~288..2520 FP16.16).
 *  11. Apply damped smoothing: new = old + (raw - old) >> 2, write back
 *      to car+0x140 (X scale) and car+0x144 (Y scale).
 *
 * Contains two functions:
 *   vdp1_display_list_setup (0x0602C690) -- main scale computation
 *   activation_weight_calc  (0x0602C7FC) -- weighted sum from flag bits
 *
 * activation_weight_calc subroutine:
 *   Scans flag word r4 for up to 6 known bit positions. For each set bit,
 *   clears it from r4, adds the corresponding weight to r8, and increments
 *   count r9. Any remaining bits add a final weight. The count r9 determines
 *   a dispatch path in the next TU (FUN_0602C884) which performs hardware
 *   divide by count and table lookup from sym_06045AEC. Returns weighted
 *   average in r4 (via the next TU's tail code).
 *
 *   r0 = car struct base (preserved)
 *   r3 = car speed index (car+0x08)
 *   r4 = OR'd flag word (input), result scale (output)
 *   r8 = accumulated weight sum
 *   r9 = count of set flag groups
 *
 *   Bit masks and weights (word pool, in next TU's data area):
 *     bit 0x0001 -> weight 0x00EE (238)
 *     bit 0x0004 -> weight 0x00B4 (180)
 *     bit 0x0002 -> weight 0x00D2 (210)
 *     bit 0x0010 -> weight 0x00F6 (246)
 *     bit 0x0020 -> weight 0x00FA (250)
 *     remainder  -> weight 0x0096 (150)
 *
 * NOTE: BSR/BRA kept as mnemonics (TU-internal). External branches (.byte)
 * in activation_weight_calc target FUN_0602C884 (next TU).
 *
 * Input:  r0 = car struct base pointer
 * Output: car+0x140 and car+0x144 updated with smoothed display scales
 */

    .section .text.FUN_0602C690


    .global vdp1_display_list_setup
    .type vdp1_display_list_setup, @function
vdp1_display_list_setup:
    sts.l pr, @-r15                     ! save return address
    mov.w   .L_off_flag_word_a, r1      ! r1 = 0x0120 (offset: flag word A)
    mov.w   .L_off_flag_word_b, r2      ! r2 = 0x0124 (offset: flag word B)
    mov.l @(r0, r1), r3                 ! r3 = car[0x120] (flag word A)
    mov.l @(r0, r2), r4                 ! r4 = car[0x124] (flag word B)
    bsr     .L_activation_weight_calc   ! call activation_weight_calc
    or r3, r4                           ! delay slot: r4 = flagA | flagB (combined flags)
    mov r4, r10                         ! r10 = X-axis activation weight result
    mov.w   .L_off_flag_word_c, r1      ! r1 = 0x0128 (offset: flag word C)
    mov.w   .L_off_flag_word_d, r2      ! r2 = 0x012C (offset: flag word D)
    mov.l @(r0, r1), r3                 ! r3 = car[0x128] (flag word C)
    mov.l @(r0, r2), r4                 ! r4 = car[0x12C] (flag word D)
    bsr     .L_activation_weight_calc   ! call activation_weight_calc
    or r3, r4                           ! delay slot: r4 = flagC | flagD (combined flags)
    mov r4, r11                         ! r11 = Y-axis activation weight result
    mov.w   .L_off_vel_x, r1            ! r1 = 0x0060 (offset: velocity X component)
    mov.w   .L_off_vel_y, r2            ! r2 = 0x0064 (offset: velocity Y component)
    mov.l @(r0, r1), r5                 ! r5 = car[0x60] (velocity X)
    mov.l @(r0, r2), r6                 ! r6 = car[0x64] (velocity Y)
    neg r5, r5                          ! r5 = -velocity_x
    neg r6, r6                          ! r6 = -velocity_y
    mov r0, r14                         ! r14 = car base (preserve across calls)
    mov.w   .L_off_vel_state_x, r1      ! r1 = 0x0100 (offset: velocity state X)
    mov.w   .L_off_vel_state_y, r2      ! r2 = 0x0104 (offset: velocity state Y)
    mov.l @(r0, r1), r9                 ! r9 = car[0x100] (velocity state X)
    mov.l @(r0, r2), r4                 ! r4 = car[0x104] (velocity state Y)
    mov r9, r7                          ! r7 = vel_state_x (copy for sign check)
    xor r5, r7                          ! r7 = vel_state_x XOR (-velocity_x)
    cmp/pz r7                           ! test if signs agree (XOR >= 0)
    bt      .L_signs_agree              ! if same sign, keep r9
    mov #0x0, r9                        ! signs differ: zero vel_state_x
.L_signs_agree:
    mov.l r6, @-r15                     ! push -velocity_y onto stack
    mov.l r5, @-r15                     ! push -velocity_x onto stack
    mov.l   .L_horiz_scale_factor, r5   ! r5 = 0x03700000 (~880.0 FP16.16 horizontal scale)
    mov r4, r7                          ! r7 = vel_state_y (save for later)
    dmuls.l r4, r5                      ! MAC = vel_state_y * horiz_scale
    mov.l   .L_vert_scale_factor, r1    ! r1 = 0x02D00000 (~720.0 FP16.16 vertical scale)
    sts mach, r4                        ! r4 = high 32 bits of product
    sts macl, r8                        ! r8 = low 32 bits of product
    mov #0x0, r13                       ! r13 = 0 (heading_valid flag, 0 = no heading)
    xtrct r4, r8                        ! r8 = mid-32 of 64-bit product (FP16.16 result)
    dmuls.l r7, r1                      ! MAC = vel_state_y * vert_scale
    mov.l @(28, r0), r4                 ! r4 = car[0x1C] (heading angle)
    mov.l   .L_sin_index_range, r5      ! r5 = 0x00000645 (sin table index range: 1605)
    sts mach, r1                        ! r1 = high 32 bits of product
    sts macl, r7                        ! r7 = low 32 bits of product
    mov.l   .L_sin_lookup_ptr, r0       ! r0 = &sin_lookup (trig table address)
    xtrct r1, r7                        ! r7 = FP16.16 vert-scaled result
    cmp/pz r4                           ! test if heading >= 0
    bt      .L_heading_valid            ! if positive, use heading
    mov #0x0, r4                        ! heading negative: zero it out
    mov #0x0, r13                       ! r13 = 0 (mark heading invalid)
.L_heading_valid:
    jsr @r0                             ! call sin_lookup(r4 >> 1)
    shar r4                             ! delay slot: r4 = heading / 2 (half-angle)
    dmuls.l r0, r5                      ! MAC = sin(heading/2) * sin_index_range
    mov.w   .L_off_speed_delta, r1      ! r1 = 0x00FC (offset: clamped speed delta)
    mov.l   .L_normalize_factor, r3     ! r3 = 0x251B1285 (normalization constant)
    sts mach, r5                        ! r5 = high 32 bits
    sts macl, r4                        ! r4 = low 32 bits
    mov r14, r0                         ! r0 = car base (restore from r14)
    xtrct r5, r4                        ! r4 = FP16.16 sin result * range
    tst r13, r13                        ! was heading valid? (r13 != 0 means yes)
    mov r4, r13                         ! r13 = scaled sin value
    mov.l @(r0, r1), r5                 ! r5 = car[0xFC] (clamped speed delta)
    bf      .L_heading_was_invalid      ! if heading was invalid (r13 was 0), branch
    shll r13                            ! r13 = scaled_sin * 2
    add r5, r13                         ! r13 += speed_delta
    bra     .L_compute_scale_products   ! jump to scale computation
    add r4, r5                          ! delay slot: r5 = speed_delta + scaled_sin

    .global DAT_0602c71a
.L_off_flag_word_a:
DAT_0602c71a:
    .2byte  0x0120                      ! offset: activation flag word A

    .global DAT_0602c71c
.L_off_flag_word_b:
DAT_0602c71c:
    .2byte  0x0124                      ! offset: activation flag word B

    .global DAT_0602c71e
.L_off_flag_word_c:
DAT_0602c71e:
    .2byte  0x0128                      ! offset: activation flag word C

    .global DAT_0602c720
.L_off_flag_word_d:
DAT_0602c720:
    .2byte  0x012C                      ! offset: activation flag word D

    .global DAT_0602c722
.L_off_vel_x:
DAT_0602c722:
    .2byte  0x0060                      ! offset: velocity X component

    .global DAT_0602c724
.L_off_vel_y:
DAT_0602c724:
    .2byte  0x0064                      ! offset: velocity Y component

    .global DAT_0602c726
.L_off_vel_state_x:
DAT_0602c726:
    .2byte  0x0100                      ! offset: velocity state X

    .global DAT_0602c728
.L_off_vel_state_y:
DAT_0602c728:
    .2byte  0x0104                      ! offset: velocity state Y

    .global DAT_0602c72a
.L_off_speed_delta:
DAT_0602c72a:
    .2byte  0x00FC                      ! offset: clamped speed delta
.L_horiz_scale_factor:
    .4byte  0x03700000                  ! ~880.0 FP16.16 (horizontal scale factor)
.L_vert_scale_factor:
    .4byte  0x02D00000                  ! ~720.0 FP16.16 (vertical scale factor)
.L_sin_index_range:
    .4byte  0x00000645                  ! 1605 (sin table angular range)
.L_sin_lookup_ptr:
    .4byte  sin_lookup                  ! -> sin lookup table
.L_normalize_factor:
    .4byte  0x251B1285                  ! normalization constant for scale blend
.L_heading_was_invalid:
    neg r13, r13                        ! r13 = -scaled_sin (negate for reverse)
    shll r13                            ! r13 = -scaled_sin * 2
    add r5, r13                         ! r13 += speed_delta
    add r4, r5                          ! r5 = speed_delta + scaled_sin
.L_compute_scale_products:
    dmuls.l r3, r5                      ! MAC = speed_base * normalize_factor
    mov.l @r15+, r5                     ! pop r5 = -velocity_x (from stack)
    sts mach, r4                        ! r4 = high 32 bits
    sts macl, r0                        ! r0 = low 32 bits
    xtrct r4, r0                        ! r0 = FP16.16 normalized speed_base
    dmuls.l r3, r13                     ! MAC = heading_contrib * normalize_factor
    sts mach, r3                        ! r3 = high 32 bits
    sts macl, r13                       ! r13 = low 32 bits
    xtrct r3, r13                       ! r13 = FP16.16 normalized heading_contrib
    mov r9, r4                          ! r4 = vel_state_x (or 0 if sign mismatch)
    dmuls.l r4, r5                      ! MAC = vel_state_x * (-velocity_x)
    sts mach, r4                        ! r4 = high 32 bits
    sts macl, r5                        ! r5 = low 32 bits
    xtrct r4, r5                        ! r5 = FP16.16 x_velocity_product
    add r8, r5                          ! r5 += horiz-scaled vel (from earlier)
    sub r0, r5                          ! r5 -= normalized speed_base
    dmuls.l r10, r5                     ! MAC = x_weight * x_composite
    mov.l   .L_display_scale_norm, r3   ! r3 = 0x00028000 (~2.5 FP16.16 display norm)
    sts mach, r5                        ! r5 = high 32 bits
    sts macl, r4                        ! r4 = low 32 bits
    xtrct r5, r4                        ! r4 = FP16.16 weighted X composite
    dmuls.l r4, r3                      ! MAC = weighted_x * display_norm
    sts mach, r4                        ! r4 = high 32 bits
    sts macl, r10                       ! r10 = low 32 bits
    xtrct r4, r10                       ! r10 = raw X display scale (FP16.16)
    mov.l @r15+, r4                     ! pop r4 = -velocity_y (from stack)
    dmuls.l r4, r9                      ! MAC = (-velocity_y) * vel_state_x
    sts mach, r5                        ! r5 = high 32 bits
    sts macl, r4                        ! r4 = low 32 bits
    xtrct r5, r4                        ! r4 = FP16.16 y_velocity_product
    add r7, r4                          ! r4 += vert-scaled vel (from earlier)
    add r13, r4                         ! r4 += normalized heading_contrib
    dmuls.l r4, r11                     ! MAC = y_composite * y_weight
    mov.l   .L_display_scale_norm, r3   ! r3 = 0x00028000 (~2.5 FP16.16 display norm)
    sts mach, r5                        ! r5 = high 32 bits
    sts macl, r4                        ! r4 = low 32 bits
    xtrct r5, r4                        ! r4 = FP16.16 weighted Y composite
    dmuls.l r4, r3                      ! MAC = weighted_y * display_norm
    sts mach, r4                        ! r4 = high 32 bits
    sts macl, r11                       ! r11 = low 32 bits
    xtrct r4, r11                       ! r11 = raw Y display scale (FP16.16)
    mov.l   .L_x_scale_min, r1          ! r1 = 0x01600000 (~352.0 FP16.16 min X scale)
    mov.l   .L_x_scale_max, r2          ! r2 = 0x0C080000 (~3080.0 FP16.16 max X scale)
    cmp/gt r1, r10                      ! is raw_x > min?
    bt      .L_x_above_min             ! if so, check upper bound
    mov r1, r10                         ! clamp: r10 = min X scale
    bra     .L_x_clamped               ! skip upper check
    nop                                 ! delay slot
.L_display_scale_norm:
    .4byte  0x00028000                  ! ~2.5 FP16.16 (display scale normalization)
.L_x_scale_min:
    .4byte  0x01600000                  ! ~352.0 FP16.16 (minimum X display scale)
.L_x_scale_max:
    .4byte  0x0C080000                  ! ~3080.0 FP16.16 (maximum X display scale)
.L_x_above_min:
    cmp/ge r10, r2                      ! is max >= raw_x? (i.e., raw_x <= max?)
    bt      .L_x_clamped               ! if within range, keep r10
    mov r2, r10                         ! clamp: r10 = max X scale
.L_x_clamped:
    mov.l   .L_y_scale_min, r1          ! r1 = 0x01200000 (~288.0 FP16.16 min Y scale)
    mov.l   .L_y_scale_max, r2          ! r2 = 0x09D80000 (~2520.0 FP16.16 max Y scale)
    cmp/gt r1, r11                      ! is raw_y > min?
    bt      .L_y_above_min             ! if so, check upper bound
    mov r1, r11                         ! clamp: r11 = min Y scale
    bra     .L_y_clamped               ! skip upper check
    nop                                 ! delay slot
.L_y_scale_min:
    .4byte  0x01200000                  ! ~288.0 FP16.16 (minimum Y display scale)
.L_y_scale_max:
    .4byte  0x09D80000                  ! ~2520.0 FP16.16 (maximum Y display scale)
.L_y_above_min:
    cmp/ge r11, r2                      ! is max >= raw_y? (i.e., raw_y <= max?)
    bt      .L_y_clamped               ! if within range, keep r11
    mov r2, r11                         ! clamp: r11 = max Y scale
.L_y_clamped:
    mov r14, r0                         ! r0 = car base (restore)
    mov.w   .L_off_display_scale_x, r1  ! r1 = 0x0140 (offset: display scale X)
    mov.w   .L_off_display_scale_y, r3  ! r3 = 0x0144 (offset: display scale Y)
    mov.l @(r0, r1), r2                 ! r2 = car[0x140] (current X display scale)
    mov.l @(r0, r3), r4                 ! r4 = car[0x144] (current Y display scale)
    sub r2, r10                         ! r10 = raw_x - current_x (delta)
    sub r4, r11                         ! r11 = raw_y - current_y (delta)
    shar r10                            ! r10 = delta_x >> 1
    shar r11                            ! r11 = delta_y >> 1
    shar r10                            ! r10 = delta_x >> 2 (1/4 smoothing)
    shar r11                            ! r11 = delta_y >> 2 (1/4 smoothing)
    add r10, r2                         ! r2 = current_x + delta_x/4 (smoothed X)
    add r11, r4                         ! r4 = current_y + delta_y/4 (smoothed Y)
    mov.l r2, @(r0, r1)                 ! car[0x140] = smoothed X display scale
    lds.l @r15+, pr                     ! restore return address
    rts                                 ! return
    mov.l r4, @(r0, r3)                 ! delay slot: car[0x144] = smoothed Y display scale

    .global DAT_0602c7f8
.L_off_display_scale_x:
DAT_0602c7f8:
    .2byte  0x0140                      ! offset: display scale X (car+0x140)

    .global DAT_0602c7fa
.L_off_display_scale_y:
DAT_0602c7fa:
    .2byte  0x0144                      ! offset: display scale Y (car+0x144)

/* activation_weight_calc -- Weighted sum from activation flag bits
 *
 * Scans the OR'd flag word in r4 for known bit positions. For each
 * set bit, clears it, adds a weight to accumulator r8, and increments
 * count r9. Dispatches to FUN_0602C884 (next TU) based on count for
 * hardware divide and table lookup. Returns weighted average in r4.
 *
 * If car speed index (car+0x08) >= 10, early-exits with r4 = 0x10000
 * (1.0 FP16.16, default scale).
 *
 * Input:  r0 = car base, r4 = OR'd flag word
 * Output: r4 = weighted activation scale (FP16.16)
 */
.L_activation_weight_calc:
    mov.l @(8, r0), r3                  ! r3 = car[0x08] (speed index)
    mov #0xA, r2                        ! r2 = 0xA (threshold: 10)
    mov.l r10, @-r15                    ! save r10 (caller's value)
    cmp/ge r3, r2                       ! is 10 >= speed_index? (i.e., index <= 10)
    .byte   0x8D, 0x69    /* bt/s 0x0602C8DA (external: early exit with 0x10000) */
    mov #0x0, r9                        ! delay slot: r9 = 0 (flag count)
    mov #0x0, r8                        ! r8 = 0 (weight accumulator)
    .byte   0x96, 0x45    /* mov.w .L_wpool_0602C898, r6 (r6 = 0x0001, bit 0 mask) */
    tst r6, r4                          ! test bit 0 in flag word
    not r6, r7                          ! r7 = ~mask (for clearing bit)
    bt/s    .L_test_bit_2              ! if bit not set, skip
    and r7, r4                          ! delay slot: clear bit 0 from r4
    .byte   0x98, 0x41    /* mov.w .L_wpool_0602C89A, r8 (r8 = 0x00EE, weight 238) */
    mov #0x1, r9                        ! r9 = 1 (one flag found)
.L_test_bit_2:
    .byte   0x96, 0x40    /* mov.w .L_wpool_0602C89C, r6 (r6 = 0x0004, bit 2 mask) */
    tst r6, r4                          ! test bit 2 in flag word
    not r6, r7                          ! r7 = ~mask
    bt/s    .L_test_bit_1              ! if bit not set, skip
    and r7, r4                          ! delay slot: clear bit 2 from r4
    .byte   0x96, 0x3C    /* mov.w .L_wpool_0602C89E, r6 (r6 = 0x00B4, weight 180) */
    add r6, r8                          ! r8 += 180
    add #0x1, r9                        ! r9++ (increment count)
.L_test_bit_1:
    .byte   0x96, 0x3A    /* mov.w .L_wpool_0602C8A0, r6 (r6 = 0x0002, bit 1 mask) */
    tst r6, r4                          ! test bit 1 in flag word
    not r6, r7                          ! r7 = ~mask
    bt/s    .L_test_bit_4              ! if bit not set, skip
    and r7, r4                          ! delay slot: clear bit 1 from r4
    .byte   0x96, 0x36    /* mov.w .L_wpool_0602C8A2, r6 (r6 = 0x00D2, weight 210) */
    add r6, r8                          ! r8 += 210
    add #0x1, r9                        ! r9++ (increment count)
.L_test_bit_4:
    .byte   0x96, 0x34    /* mov.w .L_wpool_0602C8A4, r6 (r6 = 0x0010, bit 4 mask) */
    tst r6, r4                          ! test bit 4 in flag word
    not r6, r7                          ! r7 = ~mask
    bt/s    .L_test_bit_5              ! if bit not set, skip
    and r7, r4                          ! delay slot: clear bit 4 from r4
    .byte   0x96, 0x30    /* mov.w .L_wpool_0602C8A6, r6 (r6 = 0x00F6, weight 246) */
    add r6, r8                          ! r8 += 246
    add #0x1, r9                        ! r9++ (increment count)
.L_test_bit_5:
    .byte   0x96, 0x2E    /* mov.w .L_wpool_0602C8A8, r6 (r6 = 0x0020, bit 5 mask) */
    tst r6, r4                          ! test bit 5 in flag word
    not r6, r7                          ! r7 = ~mask
    bt/s    .L_test_remainder          ! if bit not set, skip
    and r7, r4                          ! delay slot: clear bit 5 from r4
    .byte   0x96, 0x2A    /* mov.w .L_wpool_0602C8AA, r6 (r6 = 0x00FA, weight 250) */
    add r6, r8                          ! r8 += 250
    add #0x1, r9                        ! r9++ (increment count)
.L_test_remainder:
    mov #0x0, r6                        ! r6 = 0
    cmp/eq r6, r4                       ! any remaining bits in r4?
    bt      .L_all_bits_tested         ! if r4 == 0, no remainder
    .byte   0x96, 0x25    /* mov.w .L_wpool_0602C8AC, r6 (r6 = 0x0096, weight 150) */
    add r6, r8                          ! r8 += 150 (remainder weight)
    add #0x1, r9                        ! r9++ (increment count)
.L_all_bits_tested:
    tst r9, r9                          ! any flags found at all?
    .byte   0x8D, 0x15    /* bt/s 0x0602C894 (external: no flags, return r4=0) */
    mov #0x0, r4                        ! delay slot: r4 = 0 (default if no flags)
    .byte   0xD2, 0x11    /* mov.l .L_pool_0602C8B0, r2 (r2 = sym_06045AEC, heading table) */
    mov #0x1, r4                        ! r4 = 1
    cmp/eq r4, r9                       ! count == 1?
    .byte   0x89, 0x22    /* bt 0x0602C8B8 (external: 1-flag path, shll2+lookup) */
    shll r4                             ! r4 = 2
    cmp/eq r4, r9                       ! count == 2?
    .byte   0x89, 0x24    /* bt 0x0602C8C2 (external: 2-flag path, shlr+shll2+lookup) */
    shll r4                             ! r4 = 4
    cmp/eq r4, r9                       ! count == 4?
    .byte   0x89, 0x27    /* bt 0x0602C8CE (external: 4-flag path, shlr2+shll2+lookup) */
    mov.l r0, @-r15                     ! save car base (for hw divide path)
    mov r8, r1                          ! r1 = weight sum (dividend for hw divide)
    .byte   0xDC, 0x0C    /* mov.l .L_pool_0602C8B4, r12 (r12 = 0x0602ECCC, hw divide fn) */
