
    .section .text.FUN_0602EFF0


    .global render_camera_compute
    .type render_camera_compute, @function
render_camera_compute:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_0602F024, r0
    mov.l @r0, r0
    mov #0x0, r1
    mov #0x0, r2
    mov #0x0, r3
    mov #0x0, r4
    mov #0x0, r7
    mov r0, r14
    mov.w   DAT_0602f01e, r1
    mov.l @(r0, r1), r1
    mov r1, r6
    mov.w   .L_0602F020, r2
    mov.w   .L_0602F022, r3
    cmp/pz r1
    bt      .L_0602F014
    neg r1, r1
.L_0602F014:
    sub r2, r1
    cmp/pz r1
    bt      .L_0602F028
    bra     .L_0602F036
    mov #0x0, r1

    .global DAT_0602f01e
DAT_0602f01e:
    .2byte  0x00AC
.L_0602F020:
    .2byte  0x0005
.L_0602F022:
    .2byte  0x0050
.L_0602F024:
    .4byte  sym_0607E944
.L_0602F028:
    sub r2, r3
    cmp/gt r1, r3
    bt      .L_0602F030
    mov r3, r1
.L_0602F030:
    cmp/pz r6
    bt      .L_0602F036
    neg r1, r1
.L_0602F036:
    mov r0, r14
    mov.w   .L_0602F060, r2
    muls.w r1, r2
    mov.w   .L_0602F062, r0
    sts macl, r1
    .byte   0xBE, 0x44    /* bsr 0x0602ECCC (external) */
    nop
    mov r0, r2
    mov r14, r0
    mov.w   DAT_0602f064, r6
    mov.w   DAT_0602f066, r1
    mov.l @(r0, r6), r4
    mov.l r2, @(r0, r6)
    mov.l r4, @(r0, r1)
    mov.w   .L_0602F068, r3
    mov.l @(r0, r3), r1
    mov.l   .L_0602F06C, r2
    cmp/ge r1, r2
    bt      .L_0602F070
    bra     .L_0602F078
    mov r2, r1
.L_0602F060:
    .2byte  0x00FF
.L_0602F062:
    .2byte  0x0096

    .global DAT_0602f064
DAT_0602f064:
    .2byte  0x00B0

    .global DAT_0602f066
DAT_0602f066:
    .2byte  0x00B4
.L_0602F068:
    .2byte  0x0074
    .2byte  0x0000
.L_0602F06C:
    .4byte  0x000000B8
.L_0602F070:
    mov.l   .L_0602F0A4, r2
    cmp/ge r1, r2
    bf      .L_0602F078
    mov r2, r1
.L_0602F078:
    mov.l   .L_0602F0A4, r2
    sub r2, r1
    mov.w   .L_0602F0A0, r3
    mulu.w r3, r1
    mov.l r0, @-r15
    mov.l   .L_0602F0A8, r3
    sts macl, r1
    mov.l   .L_0602F0AC, r0
    .byte   0xBE, 0x20    /* bsr 0x0602ECCC (external) */
    nop
    mov.l @r15+, r0
    mov.l @(r0, r3), r2
    mov.l r1, @(r0, r3)
    mov.w   .L_0602F0A2, r3
    mov.l @(r0, r3), r1
    mov.l   .L_0602F0B0, r2
    cmp/ge r1, r2
    bt      .L_0602F0B4
    bra     .L_0602F0BC
    mov r2, r1
.L_0602F0A0:
    .2byte  0x00FF
.L_0602F0A2:
    .2byte  0x0090
.L_0602F0A4:
    .4byte  0x00000038
.L_0602F0A8:
    .4byte  0x00000078
.L_0602F0AC:
    .4byte  0x00000080
.L_0602F0B0:
    .4byte  0x00000098
.L_0602F0B4:
    mov.l   .L_0602F0E4, r2
    cmp/ge r1, r2
    bf      .L_0602F0BC
    mov r2, r1
.L_0602F0BC:
    mov.l   .L_0602F0E4, r2
    sub r2, r1
    mov.w   .L_0602F0DC, r3
    mulu.w r3, r1
    mov.l r0, @-r15
    sts macl, r1
    mov.w   .L_0602F0DE, r0
    .byte   0xBD, 0xFF    /* bsr 0x0602ECCC (external) */
    nop
    mov.l @r15+, r0
    mov.w   .L_0602F0E0, r3
    mov.l r1, @(r0, r3)
    lds.l @r15+, pr
    mov.l @r15+, r14
    rts
    nop
.L_0602F0DC:
    .2byte  0x00FF
.L_0602F0DE:
    .2byte  0x0060
.L_0602F0E0:
    .2byte  0x0094
    .2byte  0x0000
.L_0602F0E4:
    .4byte  0x00000038

    .global sym_0602F0E8
sym_0602F0E8:
    mov.l   .L_0602F12C, r2
    mov.l @r2, r0
    mov.w   DAT_0602f11e, r1
    mov.l @(r0, r1), r2
    shll8 r2
    mov.w   DAT_0602f120, r3
    mov.l @(r0, r3), r4
    add r4, r2
    shar r2
    mov.l r2, @(r0, r3)
    mov.w   DAT_0602f122, r1
    mov.l @(r0, r1), r3
    tst r3, r3
    bf      .L_0602F134
    mov.w   DAT_0602f124, r2
    mov.l @(r0, r2), r4
    tst r4, r4
    bf      .L_0602F134
    mov.w   DAT_0602f126, r1
    mov.l @(r0, r1), r2
    mov.l   .L_0602F130, r3
    mov.l r2, @(r0, r3)
    mov.w   DAT_0602f128, r1
    mov.l @(r0, r1), r2
    mov.w   DAT_0602f12a, r3
    rts
    mov.l r2, @(r0, r3)

    .global DAT_0602f11e
