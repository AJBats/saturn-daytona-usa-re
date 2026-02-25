/* vdp1_sprite_render_alt -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06007790 - 0x060078DC
 *
 * VDP1 sprite slot builder — writes one display command slot into the
 * per-slot data table, resolves color bank for special command types
 * (0xD/0xE/0xF), and triggers a DMA transfer of texture data into
 * VDP1 VRAM.
 *
 * vdp1_sprite_render_alt (0x06007790):
 *   r4 = pointer to 12-byte sprite descriptor:
 *         [0] .w  command type (0x0A = normal, 0x0D-0x0F = special)
 *         [2] .w  attribute word (color bank in bits 13:8, palette in bits 7:0)
 *         [4] .w  texture VRAM offset (base slot address)
 *         [8] .l  texture source ROM/RAM address
 *   r5 = texture bank index (shifted left 2 to form VRAM offset)
 *   r6 = source address offset (added to descriptor's source addr)
 *
 *   Steps:
 *     1. If cmd type == 0xA, compute DMA dest from slot counter * 8
 *     2. Write command link into jump table (sym_060684EC indexed by type)
 *     3. Store current slot counter into per-slot data table (sym_06063F64)
 *     4. For types 0xD/0xE/0xF: call color bank lookup (sym_06034FE0)
 *        with mode=3 and index=palette, merge result into attribute word
 *     5. Compute texture source = descriptor[8] + r6 offset
 *     6. Compute texture dest = slot_counter * 8 + display base table
 *     7. DMA transfer texture data from source to dest
 *     8. Advance slot counter by (width * height) texels
 *
 * External references:
 *   sym_06063F64 -- per-slot data table (8 bytes/slot: link, size, grda, etc.)
 *   sym_0606A4EC -- VDP1 command slot counter (current index)
 *   sym_0606A4F4 -- VDP1 slot config register
 *   sym_06063F5C -- display/scroll base table pointer
 *   sym_06063F60 -- DMA destination pointer (set for cmd type 0xA)
 *   sym_060684EC -- command type -> VRAM jump table
 *   sym_0606A4F0 -- slot counter shadow (written after special types)
 *   sym_06034FE0 -- color bank lookup (r0=mode, r1=index -> r0=bank)
 *   dma_memory_transfer -- DMA memory-to-memory copy
 */

    .section .text.FUN_06007790


    .global vdp1_sprite_render_alt
    .type vdp1_sprite_render_alt, @function
vdp1_sprite_render_alt:
    mov.l r14, @-r15                        ! save r14 (callee-saved)
    mov.l r13, @-r15                        ! save r13 (callee-saved)
    mov.l r12, @-r15                        ! save r12 (callee-saved)
    sts.l pr, @-r15                         ! save return address
    sts.l macl, @-r15                       ! save MACL (multiply accumulator)
    add #-0x10, r15                         ! allocate 16 bytes of stack locals
    mov.l   _pool_slot_data_table, r12      ! r12 = per-slot data table base (sym_06063F64)
    mov.l   _pool_slot_counter, r13         ! r13 = &slot_counter (sym_0606A4EC)
    mov.l   _pool_slot_config, r14          ! r14 = &slot_config (sym_0606A4F4)
    mov.w @r4, r0                           ! r0 = descriptor[0] (command type word)
    extu.w r0, r0                           ! zero-extend command type to 32-bit
    cmp/eq #0xA, r0                         ! is command type == 0xA (normal sprite)?
    bf      .L_skip_dma_dest                ! if not normal sprite, skip DMA dest calc
    mov.l @r13, r2                          ! r2 = current slot counter
    shll2 r2                                ! r2 = slot_counter * 4
    shll r2                                 ! r2 = slot_counter * 8 (8 bytes per slot)
    mov.l   _pool_display_base_ptr, r3      ! r3 = &display_base_ptr (sym_06063F5C)
    mov.l @r3, r3                           ! r3 = display base address
    add r3, r2                              ! r2 = display_base + slot_counter * 8
    mov.l   _pool_dma_dest_ptr, r1          ! r1 = &dma_dest (sym_06063F60)
    mov.l r2, @r1                           ! store computed DMA destination
