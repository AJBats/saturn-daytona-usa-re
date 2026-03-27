
    .section .text.FUN_0600B340


    .global FUN_0600B340
    .type FUN_0600B340, @function
FUN_0600B340:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_0600B378, r11
    mov.l @r11, r11
    mov.l   .L_0600B37C, r14
    mov.l @r14, r14
    mov.l   .L_0600B380, r3
    mov.l r14, @r3
    mov.l   .L_0600B384, r0
    bra     .L_0600B3A0
    mov.l @r0, r0
.L_0600B35E:
    mov.l   .L_0600B388, r13
    mov.l   .L_0600B38C, r12
    bra     .L_0600B3AC
    nop
.L_0600B366:
    mov.l   .L_0600B390, r13
    mov.l   .L_0600B394, r12
    bra     .L_0600B3AC
    nop
.L_0600B36E:
    mov.l   .L_0600B398, r13
    mov.l   .L_0600B39C, r12
    bra     .L_0600B3AC
    nop
    .2byte  0xFFFF
.L_0600B378:
    .4byte  sym_0607EB8C
.L_0600B37C:
    .4byte  sym_0607E944
.L_0600B380:
    .4byte  sym_0607E940
.L_0600B384:
    .4byte  sym_0607EAD8
.L_0600B388:
    .4byte  sym_06063488
.L_0600B38C:
    .4byte  sym_06063434
.L_0600B390:
    .4byte  sym_060634A4
.L_0600B394:
    .4byte  sym_06063450
.L_0600B398:
    .4byte  sym_060634C0
.L_0600B39C:
    .4byte  sym_0606346C
.L_0600B3A0:
    cmp/eq #0x0, r0
    bt      .L_0600B35E
    cmp/eq #0x1, r0
    bt      .L_0600B366
    cmp/eq #0x2, r0
    bt      .L_0600B36E
.L_0600B3AC:
    mov.l   .L_0600B484, r3
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.l   .L_0600B488, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov.l   .L_0600B48C, r3
    jsr @r3
    mov.l @(32, r14), r4
    mov.l   .L_0600B490, r3
    jsr @r3
    mov.l @(36, r14), r4
    mov.l   .L_0600B494, r3
    jsr @r3
    mov.l @(28, r14), r4
    mov.w   DAT_0600b47a, r0
    mov.l   .L_0600B48C, r3
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r2
    jsr @r3
    add r2, r4
    mov.l   .L_0600B498, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600B45A
    mov.l   .L_0600B49C, r5
    mov.l   .L_0600B4A0, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(24, r13), r4
    mov.l   .L_0600B4A4, r6
    mov.l   .L_0600B4A8, r2
    mov.l @r6, r6
    mov r2, r5
    mov.l r2, @(4, r15)
    mov.w @r5, r5
    mov.l   .L_0600B4AC, r3
    extu.w r5, r5
    jsr @r3
    mov.l @(24, r12), r4
    mov #0x0, r6
    mov.w   DAT_0600b47c, r0
    mov.l   .L_0600B488, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   DAT_0600b47e, r0
    mov.l   .L_0600B490, r3
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   .L_0600B480, r0
    mov.l   .L_0600B4B0, r2
    mov.l   .L_0600B494, r3
    mov.l @(r0, r14), r4
    mov.l @r2, r2
    jsr @r3
    add r2, r4
    mov.l @(12, r11), r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0600B4B4, r3
    mov.l @r15, r4
    mov.l   .L_0600B4A0, r2
    add r3, r5
    add r13, r4
    mov.l @r5, r5
    jsr @r2
    mov.l @r4, r4
    mov.l @(12, r11), r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0600B4B8, r3
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l   .L_0600B4AC, r2
    add r3, r6
    mov.w @r5, r5
    add r12, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r2
    mov.l @r4, r4
    .reloc ., R_SH_IND12W, FUN_0600A76C - 4
    .2byte 0xB000    /* bsr FUN_0600A76C (linker-resolved) */
    nop
.L_0600B45A:
    mov.l   .L_0600B4BC, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    mov.l   .L_0600B4C0, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0600B4C4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     FUN_0600B4D2
    mov.l @r15+, r14

    .global DAT_0600b47a
DAT_0600b47a:
    .2byte  0x01D8

    .global DAT_0600b47c
DAT_0600b47c:
    .2byte  0x01B4

    .global DAT_0600b47e
DAT_0600b47e:
    .2byte  0x01D0
