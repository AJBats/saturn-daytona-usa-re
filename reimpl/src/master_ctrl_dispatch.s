
    .section .text.FUN_0601C3E4


    .global master_ctrl_dispatch
    .type master_ctrl_dispatch, @function
master_ctrl_dispatch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_disp_elem_index, r8
    mov.l   .L_fp_half, r9
    mov.l   .L_cmd_buf_base, r10
    mov.l   .L_idx_byte_b, r11
    mov.l   .L_idx_byte_a, r12
    mov.l   .L_ctrl_state_ptr, r14
    mov.l   .L_game_flag_a, r0
    mov.l @r0, r0
    tst r0, r0
    bt/s    .L_issue_all_cmds
    mov.l @r14, r14
    mov.l   .L_game_flag_b, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_check_bit_flags
.L_issue_all_cmds:
    mov r13, r0
    mov.w   .L_cmd_id_1901_a, r1
    mov.l   .L_fn_disp_cmd_issue, r3
    jsr @r3
    mov r14, r2
    mov r13, r0
    mov.w   .L_cmd_id_1801_a, r1
    mov.l   .L_fn_disp_cmd_issue, r3
    jsr @r3
    mov r14, r2
    mov r13, r0
    mov.w   .L_cmd_id_1701_a, r1
    mov.l   .L_fn_disp_cmd_issue, r3
    jsr @r3
    mov r14, r2
    mov r13, r0
    mov.w   .L_cmd_id_1601_a, r1
    mov.l   .L_fn_disp_cmd_issue, r3
    jsr @r3
    mov r14, r2
    bra     .L_epilogue
    nop
.L_cmd_id_1901_a:
    .2byte  0x1901
.L_cmd_id_1801_a:
    .2byte  0x1801
.L_cmd_id_1701_a:
    .2byte  0x1701
.L_cmd_id_1601_a:
    .2byte  0x1601
    .2byte  0xFFFF
.L_disp_elem_index:
    .4byte  sym_0605DF44
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_cmd_buf_base:
    .4byte  sym_0608A52C
.L_idx_byte_b:
    .4byte  sym_0605DF57
.L_idx_byte_a:
    .4byte  sym_0605DF56
.L_ctrl_state_ptr:
    .4byte  sym_0607E944
.L_game_flag_a:
    .4byte  sym_06063E1C
.L_game_flag_b:
    .4byte  sym_06063E20
.L_fn_disp_cmd_issue:
    .4byte  sym_06034F78
.L_check_bit_flags:
    mov r14, r0
    mov.b @(3, r0), r0
    tst #0x40, r0
    bt      .L_check_bit_80
    mov #0x8, r3
    mov.l   .L_timer_ch_a, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_cmd_id_1901_b, r1
    mov.l   .L_fn_disp_cmd_issue_b, r3
    jsr @r3
    mov r14, r2
.L_check_bit_80:
    mov r14, r0
    mov.b @(3, r0), r0
    tst #0x80, r0
    bt      .L_check_bit_01
    mov #0x8, r3
    mov.l   .L_timer_ch_b, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_cmd_id_1801_b, r1
    mov.l   .L_fn_disp_cmd_issue_b, r3
    jsr @r3
    mov r14, r2
.L_check_bit_01:
    mov r14, r0
    mov.b @(2, r0), r0
    tst #0x1, r0
    bt      .L_check_bit_02
    mov #0x8, r3
    mov.l   .L_timer_ch_c, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_cmd_id_1701_b, r1
    mov.l   .L_fn_disp_cmd_issue_b, r3
    jsr @r3
    mov r14, r2
.L_check_bit_02:
    mov r14, r0
    mov.b @(2, r0), r0
    tst #0x2, r0
    bt      .L_check_timer_ch_a
    mov #0x8, r3
    mov.l   .L_timer_ch_d, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_cmd_id_1601_b, r1
    mov.l   .L_fn_disp_cmd_issue_b, r3
    jsr @r3
    mov r14, r2
