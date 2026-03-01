
    .section .text.FUN_06022140


    .global scene_process_stage
    .type scene_process_stage, @function
scene_process_stage:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x24, r15
    mov.l   .L_fp_1000, r8
    mov.l   .L_fn_fpmul, r9
    mov.l   .L_entity_data_base, r10
    mov #0x0, r11
    mov.l   .L_entity_pos_base, r12
    mov.l   .L_entity_type_table, r13
    mov.l   .L_player_car_ptr, r3
    mov.l @r3, r3
    mov.l r3, @(4, r15)
    mov.l   .L_offset_table_a, r3
    mov.l r3, @(16, r15)
    mov.l   .L_offset_table_b, r3
    mov.l r3, @(20, r15)
    bra     .L_loop_check
    mov r11, r14
.L_entity_loop:
    exts.w r14, r5
    mov.l @(4, r15), r7
    mov r5, r3
    mov.l @(16, r7), r7
    shll2 r5
    shll2 r3
    shll r5
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r12, r5
    mov.l @r5, r6
    mov r6, r4
    sub r7, r4
    cmp/pz r4
    bt      .L_dx_positive
    mov r7, r4
    sub r6, r4
.L_dx_positive:
    mov.l @(8, r5), r3
    mov.l r3, @r15
    mov r3, r6
    mov.l @(4, r15), r7
    mov.l @(24, r7), r7
    sub r7, r6
    cmp/pz r6
    bt      .L_dz_positive
    mov.l @r15, r2
    mov r7, r5
    bra     .L_dz_done
    sub r2, r5
.L_dz_positive:
    mov r6, r5
.L_dz_done:
    mov.l   .L_cull_threshold, r2
    cmp/ge r2, r4
    bf      .L_dz_cull_check
    bra     .L_entity_next
    nop
.L_dz_cull_check:
    mov.l   .L_cull_threshold, r2
    cmp/ge r2, r5
    bf      .L_in_range
    bra     .L_entity_next
    nop
.L_in_range:
    mov r14, r0
    shll2 r0
    mov.l   .L_activation_table, r3
    mov.l @(r0, r3), r0
    bra     .L_activation_dispatch
    nop
.L_type0_setup:
    cmp/gt r5, r4
    bf      .L_type0_dz_dominant
    mov r5, r3
    shar r3
    shar r3
    add r3, r4
    bra     .L_type0_lod_check
    nop
.L_fp_1000:
    .4byte  0x03E80000
.L_fn_fpmul:
    .4byte  fpmul
.L_entity_data_base:
    .4byte  sym_060896B8
.L_entity_pos_base:
    .4byte  sym_060897D0
.L_entity_type_table:
    .4byte  sym_060895A0
.L_player_car_ptr:
    .4byte  sym_0607E944
.L_offset_table_a:
    .4byte  sym_06089C58
.L_offset_table_b:
    .4byte  sym_06089E98
.L_cull_threshold:
    .4byte  0x006A0000
.L_activation_table:
    .4byte  sym_0608962C
.L_type0_dz_dominant:
    mov r4, r2
    shar r2
    shar r2
    mov r2, r4
    add r5, r4
.L_type0_lod_check:
    mov r14, r0
    mov.l   .L_lod_scale_table, r2
    shll2 r0
    mov.l @(r0, r13), r3
    shll2 r3
    add r2, r3
    mov.l @r3, r3
    cmp/hi r3, r4
    bf      .L_within_lod
    exts.w r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r12, r4
    mov.l @r4, r2
    mov.l r2, @(24, r15)
    mov.l @(8, r4), r3
    mov.l r3, @(32, r15)
    mov.l @(4, r4), r0
    tst r0, r0
    bf      .L_type0_has_state
    mov.l r8, @(28, r15)
    mov r15, r6
    add #0xC, r6
    mov.l r6, @-r15
    mov r15, r5
    add #0x1C, r5
    mov.l r5, @-r15
    mov.l @(40, r15), r5
    mov.l   .L_fn_heading_calc, r3
    jsr @r3
    mov.l @(32, r15), r4
    mov r0, r4
    mov.l @r15+, r5
    mov.l   .L_fn_scene_render, r3
    jsr @r3
    mov.l @r15+, r6
    mov.w @(12, r15), r0
    mov #0x34, r3
    mov.l   .L_validation_table, r2
    mov r0, r4
    extu.w r4, r4
    mul.l r3, r4
    mov.l @(28, r15), r3
    sts macl, r4
    cmp/eq r8, r3
    bt/s    .L_type0_cull
    add r2, r4
    mov.l @r4, r0
    tst #0x80, r0
    bt      .L_type0_visible
