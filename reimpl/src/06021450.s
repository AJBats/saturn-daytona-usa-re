	.text
    .global track_obj_placement
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
    bf.s    .L_0602156A
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
    .short  0x0E39

    .global DAT_06021522
DAT_06021522:
    .short  0x0800
.L_06021524:
    .short  0x0140

    .global DAT_06021526
DAT_06021526:
    .short  0x008C
.L_06021528:
    .short  0x00F0
    .short  0xFFFF
.L_0602152C:
    .long  sym_060897D0
.L_06021530:
    .long  sym_0608962C
.L_06021534:
    .long  sym_06089744
.L_06021538:
    .long  sym_060895A0
.L_0602153C:
    .long  sym_060896B8
.L_06021540:
    .long  sym_06089D98
.L_06021544:
    .long  sym_0607EAD8
.L_06021548:
    .long  0x00200000
.L_0602154C:
    .long  0x00037F08
.L_06021550:
    .long  0x00037F98
.L_06021554:
    .long  0x00010000
.L_06021558:
    .long  sym_060507A4
.L_0602155C:
    .long  sym_06034FE0
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
    .long  sym_0607EAD8
.L_06021674:
    .long  0x00200000
.L_06021678:
    .long  0x00089364
.L_0602167C:
    .long  0x0008943C
.L_06021680:
    .long  0x00010000
.L_06021684:
    .long  0x00089124
.L_06021688:
    .long  0x00089274
.L_0602168C:
    .long  0x0000CCCC
.L_06021690:
    .long  0x00089544
.L_06021694:
    .long  0x000897B4
.L_06021698:
    .long  0x0000F333
.L_0602169C:
    .long  sym_06050844
.L_060216A0:
    mov #0xC, r3
    cmp/hs r3, r5
    bt.s    .L_06021738
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
    .short  0x6122
    .long  0x231263F2
    .long  0x52F15121
    .long  0x131163F2
    .long  0x52F15222
    .long  0x622B1322
    .long  0x63F21343
    .long  0x63F21344
    .long  0x63F251F1
    .long  0xD22D5113
    .long  0x420B6063
    .long  0x600F813A
    .long  0x63F251F1
    .long  0xD2295114
    .long  0x420B6063
    .long  0x813B6053
    .long  0x40087501
    .long  0x63032F02
    .long  0x33CC0746
    .long  0x234262F2
    .long  0x32DC2242
    .long  0xE20263F2
    .long  0x33EC2322
    .long  0xE20C53F2
    .long  0x73013522
    .long  0x8FB81F32
.L_06021738:
    mov #0xF, r3
    cmp/hs r3, r5
    bf.s    .L_06021744
    mov.l r4, @(8, r15)
    bra     .L_06021B8C
    nop
.L_06021744:
    exts.w r5, r3
    .short  0x6233
    .long  0x43084300
    .long  0x42084208
    .long  0x332C633F
    .long  0x33BC2F32
    .long  0x52F24208
    .long  0x4208D114
    .long  0x321C1F21
    .long  0x61222312
    .long  0x63F252F1
    .long  0x51211311
    .long  0x63F252F1
    .long  0x5222622B
    .long  0x132263F2
    .long  0x134363F2
    .long  0x1344604F
    .long  0x63F2813A
    .long  0x63F251F1
    .long  0xD2075113
    .long  0x420B6063
    .long  0x813B6053
    .long  0x40082F02
    .long  0x630333CC
    .long  0x07462342
    .long  0xA0060009