.L_check_timer_ch_a:
    mov.l   .L_timer_ch_a, r2
    mov.w @r2, r2
    extu.w r2, r2
    cmp/pl r2
    bf      .L_check_timer_ch_b
    mov.l   .L_fn_render_setup, r3
    jsr @r3
    nop
    mov.l   .L_game_flag_a_2, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_ch_a_neg_position
    mov.l   .L_game_flag_b_2, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_ch_a_neg_position
    mov.l   .L_scale_neg_ch_a, r6
    mov.l   .L_pos_param_ch_a, r4
    mov.l   .L_fn_position_set, r3
    jsr @r3
    mov r9, r5
    mov.w   DAT_0601c510, r6
    mov.l   .L_fn_mat_scale, r3
    mov r6, r5
    jsr @r3
    mov r6, r4
    bra     .L_ch_a_render_common
    nop
.L_cmd_id_1901_b:
    .2byte  0x1901
.L_cmd_id_1801_b:
    .2byte  0x1801
.L_cmd_id_1701_b:
    .2byte  0x1701
.L_cmd_id_1601_b:
    .2byte  0x1601

    .global DAT_0601c510
DAT_0601c510:
    .2byte  0x6666
    .2byte  0xFFFF
.L_timer_ch_a:
    .4byte  sym_0605DF4E
.L_fn_disp_cmd_issue_b:
    .4byte  sym_06034F78
.L_timer_ch_b:
    .4byte  sym_0605DF50
.L_timer_ch_c:
    .4byte  sym_0605DF52
.L_timer_ch_d:
    .4byte  sym_0605DF54
.L_fn_render_setup:
    .4byte  sym_06027080
.L_game_flag_a_2:
    .4byte  sym_06063E1C
.L_game_flag_b_2:
    .4byte  sym_06063E20
.L_scale_neg_ch_a:
    .4byte  0xFFFE4000                  /* -1.75 (16.16 fixed-point) */
.L_pos_param_ch_a:
    .4byte  0x00014872                  /* 1.28 (16.16 fixed-point) */
.L_fn_position_set:
    .4byte  sym_060270F2
.L_fn_mat_scale:
    .4byte  mat_scale_b
.L_ch_a_neg_position:
    mov.l   .L_fp_neg_one, r6
    mov.l   .L_pos_param_ch_a_alt, r4
    mov.l   .L_fn_position_set_2, r3
    jsr @r3
    mov r9, r5
.L_ch_a_render_common:
    mov.w   DAT_0601c5f8, r4
    mov.l   .L_fn_mat_rot_xy, r3
    jsr @r3
    nop
    mov.b @r12, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_render_z_tbl, r3
    mov.l @r15, r4
    mov.l   .L_render_x_tbl, r2
    mov.l   .L_fn_render_params_a, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r12, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_render_y_tbl, r3
    mov.l   .L_scale_factor_tbl, r5
    mov.l @r15, r4
    mov.l   .L_render_w_tbl, r2
    mov.l   .L_fn_render_params_b, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.l @r10, r3
    add #-0x30, r3
    mov.l r3, @r10
    mov.b @r12, r2
    add #0x1, r2
    mov.b r2, @r12
    mov.b @r12, r3
    mov #0x3, r2
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_ch_a_dec_timer
    extu.b r13, r2
    mov.b r2, @r12
.L_ch_a_dec_timer:
    mov.l   .L_timer_ch_a_dec, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_timer_ch_a_dec, r2
    mov.w r3, @r2
    bra     .L_check_active_display
    nop
.L_check_timer_ch_b:
    mov.l   .L_timer_ch_b_chk, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/pl r3
    bt      .L_process_ch_b
    bra     .L_check_timer_ch_c
    nop
.L_process_ch_b:
    mov.l   .L_fn_render_setup_2, r3
    jsr @r3
    nop
    mov.l   .L_game_flag_a_3, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_ch_b_neg_position
    mov.l   .L_game_flag_b_3, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_ch_b_neg_position
    mov.l   .L_scale_neg_ch_b, r6
    mov.l   .L_pos_param_ch_b, r4
    mov.l   .L_fn_position_set_2, r3
    jsr @r3
    mov r9, r5
    mov.w   DAT_0601c5fa, r6
    mov.l   .L_fn_mat_scale_2, r3
    mov r6, r5
    jsr @r3
    mov r6, r4
    bra     .L_ch_b_render_common
    nop

    .global DAT_0601c5f8
DAT_0601c5f8:
    .2byte  0x1000

    .global DAT_0601c5fa
DAT_0601c5fa:
    .2byte  0x6666
.L_fp_neg_one:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_pos_param_ch_a_alt:
    .4byte  0x00014872                  /* 1.28 (16.16 fixed-point) */
