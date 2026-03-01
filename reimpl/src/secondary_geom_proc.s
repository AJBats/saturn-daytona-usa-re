
    .section .text.FUN_0600A76C


    .global secondary_geom_proc
    .type secondary_geom_proc, @function
secondary_geom_proc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0600A858, r12
    mov.l   .L_0600A85C, r13
    mov.l   .L_0600A860, r14
    mov.l @r14, r14
    mov.b @(1, r14), r0
    mov r0, r3
    tst r3, r3
    bt      .L_0600A7F0
    mov.l   .L_0600A864, r3
    jsr @r3
    nop
    mov.l   .L_0600A868, r11
    mov.l   .L_0600A86C, r2
    mov.w   .L_0600A854, r3
    mov.l @(8, r11), r6
    mov.l @(4, r11), r5
    mov.l @r11, r4
    add r2, r6
    add r3, r5
    mov.w   DAT_0600a856, r2
    mov.l   .L_0600A870, r3
    jsr @r3
    add r2, r4
    mov r13, r6
    mov r13, r5
    mov.l   .L_0600A874, r3
    jsr @r3
    mov r13, r4
    mov.b @r14, r5
    add #0xE, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0600A878, r3
    mov.l @r15, r4
    mov.l   .L_0600A87C, r2
    mov.l   .L_0600A880, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r14, r6
    add #0xE, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0600A884, r3
    mov.l   .L_0600A888, r5
    mov.l @r15, r4
    mov.l   .L_0600A88C, r2
    mov.l   .L_0600A890, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.l @r12, r3
    add #-0x30, r3
    mov.l r3, @r12
.L_0600A7F0:
    mov.b @(4, r14), r0
    mov r0, r2
    tst r2, r2
    bt      .L_0600A8AE
    mov.l   .L_0600A864, r3
    jsr @r3
    nop
    mov.l   .L_0600A894, r11
    mov.l   .L_0600A898, r3
    mov.w   .L_0600A854, r2
    mov.l @(8, r11), r6
    mov.l @(4, r11), r5
    neg r6, r6
    add r2, r5
    add r3, r6
    mov.l   .L_0600A870, r3
    jsr @r3
    mov.l @r11, r4
    mov r13, r6
    mov r13, r5
    mov.l   .L_0600A874, r3
    jsr @r3
    mov r13, r4
    mov.b @(3, r14), r0
    mov r0, r5
    add #0xE, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0600A878, r3
    mov.l @r15, r4
    mov.l   .L_0600A87C, r2
    mov.l   .L_0600A880, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @(3, r14), r0
    mov r0, r6
    add #0xE, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0600A884, r3
    add r3, r6
    mov.l @r6, r6
    mov.l   .L_0600A888, r5
    mov.w @r5, r5
    extu.w r5, r5
    bra     .L_0600A89C
    nop
.L_0600A854:
    .2byte  0xCCCD                      /* Y axis position adjustment (signed: -0x3333) */

    .global DAT_0600a856
DAT_0600a856:
    .2byte  0x8000                      /* X axis position adjustment (signed: -0x8000) */
.L_0600A858:
    .4byte  sym_0608A52C                /* render budget counter B */
.L_0600A85C:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_0600A860:
    .4byte  sym_0607EB8C                /* config struct pointer (indirect) */
.L_0600A864:
    .4byte  sym_06027080                /* Type B: scene matrix setup */
.L_0600A868:
    .4byte  sym_06044640                /* object A position vector (XYZ triplet) */
.L_0600A86C:
    .4byte  0xFFFF0F5D                  /* object A Z offset (signed: -0xF0A3) */
.L_0600A870:
    .4byte  sym_060270F2                /* Type B: set position transform */
.L_0600A874:
    .4byte  mat_scale_b                 /* Type B: matrix scale function */
.L_0600A878:
    .4byte  sym_060621D8                /* distance check source table */
.L_0600A87C:
    .4byte  sym_0606212C                /* distance check parameter table */
.L_0600A880:
    .4byte  sym_06032158                /* Type B: distance check function */
.L_0600A884:
    .4byte  sym_06062180                /* render submit source table */
.L_0600A888:
    .4byte  sym_06089E9C                /* display mode selector (16-bit) */
.L_0600A88C:
    .4byte  sym_060620D8                /* render submit parameter table */
.L_0600A890:
    .4byte  sym_06031DF4                /* Type B: render submit function */
.L_0600A894:
    .4byte  sym_06044670                /* object B position vector (XYZ triplet) */
.L_0600A898:
    .4byte  0xFFFDB334                  /* object B Z offset (signed: -0x24CCC) */
.L_0600A89C:
    mov.l @r15, r4
    mov.l   .L_0600A904, r2
    mov.l   .L_0600A908, r1
    add r2, r4
    jsr @r1
    mov.l @r4, r4
    mov.l @r12, r3
    add #-0x30, r3
    mov.l r3, @r12
.L_0600A8AE:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0600A8BC
sym_0600A8BC:
    mov.l   .L_0600A90C, r4
    mov.l   .L_0600A910, r5
    mov.l @r5, r5
    mov.l @(12, r5), r0
    tst r0, r0
    bt      .L_0600A8F8
    mov #0x64, r2
    mov.l @(8, r5), r3
    cmp/ge r2, r3
    bt      .L_0600A8D8
    mov.w @r4, r2
    add #0x1, r2
    bra     .L_0600A8F0
    mov.w r2, @r4
.L_0600A8D8:
    mov.l @(8, r5), r2
    mov.w   .L_0600A900, r3
    cmp/ge r3, r2
    bt      .L_0600A8EA
    mov.w @r4, r3
    add #0x2, r3
    mov.w r3, @r4
    bra     .L_0600A8F0
    nop
.L_0600A8EA:
    mov.w @r4, r2
    add #0x4, r2
    mov.w r2, @r4
.L_0600A8F0:
    mov.w @r4, r0
    and #0xF, r0
    bra     .L_0600A8FC
    mov.w r0, @r4
.L_0600A8F8:
    mov #0x0, r2
    mov.w r2, @r4
.L_0600A8FC:
    rts
    nop
.L_0600A900:
    .2byte  0x00C8                      /* 200 (speed threshold for +4 increment) */
    .2byte  0xFFFF                      /* padding */
.L_0600A904:
    .4byte  sym_060620D8                /* render param table (dup for pool reach) */
.L_0600A908:
    .4byte  sym_06031DF4                /* render submit fn (dup for pool reach) */
.L_0600A90C:
    .4byte  sym_06063F46                /* audio phase counter (16-bit word) */
.L_0600A910:
    .4byte  sym_0607E940                /* current car state pointer (indirect) */
