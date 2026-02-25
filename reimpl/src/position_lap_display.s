/* position_lap_display -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0603139C - 0x060316D0
 *
 * Car-car collision response — second ordering path.
 *
 * Contains two symbols:
 *   position_lap_display (FUN_0603139C)
 *     Collision impulse calculation for the second car ordering.
 *     Called when car_A is "below" car_B in Y. Computes heading
 *     differences between two cars, looks up collision force from
 *     the force table (sym_0605BCC8), checks height thresholds,
 *     sets collision flags (0x08000000 / 0x20000000) on car structs,
 *     and applies position impulse via sin/cos of the collision angle.
 *     Shares prologue (atan2 call) and epilogue with hud_number_render
 *     via BSR to 0x06031340 and BRA to 0x06031322.
 *
 *   sym_060316C4
 *     Register save wrapper — saves r8-r13, falls through to the
 *     collision response main body in the next TU (collision_order_b).
 *
 * Car struct offsets used:
 *   +0x00 (0)   flags         bit 27 = collision, bit 29 = direction
 *   +0x0C (12)  Y position    vertical ordering + height threshold
 *   +0x10 (16)  X position    impulse target
 *   +0x18 (24)  Z position    impulse target
 *   +0x20 (32)  heading       primary rotation angle
 *   +0x28 (40)  heading2      secondary rotation / validation
 *   +0x30 (48)  heading3      used for angle comparison
 *   +0x38 (56)  X backup      pre-collision X saved here
 *   +0x3C (60)  Z backup      pre-collision Z saved here
 *
 * Key constants:
 *   0x8000      half-circle (heading range)
 *   0x4000      quarter-circle (angle threshold)
 *   0x00042AAA  height threshold (~274K fixed-point)
 *   0x08000000  COLLISION_FLAG (bit 27 of car flags)
 *   0x20000000  DIRECTION_FLAG (bit 29 of car flags)
 *   0x0000D999  crossing offset constant
 *   0x00008000  half rotation (180 degrees) for opposite impulse
 */

    .section .text.FUN_0603139C


    .global position_lap_display
    .type position_lap_display, @function
position_lap_display:
    sts.l pr, @-r15              ! save PR (atan2 call follows)
    jsr @r0                      ! call atan2(dx, dz) — r0 set by caller
    nop                          ! delay slot
    lds.l @r15+, pr              ! restore PR after atan2 return
    neg r0, r11                  ! r11 = -atan2_result (negate angle)
    exts.w r11, r11              ! sign-extend collision angle to 32-bit
    mov.l @r15+, r0              ! restore saved r0 from caller
    mov #0x0, r9                 ! r9 = 0 (crossing flag: no crossing detected)
    mov.w   DAT_0603143a, r4     ! r4 = 0x8000 (half-circle range)
    mov.l @(48, r13), r1         ! r1 = car_B->heading3 (+0x30)
    extu.w r4, r4                ! zero-extend 0x8000 to 32-bit
    exts.w r1, r1                ! sign-extend heading to 32-bit
    mov #0x1, r7                 ! r7 = 1 (side_A flag: assume within range)
    mov r4, r3                   ! r3 = 0x8000
    extu.w r11, r6               ! r6 = collision_angle (unsigned 16-bit)
    shll r3                      ! r3 = 0x10000 (full circle)
    or r3, r6                    ! r6 |= 0x10000 (set wrap bit)
    sub r6, r1                   ! r1 = heading_B - (angle | 0x10000)
    cmp/pl r1                    ! heading diff > 0?
    bt      .L_heading_a_abs     ! yes: already positive
    neg r1, r1                   ! no: take absolute value
.L_heading_a_abs:
    extu.w r1, r1                ! unsigned 16-bit heading diff
    cmp/gt r1, r4                ! diff < 0x8000 (half circle)?
    bt      .L_check_heading_b   ! yes: heading_A within range
    sub r4, r1                   ! reduce by half-circle
    mov #0x0, r7                 ! r7 = 0 (side_A flag: outside range)
