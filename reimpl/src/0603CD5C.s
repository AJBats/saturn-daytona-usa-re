
    .section .text.FUN_0603CD5C


    .global hud_display_large
    .type hud_display_large, @function
hud_display_large:
    mov.l r14, @-r15
    mov #0x1, r6
    mov.l r13, @-r15
    mov r6, r0
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.w   DAT_0603ce8e, r11
    mov.l   .L_0603CE94, r5
    mov.l   .L_0603CE98, r4
    mov.l   .L_0603CE9C, r3
    mov r5, r2
    jsr @r3
    mov r6, r1
    mov r6, r0
    mov.w @r4, r2
    mov.w   DAT_0603ce90, r3
    extu.w r2, r2
    and r11, r2
    or r3, r2
    mov.w r2, @r4
    mov r5, r2
    mov.l   .L_0603CE9C, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_0603CEA0, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov.l   .L_0603CEA4, r7
    mov r6, r0
    mov.l   .L_0603CE9C, r3
    jsr @r3
    mov r6, r1
    mov r5, r2
    mov.w @r4, r0
    extu.w r0, r0
    and r7, r0
    or #0x20, r0
    mov.w r0, @r4
    mov r6, r0
    mov.l   .L_0603CE9C, r3
    mov.l   .L_0603CEA8, r14
    jsr @r3
    mov r6, r1
    mov.w @r4, r2
    mov r6, r0
    extu.w r2, r2
    and r14, r2
    mov.w r2, @r4
    mov r5, r2
    mov.l   .L_0603CE9C, r3
    mov.l   .L_0603CEAC, r13
    jsr @r3
    mov r6, r1
    mov.w @r4, r0
    mov r5, r2
    extu.w r0, r0
    and r13, r0
    or #0x7, r0
    mov.w r0, @r4
    mov r6, r0
    mov.l   .L_0603CE9C, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_0603CE9C, r3
    mov.l   .L_0603CEB0, r12
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_0603CE9C, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov.l   .L_0603CEB4, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_0603CE9C, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603CE9C, r3
    jsr @r3
    mov r6, r1
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.l   .L_0603CE9C, r3
    jsr @r3
    mov r6, r1
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603CE9C, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_0603CE9C, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    bra     .L_0603CEB8
    nop

    .global DAT_0603ce8e
DAT_0603ce8e:
    .2byte  0x0FFF

    .global DAT_0603ce90
DAT_0603ce90:
    .2byte  0x3000
    .2byte  0xFFFF
.L_0603CE94:
    .4byte  sym_060A4D58
.L_0603CE98:
    .4byte  sym_060A4D18
.L_0603CE9C:
    .4byte  sym_06034F78
.L_0603CEA0:
    .4byte  0x0000FFBF
.L_0603CEA4:
    .4byte  0x0000FFDF
.L_0603CEA8:
    .4byte  0x0000FFEF
.L_0603CEAC:
    .4byte  0x0000FFF0
.L_0603CEB0:
    .4byte  0x0000FF0F
.L_0603CEB4:
    .4byte  0x0000F0FF
.L_0603CEB8:
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov.l   .L_0603D03C, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r5, r2
    mov.l   .L_0603D040, r11
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r2, r0
    mov.w r0, @(8, r4)
    mov r5, r2
    mov.l   .L_0603D044, r12
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov.w r0, @(8, r4)
    mov r5, r2
    mov.l   .L_0603D048, r10
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    add #0x7, r13
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r10, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(8, r4)
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov.w r0, @(8, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(8, r4)
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(8, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(8, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(10, r4), r0
    mov.l   .L_0603D04C, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(10, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(10, r4), r0
    mov.l   .L_0603D050, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(10, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(10, r4), r0
    mov.l   .L_0603D054, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(10, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(10, r4), r0
    mov.l   .L_0603D058, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(10, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(10, r4), r0
    mov.l   .L_0603D05C, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(10, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D038, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    mov.w   DAT_0603d034, r3
    bra     .L_0603D060
    nop

    .global DAT_0603d034
DAT_0603d034:
    .2byte  0x7FFF
    .2byte  0xFFFF
.L_0603D038:
    .4byte  sym_06034F78
.L_0603D03C:
    .4byte  0x0000F0FF
.L_0603D040:
    .4byte  0x0000FFFE
.L_0603D044:
    .4byte  0x0000FFFD
.L_0603D048:
    .4byte  0x0000FFFB
.L_0603D04C:
    .4byte  0x0000FFFC
.L_0603D050:
    .4byte  0x0000FFF3
.L_0603D054:
    .4byte  0x0000FFCF
.L_0603D058:
    .4byte  0x0000FF3F
.L_0603D05C:
    .4byte  0x0000FCFF
.L_0603D060:
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_0603D1C8, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_0603D1CC, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_0603D1D0, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_0603D1D4, r3
    mov.w   DAT_0603d1c2, r1
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    or r1, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov.l   .L_0603D1D8, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(12, r4)
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(12, r4)
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r10, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(12, r4)
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(12, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r2, r0
    mov.w r0, @(12, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(14, r4), r0
    mov.l   .L_0603D1DC, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(14, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(14, r4), r0
    mov.l   .L_0603D1E0, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(14, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(14, r4), r0
    mov.l   .L_0603D1E4, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov.w r0, @(14, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D1C4, r3
    jsr @r3
    mov r6, r1
    mov.w @(14, r4), r0
    mov r0, r2
    extu.w r2, r2
    bra     .L_0603D1E8
    nop

    .global DAT_0603d1c2
DAT_0603d1c2:
    .2byte  0x0100
.L_0603D1C4:
    .4byte  sym_06034F78
.L_0603D1C8:
    .4byte  0x00008FFF
.L_0603D1CC:
    .4byte  0x0000FBFF
.L_0603D1D0:
    .4byte  0x0000FDFF
.L_0603D1D4:
    .4byte  0x0000FEFF
.L_0603D1D8:
    .4byte  0x0000FFBF
.L_0603D1DC:
    .4byte  0x0000FFFC
.L_0603D1E0:
    .4byte  0x0000FFF3
.L_0603D1E4:
    .4byte  0x0000FFCF
.L_0603D1E8:
    mov.l   .L_0603D2BC, r3
    and r3, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(14, r4)
    mov r6, r0
    mov.l   .L_0603D2C0, r3
    jsr @r3
    mov r6, r1
    mov.w @(14, r4), r0
    mov.l   .L_0603D2C4, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(14, r4)
    mov r6, r0
    mov.l   .L_0603D2C0, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r11, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D2C0, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r12, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.l   .L_0603D2C0, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r10, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D2C0, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r13, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.l   .L_0603D2C0, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r5, r2
    mov r6, r0
    mov.l   .L_0603D2C0, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.l   .L_0603D2C0, r3
    jsr @r3
    mov r6, r1
    mov.w @(2, r4), r0
    mov.l   .L_0603D2C8, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    extu.w r2, r0
    mov r5, r2
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.l   .L_0603D2C0, r3
    jsr @r3
    mov r6, r1
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0603D2BC:
    .4byte  0x0000FF3F
.L_0603D2C0:
    .4byte  sym_06034F78
.L_0603D2C4:
    .4byte  0x0000FCFF
.L_0603D2C8:
    .4byte  0x0000FEFF
