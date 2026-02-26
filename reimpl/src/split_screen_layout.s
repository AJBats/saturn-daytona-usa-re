/* split_screen_layout -- HUD element pre-computed quad writer
 * Translation unit: 0x0601198C - 0x06011AF4
 *
 * Takes 8 pre-computed corner coordinates from an input array and writes
 * them into a 24-byte HUD record. Each coordinate is offset-adjusted via
 * swap_sign_ext (extract int16 from 16.16 fixed-point) with alternating
 * x_offset (r10) and y_offset (r9).
 *
 * Inputs (caller sets callee-saved regs before call):
 *   r7  = parameter word (saved to stack, written to record +0x06)
 *   r9  = y_offset (16.16, set by caller)
 *   r10 = x_offset (16.16, set by caller)
 *   r11 = pointer to input coord array (8 x 32-bit values)
 *
 * HUD record layout (24 bytes at sym_060786CC + index*24):
 *   +0x04  byte  visibility flag A (written 0)
 *   +0x05  byte  visibility flag B (written 1)
 *   +0x06  word  parameter (from caller r7)
 *   +0x08  word  corner0 X
 *   +0x0A  word  corner0 Y
 *   +0x0C  word  corner1 X
 *   +0x0E  word  corner1 Y
 *   +0x10  word  corner2 X
 *   +0x12  word  corner2 Y
 *   +0x14  word  corner3 X
 *   +0x16  word  corner3 Y
 *
 * Record counter at sym_0605AAA0 is incremented at exit.
 */

    .section .text.FUN_0601198C


    .global split_screen_layout
    .type split_screen_layout, @function
