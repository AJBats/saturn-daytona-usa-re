/* state_mode_select_setup -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06008CD0 - 0x06008D74
 *
 * Mode select screen initialization (game state 4, one-shot setup).
 * Called from state_mode_select_entry which sets r14 = 0.
 * After attract mode ends or Start is pressed, the game transitions
 * to state 4 to show the mode select menu (Saturn / Arcade / Time Trial).
 *
 * Initialization sequence:
 *   1. Clear course type to 0
 *   2. disable_display() — turn off screen output
 *   3. camera_finalize() — reset camera state
 *   4. Clear animation state to 0
 *   5. render_coord_transform() — recalculate render matrices
 *   6. course_setup_handler() — initialize course data for menu
 *   7. Set attract countdown timer = 0x258 (600 frames = 10 sec at 60fps)
 *   8. Clear DMA pending flag to 0
 *   9. Set game state dispatch = 5 (next state = mode_select_active)
 *  10. Set render_mode_flags |= 0x40000000 (mode select active bit)
 *  11. camera_finalize() — finalize camera for mode select view
 *  12. Clear animation state to 0
 *  13. Set display mode = 3 (mode select screen layout)
 *  14. If demo_flag_b == 1: race_state_pair_1() and clear flag
 *
 * Parameters:
 *   r14 = 0 (set by state_mode_select_entry prologue)
 */

    .section .text.FUN_06008CD0


    .global state_mode_select_setup
    .type state_mode_select_setup, @function
state_mode_select_setup:
    sts.l pr, @-r15                         ! save return address
    mov.l   _pool_course_type_ptr, r3       ! r3 = &course_type
    mov.l r14, @r3                          ! course_type = 0 (r14 = 0 from entry)
    mov.l   _pool_fn_disable_display, r3    ! r3 = &disable_display
    jsr @r3                                 ! disable_display() — clear display bit 15
    nop                                     ! (delay slot)
    mov.l   _pool_fn_camera_finalize, r3    ! r3 = &camera_finalize
    jsr @r3                                 ! camera_finalize() — reset camera state
    nop                                     ! (delay slot)
    mov.l   _pool_anim_state_ptr, r3        ! r3 = &animation_state
    mov.l r14, @r3                          ! animation_state = 0
    mov.l   _pool_fn_render_coord, r3       ! r3 = &render_coord_transform
    jsr @r3                                 ! render_coord_transform() — recalc matrices
    nop                                     ! (delay slot)
    mov.l   _pool_fn_course_setup, r3       ! r3 = &course_setup_handler
    jsr @r3                                 ! course_setup_handler() — load course data
    nop                                     ! (delay slot)
    mov.w   _wpool_timer_600, r2            ! r2 = 0x258 (600 frames = 10 sec timer)
    mov.l   _pool_countdown_ptr, r3         ! r3 = &attract_countdown
    mov.l r2, @r3                           ! attract_countdown = 600
    mov.l   _pool_dma_pending_ptr, r3       ! r3 = &dma_pending_flag
    mov #0x5, r2                            ! r2 = 5 (next game state)
    mov.l r14, @r3                          ! dma_pending_flag = 0
    mov.l   _pool_game_state_ptr, r3        ! r3 = &game_state_dispatch
    mov.l r2, @r3                           ! game_state_dispatch = 5 (mode_select_active)
    mov.l   _pool_render_flags_ptr, r4      ! r4 = &render_mode_flags
    mov.l   _pool_mode_select_bit, r2       ! r2 = 0x40000000 (mode select active bit)
    mov.l @r4, r3                           ! r3 = render_mode_flags
    or r2, r3                               ! r3 |= 0x40000000
    mov.l r3, @r4                           ! render_mode_flags |= mode select bit
    mov.l   _pool_fn_camera_finalize, r3    ! r3 = &camera_finalize
    jsr @r3                                 ! camera_finalize() — finalize for menu view
    nop                                     ! (delay slot)
    mov #0x3, r2                            ! r2 = 3 (mode select display layout)
    mov.l   _pool_anim_state_ptr, r3        ! r3 = &animation_state
    mov.l r14, @r3                          ! animation_state = 0
    mov.l   _pool_display_mode_ptr, r3      ! r3 = &display_mode
    mov.w r2, @r3                           ! display_mode = 3 (mode select screen)
    mov.l   _pool_demo_flag_b_ptr, r0       ! r0 = &demo_flag_b
    mov.b @r0, r0                           ! r0 = demo_flag_b (byte read)
    extu.b r0, r0                           ! zero-extend to 32-bit
    cmp/eq #0x1, r0                         ! demo_flag_b == 1?
    bf      .L_exit                         ! if not 1 → skip race state cleanup
    mov.l   _pool_fn_race_state_pair, r3    ! r3 = &race_state_pair_1
    jsr @r3                                 ! race_state_pair_1() — teardown demo race state
    nop                                     ! (delay slot)
    extu.b r14, r14                         ! r14 = 0 (ensure zero, byte-clean)
    mov.l   _pool_demo_flag_b_ptr, r3       ! r3 = &demo_flag_b
    mov.b r14, @r3                          ! demo_flag_b = 0 (clear demo flag)
.L_exit:
    lds.l @r15+, pr                         ! restore return address
    rts                                     ! return
    mov.l @r15+, r14                        ! (delay slot) restore r14
_wpool_timer_600:
    .2byte  0x0258                          /* 600 frames (10 seconds at 60fps) */
    .2byte  0xFFFF                          /* alignment padding */
_pool_course_type_ptr:
    .4byte  sym_06078644                    /* &course_type (32-bit) */
_pool_fn_disable_display:
    .4byte  sym_060149E0                    /* disable_display — clear bit 15 */
_pool_fn_camera_finalize:
    .4byte  sym_06026CE0                    /* camera_finalize / display update */
_pool_anim_state_ptr:
    .4byte  sym_06059F44                    /* &animation_state (32-bit) */
_pool_fn_render_coord:
    .4byte  render_coord_transform          /* render coordinate transform */
_pool_fn_course_setup:
    .4byte  course_setup_handler            /* course data setup */
_pool_countdown_ptr:
    .4byte  sym_0607EBCC                    /* &attract_countdown (32-bit timer) */
_pool_dma_pending_ptr:
    .4byte  sym_06086024                    /* &dma_pending_flag (32-bit) */
_pool_game_state_ptr:
    .4byte  g_game_state                    /* &game_state_dispatch (32-bit) */
_pool_render_flags_ptr:
    .4byte  sym_0605B6D8                    /* &render_mode_flags (32-bit bitmask) */
_pool_mode_select_bit:
    .4byte  0x40000000                      /* bit 30 — mode select active flag */
_pool_display_mode_ptr:
    .4byte  sym_0605A016                    /* &display_mode (16-bit) */
_pool_demo_flag_b_ptr:
    .4byte  sym_0607864B                    /* &demo_flag_b (byte) */
_pool_fn_race_state_pair:
    .4byte  race_state_pair_1               /* race state teardown */