.L_check_heading_b:
    mov.l @(48, r13), r1         ! r1 = car_B->heading3 (+0x30) again
    mov #0x1, r8                 ! r8 = 1 (side_B flag: assume within range)
    exts.w r1, r1                ! sign-extend heading
    mov r4, r3                   ! r3 = 0x8000
    shll r3                      ! r3 = 0x10000 (full circle)
    extu.w r10, r6               ! r6 = collision_angle_B (unsigned 16-bit)
    or r3, r6                    ! r6 |= 0x10000 (set wrap bit)
    sub r6, r1                   ! r1 = heading_B - (angle_B | 0x10000)
    cmp/pl r1                    ! heading diff > 0?
    bt/s    .L_heading_b_abs     ! yes: already positive
    mov.l @(48, r14), r2         ! r2 = car_A->heading3 (+0x30) [delay slot]
    neg r1, r1                   ! no: take absolute value
.L_heading_b_abs:
    extu.w r1, r1                ! unsigned 16-bit heading diff
    .byte   0xBF, 0xA9    /* bsr 0x06031340 — angle range check (external) */
    nop                          ! delay slot
    cmp/gt r1, r4                ! diff < 0x8000 (half circle)?
    bt      .L_compare_sides     ! yes: heading_B within range
    sub r4, r1                   ! reduce by half-circle
    mov #0x0, r8                 ! r8 = 0 (side_B flag: outside range)
.L_compare_sides:
    cmp/eq r7, r8                ! side_A == side_B?
    bt      .L_calc_sin          ! yes: same side, no crossing
    mov #0x1, r9                 ! r9 = 1 (crossing detected — cars on opposite sides)
.L_calc_sin:
    mov.l r4, @-r15              ! save r4 (half-circle constant)
    mov r1, r4                   ! r4 = heading diff for sin lookup
    mov.l   .L_pool_sin_lookup, r0 ! r0 = sin_lookup function ptr
    jsr @r0                      ! call sin_lookup(heading_diff)
    nop                          ! delay slot
    mov.l @r15+, r4              ! restore r4 (half-circle constant)
    sub r10, r2                  ! r2 = car_A->heading3 - collision_angle
    extu.w r2, r2                ! unsigned 16-bit
    cmp/gt r2, r4                ! diff < 0x8000?
    bt/s    .L_normalize_heading ! yes: within range
    shlr8 r1                     ! r1 >>= 8 (scale sin result) [delay slot]
    sub r4, r2                   ! reduce by half-circle
.L_normalize_heading:
    shlr r1                      ! r1 >>= 1 (convert to table index range)
    mov #0x0, r7                 ! r7 = 0 (assume out of valid range)
    mov #0xA, r3                 ! r3 = 0xA (lower bound)
    cmp/ge r1, r3                ! r1 < 0xA?
    bt      .L_build_table_index ! yes: skip (below valid range)
    mov #0x37, r3                ! r3 = 0x37 (upper bound)
    cmp/ge r3, r1                ! r1 >= 0x37?
    bt      .L_build_table_index ! yes: skip (above valid range)
    mov #0x1, r7                 ! r7 = 1 (within valid force range)
.L_build_table_index:
    shll2 r1                     ! r1 <<= 2 (index * 4 for .4byte table)
    shlr8 r2                     ! r2 >>= 8 (scale heading diff)
    shlr r2                      ! r2 >>= 1
    shll2 r2                     ! r2 <<= 2 (index * 4 for .4byte table)
    tst r9, r9                   ! crossing flag set?
    bt      .L_force_table_lookup ! no crossing: go to force lookup
    tst r8, r8                   ! side_B flag set?
    bt      .L_set_side_b        ! no: go set side_B = 1
    bra     .L_check_in_range    ! yes: go check range
    mov #0x0, r8                 ! r8 = 0 (clear side_B) [delay slot]

    .global DAT_0603143a
DAT_0603143a:
    .2byte  0x8000                   ! half-circle constant (16-bit)
    .4byte  atan2                    ! pool: atan2 function ptr
.L_pool_sin_lookup:
    .4byte  sin_lookup               ! pool: sin_lookup function ptr
