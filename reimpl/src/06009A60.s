
    .section .text.FUN_06009A60


    .global state_race_complete
    .type state_race_complete, @function
state_race_complete:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    mov #0x1, r11
    mov.l r10, @-r15
    mov #0x4, r10
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_06009B14, r9
    mov.l   .L_06009B18, r12
    mov.l   .L_06009B1C, r14
    mov.l   .L_06009B20, r3
    jsr @r3
    mov.l @r12, r8
    mov.l   .L_06009B24, r3
    jsr @r3
    nop
    .byte   0xB2, 0xB7    /* bsr 0x06009FFC (external) */
    nop
    mov r13, r6
    mov.l   .L_06009B28, r5
    mov.b @r5, r5
    add #0xA, r5
    mov.l r5, @r15
    mov.l   .L_06009B2C, r3
    jsr @r3
    mov r5, r4
    mov.l @r12, r2
    mov.w   .L_06009B10, r0
    mov.l @(r0, r2), r3
    add #0x1C, r0
    mov.b r3, @r9
    mov.l @r12, r3
    mov.l   .L_06009B30, r1
    mov.l @(r0, r3), r2
    mov.l r2, @r1
    mov.l   .L_06009B34, r3
    mov.l   .L_06009B38, r2
    mov.l @r3, r3
    mov.l r3, @r2
    mov.l   .L_06009B3C, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_06009AE0
    mov #0x1, r2
    mov.l   .L_06009B40, r3
    mov.l @r3, r3
    cmp/gt r2, r3
    bf      .L_06009AE0
    mov.b @r9, r2
    tst r2, r2
    bf      .L_06009AE0
    mov.l   .L_06009B44, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06009AE0
    mov.b @r14, r0
    or #0x8, r0
    exts.b r0, r0
    mov.b r0, @r14
.L_06009AE0:
    mov.l   .L_06009B48, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_06009BAA
    mov #0x1, r2
    mov.l   .L_06009B4C, r3
    mov.l @r3, r3
    cmp/gt r2, r3
    bf      .L_06009BAA
    mov.l   .L_06009B44, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06009BAA
    mov.b @r9, r3
    mov #0x3, r2
    cmp/ge r2, r3
    bt      .L_06009B78
    mov.l   .L_06009B50, r4
    mov.l   .L_06009B54, r0
    bra     .L_06009B6C
    mov.l @r0, r0
.L_06009B0A:
    mov.b @r4, r2
    bra     .L_06009B66
    or r11, r2
.L_06009B10:
    .2byte  0x0224
    .2byte  0xFFFF
.L_06009B14:
    .4byte  sym_06078637
.L_06009B18:
    .4byte  sym_0607E944
.L_06009B1C:
    .4byte  sym_0605AB17
.L_06009B20:
    .4byte  vdp1_cmd_update                  /* VDP1 command table update fn */
.L_06009B24:
    .4byte  obj_render_update
.L_06009B28:
    .4byte  sym_06078648
.L_06009B2C:
    .4byte  handler_dispatch
.L_06009B30:
    .4byte  sym_06078638
.L_06009B34:
    .4byte  sym_060786A4
.L_06009B38:
    .4byte  sym_0607863C
.L_06009B3C:
    .4byte  sym_06083255
.L_06009B40:
    .4byte  sym_0605AD00
.L_06009B44:
    .4byte  sym_0607EAE0
.L_06009B48:
    .4byte  sym_06085FF4
.L_06009B4C:
    .4byte  sym_0605AD04
.L_06009B50:
    .4byte  sym_0605AB16
.L_06009B54:
    .4byte  sym_0607EAD8
.L_06009B58:
    mov.b @r4, r0
    or #0x2, r0
    exts.b r0, r0
    bra     .L_06009B78
    mov.b r0, @r4
.L_06009B62:
    mov.b @r4, r2
    or r10, r2
.L_06009B66:
    exts.b r2, r2
    bra     .L_06009B78
    mov.b r2, @r4
.L_06009B6C:
    cmp/eq #0x0, r0
    bt      .L_06009B0A
    cmp/eq #0x1, r0
    bt      .L_06009B58
    cmp/eq #0x2, r0
    bt      .L_06009B62
.L_06009B78:
    mov.b @r9, r2
    tst r2, r2
    bf      .L_06009BAA
    mov.l   .L_06009C28, r0
    bra     .L_06009B9E
    mov.l @r0, r0
.L_06009B84:
    mov.b @r14, r2
    bra     .L_06009B98
    or r11, r2
.L_06009B8A:
    mov.b @r14, r0
    or #0x2, r0
    exts.b r0, r0
    bra     .L_06009BAA
    mov.b r0, @r14
.L_06009B94:
    mov.b @r14, r2
    or r10, r2
.L_06009B98:
    exts.b r2, r2
    bra     .L_06009BAA
    mov.b r2, @r14
.L_06009B9E:
    cmp/eq #0x0, r0
    bt      .L_06009B84
    cmp/eq #0x1, r0
    bt      .L_06009B8A
    cmp/eq #0x2, r0
    bt      .L_06009B94
.L_06009BAA:
    .byte   0xB3, 0x05    /* bsr 0x0600A1B8 (external) */
    nop
    mov r8, r0
    mov.l   .L_06009C2C, r4
    mov.b @(3, r0), r0
    tst #0x8, r0
    bf      .L_06009BF6
    mov.l   .L_06009C28, r0
    bra     .L_06009BE6
    mov.l @r0, r0
.L_06009BBE:
    mov.l @(24, r8), r2
    mov.l   .L_06009C30, r3
    cmp/ge r3, r2
    bf      .L_06009BCA
    bra     .L_06009BD8
    nop
.L_06009BCA:
    exts.b r13, r2
    bra     .L_06009BFA
    mov.b r2, @r4
.L_06009BD0:
    mov.l @(16, r8), r2
    mov.l   .L_06009C34, r3
    cmp/gt r3, r2
    bt      .L_06009BDC
.L_06009BD8:
    bra     .L_06009BFA
    mov.b r11, @r4
.L_06009BDC:
    exts.b r13, r2
    bra     .L_06009BFA
    mov.b r2, @r4
.L_06009BE2:
    bra     .L_06009BF8
    exts.b r13, r2
.L_06009BE6:
    cmp/eq #0x0, r0
    bt      .L_06009BBE
    cmp/eq #0x1, r0
    bt      .L_06009BD0
    cmp/eq #0x2, r0
    bt      .L_06009BE2
    bra     .L_06009BFA
    nop
.L_06009BF6:
    mov #0x2, r2
.L_06009BF8:
    mov.b r2, @r4
.L_06009BFA:
    mov #0x40, r0
    mov.l @r12, r3
    mov.l r13, @(r0, r3)
    mov #0x15, r3
    mov.l   .L_06009C38, r2
    mov.l r3, @r2
    mov #0x56, r3
    mov.l   .L_06009C3C, r2
    mov.l r3, @r2
    mov.l   .L_06009C40, r2
    mov.b r10, @r2
    mov.l   .L_06009C44, r2
    mov.w r10, @r2
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06009C28:
    .4byte  sym_0607EAD8
.L_06009C2C:
    .4byte  sym_06083261
.L_06009C30:
    .4byte  0xFFB80000
.L_06009C34:
    .4byte  0xFEC60000
.L_06009C38:
    .4byte  g_game_state
.L_06009C3C:
    .4byte  sym_0607EBCC
.L_06009C40:
    .4byte  sym_06078654
.L_06009C44:
    .4byte  sym_0605A016
