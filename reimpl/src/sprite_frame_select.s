
    .section .text.FUN_0600553C


    .global sprite_frame_select
    .type sprite_frame_select, @function
sprite_frame_select:
    mov.l r14, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.b @r4, r14
    tst r5, r5
    bf/s    .L_check_frame_match
    mov #0x1, r4
    bra     .L_do_frame_update
    nop
.L_check_frame_match:
    exts.b r14, r2
    mov.b @r5, r3
    cmp/eq r3, r2
    bf      .L_do_frame_update
    mov #0x0, r4
.L_do_frame_update:
    exts.b r4, r4
    tst r4, r4
    bt      .L_early_return
    mov.l   .L_pool_mat_identity, r3
    jsr @r3
    nop
    exts.b r14, r0
    cmp/eq #-0x1, r0
    bt      .L_early_return
    exts.b r14, r14
    mov.w   .L_wpool_anim_entry_stride, r2
    mov.l   .L_pool_anim_table_base, r3
    mul.l r2, r14
    sts macl, r14
    add r3, r14
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.l   .L_pool_mat_xform_trans, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov.l   .L_pool_mat_rot_y, r3
    jsr @r3
    mov.l @(32, r14), r4
    mov.l   .L_pool_mat_rot_x, r3
    jsr @r3
    mov.l @(28, r14), r4
    mov.l @(36, r14), r4
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l   .L_pool_mat_rot_z, r3
    jmp @r3
    mov.l @r15+, r14
.L_early_return:
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_anim_entry_stride:
    .2byte  0x0268              /* [HIGH] animation table entry stride: 0x268 bytes per entry */
    .2byte  0xFFFF
.L_pool_mat_identity:
    .4byte  sym_06026E0C
.L_pool_anim_table_base:
    .4byte  sym_06078900
.L_pool_mat_xform_trans:
    .4byte  sym_06026E2E
.L_pool_mat_rot_y:
    .4byte  mat_rot_y
.L_pool_mat_rot_x:
    .4byte  mat_rot_x
.L_pool_mat_rot_z:
    .4byte  mat_rot_z
