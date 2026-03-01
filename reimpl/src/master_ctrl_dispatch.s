
    .section .text.FUN_0601C3E4


    .global master_ctrl_dispatch
    .type master_ctrl_dispatch, @function
master_ctrl_dispatch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601C44C, r8
    mov.l   .L_0601C450, r9
    mov.l   .L_0601C454, r10
    mov.l   .L_0601C458, r11
    mov.l   .L_0601C45C, r12
    mov.l   .L_0601C460, r14
    mov.l   .L_0601C464, r0
    mov.l @r0, r0
    tst r0, r0
    bt/s    .L_0601C416
    mov.l @r14, r14
    mov.l   .L_0601C468, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601C470
.L_0601C416:
    mov r13, r0
    mov.w   .L_0601C442, r1
    mov.l   .L_0601C46C, r3
    jsr @r3
    mov r14, r2
    mov r13, r0
    mov.w   .L_0601C444, r1
    mov.l   .L_0601C46C, r3
    jsr @r3
    mov r14, r2
    mov r13, r0
    mov.w   .L_0601C446, r1
    mov.l   .L_0601C46C, r3
    jsr @r3
    mov r14, r2
    mov r13, r0
    mov.w   .L_0601C448, r1
    mov.l   .L_0601C46C, r3
    jsr @r3
    mov r14, r2
    bra     .L_0601C928
    nop
.L_0601C442:
    .2byte  0x1901
.L_0601C444:
    .2byte  0x1801
.L_0601C446:
    .2byte  0x1701
.L_0601C448:
    .2byte  0x1601
    .2byte  0xFFFF
.L_0601C44C:
    .4byte  sym_0605DF44
.L_0601C450:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_0601C454:
    .4byte  sym_0608A52C
.L_0601C458:
    .4byte  sym_0605DF57
.L_0601C45C:
    .4byte  sym_0605DF56
.L_0601C460:
    .4byte  sym_0607E944
.L_0601C464:
    .4byte  sym_06063E1C
.L_0601C468:
    .4byte  sym_06063E20
.L_0601C46C:
    .4byte  sym_06034F78
.L_0601C470:
    mov r14, r0
    mov.b @(3, r0), r0
    tst #0x40, r0
    bt      .L_0601C488
    mov #0x8, r3
    mov.l   .L_0601C514, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_0601C508, r1
    mov.l   .L_0601C518, r3
    jsr @r3
    mov r14, r2
.L_0601C488:
    mov r14, r0
    mov.b @(3, r0), r0
    tst #0x80, r0
    bt      .L_0601C4A0
    mov #0x8, r3
    mov.l   .L_0601C51C, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_0601C50A, r1
    mov.l   .L_0601C518, r3
    jsr @r3
    mov r14, r2
.L_0601C4A0:
    mov r14, r0
    mov.b @(2, r0), r0
    tst #0x1, r0
    bt      .L_0601C4B8
    mov #0x8, r3
    mov.l   .L_0601C520, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_0601C50C, r1
    mov.l   .L_0601C518, r3
    jsr @r3
    mov r14, r2
.L_0601C4B8:
    mov r14, r0
    mov.b @(2, r0), r0
    tst #0x2, r0
    bt      .L_0601C4D0
    mov #0x8, r3
    mov.l   .L_0601C524, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_0601C50E, r1
    mov.l   .L_0601C518, r3
    jsr @r3
    mov r14, r2
.L_0601C4D0:
    mov.l   .L_0601C514, r2
    mov.w @r2, r2
    extu.w r2, r2
    cmp/pl r2
    bf      .L_0601C5BC
    mov.l   .L_0601C528, r3
    jsr @r3
    nop
    mov.l   .L_0601C52C, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601C544
    mov.l   .L_0601C530, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601C544
    mov.l   .L_0601C534, r6
    mov.l   .L_0601C538, r4
    mov.l   .L_0601C53C, r3
    jsr @r3
    mov r9, r5
    mov.w   DAT_0601c510, r6
    mov.l   .L_0601C540, r3
    mov r6, r5
    jsr @r3
    mov r6, r4
    bra     .L_0601C54E
    nop
.L_0601C508:
    .2byte  0x1901
.L_0601C50A:
    .2byte  0x1801
.L_0601C50C:
    .2byte  0x1701
.L_0601C50E:
    .2byte  0x1601

    .global DAT_0601c510
DAT_0601c510:
    .2byte  0x6666
    .2byte  0xFFFF
.L_0601C514:
    .4byte  sym_0605DF4E
.L_0601C518:
    .4byte  sym_06034F78
.L_0601C51C:
    .4byte  sym_0605DF50
.L_0601C520:
    .4byte  sym_0605DF52
