/* VERIFIED: sym_0602D814 (in this TU) writes car struct +0x0C during racing
 * Method: watchpoint on sym_06078900+0x0C during LEFT steering
 *   PC=0x0602D826 (sym_0602D814+0xE), PR=render_orchestrator+0xE4
 *   wrote 0x00043364 -> 0x00043483 (car state field, possibly speed or heading)
 *   Called from render_orchestrator pipeline.
 * Date: 2026-02-28
 */

    .section .text.FUN_0602D43C


    .global vdp1_display_submit
    .type vdp1_display_submit, @function
vdp1_display_submit:
    sts.l pr, @-r15
    mov r14, r0
    mov.w   DAT_0602d48a, r1
    mov #0x0, r12
    mov.l @(r0, r1), r10
    mov.w   .L_0602D48C, r11
    mov.w   DAT_0602d48e, r2
    mov.w @(r0, r2), r7
    cmp/pl r7
    bt      .L_0602D4A4
    mov.w   .L_0602D490, r3
    mov.l   .L_0602D498, r5
    neg r3, r4
    mov.l @(8, r0), r7
    mov.w   .L_0602D492, r8
    cmp/gt r7, r8
    bt      .L_0602D4A4
    mov.w   .L_0602D494, r2
    mov.l @(r0, r2), r9
    tst r9, r9
    bt      .L_0602D4A4
    mov.w   DAT_0602d496, r2
    mov.l @(r0, r2), r9
    cmp/gt r5, r9
    bt      .L_0602D4A4
    mov r10, r8
    cmp/gt r3, r10
    bt      .L_0602D47A
    cmp/ge r4, r10
    bt      .L_0602D4A4
    neg r8, r8
.L_0602D47A:
    sub r3, r8
    mov #0x4, r1
    mov #0xA, r2
    cmp/gt r1, r8
    bt      .L_0602D49C
    mov r1, r8
    bra     .L_0602D4A2
    nop

    .global DAT_0602d48a
DAT_0602d48a:
    .2byte  0x0154
.L_0602D48C:
    .2byte  0x0168

    .global DAT_0602d48e
DAT_0602d48e:
    .2byte  0x0166
.L_0602D490:
    .2byte  0x02F8
.L_0602D492:
    .2byte  0x00F0
.L_0602D494:
    .2byte  0x0040

    .global DAT_0602d496
DAT_0602d496:
    .2byte  0x010C
.L_0602D498:
    .4byte  0x00006800                  /* far clip distance threshold */
.L_0602D49C:
    cmp/gt r8, r2
    bt      .L_0602D4A2
    mov r2, r8
.L_0602D4A2:
    mov.w r8, @(r0, r11)
.L_0602D4A4:
    mov.w @(r0, r11), r3
    mov r3, r12
    cmp/pl r3
    bf      .L_0602D4EE
    mov.w   DAT_0602d542, r1
    mov.l @(r0, r1), r4
    tst r4, r4
    bf      .L_0602D4B6
    add #-0x2, r3
.L_0602D4B6:
    add #-0x1, r3
    mov.w r3, @(r0, r11)
    mov.l   .L_0602D550, r4
    mov r4, r2
    mov #0x0, r5
    shll16 r3
    sub r3, r2
    mov r2, r3
    cmp/pz r2
    bf      .L_0602D4E8
    mov.w   DAT_0602d544, r1
    mov.l @(r0, r1), r5
    dmuls.l r3, r5
    sts mach, r3
    sts macl, r5
    xtrct r3, r5
    mov.w   .L_0602D546, r2
    mov r5, r3
    mov.l r4, @(0, r2)
    shlr16 r3
    exts.w r3, r3
    mov.l r3, @(16, r2)
    shll16 r5
    mov.l r5, @(20, r2)
    mov.l @(28, r2), r5
.L_0602D4E8:
    mov.w   DAT_0602d544, r1
    bsr     .L_0602D7E4
    mov.l r5, @(r0, r1)
