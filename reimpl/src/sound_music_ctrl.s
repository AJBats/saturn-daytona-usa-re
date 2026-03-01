
    .section .text.FUN_06030548


    .global sound_music_ctrl
    .type sound_music_ctrl, @function
sound_music_ctrl:
    sts.l pr, @-r15
    mov.l @r14, r14
    mov.w   DAT_0603056a, r1
    add r14, r1
    mov.l @r1, r3
    mov.l @(4, r1), r4
    mov.l @(8, r1), r5
    mov.l @(12, r1), r6
    mov r3, r2
    or r4, r2
    or r5, r2
    or r6, r2
    mov.w   .L_0603056C, r7
    tst r7, r2
    bf      .L_06030578
    bra     .L_06030724
    nop

    .global DAT_0603056a
DAT_0603056a:
    .2byte  0x0120
.L_0603056C:
    .2byte  0x0080
    .2byte  0x0000
    .4byte  sym_06030FBE
    .4byte  sym_0607E940
.L_06030578:
    and r3, r4
    and r5, r6
    and r4, r6
    mov.w   .L_06030588, r2
    tst r2, r6
    bt      .L_0603058A
    bra     .L_06030724
    nop
.L_06030588:
    .2byte  0x0001                      /* 1 */
.L_0603058A:
    mov.w   .L_06030598, r2
    tst r2, r6
    bt      .L_060305A0
    mov.l   .L_0603059C, r7
    mov #0x0, r4
    bra     .L_06030A9C
    mov.l @(16, r7), r6
.L_06030598:
    .2byte  0x0080
    .2byte  0x0000
.L_0603059C:
    .4byte  sym_06063EC4
.L_060305A0:
    mov.w   DAT_060305ae, r2
    tst r2, r6
    bt      .L_060305B2
    mov.w   DAT_060305b0, r0
    mov #0xF, r2
    bra     .L_06030724
    mov.w r2, @(r0, r14)

    .global DAT_060305ae
DAT_060305ae:
    .2byte  0x0004

    .global DAT_060305b0
DAT_060305b0:
    .2byte  0x016C
.L_060305B2:
    mov #0x0, r12
    mov.w   DAT_06030602, r5
    mov.l @r1, r4
    tst r5, r4
    bt      .L_060305BE
    add #0x1, r12
.L_060305BE:
    mov.l @(4, r1), r4
    tst r5, r4
    bt      .L_060305C6
    add #0x2, r12
.L_060305C6:
    mov.l @(8, r1), r4
    tst r5, r4
    bt      .L_060305CE
    add #0x4, r12
.L_060305CE:
    mov.l @(12, r1), r4
    tst r5, r4
    bt      .L_060305D6
    add #0x8, r12
.L_060305D6:
    mov.w   DAT_06030604, r7
    mov #0x8, r4
    add r14, r7
    mov.l r4, @r7
    mov #0x3, r7
    cmp/eq r7, r12
    bt      .L_06030644
    mov #0xC, r7
    cmp/eq r7, r12
    bt      .L_06030606
    mov #0x5, r7
    mov r7, r5
    and r12, r7
    cmp/eq r5, r7
    bt      .L_060306D8
    tst r7, r7
    bt      .L_0603068C
    mov #0xA, r5
    tst r12, r5
    bt      .L_060306D8
    bra     .L_0603068C
    nop

    .global DAT_06030602
DAT_06030602:
    .2byte  0x0080

    .global DAT_06030604
DAT_06030604:
    .2byte  0x0208
.L_06030606:
    mov.l   .L_0603063C, r7
    mov.w   DAT_0603063a, r4
    mov.l @(16, r7), r5
    mov.l @(48, r14), r2
    add r4, r5
    sub r5, r2
    cmp/pz r2
    mov.l @(16, r7), r5
    bt      .L_0603061A
    neg r2, r2
.L_0603061A:
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_0603062C
    mov r4, r3
    shll r4
    add r4, r3
    cmp/gt r3, r2
    bt      .L_0603062C
    add r4, r5
.L_0603062C:
    mov.w   DAT_0603063a, r4
    mov.l   .L_06030640, r3
    add r4, r5
    mov.w r5, @r3
    mov #0x2, r4
    bra     .L_06030B68
    mov.l @(16, r7), r5

    .global DAT_0603063a
DAT_0603063a:
    .2byte  0x4000
.L_0603063C:
    .4byte  sym_06063EC4
.L_06030640:
    .4byte  sym_06030FBC
