
    .section .text.FUN_06012454


    .global file_format_parse
    .type file_format_parse, @function
file_format_parse:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_fn_pre_transform, r3
    jsr @r3
    mov.b r5, @r15
    mov.l   .L_fn_matrix_init, r3
    jsr @r3
    nop
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    mov.l   .L_fn_transform_dispatch, r3
    jsr @r3
    mov.l @r14, r4
    mov.b @r15, r1
    mov.l   .L_fn_mem_store_helper, r3
    extu.b r1, r1
    jsr @r3
    mov #0x2, r0
    mov r0, r4
    mov r0, r3
    mov.w   .L_angle_offset, r2
    shll8 r4
    shll8 r3
    shll2 r4
    shll2 r3
    shll2 r4
    shll2 r3
    shll2 r4
    shll2 r3
    shll r3
    add r3, r4
    mov.l   .L_fn_transform_mat, r3
    jsr @r3
    add r2, r4
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
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_fn_post_cleanup, r3
    jmp @r3
    mov.l @r15+, r14
.L_angle_offset:
    .2byte  0x1000                         /* 0x1000 fixed-point angle bias */
.L_fn_pre_transform:
    .4byte  sym_06026DBC                   /* pre-transform setup */
.L_fn_matrix_init:
    .4byte  sym_06026E0C                   /* matrix entry init */
.L_fn_transform_dispatch:
    .4byte  sym_06026E2E                   /* position transform dispatch */
.L_fn_mem_store_helper:
    .4byte  sym_06035C2C                   /* memory store helper (writes to 0xFF00 area) */
.L_fn_transform_mat:
    .4byte  mat_rot_x               /* transform matrix application */
.L_chain_a_src:
    .4byte  sym_06063570                   /* chain A source param (dword: 0x4) */
.L_obj_counter:
    .4byte  sym_0607EAD8                   /* object/car counter (dword) */
.L_chain_a_table:
    .4byte  sym_06063564                   /* chain A lookup table (object transforms) */
.L_fn_chain_a:
    .4byte  sym_06031D8C                   /* transform chain dispatch A */
.L_chain_b_src:
    .4byte  sym_0606356C                   /* chain B source param (dword: 0x1) */
.L_disp_mode:
    .4byte  sym_06089EA0                   /* display mode selector (16-bit) */
.L_chain_b_table:
    .4byte  sym_0606355C                   /* chain B lookup table (display transforms) */
.L_fn_chain_b:
    .4byte  sym_06031A28                   /* transform chain dispatch B */
.L_fn_post_cleanup:
    .4byte  sym_06026DF8                   /* post-render cleanup (pop matrix frame) */
