/* vec3_angle_calc -- compute 3D angle from origin to target
 * Translation unit: 0x06005294 - 0x060053AC
 *
 * Given an origin point and a target point (both vec3 in 16.16 fixed-point),
 * computes the yaw and pitch angles needed to look from origin toward target.
 * The result is a rotation vector written to the output vec3.
 *
 * Algorithm:
 *   1. Compute delta vector: delta = target - origin  (dx, dy, dz)
 *   2. Call atan2(dx, dz) to get the raw horizontal (yaw) angle.
 *   3. Determine the dominant horizontal axis (|dx| vs |dz|):
 *      - If |dx| > |dz|: horiz_dist = fpmul(SCALE_FACTOR, |dx|) + fpmul(COMPL_FACTOR, |dz|)
 *      - Else:           horiz_dist = fpmul(SCALE_FACTOR, |dz|) + fpmul(COMPL_FACTOR, |dx|)
 *      This approximates sqrt(dx^2 + dz^2) without a true sqrt.
 *   4. Call atan2(dy, horiz_dist) to get the pitch (elevation) angle.
 *   5. Negate the pitch to get downward-positive convention.
 *   6. Check camera direction flip flag (sym_06078663); if set, flip Y scale.
 *   7. Apply rotation matrices: transform_matrix(pitch), mat_rot_y(yaw).
 *   8. Translate by negated origin via sym_06026E2E (position transform dispatch).
 *   9. Copy camera state via memcpy_long to sym_06063DF8 (camera position struct).
 *  10. Store [-pitch, -yaw, 0] into the output vec3.
 *
 * Args (SH-2 calling convention):
 *   R4 = origin vec3 ptr (XYZ, 3 x int32)
 *   R5 = target vec3 ptr (XYZ, 3 x int32)
 *   R6 = output vec3 ptr (receives rotation angles: [-pitch, -yaw, 0])
 *
 * Constants:
 *   0xEC83 = ~0.9239 in 16.16 fixed-point (cos 22.5 deg — octant major axis scale)
 *   0x61F7 = ~0.3827 in 16.16 fixed-point (sin 22.5 deg — octant minor axis scale)
 *
 * External calls:
 *   atan2             — fixed-point atan2(y, x)
 *   fpmul             — 16.16 fixed-point multiply
 *   mat_scale_columns — scale matrix columns (for camera flip)
 *   transform_matrix  — apply rotation by angle (pitch)
 *   mat_rot_y         — apply Y-axis rotation (yaw)
 *   sym_06026E2E      — position transform dispatch (translate by negated origin)
 *   sym_06035168      — memcpy_long (unrolled longword copy)
 *
 * Globals:
 *   sym_06078663 — camera direction flip flag (byte; 0 = normal, !0 = flipped)
 *   sym_06063DF8 — camera position/orientation state struct
 */

    .section .text.FUN_06005294


    .global vec3_angle_calc
    .type vec3_angle_calc, @function
vec3_angle_calc:
    mov.l r14, @-r15                       ! save r14 (callee-saved)
    mov r4, r14                            ! r14 = origin vec3 ptr
    mov.l r13, @-r15                       ! save r13
    mov.l r12, @-r15                       ! save r12
    mov.l r11, @-r15                       ! save r11
    mov.l r10, @-r15                       ! save r10
    mov.l r9, @-r15                        ! save r9
    mov r6, r10                            ! r10 = output vec3 ptr
    mov.l r8, @-r15                        ! save r8
    sts.l pr, @-r15                        ! save return address
    add #-0x4, r15                         ! allocate 4 bytes on stack for dy
    mov.l @r5, r13                         ! r13 = target.x
    mov.l @r14, r3                         ! r3 = origin.x
    mov.l @(4, r5), r2                     ! r2 = target.y
    sub r3, r13                            ! r13 = dx = target.x - origin.x
    mov.l @(4, r14), r3                    ! r3 = origin.y
    sub r3, r2                             ! r2 = dy = target.y - origin.y
    mov.l r2, @r15                         ! [sp+0] = dy (save for later pitch calc)
    mov.l @(8, r5), r12                    ! r12 = target.z
    mov.l @(8, r14), r3                    ! r3 = origin.z
    sub r3, r12                            ! r12 = dz = target.z - origin.z
    mov r12, r5                            ! r5 = dz (second arg to atan2)
    mov.l   .L_pool_atan2_fn, r3           ! r3 = &atan2
    jsr @r3                                ! yaw = atan2(dx, dz)
    mov r13, r4                            ! r4 = dx (first arg, in delay slot)
    cmp/pz r13                             ! is dx >= 0?
    bt/s    .L_dx_positive                 ! if yes, branch (dx already positive)
    mov r0, r9                             ! r9 = yaw angle (delay slot, always runs)
    bra     .L_have_abs_dx                 ! skip positive case
    neg r13, r11                           ! r11 = |dx| = -dx (delay slot)