.L_060217A8:
    .long  sym_06050874
    .long  sym_06034FE0
    .long  sym_06050914
    .long  0x62F27501
    .long  0x32DC2242
    .long  0x63F2E203
    .long  0x33EC2322
    .long  0x53F2E20F
    .long  0x73013522
    .long  0x8FBA1F32
    .long  0xA1DC0009
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
    .short  0x1532
    .long  0xE31C1539
    .long  0x62537240
    .long  0x63F2D13A
    .long  0x331C2232
    .long  0x6353735C
    .long  0xE20A2322
    .long  0x63537378
    .long  0xD2362322
    .long  0x63F2D236
    .long  0x332C1534
    .long  0xE320153B
    .long  0x62537248
    .long  0x63F2D133
    .long  0x331C2232
    .long  0x63537364
    .long  0xE20E2322
    .long  0xD330904A
    .long  0x053663F2
    .long  0xD22F332C
    .long  0x1535E30E
    .long  0x153C6253
    .long  0x724C63F2
    .long  0xD12C331C
    .long  0x22326353
    .long  0x7368E20A
    .long  0x2322D324
    .long  0x90380536
    .long  0x63F2D228
    .long  0x332C1536
    .long  0xE30E153D
    .long  0x62537250
    .long  0x63F2D125
    .long  0x331C2232
    .long  0x6353736C
    .long  0xE20A2322
    .long  0xD31A9026
    .long  0x0536E323
    .long  0x70040536
    .long  0x6543635F
    .long  0x62334308
    .long  0x42084300
    .long  0x4208332C
    .long  0x633F625E
    .long  0x33BC6123
    .long  0x2F324208
    .long  0x41084100
    .long  0x321C622E
    .long  0xD016320C
    .long  0x1F216122
    .long  0x231263F2
    .long  0x52F15121
    .long  0x131163F2
    .long  0x52F15222
    .long  0x622BA021
    .short  0x0009

    .global DAT_060218de
DAT_060218de:
    .short  0x0080

    .global DAT_060218e0
DAT_060218e0:
    .long  0x00840088
.L_060218E4:
    .long  0x00200000
.L_060218E8:
    .long  0x000BE1F8
.L_060218EC:
    .long  0x000BE288
.L_060218F0:
    .long  0x00010000
