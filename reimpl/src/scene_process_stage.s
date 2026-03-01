
    .section .text.FUN_06022140


    .global scene_process_stage
    .type scene_process_stage, @function
scene_process_stage:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x24, r15
    mov.l   .L_060221E0, r8
    mov.l   .L_060221E4, r9
    mov.l   .L_060221E8, r10
    mov #0x0, r11
    mov.l   .L_060221EC, r12
    mov.l   .L_060221F0, r13
    mov.l   .L_060221F4, r3
    mov.l @r3, r3
    mov.l r3, @(4, r15)
    mov.l   .L_060221F8, r3
    mov.l r3, @(16, r15)
    mov.l   .L_060221FC, r3
    mov.l r3, @(20, r15)
    bra     .L_060227CC
    mov r11, r14
.L_06022172:
    exts.w r14, r5
    mov.l @(4, r15), r7
    mov r5, r3
    mov.l @(16, r7), r7
    shll2 r5
    shll2 r3
    shll r5
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r12, r5
    mov.l @r5, r6
    mov r6, r4
    sub r7, r4
    cmp/pz r4
    bt      .L_06022196
    mov r7, r4
    sub r6, r4
.L_06022196:
    mov.l @(8, r5), r3
    mov.l r3, @r15
    mov r3, r6
    mov.l @(4, r15), r7
    mov.l @(24, r7), r7
    sub r7, r6
    cmp/pz r6
    bt      .L_060221AE
    mov.l @r15, r2
    mov r7, r5
    bra     .L_060221B0
    sub r2, r5
.L_060221AE:
    mov r6, r5
.L_060221B0:
    mov.l   .L_06022200, r2
    cmp/ge r2, r4
    bf      .L_060221BA
    bra     .L_060227CA
    nop
.L_060221BA:
    mov.l   .L_06022200, r2
    cmp/ge r2, r5
    bf      .L_060221C4
    bra     .L_060227CA
    nop
.L_060221C4:
    mov r14, r0
    shll2 r0
    mov.l   .L_06022204, r3
    mov.l @(r0, r3), r0
    bra     .L_0602273C
    nop
.L_060221D0:
    cmp/gt r5, r4
    bf      .L_06022208
    mov r5, r3
    shar r3
    shar r3
    add r3, r4
    bra     .L_06022212
    nop
.L_060221E0:
    .4byte  0x03E80000
.L_060221E4:
    .4byte  fpmul
.L_060221E8:
    .4byte  sym_060896B8
.L_060221EC:
    .4byte  sym_060897D0
.L_060221F0:
    .4byte  sym_060895A0
.L_060221F4:
    .4byte  sym_0607E944
.L_060221F8:
    .4byte  sym_06089C58
.L_060221FC:
    .4byte  sym_06089E98
.L_06022200:
    .4byte  0x006A0000
.L_06022204:
    .4byte  sym_0608962C
.L_06022208:
    mov r4, r2
    shar r2
    shar r2
    mov r2, r4
    add r5, r4
.L_06022212:
    mov r14, r0
    mov.l   .L_060222E8, r2
    shll2 r0
    mov.l @(r0, r13), r3
    shll2 r3
    add r2, r3
    mov.l @r3, r3
    cmp/hi r3, r4
    bf      .L_06022304
    exts.w r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r12, r4
    mov.l @r4, r2
    mov.l r2, @(24, r15)
    mov.l @(8, r4), r3
    mov.l r3, @(32, r15)
    mov.l @(4, r4), r0
    tst r0, r0
    bf      .L_060222CE
    mov.l r8, @(28, r15)
    mov r15, r6
    add #0xC, r6
    mov.l r6, @-r15
    mov r15, r5
    add #0x1C, r5
    mov.l r5, @-r15
    mov.l @(40, r15), r5
    mov.l   .L_060222EC, r3
    jsr @r3
    mov.l @(32, r15), r4
    mov r0, r4
    mov.l @r15+, r5
    mov.l   .L_060222F0, r3
    jsr @r3
    mov.l @r15+, r6
    mov.w @(12, r15), r0
    mov #0x34, r3
    mov.l   .L_060222F4, r2
    mov r0, r4
    extu.w r4, r4
    mul.l r3, r4
    mov.l @(28, r15), r3
    sts macl, r4
    cmp/eq r8, r3
    bt/s    .L_06022280
    add r2, r4
    mov.l @r4, r0
    tst #0x80, r0
    bt      .L_0602229A
