/* race_variant_setup_a -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601416C - 0x0601424C
 *
 * Per-car variant object renderer -- iterates over active cars (up to 3)
 * and renders a variant-specific 3D object for each one.
 *
 * For each car slot:
 *   1. Pre-transform setup (sym_06026DBC)
 *   2. Load car position from object table, dispatch transform (sym_06026E2E)
 *   3. Uniform 1.0 scale via mat_scale_columns
 *   4. Read variant character from car_variant_chars[i] (sym_06084B14):
 *      - '.' (0x2E) → index 26 (no variant / default)
 *      - 'A'-'Z'    → index 0-25
 *   5. Dispatch chain A (sym_06031D8C) with model from chain_a_table[idx]
 *   6. Dispatch chain B (sym_06031A28) with model from chain_b_table[idx],
 *      using per-mode scale factor from sym_06089E4A
 *   7. Decrement render budget counter (sym_06089EDC) by 0x30
 *
 * Register allocation (persistent across loop):
 *   r8  = Y offset constant (0xCCCD sign-extended = -0x3333)
 *   r9  = max car count (3)
 *   r12 = render budget counter ptr (sym_06089EDC)
 *   r13 = loop index i (0..active_car_count-1)
 *   r14 = fixed-point 1.0 (0x00010000)
 *   [r15] = per-mode scale factor ptr (sym_06089E4A)
 */

    .section .text.FUN_0601416C


    .global race_variant_setup_a
    .type race_variant_setup_a, @function
race_variant_setup_a:
    mov.l r14, @-r15                    ! save r14 (callee-saved)
    mov.l r13, @-r15                    ! save r13
    mov.l r12, @-r15                    ! save r12
    mov.l r11, @-r15                    ! save r11
    mov.l r10, @-r15                    ! save r10
    mov.l r9, @-r15                     ! save r9
    mov.l r8, @-r15                     ! save r8
    sts.l pr, @-r15                     ! save return address
    add #-0x4, r15                      ! allocate 4 bytes on stack for local var
    mov.w   _wpool_y_offset, r8         ! r8 = 0xCCCD (sign-ext → -0x3333 Y offset)
    mov.l   _pool_budget_counter_ptr, r12 ! r12 = &render_budget_counter (sym_06089EDC)
    mov.l   _pool_fp_one, r14           ! r14 = 0x00010000 (fixed-point 1.0)
    mov.l   _pool_fn_pre_transform, r3  ! r3 = sym_06026E0C (pre-transform init)
    jsr @r3                             ! call pre_transform_init()
    mov #0x3, r9                        ! (delay) r9 = 3 (max car count)
    mov #0x0, r13                       ! r13 = 0 (loop index i)
    mov.l   _pool_scale_factor_ptr, r2  ! r2 = sym_06089E4A (per-mode scale factor)
    mov.l r2, @r15                      ! [r15] = scale_factor_ptr (local var)
.L_car_loop_top:
    mov.l   _pool_active_car_count, r3  ! r3 = &active_car_count (sym_06084B18)
    mov.l @r3, r3                       ! r3 = active_car_count
    cmp/hs r3, r13                      ! if i >= active_car_count...
    bt      .L_budget_decrement         ! ...skip to budget decrement
    mov.l   _pool_fn_pretransform_setup, r3 ! r3 = sym_06026DBC (pre-transform setup)
    jsr @r3                             ! call pre_transform_setup()
    nop                                 ! (delay)
    mov r14, r6                         ! r6 = 1.0 (Z scale)
    mov r8, r5                          ! r5 = Y offset constant
    mov r13, r4                         ! r4 = car index i
    mov.l   _pool_car_object_table, r3  ! r3 = sym_0605AD4C (car object table base)
    mov.l   _pool_fn_transform_dispatch, r2 ! r2 = sym_06026E2E (transform dispatch)
    shll2 r4                            ! r4 = i * 4 (dword offset)
    add r3, r4                          ! r4 = &car_object_table[i]
    jsr @r2                             ! call transform_dispatch(car_obj_table[i], y_off, 1.0)
    mov.l @r4, r4                       ! (delay) r4 = car_object_table[i]
    mov r14, r6                         ! r6 = 1.0 (Z scale)
    mov r14, r5                         ! r5 = 1.0 (Y scale)
    mov.l   _pool_fn_mat_scale, r3      ! r3 = mat_scale_columns
    jsr @r3                             ! call mat_scale_columns(1.0, 1.0, 1.0)
    mov r14, r4                         ! (delay) r4 = 1.0 (X scale)
    mov.l   _pool_variant_chars, r4     ! r4 = sym_06084B14 (car variant char array)
    add r13, r4                         ! r4 = &variant_chars[i]
    mov.b @r4, r4                       ! r4 = variant_chars[i] (signed byte)
    extu.b r4, r4                       ! r4 = zero-extend to unsigned
    mov r4, r0                          ! r0 = variant char
    cmp/eq #0x2E, r0                    ! is char '.' (period)?
    bf      .L_alpha_index              ! if not '.', compute alpha index
    bra     .L_index_ready              ! char is '.', use default index
    mov #0x1A, r11                      ! (delay) r11 = 26 (index for '.')
.L_alpha_index:
    mov r4, r11                         ! r11 = ASCII char
    add #-0x41, r11                     ! r11 = char - 'A' (0-based alpha index)
.L_index_ready:
    extu.b r11, r11                     ! r11 = zero-extend index to unsigned
    mov #0x4, r5                        ! r5 = 4 (stride for chain A dispatch)
    mov.l   _pool_chain_a_table, r4     ! r4 = sym_06062338 (chain A model table)
    mov.l   _pool_fn_chain_a, r3        ! r3 = sym_06031D8C (chain A dispatch)
    extu.b r11, r10                     ! r10 = unsigned variant index
    shll2 r10                           ! r10 = index * 4 (dword offset)
    add r10, r4                         ! r4 = &chain_a_table[index]
    jsr @r3                             ! call chain_a_dispatch(chain_a_table[idx], 4)
    mov.l @r4, r4                       ! (delay) r4 = chain_a_table[index]
    mov #0x1, r6                        ! r6 = 1 (chain B flag)
    mov.l @r15, r5                      ! r5 = scale_factor_ptr (from stack)
    mov.l   _pool_chain_b_table, r4     ! r4 = sym_060622C0 (chain B model table)
    mov.l   _pool_fn_chain_b, r3        ! r3 = sym_06031A28 (chain B dispatch)
    mov.w @r5, r5                       ! r5 = *scale_factor_ptr (16-bit scale)
    add r10, r4                         ! r4 = &chain_b_table[index]
    jsr @r3                             ! call chain_b_dispatch(chain_b_table[idx], scale, 1)
    mov.l @r4, r4                       ! (delay) r4 = chain_b_table[index]
    mov.l @r12, r2                      ! r2 = render_budget_counter
    add #-0x30, r2                      ! r2 -= 0x30 (subtract this object's cost)
    mov.l r2, @r12                      ! write back decremented budget
.L_budget_decrement:
    add #0x1, r13                       ! i++
    cmp/hs r9, r13                      ! if i >= 3 (max car count)...
    bf      .L_car_loop_top             ! ...else loop back
    add #0x4, r15                       ! free local stack var
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r8                     ! restore r8
    mov.l @r15+, r9                     ! restore r9
    mov.l @r15+, r10                    ! restore r10
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return
    mov.l @r15+, r14                    ! (delay) restore r14
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
