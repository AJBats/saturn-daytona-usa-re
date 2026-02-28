/* vdp2_course1_init.s -- VDP2 VRAM/CRAM setup for Course 1
 * Translation unit: 0x060034D4 - 0x06003508
 *
 * Function catalog:
 *   vdp2_course1_init -- Loads course-specific palettes and tilemaps into VDP2.
 *
 * Initialization sequence (3 transfers, same pattern as course 0 and course 2):
 *   1. Copy 224 bytes (112 colors) from CRAM+0x860 to CRAM+0x200 (palette bank swap)
 *   2. DMA: tilemap data from VDP2 VRAM+0x497E4 to VRAM+0x34000
 *   3. DMA: pattern data from ROM (via sym_060612AC) to VRAM+0x4108C
 *   4. DMA: pattern data from ROM + 0x2000 offset to VRAM+0x41A24
 *
 * Pool entries are cross-TU: they reside in the vdp2_course2_init section
 * (0x06003508+). The .byte encodings preserve raw PC-relative displacements.
 *
 * CONFIDENCE: HIGH -- Same structure as annotated course 0 / course 2 siblings;
 *   all VDP2 addresses match annotation in asm/system_init.s lines 62-65.
 */

    .section .text.FUN_060034D4


    .global vdp2_course1_init
    .type vdp2_course1_init, @function
vdp2_course1_init:
    mov.l r14, @-r15                        ! save r14 (callee-save)
    sts.l pr, @-r15                         ! save return address

    /* Step 1: Copy palette bank -- CRAM+0x860 to CRAM+0x200 (224 bytes = 112 colors) */
    .byte   0x96, 0x30    /* mov.w .L_pal_copy_size, r6 */       ! r6 = 0x00E0 = 224 byte count
    .byte   0xD5, 0x1A    /* mov.l .L_vdp2_cram_0x860, r5 */    ! r5 = 0x25F00860 -- palette source in CRAM
    .byte   0xD4, 0x1A    /* mov.l .L_vdp2_cram_0x200, r4 */    ! r4 = 0x25F00200 -- palette dest in CRAM
    .byte   0xD3, 0x1B    /* mov.l .L_fn_memcpy_word_idx, r3 */ ! r3 = &memcpy_word_idx
    jsr @r3                                 ! call memcpy_word_idx(dest, src, count)
    nop                                     ! delay slot

    /* Step 2: DMA tilemap data to VDP2 VRAM */
    .byte   0xDE, 0x1A    /* mov.l .L_fn_dma_transfer, r14 */   ! r14 = &dma_memory_transfer (reused below)
    .byte   0xD5, 0x1B    /* mov.l .L_vdp2_vram_0x34000, r5 */ ! r5 = 0x25E34000 -- VRAM dest for bg tiles
    .byte   0xD4, 0x1B    /* mov.l .L_vdp2_vram_0x497E4, r4 */ ! r4 = 0x25E497E4 -- VRAM source for bg tiles
    jsr @r14                                ! call dma_memory_transfer -- bg tile data
    nop                                     ! delay slot

    /* Step 3: DMA pattern data to VRAM+0x4108C */
    .byte   0xD5, 0x1B    /* mov.l .L_ptr_course_tile_data, r5 */ ! r5 = &sym_060612AC (pointer to tile data)
    .byte   0xD4, 0x1B    /* mov.l .L_vdp2_vram_0x4108C, r4 */   ! r4 = 0x25E4108C -- VRAM dest for pattern block 1
    jsr @r14                                ! call dma_memory_transfer -- pattern block 1
    mov.l @r5, r5                           ! delay slot: r5 = *sym_060612AC (load actual src addr)

    /* Step 4: DMA pattern data + 0x2000 offset to VRAM+0x41A24 */
    .byte   0xD5, 0x19    /* mov.l .L_ptr_course_tile_data, r5 */ ! r5 = &sym_060612AC (reload pointer)
    .byte   0x92, 0x21    /* mov.w .L_pattern_blk2_offset, r2 */  ! r2 = 0x2000 -- offset into pattern data
    .byte   0xD4, 0x1A    /* mov.l .L_vdp2_vram_0x41A24, r4 */   ! r4 = 0x25E41A24 -- VRAM dest for pattern block 2
    mov.l @r5, r5                           ! r5 = *sym_060612AC (load actual src addr)
    jsr @r14                                ! call dma_memory_transfer -- pattern block 2
    add r2, r5                              ! delay slot: r5 += 0x2000 (offset to second block)

    lds.l @r15+, pr                         ! restore return address
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! delay slot: restore r14
