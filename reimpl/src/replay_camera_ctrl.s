
    .section .text.FUN_0601DBB8


    .global replay_camera_ctrl
    .type replay_camera_ctrl, @function
replay_camera_ctrl:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l   .L_0601DC10, r8
    mov.l   .L_0601DC14, r9
    mov.l   .L_0601DC18, r10
    mov.l   .L_0601DC1C, r11
    mov.l   .L_0601DC20, r12
    mov.l   .L_0601DC24, r13
    mov.l   .L_0601DC28, r14
    mov.l   .L_0601DC2C, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0601DBF8
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     camera_cleanup_reset
    mov.l @r15+, r14
.L_0601DBF8:
    mov.b @r13, r0
    extu.b r0, r0
    tst r0, r0
    .word 0x0029
    mov.l   .L_0601DC30, r3
    mov.l @r3, r3
    and r3, r0
    tst #0x1, r0
    bt      .L_0601DC34
    bra     .L_0601DC5A
    nop
    .2byte  0xFFFF
.L_0601DC10:
    .4byte  sym_06078900
.L_0601DC14:
    .4byte  0x00009000
.L_0601DC18:
    .4byte  sym_0608706C
.L_0601DC1C:
    .4byte  sym_06028400
.L_0601DC20:
    .4byte  sym_06087074
.L_0601DC24:
    .4byte  sym_06087068
.L_0601DC28:
    .4byte  sym_06087070
.L_0601DC2C:
    .4byte  sym_060786AC
.L_0601DC30:
    .4byte  sym_0607EBF4
.L_0601DC34:
    mov.b @r13, r0
    extu.b r0, r0
    tst r0, r0
    .word 0x0029
    mov.l   .L_0601DD3C, r3
    mov.l @r3, r3
    and r3, r0
    mov r0, r3
    mov r8, r0
    mov.b @(3, r0), r0
    tst #0x8, r0
    .word 0x0229
    add #-0x1, r2
    neg r2, r2
    tst r2, r2
    .word 0x0029
    and r3, r0
    tst #0x1, r0
    bt      .L_0601DCC0
.L_0601DC5A:
    mov #0x1, r3
    mov.b r3, @r13
    mov.w   DAT_0601dd30, r2
    mov.l   .L_0601DD40, r3
    mov.w r2, @r3
    mov #0x0, r2
    mov.l   .L_0601DD44, r3
    mov.b r2, @r3
    mov #0x3, r3
    mov.l   .L_0601DD48, r2
    mov.l @r2, r2
    mov.l r2, @r14
    mov.l   .L_0601DD4C, r4
    mov.l r3, @r12
    mov.l   .L_0601DD50, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_0601DC84
    mov.l   .L_0601DD54, r4
    mov #0x6, r3
    mov.l r3, @r12
.L_0601DC84:
    mov.w   .L_0601DD32, r0
    mov.l   .L_0601DD58, r3
    mov.l @(r0, r8), r1
    add #-0x1, r1
    jsr @r3
    mov.l @r12, r0
    shll2 r0
    mov #0x9, r3
    mov.l @(r0, r4), r2
    mov.l r2, @r10
    mov.l   .L_0601DD5C, r2
    mov.b r3, @r2
    mov.l @r14, r3
    mov.l @r10, r2
    cmp/hs r2, r3
    bt      .L_0601DCC0
    mov #0xA, r2
    mov.l   .L_0601DD5C, r3
    mov.b r2, @r3
    mov.l @r14, r2
    mov.l r2, @r10
    mov.w   .L_0601DD32, r0
    mov.l   .L_0601DD58, r3
    mov.l @(r0, r8), r1
    add #-0x1, r1
    jsr @r3
    mov.l @r12, r0
    shll2 r0
    mov.l @r14, r2
    mov.l r2, @(r0, r4)
.L_0601DCC0:
    mov.b @r13, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_0601DCCC
    bra     .L_0601DDE0
    nop
