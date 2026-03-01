
   .section .text.FUN_06014A74


   .global display_mode_init
   .type display_mode_init, @function
display_mode_init:
    mov.l r14, @-r15
    mov #0x19, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x0, r11
    mov.l r10, @-r15
    mov #0x1, r10
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   .L_06014AE4, r9
    mov.l   .L_06014AE8, r12

    mov.w   .L_06014AE2, r4
    jsr @r12
    mov r11, r5
    mov r10, r5
    jsr @r12
    mov #0x4, r4
    mov r10, r5
    jsr @r12
    mov #0x8, r4
    mov #0x2, r5
    jsr @r12
    mov #0x10, r4
    mov #0x7, r5
    jsr @r12
    mov #0x20, r4
    mov r11, r5
    jsr @r12
    mov r10, r4

    mov.l   .L_06014AEC, r3
    mov.b @r3, r3
    tst r3, r3
    bf      .L_06014B00

    mov.l   .L_06014AF0, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r6
    mov.l   .L_06014AF4, r3
    mov r6, r5
    jsr @r3
    mov #0x8, r4
    mov #0x6, r5
    jsr @r12
    mov #0x10, r4
    mov.l   .L_06014AF8, r3
    jsr @r3
    nop
    mov.l   .L_06014AFC, r3
    jsr @r3
    nop
    bra     .L_06014B0C
    nop
.L_06014AE2:
    .2byte  0x0100
.L_06014AE4:
    .4byte  sym_06085640
.L_06014AE8:
    .4byte  channel_nibble_config
.L_06014AEC:
    .4byte  sym_06085F8A
.L_06014AF0:
    .4byte  sym_0602853E
.L_06014AF4:
    .4byte  display_channel_b
.L_06014AF8:
    .4byte  sym_06028560
.L_06014AFC:
    .4byte  gameover_channel_setup

.L_06014B00:
    mov.l   .L_06014BD8, r3
    jsr @r3
    nop
    mov.l   .L_06014BDC, r3
    jsr @r3
    nop

.L_06014B0C:
    mov.w   .L_06014BCE, r4
    jsr @r12
    mov #0x4, r5
    mov.l   .L_06014BE0, r3
    jsr @r3
    mov #0xC, r4

    mov #0x0, r6
    mov.l   .L_06014BE4, r3
    mov r6, r5
    jsr @r3
    mov #0x10, r4
    mov #0x0, r6
    mov.l   .L_06014BE4, r3
    mov r6, r5
    jsr @r3
    mov #0x20, r4

    mov.l   .L_06014BE8, r13
    mov.l   .L_06014BEC, r5
    mov.l   .L_06014BF0, r4
    jsr @r13
    mov #0x20, r6
    mov.l   .L_06014BF4, r5
    mov.l   .L_06014BF8, r4
    jsr @r13
    mov #0x20, r6
    mov.l   .L_06014BFC, r5
    mov.l   .L_06014C00, r4
    jsr @r13
    mov #0x20, r6
    mov.l   .L_06014C04, r5
    mov.l   .L_06014C08, r4
    jsr @r13
    mov #0x20, r6

    mov #0x20, r6
    mov.l   .L_06014C10, r5
    mov.l   .L_06014C0C, r8
    mov.l   .L_06014C14, r4
    mov.w   .L_06014BD0, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r8, r4
    jsr @r13
    add r3, r4
    mov #0x20, r6
    mov.l   .L_06014C18, r5
    mov.l   .L_06014C14, r4
    mov.w   .L_06014BD2, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r8, r4
    jsr @r13
    add r3, r4
    mov #0x20, r6
    mov.l   .L_06014C1C, r5
    mov.l   .L_06014C14, r4
    mov.w   .L_06014BD4, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r8, r4
    jsr @r13
    add r3, r4
    mov #0x20, r6
    mov.l   .L_06014C20, r5
    mov.l   .L_06014C14, r4
    mov.w   .L_06014BD6, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r8, r4
    jsr @r13
    add r3, r4

    mov.l   .L_06014C24, r13
    mov #0x8, r7
    mov.l   .L_06014C28, r5
    mov.l   .L_06014C2C, r4
    jsr @r13
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_06014C30, r5
    mov.l   .L_06014C34, r4
    jsr @r13
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_06014C38, r5
    mov.l   .L_06014C3C, r4
    jsr @r13
    mov #0x0, r6
    mov #0x8, r7
    mov.l   .L_06014C40, r5
    mov.l   .L_06014C44, r4
    jsr @r13
    mov #0x0, r6
    bra     .L_06014C7C
    extu.b r11, r5
.L_06014BCE:
    .2byte  0x0100
.L_06014BD0:
    .2byte  0x0260
.L_06014BD2:
    .2byte  0x0280
.L_06014BD4:
    .2byte  0x0220
.L_06014BD6:
    .2byte  0x0240
