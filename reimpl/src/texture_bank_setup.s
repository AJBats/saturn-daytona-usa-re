/* texture_bank_setup -- VDP2 character pattern bank configuration
 * Translation unit: 0x060370E4 - 0x06037660
 *
 * Configures VDP2 scroll screen (NBG0-NBG3) character pattern data
 * addresses based on a texture bank descriptor struct. Each of the
 * 4 bank slots maps to a 128KB VRAM region (0x00000, 0x20000,
 * 0x40000, 0x60000). The descriptor specifies which bank each
 * scroll screen should use for its character patterns.
 *
 * Also handles a fallback path that calls a visibility check
 * function and computes VRAM offsets via a divide helper when
 * the primary configuration path doesn't assign addresses.
 *
 * Contains two functions:
 *   texture_bank_setup  -- main bank configuration (r4 = descriptor ptr)
 *   sym_06037618         -- VDP command struct zero-init (r4 = struct ptr)
 *
 * Key data structures:
 *   sym_060A4C44 = VRAM addr output A (primary/secondary pair, 8 bytes)
 *   sym_060A3D88 = VDP2 display control register shadow (word at +14)
 *   sym_060A3E38 = scene enable flags (word at +6 = char pattern bank select)
 *   sym_060A4C4C = VRAM base address input pair (primary/secondary, 8 bytes)
 *   sym_060A4C50 = secondary scene enable flag
 *   sym_060A4C58 = primary scene active flag (byte)
 *   sym_060A4C59 = secondary scene active flag (byte)
 *   sym_0603C156 = visibility check function
 *   sym_06034FFC = divide/bank-select helper function
 */

    .section .text.FUN_060370E4


    .global texture_bank_setup
    .type texture_bank_setup, @function
texture_bank_setup:
    mov.l r14, @-r15                    ! save r14
    mov #0x0, r3                        ! r3 = 0 (zero init)
    mov.l r13, @-r15                    ! save r13
    mov r3, r2                          ! r2 = 0
    mov.l r12, @-r15                    ! save r12
    mov.l r11, @-r15                    ! save r11
    mov.l r10, @-r15                    ! save r10
    mov r4, r11                         ! r11 = descriptor ptr (arg)
    mov.l r9, @-r15                     ! save r9
    mov.l r8, @-r15                     ! save r8
    sts.l pr, @-r15                     ! save return address
    mov.l   .L_mask_byte1, r9           ! r9 = 0x0000FF00 (byte-1 mask)
    mov.l   .L_vram_addr_out, r10       ! r10 = &vram_addr_out (output pair)
    mov.l   .L_disp_ctrl_reg, r12       ! r12 = &disp_ctrl (VDP2 shadow reg)
    mov.l   .L_scene_flags, r13         ! r13 = &scene_flags (bank select)
    mov.l   .L_vram_base_in, r14        ! r14 = &vram_base_in (input pair)
    mov.l r3, @r10                      ! vram_addr_out[0] = 0 (clear primary)
    mov.l r3, @(4, r10)                 ! vram_addr_out[4] = 0 (clear secondary)
    mov.l @r11, r3                      ! r3 = descriptor[0] (primary base)
    mov.l r3, @r14                      ! vram_base_in[0] = primary base
    mov.l @(4, r11), r2                 ! r2 = descriptor[4] (secondary base)
    mov.l r2, @(4, r14)                 ! vram_base_in[4] = secondary base
    mov.w   DAT_06037154, r3            ! r3 = 0x7FFF (clear bit 15)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl word
    mov r0, r2                          ! r2 = disp_ctrl
    and r3, r2                          ! clear bit 15 (display enable)
    mov r2, r0                          ! r0 = result
    mov.w r0, @(14, r12)                ! write back disp_ctrl
    mov.b @(8, r11), r0                 ! r0 = descriptor[8] (NBG0 bit8 flag)
    extu.b r0, r0                       ! zero-extend byte
    cmp/eq #0x1, r0                     ! bit8 flag == 1?
    bf      .L_nbg0_not_bit8            ! no -> clear bit 8 path
    mov.w   DAT_06037156, r2            ! r2 = 0x0100 (bit 8 set mask)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r3                          ! r3 = disp_ctrl
    or r2, r3                           ! set bit 8
    mov r3, r0                          ! r0 = result
    bra     .L_nbg0_bit8_done           ! -> write back
    nop                                 ! (delay slot)
.L_nbg0_not_bit8:
    mov.l   .L_mask_clear_bit8, r2      ! r2 = 0x0000FEFF (clear bit 8)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r3                          ! r3 = disp_ctrl
    and r2, r3                          ! clear bit 8
    mov r3, r0                          ! r0 = result
.L_nbg0_bit8_done:
    mov.w r0, @(14, r12)                ! write back disp_ctrl (bit 8 set/clear)
    mov.b @(9, r11), r0                 ! r0 = descriptor[9] (NBG0 bit9 flag)
    extu.b r0, r0                       ! zero-extend byte
    cmp/eq #0x1, r0                     ! bit9 flag == 1?
    bf      .L_nbg0_not_bit9            ! no -> clear bit 9 path
    mov.w   .L_bit9_set, r2             ! r2 = 0x0200 (bit 9 set mask)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r3                          ! r3 = disp_ctrl
    or r2, r3                           ! set bit 9
    mov r3, r0                          ! r0 = result
    bra     .L_nbg0_bit9_done           ! -> write back
    nop                                 ! (delay slot)

    .global DAT_06037154
DAT_06037154:
    .2byte  0x7FFF

    .global DAT_06037156
DAT_06037156:
    .2byte  0x0100