.L_0601DCCC:
    mov.l   .L_0601DD44, r3
    mov.l   .L_0601DD44, r2
    mov.b @r3, r3
    add #0x30, r3
    mov.b r3, @r2
    extu.b r3, r3
    mov.w   DAT_0601dd34, r1
    cmp/ge r1, r3
    bt      .L_0601DDB2
    mov.l   .L_0601DD60, r2
    mov.l r2, @(4, r15)
    mov r2, r7
    mov.w   .L_0601DD36, r6
    mov.w   .L_0601DD32, r0
    mov.l   .L_0601DD58, r3
    mov.l @(4, r7), r7
    mov.l @(r0, r8), r1
    add r9, r7
    add #-0x1, r1
    jsr @r3
    mov.l @r12, r0
    mov #0xE, r5
    mov.l   .L_0601DD64, r3
    mul.l r5, r0
    sts macl, r5
    add r3, r5
    jsr @r11
    mov #0x8, r4
    mov.l   .L_0601DD68, r2
    mov.l r2, @r15
    mov r2, r7
    mov.l   .L_0601DD5C, r3
    mov.w   .L_0601DD38, r6
    mov.l   .L_0601DD6C, r5
    mov.l @(4, r7), r7
    mov.b @r3, r3
    mov.l @r5, r5
    extu.b r3, r3
    shll8 r3
    shll2 r3
    shll2 r3
    add r3, r7
    jsr @r11
    mov #0x8, r4
    mov.l @r15, r7
    mov.l @(4, r7), r7
    add r9, r7
    mov.w   .L_0601DD3A, r6
    bra     .L_0601DD70
    nop

    .global DAT_0601dd30
DAT_0601dd30:
    .2byte  0x00A0
.L_0601DD32:
    .2byte  0x0230

    .global DAT_0601dd34
DAT_0601dd34:
    .2byte  0x00C0
.L_0601DD36:
    .2byte  0x07C8
.L_0601DD38:
    .2byte  0x0842
.L_0601DD3A:
    .2byte  0x0942
.L_0601DD3C:
    .4byte  sym_0607EABC
.L_0601DD40:
    .4byte  sym_0608706A
.L_0601DD44:
    .4byte  sym_0605DFED
.L_0601DD48:
    .4byte  sym_060786A0
.L_0601DD4C:
    .4byte  sym_0605DDB4
.L_0601DD50:
    .4byte  sym_0607EAD8
.L_0601DD54:
    .4byte  sym_0605DDD4
.L_0601DD58:
    .4byte  sym_060350B0
.L_0601DD5C:
    .4byte  sym_0608707C
.L_0601DD60:
    .4byte  sym_060639F8
.L_0601DD64:
    .4byte  sym_0605E008
.L_0601DD68:
    .4byte  sym_060639E0
.L_0601DD6C:
    .4byte  sym_060639D8
.L_0601DD70:
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r11
    mov #0x8, r4
    bsr     hud_element_pos
    mov.l @r10, r4
    mov.l @(4, r15), r7
    mov.w   DAT_0601de24, r6
    mov.l   .L_0601DE30, r5
    mov.l @(4, r7), r7
    add r9, r7
    jsr @r11
    mov #0x8, r4
    mov.l @r14, r3
    mov.l   .L_0601DE34, r2
    cmp/hs r2, r3
    bf      .L_0601DD9C
    mov.l   .L_0601DE34, r4
    bsr     hud_element_pos
    nop
    bra     .L_0601DDA0
    nop
.L_0601DD9C:
    bsr     hud_element_pos
    mov.l @r14, r4
.L_0601DDA0:
    mov.l   .L_0601DE38, r7
    mov.w   DAT_0601de26, r6
    mov.l   .L_0601DE30, r5
    mov.l @(4, r7), r7
    add r9, r7
    jsr @r11
    mov #0x8, r4
    bra     .L_0601DDB6
    nop
.L_0601DDB2:
    bsr     camera_cleanup_reset
    nop
.L_0601DDB6:
    mov.l   .L_0601DE3C, r2
    mov.l   .L_0601DE3C, r3
    mov.w @r2, r2
    add #-0x1, r2
    mov.w r2, @r3
    extu.w r2, r2
    cmp/pl r2
    bt      .L_0601DDE0
    mov #0x0, r3
    mov.b r3, @r13
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     camera_cleanup_reset
    mov.l @r15+, r14
.L_0601DDE0:
    add #0x8, r15
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

    .global camera_cleanup_reset
    .type camera_cleanup_reset, @function
