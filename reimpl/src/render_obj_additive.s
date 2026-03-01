/* render_obj_additive -- Scene Object Renderer Type A (Additive Transform)
 * Translation unit: 0x0600AA98 - 0x0600AC44
 *
 * Renders hierarchical scene objects using additive (push) transforms.
 * Called from the course-specific object rendering path.
 *
 * Pipeline per sub-object:
 *   1. Index into config table at sym_0605A1D5 + (index << 2)
 *   2. Read 4 config bytes: [0]=node_id, [1]=child1, [2]=child2, [3]=type
 *   3. Load position from static object table (sym_06044640 / sym_0604464C / sym_06044670)
 *   4. Push matrix via sym_06026DBC (matrix push)
 *   5. Translate via sym_06026E2E (X, Y=-Z, Z from position struct)
 *   6. Apply Y-axis rotation via mat_rot_y (from obj[+0x40] << 1)
 *   7. Apply X-axis rotation via mat_rot_x (negated from obj[+0x48])
 *   8. Look up car data struct pointers by config byte (4 car bases)
 *   9. Call sym_06031D8C (distance check / visibility culling)
 *  10. Call sym_06031A28 (sprite submission, word index from sym_06089E44)
 *  11. Decrement render budget at sym_06089EDC by 0x30 (48 bytes per object)
 *
 * Processes 3 sub-objects total from the config table entry.
 * Each sub-object uses a different position table base.
 *
 * Render budget model: each object costs 48 bytes (0x30) from
 * per-frame allocation at sym_06089EDC.
 *
 * params: r4 = object base pointer, r5 = sub-object index
 */

    .section .text.FUN_0600AA98


    .global render_obj_additive
    .type render_obj_additive, @function
