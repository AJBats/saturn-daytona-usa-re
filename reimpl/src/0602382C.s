	.text
    .global scene_setup_master
scene_setup_master:
    sts.l pr, @-r15
    mov #0x0, r2
    add #-0x8, r15
    mov.l   .L_0602390C, r3
    mov.w r2, @r3
    mov r2, r3
    mov r3, r0
    mov r3, r6
    mov.w r0, @(6, r15)
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_06023910, r7
    mov.w   .L_060238FA, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023914, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1, r4
    mov #0x0, r6
    mov.w   .L_060238FC, r5
    mov.l   .L_06023918, r7
    mov.w @(6, r15), r0
    mov.l   .L_06023914, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2, r4
    mov.l   .L_0602391C, r7
    mov #0x0, r6
    mov.w   DAT_060238fe, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023914, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x3, r4
    mov #0x0, r6
    mov.w   DAT_06023900, r5
    mov.l   .L_06023920, r7
    mov.w @(6, r15), r0
    mov.l   .L_06023914, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x4, r4
    mov.l   .L_06023924, r7
    mov #0x0, r6
    mov.w   .L_06023902, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023914, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x5, r4
    mov #0x0, r6
    mov.w   DAT_06023904, r5
    mov.l   .L_06023928, r7
    mov.w @(6, r15), r0
    mov.l   .L_06023914, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x6, r4
    mov.l   .L_0602392C, r7
    mov #0x4, r6
    mov.w   .L_06023906, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023914, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x7, r4
    mov #0x4, r6
    mov.w   .L_06023906, r5
    mov.l   .L_06023930, r7
    mov.w @(6, r15), r0
    mov.l   .L_06023914, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x8, r4
    mov.l   .L_06023934, r7
    mov #0x0, r6
    mov.w   .L_06023908, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023914, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x9, r4
    mov #0x3C, r6
    mov.w   .L_0602390A, r5
    mov.l   .L_06023938, r7
    mov.w @(6, r15), r0
    mov.l   .L_06023914, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xA, r4
    mov.l   .L_0602393C, r7
    bra     .L_06023940
    nop
.L_060238FA:
    .short  0x0108
.L_060238FC:
    .short  0x0810

    .global DAT_060238fe
DAT_060238fe:
    .short  0x0512

    .global DAT_06023900
DAT_06023900:
    .short  0x083C
.L_06023902:
    .short  0x0519

    .global DAT_06023904
DAT_06023904:
    .short  0x080F
.L_06023906:
    .short  0x0738
.L_06023908:
    .short  0x0208
.L_0602390A:
    .short  0x0A28
.L_0602390C:
    .long  sym_06089E44
.L_06023910:
    .long  0x002A299B
.L_06023914:
    .long  vdp1_sprite_render
.L_06023918:
    .long  0x002A29A3
.L_0602391C:
    .long  0x002A2A53
.L_06023920:
    .long  0x002A2B27
.L_06023924:
    .long  0x002A2E73
.L_06023928:
    .long  0x002A2F93
.L_0602392C:
    .long  0x002A3027
.L_06023930:
    .long  0x002A325B
.L_06023934:
    .long  0x002A3433
.L_06023938:
    .long  0x002A3457
.L_0602393C:
    .long  0x002A0640
.L_06023940:
    mov.w @(4, r15), r0
    mov.w   .L_06023A54, r5
    mov.l   .L_06023A68, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x10, r4
    mov.l   .L_06023A6C, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023A56, r5
    mov.l   .L_06023A68, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x11, r4
    mov.l   .L_06023A70, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023A58, r5
    mov.l   .L_06023A68, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x12, r4
    mov.l   .L_06023A74, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023A5A, r5
    mov.l   .L_06023A68, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x13, r4
    mov.l   .L_06023A78, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023A5C, r5
    mov.l   .L_06023A68, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x14, r4
    mov.l   .L_06023A7C, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023A5C, r5
    mov.l   .L_06023A68, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x15, r4
    mov.l   .L_06023A80, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023A5E, r5
    mov.l   .L_06023A68, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x16, r4
    mov.l   .L_06023A84, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023A60, r5
    mov.l   .L_06023A68, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x17, r4
    mov.l   .L_06023A88, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023a62, r5
    mov.l   .L_06023A68, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x7, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x18, r4
    mov.l   .L_06023A8C, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023A64, r5
    mov.l   .L_06023A68, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x4, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x19, r4
    mov.l   .L_06023A90, r7
    mov.w @(4, r15), r0
    mov r0, r6
    extu.w r6, r6
    add #0x4, r6
    shll2 r6
    mov.w   .L_06023A64, r5
    bra     .L_06023A94
    nop
.L_06023A54:
    .short  0x0228
.L_06023A56:
    .short  0x0428
.L_06023A58:
    .short  0x0418
.L_06023A5A:
    .short  0x0820
.L_06023A5C:
    .short  0x0518
.L_06023A5E:
    .short  0x0508
.L_06023A60:
    .short  0x0D10

    .global DAT_06023a62
DAT_06023a62:
    .short  0x041C
.L_06023A64:
    .short  0x0348
    .short  0xFFFF
.L_06023A68:
    .long  vdp1_sprite_render
.L_06023A6C:
    .long  0x002A06AC
.L_06023A70:
    .long  0x002A074C
.L_06023A74:
    .long  0x002A07E4
.L_06023A78:
    .long  0x002A09B4
.L_06023A7C:
    .long  0x002A0A34
.L_06023A80:
    .long  0x002A0AA4
.L_06023A84:
    .long  0x002A0AD8
