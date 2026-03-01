
    .section .text.FUN_06022AE0


    .global render_obj_processor
    .type render_obj_processor, @function
render_obj_processor:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    add #-0x2C, r15
    mov #0x0, r7
    mov.w   .L_wpool_06022BBA, r6
    mov r15, r14
    add #0x24, r14
    mov r14, r3
    mov.l r3, @(20, r15)
    mov.w @r5, r2
    mov.w r2, @r3
    add #0x2, r3
    mov.l r3, @(12, r15)
    mov r5, r2
    add #0x2, r2
    mov.l r2, @(28, r15)
    mov.w @r2, r1
    mov.w r1, @r3
    mov r14, r3
    add #0x4, r3
    mov.l r3, @(8, r15)
    mov r5, r2
    add #0x4, r2
    mov.l r2, @(24, r15)
    mov.w @r2, r1
    mov.w r1, @r3
    add #0x6, r14
    mov.l r14, @(16, r15)
    mov r5, r3
    add #0x6, r3
    mov.l r3, @(32, r15)
    mov.w @r3, r2
    mov.w r2, @r14
    mov r4, r14
    add #0x8, r14
    mov r4, r9
    add #0xC, r9
    mov r4, r11
    add #0x4, r11
    mov r4, r8
    add #0x10, r8
    mov r4, r10
    add #0x14, r10
    mov r4, r12
    add #0x18, r12
    mov r4, r13
    add #0x1C, r13
.L_06022B48:
    mov.w @r5, r2
    extu.w r2, r2
    tst r2, r2
    bt      .L_06022B54
    bra     .L_06022C7E
    nop
