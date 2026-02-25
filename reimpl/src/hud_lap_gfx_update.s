/* hud_lap_gfx_update -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601250C - 0x060125D0
 *
 * HUD lap indicator graphics update — sets up and renders the 3D lap
 * counter element on the racing HUD. This is the lightweight companion
 * to lap_display_anim (which handles the animated model).
 *
 * Flow:
 *   1. Pre-transform setup (sym_06026DBC)
 *   2. Matrix entry init (sym_06026E0C)
 *   3. Load object position (XYZ triplet) and dispatch transform (sym_06026E2E)
 *   4. Apply Z rotation from angle state (mat_rot_z)
 *   5. Apply Y rotation = 0 (mat_rot_y, identity)
 *   6. Apply transform matrix with angle = 0 (transform_matrix)
 *   7. If speed counter >= 100 (0x64), apply additional transform with 0x1000
 *   8. Dispatch transform chain A (sym_06031D8C) — object transform, indexed by counter-1
 *   9. Dispatch transform chain B (sym_06031A28) — display transform, indexed by counter-1
 *  10. Tail-call post-render cleanup (sym_06026DF8)
 */

    .section .text.FUN_0601250C


    .global hud_lap_gfx_update
    .type hud_lap_gfx_update, @function
hud_lap_gfx_update:
    mov.l r14, @-r15                       ! save r14 (callee-saved)
    sts.l pr, @-r15                        ! save return address
    mov.l   .L_fn_pre_transform, r3        ! r3 = &pre_transform_setup
    jsr @r3                                ! call pre-transform setup
    nop                                    ! (delay slot)
    mov.l   .L_fn_matrix_init, r3          ! r3 = &matrix_entry_init
    jsr @r3                                ! call matrix entry init
    nop                                    ! (delay slot)
    mov.l   .L_position_vec, r14           ! r14 = &position XYZ triplet (WRAM High)
    mov.l   .L_fn_transform_dispatch, r3   ! r3 = &transform_dispatch
    mov.l @(8, r14), r6                    ! r6 = position.Z (arg3)
    mov.l @(4, r14), r5                    ! r5 = position.Y (arg2)
    jsr @r3                                ! call transform_dispatch(X, Y, Z)
    mov.l @r14, r4                         ! r4 = position.X (arg1, delay slot)
    mov.l   .L_rot_angle_z, r4             ! r4 = &z_rotation_angle (16-bit state)
    mov.l   .L_fn_rot_z, r3                ! r3 = &mat_rot_z
    jsr @r3                                ! call mat_rot_z(angle)
    mov.w @r4, r4                          ! r4 = z_rotation_angle value (delay slot)
    mov.l   .L_fn_rot_y, r3                ! r3 = &mat_rot_y
    jsr @r3                                ! call mat_rot_y(0) — identity Y rotation
    mov #0x0, r4                           ! r4 = 0x0 (no Y rotation, delay slot)
    mov.l   .L_fn_transform_mat, r3        ! r3 = &transform_matrix
    jsr @r3                                ! call transform_matrix(0) — base transform
    mov #0x0, r4                           ! r4 = 0x0 (no extra angle, delay slot)
    mov.l   .L_speed_counter, r2           ! r2 = &speed_counter (32-bit, WRAM High)
    mov #0x64, r3                          ! r3 = 0x64 (100 — threshold)
    mov.l @r2, r2                          ! r2 = speed_counter value
    cmp/ge r3, r2                          ! T = (speed_counter >= 100)?
    bf      .L_skip_extra_transform        ! if speed < 100, skip extra transform
    mov.w   DAT_06012586, r4               ! r4 = 0x1000 (large transform angle)
    mov.l   .L_fn_transform_mat, r3        ! r3 = &transform_matrix
    jsr @r3                                ! call transform_matrix(0x1000)
    nop                                    ! (delay slot)
