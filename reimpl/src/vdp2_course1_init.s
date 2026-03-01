
    .section .text.FUN_060034D4


    .global vdp2_course1_init
    .type vdp2_course1_init, @function
vdp2_course1_init:
    mov.l r14, @-r15
    sts.l pr, @-r15

    .byte   0x96, 0x30    /* mov.w .L_pal_copy_size, r6 */
    .byte   0xD5, 0x1A    /* mov.l .L_vdp2_cram_0x860, r5 */
    .byte   0xD4, 0x1A    /* mov.l .L_vdp2_cram_0x200, r4 */
    .byte   0xD3, 0x1B    /* mov.l .L_fn_memcpy_word_idx, r3 */
    jsr @r3
    nop

    .byte   0xDE, 0x1A    /* mov.l .L_fn_dma_transfer, r14 */
    .byte   0xD5, 0x1B    /* mov.l .L_vdp2_vram_0x34000, r5 */
    .byte   0xD4, 0x1B    /* mov.l .L_vdp2_vram_0x497E4, r4 */
    jsr @r14
    nop

    .byte   0xD5, 0x1B    /* mov.l .L_ptr_course_tile_data, r5 */
    .byte   0xD4, 0x1B    /* mov.l .L_vdp2_vram_0x4108C, r4 */
    jsr @r14
    mov.l @r5, r5

    .byte   0xD5, 0x19    /* mov.l .L_ptr_course_tile_data, r5 */
    .byte   0x92, 0x21    /* mov.w .L_pattern_blk2_offset, r2 */
    .byte   0xD4, 0x1A    /* mov.l .L_vdp2_vram_0x41A24, r4 */
    mov.l @r5, r5
    jsr @r14
    add r2, r5

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
