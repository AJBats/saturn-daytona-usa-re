
    .section .text.FUN_0602052C


    .global obj_visibility_test
    .type obj_visibility_test, @function
obj_visibility_test:
    mov.l r14, @-r15
    mov r4, r0
    mov #0x3, r3
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.b r0, @(4, r15)
    mov.l   .L_06020600, r2
    mov.w r3, @r2
    mov.l   .L_06020604, r3
    jsr @r3
    nop
    mov.l   .L_06020608, r3
    jsr @r3
    nop
    mov.l   .L_0602060C, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_0602060C, r3
    jsr @r3
    mov #0x4, r4
    mov.l   .L_06020610, r14
    mov.l   .L_06020614, r5
    mov.l   .L_06020618, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_0602061C, r5
    mov.l   .L_06020620, r4
    jsr @r14
    mov #0x20, r6
    mov #0x20, r6
    mov.l   .L_06020624, r2
    mov.l r2, @r15
    mov.l   .L_06020628, r4
    jsr @r14
    mov r2, r5
    mov #0x20, r6
    mov.l   .L_0602062C, r4
    jsr @r14
    mov.l @r15, r5
    mov.l   .L_06020630, r13
    mov #0x0, r6
    mov.l   .L_06020634, r14
    mov.w   .L_060205F2, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_06020638, r3
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov r6, r4
    mov.w   .L_060205F4, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_060205F6, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r14
    mov #0x4, r4
    mov.w   .L_060205F8, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_060205FA, r3
    mov.w   .L_060205FC, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0xC, r4
    mov #0x0, r6
    mov.l   .L_0602063C, r14
    mov r6, r5
    jsr @r14
    mov #0x20, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x8, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r14
    mov #0x4, r4
    mov.l   .L_06020640, r14
    mov.w   .L_060205FE, r4
    jsr @r14
    mov #0x0, r5
    mov #0x4, r5
    jsr @r14
    mov r5, r4
    mov #0x5, r5
    jsr @r14
    mov #0x8, r4
    mov #0x6, r5
    bra     .L_06020644
    mov #0x10, r4
.L_060205F2:
    .2byte  0x0558                          /* struct offset: display list A ptr */
.L_060205F4:
    .2byte  0x0560                          /* struct offset: display list B ptr */
.L_060205F6:
    .2byte  0x0294                          /* copy length for list B */
.L_060205F8:
    .2byte  0x0550                          /* struct offset: display list C ptr */
.L_060205FA:
    .2byte  0x6000                          /* size adjustment for list C */
.L_060205FC:
    .2byte  0x0082                          /* copy length for list C */
.L_060205FE:
    .2byte  0x0100                          /* channel ID for nibble config */
.L_06020600:
    .4byte  sym_06087804                    /* display timer (16-bit word) */
.L_06020604:
    .4byte  sym_06028560                    /* render state commit / clear */
.L_06020608:
    .4byte  gameover_channel_setup          /* game-over channel setup */
.L_0602060C:
    .4byte  sym_0602853E                    /* display layer fill config */
.L_06020610:
    .4byte  memcpy_word_idx                 /* word-indexed memcpy */
.L_06020614:
    .4byte  sym_0604898C                    /* palette source for CRAM +0x6E0 */
.L_06020618:
    .4byte  0x25F006E0                      /* VDP2 color RAM +0x6E0 */
.L_0602061C:
    .4byte  sym_060489AC                    /* palette source for CRAM +0x300 */
.L_06020620:
    .4byte  0x25F00300                      /* VDP2 color RAM +0x300 */
.L_06020624:
    .4byte  sym_060489CC                    /* palette source for CRAM +0x400 */
.L_06020628:
    .4byte  0x25F00400                      /* VDP2 color RAM +0x400 */
.L_0602062C:
    .4byte  0x25F00060                      /* VDP2 color RAM +0x060 */
.L_06020630:
    .4byte  sym_06063750                    /* obj/replay struct base ptr */
