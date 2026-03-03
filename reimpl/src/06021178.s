	.text
    .global obj_overlay_render
obj_overlay_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov #0x1, r9
    mov.l   .L_060211DC, r14
    mov.l   .L_060211E0, r6
    mov.w   .L_060211D8, r0
    mov.l @r6, r4
    mov.l @r6, r5
    mov.l @r6, r3
    mov.l @(16, r4), r4
    mov.l @(r0, r3), r6
    mov.l   .L_060211E4, r3
    cmp/gt r3, r4
    bf.s    .L_060211F4
    mov.l @(24, r5), r5
    mov.l   .L_060211E8, r3
    cmp/ge r3, r4
    bt      .L_060211F4
    mov.l   .L_060211EC, r3
    cmp/ge r3, r5
    bt      .L_060211F4
    mov.l   .L_060211F0, r3
    cmp/gt r3, r5
    bf      .L_060211F4
    mov #0x57, r3
    cmp/gt r3, r6
    bf      .L_06021248
    mov #0x7A, r3
    cmp/ge r3, r6
    bt      .L_06021248
    mov.w @r14, r3
    extu.w r3, r3
    and r9, r3
    tst r3, r3
    bf      .L_060211D4
    mov.w @r14, r0
    or #0x1, r0
    mov.w r0, @r14
    mov.w @r14, r0
    or #0x2, r0
    mov.w r0, @r14
.L_060211D4:
    bra     .L_06021248
    nop
.L_060211D8:
    .short  0x01EC
    .short  0xFFFF
.L_060211DC:
    .long  sym_0608959C
.L_060211E0:
    .long  sym_0607E940
.L_060211E4:
    .long  0x00760000
.L_060211E8:
    .long  0x014B0000
.L_060211EC:
    .long  0x00D00000
.L_060211F0:
    .long  0xFF3B0000
.L_060211F4:
    mov.l   .L_060212E0, r2
    cmp/ge r2, r4
    bt      .L_06021200
    mov.l   .L_060212E4, r2
    cmp/ge r2, r5
    bf      .L_06021218
.L_06021200:
    mov.l   .L_060212E8, r2
    cmp/ge r2, r4
    bt      .L_0602120C
    mov.l   .L_060212EC, r2
    cmp/ge r2, r5
    bf      .L_06021218
.L_0602120C:
    mov.l   .L_060212F0, r2
    cmp/ge r2, r4
    bt      .L_06021230
    mov.l   .L_060212F4, r2
    cmp/ge r2, r5
    bt      .L_06021230
.L_06021218:
    mov.w @r14, r2
    extu.w r2, r2
    and r9, r2
    tst r2, r2
    bf      .L_06021248
    mov.w @r14, r0
    or #0x1, r0
    mov.w r0, @r14
    mov.w @r14, r0
    or #0x2, r0
    bra     .L_06021248
    mov.w r0, @r14
.L_06021230:
    mov.w @r14, r2
    extu.w r2, r2
    and r9, r2
    tst r2, r2
    bt      .L_06021248
    mov #-0x2, r3
    mov.w @r14, r2
    and r3, r2
    mov.w r2, @r14
    mov.w @r14, r0
    or #0x2, r0
    mov.w r0, @r14
.L_06021248:
    mov.w @r14, r0
    extu.w r0, r0
    shlr r0
    tst #0x1, r0
    bf      .L_06021256
    bra     .L_06021404
    nop
.L_06021256:
    mov.w   .L_060212D4, r10
    mov.l   .L_060212F8, r11
    mov.l   .L_060212FC, r12
    mov.l   .L_06021300, r13
    mov.w @r14, r3
    extu.w r3, r3
    and r9, r3
    tst r3, r3
    bt      .L_0602135A
    mov.l   .L_06021304, r3
    jsr @r3
    nop
    mov.w   .L_060212D6, r6
    mov.l   .L_06021308, r5
    mov.l @r12, r4
    mov.l @r11, r3
    shll2 r4
    shll r4
    jsr @r13
    add r3, r4
    mov.w   DAT_060212d8, r6
    mov.l   .L_0602130C, r5
    mov.l @r12, r4
    mov.l @r11, r3
    mov.w   .L_060212DA, r2
    shll2 r4
    shll r4
    add r3, r4
    jsr @r13
    add r2, r4
    mov.l   .L_06021310, r3
    mov.b @r3, r3
    tst r3, r3
    bf      .L_06021320
    mov r10, r6
    mov.l   .L_06021314, r5
    mov.l   .L_06021318, r3
    mov.l @r12, r4
    mov.l @r11, r2
    mov.l @r5, r5
    shll2 r4
    shll2 r5
    shll r4
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r13
    add #0x40, r4
    mov r10, r6
    mov.l   .L_0602131C, r5
    mov.l   .L_06021318, r3
    mov.l @r12, r4
    mov.b @r5, r5
    shll2 r4
    extu.b r5, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    shll r4
    mov.l @r11, r2
    mov.w   .L_060212DC, r1
    bra     .L_06021352
    add r2, r4
.L_060212D4:
    .short  0x00C0
