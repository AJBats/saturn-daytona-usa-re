/* scene_render_coord -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0600B340 - 0x0600B4D2
 *
 * Primary scene rendering coordinator -- sets up the camera transform
 * pipeline for the current car's position and orientation each frame.
 *
 * Dispatches on course index (0/1/2) to select course-specific transform
 * parameter tables (r13 = distance-check table, r12 = render-submit table).
 *
 * Core pipeline:
 *   1. Init transform matrix (FUN_06027080)
 *   2. Set camera position from car XYZ at +16/+20/+24 (FUN_060270F2)
 *   3. Apply rotation: mat_rot_xy_b(bank +32), mat_rot_yz_b(pitch +36),
 *      mat_rot_xz_b(yaw +28)
 *   4. Combine camera yaw from car[+0x1D8] with car[+0x1CC] offset,
 *      apply via mat_rot_xy_b
 *
 * If secondary scene flag (sym_06059F30) is set:
 *   - Distance check (FUN_06032158) + render submit (FUN_06031DF4) using
 *     per-course tables indexed by camera state
 *   - Call secondary_geom_proc (FUN_0600A76C) for additional geometry
 *
 * Decrements render budget (sym_0608A52C) by 0x30 per frame.
 * If early-exit flag (sym_0607867C) is nonzero, tail-calls camera_lerp
 * instead of returning normally.
 */

    .section .text.FUN_0600B340


    .global scene_render_coord
    .type scene_render_coord, @function
scene_render_coord:
    mov.l r14, @-r15                     ! save r14
    mov.l r13, @-r15                     ! save r13
    mov.l r12, @-r15                     ! save r12
    mov.l r11, @-r15                     ! save r11
    sts.l pr, @-r15                      ! save pr
    add #-0x8, r15                       ! allocate 0x8 bytes of stack frame
    mov.l   .L_ptr_camera_state, r11     ! r11 -> &camera_state ptr
    mov.l @r11, r11                      ! r11 = camera_state struct
    mov.l   .L_ptr_car_array_base, r14   ! r14 -> &car_array_base ptr
    mov.l @r14, r14                      ! r14 = car struct pointer
    mov.l   .L_ptr_cur_car_struct, r3    ! r3 -> &current_car_struct
    mov.l r14, @r3                       ! store car ptr as current car
    mov.l   .L_ptr_course_index, r0      ! r0 -> &course_index
    bra     .L_course_dispatch           ! jump to course dispatch
    mov.l @r0, r0                        ! (delay) r0 = course index (0/1/2)
.L_course_0:
    mov.l   .L_ptr_cs0_dist_tbl, r13     ! r13 = course 0 distance-check table
    mov.l   .L_ptr_cs0_render_tbl, r12   ! r12 = course 0 render-submit table
    bra     .L_tables_selected           ! proceed with tables loaded
    nop                                  ! (delay)
.L_course_1:
    mov.l   .L_ptr_cs1_dist_tbl, r13     ! r13 = course 1 distance-check table
    mov.l   .L_ptr_cs1_render_tbl, r12   ! r12 = course 1 render-submit table
    bra     .L_tables_selected           ! proceed with tables loaded
    nop                                  ! (delay)
.L_course_2:
    mov.l   .L_ptr_cs2_dist_tbl, r13     ! r13 = course 2 distance-check table
    mov.l   .L_ptr_cs2_render_tbl, r12   ! r12 = course 2 render-submit table
    bra     .L_tables_selected           ! proceed with tables loaded
    nop                                  ! (delay)
    .2byte  0xFFFF                       ! alignment padding
.L_ptr_camera_state:
    .4byte  sym_0607EB8C               ! camera lerp state pointer
.L_ptr_car_array_base:
    .4byte  sym_0607E944               ! car array base pointer
.L_ptr_cur_car_struct:
    .4byte  sym_0607E940               ! current car struct pointer
.L_ptr_course_index:
    .4byte  sym_0607EAD8               ! race end state / course index
.L_ptr_cs0_dist_tbl:
    .4byte  sym_06063488               ! course 0 distance param table
