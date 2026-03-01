
    .section .text.FUN_0600EC78


    .global car_physics_init
    .type car_physics_init, @function
car_physics_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0600ED84, r3
    jsr @r3
    nop
    mov.l   .L_0600ED88, r4
    mov.l   .L_0600ED8C, r14
    mov.l   .L_0600ED90, r5
    mov.l @r5, r5
    shll2 r5
    shll r5
    mov.l @r14, r3
    add r3, r5
    mov r5, r2
    add #0x40, r2
    mov.l r2, @r4
    mov.w   .L_0600ED60, r10
    mov r2, r3
    add r10, r3
    mov.l   .L_0600ED94, r2
    mov.l r3, @r2
    mov.l   .L_0600ED98, r4
    mov r4, r6
    mov.w   DAT_0600ed62, r1
    add r1, r5
    mov.l r5, @r6
    mov r6, r5
    add #0x4, r5
    mov.l @r6, r3
    add #0x20, r3
    mov.l r3, @r5
    mov r3, r2
    add #0x20, r2
    mov.l r2, @(8, r4)
    mov #0x0, r3
    mov.l   .L_0600ED9C, r2
    mov.l r3, @r2
    mov.w   DAT_0600ed64, r3
    mov.l   .L_0600EDA0, r2
    mov.l r3, @r2
    mov.l   .L_0600EDA4, r3
    mov.w   .L_0600ED66, r5
    mov.l @r3, r3
    jsr @r3
    mov #-0x1, r4
    mov.l   .L_0600EDA8, r3
    jsr @r3
    nop
    mov.l   .L_0600EDA4, r2
    mov.w   .L_0600ED68, r4
    mov.l @r2, r2
    jsr @r2
    mov #0x0, r5
    mov #0x60, r6
    mov.l   .L_0600EDAC, r5
    mov.l   .L_0600EDB0, r3
    jsr @r3
    mov.l @r14, r4
    mov #0x3, r2
    mov.l   .L_0600EDB4, r3
    mov #0x0, r11
    mov.l r2, @r3
    mov r11, r6
    mov.l @r14, r2
    mov.l   .L_0600EDB8, r3
    add #0x60, r2
    mov.w r3, @r2
    mov.l   .L_0600EDBC, r2
    mov.w r11, @r2
    mov.w   .L_0600ED6A, r12
    mov.l   .L_0600EDC0, r14
    mov.l   .L_0600EDC4, r13
    mov.w   DAT_0600ed6c, r7
    mov r12, r5
    add r13, r7
    jsr @r14
    mov #0x1, r4
    mov.w   DAT_0600ed6e, r7
    mov r11, r6
    mov.w   .L_0600ED70, r5
    add r13, r7
    jsr @r14
    mov #0x2, r4
    mov.w   DAT_0600ed72, r7
    mov r11, r6
    mov.w   DAT_0600ed74, r5
    add r13, r7
    jsr @r14
    mov #0x3, r4
    mov.w   DAT_0600ed76, r7
    mov r11, r6
    mov.w   DAT_0600ed78, r5
    add r13, r7
    jsr @r14
    mov #0x4, r4
    mov.w   DAT_0600ed7a, r7
    mov r11, r6
    mov.w   .L_0600ED7C, r5
    add r13, r7
    jsr @r14
    mov #0x5, r4
    mov.w   DAT_0600ed7e, r7
    mov r11, r6
    mov.w   DAT_0600ed80, r5
    add r13, r7
    jsr @r14
    mov #0x6, r4
    bra     .L_0600EDC8
    nop
.L_0600ED60:
    .2byte  0x00C0

    .global DAT_0600ed62
DAT_0600ed62:
    .2byte  0x03C0

    .global DAT_0600ed64
DAT_0600ed64:
    .2byte  0x20D8
.L_0600ED66:
    .2byte  0x0083
.L_0600ED68:
    .2byte  0xFF7C
.L_0600ED6A:
    .2byte  0x0108

    .global DAT_0600ed6c
DAT_0600ed6c:
    .2byte  0x299B

    .global DAT_0600ed6e
DAT_0600ed6e:
    .2byte  0x29A3
.L_0600ED70:
    .2byte  0x0810

    .global DAT_0600ed72