.L_060212D6:
    .short  0x0200

    .global DAT_060212d8
DAT_060212d8:
    .short  0x17C0
.L_060212DA:
    .short  0x03C0
.L_060212DC:
    .short  0x0100
    .short  0xFFFF
.L_060212E0:
    .long  0xFE9A0000
.L_060212E4:
    .long  0xFDCD0000
.L_060212E8:
    .long  0xFE950000
.L_060212EC:
    .long  0xFDD30000
.L_060212F0:
    .long  0xFE8F0000
.L_060212F4:
    .long  0xFDD80000
.L_060212F8:
    .long  sym_06063F5C
.L_060212FC:
    .long  sym_06059FFC
.L_06021300:
    .long  dma_transfer
.L_06021304:
    .long  sym_060039F2
.L_06021308:
    .long  sym_0604D608
.L_0602130C:
    .long  sym_0604EFC8
.L_06021310:
    .long  sym_06083255
.L_06021314:
    .long  sym_06078868
.L_06021318:
    .long  sym_0605D084
.L_0602131C:
    .long  sym_0607ED91
.L_06021320:
    mov #0x20, r6
    mov.l   .L_0602141C, r5
    mov.l   .L_06021420, r3
    mov.l   .L_06021424, r4
    mov.l   .L_06021428, r2
    mov.l   .L_0602142C, r1
    mov.l @r12, r0
    mov.l @r5, r5
    mov.l @r4, r4
    mov.w @r1, r1
    shll2 r0
    shll2 r5
    add r2, r4
    extu.w r1, r1
    add r3, r5
    mov.b @r4, r4
    mov.l @r5, r5
    extu.b r4, r4
    add r1, r4
    shll2 r4
    shll2 r4
    shll r4
    shll r0
    add r0, r4
    mov.l @r11, r1
.L_06021352:
    jsr @r13
    add r1, r4
    bra     .L_060213FC
    nop
.L_0602135A:
    mov.l   .L_06021430, r3
    jsr @r3
    nop
    mov.w   .L_06021414, r6
    mov.l   .L_06021434, r5
    mov.l @r12, r4
    mov.l @r11, r3
    shll2 r4
    shll r4
    jsr @r13
    add r3, r4
    mov.w   DAT_06021416, r6
    mov.l   .L_06021438, r5
    mov.l @r12, r4
    mov.l @r11, r3
    mov.w   .L_06021418, r2
    shll2 r4
    shll r4
    add r3, r4
    jsr @r13
    add r2, r4
    mov.l   .L_0602143C, r3
    mov.b @r3, r3
    tst r3, r3
    bf      .L_060213C6
    mov r10, r6
    mov.l   .L_06021440, r5
    mov.l   .L_06021444, r3
    mov.l @r12, r4
    mov.l @r11, r2
    mov.l @r5, r5
    shll2 r4
    shll2 r5
    shll r4
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r13
    add #0x40, r4
    mov r10, r6
    mov.l   .L_06021448, r5
    mov.l   .L_06021444, r3
    mov.l @r12, r4
    mov.b @r5, r5
    shll2 r4
    extu.b r5, r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    shll r4
    mov.l @r11, r2
    mov.w   .L_0602141A, r1
    bra     .L_060213F8
    add r2, r4
.L_060213C6:
    mov #0x20, r6
    mov.l   .L_0602141C, r5
    mov.l   .L_0602144C, r3
    mov.l   .L_06021424, r4
    mov.l   .L_06021428, r2
    mov.l   .L_0602142C, r1
    mov.l @r12, r0
    mov.l @r5, r5
    mov.l @r4, r4
    mov.w @r1, r1
    shll2 r0
    shll2 r5
    add r2, r4
    extu.w r1, r1
    add r3, r5
    mov.b @r4, r4
    mov.l @r5, r5
    extu.b r4, r4
    add r1, r4
    shll2 r4
    shll2 r4
    shll r4
    shll r0
    add r0, r4
    mov.l @r11, r1
.L_060213F8:
    jsr @r13
    add r1, r4
.L_060213FC:
    mov #-0x3, r3
    mov.w @r14, r2
    and r3, r2
    mov.w r2, @r14
.L_06021404:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06021414:
    .short  0x0200

    .global DAT_06021416
DAT_06021416:
    .short  0x17C0
.L_06021418:
    .short  0x03C0
.L_0602141A:
    .short  0x0100
.L_0602141C:
    .long  sym_0607EAB8
.L_06021420:
    .long  sym_0605D0B4
.L_06021424:
    .long  sym_0607EAD8
.L_06021428:
    .long  sym_060448B5
.L_0602142C:
    .long  sym_0607886C
.L_06021430:
    .long  dma_config_dispatch
.L_06021434:
    .long  sym_0604D408
.L_06021438:
    .long  sym_0604D808
.L_0602143C:
    .long  sym_06083255
.L_06021440:
    .long  sym_06078868
.L_06021444:
    .long  sym_0605D05C
.L_06021448:
    .long  sym_0607ED91
.L_0602144C:
    .long  sym_0605D0AC
