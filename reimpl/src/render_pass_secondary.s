
    .section .text.FUN_0602A840


    .global render_pass_secondary
    .type render_pass_secondary, @function
render_pass_secondary:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r8
    mov r5, r14
    mov r6, r13
    mov.l   .L_depth_cache_base, r12
    mov #0x40, r4
    mov #-0x1, r0
.L_cache_invalidate_loop:
    mov.l r0, @r12
    dt r4
    bf/s    .L_cache_invalidate_loop
    add #0x10, r12
    mov.l   .L_render_state_ptr, r10
    mov.l @r10, r10
    mov #0x18, r0
    mul.l r7, r0
    sts macl, r0
    add r0, r8
.L_obj_loop_top:
    mov.l r7, @-r15
    add #-0x18, r8
    mov.l   .L_render_enable_flag, r12
    mov.w @r12, r0
    cmp/eq #0x0, r0
    bt      .L_obj_visible
    mov.w @(14, r8), r0
    mov.w   .L_skip_obj_type_id, r1
    cmp/eq r0, r1
    bf      .L_obj_visible
    bra     .L_next_obj
    nop
.L_skip_obj_type_id:
    .2byte  0x0097
    .2byte  0x0000
.L_depth_cache_base:
    .4byte  sym_0608A820
.L_render_state_ptr:
    .4byte  sym_06063F08
.L_render_enable_flag:
    .4byte  sym_0605BE36
.L_obj_visible:
    mov.l   .L_zval_scratch_buf, r11
    mov.l   .L_dot_result_vec, r5
    mov.l   .L_matrix_stack_ptr, r0
    mov.l @r0, r6
    mov.w @(16, r8), r0
    mov r0, r9
    bsr     .L_compute_dot_products
    nop
    mov.l r1, @r5
    mov.l r2, @(4, r5)
    mov.l r3, @(8, r5)
    mov.w @(12, r8), r0
    tst #0x8, r0
    bf      .L_backface_passed
    mov.l   .L_xform_result_buf, r7
    mov r8, r4
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r9
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r9
    mov.l r9, @r7
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r9
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r9
    mov.l r9, @(4, r7)
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0x24, r6
    sts mach, r0
    sts macl, r9
    xtrct r0, r9
    mov.l r9, @(8, r7)
    clrmac
    mac.l @r5+, @r7+
    mac.l @r5+, @r7+
    mac.l @r5+, @r7+
    add #-0xC, r5
    sts mach, r9
    sts macl, r0
    xtrct r9, r0
    cmp/pl r0
    bt      .L_backface_passed
    bra     .L_next_obj
    nop
    .2byte  0x0000
.L_zval_scratch_buf:
    .4byte  sym_0602AB68
.L_dot_result_vec:
    .4byte  sym_0602AB88
.L_matrix_stack_ptr:
    .4byte  sym_06089EDC
.L_xform_result_buf:
    .4byte  sym_0602AB98
.L_backface_passed:
    mov.w @(16, r8), r0
    mov.l   .L_fn_process_vtx_1, r7
    bsr     .L_fetch_cached_vtx
    mov r0, r9
    mov.l r3, @r5
    bsr     .L_clip_and_cache_vtx
    add #0x4, r5

    .global sym_0602A91A
sym_0602A91A:
    mov.w @(18, r8), r0
    mov.l   .L_fn_process_vtx_2, r7
    bsr     .L_fetch_cached_vtx
    mov r0, r9
    bsr     .L_compute_dot_products
    nop
    mov.l r3, @r5
    bsr     .L_clip_and_cache_vtx
    add #0x4, r5

    .global sym_0602A92C
sym_0602A92C:
    mov.w @(20, r8), r0
    mov.l   .L_fn_process_vtx_3, r7
    bsr     .L_fetch_cached_vtx
    mov r0, r9
    bsr     .L_compute_dot_products
    nop
    mov.l r3, @r5
    bsr     .L_clip_and_cache_vtx
    add #0x4, r5

    .global sym_0602A93E
sym_0602A93E:
    mov.w @(22, r8), r0
    mov.l   .L_fn_process_vtx_4, r7
    bsr     .L_fetch_cached_vtx
    mov r0, r9
    bsr     .L_compute_dot_products
    nop
    mov.l r3, @r5
    bsr     .L_clip_and_cache_vtx
    add #0x4, r5

    .global sym_0602A950
