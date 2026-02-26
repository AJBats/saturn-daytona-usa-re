/* rot_scroll_vscale -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0602E4F4 - 0x0602E578
 *
 * VDP2 rotation scroll vertical scale computation.
 *
 * Part of the rotation scroll pipeline (commit -> interp -> vscale -> hscale).
 * Called with r0 = callback function pointer, r15 stack has car struct pointer.
 *
 * Calls the callback via r0 to get a raw vertical value, negates and
 * sign-extends it as the new vscale. Reads the old vertical reference from
 * the car struct at offset +0x28, computes the delta (new - old), and clamps
 * the delta to the range [-0x100, +0x100].
 *
 * Applies the clamped delta: stores the new value to car struct offsets
 * +0x30 and +0x28, then reads a coefficient from car struct offset +0x08,
 * multiplies by 0x38E (910), and stores the 16.16 fixed-point result to
 * offset +0x194.
 *
 * If the scaled coefficient exceeds a threshold at car[+0x0C], and a global
 * race state flag (sym_0608325C) is zero, writes 0x10 to that flag and loads
 * r13 with the scene handler callback (sym_0602CCD0) for the next pipeline
 * stage.
 *
 * Pool entries at 0x0602E5AC..0x0602E5C4 live in the next TU (rot_scroll_hscale)
 * and are reached via .byte-encoded mov.l instructions.
 */

    .section .text.FUN_0602E4F4


    .global rot_scroll_vscale
    .type rot_scroll_vscale, @function
rot_scroll_vscale:
    sts.l pr, @-r15                        ! save PR (return address)
    jsr @r0                                ! call vscale callback (passed in r0)
    nop                                    ! delay slot
    lds.l @r15+, pr                        ! restore PR
    neg r0, r5                             ! r5 = -r0 (negate callback result)
    exts.w r5, r5                          ! sign-extend r5 to 32-bit
    mov.l @r15+, r0                        ! r0 = pop car struct pointer from stack
    exts.w r5, r5                          ! sign-extend r5 again (original codegen artifact)
    mov.w   .L_wpool_0602E524, r1          ! r1 = 0x0028 (car struct vref offset)
    mov.l @(r0, r1), r4                    ! r4 = car[+0x28] (old vertical reference)
    exts.w r4, r4                          ! sign-extend old vref to 32-bit
    mov r5, r6                             ! r6 = r5 (new vscale)
    sub r4, r6                             ! r6 = new_vscale - old_vref (delta)
    exts.w r6, r6                          ! sign-extend delta
    mov.l   .L_pool_neg_clamp, r1          ! r1 = 0xFFFFFF00 (-0x100, lower clamp bound)
    cmp/gt r1, r6                          ! T = (delta > -0x100)?
    bt      .L_check_upper_bound           ! if delta > -0x100, check upper bound
    bra     .L_clamp_delta                 ! else delta <= -0x100, clamp to lower bound
    nop                                    ! delay slot

    .global DAT_0602e51a
DAT_0602e51a:
    mov.b r4, @(r0, r2)                   ! data — referenced externally (not executed)

    .global DAT_0602e51c
DAT_0602e51c:
    .word 0x0000 /* UNKNOWN */

    .global DAT_0602e51e
DAT_0602e51e:
    mov.b r0, @(r0, r0)                   ! data — referenced externally (not executed)

    .global DAT_0602e520
DAT_0602e520:
    .word 0x0010 /* UNKNOWN */

    .global DAT_0602e522
DAT_0602e522:
    sett                                   ! data — referenced externally (not executed)
.L_wpool_0602E524:
    .2byte  0x0028                         /* car struct offset: vertical reference */
    .2byte  0x0000                         /* padding */
    .4byte  sym_0607EAD8                   /* race end state (0/1/2) — used by interp TU */
    .4byte  sym_0602E8AC                   /* main scene render entry — used by interp TU */
    .4byte  atan2                          /* atan2 function — used by interp TU */
.L_pool_neg_clamp:
    .4byte  0xFFFFFF00                     /* -0x100 = lower clamp bound for delta */
.L_check_upper_bound:
    .byte   0xD1, 0x1C    /* mov.l .L_pool_0602E5AC, r1 */  ! r1 = 0x100 (upper clamp bound)
    cmp/gt r1, r6                          ! T = (delta > +0x100)?
    bf      .L_apply_delta                 ! if delta <= +0x100, in range — apply it
.L_clamp_delta:
    mov r1, r6                             ! clamp: r6 = r1 (bound value, -0x100 or +0x100)
.L_apply_delta:
    mov r6, r3                             ! r3 = clamped delta
    add r4, r3                             ! r3 = old_vref + clamped_delta (new vscale)
    exts.w r3, r3                          ! sign-extend new vscale
    .byte   0xD1, 0x1A    /* mov.l .L_pool_0602E5B0, r1 */  ! r1 = 0x30 (vscale store offset A)
    mov.l r3, @(r0, r1)                   ! car[+0x30] = new vscale
    .byte   0xD1, 0x1A    /* mov.l .L_pool_0602E5B4, r1 */  ! r1 = 0x28 (vscale store offset B / vref)
    mov.l r3, @(r0, r1)                   ! car[+0x28] = new vscale (update vref)
    .byte   0xD1, 0x1A    /* mov.l .L_pool_0602E5B8, r1 */  ! r1 = 0x08 (coefficient src offset)
    add r10, r1                            ! r1 = r10 + 0x08 (base + offset)
    mov.l @r1, r3                          ! r3 = coefficient value at [r10 + 0x08]
    .byte   0xD6, 0x19    /* mov.l .L_pool_0602E5BC, r6 */  ! r6 = 0x38E (910, fixed-point scale factor)
    dmuls.l r6, r3                         ! MACL:MACH = r6 * r3 (64-bit signed multiply)
    sts mach, r6                           ! r6 = MACH (upper 32 bits of product)
    sts macl, r3                           ! r3 = MACL (lower 32 bits of product)
    xtrct r6, r3                           ! r3 = (r6[15:0] << 16) | (r3[31:16]) — 16.16 extract
    .byte   0x91, 0x20    /* mov.w .L_wpool_0602E5A2, r1 */ ! r1 = 0x194 (scaled coeff store offset)
    mov.l r3, @(r0, r1)                   ! car[+0x194] = scaled coefficient
    .byte   0x91, 0x1F    /* mov.w .L_wpool_0602E5A4, r1 */ ! r1 = 0x0C (threshold compare offset)
    mov.l @(r0, r1), r4                   ! r4 = car[+0x0C] (threshold value)
    cmp/gt r3, r4                          ! T = (threshold > scaled_coeff)?
    .byte   0x8B, 0x0B    /* bf 0x0602E582 (external) */    ! if threshold <= coeff, branch to hscale
    .byte   0xD1, 0x15    /* mov.l .L_pool_0602E5C0, r1 */  ! r1 = &sym_0608325C (race state flag)
    mov.l @r1, r3                          ! r3 = *sym_0608325C (current flag value)
    tst r3, r3                             ! T = (r3 == 0)?
    .byte   0x8B, 0x07    /* bf 0x0602E582 (external) */    ! if flag != 0, skip — already set
    .byte   0x93, 0x18    /* mov.w .L_wpool_0602E5A6, r3 */ ! r3 = 0x10 (initial flag value)
    mov.l r3, @r1                          ! *sym_0608325C = 0x10 (set race state flag)
    .byte   0xDD, 0x13    /* mov.l .L_pool_0602E5C4, r13 */ ! r13 = sym_0602CCD0 (scene handler callback)
