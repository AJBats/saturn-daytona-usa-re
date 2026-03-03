
    .section .text.FUN_0602D08A


    .global vdp1_sprite_cmd
    .type vdp1_sprite_cmd, @function
vdp1_sprite_cmd:
    sts.l pr, @-r15
    mov r14, r0
    mov.w   DAT_0602d0d4, r1
    mov.l @(r0, r1), r10
    mov.w   .L_0602D0D6, r11
    mov.w   DAT_0602d0d8, r2
    mov.w @(r0, r2), r7
    cmp/pl r7
    bt      .L_0602D0EC
    mov.w   .L_0602D0DA, r3
    .byte   0xD5, 0x10    /* mov.l .L_0602D0E0, r5 */
    mov.l @(8, r0), r7
    mov.w   DAT_0602d0dc, r8
    neg r3, r4
    neg r5, r6
    cmp/gt r7, r8
    bt      .L_0602D0EC
    mov.w   DAT_0602d0de, r2
    mov.l @(r0, r2), r9
    cmp/gt r5, r9
    bt      .L_0602D0EC
    cmp/gt r9, r6
    bt      .L_0602D0EC
    mov r10, r8
    cmp/gt r3, r10
    bt      .L_0602D0C4
    cmp/ge r4, r10
    bt      .L_0602D0EC
    neg r8, r8
.L_0602D0C4:
    sub r3, r8
    mov #0x4, r1
    mov #0xF, r2
    cmp/gt r1, r8
    bt      .L_0602D0E4
    mov r1, r8
    bra     .L_0602D0EA
    nop

    .global DAT_0602d0d4
DAT_0602d0d4:
    .2byte  0x0154
.L_0602D0D6:
    .2byte  0x0168

    .global DAT_0602d0d8
DAT_0602d0d8:
    .2byte  0x0166
.L_0602D0DA:
    .2byte  0x02E0

    .global DAT_0602d0dc
DAT_0602d0dc:
    .2byte  0x0104

    .global DAT_0602d0de
DAT_0602d0de:
    .2byte  0x005C
.L_0602D0E0:
    .4byte  0x00000300
.L_0602D0E4:
    cmp/gt r8, r2
    bt      .L_0602D0EA
    mov r2, r8
.L_0602D0EA:
    mov.w r8, @(r0, r11)
.L_0602D0EC:
    mov.w @(r0, r11), r3
    cmp/pl r3
    bf      .L_0602D134
    mov.w   DAT_0602d186, r1
    mov.l @(r0, r1), r4
    cmp/pz r4
    bt      .L_0602D0FC
    add #-0x2, r3
.L_0602D0FC:
    add #-0x1, r3
    mov.w r3, @(r0, r11)
    .byte   0xD4, 0x24    /* mov.l .L_0602D194, r4 */
    mov r4, r2
    mov #0x0, r5
    shll16 r3
    sub r3, r2
    mov r2, r3
    cmp/pz r2
    bf      .L_0602D12E
    mov.w   DAT_0602d188, r1
    mov.l @(r0, r1), r5
    dmuls.l r3, r5
    sts mach, r3
    sts macl, r5
    xtrct r3, r5
    mov.w   .L_0602D18A, r2
    mov r5, r3
    mov.l r4, @(0, r2)
    shlr16 r3
    exts.w r3, r3
    mov.l r3, @(16, r2)
    shll16 r5
    mov.l r5, @(20, r2)
    mov.l @(28, r2), r5
.L_0602D12E:
    mov.w   DAT_0602d188, r1
    .byte   0xB3, 0x58    /* bsr 0x0602D7E4 (external) */
    mov.l r5, @(r0, r1)
.L_0602D134:
    mov.w   DAT_0602d18c, r1
    mov.l @(r0, r1), r4
    .byte   0xDD, 0x17    /* mov.l .L_0602D198, r13 */
    jsr @r13
    shll16 r10
    dmuls.l r0, r10
    sts mach, r0
    sts macl, r10
    xtrct r0, r10
    shlr16 r10
    exts.w r10, r10
    neg r10, r10
    mov r14, r0
    mov.w   DAT_0602d18e, r1
    mov.w   DAT_0602d188, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.w   .L_0602D190, r2
    mov.w @(r0, r2), r3
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    shll8 r3
    shlr16 r4
    shlr8 r4
    or r3, r4
    mov.l @(12, r0), r2
    .byte   0xD3, 0x0A    /* mov.l .L_0602D19C, r3 */
    cmp/ge r3, r2
    bt      .L_0602D1A4
    mov #0x0, r3
    .byte   0xD6, 0x09    /* mov.l .L_0602D1A0, r6 */
    cmp/ge r3, r4
    bt      .L_0602D182
    neg r6, r6
