/* render_batch_proc -- VDP1 sprite batch rendering (course-specific variant)
 * Translation unit: 0x0602304C - 0x06023290 (580 bytes, 1 function)
 *
 * Simplified variant of projection_mgr that processes 0x28 (40) render
 * channels from the channel descriptor table at sym_06054380.  Each channel
 * descriptor is 12 bytes: {primary_data_ptr(4), secondary_data_ptr(4),
 * primary_count(2), secondary_count(2)}.
 *
 * Phase 1 — Index table init:
 *   Fills the VDP1 sprite index table (sym_06089E44) with sequential
 *   halfword values 0x03..0x37 (entries [2]..[43]).
 *
 * Phase 2 — VDP1 display data copy:
 *   Reads game_state_index from sym_06059FFC, indexes into the scroll
 *   base table (sym_06063F5C), and copies 0x3AC0 halfwords of display
 *   data into VDP1 VRAM at 0x002A8000 via memcpy_word_idx.
 *
 * Phase 3 — Per-channel sprite rendering (0x28 channels):
 *   For each channel 0x00..0x27:
 *     - Primary entries: 12-byte stride, rendered via vdp1_sprite_render_alt
 *     - Secondary entries: 6-byte stride, rendered via sym_06007590
 *   Channel 0x27 is special: adds +0x2F to the running sprite index.
 *   All other channels add +0xA per channel.
 *
 * Phase 4 — Extra entry:
 *   After all 0x28 channels, adds +0x15 to the sprite index,
 *   processes one final descriptor from sym_06054560 (primary entries
 *   only), and stores the final sprite index to sym_0607886C
 *   (sprite bank base halfword).
 *
 * Called from: course0_bg_load (tail call after background data setup).
 *
 * Register usage:
 *   r8  = primary/secondary entry count (per-channel)
 *   r9  = sub-index counter (inner loops)
 *   r10 = current entry data pointer
 *   r11 = VDP1 VRAM dest base (0x002A8000)
 *   r12 = 0 (constant, used for counter resets)
 *   r13 = channel loop counter (outer loop)
 *   r14 = running VDP1 sprite word index (accumulator)
 */

    .section .text.FUN_0602304C


    .global render_batch_proc
    .type render_batch_proc, @function
