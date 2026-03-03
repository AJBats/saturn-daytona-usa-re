
    .section .text.FUN_06006A9C


    .global scene_path_a
    .type scene_path_a, @function
scene_path_a:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x30, r15
    mov.l   .L_06006B5C, r8
    mov.l   .L_06006B60, r9
    mov.l   .L_06006B64, r14
    mov.l   .L_06006B68, r4
    mov.l @r14, r0
    shll2 r0
    shll r0
    mov.l @(r0, r4), r3
    mov.l r3, @(12, r15)
    mov.l @r14, r0
    shll r0
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r4), r2
    mov.l r2, @(4, r15)
    mov.l   .L_06006B6C, r4
    mov.l @r14, r0
    shll2 r0
    shll2 r0
    mov.l @(r0, r4), r1
    mov.l r1, @(32, r15)
    mov.l @r14, r5
    shll2 r5
    mov r5, r0
    add #0x1, r0
    shll2 r0
    mov.l @(r0, r4), r3
    mov r5, r0
    mov.l r3, @(36, r15)
    add #0x2, r0
    shll2 r0
    mov.l @(r0, r4), r2
    mov r5, r0
    mov.l r2, @(20, r15)
    add #0x3, r0
    shll2 r0
    mov.l @(r0, r4), r1
    mov.l r1, @(24, r15)
    mov.l   .L_06006B70, r5
    mov.l   .L_06006B74, r3
    mov.l @r5, r4
    add r3, r4
    shlr16 r4
    shlr2 r4
    shlr2 r4
    shlr r4
    mov.l @(8, r5), r2
    neg r2, r2
    add #-0x1, r3
    add r3, r2
    mov r2, r5
    shlr16 r5
    shlr2 r5
    shlr2 r5
    shlr r5
    mov #-0x2, r6
    mov r5, r2
    mov r6, r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r4, r2
    mov.l r2, @(28, r15)
    mov.l r3, @(44, r15)
    mov #0x2, r3
    mov.l r3, @(16, r15)
    mov.l r3, @(40, r15)
    mov #0x3E, r3
    cmp/hs r3, r5
    bf      .L_06006B44
    mov #0x3F, r3
    sub r5, r3
    mov.l r3, @(16, r15)
    bra     .L_06006B4C
    nop
.L_06006B44:
    mov #0x1, r2
    cmp/hi r2, r5
    bt      .L_06006B4C
    neg r5, r6
.L_06006B4C:
    mov #0x3E, r2
    cmp/hs r2, r4
    bf      .L_06006B78
    mov #0x3F, r2
    sub r4, r2
    bra     .L_06006B82
    mov.l r2, @(40, r15)
    .2byte  0xFFFF
.L_06006B5C:
    .4byte  sym_060620D4
.L_06006B60:
    .4byte  sym_06089E44
.L_06006B64:
    .4byte  sym_0607EAD8
.L_06006B68:
    .4byte  sym_06062248
.L_06006B6C:
    .4byte  sym_06062260
.L_06006B70:
    .4byte  sym_06063DF8
.L_06006B74:
    .4byte  0x04000000
.L_06006B78:
    mov #0x1, r2
    cmp/hi r2, r4
    bt      .L_06006B82
    neg r4, r4
    mov.l r4, @(44, r15)
.L_06006B82:
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @(16, r15), r3
    shll2 r3
    shll2 r3
    shll2 r3
    mov.l r3, @(16, r15)
    bra     .L_06006CAC
    mov r6, r10
.L_06006B96:
    bra     .L_06006CA0
    mov.l @(44, r15), r12
.L_06006B9A:
    mov r10, r0
    cmp/eq #-0x80, r0
    bt      .L_06006BB6
    mov.w   DAT_06006c1e, r3
    cmp/eq r3, r10
    bt      .L_06006BB6
    mov r12, r0
    cmp/eq #-0x2, r0
    bt      .L_06006BB6
    mov r12, r0
    cmp/eq #0x2, r0
    bf      .L_06006C9E
    bra     .L_06006BB6
    nop
