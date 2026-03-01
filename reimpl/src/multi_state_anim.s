
    .section .text.FUN_060104E0


    .global multi_state_anim
    .type multi_state_anim, @function
multi_state_anim:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_06010518, r8
    mov #0x0, r9
    mov #0x1, r10
    mov.l   .L_0601053C, r12
    mov.l   .L_0601051C, r13
    mov.l   .L_0601050C, r14
    mov r4, r11
    mov.l   .L_06010540, r0
    bra     .L_06010550
    mov.b @r0, r0
.L_06010504:
    bra     .L_06010570
    mov #0x5, r4
    .4byte  0x00C0FFFF
.L_0601050C:
    .4byte  sym_0607EADC
    .4byte  sym_06063D9C
    .4byte  0x0000FFFF
.L_06010518:
    .4byte  sym_0607EAB8
.L_0601051C:
    .4byte  sym_06078868
    .4byte  dma_transfer
    .4byte  sym_0605D084
    .4byte  sym_06078884
    .4byte  sym_0605D060
    .4byte  sym_0605D05C
    .4byte  sym_0605D088
    .4byte  sym_06078880
.L_0601053C:
    .4byte  sym_060788A8
.L_06010540:
    .4byte  sym_0605AB16
.L_06010544:
    bra     .L_06010570
    mov #0x7, r4
.L_06010548:
    bra     .L_06010570
    mov #0x9, r4
.L_0601054C:
    bra     .L_06010570
    mov #0x3, r4
.L_06010550:
    cmp/eq #0x1, r0
    bt      .L_06010504
    cmp/eq #0x2, r0
    bt      .L_06010504
    cmp/eq #0x3, r0
    bt      .L_06010544
    cmp/eq #0x4, r0
    bt      .L_06010504
    cmp/eq #0x5, r0
    bt      .L_06010544
    cmp/eq #0x6, r0
    bt      .L_06010544
    cmp/eq #0x7, r0
    bt      .L_06010548
    bra     .L_0601054C
    nop
.L_06010570:
    mov.l   .L_0601064C, r0
    mov.b @r0, r0
    cmp/eq #0x7, r0
    bf      .L_0601057A
    mov #0xB, r4
.L_0601057A:
    mov.l   .L_0601064C, r0
    mov.b @r0, r0
    cmp/eq #0xF, r0
    bf      .L_06010584
    mov #0xD, r4
.L_06010584:
    mov.l   .L_06010650, r5
    extu.w r11, r2
    mov.l   .L_06010654, r3
    and r3, r2
    tst r2, r2
    bt      .L_06010612
    mov.l   .L_06010658, r3
    mov.l r3, @r5
    mov.l @r14, r2
    add #0x1, r2
    mov r2, r3
    mov.l r2, @r14
    cmp/gt r4, r3
    bf      .L_060105A2
    mov.l r9, @r14
.L_060105A2:
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_060105DE
    extu.b r9, r3
    mov #0x0, r2
    mov.b r3, @r12
    mov #0x0, r3
    add #-0x8, r15
    mov.l r2, @-r15
    mov.l   .L_0601065C, r2
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l   .L_06010660, r3
    mov.l r3, @-r15
    mov r15, r2
    mov.l   .L_06010664, r3
    add #0x10, r2
    jsr @r3
    mov.l r2, @-r15
    mov.l   .L_06010668, r2
    jsr @r2
    nop
    mov.l   .L_0601066C, r3
    mov.l r0, @r3
    mov.l @r14, r2
    mov.l   .L_06010670, r3
    mov.l r2, @r3
    bra     .L_06010690
    nop
.L_060105DE:
    extu.b r10, r2
    mov #0x0, r3
    mov.b r2, @r12
    add #-0x8, r15
    mov #0x0, r2
    mov.l r3, @-r15
    mov.l   .L_0601065C, r3
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l   .L_06010660, r2
    mov.l r2, @-r15
    mov r15, r3
    mov.l   .L_06010664, r2
    add #0x10, r3
    jsr @r2
    mov.l r3, @-r15
    mov.l   .L_06010668, r3
    jsr @r3
    nop
    mov.l   .L_06010674, r3
    mov.l r0, @r3
    mov.l @r14, r2
    mov.l   .L_06010678, r3
    mov.l r2, @r3
    bra     .L_06010690
    nop