render_batch_proc:
    mov.l r14, @-r15                        ! save r14 (callee-saved)
    mov.l r13, @-r15                        ! save r13
    mov.l r12, @-r15                        ! save r12
    mov.l r11, @-r15                        ! save r11
    mov.l r10, @-r15                        ! save r10
    mov.l r9, @-r15                         ! save r9
    mov.l r8, @-r15                         ! save r8
    sts.l pr, @-r15                         ! save pr (return address)
    mov #0x0, r12                           ! r12 = 0 (constant for counter resets)
    mov.l   _pool_sprite_index_table, r4    ! r4 = &sprite_index_table (sym_06089E44)
    mov #0x3, r0                            ! r0 = 0x03 (first index value)
    mov.w r0, @(4, r4)                      ! table[2] = 0x03
    mov #0x4, r0                            ! r0 = 0x04
    mov.w r0, @(6, r4)                      ! table[3] = 0x04
    mov #0x5, r0                            ! r0 = 0x05
    mov.w r0, @(8, r4)                      ! table[4] = 0x05
    mov #0x6, r0                            ! r0 = 0x06
    mov.w r0, @(10, r4)                     ! table[5] = 0x06
    mov #0x7, r0                            ! r0 = 0x07
    mov.w r0, @(12, r4)                     ! table[6] = 0x07
    mov #0x8, r0                            ! r0 = 0x08
    mov.w r0, @(14, r4)                     ! table[7] = 0x08
    mov #0x9, r0                            ! r0 = 0x09
    mov.w r0, @(16, r4)                     ! table[8] = 0x09
    mov #0xA, r0                            ! r0 = 0x0A
    mov.w r0, @(18, r4)                     ! table[9] = 0x0A
    mov #0xB, r0                            ! r0 = 0x0B
    mov.w r0, @(20, r4)                     ! table[10] = 0x0B
    mov #0xC, r0                            ! r0 = 0x0C
    mov.w r0, @(22, r4)                     ! table[11] = 0x0C
    mov #0xD, r0                            ! r0 = 0x0D
    mov.w r0, @(24, r4)                     ! table[12] = 0x0D
    mov #0xE, r0                            ! r0 = 0x0E
    mov.w r0, @(26, r4)                     ! table[13] = 0x0E
    mov #0xF, r0                            ! r0 = 0x0F
    mov.w r0, @(28, r4)                     ! table[14] = 0x0F
    mov #0x10, r0                           ! r0 = 0x10
    mov.w r0, @(30, r4)                     ! table[15] = 0x10
    mov r4, r3                              ! r3 = table base
    add #0x20, r3                           ! r3 = &table[16]
    mov #0x11, r2                           ! r2 = 0x11
    mov.w r2, @r3                           ! table[16] = 0x11
    mov r4, r3                              ! r3 = table base
    add #0x22, r3                           ! r3 = &table[17]
    mov #0x12, r2                           ! r2 = 0x12
    mov.w r2, @r3                           ! table[17] = 0x12
    mov r4, r3                              ! r3 = table base
    add #0x24, r3                           ! r3 = &table[18]
    mov #0x13, r2                           ! r2 = 0x13
    mov.w r2, @r3                           ! table[18] = 0x13
    mov r4, r3                              ! r3 = table base
    add #0x26, r3                           ! r3 = &table[19]
    mov #0x14, r2                           ! r2 = 0x14
    mov.w r2, @r3                           ! table[19] = 0x14
    mov r4, r3                              ! r3 = table base
    add #0x28, r3                           ! r3 = &table[20]
    mov #0x15, r2                           ! r2 = 0x15
    mov.w r2, @r3                           ! table[20] = 0x15
    mov r4, r3                              ! r3 = table base
    add #0x2A, r3                           ! r3 = &table[21]
    mov #0x16, r2                           ! r2 = 0x16
    mov.w r2, @r3                           ! table[21] = 0x16
    mov r4, r3                              ! r3 = table base
    add #0x2C, r3                           ! r3 = &table[22]
    mov #0x17, r2                           ! r2 = 0x17
    mov.w r2, @r3                           ! table[22] = 0x17
    mov r4, r3                              ! r3 = table base
    add #0x2E, r3                           ! r3 = &table[23]
    mov #0x18, r2                           ! r2 = 0x18
    mov.w r2, @r3                           ! table[23] = 0x18
    mov r4, r3                              ! r3 = table base
    add #0x30, r3                           ! r3 = &table[24]
    mov #0x19, r2                           ! r2 = 0x19
    mov.w r2, @r3                           ! table[24] = 0x19
    mov r4, r3                              ! r3 = table base
    add #0x32, r3                           ! r3 = &table[25]
    mov #0x1A, r2                           ! r2 = 0x1A
    mov.w r2, @r3                           ! table[25] = 0x1A
    mov r4, r3                              ! r3 = table base
    add #0x34, r3                           ! r3 = &table[26]
    mov #0x1B, r2                           ! r2 = 0x1B
    mov.w r2, @r3                           ! table[26] = 0x1B
    mov r4, r3                              ! r3 = table base
    add #0x36, r3                           ! r3 = &table[27]
    mov #0x1C, r2                           ! r2 = 0x1C
    mov.w r2, @r3                           ! table[27] = 0x1C
    mov r4, r3                              ! r3 = table base
    add #0x38, r3                           ! r3 = &table[28]
    mov #0x1D, r2                           ! r2 = 0x1D
    mov.w r2, @r3                           ! table[28] = 0x1D
    mov #0x1E, r5                           ! r5 = 0x1E (saved for r14 init later)
    mov r4, r3                              ! r3 = table base
    add #0x3A, r3                           ! r3 = &table[29]
    extu.w r5, r2                           ! r2 = 0x001E (zero-extend)
    mov.w r2, @r3                           ! table[29] = 0x1E
    mov r4, r3                              ! r3 = table base
    add #0x3C, r3                           ! r3 = &table[30]
    mov #0x1F, r2                           ! r2 = 0x1F
    mov.w r2, @r3                           ! table[30] = 0x1F
    mov r4, r3                              ! r3 = table base
    add #0x3E, r3                           ! r3 = &table[31]
    mov #0x20, r2                           ! r2 = 0x20
    mov.w r2, @r3                           ! table[31] = 0x20
    mov r4, r3                              ! r3 = table base
    add #0x40, r3                           ! r3 = &table[32]
    mov #0x21, r2                           ! r2 = 0x21
    mov.w r2, @r3                           ! table[32] = 0x21
    mov r4, r3                              ! r3 = table base
    add #0x42, r3                           ! r3 = &table[33]
    mov #0x22, r2                           ! r2 = 0x22
    mov.w r2, @r3                           ! table[33] = 0x22
    mov r4, r3                              ! r3 = table base
    add #0x44, r3                           ! r3 = &table[34]
    mov #0x23, r2                           ! r2 = 0x23
    mov.w r2, @r3                           ! table[34] = 0x23
    mov r4, r3                              ! r3 = table base
    add #0x46, r3                           ! r3 = &table[35]
    mov #0x24, r2                           ! r2 = 0x24
    mov.w r2, @r3                           ! table[35] = 0x24
    mov r4, r3                              ! r3 = table base
    add #0x48, r3                           ! r3 = &table[36]
    mov #0x25, r2                           ! r2 = 0x25
    mov.w r2, @r3                           ! table[36] = 0x25
    mov r4, r3                              ! r3 = table base
    add #0x4A, r3                           ! r3 = &table[37]
    mov #0x26, r2                           ! r2 = 0x26
    mov.w r2, @r3                           ! table[37] = 0x26
    mov r4, r3                              ! r3 = table base
    add #0x4C, r3                           ! r3 = &table[38]
    mov #0x27, r2                           ! r2 = 0x27
    mov.w r2, @r3                           ! table[38] = 0x27
    mov r4, r3                              ! r3 = table base
    add #0x4E, r3                           ! r3 = &table[39]
    mov #0x28, r2                           ! r2 = 0x28
    mov.w r2, @r3                           ! table[39] = 0x28
    mov r4, r3                              ! r3 = table base
    add #0x50, r3                           ! r3 = &table[40]
    mov #0x29, r2                           ! r2 = 0x29
    mov.w r2, @r3                           ! table[40] = 0x29
    mov r4, r3                              ! r3 = table base
    add #0x52, r3                           ! r3 = &table[41]
    mov #0x2A, r2                           ! r2 = 0x2A
    mov.w r2, @r3                           ! table[41] = 0x2A
    mov r4, r3                              ! r3 = table base
    add #0x54, r3                           ! r3 = &table[42] (skip to 0x36)
    mov #0x36, r2                           ! r2 = 0x36 (gap: indices 0x2B-0x35 skipped)
    mov.w r2, @r3                           ! table[42] = 0x36
    add #0x56, r4                           ! r4 = &table[43]
    mov #0x37, r3                           ! r3 = 0x37
    mov.w r3, @r4                           ! table[43] = 0x37
    extu.w r5, r14                          ! r14 = 0x1E (initial sprite word index)
    mov.l   _pool_vdp1_vram_base, r11      ! r11 = 0x002A8000 (VDP1 VRAM dest base)
    mov.w   _wpool_copy_count, r6          ! r6 = 0x3AC0 (halfword count for display data copy)
    mov.l   _pool_game_state_idx_ptr, r4   ! r4 = &game_state_index (sym_06059FFC)
    bra     .L_copy_vdp1_data              ! -> copy VDP1 display data
    mov r11, r5                             ! r5 = VDP1 VRAM dest base (delay slot)
