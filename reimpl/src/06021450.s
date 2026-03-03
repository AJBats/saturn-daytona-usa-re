
    .section .text.FUN_06021450


    .global track_obj_placement
    .type track_obj_placement, @function
track_obj_placement:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x14, r15
    mov.w   DAT_06021520, r8
    mov.w   DAT_06021522, r9
    mov.w   .L_06021524, r10
    mov.l   .L_0602152C, r11
    mov.l   .L_06021530, r12
    mov.l   .L_06021534, r13
    mov.l   .L_06021538, r14
    mov.l   .L_0602153C, r7
    mov.l   .L_06021540, r5
    mov.l   .L_06021544, r0
    mov r10, r6
    mov.l @r0, r0
    add #0x28, r6
    tst r0, r0
    bf/s    .L_0602156A
    mov #0x0, r4
    mov.l   .L_06021548, r3
    mov.l r3, @r15
    mov.l   .L_0602154C, r2
    add r2, r3
    mov.l r3, @r5
    mov #0xC, r3
    mov.l r3, @(28, r5)
    mov.l @r15, r2
    mov.l   .L_06021550, r3
    add r3, r2
    mov.l r2, @(56, r5)
    mov r5, r3
    add #0x54, r3
    mov #0x9, r2
    mov.l r2, @r3
    mov r5, r3
    add #0x70, r3
    mov.l   .L_06021554, r2
    mov.l r2, @r3
    mov #0xA, r3
    mov.w   DAT_06021526, r0
    mov.l r3, @(r0, r5)
    mov.l r4, @(8, r15)
    mov.l   .L_06021558, r3
    add r4, r3
    mov.l r3, @(12, r15)
    mov r11, r2
    add r4, r2
    mov.l r2, @r15
    mov.w   .L_06021528, r1
    add r11, r1
    mov.l r1, @(16, r15)
.L_060214C2:
    exts.w r4, r0
    mov.l @r15, r5
    mov.l @(12, r15), r3
    mov.l r3, @(4, r15)
    mov.l @r3, r2
    mov.l r2, @r5
    mov.l @(4, r15), r3
    mov.l @(4, r3), r2
    mov.l r2, @(4, r5)
    mov.l @(4, r15), r3
    mov.l @(8, r3), r3
    neg r3, r3
    mov.l r3, @(8, r5)
    mov.l r4, @(12, r5)
    mov.l r4, @(16, r5)
    mov.w r0, @(20, r5)
    mov.l @(4, r15), r1
    mov.l   .L_0602155C, r3
    mov.l @(12, r1), r1
    exts.w r1, r1
    jsr @r3
    mov r6, r0
    exts.w r0, r0
    mov.w r0, @(22, r5)
    mov.l @(8, r15), r5
    mov r5, r3
    add r12, r3
    mov r5, r2
    add r7, r2
    mov.l r4, @r2
    mov.l r4, @r3
    mov r5, r3
    add r13, r3
    mov.l r4, @r3
    add r14, r5
    mov.l r4, @r5
    mov.l @(8, r15), r2
    add #0x4, r2
    mov.l r2, @(8, r15)
    mov.l @(12, r15), r3
    add #0x10, r3
    mov.l r3, @(12, r15)
    mov.l @r15, r1
    add #0x18, r1
    mov.l r1, @r15
    bra     .L_06021560
    nop

    .global DAT_06021520
DAT_06021520:
    .2byte  0x0E39

    .global DAT_06021522
DAT_06021522:
    .2byte  0x0800
.L_06021524:
    .2byte  0x0140

    .global DAT_06021526
DAT_06021526:
    .2byte  0x008C
.L_06021528:
    .2byte  0x00F0
    .2byte  0xFFFF
.L_0602152C:
    .4byte  sym_060897D0
.L_06021530:
    .4byte  sym_0608962C
.L_06021534:
    .4byte  sym_06089744
.L_06021538:
    .4byte  sym_060895A0
.L_0602153C:
    .4byte  sym_060896B8
.L_06021540:
    .4byte  sym_06089D98
.L_06021544:
    .4byte  sym_0607EAD8
.L_06021548:
    .4byte  0x00200000
.L_0602154C:
    .4byte  0x00037F08
.L_06021550:
    .4byte  0x00037F98
.L_06021554:
    .4byte  0x00010000
.L_06021558:
    .4byte  sym_060507A4
.L_0602155C:
    .4byte  sym_06034FE0
.L_06021560:
    mov.l @(16, r15), r3
    cmp/hs r3, r1
    bf      .L_060214C2
    bra     .L_06021B8C
    nop