.L_skip_extra_transform:
    mov.l   .L_chain_a_src, r5             ! r5 = &chain_a_source_data ptr
    mov.l   .L_obj_counter, r4             ! r4 = &obj_counter (car/object index)
    mov.l   .L_chain_a_table, r3           ! r3 = chain_a_dispatch_table base
    mov.l   .L_fn_chain_a, r2              ! r2 = &transform_chain_dispatch_A
    mov.l @r5, r5                          ! r5 = chain_a_source_data (arg2)
    mov.l @r4, r4                          ! r4 = obj_counter value
    add #-0x1, r4                          ! r4 = obj_counter - 1 (zero-based index)
    shll2 r4                               ! r4 *= 4 (word offset into table)
    add r3, r4                             ! r4 = &chain_a_table[obj_counter - 1]
    jsr @r2                                ! call chain_dispatch_A(table_entry, src)
    mov.l @r4, r4                          ! r4 = chain_a_table[obj_counter - 1] (delay slot)
    mov.l   .L_chain_b_src, r6             ! r6 = &chain_b_source_data ptr
    mov.l   .L_disp_mode, r5               ! r5 = &display_mode_selector (16-bit)
    mov.l   .L_obj_counter, r4             ! r4 = &obj_counter
    mov.l   .L_chain_b_table, r3           ! r3 = chain_b_dispatch_table base
    mov.l   .L_fn_chain_b, r2              ! r2 = &transform_chain_dispatch_B
    mov.l @r6, r6                          ! r6 = chain_b_source_data (arg3)
    mov.w @r5, r5                          ! r5 = display_mode value (arg2, 16-bit)
    mov.l @r4, r4                          ! r4 = obj_counter value
    add #-0x1, r4                          ! r4 = obj_counter - 1 (zero-based index)
    shll2 r4                               ! r4 *= 4 (word offset into table)
    add r3, r4                             ! r4 = &chain_b_table[obj_counter - 1]
    jsr @r2                                ! call chain_dispatch_B(table_entry, mode, src)
    mov.l @r4, r4                          ! r4 = chain_b_table[obj_counter - 1] (delay slot)
    lds.l @r15+, pr                        ! restore return address
    mov.l   .L_fn_post_cleanup, r3         ! r3 = &post_render_cleanup
    jmp @r3                                ! tail-call post-render cleanup
    mov.l @r15+, r14                       ! restore r14 (delay slot)

    .global DAT_06012586
DAT_06012586:
    .2byte  0x1000                         ! large transform angle (used when speed >= 100)
.L_fn_pre_transform:
    .4byte  sym_06026DBC                   ! per-object pre-transform setup
.L_fn_matrix_init:
    .4byte  sym_06026E0C                   ! matrix entry initialization
.L_position_vec:
    .4byte  sym_060788B4                   ! object position XYZ triplet (WRAM High)
.L_fn_transform_dispatch:
    .4byte  sym_06026E2E                   ! transform dispatch with XYZ position
.L_rot_angle_z:
    .4byte  sym_060788B2                   ! Z rotation angle state (16-bit, WRAM High)
.L_fn_rot_z:
    .4byte  mat_rot_z                      ! Z-axis rotation matrix function
.L_fn_rot_y:
    .4byte  mat_rot_y                      ! Y-axis rotation matrix function
.L_fn_transform_mat:
    .4byte  transform_matrix               ! apply transform matrix with angle param
.L_speed_counter:
    .4byte  sym_0607EBCC                   ! speed/animation counter (32-bit, WRAM High)
.L_chain_a_src:
    .4byte  sym_06063558                   ! chain A source data (object transform)
.L_obj_counter:
    .4byte  sym_0607EAD8                   ! object/car counter (1-based index)
.L_chain_a_table:
    .4byte  sym_0606354C                   ! chain A dispatch table (4 bytes per entry)
.L_fn_chain_a:
    .4byte  sym_06031D8C                   ! transform chain dispatch A function
.L_chain_b_src:
    .4byte  sym_06063554                   ! chain B source data (display transform)
.L_disp_mode:
    .4byte  sym_06089EA0                   ! display mode selector (16-bit, WRAM High)
.L_chain_b_table:
    .4byte  sym_06063544                   ! chain B dispatch table (4 bytes per entry)
.L_fn_chain_b:
    .4byte  sym_06031A28                   ! transform chain dispatch B function
.L_fn_post_cleanup:
    .4byte  sym_06026DF8                   ! post-render cleanup (tail-call target)