.L_06030644:
    mov #0x1, r5
    mov.l @(48, r14), r2
    shll16 r5
    shlr r5
    mov.l   .L_06030684, r7
    add r5, r2
    mov.w   DAT_06030680, r4
    mov.l @(16, r7), r5
    add r4, r5
    sub r5, r2
    cmp/pz r2
    mov.l @(16, r7), r5
    bt      .L_06030660
    neg r2, r2
.L_06030660:
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_06030672
    mov r4, r3
    shll r4
    add r4, r3
    cmp/gt r3, r2
    bt      .L_06030672
    add r4, r5
.L_06030672:
    mov.w   DAT_06030680, r4
    add r4, r5
    mov.l   .L_06030688, r3
    mov #0x0, r4
    mov.w r5, @r3
    bra     .L_06030B68
    mov.l @(16, r7), r5

    .global DAT_06030680
DAT_06030680:
    .2byte  0x4000
    .2byte  0x0000
.L_06030684:
    .4byte  sym_06063E9C
.L_06030688:
    .4byte  sym_06030FBC
.L_0603068C:
    mov #0x2, r4
    tst r4, r12
    mov.l   .L_060306CC, r7
    mov #0x1, r13
    bf      .L_0603069A
    mov.l   .L_060306D0, r7
    mov #0x3, r13
.L_0603069A:
    mov.w   DAT_060306c8, r4
    mov.l @(16, r7), r5
    mov.l @(48, r14), r2
    sub r5, r2
    cmp/pz r2
    bt      .L_060306A8
    neg r2, r2
.L_060306A8:
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_060306BA
    mov r4, r3
    shll r4
    add r4, r3
    cmp/gt r3, r2
    bt      .L_060306BA
    add r4, r5
.L_060306BA:
    mov.w   DAT_060306c8, r4
    add r4, r5
    mov.l   .L_060306D4, r3
    mov.w r5, @r3
    mov.l @(16, r7), r5
    bra     .L_06030B68
    mov r13, r4

    .global DAT_060306c8
DAT_060306c8:
    .2byte  0x4000
    .2byte  0x0000
.L_060306CC:
    .4byte  sym_06063EB0
.L_060306D0:
    .4byte  sym_06063ED8
.L_060306D4:
    .4byte  sym_06030FBC
.L_060306D8:
    mov #0x1, r4
    mov.l   .L_06030718, r7
    mov #0x0, r13
    tst r4, r12
    bf      .L_060306E6
    mov.l   .L_0603071C, r7
    mov #0x2, r13
.L_060306E6:
    mov.w   DAT_06030714, r4
    mov.l @(16, r7), r5
    mov.l @(48, r14), r2
    sub r5, r2
    cmp/pz r2
    bt      .L_060306F4
    neg r2, r2
.L_060306F4:
    extu.w r2, r2
    cmp/gt r2, r4
    bt/s    .L_06030706
    mov r4, r3
    shll r4
    add r4, r3
    cmp/gt r3, r2
    bt      .L_06030706
    add r4, r5
.L_06030706:
    mov.w   DAT_06030716, r4
    add r4, r5
    mov.l   .L_06030720, r3
    mov.w r5, @r3
    mov.l @(16, r7), r5
    bra     .L_06030B68
    mov r13, r4

    .global DAT_06030714
DAT_06030714:
    .2byte  0x4000

    .global DAT_06030716
DAT_06030716:
    .2byte  0xC000
.L_06030718:
    .4byte  sym_06063E9C
.L_0603071C:
    .4byte  sym_06063EC4
.L_06030720:
    .4byte  sym_06030FBC
.L_06030724:
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    rts
    mov.l @r15+, r12
.L_0603072E:
    mov.w   DAT_06030742, r1
    add r14, r1
    mov.l @r1, r2
    cmp/eq r2, r5
    bf      .L_06030744
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    rts
    mov.l @r15+, r12

    .global DAT_06030742
DAT_06030742:
    .2byte  0x0080
.L_06030744:
    mov.l r5, @r1
    mov.l r5, @-r15
    mov.l   .L_06030754, r2
    shll2 r4
    add r4, r2
    mov.l @r2, r1
    jmp @r1
    mov #0x0, r12
.L_06030754:
    .4byte  sym_06030F1C

    .global loc_06030758
loc_06030758:
    mov.l   .L_06030780, r0
    mov #0x8, r5
    mov.b r5, @r0
    mov.l   .L_06030784, r0
    mov #0x1, r5
    mov.b r5, @r0
    mov.w   .L_0603077A, r5
    mov.w   .L_0603077C, r0
    mov.l @(8, r14), r6
    mov #0x64, r2
    cmp/ge r6, r2
    mov.l @(r0, r14), r2
    bt      .L_06030774
    or r5, r2