.L_set_side_b:
    mov #0x1, r8                 ! r8 = 1 (set side_B flag)
.L_check_in_range:
    tst r7, r7                   ! within valid force range?
    bt      .L_force_table_lookup ! no: skip to force lookup directly
    bra     .L_check_secondary_heading ! yes: skip force lookup, go to heading check
    mov r12, r4                  ! r4 = collision parameter [delay slot]
.L_force_table_lookup:
    mov.l   .L_pool_force_table, r3 ! r3 = force table base (sym_0605BCC8)
    add r3, r1                   ! r1 = &force_table[index_A]
    add r3, r2                   ! r2 = &force_table[index_B]
    mov.l @r1, r4                ! r4 = force_A = table[index_A]
    sub r12, r4                  ! r4 -= collision_param (adjust force)
    mov.l @r2, r12               ! r12 = force_B = table[index_B]
    add r12, r4                  ! r4 = force_A - param + force_B (net force)
    cmp/pl r4                    ! net force > 0?
    bt      .L_check_secondary_heading ! yes: continue with collision
    .byte   0xAF, 0x5F    /* bra 0x06031322 — epilogue (external): no force, exit */
    nop                          ! delay slot
.L_pool_force_table:
    .4byte  sym_0605BCC8             ! pool: collision force lookup table
.L_check_secondary_heading:
    mov.l @(40, r14), r1         ! r1 = car_A->heading2 (+0x28)
    mov.l @(40, r13), r2         ! r2 = car_B->heading2 (+0x28)
    mov #0x0, r11                ! r11 = 0 (height_crossed flag: no crossing)
    sub r2, r1                   ! r1 = heading2_A - heading2_B
    extu.w r1, r1                ! unsigned 16-bit difference
    mov.w   DAT_06031496, r3     ! r3 = 0x4000 (quarter-circle threshold)
    cmp/ge r1, r3                ! diff < quarter-circle?
    bt      .L_heading_in_range  ! yes: headings close enough
    mov r3, r2                   ! r2 = 0x4000
    shll r2                      ! r2 = 0x8000
    add r2, r3                   ! r3 = 0xC000 (3/4 circle)
    cmp/ge r3, r1                ! diff >= 0xC000?
    bt      .L_heading_in_range  ! yes: wraps around, still in range
    mov #0x1, r11                ! r11 = 1 (height_crossed: out of range)
    mov.l @(12, r14), r1         ! r1 = car_A->Y (+0x0C)
    mov.l @(12, r13), r3         ! r3 = car_B->Y (+0x0C)
    mov.l   .L_pool_height_thresh_a, r2 ! r2 = 0x00042AAA (height threshold)
    add r3, r1                   ! r1 = A.Y + B.Y (combined height)
    mov.l r11, @-r15             ! save height_crossed flag on stack
    cmp/ge r1, r2                ! combined height < threshold?
    bf      .L_set_collision_flag ! no: too high, set collision flag
    bra     .L_flag_dispatch     ! yes: within threshold, skip flag
    nop                          ! delay slot

    .global DAT_06031496
DAT_06031496:
    .2byte  0x4000                   ! quarter-circle threshold (16-bit)
.L_pool_height_thresh_a:
    .4byte  0x00042AAA               ! pool: height threshold (~274K fixed-point)
.L_set_collision_flag:
    mov.l @(0, r13), r1          ! r1 = car_B->flags (+0x00)
    mov.l   .L_pool_collision_flag_a, r3 ! r3 = 0x08000000 (COLLISION_FLAG)
    or r3, r1                    ! set collision bit 27
    mov.l r1, @(0, r13)          ! store updated flags to car_B
    bra     .L_flag_dispatch     ! go to flag dispatch
    nop                          ! delay slot
.L_pool_collision_flag_a:
    .4byte  0x08000000               ! pool: COLLISION_FLAG (bit 27)
