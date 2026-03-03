	.text
    .global vdp1_init
vdp1_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x0, r14

    mov.l   .L_pool_0600A19C, r3
    mov.l   .L_pool_0600A1A0, r2
    mov.l r3, @r2

    mov.l   .L_pool_0600A1A4, r5
    mov.l   .L_pool_0600A1A8, r4
.L_0600A150:
    mov r5, r3
    add #-0x2, r4
    add #0x4, r5
    mov.l r14, @r3
    mov r5, r2
    add #0x4, r5
    tst r4, r4
    bf.s    .L_0600A150
    mov.l r14, @r2

    mov.l   .L_pool_0600A1AC, r3
    mov.l r14, @r3
    mov.l   .L_pool_0600A1B0, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600A1B4, r3
    mov.l r14, @r3

    mov.l   .L_pool_0600A1A4, r5
    mov.l   .L_pool_0600A1A8, r4
.L_0600A174:
    mov r5, r2
    add #-0x2, r4
    add #0x4, r5
    mov.l r14, @r2
    mov r5, r3
    add #0x4, r5
    tst r4, r4
    bf.s    .L_0600A174
    mov.l r14, @r3

    mov.l   .L_pool_0600A1AC, r3
    mov.l r14, @r3
    mov.l   .L_pool_0600A1B0, r3
    jsr @r3
    nop
    mov.l   .L_pool_0600A1B4, r3
    mov.l r14, @r3

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .short  0xFFFF

.L_pool_0600A19C:
    .long  0x80000000
.L_pool_0600A1A0:
    .long  0x25C00000
.L_pool_0600A1A4:
    .long  0x25C80000
.L_pool_0600A1A8:
    .long  0x00010000
.L_pool_0600A1AC:
    .long  sym_0605A00C
.L_pool_0600A1B0:
    .long  sym_06026CE0
.L_pool_0600A1B4:
    .long  sym_06059F44
    .long  0xD01B6000
    .long  0x600C2008
    .long  0x8B08D01A
    .long  0x6001600D
    .long  0x20088B12
    .long  0xD0186002
    .long  0x20088B0E
    .long  0xD417D318
    .long  0x6331633C
    .long  0x2430D217
    .long  0x6222622C
    .long  0x60238041
    .long  0xD3156332
    .long  0x633C6033
    .long  0x8042000B
    .short  0x0009

    .global sym_0600A1F6
sym_0600A1F6:
    mov #0x3, r7
    mov.l   .L_pool_0600A244, r5
    mov.l   .L_pool_0600A248, r4
    mov.l   .L_pool_0600A24C, r0
    mov.l @r0, r0
    tst r0, r0
    bf.s    .L_0600A250
    mov #0x4, r6

    mov.l @r5, r3
    mov.w   DAT_0600a224, r2
    cmp/eq r2, r3
    bf      .L_0600A214
    exts.w r7, r7
    bra     .L_0600A290
    mov.w r7, @r4
.L_0600A214:
    mov.l @r5, r2
    mov.w   .L_wpool_0600A226, r3
    cmp/eq r3, r2
    bf      .L_0600A220
    exts.w r6, r6
    mov.w r6, @r4
.L_0600A220:
    bra     .L_0600A290
    nop

    .global DAT_0600a224
DAT_0600a224:
    .short  0x00C4
.L_wpool_0600A226:
    .short  0x00A8
    .long  sym_06078635
    .long  sym_0607ED8C
    .long  sym_0605AD00
    .long  sym_0607ED90
    .long  sym_06063F44
    .long  sym_06078868
    .long  sym_0607EAB8
.L_pool_0600A244:
    .long  sym_0607EBCC
.L_pool_0600A248:
    .long  sym_0605A016
.L_pool_0600A24C:
    .long  sym_0607EAD8
.L_0600A250:
    mov.l   .L_pool_0600A2E8, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0600A276

    mov.l @r5, r3
    mov.w   DAT_0600a2d8, r2
    cmp/eq r2, r3
    bf      .L_0600A266
    exts.w r7, r7
    bra     .L_0600A290
    mov.w r7, @r4
