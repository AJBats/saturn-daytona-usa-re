
    .section .text.FUN_0601B7F4


    .global disc_texture_load_ext
    .type disc_texture_load_ext, @function
disc_texture_load_ext:
    mov.l r14, @-r15
    mov #0x4, r14
    mov.l r13, @-r15
    mov #0x3, r13
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x8, r11
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x24, r15
    mov.l   .L_0601B880, r8
    mov r15, r10
    mov r15, r1
    mov.l   .L_0601B884, r2
    mov.l   .L_0601B888, r3
    add #0x10, r10
    add #0x20, r1
    jsr @r3
    mov #0x2, r0
    mov r15, r1
    mov.l   .L_0601B88C, r2
    mov.l   .L_0601B890, r3
    add #0x14, r1
    jsr @r3
    mov #0xC, r0
    mov r15, r1
    mov.l   .L_0601B894, r2
    mov.l   .L_0601B888, r3
    add #0x10, r1
    jsr @r3
    mov r13, r0
    mov r15, r5
    mov r15, r1
    mov.l   .L_0601B898, r2
    mov.l   .L_0601B888, r3
    add #0xC, r5
    add #0xC, r1
    jsr @r3
    mov r13, r0
    mov.l   .L_0601B89C, r6
    mov.l   .L_0601B8A0, r4
    mov.w   DAT_0601b87e, r3
    mov.w @(2, r6), r0
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601B8A8
    mov.b @r4, r3
    mov.l   .L_0601B8A4, r2
    add r2, r3
    mov.b @r3, r1
    add #-0x1, r1
    mov.b r1, @r3
    exts.b r1, r1
    cmp/pz r1
    bt      .L_0601B8D6
    mov.b @r4, r6
    mov.l   .L_0601B8A4, r2
    add r6, r2
    add r6, r5
    mov.b @r5, r3
    add #-0x1, r3
    exts.b r3, r3
    mov.b r3, @r2
    bra     .L_0601B8D6
    nop

    .global DAT_0601b87e
DAT_0601b87e:
    .2byte  0x4000                          /* bit 14 mask -- scroll-down flag */
.L_0601B880:
    .4byte  sym_06063750
.L_0601B884:
    .4byte  sym_0605DF26
.L_0601B888:
    .4byte  sym_06035228
.L_0601B88C:
    .4byte  sym_0605DF28
.L_0601B890:
    .4byte  sym_06035168
.L_0601B894:
    .4byte  sym_0605DF34
.L_0601B898:
    .4byte  sym_0605DF37
.L_0601B89C:
    .4byte  g_pad_state
.L_0601B8A0:
    .4byte  sym_0608600E
.L_0601B8A4:
    .4byte  sym_0605D4F4
.L_0601B8A8:
    mov.w @(2, r6), r0
    mov.l   .L_0601B948, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601B8D6
    mov.b @r4, r3
    mov.l   .L_0601B94C, r2
    add r2, r3
    mov.b @r3, r1
    add #0x1, r1
    mov.b r1, @r3
    exts.b r1, r1
    mov.b @r4, r0
    mov.b @(r0, r5), r3
    cmp/ge r3, r1
    bf      .L_0601B8D6
    mov.b @r4, r3
    mov.l   .L_0601B94C, r2
    add r2, r3
    mov #0x0, r1
    mov.b r1, @r3
.L_0601B8D6:
    mov #0x0, r12
    mov.l   .L_0601B94C, r3
    mov.l r3, @r15
    mov r15, r3
    add #0x20, r3
    mov.l r3, @(8, r15)
.L_0601B8E2:
    extu.b r12, r2
    mov.l @r15, r3
    mov.b @r3, r3
    cmp/eq r2, r3
    bf      .L_0601B8F0
    bra     .L_0601B8F2
    mov #0x1, r9
.L_0601B8F0:
    extu.b r14, r9
