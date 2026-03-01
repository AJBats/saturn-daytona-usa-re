
    .section .text.FUN_0600A614


    .global camera_collision_avoid
    .type camera_collision_avoid, @function
camera_collision_avoid:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_global_counter, r12
    mov.l   .L_fp_half, r13
    mov.l   .L_config_ptr, r14
    mov.l @r14, r14
    mov.b @(1, r14), r0
    mov r0, r3
    tst r3, r3
    bt      .L_skip_object_a
    mov.l   .L_fn_pre_transform, r3
    jsr @r3
    nop
    mov.l   .L_position_vec_a, r11
    mov.l   .L_pos_offset_a, r2
    mov.w   .L_off_adj_yz, r3
    mov.l @(8, r11), r6
    mov.l @(4, r11), r5
    mov.l @r11, r4
    add r2, r6
    add r3, r5
    mov.w   .L_off_adj_x, r2
    mov.l   .L_fn_transform_dispatch, r3
    jsr @r3
    add r2, r4
    mov r13, r6
    mov r13, r5
    mov.l   .L_fn_scale_columns, r3
    jsr @r3
    mov r13, r4
    mov.b @r14, r5
    add #0xE, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_chain_a_src_tbl, r3
    mov.l @r15, r4
    mov.l   .L_chain_a_param_tbl, r2
    mov.l   .L_fn_chain_a, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r14, r6
    add #0xE, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_chain_b_src_tbl, r3
    mov.l   .L_disp_mode_word, r5
    mov.l @r15, r4
    mov.l   .L_chain_b_param_tbl, r2
    mov.l   .L_fn_chain_b, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    jsr @r1
    mov.l @r4, r4
    mov.l @r12, r3
    add #-0x30, r3
    mov.l r3, @r12
.L_skip_object_a:
    mov.b @(4, r14), r0
    mov r0, r2
    tst r2, r2
    bt      .L_epilogue
    mov.l   .L_fn_pre_transform, r3
    jsr @r3
    nop
    mov.l   .L_position_vec_b, r11
    mov.l   .L_pos_offset_b, r3
    mov.w   .L_off_adj_yz, r2
    mov.l @(8, r11), r6
    mov.l @(4, r11), r5
    neg r6, r6
    add r2, r5
    add r3, r6
    mov.l   .L_fn_transform_dispatch, r3
    jsr @r3
    mov.l @r11, r4
    mov r13, r6
    mov r13, r5
    mov.l   .L_fn_scale_columns, r3
    jsr @r3
    mov r13, r4
    mov.b @(3, r14), r0
    mov r0, r5
    add #0xE, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_chain_a_src_tbl, r3
    mov.l @r15, r4
    mov.l   .L_chain_a_param_tbl, r2
    mov.l   .L_fn_chain_a, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @(3, r14), r0
    mov r0, r6
    add #0xE, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_chain_b_src_tbl, r3
    add r3, r6
    mov.l @r6, r6
    mov.l   .L_disp_mode_word, r5
    mov.w @r5, r5
    mov.l @r15, r4
    bra     .L_shared_chain_b
    nop
.L_off_adj_yz:
    .2byte  0xCCCD                        /* Y position adjustment offset */
.L_off_adj_x:
    .2byte  0x8000                        /* X position adjustment offset */
    .2byte  0xFFFF                        /* alignment padding */
.L_global_counter:
    .4byte  sym_06089EDC               /* global animation counter (dec by 0x30/obj) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_config_ptr:
    .4byte  sym_0607EB8C               /* config struct: enable flags + model indices */
.L_fn_pre_transform:
    .4byte  sym_06026DBC               /* per-object pre-transform setup */
.L_position_vec_a:
    .4byte  sym_06044640               /* object A position vector (XYZ triplet) */
.L_pos_offset_a:
    .4byte  0xFFFF0F5D                  /* object A Z offset (signed: -0xF0A3) */
.L_fn_transform_dispatch:
    .4byte  sym_06026E2E               /* transform dispatch function */
.L_fn_scale_columns:
    .4byte  mat_scale_columns          /* uniform column scale */
.L_chain_a_src_tbl:
    .4byte  sym_060621D8               /* chain A source table (object transforms) */
.L_chain_a_param_tbl:
    .4byte  sym_0606212C               /* chain A parameter table */
.L_fn_chain_a:
    .4byte  sym_06031D8C               /* transform chain dispatch A */
.L_chain_b_src_tbl:
    .4byte  sym_06062180               /* chain B source table (display transforms) */
.L_disp_mode_word:
    .4byte  sym_06089E9C               /* display mode selector (16-bit) */
.L_chain_b_param_tbl:
    .4byte  sym_060620D8               /* chain B parameter table */
.L_fn_chain_b:
    .4byte  sym_06031A28               /* transform chain dispatch B */
.L_position_vec_b:
    .4byte  sym_06044670               /* object B position vector (XYZ triplet) */
.L_pos_offset_b:
    .4byte  0xFFFDB334                  /* object B Z offset (signed: -0x24CCC) */
.L_shared_chain_b:
    mov.l   .L_chain_b_param_tbl_2, r2
    mov.l   .L_fn_chain_b_2, r1
    add r2, r4
    jsr @r1
    mov.l @r4, r4
    mov.l @r12, r3
    add #-0x30, r3
    mov.l r3, @r12
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF                        /* alignment padding */
.L_chain_b_param_tbl_2:
    .4byte  sym_060620D8               /* chain B parameter table (dup for reach) */
.L_fn_chain_b_2:
    .4byte  sym_06031A28               /* transform chain dispatch B (dup for reach) */
