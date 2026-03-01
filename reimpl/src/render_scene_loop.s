/* render_scene_loop -- Main scene object rendering loop
 * Translation unit: 0x0600B914 - 0x0600BB94
 *
 * Core scene traversal function (530 bytes, 265 insns).
 * Iterates over all scene objects and renders them at the appropriate
 * detail level (LOD).  For each visible object:
 *   1. Compute object address: index * 0x268 + obj_array_base
 *   2. Check visibility flag (obj[0] & 0x00E00000)
 *   3. Set transform matrix and apply rotations (X, Y+0.5, -Z, -pitch)
 *   4. Select LOD path based on byte flags:
 *        0x40 = close range  (full detail)
 *        0x20 = medium range (reduced detail)
 *        0x80 = far range    (sub-call to type-B renderer)
 *   5. Submit to render via distance-check + sprite-submission fn pairs
 *   6. Decrement render budget by 0x30 (48) per object
 *
 * Register plan:
 *   r8  = render budget counter ptr   (sym_0608A52C)
 *   r10 = iteration index
 *   r11 = sprite index table           (sym_06089E44)
 *   r12 = fn ptr: distance check       (sym_06032158)
 *   r13 = fn ptr: render submission     (sym_06031DF4)
 *
 * Four car data structure bases are preloaded to build per-car
 * scenery-object association tables on the stack:
 *   car0 = sym_060621D8   car1 = sym_0606212C
 *   car2 = sym_06062180   car3 = sym_060620D8
 */

    .section .text.FUN_0600B914


    .global render_scene_loop
    .type render_scene_loop, @function
render_scene_loop:
    mov.l r14, @-r15                        ! save r14
    mov.l r13, @-r15                        ! save r13
    mov.l r12, @-r15                        ! save r12
    mov.l r11, @-r15                        ! save r11
    mov.l r10, @-r15                        ! save r10
    mov.l r9, @-r15                         ! save r9
    mov.l r8, @-r15                         ! save r8
    sts.l pr, @-r15                         ! save return address
    sts.l macl, @-r15                       ! save multiply accumulator
    add #-0x44, r15                         ! allocate 0x44 bytes of stack frame
    mov.l   .L_render_budget_ptr, r8        ! r8 = &render_budget
    mov.l   .L_sprite_index_table, r11      ! r11 = sprite_index_table base
    mov.l   .L_fn_distance_check, r12       ! r12 = fn: distance_check
    mov.l   .L_fn_render_submit, r13        ! r13 = fn: render_submit
    mov.l   .L_render_disable_flag, r0      ! r0 = &render_disable_flag
    mov.l @r0, r0                           ! r0 = *render_disable_flag
    tst r0, r0                              ! rendering disabled?
    bt      .L_render_enabled               ! if flag == 0, proceed
    bra     .L_epilogue                     ! else early exit
    nop                                     ! (delay slot)
