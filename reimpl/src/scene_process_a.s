
    .section .text.FUN_06025224


    .global scene_process_a
    .type scene_process_a, @function
scene_process_a:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x18, r15
    mov.w   DAT_0602528a, r8
    mov.l   .L_06025294, r12
    mov.l   .L_06025298, r14
    mov r8, r11
    mov.l r4, @(4, r15)
    mov.l   .L_0602529C, r4
    mov.w   .L_0602528C, r13
    mov.w   .L_0602528E, r10
    mov.b @r4, r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf/s    .L_06025272
    add #0xB, r11
    mov.l   .L_060252A0, r7
    mov r13, r5
    mov.l   .L_060252A4, r3
    mov.w   .L_06025290, r6
    jsr @r3
    mov #0x8, r4
    mov r12, r7
    add r10, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06025292, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    bra     .L_060252D0
    nop
.L_06025272:
    mov.b @r4, r0
    extu.b r0, r0
    cmp/eq #0x5, r0
    bf      .L_060252AC
    mov.l   .L_060252A8, r7
    mov r13, r5
    mov.l   .L_060252A4, r3
    mov.w   .L_06025290, r6
    jsr @r3
    mov #0x8, r4
    bra     .L_060252B8
    nop

    .global DAT_0602528a
DAT_0602528a:
    .2byte  0x00A9                      /* render param (physics mode) */
.L_0602528C:
    .2byte  0x0C08                      /* scene data block size */
.L_0602528E:
    .2byte  0x0590                      /* offset into obj table for main entry */
.L_06025290:
    .2byte  0x0090                      /* DMA transfer size (small) */

    .global DAT_06025292
DAT_06025292:
    .2byte  0x0C3E                      /* layer size for state 4 extra pass */
.L_06025294:
    .4byte  sym_06063750                /* car/obj table base (8-byte stride) */
.L_06025298:
    .4byte  sym_06028400                /* layer setup / geometry dispatch */
.L_0602529C:
    .4byte  sym_06061198                /* game state byte */
.L_060252A0:
    .4byte  sym_060590B8                /* scene data for state 4 (race) */
.L_060252A4:
    .4byte  sym_060284AE                /* geometry dispatch function */
.L_060252A8:
    .4byte  sym_060590E0                /* scene data for state 5 (post-race) */
.L_060252AC:
    mov.l   .L_06025390, r7
    mov r13, r5
    mov.l   .L_06025394, r3
    mov.w   .L_06025378, r6
    jsr @r3
    mov #0x8, r4
.L_060252B8:
    mov r12, r13
    mov.w   DAT_0602537a, r6
    add r10, r13
    mov.l @(4, r13), r7
    mov.l @r13, r5
    jsr @r14
    mov #0x8, r4
    mov.l @(4, r13), r7
    mov.w   DAT_0602537c, r6
    mov.l @r13, r5
    jsr @r14
    mov #0x8, r4
.L_060252D0:
    mov.l @(4, r15), r7
    mov.l   .L_06025398, r3
    mov.w   .L_06025378, r6
    mov.w   DAT_0602537e, r5
    mov.l   .L_06025394, r2
    shll2 r7
    shll r7
    add r3, r7
    jsr @r2
    mov #0x8, r4
    mov.w   DAT_06025380, r7
    mov #0x10, r6
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06025382, r3
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_06025384, r7
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06025386, r3
    mov.w   .L_06025388, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_0602538a, r7
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06025386, r3
    mov.w   .L_0602538C, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov #0x0, r13
    mov.l @(4, r15), r10
    shll2 r10
    mov.l   .L_0602539C, r3
    add r3, r10
.L_06025330:
    extu.w r8, r5
    mov.l   .L_060253A0, r3
    jsr @r3
    extu.w r13, r4
    mov r13, r2
    mov.l @r10, r3
    shll2 r2
    shll r2
    add r3, r2
    mov.w @(6, r2), r0
    mov r0, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bf      .L_06025360
    mov.l   .L_060253A4, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bt      .L_06025360
    mov.l   .L_060253A4, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x5, r0
    bf      .L_06025446
.L_06025360:
    mov r13, r9
    mov.l @r10, r3
    shll2 r9
    shll r9
    add r9, r3
    mov.w @(6, r3), r0
    mov r0, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bt      .L_060253A8
    bra     .L_060253AA
    mov #0x8, r2
