
    .section .text.FUN_0601D3C0


    .global render_setup_dispatch
    .type render_setup_dispatch, @function
render_setup_dispatch:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   _pool_game_mode_ptr, r14
    mov.l   _pool_dma_pending_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601D430
    mov.l   _pool_button_state_ptr, r3
    mov.w @r3, r2
    mov.w   DAT_0601d444, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601D430
    mov.l   _pool_input_struct_ptr, r3
    mov.w @r3, r2
    mov.l   _pool_combo_value_a, r3
    extu.w r2, r2
    cmp/eq r3, r2
    bf      .L_0601D3EE
    mov.b @r14, r0
    or #0x7, r0
    mov.b r0, @r14
.L_0601D3EE:
    mov.l   _pool_input_struct_ptr, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   DAT_0601d446, r3
    cmp/eq r3, r2
    bf      .L_0601D408
    mov.b @r14, r0
    or #0x7, r0
    mov.b r0, @r14
    mov.l   _pool_overlay_flags_ptr, r4
    mov.b @r4, r0
    or #0x7, r0
    mov.b r0, @r4
.L_0601D408:
    mov #0x0, r6
    mov.l   _pool_fn_display_channel_b, r3
    mov r6, r5
    jsr @r3
    mov #0x20, r4
    mov #0x0, r7
    mov.l   _pool_tilemap_source, r5
    mov.l   _pool_fn_dlist_loader, r3
    mov r7, r6
    jsr @r3
    mov #0xC, r4
    mov #0xC, r2
    mov.l   _pool_countdown_timer, r3
    mov.l r2, @r3
    mov #0x4, r2
    mov.l   _pool_game_state_ptr, r3
    mov.b r2, @r3
    mov #0x1, r2
    mov.l   _pool_dma_pending_flag, r3
    mov.l r2, @r3
.L_0601D430:
    mov.l   _pool_game_state_ptr, r2
    mov.b @r2, r2
    extu.b r2, r2
    shll2 r2
    mov.l   _pool_state_jump_table, r3
    add r3, r2
    mov.l @r2, r2
    lds.l @r15+, pr
    jmp @r2
    mov.l @r15+, r14

    .global DAT_0601d444
DAT_0601d444:
    .2byte  0x0800

    .global DAT_0601d446
DAT_0601d446:
    .2byte  0x5D50
_pool_game_mode_ptr:
    .4byte  sym_0605AB16
_pool_dma_pending_flag:
    .4byte  sym_06086024
_pool_button_state_ptr:
    .4byte  sym_06063D9A
_pool_input_struct_ptr:
    .4byte  g_pad_state
_pool_combo_value_a:
    .4byte  0x0000AAA8
_pool_overlay_flags_ptr:
    .4byte  sym_0605AB17
_pool_fn_display_channel_b:
    .4byte  display_channel_b
_pool_tilemap_source:
    .4byte  sym_06094FA8
_pool_fn_dlist_loader:
    .4byte  sym_06028400
_pool_countdown_timer:
    .4byte  sym_0607EBCC
_pool_game_state_ptr:
    .4byte  sym_0607887F
_pool_state_jump_table:
    .4byte  sym_0605DF80
