
    .section .text.FUN_0600A76C


    .global secondary_geom_proc
    .type secondary_geom_proc, @function
secondary_geom_proc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_render_budget_ptr, r12
    mov.l   .L_fp_half, r13
    mov.l   .L_config_ptr, r14
    mov.l @r14, r14
    mov.b @(1, r14), r0
    mov r0, r3
    tst r3, r3
    bt      .L_skip_obj_a
    mov.l   .L_fn_scene_matrix_init, r3
    jsr @r3
    nop
    mov.l   .L_position_vec_a, r11
    mov.l   .L_pos_offset_z_a, r2
    mov.w   .L_off_adj_yz, r3
    mov.l @(8, r11), r6
    mov.l @(4, r11), r5
    mov.l @r11, r4
    add r2, r6
    add r3, r5
    mov.w   DAT_0600a856, r2
    mov.l   .L_fn_position_transform, r3
    jsr @r3
    add r2, r4
    mov r13, r6
    mov r13, r5
    mov.l   .L_fn_scale, r3
    jsr @r3
    mov r13, r4
    mov.b @r14, r5
    add #0xE, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_dist_check_src_tbl, r3
    mov.l @r15, r4
    mov.l   .L_dist_check_param_tbl, r2
    mov.l   .L_fn_dist_check, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r14, r6
    add #0xE, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_render_src_tbl, r3
    mov.l   .L_disp_mode_word, r5
    mov.l @r15, r4
    mov.l   .L_render_param_tbl, r2
    mov.l   .L_fn_render_submit, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.l @r12, r3
    add #-0x30, r3
    mov.l r3, @r12
.L_skip_obj_a:
    mov.b @(4, r14), r0
    mov r0, r2
    tst r2, r2
    bt      .L_epilogue
    mov.l   .L_fn_scene_matrix_init, r3
    jsr @r3
    nop
    mov.l   .L_position_vec_b, r11
    mov.l   .L_pos_offset_z_b, r3
    mov.w   .L_off_adj_yz, r2
    mov.l @(8, r11), r6
    mov.l @(4, r11), r5
    neg r6, r6
    add r2, r5
    add r3, r6
    mov.l   .L_fn_position_transform, r3
    jsr @r3
    mov.l @r11, r4
    mov r13, r6
    mov r13, r5
    mov.l   .L_fn_scale, r3
    jsr @r3
    mov r13, r4
    mov.b @(3, r14), r0
    mov r0, r5
    add #0xE, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_dist_check_src_tbl, r3
    mov.l @r15, r4
    mov.l   .L_dist_check_param_tbl, r2
    mov.l   .L_fn_dist_check, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @(3, r14), r0
    mov r0, r6
    add #0xE, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_render_src_tbl, r3
    add r3, r6
    mov.l @r6, r6
    mov.l   .L_disp_mode_word, r5
    mov.w @r5, r5
    extu.w r5, r5
    bra     .L_submit_render_b
    nop
.L_off_adj_yz:
    .2byte  0xCCCD                      /* Y axis position adjustment (signed: -0x3333) */

    .global DAT_0600a856
DAT_0600a856:
    .2byte  0x8000                      /* X axis position adjustment (signed: -0x8000) */
.L_render_budget_ptr:
    .4byte  sym_0608A52C                /* render budget counter B */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_config_ptr:
    .4byte  sym_0607EB8C                /* config struct pointer (indirect) */
.L_fn_scene_matrix_init:
    .4byte  sym_06027080                /* Type B: scene matrix setup */
.L_position_vec_a:
    .4byte  sym_06044640                /* object A position vector (XYZ triplet) */
.L_pos_offset_z_a:
    .4byte  0xFFFF0F5D                  /* object A Z offset (signed: -0xF0A3) */
.L_fn_position_transform:
    .4byte  sym_060270F2                /* Type B: set position transform */
.L_fn_scale:
    .4byte  mat_scale_b                 /* Type B: matrix scale function */
.L_dist_check_src_tbl:
    .4byte  sym_060621D8                /* distance check source table */
.L_dist_check_param_tbl:
    .4byte  sym_0606212C                /* distance check parameter table */
.L_fn_dist_check:
    .4byte  sym_06032158                /* Type B: distance check function */
.L_render_src_tbl:
    .4byte  sym_06062180                /* render submit source table */
.L_disp_mode_word:
    .4byte  sym_06089E9C                /* display mode selector (16-bit) */
.L_render_param_tbl:
    .4byte  sym_060620D8                /* render submit parameter table */
.L_fn_render_submit:
    .4byte  sym_06031DF4                /* Type B: render submit function */
.L_position_vec_b:
    .4byte  sym_06044670                /* object B position vector (XYZ triplet) */
.L_pos_offset_z_b:
    .4byte  0xFFFDB334                  /* object B Z offset (signed: -0x24CCC) */
.L_submit_render_b:
    mov.l @r15, r4
    mov.l   .L_render_param_tbl_2, r2
    mov.l   .L_fn_render_submit_2, r1
    add r2, r4
    jsr @r1
    mov.l @r4, r4
    mov.l @r12, r3
    add #-0x30, r3
    mov.l r3, @r12
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0600A8BC
sym_0600A8BC:
    mov.l   .L_phase_counter_ptr, r4
    mov.l   .L_car_state_ptr, r5
    mov.l @r5, r5
    mov.l @(12, r5), r0
    tst r0, r0
    bt      .L_phase_reset
    mov #0x64, r2
    mov.l @(8, r5), r3
    cmp/ge r2, r3
    bt      .L_speed_ge_100
    mov.w @r4, r2
    add #0x1, r2
    bra     .L_phase_store
    mov.w r2, @r4
.L_speed_ge_100:
    mov.l @(8, r5), r2
    mov.w   .L_speed_threshold_200, r3
    cmp/ge r3, r2
    bt      .L_speed_ge_200
    mov.w @r4, r3
    add #0x2, r3
    mov.w r3, @r4
    bra     .L_phase_store
    nop
.L_speed_ge_200:
    mov.w @r4, r2
    add #0x4, r2
    mov.w r2, @r4
.L_phase_store:
    mov.w @r4, r0
    and #0xF, r0
    bra     .L_phase_exit
    mov.w r0, @r4
.L_phase_reset:
    mov #0x0, r2
    mov.w r2, @r4
.L_phase_exit:
    rts
    nop
.L_speed_threshold_200:
    .2byte  0x00C8                      /* 200 (speed threshold for +4 increment) */
    .2byte  0xFFFF                      /* padding */
.L_render_param_tbl_2:
    .4byte  sym_060620D8                /* render param table (dup for pool reach) */
.L_fn_render_submit_2:
    .4byte  sym_06031DF4                /* render submit fn (dup for pool reach) */
.L_phase_counter_ptr:
    .4byte  sym_06063F46                /* audio phase counter (16-bit word) */
.L_car_state_ptr:
    .4byte  sym_0607E940                /* current car state pointer (indirect) */
