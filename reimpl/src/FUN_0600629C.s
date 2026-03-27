
    .section .text.FUN_0600629C


    .global FUN_0600629C
    .type FUN_0600629C, @function
FUN_0600629C:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    extu.w r13, r1
    extu.w r13, r0
    extu.w r13, r3
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   .L_06006364, r8
    mov.w   .L_0600635E, r9
    mov.l   .L_06006368, r10
    mov.l   .L_0600636C, r12
    mov.l   .L_06006370, r14
    mov.l   .L_06006374, r2
    mov.w r13, @r2
    mov.l   .L_06006378, r2
    mov.w r1, @r2
    mov.l   .L_0600637C, r2
    mov.w r0, @r2
    mov.l   .L_06006380, r2
    mov.w r3, @r2
    mov.l   .L_06006384, r1
    mov.b @r1, r1
    extu.b r1, r1
    tst r1, r1
    bt      .L_0600635A
    mov r8, r3
    add r9, r3
    mov.l r3, @r14
    mov r3, r2
    mov.l r3, @r12
    mov.l @r14, r3
    jsr @r10
    mov.l r13, @(4, r3)
    mov.l @r12, r2
    mov #0x38, r3
    mov #0x74, r0
    mov.l r3, @(r0, r2)
    mov.l @r12, r3
    mov #0x38, r2
    add #0x1C, r0
    mov.l r2, @(r0, r3)
    mov.l   .L_06006388, r4
    add #0xE, r0
    mov.l @r12, r3
    mov.b @r4, r2
    extu.b r2, r2
    mov.w r2, @(r0, r3)
    mov.l @r12, r3
    mov.b @(1, r4), r0
    mov r0, r2
    extu.b r2, r2
    mov #0x7C, r0
    mov.w r2, @(r0, r3)
    mov.l @r12, r3
    mov.b @(2, r4), r0
    mov r0, r2
    extu.b r2, r2
    mov.w   DAT_06006360, r0
    mov.w r2, @(r0, r3)
    mov.l   .L_0600638C, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06006338
    mov.l @r14, r3
    mov.w   DAT_06006362, r0
    mov.w r13, @(r0, r3)
    mov.l @r14, r3
    exts.w r13, r2
    add #0x2, r0
    mov.w r2, @(r0, r3)
    bra     .L_06006348
    nop
.L_06006338:
    mov.l @r14, r2
    mov #0x3, r3
    mov.w   DAT_06006362, r0
    mov.w r3, @(r0, r2)
    mov.l @r14, r3
    mov #0x3, r2
    add #0x2, r0
    mov.w r2, @(r0, r3)
.L_06006348:
    mov r8, r3
    mov.l r8, @r14
    mov r3, r2
    mov.l r3, @r12
    mov.l @r14, r3
    jsr @r10
    mov.l r13, @(4, r3)
    bra     .L_060063A8
    nop
.L_0600635A:
    bra     .L_060063A0
    mov r13, r11
.L_0600635E:
    .2byte  0x0268

    .global DAT_06006360
DAT_06006360:
    .2byte  0x009C

    .global DAT_06006362
DAT_06006362:
    .2byte  0x00DC
.L_06006364:
    .4byte  sym_06078900
.L_06006368:
    .4byte  FUN_0600E1D4
.L_0600636C:
    .4byte  sym_0607E944
.L_06006370:
    .4byte  sym_0607E940
.L_06006374:
    .4byte  sym_0605DF4E
.L_06006378:
    .4byte  sym_0605DF50
.L_0600637C:
    .4byte  sym_0605DF52
.L_06006380:
    .4byte  sym_0605DF54
.L_06006384:
    .4byte  sym_06078635
.L_06006388:
    .4byte  sym_0607ED90
.L_0600638C:
    .4byte  sym_0607EAD8
.L_06006390:
    mul.l r9, r11
    sts macl, r2
    add r8, r2
    mov r2, r3
    mov.l r2, @r14
    jsr @r10
    mov.l r11, @(4, r3)
    add #0x1, r11
.L_060063A0:
    mov.l   .L_06006450, r2
    mov.l @r2, r2
    cmp/ge r2, r11
    bf      .L_06006390
