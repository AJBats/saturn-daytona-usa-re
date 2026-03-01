
    .section .text.FUN_060125D0


    .global lap_display_anim
    .type lap_display_anim, @function
lap_display_anim:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x14, r15
    mov.l   .L_anim_counter, r14
    mov r15, r1
    mov.l   .L_init_data_src, r2
    mov.l   .L_fn_data_copy, r3
    add #0xC, r1
    jsr @r3
    mov #0x8, r0
    mov.l   .L_fn_pre_transform, r3
    jsr @r3
    nop
    mov.l   .L_fn_pre_anim, r3
    jsr @r3
    nop
    mov.l   .L_position_vec, r13
    mov.l   .L_fn_transform_dispatch, r3
    mov.l @(8, r13), r6
    mov.l @(4, r13), r5
    jsr @r3
    mov.l @r13, r4
    mov.l   .L_rot_angle, r4
    mov.l   .L_fn_rot_z, r3
    jsr @r3
    mov.w @r4, r4
    mov.l   .L_stack_base_ptr, r1
    mov.l   .L_fn_model_lookup, r3
    mov.l @r1, r1
    add #-0x14, r1
    jsr @r3
    mov #0x14, r0
    mov r0, r7
    mov r15, r3
    mov.l r0, @(8, r15)
    shll r7
    add #0xC, r3
    mov.l r7, @(4, r15)
    add r3, r7
    mov.l   .L_model_table, r2
    mov.w @r7, r7
    extu.w r7, r7
    shll2 r7
    shll r7
    add r2, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_model_data_offset, r3
    mov.w   .L_sprite_list_offset, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    mov.l   .L_fn_draw_sprite, r3
    jsr @r3
    mov #0x8, r4
    mov.w @r14, r2
    mov.l @(4, r15), r3
    mov.l   .L_anim_compare_tbl, r1
    add r1, r3
    mov.w @r3, r3
    cmp/eq r3, r2
    bt      .L_06012656
    mov.w   DAT_060126a4, r3
    mov.w @r14, r2
    sub r3, r2
    mov.w r2, @r14
.L_06012656:
    mov.l   .L_fn_rot_y, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_fn_transform_mat, r3
    jsr @r3
    mov.w @r14, r4
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
    mov.l   .L_fn_cleanup, r3
    jsr @r3
    nop
    add #0x14, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_sprite_list_offset:
    .2byte  0x0390                        /* VDP1 sprite display list offset */

    .global DAT_060126a4
DAT_060126a4:
    .2byte  0x1000                        /* animation counter adjustment step */
    .2byte  0xFFFF
.L_anim_counter:
    .4byte  sym_060788B0               /* animation counter (16-bit, per frame) */
.L_init_data_src:
    .4byte  sym_0605ACF8               /* initialization data source (8 bytes) */
.L_fn_data_copy:
    .4byte  sym_06035228               /* byte/word copy function */
.L_fn_pre_transform:
    .4byte  sym_06026DBC               /* per-object pre-transform setup */
.L_fn_pre_anim:
    .4byte  sym_06026E0C               /* pre-animation setup */
.L_position_vec:
    .4byte  sym_060788B4               /* object position vector (XYZ triplet) */
.L_fn_transform_dispatch:
    .4byte  sym_06026E2E               /* transform dispatch function */
.L_rot_angle:
    .4byte  sym_060788B2               /* Z rotation angle state (16-bit) */
.L_fn_rot_z:
    .4byte  mat_rot_z                  /* Z-axis rotation */
.L_stack_base_ptr:
    .4byte  sym_0607EBCC               /* stack/model base pointer (indirect) */
.L_fn_model_lookup:
    .4byte  sym_06034FE0               /* model data lookup function */
.L_model_table:
    .4byte  sym_06063750               /* model geometry table (8 bytes per entry) */
.L_model_data_offset:
    .4byte  0x0000B000                  /* model data base offset */
.L_fn_draw_sprite:
    .4byte  sym_06028400               /* sprite/model draw function */
.L_anim_compare_tbl:
    .4byte  sym_0605AC94               /* animation counter reference table */
.L_fn_rot_y:
    .4byte  mat_rot_y                  /* Y-axis rotation */
.L_fn_transform_mat:
    .4byte  mat_rot_x           /* apply transform matrix */
.L_chain_a_src:
    .4byte  sym_06063558               /* chain A source data */
.L_obj_counter:
    .4byte  sym_0607EAD8               /* object/car counter (indexed -1) */
.L_chain_a_table:
    .4byte  sym_0606354C               /* chain A dispatch table */
.L_fn_chain_a:
    .4byte  sym_06031D8C               /* transform chain dispatch A */
.L_chain_b_src:
    .4byte  sym_06063554               /* chain B source data */
.L_disp_mode:
    .4byte  sym_06089EA0               /* display mode selector (16-bit) */
.L_chain_b_table:
    .4byte  sym_06063544               /* chain B dispatch table */
.L_fn_chain_b:
    .4byte  sym_06031A28               /* transform chain dispatch B */
.L_fn_cleanup:
    .4byte  sym_06026DF8               /* post-animation cleanup */