.L_06023A88:
    .long  0x002A0C14
.L_06023A8C:
    .long  0x002A0D7C
.L_06023A90:
    .long  0x002A0F58
.L_06023A94:
    mov.w @(6, r15), r0
    mov.l   .L_06023BB8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1A, r4
    mov.l   .L_06023BBC, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023BA8, r5
    mov.l   .L_06023BB8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x4, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1B, r4
    mov.l   .L_06023BC0, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023BAA, r5
    mov.l   .L_06023BB8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x7, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1C, r4
    mov.l   .L_06023BC4, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023BAC, r5
    mov.l   .L_06023BB8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x4, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1D, r4
    mov.l   .L_06023BC8, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023BAE, r5
    mov.l   .L_06023BB8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x6, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1E, r4
    mov.l   .L_06023BCC, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023BB0, r5
    mov.l   .L_06023BB8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x6, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1F, r4
    mov.l   .L_06023BD0, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023BB2, r5
    mov.l   .L_06023BB8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x20, r4
    mov.l   .L_06023BD4, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023BB4, r5
    mov.l   .L_06023BB8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x21, r4
    mov.l   .L_06023BD8, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023BB2, r5
    mov.l   .L_06023BB8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x22, r4
    mov.l   .L_06023BDC, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023BB2, r5
    mov.l   .L_06023BB8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x23, r4
    mov.l   .L_06023BE0, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023BB4, r5
    mov.l   .L_06023BB8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x24, r4
    bra     .L_06023BE4
    nop
.L_06023BA8:
    .short  0x0348
.L_06023BAA:
    .short  0x0630
.L_06023BAC:
    .short  0x0A28
.L_06023BAE:
    .short  0x0C08
.L_06023BB0:
    .short  0x0C10
.L_06023BB2:
    .short  0x0308
.L_06023BB4:
    .short  0x0410
    .short  0xFFFF
.L_06023BB8:
    .long  vdp1_sprite_render
.L_06023BBC:
    .long  0x002A1140
.L_06023BC0:
    .long  0x002A12F8
.L_06023BC4:
    .long  0x002A1484
.L_06023BC8:
    .long  0x002A1890
.L_06023BCC:
    .long  0x002A1908
.L_06023BD0:
    .long  0x002A1AC4
.L_06023BD4:
    .long  0x002A1B04
.L_06023BD8:
    .long  0x002A1B9C
.L_06023BDC:
    .long  0x002A1BC8
.L_06023BE0:
    .long  0x002A1C04
.L_06023BE4:
    mov.l   .L_06023D08, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023cf8, r5
    mov.l   .L_06023D0C, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x25, r4
    mov.l   .L_06023D10, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023cf8, r5
    mov.l   .L_06023D0C, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x26, r4
    mov.l   .L_06023D14, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023CFA, r5
    mov.l   .L_06023D0C, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x27, r4
    mov.l   .L_06023D18, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023CFC, r5
    mov.l   .L_06023D0C, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x28, r4
    mov.l   .L_06023D1C, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023CFE, r5
    mov.l   .L_06023D0C, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x29, r4
    mov.l   .L_06023D20, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023d00, r5
    mov.l   .L_06023D0C, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x2A, r4
    mov.l   .L_06023D24, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023d02, r5
    mov.l   .L_06023D0C, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x2B, r4
    mov.l   .L_06023D28, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023D04, r5
    mov.l   .L_06023D0C, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x2C, r4
    mov.l   .L_06023D2C, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023D04, r5
    mov.l   .L_06023D0C, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x2D, r4
    mov.l   .L_06023D30, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023CFC, r5
    mov.l   .L_06023D0C, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x2E, r4
    mov.l   .L_06023D34, r7
    mov.w @(4, r15), r0
    mov r0, r6
    extu.w r6, r6
    add #0x5, r6
    shll2 r6
    bra     .L_06023D38
    nop

    .global DAT_06023cf8
DAT_06023cf8:
    .short  0x060C
.L_06023CFA:
    .short  0x0610
.L_06023CFC:
    .short  0x0510
.L_06023CFE:
    .short  0x0310

    .global DAT_06023d00
DAT_06023d00:
    .short  0x090C

    .global DAT_06023d02
DAT_06023d02:
    .short  0x080C
.L_06023D04:
    .short  0x0110
    .short  0xFFFF
.L_06023D08:
    .long  0x002A1CC8
.L_06023D0C:
    .long  vdp1_sprite_render
.L_06023D10:
    .long  0x002A1D2C
.L_06023D14:
    .long  0x002A1D84
.L_06023D18:
    .long  0x002A1E20
.L_06023D1C:
    .long  0x002A1E8C
.L_06023D20:
    .long  0x002A1EFC
.L_06023D24:
    .long  0x002A1FC8
.L_06023D28:
    .long  0x002A2060
.L_06023D2C:
    .long  0x002A2080
.L_06023D30:
    .long  0x002A20A0
.L_06023D34:
    .long  0x002A211C
