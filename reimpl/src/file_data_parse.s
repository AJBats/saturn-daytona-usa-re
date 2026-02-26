/* file_data_parse -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06012344 - 0x06012400
 *
 * Animates position vectors B/C/D/E by timer-derived scale factors.
 *
 * Reads the frame timer (sym_060788AC), halves it, converts to 16.16
 * fixed-point, then multiplies by three constants (~0.03, ~0.09, ~0.15)
 * to produce three scale values (scale_a, scale_b, scale_c). These are
 * applied as additive/subtractive offsets to the X/Y/Z components of
 * four position vectors (B through E at sym_060788C0..sym_060788E4).
 *
 * Called during race cleanup transition (frames 21-40) to animate HUD
 * or scene elements before file_block_read reinitializes them.
 *
 * Position vector adjustments:
 *   vec_b: X -= 2*scale_a,  Y += scale_b,        Z += scale_c
 *   vec_c: X -= scale_b,    Y -= scale_a,         Z -= scale_a
 *   vec_d: X += 2*scale_a,  Y -= scale_c/4,       Z -= scale_c
 *   vec_e: X += scale_b,    Y += scale_b,          Z += scale_c
 *
 * Args: none (reads global state)
 * Clobbers: r0-r6, r11-r14
 */

    .section .text.FUN_06012344


    .global file_data_parse
    .type file_data_parse, @function
