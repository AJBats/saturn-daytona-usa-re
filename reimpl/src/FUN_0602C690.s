
    .section .text.FUN_0602C690


    .global FUN_0602C690
    .type FUN_0602C690, @function
FUN_0602C690:
    sts.l pr, @-r15
    mov.w   .L_0602C71A, r1
    mov.w   .L_0602C71C, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    bsr     .L_0602C7FC
    or r3, r4
    mov r4, r10
    mov.w   .L_0602C71E, r1
    mov.w   .L_0602C720, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    bsr     .L_0602C7FC
    or r3, r4
    mov r4, r11
    mov.w   .L_0602C722, r1
    mov.w   .L_0602C724, r2
    mov.l @(r0, r1), r5
    mov.l @(r0, r2), r6
    neg r5, r5
    neg r6, r6
    mov r0, r14
    mov.w   .L_0602C726, r1
    mov.w   .L_0602C728, r2
    mov.l @(r0, r1), r9
    mov.l @(r0, r2), r4
    mov r9, r7
    xor r5, r7
    cmp/pz r7
    bt      .L_0602C6CE
    mov #0x0, r9
.L_0602C6CE:
    mov.l r6, @-r15
    mov.l r5, @-r15
    mov.l   .L_0602C72C, r5
    mov r4, r7
    dmuls.l r4, r5
    mov.l   .L_0602C730, r1
    sts mach, r4
    sts macl, r8
    mov #0x0, r13
    xtrct r4, r8
    dmuls.l r7, r1
    mov.l @(28, r0), r4
    mov.l   .L_0602C734, r5
    sts mach, r1
    sts macl, r7
    mov.l   .L_0602C738, r0
    xtrct r1, r7
    cmp/pz r4
    bt      .L_0602C6F8
    mov #0x0, r4
    mov #0x0, r13
.L_0602C6F8:
    jsr @r0
    shar r4
    dmuls.l r0, r5
    mov.w   .L_0602C72A, r1
    mov.l   .L_0602C73C, r3
    sts mach, r5
    sts macl, r4
    mov r14, r0
    xtrct r5, r4
    tst r13, r13
    mov r4, r13
    mov.l @(r0, r1), r5
    bf      .L_0602C740
    shll r13
    add r5, r13
    bra     .L_0602C748
    add r4, r5

    .global DAT_0602c71a
.L_0602C71A:
DAT_0602c71a:
    .2byte  0x0120

    .global DAT_0602c71c
.L_0602C71C:
DAT_0602c71c:
    .2byte  0x0124

    .global DAT_0602c71e
.L_0602C71E:
DAT_0602c71e:
    .2byte  0x0128

    .global DAT_0602c720
.L_0602C720:
DAT_0602c720:
    .2byte  0x012C

    .global DAT_0602c722
.L_0602C722:
DAT_0602c722:
    .2byte  0x0060

    .global DAT_0602c724
.L_0602C724:
DAT_0602c724:
    .2byte  0x0064

    .global DAT_0602c726
.L_0602C726:
DAT_0602c726:
    .2byte  0x0100

    .global DAT_0602c728
.L_0602C728:
DAT_0602c728:
    .2byte  0x0104

    .global DAT_0602c72a
.L_0602C72A:
DAT_0602c72a:
    .2byte  0x00FC
.L_0602C72C:
    .4byte  0x03700000
.L_0602C730:
    .4byte  0x02D00000
.L_0602C734:
    .4byte  0x00000645
.L_0602C738:
    .4byte  FUN_06027348
.L_0602C73C:
    .4byte  0x251B1285
.L_0602C740:
    neg r13, r13
    shll r13
    add r5, r13
    add r4, r5
