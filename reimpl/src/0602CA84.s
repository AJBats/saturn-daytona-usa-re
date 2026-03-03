	.text
    .global vdp1_coord_setup
vdp1_coord_setup:
    sts.l pr, @-r15
    mov.w   DAT_0602cb04, r1
    mov.l @(r0, r1), r2
    neg r2, r2
    mov.w   DAT_0602cb06, r1
    mov.l   .L_pool_0602CB14, r4
    mov.l @(r0, r1), r5
    neg r5, r5
    dmuls.l r4, r5
    mov r0, r14
    sts mach, r4
    sts macl, r6
    xtrct r4, r6
    mov.l   .L_pool_0602CB18, r4
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r7
    xtrct r4, r7
    mov.w   DAT_0602cb08, r1
    mov.l @(r0, r1), r4
    dmuls.l r4, r2
    mov.w   DAT_0602cb0a, r3
    mov.l @(r0, r3), r8
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
    dmuls.l r8, r2
    mov r5, r12
    xor r6, r12
    cmp/pz r12
    bf      .L_0602CAC4
    neg r6, r6
.L_0602CAC4:
    add r5, r6
    mov.l r6, @-r15
    sts mach, r8
    sts macl, r2
    xtrct r8, r2
    mov r2, r12
    xor r7, r12
    cmp/pz r12
    bf      .L_0602CAD8
    neg r7, r7
.L_0602CAD8:
    add r2, r7
    mov.w   DAT_0602cb0c, r1
    mov.l r7, @(r0, r1)
    mov.w   DAT_0602cb0e, r1
    mov.w   .L_wpool_0602CB10, r2
    mov.l @(r0, r1), r3
    mov r3, r8
    mov.l @(r0, r2), r4
    mov r4, r9
    sub r4, r3
    cmp/pz r3
    bt      .L_0602CAF2
    neg r3, r3
.L_0602CAF2:
    cmp/pz r6
    bt      .L_0602CAF8
    neg r6, r6
.L_0602CAF8:
    cmp/ge r6, r3
    bt      .L_0602CB1C
    shar r3
    shar r3
    bra     .L_0602CB22
    add r3, r6

    .global DAT_0602cb04
DAT_0602cb04:
    .short  0x0104

    .global DAT_0602cb06
DAT_0602cb06:
    .short  0x0100

    .global DAT_0602cb08
DAT_0602cb08:
    .short  0x0060

    .global DAT_0602cb0a
DAT_0602cb0a:
    .short  0x0064

    .global DAT_0602cb0c
DAT_0602cb0c:
    .short  0x0148

    .global DAT_0602cb0e
DAT_0602cb0e:
    .short  0x00EC
.L_wpool_0602CB10:
    .short  0x00F8
    .short  0x0000
.L_pool_0602CB14:
    .long  0x03700000
.L_pool_0602CB18:
    .long  0x02D00000
.L_0602CB1C:
    shar r6
    shar r6
    add r3, r6
.L_0602CB22:
    mov.l   .L_0602CB7C, r10
    mov.w   DAT_0602cb72, r1
    mov.l @(r0, r1), r4
    cmp/gt r6, r4
    bt      .L_0602CB36
    mov.l   .L_0602CB80, r0
    jsr @r0
    mov r6, r5
    mov r0, r10
    mov r14, r0
.L_0602CB36:
    mov.w   DAT_0602cb74, r1
    mov.l r10, @(r0, r1)
    neg r8, r8
    mov.w   DAT_0602cb76, r1
    mov.l @(r0, r1), r2
    add r9, r2
    sub r2, r8
    mov.l @r15+, r6
    mov.l r8, @-r15
    mov.l r2, @-r15
    mov.w   DAT_0602cb78, r1
    mov.l @(r0, r1), r3
    mov.w   DAT_0602cb7a, r2
    mov.l @(r0, r2), r4
    sub r4, r3
    mov r3, r6
    mov #0x0, r10
    cmp/pz r7
    bt      .L_0602CB5E
    neg r7, r7
.L_0602CB5E:
    sub r9, r3
    cmp/pz r3
    bf      .L_0602CB8C
    cmp/ge r7, r3
    bf      .L_0602CB84
    mov #0x1, r10
    shar r7
    shar r7
    bra     .L_0602CBA0
    add r7, r3

    .global DAT_0602cb72
DAT_0602cb72:
    .short  0x0140

    .global DAT_0602cb74
DAT_0602cb74:
    .short  0x0108

    .global DAT_0602cb76
DAT_0602cb76:
    .short  0x00F4

    .global DAT_0602cb78
DAT_0602cb78:
    .short  0x00F0

    .global DAT_0602cb7a
DAT_0602cb7a:
    .short  0x011C
.L_0602CB7C:
    .long  0x00010000
.L_0602CB80:
    .long  fpdiv_setup
.L_0602CB84:
    shar r3
    shar r3
    bra     .L_0602CBA0
    add r7, r3
.L_0602CB8C:
    neg r3, r3
    cmp/ge r7, r3
    bt      .L_0602CB9A
    shar r3
    shar r3
    bra     .L_0602CBA0
    add r7, r3
.L_0602CB9A:
    shar r7
    shar r7
    add r7, r3
.L_0602CBA0:
    mov #0x1, r11
    mov.w   DAT_0602cc9c, r1
    shll16 r11
    mov.l @(r0, r1), r4
    cmp/ge r3, r4
    bt      .L_0602CBB6
    mov.l   .L_0602CCBC, r0
    jsr @r0
    mov r3, r5
    mov r0, r11
    mov r14, r0
