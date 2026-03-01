
    .section .text.FUN_06017CEC


    .global track_state_machine
    .type track_state_machine, @function
track_state_machine:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0xC, r15
    mov.l   .L_06017DA0, r8
    mov.l   .L_06017DA4, r9
    mov #0x1, r10
    mov.l   .L_06017DA8, r13
    mov.l   .L_06017DAC, r14
    mov.l   .L_06017DB0, r5
    mov.l @r5, r5
    mov.l   .L_06017DB4, r4
    mov.l @r4, r4
    mov.l   .L_06017DB8, r3
    mov.w @r3, r3
    add #0x1, r3
    mov.l   .L_06017DB8, r2
    mov.w r3, @r2
    mov.l   .L_06017DBC, r1
    mov.w @r1, r1
    add #0x1, r1
    mov.l   .L_06017DBC, r2
    mov.w r1, @r2
    mov.l   .L_06017DC0, r3
    mov.l @r3, r3
    add #-0x1, r3
    mov.w   DAT_06017d92, r0
    mov.l @(r0, r5), r2
    cmp/hs r3, r2
    bf/s    .L_06017D4A
    mov #0x3, r12
    mov.l   .L_06017DC4, r4
    mov.w   DAT_06017d94, r0
    mov.l @r4, r4
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    mov.w   DAT_06017d96, r0
    bra     .L_06017D5A
    add r14, r2
.L_06017D4A:
    mov.w   DAT_06017d94, r0
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.w   DAT_06017d98, r3
    mov r3, r0
.L_06017D5A:
    mov.w r0, @(6, r2)
    mov.w   DAT_06017d9a, r6
    mov #0x5, r2
    mov.l   .L_06017DB8, r3
    mov.w @r3, r3
    cmp/gt r2, r3
    bt      .L_06017DC8
    add r13, r6
    mov.w   .L_06017D9C, r4
    mov.w   DAT_06017d94, r0
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add r4, r3
    mov.l r3, @r2
    mov.w @r6, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add r4, r3
    mov.l r3, @r2
    bra     .L_06017DEE
    nop

    .global DAT_06017d92
DAT_06017d92:
    .2byte  0x021C

    .global DAT_06017d94
DAT_06017d94:
    .2byte  0x1692

    .global DAT_06017d96
DAT_06017d96:
    .2byte  0x03BC

    .global DAT_06017d98
DAT_06017d98:
    .2byte  0x03A8

    .global DAT_06017d9a
DAT_06017d9a:
    .2byte  0x16AA
.L_06017D9C:
    .2byte  0x0090
    .2byte  0xFFFF
.L_06017DA0:
    .4byte  0x00088734
.L_06017DA4:
    .4byte  sym_0605BE10
.L_06017DA8:
    .4byte  sym_060684EC
.L_06017DAC:
    .4byte  sym_06063F64
.L_06017DB0:
    .4byte  sym_0607E944
.L_06017DB4:
    .4byte  sym_06089E28
.L_06017DB8:
    .4byte  sym_0605BE2C
.L_06017DBC:
    .4byte  sym_0605BE2E
.L_06017DC0:
    .4byte  sym_06063F28
.L_06017DC4:
    .4byte  sym_06089E2C
.L_06017DC8:
    mov.w   DAT_06017ea6, r0
    add r13, r6
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l r4, @r2
    mov.w @r6, r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l   .L_06017EAC, r2
    mov.l @r2, r2
    mov.l r2, @r3
    mov #0x0, r3
    mov.l   .L_06017EB0, r2
    mov.w r3, @r2
.L_06017DEE:
    mov.w   DAT_06017ea8, r7
    mov.l   .L_06017EB4, r3
    mov r7, r6
    mov.w @r3, r3
    and r12, r3
    tst r3, r3
    bf/s    .L_06017EC0
    add #-0x8, r6
    mov.l   .L_06017EB8, r4
    mov.w   DAT_06017eaa, r0
    mov.l @r4, r2
    mov.w @(r0, r13), r3
    add #0x18, r0
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    mov.l @r4, r2
    extu.w r3, r3
    add #0x12, r0
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    mov.l @r4, r2
    extu.w r3, r3
    add #0x10, r0
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l @r4, r2
    add #0x10, r0
    add r13, r6
    add r13, r7
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    mov.l @r4, r2
    extu.w r3, r3
    add #-0x2A, r0
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.l   .L_06017EBC, r4
    mov.w @r6, r3
    mov.l @r4, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @r7, r3
    mov.l @r4, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l @r4, r2
    add #0x12, r0
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    mov.l @r4, r2
    extu.w r3, r3
    add #0x10, r0
    shll2 r3
    shll r3
    add r14, r3
    mov.l r2, @r3
    mov.w @(r0, r13), r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l @r4, r2
    mov.l r2, @r3
    bra     .L_06017F74
    nop

    .global DAT_06017ea6
