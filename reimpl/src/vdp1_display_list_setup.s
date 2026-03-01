
    .section .text.FUN_0602C690


    .global vdp1_display_list_setup
    .type vdp1_display_list_setup, @function
vdp1_display_list_setup:
    sts.l pr, @-r15
    mov.w   .L_off_flag_word_a, r1
    mov.w   .L_off_flag_word_b, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    bsr     .L_activation_weight_calc
    or r3, r4
    mov r4, r10
    mov.w   .L_off_flag_word_c, r1
    mov.w   .L_off_flag_word_d, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    bsr     .L_activation_weight_calc
    or r3, r4
    mov r4, r11
    mov.w   .L_off_vel_x, r1
    mov.w   .L_off_vel_y, r2
    mov.l @(r0, r1), r5
    mov.l @(r0, r2), r6
    neg r5, r5
    neg r6, r6
    mov r0, r14
    mov.w   .L_off_vel_state_x, r1
    mov.w   .L_off_vel_state_y, r2
    mov.l @(r0, r1), r9
    mov.l @(r0, r2), r4
    mov r9, r7
    xor r5, r7
    cmp/pz r7
    bt      .L_signs_agree
    mov #0x0, r9
.L_signs_agree:
    mov.l r6, @-r15
    mov.l r5, @-r15
    mov.l   .L_horiz_scale_factor, r5
    mov r4, r7
    dmuls.l r4, r5
    mov.l   .L_vert_scale_factor, r1
    sts mach, r4
    sts macl, r8
    mov #0x0, r13
    xtrct r4, r8
    dmuls.l r7, r1
    mov.l @(28, r0), r4
    mov.l   .L_sin_index_range, r5
    sts mach, r1
    sts macl, r7
    mov.l   .L_sin_lookup_ptr, r0
    xtrct r1, r7
    cmp/pz r4
    bt      .L_heading_valid
    mov #0x0, r4
    mov #0x0, r13
.L_heading_valid:
    jsr @r0
    shar r4
    dmuls.l r0, r5
    mov.w   .L_off_speed_delta, r1
    mov.l   .L_normalize_factor, r3
    sts mach, r5
    sts macl, r4
    mov r14, r0
    xtrct r5, r4
    tst r13, r13
    mov r4, r13
    mov.l @(r0, r1), r5
    bf      .L_heading_was_invalid
    shll r13
    add r5, r13
    bra     .L_compute_scale_products
    add r4, r5

    .global DAT_0602c71a
.L_off_flag_word_a:
DAT_0602c71a:
    .2byte  0x0120                      /* car+0x120: activation flag word A [HIGH] */

    .global DAT_0602c71c
.L_off_flag_word_b:
DAT_0602c71c:
    .2byte  0x0124                      /* car+0x124: activation flag word B [HIGH] */

    .global DAT_0602c71e
.L_off_flag_word_c:
DAT_0602c71e:
    .2byte  0x0128                      /* car+0x128: activation flag word C [HIGH] */

    .global DAT_0602c720
.L_off_flag_word_d:
DAT_0602c720:
    .2byte  0x012C                      /* car+0x12C: activation flag word D [HIGH] */

    .global DAT_0602c722
.L_off_vel_x:
DAT_0602c722:
    .2byte  0x0060                      /* car+0x60: velocity X component [HIGH] */

    .global DAT_0602c724
.L_off_vel_y:
DAT_0602c724:
    .2byte  0x0064                      /* car+0x64: velocity Y component [HIGH] */

    .global DAT_0602c726
.L_off_vel_state_x:
DAT_0602c726:
    .2byte  0x0100                      /* car+0x100: velocity state X [HIGH] */

    .global DAT_0602c728
.L_off_vel_state_y:
DAT_0602c728:
    .2byte  0x0104                      /* car+0x104: velocity state Y [HIGH] */

    .global DAT_0602c72a
.L_off_speed_delta:
DAT_0602c72a:
    .2byte  0x00FC                      /* car+0xFC: clamped speed delta [HIGH] */
.L_horiz_scale_factor:
    .4byte  0x03700000                  /* 0x03700000 = ~880.0 FP16.16 horizontal velocity scale factor [HIGH] */