.L_06030774:
    mov.l r2, @(r0, r14)
    bra     .L_06030808
    mov.l @(16, r7), r6
.L_0603077A:
    .2byte  0x0011
.L_0603077C:
    .2byte  0x0214
    .2byte  0x0000
.L_06030780:
    .4byte  sym_0607866D
.L_06030784:
    .4byte  sym_06089595

    .global loc_06030788
loc_06030788:
    mov.l   .L_060307B0, r0
    mov #0x4, r5
    mov.b r5, @r0
    mov.l   .L_060307B4, r0
    mov #0x1, r5
    mov.b r5, @r0
    mov.w   .L_060307AA, r5
    mov.w   .L_060307AC, r0
    mov.l @(8, r14), r6
    mov #0x64, r2
    cmp/ge r6, r2
    mov.l @(r0, r14), r2
    bt      .L_060307A4
    or r5, r2
.L_060307A4:
    mov.l r2, @(r0, r14)
    bra     .L_06030808
    mov.l @(16, r7), r6
.L_060307AA:
    .2byte  0x0022
.L_060307AC:
    .2byte  0x0214
    .2byte  0x0000
.L_060307B0:
    .4byte  sym_0607866D
.L_060307B4:
    .4byte  sym_06089595

    .global loc_060307B8
loc_060307B8:
    mov.l   .L_060307E0, r0
    mov #0x2, r5
    mov.b r5, @r0
    mov.l   .L_060307E4, r0
    mov #0x1, r5
    mov.b r5, @r0
    mov.w   .L_060307DA, r5
    mov.w   .L_060307DC, r0
    mov.l @(8, r14), r6
    mov #0x64, r2
    cmp/ge r6, r2
    mov.l @(r0, r14), r4
    bt      .L_060307D4
    or r5, r4
.L_060307D4:
    mov.l r4, @(r0, r14)
    bra     .L_06030808
    mov.l @(16, r7), r6
.L_060307DA:
    .2byte  0x0044
.L_060307DC:
    .2byte  0x0214
    .2byte  0x0000
.L_060307E0:
    .4byte  sym_0607866D
.L_060307E4:
    .4byte  sym_06089595

    .global loc_060307E8
loc_060307E8:
    mov.l   .L_06030884, r0
    mov #0x1, r5
    mov.b r5, @r0
    mov.l   .L_06030888, r0
    mov #0x1, r5
    mov.b r5, @r0
    mov.w   .L_06030878, r5
    mov.w   .L_0603087A, r0
    mov.l @(8, r14), r6
    mov #0x64, r2
    cmp/ge r6, r2
    mov.l @(r0, r14), r4
    bt      .L_06030804
    or r5, r4
.L_06030804:
    mov.l r4, @(r0, r14)
    mov.l @(16, r7), r6
.L_06030808:
    mov.l @(40, r14), r5
    mov.w @(14, r7), r0
    mov r0, r3
    mov r5, r4
    mov.l r3, @-r15
    sub r6, r4
    mov #0x1, r1
    shll16 r1
    exts.w r4, r4
    shlr r1
    cmp/pz r4
    bt      .L_06030822
    add r1, r4
.L_06030822:
    shlr r1
    cmp/ge r4, r1
    bt      .L_0603082C
    shll r1
    sub r1, r4
.L_0603082C:
    mov r4, r1
    shar r1
    mov.w   .L_0603087C, r0
    shar r1
    add r1, r4
    mov.l r4, @(r0, r14)
    sub r4, r5
    add #-0x4, r0
    mov r5, r7
    mov.l r5, @(r0, r14)
    mov.w   .L_0603087E, r4
    add #0x8, r0
    mov.w r4, @(r0, r14)
    mov.w   .L_06030880, r0
    mov #0x0, r13
    mov.l @(r0, r14), r5
    tst r5, r5
    bf      .L_060308C4
    mov.w   .L_06030882, r0
    mov.l @(r0, r14), r0
    and #0xF, r0
    shll r0
    mov.l   .L_0603088C, r1
    mov.w @(r0, r1), r4
    mov.l   .L_06030890, r1
    mov.w @(r0, r1), r5
    mov.l @(8, r14), r0
    cmp/ge r4, r0
    bf      .L_0603089C
    mov.l   .L_06030894, r0
    mov.w @r0, r0
    tst r0, r0
    bf      .L_060308BC
    mov.l   .L_06030898, r0
    jsr @r0
    mov.l r7, @-r15
    bra     .L_060308C4
    mov.l @r15+, r7
.L_06030878:
    .2byte  0x0088
.L_0603087A:
    .2byte  0x0214
.L_0603087C:
    .2byte  0x024C
