
    .section .text.FUN_060102EC


    .global speedometer_ctrl
    .type speedometer_ctrl, @function
speedometer_ctrl:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   _pool_countdown_ptr, r14
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov.w   _wpool_abort_mask, r3
    and r3, r2
    tst r2, r2
    bt      .L_06010328
    mov #0x6, r3
    mov.l   _pool_game_dispatch_ptr, r2
    mov.l r3, @r2
    bra     .L_06010386
    nop
    .2byte  0x4000
_wpool_abort_mask:
    .2byte  0x0100                          /* bit 8: immediate abort flag */
    .2byte  0xFFFF
    .4byte  sym_0607EADC                    /* &car_index (dword, indexes sound table) */
    .4byte  0x00008000
    .4byte  sym_0607887E                    /* &game_sub_state (byte) */
    .4byte  sym_0607EAD8                    /* &race_end_state (dword, 0/1/2) */
_pool_countdown_ptr:
    .4byte  sym_0607EBCC                    /* &state_countdown (32-bit timer) */
_pool_game_dispatch_ptr:
    .4byte  g_game_state                    /* &game_state_dispatch value */
.L_06010328:
    mov.l @r14, r2
    cmp/pl r2
    bf      .L_06010338
    extu.w r4, r4
    mov.w   DAT_0601038c, r2
    and r2, r4
    tst r4, r4
    bt      .L_06010386
.L_06010338:
    mov.l   _pool_car_index_ptr, r5
    mov.l   _pool_snd_table_base, r3
    mov.l   _pool_snd_dispatch, r2
    mov.l @r5, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    jsr @r2
    mov #0x0, r4
    mov #0x0, r5
    mov #0x2, r3
    mov.l r5, @r14
    mov.l   _pool_game_state_ptr, r2
    exts.b r5, r5
    mov.b r3, @r2
    mov.l   _pool_race_end_ptr, r3
    mov.l   _pool_course_idx_ptr, r2
    mov.l @r3, r3
    exts.b r3, r3
    mov.b r3, @r2
    mov.l   _pool_overlay_flag_ptr, r4
    mov.b r5, @r4
    mov.l   _pool_2p_mode_ptr, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_06010386
    mov.l   _pool_render_state_ptr, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06010386
    mov.l   _pool_button_hw_ptr, r3
    mov.w @r3, r2
    mov.w   DAT_0601038e, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_06010386
    mov #0x1, r3
    mov.b r3, @r4
.L_06010386:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0601038c
DAT_0601038c:
    .2byte  0x0200                          /* view-change button mask (bit 9) */

    .global DAT_0601038e
DAT_0601038e:
    .2byte  0x1000                          /* start button mask (bit 12) */
_pool_car_index_ptr:
    .4byte  sym_0607EADC                    /* &car_index (dword, player/car slot) */
_pool_snd_table_base:
    .4byte  sym_0604481C                    /* sound command table base (4-byte entries) */
_pool_snd_dispatch:
    .4byte  sound_cmd_dispatch              /* &sound_cmd_dispatch function */
_pool_game_state_ptr:
    .4byte  sym_0607887F                    /* &game_state byte (0x02=post-race) */
_pool_race_end_ptr:
    .4byte  sym_0607EAD8                    /* &race_end_state (dword, 0/1/2) */
_pool_course_idx_ptr:
    .4byte  sym_06078648                    /* &course_index byte */
_pool_overlay_flag_ptr:
    .4byte  sym_0605AB18                    /* &overlay_active flag (byte) */
_pool_2p_mode_ptr:
    .4byte  sym_06085FF4                    /* &2p_mode_flag (byte, 0=1P) */
_pool_render_state_ptr:
    .4byte  sym_0605AD00                    /* &render_state (dword, 0=idle) */
_pool_button_hw_ptr:
    .4byte  g_pad_state                    /* &button_state_hw (16-bit word) */