.L_060063A8:
    mov.l @r12, r2
    mov #0x38, r3
    mov #0x74, r0
    mov.l r3, @(r0, r2)
    mov.l @r12, r3
    mov #0x38, r2
    add #0x1C, r0
    mov.l r2, @(r0, r3)
    mov.l @r12, r3
    add #0xC, r0
    mov.l   .L_06006454, r2
    mov.l @r2, r2
    exts.w r2, r2
    mov.w r2, @(r0, r3)
    mov.l @r12, r3
    add #0x2, r0
    mov.l   .L_06006458, r2
    mov.w @r2, r2
    mov.w r2, @(r0, r3)
    mov #0x7C, r0
    mov.l @r12, r3
    mov.l   .L_0600645C, r2
    mov.l @r2, r2
    mov.w r2, @(r0, r3)
    mov.l   .L_06006460, r3
    jsr @r3
    nop
    mov.l   .L_06006464, r3
    jsr @r3
    nop
    mov.l   .L_06006468, r0
    mov.l @r0, r0
    cmp/eq #0xE, r0
    bf      .L_060063F4
    mov.l   .L_0600646C, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_060063FE
.L_060063F4:
    mov #0x0, r3
    mov.l   .L_06006470, r2
    mov.l r3, @r2
    bra     .L_06006404
    nop
.L_060063FE:
    mov #0x1, r3
    mov.l   .L_06006470, r2
    mov.l r3, @r2
.L_06006404:
    mov.l @r12, r4
    mov.l   .L_06006474, r3
    mov.l @(32, r4), r2
    mov.l r2, @r3
    add #0x4, r3
    mov.l r13, @r3
    mov.l   .L_06006478, r3
    mov.l r13, @r3
    mov.l   .L_0600647C, r3
    mov.l r13, @r3
    mov r3, r2
    mov.l @r2, r2
    mov.l   .L_06006480, r3
    mov.l r2, @r3
    mov r3, r2
    mov.l @r2, r2
    mov.l   .L_06006484, r3
    mov.l r2, @r3
    mov r3, r2
    mov.l @r2, r2
    mov.l   .L_06006488, r3
    mov.l r2, @r3
    mov.l   .L_0600648C, r2
    mov.l   .L_06006490, r3
    mov.l r2, @r3
    mov.l   .L_0600646C, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06006494
    mov.w   .L_0600644C, r0
    mov.w r13, @(r0, r4)
    exts.w r13, r3
    add #0x2, r0
    mov.w r3, @(r0, r4)
    bra     .L_060064A0
    nop
.L_0600644C:
    .2byte  0x00DC
    .2byte  0xFFFF
.L_06006450:
    .4byte  sym_0607EA98
.L_06006454:
    .4byte  sym_0607EAB8
.L_06006458:
    .4byte  sym_06063F42
.L_0600645C:
    .4byte  sym_06078868
.L_06006460:
    .4byte  sym_0600D280
.L_06006464:
    .4byte  sym_0602E5E4
.L_06006468:
    .4byte  sym_0607EBC0
.L_0600646C:
    .4byte  sym_0607EAD8
.L_06006470:
    .4byte  sym_0607EAD0
.L_06006474:
    .4byte  sym_06063EF0
.L_06006478:
    .4byte  sym_06063F10
.L_0600647C:
    .4byte  sym_06063E78
.L_06006480:
    .4byte  sym_06063E8C
.L_06006484:
    .4byte  sym_06063E64
.L_06006488:
    .4byte  sym_06063E50
.L_0600648C:
    .4byte  0xFEA00000
.L_06006490:
    .4byte  sym_06063F14
.L_06006494:
    mov #0x3, r2
    mov.w   .L_pool_0600654C, r0
    mov.w r2, @(r0, r4)
    mov r2, r3
    add #0x2, r0
    mov.w r3, @(r0, r4)