.L_0603087E:
    .2byte  0x000A
.L_06030880:
    .2byte  0x00BC
.L_06030882:
    .2byte  0x01D4
.L_06030884:
    .4byte  sym_0607866D
.L_06030888:
    .4byte  sym_06089595
.L_0603088C:
    .4byte  sym_06030F74
.L_06030890:
    .4byte  sym_06030F98
.L_06030894:
    .4byte  sym_06030FBE
.L_06030898:
    .4byte  force_steer_impact
.L_0603089C:
    cmp/ge r0, r5
    bt      .L_060308C4
    mov.l   .L_060308B4, r0
    mov.w @r0, r0
    tst r0, r0
    bf      .L_060308BC
    mov.l   .L_060308B8, r0
    jsr @r0
    mov.l r7, @-r15
    bra     .L_060308C4
    mov.l @r15+, r7
    .2byte  0x0000
.L_060308B4:
    .4byte  sym_06030FBE
.L_060308B8:
    .4byte  force_steer_calc
.L_060308BC:
    mov.l @(0, r14), r0
    mov.l   .L_06030924, r4
    or r4, r0
    mov.l r0, @(0, r14)
.L_060308C4:
    mov.l @r15+, r3
    mov.l @r15+, r4
    mov #0x1, r13
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r4, @-r15
    mov.l   .L_06030928, r1
    mov #0x34, r2
    muls.w r2, r3
    mov.l r13, @-r15
    sts macl, r2
    add r2, r1
    mov #0x1, r13
    mov.l @(16, r1), r8
    shll16 r13
    mov.l @(20, r1), r10
    mov.l @(16, r14), r5
    shll8 r13
    dmuls.l r8, r5
    mov.l @(24, r14), r6
    mov.l @(0, r1), r0
    sts mach, r4
    sts macl, r5
    tst r0, r13
    xtrct r4, r5
    shlr8 r0
    mov #0x0, r9
    and #0x1, r0
    bf/s    .L_06030906
    add r10, r5
    add r6, r5
    mov #0x1, r9
.L_06030906:
    mov #0x0, r6
    cmp/pl r5
    bt      .L_0603090E
    mov #0x1, r6
.L_0603090E:
    mov #0x0, r4
    cmp/eq r0, r6
    bt      .L_06030916
    mov #0x1, r4
.L_06030916:
    mov.l r4, @-r15
    mov r8, r0
    cmp/eq #0x0, r0
    bf/s    .L_0603092C
    mov r9, r0
    bra     .L_06030934
    nop
.L_06030924:
    .4byte  0x08000000
.L_06030928:
    .4byte  sym_060A6000
.L_0603092C:
    cmp/eq #0x0, r0
    bf      .L_0603095C
    bra     .L_06030942
    nop
.L_06030934:
    mov.l @(24, r14), r5
    add r10, r5
    cmp/pl r5
    bt      .L_0603093E
    neg r5, r5
.L_0603093E:
    bra     .L_06030DFE
    nop
.L_06030942:
    neg r10, r4
    mov.l   .L_06030958, r0
    jsr @r0
    mov r8, r5
    mov.l @(16, r14), r5
    sub r0, r5
    cmp/pl r5
    bt      .L_06030954
    neg r5, r5
.L_06030954:
    bra     .L_06030DFE
    nop
.L_06030958:
    .4byte  fpdiv_setup
.L_0603095C:
    mov.l @(24, r14), r2
    add r10, r2
    neg r8, r3
    dmuls.l r2, r3
    mov #0x1, r5
    shll16 r5
    mov.w   .L_060309AA, r4
    sts mach, r2
    sts macl, r3
    cmp/gt r2, r4
    bf      .L_06030978
    neg r4, r4
    cmp/gt r4, r2
    bt      .L_060309B0
.L_06030978:
    shll8 r2
    shlr16 r3
    shlr8 r3
    or r2, r3
    mov.l @(16, r14), r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    add r3, r4
    neg r8, r2
    dmuls.l r2, r2
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    mov.l   .L_060309AC, r0
    jsr @r0
    add r2, r5
    shll8 r0
    bra     .L_060309C6
    nop
.L_060309AA:
    .2byte  0x7FFF
.L_060309AC:
    .4byte  fpdiv_setup
.L_060309B0:
    xtrct r2, r3
    mov.l @(16, r14), r4
    add r3, r4
    neg r8, r2
    dmuls.l r2, r2
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    mov.l   .L_060309F8, r0
    jsr @r0
    add r2, r5
