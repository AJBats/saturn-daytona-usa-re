/* speed_tacho_display -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06031E00 - 0x060321C0
 *
 * Speed/tachometer gauge display pipeline.
 *
 * Main function iterates over a set of display elements (24-byte entries),
 * transforms their 3D positions through camera rotation matrices using
 * MAC (multiply-accumulate) operations, performs screen-space bounds
 * checking, and dispatches to one of five blend/combine modes via a
 * jump table (average, min, max, max+offset variants).
 *
 * The results are written as 16-bit sprite indices into the sprite
 * index lookup table (sym_0606A4F8), indexed by the timing accumulator
 * (sym_060620D4).
 *
 * Second function (sym_06032158) is a batched matrix-vector transform
 * that multiplies vertex positions by a 3x3 rotation matrix with
 * translation, storing results into the display element table.
 *
 * Data:
 *   sym_06032108 (32B) - display coordinate scratch buffer (8 words)
 *   sym_06032128 (16B) - transform results array (4 longs)
 *   sym_06032138 (12B) - temporary rotation vector
 *   sym_06032144 (20B) - blend mode jump table (5 entries)
 */

    .section .text.FUN_06031E00


    .global speed_tacho_display
    .type speed_tacho_display, @function
speed_tacho_display:
    mov.l r14, @-r15                    ! save r14 (loop counter)
    sts.l pr, @-r15                     ! save return address
    mov #0x18, r0                       ! r0 = 0x18 (24 = sizeof display element)
    mul.l r6, r0                        ! MACL = count * 24
    mov r4, r8                          ! r8 = display element array base
    mov r5, r10                         ! r10 = palette/group index
    mov r6, r14                         ! r14 = element count (loop counter)
    sts macl, r0                        ! r0 = count * 24 (total byte offset)
    add r0, r8                          ! r8 = ptr past end of array (iterate backward)
    mov.l   .L_pool_results_array, r13  ! r13 -> results array (4 transformed values)
    mov.l   .L_pool_coord_scratch, r11  ! r11 -> coord scratch buffer (8 X/Y pairs)
.L_element_loop:
    add #-0x18, r8                      ! r8 -= 24 (advance to previous element)
    mov.w @(16, r8), r0                 ! r0 = elem[8].w — element type index A
    mov #0xC, r3                        ! r3 = 0xC (12 = sizeof elem_table entry)
    mulu.w r0, r3                       ! MACL = type_index * 12
    mov.w   DAT_06031e30, r12           ! r12 = 0xFF00 (base offset / mask)
    mov.l   .L_pool_elem_table, r3      ! r3 -> display element table base
    sts macl, r7                        ! r7 = type_index * 12
    add r3, r7                          ! r7 -> elem_table[type_index]
    mov.l @(8, r7), r3                  ! r3 = elem_table[type_index].visibility
    cmp/pl r3                           ! visibility > 0?
    bt      .L_elem_visible             ! yes — process this element
    bra     .L_next_element             ! no — skip to next element
    nop                                 ! (delay slot)

    .global DAT_06031e30
DAT_06031e30:
    .2byte  0xFF00                      ! signed word constant: -256 (base offset)
    .2byte  0x0000                      ! alignment padding
.L_pool_results_array:
    .4byte  sym_06032128                ! -> transform results (4 longs)
.L_pool_coord_scratch:
    .4byte  sym_06032108                ! -> coordinate scratch (8 X/Y pairs)
.L_pool_elem_table:
    .4byte  sym_060961A8                ! -> display element table (12-byte entries)