split_screen_layout:
    sts.l pr, @-r15                     ! save return address
    add #-0x4, r15                      ! allocate 4 bytes for local (param word)
    mov.w r7, @r15                      ! save parameter word to stack
    mov.l   .L_fn_swap_sign_ext, r12    ! r12 = swap_sign_ext (extract int16 from 16.16)
    mov.l   .L_hud_record_base, r13     ! r13 = sym_060786CC (HUD record array base)
    mov.l   .L_hud_record_count, r14    ! r14 = sym_0605AAA0 (HUD record index word)

    /* ====== Corner 0 X: record[index].field_0x08 ====== */
    mov.l @r11, r4                      ! r4 = input_coords[0] (corner0 raw X)
    mov.w @r14, r3                      ! r3 = record_index
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset to 32 bits
    add r13, r3                         ! r3 = &record[index]
    mov r3, r8                          ! r8 = &record[index]
    add #0x8, r8                        ! r8 = &record[index].corner0_x
    jsr @r12                            ! swap_sign_ext(corner0_raw_x + x_offset)
    add r10, r4                         ! (delay) r4 = input_coords[0] + x_offset
    mov.w r0, @r8                       ! record[index].corner0_x = result

    /* ====== Corner 0 Y: record[index].field_0x0A ====== */
    mov.w @r14, r3                      ! r3 = record_index
    mov.l @(4, r11), r4                 ! r4 = input_coords[1] (corner0 raw Y)
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r13, r3                         ! r3 = &record[index]
    mov r3, r8                          ! r8 = &record[index]
    add #0xA, r8                        ! r8 = &record[index].corner0_y
    jsr @r12                            ! swap_sign_ext(corner0_raw_y + y_offset)
    add r9, r4                          ! (delay) r4 = input_coords[1] + y_offset
    mov.w r0, @r8                       ! record[index].corner0_y = result

    /* ====== Corner 1 X: record[index].field_0x0C ====== */
    mov.w @r14, r3                      ! r3 = record_index
    mov.l @(8, r11), r4                 ! r4 = input_coords[2] (corner1 raw X)
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r13, r3                         ! r3 = &record[index]
    mov r3, r8                          ! r8 = &record[index]
    add #0xC, r8                        ! r8 = &record[index].corner1_x
    jsr @r12                            ! swap_sign_ext(corner1_raw_x + x_offset)
    add r10, r4                         ! (delay) r4 = input_coords[2] + x_offset
    mov.w r0, @r8                       ! record[index].corner1_x = result

    /* ====== Corner 1 Y: record[index].field_0x0E ====== */
    mov.w @r14, r3                      ! r3 = record_index
    mov.l @(12, r11), r4                ! r4 = input_coords[3] (corner1 raw Y)
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r13, r3                         ! r3 = &record[index]
    mov r3, r8                          ! r8 = &record[index]
    add #0xE, r8                        ! r8 = &record[index].corner1_y
    jsr @r12                            ! swap_sign_ext(corner1_raw_y + y_offset)
    add r9, r4                          ! (delay) r4 = input_coords[3] + y_offset
    mov.w r0, @r8                       ! record[index].corner1_y = result

    /* ====== Corner 2 X: record[index].field_0x10 ====== */
    mov.w @r14, r3                      ! r3 = record_index
    mov.l @(16, r11), r4                ! r4 = input_coords[4] (corner2 raw X)
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r13, r3                         ! r3 = &record[index]
    mov r3, r8                          ! r8 = &record[index]
    add #0x10, r8                       ! r8 = &record[index].corner2_x
    jsr @r12                            ! swap_sign_ext(corner2_raw_x + x_offset)
    add r10, r4                         ! (delay) r4 = input_coords[4] + x_offset
    mov.w r0, @r8                       ! record[index].corner2_x = result

    /* ====== Corner 2 Y: record[index].field_0x12 ====== */
    mov.w @r14, r3                      ! r3 = record_index
    mov.l @(20, r11), r4                ! r4 = input_coords[5] (corner2 raw Y)
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r13, r3                         ! r3 = &record[index]
    mov r3, r8                          ! r8 = &record[index]
    add #0x12, r8                       ! r8 = &record[index].corner2_y
    jsr @r12                            ! swap_sign_ext(corner2_raw_y + y_offset)
    add r9, r4                          ! (delay) r4 = input_coords[5] + y_offset
    mov.w r0, @r8                       ! record[index].corner2_y = result

    /* ====== Corner 3 X: record[index].field_0x14 ====== */
    mov.w @r14, r3                      ! r3 = record_index
    mov.l @(24, r11), r4                ! r4 = input_coords[6] (corner3 raw X)
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r13, r3                         ! r3 = &record[index]
    mov r3, r8                          ! r8 = &record[index]
    add #0x14, r8                       ! r8 = &record[index].corner3_x
    jsr @r12                            ! swap_sign_ext(corner3_raw_x + x_offset)
    add r10, r4                         ! (delay) r4 = input_coords[6] + x_offset
    mov.w r0, @r8                       ! record[index].corner3_x = result

    /* ====== Corner 3 Y: record[index].field_0x16 ====== */
    mov.w @r14, r3                      ! r3 = record_index
    mov.l @(28, r11), r4                ! r4 = input_coords[7] (corner3 raw Y)
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r13, r3                         ! r3 = &record[index]
    mov r3, r8                          ! r8 = &record[index]
    add #0x16, r8                       ! r8 = &record[index].corner3_y
    jsr @r12                            ! swap_sign_ext(corner3_raw_y + y_offset)
    add r9, r4                          ! (delay) r4 = input_coords[7] + y_offset
    exts.w r0, r0                       ! sign-extend result to 32 bits
    mov.w r0, @r8                       ! record[index].corner3_y = result

    /* ====== Write parameter word and visibility flags ====== */

    /* --- Field 0x06: write parameter word from caller r7 --- */
    mov.w @r14, r3                      ! r3 = record_index
    mov.w @r15, r0                      ! r0 = saved parameter word (from r7)
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r13, r3                         ! r3 = &record[index]
    mov.w r0, @(6, r3)                  ! record[index].param_word = parameter

    /* --- Field 0x04: write visibility flag A = 0 --- */
    mov.w @r14, r3                      ! r3 = record_index
    mov #0x0, r0                        ! r0 = 0 (visibility flag A)
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r13, r3                         ! r3 = &record[index]
    mov.b r0, @(4, r3)                  ! record[index].vis_flag_a = 0

    /* --- Field 0x05: write visibility flag B = 1 --- */
    mov.w @r14, r3                      ! r3 = record_index
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 4
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r13, r3                         ! r3 = &record[index]
    mov #0x1, r0                        ! r0 = 1 (visibility flag B)
    mov.b r0, @(5, r3)                  ! record[index].vis_flag_b = 1

    /* --- Increment record counter and return --- */
    mov.w @r14, r3                      ! r3 = record_index
    add #0x1, r3                        ! r3 = record_index + 1
    mov.w r3, @r14                      ! store incremented count
    add #0x4, r15                       ! deallocate 4 bytes of locals
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r8                     ! restore r8
    mov.l @r15+, r9                     ! restore r9
    mov.l @r15+, r10                    ! restore r10
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return
    mov.l @r15+, r14                    ! (delay) restore r14
    .2byte  0xFFFF                      ! padding
.L_fn_swap_sign_ext:
    .4byte  swap_sign_ext               /* extract int16 from 16.16 fixed-point */
.L_hud_record_base:
    .4byte  sym_060786CC                /* HUD record array base (24 bytes per entry) */
.L_hud_record_count:
    .4byte  sym_0605AAA0                /* HUD record count/index (16-bit) */