.L_heading_in_range:
    mov.l r11, @-r15             ! save height_crossed flag on stack
    mov.l @(12, r13), r1         ! r1 = car_B->Y (+0x0C)
    mov.l @(12, r14), r3         ! r3 = car_A->Y (+0x0C)
    mov.l   .L_pool_height_thresh_b, r2 ! r2 = 0x00042AAA (height threshold)
    sub r3, r1                   ! r1 = B.Y - A.Y (height difference)
    cmp/ge r1, r2                ! height diff < threshold?
    bt      .L_check_force_direction ! yes: check force direction
    mov.l @(0, r13), r1          ! r1 = car_B->flags (+0x00)
    mov.l   .L_pool_collision_flag_b, r3 ! r3 = 0x08000000 (COLLISION_FLAG)
    or r3, r1                    ! set collision bit 27
    mov.l r1, @(0, r13)          ! store updated flags to car_B
    bra     .L_flag_dispatch     ! go to flag dispatch
    nop                          ! delay slot
    .2byte  0x0000               ! alignment padding
.L_pool_height_thresh_b:
    .4byte  0x00042AAA               ! pool: height threshold (~274K fixed-point)
.L_pool_collision_flag_b:
    .4byte  0x08000000               ! pool: COLLISION_FLAG (bit 27)
.L_check_force_direction:
    tst r7, r7                   ! in valid force range?
    bf      .L_check_angle_range ! yes: go check angle range
    mov.l @(12, r14), r1         ! r1 = car_A->Y (+0x0C)
    mov.l   .L_pool_height_thresh_c, r2 ! r2 = 0x00042AAA (height threshold)
    mov.l @(12, r13), r3         ! r3 = car_B->Y (+0x0C)
    shlr r2                      ! r2 = 0x00021555 (half threshold)
    sub r1, r3                   ! r3 = B.Y - A.Y
    cmp/gt r3, r2                ! half_threshold > height_diff?
    bt      .L_check_angle_range ! yes: skip direction flag
    tst r8, r8                   ! side_B flag clear?
    mov.l @(0, r13), r2          ! r2 = car_B->flags (+0x00)
    mov.l   .L_pool_direction_flag, r3 ! r3 = 0x20000000 (DIRECTION_FLAG)
    bt      .L_apply_dir_flag    ! side_B=0: use full flag value
    shlr r3                      ! side_B=1: r3 = 0x10000000 (half flag)
.L_apply_dir_flag:
    or r3, r2                    ! set direction flag on car_B
    bra     .L_flag_dispatch     ! go to flag dispatch
    mov.l r2, @(0, r13)          ! store updated flags [delay slot]
    .2byte  0x0000               ! alignment padding
.L_pool_height_thresh_c:
    .4byte  0x00042AAA               ! pool: height threshold (~274K fixed-point)
.L_pool_direction_flag:
    .4byte  0x20000000               ! pool: DIRECTION_FLAG (bit 29)
.L_check_angle_range:
    mov.l @(40, r13), r3         ! r3 = car_B->heading2 (+0x28)
    sub r10, r3                  ! r3 = heading2_B - collision_angle
    mov.w   DAT_06031516, r2     ! r2 = 0x4000 (quarter-circle threshold)
    extu.w r3, r3                ! unsigned 16-bit
    cmp/ge r3, r2                ! diff < quarter-circle?
    bt      .L_apply_impulse     ! yes: within range, apply impulse
    mov r2, r1                   ! r1 = 0x4000
    shll r1                      ! r1 = 0x8000
    add r1, r2                   ! r2 = 0xC000 (3/4 circle)
    cmp/ge r2, r3                ! diff >= 0xC000?
    bt      .L_apply_impulse     ! yes: wraps around, still in range
    bra     .L_flag_dispatch     ! out of range: skip impulse
    nop                          ! delay slot

    .global DAT_06031516
DAT_06031516:
    .2byte  0x4000                   ! quarter-circle threshold (16-bit)
