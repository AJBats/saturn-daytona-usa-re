
    .section .text.FUN_06026110


    .global scene_dual_finalize
    .type scene_dual_finalize, @function
scene_dual_finalize:
    mov.l r14, @-r15
    mov #0x0, r14
    mov.l r13, @-r15
    extu.b r14, r3
    extu.b r14, r1
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov #0x8, r8
    mov.l   .L_060261A4, r9
    mov.l   .L_060261A8, r10
    mov.l   .L_060261AC, r11
    mov.l   .L_060261B0, r12
    mov.l   .L_060261B4, r2
    mov.b r3, @r2
    mov.l   .L_060261B8, r2
    mov.b r1, @r2
    mov.l   .L_060261BC, r4
    mov.b @r4, r0
    extu.b r0, r0
    tst r0, r0
    bt/s    .L_06026148
    mov #0xE, r13
    bra     .L_060262AA
    nop
.L_06026148:
    mov #0x1, r3
    mov.b r3, @r4
    extu.w r14, r4
.L_0602614E:
    extu.b r4, r5
    mov r5, r3
    add #0x1, r4
    shll2 r5
    shll2 r3
    shll r3
    add r3, r5
    extu.b r5, r5
    extu.w r14, r3
    add r11, r5
    mov.l @r5, r2
    mov.w r14, @r2
    mov.l @(4, r5), r2
    mov.w r3, @r2
    extu.w r4, r2
    cmp/ge r13, r2
    bf      .L_0602614E
    extu.w r14, r4
.L_06026172:
    extu.w r4, r2
    shll2 r2
    shll r2
    add r12, r2
    mov.l @r2, r3
    mov.w @r3, r2
    extu.w r2, r2
    tst r2, r2
    bt      .L_06026188
    bra     .L_06026190
    nop
.L_06026188:
    add #0x1, r4
    extu.w r4, r2
    cmp/ge r13, r2
    bf      .L_06026172
.L_06026190:
    extu.w r4, r4
    cmp/ge r13, r4
    bt      .L_060261A0
    mov.l   .L_060261C0, r3
    jsr @r3
    nop
    bra     .L_06026218
    nop
.L_060261A0:
    bra     .L_06026212
    extu.w r14, r5
.L_060261A4:
    .4byte  sym_06060F2C                /* scene output table A (8-byte stride) */
.L_060261A8:
    .4byte  sym_0606107C                /* scene output table B (8-byte stride) */
.L_060261AC:
    .4byte  sym_060610BC                /* slot element table (12-byte stride) */
.L_060261B0:
    .4byte  sym_06060D7C                /* scene data table A (8-byte stride) */
.L_060261B4:
    .4byte  sym_06061198                /* render phase state byte */
.L_060261B8:
    .4byte  sym_06061199                /* variant active flag byte */
.L_060261BC:
    .4byte  sym_06060D78                /* dual finalize active flag byte */
.L_060261C0:
    .4byte  scene_finalize_a            /* rebuilds scene output from data table A */
.L_060261C4:
    extu.w r14, r4
    extu.b r5, r7
    extu.w r5, r6
    mov r7, r3
    shll2 r6
    shll2 r7
    shll2 r3
    shll r3
    add r3, r7
    extu.b r7, r7
    add r11, r7
    shll r6
    add r12, r6
.L_060261DE:
    extu.w r4, r3
    shll2 r3
    shll r3
    add r9, r3
    mov.w @(6, r3), r0
    mov r0, r2
    extu.w r2, r2
    mov.w @(8, r7), r0
    mov r0, r3
    extu.w r3, r3
    cmp/eq r3, r2
    bf      .L_06026206
    mov.l @r6, r2
    extu.w r4, r3
    shll2 r3
    shll r3
    add r9, r3
    mov.w @(4, r3), r0
    mov r0, r1
    mov.w r1, @r2
.L_06026206:
    add #0x1, r4
    mov #0xA, r2
    extu.w r4, r3
    cmp/ge r2, r3
    bf      .L_060261DE
    add #0x1, r5
.L_06026212:
    extu.w r5, r2
    cmp/ge r13, r2
    bf      .L_060261C4
.L_06026218:
    extu.w r14, r4
.L_0602621A:
    extu.w r4, r2
    shll2 r2
    shll r2
    add r12, r2
    mov.l @(4, r2), r3
    mov.w @r3, r2
    extu.w r2, r2
    tst r2, r2
    bt      .L_06026230
    bra     .L_06026238
    nop
.L_06026230:
    add #0x1, r4
    extu.w r4, r2
    cmp/ge r13, r2
    bf      .L_0602621A
.L_06026238:
    extu.w r4, r4
    cmp/ge r13, r4
    bt      .L_06026252
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_060262BC, r3
    jmp @r3
    mov.l @r15+, r14
.L_06026252:
    bra     .L_060262A4
    extu.w r14, r5
.L_06026256:
    extu.w r14, r4
    extu.b r5, r7
    extu.w r5, r6
    mov r7, r3
    shll2 r6
    shll2 r7
    shll2 r3
    shll r3
    add r3, r7
    extu.b r7, r7
    add r11, r7
    shll r6
    add r12, r6
    add #0x4, r6
.L_06026272:
    extu.w r4, r3
    shll2 r3
    shll r3
    add r10, r3
    mov.w @(6, r3), r0
    mov r0, r2
    extu.w r2, r2
    mov.w @(8, r7), r0
    mov r0, r3
    extu.w r3, r3
    cmp/eq r3, r2
    bf      .L_0602629A
    mov.l @r6, r2
    extu.w r4, r3
    shll2 r3
    shll r3
    add r10, r3
    mov.w @(4, r3), r0
    mov r0, r1
    mov.w r1, @r2
.L_0602629A:
    add #0x1, r4
    extu.w r4, r3
    cmp/ge r8, r3
    bf      .L_06026272
    add #0x1, r5
.L_060262A4:
    extu.w r5, r3
    cmp/ge r13, r3
    bf      .L_06026256
.L_060262AA:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_060262BC:
    .4byte  scene_finalize_b            /* rebuilds scene output from data table B */
