/* perspective_project -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060055BC - 0x06005788
 *
 * 3D perspective projection pipeline for the scene rendering system.
 *
 * Walks a linked list of object nodes (stride 0x28), computing perspective-
 * projected screen coordinates for two consecutive nodes per invocation.
 * Each node carries a 3x3 orientation matrix (at +0x08 and +0x14) and
 * sprite frame data (at +0x02 and +0x03).
 *
 * Algorithm:
 *   1. Advance the object list cursor, wrapping to next node when the
 *      per-node object counter is exhausted.
 *   2. Compute a fixed-point perspective scale factor via fpdiv_setup:
 *        scale = (node_end - base_count) << 16 / (cursor_idx - base_count) << 16
 *   3. Set up sprite frames for both nodes via sprite_frame_selector (BSR).
 *   4. Transform each node's 3x3 matrix through mat_vec_transform, producing
 *      two sets of world-space XYZ vectors.
 *   5. Interpolate between the two transforms using fpmul:
 *        projected[i] = xform_A[i] + fpmul(xform_B[i] - xform_A[i], scale)
 *   6. Push a matrix entry (sym_06026E0C), compute a 3D angle between the
 *      two projected points (BSR to vec3_angle_calc), then apply the camera
 *      direction flip to derive the final Y position.
 *   7. Write the result to the scene command queue via cmd_queue_write +
 *      scene_data_write_abs + cmd_queue_commit.
 *
 * Globals:
 *   sym_06063EEC — camera target vector (also used as vec3_angle_calc output)
 *   sym_06063E08 — object list cursor index (word)
 *   sym_06063E04 — object list head pointer
 *   sym_06078663 — camera direction flip flag (byte; 0 = negative, !0 = positive)
 *
 * Stack frame (0x34 bytes):
 *   sp+0x00       : temp (base_count, then fpmul offset scratch)
 *   sp+0x04..0x0C : projected coords B (X, Y, Z) — second node
 *   sp+0x10..0x18 : projected coords A (X, Y, Z) — first node
 *   sp+0x1C..0x27 : mat_vec_transform result B (3 longs)
 *   sp+0x28..0x33 : mat_vec_transform result A (3 longs)
 */

    .section .text.FUN_060055BC


    .global perspective_project
    .type perspective_project, @function
perspective_project:
    mov.l r14, @-r15                       ! save r14
    mov.l r13, @-r15                       ! save r13
    mov.l r12, @-r15                       ! save r12
    mov.l r11, @-r15                       ! save r11
    mov.l r10, @-r15                       ! save r10
    mov.l r9, @-r15                        ! save r9
    mov.l r8, @-r15                        ! save r8
    sts.l pr, @-r15                        ! save return address
    add #-0x34, r15                        ! allocate 52-byte stack frame
    mov.l   _pool_camera_target_vec, r9    ! r9 = &camera_target_vec (sym_06063EEC)
    mov.l   _pool_obj_cursor_idx, r10      ! r10 = &obj_cursor_idx (sym_06063E08, word)
    mov.l   _pool_obj_list_head, r13       ! r13 = &obj_list_head (sym_06063E04)
    mov.w @r10, r3                         ! r3 = cursor_idx (current position in list)
    mov.l @r13, r13                        ! r13 = obj_list_head (dereference pointer)
    extu.w r3, r3                          ! zero-extend cursor_idx to 32 bits
    mov r13, r14                           ! r14 = node_A ptr
    add #0x20, r14                         ! r14 = &node_A.next_info (offset +0x20)
    mov.w @r14, r2                         ! r2 = node_A.obj_count (objects in this node)
    cmp/ge r2, r3                          ! cursor_idx >= obj_count?
    bf      .L_begin_projection            ! no: proceed with current node
    mov.w @r14, r0                         ! r0 = node_A.obj_count
    cmp/eq #-0x1, r0                       ! is obj_count == 0xFFFF (sentinel)?
    bf      .L_advance_node                ! no sentinel: just advance to next field
    mov.l @(4, r14), r14                   ! r14 = node_A.next_ptr (follow link at +0x24)
