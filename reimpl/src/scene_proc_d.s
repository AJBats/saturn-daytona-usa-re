
    .section .text.FUN_0602B334


    .global scene_proc_d
    .type scene_proc_d, @function
scene_proc_d:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r8
    mov.l   .L_ptr_clip_dist, r10
    mov.l @r10, r10
    mov #0x18, r0
    mul.l r7, r0
    mov r5, r3
    mov r6, r13
    mov r3, r14
    sts macl, r0
    add r0, r8
.L_face_loop:
    mov.l r7, @-r15
    add #-0x18, r8
    mov.w @(16, r8), r0
    extu.w r0, r4
    mov #0x6, r1
    mul.l r1, r4
    sts macl, r4
    add r14, r4
    mov.w @r4+, r0
    mov.w @r4+, r1
    mov.w @r4+, r2
    mov.l   .L_ptr_vtx_scratch, r4
    shll8 r0
    shll2 r0
    shll r0
    mov.l r0, @r4
    shll8 r1
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)
    shll8 r2
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)
    mov.l   .L_ptr_xform_result, r5
    mov.l   .L_ptr_matrix_base, r0
    mov #0x24, r7
    mov.l @r0, r6
    add r6, r7
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r5
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @(8, r5)
    mov.l @(8, r5), r0
    cmp/ge r0, r10
    mov.l   .L_ptr_depth_out, r11
    .word 0x0029
    mov.w r0, @r11
    mov.w @(12, r8), r0
    tst #0x8, r0
    bf      .L_xform_face1
    mov.l   .L_ptr_dot_result, r5
    mov r8, r4
    mov.l   .L_ptr_matrix_base, r0
    clrmac
    mov.l @r0, r2
    mac.l @r4+, @r2+
    mac.l @r4+, @r2+
    mac.l @r4+, @r2+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r2+
    xtrct r0, r1
    mov.l r1, @r5
    mac.l @r4+, @r2+
    mac.l @r4+, @r2+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r2+
    xtrct r0, r1
    mov.l r1, @(4, r5)
    mac.l @r4+, @r2+
    mac.l @r4+, @r2+
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l r1, @(8, r5)
    mov.l   .L_ptr_xform_result, r4
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    sts mach, r1
    sts macl, r0
    xtrct r1, r0
    cmp/pl r0
    bt      .L_xform_face1
    bra     .L_next_face
    nop
    .2byte  0x0000
.L_ptr_clip_dist:
    .4byte  sym_06063F08
.L_ptr_vtx_scratch:
    .4byte  sym_06094AB0
.L_ptr_xform_result:
    .4byte  sym_06094A30
.L_ptr_matrix_base:
    .4byte  sym_06089EDC
.L_ptr_depth_out:
    .4byte  sym_06094A28
.L_ptr_dot_result:
    .4byte  sym_06094A60
.L_xform_face1:
    mov.w @(18, r8), r0
    mov #0x6, r1
    extu.w r0, r4
    mul.l r1, r4
    sts macl, r4
    add r14, r4
    mov.w @r4+, r0
    mov.w @r4+, r1
    mov.w @r4+, r2
    mov.l   .L_ptr_vtx_scratch_b, r4
    shll8 r0
    shll2 r0
    shll r0
    mov.l r0, @r4
    shll8 r1
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)
    shll8 r2
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)
    mov.l   .L_ptr_xform_result_b, r5
    add #0xC, r5
    mov.l   .L_ptr_matrix_base_b, r0
    mov #0x24, r7
    mov.l @r0, r6
    add r6, r7
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r5
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @(8, r5)
    mov.l @(8, r5), r0
    cmp/ge r0, r10
    .word 0x0029
    mov.w r0, @(2, r11)
    mov.w @(20, r8), r0
    mov #0x6, r1
    extu.w r0, r4
    mul.l r1, r4
    sts macl, r4
    add r14, r4
    mov.w @r4+, r0
    mov.w @r4+, r1
    mov.w @r4+, r2
    mov.l   .L_ptr_vtx_scratch_b, r4
    shll8 r0
    shll2 r0
    shll r0
    mov.l r0, @r4
    shll8 r1
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)
    mov.l   .L_ptr_y_component, r5
    mov.l r1, @r5
    shll8 r2
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)
    mov.l   .L_ptr_xform_result_b, r5
    add #0x18, r5
    mov.l   .L_ptr_matrix_base_b, r0
    mov #0x24, r7
    mov.l @r0, r6
    add r6, r7
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r5
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @(8, r5)
    mov.l @(8, r5), r0
    cmp/ge r0, r10
    .word 0x0029
    mov.w r0, @(4, r11)
    mov.w @(22, r8), r0
    mov #0x6, r1
    extu.w r0, r4
    mul.l r1, r4
    sts macl, r4
    add r14, r4
    mov.w @r4+, r0
    mov.w @r4+, r1
    mov.w @r4+, r2
    mov.l   .L_ptr_vtx_scratch_b, r4
    shll8 r0
    shll2 r0
    shll r0
    mov.l r0, @r4
    shll8 r1
    shll2 r1
    shll r1
    mov.l r1, @(4, r4)
    shll8 r2
    shll2 r2
    shll r2
    mov.l r2, @(8, r4)
    mov.l   .L_ptr_xform_result_b, r5
    add #0x24, r5
    mov.l   .L_ptr_matrix_base_b, r0
    mov #0x24, r7
    mov.l @r0, r6
    add r6, r7
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r5
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r5)
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @(8, r5)
    mov.l @(8, r5), r0
    cmp/ge r0, r10
    .word 0x0029
    mov.w r0, @(6, r11)
    mov.w @r11+, r2
    mov.w @r11+, r3
    mov.w @r11+, r1
    add r2, r3
    add r1, r0
    add r3, r0
    cmp/eq #0x0, r0
    bt      .L_project_faces
    cmp/eq #0x4, r0
    bf      .L_dispatch_combine
    bra     .L_next_face
    nop