.L_bit9_set:
    .2byte  0x0200
    .2byte  0xFFFF
.L_mask_byte1:
    .4byte  0x0000FF00                  /* byte 1 mask */
.L_vram_addr_out:
    .4byte  sym_060A4C44
.L_disp_ctrl_reg:
    .4byte  sym_060A3D88
.L_scene_flags:
    .4byte  sym_060A3E38
.L_vram_base_in:
    .4byte  sym_060A4C4C
.L_mask_clear_bit8:
    .4byte  0x0000FEFF
.L_nbg0_not_bit9:
    mov.l   .L_mask_clear_bit9, r2      ! r2 = 0x0000FDFF (clear bit 9)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r3                          ! r3 = disp_ctrl
    and r2, r3                          ! clear bit 9
    mov r3, r0                          ! r0 = result
.L_nbg0_bit9_done:
    mov #0x0, r5                        ! r5 = 0 (zero constant)
    mov #0x4, r2                        ! r2 = 4 (bank count threshold)
    mov.w r0, @(14, r12)                ! write back disp_ctrl (bit 9)
    extu.b r5, r4                       ! r4 = 0 (bank assigned count)
    mov.b @(10, r11), r0                ! r0 = descriptor[10] (bank0 select)
    mov r0, r3                          ! r3 = bank0 select
    extu.b r3, r3                       ! zero-extend
    cmp/ge r2, r3                       ! bank0 >= 4?
    bt/s    .L_bank0_ge4                ! yes -> special bank0 path
    extu.b r5, r8                       ! (delay) r8 = 0 (fallback bank id)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov.l   .L_mask_clear_bank0, r3     ! r3 = 0x0000FFFC (clear bits 0-1)
    mov r0, r2                          ! r2 = disp_ctrl
    extu.w r2, r2                       ! zero-extend word
    mov.b @(10, r11), r0                ! r0 = bank0 select value
    and r3, r2                          ! clear bank0 field (bits 0-1)
    mov r0, r1                          ! r1 = bank0 select
    extu.b r1, r1                       ! zero-extend
    or r1, r2                           ! insert bank0 value into bits 0-1
    extu.w r2, r2                       ! zero-extend word
    mov r2, r0                          ! r0 = new disp_ctrl
    mov.w r0, @(14, r12)                ! write back disp_ctrl with bank0
    mov.b @(10, r11), r0                ! r0 = bank0 select (re-read)
    extu.b r0, r0                       ! zero-extend
    cmp/eq #0x1, r0                     ! bank0 == 1? (primary VRAM)
    bf      .L_after_bank0              ! no -> skip bank0 addr setup
    mov.l @r14, r0                      ! r0 = vram_base_in[0] (primary base)
    tst r0, r0                          ! primary base == 0?
    bt      .L_bank0_base_zero          ! yes -> mark fallback
    mov.l   .L_mask_clear_bank0, r3     ! r3 = 0x0000FFFC (clear bits 0-1)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r2                          ! r2 = disp_ctrl
    and r3, r2                          ! clear bank0 field (revert)
    mov r2, r0                          ! r0 = cleared
    bra     .L_bank0_after_base         ! -> continue
    mov.w r0, @(14, r12)                ! (delay) write back cleared ctrl
.L_bank0_base_zero:
    mov #0x1, r8                        ! r8 = 1 (fallback: bank0 needs resolve)
.L_bank0_after_base:
    mov.w @(6, r13), r0                 ! r0 = scene_flags[6] (char pattern reg)
    mov r0, r2                          ! r2 = char pattern reg
    and r9, r2                          ! keep only byte 1 (mask 0xFF00)
    mov r2, r0                          ! r0 = masked
    mov.w r0, @(6, r13)                 ! clear low byte of char pattern
    mov.l @r14, r3                      ! r3 = primary VRAM base
    mov.l   .L_vdp2_vram_0x00000, r2    ! r2 = 0x25E00000 (VDP2 VRAM base)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @r10                      ! vram_addr_out[0] = primary addr
    bra     .L_after_bank0              ! -> done with bank0
    mov #0x1, r4                        ! (delay) r4 = 1 (bank assigned)
.L_bank0_ge4:
    mov.b @(10, r11), r0                ! r0 = bank0 select (re-read)
    extu.b r0, r0                       ! zero-extend
    cmp/eq #0x4, r0                     ! bank0 == 4? (secondary VRAM)
    bf      .L_after_bank0              ! no -> skip
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    and #0xFF, r0                       ! clear high byte, keep low
    mov.w r0, @(6, r13)                 ! write back
    mov.l @(4, r14), r3                 ! r3 = secondary VRAM base
    mov.l   .L_vdp2_vram_0x00000, r2    ! r2 = 0x25E00000 (VDP2 VRAM base)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @(4, r10)                 ! vram_addr_out[4] = secondary addr