.L_render_enabled:
    mov.l   .L_iter_start_count, r10        ! r10 = &iter_start_count
    mov.w @r10, r10                         ! r10 = starting object index
    mov.l   .L_car0_data_base, r5           ! r5 = car0 base (sym_060621D8)
    mov r5, r3                              ! r3 = car0 base
    add #0x28, r3                           ! r3 = &car0[+0x28] (close dist ptr A)
    mov.l r3, @(16, r15)                    ! sp[16] = &car0.close_dist_a
    mov.l   .L_car1_data_base, r6           ! r6 = car1 base (sym_0606212C)
    mov r6, r2                              ! r2 = car1 base
    add #0x28, r2                           ! r2 = &car1[+0x28]
    mov.l r2, @(8, r15)                     ! sp[8] = &car1.close_dist_a
    mov.l   .L_car2_data_base, r4           ! r4 = car2 base (sym_06062180)
    mov r4, r3                              ! r3 = car2 base
    add #0x28, r3                           ! r3 = &car2[+0x28]
    mov.l r3, @(4, r15)                     ! sp[4] = &car2.close_dist_a
    mov r11, r2                             ! r2 = sprite_index_table
    add #0x4, r2                            ! r2 = &sprite_index_table[+0x4]
    mov.l r2, @r15                          ! sp[0] = &sprite_idx_table[+0x4]
    mov.l   .L_car3_data_base, r7           ! r7 = car3 base (sym_060620D8)
    mov r7, r3                              ! r3 = car3 base
    add #0x28, r3                           ! r3 = &car3[+0x28]
    mov.l r3, @(12, r15)                    ! sp[12] = &car3.close_dist_a
    mov r5, r2                              ! r2 = car0 base
    add #0x2C, r2                           ! r2 = &car0[+0x2C] (close dist ptr B)
    mov.l r2, @(36, r15)                    ! sp[36] = &car0.close_dist_b
    mov r6, r1                              ! r1 = car1 base
    add #0x2C, r1                           ! r1 = &car1[+0x2C]
    mov.l r1, @(40, r15)                    ! sp[40] = &car1.close_dist_b
    mov r4, r3                              ! r3 = car2 base
    add #0x2C, r3                           ! r3 = &car2[+0x2C]
    mov.l r3, @(44, r15)                    ! sp[44] = &car2.close_dist_b
    mov r7, r2                              ! r2 = car3 base
    add #0x2C, r2                           ! r2 = &car3[+0x2C]
    mov.l r2, @(48, r15)                    ! sp[48] = &car3.close_dist_b
    mov r5, r1                              ! r1 = car0 base
    add #0x30, r1                           ! r1 = &car0[+0x30] (far dist ptr)
    mov.l r1, @(52, r15)                    ! sp[52] = &car0.far_dist
    mov r6, r3                              ! r3 = car1 base
    add #0x30, r3                           ! r3 = &car1[+0x30]
    mov.l r3, @(56, r15)                    ! sp[56] = &car1.far_dist
    mov r4, r2                              ! r2 = car2 base
    add #0x30, r2                           ! r2 = &car2[+0x30]
    mov.l r2, @(60, r15)                    ! sp[60] = &car2.far_dist
    mov r7, r1                              ! r1 = car3 base
    add #0x30, r1                           ! r1 = &car3[+0x30]
    mov #0x40, r0                           ! r0 = 0x40 offset for sp access
    mov.l r1, @(r0, r15)                    ! sp[64] = &car3.far_dist
    add #0x18, r5                           ! r5 = &car0[+0x18] (medium dist ptr)
    mov.l r5, @(20, r15)                    ! sp[20] = &car0.med_dist
    add #0x18, r6                           ! r6 = &car1[+0x18]
    mov.l r6, @(24, r15)                    ! sp[24] = &car1.med_dist
    add #0x18, r4                           ! r4 = &car2[+0x18]
    mov.l r4, @(28, r15)                    ! sp[28] = &car2.med_dist
    add #0x18, r7                           ! r7 = &car3[+0x18]
    bra     .L_loop_cond                    ! jump to loop condition check
    mov.l r7, @(32, r15)                    ! (delay) sp[32] = &car3.med_dist
    .2byte  0xFFFF                          ! padding
.L_render_budget_ptr:                       ! render budget counter (decremented per obj)
    .4byte  sym_0608A52C
.L_sprite_index_table:                      ! indexed sprite table for LOD selection
    .4byte  sym_06089E44
.L_fn_distance_check:                       ! fn: distance/visibility check
    .4byte  sym_06032158
.L_fn_render_submit:                        ! fn: render submission
    .4byte  sym_06031DF4
.L_render_disable_flag:                     ! nonzero = skip all rendering
    .4byte  sym_0607EAE0
.L_iter_start_count:                        ! starting object index (halfword)
    .4byte  sym_06078664
.L_car0_data_base:                          ! car 0 (player) structure base
    .4byte  sym_060621D8
.L_car1_data_base:                          ! car 1 structure base
    .4byte  sym_0606212C
.L_car2_data_base:                          ! car 2 structure base
    .4byte  sym_06062180
.L_car3_data_base:                          ! car 3 structure base
    .4byte  sym_060620D8
