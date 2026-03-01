/* VERIFIED: active during car select screen (called after mode select C press)
 * Method: call-trace differential — 10 frames idle vs 10 frames with C on mode select
 *   12 calls during C (baseline 10, +2) — runs every frame during car select state
 *   Not present in idle mode select frames, appears only after transition
 * Date: 2026-02-28
 */

    .section .text.FUN_06008B9C


    .global state_car_select_active
    .type state_car_select_active, @function
state_car_select_active:
    sts.l pr, @-r15
    mov.l   .L_pool_06008BD0, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008BD4, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008BC4, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06008BC8, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
    .2byte  0xFFFF
    .4byte  g_game_state
    .4byte  car_select_setup
.L_pool_06008BC4:
    .4byte  sym_06026CE0
.L_pool_06008BC8:
    .4byte  sym_06059F44
    .4byte  sym_0605A016
.L_pool_06008BD0:
    .4byte  FUN_06019A48
.L_pool_06008BD4:
    .4byte  FUN_06019928