.L_06023D38:
    mov.w   .L_06023E4E, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023E58, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2F, r4
    mov.l   .L_06023E5C, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023e50, r5
    mov.l   .L_06023E58, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x30, r4
    mov.l   .L_06023E60, r7
    mov.w @(4, r15), r0
    mov.w   DAT_06023e52, r5
    mov.l   .L_06023E58, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x31, r4
    mov.l   .L_06023E64, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023E54, r5
    mov.l   .L_06023E58, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x32, r4
    mov.l   .L_06023E68, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023E54, r5
    mov.l   .L_06023E58, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x33, r4
    mov.l   .L_06023E6C, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023E54, r5
    mov.l   .L_06023E58, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x34, r4
    mov.l   .L_06023E70, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023E54, r5
    mov.l   .L_06023E58, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x5, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x35, r4
    mov.l   .L_06023E74, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023E54, r5
    mov.l   .L_06023E58, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x4, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x36, r4
    mov.l   .L_06023E78, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023E54, r5
    mov.l   .L_06023E58, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x7, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x37, r4
    mov.l   .L_06023E7C, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023E54, r5
    mov.l   .L_06023E58, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x38, r4
    mov.l   .L_06023E80, r7
    mov.w @(4, r15), r0
    mov.w   .L_06023E54, r5
    mov.l   .L_06023E58, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x4, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x39, r4
    bra     .L_06023E84
    nop
.L_06023E4E:
    .short  0x0310

    .global DAT_06023e50
DAT_06023e50:
    .short  0x090C

    .global DAT_06023e52
DAT_06023e52:
    .short  0x080C
.L_06023E54:
    .short  0x0108
    .short  0xFFFF
.L_06023E58:
    .long  vdp1_sprite_render
.L_06023E5C:
    .long  0x002A2194
.L_06023E60:
    .long  0x002A225C
.L_06023E64:
    .long  0x002A22F4
.L_06023E68:
    .long  0x002A22FC
.L_06023E6C:
    .long  0x002A2304
.L_06023E70:
    .long  0x002A230C
.L_06023E74:
    .long  0x002A2314
.L_06023E78:
    .long  0x002A231C
.L_06023E7C:
    .long  0x002A2324
.L_06023E80:
    .long  0x002A232C
.L_06023E84:
    mov.l   .L_06023FA0, r2
    mov #0x1, r3
    mov #0x0, r6
    mov r3, r5
    mov.w r3, @r2
    mov #0x40, r2
    mov r2, r0
    mov.w r0, @(6, r15)
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1, r4
    mov #0x0, r6
    mov #0x2, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2, r4
    mov #0x0, r6
    mov #0x3, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x3, r4
    mov #0x0, r6
    mov #0x4, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x4, r4
    mov #0x0, r6
    mov #0x5, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x5, r4
    mov #0x0, r6
    mov #0x6, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x6, r4
    mov #0x4, r6
    mov #0x7, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x7, r4
    mov #0x4, r6
    mov #0x8, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x8, r4
    mov #0x0, r6
    mov #0x9, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x9, r4
    mov #0x3C, r6
    mov #0xA, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xA, r4
    mov #0x20, r6
    mov #0x10, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x10, r4
    mov #0x20, r6
    mov #0x11, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x11, r4
    mov #0x20, r6
    mov #0x12, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x12, r4
    mov #0x20, r6
    mov #0x13, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x13, r4
    mov #0x20, r6
    mov #0x14, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x14, r4
    mov #0x20, r6
    mov #0x15, r5
    mov.w @(6, r15), r0
    mov.l   .L_06023FA4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x15, r4
    mov #0x24, r6
    mov #0x16, r5
    mov.w @(6, r15), r0
    mov r0, r4
    extu.w r4, r4
    bra     .L_06023FA8
    add #0x16, r4
    .short  0xFFFF
.L_06023FA0:
    .long  sym_06089E46
.L_06023FA4:
    .long  sym_06007540
.L_06023FA8:
    mov.l   .L_060240C8, r3
    jsr @r3
    nop
    mov #0x20, r6
    mov #0x17, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x17, r4
    mov #0x34, r6
    mov #0x18, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x18, r4
    mov #0x28, r6
    mov #0x19, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x19, r4
    mov #0x28, r6
    mov #0x1A, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1A, r4
    mov #0x28, r6
    mov #0x1B, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1B, r4
    mov #0x34, r6
    mov #0x1C, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1C, r4
    mov #0x28, r6
    mov #0x1D, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1D, r4
    mov #0x30, r6
    mov #0x1E, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1E, r4
    mov #0x30, r6
    mov #0x1F, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1F, r4
    mov #0x24, r6
    mov #0x20, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x20, r4
    mov #0x24, r6
    mov #0x21, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x21, r4
    mov #0x24, r6
    mov #0x22, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x22, r4
    mov #0x24, r6
    mov #0x23, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x23, r4
    mov #0x24, r6
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r6, r5
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x24, r4
    mov #0x2C, r6
    mov #0x25, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x25, r4
    mov #0x2C, r6
    mov #0x26, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x26, r4
    mov #0x24, r6
    mov #0x27, r5
    mov.w @(6, r15), r0
    mov.l   .L_060240C8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x27, r4
    mov #0x2C, r6
    mov #0x28, r5
    bra     .L_060240CC
    nop
    .short  0xFFFF
.L_060240C8:
    .long  sym_06007540