sym_0602A950:
    mov.l   .L_sprite_count_ptr, r0
    mov #0x18, r1
    mov.l @r0, r0
    mulu.w r0, r1
    mov.l   .L_sprite_table_base, r2
    sts macl, r9
    add r2, r9
    add #-0x20, r11
    mov.w   DAT_0602a97e, r12
    mov.l @(0, r11), r0
    mov.l @(8, r11), r2
    mov.l @(16, r11), r4
    mov.l @(24, r11), r6
    cmp/gt r0, r12
    bf      .L_check_far_clip
    cmp/gt r2, r12
    bf      .L_check_far_clip
    cmp/gt r4, r12
    bf      .L_check_far_clip
    cmp/gt r6, r12
    bf      .L_check_far_clip
    bra     .L_next_obj
    nop

    .global DAT_0602a97e
DAT_0602a97e:
    .2byte  0xFF50
.L_fn_process_vtx_1:
    .4byte  sym_0602A91A
.L_fn_process_vtx_2:
    .4byte  sym_0602A92C
.L_fn_process_vtx_3:
    .4byte  sym_0602A93E
.L_fn_process_vtx_4:
    .4byte  sym_0602A950
.L_sprite_count_ptr:
    .4byte  sym_060620D0
.L_sprite_table_base:
    .4byte  sym_0608AC20
.L_check_far_clip:
    mov.w   DAT_0602aa12, r12
    cmp/gt r0, r12
    bt      .L_check_x_left_clip
    cmp/gt r2, r12
    bt      .L_check_x_left_clip
    cmp/gt r4, r12
    bt      .L_check_x_left_clip
    cmp/gt r6, r12
    bt      .L_next_obj
.L_check_x_left_clip:
    mov.w   DAT_0602aa14, r12
    mov.l @(4, r11), r1
    mov.l @(12, r11), r3
    mov.l @(20, r11), r5
    mov.l @(28, r11), r7
    cmp/gt r1, r12
    bf      .L_check_x_right_clip
    cmp/gt r3, r12
    bf      .L_check_x_right_clip
    cmp/gt r5, r12
    bf      .L_check_x_right_clip
    cmp/gt r7, r12
    bt      .L_next_obj
.L_check_x_right_clip:
    mov.w   DAT_0602aa16, r12
    cmp/gt r1, r12
    bt      .L_write_sprite_entry
    cmp/gt r3, r12
    bt      .L_write_sprite_entry
    cmp/gt r5, r12
    bt      .L_write_sprite_entry
    cmp/gt r7, r12
    bf      .L_next_obj
.L_write_sprite_entry:
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
    mov r13, r0
    mov.b r0, @(5, r9)
    mov.w @(12, r8), r0
    mov.l   .L_depth_mode_table, r1
    and #0x7, r0
    shll2 r0
    mov.l @(r0, r1), r2
    .word 0xC760
    mov.l @r0, r3
    mov.l @(4, r0), r4
    mov.l @(8, r0), r5
    jmp @r2
    mov.l @(12, r0), r6

    .global DAT_0602aa12
DAT_0602aa12:
    .2byte  0x00B0

    .global DAT_0602aa14
DAT_0602aa14:
    .2byte  0xFF81

    .global DAT_0602aa16
DAT_0602aa16:
    .2byte  0x0051
.L_depth_mode_table:
    .4byte  sym_0602ABA4

    .global loc_0602AA1C
loc_0602AA1C:
    add r4, r3
    add r5, r6
    add r6, r3
    bra     .L_write_sort_key
    shlr2 r3

    .global loc_0602AA26
loc_0602AA26:
    cmp/ge r3, r4
    bt      .L_min_check_v2
    mov r4, r3
.L_min_check_v2:
    cmp/ge r3, r5
    bt      .L_min_check_v3
    mov r5, r3
.L_min_check_v3:
    cmp/ge r3, r6
    bt      .L_min_check_v4
    mov r6, r3
.L_min_check_v4:
    bra     .L_write_sort_key
    nop

    .global loc_0602AA3C
loc_0602AA3C:
    bra     .L_find_max_depth
    mov #0x0, r0

    .global loc_0602AA40
loc_0602AA40:
    mov #0x1, r0
    bra     .L_find_max_depth
    shll16 r0

    .global loc_0602AA46
loc_0602AA46:
    mov.l   .L_fixed_depth_bias, r0