.L_0601B8F2:
    extu.b r12, r2
    extu.b r9, r9
    extu.b r12, r4
    mov.l r2, @(4, r15)
    shll2 r4
    add r9, r2
    mov.w   .L_0601B946, r3
    add r3, r2
    mov.l r2, @-r15
    mov.l   .L_0601B950, r2
    mov.l r2, @-r15
    mov.l   .L_0601B948, r3
    mov.l r3, @-r15
    mov.l   .L_0601B954, r7
    mov r15, r3
    mov.l   .L_0601B960, r2
    mov.l   .L_0601B958, r6
    mov.l   .L_0601B95C, r5
    add #0x20, r3
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    add #0xC, r15
    mov.l @r15, r3
    mov.l @(4, r15), r2
    mov.b @r3, r3
    cmp/eq r2, r3
    bf      .L_0601B96C
    mov.l   .L_0601B964, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r11, r2
    tst r2, r2
    bf      .L_0601B93E
    mov.l   .L_0601B968, r3
    mov.b @r3, r3
    tst r3, r3
    bt      .L_0601B942
.L_0601B93E:
    bra     .L_0601B96E
    extu.b r13, r9
.L_0601B942:
    bra     .L_0601B96E
    extu.b r14, r9
.L_0601B946:
    .2byte  0x0100
.L_0601B948:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_0601B94C:
    .4byte  sym_0605D4F4
.L_0601B950:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_0601B954:
    .4byte  0x001C0000
.L_0601B958:
    .4byte  0x002F0000
.L_0601B95C:
    .4byte  0xFFD40000
.L_0601B960:
    .4byte  rigid_body_transform
.L_0601B964:
    .4byte  sym_0605D4F8
.L_0601B968:
    .4byte  sym_0608600E
.L_0601B96C:
    extu.b r14, r9
.L_0601B96E:
    extu.b r9, r7
    extu.b r12, r2
    extu.b r12, r0
    shll8 r7
    add #0x30, r2
    shll2 r7
    mov r2, r3
    shll2 r7
    shll2 r3
    shll r3
    mov r3, r2
    add r8, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.b @(r0, r10), r6
    mov.l @(4, r15), r5
    add r3, r7
    extu.b r6, r6
    mov.l @r5, r5
    mov.l @(8, r15), r3
    mov.b @r3, r3
    extu.b r3, r2
    shll2 r2
    mov.l   .L_0601BA40, r3
    shll2 r2
    shll2 r2
    add r2, r6
    shll r6
    jsr @r3
    mov #0x8, r4
    add #0x1, r12
    extu.b r12, r2
    cmp/ge r13, r2
    bf      .L_0601B8E2
    mov #0x0, r12
    mov.l   .L_0601BA44, r2
    mov.l r2, @(8, r15)
    mov r15, r3
    add #0x21, r3
    mov.l r3, @r15
.L_0601B9BE:
    extu.b r12, r2
    mov.l @(8, r15), r3
    mov.b @r3, r3
    cmp/eq r2, r3
    bf      .L_0601B9E4
    mov.l   .L_0601BA48, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r11, r2
    tst r2, r2
    bf      .L_0601B9DC
    mov.l   .L_0601BA4C, r0
    mov.b @r0, r0
    cmp/eq #0x1, r0
    bt      .L_0601B9E0
.L_0601B9DC:
    bra     .L_0601B9E6
    extu.b r13, r9
.L_0601B9E0:
    bra     .L_0601B9E6
    extu.b r14, r9
.L_0601B9E4:
    extu.b r14, r9
.L_0601B9E6:
    extu.b r9, r7
    extu.b r12, r2
    extu.b r12, r0
    shll8 r7
    add #0x33, r2
    shll2 r7
    mov r2, r3
    shll2 r7
    shll2 r3
    shll r3
    mov r3, r2
    add r8, r2
    mov.l r2, @(4, r15)
    mov.l @(4, r2), r3
    mov.b @(r0, r10), r6
    mov.l @(4, r15), r5
    add r3, r7
    extu.b r6, r6
    mov.l @r5, r5
    mov.l @r15, r3
    mov.b @r3, r3
    extu.b r3, r2
    shll2 r2
    mov.l   .L_0601BA40, r3
    shll2 r2
    shll2 r2
    add r2, r6
    shll r6
    jsr @r3
    mov #0x8, r4
    add #0x1, r12
    extu.b r12, r2
    cmp/ge r13, r2
    bf      .L_0601B9BE
    add #0x24, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0601BA40:
    .4byte  sym_06028400
.L_0601BA44:
    .4byte  sym_0605D4F5
.L_0601BA48:
    .4byte  sym_0605D4F8
.L_0601BA4C:
    .4byte  sym_0608600E
