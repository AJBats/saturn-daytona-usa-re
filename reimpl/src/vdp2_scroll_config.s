
    .section .text.FUN_06018320


    .global vdp2_scroll_config
    .type vdp2_scroll_config, @function
vdp2_scroll_config:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_060183F4, r9
    mov.l   .L_060183F8, r10
    mov.l   .L_060183FC, r11
    mov.l   .L_06018400, r13
    mov.l   .L_06018404, r14
    mov.l   .L_06018408, r6
    mov.l   .L_0601840C, r4
    mov.b @r4, r3
    mov.b r3, @r6
    mov.l @r10, r5
    mov.w   DAT_060183ec, r0
    mov.w   DAT_060183ee, r3
    mov.l @(r0, r5), r5
    cmp/ge r3, r5
    bf/s    .L_06018358
    mov #0x0, r12
    mov.w   DAT_060183f0, r3
    cmp/gt r3, r5
    bf      .L_06018364
.L_06018358:
    mov.l r12, @r14
    mov.l r12, @(4, r14)
    mov.b r12, @r4
    mov.b r12, @r9
    bra     .L_0601858C
    mov.b r12, @r13
.L_06018364:
    mov #0x1, r7
    extu.b r7, r2
    mov.b r2, @r4
    mov.l   .L_06018410, r0
    mov.l   .L_06018414, r3
    mov.w @r0, r0
    mov.w @r3, r3
    extu.w r0, r0
    extu.w r3, r3
    and #0x40, r0
    extu.w r0, r8
    xor r8, r3
    and r8, r3
    extu.w r3, r5
    mov.l   .L_06018414, r3
    mov.w r8, @r3
    mov.l   .L_06018418, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06018394
    extu.b r7, r7
    bra     .L_060183C2
    mov.b r7, @r9
.L_06018394:
    mov.b @r4, r2
    mov.b @r6, r3
    mov.l @r10, r1
    extu.b r2, r2
    extu.b r3, r3
    mov r1, r0
    xor r3, r2
    mov.b @(3, r0), r0
    tst #0x8, r0
    .word 0x0329
    add #-0x1, r3
    neg r3, r3
    tst r3, r3
    .word 0x0029
    and r0, r2
    tst r2, r2
    bt      .L_060183C2
    mov.l   .L_0601841C, r0
    mov.l @r0, r0
    tst #0x3F, r0
    bf      .L_060183C2
    extu.b r7, r7
    mov.b r7, @r9
.L_060183C2:
    mov.l   .L_06018420, r4
    mov.l   .L_06018424, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_06018476
    mov.l @r10, r3
    mov.l @(8, r3), r0
    tst r0, r0
    bt      .L_060183DA
    bra     .L_06018528
    nop
.L_060183DA:
    extu.w r5, r5
    tst r5, r5
    bf      .L_060183E4
    bra     .L_06018528
    nop
.L_060183E4:
    mov.w   DAT_060183f2, r5
    mov.b @r13, r0
    bra     .L_06018466
    extu.b r0, r0

    .global DAT_060183ec
DAT_060183ec:
    .2byte  0x01EC

    .global DAT_060183ee
DAT_060183ee:
    .2byte  0x0086

    .global DAT_060183f0
DAT_060183f0:
    .2byte  0x009F

    .global DAT_060183f2
DAT_060183f2:
    .2byte  0x1000
.L_060183F4:
    .4byte  sym_0605BE35
.L_060183F8:
    .4byte  sym_0607E940
.L_060183FC:
    .4byte  0x00008000
.L_06018400:
    .4byte  sym_0605BE32
.L_06018404:
    .4byte  sym_06085FC0
.L_06018408:
    .4byte  sym_0605BE34
.L_0601840C:
    .4byte  sym_0605BE33
.L_06018410:
    .4byte  g_pad_state
.L_06018414:
    .4byte  sym_0605BE30
.L_06018418:
    .4byte  sym_0605DE3C
.L_0601841C:
    .4byte  sym_0605A010
.L_06018420:
    .4byte  0x00010000
.L_06018424:
    .4byte  sym_06085FF4
.L_06018428:
    mov.l r12, @r14
    mov.l @(4, r14), r2
    add r5, r2
    mov r2, r3
    mov.l r2, @(4, r14)
    cmp/ge r4, r3
    bf      .L_06018472
    mov.l r11, @r14
    mov.l r11, @(4, r14)
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_06018472
    nop
.L_06018444:
    mov.l r11, @r14
    mov.l @(4, r14), r2
    add r5, r2
    mov r2, r3
    mov.l r2, @(4, r14)
    mov.l   .L_06018508, r2
    cmp/ge r2, r3
    bf      .L_06018472
    mov.l r12, @r14
    mov.l r12, @(4, r14)
    mov.b @r13, r2
    add #0x1, r2
    bra     .L_06018472
    mov.b r2, @r13