.L_060240CC:
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x28, r4
    mov #0x2C, r6
    mov #0x29, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x29, r4
    mov #0x2C, r6
    mov #0x2A, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2A, r4
    mov #0x2C, r6
    mov #0x2B, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2B, r4
    mov #0x24, r6
    mov #0x2C, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2C, r4
    mov #0x24, r6
    mov #0x2D, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2D, r4
    mov #0x2C, r6
    mov #0x2E, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2E, r4
    mov #0x2C, r6
    mov #0x2F, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2F, r4
    mov #0x2C, r6
    mov #0x30, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x30, r4
    mov #0x2C, r6
    mov #0x31, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x31, r4
    mov #0x2C, r6
    mov #0x32, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x32, r4
    mov #0x2C, r6
    mov #0x33, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x33, r4
    mov #0x2C, r6
    mov #0x34, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x34, r4
    mov #0x2C, r6
    mov #0x35, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x35, r4
    mov #0x28, r6
    mov #0x36, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x36, r4
    mov #0x34, r6
    mov #0x37, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x37, r4
    mov #0x20, r6
    mov #0x38, r5
    mov.w @(6, r15), r0
    mov.l   .L_060241E8, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x38, r4
    mov #0x28, r6
    mov #0x39, r5
    mov.w @(6, r15), r0
    mov r0, r4
    extu.w r4, r4
    bra     .L_060241EC
    add #0x39, r4
    .short  0xFFFF
.L_060241E8:
    .long  sym_06007540
.L_060241EC:
    mov.l   .L_060242E8, r3
    jsr @r3
    nop
    mov #0x38, r3
    mov #0x40, r6
    mov.l   .L_060242EC, r2
    mov.w r3, @r2
    mov #0x0, r3
    mov.w   DAT_060242e0, r2
    mov r2, r0
    mov.w r0, @(6, r15)
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_060242F0, r7
    mov.w   .L_060242E2, r5
    mov.w @(6, r15), r0
    mov.l   .L_060242F4, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x10, r4
    mov.l   .L_060242F8, r7
    mov.w @(4, r15), r0
    mov.w   .L_060242E2, r5
    mov.l   .L_060242F4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x1D, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x11, r4
    mov.l   .L_060242FC, r7
    mov.w @(4, r15), r0
    mov.w   .L_060242E2, r5
    mov.l   .L_060242F4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x1D, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x12, r4
    mov.l   .L_06024300, r7
    mov.w @(4, r15), r0
    mov.w   .L_060242E2, r5
    mov.l   .L_060242F4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x1D, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x13, r4
    mov.l   .L_06024304, r2
    mov #0x3A, r3
    mov.w r3, @r2
    mov #0xE, r3
    mov.w   DAT_060242e4, r2
    mov r2, r0
    mov.w r0, @(6, r15)
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_06024308, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0602431C
    mov.l   .L_0602430C, r7
    mov.w @(4, r15), r0
    mov.w   .L_060242E6, r5
    mov.l   .L_060242F4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    jsr @r3
    extu.w r4, r4
    mov.l   .L_06024310, r7
    mov.w @(4, r15), r0
    mov.w   .L_060242E6, r5
    mov.l   .L_060242F4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1, r4
    mov.l   .L_06024314, r7
    mov.w @(4, r15), r0
    mov.w   .L_060242E6, r5
    mov.l   .L_060242F4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2, r4
    mov.l   .L_06024318, r7
    mov.w @(4, r15), r0
    mov.w   .L_060242E6, r5
    mov.l   .L_060242F4, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x3, r4
    bra     .L_0602437A
    nop

    .global DAT_060242e0
DAT_060242e0:
    .short  0x0E00
.L_060242E2:
    .short  0x0630

    .global DAT_060242e4
DAT_060242e4:
    .short  0x0E82
.L_060242E6:
    .short  0x0210
.L_060242E8:
    .long  sym_06007540
.L_060242EC:
    .long  sym_06089E9C
.L_060242F0:
    .long  0x002A3987
.L_060242F4:
    .long  vdp1_sprite_render
.L_060242F8:
    .long  0x002A3C2F
.L_060242FC:
    .long  0x002A3D23
.L_06024300:
    .long  0x002A3E23
.L_06024304:
    .long  sym_06089EA0
.L_06024308:
    .long  sym_0607EAB8
.L_0602430C:
    .long  0x002A43A6
.L_06024310:
    .long  0x002A43D8
.L_06024314:
    .long  0x002A4450
.L_06024318:
    .long  0x002A44BF
.L_0602431C:
    mov.l   .L_060243EC, r7
    mov.w @(4, r15), r0
    mov.w   .L_060243E8, r5
    mov.l   .L_060243F0, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    jsr @r3
    extu.w r4, r4
    mov.l   .L_060243F4, r7
    mov.w @(4, r15), r0
    mov.w   .L_060243E8, r5
    mov.l   .L_060243F0, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1, r4
    mov.l   .L_060243F8, r7
    mov.w @(4, r15), r0
    mov.w   .L_060243E8, r5
    mov.l   .L_060243F0, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2, r4
    mov.l   .L_060243FC, r7
    mov.w @(4, r15), r0
    mov.w   .L_060243E8, r5
    mov.l   .L_060243F0, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x3, r4
.L_0602437A:
    mov.l   .L_06024400, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06024414
    mov.l   .L_06024404, r7
    mov.w @(4, r15), r0
    mov.w   .L_060243E8, r5
    mov.l   .L_060243F0, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x4, r4
    mov.l   .L_06024408, r7
    mov.w @(4, r15), r0
    mov.w   .L_060243E8, r5
    mov.l   .L_060243F0, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x5, r4
    mov.l   .L_0602440C, r7
    mov.w @(4, r15), r0
    mov.w   .L_060243E8, r5
    mov.l   .L_060243F0, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x6, r4
    mov.l   .L_06024410, r7
    mov.w @(4, r15), r0
    mov.w   .L_060243E8, r5
    mov.l   .L_060243F0, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x7, r4
    bra     .L_060244D4
    nop
.L_060243E8:
    .short  0x0210
    .short  0xFFFF
.L_060243EC:
    .long  0x002A452A
.L_060243F0:
    .long  vdp1_sprite_render
