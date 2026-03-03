	.text
    .global force_steer_calc
force_steer_calc:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_060084A8, r14
    mov.w   DAT_060084a2, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_0600845A
    mov.l   .L_060084AC, r3
    mov.l   .L_060084B0, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0600843C
    mov.l   .L_060084B4, r5
    mov.l   .L_060084B8, r3
    jsr @r3
    mov #0x0, r4
.L_0600843C:
    mov.l @r14, r3
    add #0x1, r3
    mov.b @r3, r0
    and #0xFE, r0
    or #0x1, r0
    mov.b r0, @r3
    mov.l @r14, r2
    mov.w   DAT_060084a4, r3
    mov.w   DAT_060084a6, r0
    mov.l r3, @(r0, r2)
    mov.l   .L_060084BC, r4
    mov.l @r4, r4
    lds.l @r15+, pr
    bra     race_config_physics
    mov.l @r15+, r14
.L_0600845A:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global force_steer_impact
force_steer_impact:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_060084A8, r14
    mov.w   DAT_060084a2, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_060084C4
    mov.l   .L_060084AC, r3
    mov.l   .L_060084B0, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_06008484
    mov.l   .L_060084B4, r5
    mov.l   .L_060084B8, r3
    jsr @r3
    mov #0x0, r4
.L_06008484:
    mov.l @r14, r3
    add #0x1, r3
    mov.b @r3, r0
    and #0xFE, r0
    or #0x1, r0
    mov.b r0, @r3
    mov.l @r14, r2
    mov.w   DAT_060084a4, r3
    mov.w   DAT_060084a6, r0
    mov.l r3, @(r0, r2)
    mov.l   .L_060084C0, r4
    mov.l @r4, r4
    lds.l @r15+, pr
    bra     race_config_physics
    mov.l @r15+, r14

    .global DAT_060084a2
DAT_060084a2:
    .short  0x01BC

    .global DAT_060084a4
DAT_060084a4:
    .short  0x00CC

    .global DAT_060084a6
DAT_060084a6:
    .short  0x0214
.L_060084A8:
    .long  sym_0607E944
.L_060084AC:
    .long  sym_0607EBC4
.L_060084B0:
    .long  0x00020000
.L_060084B4:
    .long  0xAE1102FF
.L_060084B8:
    .long  sound_cmd_dispatch         /* sound command dispatcher */
.L_060084BC:
    .long  sym_060453B4
.L_060084C0:
    .long  sym_060453BC
.L_060084C4:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global race_config_physics
race_config_physics:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_06008564, r14
    mov.w   DAT_0600855e, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r2
    add #0x1, r2
    mov.l r2, @(r0, r3)
    mov #0x0, r2
    add #-0x10, r0
    mov.l @r14, r3
    mov.l r2, @(r0, r3)
    bsr     force_table_apply
    nop
    mov.l @r14, r2
    mov.l   .L_06008568, r3
    cmp/eq r3, r2
    bf      .L_06008558
    mov.l   .L_0600856C, r3
    mov.l   .L_06008570, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_06008558
    mov.l   .L_06008574, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_0600850E
    mov.l   .L_06008578, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bf      .L_06008558
.L_0600850E:
    mov #0x3, r3
    mov.l   .L_0600857C, r2
    mov #0x0, r5
    mov.w r3, @r2
    mov #0x7, r3
    mov.l   .L_06008580, r2
    mov.b r3, @r2
    mov #0x2, r3
    mov.l   .L_06008584, r2
    mov.l r3, @r2
    mov #0x1, r3
    mov.l   .L_06008588, r2
    mov.l r3, @r2
    mov.l   .L_0600858C, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_06008590, r2
    mov.l   .L_06008594, r3
    mov.l r2, @r3
    mov.l   .L_06008598, r2
    mov.l   .L_0600859C, r3
    mov.l r2, @r3
    mov.l   .L_060085A0, r2
    mov.l   .L_060085A4, r3
    mov.l r2, @r3
    mov.l   .L_060085A8, r2
    mov.l   .L_060085AC, r3
    mov.l r2, @r3
    mov #0x0, r2
    mov.l   .L_060085B0, r3
    mov.l r2, @r3
    mov.l @r14, r2
    mov.w   .L_06008560, r0
    mov.l @(r0, r2), r3
    exts.b r3, r3
    mov.l   .L_060085B4, r2
    mov.b r3, @r2
.L_06008558:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600855e
DAT_0600855e:
    .short  0x01D4
.L_06008560:
    .short  0x01BC
    .short  0xFFFF
