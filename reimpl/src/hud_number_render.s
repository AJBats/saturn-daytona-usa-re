/* hud_number_render -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0603101E - 0x0603137A
 *
 * Car-to-car angular collision response and steering correction.
 *
 * Despite the filename (inherited from TU grouping), this function handles
 * inter-car physics, not HUD rendering. It computes the angular difference
 * between two cars (via atan2), determines whether they are approaching
 * head-on or from the side, and applies corrective forces:
 *
 *   1. Call atan2 to get angle between the two cars
 *   2. Compare each car's heading against the car-to-car angle
 *   3. If headings diverge (one approaching, one retreating), set conflict flag
 *   4. Use sin_lookup to decompose the angle into components
 *   5. Check heading difference thresholds (90 deg = 0x4000, 270 deg = 3*0x4000)
 *      - Large difference: call force_steer_impact to apply collision steering
 *      - Small difference: apply direct steering flag (0x20000000 = force bit)
 *   6. Check lateral proximity; if close, interpolate positions via cos/sin
 *   7. Apply position corrections to both car structs (r14 = car A, r13 = car B)
 *
 * Car struct offsets used:
 *   @(0, rN)   — flags/status word
 *   @(12, rN)  — forward velocity or heading rate (16.16 fixed-point)
 *   @(16, rN)  — X position (16.16 fixed-point)
 *   @(24, rN)  — Z position (16.16 fixed-point)
 *   @(40, rN)  — lateral offset / side position
 *   @(48, rN)  — heading angle (16-bit, 0x0000-0xFFFF = full circle)
 *   @(56, rN)  — saved X position (backup for interpolation)
 *   @(60, rN)  — saved Z position (backup for interpolation)
 *
 * Subroutine at end: check_reverse_direction — sets sym_06031A24 flag if
 * car heading is in the 90-270 degree rear arc (moving backwards on track).
 *
 * External calls: atan2, sin_lookup, cos_lookup, force_steer_impact
 * External data:  sym_0605BCC8 (collision force table),
 *                 sym_0602FD98/sym_0602FD9A (timing/state bytes),
 *                 sym_06031A24 (reverse-direction flag)
 */

    .section .text.FUN_0603101E


    .global hud_number_render
    .type hud_number_render, @function
hud_number_render:
    sts.l pr, @-r15              ! save PR (atan2 clobbers it)
    jsr @r0                      ! call atan2(delta_x, delta_z)
    nop
    lds.l @r15+, pr              ! restore PR
    neg r0, r11                  ! r11 = -atan2_result (negate angle)
    exts.w r11, r11              ! sign-extend to 32-bit
    mov.l @r15+, r0              ! restore caller's r0
    mov #0x0, r9                 ! r9 = conflict_flag (0 = no conflict)
    mov.w   DAT_060310b8, r4     ! r4 = 0x8000 (half circle)
    mov.l @(48, r14), r1         ! r1 = car_A.heading
    extu.w r4, r4                ! zero-extend half_circle
    mov #0x1, r7                 ! r7 = heading_a_match (assume match)
    mov r4, r3                   ! r3 = half_circle
    extu.w r11, r6               ! r6 = negated angle (unsigned)
    shll r3                      ! r3 = full_circle (0x10000)
    or r3, r6                    ! r6 = full_circle | angle
    sub r6, r1                   ! r1 = heading_A - (full_circle | angle)
    cmp/pl r1                    ! positive?
    bt      .L_angle_a_positive
    neg r1, r1                   ! abs(heading_A - combined_angle)
.L_angle_a_positive:
    extu.w r1, r1                ! r1 = |heading_A - combined_angle| & 0xFFFF
    cmp/gt r1, r4                ! within half-circle?
    bt      .L_check_heading_b   ! yes: car A heading matches
    sub r4, r1                   ! wrap into half-circle range
    mov #0x0, r7                 ! heading_a_match = false
.L_check_heading_b:
    mov.l @(48, r14), r1         ! r1 = car_A.heading (reload)
    mov #0x1, r8                 ! r8 = heading_b_match (assume match)
    mov r4, r3                   ! r3 = half_circle
    extu.w r10, r6               ! r6 = original atan2 result (unsigned)
    shll r3                      ! r3 = full_circle
    or r3, r6                    ! r6 = full_circle | atan2_angle
    sub r6, r1                   ! r1 = heading_A - (full_circle | atan2_angle)
    cmp/pl r1                    ! positive?
    bt/s    .L_angle_b_positive
    mov.l @(48, r13), r2         ! r2 = car_B.heading (delay slot)
    neg r1, r1                   ! abs(difference)