.L_06025378:
    .2byte  0x0090                      /* DMA transfer size (small, 2nd pool copy) */

    .global DAT_0602537a
DAT_0602537a:
    .2byte  0x0C34                      /* layer A size (states 5/default) */

    .global DAT_0602537c
DAT_0602537c:
    .2byte  0x0C4E                      /* layer B size (states 5/default) */

    .global DAT_0602537e
DAT_0602537e:
    .2byte  0x02A4                      /* slot table entry size */

    .global DAT_06025380
DAT_06025380:
    .2byte  0x0428                      /* obj table offset: layer 1 */

    .global DAT_06025382
DAT_06025382:
    .2byte  0x6000                      /* frame data offset: layer 1 */

    .global DAT_06025384
DAT_06025384:
    .2byte  0x0430                      /* obj table offset: layer 2 */

    .global DAT_06025386
DAT_06025386:
    .2byte  0x7000                      /* frame data offset: layers 2 & 3 */
.L_06025388:
    .2byte  0x02A0                      /* DMA transfer size (medium) */

    .global DAT_0602538a
DAT_0602538a:
    .2byte  0x0438                      /* obj table offset: layer 3 */
.L_0602538C:
    .2byte  0x02B4                      /* DMA transfer size (large) */
    .2byte  0xFFFF                      /* alignment padding */
.L_06025390:
    .4byte  sym_06059104                /* scene data for default state */
.L_06025394:
    .4byte  sym_060284AE                /* geometry dispatch (2nd pool copy) */
.L_06025398:
    .4byte  sym_06058F94                /* scene slot table base */
.L_0602539C:
    .4byte  sym_06061170                /* render record table (4-byte per car) */
.L_060253A0:
    .4byte  car_physics_final           /* per-car physics final update */
.L_060253A4:
    .4byte  sym_06061198                /* game state byte (2nd pool copy) */
.L_060253A8:
    mov #0x9, r2
.L_060253AA:
    extu.w r2, r2
    mov r13, r6
    mov r2, r0
    shll r6
    mov.w r0, @(16, r15)
    mov.l   .L_06025468, r7
    add r9, r7
    mov.l r7, @r15
    mov.l @r7, r7
    shll2 r7
    shll r7
    add r12, r7
    mov.l r7, @(8, r15)
    mov.l @(4, r7), r7
    mov.l   .L_0602546C, r3
    mov.l r6, @(4, r15)
    add r3, r7
    mov.l   .L_06025470, r3
    add r3, r6
    mov.l r6, @(12, r15)
    mov.b @(1, r6), r0
    mov.l @(12, r15), r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(8, r15), r5
    mov.l @r15, r4
    mov.l @r5, r5
    add #0x4, r4
    mov.l r4, @(20, r15)
    mov.l @r4, r4
    jsr @r14
    shll2 r4
    mov.w @(16, r15), r0
    mov.l @r10, r3
    mov r0, r7
    add r9, r3
    extu.w r7, r7
    mov.w @(6, r3), r0
    shll8 r7
    mov r0, r2
    shll2 r7
    extu.w r2, r3
    shll2 r7
    shll2 r3
    shll r3
    mov r12, r2
    add r3, r2
    mov.l r2, @(8, r15)
    mov.l @(4, r2), r3
    add r3, r7
    mov.l @(4, r15), r6
    mov.l   .L_06025474, r3
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov r0, r6
    extu.b r6, r6
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @r15, r2
    mov.b @r2, r2
    extu.b r2, r2
    add r2, r6
    shll r6
    mov.l @(8, r15), r5
    mov.l @(20, r15), r4
    mov.l @r5, r5
    mov.l @r4, r4
    jsr @r14
    shll2 r4
.L_06025446:
    add #0x1, r13
    mov #0xA, r3
    cmp/ge r3, r13
    bt      .L_06025452
    bra     .L_06025330
    nop
.L_06025452:
    add #0x18, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF                      /* alignment padding */
.L_06025468:
    .4byte  sym_06058FBC                /* per-slot offset entries (8-byte stride) */
.L_0602546C:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point rounding) */
.L_06025470:
    .4byte  sym_0605904C                /* direction pair table A (2-byte stride) */
.L_06025474:
    .4byte  sym_06059060                /* direction pair table B (2-byte stride) */
