
    .section .text.FUN_0601B584


    .global course_data_loader
    .type course_data_loader, @function
course_data_loader:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601B5F8, r14
    mov.l   .L_0601B5FC, r5
    mov.l   .L_0601B600, r4
    jsr @r14
    mov #0x60, r6
    mov.l   .L_0601B604, r5
    mov.l   .L_0601B608, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_0601B60C, r5
    mov.l   .L_0601B610, r4
    jsr @r14
    mov #0x20, r6
    mov.w   .L_0601B5F4, r6
    mov.l   .L_0601B614, r5
    mov.l   .L_0601B618, r4
    mov.l   .L_0601B61C, r3
    jsr @r3
    nop
    mov.l   .L_0601B620, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_0601B624, r3
    jsr @r3
    nop
    mov.l   .L_0601B628, r2
    mov #0x16, r6
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.l   .L_0601B62C, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_0601B630, r3
    jsr @r3
    mov #0x8, r4
    mov #0x0, r6
    mov.l   .L_0601B634, r5
    mov.l   .L_0601B638, r4
    mov.b @r5, r5
    .byte   0xB2, 0x38    /* bsr 0x0601BA50 (external) */
    mov.b @r4, r4
    mov #0x0, r2
    mov.l   .L_0601B63C, r3
    mov.b r2, @r3
    mov #0x4, r2
    mov.l   .L_0601B640, r3
    mov.b r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601B5F4:
    .2byte  0x0180                      /* 384 bytes = full CRAM init block size */
    .2byte  0xFFFF
.L_0601B5F8:
    .4byte  memcpy_word_idx            /* word-indexed memcpy */
.L_0601B5FC:
    .4byte  sym_0604866C               /* source: course main palette (48 colors) */
.L_0601B600:
    .4byte  0x25F006C0                  /* VDP2 color RAM +0x6C0 — course palette bank */
.L_0601B604:
    .4byte  sym_0604862C               /* source: course extended palette A */
.L_0601B608:
    .4byte  0x25F00720                  /* VDP2 color RAM +0x720 — course ext A */
.L_0601B60C:
    .4byte  sym_060485EC               /* source: course extended palette B */
.L_0601B610:
    .4byte  0x25F00740                  /* VDP2 color RAM +0x740 — course ext B */
.L_0601B614:
    .4byte  sym_0604996C               /* source: full CRAM init palette data */
.L_0601B618:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 — base */
.L_0601B61C:
    .4byte  dma_transfer               /* DMA memory transfer */
.L_0601B620:
    .4byte  sym_0602853E               /* display channel configure */
.L_0601B624:
    .4byte  sym_06028560               /* display channel init */
.L_0601B628:
    .4byte  sym_060638C8               /* course display list descriptor */
.L_0601B62C:
    .4byte  0x0000C000                  /* offset into display list (0xC000) */
.L_0601B630:
    .4byte  sym_06028400               /* display list loader */
.L_0601B634:
    .4byte  sym_0605D4F5               /* course scroll parameter B (byte) */
.L_0601B638:
    .4byte  sym_0605D4F4               /* course scroll parameter A (byte) */
.L_0601B63C:
    .4byte  sym_0605D4FA               /* course state flag A */
.L_0601B640:
    .4byte  sym_0608600D               /* course state flag B (init = 4) */