.L_angle_b_positive:
    extu.w r1, r1                ! r1 = |difference| & 0xFFFF
    bsr     .L_check_reverse_dir ! check if car B is reversed on track
    nop
    cmp/gt r1, r4                ! within half-circle?
    bt      .L_compare_directions ! yes: car B heading matches
    sub r4, r1                   ! wrap into half-circle range
    mov #0x0, r8                 ! heading_b_match = false
.L_compare_directions:
    cmp/eq r7, r8                ! both headings agree?
    bt      .L_decompose_angle   ! yes: no conflict
    mov #0x1, r9                 ! conflict_flag = 1 (headings diverge)
.L_decompose_angle:
    mov.l r4, @-r15              ! save half_circle
    mov r1, r4                   ! r4 = angle arg for sin_lookup
    .byte   0xD0, 0x10    /* mov.l .L_pool_sin_lookup_a, r0 */
    jsr @r0                      ! r0 = sin_lookup(angle)
    nop
    mov.l @r15+, r4              ! restore half_circle
    sub r10, r2                  ! r2 = car_B.heading - atan2_angle
    extu.w r2, r2                ! unsigned wrap
    cmp/gt r2, r4                ! within half-circle?
    bt/s    .L_angle_halved      ! yes: keep as-is
    shlr8 r1                     ! r1 = sin_result >> 8 (delay slot)
    sub r4, r2                   ! wrap into half-circle range
.L_angle_halved:
    shlr r1                      ! r1 >>= 1 (sin_result >> 9 total)
    mov #0x0, r7                 ! r7 = valid_angle (assume invalid)
    mov #0xA, r3                 ! lower threshold = 0xA
    cmp/ge r1, r3                ! sin_index < 0xA? (too small)
    bt      .L_done_validity_check ! yes: angle too shallow, skip
    mov #0x37, r3                ! upper threshold = 0x37
    cmp/ge r3, r1                ! sin_index >= 0x37? (too large)
    bt      .L_done_validity_check ! yes: angle too steep, skip
    mov #0x1, r7                 ! valid_angle = 1 (in usable range)
.L_done_validity_check:
    shll2 r1                     ! r1 <<= 2 (scale to table index)
    shlr8 r2                     ! r2 >>= 8
    shlr r2                      ! r2 >>= 1 (total >>= 9)
    shll2 r2                     ! r2 <<= 2 (scale to table index)
    tst r9, r9                   ! conflict_flag == 0?
    bt      .L_force_table_lookup ! no conflict: go to force table
    tst r8, r8                   ! heading_b_match == 0?
    bt      .L_set_approach_flag  ! not matching: set approach flag
    bra     .L_check_validity     ! both matched: check validity
    mov #0x0, r8                 ! clear heading_b_match (delay slot)

    .global DAT_060310b8
DAT_060310b8:
    .2byte  0x8000               ! half circle (180 deg heading range)
    .2byte  0x0000               ! padding
    .4byte  atan2                ! atan2 function pointer
.L_pool_sin_lookup_a:
    .4byte  sin_lookup           ! sine lookup function
.L_set_approach_flag:
    mov #0x1, r8                 ! heading_b_match = 1 (approaching)
.L_check_validity:
    tst r7, r7                   ! valid_angle?
    bt      .L_force_table_lookup ! no: use force table path
    bra     .L_heading_diff_check ! yes: check heading difference
    mov r12, r4                  ! r4 = collision param (delay slot)
.L_force_table_lookup:
    .byte   0xD3, 0x05    /* mov.l .L_pool_force_table, r3 */
    add r3, r1              ! r1 = &force_table[sin_index]
    add r3, r2              ! r2 = &force_table[heading_index]
    mov.l @r1, r4           ! r4 = force_table[sin_index]
    sub r12, r4             ! r4 -= collision_param
    mov.l @r2, r12          ! r12 = force_table[heading_index]
    add r12, r4             ! r4 = net force
    cmp/pl r4               ! net force > 0?
    bt      .L_heading_diff_check ! yes: apply heading correction
    bra     .L_epilogue     ! no: skip correction, exit
    nop
.L_pool_force_table:
    .4byte  sym_0605BCC8         ! collision force lookup table
