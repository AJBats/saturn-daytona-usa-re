
    .section .text.FUN_06012F80


    .global game_init_master
    .type game_init_master, @function
game_init_master:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601306C, r3
    mov.l   .L_06013070, r2
    mov.l r3, @r2
    mov.l   .L_06013074, r3
    mov.l   .L_06013078, r2
    mov.l r3, @r2
    mov.l   .L_0601307C, r3
    mov.l   .L_06013080, r2
    mov.l r3, @r2
    mov.l   .L_06013084, r3
    jsr @r3
    nop
    mov.l   .L_06013088, r3
    jsr @r3
    nop
    mov.l   .L_0601308C, r4
    mov.l   .L_06013090, r3
    jsr @r3
    nop
    mov #0x0, r6
    mov.w   DAT_06013050, r2
    mov r6, r5
    mov.l r2, @-r15
    mov.w   DAT_06013052, r7
    mov.l   .L_06013094, r3
    jsr @r3
    mov r6, r4
    mov #0x0, r2
    mov.l   .L_06013098, r3
    mov.l r2, @r3
    mov.l   .L_0601308C, r2
    mov.l   .L_0601309C, r3
    mov.l @r2, r2
    mov.w r3, @r2
    mov.l   .L_060130A0, r14
    jsr @r14
    mov #0x0, r4
    jsr @r14
    mov #0x4, r4
    jsr @r14
    mov #0x8, r4
    jsr @r14
    mov #0xC, r4
    mov.l   .L_060130A4, r2
    mov.w   .L_06013054, r5
    mov.l @r2, r2
    jsr @r2
    mov #-0x1, r4
    mov.l   .L_060130A8, r3
    jsr @r3
    nop
    mov.l   .L_060130A4, r2
    mov.w   .L_06013056, r4
    mov.l @r2, r2
    jsr @r2
    mov #0x0, r5
    mov #0x0, r3
    mov #0x2, r0
    mov.l   .L_060130AC, r2
    mov.l r3, @r2
    mov.w   DAT_06013058, r3
    mov.l   .L_060130B0, r2
    mov.l r3, @r2
    mov #0x0, r3
    mov.l   .L_060130B4, r10
    mov r3, r6
    mov.w r0, @(6, r10)
    mov.w r3, @r10
    mov.w   .L_0601305A, r12
    mov.l   .L_060130B8, r13
    mov.l   .L_060130BC, r14
    mov.w   DAT_0601305c, r7
    mov r12, r5
    add r14, r7
    jsr @r13
    mov #0x1, r4
    mov.w   DAT_0601305e, r7
    mov #0x0, r6
    mov.w   .L_06013060, r5
    add r14, r7
    jsr @r13
    mov #0x2, r4
    mov.w   DAT_06013062, r7
    mov #0x0, r6
    mov.w   DAT_06013064, r5
    add r14, r7
    jsr @r13
    mov #0x3, r4
    mov.w   DAT_06013066, r7
    mov #0x0, r6
    mov.w   DAT_06013068, r5
    add r14, r7
    jsr @r13
    mov #0x4, r4
    bra     .L_060130C0
    nop

    .global DAT_06013050
DAT_06013050:
    .2byte  0x00DF

    .global DAT_06013052
DAT_06013052:
    .2byte  0x015F
.L_06013054:
    .2byte  0x0083
.L_06013056:
    .2byte  0xFF7C

    .global DAT_06013058
DAT_06013058:
    .2byte  0x20D8
.L_0601305A:
    .2byte  0x0108

    .global DAT_0601305c
DAT_0601305c:
    .2byte  0x299B

    .global DAT_0601305e
DAT_0601305e:
    .2byte  0x29A3
.L_06013060:
    .2byte  0x0810

    .global DAT_06013062
DAT_06013062:
    .2byte  0x2A53

    .global DAT_06013064
DAT_06013064:
    .2byte  0x0512

    .global DAT_06013066
DAT_06013066:
    .2byte  0x2B27

    .global DAT_06013068
DAT_06013068:
    .2byte  0x083C
    .2byte  0xFFFF
.L_0601306C:
    .4byte  sym_06084B28
.L_06013070:
    .4byte  sym_06084FA8
.L_06013074:
    .4byte  sym_06084CA8
.L_06013078:
    .4byte  sym_06084FAC
.L_0601307C:
    .4byte  sym_06084E28
.L_06013080:
    .4byte  sym_06084FB0
.L_06013084:
    .4byte  sym_060149E0
.L_06013088:
    .4byte  sym_06026CE0
.L_0601308C:
    .4byte  sym_06063F5C
.L_06013090:
    .4byte  vdp2_scroll_update
.L_06013094:
    .4byte  sym_060393FC
.L_06013098:
    .4byte  sym_0605A008
.L_0601309C:
    .4byte  0x00008000
.L_060130A0:
    .4byte  sym_0602853E
.L_060130A4:
    .4byte  sym_06000344
.L_060130A8:
    .4byte  sym_06012E00
.L_060130AC:
    .4byte  sym_0606A4F4