.L_0602156A:
    mov.l   .L_06021670, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bt      .L_06021576
    bra     .L_060217D4
    nop
.L_06021576:
    mov.l   .L_06021674, r3
    mov.l r3, @r15
    mov.l   .L_06021678, r2
    add r2, r3
    mov.l r3, @(4, r5)
    mov #0x12, r3
    mov.l r3, @(32, r5)
    mov.l @r15, r2
    mov.l   .L_0602167C, r3
    add r3, r2
    mov.l r2, @(60, r5)
    mov r5, r3
    add #0x58, r3
    mov #0xB, r2
    mov.l r2, @r3
    mov r5, r3
    add #0x74, r3
    mov.l   .L_06021680, r2
    mov.l r2, @r3
    mov.l @r15, r3
    mov.l   .L_06021684, r2
    add r2, r3
    mov.l r3, @(8, r5)
    mov #0x1C, r3
    mov.l r3, @(36, r5)
    mov r5, r2
    add #0x40, r2
    mov.l @r15, r3
    mov.l   .L_06021688, r1
    add r1, r3
    mov.l r3, @r2
    mov r5, r3
    add #0x5C, r3
    mov #0xA, r2
    mov.l r2, @r3
    mov r5, r3
    add #0x78, r3
    mov.l   .L_0602168C, r2
    mov.l r2, @r3
    mov.l @r15, r3
    mov.l   .L_06021690, r2
    add r2, r3
    mov.l r3, @(12, r5)
    mov #0x34, r3
    mov.l r3, @(40, r5)
    mov r5, r2
    add #0x44, r2
    mov.l @r15, r3
    mov.l   .L_06021694, r1
    add r1, r3
    mov.l r3, @r2
    mov r5, r3
    add #0x60, r3
    mov #0x1C, r2
    mov.l r2, @r3
    mov r5, r3
    add #0x7C, r3
    mov.l   .L_06021698, r2
    mov.l r2, @r3
    mov #0xF, r3
    mov r3, r0
    add #0x7D, r0
    mov.l r3, @(r0, r5)
    mov r4, r5
.L_060215F6:
    exts.w r5, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    exts.b r5, r2
    add r11, r3
    mov r2, r1
    mov.l r3, @r15
    shll2 r2
    shll2 r1
    shll r1
    add r1, r2
    exts.b r2, r2
    mov.l   .L_0602169C, r0
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r2, r1
    mov.l r1, @r3
    mov.l @r15, r3
    mov.l @(4, r15), r2
    mov.l @(4, r2), r1
    mov.l r1, @(4, r3)
    mov.l @r15, r3
    mov.l @(4, r15), r2
    mov.l @(8, r2), r2
    neg r2, r2
    mov.l r2, @(8, r3)
    mov.l @r15, r3
    exts.w r4, r0
    mov.l r4, @(12, r3)
    mov.l @r15, r3
    mov.l r4, @(16, r3)
    mov.l @r15, r3
    mov.w r0, @(20, r3)
    exts.w r4, r0
    mov.l @r15, r3
    mov.w r0, @(22, r3)
    mov r5, r0
    shll2 r0
    add #0x1, r5
    mov r0, r3
    mov.l r0, @r15
    add r12, r3
    mov.l r4, @(r0, r7)
    mov.l r4, @r3
    mov.l @r15, r2
    add r13, r2
    mov.l r4, @r2
    mov #0x1, r2
    mov.l @r15, r3
    add r14, r3
    mov.l r2, @r3
    mov #0x4, r3
    cmp/hs r3, r5
    bf      .L_060215F6
    bra     .L_060216A0
    mov.l r4, @(8, r15)
.L_06021670:
    .4byte  sym_0607EAD8
.L_06021674:
    .4byte  0x00200000
.L_06021678:
    .4byte  0x00089364
.L_0602167C:
    .4byte  0x0008943C
.L_06021680:
    .4byte  0x00010000
.L_06021684:
    .4byte  0x00089124
.L_06021688:
    .4byte  0x00089274
.L_0602168C:
    .4byte  0x0000CCCC
.L_06021690:
    .4byte  0x00089544
.L_06021694:
    .4byte  0x000897B4
.L_06021698:
    .4byte  0x0000F333
.L_0602169C:
    .4byte  sym_06050844