.L_06022280:
    exts.w r14, r3
    mov r3, r2
    shll2 r3
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l   .L_060222F8, r1
    mov.l r1, @r3
    bra     .L_060227CA
    nop
.L_0602229A:
    mov r14, r0
    mov.w   .L_060222E6, r2
    mov.l @(28, r15), r3
    shll2 r0
    add r2, r3
    mov.l r3, @(28, r15)
    mov.l @(r0, r13), r0
    cmp/eq #0x3, r0
    bf      .L_060222B4
    mov.l   .L_060222FC, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
.L_060222B4:
    mov r14, r0
    shll2 r0
    mov.l @(r0, r13), r0
    cmp/eq #0x4, r0
    bt      .L_060222C2
    bra     .L_0602274C
    nop
.L_060222C2:
    mov.l   .L_06022300, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
    bra     .L_0602274C
    nop
.L_060222CE:
    exts.w r14, r2
    mov r2, r3
    shll2 r2
    shll r2
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r12, r2
    mov.l @(4, r2), r1
    bra     .L_0602274C
    mov.l r1, @(28, r15)
.L_060222E6:
    .2byte  0x0100
.L_060222E8:
    .4byte  sym_06050788
.L_060222EC:
    .4byte  sym_06006838
.L_060222F0:
    .4byte  scene_render_alt
.L_060222F4:
    .4byte  sym_060A6000
.L_060222F8:
    .4byte  0x4E200000
.L_060222FC:
    .4byte  0x00013333
.L_06022300:
    .4byte  0x0000CCCC
.L_06022304:
    mov r14, r2
    mov #0x1, r1
    shll2 r2
    mov.l r2, @r15
    mov.l   .L_060223CC, r3
    add r3, r2
    mov.l r1, @r2
    exts.w r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l r11, @(4, r3)
    mov.l @r15, r5
    mov.l   .L_060223D0, r3
    mov.l @(4, r15), r4
    add r13, r5
    mov.l @r5, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    jsr @r9
    mov.l @(12, r4), r4
    mov r0, r4
    mov.l @(4, r15), r3
    mov #0x46, r2
    mov.l @(8, r3), r3
    cmp/gt r2, r3
    bf      .L_0602237E
    mov.l   .L_060223D4, r5
    jsr @r9
    nop
    mov r14, r4
    mov.l r0, @(8, r15)
    shll2 r4
    mov.l   .L_060223D8, r3
    mov r4, r2
    mov r4, r5
    add r4, r3
    add r13, r5
    mov.l r0, @r3
    mov.l @r5, r5
    tst r5, r5
    bt/s    .L_06022372
    add r10, r2
    mov r5, r0
    cmp/eq #0x3, r0
    bt      .L_06022372
    mov r5, r0
    cmp/eq #0x4, r0
    bf      .L_06022376
.L_06022372:
    bra     .L_06022378
    mov #0x0, r3
.L_06022376:
    mov #0x4, r3
.L_06022378:
    mov.l r3, @r2
    bra     .L_06022416
    nop