camera_cleanup_reset:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601DE40, r14
    mov.w   .L_0601DE28, r6
    mov.w   .L_0601DE2A, r5
    mov.l   .L_0601DE44, r3
    mov r14, r7
    jsr @r3
    mov #0x8, r4
    mov r14, r7
    mov.w   .L_0601DE28, r6
    mov.w   .L_0601DE2C, r5
    mov.l   .L_0601DE44, r3
    jsr @r3
    mov #0x8, r4
    mov r14, r7
    mov.l   .L_0601DE48, r6
    mov.w   .L_0601DE2E, r5
    mov #0x8, r4
    lds.l @r15+, pr
    mov.l   .L_0601DE4C, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_0601de24
DAT_0601de24:
    .2byte  0x08C4
DAT_0601de26:
    .2byte  0x09C4
.L_0601DE28:
    .2byte  0x0090
.L_0601DE2A:
    .2byte  0x07C2
.L_0601DE2C:
    .2byte  0x08C2
.L_0601DE2E:
    .2byte  0x09C2
.L_0601DE30:
    .4byte  sym_0605DFF4
.L_0601DE34:
    .4byte  0x000927BF
.L_0601DE38:
    .4byte  sym_060639F8
.L_0601DE3C:
    .4byte  sym_0608706A
.L_0601DE40:
    .4byte  sym_0605ACE3
.L_0601DE44:
    .4byte  sym_060284AE
.L_0601DE48:
    .4byte  0x0000E000
.L_0601DE4C:
    .4byte  sym_060283E0

    .global camera_event_handler
    .type camera_event_handler, @function
camera_event_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601DF24, r4
    mov.l   .L_0601DF28, r2
    mov.l @r4, r4
    mov r4, r3
    shll2 r4
    add r3, r4
    cmp/hs r2, r4
    bf      .L_0601DE74
    mov.l   .L_0601DF28, r4
    bsr     hud_element_pos
    nop
    bra     .L_0601DE78
    nop
.L_0601DE74:
    bsr     hud_element_pos
    nop
.L_0601DE78:
    mov.l   .L_0601DF2C, r12
    mov.l   .L_0601DF30, r14
    mov.w   DAT_0601df14, r0
    mov.l   .L_0601DF34, r2
    mov.w   DAT_0601df16, r6
    mov.l   .L_0601DF38, r5
    mov.l @(r0, r12), r7
    add r2, r7
    jsr @r14
    mov #0x8, r4
    mov.l   .L_0601DF3C, r13
    mov.w   DAT_0601df18, r0
    mov.l   .L_0601DF40, r2
    mov r13, r4
    mov.l @r2, r2
    mov.l @(r0, r4), r3
    cmp/hs r2, r3
    .word 0x0029
    xor #0x1, r0
    mov.w   DAT_0601df1a, r1
    add r4, r1
    mov.l @r1, r1
    tst r1, r1
    .word 0x0129
    add #-0x1, r1
    neg r1, r1
    and r1, r0
    tst r0, r0
    bt      .L_0601DF6E
    mov.l   .L_0601DF44, r4
    mov.l   .L_0601DF48, r3
    mov.l   .L_0601DF4C, r2
    mov.w   DAT_0601df18, r0
    mov.l @r4, r4
    mov.l @r3, r3
    shll r4
    add r3, r4
    shll2 r4
    mov.l @(r0, r13), r3
    add r2, r4
    mov.l @r4, r4
    mov.l r3, @(4, r4)
    mov.w   DAT_0601df1c, r7
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_0601DF50, r3
    mov.w   .L_0601DF1E, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_0601DF54, r4
    mov.b @r4, r3
    add #0x40, r3
    mov.b r3, @r4
    mov.b @r4, r0
    extu.b r0, r0
    shlr2 r0
    shlr2 r0
    shlr2 r0
    shlr r0
    tst #0x1, r0
    bf      .L_0601DF58
    mov.w   DAT_0601df18, r0
    bsr     hud_element_pos
    mov.l @(r0, r13), r4
    mov.w   DAT_0601df14, r0
    mov.l   .L_0601DF50, r2
    mov.w   .L_0601DF20, r6
    mov.l   .L_0601DF38, r5
    mov.l @(r0, r12), r7
    add r2, r7
    jsr @r14
    mov #0x8, r4
    bra     .L_0601DF6E
    nop

    .global DAT_0601df14
