
    .section .text.FUN_0602FDB0


    .global FUN_0602FDB0
    .type FUN_0602FDB0, @function
FUN_0602FDB0:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x0, r9
    mov r0, r6
    mov #0x1, r5
    mov #0x0, r7
    mov.l   .L_0602FDCC, r0
    mov.l @r0, r0
    mov.l   .L_0602FDD0, r1
    mov.w @r1, r2
    tst r2, r2
    bt      .L_0602FDD4
    bra     .L_060300B0
    nop
.L_0602FDCC:
    .4byte  sym_0607E944
.L_0602FDD0:
    .4byte  sym_0607ED8C
.L_0602FDD4:
    mov.l   .L_0602FDF8, r2
    mov.w @r2, r1
    extu.w r1, r1
    mov.l   .L_0602FDFC, r2
    mov.w @r2, r2
    cmp/pl r2
    mov.w   .L_0602FDF4, r3
    bf      .L_0602FE1C
    tst r1, r2
    bt      .L_0602FE00
    mov.w @(r0, r3), r4
    tst r4, r4
    bt      .L_0602FDF0
    add #-0x1, r4
.L_0602FDF0:
    bra     .L_0602FE64
    mov.w r4, @(r0, r3)
.L_0602FDF4:
    .2byte  0x00DE
    .2byte  0x0000
.L_0602FDF8:
    .4byte  sym_06063D9A
.L_0602FDFC:
    .4byte  sym_0608188A
.L_0602FE00:
    mov.l   .L_0602FE18, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_0602FE64
    mov.w @(r0, r3), r4
    mov #0x3, r2
    cmp/eq r4, r2
    bt      .L_0602FE12
    add #0x1, r4
.L_0602FE12:
    bra     .L_0602FE64
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_0602FE18:
    .4byte  sym_06081888
.L_0602FE1C:
    mov.l   .L_0602FE2C, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_0602FE30
    mov #0x3, r4
    bra     .L_0602FE64
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_0602FE2C:
    .4byte  sym_06081896
.L_0602FE30:
    mov.l   .L_0602FE40, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_0602FE44
    mov #0x2, r4
    bra     .L_0602FE64
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_0602FE40:
    .4byte  sym_06081894
.L_0602FE44:
    mov.l   .L_0602FE54, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_0602FE58
    mov #0x1, r4
    bra     .L_0602FE64
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_0602FE54:
    .4byte  sym_06081892
.L_0602FE58:
    mov.l   .L_0602FEA0, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_0602FE64
    mov #0x0, r4
    mov.w r4, @(r0, r3)
.L_0602FE64:
    mov.w @(r0, r3), r4
    mov r4, r9
    mov.l   .L_0602FEA4, r3
    mov.w @r3, r1
    extu.w r1, r1
    mov #0x1, r5
    mov.l   .L_0602FEA8, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_0602FEAC
    mov #-0x80, r8
    extu.b r8, r8
    or r8, r9
    mov.w   .L_0602FE9A, r2
    mov.l r5, @(r0, r2)
    add #0x8, r2
    mov.l @(r0, r2), r4
    mov.w   .L_0602FE9C, r8
    cmp/gt r8, r4
    bt      .L_0602FE96
    add #0xA, r4
    mov.w   .L_0602FE9E, r3
    cmp/gt r4, r3
    bt      .L_0602FE96
    mov r8, r4
.L_0602FE96:
    bra     .L_0602FED6
    mov.l r4, @(r0, r2)
.L_0602FE9A:
    .2byte  0x006C
.L_0602FE9C:
    .2byte  0x00B8
.L_0602FE9E:
    .2byte  0x00A0
.L_0602FEA0:
    .4byte  sym_06081890
.L_0602FEA4:
    .4byte  g_pad_state
.L_0602FEA8:
    .4byte  sym_0608188C