DAT_0600ed72:
    .2byte  0x2A53

    .global DAT_0600ed74
DAT_0600ed74:
    .2byte  0x0512

    .global DAT_0600ed76
DAT_0600ed76:
    .2byte  0x2B27

    .global DAT_0600ed78
DAT_0600ed78:
    .2byte  0x083C

    .global DAT_0600ed7a
DAT_0600ed7a:
    .2byte  0x2E73
.L_0600ED7C:
    .2byte  0x0519

    .global DAT_0600ed7e
DAT_0600ed7e:
    .2byte  0x2F93

    .global DAT_0600ed80
DAT_0600ed80:
    .2byte  0x080F
    .2byte  0xFFFF
.L_0600ED84:
    .4byte  vdp1_init
.L_0600ED88:
    .4byte  sym_06078884
.L_0600ED8C:
    .4byte  sym_06063F5C
.L_0600ED90:
    .4byte  sym_06059FFC
.L_0600ED94:
    .4byte  sym_06078880
.L_0600ED98:
    .4byte  sym_06078888
.L_0600ED9C:
    .4byte  sym_0606A4F4
.L_0600EDA0:
    .4byte  sym_0606A4EC
.L_0600EDA4:
    .4byte  sym_06000344
.L_0600EDA8:
    .4byte  sym_06012E00
.L_0600EDAC:
    .4byte  sym_0605A018
.L_0600EDB0:
    .4byte  dma_transfer
.L_0600EDB4:
    .4byte  sym_0605A008
.L_0600EDB8:
    .4byte  0x00008000
.L_0600EDBC:
    .4byte  sym_06089E44
.L_0600EDC0:
    .4byte  vdp1_sprite_render
.L_0600EDC4:
    .4byte  0x002A0000
.L_0600EDC8:
    mov.w   DAT_0600eeba, r7
    mov #0x4, r6
    mov.w   .L_0600EEBC, r5
    add r13, r7
    jsr @r14
    mov #0x7, r4
    mov.w   DAT_0600eebe, r7
    mov #0x4, r6
    mov.w   .L_0600EEBC, r5
    add r13, r7
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_0600eec0, r7
    mov r11, r6
    mov.w   .L_0600EEC2, r5
    add r13, r7
    jsr @r14
    mov #0x9, r4
    mov.w   DAT_0600eec4, r7
    mov #0x3C, r6
    mov.w   .L_0600EEC6, r5
    add r13, r7
    jsr @r14
    mov #0xA, r4
    mov.w   DAT_0600eec8, r7
    mov #0x8, r6
    mov.w   .L_0600EECA, r5
    add r13, r7
    jsr @r14
    mov #0x10, r4
    mov.w   DAT_0600eecc, r7
    mov #0x8, r6
    mov.w   .L_0600EECE, r5
    add r13, r7
    jsr @r14
    mov #0x11, r4
    mov.w   DAT_0600eed0, r7
    mov #0x8, r6
    mov.w   .L_0600EED2, r5
    add r13, r7
    jsr @r14
    mov #0x12, r4
    mov.w   DAT_0600eed4, r7
    mov #0x8, r6
    mov.w   .L_0600EED6, r5
    add r13, r7
    jsr @r14
    mov #0x13, r4
    mov.w   DAT_0600eed8, r7
    mov #0x8, r6
    mov.w   .L_0600EEDA, r5
    add r13, r7
    jsr @r14
    mov #0x14, r4
    mov.w   DAT_0600eedc, r7
    mov #0x8, r6
    mov.w   .L_0600EEDA, r5
    add r13, r7
    jsr @r14
    mov #0x15, r4
    mov.w   DAT_0600eede, r7
    mov #0xC, r6
    mov.w   .L_0600EEE0, r5
    add r13, r7
    jsr @r14
    mov #0x16, r4
    mov.w   DAT_0600eee2, r7
    mov #0x8, r6
    mov.w   .L_0600EEE4, r5
    add r13, r7
    jsr @r14
    mov #0x17, r4
    mov.w   DAT_0600eee6, r7
    mov #0x1C, r6
    mov.w   DAT_0600eee8, r5
    add r13, r7
    jsr @r14
    mov #0x18, r4
    mov.w   .L_0600EEEA, r9
    mov #0x10, r6
    mov.w   DAT_0600eeec, r7
    mov r9, r5
    add r13, r7
    jsr @r14
    mov #0x19, r4
    mov #0x10, r6
    mov r9, r5
    mov.w   DAT_0600eeee, r7
    add r13, r7
    jsr @r14
    mov #0x1A, r4
    mov #0x10, r6
    mov r9, r5
    mov.w   DAT_0600eef0, r7
    add r13, r7
    jsr @r14
    mov #0x1B, r4
    mov #0x1C, r6
    mov.w   .L_0600EEF4, r5
    mov.w   DAT_0600eef2, r7
    add r13, r7
    jsr @r14
    mov r6, r4
    mov #0x10, r6
    mov.w   .L_0600EEC6, r5
    mov.w   DAT_0600eef6, r7
    add r13, r7
    jsr @r14
    mov #0x1D, r4
    mov #0x18, r6
    mov.w   .L_0600EEFA, r5
    mov.w   DAT_0600eef8, r7
    add r13, r7
    jsr @r14
    mov #0x1E, r4
    mov.w   DAT_0600eefc, r7
    add r13, r7
    mov #0x18, r6
    mov.w   .L_0600EEFE, r5
    bra     .L_0600EF00
    mov #0x1F, r4

    .global DAT_0600eeba
