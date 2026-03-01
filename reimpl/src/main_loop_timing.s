
    .section .text.FUN_06007370


    .global main_loop_timing
    .type main_loop_timing, @function
main_loop_timing:
    sts.l pr, @-r15
    mov.l   .L_06007420, r14
    mov.l   .L_06007424, r2
    mov.l r3, @r2
    mov.w   DAT_06007412, r3
    mov.l   .L_06007428, r2
    mov.l r3, @r2
    mov.l   .L_0600742C, r3
    jsr @r3
    mov r14, r4
    mov #0x0, r6
    mov #0x2, r5
    mov.l   .L_06007430, r3
    jsr @r3
    mov r6, r4
    mov #0x0, r6
    mov.w   DAT_06007414, r2
    mov r6, r5
    mov.l r2, @-r15
    mov.w   DAT_06007416, r7
    mov.l   .L_06007434, r3
    jsr @r3
    mov r6, r4
    mov.l   .L_06007438, r4
    mov.l   .L_0600743C, r3
    jsr @r3
    add #0x4, r15
    mov.l   .L_06007440, r3
    jsr @r3
    nop
    mov.w   .L_06007418, r6
    mov.l   .L_06007444, r5
    mov.l   .L_06007448, r4
    mov.l @r14, r3
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r3, r4
    mov.l   .L_0600744C, r3
    jsr @r3
    nop
    mov.l   .L_06007450, r0
    mov.l @r0, r0
    tst #0x1, r0
    bt      .L_060073E2
    mov.w   .L_0600741A, r6
    mov.l   .L_06007454, r5
    mov.l   .L_06007448, r4
    mov.l @r14, r3
    mov.w   .L_0600741C, r2
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r3, r4
    mov.l   .L_0600744C, r3
    jsr @r3
    add r2, r4
.L_060073E2:
    mov #0x60, r6
    mov.l   .L_06007458, r5
    mov.l   .L_0600745C, r3
    jsr @r3
    mov.l @r14, r4
    mov #0x3, r2
    mov.l   .L_06007460, r3
    mov.l r2, @r3
    mov.l @r14, r2
    mov.l   .L_06007464, r3
    add #0x60, r2
    mov.w r3, @r2
    mov.l   .L_06007468, r3
    jsr @r3
    nop
    mov.l   .L_0600746C, r5
    mov.l   .L_06007470, r4
    mov.l   .L_06007474, r3
    jsr @r3
    nop
    lds.l @r15+, pr
    mov.l   .L_06007478, r3
    jmp @r3
    mov.l @r15+, r14

    .global DAT_06007412
DAT_06007412:
    .2byte  0x2468

    .global DAT_06007414
DAT_06007414:
    .2byte  0x00DF

    .global DAT_06007416
DAT_06007416:
    .2byte  0x015F
.L_06007418:
    .2byte  0x03C0
.L_0600741A:
    .2byte  0x0080
.L_0600741C:
    .2byte  0x0300
    .2byte  0xFFFF
.L_06007420:
    .4byte  sym_06063F5C
.L_06007424:
    .4byte  sym_0606A4F4
.L_06007428:
    .4byte  sym_0606A4EC
.L_0600742C:
    .4byte  vdp2_scroll_update
.L_06007430:
    .4byte  polygon_param_setup
.L_06007434:
    .4byte  sym_060393FC
.L_06007438:
    .4byte  0x0000FFFF
.L_0600743C:
    .4byte  display_param_set
.L_06007440:
    .4byte  sym_06012E00
.L_06007444:
    .4byte  0x002A0000
.L_06007448:
    .4byte  sym_06059FFC
.L_0600744C:
    .4byte  memcpy_word_idx
.L_06007450:
    .4byte  sym_0607EAB8
.L_06007454:
    .4byte  sym_06059F78
.L_06007458:
    .4byte  sym_0605A018
.L_0600745C:
    .4byte  dma_transfer
.L_06007460:
    .4byte  sym_0605A008
.L_06007464:
    .4byte  0x00008000
.L_06007468:
    .4byte  scene_setup_master
.L_0600746C:
    .4byte  sym_0606B178
.L_06007470:
    .4byte  0x002A3457
.L_06007474:
    .4byte  dma_memory_transfer
.L_06007478:
    .4byte  sym_06026CE0
