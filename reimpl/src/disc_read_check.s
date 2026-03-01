
    .section .text.FUN_0601B48C


    .global disc_read_check
    .type disc_read_check, @function
disc_read_check:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0x96, 0x2F    /* mov.w .L_wpool_cram_copy_len, r6 */  ! r6 = 0x80 (128 bytes)
    .byte   0xD5, 0x19    /* mov.l .L_palette_src_a, r5 */        ! r5 = palette source A (sym_060485EC)
    .byte   0xD4, 0x19    /* mov.l .L_cram_dst_020, r4 */         ! r4 = VDP2 Color RAM +0x020
    .byte   0xD3, 0x1A    /* mov.l .L_fn_memcpy_word_idx, r3 */
    jsr @r3
    nop
    .byte   0xD5, 0x19    /* mov.l .L_palette_src_b, r5 */        ! r5 = palette source B (sym_060485CC)
    .byte   0xD4, 0x1A    /* mov.l .L_cram_dst_180, r4 */         ! r4 = VDP2 Color RAM +0x180
    .byte   0xD3, 0x17    /* mov.l .L_fn_memcpy_word_idx, r3 */
    jsr @r3
    mov #0x20, r6
    .byte   0xD3, 0x19    /* mov.l .L_fn_vram_config_reset, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x18    /* mov.l .L_fn_vram_fill_indexed, r3 */
    jsr @r3
    mov #0xC, r4
    mov #0x16, r6
    .byte   0xD2, 0x17    /* mov.l .L_course_dlist_desc, r2 */    ! r2 = &course descriptor (sym_060638C8)
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    .byte   0xD3, 0x16    /* mov.l .L_pool_const_0xC000, r3 */    ! r3 = 0xC000
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    .byte   0xD3, 0x15    /* mov.l .L_fn_vram_rect_fill, r3 */
    jsr @r3
    mov #0x8, r4
    mov #0x1, r2
    .byte   0xD3, 0x14    /* mov.l .L_disc_load_phase, r3 */      ! r3 = &disc_load_phase (sym_0608600D)
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.b r2, @r3