.L_0602C748:
    dmuls.l r3, r5
    mov.l @r15+, r5
    sts mach, r4
    sts macl, r0
    xtrct r4, r0
    dmuls.l r3, r13
    sts mach, r3
    sts macl, r13
    xtrct r3, r13
    mov r9, r4
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
    add r8, r5
    sub r0, r5
    dmuls.l r10, r5
    mov.l   .L_0602C7A8, r3
    sts mach, r5
    sts macl, r4
    xtrct r5, r4
    dmuls.l r4, r3
    sts mach, r4
    sts macl, r10
    xtrct r4, r10
    mov.l @r15+, r4
    dmuls.l r4, r9
    sts mach, r5
    sts macl, r4
    xtrct r5, r4
    add r7, r4
    add r13, r4
    dmuls.l r4, r11
    mov.l   .L_0602C7A8, r3
    sts mach, r5
    sts macl, r4
    xtrct r5, r4
    dmuls.l r4, r3
    sts mach, r4
    sts macl, r11
    xtrct r4, r11
    mov.l   .L_0602C7AC, r1
    mov.l   .L_0602C7B0, r2
    cmp/gt r1, r10
    bt      .L_0602C7B4
    mov r1, r10
    bra     .L_0602C7BA
    nop
.L_0602C7A8:
    .4byte  0x00028000
.L_0602C7AC:
    .4byte  0x01600000
.L_0602C7B0:
    .4byte  0x0C080000
.L_0602C7B4:
    cmp/ge r10, r2
    bt      .L_0602C7BA
    mov r2, r10
.L_0602C7BA:
    mov.l   .L_0602C7C8, r1
    mov.l   .L_0602C7CC, r2
    cmp/gt r1, r11
    bt      .L_0602C7D0
    mov r1, r11
    bra     .L_0602C7D6
    nop
.L_0602C7C8:
    .4byte  0x01200000
.L_0602C7CC:
    .4byte  0x09D80000
.L_0602C7D0:
    cmp/ge r11, r2
    bt      .L_0602C7D6
    mov r2, r11
.L_0602C7D6:
    mov r14, r0
    mov.w   .L_0602C7F8, r1
    mov.w   .L_0602C7FA, r3
    mov.l @(r0, r1), r2
    mov.l @(r0, r3), r4
    sub r2, r10
    sub r4, r11
    shar r10
    shar r11
    shar r10
    shar r11
    add r10, r2
    add r11, r4
    mov.l r2, @(r0, r1)
    lds.l @r15+, pr
    rts
    mov.l r4, @(r0, r3)

    .global DAT_0602c7f8
.L_0602C7F8:
DAT_0602c7f8:
    .2byte  0x0140

    .global DAT_0602c7fa
.L_0602C7FA:
DAT_0602c7fa:
    .2byte  0x0144

.L_0602C7FC:
    mov.l @(8, r0), r3
    mov #0xA, r2
    mov.l r10, @-r15
    cmp/ge r3, r2
    .byte   0x8D, 0x69    /* bt/s 0x0602C8DA (external: early exit with 0x10000) */
    mov #0x0, r9
    mov #0x0, r8
    .byte   0x96, 0x45    /* mov.w .L_wpool_0602C898, r6 (r6 = 0x0001, activation bit 0 mask) [HIGH] */
    tst r6, r4
    not r6, r7
    bt/s    .L_0602C818
    and r7, r4
    .byte   0x98, 0x41    /* mov.w .L_wpool_0602C89A, r8 (r8 = 0x00EE, activation weight for bit 0 = 238) [HIGH] */
    mov #0x1, r9
.L_0602C818:
    .byte   0x96, 0x40    /* mov.w .L_wpool_0602C89C, r6 (r6 = 0x0004, activation bit 2 mask) [HIGH] */
    tst r6, r4
    not r6, r7
    bt/s    .L_0602C828
    and r7, r4
    .byte   0x96, 0x3C    /* mov.w .L_wpool_0602C89E, r6 (r6 = 0x00B4, activation weight for bit 2 = 180) [HIGH] */
    add r6, r8
    add #0x1, r9
.L_0602C828:
    .byte   0x96, 0x3A    /* mov.w .L_wpool_0602C8A0, r6 (r6 = 0x0002, activation bit 1 mask) [HIGH] */
    tst r6, r4
    not r6, r7
    bt/s    .L_0602C838
    and r7, r4
    .byte   0x96, 0x36    /* mov.w .L_wpool_0602C8A2, r6 (r6 = 0x00D2, activation weight for bit 1 = 210) [HIGH] */
    add r6, r8
    add #0x1, r9
