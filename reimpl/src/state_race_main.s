
    .section .text.FUN_06009098


    .global state_race_main
    .type state_race_main, @function
state_race_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0600911C, r8
    mov.l   .L_06009120, r9
    mov.l   .L_06009124, r10
    mov.l   .L_06009128, r11
    mov.l   .L_0600912C, r14
    mov.l   .L_06009130, r3
    mov.w @r3, r2
    mov.w   .L_0600911A, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt/s    .L_060090CE
    mov #0x10, r13
    mov #0xF, r3
    mov.l   .L_06009134, r2
    mov.l r3, @r2
    mov #0x12, r3
    mov.l r3, @r10
.L_060090CE:
    mov.l   .L_06009138, r2
    mov.l   .L_06009138, r3
    mov.l @r2, r2
    add #-0x1, r2
    mov.l r2, @r3
    mov.l   .L_0600913C, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060090E6
    mov.l   .L_06009140, r3
    jsr @r3
    mov #0x0, r4
.L_060090E6:
    mov.w @r11, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_060090F4
    mov.l   .L_06009144, r3
    jsr @r3
    nop
.L_060090F4:
    mov #0x0, r12
    mov.l   .L_06009148, r2
    bra     .L_060091A0
    mov.l r2, @r15
.L_060090FC:
    mov.l   .L_0600914C, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06009162
    extu.b r12, r12
    tst r12, r12
    bf      .L_06009150
    mov #0x1, r3
    mov.w r3, @r11
    mov.l @r15, r2
    mov.l r2, @r14
    mov r2, r3
    bra     .L_06009162
    mov.l r2, @r9
.L_0600911A:
    .2byte  0x0800                        /* traffic light change bit mask */
.L_0600911C:
    .4byte  sym_0607ED88               /* race score/points counter */
.L_06009120:
    .4byte  sym_0607E940               /* current car struct pointer variable */
.L_06009124:
    .4byte  g_game_state               /* game phase state (0x10/0x12/0x15) */
.L_06009128:
    .4byte  sym_0607ED8C               /* per-frame race state flag (16-bit) */
.L_0600912C:
    .4byte  sym_0607E944               /* car array base pointer variable */
.L_06009130:
    .4byte  sym_06063D9A               /* traffic light state register */
.L_06009134:
    .4byte  sym_0607EACC               /* race event flag (0xF on light change) */
.L_06009138:
    .4byte  sym_0607EBCC               /* race countdown timer (decremented per frame) */
.L_0600913C:
    .4byte  sym_0605AB18               /* menu overlay active flag (byte) */
.L_06009140:
    .4byte  menu_overlay_render        /* draw menu overlay */
.L_06009144:
    .4byte  sym_060033E6               /* state change notification handler */
.L_06009148:
    .4byte  sym_06078B68               /* default car data pointer */
.L_0600914C:
    .4byte  sym_06078635               /* per-car update trigger flag (byte) */
.L_06009150:
    mov #0x0, r2
    mov.w r2, @r11
    mov.l   .L_06009224, r3
    mov.l r3, @r14
    mov r3, r2
    mov.l r3, @r9
    mov.l @r8, r3
    add #-0x2, r3
    mov.l r3, @r8
.L_06009162:
    mov.l   .L_06009228, r3
    jsr @r3
    nop
    mov.l   .L_0600922C, r3
    jsr @r3
    nop
    mov.l   .L_06009230, r3
    jsr @r3
    nop
    mov.l   .L_06009234, r3
    jsr @r3
    nop
    mov.l   .L_06009238, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06009194
    mov.l   .L_0600923C, r3
    jsr @r3
    nop
    mov.l   .L_06009240, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0600919E
    bra     .L_0600919E
    mov.l r13, @r10
.L_06009194:
    mov.l   .L_06009244, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0600919E
    mov.l r13, @r10
.L_0600919E:
    add #0x1, r12
.L_060091A0:
    extu.b r12, r3
    mov.l   .L_06009248, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r2, r3
    bf      .L_060090FC
    mov.l   .L_0600924C, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060091BE
    mov.l   .L_06009250, r3
    jsr @r3
    nop
    bra     .L_060091C4
    nop
.L_060091BE:
    mov.l   .L_06009254, r3
    jsr @r3
    nop
.L_060091C4:
    mov.l   .L_06009258, r3
    jsr @r3
    nop
    mov.l   .L_0600925C, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_060091EA
    mov.l   .L_06009260, r3
    jsr @r3
    nop
    mov.l   .L_06009264, r6
    mov.l   .L_06009268, r5
    mov.l   .L_0600926C, r4
    mov.l   .L_06009270, r3
    jsr @r3
    mov.l @r6, r6
    bra     .L_060091F0
    nop
.L_060091EA:
    mov.l   .L_06009274, r3
    jsr @r3
    nop
.L_060091F0:
    mov.l   .L_06009278, r3
    jsr @r3
    nop
    mov.l   .L_0600927C, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0600920C
    mov.l   .L_06009280, r7
    mov.l   .L_06009284, r6
    mov.w   .L_06009222, r5
    mov.l   .L_06009288, r3
    jsr @r3
    mov #0x8, r4
.L_0600920C:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_0600928C, r3
    jmp @r3
    mov.l @r15+, r14
.L_06009222:
    .2byte  0x0082                        /* VDP1 cmd offset for debug display */
.L_06009224:
    .4byte  sym_06078900               /* car array start (first car struct) */
.L_06009228:
    .4byte  sym_060302C6               /* per-car frame update (physics/state) */
.L_0600922C:
    .4byte  render_camera_compute      /* camera matrix computation */
.L_06009230:
    .4byte  sym_0602F0E8               /* pre-render state preparation */
.L_06009234:
    .4byte  race_state_update          /* race progress (laps, checkpoints) */
.L_06009238:
    .4byte  sym_0607EAD8               /* race end trigger flag */
.L_0600923C:
    .4byte  sym_0600C302               /* race end sequence handler */
.L_06009240:
    .4byte  sym_0607EBCC               /* countdown timer (dup for reach) */
.L_06009244:
    .4byte  sym_0607EAD0               /* race timeout counter */
.L_06009248:
    .4byte  sym_06078634               /* total car count (byte) */
.L_0600924C:
    .4byte  sym_06083255               /* terrain rendering mode flag (byte) */
.L_06009250:
    .4byte  terrain_data_lookup        /* terrain-based rendering */
.L_06009254:
    .4byte  sprite_transform           /* sprite-based rendering */
.L_06009258:
    .4byte  sym_06012198               /* scene data preparation */
.L_0600925C:
    .4byte  sym_06078654               /* camera mode (1=full, else=simple) */
.L_06009260:
    .4byte  camera_system              /* full camera system update */
.L_06009264:
    .4byte  sym_06063E24               /* camera parameter table A (ptr) */
.L_06009268:
    .4byte  sym_06063EEC               /* camera parameter B */
.L_0600926C:
    .4byte  sym_06063EF8               /* camera parameter C */
.L_06009270:
    .4byte  camera_orient_calc         /* camera orientation computation */
.L_06009274:
    .4byte  perspective_project        /* simple perspective projection */
.L_06009278:
    .4byte  scene_master               /* master scene renderer */
.L_0600927C:
    .4byte  sym_06086030               /* debug HUD display flag (byte) */
.L_06009280:
    .4byte  sym_0605A1C8               /* debug display data struct */
.L_06009284:
    .4byte  0x0000F000                  /* nibble 3 mask */
.L_06009288:
    .4byte  sym_060283E0               /* debug HUD draw function */
.L_0600928C:
    .4byte  frame_end_commit           /* frame end / VDP commit */
