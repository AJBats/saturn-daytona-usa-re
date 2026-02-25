/* vram_defrag -- VRAM display list compaction
 * Translation unit: 0x0601FFB8 - 0x060200A4
 *
 * Walks a table of display-list entries (8 bytes each) indexed by the
 * iteration counter at sym_06087802.  For each entry whose sentinel ID
 * is within range:
 *
 *   - Negative block count (word +2): "free" path — looks up a pointer
 *     table via the source index (word +4), stores the resolved address
 *     into the current VRAM block pointer (sym_060877F4) and writes
 *     the iteration index into the handler mode word (sym_06087804).
 *
 *   - Non-negative block count: "allocate" path — computes a car-struct
 *     offset (block_count * 0x0268) via fpmul, writes a 32-bit result
 *     and size attribute into the car struct at that offset, then bumps
 *     the entry count (sym_06087800).
 *
 * After processing, if game state (sym_0605AD10) == 0x17, calls the
 * object pool allocator (obj_pool_alloc).  Finally increments the
 * iteration counter and returns.
 *
 * Second entry point loc_06020090 is a lightweight check: if game
 * state == 0x17, tail-branches to obj_pool_alloc; otherwise returns.
 *
 * Key data addresses:
 *   sym_06087802 — iteration counter (16-bit, compared as sentinel limit)
 *   sym_06087800 — entry count (16-bit, incremented per allocation)
 *   sym_060877FC — current VRAM block pointer (32-bit, indirect)
 *   sym_060877F8 — VRAM pointer lookup table base (32-bit, indirect)
 *   sym_060877F4 — resolved VRAM destination address (32-bit)
 *   sym_06087804 — handler mode / iteration index (16-bit)
 *   sym_06078900 — car struct array base
 *   sym_0605AD10 — game state dispatch value
 */

    .section .text.FUN_0601FFB8


    .global vram_defrag
    .type vram_defrag, @function
vram_defrag:
    sts.l pr, @-r15                         ! save return address
    sts.l macl, @-r15                       ! save multiply accumulator
    mov.w   .L_wpool_car_struct_stride, r8  ! r8 = 0x0268 (car struct size, 616 bytes)
    mov.l   .L_pool_iter_counter_ptr, r11   ! r11 = &iteration_counter (sym_06087802)
    mov.l   .L_pool_entry_count_ptr, r12    ! r12 = &entry_count (sym_06087800)
    mov r8, r10                             ! r10 = 0x0268 (copy of stride)
    mov.w @r12, r14                         ! r14 = entry_count (16-bit)
    add #-0x68, r10                         ! r10 = 0x0268 - 0x68 = 0x0200 (stride minus header)
    extu.w r14, r14                         ! zero-extend entry_count to 32-bit
    shll2 r14                               ! r14 *= 4
    shll r14                                ! r14 *= 2 (total: entry_count * 8 = byte offset)
    mov.l   .L_pool_vram_block_ptr, r3      ! r3 = &vram_block_ptr (sym_060877FC)
    mov.l @r3, r3                           ! r3 = vram_block_ptr (table base address)
    bra     .L_loop_test                    ! jump to loop condition check
    add r3, r14                             ! (delay) r14 = table_base + entry_count * 8 (current entry)
.L_process_entry:
    mov.w @(2, r14), r0                     ! r0 = entry.block_count (signed 16-bit at +2)
    mov r0, r3                              ! r3 = block_count (sign-extended)
    cmp/pz r3                               ! test if block_count >= 0
    bt      .L_alloc_path                   ! if non-negative, take allocation path
    /* --- free path: block_count < 0 --- */
    mov.w @(4, r14), r0                     ! r0 = entry.source_index (16-bit at +4)
    mov r0, r2                              ! r2 = source_index
    extu.w r2, r2                           ! zero-extend to 32-bit
    shll2 r2                                ! r2 = source_index * 4 (byte offset into pointer table)
    mov.l   .L_pool_lookup_table_ptr, r3    ! r3 = &lookup_table_base (sym_060877F8)
    mov.l @r3, r3                           ! r3 = lookup_table_base
    add r3, r2                              ! r2 = &lookup_table[source_index]
    mov.l @r2, r1                           ! r1 = lookup_table[source_index] (resolved ptr)
    mov.l   .L_pool_vram_dest_addr, r0      ! r0 = &vram_dest (sym_060877F4)
    mov.l r1, @r0                           ! vram_dest = resolved pointer
    extu.w r9, r2                           ! r2 = loop index (r9, zero-extended)
    mov.l   .L_pool_handler_mode_ptr, r1    ! r1 = &handler_mode (sym_06087804)
    mov.w r2, @r1                           ! handler_mode = loop index (16-bit write)
    bra     .L_loop_done                    ! exit loop — free path done
    nop                                     ! (delay) nop