.L_heading_diff_check:
    mov.l @(40, r14), r1         ! r1 = car_A.heading2
    mov.l @(40, r13), r2         ! r2 = car_B.heading2
    sub r2, r1                   ! r1 = heading2 difference
    extu.w r1, r1                ! unsigned wrap to 16-bit
    mov.w   DAT_0603112e, r3     ! r3 = 0x4000 (quarter circle = 90 deg)
    mov #0x0, r11                ! r11 = side_flag (0 = not side-on)
    cmp/ge r1, r3                ! diff < quarter circle?
    bt      .L_heading_diff_negative ! yes: headings roughly aligned
    mov r3, r2                   ! r2 = quarter_circle
    shll r2                      ! r2 = half_circle
    add r2, r3                   ! r3 = 3 * quarter_circle (270 deg)
    cmp/ge r3, r1                ! diff >= 270 deg?
    bt      .L_heading_diff_negative ! yes: headings nearly opposite
    mov #0x1, r11                ! side_flag = 1 (cars are side-by-side)
    mov.l @(12, r14), r1         ! r1 = car_A.y_pos
    mov.l @(12, r13), r3         ! r3 = car_B.y_pos
    .byte   0xD2, 0x0A    /* mov.l .L_pool_heading_thresh_a, r2 */
    add r3, r1                   ! r1 = sum of Y positions
    cmp/ge r1, r2                ! sum < height_threshold (0x42AAA)?
    bt      .L_apply_direction_force ! yes: skip force_steer_impact
    mov.l r4, @-r15              ! save r4
    mov.l r0, @-r15              ! save r0
    mov.l @(0, r13), r0          ! r0 = car_B.flags
    .byte   0xD4, 0x08    /* mov.l .L_pool_force_flag_a, r4 */
    or r4, r0                    ! set COLLISION_FLAG (bit 27)
    mov.l r0, @(0, r13)          ! store updated flags
    .byte   0xD0, 0x07    /* mov.l .L_pool_force_steer_a, r0 */
    jsr @r0                      ! call force_steer_impact
    nop
    mov.w   DAT_06031130, r0     ! r0 = 0x0214 (struct offset for steer result)
    mov.w   DAT_06031132, r4     ! r4 = 0x00CC (steer correction value)
    mov.l r4, @(r0, r14)         ! car_A[0x214] = steer correction
    mov.l @r15+, r0              ! restore r0
    bra     .L_apply_direction_force
    mov.l @r15+, r4              ! restore r4 (delay slot)

    .global DAT_0603112e
DAT_0603112e:
    .2byte  0x4000               ! quarter circle (90 deg threshold)

    .global DAT_06031130
DAT_06031130:
    .2byte  0x0214               ! car struct offset for steer result

    .global DAT_06031132
DAT_06031132:
    .2byte  0x00CC               ! steering correction value
.L_pool_heading_thresh_a:
    .4byte  0x00042AAA           ! Y height threshold (~274K fixed-point)
.L_pool_force_flag_a:
    .4byte  0x08000000           ! COLLISION_FLAG (bit 27)
.L_pool_force_steer_a:
    .4byte  force_steer_impact   ! collision steering correction function
.L_heading_diff_negative:
    mov.l @(12, r14), r1         ! r1 = car_A.y_pos
    mov.l @(12, r13), r3         ! r3 = car_B.y_pos
    .byte   0xD2, 0x11    /* mov.l .L_pool_heading_thresh_b, r2 */
    sub r3, r1                   ! r1 = height difference (A - B)
    cmp/ge r1, r2                ! diff < height_threshold?
    bt      .L_check_side_approach ! yes: skip force_steer_impact
    mov.l r4, @-r15              ! save r4
    mov.l r0, @-r15              ! save r0
    mov.l @(0, r13), r0          ! r0 = car_B.flags
    .byte   0xD4, 0x0F    /* mov.l .L_pool_force_flag_b, r4 */
    or r4, r0                    ! set COLLISION_FLAG (bit 27)
    mov.l r0, @(0, r13)          ! store updated flags
    .byte   0xD0, 0x0E    /* mov.l .L_pool_force_steer_b, r0 */
    jsr @r0                      ! call force_steer_impact
    nop
    mov.w   DAT_06031188, r0     ! r0 = 0x0214 (struct offset)
    mov.w   DAT_0603118a, r4     ! r4 = 0x00CC (steer correction)
    mov.l r4, @(r0, r14)         ! car_A[0x214] = steer correction
    mov.l @r15+, r0              ! restore r0
    mov.l @r15+, r4              ! restore r4