DAT_0600eeba:
    .2byte  0x3027
.L_0600EEBC:
    .2byte  0x0738

    .global DAT_0600eebe
DAT_0600eebe:
    .2byte  0x325B

    .global DAT_0600eec0
DAT_0600eec0:
    .2byte  0x3433
.L_0600EEC2:
    .2byte  0x0208

    .global DAT_0600eec4
DAT_0600eec4:
    .2byte  0x3457
.L_0600EEC6:
    .2byte  0x0A28

    .global DAT_0600eec8
DAT_0600eec8:
    .2byte  0x0640
.L_0600EECA:
    .2byte  0x0228

    .global DAT_0600eecc
DAT_0600eecc:
    .2byte  0x06AC
.L_0600EECE:
    .2byte  0x0428

    .global DAT_0600eed0
DAT_0600eed0:
    .2byte  0x074C
.L_0600EED2:
    .2byte  0x0418

    .global DAT_0600eed4
DAT_0600eed4:
    .2byte  0x07E4
.L_0600EED6:
    .2byte  0x0820

    .global DAT_0600eed8
DAT_0600eed8:
    .2byte  0x09B4
.L_0600EEDA:
    .2byte  0x0518

    .global DAT_0600eedc
DAT_0600eedc:
    .2byte  0x0A34

    .global DAT_0600eede
DAT_0600eede:
    .2byte  0x0AA4
.L_0600EEE0:
    .2byte  0x0508

    .global DAT_0600eee2
DAT_0600eee2:
    .2byte  0x0AD8
.L_0600EEE4:
    .2byte  0x0D10

    .global DAT_0600eee6
DAT_0600eee6:
    .2byte  0x0C14

    .global DAT_0600eee8
DAT_0600eee8:
    .2byte  0x041C
.L_0600EEEA:
    .2byte  0x0348

    .global DAT_0600eeec
DAT_0600eeec:
    .2byte  0x0D7C

    .global DAT_0600eeee
DAT_0600eeee:
    .2byte  0x0F58

    .global DAT_0600eef0
DAT_0600eef0:
    .2byte  0x1140

    .global DAT_0600eef2
DAT_0600eef2:
    .2byte  0x12F8
.L_0600EEF4:
    .2byte  0x0630

    .global DAT_0600eef6
DAT_0600eef6:
    .2byte  0x1484

    .global DAT_0600eef8
DAT_0600eef8:
    .2byte  0x1890
.L_0600EEFA:
    .2byte  0x0C08

    .global DAT_0600eefc
DAT_0600eefc:
    .2byte  0x1908
.L_0600EEFE:
    .2byte  0x0C10
