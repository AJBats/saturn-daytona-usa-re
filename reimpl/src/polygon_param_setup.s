
    .section .text.FUN_06039250


    .global vdp2_scroll_update
    .type vdp2_scroll_update, @function
vdp2_scroll_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r4, r14
    stc sr, r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov r0, r13
    stc sr, r0
    mov.w   DAT_060392e6, r3
    and r3, r0
    or #0xF0, r0
    ldc r0, sr
    bsr     .L_060394F0
    mov #0x0, r4
    mov #0x0, r6
    mov #0x0, r5
    bsr     polygon_param_setup
    mov #0x0, r4
    mov.l   .L_060392EC, r2
    mov #0x0, r6
    mov.l   .L_060392F0, r3
    mov.w @r2, r2
    mov.w r2, @r3
    mov #0x2, r2
    mov.l   .L_060392F4, r3
    mov.w r2, @r3
    mov.l   .L_060392F8, r2
    mov.l   .L_060392FC, r3
    mov.w r2, @r3
    mov #0x0, r2
    mov.l   .L_06039300, r3
    mov.w r2, @r3
    mov.l   .L_06039304, r2
    mov.l   .L_06039308, r3
    mov.w r2, @r3
    mov.l   .L_0603930C, r2
    mov.l @r2, r2
    add #-0x1, r2
    extu.w r2, r2
    mov.l r2, @-r15
    mov.l   .L_06039310, r7
    mov.l   .L_060392F8, r4
    mov.l @r7, r7
    add #-0x1, r7
    extu.w r7, r7
    bsr     sym_060393FC
    mov #0x0, r5
    add #0x4, r15
    mov.l   .L_06039314, r2
    mov.l r2, @r14
    mov r2, r3
    mov.w   .L_060392E8, r2
    mov.b r2, @r3
    mov.l @r14, r3
    add #0x1, r3
    mov #0x0, r2
    mov.b r2, @r3
    mov r13, r0
    and #0xF, r0
    shll2 r0
    shll2 r0
    stc sr, r3
    mov.w   DAT_060392e6, r2
    and r2, r3
    or r3, r0
    ldc r0, sr
    mov #0x1, r3
    mov.l   .L_06039318, r2
    mov.l r3, @r2
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_060392e6
DAT_060392e6:
    .2byte  0xFF0F
.L_060392E8:
    .2byte  0x0080
    .2byte  0xFFFF
.L_060392EC:
    .4byte  sym_060A4C92
.L_060392F0:
    .4byte  0x25D00002
.L_060392F4:
    .4byte  0x25D00004
.L_060392F8:
    .4byte  0x00008000
.L_060392FC:
    .4byte  0x25D00006
.L_06039300:
    .4byte  0x25D00008
.L_06039304:
    .4byte  0x0000FFFF
.L_06039308:
    .4byte  0x25D0000A
.L_0603930C:
    .4byte  sym_060A4C8C
.L_06039310:
    .4byte  sym_060A4C88
.L_06039314:
    .4byte  0x25C00000
.L_06039318:
    .4byte  sym_060635CC

    .global polygon_param_setup
    .type polygon_param_setup, @function
polygon_param_setup:
    mov.l r14, @-r15
    extu.w r4, r1
    mov #0x7, r3
    mov.l   .L_06039398, r14
    mov.l   .L_0603939C, r2
    and r1, r3
    mov.w r3, @r2
    mov.l   .L_060393A0, r2
    mov.w r3, @r2
    extu.w r5, r3
    mov #0x7, r2
    cmp/gt r2, r3
    bf/s    .L_0603933A
    mov #0x0, r7
    extu.w r7, r5
.L_0603933A:
    extu.w r5, r4
    mov.l   .L_060393A4, r3
    shll2 r4
    add r3, r4
    mov.w @r4, r2
    mov.l   .L_060393A8, r3
    mov.l r2, @r3
    mov.w @(2, r4), r0
    mov r0, r2
    mov.l r0, @r14
    extu.w r6, r0
    cmp/eq #0x1, r0
    bf      .L_0603935A
    mov.l @r14, r2
    shll r2
    mov.l r2, @r14
.L_0603935A:
    mov r1, r0
    cmp/eq #0x1, r0
    bt      .L_06039366
    mov r1, r0
    cmp/eq #0x3, r0
    bf      .L_06039370
.L_06039366:
    mov #0x1, r3
    mov.l   .L_060393AC, r2
    mov.w r3, @r2
    bra     .L_06039376
    nop
.L_06039370:
    extu.w r7, r2
    mov.l   .L_060393AC, r3
    mov.w r2, @r3
.L_06039376:
    extu.w r6, r6
    tst r6, r6
    bt      .L_06039386
    mov #0x8, r3
    mov.l   .L_060393B0, r2
    mov.w r3, @r2
    bra     .L_0603938C
    nop
.L_06039386:
    extu.w r7, r2
    mov.l   .L_060393B0, r3
    mov.w r2, @r3