.L_loop_body:
    mov.w   .L_obj_stride, r14              ! r14 = 0x268 (object struct stride)
    mov.l   .L_obj_array_base, r3           ! r3 = obj_array base
    mov.l   .L_visibility_mask, r1          ! r1 = 0x00E00000 (visibility bitmask)
    mul.l r14, r10                          ! macl = stride * index
    sts macl, r14                           ! r14 = byte offset into array
    add r3, r14                             ! r14 = &obj[index] (current object ptr)
    mov.l @r14, r2                          ! r2 = obj[0] (status/flags word)
    and r1, r2                              ! r2 = flags & 0x00E00000
    tst r2, r2                              ! any visibility bits set?
    bf      .L_obj_visible                  ! yes -> process this object
    bra     .L_next_object                  ! no -> skip to next
    nop                                     ! (delay slot)
.L_obj_visible:
    mov.l   .L_fn_set_transform, r3         ! r3 = fn: set_mat_rot_x
    jsr @r3                                 ! call set_mat_rot_x()
    nop                                     ! (delay slot)
    mov.l @(24, r14), r6                    ! r6 = obj[+0x18] (rotation Z)
    mov.l @(20, r14), r5                    ! r5 = obj[+0x14] (rotation X base)
    mov.w   DAT_0600bab2, r0                ! r0 = 0x01B4 (offset to addtl X rot)
    mov.l   .L_fn_rotate_x, r3             ! r3 = fn: rotate_x
    mov.l @(r0, r14), r2                    ! r2 = obj[+0x1B4] (additional X rotation)
    add r2, r5                              ! r5 = total X rotation
    jsr @r3                                 ! call rotate_x(r4=obj[+0x10], r5, r6)
    mov.l @(16, r14), r4                    ! (delay) r4 = obj[+0x10] (translation)
    mov.l @(32, r14), r4                    ! r4 = obj[+0x20] (heading/Y rotation)
    mov.l   .L_fp_half, r2                  ! r2 = 0x8000 (0.5 in 16.16 fixed-point)
    mov.l   .L_fn_rotate_xy, r3            ! r3 = fn: mat_rot_xy_b
    jsr @r3                                 ! call mat_rot_xy_b(r4 = heading + 0.5)
    add r2, r4                              ! (delay) r4 = heading + 0.5
    mov.l @(36, r14), r4                    ! r4 = obj[+0x24] (Z rotation)
    mov.l   .L_fn_rotate_yz, r3            ! r3 = fn: mat_rot_yz_b
    jsr @r3                                 ! call mat_rot_yz_b(r4 = -Z_rot)
    neg r4, r4                              ! (delay) r4 = -Z_rot
    mov.l @(28, r14), r4                    ! r4 = obj[+0x1C] (pitch)
    mov.l   .L_fn_rotate_xz, r3            ! r3 = fn: mat_rot_xz_b
    jsr @r3                                 ! call mat_rot_xz_b(r4 = -pitch)
    neg r4, r4                              ! (delay) r4 = -pitch
    mov.w   DAT_0600bab4, r0                ! r0 = 0x01BC (offset to distance sign)
    mov.l @(r0, r14), r2                    ! r2 = obj[+0x1BC] (distance sign A)
    mov.w   .L_off_extra_rot_count, r0      ! r0 = 0x00B8 (offset to extra rot count)
    mov.l @(r0, r14), r3                    ! r3 = obj[+0xB8] (extra rotation count)
    add r3, r2                              ! r2 = dist_sign + extra_rot_count
    tst r2, r2                              ! any extra rotations needed?
    bt      .L_check_lod_flags              ! if zero, skip extra rotations
    mov.w   DAT_0600bab8, r0                ! r0 = 0x01D8 (offset to extra heading)
    mov.l @(r0, r14), r4                    ! r4 = obj[+0x1D8] (extra heading)
    add #-0xC, r0                           ! r0 = 0x01CC (offset to heading base)
    neg r4, r4                              ! r4 = -extra_heading
    mov.l @(r0, r14), r3                    ! r3 = obj[+0x1CC] (heading base)
    sub r3, r4                              ! r4 = -extra_heading - heading_base
    mov.l   .L_fn_rotate_xy, r3            ! r3 = fn: mat_rot_xy_b
    jsr @r3                                 ! call mat_rot_xy_b(r4)
    nop                                     ! (delay slot)
    mov.w   .L_off_extra_rot_y, r0          ! r0 = 0x01D0 (offset to extra Y rot)
    mov.l   .L_fn_rotate_yz, r3            ! r3 = fn: mat_rot_yz_b
    mov.l @(r0, r14), r4                    ! r4 = obj[+0x1D0] (extra Y rotation)
    jsr @r3                                 ! call mat_rot_yz_b(r4 = -extra_Y_rot)
    neg r4, r4                              ! (delay) r4 = -extra_Y_rot
    mov.w   .L_off_extra_rot_pitch, r0      ! r0 = 0x01C8 (offset to extra pitch)
    mov.l   .L_fn_rotate_xz, r3            ! r3 = fn: mat_rot_xz_b
    mov.l @(r0, r14), r4                    ! r4 = obj[+0x1C8] (extra pitch)
    jsr @r3                                 ! call mat_rot_xz_b(r4 = -extra_pitch)
    neg r4, r4                              ! (delay) r4 = -extra_pitch
