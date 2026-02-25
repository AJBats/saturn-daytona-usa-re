/* system_watchdog -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0600747C - 0x06007658
 *
 * Display slot management — registers, swaps, and relocates entries in the
 * game's slot-based display list. Each slot is an 8-byte record:
 *   +0: callback/source pointer (32-bit)
 *   +4: packed attributes (16-bit)
 *   +6: render priority (16-bit)
 *
 * Data structures:
 *   sym_0606A4F4 = slot_count      — number of active display slots (32-bit)
 *   sym_060684EC = index_table     — maps logical index to physical slot (16-bit per entry)
 *   sym_06063F64 = slot_table      — per-slot data records (8-byte stride)
 *   sym_0606A4EC = source_ptr      — current source/callback pointer (32-bit)
 *   sym_06063F5C = display_base    — display/scroll base table pointer
 *
 * Contains 3 decoded functions + 1 trailing byte blob (4th function, not decoded).
 *
 * Calls: memcpy_word_idx
 */

    .section .text.FUN_0600747C


    .global system_watchdog
    .type system_watchdog, @function
system_watchdog:
    mov.l r14, @-r15                        ! save r14
    extu.w r4, r4                           ! r4 = slot_index (zero-extend to 32-bit)
    mov.l r13, @-r15                        ! save r13
    sts.l pr, @-r15                         ! save return address
    sts.l macl, @-r15                       ! save multiply accumulator
    add #-0xC, r15                          ! allocate 12 bytes on stack
    mov.l r7, @r15                          ! sp[0] = callback_ptr (r7 arg)
    extu.w r5, r7                           ! r7 = packed_attrs (zero-extended)
    mov r7, r0                              ! r0 = packed_attrs
    shar r0                                 ! r0 >>= 1 (arithmetic)
    shar r0                                 ! r0 >>= 1
    shar r0                                 ! r0 >>= 1
    shar r0                                 ! r0 >>= 1
    shar r0                                 ! r0 >>= 1
    shar r0                                 ! r0 >>= 1
    shar r0                                 ! r0 >>= 1
    shar r0                                 ! r0 >>= 1 (total: >>8, extract high byte)
    and #0x3F, r0                           ! r0 = page_count = (packed_attrs >> 8) & 0x3F
    extu.w r0, r0                           ! zero-extend page_count
    mov.w r0, @(4, r15)                     ! sp[4] = page_count
    mov.w   _wpool_low_byte_mask, r3        ! r3 = 0x00FF
    and r3, r7                              ! r7 = type_field = packed_attrs & 0xFF
    extu.w r7, r7                           ! zero-extend type_field
    mov r7, r0                              ! r0 = type_field
    mov.w r0, @(8, r15)                     ! sp[8] = type_field
    mov.l   _pool_slot_count, r7            ! r7 = &slot_count
    shll r4                                 ! r4 = slot_index * 2 (16-bit table stride)
    mov.l   _pool_index_table, r3           ! r3 = &index_table base
    add r3, r4                              ! r4 = &index_table[slot_index]
    mov.l @r7, r2                           ! r2 = current slot_count
    mov.w r2, @r4                           ! index_table[slot_index] = slot_count
    mov r5, r0                              ! r0 = original packed_attrs arg (r5)
    mov.l   _pool_slot_table, r4            ! r4 = &slot_table base
    mov.l   _pool_source_ptr, r14           ! r14 = &source_ptr
    mov.l @r7, r3                           ! r3 = slot_count
    mov.l @r14, r2                          ! r2 = *source_ptr (current callback)
    shll2 r3                                ! r3 = slot_count * 4
    shll r3                                 ! r3 = slot_count * 8 (8-byte stride)
    add r4, r3                              ! r3 = &slot_table[slot_count]
    mov.l r2, @r3                           ! slot_table[slot_count].callback = *source_ptr
    mov.l @r7, r3                           ! r3 = slot_count
    shll2 r3                                ! r3 = slot_count * 4
    shll r3                                 ! r3 = slot_count * 8
    add r4, r3                              ! r3 = &slot_table[slot_count]
    mov.w r0, @(4, r3)                      ! slot_table[slot_count].attrs = packed_attrs
    mov r6, r0                              ! r0 = priority arg (r6)
    mov.l @r7, r3                           ! r3 = slot_count
    shll2 r3                                ! r3 = slot_count * 4
    shll r3                                 ! r3 = slot_count * 8
    add r4, r3                              ! r3 = &slot_table[slot_count]
    mov.w r0, @(6, r3)                      ! slot_table[slot_count].priority = priority
    mov.l @r7, r3                           ! r3 = slot_count
    add #0x1, r3                            ! r3 = slot_count + 1
    mov.l r3, @r7                           ! slot_count++
    mov.w @(4, r15), r0                     ! r0 = page_count (from stack)
    mov r0, r13                             ! r13 = page_count
    mov.w @(8, r15), r0                     ! r0 = type_field (from stack)
    mov r0, r3                              ! r3 = type_field
    mulu.w r3, r13                          ! MACL = page_count * type_field
    mov #0x0, r3                            ! r3 = 0 (for rounding)
    sts macl, r13                           ! r13 = page_count * type_field
    cmp/gt r13, r3                          ! T = (0 > product)? i.e. product < 0?
    addc r3, r13                            ! r13 += 0 + T (round up for negative)
    shar r13                                ! r13 = (page_count * type_field + 1) / 2 = copy_size
    mov.l @r15, r5                          ! r5 = callback_ptr (src for memcpy)
    mov.l @r14, r4                          ! r4 = *source_ptr (slot offset)
    mov.l   _pool_display_base, r3          ! r3 = &display_base ptr
    mov.l   _pool_memcpy_word_idx, r2       ! r2 = &memcpy_word_idx
    mov r13, r6                             ! r6 = copy_size (word count)
    shll2 r4                                ! r4 = *source_ptr * 4
    mov.l @r3, r3                           ! r3 = display_base
    shll2 r6                                ! r6 = copy_size * 4
    shll r4                                 ! r4 = *source_ptr * 8
    shll r6                                 ! r6 = copy_size * 8 (byte count)
    jsr @r2                                 ! memcpy_word_idx(dst=display_base + offset, src=callback_ptr, count=copy_size)
    add r3, r4                              ! r4 = display_base + *source_ptr * 8 (dst, delay slot)
    mov.l @r14, r3                          ! r3 = *source_ptr
    add r13, r3                             ! r3 = *source_ptr + copy_size
    mov.l r3, @r14                          ! *source_ptr += copy_size (advance)
    add #0xC, r15                           ! deallocate 12 bytes
    lds.l @r15+, macl                       ! restore multiply accumulator
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return
    mov.l @r15+, r14                        ! restore r14 (delay slot)
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
    add #-0x4, r15                          ! allocate 4 bytes on stack
    extu.w r5, r0                           ! r0 = src_index (zero-extend)
    mov.l   _pool_index_table_b, r7         ! r7 = &index_table base
    shll r0                                 ! r0 = src_index * 2 (16-bit stride)
    mov.w @(r0, r7), r3                     ! r3 = index_table[src_index] (saved physical slot)
    extu.w r4, r0                           ! r0 = dst_index (zero-extend)
    mov.w r3, @r15                          ! sp[0] = saved_slot (from src_index)
    shll r0                                 ! r0 = dst_index * 2 (16-bit stride)
    mov.l   _pool_slot_count_b, r5          ! r5 = &slot_count
    mov.l @r5, r2                           ! r2 = current slot_count
    mov.w r2, @(r0, r7)                     ! index_table[dst_index] = slot_count
    mov.l   _pool_slot_table_b, r4          ! r4 = &slot_table base
    mov.l @r5, r3                           ! r3 = slot_count
    mov.w @r15, r7                          ! r7 = saved_slot (from stack)
    shll2 r3                                ! r3 = slot_count * 4
    extu.w r7, r7                           ! zero-extend saved_slot
    shll r3                                 ! r3 = slot_count * 8 (8-byte stride)
    shll2 r7                                ! r7 = saved_slot * 4
    add r4, r3                              ! r3 = &slot_table[slot_count]
    shll r7                                 ! r7 = saved_slot * 8
    add r4, r7                              ! r7 = &slot_table[saved_slot]
    mov.l @r7, r2                           ! r2 = slot_table[saved_slot].callback
    mov.l r2, @r3                           ! slot_table[slot_count].callback = saved_slot's callback
    mov.l @r5, r3                           ! r3 = slot_count
    shll2 r3                                ! r3 = slot_count * 4
    shll r3                                 ! r3 = slot_count * 8
    add r4, r3                              ! r3 = &slot_table[slot_count]
    mov.w @(4, r7), r0                      ! r0 = slot_table[saved_slot].attrs
    mov.w r0, @(4, r3)                      ! slot_table[slot_count].attrs = saved_slot's attrs
    mov.l @r5, r3                           ! r3 = slot_count
    shll2 r3                                ! r3 = slot_count * 4
    shll r3                                 ! r3 = slot_count * 8
    mov r6, r0                              ! r0 = new_priority arg (r6)
    add r4, r3                              ! r3 = &slot_table[slot_count]
    mov.w r0, @(6, r3)                      ! slot_table[slot_count].priority = new_priority
    mov.l @r5, r3                           ! r3 = slot_count
    add #0x1, r3                            ! r3 = slot_count + 1
    mov.l r3, @r5                           ! slot_count++
    rts                                     ! return
    add #0x4, r15                           ! deallocate 4 bytes (delay slot)

    .global sym_06007590