.L_advance_node:
    mov r14, r13                           ! r13 = new current node
    mov.l   _pool_obj_list_head, r3        ! r3 = &obj_list_head
    mov.l r13, @r3                         ! update obj_list_head to new node
    mov.w @r13, r2                         ! r2 = new_node.obj_count
    tst r2, r2                             ! is count == 0?
    bf/s    .L_begin_projection            ! non-zero: proceed
    add #0x20, r14                         ! r14 = &new_node.next_info (delay slot)
    mov #0x0, r3                           ! count is zero — reset cursor
    mov.w r3, @r10                         ! cursor_idx = 0
.L_begin_projection:
    mov.w @r14, r5                         ! r5 = node_end (obj_count from next_info)
    mov.w @r13, r3                         ! r3 = base_count (obj_count from node head)
    mov.l r3, @r15                         ! sp+0x00 = base_count (save for later)
    sub r3, r5                             ! r5 = node_end - base_count (range size)
    mov.w @r10, r4                         ! r4 = cursor_idx
    mov.l   _pool_fn_fpdiv_setup, r2       ! r2 = &fpdiv_setup
    shll16 r5                              ! r5 = range_size << 16 (16.16 dividend)
    extu.w r4, r4                          ! zero-extend cursor_idx
    sub r3, r4                             ! r4 = cursor_idx - base_count (offset into range)
    jsr @r2                                ! fpdiv_setup(dividend=range<<16, divisor=offset<<16)
    shll16 r4                              ! r4 = offset << 16 (delay slot — 16.16 divisor)
    mov r0, r12                            ! r12 = perspective_scale (16.16 fixed-point ratio)
    mov #0x0, r5                           ! r5 = 0 (no comparison object — unconditional)
    mov r13, r4                            ! r4 = node_A base ptr
    .byte   0xBF, 0x8F    /* bsr 0x0600553C (external) */  ! sprite_frame_selector(node_A+2, 0)
    add #0x2, r4                           ! r4 = &node_A.sprite_frame (delay slot)
    mov r15, r5                            ! r5 = sp (output destination)
    mov r13, r4                            ! r4 = node_A base ptr
    mov.l   _pool_fn_mat_vec_transform, r8 ! r8 = &mat_vec_transform (cached for reuse)
    add #0x28, r5                          ! r5 = sp+0x28 (dest: xform result A)
    jsr @r8                                ! mat_vec_transform(node_A+8, sp+0x28)
    add #0x8, r4                           ! r4 = &node_A.matrix (delay slot, offset +0x08)
    mov r13, r5                            ! r5 = node_A base (for sprite_frame_selector param2)
    mov r14, r4                            ! r4 = node_B info ptr
    add #0x2, r5                           ! r5 = &node_A.sprite_frame (comparison object)
    .byte   0xBF, 0x84    /* bsr 0x0600553C (external) */  ! sprite_frame_selector(node_B+2, node_A+2)
    add #0x2, r4                           ! r4 = &node_B.sprite_frame (delay slot)
    mov r15, r5                            ! r5 = sp (output destination)
    mov r14, r4                            ! r4 = node_B info ptr
    add #0x1C, r5                          ! r5 = sp+0x1C (dest: xform result B)
    jsr @r8                                ! mat_vec_transform(node_B+8, sp+0x1C)
    add #0x8, r4                           ! r4 = &node_B.matrix (delay slot, offset +0x08)
    ! --- Interpolate X component for node A ---
    mov r12, r5                            ! r5 = perspective_scale (fpmul arg2)
    mov.l   _pool_fn_fpmul, r11            ! r11 = &fpmul (cached for reuse)
    mov.l @(40, r15), r2                   ! r2 = xform_A.x (sp+0x28)
    mov.l r2, @r15                         ! sp+0x00 = xform_A.x (save as offset)
    mov r2, r3                             ! r3 = xform_A.x
    mov.l @(28, r15), r4                   ! r4 = xform_B.x (sp+0x1C)
    jsr @r11                               ! fpmul(xform_B.x - xform_A.x, scale)
    sub r3, r4                             ! r4 = xform_B.x - xform_A.x (delay slot)
    mov r12, r5                            ! r5 = perspective_scale
    mov.l @r15, r3                         ! r3 = xform_A.x (saved offset)
    add r3, r0                             ! r0 = xform_A.x + fpmul(delta_x, scale) = proj_A.x
    mov.l r0, @(16, r15)                   ! sp+0x10 = projected A.x
    ! --- Interpolate Y component for node A ---
    mov.l @(44, r15), r3                   ! r3 = xform_A.y (sp+0x2C)
    mov.l r3, @r15                         ! sp+0x00 = xform_A.y (save)
    mov.l @(32, r15), r4                   ! r4 = xform_B.y (sp+0x20)
    jsr @r11                               ! fpmul(xform_B.y - xform_A.y, scale)
    sub r3, r4                             ! r4 = delta_y (delay slot)
    mov.l @r15, r3                         ! r3 = xform_A.y
    mov r12, r5                            ! r5 = perspective_scale
    add r3, r0                             ! r0 = proj_A.y
    mov.l r0, @(20, r15)                   ! sp+0x14 = projected A.y
    ! --- Interpolate Z component for node A ---
    mov.l @(48, r15), r3                   ! r3 = xform_A.z (sp+0x30)
    mov.l r3, @r15                         ! sp+0x00 = xform_A.z (save)
    mov.l @(36, r15), r4                   ! r4 = xform_B.z (sp+0x24)
    jsr @r11                               ! fpmul(xform_B.z - xform_A.z, scale)
    sub r3, r4                             ! r4 = delta_z (delay slot)
    ! --- Set up sprite frames for second pass ---
    mov r14, r5                            ! r5 = node_B info ptr
    mov r13, r4                            ! r4 = node_A base ptr
    mov.l @r15, r3                         ! r3 = xform_A.z
    add #0x2, r5                           ! r5 = &node_B.sprite_frame
    add r3, r0                             ! r0 = proj_A.z
    mov.l r0, @(24, r15)                   ! sp+0x18 = projected A.z
    .byte   0xBF, 0x5D    /* bsr 0x0600553C (external) */  ! sprite_frame_selector(node_A+3, node_B+2)
    add #0x3, r4                           ! r4 = &node_A.sprite_alt (delay slot, +0x03)
    mov r15, r5                            ! r5 = sp (output destination)
    mov r13, r4                            ! r4 = node_A base ptr
    add #0x28, r5                          ! r5 = sp+0x28 (dest: xform result A, reused)
    jsr @r8                                ! mat_vec_transform(node_A+0x14, sp+0x28)
    add #0x14, r4                          ! r4 = &node_A.matrix_alt (delay slot, offset +0x14)
    mov r13, r5                            ! r5 = node_A base
    add #0x3, r5                           ! r5 = &node_A.sprite_alt (comparison param)
    mov r14, r4                            ! r4 = node_B info ptr
    bra     .L_second_pass_xform           ! jump to second pass transform
    add #0x3, r4                           ! r4 = &node_B.sprite_alt (delay slot, +0x03)
    .2byte  0xFFFF                         ! alignment padding
