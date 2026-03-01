
    .section .text.FUN_06004670


    .global obj_template_init
    .type obj_template_init, @function
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
    mov.l   _pool_template_table, r7
    shll r3
    add r3, r13
    add r7, r13
    mov.l   _pool_tile_data_0, r2
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
    muls.w r2, r3
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
    muls.w r2, r3
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
    muls.w r2, r3
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
    muls.w r2, r3
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
    mov.l   _pool_tile_data_2, r2
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
    muls.w r2, r3
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
    muls.w r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    exts.w r1, r0
    mov.l   _pool_tile_data_3, r2
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
    muls.w r2, r3
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
    muls.w r2, r3
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
    mov.l   _pool_tile_data_4, r2
    bra     .L_fill_template_4
    nop

    .global DAT_060047d2
DAT_060047d2:
    .2byte  0x2080

    .global DAT_060047d4
DAT_060047d4:
    .2byte  0x1080
    .2byte  0xFFFF
_pool_template_table:
    .4byte  sym_06063690
_pool_tile_data_0:
    .4byte  sym_06042CEE
_pool_tile_data_2:
    .4byte  sym_06042D72
_pool_tile_data_3:
    .4byte  sym_06042D1A
_pool_tile_data_4:
    .4byte  sym_06042DCA
.L_fill_template_4:
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
    muls.w r2, r3
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
    muls.w r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    add #0x1, r6
    mov r13, r3
    mov.l   _pool_tile_data_5, r11
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
    muls.w r2, r3
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
    muls.w r2, r3
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
    mov.l   _pool_tile_data_6, r2
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
    muls.w r2, r3
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
    muls.w r2, r3
    sts macl, r3
    shll r3
    exts.b r3, r0
    mov.b r0, @(8, r13)
    mov r6, r13
    mov.l   _pool_tile_data_8, r2
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
    muls.w r2, r3
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
    muls.w r2, r3
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
    muls.w r2, r3
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
    mov.l   _pool_tile_data_10, r2
    mov.l r2, @r13
    mov.w   DAT_0600498c, r0
    mov.w r0, @(4, r13)
    bra     .L_fill_template_10
    nop

    .global DAT_0600498a
DAT_0600498a:
    .2byte  0x0080

    .global DAT_0600498c
DAT_0600498c:
    .2byte  0xD116

    .global DAT_0600498e
DAT_0600498e:
    .2byte  0x7080
_pool_tile_data_5:
    .4byte  sym_06042CBC
_pool_tile_data_6:
    .4byte  sym_06042CD2
_pool_tile_data_8:
    .4byte  sym_06042E4E
_pool_tile_data_10:
    .4byte  sym_0604304E
.L_fill_template_10:
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
    muls.w r2, r3
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
    .4byte  0x84D96203
    .4byte  0x232F031A
    .4byte  0x633B7340
    .4byte  0x4300603F
    .4byte  0x81D584D6
    .4byte  0x630384D7
    .4byte  0x6203232F
    .4byte  0x031A4300
    .4byte  0x603E80D8
    .4byte  0x6D637601
    .4byte  0x63D34D08
    .4byte  0x43084300
    .4byte  0x3D3C3D7C
    .4byte  0xD21C2D22
    .4byte  0x903381D2
    .4byte  0x604E80D6
    .4byte  0x605E80D7
    .4byte  0xE02080D9
    .4byte  0x60EF81D5
    .4byte  0x84D66303
    .4byte  0x84D76203
    .4byte  0x232F031A
    .4byte  0x4300603E
    .4byte  0x636380D8
    .4byte  0x46084308
    .4byte  0x4300363C
    .4byte  0x367CD210
    .4byte  0x26229019
    .4byte  0x8162604E
    .4byte  0x8066605E
    .4byte  0x806760EE
    .4byte  0x806960EF
    .4byte  0x81658466
    .4byte  0x63038467
    .4byte  0x6203232F
    .4byte  0x031A4300
    .4byte  0x603E8068
    .4byte  0x7F044F16
    .4byte  0x6BF66DF6
    .4byte  0x000B6EF6

    .global DAT_06004a88
DAT_06004a88:
    .2byte  0x0080

    .global DAT_06004a8a
DAT_06004a8a:
    .2byte  0x01F7

    .global DAT_06004a8c
DAT_06004a8c:
    .4byte  0x91F7FFFF
    .4byte  sym_06059CC0
    .4byte  sym_06059DC0