.L_apply_impulse:
    mov.l r4, @-r15              ! save net force on stack
    mov.l r0, @-r15              ! save r0 on stack
    tst r7, r7                   ! in valid force range?
    bt      .L_compute_cos       ! no: skip heading copy
    mov.l @(32, r13), r4         ! r4 = car_B->heading (+0x20)
    mov.l r4, @(48, r14)         ! car_A->heading3 = car_B->heading (copy heading)
    mov.w   .L_wpool_struct_off_0x208, r1 ! r1 = 0x0208 (struct offset)
    mov #0x8, r2                 ! r2 = 0x8 (collision counter value)
    add r13, r1                  ! r1 = &car_B[0x208] (collision counter field)
    mov.l r2, @r1                ! car_B[0x208] = 8 (set collision counter)
.L_compute_cos:
    mov r3, r4                   ! r4 = angle for cos lookup
    mov.l   .L_pool_cos_lookup_a, r0 ! r0 = cos_lookup function ptr
    jsr @r0                      ! call cos_lookup(angle)
    nop                          ! delay slot
    mov.l @(12, r13), r1         ! r1 = car_B->Y (+0x0C)
    mov.l @(12, r14), r2         ! r2 = car_A->Y (+0x0C)
    sub r2, r1                   ! r1 = B.Y - A.Y (vertical diff)
    dmuls.l r0, r1               ! MACL:MACH = cos(angle) * dY (64-bit)
    sts mach, r0                 ! r0 = high 32 bits
    sts macl, r1                 ! r1 = low 32 bits
    xtrct r0, r1                 ! r1 = middle 32 bits (fixed-point product)
    shar r1                      ! r1 >>= 1 (arithmetic: halve impulse)
    add r1, r2                   ! r2 = A.Y + impulse
    mov.l r2, @(12, r14)         ! store car_A->Y (updated)
    mov.l @(12, r13), r4         ! r4 = car_B->Y (+0x0C)
    mov.w   .L_wpool_struct_off_0x194, r3 ! r3 = 0x0194 (struct offset)
    add r13, r3                  ! r3 = &car_B[0x194] (Y impulse storage)
    sub r1, r4                   ! r4 = B.Y - impulse (opposite reaction)
    mov.l r4, @r3                ! car_B[0x194] = adjusted Y (Newton 3rd law)
    mov.l @r15+, r0              ! restore r0
    mov.l @r15+, r4              ! restore net force
.L_flag_dispatch:
    mov.l @r15+, r11             ! restore height_crossed flag from stack
    tst r7, r7                   ! in valid force range?
    bf      .L_direction_dispatch ! yes: go to direction-dependent dispatch
    mov.l   .L_pool_timer_byte, r5 ! r5 = &collision_timer_byte (sym_0602FD9A)
    mov.b @r5, r3                ! r3 = current timer value
    tst r3, r3                   ! timer already running?
    bf      .L_scale_by_counter  ! yes: skip init, go to scaling
    mov #0x3, r3                 ! r3 = 3 (initial timer value)
    bra     .L_scale_by_counter  ! go to scaling
    mov.b r3, @r5                ! start timer = 3 [delay slot]
.L_wpool_struct_off_0x208:
    .2byte  0x0208                   ! struct offset for collision counter
.L_wpool_struct_off_0x194:
    .2byte  0x0194                   ! struct offset for Y impulse storage
    .2byte  0x0000                   ! alignment padding
.L_pool_cos_lookup_a:
    .4byte  cos_lookup               ! pool: cos_lookup function ptr
.L_pool_timer_byte:
    .4byte  sym_0602FD9A             ! pool: collision timer byte address
.L_direction_dispatch:
    mov.l r0, @-r15              ! save r0 on stack
    mov.l r4, @-r15              ! save net force on stack
    tst r11, r11                 ! height_crossed flag set?
    mov.l   .L_pool_counter_addr, r5 ! r5 = &collision_counter (sym_0602FD98)
    mov.l   .L_pool_crossing_flag, r10 ! r10 = &crossing_flag (sym_06031A24)
    mov.l @(0, r14), r2          ! r2 = car_A->flags (+0x00)
    mov.w @r10, r10              ! r10 = crossing_flag value (16-bit)
    bt      .L_not_crossed       ! height not crossed: branch
    tst r8, r8                   ! side_B flag set?
    bt      .L_crossed_dir_fwd   ! no: crossed, forward direction
    bra     .L_not_crossed_fwd   ! yes: not crossed, forward
    nop                          ! delay slot
