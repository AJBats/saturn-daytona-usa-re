
    .section .text.FUN_06010D94


    .global vdp_mode_select
    .type vdp_mode_select, @function
vdp_mode_select:
    mov.l r14, @-r15
    mov #0xA, r2
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l r4, @(8, r15)
    mov.l r5, @(4, r15)
    mov.l r6, @r15
    mov.l r7, @(12, r15)
    mov.l   .L_game_state_counter, r3
    mov.l @r3, r3
    cmp/hs r2, r3
    bf      .L_do_transform
    bra     .L_epilogue
    nop
.L_game_state_counter:
    .4byte  sym_060788A0
.L_do_transform:
    mov.l   .L_render_budget_ptr, r14
    mov.l   .L_fn_camera_push, r3
    mov.l @r14, r2
    add #0x30, r2
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_fn_pos_transform, r8
    mov.l @(12, r15), r6
    mov.l @r15, r5
    jsr @r8
    mov.l @(4, r15), r4
    mov.l   .L_rotation_angle, r4
    mov.l   .L_fn_mat_rot_y, r3
    jsr @r3
    mov.w @r4, r4
    mov.l   .L_chain_a_param_tbl, r13
    mov.l   .L_chain_a_src_tbl, r5
    mov.l   .L_fn_chain_a, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r13, r4
    mov.l   .L_chain_b_param_tbl, r9
    mov.l   .L_fn_chain_b, r11
    mov.l   .L_chain_b_src_tbl, r12
    mov.l @(8, r15), r10
    mov.l   .L_disp_index_table, r3
    mov.l @r12, r6
    shll r10
    add r3, r10
    mov.w @r10, r5
    jsr @r11
    mov.l @r9, r4
    mov.l   .L_fn_camera_init, r3
    jsr @r3
    nop
    mov.l   .L_ch1_pos_z, r6
    mov.l   .L_ch1_pos_y, r5
    mov.l   .L_ch1_pos_x, r4
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r8
    mov.l @r4, r4
    mov.l   .L_chain_a_src_ch2, r5
    mov.l   .L_fn_chain_a, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(4, r13), r4
    mov.l @(4, r12), r6
    mov.w @r10, r5
    jsr @r11
    mov.l @(4, r9), r4
    mov.l @r14, r2
    mov.l   .L_fn_camera_init, r3
    add #-0x30, r2
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_ch2_pos_z, r6
    mov.l   .L_ch2_pos_y, r5
    mov.l   .L_ch2_pos_x, r4
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r8
    mov.l @r4, r4
    mov.l   .L_chain_a_src_ch3, r5
    mov.l   .L_fn_chain_a, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(8, r13), r4
    mov.l @(8, r12), r6
    mov.w @r10, r5
    jsr @r11
    mov.l @(8, r9), r4
    mov.l @r14, r2
    mov.l   .L_fn_camera_init, r3
    add #-0x30, r2
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_ch3_pos_z, r6
    mov.l   .L_ch3_pos_y, r5
    mov.l   .L_ch3_pos_x, r4
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r8
    mov.l @r4, r4
    mov.l   .L_chain_a_src_ch4, r5
    mov.l   .L_fn_chain_a, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(12, r13), r4
    mov.l @(12, r12), r6
    mov.w @r10, r5
    jsr @r11
    mov.l @(12, r9), r4
    mov.l @r14, r2
    add #-0x30, r2
    mov r2, r3
    add #-0x30, r3
    mov.l r3, @r14
.L_epilogue:
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
.L_render_budget_ptr:
    .4byte  sym_06089EDC
.L_fn_camera_push:
    .4byte  sym_06026E0C
.L_fn_pos_transform:
    .4byte  sym_06026E2E
.L_rotation_angle:
    .4byte  sym_06078878
.L_fn_mat_rot_y:
    .4byte  mat_rot_y
.L_chain_a_param_tbl:
    .4byte  sym_0606212C
.L_chain_a_src_tbl:
    .4byte  sym_060621D8
.L_fn_chain_a:
    .4byte  sym_06031D8C
.L_chain_b_param_tbl:
    .4byte  sym_060620D8
.L_fn_chain_b:
    .4byte  sym_06031A28
.L_chain_b_src_tbl:
    .4byte  sym_06062180
.L_disp_index_table:
    .4byte  sym_06089E44
.L_fn_camera_init:
    .4byte  sym_06026DBC
.L_ch1_pos_z:
    .4byte  sym_06044648
.L_ch1_pos_y:
    .4byte  sym_06044644
.L_ch1_pos_x:
    .4byte  sym_06044640
.L_chain_a_src_ch2:
    .4byte  sym_060621DC
.L_ch2_pos_z:
    .4byte  sym_06044654
.L_ch2_pos_y:
    .4byte  sym_06044650
.L_ch2_pos_x:
    .4byte  sym_0604464C
.L_chain_a_src_ch3:
    .4byte  sym_060621E0
.L_ch3_pos_z:
    .4byte  sym_06044678
.L_ch3_pos_y:
    .4byte  sym_06044674
.L_ch3_pos_x:
    .4byte  sym_06044670
.L_chain_a_src_ch4:
    .4byte  sym_060621E4
