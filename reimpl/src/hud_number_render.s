
    .section .text.FUN_0603101E


    .global hud_number_render
    .type hud_number_render, @function
hud_number_render:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r11
    exts.w r11, r11
    mov.l @r15+, r0
    mov #0x0, r9
    mov.w   DAT_060310b8, r4
    mov.l @(48, r14), r1
    extu.w r4, r4
    mov #0x1, r7
    mov r4, r3
    extu.w r11, r6
    shll r3
    or r3, r6
    sub r6, r1
    cmp/pl r1
    bt      .L_angle_a_positive
    neg r1, r1
.L_angle_a_positive:
    extu.w r1, r1
    cmp/gt r1, r4
    bt      .L_check_heading_b
    sub r4, r1
    mov #0x0, r7
.L_check_heading_b:
    mov.l @(48, r14), r1
    mov #0x1, r8
    mov r4, r3
    extu.w r10, r6
    shll r3
    or r3, r6
    sub r6, r1
    cmp/pl r1
    bt/s    .L_angle_b_positive
    mov.l @(48, r13), r2
    neg r1, r1
.L_angle_b_positive:
    extu.w r1, r1
    bsr     .L_check_reverse_dir
    nop
    cmp/gt r1, r4
    bt      .L_compare_directions
    sub r4, r1
    mov #0x0, r8
.L_compare_directions:
    cmp/eq r7, r8
    bt      .L_decompose_angle
    mov #0x1, r9
.L_decompose_angle:
    mov.l r4, @-r15
    mov r1, r4
    .byte   0xD0, 0x10    /* mov.l .L_pool_sin_lookup_a, r0 */
    jsr @r0
    nop
    mov.l @r15+, r4
    sub r10, r2
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_angle_halved
    shlr8 r1
    sub r4, r2
.L_angle_halved:
    shlr r1
    mov #0x0, r7
    mov #0xA, r3
    cmp/ge r1, r3
    bt      .L_done_validity_check
    mov #0x37, r3
    cmp/ge r3, r1
    bt      .L_done_validity_check
    mov #0x1, r7
.L_done_validity_check:
    shll2 r1
    shlr8 r2
    shlr r2
    shll2 r2
    tst r9, r9
    bt      .L_force_table_lookup
    tst r8, r8
    bt      .L_set_approach_flag
    bra     .L_check_validity
    mov #0x0, r8

    .global DAT_060310b8
DAT_060310b8:
    .2byte  0x8000
    .2byte  0x0000
    .4byte  atan2
.L_pool_sin_lookup_a:
    .4byte  sin_lookup
.L_set_approach_flag:
    mov #0x1, r8
.L_check_validity:
    tst r7, r7
    bt      .L_force_table_lookup
    bra     .L_heading_diff_check
    mov r12, r4
.L_force_table_lookup:
    .byte   0xD3, 0x05    /* mov.l .L_pool_force_table, r3 */
    add r3, r1
    add r3, r2
    mov.l @r1, r4
    sub r12, r4
    mov.l @r2, r12
    add r12, r4
    cmp/pl r4
    bt      .L_heading_diff_check
    bra     .L_epilogue
    nop
.L_pool_force_table:
    .4byte  sym_0605BCC8
.L_heading_diff_check:
    mov.l @(40, r14), r1
    mov.l @(40, r13), r2
    sub r2, r1
    extu.w r1, r1
    mov.w   DAT_0603112e, r3
    mov #0x0, r11
    cmp/ge r1, r3
    bt      .L_heading_diff_negative
    mov r3, r2
    shll r2
    add r2, r3
    cmp/ge r3, r1
    bt      .L_heading_diff_negative
    mov #0x1, r11
    mov.l @(12, r14), r1
    mov.l @(12, r13), r3
    .byte   0xD2, 0x0A    /* mov.l .L_pool_heading_thresh_a, r2 */
    add r3, r1
    cmp/ge r1, r2
    bt      .L_apply_direction_force
    mov.l r4, @-r15
    mov.l r0, @-r15
    mov.l @(0, r13), r0
    .byte   0xD4, 0x08    /* mov.l .L_pool_force_flag_a, r4 */
    or r4, r0
    mov.l r0, @(0, r13)
    .byte   0xD0, 0x07    /* mov.l .L_pool_force_steer_a, r0 */
    jsr @r0
    nop
    mov.w   DAT_06031130, r0
    mov.w   DAT_06031132, r4
    mov.l r4, @(r0, r14)
    mov.l @r15+, r0
    bra     .L_apply_direction_force
    mov.l @r15+, r4

    .global DAT_0603112e
DAT_0603112e:
    .2byte  0x4000

    .global DAT_06031130
DAT_06031130:
    .2byte  0x0214

    .global DAT_06031132
DAT_06031132:
    .2byte  0x00CC