.L_elem_visible:
    mov.w   .L_wpool_elem_cmd_a0, r0   ! r0 = 0x00A0 (element display command)
    mov.l r0, @(16, r12)               ! elem_out[4] = display command
    mov.l r3, @(0, r12)                ! elem_out[0] = visibility value
    mov #0x0, r0                       ! r0 = 0
    mov.l r0, @(20, r12)               ! elem_out[5] = 0 (clear extra field)
    mov.l r3, @r13                     ! results[0] = visibility value
    mov.w @(12, r8), r0                ! r0 = elem[6].w — flags word
    mov r8, r4                         ! r4 = current element ptr (for MAC)
    tst #0x8, r0                       ! test bit 3 of flags
    bf      .L_setup_axis1             ! bit 3 set — skip camera transform
    ! --- Camera rotation: multiply element XYZ by 3x3 matrix ---
    mov.l   .L_pool_temp_rotation, r5  ! r5 -> temp rotation output
    mov.l   .L_pool_camera_matrix, r0  ! r0 -> camera matrix pointer
    mov.l @r0, r9                      ! r9 -> camera matrix data
    clrmac                             ! clear MAC for row 0
    mac.l @r4+, @r9+                   ! MAC += elem.x * mat[0][0]
    mac.l @r4+, @r9+                   ! MAC += elem.y * mat[0][1]
    mac.l @r4+, @r9+                   ! MAC += elem.z * mat[0][2]
    add #-0xC, r4                      ! rewind element ptr to start
    sts mach, r0                       ! r0 = MAC high (row 0 result high)
    sts macl, r1                       ! r1 = MAC low (row 0 result low)
    clrmac                             ! clear MAC for row 1
    mac.l @r4+, @r9+                   ! MAC += elem.x * mat[1][0]
    xtrct r0, r1                       ! r1 = 16.16 fixpt result of row 0
    mov.l r1, @r5                      ! temp_rot[0] = rotated X
    mac.l @r4+, @r9+                   ! MAC += elem.y * mat[1][1]
    mac.l @r4+, @r9+                   ! MAC += elem.z * mat[1][2]
    add #-0xC, r4                      ! rewind element ptr to start
    sts mach, r0                       ! r0 = MAC high (row 1 result high)
    sts macl, r1                       ! r1 = MAC low (row 1 result low)
    clrmac                             ! clear MAC for row 2
    mac.l @r4+, @r9+                   ! MAC += elem.x * mat[2][0]
    xtrct r0, r1                       ! r1 = 16.16 fixpt result of row 1
    mov.l r1, @(4, r5)                 ! temp_rot[1] = rotated Y
    mac.l @r4+, @r9+                   ! MAC += elem.y * mat[2][1]
    mac.l @r4+, @r9+                   ! MAC += elem.z * mat[2][2]
    add #-0x24, r9                     ! rewind matrix ptr to start (36 bytes)
    sts mach, r0                       ! r0 = MAC high (row 2 result high)
    sts macl, r1                       ! r1 = MAC low (row 2 result low)
    xtrct r0, r1                       ! r1 = 16.16 fixpt result of row 2
    mov.l r1, @(8, r5)                 ! temp_rot[2] = rotated Z
    ! --- Dot product: elem_table normal dot rotated position ---
    mov r7, r4                         ! r4 -> elem_table[type_index] (normal vector)
    clrmac                             ! clear MAC for dot product
    mac.l @r4+, @r5+                   ! MAC += normal.x * rot.x
    mac.l @r4+, @r5+                   ! MAC += normal.y * rot.y
    mac.l @r4+, @r5+                   ! MAC += normal.z * rot.z
    sts mach, r1                       ! r1 = dot product high
    sts macl, r0                       ! r0 = dot product low
    xtrct r1, r0                       ! r0 = 16.16 fixpt dot product
    cmp/pl r0                          ! dot product > 0? (facing camera)
    bt      .L_setup_axis1             ! yes — continue processing
    bra     .L_next_element            ! no — backface, skip element
    nop                                ! (delay slot)
.L_wpool_elem_cmd_a0:
    .2byte  0x00A0                      ! display command: 0x00A0
    .2byte  0x0000                      ! alignment padding
.L_pool_temp_rotation:
    .4byte  sym_06032138                ! -> temp rotation vector (3 longs)
.L_pool_camera_matrix:
    .4byte  sym_0608A52C                ! -> camera rotation matrix pointer
.L_setup_axis1:
    ! --- Axis 1: transform and project first coordinate pair ---
    mov r11, r5                        ! r5 -> coord scratch buffer (output)
    mov.l @(4, r7), r2                 ! r2 = elem_table[type].normal_y
    mov.l @r7, r1                      ! r1 = elem_table[type].normal_x
    mov.l @(28, r12), r4               ! r4 = elem_out[7] (scale factor)
    mov.w @(18, r8), r0                ! r0 = elem[9].w — element type index B
    mov #0xC, r3                       ! r3 = 0xC (12)
    mulu.w r0, r3                      ! MACL = type_index_B * 12
    mov.l   .L_pool_elem_table_b, r3   ! r3 -> element table base
    sts macl, r7                       ! r7 = type_index_B * 12
    add r3, r7                         ! r7 -> elem_table[type_index_B]
    mov.l @(8, r7), r3                 ! r3 = elem_table[type_B].visibility
    mov.w   DAT_06031eee, r0           ! r0 = 0x00A0 (display command)
    mov.l r0, @(16, r12)               ! elem_out[4] = display command
    mov.l r3, @(0, r12)                ! elem_out[0] = visibility
    mov #0x0, r0                       ! r0 = 0
    mov.l r0, @(20, r12)               ! elem_out[5] = 0
    dmuls.l r1, r4                     ! MACH:MACL = normal_x * scale
    neg r2, r2                         ! r2 = -normal_y
    sts mach, r1                       ! r1 = (normal_x * scale) >> 32 → screen X
    dmuls.l r2, r4                     ! MACH:MACL = -normal_y * scale
    mov.l r1, @r5                      ! scratch[0] = screen X
    sts mach, r2                       ! r2 = (-normal_y * scale) >> 32 → screen Y
    mov.l r2, @(4, r5)                 ! scratch[1] = screen Y
    bsr     .L_bounds_check            ! call bounds check (r1=X, r2=Y)
    nop                                ! (delay slot)
    cmp/pl r3                          ! bounds check passed? (r3 > 0)
    bt      .L_axis1_passed            ! yes — continue to axis 2
    bra     .L_next_element            ! no — skip element
    nop                                ! (delay slot)

    .global DAT_06031eee