.L_after_bank0:
    mov.b @(11, r11), r0                ! r0 = descriptor[11] (bank1 select)
    mov #0x4, r2                        ! r2 = 4 (threshold)
    mov r0, r3                          ! r3 = bank1 select
    extu.b r3, r3                       ! zero-extend
    cmp/ge r2, r3                       ! bank1 >= 4?
    bt      .L_bank1_ge4                ! yes -> special bank1 path
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov.l   .L_mask_clear_bank1, r3     ! r3 = 0x0000FFF3 (clear bits 2-3)
    mov r0, r2                          ! r2 = disp_ctrl
    extu.w r2, r2                       ! zero-extend word
    mov.b @(11, r11), r0                ! r0 = bank1 select
    and r3, r2                          ! clear bank1 field (bits 2-3)
    mov r0, r1                          ! r1 = bank1 select
    extu.b r1, r1                       ! zero-extend
    shll2 r1                            ! shift left 2 (into bits 2-3)
    extu.w r1, r1                       ! zero-extend word
    or r1, r2                           ! insert bank1 value
    extu.w r2, r2                       ! zero-extend word
    mov r2, r0                          ! r0 = new disp_ctrl
    mov.w r0, @(14, r12)                ! write back disp_ctrl with bank1
    mov.b @(11, r11), r0                ! r0 = bank1 select (re-read)
    extu.b r0, r0                       ! zero-extend
    cmp/eq #0x1, r0                     ! bank1 == 1? (primary VRAM)
    bf      .L_after_bank1              ! no -> skip bank1 addr setup
    extu.b r4, r2                       ! r2 = bank assigned count
    tst r2, r2                          ! any bank already assigned?
    bf      .L_bank1_secondary          ! yes -> use secondary path
    mov.l @r14, r0                      ! r0 = primary VRAM base
    tst r0, r0                          ! primary base == 0?
    bt      .L_bank1_base_zero          ! yes -> mark fallback
    mov.l   .L_mask_clear_bank1, r3     ! r3 = 0x0000FFF3 (clear bits 2-3)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r2                          ! r2 = disp_ctrl
    and r3, r2                          ! clear bank1 field (revert)
    mov r2, r0                          ! r0 = cleared
    bra     .L_bank1_after_base         ! -> continue
    mov.w r0, @(14, r12)                ! (delay) write back cleared ctrl
.L_bank1_base_zero:
    mov #0x2, r8                        ! r8 = 2 (fallback: bank1 needs resolve)
.L_bank1_after_base:
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r0, r2                          ! r2 = char pattern reg
    and r9, r2                          ! keep only byte 1 (mask 0xFF00)
    mov r2, r0                          ! r0 = masked
    mov.w r0, @(6, r13)                 ! clear low byte
    mov.w @(6, r13), r0                 ! r0 = char pattern reg (re-read)
    or #0x1, r0                         ! set bit 0 (bank1 = VRAM +0x20000)
    mov.w r0, @(6, r13)                 ! write back
    mov.l @r14, r3                      ! r3 = primary VRAM base
    mov.l   .L_vdp2_vram_0x20000, r2    ! r2 = 0x25E20000 (VRAM +0x20000)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @r10                      ! vram_addr_out[0] = primary addr
    bra     .L_bank1_done               ! -> done with bank1 primary
    mov #0x1, r4                        ! (delay) r4 = 1 (bank assigned)
.L_bank1_secondary:
    mov.l @(4, r14), r0                 ! r0 = secondary VRAM base
    tst r0, r0                          ! secondary base == 0?
    bt      .L_bank1_sec_base_ok        ! yes -> skip clear
    mov.l   .L_mask_clear_bank1, r3     ! r3 = 0x0000FFF3 (clear bits 2-3)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r2                          ! r2 = disp_ctrl
    and r3, r2                          ! clear bank1 field
    mov r2, r0                          ! r0 = cleared
    mov.w r0, @(14, r12)                ! write back cleared ctrl
.L_bank1_sec_base_ok:
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    and #0xFF, r0                       ! clear high byte
    mov.w r0, @(6, r13)                 ! write back
    mov.w   DAT_0603728e, r3            ! r3 = 0x0100 (high byte = 1)
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r0, r2                          ! r2 = char pattern reg
    or r3, r2                           ! set high byte to 1
    mov r2, r0                          ! r0 = result
    mov.w r0, @(6, r13)                 ! write back char pattern
    mov.l @(4, r14), r3                 ! r3 = secondary VRAM base
    mov.l   .L_vdp2_vram_0x20000, r2    ! r2 = 0x25E20000 (VRAM +0x20000)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @(4, r10)                 ! vram_addr_out[4] = secondary addr
    add #0x1, r4                        ! r4++ (bank assigned count)
.L_bank1_done:
    bra     .L_after_bank1              ! -> done with bank1
    nop                                 ! (delay slot)

    .global DAT_0603728e
DAT_0603728e:
    .2byte  0x0100
.L_mask_clear_bit9:
    .4byte  0x0000FDFF
.L_mask_clear_bank0:
    .4byte  0x0000FFFC
.L_vdp2_vram_0x00000:
    .4byte  0x25E00000                  /* VDP2 VRAM +0x00000 */
.L_mask_clear_bank1:
    .4byte  0x0000FFF3
.L_vdp2_vram_0x20000:
    .4byte  0x25E20000                  /* VDP2 VRAM +0x20000 */
.L_bank1_ge4:
    mov.b @(11, r11), r0                ! r0 = bank1 select (re-read)
    extu.b r0, r0                       ! zero-extend
    cmp/eq #0x4, r0                     ! bank1 == 4? (secondary VRAM)
    bf      .L_after_bank1              ! no -> skip
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    and #0xFF, r0                       ! clear high byte
    mov.w r0, @(6, r13)                 ! write back
    mov.w   DAT_06037362, r3            ! r3 = 0x0100 (high byte = 1)
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r0, r2                          ! r2 = char pattern reg
    or r3, r2                           ! set high byte to 1
    mov r2, r0                          ! r0 = result
    mov.w r0, @(6, r13)                 ! write back char pattern
    mov.l @(4, r14), r3                 ! r3 = secondary VRAM base
    mov.l   .L_vdp2_vram_0x20000_b, r2  ! r2 = 0x25E20000 (VRAM +0x20000)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @(4, r10)                 ! vram_addr_out[4] = secondary addr
