/* timer_countdown_display -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06031A34 - 0x06031E00
 *
 * Race countdown timer display renderer.
 *
 * Renders the on-screen countdown timer digits (minutes, seconds, centiseconds)
 * as 3D-projected sprites. For each digit, the function:
 *   1. Looks up the digit's sprite entry from the sprite data table
 *   2. Transforms its 3D position through a rotation matrix (MAC dot products)
 *   3. Projects the result and checks screen-space visibility bounds
 *   4. Clips against left/right/top/bottom screen edges
 *   5. Dispatches to one of 5 depth-sort modes via a jump table to determine
 *      the final Z-depth value for draw ordering
 *   6. Writes the sprite command into the VDP1 sprite index table
 *
 * The rotation matrix multiply uses the SH-2 MAC (multiply-accumulate) unit
 * for 3x3 fixed-point dot products. Visibility culling rejects digits that
 * are fully off-screen on any axis.
 *
 * Functions:
 *   timer_countdown_display  - Main entry: iterates digits, transforms, clips, commits
 *   validate_screen_bounds   - Local helper: range-checks projected X/Y coordinates
 *   sprite_matrix_transform  - Transforms sprite positions through rotation + translation
 *   timer_callee_save_push   - Callee-save register prologue (pushes r8-r13)
 *
 * Data:
 *   screen_coord_buf         - 32-byte scratch: projected screen X/Y pairs (4 digits)
 *   depth_result_buf         - 16-byte scratch: Z-depth results (4 digit entries)
 *   rotation_scratch         - 12-byte scratch: 3x1 rotation result vector
 *   depth_mode_table         - Jump table for 5 depth-sorting dispatch modes
 *
 * Key external references:
 *   sym_06094FA8  - Sprite data table (12-byte entries indexed by sprite ID)
 *   sym_060620D0  - Sprite count (number of active VDP1 sprite commands)
 *   sym_0608AC20  - Sprite entry base (24-byte entries for position/attribute data)
 *   sym_06089EDC  - Pointer to current rotation matrix (3x3 fixed-point)
 *   sym_0606A4F8  - VDP1 sprite index lookup table (word per entry)
 */

    .section .text.FUN_06031A34


    .global timer_countdown_display
    .type timer_countdown_display, @function
timer_countdown_display:
    mov.l r14, @-r15                    ! save r14 (digit counter)
    sts.l pr, @-r15                     ! save return address
    mov #0x18, r0                       ! r0 = 0x18 (24 = sizeof digit entry)
    mul.l r6, r0                        ! MACL = digit_count * 24
    mov r4, r8                          ! r8 = digit_array base pointer
    mov r5, r10                         ! r10 = display element index
    mov r6, r14                         ! r14 = digit_count (loop counter)
    sts macl, r0                        ! r0 = digit_count * 24 (total byte offset)
    add r0, r8                          ! r8 = &digit_array[digit_count] (past end)
    mov.l   .L_pool_depth_result_buf, r13 ! r13 -> depth_result_buf (Z-depth output)
    mov.l   .L_pool_screen_coord_buf, r11 ! r11 -> screen_coord_buf (X/Y output)
.L_digit_loop:
    add #-0x18, r8                      ! r8 -= 24; advance to previous digit entry
    mov.w @(16, r8), r0                 ! r0 = digit_entry[+16] (sprite ID for digit 0)
    mov #0xC, r3                        ! r3 = 0xC (12 = sizeof sprite data entry)
    mulu.w r0, r3                       ! MACL = sprite_id * 12
    mov.w   DAT_06031a64, r12           ! r12 = 0xFF00 (display command base offset)
    mov.l   .L_pool_sprite_data_tbl, r3 ! r3 -> sprite_data_table base
    sts macl, r7                        ! r7 = sprite_id * 12
    add r3, r7                          ! r7 -> sprite_data_table[sprite_id]
    mov.l @(8, r7), r3                  ! r3 = sprite_entry[+8] (Z-depth / visibility)
    cmp/pl r3                           ! is Z-depth positive (visible)?
    bt      .L_sprite_valid             ! yes: proceed with rendering
    bra     .L_next_digit               ! no: skip this digit
    nop                                 ! (branch delay slot)

    .global DAT_06031a64
DAT_06031a64:
    .2byte  0xFF00                      ! display command base offset (-256 signed)
    .2byte  0x0000                      ! alignment padding
.L_pool_depth_result_buf:
    .4byte  sym_06031D5C                ! -> depth_result_buf (4 longword Z-depths)
.L_pool_screen_coord_buf:
    .4byte  sym_06031D3C                ! -> screen_coord_buf (4 X/Y pairs = 32 bytes)
.L_pool_sprite_data_tbl:
    .4byte  sym_06094FA8                ! -> sprite data table base
