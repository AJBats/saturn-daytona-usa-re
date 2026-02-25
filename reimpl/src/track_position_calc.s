/* track_position_calc -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0600C994 - 0x0600CB90
 *
 * Two functions in this TU:
 *
 * 1) track_position_calc:
 *    Called per-car from car_frame_update after collision/checkpoint processing.
 *    Computes the car's nearest track segment by comparing atan2 headings.
 *    For each pair of consecutive segments in the course data array, calculates
 *    the angle from the car's world position (X,Z) to the segment's X,Z coords
 *    using atan2. The segment whose heading angle is closest to the car's own
 *    heading (from car[+0x1EC]) is chosen and stored into car[+0x1FC].
 *
 *    Registers on entry (set by car_frame_update):
 *      No explicit args — reads car struct via *sym_0607E944 (car array base).
 *
 *    Car struct offsets used:
 *      +0x01EC = current track segment index
 *      +0x01FC = best matching segment (output)
 *
 * 2) heading_smooth_gentle:
 *    Called during car_type_init to compute smoothed heading and position
 *    for a car's initial placement. Reads the heading target (car[+0x1FC])
 *    and smoothed heading (car[+0x1F8]), nudges the smoothed value toward
 *    the target by +/-4 per call (or snaps if within 8). Then interpolates
 *    X/Z position and heading from the course segment data array based on
 *    the sub-segment fractional position.
 *
 *    Registers on entry:
 *      r4 = output buffer pointer (receives interpolated X, Z, heading data)
 *
 *    Car struct offsets used:
 *      +0x01EC = track segment index
 *      +0x01F8 = heading (smoothed, read/write)
 *      +0x01FC = heading (target, read)
 *
 *    Course segment data (sym_0607EB88): 16 bytes per entry
 *      +0x00 = X position (32-bit)
 *      +0x04 = Z position (32-bit)
 *      +0x08 = heading angle A (16-bit)
 *      +0x0A = heading angle B (16-bit, scaled x4 for output)
 *      +0x0C = heading angle C (16-bit)
 */

    .section .text.FUN_0600C994


    .global track_position_calc
    .type track_position_calc, @function
track_position_calc:
    mov.l r14, @-r15                ! save r14
    mov.l r13, @-r15                ! save r13
    mov.l r12, @-r15                ! save r12
    mov.l r11, @-r15                ! save r11
    mov.l r10, @-r15                ! save r10
    mov.l r9, @-r15                 ! save r9
    mov.l r8, @-r15                 ! save r8
    sts.l pr, @-r15                 ! save return address
    add #-0x1C, r15                 ! allocate 28 bytes of stack frame
    mov.w   DAT_0600c9e6, r9       ! r9 = 0x0100 (lookup table stride = 256)
    mov.l   .L_p_atan2, r10        ! r10 = &atan2 function
    mov.l   .L_p_seg_data_array, r11 ! r11 = &course_seg_data_ptr (sym_0607EB88)
    mov.l   .L_p_car_array_base, r12 ! r12 = &car_array_base_ptr (sym_0607E944)
    mov.w   DAT_0600c9e4, r0       ! r0 = 0x01EC (offset: car track segment index)
    mov.l @r12, r12                 ! r12 = car_array_base (dereference pointer)
    mov.l @(r0, r12), r4           ! r4 = car[+0x1EC] = current track segment index
    add #0x1, r4                    ! r4 = segment_index + 1 (start from next segment)
    shll2 r4                        ! r4 *= 4
    shll r4                         ! r4 *= 2 (total: segment_index+1 * 8)
    mov r4, r5                      ! r5 = (segment_index+1) * 8
    add #0x3, r5                    ! r5 += 3 (offset into segment: entry index * 8 + 3)
    shll2 r5                        ! r5 *= 4
    shll2 r5                        ! r5 *= 4 (total: ((seg+1)*8+3) * 16 = byte offset into seg array)
    mov.l @r11, r3                  ! r3 = course_seg_data_base (dereference pointer)
    add r3, r5                      ! r5 = &seg_data[(seg+1)*8+3] — segment entry pointer
    mov.w @(10, r5), r0            ! r0 = seg_entry.heading_b (16-bit at offset 10)
    mov r0, r2                      ! r2 = heading_b value
    shll2 r2                        ! r2 *= 4 (scale heading to angle units)
    mov.l r2, @(8, r15)            ! sp[8] = reference_heading (scaled heading from segment)
    mov r15, r3                     ! r3 = stack pointer
    add #0xC, r3                    ! r3 = &sp[12] (start of angle result buffer on stack)
    mov.l r3, @(4, r15)            ! sp[4] = &angle_buffer_start
    mov r3, r14                     ! r14 = angle_buffer_write_ptr (current write position)
    mov r4, r13                     ! r13 = (segment_index+1) * 8
    shll2 r13                       ! r13 *= 4
    mov r15, r3                     ! r3 = stack pointer
    add #0x1C, r3                   ! r3 = &sp[28] = end of stack frame (loop sentinel)
    mov.l r3, @r15                  ! sp[0] = &angle_buffer_end (loop terminator)
    bra     .L_loop_cond_check      ! jump to loop condition
    shll2 r13                       ! (delay) r13 *= 4 (total: entry_offset = ((seg+1)*8) * 16)

    .global DAT_0600c9e4