.L_check_side_approach:
    tst r7, r7                   ! valid_angle?
    bf      .L_lateral_proximity  ! yes: go to lateral proximity check
    mov.l @(12, r14), r1         ! r1 = car_A.y_pos
    mov.l @(12, r13), r3         ! r3 = car_B.y_pos
    shlr r2                      ! r2 = half of height_threshold
    sub r3, r1                   ! r1 = Y difference (A - B)
    cmp/gt r1, r2                ! diff < half_threshold?
    bt      .L_lateral_proximity  ! yes: check lateral
    tst r8, r8                   ! heading_b_match == 0?
    mov.l @(0, r14), r2          ! r2 = car_A.flags
    .byte   0xD3, 0x06    /* mov.l .L_pool_steer_direct, r3 */
    bt      .L_apply_steer_flag   ! not approaching: use full flag
    shlr r3                      ! approaching: halve the flag (0x10000000)
.L_apply_steer_flag:
    or r3, r2                    ! set DIRECTION_FLAG in car_A.flags
    bra     .L_apply_direction_force
    mov.l r2, @(0, r14)          ! store updated car_A.flags (delay slot)

    .global DAT_06031188
DAT_06031188:
    .2byte  0x0214               ! car struct offset for steer result

    .global DAT_0603118a
DAT_0603118a:
    .2byte  0x00CC               ! steering correction value
.L_pool_heading_thresh_b:
    .4byte  0x00042AAA           ! Y height threshold (~274K fixed-point)
.L_pool_force_flag_b:
    .4byte  0x08000000           ! COLLISION_FLAG (bit 27)
.L_pool_force_steer_b:
    .4byte  force_steer_impact   ! collision steering correction function
.L_pool_steer_direct:
    .4byte  0x20000000           ! DIRECTION_FLAG (bit 29)
.L_lateral_proximity:
    mov.l @(40, r14), r3         ! r3 = car_A.heading2
    sub r10, r3                  ! r3 -= atan2_angle
    mov.w   DAT_060311b6, r2     ! r2 = 0x4000 (quarter circle)
    extu.w r3, r3                ! unsigned wrap
    cmp/ge r3, r2                ! diff < quarter circle?
    bt      .L_apply_lateral_corr ! yes: cars close enough laterally
    mov r2, r1                   ! r1 = quarter circle
    shll r1                      ! r1 = half circle
    add r1, r2                   ! r2 = 3 * quarter circle (270 deg)
    cmp/ge r2, r3                ! diff >= 270 deg?
    bt      .L_apply_lateral_corr ! yes: nearly opposite, still close
    bra     .L_apply_direction_force ! no: too far apart, skip correction
    nop

    .global DAT_060311b6
DAT_060311b6:
    .2byte  0x4000               ! quarter circle (90 deg threshold)
.L_apply_lateral_corr:
    mov.l r4, @-r15              ! save r4
    mov.l r0, @-r15              ! save r0
    tst r7, r7                   ! valid_angle?
    bt      .L_call_cos_lookup    ! no: skip heading copy
    mov.l @(48, r14), r4         ! r4 = car_A.heading3
    mov.l r4, @(48, r13)         ! car_B.heading3 = car_A.heading3
    mov.w   .L_wpool_heading_rate_ofs, r1 ! r1 = 0x0208 (heading rate offset)
    mov #0x8, r2                 ! r2 = 8 (heading rate value)
    add r13, r1                  ! r1 = &car_B[0x208]
    mov.l r2, @r1                ! car_B[0x208] = 8