.L_0600EF00:
    jsr @r14
    nop
    mov.w   .L_0600EFFC, r9
    mov #0xC, r6
    mov.w   DAT_0600effe, r7
    mov r9, r5
    add r13, r7
    jsr @r14
    mov #0x20, r4
    mov #0xC, r6
    mov.w   .L_0600F002, r5
    mov.w   DAT_0600f000, r7
    add r13, r7
    jsr @r14
    mov #0x21, r4
    mov #0xC, r6
    mov r9, r5
    mov.w   DAT_0600f004, r7
    add r13, r7
    jsr @r14
    mov #0x22, r4
    mov #0xC, r6
    mov r9, r5
    mov.w   DAT_0600f006, r7
    add r13, r7
    jsr @r14
    mov #0x23, r4
    mov #0xC, r6
    mov.w   .L_0600F002, r5
    mov.w   DAT_0600f008, r7
    add r13, r7
    jsr @r14
    mov #0x24, r4
    mov #0x14, r6
    mov.w   DAT_0600f00c, r5
    mov.w   DAT_0600f00a, r7
    add r13, r7
    jsr @r14
    mov #0x25, r4
    mov #0x14, r6
    mov.w   DAT_0600f00c, r5
    mov.w   DAT_0600f00e, r7
    add r13, r7
    jsr @r14
    mov #0x26, r4
    mov #0xC, r6
    mov.w   .L_0600F012, r5
    mov.w   DAT_0600f010, r7
    add r13, r7
    jsr @r14
    mov #0x27, r4
    mov #0x14, r6
    mov.w   .L_0600F016, r5
    mov.w   DAT_0600f014, r7
    add r13, r7
    jsr @r14
    mov #0x28, r4
    mov #0x14, r6
    mov.w   .L_0600F01A, r5
    mov.w   DAT_0600f018, r7
    add r13, r7
    jsr @r14
    mov #0x29, r4
    mov #0x14, r6
    mov.w   DAT_0600f01e, r5
    mov.w   DAT_0600f01c, r7
    add r13, r7
    jsr @r14
    mov #0x2A, r4
    mov #0x14, r6
    mov.w   DAT_0600f022, r5
    mov.w   DAT_0600f020, r7
    add r13, r7
    jsr @r14
    mov #0x2B, r4
    mov #0xC, r6
    mov.w   .L_0600F026, r5
    mov.w   DAT_0600f024, r7
    add r13, r7
    jsr @r14
    mov #0x2C, r4
    mov #0xC, r6
    mov.w   .L_0600F026, r5
    mov.w   DAT_0600f028, r7
    add r13, r7
    jsr @r14
    mov #0x2D, r4
    mov #0x14, r6
    mov.w   .L_0600F016, r5
    mov.w   DAT_0600f02a, r7
    add r13, r7
    jsr @r14
    mov #0x2E, r4
    mov #0x14, r6
    mov.w   .L_0600F01A, r5
    mov.w   DAT_0600f02c, r7
    add r13, r7
    jsr @r14
    mov #0x2F, r4
    mov #0x14, r6
    mov.w   DAT_0600f01e, r5
    mov.w   DAT_0600f02e, r7
    add r13, r7
    jsr @r14
    mov #0x30, r4
    mov #0x14, r6
    mov.w   DAT_0600f022, r5
    mov.w   DAT_0600f030, r7
    add r13, r7
    jsr @r14
    mov #0x31, r4
    mov #0x14, r6
    mov r12, r5
    mov.w   DAT_0600f032, r7
    add r13, r7
    jsr @r14
    mov #0x32, r4
    mov #0x14, r6
    mov r12, r5
    mov.w   DAT_0600f034, r7
    add r13, r7
    jsr @r14
    mov #0x33, r4
    mov.w   DAT_0600f036, r7
    bra     .L_0600F038
    nop
.L_0600EFFC:
    .2byte  0x0308

    .global DAT_0600effe
DAT_0600effe:
    .2byte  0x1AC4

    .global DAT_0600f000
DAT_0600f000:
    .2byte  0x1B04
.L_0600F002:
    .2byte  0x0410

    .global DAT_0600f004
DAT_0600f004:
    .2byte  0x1B9C

    .global DAT_0600f006
DAT_0600f006:
    .2byte  0x1BC8

    .global DAT_0600f008
DAT_0600f008:
    .2byte  0x1C04

    .global DAT_0600f00a