.L_type0_cull:
    exts.w r14, r3
    mov r3, r2
    shll2 r3
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l   .L_cull_marker, r1
    mov.l r1, @r3
    bra     .L_entity_next
    nop
.L_type0_visible:
    mov r14, r0
    mov.w   .L_lod_offset_base, r2
    mov.l @(28, r15), r3
    shll2 r0
    add r2, r3
    mov.l r3, @(28, r15)
    mov.l @(r0, r13), r0
    cmp/eq #0x3, r0
    bf      .L_type0_not_3
    mov.l   .L_type3_lod_bonus, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
.L_type0_not_3:
    mov r14, r0
    shll2 r0
    mov.l @(r0, r13), r0
    cmp/eq #0x4, r0
    bt      .L_type0_is_4
    bra     .L_do_transform
    nop
.L_type0_is_4:
    mov.l   .L_type4_lod_bonus, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
    bra     .L_do_transform
    nop
.L_type0_has_state:
    exts.w r14, r2
    mov r2, r3
    shll2 r2
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r12, r2
    mov.l @(4, r2), r1
    bra     .L_do_transform
    mov.l r1, @(28, r15)
.L_lod_offset_base:
    .2byte  0x0100
.L_lod_scale_table:
    .4byte  sym_06050788
.L_fn_heading_calc:
    .4byte  sym_06006838
.L_fn_scene_render:
    .4byte  scene_render_alt
.L_validation_table:
    .4byte  sym_060A6000
.L_cull_marker:
    .4byte  0x4E200000
.L_type3_lod_bonus:
    .4byte  0x00013333
.L_type4_lod_bonus:
    .4byte  0x0000CCCC
.L_within_lod:
    mov r14, r2
    mov #0x1, r1
    shll2 r2
    mov.l r2, @r15
    mov.l   .L_activation_store, r3
    add r3, r2
    mov.l r1, @r2
    exts.w r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l r11, @(4, r3)
    mov.l @r15, r5
    mov.l   .L_lod_factor_table, r3
    mov.l @(4, r15), r4
    add r13, r5
    mov.l @r5, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    jsr @r9
    mov.l @(12, r4), r4
    mov r0, r4
    mov.l @(4, r15), r3
    mov #0x46, r2
    mov.l @(8, r3), r3
    cmp/gt r2, r3
    bf      .L_lod_medium_check
    mov.l   .L_lod_standard, r5
    jsr @r9
    nop
    mov r14, r4
    mov.l r0, @(8, r15)
    shll2 r4
    mov.l   .L_lod_store, r3
    mov r4, r2
    mov r4, r5
    add r4, r3
    add r13, r5
    mov.l r0, @r3
    mov.l @r5, r5
    tst r5, r5
    bt/s    .L_lod_type_check
    add r10, r2
    mov r5, r0
    cmp/eq #0x3, r0
    bt      .L_lod_type_check
    mov r5, r0
    cmp/eq #0x4, r0
    bf      .L_lod_type_other
.L_lod_type_check:
    bra     .L_lod_type_set
    mov #0x0, r3
.L_lod_type_other:
    mov #0x4, r3
.L_lod_type_set:
    mov.l r3, @r2
    bra     .L_type0_finalize
    nop
