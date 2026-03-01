
    .section .text.FUN_06006868


    .global scene_post_render
    .type scene_post_render, @function
scene_post_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x2C, r15
    mov.l   _pool_player_mode_ptr, r14
    mov.l   _pool_car_state_ptr, r4
    mov.l   _pool_scene_depth_param, r2
    mov.l @r4, r4
    mov.l @(20, r4), r3
    mov.l r3, @r2
    mov.l   _pool_dispatch_table_a, r4
    mov.l @r14, r0
    shll2 r0
    shll r0
    mov.l @(r0, r4), r3
    mov.l r3, @(4, r15)
    mov.l @r14, r0
    shll r0
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r4), r2
    mov.l r2, @(8, r15)
    mov.l   _pool_dispatch_table_b, r4
    mov.l @r14, r0
    shll2 r0
    shll2 r0
    mov.l @(r0, r4), r1
    mov.l r1, @(16, r15)
    mov.l @r14, r5
    shll2 r5
    mov r5, r0
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r4), r3
    mov r5, r0
    mov.l r3, @(28, r15)
    add #0x2, r0
    shll2 r0
    mov.l @(r0, r4), r2
    mov r5, r0
    mov.l r2, @(24, r15)
    add #0x3, r0
    shll2 r0
    mov.l @(r0, r4), r1
    mov.l r1, @(20, r15)
    mov.l   _pool_cam_orient_data, r5
    mov.l   _pool_column_rounding, r3
    mov.l @r5, r4
    add r3, r4
    shlr16 r4
    shlr2 r4
    shlr2 r4
    shlr r4
    mov.l @(8, r5), r2
    neg r2, r2
    add #-0x1, r3
    add r3, r2
    mov r2, r5
    shlr16 r5
    mov #0x40, r3
    shlr2 r5
    shlr2 r5
    shlr r5
    mov r5, r2
    mov r5, r0
    shll2 r2
    shll2 r2
    shll2 r2
    add r4, r2
    mov.l r2, @(32, r15)
    mov.l r3, @(36, r15)
    mov #-0x1, r3
    mov.l r3, @(40, r15)
    mov #0x1, r3
    mov.l r3, @(12, r15)
    cmp/eq #0x3F, r0
    bf/s    .L_check_end_col_zero
    mov #-0x40, r6
    mov #0x0, r2
    bra     .L_check_start_col
    mov.l r2, @(36, r15)
.L_check_end_col_zero:
    tst r5, r5
    bf      .L_check_start_col
    mov #0x0, r6
.L_check_start_col:
    mov r4, r0
    cmp/eq #0x3F, r0
    bf      .L_check_start_zero
    mov #0x0, r2
    bra     .L_load_render_param
    mov.l r2, @(12, r15)
    .2byte  0xFFFF
_pool_player_mode_ptr:
    .4byte  sym_0607EAD8
_pool_car_state_ptr:
    .4byte  sym_0607E944
_pool_scene_depth_param:
    .4byte  sym_06063F54
_pool_dispatch_table_a:
    .4byte  sym_06062248
_pool_dispatch_table_b:
    .4byte  sym_06062260
_pool_cam_orient_data:
    .4byte  sym_06063DF8
_pool_column_rounding:
    .4byte  0x04000000
.L_check_start_zero:
    tst r4, r4
    bf      .L_load_render_param
    mov #0x0, r3
    mov.l r3, @(40, r15)
.L_load_render_param:
    mov.l   _pool_render_param_ptr, r10
    bra     .L_outer_loop_test
    mov.l r6, @r15
.L_outer_loop_body:
    mov.l @(40, r15), r12
    mov.l @r15, r9
    mov.l @(32, r15), r3
    mov.l @(12, r15), r2
    add r12, r9
    cmp/gt r2, r12
    bt/s    .L_advance_outer
    add r3, r9
