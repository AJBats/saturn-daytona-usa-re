
    .section .text.FUN_0600AA98


    .global render_obj_additive
    .type render_obj_additive, @function
render_obj_additive:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov r5, r13
    mov.l r11, @-r15
    shll2 r13
    mov.l r10, @-r15
    mov r4, r10
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_config_table_base, r3
    add r3, r13
    mov.b @(3, r13), r0
    mov r0, r2
    extu.b r2, r2
    mov #0x48, r0
    mov.l r2, @(8, r15)
    mov.l @(r0, r10), r3
    mov #0x40, r0
    neg r3, r3
    mov.l r3, @(4, r15)
    mov.l @(r0, r10), r3
    shll r3
    mov.l r3, @r15
    mov.b @r13, r2
    mov.l   .L_matrix_push, r1
    extu.b r2, r2
    jsr @r1
    mov.l r2, @(12, r15)
    mov.l   .L_position_table_1, r14
    mov.l   .L_translate_fn, r3
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    neg r6, r6
    jsr @r3
    mov.l @r14, r4
    mov.l   .L_rot_y_fn, r3
    jsr @r3
    mov.l @r15, r4
    mov.l   .L_transform_fn, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov.l   .L_car_data_1, r11
    mov.l @(12, r15), r14
    mov.l   .L_car_data_3, r5
    mov.l   .L_dist_check_fn, r3
    shll2 r14
    add r14, r5
    mov r14, r4
    mov.l @r5, r5
    add r11, r4
    jsr @r3
    mov.l @r4, r4
    mov r14, r4
    mov.l   .L_sprite_submit_fn, r2
    mov.l   .L_car_data_0, r8
    mov.l   .L_car_data_2, r6
    mov.l @(8, r15), r9
    mov.l   .L_sprite_index_table, r3
    add r8, r4
    add r14, r6
    shll r9
    mov.l @r6, r6
    add r3, r9
    mov.w @r9, r5
    jsr @r2
    mov.l @r4, r4
    mov.l   .L_render_budget, r14
    mov.l @r14, r3
    add #-0x30, r3
    mov.l r3, @r14
    mov.b @(1, r13), r0
    mov.l   .L_matrix_push, r3
    mov r0, r2
    extu.b r2, r2
    jsr @r3
    mov.l r2, @(8, r15)
    mov.l   .L_position_table_2, r12
    mov.l   .L_translate_fn, r3
    mov.l @(8, r12), r6
    mov.l @(4, r12), r5
    neg r6, r6
    jsr @r3
    mov.l @r12, r4
    mov.l   .L_rot_y_fn, r3
    jsr @r3
    mov.l @r15, r4
    mov.l   .L_transform_fn, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov.l @(8, r15), r12
    mov.l   .L_car_data_3, r5
    mov.l   .L_dist_check_fn, r3
    shll2 r12
    add r12, r5
    mov r12, r4
    mov.l @r5, r5
    add r11, r4
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_car_data_2, r6
    mov r12, r4
    mov.l   .L_sprite_submit_fn, r3
    mov.w @r9, r5
    add r12, r6
    add r8, r4
    mov.l @r6, r6
    jsr @r3
    mov.l @r4, r4
    mov.l @r14, r2
    add #-0x30, r2
    mov.l r2, @r14
    mov #0x50, r0
    mov.l @(r0, r10), r3
    neg r3, r3
    mov.l r3, @r15
    mov.b @(2, r13), r0
    bra     .L_subobj_2
    nop
    .2byte  0xFFFF
.L_config_table_base:
    .4byte  sym_0605A1D5
.L_matrix_push:
    .4byte  sym_06026DBC
.L_position_table_1:
    .4byte  sym_06044640
.L_translate_fn:
    .4byte  sym_06026E2E
.L_rot_y_fn:
    .4byte  mat_rot_y
.L_transform_fn:
    .4byte  mat_rot_x
.L_car_data_1:
    .4byte  sym_0606212C
.L_car_data_3:
    .4byte  sym_060621D8
.L_dist_check_fn:
    .4byte  sym_06031D8C
.L_car_data_0:
    .4byte  sym_060620D8
.L_car_data_2:
    .4byte  sym_06062180
.L_sprite_index_table:
    .4byte  sym_06089E44
.L_sprite_submit_fn:
    .4byte  sym_06031A28
.L_render_budget:
    .4byte  sym_06089EDC
.L_position_table_2:
    .4byte  sym_0604464C
.L_subobj_2:
    mov r0, r2
    mov.l   .L_matrix_push_2, r1
    extu.b r2, r2
    jsr @r1
    mov.l r2, @(4, r15)
    mov.l   .L_position_table_3, r13
    mov.l   .L_translate_fn_2, r3
    mov.l @(8, r13), r6
    mov.l @(4, r13), r5
    neg r6, r6
    jsr @r3
    mov.l @r13, r4
    mov.l   .L_transform_fn_2, r3
    jsr @r3
    mov.l @r15, r4
    mov.l @(4, r15), r13
    mov.l   .L_car_data_3_2, r5
    mov.l   .L_dist_check_fn_2, r3
    shll2 r13
    add r13, r5
    add r13, r11
    mov.l @r5, r5
    jsr @r3
    mov.l @r11, r4
    mov.l   .L_car_data_2_2, r6
    add r13, r8
    mov.l   .L_sprite_submit_fn_2, r3
    mov.w @r9, r5
    add r13, r6
    mov.l @r6, r6
    jsr @r3
    mov.l @r8, r4
    mov.l @r14, r2
    add #-0x30, r2
    mov.l r2, @r14
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_matrix_push_2:
    .4byte  sym_06026DBC
.L_position_table_3:
    .4byte  sym_06044670
.L_translate_fn_2:
    .4byte  sym_06026E2E
.L_transform_fn_2:
    .4byte  mat_rot_x
.L_car_data_3_2:
    .4byte  sym_060621D8
.L_dist_check_fn_2:
    .4byte  sym_06031D8C
.L_car_data_2_2:
    .4byte  sym_06062180
.L_sprite_submit_fn_2:
    .4byte  sym_06031A28
