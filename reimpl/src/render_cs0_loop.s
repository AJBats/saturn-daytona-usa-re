/* render_cs0_loop -- CS0 (Course Scenery 0) Object Rendering Loop
 * Translation unit: 0x0600B6A0 - 0x0600B914 (630 bytes)
 *
 * Iterates through the CS0 object table, rendering each active object.
 * For each visible object (flagged via 0x00E00000 mask):
 *   1. Push transform matrix (sym_06026DBC / mat_push)
 *   2. Apply XYZ translation from object struct
 *   3. Apply Y rotation (mat_rot_y) with +0x8000 offset
 *   4. Apply Z rotation (mat_rot_z), negated
 *   5. Apply secondary rotation (mat_rot_x), negated
 *   6. Branch on detail-level flags in object byte +1:
 *      - 0x40: close-range full detail path
 *      - 0x20: medium-range secondary detail path
 *      - 0x80: far-range tertiary path (includes sub-object renderer)
 *   7. Call distance check (r12 = sym_06031D8C) and render submit (r13 = sym_06031A28)
 *   8. Decrement render budget by 0x30 per object
 *
 * Register conventions:
 *   r8  = render budget counter ptr (sym_06089EDC)
 *   r10 = object iteration index (1..count)
 *   r11 = sprite index table (sym_06089E44)
 *   r12 = distance check function ptr (sym_06031D8C)
 *   r13 = render submission function ptr (sym_06031A28)
 *   r14 = current object base pointer (computed per iteration)
 *   r9  = LOD/sprite selector byte from sym_06047FC4
 *
 * Uses 4 car data structures (sym_060620D8..sym_060621D8) for
 * per-car scenery object association, with sub-pointers at
 * +0x18, +0x28, +0x2C, +0x30 for different render paths.
 *
 * Called from the scene rendering orchestrator (FUN_0600BFFC).
 */

    .section .text.FUN_0600B6A0


    .global render_cs0_loop
    .type render_cs0_loop, @function
render_cs0_loop:
    mov.l r14, @-r15                        ! save r14
    mov.l r13, @-r15                        ! save r13
    mov.l r12, @-r15                        ! save r12
    mov.l r11, @-r15                        ! save r11
    mov.l r10, @-r15                        ! save r10
    mov.l r9, @-r15                         ! save r9
    mov.l r8, @-r15                         ! save r8
    sts.l pr, @-r15                         ! save pr (return address)
    sts.l macl, @-r15                       ! save macl (used by mul.l)
    add #-0x44, r15                         ! allocate 0x44 bytes of stack locals
    mov.l   .L_render_budget_ptr, r8        ! r8 = &render_budget (sym_06089EDC)
    mov.l   .L_sprite_index_table, r11      ! r11 = sprite index table (sym_06089E44)
    mov.l   .L_distance_check_fn, r12       ! r12 = distance_check fn (sym_06031D8C)
    mov.l   .L_render_submit_fn, r13        ! r13 = render_submit fn (sym_06031A28)
    mov.l   .L_render_disabled_flag, r0     ! r0 = &render_disabled (sym_0607EAE0)
    mov.l @r0, r0                           ! r0 = *render_disabled
    tst r0, r0                              ! rendering disabled?
    bt      .L_render_enabled               ! if zero (enabled) -> start loop
    bra     .L_epilogue                     ! else -> skip everything, return
    nop                                     ! (delay slot)
    .4byte  sym_06031DF4                    /* (unreferenced pool: render submit B) */
    .4byte  sym_0608A52C                    /* (unreferenced pool: render budget B) */
.L_render_budget_ptr:
    .4byte  sym_06089EDC
.L_sprite_index_table:
    .4byte  sym_06089E44
.L_distance_check_fn:
    .4byte  sym_06031D8C
.L_render_submit_fn:
    .4byte  sym_06031A28
.L_render_disabled_flag:
    .4byte  sym_0607EAE0