.L_060064A0:
    mov.l   .L_pool_06006550, r3
    mov #0x2, r2
    mov #0x0, r5
    mov.l r13, @r3
    mov.l   .L_06006554, r3
    mov.l r2, @r3
    mov #0x1, r2
    mov.l   .L_pool_06006558, r3
    mov.l r2, @r3
    mov.l   .L_0600655C, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_06006560, r2
    mov.l   .L_06006564, r3
    mov.l r2, @r3
    mov.l   .L_pool_06006568, r4
    mov.l   .L_pool_0600656C, r3
    mov.l r4, @r3
    mov.l   .L_pool_06006570, r2
    mov.l   .L_pool_06006574, r3
    mov.l r2, @r3
    mov.l   .L_pool_06006578, r2
    mov.l   .L_pool_0600657C, r3
    mov.l r2, @r3
    mov.l   .L_pool_06006580, r3
    mov.l r13, @r3
    mov.l   .L_pool_06006584, r3
    mov.l r4, @r3
    mov #0x2, r2
    mov.l   .L_06006588, r3
    mov.l r2, @r3
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .reloc ., R_SH_IND12W, steering_input_dispatch - 4
    .2byte 0xA000    /* bra steering_input_dispatch (linker-resolved) */
    mov.l @r15+, r14


    .global FUN_060064F2
    .type FUN_060064F2, @function
FUN_060064F2:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.l   .L_0600658C, r11
    mov.l   .L_06006590, r12
    mov.l   .L_06006554, r13
    mov.l   .L_06006564, r14
    mov.l   .L_06006588, r3
    mov.l   .L_06006594, r2
    mov.l @r3, r3
    shll2 r3
    add r2, r3
    mov.l @r3, r1
    mov.l r1, @r12
    mov.l @r14, r3
    cmp/gt r11, r3
    bt/s    .L_06006532
    mov #0x1, r10
    mov.l   .L_06006598, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bt      .L_06006532
    mov #0x5, r5
    mov.l   .L_0600655C, r3
    jsr @r3
    mov #0x8, r4
    bra     .L_0600653A
    nop
.L_06006532:
    mov #0x0, r5
    mov.l   .L_0600655C, r3
    jsr @r3
    mov #0x8, r4
.L_0600653A:
    mov.l @r14, r2
    mov.l @r12, r3
    cmp/eq r3, r2
    bf      .L_0600659C
    mov.l   .L_06006588, r3
    mov.l @r3, r3
    mov.l r3, @r13
    bra     .L_06006780
    nop
.L_pool_0600654C:
    .4byte  0x00DCFFFF
.L_pool_06006550:
    .4byte  sym_060620D0
.L_06006554:
    .4byte  sym_06063E1C
.L_pool_06006558:
    .4byte  sym_06059F30
.L_0600655C:
    .4byte  FUN_06038BD4
.L_pool_06006560:
    .4byte  0x00058000
.L_06006564:
    .4byte  sym_06063E24
.L_pool_06006568:
    .4byte  0x0000F300
.L_pool_0600656C:
    .4byte  sym_06063E34
.L_pool_06006570:
    .4byte  0x006E0000
.L_pool_06006574:
    .4byte  sym_06063E28
.L_pool_06006578:
    .4byte  0x00100000
.L_pool_0600657C:
    .4byte  sym_06063E2C
.L_pool_06006580:
    .4byte  sym_06063E30
.L_pool_06006584:
    .4byte  sym_06063EEC
.L_06006588:
    .4byte  sym_06063E20
.L_0600658C:
    .4byte  0x00008000
.L_06006590:
    .4byte  sym_06063F4C
.L_06006594:
    .4byte  sym_060446B8
.L_06006598:
    .4byte  sym_06078654
.L_0600659C:
    mov.l   .L_0600666C, r0
    mov.l   .L_06006670, r1
    mov.l   .L_06006674, r7
    mov.l   .L_06006678, r6
    mov.l   .L_0600667C, r5
    mov.l   .L_06006680, r4
    mov.l @r12, r2
    mov.l @r14, r3
    cmp/ge r3, r2
    bt      .L_060066A0
    mov.l @r14, r3
    mov.l   .L_06006684, r2
    cmp/gt r2, r3
    bf      .L_060065D6
    mov #0x4, r2
    mov.l r2, @r13
    mov.l @r14, r3
    sub r1, r3
    mov.l r3, @r14
    mov.w   .L_06006662, r2
    mov.l @r4, r3
    sub r2, r3
    mov.l r3, @r4
    mov.l   .L_06006688, r2
    mov.l @r5, r3
    sub r2, r3
    mov.l r3, @r5
    bra     .L_06006780
    nop