.L_0602D4EE:
    mov.w   DAT_0602d548, r1
    mov.l @(r0, r1), r4
    mov.l   .L_0602D554, r0
    jsr @r0
    nop
    shll16 r10
    dmuls.l r0, r10
    sts mach, r0
    sts macl, r10
    xtrct r0, r10
    shlr16 r10
    exts.w r10, r10
    neg r10, r10
    mov r14, r0
    mov.w   DAT_0602d54a, r1
    mov.w   DAT_0602d544, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.w   .L_0602D54C, r2
    mov.w @(r0, r2), r3
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    shll8 r3
    shlr16 r4
    shlr8 r4
    or r3, r4
    mov.l @(12, r0), r2
    mov.l   .L_0602D558, r3
    cmp/ge r3, r2
    bt      .L_0602D560
    mov #0x0, r3
    mov.l   .L_0602D55C, r6
    cmp/ge r3, r4
    bt      .L_0602D53E
    neg r6, r6
.L_0602D53E:
    bra     .L_0602D590
    mov.l r3, @-r15

    .global DAT_0602d542
DAT_0602d542:
    .2byte  0x011C

    .global DAT_0602d544
DAT_0602d544:
    .2byte  0x010C
.L_0602D546:
    .2byte  0xFF00                      /* -> 0xFFFFFF00 (SH-2 hw divider) */

    .global DAT_0602d548
DAT_0602d548:
    .2byte  0x005C

    .global DAT_0602d54a
DAT_0602d54a:
    .2byte  0x0144
.L_0602D54C:
    .2byte  0x00CE
    .2byte  0x0000
.L_0602D550:
    .4byte  0x000A0000                  /* 10.0 in 16.16 fixed-point */
.L_0602D554:
    .4byte  cos_lookup
.L_0602D558:
    .4byte  0x00000100                  /* 256 — min sq_dist for atan path */
.L_0602D55C:
    .4byte  0x00004000                  /* 0.25 (16.16 fixed-point) */
.L_0602D560:
    mov r2, r3
    dmuls.l r2, r3
    sts mach, r2
    sts macl, r3
    xtrct r2, r3
    mov.l r3, @-r15
    mov.w   .L_0602D5F0, r2
    mov r4, r1
    mov.l r3, @(0, r2)
    shlr16 r1
    exts.w r1, r1
    mov.l r1, @(16, r2)
    shll16 r4
    mov.l r4, @(20, r2)
    mov.l   .L_0602D5FC, r0
    mov.l @(28, r2), r4
    jsr @r0
    nop
    cmp/eq #0x0, r0
    bf      .L_0602D58E
    mov.w   DAT_0602d5f2, r4
    add r14, r4
    mov.b @r4, r0
.L_0602D58E:
    mov r0, r6
.L_0602D590:
    mov r14, r0
    mov.w   DAT_0602d5f4, r1
    mov #0x0, r8
    mov.w @(r0, r1), r2
    cmp/pl r2
    bf      .L_0602D5D6
    mov.l @(8, r0), r2
    mov #0x46, r4
    cmp/ge r4, r2
    bt      .L_0602D5D6
    mov.w   .L_0602D5F6, r1
    mov.l @(r0, r1), r2
    mov.w   .L_0602D5F8, r3
    mov.l @(r0, r3), r4
    xor r2, r4
    cmp/pz r4
    bt      .L_0602D5D6
    mov #0x1, r8
    shar r2
    mov #0x9, r5
    muls.w r2, r5
    shll16 r6
    sts macl, r4
    mov.l   .L_0602D600, r0
    jsr @r0
    nop
    dmuls.l r0, r6
    sts mach, r2
    sts macl, r6
    xtrct r2, r6
    shlr16 r6
    exts.w r6, r6
    cmp/pz r6
    bt      .L_0602D5D6
    mov #0x0, r6
.L_0602D5D6:
    mov.w   .L_0602D5F8, r3
    mov r14, r0
    mov.l @(r0, r3), r5
    mov #0x3, r4
    muls.w r4, r6
    neg r5, r5
    sts macl, r6
    cmp/pz r5
    bf      .L_0602D604
    cmp/gt r5, r6
    bt      .L_0602D60E
    bra     .L_0602D610
    nop
