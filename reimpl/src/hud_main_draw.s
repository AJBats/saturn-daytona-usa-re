/* hud_main_draw -- HUD element rotated-quad writer
 * Translation unit: 0x060116BC - 0x06011978
 *
 * Computes rotated screen coordinates for a HUD element quad (4 corners
 * of a rectangle) and writes them into a HUD record. The rectangle has
 * half-extents 56x30 in 16.16 fixed-point. Each corner is rotated by
 * the given angle, scaled, and offset by the base position (x_offset,
 * y_offset). Results are stored as 16-bit screen coords at offsets
 * 0x08..0x16 of the 24-byte HUD record, plus byte flags at 0x04/0x05
 * and a 16-bit parameter at 0x06.
 *
 * Inputs (caller sets callee-saved regs before call):
 *   r4 = x_offset (16.16), saved to r8
 *   r0 = angle (16-bit), saved to stack
 *   r9 = y_offset (16.16, set by caller)
 *   r10 = scale factor (16.16, set by caller)
 *
 * HUD record layout (24 bytes at sym_060786CC + index*24):
 *   +0x04  byte  visibility flag A (written 0)
 *   +0x05  byte  visibility flag B (written 1)
 *   +0x06  word  parameter (from caller stack)
 *   +0x08  word  corner0 X (rotated -56,+30)
 *   +0x0A  word  corner0 Y
 *   +0x0C  word  corner1 X (rotated +56,+30)
 *   +0x0E  word  corner1 Y
 *   +0x10  word  corner2 X (rotated +56,-30)
 *   +0x12  word  corner2 Y
 *   +0x14  word  corner3 X (rotated -56,-30)
 *   +0x16  word  corner3 Y
 *
 * Corner rotation formula:
 *   X' = int16(fpmul(fpmul(cx * cos - cy * sin, scale)) + int16(x_offset))
 *   Y' = int16(fpmul(fpmul(cx * sin + cy * cos, scale)) + int16(y_offset))
 *
 * Record counter at sym_0605AAA0 is incremented at exit.
 */

    .section .text.FUN_060116BC


    .global hud_main_draw
    .type hud_main_draw, @function