.L_0600A266:
    mov.l @r5, r2
    mov.w   .L_wpool_0600A2DA, r3
    cmp/eq r3, r2
    bf      .L_0600A272
    exts.w r6, r6
    mov.w r6, @r4
.L_0600A272:
    bra     .L_0600A290
    nop

.L_0600A276:
    mov.l @r5, r2
    mov.w   DAT_0600a2dc, r3
    cmp/eq r3, r2
    bf      .L_0600A284
    exts.w r7, r7
    bra     .L_0600A290
    mov.w r7, @r4
.L_0600A284:
    mov.l @r5, r2
    mov.w   .L_wpool_0600A2DE, r3
    cmp/eq r3, r2
    bf      .L_0600A290
    exts.w r6, r6
    mov.w r6, @r4
.L_0600A290:
    rts
    nop
    .long  0xE703D515
    .long  0xD415D013
    .long  0x60028801
    .long  0x8F0FE604
    .long  0x6252931B
    .long  0x32308B02
    .long  0x677FA043
    .long  0x24716252
    .long  0x93153230
    .long  0x8B01666F
    .long  0x2461A03B
    .long  0x0009D009
    .long  0x60028802
    .long  0x8B366352
    .long  0x920A3320
    .long  0x8B10677F
    .long  0xA0302471

    .global DAT_0600a2d8
DAT_0600a2d8:
    .short  0x0287
.L_wpool_0600A2DA:
    .short  0x0271

    .global DAT_0600a2dc
DAT_0600a2dc:
    .short  0x01AE
.L_wpool_0600A2DE:
    .short  0x0190
    .long  0x03710352
    .long  0x03ABFFFF
.L_pool_0600A2E8:
    .long  sym_0607EAD8
    .long  sym_0607EBCC
    .long  sym_0605A016
    .long  0x62529338
    .long  0x32308B02
    .long  0x666FA01B
    .long  0x24616252
    .long  0x93323230
    .long  0x8B02677F
    .long  0xA0142471
    .long  0x6252932C
    .long  0x32308B02
    .long  0x666FA00D
    .long  0x24616252
    .long  0x93263230
    .long  0x8B02677F
    .long  0xA0062471
    .long  0x62529320
    .long  0x32308B01
    .long  0x666F2461
    .long  0x000B0009

    .global sym_0600A33C
sym_0600A33C:
    mov.l   .L_pool_0600A374, r5
    mov.l   .L_pool_0600A378, r4
    mov.l @r4, r0
    tst r0, r0
    bf      .L_0600A34E
    mov #0x5, r3
    mov.w r3, @r5
    bra     .L_0600A386
    nop
.L_0600A34E:
    mov.l @r4, r0
    cmp/eq #0x1, r0
    bf      .L_0600A35C
    mov #0x6, r3
    mov.w r3, @r5
    bra     .L_0600A386
    nop
.L_0600A35C:
    mov.l @r4, r0
    cmp/eq #0x2, r0
    bf      .L_0600A37C
    mov #0x7, r3
    mov.w r3, @r5
    bra     .L_0600A386
    nop
    .short  0x0398

    .global DAT_0600a36c
DAT_0600a36c:
    .short  0x036D

    .global DAT_0600a36e
DAT_0600a36e:
    .short  0x0336

    .global DAT_0600a370
DAT_0600a370:
    .short  0x021A

    .global DAT_0600a372
DAT_0600a372:
    .short  0x01B4
.L_pool_0600A374:
    .long  sym_0605A016
.L_pool_0600A378:
    .long  sym_06063E1C
.L_0600A37C:
    mov.l @r4, r0
    cmp/eq #0x3, r0
    bf      .L_0600A386
    mov #0x8, r3
    mov.w r3, @r5
.L_0600A386:
    rts
    nop
    .short  0xE300
    .long  0xD213000B
    .short  0x2232
