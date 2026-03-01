
    .section .text.FUN_0603139C


    .global position_lap_display
    .type position_lap_display, @function
position_lap_display:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r11
    exts.w r11, r11
    mov.l @r15+, r0
    mov #0x0, r9
    mov.w   DAT_0603143a, r4
    mov.l @(48, r13), r1
    extu.w r4, r4
    exts.w r1, r1
    mov #0x1, r7
    mov r4, r3
    extu.w r11, r6
    shll r3
    or r3, r6
    sub r6, r1
    cmp/pl r1
    bt      .L_heading_a_abs
    neg r1, r1
.L_heading_a_abs:
    extu.w r1, r1
    cmp/gt r1, r4
    bt      .L_check_heading_b
    sub r4, r1
    mov #0x0, r7
.L_check_heading_b:
    mov.l @(48, r13), r1
    mov #0x1, r8
    exts.w r1, r1
    mov r4, r3
    shll r3
    extu.w r10, r6
    or r3, r6
    sub r6, r1
    cmp/pl r1
    bt/s    .L_heading_b_abs
    mov.l @(48, r14), r2
    neg r1, r1
.L_heading_b_abs:
    extu.w r1, r1
    .byte   0xBF, 0xA9    /* bsr 0x06031340 — angle range check (external) */
    nop
    cmp/gt r1, r4
    bt      .L_compare_sides
    sub r4, r1
    mov #0x0, r8
.L_compare_sides:
    cmp/eq r7, r8
    bt      .L_calc_sin
    mov #0x1, r9
.L_calc_sin:
    mov.l r4, @-r15
    mov r1, r4
    mov.l   .L_pool_sin_lookup, r0
    jsr @r0
    nop
    mov.l @r15+, r4
    sub r10, r2
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_normalize_heading
    shlr8 r1
    sub r4, r2
.L_normalize_heading:
    shlr r1
    mov #0x0, r7
    mov #0xA, r3
    cmp/ge r1, r3
    bt      .L_build_table_index
    mov #0x37, r3
    cmp/ge r3, r1
    bt      .L_build_table_index
    mov #0x1, r7
.L_build_table_index:
    shll2 r1
    shlr8 r2
    shlr r2
    shll2 r2
    tst r9, r9
    bt      .L_force_table_lookup
    tst r8, r8
    bt      .L_set_side_b
    bra     .L_check_in_range
    mov #0x0, r8

    .global DAT_0603143a
DAT_0603143a:
    .2byte  0x8000
    .4byte  atan2
.L_pool_sin_lookup:
    .4byte  sin_lookup
.L_set_side_b:
    mov #0x1, r8
.L_check_in_range:
    tst r7, r7
    bt      .L_force_table_lookup
    bra     .L_check_secondary_heading
    mov r12, r4
.L_force_table_lookup:
    mov.l   .L_pool_force_table, r3
    add r3, r1
    add r3, r2
    mov.l @r1, r4
    sub r12, r4
    mov.l @r2, r12
    add r12, r4
    cmp/pl r4
    bt      .L_check_secondary_heading
    .byte   0xAF, 0x5F    /* bra 0x06031322 — epilogue (external): no force, exit */
    nop
.L_pool_force_table:
    .4byte  sym_0605BCC8
.L_check_secondary_heading:
    mov.l @(40, r14), r1
    mov.l @(40, r13), r2
    mov #0x0, r11
    sub r2, r1
    extu.w r1, r1
    mov.w   DAT_06031496, r3
    cmp/ge r1, r3
    bt      .L_heading_in_range
    mov r3, r2
    shll r2
    add r2, r3
    cmp/ge r3, r1
    bt      .L_heading_in_range
    mov #0x1, r11
    mov.l @(12, r14), r1
    mov.l @(12, r13), r3
    mov.l   .L_pool_height_thresh_a, r2
    add r3, r1
    mov.l r11, @-r15
    cmp/ge r1, r2
    bf      .L_set_collision_flag
    bra     .L_flag_dispatch
    nop

    .global DAT_06031496
DAT_06031496:
    .2byte  0x4000
.L_pool_height_thresh_a:
    .4byte  0x00042AAA
.L_set_collision_flag:
    mov.l @(0, r13), r1
    mov.l   .L_pool_collision_flag_a, r3
    or r3, r1
    mov.l r1, @(0, r13)
    bra     .L_flag_dispatch
    nop