.L_skip_dma_dest:
    mov.w @(2, r4), r0                      ! r0 = descriptor[2] (attribute word)
    mov r0, r7                              ! r7 = attribute word (preserved copy)
    extu.w r7, r0                           ! r0 = attribute word zero-extended
    mov.l r0, @r15                          ! stack[0] = full attribute word
    shar r0                                 ! r0 >>= 1 (arithmetic shift right)
    shar r0                                 ! r0 >>= 2
    shar r0                                 ! r0 >>= 3
    shar r0                                 ! r0 >>= 4
    shar r0                                 ! r0 >>= 5
    shar r0                                 ! r0 >>= 6
    shar r0                                 ! r0 >>= 7
    shar r0                                 ! r0 >>= 8 (extract bits 13:8 as width)
    and #0x3F, r0                           ! r0 = width field (6-bit, bits 13:8)
    extu.w r0, r0                           ! zero-extend width
    mov.w r0, @(12, r15)                    ! stack[12] = texture width
    mov.l @r15, r0                          ! r0 = full attribute word (reload)
    and #0xFF, r0                           ! r0 = palette index (low 8 bits)
    extu.w r0, r0                           ! zero-extend palette index
    mov.w r0, @(8, r15)                     ! stack[8] = palette index (height)
    mov.w @r4, r3                           ! r3 = descriptor[0] (command type)
    mov.l   _pool_cmd_jump_table, r2        ! r2 = jump table base (sym_060684EC)
    mov.l @r14, r1                          ! r1 = slot config (current config value)
    extu.w r3, r3                           ! zero-extend command type
    shll r3                                 ! r3 = cmd_type * 2 (word index)
    add r2, r3                              ! r3 = &jump_table[cmd_type]
    mov.w r1, @r3                           ! jump_table[cmd_type] = slot config (link)
    mov.l @r14, r3                          ! r3 = slot config value
    shll2 r3                                ! r3 = config * 4
    shll r3                                 ! r3 = config * 8 (8 bytes per entry)
    add r12, r3                             ! r3 = &slot_data_table[config]
    mov.l @r13, r2                          ! r2 = current slot counter
    mov.l r2, @r3                           ! slot_data_table[config] = slot counter
    mov.w @r4, r1                           ! r1 = descriptor[0] (command type)
    extu.w r1, r1                           ! zero-extend command type
    mov r1, r0                              ! r0 = command type (for compare)
    cmp/eq #0xD, r0                         ! is type == 0xD (special type 1)?
    bt      .L_special_cmd_type             ! if yes, do color bank lookup
    mov r1, r0                              ! r0 = command type
    cmp/eq #0xE, r0                         ! is type == 0xE (special type 2)?
    bt      .L_special_cmd_type             ! if yes, do color bank lookup
    mov r1, r0                              ! r0 = command type
    cmp/eq #0xF, r0                         ! is type == 0xF (special type 3)?
    bt      .L_special_cmd_type             ! if yes, do color bank lookup
    mov.l @r14, r2                          ! r2 = slot config (normal path)
    shll2 r2                                ! r2 = config * 4
    shll r2                                 ! r2 = config * 8
    add r12, r2                             ! r2 = &slot_data_table[config]
    mov r7, r0                              ! r0 = raw attribute word
    bra     .L_store_attr_and_continue      ! skip color bank path
    mov.w r0, @(4, r2)                      ! (delay) slot_data[config].attr = raw attrib
    .2byte  0xFFFF                           /* alignment padding */
_pool_slot_data_table:
    .4byte  sym_06063F64                     /* per-slot data table base */
_pool_slot_counter:
    .4byte  sym_0606A4EC                     /* VDP1 command slot counter */
_pool_slot_config:
    .4byte  sym_0606A4F4                     /* VDP1 slot config register */
_pool_display_base_ptr:
    .4byte  sym_06063F5C                     /* display/scroll base table pointer */
_pool_dma_dest_ptr:
    .4byte  sym_06063F60                     /* DMA destination pointer */
_pool_cmd_jump_table:
    .4byte  sym_060684EC                     /* command type -> VRAM jump table */
