
    .section .text.FUN_060316D0


    .global collision_impulse
    .type collision_impulse, @function
collision_impulse:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    mov r5, r13
    mov r6, r12
    mov.l @(12, r14), r1
    mov.l @(12, r13), r2
    cmp/gt r2, r1
    bt      .L_a_above_b
    mov.l @(16, r14), r8
    mov.l @(24, r14), r9
    mov.l @(16, r13), r6
    bra     .L_second_path_entry
    mov.l @(24, r13), r7
.L_a_above_b:
    mov.l @(16, r14), r6
    mov.l @(24, r14), r7
    mov.l @(16, r13), r8
    mov.l @(24, r13), r9
    mov.l r0, @-r15
    mov r8, r4
    sub r6, r4
    mov r9, r5
    sub r7, r5
    mov.l   .L_pool_06031754, r0

    .global collision_order_a
    .type collision_order_a, @function
collision_order_a:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r10
    exts.w r10, r10
    mov.l @r15+, r0
    mov.l @(32, r14), r1
    mov.w   DAT_06031750, r4
    extu.w r4, r4
    sub r10, r1
    extu.w r1, r1
    cmp/gt r1, r4
    bt/s    .L_a_heading_ok
    mov.l @(32, r13), r2
    sub r4, r1
.L_a_heading_ok:
    mov.w   DAT_06031750, r4
    sub r10, r2
    extu.w r4, r4
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_headings_indexed_a
    shlr8 r1
    sub r4, r2
.L_headings_indexed_a:
    shlr r1
    shll2 r1
    shlr8 r2
    shlr r2
    shll2 r2
    mov.l   .L_pool_06031758, r3
    add r3, r1
    add r3, r2
    mov.l @r1, r4
    sub r12, r4
    mov.l @r2, r12
    add r12, r4
    cmp/pl r4
    bt      .L_force_positive_a
    bra     .L_epilogue
    nop

    .global DAT_06031750
DAT_06031750:
    .2byte  0x8000              /* half-circle angle constant (180 deg in 16-bit) */
    .2byte  0x0000              /* alignment padding */
.L_pool_06031754:
    .4byte  atan2               /* atan2 function ptr */
.L_pool_06031758:
    .4byte  sym_0605BCC8        /* collision force lookup table base */
.L_force_positive_a:
    mov.l @(40, r14), r1
    mov.l @(40, r13), r2
    sub r2, r1
    extu.w r1, r1
    mov.w   DAT_0603178c, r3
    cmp/ge r1, r3
    bt      .L_in_angle_range_a
    mov r3, r2
    shll r2
    add r2, r3
    cmp/ge r3, r1
    bt      .L_in_angle_range_a
    mov.l @(12, r14), r1
    mov.l @(12, r13), r3
    mov.l   .L_pool_06031790, r2
    add r3, r1
    cmp/ge r1, r2
    bt      .L_apply_xz_impulse_a
    mov.l @(0, r13), r0
    mov.l   .L_pool_06031794, r3
    or r3, r0
    mov.l r0, @(0, r13)
    bra     .L_apply_xz_impulse_a
    nop

    .global DAT_0603178c
DAT_0603178c:
    .2byte  0x4000              /* quarter-circle angle constant (90 deg in 16-bit) */
    .2byte  0x0000              /* alignment padding */
.L_pool_06031790:
    .4byte  0x0001638E          /* height threshold (~91,022 fixed-point) */
.L_pool_06031794:
    .4byte  0x08000000          /* COLLISION_BIT (bit 27 of car flags) */
.L_in_angle_range_a:
    mov.l @(12, r14), r1
    mov.l @(12, r13), r3
    mov.l   .L_pool_060317C8, r2
    sub r3, r1
    cmp/ge r1, r2
    bt      .L_check_sec_heading_a
    mov.l @(0, r13), r0
    mov.l   .L_pool_060317CC, r3
    or r3, r0
    mov.l r0, @(0, r13)
.L_check_sec_heading_a:
    mov.l @(40, r14), r3
    sub r10, r3
    mov.w   DAT_060317c6, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bt      .L_apply_y_impulse_a
    mov r2, r1
    shll r1
    add r1, r2
    cmp/ge r2, r3
    bt      .L_apply_y_impulse_a
    bra     .L_apply_xz_impulse_a
    nop

    .global DAT_060317c6
DAT_060317c6:
    .2byte  0x4000              /* quarter-circle angle constant */
.L_pool_060317C8:
    .4byte  0x0001638E          /* height threshold (~91,022 fixed-point) */
