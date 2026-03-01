
    .section .text.FUN_06010F04


    .global race_position_track
    .type race_position_track, @function
race_position_track:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_channel_index_ptr, r3
    mov.l @r3, r3
    mov.l r3, @r15
    mov.l   .L_fn_position_init, r3
    jsr @r3
    nop
    mov #0xA, r3
    mov.l   .L_position_count, r2
    mov.l @r2, r2
    cmp/hs r3, r2
    bf      .L_06010F3C
    bra     .L_06011002
    nop
.L_channel_index_ptr:
    .4byte  sym_0607884C               /* channel index pointer */
.L_fn_position_init:
    .4byte  sym_0603C000               /* position display initialization */
.L_position_count:
    .4byte  sym_060788A4               /* active position display count */
.L_06010F3C:
    mov.l   .L_fn_fpdiv, r12
    mov.l   .L_pos_z_array, r6
    mov.l   .L_pos_y_array, r5
    mov.l   .L_pos_x_array, r4
    mov.l @r6, r6
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l   .L_rot_angle, r4
    mov.l   .L_fn_rot_xy, r3
    jsr @r3
    mov.w @r4, r4
    mov.l   .L_mat_dst_array, r9
    mov.l   .L_mat_src_array, r10
    mov.l   .L_fn_vec_transform, r11
    mov.l @r10, r5
    jsr @r11
    mov.l @r9, r4
    mov.l   .L_fn_vec_scale, r8
    mov.l   .L_rot_data_array, r6
    mov.l @r15, r13
    mov.l   .L_scale_factor, r3
    mov.l   .L_output_vec_array, r4
    mov.l @r6, r6
    shll r13
    add r3, r13
    mov.w @r13, r5
    extu.w r5, r5
    jsr @r8
    mov.l @r4, r4
    mov.l   .L_fn_fpmul, r3
    jsr @r3
    nop
    mov.l   .L_channel_params_1, r14
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    neg r6, r6
    jsr @r12
    mov.l @r14, r4
    mov.l @(4, r10), r5
    jsr @r11
    mov.l @(4, r9), r4
    mov.l   .L_rot_data_1, r6
    mov.w @r13, r5
    mov.l   .L_output_vec_1, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r8
    mov.l @r4, r4
    mov.l   .L_pos_counter, r14
    mov.l   .L_fn_fpmul, r3
    mov.l @r14, r2
    add #-0x30, r2
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_channel_params_2_z, r6
    mov.l   .L_channel_params_2_y, r5
    mov.l   .L_channel_params_2_x, r4
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r12
    mov.l @r4, r4
    mov.l @(8, r10), r5
    jsr @r11
    mov.l @(8, r9), r4
    mov.l   .L_rot_data_2, r6
    mov.w @r13, r5
    mov.l   .L_output_vec_2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r8
    mov.l @r4, r4
    mov.l @r14, r2
    mov.l   .L_fn_fpmul, r3
    add #-0x30, r2
    jsr @r3
    mov.l r2, @r14
    mov.l   .L_channel_params_3_z, r6
    mov.l   .L_channel_params_3_y, r5
    mov.l   .L_channel_params_3_x, r4
    mov.l @r6, r6
    mov.l @r5, r5
    neg r6, r6
    jsr @r12
    mov.l @r4, r4
    mov.l @(12, r10), r5
    jsr @r11
    mov.l @(12, r9), r4
    mov.l   .L_rot_data_3, r6
    mov.w @r13, r5
    mov.l   .L_output_vec_3, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r8
    mov.l @r4, r4
    mov.l @r14, r2
    add #-0x30, r2
    mov.l r2, @r14
.L_06011002:
    mov.l   .L_mask_low16, r3
    mov.l   .L_vdp2_scroll_reg, r2
    mov.w r3, @r2
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
.L_fn_fpdiv:
    .4byte  sym_060270F2               /* fixed-point divide */
.L_pos_z_array:
    .4byte  sym_06078858               /* position Z array (ptr) */
.L_pos_y_array:
    .4byte  sym_06078854               /* position Y array (ptr) */
.L_pos_x_array:
    .4byte  sym_06078850               /* position X array (ptr) */
.L_rot_angle:
    .4byte  sym_06078878               /* rotation angle (16-bit) */
.L_fn_rot_xy:
    .4byte  mat_rot_xy_b               /* XY plane rotation matrix */
.L_mat_dst_array:
    .4byte  sym_0606212C               /* matrix destination array (4 slots) */
.L_mat_src_array:
    .4byte  sym_060621D8               /* matrix source array (4 slots) */
.L_fn_vec_transform:
    .4byte  sym_06032158               /* vector matrix transform */
.L_fn_vec_scale:
    .4byte  sym_06031DF4               /* scaled vector transform */
.L_rot_data_array:
    .4byte  sym_06062180               /* rotation data array (ptr) */
.L_scale_factor:
    .4byte  sym_06089E44               /* per-channel scale factor table */
.L_output_vec_array:
    .4byte  sym_060620D8               /* output vector array (ptr) */
.L_fn_fpmul:
    .4byte  sym_06027080               /* fixed-point multiply */
.L_channel_params_1:
    .4byte  sym_06044640               /* channel 1 position parameters (X/Y/Z) */
.L_rot_data_1:
    .4byte  sym_06062184               /* channel 1 rotation data (ptr) */
.L_output_vec_1:
    .4byte  sym_060620DC               /* channel 1 output vector (ptr) */
.L_pos_counter:
    .4byte  sym_0608A52C               /* position counter (decremented by 0x30) */
.L_channel_params_2_z:
    .4byte  sym_06044654               /* channel 2 Z parameter (ptr) */
.L_channel_params_2_y:
    .4byte  sym_06044650               /* channel 2 Y parameter (ptr) */
.L_channel_params_2_x:
    .4byte  sym_0604464C               /* channel 2 X parameter (ptr) */
.L_rot_data_2:
    .4byte  sym_06062188               /* channel 2 rotation data (ptr) */
.L_output_vec_2:
    .4byte  sym_060620E0               /* channel 2 output vector (ptr) */
.L_channel_params_3_z:
    .4byte  sym_06044678               /* channel 3 Z parameter (ptr) */
.L_channel_params_3_y:
    .4byte  sym_06044674               /* channel 3 Y parameter (ptr) */
.L_channel_params_3_x:
    .4byte  sym_06044670               /* channel 3 X parameter (ptr) */
.L_rot_data_3:
    .4byte  sym_0606218C               /* channel 3 rotation data (ptr) */
.L_output_vec_3:
    .4byte  sym_060620E4               /* channel 3 output vector (ptr) */
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_vdp2_scroll_reg:
    .4byte  0x21800000                  /* VDP2 scroll position register (cache-through) */