.L_0602FEAC:
    mov.w   .L_0602FEBE, r3
    mov #-0x50, r2
    mov.l @(r0, r3), r4
    extu.b r2, r2
    mov r4, r6
    cmp/gt r4, r2
    bt      .L_0602FEC0
    bra     .L_0602FECE
    add #-0x1, r4
.L_0602FEBE:
    .2byte  0x0074
.L_0602FEC0:
    shlr2 r6
    shlr2 r6
    sub r6, r4
    mov #0x6F, r6
    cmp/ge r6, r4
    bt      .L_0602FECE
    mov #0x38, r4
.L_0602FECE:
    mov.l r4, @(r0, r3)
    mov.l   .L_0602FF00, r2
    mov #0x0, r7
    mov.l r7, @(r0, r2)
.L_0602FED6:
    mov.l   .L_0602FF04, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_0602FF0C
    mov #0x40, r8
    or r8, r9
    mov.w   .L_0602FEFA, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_0602FEFC, r3
    mov.l @(r0, r3), r4
    mov.w   .L_0602FEFE, r6
    mov.l r4, @(r0, r6)
    mov.l   .L_0602FF08, r8
    cmp/gt r8, r4
    bt      .L_0602FEF6
    add #0x28, r4
.L_0602FEF6:
    bra     .L_0602FF2A
    mov.l r4, @(r0, r3)
.L_0602FEFA:
    .2byte  0x0088
.L_0602FEFC:
    .2byte  0x0090
.L_0602FEFE:
    .2byte  0x008C
.L_0602FF00:
    .4byte  0x0000006C
.L_0602FF04:
    .4byte  sym_0608188E
.L_0602FF08:
    .4byte  0x000000B8
.L_0602FF0C:
    mov.l   .L_0602FF3C, r3
    mov.l @(r0, r3), r4
    mov.l   .L_0602FF40, r6
    mov.l r4, @(r0, r6)
    mov #0x38, r3
    mov r4, r2
    shlr r2
    sub r2, r4
    cmp/ge r3, r4
    bt      .L_0602FF22
    mov r3, r4
.L_0602FF22:
    mov.l   .L_0602FF3C, r3
    mov.l r4, @(r0, r3)
    mov.l   .L_0602FF44, r3
    mov.l r7, @(r0, r3)
.L_0602FF2A:
    mov #0x0, r10
    mov.w   .L_0602FF38, r4
    mov.w @(r0, r4), r3
    tst r3, r3
    bt      .L_0602FF48
    bra     .L_0603004C
    mov #0x1, r10
.L_0602FF38:
    .2byte  0x009E
    .2byte  0x0000
.L_0602FF3C:
    .4byte  0x00000090
.L_0602FF40:
    .4byte  0x0000008C
.L_0602FF44:
    .4byte  0x00000088
.L_0602FF48:
    mov.l   .L_0602FFA0, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_0602FFA8
    mov #0x20, r8
    or r8, r9
    mov #0x0, r7
    mov #0x1, r5
    mov.w   .L_0602FF96, r3
    mov.l r7, @(r0, r3)
    mov.w   .L_0602FF98, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_0602FF9A, r3
    mov.l @(r0, r3), r8
    mov.w   .L_0602FF9C, r6
    mov.l @(r0, r6), r4
    cmp/pl r8
    bf      .L_0602FF76
    mov #-0x32, r7
    shar r8
    cmp/gt r8, r7
    bt      .L_0602FF92
    mov #0x0, r8
.L_0602FF76:
    mov #-0x70, r7
    sub r8, r7
    mov.l r1, @-r15
    mov.l r3, @-r15
    sts.l pr, @-r15
    mov.l   .L_0602FFA4, r3
    mov r7, r1
    jsr @r3
    mov #0x7, r0
    add r1, r8
    lds.l @r15+, pr
    mov.l @r15+, r3
    mov.l @r15+, r1
    mov r14, r0
.L_0602FF92:
    bra     .L_06030068
    mov.l r8, @(r0, r3)