.L_060216A0:
    mov #0xC, r3
    cmp/hs r3, r5
    bt/s    .L_06021738
    nop
    exts.w r5, r3
    mov r3, r2
    shll2 r3
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r11, r3
    mov.l r3, @r15
    mov.l @(8, r15), r2
    extu.b r2, r2
    mov r2, r1
    shll2 r2
    shll2 r1
    shll2 r1
    add r1, r2
    extu.b r2, r2
    mov.l   .L_060217A8, r0
    add r0, r2
    mov.l r2, @(4, r15)
    .2byte  0x6122
    .4byte  0x231263F2
    .4byte  0x52F15121
    .4byte  0x131163F2
    .4byte  0x52F15222
    .4byte  0x622B1322
    .4byte  0x63F21343
    .4byte  0x63F21344
    .4byte  0x63F251F1
    .4byte  0xD22D5113
    .4byte  0x420B6063
    .4byte  0x600F813A
    .4byte  0x63F251F1
    .4byte  0xD2295114
    .4byte  0x420B6063
    .4byte  0x813B6053
    .4byte  0x40087501
    .4byte  0x63032F02
    .4byte  0x33CC0746
    .4byte  0x234262F2
    .4byte  0x32DC2242
    .4byte  0xE20263F2
    .4byte  0x33EC2322
    .4byte  0xE20C53F2
    .4byte  0x73013522
    .4byte  0x8FB81F32
.L_06021738:
    mov #0xF, r3
    cmp/hs r3, r5
    bf/s    .L_06021744
    mov.l r4, @(8, r15)
    bra     .L_06021B8C
    nop
.L_06021744:
    exts.w r5, r3
    .2byte  0x6233
    .4byte  0x43084300
    .4byte  0x42084208
    .4byte  0x332C633F
    .4byte  0x33BC2F32
    .4byte  0x52F24208
    .4byte  0x4208D114
    .4byte  0x321C1F21
    .4byte  0x61222312
    .4byte  0x63F252F1
    .4byte  0x51211311
    .4byte  0x63F252F1
    .4byte  0x5222622B
    .4byte  0x132263F2
    .4byte  0x134363F2
    .4byte  0x1344604F
    .4byte  0x63F2813A
    .4byte  0x63F251F1
    .4byte  0xD2075113
    .4byte  0x420B6063
    .4byte  0x813B6053
    .4byte  0x40082F02
    .4byte  0x630333CC
    .4byte  0x07462342
    .4byte  0xA0060009
.L_060217A8:
    .4byte  sym_06050874
    .4byte  sym_06034FE0
    .4byte  sym_06050914
    .4byte  0x62F27501
    .4byte  0x32DC2242
    .4byte  0x63F2E203
    .4byte  0x33EC2322
    .4byte  0x53F2E20F
    .4byte  0x73013522
    .4byte  0x8FBA1F32
    .4byte  0xA1DC0009
.L_060217D4:
    mov.l   .L_060218E4, r2
    mov.l r2, @r15
    mov r2, r3
    mov.l   .L_060218E8, r2
    add r2, r3
    mov.l r3, @r5
    mov #0xC, r3
    mov.l r3, @(28, r5)
    mov.l @r15, r2
    mov.l   .L_060218EC, r3
    add r3, r2
    mov.l r2, @(56, r5)
    mov r5, r3
    add #0x54, r3
    mov #0x9, r2
    mov.l r2, @r3
    mov r5, r3
    add #0x70, r3
    mov.l   .L_060218F0, r2
    mov.l r2, @r3
    mov.l @r15, r3
    mov.l   .L_060218F4, r2
    add r2, r3
    .2byte  0x1532
    .4byte  0xE31C1539
    .4byte  0x62537240
    .4byte  0x63F2D13A
    .4byte  0x331C2232
    .4byte  0x6353735C
    .4byte  0xE20A2322
    .4byte  0x63537378
    .4byte  0xD2362322
    .4byte  0x63F2D236
    .4byte  0x332C1534
    .4byte  0xE320153B
    .4byte  0x62537248
    .4byte  0x63F2D133
    .4byte  0x331C2232
    .4byte  0x63537364
    .4byte  0xE20E2322
    .4byte  0xD330904A
    .4byte  0x053663F2
    .4byte  0xD22F332C
    .4byte  0x1535E30E
    .4byte  0x153C6253
    .4byte  0x724C63F2
    .4byte  0xD12C331C
    .4byte  0x22326353
    .4byte  0x7368E20A
    .4byte  0x2322D324
    .4byte  0x90380536
    .4byte  0x63F2D228
    .4byte  0x332C1536
    .4byte  0xE30E153D
    .4byte  0x62537250
    .4byte  0x63F2D125
    .4byte  0x331C2232
    .4byte  0x6353736C
    .4byte  0xE20A2322
    .4byte  0xD31A9026
    .4byte  0x0536E323
    .4byte  0x70040536
    .4byte  0x6543635F
    .4byte  0x62334308
    .4byte  0x42084300
    .4byte  0x4208332C
    .4byte  0x633F625E
    .4byte  0x33BC6123
    .4byte  0x2F324208
    .4byte  0x41084100
    .4byte  0x321C622E
    .4byte  0xD016320C
    .4byte  0x1F216122
    .4byte  0x231263F2
    .4byte  0x52F15121
    .4byte  0x131163F2
    .4byte  0x52F15222
    .4byte  0x622BA021
    .2byte  0x0009

    .global DAT_060218de