.L_dx_positive:
    mov r13, r11                           ! r11 = |dx| = dx (already positive)
.L_have_abs_dx:
    cmp/pz r12                             ! is dz >= 0?
    bt      .L_dz_positive                 ! if yes, branch (dz already positive)
    bra     .L_have_abs_dz                 ! skip positive case
    neg r12, r13                           ! r13 = |dz| = -dz (delay slot)
.L_dz_positive:
    mov r12, r13                           ! r13 = |dz| = dz (already positive)
.L_have_abs_dz:
    cmp/gt r13, r11                        ! is |dx| > |dz|? (dominant axis check)
    bf      .L_dz_dominant                 ! if not, Z is dominant — branch
    mov.l   .L_pool_scale_major, r4         ! r4 = 0xEC83 (cos 22.5 — major scale)
    mov.l   .L_pool_fpmul_fn_a, r3         ! r3 = &fpmul
    jsr @r3                                ! r0 = fpmul(cos22, |dx|) — major component
    mov r11, r5                            ! r5 = |dx| (delay slot)
    mov r0, r8                             ! r8 = major component result
    mov.w   DAT_060052f6, r4               ! r4 = 0x61F7 (sin 22.5 — minor scale)
    mov.l   .L_pool_fpmul_fn_a, r3         ! r3 = &fpmul
    jsr @r3                                ! r0 = fpmul(sin22, |dz|) — minor component
    mov r13, r5                            ! r5 = |dz| (delay slot)
    bra     .L_have_horiz_dist             ! jump to combine major + minor
    nop                                    ! (delay slot, no-op)

    .global DAT_060052f6
DAT_060052f6:
    .2byte  0x61F7                         /* sin(22.5 deg) in 16.16 fp (~0.3827) */
.L_pool_atan2_fn:
    .4byte  atan2                          /* fixed-point atan2(y, x) */
.L_pool_scale_major:
    .4byte  0x0000EC83                     /* cos(22.5 deg) in 16.16 fp (~0.9239) */
.L_pool_fpmul_fn_a:
    .4byte  fpmul                          /* 16.16 fixed-point multiply */
.L_dz_dominant:                            ! --- |dz| >= |dx|: Z is dominant axis ---
    mov.l   .L_pool_scale_major_b, r4     ! r4 = 0xEC83 (cos 22.5 — major scale)
    mov.l   .L_pool_fpmul_fn_b, r3        ! r3 = &fpmul
    jsr @r3                                ! r0 = fpmul(cos22, |dz|) — major component
    mov r13, r5                            ! r5 = |dz| (delay slot)
    mov r0, r8                             ! r8 = major component result
    mov.w   DAT_0600537a, r4               ! r4 = 0x61F7 (sin 22.5 — minor scale)
    mov.l   .L_pool_fpmul_fn_b, r3        ! r3 = &fpmul
    jsr @r3                                ! r0 = fpmul(sin22, |dx|) — minor component
    mov r11, r5                            ! r5 = |dx| (delay slot)
.L_have_horiz_dist:                        ! --- combine into approximate horiz distance ---
    mov r8, r5                             ! r5 = major component
    mov.l   .L_pool_atan2_fn_b, r3        ! r3 = &atan2
    add r0, r5                             ! r5 = major + minor = approx horiz_dist
    jsr @r3                                ! pitch = atan2(dy, horiz_dist)
    mov.l @r15, r4                         ! r4 = dy from stack (delay slot)
    neg r0, r13                            ! r13 = -pitch (negate for convention)
    mov.l   .L_pool_cam_flip_flag, r0     ! r0 = &camera_direction_flip_flag
    mov.b @r0, r0                          ! r0 = flag byte value
    tst r0, r0                             ! is flag zero?
    bt      .L_no_cam_flip                 ! if zero, skip camera flip
    mov.l   .L_fp_one, r6                 ! r6 = +1.0 (16.16 fp)
    mov.l   .L_fp_neg_one, r4             ! r4 = -1.0 (16.16 fp)
    mov.l   .L_pool_mat_scale_fn, r3      ! r3 = &mat_scale_columns
    jsr @r3                                ! mat_scale_columns(-1.0, +1.0, +1.0) — flip Y
    mov r6, r5                             ! r5 = +1.0 (delay slot)