.L_after_bank1:
    mov #0x4, r2                        ! r2 = 4 (threshold)
    mov.b @(12, r11), r0                ! r0 = descriptor[12] (bank2 select)
    mov r0, r3                          ! r3 = bank2 select
    extu.b r3, r3                       ! zero-extend
    cmp/ge r2, r3                       ! bank2 >= 4?
    bt      .L_bank2_ge4                ! yes -> special bank2 path
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov.l   .L_mask_clear_bank2, r3     ! r3 = 0x0000FFCF (clear bits 4-5)
    mov r0, r2                          ! r2 = disp_ctrl
    extu.w r2, r2                       ! zero-extend word
    mov.b @(12, r11), r0                ! r0 = bank2 select
    and r3, r2                          ! clear bank2 field (bits 4-5)
    mov r0, r1                          ! r1 = bank2 select
    extu.b r1, r1                       ! zero-extend
    shll2 r1                            ! shift left 2
    shll2 r1                            ! shift left 2 (total <<4, into bits 4-5)
    extu.w r1, r1                       ! zero-extend word
    or r1, r2                           ! insert bank2 value
    extu.w r2, r2                       ! zero-extend word
    mov r2, r0                          ! r0 = new disp_ctrl
    mov.w r0, @(14, r12)                ! write back disp_ctrl with bank2
    mov.b @(12, r11), r0                ! r0 = bank2 select (re-read)
    extu.b r0, r0                       ! zero-extend
    cmp/eq #0x1, r0                     ! bank2 == 1? (primary VRAM)
    bf      .L_after_bank2              ! no -> skip bank2 addr setup
    extu.b r4, r2                       ! r2 = bank assigned count
    tst r2, r2                          ! any bank already assigned?
    bf      .L_bank2_secondary          ! yes -> use secondary path
    mov.l @r14, r0                      ! r0 = primary VRAM base
    tst r0, r0                          ! primary base == 0?
    bt      .L_bank2_base_zero          ! yes -> mark fallback
    mov.l   .L_mask_clear_bank2, r3     ! r3 = 0x0000FFCF (clear bits 4-5)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r2                          ! r2 = disp_ctrl
    and r3, r2                          ! clear bank2 field (revert)
    mov r2, r0                          ! r0 = cleared
    bra     .L_bank2_after_base         ! -> continue
    mov.w r0, @(14, r12)                ! (delay) write back cleared ctrl
.L_bank2_base_zero:
    mov #0x3, r8                        ! r8 = 3 (fallback: bank2 needs resolve)
.L_bank2_after_base:
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r0, r2                          ! r2 = char pattern reg
    and r9, r2                          ! keep only byte 1 (mask 0xFF00)
    mov r2, r0                          ! r0 = masked
    mov.w r0, @(6, r13)                 ! clear low byte
    mov.w @(6, r13), r0                 ! r0 = char pattern reg (re-read)
    or #0x2, r0                         ! set bit 1 (bank2 = VRAM +0x40000)
    mov.w r0, @(6, r13)                 ! write back
    mov.l @r14, r3                      ! r3 = primary VRAM base
    mov.l   .L_vdp2_vram_0x40000, r2    ! r2 = 0x25E40000 (VRAM +0x40000)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @r10                      ! vram_addr_out[0] = primary addr
    bra     .L_bank2_done               ! -> done with bank2 primary
    mov #0x1, r4                        ! (delay) r4 = 1 (bank assigned)
.L_bank2_secondary:
    mov.l @(4, r14), r0                 ! r0 = secondary VRAM base
    tst r0, r0                          ! secondary base == 0?
    bt      .L_bank2_sec_base_ok        ! yes -> skip clear
    mov.l   .L_mask_clear_bank2, r3     ! r3 = 0x0000FFCF (clear bits 4-5)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r2                          ! r2 = disp_ctrl
    and r3, r2                          ! clear bank2 field
    mov r2, r0                          ! r0 = cleared
    mov.w r0, @(14, r12)                ! write back cleared ctrl
.L_bank2_sec_base_ok:
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    and #0xFF, r0                       ! clear high byte
    mov.w r0, @(6, r13)                 ! write back
    mov.w   .L_bank2_byte_hi, r3        ! r3 = 0x0200 (high byte = 2)
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r0, r2                          ! r2 = char pattern reg
    or r3, r2                           ! set high byte to 2
    mov r2, r0                          ! r0 = result
    mov.w r0, @(6, r13)                 ! write back char pattern
    add #0x1, r4                        ! r4++ (bank assigned count)
    mov.l @(4, r14), r3                 ! r3 = secondary VRAM base
    mov.l   .L_vdp2_vram_0x40000, r2    ! r2 = 0x25E40000 (VRAM +0x40000)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @(4, r10)                 ! vram_addr_out[4] = secondary addr
.L_bank2_done:
    bra     .L_after_bank2              ! -> done with bank2
    nop                                 ! (delay slot)

    .global DAT_06037362
DAT_06037362:
    .2byte  0x0100
.L_bank2_byte_hi:
    .2byte  0x0200
    .2byte  0xFFFF
.L_vdp2_vram_0x20000_b:
    .4byte  0x25E20000                  /* VDP2 VRAM +0x20000 */
.L_mask_clear_bank2:
    .4byte  0x0000FFCF
.L_vdp2_vram_0x40000:
    .4byte  0x25E40000                  /* VDP2 VRAM +0x40000 */