render_obj_additive:
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
    mov.l @(r0, r10), r3                 ! r3 = obj[+0x48] (X-axis rotation angle)
    mov #0x40, r0                        ! offset +0x40 into object base
    neg r3, r3                           ! negate rotation angle
    mov.l r3, @(4, r15)                  ! sp[4] = -obj[+0x48] (negated X rotation)
    mov.l @(r0, r10), r3                 ! r3 = obj[+0x40] (Y-axis rotation angle)
    shll r3                              ! r3 <<= 1 (scale rotation)
    mov.l r3, @r15                       ! sp[0] = obj[+0x40] << 1 (Y rotation param)
    mov.b @r13, r2                       ! r2 = config[0] (node_id for sub-object 0)
    mov.l   .L_matrix_push, r1           ! r1 = matrix push function
    extu.b r2, r2                        ! zero-extend node_id
    jsr @r1                              ! call matrix_push(node_id)
    mov.l r2, @(12, r15)                 ! sp[12] = node_id (delay slot, saved for car lookup)
    mov.l   .L_position_table_1, r14      ! r14 = position table 1 (sym_06044640)
    mov.l   .L_translate_fn, r3           ! r3 = translate function
    mov.l @(8, r14), r6                   ! r6 = position.Z
    mov.l @(4, r14), r5                   ! r5 = position.Y
    neg r6, r6                            ! r6 = -Z (negate for coordinate system)
    jsr @r3                               ! call translate(X, Y, -Z)
    mov.l @r14, r4                        ! r4 = position.X (delay slot)
    mov.l   .L_rot_y_fn, r3              ! r3 = mat_rot_y function
    jsr @r3                               ! call mat_rot_y(Y_angle)
    mov.l @r15, r4                        ! r4 = sp[0] = Y rotation param (delay slot)
    mov.l   .L_transform_fn, r3          ! r3 = mat_rot_x function
    jsr @r3                               ! call mat_rot_x(X_angle)
    mov.l @(4, r15), r4                   ! r4 = sp[4] = negated X rotation (delay slot)
    mov.l   .L_car_data_1, r11            ! r11 = car_data_1 base (sym_0606212C)
    mov.l @(12, r15), r14                 ! r14 = node_id from sp[12]
    mov.l   .L_car_data_3, r5            ! r5 = car_data_3 base (sym_060621D8)
    mov.l   .L_dist_check_fn, r3         ! r3 = distance check function
    shll2 r14                             ! r14 = node_id << 2 (word offset into arrays)
    add r14, r5                           ! r5 = &car_data_3[node_id]
    mov r14, r4                           ! r4 = node_id << 2
    mov.l @r5, r5                         ! r5 = car_data_3[node_id] (model data ptr)
    add r11, r4                           ! r4 = &car_data_1[node_id]
    jsr @r3                               ! call dist_check(car_data_1[node_id], car_data_3[node_id])
    mov.l @r4, r4                         ! r4 = car_data_1[node_id] (delay slot)
    mov r14, r4                           ! r4 = node_id << 2
    mov.l   .L_sprite_submit_fn, r2      ! r2 = sprite submission function
    mov.l   .L_car_data_0, r8            ! r8 = car_data_0 base (sym_060620D8, kept for sub-obj 1)
    mov.l   .L_car_data_2, r6            ! r6 = car_data_2 base (sym_06062180)
    mov.l @(8, r15), r9                   ! r9 = type byte from sp[8]
    mov.l   .L_sprite_index_table, r3    ! r3 = sprite index table (sym_06089E44)
    add r8, r4                            ! r4 = &car_data_0[node_id]
    add r14, r6                           ! r6 = &car_data_2[node_id]
    shll r9                               ! r9 = type << 1 (word index)
    mov.l @r6, r6                         ! r6 = car_data_2[node_id] (color/material data)
    add r3, r9                            ! r9 = &sprite_index_table[type] (kept for sub-obj 1,2)
    mov.w @r9, r5                         ! r5 = sprite_index_table[type] (sprite word index)
    jsr @r2                               ! call sprite_submit(car_data_0[node_id], sprite_idx, color)
    mov.l @r4, r4                         ! r4 = car_data_0[node_id] (delay slot)
    mov.l   .L_render_budget, r14         ! r14 = &render_budget (sym_06089EDC, kept for sub-obj 1,2)
    mov.l @r14, r3                        ! r3 = current render budget
    add #-0x30, r3                        ! r3 -= 0x30 (48 bytes per object)
    mov.l r3, @r14                        ! write back decremented budget
    mov.b @(1, r13), r0                   ! r0 = config[1] (child1 node_id for sub-object 1)
    mov.l   .L_matrix_push, r3           ! r3 = matrix push function
    mov r0, r2                            ! r2 = child1 node_id
    extu.b r2, r2                         ! zero-extend
    jsr @r3                               ! call matrix_push(child1_node_id)
    mov.l r2, @(8, r15)                   ! sp[8] = child1 node_id (delay slot)
    mov.l   .L_position_table_2, r12      ! r12 = position table 2 (sym_0604464C)
    mov.l   .L_translate_fn, r3           ! r3 = translate function
    mov.l @(8, r12), r6                   ! r6 = position2.Z
    mov.l @(4, r12), r5                   ! r5 = position2.Y
    neg r6, r6                            ! r6 = -Z (negate for coordinate system)
    jsr @r3                               ! call translate(X, Y, -Z)
    mov.l @r12, r4                        ! r4 = position2.X (delay slot)
    mov.l   .L_rot_y_fn, r3              ! r3 = mat_rot_y function
    jsr @r3                               ! call mat_rot_y(Y_angle)
    mov.l @r15, r4                        ! r4 = sp[0] = Y rotation param (delay slot)
    mov.l   .L_transform_fn, r3          ! r3 = mat_rot_x function
    jsr @r3                               ! call mat_rot_x(X_angle)
    mov.l @(4, r15), r4                   ! r4 = sp[4] = negated X rotation (delay slot)
    mov.l @(8, r15), r12                  ! r12 = child1 node_id from sp[8]
    mov.l   .L_car_data_3, r5            ! r5 = car_data_3 base
    mov.l   .L_dist_check_fn, r3         ! r3 = distance check function
    shll2 r12                             ! r12 = child1_id << 2 (word offset)
    add r12, r5                           ! r5 = &car_data_3[child1_id]
    mov r12, r4                           ! r4 = child1_id << 2
    mov.l @r5, r5                         ! r5 = car_data_3[child1_id]
    add r11, r4                           ! r4 = &car_data_1[child1_id]
    jsr @r3                               ! call dist_check(car_data_1[child1], car_data_3[child1])
    mov.l @r4, r4                         ! r4 = car_data_1[child1_id] (delay slot)
    mov.l   .L_car_data_2, r6            ! r6 = car_data_2 base
    mov r12, r4                           ! r4 = child1_id << 2
    mov.l   .L_sprite_submit_fn, r3      ! r3 = sprite submission function
    mov.w @r9, r5                         ! r5 = sprite_index_table[type] (reuse from r9)
    add r12, r6                           ! r6 = &car_data_2[child1_id]
    add r8, r4                            ! r4 = &car_data_0[child1_id]
    mov.l @r6, r6                         ! r6 = car_data_2[child1_id]
    jsr @r3                               ! call sprite_submit(car_data_0[child1], sprite_idx, color)
    mov.l @r4, r4                         ! r4 = car_data_0[child1_id] (delay slot)
    mov.l @r14, r2                        ! r2 = current render budget
    add #-0x30, r2                        ! r2 -= 0x30 (48 bytes per object)
    mov.l r2, @r14                        ! write back decremented budget
    mov #0x50, r0                         ! offset +0x50 into object base
    mov.l @(r0, r10), r3                  ! r3 = obj[+0x50] (rotation angle for sub-obj 2)
    neg r3, r3                            ! negate rotation
    mov.l r3, @r15                        ! sp[0] = -obj[+0x50] (X rotation for sub-obj 2)
    mov.b @(2, r13), r0                   ! r0 = config[2] (child2 node_id for sub-object 2)
    bra     .L_subobj_2                   ! branch to sub-object 2 processing
    nop                                   ! delay slot (NOP)
    .2byte  0xFFFF                        ! alignment padding