.L_060309C6:
    mov r0, r2
    neg r8, r3
    dmuls.l r3, r2
    neg r10, r5
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    add r2, r5
    mov.l @(16, r14), r2
    mov.l @(24, r14), r3
    sub r2, r0
    sub r3, r5
    cmp/pl r0
    bt      .L_060309E4
    neg r0, r0
.L_060309E4:
    cmp/pl r5
    bt      .L_060309EA
    neg r5, r5
.L_060309EA:
    cmp/gt r0, r5
    bt      .L_060309FC
    shar r5
    shar r5
    bra     .L_06030A02
    add r0, r5
    .2byte  0x0000
.L_060309F8:
    .4byte  fpdiv_setup
.L_060309FC:
    shar r0
    shar r0
    add r0, r5
.L_06030A02:
    bra     .L_06030DFE
    nop

    .global sym_06030A06
sym_06030A06:
    mov.l   .L_06030A48, r1
    mov.l @r1, r3
    mov.w   .L_06030A3E, r0
    mov.w @(r0, r3), r4
    tst r4, r4
    bt      .L_06030A3A
    add #-0x1, r4
    tst r4, r4
    bf/s    .L_06030A3A
    mov.w r4, @(r0, r3)
    mov.l   .L_06030A4C, r5
    mov.w   DAT_06030a40, r6
    mov.w   .L_06030A42, r0
    add r3, r6
    mov.l r5, @r6
    mov.l @(r0, r3), r4
    mov.l   .L_06030A50, r5
    tst r5, r4
    bt      .L_06030A3A
    mov.w   DAT_06030a44, r0
    mov.w   DAT_06030a46, r2
    add r3, r2
    mov.l @r2, r4
    mov.l r4, @(r0, r3)
    mov.l @(48, r3), r5
    mov.l r5, @(40, r3)
.L_06030A3A:
    rts
    nop
.L_06030A3E:
    .2byte  0x0250

    .global DAT_06030a40
DAT_06030a40:
    .2byte  0x0080
.L_06030A42:
    .2byte  0x0160

    .global DAT_06030a44
DAT_06030a44:
    .2byte  0x01E4

    .global DAT_06030a46
DAT_06030a46:
    .2byte  0x01EC
.L_06030A48:
    .4byte  sym_0607E940
.L_06030A4C:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_06030A50:
    .4byte  0x00200000                  /* Work RAM Low base */
    .4byte  0x53E34321
    .4byte  0x1E3352E5
    .4byte  0xD109D30A
    .4byte  0x11211321
    .4byte  0xD109D30A
    .4byte  0x11211321
    .4byte  0x9409D109
    .4byte  0x21429406
    .4byte  0xD1082142
    .4byte  0x4F266EF6
    .4byte  0x6DF6000B
    .4byte  0x6CF60006
    .4byte  sym_06063E4C
    .4byte  sym_06063E60
    .4byte  sym_06063E74
    .4byte  sym_06063E88
    .4byte  sym_0607EAE8
    .4byte  sym_0607EAEC
.L_06030A9C:
    mov.l r6, @-r15
    mov.l r7, @-r15
    mov.l @r15+, r7
    mov.l @r15+, r6
    mov.l @(40, r14), r5
    mov r5, r4
    sub r6, r4
    mov.w   DAT_06030b24, r1
    exts.w r4, r4
    extu.w r1, r1
    cmp/pl r4
    bt      .L_06030AB6
    add r1, r4
.L_06030AB6:
    shlr r1
    cmp/ge r4, r1
    bt      .L_06030AC0
    shll r1
    sub r1, r4
.L_06030AC0:
    mov r4, r1
    shar r1
    shar r1
    add r1, r4
    mov.w   DAT_06030b26, r0
    mov.l r4, @(r0, r14)
    sub r4, r5
    add #-0x4, r0
    mov.l r5, @(r0, r14)
    mov.w   DAT_06030b28, r4
    add #0x8, r0
    mov.w r4, @(r0, r14)
    mov.l   .L_06030B30, r0
    mov #0xF, r5
    mov.b r5, @r0
    mov.l   .L_06030B34, r0
    mov #0x1, r1
    mov.b r1, @r0
    mov.w   DAT_06030b2a, r0
    mov.w   .L_06030B2C, r1
    mov.l @(r0, r14), r2
    or r1, r2
    mov.l r2, @(r0, r14)
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.w @(14, r7), r0
    mov.l   .L_06030B38, r1
    mov #0x34, r2
    muls.w r2, r0
    sts macl, r2
    add r2, r1
    mov.l @(16, r1), r8
    mov.l   .L_06030B3C, r2
    mov.w @r2, r2
    mov.l   .L_06030B40, r0
    mov.l @(20, r1), r10
    mov.l r6, @-r15
    mov.l @r1, r13
    mov.l   .L_06030B44, r6
    mov #0x0, r9
    tst r6, r13
    bf      .L_06030B18
    mov #0x1, r9
