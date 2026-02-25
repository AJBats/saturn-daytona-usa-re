/* render_obj_absolute -- Scene Object Renderer Type B (Absolute Transform)
 * Translation unit: 0x0600AC44 - 0x0600ADD4
 *
 * Renders hierarchical scene objects using absolute (replace) transforms.
 * Sibling of render_obj_additive (Type A); both are called from the course-
 * specific object rendering path.  Where additive uses push/translate/rot_y,
 * this variant loads position directly, then applies XY and XZ rotations to
 * build an absolute orientation matrix.
 *
 * Pipeline per sub-object (3 total):
 *   1. Index into config table at sym_0605A1D5 + (index << 2)
 *   2. Read 4 config bytes: [0]=node_id, [1]=child1, [2]=child2, [3]=type
 *   3. matrix_push(node_id) — initialize transform state
 *   4. Load position from static position table (XYZ triplet)
 *   5. camera_pos(X, Y, -Z) — set absolute position (Z negated)
 *   6. mat_rot_xy_b(obj[+0x40] << 1) — combined XY rotation (scaled)
 *   7. mat_rot_xz_b(-obj[+0x48]) — XZ rotation (negated)
 *   8. Look up transform chain pointers by config byte
 *   9. vec_transform(chain_A_param[id], chain_A_src[id])
 *  10. vec_scale(chain_B_param[id], sprite_idx, chain_B_src[id])
 *  11. Decrement render budget at sym_0608A52C by 0x30
 *
 * Sub-object 0 uses position table 1 (sym_06044640).
 * Sub-object 1 uses position table 2 (sym_0604464C).
 * Sub-object 2 uses position table 3 (sym_06044670, loaded in second pool).
 *
 * Render budget model: each object costs 48 bytes (0x30) from
 * per-frame allocation at sym_0608A52C.
 *
 * params: r4 = object base pointer, r5 = sub-object index
 */

    .section .text.FUN_0600AC44


    .global render_obj_absolute
    .type render_obj_absolute, @function
