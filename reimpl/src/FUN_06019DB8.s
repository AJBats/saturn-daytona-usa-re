
    .section .text.FUN_06019DB8


    .global FUN_06019DB8
    .type FUN_06019DB8, @function

FUN_06019DB8:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x6, r11
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15

    mov.l   .L_pool_06019E70, r8
    mov.l   .L_pool_06019E74, r9
    mov.l   .L_pool_06019E78, r12
    mov.l   .L_pool_06019E7C, r0
    mov.b @r0, r0
    cmp/eq #0x1, r0
    bt/s    .L_06019E40
    mov #0x5, r14

    mov #0x0, r13
.L_06019DDE:
    extu.b r13, r2
    mov.l   .L_pool_06019E80, r3
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_06019DEC
    bra     .L_06019DEE
    extu.b r11, r10
.L_06019DEC:
    extu.b r14, r10

.L_06019DEE:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @(8, r15)
    shll2 r7
    mov.w @(r0, r8), r3
    mov.l   .L_pool_06019E84, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.l @(8, r15), r6
    add r3, r7
    mov.l   .L_pool_06019E88, r3
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov.l @r15, r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4

    add #0x1, r13
    extu.b r13, r3
    cmp/ge r14, r3
    bf      .L_06019DDE
    bra     .L_06019EDC
    nop

.L_06019E40:
    mov #0x0, r13
.L_06019E42:
    extu.b r13, r2
    mov.l   .L_pool_06019E80, r3
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_06019E8C

    mov #0x8, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_06019E5A
    bra     .L_06019E8E
    extu.b r11, r10

.L_06019E5A:
    mov #0x10, r3
    mov.b @r12, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bf/s    .L_06019E6A
    mov #0x7, r10
    mov #0x0, r3
    mov.b r3, @r12
.L_06019E6A:
    bra     .L_06019E8E
    nop
    .2byte  0xFFFF

.L_pool_06019E70:
    .4byte  sym_06049B2C
.L_pool_06019E74:
    .4byte  sym_06028400
.L_pool_06019E78:
    .4byte  sym_0605D242
.L_pool_06019E7C:
    .4byte  sym_06085FF0
.L_pool_06019E80:
    .4byte  sym_0605AD0C
.L_pool_06019E84:
    .4byte  sym_06063750
.L_pool_06019E88:
    .4byte  sym_06049B18

.L_06019E8C:
    mov #0x3, r10

.L_06019E8E:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @r15
    shll2 r7
    mov.w @(r0, r8), r3
    mov.l   .L_pool_06019F44, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(8, r15)
    mov.l @(4, r2), r3
    mov.l @r15, r6
    add r3, r7
    mov.l   .L_pool_06019F48, r3
    add r3, r6
    mov.l r6, @(4, r15)
    mov.b @(1, r6), r0
    mov.l @(4, r15), r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(8, r15), r5
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4

    add #0x1, r13
    extu.b r13, r3
    cmp/ge r14, r3
    bf      .L_06019E42

.L_06019EDC:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06019EF0
    .type FUN_06019EF0, @function
FUN_06019EF0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_pool_06019F4C, r13
    mov.l   .L_pool_06019F50, r14
    mov.w @r13, r0
    extu.w r0, r0
    tst #0x1, r0
    bt/s    .L_06019F08
    mov #0x0, r12
    bra     .L_06019F0A
    mov #0x6, r5
.L_06019F08:
    mov #0x19, r5
.L_06019F0A:
    mov.l   .L_06019F54, r7
    mov.l   .L_pool_06019F58, r4
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    tst r2, r2
    bt      .L_06019F26
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_06019F96
    mov.b r2, @r4
.L_06019F26:
    mov.w   .L_wpool_06019F40, r6
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_06019F5C
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_06019F96
    mov.b r2, @r4
.L_wpool_06019F40:
    .2byte  0x4000
    .2byte  0xFFFF
.L_pool_06019F44:
    .4byte  sym_06063750
.L_pool_06019F48:
    .4byte  sym_06049B18
.L_pool_06019F4C:
    .4byte  g_pad_state
.L_pool_06019F50:
    .4byte  sym_0605AD0C
.L_06019F54:
    .4byte  0x00008000
.L_pool_06019F58:
    .4byte  sym_0605D243
