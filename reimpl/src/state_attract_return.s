
    .section .text.FUN_06009E60


    .global state_attract_return
    .type state_attract_return, @function
state_attract_return:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   _pool_fn_race_state_pair_2, r3
    jsr @r3
    nop
    mov.l   _pool_fn_display_layer_fill, r14
    jsr @r14
    mov #0x4, r4
    jsr @r14
    mov #0x8, r4
    jsr @r14
    mov #0xC, r4
    mov.l   _pool_fn_render_state_commit, r3
    jsr @r3
    nop
    mov.l   _pool_fn_display_channel_b, r14
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x8, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x10, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x20, r4
    mov.l   _pool_fn_gameover_channel_setup, r3
    jsr @r3
    nop
    mov.w   _wpool_countdown_1000, r2
    mov.l   _pool_countdown_ptr, r3
    mov.l r2, @r3
    mov #0x17, r2
    mov.l   _pool_game_state_ptr, r3
    mov.l r2, @r3
    mov #0x0, r2
    mov.l   _pool_display_timer_ptr, r3
    mov.w r2, @r3
    mov.l   _pool_fn_race_init_master, r3
    jsr @r3
    nop
    mov.l   _pool_fn_hud_subsystem_init, r3
    jsr @r3
    nop
    mov #0x4, r2
    mov.l   _pool_display_mode_ptr, r3
    mov.w r2, @r3
    mov #0x0, r6
    mov.l   _pool_course_index_ptr, r5
    mov.b @r5, r5
    add #0xE, r5
    mov.l r5, @r15
    mov r5, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   _pool_fn_handler_dispatch, r3
    jmp @r3
    mov.l @r15+, r14
_wpool_countdown_1000:
    .2byte  0x03E8                          /* 1000 — attract countdown frames */
_pool_fn_race_state_pair_2:
    .4byte  race_state_pair_2               /* race state pair reset */
_pool_fn_display_layer_fill:
    .4byte  sym_0602853E                    /* display layer fill (VRAM block copy) */
_pool_fn_render_state_commit:
    .4byte  sym_06028560                    /* render state commit (clear/flush) */
_pool_fn_display_channel_b:
    .4byte  display_channel_b               /* display channel B enable */
_pool_fn_gameover_channel_setup:
    .4byte  gameover_channel_setup          /* game-over display channel setup */
_pool_countdown_ptr:
    .4byte  sym_0607EBCC                    /* &state_countdown (32-bit, WRAM High) */
_pool_game_state_ptr:
    .4byte  g_game_state                    /* &game_state (32-bit dispatch value) */
_pool_display_timer_ptr:
    .4byte  sym_06087804                    /* &display_timer (16-bit) */
_pool_fn_race_init_master:
    .4byte  race_init_master                /* race subsystem reinit */
_pool_fn_hud_subsystem_init:
    .4byte  hud_subsystem_init              /* HUD subsystem reinit */
_pool_display_mode_ptr:
    .4byte  sym_0605A016                    /* &display_mode (16-bit) */
_pool_course_index_ptr:
    .4byte  sym_06078648                    /* &course_index (byte, 0-2) */
_pool_fn_handler_dispatch:
    .4byte  handler_dispatch                /* course-specific handler dispatch */