.L_render_enabled:
    mov #0x1, r10                           ! r10 = 1 (starting object index)
    mov.l   .L_car3_data_base, r5          ! r5 = car3 base (sym_060621D8)
    mov r5, r3                              ! r3 = car3 base
    add #0x28, r3                           ! r3 = car3+0x28 (close-range dist ptr)
    mov.l r3, @(16, r15)                    ! sp[0x10] = &car3[+0x28]
    mov.l   .L_car1_data_base, r6          ! r6 = car1 base (sym_0606212C)
    mov r6, r2                              ! r2 = car1 base
    add #0x28, r2                           ! r2 = car1+0x28
    mov.l r2, @(8, r15)                     ! sp[0x08] = &car1[+0x28]
    mov.l   .L_car2_data_base, r4          ! r4 = car2 base (sym_06062180)
    mov r4, r3                              ! r3 = car2 base
    add #0x28, r3                           ! r3 = car2+0x28
    mov.l r3, @(4, r15)                     ! sp[0x04] = &car2[+0x28]
    mov r11, r2                             ! r2 = sprite_index_table
    add #0x4, r2                            ! r2 = sprite_index_table+0x4
    mov.l r2, @r15                          ! sp[0x00] = &sprite_table[+0x4]
    mov.l   .L_car0_data_base, r7          ! r7 = car0 base (sym_060620D8)
    mov r7, r3                              ! r3 = car0 base
    add #0x28, r3                           ! r3 = car0+0x28
    mov.l r3, @(12, r15)                    ! sp[0x0C] = &car0[+0x28]
    mov r5, r2                              ! r2 = car3 base
    add #0x2C, r2                           ! r2 = car3+0x2C (close-range sprite ptr)
    mov.l r2, @(36, r15)                    ! sp[0x24] = &car3[+0x2C]
    mov r6, r1                              ! r1 = car1 base
    add #0x2C, r1                           ! r1 = car1+0x2C
    mov.l r1, @(40, r15)                    ! sp[0x28] = &car1[+0x2C]
    mov r4, r3                              ! r3 = car2 base
    add #0x2C, r3                           ! r3 = car2+0x2C
    mov.l r3, @(44, r15)                    ! sp[0x2C] = &car2[+0x2C]
    mov r7, r2                              ! r2 = car0 base
    add #0x2C, r2                           ! r2 = car0+0x2C
    mov.l r2, @(48, r15)                    ! sp[0x30] = &car0[+0x2C]
    mov r5, r1                              ! r1 = car3 base
    add #0x30, r1                           ! r1 = car3+0x30 (medium-range dist ptr)
    mov.l r1, @(52, r15)                    ! sp[0x34] = &car3[+0x30]
    mov r6, r3                              ! r3 = car1 base
    add #0x30, r3                           ! r3 = car1+0x30
    mov.l r3, @(56, r15)                    ! sp[0x38] = &car1[+0x30]
    mov r4, r2                              ! r2 = car2 base
    add #0x30, r2                           ! r2 = car2+0x30
    mov.l r2, @(60, r15)                    ! sp[0x3C] = &car2[+0x30]
    mov r7, r1                              ! r1 = car0 base
    add #0x30, r1                           ! r1 = car0+0x30
    mov #0x40, r0                           ! r0 = 0x40 (offset for indexed store)
    mov.l r1, @(r0, r15)                    ! sp[0x40] = &car0[+0x30]
    add #0x18, r5                           ! r5 = car3+0x18 (far-range dist ptr)
    mov.l r5, @(20, r15)                    ! sp[0x14] = &car3[+0x18]
    add #0x18, r6                           ! r6 = car1+0x18
    mov.l r6, @(24, r15)                    ! sp[0x18] = &car1[+0x18]
    add #0x18, r4                           ! r4 = car2+0x18
    mov.l r4, @(28, r15)                    ! sp[0x1C] = &car2[+0x18]
    add #0x18, r7                           ! r7 = car0+0x18
    bra     .L_loop_check                   ! jump to loop condition check
    mov.l r7, @(32, r15)                    ! (delay) sp[0x20] = &car0[+0x18]
.L_car3_data_base:
    .4byte  sym_060621D8
.L_car1_data_base:
    .4byte  sym_0606212C
.L_car2_data_base:
    .4byte  sym_06062180
.L_car0_data_base:
    .4byte  sym_060620D8
