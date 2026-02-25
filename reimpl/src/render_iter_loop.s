/* render_iter_loop -- Single-Object Render Iteration
 * Translation unit: 0x060140C8 - 0x0601416C
 *
 * Renders one dynamic object from the object pointer array (sym_0605AD4C),
 * indexed by the current object counter (sym_06084B18). Called from
 * dyn_obj_physics which sets r2 = max index (e.g. 3 for 4 objects).
 *
 * If the object counter exceeds r2, exits immediately. Otherwise:
 *   1. Look up object pointer from array[counter]
 *   2. Pre-transform setup (sym_06026DBC)
 *   3. Position transform (sym_06026E2E) with Y offset -0.2 and Z scale 1.0
 *   4. Identity scale via mat_scale_columns(1.0, 1.0, 1.0)
 *   5. BSR to camera_fov_dispatch (sets perspective r2=0x10)
 *   6. Dispatch transform chain A (sym_06031D8C) using active car slot
 *   7. Dispatch transform chain B (sym_06031A28) using display mode
 *   8. Decrement render budget (sym_06089EDC) by 0x30
 *
 * Register inputs:
 *   r2 = max object index (from caller, e.g. 3)
 *
 * Callee-saved: r14 (used to hold 1.0 fixed-point constant)
 */

    .section .text.FUN_060140C8


    .global render_iter_loop
    .type render_iter_loop, @function
render_iter_loop:
    sts.l pr, @-r15                              ! save return address
    add #-0x4, r15                               ! allocate 4 bytes stack (for object ptr)
    mov.l   _pool_obj_count_ptr, r4              ! r4 = &obj_counter (sym_06084B18)
    mov.l @r4, r3                                ! r3 = current object counter
    cmp/hi r2, r3                                ! counter > max_index?
    bt      .L_exit                              ! if so, nothing to render — exit
    mov.l @r4, r2                                ! r2 = object counter (re-read)
    mov.l   _pool_obj_ptr_table, r3              ! r3 = object pointer array base (sym_0605AD4C)
    shll2 r2                                     ! r2 = counter * 4 (pointer-size stride)
    add r3, r2                                   ! r2 = &obj_ptr_table[counter]
    mov.l @r2, r1                                ! r1 = obj_ptr_table[counter] (object data ptr)
    mov.l   _pool_pre_transform_fn, r2           ! r2 = pre-transform setup fn (sym_06026DBC)
    jsr @r2                                      ! call pre-transform setup
    mov.l r1, @r15                               ! (delay) save object pointer to stack
    mov.l   _pool_fp_one, r14                    ! r14 = 1.0 (16.16 fixed-point), kept for reuse
    mov.w   _wpool_y_offset, r5                  ! r5 = 0xFFFFCCCD (sign-ext: ~-0.2 in 16.16)
    mov.l   _pool_pos_transform_fn, r3           ! r3 = position transform fn (sym_06026E2E)
    mov r14, r6                                  ! r6 = 1.0 (Z scale)
    jsr @r3                                      ! call position transform(obj_ptr, y_offset, z_scale)
    mov.l @r15, r4                               ! (delay) r4 = saved object pointer
    mov r14, r6                                  ! r6 = 1.0 (Z scale column)
    mov r14, r5                                  ! r5 = 1.0 (Y scale column)
    mov.l   _pool_scale_columns_fn, r3           ! r3 = mat_scale_columns
    jsr @r3                                      ! call mat_scale_columns(1.0, 1.0, 1.0) — identity
    mov r14, r4                                  ! (delay) r4 = 1.0 (X scale column)
    .byte   0xBE, 0x8A    /* bsr 0x06013E12 (external) — camera_fov_dispatch */
    nop                                          ! (delay slot)
    mov #0x4, r5                                 ! r5 = 4 (render pass type for chain A)
    mov.l   _pool_car_slot_ptr, r4               ! r4 = &active_car_slot (sym_06084B08)
    mov.l   _pool_obj_xform_table, r3            ! r3 = object transform table A (sym_06062338)
    mov.l   _pool_chain_a_fn, r2                 ! r2 = transform chain dispatch A (sym_06031D8C)
    mov.l @r4, r4                                ! r4 = active car slot index
    shll2 r4                                     ! r4 = slot * 4 (pointer-size stride)
    add r3, r4                                   ! r4 = &obj_xform_table[slot]
    jsr @r2                                      ! call chain A dispatch(obj_xform[slot], 4)
    mov.l @r4, r4                                ! (delay) r4 = obj_xform_table[slot] (xform data)
    mov #0x1, r6                                 ! r6 = 1 (render pass type for chain B)
    mov.l   _pool_disp_mode_ptr, r5              ! r5 = &display_mode (sym_06089E4A)
    mov.l   _pool_car_slot_ptr, r4               ! r4 = &active_car_slot (sym_06084B08)
    mov.l   _pool_disp_xform_table, r3           ! r3 = display transform table B (sym_060622C0)
    mov.l   _pool_chain_b_fn, r2                 ! r2 = transform chain dispatch B (sym_06031A28)
    mov.w @r5, r5                                ! r5 = display mode value (16-bit)
    mov.l @r4, r4                                ! r4 = active car slot index
    shll2 r4                                     ! r4 = slot * 4 (pointer-size stride)
    add r3, r4                                   ! r4 = &disp_xform_table[slot]
    jsr @r2                                      ! call chain B dispatch(disp_xform[slot], mode, 1)
    mov.l @r4, r4                                ! (delay) r4 = disp_xform_table[slot] (xform data)
    mov.l   _pool_render_budget, r4              ! r4 = &render_budget (sym_06089EDC)
    mov.l @r4, r3                                ! r3 = current render budget
    add #-0x30, r3                               ! r3 -= 0x30 (48 bytes cost per object)
    mov.l r3, @r4                                ! store updated render budget
.L_exit:
    add #0x4, r15                                ! deallocate stack local
    lds.l @r15+, pr                              ! restore return address
    rts                                          ! return to caller
    mov.l @r15+, r14                             ! (delay) restore r14
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