.L_06010612:
    extu.w r11, r2
    mov.w   DAT_0601064a, r3
    and r3, r2
    tst r2, r2
    bt      .L_06010690
    mov.l   .L_0601067C, r3
    mov.l r3, @r5
    mov.l @r14, r2
    add #-0x1, r2
    mov r2, r3
    mov.l r2, @r14
    cmp/pz r3
    bt      .L_0601062E
    mov.l r4, @r14
.L_0601062E:
    mov.l   .L_06010680, r4
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06010684
    extu.b r9, r3
    mov.b r3, @r12
    mov.l   .L_0601066C, r3
    mov.l r4, @r3
    mov.l @r14, r2
    mov.l   .L_06010670, r3
    mov.l r2, @r3
    bra     .L_06010690
    nop

    .global DAT_0601064a
DAT_0601064a:
    .2byte  0x4000
.L_0601064C:
    .4byte  sym_0605AB17
.L_06010650:
    .4byte  sym_0607889C
.L_06010654:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_06010658:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_0601065C:
    .4byte  0x40280000
.L_06010660:
    .4byte  0x40F00000
.L_06010664:
    .4byte  sym_060359E4
.L_06010668:
    .4byte  sym_060357B8
.L_0601066C:
    .4byte  sym_06078894
.L_06010670:
    .4byte  sym_060788A0
.L_06010674:
    .4byte  sym_06078898
.L_06010678:
    .4byte  sym_060788A4
.L_0601067C:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_06010680:
    .4byte  0xFFF40000
.L_06010684:
    mov.b r10, @r12
    mov.l   .L_06010738, r3
    mov.l r4, @r3
    mov.l @r14, r2
    mov.l   .L_0601073C, r3
    mov.l r2, @r3
.L_06010690:
    mov.l @r14, r2
    mov.l r2, @r13
    mov r2, r3
    and r10, r3
    mov.l r3, @r8
    mov #0xA, r3
    mov.l @r13, r2
    cmp/hs r3, r2
    bt      .L_060106CE
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_060106BA
    mov.w   .L_06010736, r6
    mov.l @r13, r5
    shll2 r5
    mov.l   .L_06010740, r3
    add r3, r5
    mov.l   .L_06010744, r4
    bra     .L_060106C8
    mov.l @r5, r5
.L_060106BA:
    mov.w   .L_06010736, r6
    mov.l @r13, r5
    shll2 r5
    mov.l   .L_06010740, r3
    add r3, r5
    mov.l @r5, r5
    mov.l   .L_06010748, r4
.L_060106C8:
    mov.l   .L_0601074C, r2
    jsr @r2
    mov.l @r4, r4
.L_060106CE:
    extu.w r11, r11
    mov.l   .L_06010750, r3
    and r3, r11
    tst r11, r11
    bt      .L_06010724
    mov #0xC, r2
    mov.l @r13, r3
    cmp/hs r2, r3
    bt      .L_060106F0
    mov.l @r13, r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov.l   .L_06010754, r3
    add r3, r5
    bra     .L_06010700
    mov #0x40, r6
.L_060106F0:
    mov #0x40, r6
    mov.l @r13, r5
    add #-0x2, r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov.l   .L_06010754, r3
    add r3, r5
.L_06010700:
    mov.l @r8, r4
    shll r4
    add #0x23, r4
    shll2 r4
    shll2 r4
    shll r4
    mov.l   .L_06010758, r2
    add r2, r4
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_0601075C, r2
    jmp @r2
    mov.l @r15+, r14
.L_06010724:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06010736:
    .2byte  0x00C0
.L_06010738:
    .4byte  sym_06078898
.L_0601073C:
    .4byte  sym_060788A4
.L_06010740:
    .4byte  sym_0605D05C
.L_06010744:
    .4byte  sym_06078880
.L_06010748:
    .4byte  sym_06078884
.L_0601074C:
    .4byte  dma_transfer
.L_06010750:
    .4byte  0x0000C000                  /* bits 15:14 mask */
.L_06010754:
    .4byte  sym_0605CA9C
.L_06010758:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 */
.L_0601075C:
    .4byte  memcpy_word_idx