.L_0602C838:
    .byte   0x96, 0x34    /* mov.w .L_wpool_0602C8A4, r6 (r6 = 0x0010, activation bit 4 mask) [HIGH] */
    tst r6, r4
    not r6, r7
    bt/s    .L_0602C848
    and r7, r4
    .byte   0x96, 0x30    /* mov.w .L_wpool_0602C8A6, r6 (r6 = 0x00F6, activation weight for bit 4 = 246) [HIGH] */
    add r6, r8
    add #0x1, r9
.L_0602C848:
    .byte   0x96, 0x2E    /* mov.w .L_wpool_0602C8A8, r6 (r6 = 0x0020, activation bit 5 mask) [HIGH] */
    tst r6, r4
    not r6, r7
    bt/s    .L_0602C858
    and r7, r4
    .byte   0x96, 0x2A    /* mov.w .L_wpool_0602C8AA, r6 (r6 = 0x00FA, activation weight for bit 5 = 250) [HIGH] */
    add r6, r8
    add #0x1, r9
.L_0602C858:
    mov #0x0, r6
    cmp/eq r6, r4
    bt      .L_0602C864
    .byte   0x96, 0x25    /* mov.w .L_wpool_0602C8AC, r6 (r6 = 0x0096, activation weight for remainder bits = 150) [HIGH] */
    add r6, r8
    add #0x1, r9
.L_0602C864:
    tst r9, r9
    .byte   0x8D, 0x15    /* bt/s 0x0602C894 (external: no flags, return r4=0) */
    mov #0x0, r4
    .byte   0xD2, 0x11    /* mov.l .L_pool_0602C8B0, r2 (r2 = sym_06045AEC, activation weight lookup table) [MEDIUM] */
    mov #0x1, r4
    cmp/eq r4, r9
    .byte   0x89, 0x22    /* bt 0x0602C8B8 (external: 1-flag path, shll2+lookup) */
    shll r4
    cmp/eq r4, r9
    .byte   0x89, 0x24    /* bt 0x0602C8C2 (external: 2-flag path, shlr+shll2+lookup) */
    shll r4
    cmp/eq r4, r9
    .byte   0x89, 0x27    /* bt 0x0602C8CE (external: 4-flag path, shlr2+shll2+lookup) */
    mov.l r0, @-r15
    mov r8, r1
    .byte   0xDC, 0x0C    /* mov.l .L_pool_0602C8B4, r12 (r12 = hw_divide_protected @ 0x0602ECCC) [HIGH] */


    .global FUN_0602C884
    .type FUN_0602C884, @function
FUN_0602C884:
    sts.l pr, @-r15
    jsr @r12
    mov r9, r0
    lds.l @r15+, pr
    mov.l @r15+, r0
    shll2 r1
    add r2, r1
    mov.l @r1, r4
    rts
    mov.l @r15+, r10
    .4byte  0x000100EE

    .global DAT_0602c89c
DAT_0602c89c:
    mov.b r0, @(r0, r0)
    mov.b r11, @(r0, r0)

    .global DAT_0602c8a0
DAT_0602c8a0:
    stc sr, r0
    .word 0x00D2
    .word 0x0010
    mov.l r15, @(r0, r0)
    .word 0x0020
    .word 0x00FA
    mov.l r9, @(r0, r0)
    .word 0x0000
    .4byte  sym_06045AEC
    .4byte  sym_0602ECCC
    .4byte  0x4808328C
    .4byte  0x6AF6000B
    .4byte  0x64224801
    .4byte  0x4808328C
    .4byte  0x6AF6000B
    .4byte  0x64224809
    .4byte  0x4808328C
    .4byte  0x6AF6000B
    .4byte  0x6422E401
    .4byte  0x6AF6000B
    .2byte  0x4428


    .global FUN_0602C8E2
    .type FUN_0602C8E2, @function
FUN_0602C8E2:
    sts.l pr, @-r15
    mov #0x0, r12
    mov #0x0, r6
    mov.w   .L_0602C9CC, r1
    mov.w   .L_0602C9CE, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    xor r3, r4
    cmp/pz r4
    bf      .L_0602C8FE
    mov r3, r6
    cmp/pz r6
    bt      .L_0602C8FE
    neg r6, r6