DAT_060218de:
    .2byte  0x0080

    .global DAT_060218e0
DAT_060218e0:
    .4byte  0x00840088
.L_060218E4:
    .4byte  0x00200000
.L_060218E8:
    .4byte  0x000BE1F8
.L_060218EC:
    .4byte  0x000BE288
.L_060218F0:
    .4byte  0x00010000
.L_060218F4:
    .4byte  0x000BE360
    .4byte  0x000BE4B0
    .4byte  0x0000CCCC
    .4byte  0x000BDBF8
    .4byte  0x000BDD78
    .4byte  0x0000F333
    .4byte  0x000BDEC8
    .4byte  0x000BDF70
    .4byte  0x000BE060
    .4byte  0x000BE108
    .4byte  sym_06050AE4
    .4byte  0x1322604F
    .4byte  0x63F21343
    .4byte  0x63F21344
    .4byte  0x63F2813A
    .4byte  0x63F2604F
    .4byte  0x813B6053
    .4byte  0x40087501
    .4byte  0x2F026303
    .4byte  0x074633CC
    .4byte  0x234262F2
    .4byte  0x32DC2242
    .4byte  0x63F233EC
    .4byte  0x2342E309
    .4byte  0x35328BA2
    .4byte  0xE3153532
    .4byte  0x8D3E1F42
    .4byte  0x635F6233
    .4byte  0x43084300
    .4byte  0x42084208
    .4byte  0x332C633F
    .4byte  0x33BC2F32
    .4byte  0x52F24208
    .4byte  0x4208D129
    .4byte  0x321C1F21
    .4byte  0x61222312
    .4byte  0x63F252F1
    .4byte  0x51211311
    .4byte  0x63F252F1
    .4byte  0x5222622B
    .4byte  0x132263F2
    .4byte  0x134363F2
    .4byte  0x134463F2
    .4byte  0x604F813A
    .4byte  0x63F251F1
    .4byte  0xD21E5113
    .4byte  0x420B6063
    .4byte  0x813B6053
    .4byte  0x40087501
    .4byte  0x63032F02
    .4byte  0x33CC0746
    .4byte  0x234262F2
    .4byte  0x32DC2242
    .4byte  0xE20263F2
    .4byte  0x33EC2322
    .4byte  0xE21553F2
    .4byte  0x73013522
    .4byte  0x8FC21F32
    .4byte  0xE3183532
    .4byte  0x8D471F42
    .4byte  0x635F6233
    .4byte  0x43084300
    .4byte  0x42084208
    .4byte  0x332C633F
    .4byte  0x33BC2F32
    .4byte  0x52F24208
    .4byte  0x4208D10A
    .4byte  0x321C1F21
    .4byte  0x61222312
    .4byte  0x63F252F1
    .4byte  0x51211311
    .4byte  0x63F252F1
    .4byte  0x5222622B
    .4byte  0x1322A007
    .4byte  0x0009FFFF
    .4byte  sym_06050974
    .4byte  sym_06034FE0
    .4byte  sym_06050944
    .4byte  0x63F2604F
    .4byte  0x134363F2
    .4byte  0x134463F2
    .4byte  0x813A63F2
    .4byte  0x51F1D23A
    .4byte  0x5113420B
    .4byte  0x6063813B
    .4byte  0x60534008
    .4byte  0x75016303
    .4byte  0x2F0233CC
    .4byte  0x07462342
    .4byte  0x62F232DC
    .4byte  0x2242E204
    .4byte  0x63F233EC
    .4byte  0x2322E218
    .4byte  0x53F27301
    .4byte  0x35228FB9
    .4byte  0x1F32E31D
    .4byte  0x35328D3E
    .4byte  0x1F42635F
    .4byte  0x62334308
    .4byte  0x43004208
    .4byte  0x4208332C
    .4byte  0x633F33BC
    .4byte  0x2F3252F2
    .4byte  0x42084208
    .4byte  0xD125321C
    .4byte  0x1F216122
    .4byte  0x231263F2
    .4byte  0x52F15121
    .4byte  0x131163F2
    .4byte  0x52F15222
    .4byte  0x622B1322
    .4byte  0x63F21343
    .4byte  0x63F21344
    .4byte  0x604F63F2
    .4byte  0x813A63F2
    .4byte  0x51F1D219
    .4byte  0x5113420B
    .4byte  0x6063813B
    .4byte  0x60534008
    .4byte  0x75012F02
    .4byte  0x63030746
    .4byte  0x33CC2342
    .4byte  0x62F232DC
    .4byte  0x224263F2
    .4byte  0xE20533EC
    .4byte  0x232253F2
    .4byte  0xE21D7301
    .4byte  0x35228FC2
    .4byte  0x1F32E323
    .4byte  0x35328D47
    .4byte  0x1F42635F
    .4byte  0x62334308
    .4byte  0x43004208
    .4byte  0x4208332C
    .4byte  0x633F33BC
    .4byte  0x2F3252F2
    .4byte  0x42084208
    .4byte  0xD105321C
    .4byte  0x1F216122
    .4byte  0x2312A007
    .4byte  0x0009FFFF
    .4byte  sym_06034FE0
    .4byte  sym_06050A34
    .4byte  sym_06050A84
    .4byte  0x63F2604F
    .4byte  0x52F15121
    .4byte  0x131163F2
    .4byte  0x52F15222
    .4byte  0x622B1322
    .4byte  0x63F21343
    .4byte  0x63F21344
    .4byte  0x63F2813A
    .4byte  0x63F251F1
    .4byte  0xD2365113
    .4byte  0x420B6063
    .4byte  0x813B6053
    .4byte  0x40087501
    .4byte  0x2F026303
    .4byte  0x074633CC
    .4byte  0x234262F2
    .4byte  0x32DC2242
    .4byte  0x63F2E206
    .4byte  0x33EC2322
    .4byte  0x53F2E223
    .4byte  0x73013522
    .4byte  0x8FB91F32
