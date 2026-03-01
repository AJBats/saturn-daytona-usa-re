
    .section .text.FUN_06010760


    .global adv_anim_state
    .type adv_anim_state, @function
adv_anim_state:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov #0x1, r8
    mov #0x0, r9
    mov.l   .L_060107B4, r10
    mov.l   .L_060107B8, r12
    mov.l   .L_060107BC, r13
    mov.l   .L_060107C0, r14
    mov.l   .L_060107C4, r0
    bra     .L_06010792
    mov.b @r0, r0
.L_06010782:
    bra     .L_060107C8
    mov #0x5, r4
.L_06010786:
    bra     .L_060107C8
    mov #0x7, r4
.L_0601078A:
    bra     .L_060107C8
    mov #0x9, r4
.L_0601078E:
    bra     .L_060107C8
    mov #0x3, r4
.L_06010792:
    cmp/eq #0x1, r0
    bt      .L_06010782
    cmp/eq #0x2, r0
    bt      .L_06010782
    cmp/eq #0x3, r0
    bt      .L_06010786
    cmp/eq #0x4, r0
    bt      .L_06010782
    cmp/eq #0x5, r0
    bt      .L_06010786
    cmp/eq #0x6, r0
    bt      .L_06010786
    cmp/eq #0x7, r0
    bt      .L_0601078A
    bra     .L_0601078E
    nop
    .2byte  0xFFFF
.L_060107B4:
    .4byte  memcpy_word_idx                  /* word-indexed memcpy routine */
.L_060107B8:
    .4byte  sym_060788A8                     /* DMA pair toggle flag (byte) */
.L_060107BC:
    .4byte  sym_06078868                     /* frame mirror / sprite index (dword) */
.L_060107C0:
    .4byte  sym_0607EADC                     /* animation frame counter (dword) */
.L_060107C4:
    .4byte  sym_0605AB16                     /* game mode byte (1-7) */
.L_060107C8:
    mov.l   .L_06010874, r0
    mov.b @r0, r0
    cmp/eq #0x7, r0
    bf      .L_060107D2
    mov #0xB, r4
.L_060107D2:
    mov.l   .L_06010874, r0
    mov.b @r0, r0
    cmp/eq #0xF, r0
    bf      .L_060107DC
    mov #0xD, r4
.L_060107DC:
    mov.l   .L_06010878, r0
    mov.l   .L_0601087C, r3
    mov.w @r0, r0
    extu.w r0, r0
    xor r3, r0
    and #0xFF, r0
    mov.w   .L_06010870, r3
    extu.w r0, r11
    cmp/gt r3, r11
    bf      .L_06010832
    mov.l   .L_06010880, r3
    mov.l   .L_06010884, r2
    mov.l r3, @r2
    mov #0x1E, r3
    mov.l   .L_06010888, r2
    mov.l r3, @r2
    mov.l @r14, r3
    add #0x1, r3
    mov r3, r2
    mov.l r3, @r14
    cmp/gt r4, r2
    bf      .L_0601080A
    mov.l r9, @r14
.L_0601080A:
    mov.l   .L_0601088C, r5
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06010826
    extu.b r9, r3
    mov.b r3, @r12
    mov.l   .L_06010890, r3
    mov.l r5, @r3
    mov.l @r14, r2
    mov.l   .L_06010894, r3
    mov.l r2, @r3
    bra     .L_06010832
    nop
.L_06010826:
    mov.b r8, @r12
    mov.l   .L_06010898, r3
    mov.l r5, @r3
    mov.l @r14, r2
    mov.l   .L_0601089C, r3
    mov.l r2, @r3
.L_06010832:
    extu.w r11, r2
    mov #0x70, r3
    cmp/ge r3, r2
    bt      .L_060108B4
    mov.l   .L_060108A0, r3
    mov.l   .L_06010884, r2
    mov.l r3, @r2
    mov #0x1E, r3
    mov.l   .L_06010888, r2
    mov.l r3, @r2
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov r3, r2
    cmp/pz r2
    bt      .L_06010854
    mov.l r4, @r14
.L_06010854:
    mov.l   .L_060108A4, r4
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_060108A8
    extu.b r9, r3
    mov.b r3, @r12
    mov.l   .L_06010890, r3
    mov.l r4, @r3
    mov.l @r14, r2
    mov.l   .L_06010894, r3
    mov.l r2, @r3
    bra     .L_060108B4
    nop
.L_06010870:
    .2byte  0x0090                           /* forward input threshold (> this = fwd) */
    .2byte  0xFFFF                           /* alignment padding */