.L_pool_060317CC:
    .4byte  0x08000000          /* COLLISION_BIT (bit 27 of car flags) */
.L_apply_y_impulse_a:
    mov.l r4, @-r15
    mov.l @(32, r14), r4
    mov.l r4, @(32, r13)
    mov r3, r4
    mov.l   .L_pool_06031880, r0
    jsr @r0
    nop
    mov.l @(12, r14), r1
    mov.l @(12, r13), r2
    sub r2, r1
    dmuls.l r0, r1
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r1, r2
    mov.l r2, @(12, r13)
    mov.l @(12, r14), r4
    sub r1, r4
    mov.l r4, @(12, r14)
    mov.l @r15+, r4
.L_apply_xz_impulse_a:
    shlr r4
    mov r4, r3
    mov.l r4, @-r15
    neg r10, r4
    mov r3, r9
    mov.l @(16, r13), r5
    mov.l @(24, r13), r6
    mov.l r5, @(56, r13)
    mov.l r6, @(60, r13)
    mov.l   .L_pool_06031880, r0
    jsr @r0
    nop
    mov r0, r8
    neg r10, r4
    mov.l   .L_pool_06031884, r0
    jsr @r0
    nop
    dmuls.l r0, r3
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    add r3, r5
    mov.l r5, @(16, r13)
    dmuls.l r8, r9
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    add r9, r6
    mov.l r6, @(24, r13)
    mov.l @r15+, r3
    mov.l   .L_fp_half, r5
    add r5, r10
    neg r10, r4
    mov r3, r9
    mov.l @(16, r14), r5
    mov.l @(24, r14), r6
    mov.l r5, @(56, r14)
    mov.l r6, @(60, r14)
    mov.l   .L_pool_06031880, r0
    jsr @r0
    nop
    mov r0, r8
    neg r10, r4
    mov.l   .L_pool_06031884, r0
    jsr @r0
    nop
    dmuls.l r0, r3
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    add r3, r5
    mov.l r5, @(16, r14)
    dmuls.l r8, r9
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    add r9, r6
    mov.l r6, @(24, r14)
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
    .2byte  0x0000              /* alignment padding */
.L_pool_06031880:
    .4byte  cos_lookup          /* cos lookup function ptr (path A) */
.L_pool_06031884:
    .4byte  sin_lookup          /* sin lookup function ptr (path A) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) / 180 deg */
.L_second_path_entry:
    mov.l r0, @-r15
    mov r8, r4
    sub r6, r4
    mov r9, r5
    sub r7, r5
    mov.l   .L_pool_060318E8, r0

    .global collision_order_b
    .type collision_order_b, @function
collision_order_b:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r10
    exts.w r10, r10
    mov.l @r15+, r0
    mov.l @(32, r14), r1
    mov.w   DAT_060318e4, r4
    extu.w r4, r4
    sub r10, r1
    extu.w r1, r1
    cmp/gt r1, r4
    bt/s    .L_b_heading_ok
    mov.l @(32, r13), r2
    sub r4, r1
.L_b_heading_ok:
    sub r10, r2
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_headings_indexed_b
    shlr8 r1
    sub r4, r2
.L_headings_indexed_b:
    shlr r1
    shll2 r1
    shlr8 r2
    shlr r2
    shll2 r2
    mov.l   .L_pool_060318EC, r3
    add r3, r1
    add r3, r2
    mov.l @r1, r4
    sub r12, r4
    mov.l @r2, r12
    add r12, r4
    cmp/pl r4
    bt      .L_force_positive_b
    bra     .L_epilogue
    nop

    .global DAT_060318e4
DAT_060318e4:
    .2byte  0x8000              /* half-circle angle constant (180 deg in 16-bit) */
    .2byte  0x0000              /* alignment padding */
.L_pool_060318E8:
    .4byte  atan2               /* atan2 function ptr (path B) */
.L_pool_060318EC:
    .4byte  sym_0605BCC8        /* collision force lookup table base (path B) */
.L_force_positive_b:
    mov.l @(40, r14), r1
    mov.l @(40, r13), r2
    sub r2, r1
    extu.w r1, r1
    mov.w   DAT_06031918, r3
    cmp/ge r1, r3
    bt      .L_in_angle_range_b
    mov r3, r2
    shll r2
    add r2, r3
    cmp/ge r3, r1
    bt      .L_in_angle_range_b
    mov.l @(12, r14), r1
    mov.l @(12, r13), r3
    mov.l   .L_pool_0603191C, r2
    add r3, r1
    cmp/ge r1, r2
    bf      .L_set_both_flags
    bra     .L_apply_xz_impulse_b
    nop

    .global DAT_06031918