.L_no_cam_flip:                            ! --- apply rotation matrices ---
    mov.l   .L_pool_xform_mat_fn, r3      ! r3 = &transform_matrix
    jsr @r3                                ! transform_matrix(-pitch) — apply pitch rotation
    mov r13, r4                            ! r4 = -pitch (delay slot)
    mov.l   .L_pool_rot_y_fn, r3          ! r3 = &mat_rot_y
    jsr @r3                                ! mat_rot_y(yaw) — apply yaw rotation
    mov r9, r4                             ! r4 = yaw angle (delay slot)
    mov.l @(8, r14), r6                    ! r6 = origin.z
    mov.l @(4, r14), r5                    ! r5 = origin.y
    mov.l @r14, r4                         ! r4 = origin.x
    mov.l   .L_pool_pos_xform_fn, r3      ! r3 = &position_transform_dispatch
    neg r6, r6                             ! r6 = -origin.z
    neg r5, r5                             ! r5 = -origin.y
    jsr @r3                                ! translate by (-origin.x, -origin.y, -origin.z)
    neg r4, r4                             ! r4 = -origin.x (delay slot)
    mov.l   .L_pool_cam_state_ptr, r1     ! r1 = &sym_06063DF8 (camera state dst)
    mov r14, r2                            ! r2 = origin ptr (src for memcpy)
    mov.l   .L_pool_memcpy_long_fn, r3    ! r3 = &memcpy_long
    jsr @r3                                ! memcpy_long(0xC, cam_state, origin)
    mov #0xC, r0                           ! r0 = 12 bytes to copy (delay slot)
    neg r13, r13                           ! r13 = pitch (re-negate: was -pitch)
    neg r9, r9                             ! r9 = -yaw
    mov #0x0, r2                           ! r2 = 0 (Z rotation = none)
    mov.l r13, @r10                        ! output[0] = pitch (negated = -pitch originally)
    mov.l r9, @(4, r10)                    ! output[1] = -yaw
    mov.l r2, @(8, r10)                    ! output[2] = 0 (no roll)
    add #0x4, r15                          ! free stack local (dy)
    lds.l @r15+, pr                        ! restore return address
    mov.l @r15+, r8                        ! restore r8
    mov.l @r15+, r9                        ! restore r9
    mov.l @r15+, r10                       ! restore r10
    mov.l @r15+, r11                       ! restore r11
    mov.l @r15+, r12                       ! restore r12
    mov.l @r15+, r13                       ! restore r13
    rts                                    ! return
    mov.l @r15+, r14                       ! restore r14 (delay slot)

    .global DAT_0600537a
DAT_0600537a:
    .2byte  0x61F7                         /* sin(22.5 deg) in 16.16 fp (~0.3827) */
.L_pool_scale_major_b:
    .4byte  0x0000EC83                     /* cos(22.5 deg) in 16.16 fp (~0.9239) */
.L_pool_fpmul_fn_b:
    .4byte  fpmul                          /* 16.16 fixed-point multiply */
.L_pool_atan2_fn_b:
    .4byte  atan2                          /* fixed-point atan2(y, x) */
.L_pool_cam_flip_flag:
    .4byte  sym_06078663                   /* camera direction flip flag (byte) */
.L_fp_one:
    .4byte  0x00010000                     /* 1.0 (16.16 fixed-point) */
.L_fp_neg_one:
    .4byte  0xFFFF0000                     /* -1.0 (16.16 fixed-point) */
.L_pool_mat_scale_fn:
    .4byte  mat_scale_columns              /* scale matrix columns (for Y flip) */
.L_pool_xform_mat_fn:
    .4byte  transform_matrix               /* apply rotation by angle */
.L_pool_rot_y_fn:
    .4byte  mat_rot_y                      /* Y-axis rotation matrix */
.L_pool_pos_xform_fn:
    .4byte  sym_06026E2E                   /* position transform dispatch */
.L_pool_cam_state_ptr:
    .4byte  sym_06063DF8                   /* camera position/orientation state */
.L_pool_memcpy_long_fn:
    .4byte  sym_06035168                   /* memcpy_long (unrolled longword copy) */