.L_06030B18:
    tst r2, r2
    bf      .L_06030B48
    jsr @r0
    mov.l r5, @-r15
    bra     .L_06030B50
    mov.l @r15+, r5

    .global DAT_06030b24
DAT_06030b24:
    .2byte  0x8000

    .global DAT_06030b26
DAT_06030b26:
    .2byte  0x024C

    .global DAT_06030b28
DAT_06030b28:
    .2byte  0x000A

    .global DAT_06030b2a
DAT_06030b2a:
    .2byte  0x0214
.L_06030B2C:
    .2byte  0x00CC
    .2byte  0x0000
.L_06030B30:
    .4byte  sym_0607866D
.L_06030B34:
    .4byte  sym_06089595
.L_06030B38:
    .4byte  sym_060A6000
.L_06030B3C:
    .4byte  sym_06030FBE
.L_06030B40:
    .4byte  force_steer_impact
.L_06030B44:
    .4byte  0x01000000                  /* MINIT — primary SH-2 init comm */
.L_06030B48:
    mov.l   .L_06030B60, r0
    mov.l @(0, r14), r2
    or r0, r2
    mov.l r2, @(0, r14)
.L_06030B50:
    mov.l   .L_06030B64, r0
    mov #0x0, r3
    mov.w r5, @r0
    mov.l r3, @-r15
    mov.l r3, @-r15
    bra     .L_06030CBE
    nop
    .2byte  0x0000
.L_06030B60:
    .4byte  0x08000000
.L_06030B64:
    .4byte  sym_06030FBC
.L_06030B68:
    mov #0x0, r13
    mov.l @(40, r14), r0
    mov r5, r6
    sub r0, r6
    exts.w r6, r6
    mov.l   .L_06030B84, r2
    mov.l   .L_06030B88, r3
    cmp/ge r6, r3
    bt      .L_06030B8C
    cmp/ge r2, r6
    bt      .L_06030B8C
    bra     .L_0603072E
    nop
    .2byte  0x0000
.L_06030B84:
    .4byte  0x00006FFF
.L_06030B88:
    .4byte  0x00001000                  /* 0.0625 (16.16 fixed-point) */
.L_06030B8C:
    neg r2, r2
    neg r3, r3
    cmp/ge r3, r6
    bt      .L_06030B9C
    cmp/ge r6, r2
    bt      .L_06030B9C
    bra     .L_0603072E
    nop
.L_06030B9C:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l   .L_06030BC4, r0
    mov #0x1, r9
    mov.b r9, @r0
    mov.w   .L_06030BC2, r8
    mov #0x4, r9
    add r14, r8
    mov.w r9, @r8
    mov r4, r0
    cmp/eq #0x0, r0
    bt      .L_06030BC8
    cmp/eq #0x1, r0
    bt      .L_06030C08
    cmp/eq #0x2, r0
    bt      .L_06030BE8
    bra     .L_06030C28
    nop
.L_06030BC2:
    .2byte  0x0150
.L_06030BC4:
    .4byte  sym_06089595
.L_06030BC8:
    mov.l @(0, r14), r0
    mov.w   .L_06030BE0, r4
    or r4, r0
    mov.l r0, @(0, r14)
    mov #0x0, r4
    mov.w   .L_06030BE2, r0
    mov.l r4, @(r0, r14)
    mov.l   .L_06030BE4, r1
    mov.w @(14, r1), r0
    mov r0, r3
    bra     .L_06030C48
    mov.l @(16, r1), r4
.L_06030BE0:
    .2byte  0x0040
.L_06030BE2:
    .2byte  0x0260
.L_06030BE4:
    .4byte  sym_06063E9C
.L_06030BE8:
    mov.l @(0, r14), r0
    mov.w   .L_06030C00, r4
    or r4, r0
    mov.l r0, @(0, r14)
    mov #0x1, r4
    mov.w   .L_06030C02, r0
    mov.l r4, @(r0, r14)
    mov.l   .L_06030C04, r1
    mov.w @(14, r1), r0
    mov r0, r3
    bra     .L_06030C48
    mov.l @(16, r1), r4
.L_06030C00:
    .2byte  0x0100
.L_06030C02:
    .2byte  0x0260
.L_06030C04:
    .4byte  sym_06063EC4
.L_06030C08:
    mov.l @(0, r14), r0
    mov.w   .L_06030C20, r4
    or r4, r0
    mov.l r0, @(0, r14)
    mov #0x2, r4
    mov.w   .L_06030C22, r0
    mov.l r4, @(r0, r14)
    mov.l   .L_06030C24, r1
    mov.w @(14, r1), r0
    mov r0, r3
    bra     .L_06030CDC
    mov.l @(16, r1), r4
