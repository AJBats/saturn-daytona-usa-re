
    .section .text.FUN_060256CC


    .global scene_physics_integrate
    .type scene_physics_integrate, @function
scene_physics_integrate:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x20, r15
    mov.l   .L_0602574C, r8
    mov.w   DAT_06025746, r9
    mov.l   .L_06025750, r10
    mov.l   .L_06025754, r13
    mov.l   .L_06025758, r14
    mov.l   .L_0602575C, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bt/s    .L_060256F8
    mov #0xA, r12
    bra     .L_0602582E
    nop
.L_060256F8:
    mov.l   .L_06025760, r1
    mov.l   .L_06025764, r3
    mov.w @r1, r1
    extu.w r1, r1
    jsr @r3
    mov #0x10, r0
    mov #0x6, r2
    cmp/ge r2, r0
    bt      .L_06025720
    mov #0x0, r11
.L_0602570C:
    extu.w r9, r5
    mov.l   .L_06025768, r3
    jsr @r3
    mov r11, r4
    add #0x1, r11
    extu.w r11, r2
    cmp/ge r12, r2
    bf      .L_0602570C
    bra     .L_06025816
    nop
.L_06025720:
    mov #0x0, r11
.L_06025722:
    extu.w r9, r5
    mov.l   .L_06025768, r3
    jsr @r3
    mov r11, r4
    extu.w r11, r3
    shll2 r3
    shll r3
    mov.l r3, @(20, r15)
    add r10, r3
    mov.l r3, @(16, r15)
    mov.w @(6, r3), r0
    mov.w   .L_06025748, r2
    mov r0, r3
    extu.w r3, r3
    cmp/eq r2, r3
    bt      .L_0602576C
    bra     .L_0602576E
    mov #0x8, r2

    .global DAT_06025746
DAT_06025746:
    .2byte  0x00A9
.L_06025748:
    .2byte  0x00B4
    .2byte  0xFFFF
.L_0602574C:
    .4byte  sym_06063750
.L_06025750:
    .4byte  sym_06060F2C
.L_06025754:
    .4byte  sym_06089ECC
.L_06025758:
    .4byte  sym_06089ED0
.L_0602575C:
    .4byte  sym_06061199
.L_06025760:
    .4byte  sym_06089EC6
.L_06025764:
    .4byte  sym_06035C2C
.L_06025768:
    .4byte  car_physics_final
.L_0602576C:
    mov #0x9, r2