.L_0602C8FE:
    mov.l @(8, r0), r1
    mov #0x46, r7
    cmp/ge r1, r7
    bt      .L_0602C92A
    mov.w   .L_0602C9D0, r2
    mov.w   .L_0602C9D2, r3
    mov.l @(r0, r2), r4
    mov.l @(r0, r3), r5
    xor r4, r5
    cmp/pz r5
    bt      .L_0602C92A
    mov.w   .L_0602C9D4, r2
    mov.w   .L_0602C9D6, r4
    mov.l @(r0, r2), r3
    cmp/ge r4, r3
    bt      .L_0602C924
    neg r4, r4
    cmp/ge r3, r4
    bt      .L_0602C92A
.L_0602C924:
    mov.w   .L_0602C9D8, r2
    mov #0xA, r3
    mov.w r3, @(r0, r2)
.L_0602C92A:
    mov #0x64, r2
    mov.w   .L_0602C9DA, r3
    cmp/gt r1, r2
    bt      .L_0602C938
    cmp/gt r6, r3
    bt      .L_0602C938
    mov #0x1, r12
.L_0602C938:
    mov.w   .L_0602C9DC, r3
    mov.w @(r0, r3), r2
    tst r2, r2
    bt      .L_0602C946
    mov.w   .L_0602C9DE, r3
    mov #0x10, r2
    mov.w r2, @(r0, r3)
.L_0602C946:
    mov.l @(28, r0), r3
    mov.w   .L_0602C9E0, r2
    cmp/ge r3, r2
    bt      .L_0602C978
    mov.w   .L_0602C9E2, r2
    mov #0x4, r3
    mov.l @(r0, r2), r1
    add #0x4, r2
    tst r1, r3
    bt      .L_0602C962
    mov.w   .L_0602C9CC, r3
    mov.l @(r0, r3), r1
    cmp/pz r1
    bf      .L_0602C972
.L_0602C962:
    mov #0x4, r3
    mov.l @(r0, r2), r1
    tst r1, r3
    bt      .L_0602C978
    mov.w   .L_0602C9CC, r3
    mov.l @(r0, r3), r1
    cmp/pz r1
    bf      .L_0602C978
.L_0602C972:
    mov.w   .L_0602C9D8, r3
    mov #0x14, r2
    mov.w r2, @(r0, r3)
.L_0602C978:
    mov.w   .L_0602C9E4, r8
    mov.w @(r0, r8), r2
    tst r12, r12
    bt      .L_0602C982
    add #0x1, r2
.L_0602C982:
    cmp/pz r2
    bf      .L_0602C9F8
    add #-0x1, r2
    mov.w r2, @(r0, r8)
    mov.w   .L_0602C9E6, r3
    mov.w   .L_0602C9D2, r2
    mov.l @(r0, r3), r6
    mov.w   .L_0602C9E8, r1
    dmuls.l r6, r6
    mov.l @(r0, r2), r5
    mov.l @(r0, r1), r4
    sts mach, r6
    dmuls.l r5, r5
    sts mach, r0
    dmuls.l r4, r4
    mov.l   .L_0602C9EC, r13
    sts mach, r1
    jsr @r13
    add r6, r0
    shll16 r0
    mov r0, r3
    mov.w   .L_0602C9E8, r1
    mov r14, r0
    mov.l @(r0, r1), r5
    dmuls.l r3, r5
    mov #0x0, r4
    sts mach, r6
    sts macl, r3
    xtrct r6, r3
    cmp/pz r3
    bt      .L_0602C9C2
    mov r4, r3
.L_0602C9C2:
    cmp/gt r4, r5
    bt      .L_0602C9F0
    mov r4, r5
    bra     .L_0602C9F6
    nop

    .global DAT_0602c9cc
.L_0602C9CC:
DAT_0602c9cc:
    .2byte  0x0040

    .global DAT_0602c9ce
.L_0602C9CE:
DAT_0602c9ce:
    .2byte  0x005C

    .global DAT_0602c9d0
.L_0602C9D0:
DAT_0602c9d0:
    .2byte  0x0060

    .global DAT_0602c9d2
