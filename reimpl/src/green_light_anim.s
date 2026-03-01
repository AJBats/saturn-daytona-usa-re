
    .section .text.FUN_0601A348


    .global green_light_anim
    .type green_light_anim, @function
green_light_anim:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601A3C0, r14
    mov.l   .L_0601A3C4, r3
    mov.l r3, @r15
    mov.l   .L_0601A3C8, r4
    jsr @r14
    mov r3, r5
    mov #0x60, r6
    mov.l   .L_0601A3CC, r4
    jsr @r14
    mov.l @r15, r5
    mov.l   .L_0601A3D0, r5
    mov.l   .L_0601A3D4, r4
    jsr @r14
    mov #0x40, r6
    mov.l   .L_0601A3D8, r3
    jsr @r3
    nop
    mov.l   .L_0601A3DC, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_0601A390
    mov #0x0, r6
    mov.l   .L_0601A3E0, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.l   .L_0601A3E4, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    bra     .L_0601A3A8
    nop
.L_0601A390:
    mov.l   .L_0601A3E8, r2
    mov #0x0, r6
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   .L_0601A3BE, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_0601A3E4, r3
    jsr @r3
    mov #0x4, r4
.L_0601A3A8:
    mov.l   .L_0601A3EC, r3
    jsr @r3
    nop
    mov.l   .L_0601A3F0, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601A3BE:
    .2byte  0x1000                      /* display list offset for alternate frame */
.L_0601A3C0:
    .4byte  memcpy_word_idx            /* word-indexed memcpy */
.L_0601A3C4:
    .4byte  sym_0605CF9C               /* source: traffic light palette (48 colors) */
.L_0601A3C8:
    .4byte  0x25F00020                  /* VDP2 color RAM +0x020 — traffic light low */
.L_0601A3CC:
    .4byte  0x25F00620                  /* VDP2 color RAM +0x620 — traffic light high mirror */
.L_0601A3D0:
    .4byte  sym_0605D01C               /* source: start sequence sprite palette */
.L_0601A3D4:
    .4byte  0x25F00400                  /* VDP2 color RAM +0x400 — sprite bank */
.L_0601A3D8:
    .4byte  race_data_handler          /* race state update */
.L_0601A3DC:
    .4byte  sym_06063D9E               /* game timer (16-bit) — 0x10 = green light moment */
.L_0601A3E0:
    .4byte  sym_06063C90               /* display list descriptor A (green ON) */
.L_0601A3E4:
    .4byte  sym_06028400               /* display list loader */
.L_0601A3E8:
    .4byte  sym_06063C98               /* display list descriptor B (alternate) */
.L_0601A3EC:
    .4byte  sym_06026CE0               /* post-process display commit */
.L_0601A3F0:
    .4byte  sym_06085FF2               /* animation frame counter (byte) */
