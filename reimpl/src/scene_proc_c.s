
    .section .text.FUN_0602AF48


    .global scene_proc_c
    .type scene_proc_c, @function
scene_proc_c:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r8
    mov r5, r14
    mov r6, r13
    mov.l   .L_ptr_cache_base, r12
    mov #0x40, r4
    mov #-0x1, r0
.L_clear_cache_loop:
    mov.l r0, @r12
    dt r4
    bf/s    .L_clear_cache_loop
    add #0x10, r12
    mov.l   .L_ptr_clip_dist, r10
    mov.l @r10, r10
    mov #0x18, r0
    mul.l r7, r0
    sts macl, r0
    add r0, r8
.L_face_loop:
    mov.l r7, @-r15
    add #-0x18, r8
    mov.l   .L_ptr_depth_output, r11
    mov.l   .L_ptr_xform_result, r5
    mov.l   .L_ptr_matrix_base, r0
    mov.l @r0, r6
    mov.w @(16, r8), r0
    extu.w r0, r4
    bsr     .L_transform_vertex
    mov #0x6, r9
    mov.l r1, @r5
    mov.l r2, @(4, r5)
    mov.l r3, @(8, r5)
    mov.l   .L_ptr_dot_result, r7
    mov.l r2, @r7
    mov.w @(12, r8), r0
    tst #0x8, r0
    bf      .L_backface_pass
    mov.l   .L_ptr_mat_intermediate, r7
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
    bt      .L_backface_pass
    bra     .L_next_face
    nop
    .2byte  0x0000
.L_ptr_cache_base:
    .4byte  sym_06094620
.L_ptr_clip_dist:
    .4byte  sym_06063F08
.L_ptr_depth_output:
    .4byte  sym_0602B2C8
.L_ptr_xform_result:
    .4byte  sym_0602B2E8
.L_ptr_matrix_base:
    .4byte  sym_06089EDC
.L_ptr_dot_result:
    .4byte  sym_0602B310
.L_ptr_mat_intermediate:
    .4byte  sym_0602B2F8
.L_backface_pass:
    mov.w @(16, r8), r0
    mov.l   .L_ptr_face1_cont, r7
    bsr     .L_cache_lookup
    mov r0, r4
    mov.l r3, @r5
    add #0x4, r5
    mov.w @(16, r8), r0
    bsr     .L_project_and_clip
    nop

    .global sym_0602B012
sym_0602B012:
    mov.w @(18, r8), r0
    mov.l   .L_ptr_face2_cont, r7
    bsr     .L_cache_lookup
    mov r0, r4
    bsr     .L_transform_vertex
    mov #0x6, r9
    mov.l r3, @r5
    add #0x4, r5
    mov.w @(18, r8), r0
    bsr     .L_project_and_clip
    nop

    .global sym_0602B028
sym_0602B028:
    mov.w @(20, r8), r0
    mov.l   .L_ptr_face3_cont, r7
    bsr     .L_cache_lookup
    mov r0, r4
    bsr     .L_transform_vertex
    mov #0x6, r9
    mov.l r3, @r5
    add #0x4, r5
    mov.w @(20, r8), r0
    bsr     .L_project_and_clip
    nop

    .global sym_0602B03E
sym_0602B03E:
    mov.w @(22, r8), r0
    mov.l   .L_ptr_face4_cont, r7
    bsr     .L_cache_lookup
    mov r0, r4
    bsr     .L_transform_vertex
    mov #0x6, r9
    mov.l r3, @r5
    add #0x4, r5
    mov.w @(22, r8), r0
    bsr     .L_project_and_clip
    nop

    .global sym_0602B054
sym_0602B054:
    mov.l   .L_ptr_sort_index, r0
    mov #0x18, r1
    mov.l @r0, r0
    mulu.w r0, r1
    mov.l   .L_ptr_sprite_table, r2
    sts macl, r9
    add r2, r9
    add #-0x20, r11
    mov.w   DAT_0602b082, r12
    mov.l @(0, r11), r0
    mov.l @(8, r11), r2
    mov.l @(16, r11), r4
    mov.l @(24, r11), r6
    cmp/gt r0, r12
    bf      .L_check_x_hi_bounds
    cmp/gt r2, r12
    bf      .L_check_x_hi_bounds
    cmp/gt r4, r12
    bf      .L_check_x_hi_bounds
    cmp/gt r6, r12
    bf      .L_check_x_hi_bounds
    bra     .L_next_face
    nop

    .global DAT_0602b082
DAT_0602b082:
    .2byte  0xFF50
.L_ptr_face1_cont:
    .4byte  sym_0602B012
