
    .section .text.FUN_06005494


    .global obj_state_writer
    .type obj_state_writer, @function
obj_state_writer:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   _pool_cam_dir_flip, r0
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_skip_y_flip
    mov r5, r13
    mov.l   _pool_fp_one, r6
    mov.l   _pool_fp_neg_one, r4
    mov.l   _pool_fn_mat_scale_columns, r3
    jsr @r3
    mov r6, r5
.L_skip_y_flip:
    mov.l @(8, r13), r4
    mov.l   _pool_fn_mat_rot_z, r3
    jsr @r3
    neg r4, r4
    mov.l @r13, r4
    mov.l   _pool_fn_mat_rot_x, r3
    jsr @r3
    neg r4, r4
    mov.l @(4, r13), r4
    mov.l   _pool_fn_mat_rot_y, r3
    jsr @r3
    neg r4, r4
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    mov.l @r14, r4
    mov.l   _pool_fn_mat_vec_mac, r3
    neg r6, r6
    neg r5, r5
    jsr @r3
    neg r4, r4
    mov.l   _pool_cam_position, r1
    mov r14, r2
    mov.l   _pool_fn_memcpy_long, r3
    jsr @r3
    mov #0xC, r0
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_060054EA
sym_060054EA:
    mov.l   _pool_obj_list_head, r3
    mov.l r4, @r3
    mov #0x0, r4
    mov.l   _pool_obj_cursor_idx, r3
    mov.w r4, @r3
    mov.l   _pool_view_matrix_b, r3
    mov.l r4, @r3
    mov r3, r1
    mov.l @r1, r1
    mov.l   _pool_view_matrix_a, r3
    rts
    mov.l r1, @r3
    .2byte  0xFFFF
_pool_cam_dir_flip:
    .4byte  sym_06078663                     /* camera direction flip flag (byte) */
_pool_fp_one:
    .4byte  0x00010000                       /* 1.0 (16.16 fixed-point) */
_pool_fp_neg_one:
    .4byte  0xFFFF0000                       /* -1.0 (16.16 fixed-point) */
_pool_fn_mat_scale_columns:
    .4byte  mat_scale_columns                /* matrix column scaling */
_pool_fn_mat_rot_z:
    .4byte  mat_rot_z                        /* Z-axis rotation matrix */
_pool_fn_mat_rot_x:
    .4byte  mat_rot_x                 /* general rotation transform */
_pool_fn_mat_rot_y:
    .4byte  mat_rot_y                        /* Y-axis rotation matrix */
_pool_fn_mat_vec_mac:
    .4byte  sym_06026E2E                     /* matrix-vector multiply-accumulate */
_pool_cam_position:
    .4byte  sym_06063DF8                     /* camera/view position state (XYZ) */
_pool_fn_memcpy_long:
    .4byte  sym_06035168                     /* memcpy_long(r0=count, r1=dst, r2=src) */
_pool_obj_list_head:
    .4byte  sym_06063E04                     /* object list head pointer */
_pool_obj_cursor_idx:
    .4byte  sym_06063E08                     /* object list cursor index (word) */
_pool_view_matrix_b:
    .4byte  sym_06063F08                     /* view matrix pointer B */
_pool_view_matrix_a:
    .4byte  sym_06063F04                     /* view matrix pointer A */