DAT_06031918:
    .2byte  0x4000              /* quarter-circle angle constant */
    .2byte  0x0000              /* alignment padding */
.L_pool_0603191C:
    .4byte  0x0001638E          /* height threshold (~91,022 fixed-point) */
.L_set_both_flags:
    mov.l @(0, r13), r0
    mov.l @(0, r14), r1
    mov.l   .L_pool_06031934, r3
    or r3, r0
    or r3, r1
    mov.l r0, @(0, r13)
    mov.l r1, @(0, r14)
    bra     .L_apply_xz_impulse_b
    nop
    .2byte  0x0000              /* alignment padding */
.L_pool_06031934:
    .4byte  0x08000000          /* COLLISION_BIT (bit 27 of car flags) */
.L_in_angle_range_b:
    mov.l @(12, r13), r1
    mov.l @(12, r14), r3
    mov.l   .L_pool_06031970, r2
    sub r3, r1
    cmp/ge r1, r2
    bt      .L_check_sec_heading_b
    mov.l @(0, r13), r0
    mov.l @(0, r14), r1
    mov.l   .L_pool_06031974, r3
    or r3, r0
    or r3, r1
    mov.l r0, @(0, r13)
    mov.l r1, @(0, r14)
.L_check_sec_heading_b:
    mov.l @(40, r13), r3
    sub r10, r3
    mov.w   DAT_0603196c, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bt      .L_apply_y_impulse_b
    mov r2, r1
    shll r1
    add r1, r2
    cmp/ge r2, r3
    bt      .L_apply_y_impulse_b
    bra     .L_apply_xz_impulse_b
    nop

    .global DAT_0603196c
DAT_0603196c:
    .2byte  0x4000              /* quarter-circle angle constant */
    .2byte  0x0000              /* alignment padding */
.L_pool_06031970:
    .4byte  0x0001638E          /* height threshold (~91,022 fixed-point) */
.L_pool_06031974:
    .4byte  0x08000000          /* COLLISION_BIT (bit 27 of car flags) */
.L_apply_y_impulse_b:
    mov.l r4, @-r15
    mov.l @(32, r13), r4
    mov.l r4, @(32, r14)
    mov.l r4, @(40, r14)
    mov r3, r4
    mov.l   .L_pool_06031A18, r0
    jsr @r0
    nop
    mov.l @(12, r13), r1
    mov.l @(12, r14), r2
    sub r2, r1
    dmuls.l r0, r1
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r1, r2
    mov.l r2, @(12, r14)
    mov.l @(12, r13), r4
    sub r1, r4
    mov.l r4, @(12, r13)
    mov.l @r15+, r4
.L_apply_xz_impulse_b:
    shlr r4
    mov r4, r3
    mov.l r4, @-r15
    neg r10, r4
    mov r3, r9
    mov.l @(16, r14), r5
    mov.l @(24, r14), r6
    mov.l r5, @(56, r14)
    mov.l r6, @(60, r14)
    mov.l   .L_pool_06031A18, r0
    jsr @r0
    nop
    mov r0, r8
    neg r10, r4
    mov.l   .L_pool_06031A1C, r0
    jsr @r0
    nop
    dmuls.l r0, r3
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    add r3, r5
    mov.l r5, @(16, r14)
    dmuls.l r8, r9
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    add r9, r6
    mov.l r6, @(24, r14)
    mov.l @r15+, r3
    mov.l   .L_fp_half_b, r5
    add r5, r10
    neg r10, r4
    mov r3, r9
    mov.l @(16, r13), r5
    mov.l @(24, r13), r6
    mov.l r5, @(56, r13)
    mov.l r6, @(60, r13)
    mov.l   .L_pool_06031A18, r0
    jsr @r0
    nop
    mov r0, r8
    neg r10, r4
    mov.l   .L_pool_06031A1C, r0
    jsr @r0
    nop
    dmuls.l r0, r3
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    add r3, r5
    mov.l r5, @(16, r13)
    dmuls.l r8, r9
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    add r9, r6
    bra     .L_epilogue
    mov.l r6, @(24, r13)
.L_pool_06031A18:
    .4byte  cos_lookup          /* cos lookup function ptr (path B) */
.L_pool_06031A1C:
    .4byte  sin_lookup          /* sin lookup function ptr (path B) */
.L_fp_half_b:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) / 180 deg */

    .global sym_06031A24
sym_06031A24:
    .word 0x0000
    .word 0x0000

    .global sym_06031A28
sym_06031A28:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