DAT_0601df14:
    .2byte  0x02AC

    .global DAT_0601df16
DAT_0601df16:
    .2byte  0x0644

    .global DAT_0601df18
DAT_0601df18:
    .2byte  0x0240

    .global DAT_0601df1a
DAT_0601df1a:
    .2byte  0x021C

    .global DAT_0601df1c
DAT_0601df1c:
    .2byte  0x0278
.L_0601DF1E:
    .2byte  0x03C2
.L_0601DF20:
    .2byte  0x0444
    .2byte  0xFFFF
.L_0601DF24:
    .4byte  sym_0607EBD0
.L_0601DF28:
    .4byte  0x000927BF
.L_0601DF2C:
    .4byte  sym_06063750
.L_0601DF30:
    .4byte  sym_06028400
.L_0601DF34:
    .4byte  0x00009000
.L_0601DF38:
    .4byte  sym_0605DFF4
.L_0601DF3C:
    .4byte  sym_06078900
.L_0601DF40:
    .4byte  sym_06086008
.L_0601DF44:
    .4byte  sym_0607EAD8
.L_0601DF48:
    .4byte  sym_0607EAE0
.L_0601DF4C:
    .4byte  sym_0605DE24
.L_0601DF50:
    .4byte  0x0000A000
.L_0601DF54:
    .4byte  sym_0605DFEC
.L_0601DF58:
    mov.l   .L_0601DF7C, r7
    mov.l   .L_0601DF80, r6
    mov.w   .L_0601DF7A, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_0601DF84, r3
    jmp @r3
    mov.l @r15+, r14
.L_0601DF6E:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0601DF7A:
    .2byte  0x0442
.L_0601DF7C:
    .4byte  sym_0605ACE3
.L_0601DF80:
    .4byte  0x0000E000
.L_0601DF84:
    .4byte  sym_060283E0

    .global camera_special_mode
    .type camera_special_mode, @function
camera_special_mode:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601E034, r9
    mov.l   .L_0601E038, r10
    mov.w   .L_0601E022, r11
    mov.l   .L_0601E03C, r12
    mov.l   .L_0601E040, r13
    mov.l   .L_0601E044, r14
    mov.l   .L_0601E048, r3
    mov r11, r0
    add #-0x68, r0
    mov.l @(r0, r3), r2
    mov.l   .L_0601E04C, r3
    mov.l @r3, r3
    cmp/hs r3, r2
    bt      .L_0601DFE0
    mov.w   DAT_0601e024, r7
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_0601E026, r6
    mov.l @r15, r5
    add r9, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_0601E048, r4
    mov.w   DAT_0601e028, r0
    bsr     hud_element_pos
    mov.l @(r0, r4), r4
    mov r12, r7
    mov.w   DAT_0601e02a, r6
    mov.l   .L_0601E050, r5
    add r11, r7
    mov.l @(4, r7), r7
    add r9, r7
    jsr @r14
    mov #0x8, r4
.L_0601DFE0:
    bsr     hud_element_pos
    mov.l @r13, r4
    mov r12, r7
    mov.l   .L_0601E054, r3
    mov.w   DAT_0601e02c, r6
    mov.l   .L_0601E050, r5
    add r11, r7
    mov.l @(4, r7), r7
    add r3, r7
    jsr @r14
    mov #0x8, r4
    mov.l @r13, r2
    mov.l   .L_0601E058, r3
    mov.l @r3, r3
    cmp/hs r3, r2
    bt      .L_0601E0CC
    mov.w   DAT_0601e02e, r7
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_0601E030, r6
    mov.l @r15, r5
    add r9, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.l @r13, r3
    cmp/hs r10, r3
    bf      .L_0601E05C
    bsr     hud_element_pos
    mov r10, r4
    bra     .L_0601E060
    nop
.L_0601E022:
    .2byte  0x02A8

    .global DAT_0601e024
DAT_0601e024:
    .2byte  0x0278
.L_0601E026:
    .2byte  0x03C2

    .global DAT_0601e028
DAT_0601e028:
    .2byte  0x0240

    .global DAT_0601e02a
DAT_0601e02a:
    .2byte  0x0444

    .global DAT_0601e02c
DAT_0601e02c:
    .2byte  0x0644

    .global DAT_0601e02e
DAT_0601e02e:
    .2byte  0x0280