.L_06010874:
    .4byte  sym_0605AB17                     /* overlay flags byte */
.L_06010878:
    .4byte  sym_06063D9C                     /* input state word (button/analog) */
.L_0601087C:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_06010880:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_06010884:
    .4byte  sym_0607889C                     /* per-frame scroll delta (16.16 fp) */
.L_06010888:
    .4byte  sym_0605AA9C                     /* animation hold timer (frames) */
.L_0601088C:
    .4byte  0x000C0000                       /* +12.0 (16.16 fp) — forward DMA size */
.L_06010890:
    .4byte  sym_06078894                     /* scroll X position accumulator */
.L_06010894:
    .4byte  sym_060788A0                     /* game state counter (pair A) */
.L_06010898:
    .4byte  sym_06078898                     /* scroll Y position accumulator */
.L_0601089C:
    .4byte  sym_060788A4                     /* frame index (pair B) */
.L_060108A0:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_060108A4:
    .4byte  0xFFF40000                       /* -12.0 (16.16 fp) — backward DMA size */
.L_060108A8:
    mov.b r8, @r12
    mov.l   .L_06010974, r3
    mov.l r4, @r3
    mov.l @r14, r2
    mov.l   .L_06010978, r3
    mov.l r2, @r3
.L_060108B4:
    mov.l @r14, r2
    mov.l r2, @r13
    mov r2, r3
    and r8, r3
    mov.l   .L_0601097C, r2
    mov.l r3, @r2
    mov.l @r13, r1
    mov #0xA, r2
    cmp/hs r2, r1
    bt      .L_06010912
    mov.b @r12, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_060108F2
    mov.w   DAT_0601096e, r6
    mov.l @r13, r5
    mov.l   .L_06010980, r3
    mov.l   .L_06010984, r4
    shll2 r5
    mov.l @r4, r4
    add r3, r5
    shll2 r4
    mov.l @r5, r5
    shll r4
    mov.l   .L_06010988, r2
    mov.l @r2, r2
    add r2, r4
    mov r6, r1
    add #0x40, r1
    bra     .L_0601090E
    add r1, r4
.L_060108F2:
    mov.w   DAT_0601096e, r6
    mov.l @r13, r5
    mov.l   .L_06010980, r3
    mov.l   .L_06010984, r4
    shll2 r5
    mov.l @r4, r4
    add r3, r5
    shll2 r4
    mov.l @r5, r5
    shll r4
    mov.l   .L_06010988, r2
    mov.l @r2, r2
    add r2, r4
    add #0x40, r4
.L_0601090E:
    jsr @r10
    nop
.L_06010912:
    extu.w r11, r4
    mov #0x70, r3
    cmp/ge r3, r4
    bf      .L_06010920
    mov.w   .L_06010970, r3
    cmp/gt r3, r4
    bf      .L_0601095C
.L_06010920:
    mov.l @r13, r3
    mov #0xC, r2
    cmp/hs r2, r3
    bt      .L_06010938
    mov.l @r13, r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov.l   .L_0601098C, r3
    add r3, r5
    bra     .L_06010948
    mov #0x40, r6
.L_06010938:
    mov #0x40, r6
    mov.l @r13, r5
    add #-0x2, r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov.l   .L_0601098C, r3
    add r3, r5
.L_06010948:
    mov.l   .L_0601097C, r4
    mov.l   .L_06010990, r2
    mov.l @r4, r4
    shll r4
    add #0x23, r4
    shll2 r4
    shll2 r4
    shll r4
    jsr @r10
    add r2, r4
.L_0601095C:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601096e
DAT_0601096e:
    .2byte  0x00C0                           /* tile block size (192 bytes) */
.L_06010970:
    .2byte  0x0090                           /* upper dead zone bound for palette skip */
    .2byte  0xFFFF                           /* alignment padding */
.L_06010974:
    .4byte  sym_06078898                     /* scroll Y accumulator (pair B, 2nd ref) */
.L_06010978:
    .4byte  sym_060788A4                     /* frame index pair B (2nd ref) */
.L_0601097C:
    .4byte  sym_0607EAB8                     /* frame output (odd/even selector) */
.L_06010980:
    .4byte  sym_0605D05C                     /* tile data lookup table base */
.L_06010984:
    .4byte  sym_06059FFC                     /* current game state index */
.L_06010988:
    .4byte  sym_06063F5C                     /* car struct array base pointer */
.L_0601098C:
    .4byte  sym_0605CA9C                     /* 64-byte palette entry table base */
.L_06010990:
    .4byte  0x25F00000                       /* VDP2 color RAM base address */