DAT_0600c9e4:
    .2byte  0x01EC                  ! car struct offset: track segment index

    .global DAT_0600c9e6
DAT_0600c9e6:
    .2byte  0x0100                  ! lookup table stride (256 bytes per entry)
    .4byte  sym_0605A1E0            ! heading lookup table base address
.L_p_atan2:
    .4byte  atan2                   ! atan2(r4=deltaX, r5=deltaZ) function pointer
.L_p_seg_data_array:
    .4byte  sym_0607EB88            ! course segment data array pointer
.L_p_car_array_base:
    .4byte  sym_0607E944            ! car array base pointer
.L_compute_segment_angles:
    mov.l @r11, r8                  ! r8 = course_seg_data_base (dereference pointer)
    mov.l @(24, r12), r2           ! r2 = car_array_base[24] = car Z world position
    mov.l @(16, r12), r3           ! r3 = car_array_base[16] = car X world position
    add r13, r8                     ! r8 = &seg_data[current_entry] (base + offset)
    mov.l @(4, r8), r5            ! r5 = segment_entry.Z (32-bit Z coord at +4)
    mov.l @r8, r4                  ! r4 = segment_entry.X (32-bit X coord at +0)
    sub r2, r5                      ! r5 = deltaZ = seg.Z - car.Z
    jsr @r10                        ! call atan2(r4=deltaX, r5=deltaZ)
    sub r3, r4                      ! (delay) r4 = deltaX = seg.X - car.X
    neg r0, r0                      ! negate angle (convention: clockwise positive)
    add #0x10, r13                  ! advance to next segment entry (+16 bytes)
    mov.w r0, @r14                 ! store angle result to buffer
    add #0x2, r14                   ! advance write pointer by 2 bytes (word)
    mov.l @r11, r8                  ! r8 = course_seg_data_base (reload)
    mov.l @(24, r12), r2           ! r2 = car Z world position (reload)
    mov.l @(16, r12), r3           ! r3 = car X world position (reload)
    add r13, r8                     ! r8 = &seg_data[next_entry]
    mov.l @(4, r8), r5            ! r5 = next_segment.Z
    mov.l @r8, r4                  ! r4 = next_segment.X
    sub r2, r5                      ! r5 = deltaZ for next segment
    jsr @r10                        ! call atan2(r4=deltaX, r5=deltaZ)
    sub r3, r4                      ! (delay) r4 = deltaX for next segment
    neg r0, r0                      ! negate angle
    extu.w r0, r0                   ! zero-extend to unsigned 16-bit
    mov.w r0, @r14                 ! store second angle to buffer
    add #0x2, r14                   ! advance write pointer
    add #0x10, r13                  ! advance to next entry pair (+16 more bytes)
.L_loop_cond_check:
    mov.l @r15, r2                  ! r2 = angle_buffer_end (loop sentinel)
    cmp/hs r2, r14                  ! has write pointer reached end of buffer?
    bf      .L_compute_segment_angles ! no — compute more segment angles
    mov.l @(4, r15), r4            ! r4 = angle_buffer_start (first stored angle)
    mov.l @(8, r15), r14           ! r14 = reference_heading (negated for comparison)
    mov.w @r4, r4                  ! r4 = first angle value (16-bit)
    neg r14, r14                    ! r14 = -reference_heading
    extu.w r4, r4                   ! zero-extend first angle
    extu.w r14, r14                 ! zero-extend negated heading
    add r14, r4                     ! r4 = first_angle - reference_heading (difference)
    exts.w r4, r4                   ! sign-extend the difference
    cmp/pz r4                       ! is difference >= 0?
    bt      .L_diff_positive        ! yes — use as-is
    bra     .L_diff_ready           ! no — negate to get absolute value
    neg r4, r7                      ! (delay) r7 = |difference|
