
    .section .text.FUN_0600747C


    .global system_watchdog
    .type system_watchdog, @function
system_watchdog:
    mov.l r14, @-r15
    extu.w r4, r4
    mov.l r13, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0xC, r15
    mov.l r7, @r15
    extu.w r5, r7
    mov r7, r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    and #0x3F, r0
    extu.w r0, r0
    mov.w r0, @(4, r15)
    mov.w   _wpool_low_byte_mask, r3
    and r3, r7
    extu.w r7, r7
    mov r7, r0
    mov.w r0, @(8, r15)
    mov.l   _pool_slot_count, r7
    shll r4
    mov.l   _pool_index_table, r3
    add r3, r4
    mov.l @r7, r2
    mov.w r2, @r4
    mov r5, r0
    mov.l   _pool_slot_table, r4
    mov.l   _pool_source_ptr, r14
    mov.l @r7, r3
    mov.l @r14, r2
    shll2 r3
    shll r3
    add r4, r3
    mov.l r2, @r3
    mov.l @r7, r3
    shll2 r3
    shll r3
    add r4, r3
    mov.w r0, @(4, r3)
    mov r6, r0
    mov.l @r7, r3
    shll2 r3
    shll r3
    add r4, r3
    mov.w r0, @(6, r3)
    mov.l @r7, r3
    add #0x1, r3
    mov.l r3, @r7
    mov.w @(4, r15), r0
    mov r0, r13
    mov.w @(8, r15), r0
    mov r0, r3
    mulu.w r3, r13
    mov #0x0, r3
    sts macl, r13
    cmp/gt r13, r3
    addc r3, r13
    shar r13
    mov.l @r15, r5
    mov.l @r14, r4
    mov.l   _pool_display_base, r3
    mov.l   _pool_memcpy_word_idx, r2
    mov r13, r6
    shll2 r4
    mov.l @r3, r3
    shll2 r6
    shll r4
    shll r6
    jsr @r2
    add r3, r4
    mov.l @r14, r3
    add r13, r3
    mov.l r3, @r14
    add #0xC, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
_wpool_low_byte_mask:
    .2byte  0x00FF
_pool_slot_count:
    .4byte  sym_0606A4F4
_pool_index_table:
    .4byte  sym_060684EC
_pool_slot_table:
    .4byte  sym_06063F64
_pool_source_ptr:
    .4byte  sym_0606A4EC
_pool_display_base:
    .4byte  sym_06063F5C
_pool_memcpy_word_idx:
    .4byte  memcpy_word_idx

    .global sym_06007540
sym_06007540:
    add #-0x4, r15
    extu.w r5, r0
    mov.l   _pool_index_table_b, r7
    shll r0
    mov.w @(r0, r7), r3
    extu.w r4, r0
    mov.w r3, @r15
    shll r0
    mov.l   _pool_slot_count_b, r5
    mov.l @r5, r2
    mov.w r2, @(r0, r7)
    mov.l   _pool_slot_table_b, r4
    mov.l @r5, r3
    mov.w @r15, r7
    shll2 r3
    extu.w r7, r7
    shll r3
    shll2 r7
    add r4, r3
    shll r7
    add r4, r7
    mov.l @r7, r2
    mov.l r2, @r3
    mov.l @r5, r3
    shll2 r3
    shll r3
    add r4, r3
    mov.w @(4, r7), r0
    mov.w r0, @(4, r3)
    mov.l @r5, r3
    shll2 r3
    shll r3
    mov r6, r0
    add r4, r3
    mov.w r0, @(6, r3)
    mov.l @r5, r3
    add #0x1, r3
    mov.l r3, @r5
    rts
    add #0x4, r15

    .global sym_06007590
sym_06007590:
    add #-0x8, r15
    mov.l   _pool_slot_table_b, r7
    mov.l   _pool_slot_count_b, r6
    mov.w @(2, r4), r0
    mov.l   _pool_index_table_b, r2
    mov r0, r3
    extu.w r3, r3
    shll r3
    add r2, r3
    mov.w @r3, r1
    mov.w r1, @r15
    mov.w @r4, r3
    mov.l @r6, r1
    extu.w r3, r3
    shll r3
    add r3, r2
    mov.w r1, @r2
    mov.l @r6, r3
    mov.w @r15, r2
    shll2 r3
    extu.w r2, r2
    shll r3
    shll2 r2
    add r7, r3
    shll r2
    add r7, r2
    mov.l r2, @(4, r15)
    mov.l @r2, r1
    mov.l r1, @r3
    mov.l @r6, r3
    shll2 r3
    shll r3
    mov.l @(4, r15), r2
    add r7, r3
    mov.w @(4, r2), r0
    mov #0xC, r2
    mov r0, r1
    mov.w r0, @(4, r3)
    mov.w @(2, r4), r0
    mov r0, r3
    extu.w r3, r3
    cmp/gt r2, r3
    bf      .L_no_priority_offset
    mov.w @(4, r4), r0
    mov r0, r1
    extu.w r1, r1
    extu.w r5, r2
    shll2 r2
    add r2, r1
    bra     .L_store_priority
    extu.w r1, r1
    .2byte  0xFFFF
_pool_index_table_b:
    .4byte  sym_060684EC
_pool_slot_count_b:
    .4byte  sym_0606A4F4
_pool_slot_table_b:
    .4byte  sym_06063F64
.L_no_priority_offset:
    mov.w @(4, r4), r0
    mov r0, r1
.L_store_priority:
    mov.l @r6, r3
    mov r1, r0
    shll2 r3
    shll r3
    add r7, r3
    mov.w r0, @(6, r3)
    mov.l @r6, r3
    add #0x1, r3
    mov.l r3, @r6
    rts
    add #0x8, r15
    .2byte  0x6643
    .4byte  0xD30A655D
    .4byte  0xD20A4600
    .4byte  0x363C6661
    .4byte  0xD309646D
    .4byte  0x44084400
    .4byte  0x342C8542
    .4byte  0x62032239
    .4byte  0x60238142
    .4byte  0x85426303
    .4byte  0x235B6033
    .4byte  0x000B8142
    .4byte  sym_060684EC
    .4byte  sym_06063F64
    .4byte  0x0000FF00
