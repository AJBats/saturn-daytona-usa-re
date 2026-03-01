
    .section .text.FUN_06031A34


    .global timer_countdown_display
    .type timer_countdown_display, @function
timer_countdown_display:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x18, r0
    mul.l r6, r0
    mov r4, r8
    mov r5, r10
    mov r6, r14
    sts macl, r0
    add r0, r8
    mov.l   .L_pool_depth_result_buf, r13
    mov.l   .L_pool_screen_coord_buf, r11
.L_digit_loop:
    add #-0x18, r8
    mov.w @(16, r8), r0
    mov #0xC, r3
    mulu.w r0, r3
    mov.w   DAT_06031a64, r12
    mov.l   .L_pool_sprite_data_tbl, r3
    sts macl, r7
    add r3, r7
    mov.l @(8, r7), r3
    cmp/pl r3
    bt      .L_sprite_valid
    bra     .L_next_digit
    nop

    .global DAT_06031a64
DAT_06031a64:
    .2byte  0xFF00
    .2byte  0x0000
.L_pool_depth_result_buf:
    .4byte  sym_06031D5C
.L_pool_screen_coord_buf:
    .4byte  sym_06031D3C
.L_pool_sprite_data_tbl:
    .4byte  sym_06094FA8
.L_sprite_valid:
    mov.w   .L_wpool_cmd_size_a, r0
    mov.l r0, @(16, r12)
    mov.l r3, @(0, r12)
    mov #0x0, r0
    mov.l r0, @(20, r12)
    mov.l r3, @r13
    mov.w @(12, r8), r0
    mov r8, r4
    tst #0x8, r0
    bf      .L_after_matrix_xform
    mov.l   .L_pool_rotation_scratch, r5
    mov.l   .L_pool_rot_matrix_ptr, r0
    mov.l @r0, r9
    clrmac
    mac.l @r4+, @r9+
    mac.l @r4+, @r9+
    mac.l @r4+, @r9+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r9+
    xtrct r0, r1
    mov.l r1, @r5
    mac.l @r4+, @r9+
    mac.l @r4+, @r9+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r9+
    xtrct r0, r1
    mov.l r1, @(4, r5)
    mac.l @r4+, @r9+
    mac.l @r4+, @r9+
    add #-0x24, r9
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l r1, @(8, r5)
    mov r7, r4
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    sts mach, r1
    sts macl, r0
    xtrct r1, r0
    cmp/pl r0
    bt      .L_after_matrix_xform
    bra     .L_next_digit
    nop
.L_wpool_cmd_size_a:
    .2byte  0x00A0
    .2byte  0x0000
.L_pool_rotation_scratch:
    .4byte  sym_06031D6C
.L_pool_rot_matrix_ptr:
    .4byte  sym_06089EDC
.L_after_matrix_xform:
    mov r11, r5
    mov.l @(4, r7), r2
    mov.l @r7, r1
    mov.l @(28, r12), r4
    mov.w @(18, r8), r0
    mov #0xC, r3
    mulu.w r0, r3
    mov.l   .L_pool_sprite_data_tbl_b, r3
    sts macl, r7
    add r3, r7
    mov.l @(8, r7), r3
    mov.w   DAT_06031b22, r0
    mov.l r0, @(16, r12)
    mov.l r3, @(0, r12)
    mov #0x0, r0
    mov.l r0, @(20, r12)
    dmuls.l r1, r4
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r4
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    bsr     .L_validate_screen_bounds
    nop
    cmp/pl r3
    bt      .L_digit1_valid
    bra     .L_next_digit
    nop

    .global DAT_06031b22
DAT_06031b22:
    .2byte  0x00A0
.L_pool_sprite_data_tbl_b:
    .4byte  sym_06094FA8
.L_digit1_valid:
    mov.l r3, @(4, r13)
    add #0x8, r5
    mov.l @(4, r7), r2
    mov.l @r7, r1
    mov.l @(28, r12), r4
    mov.w @(20, r8), r0
    mov #0xC, r3
    mulu.w r0, r3
    mov.l   .L_pool_sprite_data_tbl_c, r3
    sts macl, r7
    add r3, r7
    mov.l @(8, r7), r3
    mov.w   .L_wpool_cmd_size_b, r0
    mov.l r0, @(16, r12)
    mov.l r3, @(0, r12)
    mov #0x0, r0
    mov.l r0, @(20, r12)
    dmuls.l r1, r4
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r4
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    bsr     .L_validate_screen_bounds
    nop
    cmp/pl r3
    bt      .L_digit2_valid
    bra     .L_next_digit
    nop
.L_wpool_cmd_size_b:
    .2byte  0x00A0
    .2byte  0x0000
.L_pool_sprite_data_tbl_c:
    .4byte  sym_06094FA8