.L_check_lod_flags:
    mov.l   .L_lod_select_table, r9         ! r9 = lod_select_table base
    mov r14, r0                             ! r0 = current object ptr
    add r10, r9                             ! r9 = &lod_table[index]
    mov.b @(1, r0), r0                      ! r0 = obj byte[1] (LOD flag byte)
    mov.b @r9, r9                           ! r9 = lod_table[index] (sprite idx)
    tst #0x40, r0                           ! close-range flag set?
    bf/s    .L_lod_close                    ! yes -> close-range LOD path
    extu.b r9, r9                           ! (delay) r9 = zero-extend sprite idx
    mov.l   .L_scene_state_a, r0            ! r0 = &scene_state_a
    mov.l   .L_scene_state_b, r3            ! r3 = &scene_state_b
    mov.l @r0, r0                           ! r0 = scene_state_a
    mov.l @r3, r3                           ! r3 = scene_state_b
    add r3, r0                              ! r0 = state_a + state_b
    cmp/eq #0x8, r0                         ! combined state == 8?
    bf      .L_check_lod_medium             ! no -> try medium-range path
.L_lod_close:
    mov.w   DAT_0600bab4, r0                ! r0 = 0x01BC (distance sign offset)
    mov.l @(r0, r14), r3                    ! r3 = obj[+0x1BC] (distance sign)
    cmp/pl r3                               ! distance > 0?
    bt      .L_lod_close_secondary          ! yes -> skip primary render, do secondary
    mov.l @(16, r15), r5                    ! r5 = &car0.close_dist_a
    mov.l @(8, r15), r4                     ! r4 = &car1.close_dist_a
    mov.l @r5, r5                           ! r5 = car0.close_dist_a (deref)
    jsr @r12                                ! call distance_check(r4, r5)
    mov.l @r4, r4                           ! (delay) r4 = car1.close_dist_a
    mov.l @(4, r15), r6                     ! r6 = &car2.close_dist_a
    mov.l @r15, r5                          ! r5 = &sprite_idx_table[+4]
    mov.l @(12, r15), r4                    ! r4 = &car3.close_dist_a
    mov.l @r6, r6                           ! r6 = car2.close_dist_a
    mov.w @r5, r5                           ! r5 = sprite_idx_table[+4] (halfword)
    extu.w r5, r5                           ! r5 = zero-extend to 32-bit
    jsr @r13                                ! call render_submit(r4, r5, r6)
    mov.l @r4, r4                           ! (delay) r4 = car3.close_dist_a