.L_special_cmd_type:
    extu.w r7, r7                           ! zero-extend attribute word
    mov.l r7, @(4, r15)                     ! stack[4] = full attribute word (backup)
    mov.w   DAT_060078ca, r3                ! r3 = 0x3F00 (color bank mask, bits 13:8)
    and r3, r7                              ! r7 = attribute & 0x3F00 (isolate color bank)
    extu.w r7, r7                           ! zero-extend masked color bank
    mov.w r7, @r15                          ! stack[0] = color bank bits only
    mov.l @(4, r15), r0                     ! r0 = full attribute word (reload backup)
    mov.l   _pool_color_bank_lookup, r3     ! r3 = color_bank_lookup fn (sym_06034FE0)
    and #0xFF, r0                           ! r0 = palette index (low byte)
    extu.w r0, r1                           ! r1 = palette index (arg 2)
    mov #0x3, r0                            ! r0 = 3 (lookup mode: color bank)
    jsr @r3                                 ! call color_bank_lookup(mode=3, index=r1)
    extu.w r1, r1                           ! (delay) ensure r1 is clean 16-bit
    mov r0, r7                              ! r7 = returned color bank value
    mov.w @r15, r3                          ! r3 = saved color bank mask bits
    extu.w r7, r2                           ! r2 = color bank result (zero-extended)
    extu.w r3, r3                           ! r3 = color bank mask bits (zero-extended)
    or r3, r2                               ! r2 = lookup result | original bank bits
    extu.w r2, r7                           ! r7 = merged attribute word
    mov.l @r14, r3                          ! r3 = slot config
    shll2 r3                                ! r3 = config * 4
    shll r3                                 ! r3 = config * 8
    add r12, r3                             ! r3 = &slot_data_table[config]
    mov r7, r0                              ! r0 = merged attribute word
    mov.w r0, @(4, r3)                      ! slot_data[config].attr = merged attrib
    mov.l @r13, r3                          ! r3 = current slot counter
    mov.l   _pool_slot_counter_shadow, r2   ! r2 = &slot_counter_shadow (sym_0606A4F0)
    mov.l r3, @r2                           ! update shadow with current counter
.L_store_attr_and_continue:
    mov.l @r14, r3                          ! r3 = slot config
    extu.w r5, r5                           ! r5 = texture bank index (zero-extended)
    mov.w @(4, r4), r0                      ! r0 = descriptor[4] (texture VRAM offset)
    shll2 r3                                ! r3 = config * 4
    shll2 r5                                ! r5 = bank_index * 4 (VRAM bank offset)
    mov r0, r2                              ! r2 = texture VRAM offset
    shll r3                                 ! r3 = config * 8
    extu.w r2, r2                           ! zero-extend VRAM offset
    add r12, r3                             ! r3 = &slot_data_table[config]
    add r5, r2                              ! r2 = VRAM_offset + bank_offset
    extu.w r2, r0                           ! r0 = combined VRAM address (16-bit)
    mov.w r0, @(6, r3)                      ! slot_data[config].vram_addr = combined addr
    mov.l @(8, r4), r4                      ! r4 = descriptor[8] (texture source addr)
    mov.l @r13, r5                          ! r5 = current slot counter
    mov.l   _pool_display_base_ptr_b, r3    ! r3 = &display_base_ptr (sym_06063F5C)
    mov.l   _pool_dma_transfer_fn, r2       ! r2 = dma_memory_transfer fn ptr
    add r6, r4                              ! r4 = source + offset (DMA source addr)
    shll2 r5                                ! r5 = slot_counter * 4
    mov.l @r3, r3                           ! r3 = display base address
    shll r5                                 ! r5 = slot_counter * 8 (DMA dest offset)
    jsr @r2                                 ! call dma_memory_transfer(r4=src, r5=dest)
    add r3, r5                              ! (delay) r5 = display_base + counter * 8
    mov.l @r14, r3                          ! r3 = slot config
    add #0x1, r3                            ! r3 = config + 1 (advance to next slot)
    mov.l r3, @r14                          ! store incremented config
    mov.w @(12, r15), r0                    ! r0 = texture width (from stack)
    mov.l @r13, r2                          ! r2 = current slot counter
    mov r0, r4                              ! r4 = width (multiplicand)
    mov.w @(8, r15), r0                     ! r0 = palette/height (from stack)
    mov r0, r3                              ! r3 = height (multiplier)
    mulu.w r3, r4                           ! MACL = width * height (texel count)
    mov #0x0, r3                            ! r3 = 0 (for rounding)
    sts macl, r4                            ! r4 = width * height
    cmp/gt r4, r3                           ! T = (0 > product), i.e. carry check
    addc r3, r4                             ! r4 += carry (round up if negative)
    shar r4                                 ! r4 = (width * height) / 2 (slot advance)
    add r4, r2                              ! r2 = slot_counter + advance
    mov.l r2, @r13                          ! update slot counter
    add #0x10, r15                          ! free 16 bytes of stack locals
    lds.l @r15+, macl                       ! restore MACL
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! (delay) restore r14

    .global DAT_060078ca
DAT_060078ca:
    .2byte  0x3F00                           /* color bank mask (bits 13:8) */
_pool_color_bank_lookup:
    .4byte  sym_06034FE0                     /* color bank lookup function */
_pool_slot_counter_shadow:
    .4byte  sym_0606A4F0                     /* slot counter shadow register */
_pool_display_base_ptr_b:
    .4byte  sym_06063F5C                     /* display/scroll base table pointer */
_pool_dma_transfer_fn:
    .4byte  dma_memory_transfer              /* DMA memory-to-memory copy */
