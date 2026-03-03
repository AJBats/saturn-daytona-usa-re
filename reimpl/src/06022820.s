
    .section .text.FUN_06022820


    .global render_list_builder
    .type render_list_builder, @function
render_list_builder:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    add #-0x2C, r15
    mov #0x0, r7
    mov.w   .L_060228D2, r6
    mov r15, r14
    add #0x24, r14
    mov r14, r3
    mov.l r3, @(28, r15)
    mov.w @r5, r2
    mov.w r2, @r3
    add #0x2, r3
    mov.l r3, @(12, r15)
    mov r5, r2
    add #0x2, r2
    mov.l r2, @(20, r15)
    mov.w @r2, r1
    mov.w r1, @r3
    mov r14, r3
    add #0x4, r3
    mov.l r3, @(24, r15)
    mov r5, r2
    add #0x4, r2
    mov.l r2, @(8, r15)
    mov.w @r2, r1
    mov.w r1, @r3
    add #0x6, r14
    mov.l r14, @(32, r15)
    mov r5, r3
    add #0x6, r3
    mov.l r3, @(16, r15)
    mov.w @r3, r2
    mov.w r2, @r14
    mov r4, r12
    add #0x4, r12
    mov r4, r3
    add #0x8, r3
    mov.l r3, @r15
    mov r4, r2
    add #0xC, r2
    mov r4, r10
    add #0x18, r10
    mov r4, r11
    add #0x1C, r11
    mov r2, r13
    mov r4, r8
    add #0x10, r8
    mov r4, r9
    add #0x14, r9
    mov.l r13, @(4, r15)