.L_060218F4:
    .long  0x000BE360
    .long  0x000BE4B0
    .long  0x0000CCCC
    .long  0x000BDBF8
    .long  0x000BDD78
    .long  0x0000F333
    .long  0x000BDEC8
    .long  0x000BDF70
    .long  0x000BE060
    .long  0x000BE108
    .long  sym_06050AE4
    .long  0x1322604F
    .long  0x63F21343
    .long  0x63F21344
    .long  0x63F2813A
    .long  0x63F2604F
    .long  0x813B6053
    .long  0x40087501
    .long  0x2F026303
    .long  0x074633CC
    .long  0x234262F2
    .long  0x32DC2242
    .long  0x63F233EC
    .long  0x2342E309
    .long  0x35328BA2
    .long  0xE3153532
    .long  0x8D3E1F42
    .long  0x635F6233
    .long  0x43084300
    .long  0x42084208
    .long  0x332C633F
    .long  0x33BC2F32
    .long  0x52F24208
    .long  0x4208D129
    .long  0x321C1F21
    .long  0x61222312
    .long  0x63F252F1
    .long  0x51211311
    .long  0x63F252F1
    .long  0x5222622B
    .long  0x132263F2
    .long  0x134363F2
    .long  0x134463F2
    .long  0x604F813A
    .long  0x63F251F1
    .long  0xD21E5113
    .long  0x420B6063
    .long  0x813B6053
    .long  0x40087501
    .long  0x63032F02
    .long  0x33CC0746
    .long  0x234262F2
    .long  0x32DC2242
    .long  0xE20263F2
    .long  0x33EC2322
    .long  0xE21553F2
    .long  0x73013522
    .long  0x8FC21F32
    .long  0xE3183532
    .long  0x8D471F42
    .long  0x635F6233
    .long  0x43084300
    .long  0x42084208
    .long  0x332C633F
    .long  0x33BC2F32
    .long  0x52F24208
    .long  0x4208D10A
    .long  0x321C1F21
    .long  0x61222312
    .long  0x63F252F1
    .long  0x51211311
    .long  0x63F252F1
    .long  0x5222622B
    .long  0x1322A007
    .long  0x0009FFFF
    .long  sym_06050974
    .long  sym_06034FE0
    .long  sym_06050944
    .long  0x63F2604F
    .long  0x134363F2
    .long  0x134463F2
    .long  0x813A63F2
    .long  0x51F1D23A
    .long  0x5113420B
    .long  0x6063813B
    .long  0x60534008
    .long  0x75016303
    .long  0x2F0233CC
    .long  0x07462342
    .long  0x62F232DC
    .long  0x2242E204
    .long  0x63F233EC
    .long  0x2322E218
    .long  0x53F27301
    .long  0x35228FB9
    .long  0x1F32E31D
    .long  0x35328D3E
    .long  0x1F42635F
    .long  0x62334308
    .long  0x43004208
    .long  0x4208332C
    .long  0x633F33BC
    .long  0x2F3252F2
    .long  0x42084208
    .long  0xD125321C
    .long  0x1F216122
    .long  0x231263F2
    .long  0x52F15121
    .long  0x131163F2
    .long  0x52F15222
    .long  0x622B1322
    .long  0x63F21343
    .long  0x63F21344
    .long  0x604F63F2
    .long  0x813A63F2
    .long  0x51F1D219
    .long  0x5113420B
    .long  0x6063813B
    .long  0x60534008
    .long  0x75012F02
    .long  0x63030746
    .long  0x33CC2342
    .long  0x62F232DC
    .long  0x224263F2
    .long  0xE20533EC
    .long  0x232253F2
    .long  0xE21D7301
    .long  0x35228FC2
    .long  0x1F32E323
    .long  0x35328D47
    .long  0x1F42635F
    .long  0x62334308
    .long  0x43004208
    .long  0x4208332C
    .long  0x633F33BC
    .long  0x2F3252F2
    .long  0x42084208
    .long  0xD105321C
    .long  0x1F216122
    .long  0x2312A007
    .long  0x0009FFFF
    .long  sym_06034FE0
    .long  sym_06050A34
    .long  sym_06050A84
    .long  0x63F2604F
    .long  0x52F15121
    .long  0x131163F2
    .long  0x52F15222
    .long  0x622B1322
    .long  0x63F21343
    .long  0x63F21344
    .long  0x63F2813A
    .long  0x63F251F1
    .long  0xD2365113
    .long  0x420B6063
    .long  0x813B6053
    .long  0x40087501
    .long  0x2F026303
    .long  0x074633CC
    .long  0x234262F2
    .long  0x32DC2242
    .long  0x63F2E206
    .long  0x33EC2322
    .long  0x53F2E223
    .long  0x73013522
    .long  0x8FB91F32
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
    .short  0xF6B0
.L_06021C30:
    .short  0x4000

    .global DAT_06021c32
DAT_06021c32:
    .short  0x8000
    .long  sym_06034FE0
.L_06021C38:
    .long  sym_06089B18
.L_06021C3C:
    .long  sym_06035BC8
.L_06021C40:
    .long  0x33333333
.L_06021C44:
    .long  0x4054D333
.L_06021C48:
    .long  sym_060359E4
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
    .long  0x2F16D127
    .long  0x2F1662F3
    .long  0xD1237210
    .long  0x410B2F26
    .long  0x62F3D124
    .long  0x7210410B
    .long  0x2F26E200
    .long  0x2F26D222
    .long  0x2F2661F3
    .long  0xD21C7110
    .long  0x420B2F16
    .long  0xD11F410B
    .long  0x00097501
    .long  0x2302608F
    .long  0x53F18132
    .long  0x53F1609F
    .long  0x81336353
    .long  0x62F26053
    .long  0x430870FC
    .long  0x4300332C
    .long  0x1F317FE0
    .long  0xD216420B
    .long  0x2FF6D116
    .long  0x2F16D116
    .long  0x2F1662F3
    .long  0xD10C7210
    .long  0x410B2F26
    .long  0x60537FE8
    .long  0x70FCD20F
    .long  0x420B2FF6
    .long  0x60537FF8
    .long  0x70FCD20C
    .long  0x420B2FF6
    .long  0x61F3D204
    .long  0x7110420B
    .long  0x2F16D103
    .long  0x2F16A013
    .long  0x0009FFFF
