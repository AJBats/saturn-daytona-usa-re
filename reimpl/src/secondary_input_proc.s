
    .section .text.FUN_06035A08


    .global secondary_input_proc
    .type secondary_input_proc, @function
secondary_input_proc:
    mov.l r14, @-r15
    sts.l macl, @-r15
    sts.l mach, @-r15
    mov.l   .L_pool_06035B20, r3
    mov.l   .L_pool_06035B24, r0
    mov r4, r10
    xor r6, r10
    mov r4, r8
    shlr16 r8
    shlr2 r8
    shlr2 r8
    and r3, r8
    mov r6, r9
    shlr16 r9
    shlr2 r9
    shlr2 r9
    and r3, r9
    and r0, r4
    and r0, r6
    cmp/eq r3, r8
    .byte   0x89, 0x86    /* bt 0x06035940 (external) — exp_a_max: handle NaN/Inf for A */
    cmp/eq r3, r9
    .byte   0x89, 0x98    /* bt 0x06035968 (external) — exp_b_zero: handle NaN/Inf for B */
    tst r8, r8
    .byte   0x89, 0xA2    /* bt 0x06035980 (external) — shift_up_3: handle zero/denorm A */
    tst r9, r9
    .byte   0x89, 0xB2    /* bt 0x060359A4 (external) — norm_b_start: handle zero/denorm B */
    mov.l   .L_pool_06035B30, r2
    add r9, r8
    sub r2, r8
    cmp/ge r3, r8
    .byte   0x89, 0xC4    /* bt 0x060359D2 (external) — fadd_epilog: overflow → Inf */
    mov #-0x35, r3
    cmp/gt r8, r3
    .byte   0x89, 0xBC    /* bt 0x060359C8 (external) — exact_zero: underflow → 0 */
    mov.l   .L_pool_06035B28, r0
    or r0, r4
    or r0, r6
    dmulu.l r5, r7
    sts mach, r2
    sts macl, r3
    dmulu.l r4, r6
    sts mach, r9
    sts macl, r1
    dmulu.l r4, r7
    sts mach, r4
    sts macl, r7
    dmulu.l r5, r6
    sts mach, r6
    sts macl, r0
    clrt
    addc r2, r7
    addc r4, r6
    mov #0x0, r2
    addc r7, r0
    addc r6, r1
    addc r2, r9
    tst r3, r3
    bt      .L_sticky_clear
    or #0x1, r0
.L_sticky_clear:
    xtrct r0, r3
    xtrct r1, r0
    xtrct r9, r1
    shlr r1
    rotcr r0
    rotcr r3
    mov.l   .L_pool_06035B2C, r5
    tst r1, r5
    bt      .L_no_extra_shift
    shlr r1
    rotcr r0
    rotcr r3
    add #0x1, r8
    mov.l   .L_pool_06035B20, r4
    cmp/eq r4, r8
    bf      .L_no_extra_shift
    .byte   0xAF, 0x97    /* bra 0x060359D2 (external) — fadd_epilog: overflow → Inf */
    nop
.L_no_extra_shift:
    tst r3, r3
    bt      .L_round_skip
    or #0x1, r0
.L_round_skip:
    cmp/pl r8
    bt      .L_pack_mantissa
    neg r8, r8
    add #0x1, r8
.L_denorm_shift:
    shlr r1
    rotcr r0
    .word 0x0329
    dt r8
    bf/s    .L_denorm_shift
    or r3, r0
.L_pack_mantissa:
    tst #0x4, r0
    bt      .L_no_round
    tst #0xB, r0
    bt      .L_no_round
    mov #0x8, r4
    addc r4, r0
    addc r2, r1
    cmp/gt r1, r5
    bt      .L_no_round
    shlr r1
    rotcr r0
    add #0x1, r8