.L_06008564:
    .long  sym_0607E944
.L_06008568:
    .long  sym_06078900
.L_0600856C:
    .long  sym_0607EBC4
.L_06008570:
    .long  0x00020000
.L_06008574:
    .long  sym_06078635
.L_06008578:
    .long  sym_0607ED8C
.L_0600857C:
    .long  sym_0605A016
.L_06008580:
    .long  sym_06078654
.L_06008584:
    .long  sym_06063E1C
.L_06008588:
    .long  sym_06059F30
.L_0600858C:
    .long  channel_nibble_config
.L_06008590:
    .long  0x00058000
.L_06008594:
    .long  sym_06063E24
.L_06008598:
    .long  0x0000F300
.L_0600859C:
    .long  sym_06063E34
.L_060085A0:
    .long  0x006E0000
.L_060085A4:
    .long  sym_06063E28
.L_060085A8:
    .long  0x00100000
.L_060085AC:
    .long  sym_06063E2C
.L_060085B0:
    .long  sym_06063E30
.L_060085B4:
    .long  sym_0607866C

    .global brake_force_apply
brake_force_apply:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_0600862C, r14
    mov.w   DAT_06008624, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_0600861E
    mov #0x46, r3
    mov.l   .L_06008630, r2
    mov.l r3, @r2
    mov.l @r14, r0
    mov.w   DAT_06008626, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf      .L_060085F6
    mov.l @r14, r2
    mov.w   .L_06008628, r0
    mov.b @(r0, r2), r0
    tst #0x80, r0
    bt      .L_060085F6
    mov.l @r14, r3
    mov r3, r2
    mov.l @(48, r2), r1
    mov.l r1, @(40, r3)
    mov.l @r14, r3
    mov r3, r2
    mov.w   DAT_0600862a, r0
    mov.l @(r0, r2), r1
    add #-0x8, r0
    mov.l r1, @(r0, r3)
.L_060085F6:
    bsr     .L_06008730
    nop
    mov #0x1, r4
    mov.l @r14, r2
    mov.w   DAT_06008624, r0
    mov.l @(r0, r2), r3
    cmp/gt r4, r3
    bt      .L_0600861E
    mov.l   .L_06008634, r5
    mov.l   .L_06008638, r2
    mov.l   .L_0600863C, r3
    mov.l @r2, r2
    cmp/eq r3, r2
    bf      .L_0600861A
    mov #0x4, r3
    mov.b r3, @r5
    bra     .L_0600861E
    nop
.L_0600861A:
    extu.b r4, r4
    mov.b r4, @r5
.L_0600861E:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_06008624
DAT_06008624:
    .short  0x01BC

    .global DAT_06008626
DAT_06008626:
    .short  0x00BC
.L_06008628:
    .short  0x0160

    .global DAT_0600862a
DAT_0600862a:
    .short  0x01EC
.L_0600862C:
    .long  sym_0607E940
.L_06008630:
    .long  sym_0607EBD4
.L_06008634:
    .long  sym_06078654
.L_06008638:
    .long  sym_0607EBC4
.L_0600863C:
    .long  0x00200000

    .global sym_06008640
sym_06008640:
    mov.l   .L_060086A8, r4
    mov.l @r4, r2
    mov r2, r0
    mov.b @r0, r0
    tst #0x8, r0
    bf      .L_0600865A
    mov.l @r4, r3
    mov.w   .L_060086A4, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_060086A0
    bra     .L_06008730
    nop
.L_0600865A:
    mov.l @r4, r3
    mov.b @r3, r0
    and #0xF7, r0
    or #0x0, r0
    mov.b r0, @r3
    mov.l @r4, r2
    mov.w   .L_060086A4, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bt      .L_06008672
    bra     .L_06008730
    nop
.L_06008672:
    mov #0x14, r3
    mov.w   .L_060086A6, r0
    mov.l @r4, r2
    mov.w r3, @(r0, r2)
    mov.l   .L_060086AC, r3
    mov.l   .L_060086B0, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0600868C
    mov.l   .L_060086B4, r4
    bra     force_table_apply
    mov.l @r4, r4
.L_0600868C:
    mov.l   .L_060086B8, r0
    mov.l @r0, r0
    and #0x1, r0
    mov r0, r4
    shll2 r4
    shll r4
    mov.l   .L_060086BC, r3
    add r3, r4
    bra     force_table_apply
    mov.l @r4, r4
.L_060086A0:
    rts
    nop
.L_060086A4:
    .short  0x01BC
.L_060086A6:
    .short  0x00D4