.L_alloc_path:
    /* --- alloc path: block_count >= 0 --- */
    mov.w @(2, r14), r0                     ! r0 = entry.block_count (re-read, 16-bit)
    mov.l   .L_pool_car_array_base, r3      ! r3 = car_array_base (sym_06078900)
    mov.w   .L_wpool_car_result_offset, r4  ! r4 = 0x035A (fpmul arg: fractional multiplier)
    mov r0, r13                             ! r13 = block_count
    mul.l r8, r13                           ! MACL = block_count * 0x0268 (car struct offset)
    mov.w @(4, r14), r0                     ! r0 = entry.source_index (16-bit at +4)
    sts macl, r13                           ! r13 = block_count * stride (byte offset into car array)
    mov r0, r5                              ! r5 = source_index
    add r3, r13                             ! r13 = &car_array[block_count] (struct pointer)
    extu.w r5, r5                           ! zero-extend source_index
    mov.l   .L_pool_fpmul_addr, r3          ! r3 = &fpmul
    jsr @r3                                 ! r0 = fpmul(r4=0x035A, r5=source_index<<16)
    shll16 r5                               ! (delay) r5 = source_index << 16 (fixed-point)
    mov.w   .L_wpool_car_fpmul_dest_offset, r1  ! r1 = 0x0194 (car struct field offset)
    add r13, r1                             ! r1 = &car[block_count].field_0194
    mov.l r0, @r1                           ! car[block_count].field_0194 = fpmul result
    mov.w @(6, r14), r0                     ! r0 = entry.size_attr (16-bit at +6)
    mov r0, r3                              ! r3 = size_attr
    extu.w r3, r3                           ! zero-extend to 32-bit
    mov.w   .L_wpool_car_size_attr_offset, r0  ! r0 = 0x01F8 (car struct field offset)
    mov.l r3, @(r0, r13)                    ! car[block_count].field_01F8 = size_attr
    add #0xC, r0                            ! r0 = 0x01F8 + 0x0C = 0x0204
    mov.l r10, @(r0, r13)                   ! car[block_count].field_0204 = 0x0200 (stride - header)
    mov.w @r12, r3                          ! r3 = entry_count
    add #0x1, r3                            ! r3 = entry_count + 1
    mov.w r3, @r12                          ! entry_count++ (sym_06087800)
    add #0x8, r14                           ! r14 += 8 (advance to next table entry)
.L_loop_test:
    mov.w @r11, r2                          ! r2 = iteration_counter (sym_06087802)
    mov.w @r14, r3                          ! r3 = entry.sentinel_id (16-bit at +0)
    extu.w r2, r2                           ! zero-extend iteration_counter
    extu.w r3, r3                           ! zero-extend sentinel_id
    cmp/gt r3, r2                           ! if iteration_counter > sentinel_id ...
    bt      .L_process_entry                ! ... then process this entry
.L_loop_done:
    mov.l   .L_pool_game_state_ptr, r0      ! r0 = &game_state (sym_0605AD10)
    mov.l @r0, r0                           ! r0 = game_state value
    cmp/eq #0x17, r0                        ! is game_state == 0x17 (race active)?
    bf      .L_skip_pool_alloc              ! if not, skip pool allocator call
    .byte   0xB0, 0xB7    /* bsr 0x060201B8 (obj_pool_alloc — external) */
    nop                                     ! (delay) nop
.L_skip_pool_alloc:
    mov.w @r11, r2                          ! r2 = iteration_counter
    add #0x1, r2                            ! r2 = iteration_counter + 1
    mov.w r2, @r11                          ! iteration_counter++ (sym_06087802)
    lds.l @r15+, macl                       ! restore multiply accumulator
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r8                         ! restore r8 (caller-saved frame)
    mov.l @r15+, r9                         ! restore r9 (caller-saved frame)
    mov.l @r15+, r10                        ! restore r10 (caller-saved frame)
    mov.l @r15+, r11                        ! restore r11 (caller-saved frame)
    mov.l @r15+, r12                        ! restore r12 (caller-saved frame)
    mov.l @r15+, r13                        ! restore r13 (caller-saved frame)
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! (delay) restore r14 (caller-saved frame)
.L_wpool_car_struct_stride:
    .2byte  0x0268                          /* car struct size: 616 bytes */
.L_wpool_car_result_offset:
    .2byte  0x035A                          /* fpmul arg: fractional multiplier */
.L_wpool_car_fpmul_dest_offset:
    .2byte  0x0194                          /* car struct field offset: fpmul result dest */
.L_wpool_car_size_attr_offset:
    .2byte  0x01F8                          /* car struct field offset: size attribute */
.L_pool_iter_counter_ptr:
    .4byte  sym_06087802                    /* iteration counter (16-bit) */
.L_pool_entry_count_ptr:
    .4byte  sym_06087800                    /* entry count (16-bit) */
.L_pool_vram_block_ptr:
    .4byte  sym_060877FC                    /* VRAM block pointer (indirect) */
.L_pool_lookup_table_ptr:
    .4byte  sym_060877F8                    /* VRAM pointer lookup table base */
.L_pool_vram_dest_addr:
    .4byte  sym_060877F4                    /* resolved VRAM destination address */
.L_pool_handler_mode_ptr:
    .4byte  sym_06087804                    /* handler mode / display timer (16-bit) */
.L_pool_car_array_base:
    .4byte  sym_06078900                    /* car struct array base */
.L_pool_fpmul_addr:
    .4byte  fpmul                           /* fixed-point multiply routine */
.L_pool_game_state_ptr:
    .4byte  sym_0605AD10                    /* game state dispatch value */

    .global loc_06020090
loc_06020090:
    mov.l   .L_pool_game_state_ptr_b, r0    ! r0 = &game_state (sym_0605AD10)
    mov.l @r0, r0                           ! r0 = game_state value
    cmp/eq #0x17, r0                        ! is game_state == 0x17 (race active)?
    bf      .L_state_check_exit             ! if not, just return
    .byte   0xA0, 0x8E    /* bra 0x060201B8 (obj_pool_alloc — external tail-call) */
    nop                                     ! (delay) nop
.L_state_check_exit:
    rts                                     ! return — game state is not 0x17
    nop                                     ! (delay) nop
.L_pool_game_state_ptr_b:
    .4byte  sym_0605AD10                    /* game state dispatch value */