.L_06020634:
    .4byte  sym_06028400                    /* display list copy function */
.L_06020638:
    .4byte  0x00008000                      /* 0.5 (16.16 fixed-point) */
.L_0602063C:
    .4byte  display_channel_b               /* display channel enable */
.L_06020640:
    .4byte  channel_nibble_config           /* channel nibble configuration */
.L_06020644:
    jsr @r14
    nop
    mov #0x7, r5
    jsr @r14
    mov #0x20, r4
    mov #0x1, r2
    mov.l   .L_060206C8, r3
    mov.b r2, @r3
    mov.b @(4, r15), r0
    mov r0, r4
    .byte   0xB3, 0xC9    /* bsr 0x06020DEE (external) */
    extu.b r4, r4
    mov.l   .L_060206CC, r14
    mov.l   .L_060206D0, r2
    mov.l r2, @r14
    mov r2, r3
    mov.l   .L_060206D4, r2
    mov.l r3, @r2
    mov.l @r14, r3
    mov.l   .L_060206D8, r2
    mov.l r3, @r2
    mov.l   .L_060206DC, r5
    mov.l   .L_060206E0, r4
    mov.l   .L_060206E4, r3
    jsr @r3
    nop
    mov r0, r4
    mov.l   .L_060206E8, r3
    jsr @r3
    mov.l @r14, r5
    mov.l   .L_060206EC, r3
    mov.l r0, @r3
    mov.l @r14, r5
    mov.l   .L_060206F0, r2
    mov.l   .L_060206F4, r4
    mov.l   .L_060206E4, r3
    jsr @r3
    add r2, r5
    mov r0, r4
    mov.l   .L_060206E8, r3
    jsr @r3
    mov.l @r14, r5
    mov.l   .L_060206F8, r3
    mov.l r0, @r3
    mov.l   .L_060206FC, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_060206D8, r5
    mov.l   .L_060206D4, r4
    mov.l   .L_06020700, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov #0x0, r6
    mov.l   .L_060206F8, r5
    mov.l   .L_060206EC, r4
    mov.l   .L_06020704, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    mov.l   .L_06020708, r3
    jmp @r3
    mov.l @r15+, r14
.L_060206C8:
    .4byte  sym_06059F6F                    /* obj visibility mode flag (byte) */
.L_060206CC:
    .4byte  sym_06087820                    /* obj scale Z (16.16 fp) */
.L_060206D0:
    .4byte  0x00040000                      /* 4.0 (16.16 fixed-point) */
.L_060206D4:
    .4byte  sym_06087818                    /* obj scale X (16.16 fp) */
.L_060206D8:
    .4byte  sym_0608781C                    /* obj scale Y (16.16 fp) */
.L_060206DC:
    .4byte  0x00030000                      /* 3.0 (16.16 fixed-point) */
.L_060206E0:
    .4byte  0x00B00000                      /* 176.0 (16.16 fp) — half screen width */
.L_060206E4:
    .4byte  fpmul                           /* fixed-point multiply */
.L_060206E8:
    .4byte  fpdiv_setup                     /* fixed-point divide */
.L_060206EC:
    .4byte  sym_06087810                    /* obj draw X coordinate (16.16 fp) */
.L_060206F0:
    .4byte  0xFFFF0000                      /* -1.0 (16.16 fixed-point) */
.L_060206F4:
    .4byte  0x00700000                      /* 112.0 (16.16 fp) — half screen height */
.L_060206F8:
    .4byte  sym_06087814                    /* obj draw Y coordinate (16.16 fp) */
.L_060206FC:
    .4byte  sym_0603850C                    /* display cmd queue: init */
.L_06020700:
    .4byte  scene_color_intensity           /* scene color intensity */
.L_06020704:
    .4byte  scene_data_write_add            /* scene data write (additive) */
.L_06020708:
    .4byte  sym_06038520                    /* display cmd queue: commit */