.L_lod_medium_check:
    mov.l @(4, r15), r2
    mov.l @(8, r2), r3
    mov #0x1E, r2
    cmp/gt r2, r3
    bf      .L_lod_close
    mov.l   .L_lod_standard, r5
    jsr @r9
    nop
    mov.l r0, @(8, r15)
    mov r14, r3
    shll2 r3
    mov.l r3, @r15
    mov.l   .L_lod_store, r2
    add r2, r3
    mov.l r3, @-r15
    mov.l   .L_lod_medium_factor, r5
    mov.l @(8, r15), r4
    jsr @r9
    mov.l @(12, r4), r4
    mov.l @r15+, r3
    mov.l r0, @r3
    mov.l @r15, r2
    mov.l @r15, r4
    add r13, r4
    mov.l @r4, r4
    mov r4, r0
    cmp/eq #0x3, r0
    bt/s    .L_lod_med_type_check
    add r10, r2
    mov r4, r0
    cmp/eq #0x4, r0
    bf      .L_lod_med_other
.L_lod_med_type_check:
    bra     .L_lod_med_set
    mov #0xE, r3
.L_lod_med_other:
    mov #0x4, r3
.L_lod_med_set:
    mov.l r3, @r2
    bra     .L_type0_finalize
    nop
    .2byte  0xFFFF
.L_activation_store:
    .4byte  sym_0608962C
.L_lod_factor_table:
    .4byte  sym_06089E08
.L_lod_standard:
    .4byte  0x00014CCC
.L_lod_store:
    .4byte  sym_06089744
.L_lod_medium_factor:
    .4byte  0x00030000
.L_lod_close:
    mov.l   .L_lod_close_factor, r5
    jsr @r9
    nop
    mov r14, r4
    mov.w   DAT_060224b6, r2
    shll2 r4
    add r2, r0
    mov r4, r5
    mov.l r0, @(8, r15)
    add r13, r5
    mov.l   .L_lod_store_b, r3
    mov.l   .L_fp_two, r2
    add r4, r3
    mov.l r2, @r3
    mov r4, r3
    mov.l @r5, r5
    mov r5, r0
    cmp/eq #0x3, r0
    bt/s    .L_lod_close_type_check
    add r10, r3
    mov r5, r0
    cmp/eq #0x4, r0
    bf      .L_lod_close_other
.L_lod_close_type_check:
    bra     .L_lod_close_set
    mov #0xE, r2
.L_lod_close_other:
    mov #0x16, r2
.L_lod_close_set:
    mov.l r2, @r3
.L_type0_finalize:
    mov.l @(4, r15), r4
    mov.w   .L_sound_stride, r3
    mov r4, r0
    mov.l @(8, r0), r0
    mov.l @(40, r4), r4
    and #0x1, r0
    mul.l r3, r0
    mov r14, r0
    sts macl, r3
    shll2 r0
    add r3, r4
    mov.l @(r0, r13), r5
    mov.w   .L_sound_offset, r3
    mov r5, r0
    add r3, r4
    cmp/eq #0x3, r0
    bt      .L_sound_type34
    mov r5, r0
    cmp/eq #0x4, r0
    bf      .L_sound_not_34
.L_sound_type34:
    mov r14, r3
    shll2 r3
    mov.l   .L_lod_store_b, r2
    add r2, r3
    mov.l   .L_fp_one_point_five, r1
    mov.l r1, @r3
.L_sound_not_34:
    exts.w r14, r3
    exts.w r11, r0
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l r3, @r15
    mov.w r0, @(20, r3)
    mov.l @r15, r3
    mov.l @(4, r15), r2
    mov.l @(40, r2), r2
    exts.w r2, r0
    mov.w r0, @(22, r3)
    mov.l @r15, r6
    mov.l @r15, r5
    mov.l   .L_fn_sincos, r3
    add #0x10, r6
    jsr @r3
    add #0xC, r5
    mov.l @r15, r2
    mov #0xC, r3
    add r2, r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    mov.l @(12, r5), r5
    jsr @r9
    mov.l @(12, r15), r4
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @r15, r3
    mov #0x10, r2
    add r3, r2
    mov.l r2, @-r15
    mov.l @(4, r15), r5
    mov.l @(16, r5), r5
    jsr @r9
    mov.l @(12, r15), r4
    mov.l @r15+, r3
    mov.l r0, @r3
    mov r14, r0
    shll2 r0
    mov.l @(r0, r13), r3
    tst r3, r3
    bf      .L_sound_nonzero
    mov.l   .L_snd_type0, r5
    mov.l   .L_fn_sound_cmd, r3
    jsr @r3
    mov #0x0, r4
    bra     .L_post_sound
    nop

    .global DAT_060224b6