.L_bank2_ge4:
    mov.b @(12, r11), r0                ! r0 = bank2 select (re-read)
    extu.b r0, r0                       ! zero-extend
    cmp/eq #0x4, r0                     ! bank2 == 4? (secondary VRAM)
    bf      .L_after_bank2              ! no -> skip
    mov.l   .L_secondary_enable, r2     ! r2 = &secondary_enable flag
    mov.l @r2, r0                       ! r0 = secondary enable value
    tst r0, r0                          ! secondary enabled?
    bt      .L_after_bank2              ! no -> skip
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    and #0xFF, r0                       ! clear high byte
    mov.w r0, @(6, r13)                 ! write back
    mov.w   DAT_0603743a, r3            ! r3 = 0x0200 (high byte = 2)
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r0, r2                          ! r2 = char pattern reg
    or r3, r2                           ! set high byte to 2
    mov r2, r0                          ! r0 = result
    mov.w r0, @(6, r13)                 ! write back char pattern
    mov.l @(4, r14), r3                 ! r3 = secondary VRAM base
    mov.l   .L_vdp2_vram_0x40000_b, r2  ! r2 = 0x25E40000 (VRAM +0x40000)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @(4, r10)                 ! vram_addr_out[4] = secondary addr
.L_after_bank2:
    mov #0x4, r2                        ! r2 = 4 (threshold)
    mov.b @(13, r11), r0                ! r0 = descriptor[13] (bank3 select)
    mov r0, r3                          ! r3 = bank3 select
    extu.b r3, r3                       ! zero-extend
    cmp/ge r2, r3                       ! bank3 >= 4?
    bt      .L_bank3_ge4                ! yes -> special bank3 path
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov.l   .L_mask_clear_bank3, r3     ! r3 = 0x0000FF3F (clear bits 6-7)
    mov r0, r2                          ! r2 = disp_ctrl
    extu.w r2, r2                       ! zero-extend word
    mov.b @(13, r11), r0                ! r0 = bank3 select
    and r3, r2                          ! clear bank3 field (bits 6-7)
    mov r0, r1                          ! r1 = bank3 select
    extu.b r1, r1                       ! zero-extend
    shll2 r1                            ! shift left 2
    shll2 r1                            ! shift left 2
    shll2 r1                            ! shift left 2 (total <<6, into bits 6-7)
    extu.w r1, r1                       ! zero-extend word
    or r1, r2                           ! insert bank3 value
    extu.w r2, r2                       ! zero-extend word
    mov r2, r0                          ! r0 = new disp_ctrl
    mov.w r0, @(14, r12)                ! write back disp_ctrl with bank3
    mov.b @(13, r11), r0                ! r0 = bank3 select (re-read)
    extu.b r0, r0                       ! zero-extend
    cmp/eq #0x1, r0                     ! bank3 == 1? (primary VRAM)
    bf      .L_after_bank3              ! no -> skip bank3 addr setup
    extu.b r4, r4                       ! r4 = bank assigned count (zero-ext)
    tst r4, r4                          ! any bank already assigned?
    bf      .L_bank3_secondary          ! yes -> use secondary path
    mov.l @r14, r0                      ! r0 = primary VRAM base
    tst r0, r0                          ! primary base == 0?
    bt      .L_bank3_base_zero          ! yes -> mark fallback
    mov.l   .L_mask_clear_bank3, r3     ! r3 = 0x0000FF3F (clear bits 6-7)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r2                          ! r2 = disp_ctrl
    and r3, r2                          ! clear bank3 field (revert)
    mov r2, r0                          ! r0 = cleared
    bra     .L_bank3_after_base         ! -> continue
    mov.w r0, @(14, r12)                ! (delay) write back cleared ctrl
.L_bank3_base_zero:
    mov #0x4, r8                        ! r8 = 4 (fallback: bank3 needs resolve)
.L_bank3_after_base:
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r0, r2                          ! r2 = char pattern reg
    and r9, r2                          ! keep only byte 1 (mask 0xFF00)
    mov r2, r0                          ! r0 = masked
    mov.w r0, @(6, r13)                 ! clear low byte
    mov.w @(6, r13), r0                 ! r0 = char pattern reg (re-read)
    or #0x3, r0                         ! set bits 0-1 (bank3 = VRAM +0x60000)
    mov.w r0, @(6, r13)                 ! write back
    mov.l @r14, r3                      ! r3 = primary VRAM base
    mov.l   .L_vdp2_vram_0x60000, r2    ! r2 = 0x25E60000 (VRAM +0x60000)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @r10                      ! vram_addr_out[0] = primary addr
    bra     .L_bank3_done               ! -> done with bank3 primary
    nop                                 ! (delay slot)
.L_bank3_secondary:
    mov.l @(4, r14), r0                 ! r0 = secondary VRAM base
    tst r0, r0                          ! secondary base == 0?
    bt      .L_bank3_sec_base_ok        ! yes -> skip clear
    mov.l   .L_mask_clear_bank3, r3     ! r3 = 0x0000FF3F (clear bits 6-7)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r2                          ! r2 = disp_ctrl
    and r3, r2                          ! clear bank3 field
    mov r2, r0                          ! r0 = cleared
    mov.w r0, @(14, r12)                ! write back cleared ctrl
.L_bank3_sec_base_ok:
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    and #0xFF, r0                       ! clear high byte
    mov.w r0, @(6, r13)                 ! write back
    mov.w   .L_bank3_byte_hi, r3        ! r3 = 0x0300 (high byte = 3)
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r0, r2                          ! r2 = char pattern reg
    or r3, r2                           ! set high byte to 3
    mov r2, r0                          ! r0 = result
    mov.w r0, @(6, r13)                 ! write back char pattern
    mov.l @(4, r14), r3                 ! r3 = secondary VRAM base
    mov.l   .L_vdp2_vram_0x60000, r2    ! r2 = 0x25E60000 (VRAM +0x60000)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @(4, r10)                 ! vram_addr_out[4] = secondary addr
