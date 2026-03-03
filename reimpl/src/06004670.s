	.text
    .global obj_template_init
obj_template_init:
    mov.l r14, @-r15
    mov #0x0, r14
    mov.l r13, @-r15
    mov r14, r6
    mov r14, r3
    mov r14, r13
    mov.l r11, @-r15
    add #0x1, r6
    shll2 r3
    shll2 r13
    sts.l macl, @-r15
    add #-0x4, r15
    mov.l   .L_pool_060047D8, r7
    shll r3
    add r3, r13
    add r7, r13
    mov.l   .L_pool_060047DC, r2
    mov.l r2, @r15
    mov r2, r3
    mov.l r2, @r13
    mov.w   DAT_060047d2, r0
    mov.w r0, @(4, r13)
    mov #0x1, r4
    exts.b r4, r0
    mov.b r0, @(6, r13)
    mov #0x2, r5
    exts.b r5, r0
    mov.b r0, @(7, r13)
    exts.b r4, r0
    mov.b r0, @(9, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(9, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    neg r3, r3
    add #0x40, r3
    shll r3
    exts.w r3, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    add #0x1, r6
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov.l @r15, r2
    mov.l r2, @r13
    mov.w   DAT_060047d2, r0
    mov.w r0, @(4, r13)
    exts.b r4, r0
    mov.b r0, @(6, r13)
    exts.b r5, r0
    mov.b r0, @(7, r13)
    exts.b r5, r0
    mov.b r0, @(9, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(9, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    neg r3, r3
    add #0x40, r3
    shll r3
    exts.w r3, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    add #0x1, r6
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov #0x3, r11
    mov.l   .L_pool_060047E0, r2
    mov.l r2, @r13
    mov.w   DAT_060047d4, r1
    exts.w r1, r0
    mov.w r0, @(4, r13)
    exts.b r5, r0
    mov.b r0, @(6, r13)
    exts.b r5, r0
    mov.b r0, @(7, r13)
    exts.b r11, r0
    mov.b r0, @(9, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(9, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    neg r3, r3
    add #0x40, r3
    shll r3
    exts.w r3, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    exts.w r1, r0
    mov.l   .L_pool_060047E4, r2
    add #0x1, r6
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov.l r2, @r13
    mov.w r0, @(4, r13)
    exts.b r5, r0
    mov.b r0, @(6, r13)
    exts.b r5, r0
    mov.b r0, @(7, r13)
    exts.b r11, r0
    mov.b r0, @(9, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(9, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    neg r3, r3
    add #0x40, r3
    shll r3
    exts.w r3, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    add #0x1, r6
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov.l   .L_pool_060047E8, r2
    bra     .L_060047EC
    nop

    .global DAT_060047d2
DAT_060047d2:
    .short  0x2080

    .global DAT_060047d4
DAT_060047d4:
    .short  0x1080
    .short  0xFFFF
.L_pool_060047D8:
    .long  sym_06063690
.L_pool_060047DC:
    .long  sym_06042CEE
.L_pool_060047E0:
    .long  sym_06042D72
.L_pool_060047E4:
    .long  sym_06042D1A
.L_pool_060047E8:
    .long  sym_06042DCA
.L_060047EC:
    mov.l r2, @r13
    exts.w r1, r0
    mov.w r0, @(4, r13)
    exts.b r5, r0
    mov.b r0, @(6, r13)
    exts.b r11, r0
    mov.b r0, @(7, r13)
    exts.b r5, r0
    mov.b r0, @(9, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(9, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    neg r3, r3
    add #0x40, r3
    shll r3
    exts.w r3, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    add #0x1, r6
    mov r13, r3
    mov.l   .L_pool_06004990, r11
    exts.w r1, r0
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov.l r11, @r13
    mov.w r0, @(4, r13)
    exts.b r4, r0
    mov.b r0, @(6, r13)
    exts.b r4, r0
    mov.b r0, @(7, r13)
    exts.b r5, r0
    mov.b r0, @(9, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(9, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    neg r3, r3
    add #0x40, r3
    shll r3
    exts.w r3, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    add #0x1, r6
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov.l   .L_pool_06004994, r2
    mov.l r2, @r15
    mov r2, r3
    mov.l r2, @r13
    exts.w r1, r0
    mov.w r0, @(4, r13)
    exts.b r4, r0
    mov.b r0, @(6, r13)
    exts.b r4, r0
    mov.b r0, @(7, r13)
    exts.b r14, r0
    mov.b r0, @(9, r13)
    exts.w r14, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    mov.l @r15, r2
    add #0x1, r6
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov.l r2, @r13
    mov.w   DAT_0600498a, r0
    mov.w r0, @(4, r13)
    exts.b r4, r0
    mov.b r0, @(6, r13)
    exts.b r4, r0
    mov.b r0, @(7, r13)
    exts.b r14, r0
    mov.b r0, @(9, r13)
    exts.w r14, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    mov.l   .L_pool_06004998, r2
    add #0x1, r6
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov.l r2, @r13
    mov.w   DAT_0600498c, r0
    mov.w r0, @(4, r13)
    exts.b r5, r0
    mov.b r0, @(6, r13)
    exts.b r5, r0
    mov.b r0, @(7, r13)
    mov #0x20, r0
    mov.b r0, @(9, r13)
    exts.w r14, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    add #0x1, r6
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov.l r11, @r13
    mov.w   DAT_0600498e, r0
    mov.w r0, @(4, r13)
    exts.b r4, r0
    mov.b r0, @(6, r13)
    exts.b r4, r0
    mov.b r0, @(7, r13)
    exts.b r4, r0
    mov.b r0, @(9, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(9, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    neg r3, r3
    add #0x40, r3
    shll r3
    exts.w r3, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    add #0x1, r6
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov.l   .L_pool_0600499C, r2
    mov.l r2, @r13
    mov.w   DAT_0600498c, r0
    mov.w r0, @(4, r13)
    bra     .L_060049A0
    nop

    .global DAT_0600498a
DAT_0600498a:
    .short  0x0080

    .global DAT_0600498c
DAT_0600498c:
    .short  0xD116

    .global DAT_0600498e
DAT_0600498e:
    .short  0x7080
.L_pool_06004990:
    .long  sym_06042CBC
.L_pool_06004994:
    .long  sym_06042CD2
.L_pool_06004998:
    .long  sym_06042E4E
.L_pool_0600499C:
    .long  sym_0604304E
.L_060049A0:
    exts.b r5, r0
    mov.b r0, @(6, r13)
    exts.b r5, r0
    mov.b r0, @(7, r13)
    exts.b r14, r0
    mov.b r0, @(9, r13)
    exts.w r14, r0
    mov.w r0, @(10, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    mov.b @(7, r13), r0
    mov r0, r2
    muls r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    add #0x1, r6
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r3
    add r3, r13
    add r7, r13
    mov.l r11, @r13
    mov.w   DAT_06004a88, r0
    mov.w r0, @(4, r13)
    exts.b r4, r0
    mov.b r0, @(6, r13)
    exts.b r4, r0
    mov.b r0, @(7, r13)
    exts.b r4, r0
    mov.b r0, @(9, r13)
    mov.b @(6, r13), r0
    mov r0, r3
    .long  0x84D96203
    .long  0x232F031A
    .long  0x633B7340
    .long  0x4300603F
    .long  0x81D584D6
    .long  0x630384D7
    .long  0x6203232F
    .long  0x031A4300
    .long  0x603E80D8
    .long  0x6D637601
    .long  0x63D34D08
    .long  0x43084300
    .long  0x3D3C3D7C
    .long  0xD21C2D22
    .long  0x903381D2
    .long  0x604E80D6
    .long  0x605E80D7
    .long  0xE02080D9
    .long  0x60EF81D5
    .long  0x84D66303
    .long  0x84D76203
    .long  0x232F031A
    .long  0x4300603E
    .long  0x636380D8
    .long  0x46084308
    .long  0x4300363C
    .long  0x367CD210
    .long  0x26229019
    .long  0x8162604E
    .long  0x8066605E
    .long  0x806760EE
    .long  0x806960EF
    .long  0x81658466
    .long  0x63038467
    .long  0x6203232F
    .long  0x031A4300
    .long  0x603E8068
    .long  0x7F044F16
    .long  0x6BF66DF6
    .long  0x000B6EF6

    .global DAT_06004a88
DAT_06004a88:
    .short  0x0080

    .global DAT_06004a8a
DAT_06004a8a:
    .short  0x01F7

    .global DAT_06004a8c
DAT_06004a8c:
    .long  0x91F7FFFF
    .long  sym_06059CC0
    .long  sym_06059DC0