render_obj_absolute:
    mov.l r14, @-r15                     ! save r14
    mov.l r13, @-r15                     ! save r13
    mov.l r12, @-r15                     ! save r12
    mov r5, r13                          ! r13 = sub-object index
    mov.l r11, @-r15                     ! save r11
    shll2 r13                            ! r13 = index << 2 (4 bytes per config entry)
    mov.l r10, @-r15                     ! save r10
    mov r4, r10                          ! r10 = object base pointer
    mov.l r9, @-r15                      ! save r9
    mov.l r8, @-r15                      ! save r8
    sts.l pr, @-r15                      ! save return address
    add #-0x10, r15                      ! allocate 16 bytes of locals on stack
    mov.l   .L_config_table_base, r3     ! r3 = config table base (sym_0605A1D5)
    add r3, r13                          ! r13 = &config_table[index] (4-byte entry)
    mov.b @(3, r13), r0                  ! r0 = config[3] (type byte)
    mov r0, r2                           ! r2 = type byte
    extu.b r2, r2                        ! zero-extend to unsigned
    mov #0x48, r0                        ! offset +0x48 into object base
    mov.l r2, @(8, r15)                  ! sp[8] = type byte (saved for sprite index)
    mov.l @(r0, r10), r3                 ! r3 = obj[+0x48] (XZ rotation angle)
    mov #0x40, r0                        ! offset +0x40 into object base
    neg r3, r3                           ! negate XZ rotation angle
    mov.l r3, @(4, r15)                  ! sp[4] = -obj[+0x48] (negated XZ rotation)
    mov.l @(r0, r10), r3                 ! r3 = obj[+0x40] (XY rotation angle)
    shll r3                              ! r3 <<= 1 (scale rotation)
    mov.l r3, @r15                       ! sp[0] = obj[+0x40] << 1 (XY rotation param)
    mov.b @r13, r2                       ! r2 = config[0] (node_id for sub-object 0)
    mov.l   .L_fn_matrix_push, r1       ! r1 = matrix push function
    extu.b r2, r2                        ! zero-extend node_id
    jsr @r1                              ! matrix_push(node_id)
    mov.l r2, @(12, r15)                 ! (delay) sp[12] = node_id (saved for chain lookup)
    mov.l   .L_pos_table_1, r14         ! r14 = position table 1 (sym_06044640, sub-obj 0)
    mov.l   .L_fn_camera_pos, r3        ! r3 = camera_pos function (absolute position set)
    mov.l @(8, r14), r6                  ! r6 = position1.Z
    mov.l @(4, r14), r5                  ! r5 = position1.Y
    neg r6, r6                           ! r6 = -Z (negate for coordinate system)
    jsr @r3                              ! camera_pos(X, Y, -Z)
    mov.l @r14, r4                       ! (delay) r4 = position1.X
    mov.l   .L_fn_rot_xy, r3            ! r3 = mat_rot_xy_b function
    jsr @r3                              ! mat_rot_xy_b(XY_angle)
    mov.l @r15, r4                       ! (delay) r4 = sp[0] = XY rotation param
    mov.l   .L_fn_rot_xz, r3            ! r3 = mat_rot_xz_b function
    jsr @r3                              ! mat_rot_xz_b(XZ_angle)
    mov.l @(4, r15), r4                  ! (delay) r4 = sp[4] = negated XZ rotation
    mov.l   .L_chain_A_param_base, r11  ! r11 = chain A parameter table base (sym_0606212C)
    mov.l @(12, r15), r14                ! r14 = node_id from sp[12]
    mov.l   .L_chain_A_src_base, r5     ! r5 = chain A source table base (sym_060621D8)
    mov.l   .L_fn_vec_transform, r3     ! r3 = vec_transform function (sym_06032158)
    shll2 r14                            ! r14 = node_id << 2 (word offset into arrays)
    add r14, r5                          ! r5 = &chain_A_src[node_id]
    mov r14, r4                          ! r4 = node_id << 2
    mov.l @r5, r5                        ! r5 = chain_A_src[node_id] (model data ptr)
    add r11, r4                          ! r4 = &chain_A_param[node_id]
    jsr @r3                              ! vec_transform(chain_A_param[id], chain_A_src[id])
    mov.l @r4, r4                        ! (delay) r4 = chain_A_param[node_id]
    mov r14, r4                          ! r4 = node_id << 2
    mov.l   .L_fn_vec_scale, r2         ! r2 = vec_scale function (sym_06031DF4)
    mov.l   .L_chain_B_param_base, r8   ! r8 = chain B parameter table base (sym_060620D8, kept)
    mov.l   .L_chain_B_src_base, r6     ! r6 = chain B source table base (sym_06062180)
    mov.l @(8, r15), r9                  ! r9 = type byte from sp[8]
    mov.l   .L_sprite_index_table, r3   ! r3 = sprite word index table (sym_06089E44)
    add r8, r4                           ! r4 = &chain_B_param[node_id]
    add r14, r6                          ! r6 = &chain_B_src[node_id]
    shll r9                              ! r9 = type << 1 (word index into sprite table)
    mov.l @r6, r6                        ! r6 = chain_B_src[node_id]
    add r3, r9                           ! r9 = &sprite_index_table[type] (kept for sub-obj 1,2)
    mov.w @r9, r5                        ! r5 = sprite_index_table[type] (sprite word index)
    extu.w r5, r5                        ! zero-extend sprite index to 32-bit
    jsr @r2                              ! vec_scale(chain_B_param[id], sprite_idx, chain_B_src[id])
    mov.l @r4, r4                        ! (delay) r4 = chain_B_param[node_id]
    mov.l   .L_render_budget, r14       ! r14 = &render_budget (sym_0608A52C, kept for sub-obj 1,2)
    mov.l @r14, r3                       ! r3 = current render budget
    add #-0x30, r3                       ! r3 -= 0x30 (48 bytes per object)
    mov.l r3, @r14                       ! write back decremented budget
    mov.b @(1, r13), r0                  ! r0 = config[1] (child1 node_id for sub-object 1)
    mov.l   .L_fn_matrix_push, r3       ! r3 = matrix push function
    mov r0, r2                           ! r2 = child1 node_id
    extu.b r2, r2                        ! zero-extend
    jsr @r3                              ! matrix_push(child1_node_id)
    mov.l r2, @(8, r15)                  ! (delay) sp[8] = child1 node_id
    mov.l   .L_pos_table_2, r12         ! r12 = position table 2 (sym_0604464C, sub-obj 1)
    mov.l   .L_fn_camera_pos, r3        ! r3 = camera_pos function
    mov.l @(8, r12), r6                  ! r6 = position2.Z
    mov.l @(4, r12), r5                  ! r5 = position2.Y
    neg r6, r6                           ! r6 = -Z (negate for coordinate system)
    jsr @r3                              ! camera_pos(X, Y, -Z)
    mov.l @r12, r4                       ! (delay) r4 = position2.X
    mov.l   .L_fn_rot_xy, r3            ! r3 = mat_rot_xy_b function
    jsr @r3                              ! mat_rot_xy_b(XY_angle)
    mov.l @r15, r4                       ! (delay) r4 = sp[0] = XY rotation param
    mov.l   .L_fn_rot_xz, r3            ! r3 = mat_rot_xz_b function
    jsr @r3                              ! mat_rot_xz_b(XZ_angle)
    mov.l @(4, r15), r4                  ! (delay) r4 = sp[4] = negated XZ rotation
    mov.l @(8, r15), r12                 ! r12 = child1 node_id from sp[8]
    mov.l   .L_chain_A_src_base, r5     ! r5 = chain A source table base
    mov.l   .L_fn_vec_transform, r3     ! r3 = vec_transform function
    shll2 r12                            ! r12 = child1_id << 2 (word offset)
    add r12, r5                          ! r5 = &chain_A_src[child1_id]
    mov r12, r4                          ! r4 = child1_id << 2
    mov.l @r5, r5                        ! r5 = chain_A_src[child1_id]
    add r11, r4                          ! r4 = &chain_A_param[child1_id]
    jsr @r3                              ! vec_transform(chain_A_param[child1], chain_A_src[child1])
    mov.l @r4, r4                        ! (delay) r4 = chain_A_param[child1_id]
    mov r12, r4                          ! r4 = child1_id << 2
    mov.l   .L_fn_vec_scale, r3         ! r3 = vec_scale function
    mov.l   .L_chain_B_src_base, r6     ! r6 = chain B source table base
    mov.w @r9, r5                        ! r5 = sprite_index_table[type] (reuse r9)
    add r8, r4                           ! r4 = &chain_B_param[child1_id]
    add r12, r6                          ! r6 = &chain_B_src[child1_id]
    extu.w r5, r5                        ! zero-extend sprite index to 32-bit
    mov.l @r6, r6                        ! r6 = chain_B_src[child1_id]
    jsr @r3                              ! vec_scale(chain_B_param[child1], sprite_idx, chain_B_src[child1])
    mov.l @r4, r4                        ! (delay) r4 = chain_B_param[child1_id]
    mov.l @r14, r2                       ! r2 = current render budget
    add #-0x30, r2                       ! r2 -= 0x30 (48 bytes per object)
    mov.l r2, @r14                       ! write back decremented budget
    mov #0x50, r0                        ! offset +0x50 into object base
    mov.l @(r0, r10), r3                 ! r3 = obj[+0x50] (rotation angle for sub-obj 2)
    neg r3, r3                           ! negate rotation
    bra     .L_subobj_2                  ! branch to sub-object 2 processing
    nop                                  ! delay slot (NOP)
    .2byte  0xFFFF                       ! alignment padding