.L_060086A8:
    .long  sym_0607E940
.L_060086AC:
    .long  sym_0607EBC4
.L_060086B0:
    .long  0x00800000
.L_060086B4:
    .long  sym_060453C4
.L_060086B8:
    .long  sym_0607EBD0
.L_060086BC:
    .long  sym_060453B4

    .global force_table_apply
force_table_apply:
    sts.l pr, @-r15
    mov #0x1, r6
    mov.l   .L_06008720, r7
    mov.l   .L_06008724, r5
    mov.w   .L_06008714, r3
    mov.l @r7, r0
    mov.l @r5, r2
    and r6, r0
    add r3, r2
    mov.l   .L_06008728, r3
    jsr @r3
    mov r6, r1
    mov.l @r5, r2
    mov.l @r7, r0
    mov.w   .L_06008714, r3
    mov.w   .L_06008716, r1
    shar r0
    add r3, r2
    mov.l   .L_06008728, r3
    jsr @r3
    and r6, r0
    mov.l @r5, r2
    mov.l @r4, r3
    mov.w   .L_06008718, r0
    mov.l r3, @(r0, r2)
    mov.l @(4, r4), r4
    mov.l @r5, r3
    mov.w   DAT_0600871a, r0
    mov.l r4, @(r0, r3)
    add #-0x28, r4
    mov.l @r5, r3
    mov.w   DAT_0600871c, r0
    mov.l r4, @(r0, r3)
    mov.l @r5, r3
    mov.w   .L_0600871E, r0
    mov.l r4, @(r0, r3)
    mov.l   .L_0600872C, r4
    mov.b @r4, r3
    add r6, r3
    mov.b r3, @r4
    bra     .L_06008730
    lds.l @r15+, pr
.L_06008714:
    .short  0x01C0
.L_06008716:
    .short  0x0101
.L_06008718:
    .short  0x01B8

    .global DAT_0600871a
DAT_0600871a:
    .short  0x01BC

    .global DAT_0600871c
DAT_0600871c:
    .short  0x00BC
.L_0600871E:
    .short  0x0208
.L_06008720:
    .long  sym_0607EBD0
.L_06008724:
    .long  sym_0607E940
.L_06008728:
    .long  sym_06034F78
.L_0600872C:
    .long  sym_0607EBEC
.L_06008730:
    mov.l   .L_060087F8, r4
    mov.w   DAT_060087e8, r0
    mov.l @r4, r3
    mov.l @(r0, r3), r2
    cmp/pl r2
    bf.s    .L_06008748
    mov #0x0, r6
    mov.l @r4, r2
    mov.w   DAT_060087e8, r0
    mov.l @(r0, r2), r3
    add #-0x1, r3
    mov.l r3, @(r0, r2)
.L_06008748:
    mov.l @r4, r3
    mov.w   DAT_060087ea, r0
    mov.l @(r0, r3), r2
    cmp/pl r2
    bf      .L_0600875C
    mov.l @r4, r2
    mov.w   DAT_060087ea, r0
    mov.l @(r0, r2), r3
    add #-0x1, r3
    mov.l r3, @(r0, r2)
.L_0600875C:
    mov.l @r4, r0
    mov.w   DAT_060087ea, r1
    mov.l @(r0, r1), r0
    cmp/eq #0xA, r0
    bf      .L_0600876E
    mov.l @r4, r2
    mov #0xA, r3
    mov.w   DAT_060087ec, r0
    mov.w r3, @(r0, r2)
.L_0600876E:
    mov.l @r4, r5
    mov.w   .L_060087EE, r0
    mov.l @(r0, r5), r3
    add #0xC, r3
    mov.l r3, @(r0, r5)
    add #-0xC, r3
    add #-0x4, r0
    mov r3, r5
    mov.l @r4, r3
    mov.l @r5, r2
    mov.l r2, @(r0, r3)
    mov.w @(4, r5), r0
    mov.l @r4, r2
    mov r0, r7
    mov.w   .L_060087F0, r0
    mov.b @(r0, r2), r0
    tst #0x40, r0
    bt      .L_060087B8
    mov.l @r4, r3
    mov.w @(6, r5), r0
    mov r0, r2
    mov.w   .L_060087F2, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.w @(8, r5), r0
    mov r0, r2
    neg r2, r2
    mov.w   DAT_060087f4, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.w @(10, r5), r0
    mov r0, r2
    neg r2, r2
    mov.w   .L_060087F6, r0
    mov.l r2, @(r0, r3)
    bra     .L_0600881A
    nop
