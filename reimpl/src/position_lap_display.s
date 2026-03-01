
    .section .text.FUN_0603139C


    .global position_lap_display
    .type position_lap_display, @function
position_lap_display:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    neg r0, r11
    exts.w r11, r11
    mov.l @r15+, r0
    mov #0x0, r9
    mov.w   DAT_0603143a, r4
    mov.l @(48, r13), r1
    extu.w r4, r4
    exts.w r1, r1
    mov #0x1, r7
    mov r4, r3
    extu.w r11, r6
    shll r3
    or r3, r6
    sub r6, r1
    cmp/pl r1
    bt      .L_060313C6
    neg r1, r1
.L_060313C6:
    extu.w r1, r1
    cmp/gt r1, r4
    bt      .L_060313D0
    sub r4, r1
    mov #0x0, r7
.L_060313D0:
    mov.l @(48, r13), r1
    mov #0x1, r8
    exts.w r1, r1
    mov r4, r3
    shll r3
    extu.w r10, r6
    or r3, r6
    sub r6, r1
    cmp/pl r1
    bt/s    .L_060313E8
    mov.l @(48, r14), r2
    neg r1, r1
.L_060313E8:
    extu.w r1, r1
    .byte   0xBF, 0xA9    /* bsr 0x06031340 */
    nop
    cmp/gt r1, r4
    bt      .L_060313F6
    sub r4, r1
    mov #0x0, r8
.L_060313F6:
    cmp/eq r7, r8
    bt      .L_060313FC
    mov #0x1, r9
.L_060313FC:
    mov.l r4, @-r15
    mov r1, r4
    mov.l   .L_pool_06031440, r0
    jsr @r0
    nop
    mov.l @r15+, r4
    sub r10, r2
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_06031414
    shlr8 r1
    sub r4, r2
.L_06031414:
    shlr r1
    mov #0x0, r7
    mov #0xA, r3
    cmp/ge r1, r3
    bt      .L_06031426
    mov #0x37, r3
    cmp/ge r3, r1
    bt      .L_06031426
    mov #0x1, r7
.L_06031426:
    shll2 r1
    shlr8 r2
    shlr r2
    shll2 r2
    tst r9, r9
    bt      .L_0603144E
    tst r8, r8
    bt      .L_06031444
    bra     .L_06031446
    mov #0x0, r8

    .global DAT_0603143a
DAT_0603143a:
    .2byte  0x8000
    .4byte  atan2
.L_pool_06031440:
    .4byte  sin_lookup
.L_06031444:
    mov #0x1, r8
.L_06031446:
    tst r7, r7
    bt      .L_0603144E
    bra     .L_06031468
    mov r12, r4
.L_0603144E:
    mov.l   .L_pool_06031465, r3
    add r3, r1
    add r3, r2
    mov.l @r1, r4
    sub r12, r4
    mov.l @r2, r12
    add r12, r4
    cmp/pl r4
    bt      .L_06031468
    .byte   0xAF, 0x5F    /* bra 0x06031322 */
    nop
.L_pool_06031465:
    .4byte  sym_0605BCC8
.L_06031468:
    mov.l @(40, r14), r1
    mov.l @(40, r13), r2
    mov #0x0, r11
    sub r2, r1
    extu.w r1, r1
    mov.w   DAT_06031496, r3
    cmp/ge r1, r3
    bt      .L_060314AC
    mov r3, r2
    shll r2
    add r2, r3
    cmp/ge r3, r1
    bt      .L_060314AC
    mov #0x1, r11
    mov.l @(12, r14), r1
    mov.l @(12, r13), r3
    mov.l   .L_pool_06031499, r2
    add r3, r1
    mov.l r11, @-r15
    cmp/ge r1, r2
    bf      .L_0603149C
    bra     .L_06031556
    nop

    .global DAT_06031496
DAT_06031496:
    .2byte  0x4000
.L_pool_06031499:
    .4byte  0x00042AAA
.L_0603149C:
    mov.l @(0, r13), r1
    mov.l   .L_pool_060314A9, r3
    or r3, r1
    mov.l r1, @(0, r13)
    bra     .L_06031556
    nop
.L_pool_060314A9:
    .4byte  0x08000000