.L_0600B480:
    .2byte  0x01C8
    .2byte  0xFFFF
.L_0600B484:
    .4byte  sym_06027080
.L_0600B488:
    .4byte  sym_060270F2
.L_0600B48C:
    .4byte  FUN_060271A2
.L_0600B490:
    .4byte  FUN_060271EE
.L_0600B494:
    .4byte  FUN_06027158
.L_0600B498:
    .4byte  sym_06059F30
.L_0600B49C:
    .4byte  sym_06063510
.L_0600B4A0:
    .4byte  sym_06032158
.L_0600B4A4:
    .4byte  sym_060634F4
.L_0600B4A8:
    .4byte  sym_06089E98
.L_0600B4AC:
    .4byte  sym_06031DF4
.L_0600B4B0:
    .4byte  sym_06083258
.L_0600B4B4:
    .4byte  sym_060634F8
.L_0600B4B8:
    .4byte  sym_060634DC
.L_0600B4BC:
    .4byte  sym_0608A52C
.L_0600B4C0:
    .4byte  sym_0607867C
.L_0600B4C4:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0600B4D2
    .type FUN_0600B4D2, @function
FUN_0600B4D2:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_pool_0600B516, r10
    mov.l @r10, r10
    mov.l   .L_pool_0600B51A, r14
    mov.l @r14, r14
    mov.l   .L_pool_0600B51E, r3
    mov.l r14, @r3
    mov.l   .L_pool_0600B522, r0
    bra     .L_0600B534
    mov.l @r0, r0
.L_0600B4F4:
    mov.l   .L_pool_0600B526, r12
    mov.l   .L_pool_0600B52A, r11
    bra     .L_0600B540
    nop
.L_0600B4FC:
    mov.l   .L_pool_0600B52E, r12
    mov.l   .L_pool_0600B532, r11
    bra     .L_0600B540
    nop
.L_0600B504:
    mov.l   .L_pool_0600B536, r12
    mov.l   .L_pool_0600B53A, r11
    bra     .L_0600B540
    nop
.L_pool_0600B516:
    .4byte  sym_0607EB8C
.L_pool_0600B51A:
    .4byte  sym_0607E944
.L_pool_0600B51E:
    .4byte  sym_0607E940
.L_pool_0600B522:
    .4byte  sym_0607EAD8
.L_pool_0600B526:
    .4byte  sym_06063488
.L_pool_0600B52A:
    .4byte  sym_06063434
.L_pool_0600B52E:
    .4byte  sym_060634A4
.L_pool_0600B532:
    .4byte  sym_06063450
.L_pool_0600B536:
    .4byte  sym_060634C0
.L_pool_0600B53A:
    .4byte  sym_0606346C
.L_0600B534:
    cmp/eq #0x0, r0
    bt      .L_0600B4F4
    cmp/eq #0x1, r0
    bt      .L_0600B4FC
    cmp/eq #0x2, r0
    bt      .L_0600B504