.L_diff_positive:
    mov r4, r7                      ! r7 = difference (already positive)
.L_diff_ready:
    extu.w r7, r7                   ! r7 = best_distance (unsigned 16-bit abs diff)
    mov #0x0, r13                   ! r13 = best_index = 0 (initial: first entry wins)
    mov r9, r5                      ! r5 = stride (0x0100, used as index counter)
    mov r15, r4                     ! r4 = stack pointer
    bra     .L_search_cond_check    ! jump to search loop condition
    add #0xE, r4                    ! (delay) r4 = &sp[14] = second angle in buffer
.L_search_compare:
    mov.w @r4, r6                  ! r6 = current angle from buffer
    extu.w r6, r6                   ! zero-extend angle
    add r14, r6                     ! r6 = angle - reference_heading (difference)
    exts.w r6, r6                   ! sign-extend the difference
    cmp/pz r6                       ! is difference >= 0?
    bt      .L_abs_done             ! yes — already absolute
    neg r6, r6                      ! negate to get |difference|
.L_abs_done:
    extu.w r7, r3                   ! r3 = current best_distance (unsigned)
    cmp/gt r6, r3                   ! is best_distance > this distance?
    bf      .L_no_update            ! no — current entry is not closer, skip
    extu.w r6, r7                   ! r7 = new best_distance (this entry is closer)
    extu.w r5, r13                  ! r13 = new best_index (stride-based index)
.L_no_update:
    add r9, r5                      ! r5 += stride (advance index by 0x100)
    add #0x2, r4                    ! r4 += 2 (advance to next angle in buffer)
.L_search_cond_check:
    mov.l @r15, r3                  ! r3 = angle_buffer_end
    cmp/hs r3, r4                   ! has search pointer reached end?
    bf      .L_search_compare       ! no — compare next angle
    extu.w r13, r13                 ! r13 = best matching index (zero-extended)
    mov.w   DAT_0600cac0, r0       ! r0 = 0x01FC (offset: car best segment result)
    mov.l r13, @(r0, r12)          ! car[+0x1FC] = best_index (store result)
    add #0x1C, r15                  ! deallocate stack frame
    lds.l @r15+, pr                 ! restore return address
    mov.l @r15+, r8                 ! restore r8
    mov.l @r15+, r9                 ! restore r9
    mov.l @r15+, r10                ! restore r10
    mov.l @r15+, r11                ! restore r11
    mov.l @r15+, r12                ! restore r12
    mov.l @r15+, r13                ! restore r13
    rts                             ! return
    mov.l @r15+, r14                ! (delay) restore r14

    .global heading_smooth_gentle
heading_smooth_gentle:
    mov.l r13, @-r15                ! save r13
    sts.l macl, @-r15               ! save macl (used by mul.l)
    mov.l   .L_p_cur_car_ptr, r5   ! r5 = &current_car_ptr (sym_0607E940)
    mov.w   DAT_0600cac2, r0       ! r0 = 0x01F8 (offset: smoothed heading)
    mov.l @r5, r5                   ! r5 = current car struct base (dereference)
    mov.l @(r0, r5), r6           ! r6 = car[+0x1F8] = smoothed heading
    add #0x4, r0                    ! r0 = 0x01FC (offset: target heading)
    mov.l @(r0, r5), r3           ! r3 = car[+0x1FC] = target heading
    sub r3, r6                      ! r6 = smoothed - target (heading difference)
    mov #0x8, r3                    ! r3 = 8 (snap threshold positive)
    cmp/ge r3, r6                   ! is difference >= 8?
    bt      .L_nudge_heading        ! yes — difference is large, nudge gradually
    mov #-0x8, r3                   ! r3 = -8 (snap threshold negative)
    cmp/gt r3, r6                   ! is difference > -8?
    bf      .L_nudge_heading        ! no (diff <= -8) — large negative, nudge gradually
    mov.w   DAT_0600cac2, r0       ! r0 = 0x01F8 (smoothed heading offset)
    mov.l @(r0, r5), r3           ! r3 = car[+0x1F8] = smoothed heading
    add #0x4, r0                    ! r0 = 0x01FC (target heading offset)
    mov.l r3, @(r0, r5)           ! car[+0x1FC] = smoothed heading (snap: copy smoothed to target)
    bra     .L_after_heading_adj    ! heading is close enough, skip nudging
    nop                             ! (delay)

    .global DAT_0600cac0