.L_digit2_valid:
    mov.l r3, @(8, r13)
    add #0x8, r5
    mov.l @(4, r7), r2
    mov.l @r7, r1
    mov.l @(28, r12), r4
    mov.w @(22, r8), r0
    mov #0xC, r3
    mulu.w r0, r3
    mov.l   .L_pool_sprite_data_tbl_d, r3
    sts macl, r7
    add r3, r7
    mov.l @(8, r7), r3
    mov.w   .L_wpool_cmd_size_c, r0
    mov.l r0, @(16, r12)
    mov.l r3, @(0, r12)
    mov #0x0, r0
    mov.l r0, @(20, r12)
    dmuls.l r1, r4
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r4
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    bsr     .L_validate_screen_bounds
    nop
    cmp/pl r3
    bt      .L_digit3_valid
    bra     .L_next_digit
    nop
.L_wpool_cmd_size_c:
    .2byte  0x00A0
    .2byte  0x0000
.L_pool_sprite_data_tbl_d:
    .4byte  sym_06094FA8
.L_digit3_valid:
    mov.l r3, @(12, r13)
    add #0x8, r5
    mov.l @(4, r7), r2
    mov.l @r7, r1
    mov.l @(28, r12), r4
    dmuls.l r1, r4
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r4
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    bsr     .L_validate_screen_bounds
    nop
    mov.l   .L_pool_sprite_count, r0
    mov #0x18, r1
    mov.l @r0, r0
    mul.l r0, r1
    mov.l   .L_pool_sprite_entry_base, r2
    sts macl, r9
    add r2, r9
    mov.w   .L_wpool_neg_clip_threshold, r12
    mov.l @(0, r11), r0
    mov.l @(8, r11), r2
    mov.l @(16, r11), r4
    mov.l @(24, r11), r6
    cmp/gt r0, r12
    bf      .L_check_right_bound
    cmp/gt r2, r12
    bf      .L_check_right_bound
    cmp/gt r4, r12
    bf      .L_check_right_bound
    cmp/gt r6, r12
    bf      .L_check_right_bound
    bra     .L_next_digit
    nop
.L_wpool_neg_clip_threshold:
    .2byte  0xFF50
    .2byte  0x0000
.L_pool_sprite_count:
    .4byte  sym_060620D0
.L_pool_sprite_entry_base:
    .4byte  sym_0608AC20
.L_check_right_bound:
    mov.w   .L_wpool_right_clip, r12
    cmp/gt r0, r12
    bt      .L_load_y_coords
    cmp/gt r2, r12
    bt      .L_load_y_coords
    cmp/gt r4, r12
    bt      .L_load_y_coords
    cmp/gt r6, r12
    bt      .L_next_digit
.L_load_y_coords:
    mov.w   .L_wpool_top_clip, r12
    mov.l @(4, r11), r1
    mov.l @(12, r11), r3
    mov.l @(20, r11), r5
    mov.l @(28, r11), r7
    cmp/gt r1, r12
    bf      .L_check_bottom_bound
    cmp/gt r3, r12
    bf      .L_check_bottom_bound
    cmp/gt r5, r12
    bf      .L_check_bottom_bound
    cmp/gt r7, r12
    bt      .L_next_digit
.L_check_bottom_bound:
    mov.w   .L_wpool_bottom_clip, r12
    cmp/gt r1, r12
    bt      .L_write_sprite_cmd
    cmp/gt r3, r12
    bt      .L_write_sprite_cmd
    cmp/gt r5, r12
    bt      .L_write_sprite_cmd
    cmp/gt r7, r12
    bf      .L_next_digit
.L_write_sprite_cmd:
    mov r9, r12
    add #0x18, r12
    mov.w r7, @-r12
    mov.w r6, @-r12
    mov.w r5, @-r12
    mov.w r4, @-r12
    mov.w r3, @-r12
    mov.w r2, @-r12
    mov.w r1, @-r12
    mov.w r0, @-r12
    mov.w @(14, r8), r0
    mov.w r0, @(6, r9)
    mov.w @(12, r8), r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov.b r0, @(4, r9)
    mov r10, r0
    mov.b r0, @(5, r9)
    mov.w @(12, r8), r0
    mov.l   .L_pool_depth_mode_table, r1
    and #0x7, r0
    shll2 r0
    mov.l @(r0, r1), r0
    mov.l @(0, r13), r3
    mov.l @(4, r13), r4
    mov.l @(8, r13), r5
    jmp @r0
    mov.l @(12, r13), r6
.L_wpool_right_clip:
    .2byte  0x00B0
.L_wpool_top_clip:
    .2byte  0xFF81
.L_wpool_bottom_clip:
    .2byte  0x0051
    .2byte  0x0000
.L_pool_depth_mode_table:
    .4byte  sym_06031D78

    .global loc_06031C88
