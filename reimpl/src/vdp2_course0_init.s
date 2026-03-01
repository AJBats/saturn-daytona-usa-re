
    .section .text.FUN_06003466


    .global vdp2_course0_init
    .type vdp2_course0_init, @function
vdp2_course0_init:
    mov.l r14, @-r15
    sts.l pr, @-r15

    .byte   0xD5, 0x11    /* mov.l .L_vdp2_cram_0x800, r5 */
    .byte   0xD4, 0x11    /* mov.l .L_vdp2_cram_0x200, r4 */
    .byte   0xD3, 0x12    /* mov.l .L_fn_memcpy_word, r3 */
    jsr @r3
    mov #0x60, r6

    .byte   0xDE, 0x11    /* mov.l .L_fn_dma_transfer, r14 */
    .byte   0xD5, 0x12    /* mov.l .L_vdp2_vram_0x34000, r5 */
    .byte   0xD4, 0x12    /* mov.l .L_vdp2_vram_0x4363C, r4 */
    jsr @r14
    nop

    .byte   0xD5, 0x12    /* mov.l .L_rom_pattern_base, r5 */
    .byte   0xD4, 0x12    /* mov.l .L_vdp2_vram_0x40000, r4 */
    jsr @r14
    mov.l @r5, r5

    .byte   0xD5, 0x10    /* mov.l .L_rom_pattern_base, r5 */
    mov.w   .L_pal_offset, r2
    .byte   0xD4, 0x11    /* mov.l .L_vdp2_vram_0x407F0, r4 */
    mov.l @r5, r5
    jsr @r14
    add r2, r5

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .4byte  0x09000490
.L_pal_offset:
    .2byte  0x2000                     /* offset into ROM pattern data */
    .2byte  0xFFFF
    .4byte  sym_06083255
    .4byte  sym_06063798
    .4byte  sym_06028400
    .4byte  sym_06063790
.L_vdp2_cram_0x800:
    .4byte  0x25F00800                  /* VDP2 color RAM +0x800 */
.L_vdp2_cram_0x200:
    .4byte  0x25F00200                  /* VDP2 color RAM +0x200 */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx            /* word-indexed memcpy */
.L_fn_dma_transfer:
    .4byte  dma_memory_transfer        /* SCU DMA transfer function */
.L_vdp2_vram_0x34000:
    .4byte  0x25E34000                  /* VDP2 VRAM bank B0 +0x34000 (tilemap staging) */
.L_vdp2_vram_0x4363C:
    .4byte  0x25E4363C                  /* VDP2 VRAM bank B0 +0x4363C (tilemap dest) */
.L_rom_pattern_base:
    .4byte  sym_060612AC               /* ROM source: course 0 character patterns */
.L_vdp2_vram_0x40000:
    .4byte  0x25E40000                  /* VDP2 VRAM bank B0 +0x40000 (NBG pattern A) */
.L_vdp2_vram_0x407F0:
    .4byte  0x25E407F0                  /* VDP2 VRAM bank B0 +0x407F0 (NBG pattern B) */