.L_loop_body:
    mov.w   .L_obj_stride, r14              ! r14 = 0x0268 (object struct stride)
    mov.l   .L_obj_table_base, r3          ! r3 = obj_table (sym_06078900)
    mov.l   .L_visibility_mask, r1         ! r1 = 0x00E00000 (visibility flag mask)
    mul.l r14, r10                          ! macl = stride * index
    sts macl, r14                           ! r14 = byte offset into table
    add r3, r14                             ! r14 = &obj_table[index] (current object ptr)
    mov.l @r14, r2                          ! r2 = obj[0] (flags/status word)
    and r1, r2                              ! r2 = flags & 0x00E00000 (isolate visibility)
    tst r2, r2                              ! visible?
    bf      .L_obj_visible                  ! if nonzero (visible) -> process object
    bra     .L_next_object                  ! else -> skip to next object
    nop                                     ! (delay slot)
.L_obj_visible:
    mov.l   .L_mat_push_fn, r3             ! r3 = mat_push (sym_06026DBC)
    jsr @r3                                 ! call mat_push — push current matrix
    nop                                     ! (delay slot)
    mov.l @(24, r14), r6                    ! r6 = obj[+0x18] (Z position)
    mov.l @(20, r14), r5                    ! r5 = obj[+0x14] (Y position)
    mov.w   DAT_0600b83a, r0               ! r0 = 0x01B4 (offset to extra Y term)
    mov.l   .L_mat_xform_trans_fn, r3     ! r3 = mat_xform_trans (sym_06026E2E)
    mov.l @(r0, r14), r2                    ! r2 = obj[+0x1B4] (Y correction term)
    add r2, r5                              ! r5 = Y + correction
    jsr @r3                                 ! call mat_xform_trans(r4=X, r5=Y+corr, r6=Z)
    mov.l @(16, r14), r4                    ! (delay) r4 = obj[+0x10] (X position)
    mov.l @(32, r14), r4                    ! r4 = obj[+0x20] (Y rotation angle)
    mov.l   .L_fp_half, r2                 ! r2 = 0x00008000 (0.5 fixed-point)
    mov.l   .L_mat_rot_y_fn, r3           ! r3 = mat_rot_y
    jsr @r3                                 ! call mat_rot_y(r4 = angle + 0.5)
    add r2, r4                              ! (delay) r4 = Y_rot + 0x8000
    mov.l @(36, r14), r4                    ! r4 = obj[+0x24] (Z rotation angle)
    mov.l   .L_mat_rot_z_fn, r3           ! r3 = mat_rot_z
    jsr @r3                                 ! call mat_rot_z(r4 = -Z_rot)
    neg r4, r4                              ! (delay) r4 = -Z_rot (negate Z angle)
    mov.l @(28, r14), r4                    ! r4 = obj[+0x1C] (secondary rotation)
    mov.l   .L_mat_rot_x_fn, r3    ! r3 = mat_rot_x
    jsr @r3                                 ! call mat_rot_x(r4 = -secondary_rot)
    neg r4, r4                              ! (delay) r4 = -secondary_rot
    mov.w   DAT_0600b83c, r0               ! r0 = 0x01BC (collision field A offset)
    mov.l @(r0, r14), r2                    ! r2 = obj[+0x1BC] (collision field A)
    mov.w   .L_off_collision_b, r0         ! r0 = 0x00B8 (collision field B offset)
    mov.l @(r0, r14), r3                    ! r3 = obj[+0xB8] (collision field B)
    add r3, r2                              ! r2 = collision_A + collision_B
    tst r2, r2                              ! any collision interaction?
    bt      .L_check_detail_flags           ! if zero -> skip extra rotations
    mov.w   DAT_0600b840, r0               ! r0 = 0x01D8 (collision rot offset)
    mov.l @(r0, r14), r4                    ! r4 = obj[+0x1D8] (collision Y rotation)
    add #-0xC, r0                           ! r0 = 0x01CC
    neg r4, r4                              ! r4 = -collision_Y_rot
    mov.l @(r0, r14), r3                    ! r3 = obj[+0x1CC] (collision base rot)
    sub r3, r4                              ! r4 = -collision_Y_rot - base_rot
    mov.l   .L_mat_rot_y_fn, r3           ! r3 = mat_rot_y
    jsr @r3                                 ! call mat_rot_y(r4) — apply collision Y rot
    nop                                     ! (delay slot)
    mov.w   .L_off_rot_alt_y, r0          ! r0 = 0x01D0 (alt Y rot offset)
    mov.l   .L_mat_rot_z_fn, r3           ! r3 = mat_rot_z
    mov.l @(r0, r14), r4                    ! r4 = obj[+0x1D0] (alt Z rotation)
    jsr @r3                                 ! call mat_rot_z(r4 = -alt_Z_rot)
    neg r4, r4                              ! (delay) r4 = -alt_Z_rot
    mov.w   .L_off_rot_alt_z, r0          ! r0 = 0x01C8 (alt secondary rot offset)
    mov.l   .L_mat_rot_x_fn, r3    ! r3 = mat_rot_x
    mov.l @(r0, r14), r4                    ! r4 = obj[+0x1C8] (alt secondary rot)
    jsr @r3                                 ! call mat_rot_x(r4 = -alt_rot)
    neg r4, r4                              ! (delay) r4 = -alt_rot
