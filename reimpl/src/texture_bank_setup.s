
    .section .text.FUN_060370E4


    .global texture_bank_setup
    .type texture_bank_setup, @function
texture_bank_setup:
    mov.l r14, @-r15
    mov #0x0, r3
    mov.l r13, @-r15
    mov r3, r2
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov r4, r11
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_0603715C, r9
    mov.l   .L_06037160, r10
    mov.l   .L_06037164, r12
    mov.l   .L_06037168, r13
    mov.l   .L_0603716C, r14
    mov.l r3, @r10
    mov.l r3, @(4, r10)
    mov.l @r11, r3
    mov.l r3, @r14
    mov.l @(4, r11), r2
    mov.l r2, @(4, r14)
    mov.w   DAT_06037154, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.b @(8, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06037132
    mov.w   DAT_06037156, r2
    mov.w @(14, r12), r0
    mov r0, r3
    or r2, r3
    mov r3, r0
    bra     .L_0603713C
    nop
.L_06037132:
    mov.l   .L_06037170, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_0603713C:
    mov.w r0, @(14, r12)
    mov.b @(9, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06037174
    mov.w   .L_06037158, r2
    mov.w @(14, r12), r0
    mov r0, r3
    or r2, r3
    mov r3, r0
    bra     .L_0603717E
    nop

    .global DAT_06037154
DAT_06037154:
    .2byte  0x7FFF

    .global DAT_06037156
DAT_06037156:
    .2byte  0x0100
.L_06037158:
    .2byte  0x0200
    .2byte  0xFFFF
.L_0603715C:
    .4byte  0x0000FF00                  /* byte 1 mask */
.L_06037160:
    .4byte  sym_060A4C44
.L_06037164:
    .4byte  sym_060A3D88
.L_06037168:
    .4byte  sym_060A3E38
.L_0603716C:
    .4byte  sym_060A4C4C
.L_06037170:
    .4byte  0x0000FEFF
.L_06037174:
    mov.l   .L_06037290, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_0603717E:
    mov #0x0, r5
    mov #0x4, r2
    mov.w r0, @(14, r12)
    extu.b r5, r4
    mov.b @(10, r11), r0
    mov r0, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt/s    .L_060371DE
    extu.b r5, r8
    mov.w @(14, r12), r0
    mov.l   .L_06037294, r3
    mov r0, r2
    extu.w r2, r2
    mov.b @(10, r11), r0
    and r3, r2
    mov r0, r1
    extu.b r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.b @(10, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_060371F4
    mov.l @r14, r0
    tst r0, r0
    bt      .L_060371C6
    mov.l   .L_06037294, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    bra     .L_060371C8
    mov.w r0, @(14, r12)
.L_060371C6:
    mov #0x1, r8
.L_060371C8:
    mov.w @(6, r13), r0
    mov r0, r2
    and r9, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @r14, r3
    mov.l   .L_06037298, r2
    add r2, r3
    mov.l r3, @r10
    bra     .L_060371F4
    mov #0x1, r4
.L_060371DE:
    mov.b @(10, r11), r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf      .L_060371F4
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_06037298, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_060371F4:
    mov.b @(11, r11), r0
    mov #0x4, r2
    mov r0, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_060372A4
    mov.w @(14, r12), r0
    mov.l   .L_0603729C, r3
    mov r0, r2
    extu.w r2, r2
    mov.b @(11, r11), r0
    and r3, r2
    mov r0, r1
    extu.b r1, r1
    shll2 r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.b @(11, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_060372C6
    extu.b r4, r2
    tst r2, r2
    bf      .L_0603725C
    mov.l @r14, r0
    tst r0, r0
    bt      .L_0603723E
    mov.l   .L_0603729C, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    bra     .L_06037240
    mov.w r0, @(14, r12)
.L_0603723E:
    mov #0x2, r8
.L_06037240:
    mov.w @(6, r13), r0
    mov r0, r2
    and r9, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.w @(6, r13), r0
    or #0x1, r0
    mov.w r0, @(6, r13)
    mov.l @r14, r3
    mov.l   .L_060372A0, r2
    add r2, r3
    mov.l r3, @r10
    bra     .L_0603728A
    mov #0x1, r4
.L_0603725C:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_0603726E
    mov.l   .L_0603729C, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(14, r12)
.L_0603726E:
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   DAT_0603728e, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_060372A0, r2
    add r2, r3
    mov.l r3, @(4, r10)
    add #0x1, r4
.L_0603728A:
    bra     .L_060372C6
    nop

    .global DAT_0603728e
DAT_0603728e:
    .2byte  0x0100
.L_06037290:
    .4byte  0x0000FDFF
.L_06037294:
    .4byte  0x0000FFFC
.L_06037298:
    .4byte  0x25E00000                  /* VDP2 VRAM +0x00000 */
.L_0603729C:
    .4byte  0x0000FFF3
.L_060372A0:
    .4byte  0x25E20000                  /* VDP2 VRAM +0x20000 */
.L_060372A4:
    mov.b @(11, r11), r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf      .L_060372C6
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   DAT_06037362, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_06037368, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_060372C6:
    mov #0x4, r2
    mov.b @(12, r11), r0
    mov r0, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_06037374
    mov.w @(14, r12), r0
    mov.l   .L_0603736C, r3
    mov r0, r2
    extu.w r2, r2
    mov.b @(12, r11), r0
    and r3, r2
    mov r0, r1
    extu.b r1, r1
    shll2 r1
    shll2 r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.b @(12, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_0603739E
    extu.b r4, r2
    tst r2, r2
    bf      .L_06037330
    mov.l @r14, r0
    tst r0, r0
    bt      .L_06037312
    mov.l   .L_0603736C, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    bra     .L_06037314
    mov.w r0, @(14, r12)
.L_06037312:
    mov #0x3, r8
.L_06037314:
    mov.w @(6, r13), r0
    mov r0, r2
    and r9, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.w @(6, r13), r0
    or #0x2, r0
    mov.w r0, @(6, r13)
    mov.l @r14, r3
    mov.l   .L_06037370, r2
    add r2, r3
    mov.l r3, @r10
    bra     .L_0603735E
    mov #0x1, r4
.L_06037330:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_06037342
    mov.l   .L_0603736C, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(14, r12)
.L_06037342:
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   .L_06037364, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    add #0x1, r4
    mov.l @(4, r14), r3
    mov.l   .L_06037370, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_0603735E:
    bra     .L_0603739E
    nop

    .global DAT_06037362
DAT_06037362:
    .2byte  0x0100
.L_06037364:
    .2byte  0x0200
    .2byte  0xFFFF
.L_06037368:
    .4byte  0x25E20000                  /* VDP2 VRAM +0x20000 */
.L_0603736C:
    .4byte  0x0000FFCF
.L_06037370:
    .4byte  0x25E40000                  /* VDP2 VRAM +0x40000 */
.L_06037374:
    mov.b @(12, r11), r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf      .L_0603739E
    mov.l   .L_06037440, r2
    mov.l @r2, r0
    tst r0, r0
    bt      .L_0603739E
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   DAT_0603743a, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_06037444, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_0603739E:
    mov #0x4, r2
    mov.b @(13, r11), r0
    mov r0, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_06037450
    mov.w @(14, r12), r0
    mov.l   .L_06037448, r3
    mov r0, r2
    extu.w r2, r2
    mov.b @(13, r11), r0
    and r3, r2
    mov r0, r1
    extu.b r1, r1
    shll2 r1
    shll2 r1
    shll2 r1
    extu.w r1, r1
    or r1, r2
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.b @(13, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_0603747A
    extu.b r4, r4
    tst r4, r4
    bf      .L_0603740A
    mov.l @r14, r0
    tst r0, r0
    bt      .L_060373EC
    mov.l   .L_06037448, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    bra     .L_060373EE
    mov.w r0, @(14, r12)
.L_060373EC:
    mov #0x4, r8
.L_060373EE:
    mov.w @(6, r13), r0
    mov r0, r2
    and r9, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.w @(6, r13), r0
    or #0x3, r0
    mov.w r0, @(6, r13)
    mov.l @r14, r3
    mov.l   .L_0603744C, r2
    add r2, r3
    mov.l r3, @r10
    bra     .L_06037436
    nop
.L_0603740A:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_0603741C
    mov.l   .L_06037448, r3
    mov.w @(14, r12), r0
    mov r0, r2
    and r3, r2
    mov r2, r0
    mov.w r0, @(14, r12)
.L_0603741C:
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   .L_0603743C, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_0603744C, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_06037436:
    bra     .L_0603747A
    nop

    .global DAT_0603743a
DAT_0603743a:
    .2byte  0x0200
.L_0603743C:
    .2byte  0x0300
    .2byte  0xFFFF
.L_06037440:
    .4byte  sym_060A4C50
.L_06037444:
    .4byte  0x25E40000                  /* VDP2 VRAM +0x40000 */
.L_06037448:
    .4byte  0x0000FF3F
.L_0603744C:
    .4byte  0x25E60000                  /* VDP2 VRAM +0x60000 */
.L_06037450:
    mov.b @(13, r11), r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf      .L_0603747A
    mov.l   .L_06037538, r2
    mov.l @r2, r0
    tst r0, r0
    bt      .L_0603747A
    mov.w @(6, r13), r0
    and #0xFF, r0
    mov.w r0, @(6, r13)
    mov.w   DAT_06037532, r3
    mov.w @(6, r13), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @(4, r14), r3
    mov.l   .L_0603753C, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_0603747A:
    mov.l @(4, r10), r0
    tst r0, r0
    bt      .L_06037484
    bra     .L_060375F2
    nop
.L_06037484:
    mov.b @(14, r11), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_060374B2
    mov.l   .L_06037540, r2
    mov.l @r2, r0
    tst r0, r0
    bf      .L_060374B2
    mov.l   .L_06037544, r3
    jsr @r3
    nop
    cmp/eq #0x1, r0
    bf      .L_060374B2
    mov.l   .L_06037548, r3
    mov.w @(14, r12), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
    mov.w r0, @(14, r12)
    mov.l   .L_0603754C, r3
    mov.l r3, @r10
    bra     .L_060375F2
    nop
.L_060374B2:
    mov.l @r10, r0
    tst r0, r0
    bt      .L_06037578
    mov.l   .L_06037550, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_06037578
    mov.l @(4, r14), r0
    tst r0, r0
    bf      .L_060374D0
    mov.l @r14, r3
    mov.w   .L_06037534, r2
    add r2, r3
    mov.l r3, @(4, r14)
.L_060374D0:
    mov.l @r14, r0
    tst r0, r0
    bf      .L_060374DA
    mov #-0x1, r3
    mov.l r3, @r14
.L_060374DA:
    mov.l @(4, r14), r2
    mov.l @r10, r3
    add r3, r2
    mov.l r2, @(4, r10)
    mov.w @(6, r13), r0
    mov r0, r4
    extu.w r4, r4
    mov.w   DAT_06037536, r3
    and r4, r3
    mov r4, r2
    shll8 r2
    or r2, r3
    extu.w r3, r0
    mov.w r0, @(6, r13)
    bra     .L_06037564
    extu.b r8, r0
.L_060374FA:
    mov.l   .L_06037554, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    bra     .L_0603752E
    nop
.L_06037508:
    mov.l   .L_06037558, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    bra     .L_0603752E
    nop
.L_06037516:
    mov.l   .L_0603755C, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    bra     .L_0603752E
    nop
.L_06037524:
    mov.l   .L_06037560, r2
    mov.w @(14, r12), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
.L_0603752E:
    bra     .L_060375F2
    mov.w r0, @(14, r12)

    .global DAT_06037532
DAT_06037532:
    .2byte  0x0300
.L_06037534:
    .2byte  0x0400

    .global DAT_06037536
DAT_06037536:
    .2byte  0x00FF
.L_06037538:
    .4byte  sym_060A4C50
.L_0603753C:
    .4byte  0x25E60000                  /* VDP2 VRAM +0x60000 */
.L_06037540:
    .4byte  sym_060A4C44
.L_06037544:
    .4byte  sym_0603C156
.L_06037548:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_0603754C:
    .4byte  0x25F00800                  /* VDP2 color RAM +0x800 */
.L_06037550:
    .4byte  sym_060A4C59
.L_06037554:
    .4byte  0x0000FFFC
.L_06037558:
    .4byte  0x0000FFF3
.L_0603755C:
    .4byte  0x0000FFCF
.L_06037560:
    .4byte  0x0000FF3F
.L_06037564:
    cmp/eq #0x1, r0
    bt      .L_060374FA
    cmp/eq #0x2, r0
    bt      .L_06037508
    cmp/eq #0x3, r0
    bt      .L_06037516
    cmp/eq #0x4, r0
    bt      .L_06037524
    bra     .L_060375F2
    nop
.L_06037578:
    mov.l @r10, r0
    tst r0, r0
    bf      .L_060375F2
    mov.l @r14, r0
    tst r0, r0
    bt      .L_060375B8
    mov.l   .L_06037604, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_060375B8
    mov.w @(6, r13), r0
    mov r14, r4
    mov r0, r3
    and r9, r3
    mov r3, r0
    mov.w r0, @(6, r13)
    mov.l   .L_06037608, r0
    mov.l   .L_0603760C, r3
    jsr @r3
    mov.l @r4, r1
    extu.w r0, r0
    mov #0x6, r2
    add r13, r2
    mov.w @r2, r2
    or r0, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @r4, r3
    mov.l   .L_06037610, r2
    add r2, r3
    mov.l r3, @r10
.L_060375B8:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_060375F2
    mov.l   .L_06037614, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_060375F2
    mov.w @(6, r13), r0
    mov r14, r4
    and #0xFF, r0
    add #0x4, r4
    mov.w r0, @(6, r13)
    mov.l   .L_06037608, r0
    mov.l   .L_0603760C, r3
    jsr @r3
    mov.l @r4, r1
    extu.w r0, r0
    shll8 r0
    mov #0x6, r2
    add r13, r2
    mov.w @r2, r2
    or r0, r2
    mov r2, r0
    mov.w r0, @(6, r13)
    mov.l @r4, r3
    mov.l   .L_06037610, r2
    add r2, r3
    mov.l r3, @(4, r10)
.L_060375F2:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06037604:
    .4byte  sym_060A4C58
.L_06037608:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_0603760C:
    .4byte  sym_06034FFC
.L_06037610:
    .4byte  0x25E00000                  /* VDP2 VRAM +0x00000 */
.L_06037614:
    .4byte  sym_060A4C59

    .global sym_06037618
sym_06037618:
    mov #0x10, r7
    mov #0x0, r5
    mov.b r5, @r4
    extu.b r5, r2
    mov r2, r0
    mov.b r0, @(1, r4)
    extu.b r5, r0
    mov.b r0, @(2, r4)
    extu.b r5, r0
    mov.b r0, @(3, r4)
    extu.b r5, r0
    mov.b r0, @(4, r4)
    extu.b r5, r0
    mov.b r0, @(5, r4)
    extu.b r5, r0
    mov.b r0, @(6, r4)
    extu.b r5, r0
    mov.b r0, @(8, r4)
    extu.b r5, r0
    mov.b r0, @(7, r4)
    extu.w r5, r3
    mov r3, r0
    mov.w r0, @(10, r4)
    extu.b r5, r6
.L_06037648:
    extu.b r6, r3
    mov r4, r2
    shll2 r3
    add #0x1, r6
    add #0xC, r2
    add r2, r3
    mov.l r5, @r3
    extu.b r6, r3
    cmp/ge r7, r3
    bf      .L_06037648
    rts
    nop