.L_060130B0:
    .4byte  sym_0606A4EC
.L_060130B4:
    .4byte  sym_06089E44
.L_060130B8:
    .4byte  vdp1_sprite_render
.L_060130BC:
    .4byte  0x002A0000
.L_060130C0:
    mov.w   DAT_060131b4, r7
    mov #0x0, r6
    mov.w   .L_060131B6, r5
    add r14, r7
    jsr @r13
    mov #0x5, r4
    mov.w   DAT_060131b8, r7
    mov #0x0, r6
    mov.w   DAT_060131ba, r5
    add r14, r7
    jsr @r13
    mov #0x6, r4
    mov.w   DAT_060131bc, r7
    mov #0x4, r6
    mov.w   .L_060131BE, r5
    add r14, r7
    jsr @r13
    mov #0x7, r4
    mov.w   DAT_060131c0, r7
    mov #0x4, r6
    mov.w   .L_060131BE, r5
    add r14, r7
    jsr @r13
    mov #0x8, r4
    mov.w   DAT_060131c2, r7
    mov #0x0, r6
    mov.w   .L_060131C4, r5
    add r14, r7
    jsr @r13
    mov #0x9, r4
    mov.w   DAT_060131c6, r7
    mov #0x3C, r6
    mov.w   .L_060131C8, r5
    add r14, r7
    jsr @r13
    mov #0xA, r4
    mov.w   DAT_060131ca, r7
    mov #0x8, r6
    mov.w   .L_060131CC, r5
    add r14, r7
    jsr @r13
    mov #0x10, r4
    mov.w   DAT_060131ce, r7
    mov #0x8, r6
    mov.w   .L_060131D0, r5
    add r14, r7
    jsr @r13
    mov #0x11, r4
    mov.w   DAT_060131d2, r7
    mov #0x8, r6
    mov.w   .L_060131D4, r5
    add r14, r7
    jsr @r13
    mov #0x12, r4
    mov.w   DAT_060131d6, r7
    mov #0x8, r6
    mov.w   .L_060131D8, r5
    add r14, r7
    jsr @r13
    mov #0x13, r4
    mov.w   DAT_060131da, r7
    mov #0x8, r6
    mov.w   .L_060131DC, r5
    add r14, r7
    jsr @r13
    mov #0x14, r4
    mov.w   DAT_060131de, r7
    mov #0x8, r6
    mov.w   .L_060131DC, r5
    add r14, r7
    jsr @r13
    mov #0x15, r4
    mov.w   DAT_060131e0, r7
    mov #0xC, r6
    mov.w   .L_060131E2, r5
    add r14, r7
    jsr @r13
    mov #0x16, r4
    mov.w   DAT_060131e4, r7
    mov #0x8, r6
    mov.w   .L_060131E6, r5
    add r14, r7
    jsr @r13
    mov #0x17, r4
    mov.w   DAT_060131e8, r7
    mov #0x1C, r6
    mov.w   DAT_060131ea, r5
    add r14, r7
    jsr @r13
    mov #0x18, r4
    mov.w   .L_060131EC, r11
    mov #0x10, r6
    mov.w   DAT_060131ee, r7
    mov r11, r5
    add r14, r7
    jsr @r13
    mov #0x19, r4
    mov #0x10, r6
    mov r11, r5
    mov.w   DAT_060131f0, r7
    add r14, r7
    jsr @r13
    mov #0x1A, r4
    mov #0x10, r6
    mov r11, r5
    mov.w   DAT_060131f2, r7
    add r14, r7
    jsr @r13
    mov #0x1B, r4
    mov #0x1C, r6
    mov.w   .L_060131F4, r11
    mov.w   DAT_060131f6, r7
    mov r11, r5
    add r14, r7
    jsr @r13
    mov r6, r4
    mov.w   DAT_060131f8, r7
    add r14, r7
    mov #0x10, r6
    mov.w   .L_060131C8, r5
    bra     .L_060131FA
    nop

    .global DAT_060131b4
DAT_060131b4:
    .2byte  0x2E73
.L_060131B6:
    .2byte  0x0519

    .global DAT_060131b8
DAT_060131b8:
    .2byte  0x2F93

    .global DAT_060131ba
DAT_060131ba:
    .2byte  0x080F

    .global DAT_060131bc
DAT_060131bc:
    .2byte  0x3027
.L_060131BE:
    .2byte  0x0738

    .global DAT_060131c0
DAT_060131c0:
    .2byte  0x325B

    .global DAT_060131c2
DAT_060131c2:
    .2byte  0x3433
.L_060131C4:
    .2byte  0x0208

    .global DAT_060131c6
DAT_060131c6:
    .2byte  0x3457
.L_060131C8:
    .2byte  0x0A28

    .global DAT_060131ca
DAT_060131ca:
    .2byte  0x0640
.L_060131CC:
    .2byte  0x0228

    .global DAT_060131ce
DAT_060131ce:
    .2byte  0x06AC
.L_060131D0:
    .2byte  0x0428

    .global DAT_060131d2