.L_check_detail_flags:
    mov.l   .L_lod_selector_table, r9      ! r9 = LOD selector table (sym_06047FC4)
    mov r14, r0                             ! r0 = current object ptr
    add r10, r9                             ! r9 = &lod_table[index]
    mov.b @(1, r0), r0                      ! r0 = obj byte[+1] (detail level flags)
    mov.b @r9, r9                           ! r9 = lod_table[index] (sprite selector)
    tst #0x40, r0                           ! test close-range flag (bit 6)?
    bf/s    .L_detail_close                 ! if set -> close-range detail path
    extu.b r9, r9                           ! (delay) r9 = zero-extend sprite selector
    mov.l   .L_state_flag_a, r0            ! r0 = &state_flag_A (sym_06063E1C)
    mov.l   .L_state_flag_b, r3            ! r3 = &state_flag_B (sym_06063E20)
    mov.l @r0, r0                           ! r0 = *state_flag_A
    mov.l @r3, r3                           ! r3 = *state_flag_B
    add r3, r0                              ! r0 = state_A + state_B
    cmp/eq #0x8, r0                         ! sum == 0x8? (special condition)
    bf      .L_check_medium_detail          ! if not 8 -> check medium detail instead
.L_detail_close:
    mov.w   DAT_0600b83c, r0               ! r0 = 0x01BC (collision field A offset)
    mov.l @(r0, r14), r3                    ! r3 = obj[+0x1BC] (collision field A)
    cmp/pl r3                               ! collision_A > 0?
    bt      .L_close_secondary              ! if positive -> skip primary render pass
    mov.l @(16, r15), r5                    ! r5 = sp[0x10] = &car3[+0x28]
    mov.l @(8, r15), r4                     ! r4 = sp[0x08] = &car1[+0x28]
    mov.l @r5, r5                           ! r5 = car3[+0x28] (dist param A)
    jsr @r12                                ! call distance_check(r4, r5)
    mov.l @r4, r4                           ! (delay) r4 = car1[+0x28] (dist param B)
    mov.l @(4, r15), r6                     ! r6 = sp[0x04] = &car2[+0x28]
    mov.l @r15, r5                          ! r5 = sp[0x00] = &sprite_table[+0x4]
    mov.l @(12, r15), r4                    ! r4 = sp[0x0C] = &car0[+0x28]
    mov.l @r6, r6                           ! r6 = car2[+0x28] (sprite param A)
    mov.w @r5, r5                           ! r5 = sprite_table[+0x4] (sprite index)
    jsr @r13                                ! call render_submit(r4, r5, r6)
    mov.l @r4, r4                           ! (delay) r4 = car0[+0x28] (sprite param B)