.L_06018460:
    mov.l r12, @r14
    bra     .L_06018472
    mov.l r12, @(4, r14)
.L_06018466:
    cmp/eq #0x0, r0
    bt      .L_06018428
    cmp/eq #0x1, r0
    bt      .L_06018444
    bra     .L_06018460
    nop
.L_06018472:
    bra     .L_06018528
    nop
.L_06018476:
    mov.w   .L_06018504, r7
    mov.w   .L_06018506, r6
    mov.b @r13, r0
    bra     .L_06018510
    extu.b r0, r0
.L_06018480:
    mov.l r12, @r14
    mov.l r12, @(4, r14)
    mov.l @r10, r2
    mov.l @(8, r2), r0
    tst r0, r0
    bf      .L_06018528
    extu.w r5, r5
    tst r5, r5
    bt      .L_06018528
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_06018528
    nop
.L_0601849C:
    mov.l @(4, r14), r2
    add r6, r2
    mov.l r2, @(4, r14)
    mov r2, r3
    cmp/ge r4, r3
    bf      .L_06018528
    mov.l r4, @(4, r14)
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_06018528
    nop
.L_060184B4:
    mov.l @r14, r2
    add r7, r2
    mov.l r2, @r14
    mov r2, r3
    cmp/ge r11, r3
    bf      .L_06018528
    mov.l r11, @r14
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_06018528
    nop
.L_060184CC:
    mov.l @(4, r14), r2
    add r6, r2
    mov.l r2, @(4, r14)
    mov r2, r3
    mov.l   .L_0601850C, r4
    cmp/ge r4, r3
    bf      .L_06018528
    mov.l r4, @(4, r14)
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_06018528
    nop
.L_060184E6:
    mov.l @r14, r2
    add r7, r2
    mov r2, r3
    mov.l r2, @r14
    cmp/ge r4, r3
    bf      .L_06018528
    mov.l r12, @r14
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_06018528
    nop
.L_060184FE:
    mov.l r12, @r14
    bra     .L_06018528
    mov.l r12, @(4, r14)
.L_06018504:
    .2byte  0x0200
.L_06018506:
    .2byte  0x0100
.L_06018508:
    .4byte  0x00018000
.L_0601850C:
    .4byte  0x00020000
.L_06018510:
    cmp/eq #0x0, r0
    bt      .L_06018480
    cmp/eq #0x1, r0
    bt      .L_0601849C
    cmp/eq #0x2, r0
    bt      .L_060184B4
    cmp/eq #0x3, r0
    bt      .L_060184CC
    cmp/eq #0x4, r0
    bt      .L_060184E6
    bra     .L_060184FE
    nop
.L_06018528:
    mov.b @r9, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06018534
    mov.l r11, @r14
    mov.l r11, @(4, r14)
.L_06018534:
    mov.l   .L_060185A8, r3
    jsr @r3
    nop
    mov.l   .L_060185AC, r8
    mov.l   .L_060185B0, r3
    mov.l @(8, r8), r6
    mov.l @(4, r8), r5
    jsr @r3
    mov.l @r8, r4
    mov.l @(4, r14), r4
    mov.w   DAT_060185a0, r2
    mov.l   .L_060185B4, r3
    jsr @r3
    add r2, r4
    mov.l   .L_060185B8, r3
    jsr @r3
    mov.l @r14, r4
    mov.w   .L_060185A2, r5
    mov.l   .L_060185BC, r2
    mov.l   .L_060185C0, r3
    mov r2, r4
    add r3, r4
    mov.l   .L_060185C4, r3
    jsr @r3
    mov.l r2, @r15
    mov.w   .L_060185A4, r6
    mov.l   .L_060185C8, r5
    mov.l @r15, r4
    mov.l   .L_060185CC, r2
    mov.l   .L_060185D0, r3
    mov.w @r5, r5
    jsr @r3
    add r2, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_060185D4, r3
    jmp @r3
    mov.l @r15+, r14
.L_0601858C:
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

    .global DAT_060185a0
DAT_060185a0:
    .2byte  0x38E3
.L_060185A2:
    .2byte  0x0178
.L_060185A4:
    .2byte  0x0145
    .2byte  0xFFFF
.L_060185A8:
    .4byte  sym_06026DBC
.L_060185AC:
    .4byte  sym_06048140
.L_060185B0:
    .4byte  sym_06026E2E
.L_060185B4:
    .4byte  mat_rot_y
.L_060185B8:
    .4byte  mat_rot_x
.L_060185BC:
    .4byte  0x00200000
.L_060185C0:
    .4byte  0x000BABE0
.L_060185C4:
    .4byte  sym_06031D8C
.L_060185C8:
    .4byte  sym_06089E98
.L_060185CC:
    .4byte  0x000BBD80
.L_060185D0:
    .4byte  sym_06031A28
.L_060185D4:
    .4byte  sym_06026DF8
