
    .section .text.FUN_060401FC


    .global hw_init_setup
    .type hw_init_setup, @function
hw_init_setup:
    sts.l pr, @-r15
    mov r4, r14

    .global loc_06040200
loc_06040200:
    mov.l r5, @(32, r14)
    mov.l   .Lpool_max_positive, r5
    mov.l   .Lpool_evt_cmd_enqueue, r3
    jsr @r3
    mov.l @(24, r14), r4
    mov r0, r4
    cmp/pz r4
    bt      .Lresult_nonneg
    mov #0x0, r4
.Lresult_nonneg:
    mov.l @(24, r14), r3
    mov.l @(16, r3), r2
    sub r2, r4
    mov.l r4, @(36, r14)
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sym_06040220
sym_06040220:
    mov.l @(4, r15), r1
    tst r5, r5
    bt      .Lcheck_field1
    mov.l @r4, r3
    mov.l   .Lpool_bit30_mask, r2
    and r2, r3
    tst r3, r3
    bt      .Lfield0_no_mask
    mov.l @r4, r3
    mov.l   .Lpool_bit30_clear, r2
    and r2, r3
    mov.l r3, @r5
    bra     .Lcheck_field1
    nop
.Lpool_max_positive:
    .4byte  0x7FFFFFFF                  /* max positive 16.16 */
.Lpool_evt_cmd_enqueue:
    .4byte  evt_cmd_enqueue
.Lpool_bit30_mask:
    .4byte  0x40000000                  /* 0.25 (2.30) or 16384.0 (16.16) */
.Lpool_bit30_clear:
    .4byte  0x3FFFFFFF
.Lfield0_no_mask:
    mov.l @r4, r2
    mov.l r2, @r5
.Lcheck_field1:
    tst r6, r6
    bt      .Lcheck_field1c
    mov.l @(4, r4), r3
    mov.l r3, @r6
.Lcheck_field1c:
    mov.l @(8, r15), r0
    tst r0, r0
    bt      .Lcheck_field3
    mov.l @(8, r15), r3
    mov #0x1C, r0
    mov.b @(r0, r4), r2
    extu.b r2, r2
    mov.l r2, @r3
.Lcheck_field3:
    tst r7, r7
    bt      .Lcheck_field4
    mov.l @(12, r4), r3
    mov.l r3, @r7
.Lcheck_field4:
    mov.l @r15, r0
    tst r0, r0
    bt      .Lcheck_byte_1d
    mov.l @r15, r3
    mov.l @(16, r4), r2
    mov.l r2, @r3
.Lcheck_byte_1d:
    mov.l @(12, r15), r0
    tst r0, r0
    bt      .Lcheck_remaining
    mov.l @(12, r15), r3
    mov #0x1D, r0
    mov.b @(r0, r4), r2
    extu.b r2, r2
    mov.l r2, @r3
.Lcheck_remaining:
    tst r1, r1
    bt      .Lreturn
    mov #0x1D, r0
    mov #0x8, r3
    mov.b @(r0, r4), r5
    extu.b r5, r5
    and r5, r3
    tst r3, r3
    bt      .Lcalc_elapsed
    bra     .Lcheck_complete_flag
    nop
.Lcheck_complete_flag:
    mov #0x4, r2
    and r5, r2
    tst r2, r2
    bt      .Lcalc_elapsed
    mov #0x0, r2
    bra     .Lreturn
    mov.l r2, @r1
.Lcalc_elapsed:
    mov.l @(12, r4), r2
    mov.l @(20, r4), r3
    sub r3, r2
    mov.l r2, @r1
.Lreturn:
    rts
    nop
