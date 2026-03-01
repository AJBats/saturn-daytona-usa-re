
    .section .text.FUN_0600D31C


    .global physics_calc_dispatch
    .type physics_calc_dispatch, @function
physics_calc_dispatch:
    sts.l pr, @-r15
    mov.l   .L_0600D370, r3
    mov.l   .L_0600D374, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bf      .L_0600D32E
    bsr     .L_0600D37C
    nop
.L_0600D32E:
    bsr     .L_0600D3C4
    nop
    bra     render_batch
    lds.l @r15+, pr

    .global sym_0600D336
sym_0600D336:
    mov.l   .L_0600D378, r5
    mov.w   .L_0600D36A, r3
    mov.l   .L_0600D370, r2
    mov r5, r4
    mov.l @r2, r2
    add r3, r5
    mov.l   .L_0600D374, r3
    and r3, r2
    tst r2, r2
    bf      .L_0600D366
    mov #0x1, r7
    mov.w   .L_0600D36C, r0
    mov.l @(r0, r4), r3
    mov.l @(r0, r5), r2
    cmp/ge r2, r3
    bf/s    .L_0600D360
    mov #0x0, r6
    mov.w   .L_0600D36E, r0
    mov.l r6, @(r0, r4)
    bra     .L_0600D366
    mov.l r7, @(r0, r5)
.L_0600D360:
    mov.w   .L_0600D36E, r0
    mov.l r7, @(r0, r4)
    mov.l r6, @(r0, r5)
.L_0600D366:
    rts
    nop
.L_0600D36A:
    .2byte  0x0268
.L_0600D36C:
    .2byte  0x01F4
.L_0600D36E:
    .2byte  0x0224
.L_0600D370:
    .4byte  sym_0607EBC4
.L_0600D374:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_0600D378:
    .4byte  sym_06078900
.L_0600D37C:
    mov.l r13, @-r15
    mov #0x1, r13
    mov.l r12, @-r15
    mov.l   .L_0600D40C, r4
    mov.w   DAT_0600d404, r0
    mov.l   .L_0600D410, r5
    mov.l @r4, r1
    mov.l @r5, r5
    mov.l @(r0, r1), r1
    cmp/hi r13, r5
    bf/s    .L_0600D3B8
    mov #0x0, r12
.L_0600D394:
    mov.l @(4, r4), r6
    mov.w   DAT_0600d404, r0
    mov.l @(r0, r6), r7
    cmp/gt r1, r7
    bf      .L_0600D3A6
    mov.l @r4, r7
    mov.l r6, @r4
    bra     .L_0600D3A8
    mov.l r7, @(4, r4)
.L_0600D3A6:
    mov r7, r1
.L_0600D3A8:
    mov.l @r4+, r3
    mov r12, r2
    mov.w   DAT_0600d406, r0
    add #-0x1, r5
    mov.l r2, @(r0, r3)
    cmp/hi r13, r5
    bt/s    .L_0600D394
    add #0x1, r12
.L_0600D3B8:
    mov.l @r4, r2
    mov.w   DAT_0600d406, r0
    mov.l r12, @(r0, r2)
    mov.l @r15+, r12
    rts
    mov.l @r15+, r13
.L_0600D3C4:
    mov.l r13, @-r15
    mov.l   .L_0600D414, r4
    mov.w   .L_0600D408, r0
    mov.l   .L_0600D418, r3
    mov.l @r4, r5
    mov.l @r3, r3
    mov.l @(r0, r5), r5
    cmp/hi r5, r3
    bf/s    .L_0600D3DC
    mov #0x1, r13
    bra     vehicle_state_update
    mov.l @r15+, r13
.L_0600D3DC:
    mov.l   .L_0600D410, r6
    mov.l @r6, r6
    cmp/hi r13, r6
    bf      .L_0600D400
.L_0600D3E4:
    mov.l @(4, r4), r7
    mov.w   .L_0600D408, r0
    mov.l @(r0, r7), r1
    cmp/hi r5, r1
    bf      .L_0600D3F6
    mov.l @r4, r1
    mov.l r7, @r4
    bra     .L_0600D3F8
    mov.l r1, @(4, r4)
.L_0600D3F6:
    mov r1, r5
.L_0600D3F8:
    add #-0x1, r6
    cmp/hi r13, r6
    bt/s    .L_0600D3E4
    add #0x4, r4
.L_0600D400:
    bra     .L_0600D496
    mov.l @r15+, r13

    .global DAT_0600d404
DAT_0600d404:
    .2byte  0x01F4

    .global DAT_0600d406
DAT_0600d406:
    .2byte  0x0224
.L_0600D408:
    .2byte  0x01EC
    .2byte  0xFFFF
.L_0600D40C:
    .4byte  sym_0607E94C