_pool_camera_target_vec:
    .4byte  sym_06063EEC                   /* camera target vector */
_pool_obj_cursor_idx:
    .4byte  sym_06063E08                   /* object list cursor index (word) */
_pool_obj_list_head:
    .4byte  sym_06063E04                   /* object list head pointer */
_pool_fn_fpdiv_setup:
    .4byte  fpdiv_setup                    /* 16.16 fixed-point divide */
_pool_fn_mat_vec_transform:
    .4byte  mat_vec_transform              /* 3x3 matrix-vector multiply */
_pool_fn_fpmul:
    .4byte  fpmul                          /* 16.16 fixed-point multiply */
.L_second_pass_xform:
    .byte   0xBF, 0x44    /* bsr 0x0600553C (external) */  ! sprite_frame_selector(node_B+3, node_A+3)
    nop                                    ! delay slot (no useful work)
    mov r15, r5                            ! r5 = sp (output destination)
    mov r14, r4                            ! r4 = node_B info ptr
    add #0x1C, r5                          ! r5 = sp+0x1C (dest: xform result B, reused)
    jsr @r8                                ! mat_vec_transform(node_B+0x14, sp+0x1C)
    add #0x14, r4                          ! r4 = &node_B.matrix_alt (delay slot, offset +0x14)
    ! --- Interpolate X component for node B ---
    mov r12, r5                            ! r5 = perspective_scale
    mov.l @(40, r15), r2                   ! r2 = xform_A.x (sp+0x28)
    mov.l r2, @r15                         ! sp+0x00 = xform_A.x (save)
    mov r2, r3                             ! r3 = xform_A.x
    mov.l @(28, r15), r4                   ! r4 = xform_B.x (sp+0x1C)
    jsr @r11                               ! fpmul(xform_B.x - xform_A.x, scale)
    sub r3, r4                             ! r4 = delta_x (delay slot)
    mov.l @r15, r3                         ! r3 = xform_A.x
    mov r12, r5                            ! r5 = perspective_scale
    add r3, r0                             ! r0 = proj_B.x
    mov.l r0, @(4, r15)                    ! sp+0x04 = projected B.x
    ! --- Interpolate Y component for node B ---
    mov.l @(44, r15), r3                   ! r3 = xform_A.y (sp+0x2C)
    mov.l r3, @r15                         ! sp+0x00 = xform_A.y (save)
    mov.l @(32, r15), r4                   ! r4 = xform_B.y (sp+0x20)
    jsr @r11                               ! fpmul(xform_B.y - xform_A.y, scale)
    sub r3, r4                             ! r4 = delta_y (delay slot)
    mov r12, r5                            ! r5 = perspective_scale
    mov.l @r15, r3                         ! r3 = xform_A.y
    add r3, r0                             ! r0 = proj_B.y
    mov.l r0, @(8, r15)                    ! sp+0x08 = projected B.y
    ! --- Interpolate Z component for node B ---
    mov.l @(48, r15), r3                   ! r3 = xform_A.z (sp+0x30)
    mov.l r3, @r15                         ! sp+0x00 = xform_A.z (save)
    mov.l @(36, r15), r4                   ! r4 = xform_B.z (sp+0x24)
    jsr @r11                               ! fpmul(xform_B.z - xform_A.z, scale)
    sub r3, r4                             ! r4 = delta_z (delay slot)
    mov.l @r15, r3                         ! r3 = xform_A.z
    add r3, r0                             ! r0 = proj_B.z
    mov.l r0, @(12, r15)                   ! sp+0x0C = projected B.z
    ! --- Advance cursor index ---
    mov.w @r10, r3                         ! r3 = cursor_idx
    add #0x1, r3                           ! cursor_idx++
    mov.w r3, @r10                         ! store updated cursor_idx
    ! --- Push matrix entry for final output ---
    mov.l   _pool_fn_matrix_entry_init, r3 ! r3 = &matrix_entry_init (sym_06026E0C)
    jsr @r3                                ! matrix_entry_init() — push current matrix state
    nop                                    ! delay slot
    ! --- Compute 3D angle between projected points A and B ---
    mov r15, r5                            ! r5 = &proj_B (sp+0x04)
    mov r15, r4                            ! r4 = &proj_A (sp+0x10)
    mov.l   _pool_camera_target_vec_2, r6  ! r6 = &camera_target_vec (output for angle calc)
    add #0x4, r5                           ! r5 = sp+0x04 (proj_B coords)
    .byte   0xBD, 0xC3    /* bsr 0x06005294 (external) */  ! vec3_angle_calc(proj_A, proj_B, camera_target)
    add #0x10, r4                          ! r4 = sp+0x10 (proj_A coords) (delay slot)
    ! --- Apply camera direction flip for Y position ---
    mov.l   _pool_cam_dir_flip_flag, r0    ! r0 = &cam_dir_flip_flag (sym_06078663)
    mov.b @r0, r0                          ! r0 = direction flip flag (byte)
    tst r0, r0                             ! flag == 0?
    bt      .L_negative_direction          ! yes: use negative Y direction
    ! --- Positive direction path ---
    mov.l @(4, r9), r14                    ! r14 = camera_target_vec[1] (Y component)
    shll8 r14                              ! r14 <<= 8 (scale to world coords)
    shll2 r14                              ! r14 <<= 2 (total shift: 10 bits)
    mov.l   _pool_positive_y_base, r3      ! r3 = 0x01A00000 (positive Y base offset)
    add r3, r14                            ! r14 = positive_base + scaled_Y
    bra     .L_write_scene_data            ! proceed to scene data output
    nop                                    ! delay slot