.L_fn_position_set_2:
    .4byte  sym_060270F2
.L_fn_mat_rot_xy:
    .4byte  mat_rot_xy_b
.L_render_z_tbl:
    .4byte  sym_060621D8
.L_render_x_tbl:
    .4byte  sym_0606212C
.L_fn_render_params_a:
    .4byte  sym_06032158
.L_render_y_tbl:
    .4byte  sym_06062180
.L_scale_factor_tbl:
    .4byte  sym_06089E9C
.L_render_w_tbl:
    .4byte  sym_060620D8
.L_fn_render_params_b:
    .4byte  sym_06031DF4
.L_timer_ch_a_dec:
    .4byte  sym_0605DF4E
.L_timer_ch_b_chk:
    .4byte  sym_0605DF50
.L_fn_render_setup_2:
    .4byte  sym_06027080
.L_game_flag_a_3:
    .4byte  sym_06063E1C
.L_game_flag_b_3:
    .4byte  sym_06063E20
.L_scale_neg_ch_b:
    .4byte  0xFFFE4000                  /* -1.75 (16.16 fixed-point) */
.L_pos_param_ch_b:
    .4byte  0xFFFEB78E                  /* -1.28 (16.16 fixed-point) */
.L_fn_mat_scale_2:
    .4byte  mat_scale_b
.L_ch_b_neg_position:
    mov.l   .L_fp_neg_one_ch_b, r6
    mov.l   .L_pos_param_ch_b_alt, r4
    mov.l   .L_fn_position_set_3, r3
    jsr @r3
    mov r9, r5
.L_ch_b_render_common:
    mov.w   DAT_0601c6c0, r4
    mov.l   .L_fn_mat_rot_xy_2, r3
    jsr @r3
    nop
    mov.b @r11, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_render_z_tbl_2, r3
    mov.l @r15, r4
    mov.l   .L_render_x_tbl_2, r2
    mov.l   .L_fn_render_params_a_2, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r11, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_render_y_tbl_2, r3
    mov.l   .L_scale_factor_tbl_2, r5
    mov.l @r15, r4
    mov.l   .L_render_w_tbl_2, r2
    mov.l   .L_fn_render_params_b_2, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.l @r10, r3
    add #-0x30, r3
    mov.l r3, @r10
    mov.b @r11, r2
    add #0x1, r2
    mov.b r2, @r11
    mov.b @r11, r3
    mov #0x3, r2
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_ch_b_dec_timer
    extu.b r13, r2
    mov.b r2, @r11
.L_ch_b_dec_timer:
    mov.l   .L_timer_ch_b_dec, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_timer_ch_b_dec, r2
    mov.w r3, @r2
    bra     .L_check_active_display
    nop

    .global DAT_0601c6c0
DAT_0601c6c0:
    .2byte  0x7000
    .2byte  0xFFFF
.L_fp_neg_one_ch_b:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_pos_param_ch_b_alt:
    .4byte  0xFFFEB78E                  /* -1.28 (16.16 fixed-point) */
.L_fn_position_set_3:
    .4byte  sym_060270F2
.L_fn_mat_rot_xy_2:
    .4byte  mat_rot_xy_b
.L_render_z_tbl_2:
    .4byte  sym_060621D8
.L_render_x_tbl_2:
    .4byte  sym_0606212C
.L_fn_render_params_a_2:
    .4byte  sym_06032158
.L_render_y_tbl_2:
    .4byte  sym_06062180
.L_scale_factor_tbl_2:
    .4byte  sym_06089E9C
.L_render_w_tbl_2:
    .4byte  sym_060620D8
.L_fn_render_params_b_2:
    .4byte  sym_06031DF4
.L_timer_ch_b_dec:
    .4byte  sym_0605DF50