.L_0602CBB6:
    mov.w   DAT_0602cc9e, r1
    mov.l r11, @(r0, r1)
    tst r10, r10
    bt      .L_0602CBD2
    mov.l   .L_pool_0602CCC0, r2
    cmp/gt r2, r11
    bt      .L_0602CBD2
    mov.w   DAT_0602cca0, r1
    mov.l @(r0, r1), r2
    cmp/pl r2
    bt      .L_0602CBD2
    bsr     sym_0602CCD0
    nop
    mov r14, r0
.L_0602CBD2:
    neg r6, r6
    mov.l @r15+, r2
    sub r2, r6
    mov.l r6, @-r15
    mov.w   DAT_0602cca2, r1
    mov.l @(r0, r1), r2
    neg r2, r2
    shar r2
    mov.w   DAT_0602cca4, r1
    shar r2
    shar r2
    mov.l r2, @(r0, r1)
    mov.w   DAT_0602cca6, r1
    mov.w @(r0, r1), r2
    tst r2, r2
    bt      .L_0602CC1C
    mov.w   DAT_0602cca8, r1
    mov.w   DAT_0602ccaa, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    mov r3, r7
    sub r4, r3
    sub r7, r3
    neg r4, r11
    shar r3
    shar r11
    shar r3
    shar r11
    add r3, r7
    add r4, r11
    mov.l r7, @(r0, r1)
    mov.l r11, @(r0, r2)
    mov #0x0, r11
    mov.w   DAT_0602ccac, r1
    mov.w   DAT_0602ccae, r2
    mov.l r11, @(r0, r1)
    mov.l r11, @(r0, r2)
.L_0602CC1C:
    mov.w   DAT_0602ccb0, r1
    mov #0x0, r11
    mov.w @(r0, r1), r4
    tst r4, r4
    bt      .L_0602CC40
    mov.w   DAT_0602cca4, r1
    mov.w   DAT_0602cca8, r2
    mov.w   DAT_0602ccaa, r3
    mov.l r11, @(r0, r1)
    mov.l r11, @(r0, r2)
    mov.l r11, @(r0, r3)
    mov.w   DAT_0602ccac, r1
    mov.w   DAT_0602ccae, r2
    mov.l r11, @(r0, r1)
    mov.l r11, @(r0, r2)
    mov.l   .L_0602CCC4, r2
    mov.w   DAT_0602ccb2, r1
    mov.l r2, @(r0, r1)
.L_0602CC40:
    .byte   0xB0, 0x54    /* bsr 0x0602CCEC (external) */
    nop
    mov.l @r15+, r9
    mov.l @r15+, r5
    mov.w   DAT_0602ccb4, r1
    mov.l @(r0, r1), r4
    mov.w   DAT_0602cc9e, r1
    mov.l @(r0, r1), r2
    mov.w   DAT_0602ccb6, r1
    mov.l @(r0, r1), r3
    mov.l   .L_pool_0602CCC8, r1
    mov.w   DAT_0602ccb8, r10
    mov.w @(r0, r10), r10
    mov #0x4, r6
    cmp/eq r6, r10
    bt      .L_0602CC68
    mov #0x5, r6
    cmp/eq r6, r10
    bt      .L_0602CC68
    mov.l   .L_pool_0602CCCC, r1
.L_0602CC68:
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r6
    xtrct r4, r6
    dmuls.l r9, r2
    sts mach, r9
    sts macl, r2
    xtrct r9, r2
    add r2, r6
    sub r3, r6
    dmuls.l r6, r1
    mov.w   DAT_0602ccba, r4
    sts mach, r6
    sts macl, r3
    xtrct r6, r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    shar r3
    lds.l @r15+, pr
    rts
    mov.l r3, @(r0, r4)

    .global DAT_0602cc9c
DAT_0602cc9c:
    .short  0x0144

    .global DAT_0602cc9e
DAT_0602cc9e:
    .short  0x010C

    .global DAT_0602cca0
DAT_0602cca0:
    .short  0x00D8

    .global DAT_0602cca2
DAT_0602cca2:
    .short  0x00D0

    .global DAT_0602cca4
DAT_0602cca4:
    .short  0x0040

    .global DAT_0602cca6
DAT_0602cca6:
    .short  0x0150

    .global DAT_0602cca8
DAT_0602cca8:
    .short  0x0058

    .global DAT_0602ccaa
DAT_0602ccaa:
    .short  0x005C

    .global DAT_0602ccac
DAT_0602ccac:
    .short  0x0060

    .global DAT_0602ccae
DAT_0602ccae:
    .short  0x0064

    .global DAT_0602ccb0
DAT_0602ccb0:
    .short  0x0250

    .global DAT_0602ccb2
DAT_0602ccb2:
    .short  0x0110

    .global DAT_0602ccb4
DAT_0602ccb4:
    .short  0x0108

    .global DAT_0602ccb6
DAT_0602ccb6:
    .short  0x0114

    .global DAT_0602ccb8
DAT_0602ccb8:
    .short  0x007C

    .global DAT_0602ccba
DAT_0602ccba:
    .short  0x00FC
.L_0602CCBC:
    .long  fpdiv_setup
.L_pool_0602CCC0:
    .long  0x0000CCCC
.L_0602CCC4:
    .long  0xFFFF0000
.L_pool_0602CCC8:
    .long  0x00000140
.L_pool_0602CCCC:
    .long  0x00000100

    .global sym_0602CCD0
sym_0602CCD0:
    mov.w   .L_wpool_0602CCEA, r7
    mov.w @(r0, r7), r3
    mov #0x4, r4
    cmp/gt r4, r3
    bt      .L_0602CCE6
    mov.l @(8, r0), r3
    mov #0x14, r4
    cmp/ge r3, r4
    bt      .L_0602CCE6
    mov #0xA, r4
    mov.w r4, @(r0, r7)
.L_0602CCE6:
    rts
    nop
.L_wpool_0602CCEA:
    .short  0x0152