.L_06021D7C:
    .long  sym_060359E4
.L_06021D80:
    .long  0x9999999A
.L_06021D84:
    .long  0x40139999
.L_06021D88:
    .long  sym_06035460
.L_06021D8C:
    .long  0x40680000
.L_06021D90:
    .long  sym_060357B8
.L_06021D94:
    .long  sym_06035BC8
.L_06021D98:
    .long  0x33333333
.L_06021D9C:
    .long  0x4054D333
    .long  0xD13E2F16
    .long  0x62F3D13E
    .long  0x7210410B
    .long  0x2F2662F3
    .long  0xD13C7210
    .long  0x410B2F26
    .long  0xE2002F26
    .long  0xD23A2F26
    .long  0x61F3D237
    .long  0x7110420B
    .long  0x2F16D138
    .long  0x410B0009
    .long  0x23027501
    .long  0x53F1608F
    .long  0x8132609F
    .long  0x53F18133
    .long  0xE3163532
    .long  0x8901AEFD
    .long  0x00096353
    .long  0x73EA2F32
    .long  0x1F3262F2
    .long  0x1F21D22E
    .long  0x1F24E228
    .long  0x3522896C
    .long  0x635352F4
    .long  0x43084300
    .long  0x332C1F33
    .long  0x7FE850F6
    .long  0x7FF8D228
    .long  0x420B2FF6
    .long  0xD2272F26
    .long  0xD2272F26
    .long  0x61F3D21F
    .long  0x7110420B
    .long  0x2F167FF0
    .long  0x50FB7FF8
    .long  0xD120410B
    .long  0x2FF650FE
    .long  0x7FF8D21E
    .long  0x420B2FF6
    .long  0x62F3D117
    .long  0x7210410B
    .long  0x2F26D21D
    .long  0x2F26D213
    .long  0x2F2661F3
    .long  0xD2127110
    .long  0x420B2F16
    .long  0x61F3D211
    .long  0x7110420B
    .long  0x2F16E100
    .long  0x2F16D116
    .long  0x2F1662F3
    .long  0xD10B7210
    .long  0x410B2F26
    .long  0xD20C420B
    .long  0x00092302
    .long  0x53F39009
    .long  0x813253F3
    .long  0x90078133
    .long  0x750153F2
    .long  0x73011F32
    .long  0xA0180009

    .global DAT_06021e98
DAT_06021e98:
    .short  0x0AA9

    .global DAT_06021e9a
DAT_06021e9a:
    .short  0x0400
    .long  0x40139999
    .long  sym_060359E4
    .long  sym_06035460
    .long  0x40680000
    .long  sym_060357B8
    .long  sym_06089B18
    .long  sym_06035BC8
    .long  0x33333333
    .long  0x4054D333
    .long  0x9999999A
    .long  0x40580000
    .long  0x52F1E328
    .long  0x72011F21
    .long  0x61F27101
    .long  0x2F123532
    .long  0x8B926543
    .long  0xD3411F31
    .long  0x63536053
    .long  0x52F14308
    .long  0x4300332C
    .long  0x33AC2F32
    .long  0x7FE0D23D
    .long  0x420B2FF6
    .long  0xD13C2F16
    .long  0xD13C2F16
    .long  0x62F3D13C
    .long  0x7210410B
    .long  0x2F266053
    .long  0x7FE8D236
    .long  0x420B2FF6
    .long  0x60537FF8
    .long  0xD133410B
    .long  0x2FF662F3
    .long  0xD1347210
    .long  0x410B2F26
    .long  0xD2302F26
    .long  0xD2322F26
    .long  0x61F3D230
    .long  0x7110420B
    .long  0x2F1661F3
    .long  0xD22F7110
    .long  0x420B2F16
    .long  0xE1002F16
    .long  0xD12D2F16
    .long  0x62F3D129
    .long  0x7210410B
    .long  0x2F26D22B
    .long  0x420B0009
    .long  0x23027501
    .long  0x63F2903D
    .long  0x8132604F
    .long  0x63F28133
    .long  0x63536053
    .long  0x52F14308
    .long  0x4300332C
    .long  0x33AC2F32
    .long  0x7FE0D21A
    .long  0x420B2FF6
    .long  0xD1192F16
    .long  0xD1192F16
    .long  0x62F3D119
    .long  0x7210410B
    .long  0x2F266053
    .long  0x7FE8D213
    .long  0x420B2FF6
    .long  0x60537FF8
    .long  0xD110410B
    .long  0x2FF662F3
    .long  0xD1117210
    .long  0x410B2F26
    .long  0xD20D2F26
    .long  0xD20F2F26
    .long  0x61F3D20D
    .long  0x7110420B
    .long  0x2F1661F3
    .long  0xD20C7110
    .long  0x420B2F16
    .long  0xE1002F16
    .long  0xD10A2F16
    .long  0x62F37210
    .long  0xA0142F26

    .global DAT_06021fe0