.L_06019F5C:
    mov.w @r13, r2
    extu.w r2, r2
    and r7, r2
    tst r2, r2
    bt      .L_06019F7A
    mov.b @r4, r3
    extu.b r5, r5
    cmp/eq r5, r3
    bf      .L_06019F96
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_06019F96
    mov.b r2, @r4
.L_06019F7A:
    mov.w @r13, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_06019F96
    extu.b r5, r5
    mov.b @r4, r3
    cmp/eq r5, r3
    bf      .L_06019F96
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    mov.b r2, @r4
.L_06019F96:
    mov #0x5, r2
    mov.l @r14, r3
    cmp/ge r2, r3
    bf      .L_06019FA2
    mov #0x4, r2
    mov.l r2, @r14
.L_06019FA2:
    mov.l @r14, r3
    cmp/pz r3
    bt      .L_06019FAA
    mov.l r12, @r14
.L_06019FAA:
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     FUN_06019DB8
    mov.l @r15+, r14


    .global FUN_06019FB2
    .type FUN_06019FB2, @function
FUN_06019FB2:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x6, r11
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15

    mov.l   .L_pool_06019FED, r8
    mov.l   .L_pool_06019FF1, r9
    mov.l   .L_pool_06019FF5, r12
    mov.l   .L_pool_06019FF9, r0
    mov.b @r0, r0
    cmp/eq #0x2, r0
    bt/s    .L_0601A050
    mov #0x5, r14

    mov #0x0, r13
.L_06019FD8:
    extu.b r13, r2
    mov.l   .L_pool_06019FFD, r3
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_06019FFC
    bra     .L_06019FFE
    extu.b r11, r10
    .2byte  0xFFFF

.L_pool_06019FED:
    .4byte  sym_06049B2C
.L_pool_06019FF1:
    .4byte  sym_06028400
.L_pool_06019FF5:
    .4byte  sym_0605D242
.L_pool_06019FF9:
    .4byte  sym_06085FF0
.L_pool_06019FFD:
    .4byte  sym_0605AD04

.L_06019FFC:
    extu.b r14, r10

.L_06019FFE:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @(8, r15)
    shll2 r7
    mov.w @(r0, r8), r3
    mov.l   .L_pool_0601A0EE, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.l @(8, r15), r6
    add r3, r7
    mov.l   .L_pool_0601A0F2, r3
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov.l @r15, r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4

    add #0x1, r13
    extu.b r13, r3
    cmp/ge r14, r3
    bf      .L_06019FD8
    bra     .L_0601A0CE
    nop

.L_0601A050:
    mov #0x0, r13
.L_0601A052:
    extu.b r13, r2
    mov.l   .L_pool_0601A0F6, r3
    mov.l @r3, r3
    cmp/eq r3, r2
    bf      .L_0601A07E

    mov #0x8, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bt      .L_0601A06A
    bra     .L_0601A080
    extu.b r11, r10

.L_0601A06A:
    mov #0x10, r3
    mov.b @r12, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bf/s    .L_0601A07A
    mov #0x7, r10
    mov #0x0, r3
    mov.b r3, @r12

.L_0601A07A:
    bra     .L_0601A080
    nop

.L_0601A07E:
    mov #0x3, r10

.L_0601A080:
    extu.b r10, r7
    extu.b r13, r0
    shll8 r7
    shll r0
    shll2 r7
    mov.l r0, @r15
    shll2 r7
    mov.w @(r0, r8), r3
    mov.l   .L_pool_0601A0EE, r2
    extu.w r3, r3
    shll2 r3
    shll r3
    add r3, r2
    mov.l r2, @(8, r15)
    mov.l @(4, r2), r3
    mov.l @r15, r6
    add r3, r7
    mov.l   .L_pool_0601A0F2, r3
    add r3, r6
    mov.l r6, @(4, r15)
    mov.b @(1, r6), r0
    mov.l @(4, r15), r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(8, r15), r5
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4

    add #0x1, r13
    extu.b r13, r3
    cmp/ge r14, r3
    bf      .L_0601A052

.L_0601A0CE:
    add #0xC, r15
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

.L_pool_0601A0EE:
    .4byte  sym_06063750
.L_pool_0601A0F2:
    .4byte  sym_06049B22
.L_pool_0601A0F6:
    .4byte  sym_0605AD04
