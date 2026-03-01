/* obj_state_writer -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06005494 - 0x0600553C
 *
 * Object orientation & position writer for the 3D scene pipeline.
 *
 * obj_state_writer(r4=position_xyz_ptr, r5=rotation_angles_ptr):
 *   Builds the current object's world-space transform by composing
 *   rotation matrices (Y, Z, and general transform) from the angle
 *   vector at r5, then applies the position translation via a
 *   matrix-vector multiply-accumulate (sym_06026E2E). The resulting
 *   camera-relative position is copied from sym_06063DF8 into the
 *   destination buffer (sym_06063DF8+0x00..0x0B → via memcpy_long).
 *
 *   If the camera direction flip flag (sym_06078663) is set, a
 *   mat_scale_columns(1.0, -1.0, 1.0) call mirrors the Y axis first.
 *   This is the same pattern used by camera_orient_calc.
 *
 * obj_list_state_reset(r4=list_head_ptr):
 *   Resets the object list traversal state for a new frame:
 *   stores r4 as the new obj_list_head, clears the cursor index
 *   (sym_06063E08) and the view matrix pointer (sym_06063F08),
 *   then copies its value to sym_06063F04.
 *
 * Globals:
 *   sym_06078663 — camera direction flip flag (byte; 0=normal, !0=flip Y)
 *   sym_06063DF8 — camera/view position state (XYZ, 3 longs)
 *   sym_06063E04 — object list head pointer
 *   sym_06063E08 — object list cursor index (word)
 *   sym_06063F08 — view matrix pointer B
 *   sym_06063F04 — view matrix pointer A
 */

    .section .text.FUN_06005494


    .global obj_state_writer
    .type obj_state_writer, @function
obj_state_writer:
    mov.l r14, @-r15                         ! save r14 (callee-saved)
    mov r4, r14                              ! r14 = position_xyz_ptr (arg0)
    mov.l r13, @-r15                         ! save r13 (callee-saved)
    sts.l pr, @-r15                          ! save return address
    mov.l   _pool_cam_dir_flip, r0           ! r0 = &camera_direction_flip (byte)
    mov.b @r0, r0                            ! r0 = camera_direction_flip value
    tst r0, r0                               ! is flip flag zero?
    bt/s    .L_skip_y_flip                   ! yes: skip the Y-axis mirror
    mov r5, r13                              ! r13 = rotation_angles_ptr (arg1, delay slot)
    mov.l   _pool_fp_one, r6                 ! r6 = 1.0 (16.16 fixed-point) — scale Z
    mov.l   _pool_fp_neg_one, r4             ! r4 = -1.0 (16.16 fixed-point) — scale X (flipped)
    mov.l   _pool_fn_mat_scale_columns, r3   ! r3 = &mat_scale_columns
    jsr @r3                                  ! mat_scale_columns(r4=-1.0, r5=1.0, r6=1.0)
    mov r6, r5                               ! r5 = 1.0 — scale Y (delay slot)