.L_0601E030:
    .2byte  0x04C2
    .2byte  0xFFFF
.L_0601E034:
    .4byte  0x0000A000
.L_0601E038:
    .4byte  0x000927BF
.L_0601E03C:
    .4byte  sym_06063750
.L_0601E040:
    .4byte  sym_0607863C
.L_0601E044:
    .4byte  sym_06028400
.L_0601E048:
    .4byte  sym_06078900
.L_0601E04C:
    .4byte  sym_06086008
.L_0601E050:
    .4byte  sym_0605DFF4
.L_0601E054:
    .4byte  0x00009000
.L_0601E058:
    .4byte  sym_06086004
.L_0601E05C:
    bsr     hud_element_pos
    mov.l @r13, r4
.L_0601E060:
    mov r12, r7
    mov.l   .L_0601E0E8, r3
    mov.w   DAT_0601e0e2, r6
    mov.l   .L_0601E0EC, r5
    add r11, r7
    mov.l @(4, r7), r7
    add r3, r7
    jsr @r14
    mov #0x8, r4
    mov.l   .L_0601E0F0, r4
    mov.b @r4, r2
    add #0x40, r2
    mov.b r2, @r4
    mov.b @r4, r0
    extu.b r0, r0
    shlr2 r0
    shlr2 r0
    shlr2 r0
    shlr r0
    tst #0x1, r0
    bf      .L_0601E0B0
    mov.l @r13, r3
    cmp/hs r10, r3
    bf      .L_0601E098
    bsr     hud_element_pos
    mov r10, r4
    bra     .L_0601E09C
    nop
.L_0601E098:
    bsr     hud_element_pos
    mov.l @r13, r4
.L_0601E09C:
    mov r12, r7
    mov.w   DAT_0601e0e4, r6
    mov.l   .L_0601E0EC, r5
    add r11, r7
    mov.l @(4, r7), r7
    add r9, r7
    jsr @r14
    mov #0x8, r4
    bra     .L_0601E0CC
    nop
.L_0601E0B0:
    mov.l   .L_0601E0F4, r7
    mov.l   .L_0601E0F8, r6
    mov.w   .L_0601E0E6, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_0601E0FC, r3
    jmp @r3
    mov.l @r15+, r14
.L_0601E0CC:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0601E0DE
sym_0601E0DE:
    rts
    nop

    .global DAT_0601e0e2
DAT_0601e0e2:
    .2byte  0x0644

    .global DAT_0601e0e4
DAT_0601e0e4:
    .2byte  0x0544
.L_0601E0E6:
    .2byte  0x0542
.L_0601E0E8:
    .4byte  0x00009000
.L_0601E0EC:
    .4byte  sym_0605DFF4
.L_0601E0F0:
    .4byte  sym_0605DFEC
.L_0601E0F4:
    .4byte  sym_0605ACE3
.L_0601E0F8:
    .4byte  0x0000E000
.L_0601E0FC:
    .4byte  sym_060283E0

    .global geom_matrix_setup
    .type geom_matrix_setup, @function
geom_matrix_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601E16C, r13
    mov.l   .L_0601E170, r14
    mov.l   .L_0601E174, r12
    mov.l   .L_0601E178, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601E14A
    mov.l   .L_0601E17C, r5
    mov.l   .L_0601E180, r4
    mov.l   .L_0601E184, r3
    jsr @r3
    mov #0x20, r6
    mov r13, r7
    add #0x10, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_0601e162, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_0601e164, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    add r12, r7
    mov.w   DAT_0601e166, r6
    mov.l @r15, r5
    bra     .L_0601E21C
    mov.l @r5, r5
.L_0601E14A:
    mov.l   .L_0601E188, r5
    mov.l   .L_0601E180, r4
    mov.l   .L_0601E184, r3
    jsr @r3
    mov #0x20, r6
    mov.l   .L_0601E18C, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601E190
    mov.w   .L_0601E168, r7
    bra     .L_0601E192
    nop

    .global DAT_0601e162
DAT_0601e162:
    .2byte  0x0344

    .global DAT_0601e164
DAT_0601e164:
    .2byte  0x0270

    .global DAT_0601e166
DAT_0601e166:
    .2byte  0x06C6
.L_0601E168:
    .2byte  0x00F8
    .2byte  0xFFFF