.L_06030C20:
    .2byte  0x0080
.L_06030C22:
    .2byte  0x0260
.L_06030C24:
    .4byte  sym_06063EB0
.L_06030C28:
    mov.l @(0, r14), r0
    mov.w   .L_06030C40, r4
    or r4, r0
    mov.l r0, @(0, r14)
    mov #0x3, r4
    mov.w   .L_06030C42, r0
    mov.l r4, @(r0, r14)
    mov.l   .L_06030C44, r1
    mov.w @(14, r1), r0
    mov r0, r3
    bra     .L_06030CDC
    mov.l @(16, r1), r4
.L_06030C40:
    .2byte  0x0200
.L_06030C42:
    .2byte  0x0260
.L_06030C44:
    .4byte  sym_06063ED8
.L_06030C48:
    mov.l r4, @-r15
    mov.l   .L_06030CCC, r2
    mov.b @r2, r5
    tst r5, r5
    bf      .L_06030C56
    mov #0x5, r6
    mov.b r6, @r2
.L_06030C56:
    mov.l @(40, r14), r5
    sub r4, r5
    cmp/pz r5
    bt      .L_06030C60
    neg r5, r5
.L_06030C60:
    mov.w   DAT_06030cca, r6
    cmp/gt r5, r6
    bt      .L_06030C72
    mov r6, r2
    shll r6
    add r6, r2
    cmp/gt r2, r5
    bt      .L_06030C72
    add r6, r4
.L_06030C72:
    exts.w r4, r4
    mov.l r4, @(48, r14)
    mov.l r4, @(40, r14)
    mov.l   .L_06030CD0, r1
    mov #0x34, r2
    muls.w r2, r3
    mov.l r13, @-r15
    sts macl, r2
    add r2, r1
    mov #0x1, r13
    mov.l @(16, r1), r8
    shll16 r13
    mov.l @(20, r1), r10
.L_06030C8C:
    mov.l @(16, r14), r5
    shll8 r13
    dmuls.l r8, r5
    mov.l @(24, r14), r6
    mov.l @(0, r1), r0
    sts mach, r4
    sts macl, r5
    tst r0, r13
    xtrct r4, r5
    shlr8 r0
    mov #0x0, r9
    and #0x1, r0
    bf/s    .L_06030CAC
    add r10, r5
    add r6, r5
    mov #0x1, r9
.L_06030CAC:
    mov #0x0, r6
    cmp/pl r5
    bt      .L_06030CB4
    mov #0x1, r6
.L_06030CB4:
    mov #0x0, r4
    cmp/eq r0, r6
    bt      .L_06030CBC
    mov #0x1, r4
.L_06030CBC:
    mov.l r4, @-r15
.L_06030CBE:
    mov r8, r0
    cmp/eq #0x0, r0
    bf/s    .L_06030CD4
    mov r9, r0
    bra     .L_06030D2C
    nop

    .global DAT_06030cca
DAT_06030cca:
    .2byte  0x4000
.L_06030CCC:
    .4byte  sym_0602FD9B
.L_06030CD0:
    .4byte  sym_060A6000
.L_06030CD4:
    cmp/eq #0x0, r0
    bf      .L_06030D54
    bra     .L_06030D3A
    nop
.L_06030CDC:
    mov.l r4, @-r15
    mov.l   .L_06030D24, r2
    mov.b @r2, r5
    tst r5, r5
    bf      .L_06030CEA
    mov #0x5, r6
    mov.b r6, @r2
.L_06030CEA:
    mov.l @(40, r14), r5
    sub r4, r5
    cmp/pz r5
    bt      .L_06030CF4
    neg r5, r5
.L_06030CF4:
    mov.w   DAT_06030d22, r6
    cmp/gt r5, r6
    bt      .L_06030D06
    mov r6, r2
    shll r6
    add r6, r2
    cmp/gt r2, r5
    bt      .L_06030D06
    add r6, r4
.L_06030D06:
    exts.w r4, r4
    mov.l r4, @(48, r14)
    mov.l r4, @(40, r14)
    mov.l   .L_06030D28, r1
    mov #0x34, r2
    mov.l r13, @-r15
    muls.w r2, r3
    sts macl, r2
    add r2, r1
    mov #0x1, r13
    mov.l @(16, r1), r8
    shll16 r13
    bra     .L_06030C8C
    mov.l @(20, r1), r10

    .global DAT_06030d22
DAT_06030d22:
    .2byte  0x4000