hud_main_draw:
    sts.l pr, @-r15                     ! save return address
    mov r4, r8                          ! r8 = x_offset (preserve across calls)
    add #-0xC, r15                      ! allocate 12 bytes: [sp+0]=sin, [sp+4]=cos, [sp+8]=temp
    mov r15, r6                         ! r6 = &sin_out (for sincos_pair cos_ptr after +4)
    mov r15, r5                         ! r5 = &sin_out (for sincos_pair sin_ptr)
    mov.w r0, @(8, r15)                 ! save angle to sp[8]
    add #0x4, r6                        ! r6 = &cos_out (sp+4)
    mov.w @(8, r15), r0                 ! reload angle into r0
    mov.l   .L_fn_sincos, r3            ! r3 = sincos_pair
    jsr @r3                             ! sincos_pair(angle, &sin, &cos)
    mov r0, r4                          ! (delay) r4 = angle

    /* --- Load persistent registers for all field computations --- */
    mov.l   .L_hud_record_base, r11     ! r11 = sym_060786CC (HUD record array base)
    mov.l   .L_hud_record_count, r12    ! r12 = sym_0605AAA0 (HUD record index word)
    mov.l   .L_fn_swap_sign_ext, r13    ! r13 = swap_sign_ext (extract int16 from 16.16)
    mov.l   .L_fn_fpmul, r14            ! r14 = fpmul (16.16 fixed-point multiply)

    /* ====== Corner 0: rotate point (-56, +30) => fields 0x08, 0x0A ====== */
    /* --- Field 0x08: corner0 X = int16(fpmul(-56*cos - 30*sin, scale) + x_base) --- */
    mov.w @r12, r2                      ! r2 = record_index
    mov r2, r3                          ! r3 = index (copy for *16)
    shll2 r2                            ! r2 = index * 4
    shll2 r3                            ! r3 = index * 4
    shll r2                             ! r2 = index * 8
    shll2 r3                            ! r3 = index * 16
    add r3, r2                          ! r2 = index * 24
    exts.w r2, r2                       ! sign-extend offset to 32 bits
    mov #0x8, r3                        ! r3 = field offset 0x08
    add r11, r2                         ! r2 = &record[index]
    add r2, r3                          ! r3 = &record[index].corner0_x
    mov.l r3, @-r15                     ! push dest_ptr
    mov.l   .L_fp_neg56, r4             ! r4 = -56.0 (0xFFC80000)
    jsr @r14                            ! fpmul(-56.0, cos_val)
    mov.l @(8, r15), r5                 ! (delay) r5 = cos_val (sp+8 after push = original sp+4)
    mov.l r0, @-r15                     ! push fpmul_result (-56*cos)
    mov.l   .L_fp_plus30, r4            ! r4 = +30.0 (0x001E0000)
    jsr @r14                            ! fpmul(+30.0, sin_val)
    mov.l @(8, r15), r5                 ! (delay) r5 = sin_val (sp+8 after two pushes = original sp+0)
    mov.l @r15+, r4                     ! pop (-56*cos)
    sub r0, r4                          ! r4 = (-56*cos) - (+30*sin)
    jsr @r14                            ! fpmul(rotated_x, scale)
    mov r10, r5                         ! (delay) r5 = scale
    jsr @r13                            ! swap_sign_ext(scaled_result)
    mov r0, r4                          ! (delay) r4 = scaled_result
    mov.l r0, @-r15                     ! push int16(scaled_x)
    jsr @r13                            ! swap_sign_ext(x_offset)
    mov r8, r4                          ! (delay) r4 = x_offset
    mov.l @r15+, r3                     ! pop int16(scaled_x)
    add r3, r0                          ! r0 = int16(scaled_x) + int16(x_offset)
    mov.l @r15+, r2                     ! pop dest_ptr (&record.corner0_x)
    exts.w r0, r0                       ! sign-extend to 32 bits
    mov.w r0, @r2                       ! record.corner0_x = result

    /* --- Field 0x0A: corner0 Y = int16(fpmul(-56*sin + 30*cos, scale) + y_base) --- */
    mov.w @r12, r3                      ! r3 = record_index
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    mov #0xA, r2                        ! r2 = field offset 0x0A
    add r11, r3                         ! r3 = &record[index]
    add r3, r2                          ! r2 = &record[index].corner0_y
    mov.l r2, @-r15                     ! push dest_ptr
    mov.l   .L_fp_neg56, r4             ! r4 = -56.0 (0xFFC80000)
    jsr @r14                            ! fpmul(-56.0, sin_val)
    mov.l @(4, r15), r5                 ! (delay) r5 = sin_val (sp+4 after push = original sp+0)
    mov.l r0, @-r15                     ! push fpmul_result (-56*sin)
    mov.l   .L_fp_plus30, r4            ! r4 = +30.0 (0x001E0000)
    jsr @r14                            ! fpmul(+30.0, cos_val)
    mov.l @(12, r15), r5                ! (delay) r5 = cos_val (sp+12 after two pushes = orig sp+4)
    mov.l @r15+, r4                     ! pop (-56*sin)
    add r0, r4                          ! r4 = (-56*sin) + (+30*cos)
    jsr @r14                            ! fpmul(rotated_y, scale)
    mov r10, r5                         ! (delay) r5 = scale
    jsr @r13                            ! swap_sign_ext(scaled_result)
    mov r0, r4                          ! (delay) r4 = scaled_result
    mov.l r0, @-r15                     ! push int16(scaled_y)
    jsr @r13                            ! swap_sign_ext(y_offset)
    mov r9, r4                          ! (delay) r4 = y_offset
    mov.l @r15+, r3                     ! pop int16(scaled_y)
    add r3, r0                          ! r0 = int16(scaled_y) + int16(y_offset)
    exts.w r0, r0                       ! sign-extend to 32 bits
    mov.l @r15+, r3                     ! pop dest_ptr (&record.corner0_y)
    mov.w r0, @r3                       ! record.corner0_y = result

    /* ====== Corner 1: rotate point (+56, +30) => fields 0x0C, 0x0E ====== */
    /* --- Field 0x0C: corner1 X = int16(fpmul(+56*cos - 30*sin, scale) + x_base) --- */
    mov.w @r12, r2                      ! r2 = record_index
    mov r2, r3                          ! r3 = index (copy for *16)
    shll2 r2                            ! r2 = index * 4
    shll2 r3                            ! r3 = index * 4
    shll r2                             ! r2 = index * 8
    shll2 r3                            ! r3 = index * 16
    add r3, r2                          ! r2 = index * 24
    exts.w r2, r2                       ! sign-extend offset
    mov #0xC, r3                        ! r3 = field offset 0x0C
    add r11, r2                         ! r2 = &record[index]
    add r2, r3                          ! r3 = &record[index].corner1_x
    mov.l r3, @-r15                     ! push dest_ptr
    mov.l   .L_fp_plus56, r4            ! r4 = +56.0 (0x00380000)
    jsr @r14                            ! fpmul(+56.0, cos_val)
    mov.l @(8, r15), r5                 ! (delay) r5 = cos_val
    mov.l r0, @-r15                     ! push fpmul_result (+56*cos)
    mov.l   .L_fp_plus30, r4            ! r4 = +30.0 (0x001E0000)
    jsr @r14                            ! fpmul(+30.0, sin_val)
    mov.l @(8, r15), r5                 ! (delay) r5 = sin_val
    mov.l @r15+, r4                     ! pop (+56*cos)
    sub r0, r4                          ! r4 = (+56*cos) - (+30*sin)
    jsr @r14                            ! fpmul(rotated_x, scale)
    mov r10, r5                         ! (delay) r5 = scale
    jsr @r13                            ! swap_sign_ext(scaled_result)
    mov r0, r4                          ! (delay) r4 = scaled_result
    mov.l r0, @-r15                     ! push int16(scaled_x)
    jsr @r13                            ! swap_sign_ext(x_offset)
    mov r8, r4                          ! (delay) r4 = x_offset
    mov.l @r15+, r3                     ! pop int16(scaled_x)
    add r3, r0                          ! r0 = int16(scaled_x) + int16(x_offset)
    mov.l @r15+, r2                     ! pop dest_ptr (&record.corner1_x)
    exts.w r0, r0                       ! sign-extend to 32 bits
    mov.w r0, @r2                       ! record.corner1_x = result

    /* --- Field 0x0E: corner1 Y = int16(fpmul(+56*sin + 30*cos, scale) + y_base) --- */
    mov.w @r12, r3                      ! r3 = record_index
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    mov #0xE, r2                        ! r2 = field offset 0x0E
    add r11, r3                         ! r3 = &record[index]
    add r3, r2                          ! r2 = &record[index].corner1_y
    mov.l r2, @-r15                     ! push dest_ptr
    mov.l   .L_fp_plus56, r4            ! r4 = +56.0 (0x00380000)
    jsr @r14                            ! fpmul(+56.0, sin_val)
    mov.l @(4, r15), r5                 ! (delay) r5 = sin_val
    mov.l r0, @-r15                     ! push fpmul_result (+56*sin)
    mov.l   .L_fp_plus30, r4            ! r4 = +30.0 (0x001E0000)
    jsr @r14                            ! fpmul(+30.0, cos_val)
    mov.l @(12, r15), r5                ! (delay) r5 = cos_val
    mov.l @r15+, r4                     ! pop (+56*sin)
    add r0, r4                          ! r4 = (+56*sin) + (+30*cos)
    jsr @r14                            ! fpmul(rotated_y, scale)
    mov r10, r5                         ! (delay) r5 = scale
    jsr @r13                            ! swap_sign_ext(scaled_result)
    mov r0, r4                          ! (delay) r4 = scaled_result
    mov.l r0, @-r15                     ! push int16(scaled_y)
    jsr @r13                            ! swap_sign_ext(y_offset)
    mov r9, r4                          ! (delay) r4 = y_offset
    bra     .L_after_pool1              ! jump over first constant pool
    nop                                 ! (delay) alignment

    /* --- First constant pool (between branch islands) --- */