.L_bank3_done:
    bra     .L_after_bank3              ! -> done with bank3
    nop                                 ! (delay slot)

    .global DAT_0603743a
DAT_0603743a:
    .2byte  0x0200
.L_bank3_byte_hi:
    .2byte  0x0300
    .2byte  0xFFFF
.L_secondary_enable:
    .4byte  sym_060A4C50
.L_vdp2_vram_0x40000_b:
    .4byte  0x25E40000                  /* VDP2 VRAM +0x40000 */
.L_mask_clear_bank3:
    .4byte  0x0000FF3F
.L_vdp2_vram_0x60000:
    .4byte  0x25E60000                  /* VDP2 VRAM +0x60000 */
.L_bank3_ge4:
    mov.b @(13, r11), r0                ! r0 = bank3 select (re-read)
    extu.b r0, r0                       ! zero-extend
    cmp/eq #0x4, r0                     ! bank3 == 4? (secondary VRAM)
    bf      .L_after_bank3              ! no -> skip
    mov.l   .L_secondary_enable_b, r2   ! r2 = &secondary_enable flag
    mov.l @r2, r0                       ! r0 = secondary enable value
    tst r0, r0                          ! secondary enabled?
    bt      .L_after_bank3              ! no -> skip
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    and #0xFF, r0                       ! clear high byte
    mov.w r0, @(6, r13)                 ! write back
    mov.w   DAT_06037532, r3            ! r3 = 0x0300 (high byte = 3)
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r0, r2                          ! r2 = char pattern reg
    or r3, r2                           ! set high byte to 3
    mov r2, r0                          ! r0 = result
    mov.w r0, @(6, r13)                 ! write back char pattern
    mov.l @(4, r14), r3                 ! r3 = secondary VRAM base
    mov.l   .L_vdp2_vram_0x60000_b, r2  ! r2 = 0x25E60000 (VRAM +0x60000)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @(4, r10)                 ! vram_addr_out[4] = secondary addr
.L_after_bank3:
    mov.l @(4, r10), r0                 ! r0 = vram_addr_out[4] (secondary)
    tst r0, r0                          ! secondary addr assigned?
    bt      .L_no_secondary_addr        ! no -> try fallback
    bra     .L_epilogue                 ! yes -> done
    nop                                 ! (delay slot)
.L_no_secondary_addr:
    mov.b @(14, r11), r0                ! r0 = descriptor[14] (vis check flag)
    extu.b r0, r0                       ! zero-extend
    cmp/eq #0x1, r0                     ! vis check requested?
    bf      .L_after_vis_check          ! no -> skip
    mov.l   .L_vram_addr_out_b, r2      ! r2 = &vram_addr_out[0]
    mov.l @r2, r0                       ! r0 = primary addr output
    tst r0, r0                          ! primary addr already set?
    bf      .L_after_vis_check          ! yes -> skip (already configured)
    mov.l   .L_fn_visibility_check, r3  ! r3 = &visibility_check function
    jsr @r3                             ! call visibility_check()
    nop                                 ! (delay slot)
    cmp/eq #0x1, r0                     ! visible? (return == 1)
    bf      .L_after_vis_check          ! no -> skip
    mov.l   .L_fp_half, r3              ! r3 = 0x00008000 (bit 15 = enable)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r2                          ! r2 = disp_ctrl
    or r3, r2                           ! set bit 15 (display enable)
    mov r2, r0                          ! r0 = result
    mov.w r0, @(14, r12)                ! write back disp_ctrl
    mov.l   .L_vdp2_cram_0x800, r3      ! r3 = 0x25F00800 (color RAM +0x800)
    mov.l r3, @r10                      ! vram_addr_out[0] = color RAM addr
    bra     .L_epilogue                 ! -> done
    nop                                 ! (delay slot)
.L_after_vis_check:
    mov.l @r10, r0                      ! r0 = vram_addr_out[0] (primary)
    tst r0, r0                          ! primary addr assigned?
    bt      .L_both_addr_zero           ! no -> try active flag path
    mov.l   .L_secondary_active, r3     ! r3 = &secondary_active flag
    mov.b @r3, r3                       ! r3 = secondary active byte
    extu.b r3, r3                       ! zero-extend
    tst r3, r3                          ! secondary scene active?
    bt      .L_both_addr_zero           ! no -> try active flag path
    mov.l @(4, r14), r0                 ! r0 = secondary VRAM base
    tst r0, r0                          ! secondary base set?
    bf      .L_after_offset_calc        ! yes -> skip offset calc
    mov.l @r14, r3                      ! r3 = primary VRAM base
    mov.w   .L_vram_offset_0x400, r2    ! r2 = 0x0400 (default offset)
    add r2, r3                          ! r3 = primary + 0x400
    mov.l r3, @(4, r14)                 ! secondary base = primary + 0x400
.L_after_offset_calc:
    mov.l @r14, r0                      ! r0 = primary VRAM base
    tst r0, r0                          ! primary base == 0?
    bf      .L_ensure_base_nonzero      ! no -> proceed
    mov #-0x1, r3                       ! r3 = 0xFFFFFFFF (sentinel)
    mov.l r3, @r14                      ! primary base = -1 (force nonzero)