DAT_06031eee:
    .2byte  0x00A0                      ! display command constant
.L_pool_elem_table_b:
    .4byte  sym_060961A8                ! -> display element table
.L_axis1_passed:
    ! --- Axis 2: transform and project second coordinate pair ---
    mov.l r3, @(4, r13)               ! results[1] = axis 1 visibility
    add #0x8, r5                       ! r5 += 8 (advance scratch ptr to pair 2)
    mov.l @(4, r7), r2                 ! r2 = elem_table[type_B].normal_y
    mov.l @r7, r1                      ! r1 = elem_table[type_B].normal_x
    mov.l @(28, r12), r4               ! r4 = scale factor
    mov.w @(20, r8), r0                ! r0 = elem[10].w — element type index C
    mov #0xC, r3                       ! r3 = 0xC (12)
    mulu.w r0, r3                      ! MACL = type_index_C * 12
    mov.l   .L_pool_elem_table_c, r3   ! r3 -> element table base
    sts macl, r7                       ! r7 = type_index_C * 12
    add r3, r7                         ! r7 -> elem_table[type_index_C]
    mov.l @(8, r7), r3                 ! r3 = elem_table[type_C].visibility
    mov.w   .L_wpool_elem_cmd_a0_b, r0 ! r0 = 0x00A0 (display command)
    mov.l r0, @(16, r12)               ! elem_out[4] = display command
    mov.l r3, @(0, r12)                ! elem_out[0] = visibility
    mov #0x0, r0                       ! r0 = 0
    mov.l r0, @(20, r12)               ! elem_out[5] = 0
    dmuls.l r1, r4                     ! MACH:MACL = normal_x * scale
    neg r2, r2                         ! r2 = -normal_y
    sts mach, r1                       ! r1 = screen X
    dmuls.l r2, r4                     ! MACH:MACL = -normal_y * scale
    mov.l r1, @r5                      ! scratch[2] = screen X
    sts mach, r2                       ! r2 = screen Y
    mov.l r2, @(4, r5)                 ! scratch[3] = screen Y
    bsr     .L_bounds_check            ! call bounds check
    nop                                ! (delay slot)
    cmp/pl r3                          ! bounds check passed?
    bt      .L_axis2_passed            ! yes — continue to axis 3
    bra     .L_next_element            ! no — skip element
    nop                                ! (delay slot)
.L_wpool_elem_cmd_a0_b:
    .2byte  0x00A0                      ! display command constant
    .2byte  0x0000                      ! alignment padding
.L_pool_elem_table_c:
    .4byte  sym_060961A8                ! -> display element table
.L_axis2_passed:
    ! --- Axis 3: transform and project third coordinate pair ---
    mov.l r3, @(8, r13)               ! results[2] = axis 2 visibility
    add #0x8, r5                       ! r5 += 8 (advance scratch ptr to pair 3)
    mov.l @(4, r7), r2                 ! r2 = elem_table[type_C].normal_y
    mov.l @r7, r1                      ! r1 = elem_table[type_C].normal_x
    mov.l @(28, r12), r4               ! r4 = scale factor
    mov.w @(22, r8), r0                ! r0 = elem[11].w — element type index D
    mov #0xC, r3                       ! r3 = 0xC (12)
    mulu.w r0, r3                      ! MACL = type_index_D * 12
    mov.l   .L_pool_elem_table_d, r3   ! r3 -> element table base
    sts macl, r7                       ! r7 = type_index_D * 12
    add r3, r7                         ! r7 -> elem_table[type_index_D]
    mov.l @(8, r7), r3                 ! r3 = elem_table[type_D].visibility
    mov.w   .L_wpool_elem_cmd_a0_c, r0 ! r0 = 0x00A0 (display command)
    mov.l r0, @(16, r12)               ! elem_out[4] = display command
    mov.l r3, @(0, r12)                ! elem_out[0] = visibility
    mov #0x0, r0                       ! r0 = 0
    mov.l r0, @(20, r12)               ! elem_out[5] = 0
    dmuls.l r1, r4                     ! MACH:MACL = normal_x * scale
    neg r2, r2                         ! r2 = -normal_y
    sts mach, r1                       ! r1 = screen X
    dmuls.l r2, r4                     ! MACH:MACL = -normal_y * scale
    mov.l r1, @r5                      ! scratch[4] = screen X
    sts mach, r2                       ! r2 = screen Y
    mov.l r2, @(4, r5)                 ! scratch[5] = screen Y
    bsr     .L_bounds_check            ! call bounds check
    nop                                ! (delay slot)
    cmp/pl r3                          ! bounds check passed?
    bt      .L_axis3_passed            ! yes — continue to axis 4
    bra     .L_next_element            ! no — skip element
    nop                                ! (delay slot)