.L_0602237E:
    mov.l @(4, r15), r2
    mov.l @(8, r2), r3
    mov #0x1E, r2
    cmp/gt r2, r3
    bf      .L_060223E0
    mov.l   .L_060223D4, r5
    jsr @r9
    nop
    mov.l r0, @(8, r15)
    mov r14, r3
    shll2 r3
    mov.l r3, @r15
    mov.l   .L_060223D8, r2
    add r2, r3
    mov.l r3, @-r15
    mov.l   .L_060223DC, r5
    mov.l @(8, r15), r4
    jsr @r9
    mov.l @(12, r4), r4
    mov.l @r15+, r3
    mov.l r0, @r3
    mov.l @r15, r2
    mov.l @r15, r4
    add r13, r4
    mov.l @r4, r4
    mov r4, r0
    cmp/eq #0x3, r0
    bt/s    .L_060223BE
    add r10, r2
    mov r4, r0
    cmp/eq #0x4, r0
    bf      .L_060223C2
.L_060223BE:
    bra     .L_060223C4
    mov #0xE, r3
.L_060223C2:
    mov #0x4, r3
.L_060223C4:
    mov.l r3, @r2
    bra     .L_06022416
    nop
    .2byte  0xFFFF
.L_060223CC:
    .4byte  sym_0608962C
.L_060223D0:
    .4byte  sym_06089E08
.L_060223D4:
    .4byte  0x00014CCC
.L_060223D8:
    .4byte  sym_06089744
.L_060223DC:
    .4byte  0x00030000
.L_060223E0:
    mov.l   .L_060224BC, r5
    jsr @r9
    nop
    mov r14, r4
    mov.w   DAT_060224b6, r2
    shll2 r4
    add r2, r0
    mov r4, r5
    mov.l r0, @(8, r15)
    add r13, r5
    mov.l   .L_060224C0, r3
    mov.l   .L_060224C4, r2
    add r4, r3
    mov.l r2, @r3
    mov r4, r3
    mov.l @r5, r5
    mov r5, r0
    cmp/eq #0x3, r0
    bt/s    .L_0602240E
    add r10, r3
    mov r5, r0
    cmp/eq #0x4, r0
    bf      .L_06022412
.L_0602240E:
    bra     .L_06022414
    mov #0xE, r2
.L_06022412:
    mov #0x16, r2
.L_06022414:
    mov.l r2, @r3
.L_06022416:
    mov.l @(4, r15), r4
    mov.w   .L_060224B8, r3
    mov r4, r0
    mov.l @(8, r0), r0
    mov.l @(40, r4), r4
    and #0x1, r0
    mul.l r3, r0
    mov r14, r0
    sts macl, r3
    shll2 r0
    add r3, r4
    mov.l @(r0, r13), r5
    mov.w   .L_060224BA, r3
    mov r5, r0
    add r3, r4
    cmp/eq #0x3, r0
    bt      .L_0602243E
    mov r5, r0
    cmp/eq #0x4, r0
    bf      .L_0602244A
.L_0602243E:
    mov r14, r3
    shll2 r3
    mov.l   .L_060224C0, r2
    add r2, r3
    mov.l   .L_060224C8, r1
    mov.l r1, @r3
.L_0602244A:
    exts.w r14, r3
    exts.w r11, r0
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l r3, @r15
    mov.w r0, @(20, r3)
    mov.l @r15, r3
    mov.l @(4, r15), r2
    mov.l @(40, r2), r2
    exts.w r2, r0
    mov.w r0, @(22, r3)
    mov.l @r15, r6
    mov.l @r15, r5
    mov.l   .L_060224CC, r3
    add #0x10, r6
    jsr @r3
    add #0xC, r5
    mov.l @r15, r2
    mov #0xC, r3
    add r2, r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    mov.l @(12, r5), r5
    jsr @r9
    mov.l @(12, r15), r4
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @r15, r3
    mov #0x10, r2
    add r3, r2
    mov.l r2, @-r15
    mov.l @(4, r15), r5
    mov.l @(16, r5), r5
    jsr @r9
    mov.l @(12, r15), r4
    mov.l @r15+, r3
    mov.l r0, @r3
    mov r14, r0
    shll2 r0
    mov.l @(r0, r13), r3
    tst r3, r3
    bf      .L_060224D8
    mov.l   .L_060224D0, r5
    mov.l   .L_060224D4, r3
    jsr @r3
    mov #0x0, r4
    bra     .L_060224E0
    nop

    .global DAT_060224b6
