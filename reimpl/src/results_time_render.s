
    .section .text.FUN_06033338


    .global results_time_render
    .type results_time_render, @function
results_time_render:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    rts
    nop
    .4byte  0x07E00000                       /* VDP1 VRAM base address */
    .4byte  sym_060430CE                     /* palette/render helper */
    .4byte  sym_060629AC                     /* element source data buffer */
    .4byte  memcpy_word_idx                  /* word-indexed memcpy routine */

    .global sym_06033354
sym_06033354:
    .byte   0xD5, 0x17    /* mov.l .L_pool_default_char_tbl, r5 — r5 = default digit char table (sym_060338DC) */
    .byte   0xD0, 0x18    /* mov.l .L_pool_display_state_ptr, r0 — r0 = &display state ptr (sym_06033868) */
    mov.l @r0, r0
    mov.l @r0, r0
    cmp/pl r0
    bf      .L_use_default_chars
    .byte   0xD5, 0x16    /* mov.l .L_pool_alt_char_tbl, r5 — r5 = alternate digit char table (sym_060338E8) */
.L_use_default_chars:
    .byte   0xD4, 0x17    /* mov.l .L_pool_work_buffer, r4 — r4 = display element work buffer (sym_06062D95) */
    mov #0x6, r1
.L_copy_char_loop:
    mov.b @r5+, r0
    mov.b r0, @r4
    add #0x1, r4
    mov.b @r5+, r0
    mov.b r0, @r4
    add #0x3, r4
    add #-0x1, r1
    mov #0x0, r0
    cmp/eq r0, r1
    bf      .L_copy_char_loop
    mov #0x6, r7
    .byte   0xD8, 0x11    /* mov.l .L_pool_pos_table, r8 — r8 = element XY position table (sym_060338F4) */
    .byte   0xD9, 0x12    /* mov.l .L_pool_render_fn, r9 — r9 = palette/render helper (sym_060430CE) */
    .byte   0xDA, 0x12    /* mov.l .L_pool_src_buffer, r10 — r10 = element source data (sym_060629AC) */
    mov.w @r8+, r4
    mov r4, r5
    add r10, r4
    add r9, r5
    mov.w @r8+, r6
    .byte   0xD0, 0x10    /* mov.l .L_pool_memcpy_fn, r0 — r0 = memcpy_word_idx */
