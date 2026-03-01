
    .section .text.FUN_060140C8


    .global render_iter_loop
    .type render_iter_loop, @function
render_iter_loop:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   _pool_obj_count_ptr, r4
    mov.l @r4, r3
    cmp/hi r2, r3
    bt      .L_exit
    mov.l @r4, r2
    mov.l   _pool_obj_ptr_table, r3
    shll2 r2
    add r3, r2
    mov.l @r2, r1
    mov.l   _pool_pre_transform_fn, r2
    jsr @r2
    mov.l r1, @r15
    mov.l   _pool_fp_one, r14
    mov.w   _wpool_y_offset, r5
    mov.l   _pool_pos_transform_fn, r3
    mov r14, r6
    jsr @r3
    mov.l @r15, r4
    mov r14, r6
    mov r14, r5
    mov.l   _pool_scale_columns_fn, r3
    jsr @r3
    mov r14, r4
    .byte   0xBE, 0x8A    /* bsr 0x06013E12 (external) */
    nop
    mov #0x4, r5
    mov.l   _pool_car_slot_ptr, r4
    mov.l   _pool_obj_xform_table, r3
    mov.l   _pool_chain_a_fn, r2
    mov.l @r4, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov #0x1, r6
    mov.l   _pool_disp_mode_ptr, r5
    mov.l   _pool_car_slot_ptr, r4
    mov.l   _pool_disp_xform_table, r3
    mov.l   _pool_chain_b_fn, r2
    mov.w @r5, r5
    mov.l @r4, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov.l   _pool_render_budget, r4
    mov.l @r4, r3
    add #-0x30, r3
    mov.l r3, @r4
.L_exit:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
_wpool_y_offset:
    .2byte  0xCCCD                               /* ~-0.2 (16.16 fixed-point, sign-extended) */
_pool_obj_count_ptr:
    .4byte  sym_06084B18                         /* object iteration counter */
_pool_obj_ptr_table:
    .4byte  sym_0605AD4C                         /* object pointer array base */
_pool_pre_transform_fn:
    .4byte  sym_06026DBC                         /* pre-transform setup function */
_pool_fp_one:
    .4byte  0x00010000                           /* 1.0 (16.16 fixed-point) */
_pool_pos_transform_fn:
    .4byte  sym_06026E2E                         /* position transform dispatch */
_pool_scale_columns_fn:
    .4byte  mat_scale_columns                    /* matrix column scaling */
_pool_car_slot_ptr:
    .4byte  sym_06084B08                         /* active car slot index */
_pool_obj_xform_table:
    .4byte  sym_06062338                         /* object transform table A */
_pool_chain_a_fn:
    .4byte  sym_06031D8C                         /* transform chain dispatch A */
_pool_disp_mode_ptr:
    .4byte  sym_06089E4A                         /* display mode selector (16-bit) */
_pool_disp_xform_table:
    .4byte  sym_060622C0                         /* display transform table B */
_pool_chain_b_fn:
    .4byte  sym_06031A28                         /* transform chain dispatch B */
_pool_render_budget:
    .4byte  sym_06089EDC                         /* render budget counter (dec by 0x30/obj) */