DAT_0602f11e:
    .2byte  0x00B0

    .global DAT_0602f120
DAT_0602f120:
    .2byte  0x00D0

    .global DAT_0602f122
DAT_0602f122:
    .2byte  0x00B8

    .global DAT_0602f124
DAT_0602f124:
    .2byte  0x01BC

    .global DAT_0602f126
DAT_0602f126:
    .2byte  0x0094

    .global DAT_0602f128
DAT_0602f128:
    .2byte  0x0078

    .global DAT_0602f12a
DAT_0602f12a:
    .2byte  0x0068
.L_0602F12C:
    .4byte  sym_0607E944
.L_0602F130:
    .4byte  0x00000084
.L_0602F134:
    mov #0x0, r5
    mov.w   DAT_0602f15a, r1
    mov.w r5, @(r0, r1)
    mov.w   DAT_0602f15c, r5
    mov.w   DAT_0602f15e, r1
    mov.l r5, @(r0, r1)
    mov.w   DAT_0602f160, r1
    mov.l r5, @(r0, r1)
    mov #0x0, r5
    mov.w   .L_0602F162, r1
    mov.l @(r0, r1), r4
    mov.l   .L_0602F164, r2
    cmp/pz r4
    bt      .L_0602F168
    add r2, r4
    cmp/pz r4
    bt      .L_0602F174
    bra     .L_0602F16E
    nop

    .global DAT_0602f15a
DAT_0602f15a:
    .2byte  0x0166

    .global DAT_0602f15c
DAT_0602f15c:
    .2byte  0x0038

    .global DAT_0602f15e
DAT_0602f15e:
    .2byte  0x0090

    .global DAT_0602f160
DAT_0602f160:
    .2byte  0x0074
.L_0602F162:
    .2byte  0x00D0
.L_0602F164:
    .4byte  0x0000071C
.L_0602F168:
    sub r2, r4
    cmp/pz r4
    bt      .L_0602F174
.L_0602F16E:
    mov.l r4, @(r0, r1)
    rts
    nop
.L_0602F174:
    mov #0x0, r5
    mov.l r5, @(r0, r1)
    rts
    nop

    .global sym_0602F17C
sym_0602F17C:
    mov r0, r14
    mov #0x0, r5
    mov.w   .L_0602F1BA, r8
    mov.l @(r0, r8), r2
    tst r2, r2
    bt      .L_0602F190
    cmp/pz r2
    bf      .L_0602F18E
    add #-0x2, r2
.L_0602F18E:
    add #0x1, r2
.L_0602F190:
    mov.l r2, @(r0, r8)
    mov.w   DAT_0602f1bc, r9
    mov.w @(r0, r9), r2
    mov.w   DAT_0602f1be, r3
    shll2 r2
    mov.l @(r0, r3), r4
    mov.l @(8, r0), r7
    tst r7, r7
    bt      .L_0602F1AC
    mov.l   .L_0602F1C0, r6
    add r2, r6
    mov.l @r6, r6
    cmp/gt r6, r4
    bt      .L_0602F1C8
.L_0602F1AC:
    mov.l   .L_0602F1C4, r6
    add r2, r6
    mov.l @r6, r6
    cmp/ge r4, r6
    bt      .L_0602F1F8
    .byte   0xA0, 0x35    /* bra 0x0602F224 (external) */
    nop
.L_0602F1BA:
    .2byte  0x00D8

    .global DAT_0602f1bc
DAT_0602f1bc:
    .2byte  0x00DC

    .global DAT_0602f1be
DAT_0602f1be:
    .2byte  0x00E0
.L_0602F1C0:
    .4byte  sym_060477AC
.L_0602F1C4:
    .4byte  sym_0604779C
.L_0602F1C8:
    mov #0x5, r1
    mov.l r1, @(r0, r8)
    mov.w @(r0, r9), r1
    mov r1, r3
    add #0x1, r1
    mov.w r1, @(r0, r9)
    mov.w   DAT_0602f1f2, r8
    mov.l @(r0, r8), r5
    mov.l   .L_0602F1F4, r2
    shll16 r5
    shll2 r3
    add r2, r3
    mov.l @r3, r4
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r1
    xtrct r4, r1
    mov #0x0, r2
    shlr16 r1
    .byte   0xA0, 0x19    /* bra 0x0602F224 (external) */
    mov.l r1, @(r0, r8)

    .global DAT_0602f1f2
DAT_0602f1f2:
    .2byte  0x00E0
.L_0602F1F4:
    .4byte  sym_060477CC
.L_0602F1F8:
    mov #-0x5, r1
    mov.l r1, @(r0, r8)
    mov.w @(r0, r9), r1
    add #-0x1, r1
    mov r1, r3
    mov.w r1, @(r0, r9)
    .byte   0x98, 0x22    /* mov.w .L_wpool_0602F24C, r8 */
    mov.l @(r0, r8), r4
    shll16 r4
    .byte   0xD2, 0x12    /* mov.l .L_pool_0602F254, r2 */
    shll2 r3
    add r2, r3
    mov.l @r3, r5
    .byte   0xDC, 0x11    /* mov.l .L_pool_0602F258, r12 */