.L_call_cos_lookup:
    .byte   0xD0, 0x0F    /* mov.l .L_pool_cos_lookup_a, r0 */
    jsr @r0                      ! r0 = cos_lookup(lateral_angle)
    mov r3, r4                   ! r4 = lateral_angle (delay slot)
    mov.l @(12, r14), r1         ! r1 = car_A.y_pos
    mov.l @(12, r13), r2         ! r2 = car_B.y_pos
    sub r2, r1                   ! r1 = Y difference
    shlr2 r1                     ! r1 >>= 2 (scale down)
    dmuls.l r0, r1               ! 64-bit: cos * y_diff
    sts mach, r0                 ! r0 = high 32 bits
    sts macl, r1                 ! r1 = low 32 bits
    xtrct r0, r1                 ! r1 = middle 32 bits (fixed-point result)
    shar r1                      ! r1 >>= 1 (arithmetic shift, preserve sign)
    add r1, r2                   ! r2 = car_B.y_pos + correction
    mov.w   DAT_0603120a, r3     ! r3 = 0x0194 (Y interp offset in struct)
    add r13, r3                  ! r3 = &car_B[0x194]
    mov.l r2, @r3                ! car_B[0x194] = interpolated Y
    mov.l @(12, r14), r4         ! r4 = car_A.y_pos
    sub r1, r4                   ! r4 -= correction (equal+opposite)
    mov.l r4, @(12, r14)         ! car_A.y_pos = adjusted
    mov.l @r15+, r0              ! restore r0
    mov.l @r15+, r4              ! restore r4
.L_apply_direction_force:
    tst r7, r7                   ! valid_angle?
    bf      .L_approaching_path   ! yes: take approaching path
    .byte   0xD5, 0x05    /* mov.l .L_pool_state_byte_a, r5 */
    mov.b @r5, r3                ! r3 = state_byte_A (sym_0602FD9A)
    tst r3, r3                   ! state == 0?
    bf      .L_scale_correction   ! no: already set, skip init
    mov #0x3, r3                 ! r3 = 3 (init timer/counter)
    bra     .L_scale_correction
    mov.b r3, @r5                ! state_byte_A = 3 (delay slot)
.L_wpool_heading_rate_ofs:
    .2byte  0x0208               ! car struct offset for heading rate

    .global DAT_0603120a
DAT_0603120a:
    .2byte  0x0194               ! car struct offset for interpolated Y
.L_pool_cos_lookup_a:
    .4byte  cos_lookup           ! cosine lookup function
.L_pool_state_byte_a:
    .4byte  sym_0602FD9A         ! collision state byte A
.L_approaching_path:
    mov.l r0, @-r15              ! save r0
    mov.l r4, @-r15              ! save r4
    .byte   0xD5, 0x07    /* mov.l .L_pool_state_byte_b, r5 */
    mov.l @(0, r14), r2          ! r2 = car_A.flags
    tst r8, r8                   ! heading_b_match == 0?
    .byte   0xDA, 0x07    /* mov.l .L_pool_reverse_flag, r10 */
    bf      .L_read_reverse_front ! approaching: take front path
    mov.w @r10, r10              ! r10 = reverse_direction_flag value
    add #0x1, r5                 ! r5 = &state_byte + 1 (alternate byte)
    mov #-0x80, r3               ! r3 = 0x80
    extu.b r3, r3                ! r3 = 0x80 (unsigned, retreating flag)
    tst r10, r10                 ! reverse_flag == 0?
    bt      .L_merge_flags        ! yes: use 0x80 flag
    mov.w   .L_wpool_large_flag, r3 ! no: use 0x0200 (reversed + retreating)
    bra     .L_merge_flags
    nop
.L_wpool_large_flag:
    .2byte  0x0200               ! reversed + retreating flag
    .2byte  0x0000               ! padding
.L_pool_state_byte_b:
    .4byte  sym_0602FD98         ! collision state byte B
.L_pool_reverse_flag:
    .4byte  sym_06031A24         ! reverse-direction flag word
.L_read_reverse_front:
    mov.w @r10, r10              ! r10 = reverse_direction_flag value
    mov #0x40, r3                ! r3 = 0x40 (approaching flag)
    tst r10, r10                 ! reverse_flag == 0?
    bt      .L_merge_flags        ! yes: use 0x40
    mov.w   .L_wpool_front_flag, r3 ! no: use 0x0100 (reversed + approaching)
.L_merge_flags:
    or r3, r2                    ! merge direction flag into car_A.flags
    mov.l r2, @(0, r14)          ! store updated car_A.flags
    mov.b @r5, r4                ! r4 = state_byte value
    tst r4, r4                   ! state == 0?
    bf      .L_restore_and_compute ! no: already initialized
    mov #0x3, r4                 ! r4 = 3 (init timer/counter)
    mov.b r4, @r5                ! state_byte = 3