.L_ensure_base_nonzero:
    mov.l @(4, r14), r2                 ! r2 = secondary VRAM base
    mov.l @r10, r3                      ! r3 = primary VRAM addr output
    add r3, r2                          ! r2 = primary addr + secondary base
    mov.l r2, @(4, r10)                 ! vram_addr_out[4] = combined addr
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r0, r4                          ! r4 = char pattern reg
    extu.w r4, r4                       ! zero-extend word
    mov.w   DAT_06037536, r3            ! r3 = 0x00FF (low byte mask)
    and r4, r3                          ! r3 = low byte only
    mov r4, r2                          ! r2 = char pattern reg
    shll8 r2                            ! r2 <<= 8 (duplicate low to high)
    or r2, r3                           ! r3 = low | (low << 8)
    extu.w r3, r0                       ! zero-extend word
    mov.w r0, @(6, r13)                 ! write back mirrored pattern
    bra     .L_dispatch_switch          ! -> dispatch on fallback bank id
    extu.b r8, r0                       ! (delay) r0 = fallback bank id
.L_dispatch_bank0:
    mov.l   .L_mask_clear_bank0_b, r2   ! r2 = 0x0000FFFC (clear bits 0-1)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r3                          ! r3 = disp_ctrl
    and r2, r3                          ! clear bank0 field
    mov r3, r0                          ! r0 = result
    bra     .L_dispatch_writeback       ! -> write back and return
    nop                                 ! (delay slot)
.L_dispatch_bank1:
    mov.l   .L_mask_clear_bank1_b, r2   ! r2 = 0x0000FFF3 (clear bits 2-3)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r3                          ! r3 = disp_ctrl
    and r2, r3                          ! clear bank1 field
    mov r3, r0                          ! r0 = result
    bra     .L_dispatch_writeback       ! -> write back and return
    nop                                 ! (delay slot)
.L_dispatch_bank2:
    mov.l   .L_mask_clear_bank2_b, r2   ! r2 = 0x0000FFCF (clear bits 4-5)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r3                          ! r3 = disp_ctrl
    and r2, r3                          ! clear bank2 field
    mov r3, r0                          ! r0 = result
    bra     .L_dispatch_writeback       ! -> write back and return
    nop                                 ! (delay slot)
.L_dispatch_bank3:
    mov.l   .L_mask_clear_bank3_b, r2   ! r2 = 0x0000FF3F (clear bits 6-7)
    mov.w @(14, r12), r0                ! r0 = disp_ctrl
    mov r0, r3                          ! r3 = disp_ctrl
    and r2, r3                          ! clear bank3 field
    mov r3, r0                          ! r0 = result
.L_dispatch_writeback:
    bra     .L_epilogue                 ! -> return
    mov.w r0, @(14, r12)                ! (delay) write back disp_ctrl

    .global DAT_06037532
DAT_06037532:
    .2byte  0x0300
.L_vram_offset_0x400:
    .2byte  0x0400

    .global DAT_06037536
DAT_06037536:
    .2byte  0x00FF
.L_secondary_enable_b:
    .4byte  sym_060A4C50
.L_vdp2_vram_0x60000_b:
    .4byte  0x25E60000                  /* VDP2 VRAM +0x60000 */
.L_vram_addr_out_b:
    .4byte  sym_060A4C44
.L_fn_visibility_check:
    .4byte  sym_0603C156
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_vdp2_cram_0x800:
    .4byte  0x25F00800                  /* VDP2 color RAM +0x800 */
.L_secondary_active:
    .4byte  sym_060A4C59
.L_mask_clear_bank0_b:
    .4byte  0x0000FFFC
.L_mask_clear_bank1_b:
    .4byte  0x0000FFF3
.L_mask_clear_bank2_b:
    .4byte  0x0000FFCF
.L_mask_clear_bank3_b:
    .4byte  0x0000FF3F
.L_dispatch_switch:
    cmp/eq #0x1, r0                     ! fallback bank == 1?
    bt      .L_dispatch_bank0           ! yes -> clear bank0 bits
    cmp/eq #0x2, r0                     ! fallback bank == 2?
    bt      .L_dispatch_bank1           ! yes -> clear bank1 bits
    cmp/eq #0x3, r0                     ! fallback bank == 3?
    bt      .L_dispatch_bank2           ! yes -> clear bank2 bits
    cmp/eq #0x4, r0                     ! fallback bank == 4?
    bt      .L_dispatch_bank3           ! yes -> clear bank3 bits
    bra     .L_epilogue                 ! no match -> return
    nop                                 ! (delay slot)
.L_both_addr_zero:
    mov.l @r10, r0                      ! r0 = vram_addr_out[0] (primary)
    tst r0, r0                          ! primary addr assigned?
    bf      .L_epilogue                 ! yes -> done
    mov.l @r14, r0                      ! r0 = primary VRAM base
    tst r0, r0                          ! primary base exists?
    bt      .L_after_primary_path       ! no -> skip primary setup
    mov.l   .L_primary_active, r3       ! r3 = &primary_active flag
    mov.b @r3, r3                       ! r3 = primary active byte
    extu.b r3, r3                       ! zero-extend
    tst r3, r3                          ! primary scene active?
    bt      .L_after_primary_path       ! no -> skip primary setup
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r14, r4                         ! r4 = &vram_base_in[0] (arg ptr)
    mov r0, r3                          ! r3 = char pattern reg
    and r9, r3                          ! keep only byte 1 (mask 0xFF00)
    mov r3, r0                          ! r0 = masked
    mov.w r0, @(6, r13)                 ! clear low byte of char pattern
    mov.l   .L_fp_two, r0              ! r0 = 0x00020000 (2.0 fixed-point)
    mov.l   .L_fn_bank_select, r3       ! r3 = &bank_select function
    jsr @r3                             ! call bank_select(r0=2.0, r1=base)
    mov.l @r4, r1                       ! (delay) r1 = primary VRAM base
    extu.w r0, r0                       ! r0 = result (bank index, word)
    mov #0x6, r2                        ! r2 = offset 6
    add r13, r2                         ! r2 = &scene_flags[6]
    mov.w @r2, r2                       ! r2 = char pattern reg
    or r0, r2                           ! merge bank select result
    mov r2, r0                          ! r0 = merged
    mov.w r0, @(6, r13)                 ! write back char pattern
    mov.l @r4, r3                       ! r3 = primary VRAM base
    mov.l   .L_vdp2_vram_0x00000_b, r2  ! r2 = 0x25E00000 (VDP2 VRAM base)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @r10                      ! vram_addr_out[0] = primary addr