DAT_060224b6:
    .2byte  0x2000
.L_sound_stride:
    .2byte  0x0380
.L_sound_offset:
    .2byte  0xFE40
.L_lod_close_factor:
    .4byte  0x00013333
.L_lod_store_b:
    .4byte  sym_06089744
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_fp_one_point_five:
    .4byte  0x00018000
.L_fn_sincos:
    .4byte  sincos_pair
.L_snd_type0:
    .4byte  0xAE110BFF
.L_fn_sound_cmd:
    .4byte  sound_cmd_dispatch
.L_sound_nonzero:
    mov.l   .L_snd_type_other, r5
    mov.l   .L_fn_sound_cmd_b, r3
    jsr @r3
    mov #0x0, r4
.L_post_sound:
    mov r14, r0
    mov #0x28, r2
    shll2 r0
    mov.l @(r0, r10), r3
    cmp/hs r2, r3
    bf      .L_active_entity
    bra     .L_mature_entity
    nop
.L_active_entity:
    mov r14, r0
    shll2 r0
    mov.l @(r0, r13), r4
    mov r4, r0
    cmp/eq #0x3, r0
    bt      .L_active_type34
    mov r4, r0
    cmp/eq #0x4, r0
    bf      .L_active_other
.L_active_type34:
    mov.l @(16, r15), r3
    mov.l r3, @r15
    bra     .L_active_render_setup
    nop
.L_active_other:
    mov.l   .L_offset_default, r3
    mov.l r3, @r15
.L_active_render_setup:
    exts.w r14, r4
    mov r15, r6
    mov r4, r3
    add #0xC, r6
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r12, r4
    mov.l @(12, r4), r2
    mov.l @r4, r3
    sub r2, r3
    mov.l r3, @r4
    mov.l @(16, r4), r2
    mov.l @(8, r4), r3
    add r2, r3
    mov.l r3, @(8, r4)
    mov.l @r4, r2
    mov.l r2, @(24, r15)
    mov.l @(8, r4), r3
    mov.l r3, @(32, r15)
    mov.l r8, @(28, r15)
    mov.l r6, @-r15
    mov r15, r5
    add #0x1C, r5
    mov.l r5, @-r15
    mov.l @(40, r15), r5
    mov.l   .L_fn_heading_calc_b, r3
    jsr @r3
    mov.l @(32, r15), r4
    mov r0, r4
    mov.l @r15+, r5
    mov.l   .L_fn_scene_render_b, r3
    jsr @r3
    mov.l @r15+, r6
    mov.w @(12, r15), r0
    mov #0x34, r3
    mov.l   .L_validation_table_b, r2
    mov r0, r4
    extu.w r4, r4
    mul.l r3, r4
    mov.l @(28, r15), r3
    sts macl, r4
    cmp/eq r8, r3
    bt/s    .L_active_cull
    add r2, r4
    mov.l @r4, r0
    tst #0x80, r0
    bt      .L_active_visible
.L_active_cull:
    exts.w r14, r3
    mov r3, r2
    shll2 r3
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l   .L_cull_marker_b, r1
    mov.l r1, @r3
    mov r14, r4
    shll2 r4
    mov r4, r3
    add r10, r3
    mov.l r11, @r3
    bra     .L_entity_deactivate
    nop
.L_snd_type_other:
    .4byte  0xAE110DFF
.L_fn_sound_cmd_b:
    .4byte  sound_cmd_dispatch
.L_offset_default:
    .4byte  sym_06089B18
.L_fn_heading_calc_b:
    .4byte  sym_06006838
.L_fn_scene_render_b:
    .4byte  scene_render_alt
.L_validation_table_b:
    .4byte  sym_060A6000
.L_cull_marker_b:
    .4byte  0x4E200000
