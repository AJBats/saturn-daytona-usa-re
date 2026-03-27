
    .section .text.FUN_0601E37C


    .global FUN_0601E37C
    .type FUN_0601E37C, @function
FUN_0601E37C:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15

    mov.w   DAT_0601e444, r8
    mov #0x3, r9
    mov #0x0, r10
    mov #0x1, r11
    mov.l   .L_pool_0601E448, r14
    extu.w r10, r13
    bra     .L_0601E46C
    mov r13, r12

.L_0601E39C:
    extu.w r12, r2
    mov.l   .L_pool_0601E44C, r3
    shll2 r2
    add r3, r2
    mov.w @r2, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_0601E3B0
    bra     .L_0601E46A
    nop

.L_0601E3B0:
    extu.w r13, r2
    mov r12, r0
    shll2 r2
    shll2 r2
    shll r2
    add r14, r2
    mov.w r0, @(28, r2)
    bsr     FUN_0601E488
    mov r13, r4
    bra     .L_0601E404
    nop

.L_0601E3C6:
    extu.w r13, r4
    shll2 r4
    shll2 r4
    shll r4
    add r14, r4
    mov.w @(28, r4), r0
    mov r0, r4
    .reloc ., R_SH_IND12W, FUN_0601E6A4 - 4
    .2byte 0xB000    /* bsr FUN_0601E6A4 (linker-resolved) */
    extu.w r4, r4
    tst r0, r0
    bt      .L_0601E3F0
    extu.w r13, r3
    shll2 r3
    shll2 r3
    shll r3
    add r14, r3
    extu.b r8, r2
    mov #0x1F, r0
    mov.b r2, @(r0, r3)
    bra     .L_0601E410
    nop

.L_0601E3F0:
    extu.w r13, r2
    shll2 r2
    shll2 r2
    shll r2
    add r14, r2
    extu.b r11, r3
    mov #0x1F, r0
    mov.b r3, @(r0, r2)
    bra     .L_0601E410
    nop

.L_0601E404:
    cmp/eq #0x0, r0
    bt      .L_0601E410
    cmp/eq #0x1, r0
    bt      .L_0601E46A
    cmp/eq #0x2, r0
    bt      .L_0601E3C6

.L_0601E410:
    extu.w r13, r4
    mov.l   .L_pool_0601E450, r3
    mov.l   .L_pool_0601E454, r2
    shll2 r4
    mov.b @r3, r3
    shll2 r4
    extu.b r3, r3
    shll r4
    shll2 r3
    add r14, r4
    add r2, r3
    mov.l @(12, r4), r4
    mov.l @r3, r3
    add #0x20, r3
    cmp/hs r3, r4
    bt      .L_0601E458

    extu.w r13, r3
    shll2 r3
    shll2 r3
    shll r3
    add r14, r3
    extu.b r10, r2
    mov #0x1E, r0
    mov.b r2, @(r0, r3)
    bra     .L_0601E468
    nop

    .global DAT_0601e444
DAT_0601e444:
    .2byte  0x00FF
    .2byte  0xFFFF
.L_pool_0601E448:
    .4byte  sym_06087094
.L_pool_0601E44C:
    .4byte  sym_06087086
.L_pool_0601E450:
    .4byte  sym_060877D8
.L_pool_0601E454:
    .4byte  sym_0604A5C0

.L_0601E458:
    extu.w r13, r2
    shll2 r2
    shll2 r2
    shll r2
    add r14, r2
    extu.b r11, r3
    mov #0x1E, r0
    mov.b r3, @(r0, r2)

.L_0601E468:
    add #0x1, r13

.L_0601E46A:
    add #0x1, r12

.L_0601E46C:
    extu.w r12, r3
    cmp/ge r9, r3
    bf      .L_0601E39C

    mov.l   .L_pool_0601E518, r3
    mov.w r13, @r3
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0601E488
    .type FUN_0601E488, @function
FUN_0601E488:
    mov.l r14, @-r15
    mov #0x0, r5

    .global FUN_0601E48C
    .type FUN_0601E48C, @function
FUN_0601E48C:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w r4, @r15
    mov.l   .L_pool_0601E51C, r3
    mov.w @r15, r14
    mov.l @r3, r3
    extu.w r14, r14
    mov.l @(4, r3), r2
    shll2 r14
    mov.l   .L_pool_0601E520, r3
    shll2 r14
    shll r14
    add r3, r14
    mov.w @(28, r14), r0
    mov r0, r4
    jsr @r2
    extu.w r4, r4
    mov.l   .L_pool_0601E51C, r0
    mov.l @r0, r0
    mov.l @(12, r0), r0
    mov r14, r6
    mov.l   .L_pool_0601E524, r5
    mov.b @r5, r5
    extu.b r5, r5
    shll2 r5
    mov.l   .L_pool_0601E528, r3
    add r3, r5
    mov.l @r5, r5
    mov #0x1C, r4
    add r14, r4
    mov.w @r4, r4
    extu.w r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    jmp @r0
    mov.l @r15+, r14

    .global FUN_0601E4D4
    .type FUN_0601E4D4, @function
