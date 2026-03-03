	.text
    .global attract_init_setup
attract_init_setup:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l @(16, r4), r7
    mov.l @(20, r4), r3
    mov.l   .L_0603EF8C, r2
    sub r3, r7
    cmp/eq r2, r5
    bf      .L_0603EF76
    mov.l   .L_0603EF90, r5
.L_0603EF76:
    mov.w   DAT_0603ef8a, r2
    add r7, r2
    shlr8 r2
    shlr2 r2
    shlr r2
    cmp/hs r2, r5
    bt.s    .L_0603EF94
    mov.l r2, @r15
    bra     .L_0603EF96
    nop

    .global DAT_0603ef8a
DAT_0603ef8a:
    .short  0x07FF
.L_0603EF8C:
    .long  0x0000FFFF
.L_0603EF90:
    .long  0x7FFFFFFF
.L_0603EF94:
    mov.l @r15, r5
.L_0603EF96:
    tst r6, r6
    bt      .L_0603EFCC
    mov r5, r3
    shll8 r3
    shll2 r3
    shll r3
    mov.l r3, @r6
    mov.l @(20, r4), r2
    mov.l @(16, r4), r1
    add r3, r2
    cmp/gt r1, r2
    bf      .L_0603EFCC
    mov.w   DAT_0603eff4, r0
    mov.l   .L_0603EFF8, r2
    jsr @r2
    mov r7, r1
    mov r0, r4
    mov.l @r6, r0
    tst r0, r0
    bt      .L_0603EFCC
    tst r4, r4
    bt      .L_0603EFCC
    mov.w   DAT_0603eff4, r3
    sub r4, r3
    mov.l @r6, r2
    sub r3, r2
    mov.l r2, @r6
.L_0603EFCC:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov r5, r0

    .global sym_0603EFD4
sym_0603EFD4:
    sts.l macl, @-r15
    mov.l @(8, r4), r0
    mov.l @(12, r4), r3
    mov.l @(16, r4), r2
    mul.l r3, r0
    sts macl, r0
    sub r2, r0
    rts
    lds.l @r15+, macl

    .global sym_0603EFE6
sym_0603EFE6:
    mov.l   .L_0603EFFC, r3
    mov.l @(32, r3), r0
    tst r0, r0
    bt.s    .L_0603F000
    mov #0x1, r7
    rts
    mov #0x0, r0

    .global DAT_0603eff4
DAT_0603eff4:
    .short  0x0800
    .short  0xFFFF
.L_0603EFF8:
    .long  sym_06036BE4
.L_0603EFFC:
    .long  sym_06063624
.L_0603F000:
    mov.l   .L_0603F06C, r6
    mov.l @(4, r4), r3
    mov.l @(20, r4), r2
    add r2, r3
    mov.l r3, @r6
    mov r5, r3
    mov.l r7, @(4, r6)
    shll8 r3
    shll2 r3
    shll r3
    mov.l r3, @(8, r6)
    mov.l @(16, r4), r2
    mov.l @(20, r4), r3
    mov.l @(8, r6), r1
    sub r3, r2
    cmp/gt r2, r1
    bf      .L_0603F02A
    mov.l @(16, r4), r2
    mov.l @(20, r4), r3
    sub r3, r2
    mov.l r2, @(8, r6)
.L_0603F02A:
    mov.l r5, @(12, r6)
    mov.l   .L_0603F06C, r2
    mov.l r7, @(32, r2)
    mov r6, r0
    rts
    nop

    .global sym_0603F036
sym_0603F036:
    mov.l   .L_0603F06C, r3
    mov.l @(36, r3), r0
    tst r0, r0
    bt      .L_0603F042
    rts
    mov #0x0, r0
.L_0603F042:
    mov.l   .L_0603F06C, r6
    mov.l @(4, r4), r3
    mov.l @(16, r4), r2
    add #0x10, r6
    add r2, r3
    mov #0x1, r4
    mov.l r3, @r6
    mov.l r4, @(4, r6)
    mov.l r5, @(8, r6)
    mov.w   .L_0603F06A, r3
    add r3, r5
    shlr8 r5
    shlr2 r5
    shlr r5
    mov.l r5, @(12, r6)
    mov.l   .L_0603F06C, r2
    mov.l r4, @(36, r2)
    mov r6, r0
    rts
    nop
.L_0603F06A:
    .short  0x07FF
.L_0603F06C:
    .long  sym_06063624

    .global sym_0603F070
sym_0603F070:
    mov.l   .L_0603F0D8, r3
    cmp/eq r3, r5
    bf.s    .L_0603F08E
    mov #0x0, r7
    mov r6, r0
    cmp/eq #-0x1, r0
    bf      .L_0603F080
    mov.l @(8, r5), r6
.L_0603F080:
    mov.l @(20, r4), r2
    add r6, r2
    mov.l r2, @(20, r4)
    mov.l   .L_0603F0D8, r3
    mov.l r7, @(32, r3)
    bra     .L_0603F0A8
    nop
.L_0603F08E:
    mov.l   .L_0603F0D8, r3
    add #0x10, r3
    cmp/eq r3, r5
    bf      .L_0603F0A8
    mov r6, r0
    cmp/eq #-0x1, r0
    bf      .L_0603F09E
    mov.l @(8, r5), r6
.L_0603F09E:
    mov.l @(16, r4), r2
    add r6, r2
    mov.l r2, @(16, r4)
    mov.l   .L_0603F0D8, r3
    mov.l r7, @(36, r3)
.L_0603F0A8:
    rts
    nop
    .long  0x66425664
    .long  0x35678B00
    .long  0x65634511
    .long  0x8900E500
    .long  0x63534318
    .long  0x43084300
    .long  0x14356233
    .long  0x53443237
    .long  0x8B015345
    .long  0x1434000B
    .long  0x6053FFFF
.L_0603F0D8:
    .long  sym_06063624
    .long  0x5045930B
    .long  0x303C4019
    .long  0x4009000B
    .long  0x40015341
    .long  0x25325242
    .long  0x26225343
    .long  0x000B2732
    .long  0x07FF0000