.L_0602FF96:
    .2byte  0x00A4
.L_0602FF98:
    .2byte  0x00A0
.L_0602FF9A:
    .2byte  0x00AC
.L_0602FF9C:
    .2byte  0x00A8
    .2byte  0x0000
.L_0602FFA0:
    .4byte  sym_06063F48
.L_0602FFA4:
    .4byte  sym_0602ECCC
.L_0602FFA8:
    mov.l   .L_06030000, r2
    mov.w @r2, r2
    extu.w r2, r2
    tst r1, r2
    bt      .L_06030008
    mov #0x10, r8
    or r8, r9
    mov #0x0, r7
    mov #0x1, r5
    mov.w   .L_0602FFF8, r3
    mov.l r7, @(r0, r3)
    mov.w   .L_0602FFFA, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_0602FFFC, r3
    mov.l @(r0, r3), r8
    mov.w   .L_0602FFFE, r6
    mov.l @(r0, r6), r4
    cmp/pz r8
    bt      .L_0602FFD8
    mov #0x32, r7
    shar r8
    cmp/gt r7, r8
    bt      .L_0602FFF4
    mov #0x0, r8
.L_0602FFD8:
    mov #0x70, r7
    sub r8, r7
    mov.l r1, @-r15
    mov.l r3, @-r15
    sts.l pr, @-r15
    mov.l   .L_06030004, r3
    mov r7, r1
    jsr @r3
    mov #0x7, r0
    add r1, r8
    lds.l @r15+, pr
    mov.l @r15+, r3
    mov.l @r15+, r1
    mov r14, r0
.L_0602FFF4:
    bra     .L_06030068
    mov.l r8, @(r0, r3)
.L_0602FFF8:
    .2byte  0x00A0
.L_0602FFFA:
    .2byte  0x00A4
.L_0602FFFC:
    .2byte  0x00AC
.L_0602FFFE:
    .2byte  0x00A8
.L_06030000:
    .4byte  sym_06063F4A
.L_06030004:
    .4byte  sym_0602ECCC
.L_06030008:
    mov.w   .L_0603002A, r6
    mov #0x0, r4
    mov.l r4, @(r0, r6)
    mov.w   .L_0603002C, r3
    mov.l @(r0, r3), r4
    tst r4, r4
    bt      .L_06030068
    cmp/pl r4
    bt/s    .L_0603002E
    mov r4, r6
    mov #-0x68, r8
    mov #-0x7, r7
    cmp/ge r8, r6
    bt      .L_06030024
.L_06030024:
    sub r6, r4
    bra     .L_06030038
    nop
.L_0603002A:
    .2byte  0x00A8
.L_0603002C:
    .2byte  0x00AC
.L_0603002E:
    mov #0x68, r8
    mov #0x7, r7
    cmp/ge r6, r8
    bt      .L_06030036
.L_06030036:
    sub r6, r4
.L_06030038:
    mov.l r4, @(r0, r3)
    mov.w   .L_06030048, r3
    mov #0x0, r7
    mov.l r7, @(r0, r3)
    mov.w   .L_0603004A, r3
    mov.l r7, @(r0, r3)
    bra     .L_06030068
    nop
.L_06030048:
    .2byte  0x00A0
.L_0603004A:
    .2byte  0x00A4
.L_0603004C:
    mov.l   .L_060300A0, r3
    mov.w @r3, r1
    mov.l   .L_060300A4, r7
    mov.b @r7, r7
    tst r7, r7
    bf      .L_0603005A
    not r1, r1
.L_0603005A:
    extu.b r1, r1
    mov r1, r7
    mov #-0x80, r5
    add r5, r1
    mov.w   .L_0603009A, r3
    mov.l @(r0, r3), r4
    mov.l r1, @(r0, r3)