.L_pool_counter_addr:
    .4byte  sym_0602FD98             ! pool: collision counter address
.L_pool_crossing_flag:
    .4byte  sym_06031A24             ! pool: crossing flag address
.L_not_crossed:
    tst r8, r8                   ! side_B flag set?
    bt      .L_not_crossed_no_dir ! no: not crossed, no direction
    bra     .L_not_crossed_rev   ! yes: not crossed, reverse direction
    nop                          ! delay slot
.L_crossed_dir_fwd:
    add #0x1, r5                 ! r5++ (use counter+1 byte)
    tst r10, r10                 ! crossing_flag value zero?
    mov #-0x80, r3               ! r3 = 0x80
    extu.b r3, r3                ! r3 = 0x80 (zero-extended)
    bt      .L_store_flags       ! flag=0: use 0x80
    mov.w   .L_wpool_flag_0x200_a, r3 ! flag!=0: r3 = 0x0200
    bra     .L_store_flags       ! go store flags
    nop                          ! delay slot
.L_wpool_flag_0x200_a:
    .2byte  0x0200                   ! flag value for crossed+fwd+active
.L_not_crossed_fwd:
    tst r10, r10                 ! crossing_flag value zero?
    mov #0x40, r3                ! r3 = 0x40 (default)
    bt      .L_store_flags       ! flag=0: use 0x40
    mov.w   .L_wpool_flag_0x100_a, r3 ! flag!=0: r3 = 0x0100
    bra     .L_store_flags       ! go store flags
    nop                          ! delay slot
.L_wpool_flag_0x100_a:
    .2byte  0x0100                   ! flag value for not_crossed+fwd+active
.L_not_crossed_rev:
    add #0x1, r5                 ! r5++ (use counter+1 byte)
    tst r10, r10                 ! crossing_flag value zero?
    mov.w   .L_wpool_flag_0x200_b, r3 ! r3 = 0x0200 (default for inactive)
    bt      .L_store_flags       ! flag=0: use 0x0200
    mov #-0x80, r3               ! flag!=0: r3 = 0x80
    bra     .L_store_flags       ! go store flags
    extu.b r3, r3                ! r3 = 0x80 (zero-extended) [delay slot]
.L_wpool_flag_0x200_b:
    .2byte  0x0200                   ! flag value for not_crossed+rev+inactive
.L_not_crossed_no_dir:
    tst r10, r10                 ! crossing_flag value zero?
    mov.w   .L_wpool_flag_0x100_b, r3 ! r3 = 0x0100 (default for inactive)
    bt      .L_store_flags       ! flag=0: use 0x0100
    mov #0x40, r3                ! flag!=0: r3 = 0x40
.L_store_flags:
    mov.b @r5, r4                ! r4 = collision counter byte
    or r3, r2                    ! r2 = flags | direction_bits
    tst r4, r4                   ! counter already running?
    mov.l r2, @(0, r14)          ! store updated car_A->flags
    bf      .L_restore_and_scale ! yes: skip counter init
    mov #0x3, r4                 ! r4 = 3 (initial counter value)
    mov.b r4, @r5                ! start collision counter = 3
.L_restore_and_scale:
    mov.l @r15+, r4              ! restore net force from stack
    mov.l @r15+, r0              ! restore r0 from stack
    mov.w   .L_wpool_quarter_circle, r3 ! r3 = 0x4000 (quarter-circle)
    tst r8, r8                   ! side_B flag clear?
    mov.l @(48, r13), r10        ! r10 = car_B->heading3 (+0x30)
    bf/s    .L_multiply_force    ! side_B set: skip triple
    extu.w r10, r10              ! unsigned 16-bit [delay slot]
    mov r3, r7                   ! r7 = 0x4000
    shll r7                      ! r7 = 0x8000
    add r7, r3                   ! r3 = 0xC000 (3/4 circle)
