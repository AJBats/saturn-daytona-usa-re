
    .section .text.FUN_06020E84


    .global obj_render_setup
    .type obj_render_setup, @function
obj_render_setup:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_06020F34, r10
    mov.l   .L_06020F38, r11
    mov.l   .L_06020F3C, r14
    mov.l   .L_06020F40, r4
    mov.b @r4, r0
    extu.b r0, r0
    tst r0, r0
    bt/s    .L_06020EA2
    mov #0x0, r13
    mov #0xA, r3
    mov.b r3, @r10
    extu.b r13, r2
    mov.b r2, @r4
.L_06020EA2:
    mov.b @r10, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06020EB0
    mov.b @r10, r3
    add #-0x1, r3
    mov.b r3, @r10
.L_06020EB0:
    mov.l   .L_06020F44, r2
    mov.w   DAT_06020f2e, r0
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    mov.l   .L_06020F48, r2
    mov.l @r2, r2
    cmp/eq r2, r3
    bt      .L_06020FAE
    mov.l   .L_06020F4C, r2
    mov.b @r2, r2
    tst r2, r2
    bf      .L_06020FAE
    mov.w   .L_06020F30, r9
    mov.l   .L_06020F50, r12
    mov.l   .L_06020F44, r0
    mov.l @r0, r0
    mov.w   DAT_06020f2e, r1
    mov.l @(r0, r1), r0
    bra     .L_06020F9A
    and #0xCC, r0
.L_06020ED8:
    mov r12, r7
    mov r9, r6
    add #0x60, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l @r15, r5
    mov.l   .L_06020F54, r3
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    bra     .L_06020FAE
    nop
.L_06020EF0:
    mov.b @r11, r0
    tst r0, r0
    bf      .L_06020EFA
    bra     .L_06020EFC
    mov #0xB, r7
.L_06020EFA:
    mov #0xA, r7
.L_06020EFC:
    shll2 r7
    mov.b @r11, r0
    shll r7
    add r12, r7
    mov.l @(4, r7), r7
    tst r0, r0
    bf/s    .L_06020F10
    mov r9, r6
    bra     .L_06020F12
    mov #0xB, r5
.L_06020F10:
    mov #0xA, r5
.L_06020F12:
    shll2 r5
    mov.l   .L_06020F54, r3
    shll r5
    add r12, r5
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    bra     .L_06020FAE
    nop
.L_06020F24:
    mov.b @r11, r0
    tst r0, r0
    bf      .L_06020F58
    bra     .L_06020F5A
    mov #0xA, r7

    .global DAT_06020f2e
DAT_06020f2e:
    .2byte  0x0214                          /* car state struct view mode offset */
.L_06020F30:
    .2byte  0x0900                          /* VRAM destination offset for tile blit */
    .2byte  0xFFFF                          /* padding */
.L_06020F34:
    .4byte  sym_06089594                    /* render countdown timer (byte) */
.L_06020F38:
    .4byte  sym_06078663                    /* camera direction flip flag (byte) */
.L_06020F3C:
    .4byte  sym_06087C84                    /* scene config struct base */
.L_06020F40:
    .4byte  sym_06089595                    /* render trigger flag (byte) */
.L_06020F44:
    .4byte  sym_0607E944                    /* car array base pointer */
.L_06020F48:
    .4byte  sym_06089598                    /* previous car state (for change detect) */
.L_06020F4C:
    .4byte  sym_06083255                    /* secondary SH-2 processing flag */
.L_06020F50:
    .4byte  sym_06063750                    /* scene tile config table */
.L_06020F54:
    .4byte  sym_06028400                    /* tile_rect_blit function */
.L_06020F58:
    mov #0xB, r7
.L_06020F5A:
    shll2 r7
    mov.b @r11, r0
    shll r7
    add r12, r7
    mov.l @(4, r7), r7
    tst r0, r0
    bf/s    .L_06020F6E
    mov r9, r6
    bra     .L_06020F70
    mov #0xA, r5
.L_06020F6E:
    mov #0xB, r5
.L_06020F70:
    shll2 r5
    mov.l   .L_06020FCC, r3
    shll r5
    add r12, r5
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    bra     .L_06020FAE
    nop
.L_06020F82:
    mov r12, r7
    mov r9, r6
    add #0x48, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l @r15, r5
    mov.l   .L_06020FCC, r3
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    bra     .L_06020FAE
    nop
