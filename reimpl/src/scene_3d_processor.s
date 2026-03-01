
    .section .text.FUN_06027CA4


    .global scene_3d_processor
    .type scene_3d_processor, @function
scene_3d_processor:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l r5, @-r15
    mov.l @r4, r1
    mov.l   _pool_z_bias, r2
    add r2, r1
    shlr16 r1
    shlr2 r1
    shlr2 r1
    shlr r1
    mov.l @(8, r4), r2
    mov.l   _pool_z_range_mask, r3
    sub r2, r3
    shlr16 r3
    shlr2 r3
    shlr2 r3
    shlr r3
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r1
    mov.l   _pool_camera_mode_ptr, r2
    mov.l @r2, r0
    cmp/eq #0x2, r0
    bf      .L_06027D40
    mov.l r1, @-r15
    mov r1, r10
    mov.l   _pool_visibility_list, r1
    xor r12, r12
.L_06027CEA:
    mov.w @r1+, r0
    tst r0, r0
    bt      .L_06027D34
    cmp/eq r0, r10
    bt      .L_06027D08
    bra     .L_06027CEA
    add #0x2, r12
_pool_z_bias:
    .4byte  0x04000000
_pool_z_range_mask:
    .4byte  0x03FFFFFF
_pool_camera_mode_ptr:
    .4byte  sym_0607EAD8
_pool_visibility_list:
    .4byte  sym_06061270
.L_06027D08:
    mov.l   _pool_car_ptr, r1
    mov.l @r1, r1
    mov.w   DAT_06027d26, r0
    mov.l @(r0, r1), r1
    mov #0x46, r0
    cmp/gt r0, r1
    bt      .L_06027D34
    shll r12
    mov.l   _pool_model_overrides, r0
    add r12, r0
    mov.l   _pool_render_queue_ctrl, r1
    mov.w @r0+, r2
    mov.w @r0, r12
    bra     .L_06027D36
    mov.w r2, @r1

    .global DAT_06027d26
DAT_06027d26:
    .2byte  0x01EC
_pool_car_ptr:
    .4byte  sym_0607E940
_pool_model_overrides:
    .4byte  sym_06061240
_pool_render_queue_ctrl:
    .4byte  sym_06063F50
.L_06027D34:
    xor r12, r12
.L_06027D36:
    mov.l @r15+, r1
    tst r12, r12
    bt      .L_06027D40
    bra     .L_06027D50
    mov r2, r13
.L_06027D40:
    mov r1, r2
    shll2 r2
    mov.l   _pool_scene_node_table, r0
    add r0, r2
    mov.w @r2, r13
    extu.w r13, r13
    mov.w @(2, r2), r0
    mov r0, r12
.L_06027D50:
    cmp/pl r12
    bt      .L_06027D60
    mov #0x0, r0
    mov r0, r3
    bra     .L_06027E6A
    mov #0x0, r6
_pool_scene_node_table:
    .4byte  sym_060C2000
.L_06027D60:
    mov.l   _pool_texture_index_table, r0
    mov.w @(r0, r13), r5
    mov #0x34, r6
    mov.l   _pool_polygon_data_pool, r0
    muls.w r6, r5
    sts macl, r5
    add r5, r0
    mov.l @r0, r6
    add #0x10, r0
    mov #0x1, r14
    mov.l @r0+, r7
    shll16 r14
    mov.l @r4, r2
    shll8 r14
    dmuls.l r7, r2
    mov.l @r0+, r9
    mov.l @(8, r4), r10
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    tst r14, r6
    add r9, r3
    bf      .L_06027D90
    add r10, r3
.L_06027D90:
    mov.w   _wpool_plane_a_mask, r11
    tst r11, r6
    bt      .L_06027DAC
    cmp/pl r3
    bf      .L_06027DB6
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
_wpool_plane_a_mask:
    .2byte  0x0100
    .2byte  0x0000
_pool_texture_index_table:
    .4byte  sym_060BF000
_pool_polygon_data_pool:
    .4byte  sym_060A6000