.L_wpool_elem_cmd_a0_c:
    .2byte  0x00A0                      ! display command constant
    .2byte  0x0000                      ! alignment padding
.L_pool_elem_table_d:
    .4byte  sym_060961A8                ! -> display element table
.L_axis3_passed:
    ! --- Axis 4: transform last pair (no elem_table lookup needed) ---
    mov.l r3, @(12, r13)              ! results[3] = axis 3 visibility
    add #0x8, r5                       ! r5 += 8 (advance scratch ptr to pair 4)
    mov.l @(4, r7), r2                 ! r2 = elem_table[type_D].normal_y
    mov.l @r7, r1                      ! r1 = elem_table[type_D].normal_x
    mov.l @(28, r12), r4               ! r4 = scale factor
    dmuls.l r1, r4                     ! MACH:MACL = normal_x * scale
    neg r2, r2                         ! r2 = -normal_y
    sts mach, r1                       ! r1 = screen X
    dmuls.l r2, r4                     ! MACH:MACL = -normal_y * scale
    mov.l r1, @r5                      ! scratch[6] = screen X
    sts mach, r2                       ! r2 = screen Y
    mov.l r2, @(4, r5)                 ! scratch[7] = screen Y
    bsr     .L_bounds_check            ! call bounds check
    nop                                ! (delay slot)
    ! --- All 4 axes passed — compute sprite table entry ---
    mov.l   .L_pool_timing_accum, r0   ! r0 -> timing accumulator
    mov #0x18, r1                      ! r1 = 0x18 (24 = sizeof sprite entry)
    mov.l @r0, r0                      ! r0 = current timing index
    mul.l r0, r1                       ! MACL = timing_index * 24
    mov.l   .L_pool_sprite_table, r2   ! r2 -> sprite data table base
    sts macl, r9                       ! r9 = timing_index * 24
    add r2, r9                         ! r9 -> sprite_table[timing_index]
    mov.w   .L_wpool_neg_threshold, r12 ! r12 = -176 (left screen boundary)
    ! --- Screen clipping: check all 4 X coordinates against left ---
    mov.l @(0, r11), r0                ! r0 = scratch[0].x (coord pair 1 X)
    mov.l @(8, r11), r2                ! r2 = scratch[1].x (coord pair 2 X)
    mov.l @(16, r11), r4               ! r4 = scratch[2].x (coord pair 3 X)
    mov.l @(24, r11), r6               ! r6 = scratch[3].x (coord pair 4 X)
    cmp/gt r0, r12                     ! -176 > X0? (X0 off left?)
    bf      .L_check_right_bound       ! no — at least one X in range
    cmp/gt r2, r12                     ! -176 > X1?
    bf      .L_check_right_bound       ! no
    cmp/gt r4, r12                     ! -176 > X2?
    bf      .L_check_right_bound       ! no
    cmp/gt r6, r12                     ! -176 > X3?
    bf      .L_check_right_bound       ! no
    bra     .L_next_element            ! all 4 off left — skip entirely
    nop                                ! (delay slot)
.L_wpool_neg_threshold:
    .2byte  0xFF50                      ! signed: -176 (left screen boundary)
    .2byte  0x0000                      ! alignment padding
.L_pool_timing_accum:
    .4byte  sym_060620D4                ! -> timing accumulator (sprite count)
.L_pool_sprite_table:
    .4byte  sym_0608AC20                ! -> sprite data table (24-byte entries)
