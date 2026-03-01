
    .section .text.FUN_0601A65E


    .global car_init_handler
    .type car_init_handler, @function
car_init_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD0, 0x1E    /* mov.l _pool_car_course_index, r0 */
    mov.b @r0, r0
    cmp/eq #0x3, r0
    bf/s    .L_0601A69A
    mov #0x6, r5
    .byte   0xD4, 0x1C    /* mov.l _pool_display_phase_ctr, r4 */
    mov #0x8, r3
    mov.b @r4, r2
    extu.b r2, r2
    cmp/ge r3, r2
    bt/s    .L_0601A686
    mov #0x3, r12
    bra     .L_0601A69E
    extu.b r5, r14
.L_0601A686:
    mov #0x10, r3
    mov.b @r4, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bf/s    .L_0601A696
    mov #0x7, r14
    mov #0x0, r3
    mov.b r3, @r4
.L_0601A696:
    bra     .L_0601A69E
    nop
.L_0601A69A:
    extu.b r5, r14
    mov #0x5, r12
.L_0601A69E:
    .byte   0xDB, 0x13    /* mov.l _pool_car_obj_table, r11 */
    .byte   0xDD, 0x13    /* mov.l _pool_dlist_loader, r13 */
    .byte   0xD2, 0x14    /* mov.l _pool_two_player_flag, r2 */
    mov.b @r2, r2
    tst r2, r2
    bf      .L_0601A6F8
    extu.b r14, r7
    mov.w   DAT_0601a6de, r3
    shll8 r7
    add r11, r3
    shll2 r7
    mov.l r3, @r15
    shll2 r7
    mov.l @(4, r3), r3
    mov.w   DAT_0601a6e0, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    extu.b r12, r7
    shll8 r7
    shll2 r7
    shll2 r7
    mov.w   DAT_0601a6e2, r3
    add r11, r3
    mov.l r3, @r15
    mov.l @(4, r3), r3
    add r3, r7
    bra     .L_0601A726
    nop
    .2byte  0x00A9

    .global DAT_0601a6de
DAT_0601a6de:
    .2byte  0x0418

    .global DAT_0601a6e0
DAT_0601a6e0:
    .2byte  0x0624

    .global DAT_0601a6e2
DAT_0601a6e2:
    .2byte  0x0420
_pool_car_course_index:
    .4byte  sym_06085FF0
_pool_display_phase_ctr:
    .4byte  sym_0605D242
_pool_car_obj_table:
    .4byte  sym_06063750
_pool_dlist_loader:
    .4byte  sym_06028400
_pool_two_player_flag:
    .4byte  sym_0605D241
.L_0601A6F8:
    extu.b r12, r7
    mov.w   DAT_0601a756, r3
    shll8 r7
    add r11, r3
    shll2 r7
    mov.l r3, @r15
    shll2 r7
    mov.l @(4, r3), r3
    mov.w   DAT_0601a758, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    extu.b r14, r7
    shll8 r7
    shll2 r7
    shll2 r7
    mov.w   DAT_0601a75a, r3
    add r11, r3
    mov.l r3, @r15
    mov.l @(4, r3), r3
    add r3, r7
.L_0601A726:
    mov.w   _wpool_final_dlist_size, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0601A73E
sym_0601A73E:
    .byte   0xD3, 0x08    /* mov.l _pool_two_player_flag_b, r3 */
    mov.b @r3, r3
    tst r3, r3
    bf      .L_0601A74E
    .byte   0xD5, 0x07    /* mov.l _pool_snd_cmd_1p, r5 */
    .byte   0xD3, 0x07    /* mov.l _pool_fn_sound_cmd_dispatch, r3 */
    jmp @r3
    mov #0xF, r4
.L_0601A74E:
    .byte   0xD5, 0x07    /* mov.l _pool_snd_cmd_2p, r5 */
    .byte   0xD3, 0x05    /* mov.l _pool_fn_sound_cmd_dispatch, r3 */
    jmp @r3
    mov #0xF, r4

    .global DAT_0601a756
DAT_0601a756:
    .2byte  0x0418

    .global DAT_0601a758
DAT_0601a758:
    .2byte  0x0624

    .global DAT_0601a75a
DAT_0601a75a:
    .2byte  0x0420
_wpool_final_dlist_size:
    .2byte  0x063C
    .2byte  0xFFFF
_pool_two_player_flag_b:
    .4byte  sym_0605D241
_pool_snd_cmd_1p:
    .4byte  0xAE0006FF
_pool_fn_sound_cmd_dispatch:
    .4byte  sound_cmd_dispatch
_pool_snd_cmd_2p:
    .4byte  0xAE0007FF