.L_0602D182:
    bra     .L_0602D1D4
    mov.l r3, @-r15

    .global DAT_0602d186
DAT_0602d186:
    .2byte  0x011C

    .global DAT_0602d188
DAT_0602d188:
    .2byte  0x010C
.L_0602D18A:
    .2byte  0xFF00

    .global DAT_0602d18c
DAT_0602d18c:
    .2byte  0x005C

    .global DAT_0602d18e
DAT_0602d18e:
    .2byte  0x0144
.L_0602D190:
    .2byte  0x00CE
    .2byte  0x0000
.L_0602D194:
    .4byte  0x000F0000
.L_0602D198:
    .4byte  cos_lookup
.L_0602D19C:
    .4byte  0x00000100
.L_0602D1A0:
    .4byte  0x00004000
.L_0602D1A4:
    mov r2, r3
    dmuls.l r2, r3
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    mov.l r3, @-r15
    mov.w   .L_0602D234, r2
    mov r4, r1
    mov.l r3, @(0, r2)
    shlr16 r1
    exts.w r1, r1
    mov.l r1, @(16, r2)
    shll16 r4
    mov.l r4, @(20, r2)
    .byte   0xDD, 0x1F    /* mov.l .L_0602D240, r13 */
    mov.l @(28, r2), r4
    jsr @r13
    nop
    cmp/eq #0x0, r0
    bf      .L_0602D1D2
    mov.w   DAT_0602d236, r4
    add r14, r4
    mov.b @r4, r0
.L_0602D1D2:
    mov r0, r6
.L_0602D1D4:
    mov r14, r0
    mov.w   DAT_0602d238, r1
    mov #0x0, r8
    mov.w @(r0, r1), r2
    cmp/pl r2
    bf      .L_0602D21A
    mov.l @(8, r0), r2
    mov #0x46, r4
    cmp/ge r4, r2
    bt      .L_0602D21A
    mov.w   .L_0602D23A, r1
    mov.w   .L_0602D23C, r3
    mov.l @(r0, r1), r2
    mov.l @(r0, r3), r4
    xor r2, r4
    cmp/pz r4
    bt      .L_0602D21A
    mov #0x1, r8
    shar r2
    mov #0x9, r5
    muls.w r2, r5
    shll16 r6
    sts macl, r4
    .byte   0xD0, 0x10    /* mov.l .L_0602D244, r0 */
    jsr @r0
    nop
    dmuls.l r0, r6
    sts mach, r2
    sts macl, r6
    xtrct r2, r6
    shlr16 r6
    exts.w r6, r6
    cmp/pz r6
    bt      .L_0602D21A
    mov #0x0, r6
.L_0602D21A:
    mov.w   .L_0602D23C, r3
    mov r14, r0
    mov.l @(r0, r3), r5
    mov #0x3, r4
    muls.w r4, r6
    neg r5, r5
    sts macl, r6
    cmp/pz r5
    bf      .L_0602D248
    cmp/gt r5, r6
    bt      .L_0602D252
    bra     .L_0602D254
    nop
.L_0602D234:
    .2byte  0xFF00

    .global DAT_0602d236
DAT_0602d236:
    .2byte  0x007F

    .global DAT_0602d238
DAT_0602d238:
    .2byte  0x0166
.L_0602D23A:
    .2byte  0x0040
.L_0602D23C:
    .2byte  0x005C
    .2byte  0x0000
.L_0602D240:
    .4byte  atan_piecewise
.L_0602D244:
    .4byte  cos_lookup
.L_0602D248:
    neg r6, r6
    cmp/gt r6, r5
    bt      .L_0602D252
    bra     .L_0602D254
    mov #0x0, r7
.L_0602D252:
    mov r5, r6