.L_check_right_bound:
    ! --- Check all 4 X coordinates against right screen boundary ---
    mov.w   .L_wpool_screen_right, r12 ! r12 = 176 (right screen boundary)
    cmp/gt r0, r12                     ! 176 > X0? (X0 within right bound?)
    bt      .L_check_y_bounds          ! yes — proceed to Y check
    cmp/gt r2, r12                     ! 176 > X1?
    bt      .L_check_y_bounds          ! yes
    cmp/gt r4, r12                     ! 176 > X2?
    bt      .L_check_y_bounds          ! yes
    cmp/gt r6, r12                     ! 176 > X3?
    bt      .L_next_element            ! all 4 off right — skip entirely
.L_check_y_bounds:
    ! --- Check all 4 Y coordinates against top screen boundary ---
    mov.w   .L_wpool_screen_top, r12   ! r12 = -127 (top screen boundary)
    mov.l @(4, r11), r1                ! r1 = scratch[0].y (coord pair 1 Y)
    mov.l @(12, r11), r3               ! r3 = scratch[1].y (coord pair 2 Y)
    mov.l @(20, r11), r5               ! r5 = scratch[2].y (coord pair 3 Y)
    mov.l @(28, r11), r7               ! r7 = scratch[3].y (coord pair 4 Y)
    cmp/gt r1, r12                     ! -127 > Y0? (Y0 off top?)
    bf      .L_check_y_lower           ! no — check bottom boundary
    cmp/gt r3, r12                     ! -127 > Y1?
    bf      .L_check_y_lower           ! no
    cmp/gt r5, r12                     ! -127 > Y2?
    bf      .L_check_y_lower           ! no
    cmp/gt r7, r12                     ! -127 > Y3?
    bt      .L_next_element            ! all 4 off top — skip entirely
.L_check_y_lower:
    ! --- Check all 4 Y coordinates against bottom screen boundary ---
    mov.w   .L_wpool_screen_bottom, r12 ! r12 = 81 (bottom screen boundary)
    cmp/gt r1, r12                     ! 81 > Y0? (Y0 within bottom?)
    bt      .L_write_sprite_entry      ! yes — at least one Y in range
    cmp/gt r3, r12                     ! 81 > Y1?
    bt      .L_write_sprite_entry      ! yes
    cmp/gt r5, r12                     ! 81 > Y2?
    bt      .L_write_sprite_entry      ! yes
    cmp/gt r7, r12                     ! 81 > Y3?
    bf      .L_next_element            ! all 4 off bottom — skip entirely
.L_write_sprite_entry:
    ! --- Write 8 coordinate words into sprite table entry ---
    mov r9, r12                        ! r12 = sprite entry base
    add #0x18, r12                     ! r12 = past end of entry (write backward)
    mov.w r7, @-r12                    ! sprite[11] = Y3
    mov.w r6, @-r12                    ! sprite[10] = X3
    mov.w r5, @-r12                    ! sprite[9] = Y2
    mov.w r4, @-r12                    ! sprite[8] = X2
    mov.w r3, @-r12                    ! sprite[7] = Y1
    mov.w r2, @-r12                    ! sprite[6] = X1
    mov.w r1, @-r12                    ! sprite[5] = Y0
    mov.w r0, @-r12                    ! sprite[4] = X0
    mov.w @(14, r8), r0                ! r0 = elem[7].w — texture/color index
    mov.w r0, @(6, r9)                 ! sprite[3] = texture/color index
    mov.w @(12, r8), r0                ! r0 = elem[6].w — flags word
    shlr2 r0                           ! r0 >>= 2
    shlr2 r0                           ! r0 >>= 2 (total >>= 4)
    and #0xF, r0                       ! r0 = (flags >> 4) & 0xF — draw priority
    mov.b r0, @(4, r9)                 ! sprite[4].b = draw priority
    mov r10, r0                        ! r0 = palette/group index
    mov.b r0, @(5, r9)                 ! sprite[5].b = palette/group index
    ! --- Dispatch to blend mode via jump table ---
    mov.w @(12, r8), r0                ! r0 = elem[6].w — flags word (reload)
    mov.l   .L_pool_blend_jumptbl, r1  ! r1 -> blend mode jump table
    and #0x7, r0                       ! r0 = flags & 0x7 — blend mode (0-4)
    shll2 r0                           ! r0 *= 4 (index to table offset)
    mov.l @(r0, r1), r0                ! r0 = jump_table[blend_mode]
    mov.l @(0, r13), r3                ! r3 = results[0] (visibility axis 0)
    mov.l @(4, r13), r4                ! r4 = results[1] (visibility axis 1)
    mov.l @(8, r13), r5                ! r5 = results[2] (visibility axis 2)
    jmp @r0                            ! jump to blend mode handler
    mov.l @(12, r13), r6              ! r6 = results[3] (visibility axis 3) (delay)
