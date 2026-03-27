
    .section .text.FUN_0600C218


    .global FUN_0600C218
    .type FUN_0600C218, @function
FUN_0600C218:
    mov.l r14, @-r15
    mov #0x30, r6
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.w   .L_pool_0600C2A6, r12
    mov.l   .L_pool_0600C2AC, r13
    mov.w   .L_pool_0600C2A8, r14
    mov.l @r13, r3
    add #0x30, r3
    mov.l r3, @r13
    mov r3, r4
    mov.l   .L_pool_0600C2B0, r5
    mov.l   .L_pool_0600C2B4, r3
    jsr @r3
    mov.l @r5, r5
    mov.l   .L_pool_0600C2B8, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600C2BC, r2
    mov.l   .L_pool_0600C2C0, r3
    mov.l r2, @r3
    mov.l   .L_pool_0600C2C4, r2
    mov.l   .L_pool_0600C2C8, r3
    mov.w r2, @r3
    mov.l   .L_pool_0600C2CC, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600C2D0, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600C2D4, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600C2D8, r0
    mov.l @r0, r0
    tst r0, r0
.L_0600C262:
    mov.b @r12, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_0600C262
    mov.b @r12, r0
    mov.l   .L_0600C2DC, r3
    and #0xF, r0
    jsr @r3
    mov.b r0, @r12
    mov.l @r13, r2
    add #-0x30, r2
    mov.l r2, @r13
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0600C286
    .type FUN_0600C286, @function
FUN_0600C286:
    sts.l pr, @-r15
    mov.l   .L_0600C2DC, r3
    jsr @r3
    nop
    mov.l   .L_0600C2E0, r3
    jsr @r3
    nop
    mov.l   .L_0600C2E4, r4
    mov.b @r4, r2
    tst r2, r2
    bf      .L_0600C2EC
    mov.l   .L_0600C2E8, r3
    jsr @r3
    nop
    bra     .L_0600C2F8
    nop
.L_pool_0600C2A6:
    .2byte  0xFE11
.L_pool_0600C2A8:
    .4byte  0x0080FFFF
.L_pool_0600C2AC:
    .4byte  sym_0608A52C
.L_pool_0600C2B0:
    .4byte  sym_06089EDC
.L_pool_0600C2B4:
    .4byte  FUN_06027630
.L_pool_0600C2B8:
    .4byte  FUN_0600D31C
.L_pool_0600C2BC:
    .4byte  FUN_0600C286
.L_pool_0600C2C0:
    .4byte  sym_06063574
.L_pool_0600C2C4:
    .4byte  0x0000FFFF
.L_pool_0600C2C8:
    .4byte  0x21000000
.L_pool_0600C2CC:
    .4byte  FUN_060058FA
.L_pool_0600C2D0:
    .4byte  FUN_06006868
.L_pool_0600C2D4:
    .4byte  FUN_0601BDEC
.L_pool_0600C2D8:
    .4byte  sym_06059FF8
.L_0600C2DC:
    .4byte  sym_0603C000
.L_0600C2E0:
    .4byte  FUN_0600AFB2
.L_0600C2E4:
    .4byte  sym_06082A26
.L_0600C2E8:
    .4byte  FUN_06006CDC
.L_0600C2EC:
    mov.b @r4, r0
    cmp/eq #0x1, r0
    bf      .L_0600C2F8
    mov.l   .L_0600C378, r3
    jsr @r3
    nop
.L_0600C2F8:
    mov.l   .L_0600C37C, r2
    mov.l   .L_0600C380, r3
    lds.l @r15+, pr
    rts
    mov.w r2, @r3

    .global sym_0600C302
sym_0600C302:
    mov #0x68, r0
    mov.l   .L_0600C384, r4
    mov.l @r4, r4
    mov.l @(r0, r4), r3
    add #0x7C, r0
    shll2 r3
    shll2 r3
    shll r3
    mov.l r3, @(r0, r4)
    add #-0x4, r0
    mov.l r3, @(r0, r4)
    mov.w   DAT_0600c36a, r0
    mov.w @(r0, r4), r3
    cmp/pl r3
    bf      .L_0600C328
    mov.w   DAT_0600c36a, r0
    mov.w @(r0, r4), r2
    add #-0x1, r2
    mov.w r2, @(r0, r4)
.L_0600C328:
    mov.w   DAT_0600c36c, r0
    mov.w @(r0, r4), r3
    cmp/pl r3
    bf      .L_0600C338
    mov.w   DAT_0600c36c, r0
    mov.w @(r0, r4), r2
    add #-0x1, r2
    mov.w r2, @(r0, r4)
.L_0600C338:
    mov.w   DAT_0600c36e, r0
    mov.w @(r0, r4), r0
    tst r0, r0
    bt      .L_0600C344
    rts
    nop
