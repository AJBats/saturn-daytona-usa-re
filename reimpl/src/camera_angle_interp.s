
    .section .text.FUN_0601424C


    .global camera_angle_interp
    .type camera_angle_interp, @function
camera_angle_interp:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_camera_push, r3
    jsr @r3
    nop
    mov.l   .L_fn_camera_init, r3
    jsr @r3
    nop
    mov.l   .L_camera_z_offset, r6
    mov.w   DAT_06014306, r5
    mov.l   .L_fn_camera_pos, r3
    jsr @r3
    mov #0x0, r4
    mov #0x0, r1
    mov.l   .L_car_slot_index, r12
    mov.l   .L_car_data_table, r3
    mov.l   .L_interp_angle, r14
    mov.l @r12, r12
    shll2 r12
    shll2 r12
    shll r12
    add r3, r12
    mov.w @(24, r12), r0
    mov.w @r14, r3
    mov r0, r2
    sub r3, r2
    cmp/gt r2, r1
    addc r1, r2
    shar r2
    add r2, r3
    mov.w r3, @r14
    mov.l   .L_fn_rot_z, r3
    jsr @r3
    mov.w @r14, r4
    mov.l   .L_camera_distance, r13
    mov.l   .L_fp_half, r5
    mov.l @r12, r4
    mov.w   .L_distance_bias, r2
    mov.l @r13, r3
    sub r3, r4
    mov.l   .L_fn_fpmul, r3
    jsr @r3
    add r2, r4
    mov #0x0, r6
    mov.l @r13, r2
    add r0, r2
    mov.l r2, @r13
    mov r2, r5
    mov.l   .L_fn_camera_pos, r3
    jsr @r3
    mov r6, r4
    mov.w @r14, r4
    mov.l   .L_fn_rot_z, r3
    jsr @r3
    neg r4, r4
    mov.l   .L_wind_direction, r0
    mov.l   .L_fn_rot_y, r3
    mov.l @r0, r0
    and #0x1F, r0
    mov r0, r4
    shll8 r4
    shll2 r4
    jsr @r3
    shll r4
    mov.l   .L_fp_one, r14
    mov.l   .L_fn_mat_scale, r3
    mov r14, r6
    mov r14, r5
    jsr @r3
    mov r14, r4
    mov #0x4, r5
    mov.l   .L_vec_src_a, r4
    mov.l   .L_fn_vec_copy, r3
    jsr @r3
    mov.l @r4, r4
    mov #0x1, r6
    mov.l   .L_scale_factor, r5
    mov.l   .L_vec_src_b, r4
    mov.l   .L_fn_vec_scale, r3
    mov.w @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_frame_counter, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06014306
DAT_06014306:
    .2byte  0x8000                        /* initial Y position (half-rotation) */
.L_distance_bias:
    .2byte  0x020C                        /* distance interpolation bias */
    .2byte  0xFFFF
.L_fn_camera_push:
    .4byte  sym_06026E0C               /* camera state push/save */
.L_fn_camera_init:
    .4byte  sym_06026DBC               /* camera state initialization */
.L_camera_z_offset:
    .4byte  0x000108F5                  /* fixed Z camera position */
.L_fn_camera_pos:
    .4byte  sym_06026E2E               /* set camera base position */
.L_car_slot_index:
    .4byte  sym_06084B08               /* active car slot index (32-bit ptr) */
.L_car_data_table:
    .4byte  sym_0605AD5C               /* car data table base */
.L_interp_angle:
    .4byte  sym_06084AF8               /* interpolated angle state (16-bit) */
.L_fn_rot_z:
    .4byte  mat_rot_z                  /* Z-axis rotation */
.L_camera_distance:
    .4byte  sym_06084AFC               /* camera distance state (32-bit) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_fn_fpmul:
    .4byte  fpmul                      /* fixed-point multiply */
.L_wind_direction:
    .4byte  sym_0607EBC8               /* wind/environment direction (5-bit used) */
.L_fn_rot_y:
    .4byte  mat_rot_y                  /* Y-axis rotation */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_fn_mat_scale:
    .4byte  mat_scale_columns          /* matrix column scaling */
.L_vec_src_a:
    .4byte  sym_060623AC               /* vector source A (ptr to data) */
.L_fn_vec_copy:
    .4byte  sym_06031D8C               /* vector copy function */
.L_scale_factor:
    .4byte  sym_06089E4A               /* per-mode scale factor (16-bit) */
.L_vec_src_b:
    .4byte  sym_06062334               /* vector source B (ptr to data) */
.L_fn_vec_scale:
    .4byte  sym_06031A28               /* scaled vector copy function */
.L_frame_counter:
    .4byte  sym_06089EDC               /* frame/position counter (32-bit) */