_wpool_copy_count:
    .2byte  0x3AC0                          ! halfword count: 0x3AC0 words of display data
    .2byte  0xFFFF                          ! padding (alignment)
_pool_sprite_index_table:
    .4byte  sym_06089E44                    ! sprite word index table (halfword array)
_pool_vdp1_vram_base:
    .4byte  0x002A8000                      ! VDP1 VRAM destination address
_pool_game_state_idx_ptr:
    .4byte  sym_06059FFC                    ! game state index pointer
.L_copy_vdp1_data:
    mov.l @r4, r4                           ! r4 = game_state_index (dereference)
    mov.l   _pool_scroll_base_table, r3    ! r3 = &scroll_base_table (sym_06063F5C)
    mov.w   _wpool_scroll_data_offset, r2  ! r2 = 0x03C0 (offset into scroll data block)
    shll2 r4                                ! r4 *= 4
    mov.l @r3, r3                           ! r3 = scroll_base_table (dereference)
    shll r4                                 ! r4 *= 2 (total: state_index * 8)
    add r3, r4                              ! r4 = scroll_base + state_index * 8
    add r2, r4                              ! r4 += 0x03C0 (source addr for VDP1 data copy)
    mov.l   _pool_memcpy_word_idx, r2      ! r2 = &memcpy_word_idx
    jsr @r2                                 ! memcpy_word_idx(dst=r5, src=r4, count=r6)
    nop                                     ! (delay slot)
    bra     .L_channel_loop_test           ! -> enter channel loop at test
    extu.w r12, r13                         ! r13 = 0 (channel counter, delay slot)