.L_ptr_vtx_scratch_b:
    .4byte  sym_06094AB0
.L_ptr_xform_result_b:
    .4byte  sym_06094A30
.L_ptr_matrix_base_b:
    .4byte  sym_06089EDC
.L_ptr_y_component:
    .4byte  sym_06094AE0
.L_dispatch_combine:
    mov.l   .L_ptr_combine_tbl, r1
    shll2 r0
    add r1, r0
    mov.l @r0, r0
    mov.l   .L_ptr_xform_data, r4
    mov.l   .L_ptr_depth_array, r5
    jsr @r0
    nop
.L_project_faces:
    mov.l   .L_ptr_face_index, r0
    mov #0x18, r1
    mov.l @r0, r0
    mul.l r0, r1
    mov.l   .L_ptr_output_base, r2
    mov.l   .L_ptr_proj_workspace, r11
    sts macl, r9
    add r2, r9
    mov.l   .L_ptr_xform_data, r4
    mov r11, r5
    mov.w   DAT_0602b64c, r1
    mov.w   DAT_0602b64e, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0
    neg r3, r3
    sts mach, r1
    dmuls.l r3, r0
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov.l   .L_ptr_clip_flags, r12
    mov #0x0, r0
    mov.w r0, @r12
    mov.w   .L_x_pos_thresh, r3
    cmp/gt r3, r1
    bf      .L_f0_chk_x_neg
    mov #0x1, r0
    bra     .L_f1_project
    mov.w r0, @r12

    .global DAT_0602b64c
DAT_0602b64c:
    .2byte  0xFF00

    .global DAT_0602b64e
DAT_0602b64e:
    .2byte  0x00A0
.L_x_pos_thresh:
    .2byte  0x0190
    .2byte  0x0000
.L_ptr_combine_tbl:
    .4byte  sym_0602B9AC
.L_ptr_xform_data:
    .4byte  sym_06094A30
.L_ptr_depth_array:
    .4byte  sym_06094A28
.L_ptr_face_index:
    .4byte  sym_060620D0
.L_ptr_output_base:
    .4byte  sym_0608AC20
.L_ptr_proj_workspace:
    .4byte  sym_06094A90
.L_ptr_clip_flags:
    .4byte  sym_06094A20
.L_f0_chk_x_neg:
    mov.w   DAT_0602b67c, r3
    cmp/gt r1, r3
    bf      .L_f0_chk_y_pos
    mov #0x1, r0
    bra     .L_f1_project
    mov.w r0, @r12

    .global DAT_0602b67c
DAT_0602b67c:
    .2byte  0xFE70
.L_f0_chk_y_pos:
    mov.w   DAT_0602b68a, r3
    cmp/gt r3, r2
    bf      .L_f0_chk_y_neg
    mov #0x1, r0
    bra     .L_f1_project
    mov.w r0, @r12

    .global DAT_0602b68a
DAT_0602b68a:
    .2byte  0x012C
.L_f0_chk_y_neg:
    mov.w   DAT_0602b6d2, r3
    cmp/gt r2, r3
    bf      .L_f1_project
    mov #0x1, r0
    mov.w r0, @r12