.L_06006BB6:
    mov r10, r2
    mov.l @(28, r15), r3
    add r12, r2
    add r3, r2
    mov r2, r4
    mov.l r2, @r15
    shll r4
    mov.l @(32, r15), r13
    mov.l @(20, r15), r3
    add r4, r13
    add r3, r4
    mov.w @r13, r13
    exts.w r13, r2
    cmp/pl r2
    bf/s    .L_06006C3E
    mov.w @r4, r11
    mov.l @r14, r3
    mov.l   .L_06006C24, r2
    mov.l @r15, r0
    mov.l @(36, r15), r1
    shll2 r3
    shll2 r0
    shll r3
    mov.l @(r0, r1), r0
    add r2, r3
    mov.l @r3, r3
    exts.w r13, r2
    add r0, r3
    mov.l r3, @(8, r15)
    mov.l @r8, r0
    add r0, r2
    mov.w   .L_06006C20, r0
    cmp/hs r0, r2
    bf      .L_06006C02
    mov.w   .L_06006C20, r13
    mov.l @r8, r3
    sub r3, r13
    exts.w r13, r13
.L_06006C02:
    mov.l @r14, r0
    cmp/eq #0x2, r0
    bt      .L_06006C2C
    exts.w r13, r7
    mov r9, r6
    mov.l @(12, r15), r5
    mov.l   .L_06006C28, r3
    add #0x52, r6
    mov.w @r6, r6
    extu.w r6, r6
    jsr @r3
    mov.l @(8, r15), r4
    bra     .L_06006C3E
    nop

    .global DAT_06006c1e
DAT_06006c1e:
    .2byte  0x0080
.L_06006C20:
    .2byte  0x0640
    .2byte  0xFFFF
.L_06006C24:
    .4byte  sym_06062230
.L_06006C28:
    .4byte  sym_0602A214
.L_06006C2C:
    exts.w r13, r7
    mov r9, r6
    mov.l @(12, r15), r5
    mov.l   .L_06006CCC, r3
    add #0x52, r6
    mov.w @r6, r6
    extu.w r6, r6
    jsr @r3
    mov.l @(8, r15), r4
.L_06006C3E:
    exts.w r11, r2
    cmp/pl r2
    bf      .L_06006C9E
    exts.w r11, r1
    mov.l @r14, r13
    mov.l   .L_06006CD0, r3
    mov.l @r15, r0
    mov.l @(24, r15), r2
    shll r13
    shll2 r0
    add #0x1, r13
    mov.l @(r0, r2), r0
    shll2 r13
    add r3, r13
    mov.l @r13, r13
    add r0, r13
    mov.l @r8, r0
    add r0, r1
    mov.w   DAT_06006cca, r0
    cmp/hs r0, r1
    bf      .L_06006C70
    mov.w   DAT_06006cca, r11
    mov.l @r8, r3
    sub r3, r11
    exts.w r11, r11
.L_06006C70:
    mov.l @r14, r0
    cmp/eq #0x2, r0
    bt      .L_06006C8C
    exts.w r11, r7
    mov r9, r6
    mov.l @(4, r15), r5
    mov.l   .L_06006CD4, r3
    add #0x52, r6
    mov.w @r6, r6
    extu.w r6, r6
    jsr @r3
    mov r13, r4
    bra     .L_06006C9E
    nop
.L_06006C8C:
    exts.w r11, r7
    mov r9, r6
    mov.l @(4, r15), r5
    mov.l   .L_06006CD8, r3
    add #0x52, r6
    mov.w @r6, r6
    extu.w r6, r6
    jsr @r3
    mov r13, r4
.L_06006C9E:
    add #0x1, r12
.L_06006CA0:
    mov.l @(40, r15), r2
    cmp/ge r2, r12
    bt      .L_06006CAA
    bra     .L_06006B9A
    nop
.L_06006CAA:
    add #0x40, r10
.L_06006CAC:
    mov.l @(16, r15), r2
    cmp/ge r2, r10
    bt      .L_06006CB6
    bra     .L_06006B96
    nop
.L_06006CB6:
    add #0x30, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06006cca
DAT_06006cca:
    .2byte  0x0640
.L_06006CCC:
    .4byte  vdp1_list_finalize
.L_06006CD0:
    .4byte  sym_06062230
.L_06006CD4:
    .4byte  sym_0602ABB8
.L_06006CD8:
    .4byte  sym_0602B9E0