.L_06021B8C:
    mov.l   .L_06021C38, r3
    mov.l r3, @r15
    mov.l r4, @r3
    mov.l @r15, r3
    mov.w   DAT_06021c2e, r0
    mov.w r0, @(4, r3)
    mov.l @r15, r3
    mov.w   .L_06021C30, r0
    mov.w r0, @(6, r3)
    mov.l @r15, r3
    add #0x8, r3
    mov.l r3, @(4, r15)
    mov.l r4, @r3
    mov.l @(4, r15), r3
    exts.w r4, r0
    mov.w r0, @(4, r3)
    mov.w   DAT_06021c32, r5
    mov.l @(4, r15), r3
    exts.w r5, r0
    mov.w r0, @(6, r3)
    mov.l @r15, r3
    add #0x10, r3
    mov.l r3, @(4, r15)
    mov.l r4, @r3
    mov.l @(4, r15), r3
    exts.w r4, r0
    mov.w r0, @(4, r3)
    mov.l @(4, r15), r3
    exts.w r5, r0
    mov.w r0, @(6, r3)
    mov.l @r15, r3
    add #0x18, r3
    mov.l r3, @(4, r15)
    mov.l r4, @r3
    mov.l @(4, r15), r3
    exts.w r4, r2
    mov r2, r0
    mov.w r0, @(4, r3)
    mov.l @(4, r15), r3
    exts.w r5, r0
    mov.w r0, @(6, r3)
    mov #0x4, r5
    mov.l   .L_06021C38, r3
    mov.l r3, @r15
    mov r5, r3
    mov r5, r0
    mov.l @r15, r2
    shll2 r3
    add #-0x4, r0
    shll r3
    add r2, r3
    mov.l r3, @(4, r15)
    add #-0x20, r15
    mov.l   .L_06021C3C, r2
    jsr @r2
    mov.l r15, @-r15
    mov.l   .L_06021C40, r1
    mov.l r1, @-r15
    mov.l   .L_06021C44, r1
    mov.l r1, @-r15
    mov r15, r2
    mov.l   .L_06021C48, r1
    add #0x10, r2
    jsr @r1
    mov.l r2, @-r15
    mov r5, r0
    add #-0x18, r15
    add #-0x4, r0
    mov.l   .L_06021C3C, r2
    jsr @r2
    mov.l r15, @-r15
    mov r5, r0
    add #-0x8, r15
    add #-0x4, r0
    mov.l   .L_06021C3C, r2
    jsr @r2
    mov.l r15, @-r15
    mov r15, r1
    add #0x10, r1
    bra     .L_06021C4C
    mov.l r1, @-r15

    .global DAT_06021c2e