file_data_parse:
    mov.l r14, @-r15                        ! save r14 (will hold scale_b)
    mov #0x0, r3                            ! r3 = 0 (for rounding comparison)
    mov.l r13, @-r15                        ! save r13 (will hold scale_a)
    mov.l r12, @-r15                        ! save r12 (will hold half_timer as 16.16 FP)
    mov.l r11, @-r15                        ! save r11 (will hold &fpmul)
    sts.l pr, @-r15                         ! save return address
    mov.l   _pool_frame_timer, r12          ! r12 = &frame_timer (sym_060788AC)
    mov.l   _pool_fn_fpmul, r11             ! r11 = &fpmul (16.16 fixed-point multiply)
    mov.w   DAT_060123de, r5                ! r5 = 0x07AE (~0.03 in 16.16 FP)
    mov.l @r12, r12                         ! r12 = frame_timer value
    cmp/gt r12, r3                          ! T = (0 > r12), i.e. T=1 if timer is negative
    addc r3, r12                            ! r12 += T (round toward zero before halving)
    shar r12                                ! r12 = frame_timer / 2 (arithmetic shift right)
    shll16 r12                              ! r12 = half_timer << 16 (convert to 16.16 FP)
    jsr @r11                                ! call fpmul(half_timer_fp, 0.03)
    mov r12, r4                             ! r4 = half_timer_fp (delay slot: multiplicand)
    mov r0, r13                             ! r13 = scale_a = half_timer * 0.03
    mov.w   DAT_060123e0, r5                ! r5 = 0x170A (~0.09 in 16.16 FP)
    jsr @r11                                ! call fpmul(half_timer_fp, 0.09)
    mov r12, r4                             ! r4 = half_timer_fp (delay slot: multiplicand)
    mov r0, r14                             ! r14 = scale_b = half_timer * 0.09
    mov.w   DAT_060123e2, r5                ! r5 = 0x2666 (~0.15 in 16.16 FP)
    jsr @r11                                ! call fpmul(half_timer_fp, 0.15)
    mov r12, r4                             ! r4 = half_timer_fp (delay slot: multiplicand)
    mov r0, r4                              ! r4 = scale_c = half_timer * 0.15
    mov r13, r5                             ! r5 = scale_a
    mov.l   _pool_vec_b, r6                 ! r6 = &vec_b (sym_060788C0, XYZ triplet)
    mov r4, r1                              ! r1 = scale_c (preserve for hw_divide later)
    shll r5                                 ! r5 = 2 * scale_a
    mov.l @r6, r2                           ! r2 = vec_b.X
    sub r5, r2                              ! r2 = vec_b.X - 2*scale_a
    mov.l r2, @r6                           ! vec_b.X -= 2*scale_a
    mov.l @(4, r6), r3                      ! r3 = vec_b.Y
    add r14, r3                             ! r3 = vec_b.Y + scale_b
    mov.l r3, @(4, r6)                      ! vec_b.Y += scale_b
    mov.l @(8, r6), r2                      ! r2 = vec_b.Z
    add r4, r2                              ! r2 = vec_b.Z + scale_c
    mov.l r2, @(8, r6)                      ! vec_b.Z += scale_c
    mov.l   _pool_vec_c, r6                 ! r6 = &vec_c (sym_060788CC, XYZ triplet)
    mov.l @r6, r3                           ! r3 = vec_c.X
    sub r14, r3                             ! r3 = vec_c.X - scale_b
    mov.l r3, @r6                           ! vec_c.X -= scale_b
    mov.l @(4, r6), r2                      ! r2 = vec_c.Y
    sub r13, r2                             ! r2 = vec_c.Y - scale_a
    mov.l r2, @(4, r6)                      ! vec_c.Y -= scale_a
    mov.l @(8, r6), r3                      ! r3 = vec_c.Z
    sub r13, r3                             ! r3 = vec_c.Z - scale_a
    mov.l r3, @(8, r6)                      ! vec_c.Z -= scale_a
    mov.l   _pool_vec_d, r6                 ! r6 = &vec_d (sym_060788D8, XYZ triplet)
    mov.l @r6, r2                           ! r2 = vec_d.X
    add r5, r2                              ! r2 = vec_d.X + 2*scale_a
    mov.l r2, @r6                           ! vec_d.X += 2*scale_a
    mov.l   _pool_fn_hw_divide, r3          ! r3 = &hw_divide (sym_06034FE0)
    jsr @r3                                 ! call hw_divide(r0=4, r1=scale_c) -> r0 = scale_c/4
    mov #0x4, r0                            ! r0 = 4 (divisor, delay slot)
    mov.l @(4, r6), r2                      ! r2 = vec_d.Y
    sub r0, r2                              ! r2 = vec_d.Y - scale_c/4
    mov.l r2, @(4, r6)                      ! vec_d.Y -= scale_c/4
    mov.l @(8, r6), r3                      ! r3 = vec_d.Z
    sub r4, r3                              ! r3 = vec_d.Z - scale_c
    mov.l r3, @(8, r6)                      ! vec_d.Z -= scale_c
    mov.l   _pool_vec_e, r5                 ! r5 = &vec_e (sym_060788E4, XYZ triplet)
    mov.l @r5, r2                           ! r2 = vec_e.X
    add r14, r2                             ! r2 = vec_e.X + scale_b
    mov.l r2, @r5                           ! vec_e.X += scale_b
    mov.l @(4, r5), r3                      ! r3 = vec_e.Y
    add r14, r3                             ! r3 = vec_e.Y + scale_b
    mov.l r3, @(4, r5)                      ! vec_e.Y += scale_b
    mov.l @(8, r5), r2                      ! r2 = vec_e.Z
    add r4, r2                              ! r2 = vec_e.Z + scale_c
    mov.l r2, @(8, r5)                      ! vec_e.Z += scale_c
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return
    mov.l @r15+, r14                        ! restore r14 (delay slot)

    .global DAT_060123de
DAT_060123de:
    .2byte  0x07AE
                                            /* ~0.03 in 16.16 fixed-point (1966/65536) */
    .global DAT_060123e0
DAT_060123e0:
    .2byte  0x170A
                                            /* ~0.09 in 16.16 fixed-point (5898/65536) */
    .global DAT_060123e2
DAT_060123e2:
    .2byte  0x2666
_pool_frame_timer:
    .4byte  sym_060788AC                    /* frame timer / animation state counter */
_pool_fn_fpmul:
    .4byte  fpmul                           /* 16.16 fixed-point multiply: fpmul(r4, r5) -> r0 */
_pool_vec_b:
    .4byte  sym_060788C0                    /* position vector B (XYZ triplet, 12 bytes) */
_pool_vec_c:
    .4byte  sym_060788CC                    /* position vector C (XYZ triplet, 12 bytes) */
_pool_vec_d:
    .4byte  sym_060788D8                    /* position vector D (XYZ triplet, 12 bytes) */
_pool_fn_hw_divide:
    .4byte  sym_06034FE0                    /* hw_divide(r0=divisor, r1=dividend) -> r0=quotient */
_pool_vec_e:
    .4byte  sym_060788E4                    /* position vector E (XYZ triplet, 12 bytes) */