.L_config_table_base:
    .4byte  sym_0605A1D5                  ! object config table (4 bytes per entry)
.L_fn_matrix_push:
    .4byte  sym_06027080                  ! matrix push / pre-transform setup
.L_pos_table_1:
    .4byte  sym_06044640                  ! static position table 1 (sub-obj 0, XYZ triplet)
.L_fn_camera_pos:
    .4byte  sym_060270F2                  ! absolute position set (camera_pos)
.L_fn_rot_xy:
    .4byte  mat_rot_xy_b                  ! combined XY rotation
.L_fn_rot_xz:
    .4byte  mat_rot_xz_b                  ! combined XZ rotation
.L_chain_A_param_base:
    .4byte  sym_0606212C                  ! chain A parameter table (per-object transform params)
.L_chain_A_src_base:
    .4byte  sym_060621D8                  ! chain A source table (object model data)
.L_fn_vec_transform:
    .4byte  sym_06032158                  ! vector matrix transform
.L_chain_B_param_base:
    .4byte  sym_060620D8                  ! chain B parameter table (display transform params)
.L_chain_B_src_base:
    .4byte  sym_06062180                  ! chain B source table (display model data)
.L_sprite_index_table:
    .4byte  sym_06089E44                  ! sprite word index table (16-bit entries)