.L_06014BD8:
    .4byte  obj_data_compact
.L_06014BDC:
    .4byte  frame_end_commit
.L_06014BE0:
    .4byte  sym_0602853E
.L_06014BE4:
    .4byte  display_channel_b
.L_06014BE8:
    .4byte  memcpy_word_idx
.L_06014BEC:
    .4byte  sym_06044A64
.L_06014BF0:
    .4byte  0x25F00660
.L_06014BF4:
    .4byte  sym_06044A84
.L_06014BF8:
    .4byte  0x25F00680
.L_06014BFC:
    .4byte  sym_06044AA4
.L_06014C00:
    .4byte  0x25F006A0
.L_06014C04:
    .4byte  sym_06044AC4
.L_06014C08:
    .4byte  0x25F006C0
.L_06014C0C:
    .4byte  0x25C00000
.L_06014C10:
    .4byte  sym_06044AE4
.L_06014C14:
    .4byte  sym_06059FFC
.L_06014C18:
    .4byte  sym_06044B24
.L_06014C1C:
    .4byte  sym_06044B04
.L_06014C20:
    .4byte  sym_06044B44
.L_06014C24:
    .4byte  sym_0600511E
.L_06014C28:
    .4byte  0x00017700
.L_06014C2C:
    .4byte  0x25E73B98
.L_06014C30:
    .4byte  0x000189E0
.L_06014C34:
    .4byte  0x25E74158
.L_06014C38:
    .4byte  0x0001AFA0
.L_06014C3C:
    .4byte  0x25E74AFC
.L_06014C40:
    .4byte  0x0001C980
.L_06014C44:
    .4byte  0x25E75730

.L_06014C48:
    extu.b r5, r4
    mov #0x36, r3
    muls.w r3, r4
    sts macl, r4
    exts.w r4, r4
    add r9, r4
    extu.w r10, r2
    mov.w r2, @r4
    extu.w r14, r0
    mov.w r0, @(2, r4)
    extu.b r11, r4
    extu.b r5, r6
    muls.w r3, r6
    sts macl, r6
    exts.w r6, r6
    add r9, r6

.L_06014C68:
    extu.b r4, r2
    mov #0x20, r0
    shll r2
    add #0x1, r4
    add r6, r2
    extu.b r4, r3
    mov.w r0, @(4, r2)
    cmp/ge r14, r3
    bf      .L_06014C68
    add #0x1, r5

.L_06014C7C:
    extu.b r5, r3
    mov #0x2C, r2
    cmp/ge r2, r3
    bf      .L_06014C48

    mov.l   .L_06014CF8, r3
    jsr @r3
    nop
    mov.l   .L_06014CFC, r3
    jsr @r3
    nop

    exts.w r10, r0
    mov.l   .L_06014D00, r3
    mov.b r11, @r3
    mov.l   .L_06014D04, r3
    mov.w r11, @r3
    mov.l   .L_06014D08, r3
    mov.w r0, @r3
    mov.l   .L_06014D0C, r3
    jsr @r3
    nop

    mov.l   .L_06014D10, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    .word 0x0029
    mov.l   .L_06014D14, r3
    mov.l @r3, r3
    and r3, r0
    and r10, r0
    tst r0, r0
    bt      .L_06014CDE

    mov #0x27, r3
    mov.l   .L_06014D04, r2
    mov.w r3, @r2
    mov.l   .L_06014D18, r4
    mov.l @r4, r3
    mov.l   .L_06014D1C, r2
    mov.b @r2, r2
    mov.w   DAT_06014cf2, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.l   .L_06014D20, r2
    mov.l @r2, r2
    mov.w   .L_06014CF4, r0
    mov.l r2, @(r0, r3)
    mov.l   .L_06014D24, r3
    mov.l @r3, r3
    mov.l   .L_06014D28, r2
    mov.l r3, @r2

.L_06014CDE:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06014cf2
DAT_06014cf2:
    .2byte  0x0224
.L_06014CF4:
    .2byte  0x0240
    .2byte  0xFFFF
.L_06014CF8:
    .4byte  vdp2_loop_ctrl
.L_06014CFC:
    .4byte  geom_pipeline_coord
.L_06014D00:
    .4byte  sym_06085F89
.L_06014D04:
    .4byte  sym_06085F90
.L_06014D08:
    .4byte  sym_06085F94
.L_06014D0C:
    .4byte  sym_060149CC
.L_06014D10:
    .4byte  sym_0607ED8C
.L_06014D14:
    .4byte  sym_0607EBF4
.L_06014D18:
    .4byte  sym_0607E944
.L_06014D1C:
    .4byte  sym_06078637
.L_06014D20:
    .4byte  sym_06078638
.L_06014D24:
    .4byte  sym_0607863C
.L_06014D28:
    .4byte  sym_060786A4