.L_0601E16C:
    .4byte  sym_06063750
.L_0601E170:
    .4byte  sym_06028400
.L_0601E174:
    .4byte  0x00008000
.L_0601E178:
    .4byte  sym_0607EAE0
.L_0601E17C:
    .4byte  sym_0604892C
.L_0601E180:
    .4byte  0x25F00100
.L_0601E184:
    .4byte  memcpy_word_idx
.L_0601E188:
    .4byte  sym_0605DFCC
.L_0601E18C:
    .4byte  sym_06078644
.L_0601E190:
    mov.w   DAT_0601e238, r7
.L_0601E192:
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_0601e23a, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_0601E250, r12
    mov.w   DAT_0601e23c, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_0601E23E, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_0601e240, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_0601E242, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_0601e244, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_0601E246, r6
    mov.l @r15, r5
    add r12, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_0601E254, r3
    jsr @r3
    nop
    mov.l   .L_0601E258, r4
    bsr     hud_element_pos
    mov.l @r4, r4
    mov.w   DAT_0601e248, r11
    mov.w   DAT_0601e24a, r6
    mov.l   .L_0601E25C, r5
    add r13, r11
    mov.l @(4, r11), r7
    add r12, r7
    jsr @r14
    mov #0x8, r4
    mov.l   .L_0601E260, r4
    bsr     hud_element_pos
    mov.l @r4, r4
    mov.l @(4, r11), r7
    mov.w   DAT_0601e24c, r6
    mov.l   .L_0601E25C, r5
    add r12, r7
    jsr @r14
    mov #0x8, r4
    bsr     hud_element_pos
    mov #0x0, r4
    mov.l @(4, r11), r7
    add r12, r7
    mov.w   DAT_0601e24e, r6
    mov.l   .L_0601E25C, r5
.L_0601E21C:
    jsr @r14
    mov #0x8, r4
    mov #0x0, r4
    mov.l   .L_0601E264, r3
    mov.b r4, @r3
    mov.l   .L_0601E268, r3
    mov.l r4, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601e238
DAT_0601e238:
    .2byte  0x0100

    .global DAT_0601e23a
DAT_0601e23a:
    .2byte  0x00C4

    .global DAT_0601e23c
DAT_0601e23c:
    .2byte  0x0278
.L_0601E23E:
    .2byte  0x03C2

    .global DAT_0601e240
DAT_0601e240:
    .2byte  0x0280
.L_0601E242:
    .2byte  0x04C2

    .global DAT_0601e244
DAT_0601e244:
    .2byte  0x0290
.L_0601E246:
    .2byte  0x05C2

    .global DAT_0601e248
DAT_0601e248:
    .2byte  0x02A8

    .global DAT_0601e24a
DAT_0601e24a:
    .2byte  0x0444

    .global DAT_0601e24c
DAT_0601e24c:
    .2byte  0x0544

    .global DAT_0601e24e
DAT_0601e24e:
    .2byte  0x0644
.L_0601E250:
    .4byte  0x00009000
.L_0601E254:
    .4byte  sym_0601AB8C
.L_0601E258:
    .4byte  sym_06086008
.L_0601E25C:
    .4byte  sym_0605DFF4
.L_0601E260:
    .4byte  sym_06086004
.L_0601E264:
    .4byte  sym_06087068
.L_0601E268:
    .4byte  sym_0605DFF0

    .global hud_element_pos
    .type hud_element_pos, @function
hud_element_pos:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601E2A8, r12
    mov.l   .L_0601E2AC, r13
    mov.l   .L_0601E2B0, r3
    jsr @r3
    mov #0x8, r14
    mov.l r0, @r13
    mov #0x0, r4
.L_0601E282:
    extu.b r4, r2
    extu.b r4, r0
    mov.l @r13, r3
    shll r2
    add #0x1, r4
    mov.b @(r0, r3), r1
    add r12, r2
    extu.b r1, r1
    extu.b r4, r3
    mov r1, r0
    mov.w r0, @(4, r2)
    cmp/ge r14, r3
    bf      .L_0601E282
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0601E2A8:
    .4byte  sym_0605DFF4
.L_0601E2AC:
    .4byte  sym_06087064
.L_0601E2B0:
    .4byte  anim_frame_transform