DAT_06021c2e:
    .2byte  0xF6B0
.L_06021C30:
    .2byte  0x4000

    .global DAT_06021c32
DAT_06021c32:
    .2byte  0x8000
    .4byte  sym_06034FE0
.L_06021C38:
    .4byte  sym_06089B18
.L_06021C3C:
    .4byte  sym_06035BC8
.L_06021C40:
    .4byte  0x33333333
.L_06021C44:
    .4byte  0x4054D333
.L_06021C48:
    .4byte  sym_060359E4
.L_06021C4C:
    mov.l   .L_06021D7C, r2
    jsr @r2
    nop
    mov.l   .L_06021D80, r1
    mov.l r1, @-r15
    mov.l   .L_06021D84, r1
    mov.l r1, @-r15
    mov r15, r2
    mov.l   .L_06021D7C, r1
    add #0x10, r2
    jsr @r1
    mov.l r2, @-r15
    mov r15, r2
    mov.l   .L_06021D88, r1
    add #0x10, r2
    jsr @r1
    mov.l r2, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_06021D8C, r2
    mov.l r2, @-r15
    mov r15, r1
    mov.l   .L_06021D7C, r2
    add #0x10, r1
    jsr @r2
    mov.l r1, @-r15
    mov.l   .L_06021D90, r1
    jsr @r1
    nop
    add #0x1, r5
    mov.l r0, @r3
    exts.w r8, r0
    mov.l @(4, r15), r3
    mov.w r0, @(4, r3)
    mov.l @(4, r15), r3
    exts.w r9, r0
    mov.w r0, @(6, r3)
    mov r5, r3
    mov.l @r15, r2
    mov r5, r0
    shll2 r3
    add #-0x4, r0
    shll r3
    add r2, r3
    mov.l r3, @(4, r15)
    add #-0x20, r15
    mov.l   .L_06021D94, r2
    jsr @r2
    mov.l r15, @-r15
    mov.l   .L_06021D98, r1
    mov.l r1, @-r15
    mov.l   .L_06021D9C, r1
    mov.l r1, @-r15
    mov r15, r2
    mov.l   .L_06021D7C, r1
    add #0x10, r2
    jsr @r1
    mov.l r2, @-r15
    mov r5, r0
    add #-0x18, r15
    add #-0x4, r0
    mov.l   .L_06021D94, r2
    jsr @r2
    mov.l r15, @-r15
    mov r5, r0
    add #-0x8, r15
    add #-0x4, r0
    mov.l   .L_06021D94, r2
    jsr @r2
    mov.l r15, @-r15
    mov r15, r1
    mov.l   .L_06021D7C, r2
    add #0x10, r1
    jsr @r2
    mov.l r1, @-r15
    mov.l   .L_06021D80, r1
    .4byte  0x2F16D127
    .4byte  0x2F1662F3
    .4byte  0xD1237210
    .4byte  0x410B2F26
    .4byte  0x62F3D124
    .4byte  0x7210410B
    .4byte  0x2F26E200
    .4byte  0x2F26D222
    .4byte  0x2F2661F3
    .4byte  0xD21C7110
    .4byte  0x420B2F16
    .4byte  0xD11F410B
    .4byte  0x00097501
    .4byte  0x2302608F
    .4byte  0x53F18132
    .4byte  0x53F1609F
    .4byte  0x81336353
    .4byte  0x62F26053
    .4byte  0x430870FC
    .4byte  0x4300332C
    .4byte  0x1F317FE0
    .4byte  0xD216420B
    .4byte  0x2FF6D116
    .4byte  0x2F16D116
    .4byte  0x2F1662F3
    .4byte  0xD10C7210
    .4byte  0x410B2F26
    .4byte  0x60537FE8
    .4byte  0x70FCD20F
    .4byte  0x420B2FF6
    .4byte  0x60537FF8
    .4byte  0x70FCD20C
    .4byte  0x420B2FF6
    .4byte  0x61F3D204
    .4byte  0x7110420B
    .4byte  0x2F16D103
    .4byte  0x2F16A013
    .4byte  0x0009FFFF
