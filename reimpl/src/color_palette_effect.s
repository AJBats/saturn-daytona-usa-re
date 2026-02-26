/* color_palette_effect -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060429EC - 0x06042ACA
 *
 * Copies one color entry (or a sequence) from a source palette into VDP2
 * Color RAM (CRAM) at the address determined by the current display color mode:
 *
 *   color_palette_effect(r4=palette_mask, r5=palette_src, r6=color_mode, r7=chan_data)
 *     1. Call get_display_mode (sym_0603C156) → r0 = VDP2 display color mode (0-3).
 *     2. If mode == 2 (32bpp packed): CRAM address = 0x25F00000 + (r4<<10) + (r3<<2)
 *        - color_mode==1: write one longword; else tail-call word_copy_helper.
 *     3. If mode != 2 (16bpp): CRAM address = 0x25F00000 + (r4<<9) + (r3<<1)
 *        - color_mode==1: write one word; else tail-call word_copy_helper.
 *
 * sym_06042A8C — VDP2 scroll register bit-field modifier.
 *   Modifies the flags word at *(r6-0x50) based on three control fields in
 *   the parameter block at r4 (offsets 0, 4, 8). Each field conditionally
 *   clears one or two bits in the flags word:
 *     @(8,r4) & 4 == 4 → clear bit 1 (write value from @(4,r4))
 *     @(8,r4) & 1 == 1 → clear bit 2 (bit mask 0xFFFFFFFB)
 *     @(8,r4) & 2 == 2 → clear bits 0+1 (bit mask 0xFFFFFFFC)
 */

    .section .text.FUN_060429EC


    .global color_palette_effect
    .type color_palette_effect, @function
color_palette_effect:
    mov.l r14, @-r15                        ! push r14 (callee-save)
    mov r6, r14                             ! r14 = color_mode (save arg2)
    mov.l r13, @-r15                        ! push r13 (callee-save)
    sts.l pr, @-r15                         ! push return address
    add #-0xC, r15                          ! allocate 12-byte local frame
    mov.l r4, @r15                          ! sp[0] = palette_mask (arg0)
    mov.l r5, @(4, r15)                     ! sp[4] = palette_src (arg1)
    mov.l   .L_pool_get_display_mode, r3    ! r3 = get_display_mode
    jsr @r3                                 ! call get_display_mode(r4=palette_mask)
    mov.l r7, @(8, r15)                     ! sp[8] = chan_data (arg3, delay slot)
    cmp/eq #0x2, r0                         ! is display mode == 2 (32bpp packed)?
    bf      .L_mode_not2                    ! no → 16bpp path
    mov.l @(8, r15), r13                    ! r13 = chan_data pointer
    mov.l   .L_pool_cram_palette_index, r3  ! r3 = cram_palette_index (sym_06042BFC)
    jsr @r3                                 ! call cram_palette_index(r4=palette_mask source)
    mov.l @r15, r4                          ! r4 = palette_mask (delay slot)
    shll8 r0                                ! r0 = palette_index << 8 (start of bank shift)
    mov.l   .L_vdp2_cram_0x000, r2         ! r2 = 0x25F00000 (VDP2 CRAM base)
    mov.l @(4, r15), r3                     ! r3 = palette_src
    shll2 r0                                ! r0 <<= 2 (total: index << 10 = 32bpp bank offset)
    shll2 r3                                ! r3 = palette_src << 2 (longword stride)
    add r2, r0                              ! r0 = CRAM base + bank offset
    mov r0, r4                              ! r4 = CRAM bank start address
    add r3, r4                              ! r4 = CRAM destination address (bank + entry offset)
    mov r14, r0                             ! r0 = color_mode
    cmp/eq #0x1, r0                         ! is color_mode == 1 (single entry)?
    bf      .L_mode2_multi                  ! no → copy multiple longwords
    mov.l @r13, r2                          ! r2 = *chan_data (single 32bpp color entry)
    bra     .L_return                       ! → epilog
    mov.l r2, @r4                           ! *CRAM_dst = color entry (delay slot)
.L_mode2_multi:
    mov r14, r6                             ! r6 = color_mode (entry count)
    shll2 r6                                ! r6 = color_mode << 2 (byte count for longwords)
    mov r13, r5                             ! r5 = chan_data (source pointer)
    add #0xC, r15                           ! restore stack pointer past locals
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    mov.l   .L_pool_word_copy_helper, r3    ! r3 = word_copy_helper (sym_06038A48)
    jmp @r3                                 ! tail-call word_copy_helper(r4=dst, r5=src, r6=bytes)
    mov.l @r15+, r14                        ! restore r14 (delay slot)