DAT_060131d2:
    .2byte  0x074C
.L_060131D4:
    .2byte  0x0418

    .global DAT_060131d6
DAT_060131d6:
    .2byte  0x07E4
.L_060131D8:
    .2byte  0x0820

    .global DAT_060131da
DAT_060131da:
    .2byte  0x09B4
.L_060131DC:
    .2byte  0x0518

    .global DAT_060131de
DAT_060131de:
    .2byte  0x0A34

    .global DAT_060131e0
DAT_060131e0:
    .2byte  0x0AA4
.L_060131E2:
    .2byte  0x0508

    .global DAT_060131e4
DAT_060131e4:
    .2byte  0x0AD8
.L_060131E6:
    .2byte  0x0D10

    .global DAT_060131e8
DAT_060131e8:
    .2byte  0x0C14

    .global DAT_060131ea
DAT_060131ea:
    .2byte  0x041C
.L_060131EC:
    .2byte  0x0348

    .global DAT_060131ee
DAT_060131ee:
    .2byte  0x0D7C

    .global DAT_060131f0
DAT_060131f0:
    .2byte  0x0F58

    .global DAT_060131f2
DAT_060131f2:
    .2byte  0x1140
.L_060131F4:
    .2byte  0x0630

    .global DAT_060131f6
DAT_060131f6:
    .2byte  0x12F8

    .global DAT_060131f8
DAT_060131f8:
    .2byte  0x1484
.L_060131FA:
    jsr @r13
    mov #0x1D, r4
    mov #0x18, r6
    mov.w   .L_060132F4, r5
    mov.w   DAT_060132f2, r7
    add r14, r7
    jsr @r13
    mov #0x1E, r4
    mov #0x18, r6
    mov.w   .L_060132F8, r5
    mov.w   DAT_060132f6, r7
    add r14, r7
    jsr @r13
    mov #0x1F, r4
    mov #0xC, r6
    mov.w   .L_060132FA, r9
    mov.w   DAT_060132fc, r7
    mov r9, r5
    add r14, r7
    jsr @r13
    mov #0x20, r4
    mov.w   DAT_060132fe, r7
    mov #0xC, r6
    mov.w   .L_06013300, r5
    add r14, r7
    jsr @r13
    mov #0x21, r4
    mov.w   DAT_06013302, r7
    mov #0xC, r6
    mov r9, r5
    add r14, r7
    jsr @r13
    mov #0x22, r4
    mov.w   DAT_06013304, r7
    mov #0xC, r6
    mov r9, r5
    add r14, r7
    jsr @r13
    mov #0x23, r4
    mov.w   DAT_06013306, r7
    mov #0xC, r6
    mov.w   .L_06013300, r5
    add r14, r7
    jsr @r13
    mov #0x24, r4
    mov.w   DAT_06013308, r7
    mov #0x14, r6
    mov.w   DAT_0601330a, r5
    add r14, r7
    jsr @r13
    mov #0x25, r4
    mov.w   DAT_0601330c, r7
    mov #0x14, r6
    mov.w   DAT_0601330a, r5
    add r14, r7
    jsr @r13
    mov #0x26, r4
    mov.w   DAT_0601330e, r7
    mov #0xC, r6
    mov.w   .L_06013310, r5
    add r14, r7
    jsr @r13
    mov #0x27, r4
    mov.w   DAT_06013312, r7
    mov #0x14, r6
    mov.w   .L_06013314, r5
    add r14, r7
    jsr @r13
    mov #0x28, r4
    mov.w   .L_06013316, r9
    mov #0x14, r6
    mov.w   DAT_06013318, r7
    mov r9, r5
    add r14, r7
    jsr @r13
    mov #0x29, r4
    mov #0x14, r6
    mov.w   DAT_0601331c, r5
    mov.w   DAT_0601331a, r7
    add r14, r7
    jsr @r13
    mov #0x2A, r4
    mov #0x14, r6
    mov.w   DAT_06013320, r5
    mov.w   DAT_0601331e, r7
    add r14, r7
    jsr @r13
    mov #0x2B, r4
    mov #0xC, r6
    mov.w   .L_06013324, r5
    mov.w   DAT_06013322, r7
    add r14, r7
    jsr @r13
    mov #0x2C, r4
    mov #0xC, r6
    mov.w   .L_06013324, r5
    mov.w   DAT_06013326, r7
    add r14, r7
    jsr @r13
    mov #0x2D, r4
    mov #0x14, r6
    mov.w   .L_06013314, r5
    mov.w   DAT_06013328, r7
    add r14, r7
    jsr @r13
    mov #0x2E, r4
    mov #0x14, r6
    mov r9, r5
    mov.w   DAT_0601332a, r7
    add r14, r7
    jsr @r13
    mov #0x2F, r4
    mov #0x14, r6
    mov.w   DAT_0601331c, r5
    mov.w   DAT_0601332c, r7
    add r14, r7
    jsr @r13
    mov #0x30, r4
    mov.w   DAT_0601332e, r7
    add r14, r7
    mov #0x14, r6
    mov.w   DAT_06013320, r5
    bra     .L_06013330
    mov #0x31, r4

    .global DAT_060132f2