.L_0602D5F0:
    .2byte  0xFF00                      /* -> 0xFFFFFF00 (SH-2 hw divider) */

    .global DAT_0602d5f2
DAT_0602d5f2:
    .2byte  0x007F

    .global DAT_0602d5f4
DAT_0602d5f4:
    .2byte  0x0166
.L_0602D5F6:
    .2byte  0x0040
.L_0602D5F8:
    .2byte  0x005C
    .2byte  0x0000
.L_0602D5FC:
    .4byte  atan_piecewise
.L_0602D600:
    .4byte  cos_lookup
.L_0602D604:
    neg r6, r6
    cmp/gt r6, r5
    bt      .L_0602D60E
    bra     .L_0602D610
    mov #0x0, r7
.L_0602D60E:
    mov r5, r6
.L_0602D610:
    neg r6, r11
    mov r14, r0
    mov.w   .L_0602D62C, r1
    mov.l @(r0, r1), r5
    sub r11, r10
    sub r5, r10
    add r10, r5
    mov.w   .L_0602D62E, r3
    neg r3, r4
    cmp/gt r4, r5
    bt      .L_0602D630
    mov r4, r5
    bra     .L_0602D636
    nop
.L_0602D62C:
    .2byte  0x0178
.L_0602D62E:
    .2byte  0x0300
.L_0602D630:
    cmp/gt r5, r3
    bt      .L_0602D636
    mov r3, r5
.L_0602D636:
    mov.l r5, @(r0, r1)
    mov.w   DAT_0602d67c, r2
    mov.l @(r0, r2), r3
    mov r3, r6
    add r3, r5
    sub r5, r6
    neg r6, r6
    shar r6
    shar r6
    shar r6
    sub r6, r5
    mov.l r5, @(r0, r2)
    mov.w   .L_0602D67E, r1
    mov.w   .L_0602D680, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.w   DAT_0602d682, r2
    mov.w @(r0, r2), r3
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    shll8 r3
    shlr16 r4
    shlr8 r4
    or r3, r4
    mov.l @r15+, r3
    tst r3, r3
    bf      .L_0602D688
    mov.l   .L_0602D684, r6
    bra     .L_0602D6AC
    nop

    .global DAT_0602d67c
DAT_0602d67c:
    .2byte  0x005C
.L_0602D67E:
    .2byte  0x0140
.L_0602D680:
    .2byte  0x0108

    .global DAT_0602d682
DAT_0602d682:
    .2byte  0x00CC
.L_0602D684:
    .4byte  0x00004000                  /* 0.25 (16.16 fixed-point) */
.L_0602D688:
    mov.w   .L_0602D6BE, r2
    mov r4, r1
    mov.l r3, @(0, r2)
    shlr16 r1
    exts.w r1, r1
    mov.l r1, @(16, r2)
    shll16 r4
    mov.l r4, @(20, r2)
    mov.l @(28, r2), r4
    mov.l   .L_0602D6C4, r0
    jsr @r0
    nop
    cmp/eq #0x0, r0
    bf      .L_0602D6AA
    mov.w   .L_0602D6C0, r4
    add r14, r4
    mov.b @r4, r0
.L_0602D6AA:
    mov r0, r6
.L_0602D6AC:
    mov r14, r0
    mov #0x32, r3
    mov.w   DAT_0602d6c2, r4
    mov.l @(8, r0), r7
    cmp/gt r3, r7
    bt      .L_0602D6C8
    mov r3, r7
    bra     .L_0602D6CE
    nop
.L_0602D6BE:
    .2byte  0xFF00                      /* -> 0xFFFFFF00 (SH-2 hw divider) */
.L_0602D6C0:
    .2byte  0x007E

    .global DAT_0602d6c2
DAT_0602d6c2:
    .2byte  0x00FA
.L_0602D6C4:
    .4byte  atan_piecewise
