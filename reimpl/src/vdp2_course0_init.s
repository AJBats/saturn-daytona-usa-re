/* vdp2_course0_init.s -- VDP2 VRAM/CRAM setup for Course 0 (Three Seven Speedway)
 * Translation unit: 0x06003466 - 0x060034D4
 *
 * Function catalog:
 *   vdp2_course0_init — Loads course-specific palettes and tilemaps into VDP2.
 *
 * Initialization sequence:
 *   1. Copy 96 bytes (48 colors) from CRAM+0x800 → CRAM+0x200 (palette bank swap)
 *   2. DMA: ROM tilemap → VDP2 VRAM+0x4363C (from intermediate VRAM+0x34000)
 *   3. DMA: ROM character patterns → VDP2 VRAM+0x40000 (NBG scroll plane data)
 *   4. DMA: ROM character patterns → VDP2 VRAM+0x407F0 (offset +0x2000 from above)
 */

    .section .text.FUN_06003466


    .global vdp2_course0_init
    .type vdp2_course0_init, @function
vdp2_course0_init:
    mov.l r14, @-r15
    sts.l pr, @-r15

    /* Step 1: Copy palette bank — CRAM+0x800 → CRAM+0x200 (96 bytes = 48 colors) */
    .byte   0xD5, 0x11    /* mov.l .L_vdp2_cram_0x800, r5 */
    .byte   0xD4, 0x11    /* mov.l .L_vdp2_cram_0x200, r4 */
    .byte   0xD3, 0x12    /* mov.l .L_fn_memcpy_word, r3 */
    jsr @r3
    mov #0x60, r6                      /* 0x60 = 96 bytes */

    /* Step 2: DMA tilemap data to VDP2 VRAM */
    .byte   0xDE, 0x11    /* mov.l .L_fn_dma_transfer, r14 */
    .byte   0xD5, 0x12    /* mov.l .L_vdp2_vram_0x34000, r5 */
    .byte   0xD4, 0x12    /* mov.l .L_vdp2_vram_0x4363C, r4 */
    jsr @r14                           /* dma_memory_transfer(dest, src) */
    nop

    /* Step 3: DMA character patterns to VRAM+0x40000 */
    .byte   0xD5, 0x12    /* mov.l .L_rom_pattern_base, r5 */
    .byte   0xD4, 0x12    /* mov.l .L_vdp2_vram_0x40000, r4 */
    jsr @r14
    mov.l @r5, r5                      /* indirect: load ROM address from pointer */

    /* Step 4: DMA more patterns to VRAM+0x407F0 (offset +0x2000) */
    .byte   0xD5, 0x10    /* mov.l .L_rom_pattern_base, r5 */
    mov.w   .L_pal_offset, r2         /* 0x2000 = offset into ROM data */
    .byte   0xD4, 0x11    /* mov.l .L_vdp2_vram_0x407F0, r4 */
    mov.l @r5, r5
    jsr @r14
    add r2, r5                         /* src = ROM base + 0x2000 */

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