.L_pool_collision_flag_a:
    .4byte  0x08000000
.L_heading_in_range:
    mov.l r11, @-r15
    mov.l @(12, r13), r1
    mov.l @(12, r14), r3
    mov.l   .L_pool_height_thresh_b, r2
    sub r3, r1
    cmp/ge r1, r2
    bt      .L_check_force_direction
    mov.l @(0, r13), r1
    mov.l   .L_pool_collision_flag_b, r3
    or r3, r1
    mov.l r1, @(0, r13)
    bra     .L_flag_dispatch
    nop
    .2byte  0x0000
.L_pool_height_thresh_b:
    .4byte  0x00042AAA
.L_pool_collision_flag_b:
    .4byte  0x08000000
.L_check_force_direction:
    tst r7, r7
    bf      .L_check_angle_range
    mov.l @(12, r14), r1
    mov.l   .L_pool_height_thresh_c, r2
    mov.l @(12, r13), r3
    shlr r2
    sub r1, r3
    cmp/gt r3, r2
    bt      .L_check_angle_range
    tst r8, r8
    mov.l @(0, r13), r2
    mov.l   .L_pool_direction_flag, r3
    bt      .L_apply_dir_flag
    shlr r3
.L_apply_dir_flag:
    or r3, r2
    bra     .L_flag_dispatch
    mov.l r2, @(0, r13)
    .2byte  0x0000
.L_pool_height_thresh_c:
    .4byte  0x00042AAA
.L_pool_direction_flag:
    .4byte  0x20000000
.L_check_angle_range:
    mov.l @(40, r13), r3
    sub r10, r3
    mov.w   DAT_06031516, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bt      .L_apply_impulse
    mov r2, r1
    shll r1
    add r1, r2
    cmp/ge r2, r3
    bt      .L_apply_impulse
    bra     .L_flag_dispatch
    nop

    .global DAT_06031516
DAT_06031516:
    .2byte  0x4000
.L_apply_impulse:
    mov.l r4, @-r15
    mov.l r0, @-r15
    tst r7, r7
    bt      .L_compute_cos
    mov.l @(32, r13), r4
    mov.l r4, @(48, r14)
    mov.w   .L_wpool_struct_off_0x208, r1
    mov #0x8, r2
    add r13, r1
    mov.l r2, @r1
.L_compute_cos:
    mov r3, r4
    mov.l   .L_pool_cos_lookup_a, r0
    jsr @r0
    nop
    mov.l @(12, r13), r1
    mov.l @(12, r14), r2
    sub r2, r1
    dmuls.l r0, r1
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    shar r1
    add r1, r2
    mov.l r2, @(12, r14)
    mov.l @(12, r13), r4
    mov.w   .L_wpool_struct_off_0x194, r3
    add r13, r3
    sub r1, r4
    mov.l r4, @r3
    mov.l @r15+, r0
    mov.l @r15+, r4
.L_flag_dispatch:
    mov.l @r15+, r11
    tst r7, r7
    bf      .L_direction_dispatch
    mov.l   .L_pool_timer_byte, r5
    mov.b @r5, r3
    tst r3, r3
    bf      .L_scale_by_counter
    mov #0x3, r3
    bra     .L_scale_by_counter
    mov.b r3, @r5
.L_wpool_struct_off_0x208:
    .2byte  0x0208
.L_wpool_struct_off_0x194:
    .2byte  0x0194
    .2byte  0x0000
.L_pool_cos_lookup_a:
    .4byte  cos_lookup
.L_pool_timer_byte:
    .4byte  sym_0602FD9A
.L_direction_dispatch:
    mov.l r0, @-r15
    mov.l r4, @-r15
    tst r11, r11
    mov.l   .L_pool_counter_addr, r5
    mov.l   .L_pool_crossing_flag, r10
    mov.l @(0, r14), r2
    mov.w @r10, r10
    bt      .L_not_crossed
    tst r8, r8
    bt      .L_crossed_dir_fwd
    bra     .L_not_crossed_fwd
    nop
.L_pool_counter_addr:
    .4byte  sym_0602FD98
.L_pool_crossing_flag:
    .4byte  sym_06031A24
.L_not_crossed:
    tst r8, r8
    bt      .L_not_crossed_no_dir
    bra     .L_not_crossed_rev
    nop
