
    .section .text.FUN_0602E4F4


    .global rot_scroll_vscale
    .type rot_scroll_vscale, @function
rot_scroll_vscale:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r5
    exts.w r5, r5
    mov.l @r15+, r0
    exts.w r5, r5
    mov.w   .L_w_vref_offset, r1
    mov.l @(r0, r1), r4
    exts.w r4, r4
    mov r5, r6
    sub r4, r6
    exts.w r6, r6
    mov.l   .L_pool_neg_clamp, r1
    cmp/gt r1, r6
    bt      .L_check_upper_bound
    bra     .L_clamp_delta
    nop

    .global DAT_0602e51a
DAT_0602e51a:
    mov.b r4, @(r0, r2)

    .global DAT_0602e51c
DAT_0602e51c:
    .word 0x0000

    .global DAT_0602e51e
DAT_0602e51e:
    mov.b r0, @(r0, r0)

    .global DAT_0602e520
DAT_0602e520:
    .word 0x0010

    .global DAT_0602e522
DAT_0602e522:
    sett
.L_w_vref_offset:
    .2byte  0x0028                     /* [HIGH] car struct offset: vertical reference (+0x28) */
    .2byte  0x0000
    .4byte  sym_0607EAD8               /* [HIGH] race end state — used by interp TU */
    .4byte  sym_0602E8AC               /* [MEDIUM] main scene render entry — used by interp TU */
    .4byte  atan2                      /* [HIGH] atan2 function — used by interp TU */
.L_pool_neg_clamp:
    .4byte  0xFFFFFF00                 /* [HIGH] -0x100 = lower clamp bound for delta */
.L_check_upper_bound:
    .byte   0xD1, 0x1C    /* mov.l .L_pool_0602E5AC, r1 */  ! r1 = 0x100 (upper clamp bound)
    cmp/gt r1, r6
    bf      .L_apply_delta
.L_clamp_delta:
    mov r1, r6
.L_apply_delta:
    mov r6, r3
    add r4, r3
    exts.w r3, r3
    .byte   0xD1, 0x1A    /* mov.l .L_pool_0602E5B0, r1 */  ! r1 = 0x30 (vscale store offset A)
    mov.l r3, @(r0, r1)
    .byte   0xD1, 0x1A    /* mov.l .L_pool_0602E5B4, r1 */  ! r1 = 0x28 (vscale store offset B / vref)
    mov.l r3, @(r0, r1)
    .byte   0xD1, 0x1A    /* mov.l .L_pool_0602E5B8, r1 */  ! r1 = 0x08 (coefficient src offset)
    add r10, r1
    mov.l @r1, r3
    .byte   0xD6, 0x19    /* mov.l .L_pool_0602E5BC, r6 */  ! r6 = 0x38E (910, fixed-point scale factor)
    dmuls.l r6, r3
    sts mach, r6
    sts macl, r3
    xtrct r6, r3
    .byte   0x91, 0x20    /* mov.w .L_wpool_0602E5A2, r1 */ ! r1 = 0x194 (scaled coeff store offset)
    mov.l r3, @(r0, r1)
    .byte   0x91, 0x1F    /* mov.w .L_wpool_0602E5A4, r1 */ ! r1 = 0x0C (threshold compare offset)
    mov.l @(r0, r1), r4
    cmp/gt r3, r4
    .byte   0x8B, 0x0B    /* bf 0x0602E582 (external) */    ! if threshold <= coeff, branch to hscale
    .byte   0xD1, 0x15    /* mov.l .L_pool_0602E5C0, r1 */  ! r1 = &sym_0608325C (race state flag)
    mov.l @r1, r3
    tst r3, r3
    .byte   0x8B, 0x07    /* bf 0x0602E582 (external) */    ! if flag != 0, skip — already set
    .byte   0x93, 0x18    /* mov.w .L_wpool_0602E5A6, r3 */ ! r3 = 0x10 (initial flag value)
    mov.l r3, @r1
    .byte   0xDD, 0x13    /* mov.l .L_pool_0602E5C4, r13 */ ! r13 = sym_0602CCD0 (scene handler callback)