.L_sprite_valid:
    mov.w   .L_wpool_cmd_size_a, r0     ! r0 = 0x00A0 (160 = sprite command size)
    mov.l r0, @(16, r12)                ! display_cmd[+16] = command size
    mov.l r3, @(0, r12)                 ! display_cmd[+0] = Z-depth value
    mov #0x0, r0                        ! r0 = 0
    mov.l r0, @(20, r12)                ! display_cmd[+20] = 0 (clear flags)
    mov.l r3, @r13                      ! depth_result_buf[0] = Z-depth
    mov.w @(12, r8), r0                 ! r0 = digit_entry[+12] (flags/mode word)
    mov r8, r4                          ! r4 -> digit_entry (position data for MAC)
    tst #0x8, r0                        ! test bit 3: rotation needed?
    bf      .L_after_matrix_xform       ! bit set: skip rotation, already transformed
    mov.l   .L_pool_rotation_scratch, r5 ! r5 -> rotation_scratch (3x1 output vector)
    mov.l   .L_pool_rot_matrix_ptr, r0  ! r0 -> pointer to rotation matrix
    mov.l @r0, r9                       ! r9 -> rotation matrix (3x3 fixed-point)
    clrmac                              ! clear MAC for dot product row 0
    mac.l @r4+, @r9+                    ! MAC += pos[0] * mat[0][0]
    mac.l @r4+, @r9+                    ! MAC += pos[1] * mat[0][1]
    mac.l @r4+, @r9+                    ! MAC += pos[2] * mat[0][2]
    add #-0xC, r4                       ! rewind r4 to start of position vector
    sts mach, r0                        ! r0 = dot product high word (row 0)
    sts macl, r1                        ! r1 = dot product low word (row 0)
    clrmac                              ! clear MAC for dot product row 1
    mac.l @r4+, @r9+                    ! MAC += pos[0] * mat[1][0]
    xtrct r0, r1                        ! r1 = middle 32 bits of row 0 result
    mov.l r1, @r5                       ! rotation_scratch[0] = projected X
    mac.l @r4+, @r9+                    ! MAC += pos[1] * mat[1][1]
    mac.l @r4+, @r9+                    ! MAC += pos[2] * mat[1][2]
    add #-0xC, r4                       ! rewind r4 to start of position vector
    sts mach, r0                        ! r0 = dot product high word (row 1)
    sts macl, r1                        ! r1 = dot product low word (row 1)
    clrmac                              ! clear MAC for dot product row 2
    mac.l @r4+, @r9+                    ! MAC += pos[0] * mat[2][0]
    xtrct r0, r1                        ! r1 = middle 32 bits of row 1 result
    mov.l r1, @(4, r5)                  ! rotation_scratch[1] = projected Y
    mac.l @r4+, @r9+                    ! MAC += pos[1] * mat[2][1]
    mac.l @r4+, @r9+                    ! MAC += pos[2] * mat[2][2]
    add #-0x24, r9                      ! rewind r9 to start of matrix (-36 = -9*4)
    sts mach, r0                        ! r0 = dot product high word (row 2)
    sts macl, r1                        ! r1 = dot product low word (row 2)
    xtrct r0, r1                        ! r1 = middle 32 bits of row 2 result
    mov.l r1, @(8, r5)                  ! rotation_scratch[2] = projected Z
    mov r7, r4                          ! r4 -> sprite_data_entry (direction vector)
    clrmac                              ! clear MAC for Z-visibility dot product
    mac.l @r4+, @r5+                    ! MAC += sprite[0] * rotated[0]
    mac.l @r4+, @r5+                    ! MAC += sprite[1] * rotated[1]
    mac.l @r4+, @r5+                    ! MAC += sprite[2] * rotated[2]
    sts mach, r1                        ! r1 = visibility dot product high
    sts macl, r0                        ! r0 = visibility dot product low
    xtrct r1, r0                        ! r0 = middle 32 bits (signed visibility)
    cmp/pl r0                           ! is visibility positive (facing camera)?
    bt      .L_after_matrix_xform       ! yes: continue rendering
    bra     .L_next_digit               ! no: backface cull, skip digit
    nop                                 ! (branch delay slot)
.L_wpool_cmd_size_a:
    .2byte  0x00A0                      ! 160 = sprite command size
    .2byte  0x0000                      ! alignment padding
.L_pool_rotation_scratch:
    .4byte  sym_06031D6C                ! -> rotation_scratch (3x1 result vector)
.L_pool_rot_matrix_ptr:
    .4byte  sym_06089EDC                ! -> pointer to current rotation matrix