.L_06021D7C:
    .4byte  sym_060359E4
.L_06021D80:
    .4byte  0x9999999A
.L_06021D84:
    .4byte  0x40139999
.L_06021D88:
    .4byte  sym_06035460
.L_06021D8C:
    .4byte  0x40680000
.L_06021D90:
    .4byte  sym_060357B8
.L_06021D94:
    .4byte  sym_06035BC8
.L_06021D98:
    .4byte  0x33333333
.L_06021D9C:
    .4byte  0x4054D333
    .4byte  0xD13E2F16
    .4byte  0x62F3D13E
    .4byte  0x7210410B
    .4byte  0x2F2662F3
    .4byte  0xD13C7210
    .4byte  0x410B2F26
    .4byte  0xE2002F26
    .4byte  0xD23A2F26
    .4byte  0x61F3D237
    .4byte  0x7110420B
    .4byte  0x2F16D138
    .4byte  0x410B0009
    .4byte  0x23027501
    .4byte  0x53F1608F
    .4byte  0x8132609F
    .4byte  0x53F18133
    .4byte  0xE3163532
    .4byte  0x8901AEFD
    .4byte  0x00096353
    .4byte  0x73EA2F32
    .4byte  0x1F3262F2
    .4byte  0x1F21D22E
    .4byte  0x1F24E228
    .4byte  0x3522896C
    .4byte  0x635352F4
    .4byte  0x43084300
    .4byte  0x332C1F33
    .4byte  0x7FE850F6
    .4byte  0x7FF8D228
    .4byte  0x420B2FF6
    .4byte  0xD2272F26
    .4byte  0xD2272F26
    .4byte  0x61F3D21F
    .4byte  0x7110420B
    .4byte  0x2F167FF0
    .4byte  0x50FB7FF8
    .4byte  0xD120410B
    .4byte  0x2FF650FE
    .4byte  0x7FF8D21E
    .4byte  0x420B2FF6
    .4byte  0x62F3D117
    .4byte  0x7210410B
    .4byte  0x2F26D21D
    .4byte  0x2F26D213
    .4byte  0x2F2661F3
    .4byte  0xD2127110
    .4byte  0x420B2F16
    .4byte  0x61F3D211
    .4byte  0x7110420B
    .4byte  0x2F16E100
    .4byte  0x2F16D116
    .4byte  0x2F1662F3
    .4byte  0xD10B7210
    .4byte  0x410B2F26
    .4byte  0xD20C420B
    .4byte  0x00092302
    .4byte  0x53F39009
    .4byte  0x813253F3
    .4byte  0x90078133
    .4byte  0x750153F2
    .4byte  0x73011F32
    .4byte  0xA0180009

    .global DAT_06021e98
DAT_06021e98:
    .2byte  0x0AA9

    .global DAT_06021e9a
DAT_06021e9a:
    .2byte  0x0400
    .4byte  0x40139999
    .4byte  sym_060359E4
    .4byte  sym_06035460
    .4byte  0x40680000
    .4byte  sym_060357B8
    .4byte  sym_06089B18
    .4byte  sym_06035BC8
    .4byte  0x33333333
    .4byte  0x4054D333
    .4byte  0x9999999A
    .4byte  0x40580000
    .4byte  0x52F1E328
    .4byte  0x72011F21
    .4byte  0x61F27101
    .4byte  0x2F123532
    .4byte  0x8B926543
    .4byte  0xD3411F31
    .4byte  0x63536053
    .4byte  0x52F14308
    .4byte  0x4300332C
    .4byte  0x33AC2F32
    .4byte  0x7FE0D23D
    .4byte  0x420B2FF6
    .4byte  0xD13C2F16
    .4byte  0xD13C2F16
    .4byte  0x62F3D13C
    .4byte  0x7210410B
    .4byte  0x2F266053
    .4byte  0x7FE8D236
    .4byte  0x420B2FF6
    .4byte  0x60537FF8
    .4byte  0xD133410B
    .4byte  0x2FF662F3
    .4byte  0xD1347210
    .4byte  0x410B2F26
    .4byte  0xD2302F26
    .4byte  0xD2322F26
    .4byte  0x61F3D230
    .4byte  0x7110420B
    .4byte  0x2F1661F3
    .4byte  0xD22F7110
    .4byte  0x420B2F16
    .4byte  0xE1002F16
    .4byte  0xD12D2F16
    .4byte  0x62F3D129
    .4byte  0x7210410B
    .4byte  0x2F26D22B
    .4byte  0x420B0009
    .4byte  0x23027501
    .4byte  0x63F2903D
    .4byte  0x8132604F
    .4byte  0x63F28133
    .4byte  0x63536053
    .4byte  0x52F14308
    .4byte  0x4300332C
    .4byte  0x33AC2F32
    .4byte  0x7FE0D21A
    .4byte  0x420B2FF6
    .4byte  0xD1192F16
    .4byte  0xD1192F16
    .4byte  0x62F3D119
    .4byte  0x7210410B
    .4byte  0x2F266053
    .4byte  0x7FE8D213
    .4byte  0x420B2FF6
    .4byte  0x60537FF8
    .4byte  0xD110410B
    .4byte  0x2FF662F3
    .4byte  0xD1117210
    .4byte  0x410B2F26
    .4byte  0xD20D2F26
    .4byte  0xD20F2F26
    .4byte  0x61F3D20D
    .4byte  0x7110420B
    .4byte  0x2F1661F3
    .4byte  0xD20C7110
    .4byte  0x420B2F16
    .4byte  0xE1002F16
    .4byte  0xD10A2F16
    .4byte  0x62F37210
    .4byte  0xA0142F26

    .global DAT_06021fe0