.L_06030D24:
    .4byte  sym_0602FD9C
.L_06030D28:
    .4byte  sym_060A6000
.L_06030D2C:
    mov.l @(24, r14), r5
    add r10, r5
    cmp/pl r5
    bt      .L_06030D36
    neg r5, r5
.L_06030D36:
    bra     .L_06030DFE
    nop
.L_06030D3A:
    neg r10, r4
    mov.l   .L_06030D50, r0
    jsr @r0
    mov r8, r5
    mov.l @(16, r14), r5
    sub r0, r5
    cmp/pl r5
    bt      .L_06030D4C
    neg r5, r5
.L_06030D4C:
    bra     .L_06030DFE
    nop
.L_06030D50:
    .4byte  fpdiv_setup
.L_06030D54:
    mov.l @(24, r14), r2
    add r10, r2
    neg r8, r3
    dmuls.l r2, r3
    mov #0x1, r5
    shll16 r5
    mov.w   DAT_06030da2, r4
    sts mach, r2
    sts macl, r3
    cmp/gt r2, r4
    bf      .L_06030D70
    neg r4, r4
    cmp/gt r4, r2
    bt      .L_06030DA8
.L_06030D70:
    shll8 r2
    shlr16 r3
    shlr8 r3
    or r2, r3
    mov.l @(16, r14), r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    add r3, r4
    neg r8, r2
    dmuls.l r2, r2
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    mov.l   .L_06030DA4, r0
    jsr @r0
    add r2, r5
    shll8 r0
    bra     .L_06030DBE
    nop

    .global DAT_06030da2
DAT_06030da2:
    .2byte  0x7FFF
.L_06030DA4:
    .4byte  fpdiv_setup
.L_06030DA8:
    xtrct r2, r3
    mov.l @(16, r14), r4
    add r3, r4
    neg r8, r2
    dmuls.l r2, r2
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    mov.l   .L_06030DF0, r0
    jsr @r0
    add r2, r5
.L_06030DBE:
    mov r0, r2
    neg r8, r3
    dmuls.l r3, r2
    neg r10, r5
    sts mach, r3
    sts macl, r2
    xtrct r3, r2
    add r2, r5
    mov.l @(16, r14), r2
    mov.l @(24, r14), r3
    sub r2, r0
    sub r3, r5
    cmp/pl r0
    bt      .L_06030DDC
    neg r0, r0
.L_06030DDC:
    cmp/pl r5
    bt      .L_06030DE2
    neg r5, r5
.L_06030DE2:
    cmp/gt r0, r5
    bt      .L_06030DF4
    shar r5
    shar r5
    bra     .L_06030DFA
    add r0, r5
    .2byte  0x0000
.L_06030DF0:
    .4byte  fpdiv_setup
.L_06030DF4:
    shar r0
    shar r0
    add r0, r5
.L_06030DFA:
    bra     .L_06030DFE
    nop
.L_06030DFE:
    mov.l   .L_06030E28, r9
    mov.l @r15+, r3
    mov.l @r15+, r13
    mov.w @r9, r9
    mov.l @r15+, r2
    tst r13, r13
    bt      .L_06030E34
    mov.l @(48, r14), r4
    mov.l   .L_06030E2C, r0
    mov.l   .L_06030E30, r10
    jsr @r0
    sub r2, r4
    cmp/pz r0
    bt      .L_06030E1C
    neg r0, r0
.L_06030E1C:
    dmuls.l r0, r10
    sts mach, r0
    sts macl, r2
    bra     .L_06030E36
    xtrct r0, r2
    .2byte  0x0000
.L_06030E28:
    .4byte  sym_06030FBC
.L_06030E2C:
    .4byte  sin_lookup
.L_06030E30:
    .4byte  0x00038000
.L_06030E34:
    mov.l   .L_06030E44, r2
.L_06030E36:
    cmp/pl r3
    bt/s    .L_06030E48
    mov r9, r4
    add r5, r2
    bra     .L_06030E52
    nop
    .2byte  0x0000
.L_06030E44:
    .4byte  0x00013333
.L_06030E48:
    sub r5, r2
    cmp/pl r2
    bt      .L_06030E52
    .byte   0xA0, 0x3D    /* bra 0x06030ECC (external) */
    nop
.L_06030E52:
    neg r4, r4
    mov r4, r10
    mov r2, r3
    mov r3, r9
    mov.l @(16, r14), r5
    mov.l @(24, r14), r6
    mov.l r5, @(56, r14)
    mov.l r6, @(60, r14)
    .byte   0xD0, 0x13    /* mov.l .L_pool_06030EB0, r0 */