.L_0602C9D2:
DAT_0602c9d2:
    .2byte  0x0064

    .global DAT_0602c9d4
.L_0602C9D4:
DAT_0602c9d4:
    .2byte  0x00D0

    .global DAT_0602c9d6
.L_0602C9D6:
DAT_0602c9d6:
    .2byte  0x1000

    .global DAT_0602c9d8
.L_0602C9D8:
DAT_0602c9d8:
    .2byte  0x016C
.L_0602C9DA:
    .2byte  0x0E00

    .global DAT_0602c9dc
.L_0602C9DC:
DAT_0602c9dc:
    .2byte  0x00D4

    .global DAT_0602c9de
.L_0602C9DE:
DAT_0602c9de:
    .2byte  0x0170
.L_0602C9E0:
    .2byte  0x0500

    .global DAT_0602c9e2
.L_0602C9E2:
DAT_0602c9e2:
    .2byte  0x0128
.L_0602C9E4:
    .2byte  0x016A

    .global DAT_0602c9e6
.L_0602C9E6:
DAT_0602c9e6:
    .2byte  0x0144
.L_0602C9E8:
    .2byte  0x011C
    .2byte  0x0000
.L_0602C9EC:
    .4byte  sym_0602ECCC
.L_0602C9F0:
    cmp/ge r5, r3
    bt      .L_0602C9F6
    mov r3, r5
.L_0602C9F6:
    mov.l r5, @(r0, r1)
.L_0602C9F8:
    add #0x2, r8
    mov.w @(r0, r8), r2
    cmp/pz r2
    bf      .L_0602CA0A
    add #-0x1, r2
    mov.w r2, @(r0, r8)
    mov.w   .L_0602CA72, r3
    mov #0x0, r4
    mov.w r4, @(r0, r3)
.L_0602CA0A:
    add #0x2, r8
    mov.w @(r0, r8), r5
    cmp/pl r5
    bf      .L_0602CA26
    add #-0x1, r5
    mov.w r5, @(r0, r8)
    mov.w   .L_0602CA74, r2
    mov.l   .L_0602CA7C, r4
    mov.l @(r0, r2), r3
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.w r4, @(r0, r2)
.L_0602CA26:
    add #0x2, r8
    mov.w @(r0, r8), r5
    cmp/pl r5
    bf      .L_0602CA38
    add #-0x1, r5
    mov.w r5, @(r0, r8)
    mov.w   .L_0602CA74, r2
    mov.l   .L_0602CA80, r3
    mov.l r3, @(r0, r2)
.L_0602CA38:
    add #0x2, r8
    mov.w @(r0, r8), r5
    cmp/pl r5
    bf      .L_0602CA52
    add #-0x1, r5
    mov.w r5, @(r0, r8)
    mov.w   .L_0602CA74, r1
    mov.l @(r0, r1), r2
    shar r2
    mov.l r2, @(r0, r1)
    mov.w   .L_0602CA76, r5
    mov #0x0, r3
    mov.l r3, @(r0, r5)
.L_0602CA52:
    add #0x2, r8
    mov.w @(r0, r8), r5
    cmp/pl r5
    bf      .L_0602CA6C
    add #-0x1, r5
    mov.w r5, @(r0, r8)
    mov.w   .L_0602CA78, r1
    mov.l @(r0, r1), r3
    cmp/pz r3
    bf      .L_0602CA6C
    neg r3, r3
    mov.w   .L_0602CA76, r1
    mov.l r3, @(r0, r1)
.L_0602CA6C:
    lds.l @r15+, pr
    rts
    mov #0x0, r1

    .global DAT_0602ca72
.L_0602CA72:
DAT_0602ca72:
    .2byte  0x0168

    .global DAT_0602ca74
.L_0602CA74:
DAT_0602ca74:
    .2byte  0x0144

    .global DAT_0602ca76
.L_0602CA76:
DAT_0602ca76:
    .2byte  0x00F4
.L_0602CA78:
    .2byte  0x011C
    .2byte  0x0000
.L_0602CA7C:
    .4byte  0x00011999
.L_0602CA80:
    .4byte  0x09D80000