.L_active_visible:
    mov r14, r0
    shll2 r0
    mov.l r0, @(8, r15)
    mov.l @(r0, r10), r5
    mov.l @r15, r3
    mov.l @(8, r15), r4
    shll2 r5
    shll r5
    add r3, r5
    mov.l @r5, r5
    mov.l   .L_lod_store_c, r3
    add r3, r4
    jsr @r9
    mov.l @r4, r4
    mov.l @(28, r15), r3
    add r0, r3
    mov.l r3, @(28, r15)
    mov.w   .L_vis_offset_base, r3
    mov.l @(28, r15), r2
    add r3, r2
    mov.l r2, @(28, r15)
    mov.l @(8, r15), r0
    mov.l @(r0, r13), r0
    cmp/eq #0x3, r0
    bf      .L_vis_not_3
    mov.l   .L_type3_bonus_b, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
.L_vis_not_3:
    mov r14, r0
    shll2 r0
    mov.l @(r0, r13), r0
    cmp/eq #0x4, r0
    bf      .L_vis_not_4
    mov.l   .L_type4_bonus_b, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
.L_vis_not_4:
    exts.w r14, r4
    mov r14, r5
    mov.l @r15, r1
    mov r4, r3
    shll2 r5
    shll2 r4
    shll2 r3
    add r10, r5
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    mov.l @r5, r3
    add r12, r4
    shll2 r3
    mov.w @(20, r4), r0
    shll r3
    mov r0, r2
    add r1, r3
    mov.w @(4, r3), r0
    mov r0, r3
    add r3, r2
    exts.w r2, r0
    mov.w r0, @(20, r4)
    mov.w @(22, r4), r0
    mov.l @r5, r2
    mov r0, r3
    shll2 r2
    shll r2
    mov.l @r15, r1
    add r1, r2
    mov.w @(6, r2), r0
    mov r0, r2
    add r2, r3
    exts.w r3, r0
    mov.w r0, @(22, r4)
    mov.l @r5, r3
    add #0x1, r3
    mov.l r3, @r5
    bra     .L_entity_transform_jmp
    nop
.L_vis_offset_base:
    .2byte  0x0100
.L_lod_store_c:
    .4byte  sym_06089744
.L_type3_bonus_b:
    .4byte  0x00013333
.L_type4_bonus_b:
    .4byte  0x0000CCCC
.L_mature_entity:
    exts.w r14, r4
    mov r15, r6
    mov r4, r3
    add #0xC, r6
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r12, r4
    mov.l @r4, r2
    mov.l r2, @(24, r15)
    mov.l @(8, r4), r3
    mov.l r3, @(32, r15)
    mov.l r8, @(28, r15)
    mov.l r6, @-r15
    mov r15, r5
    add #0x1C, r5
    mov.l r5, @-r15
    mov.l @(40, r15), r5
    mov.l   .L_fn_heading_calc_c, r3
    jsr @r3
    mov.l @(32, r15), r4
    mov r0, r4
    mov.l @r15+, r5
    mov.l   .L_fn_scene_render_c, r3
    jsr @r3
    mov.l @r15+, r6
    mov #0x34, r3
    mov.l   .L_validation_table_c, r2
    mov.w @(12, r15), r0
    mov r0, r4
    extu.w r4, r4
    mul.l r3, r4
    mov.l @(28, r15), r3
    sts macl, r4
    cmp/eq r8, r3
    bt/s    .L_mature_cull
    add r2, r4
    mov.l @r4, r0
    tst #0x80, r0
    bt      .L_mature_visible
.L_mature_cull:
    exts.w r14, r3
    mov r3, r2
    shll2 r3
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l   .L_cull_marker_c, r1
    mov.l r1, @r3
    mov r14, r4
    shll2 r4
    mov r4, r3
    add r10, r3
    mov.l r11, @r3
.L_entity_deactivate:
    mov.l   .L_deactivation_store, r2
    add r2, r4
    bra     .L_entity_next
    mov.l r11, @r4
.L_mature_visible:
    mov r14, r0
    mov.w   .L_mature_offset_base, r2
    mov.l @(28, r15), r3
    shll2 r0
    add r2, r3
    mov.l r3, @(28, r15)
    mov.l @(r0, r13), r0
    cmp/eq #0x3, r0
    bf      .L_mature_not_3
    mov.l   .L_type3_bonus_c, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
