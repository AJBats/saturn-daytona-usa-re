
    .section .text.FUN_060055BC


    .global perspective_project
    .type perspective_project, @function
perspective_project:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x34, r15
    mov.l   _pool_camera_target_vec, r9
    mov.l   _pool_obj_cursor_idx, r10
    mov.l   _pool_obj_list_head, r13
    mov.w @r10, r3
    mov.l @r13, r13
    extu.w r3, r3
    mov r13, r14
    add #0x20, r14
    mov.w @r14, r2
    cmp/ge r2, r3
    bf      .L_060055FE
    mov.w @r14, r0
    cmp/eq #-0x1, r0
    bf      .L_060055EC
    mov.l @(4, r14), r14
.L_060055EC:
    mov r14, r13
    mov.l   _pool_obj_list_head, r3
    mov.l r13, @r3
    mov.w @r13, r2
    tst r2, r2
    bf/s    .L_060055FE
    add #0x20, r14
    mov #0x0, r3
    mov.w r3, @r10
.L_060055FE:
    mov.w @r14, r5
    mov.w @r13, r3
    mov.l r3, @r15
    sub r3, r5
    mov.w @r10, r4
    mov.l   _pool_fn_fpdiv_setup, r2
    shll16 r5
    extu.w r4, r4
    sub r3, r4
    jsr @r2
    shll16 r4
    mov r0, r12
    mov #0x0, r5
    mov r13, r4
    .byte   0xBF, 0x8F    /* bsr 0x0600553C (external) */
    add #0x2, r4
    mov r15, r5
    mov r13, r4
    mov.l   _pool_fn_mat_vec_transform, r8
    add #0x28, r5
    jsr @r8
    add #0x8, r4
    mov r13, r5
    mov r14, r4
    add #0x2, r5
    .byte   0xBF, 0x84    /* bsr 0x0600553C (external) */
    add #0x2, r4
    mov r15, r5
    mov r14, r4
    add #0x1C, r5
    jsr @r8
    add #0x8, r4
    mov r12, r5
    mov.l   _pool_fn_fpmul, r11
    mov.l @(40, r15), r2
    mov.l r2, @r15
    mov r2, r3
    mov.l @(28, r15), r4
    jsr @r11
    sub r3, r4
    mov r12, r5
    mov.l @r15, r3
    add r3, r0
    mov.l r0, @(16, r15)
    mov.l @(44, r15), r3
    mov.l r3, @r15
    mov.l @(32, r15), r4
    jsr @r11
    sub r3, r4
    mov.l @r15, r3
    mov r12, r5
    add r3, r0
    mov.l r0, @(20, r15)
    mov.l @(48, r15), r3
    mov.l r3, @r15
    mov.l @(36, r15), r4
    jsr @r11
    sub r3, r4
    mov r14, r5
    mov r13, r4
    mov.l @r15, r3
    add #0x2, r5
    add r3, r0
    mov.l r0, @(24, r15)
    .byte   0xBF, 0x5D    /* bsr 0x0600553C (external) */
    add #0x3, r4
    mov r15, r5
    mov r13, r4
    add #0x28, r5
    jsr @r8
    add #0x14, r4
    mov r13, r5
    add #0x3, r5
    mov r14, r4
    bra     .L_060056B0
    add #0x3, r4
    .2byte  0xFFFF
_pool_camera_target_vec:
    .4byte  sym_06063EEC                   /* camera target vector */
_pool_obj_cursor_idx:
    .4byte  sym_06063E08                   /* object list cursor index (word) */
_pool_obj_list_head:
    .4byte  sym_06063E04                   /* object list head pointer */
_pool_fn_fpdiv_setup:
    .4byte  fpdiv_setup                    /* 16.16 fixed-point divide */
_pool_fn_mat_vec_transform:
    .4byte  mat_vec_transform              /* 3x3 matrix-vector multiply */
_pool_fn_fpmul:
    .4byte  fpmul                          /* 16.16 fixed-point multiply */
.L_060056B0:
    .byte   0xBF, 0x44    /* bsr 0x0600553C (external) */
    nop
    mov r15, r5
    mov r14, r4
    add #0x1C, r5
    jsr @r8
    add #0x14, r4
    mov r12, r5
    mov.l @(40, r15), r2
    mov.l r2, @r15
    mov r2, r3
    mov.l @(28, r15), r4
    jsr @r11
    sub r3, r4
    mov.l @r15, r3
    mov r12, r5
    add r3, r0
    mov.l r0, @(4, r15)
    mov.l @(44, r15), r3
    mov.l r3, @r15
    mov.l @(32, r15), r4
    jsr @r11
    sub r3, r4
    mov r12, r5
    mov.l @r15, r3
    add r3, r0
    mov.l r0, @(8, r15)
    mov.l @(48, r15), r3
    mov.l r3, @r15
    mov.l @(36, r15), r4
    jsr @r11
    sub r3, r4
    mov.l @r15, r3
    add r3, r0
    mov.l r0, @(12, r15)
    mov.w @r10, r3
    add #0x1, r3
    mov.w r3, @r10
    mov.l   _pool_fn_matrix_entry_init, r3
    jsr @r3
    nop
    mov r15, r5
    mov r15, r4
    mov.l   _pool_camera_target_vec_2, r6
    add #0x4, r5
    .byte   0xBD, 0xC3    /* bsr 0x06005294 (external) */
    add #0x10, r4
    mov.l   _pool_cam_dir_flip_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_06005724
    mov.l @(4, r9), r14
    shll8 r14
    shll2 r14
    mov.l   _pool_positive_y_base, r3
    add r3, r14
    bra     .L_06005730
    nop
.L_06005724:
    mov.l @(4, r9), r14
    shll8 r14
    shll2 r14
    neg r14, r14
    mov.l   _pool_negative_y_base, r3
    add r3, r14
.L_06005730:
    mov.l   _pool_fn_cmd_queue_write, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r6
    mov.l @r9, r5
    mov.l   _pool_x_position_offset, r3
    shll8 r5
    shll r5
    neg r5, r5
    add r3, r5
    mov.l   _pool_fn_scene_data_write, r3
    jsr @r3
    mov r14, r4
    mov.l   _pool_fn_cmd_queue_commit, r3
    jsr @r3
    nop
    add #0x34, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
_pool_fn_matrix_entry_init:
    .4byte  sym_06026E0C                   /* matrix entry init from current ptr */
_pool_camera_target_vec_2:
    .4byte  sym_06063EEC                   /* camera target vector (output) */
_pool_cam_dir_flip_flag:
    .4byte  sym_06078663                   /* camera direction flip flag (byte) */
_pool_positive_y_base:
    .4byte  0x01A00000                     /* positive Y base offset (16.16 fixed-point) */
_pool_negative_y_base:
    .4byte  0xFFA00000                     /* negative Y base offset (16.16 fixed-point) */
_pool_fn_cmd_queue_write:
    .4byte  sym_0603850C                   /* cmd queue: write channel ID */
_pool_x_position_offset:
    .4byte  0x003A0000                     /* screen X position offset (16.16) */
_pool_fn_scene_data_write:
    .4byte  scene_data_write_abs           /* scene data: write absolute coords */
_pool_fn_cmd_queue_commit:
    .4byte  sym_06038520                   /* cmd queue: commit */