.L_ptr_face2_cont:
    .4byte  sym_0602B028
.L_ptr_face3_cont:
    .4byte  sym_0602B03E
.L_ptr_face4_cont:
    .4byte  sym_0602B054
.L_ptr_sort_index:
    .4byte  sym_060620D0
.L_ptr_sprite_table:
    .4byte  sym_0608AC20
.L_check_x_hi_bounds:
    mov.w   DAT_0602b116, r12
    cmp/gt r0, r12
    bt      .L_check_y_lo_bounds
    cmp/gt r2, r12
    bt      .L_check_y_lo_bounds
    cmp/gt r4, r12
    bt      .L_check_y_lo_bounds
    cmp/gt r6, r12
    bt      .L_next_face
.L_check_y_lo_bounds:
    mov.w   DAT_0602b118, r12
    mov.l @(4, r11), r1
    mov.l @(12, r11), r3
    mov.l @(20, r11), r5
    mov.l @(28, r11), r7
    cmp/gt r1, r12
    bf      .L_check_y_hi_bounds
    cmp/gt r3, r12
    bf      .L_check_y_hi_bounds
    cmp/gt r5, r12
    bf      .L_check_y_hi_bounds
    cmp/gt r7, r12
    bt      .L_next_face
.L_check_y_hi_bounds:
    mov.w   DAT_0602b11a, r12
    cmp/gt r1, r12
    bt      .L_build_sort_entry
    cmp/gt r3, r12
    bt      .L_build_sort_entry
    cmp/gt r5, r12
    bt      .L_build_sort_entry
    cmp/gt r7, r12
    bf      .L_next_face
.L_build_sort_entry:
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
    mov.l   .L_ptr_depth_dispatch, r1
    and #0x7, r0
    shll2 r0
    mov.l @(r0, r1), r2
    .word 0xC777
    mov.l @r0, r3
    mov.l @(4, r0), r4
    mov.l @(8, r0), r5
    jmp @r2
    mov.l @(12, r0), r6

    .global DAT_0602b116
DAT_0602b116:
    .2byte  0x00B0

    .global DAT_0602b118
DAT_0602b118:
    .2byte  0xFF81

    .global DAT_0602b11a
DAT_0602b11a:
    .2byte  0x0051
.L_ptr_depth_dispatch:
    .4byte  sym_0602B314

    .global loc_0602B120
loc_0602B120:
    add r4, r3
    add r5, r6
    add r6, r3
    bra     .L_write_sort_key
    shlr2 r3

    .global loc_0602B12A
loc_0602B12A:
    cmp/ge r3, r4
    bt      .L_min_check_v1
    mov r4, r3
.L_min_check_v1:
    cmp/ge r3, r5
    bt      .L_min_check_v2
    mov r5, r3
.L_min_check_v2:
    cmp/ge r3, r6
    bt      .L_min_done
    mov r6, r3
.L_min_done:
    bra     .L_write_sort_key
    nop

    .global loc_0602B140
loc_0602B140:
    cmp/gt r3, r4
    bf      .L_max_check_v1
    mov r4, r3
.L_max_check_v1:
    cmp/gt r3, r5
    bf      .L_max_check_v2
    mov r5, r3
.L_max_check_v2:
    cmp/gt r3, r6
    bf      .L_max_done
    mov r6, r3
.L_max_done:
    bra     .L_write_sort_key
    nop

    .global loc_0602B156
loc_0602B156:
    mov #0x1, r0
    bra     .L_max_bias_find
    shll16 r0

    .global loc_0602B15C
loc_0602B15C:
    mov.l   .L_depth_bias_large, r0
.L_max_bias_find:
    cmp/gt r3, r4
    bf      .L_max_bias_v1
    mov r4, r3
.L_max_bias_v1:
    cmp/gt r3, r5
    bf      .L_max_bias_v2
    mov r5, r3
.L_max_bias_v2:
    cmp/gt r3, r6
    bf      .L_max_bias_done
    mov r6, r3
.L_max_bias_done:
    add r0, r3
.L_write_sort_key:
    mov.l   .L_ptr_dot_result_b, r1
    mov.l @r1, r1
    mov.l   .L_ptr_scene_param, r0
    mov.l @r0, r0
    mov.l   .L_fp_two, r2
    add r2, r1
    cmp/gt r1, r0
    bf      .L_store_sort_key
    mov.l   .L_depth_bias_extra, r2
    add r2, r3