.L_multiply_force:
    dmuls.l r0, r4               ! MACL:MACH = r0 * net_force (64-bit)
    add r3, r10                  ! r10 = heading3 + angle_offset
    tst r9, r9                   ! crossing flag set?
    sts mach, r0                 ! r0 = high 32 bits
    sts macl, r4                 ! r4 = low 32 bits
    xtrct r0, r4                 ! r4 = middle 32 (fixed-point product)
    bt      .L_scale_by_counter  ! no crossing: skip offset
    mov.l   .L_pool_crossing_offset, r3 ! r3 = 0x0000D999 (crossing offset)
    add r3, r4                   ! r4 += crossing offset
.L_scale_by_counter:
    mov.w   DAT_0603162e, r3     ! r3 = 0x007C (struct offset for counter)
    add r14, r3                  ! r3 = &car_A[0x7C] (collision counter)
    mov.w @r3, r0                ! r0 = counter value (16-bit)
    mov #0x8, r5                 ! r5 = 8 (high threshold)
    cmp/ge r5, r0                ! counter >= 8?
    bt      .L_force_zero_forward ! yes: zero the forward component
    add #-0x2, r5               ! r5 = 6 (mid threshold)
    cmp/ge r5, r0                ! counter >= 6?
    bt      .L_force_zero_lateral ! yes: zero the lateral component
    shlr r4                      ! r4 >>= 1 (halve force)
    mov r4, r3                   ! r3 = r4
    shlr r3                      ! r3 >>= 1 (quarter force)
    add r3, r4                   ! r4 = r4/2 + r4/4 = 3/4 force (scale by 0.75)
    bra     .L_apply_position_impulse ! go apply impulse
    mov.l r4, @-r15              ! push forward force [delay slot]
.L_wpool_flag_0x100_b:
    .2byte  0x0100                   ! flag value for not_crossed+no_dir+inactive
.L_wpool_quarter_circle:
    .2byte  0x4000                   ! quarter-circle constant (16-bit)

    .global DAT_0603162e
DAT_0603162e:
    .2byte  0x007C                   ! struct offset for collision counter
.L_pool_crossing_offset:
    .4byte  0x0000D999               ! pool: crossing offset constant
.L_force_zero_lateral:
    mov #0x0, r3                 ! r3 = 0 (zero lateral force)
    bra     .L_apply_position_impulse ! go apply impulse
    mov.l r4, @-r15              ! push forward force [delay slot]
.L_force_zero_forward:
    mov r4, r3                   ! r3 = forward force (becomes lateral)
    mov #0x0, r4                 ! r4 = 0 (zero forward force)
    mov.l r4, @-r15              ! push zero forward force
