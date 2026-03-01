
    .section .text.FUN_06009F10


    .global state_demo_setup
    .type state_demo_setup, @function
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
    .2byte  0x4F26                        /* (dead code / alignment) */
    .4byte  0x000B0009
.L_06009FAC:
    .2byte  0x0224                        /* car struct offset: demo param A */
    .2byte  0xFFFF
.L_06009FB0:
    .4byte  sym_0607EBCC               /* attract mode countdown (32-bit) */
.L_06009FB4:
    .4byte  sym_0607E944               /* car state base pointer */
.L_06009FB8:
    .4byte  sym_06078637               /* demo parameter A (byte) */
.L_06009FBC:
    .4byte  sym_06078638               /* demo parameter B (32-bit ptr) */
.L_06009FC0:
    .4byte  sym_0607863C               /* course selection source */
.L_06009FC4:
    .4byte  sym_060786A4               /* replay course store */
.L_06009FC8:
    .4byte  g_game_state               /* game state dispatch value */
.L_06009FCC:
    .4byte  sym_06087804               /* display timer (16-bit) */
.L_06009FD0:
    .4byte  sym_0607EAD8               /* race end state (0/1/2) */
.L_06009FD4:
    .4byte  disp_score_renderer        /* score display renderer */
.L_06009FD8:
    .4byte  geom_display_ctrl_b        /* geometry display control */
.L_06009FDC:
    .4byte  sym_06078900               /* car data array base */
.L_06009FE0:
    .4byte  race_countdown_update      /* race countdown timer update */
.L_06009FE4:
    .4byte  car_proximity_check        /* car proximity/collision check */
.L_06009FE8:
    .4byte  perspective_project        /* 3D perspective projection */
.L_06009FEC:
    .4byte  scene_master               /* scene rendering master */
.L_06009FF0:
    .4byte  frame_end_commit           /* frame end commit */
.L_06009FF4:
    .4byte  sym_0605A00C               /* animation state (32-bit) */
.L_06009FF8:
    .4byte  sym_06026CE0               /* camera state finalization */