DAT_060224b6:
    .2byte  0x2000
.L_060224B8:
    .2byte  0x0380
.L_060224BA:
    .2byte  0xFE40
.L_060224BC:
    .4byte  0x00013333
.L_060224C0:
    .4byte  sym_06089744
.L_060224C4:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_060224C8:
    .4byte  0x00018000
.L_060224CC:
    .4byte  sincos_pair
.L_060224D0:
    .4byte  0xAE110BFF
.L_060224D4:
    .4byte  sound_cmd_dispatch
.L_060224D8:
    mov.l   .L_06022598, r5
    mov.l   .L_0602259C, r3
    jsr @r3
    mov #0x0, r4
.L_060224E0:
    mov r14, r0
    mov #0x28, r2
    shll2 r0
    mov.l @(r0, r10), r3
    cmp/hs r2, r3
    bf      .L_060224F0
    bra     .L_06022660
    nop
.L_060224F0:
    mov r14, r0
    shll2 r0
    mov.l @(r0, r13), r4
    mov r4, r0
    cmp/eq #0x3, r0
    bt      .L_06022502
    mov r4, r0
    cmp/eq #0x4, r0
    bf      .L_0602250A
.L_06022502:
    mov.l @(16, r15), r3
    mov.l r3, @r15
    bra     .L_0602250E
    nop
.L_0602250A:
    mov.l   .L_060225A0, r3
    mov.l r3, @r15
.L_0602250E:
    exts.w r14, r4
    mov r15, r6
    mov r4, r3
    add #0xC, r6
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r12, r4
    mov.l @(12, r4), r2
    mov.l @r4, r3
    sub r2, r3
    mov.l r3, @r4
    mov.l @(16, r4), r2
    mov.l @(8, r4), r3
    add r2, r3
    mov.l r3, @(8, r4)
    mov.l @r4, r2
    mov.l r2, @(24, r15)
    mov.l @(8, r4), r3
    mov.l r3, @(32, r15)
    mov.l r8, @(28, r15)
    mov.l r6, @-r15
    mov r15, r5
    add #0x1C, r5
    mov.l r5, @-r15
    mov.l @(40, r15), r5
    mov.l   .L_060225A4, r3
    jsr @r3
    mov.l @(32, r15), r4
    mov r0, r4
    mov.l @r15+, r5
    mov.l   .L_060225A8, r3
    jsr @r3
    mov.l @r15+, r6
    mov.w @(12, r15), r0
    mov #0x34, r3
    mov.l   .L_060225AC, r2
    mov r0, r4
    extu.w r4, r4
    mul.l r3, r4
    mov.l @(28, r15), r3
    sts macl, r4
    cmp/eq r8, r3
    bt/s    .L_06022574
    add r2, r4
    mov.l @r4, r0
    tst #0x80, r0
    bt      .L_060225B4
.L_06022574:
    exts.w r14, r3
    mov r3, r2
    shll2 r3
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l   .L_060225B0, r1
    mov.l r1, @r3
    mov r14, r4
    shll2 r4
    mov r4, r3
    add r10, r3
    mov.l r11, @r3
    bra     .L_060226D6
    nop
.L_06022598:
    .4byte  0xAE110DFF
.L_0602259C:
    .4byte  sound_cmd_dispatch
.L_060225A0:
    .4byte  sym_06089B18
.L_060225A4:
    .4byte  sym_06006838
.L_060225A8:
    .4byte  scene_render_alt
.L_060225AC:
    .4byte  sym_060A6000
.L_060225B0:
    .4byte  0x4E200000