.L_0600B540:
    mov.l   .L_pool_0600B65C, r9
    mov #0x0, r1
    mov.l   .L_pool_0600B660, r13
    mov.l @(16, r14), r2
    mov.l @r13, r3
    sub r3, r2
    add r9, r2
    cmp/gt r2, r1
    addc r1, r2
    shar r2
    add r2, r3
    mov.l r3, @r13
    mov.l @(20, r14), r2
    mov.l @(4, r13), r3
    sub r3, r2
    cmp/gt r2, r1
    addc r1, r2
    shar r2
    add r2, r3
    mov.l r3, @(4, r13)
    mov.l @(24, r14), r2
    mov.l @(8, r13), r3
    mov.w   DAT_0600b630, r1
    sub r3, r2
    add r1, r2
    mov #0x0, r3
    cmp/gt r2, r3
    addc r3, r2
    shar r2
    mov.l @(8, r13), r1
    add r2, r1
    mov.l   .L_pool_0600B664, r3
    jsr @r3
    mov.l r1, @(8, r13)
    mov.l @(8, r13), r6
    mov.l @(4, r13), r5
    mov.l   .L_pool_0600B668, r3
    jsr @r3
    mov.l @r13, r4
    mov.l   .L_pool_0600B66C, r3
    jsr @r3
    mov.l @(32, r14), r4
    mov.l   .L_pool_0600B670, r3
    jsr @r3
    mov.l @(36, r14), r4
    mov.l   .L_pool_0600B674, r3
    jsr @r3
    mov.l @(28, r14), r4
    mov.w   DAT_0600b632, r0
    mov.l   .L_pool_0600B66C, r3
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r2
    jsr @r3
    add r2, r4
    mov.l   .L_pool_0600B678, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600B686
    mov r9, r6
    mov r9, r5
    mov.l   .L_pool_0600B67C, r3
    jsr @r3
    mov r9, r4
    mov.l   .L_pool_0600B680, r5
    mov.l   .L_pool_0600B684, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(24, r12), r4
    mov.l   .L_pool_0600B688, r6
    mov.l   .L_pool_0600B68C, r2
    mov.l @r6, r6
    mov r2, r5
    mov.l r2, @(4, r15)
    mov.w @r5, r5
    mov.l   .L_pool_0600B690, r3
    extu.w r5, r5
    jsr @r3
    mov.l @(24, r11), r4
    mov #0x0, r6
    mov.w   DAT_0600b634, r0
    mov.l   .L_pool_0600B668, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   DAT_0600b636, r0
    mov.l   .L_pool_0600B670, r3
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   .L_0600B638, r0
    mov.l   .L_pool_0600B694, r2
    mov.l   .L_pool_0600B674, r3
    mov.l @(r0, r14), r4
    mov.l @r2, r2
    jsr @r3
    add r2, r4
    mov.l @(12, r10), r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_pool_0600B698, r3
    mov.l @r15, r4
    mov.l   .L_pool_0600B684, r2
    add r3, r5
    add r12, r4
    mov.l @r5, r5
    jsr @r2
    mov.l @r4, r4
    mov.l @(12, r10), r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_pool_0600B69C, r3
    add r3, r6
    mov.l @r6, r6
    mov.l @(4, r15), r5
    mov.w @r5, r5
    extu.w r5, r5
    mov.l @r15, r4
    add r11, r4
    bra     .L_0600B680
    mov.l @r4, r4

    .global DAT_0600b630
DAT_0600b630:
    .2byte  0x8000

    .global DAT_0600b632
DAT_0600b632:
    .2byte  0x01D8

    .global DAT_0600b634
DAT_0600b634:
    .2byte  0x01B4

    .global DAT_0600b636
DAT_0600b636:
    .2byte  0x01D0
.L_0600B638:
    .2byte  0x01C8
    .2byte  0xFFFF
.L_pool_0600B65C:
    .4byte  0x00008000
.L_pool_0600B660:
    .4byte  sym_06078670
.L_pool_0600B664:
    .4byte  sym_06027080
.L_pool_0600B668:
    .4byte  sym_060270F2
.L_pool_0600B66C:
    .4byte  FUN_060271A2
.L_pool_0600B670:
    .4byte  FUN_060271EE
.L_pool_0600B674:
    .4byte  FUN_06027158
.L_pool_0600B678:
    .4byte  sym_06059F30
.L_pool_0600B67C:
    .4byte  FUN_06027124
.L_pool_0600B680:
    .4byte  sym_06063510
.L_pool_0600B684:
    .4byte  sym_06032158
.L_pool_0600B688:
    .4byte  sym_060634F4
.L_pool_0600B68C:
    .4byte  sym_06089E98
.L_pool_0600B690:
    .4byte  sym_06031DF4
.L_pool_0600B694:
    .4byte  sym_06083258
.L_pool_0600B698:
    .4byte  sym_060634F8
.L_pool_0600B69C:
    .4byte  sym_060634DC
.L_0600B680:
    .byte   0xD2, 0x11    /* mov.l .L_pool_0600B6E8, r2 */
    jsr @r2
    nop
.L_0600B686:
    .byte   0xD4, 0x11    /* mov.l .L_pool_0600B6EC, r4 */
    mov.l @r4, r3
    add #-0x30, r3
    mov.l r3, @r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    /* THEORY: per-car opponent update loop (primary CPU, cars 1..N).
       Empirical: NOPping BSR to this function removes those cars
       from both rendering and collision. Minimap still tracks them. */
    .global FUN_0600B6A0
    .type FUN_0600B6A0, @function
FUN_0600B6A0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x44, r15
    mov.l   .L_0600B6D0, r8
    mov.l   .L_0600B6D4, r11
    mov.l   .L_0600B6D8, r12
    mov.l   .L_0600B6DC, r13
    mov.l   .L_0600B6E0, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600B6E4
    bra     .L_0600B8F8
    nop
    .4byte  sym_06031DF4
    .4byte  sym_0608A52C
.L_0600B6D0:
    .4byte  sym_06089EDC