.L_mode_not2:
    mov.l @(8, r15), r13                    ! r13 = chan_data pointer
    mov.l   .L_pool_cram_palette_index, r3  ! r3 = cram_palette_index (sym_06042BFC)
    jsr @r3                                 ! call cram_palette_index(r4=palette_mask source)
    mov.l @r15, r4                          ! r4 = palette_mask (delay slot)
    shll8 r0                                ! r0 = palette_index << 8 (start of bank shift)
    mov.l   .L_vdp2_cram_0x000, r2         ! r2 = 0x25F00000 (VDP2 CRAM base)
    mov.l @(4, r15), r3                     ! r3 = palette_src
    shll r0                                 ! r0 <<= 1 (total: index << 9 = 16bpp bank offset)
    shll r3                                 ! r3 = palette_src << 1 (word stride)
    add r2, r0                              ! r0 = CRAM base + bank offset
    mov r0, r4                              ! r4 = CRAM bank start address
    add r3, r4                              ! r4 = CRAM destination address (bank + entry offset)
    mov r14, r0                             ! r0 = color_mode
    cmp/eq #0x1, r0                         ! is color_mode == 1 (single entry)?
    bf      .L_mode_not2_multi              ! no → copy multiple words
    mov.w @r13, r2                          ! r2 = *chan_data (single 16bpp color entry)
    bra     .L_return                       ! → epilog
    mov.w r2, @r4                           ! *CRAM_dst = color entry (delay slot)
.L_mode_not2_multi:
    mov r14, r6                             ! r6 = color_mode (entry count)
    shll r6                                 ! r6 = color_mode << 1 (byte count for words)
    mov r13, r5                             ! r5 = chan_data (source pointer)
    add #0xC, r15                           ! restore stack pointer past locals
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    mov.l   .L_pool_word_copy_helper, r3    ! r3 = word_copy_helper (sym_06038A48)
    jmp @r3                                 ! tail-call word_copy_helper(r4=dst, r5=src, r6=bytes)
    mov.l @r15+, r14                        ! restore r14 (delay slot)
.L_return:
    add #0xC, r15                           ! restore stack pointer past locals
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! restore r14 (delay slot)
    .2byte  0xFFFF
.L_pool_get_display_mode:
    .4byte  sym_0603C156
.L_pool_cram_palette_index:
    .4byte  sym_06042BFC
.L_vdp2_cram_0x000:
    .4byte  0x25F00000                  /* VDP2 color RAM +0x000 */
.L_pool_word_copy_helper:
    .4byte  sym_06038A48

    .global sym_06042A8C
sym_06042A8C:
    mov #-0x50, r6                          ! r6 = -0x50 (offset to flags word from r6 base)
    mov #-0x9, r3                           ! r3 = 0xFFFFFFF7 (clear-bit-3 mask)
    mov.l @r4, r2                           ! r2 = param_block[0] (base value to merge)
    mov #0x4, r7                            ! r7 = 0x4 (test bit 2)
    mov.l @r6, r5                           ! r5 = *flags_word (current VDP2 register value)
    and r3, r5                              ! r5 = flags_word & ~0x08 (clear bit 3)
    or r2, r5                               ! r5 |= param_block[0] (merge base value)
    mov.l @(8, r4), r3                      ! r3 = param_block[8] (control flags)
    and r7, r3                              ! r3 = param_block[8] & 0x4 (test enable-bit-1 flag)
    cmp/eq r7, r3                           ! is bit 2 of control flags set?
    bf      .L_skip_bit1_clear              ! no → skip this bit-1 update
    mov #-0x2, r3                           ! r3 = 0xFFFFFFFE (clear-bit-0 mask)
    and r3, r5                              ! r5 &= ~0x01 (clear bit 0 of flags word)
    mov.l @(4, r4), r2                      ! r2 = param_block[4] (alternate value)
    or r2, r5                               ! r5 |= param_block[4] (set bit 0 from param)
.L_skip_bit1_clear:
    mov #0x1, r7                            ! r7 = 0x1 (test bit 0)
    mov.l @(8, r4), r3                      ! r3 = param_block[8] (re-read control flags)
    and r7, r3                              ! r3 = param_block[8] & 0x1 (test bit-2-clear flag)
    cmp/eq r7, r3                           ! is bit 0 of control flags set?
    bf      .L_skip_bit2_clear              ! no → skip bit 2 clear
    mov #-0x5, r3                           ! r3 = 0xFFFFFFFB (clear-bit-2 mask)
    and r3, r5                              ! r5 &= ~0x04 (clear bit 2 of flags word)
.L_skip_bit2_clear:
    mov #0x2, r7                            ! r7 = 0x2 (test bit 1)
    mov.l @(8, r4), r2                      ! r2 = param_block[8] (re-read control flags)
    and r7, r2                              ! r2 = param_block[8] & 0x2 (test bits-0-1-clear flag)
    cmp/eq r7, r2                           ! is bit 1 of control flags set?
    bf      .L_skip_bits01_clear            ! no → skip bits 0+1 clear
    mov #-0x3, r2                           ! r2 = 0xFFFFFFFC (clear-bits-0-1 mask)
    and r2, r5                              ! r5 &= ~0x03 (clear bits 0 and 1 of flags word)
.L_skip_bits01_clear:
    rts                                     ! return to caller; r5 = modified flags word
    mov.l r5, @r6                           ! *flags_word = r5 (write back result, delay slot)