.L_060243F4:
    .long  0x002A455C
.L_060243F8:
    .long  0x002A45CD
.L_060243FC:
    .long  0x002A463C
.L_06024400:
    .long  sym_06078635
.L_06024404:
    .long  0x002A46AC
.L_06024408:
    .long  0x002A46DE
.L_0602440C:
    .long  0x002A4753
.L_06024410:
    .long  0x002A47C4
.L_06024414:
    mov.l   .L_0602450C, r7
    mov.w @(4, r15), r0
    mov.w   .L_06024506, r5
    mov.l   .L_06024510, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x4, r4
    mov.l   .L_06024514, r7
    mov.w @(4, r15), r0
    mov.w   .L_06024506, r5
    mov.l   .L_06024510, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x5, r4
    mov.l   .L_06024518, r7
    mov.w @(4, r15), r0
    mov.w   .L_06024506, r5
    mov.l   .L_06024510, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x6, r4
    mov.l   .L_0602451C, r7
    mov.w @(4, r15), r0
    mov.w   .L_06024506, r5
    mov.l   .L_06024510, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x7, r4
    mov.l   .L_06024520, r7
    mov.w @(4, r15), r0
    mov.w   .L_06024506, r5
    mov.l   .L_06024510, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x8, r4
    mov.l   .L_06024524, r7
    mov.w @(4, r15), r0
    mov.w   .L_06024506, r5
    mov.l   .L_06024510, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x9, r4
    mov.l   .L_06024528, r7
    mov.w @(4, r15), r0
    mov.w   .L_06024506, r5
    mov.l   .L_06024510, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xA, r4
    mov.l   .L_0602452C, r7
    mov.w @(4, r15), r0
    mov.w   .L_06024506, r5
    mov.l   .L_06024510, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    shll2 r6
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xB, r4
.L_060244D4:
    mov.l   .L_06024530, r0
    bra     .L_0602455C
    mov.l @r0, r0
.L_060244DA:
    mov #0x38, r6
    mov.w   .L_06024508, r5
    mov.l   .L_06024534, r7
    mov.w @(6, r15), r0
    mov.l   .L_06024510, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xC, r4
    bra     .L_06024568
    nop
.L_060244F0:
    mov.l   .L_06024538, r7
    mov #0x38, r6
    mov.w   .L_06024508, r5
    mov.w @(6, r15), r0
    mov.l   .L_06024510, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xC, r4
    bra     .L_06024568
    nop
.L_06024506:
    .short  0x0210
.L_06024508:
    .short  0x0940
    .short  0xFFFF
.L_0602450C:
    .long  0x002A4836
.L_06024510:
    .long  vdp1_sprite_render
.L_06024514:
    .long  0x002A4862
.L_06024518:
    .long  0x002A48CF
.L_0602451C:
    .long  0x002A4946
.L_06024520:
    .long  0x002A49B3
.L_06024524:
    .long  0x002A49F0
.L_06024528:
    .long  0x002A4A61
.L_0602452C:
    .long  0x002A4AD7
.L_06024530:
    .long  sym_0607EAD8
.L_06024534:
    .long  0x002A3F1F
.L_06024538:
    .long  0x002A405A
.L_0602453C:
    mov.l   .L_06024554, r7
    mov #0x38, r6
    mov.w   .L_06024552, r5
    mov.w @(6, r15), r0
    mov.l   .L_06024558, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xC, r4
    bra     .L_06024568
    nop
.L_06024552:
    .short  0x0C40
.L_06024554:
    .long  0x002A41C5
.L_06024558:
    .long  vdp1_sprite_render
.L_0602455C:
    cmp/eq #0x0, r0
    bt      .L_060244DA
    cmp/eq #0x1, r0
    bt      .L_060244F0
    cmp/eq #0x2, r0
    bt      .L_0602453C
.L_06024568:
    mov.l   .L_0602463C, r7
    mov.w   .L_0602461C, r5
    mov.w   DAT_0602461e, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_06024644, r2
    mov.l   .L_06024648, r3
    mov.l @r2, r2
    mov.l r2, @r3
    mov r3, r2
    mov.l @r2, r2
    add #-0x1, r2
    mov.l r2, @r3
    mov.l   .L_0602464C, r7
    mov.w   .L_0602461C, r5
    mov.w   .L_06024620, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_06024650, r7
    mov.w   .L_0602461C, r5
    mov.w   .L_06024622, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_06024654, r7
    mov.w   .L_0602461C, r5
    mov.w   DAT_06024624, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_06024658, r7
    mov.w   .L_0602461C, r5
    mov.w   .L_06024626, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_0602465C, r7
    mov.w   .L_0602461C, r5
    mov.w   DAT_06024628, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x4C, r6
    mov #0x50, r6
    mov.w   DAT_06024624, r5
    mov.l   .L_06024660, r3
    mov r5, r4
    jsr @r3
    add #0x3, r4
    mov.l   .L_06024664, r7
    mov.w   .L_0602461C, r5
    mov.w   DAT_0602462a, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_06024668, r7
    mov.w   .L_0602461C, r5
    mov.w   DAT_0602462c, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x4C, r6
    mov.l   .L_0602466C, r7
    mov.w   .L_0602462E, r5
    mov.w   .L_06024630, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x44, r6
    mov.l   .L_06024670, r7
    mov.w   .L_06024632, r5
    mov.w   .L_06024634, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x44, r6
    mov.l   .L_06024674, r7
    mov.w   .L_06024636, r5
    mov.w   DAT_06024638, r4
    mov.l   .L_06024640, r3
    jsr @r3
    mov #0x48, r6
    mov #0x4C, r6
    mov.w   DAT_06024638, r5
    mov.l   .L_06024660, r3
    mov r5, r4
    jsr @r3
    add #0x1, r4
    mov #0x50, r6
    mov.w   DAT_06024638, r5
    bra     .L_06024678
    nop