.L_find_max_depth:
    cmp/gt r3, r4
    bf      .L_max_check_v2
    mov r4, r3
.L_max_check_v2:
    cmp/gt r3, r5
    bf      .L_max_check_v3
    mov r5, r3
.L_max_check_v3:
    cmp/gt r3, r6
    bf      .L_max_check_v4
    mov r6, r3
.L_max_check_v4:
    add r0, r3
.L_write_sort_key:
    mov.l   .L_sort_write_idx_ptr, r2
    neg r3, r3
    mov.l   .L_sort_index_table, r1
    shlr8 r3
    mov.l @r2, r0
    shlr2 r3
    shlr2 r3
    shll r0
    mov.w r3, @(r0, r1)
    shar r0
    add #0x1, r0
    mov.l r0, @r2
.L_next_obj:
    mov.l @r15+, r7
    dt r7
    bt      .L_epilogue
    bra     .L_obj_loop_top
    nop
    .2byte  0x0000
.L_fixed_depth_bias:
    .4byte  0x000B8000
.L_sort_write_idx_ptr:
    .4byte  sym_060620D0
.L_sort_index_table:
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
    .2byte  0x0009
.L_compute_dot_products:
    mov #0xC, r0
    mul.l r0, r9
    mov #0x18, r7
    add r6, r7
    sts macl, r4
    add r14, r4
    clrmac
    mac.l @r4+, @r7+
    mac.l @r4+, @r7+
    mac.l @r4+, @r7+
    add #-0xC, r4
    mov.l @(8, r7), r2
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r2, r3
    cmp/gt r10, r3
    bf      .L_next_obj
    mov.w   .L_sprite_entry_offset, r2
    mov.w   .L_sprite_cmd_size, r0
    mov.l r0, @(16, r2)
    mov.l r3, @(0, r2)
    mov #0x0, r0
    mov.l r0, @(20, r2)
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0xC, r4
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r7
    add #-0x18, r6
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    rts
    add r7, r2
.L_sprite_entry_offset:
    .2byte  0xFF00
.L_sprite_cmd_size:
    .2byte  0x00A0
    .2byte  0x0009
.L_clip_and_cache_vtx:
    mov.w   DAT_0602ab36, r0
    mov.l @(28, r0), r4
    dmuls.l r1, r4
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r4
    mov.l r1, @r11
    sts mach, r2
    mov.l r2, @(4, r11)
    add #0x8, r11
    mov.w   DAT_0602ab38, r7
    cmp/gt r7, r1
    bt      .L_next_obj
    neg r7, r0
    cmp/gt r1, r0
    bt      .L_next_obj
    cmp/gt r2, r0
    bt      .L_next_obj
    shlr r7
    cmp/gt r7, r2
    bt      .L_next_obj
    mov.l r9, @r12
    mov.l r1, @(4, r12)
    mov.l r2, @(8, r12)
    mov.l r3, @(12, r12)
    rts
    nop

    .global DAT_0602ab36
DAT_0602ab36:
    .2byte  0xFF00

    .global DAT_0602ab38
DAT_0602ab38:
    .2byte  0x0190
.L_fetch_cached_vtx:
    and #0x3F, r0
    mov.l   .L_cache_entry_base, r12
    shll2 r0
    shll2 r0
    add r0, r12
    mov.l @r12, r0
    cmp/pz r0
    bf      .L_cache_miss
    cmp/eq r0, r9
    bf      .L_cache_miss
    mov.l @(4, r12), r1
    mov.l @(8, r12), r2
    mov.l @(12, r12), r3
    mov.l r1, @r11
    mov.l r2, @(4, r11)
    add #0x8, r11
    mov.l r3, @r5
    jmp @r7
    add #0x4, r5
.L_cache_entry_base:
    .4byte  sym_0608A820
.L_cache_miss:
    rts
    nop

    .global sym_0602AB68
sym_0602AB68:
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

    .global sym_0602AB88
sym_0602AB88:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602ab8c
DAT_0602ab8c:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602ab90
DAT_0602ab90:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602ab94
DAT_0602ab94:
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602AB98
sym_0602AB98:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602ABA4
sym_0602ABA4:
    .4byte  loc_0602AA1C
    .4byte  loc_0602AA26
    .4byte  loc_0602AA3C
    .4byte  loc_0602AA40
    .4byte  loc_0602AA46

    .global sym_0602ABB8
sym_0602ABB8:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