.L_wpool_screen_right:
    .2byte  0x00B0                      ! signed: +176 (right screen boundary)
.L_wpool_screen_top:
    .2byte  0xFF81                      ! signed: -127 (top screen boundary)
.L_wpool_screen_bottom:
    .2byte  0x0051                      ! signed: +81 (bottom screen boundary)
    .2byte  0x0000                      ! alignment padding
.L_pool_blend_jumptbl:
    .4byte  sym_06032144                ! -> blend mode jump table (5 entries)

    ! === Blend mode 0: Average of all 4 axes ===
    .global loc_06032054
loc_06032054:
    add r4, r3                         ! r3 = axis0 + axis1
    add r5, r6                         ! r6 = axis2 + axis3
    add r6, r3                         ! r3 = axis0 + axis1 + axis2 + axis3
    bra     .L_store_sprite_result     ! store result
    shlr2 r3                           ! r3 /= 4 (average) (delay slot)

    ! === Blend mode 1: Minimum of all 4 axes ===
    .global loc_0603205E
loc_0603205E:
    cmp/ge r3, r4                      ! axis1 >= axis0?
    bt      .L_min_skip_1              ! yes — keep r3
    mov r4, r3                         ! no — r3 = axis1 (smaller)
.L_min_skip_1:
    cmp/ge r3, r5                      ! axis2 >= current min?
    bt      .L_min_skip_2              ! yes — keep r3
    mov r5, r3                         ! no — r3 = axis2
.L_min_skip_2:
    cmp/ge r3, r6                      ! axis3 >= current min?
    bt      .L_min_done                ! yes — keep r3
    mov r6, r3                         ! no — r3 = axis3
.L_min_done:
    bra     .L_store_sprite_result     ! store result
    nop                                ! (delay slot)

    ! === Blend mode 2: Maximum of all 4 axes ===
    .global loc_06032074
loc_06032074:
    cmp/gt r3, r4                      ! axis1 > axis0?
    bf      .L_max_skip_1              ! no — keep r3
    mov r4, r3                         ! yes — r3 = axis1 (larger)
.L_max_skip_1:
    cmp/gt r3, r5                      ! axis2 > current max?
    bf      .L_max_skip_2              ! no — keep r3
    mov r5, r3                         ! yes — r3 = axis2
.L_max_skip_2:
    cmp/gt r3, r6                      ! axis3 > current max?
    bf      .L_max_done                ! no — keep r3
    mov r6, r3                         ! yes — r3 = axis3
.L_max_done:
    bra     .L_store_sprite_result     ! store result
    nop                                ! (delay slot)

    ! === Blend mode 3: Maximum + small offset (0x00200000) ===
    .global loc_0603208A
loc_0603208A:
    mov #0x20, r0                      ! r0 = 0x20
    bra     .L_maxofs_body             ! jump to max+offset body
    shll16 r0                          ! r0 = 0x00200000 (delay slot)

    ! === Blend mode 4: Maximum + large offset (0x00400000) ===
    .global loc_06032090
loc_06032090:
    mov.l   .L_pool_max_offset, r0     ! r0 = 0x00400000 (large offset)
.L_maxofs_body:
    cmp/gt r3, r4                      ! axis1 > axis0?
    bf      .L_maxofs_skip_1           ! no — keep r3
    mov r4, r3                         ! yes — r3 = axis1
.L_maxofs_skip_1:
    cmp/gt r3, r5                      ! axis2 > current max?
    bf      .L_maxofs_skip_2           ! no — keep r3
    mov r5, r3                         ! yes — r3 = axis2
.L_maxofs_skip_2:
    cmp/gt r3, r6                      ! axis3 > current max?
    bf      .L_maxofs_add              ! no — keep r3
    mov r6, r3                         ! yes — r3 = axis3
.L_maxofs_add:
    add r0, r3                         ! r3 = max + offset
.L_store_sprite_result:
    ! --- Store blended result as sprite index ---
    mov.l   .L_pool_timing_accum_b, r2 ! r2 -> timing accumulator
    neg r3, r3                         ! r3 = -result (negate for depth sort)
    mov.l   .L_pool_sprite_idx_tbl, r1 ! r1 -> sprite index lookup table
    shlr8 r3                           ! r3 >>= 8
    mov.l @r2, r0                      ! r0 = current sprite count
    shlr2 r3                           ! r3 >>= 2
    shlr2 r3                           ! r3 >>= 2 (total >>= 12: fixpt to int)
    shll r0                            ! r0 *= 2 (word index to byte offset)
    mov.w r3, @(r0, r1)               ! sprite_idx_table[count] = depth value
    shar r0                            ! r0 /= 2 (restore count)
    add #0x1, r0                       ! r0 = count + 1
    mov.l r0, @r2                      ! timing_accum = count + 1
