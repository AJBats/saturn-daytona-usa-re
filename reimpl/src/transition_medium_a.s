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
    .byte   0xD4, 0x13    /* mov.l .L_pool_0600FDDC, r4 */
    mov.w @r4, r3
    add #-0x1, r3
    mov.w r3, @r4
    exts.w r3, r3
    cmp/pz r3
    bt      .L_0600FDB8
    mov #0xC, r3
    .byte   0xD2, 0x10    /* mov.l .L_pool_0600FDE0, r2 */
    mov r3, r4
    mov.b r3, @r2
    .byte   0xD3, 0x13    /* mov.l .L_pool_0600FDF0, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x11    /* mov.l .L_pool_0600FDF0, r3 */
    jsr @r3
    mov #0x4, r4
    mov #0x14, r2
    .byte   0xD3, 0x10    /* mov.l .L_pool_0600FDF4, r3 */
    mov.l r2, @r3
    bra     .L_0600FDF8
    nop
.L_0600FDB8:
    .byte   0xB7, 0x04    /* bsr 0x06010BC4 (external) */
    nop
    .byte   0xD3, 0x09    /* mov.l .L_pool_0600FDE4, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x09    /* mov.l .L_pool_0600FDE8, r0 */
    mov.b @r0, r0
    tst r0, r0
    bf      .L_0600FDF8
    mov #0x1, r4
    .byte   0xD3, 0x07    /* mov.l .L_pool_0600FDEC, r3 */
    jmp @r3
    lds.l @r15+, pr
    .2byte  0xFFFF                       /* alignment padding */
    .4byte  0xAB1101FF                   /* sound ID: transition sound (unused by this TU) */
    .4byte  sound_cmd_dispatch           /* sound_cmd_dispatch function ptr (unused by this TU) */
.L_pool_0600FDDC:
    .4byte  sym_0607887A                 /* &transition countdown timer (16-bit word) */
.L_pool_0600FDE0:
    .4byte  sym_0607887F                 /* &game_mode_byte (8-bit game state) */
.L_pool_0600FDE4:
    .4byte  sym_06011EB4                 /* dual_hud_render_dispatch function */
.L_pool_0600FDE8:
    .4byte  sym_06085FF4                 /* &2-player mode flag (byte, 0=1P, 1=2P) */
.L_pool_0600FDEC:
    .4byte  anim_ui_transition           /* UI animation transition function */
.L_pool_0600FDF0:
    .4byte  sym_0602853E                 /* display_layer_config function */
.L_pool_0600FDF4:
    .4byte  sym_0607EBCC                 /* &attract mode timer (32-bit countdown) */
.L_0600FDF8:
    lds.l @r15+, pr
    rts
    nop