.L_f1_project:
    mov r11, r5
    add #0xC, r4
    add #0x8, r5
    mov.w   DAT_0602b6d4, r1
    mov.w   DAT_0602b6d6, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0
    neg r3, r3
    sts mach, r1
    dmuls.l r3, r0
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(2, r12)
    mov.w   DAT_0602b6d8, r3
    cmp/gt r3, r1
    bf      .L_f1_chk_x_neg
    mov #0x1, r0
    bra     .L_f2_project
    mov.w r0, @(2, r12)

    .global DAT_0602b6d2
DAT_0602b6d2:
    .2byte  0xFE70

    .global DAT_0602b6d4
DAT_0602b6d4:
    .2byte  0xFF00

    .global DAT_0602b6d6
DAT_0602b6d6:
    .2byte  0x00A0

    .global DAT_0602b6d8
DAT_0602b6d8:
    .2byte  0x0190
.L_f1_chk_x_neg:
    mov.w   DAT_0602b6e6, r3
    cmp/gt r1, r3
    bf      .L_f1_chk_y_pos
    mov #0x1, r0
    bra     .L_f2_project
    mov.w r0, @(2, r12)

    .global DAT_0602b6e6
DAT_0602b6e6:
    .2byte  0xFE70
.L_f1_chk_y_pos:
    mov.w   DAT_0602b6f4, r3
    cmp/gt r3, r2
    bf      .L_f1_chk_y_neg
    mov #0x1, r0
    bra     .L_f2_project
    mov.w r0, @(2, r12)

    .global DAT_0602b6f4
DAT_0602b6f4:
    .2byte  0x012C
.L_f1_chk_y_neg:
    mov.w   DAT_0602b73c, r3
    cmp/gt r2, r3
    bf      .L_f2_project
    mov #0x1, r0
    mov.w r0, @(2, r12)
.L_f2_project:
    mov r11, r5
    add #0xC, r4
    add #0x10, r5
    mov.w   DAT_0602b73e, r1
    mov.w   DAT_0602b740, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0
    neg r3, r3
    sts mach, r1
    dmuls.l r3, r0
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(4, r12)
    mov.w   DAT_0602b742, r3
    cmp/gt r3, r1
    bf      .L_f2_chk_x_neg
    mov #0x1, r0
    bra     .L_f3_project
    mov.w r0, @(4, r12)

    .global DAT_0602b73c
DAT_0602b73c:
    .2byte  0xFE70

    .global DAT_0602b73e
DAT_0602b73e:
    .2byte  0xFF00

    .global DAT_0602b740
DAT_0602b740:
    .2byte  0x00A0

    .global DAT_0602b742
DAT_0602b742:
    .2byte  0x0190
.L_f2_chk_x_neg:
    mov.w   DAT_0602b750, r3
    cmp/gt r1, r3
    bf      .L_f2_chk_y_pos
    mov #0x1, r0
    bra     .L_f3_project
    mov.w r0, @(4, r12)

    .global DAT_0602b750
DAT_0602b750:
    .2byte  0xFE70
.L_f2_chk_y_pos:
    mov.w   DAT_0602b75e, r3
    cmp/gt r3, r2
    bf      .L_f2_chk_y_neg
    mov #0x1, r0
    bra     .L_f3_project
    mov.w r0, @(4, r12)

    .global DAT_0602b75e
DAT_0602b75e:
    .2byte  0x012C
.L_f2_chk_y_neg:
    mov.w   DAT_0602b7a6, r3
    cmp/gt r2, r3
    bf      .L_f3_project
    mov #0x1, r0
    mov.w r0, @(4, r12)
.L_f3_project:
    mov r11, r5
    add #0xC, r4
    add #0x18, r5
    mov.w   DAT_0602b7a8, r1
    mov.w   DAT_0602b7aa, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0
    neg r3, r3
    sts mach, r1
    dmuls.l r3, r0
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(6, r12)
    mov.w   DAT_0602b7ac, r3
    cmp/gt r3, r1
    bf      .L_f3_chk_x_neg
    mov #0x1, r0
    bra     .L_bounds_check
    mov.w r0, @(6, r12)

    .global DAT_0602b7a6
DAT_0602b7a6:
    .2byte  0xFE70

    .global DAT_0602b7a8
DAT_0602b7a8:
    .2byte  0xFF00

    .global DAT_0602b7aa
DAT_0602b7aa:
    .2byte  0x00A0

    .global DAT_0602b7ac
DAT_0602b7ac:
    .2byte  0x0190
