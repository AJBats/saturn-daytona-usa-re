/* vdp1_sprite_render -- Register a VDP1 sprite slot and DMA texture data
 * Translation unit: 0x06007658 - 0x06007790
 *
 * Registers a sprite into the VDP1 sprite slot table. Each slot gets an
 * entry in a per-slot data array (8 bytes: VRAM offset, size word, flags).
 * For special color-mode slots (0xD-0xF), resolves color bits via a lookup
 * function. Initiates a DMA transfer of texture data from the source address
 * (typically CD-ROM) into VDP1 VRAM, then advances the VRAM write pointer
 * by ceil(width * height / 2) bytes.
 *
 * Args:
 *   r4 = slot_id  (sprite slot number, e.g. 0x01-0x39)
 *   r5 = size_param (bits 13:8 = width/8, bits 7:0 = height)
 *   r6 = flags    (sprite type / attribute flags)
 *   r7 = src_addr (source address for DMA, typically CD-ROM offset)
 *
 * Returns: nothing (void)
 *
 * Globals:
 *   sym_06063F64 -- sprite slot data table (8 bytes/entry: VRAM ptr, size, flags)
 *   sym_0606A4EC -- current VRAM write offset (running allocation pointer)
 *   sym_0606A4F4 -- sprite index counter (incremented per registration)
 *   sym_06063F5C -- VDP1 VRAM base pointer
 *   sym_06063F60 -- last computed VRAM address (slot 0xA special case)
 *   sym_060684EC -- slot-to-index mapping table (1 word per slot)
 *   sym_0606A4F0 -- saved sprite index (written for color-mode slots)
 *   sym_06034FE0 -- color/texture lookup function
 */

    .section .text.FUN_06007658


    .global vdp1_sprite_render
    .type vdp1_sprite_render, @function
vdp1_sprite_render:
    mov.l r14, @-r15                    ! save r14 (callee-saved)
    extu.w r4, r0                       ! r0 = slot_id (zero-extended to 16 bits)
    mov.l r13, @-r15                    ! save r13
    mov.l r12, @-r15                    ! save r12
    sts.l pr, @-r15                     ! save return address
    sts.l macl, @-r15                   ! save MACL (used by mulu.w later)
    add #-0x10, r15                     ! allocate 16 bytes of stack frame
    mov.l   _pool_slot_data_table, r12  ! r12 = &sprite_slot_data_table (8 bytes/entry)
    mov.l   _pool_vram_offset_ptr, r13  ! r13 = &vram_write_offset
    mov.l   _pool_sprite_index_ptr, r14 ! r14 = &sprite_index_counter
    mov.l r7, @(4, r15)                 ! stack[4] = src_addr (save for DMA call)
    cmp/eq #0xA, r0                     ! is slot_id == 0x0A?
    bf      .L_skip_vram_calc           ! if not, skip special VRAM address computation
    mov.l @r13, r2                      ! r2 = current VRAM write offset
    shll2 r2                            ! r2 *= 4
    shll r2                             ! r2 *= 2 (total: offset * 8)
    mov.l   _pool_vram_base_ptr, r3     ! r3 = &vram_base_ptr
    mov.l @r3, r3                       ! r3 = vram_base (e.g. VDP1 VRAM base)
    add r3, r2                          ! r2 = vram_base + offset * 8
    mov.l   _pool_vram_addr_store, r1   ! r1 = &last_vram_addr
    mov.l r2, @r1                       ! last_vram_addr = computed VRAM address
