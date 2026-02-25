/* state_attract_return -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06009E60 - 0x06009F10
 *
 * Attract-mode teardown state (state table index 0x16). Called when
 * returning from the attract-mode demo playback to the main menu flow.
 *
 * Sequence:
 *   1. race_state_pair_2()     — reset race state pair
 *   2. display_layer_fill(4/8/12) — fill display layers 4, 8, 12
 *   3. render_state_commit()   — commit render state
 *   4. display_channel_b(8/16/32, 0, 0) — enable display channels
 *   5. gameover_channel_setup() — configure game-over display channel
 *   6. countdown = 1000        — set state countdown timer
 *   7. game_state = 0x17       — set next game state (demo setup)
 *   8. display_timer = 0       — clear display timer
 *   9. race_init_master()      — reinitialize race subsystem
 *  10. hud_subsystem_init()    — reinitialize HUD
 *  11. display_mode = 4        — set display mode
 *  12. Tail-call handler_dispatch(course+14, 0) — dispatch course handler
 */

    .section .text.FUN_06009E60


    .global state_attract_return
    .type state_attract_return, @function
state_attract_return:
    mov.l r14, @-r15                        ! save r14
    sts.l pr, @-r15                         ! save return address
    add #-0x4, r15                          ! allocate 4 bytes on stack
    mov.l   _pool_fn_race_state_pair_2, r3  ! r3 = &race_state_pair_2
    jsr @r3                                 ! race_state_pair_2() — reset race state pair
    nop                                     ! (delay slot)
    mov.l   _pool_fn_display_layer_fill, r14 ! r14 = &display_layer_fill (kept for reuse)
    jsr @r14                                ! display_layer_fill(4) — fill layer 4
    mov #0x4, r4                            ! arg: layer_id = 4 (delay slot)
    jsr @r14                                ! display_layer_fill(8) — fill layer 8
    mov #0x8, r4                            ! arg: layer_id = 8 (delay slot)
    jsr @r14                                ! display_layer_fill(12) — fill layer 12
    mov #0xC, r4                            ! arg: layer_id = 12 (delay slot)
    mov.l   _pool_fn_render_state_commit, r3 ! r3 = &render_state_commit
    jsr @r3                                 ! render_state_commit() — flush render state
    nop                                     ! (delay slot)
    mov.l   _pool_fn_display_channel_b, r14 ! r14 = &display_channel_b (kept for reuse)
    mov #0x0, r6                            ! arg: param2 = 0
    mov r6, r5                              ! arg: param1 = 0
    jsr @r14                                ! display_channel_b(8, 0, 0) — enable channel 8
    mov #0x8, r4                            ! arg: channel_id = 8 (delay slot)
    mov #0x0, r6                            ! arg: param2 = 0
    mov r6, r5                              ! arg: param1 = 0
    jsr @r14                                ! display_channel_b(16, 0, 0) — enable channel 16
    mov #0x10, r4                           ! arg: channel_id = 16 (delay slot)
    mov #0x0, r6                            ! arg: param2 = 0
    mov r6, r5                              ! arg: param1 = 0
    jsr @r14                                ! display_channel_b(32, 0, 0) — enable channel 32
    mov #0x20, r4                           ! arg: channel_id = 32 (delay slot)
    mov.l   _pool_fn_gameover_channel_setup, r3 ! r3 = &gameover_channel_setup
    jsr @r3                                 ! gameover_channel_setup() — configure game-over channel
    nop                                     ! (delay slot)
    mov.w   _wpool_countdown_1000, r2       ! r2 = 0x03E8 (1000 frames)
    mov.l   _pool_countdown_ptr, r3         ! r3 = &state_countdown
    mov.l r2, @r3                           ! state_countdown = 1000
    mov #0x17, r2                           ! r2 = 0x17 (state: demo setup)
    mov.l   _pool_game_state_ptr, r3        ! r3 = &game_state
    mov.l r2, @r3                           ! game_state = 0x17 (next state = demo setup)
    mov #0x0, r2                            ! r2 = 0
    mov.l   _pool_display_timer_ptr, r3     ! r3 = &display_timer (16-bit)
    mov.w r2, @r3                           ! display_timer = 0 (clear timer)
    mov.l   _pool_fn_race_init_master, r3   ! r3 = &race_init_master
    jsr @r3                                 ! race_init_master() — reinitialize race subsystem
    nop                                     ! (delay slot)
    mov.l   _pool_fn_hud_subsystem_init, r3 ! r3 = &hud_subsystem_init
    jsr @r3                                 ! hud_subsystem_init() — reinitialize HUD
    nop                                     ! (delay slot)
    mov #0x4, r2                            ! r2 = 4
    mov.l   _pool_display_mode_ptr, r3      ! r3 = &display_mode (16-bit)
    mov.w r2, @r3                           ! display_mode = 4
    mov #0x0, r6                            ! r6 = 0 (arg: param2 = 0)
    mov.l   _pool_course_index_ptr, r5      ! r5 = &course_index (byte)
    mov.b @r5, r5                           ! r5 = course_index (0-2)
    add #0xE, r5                            ! r5 = course_index + 14 (handler table offset)
    mov.l r5, @r15                          ! store handler index on stack (unused scratch)
    mov r5, r4                              ! r4 = course_index + 14 (arg: handler_id)
    add #0x4, r15                           ! deallocate 4 bytes from stack
    lds.l @r15+, pr                         ! restore return address (discarded by jmp)
    mov.l   _pool_fn_handler_dispatch, r3   ! r3 = &handler_dispatch
    jmp @r3                                 ! tail-call handler_dispatch(course+14, 0)
    mov.l @r15+, r14                        ! restore r14 (delay slot)
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
    .4byte  sym_0605AD10                    /* &game_state (32-bit dispatch value) */
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