DAT_06017ea6:
    .2byte  0x1692

    .global DAT_06017ea8
DAT_06017ea8:
    .2byte  0x1718

    .global DAT_06017eaa
DAT_06017eaa:
    .2byte  0x1708
.L_06017EAC:
    .4byte  sym_06089E30
.L_06017EB0:
    .4byte  sym_0605BE2C
.L_06017EB4:
    .4byte  sym_0605BE2E
.L_06017EB8:
    .4byte  sym_06089E34
.L_06017EBC:
    .4byte  sym_06089E38
.L_06017EC0:
    mov.w   DAT_06017fdc, r0
    add r13, r6
    add r13, r7
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @r6, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @r7, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    add #0x18, r0
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add #0x8, r0
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @(r0, r13), r2
    add #0xA, r0
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @(r0, r13), r2
    add #0x8, r0
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    add #0x8, r0
    mov.w @(r0, r13), r2
    add #0x8, r0
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @(r0, r13), r2
    add #0x8, r0
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
    mov.w @(r0, r13), r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r2, r3
    add #0x40, r3
    mov.l r3, @r2
.L_06017F74:
    mov.w   DAT_06017fde, r6
    mov.l   .L_06017FE8, r4
    mov.l   .L_06017FEC, r0
    mov.w @r0, r0
    tst #0x10, r0
    bt      .L_06017F98
    add r13, r6
    mov.w @r6, r3
    extu.w r3, r3
    shll2 r3
    shll r3
    add r14, r3
    mov.l @r4, r2
    mov.w   .L_06017FE0, r1
    add r1, r2
    mov.l r2, @r3
    bra     .L_06017FA8
    nop
.L_06017F98:
    add r13, r6
    mov.w @r6, r2
    extu.w r2, r2
    shll2 r2
    shll r2
    add r14, r2
    mov.l @r4, r3
    mov.l r3, @r2
.L_06017FA8:
    mov.w   DAT_06017fe2, r0
    mov.w   DAT_06017fe4, r3
    mov.l @(r0, r5), r4
    mov.l   .L_06017FF0, r5
    cmp/ge r3, r4
    bf      .L_06017FC2
    mov.w   DAT_06017fe6, r3
    cmp/gt r3, r4
    bt      .L_06017FC2
    extu.w r10, r3
    mov.w r3, @r5
    bra     .L_06017FC6
    nop
.L_06017FC2:
    mov #0x0, r2
    mov.w r2, @r5
.L_06017FC6:
    mov #0x4B, r3
    mov.l   .L_06017FF4, r5
    cmp/ge r3, r4
    bf      .L_06017FF8
    mov #0x57, r3
    cmp/gt r3, r4
    bt      .L_06017FF8
    mov #0x4, r3
    mov.w r3, @r5
    bra     .L_06017FFC
    nop

    .global DAT_06017fdc
DAT_06017fdc:
    .2byte  0x1708

    .global DAT_06017fde
DAT_06017fde:
    .2byte  0x16B8
.L_06017FE0:
    .2byte  0x0100

    .global DAT_06017fe2
DAT_06017fe2:
    .2byte  0x01EC

    .global DAT_06017fe4
DAT_06017fe4:
    .2byte  0x00A8

    .global DAT_06017fe6
DAT_06017fe6:
    .2byte  0x00C1
.L_06017FE8:
    .4byte  sym_06089E40
.L_06017FEC:
    .4byte  sym_0605BE2E
.L_06017FF0:
    .4byte  sym_0605BE36
.L_06017FF4:
    .4byte  sym_0605BE38
.L_06017FF8:
    mov #0x0, r2
    mov.w r2, @r5
.L_06017FFC:
    mov.w   DAT_060180fc, r3
    cmp/ge r3, r4
    bt      .L_06018006
    bra     .L_0601814A
    nop
.L_06018006:
    mov.w   DAT_060180fe, r3
    cmp/gt r3, r4
    bf      .L_06018010
    bra     .L_0601814A
    nop
.L_06018010:
    mov.w   .L_06018100, r3
    mov.l @r9, r2
    add r3, r2
    mov.l r2, @r9
    mov.w   DAT_06018102, r3
    mov.l @(4, r9), r2
    add r3, r2
    mov.l r2, @(4, r9)
    mov #0x0, r11
    mov.l   .L_06018108, r3
    mov.l r3, @(4, r15)