.L_next_element:
    dt r14                             ! r14-- (decrement element counter); T = (r14 == 0)
    bt      .L_epilogue                ! no more elements — exit
    bra     .L_element_loop            ! loop back for next element
    nop                                ! (delay slot)
    .2byte  0x0000                     ! alignment padding
.L_pool_max_offset:
    .4byte  0x00400000                  ! large depth offset for blend mode 4
.L_pool_timing_accum_b:
    .4byte  sym_060620D4                ! -> timing accumulator (sprite count)
.L_pool_sprite_idx_tbl:
    .4byte  sym_0606A4F8                ! -> sprite index lookup table (words)
.L_epilogue:
    lds.l @r15+, pr                    ! restore return address
    mov.l @r15+, r14                   ! restore r14
    mov.l @r15+, r13                   ! restore r13
    mov.l @r15+, r12                   ! restore r12
    mov.l @r15+, r11                   ! restore r11
    mov.l @r15+, r10                   ! restore r10
    mov.l @r15+, r9                    ! restore r9
    rts                                ! return
    mov.l @r15+, r8                    ! restore r8 (delay slot)
.L_bounds_check:
    ! --- Validate X,Y against screen limits; skip element if out ---
    mov.w   DAT_06032102, r0           ! r0 = 0x0190 (+400, max positive X)
    cmp/gt r0, r1                      ! X > +400?
    bt      .L_next_element            ! yes — off screen right, skip
    mov.w   DAT_06032104, r0           ! r0 = 0xFE70 (-400, min negative X)
    cmp/gt r1, r0                      ! -400 > X?
    bt      .L_next_element            ! yes — off screen left, skip
    mov.w   DAT_06032106, r0           ! r0 = 0x00C8 (+200, max positive Y)
    cmp/gt r0, r2                      ! Y > +200?
    bt      .L_next_element            ! yes — off screen bottom, skip
    mov.w   DAT_06032104, r0           ! r0 = 0xFE70 (-400, min Y — reused)
    cmp/gt r2, r0                      ! -400 > Y?
    bt      .L_next_element            ! yes — off screen top, skip
    rts                                ! all bounds passed — return normally
    nop                                ! (delay slot)

    .global DAT_06032102
DAT_06032102:
    .2byte  0x0190                      ! +400: max positive X screen limit

    .global DAT_06032104
DAT_06032104:
    .2byte  0xFE70                      ! -400: min negative X/Y screen limit

    .global DAT_06032106
DAT_06032106:
    .2byte  0x00C8                      ! +200: max positive Y screen limit

    ! === BSS: coordinate scratch buffer (8 X/Y pairs = 32 bytes) ===
    .global sym_06032108
sym_06032108:
    .word 0xFFFF /* scratch[0].x */
    .word 0xFFFF /* scratch[0].y */
    .word 0xFFFF /* scratch[1].x */
    .word 0xFFFF /* scratch[1].y */
    .word 0xFFFF /* scratch[2].x */
    .word 0xFFFF /* scratch[2].y */
    .word 0xFFFF /* scratch[3].x */
    .word 0xFFFF /* scratch[3].y */
    .word 0xFFFF /* scratch[4].x */
    .word 0xFFFF /* scratch[4].y */
    .word 0xFFFF /* scratch[5].x */
    .word 0xFFFF /* scratch[5].y */
    .word 0xFFFF /* scratch[6].x */
    .word 0xFFFF /* scratch[6].y */
    .word 0xFFFF /* scratch[7].x */
    .word 0xFFFF /* scratch[7].y */

    ! === BSS: transform results array (4 longs = 16 bytes) ===
    .global sym_06032128
sym_06032128:
    .word 0xFFFF /* results[0] high */
    .word 0xFFFF /* results[0] low */
    .word 0xFFFF /* results[1] high */
    .word 0xFFFF /* results[1] low */
    .word 0xFFFF /* results[2] high */
    .word 0xFFFF /* results[2] low */
    .word 0xFFFF /* results[3] high */
    .word 0xFFFF /* results[3] low */

    ! === BSS: temporary rotation vector (3 longs = 12 bytes) ===
    .global sym_06032138
sym_06032138:
    .word 0xFFFF /* rot_x high */
    .word 0xFFFF /* rot_x low */
    .word 0xFFFF /* rot_y high */
    .word 0xFFFF /* rot_y low */
    .word 0xFFFF /* rot_z high */
    .word 0xFFFF /* rot_z low */

    ! === Blend mode jump table (5 entries) ===
    .global sym_06032144