.L_f3_chk_x_neg:
    mov.w   DAT_0602b7ba, r3
    cmp/gt r1, r3
    bf      .L_f3_chk_y_pos
    mov #0x1, r0
    bra     .L_bounds_check
    mov.w r0, @(6, r12)

    .global DAT_0602b7ba
DAT_0602b7ba:
    .2byte  0xFE70
.L_f3_chk_y_pos:
    mov.w   DAT_0602b7c8, r3
    cmp/gt r3, r2
    bf      .L_f3_chk_y_neg
    mov #0x1, r0
    bra     .L_bounds_check
    mov.w r0, @(6, r12)

    .global DAT_0602b7c8
DAT_0602b7c8:
    .2byte  0x012C
.L_f3_chk_y_neg:
    mov.w   DAT_0602b7f8, r3
    cmp/gt r2, r3
    bf      .L_bounds_check
    mov #0x1, r0
    mov.w r0, @(6, r12)
.L_bounds_check:
    mov.l   .L_const_x_lower, r4
    mov.l   .L_const_x_upper, r5
    mov.l   .L_const_y_lower, r6
    mov.l   .L_const_y_upper, r7
    mov.l @r11, r0
    cmp/gt r0, r4
    bf      .L_chk_x_upper
    mov.l @(8, r11), r0
    cmp/gt r0, r4
    bf      .L_chk_x_upper
    mov.l @(16, r11), r0
    cmp/gt r0, r4
    bf      .L_chk_x_upper
    mov.l @(24, r11), r0
    cmp/gt r0, r4
    bf      .L_chk_x_upper
    bra     .L_next_face
    nop

    .global DAT_0602b7f8
DAT_0602b7f8:
    .2byte  0xFE70
    .2byte  0x0000
.L_const_x_lower:
    .4byte  0xFFFFFF50
.L_const_x_upper:
    .4byte  0x000000B0
.L_const_y_lower:
    .4byte  0xFFFFFF81
.L_const_y_upper:
    .4byte  0x00000051
.L_chk_x_upper:
    mov.l @r11, r0
    cmp/gt r0, r5
    bt      .L_chk_y_lower
    mov.l @(8, r11), r0
    cmp/gt r0, r5
    bt      .L_chk_y_lower
    mov.l @(16, r11), r0
    cmp/gt r0, r5
    bt      .L_chk_y_lower
    mov.l @(24, r11), r0
    cmp/gt r0, r5
    bt      .L_chk_y_lower
    bra     .L_next_face
    nop
.L_chk_y_lower:
    mov.l @(4, r11), r0
    cmp/gt r0, r6
    bf      .L_chk_y_upper
    mov.l @(12, r11), r0
    cmp/gt r0, r6
    bf      .L_chk_y_upper
    mov.l @(20, r11), r0
    cmp/gt r0, r6
    bf      .L_chk_y_upper
    mov.l @(28, r11), r0
    cmp/gt r0, r6
    bf      .L_chk_y_upper
    bra     .L_next_face
    nop
.L_chk_y_upper:
    mov.l @(4, r11), r0
    cmp/gt r0, r7
    bt      .L_sum_clip_flags
    mov.l @(12, r11), r0
    cmp/gt r0, r7
    bt      .L_sum_clip_flags
    mov.l @(20, r11), r0
    cmp/gt r0, r7
    bt      .L_sum_clip_flags
    mov.l @(28, r11), r0
    cmp/gt r0, r7
    bt      .L_sum_clip_flags
    bra     .L_next_face
    nop
.L_sum_clip_flags:
    mov.w @r12, r1
    mov.w @(2, r12), r0
    add r0, r1
    mov.w @(4, r12), r0
    add r0, r1
    mov.w @(6, r12), r0
    add r1, r0
    cmp/eq #0x4, r0
    bf      .L_faces_visible
    bra     .L_next_face
    nop
.L_faces_visible:
    cmp/eq #0x0, r0
    bt      .L_store_proj
    mov r11, r4
    shll2 r0
    mov.l   .L_ptr_combine_fn_tbl, r1
    add r1, r0
    mov.l @r0, r0
    jsr @r0
    mov r12, r5
.L_store_proj:
    mov.l @r11, r0
    mov.w r0, @(8, r9)
    mov.l @(4, r11), r0
    mov.w r0, @(10, r9)
    mov.l @(8, r11), r0
    mov.w r0, @(12, r9)
    mov.l @(12, r11), r0
    mov.w r0, @(14, r9)
    mov.l @(16, r11), r0
    mov.w r0, @(16, r9)
    mov.l @(20, r11), r0
    mov.w r0, @(18, r9)
    mov.l @(24, r11), r0
    mov.w r0, @(20, r9)
    mov.l @(28, r11), r0
    mov.w r0, @(22, r9)
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
    mov.l   .L_ptr_depth_mode_tbl, r1
    and #0x7, r0
    shll2 r0
    mov.l @(r0, r1), r0
    mov.l   .L_ptr_face_xforms, r1
    mov.l @(8, r1), r3
    mov.l @(20, r1), r4
    mov.l @(32, r1), r5
    jmp @r0
    mov.l @(44, r1), r6