loc_06031C88:
    add r4, r3
    add r5, r6
    add r6, r3
    bra     .L_commit_sprite_entry
    shlr2 r3

    .global loc_06031C92
loc_06031C92:
    cmp/ge r3, r4
    bt      .L_min_cmp_r5
    mov r4, r3
.L_min_cmp_r5:
    cmp/ge r3, r5
    bt      .L_min_cmp_r6
    mov r5, r3
.L_min_cmp_r6:
    cmp/ge r3, r6
    bt      .L_min_done
    mov r6, r3
.L_min_done:
    bra     .L_commit_sprite_entry
    nop

    .global loc_06031CA8
loc_06031CA8:
    cmp/gt r3, r4
    bf      .L_max_cmp_r5
    mov r4, r3
.L_max_cmp_r5:
    cmp/gt r3, r5
    bf      .L_max_cmp_r6
    mov r5, r3
.L_max_cmp_r6:
    cmp/gt r3, r6
    bf      .L_max_done
    mov r6, r3
.L_max_done:
    bra     .L_commit_sprite_entry
    nop

    .global loc_06031CBE
loc_06031CBE:
    mov #0x20, r0
    bra     .L_max_with_offset
    shll16 r0

    .global loc_06031CC4
loc_06031CC4:
    mov.l   .L_pool_depth_offset_large, r0
.L_max_with_offset:
    cmp/gt r3, r4
    bf      .L_max_off_cmp_r5
    mov r4, r3
.L_max_off_cmp_r5:
    cmp/gt r3, r5
    bf      .L_max_off_cmp_r6
    mov r5, r3
.L_max_off_cmp_r6:
    cmp/gt r3, r6
    bf      .L_apply_depth_offset
    mov r6, r3
.L_apply_depth_offset:
    add r0, r3
.L_commit_sprite_entry:
    mov.l   .L_pool_sprite_count_b, r2
    neg r3, r3
    mov.l   .L_pool_sprite_index_tbl, r1
    shlr8 r3
    mov.l @r2, r0
    shlr2 r3
    shlr2 r3
    shll r0
    mov.w r3, @(r0, r1)
    shar r0
    add #0x1, r0
    mov.l r0, @r2
.L_next_digit:
    dt r14
    bt      .L_epilogue
    bra     .L_digit_loop
    nop
    .2byte  0x0000
.L_pool_depth_offset_large:
    .4byte  0x00400000
.L_pool_sprite_count_b:
    .4byte  sym_060620D0
.L_pool_sprite_index_tbl:
    .4byte  sym_0606A4F8
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
.L_validate_screen_bounds:
    mov.w   DAT_06031d36, r0
    cmp/gt r0, r1
    bt      .L_next_digit
    mov.w   DAT_06031d38, r0
    cmp/gt r1, r0
    bt      .L_next_digit
    mov.w   DAT_06031d3a, r0
    cmp/gt r0, r2
    bt      .L_next_digit
    mov.w   DAT_06031d38, r0
    cmp/gt r2, r0
    bt      .L_next_digit
    rts
    nop

    .global DAT_06031d36
DAT_06031d36:
    .2byte  0x0190

    .global DAT_06031d38
DAT_06031d38:
    .2byte  0xFE70

    .global DAT_06031d3a
DAT_06031d3a:
    .2byte  0x00C8

    .global sym_06031D3C
sym_06031D3C:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_06031D5C
sym_06031D5C:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_06031D6C
sym_06031D6C:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_06031D78
sym_06031D78:
    .4byte  loc_06031C88
    .4byte  loc_06031C92
    .4byte  loc_06031CA8
    .4byte  loc_06031CBE
    .4byte  loc_06031CC4

    .global sym_06031D8C
sym_06031D8C:
    mov.l   .L_pool_rot_matrix_ptr_b, r0
    mov.l   .L_pool_sprite_data_tbl_e, r3
    mov.l @r0, r6
    mov #0x24, r7
    add r6, r7
    add #-0x8, r15
.L_xform_loop:
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7, r2
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r15
    mac.l @r4+, @r6+
    mov.l @(4, r7), r2
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r4+, @r6+
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r15)
    mov.l @(8, r7), r2
    dt r5
    mac.l @r4+, @r6+
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @(8, r3)
    mov.l @r15, r0
    mov.l @(4, r15), r1
    mov.l r0, @r3
    mov.l r1, @(4, r3)
    add #-0x24, r6
    bf/s    .L_xform_loop
    add #0xC, r3
    rts
    add #0x8, r15
.L_pool_rot_matrix_ptr_b:
    .4byte  sym_06089EDC
.L_pool_sprite_data_tbl_e:
    .4byte  sym_06094FA8

    .global sym_06031DF4
sym_06031DF4:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