.L_config_table_base:
    .4byte  sym_0605A1D5                  ! object config table (4 bytes per entry)
.L_matrix_push:
    .4byte  sym_06026DBC                  ! matrix push (additive transform)
.L_position_table_1:
    .4byte  sym_06044640                  ! static position table 1 (sub-obj 0)
.L_translate_fn:
    .4byte  sym_06026E2E                  ! translate (X, Y, Z)
.L_rot_y_fn:
    .4byte  mat_rot_y                     ! Y-axis rotation
.L_transform_fn:
    .4byte  mat_rot_x              ! X-axis rotation / transform
.L_car_data_1:
    .4byte  sym_0606212C                  ! car data struct base 1
.L_car_data_3:
    .4byte  sym_060621D8                  ! car data struct base 3
.L_dist_check_fn:
    .4byte  sym_06031D8C                  ! distance check / visibility culling
.L_car_data_0:
    .4byte  sym_060620D8                  ! car data struct base 0 (player)
.L_car_data_2:
    .4byte  sym_06062180                  ! car data struct base 2
.L_sprite_index_table:
    .4byte  sym_06089E44                  ! sprite word index table
.L_sprite_submit_fn:
    .4byte  sym_06031A28                  ! sprite submission function
.L_render_budget:
    .4byte  sym_06089EDC                  ! render budget counter (decremented by 0x30)
.L_position_table_2:
    .4byte  sym_0604464C                  ! static position table 2 (sub-obj 1)
