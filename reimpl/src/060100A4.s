	.text
    .global sprite_anim_render
sprite_anim_render:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    extu.b r14, r3
    extu.b r14, r4
    extu.b r14, r1
    mov.l r12, @-r15
    shll2 r4
    mov.l r11, @-r15
    shll2 r4
    mov.l r10, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l r3, @r15
    mov.w   DAT_060100f6, r2
    add r2, r3
    extu.w r3, r3
    mov r3, r0
    mov.w r0, @(4, r15)
    mov.l   .L_06010100, r2
    mov.w   DAT_060100f8, r12
    mov.l   .L_06010104, r13
    mov.l   .L_06010108, r0
    add r2, r4
    mov.l @r0, r0
    mov.l @r4, r10
    cmp/eq r0, r1
    bt.s    .L_06010110
    mov.l @(4, r4), r11
    mov.l @r15, r5
    add #0x3, r5
    shll2 r5
    shll2 r5
    shll r5
    mov.l   .L_0601010C, r3
    add r3, r5
    bra     .L_0601011E
    mov #0x20, r6

    .global DAT_060100f2
DAT_060100f2:
    .word 0x06A2

    .global DAT_060100f4
DAT_060100f4:
    stc vbr, r11

    .global DAT_060100f6
DAT_060100f6:
    .short  0x0101
    .global DAT_060100f8
DAT_060100f8:
    .short  0x8000
    .short  0xFFFF
    .long  sym_0605AB19
.L_06010100:
    .long  sym_060447C8
.L_06010104:
    .long  0x00010000
.L_06010108:
    .long  sym_0607EAD8
.L_0601010C:
    .long  sym_0605D0BC
.L_06010110:
    mov #0x20, r6
    extu.b r14, r5
    shll2 r5
    shll2 r5
    shll r5
    mov.l   .L_060101B4, r3
    add r3, r5
.L_0601011E:
    extu.b r14, r4
    mov.l   .L_060101B8, r2
    mov.l   .L_060101BC, r1
    shll2 r4
    add r2, r4
    jsr @r1
    mov.l @r4, r4
    mov.l   .L_060101C0, r3
    mov #0x4, r2
    mov.b @r3, r3
    extu.b r3, r3
    cmp/gt r2, r3
    bf      .L_060101EE
    extu.b r14, r2
    mov.l   .L_060101C8, r3
    mov.l   .L_060101C4, r5
    mov.l @r3, r3
    cmp/eq r3, r2
    bf.s    .L_060101A2
    mov #0x1E, r4
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r3
    extu.w r3, r3
    cmp/ge r4, r3
    bf      .L_06010160
    extu.b r14, r0
    shll r0
    mov #0x20, r3
    mov.w r3, @(r0, r5)
    mov r3, r4
    bra     .L_0601016A
    nop
.L_06010160:
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r4
    add #0x1, r4
    mov.w r4, @(r0, r5)
.L_0601016A:
    mov r14, r5
    mov r14, r3
    mov.l   .L_060101CC, r2
    shll2 r5
    shll2 r3
    shll r3
    add r3, r5
    exts.b r5, r5
    extu.w r4, r3
    add r2, r5
    mov.l @r5, r1
    mul.l r3, r1
    mov.l @(4, r5), r1
    sts macl, r3
    add r3, r10
    extu.w r4, r3
    mul.l r3, r1
    sts macl, r3
    add r3, r11
    extu.w r4, r3
    shll8 r3
    shll2 r3
    shll r3
    sub r3, r12
    extu.w r4, r4
    mov.w   DAT_060101b2, r1
    bra     .L_060101EA
    mul.l r1, r4
.L_060101A2:
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r3
    extu.w r3, r3
    cmp/ge r4, r3
    bf      .L_060101D0
    bra     .L_06010226
    nop

    .global DAT_060101b2
DAT_060101b2:
    .short  0x020C
.L_060101B4:
    .long  sym_0605D0BC
.L_060101B8:
    .long  sym_06078888
.L_060101BC:
    .long  dma_transfer
.L_060101C0:
    .long  sym_0607887F
.L_060101C4:
    .long  sym_06078870
.L_060101C8:
    .long  sym_0607EAD8
.L_060101CC:
    .long  sym_060447F8
.L_060101D0:
    extu.b r14, r0
    shll r0
    mov.w @(r0, r5), r4
    add #0x1, r4
    mov.w r4, @(r0, r5)
    extu.w r4, r3
    shll8 r3
    shll2 r3
    shll r3
    sub r3, r12
    extu.w r4, r4
    mov.w   .L_06010274, r2
    mul.l r2, r4
.L_060101EA:
    sts macl, r4
    sub r4, r13
.L_060101EE:
    mov #0xC, r2
    mov.l   .L_0601027C, r3
    mov.b @r3, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_060101FC
    mov.l   .L_06010280, r11
.L_060101FC:
    mov.l   .L_06010284, r2
    mov r11, r5
    mov.l   .L_06010288, r3
    mov.l @r2, r2
    shll2 r2
    add r3, r2
    mov.l @r2, r1
    mov.l r1, @r15
    mov.w @(4, r15), r0
    mov r0, r2
    mov.l r2, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_0601028C, r7
    mov.l @(12, r15), r6
    mov.l   .L_06010290, r2
    shlr r6
    shll16 r6
    jsr @r2
    mov r10, r4
    add #0xC, r15
.L_06010226:
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .long  0xD416E200              /* following TU code (not part of this function) */
    .long  0xD016D317
    .long  0x6001600D
    .long  0x2422203A
    .long  0x9215C9FF
    .long  0x650D3527
    .long  0x8B026242
    .long  0x72012422
    .long  0x655D930D
    .long  0x35378B02
    .long  0x63427301
    .long  0x24326242
    .long  0xD30D2320
    .long  0x6142D30D
    .long  0x000B2312
.L_06010274:
    .short  0x072B
    .short  0x0080
    .long  0x00C0FFFF
.L_0601027C:
    .long  sym_0607887F
.L_06010280:
    .long  0x00960000
.L_06010284:
    .long  sym_0605AA98
.L_06010288:
    .long  sym_06044844
.L_0601028C:
    .long  0x00200000
.L_06010290:
    .long  rigid_body_transform
    .long  sym_0607EADC
    .long  sym_06063D9C
    .long  0x0000FFFF
    .long  sym_0607887E
    .long  sym_0607EAD8
    .long  0xD519634D
    .long  0xD2192329
    .long  0x23388907
    .long  0xE202D316
    .long  0x63323323
    .long  0x89026252
    .long  0x72012522
    .long  0x644D9320
    .long  0x24392448
    .long  0x8906D310
    .long  0x63324315
    .long  0x8B026352
    .long  0x73FF2532
    .long  0x6252D30E
    .long  0x23206152
    .long  0xD30D000B
    .long  0x2312624D
