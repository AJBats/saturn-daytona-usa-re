
    .section .text.FUN_0600B6A0


    .global render_cs0_loop
    .type render_cs0_loop, @function
render_cs0_loop:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x44, r15
    mov.l   .L_render_budget_ptr, r8
    mov.l   .L_sprite_index_table, r11
    mov.l   .L_distance_check_fn, r12
    mov.l   .L_render_submit_fn, r13
    mov.l   .L_render_disabled_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_render_enabled
    bra     .L_epilogue
    nop
    .4byte  sym_06031DF4                    /* (unreferenced pool: render submit B) */
    .4byte  sym_0608A52C                    /* (unreferenced pool: render budget B) */
.L_render_budget_ptr:
    .4byte  sym_06089EDC
.L_sprite_index_table:
    .4byte  sym_06089E44
.L_distance_check_fn:
    .4byte  sym_06031D8C
.L_render_submit_fn:
    .4byte  sym_06031A28
.L_render_disabled_flag:
    .4byte  sym_0607EAE0
.L_render_enabled:
    mov #0x1, r10
    mov.l   .L_car3_data_base, r5
    mov r5, r3
    add #0x28, r3
    mov.l r3, @(16, r15)
    mov.l   .L_car1_data_base, r6
    mov r6, r2
    add #0x28, r2
    mov.l r2, @(8, r15)
    mov.l   .L_car2_data_base, r4
    mov r4, r3
    add #0x28, r3
    mov.l r3, @(4, r15)
    mov r11, r2
    add #0x4, r2
    mov.l r2, @r15
    mov.l   .L_car0_data_base, r7
    mov r7, r3
    add #0x28, r3
    mov.l r3, @(12, r15)
    mov r5, r2
    add #0x2C, r2
    mov.l r2, @(36, r15)
    mov r6, r1
    add #0x2C, r1
    mov.l r1, @(40, r15)
    mov r4, r3
    add #0x2C, r3
    mov.l r3, @(44, r15)
    mov r7, r2
    add #0x2C, r2
    mov.l r2, @(48, r15)
    mov r5, r1
    add #0x30, r1
    mov.l r1, @(52, r15)
    mov r6, r3
    add #0x30, r3
    mov.l r3, @(56, r15)
    mov r4, r2
    add #0x30, r2
    mov.l r2, @(60, r15)
    mov r7, r1
    add #0x30, r1
    mov #0x40, r0
    mov.l r1, @(r0, r15)
    add #0x18, r5
    mov.l r5, @(20, r15)
    add #0x18, r6
    mov.l r6, @(24, r15)
    add #0x18, r4
    mov.l r4, @(28, r15)
    add #0x18, r7
    bra     .L_loop_check
    mov.l r7, @(32, r15)
.L_car3_data_base:
    .4byte  sym_060621D8
.L_car1_data_base:
    .4byte  sym_0606212C
.L_car2_data_base:
    .4byte  sym_06062180
.L_car0_data_base:
    .4byte  sym_060620D8
.L_loop_body:
    mov.w   .L_obj_stride, r14
    mov.l   .L_obj_table_base, r3
    mov.l   .L_visibility_mask, r1
    mul.l r14, r10
    sts macl, r14
    add r3, r14
    mov.l @r14, r2
    and r1, r2
    tst r2, r2
    bf      .L_obj_visible
    bra     .L_next_object
    nop
.L_obj_visible:
    mov.l   .L_mat_push_fn, r3
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.w   DAT_0600b83a, r0
    mov.l   .L_mat_xform_trans_fn, r3
    mov.l @(r0, r14), r2
    add r2, r5
    jsr @r3
    mov.l @(16, r14), r4
    mov.l @(32, r14), r4
    mov.l   .L_fp_half, r2
    mov.l   .L_mat_rot_y_fn, r3
    jsr @r3
    add r2, r4
    mov.l @(36, r14), r4
    mov.l   .L_mat_rot_z_fn, r3
    jsr @r3
    neg r4, r4
    mov.l @(28, r14), r4
    mov.l   .L_mat_rot_x_fn, r3
    jsr @r3
    neg r4, r4
    mov.w   DAT_0600b83c, r0
    mov.l @(r0, r14), r2
    mov.w   .L_off_collision_b, r0
    mov.l @(r0, r14), r3
    add r3, r2
    tst r2, r2
    bt      .L_check_detail_flags
    mov.w   DAT_0600b840, r0
    mov.l @(r0, r14), r4
    add #-0xC, r0
    neg r4, r4
    mov.l @(r0, r14), r3
    sub r3, r4
    mov.l   .L_mat_rot_y_fn, r3
    jsr @r3
    nop
    mov.w   .L_off_rot_alt_y, r0
    mov.l   .L_mat_rot_z_fn, r3
    mov.l @(r0, r14), r4
    jsr @r3
    neg r4, r4
    mov.w   .L_off_rot_alt_z, r0
    mov.l   .L_mat_rot_x_fn, r3
    mov.l @(r0, r14), r4
    jsr @r3
    neg r4, r4