DAT_0600f00a:
    .2byte  0x1CC8

    .global DAT_0600f00c
DAT_0600f00c:
    .2byte  0x060C

    .global DAT_0600f00e
DAT_0600f00e:
    .2byte  0x1D2C

    .global DAT_0600f010
DAT_0600f010:
    .2byte  0x1D84
.L_0600F012:
    .2byte  0x0610

    .global DAT_0600f014
DAT_0600f014:
    .2byte  0x1E20
.L_0600F016:
    .2byte  0x0510

    .global DAT_0600f018
DAT_0600f018:
    .2byte  0x1E8C
.L_0600F01A:
    .2byte  0x0310

    .global DAT_0600f01c
DAT_0600f01c:
    .2byte  0x1EFC

    .global DAT_0600f01e
DAT_0600f01e:
    .2byte  0x090C

    .global DAT_0600f020
DAT_0600f020:
    .2byte  0x1FC8

    .global DAT_0600f022
DAT_0600f022:
    .2byte  0x080C

    .global DAT_0600f024
DAT_0600f024:
    .2byte  0x2060
.L_0600F026:
    .2byte  0x0110

    .global DAT_0600f028
DAT_0600f028:
    .2byte  0x2080

    .global DAT_0600f02a
DAT_0600f02a:
    .2byte  0x20A0

    .global DAT_0600f02c
DAT_0600f02c:
    .2byte  0x211C

    .global DAT_0600f02e
DAT_0600f02e:
    .2byte  0x2194

    .global DAT_0600f030
DAT_0600f030:
    .2byte  0x225C

    .global DAT_0600f032
DAT_0600f032:
    .2byte  0x22F4

    .global DAT_0600f034
DAT_0600f034:
    .2byte  0x22FC

    .global DAT_0600f036
DAT_0600f036:
    .2byte  0x2304
.L_0600F038:
    add r13, r7
    mov #0x14, r6
    mov r12, r5
    jsr @r14
    mov #0x34, r4
    mov #0x14, r6
    mov r12, r5
    mov.w   DAT_0600f14c, r7
    add r13, r7
    jsr @r14
    mov #0x35, r4
    mov #0x10, r6
    mov r12, r5
    mov.w   DAT_0600f14e, r7
    add r13, r7
    jsr @r14
    mov #0x36, r4
    mov #0x1C, r6
    mov r12, r5
    mov.w   DAT_0600f150, r7
    add r13, r7
    jsr @r14
    mov #0x37, r4
    mov #0x8, r6
    mov r12, r5
    mov.w   DAT_0600f152, r7
    add r13, r7
    jsr @r14
    mov #0x38, r4
    mov #0x10, r6
    mov r12, r5
    mov.w   .L_0600F154, r7
    add r13, r7
    jsr @r14
    mov #0x39, r4
    mov #0x1, r3
    mov r11, r6
    mov.l   .L_0600F158, r2
    mov r3, r5
    mov.w r3, @r2
    mov.l   .L_0600F15C, r12
    jsr @r12
    mov #0x41, r4
    mov r11, r6
    mov #0x2, r5
    jsr @r12
    mov #0x42, r4
    mov r11, r6
    mov #0x3, r5
    jsr @r12
    mov #0x43, r4
    mov r11, r6
    mov #0x4, r5
    jsr @r12
    mov #0x44, r4
    mov r11, r6
    mov #0x5, r5
    jsr @r12
    mov #0x45, r4
    mov r11, r6
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
    mov r11, r6
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
    bra     .L_0600F160
    nop

    .global DAT_0600f14c
DAT_0600f14c:
    .2byte  0x230C

    .global DAT_0600f14e
DAT_0600f14e:
    .2byte  0x2314

    .global DAT_0600f150
DAT_0600f150:
    .2byte  0x231C

    .global DAT_0600f152
DAT_0600f152:
    .2byte  0x2324
.L_0600F154:
    .2byte  0x232C
    .2byte  0xFFFF
.L_0600F158:
    .4byte  sym_06089E46
.L_0600F15C:
    .4byte  sym_06007540