.L_ptr_cs0_render_tbl:
    .4byte  sym_06063434               ! course 0 render param table
.L_ptr_cs1_dist_tbl:
    .4byte  sym_060634A4               ! course 1 distance param table
.L_ptr_cs1_render_tbl:
    .4byte  sym_06063450               ! course 1 render param table
.L_ptr_cs2_dist_tbl:
    .4byte  sym_060634C0               ! course 2 distance param table
.L_ptr_cs2_render_tbl:
    .4byte  sym_0606346C               ! course 2 render param table
.L_course_dispatch:
    cmp/eq #0x0, r0                      ! course == 0?
    bt      .L_course_0                  ! if so, use course 0 tables
    cmp/eq #0x1, r0                      ! course == 1?
    bt      .L_course_1                  ! if so, use course 1 tables
    cmp/eq #0x2, r0                      ! course == 2?
    bt      .L_course_2                  ! if so, use course 2 tables
.L_tables_selected:
    mov.l   .L_fn_transform_init, r3     ! r3 = FUN_06027080 (transform init)
    jsr @r3                              ! call transform_init()
    nop                                  ! (delay)
    mov.l @(24, r14), r6                 ! r6 = car[+24] = Z position
    mov.l @(20, r14), r5                 ! r5 = car[+20] = Y position
    mov.l   .L_fn_set_position, r3       ! r3 = FUN_060270F2 (set position)
    jsr @r3                              ! call set_position(X, Y, Z)
    mov.l @(16, r14), r4                 ! (delay) r4 = car[+16] = X position
    mov.l   .L_fn_rot_xy, r3            ! r3 = mat_rot_xy_b
    jsr @r3                              ! call mat_rot_xy_b(bank)
    mov.l @(32, r14), r4                 ! (delay) r4 = car[+32] = bank angle
    mov.l   .L_fn_rot_yz, r3            ! r3 = mat_rot_yz_b
    jsr @r3                              ! call mat_rot_yz_b(pitch)
    mov.l @(36, r14), r4                 ! (delay) r4 = car[+36] = pitch angle
    mov.l   .L_fn_rot_xz, r3            ! r3 = mat_rot_xz_b
    jsr @r3                              ! call mat_rot_xz_b(yaw)
    mov.l @(28, r14), r4                 ! (delay) r4 = car[+28] = yaw angle
    mov.w   DAT_0600b47a, r0            ! r0 = 0x01D8 (camera yaw offset)
    mov.l   .L_fn_rot_xy, r3            ! r3 = mat_rot_xy_b
    mov.l @(r0, r14), r4                 ! r4 = car[+0x1D8] = camera yaw
    add #-0xC, r0                        ! r0 = 0x01CC (yaw offset field)
    mov.l @(r0, r14), r2                 ! r2 = car[+0x1CC] = yaw offset
    jsr @r3                              ! call mat_rot_xy_b(cam_yaw + yaw_offset)
    add r2, r4                           ! (delay) r4 = camera_yaw + yaw_offset
    mov.l   .L_ptr_secondary_flag, r0    ! r0 -> &secondary_scene_flag
    mov.l @r0, r0                        ! r0 = secondary scene flag
    tst r0, r0                           ! is secondary scene disabled?
    bt      .L_decrement_budget          ! if zero, skip secondary path
    ! --- Secondary scene rendering path ---
    mov.l   .L_ptr_lod_dist_param, r5   ! r5 -> &LOD distance parameter
    mov.l   .L_fn_dist_check, r3        ! r3 = FUN_06032158 (distance check)
    mov.l @r5, r5                        ! r5 = LOD distance value
    jsr @r3                              ! call dist_check(dist_tbl[24], LOD_dist)
    mov.l @(24, r13), r4                 ! (delay) r4 = dist_tbl[+24] entry
    mov.l   .L_ptr_lod_scale_param, r6  ! r6 -> &LOD scale parameter
    mov.l   .L_ptr_sprite_index_tbl, r2 ! r2 -> sprite index table base
    mov.l @r6, r6                        ! r6 = LOD scale value
    mov r2, r5                           ! r5 = sprite index table ptr
    mov.l r2, @(4, r15)                  ! save sprite tbl ptr on stack[+4]
    mov.w @r5, r5                        ! r5 = sprite index (halfword)
    mov.l   .L_fn_render_submit, r3     ! r3 = FUN_06031DF4 (render submit)
    extu.w r5, r5                        ! zero-extend sprite index
    jsr @r3                              ! call render_submit(render_tbl[24], idx, scale)
    mov.l @(24, r12), r4                 ! (delay) r4 = render_tbl[+24] entry
    mov #0x0, r6                         ! r6 = 0 (zero X position)
    mov.w   DAT_0600b47c, r0            ! r0 = 0x01B4 (camera roll offset)
    mov.l   .L_fn_set_position, r3      ! r3 = FUN_060270F2 (set position)
    mov.l @(r0, r14), r5                 ! r5 = car[+0x1B4] = camera roll
    jsr @r3                              ! call set_position(0, roll, 0)
    mov r6, r4                           ! (delay) r4 = 0 (zero position)
    mov.w   DAT_0600b47e, r0            ! r0 = 0x01D0 (camera pitch A offset)
    mov.l   .L_fn_rot_yz, r3            ! r3 = mat_rot_yz_b
    jsr @r3                              ! call mat_rot_yz_b(pitch_a)
    mov.l @(r0, r14), r4                 ! (delay) r4 = car[+0x1D0] = pitch A
    mov.w   .L_off_cam_pitch_b, r0      ! r0 = 0x01C8 (camera pitch B offset)
    mov.l   .L_ptr_height_offset, r2    ! r2 -> &height_offset
    mov.l   .L_fn_rot_xz, r3            ! r3 = mat_rot_xz_b
    mov.l @(r0, r14), r4                 ! r4 = car[+0x1C8] = pitch B
    mov.l @r2, r2                        ! r2 = height offset value
    jsr @r3                              ! call mat_rot_xz_b(pitch_b + height)
    add r2, r4                           ! (delay) r4 = pitch_b + height_offset
    ! --- Indexed table lookups using camera state ---
    mov.l @(12, r11), r5                 ! r5 = camera_state[+12] = table index
    shll2 r5                             ! r5 *= 4 (word-size stride)
    mov.l r5, @r15                       ! save index*4 on stack[+0]
    mov.l   .L_ptr_dist_tbl_indexed, r3 ! r3 = dist_tbl index base
    mov.l @r15, r4                       ! r4 = index*4
    mov.l   .L_fn_dist_check, r2        ! r2 = FUN_06032158 (distance check)
    add r3, r5                           ! r5 = &dist_tbl_base[index]
    add r13, r4                          ! r4 = &course_dist_tbl[index]
    mov.l @r5, r5                        ! r5 = dist_tbl_base[index] value
    jsr @r2                              ! call dist_check(course_dist[idx], tbl[idx])
    mov.l @r4, r4                        ! (delay) r4 = course_dist_tbl[index]
    mov.l @(12, r11), r6                 ! r6 = camera_state[+12] = table index
    shll2 r6                             ! r6 *= 4
    mov.l r6, @r15                       ! save index*4 on stack[+0]
    mov.l   .L_ptr_render_tbl_indexed, r3 ! r3 = render_tbl index base
    mov.l @(4, r15), r5                  ! r5 = sprite tbl ptr (from stack[+4])
    mov.l @r15, r4                       ! r4 = index*4
    mov.l   .L_fn_render_submit, r2     ! r2 = FUN_06031DF4 (render submit)
    add r3, r6                           ! r6 = &render_tbl_base[index]
    mov.w @r5, r5                        ! r5 = sprite index (halfword)
    add r12, r4                          ! r4 = &course_render_tbl[index]
    mov.l @r6, r6                        ! r6 = render_tbl_base[index] value
    extu.w r5, r5                        ! zero-extend sprite index
    jsr @r2                              ! call render_submit(course_render[idx], idx, tbl[idx])
    mov.l @r4, r4                        ! (delay) r4 = course_render_tbl[index]
    .byte   0xB9, 0x89    /* bsr 0x0600A76C (secondary_geom_proc) */
    nop                                  ! (delay)