.L_close_secondary:
    mov.l @(36, r15), r5                    ! r5 = sp[0x24] = &car3[+0x2C]
    mov.l @(40, r15), r4                    ! r4 = sp[0x28] = &car1[+0x2C]
    mov.l @r5, r5                           ! r5 = car3[+0x2C] (dist param A)
    jsr @r12                                ! call distance_check(r4, r5)
    mov.l @r4, r4                           ! (delay) r4 = car1[+0x2C] (dist param B)
    mov.l @(44, r15), r6                    ! r6 = sp[0x2C] = &car2[+0x2C]
    mov r9, r0                              ! r0 = sprite selector byte
    mov.l @(48, r15), r4                    ! r4 = sp[0x30] = &car0[+0x2C]
    mov.l @r6, r6                           ! r6 = car2[+0x2C] (sprite param A)
    shll r0                                 ! r0 = selector * 2 (word index)
    mov.w @(r0, r11), r5                    ! r5 = sprite_table[selector] (sprite ID)
    jsr @r13                                ! call render_submit(r4, r5, r6)
    mov.l @r4, r4                           ! (delay) r4 = car0[+0x2C] (sprite param B)
    bra     .L_decrement_budget             ! done with close-range -> decrement budget
    nop                                     ! (delay slot)
.L_obj_stride:
    .2byte  0x0268

    .global DAT_0600b83a
DAT_0600b83a:
    .2byte  0x01B4

    .global DAT_0600b83c
DAT_0600b83c:
    .2byte  0x01BC
.L_off_collision_b:
    .2byte  0x00B8

    .global DAT_0600b840
DAT_0600b840:
    .2byte  0x01D8
.L_off_rot_alt_y:
    .2byte  0x01D0
.L_off_rot_alt_z:
    .2byte  0x01C8
    .2byte  0xFFFF
.L_obj_table_base:
    .4byte  sym_06078900
.L_visibility_mask:
    .4byte  0x00E00000
.L_mat_push_fn:
    .4byte  sym_06026DBC
.L_mat_xform_trans_fn:
    .4byte  sym_06026E2E
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_mat_rot_y_fn:
    .4byte  mat_rot_y
.L_mat_rot_z_fn:
    .4byte  mat_rot_z
.L_mat_rot_x_fn:
    .4byte  mat_rot_x
.L_lod_selector_table:
    .4byte  sym_06047FC4
.L_state_flag_a:
    .4byte  sym_06063E1C
.L_state_flag_b:
    .4byte  sym_06063E20
.L_check_medium_detail:
    mov r14, r0                             ! r0 = current object ptr
    mov.b @(1, r0), r0                      ! r0 = obj byte[+1] (detail flags)
    tst #0x20, r0                           ! test medium-range flag (bit 5)?
    bt      .L_check_far_detail             ! if not set -> check far-range
    mov.l @(52, r15), r5                    ! r5 = sp[0x34] = &car3[+0x30]
    mov.l @(56, r15), r4                    ! r4 = sp[0x38] = &car1[+0x30]
    mov.l @r5, r5                           ! r5 = car3[+0x30] (dist param A)
    jsr @r12                                ! call distance_check(r4, r5)
    mov.l @r4, r4                           ! (delay) r4 = car1[+0x30] (dist param B)
    mov.l @(60, r15), r6                    ! r6 = sp[0x3C] = &car2[+0x30]
    mov r9, r0                              ! r0 = sprite selector byte
    mov.l @r6, r6                           ! r6 = car2[+0x30] (sprite param A)
    shll r0                                 ! r0 = selector * 2 (word index)
    mov.w @(r0, r11), r5                    ! r5 = sprite_table[selector] (sprite ID)
    mov #0x40, r0                           ! r0 = 0x40 (stack offset for indexed load)
    mov.l @(r0, r15), r4                    ! r4 = sp[0x40] = &car0[+0x30]
    jsr @r13                                ! call render_submit(r4, r5, r6)
    mov.l @r4, r4                           ! (delay) r4 = car0[+0x30] (sprite param B)
    bra     .L_decrement_budget             ! done with medium-range -> decrement budget
    nop                                     ! (delay slot)