.L_channel_loop_body:
    mov r13, r4                             ! r4 = channel index
    mov r13, r3                             ! r3 = channel index
    mov.l   _pool_channel_table_base, r2   ! r2 = channel descriptor table (sym_06054380)
    shll2 r4                                ! r4 *= 4
    shll2 r3                                ! r3 *= 4
    shll r3                                 ! r3 *= 2 (total: index * 8)
    add r3, r4                              ! r4 = index*4 + index*8 = index * 12
    exts.w r4, r4                           ! r4 = sign-extend offset to 32 bits
    add r2, r4                              ! r4 = &channel_desc[index] (12-byte entry)
    mov.l @r4, r10                          ! r10 = channel[+0] primary data pointer
    mov.w @(8, r4), r0                      ! r0 = channel[+8] primary entry count
    mov r0, r8                              ! r8 = primary entry count
    extu.w r8, r3                           ! r3 = primary count (unsigned)
    cmp/pl r3                               ! primary count > 0?
    bf/s    .L_primary_done                ! if no primary entries -> skip
    extu.w r12, r9                          ! r9 = 0 (primary sub-index counter, delay slot)
.L_primary_loop:
    mov r11, r6                             ! r6 = VDP1 VRAM base (arg3)
    extu.w r14, r5                          ! r5 = sprite word index (arg2)
    mov.l   _pool_sprite_render_fn, r3     ! r3 = &vdp1_sprite_render_alt
    jsr @r3                                 ! vdp1_sprite_render_alt(data=r4, idx=r5, vram=r6)
    mov r10, r4                             ! r4 = current entry ptr (arg1, delay slot)
    add #0x1, r9                            ! r9++ (sub-index)
    extu.w r8, r3                           ! r3 = primary entry count
    extu.w r9, r2                           ! r2 = current sub-index
    cmp/ge r3, r2                           ! sub-index >= count?
    bf/s    .L_primary_loop                ! if more entries -> continue loop
    add #0xC, r10                           ! r10 += 12 (next entry, delay slot)
.L_primary_done:
    mov r13, r4                             ! r4 = channel index
    mov r13, r3                             ! r3 = channel index
    mov.l   _pool_channel_table_base, r2   ! r2 = channel descriptor table (sym_06054380)
    shll2 r4                                ! r4 *= 4
    shll2 r3                                ! r3 *= 4
    shll r3                                 ! r3 *= 2 (total: index * 8)
    add r3, r4                              ! r4 = index * 12
    exts.w r4, r4                           ! r4 = sign-extend offset
    add r2, r4                              ! r4 = &channel_desc[index]
    mov.w @(10, r4), r0                     ! r0 = channel[+10] secondary entry count
    mov r0, r8                              ! r8 = secondary entry count
    extu.w r13, r0                          ! r0 = channel index
    cmp/eq #0x27, r0                        ! channel == 0x27?
    bf/s    .L_not_special_channel         ! if not -> skip special adjustment
    mov.l @(4, r4), r10                     ! r10 = channel[+4] secondary data ptr (delay slot)
    add #0x2F, r14                          ! r14 += 0x2F (extra sprite index for ch 0x27)
.L_not_special_channel:
    extu.w r8, r2                           ! r2 = secondary count (unsigned)
    cmp/pl r2                               ! secondary count > 0?
    bf/s    .L_secondary_done              ! if no secondary entries -> skip
    extu.w r12, r9                          ! r9 = 0 (secondary sub-index counter, delay slot)
