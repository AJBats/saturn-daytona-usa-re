	.text
    .global game_state_dispatch
game_state_dispatch:
    mov.l r14, @-r15
    mov #0x4, r3
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0600F484, r14
    mov.b @r14, r4
    extu.b r4, r4
    cmp/gt r3, r4
    bf      .L_0600F440
    mov r4, r0
    cmp/eq #0x9, r0
    bf      .L_0600F4BA
.L_0600F440:
    mov.b @r14, r0
    extu.b r0, r0
    cmp/eq #0x9, r0
    bf      .L_0600F4A4
    mov.l   .L_0600F498, r1
    mov.l   .L_0600F49C, r2
    mov.l @r1, r1
    jsr @r2
    mov #0x3C, r0
    mov r0, r7
    mov #0x18, r6
    mov.w   .L_0600F462, r5
    mov.l   .L_0600F4A0, r3
    jsr @r3
    mov #0xC, r4
    bra     .L_0600F4BA
    nop
.L_0600F462:
    .short  0x0148
    .long  0x25F00720
    .long  sym_060487CC
    .long  0x25F00680
    .long  0x25F00140
    .long  sym_060483EC
    .long  0x25F000C0
    .long  0x25F006C0
    .long  sym_0605AAA0
.L_0600F484:
    .long  sym_0607887F
    .long  sym_0605B6D8
    .long  0x40000000
    .long  sym_06026CE0
    .long  sym_06059F44
.L_0600F498:
    .long  sym_0607EBCC
.L_0600F49C:
    .long  sym_06034FE0
.L_0600F4A0:
    .long  sym_06028430
.L_0600F4A4:
    mov.l   .L_0600F524, r1
    mov.l   .L_0600F528, r2
    mov.l @r1, r1
    jsr @r2
    mov #0x3C, r0
    mov r0, r7
    mov #0x18, r6
    mov.w   .L_0600F520, r5
    mov.l   .L_0600F52C, r3
    jsr @r3
    mov #0x8, r4
.L_0600F4BA:
    mov #0xA, r3
    mov.b @r14, r2
    extu.b r2, r2
    cmp/ge r3, r2
    bf      .L_0600F562
    mov.l   .L_0600F530, r3
    mov.l   .L_0600F534, r2
    mov.w @r3, r3
    extu.w r3, r3
    cmp/eq r2, r3
    bf      .L_0600F562
    mov.l   .L_0600F538, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_0600F562
    mov.l   .L_0600F53C, r4
    mov.l   .L_0600F540, r5
    mov.l   .L_0600F544, r2
    mov.w @r4, r4
    mov.w @r2, r2
    exts.w r4, r3
    extu.w r2, r2
    and r2, r3
    tst r3, r3
    bt      .L_0600F4F4
    mov #0x0, r3
    mov.b r3, @r5
    bra     .L_0600F562
    nop
.L_0600F4F4:
    exts.w r4, r2
    mov.l   .L_0600F548, r3
    mov.w @r3, r3
    extu.w r3, r3
    and r3, r2
    tst r2, r2
    bt      .L_0600F50A
    mov #0x1, r3
    mov.b r3, @r5
    bra     .L_0600F562
    nop
.L_0600F50A:
    exts.w r4, r2
    mov.l   .L_0600F54C, r3
    mov.w @r3, r3
    extu.w r3, r3
    and r3, r2
    tst r2, r2
    bt      .L_0600F550
    mov #0x2, r3
    mov.b r3, @r5
    bra     .L_0600F562
    nop
.L_0600F520:
    .short  0x0148
    .short  0xFFFF
.L_0600F524:
    .long  sym_0607EBCC
.L_0600F528:
    .long  sym_06034FE0
.L_0600F52C:
    .long  sym_06028430
.L_0600F530:
    .long  sym_0607865E
.L_0600F534:
    .long  0x00008000
.L_0600F538:
    .long  sym_0605AB18
.L_0600F53C:
    .long  g_pad_state
.L_0600F540:
    .long  sym_06078648
.L_0600F544:
    .long  sym_06078656
.L_0600F548:
    .long  sym_06078658
.L_0600F54C:
    .long  sym_0607865A
.L_0600F550:
    exts.w r4, r4
    mov.l   .L_0600F61C, r2
    mov.w @r2, r2
    extu.w r2, r2
    and r2, r4
    tst r4, r4
    bt      .L_0600F562
    mov #0x3, r3
    mov.b r3, @r5
.L_0600F562:
    mov #0xC, r2
    mov.b @r14, r4
    extu.b r4, r4
    cmp/ge r2, r4
    bt      .L_0600F5E2
    mov #0x8, r2
    cmp/gt r2, r4
    bf      .L_0600F5E2
    mov.w   DAT_0600f612, r13
    mov.l   .L_0600F620, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600F5BC
    mov.l   .L_0600F624, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0600F5A0
    mov.l   .L_0600F628, r2
    mov r13, r6
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_0600f614, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_0600F62C, r3
    jsr @r3
    mov #0xC, r4
    bra     .L_0600F5E2
    nop
.L_0600F5A0:
    mov.l   .L_0600F630, r2
    mov r13, r6
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_0600f614, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_0600F62C, r3
    jsr @r3
    mov #0xC, r4
    bra     .L_0600F5E2
    nop
.L_0600F5BC:
    mov.l   .L_0600F634, r12
    mov r13, r5
    mov.l   .L_0600F638, r3
    mov.w   .L_0600F616, r6
    mov r12, r7
    jsr @r3
    mov #0xC, r4
    mov r12, r7
    mov.w   .L_0600F616, r6
    mov.w   DAT_0600f618, r5
    mov.l   .L_0600F638, r3
    jsr @r3
    mov #0xC, r4
    mov r12, r7
    mov #0x0, r6
    mov.w   DAT_0600f61a, r5
    mov.l   .L_0600F63C, r3
    jsr @r3
    mov #0xC, r4
.L_0600F5E2:
    mov.l   .L_0600F640, r3
    jsr @r3
    nop
    mov.b @r14, r2
    mov.l   .L_0600F644, r3
    extu.b r2, r2
    shll2 r2
    add r3, r2
    mov.l @r2, r2
    jsr @r2
    nop
    .byte   0xB4, 0xEA                   /* bsr 0x0600FFD0 (external post-state helper) */
    nop
    mov.l   .L_0600F648, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_0600F64C, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_0600f612
DAT_0600f612:
    .short  0x08A4

    .global DAT_0600f614
DAT_0600f614:
    .short  0x5000
.L_0600F616:
    .short  0x0090

    .global DAT_0600f618
DAT_0600f618:
    .short  0x09A4

    .global DAT_0600f61a
DAT_0600f61a:
    .short  0x0AA4
.L_0600F61C:
    .long  sym_0607865C
.L_0600F620:
    .long  sym_0607EAE0
.L_0600F624:
    .long  sym_06078644
.L_0600F628:
    .long  sym_06063848
.L_0600F62C:
    .long  sym_06028400
.L_0600F630:
    .long  sym_06063850
.L_0600F634:
    .long  sym_0605ACE4
.L_0600F638:
    .long  sym_060284AE
.L_0600F63C:
    .long  sym_060283E0
.L_0600F640:
    .long  sym_06026DBC
.L_0600F644:
    .long  sym_0605AC2C
.L_0600F648:
    .long  sym_06089EDC
.L_0600F64C:
    .long  frame_end_commit
