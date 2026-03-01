
    .section .text.FUN_06006CDC


    .global scene_path_b
    .type scene_path_b, @function
scene_path_b:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x3C, r15
    mov.l   .L_06006DB0, r10
    mov.l   .L_06006DB4, r13
    mov.w   DAT_06006da6, r14
    mov.l   .L_06006DB8, r4
    mov.w   .L_06006DA8, r3
    mov.l   .L_06006DBC, r2
    mov.l   .L_06006DC0, r5
    mov.l @r13, r0
    mov.l @r4, r4
    shll2 r0
    add r3, r4
    shll r0
    and r2, r4
    mov.l @(r0, r5), r3
    shlr8 r4
    mov.l r3, @(12, r15)
    shlr2 r4
    mov.l @r13, r0
    shlr2 r4
    shll r0
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r5), r2
    mov.l r2, @(16, r15)
    mov.w   .L_06006DAA, r1
    mul.l r1, r4
    sts macl, r4
    mov.l   .L_06006DC4, r0
    add r0, r4
    mov.w   .L_06006DAC, r1
    add r1, r4
    mov.l r4, @(36, r15)
    mov.l   .L_06006DC8, r4
    mov.l @r13, r0
    shll2 r0
    shll2 r0
    mov.l @(r0, r4), r1
    mov.l r1, @(40, r15)
    mov.l @r13, r5
    shll2 r5
    mov r5, r0
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r4), r3
    mov.l r3, @(48, r15)
    mov r5, r0
    add #0x2, r0
    shll2 r0
    mov.l @(r0, r4), r2
    mov.l r2, @(44, r15)
    mov r5, r0
    add #0x3, r0
    shll2 r0
    mov.l @(r0, r4), r1
    mov.l r1, @(24, r15)
    mov.l   .L_06006DCC, r5
    mov.l   .L_06006DD0, r3
    mov.l @r5, r4
    mov.l @(8, r5), r2
    add r3, r4
    neg r2, r2
    shlr16 r4
    add #-0x1, r3
    shlr2 r4
    add r3, r2
    shlr2 r4
    mov r2, r5
    shlr r4
    shlr16 r5
    shlr2 r5
    shlr2 r5
    shlr r5
    mov r5, r2
    shll2 r2
    shll2 r2
    shll2 r2
    add r4, r2
    mov.l r2, @r15
    mov #0x0, r3
    mov.l r3, @(52, r15)
    mov r3, r6
    mov #0xB, r3
    mov.l r3, @(28, r15)
    mov.l r3, @(56, r15)
    mov #0x3B, r3
    cmp/hs r3, r5
    bf      .L_06006DD4
    mov #0x45, r3
    sub r5, r3
    bra     .L_06006DDE
    mov.l r3, @(56, r15)

    .global DAT_06006da6
DAT_06006da6:
    .2byte  0x0640
.L_06006DA8:
    .2byte  0x0800
.L_06006DAA:
    .2byte  0x00F2
.L_06006DAC:
    .2byte  0x2000
    .2byte  0xFFFF
.L_06006DB0:
    .4byte  sym_060620D4
.L_06006DB4:
    .4byte  sym_0607EAD8
.L_06006DB8:
    .4byte  sym_06063EF0
.L_06006DBC:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_06006DC0:
    .4byte  sym_06062248
.L_06006DC4:
    .4byte  0x002F0000                  /* vis table base address offset */
.L_06006DC8:
    .4byte  sym_06062260
.L_06006DCC:
    .4byte  sym_06063DF8
.L_06006DD0:
    .4byte  0x04000000                  /* angle-to-column rounding bias */
.L_06006DD4:
    mov #0x5, r3
    cmp/hs r3, r5
    bt      .L_06006DDE
    mov #0x5, r6
    sub r5, r6
.L_06006DDE:
    mov #0x3B, r3
    cmp/hs r3, r4
    bf      .L_06006DEC
    mov #0x45, r3
    sub r4, r3
    bra     .L_06006DF8
    mov.l r3, @(28, r15)
.L_06006DEC:
    mov #0x5, r3
    cmp/hs r3, r4
    bt      .L_06006DF8
    mov #0x5, r3
    sub r4, r3
    mov.l r3, @(52, r15)
.L_06006DF8:
    mov.l   .L_06006E84, r8
    bra     .L_06006F0C
    mov.l r6, @(8, r15)