.L_apply_position_impulse:
    /* === Apply impulse to car_A (XZ plane) === */
    neg r10, r4                  ! r4 = -collision_angle (for trig arg)
    mov r3, r9                   ! r9 = lateral force magnitude
    mov.l @(16, r14), r5         ! r5 = car_A->X (+0x10)
    mov.l @(24, r14), r6         ! r6 = car_A->Z (+0x18)
    mov.l r5, @(56, r14)         ! car_A->X_backup (+0x38) = pre-collision X
    mov.l r6, @(60, r14)         ! car_A->Z_backup (+0x3C) = pre-collision Z
    mov.l   .L_pool_cos_lookup_b, r0 ! r0 = cos_lookup function ptr
    jsr @r0                      ! call cos_lookup(-angle)
    nop                          ! delay slot
    mov r0, r8                   ! r8 = cos(-angle)
    neg r10, r4                  ! r4 = -collision_angle (for sin arg)
    mov.l   .L_pool_sin_lookup_b, r0 ! r0 = sin_lookup function ptr
    jsr @r0                      ! call sin_lookup(-angle)
    nop                          ! delay slot
    dmuls.l r0, r3               ! MACL:MACH = sin * forward_force (64-bit)
    sts mach, r11                ! r11 = high 32 bits
    sts macl, r3                 ! r3 = low 32 bits
    xtrct r11, r3                ! r3 = fixed-point X impulse
    add r3, r5                   ! r5 = A.X + X_impulse
    mov.l r5, @(16, r14)         ! store car_A->X (updated)
    dmuls.l r8, r9               ! MACL:MACH = cos * lateral_force (64-bit)
    sts mach, r8                 ! r8 = high 32 bits
    sts macl, r9                 ! r9 = low 32 bits
    xtrct r8, r9                 ! r9 = fixed-point Z impulse
    add r9, r6                   ! r6 = A.Z + Z_impulse
    mov.l r6, @(24, r14)         ! store car_A->Z (updated)
    /* === Apply opposite impulse to car_B (Newton 3rd law) === */
    mov.l @r15+, r3              ! restore forward force from stack
    mov.l   .L_fp_half, r5       ! r5 = 0x00008000 (half rotation = 180 deg)
    mov r3, r4                   ! r4 = forward force
    shlr r3                      ! r3 = force / 2
    add r4, r3                   ! r3 = force + force/2 = 1.5x force (car_B gets more)
    add r5, r10                  ! r10 += 0x8000 (rotate angle by 180 deg)
    neg r10, r4                  ! r4 = -(angle + 180) for trig arg
    mov r3, r9                   ! r9 = scaled force for car_B
    mov.l @(16, r13), r5         ! r5 = car_B->X (+0x10)
    mov.l @(24, r13), r6         ! r6 = car_B->Z (+0x18)
    mov.l r5, @(56, r13)         ! car_B->X_backup (+0x38) = pre-collision X
    mov.l r6, @(60, r13)         ! car_B->Z_backup (+0x3C) = pre-collision Z
    mov.l   .L_pool_cos_lookup_b, r0 ! r0 = cos_lookup function ptr
    jsr @r0                      ! call cos_lookup(-(angle+180))
    nop                          ! delay slot
    mov r0, r8                   ! r8 = cos(-(angle+180))
    neg r10, r4                  ! r4 = -(angle+180) for sin arg
    mov.l   .L_pool_sin_lookup_b, r0 ! r0 = sin_lookup function ptr
    jsr @r0                      ! call sin_lookup(-(angle+180))
    nop                          ! delay slot
    dmuls.l r0, r3               ! MACL:MACH = sin * force (64-bit)
    sts mach, r11                ! r11 = high 32 bits
    sts macl, r3                 ! r3 = low 32 bits
    xtrct r11, r3                ! r3 = fixed-point X impulse (opposite)
    add r3, r5                   ! r5 = B.X + opposite_X_impulse
    mov.l r5, @(16, r13)         ! store car_B->X (updated)
    dmuls.l r8, r9               ! MACL:MACH = cos * force (64-bit)
    sts mach, r8                 ! r8 = high 32 bits
    sts macl, r9                 ! r9 = low 32 bits
    xtrct r8, r9                 ! r9 = fixed-point Z impulse (opposite)
    add r9, r6                   ! r6 = B.Z + opposite_Z_impulse
    .byte   0xAE, 0x36    /* bra 0x06031322 — epilogue (external): done, exit */
    mov.l r6, @(24, r13)         ! store car_B->Z (updated) [delay slot]
    .2byte  0x0000               ! alignment padding
.L_pool_cos_lookup_b:
    .4byte  cos_lookup               ! pool: cos_lookup function ptr
.L_pool_sin_lookup_b:
    .4byte  sin_lookup               ! pool: sin_lookup function ptr
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) / half rotation */

    /* sym_060316C4 — Register save wrapper for collision response main body.
     * Saves r8-r13 (callee-saved), falls through to next TU (collision_order_b).
     */
    .global sym_060316C4
sym_060316C4:
    mov.l r8, @-r15              ! save r8 (callee-saved)
    mov.l r9, @-r15              ! save r9 (callee-saved)
    mov.l r10, @-r15             ! save r10 (callee-saved)
    mov.l r11, @-r15             ! save r11 (callee-saved)
    mov.l r12, @-r15             ! save r12 (callee-saved)
    mov.l r13, @-r15             ! save r13 (callee-saved)
    /* falls through to collision_order_b (FUN_060316D0) */