.L_after_matrix_xform:
    mov r11, r5                         ! r5 -> screen_coord_buf (output for digit 0)
    mov.l @(4, r7), r2                  ! r2 = sprite_entry[+4] (Y direction component)
    mov.l @r7, r1                       ! r1 = sprite_entry[+0] (X direction component)
    mov.l @(28, r12), r4                ! r4 = display_cmd[+28] (scale factor)
    mov.w @(18, r8), r0                 ! r0 = digit_entry[+18] (sprite ID for digit 1)
    mov #0xC, r3                        ! r3 = 0xC (12 = sizeof sprite data entry)
    mulu.w r0, r3                       ! MACL = sprite_id * 12
    mov.l   .L_pool_sprite_data_tbl_b, r3 ! r3 -> sprite_data_table base
    sts macl, r7                        ! r7 = sprite_id * 12
    add r3, r7                          ! r7 -> sprite_data_table[sprite_id]
    mov.l @(8, r7), r3                  ! r3 = sprite_entry[+8] (Z-depth)
    mov.w   DAT_06031b22, r0            ! r0 = 0x00A0 (sprite command size)
    mov.l r0, @(16, r12)                ! display_cmd[+16] = command size
    mov.l r3, @(0, r12)                 ! display_cmd[+0] = Z-depth
    mov #0x0, r0                        ! r0 = 0
    mov.l r0, @(20, r12)                ! display_cmd[+20] = 0 (clear flags)
    dmuls.l r1, r4                      ! MACH:MACL = X_dir * scale (signed 64-bit)
    neg r2, r2                          ! r2 = -Y_dir (negate for screen coords)
    sts mach, r1                        ! r1 = scaled X high word (screen X)
    dmuls.l r2, r4                      ! MACH:MACL = -Y_dir * scale (signed 64-bit)
    mov.l r1, @r5                       ! screen_coord_buf[0] = screen X for digit 0
    sts mach, r2                        ! r2 = scaled Y high word (screen Y)
    mov.l r2, @(4, r5)                  ! screen_coord_buf[1] = screen Y for digit 0
    bsr     .L_validate_screen_bounds   ! check if projected coords are on-screen
    nop                                 ! (branch delay slot)
    cmp/pl r3                           ! bounds check passed? (r3 > 0 = valid)
    bt      .L_digit1_valid             ! yes: continue with digit 1
    bra     .L_next_digit               ! no: skip remaining digits
    nop                                 ! (branch delay slot)

    .global DAT_06031b22
DAT_06031b22:
    .2byte  0x00A0                      ! 160 = sprite command size
.L_pool_sprite_data_tbl_b:
    .4byte  sym_06094FA8                ! -> sprite data table base
.L_digit1_valid:
    mov.l r3, @(4, r13)                 ! depth_result_buf[1] = Z-depth for digit 1
    add #0x8, r5                        ! r5 += 8; advance to next screen coord slot
    mov.l @(4, r7), r2                  ! r2 = sprite_entry[+4] (Y direction)
    mov.l @r7, r1                       ! r1 = sprite_entry[+0] (X direction)
    mov.l @(28, r12), r4                ! r4 = display_cmd[+28] (scale factor)
    mov.w @(20, r8), r0                 ! r0 = digit_entry[+20] (sprite ID for digit 2)
    mov #0xC, r3                        ! r3 = 0xC (12 = sizeof sprite data entry)
    mulu.w r0, r3                       ! MACL = sprite_id * 12
    mov.l   .L_pool_sprite_data_tbl_c, r3 ! r3 -> sprite_data_table base
    sts macl, r7                        ! r7 = sprite_id * 12
    add r3, r7                          ! r7 -> sprite_data_table[sprite_id]
    mov.l @(8, r7), r3                  ! r3 = sprite_entry[+8] (Z-depth)
    mov.w   .L_wpool_cmd_size_b, r0     ! r0 = 0x00A0 (sprite command size)
    mov.l r0, @(16, r12)                ! display_cmd[+16] = command size
    mov.l r3, @(0, r12)                 ! display_cmd[+0] = Z-depth
    mov #0x0, r0                        ! r0 = 0
    mov.l r0, @(20, r12)                ! display_cmd[+20] = 0 (clear flags)
    dmuls.l r1, r4                      ! MACH:MACL = X_dir * scale
    neg r2, r2                          ! r2 = -Y_dir
    sts mach, r1                        ! r1 = scaled X (screen X)
    dmuls.l r2, r4                      ! MACH:MACL = -Y_dir * scale
    mov.l r1, @r5                       ! screen_coord_buf[2] = screen X for digit 2
    sts mach, r2                        ! r2 = scaled Y (screen Y)
    mov.l r2, @(4, r5)                  ! screen_coord_buf[3] = screen Y for digit 2
    bsr     .L_validate_screen_bounds   ! check if projected coords are on-screen
    nop                                 ! (branch delay slot)
    cmp/pl r3                           ! bounds check passed?
    bt      .L_digit2_valid             ! yes: continue with digit 2
    bra     .L_next_digit               ! no: skip remaining digits
    nop                                 ! (branch delay slot)
.L_wpool_cmd_size_b:
    .2byte  0x00A0                      ! 160 = sprite command size
    .2byte  0x0000                      ! alignment padding
.L_pool_sprite_data_tbl_c:
    .4byte  sym_06094FA8                ! -> sprite data table base