.L_skip_vram_calc:
    extu.w r5, r0                       ! r0 = size_param (zero-extended)
    extu.w r4, r2                       ! r2 = slot_id (zero-extended)
    mov.l r0, @r15                      ! stack[0] = size_param
    shll r2                             ! r2 = slot_id * 2 (index into word table)
    shar r0                             ! r0 = size_param >> 1 (arithmetic)
    shar r0                             ! r0 = size_param >> 2
    shar r0                             ! r0 = size_param >> 3
    shar r0                             ! r0 = size_param >> 4
    shar r0                             ! r0 = size_param >> 5
    shar r0                             ! r0 = size_param >> 6
    shar r0                             ! r0 = size_param >> 7
    shar r0                             ! r0 = size_param >> 8 (extract width field)
    and #0x3F, r0                       ! r0 = width = (size_param >> 8) & 0x3F
    extu.w r0, r0                       ! zero-extend width to 16 bits
    mov.w r0, @(8, r15)                 ! stack[8] = width
    mov.w   _wpool_lo_byte_mask, r7     ! r7 = 0x00FF (low-byte mask)
    mov.l @r15, r3                      ! r3 = size_param (from stack)
    and r7, r3                          ! r3 = size_param & 0xFF = height
    extu.w r3, r3                       ! zero-extend height
    mov r3, r0                          ! r0 = height
    mov.w r0, @(12, r15)               ! stack[12] = height
    mov.l   _pool_slot_index_table, r1  ! r1 = slot_to_index_table base
    mov.l @r14, r0                      ! r0 = current sprite_index
    add r1, r2                          ! r2 = &slot_to_index_table[slot_id] (slot*2 + base)
    mov.w r0, @r2                       ! slot_to_index_table[slot_id] = sprite_index
    mov.l @r14, r3                      ! r3 = sprite_index
    shll2 r3                            ! r3 *= 4
    shll r3                             ! r3 *= 2 (total: index * 8)
    add r12, r3                         ! r3 = &slot_data_table[index] (8 bytes/entry)
    mov.l @r13, r2                      ! r2 = current VRAM write offset
    mov.l r2, @r3                       ! slot_data[index].vram_offset = vram_write_offset
    extu.w r4, r1                       ! r1 = slot_id
    mov r1, r0                          ! r0 = slot_id
    cmp/eq #0xD, r0                     ! is slot_id == 0x0D?
    bt      .L_color_mode_lookup        ! yes -> do color mode lookup
    mov r1, r0                          ! r0 = slot_id
    cmp/eq #0xE, r0                     ! is slot_id == 0x0E?
    bt      .L_color_mode_lookup        ! yes -> do color mode lookup
    mov r1, r0                          ! r0 = slot_id
    cmp/eq #0xF, r0                     ! is slot_id == 0x0F?
    bt      .L_color_mode_lookup        ! yes -> do color mode lookup
    mov.l @r14, r2                      ! r2 = sprite_index (normal path)
    shll2 r2                            ! r2 *= 4
    shll r2                             ! r2 *= 2 (total: index * 8)
    add r12, r2                         ! r2 = &slot_data_table[index]
    mov r5, r0                          ! r0 = size_param
    bra     .L_store_flags              ! jump to store flags + DMA
    mov.w r0, @(4, r2)                  ! slot_data[index].size = size_param (delay slot)

    .global DAT_060076e2
_wpool_lo_byte_mask:
DAT_060076e2:
    .2byte  0x00FF                      ! mask: extract low byte (height from size_param)
_pool_slot_data_table:
    .4byte  sym_06063F64                ! sprite slot data table (8 bytes/entry)
_pool_vram_offset_ptr:
    .4byte  sym_0606A4EC                ! current VRAM write offset
_pool_sprite_index_ptr:
    .4byte  sym_0606A4F4                ! sprite index counter
_pool_vram_base_ptr:
    .4byte  sym_06063F5C                ! VDP1 VRAM base pointer
_pool_vram_addr_store:
    .4byte  sym_06063F60                ! last computed VRAM address (slot 0xA)
_pool_slot_index_table:
    .4byte  sym_060684EC                ! slot-to-index mapping table (word/slot)