.L_check_timer_ch_c:
    mov.l   .L_timer_ch_c_val, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/pl r3
    bf      .L_check_timer_ch_d
    mov.l   .L_fn_render_setup_3, r3
    jsr @r3
    nop
    mov.l   .L_scale_ch_c, r6
    mov.l   .L_pos_param_ch_c, r4
    mov.l   .L_fn_position_set_4, r3
    jsr @r3
    mov r9, r5
    mov.w   DAT_0601c77c, r4
    mov.l   .L_fn_mat_rot_xy_3, r3
    jsr @r3
    nop
    mov.b @r12, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_render_z_tbl_3, r3
    mov.l @r15, r4
    mov.l   .L_render_x_tbl_3, r2
    mov.l   .L_fn_render_params_a_3, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r12, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_render_y_tbl_3, r3
    mov.l   .L_scale_factor_tbl_3, r5
    mov.l @r15, r4
    mov.l   .L_render_w_tbl_3, r2
    mov.l   .L_fn_render_params_b_3, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.l @r10, r3
    add #-0x30, r3
    mov.l r3, @r10
    mov.b @r12, r2
    add #0x1, r2
    mov.b r2, @r12
    mov #0x3, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_ch_c_dec_timer
    extu.b r13, r2
    mov.b r2, @r12
.L_ch_c_dec_timer:
    mov.l   .L_timer_ch_c_val, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_timer_ch_c_val, r2
    mov.w r3, @r2
    bra     .L_check_active_display
    nop

    .global DAT_0601c77c
DAT_0601c77c:
    .2byte  0x1000
    .2byte  0xFFFF
.L_timer_ch_c_val:
    .4byte  sym_0605DF52
.L_fn_render_setup_3:
    .4byte  sym_06027080
.L_scale_ch_c:
    .4byte  0x00013333                  /* 1.2 (16.16 fixed-point) */
.L_pos_param_ch_c:
    .4byte  0x0001620C                  /* 1.38 (16.16 fixed-point) */
.L_fn_position_set_4:
    .4byte  sym_060270F2
.L_fn_mat_rot_xy_3:
    .4byte  mat_rot_xy_b
.L_render_z_tbl_3:
    .4byte  sym_060621D8
.L_render_x_tbl_3:
    .4byte  sym_0606212C
.L_fn_render_params_a_3:
    .4byte  sym_06032158
.L_render_y_tbl_3:
    .4byte  sym_06062180
.L_scale_factor_tbl_3:
    .4byte  sym_06089E9C
.L_render_w_tbl_3:
    .4byte  sym_060620D8
.L_fn_render_params_b_3:
    .4byte  sym_06031DF4
.L_check_timer_ch_d:
    mov.l   .L_timer_ch_d_val, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/pl r3
    bf      .L_check_active_display
    mov.l   .L_fn_render_setup_4, r3
    jsr @r3
    nop
    mov.l   .L_scale_ch_d, r6
    mov.l   .L_pos_param_ch_d, r4
    mov.l   .L_fn_position_set_5, r3
    jsr @r3
    mov r9, r5
    mov.w   DAT_0601c844, r4
    mov.l   .L_fn_mat_rot_xy_4, r3
    jsr @r3
    nop
    mov.b @r11, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_render_z_tbl_4, r3
    mov.l @r15, r4
    mov.l   .L_render_x_tbl_4, r2
    mov.l   .L_fn_render_params_a_4, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r11, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_render_y_tbl_4, r3
    mov.l   .L_scale_factor_tbl_4, r5
    mov.l @r15, r4
    mov.l   .L_render_w_tbl_4, r2
    mov.l   .L_fn_render_params_b_4, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.l @r10, r3
    add #-0x30, r3
    mov.l r3, @r10
    mov.b @r11, r2
    add #0x1, r2
    mov.b r2, @r11
    mov #0x3, r2
    mov.b @r11, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_ch_d_dec_timer
    extu.b r13, r2
    mov.b r2, @r11
.L_ch_d_dec_timer:
    mov.l   .L_timer_ch_d_val, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_timer_ch_d_val, r2
    mov.w r3, @r2
.L_check_active_display:
    mov.l   .L_active_display_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_check_anim_state
    bra     .L_epilogue
    nop

    .global DAT_0601c844
DAT_0601c844:
    .2byte  0x7000
    .2byte  0xFFFF
.L_timer_ch_d_val:
    .4byte  sym_0605DF54
.L_fn_render_setup_4:
    .4byte  sym_06027080
.L_scale_ch_d:
    .4byte  0x00013333                  /* 1.2 (16.16 fixed-point) */
.L_pos_param_ch_d:
    .4byte  0xFFFE9DF4                  /* -1.38 (16.16 fixed-point) */
.L_fn_position_set_5:
    .4byte  sym_060270F2
.L_fn_mat_rot_xy_4:
    .4byte  mat_rot_xy_b