.L_060225B4:
    mov r14, r0
    shll2 r0
    mov.l r0, @(8, r15)
    mov.l @(r0, r10), r5
    mov.l @r15, r3
    mov.l @(8, r15), r4
    shll2 r5
    shll r5
    add r3, r5
    mov.l @r5, r5
    mov.l   .L_06022654, r3
    add r3, r4
    jsr @r9
    mov.l @r4, r4
    mov.l @(28, r15), r3
    add r0, r3
    mov.l r3, @(28, r15)
    mov.w   .L_06022652, r3
    mov.l @(28, r15), r2
    add r3, r2
    mov.l r2, @(28, r15)
    mov.l @(8, r15), r0
    mov.l @(r0, r13), r0
    cmp/eq #0x3, r0
    bf      .L_060225EE
    mov.l   .L_06022658, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
.L_060225EE:
    mov r14, r0
    shll2 r0
    mov.l @(r0, r13), r0
    cmp/eq #0x4, r0
    bf      .L_06022600
    mov.l   .L_0602265C, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
.L_06022600:
    exts.w r14, r4
    mov r14, r5
    mov.l @r15, r1
    mov r4, r3
    shll2 r5
    shll2 r4
    shll2 r3
    add r10, r5
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    mov.l @r5, r3
    add r12, r4
    shll2 r3
    mov.w @(20, r4), r0
    shll r3
    mov r0, r2
    add r1, r3
    mov.w @(4, r3), r0
    mov r0, r3
    add r3, r2
    exts.w r2, r0
    mov.w r0, @(20, r4)
    mov.w @(22, r4), r0
    mov.l @r5, r2
    mov r0, r3
    shll2 r2
    shll r2
    mov.l @r15, r1
    add r1, r2
    mov.w @(6, r2), r0
    mov r0, r2
    add r2, r3
    exts.w r3, r0
    mov.w r0, @(22, r4)
    mov.l @r5, r3
    add #0x1, r3
    mov.l r3, @r5
    bra     .L_0602271A
    nop
.L_06022652:
    .2byte  0x0100
.L_06022654:
    .4byte  sym_06089744
.L_06022658:
    .4byte  0x00013333
.L_0602265C:
    .4byte  0x0000CCCC
.L_06022660:
    exts.w r14, r4
    mov r15, r6
    mov r4, r3
    add #0xC, r6
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r12, r4
    mov.l @r4, r2
    mov.l r2, @(24, r15)
    mov.l @(8, r4), r3
    mov.l r3, @(32, r15)
    mov.l r8, @(28, r15)
    mov.l r6, @-r15
    mov r15, r5
    add #0x1C, r5
    mov.l r5, @-r15
    mov.l @(40, r15), r5
    mov.l   .L_06022720, r3
    jsr @r3
    mov.l @(32, r15), r4
    mov r0, r4
    mov.l @r15+, r5
    mov.l   .L_06022724, r3
    jsr @r3
    mov.l @r15+, r6
    mov #0x34, r3
    mov.l   .L_06022728, r2
    mov.w @(12, r15), r0
    mov r0, r4
    extu.w r4, r4
    mul.l r3, r4
    mov.l @(28, r15), r3
    sts macl, r4
    cmp/eq r8, r3
    bt/s    .L_060226B6
    add r2, r4
    mov.l @r4, r0
    tst #0x80, r0
    bt      .L_060226DE
.L_060226B6:
    exts.w r14, r3
    mov r3, r2
    shll2 r3
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l   .L_0602272C, r1
    mov.l r1, @r3
    mov r14, r4
    shll2 r4
    mov r4, r3
    add r10, r3
    mov.l r11, @r3
.L_060226D6:
    mov.l   .L_06022730, r2
    add r2, r4
    bra     .L_060227CA
    mov.l r11, @r4
.L_060226DE:
    mov r14, r0
    mov.w   .L_0602271E, r2
    mov.l @(28, r15), r3
    shll2 r0
    add r2, r3
    mov.l r3, @(28, r15)
    mov.l @(r0, r13), r0
    cmp/eq #0x3, r0
    bf      .L_060226F8
    mov.l   .L_06022734, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