.L_0602288E:
    mov.w @r5, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06022910
    mov.l @(28, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_06022910
    mov.l @r4, r14
    mov.l @r12, r13
    mov r14, r3
    mov r13, r2
    shll r14
    shll r13
    add r3, r14
    mov.l @(20, r15), r3
    mov.w @r3, r3
    extu.w r3, r3
    tst r3, r3
    bf/s    .L_060228D4
    add r2, r13
    mov.l @r15, r3
    mov.l @(4, r15), r2
    mov.l @r3, r3
    add r3, r14
    mov.l @r2, r3
    shar r14
    add r3, r13
    shar r14
    shar r13
    mov.l r14, @r4
    shar r13
    bra     .L_060228F2
    mov.l r13, @r12
.L_060228D2:
    .2byte  0xFE6B
.L_060228D4:
    mov.l @(16, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_060228F2
    mov.l @r10, r3
    mov.l @r11, r2
    add r3, r14
    add r2, r13
    shar r14
    shar r13
    shar r14
    mov.l r14, @r4
    shar r13
    mov.l r13, @r12
.L_060228F2:
    mov.l @r4, r14
    cmp/ge r6, r14
    bf      .L_06022910
    mov.w   .L_0602295C, r2
    cmp/gt r2, r14
    bt      .L_06022910
    mov.l @r12, r14
    cmp/ge r6, r14
    bf      .L_06022910
    mov.w   .L_0602295E, r3
    cmp/gt r3, r14
    bt      .L_06022910
    mov.l @(28, r15), r3
    exts.w r7, r2
    mov.w r2, @r3
.L_06022910:
    mov.l @(20, r15), r3
    mov.w @r3, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_060229A2
    mov.l @(12, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_060229A2
    mov.l @r15, r14
    mov.l @(4, r15), r13
    mov.l @(8, r15), r2
    mov.l @r14, r14
    mov.l @r13, r13
    mov r14, r3
    shll r14
    add r3, r14
    mov r13, r3
    shll r13
    add r3, r13
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_06022960
    mov.l @r8, r3
    mov.l @r9, r2
    add r3, r14
    add r2, r13
    shar r14
    mov.l @r15, r3
    shar r13
    shar r14
    mov.l r14, @r3
    mov.l @(4, r15), r3
    shar r13
    mov.l r13, @r3
    bra     .L_06022980
    nop
.L_0602295C:
    .2byte  0x0195
.L_0602295E:
    .2byte  0x0131
.L_06022960:
    mov.w @r5, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_06022980
    mov.l @r4, r3
    mov.l @r12, r2
    add r3, r14
    add r2, r13
    shar r14
    mov.l @r15, r3
    shar r13
    shar r14
    mov.l r14, @r3
    mov.l @(4, r15), r3
    shar r13
    mov.l r13, @r3
.L_06022980:
    mov.l @r15, r14
    mov.l @r14, r14
    cmp/ge r6, r14
    bf      .L_060229A2
    mov.w   .L_060229E4, r2
    cmp/gt r2, r14
    bt      .L_060229A2
    mov.l @(4, r15), r14
    mov.l @r14, r14
    cmp/ge r6, r14
    bf      .L_060229A2
    mov.w   .L_060229E6, r2
    cmp/gt r2, r14
    bt      .L_060229A2
    mov.l @(12, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_060229A2:
    mov.l @(8, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06022A28
    mov.l @(24, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_06022A28
    mov.l @r8, r14
    mov.l @r9, r13
    mov r14, r3
    mov r13, r2
    shll r14
    shll r13
    add r3, r14
    mov.l @(16, r15), r3
    mov.w @r3, r3
    extu.w r3, r3
    tst r3, r3
    bf/s    .L_060229E8
    add r2, r13
    mov.l @r10, r3
    mov.l @r11, r2
    add r3, r14
    add r2, r13
    shar r14
    shar r13
    shar r14
    mov.l r14, @r8
    shar r13
    bra     .L_06022A0A
    mov.l r13, @r9
.L_060229E4:
    .2byte  0x0195
.L_060229E6:
    .2byte  0x0131
.L_060229E8:
    mov.l @(20, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_06022A0A
    mov.l @r15, r3
    mov.l @(4, r15), r2
    mov.l @r3, r3
    add r3, r14
    mov.l @r2, r3
    shar r14
    add r3, r13
    shar r14
    shar r13
    mov.l r14, @r8
    shar r13
    mov.l r13, @r9
.L_06022A0A:
    mov.l @r8, r14
    cmp/ge r6, r14
    bf      .L_06022A28
    mov.w   .L_06022A68, r3
    cmp/gt r3, r14
    bt      .L_06022A28
    mov.l @r9, r14
    cmp/ge r6, r14
    bf      .L_06022A28
    mov.w   .L_06022A6A, r2
    cmp/gt r2, r14
    bt      .L_06022A28
    mov.l @(24, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022A28:
    mov.l @(16, r15), r2
    mov.w @r2, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06022AA8
    mov.l @(32, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_06022AA8
    mov.l @r10, r13
    mov.l @r11, r14
    mov r13, r3
    mov r14, r2
    shll r13
    shll r14
    add r3, r13
    mov.w @r5, r3
    extu.w r3, r3
    tst r3, r3
    bf/s    .L_06022A6C
    add r2, r14
    mov.l @r4, r3
    mov.l @r12, r2
    add r3, r13
    add r2, r14
    shar r13
    shar r14
    shar r13
    mov.l r13, @r10
    shar r14
    bra     .L_06022A8A
    mov.l r14, @r11
.L_06022A68:
    .2byte  0x0195
.L_06022A6A:
    .2byte  0x0131
.L_06022A6C:
    mov.l @(8, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_06022A8A
    mov.l @r8, r3
    mov.l @r9, r2
    add r3, r13
    add r2, r14
    shar r13
    shar r14
    shar r13
    mov.l r13, @r10
    shar r14
    mov.l r14, @r11
.L_06022A8A:
    mov.l @r10, r14
    cmp/ge r6, r14
    bf      .L_06022AA8
    mov.w   .L_06022ADC, r2
    cmp/gt r2, r14
    bt      .L_06022AA8
    mov.l @r11, r14
    cmp/ge r6, r14
    bf      .L_06022AA8
    mov.w   .L_06022ADE, r3
    cmp/gt r3, r14
    bt      .L_06022AA8
    mov.l @(32, r15), r3
    exts.w r7, r2
    mov.w r2, @r3
.L_06022AA8:
    mov.l @(28, r15), r3
    mov.l @(12, r15), r2
    mov.l @(24, r15), r1
    mov.w @r3, r3
    mov.w @r2, r2
    or r2, r3
    mov.w @r1, r2
    or r2, r3
    mov.l @(32, r15), r1
    mov.w @r1, r2
    or r2, r3
    tst r3, r3
    bf      .L_06022AC6
    bra     .L_06022ACA
    nop
.L_06022AC6:
    bra     .L_0602288E
    nop
.L_06022ACA:
    add #0x2C, r15
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06022ADC:
    .2byte  0x0195
.L_06022ADE:
    .2byte  0x0131
