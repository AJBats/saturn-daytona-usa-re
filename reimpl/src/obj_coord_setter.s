
    .section .text.FUN_0600508C


    .global obj_coord_setter
    .type obj_coord_setter, @function
obj_coord_setter:
    mov.l r14, @-r15
    and r3, r6
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x4, r15
    mov.l r5, @r15
    tst r6, r6
    bt/s    .L_no_data_copy
    mov r4, r13
    mov r13, r4
    mov r13, r5
    mov.l   .L_heap_cursor_ptr, r11
    mov.w @(2, r4), r0
    mov.w @r4, r3
    mov.l @r11, r14
    mov r0, r12
    mulu.w r3, r12
    mov.l   .L_fn_memcpy_word, r3
    sts macl, r12
    add #0x2, r12
    shll r12
    extu.w r12, r12
    extu.w r12, r6
    jsr @r3
    mov r14, r4
    extu.w r12, r5
    mov.l @r11, r2
    add r5, r2
    mov.l r2, @r11
    mov.l   .L_heap_cursor_b_ptr, r4
    mov.l @r4, r3
    add r5, r3
    mov.l r3, @r4
    bra     .L_write_cmd_entry
    nop
    .4byte  0x25E20000                       /* VDP2 VRAM +0x20000 (cache-through) */
    .4byte  dma_memory_transfer              /* DMA transfer function */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx                  /* CPU word-copy function */
.L_heap_cursor_ptr:
    .4byte  sym_06063D90                     /* heap write cursor */
.L_heap_cursor_b_ptr:
    .4byte  sym_06063D94                     /* secondary heap cursor */
.L_no_data_copy:
    mov r13, r14
.L_write_cmd_entry:
    .byte   0xD5, 0x1B    /* mov.l .L_pool_0600515C, r5 -- cross-TU: sym_06063750 (cmd table base) */
    .byte   0xD4, 0x1B    /* mov.l .L_pool_06005160, r4 -- cross-TU: sym_06059F10 (mode flag) */
    mov.l @r15, r3
    mov.l @r4, r2
    shll2 r2
    shll r2
    add r5, r2
    mov.l r3, @(4, r2)
    mov.l @r4, r3
    shll2 r3
    shll r3
    add r5, r3
    mov.l r14, @r3
    mov.l @r4, r2
    add #0x1, r2
    mov.l r2, @r4
    add #0x4, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0600511E
sym_0600511E:
    mov #0x3, r3