DAT_060132f2:
    .2byte  0x1890
.L_060132F4:
    .2byte  0x0C08

    .global DAT_060132f6
DAT_060132f6:
    .2byte  0x1908
.L_060132F8:
    .2byte  0x0C10
.L_060132FA:
    .2byte  0x0308

    .global DAT_060132fc
DAT_060132fc:
    .2byte  0x1AC4

    .global DAT_060132fe
DAT_060132fe:
    .2byte  0x1B04
.L_06013300:
    .2byte  0x0410

    .global DAT_06013302
DAT_06013302:
    .2byte  0x1B9C

    .global DAT_06013304
DAT_06013304:
    .2byte  0x1BC8

    .global DAT_06013306
DAT_06013306:
    .2byte  0x1C04

    .global DAT_06013308
DAT_06013308:
    .2byte  0x1CC8

    .global DAT_0601330a
DAT_0601330a:
    .2byte  0x060C

    .global DAT_0601330c
DAT_0601330c:
    .2byte  0x1D2C

    .global DAT_0601330e
DAT_0601330e:
    .2byte  0x1D84
.L_06013310:
    .2byte  0x0610

    .global DAT_06013312
DAT_06013312:
    .2byte  0x1E20
.L_06013314:
    .2byte  0x0510
.L_06013316:
    .2byte  0x0310

    .global DAT_06013318
DAT_06013318:
    .2byte  0x1E8C

    .global DAT_0601331a
DAT_0601331a:
    .2byte  0x1EFC

    .global DAT_0601331c
DAT_0601331c:
    .2byte  0x090C

    .global DAT_0601331e
DAT_0601331e:
    .2byte  0x1FC8

    .global DAT_06013320
DAT_06013320:
    .2byte  0x080C

    .global DAT_06013322
DAT_06013322:
    .2byte  0x2060
.L_06013324:
    .2byte  0x0110

    .global DAT_06013326
DAT_06013326:
    .2byte  0x2080

    .global DAT_06013328
DAT_06013328:
    .2byte  0x20A0

    .global DAT_0601332a
DAT_0601332a:
    .2byte  0x211C

    .global DAT_0601332c
DAT_0601332c:
    .2byte  0x2194

    .global DAT_0601332e
DAT_0601332e:
    .2byte  0x225C
.L_06013330:
    jsr @r13
    nop
    mov.w   DAT_06013440, r7
    mov #0x14, r6
    mov r12, r5
    add r14, r7
    jsr @r13
    mov #0x32, r4
    mov.w   DAT_06013442, r7
    mov #0x14, r6
    mov r12, r5
    add r14, r7
    jsr @r13
    mov #0x33, r4
    mov.w   DAT_06013444, r7
    mov #0x14, r6
    mov r12, r5
    add r14, r7
    jsr @r13
    mov #0x34, r4
    mov.w   DAT_06013446, r7
    mov #0x14, r6
    mov r12, r5
    add r14, r7
    jsr @r13
    mov #0x35, r4
    mov.w   DAT_06013448, r7
    mov #0x10, r6
    mov r12, r5
    add r14, r7
    jsr @r13
    mov #0x36, r4
    mov.w   DAT_0601344a, r7
    mov #0x1C, r6
    mov r12, r5
    add r14, r7
    jsr @r13
    mov #0x37, r4
    mov.w   DAT_0601344c, r7
    mov #0x8, r6
    mov r12, r5
    add r14, r7
    jsr @r13
    mov #0x38, r4
    mov.w   DAT_0601344e, r7
    mov #0x10, r6
    mov r12, r5
    add r14, r7
    jsr @r13
    mov #0x39, r4
    mov #0x1, r0
    mov #0x0, r6
    mov.w r0, @(2, r10)
    mov r0, r5
    mov.l   .L_06013450, r12
    jsr @r12
    mov #0x41, r4
    mov #0x0, r6
    mov #0x2, r5
    jsr @r12
    mov #0x42, r4
    mov #0x0, r6
    mov #0x3, r5
    jsr @r12
    mov #0x43, r4
    mov #0x0, r6
    mov #0x4, r5
    jsr @r12
    mov #0x44, r4
    mov #0x0, r6
    mov #0x5, r5
    jsr @r12
    mov #0x45, r4
    mov #0x0, r6
    mov #0x6, r5
    jsr @r12
    mov #0x46, r4
    mov #0x4, r6
    mov #0x7, r5
    jsr @r12
    mov #0x47, r4
    mov #0x4, r6
    mov #0x8, r5
    jsr @r12
    mov #0x48, r4
    mov #0x0, r6
    mov #0x9, r5
    jsr @r12
    mov #0x49, r4
    mov #0x3C, r6
    mov #0xA, r5
    jsr @r12
    mov #0x4A, r4
    mov #0x20, r6
    mov #0x10, r5
    jsr @r12
    mov #0x50, r4
    mov #0x20, r6
    mov #0x11, r5
    jsr @r12
    mov #0x51, r4
    mov #0x20, r6
    mov #0x12, r5
    jsr @r12
    mov #0x52, r4
    mov #0x20, r6
    mov #0x13, r5
    jsr @r12
    mov #0x53, r4
    mov #0x20, r6
    mov #0x14, r5
    jsr @r12
    mov #0x54, r4
    mov #0x20, r6
    mov #0x15, r5
    jsr @r12
    mov #0x55, r4
    mov #0x24, r6
    mov #0x16, r5
    jsr @r12
    mov #0x56, r4
    mov #0x20, r6
    mov #0x17, r5
    jsr @r12
    mov #0x57, r4
    mov #0x34, r6
    mov #0x18, r5
    jsr @r12
    mov #0x58, r4
    mov #0x28, r6
    mov #0x19, r5
    jsr @r12
    mov #0x59, r4
    mov #0x28, r6
    bra     .L_06013454
    nop

    .global DAT_06013440