.L_06006DFE:
    mov.l @(52, r15), r2
    mov.l r2, @(4, r15)
    mov.l @(8, r15), r3
    mov #0xB, r2
    mul.l r2, r3
    sts macl, r3
    bra     .L_06006EFE
    mov.l r3, @(32, r15)
.L_06006E0E:
    mov.l @(32, r15), r0
    mov.l @(4, r15), r3
    mov.l @(36, r15), r2
    add r3, r0
    shll r0
    mov.w @(r0, r2), r9
    tst r9, r9
    bf      .L_06006E22
    bra     .L_06006EF8
    nop
.L_06006E22:
    exts.w r9, r4
    mov.l @r15, r3
    mov.l @(40, r15), r12
    mov.l @(44, r15), r2
    add r3, r4
    shll r4
    add r4, r12
    mov.w @r12, r12
    add r2, r4
    exts.w r12, r1
    cmp/pl r1
    bf/s    .L_06006E9E
    mov.w @r4, r11
    exts.w r9, r0
    mov.l @r15, r3
    mov.l @(48, r15), r2
    mov.l @r13, r1
    add r3, r0
    shll2 r1
    shll2 r0
    mov.l   .L_06006E88, r3
    shll r1
    mov.l @(r0, r2), r0
    add r3, r1
    exts.w r12, r3
    mov.l @r1, r1
    add r1, r0
    mov.l r0, @(20, r15)
    mov.l @r10, r1
    add r1, r3
    cmp/hs r14, r3
    bf      .L_06006E6A
    mov.l @r10, r2
    mov r14, r12
    sub r2, r12
    exts.w r12, r12
.L_06006E6A:
    mov.l @r13, r0
    cmp/eq #0x2, r0
    bt      .L_06006E90
    exts.w r12, r7
    mov.w @r8, r6
    mov.l @(12, r15), r5
    mov.l   .L_06006E8C, r3
    extu.w r6, r6
    jsr @r3
    mov.l @(20, r15), r4
    bra     .L_06006E9E
    nop
    .2byte  0xFFFF
.L_06006E84:
    .4byte  sym_06089E96
.L_06006E88:
    .4byte  sym_06062230
.L_06006E8C:
    .4byte  sym_0602ABB8
.L_06006E90:
    exts.w r12, r7
    mov.w @r8, r6
    mov.l @(12, r15), r5
    mov.l   .L_06006F30, r3
    extu.w r6, r6
    jsr @r3
    mov.l @(20, r15), r4
.L_06006E9E:
    exts.w r11, r2
    cmp/pl r2
    bf      .L_06006EF8
    exts.w r9, r0
    mov.l @r15, r2
    mov.l @r13, r12
    mov.l   .L_06006F34, r3
    mov.l @(24, r15), r1
    add r2, r0
    shll r12
    shll2 r0
    add #0x1, r12
    shll2 r12
    add r3, r12
    mov.l @r12, r12
    mov.l @(r0, r1), r3
    exts.w r11, r0
    add r3, r12
    mov.l @r10, r3
    add r3, r0
    cmp/hs r14, r0
    bf      .L_06006ED2
    mov.l @r10, r3
    mov r14, r11
    sub r3, r11
    exts.w r11, r11
.L_06006ED2:
    mov.l @r13, r0
    cmp/eq #0x2, r0
    bt      .L_06006EEA
    exts.w r11, r7
    mov.w @r8, r6
    mov.l @(16, r15), r5
    mov.l   .L_06006F38, r3
    extu.w r6, r6
    jsr @r3
    mov r12, r4
    bra     .L_06006EF8
    nop
.L_06006EEA:
    exts.w r11, r7
    mov.w @r8, r6
    mov.l @(16, r15), r5
    mov.l   .L_06006F30, r3
    extu.w r6, r6
    jsr @r3
    mov r12, r4
.L_06006EF8:
    mov.l @(4, r15), r2
    add #0x1, r2
    mov.l r2, @(4, r15)
.L_06006EFE:
    mov.l @(4, r15), r3
    mov.l @(28, r15), r2
    cmp/hs r2, r3
    bf      .L_06006E0E
    mov.l @(8, r15), r2
    add #0x1, r2
    mov.l r2, @(8, r15)
.L_06006F0C:
    mov.l @(8, r15), r3
    mov.l @(56, r15), r2
    cmp/hs r2, r3
    bt      .L_06006F18
    bra     .L_06006DFE
    nop
.L_06006F18:
    add #0x3C, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_06006F30:
    .4byte  sym_0602B9E0
.L_06006F34:
    .4byte  sym_06062230
.L_06006F38:
    .4byte  sym_0602ABB8