FUN_0601E4D4:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15

    mov #0x0, r8
    mov r15, r9
    add #0x8, r9
    mov.l   .L_0601E52C, r10
    mov r10, r13
    add #0x44, r13
    mov #0x1, r14
    mov r15, r3
    add #0x4, r3
    mov.l r3, @r15

    mov r3, r5
    mov r9, r4
    mov.b r8, @r5
    mov.b r8, @r4
    add #0x1, r5
    add #0x1, r4
    extu.b r8, r2
    mov.b r2, @r5
    mov.b r2, @r4
    add #0x1, r5
    add #0x1, r4
    mov.b r8, @r5
    mov.b r8, @r4
    bra     .L_0601E5C4
    mov r8, r12
.L_pool_0601E518:

.L_pool_0601E518:
    .4byte  sym_06087084
.L_pool_0601E51C:
    .4byte  sym_06000354
.L_pool_0601E520:
    .4byte  sym_06087094
.L_pool_0601E524:
    .4byte  sym_060877D8
.L_pool_0601E528:
    .4byte  sym_0604A5C0
.L_0601E52C:
    .4byte  0x2010001F

.L_0601E530:
    mov r12, r11
    shll2 r11
    shll2 r11
    shll r11
    mov.l   .L_pool_0601E600, r3
    add r3, r11

.L_0601E53C:
    mov.b @r13, r3
    extu.b r3, r3
    and r14, r3
    cmp/eq r14, r3
    bt      .L_0601E53C
    mov.b r14, @r13
    mov #0x1A, r2
    mov.b r2, @r10
.L_0601E54C:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E54C

    mov.l   .L_pool_0601E604, r3
    mov #0x0, r5
    mov.w @(28, r11), r0
    mov.l @r3, r3
    mov r0, r4
    mov.l @(4, r3), r2
    jsr @r2
    extu.w r4, r4

    mov.l   .L_pool_0601E608, r6
    mov.l   .L_pool_0601E60C, r5
    mov.l   .L_pool_0601E610, r2
    mov.w @(28, r11), r0
    mov.l @r6, r6
    mov.b @r5, r5
    extu.b r5, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll r3
    add r3, r5
    add r2, r5
    .reloc ., R_SH_IND12W, FUN_0601E764 - 4
    .2byte 0xB000    /* bsr FUN_0601E764 (linker-resolved) */
    mov r0, r4
    mov r0, r4

.L_0601E586:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E586
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    mov.b r3, @r10
.L_0601E598:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E598

    tst r4, r4
    bf      .L_0601E5AE
    mov r12, r3
    add r9, r3
    extu.b r14, r2
    mov.b r2, @r3

.L_0601E5AE:
    mov #0x1E, r0
    mov.b @(r0, r11), r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0601E5C2
    mov r15, r3
    add #0x4, r3
    add r12, r3
    extu.b r14, r2
    mov.b r2, @r3

.L_0601E5C2:
    add #0x1, r12

.L_0601E5C4:
    mov.l   .L_pool_0601E614, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/ge r3, r12
    bf      .L_0601E530

    mov r8, r4

.L_0601E5D0:
    mov r4, r3
    add r9, r3
    mov.b @r3, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0601E5E0
    bra     .L_0601E622
    extu.b r4, r0

.L_0601E5E0:
    add #0x1, r4
    mov #0x3, r3
    cmp/ge r3, r4
    bf      .L_0601E5D0

    mov r15, r6
    mov.l @r15, r4
    add #0x7, r6
    cmp/hs r6, r4
    bt/s    .L_0601E620
    mov #0x3, r5

.L_0601E5F4:
    mov.b @r4, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0601E618
    bra     .L_0601E622
    extu.b r5, r0

.L_pool_0601E600:
    .4byte  sym_06087094
.L_pool_0601E604:
    .4byte  sym_06000354
.L_pool_0601E608:
    .4byte  sym_0605E098
.L_pool_0601E60C:
    .4byte  sym_060877D8
.L_pool_0601E610:
    .4byte  sym_0604A57C
.L_pool_0601E614:
    .4byte  sym_06087084

.L_0601E618:
    add #0x1, r4
    cmp/hs r6, r4
    bf/s    .L_0601E5F4
    add #0x1, r5

.L_0601E620:
    mov #0x8, r0

.L_0601E622:
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


    .global FUN_0601E636
    .type FUN_0601E636, @function
FUN_0601E636:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_0601E694, r13
    mov #0x1, r14
.L_0601E640:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E640
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x1A, r3
    mov.l   .L_0601E698, r2
    mov.b r3, @r2
.L_0601E654:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E654
    mov.l   .L_0601E69C, r3
    mov.l   .L_0601E6A0, r7
    mov.l @r3, r3
    mov.l @(28, r3), r2
    jsr @r2
    mov #0x10, r6
    mov r0, r6
.L_0601E66C:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E66C
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    mov.l   .L_0601E698, r2
    mov.b r3, @r2
.L_0601E680:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E680
    mov r6, r0
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0601E694:
    .4byte  0x20100063
.L_0601E698:
    .4byte  0x2010001F
.L_0601E69C:
    .4byte  sym_06000354
.L_0601E6A0:
    .4byte  sym_060870F4