.L_ptr_combine_fn_tbl:
    .4byte  sym_0602B9BC
.L_ptr_depth_mode_tbl:
    .4byte  sym_0602B9CC
.L_ptr_face_xforms:
    .4byte  sym_06094A30

    .global loc_0602B8DC
loc_0602B8DC:
    add r4, r3
    add r5, r6
    add r6, r3
    shlr2 r3
    bra     .L_store_depth
    nop

    .global loc_0602B8E8
loc_0602B8E8:
    cmp/ge r3, r4
    bt      .L_min_chk_1
    mov r4, r3
.L_min_chk_1:
    cmp/ge r3, r5
    bt      .L_min_chk_2
    mov r5, r3
.L_min_chk_2:
    cmp/ge r3, r6
    bt      .L_min_done
    mov r6, r3
.L_min_done:
    bra     .L_store_depth
    nop

    .global loc_0602B8FE
loc_0602B8FE:
    cmp/gt r3, r4
    bf      .L_max_chk_1
    mov r4, r3
.L_max_chk_1:
    cmp/gt r3, r5
    bf      .L_max_chk_2
    mov r5, r3
.L_max_chk_2:
    cmp/gt r3, r6
    bf      .L_max_done
    mov r6, r3
.L_max_done:
    bra     .L_store_depth
    nop

    .global loc_0602B914
loc_0602B914:
    mov.l   .L_fp_bias_b8, r0
    cmp/gt r3, r4
    bf      .L_max_bias_chk_1
    mov r4, r3
.L_max_bias_chk_1:
    cmp/gt r3, r5
    bf      .L_max_bias_chk_2
    mov r5, r3
.L_max_bias_chk_2:
    cmp/gt r3, r6
    bf      .L_max_bias_done
    mov r6, r3
.L_max_bias_done:
    bra     .L_store_depth
    add r0, r3
.L_fp_bias_b8:
    .4byte  0x000B8000

    .global loc_0602B930
loc_0602B930:
    mov.l   .L_fp_one, r0
    cmp/gt r3, r4
    bf      .L_max_fp1_chk_1
    mov r4, r3
.L_max_fp1_chk_1:
    cmp/gt r3, r5
    bf      .L_max_fp1_chk_2
    mov r5, r3
.L_max_fp1_chk_2:
    cmp/gt r3, r6
    bf      .L_max_fp1_add
    mov r6, r3
.L_max_fp1_add:
    add r0, r3
.L_store_depth:
    mov.l   .L_ptr_y_comp_val, r1
    mov.l @r1, r1
    mov.l   .L_ptr_scene_param, r0
    mov.l @r0, r0
    mov.l   .L_fp_two, r2
    add r2, r1
    cmp/gt r1, r0
    bf      .L_write_zsort
    mov.l   .L_fp_ten, r2
    add r2, r3
.L_write_zsort:
    mov.l   .L_ptr_zsort_idx, r2
    neg r3, r3
    mov.l   .L_ptr_zsort_buf, r1
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
.L_fp_one:
    .4byte  0x00010000
.L_ptr_y_comp_val:
    .4byte  sym_06094AE0
.L_ptr_scene_param:
    .4byte  sym_06063F54
.L_fp_two:
    .4byte  0x00020000
.L_fp_ten:
    .4byte  0x000A0000
.L_ptr_zsort_idx:
    .4byte  sym_060620D0
.L_ptr_zsort_buf:
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

    .global sym_0602B9AC
sym_0602B9AC:
    .word 0x0000
    .word 0x0000
    .4byte  spring_damper
    .4byte  transform_pipeline
    .4byte  mega_render_func

    .global sym_0602B9BC
sym_0602B9BC:
    .word 0x0000
    .word 0x0000
    .4byte  vblank_frame_handler
    .4byte  render_list_builder
    .4byte  render_obj_processor

    .global sym_0602B9CC
sym_0602B9CC:
    .4byte  loc_0602B8DC
    .4byte  loc_0602B8E8
    .4byte  loc_0602B8FE
    .4byte  loc_0602B930
    .4byte  loc_0602B914

    .global sym_0602B9E0
sym_0602B9E0:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