.L_06027DAC:
    cmp/pz r3
    bt      .L_06027DB6
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_06027DB6:
    mov r4, r1
    mov.l @r0+, r7
    mov.l @r1, r2
    shll r14
    dmuls.l r7, r2
    mov.l @r0+, r9
    mov.l @(8, r4), r10
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    tst r14, r6
    add r9, r3
    bf      .L_06027DD2
    add r10, r3
.L_06027DD2:
    mov.w   _wpool_plane_b_mask, r11
    tst r11, r6
    bt      .L_06027DE4
    cmp/pl r3
    bf      .L_06027DEE
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
_wpool_plane_b_mask:
    .2byte  0x0200
.L_06027DE4:
    cmp/pz r3
    bt      .L_06027DEE
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_06027DEE:
    mov.l @r0+, r7
    mov.l @r4, r2
    shll r14
    dmuls.l r7, r2
    mov.l @r0+, r9
    mov.l @(8, r4), r10
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    tst r14, r6
    add r9, r3
    bf      .L_06027E08
    add r10, r3
.L_06027E08:
    mov.w   _wpool_plane_c_mask, r10
    tst r10, r6
    bt      .L_06027E1A
    cmp/pl r3
    bf      .L_06027E24
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
_wpool_plane_c_mask:
    .2byte  0x0400
.L_06027E1A:
    cmp/pz r3
    bt      .L_06027E24
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_06027E24:
    mov.l @r0+, r7
    mov.l @r4, r2
    shll r14
    dmuls.l r7, r2
    mov.l @r0+, r9
    mov.l @(8, r4), r10
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    tst r14, r6
    add r9, r3
    bf      .L_06027E3E
    add r10, r3
.L_06027E3E:
    mov.l   _pool_plane_d_mask, r10
    tst r10, r6
    bt      .L_06027E54
    cmp/pl r3
    bf      .L_06027E5E
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
    .2byte  0x0000
_pool_plane_d_mask:
    .4byte  0x00000800
.L_06027E54:
    cmp/pz r3
    bt      .L_06027E5E
    add #0x2, r13
    bra     .L_06027D50
    add #-0x1, r12
.L_06027E5E:
    mov.l   _pool_poly_data_base, r1
    add r5, r1
    mov.l @r1, r3
    mov.w   DAT_06027e98, r6
    and r6, r3
    mov r3, r0
.L_06027E6A:
    mov.w r0, @(12, r4)
    mov #0x0, r0
    cmp/eq r0, r6
    bt      .L_06027EA8
    add #0x30, r1
    mov.w @r1, r0
    mov.l r0, @(16, r4)
    mov r0, r8
    mov r5, r1
    mov #0x34, r0
    mov.l   _pool_hw_divide, r12
    jsr @r12
    mov.l r3, @-r15
    mov.l @r15+, r3
    mov.w r0, @(14, r4)
    mov.l   _pool_car_ptr_b, r6
    mov.l @r6, r0
    mov.l @r15+, r5
    cmp/pl r5
    bt      .L_06027EAE
    mov.w   DAT_06027e9a, r1
    bra     .L_06027EAE
    mov.l r8, @(r0, r1)

    .global DAT_06027e98
DAT_06027e98:
    .2byte  0x00FF

    .global DAT_06027e9a
DAT_06027e9a:
    .2byte  0x025C
_pool_poly_data_base:
    .4byte  sym_060A6000
_pool_hw_divide:
    .4byte  sym_0602ECCC
_pool_car_ptr_b:
    .4byte  sym_0607E940
.L_06027EA8:
    mov.l   _pool_car_ptr_c, r6
    mov.l @r6, r0
    mov.l @r15+, r5
.L_06027EAE:
    shll r5
    mov.l   _pool_output_offset_table, r2
    add r5, r2
    mov.w @r2, r2
    extu.w r2, r2
    mov.l r3, @(r0, r2)
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
_pool_car_ptr_c:
    .4byte  sym_0607E940
_pool_output_offset_table:
    .4byte  sym_0606128A
    .4byte  0x00093600
    .4byte  0x89FCAFD5
    .2byte  0x0009