.L_vert_scale_factor:
    .4byte  0x02D00000                  /* 0x02D00000 = ~720.0 FP16.16 vertical velocity scale factor [HIGH] */
.L_sin_index_range:
    .4byte  0x00000645                  /* 0x645 = 1605, sin table index range [MEDIUM] */
.L_sin_lookup_ptr:
    .4byte  sin_lookup                  /* -> sin_lookup function (trig table) [HIGH] */
.L_normalize_factor:
    .4byte  0x251B1285                  /* FP normalization constant for scale blend [MEDIUM] */
.L_heading_was_invalid:
    neg r13, r13
    shll r13
    add r5, r13
    add r4, r5
.L_compute_scale_products:
    dmuls.l r3, r5
    mov.l @r15+, r5
    sts mach, r4
    sts macl, r0
    xtrct r4, r0
    dmuls.l r3, r13
    sts mach, r3
    sts macl, r13
    xtrct r3, r13
    mov r9, r4
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
    add r8, r5
    sub r0, r5
    dmuls.l r10, r5
    mov.l   .L_display_scale_norm, r3
    sts mach, r5
    sts macl, r4
    xtrct r5, r4
    dmuls.l r4, r3
    sts mach, r4
    sts macl, r10
    xtrct r4, r10
    mov.l @r15+, r4
    dmuls.l r4, r9
    sts mach, r5
    sts macl, r4
    xtrct r5, r4
    add r7, r4
    add r13, r4
    dmuls.l r4, r11
    mov.l   .L_display_scale_norm, r3
    sts mach, r5
    sts macl, r4
    xtrct r5, r4
    dmuls.l r4, r3
    sts mach, r4
    sts macl, r11
    xtrct r4, r11
    mov.l   .L_x_scale_min, r1
    mov.l   .L_x_scale_max, r2
    cmp/gt r1, r10
    bt      .L_x_above_min
    mov r1, r10
    bra     .L_x_clamped
    nop
.L_display_scale_norm:
    .4byte  0x00028000                  /* 0x00028000 = ~2.5 FP16.16 display scale normalization [HIGH] */
.L_x_scale_min:
    .4byte  0x01600000                  /* 0x01600000 = ~352.0 FP16.16 minimum X display scale [HIGH] */
.L_x_scale_max:
    .4byte  0x0C080000                  /* 0x0C080000 = ~3080.0 FP16.16 maximum X display scale [HIGH] */
.L_x_above_min:
    cmp/ge r10, r2
    bt      .L_x_clamped
    mov r2, r10
.L_x_clamped:
    mov.l   .L_y_scale_min, r1
    mov.l   .L_y_scale_max, r2
    cmp/gt r1, r11
    bt      .L_y_above_min
    mov r1, r11
    bra     .L_y_clamped
    nop
.L_y_scale_min:
    .4byte  0x01200000                  /* 0x01200000 = ~288.0 FP16.16 minimum Y display scale [HIGH] */
.L_y_scale_max:
    .4byte  0x09D80000                  /* 0x09D80000 = ~2520.0 FP16.16 maximum Y display scale [HIGH] */
.L_y_above_min:
    cmp/ge r11, r2
    bt      .L_y_clamped
    mov r2, r11
.L_y_clamped:
    mov r14, r0
    mov.w   .L_off_display_scale_x, r1
    mov.w   .L_off_display_scale_y, r3
    mov.l @(r0, r1), r2
    mov.l @(r0, r3), r4
    sub r2, r10
    sub r4, r11
    shar r10
    shar r11
    shar r10
    shar r11
    add r10, r2
    add r11, r4
    mov.l r2, @(r0, r1)
    lds.l @r15+, pr
    rts
    mov.l r4, @(r0, r3)

    .global DAT_0602c7f8
.L_off_display_scale_x:
DAT_0602c7f8:
    .2byte  0x0140                      /* car+0x140: smoothed X display scale output [HIGH] */

    .global DAT_0602c7fa
.L_off_display_scale_y:
DAT_0602c7fa:
    .2byte  0x0144                      /* car+0x144: smoothed Y display scale output [HIGH] */