.L_restore_and_compute:
    mov.l @r15+, r4              ! restore r4
    mov.l @r15+, r0              ! restore r0
    mov.w   .L_wpool_quarter_circle, r3 ! r3 = 0x4000 (quarter circle)
    tst r8, r8                   ! heading_b_match == 0?
    mov.l @(48, r14), r10        ! r10 = car_A.heading3
    bf/s    .L_heading_blend      ! approaching: use quarter_circle offset
    extu.w r10, r10              ! unsigned (delay slot)
    mov r3, r7                   ! retreating path: r7 = quarter_circle
    shll r7                      ! r7 = half_circle
    add r7, r3                   ! r3 = 3 * quarter_circle (270 deg offset)
.L_heading_blend:
    dmuls.l r0, r4               ! 64-bit: sin_result * correction
    add r3, r10                  ! r10 = heading + angle_offset
    tst r9, r9                   ! conflict_flag == 0?
    sts mach, r0                 ! r0 = high 32 bits
    sts macl, r4                 ! r4 = low 32 bits
    xtrct r0, r4                 ! r4 = middle 32 bits (fixed-point blend)
    bt      .L_scale_correction   ! no conflict: skip adjustment
    .byte   0xD3, 0x0A    /* mov.l .L_pool_half_circle_adj, r3 */
    add r3, r4                   ! conflict: add 0xD999 crossing offset
.L_scale_correction:
    mov.w   .L_wpool_scale_index_ofs, r3 ! r3 = 0x007C (scale index offset)
    add r14, r3                  ! r3 = &car_A[0x7C]
    mov.w @r3, r0                ! r0 = scale_index
    mov #0x8, r5                 ! r5 = 8 (high threshold)
    cmp/ge r5, r0                ! scale_index >= 8?
    bt      .L_zero_scale         ! yes: zero out correction
    add #-0x2, r5               ! r5 = 6 (medium threshold)
    cmp/ge r5, r0                ! scale_index >= 6?
    bt      .L_medium_scale       ! yes: use full correction, zero remainder
    shlr r4                      ! r4 >>= 1 (correction / 2)
    mov r4, r3                   ! r3 = correction / 2
    shlr r4                      ! r4 >>= 1 (correction / 4)
    add r4, r3                   ! r3 = 3/4 of original correction
    bra     .L_apply_pos_correction
    mov.l r4, @-r15              ! save remainder on stack (delay slot)
.L_wpool_front_flag:
    .2byte  0x0100               ! reversed + approaching flag
.L_wpool_quarter_circle:
    .2byte  0x4000               ! 90 degrees (quarter circle)
.L_wpool_scale_index_ofs:
    .2byte  0x007C               ! car struct offset for scale index
    .2byte  0x0000               ! padding
.L_pool_half_circle_adj:
    .4byte  0x0000D999           ! crossing offset constant
.L_medium_scale:
    mov r4, r3                   ! r3 = full correction (unscaled)
    mov #0x0, r4                 ! r4 = 0 (no remainder)
    bra     .L_apply_pos_correction
    mov.l r4, @-r15              ! push 0 (delay slot)
.L_zero_scale:
    mov #0x0, r3                 ! r3 = 0 (no correction)
    mov.l r4, @-r15              ! push original r4