DAT_06021fe0:
    .long  0xEDB7FFFF
    .long  sym_06089B18
    .long  sym_06035BC8
    .long  0x9999999A
    .long  0x404FD999
    .long  sym_060359E4
    .long  0x40139999
    .long  sym_06035460
    .long  0x40700000
    .long  sym_060357B8
    .long  0xD144410B
    .long  0x0009D244
    .long  0x420B0009
    .long  0x23027501
    .long  0x63F2907B
    .long  0x8132604F
    .long  0x63F28133
    .long  0xE30E3532
    .long  0x8901AF59
    .long  0x0009D33D
    .long  0x1F31E31C
    .long  0x3532894B
    .long  0x63536053
    .long  0x52F14308
    .long  0x70F24300
    .long  0x332C33AC
    .long  0x2F327FE0
    .long  0xD236420B
    .long  0x2FF6D136
    .long  0x2F16D136
    .long  0x2F1662F3
    .long  0xD12F7210
    .long  0x410B2F26
    .long  0x60537FE8
    .long  0x70F2D22F
    .long  0x420B2FF6
    .long  0x60537FF8
    .long  0x70F2D22C
    .long  0x420B2FF6
    .long  0x61F3D227
    .long  0x7110420B
    .long  0x2F16D129
    .long  0x2F16D12A
    .long  0x2F1662F3
    .long  0xD1227210
    .long  0x410B2F26
    .long  0x62F3D127
    .long  0x7210410B
    .long  0x2F26E200
    .long  0x2F26D225
    .long  0x2F2661F3
    .long  0xD21B7110
    .long  0x420B2F16
    .long  0xD11A410B
    .long  0x00097501
    .long  0x2302604F
    .long  0x63F28132
    .long  0x63F2604F
    .long  0x8133E31C
    .long  0x35328BB3
    .long  0x4508D314
    .long  0x45002F32
    .long  0x353C921C
    .long  0x35AC332C
    .long  0x35328D0D
    .long  0x1F31624F
    .long  0x2F522542
    .long  0x63F27508
    .long  0x90128132
    .long  0x63F26023
    .long  0x813353F1
    .long  0x35328BF2
    .long  0x7F144F26
    .long  0x68F669F6
    .long  0x6AF66BF6
    .long  0x6CF66DF6
    .long  0x000B6EF6

    .global DAT_06022114
DAT_06022114:
    .short  0xEDB7

    .global DAT_06022116
DAT_06022116:
    .short  0x0280

    .global DAT_06022118
DAT_06022118:
    .long  0xFA13FFFF
    .long  sym_060359E4
    .long  sym_060357B8
    .long  sym_06089B18
    .long  sym_06035BC8
    .long  0x9999999A
    .long  0x404FD999
    .long  0x40139999
    .long  sym_06035460
    .long  0x40600000