.L_0600D410:
    .4byte  sym_0607EA98
.L_0600D414:
    .4byte  sym_0607E9EC
.L_0600D418:
    .4byte  sym_060786B4

    .global vehicle_state_update
    .type vehicle_state_update, @function
vehicle_state_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_0600D4A8, r12
    mov.l   .L_0600D4AC, r13
    mov #0x1, r14
    bra     .L_0600D42E
    mov r14, r4
.L_0600D42C:
    add #0x1, r4
.L_0600D42E:
    mov r4, r0
    mov.l @r12, r2
    shll2 r0
    mov.l @(r0, r13), r3
    mov.w   DAT_0600d4a6, r0
    mov.l @(r0, r3), r3
    cmp/hi r3, r2
    bf      .L_0600D444
    mov #0x3, r2
    cmp/hs r2, r4
    bf      .L_0600D42C
.L_0600D444:
    mov.l   .L_0600D4B0, r7
    mov r4, r5
    mov #0x0, r2
    cmp/hi r2, r5
    bf/s    .L_0600D45E
    mov r13, r6
.L_0600D450:
    mov.l @r6+, r1
    add #-0x1, r5
    mov #0x0, r3
    mov.l r1, @r7
    cmp/hi r3, r5
    bt/s    .L_0600D450
    add #0x4, r7
.L_0600D45E:
    mov.l   .L_0600D4B4, r5
    mov.l @r5, r5
    sub r4, r5
    cmp/hi r14, r5
    bf/s    .L_0600D478
    mov r13, r7
.L_0600D46A:
    mov r7, r2
    mov.l @r6+, r1
    add #-0x1, r5
    add #0x4, r7
    cmp/hi r14, r5
    bt/s    .L_0600D46A
    mov.l r1, @r2
.L_0600D478:
    mov.l   .L_0600D4B0, r5
    mov #0x0, r2
    cmp/hi r2, r4
    bf      .L_0600D48E
.L_0600D480:
    mov.l @r5+, r1
    add #-0x1, r4
    mov #0x0, r3
    mov.l r1, @r7
    cmp/hi r3, r4
    bt/s    .L_0600D480
    add #0x4, r7
.L_0600D48E:
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     .L_0600D496
    mov.l @r15+, r14
.L_0600D496:
    add #-0x4, r15
    mov.l   .L_0600D4B4, r7
    mov.l   .L_0600D4AC, r5
    mov r5, r4
    add #0x4, r4
    mov.l r4, @r15
    bra     .L_0600D4D0
    mov #0x1, r6

    .global DAT_0600d4a6
DAT_0600d4a6:
    .2byte  0x01EC
.L_0600D4A8:
    .4byte  sym_060786B4
.L_0600D4AC:
    .4byte  sym_0607E9EC
.L_0600D4B0:
    .4byte  sym_0607EA8C
.L_0600D4B4:
    .4byte  sym_0607EA98
.L_0600D4B8:
    mov.l @r4, r2
    mov r4, r3
    add #-0x4, r3
    mov.l @r3, r1
    mov.w   .L_0600D534, r0
    mov.l r1, @(r0, r2)
    mov.l @r4, r3
    mov.l @(4, r4), r2
    add #0x4, r0
    mov.l r2, @(r0, r3)
    add #0x4, r4
    add #0x1, r6
.L_0600D4D0:
    mov.l @r7, r3
    add #-0x1, r3
    cmp/hs r3, r6
    bf      .L_0600D4B8
    mov.l @r5, r3
    mov.l @r4, r2
    mov.w   .L_0600D534, r0
    mov.l r2, @(r0, r3)
    mov.l @r5, r3
    mov.l @r15, r2
    mov.w   DAT_0600d536, r0
    mov.l @r2, r1
    mov r4, r2
    mov.l r1, @(r0, r3)
    add #-0x4, r2
    mov.l @r4, r3
    add #-0x4, r0
    mov.l @r2, r1
    mov.l r1, @(r0, r3)
    mov.l @r4, r3
    add #0x4, r0
    mov.l @r5, r2
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    add #-0x50, r0
    mov.l   .L_0600D538, r1
    mov.l @(r0, r3), r2
    mov.l r2, @r1
    rts
    add #0x4, r15

    .global render_batch
    .type render_batch, @function
render_batch:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_0600D53C, r9
    mov.l   .L_0600D540, r11
    mov #0x1, r13
    mov #0x0, r14
    mov.l   .L_0600D544, r3
    mov.l r14, @r3
    mov.l r14, @(8, r15)
    mov r14, r8
    mov.l   .L_0600D548, r6
    bra     .L_0600D586
    mov r14, r5
.L_0600D534:
    .2byte  0x0238

    .global DAT_0600d536
DAT_0600d536:
    .2byte  0x023C