.L_0602576E:
    extu.w r2, r2
    extu.w r11, r6
    mov r2, r0
    mov.w r0, @(8, r15)
    mov.l @(20, r15), r7
    mov.l   .L_0602583C, r3
    add r3, r7
    mov.l r7, @r15
    mov.l @r7, r7
    shll2 r7
    shll r7
    add r8, r7
    mov.l r7, @(4, r15)
    mov.l @(4, r7), r7
    mov.l   .L_06025840, r3
    add r3, r7
    shll r6
    mov.l r6, @(24, r15)
    mov.l   .L_06025844, r3
    add r3, r6
    mov.l r6, @(28, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    extu.b r6, r6
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @(28, r15), r2
    mov.b @r2, r2
    extu.b r2, r2
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l @r5, r5
    add #0x4, r4
    mov.l r4, @(12, r15)
    mov.l @r4, r4
    mov.l   .L_06025848, r3
    jsr @r3
    shll2 r4
    mov.w @(8, r15), r0
    mov r8, r2
    mov.l @(16, r15), r3
    mov r0, r7
    extu.w r7, r7
    mov.w @(6, r3), r0
    shll8 r7
    mov r0, r3
    shll2 r7
    extu.w r3, r3
    shll2 r7
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.l @(24, r15), r6
    add r3, r7
    mov.l   .L_0602584C, r3
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov.l @r15, r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @(12, r15), r4
    mov.l   .L_06025848, r3
    mov.l @r5, r5
    mov.l @r4, r4
    jsr @r3
    shll2 r4
    add #0x1, r11
    extu.w r11, r2
    cmp/ge r12, r2
    bf      .L_06025722
.L_06025816:
    mov.l   .L_06025850, r5
    mov.w @r5, r5
    extu.w r5, r4
    tst r4, r4
    bt      .L_0602582E
    mov.l   .L_06025854, r3
    and r4, r3
    tst r3, r3
    bf      .L_0602582E
    mov #0x1, r3
    mov.l   .L_06025858, r2
    mov.b r3, @r2
.L_0602582E:
    mov.l   .L_06025858, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0602585C
    bra     .L_06025BE0
    nop
.L_0602583C:
    .4byte  sym_06058FBC
.L_06025840:
    .4byte  0x00008000
.L_06025844:
    .4byte  sym_0605904C
.L_06025848:
    .4byte  sym_06028400
.L_0602584C:
    .4byte  sym_06059060
.L_06025850:
    .4byte  sym_06063D9A
.L_06025854:
    .4byte  0x0000C000
.L_06025858:
    .4byte  sym_06061199
.L_0602585C:
    mov.l   .L_0602596C, r4
    mov.w @r4, r4
    extu.w r4, r3
    tst r3, r3
    bf      .L_0602586A
    bra     .L_06025A76
    nop
.L_0602586A:
    extu.w r4, r3
    mov.l   .L_06025970, r2
    and r2, r3
    tst r3, r3
    bf      .L_06025878
    bra     .L_06025984
    nop
.L_06025878:
    extu.w r4, r3
    mov.l   .L_06025974, r2
    and r2, r3
    tst r3, r3
    bt      .L_060258F4
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov r3, r2
    mov #0xE, r3
    cmp/gt r3, r2
    bf      .L_06025894
    mov #0x0, r3
    mov.l r3, @r14
.L_06025894:
    mov.l   .L_06025978, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_060258AA
    mov.l   .L_0602597C, r0
    mov.l @r0, r0
    cmp/eq #0x4, r0
    bf      .L_060258AA
    mov #0x8, r3
    mov.l r3, @r14
.L_060258AA:
    mov.l   .L_06025978, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_060258C0
    mov.l   .L_0602597C, r0
    mov.l @r0, r0
    cmp/eq #0x2, r0
    bf      .L_060258C0
    mov #0x4, r3
    mov.l r3, @r14
.L_060258C0:
    mov.l   .L_06025980, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_060258D6
    mov.l   .L_0602597C, r0
    mov.l @r0, r0
    cmp/eq #0xA, r0
    bf      .L_060258D6
    mov #0xE, r3
    mov.l r3, @r14
.L_060258D6:
    mov.l   .L_06025980, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bt      .L_060258E4
    bra     .L_06025A1E
    nop
.L_060258E4:
    mov.l   .L_0602597C, r0
    mov.l @r0, r0
    cmp/eq #0x8, r0
    bt      .L_060258F0
    bra     .L_06025A1E
    nop
.L_060258F0:
    bra     .L_06025A1E
    mov.l r12, @r14
.L_060258F4:
    extu.w r4, r4
    mov.w   DAT_0602596a, r2
    and r2, r4
    tst r4, r4
    bt      .L_06025966
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov r3, r2
    cmp/pz r2
    bt      .L_0602590E
    mov #0xE, r2
    mov.l r2, @r14
.L_0602590E:
    mov.l   .L_06025980, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_06025924
    mov.l   .L_0602597C, r0
    mov.l @r0, r0
    cmp/eq #0xD, r0
    bf      .L_06025924
    mov #0x9, r3
    mov.l r3, @r14
.L_06025924:
    mov.l   .L_06025980, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_0602593A
    mov.l   .L_0602597C, r0
    mov.l @r0, r0
    cmp/eq #0x9, r0
    bf      .L_0602593A
    mov #0x7, r3
    mov.l r3, @r14
.L_0602593A:
    mov.l   .L_06025978, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x1, r0
    bf      .L_06025950
    mov.l   .L_0602597C, r0
    mov.l @r0, r0
    cmp/eq #0x7, r0
    bf      .L_06025950
    mov #0x3, r3
    mov.l r3, @r14
.L_06025950:
    mov.l   .L_06025978, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_06025966
    mov.l   .L_0602597C, r0
    mov.l @r0, r0
    cmp/eq #0x3, r0
    bf      .L_06025966
    mov #0x1, r3
    mov.l r3, @r14
.L_06025966:
    bra     .L_06025A1E
    nop

    .global DAT_0602596a
DAT_0602596a:
    .2byte  0x4000
.L_0602596C:
    .4byte  sym_06063D9A
.L_06025970:
    .4byte  0x0000C000
.L_06025974:
    .4byte  0x00008000
.L_06025978:
    .4byte  sym_06089ED6
.L_0602597C:
    .4byte  sym_06089ED0
.L_06025980:
    .4byte  sym_06089ED4
.L_06025984:
    extu.w r4, r2
    mov.w   DAT_06025a80, r3
    and r3, r2
    tst r2, r2
    bt      .L_060259B6
    mov #0x5, r3
    mov.l   .L_06025A84, r2
    mov.b r3, @r2
    mov #0x12, r3
    mov.l   .L_06025A88, r2
    mov.w r3, @r2
    mov #0x0, r3
    mov.l   .L_06025A8C, r2
    mov.b r3, @r2
    mov #0x4, r4
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xAC, 0x37    /* bra scene_process_a (external) */
    mov.l @r15+, r14
.L_060259B6:
    mov #0x0, r5
.L_060259B8:
    extu.w r5, r2
    extu.w r4, r1
    mov.l   .L_06025A90, r3
    shll r2
    add r3, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r1, r2
    tst r2, r2
    bt      .L_060259D0
    bra     .L_060259D8
    nop
.L_060259D0:
    add #0x1, r5
    extu.w r5, r2
    cmp/ge r12, r2
    bf      .L_060259B8
.L_060259D8:
    extu.w r5, r5
    mov.l r5, @r13
    .byte   0xB4, 0x70    /* bsr transform_heading_apply (external) */
    mov r5, r4
    mov #0x0, r4
.L_060259E2:
    extu.b r4, r2
    mov.l   .L_06025A94, r1
    mov r2, r3
    shll2 r2
    shll2 r3
    shll r3
    add r3, r2
    extu.b r2, r2
    add r1, r2
    mov.w @(8, r2), r0
    mov r0, r3
    mov.l @r13, r2
    extu.w r3, r3
    shll2 r2
    shll r2
    add r10, r2
    mov.w @(6, r2), r0
    mov r0, r1
    extu.w r1, r1
    cmp/eq r1, r3
    bf      .L_06025A10
    bra     .L_06025A1A
    nop
.L_06025A10:
    add #0x1, r4
    mov #0xE, r3
    extu.w r4, r2
    cmp/ge r3, r2
    bf      .L_060259E2
.L_06025A1A:
    extu.w r4, r4
    mov.l r4, @r14
.L_06025A1E:
    mov.l @r13, r3
    mov.l @r14, r2
    mov.l   .L_06025A94, r0
    shll2 r3
    extu.b r2, r2
    shll r3
    mov r2, r1
    add r10, r3
    shll2 r2
    shll2 r1
    shll r1
    add r1, r2
    extu.b r2, r2
    add r0, r2
    mov.l @(4, r2), r1
    mov.l r1, @r3
    mov.l @r13, r3
    mov.l @r13, r2
    mov.l   .L_06025A90, r1
    shll2 r3
    shll r2
    shll r3
    add r1, r2
    add r10, r3
    mov.w @r2, r0
    mov.w r0, @(4, r3)
    mov.l @r13, r3
    shll2 r3
    shll r3
    add r10, r3
    mov.l @r14, r2
    extu.b r2, r2
    mov.l   .L_06025A94, r0
    mov r2, r1
    shll2 r2
    shll2 r1
    shll r1
    add r1, r2
    extu.b r2, r2
    add r0, r2
    mov.w @(8, r2), r0
    mov.w r0, @(6, r3)
    .byte   0xBB, 0xD7    /* bsr scene_process_a (external) */
    mov #0x4, r4
.L_06025A76:
    mov.l @r13, r2
    cmp/pz r2
    bt      .L_06025A98
    bra     .L_06025BE0
    nop

    .global DAT_06025a80
DAT_06025a80:
    .2byte  0x0800
    .2byte  0xFFFF
.L_06025A84:
    .4byte  sym_06061198
.L_06025A88:
    .4byte  sym_06089EDA
.L_06025A8C:
    .4byte  sym_06061199
.L_06025A90:
    .4byte  sym_06059094
.L_06025A94:
    .4byte  sym_060610BC
.L_06025A98:
    mov.l   .L_06025BBC, r1
    mov.l   .L_06025BC0, r3
    mov.w @r1, r1
    extu.w r1, r1
    jsr @r3
    mov #0x10, r0
    mov #0x6, r2
    cmp/ge r2, r0
    bt      .L_06025AC6
    extu.w r9, r5
    mov.l @r13, r4
    extu.w r4, r4
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_06025BC4, r3
    jmp @r3
    mov.l @r15+, r14
.L_06025AC6:
    mov.l @r14, r3
    mov.l   .L_06025BC8, r1
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r2
    add r2, r3
    extu.b r3, r3
    mov.w   .L_06025BB8, r2
    add r1, r3
    mov.w @(8, r3), r0
    mov r0, r3
    extu.w r3, r3
    cmp/eq r2, r3
    bt      .L_06025AEA
    bra     .L_06025AEC
    mov #0x8, r2
.L_06025AEA:
    mov #0x9, r2
.L_06025AEC:
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(4, r15)
    mov.l @r13, r7
    mov.l   .L_06025BCC, r3
    shll2 r7
    shll r7
    add r3, r7
    mov.l r7, @r15
    mov.l @r7, r7
    shll2 r7
    shll r7
    add r8, r7
    mov.l r7, @(8, r15)
    mov.l @(4, r7), r7
    mov.l   .L_06025BD0, r3
    mov.l @r13, r6
    add r3, r7
    shll r6
    mov.l   .L_06025BD4, r3
    add r3, r6
    mov.l r6, @(12, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    extu.b r6, r6
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @(12, r15), r2
    mov.b @r2, r2
    extu.b r2, r2
    add r2, r6
    mov.l @(8, r15), r5
    mov.l @r15, r4
    mov.l   .L_06025BD8, r3
    shll r6
    mov.l @r5, r5
    mov.l @(4, r4), r4
    jsr @r3
    shll2 r4
    mov.w @(4, r15), r0
    mov.l @r14, r3
    mov r0, r7
    extu.b r3, r3
    extu.w r7, r7
    mov r3, r2
    shll8 r7
    shll2 r2
    shll2 r3
    shll2 r7
    shll r3
    shll2 r7
    add r3, r2
    extu.b r2, r2
    mov.l   .L_06025BC8, r3
    add r2, r3
    mov.w @(8, r3), r0
    mov r0, r2
    extu.w r2, r3
    shll2 r3
    mov r8, r2
    shll r3
    add r3, r2
    mov.l r2, @r15
    mov.l @(4, r2), r3
    mov.l @r13, r6
    add r3, r7
    shll r6
    mov.l   .L_06025BDC, r3
    add r3, r6
    mov.l r6, @(8, r15)
    mov.b @(1, r6), r0
    mov r0, r6
    mov.l @(8, r15), r2
    mov.l @r15, r5
    mov.l @r13, r4
    extu.b r6, r6
    mov.b @r2, r2
    mov.l @r5, r5
    shll2 r4
    shll2 r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    shll r4
    mov.l   .L_06025BCC, r3
    add r3, r4
    mov.l @(4, r4), r4
    shll2 r4
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_06025BD8, r2
    jmp @r2
    mov.l @r15+, r14
.L_06025BB8:
    .2byte  0x00B4
    .2byte  0xFFFF
.L_06025BBC:
    .4byte  sym_06089EC6
.L_06025BC0:
    .4byte  sym_06035C2C
.L_06025BC4:
    .4byte  car_physics_final
.L_06025BC8:
    .4byte  sym_060610BC
.L_06025BCC:
    .4byte  sym_06058FBC
.L_06025BD0:
    .4byte  0x00008000
.L_06025BD4:
    .4byte  sym_0605904C
.L_06025BD8:
    .4byte  sym_06028400
.L_06025BDC:
    .4byte  sym_06059060
.L_06025BE0:
    add #0x20, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