DAT_06013440:
    .2byte  0x22F4

    .global DAT_06013442
DAT_06013442:
    .2byte  0x22FC

    .global DAT_06013444
DAT_06013444:
    .2byte  0x2304

    .global DAT_06013446
DAT_06013446:
    .2byte  0x230C

    .global DAT_06013448
DAT_06013448:
    .2byte  0x2314

    .global DAT_0601344a
DAT_0601344a:
    .2byte  0x231C

    .global DAT_0601344c
DAT_0601344c:
    .2byte  0x2324

    .global DAT_0601344e
DAT_0601344e:
    .2byte  0x232C
.L_06013450:
    .4byte  sym_06007540
.L_06013454:
    mov #0x1A, r5
    jsr @r12
    mov #0x5A, r4
    mov #0x28, r6
    mov #0x1B, r5
    jsr @r12
    mov #0x5B, r4
    mov #0x34, r6
    mov #0x1C, r5
    jsr @r12
    mov #0x5C, r4
    mov #0x28, r6
    mov #0x1D, r5
    jsr @r12
    mov #0x5D, r4
    mov #0x30, r6
    mov #0x1E, r5
    jsr @r12
    mov #0x5E, r4
    mov #0x30, r6
    mov #0x1F, r5
    jsr @r12
    mov #0x5F, r4
    mov #0x24, r6
    mov #0x20, r5
    jsr @r12
    mov #0x60, r4
    mov #0x24, r6
    mov #0x21, r5
    jsr @r12
    mov #0x61, r4
    mov #0x24, r6
    mov #0x22, r5
    jsr @r12
    mov #0x62, r4
    mov #0x24, r6
    mov #0x23, r5
    jsr @r12
    mov #0x63, r4
    mov #0x24, r6
    mov r6, r5
    jsr @r12
    mov #0x64, r4
    mov #0x2C, r6
    mov #0x25, r5
    jsr @r12
    mov #0x65, r4
    mov #0x2C, r6
    mov #0x26, r5
    jsr @r12
    mov #0x66, r4
    mov #0x24, r6
    mov #0x27, r5
    jsr @r12
    mov #0x67, r4
    mov #0x2C, r6
    mov #0x28, r5
    jsr @r12
    mov #0x68, r4
    mov #0x2C, r6
    mov #0x29, r5
    jsr @r12
    mov #0x69, r4
    mov #0x2C, r6
    mov #0x2A, r5
    jsr @r12
    mov #0x6A, r4
    mov #0x2C, r6
    mov #0x2B, r5
    jsr @r12
    mov #0x6B, r4
    mov #0x24, r6
    mov #0x2C, r5
    jsr @r12
    mov #0x6C, r4
    mov #0x24, r6
    mov #0x2D, r5
    jsr @r12
    mov #0x6D, r4
    mov #0x2C, r6
    mov #0x2E, r5
    jsr @r12
    mov #0x6E, r4
    mov #0x2C, r6
    mov #0x2F, r5
    jsr @r12
    mov #0x6F, r4
    mov #0x2C, r6
    mov #0x30, r5
    jsr @r12
    mov #0x70, r4
    mov #0x2C, r6
    mov #0x31, r5
    jsr @r12
    mov #0x71, r4
    mov #0x2C, r6
    mov #0x32, r5
    jsr @r12
    mov #0x72, r4
    mov #0x2C, r6
    mov #0x33, r5
    jsr @r12
    mov #0x73, r4
    mov #0x2C, r6
    mov #0x34, r5
    jsr @r12
    mov #0x74, r4
    mov #0x2C, r6
    mov #0x35, r5
    jsr @r12
    mov #0x75, r4
    mov #0x28, r6
    mov #0x36, r5
    jsr @r12
    mov #0x76, r4
    mov #0x34, r6
    mov #0x37, r5
    jsr @r12
    mov #0x77, r4
    mov #0x20, r6
    mov #0x38, r5
    jsr @r12
    mov #0x78, r4
    mov #0x28, r6
    mov #0x39, r5
    jsr @r12
    mov #0x79, r4
    mov.w   .L_06013560, r12
    mov.w   DAT_06013562, r7
    add r14, r7
    mov #0x74, r6
    mov r12, r5
    bra     .L_06013564
    nop
