/* VERIFIED: called exclusively when C is pressed on Car Select screen
 * Method: call-trace differential — 10 frames idle vs 10 frames with C on car select
 *   13 calls during C press, 0 calls during idle baseline [NEW — only during C]
 *   Activates during the Car Select -> Pre-Race state transition.
 * Date: 2026-02-28
 */
/* transition_medium_a -- per-frame medium screen transition handler
 * Translation unit: 0x0600FD8A - 0x0600FDFE
 *
 * Called every frame during a medium screen transition. Manages a 16-bit
 * countdown timer (sym_0607887A) and performs two phases:
 *
 *   Phase 1 (countdown >= 0): Active transition
 *     - Calls graphics_mode_setup() (BSR to FUN_06010BC4)
 *     - Calls dual_hud_render_dispatch() to update HUD
 *     - Checks 2-player mode flag; if single-player, tail-calls
 *       anim_ui_transition(1) to animate the UI transition
 *
 *   Phase 2 (countdown expired, < 0): Transition complete
 *     - Sets game mode byte (sym_0607887F) to 0xC
 *     - Calls display_layer_config(0xC) then display_layer_config(4)
 *       to reconfigure display layers for the new mode
 *     - Stores 0x14 (20) into attract mode timer (sym_0607EBCC)
 *
 * Args: none (reads state from globals)
 * Returns: void
 * Calls: graphics_mode_setup (BSR), dual_hud_render_dispatch,
 *         display_layer_config, anim_ui_transition
 */

    .section .text.FUN_0600FD8A


    .global transition_medium_a
    .type transition_medium_a, @function
transition_medium_a:
    sts.l pr, @-r15                      ! save return address
    .byte   0xD4, 0x13    /* mov.l _pool_countdown_timer_ptr, r4 */
    mov.w @r4, r3                        ! r3 = countdown timer value (16-bit)
    add #-0x1, r3                        ! decrement countdown
    mov.w r3, @r4                        ! store decremented countdown
    exts.w r3, r3                        ! sign-extend to 32-bit for comparison
    cmp/pz r3                            ! is countdown >= 0? (still running)
    bt      .countdown_active            ! if so, continue active transition
    mov #0xC, r3                         ! r3 = 0xC (new game mode value)
    .byte   0xD2, 0x10    /* mov.l _pool_game_mode_ptr, r2 */
    mov r3, r4                           ! r4 = 0xC (arg for display_layer_config)
    mov.b r3, @r2                        ! game_mode_byte = 0xC
    .byte   0xD3, 0x13    /* mov.l _pool_display_layer_config, r3 */
    jsr @r3                              ! display_layer_config(0xC)
    nop                                  ! (delay slot)
    .byte   0xD3, 0x11    /* mov.l _pool_display_layer_config, r3 */
    jsr @r3                              ! display_layer_config(4)
    mov #0x4, r4                         ! r4 = 4 (layer config mode, delay slot)
    mov #0x14, r2                        ! r2 = 0x14 (20 = new attract timer value)
    .byte   0xD3, 0x10    /* mov.l _pool_attract_timer_ptr, r3 */
    mov.l r2, @r3                        ! attract_timer = 20
    bra     .epilogue                    ! done, return
    nop                                  ! (delay slot)
.countdown_active:
    .byte   0xB7, 0x04    /* bsr 0x06010BC4 (external) */
    nop                                  ! graphics_mode_setup() (delay slot)
    .byte   0xD3, 0x09    /* mov.l _pool_hud_render_dispatch, r3 */
    jsr @r3                              ! dual_hud_render_dispatch()
    nop                                  ! (delay slot)
    .byte   0xD0, 0x09    /* mov.l _pool_2p_mode_flag, r0 */
    mov.b @r0, r0                        ! r0 = 2-player mode flag (0=1P, 1=2P)
    tst r0, r0                           ! is single-player mode?
    bf      .epilogue                    ! if 2P mode, skip UI anim and return
    mov #0x1, r4                         ! r4 = 1 (UI transition direction)
    .byte   0xD3, 0x07    /* mov.l _pool_anim_ui_transition, r3 */
    jmp @r3                              ! tail-call anim_ui_transition(1)
    lds.l @r15+, pr                      ! restore return address (delay slot)
    .2byte  0xFFFF                       /* alignment padding */
    .4byte  0xAB1101FF                   /* sound ID: transition sound (unused by this TU) */
    .4byte  sound_cmd_dispatch           /* sound_cmd_dispatch function ptr (unused by this TU) */
_pool_countdown_timer_ptr:
    .4byte  sym_0607887A                 /* &transition countdown timer (16-bit word) */
_pool_game_mode_ptr:
    .4byte  sym_0607887F                 /* &game_mode_byte (8-bit game state) */
_pool_hud_render_dispatch:
    .4byte  sym_06011EB4                 /* dual_hud_render_dispatch function */
_pool_2p_mode_flag:
    .4byte  sym_06085FF4                 /* &2-player mode flag (byte, 0=1P, 1=2P) */
_pool_anim_ui_transition:
    .4byte  anim_ui_transition           /* UI animation transition function */
_pool_display_layer_config:
    .4byte  sym_0602853E                 /* display_layer_config function */
_pool_attract_timer_ptr:
    .4byte  sym_0607EBCC                 /* &attract mode timer (32-bit countdown) */
.epilogue:
    lds.l @r15+, pr                      ! restore return address
    rts                                  ! return
    nop                                  ! (delay slot)