.L_digit2_valid:
    mov.l r3, @(8, r13)                 ! depth_result_buf[2] = Z-depth for digit 2
    add #0x8, r5                        ! r5 += 8; advance to next screen coord slot
    mov.l @(4, r7), r2                  ! r2 = sprite_entry[+4] (Y direction)
    mov.l @r7, r1                       ! r1 = sprite_entry[+0] (X direction)
    mov.l @(28, r12), r4                ! r4 = display_cmd[+28] (scale factor)
    mov.w @(22, r8), r0                 ! r0 = digit_entry[+22] (sprite ID for digit 3)
    mov #0xC, r3                        ! r3 = 0xC (12 = sizeof sprite data entry)
    mulu.w r0, r3                       ! MACL = sprite_id * 12
    mov.l   .L_pool_sprite_data_tbl_d, r3 ! r3 -> sprite_data_table base
    sts macl, r7                        ! r7 = sprite_id * 12
    add r3, r7                          ! r7 -> sprite_data_table[sprite_id]
    mov.l @(8, r7), r3                  ! r3 = sprite_entry[+8] (Z-depth)
    mov.w   .L_wpool_cmd_size_c, r0     ! r0 = 0x00A0 (sprite command size)
    mov.l r0, @(16, r12)                ! display_cmd[+16] = command size
    mov.l r3, @(0, r12)                 ! display_cmd[+0] = Z-depth
    mov #0x0, r0                        ! r0 = 0
    mov.l r0, @(20, r12)                ! display_cmd[+20] = 0 (clear flags)
    dmuls.l r1, r4                      ! MACH:MACL = X_dir * scale
    neg r2, r2                          ! r2 = -Y_dir
    sts mach, r1                        ! r1 = scaled X (screen X)
    dmuls.l r2, r4                      ! MACH:MACL = -Y_dir * scale
    mov.l r1, @r5                       ! screen_coord_buf[4] = screen X for digit 3
    sts mach, r2                        ! r2 = scaled Y (screen Y)
    mov.l r2, @(4, r5)                  ! screen_coord_buf[5] = screen Y for digit 3
    bsr     .L_validate_screen_bounds   ! check if projected coords are on-screen
    nop                                 ! (branch delay slot)
    cmp/pl r3                           ! bounds check passed?
    bt      .L_digit3_valid             ! yes: continue with digit 3
    bra     .L_next_digit               ! no: skip remaining digits
    nop                                 ! (branch delay slot)
.L_wpool_cmd_size_c:
    .2byte  0x00A0                      ! 160 = sprite command size
    .2byte  0x0000                      ! alignment padding
.L_pool_sprite_data_tbl_d:
    .4byte  sym_06094FA8                ! -> sprite data table base
.L_digit3_valid:
    mov.l r3, @(12, r13)                ! depth_result_buf[3] = Z-depth for digit 3
    add #0x8, r5                        ! r5 += 8; advance to next screen coord slot
    mov.l @(4, r7), r2                  ! r2 = sprite_entry[+4] (Y direction)
    mov.l @r7, r1                       ! r1 = sprite_entry[+0] (X direction)
    mov.l @(28, r12), r4                ! r4 = display_cmd[+28] (scale factor)
    dmuls.l r1, r4                      ! MACH:MACL = X_dir * scale
    neg r2, r2                          ! r2 = -Y_dir
    sts mach, r1                        ! r1 = scaled X (screen X)
    dmuls.l r2, r4                      ! MACH:MACL = -Y_dir * scale
    mov.l r1, @r5                       ! screen_coord_buf[6] = screen X for digit 4
    sts mach, r2                        ! r2 = scaled Y (screen Y)
    mov.l r2, @(4, r5)                  ! screen_coord_buf[7] = screen Y for digit 4
    bsr     .L_validate_screen_bounds   ! check if projected coords are on-screen
    nop                                 ! (branch delay slot)
    mov.l   .L_pool_sprite_count, r0    ! r0 -> sprite_count variable
    mov #0x18, r1                       ! r1 = 0x18 (24 = sizeof sprite entry)
    mov.l @r0, r0                       ! r0 = current sprite count
    mul.l r0, r1                        ! MACL = sprite_count * 24
    mov.l   .L_pool_sprite_entry_base, r2 ! r2 -> sprite_entry_base
    sts macl, r9                        ! r9 = sprite_count * 24
    add r2, r9                          ! r9 -> next free sprite entry slot
    mov.w   .L_wpool_neg_clip_threshold, r12 ! r12 = 0xFF50 (-176 = left clip edge)
    mov.l @(0, r11), r0                 ! r0 = screen_X[0] (digit 0 X)
    mov.l @(8, r11), r2                 ! r2 = screen_X[1] (digit 1 X)
    mov.l @(16, r11), r4                ! r4 = screen_X[2] (digit 2 X)
    mov.l @(24, r11), r6                ! r6 = screen_X[3] (digit 3 X)
    cmp/gt r0, r12                      ! is digit 0 X left of left clip edge?
    bf      .L_check_right_bound        ! no: at least partially visible
    cmp/gt r2, r12                      ! is digit 1 X left of left clip edge?
    bf      .L_check_right_bound        ! no: at least partially visible
    cmp/gt r4, r12                      ! is digit 2 X left of left clip edge?
    bf      .L_check_right_bound        ! no: at least partially visible
    cmp/gt r6, r12                      ! is digit 3 X left of left clip edge?
    bf      .L_check_right_bound        ! no: at least partially visible
    bra     .L_next_digit               ! all digits off-screen left: skip
    nop                                 ! (branch delay slot)