.L_060065D6:
    mov.l @r14, r2
    cmp/gt r0, r2
    bf      .L_060065FA
    mov #0x3, r2
    mov.l r2, @r13
    mov.w   .L_06006664, r3
    mov.l @r14, r2
    sub r3, r2
    mov.l r2, @r14
    mov #-0x80, r3
    mov.l @r4, r2
    sub r3, r2
    mov.l r2, @r4
    mov.l   .L_0600668C, r3
    mov.l @r5, r2
    sub r3, r2
    bra     .L_0600665E
    mov.l r2, @r5
.L_060065FA:
    mov.l @r14, r2
    cmp/gt r11, r2
    bf      .L_06006622
    mov #0x2, r2
    mov.l r2, @r13
    mov.l   .L_06006690, r3
    mov.l @r14, r2
    sub r3, r2
    mov.l r2, @r14
    mov.l @r4, r3
    add #0x40, r3
    mov.l r3, @r4
    mov.l @r5, r2
    sub r1, r2
    mov.l r2, @r5
    mov.w   DAT_06006666, r3
    mov.l @r7, r2
    sub r3, r2
    bra     .L_0600665E
    mov.l r2, @r7
.L_06006622:
    mov.l @r14, r2
    cmp/pl r2
    bf      .L_0600665A
    mov.l r10, @r13
    mov.w   DAT_06006668, r2
    mov.l @r14, r3
    sub r2, r3
    mov.l r3, @r14
    mov.w   .L_0600666A, r2
    mov.l @r4, r3
    sub r2, r3
    mov.l r3, @r4
    mov.l @r5, r2
    sub r0, r2
    mov.l r2, @r5
    mov.l   .L_06006694, r3
    mov.l @r6, r2
    sub r3, r2
    mov.l r2, @r6
    mov.l   .L_06006698, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0600665E
    mov.l   .L_0600669C, r3
    mov.l @r6, r2
    sub r3, r2
    bra     .L_0600665E
    mov.l r2, @r6
.L_0600665A:
    mov #0x0, r2
    mov.l r2, @r13
.L_0600665E:
    bra     .L_06006780
    nop
.L_06006662:
    .2byte  0xFDC0
.L_06006664:
    .2byte  0x4000

    .global DAT_06006666
DAT_06006666:
    .2byte  0xE000

    .global DAT_06006668
DAT_06006668:
    .2byte  0x1000
.L_0600666A:
    .2byte  0xFEA0
.L_0600666C:
    .4byte  0x00058000
.L_06006670:
    .4byte  0x00010000
.L_06006674:
    .4byte  sym_06063E30
.L_06006678:
    .4byte  sym_06063E2C
.L_0600667C:
    .4byte  sym_06063E28
.L_06006680:
    .4byte  sym_06063E34
.L_06006684:
    .4byte  0x00078000
.L_06006688:
    .4byte  0x0003C000
.L_0600668C:
    .4byte  0x0001C000
.L_06006690:
    .4byte  0x0000A000
.L_06006694:
    .4byte  0x000D0000
.L_06006698:
    .4byte  sym_06083255
.L_0600669C:
    .4byte  0x000A0000
.L_060066A0:
    mov.l @r12, r2
    mov.l @r14, r3
    cmp/gt r3, r2
    bf      .L_06006780
    mov.l @r14, r3
    cmp/ge r11, r3
    bt      .L_060066E2
    mov #0x0, r3
    mov.l r3, @r13
    mov.w   DAT_06006752, r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov.w   .L_06006754, r2
    mov.l @r4, r3
    add r2, r3
    mov.l r3, @r4
    mov.l @r5, r2
    add r0, r2
    mov.l r2, @r5
    mov.l   .L_0600675C, r3
    mov.l @r6, r2
    add r3, r2
    mov.l r2, @r6
    mov.l   .L_06006760, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_06006780
    mov.l   .L_06006764, r3
    mov.l @r6, r2
    add r3, r2
    bra     .L_06006780
    mov.l r2, @r6