sym_06032144:
    .4byte  loc_06032054               ! mode 0: average
    .4byte  loc_0603205E               ! mode 1: minimum
    .4byte  loc_06032074               ! mode 2: maximum
    .4byte  loc_0603208A               ! mode 3: max + small offset
    .4byte  loc_06032090               ! mode 4: max + large offset

    ! === Batched matrix-vector transform ===
    ! r4 = input vertex array (3 longs per vertex, reused each iteration)
    ! r5 = vertex count
    ! Transforms vertices through camera 3x3 rotation matrix + translation
    .global sym_06032158
sym_06032158:
    mov.l   .L_pool_cam_matrix_ptr, r0 ! r0 -> camera matrix pointer
    mov.l   .L_pool_elem_table_e, r3   ! r3 -> output: display element table
    mov.l @r0, r6                      ! r6 -> camera rotation matrix (9 longs)
    mov #0x24, r7                      ! r7 = 0x24 (36 = sizeof 3x3 matrix)
    add r6, r7                         ! r7 -> translation vector (past matrix)
    add #-0x8, r15                     ! allocate 8 bytes stack temp
.L_xform_loop:
    ! --- Row 0: dot(vertex, matrix row 0) + translation.x ---
    clrmac                             ! clear MAC for row 0
    mac.l @r4+, @r6+                   ! MAC += vtx.x * mat[0][0]
    mac.l @r4+, @r6+                   ! MAC += vtx.y * mat[0][1]
    mov.l @r7, r2                      ! r2 = translation.x
    mac.l @r4+, @r6+                   ! MAC += vtx.z * mat[0][2]
    add #-0xC, r4                      ! rewind vertex ptr
    sts mach, r0                       ! r0 = dot product high
    sts macl, r1                       ! r1 = dot product low
    ! --- Row 1: dot(vertex, matrix row 1) + translation.y ---
    clrmac                             ! clear MAC for row 1
    mac.l @r4+, @r6+                   ! MAC += vtx.x * mat[1][0]
    xtrct r0, r1                       ! r1 = 16.16 fixpt row 0 result
    add r2, r1                         ! r1 += translation.x
    mac.l @r4+, @r6+                   ! MAC += vtx.y * mat[1][1]
    mov.l r1, @r15                     ! temp[0] = transformed X (stack)
    mac.l @r4+, @r6+                   ! MAC += vtx.z * mat[1][2]
    mov.l @(4, r7), r2                 ! r2 = translation.y
    add #-0xC, r4                      ! rewind vertex ptr
    sts mach, r0                       ! r0 = dot product high
    sts macl, r1                       ! r1 = dot product low
    xtrct r0, r1                       ! r1 = 16.16 fixpt row 1 result
    ! --- Row 2: dot(vertex, matrix row 2) + translation.z ---
    clrmac                             ! clear MAC for row 2
    mac.l @r4+, @r6+                   ! MAC += vtx.x * mat[2][0]
    add r2, r1                         ! r1 += translation.y
    mac.l @r4+, @r6+                   ! MAC += vtx.y * mat[2][1]
    mov.l r1, @(4, r15)               ! temp[1] = transformed Y (stack)
    mov.l @(8, r7), r2                 ! r2 = translation.z
    dt r5                              ! r5-- (decrement vertex count); T = (r5 == 0)
    mac.l @r4+, @r6+                   ! MAC += vtx.z * mat[2][2]
    sts mach, r0                       ! r0 = dot product high
    sts macl, r1                       ! r1 = dot product low
    xtrct r0, r1                       ! r1 = 16.16 fixpt row 2 result
    add r2, r1                         ! r1 += translation.z
    ! --- Store transformed XYZ to output ---
    mov.l r1, @(8, r3)                ! out[2] = transformed Z
    mov.l @r15, r0                     ! r0 = transformed X (from stack)
    mov.l @(4, r15), r1                ! r1 = transformed Y (from stack)
    mov.l r0, @r3                      ! out[0] = transformed X
    mov.l r1, @(4, r3)                 ! out[1] = transformed Y
    add #-0x24, r6                     ! rewind matrix ptr to start (36 bytes)
    bf/s    .L_xform_loop              ! more vertices? loop back
    add #0xC, r3                       ! advance output ptr by 12 (delay slot)
    rts                                ! return
    add #0x8, r15                      ! deallocate stack temp (delay slot)
.L_pool_cam_matrix_ptr:
    .4byte  sym_0608A52C                ! -> camera rotation matrix pointer
.L_pool_elem_table_e:
    .4byte  sym_060961A8                ! -> display element table (output)