DAT_0600cac0:
    .2byte  0x01FC                  ! car struct offset: best segment result / target heading

    .global DAT_0600cac2
DAT_0600cac2:
    .2byte  0x01F8                  ! car struct offset: smoothed heading
.L_p_cur_car_ptr:
    .4byte  sym_0607E940            ! current car struct pointer
.L_nudge_heading:
    cmp/pl r6                       ! is heading difference positive?
    bf      .L_nudge_negative       ! no — heading is behind target, decrement
    mov.w   DAT_0600cb84, r0       ! r0 = 0x01FC (offset: target heading)
    mov.l @(r0, r5), r3           ! r3 = car[+0x1FC] = target heading
    add #0x4, r3                    ! r3 += 4 (nudge target heading up by 4)
    mov.l r3, @(r0, r5)           ! car[+0x1FC] = target + 4 (gentle increase)
    bra     .L_after_heading_adj    ! done nudging
    nop                             ! (delay)
.L_nudge_negative:
    mov.w   DAT_0600cb84, r0       ! r0 = 0x01FC (offset: target heading)
    mov.l @(r0, r5), r2           ! r2 = car[+0x1FC] = target heading
    add #-0x4, r2                   ! r2 -= 4 (nudge target heading down by 4)
    mov.l r2, @(r0, r5)           ! car[+0x1FC] = target - 4 (gentle decrease)
.L_after_heading_adj:
    mov.w   DAT_0600cb84, r0       ! r0 = 0x01FC (offset: target heading)
    mov.w   DAT_0600cb86, r3       ! r3 = 0x00FF (low-byte mask)
    mov.l   .L_p_course_seg_data, r13 ! r13 = &course_seg_data_ptr (sym_0607EB88)
    mov.l @(r0, r5), r7           ! r7 = car[+0x1FC] = target heading (updated)
    extu.w r7, r6                   ! r6 = heading unsigned 16-bit (full value for high byte)
    and r3, r7                      ! r7 = heading & 0xFF (low byte = sub-segment fraction)
    extu.w r7, r7                   ! zero-extend fraction
    shlr2 r7                        ! r7 >>= 2
    shlr2 r7                        ! r7 >>= 2
    shlr2 r7                        ! r7 >>= 2 (total: fraction >> 6, range 0..3)
    tst r7, r7                      ! is fraction component zero?
    bt/s    .L_no_interpolation     ! yes — no sub-segment interpolation needed
    shlr8 r6                        ! (delay) r6 >>= 8 (high byte = segment index within section)
    mov #0x7, r3                    ! r3 = 7 (max segment index for interpolation)
    cmp/ge r3, r6                   ! is segment_index >= 7?
    bt      .L_no_interpolation     ! yes — at last segment, can't interpolate forward
    mov #0x4, r1                    ! r1 = 4 (complement weight base)
    mov.w   .L_off_track_seg_idx, r0 ! r0 = 0x01EC (offset: track segment index)
    sub r7, r1                      ! r1 = 4 - fraction (weight for current segment)
    mov.l @(r0, r5), r3           ! r3 = car[+0x1EC] = track segment index
    shll2 r3                        ! r3 *= 4
    shll r3                         ! r3 *= 2 (total: seg_index * 8)
    add r3, r6                      ! r6 = seg_index*8 + segment_within_section
    mov r6, r5                      ! r5 = combined_index (for current segment)
    mov.l @r13, r3                  ! r3 = course_seg_data_base (dereference pointer)
    shll2 r5                        ! r5 *= 4
    add #0x1, r6                    ! r6 = combined_index + 1 (next segment for lerp)
    mov r3, r2                      ! r2 = seg_data_base (save for next calc)
    shll2 r5                        ! r5 *= 4 (total: combined_index * 16 = byte offset)
    shll2 r6                        ! r6 *= 4
    add r3, r5                      ! r5 = &seg_data[combined_index] (current entry ptr)
    shll2 r6                        ! r6 *= 4 (total: (combined_index+1) * 16)
    mov.l @r5, r3                  ! r3 = current_seg.X (32-bit X position)
    add r2, r6                      ! r6 = &seg_data[combined_index+1] (next entry ptr)
    mul.l r1, r3                    ! macl = current_seg.X * (4 - fraction)
    mov.l @r6, r2                  ! r2 = next_seg.X (32-bit X position)
    sts macl, r3                    ! r3 = weighted current X
    mul.l r7, r2                    ! macl = next_seg.X * fraction
    sts macl, r2                    ! r2 = weighted next X
    add r2, r3                      ! r3 = total weighted X (sum of both)
    shar r3                         ! r3 >>= 1 (arithmetic shift right)
    shar r3                         ! r3 >>= 1 (total: divide by 4 to normalize weights)
    mov.l r3, @r4                  ! output[0] = interpolated X position
    mov.l @(4, r5), r3            ! r3 = current_seg.Z (32-bit Z position at +4)
    mul.l r1, r3                    ! macl = current_seg.Z * (4 - fraction)
    sts macl, r1                    ! r1 = weighted current Z
    mov.l @(4, r6), r2            ! r2 = next_seg.Z (32-bit Z position at +4)
    mul.l r7, r2                    ! macl = next_seg.Z * fraction
    sts macl, r7                    ! r7 = weighted next Z
    add r7, r1                      ! r1 = total weighted Z
    shar r1                         ! r1 >>= 1
    shar r1                         ! r1 >>= 1 (divide by 4)
    bra     .L_copy_heading_fields  ! jump to copy heading angles
    mov.l r1, @(8, r4)            ! (delay) output[8] = interpolated Z position