.L_decrement_budget:
    mov.l   .L_ptr_render_budget, r4     ! r4 -> &render_budget counter
    mov.l @r4, r2                        ! r2 = current budget
    add #-0x30, r2                       ! r2 -= 0x30 (48 bytes per frame)
    mov.l r2, @r4                        ! store decremented budget
    mov.l   .L_ptr_early_exit_flag, r0   ! r0 -> &early_exit_flag byte
    mov.b @r0, r0                        ! r0 = early exit flag
    extu.b r0, r0                        ! zero-extend byte
    tst r0, r0                           ! is early exit flag zero?
    bt      .L_normal_return             ! if zero, return normally
    ! --- Early exit: tail-call camera_lerp ---
    add #0x8, r15                        ! deallocate stack frame
    lds.l @r15+, pr                      ! restore pr
    mov.l @r15+, r11                     ! restore r11
    mov.l @r15+, r12                     ! restore r12
    mov.l @r15+, r13                     ! restore r13
    .byte   0xA0, 0x2C    /* bra 0x0600B4D2 (camera_lerp, external) */
    mov.l @r15+, r14                     ! (delay) restore r14

    .global DAT_0600b47a
DAT_0600b47a:
    .2byte  0x01D8                       ! car struct offset: camera yaw

    .global DAT_0600b47c