.L_0602D6C8:
    cmp/gt r7, r4
    bt      .L_0602D6CE
    mov r4, r7
.L_0602D6CE:
    sub r3, r4
    sub r3, r7
    mov.l   .L_0602D734, r12
    shll8 r7
    mov r4, r0
    jsr @r12
    mov r7, r1
    mov r14, r0
    mov #0x2, r3
    mov #0x3, r4
    muls.w r4, r1
    shll8 r3
    sts macl, r7
    add r3, r7
    mov.w   .L_0602D730, r1
    mov.w   DAT_0602d732, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    mov r4, r13
    mov r3, r5
    sub r4, r5
    mov.l r7, @-r15
    muls.w r6, r7
    sts macl, r6
    neg r4, r4
    mov r5, r7
    shlr8 r6
    xor r3, r7
    cmp/pz r7
    bt      .L_0602D724
    mov.l   .L_0602D738, r4
    cmp/pz r3
    bt      .L_0602D712
    neg r4, r4
.L_0602D712:
    sub r4, r3
    neg r3, r3
    dmuls.l r3, r6
    mov.l   .L_0602D734, r12
    mov r4, r0
    jsr @r12
    sts macl, r1
    mov r0, r6
    mov r14, r0
.L_0602D724:
    cmp/pz r5
    bf      .L_0602D73C
    cmp/gt r5, r6
    bt      .L_0602D746
    bra     .L_0602D748
    nop
.L_0602D730:
    .2byte  0x0040

    .global DAT_0602d732
DAT_0602d732:
    .2byte  0x005C
.L_0602D734:
    .4byte  sym_0602ECCC
.L_0602D738:
    .4byte  0x00000FE0                  /* ~180 degrees in angle units */
.L_0602D73C:
    neg r6, r6
    cmp/gt r6, r5
    bt      .L_0602D746
    bra     .L_0602D748
    nop
.L_0602D746:
    mov r5, r6
.L_0602D748:
    shll8 r6
    mov.l   .L_0602D798, r12
    mov.l @r15+, r0
    jsr @r12
    mov r6, r1
    mov r0, r6
    mov r14, r0
    sub r5, r6
    mov.w   DAT_0602d790, r1
    mov.l @(r0, r1), r3
    sub r6, r3
    neg r3, r3
    shar r3
    shar r3
    shar r3
    sub r3, r6
    mov.l r6, @(r0, r1)
    mov.l @(8, r0), r3
    mov.w   .L_0602D792, r4
    cmp/ge r3, r4
    mov.w   .L_0602D794, r7
    bt      .L_0602D7C0
    mov.l @(r0, r7), r6
    mov.l   .L_0602D79C, r5
    cmp/ge r6, r5
    bt      .L_0602D7A8
    neg r5, r5
    cmp/gt r6, r5
    bt      .L_0602D7C0
    mov.l @(0, r0), r2
    mov.l   .L_0602D7A0, r3
    or r3, r2
    mov.l   .L_0602D7A4, r3
    or r3, r2
    bra     .L_0602D7C0
    mov.l r2, @(0, r0)

    .global DAT_0602d790
DAT_0602d790:
    .2byte  0x0058
.L_0602D792:
    .2byte  0x0041
.L_0602D794:
    .2byte  0x005C
    .2byte  0x0000
.L_0602D798:
    .4byte  sym_0602ECCC
.L_0602D79C:
    .4byte  0xFFFFCD80                  /* -0x3280 lateral distance threshold */
.L_0602D7A0:
    .4byte  0x20000000                  /* cache-through render flag */
.L_0602D7A4:
    .4byte  0x40000000                  /* 0.25 (2.30) or 16384.0 (16.16) */
.L_0602D7A8:
    mov.l @(0, r0), r2
    mov.l   .L_0602D7B8, r3
    or r3, r2
    mov.l   .L_0602D7BC, r3
    or r3, r2
    bra     .L_0602D7C0
    mov.l r2, @(0, r0)
    .2byte  0x0000
