
    .section .text.FUN_06019DB8


    .global course1_physics_init
    .type course1_physics_init, @function

course1_physics_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x6, r11
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15

    mov.l   .L_pool_car_model_table, r8
    mov.l   .L_pool_dlist_loader, r9
    mov.l   .L_pool_display_phase_ctr, r12
    mov.l   .L_pool_game_config, r0
    mov.b @r0, r0
    cmp/eq #0x1, r0
    bt/s    .L_active_path
    mov #0x5, r14

    mov #0x0, r13
.L_normal_loop_top:
    extu.b r13, r2
    mov.l   .L_pool_player_car_index, r3
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_normal_not_player
    bra     .L_normal_slot_chosen
    extu.b r11, r10
.L_normal_not_player:
    extu.b r14, r10

.L_normal_slot_chosen:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @(8, r15)
    shll2 r7
    mov.w @(r0, r8), r3
    mov.l   .L_pool_car_obj_table, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.l @(8, r15), r6
    add r3, r7
    mov.l   .L_pool_dlist_offset_table, r3
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
    bf      .L_normal_loop_top
    bra     .L_epilogue
    nop

.L_active_path:
    mov #0x0, r13
.L_active_loop_top:
    extu.b r13, r2
    mov.l   .L_pool_player_car_index, r3
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_active_not_player

    mov #0x8, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_active_phase_ge_8
    bra     .L_active_slot_chosen
    extu.b r11, r10

.L_active_phase_ge_8:
    mov #0x10, r3
    mov.b @r12, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bf/s    .L_active_phase_le_16
    mov #0x7, r10
    mov #0x0, r3
    mov.b r3, @r12
.L_active_phase_le_16:
    bra     .L_active_slot_chosen
    nop
    .2byte  0xFFFF

.L_pool_car_model_table:
    .4byte  sym_06049B2C
.L_pool_dlist_loader:
    .4byte  sym_06028400
.L_pool_display_phase_ctr:
    .4byte  sym_0605D242
.L_pool_game_config:
    .4byte  sym_06085FF0
.L_pool_player_car_index:
    .4byte  sym_0605AD0C
.L_pool_car_obj_table:
    .4byte  sym_06063750
.L_pool_dlist_offset_table:
    .4byte  sym_06049B18

.L_active_not_player:
    mov #0x3, r10

.L_active_slot_chosen:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @r15
    shll2 r7
    mov.w @(r0, r8), r3
    .byte   0xD2, 0x29    /* mov.l .L_pool_06019F44, r2 */  ! r2 -> car object table (sym_06063750, cross-TU pool)
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(8, r15)
    mov.l @(4, r2), r3
    mov.l @r15, r6
    add r3, r7
    .byte   0xD3, 0x25    /* mov.l .L_pool_06019F48, r3 */  ! r3 -> course 1 dlist offset table (sym_06049B18, cross-TU pool)
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
    bf      .L_active_loop_top

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