.L_0602D254:
    neg r6, r11
    mov r14, r0
    mov.w   .L_0602D270, r1
    mov.l @(r0, r1), r5
    sub r11, r10
    sub r5, r10
    add r10, r5
    .byte   0xD3, 0x04    /* mov.l .L_0602D274, r3 */
    neg r3, r4
    cmp/gt r4, r5
    bt      .L_0602D278
    mov r4, r5
    bra     .L_0602D27E
    nop
.L_0602D270:
    .2byte  0x0178
    .2byte  0x0000
.L_0602D274:
    .4byte  0x00000300
.L_0602D278:
    cmp/gt r5, r3
    bt      .L_0602D27E
    mov r3, r5
.L_0602D27E:
    mov.l r5, @(r0, r1)
    mov.w   DAT_0602d2c4, r2
    mov.l @(r0, r2), r3
    mov r3, r6
    add r3, r5
    sub r5, r6
    neg r6, r6
    shar r6
    shar r6
    shar r6
    sub r6, r5
    mov.l r5, @(r0, r2)
    mov.w   .L_0602D2C6, r1
    mov.w   .L_0602D2C8, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.w   DAT_0602d2ca, r2
    mov.w @(r0, r2), r3
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    shll8 r3
    shlr16 r4
    shlr8 r4
    or r3, r4
    mov.l @r15+, r3
    tst r3, r3
    bf      .L_0602D2D0
    .byte   0xD6, 0x03    /* mov.l .L_0602D2CC, r6 */
    bra     .L_0602D2F4
    nop

    .global DAT_0602d2c4
DAT_0602d2c4:
    .2byte  0x005C
.L_0602D2C6:
    .2byte  0x0140
.L_0602D2C8:
    .2byte  0x0108

    .global DAT_0602d2ca
DAT_0602d2ca:
    .2byte  0x00CC
.L_0602D2CC:
    .4byte  0x00004000
.L_0602D2D0:
    mov.w   .L_0602D306, r2
    mov r4, r1
    mov.l r3, @(0, r2)
    shlr16 r1
    exts.w r1, r1
    mov.l r1, @(16, r2)
    shll16 r4
    mov.l r4, @(20, r2)
    .byte   0xD0, 0x0A    /* mov.l .L_0602D30C, r0 */
    mov.l @(28, r2), r4
    jsr @r0
    nop
    cmp/eq #0x0, r0
    bf      .L_0602D2F2
    mov.w   .L_0602D308, r4
    add r14, r4
    mov.b @r4, r0
.L_0602D2F2:
    mov r0, r6
.L_0602D2F4:
    mov r14, r0
    mov #0x32, r3
    mov.w   DAT_0602d30a, r4
    mov.l @(8, r0), r7
    cmp/gt r3, r7
    bt      .L_0602D310
    mov r3, r7
    bra     .L_0602D316
    nop
.L_0602D306:
    .2byte  0xFF00
.L_0602D308:
    .2byte  0x007E

    .global DAT_0602d30a
DAT_0602d30a:
    .2byte  0x00FA
.L_0602D30C:
    .4byte  atan_piecewise
.L_0602D310:
    cmp/gt r7, r4
    bt      .L_0602D316
    mov r4, r7
.L_0602D316:
    sub r3, r4
    sub r3, r7
    .byte   0xDC, 0x1C    /* mov.l .L_0602D38C, r12 */
    shll8 r7
    mov r4, r0
    jsr @r12
    mov r7, r1
    mov r14, r0
    mov #0x2, r3
    mov #0x4, r4
    muls.w r4, r1
    shll8 r3
    sts macl, r7
    add r3, r7
    mov.l r7, @-r15
    mov.w   .L_0602D388, r1
    mov.l @(r0, r1), r3
    mov.w   DAT_0602d38a, r2
    mov.l @(r0, r2), r4
    mov r3, r5
    sub r4, r5
    muls.w r6, r7
    sts macl, r6
    shar r6
    neg r4, r4
    shar r6
    mov r5, r7
    shar r6
    xor r3, r7
    shar r6
    shar r6
    shar r6
    shar r6
    shar r6
    cmp/pz r7
    bt      .L_0602D37C
    .byte   0xD4, 0x0C    /* mov.l .L_0602D390, r4 */
    cmp/pz r3
    bt      .L_0602D366
    neg r4, r4