.L_0602461C:
    .short  0x0418

    .global DAT_0602461e
DAT_0602461e:
    .short  0x0E97
.L_06024620:
    .short  0x0E98
.L_06024622:
    .short  0x0E99

    .global DAT_06024624
DAT_06024624:
    .short  0x0E9A
.L_06024626:
    .short  0x0E9B

    .global DAT_06024628
DAT_06024628:
    .short  0x0E9C

    .global DAT_0602462a
DAT_0602462a:
    .short  0x0E9E

    .global DAT_0602462c
DAT_0602462c:
    .short  0x0E9F
.L_0602462E:
    .short  0x0110
.L_06024630:
    .short  0x0E90
.L_06024632:
    .short  0x0210
.L_06024634:
    .short  0x0E91
.L_06024636:
    .short  0x0420

    .global DAT_06024638
DAT_06024638:
    .short  0x0E92
    .short  0xFFFF
.L_0602463C:
    .long  0x002A7A5E
.L_06024640:
    .long  vdp1_sprite_render
.L_06024644:
    .long  sym_0606A4F4
.L_06024648:
    .long  sym_06085F98
.L_0602464C:
    .long  0x002A7AC5
.L_06024650:
    .long  0x002A7B1F
.L_06024654:
    .long  0x002A7BA0
.L_06024658:
    .long  0x002A7BE9
.L_0602465C:
    .long  0x002A7C3B
.L_06024660:
    .long  sym_06007540
.L_06024664:
    .long  0x002A7CA5
.L_06024668:
    .long  0x002A7CFA
.L_0602466C:
    .long  0x002A8B47
.L_06024670:
    .long  0x002A8B7E
.L_06024674:
    .long  0x002A8BBB
.L_06024678:
    mov r5, r4
    mov.l   .L_0602478C, r3
    jsr @r3
    add #0x2, r4
    mov #0x54, r6
    mov.w   DAT_06024782, r5
    mov.l   .L_0602478C, r3
    mov r5, r4
    jsr @r3
    add #0x3, r4
    mov.l   .L_06024790, r7
    mov.w   DAT_06024784, r5
    mov.w   DAT_06024786, r4
    mov.l   .L_06024794, r3
    jsr @r3
    mov #0x58, r6
    mov.l   .L_06024798, r2
    mov #0x39, r3
    mov #0x0, r6
    mov #0x1, r5
    mov.w r3, @r2
    mov #0x18, r3
    mov.w   DAT_06024788, r2
    mov r2, r0
    mov.w r0, @(6, r15)
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.w @(6, r15), r0
    mov.l   .L_0602478C, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1, r4
    mov #0x0, r6
    mov #0x2, r5
    mov.w @(6, r15), r0
    mov.l   .L_0602478C, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x2, r4
    mov #0x0, r6
    mov #0x3, r5
    mov.w @(6, r15), r0
    mov.l   .L_0602478C, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x3, r4
    mov #0x0, r6
    mov #0x4, r5
    mov.w @(6, r15), r0
    mov.l   .L_0602478C, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x4, r4
    mov #0x0, r6
    mov #0x5, r5
    mov.w @(6, r15), r0
    mov.l   .L_0602478C, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x5, r4
    mov #0x0, r6
    mov #0x6, r5
    mov.w @(6, r15), r0
    mov.l   .L_0602478C, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x6, r4
    mov #0x4, r6
    mov #0x7, r5
    mov.w @(6, r15), r0
    mov.l   .L_0602478C, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x7, r4
    mov #0x4, r6
    mov #0x8, r5
    mov.w @(6, r15), r0
    mov.l   .L_0602478C, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x8, r4
    mov #0x0, r6
    mov #0x9, r5
    mov.w @(6, r15), r0
    mov.l   .L_0602478C, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x9, r4
    mov #0x3C, r6
    mov #0xA, r5
    mov.w @(6, r15), r0
    mov.l   .L_0602478C, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0xA, r4
    mov.l   .L_0602479C, r7
    mov.w @(4, r15), r0
    mov.w   .L_0602478A, r5
    mov.l   .L_06024794, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x10, r4
    mov.l   .L_060247A0, r7
    mov.w @(4, r15), r0
    mov.w   .L_0602478A, r5
    mov.l   .L_06024794, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x11, r4
    bra     .L_060247A4
    nop

    .global DAT_06024782
DAT_06024782:
    .short  0x0E92

    .global DAT_06024784
DAT_06024784:
    .short  0x1020

    .global DAT_06024786
DAT_06024786:
    .short  0x0E96

    .global DAT_06024788
DAT_06024788:
    .short  0x0E40
.L_0602478A:
    .short  0x0108
.L_0602478C:
    .long  sym_06007540
.L_06024790:
    .long  0x002A92CB
.L_06024794:
    .long  vdp1_sprite_render
.L_06024798:
    .long  sym_06089E9E
.L_0602479C:
    .long  0x002A7D76
.L_060247A0:
    .long  0x002A7D8E
