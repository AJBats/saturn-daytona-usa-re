
    .section .text.FUN_060197F4


    .global car_select_state
    .type car_select_state, @function
car_select_state:
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   _pool_button_status, r3
    mov.w @r3, r2
    mov.w   _wpool_confirm_mask, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_no_confirm
    mov #0x0, r5
    mov.l   _pool_anim_state, r3
    mov.l r5, @r3
    mov.l   _pool_display_active, r3
    mov.b r5, @r3
    mov.l   _pool_game_state_val, r3
    mov.l r4, @r3
    mov.l   _pool_car_slot_idx, r7
    mov.b @r7, r7
    shll r7
    mov.l r7, @(8, r15)
    mov.l   _pool_car_slot_lut, r3
    add r3, r7
    mov.w @r7, r7
    extu.w r7, r7
    shll2 r7
    shll r7
    mov.l   _pool_car_obj_table, r2
    add r2, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   _wpool_texture_offset, r3
    add r3, r7
    mov.l @(8, r15), r6
    mov.l   _pool_car_slot_params, r3
    add r3, r6
    mov.l r6, @(4, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    extu.b r6, r6
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @(4, r15), r2
    mov.l @r15, r5
    mov.l   _pool_dlist_loader, r3
    mov.b @r2, r2
    mov.l @r5, r5
    extu.b r2, r2
    add r2, r6
    shll r6
    jsr @r3
    mov #0xC, r4
    add #0xC, r15
    mov.l   _pool_camera_finalize, r3
    jmp @r3
    lds.l @r15+, pr

    .global DAT_06019864
DAT_06019864:
    mov.l r0, @(0, r0)
_wpool_confirm_mask:
    .2byte  0x0600
_wpool_texture_offset:
    .2byte  0x4000
    .2byte  0xFFFF
    .4byte  sym_0605D243
    .4byte  sym_0605D250
_pool_button_status:
    .4byte  sym_06063D9A
_pool_anim_state:
    .4byte  sym_06059F44
_pool_display_active:
    .4byte  sym_0605D242
_pool_game_state_val:
    .4byte  g_game_state
_pool_car_slot_idx:
    .4byte  sym_0605D244
_pool_car_slot_lut:
    .4byte  sym_06049AF4
_pool_car_obj_table:
    .4byte  sym_06063750
_pool_car_slot_params:
    .4byte  sym_06049AEC
_pool_dlist_loader:
    .4byte  sym_06028400
_pool_camera_finalize:
    .4byte  sym_06026CE0
.L_no_confirm:
    add #0xC, r15
    lds.l @r15+, pr
    rts
    nop

    .global loc_060198A4
loc_060198A4:
    mov #0x0, r4
    mov.l   _pool_camera_dir_flip, r2
    mov.b r4, @r2
    mov.l   _pool_select_timer, r2
    mov.l r4, @r2
    exts.b r4, r4
    mov.l   _pool_2p_mode_flag, r2
    mov.b r4, @r2
    bra     car_select_state
    mov #0xC, r4

    .global loc_060198B8
loc_060198B8:
    mov #0x0, r4
    mov.l   _pool_camera_dir_flip, r2
    mov.b r4, @r2
    mov.l   _pool_select_timer, r2
    mov.l r4, @r2
    mov #0x1, r1
    mov.l   _pool_2p_mode_flag, r2
    mov.b r1, @r2
    bra     car_select_state
    mov #0xC, r4

    .global loc_060198CC
loc_060198CC:
    bra     car_select_state
    mov #0x8, r4

    .global loc_060198D0
loc_060198D0:
    bra     car_select_state
    mov #0xA, r4
_pool_camera_dir_flip:
    .4byte  sym_06078663
_pool_select_timer:
    .4byte  sym_0605AA98
_pool_2p_mode_flag:
    .4byte  sym_06085FF4