.L_0602D7B8:
    .4byte  0x10000000                  /* near-object render flag */
.L_0602D7BC:
    .4byte  0x40000000                  /* 0.25 (2.30) or 16384.0 (16.16) */
.L_0602D7C0:
    mov.l @(r0, r7), r6
    mov.l   .L_0602D7E0, r3
    cmp/ge r6, r3
    bt      .L_0602D7CE
    neg r3, r3
    cmp/ge r6, r3
    bt      .L_0602D7D6
.L_0602D7CE:
    mov r3, r6
    mov #0x1, r4
    mov.w   .L_0602D7DC, r1
    mov.w r4, @(r0, r1)
.L_0602D7D6:
    lds.l @r15+, pr
    rts
    mov.l r6, @(r0, r7)
.L_0602D7DC:
    .2byte  0x00D4
    .2byte  0x0000
.L_0602D7E0:
    .4byte  0xFFFFCC00                  /* -0x3400 velocity clamp limit */
.L_0602D7E4:
    mov.l r3, @-r15
    mov.l @(8, r0), r3
    mov.w   .L_0602D80C, r1
    cmp/pl r3
    bf      .L_0602D808
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov #0x3, r4
    mov.w @(r0, r1), r3
    cmp/gt r4, r3
    bt      .L_0602D804
    mov.l   .L_0602D810, r5
    tst r3, r3
    bt      .L_0602D802
    add #-0x3, r5
.L_0602D802:
    mov.w r5, @(r0, r1)
.L_0602D804:
    mov.l @r15+, r5
    mov.l @r15+, r4
.L_0602D808:
    rts
    mov.l @r15+, r3
.L_0602D80C:
    .2byte  0x0166
    .2byte  0x0000
.L_0602D810:
    .4byte  0x0000000A                  /* 10 = visibility counter reset */

    .global sym_0602D814
sym_0602D814:
    mov r14, r0
    mov.l @(12, r0), r4
    mov.w   DAT_0602d862, r2
    mov.l @(r0, r2), r3
    add r3, r4
    mov.l r4, @(12, r0)
    cmp/pz r4
    bt      sym_0602D82A
    mov #0x0, r3
    mov.l r3, @(12, r0)
    mov.l r3, @(r0, r2)

    .global sym_0602D82A
sym_0602D82A:
    mov.w   DAT_0602d864, r2
    mov.l @(12, r0), r3
    mov.w @(r0, r2), r4
    mov.l   .L_0602D868, r5
    shll2 r4
    add r5, r4
    mov.l @r4, r4
    mov.l   .L_0602D86C, r5
    dmuls.l r3, r4
    nop
    nop
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    dmuls.l r4, r5
    mov.w   DAT_0602d866, r1
    mov #0x0, r3
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
    shlr16 r5
    mov r5, r6
    mov.l   .L_0602D870, r4
    cmp/gt r3, r5
    bt      .L_0602D874
    mov r3, r5
    bra     .L_0602D87A
    nop

    .global DAT_0602d862
DAT_0602d862:
    .2byte  0x00FC

    .global DAT_0602d864
DAT_0602d864:
    .2byte  0x00DC

    .global DAT_0602d866
DAT_0602d866:
    .2byte  0x00E0
.L_0602D868:
    .4byte  sym_060477BC
.L_0602D86C:
    .4byte  0x0221AC91                  /* global intensity scale constant */
.L_0602D870:
    .4byte  0x00002134                  /* max display intensity value */
.L_0602D874:
    cmp/gt r5, r4
    bt      .L_0602D87A
    mov r4, r5
.L_0602D87A:
    mov.l r5, @(r0, r1)
    sub r5, r6
    cmp/pz r6
    bt      .L_0602D884
    mov #0x0, r6
.L_0602D884:
    mov.w   DAT_0602d88c, r1
    mov.l r6, @(r0, r1)
    rts
    nop

    .global DAT_0602d88c
DAT_0602d88c:
    .2byte  0x00E8

    .global sym_0602D88E
sym_0602D88E:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