.L_check_detail_flags:
    mov.l   .L_lod_selector_table, r9
    mov r14, r0
    add r10, r9
    mov.b @(1, r0), r0
    mov.b @r9, r9
    tst #0x40, r0
    bf/s    .L_detail_close
    extu.b r9, r9
    mov.l   .L_state_flag_a, r0
    mov.l   .L_state_flag_b, r3
    mov.l @r0, r0
    mov.l @r3, r3
    add r3, r0
    cmp/eq #0x8, r0
    bf      .L_check_medium_detail
.L_detail_close:
    mov.w   DAT_0600b83c, r0
    mov.l @(r0, r14), r3
    cmp/pl r3
    bt      .L_close_secondary
    mov.l @(16, r15), r5
    mov.l @(8, r15), r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l @(4, r15), r6
    mov.l @r15, r5
    mov.l @(12, r15), r4
    mov.l @r6, r6
    mov.w @r5, r5
    jsr @r13
    mov.l @r4, r4
.L_close_secondary:
    mov.l @(36, r15), r5
    mov.l @(40, r15), r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l @(44, r15), r6
    mov r9, r0
    mov.l @(48, r15), r4
    mov.l @r6, r6
    shll r0
    mov.w @(r0, r11), r5
    jsr @r13
    mov.l @r4, r4
    bra     .L_decrement_budget
    nop
.L_obj_stride:
    .2byte  0x0268

    .global DAT_0600b83a
DAT_0600b83a:
    .2byte  0x01B4

    .global DAT_0600b83c
DAT_0600b83c:
    .2byte  0x01BC
.L_off_collision_b:
    .2byte  0x00B8

    .global DAT_0600b840
DAT_0600b840:
    .2byte  0x01D8
.L_off_rot_alt_y:
    .2byte  0x01D0
.L_off_rot_alt_z:
    .2byte  0x01C8
    .2byte  0xFFFF
.L_obj_table_base:
    .4byte  sym_06078900
.L_visibility_mask:
    .4byte  0x00E00000
.L_mat_push_fn:
    .4byte  sym_06026DBC
.L_mat_xform_trans_fn:
    .4byte  sym_06026E2E
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_mat_rot_y_fn:
    .4byte  mat_rot_y
.L_mat_rot_z_fn:
    .4byte  mat_rot_z
.L_mat_rot_x_fn:
    .4byte  mat_rot_x
.L_lod_selector_table:
    .4byte  sym_06047FC4
.L_state_flag_a:
    .4byte  sym_06063E1C
.L_state_flag_b:
    .4byte  sym_06063E20
.L_check_medium_detail:
    mov r14, r0
    mov.b @(1, r0), r0
    tst #0x20, r0
    bt      .L_check_far_detail
    mov.l @(52, r15), r5
    mov.l @(56, r15), r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l @(60, r15), r6
    mov r9, r0
    mov.l @r6, r6
    shll r0
    mov.w @(r0, r11), r5
    mov #0x40, r0
    mov.l @(r0, r15), r4
    jsr @r13
    mov.l @r4, r4
    bra     .L_decrement_budget
    nop
.L_check_far_detail:
    mov r14, r0
    mov.b @(1, r0), r0
    tst #0x80, r0
    bt      .L_decrement_budget
    mov.w   DAT_0600b90e, r0
    mov.l @(r0, r14), r3
    cmp/pl r3
    bt      .L_far_render_pass
    mov.l @(16, r15), r5
    mov.l @(8, r15), r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l @(4, r15), r6
    mov.l @r15, r5
    mov.l @(12, r15), r4
    mov.l @r6, r6
    mov.w @r5, r5
    jsr @r13
    mov.l @r4, r4
.L_far_render_pass:
    mov #0x1, r5
    .byte   0xB8, 0xE7    /* bsr 0x0600AA98 (external) — scene_obj_type_A renderer */
    mov r14, r4
    mov.l @(20, r15), r5
    mov.l @(24, r15), r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l @(28, r15), r6
    mov r9, r0
    mov.l @(32, r15), r4
    mov.l @r6, r6
    shll r0
    mov.w @(r0, r11), r5
    jsr @r13
    mov.l @r4, r4
.L_decrement_budget:
    mov.l @r8, r3
    add #-0x30, r3
    mov.l r3, @r8
.L_next_object:
    add #0x1, r10
.L_loop_check:
    mov.l   .L_obj_count_ptr, r2
    mov.w @r2, r2
    cmp/hs r2, r10
    bt      .L_epilogue
    bra     .L_loop_body
    nop
.L_epilogue:
    add #0x44, r15
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

    .global DAT_0600b90e
DAT_0600b90e:
    .2byte  0x01BC
.L_obj_count_ptr:
    .4byte  sym_06078664