.L_inner_loop_body:
    mov r9, r11
    mov r9, r4
    mov.l @(16, r15), r7
    mov.l @(24, r15), r3
    shll r4
    add r4, r7
    add r3, r4
    mov.w @r7, r7
    exts.w r7, r2
    cmp/pl r2
    bf/s    .L_check_pass_b
    mov.w @r4, r13
    mov r11, r0
    mov.l @(28, r15), r2
    mov.l @r14, r8
    mov.l   _pool_pipeline_state, r3
    shll2 r0
    shll2 r8
    mov.l @(r0, r2), r0
    shll r8
    add r3, r8
    mov.l @r8, r8
    add r0, r8
    mov.l @r14, r0
    cmp/eq #0x2, r0
    bt      .L_pass_a_mode_2
    mov.w @r10, r6
    mov.l @(4, r15), r5
    mov.l   _pool_fn_vtx_xform_a, r3
    jsr @r3
    mov r8, r4
    bra     .L_check_pass_b
    nop
.L_pass_a_mode_2:
    mov.w @r10, r6
    mov.l @(4, r15), r5
    mov.l   _pool_fn_face_proj_a, r3
    jsr @r3
    mov r8, r4
.L_check_pass_b:
    exts.w r13, r2
    cmp/pl r2
    bf      .L_next_inner
    mov r11, r0
    mov.l @(20, r15), r1
    mov.l @r14, r2
    mov.l   _pool_pipeline_state, r3
    shll2 r0
    shll r2
    add #0x1, r2
    shll2 r2
    add r3, r2
    mov.l @r2, r11
    mov.l @(r0, r1), r2
    mov.l @r14, r0
    cmp/eq #0x2, r0
    bt/s    .L_pass_b_mode_2
    add r2, r11
    mov r13, r7
    mov.w @r10, r6
    mov.l @(8, r15), r5
    mov.l   _pool_fn_vtx_xform_b, r3
    jsr @r3
    mov r11, r4
    bra     .L_next_inner
    nop
    .2byte  0xFFFF
_pool_render_param_ptr:
    .4byte  sym_06089E96
_pool_pipeline_state:
    .4byte  sym_06062230
_pool_fn_vtx_xform_a:
    .4byte  sym_06029BF4
_pool_fn_face_proj_a:
    .4byte  sym_0602B328
_pool_fn_vtx_xform_b:
    .4byte  sym_0602A834
.L_pass_b_mode_2:
    mov r13, r7
    mov.w @r10, r6
    mov.l @(8, r15), r5
    mov.l   _pool_fn_frustum_cull_b, r3
    jsr @r3
    mov r11, r4
.L_next_inner:
    add #0x1, r12
    mov.l @(12, r15), r2
    cmp/gt r2, r12
    bf/s    .L_inner_loop_body
    add #0x1, r9
.L_advance_outer:
    mov.l @r15, r2
    add #0x40, r2
    mov.l r2, @r15
.L_outer_loop_test:
    mov.l @r15, r3
    mov.l @(36, r15), r2
    cmp/gt r2, r3
    bf      .L_outer_loop_body
    mov.l   _pool_game_state_flags, r2
    mov.l   _pool_state_check_mask, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bf      .L_epilogue_rts
    bra     .L_mode_dispatch
    mov.l @r14, r0
.L_mode_0_dispatch:
    mov.l   _pool_fn_track_geom, r3
    jsr @r3
    nop
    bra     .L_epilogue_tailcall
    nop
.L_mode_1_dispatch:
    mov.l   _pool_fn_track_state, r3
    jsr @r3
    nop
    bra     .L_epilogue_tailcall
    nop
.L_mode_2_dispatch:
    mov.l   _pool_fn_geom_math, r3
    jsr @r3
    nop
    bra     .L_epilogue_tailcall
    nop
.L_mode_dispatch:
    cmp/eq #0x0, r0
    bt      .L_mode_0_dispatch
    cmp/eq #0x1, r0
    bt      .L_mode_1_dispatch
    cmp/eq #0x2, r0
    bt      .L_mode_2_dispatch
.L_epilogue_tailcall:
    add #0x2C, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   _pool_fn_scene_entity, r3
    jmp @r3
    mov.l @r15+, r14
.L_epilogue_rts:
    add #0x2C, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
_pool_fn_frustum_cull_b:
    .4byte  sym_0602AF3C
_pool_game_state_flags:
    .4byte  sym_0607EBC4
_pool_state_check_mask:
    .4byte  0x30000000
_pool_fn_track_geom:
    .4byte  track_geometry_proc
_pool_fn_track_state:
    .4byte  track_state_machine
_pool_fn_geom_math:
    .4byte  geom_math_calc
_pool_fn_scene_entity:
    .4byte  scene_process_stage