sym_06007590:
    add #-0x8, r15                          ! allocate 8 bytes on stack
    mov.l   _pool_slot_table_b, r7          ! r7 = &slot_table base
    mov.l   _pool_slot_count_b, r6          ! r6 = &slot_count
    mov.w @(2, r4), r0                      ! r0 = descriptor[1] = src_index
    mov.l   _pool_index_table_b, r2         ! r2 = &index_table base
    mov r0, r3                              ! r3 = src_index
    extu.w r3, r3                           ! zero-extend src_index
    shll r3                                 ! r3 = src_index * 2 (16-bit stride)
    add r2, r3                              ! r3 = &index_table[src_index]
    mov.w @r3, r1                           ! r1 = index_table[src_index] (saved physical slot)
    mov.w r1, @r15                          ! sp[0] = saved_slot
    mov.w @r4, r3                           ! r3 = descriptor[0] = dst_index
    mov.l @r6, r1                           ! r1 = current slot_count
    extu.w r3, r3                           ! zero-extend dst_index
    shll r3                                 ! r3 = dst_index * 2
    add r3, r2                              ! r2 = &index_table[dst_index]
    mov.w r1, @r2                           ! index_table[dst_index] = slot_count
    mov.l @r6, r3                           ! r3 = slot_count
    mov.w @r15, r2                          ! r2 = saved_slot (from stack)
    shll2 r3                                ! r3 = slot_count * 4
    extu.w r2, r2                           ! zero-extend saved_slot
    shll r3                                 ! r3 = slot_count * 8 (8-byte stride)
    shll2 r2                                ! r2 = saved_slot * 4
    add r7, r3                              ! r3 = &slot_table[slot_count]
    shll r2                                 ! r2 = saved_slot * 8
    add r7, r2                              ! r2 = &slot_table[saved_slot]
    mov.l r2, @(4, r15)                     ! sp[4] = &slot_table[saved_slot]
    mov.l @r2, r1                           ! r1 = slot_table[saved_slot].callback
    mov.l r1, @r3                           ! slot_table[slot_count].callback = saved_slot's callback
    mov.l @r6, r3                           ! r3 = slot_count
    shll2 r3                                ! r3 = slot_count * 4
    shll r3                                 ! r3 = slot_count * 8
    mov.l @(4, r15), r2                     ! r2 = &slot_table[saved_slot]
    add r7, r3                              ! r3 = &slot_table[slot_count]
    mov.w @(4, r2), r0                      ! r0 = slot_table[saved_slot].attrs
    mov #0xC, r2                            ! r2 = 12 (threshold for priority offset)
    mov r0, r1                              ! r1 = saved attrs
    mov.w r0, @(4, r3)                      ! slot_table[slot_count].attrs = saved_slot's attrs
    mov.w @(2, r4), r0                      ! r0 = descriptor[1] = src_index (reload)
    mov r0, r3                              ! r3 = src_index
    extu.w r3, r3                           ! zero-extend src_index
    cmp/gt r2, r3                           ! T = (src_index > 12)?
    bf      .L_no_priority_offset           ! if src_index <= 12, skip offset
    mov.w @(4, r4), r0                      ! r0 = descriptor[2] = base_priority
    mov r0, r1                              ! r1 = base_priority
    extu.w r1, r1                           ! zero-extend base_priority
    extu.w r5, r2                           ! r2 = priority_offset arg (r5)
    shll2 r2                                ! r2 = priority_offset * 4
    add r2, r1                              ! r1 = base_priority + priority_offset * 4
    bra     .L_store_priority               ! jump to store priority
    extu.w r1, r1                           ! zero-extend adjusted priority (delay slot)
    .2byte  0xFFFF
_pool_index_table_b:
    .4byte  sym_060684EC
_pool_slot_count_b:
    .4byte  sym_0606A4F4
_pool_slot_table_b:
    .4byte  sym_06063F64
.L_no_priority_offset:
    mov.w @(4, r4), r0                      ! r0 = descriptor[2] = base_priority
    mov r0, r1                              ! r1 = base_priority (no offset applied)
.L_store_priority:
    mov.l @r6, r3                           ! r3 = slot_count
    mov r1, r0                              ! r0 = final priority value
    shll2 r3                                ! r3 = slot_count * 4
    shll r3                                 ! r3 = slot_count * 8 (8-byte stride)
    add r7, r3                              ! r3 = &slot_table[slot_count]
    mov.w r0, @(6, r3)                      ! slot_table[slot_count].priority = final_priority
    mov.l @r6, r3                           ! r3 = slot_count
    add #0x1, r3                            ! r3 = slot_count + 1
    mov.l r3, @r6                           ! slot_count++
    rts                                     ! return
    add #0x8, r15                           ! deallocate 8 bytes (delay slot)
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