.L_store_sort_key:
    mov.l   .L_ptr_sort_count, r2
    neg r3, r3
    mov.l   .L_ptr_sort_buffer, r1
    shlr8 r3
    mov.l @r2, r0
    shlr2 r3
    shlr2 r3
    shll r0
    mov.w r3, @(r0, r1)
    shar r0
    add #0x1, r0
    mov.l r0, @r2
.L_next_face:
    mov.l @r15+, r7
    dt r7
    bt      .L_epilogue
    bra     .L_face_loop
    nop
.L_depth_bias_large:
    .4byte  0x000B8000
.L_ptr_dot_result_b:
    .4byte  sym_0602B310
.L_ptr_scene_param:
    .4byte  sym_06063F54
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_depth_bias_extra:
    .4byte  0x000A0000
.L_ptr_sort_count:
    .4byte  sym_060620D0
.L_ptr_sort_buffer:
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
.L_transform_vertex:
    mul.l r9, r4
    mov.l   .L_ptr_vtx_scratch, r4
    sts macl, r0
    add r14, r0
    mov.w @r0+, r1
    mov.w @r0+, r2
    mov.w @r0+, r3
    shll8 r1
    shll2 r1
    shll r1
    mov.l r1, @r4
    shll8 r2
    shll2 r2
    shll r2
    mov.l r2, @(4, r4)
    shll8 r3
    shll2 r3
    shll r3
    mov.l r3, @(8, r4)
    mov #0x18, r7
    add r6, r7
    clrmac
    mac.l @r4+, @r7+
    mac.l @r4+, @r7+
    mac.l @r4+, @r7+
    add #-0xC, r4
    mov.l @(8, r7), r9
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r9, r3
    cmp/gt r10, r3
    bf      .L_next_face
    mov.w   .L_cache_slot_offset, r9
    mov.w   .L_backface_threshold, r0
    mov.l r0, @(16, r9)
    mov.l r3, @(0, r9)
    mov #0x0, r0
    mov.l r0, @(20, r9)
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    add #-0xC, r4
    mov.l @r7+, r9
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r9, r1
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r9
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    add r9, r2
    rts
    add #-0x18, r6
.L_cache_slot_offset:
    .2byte  0xFF00
.L_backface_threshold:
    .2byte  0x00A0
    .2byte  0x0000
.L_ptr_vtx_scratch:
    .4byte  sym_0602B304
.L_project_and_clip:
    mov.w   .L_project_base_offset, r9
    mov.l @(28, r9), r7
    dmuls.l r1, r7
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r7
    mov.l r1, @r11
    sts mach, r2
    mov.l r2, @(4, r11)
    add #0x8, r11
    mov.w   DAT_0602b292, r7
    cmp/gt r7, r1
    bt      .L_next_face
    mov.w   DAT_0602b294, r7
    cmp/gt r1, r7
    bt      .L_next_face
    mov.w   DAT_0602b296, r7
    cmp/gt r7, r2
    bt      .L_next_face
    mov.w   DAT_0602b294, r7
    cmp/gt r2, r7
    bt      .L_next_face
    mov.l r0, @r12
    mov.l r1, @(4, r12)
    mov.l r2, @(8, r12)
    mov.l r3, @(12, r12)
    rts
    nop
.L_project_base_offset:
    .2byte  0xFF00

    .global DAT_0602b292
DAT_0602b292:
    .2byte  0x0190

    .global DAT_0602b294
DAT_0602b294:
    .2byte  0xFE70

    .global DAT_0602b296
DAT_0602b296:
    .2byte  0x00C8
.L_cache_lookup:
    and #0x3F, r0
    mov.l   .L_ptr_cache_array, r12
    shll2 r0
    shll2 r0
    add r0, r12
    mov.l @r12, r0
    cmp/pz r0
    bf      .L_cache_miss
    cmp/eq r0, r4
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
    .2byte  0x0000
.L_ptr_cache_array:
    .4byte  sym_06094620
.L_cache_miss:
    rts
    nop


    .global sym_0602B2C8
sym_0602B2C8:
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

    .global sym_0602B2E8
sym_0602B2E8:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602b2ec
DAT_0602b2ec:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602b2f0
DAT_0602b2f0:
    .word 0xFFFF
    .word 0xFFFF

    .global DAT_0602b2f4
DAT_0602b2f4:
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602B2F8
sym_0602B2F8:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602B304
sym_0602B304:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602B310
sym_0602B310:
    .word 0xFFFF
    .word 0xFFFF

    .global sym_0602B314
sym_0602B314:
    .4byte  loc_0602B120
    .4byte  loc_0602B12A
    .4byte  loc_0602B140
    .4byte  loc_0602B156
    .4byte  loc_0602B15C

    .global sym_0602B328
sym_0602B328:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