.L_crossed_dir_fwd:
    add #0x1, r5
    tst r10, r10
    mov #-0x80, r3
    extu.b r3, r3
    bt      .L_store_flags
    mov.w   .L_wpool_flag_0x200_a, r3
    bra     .L_store_flags
    nop
.L_wpool_flag_0x200_a:
    .2byte  0x0200
.L_not_crossed_fwd:
    tst r10, r10
    mov #0x40, r3
    bt      .L_store_flags
    mov.w   .L_wpool_flag_0x100_a, r3
    bra     .L_store_flags
    nop
.L_wpool_flag_0x100_a:
    .2byte  0x0100
.L_not_crossed_rev:
    add #0x1, r5
    tst r10, r10
    mov.w   .L_wpool_flag_0x200_b, r3
    bt      .L_store_flags
    mov #-0x80, r3
    bra     .L_store_flags
    extu.b r3, r3
.L_wpool_flag_0x200_b:
    .2byte  0x0200
.L_not_crossed_no_dir:
    tst r10, r10
    mov.w   .L_wpool_flag_0x100_b, r3
    bt      .L_store_flags
    mov #0x40, r3
.L_store_flags:
    mov.b @r5, r4
    or r3, r2
    tst r4, r4
    mov.l r2, @(0, r14)
    bf      .L_restore_and_scale
    mov #0x3, r4
    mov.b r4, @r5
.L_restore_and_scale:
    mov.l @r15+, r4
    mov.l @r15+, r0
    mov.w   .L_wpool_quarter_circle, r3
    tst r8, r8
    mov.l @(48, r13), r10
    bf/s    .L_multiply_force
    extu.w r10, r10
    mov r3, r7
    shll r7
    add r7, r3
.L_multiply_force:
    dmuls.l r0, r4
    add r3, r10
    tst r9, r9
    sts mach, r0
    sts macl, r4
    xtrct r0, r4
    bt      .L_scale_by_counter
    mov.l   .L_pool_crossing_offset, r3
    add r3, r4
.L_scale_by_counter:
    mov.w   DAT_0603162e, r3
    add r14, r3
    mov.w @r3, r0
    mov #0x8, r5
    cmp/ge r5, r0
    bt      .L_force_zero_forward
    add #-0x2, r5
    cmp/ge r5, r0
    bt      .L_force_zero_lateral
    shlr r4
    mov r4, r3
    shlr r3
    add r3, r4
    bra     .L_apply_position_impulse
    mov.l r4, @-r15
.L_wpool_flag_0x100_b:
    .2byte  0x0100
.L_wpool_quarter_circle:
    .2byte  0x4000

    .global DAT_0603162e
DAT_0603162e:
    .2byte  0x007C
.L_pool_crossing_offset:
    .4byte  0x0000D999
.L_force_zero_lateral:
    mov #0x0, r3
    bra     .L_apply_position_impulse
    mov.l r4, @-r15
.L_force_zero_forward:
    mov r4, r3
    mov #0x0, r4
    mov.l r4, @-r15
.L_apply_position_impulse:
    neg r10, r4
    mov r3, r9
    mov.l @(16, r14), r5
    mov.l @(24, r14), r6
    mov.l r5, @(56, r14)
    mov.l r6, @(60, r14)
    mov.l   .L_pool_cos_lookup_b, r0
    jsr @r0
    nop
    mov r0, r8
    neg r10, r4
    mov.l   .L_pool_sin_lookup_b, r0
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
    mov.l   .L_fp_half, r5
    mov r3, r4
    shlr r3
    add r4, r3
    add r5, r10
    neg r10, r4
    mov r3, r9
    mov.l @(16, r13), r5
    mov.l @(24, r13), r6
    mov.l r5, @(56, r13)
    mov.l r6, @(60, r13)
    mov.l   .L_pool_cos_lookup_b, r0
    jsr @r0
    nop
    mov r0, r8
    neg r10, r4
    mov.l   .L_pool_sin_lookup_b, r0
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
    .byte   0xAE, 0x36    /* bra 0x06031322 — epilogue (external): done, exit */
    mov.l r6, @(24, r13)
    .2byte  0x0000
.L_pool_cos_lookup_b:
    .4byte  cos_lookup
.L_pool_sin_lookup_b:
    .4byte  sin_lookup
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) / half rotation */

    .global sym_060316C4
sym_060316C4:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