.L_060314AC:
    mov.l r11, @-r15
    mov.l @(12, r13), r1
    mov.l @(12, r14), r3
    mov.l   .L_pool_060314C9, r2
    sub r3, r1
    cmp/ge r1, r2
    bt      .L_060314D0
    mov.l @(0, r13), r1
    mov.l   .L_pool_060314CD, r3
    or r3, r1
    mov.l r1, @(0, r13)
    bra     .L_06031556
    nop
    .2byte  0x0000
.L_pool_060314C9:
    .4byte  0x00042AAA
.L_pool_060314CD:
    .4byte  0x08000000
.L_060314D0:
    tst r7, r7
    bf      .L_060314FC
    mov.l @(12, r14), r1
    mov.l   .L_pool_060314F5, r2
    mov.l @(12, r13), r3
    shlr r2
    sub r1, r3
    cmp/gt r3, r2
    bt      .L_060314FC
    tst r8, r8
    mov.l @(0, r13), r2
    mov.l   .L_pool_060314F9, r3
    bt      .L_060314EC
    shlr r3
.L_060314EC:
    or r3, r2
    bra     .L_06031556
    mov.l r2, @(0, r13)
    .2byte  0x0000
.L_pool_060314F5:
    .4byte  0x00042AAA
.L_pool_060314F9:
    .4byte  0x20000000
.L_060314FC:
    mov.l @(40, r13), r3
    sub r10, r3
    mov.w   DAT_06031516, r2
    extu.w r3, r3
    cmp/ge r3, r2
    bt      .L_06031518
    mov r2, r1
    shll r1
    add r1, r2
    cmp/ge r2, r3
    bt      .L_06031518
    bra     .L_06031556
    nop

    .global DAT_06031516
DAT_06031516:
    .2byte  0x4000
.L_06031518:
    mov.l r4, @-r15
    mov.l r0, @-r15
    tst r7, r7
    bt      .L_0603152C
    mov.l @(32, r13), r4
    mov.l r4, @(48, r14)
    mov.w   .L_wpool_0603156B, r1
    mov #0x8, r2
    add r13, r1
    mov.l r2, @r1
.L_0603152C:
    mov r3, r4
    mov.l   .L_pool_06031571, r0
    jsr @r0
    nop
    mov.l @(12, r13), r1
    mov.l @(12, r14), r2
    sub r2, r1
    dmuls.l r0, r1
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    shar r1
    add r1, r2
    mov.l r2, @(12, r14)
    mov.l @(12, r13), r4
    mov.w   .L_wpool_0603156D, r3
    add r13, r3
    sub r1, r4
    mov.l r4, @r3
    mov.l @r15+, r0
    mov.l @r15+, r4
.L_06031556:
    mov.l @r15+, r11
    tst r7, r7
    bf      .L_06031578
    mov.l   .L_pool_06031575, r5
    mov.b @r5, r3
    tst r3, r3
    bf      .L_0603160C
    mov #0x3, r3
    bra     .L_0603160C
    mov.b r3, @r5
.L_wpool_0603156B:
    .2byte  0x0208
.L_wpool_0603156D:
    .2byte  0x0194
    .2byte  0x0000
.L_pool_06031571:
    .4byte  cos_lookup
.L_pool_06031575:
    .4byte  sym_0602FD9A
.L_06031578:
    mov.l r0, @-r15
    mov.l r4, @-r15
    tst r11, r11
    mov.l   .L_pool_06031591, r5
    mov.l   .L_pool_06031595, r10
    mov.l @(0, r14), r2
    mov.w @r10, r10
    bt      .L_06031598
    tst r8, r8
    bt      .L_060315A0
    bra     .L_060315B2
    nop
.L_pool_06031591:
    .4byte  sym_0602FD98
.L_pool_06031595:
    .4byte  sym_06031A24
.L_06031598:
    tst r8, r8
    bt      .L_060315D0
    bra     .L_060315C0
    nop
.L_060315A0:
    add #0x1, r5
    tst r10, r10
    mov #-0x80, r3
    extu.b r3, r3
    bt      .L_060315D8
    mov.w   .L_wpool_060315B1, r3
    bra     .L_060315D8
    nop
.L_wpool_060315B1:
    .2byte  0x0200