.L_0600B6D4:
    .4byte  sym_06089E44
.L_0600B6D8:
    .4byte  sym_06031D8C
.L_0600B6DC:
    .4byte  sym_06031A28
.L_0600B6E0:
    .4byte  sym_0607EAE0
.L_0600B6E4:
    mov #0x1, r10
    mov.l   .L_0600B750, r5
    mov r5, r3
    add #0x28, r3
    mov.l r3, @(16, r15)
    mov.l   .L_0600B754, r6
    mov r6, r2
    add #0x28, r2
    mov.l r2, @(8, r15)
    mov.l   .L_0600B758, r4
    mov r4, r3
    add #0x28, r3
    mov.l r3, @(4, r15)
    mov r11, r2
    add #0x4, r2
    mov.l r2, @r15
    mov.l   .L_0600B75C, r7
    mov r7, r3
    add #0x28, r3
    mov.l r3, @(12, r15)
    mov r5, r2
    add #0x2C, r2
    mov.l r2, @(36, r15)
    mov r6, r1
    add #0x2C, r1
    mov.l r1, @(40, r15)
    mov r4, r3
    add #0x2C, r3
    mov.l r3, @(44, r15)
    mov r7, r2
    add #0x2C, r2
    mov.l r2, @(48, r15)
    mov r5, r1
    add #0x30, r1
    mov.l r1, @(52, r15)
    mov r6, r3
    add #0x30, r3
    mov.l r3, @(56, r15)
    mov r4, r2
    add #0x30, r2
    mov.l r2, @(60, r15)
    mov r7, r1
    add #0x30, r1
    mov #0x40, r0
    mov.l r1, @(r0, r15)
    add #0x18, r5
    mov.l r5, @(20, r15)
    add #0x18, r6
    mov.l r6, @(24, r15)
    add #0x18, r4
    mov.l r4, @(28, r15)
    add #0x18, r7
    bra     .L_0600B8EC
    mov.l r7, @(32, r15)
.L_0600B750:
    .4byte  sym_060621D8
.L_0600B754:
    .4byte  sym_0606212C
.L_0600B758:
    .4byte  sym_06062180
.L_0600B75C:
    .4byte  sym_060620D8
.L_0600B760:
    mov.w   .L_0600B838, r14
    mov.l   .L_0600B848, r3
    mov.l   .L_0600B84C, r1
    mul.l r14, r10
    sts macl, r14
    add r3, r14
    mov.l @r14, r2
    and r1, r2
    tst r2, r2
    bf      .L_0600B778
    bra     .L_0600B8EA
    nop
.L_0600B778:
    mov.l   .L_0600B850, r3
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.w   DAT_0600b83a, r0
    mov.l   .L_0600B854, r3
    mov.l @(r0, r14), r2
    add r2, r5
    jsr @r3
    mov.l @(16, r14), r4
    mov.l @(32, r14), r4
    mov.l   .L_0600B858, r2
    mov.l   .L_0600B85C, r3
    jsr @r3
    add r2, r4
    mov.l @(36, r14), r4
    mov.l   .L_0600B860, r3
    jsr @r3
    neg r4, r4
    mov.l @(28, r14), r4
    mov.l   .L_0600B864, r3
    jsr @r3
    neg r4, r4
    mov.w   DAT_0600b83c, r0
    mov.l @(r0, r14), r2
    mov.w   .L_0600B83E, r0
    mov.l @(r0, r14), r3
    add r3, r2
    tst r2, r2
    bt      .L_0600B7DC
    mov.w   DAT_0600b840, r0
    mov.l @(r0, r14), r4
    add #-0xC, r0
    neg r4, r4
    mov.l @(r0, r14), r3
    sub r3, r4
    mov.l   .L_0600B85C, r3
    jsr @r3
    nop
    mov.w   .L_0600B842, r0
    mov.l   .L_0600B860, r3
    mov.l @(r0, r14), r4
    jsr @r3
    neg r4, r4
    mov.w   .L_0600B844, r0
    mov.l   .L_0600B864, r3
    mov.l @(r0, r14), r4
    jsr @r3
    neg r4, r4
.L_0600B7DC:
    mov.l   .L_0600B868, r9
    mov r14, r0
    add r10, r9
    mov.b @(1, r0), r0
    mov.b @r9, r9
    tst #0x40, r0
    bf/s    .L_0600B7FA
    extu.b r9, r9
    mov.l   .L_0600B86C, r0
    mov.l   .L_0600B870, r3
    mov.l @r0, r0
    mov.l @r3, r3
    add r3, r0
    cmp/eq #0x8, r0
    bf      .L_0600B874