DAT_0600b47c:
    .2byte  0x01B4                       ! car struct offset: camera roll

    .global DAT_0600b47e
DAT_0600b47e:
    .2byte  0x01D0                       ! car struct offset: camera pitch A
.L_off_cam_pitch_b:
    .2byte  0x01C8                       ! car struct offset: camera pitch B
    .2byte  0xFFFF                       ! alignment padding
.L_fn_transform_init:
    .4byte  sym_06027080               ! FUN_06027080: scene transform init
.L_fn_set_position:
    .4byte  sym_060270F2               ! FUN_060270F2: set camera position
.L_fn_rot_xy:
    .4byte  mat_rot_xy_b               ! mat_rot_xy_b: XY-plane rotation (bank)
.L_fn_rot_yz:
    .4byte  mat_rot_yz_b               ! mat_rot_yz_b: YZ-plane rotation (pitch)
.L_fn_rot_xz:
    .4byte  mat_rot_xz_b               ! mat_rot_xz_b: XZ-plane rotation (yaw)
.L_ptr_secondary_flag:
    .4byte  sym_06059F30               ! secondary scene enable flag
.L_ptr_lod_dist_param:
    .4byte  sym_06063510               ! LOD distance parameter
.L_fn_dist_check:
    .4byte  sym_06032158               ! FUN_06032158: distance check
.L_ptr_lod_scale_param:
    .4byte  sym_060634F4               ! LOD scale parameter
.L_ptr_sprite_index_tbl:
    .4byte  sym_06089E98               ! sprite index lookup table
.L_fn_render_submit:
    .4byte  sym_06031DF4               ! FUN_06031DF4: render submit to VDP1
.L_ptr_height_offset:
    .4byte  sym_06083258               ! camera height offset value
.L_ptr_dist_tbl_indexed:
    .4byte  sym_060634F8               ! indexed distance table base
.L_ptr_render_tbl_indexed:
    .4byte  sym_060634DC               ! indexed render table base
.L_ptr_render_budget:
    .4byte  sym_0608A52C               ! render budget counter
.L_ptr_early_exit_flag:
    .4byte  sym_0607867C               ! early exit flag byte
.L_normal_return:
    add #0x8, r15                        ! deallocate stack frame
    lds.l @r15+, pr                      ! restore pr
    mov.l @r15+, r11                     ! restore r11
    mov.l @r15+, r12                     ! restore r12
    mov.l @r15+, r13                     ! restore r13
    rts                                  ! return to caller
    mov.l @r15+, r14                     ! (delay) restore r14