.L_render_z_tbl_4:
    .4byte  sym_060621D8
.L_render_x_tbl_4:
    .4byte  sym_0606212C
.L_fn_render_params_a_4:
    .4byte  sym_06032158
.L_render_y_tbl_4:
    .4byte  sym_06062180
.L_scale_factor_tbl_4:
    .4byte  sym_06089E9C
.L_render_w_tbl_4:
    .4byte  sym_060620D8
.L_fn_render_params_b_4:
    .4byte  sym_06031DF4
.L_active_display_flag:
    .4byte  sym_06059F30
.L_check_anim_state:
    mov.w   DAT_0601c93c, r0
    mov.w @(r0, r14), r3
    tst r3, r3
    bf      .L_recheck_anim_fields
    mov.w   DAT_0601c93e, r0
    mov.w @(r0, r14), r3
    tst r3, r3
    bf      .L_recheck_anim_fields
    exts.w r13, r3
    mov.w r3, @r8
.L_recheck_anim_fields:
    mov.w   DAT_0601c93c, r0
    mov.w @(r0, r14), r0
    tst r0, r0
    bf      .L_anim_render_dispatch
    mov.w   DAT_0601c93e, r0
    mov.w @(r0, r14), r0
    tst r0, r0
    bt      .L_epilogue
.L_anim_render_dispatch:
    mov.l   .L_fn_render_setup_5, r3
    jsr @r3
    nop
    mov.l   .L_camera_state_ptr, r14
    mov.l   .L_z_offset_neg, r3
    mov.w   .L_y_offset_neg, r2
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    neg r6, r6
    add r2, r5
    add r3, r6
    mov.l   .L_fn_position_set_6, r3
    jsr @r3
    mov.l @r14, r4
    mov.l   .L_fn_mat_rot_xy_5, r3
    jsr @r3
    mov r9, r4
    mov.w @r8, r5
    mov.l   .L_elem_lookup_tbl, r3
    shll r5
    add r3, r5
    mov.w @r5, r5
    add #0xE, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_render_z_tbl_5, r2
    mov.l @r15, r4
    mov.l   .L_render_x_tbl_5, r1
    mov.l   .L_fn_render_params_a_5, r3
    add r2, r5
    add r1, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.w @r8, r6
    mov.l   .L_elem_lookup_tbl, r3
    shll r6
    add r3, r6
    mov.w @r6, r6
    add #0xE, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_render_y_tbl_5, r2
    mov.l   .L_scale_factor_tbl_5, r5
    mov.l @r15, r4
    mov.l   .L_render_w_tbl_5, r1
    mov.l   .L_fn_render_params_b_5, r3
    add r2, r6
    mov.w @r5, r5
    add r1, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l @r10, r2
    add #-0x30, r2
    mov.l r2, @r10
    mov.w @r8, r3
    add #0x1, r3
    mov.w r3, @r8
    mov.w @r8, r2
    mov #0x4, r3
    cmp/ge r3, r2
    bf      .L_epilogue
    exts.w r13, r3
    mov.w r3, @r8
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601c93c
DAT_0601c93c:
    .2byte  0x0166

    .global DAT_0601c93e
DAT_0601c93e:
    .2byte  0x0152
.L_y_offset_neg:
    .2byte  0xCCCD                      /* -0x3333 signed = -13107 */
    .2byte  0xFFFF
.L_fn_render_setup_5:
    .4byte  sym_06027080
.L_camera_state_ptr:
    .4byte  sym_06044670
.L_z_offset_neg:
    .4byte  0xFFFF6000                  /* -0.625 (16.16 fixed-point) */
.L_fn_position_set_6:
    .4byte  sym_060270F2
.L_fn_mat_rot_xy_5:
    .4byte  mat_rot_xy_b
.L_elem_lookup_tbl:
    .4byte  sym_0605DF46
.L_render_z_tbl_5:
    .4byte  sym_060621D8
.L_render_x_tbl_5:
    .4byte  sym_0606212C
.L_fn_render_params_a_5:
    .4byte  sym_06032158
.L_render_y_tbl_5:
    .4byte  sym_06062180
.L_scale_factor_tbl_5:
    .4byte  sym_06089E9C
.L_render_w_tbl_5:
    .4byte  sym_060620D8
.L_fn_render_params_b_5:
    .4byte  sym_06031DF4
