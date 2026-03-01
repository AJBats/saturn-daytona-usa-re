
    .section .text.FUN_06005294


    .global vec3_angle_calc
    .type vec3_angle_calc, @function
vec3_angle_calc:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov r6, r10
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l @r5, r13
    mov.l @r14, r3
    mov.l @(4, r5), r2
    sub r3, r13
    mov.l @(4, r14), r3
    sub r3, r2
    mov.l r2, @r15
    mov.l @(8, r5), r12
    mov.l @(8, r14), r3
    sub r3, r12
    mov r12, r5
    mov.l   .L_pool_atan2_fn, r3
    jsr @r3
    mov r13, r4
    cmp/pz r13
    bt/s    .L_dx_positive
    mov r0, r9
    bra     .L_have_abs_dx
    neg r13, r11
.L_dx_positive:
    mov r13, r11
.L_have_abs_dx:
    cmp/pz r12
    bt      .L_dz_positive
    bra     .L_have_abs_dz
    neg r12, r13
.L_dz_positive:
    mov r12, r13
.L_have_abs_dz:
    cmp/gt r13, r11
    bf      .L_dz_dominant
    mov.l   .L_pool_scale_major, r4
    mov.l   .L_pool_fpmul_fn_a, r3
    jsr @r3
    mov r11, r5
    mov r0, r8
    mov.w   DAT_060052f6, r4
    mov.l   .L_pool_fpmul_fn_a, r3
    jsr @r3
    mov r13, r5
    bra     .L_have_horiz_dist
    nop

    .global DAT_060052f6
DAT_060052f6:
    .2byte  0x61F7                         /* sin(22.5 deg) in 16.16 fp (~0.3827) */
.L_pool_atan2_fn:
    .4byte  atan2                          /* fixed-point atan2(y, x) */
.L_pool_scale_major:
    .4byte  0x0000EC83                     /* cos(22.5 deg) in 16.16 fp (~0.9239) */
.L_pool_fpmul_fn_a:
    .4byte  fpmul                          /* 16.16 fixed-point multiply */
.L_dz_dominant:
    mov.l   .L_pool_scale_major_b, r4
    mov.l   .L_pool_fpmul_fn_b, r3
    jsr @r3
    mov r13, r5
    mov r0, r8
    mov.w   DAT_0600537a, r4
    mov.l   .L_pool_fpmul_fn_b, r3
    jsr @r3
    mov r11, r5
.L_have_horiz_dist:
    mov r8, r5
    mov.l   .L_pool_atan2_fn_b, r3
    add r0, r5
    jsr @r3
    mov.l @r15, r4
    neg r0, r13
    mov.l   .L_pool_cam_flip_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_no_cam_flip
    mov.l   .L_fp_one, r6
    mov.l   .L_fp_neg_one, r4
    mov.l   .L_pool_mat_scale_fn, r3
    jsr @r3
    mov r6, r5
.L_no_cam_flip:
    mov.l   .L_pool_xform_mat_fn, r3
    jsr @r3
    mov r13, r4
    mov.l   .L_pool_rot_y_fn, r3
    jsr @r3
    mov r9, r4
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    mov.l @r14, r4
    mov.l   .L_pool_pos_xform_fn, r3
    neg r6, r6
    neg r5, r5
    jsr @r3
    neg r4, r4
    mov.l   .L_pool_cam_state_ptr, r1
    mov r14, r2
    mov.l   .L_pool_memcpy_long_fn, r3
    jsr @r3
    mov #0xC, r0
    neg r13, r13
    neg r9, r9
    mov #0x0, r2
    mov.l r13, @r10
    mov.l r9, @(4, r10)
    mov.l r2, @(8, r10)
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

    .global DAT_0600537a
DAT_0600537a:
    .2byte  0x61F7                         /* sin(22.5 deg) in 16.16 fp (~0.3827) */
.L_pool_scale_major_b:
    .4byte  0x0000EC83                     /* cos(22.5 deg) in 16.16 fp (~0.9239) */
.L_pool_fpmul_fn_b:
    .4byte  fpmul                          /* 16.16 fixed-point multiply */
.L_pool_atan2_fn_b:
    .4byte  atan2                          /* fixed-point atan2(y, x) */
.L_pool_cam_flip_flag:
    .4byte  sym_06078663                   /* camera direction flip flag (byte) */
.L_fp_one:
    .4byte  0x00010000                     /* 1.0 (16.16 fixed-point) */
.L_fp_neg_one:
    .4byte  0xFFFF0000                     /* -1.0 (16.16 fixed-point) */
.L_pool_mat_scale_fn:
    .4byte  mat_scale_columns              /* scale matrix columns (for Y flip) */
.L_pool_xform_mat_fn:
    .4byte  mat_rot_x               /* apply rotation by angle */
.L_pool_rot_y_fn:
    .4byte  mat_rot_y                      /* Y-axis rotation matrix */
.L_pool_pos_xform_fn:
    .4byte  sym_06026E2E                   /* position transform dispatch */
.L_pool_cam_state_ptr:
    .4byte  sym_06063DF8                   /* camera position/orientation state */
.L_pool_memcpy_long_fn:
    .4byte  sym_06035168                   /* memcpy_long (unrolled longword copy) */