.L_06018026:
    mov.l   .L_0601810C, r3
    jsr @r3
    nop
    extu.b r11, r6
    mov.l   .L_06018110, r2
    mov r6, r3
    shll2 r6
    shll2 r3
    shll r3
    add r3, r6
    extu.b r6, r6
    add r2, r6
    mov.l r6, @r15
    mov.l @(8, r6), r6
    mov.l @r15, r5
    mov.l @r15, r4
    mov.l   .L_06018114, r3
    neg r6, r6
    mov.l @(4, r5), r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_06018118, r4
    mov.l   .L_0601811C, r3
    jsr @r3
    nop
    mov r11, r0
    mov r11, r3
    mov.w   DAT_06018104, r2
    and r10, r0
    and r12, r3
    shll2 r0
    mul.l r2, r3
    mov.l @(r0, r9), r4
    sts macl, r2
    mov.l   .L_06018120, r3
    jsr @r3
    add r2, r4
    mov #0xC, r5
    mov.l   .L_06018124, r2
    mov.l r2, @r15
    mov r2, r4
    mov.l   .L_06018128, r3
    jsr @r3
    add r8, r4
    mov r12, r6
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l   .L_0601812C, r3
    add r3, r4
    mov.l   .L_06018130, r3
    jsr @r3
    mov.w @r5, r5
    mov.l   .L_06018134, r3
    jsr @r3
    nop
    mov.l   .L_0601810C, r3
    jsr @r3
    add #0x1, r11
    extu.b r11, r6
    mov.l   .L_06018110, r2
    mov r6, r3
    shll2 r6
    shll2 r3
    shll r3
    add r3, r6
    extu.b r6, r6
    add r2, r6
    mov.l r6, @(8, r15)
    mov.l @(8, r6), r6
    mov.l @(8, r15), r5
    mov.l @(8, r15), r4
    mov.l   .L_06018114, r3
    neg r6, r6
    mov.l @(4, r5), r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_06018118, r4
    mov.l   .L_0601811C, r3
    jsr @r3
    nop
    mov r11, r0
    mov r11, r3
    mov.w   DAT_06018104, r2
    and r10, r0
    and r12, r3
    shll2 r0
    mul.l r2, r3
    mov.l @(r0, r9), r4
    sts macl, r2
    mov.l   .L_06018120, r3
    jsr @r3
    add r2, r4
    mov #0xC, r5
    mov.l @r15, r4
    mov.l   .L_06018128, r3
    jsr @r3
    add r8, r4
    mov r12, r6
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l   .L_0601812C, r3
    add r3, r4
    mov.l   .L_06018130, r3
    jsr @r3
    mov.w @r5, r5
    bra     .L_06018138
    nop

    .global DAT_060180fc
DAT_060180fc:
    .2byte  0x0089

    .global DAT_060180fe
DAT_060180fe:
    .2byte  0x00B6
.L_06018100:
    .2byte  0x0333

    .global DAT_06018102
DAT_06018102:
    .2byte  0x0666

    .global DAT_06018104
DAT_06018104:
    .2byte  0x1555
    .2byte  0xFFFF
.L_06018108:
    .4byte  sym_06089E98
.L_0601810C:
    .4byte  sym_06026DBC
.L_06018110:
    .4byte  sym_06048078
.L_06018114:
    .4byte  sym_06026E2E
.L_06018118:
    .4byte  0x0000C000
.L_0601811C:
    .4byte  mat_rot_y
.L_06018120:
    .4byte  mat_rot_z
.L_06018124:
    .4byte  0x00200000
.L_06018128:
    .4byte  sym_06031D8C
.L_0601812C:
    .4byte  0x000887C4
.L_06018130:
    .4byte  sym_06031A28
.L_06018134:
    .4byte  sym_06026DF8
.L_06018138:
    .byte   0xD3, 0x38    /* mov.l .L_pool_0601821C, r3 */
    jsr @r3
    nop
    add #0x1, r11
    mov #0xD, r2
    cmp/gt r2, r11
    bt      .L_0601814A
    bra     .L_06018026
    nop
.L_0601814A:
    .byte   0xD3, 0x35    /* mov.l .L_pool_06018220, r3 */
    jsr @r3
    nop
    add #0xC, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA0, 0x89    /* bra 0x06018278 (external tail call) */
    mov.l @r15+, r14
