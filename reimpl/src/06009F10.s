	.text
    .global state_demo_setup
state_demo_setup:
    sts.l pr, @-r15
    .byte   0xB1, 0xBF    /* bsr 0x0600A294 (external update sub) */
    nop
    mov.l   .L_06009FB0, r4
    mov.l @r4, r2
    add #-0x1, r2
    mov.l r2, @r4
    mov r2, r3
    cmp/pz r3
    bt      .L_06009F52
    mov.l   .L_06009FB4, r4
    mov.l   .L_06009FB8, r2
    mov.w   .L_06009FAC, r0
    mov.l @r4, r3
    mov.b @r2, r2
    mov.l r2, @(r0, r3)
    add #0x1C, r0
    mov.l @r4, r3
    mov.l   .L_06009FBC, r2
    mov.l @r2, r2
    mov.l r2, @(r0, r3)
    mov.l   .L_06009FC0, r3
    mov.l   .L_06009FC4, r2
    mov.l @r3, r3
    mov.l r3, @r2
    mov #0x18, r3
    mov.l   .L_06009FC8, r2
    mov.l r3, @r2
    mov #0x3, r3
    mov.l   .L_06009FCC, r2
    lds.l @r15+, pr
    rts
    mov.w r3, @r2
.L_06009F52:
    mov.l   .L_06009FD0, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_06009F60
    mov.l   .L_06009FD4, r3
    jsr @r3
    nop
.L_06009F60:
    mov.l   .L_06009FD8, r3
    jsr @r3
    nop
    mov.l   .L_06009FCC, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x3, r0
    bt      .L_06009F9A
    mov.l   .L_06009FDC, r3
    add #0x1, r3
    mov.b @r3, r0
    and #0x7F, r0
    or #0x80, r0
    mov.b r0, @r3
    mov.l   .L_06009FE0, r3
    jsr @r3
    nop
    mov.l   .L_06009FE4, r3
    jsr @r3
    nop
    mov.l   .L_06009FE8, r3
    jsr @r3
    nop
    mov.l   .L_06009FEC, r3
    jsr @r3
    nop
    mov.l   .L_06009FF0, r3
    jmp @r3
    lds.l @r15+, pr
.L_06009F9A:
    mov #0x0, r2
    mov.l   .L_06009FF4, r3
    mov.l r2, @r3
    mov.l   .L_06009FF8, r3
    jmp @r3
    lds.l @r15+, pr
    .short  0x4F26
    .long  0x000B0009
.L_06009FAC:
    .short  0x0224
    .short  0xFFFF
.L_06009FB0:
    .long  sym_0607EBCC
.L_06009FB4:
    .long  sym_0607E944
.L_06009FB8:
    .long  sym_06078637
.L_06009FBC:
    .long  sym_06078638
.L_06009FC0:
    .long  sym_0607863C
.L_06009FC4:
    .long  sym_060786A4
.L_06009FC8:
    .long  g_game_state
.L_06009FCC:
    .long  sym_06087804
.L_06009FD0:
    .long  sym_0607EAD8
.L_06009FD4:
    .long  disp_score_renderer
.L_06009FD8:
    .long  geom_display_ctrl_b
.L_06009FDC:
    .long  sym_06078900
.L_06009FE0:
    .long  race_countdown_update
.L_06009FE4:
    .long  car_proximity_check
.L_06009FE8:
    .long  perspective_project
.L_06009FEC:
    .long  scene_master
.L_06009FF0:
    .long  frame_end_commit
.L_06009FF4:
    .long  sym_0605A00C
.L_06009FF8:
    .long  sym_06026CE0