.L_060066E2:
    mov.l @r14, r2
    cmp/ge r0, r2
    bt      .L_0600670A
    mov.l r10, @r13
    mov.l   .L_06006768, r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov.l @r4, r2
    add #-0x40, r2
    mov.l r2, @r4
    mov.l @r5, r3
    add r1, r3
    mov.l r3, @r5
    mov.w   DAT_06006756, r2
    mov.l @r7, r3
    add r2, r3
    mov.l r3, @r7
    bra     .L_06006780
    nop
.L_0600670A:
    mov.l @r14, r2
    mov.l   .L_0600676C, r3
    cmp/ge r3, r2
    bt      .L_0600672E
    mov #0x2, r3
    mov.l r3, @r13
    mov.w   DAT_06006758, r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov.l @r4, r2
    add #-0x80, r2
    mov.l r2, @r4
    mov.l   .L_06006770, r3
    mov.l @r5, r2
    add r3, r2
    bra     .L_06006780
    mov.l r2, @r5
.L_0600672E:
    mov.l @r14, r2
    mov.l   .L_06006774, r3
    cmp/ge r3, r2
    bt      .L_0600677C
    mov #0x3, r3
    mov.l r3, @r13
    mov.l @r14, r2
    add r1, r2
    mov.l r2, @r14
    mov.w   .L_0600675A, r3
    mov.l @r4, r2
    add r3, r2
    mov.l r2, @r4
    mov.l   .L_06006778, r3
    mov.l @r5, r2
    add r3, r2
    bra     .L_06006780
    mov.l r2, @r5

    .global DAT_06006752
DAT_06006752:
    .2byte  0x1000
.L_06006754:
    .2byte  0xFEA0

    .global DAT_06006756
DAT_06006756:
    .2byte  0xE000

    .global DAT_06006758
DAT_06006758:
    .2byte  0x4000
.L_0600675A:
    .2byte  0xFDC0
.L_0600675C:
    .4byte  0x000D0000
.L_06006760:
    .4byte  sym_06083255
.L_06006764:
    .4byte  0x000A0000
.L_06006768:
    .4byte  0x0000A000
.L_0600676C:
    .4byte  0x00078000
.L_06006770:
    .4byte  0x0001C000
.L_06006774:
    .4byte  0x00178000
.L_06006778:
    .4byte  0x0003C000
.L_0600677C:
    mov #0x4, r2
    mov.l r2, @r13
.L_06006780:
    .byte   0x95, 0x3F    /* mov.w .L_wpool_06006802, r5 */
    .byte   0xD3, 0x21    /* mov.l .L_pool_06006808, r3 */
    jsr @r3
    mov.l @r14, r4
    .byte   0xD3, 0x20    /* mov.l .L_pool_0600680C, r3 */
    mov.l r0, @r3
    .byte   0x95, 0x39    /* mov.w .L_wpool_06006802, r5 */
    .byte   0xD3, 0x1E    /* mov.l .L_pool_06006808, r3 */
    jsr @r3
    mov.l @r14, r4
    .byte   0xD3, 0x1E    /* mov.l .L_pool_06006810, r3 */
    mov.l r0, @r3
    .byte   0xD4, 0x1E    /* mov.l .L_pool_06006814, r4 */
    mov.l @r13, r1
    tst r1, r1
    bt      .L_060067B0
    mov.l @r13, r0
    cmp/eq #0x1, r0
    bf      .L_060067B8
    mov #0x1, r3
    .byte   0xD2, 0x1B    /* mov.l .L_pool_06006818, r2 */
    mov.l @r2, r2
    cmp/hi r3, r2
    bt      .L_060067B8
.L_060067B0:
    mov #0x0, r3
    mov.l r3, @r4
    bra     .L_060067BA
    nop
.L_060067B8:
    mov.l r10, @r4
.L_060067BA:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