.L_060247A4:
    mov.l   .L_060248C4, r7
    mov.w @(4, r15), r0
    mov.w   .L_060248BA, r5
    mov.l   .L_060248C8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x12, r4
    mov.l   .L_060248CC, r7
    mov.w @(4, r15), r0
    mov.w   .L_060248BA, r5
    mov.l   .L_060248C8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x13, r4
    mov.l   .L_060248D0, r7
    mov.w @(4, r15), r0
    mov.w   .L_060248BA, r5
    mov.l   .L_060248C8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x14, r4
    mov.l   .L_060248D4, r7
    mov.w @(4, r15), r0
    mov.w   DAT_060248bc, r5
    mov.l   .L_060248C8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x15, r4
    mov.l   .L_060248D8, r7
    mov.w @(4, r15), r0
    mov.w   .L_060248BA, r5
    mov.l   .L_060248C8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x16, r4
    mov.l   .L_060248DC, r7
    mov.w @(4, r15), r0
    mov.w   DAT_060248be, r5
    mov.l   .L_060248C8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x17, r4
    mov.l   .L_060248E0, r7
    mov.w @(4, r15), r0
    mov.w   .L_060248BA, r5
    mov.l   .L_060248C8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x2, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x18, r4
    mov.l   .L_060248E4, r7
    mov.w @(4, r15), r0
    mov.w   .L_060248BA, r5
    mov.l   .L_060248C8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x1, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x19, r4
    mov.l   .L_060248E8, r7
    mov.w @(4, r15), r0
    mov.w   .L_060248C0, r5
    mov.l   .L_060248C8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x1, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1A, r4
    mov.l   .L_060248EC, r7
    mov.w @(4, r15), r0
    mov.w   .L_060248BA, r5
    mov.l   .L_060248C8, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1B, r4
    mov.l   .L_060248F0, r7
    mov.w @(4, r15), r0
    mov r0, r6
    extu.w r6, r6
    add #0x3, r6
    shll2 r6
    mov.w   .L_060248BA, r5
    bra     .L_060248F4
    nop
.L_060248BA:
    .short  0x0108

    .global DAT_060248bc
DAT_060248bc:
    .short  0x010C

    .global DAT_060248be
DAT_060248be:
    .short  0x040C
.L_060248C0:
    .short  0x0208
    .short  0xFFFF
.L_060248C4:
    .long  0x002A7DA6
.L_060248C8:
    .long  vdp1_sprite_render
.L_060248CC:
    .long  0x002A7DC6
.L_060248D0:
    .long  0x002A7DE6
.L_060248D4:
    .long  0x002A7DF2
.L_060248D8:
    .long  0x002A7E0A
.L_060248DC:
    .long  0x002A7E16
.L_060248E0:
    .long  0x002A7E9E
.L_060248E4:
    .long  0x002A7EB6
.L_060248E8:
    .long  0x002A7ECA
.L_060248EC:
    .long  0x002A7EFE
.L_060248F0:
    .long  0x002A7F0A
.L_060248F4:
    mov.w @(6, r15), r0
    mov.l   .L_06024A10, r3
    mov r0, r4
    extu.w r4, r4
    jsr @r3
    add #0x1C, r4
    mov.l   .L_06024A14, r7
    mov.w @(4, r15), r0
    mov.w   .L_06024A06, r5
    mov.l   .L_06024A10, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    shll2 r6
    extu.w r4, r4
    jsr @r3
    add #0x1D, r4
    mov.l   .L_06024A18, r7
    mov.w @(4, r15), r0
    mov.w   .L_06024A06, r5
    mov.l   .L_06024A10, r3
    mov r0, r6
    extu.w r6, r6
    mov.w @(6, r15), r0
    add #0x3, r6
    mov r0, r4
    .long  0x4608644D
    .long  0x430B741E
    .long  0xD73985F2
    .long  0x9566D335
    .long  0x6603666D
    .long  0x85F37601
    .long  0x64034608
    .long  0x644D430B
    .long  0x741FD734
    .long  0x85F2955A
    .long  0xD32E6603
    .long  0x666D85F3
    .long  0x76016403
    .long  0x4608644D
    .long  0x430B7420
    .long  0xD72E85F2
    .long  0x954ED328
    .long  0x6603666D
    .long  0x85F37603
    .long  0x64034608
    .long  0x644D430B
    .long  0x7421D729
    .long  0x85F29542
    .long  0xD3216603
    .long  0x666D85F3
    .long  0x46086403
    .long  0x644D430B
    .long  0x7422D724
    .long  0x85F29536
    .long  0xD31B6603
    .long  0x666D85F3
    .long  0x46086403
    .long  0x644D430B
    .long  0x7423D71F
    .long  0x85F2952A
    .long  0xD3156603
    .long  0x666D85F3
    .long  0x76026403
    .long  0x4608644D
    .long  0x430B7424
    .long  0xD71985F2
    .long  0x9519D30F
    .long  0x6603666D
    .long  0x85F37603
    .long  0x64034608
    .long  0x644D430B
    .long  0x7425D714
    .long  0x85F2950C
    .long  0xD3086603
    .long  0x666D85F3
    .long  0x76036403
    .long  0x4608644D
    .long  0x430B7426
    .long  0xD70EA01D
    .short  0x0009
.L_06024A06:
    .short  0x0108

    .global DAT_06024a08
DAT_06024a08:
    .short  0x011C

    .global DAT_06024a0a
DAT_06024a0a:
    .short  0x021C
    .long  0x05080210
.L_06024A10:
    .long  vdp1_sprite_render
.L_06024A14:
    .long  0x002A7F12