.L_0601C524:
    .4byte  sym_0605DF54
.L_0601C528:
    .4byte  sym_06027080
.L_0601C52C:
    .4byte  sym_06063E1C
.L_0601C530:
    .4byte  sym_06063E20
.L_0601C534:
    .4byte  0xFFFE4000                  /* -1.75 (16.16 fixed-point) */
.L_0601C538:
    .4byte  0x00014872                  /* 1.28 (16.16 fixed-point) */
.L_0601C53C:
    .4byte  sym_060270F2
.L_0601C540:
    .4byte  mat_scale_b
.L_0601C544:
    mov.l   .L_0601C5FC, r6
    mov.l   .L_0601C600, r4
    mov.l   .L_0601C604, r3
    jsr @r3
    mov r9, r5
.L_0601C54E:
    mov.w   DAT_0601c5f8, r4
    mov.l   .L_0601C608, r3
    jsr @r3
    nop
    mov.b @r12, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0601C60C, r3
    mov.l @r15, r4
    mov.l   .L_0601C610, r2
    mov.l   .L_0601C614, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r12, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0601C618, r3
    mov.l   .L_0601C61C, r5
    mov.l @r15, r4
    mov.l   .L_0601C620, r2
    mov.l   .L_0601C624, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.l @r10, r3
    add #-0x30, r3
    mov.l r3, @r10
    mov.b @r12, r2
    add #0x1, r2
    mov.b r2, @r12
    mov.b @r12, r3
    mov #0x3, r2
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_0601C5AE
    extu.b r13, r2
    mov.b r2, @r12
.L_0601C5AE:
    mov.l   .L_0601C628, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_0601C628, r2
    mov.w r3, @r2
    bra     .L_0601C838
    nop
.L_0601C5BC:
    mov.l   .L_0601C62C, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/pl r3
    bt      .L_0601C5CA
    bra     .L_0601C6F4
    nop
.L_0601C5CA:
    mov.l   .L_0601C630, r3
    jsr @r3
    nop
    mov.l   .L_0601C634, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601C648
    mov.l   .L_0601C638, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601C648
    mov.l   .L_0601C63C, r6
    mov.l   .L_0601C640, r4
    mov.l   .L_0601C604, r3
    jsr @r3
    mov r9, r5
    mov.w   DAT_0601c5fa, r6
    mov.l   .L_0601C644, r3
    mov r6, r5
    jsr @r3
    mov r6, r4
    bra     .L_0601C652
    nop

    .global DAT_0601c5f8
DAT_0601c5f8:
    .2byte  0x1000

    .global DAT_0601c5fa
DAT_0601c5fa:
    .2byte  0x6666
.L_0601C5FC:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_0601C600:
    .4byte  0x00014872                  /* 1.28 (16.16 fixed-point) */
.L_0601C604:
    .4byte  sym_060270F2
.L_0601C608:
    .4byte  mat_rot_xy_b
.L_0601C60C:
    .4byte  sym_060621D8
.L_0601C610:
    .4byte  sym_0606212C
.L_0601C614:
    .4byte  sym_06032158
.L_0601C618:
    .4byte  sym_06062180
.L_0601C61C:
    .4byte  sym_06089E9C
.L_0601C620:
    .4byte  sym_060620D8
.L_0601C624:
    .4byte  sym_06031DF4
.L_0601C628:
    .4byte  sym_0605DF4E
.L_0601C62C:
    .4byte  sym_0605DF50
.L_0601C630:
    .4byte  sym_06027080
.L_0601C634:
    .4byte  sym_06063E1C
.L_0601C638:
    .4byte  sym_06063E20
.L_0601C63C:
    .4byte  0xFFFE4000                  /* -1.75 (16.16 fixed-point) */
.L_0601C640:
    .4byte  0xFFFEB78E                  /* -1.28 (16.16 fixed-point) */
.L_0601C644:
    .4byte  mat_scale_b
.L_0601C648:
    mov.l   .L_0601C6C4, r6
    mov.l   .L_0601C6C8, r4
    mov.l   .L_0601C6CC, r3
    jsr @r3
    mov r9, r5
.L_0601C652:
    mov.w   DAT_0601c6c0, r4
    mov.l   .L_0601C6D0, r3
    jsr @r3
    nop
    mov.b @r11, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0601C6D4, r3
    mov.l @r15, r4
    mov.l   .L_0601C6D8, r2
    mov.l   .L_0601C6DC, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r11, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0601C6E0, r3
    mov.l   .L_0601C6E4, r5
    mov.l @r15, r4
    mov.l   .L_0601C6E8, r2
    mov.l   .L_0601C6EC, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.l @r10, r3
    add #-0x30, r3
    mov.l r3, @r10
    mov.b @r11, r2
    add #0x1, r2
    mov.b r2, @r11
    mov.b @r11, r3
    mov #0x3, r2
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_0601C6B2
    extu.b r13, r2
    mov.b r2, @r11