.L_subobj_2:
    mov r0, r2                            ! r2 = child2 node_id (from config[2])
    mov.l   .L_matrix_push_2, r1         ! r1 = matrix push function
    extu.b r2, r2                         ! zero-extend node_id
    jsr @r1                               ! call matrix_push(child2_node_id)
    mov.l r2, @(4, r15)                   ! sp[4] = child2 node_id (delay slot)
    mov.l   .L_position_table_3, r13     ! r13 = position table 3 (sym_06044670)
    mov.l   .L_translate_fn_2, r3        ! r3 = translate function
    mov.l @(8, r13), r6                   ! r6 = position3.Z
    mov.l @(4, r13), r5                   ! r5 = position3.Y
    neg r6, r6                            ! r6 = -Z (negate for coordinate system)
    jsr @r3                               ! call translate(X, Y, -Z)
    mov.l @r13, r4                        ! r4 = position3.X (delay slot)
    mov.l   .L_transform_fn_2, r3        ! r3 = mat_rot_x function
    jsr @r3                               ! call mat_rot_x(X_angle)
    mov.l @r15, r4                        ! r4 = sp[0] = rotation param (delay slot)
    mov.l @(4, r15), r13                  ! r13 = child2 node_id from sp[4]
    mov.l   .L_car_data_3_2, r5          ! r5 = car_data_3 base
    mov.l   .L_dist_check_fn_2, r3       ! r3 = distance check function
    shll2 r13                             ! r13 = child2_id << 2 (word offset)
    add r13, r5                           ! r5 = &car_data_3[child2_id]
    add r13, r11                          ! r11 = &car_data_1[child2_id] (r11 still has car_data_1 base)
    mov.l @r5, r5                         ! r5 = car_data_3[child2_id]
    jsr @r3                               ! call dist_check(car_data_1[child2], car_data_3[child2])
    mov.l @r11, r4                        ! r4 = car_data_1[child2_id] (delay slot)
    mov.l   .L_car_data_2_2, r6          ! r6 = car_data_2 base
    add r13, r8                           ! r8 = &car_data_0[child2_id] (r8 still has car_data_0 base)
    mov.l   .L_sprite_submit_fn_2, r3    ! r3 = sprite submission function
    mov.w @r9, r5                         ! r5 = sprite_index_table[type] (reuse from r9)
    add r13, r6                           ! r6 = &car_data_2[child2_id]
    mov.l @r6, r6                         ! r6 = car_data_2[child2_id]
    jsr @r3                               ! call sprite_submit(car_data_0[child2], sprite_idx, color)
    mov.l @r8, r4                         ! r4 = car_data_0[child2_id] (delay slot)
    mov.l @r14, r2                        ! r2 = current render budget
    add #-0x30, r2                        ! r2 -= 0x30 (48 bytes per object)
    mov.l r2, @r14                        ! write back decremented budget
    add #0x10, r15                        ! free 16 bytes of locals
    lds.l @r15+, pr                       ! restore return address
    mov.l @r15+, r8                       ! restore r8
    mov.l @r15+, r9                       ! restore r9
    mov.l @r15+, r10                      ! restore r10
    mov.l @r15+, r11                      ! restore r11
    mov.l @r15+, r12                      ! restore r12
    mov.l @r15+, r13                      ! restore r13
    rts                                   ! return
    mov.l @r15+, r14                      ! restore r14 (delay slot)
    .2byte  0xFFFF                        ! alignment padding
.L_matrix_push_2:
    .4byte  sym_06026DBC                  ! matrix push (additive transform)
.L_position_table_3:
    .4byte  sym_06044670                  ! static position table 3 (sub-obj 2)
.L_translate_fn_2:
    .4byte  sym_06026E2E                  ! translate (X, Y, Z)
.L_transform_fn_2:
    .4byte  mat_rot_x              ! X-axis rotation / transform
.L_car_data_3_2:
    .4byte  sym_060621D8                  ! car data struct base 3
.L_dist_check_fn_2:
    .4byte  sym_06031D8C                  ! distance check / visibility culling
.L_car_data_2_2:
    .4byte  sym_06062180                  ! car data struct base 2
.L_sprite_submit_fn_2:
    .4byte  sym_06031A28                  ! sprite submission function
