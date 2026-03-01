
    .section .text.FUN_06008A18


    .global state_attract_active
    .type state_attract_active, @function
state_attract_active:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_06008AC4, r14
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov.l   .L_06008AC8, r3
    jsr @r3
    nop
    mov.l   .L_06008ACC, r4
    mov.l @r14, r2
    cmp/pz r2
    bf      .L_06008A40
    mov.l   .L_06008AD0, r2
    mov.w @r2, r3
    mov.w   .L_06008AC0, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_06008A72
.L_06008A40:
    mov.l @r14, r3
    cmp/pz r3
    bf      .L_06008A50
    mov.l   .L_06008AD4, r3
    jsr @r3
    nop
    bra     .L_06008A60
    nop
.L_06008A50:
    mov.l @r4, r2
    mov #0x3, r3
    add #0x1, r2
    mov.l r2, @r4
    cmp/hs r3, r2
    bf      .L_06008A60
    mov #0x0, r3
    mov.l r3, @r4
.L_06008A60:
    mov #0x4, r2
    mov.l   .L_06008AD8, r3
    mov.l r2, @r3
    mov #0x3, r2
    mov.l   .L_06008ADC, r3
    mov.w r2, @r3
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06008A72:
    mov.l @r4, r0
    cmp/eq #0x2, r0
    bf      .L_06008A7E
    mov.l   .L_06008AE0, r3
    jsr @r3
    nop
.L_06008A7E:
    mov.l   .L_06008AE4, r3
    jsr @r3
    nop
    mov.l   .L_06008AE8, r3
    jsr @r3
    nop
    mov.l   .L_06008AEC, r3
    jsr @r3
    nop
    mov.l   .L_06008AF0, r3
    jsr @r3
    nop
    mov #0x15, r5
    mov.l   .L_06008AF4, r3
    jsr @r3
    mov.l @r14, r4
    mov.l   .L_06008AF8, r3
    jsr @r3
    nop
    mov.l @r14, r2
    mov.w   .L_06008AC2, r3
    cmp/gt r3, r2
    bt      .L_06008AB2
    mov.l   .L_06008AFC, r3
    jsr @r3
    nop
.L_06008AB2:
    lds.l @r15+, pr
    mov.l   .L_06008B00, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0x4F26                              /* dead code: unreachable lds.l @r15+, pr */
    .4byte  0x000B6EF6                          /* dead code: unreachable rts + mov.l @r15+, r14 */
.L_06008AC0:
    .2byte  0x0800                              /* Start button bitmask */
.L_06008AC2:
    .2byte  0x0244                              /* 580 frames (~9.7s remaining = first ~5.7s of attract) */
.L_06008AC4:
    .4byte  sym_0607EBCC                        /* attract mode countdown timer (32-bit, init 920) */
.L_06008AC8:
    .4byte  sym_0600A1F6                        /* per_frame_game_tick — general per-frame update */
.L_06008ACC:
    .4byte  sym_0607EAD8                        /* attract cycle counter (0-2, wraps mod 3) */
.L_06008AD0:
    .4byte  sym_06063D9A                        /* button state register (16-bit) */
.L_06008AD4:
    .4byte  handler_init_reset                  /* handler_init_reset — prepare for mode select */
.L_06008AD8:
    .4byte  g_game_state                        /* game state variable (32-bit) */
.L_06008ADC:
    .4byte  sym_06087804                        /* handler mode (16-bit) */
.L_06008AE0:
    .4byte  camera_attract_init                 /* camera_attract_init — special camera for 3rd cycle */
.L_06008AE4:
    .4byte  geom_display_ctrl_b                 /* geom_display_ctrl_b — geometry display update */
.L_06008AE8:
    .4byte  race_countdown_update               /* race_countdown_update — countdown state update */
.L_06008AEC:
    .4byte  car_proximity_check                 /* car_proximity_check — car-to-car proximity */
.L_06008AF0:
    .4byte  perspective_project                 /* perspective_project — 3D projection / rendering */
.L_06008AF4:
    .4byte  sym_0600338C                        /* dlist_slot_select — display list slot dispatch */
.L_06008AF8:
    .4byte  scene_master                        /* scene_master — master scene rendering orchestrator */
.L_06008AFC:
    .4byte  sym_0601AEB6                        /* attract_phase_dispatch — early attract phase logic */
.L_06008B00:
    .4byte  frame_end_commit                    /* frame_end_commit — finalize and commit frame */