.L_0600D538:
    .4byte  sym_060786B4
.L_0600D53C:
    .4byte  sym_0607E944
.L_0600D540:
    .4byte  sym_0607EA98
.L_0600D544:
    .4byte  sym_0607EBDC
.L_0600D548:
    .4byte  sym_0607E94C
.L_0600D54C:
    mov.l @r6+, r4
    mov.w   DAT_0600d5d6, r0
    mov.l r14, @(r0, r4)
    mov r14, r0
    mov.w   .L_0600D5D8, r1
    mov.l   .L_0600D5E4, r3
    jsr @r3
    mov r4, r2
    mov r14, r0
    mov.w   .L_0600D5DA, r1
    mov.l   .L_0600D5E4, r3
    jsr @r3
    mov r4, r2
    mov r14, r0
    mov.w   .L_0600D5DC, r1
    mov.l   .L_0600D5E4, r3
    jsr @r3
    mov r4, r2
    mov r14, r0
    mov.w   .L_0600D5DE, r1
    mov.l   .L_0600D5E4, r3
    jsr @r3
    mov r4, r2
    mov r14, r0
    mov.w   .L_0600D5E0, r1
    mov.l   .L_0600D5E4, r3
    jsr @r3
    mov r4, r2
    add #0x1, r5
.L_0600D586:
    mov.l @r11, r2
    cmp/hs r2, r5
    bf      .L_0600D54C
    mov.l @r9, r4
    mov.l   .L_0600D5E8, r2
    mov.l   .L_0600D5EC, r3
    mov r4, r12
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bf/s    .L_0600D604
    mov r4, r10
    mov r15, r6
    mov r15, r5
    mov.l   .L_0600D5F0, r4
    mov.l   .L_0600D5F4, r3
    add #0x4, r6
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_0600D5F8, r5
    mov.l @r15, r4
    mov.l   .L_0600D5FC, r3
    jsr @r3
    neg r4, r4
    mov.l r0, @r15
    mov.l   .L_0600D5F8, r5
    mov.l   .L_0600D5FC, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov.l r0, @(4, r15)
    mov.l   .L_0600D600, r4
    mov.l @r4, r3
    mov.l @r15, r2
    add r3, r2
    mov.l r2, @r15
    mov.l @(8, r4), r3
    mov.l @(4, r15), r2
    add r3, r2
    bra     .L_0600D63A
    nop

    .global DAT_0600d5d6
DAT_0600d5d6:
    .2byte  0x0218
.L_0600D5D8:
    .2byte  0x0801
.L_0600D5DA:
    .2byte  0x0901
.L_0600D5DC:
    .2byte  0x0A01
.L_0600D5DE:
    .2byte  0x0701
.L_0600D5E0:
    .2byte  0x0601
    .2byte  0xFFFF
.L_0600D5E4:
    .4byte  sym_06034F78
.L_0600D5E8:
    .4byte  sym_0607EBC4
.L_0600D5EC:
    .4byte  0x10060000
.L_0600D5F0:
    .4byte  sym_06063EF0
.L_0600D5F4:
    .4byte  sincos_pair
.L_0600D5F8:
    .4byte  0x00070000
.L_0600D5FC:
    .4byte  fpmul
.L_0600D600:
    .4byte  sym_06063DF8
.L_0600D604:
    mov r15, r6
    mov r15, r5
    mov.l @r9, r4
    mov.l   .L_0600D6C0, r3
    add #0x4, r6
    jsr @r3
    mov.l @(32, r4), r4
    mov.l   .L_0600D6C4, r5
    mov.l @r15, r4
    mov.l   .L_0600D6C8, r3
    jsr @r3
    neg r4, r4
    mov.l r0, @r15
    mov.l   .L_0600D6C4, r5
    mov.l   .L_0600D6C8, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov.l r0, @(4, r15)
    mov.l @r9, r3
    mov.l @(16, r3), r2
    mov.l @r15, r3
    add r2, r3
    mov.l r3, @r15
    mov.l @r9, r2
    mov.l @(24, r2), r3
    mov.l @(4, r15), r2
    add r3, r2
.L_0600D63A:
    mov.l r2, @(4, r15)
    mov.l @r11, r4
    cmp/hi r13, r4
    bf      .L_0600D6EE
.L_0600D642:
    mov.w   .L_0600D6BA, r0
    mov.l @(r0, r12), r12
    add #0x4, r0
    mov.l @(r0, r10), r10
    add #-0x24, r0
    mov.l r4, @(r0, r12)
    mov.l r4, @(r0, r10)
    mov.l @(16, r12), r6
    mov.l @r15, r5
    sub r6, r5
    cmp/pz r5
    bt      .L_0600D664
    mov.l @r15, r2
    mov r6, r3
    sub r2, r3
    bra     .L_0600D666
    nop