.L_negative_direction:
    mov.l @(4, r9), r14                    ! r14 = camera_target_vec[1] (Y component)
    shll8 r14                              ! r14 <<= 8
    shll2 r14                              ! r14 <<= 2 (total shift: 10 bits)
    neg r14, r14                           ! negate for negative direction
    mov.l   _pool_negative_y_base, r3      ! r3 = 0xFFA00000 (negative Y base offset)
    add r3, r14                            ! r14 = negative_base - scaled_Y
.L_write_scene_data:
    ! --- Write projected result to scene command queue ---
    mov.l   _pool_fn_cmd_queue_write, r3   ! r3 = &cmd_queue_write (sym_0603850C)
    jsr @r3                                ! cmd_queue_write(channel=4)
    mov #0x4, r4                           ! r4 = 4 (channel ID) (delay slot)
    mov #0x0, r6                           ! r6 = 0 (Z component = 0 for 2D output)
    mov.l @r9, r5                          ! r5 = camera_target_vec[0] (X/angle)
    mov.l   _pool_x_position_offset, r3    ! r3 = 0x003A0000 (screen X offset, 16.16)
    shll8 r5                               ! r5 <<= 8
    shll r5                                ! r5 <<= 1 (total shift: 9 bits)
    neg r5, r5                             ! negate X for screen-space convention
    add r3, r5                             ! r5 = screen_x_offset - scaled_angle
    mov.l   _pool_fn_scene_data_write, r3  ! r3 = &scene_data_write_abs
    jsr @r3                                ! scene_data_write_abs(y_pos, x_pos, 0)
    mov r14, r4                            ! r4 = y_pos (delay slot)
    ! --- Commit command queue and clean up ---
    mov.l   _pool_fn_cmd_queue_commit, r3  ! r3 = &cmd_queue_commit (sym_06038520)
    jsr @r3                                ! cmd_queue_commit()
    nop                                    ! delay slot
    add #0x34, r15                         ! deallocate stack frame
    lds.l @r15+, pr                        ! restore return address
    mov.l @r15+, r8                        ! restore r8
    mov.l @r15+, r9                        ! restore r9
    mov.l @r15+, r10                       ! restore r10
    mov.l @r15+, r11                       ! restore r11
    mov.l @r15+, r12                       ! restore r12
    mov.l @r15+, r13                       ! restore r13
    rts                                    ! return
    mov.l @r15+, r14                       ! restore r14 (delay slot)
_pool_fn_matrix_entry_init:
    .4byte  sym_06026E0C                   /* matrix entry init from current ptr */
_pool_camera_target_vec_2:
    .4byte  sym_06063EEC                   /* camera target vector (output) */
_pool_cam_dir_flip_flag:
    .4byte  sym_06078663                   /* camera direction flip flag (byte) */
_pool_positive_y_base:
    .4byte  0x01A00000                     /* positive Y base offset (16.16 fixed-point) */
_pool_negative_y_base:
    .4byte  0xFFA00000                     /* negative Y base offset (16.16 fixed-point) */
_pool_fn_cmd_queue_write:
    .4byte  sym_0603850C                   /* cmd queue: write channel ID */
_pool_x_position_offset:
    .4byte  0x003A0000                     /* screen X position offset (16.16) */
_pool_fn_scene_data_write:
    .4byte  scene_data_write_abs           /* scene data: write absolute coords */
_pool_fn_cmd_queue_commit:
    .4byte  sym_06038520                   /* cmd queue: commit */
