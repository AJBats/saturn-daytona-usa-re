
    .section .text.FUN_0601416C


    .global race_variant_setup_a
    .type race_variant_setup_a, @function
race_variant_setup_a:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w   _wpool_y_offset, r8
    mov.l   _pool_budget_counter_ptr, r12
    mov.l   _pool_fp_one, r14
    mov.l   _pool_fn_pre_transform, r3
    jsr @r3
    mov #0x3, r9
    mov #0x0, r13
    mov.l   _pool_scale_factor_ptr, r2
    mov.l r2, @r15
.L_06014190:
    mov.l   _pool_active_car_count, r3
    mov.l @r3, r3
    cmp/hs r3, r13
    bt      .L_060141F8
    mov.l   _pool_fn_pretransform_setup, r3
    jsr @r3
    nop
    mov r14, r6
    mov r8, r5
    mov r13, r4
    mov.l   _pool_car_object_table, r3
    mov.l   _pool_fn_transform_dispatch, r2
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov r14, r6
    mov r14, r5
    mov.l   _pool_fn_mat_scale, r3
    jsr @r3
    mov r14, r4
    mov.l   _pool_variant_chars, r4
    add r13, r4
    mov.b @r4, r4
    extu.b r4, r4
    mov r4, r0
    cmp/eq #0x2E, r0
    bf      .L_060141CC
    bra     .L_060141D0
    mov #0x1A, r11
.L_060141CC:
    mov r4, r11
    add #-0x41, r11
.L_060141D0:
    extu.b r11, r11
    mov #0x4, r5
    mov.l   _pool_chain_a_table, r4
    mov.l   _pool_fn_chain_a, r3
    extu.b r11, r10
    shll2 r10
    add r10, r4
    jsr @r3
    mov.l @r4, r4
    mov #0x1, r6
    mov.l @r15, r5
    mov.l   _pool_chain_b_table, r4
    mov.l   _pool_fn_chain_b, r3
    mov.w @r5, r5
    add r10, r4
    jsr @r3
    mov.l @r4, r4
    mov.l @r12, r2
    add #-0x30, r2
    mov.l r2, @r12
.L_060141F8:
    add #0x1, r13
    cmp/hs r9, r13
    bf      .L_06014190
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
_wpool_y_offset:
    .2byte  0xCCCD                      /* sign-extended: -0x3333 (Y position offset) */
_pool_budget_counter_ptr:
    .4byte  sym_06089EDC                /* render budget counter (decremented by 0x30 per car) */
_pool_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
_pool_fn_pre_transform:
    .4byte  sym_06026E0C                /* pre-transform initialization function */
_pool_scale_factor_ptr:
    .4byte  sym_06089E4A                /* per-mode 16-bit scale factor */
_pool_active_car_count:
    .4byte  sym_06084B18                /* active car count (read as 32-bit) */
_pool_fn_pretransform_setup:
    .4byte  sym_06026DBC                /* per-object pre-transform setup */
_pool_car_object_table:
    .4byte  sym_0605AD4C                /* car object position table (array of ptrs) */
_pool_fn_transform_dispatch:
    .4byte  sym_06026E2E                /* transform dispatch (sets position) */
_pool_fn_mat_scale:
    .4byte  mat_scale_columns           /* uniform column scale function */
_pool_variant_chars:
    .4byte  sym_06084B14                /* car variant character array (byte per car) */
_pool_chain_a_table:
    .4byte  sym_06062338                /* chain A model lookup table (27 entries) */
_pool_fn_chain_a:
    .4byte  sym_06031D8C                /* transform chain A dispatch */
_pool_chain_b_table:
    .4byte  sym_060622C0                /* chain B model lookup table (27 entries) */
_pool_fn_chain_b:
    .4byte  sym_06031A28                /* transform chain B dispatch (scaled) */
