
    .section .text.FUN_06019FB2


    .global course2_physics_init
    .type course2_physics_init, @function
course2_physics_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x6, r11
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15

    .byte   0xD8, 0x08    /* mov.l .L_pool_car_model_table, r8 */   ! r8 = &car_model_table (sym_06049B2C)
    .byte   0xD9, 0x08    /* mov.l .L_pool_block_copy, r9 */        ! r9 = &block_copy (sym_06028400)
    .byte   0xDC, 0x09    /* mov.l .L_pool_anim_counter, r12 */     ! r12 = &anim_counter_byte (sym_0605D242)
    .byte   0xD0, 0x09    /* mov.l .L_pool_game_config, r0 */       ! r0 = &game_config_byte (sym_06085FF0)
    mov.b @r0, r0
    cmp/eq #0x2, r0
    bt/s    .L_expert_path
    mov #0x5, r14

    mov #0x0, r13
.L_normal_loop:
    extu.b r13, r2
    .byte   0xD3, 0x07    /* mov.l .L_pool_player_car_index, r3 */  ! r3 = &player_car_index (sym_0605AD04)
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_normal_not_player
    bra     .L_normal_apply_index
    extu.b r11, r10
    .2byte  0xFFFF

.L_pool_car_model_table:
    .4byte  sym_06049B2C        /* car model index table (word array, course 2) */
.L_pool_block_copy:
    .4byte  sym_06028400        /* block_copy function */
.L_pool_anim_counter:
    .4byte  sym_0605D242        /* animation counter byte */
.L_pool_game_config:
    .4byte  sym_06085FF0        /* game config / course selection byte */
.L_pool_player_car_index:
    .4byte  sym_0605AD04        /* player car index (long) for course 2 */

.L_normal_not_player:
    extu.b r14, r10

.L_normal_apply_index:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @(8, r15)
    shll2 r7
    mov.w @(r0, r8), r3
    .byte   0xD2, 0x35    /* mov.l .L_pool_physics_data_table, r2 */ ! r2 = &physics_data_table (sym_06063750)
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.l @(8, r15), r6
    add r3, r7
    .byte   0xD3, 0x31    /* mov.l .L_pool_course_param_offsets, r3 */ ! r3 = &course_param_offsets (sym_06049B22)
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov.l @r15, r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4

    add #0x1, r13
    extu.b r13, r3
    cmp/ge r14, r3
    bf      .L_normal_loop
    bra     .L_epilogue
    nop

.L_expert_path:
    mov #0x0, r13
.L_expert_loop:
    extu.b r13, r2
    .byte   0xD3, 0x25    /* mov.l .L_pool_player_car_index_b, r3 */ ! r3 = &player_car_index (sym_0605AD04)
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_expert_not_player

    mov #0x8, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_expert_counter_high
    bra     .L_expert_apply_index
    extu.b r11, r10

.L_expert_counter_high:
    mov #0x10, r3
    mov.b @r12, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bf/s    .L_expert_use_index_7
    mov #0x7, r10
    mov #0x0, r3
    mov.b r3, @r12

.L_expert_use_index_7:
    bra     .L_expert_apply_index
    nop

.L_expert_not_player:
    mov #0x3, r10

.L_expert_apply_index:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @r15
    shll2 r7
    mov.w @(r0, r8), r3
    .byte   0xD2, 0x14    /* mov.l .L_pool_physics_data_table, r2 */ ! r2 = &physics_data_table (sym_06063750)
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(8, r15)
    mov.l @(4, r2), r3
    mov.l @r15, r6
    add r3, r7
    .byte   0xD3, 0x11    /* mov.l .L_pool_course_param_offsets, r3 */ ! r3 = &course_param_offsets (sym_06049B22)
    add r3, r6
    mov.l r6, @(4, r15)
    mov.b @(1, r6), r0
    mov.l @(4, r15), r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(8, r15), r5
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4

    add #0x1, r13
    extu.b r13, r3
    cmp/ge r14, r3
    bf      .L_expert_loop

.L_epilogue:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF

.L_pool_physics_data_table:
    .4byte  sym_06063750        /* physics data table base (8-byte records per car model) */
.L_pool_course_param_offsets:
    .4byte  sym_06049B22        /* course 2 per-car parameter offset table */
.L_pool_player_car_index_b:
    .4byte  sym_0605AD04        /* player car index (long) for course 2 (expert path copy) */
