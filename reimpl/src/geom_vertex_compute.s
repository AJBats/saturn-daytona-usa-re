
    .section .text.FUN_0601EBDA


    .global geom_vertex_compute
    .type geom_vertex_compute, @function
geom_vertex_compute:
    mov.l r14, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.w   .L_const_batch_stride, r5
    .byte   0xD0, 0x09    /* mov.l .L_ptr_geom_busy_flag, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_begin_unpack
    bra     .L_epilogue
    nop
.L_const_batch_stride:
    .2byte  0x00F0
    .2byte  0xFFFF
    .4byte  sym_0604A5C0
    .4byte  sym_060877D8
    .4byte  sym_0605E098
    .4byte  sym_0604A5AC
    .4byte  sym_0605E09C
.L_ptr_geom_busy_flag:
    .4byte  sym_06087080
.L_begin_unpack:
    .byte   0xD4, 0xB5    /* mov.l .L_ptr_input_buf, r4 */
    mov.l @r4, r4
    add #0x10, r4
    .byte   0xD6, 0xB5    /* mov.l .L_ptr_vtx_row_table, r6 */
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
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    mov.b r2, @r14
    mov r0, r14
    add #0x4, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    mov.b r2, @r14
    mov r0, r14
    add #0x8, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    add #0xC, r6
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    cmp/hs r12, r6
    bf/s    .L_row_table_inner
    mov.b r2, @r14
    add #0x8, r7
    cmp/hs r11, r7
    bf      .L_row_table_outer
    .byte   0xD6, 0x9B    /* mov.l .L_ptr_model_desc_table, r6 */
    mov r6, r7
    add #0x18, r7
.L_unpack_model_desc:
    mov.l @r6, r0
    mov.b @r4+, r1
    mov r0, r14
    add #0x4, r6
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    mov.b r2, @r14
    mov r0, r14
    mov.b @r4+, r1
    add #0x4, r14
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    cmp/hs r7, r6
    bf/s    .L_unpack_model_desc
    mov.b r2, @r14
    .byte   0xD6, 0x8C    /* mov.l .L_ptr_vtx_scale_a, r6 */
    mov r6, r7
    add #0x20, r7
.L_unpack_scale_a:
    mov r6, r14
    mov.b @r4+, r1
    add #0x4, r6
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    mov.b r2, @r14
    mov r6, r14
    mov.b @r4+, r1
    add #0x4, r6
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    cmp/hs r7, r6
    bf/s    .L_unpack_scale_a
    mov.b r2, @r14
    .byte   0xD6, 0x7E    /* mov.l .L_ptr_vtx_scale_b, r6 */
    mov r6, r7
    add #0x20, r7
.L_unpack_scale_b:
    mov r6, r14
    mov.b @r4+, r1
    add #0x4, r6
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    mov.b r2, @r14
    mov r6, r14
    mov.b @r4+, r1
    add #0x4, r6
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r1
    mov.b r1, @r14
    add #0x1, r14
    mov.b @r4+, r2
    cmp/hs r7, r6
    bf/s    .L_unpack_scale_b
    mov.b r2, @r14
    .byte   0xD6, 0x6F    /* mov.l .L_ptr_coord_extents, r6 */
    mov r6, r7
    mov r6, r14
    add #0x24, r14
.L_unpack_extents:
    mov r7, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    add #0xC, r7
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    cmp/hs r14, r7
    bf/s    .L_unpack_extents
    mov.b r2, @r6
    .byte   0xD6, 0x5B    /* mov.l .L_ptr_course_data_a, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x56    /* mov.l .L_ptr_course_data_b, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x51    /* mov.l .L_ptr_course_data_c, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    mov.b @r4+, r2
    .byte   0xD3, 0x4B    /* mov.l .L_ptr_anim_flag_a, r3 */
    mov.b r2, @r3
    mov.b @r4+, r3
    .byte   0xD2, 0x4B    /* mov.l .L_ptr_anim_flag_b, r2 */
    mov.b r3, @r2
    mov.b @r4+, r2
    .byte   0xD3, 0x4A    /* mov.l .L_ptr_disp_flag_a, r3 */
    mov.b r2, @r3
    mov.b @r4+, r3
    .byte   0xD2, 0x4A    /* mov.l .L_ptr_disp_flag_b, r2 */
    mov.b r3, @r2
    .byte   0xD6, 0x4A    /* mov.l .L_ptr_xform_param_00, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x48    /* mov.l .L_ptr_xform_param_02, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x46    /* mov.l .L_ptr_xform_param_04, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x44    /* mov.l .L_ptr_xform_param_06, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x42    /* mov.l .L_ptr_xform_param_08, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x40    /* mov.l .L_ptr_xform_param_0A, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x3E    /* mov.l .L_ptr_xform_param_0C, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x3C    /* mov.l .L_ptr_xform_param_0E, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x3A    /* mov.l .L_ptr_xform_param_10, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x35    /* mov.l .L_ptr_xform_param_14, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x30    /* mov.l .L_ptr_xform_param_18, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x2B    /* mov.l .L_ptr_xform_param_1C, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x29    /* mov.l .L_ptr_xform_param_1E, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x27    /* mov.l .L_ptr_xform_param_20, r6 */
    mov r6, r3
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r3
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x24    /* mov.l .L_ptr_xform_param_22, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x22    /* mov.l .L_ptr_xform_param_24, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x20    /* mov.l .L_ptr_xform_param_26, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    bra     .L_single_field_cont
    nop
.L_ptr_input_buf:
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
.L_ptr_xform_param_22:
    .4byte  sym_06060D5E
.L_ptr_xform_param_24:
    .4byte  sym_06060D64
.L_ptr_xform_param_26:
    .4byte  sym_06060D66
.L_single_field_cont:
    .byte   0xD6, 0x1F    /* mov.l .L_ptr_xform_param_28, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x1D    /* mov.l .L_ptr_xform_param_2A, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x1B    /* mov.l .L_ptr_xform_param_2C, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x16    /* mov.l .L_ptr_xform_param_30, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r2
    mov.b r2, @r6
    .byte   0xD6, 0x11    /* mov.l .L_ptr_xform_param_34, r6 */
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4+, r1
    mov.b r1, @r6
    add #0x1, r6
    mov.b @r4, r3
    mov.b r3, @r6
.L_epilogue:
    mov.l @r15+, r11
    mov.l @r15+, r12
    rts
    mov.l @r15+, r14