.L_06030068:
    mov.l   .L_060300A8, r2
    mov.l   .L_060300AC, r4
    mov.l @r4, r6
    add r6, r2
    add #0x1, r6
    mov.b r9, @r2
    tst r10, r10
    add #0x1, r2
    add #0x1, r6
    bt      .L_0603007E
    mov.b r7, @r2
.L_0603007E:
    mov.w   .L_0603009C, r3
    cmp/ge r6, r3
    bt      .L_06030086
    add #-0x2, r6
.L_06030086:
    mov.l r6, @r4
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
.L_0603009A:
    .2byte  0x00AC
.L_0603009C:
    .2byte  0x2AF6
    .2byte  0x0000
.L_060300A0:
    .4byte  sym_06063D9C
.L_060300A4:
    .4byte  sym_06078663
.L_060300A8:
    .4byte  sym_0607ED90
.L_060300AC:
    .4byte  sym_0607ED88
.L_060300B0:
    mov.l   .L_060300F8, r2
    mov.l   .L_060300FC, r4
    mov.l @r4, r6
    add r6, r2
    add #0x1, r6
    mov.b @r2, r1
    mov.w   .L_060300F0, r3
    extu.b r1, r1
    mov r1, r5
    mov #0x3, r2
    and r2, r5
    mov.w r5, @(r0, r3)
    mov.l r6, @r4
    mov #0x1, r5
    mov #-0x80, r2
    extu.b r2, r2
    tst r1, r2
    bt      .L_06030100
    mov.w   .L_060300F2, r2
    mov.l r5, @(r0, r2)
    add #0x8, r2
    mov.l @(r0, r2), r4
    mov.w   .L_060300F4, r8
    cmp/gt r8, r4
    bt      .L_060300EC
    add #0xA, r4
    mov.w   .L_060300F6, r3
    cmp/gt r4, r3
    bt      .L_060300EC
    mov r8, r4
.L_060300EC:
    bra     .L_0603012A
    mov.l r4, @(r0, r2)
.L_060300F0:
    .2byte  0x00DE
.L_060300F2:
    .2byte  0x006C
.L_060300F4:
    .2byte  0x00B8
.L_060300F6:
    .2byte  0x00A0
.L_060300F8:
    .4byte  sym_0607ED90
.L_060300FC:
    .4byte  sym_0607ED88
.L_06030100:
    mov.w   .L_06030112, r3
    mov #-0x50, r2
    mov.l @(r0, r3), r4
    extu.b r2, r2
    mov r4, r6
    cmp/gt r4, r2
    bt      .L_06030114
    bra     .L_06030122
    add #-0x1, r4
.L_06030112:
    .2byte  0x0074
.L_06030114:
    shlr2 r6
    shlr2 r6
    sub r6, r4
    mov #0x6F, r6
    cmp/ge r6, r4
    bt      .L_06030122
    mov #0x38, r4
.L_06030122:
    mov.l r4, @(r0, r3)
    mov.l   .L_06030150, r2
    mov #0x0, r7
    mov.l r7, @(r0, r2)
.L_0603012A:
    mov #0x40, r2
    tst r1, r2
    bt      .L_06030158
    mov.w   .L_06030148, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_0603014A, r3
    mov.l @(r0, r3), r4
    mov.w   .L_0603014C, r6
    mov.l r4, @(r0, r6)
    mov.l   .L_06030154, r8
    cmp/gt r8, r4
    bt      .L_06030144
    add #0x28, r4
.L_06030144:
    bra     .L_06030176
    mov.l r4, @(r0, r3)
.L_06030148:
    .2byte  0x0088
.L_0603014A:
    .2byte  0x0090
.L_0603014C:
    .2byte  0x008C
    .2byte  0x0000
.L_06030150:
    .4byte  0x0000006C
.L_06030154:
    .4byte  0x000000B8