.L_wpool_neg_clip_threshold:
    .2byte  0xFF50                      ! -176 signed = left screen clip edge
    .2byte  0x0000                      ! alignment padding
.L_pool_sprite_count:
    .4byte  sym_060620D0                ! -> sprite_count (active VDP1 commands)
.L_pool_sprite_entry_base:
    .4byte  sym_0608AC20                ! -> sprite entry base (24-byte entries)
.L_check_right_bound:
    mov.w   .L_wpool_right_clip, r12    ! r12 = 0x00B0 (176 = right clip edge)
    cmp/gt r0, r12                      ! is right edge > digit 0 X? (on-screen?)
    bt      .L_load_y_coords            ! yes: at least one digit visible in X
    cmp/gt r2, r12                      ! is right edge > digit 1 X?
    bt      .L_load_y_coords            ! yes: visible
    cmp/gt r4, r12                      ! is right edge > digit 2 X?
    bt      .L_load_y_coords            ! yes: visible
    cmp/gt r6, r12                      ! is right edge > digit 3 X?
    bt      .L_next_digit               ! all digits off-screen right: skip
.L_load_y_coords:
    mov.w   .L_wpool_top_clip, r12      ! r12 = 0xFF81 (-127 = top clip edge)
    mov.l @(4, r11), r1                 ! r1 = screen_Y[0] (digit 0 Y)
    mov.l @(12, r11), r3                ! r3 = screen_Y[1] (digit 1 Y)
    mov.l @(20, r11), r5                ! r5 = screen_Y[2] (digit 2 Y)
    mov.l @(28, r11), r7                ! r7 = screen_Y[3] (digit 3 Y)
    cmp/gt r1, r12                      ! is digit 0 Y above top clip edge?
    bf      .L_check_bottom_bound       ! no: at least partially visible
    cmp/gt r3, r12                      ! is digit 1 Y above top clip?
    bf      .L_check_bottom_bound       ! no: visible
    cmp/gt r5, r12                      ! is digit 2 Y above top clip?
    bf      .L_check_bottom_bound       ! no: visible
    cmp/gt r7, r12                      ! is digit 3 Y above top clip?
    bt      .L_next_digit               ! all digits off-screen top: skip
.L_check_bottom_bound:
    mov.w   .L_wpool_bottom_clip, r12   ! r12 = 0x0051 (81 = bottom clip edge)
    cmp/gt r1, r12                      ! is bottom edge > digit 0 Y? (on-screen?)
    bt      .L_write_sprite_cmd         ! yes: at least one digit visible
    cmp/gt r3, r12                      ! is bottom edge > digit 1 Y?
    bt      .L_write_sprite_cmd         ! yes: visible
    cmp/gt r5, r12                      ! is bottom edge > digit 2 Y?
    bt      .L_write_sprite_cmd         ! yes: visible
    cmp/gt r7, r12                      ! is bottom edge > digit 3 Y?
    bf      .L_next_digit               ! all digits off-screen bottom: skip
.L_write_sprite_cmd:
    mov r9, r12                         ! r12 -> sprite entry (write pointer)
    add #0x18, r12                      ! r12 -> end of 24-byte entry (+24)
    mov.w r7, @-r12                     ! entry[+22] = screen_Y[3] (write backwards)
    mov.w r6, @-r12                     ! entry[+20] = screen_X[3]
    mov.w r5, @-r12                     ! entry[+18] = screen_Y[2]
    mov.w r4, @-r12                     ! entry[+16] = screen_X[2]
    mov.w r3, @-r12                     ! entry[+14] = screen_Y[1]
    mov.w r2, @-r12                     ! entry[+12] = screen_X[1]
    mov.w r1, @-r12                     ! entry[+10] = screen_Y[0]
    mov.w r0, @-r12                     ! entry[+8] = screen_X[0]
    mov.w @(14, r8), r0                 ! r0 = digit_entry[+14] (sprite attribute word)
    mov.w r0, @(6, r9)                  ! entry[+6] = sprite type/attribute
    mov.w @(12, r8), r0                 ! r0 = digit_entry[+12] (flags/mode)
    shlr2 r0                            ! r0 >>= 2
    shlr2 r0                            ! r0 >>= 2 (total >>= 4, extract bits 7:4)
    and #0xF, r0                        ! r0 = color/palette index (4 bits)
    mov.b r0, @(4, r9)                  ! entry[+4] = color index
    mov r10, r0                         ! r0 = display element index
    mov.b r0, @(5, r9)                  ! entry[+5] = element index
    mov.w @(12, r8), r0                 ! r0 = digit_entry[+12] (flags/mode)
    mov.l   .L_pool_depth_mode_table, r1 ! r1 -> depth_mode_table (jump table)
    and #0x7, r0                        ! r0 = depth sort mode (bits 2:0)
    shll2 r0                            ! r0 *= 4 (index into pointer table)
    mov.l @(r0, r1), r0                 ! r0 = depth_mode_table[mode] (handler addr)
    mov.l @(0, r13), r3                 ! r3 = depth_result[0]
    mov.l @(4, r13), r4                 ! r4 = depth_result[1]
    mov.l @(8, r13), r5                 ! r5 = depth_result[2]
    jmp @r0                             ! jump to depth-sort handler
    mov.l @(12, r13), r6                ! r6 = depth_result[3] (delay slot)