.L_skip_y_flip:
    mov.l @(8, r13), r4                      ! r4 = rotation_angles[2] (Z angle)
    mov.l   _pool_fn_mat_rot_z, r3           ! r3 = &mat_rot_z
    jsr @r3                                  ! mat_rot_z(-angle_z)
    neg r4, r4                               ! r4 = -angle_z (delay slot)
    mov.l @r13, r4                            ! r4 = rotation_angles[0] (general angle)
    mov.l   _pool_fn_mat_rot_x, r3    ! r3 = &mat_rot_x
    jsr @r3                                  ! mat_rot_x(-angle_general)
    neg r4, r4                               ! r4 = -angle_general (delay slot)
    mov.l @(4, r13), r4                      ! r4 = rotation_angles[1] (Y angle)
    mov.l   _pool_fn_mat_rot_y, r3           ! r3 = &mat_rot_y
    jsr @r3                                  ! mat_rot_y(-angle_y)
    neg r4, r4                               ! r4 = -angle_y (delay slot)
    mov.l @(8, r14), r6                      ! r6 = position[2] (Z coordinate)
    mov.l @(4, r14), r5                      ! r5 = position[1] (Y coordinate)
    mov.l @r14, r4                           ! r4 = position[0] (X coordinate)
    mov.l   _pool_fn_mat_vec_mac, r3         ! r3 = &mat_vec_multiply_accumulate
    neg r6, r6                               ! r6 = -pos_z
    neg r5, r5                               ! r5 = -pos_y
    jsr @r3                                  ! mat_vec_mac(-pos_x, -pos_y, -pos_z)
    neg r4, r4                               ! r4 = -pos_x (delay slot)
    mov.l   _pool_cam_position, r1           ! r1 = &camera_position_state (src for copy)
    mov r14, r2                              ! r2 = position_xyz_ptr (dst for copy)
    mov.l   _pool_fn_memcpy_long, r3         ! r3 = &memcpy_long(r0=count, r1=dst, r2=src)
    jsr @r3                                  ! memcpy_long(0xC, position_xyz_ptr, cam_pos)
    mov #0xC, r0                             ! r0 = 12 bytes (3 longs: XYZ) (delay slot)
    lds.l @r15+, pr                          ! restore return address
    mov.l @r15+, r13                         ! restore r13
    rts                                      ! return
    mov.l @r15+, r14                         ! restore r14 (delay slot)

    .global sym_060054EA
sym_060054EA:                                ! obj_list_state_reset — reset traversal state
    mov.l   _pool_obj_list_head, r3          ! r3 = &obj_list_head
    mov.l r4, @r3                            ! obj_list_head = r4 (new list head ptr)
    mov #0x0, r4                             ! r4 = 0
    mov.l   _pool_obj_cursor_idx, r3         ! r3 = &obj_cursor_idx (word)
    mov.w r4, @r3                            ! obj_cursor_idx = 0 (reset to start)
    mov.l   _pool_view_matrix_b, r3          ! r3 = &view_matrix_ptr_b
    mov.l r4, @r3                            ! view_matrix_ptr_b = 0 (clear)
    mov r3, r1                               ! r1 = &view_matrix_ptr_b
    mov.l @r1, r1                            ! r1 = view_matrix_ptr_b (just stored 0)
    mov.l   _pool_view_matrix_a, r3          ! r3 = &view_matrix_ptr_a
    rts                                      ! return
    mov.l r1, @r3                            ! view_matrix_ptr_a = view_matrix_ptr_b (delay slot)
    .2byte  0xFFFF                           ! padding to align constant pool
_pool_cam_dir_flip:
    .4byte  sym_06078663                     /* camera direction flip flag (byte) */
_pool_fp_one:
    .4byte  0x00010000                       /* 1.0 (16.16 fixed-point) */
_pool_fp_neg_one:
    .4byte  0xFFFF0000                       /* -1.0 (16.16 fixed-point) */
_pool_fn_mat_scale_columns:
    .4byte  mat_scale_columns                /* matrix column scaling */
_pool_fn_mat_rot_z:
    .4byte  mat_rot_z                        /* Z-axis rotation matrix */
_pool_fn_mat_rot_x:
    .4byte  mat_rot_x                 /* general rotation transform */
_pool_fn_mat_rot_y:
    .4byte  mat_rot_y                        /* Y-axis rotation matrix */
_pool_fn_mat_vec_mac:
    .4byte  sym_06026E2E                     /* matrix-vector multiply-accumulate */
_pool_cam_position:
    .4byte  sym_06063DF8                     /* camera/view position state (XYZ) */
_pool_fn_memcpy_long:
    .4byte  sym_06035168                     /* memcpy_long(r0=count, r1=dst, r2=src) */
_pool_obj_list_head:
    .4byte  sym_06063E04                     /* object list head pointer */
_pool_obj_cursor_idx:
    .4byte  sym_06063E08                     /* object list cursor index (word) */
_pool_view_matrix_b:
    .4byte  sym_06063F08                     /* view matrix pointer B */
_pool_view_matrix_a:
    .4byte  sym_06063F04                     /* view matrix pointer A */