DAT_06021fe0:
    .4byte  0xEDB7FFFF
    .4byte  sym_06089B18
    .4byte  sym_06035BC8
    .4byte  0x9999999A
    .4byte  0x404FD999
    .4byte  sym_060359E4
    .4byte  0x40139999
    .4byte  sym_06035460
    .4byte  0x40700000
    .4byte  sym_060357B8
    .4byte  0xD144410B
    .4byte  0x0009D244
    .4byte  0x420B0009
    .4byte  0x23027501
    .4byte  0x63F2907B
    .4byte  0x8132604F
    .4byte  0x63F28133
    .4byte  0xE30E3532
    .4byte  0x8901AF59
    .4byte  0x0009D33D
    .4byte  0x1F31E31C
    .4byte  0x3532894B
    .4byte  0x63536053
    .4byte  0x52F14308
    .4byte  0x70F24300
    .4byte  0x332C33AC
    .4byte  0x2F327FE0
    .4byte  0xD236420B
    .4byte  0x2FF6D136
    .4byte  0x2F16D136
    .4byte  0x2F1662F3
    .4byte  0xD12F7210
    .4byte  0x410B2F26
    .4byte  0x60537FE8
    .4byte  0x70F2D22F
    .4byte  0x420B2FF6
    .4byte  0x60537FF8
    .4byte  0x70F2D22C
    .4byte  0x420B2FF6
    .4byte  0x61F3D227
    .4byte  0x7110420B
    .4byte  0x2F16D129
    .4byte  0x2F16D12A
    .4byte  0x2F1662F3
    .4byte  0xD1227210
    .4byte  0x410B2F26
    .4byte  0x62F3D127
    .4byte  0x7210410B
    .4byte  0x2F26E200
    .4byte  0x2F26D225
    .4byte  0x2F2661F3
    .4byte  0xD21B7110
    .4byte  0x420B2F16
    .4byte  0xD11A410B
    .4byte  0x00097501
    .4byte  0x2302604F
    .4byte  0x63F28132
    .4byte  0x63F2604F
    .4byte  0x8133E31C
    .4byte  0x35328BB3
    .4byte  0x4508D314
    .4byte  0x45002F32
    .4byte  0x353C921C
    .4byte  0x35AC332C
    .4byte  0x35328D0D
    .4byte  0x1F31624F
    .4byte  0x2F522542
    .4byte  0x63F27508
    .4byte  0x90128132
    .4byte  0x63F26023
    .4byte  0x813353F1
    .4byte  0x35328BF2
    .4byte  0x7F144F26
    .4byte  0x68F669F6
    .4byte  0x6AF66BF6
    .4byte  0x6CF66DF6
    .4byte  0x000B6EF6

    .global DAT_06022114
DAT_06022114:
    .2byte  0xEDB7

    .global DAT_06022116
DAT_06022116:
    .2byte  0x0280

    .global DAT_06022118
DAT_06022118:
    .4byte  0xFA13FFFF
    .4byte  sym_060359E4
    .4byte  sym_060357B8
    .4byte  sym_06089B18
    .4byte  sym_06035BC8
    .4byte  0x9999999A
    .4byte  0x404FD999
    .4byte  0x40139999
    .4byte  sym_06035460
    .4byte  0x40600000
