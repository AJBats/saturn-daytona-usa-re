/* VERIFIED: called exclusively when C is pressed on Car Select screen
 * Method: call-trace differential — 10 frames idle vs 10 frames with C on car select
 *   13 calls during C press, 0 calls during idle baseline [NEW — only during C]
 *   Activates during the Car Select -> Pre-Race state transition.
 * Date: 2026-02-28
 */

    .section .text.FUN_0600FD8A


    .global transition_medium_a
    .type transition_medium_a, @function
transition_medium_a:
    sts.l pr, @-r15
    .byte   0xD4, 0x13    /* mov.l _pool_countdown_timer_ptr, r4 */
    mov.w @r4, r3
    add #-0x1, r3
    mov.w r3, @r4
    exts.w r3, r3
    cmp/pz r3
    bt      .countdown_active
    mov #0xC, r3
    .byte   0xD2, 0x10    /* mov.l _pool_game_mode_ptr, r2 */
    mov r3, r4
    mov.b r3, @r2
    .byte   0xD3, 0x13    /* mov.l _pool_display_layer_config, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x11    /* mov.l _pool_display_layer_config, r3 */
    jsr @r3
    mov #0x4, r4
    mov #0x14, r2
    .byte   0xD3, 0x10    /* mov.l _pool_attract_timer_ptr, r3 */
    mov.l r2, @r3
    bra     .epilogue
    nop
.countdown_active:
    .byte   0xB7, 0x04    /* bsr 0x06010BC4 (external) */
    nop
    .byte   0xD3, 0x09    /* mov.l _pool_hud_render_dispatch, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x09    /* mov.l _pool_2p_mode_flag, r0 */
    mov.b @r0, r0
    tst r0, r0
    bf      .epilogue
    mov #0x1, r4
    .byte   0xD3, 0x07    /* mov.l _pool_anim_ui_transition, r3 */
    jmp @r3
    lds.l @r15+, pr
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
    lds.l @r15+, pr
    rts
    nop
