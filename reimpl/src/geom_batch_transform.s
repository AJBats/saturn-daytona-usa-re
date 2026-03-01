
    .section .text.FUN_0601EFC4


    .global geom_batch_transform
    .type geom_batch_transform, @function
geom_batch_transform:
    mov.l r14, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.w   .L_const_batch_stride, r5
    mov.l   .L_ptr_geom_busy_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_begin_copy
    bra     .L_epilogue
    nop
.L_const_batch_stride:
    .2byte  0x00F0
    .4byte  sym_06060D68
    .4byte  sym_06060D6A
    .4byte  sym_06060D70
    .4byte  sym_06060D74
    .4byte  sym_06060D6C
.L_ptr_geom_busy_flag:
    .4byte  sym_06087080
.L_begin_copy:
    mov.l   .L_ptr_output_buf, r4
    mov.l @r4, r4
    add #0x10, r4
    mov.l   .L_ptr_vtx_row_table, r6
    mov r6, r7
    mov r6, r11
    add #0x48, r11
.L_row_table_outer:
    mov.l @r7, r14
    mov r14, r6
    mov r14, r12
    add r5, r12
.L_row_table_inner:
    mov r6, r0
    mov r6, r14
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    add #0x1, r4
    mov r0, r14
    add #0x4, r14
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    add #0x1, r4
    mov r0, r14
    add #0x8, r14
    mov.b @r14+, r1
    add #0xC, r6
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    cmp/hs r12, r6
    bf/s    .L_row_table_inner
    add #0x1, r4
    add #0x8, r7
    cmp/hs r11, r7
    bf      .L_row_table_outer
    mov.l   .L_ptr_model_desc_table, r6
    mov r6, r7
    add #0x18, r7
.L_copy_model_desc:
    mov.l @r6, r0
    add #0x4, r6
    mov r0, r14
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov r0, r14
    mov.b r2, @r4
    add #0x4, r14
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    cmp/hs r7, r6
    bf/s    .L_copy_model_desc
    add #0x1, r4
    mov.l   .L_ptr_vtx_scale_a, r6
    mov r6, r7
    add #0x20, r7
.L_copy_scale_a:
    mov r6, r14
    add #0x4, r6
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov r6, r14
    mov.b r2, @r4
    add #0x4, r6
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    cmp/hs r7, r6
    bf/s    .L_copy_scale_a
    add #0x1, r4
    mov.l   .L_ptr_vtx_scale_b, r6
    mov r6, r7
    add #0x20, r7
.L_copy_scale_b:
    mov r6, r14
    mov.b @r14+, r1
    add #0x4, r6
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov r6, r14
    mov.b r2, @r4
    add #0x4, r6
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r14, r2
    mov.b r2, @r4
    cmp/hs r7, r6
    bf/s    .L_copy_scale_b
    add #0x1, r4
    mov.l   .L_ptr_coord_extents, r6
    mov r6, r7
    mov r6, r14
    add #0x24, r14
.L_copy_extents:
    mov r7, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    add #0xC, r7
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    cmp/hs r14, r7
    bf/s    .L_copy_extents
    add #0x1, r4
    mov.l   .L_ptr_course_data_a, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_course_data_b, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_course_data_c, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_anim_flag_a, r2
    mov.b @r2, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_anim_flag_b, r2
    mov.b @r2, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_disp_flag_a, r2
    mov.b @r2, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_disp_flag_b, r2
    mov.b @r2, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_00, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_02, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_04, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_06, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_08, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_0A, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_0C, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_0E, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_10, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_14, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_18, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov r4, r3
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r3
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_1C, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_1E, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_20, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    bra     .L_copy_tail_params
    nop
.L_ptr_output_buf:
    .4byte  sym_0605E098
.L_ptr_vtx_row_table:
    .4byte  sym_0605DD6C
.L_ptr_model_desc_table:
    .4byte  sym_0605DE24
.L_ptr_vtx_scale_a:
    .4byte  sym_0605DDB4
.L_ptr_vtx_scale_b:
    .4byte  sym_0605DDD4
.L_ptr_coord_extents:
    .4byte  sym_0605DE40
.L_ptr_course_data_a:
    .4byte  sym_0605AD00
.L_ptr_course_data_b:
    .4byte  sym_0605AD04
.L_ptr_course_data_c:
    .4byte  sym_0605AD0C
.L_ptr_anim_flag_a:
    .4byte  sym_0605AB16
.L_ptr_anim_flag_b:
    .4byte  sym_0605AB17
.L_ptr_disp_flag_a:
    .4byte  sym_0605D240
.L_ptr_disp_flag_b:
    .4byte  sym_0605D241
.L_ptr_xform_param_00:
    .4byte  sym_06060D44
.L_ptr_xform_param_02:
    .4byte  sym_06060D46
.L_ptr_xform_param_04:
    .4byte  sym_06060D40
.L_ptr_xform_param_06:
    .4byte  sym_06060D42
.L_ptr_xform_param_08:
    .4byte  sym_06060D48
.L_ptr_xform_param_0A:
    .4byte  sym_06060D4A
.L_ptr_xform_param_0C:
    .4byte  sym_06060D4C
.L_ptr_xform_param_0E:
    .4byte  sym_06060D4E
.L_ptr_xform_param_10:
    .4byte  sym_06060D54
.L_ptr_xform_param_14:
    .4byte  sym_06060D58
.L_ptr_xform_param_18:
    .4byte  sym_06060D50
.L_ptr_xform_param_1C:
    .4byte  sym_06060D60
.L_ptr_xform_param_1E:
    .4byte  sym_06060D62
.L_ptr_xform_param_20:
    .4byte  sym_06060D5C
.L_copy_tail_params:
    add #0x1, r4
    mov.l   .L_ptr_xform_param_22, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_24, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_26, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_28, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_2A, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_2C, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_30, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r2
    mov.b r2, @r4
    add #0x1, r4
    mov.l   .L_ptr_xform_param_34, r6
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6+, r1
    mov.b r1, @r4
    add #0x1, r4
    mov.b @r6, r3
    mov.b r3, @r4
.L_epilogue:
    mov.l @r15+, r11
    mov.l @r15+, r12
    rts
    mov.l @r15+, r14
.L_ptr_xform_param_22:
    .4byte  sym_06060D5E
.L_ptr_xform_param_24:
    .4byte  sym_06060D64
.L_ptr_xform_param_26:
    .4byte  sym_06060D66
.L_ptr_xform_param_28:
    .4byte  sym_06060D68
.L_ptr_xform_param_2A:
    .4byte  sym_06060D6A
.L_ptr_xform_param_2C:
    .4byte  sym_06060D70
.L_ptr_xform_param_30:
    .4byte  sym_06060D74
.L_ptr_xform_param_34:
    .4byte  sym_06060D6C
