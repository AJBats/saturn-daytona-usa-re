
    .section .text.FUN_06003508


    .global vdp2_course2_init
    .type vdp2_course2_init, @function
vdp2_course2_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.w   .L_06003540, r6
    mov.l   .L_06003568, r5
    mov.l   .L_06003548, r4
    mov.l   .L_0600354C, r3
    jsr @r3
    nop
    mov.l   .L_06003550, r14
    mov.l   .L_06003554, r5
    mov.l   .L_0600356C, r4
    jsr @r14
    nop
    mov.l   .L_0600355C, r5
    mov.l   .L_06003570, r4
    jsr @r14
    mov.l @r5, r5
    mov.l   .L_0600355C, r5
    mov.w   .L_0600353E, r2
    mov.l   .L_06003574, r4
    mov.l @r5, r5
    jsr @r14
    add r2, r5
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0x00E0
.L_0600353E:
    .2byte  0x2000                          /* [HIGH] pattern block 2 offset into ROM data */
.L_06003540:
    .2byte  0x0100                          /* [HIGH] palette copy size: 0x100 words (512 bytes) */
    .2byte  0xFFFF
    .4byte  0x25F00860
.L_06003548:
    .4byte  0x25F00200                      /* VDP2 color RAM +0x200 — palette dest */
.L_0600354C:
    .4byte  memcpy_word_idx                 /* word-indexed memory copy function */
.L_06003550:
    .4byte  dma_memory_transfer             /* DMA block transfer function */
.L_06003554:
    .4byte  0x25E34000                      /* VDP2 VRAM +0x34000 — bg tile dest */
    .4byte  0x25E497E4                      /* (unused pool entry — VDP2 VRAM +0x497E4) */
.L_0600355C:
    .4byte  sym_060612AC                    /* pointer to course 2 tile/pattern source data */
    .4byte  0x25E4108C                      /* (unused pool entry — VDP2 VRAM +0x4108C) */
    .4byte  0x25E41A24                      /* (unused pool entry — VDP2 VRAM +0x41A24) */
.L_06003568:
    .4byte  0x25F00940                      /* VDP2 color RAM +0x940 — palette source */
.L_0600356C:
    .4byte  0x25E4EFEC                      /* VDP2 VRAM +0x4EFEC — bg tile source */
.L_06003570:
    .4byte  0x25E42300                      /* VDP2 VRAM +0x42300 — pattern dest block 1 */
.L_06003574:
    .4byte  0x25E42C78                      /* VDP2 VRAM +0x42C78 — pattern dest block 2 */