.L_0601C6B2:
    mov.l   .L_0601C6F0, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_0601C6F0, r2
    mov.w r3, @r2
    bra     .L_0601C838
    nop

    .global DAT_0601c6c0
DAT_0601c6c0:
    .2byte  0x7000
    .2byte  0xFFFF
.L_0601C6C4:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_0601C6C8:
    .4byte  0xFFFEB78E                  /* -1.28 (16.16 fixed-point) */
.L_0601C6CC:
    .4byte  sym_060270F2
.L_0601C6D0:
    .4byte  mat_rot_xy_b
.L_0601C6D4:
    .4byte  sym_060621D8
.L_0601C6D8:
    .4byte  sym_0606212C
.L_0601C6DC:
    .4byte  sym_06032158
.L_0601C6E0:
    .4byte  sym_06062180
.L_0601C6E4:
    .4byte  sym_06089E9C
.L_0601C6E8:
    .4byte  sym_060620D8
.L_0601C6EC:
    .4byte  sym_06031DF4
.L_0601C6F0:
    .4byte  sym_0605DF50
.L_0601C6F4:
    mov.l   .L_0601C780, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/pl r3
    bf      .L_0601C7B4
    mov.l   .L_0601C784, r3
    jsr @r3
    nop
    mov.l   .L_0601C788, r6
    mov.l   .L_0601C78C, r4
    mov.l   .L_0601C790, r3
    jsr @r3
    mov r9, r5
    mov.w   DAT_0601c77c, r4
    mov.l   .L_0601C794, r3
    jsr @r3
    nop
    mov.b @r12, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0601C798, r3
    mov.l @r15, r4
    mov.l   .L_0601C79C, r2
    mov.l   .L_0601C7A0, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r12, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0601C7A4, r3
    mov.l   .L_0601C7A8, r5
    mov.l @r15, r4
    mov.l   .L_0601C7AC, r2
    mov.l   .L_0601C7B0, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.l @r10, r3
    add #-0x30, r3
    mov.l r3, @r10
    mov.b @r12, r2
    add #0x1, r2
    mov.b r2, @r12
    mov #0x3, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_0601C76E
    extu.b r13, r2
    mov.b r2, @r12
.L_0601C76E:
    mov.l   .L_0601C780, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_0601C780, r2
    mov.w r3, @r2
    bra     .L_0601C838
    nop

    .global DAT_0601c77c
DAT_0601c77c:
    .2byte  0x1000
    .2byte  0xFFFF
.L_0601C780:
    .4byte  sym_0605DF52
.L_0601C784:
    .4byte  sym_06027080
.L_0601C788:
    .4byte  0x00013333                  /* 1.2 (16.16 fixed-point) */
.L_0601C78C:
    .4byte  0x0001620C                  /* 1.38 (16.16 fixed-point) */
.L_0601C790:
    .4byte  sym_060270F2
.L_0601C794:
    .4byte  mat_rot_xy_b
.L_0601C798:
    .4byte  sym_060621D8
.L_0601C79C:
    .4byte  sym_0606212C
.L_0601C7A0:
    .4byte  sym_06032158
.L_0601C7A4:
    .4byte  sym_06062180
.L_0601C7A8:
    .4byte  sym_06089E9C
.L_0601C7AC:
    .4byte  sym_060620D8
.L_0601C7B0:
    .4byte  sym_06031DF4
.L_0601C7B4:
    mov.l   .L_0601C848, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/pl r3
    bf      .L_0601C838
    mov.l   .L_0601C84C, r3
    jsr @r3
    nop
    mov.l   .L_0601C850, r6
    mov.l   .L_0601C854, r4
    mov.l   .L_0601C858, r3
    jsr @r3
    mov r9, r5
    mov.w   DAT_0601c844, r4
    mov.l   .L_0601C85C, r3
    jsr @r3
    nop
    mov.b @r11, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0601C860, r3
    mov.l @r15, r4
    mov.l   .L_0601C864, r2
    mov.l   .L_0601C868, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r11, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0601C86C, r3
    mov.l   .L_0601C870, r5
    mov.l @r15, r4
    mov.l   .L_0601C874, r2
    mov.l   .L_0601C878, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.l @r10, r3
    add #-0x30, r3
    mov.l r3, @r10
    mov.b @r11, r2
    add #0x1, r2
    mov.b r2, @r11
    mov #0x3, r2
    mov.b @r11, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_0601C82E
    extu.b r13, r2
    mov.b r2, @r11