.L_06022B54:
    mov.l @(12, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_06022BB0
    mov.l @r14, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r9, r2
    mov.l @r11, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r14
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r9
    mov.l @r14, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022BB0
    mov.l @r15, r2
    mov.w   .L_wpool_06022BBC, r3
    cmp/gt r3, r2
    bt      .L_06022BB0
    mov.l @r9, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022BB0
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022BBE, r3
    cmp/gt r3, r2
    bt      .L_06022BB0
    mov.l @(12, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022BB0:
    mov.l @(8, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bra     .L_06022BC0
    nop
.L_wpool_06022BBA:
    .2byte  0xFE6B
.L_wpool_06022BBC:
    .2byte  0x0195
.L_wpool_06022BBE:
    .2byte  0x0131
.L_06022BC0:
    bt      .L_06022C16
    mov.l @r8, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r10, r2
    mov.l @r11, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r8
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r10
    mov.l @r8, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022C16
    mov.l @r15, r2
    mov.w   .L_wpool_06022C7A, r3
    cmp/gt r3, r2
    bt      .L_06022C16
    mov.l @r10, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022C16
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022C7C, r3
    cmp/gt r3, r2
    bt      .L_06022C16
    mov.l @(8, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022C16:
    mov.l @(16, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bf      .L_06022C22
    bra     .L_06023014
    nop
.L_06022C22:
    mov.l @r12, r3
    mov.l @r4, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r13, r2
    mov.l @r11, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r12
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r13
    mov.l @r12, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022C76
    mov.l @r15, r2
    mov.w   .L_wpool_06022C7A, r3
    cmp/gt r3, r2
    bt      .L_06022C76
    mov.l @r13, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022C76
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022C7C, r3
    cmp/gt r3, r2
    bt      .L_06022C76
    mov.l @(16, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022C76:
    bra     .L_06023014
    nop
.L_wpool_06022C7A:
    .2byte  0x0195
.L_wpool_06022C7C:
    .2byte  0x0131
.L_06022C7E:
    mov.l @(28, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bt      .L_06022C8C
    bra     .L_06022DB4
    nop
.L_06022C8C:
    mov.l @(20, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_06022CE8
    mov.l @r4, r3
    mov.l @r14, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r11, r2
    mov.l @r9, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r4
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r11
    mov.l @r4, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022CE8
    mov.l @r15, r2
    mov.w   .L_wpool_06022D4E, r3
    cmp/gt r3, r2
    bt      .L_06022CE8
    mov.l @r11, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022CE8
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022D50, r3
    cmp/gt r3, r2
    bt      .L_06022CE8
    mov.l @(20, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022CE8:
    mov.l @(8, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bt      .L_06022D44
    mov.l @r8, r3
    mov.l @r14, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r10, r2
    mov.l @r9, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r8
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r10
    mov.l @r8, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022D44
    mov.l @r15, r2
    mov.w   .L_wpool_06022D4E, r3
    cmp/gt r3, r2
    bt      .L_06022D44
    mov.l @r10, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022D44
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022D50, r3
    cmp/gt r3, r2
    bt      .L_06022D44
    mov.l @(8, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022D44:
    mov.l @(16, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bra     .L_06022D52
    nop
.L_wpool_06022D4E:
    .2byte  0x0195
.L_wpool_06022D50:
    .2byte  0x0131
.L_06022D52:
    bf      .L_06022D58
    bra     .L_06023014
    nop
.L_06022D58:
    mov.l @r12, r3
    mov.l @r14, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r13, r2
    mov.l @r9, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r12
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r13
    mov.l @r12, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022DAC
    mov.l @r15, r2
    mov.w   .L_wpool_06022DB0, r3
    cmp/gt r3, r2
    bt      .L_06022DAC
    mov.l @r13, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022DAC
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022DB2, r3
    cmp/gt r3, r2
    bt      .L_06022DAC
    mov.l @(16, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022DAC:
    bra     .L_06023014
    nop
.L_wpool_06022DB0:
    .2byte  0x0195
.L_wpool_06022DB2:
    .2byte  0x0131
.L_06022DB4:
    mov.l @(24, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bt      .L_06022DC2
    bra     .L_06022EEA
    nop
.L_06022DC2:
    mov.l @(20, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_06022E1E
    mov.l @r4, r3
    mov.l @r8, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r11, r2
    mov.l @r10, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r4
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r11
    mov.l @r4, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022E1E
    mov.l @r15, r2
    mov.w   .L_wpool_06022E84, r3
    cmp/gt r3, r2
    bt      .L_06022E1E
    mov.l @r11, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022E1E
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022E86, r3
    cmp/gt r3, r2
    bt      .L_06022E1E
    mov.l @(20, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022E1E:
    mov.l @(12, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bt      .L_06022E7A
    mov.l @r14, r3
    mov.l @r8, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r9, r2
    mov.l @r10, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r14
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r9
    mov.l @r14, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022E7A
    mov.l @r15, r2
    mov.w   .L_wpool_06022E84, r3
    cmp/gt r3, r2
    bt      .L_06022E7A
    mov.l @r9, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022E7A
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022E86, r3
    cmp/gt r3, r2
    bt      .L_06022E7A
    mov.l @(12, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022E7A:
    mov.l @(16, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bra     .L_06022E88
    nop
.L_wpool_06022E84:
    .2byte  0x0195
.L_wpool_06022E86:
    .2byte  0x0131
.L_06022E88:
    bf      .L_06022E8E
    bra     .L_06023014
    nop
.L_06022E8E:
    mov.l @r12, r3
    mov.l @r8, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r13, r2
    mov.l @r10, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r12
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r13
    mov.l @r12, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022EE2
    mov.l @r15, r2
    mov.w   .L_wpool_06022EE6, r3
    cmp/gt r3, r2
    bt      .L_06022EE2
    mov.l @r13, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022EE2
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022EE8, r3
    cmp/gt r3, r2
    bt      .L_06022EE2
    mov.l @(16, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022EE2:
    bra     .L_06023014
    nop
.L_wpool_06022EE6:
    .2byte  0x0195
.L_wpool_06022EE8:
    .2byte  0x0131
.L_06022EEA:
    mov.l @(32, r15), r2
    mov.w @r2, r3
    extu.w r3, r3
    tst r3, r3
    bt      .L_06022EF8
    bra     .L_06023014
    nop
.L_06022EF8:
    mov.l @(20, r15), r3
    mov.w @r3, r0
    tst r0, r0
    bt      .L_06022F54
    mov.l @r4, r3
    mov.l @r12, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r11, r2
    mov.l @r13, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r4
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r11
    mov.l @r4, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022F54
    mov.l @r15, r2
    mov.w   .L_wpool_06022FBA, r3
    cmp/gt r3, r2
    bt      .L_06022F54
    mov.l @r11, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022F54
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022FBC, r3
    cmp/gt r3, r2
    bt      .L_06022F54
    mov.l @(20, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022F54:
    mov.l @(12, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bt      .L_06022FB0
    mov.l @r14, r3
    mov.l @r12, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @r15
    mov.l @r9, r2
    mov.l @r13, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @(4, r15)
    mov.l @r15, r1
    shar r1
    shar r1
    mov.l r1, @r14
    mov.l @(4, r15), r3
    shar r3
    shar r3
    mov.l r3, @r9
    mov.l @r14, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06022FB0
    mov.l @r15, r2
    mov.w   .L_wpool_06022FBA, r3
    cmp/gt r3, r2
    bt      .L_06022FB0
    mov.l @r9, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06022FB0
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_06022FBC, r3
    cmp/gt r3, r2
    bt      .L_06022FB0
    mov.l @(12, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06022FB0:
    mov.l @(8, r15), r2
    mov.w @r2, r0
    tst r0, r0
    bra     .L_06022FBE
    nop
.L_wpool_06022FBA:
    .2byte  0x0195
.L_wpool_06022FBC:
    .2byte  0x0131
.L_06022FBE:
    bt      .L_06023014
    mov.l @r8, r3
    mov.l @r12, r1
    mov r3, r2
    shll r3
    add r2, r3
    add r1, r3
    mov.l r3, @(4, r15)
    mov.l @r10, r2
    mov.l @r13, r0
    mov r2, r1
    shll r2
    add r1, r2
    add r0, r2
    mov.l r2, @r15
    mov.l @(4, r15), r1
    shar r1
    shar r1
    mov.l r1, @r8
    mov.l @r15, r3
    shar r3
    shar r3
    mov.l r3, @r10
    mov.l @r8, r3
    mov.l r3, @r15
    cmp/ge r6, r3
    bf      .L_06023014
    mov.l @r15, r2
    mov.w   .L_wpool_06023048, r3
    cmp/gt r3, r2
    bt      .L_06023014
    mov.l @r10, r2
    mov r2, r3
    cmp/ge r6, r3
    bf/s    .L_06023014
    mov.l r2, @r15
    mov.l @r15, r2
    mov.w   .L_wpool_0602304A, r3
    cmp/gt r3, r2
    bt      .L_06023014
    mov.l @(8, r15), r2
    exts.w r7, r3
    mov.w r3, @r2
.L_06023014:
    mov.l @(20, r15), r2
    mov.l @(8, r15), r1
    mov.w @r2, r3
    mov.l @(12, r15), r2
    mov.w @r2, r2
    or r2, r3
    mov.w @r1, r2
    or r2, r3
    mov.l @(16, r15), r1
    mov.w @r1, r2
    or r2, r3
    tst r3, r3
    bf      .L_06023032
    bra     .L_06023036
    nop
.L_06023032:
    bra     .L_06022B48
    nop
.L_06023036:
    add #0x2C, r15
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_06023048:
    .2byte  0x0195
.L_wpool_0602304A:
    .2byte  0x0131