.L_06020F9A:
    cmp/eq #0x0, r0
    bt      .L_06020F82
    cmp/eq #0x44, r0
    bt      .L_06020F24
    mov.w   .L_06020FC6, r1
    cmp/eq r1, r0
    bt      .L_06020EF0
    mov.w   DAT_06020fc8, r1
    cmp/eq r1, r0
    bt      .L_06020ED8
.L_06020FAE:
    mov.l   .L_06020FD0, r2
    mov.w   DAT_06020fca, r0
    mov.l   .L_06020FD4, r1
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    mov.l r3, @r1
    mov.l   .L_06020FD8, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bt      .L_06020FDC
    bra     .L_06021084
    nop
.L_06020FC6:
    .2byte  0x0088                          /* view mode: rear-view mirror */

    .global DAT_06020fc8
DAT_06020fc8:
    .2byte  0x00CC                          /* view mode: replay camera */

    .global DAT_06020fca
DAT_06020fca:
    .2byte  0x0214                          /* car state struct view mode offset (dup) */
.L_06020FCC:
    .4byte  sym_06028400                    /* tile_rect_blit function (pool B copy) */
.L_06020FD0:
    .4byte  sym_0607E944                    /* car array base pointer (pool B copy) */
.L_06020FD4:
    .4byte  sym_06089598                    /* current car state store (for secondary) */
.L_06020FD8:
    .4byte  sym_06063E20                    /* game state flag (1 = active race) */
.L_06020FDC:
    mov r13, r12
    mov r13, r6
    mov.b @r10, r7
    mov #0x60, r0
    mov.l   .L_060210A0, r3
    mov.l   .L_060210A4, r4
    extu.b r7, r7
    mov.l @r4, r4
    shll2 r7
    mov.l @(r0, r4), r4
    add r3, r7
    shar r4
    mov.b @r11, r0
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    tst r0, r0
    bt/s    .L_06021018
    mov.l @r7, r7
    neg r4, r4
.L_06021018:
    mov.w   DAT_06021098, r3
    cmp/ge r3, r4
    bt      .L_06021026
    mov.w   DAT_0602109a, r3
    cmp/gt r3, r4
    bf      .L_06021026
    mov r13, r4
.L_06021026:
    mov.w   DAT_0602109c, r0
    mov.l r13, @(r0, r14)
    extu.b r13, r5
.L_0602102C:
    add r4, r12
    extu.b r5, r3
    mov r8, r2
    sub r4, r6
    mov r12, r1
    sub r3, r2
    add r7, r1
    shll2 r2
    mov.w   DAT_0602109e, r3
    add r14, r3
    add r3, r2
    extu.b r5, r3
    mov.l r1, @r2
    shll2 r3
    add #0x1, r5
    mov r6, r1
    mov.w   DAT_0602109e, r2
    add r7, r1
    add r14, r2
    add r2, r3
    add #0x58, r3
    mov #0x16, r2
    mov.l r1, @r3
    extu.b r5, r3
    cmp/ge r2, r3
    bf      .L_0602102C
    mov.l   .L_060210A8, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_060210AC, r4
    mov.l   .L_060210B0, r3
    jsr @r3
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_060210B4, r3
    jmp @r3
    mov.l @r15+, r14
.L_06021084:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06021098
DAT_06021098:
    .2byte  0x1000                          /* heading step positive clamp (+4096) */

    .global DAT_0602109a
DAT_0602109a:
    .2byte  0xF000                          /* heading step negative clamp (-4096 sign-ext) */

    .global DAT_0602109c
DAT_0602109c:
    .2byte  0x1868                          /* config clear field offset */

    .global DAT_0602109e
DAT_0602109e:
    .2byte  0x1810                          /* scene coord array offset in config */
.L_060210A0:
    .4byte  sym_0604D3E0                    /* heading-to-Y lookup table (indexed by timer) */
.L_060210A4:
    .4byte  sym_0607E944                    /* car array base pointer (pool C copy) */
.L_060210A8:
    .4byte  sym_0603850C                    /* cmd_slot_write (command queue channel write) */
.L_060210AC:
    .4byte  sym_06087C84                    /* scene config base (arg for scene_buffer_init) */
.L_060210B0:
    .4byte  scene_buffer_init               /* scene buffer initialization function */
.L_060210B4:
    .4byte  sym_06038520                    /* cmd_queue_commit (signal command ready) */
