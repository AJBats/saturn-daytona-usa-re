
    .section .text.FUN_06033AAC


    .global hud_subsystem_init
    .type hud_subsystem_init, @function
hud_subsystem_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    xor r7, r7
.L_06033ABC:
    mov.l   .L_06033B30, r1
    mulu.w r7, r1
    sts macl, r0
    mov.l   .L_06033B34, r14
    add r0, r14
    mov.l   .L_06033B38, r0
    mov.b r7, @(r0, r14)
    xor r2, r2
    mov.l   .L_06033B3C, r0
    mov.b r2, @(r0, r14)
    mov.l   .L_06033B40, r0
    mov.b r2, @(r0, r14)
    mov.l   .L_06033B44, r0
    mov.b r2, @(r0, r14)
    mov.l   .L_06033B48, r0
    mov.b r2, @(r0, r14)
    mov.l   .L_06033B4C, r1
    mulu.w r7, r1
    sts macl, r0
    mov.l   .L_06033B50, r1
    add r0, r1
    mov.w @r1+, r2
    shll16 r2
    mov.l   .L_06033B54, r0
    mov.l r2, @(r0, r14)
    mov.w @r1+, r2
    shll16 r2
    mov.l   .L_06033B58, r0
    mov.l r2, @(r0, r14)
    mov.w @r1+, r2
    shll16 r2
    mov.l   .L_06033B5C, r0
    mov.l r2, @(r0, r14)
    mov.w @r1+, r2
    shll16 r2
    mov.l   .L_06033B60, r0
    mov.l r2, @(r0, r14)
    mov.w @r1+, r2
    mov.l   .L_06033B64, r0
    mov.w r2, @(r0, r14)
    mov.w @r1+, r2
    mov.l   .L_06033B68, r0
    mov.w r2, @(r0, r14)
    mov.b @r1+, r2
    shll8 r2
    exts.w r2, r2
    mov.l   .L_06033B6C, r0
    mov.w r2, @(r0, r14)
    mov.b @r1+, r2
    mov.l   .L_06033B70, r0
    mov.b r2, @(r0, r14)
    mov #0x1, r0
    add r0, r7
    mov.l   .L_06033B74, r0
    cmp/ge r0, r7
    bt      .L_06033B78
    bra     .L_06033ABC
    nop
.L_06033B30:
    .4byte  0x0000002C                  /* 44 bytes per HUD element */
.L_06033B34:
    .4byte  DAT_06082A7C               /* HUD element array base */
.L_06033B38:
    .4byte  0x00000000                  /* +0x00: element index (byte) */
.L_06033B3C:
    .4byte  0x00000010                  /* +0x10: element state (byte) */
.L_06033B40:
    .4byte  0x00000011                  /* +0x11: visibility (byte) */
.L_06033B44:
    .4byte  0x00000026                  /* +0x26: flag A (byte) */
.L_06033B48:
    .4byte  0x00000028                  /* +0x28: flag B (byte) */
.L_06033B4C:
    .4byte  0x0000000E                  /* 14 bytes per init table entry */
.L_06033B50:
    .4byte  sym_060631BC               /* HUD init data table (14 bytes/entry) */
.L_06033B54:
    .4byte  0x00000014                  /* +0x14: X position (32-bit 16.16) */
.L_06033B58:
    .4byte  0x00000018                  /* +0x18: Y position (32-bit 16.16) */
.L_06033B5C:
    .4byte  0x0000001C                  /* +0x1C: width (32-bit 16.16) */
.L_06033B60:
    .4byte  0x00000020                  /* +0x20: height (32-bit 16.16) */
.L_06033B64:
    .4byte  0x00000002                  /* +0x02: type/sprite index (16-bit) */
.L_06033B68:
    .4byte  0x00000012                  /* +0x12: palette index (16-bit) */
.L_06033B6C:
    .4byte  0x00000024                  /* +0x24: draw priority (16-bit) */
.L_06033B70:
    .4byte  0x00000001                  /* +0x01: element flags (byte) */
.L_06033B74:
    .4byte  0x0000002D                  /* 45 HUD elements total */
.L_06033B78:
    xor r2, r2
    mov.l   .L_06033BB0, r0
    mov.b r2, @r0
    mov.l   .L_06033BB4, r0
    mov.l r2, @r0
    xor r7, r7
    mov.l   .L_06033BB8, r6
    mov.l   .L_06033BBC, r5
    mov.l   .L_06033BC0, r4
    mov #0x2, r3
.L_06033B8C:
    mov.l @r5+, r2
    mov.l r6, @r2
    mov.l   .L_06033BC4, r0
    mov.b r7, @(r0, r6)
    add r4, r6
    add #0x1, r7
    cmp/ge r3, r7
    bf      .L_06033B8C
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop
    .2byte  0x0000
.L_06033BB0:
    .4byte  sym_06083254               /* active HUD element count (byte) */
.L_06033BB4:
    .4byte  sym_06083250               /* HUD subsystem state (32-bit) */
.L_06033BB8:
    .4byte  sym_0607EB94               /* display channel array base */
.L_06033BBC:
    .4byte  sym_060631AC               /* channel pointer table (2 entries) */
.L_06033BC0:
    .4byte  0x00000014                  /* 20 bytes per channel entry */
.L_06033BC4:
    .4byte  0x00000006                  /* +0x06: channel index (byte) */