.L_060315B2:
    tst r10, r10
    mov #0x40, r3
    bt      .L_060315D8
    mov.w   .L_wpool_060315BF, r3
    bra     .L_060315D8
    nop
.L_wpool_060315BF:
    .2byte  0x0100
.L_060315C0:
    add #0x1, r5
    tst r10, r10
    mov.w   .L_wpool_060315CF, r3
    bt      .L_060315D8
    mov #-0x80, r3
    bra     .L_060315D8
    extu.b r3, r3
.L_wpool_060315CF:
    .2byte  0x0200
.L_060315D0:
    tst r10, r10
    mov.w   .L_wpool_0603162B, r3
    bt      .L_060315D8
    mov #0x40, r3
.L_060315D8:
    mov.b @r5, r4
    or r3, r2
    tst r4, r4
    mov.l r2, @(0, r14)
    bf      .L_060315E6
    mov #0x3, r4
    mov.b r4, @r5
.L_060315E6:
    mov.l @r15+, r4
    mov.l @r15+, r0
    mov.w   .L_wpool_0603162D, r3
    tst r8, r8
    mov.l @(48, r13), r10
    bf/s    .L_060315FA
    extu.w r10, r10
    mov r3, r7
    shll r7
    add r7, r3
.L_060315FA:
    dmuls.l r0, r4
    add r3, r10
    tst r9, r9
    sts mach, r0
    sts macl, r4
    xtrct r0, r4
    bt      .L_0603160C
    mov.l   .L_pool_06031631, r3
    add r3, r4
.L_0603160C:
    mov.w   DAT_0603162e, r3
    add r14, r3
    mov.w @r3, r0
    mov #0x8, r5
    cmp/ge r5, r0
    bt      .L_0603163A
    add #-0x2, r5
    cmp/ge r5, r0
    bt      .L_06031634
    shlr r4
    mov r4, r3
    shlr r3
    add r3, r4
    bra     .L_06031640
    mov.l r4, @-r15
.L_wpool_0603162B:
    .2byte  0x0100
.L_wpool_0603162D:
    .2byte  0x4000

    .global DAT_0603162e
DAT_0603162e:
    .2byte  0x007C
.L_pool_06031631:
    .4byte  0x0000D999
.L_06031634:
    mov #0x0, r3
    bra     .L_06031640
    mov.l r4, @-r15
.L_0603163A:
    mov r4, r3
    mov #0x0, r4
    mov.l r4, @-r15
.L_06031640:
    neg r10, r4
    mov r3, r9
    mov.l @(16, r14), r5
    mov.l @(24, r14), r6
    mov.l r5, @(56, r14)
    mov.l r6, @(60, r14)
    mov.l   .L_pool_060316BA, r0
    jsr @r0
    nop
    mov r0, r8
    neg r10, r4
    mov.l   .L_pool_060316BE, r0
    jsr @r0
    nop
    dmuls.l r0, r3
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    add r3, r5
    mov.l r5, @(16, r14)
    dmuls.l r8, r9
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    add r9, r6
    mov.l r6, @(24, r14)
    mov.l @r15+, r3
    mov.l   .L_060316C0, r5
    mov r3, r4
    shlr r3
    add r4, r3
    add r5, r10
    neg r10, r4
    mov r3, r9
    mov.l @(16, r13), r5
    mov.l @(24, r13), r6
    mov.l r5, @(56, r13)
    mov.l r6, @(60, r13)
    mov.l   .L_pool_060316BA, r0
    jsr @r0
    nop
    mov r0, r8
    neg r10, r4
    mov.l   .L_pool_060316BE, r0
    jsr @r0
    nop
    dmuls.l r0, r3
    sts mach, r11
    sts macl, r3
    xtrct r11, r3
    add r3, r5
    mov.l r5, @(16, r13)
    dmuls.l r8, r9
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    add r9, r6
    .byte   0xAE, 0x36    /* bra 0x06031322 */
    mov.l r6, @(24, r13)
    .2byte  0x0000
.L_pool_060316BA:
    .4byte  cos_lookup
.L_pool_060316BE:
    .4byte  sin_lookup
.L_060316C0:
    .4byte  0x00008000

    .global sym_060316C4
sym_060316C4:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