.L_color_mode_lookup:
    extu.w r5, r4                       ! r4 = size_param (for color lookup call)
    mov #0x3, r0                        ! r0 = 3 (color lookup mode parameter)
    mov.w   _wpool_color_hi_mask, r2    ! r2 = 0x3F00 (color bits mask)
    mov r4, r5                          ! r5 = size_param (copy for masking)
    and r4, r2                          ! r2 = size_param & 0x3F00 (color mode bits)
    and r7, r5                          ! r5 = size_param & 0x00FF (low byte)
    extu.w r2, r2                       ! zero-extend color mode bits
    extu.w r5, r1                       ! r1 = low byte of size_param (color index arg)
    mov.w r2, @r15                      ! stack[0] = color mode bits (save for later)
    mov.l   _pool_fn_color_lookup, r3   ! r3 = &color_lookup_fn
    jsr @r3                             ! r0 = color_lookup(r0=3, r1=color_byte)
    extu.w r1, r1                       ! zero-extend r1 for call (delay slot)
    mov r0, r5                          ! r5 = resolved color value
    mov.w @r15, r3                      ! r3 = saved color mode bits
    extu.w r5, r1                       ! r1 = resolved color value (16-bit)
    extu.w r3, r3                       ! zero-extend color mode bits
    or r3, r1                           ! r1 = resolved_color | color_mode_bits
    extu.w r1, r5                       ! r5 = combined size/color word
    mov.l @r14, r3                      ! r3 = sprite_index
    shll2 r3                            ! r3 *= 4
    shll r3                             ! r3 *= 2 (total: index * 8)
    add r12, r3                         ! r3 = &slot_data_table[index]
    mov r5, r0                          ! r0 = combined word
    mov.w r0, @(4, r3)                  ! slot_data[index].size = combined word
    mov.l @r13, r3                      ! r3 = vram_write_offset
    mov.l   _pool_saved_index_store, r2 ! r2 = &saved_sprite_index
    mov.l r3, @r2                       ! saved_sprite_index = vram_write_offset
.L_store_flags:
    mov r6, r0                          ! r0 = flags argument
    mov.l @r14, r3                      ! r3 = sprite_index
    shll2 r3                            ! r3 *= 4
    shll r3                             ! r3 *= 2 (total: index * 8)
    add r12, r3                         ! r3 = &slot_data_table[index]
    mov.w r0, @(6, r3)                  ! slot_data[index].flags = flags
    mov.l @r13, r5                      ! r5 = vram_write_offset
    mov.l   _pool_vram_base_ptr_b, r3   ! r3 = &vram_base_ptr
    mov.l   _pool_fn_dma_transfer, r2   ! r2 = &dma_memory_transfer
    shll2 r5                            ! r5 *= 4
    mov.l @r3, r3                       ! r3 = vram_base
    shll r5                             ! r5 *= 2 (total: offset * 8)
    add r3, r5                          ! r5 = vram_base + offset*8 = DMA dest addr
    jsr @r2                             ! dma_memory_transfer(r4=src_addr, r5=dest)
    mov.l @(4, r15), r4                 ! r4 = src_addr from stack (delay slot)
    mov.l @r14, r3                      ! r3 = sprite_index
    add #0x1, r3                        ! r3 = sprite_index + 1
    mov.l r3, @r14                      ! sprite_index_counter++
    mov.w @(8, r15), r0                 ! r0 = width
    mov.l @r13, r2                      ! r2 = vram_write_offset
    mov r0, r4                          ! r4 = width
    mov.w @(12, r15), r0                ! r0 = height
    mov r0, r3                          ! r3 = height
    mulu.w r3, r4                       ! MACL = width * height
    mov #0x0, r3                        ! r3 = 0
    sts macl, r4                        ! r4 = width * height
    cmp/gt r4, r3                       ! T = (0 > w*h)? i.e. T=0 if product >= 0
    addc r3, r4                         ! r4 = w*h + T (add carry for rounding)
    shar r4                             ! r4 = (w*h + T) / 2 = ceil(w*h / 2)
    add r4, r2                          ! r2 = vram_offset + ceil(w*h/2)
    mov.l r2, @r13                      ! update vram_write_offset
    add #0x10, r15                      ! deallocate stack frame
    lds.l @r15+, macl                   ! restore MACL
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return to caller
    mov.l @r15+, r14                    ! restore r14 (delay slot)

    .global DAT_0600777e
_wpool_color_hi_mask:
DAT_0600777e:
    .2byte  0x3F00                      ! mask: extract color mode bits (bits 13:8)
_pool_fn_color_lookup:
    .4byte  sym_06034FE0                ! color/texture lookup function
_pool_saved_index_store:
    .4byte  sym_0606A4F0                ! saved sprite index (for color-mode slots)
_pool_vram_base_ptr_b:
    .4byte  sym_06063F5C                ! VDP1 VRAM base pointer (second pool ref)
_pool_fn_dma_transfer:
    .4byte  dma_memory_transfer         ! DMA memory-to-memory transfer function