.L_wpool_right_clip:
    .2byte  0x00B0                      ! 176 = right screen clip edge
.L_wpool_top_clip:
    .2byte  0xFF81                      ! -127 signed = top screen clip edge
.L_wpool_bottom_clip:
    .2byte  0x0051                      ! 81 = bottom screen clip edge
    .2byte  0x0000                      ! alignment padding
.L_pool_depth_mode_table:
    .4byte  sym_06031D78                ! -> depth_mode_table (5-entry jump table)

    .global loc_06031C88
loc_06031C88:                                   ! depth mode 0: average of all four
    add r4, r3                          ! r3 = depth[0] + depth[1]
    add r5, r6                          ! r6 = depth[2] + depth[3]
    add r6, r3                          ! r3 = sum of all four depths
    bra     .L_commit_sprite_entry      ! go commit the sprite entry
    shlr2 r3                            ! r3 >>= 2; average = sum / 4 (delay slot)

    .global loc_06031C92
loc_06031C92:                                   ! depth mode 1: minimum (nearest)
    cmp/ge r3, r4                       ! is depth[1] >= depth[0]?
    bt      .L_min_cmp_r5              ! yes: keep r3 as current min
    mov r4, r3                          ! no: r3 = depth[1] (new min)
.L_min_cmp_r5:
    cmp/ge r3, r5                       ! is depth[2] >= current min?
    bt      .L_min_cmp_r6              ! yes: keep current min
    mov r5, r3                          ! no: r3 = depth[2] (new min)
.L_min_cmp_r6:
    cmp/ge r3, r6                       ! is depth[3] >= current min?
    bt      .L_min_done                ! yes: keep current min
    mov r6, r3                          ! no: r3 = depth[3] (new min)
.L_min_done:
    bra     .L_commit_sprite_entry      ! go commit with minimum depth
    nop                                 ! (branch delay slot)

    .global loc_06031CA8
loc_06031CA8:                                   ! depth mode 2: maximum (farthest)
    cmp/gt r3, r4                       ! is depth[1] > depth[0]?
    bf      .L_max_cmp_r5             ! no: keep current max
    mov r4, r3                          ! yes: r3 = depth[1] (new max)
.L_max_cmp_r5:
    cmp/gt r3, r5                       ! is depth[2] > current max?
    bf      .L_max_cmp_r6             ! no: keep current max
    mov r5, r3                          ! yes: r3 = depth[2] (new max)
.L_max_cmp_r6:
    cmp/gt r3, r6                       ! is depth[3] > current max?
    bf      .L_max_done                ! no: keep current max
    mov r6, r3                          ! yes: r3 = depth[3] (new max)
.L_max_done:
    bra     .L_commit_sprite_entry      ! go commit with maximum depth
    nop                                 ! (branch delay slot)

    .global loc_06031CBE
loc_06031CBE:                                   ! depth mode 3: max + small offset
    mov #0x20, r0                       ! r0 = 0x20
    bra     .L_max_with_offset          ! jump to shared max+offset logic
    shll16 r0                           ! r0 = 0x00200000 (delay slot: small offset)

    .global loc_06031CC4
loc_06031CC4:                                   ! depth mode 4: max + large offset
    mov.l   .L_pool_depth_offset_large, r0 ! r0 = 0x00400000 (large depth offset)
.L_max_with_offset:
    cmp/gt r3, r4                       ! is depth[1] > depth[0]?
    bf      .L_max_off_cmp_r5         ! no: keep current max
    mov r4, r3                          ! yes: r3 = depth[1]
.L_max_off_cmp_r5:
    cmp/gt r3, r5                       ! is depth[2] > current max?
    bf      .L_max_off_cmp_r6         ! no: keep current max
    mov r5, r3                          ! yes: r3 = depth[2]
.L_max_off_cmp_r6:
    cmp/gt r3, r6                       ! is depth[3] > current max?
    bf      .L_apply_depth_offset      ! no: keep current max
    mov r6, r3                          ! yes: r3 = depth[3]
.L_apply_depth_offset:
    add r0, r3                          ! r3 = max_depth + offset (push farther back)
.L_commit_sprite_entry:
    mov.l   .L_pool_sprite_count_b, r2  ! r2 -> sprite_count variable
    neg r3, r3                          ! r3 = -depth (negate for sort key)
    mov.l   .L_pool_sprite_index_tbl, r1 ! r1 -> sprite_index_table
    shlr8 r3                            ! r3 >>= 8 (fixed-point to integer)
    mov.l @r2, r0                       ! r0 = current sprite_count
    shlr2 r3                            ! r3 >>= 2
    shlr2 r3                            ! r3 >>= 2 (total >>= 12: 16.16 to 16-bit)
    shll r0                             ! r0 *= 2 (word index into sprite_index_table)
    mov.w r3, @(r0, r1)                 ! sprite_index_table[count] = sort key (word)
    shar r0                             ! r0 /= 2 (restore sprite count)
    add #0x1, r0                        ! r0 = sprite_count + 1
    mov.l r0, @r2                       ! sprite_count++ (committed one sprite)