.L_activation_weight_calc:
    mov.l @(8, r0), r3
    mov #0xA, r2
    mov.l r10, @-r15
    cmp/ge r3, r2
    .byte   0x8D, 0x69    /* bt/s 0x0602C8DA (external: early exit with 0x10000) */
    mov #0x0, r9
    mov #0x0, r8
    .byte   0x96, 0x45    /* mov.w .L_wpool_0602C898, r6 (r6 = 0x0001, activation bit 0 mask) [HIGH] */
    tst r6, r4
    not r6, r7
    bt/s    .L_test_bit_2
    and r7, r4
    .byte   0x98, 0x41    /* mov.w .L_wpool_0602C89A, r8 (r8 = 0x00EE, activation weight for bit 0 = 238) [HIGH] */
    mov #0x1, r9
.L_test_bit_2:
    .byte   0x96, 0x40    /* mov.w .L_wpool_0602C89C, r6 (r6 = 0x0004, activation bit 2 mask) [HIGH] */
    tst r6, r4
    not r6, r7
    bt/s    .L_test_bit_1
    and r7, r4
    .byte   0x96, 0x3C    /* mov.w .L_wpool_0602C89E, r6 (r6 = 0x00B4, activation weight for bit 2 = 180) [HIGH] */
    add r6, r8
    add #0x1, r9
.L_test_bit_1:
    .byte   0x96, 0x3A    /* mov.w .L_wpool_0602C8A0, r6 (r6 = 0x0002, activation bit 1 mask) [HIGH] */
    tst r6, r4
    not r6, r7
    bt/s    .L_test_bit_4
    and r7, r4
    .byte   0x96, 0x36    /* mov.w .L_wpool_0602C8A2, r6 (r6 = 0x00D2, activation weight for bit 1 = 210) [HIGH] */
    add r6, r8
    add #0x1, r9
.L_test_bit_4:
    .byte   0x96, 0x34    /* mov.w .L_wpool_0602C8A4, r6 (r6 = 0x0010, activation bit 4 mask) [HIGH] */
    tst r6, r4
    not r6, r7
    bt/s    .L_test_bit_5
    and r7, r4
    .byte   0x96, 0x30    /* mov.w .L_wpool_0602C8A6, r6 (r6 = 0x00F6, activation weight for bit 4 = 246) [HIGH] */
    add r6, r8
    add #0x1, r9
.L_test_bit_5:
    .byte   0x96, 0x2E    /* mov.w .L_wpool_0602C8A8, r6 (r6 = 0x0020, activation bit 5 mask) [HIGH] */
    tst r6, r4
    not r6, r7
    bt/s    .L_test_remainder
    and r7, r4
    .byte   0x96, 0x2A    /* mov.w .L_wpool_0602C8AA, r6 (r6 = 0x00FA, activation weight for bit 5 = 250) [HIGH] */
    add r6, r8
    add #0x1, r9
.L_test_remainder:
    mov #0x0, r6
    cmp/eq r6, r4
    bt      .L_all_bits_tested
    .byte   0x96, 0x25    /* mov.w .L_wpool_0602C8AC, r6 (r6 = 0x0096, activation weight for remainder bits = 150) [HIGH] */
    add r6, r8
    add #0x1, r9
.L_all_bits_tested:
    tst r9, r9
    .byte   0x8D, 0x15    /* bt/s 0x0602C894 (external: no flags, return r4=0) */
    mov #0x0, r4
    .byte   0xD2, 0x11    /* mov.l .L_pool_0602C8B0, r2 (r2 = sym_06045AEC, activation weight lookup table) [MEDIUM] */
    mov #0x1, r4
    cmp/eq r4, r9
    .byte   0x89, 0x22    /* bt 0x0602C8B8 (external: 1-flag path, shll2+lookup) */
    shll r4
    cmp/eq r4, r9
    .byte   0x89, 0x24    /* bt 0x0602C8C2 (external: 2-flag path, shlr+shll2+lookup) */
    shll r4
    cmp/eq r4, r9
    .byte   0x89, 0x27    /* bt 0x0602C8CE (external: 4-flag path, shlr2+shll2+lookup) */
    mov.l r0, @-r15
    mov r8, r1
    .byte   0xDC, 0x0C    /* mov.l .L_pool_0602C8B4, r12 (r12 = hw_divide_protected @ 0x0602ECCC) [HIGH] */