.L_0603938C:
    extu.w r7, r2
    mov.l   .L_060393B4, r3
    mov.w r2, @r3
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_06039398:
    .4byte  sym_060A4C8C
.L_0603939C:
    .4byte  sym_060A4C90
.L_060393A0:
    .4byte  0x25D00000
.L_060393A4:
    .4byte  sym_060635E0
.L_060393A8:
    .4byte  sym_060A4C88
.L_060393AC:
    .4byte  sym_060635DE
.L_060393B0:
    .4byte  sym_060A4C94
.L_060393B4:
    .4byte  sym_060A4C96
    .4byte  0xD31C6331
    .4byte  0x2431D21C
    .4byte  0x6222622D
    .4byte  0x60238141
    .4byte  0xD31A6332
    .4byte  0x633D6033
    .4byte  0x8142D319
    .4byte  0x63316033
    .4byte  0x8143D318
    .4byte  0x63316033
    .4byte  0x8144D317
    .4byte  0x63316033
    .4byte  0x8145D316
    .4byte  0x63316033
    .4byte  0x8146D315
    .4byte  0x63316033
    .4byte  0x000B8147

    .global sym_060393FC
sym_060393FC:
    mov.w @(2, r15), r0
    mov.l   .L_06039438, r3
    mov r0, r1
    mov.w r4, @r3
    mov.l   .L_0603943C, r3
    mov.w r5, @r3
    mov.l   .L_06039440, r3
    mov.w r6, @r3
    mov.l   .L_06039444, r3
    mov.w r7, @r3
    mov.l   .L_06039448, r3
    mov.w r1, @r3
    mov.l   .L_0603944C, r3
    mov.w r4, @r3
    mov.l   .L_06039450, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06039454
    extu.w r5, r5
    shlr2 r5
    bra     .L_0603945A
    shlr2 r5
    .2byte  0xFFFF
    .4byte  sym_060635B4
    .4byte  sym_060635B8               /* framebuffer swap enable (unreferenced pool) */
    .4byte  sym_060635BC               /* framebuffer swap delay (unreferenced pool) */
.L_06039438:
    .4byte  sym_060635D4
.L_0603943C:
    .4byte  sym_060635D6
.L_06039440:
    .4byte  sym_060635D8
.L_06039444:
    .4byte  sym_060635DA
.L_06039448:
    .4byte  sym_060635DC
.L_0603944C:
    .4byte  0x25D00006
.L_06039450:
    .4byte  sym_060635DE
.L_06039454:
    extu.w r5, r5
    shlr2 r5
    shlr r5
.L_0603945A:
    mov.l   .L_060394D4, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_06039468
    extu.w r6, r6
    shlr r6
.L_06039468:
    extu.w r5, r5
    extu.w r6, r6
    mov.l   .L_060394D8, r3
    shll8 r5
    shll r5
    add r6, r5
    extu.w r5, r5
    mov.w r5, @r3
    mov.l   .L_060394D8, r2
    mov.l   .L_060394DC, r3
    mov.w @r2, r2
    mov.w r2, @r3
    mov.l   .L_060394E0, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt/s    .L_06039494
    add #0x1, r7
    extu.w r7, r7
    shlr2 r7
    bra     .L_0603949A
    shlr2 r7
.L_06039494:
    extu.w r7, r7
    shlr2 r7
    shlr r7
.L_0603949A:
    mov.l   .L_060394D4, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_060394A8
    extu.w r1, r1
    shlr r1
.L_060394A8:
    extu.w r7, r7
    extu.w r1, r1
    mov.l   .L_060394E4, r3
    shll8 r7
    shll r7
    add r1, r7
    extu.w r7, r7
    mov.w r7, @r3
    mov.l   .L_060394E4, r2
    mov.l   .L_060394E8, r3
    mov.w @r2, r2
    rts
    mov.w r2, @r3

    .global sym_060394C2
sym_060394C2:
    mov.l   .L_060394EC, r5
    mov #0x2, r4
.L_060394C6:
    mov.w @r5, r2
    extu.w r2, r2
    and r4, r2
    tst r2, r2
    bt      .L_060394C6
    rts
    nop
.L_060394D4:
    .4byte  sym_060A4C94
.L_060394D8:
    .4byte  sym_060635D0
.L_060394DC:
    .4byte  0x25D00008
.L_060394E0:
    .4byte  sym_060635DE
.L_060394E4:
    .4byte  sym_060635D2
.L_060394E8:
    .4byte  0x25D0000A
.L_060394EC:
    .4byte  0x25D00010
.L_060394F0:
    tst r4, r4
    bt      .L_060394FE
    mov #0x10, r3
    mov.l   .L_06039508, r2
    mov.w r3, @r2
    bra     .L_06039504
    nop
.L_060394FE:
    mov #0x0, r2
    mov.l   .L_06039508, r3
    mov.w r2, @r3
.L_06039504:
    rts
    nop
.L_06039508:
    .4byte  sym_060A4C92