.L_06030158:
    mov.l   .L_06030184, r3
    mov.l @(r0, r3), r4
    mov.l   .L_06030188, r6
    mov.l r4, @(r0, r6)
    mov #0x38, r3
    mov r4, r2
    shlr r2
    sub r2, r4
    cmp/ge r3, r4
    bt      .L_0603016E
    mov r3, r4
.L_0603016E:
    mov.l   .L_06030184, r3
    mov.l r4, @(r0, r3)
    mov.l   .L_0603018C, r3
    mov.l r7, @(r0, r3)
.L_06030176:
    mov #0x0, r10
    mov.l   .L_06030190, r4
    mov.b @r4, r3
    tst r3, r3
    bt      .L_06030194
    bra     .L_06030280
    mov #0x1, r10
.L_06030184:
    .4byte  0x00000090
.L_06030188:
    .4byte  0x0000008C
.L_0603018C:
    .4byte  0x00000088
.L_06030190:
    .4byte  sym_0607ED90
.L_06030194:
    mov #0x20, r2
    tst r1, r2
    bt      .L_060301E8
    mov #0x0, r7
    mov #0x1, r5
    mov.w   .L_060301DC, r3
    mov.l r7, @(r0, r3)
    mov.w   .L_060301DE, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_060301E0, r3
    mov.l @(r0, r3), r8
    mov.w   .L_060301E2, r6
    mov.l @(r0, r6), r4
    cmp/pl r8
    bf      .L_060301BC
    mov #-0x32, r7
    shar r8
    cmp/gt r8, r7
    bt      .L_060301D8
    mov #0x0, r8
.L_060301BC:
    mov #-0x70, r7
    sub r8, r7
    mov.l r1, @-r15
    mov.l r3, @-r15
    sts.l pr, @-r15
    mov.l   .L_060301E4, r3
    mov r7, r1
    jsr @r3
    mov #0x7, r0
    add r1, r8
    lds.l @r15+, pr
    mov.l @r15+, r3
    mov.l @r15+, r1
    mov r14, r0
.L_060301D8:
    bra     .L_06030296
    mov.l r8, @(r0, r3)
.L_060301DC:
    .2byte  0x00A4
.L_060301DE:
    .2byte  0x00A0
.L_060301E0:
    .2byte  0x00AC
.L_060301E2:
    .2byte  0x00A8
.L_060301E4:
    .4byte  sym_0602ECCC
.L_060301E8:
    mov #0x10, r2
    tst r1, r2
    bt      .L_0603023C
    mov #0x0, r7
    mov #0x1, r5
    mov.w   .L_06030230, r3
    mov.l r7, @(r0, r3)
    mov.w   .L_06030232, r3
    mov.l r5, @(r0, r3)
    mov.w   .L_06030234, r3
    mov.l @(r0, r3), r8
    mov.w   .L_06030236, r6
    mov.l @(r0, r6), r4
    cmp/pz r8
    bt      .L_06030210
    mov #0x32, r7
    shar r8
    cmp/gt r7, r8
    bt      .L_0603022C
    mov #0x0, r8
.L_06030210:
    mov #0x70, r7
    sub r8, r7
    mov.l r1, @-r15
    mov.l r3, @-r15
    sts.l pr, @-r15
    mov.l   .L_06030238, r3
    mov r7, r1
    jsr @r3
    mov #0x7, r0
    add r1, r8
    lds.l @r15+, pr
    mov.l @r15+, r3
    mov.l @r15+, r1
    mov r14, r0
.L_0603022C:
    bra     .L_06030296
    mov.l r8, @(r0, r3)
.L_06030230:
    .2byte  0x00A0
.L_06030232:
    .2byte  0x00A4
.L_06030234:
    .2byte  0x00AC
.L_06030236:
    .2byte  0x00A8
.L_06030238:
    .4byte  sym_0602ECCC