.L_06024A18:
    .long  0x002A7F1A
    .long  0x002A7F3A
    .long  0x002A7FB6
    .long  0x002A8072
    .long  0x002A80FA
    .long  0x002A8172
    .long  0x002A81F6
    .long  0x002A8276
    .long  0x002A8292
    .long  0x002A829A
    .long  0x85F29586
    .long  0xD3456603
    .long  0x666D85F3
    .long  0x46086403
    .long  0x644D430B
    .long  0x7427D742
    .long  0x85F2957A
    .long  0xD33F6603
    .long  0x666D85F3
    .long  0x46086403
    .long  0x644D430B
    .long  0x7428D73D
    .long  0x85F2956E
    .long  0xD3396603
    .long  0x666D85F3
    .long  0x76036403
    .long  0x4608644D
    .long  0x430B7429
    .long  0xD73785F2
    .long  0x9561D333
    .long  0x6603666D
    .long  0x85F37603
    .long  0x64034608
    .long  0x644D430B
    .long  0x742AD732
    .long  0x85F29555
    .long  0xD32C6603
    .long  0x666D85F3
    .long  0x76016403
    .long  0x4608644D
    .long  0x430B742B
    .long  0xD72C85F2
    .long  0x9549D326
    .long  0x6603666D
    .long  0x85F37603
    .long  0x64034608
    .long  0x644D430B
    .long  0x742CD727
    .long  0x85F2953D
    .long  0xD31F6603
    .long  0x666D85F3
    .long  0x76036403
    .long  0x4608644D
    .long  0x430B742D
    .long  0xD72185F2
    .long  0x952DD319
    .long  0x6603666D
    .long  0x85F37603
    .long  0x64034608
    .long  0x644D430B
    .long  0x742ED71C
    .long  0x85F29524
    .long  0xD3126603
    .long  0x666D85F3
    .long  0x76036403
    .long  0x4608644D
    .long  0x430B742F
    .long  0xD71685F2
    .long  0x9515D30C
    .long  0x6603666D
    .long  0x85F34608
    .long  0x6403644D
    .long  0x430B7430
    .long  0xD71185F2
    .long  0x6603666D
    .long  0x46089508
    .long  0x85F36403
    .long  0x644DA01B
    .long  0x74310108

    .global DAT_06024b54
DAT_06024b54:
    .long  0x021C0320
    .long  0x01200308
    .long  vdp1_sprite_render
    .long  0x002A82A2
    .long  0x002A82B2
    .long  0x002A82BA
    .long  0x002A82CE
    .long  0x002A8372
    .long  0x002A84BE
    .long  0x002A854A
    .long  0x002A8572
    .long  0x002A85C6
    .long  0x002A86EE
    .long  0xD347430B
    .long  0x0009D747
    .long  0x85F29583
    .long  0xD3446603
    .long  0x666D85F3
    .long  0x46086403
    .long  0x644D430B
    .long  0x7432D742
    .long  0x85F29577
    .long  0xD33E6603
    .long  0x666D85F3
    .long  0x46086403
    .long  0x644D430B
    .long  0x7433D73D
    .long  0x85F2956B
    .long  0xD3386603
    .long  0x666D85F3
    .long  0x76026403
    .long  0x4608644D
    .long  0x430B7434
    .long  0xD73785F2
    .long  0x955FD332
    .long  0x6603666D
    .long  0x85F37601
    .long  0x64034608
    .long  0x644D430B
    .long  0x7439D732
    .long  0x85F29552
    .long  0xD32B6603
    .long  0x666D85F3
    .long  0x76016403
    .long  0x4608644D
    .long  0x430B743A
    .long  0xD72C85F2
    .long  0x9546D325
    .long  0x6603666D
    .long  0x85F37601
    .long  0x64034608
    .long  0x644D430B
    .long  0x743BD727
    .long  0x85F2953A
    .long  0xD31E6603
    .long  0x666D85F3
    .long  0x76016403
    .long  0x4608644D
    .long  0x430B7435
    .long  0xD72185F2
    .long  0x952ED318
    .long  0x6603666D
    .long  0x85F37601
    .long  0x64034608
    .long  0x644D430B
    .long  0x7436D71C
    .long  0x85F29520
    .long  0xD3116603
    .long  0x666D85F3
    .long  0x76016403
    .long  0x4608644D
    .long  0x430B7437
    .long  0xD71685F2
    .long  0x9514D30B
    .long  0x6603666D
    .long  0x85F37601
    .long  0x64034608
    .long  0x644D430B
    .long  0x7438D711
    .long  0x85F26603
    .long  0x666D7601
    .long  0xA01E0009
    .short  0x0110

    .global DAT_06024c9e
DAT_06024c9e:
    .short  0x0116

    .global DAT_06024ca0
DAT_06024ca0:
    .short  0x0216

    .global DAT_06024ca2
DAT_06024ca2:
    .short  0x020A
    .long  0x020CFFFF
    .long  vdp1_sprite_render
    .long  0x002A873E
    .long  0x002A878A
    .long  0x002A87C6
    .long  0x002A8812
    .long  0x002A8852
    .long  0x002A8896
    .long  0x002A8906
    .long  0x002A8926
    .long  0x002A897E
    .long  0x002A89A6
    .long  0x002A89F6
    .long  0x46089516
    .long  0x85F3D30B
    .long  0x6403644D
    .long  0x430B743C
    .long  0xD70985F2
    .long  0x950DD307
    .long  0x6603666D
    .long  0x85F37601
    .long  0x64034608
    .long  0x644D430B
    .long  0x743D7F08
    .long  0x4F26000B
    .long  0x00090108
    .long  vdp1_sprite_render
    .long  0x002A8A06