.L_fn_vec_scale:
    .4byte  sym_06031DF4                  ! scaled vector transform
.L_render_budget:
    .4byte  sym_0608A52C                  ! render budget counter (decremented by 0x30)
.L_pos_table_2:
    .4byte  sym_0604464C                  ! static position table 2 (sub-obj 1, XYZ triplet)
.L_subobj_2:
    mov.l r3, @r15                       ! sp[0] = -obj[+0x50] (XZ rotation for sub-obj 2)
    mov.b @(2, r13), r0                  ! r0 = config[2] (child2 node_id for sub-object 2)
    .byte   0xD1, 0x2C    /* mov.l .L_pool_0600AE2C, r1 */
    mov r0, r2                           ! r2 = child2 node_id
    extu.b r2, r2                        ! zero-extend node_id
    jsr @r1                              ! matrix_push(child2_node_id)
    mov.l r2, @(4, r15)                  ! (delay) sp[4] = child2 node_id
    .byte   0xDD, 0x2B    /* mov.l .L_pool_0600AE30, r13 */
    .byte   0xD3, 0x2B    /* mov.l .L_pool_0600AE34, r3 */
    mov.l @(8, r13), r6                  ! r6 = position3.Z
    mov.l @(4, r13), r5                  ! r5 = position3.Y
    neg r6, r6                           ! r6 = -Z (negate for coordinate system)
    jsr @r3                              ! camera_pos(X, Y, -Z)
    mov.l @r13, r4                       ! (delay) r4 = position3.X
    .byte   0xD3, 0x29    /* mov.l .L_pool_0600AE38, r3 */
    jsr @r3                              ! mat_rot_xy_b(XY_angle)
    mov.l @r15, r4                       ! (delay) r4 = sp[0] = XZ rotation param for sub-obj 2
    mov.l @(4, r15), r13                 ! r13 = child2 node_id from sp[4]
    .byte   0xD5, 0x28    /* mov.l .L_pool_0600AE3C, r5 */
    .byte   0xD3, 0x29    /* mov.l .L_pool_0600AE40, r3 */
    shll2 r13                            ! r13 = child2_id << 2 (word offset)
    add r13, r5                          ! r5 = &chain_A_src[child2_id]
    add r13, r11                         ! r11 = &chain_A_param[child2_id] (r11 still has base)
    mov.l @r5, r5                        ! r5 = chain_A_src[child2_id]
    jsr @r3                              ! vec_transform(chain_A_param[child2], chain_A_src[child2])
    mov.l @r11, r4                       ! (delay) r4 = chain_A_param[child2_id]
    .byte   0xD6, 0x26    /* mov.l .L_pool_0600AE44, r6 */
    add r13, r8                          ! r8 = &chain_B_param[child2_id] (r8 still has base)
    .byte   0xD3, 0x26    /* mov.l .L_pool_0600AE48, r3 */
    mov.w @r9, r5                        ! r5 = sprite_index_table[type] (reuse r9)
    add r13, r6                          ! r6 = &chain_B_src[child2_id]
    extu.w r5, r5                        ! zero-extend sprite index to 32-bit
    mov.l @r6, r6                        ! r6 = chain_B_src[child2_id]
    jsr @r3                              ! vec_scale(chain_B_param[child2], sprite_idx, chain_B_src[child2])
    mov.l @r8, r4                        ! (delay) r4 = chain_B_param[child2_id]
    mov.l @r14, r2                       ! r2 = current render budget
    add #-0x30, r2                       ! r2 -= 0x30 (48 bytes per object)
    mov.l r2, @r14                       ! write back decremented budget
    add #0x10, r15                       ! free 16 bytes of locals
    lds.l @r15+, pr                      ! restore return address
    mov.l @r15+, r8                      ! restore r8
    mov.l @r15+, r9                      ! restore r9
    mov.l @r15+, r10                     ! restore r10
    mov.l @r15+, r11                     ! restore r11
    mov.l @r15+, r12                     ! restore r12
    mov.l @r15+, r13                     ! restore r13
    rts                                  ! return
    mov.l @r15+, r14                     ! (delay) restore r14