.L_0600D664:
    mov r5, r3
.L_0600D666:
    mov.l @(24, r12), r2
    mov.l r2, @(12, r15)
    mov.l @(4, r15), r7
    sub r2, r7
    cmp/pz r7
    bt      .L_0600D67A
    mov.l @(12, r15), r1
    mov.l @(4, r15), r0
    bra     .L_0600D67C
    sub r0, r1
.L_0600D67A:
    mov r7, r1
.L_0600D67C:
    mov r3, r5
    add r1, r5
    mov.l   .L_0600D6CC, r3
    cmp/ge r3, r5
    bt      .L_0600D6A0
    mov.l @(8, r15), r3
    mov #0x3, r2
    cmp/ge r2, r3
    bt      .L_0600D6A0
    mov r13, r0
    mov.w   .L_0600D6BC, r1
    mov.l   .L_0600D6D0, r3
    jsr @r3
    mov r12, r2
    mov.l @(8, r15), r2
    add #0x1, r2
    bra     .L_0600D6E8
    mov.l r2, @(8, r15)
.L_0600D6A0:
    mov.l   .L_0600D6D4, r2
    cmp/ge r2, r5
    bt      .L_0600D6D8
    mov #0x7, r2
    cmp/ge r2, r8
    bt      .L_0600D6D8
    mov r13, r0
    mov.w   .L_0600D6BE, r1
    mov.l   .L_0600D6D0, r3
    jsr @r3
    mov r12, r2
    bra     .L_0600D6E8
    add #0x1, r8
.L_0600D6BA:
    .2byte  0x0238
.L_0600D6BC:
    .2byte  0x0801
.L_0600D6BE:
    .2byte  0x0901
.L_0600D6C0:
    .4byte  sincos_pair
.L_0600D6C4:
    .4byte  0x00050000
.L_0600D6C8:
    .4byte  fpmul
.L_0600D6CC:
    .4byte  0x000C0000
.L_0600D6D0:
    .4byte  sym_06034F78
.L_0600D6D4:
    .4byte  0x00230000
.L_0600D6D8:
    mov.l   .L_0600D774, r2
    cmp/ge r2, r5
    bt      .L_0600D6E8
    mov r13, r0
    mov.w   .L_0600D766, r1
    mov.l   .L_0600D778, r3
    jsr @r3
    mov r12, r2
.L_0600D6E8:
    add #-0x1, r4
    cmp/hi r13, r4
    bt      .L_0600D642
.L_0600D6EE:
    mov.l @r9, r2
    mov.w   .L_0600D768, r1
    mov.l   .L_0600D778, r3
    jsr @r3
    mov r13, r0
    mov.l @r9, r7
    mov.w   DAT_0600d76a, r0
    mov.l @(r0, r7), r7
    mov.l   .L_0600D77C, r4
    bra     .L_0600D74C
    mov r13, r6
.L_0600D704:
    mov.w   DAT_0600d76a, r0
    mov.w   .L_0600D76C, r1
    mov.l   .L_0600D778, r3
    mov.l @(r0, r4), r5
    mov r14, r0
    sub r7, r5
    jsr @r3
    mov r4, r2
    mov r14, r0
    mov.w   .L_0600D76E, r1
    mov.l   .L_0600D778, r3
    jsr @r3
    mov r4, r2
    mov #0x3, r2
    cmp/ge r2, r5
    bt      .L_0600D732
    cmp/pl r5
    bf      .L_0600D732
    mov r13, r0
    mov.w   .L_0600D76C, r1
    mov.l   .L_0600D778, r3
    jsr @r3
    mov r4, r2
.L_0600D732:
    cmp/pl r5
    bt      .L_0600D746
    mov #-0x2, r3
    cmp/gt r3, r5
    bf      .L_0600D746
    mov r13, r0
    mov.w   .L_0600D76E, r1
    mov.l   .L_0600D778, r3
    jsr @r3
    mov r4, r2
.L_0600D746:
    add #0x1, r6
    mov.w   .L_0600D770, r2
    add r2, r4
.L_0600D74C:
    mov.l @r11, r3
    cmp/hs r3, r6
    bf      .L_0600D704
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0600D766:
    .2byte  0x0A01
.L_0600D768:
    .2byte  0x0801

    .global DAT_0600d76a
DAT_0600d76a:
    .2byte  0x01EC
.L_0600D76C:
    .2byte  0x0701
.L_0600D76E:
    .2byte  0x0601
.L_0600D770:
    .2byte  0x0268
    .2byte  0xFFFF
.L_0600D774:
    .4byte  0x00780000
.L_0600D778:
    .4byte  sym_06034F78
.L_0600D77C:
    .4byte  sym_06078B68