.L_no_round:
    shlr r1
    rotcr r0
    shlr r1
    rotcr r0
    shlr r1
    rotcr r0
    mov.l   .L_pool_06035B24, r2
    and r2, r1
    shll16 r8
    shll2 r8
    shll2 r8
    or r8, r1
    shll r1
    shll r10
    rotcr r1
    lds.l @r15+, mach
    lds.l @r15+, macl
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    mov.l @r15+, r3
    mov.l @r15+, r2
    mov.l @(24, r15), r6
    mov.l r1, @r6
    mov.l r0, @(4, r6)
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @r15+, r5
    mov.l @r15+, r4
    mov.l @r15+, r1
    mov.l @r15+, r0
    rts
    add #0x14, r15
.L_pool_06035B20:
    .4byte  0x000007FF
.L_pool_06035B24:
    .4byte  0x000FFFFF
.L_pool_06035B28:
    .4byte  0x00100000
.L_pool_06035B2C:
    .4byte  0x01000000
.L_pool_06035B30:
    .4byte  0x000003FF

    .global sym_06035B34
sym_06035B34:
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l @(24, r15), r4
    mov.l @(28, r15), r5
    mov.l @(16, r15), r6
    mov.l @(20, r15), r7
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l   .L_cmp_exp_field, r0
    mov r4, r10
    mov r6, r11
    mov r4, r8
    and r0, r8
    mov r6, r9
    and r0, r9
    mov.l   .L_cmp_mant_field, r0
    and r0, r4
    and r0, r6
    mov.l   .L_cmp_exp_field, r0
    cmp/eq r0, r8
    bt      .L_cmp_a_special
.L_cmp_check_b:
    cmp/eq r0, r9
    bt      .L_cmp_b_special
.L_cmp_check_a_zero:
    tst r8, r8
    bt      .L_cmp_both_zero
.L_cmp_compare:
    cmp/eq r10, r11
    bf      .L_cmp_not_equal
    cmp/eq r5, r7
    bf      .L_cmp_not_equal
    bra     .L_cmp_done
    mov #0x0, r0
.L_cmp_not_equal:
    mov #0x1, r0
.L_cmp_done:
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @r15+, r5
    mov.l @r15+, r4
    rts
    add #0x10, r15
.L_cmp_a_special:
    tst r4, r4
    bf      .L_cmp_not_equal
    tst r5, r5
    bf      .L_cmp_not_equal
    bra     .L_cmp_check_b
    nop
.L_cmp_b_special:
    tst r6, r6
    bf      .L_cmp_not_equal
    tst r7, r7
    bf      .L_cmp_not_equal
    bra     .L_cmp_check_a_zero
    nop
.L_cmp_both_zero:
    tst r9, r9
    bf      .L_cmp_not_equal
    tst r4, r4
    bf      .L_cmp_compare
    tst r5, r5
    bf      .L_cmp_compare
    tst r6, r6
    bf      .L_cmp_not_equal
    tst r7, r7
    bf      .L_cmp_not_equal
    bra     .L_cmp_done
    mov #0x0, r0
.L_cmp_exp_field:
    .4byte  0x7FF00000
.L_cmp_mant_field:
    .4byte  0x000FFFFF

    .global sym_06035BC8
sym_06035BC8:
    mov.l r1, @-r15
    mov.l r2, @-r15
    tst r0, r0
    bt      .L_i2f_zero
    mov.l   .L_i2f_bias_max, r1
.L_i2f_normalize:
    shll r0
    bf/s    .L_i2f_normalize
    add #-0x1, r1
    mov r0, r2
    shll16 r2
    shll2 r2
    shll2 r2
    shlr8 r0
    shlr2 r0
    shlr2 r0
    shll16 r1
    shll2 r1
    shll2 r1
    or r1, r0
.L_i2f_store:
    mov.l @(8, r15), r1
    mov.l r0, @r1
    mov.l r2, @(4, r1)
    mov.l @r15+, r2
    mov.l @r15+, r1
    rts
    add #0x4, r15
.L_i2f_zero:
    mov #0x0, r2
    bra     .L_i2f_store
    mov #0x0, r0
    .2byte  0x0009
.L_i2f_bias_max:
    .4byte  0x0000041F