.L_next_digit:
    dt r14                              ! r14--; decrement digit loop counter
    bt      .L_epilogue                 ! if counter == 0: all digits done, exit
    bra     .L_digit_loop               ! loop back for next digit
    nop                                 ! (branch delay slot)
    .2byte  0x0000                      ! alignment padding
.L_pool_depth_offset_large:
    .4byte  0x00400000                  ! large depth offset constant (4194304)
.L_pool_sprite_count_b:
    .4byte  sym_060620D0                ! -> sprite_count (active VDP1 commands)
.L_pool_sprite_index_tbl:
    .4byte  sym_0606A4F8                ! -> sprite_index_table (word per entry)
.L_epilogue:
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r14                    ! restore r14
    mov.l @r15+, r13                    ! restore r13
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r10                    ! restore r10
    mov.l @r15+, r9                     ! restore r9
    rts                                 ! return to caller
    mov.l @r15+, r8                     ! restore r8 (delay slot)
.L_validate_screen_bounds:
    mov.w   DAT_06031d36, r0            ! r0 = 0x0190 (400 = max positive X bound)
    cmp/gt r0, r1                       ! is screen_X > 400?
    bt      .L_next_digit               ! yes: off-screen right, reject
    mov.w   DAT_06031d38, r0            ! r0 = 0xFE70 (-400 = max negative bound)
    cmp/gt r1, r0                       ! is -400 > screen_X? (X < -400?)
    bt      .L_next_digit               ! yes: off-screen left, reject
    mov.w   DAT_06031d3a, r0            ! r0 = 0x00C8 (200 = max positive Y bound)
    cmp/gt r0, r2                       ! is screen_Y > 200?
    bt      .L_next_digit               ! yes: off-screen bottom, reject
    mov.w   DAT_06031d38, r0            ! r0 = 0xFE70 (-400 = reused as min Y bound)
    cmp/gt r2, r0                       ! is -400 > screen_Y? (Y < -400?)
    bt      .L_next_digit               ! yes: off-screen top, reject
    rts                                 ! all bounds OK: return normally
    nop                                 ! (branch delay slot)

    .global DAT_06031d36
DAT_06031d36:
    .2byte  0x0190                      ! 400 = max positive X screen bound

    .global DAT_06031d38
DAT_06031d38:
    .2byte  0xFE70                      ! -400 signed = max negative screen bound

    .global DAT_06031d3a
DAT_06031d3a:
    .2byte  0x00C8                      ! 200 = max positive Y screen bound

    .global sym_06031D3C
sym_06031D3C:                                   ! screen_coord_buf: 32 bytes (4 X/Y pairs)
    .word 0xFFFF /* scratch: digit 0 screen X (low) */
    .word 0xFFFF /* scratch: digit 0 screen X (high) */
    .word 0xFFFF /* scratch: digit 0 screen Y (low) */
    .word 0xFFFF /* scratch: digit 0 screen Y (high) */
    .word 0xFFFF /* scratch: digit 1 screen X (low) */
    .word 0xFFFF /* scratch: digit 1 screen X (high) */
    .word 0xFFFF /* scratch: digit 1 screen Y (low) */
    .word 0xFFFF /* scratch: digit 1 screen Y (high) */
    .word 0xFFFF /* scratch: digit 2 screen X (low) */
    .word 0xFFFF /* scratch: digit 2 screen X (high) */
    .word 0xFFFF /* scratch: digit 2 screen Y (low) */
    .word 0xFFFF /* scratch: digit 2 screen Y (high) */
    .word 0xFFFF /* scratch: digit 3 screen X (low) */
    .word 0xFFFF /* scratch: digit 3 screen X (high) */
    .word 0xFFFF /* scratch: digit 3 screen Y (low) */
    .word 0xFFFF /* scratch: digit 3 screen Y (high) */

    .global sym_06031D5C
sym_06031D5C:                                   ! depth_result_buf: 16 bytes (4 Z-depths)
    .word 0xFFFF /* scratch: digit 0 depth (low) */
    .word 0xFFFF /* scratch: digit 0 depth (high) */
    .word 0xFFFF /* scratch: digit 1 depth (low) */
    .word 0xFFFF /* scratch: digit 1 depth (high) */
    .word 0xFFFF /* scratch: digit 2 depth (low) */
    .word 0xFFFF /* scratch: digit 2 depth (high) */
    .word 0xFFFF /* scratch: digit 3 depth (low) */
    .word 0xFFFF /* scratch: digit 3 depth (high) */

    .global sym_06031D6C
sym_06031D6C:                                   ! rotation_scratch: 12 bytes (3x1 vector)
    .word 0xFFFF /* scratch: rotated X (low) */
    .word 0xFFFF /* scratch: rotated X (high) */
    .word 0xFFFF /* scratch: rotated Y (low) */
    .word 0xFFFF /* scratch: rotated Y (high) */
    .word 0xFFFF /* scratch: rotated Z (low) */
    .word 0xFFFF /* scratch: rotated Z (high) */

    .global sym_06031D78