.L_lod_close_secondary:
    mov.l @(36, r15), r5                    ! r5 = &car0.close_dist_b
    mov.l @(40, r15), r4                    ! r4 = &car1.close_dist_b
    mov.l @r5, r5                           ! r5 = car0.close_dist_b (deref)
    jsr @r12                                ! call distance_check(r4, r5)
    mov.l @r4, r4                           ! (delay) r4 = car1.close_dist_b
    mov r9, r0                              ! r0 = sprite index from LOD table
    mov.l @(48, r15), r4                    ! r4 = &car3.close_dist_b
    mov.l @(44, r15), r6                    ! r6 = &car2.close_dist_b
    shll r0                                 ! r0 *= 2 (halfword index to byte offset)
    mov.l @r6, r6                           ! r6 = car2.close_dist_b
    mov.w @(r0, r11), r5                    ! r5 = sprite_table[lod_idx] (halfword)
    extu.w r5, r5                           ! r5 = zero-extend sprite ID
    jsr @r13                                ! call render_submit(r4, r5, r6)
    mov.l @r4, r4                           ! (delay) r4 = car3.close_dist_b
    bra     .L_decrement_budget             ! done with close LOD -> decrement budget
    nop                                     ! (delay slot)
.L_obj_stride:                              ! object struct size
    .2byte  0x0268

    .global DAT_0600bab2
DAT_0600bab2:                               ! offset: additional X rotation
    .2byte  0x01B4

    .global DAT_0600bab4
DAT_0600bab4:                               ! offset: distance sign word
    .2byte  0x01BC
.L_off_extra_rot_count:                     ! offset: extra rotation count
    .2byte  0x00B8

    .global DAT_0600bab8
DAT_0600bab8:                               ! offset: extra heading value
    .2byte  0x01D8
.L_off_extra_rot_y:                         ! offset: extra Y rotation
    .2byte  0x01D0
.L_off_extra_rot_pitch:                     ! offset: extra pitch rotation
    .2byte  0x01C8
    .2byte  0xFFFF                          ! padding
.L_obj_array_base:                          ! scene object array base
    .4byte  sym_06078900
.L_visibility_mask:                         ! visibility test bitmask
    .4byte  0x00E00000
.L_fn_set_transform:                        ! fn: set transform matrix
    .4byte  sym_06027080
.L_fn_rotate_x:                             ! fn: rotate X axis
    .4byte  sym_060270F2
.L_fp_half:                                 ! 0.5 in 16.16 fixed-point
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_fn_rotate_xy:                            ! fn: mat_rot_xy_b
    .4byte  mat_rot_xy_b
.L_fn_rotate_yz:                            ! fn: mat_rot_yz_b
    .4byte  mat_rot_yz_b
.L_fn_rotate_xz:                            ! fn: mat_rot_xz_b
    .4byte  mat_rot_xz_b
.L_lod_select_table:                        ! per-object LOD sprite index table
    .4byte  sym_06047FC4
.L_scene_state_a:                           ! scene state counter A
    .4byte  sym_06063E1C
.L_scene_state_b:                           ! scene state counter B
    .4byte  sym_06063E20
.L_check_lod_medium:
    mov r14, r0                             ! r0 = current object ptr
    mov.b @(1, r0), r0                      ! r0 = obj byte[1] (LOD flags)
    tst #0x20, r0                           ! medium-range flag set?
    bt      .L_check_lod_far                ! no -> try far-range path
    mov.l @(52, r15), r5                    ! r5 = &car0.far_dist
    mov.l @(56, r15), r4                    ! r4 = &car1.far_dist
    mov.l @r5, r5                           ! r5 = car0.far_dist (deref)
    jsr @r12                                ! call distance_check(r4, r5)
    mov.l @r4, r4                           ! (delay) r4 = car1.far_dist
    mov.l @(60, r15), r6                    ! r6 = &car2.far_dist
    mov r9, r0                              ! r0 = sprite index from LOD table
    mov.l @r6, r6                           ! r6 = car2.far_dist
    shll r0                                 ! r0 *= 2 (halfword offset)
    mov.w @(r0, r11), r5                    ! r5 = sprite_table[lod_idx]
    mov #0x40, r0                           ! r0 = 0x40 (stack offset for sp[64])
    extu.w r5, r5                           ! r5 = zero-extend sprite ID
    mov.l @(r0, r15), r4                    ! r4 = &car3.far_dist
    jsr @r13                                ! call render_submit(r4, r5, r6)
    mov.l @r4, r4                           ! (delay) r4 = car3.far_dist
    bra     .L_decrement_budget             ! done with medium LOD -> decrement budget
    nop                                     ! (delay slot)