.L_0601C82E:
    mov.l   .L_0601C848, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_0601C848, r2
    mov.w r3, @r2
.L_0601C838:
    mov.l   .L_0601C87C, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601C880
    bra     .L_0601C928
    nop

    .global DAT_0601c844
DAT_0601c844:
    .2byte  0x7000
    .2byte  0xFFFF
.L_0601C848:
    .4byte  sym_0605DF54
.L_0601C84C:
    .4byte  sym_06027080
.L_0601C850:
    .4byte  0x00013333                  /* 1.2 (16.16 fixed-point) */
.L_0601C854:
    .4byte  0xFFFE9DF4                  /* -1.38 (16.16 fixed-point) */
.L_0601C858:
    .4byte  sym_060270F2
.L_0601C85C:
    .4byte  mat_rot_xy_b
.L_0601C860:
    .4byte  sym_060621D8
.L_0601C864:
    .4byte  sym_0606212C
.L_0601C868:
    .4byte  sym_06032158
.L_0601C86C:
    .4byte  sym_06062180
.L_0601C870:
    .4byte  sym_06089E9C
.L_0601C874:
    .4byte  sym_060620D8
.L_0601C878:
    .4byte  sym_06031DF4
.L_0601C87C:
    .4byte  sym_06059F30
.L_0601C880:
    mov.w   DAT_0601c93c, r0
    mov.w @(r0, r14), r3
    tst r3, r3
    bf      .L_0601C894
    mov.w   DAT_0601c93e, r0
    mov.w @(r0, r14), r3
    tst r3, r3
    bf      .L_0601C894
    exts.w r13, r3
    mov.w r3, @r8
.L_0601C894:
    mov.w   DAT_0601c93c, r0
    mov.w @(r0, r14), r0
    tst r0, r0
    bf      .L_0601C8A4
    mov.w   DAT_0601c93e, r0
    mov.w @(r0, r14), r0
    tst r0, r0
    bt      .L_0601C928
.L_0601C8A4:
    mov.l   .L_0601C944, r3
    jsr @r3
    nop
    mov.l   .L_0601C948, r14
    mov.l   .L_0601C94C, r3
    mov.w   .L_0601C940, r2
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    neg r6, r6
    add r2, r5
    add r3, r6
    mov.l   .L_0601C950, r3
    jsr @r3
    mov.l @r14, r4
    mov.l   .L_0601C954, r3
    jsr @r3
    mov r9, r4
    mov.w @r8, r5
    mov.l   .L_0601C958, r3
    shll r5
    add r3, r5
    mov.w @r5, r5
    add #0xE, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0601C95C, r2
    mov.l @r15, r4
    mov.l   .L_0601C960, r1
    mov.l   .L_0601C964, r3
    add r2, r5
    add r1, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.w @r8, r6
    mov.l   .L_0601C958, r3
    shll r6
    add r3, r6
    mov.w @r6, r6
    add #0xE, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0601C968, r2
    mov.l   .L_0601C96C, r5
    mov.l @r15, r4
    mov.l   .L_0601C970, r1
    mov.l   .L_0601C974, r3
    add r2, r6
    mov.w @r5, r5
    add r1, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l @r10, r2
    add #-0x30, r2
    mov.l r2, @r10
    mov.w @r8, r3
    add #0x1, r3
    mov.w r3, @r8
    mov.w @r8, r2
    mov #0x4, r3
    cmp/ge r3, r2
    bf      .L_0601C928
    exts.w r13, r3
    mov.w r3, @r8
.L_0601C928:
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

    .global DAT_0601c93c
DAT_0601c93c:
    .2byte  0x0166

    .global DAT_0601c93e
DAT_0601c93e:
    .2byte  0x0152
.L_0601C940:
    .2byte  0xCCCD                      /* -0x3333 signed = -13107 */
    .2byte  0xFFFF
.L_0601C944:
    .4byte  sym_06027080
.L_0601C948:
    .4byte  sym_06044670
.L_0601C94C:
    .4byte  0xFFFF6000                  /* -0.625 (16.16 fixed-point) */
.L_0601C950:
    .4byte  sym_060270F2
.L_0601C954:
    .4byte  mat_rot_xy_b
.L_0601C958:
    .4byte  sym_0605DF46
.L_0601C95C:
    .4byte  sym_060621D8
.L_0601C960:
    .4byte  sym_0606212C
.L_0601C964:
    .4byte  sym_06032158
.L_0601C968:
    .4byte  sym_06062180
.L_0601C96C:
    .4byte  sym_06089E9C
.L_0601C970:
    .4byte  sym_060620D8
.L_0601C974:
    .4byte  sym_06031DF4
