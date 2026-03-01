
    .section .text.FUN_06004F28


    .global obj_position_update
    .type obj_position_update, @function
obj_position_update:
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0xC, r15
    mov.l   .L_cmd_table_base, r10
    mov.l   .L_counter_b_ptr, r11
    mov.l   .L_counter_a_ptr, r12
    mov.l   .L_mode_flag_ptr, r14
    mov.l r4, @(4, r15)
    mov.l r7, @r15
    tst r3, r3
    bt/s    .L_no_data_copy
    mov r6, r13
    mov.l @(4, r15), r4
    mov.w @(2, r4), r0
    mov.w @r4, r2
    mov r0, r3
    mulu.w r2, r3
    sts macl, r3
    add #0x2, r3
    shll r3
    extu.w r3, r3
    mov r3, r0
    extu.w r3, r6
    mov.w r0, @(8, r15)
    mov.l   .L_heap_cursor_ptr, r8
    mov.l @(4, r15), r5
    mov.l   .L_fn_memcpy_word, r2
    mov.l @r8, r8
    jsr @r2
    mov r8, r4
    mov.w @(8, r15), r0
    mov r0, r4
    extu.w r4, r4
    mov.l   .L_heap_cursor_ptr, r3
    mov.l @r3, r3
    add r4, r3
    mov.l   .L_heap_cursor_ptr, r2
    mov.l r3, @r2
    mov.l   .L_heap_cursor_b_ptr, r5
    mov.l @r5, r1
    add r4, r1
    bra     .L_check_word_count
    mov.l r1, @r5
.L_no_data_copy:
    mov.l @(4, r15), r8
.L_check_word_count:
    tst r13, r13
    bt      .L_no_vram_transfer
    mov #0x3, r3
    and r9, r3
    tst r3, r3
    bf/s    .L_use_table_b
    mov #0x8, r4
    mov.l @r14, r3
    and r4, r9
    mov.l @r12, r2
    shll2 r3
    shll r3
    add r10, r3
    tst r9, r9
    bt/s    .L_table_a_memcpy
    mov.l r2, @(4, r3)
    mov.l @r12, r5
    mov.l   .L_vdp2_vram_base, r3
    shll2 r5
    shll2 r5
    shll r5
    add r3, r5
    mov.l   .L_fn_dma_transfer, r3
    jsr @r3
    mov r13, r4
    bra     .L_advance_counter_a
    nop
.L_table_a_memcpy:
    mov.l @r15, r6
    mov.l @r12, r4
    mov.l   .L_vdp2_vram_base, r3
    shll2 r6
    shll2 r4
    shll2 r6
    shll2 r4
    shll r6
    shll r4
    add r3, r4
    mov.l   .L_fn_memcpy_word, r3
    jsr @r3
    mov r13, r5
.L_advance_counter_a:
    mov.l @r15, r2
    mov.l @r12, r3
    add r2, r3
    mov.l r3, @r12
    bra     .L_finalize_entry
    nop
.L_cmd_table_base:
    .4byte  sym_06063750                 /* display command table base */
.L_counter_b_ptr:
    .4byte  sym_06059F1C                 /* counter B (init_counter) */
.L_counter_a_ptr:
    .4byte  sym_06059F18                 /* counter A (dispatch_flags) */
.L_mode_flag_ptr:
    .4byte  sym_06059F10                 /* mode flag / entry index */
.L_heap_cursor_ptr:
    .4byte  sym_06063D90                 /* heap write cursor */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx              /* CPU word-copy function */
.L_heap_cursor_b_ptr:
    .4byte  sym_06063D94                 /* secondary heap cursor */
.L_vdp2_vram_base:
    .4byte  0x25E00000                   /* VDP2 VRAM +0x00000 */
.L_fn_dma_transfer:
    .4byte  dma_memory_transfer          /* DMA transfer function */
.L_use_table_b:
    mov.l @r14, r2
    and r4, r9
    mov.l @r11, r3
    shll2 r2
    shll r2
    add r10, r2
    tst r9, r9
    bt/s    .L_table_b_memcpy
    mov.l r3, @(4, r2)
    mov.l @r11, r5
    .byte   0xD3, 0x30    /* mov.l .L_pool_060050D8, r3 -- cross-TU: VDP2 VRAM 0x25E00000 */
    shll2 r5
    shll2 r5
    shll r5
    add r3, r5
    .byte   0xD3, 0x2F    /* mov.l .L_pool_060050DC, r3 -- cross-TU: dma_memory_transfer */
    jsr @r3
    mov r13, r4
    bra     .L_advance_counter_b
    nop
.L_table_b_memcpy:
    mov.l @r15, r6
    mov.l @r11, r4
    .byte   0xD3, 0x2A    /* mov.l .L_pool_060050D8, r3 -- cross-TU: VDP2 VRAM 0x25E00000 */
    shll2 r6
    shll2 r4
    shll2 r6
    shll2 r4
    shll r6
    shll r4
    add r3, r4
    .byte   0xD3, 0x28    /* mov.l .L_pool_060050E0, r3 -- cross-TU: memcpy_word_idx */
    jsr @r3
    mov r13, r5
.L_advance_counter_b:
    mov.l @r15, r2
    mov.l @r11, r3
    add r2, r3
    mov.l r3, @r11
    bra     .L_finalize_entry
    nop
.L_no_vram_transfer:
    mov.l @r14, r2
    mov.l @r14, r3
    shll2 r2
    add #-0x1, r3
    shll r2
    shll2 r3
    add r10, r2
    shll r3
    add r10, r3
    mov.l @(4, r3), r1
    mov.l r1, @(4, r2)
.L_finalize_entry:
    mov.l @r14, r3
    shll2 r3
    shll r3
    add r10, r3
    mov.l r8, @r3
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
    add #0xC, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0600508A
sym_0600508A:
    mov #0x4, r3