.L_0603023C:
    mov.w   .L_0603025E, r6
    mov #0x0, r4
    mov.l r4, @(r0, r6)
    mov.w   .L_06030260, r3
    mov.l @(r0, r3), r4
    tst r4, r4
    bt      .L_06030296
    cmp/pl r4
    bt/s    .L_06030262
    mov r4, r6
    mov #-0x68, r8
    mov #-0x7, r7
    cmp/ge r8, r6
    bt      .L_06030258
.L_06030258:
    sub r6, r4
    bra     .L_0603026C
    nop
.L_0603025E:
    .2byte  0x00A8
.L_06030260:
    .2byte  0x00AC
.L_06030262:
    mov #0x68, r8
    mov #0x7, r7
    cmp/ge r6, r8
    bt      .L_0603026A
.L_0603026A:
    sub r6, r4
.L_0603026C:
    mov.l r4, @(r0, r3)
    mov.w   .L_0603027C, r3
    mov #0x0, r7
    mov.l r7, @(r0, r3)
    mov.w   .L_0603027E, r3
    mov.l r7, @(r0, r3)
    bra     .L_06030296
    nop
.L_0603027C:
    .2byte  0x00A0
.L_0603027E:
    .2byte  0x00A4
.L_06030280:
    mov.l   .L_060302B4, r2
    mov.l   .L_060302B8, r4
    mov.l @r4, r6
    add r6, r2
    mov.b @r2, r1
    mov #-0x80, r5
    extu.b r1, r1
    add r5, r1
    mov.w   .L_060302B0, r3
    mov.l @(r0, r3), r4
    mov.l r1, @(r0, r3)
.L_06030296:
    mov.l   .L_060302B8, r4
    mov.l @r4, r6
    add #0x1, r6
    mov.l r6, @r4
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
.L_060302B0:
    .2byte  0x00AC
    .2byte  0x0000
.L_060302B4:
    .4byte  sym_0607ED90
.L_060302B8:
    .4byte  sym_0607ED88
    .4byte  0x00090009
    .4byte  0x401589FB
    .2byte  0x0009

    .global sym_060302C6
sym_060302C6:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15


    .global FUN_060302D2
    .type FUN_060302D2, @function
FUN_060302D2:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x0, r9
    mov r0, r6
    mov #0x1, r5
    mov #0x0, r7
    mov.l   .L_060302F0, r0
    mov.l @r0, r0
    mov.l   .L_060302F4, r1
    mov.w @r1, r2
    tst r2, r2
    bt      .L_060302F8
    bra     .L_06030474
    nop
    .2byte  0x0000
.L_060302F0:
    .4byte  sym_0607E944
.L_060302F4:
    .4byte  sym_0607ED8C
.L_060302F8:
    mov.l   .L_0603031C, r2
    mov.w @r2, r1
    extu.w r1, r1
    mov.l   .L_06030320, r2
    mov.w @r2, r2
    mov.w   .L_06030318, r3
    cmp/pl r2
    bf      .L_06030340
    tst r1, r2
    bt      .L_06030324
    mov.w @(r0, r3), r4
    tst r4, r4
    bt      .L_06030314
    add #-0x1, r4
.L_06030314:
    bra     .L_06030388
    mov.w r4, @(r0, r3)
.L_06030318:
    .2byte  0x00DE
    .2byte  0x0000
.L_0603031C:
    .4byte  sym_06063D9A
.L_06030320:
    .4byte  sym_0608188A
.L_06030324:
    mov.l   .L_0603033C, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_06030388
    mov.w @(r0, r3), r4
    mov #0x3, r2
    cmp/eq r4, r2
    bt      .L_06030336
    add #0x1, r4
.L_06030336:
    bra     .L_06030388
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_0603033C:
    .4byte  sym_06081888
.L_06030340:
    mov.l   .L_06030350, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_06030354
    mov #0x3, r4
    bra     .L_06030388
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_06030350:
    .4byte  sym_06081896
.L_06030354:
    mov.l   .L_06030364, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_06030368
    mov #0x2, r4
    bra     .L_06030388
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_06030364:
    .4byte  sym_06081894
