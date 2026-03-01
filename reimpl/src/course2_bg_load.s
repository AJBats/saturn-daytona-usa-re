
    .section .text.FUN_06018938


    .global course2_bg_load
    .type course2_bg_load, @function
course2_bg_load:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x8, r10
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_060189E4, r11
    mov.l   .L_060189E8, r12
    mov.l   .L_060189EC, r14
    mov.l   .L_060189F0, r13
    mov.w   .L_060189DE, r6
    mov.l   .L_060189F4, r9
    mov.l   .L_060189F8, r4
    jsr @r13
    mov r9, r5
    mov.l   .L_060189FC, r6
    mov.w   .L_060189DE, r5
    mov.l   .L_06018A00, r4
    jsr @r13
    add r9, r5
    mov.l   .L_06018A04, r6
    mov.l   .L_06018A08, r5
    add r9, r5
    jsr @r13
    mov r14, r4
    mov.l   .L_06018A0C, r6
    mov.l   .L_06018A10, r9
    mov.l   .L_06018A14, r4
    jsr @r13
    mov r9, r5
    mov.w   .L_060189E0, r6
    mov.l   .L_06018A18, r5
    mov.l   .L_06018A1C, r4
    jsr @r13
    add r9, r5
    mov.w   .L_060189E2, r6
    mov.l   .L_06018A20, r5
    mov.l   .L_06018A24, r4
    jsr @r13
    add r9, r5
    mov.w   .L_060189E0, r6
    mov.l   .L_06018A28, r5
    mov.l   .L_06018A2C, r4
    jsr @r13
    add r9, r5
    mov #0x0, r6
    mov r6, r5
    mov r6, r4
.L_0601899C:
    mov r4, r2
    mov r4, r3
    add #0x2, r5
    add r11, r2
    add r12, r3
    add #0x4, r4
    mov.l @r2, r1
    mov r4, r6
    add r14, r1
    mov r4, r2
    mov.l r1, @r3
    add r11, r2
    mov r4, r3
    mov.l @r2, r1
    add r12, r3
    add r14, r1
    mov.l r1, @r3
    cmp/ge r10, r5
    bf/s    .L_0601899C
    add #0x4, r4
    mov.l   .L_06018A30, r4
    mov.l   .L_06018A34, r3
    jsr @r3
    mov.l @r4, r4
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_06018A38, r3
    jmp @r3
    mov.l @r15+, r14
.L_060189DE:
    .2byte  0x10A0                        /* palette data: 4256 bytes */
.L_060189E0:
    .2byte  0x3000                        /* tile set B/D: 12288 bytes */
.L_060189E2:
    .2byte  0x4000                        /* tile set C: 16384 bytes */
.L_060189E4:
    .4byte  sym_0605D21C               /* BG offset source table */
.L_060189E8:
    .4byte  sym_06085FD0               /* BG offset dest table */
.L_060189EC:
    .4byte  sym_060D6900               /* BG data base address (course 2) */
.L_060189F0:
    .4byte  memcpy_long_idx            /* long-indexed memory copy */
.L_060189F4:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_060189F8:
    .4byte  sym_060D5840               /* palette source data */
.L_060189FC:
    .4byte  0x0000F800                  /* tile set A: 63488 bytes */
.L_06018A00:
    .4byte  sym_060C6000               /* tile set A source */
.L_06018A04:
    .4byte  0x00017A00                  /* base BG data: 97792 bytes */
.L_06018A08:
    .4byte  0x000108A0                  /* WRAM offset for base BG */
.L_06018A0C:
    .4byte  0x00019000                  /* map data: 100KB */
.L_06018A10:
    .4byte  0x00240000                  /* VRAM destination base */
.L_06018A14:
    .4byte  sym_060A6000               /* map data source */
.L_06018A18:
    .4byte  0x0001C598                  /* VRAM offset for tile set B */
.L_06018A1C:
    .4byte  sym_060BF000               /* tile set B source */
.L_06018A20:
    .4byte  0x00018598                  /* VRAM offset for tile set C */
.L_06018A24:
    .4byte  sym_060C2000               /* tile set C source */
.L_06018A28:
    .4byte  0x0001EEA0                  /* VRAM offset for data block D */
.L_06018A2C:
    .4byte  0x002F8000                  /* data block D source address */
.L_06018A30:
    .4byte  sym_0607EAD8               /* race end state variable */
.L_06018A34:
    .4byte  sound_init_sequence        /* sound initialization for course */
.L_06018A38:
    .4byte  render_stage_c             /* render stage C entry point */