.L_after_primary_path:
    mov.l @(4, r14), r0                 ! r0 = secondary VRAM base
    tst r0, r0                          ! secondary base exists?
    bt      .L_epilogue                 ! no -> done
    mov.l   .L_secondary_active_b, r3   ! r3 = &secondary_active flag
    mov.b @r3, r3                       ! r3 = secondary active byte
    extu.b r3, r3                       ! zero-extend
    tst r3, r3                          ! secondary scene active?
    bt      .L_epilogue                 ! no -> done
    mov.w @(6, r13), r0                 ! r0 = char pattern reg
    mov r14, r4                         ! r4 = &vram_base_in[0]
    and #0xFF, r0                       ! clear high byte
    add #0x4, r4                        ! r4 = &vram_base_in[4] (secondary)
    mov.w r0, @(6, r13)                 ! write back cleared high byte
    mov.l   .L_fp_two, r0              ! r0 = 0x00020000 (2.0 fixed-point)
    mov.l   .L_fn_bank_select, r3       ! r3 = &bank_select function
    jsr @r3                             ! call bank_select(r0=2.0, r1=base)
    mov.l @r4, r1                       ! (delay) r1 = secondary VRAM base
    extu.w r0, r0                       ! r0 = result (bank index, word)
    shll8 r0                            ! shift into high byte position
    mov #0x6, r2                        ! r2 = offset 6
    add r13, r2                         ! r2 = &scene_flags[6]
    mov.w @r2, r2                       ! r2 = char pattern reg
    or r0, r2                           ! merge bank select (high byte)
    mov r2, r0                          ! r0 = merged
    mov.w r0, @(6, r13)                 ! write back char pattern
    mov.l @r4, r3                       ! r3 = secondary VRAM base
    mov.l   .L_vdp2_vram_0x00000_b, r2  ! r2 = 0x25E00000 (VDP2 VRAM base)
    add r2, r3                          ! r3 = absolute VRAM address
    mov.l r3, @(4, r10)                 ! vram_addr_out[4] = secondary addr
.L_epilogue:
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r8                     ! restore r8
    mov.l @r15+, r9                     ! restore r9
    mov.l @r15+, r10                    ! restore r10
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return
    mov.l @r15+, r14                    ! (delay) restore r14
.L_primary_active:
    .4byte  sym_060A4C58
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_fn_bank_select:
    .4byte  sym_06034FFC
.L_vdp2_vram_0x00000_b:
    .4byte  0x25E00000                  /* VDP2 VRAM +0x00000 */
.L_secondary_active_b:
    .4byte  sym_060A4C59

    .global sym_06037618
sym_06037618:                           ! VDP command struct zero-init (r4 = struct ptr)
    mov #0x10, r7                       ! r7 = 16 (loop count for longword array)
    mov #0x0, r5                        ! r5 = 0 (zero fill value)
    mov.b r5, @r4                       ! struct[0] = 0
    extu.b r5, r2                       ! r2 = 0
    mov r2, r0                          ! r0 = 0
    mov.b r0, @(1, r4)                  ! struct[1] = 0
    extu.b r5, r0                       ! r0 = 0
    mov.b r0, @(2, r4)                  ! struct[2] = 0
    extu.b r5, r0                       ! r0 = 0
    mov.b r0, @(3, r4)                  ! struct[3] = 0
    extu.b r5, r0                       ! r0 = 0
    mov.b r0, @(4, r4)                  ! struct[4] = 0
    extu.b r5, r0                       ! r0 = 0
    mov.b r0, @(5, r4)                  ! struct[5] = 0
    extu.b r5, r0                       ! r0 = 0
    mov.b r0, @(6, r4)                  ! struct[6] = 0
    extu.b r5, r0                       ! r0 = 0
    mov.b r0, @(8, r4)                  ! struct[8] = 0
    extu.b r5, r0                       ! r0 = 0
    mov.b r0, @(7, r4)                  ! struct[7] = 0
    extu.w r5, r3                       ! r3 = 0 (word)
    mov r3, r0                          ! r0 = 0
    mov.w r0, @(10, r4)                 ! struct[10..11] = 0 (word)
    extu.b r5, r6                       ! r6 = 0 (loop index)
.L_zero_loop:
    extu.b r6, r3                       ! r3 = loop index
    mov r4, r2                          ! r2 = struct base
    shll2 r3                            ! r3 = index * 4
    add #0x1, r6                        ! r6++ (increment index)
    add #0xC, r2                        ! r2 = struct + 12 (longword array base)
    add r2, r3                          ! r3 = &struct[12 + index*4]
    mov.l r5, @r3                       ! struct[12 + index*4] = 0
    extu.b r6, r3                       ! r3 = next index
    cmp/ge r7, r3                       ! index >= 16?
    bf      .L_zero_loop                ! no -> loop
    rts                                 ! return
    nop                                 ! (delay slot)