.L_0600F160:
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
    mov #0x78, r6
    mov.w   .L_0600F26E, r4
    mov.w   .L_0600F26A, r8
    mov.w   DAT_0600f26c, r7
    add r13, r7
    jsr @r14
    mov r8, r5
    mov.w   DAT_0600f270, r7
    mov #0x7C, r6
    mov.w   DAT_0600f272, r4
    add r13, r7
    jsr @r14
    mov r8, r5
    mov.w   .L_0600F274, r9
    mov.w   DAT_0600f276, r7
    mov.w   .L_0600F278, r4
    mov r9, r6
    add r13, r7
    jsr @r14
    mov r8, r5
    bra     .L_0600F27A
    nop
.L_0600F26A:
    .2byte  0x0B40

    .global DAT_0600f26c
DAT_0600f26c:
    .2byte  0x4B46
.L_0600F26E:
    .2byte  0x0101

    .global DAT_0600f270
DAT_0600f270:
    .2byte  0x5313

    .global DAT_0600f272
DAT_0600f272:
    .2byte  0x0102
.L_0600F274:
    .2byte  0x0080

    .global DAT_0600f276
DAT_0600f276:
    .2byte  0x5B86
.L_0600F278:
    .2byte  0x0103
.L_0600F27A:
    mov.w   DAT_0600f342, r6
    mov.w   DAT_0600f344, r4
    mov r6, r5
    jsr @r12
    add #0x7D, r5
    mov.w   DAT_0600f346, r6
    mov.w   DAT_0600f348, r4
    mov r6, r5
    jsr @r12
    add #0x7A, r5
    mov.w   DAT_0600f34a, r6
    mov.w   .L_0600F34C, r4
    mov r6, r5
    jsr @r12
    add #0x77, r5
    mov.l   .L_0600F350, r2
    mov.l   .L_0600F354, r3
    mov.w r2, @r3
    mov r3, r6
    mov.l   .L_0600F358, r4
    mov.l   .L_0600F35C, r3
    jsr @r3
    mov #0x1, r5
    mov.l   .L_0600F360, r3
    jsr @r3
    nop
    mov.l   .L_0600F364, r3
    jsr @r3
    nop
    mov.l   .L_0600F368, r3
    jsr @r3
    nop
    mov r10, r6
    mov.l   .L_0600F370, r2
    mov.l   .L_0600F36C, r14
    mov.l r2, @r15
    mov.l   .L_0600F374, r4
    jsr @r14
    mov r2, r5
    mov r10, r6
    mov.l   .L_0600F378, r4
    jsr @r14
    mov.l @r15, r5
    mov #0x20, r6
    mov.l   .L_0600F37C, r3
    mov.l r3, @r15
    mov.l   .L_0600F380, r4
    jsr @r14
    mov r3, r5
    mov #0x20, r6
    mov.l   .L_0600F384, r4
    jsr @r14
    mov.l @r15, r5
    mov #0x40, r6
    mov.l   .L_0600F388, r3
    mov.l r3, @r15
    mov.l   .L_0600F38C, r4
    jsr @r14
    mov r3, r5
    mov #0x40, r6
    mov.l   .L_0600F390, r4
    jsr @r14
    mov.l @r15, r5
    mov #0x20, r6
    mov.l   .L_0600F394, r3
    mov.l r3, @r15
    mov.l   .L_0600F398, r4
    jsr @r14
    mov r3, r5
    mov #0x20, r6
    mov.l   .L_0600F39C, r4
    jsr @r14
    mov.l @r15, r5
    mov.l   .L_0600F3A0, r5
    mov.l   .L_0600F3A4, r4
    jsr @r14
    mov #0x40, r6
    mov #0x60, r6
    mov.l   .L_0600F3A8, r3
    mov.l r3, @r15
    mov.l   .L_0600F3AC, r4
    jsr @r14
    mov r3, r5
    mov #0x60, r6
    mov.l   .L_0600F3B0, r4
    jsr @r14
    mov.l @r15, r5
    mov.l   .L_0600F3B4, r5
    mov.l   .L_0600F3B8, r4
    jsr @r14
    mov #0x20, r6
    mov r9, r6
    mov.l   .L_0600F3BC, r3
    mov.l r3, @r15
    mov.l   .L_0600F3C0, r4
    jsr @r14
    mov r3, r5
    mov r9, r6
    bra     .L_0600F3C4
    mov.l @r15, r5

    .global DAT_0600f342