.L_pool_heading_thresh_a:
    .4byte  0x00042AAA
.L_pool_force_flag_a:
    .4byte  0x08000000
.L_pool_force_steer_a:
    .4byte  force_steer_impact
.L_heading_diff_negative:
    mov.l @(12, r14), r1
    mov.l @(12, r13), r3
    .byte   0xD2, 0x11    /* mov.l .L_pool_heading_thresh_b, r2 */
    sub r3, r1
    cmp/ge r1, r2
    bt      .L_check_side_approach
    mov.l r4, @-r15
    mov.l r0, @-r15
    mov.l @(0, r13), r0
    .byte   0xD4, 0x0F    /* mov.l .L_pool_force_flag_b, r4 */
    or r4, r0
    mov.l r0, @(0, r13)
    .byte   0xD0, 0x0E    /* mov.l .L_pool_force_steer_b, r0 */
    jsr @r0
    nop
    mov.w   DAT_06031188, r0
    mov.w   DAT_0603118a, r4
    mov.l r4, @(r0, r14)
    mov.l @r15+, r0
    mov.l @r15+, r4
.L_check_side_approach:
    tst r7, r7
    bf      .L_lateral_proximity
    mov.l @(12, r14), r1
    mov.l @(12, r13), r3
    shlr r2
    sub r3, r1
    cmp/gt r1, r2
    bt      .L_lateral_proximity
    tst r8, r8
    mov.l @(0, r14), r2
    .byte   0xD3, 0x06    /* mov.l .L_pool_steer_direct, r3 */
    bt      .L_apply_steer_flag
    shlr r3
.L_apply_steer_flag:
    or r3, r2
    bra     .L_apply_direction_force
    mov.l r2, @(0, r14)

    .global DAT_06031188
DAT_06031188:
    .2byte  0x0214

    .global DAT_0603118a
DAT_0603118a:
    .2byte  0x00CC
.L_pool_heading_thresh_b:
    .4byte  0x00042AAA
.L_pool_force_flag_b:
    .4byte  0x08000000
.L_pool_force_steer_b:
    .4byte  force_steer_impact
.L_pool_steer_direct:
    .4byte  0x20000000
.L_lateral_proximity:
    mov.l @(40, r14), r3
    sub r10, r3
    mov.w   DAT_060311b6, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bt      .L_apply_lateral_corr
    mov r2, r1
    shll r1
    add r1, r2
    cmp/ge r2, r3
    bt      .L_apply_lateral_corr
    bra     .L_apply_direction_force
    nop

    .global DAT_060311b6
DAT_060311b6:
    .2byte  0x4000
.L_apply_lateral_corr:
    mov.l r4, @-r15
    mov.l r0, @-r15
    tst r7, r7
    bt      .L_call_cos_lookup
    mov.l @(48, r14), r4
    mov.l r4, @(48, r13)
    mov.w   .L_wpool_heading_rate_ofs, r1
    mov #0x8, r2
    add r13, r1
    mov.l r2, @r1
.L_call_cos_lookup:
    .byte   0xD0, 0x0F    /* mov.l .L_pool_cos_lookup_a, r0 */
    jsr @r0
    mov r3, r4
    mov.l @(12, r14), r1
    mov.l @(12, r13), r2
    sub r2, r1
    shlr2 r1
    dmuls.l r0, r1
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    shar r1
    add r1, r2
    mov.w   DAT_0603120a, r3
    add r13, r3
    mov.l r2, @r3
    mov.l @(12, r14), r4
    sub r1, r4
    mov.l r4, @(12, r14)
    mov.l @r15+, r0
    mov.l @r15+, r4
.L_apply_direction_force:
    tst r7, r7
    bf      .L_approaching_path
    .byte   0xD5, 0x05    /* mov.l .L_pool_state_byte_a, r5 */
    mov.b @r5, r3
    tst r3, r3
    bf      .L_scale_correction
    mov #0x3, r3
    bra     .L_scale_correction
    mov.b r3, @r5
.L_wpool_heading_rate_ofs:
    .2byte  0x0208

    .global DAT_0603120a
DAT_0603120a:
    .2byte  0x0194
.L_pool_cos_lookup_a:
    .4byte  cos_lookup
.L_pool_state_byte_a:
    .4byte  sym_0602FD9A
.L_approaching_path:
    mov.l r0, @-r15
    mov.l r4, @-r15
    .byte   0xD5, 0x07    /* mov.l .L_pool_state_byte_b, r5 */
    mov.l @(0, r14), r2
    tst r8, r8
    .byte   0xDA, 0x07    /* mov.l .L_pool_reverse_flag, r10 */
    bf      .L_read_reverse_front
    mov.w @r10, r10
    add #0x1, r5
    mov #-0x80, r3
    extu.b r3, r3
    tst r10, r10
    bt      .L_merge_flags
    mov.w   .L_wpool_large_flag, r3
    bra     .L_merge_flags
    nop