.L_secondary_loop:
    extu.w r14, r5                          ! r5 = sprite word index (arg2)
    mov.l   _pool_secondary_render_fn, r3  ! r3 = &sym_06007590 (secondary sprite renderer)
    jsr @r3                                 ! sym_06007590(data=r4, idx=r5)
    mov r10, r4                             ! r4 = current entry ptr (arg1, delay slot)
    add #0x1, r9                            ! r9++ (sub-index)
    extu.w r8, r3                           ! r3 = secondary entry count
    extu.w r9, r2                           ! r2 = current sub-index
    cmp/ge r3, r2                           ! sub-index >= count?
    bf/s    .L_secondary_loop              ! if more entries -> continue loop
    add #0x6, r10                           ! r10 += 6 (next entry, delay slot)
.L_secondary_done:
    extu.w r13, r3                          ! r3 = channel index
    mov #0x27, r2                           ! r2 = 0x27 (last channel before extra bump)
    cmp/ge r2, r3                           ! channel >= 0x27?
    bt      .L_skip_index_bump             ! if >= 0x27 -> skip normal +0xA bump
    add #0xA, r14                           ! r14 += 0x0A (per-channel sprite index bump)
.L_skip_index_bump:
    add #0x1, r13                           ! r13++ (next channel)
.L_channel_loop_test:
    extu.w r13, r2                          ! r2 = channel index (unsigned)
    mov #0x28, r3                           ! r3 = 0x28 (total channels = 40)
    cmp/ge r3, r2                           ! channel >= 0x28?
    bf      .L_channel_loop_body           ! if more channels -> continue loop
    add #0x15, r14                          ! r14 += 0x15 (final sprite index bump)
    mov.l   _pool_sprite_bank_base, r3     ! r3 = &sprite_bank_base (sym_0607886C)
    mov.l   _pool_extra_desc, r4           ! r4 = &extra_desc (sym_06054560)
    mov.l @r4, r13                          ! r13 = extra_desc[+0] primary data pointer
    mov.w @(8, r4), r0                      ! r0 = extra_desc[+8] primary entry count
    mov.w r14, @r3                          ! sprite_bank_base = final sprite index
    mov r0, r9                              ! r9 = extra primary entry count
    extu.w r9, r2                           ! r2 = extra count (unsigned)
    cmp/pl r2                               ! extra count > 0?
    bf/s    .L_epilogue                    ! if no extra entries -> done
    extu.w r12, r10                         ! r10 = 0 (extra sub-index counter, delay slot)
.L_extra_primary_loop:
    mov r11, r6                             ! r6 = VDP1 VRAM base (arg3)
    extu.w r14, r5                          ! r5 = sprite word index (arg2)
    mov.l   _pool_sprite_render_fn, r3     ! r3 = &vdp1_sprite_render_alt
    jsr @r3                                 ! vdp1_sprite_render_alt(data=r4, idx=r5, vram=r6)
    mov r13, r4                             ! r4 = current entry ptr (arg1, delay slot)
    add #0x1, r10                           ! r10++ (sub-index)
    extu.w r9, r3                           ! r3 = extra entry count
    extu.w r10, r2                          ! r2 = current sub-index
    cmp/ge r3, r2                           ! sub-index >= count?
    bf/s    .L_extra_primary_loop          ! if more entries -> continue loop
    add #0xC, r13                           ! r13 += 12 (next entry, delay slot)
.L_epilogue:
    lds.l @r15+, pr                         ! restore pr (return address)
    mov.l @r15+, r8                         ! restore r8
    mov.l @r15+, r9                         ! restore r9
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return
    mov.l @r15+, r14                        ! restore r14 (delay slot)
_wpool_scroll_data_offset:
    .2byte  0x03C0                          ! offset into scroll data block
_pool_scroll_base_table:
    .4byte  sym_06063F5C                    ! scroll/display base table pointer
_pool_memcpy_word_idx:
    .4byte  memcpy_word_idx                 ! word-indexed memory copy function
_pool_channel_table_base:
    .4byte  sym_06054380                    ! channel descriptor table (12 bytes/entry, 40 channels)
_pool_sprite_render_fn:
    .4byte  vdp1_sprite_render_alt          ! primary sprite renderer (12-byte stride entries)
_pool_secondary_render_fn:
    .4byte  sym_06007590                    ! secondary sprite renderer (6-byte stride entries)
_pool_extra_desc:
    .4byte  sym_06054560                    ! extra channel descriptor (post-loop)
_pool_sprite_bank_base:
    .4byte  sym_0607886C                    ! sprite bank base halfword (final index stored here)