.L_0600B7FA:
    mov.w   DAT_0600b83c, r0
    mov.l @(r0, r14), r3
    cmp/pl r3
    bt      .L_0600B81A
    mov.l @(16, r15), r5
    mov.l @(8, r15), r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l @(4, r15), r6
    mov.l @r15, r5
    mov.l @(12, r15), r4
    mov.l @r6, r6
    mov.w @r5, r5
    jsr @r13
    mov.l @r4, r4
.L_0600B81A:
    mov.l @(36, r15), r5
    mov.l @(40, r15), r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l @(44, r15), r6
    mov r9, r0
    mov.l @(48, r15), r4
    mov.l @r6, r6
    shll r0
    mov.w @(r0, r11), r5
    jsr @r13
    mov.l @r4, r4
    bra     .L_0600B8E4
    nop
.L_0600B838:
    .2byte  0x0268

    .global DAT_0600b83a
DAT_0600b83a:
    .2byte  0x01B4

    .global DAT_0600b83c
DAT_0600b83c:
    .2byte  0x01BC
.L_0600B83E:
    .2byte  0x00B8

    .global DAT_0600b840
DAT_0600b840:
    .2byte  0x01D8
.L_0600B842:
    .2byte  0x01D0
.L_0600B844:
    .2byte  0x01C8
    .2byte  0xFFFF
.L_0600B848:
    .4byte  sym_06078900
.L_0600B84C:
    .4byte  0x00E00000
.L_0600B850:
    .4byte  sym_06026DBC
.L_0600B854:
    .4byte  sym_06026E2E
.L_0600B858:
    .4byte  0x00008000
.L_0600B85C:
    .4byte  FUN_06026EDE
.L_0600B860:
    .4byte  FUN_06026F2A
.L_0600B864:
    .4byte  FUN_06026E94
.L_0600B868:
    .4byte  sym_06047FC4
.L_0600B86C:
    .4byte  sym_06063E1C
.L_0600B870:
    .4byte  sym_06063E20
.L_0600B874:
    mov r14, r0
    mov.b @(1, r0), r0
    tst #0x20, r0
    bt      .L_0600B89C
    mov.l @(52, r15), r5
    mov.l @(56, r15), r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l @(60, r15), r6
    mov r9, r0
    mov.l @r6, r6
    shll r0
    mov.w @(r0, r11), r5
    mov #0x40, r0
    mov.l @(r0, r15), r4
    jsr @r13
    mov.l @r4, r4
    bra     .L_0600B8E4
    nop
.L_0600B89C:
    mov r14, r0
    mov.b @(1, r0), r0
    tst #0x80, r0
    bt      .L_0600B8E4
    mov.w   DAT_0600b90e, r0
    mov.l @(r0, r14), r3
    cmp/pl r3
    bt      .L_0600B8C4
    mov.l @(16, r15), r5
    mov.l @(8, r15), r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l @(4, r15), r6
    mov.l @r15, r5
    mov.l @(12, r15), r4
    mov.l @r6, r6
    mov.w @r5, r5
    jsr @r13
    mov.l @r4, r4
.L_0600B8C4:
    mov #0x1, r5
    .reloc ., R_SH_IND12W, FUN_0600AA98 - 4
    .2byte 0xB000    /* bsr FUN_0600AA98 (linker-resolved) */
    mov r14, r4
    mov.l @(20, r15), r5
    mov.l @(24, r15), r4
    mov.l @r5, r5
    jsr @r12
    mov.l @r4, r4
    mov.l @(28, r15), r6
    mov r9, r0
    mov.l @(32, r15), r4
    mov.l @r6, r6
    shll r0
    mov.w @(r0, r11), r5
    jsr @r13
    mov.l @r4, r4
.L_0600B8E4:
    mov.l @r8, r3
    add #-0x30, r3
    mov.l r3, @r8
.L_0600B8EA:
    add #0x1, r10
.L_0600B8EC:
    mov.l   .L_0600B910, r2
    mov.w @r2, r2
    cmp/hs r2, r10
    bt      .L_0600B8F8
    bra     .L_0600B760
    nop
.L_0600B8F8:
    add #0x44, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0600b90e
DAT_0600b90e:
    .2byte  0x01BC
.L_0600B910:
    .4byte  sym_06078664