.L_wpool_large_flag:
    .2byte  0x0200
    .2byte  0x0000
.L_pool_state_byte_b:
    .4byte  sym_0602FD98
.L_pool_reverse_flag:
    .4byte  sym_06031A24
.L_read_reverse_front:
    mov.w @r10, r10
    mov #0x40, r3
    tst r10, r10
    bt      .L_merge_flags
    mov.w   .L_wpool_front_flag, r3
.L_merge_flags:
    or r3, r2
    mov.l r2, @(0, r14)
    mov.b @r5, r4
    tst r4, r4
    bf      .L_restore_and_compute
    mov #0x3, r4
    mov.b r4, @r5
.L_restore_and_compute:
    mov.l @r15+, r4
    mov.l @r15+, r0
    mov.w   .L_wpool_quarter_circle, r3
    tst r8, r8
    mov.l @(48, r14), r10
    bf/s    .L_heading_blend
    extu.w r10, r10
    mov r3, r7
    shll r7
    add r7, r3
.L_heading_blend:
    dmuls.l r0, r4
    add r3, r10
    tst r9, r9
    sts mach, r0
    sts macl, r4
    xtrct r0, r4
    bt      .L_scale_correction
    .byte   0xD3, 0x0A    /* mov.l .L_pool_half_circle_adj, r3 */
    add r3, r4
.L_scale_correction:
    mov.w   .L_wpool_scale_index_ofs, r3
    add r14, r3
    mov.w @r3, r0
    mov #0x8, r5
    cmp/ge r5, r0
    bt      .L_zero_scale
    add #-0x2, r5
    cmp/ge r5, r0
    bt      .L_medium_scale
    shlr r4
    mov r4, r3
    shlr r4
    add r4, r3
    bra     .L_apply_pos_correction
    mov.l r4, @-r15
.L_wpool_front_flag:
    .2byte  0x0100
.L_wpool_quarter_circle:
    .2byte  0x4000
.L_wpool_scale_index_ofs:
    .2byte  0x007C
    .2byte  0x0000
.L_pool_half_circle_adj:
    .4byte  0x0000D999
.L_medium_scale:
    mov r4, r3
    mov #0x0, r4
    bra     .L_apply_pos_correction
    mov.l r4, @-r15
.L_zero_scale:
    mov #0x0, r3
    mov.l r4, @-r15
.L_apply_pos_correction:
    neg r10, r4
    mov r3, r9
    mov.l @(16, r13), r5
    mov.l @(24, r13), r6
    mov.l r5, @(56, r13)
    mov.l r6, @(60, r13)
    .byte   0xD0, 0x1C    /* mov.l .L_pool_cos_lookup_b, r0 */
    jsr @r0
    nop
    mov r0, r8
    neg r10, r4
    .byte   0xD0, 0x1B    /* mov.l .L_pool_sin_lookup_b, r0 */
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
    .byte   0xD5, 0x14    /* mov.l .L_fp_half, r5 */
    add r5, r10
    neg r10, r4
    mov r3, r9
    mov.l @(16, r14), r5
    mov.l @(24, r14), r6
    mov.l r5, @(56, r14)
    mov.l r6, @(60, r14)
    .byte   0xD0, 0x0E    /* mov.l .L_pool_cos_lookup_b, r0 */
    jsr @r0
    nop
    mov r0, r8
    neg r10, r4
    .byte   0xD0, 0x0C    /* mov.l .L_pool_sin_lookup_b, r0 */
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
.L_pool_cos_lookup_b:
    .4byte  cos_lookup
.L_pool_sin_lookup_b:
    .4byte  sin_lookup
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_check_reverse_dir:
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.w   DAT_0603135c, r4
    mov r4, r5
    cmp/ge r1, r4
    shll r5
    bt      .L_clear_reverse_flag
    add r5, r4
    cmp/ge r4, r1
    .byte   0xD5, 0x03    /* mov.l .L_pool_reverse_flag_sub, r5 */
    bt      .L_clear_reverse_flag
    mov #0x1, r4
    bra     .L_check_reverse_ret
    mov.w r4, @r5

    .global DAT_0603135c
DAT_0603135c:
    .2byte  0x4000
    .2byte  0x0000
.L_pool_reverse_flag_sub:
    .4byte  sym_06031A24
.L_clear_reverse_flag:
    mov #0x0, r4
    mov.w r4, @r5
.L_check_reverse_ret:
    mov.l @r15+, r5
    rts
    mov.l @r15+, r4
    .2byte  0x2F06
    .4byte  0x64833468
    .4byte  0x65933578
    .2byte  0xD030
