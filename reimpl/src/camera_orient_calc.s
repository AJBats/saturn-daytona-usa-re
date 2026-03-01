
    .section .text.FUN_060053AC


    .global camera_orient_calc
    .type camera_orient_calc, @function
camera_orient_calc:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov r5, r13
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_fn_camera_push, r3
    jsr @r3
    mov r6, r12
    mov.l   .L_budget_counter, r4
    mov.l @r4, r4
    mov.l r12, @(44, r4)
    mov.l   .L_cam_dir_flip, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_skip_y_mirror
    mov.l   .L_fp_one, r6
    mov.l   .L_fp_neg_one, r4
    mov.l   .L_fn_mat_scale_cols, r3
    jsr @r3
    mov r6, r5
.L_skip_y_mirror:
    mov.l @r13, r4
    mov.l   .L_fn_mat_rot_x, r3
    jsr @r3
    neg r4, r4
    mov.l @(8, r13), r4
    mov.l   .L_fn_mat_rot_z, r3
    jsr @r3
    neg r4, r4
    mov.l @(4, r13), r4
    mov.l   .L_fn_mat_rot_y, r3
    jsr @r3
    neg r4, r4
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    mov.l @r14, r4
    mov.l   .L_fn_mat_vec_mac, r3
    neg r6, r6
    neg r5, r5
    jsr @r3
    neg r4, r4
    mov r15, r6
    mov r15, r5
    mov.l   .L_fn_sincos_pair, r3
    add #0xC, r5
    jsr @r3
    mov.l @r13, r4
    mov r15, r6
    mov r15, r5
    mov.l   .L_fn_sincos_pair, r3
    add #0x8, r6
    add #0x4, r5
    jsr @r3
    mov.l @(4, r13), r4
    mov.l   .L_cam_pos_state, r11
    mov.l   .L_fn_fpmul, r13
    mov.l @(4, r15), r5
    jsr @r13
    mov.l @r15, r4
    mov r0, r5
    jsr @r13
    mov r12, r4
    mov.l @r14, r3
    add r3, r0
    mov.l r0, @r11
    mov.l @(12, r15), r5
    jsr @r13
    mov r12, r4
    mov.l @(4, r14), r3
    sub r0, r3
    mov.l r3, @(4, r11)
    mov.l @(8, r15), r5
    jsr @r13
    mov.l @r15, r4
    mov r0, r5
    jsr @r13
    mov r12, r4
    mov.l @(8, r14), r3
    sub r0, r3
    mov.l r3, @(8, r11)
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_fn_camera_push:
    .4byte  sym_06026E0C              /* camera_push — save/init camera state */
.L_budget_counter:
    .4byte  sym_06089EDC              /* rendering budget counter struct ptr (write [+44] = scale) */
.L_cam_dir_flip:
    .4byte  sym_06078663              /* camera direction flip flag (byte; 0=normal, !0=flip Y) */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_fp_neg_one:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_fn_mat_scale_cols:
    .4byte  mat_scale_columns           /* matrix column scale: mat_scale_columns(x, y, z) */
.L_fn_mat_rot_x:
    .4byte  mat_rot_x            /* general rotation matrix transform */
.L_fn_mat_rot_z:
    .4byte  mat_rot_z                   /* Z-axis rotation matrix */
.L_fn_mat_rot_y:
    .4byte  mat_rot_y                   /* Y-axis rotation matrix */
.L_fn_mat_vec_mac:
    .4byte  sym_06026E2E               /* mat_vec_multiply_accumulate — translate view */
.L_fn_sincos_pair:
    .4byte  sincos_pair                 /* sincos_pair(angle, &sin_out, &cos_out) */
.L_cam_pos_state:
    .4byte  sym_06063DF8               /* camera position/orientation state (XYZ output) */
.L_fn_fpmul:
    .4byte  fpmul                       /* 16.16 fixed-point multiply: fpmul(r4, r5) → r0 */