sym_06031D78:                                   ! depth_mode_table: 5 dispatch handlers
    .4byte  loc_06031C88                ! mode 0: average of 4 depths
    .4byte  loc_06031C92                ! mode 1: minimum depth (nearest)
    .4byte  loc_06031CA8                ! mode 2: maximum depth (farthest)
    .4byte  loc_06031CBE                ! mode 3: max + small offset (0x00200000)
    .4byte  loc_06031CC4                ! mode 4: max + large offset (0x00400000)

    .global sym_06031D8C
sym_06031D8C:                                   ! sprite_matrix_transform(r4=pos, r5=count)
    mov.l   .L_pool_rot_matrix_ptr_b, r0 ! r0 -> rotation matrix pointer
    mov.l   .L_pool_sprite_data_tbl_e, r3 ! r3 -> sprite_data_table (output)
    mov.l @r0, r6                       ! r6 -> rotation matrix (3x3)
    mov #0x24, r7                       ! r7 = 0x24 (36 = 9 * 4 = matrix size)
    add r6, r7                          ! r7 -> translation vector (after 3x3 matrix)
    add #-0x8, r15                      ! allocate 8 bytes of stack for temp storage
.L_xform_loop:
    clrmac                              ! clear MAC for dot product row 0
    mac.l @r4+, @r6+                    ! MAC += pos[0] * mat[0][0]
    mac.l @r4+, @r6+                    ! MAC += pos[1] * mat[0][1]
    mov.l @r7, r2                       ! r2 = translation[0] (X offset)
    mac.l @r4+, @r6+                    ! MAC += pos[2] * mat[0][2]
    add #-0xC, r4                       ! rewind r4 to start of position
    sts mach, r0                        ! r0 = row 0 dot product high
    sts macl, r1                        ! r1 = row 0 dot product low
    clrmac                              ! clear MAC for dot product row 1
    mac.l @r4+, @r6+                    ! MAC += pos[0] * mat[1][0]
    xtrct r0, r1                        ! r1 = middle 32 bits of row 0
    add r2, r1                          ! r1 += translation[0] (add X offset)
    mac.l @r4+, @r6+                    ! MAC += pos[1] * mat[1][1]
    mov.l r1, @r15                      ! temp[0] = rotated + translated X
    mac.l @r4+, @r6+                    ! MAC += pos[2] * mat[1][2]
    mov.l @(4, r7), r2                  ! r2 = translation[1] (Y offset)
    add #-0xC, r4                       ! rewind r4 to start of position
    sts mach, r0                        ! r0 = row 1 dot product high
    sts macl, r1                        ! r1 = row 1 dot product low
    xtrct r0, r1                        ! r1 = middle 32 bits of row 1
    clrmac                              ! clear MAC for dot product row 2
    mac.l @r4+, @r6+                    ! MAC += pos[0] * mat[2][0]
    add r2, r1                          ! r1 += translation[1] (add Y offset)
    mac.l @r4+, @r6+                    ! MAC += pos[1] * mat[2][1]
    mov.l r1, @(4, r15)                 ! temp[1] = rotated + translated Y
    mov.l @(8, r7), r2                  ! r2 = translation[2] (Z offset)
    dt r5                               ! r5--; decrement vertex count
    mac.l @r4+, @r6+                    ! MAC += pos[2] * mat[2][2]
    sts mach, r0                        ! r0 = row 2 dot product high
    sts macl, r1                        ! r1 = row 2 dot product low
    xtrct r0, r1                        ! r1 = middle 32 bits of row 2
    add r2, r1                          ! r1 += translation[2] (add Z offset)
    mov.l r1, @(8, r3)                  ! output[+8] = transformed Z
    mov.l @r15, r0                      ! r0 = temp[0] (transformed X)
    mov.l @(4, r15), r1                 ! r1 = temp[1] (transformed Y)
    mov.l r0, @r3                       ! output[+0] = transformed X
    mov.l r1, @(4, r3)                  ! output[+4] = transformed Y
    add #-0x24, r6                      ! rewind r6 to start of rotation matrix
    bf/s    .L_xform_loop               ! loop if more vertices to transform
    add #0xC, r3                        ! r3 += 12; advance to next output entry (delay)
    rts                                 ! return to caller
    add #0x8, r15                       ! deallocate 8 bytes of stack (delay slot)
.L_pool_rot_matrix_ptr_b:
    .4byte  sym_06089EDC                ! -> pointer to current rotation matrix
.L_pool_sprite_data_tbl_e:
    .4byte  sym_06094FA8                ! -> sprite data table base (output)

    .global sym_06031DF4
sym_06031DF4:                                   ! timer_callee_save_push (prologue)
    mov.l r8, @-r15                     ! save r8
    mov.l r9, @-r15                     ! save r9
    mov.l r10, @-r15                    ! save r10
    mov.l r11, @-r15                    ! save r11
    mov.l r12, @-r15                    ! save r12
    mov.l r13, @-r15                    ! save r13 (falls through to caller body)
