
    .section .text.FUN_0601250C


    .global hud_lap_gfx_update
    .type hud_lap_gfx_update, @function
hud_lap_gfx_update:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_pre_transform, r3
    jsr @r3
    nop
    mov.l   .L_fn_matrix_init, r3
    jsr @r3
    nop
    mov.l   .L_position_vec, r14
    mov.l   .L_fn_transform_dispatch, r3
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    jsr @r3
    mov.l @r14, r4
    mov.l   .L_rot_angle_z, r4
    mov.l   .L_fn_rot_z, r3
    jsr @r3
    mov.w @r4, r4
    mov.l   .L_fn_rot_y, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_fn_transform_mat, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_speed_counter, r2
    mov #0x64, r3
    mov.l @r2, r2
    cmp/ge r3, r2
    bf      .L_skip_extra_transform
    mov.w   DAT_06012586, r4
    mov.l   .L_fn_transform_mat, r3
    jsr @r3
    nop
.L_skip_extra_transform:
    mov.l   .L_chain_a_src, r5
    mov.l   .L_obj_counter, r4
    mov.l   .L_chain_a_table, r3
    mov.l   .L_fn_chain_a, r2
    mov.l @r5, r5
    mov.l @r4, r4
    add #-0x1, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov.l   .L_chain_b_src, r6
    mov.l   .L_disp_mode, r5
    mov.l   .L_obj_counter, r4
    mov.l   .L_chain_b_table, r3
    mov.l   .L_fn_chain_b, r2
    mov.l @r6, r6
    mov.w @r5, r5
    mov.l @r4, r4
    add #-0x1, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l   .L_fn_post_cleanup, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_06012586
DAT_06012586:
    .2byte  0x1000
.L_fn_pre_transform:
    .4byte  sym_06026DBC
.L_fn_matrix_init:
    .4byte  sym_06026E0C
.L_position_vec:
    .4byte  sym_060788B4
.L_fn_transform_dispatch:
    .4byte  sym_06026E2E
.L_rot_angle_z:
    .4byte  sym_060788B2
.L_fn_rot_z:
    .4byte  mat_rot_z
.L_fn_rot_y:
    .4byte  mat_rot_y
.L_fn_transform_mat:
    .4byte  mat_rot_x
.L_speed_counter:
    .4byte  sym_0607EBCC
.L_chain_a_src:
    .4byte  sym_06063558
.L_obj_counter:
    .4byte  sym_0607EAD8
.L_chain_a_table:
    .4byte  sym_0606354C
.L_fn_chain_a:
    .4byte  sym_06031D8C
.L_chain_b_src:
    .4byte  sym_06063554
.L_disp_mode:
    .4byte  sym_06089EA0
.L_chain_b_table:
    .4byte  sym_06063544
.L_fn_chain_b:
    .4byte  sym_06031A28
.L_fn_post_cleanup:
    .4byte  sym_06026DF8