.L_06030368:
    mov.l   .L_06030378, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_0603037C
    mov #0x1, r4
    bra     .L_06030388
    mov.w r4, @(r0, r3)
    .2byte  0x0000
.L_06030378:
    .4byte  sym_06081892
.L_0603037C:
    mov.l   .L_060303BC, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_06030388
    mov #0x0, r4
    mov.w r4, @(r0, r3)
.L_06030388:
    mov.w @(r0, r3), r4
    mov r4, r9
    mov.l   .L_060303C0, r3
    mov.w @r3, r1
    extu.w r1, r1
    mov #0x1, r5
    mov.l   .L_060303C4, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_060303C8
    mov #-0x80, r8
    extu.b r8, r8
    or r8, r9
    mov.w   DAT_060303b6, r2
    mov.l r5, @(r0, r2)
    add #0x8, r2
    mov.w   .L_060303B8, r8
    mov.l @(r0, r2), r4
    cmp/gt r8, r4
    bt      .L_060303B2
    add #0x4, r4
.L_060303B2:
    bra     .L_060303DE
    mov.l r4, @(r0, r2)

    .global DAT_060303b6
DAT_060303b6:
    .2byte  0x006C
.L_060303B8:
    .2byte  0x00B8
    .2byte  0x0000
.L_060303BC:
    .4byte  sym_06081890
.L_060303C0:
    .4byte  g_pad_state
.L_060303C4:
    .4byte  sym_0608188C
.L_060303C8:
    mov.w   DAT_06030402, r3
    mov #0x38, r5
    mov.l @(r0, r3), r4
    add #-0x2, r4
    cmp/gt r5, r4
    bt      .L_060303D6
    mov r5, r4
.L_060303D6:
    mov.l r4, @(r0, r3)
    mov.l   .L_06030408, r2
    mov #0x0, r7
    mov.l r7, @(r0, r2)
.L_060303DE:
    mov.l   .L_0603040C, r2
    mov.w @r2, r2
    tst r1, r2
    bt      .L_0603041C
    mov #0x40, r8
    or r8, r9
    mov.l   .L_06030410, r3
    mov.l r5, @(r0, r3)
    mov.l   .L_06030414, r3
    mov.l @(r0, r3), r4
    mov.l   .L_06030418, r6
    mov.w   .L_06030404, r8
    mov.l r4, @(r0, r6)
    cmp/gt r8, r4
    bt      .L_060303FE
    add #0x5, r4
.L_060303FE:
    bra     .L_06030436
    mov.l r4, @(r0, r3)

    .global DAT_06030402
DAT_06030402:
    .2byte  0x0074
.L_06030404:
    .2byte  0x00B8
    .2byte  0x0000
.L_06030408:
    .4byte  0x0000006C
.L_0603040C:
    .4byte  sym_0608188E
.L_06030410:
    .4byte  0x00000088
.L_06030414:
    .4byte  0x00000090
.L_06030418:
    .4byte  0x0000008C
.L_0603041C:
    mov.l   .L_06030460, r3
    mov.l @(r0, r3), r4
    mov.l   .L_06030464, r6
    mov.l r4, @(r0, r6)
    mov #0x38, r3
    add #-0x5, r4
    cmp/ge r3, r4
    bt      .L_0603042E
    mov r3, r4
.L_0603042E:
    mov.l   .L_06030460, r3
    mov.l r4, @(r0, r3)
    mov.l   .L_06030468, r3
    mov.l r7, @(r0, r3)
.L_06030436:
    mov.l   .L_0603046C, r2
    mov.l   .L_06030470, r4
    mov.l @r4, r6
    add r6, r2
    add #0x2, r6
    mov.b r9, @r2
    mov.w   DAT_0603045e, r3
    cmp/gt r6, r3
    bt      .L_0603044A
    add #-0x2, r6
