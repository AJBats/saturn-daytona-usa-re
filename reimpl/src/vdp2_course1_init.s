
    .section .text.FUN_060034D4


    .global vdp2_course1_init
    .type vdp2_course1_init, @function
vdp2_course1_init:
    mov.l r14, @-r15
    sts.l pr, @-r15

    .byte   0x96, 0x30    /* mov.w .L_pal_copy_size, r6 */       ! r6 = 0x00E0 = 224 byte count
    .byte   0xD5, 0x1A    /* mov.l .L_vdp2_cram_0x860, r5 */    ! r5 = 0x25F00860 -- palette source in CRAM
    .byte   0xD4, 0x1A    /* mov.l .L_vdp2_cram_0x200, r4 */    ! r4 = 0x25F00200 -- palette dest in CRAM
    .byte   0xD3, 0x1B    /* mov.l .L_fn_memcpy_word_idx, r3 */ ! r3 = &memcpy_word_idx
    jsr @r3
    nop

    .byte   0xDE, 0x1A    /* mov.l .L_fn_dma_transfer, r14 */   ! r14 = &dma_memory_transfer (reused below)
    .byte   0xD5, 0x1B    /* mov.l .L_vdp2_vram_0x34000, r5 */ ! r5 = 0x25E34000 -- VRAM dest for bg tiles
    .byte   0xD4, 0x1B    /* mov.l .L_vdp2_vram_0x497E4, r4 */ ! r4 = 0x25E497E4 -- VRAM source for bg tiles
    jsr @r14
    nop

    .byte   0xD5, 0x1B    /* mov.l .L_ptr_course_tile_data, r5 */ ! r5 = &sym_060612AC (pointer to tile data)
    .byte   0xD4, 0x1B    /* mov.l .L_vdp2_vram_0x4108C, r4 */   ! r4 = 0x25E4108C -- VRAM dest for pattern block 1
    jsr @r14
    mov.l @r5, r5

    .byte   0xD5, 0x19    /* mov.l .L_ptr_course_tile_data, r5 */ ! r5 = &sym_060612AC (reload pointer)
    .byte   0x92, 0x21    /* mov.w .L_pattern_blk2_offset, r2 */  ! r2 = 0x2000 -- offset into pattern data
    .byte   0xD4, 0x1A    /* mov.l .L_vdp2_vram_0x41A24, r4 */   ! r4 = 0x25E41A24 -- VRAM dest for pattern block 2
    mov.l @r5, r5
    jsr @r14
    add r2, r5

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