DAT_0600f342:
    .2byte  0x0084

    .global DAT_0600f344
DAT_0600f344:
    .2byte  0x0104

    .global DAT_0600f346
DAT_0600f346:
    .2byte  0x0088

    .global DAT_0600f348
DAT_0600f348:
    .2byte  0x0105

    .global DAT_0600f34a
DAT_0600f34a:
    .2byte  0x008C
.L_0600F34C:
    .2byte  0x0106
    .2byte  0xFFFF
.L_0600F350:
    .4byte  0x00008000
.L_0600F354:
    .4byte  sym_06086028
.L_0600F358:
    .4byte  0x25F00FFE
.L_0600F35C:
    .4byte  tilemap_dma_update
.L_0600F360:
    .4byte  sym_060149E0
.L_0600F364:
    .4byte  audio_display_init
.L_0600F368:
    .4byte  render_coord_transform
.L_0600F36C:
    .4byte  memcpy_word_idx
.L_0600F370:
    .4byte  sym_060484EC
.L_0600F374:
    .4byte  0x25F00060
.L_0600F378:
    .4byte  0x25F00460
.L_0600F37C:
    .4byte  sym_0604870C
.L_0600F380:
    .4byte  0x25F00520
.L_0600F384:
    .4byte  0x25F00540
.L_0600F388:
    .4byte  sym_0604842C
.L_0600F38C:
    .4byte  0x25F001A0
.L_0600F390:
    .4byte  0x25F007A0
.L_0600F394:
    .4byte  sym_0604846C
.L_0600F398:
    .4byte  0x25F001E0
.L_0600F39C:
    .4byte  0x25F007E0
.L_0600F3A0:
    .4byte  sym_0605CA5C
.L_0600F3A4:
    .4byte  0x25F005A0
.L_0600F3A8:
    .4byte  sym_0604814C
.L_0600F3AC:
    .4byte  0x25F00000
.L_0600F3B0:
    .4byte  0x25F00600
.L_0600F3B4:
    .4byte  sym_060484CC
.L_0600F3B8:
    .4byte  0x25F006A0
.L_0600F3BC:
    .4byte  sym_060487AC
.L_0600F3C0:
    .4byte  0x25F00120
.L_0600F3C4:
    .byte   0xD4, 0x27    /* mov.l .L_pool_0600F464, r4 */
    jsr @r14
    nop
    mov #0x20, r6
    .byte   0xD3, 0x26    /* mov.l .L_pool_0600F468, r3 */
    mov.l r3, @r15
    .byte   0xD4, 0x26    /* mov.l .L_pool_0600F46C, r4 */
    jsr @r14
    mov r3, r5
    mov #0x20, r6
    .byte   0xD4, 0x25    /* mov.l .L_pool_0600F470, r4 */
    jsr @r14
    mov.l @r15, r5
    mov #0x20, r6
    .byte   0xD3, 0x24    /* mov.l .L_pool_0600F474, r3 */
    mov.l r3, @r15
    .byte   0xD4, 0x24    /* mov.l .L_pool_0600F478, r4 */
    jsr @r14
    mov r3, r5
    mov #0x20, r6
    .byte   0xD4, 0x23    /* mov.l .L_pool_0600F47C, r4 */
    jsr @r14
    mov.l @r15, r5
    extu.w r11, r3
    .byte   0xD2, 0x22    /* mov.l .L_pool_0600F480, r2 */
    mov.w r3, @r2
    .byte   0xD2, 0x22    /* mov.l .L_pool_0600F484, r2 */
    mov.b r11, @r2
    .byte   0xD4, 0x22    /* mov.l .L_pool_0600F488, r4 */
    .byte   0xD1, 0x23    /* mov.l .L_pool_0600F48C, r1 */
    .byte   0xD3, 0x23    /* mov.l .L_pool_0600F490, r3 */
    mov.l @r4, r2
    or r1, r2
    jsr @r3
    mov.l r2, @r4
    mov r11, r2
    .byte   0xD3, 0x21    /* mov.l .L_pool_0600F494, r3 */
    mov.l r11, @r3
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