.L_06013560:
    .2byte  0x0730

    .global DAT_06013562
DAT_06013562:
    .2byte  0x63F6
.L_06013564:
    mov r6, r4
    jsr @r13
    add #0x16, r4
    mov #0x74, r6
    mov r11, r5
    mov.w   DAT_06013682, r7
    mov r6, r4
    add r14, r7
    jsr @r13
    add #0x17, r4
    mov.w   DAT_06013684, r7
    mov #0x74, r6
    mov r11, r5
    add r14, r7
    mov r6, r4
    jsr @r13
    add #0x18, r4
    mov #0x74, r6
    mov r12, r5
    mov.w   DAT_06013686, r7
    mov r6, r4
    add r14, r7
    jsr @r13
    add #0x19, r4
    mov.w   DAT_06013688, r7
    mov #0x74, r6
    mov r11, r5
    add r14, r7
    mov r6, r4
    jsr @r13
    add #0x1A, r4
    mov #0x74, r6
    mov r11, r5
    mov.w   DAT_0601368a, r7
    mov r6, r4
    add r14, r7
    jsr @r13
    add #0x1B, r4
    mov.w   DAT_0601368c, r7
    mov #0x74, r6
    mov r11, r5
    add r14, r7
    mov r6, r4
    jsr @r13
    add #0x1C, r4
    mov.w   DAT_0601368e, r7
    mov.w   .L_06013690, r5
    mov.w   .L_06013692, r4
    add r14, r7
    jsr @r13
    mov #0x74, r6
    mov.w   DAT_06013694, r7
    mov.w   .L_06013696, r5
    mov.w   .L_06013698, r4
    add r14, r7
    jsr @r13
    mov #0x74, r6
    mov.w   DAT_0601369a, r7
    mov.w   .L_0601369C, r5
    mov.w   .L_0601369E, r4
    add r14, r7
    jsr @r13
    mov #0x74, r6
    mov #0x74, r6
    mov r11, r5
    mov.w   DAT_060136a0, r7
    mov r6, r4
    add r14, r7
    jsr @r13
    add #0x20, r4
    mov.w   DAT_060136a2, r7
    mov.w   .L_060136A4, r5
    mov.w   DAT_060136a6, r4
    add r14, r7
    jsr @r13
    mov #0x74, r6
    mov.w   DAT_060136a8, r7
    mov.w   .L_06013690, r5
    mov.w   DAT_060136aa, r4
    add r14, r7
    jsr @r13
    mov #0x74, r6
    mov.w   DAT_060136ac, r7
    mov #0x74, r6
    mov r12, r5
    add r14, r7
    mov r6, r4
    jsr @r13
    add #0x23, r4
    mov #0x74, r6
    mov r12, r5
    mov.w   DAT_060136ae, r7
    mov r6, r4
    add r14, r7
    jsr @r13
    add #0x24, r4
    mov.w   DAT_060136b0, r7
    mov #0x74, r6
    mov r11, r5
    add r14, r7
    mov r6, r4
    jsr @r13
    add #0x25, r4
    mov.w   DAT_060136b2, r7
    mov.w   .L_060136B4, r5
    mov.w   .L_060136B6, r4
    add r14, r7
    jsr @r13
    mov #0x74, r6
    mov #0x74, r6
    mov r11, r5
    mov.w   DAT_060136b8, r7
    mov r6, r4
    add r14, r7
    jsr @r13
    add #0x27, r4
    mov.w   DAT_060136ba, r7
    mov.w   .L_060136A4, r5
    mov.w   DAT_060136bc, r4
    add r14, r7
    jsr @r13
    mov #0x74, r6
    mov.w   DAT_060136be, r7
    mov #0x74, r6
    mov r11, r5
    add r14, r7
    mov r6, r4
    jsr @r13
    add #0x29, r4
    mov #0x74, r6
    mov r12, r5
    mov.w   DAT_060136c0, r7
    mov r6, r4
    add r14, r7
    jsr @r13
    add #0x2A, r4
    mov.w   DAT_060136c2, r7
    add r14, r7
    mov #0x74, r6
    mov r11, r5
    mov r6, r4
    bra     .L_060136C4
    add #0x2B, r4

    .global DAT_06013682
DAT_06013682:
    .2byte  0x64CB

    .global DAT_06013684
DAT_06013684:
    .2byte  0x6587

    .global DAT_06013686
DAT_06013686:
    .2byte  0x663F

    .global DAT_06013688
DAT_06013688:
    .2byte  0x6709

    .global DAT_0601368a
DAT_0601368a:
    .2byte  0x67BD

    .global DAT_0601368c
DAT_0601368c:
    .2byte  0x686D

    .global DAT_0601368e
DAT_0601368e:
    .2byte  0x6928