.L_fn_sincos:
    .4byte  sincos_pair                 /* sin/cos lookup function */
.L_hud_record_base:
    .4byte  sym_060786CC                /* HUD record array base address */
.L_hud_record_count:
    .4byte  sym_0605AAA0                /* HUD record count/index (16-bit) */
.L_fn_swap_sign_ext:
    .4byte  swap_sign_ext               /* extract int16 from 16.16 fixed-point */
.L_fn_fpmul:
    .4byte  fpmul                       /* 16.16 fixed-point multiply */
.L_fp_neg56:
    .4byte  0xFFC80000                  /* -56.0 in 16.16 fixed-point */
.L_fp_plus30:
    .4byte  0x001E0000                  /* +30.0 in 16.16 fixed-point */
.L_fp_plus56:
    .4byte  0x00380000                  /* +56.0 in 16.16 fixed-point */

    /* --- Continue corner1 Y computation after pool --- */
.L_after_pool1:
    mov.l @r15+, r3                     ! pop int16(scaled_y)
    add r3, r0                          ! r0 = int16(scaled_y) + int16(y_offset)
    exts.w r0, r0                       ! sign-extend to 32 bits
    mov.l @r15+, r3                     ! pop dest_ptr (&record.corner1_y)
    mov.w r0, @r3                       ! record.corner1_y = result

    /* ====== Corner 2: rotate point (+56, -30) => fields 0x10, 0x12 ====== */
    /* --- Field 0x10: corner2 X = int16(fpmul(+56*cos + 30*sin, scale) + x_base) --- */
    mov.w @r12, r2                      ! r2 = record_index
    mov r2, r3                          ! r3 = index (copy for *16)
    shll2 r2                            ! r2 = index * 4
    shll2 r3                            ! r3 = index * 4
    shll r2                             ! r2 = index * 8
    shll2 r3                            ! r3 = index * 16
    add r3, r2                          ! r2 = index * 24
    exts.w r2, r2                       ! sign-extend offset
    mov #0x10, r3                       ! r3 = field offset 0x10
    add r11, r2                         ! r2 = &record[index]
    add r2, r3                          ! r3 = &record[index].corner2_x
    mov.l r3, @-r15                     ! push dest_ptr
    mov.l   .L_fp_plus56_b, r4          ! r4 = +56.0 (0x00380000)
    jsr @r14                            ! fpmul(+56.0, cos_val)
    mov.l @(8, r15), r5                 ! (delay) r5 = cos_val
    mov.l r0, @-r15                     ! push fpmul_result (+56*cos)
    mov.l   .L_fp_neg30, r4             ! r4 = -30.0 (0xFFE20000)
    jsr @r14                            ! fpmul(-30.0, sin_val)
    mov.l @(8, r15), r5                 ! (delay) r5 = sin_val
    mov.l @r15+, r4                     ! pop (+56*cos)
    sub r0, r4                          ! r4 = (+56*cos) - (-30*sin) = +56*cos + 30*sin
    jsr @r14                            ! fpmul(rotated_x, scale)
    mov r10, r5                         ! (delay) r5 = scale
    jsr @r13                            ! swap_sign_ext(scaled_result)
    mov r0, r4                          ! (delay) r4 = scaled_result
    mov.l r0, @-r15                     ! push int16(scaled_x)
    jsr @r13                            ! swap_sign_ext(x_offset)
    mov r8, r4                          ! (delay) r4 = x_offset
    mov.l @r15+, r3                     ! pop int16(scaled_x)
    add r3, r0                          ! r0 = int16(scaled_x) + int16(x_offset)
    mov.l @r15+, r2                     ! pop dest_ptr (&record.corner2_x)
    exts.w r0, r0                       ! sign-extend to 32 bits
    mov.w r0, @r2                       ! record.corner2_x = result

    /* --- Field 0x12: corner2 Y = int16(fpmul(+56*sin - 30*cos, scale) + y_base) --- */
    mov.w @r12, r3                      ! r3 = record_index
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    mov #0x12, r2                       ! r2 = field offset 0x12
    add r11, r3                         ! r3 = &record[index]
    add r3, r2                          ! r2 = &record[index].corner2_y
    mov.l r2, @-r15                     ! push dest_ptr
    mov.l   .L_fp_plus56_b, r4          ! r4 = +56.0 (0x00380000)
    jsr @r14                            ! fpmul(+56.0, sin_val)
    mov.l @(4, r15), r5                 ! (delay) r5 = sin_val
    mov.l r0, @-r15                     ! push fpmul_result (+56*sin)
    mov.l   .L_fp_neg30, r4             ! r4 = -30.0 (0xFFE20000)
    jsr @r14                            ! fpmul(-30.0, cos_val)
    mov.l @(12, r15), r5                ! (delay) r5 = cos_val
    mov.l @r15+, r4                     ! pop (+56*sin)
    add r0, r4                          ! r4 = (+56*sin) + (-30*cos) = +56*sin - 30*cos
    jsr @r14                            ! fpmul(rotated_y, scale)
    mov r10, r5                         ! (delay) r5 = scale
    jsr @r13                            ! swap_sign_ext(scaled_result)
    mov r0, r4                          ! (delay) r4 = scaled_result
    mov.l r0, @-r15                     ! push int16(scaled_y)
    jsr @r13                            ! swap_sign_ext(y_offset)
    mov r9, r4                          ! (delay) r4 = y_offset
    mov.l @r15+, r3                     ! pop int16(scaled_y)
    add r3, r0                          ! r0 = int16(scaled_y) + int16(y_offset)
    exts.w r0, r0                       ! sign-extend to 32 bits
    mov.l @r15+, r3                     ! pop dest_ptr (&record.corner2_y)
    mov.w r0, @r3                       ! record.corner2_y = result

    /* ====== Corner 3: rotate point (-56, -30) => fields 0x14, 0x16 ====== */
    /* --- Field 0x14: corner3 X = int16(fpmul(-56*cos + 30*sin, scale) + x_base) --- */
    mov.w @r12, r2                      ! r2 = record_index
    mov r2, r3                          ! r3 = index (copy for *16)
    shll2 r2                            ! r2 = index * 4
    shll2 r3                            ! r3 = index * 4
    shll r2                             ! r2 = index * 8
    shll2 r3                            ! r3 = index * 16
    add r3, r2                          ! r2 = index * 24
    exts.w r2, r2                       ! sign-extend offset
    mov #0x14, r3                       ! r3 = field offset 0x14
    add r11, r2                         ! r2 = &record[index]
    add r2, r3                          ! r3 = &record[index].corner3_x
    mov.l r3, @-r15                     ! push dest_ptr
    mov.l   .L_fp_neg56_b, r4           ! r4 = -56.0 (0xFFC80000)
    jsr @r14                            ! fpmul(-56.0, cos_val)
    mov.l @(8, r15), r5                 ! (delay) r5 = cos_val
    mov.l r0, @-r15                     ! push fpmul_result (-56*cos)
    mov.l   .L_fp_neg30, r4             ! r4 = -30.0 (0xFFE20000)
    jsr @r14                            ! fpmul(-30.0, sin_val)
    mov.l @(8, r15), r5                 ! (delay) r5 = sin_val
    mov.l @r15+, r4                     ! pop (-56*cos)
    sub r0, r4                          ! r4 = (-56*cos) - (-30*sin) = -56*cos + 30*sin
    jsr @r14                            ! fpmul(rotated_x, scale)
    mov r10, r5                         ! (delay) r5 = scale
    jsr @r13                            ! swap_sign_ext(scaled_result)
    mov r0, r4                          ! (delay) r4 = scaled_result
    mov.l r0, @-r15                     ! push int16(scaled_x)
    jsr @r13                            ! swap_sign_ext(x_offset)
    mov r8, r4                          ! (delay) r4 = x_offset
    mov.l @r15+, r3                     ! pop int16(scaled_x)
    add r3, r0                          ! r0 = int16(scaled_x) + int16(x_offset)
    mov.l @r15+, r2                     ! pop dest_ptr (&record.corner3_x)
    exts.w r0, r0                       ! sign-extend to 32 bits
    mov.w r0, @r2                       ! record.corner3_x = result

    /* --- Field 0x16: corner3 Y = int16(fpmul(-56*sin - 30*cos, scale) + y_base) --- */
    mov.w @r12, r3                      ! r3 = record_index
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    mov #0x16, r2                       ! r2 = field offset 0x16
    add r11, r3                         ! r3 = &record[index]
    add r3, r2                          ! r2 = &record[index].corner3_y
    mov.l r2, @-r15                     ! push dest_ptr
    mov.l   .L_fp_neg56_b, r4           ! r4 = -56.0 (0xFFC80000)
    jsr @r14                            ! fpmul(-56.0, sin_val)
    mov.l @(4, r15), r5                 ! (delay) r5 = sin_val
    mov.l r0, @-r15                     ! push fpmul_result (-56*sin)
    mov.l   .L_fp_neg30, r4             ! r4 = -30.0 (0xFFE20000)
    jsr @r14                            ! fpmul(-30.0, cos_val)
    mov.l @(12, r15), r5                ! (delay) r5 = cos_val
    mov.l @r15+, r4                     ! pop (-56*sin)
    add r0, r4                          ! r4 = (-56*sin) + (-30*cos) = -56*sin - 30*cos
    jsr @r14                            ! fpmul(rotated_y, scale)
    mov r10, r5                         ! (delay) r5 = scale
    jsr @r13                            ! swap_sign_ext(scaled_result)
    mov r0, r4                          ! (delay) r4 = scaled_result
    mov.l r0, @-r15                     ! push int16(scaled_y)
    jsr @r13                            ! swap_sign_ext(y_offset)
    mov r9, r4                          ! (delay) r4 = y_offset
    mov.l @r15+, r3                     ! pop int16(scaled_y)
    add r3, r0                          ! r0 = int16(scaled_y) + int16(y_offset)
    exts.w r0, r0                       ! sign-extend to 32 bits
    mov.l @r15+, r3                     ! pop dest_ptr (&record.corner3_y)
    mov.w r0, @r3                       ! record.corner3_y = result

    /* ====== Write byte fields and parameter word ====== */

    /* --- Field 0x06: write parameter word from caller stack --- */
    mov #0x2E, r0                       ! r0 = 0x2E (offset to caller parameter on stack)
    mov.w @r12, r2                      ! r2 = record_index
    mov.w @(r0, r15), r0                ! r0 = caller parameter word from stack
    mov r2, r3                          ! r3 = index (copy for *16)
    shll2 r2                            ! r2 = index * 4
    shll2 r3                            ! r3 = index * 4
    shll r2                             ! r2 = index * 8
    shll2 r3                            ! r3 = index * 16
    add r3, r2                          ! r2 = index * 24
    exts.w r2, r2                       ! sign-extend offset
    add r11, r2                         ! r2 = &record[index]
    mov.w r0, @(6, r2)                  ! record[index].param_word = caller parameter

    /* --- Field 0x04: write visibility flag A = 0 --- */
    mov #0x0, r0                        ! r0 = 0 (visibility flag A)
    mov.w @r12, r3                      ! r3 = record_index
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll2 r2                            ! r2 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r11, r3                         ! r3 = &record[index]
    mov.b r0, @(4, r3)                  ! record[index].vis_flag_a = 0

    /* --- Field 0x05: write visibility flag B = 1 --- */
    mov.w @r12, r3                      ! r3 = record_index
    mov r3, r2                          ! r2 = index (copy for *16)
    shll2 r3                            ! r3 = index * 4
    shll r3                             ! r3 = index * 8
    shll2 r2                            ! r2 = index * 4
    mov #0x1, r0                        ! r0 = 1 (visibility flag B)
    shll2 r2                            ! r2 = index * 16
    add r2, r3                          ! r3 = index * 24
    exts.w r3, r3                       ! sign-extend offset
    add r11, r3                         ! r3 = &record[index]
    mov.b r0, @(5, r3)                  ! record[index].vis_flag_b = 1

    /* --- Increment record counter and return --- */
    mov.w @r12, r3                      ! r3 = record_index
    add #0x1, r3                        ! r3 = record_index + 1
    mov.w r3, @r12                      ! store incremented count
    add #0xC, r15                       ! deallocate 12 bytes of locals
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r8                     ! restore r8
    mov.l @r15+, r9                     ! restore r9
    mov.l @r15+, r10                    ! restore r10
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return
    mov.l @r15+, r14                    ! (delay) restore r14

    /* --- Second constant pool (at end of function) --- */
.L_fp_plus56_b:
    .4byte  0x00380000                  /* +56.0 in 16.16 fixed-point */
.L_fp_neg30:
    .4byte  0xFFE20000                  /* -30.0 in 16.16 fixed-point */
.L_fp_neg56_b:
    .4byte  0xFFC80000                  /* -56.0 in 16.16 fixed-point */