.L_check_lod_far:
    mov r14, r0                             ! r0 = current object ptr
    mov.b @(1, r0), r0                      ! r0 = obj byte[1] (LOD flags)
    tst #0x80, r0                           ! far-range flag set?
    bt      .L_decrement_budget             ! no -> skip rendering entirely
    mov.w   .L_off_dist_sign_b, r0          ! r0 = 0x01BC (distance sign offset)
    mov.l @(r0, r14), r3                    ! r3 = obj[+0x1BC] (distance sign)
    cmp/pl r3                               ! distance > 0?
    bt      .L_lod_far_render               ! yes -> skip primary, go to type-B render
    mov.l @(16, r15), r5                    ! r5 = &car0.close_dist_a
    mov.l @(8, r15), r4                     ! r4 = &car1.close_dist_a
    mov.l @r5, r5                           ! r5 = car0.close_dist_a (deref)
    jsr @r12                                ! call distance_check(r4, r5)
    mov.l @r4, r4                           ! (delay) r4 = car1.close_dist_a
    mov.l @(4, r15), r6                     ! r6 = &car2.close_dist_a
    mov.l @r15, r5                          ! r5 = &sprite_idx_table[+4]
    mov.l @(12, r15), r4                    ! r4 = &car3.close_dist_a
    mov.l @r6, r6                           ! r6 = car2.close_dist_a
    mov.w @r5, r5                           ! r5 = sprite_idx_table[+4] (halfword)
    extu.w r5, r5                           ! r5 = zero-extend sprite ID
    jsr @r13                                ! call render_submit(r4, r5, r6)
    mov.l @r4, r4                           ! (delay) r4 = car3.close_dist_a
.L_lod_far_render:
    mov #0x1, r5                            ! r5 = 1 (type-B renderer flag)
    .byte   0xB8, 0x7F    /* bsr 0x0600AC44 (external) */ ! call type-B obj renderer
    mov r14, r4                             ! (delay) r4 = current object ptr
    mov.l @(20, r15), r5                    ! r5 = &car0.med_dist
    mov.l @(24, r15), r4                    ! r4 = &car1.med_dist
    mov.l @r5, r5                           ! r5 = car0.med_dist (deref)
    jsr @r12                                ! call distance_check(r4, r5)
    mov.l @r4, r4                           ! (delay) r4 = car1.med_dist
    mov.l @(28, r15), r6                    ! r6 = &car2.med_dist
    mov r9, r0                              ! r0 = sprite index from LOD table
    mov.l @(32, r15), r4                    ! r4 = &car3.med_dist
    mov.l @r6, r6                           ! r6 = car2.med_dist
    shll r0                                 ! r0 *= 2 (halfword offset)
    mov.w @(r0, r11), r5                    ! r5 = sprite_table[lod_idx]
    extu.w r5, r5                           ! r5 = zero-extend sprite ID
    jsr @r13                                ! call render_submit(r4, r5, r6)
    mov.l @r4, r4                           ! (delay) r4 = car3.med_dist
.L_decrement_budget:
    mov.l @r8, r3                           ! r3 = current render budget
    add #-0x30, r3                          ! r3 -= 48 (cost per rendered object)
    mov.l r3, @r8                           ! store updated budget
.L_next_object:
    add #0x1, r10                           ! index++
.L_loop_cond:
    mov.l   .L_obj_count_ptr, r2            ! r2 = &obj_count
    mov.l @r2, r2                           ! r2 = total object count
    cmp/hs r2, r10                          ! index >= count?
    bt      .L_epilogue                     ! yes -> exit loop
    bra     .L_loop_body                    ! no -> process next object
    nop                                     ! (delay slot)
.L_epilogue:
    add #0x44, r15                          ! deallocate stack frame
    lds.l @r15+, macl                       ! restore multiply accumulator
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r8                         ! restore r8
    mov.l @r15+, r9                         ! restore r9
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return
    mov.l @r15+, r14                        ! (delay) restore r14
.L_off_dist_sign_b:                         ! offset: distance sign (far-range path)
    .2byte  0x01BC
    .2byte  0xFFFF                          ! padding
.L_obj_count_ptr:                           ! total scene object count
    .4byte  sym_0607EA98