.L_check_far_detail:
    mov r14, r0                             ! r0 = current object ptr
    mov.b @(1, r0), r0                      ! r0 = obj byte[+1] (detail flags)
    tst #0x80, r0                           ! test far-range flag (bit 7)?
    bt      .L_decrement_budget             ! if not set -> no detail path, skip
    mov.w   DAT_0600b90e, r0               ! r0 = 0x01BC (collision field offset)
    mov.l @(r0, r14), r3                    ! r3 = obj[+0x1BC] (collision field A)
    cmp/pl r3                               ! collision_A > 0?
    bt      .L_far_render_pass              ! if positive -> skip primary render
    mov.l @(16, r15), r5                    ! r5 = sp[0x10] = &car3[+0x28]
    mov.l @(8, r15), r4                     ! r4 = sp[0x08] = &car1[+0x28]
    mov.l @r5, r5                           ! r5 = car3[+0x28] (dist param A)
    jsr @r12                                ! call distance_check(r4, r5)
    mov.l @r4, r4                           ! (delay) r4 = car1[+0x28] (dist param B)
    mov.l @(4, r15), r6                     ! r6 = sp[0x04] = &car2[+0x28]
    mov.l @r15, r5                          ! r5 = sp[0x00] = &sprite_table[+0x4]
    mov.l @(12, r15), r4                    ! r4 = sp[0x0C] = &car0[+0x28]
    mov.l @r6, r6                           ! r6 = car2[+0x28] (sprite param A)
    mov.w @r5, r5                           ! r5 = sprite_table[+0x4] (sprite index)
    jsr @r13                                ! call render_submit(r4, r5, r6)
    mov.l @r4, r4                           ! (delay) r4 = car0[+0x28] (sprite param B)
.L_far_render_pass:
    mov #0x1, r5                            ! r5 = 1 (sub-object index)
    .byte   0xB8, 0xE7    /* bsr 0x0600AA98 (external) — scene_obj_type_A renderer */
    mov r14, r4                             ! (delay) r4 = current object ptr
    mov.l @(20, r15), r5                    ! r5 = sp[0x14] = &car3[+0x18]
    mov.l @(24, r15), r4                    ! r4 = sp[0x18] = &car1[+0x18]
    mov.l @r5, r5                           ! r5 = car3[+0x18] (dist param A)
    jsr @r12                                ! call distance_check(r4, r5)
    mov.l @r4, r4                           ! (delay) r4 = car1[+0x18] (dist param B)
    mov.l @(28, r15), r6                    ! r6 = sp[0x1C] = &car2[+0x18]
    mov r9, r0                              ! r0 = sprite selector byte
    mov.l @(32, r15), r4                    ! r4 = sp[0x20] = &car0[+0x18]
    mov.l @r6, r6                           ! r6 = car2[+0x18] (sprite param A)
    shll r0                                 ! r0 = selector * 2 (word index)
    mov.w @(r0, r11), r5                    ! r5 = sprite_table[selector] (sprite ID)
    jsr @r13                                ! call render_submit(r4, r5, r6)
    mov.l @r4, r4                           ! (delay) r4 = car0[+0x18] (sprite param B)
.L_decrement_budget:
    mov.l @r8, r3                           ! r3 = *render_budget
    add #-0x30, r3                          ! r3 -= 0x30 (cost per object = 48)
    mov.l r3, @r8                           ! *render_budget = r3 (updated)
.L_next_object:
    add #0x1, r10                           ! r10++ (advance to next object index)
.L_loop_check:
    mov.l   .L_obj_count_ptr, r2           ! r2 = &obj_count (sym_06078664)
    mov.w @r2, r2                           ! r2 = obj_count (16-bit)
    cmp/hs r2, r10                          ! index >= count?
    bt      .L_epilogue                     ! if done -> exit loop
    bra     .L_loop_body                    ! else -> process next object
    nop                                     ! (delay slot)
.L_epilogue:
    add #0x44, r15                          ! deallocate 0x44 bytes of stack locals
    lds.l @r15+, macl                       ! restore macl
    lds.l @r15+, pr                         ! restore pr (return address)
    mov.l @r15+, r8                         ! restore r8
    mov.l @r15+, r9                         ! restore r9
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! (delay) restore r14

    .global DAT_0600b90e
DAT_0600b90e:
    .2byte  0x01BC
.L_obj_count_ptr:
    .4byte  sym_06078664