.L_mature_not_3:
    mov r14, r0
    shll2 r0
    mov.l @(r0, r13), r0
    cmp/eq #0x4, r0
    bf      .L_mature_not_4
    mov.l   .L_type4_bonus_c, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
.L_mature_not_4:
    mov r14, r4
    shll2 r4
    mov r4, r3
    add r10, r3
    mov.l r11, @r3
    mov.l   .L_deactivation_store, r2
    add r2, r4
    mov.l r11, @r4
.L_entity_transform_jmp:
    bra     .L_do_transform
    nop
.L_mature_offset_base:
    .2byte  0x0100
.L_fn_heading_calc_c:
    .4byte  sym_06006838
.L_fn_scene_render_c:
    .4byte  scene_render_alt
.L_validation_table_c:
    .4byte  sym_060A6000
.L_cull_marker_c:
    .4byte  0x4E200000
.L_deactivation_store:
    .4byte  sym_0608962C
.L_type3_bonus_c:
    .4byte  0x00013333
.L_type4_bonus_c:
    .4byte  0x0000CCCC
.L_activation_dispatch:
    cmp/eq #0x0, r0
    bf      .L_act_not_0
    bra     .L_type0_setup
    nop
.L_act_not_0:
    cmp/eq #0x1, r0
    bf      .L_do_transform
    bra     .L_post_sound
    nop
.L_do_transform:
    mov.l   .L_fn_mat_identity, r3
    jsr @r3
    nop
    mov.l @(32, r15), r6
    mov.l @(28, r15), r5
    mov.l   .L_fn_mat_setup, r3
    jsr @r3
    mov.l @(24, r15), r4
    exts.w r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r12, r4
    mov.l r4, @r15
    mov.w @(22, r4), r0
    mov.l   .L_fn_mat_rot_y, r3
    jsr @r3
    mov r0, r4
    mov.l @r15, r4
    mov.l   .L_fn_transform, r3
    mov.w @(20, r4), r0
    jsr @r3
    mov r0, r4
    mov r14, r5
    shll2 r5
    add r13, r5
    mov.l r5, @r15
    mov.l @r5, r5
    shll2 r5
    mov.l r5, @(8, r15)
    mov.l   .L_transform_tbl_a, r3
    mov.l   .L_transform_tbl_b, r4
    mov.l   .L_fn_matrix_a, r2
    add r3, r5
    mov.l @r5, r5
    mov.l @(8, r15), r3
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov.l @r15, r3
    mov.l @r3, r3
    shll2 r3
    mov.l r3, @(8, r15)
    mov.l   .L_transform_tbl_c, r2
    add r2, r3
    mov.l @r3, r1
    mov.l r1, @r15
    mov.l   .L_transform_tbl_d, r6
    mov.l @(8, r15), r3
    mov.l @(20, r15), r5
    mov.l   .L_fn_matrix_b, r2
    add r3, r6
    mov.w @r5, r5
    mov.l @r6, r6
    jsr @r2
    mov r1, r4
    mov.l   .L_fn_entity_cleanup, r3
    jsr @r3
    nop
.L_entity_next:
    add #0x1, r14
.L_loop_check:
    mov.l   .L_entity_limit, r2
    mov.l @r2, r2
    cmp/hs r2, r14
    bt      .L_loop_done
    bra     .L_entity_loop
    nop
.L_loop_done:
    add #0x24, r15
    lds.l @r15+, macl
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
.L_fn_mat_identity:
    .4byte  sym_06026DBC
.L_fn_mat_setup:
    .4byte  sym_06026E2E
.L_fn_mat_rot_y:
    .4byte  mat_rot_y
.L_fn_transform:
    .4byte  mat_rot_x
.L_transform_tbl_a:
    .4byte  sym_06089DB4
.L_transform_tbl_b:
    .4byte  sym_06089D98
.L_fn_matrix_a:
    .4byte  sym_06031D8C
.L_transform_tbl_c:
    .4byte  sym_06089DD0
.L_transform_tbl_d:
    .4byte  sym_06089DEC
.L_fn_matrix_b:
    .4byte  sym_06031A28
.L_fn_entity_cleanup:
    .4byte  sym_06026DF8
.L_entity_limit:
    .4byte  sym_06089E24
