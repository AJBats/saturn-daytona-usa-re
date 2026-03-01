
    .section .text.FUN_06039100


    .global color_transform_calc
    .type color_transform_calc, @function
color_transform_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_06039194, r11
    mov.l   .L_06039198, r14
    mov.l r5, @(4, r15)
    mov r6, r13
    mov.l r7, @r15
    mov #0x0, r5
    bra     .L_06039160
    extu.b r4, r0
.L_06039122:
    mov.l r5, @(24, r14)
    mov r14, r4
    add r5, r4
    mov r14, r2
    add #0x4, r2
    add r2, r5
    mov #0x2, r3
    mov r3, r0
    mov.b r0, @(8, r15)
    mov.w   DAT_0603918c, r8
    mov #0x1, r9
    mov r8, r10
    bra     .L_0603916C
    add #0x1, r10
.L_0603913E:
    mov.l r5, @(28, r14)
    mov r14, r4
    add #0x8, r4
    add r5, r4
    mov r14, r2
    add #0xC, r2
    add r2, r5
    mov #0x8, r3
    mov r3, r0
    mov.b r0, @(8, r15)
    mov.w   DAT_0603918e, r8
    mov #0x4, r9
    mov r8, r10
    bra     .L_0603916C
    add #0x4, r10
.L_0603915C:
    bra     .L_06039228
    nop
.L_06039160:
    cmp/eq #0x0, r0
    bt      .L_06039122
    cmp/eq #0x1, r0
    bt      .L_0603913E
    bra     .L_0603915C
    nop
.L_0603916C:
    mov r14, r12
    mov.l   .L_0603919C, r2
    mov.w   .L_06039190, r3
    mov.w @r2, r2
    extu.w r2, r2
    cmp/gt r3, r2
    bf/s    .L_060391A0
    add #0x10, r12
    mov #0x2E, r0
    mov.w @(r0, r15), r3
    mov.w r3, @r4
    mov #0x36, r0
    mov.w @(r0, r15), r3
    mov.w r3, @r5
    bra     .L_060391B8
    nop

    .global DAT_0603918c
DAT_0603918c:
    .2byte  0x00FD

    .global DAT_0603918e
DAT_0603918e:
    .2byte  0x00F7
.L_06039190:
    .2byte  0x0160
    .2byte  0xFFFF
.L_06039194:
    .4byte  vblank_color_apply
.L_06039198:
    .4byte  sym_060A3E48
.L_0603919C:
    .4byte  sym_060635AE
.L_060391A0:
    mov #0x2E, r0
    mov.w @(r0, r15), r2
    mov #0x36, r0
    extu.w r2, r2
    shll r2
    extu.w r2, r2
    mov.w r2, @r4
    mov.w @(r0, r15), r3
    extu.w r3, r3
    shll r3
    extu.w r3, r3
    mov.w r3, @r5
.L_060391B8:
    mov #0x32, r0
    mov.w @(r0, r15), r0
    mov.w r0, @(2, r4)
    mov #0x3A, r0
    mov.w @(r0, r15), r0
    mov.w r0, @(2, r5)
    mov.l @(4, r15), r3
    or r13, r3
    tst r3, r3
    bt      .L_060391DC
    mov #0x7F, r3
    mov r12, r6
    mov r13, r5
    mov.l r3, @-r15
    mov.w   .L_0603923C, r7
    jsr @r11
    mov.l @(8, r15), r4
    add #0x4, r15
.L_060391DC:
    mov.l @r15, r3
    or r13, r3
    tst r3, r3
    bt      .L_060391F2
    mov r9, r7
    mov r12, r6
    mov r13, r5
    mov.l r10, @-r15
    jsr @r11
    mov.l @(4, r15), r4
    add #0x4, r15
.L_060391F2:
    mov r12, r6
    mov #-0x1, r5
    mov.l r8, @-r15
    mov.b @(12, r15), r0
    mov r0, r7
    jsr @r11
    mov r13, r4
    mov.l   .L_06039240, r4
    mov.l   .L_06039244, r3
    and r3, r13
    tst r13, r13
    bt/s    .L_06039214
    add #0x4, r15
    mov #0x3, r3
    mov.w r3, @r4
    bra     .L_0603921A
    nop
.L_06039214:
    mov.l   .L_06039248, r2
    mov.w @r2, r2
    mov.w r2, @r4
.L_0603921A:
    mov.l   .L_0603924C, r4
    mov.w @r4, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_06039228
    mov #0x1, r3
    mov.w r3, @r4
.L_06039228:
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
.L_0603923C:
    .2byte  0x0080
    .2byte  0xFFFF
.L_06039240:
    .4byte  sym_060A3E38
.L_06039244:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) / bit 16 mask */
.L_06039248:
    .4byte  sym_060A4C80
.L_0603924C:
    .4byte  sym_060635AC