.L_no_interpolation:
    mov.w   .L_off_track_seg_idx, r0 ! r0 = 0x01EC (offset: track segment index)
    mov.l @(r0, r5), r2           ! r2 = car[+0x1EC] = track segment index
    shll2 r2                        ! r2 *= 4
    shll r2                         ! r2 *= 2 (total: seg_index * 8)
    add r2, r6                      ! r6 = seg_index*8 + segment_within_section
    mov r6, r5                      ! r5 = combined_index
    shll2 r5                        ! r5 *= 4
    shll2 r5                        ! r5 *= 4 (total: combined_index * 16 = byte offset)
    mov.l @r13, r3                  ! r3 = course_seg_data_base (dereference)
    add r3, r5                      ! r5 = &seg_data[combined_index] (entry pointer)
    mov.l @r5, r2                  ! r2 = seg_entry.X (32-bit X position)
    mov.l r2, @r4                  ! output[0] = X position (no interpolation)
    mov.l @(4, r5), r3            ! r3 = seg_entry.Z (32-bit Z position)
    mov.l r3, @(8, r4)            ! output[8] = Z position (no interpolation)
.L_copy_heading_fields:
    mov.w @(8, r5), r0            ! r0 = seg_entry.heading_A (16-bit at +8)
    mov.w r0, @(12, r4)           ! output[12] = heading angle A (16-bit)
    mov.w @(10, r5), r0           ! r0 = seg_entry.heading_B (16-bit at +10)
    mov r0, r3                      ! r3 = heading_B raw value
    shll2 r3                        ! r3 *= 4 (scale heading_B by 4)
    exts.w r3, r0                   ! r0 = scaled heading_B (sign-extended)
    mov.w r0, @(14, r4)           ! output[14] = heading angle B * 4 (16-bit)
    mov.w @(12, r5), r0           ! r0 = seg_entry.heading_C (16-bit at +12)
    mov.w r0, @(16, r4)           ! output[16] = heading angle C (16-bit)
    mov #0x0, r0                    ! r0 = 0
    mov.w r0, @(18, r4)           ! output[18] = 0 (clear padding/unused field)
    lds.l @r15+, macl               ! restore macl
    rts                             ! return
    mov.l @r15+, r13                ! (delay) restore r13

    .global DAT_0600cb84
DAT_0600cb84:
    .2byte  0x01FC                  ! car struct offset: target heading

    .global DAT_0600cb86
DAT_0600cb86:
    .2byte  0x00FF                  ! low-byte mask (sub-segment fraction)
.L_off_track_seg_idx:
    .2byte  0x01EC                  ! car struct offset: track segment index
    .2byte  0xFFFF                  ! padding / alignment
.L_p_course_seg_data:
    .4byte  sym_0607EB88            ! course segment data array pointer