.L_0600C344:
    mov #0x12, r7
    mov #0x68, r0
    mov.w   DAT_0600c370, r2
    mov.l @(r0, r4), r3
    cmp/ge r2, r3
    bf/s    .L_0600C35C
    mov #0x0, r6
    mov.w   DAT_0600c36a, r0
    mov.w r7, @(r0, r4)
    add #0x2, r0
    rts
    mov.w r6, @(r0, r4)
.L_0600C35C:
    mov.w   DAT_0600c372, r0
    mov.w   .L_wpool_0600C37C, r2
    mov.l @(r0, r4), r3
    cmp/ge r2, r3
    bt      .L_0600C388
    rts
    nop

    .global DAT_0600c36a
DAT_0600c36a:
    .2byte  0x0172

    .global DAT_0600c36c
DAT_0600c36c:
    .2byte  0x0174

    .global DAT_0600c36e
DAT_0600c36e:
    .2byte  0x00DC

    .global DAT_0600c370
DAT_0600c370:
    .2byte  0x00E6

    .global DAT_0600c372
DAT_0600c372:
    .2byte  0x0084
.L_wpool_0600C37C:
    .2byte  0x008C
    .2byte  0xFFFF
.L_0600C378:
    .4byte  FUN_06006A9C
.L_0600C37C:
    .4byte  0x0000FFFF
.L_0600C380:
    .4byte  0x21800000
.L_0600C384:
    .4byte  sym_0607E944
.L_0600C388:
    mov #0x68, r0
    mov.w   .L_wpool_0600C41E, r3
    mov.l @(r0, r4), r5
    cmp/gt r3, r5
    bf      .L_0600C3A4
    mov.w   DAT_0600c418, r3
    cmp/ge r3, r5
    bt      .L_0600C3A4
    exts.w r6, r6
    mov.w   .L_wpool_0600C422, r0
    mov.w r6, @(r0, r4)
    exts.w r7, r7
    add #0x2, r0
    mov.w r7, @(r0, r4)
.L_0600C3A4:
    rts
    nop
    .global FUN_0600C3A8
FUN_0600C3A8:
    .4byte  0xD51CD61D
    .4byte  0xD31DD21E
    .4byte  0x6331633D
    .4byte  0x33208F41
    .4byte  0xE703624D
    .4byte  0xD31B6331
    .4byte  0x633D2239
    .4byte  0x22288903
    .4byte  0xE3002532
    .4byte  0xA06C0009
    .4byte  0x624DD317
    .4byte  0x6331633D
    .4byte  0x22392228
    .4byte  0x89066060
    .4byte  0x20088B16
    .4byte  0xE3012532
    .4byte  0xA0130009
    .4byte  0x624DD311
    .4byte  0x6331633D
    .4byte  0x22392228
    .4byte  0x8903E302
    .4byte  0x2532A008
    .4byte  0x0009644D
    .4byte  0xD20C6221
    .4byte  0x622D2429
    .4byte  0x24488900
    .4byte  0x2572A049
    .2byte  0x0009
.L_wpool_0600C41E:
    .2byte  0x009B

    .global DAT_0600c418
DAT_0600c418:
    .2byte  0x00E6
.L_wpool_0600C422:
    .2byte  0x0172
    .4byte  sym_06063E20
    .4byte  sym_06083255
    .4byte  sym_0607865E
    .4byte  0x00008000
    .4byte  sym_06078656
    .4byte  sym_06078658
    .4byte  sym_0607865A
    .4byte  sym_0607865C
    .4byte  0x624DD326
    .4byte  0x6331633D
    .4byte  0x22392228
    .4byte  0x8912D324
    .4byte  0xE2006332
    .4byte  0x33268B0D
    .4byte  0x60602008
    .4byte  0x8903D020
    .4byte  0x60028802
    .4byte  0x89026252
    .4byte  0xA00272FF
    .4byte  0x625272FE
    .4byte  0xA01C2522
    .4byte  0x644DD21B
    .4byte  0x6221622D
    .4byte  0x24292448
    .4byte  0x8914D319
    .4byte  0xD2166330
    .4byte  0x62223232
    .4byte  0x890E6060
    .4byte  0x20088903
    .4byte  0xD0126002
    .4byte  0x20088904
    .4byte  0x63527301
    .4byte  0x2532A003
    .4byte  0x00096252
    .4byte  0x72022522
    .4byte  0xD00F6000
    .4byte  0x600C2008
    .4byte  0x8B10D00E
    .4byte  0x6001600D
    .4byte  0x2008890B
    .4byte  0xD40CE106
    .4byte  0xD30C6252
    .4byte  0x6332332C
    .4byte  0x33168B01
    .4byte  0xA001627F
    .4byte  0xE2042421
    .4byte  0x000B0009
    .4byte  sym_0607865E
    .4byte  sym_06063E20
    .4byte  sym_06078660
    .4byte  sym_06078662
    .4byte  sym_06078635
    .4byte  sym_0607ED8C
    .4byte  sym_0605A016
    .4byte  sym_06063E1C