.L_060226F8:
    mov r14, r0
    shll2 r0
    mov.l @(r0, r13), r0
    cmp/eq #0x4, r0
    bf      .L_0602270A
    mov.l   .L_06022738, r2
    mov.l @(28, r15), r3
    add r2, r3
    mov.l r3, @(28, r15)
.L_0602270A:
    mov r14, r4
    shll2 r4
    mov r4, r3
    add r10, r3
    mov.l r11, @r3
    mov.l   .L_06022730, r2
    add r2, r4
    mov.l r11, @r4
.L_0602271A:
    bra     .L_0602274C
    nop
.L_0602271E:
    .2byte  0x0100
.L_06022720:
    .4byte  sym_06006838
.L_06022724:
    .4byte  scene_render_alt
.L_06022728:
    .4byte  sym_060A6000
.L_0602272C:
    .4byte  0x4E200000
.L_06022730:
    .4byte  sym_0608962C
.L_06022734:
    .4byte  0x00013333
.L_06022738:
    .4byte  0x0000CCCC
.L_0602273C:
    cmp/eq #0x0, r0
    bf      .L_06022744
    bra     .L_060221D0
    nop
.L_06022744:
    cmp/eq #0x1, r0
    bf      .L_0602274C
    bra     .L_060224E0
    nop
.L_0602274C:
    mov.l   .L_060227F0, r3
    jsr @r3
    nop
    mov.l @(32, r15), r6
    mov.l @(28, r15), r5
    mov.l   .L_060227F4, r3
    jsr @r3
    mov.l @(24, r15), r4
    exts.w r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r12, r4
    mov.l r4, @r15
    mov.w @(22, r4), r0
    mov.l   .L_060227F8, r3
    jsr @r3
    mov r0, r4
    mov.l @r15, r4
    mov.l   .L_060227FC, r3
    mov.w @(20, r4), r0
    jsr @r3
    mov r0, r4
    mov r14, r5
    shll2 r5
    add r13, r5
    mov.l r5, @r15
    mov.l @r5, r5
    shll2 r5
    mov.l r5, @(8, r15)
    mov.l   .L_06022800, r3
    mov.l   .L_06022804, r4
    mov.l   .L_06022808, r2
    add r3, r5
    mov.l @r5, r5
    mov.l @(8, r15), r3
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov.l @r15, r3
    mov.l @r3, r3
    shll2 r3
    mov.l r3, @(8, r15)
    mov.l   .L_0602280C, r2
    add r2, r3
    mov.l @r3, r1
    mov.l r1, @r15
    mov.l   .L_06022810, r6
    mov.l @(8, r15), r3
    mov.l @(20, r15), r5
    mov.l   .L_06022814, r2
    add r3, r6
    mov.w @r5, r5
    mov.l @r6, r6
    jsr @r2
    mov r1, r4
    mov.l   .L_06022818, r3
    jsr @r3
    nop
.L_060227CA:
    add #0x1, r14
.L_060227CC:
    mov.l   .L_0602281C, r2
    mov.l @r2, r2
    cmp/hs r2, r14
    bt      .L_060227D8
    bra     .L_06022172
    nop
.L_060227D8:
    add #0x24, r15
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
    .2byte  0xFFFF
.L_060227F0:
    .4byte  sym_06026DBC
.L_060227F4:
    .4byte  sym_06026E2E
.L_060227F8:
    .4byte  mat_rot_y
.L_060227FC:
    .4byte  mat_rot_x
.L_06022800:
    .4byte  sym_06089DB4
.L_06022804:
    .4byte  sym_06089D98
.L_06022808:
    .4byte  sym_06031D8C
.L_0602280C:
    .4byte  sym_06089DD0
.L_06022810:
    .4byte  sym_06089DEC
.L_06022814:
    .4byte  sym_06031A28
.L_06022818:
    .4byte  sym_06026DF8
.L_0602281C:
    .4byte  sym_06089E24