.L_06013690:
    .2byte  0x0830
.L_06013692:
    .2byte  0x0091

    .global DAT_06013694
DAT_06013694:
    .2byte  0x69FB
.L_06013696:
    .2byte  0x0430
.L_06013698:
    .2byte  0x0092

    .global DAT_0601369a
DAT_0601369a:
    .2byte  0x6A6A
.L_0601369C:
    .2byte  0x0540
.L_0601369E:
    .2byte  0x0093

    .global DAT_060136a0
DAT_060136a0:
    .2byte  0x6B18

    .global DAT_060136a2
DAT_060136a2:
    .2byte  0x6BE9
.L_060136A4:
    .2byte  0x0530

    .global DAT_060136a6
DAT_060136a6:
    .2byte  0x0095

    .global DAT_060136a8
DAT_060136a8:
    .2byte  0x6C7E

    .global DAT_060136aa
DAT_060136aa:
    .2byte  0x0096

    .global DAT_060136ac
DAT_060136ac:
    .2byte  0x6DA1

    .global DAT_060136ae
DAT_060136ae:
    .2byte  0x6E7F

    .global DAT_060136b0
DAT_060136b0:
    .2byte  0x6F4B

    .global DAT_060136b2
DAT_060136b2:
    .2byte  0x6FFE
.L_060136B4:
    .2byte  0x0840
.L_060136B6:
    .2byte  0x009A

    .global DAT_060136b8
DAT_060136b8:
    .2byte  0x711E

    .global DAT_060136ba
DAT_060136ba:
    .2byte  0x71DF

    .global DAT_060136bc
DAT_060136bc:
    .2byte  0x009C

    .global DAT_060136be
DAT_060136be:
    .2byte  0x7293

    .global DAT_060136c0
DAT_060136c0:
    .2byte  0x734A

    .global DAT_060136c2
DAT_060136c2:
    .2byte  0x7408
.L_060136C4:
    jsr @r13
    nop
    mov.w   DAT_060137b0, r7
    mov.w   .L_060137B2, r5
    mov.w   .L_060137B4, r4
    add r14, r7
    jsr @r13
    mov #0x74, r6
    mov.w   DAT_060137b6, r7
    mov #0x74, r6
    mov r12, r5
    add r14, r7
    mov r6, r4
    jsr @r13
    add #0x2D, r4
    mov #0x74, r6
    mov r11, r5
    mov.w   DAT_060137b8, r7
    mov r6, r4
    add r14, r7
    jsr @r13
    add #0x2E, r4
    mov.w   DAT_060137ba, r7
    mov #0x74, r6
    mov r12, r5
    add r14, r7
    mov r6, r4
    jsr @r13
    add #0x2F, r4
    mov #0x74, r6
    mov r11, r5
    mov.w   DAT_060137bc, r7
    mov r6, r4
    add r14, r7
    jsr @r13
    add #0x30, r4
    mov.w   DAT_060137be, r7
    mov #0x74, r6
    mov r11, r5
    add r14, r7
    mov r6, r4
    jsr @r13
    add #0x31, r4
    mov #0x74, r6
    mov r12, r5
    mov.w   DAT_060137c0, r7
    mov r6, r4
    add r14, r7
    jsr @r13
    add #0x32, r4
    mov.w   DAT_060137c2, r7
    mov #0x70, r6
    mov r9, r5
    add r14, r7
    mov r6, r4
    jsr @r13
    add #0x37, r4
    mov.l   .L_060137C8, r14
    mov.l   .L_060137CC, r5
    mov.l   .L_060137D0, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_060137D4, r5
    mov.l   .L_060137D8, r4
    jsr @r14
    mov #0x60, r6
    mov.l   .L_060137DC, r5
    mov.l   .L_060137E0, r4
    jsr @r14
    mov #0x40, r6
    mov.l   .L_060137E4, r5
    mov.l   .L_060137E8, r4
    jsr @r14
    mov #0x40, r6
    mov #0x40, r6
    mov.l   .L_060137EC, r3
    mov.l r3, @(4, r15)
    mov.l   .L_060137F0, r4
    jsr @r14
    mov r3, r5
    mov #0x40, r6
    mov.l   .L_060137F4, r4
    jsr @r14
    mov.l @(4, r15), r5
    mov.l   .L_060137F8, r5
    mov.l   .L_060137FC, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_06013800, r14
    mov #0x4, r5
    jsr @r14
    mov #0x10, r4
    mov.w   .L_060137C4, r4
    jsr @r14
    mov #0x5, r5
    mov #0x6, r5
    jsr @r14
    mov #0x8, r4
    mov.l   .L_06013804, r4
    mov.l   .L_06013808, r3
    mov.l   .L_0601380C, r1
    mov.l @r4, r4
    shll2 r4
    add r4, r3
    mov.l @r3, r2
    mov.l r2, @r1
    mov.l   .L_06013810, r3
    mov.l   .L_06013814, r1
    add r3, r4
    mov.l @r4, r2
    mov.l r2, @r1
    .byte   0xB2, 0x59    /* bsr 0x06013C58 (external) */
    nop
    mov.l   .L_06013818, r6
    mov #0xF, r4
    mov.l r4, @r6
    bra     .L_0601381C
    nop

    .global DAT_060137b0