.L_0602D366:
    sub r4, r3
    neg r3, r3
    dmuls.l r3, r6
    .byte   0xDC, 0x07    /* mov.l .L_0602D38C, r12 */
    mov r4, r0
    mov.l r1, @-r15
    jsr @r12
    sts macl, r1
    mov r0, r6
    mov.l @r15+, r1
    mov r14, r0
.L_0602D37C:
    cmp/pz r5
    bf      .L_0602D394
    cmp/gt r5, r6
    bt      .L_0602D39E
    bra     .L_0602D3A0
    nop
.L_0602D388:
    .2byte  0x0040

    .global DAT_0602d38a
DAT_0602d38a:
    .2byte  0x005C
.L_0602D38C:
    .4byte  sym_0602ECCC
.L_0602D390:
    .4byte  0x00000FE0
.L_0602D394:
    neg r6, r6
    cmp/gt r6, r5
    bt      .L_0602D39E
    bra     .L_0602D3A0
    nop
.L_0602D39E:
    mov r5, r6
.L_0602D3A0:
    shll8 r6
    .byte   0xDC, 0x12    /* mov.l .L_0602D3EC, r12 */
    mov.l @r15+, r0
    jsr @r12
    mov r6, r1
    mov r0, r6
    mov r14, r0
    sub r5, r6
    mov.w   DAT_0602d3e8, r1
    mov.l @(r0, r1), r3
    sub r6, r3
    neg r3, r3
    shar r3
    shar r3
    shar r3
    sub r3, r6
    mov.l r6, @(r0, r1)
    mov.l @(8, r0), r3
    mov #0x41, r4
    cmp/ge r3, r4
    bt      .L_0602D414
    mov.w   DAT_0602d3ea, r7
    mov.l @(r0, r7), r6
    .byte   0xD5, 0x08    /* mov.l .L_0602D3F0, r5 */
    cmp/ge r6, r5
    bt      .L_0602D3FC
    neg r5, r5
    cmp/gt r6, r5
    bt      .L_0602D414
    mov.l @(0, r0), r2
    .byte   0xD3, 0x05    /* mov.l .L_0602D3F4, r3 */
    or r3, r2
    .byte   0xD3, 0x05    /* mov.l .L_0602D3F8, r3 */
    or r3, r2
    bra     .L_0602D414
    mov.l r2, @(0, r0)

    .global DAT_0602d3e8
DAT_0602d3e8:
    .2byte  0x0058

    .global DAT_0602d3ea
DAT_0602d3ea:
    .2byte  0x005C
.L_0602D3EC:
    .4byte  sym_0602ECCC
.L_0602D3F0:
    .4byte  0xFFFFCD80
.L_0602D3F4:
    .4byte  0x20000000
.L_0602D3F8:
    .4byte  0x40000000
.L_0602D3FC:
    mov.l @(0, r0), r2
    .byte   0xD3, 0x03    /* mov.l .L_0602D40C, r3 */
    or r3, r2
    .byte   0xD3, 0x03    /* mov.l .L_0602D410, r3 */
    or r3, r2
    bra     .L_0602D414
    mov.l r2, @(0, r0)
    .2byte  0x0000
.L_0602D40C:
    .4byte  0x10000000
.L_0602D410:
    .4byte  0x40000000
.L_0602D414:
    mov.w   DAT_0602d432, r7
    mov.l @(r0, r7), r6
    .byte   0xD3, 0x07    /* mov.l .L_0602D438, r3 */
    cmp/ge r6, r3
    bt      .L_0602D424
    neg r3, r3
    cmp/ge r6, r3
    bt      .L_0602D42C
.L_0602D424:
    mov r3, r6
    mov #0x1, r4
    mov.w   .L_0602D434, r1
    mov.w r4, @(r0, r1)
.L_0602D42C:
    lds.l @r15+, pr
    rts
    mov.l r6, @(r0, r7)

    .global DAT_0602d432
DAT_0602d432:
    .2byte  0x005C
.L_0602D434:
    .2byte  0x00D4
    .2byte  0x0000
.L_0602D438:
    .4byte  0xFFFFCC00