.L_060087B8:
    mov.l @r4, r2
    mov.w   .L_060087F0, r0
    mov.b @(r0, r2), r0
    tst #0x80, r0
    bt      .L_060087FC
    mov.l @r4, r3
    mov.w @(6, r5), r0
    mov r0, r2
    neg r2, r2
    mov.w   .L_060087F2, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.w @(8, r5), r0
    mov r0, r2
    neg r2, r2
    mov.w   DAT_060087f4, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.w @(10, r5), r0
    mov r0, r2
    mov.w   .L_060087F6, r0
    mov.l r2, @(r0, r3)
    bra     .L_0600881A
    nop

    .global DAT_060087e8
DAT_060087e8:
    .short  0x01BC

    .global DAT_060087ea
DAT_060087ea:
    .short  0x00BC

    .global DAT_060087ec
DAT_060087ec:
    .short  0x00D4
.L_060087EE:
    .short  0x01B8
.L_060087F0:
    .short  0x01C0
.L_060087F2:
    .short  0x01C8

    .global DAT_060087f4
DAT_060087f4:
    .short  0x01CC
.L_060087F6:
    .short  0x01D0
.L_060087F8:
    .long  sym_0607E940
.L_060087FC:
    mov.l @r4, r2
    mov.w @(6, r5), r0
    mov r0, r3
    mov.w   .L_060088AA, r0
    mov.l r3, @(r0, r2)
    mov.l @r4, r3
    mov.w @(8, r5), r0
    mov r0, r2
    mov.w   DAT_060088ac, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.w @(10, r5), r0
    mov r0, r2
    mov.w   .L_060088AE, r0
    mov.l r2, @(r0, r3)
.L_0600881A:
    mov.l @r4, r3
    mov.l   .L_060088B8, r2
    mov.l @(4, r3), r3
    mov.b @r2, r2
    extu.b r2, r2
    cmp/eq r2, r3
    bf      .L_06008884
    exts.w r7, r7
    mov.l @r4, r3
    mov.w   DAT_060088b0, r0
    mov.l @(r0, r3), r2
    add #0x1, r2
    mov.l r2, @(r0, r3)
    mov.w   DAT_060088b2, r3
    cmp/gt r3, r7
    bf      .L_0600885A
    mov.l @r4, r3
    mov.w   DAT_060088b0, r0
    mov.l @(r0, r3), r2
    mov #0x50, r3
    cmp/ge r3, r2
    bf      .L_0600884A
    bra     .L_06008854
    nop
.L_0600884A:
    mov.l @r4, r2
    mov.w   DAT_060088b0, r0
    mov.l @(r0, r2), r3
    mov #0x28, r2
    cmp/ge r2, r3
.L_06008854:
    mov.l @r4, r2
    mov.w   DAT_060088b0, r0
    mov.l r6, @(r0, r2)
.L_0600885A:
    mov.l @r4, r3
    mov.w   DAT_060088b4, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_06008884
    exts.b r6, r3
    mov.l   .L_060088BC, r2
    mov.b r3, @r2
    mov.l   .L_060088C0, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_0600887E
    mov.l   .L_060088C4, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bf      .L_06008884
.L_0600887E:
    mov #0x4, r3
    mov.l   .L_060088C8, r2
    mov.w r3, @r2
.L_06008884:
    mov.l @r4, r3
    mov.w   DAT_060088b4, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_060088A6
    mov.l @r4, r3
    mov.w   DAT_060088b6, r0
    mov.l r6, @(r0, r3)
    mov.l @r4, r3
    add #0x14, r0
    mov.l r6, @(r0, r3)
    mov.l @r4, r3
    add #0x4, r0
    mov.l r6, @(r0, r3)
    mov.l @r4, r3
    add #0x4, r0
    mov.l r6, @(r0, r3)
.L_060088A6:
    rts
    nop
.L_060088AA:
    .short  0x01C8

    .global DAT_060088ac
DAT_060088ac:
    .short  0x01CC
.L_060088AE:
    .short  0x01D0

    .global DAT_060088b0
DAT_060088b0:
    .short  0x01C4

    .global DAT_060088b2
DAT_060088b2:
    .short  0x0100

    .global DAT_060088b4
DAT_060088b4:
    .short  0x01BC

    .global DAT_060088b6
DAT_060088b6:
    .short  0x01B4
.L_060088B8:
    .long  sym_0607EBBC
.L_060088BC:
    .long  sym_0607866C
.L_060088C0:
    .long  sym_06078635
.L_060088C4:
    .long  sym_0607ED8C
.L_060088C8:
    .long  sym_0605A016