DAT_060137b0:
    .2byte  0x74D0
.L_060137B2:
    .2byte  0x0930
.L_060137B4:
    .2byte  0x00A0

    .global DAT_060137b6
DAT_060137b6:
    .2byte  0x75F5

    .global DAT_060137b8
DAT_060137b8:
    .2byte  0x76D2

    .global DAT_060137ba
DAT_060137ba:
    .2byte  0x778E

    .global DAT_060137bc
DAT_060137bc:
    .2byte  0x784A

    .global DAT_060137be
DAT_060137be:
    .2byte  0x78E3

    .global DAT_060137c0
DAT_060137c0:
    .2byte  0x7987

    .global DAT_060137c2
DAT_060137c2:
    .2byte  0x7D47
.L_060137C4:
    .2byte  0x0100
    .2byte  0xFFFF
.L_060137C8:
    .4byte  memcpy_word_idx
.L_060137CC:
    .4byte  sym_0604878C
.L_060137D0:
    .4byte  0x25F00000
.L_060137D4:
    .4byte  sym_0604814C
.L_060137D8:
    .4byte  0x25F00600
.L_060137DC:
    .4byte  sym_0604848C
.L_060137E0:
    .4byte  0x25F00660
.L_060137E4:
    .4byte  sym_060484CC
.L_060137E8:
    .4byte  0x25F006A0
.L_060137EC:
    .4byte  sym_060485AC
.L_060137F0:
    .4byte  0x25F006E0
.L_060137F4:
    .4byte  0x25F004E0
.L_060137F8:
    .4byte  sym_0605CD9C
.L_060137FC:
    .4byte  0x25F00720
.L_06013800:
    .4byte  channel_nibble_config
.L_06013804:
    .4byte  sym_0607EAD8
.L_06013808:
    .4byte  sym_0605AD14
.L_0601380C:
    .4byte  sym_06084B00
.L_06013810:
    .4byte  sym_0605AD20
.L_06013814:
    .4byte  sym_06084B1C
.L_06013818:
    .4byte  sym_06084B08
.L_0601381C:
    .byte   0xD3, 0x2F    /* mov.l .L_game_timer_addr, r3 */
    mov.l r4, @r3
    mov #0x0, r2
    .byte   0xD3, 0x2F    /* mov.l .L_game_counter_addr, r3 */
    mov.l r2, @r3
    mov #0x50, r2
    .byte   0xD3, 0x2E    /* mov.l .L_init_param_0x50, r3 */
    mov.l r2, @r3
    .byte   0x92, 0x53    /* mov.w .L_vdp1_erase_color, r2 */
    .byte   0xD3, 0x2E    /* mov.l .L_vdp1_framebuf_cfg, r3 */
    mov.w r2, @r3
    .byte   0x92, 0x51    /* mov.w .L_display_res_param, r2 */
    .byte   0xD3, 0x2D    /* mov.l .L_display_mode_addr, r3 */
    mov.l r2, @r3
    mov #0x0, r5
    extu.b r5, r2
    .byte   0xD3, 0x2C    /* mov.l .L_player_state_byte, r3 */
    mov.b r2, @r3
    .byte   0xD4, 0x2C    /* mov.l .L_player_flags_base, r4 */
    extu.b r5, r3
    mov.b r3, @r4
    add #0x1, r4
    extu.b r5, r3
    mov.b r3, @r4
    add #0x1, r4
    extu.b r5, r3
    mov.b r3, @r4
    add #0x1, r4
    extu.b r5, r5
    mov.b r5, @r4
    mov.l @r6, r4
    shll2 r4
    .byte   0xD3, 0x26    /* mov.l .L_course_seg_table, r3 */
    .byte   0xD1, 0x27    /* mov.l .L_track_seg_count_addr, r1 */
    shll2 r4
    shll r4
    add r3, r4
    mov.w @(24, r4), r0
    mov r0, r2
    mov.w r2, @r1
    mov #0x0, r1
    mov.l @r4, r3
    .byte   0x92, 0x33    /* mov.w .L_course_data_offset, r2 */
    add r2, r3
    .byte   0xD2, 0x22    /* mov.l .L_course_base_addr, r2 */
    mov.l r3, @r2
    .byte   0xD2, 0x22    /* mov.l .L_race_lap_count_addr, r2 */
    mov.w r1, @r2
    .byte   0xD5, 0x22    /* mov.l .L_fn_course_data_init, r5 */
    .byte   0xD2, 0x23    /* mov.l .L_fn_race_config, r2 */
    jsr @r2
    mov r1, r4
    .byte   0xD3, 0x22    /* mov.l .L_fn_final_init, r3 */
    jsr @r3
    nop
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x1E    /* mov.l .L_fn_tail_call, r3 */
    jmp @r3
    mov.l @r15+, r14