.L_0603044A:
    mov.l r6, @r4
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8

    .global DAT_0603045e
DAT_0603045e:
    .2byte  0x2AF6
.L_06030460:
    .4byte  0x00000090
.L_06030464:
    .4byte  0x0000008C
.L_06030468:
    .4byte  0x00000088
.L_0603046C:
    .4byte  sym_0607ED90
.L_06030470:
    .4byte  sym_0607ED88
.L_06030474:
    mov.l   .L_060304B4, r2
    mov.l   .L_060304B8, r4
    mov.l @r4, r6
    add r6, r2
    add #0x2, r6
    mov.b @r2, r1
    mov.w   DAT_060304ac, r3
    extu.b r1, r1
    mov r1, r5
    mov #0x3, r2
    and r2, r5
    mov.w r5, @(r0, r3)
    mov.l r6, @r4
    mov #0x1, r5
    mov #-0x80, r2
    extu.b r2, r2
    tst r1, r2
    bt      .L_060304BC
    mov.w   DAT_060304ae, r2
    mov.l r5, @(r0, r2)
    add #0x8, r2
    mov.w   .L_060304B0, r8
    mov.l @(r0, r2), r4
    cmp/gt r8, r4
    bt      .L_060304A8
    add #0x4, r4
.L_060304A8:
    bra     .L_060304D2
    mov.l r4, @(r0, r2)

    .global DAT_060304ac
DAT_060304ac:
    .2byte  0x00DE

    .global DAT_060304ae
DAT_060304ae:
    .2byte  0x006C
.L_060304B0:
    .2byte  0x00B8
    .2byte  0x0000
.L_060304B4:
    .4byte  sym_0607ED90
.L_060304B8:
    .4byte  sym_0607ED88
.L_060304BC:
    mov.w   DAT_060304f0, r3
    mov #0x38, r5
    mov.l @(r0, r3), r4
    add #-0x2, r4
    cmp/ge r5, r4
    bt      .L_060304CA
    mov r5, r4
.L_060304CA:
    mov.l r4, @(r0, r3)
    mov.l   .L_060304F4, r2
    mov #0x0, r7
    mov.l r7, @(r0, r2)
.L_060304D2:
    mov #0x40, r2
    tst r1, r2
    bt      .L_06030504
    mov.l   .L_060304F8, r3
    mov.l r5, @(r0, r3)
    mov.l   .L_060304FC, r3
    mov.l @(r0, r3), r4
    mov.l   .L_06030500, r6
    mov.w   .L_060304F2, r8
    mov.l r4, @(r0, r6)
    cmp/gt r8, r4
    bt      .L_060304EC
    add #0x5, r4
.L_060304EC:
    bra     .L_0603051E
    mov.l r4, @(r0, r3)

    .global DAT_060304f0
DAT_060304f0:
    .2byte  0x0074
.L_060304F2:
    .2byte  0x00B8
.L_060304F4:
    .4byte  0x0000006C
.L_060304F8:
    .4byte  0x00000088
.L_060304FC:
    .4byte  0x00000090
.L_06030500:
    .4byte  0x0000008C
.L_06030504:
    mov.l   .L_06030530, r3
    mov.l @(r0, r3), r4
    mov.l   .L_06030534, r6
    mov.l r4, @(r0, r6)
    mov #0x38, r3
    add #-0x5, r4
    cmp/ge r3, r4
    bt      .L_06030516
    mov r3, r4
.L_06030516:
    mov.l   .L_06030530, r3
    mov.l r4, @(r0, r3)
    mov.l   .L_06030538, r3
    mov.l r7, @(r0, r3)
.L_0603051E:
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
.L_06030530:
    .4byte  0x00000090
.L_06030534:
    .4byte  0x0000008C
.L_06030538:
    .4byte  0x00000088

    .global sym_0603053C
sym_0603053C:
    mov.l r12, @-r15
    mov.l r13, @-r15