.L_apply_pos_correction:
    neg r10, r4                  ! r4 = -heading_angle (for trig lookup)
    mov r3, r9                   ! r9 = Z_correction_scale
    mov.l @(16, r13), r5         ! r5 = car_B.x_pos
    mov.l @(24, r13), r6         ! r6 = car_B.z_pos
    mov.l r5, @(56, r13)         ! car_B.x_backup = x_pos (save pre-correction)
    mov.l r6, @(60, r13)         ! car_B.z_backup = z_pos (save pre-correction)
    .byte   0xD0, 0x1C    /* mov.l .L_pool_cos_lookup_b, r0 */
    jsr @r0                      ! r0 = cos_lookup(-heading)
    nop
    mov r0, r8                   ! r8 = cos_value
    neg r10, r4                  ! r4 = -heading_angle (for sin)
    .byte   0xD0, 0x1B    /* mov.l .L_pool_sin_lookup_b, r0 */
    jsr @r0                      ! r0 = sin_lookup(-heading)
    nop
    dmuls.l r0, r3               ! 64-bit: sin * X_correction
    sts mach, r11
    sts macl, r3
    xtrct r11, r3                ! r3 = X impulse (fixed-point)
    add r3, r5                   ! car_B.x_pos += X impulse
    mov.l r5, @(16, r13)         ! store corrected X
    dmuls.l r8, r9               ! 64-bit: cos * Z_correction
    sts mach, r8
    sts macl, r9
    xtrct r8, r9                 ! r9 = Z impulse (fixed-point)
    add r9, r6                   ! car_B.z_pos += Z impulse
    mov.l r6, @(24, r13)         ! store corrected Z
    mov.l @r15+, r3              ! restore scale remainder
    .byte   0xD5, 0x14    /* mov.l .L_fp_half, r5 */
    add r5, r10                  ! r10 += 0x8000 (rotate 180 degrees)
    neg r10, r4                  ! r4 = -(heading + 180) for opposite impulse
    mov r3, r9                   ! r9 = Z_correction_scale (for car_A)
    mov.l @(16, r14), r5         ! r5 = car_A.x_pos
    mov.l @(24, r14), r6         ! r6 = car_A.z_pos
    mov.l r5, @(56, r14)         ! car_A.x_backup = x_pos
    mov.l r6, @(60, r14)         ! car_A.z_backup = z_pos
    .byte   0xD0, 0x0E    /* mov.l .L_pool_cos_lookup_b, r0 */
    jsr @r0                      ! r0 = cos_lookup(opposite_heading)
    nop
    mov r0, r8                   ! r8 = cos_value
    neg r10, r4                  ! r4 = opposite heading for sin
    .byte   0xD0, 0x0C    /* mov.l .L_pool_sin_lookup_b, r0 */
    jsr @r0                      ! r0 = sin_lookup(opposite_heading)
    nop
    dmuls.l r0, r3               ! 64-bit: sin * X_correction (opposite)
    sts mach, r11
    sts macl, r3
    xtrct r11, r3                ! r3 = opposite X impulse
    add r3, r5                   ! car_A.x_pos += opposite X impulse
    mov.l r5, @(16, r14)         ! store corrected X
    dmuls.l r8, r9               ! 64-bit: cos * Z_correction (opposite)
    sts mach, r8
    sts macl, r9
    xtrct r8, r9                 ! r9 = opposite Z impulse
    add r9, r6                   ! car_A.z_pos += opposite Z impulse
    mov.l r6, @(24, r14)         ! store corrected Z
.L_epilogue:
    lds.l @r15+, pr              ! restore return address
    mov.l @r15+, r14             ! restore callee-saved registers
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8              ! (delay slot)
.L_pool_cos_lookup_b:
    .4byte  cos_lookup           ! cosine lookup (position correction)
.L_pool_sin_lookup_b:
    .4byte  sin_lookup           ! sine lookup (position correction)
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_check_reverse_dir:            ! subroutine: test if heading is in rear arc (90-270 deg)
    mov.l r4, @-r15              ! save r4
    mov.l r5, @-r15              ! save r5
    mov.w   DAT_0603135c, r4     ! r4 = 0x4000 (quarter circle = 90 deg)
    mov r4, r5                   ! r5 = quarter_circle
    cmp/ge r1, r4                ! heading_diff < 90 deg?
    shll r5                      ! r5 = half_circle (0x8000)
    bt      .L_clear_reverse_flag ! yes: facing forward, clear flag
    add r5, r4                   ! r4 = 3 * quarter_circle (270 deg)
    cmp/ge r4, r1                ! heading_diff >= 270 deg?
    .byte   0xD5, 0x03    /* mov.l .L_pool_reverse_flag_sub, r5 */
    bt      .L_clear_reverse_flag ! yes: nearly forward, clear flag
    mov #0x1, r4                 ! in rear arc (90-270): set flag = 1
    bra     .L_check_reverse_ret
    mov.w r4, @r5                ! reverse_flag = 1 (delay slot)

    .global DAT_0603135c
DAT_0603135c:
    .2byte  0x4000               ! quarter circle (90 deg)
    .2byte  0x0000               ! padding
.L_pool_reverse_flag_sub:
    .4byte  sym_06031A24         ! reverse-direction flag word
.L_clear_reverse_flag:
    mov #0x0, r4                 ! facing forward: flag = 0
    mov.w r4, @r5                ! reverse_flag = 0
.L_check_reverse_ret:
    mov.l @r15+, r5              ! restore r5
    rts
    mov.l @r15+, r4              ! restore r4 (delay slot)
    .2byte  0x2F06               ! next TU prologue (not part of this function)
    .4byte  0x64833468
    .4byte  0x65933578
    .2byte  0xD030
