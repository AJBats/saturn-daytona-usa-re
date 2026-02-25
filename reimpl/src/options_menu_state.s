/* options_menu_state -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0603D7B0 - 0x0603D9EC
 *
 * Options menu display configuration -- maps option selection bitmask (r4) to
 * display channel config bits in the config word at sym_060A4D18+2.
 *
 * On entry, clears 7 config bits (bits 8, 0, 1, 2, 3, 4, 5) in the config
 * word via repeated calls to the bitfield read-modify-write utility
 * (sym_06034F78). If r4 == 0 (no options active), returns immediately.
 *
 * Otherwise, tests individual bits of r4 and sets corresponding config bits:
 *   r4 bit 2  (0x04)    -> set config bit 8 (0x0100) + bit 0 (0x0001)
 *   r4 bit 1  (0x02)    -> set config bit 0 (0x0001)
 *   r4 bit 3  (0x08)    -> set config bits 1+0 (0x0002 via r14)
 *   r4 bit 7  (0x80)    -> set config bits 1+0 (0x0002 via r14)
 *   r4 bit 4  (0x10)    -> set config bit 2 (0x0004)
 *   r4 bit 5  (0x20)    -> set config bit 3 (0x0008)
 *   r4 bit 0  (0x01)    -> set config bit 4 (0x0010)
 *   r4 bit 19 (0x80000) -> set config bit 5 (0x0020)
 *
 * Each bit-set operation calls sym_06034F78 (bitfield RMW) then reads back
 * the config word, applies a clear-mask, ORs the new bit, and writes it back.
 *
 * Args:
 *   r4 = option selection bitmask (which options are active)
 *
 * Persistent registers:
 *   r5  = sym_060A4D18 (config word array base; word at +2 is target)
 *   r7  = sym_060A4D58 (bitfield RMW target pointer)
 *   r6  = 1 (constant; value arg for bitfield RMW, also used as OR bit 0)
 *   r12 = 0x0000FFFE (clear-mask for bit 0)
 *   r13 = 0x0000FFFD (clear-mask for bit 1; r12 - 1)
 *   r14 = 2 (constant; used as OR bit 1)
 */

    .section .text.FUN_0603D7B0


    .global options_menu_state
    .type options_menu_state, @function
options_menu_state:
    mov.l r14, @-r15              ! save r14
    mov #0x1, r6                  ! r6 = 0x1 (persistent constant)
    mov.l r13, @-r15              ! save r13
    mov #0x2, r14                 ! r14 = 0x2 (persistent constant)
    mov r6, r0                    ! r0 = 0x1 (value arg for bitfield RMW)
    mov.l r12, @-r15              ! save r12
    sts.l pr, @-r15               ! save return address
    mov.l   .L_mask_bit0, r12     ! r12 = 0xFFFE (clear-mask for bit 0)
    mov.l   .L_cfg_target_ptr, r7 ! r7 -> sym_060A4D58 (bitfield target)
    mov.l   .L_cfg_word_base, r5  ! r5 -> sym_060A4D18 (config word array)
    mov.l   .L_fn_bitfield_rmw, r3 ! r3 -> bitfield RMW function
    mov r12, r13                  ! r13 = 0xFFFE
    mov r7, r2                    ! r2 = target ptr (arg for RMW)
    add #-0x1, r13                ! r13 = 0xFFFD (clear-mask for bit 1)
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov r6, r1                    ! r1 = 0x1 (delay slot: bit position arg)
    ! === Clear config bit 8 (0x0100) ===
    mov.w @(2, r5), r0            ! r0 = config word [+2]
    mov.l   .L_mask_bit8, r3     ! r3 = 0xFEFF (clear bit 8)
    mov r0, r2                    ! r2 = config word
    extu.w r2, r2                 ! zero-extend to 32-bit
    and r3, r2                    ! clear bit 8
    extu.w r2, r0                 ! zero-extend result
    mov.w r0, @(2, r5)           ! write back config word
    ! === Clear config bit 0 (0x0001) ===
    mov r7, r2                    ! r2 = target ptr
    mov r6, r0                    ! r0 = 0x1 (value)
    mov.l   .L_fn_bitfield_rmw, r3 ! r3 -> bitfield RMW
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov r6, r1                    ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    mov r0, r2
    extu.w r2, r2                 ! zero-extend
    and r12, r2                   ! AND 0xFFFE -- clear bit 0
    extu.w r2, r0
    mov r7, r2                    ! r2 = target ptr (setup for next call)
    mov.w r0, @(2, r5)           ! write back config word
    ! === Clear config bit 1 (0x0002) ===
    mov r6, r0                    ! r0 = 0x1 (value)
    mov.l   .L_fn_bitfield_rmw, r3 ! r3 -> bitfield RMW
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov r6, r1                    ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    mov r0, r2
    extu.w r2, r2                 ! zero-extend
    and r13, r2                   ! AND 0xFFFD -- clear bit 1
    extu.w r2, r0
    mov.w r0, @(2, r5)           ! write back config word
    ! === Clear config bit 2 (0x0004) ===
    mov r7, r2                    ! r2 = target ptr
    mov r6, r0                    ! r0 = 0x1
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov r6, r1                    ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    mov.l   .L_mask_bit2, r3     ! r3 = 0xFFFB (clear bit 2)
    mov r0, r2
    extu.w r2, r2
    and r3, r2                    ! clear bit 2
    extu.w r2, r0
    mov.w r0, @(2, r5)           ! write back
    ! === Clear config bit 3 (0x0008) ===
    mov r7, r2                    ! r2 = target ptr
    mov r6, r0                    ! r0 = 0x1
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov r6, r1                    ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    mov.l   .L_mask_bit3, r3     ! r3 = 0xFFF7 (clear bit 3)
    mov r0, r2
    extu.w r2, r2
    and r3, r2                    ! clear bit 3
    extu.w r2, r0
    mov.w r0, @(2, r5)           ! write back
    ! === Clear config bit 4 (0x0010) ===
    mov r7, r2                    ! r2 = target ptr
    mov r6, r0                    ! r0 = 0x1
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov r6, r1                    ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    mov.l   .L_mask_bit4, r3     ! r3 = 0xFFEF (clear bit 4)
    mov r0, r2
    extu.w r2, r2
    and r3, r2                    ! clear bit 4
    extu.w r2, r0
    mov.w r0, @(2, r5)           ! write back
    ! === Clear config bit 5 (0x0020) ===
    mov r7, r2                    ! r2 = target ptr
    mov r6, r0                    ! r0 = 0x1
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov r6, r1                    ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    mov.l   .L_mask_bit5, r3     ! r3 = 0xFFDF (clear bit 5)
    mov r0, r2
    extu.w r2, r2
    and r3, r2                    ! clear bit 5
    extu.w r2, r2                 ! zero-extend
    mov r2, r0
    mov.w r0, @(2, r5)           ! write back
    ! === Check if any options are active ===
    tst r4, r4                    ! test option bitmask
    bf      .L_options_active     ! if r4 != 0, jump to set bits
    bra     .L_epilogue           ! r4 == 0: no options active, return
    nop
.L_options_active:
    ! === Always set config bit 8 (0x0100) when any option active ===
    mov r6, r0                    ! r0 = 0x1 (value)
    mov r7, r2                    ! r2 = target ptr
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov #0x1, r1                  ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    mov.l   .L_mask_bit8, r3     ! r3 = 0xFEFF (clear bit 8)
    mov.w   .L_set_bit8, r1      ! r1 = 0x0100 (bit 8 value)
    mov r0, r2
    extu.w r2, r2                 ! zero-extend config word
    and r3, r2                    ! clear bit 8
    or r1, r2                     ! set bit 8 (OR 0x0100)
    mov #0x4, r3                  ! r3 = 0x4 (test mask for opt bit 2)
    extu.w r2, r2                 ! zero-extend
    and r4, r3                    ! r3 = r4 & 0x4 -- test opt bit 2
    mov r2, r0
    mov.w r0, @(2, r5)           ! write back config word with bit 8
    ! === Test r4 bit 2 (0x04) -> set config bit 0 (0x0001) ===
    tst r3, r3                    ! test opt bit 2
    bt      .L_check_opt_bit1    ! bit 2 clear -> skip
    mov r6, r0                    ! r0 = 0x1 (value)
    mov r7, r2                    ! r2 = target ptr
    mov.l   .L_fn_bitfield_rmw, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov #0x1, r1                  ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    mov r0, r2
    extu.w r2, r2
    and r12, r2                   ! AND 0xFFFE -- clear bit 0
    or r6, r2                     ! OR 0x1 -- set bit 0
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r5)           ! write back with bit 0 set
.L_check_opt_bit1:
    ! === Test r4 bit 1 (0x02) -> set config bit 0 (0x0001) ===
    mov r4, r3                    ! r3 = option bitmask
    and r14, r3                   ! r3 = r4 & 0x2 -- test opt bit 1
    tst r3, r3
    bt      .L_check_opt_bit3    ! bit 1 clear -> skip
    mov r6, r0                    ! r0 = 0x1 (value)
    mov r7, r2                    ! r2 = target ptr
    bra     .L_set_cfg_bit0      ! branch to shared set-bit-0 code
    mov #0x1, r1                  ! r1 = 0x1 (delay slot)
.L_set_bit8:
    .2byte  0x0100                          /* bit 8 value (0x0100) */
    .2byte  0xFFFF                          /* padding */
.L_mask_bit0:
    .4byte  0x0000FFFE                      /* clear-mask for bit 0 */
.L_cfg_target_ptr:
    .4byte  sym_060A4D58                    /* bitfield RMW target ptr */
.L_cfg_word_base:
    .4byte  sym_060A4D18                    /* config word array base */
.L_fn_bitfield_rmw:
    .4byte  sym_06034F78                    /* bitfield RMW function */
.L_mask_bit8:
    .4byte  0x0000FEFF                      /* clear-mask for bit 8 */
.L_mask_bit2:
    .4byte  0x0000FFFB                      /* clear-mask for bit 2 */
.L_mask_bit3:
    .4byte  0x0000FFF7                      /* clear-mask for bit 3 */
.L_mask_bit4:
    .4byte  0x0000FFEF                      /* clear-mask for bit 4 */
.L_mask_bit5:
    .4byte  0x0000FFDF                      /* clear-mask for bit 5 */
.L_set_cfg_bit0:
    ! === Shared: call bitfield RMW then set config bit 0 ===
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    nop
    mov.w @(2, r5), r0            ! r0 = config word
    mov r0, r2
    extu.w r2, r2
    and r12, r2                   ! AND 0xFFFE -- clear bit 0
    or r6, r2                     ! OR 0x1 -- set bit 0
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r5)           ! write back with bit 0 set
.L_check_opt_bit3:
    ! === Test r4 bit 3 (0x08) -> set config bits 1+0 (0x0003) ===
    mov #0x8, r3                  ! r3 = 0x8 (test mask for opt bit 3)
    and r4, r3                    ! r3 = r4 & 0x8
    tst r3, r3
    bt      .L_check_opt_bit7    ! bit 3 clear -> skip
    mov r6, r0                    ! r0 = 0x1 (value)
    mov r7, r2                    ! r2 = target ptr
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov #0x1, r1                  ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    mov r0, r2
    extu.w r2, r2
    and r13, r2                   ! AND 0xFFFD -- clear bit 1
    or r14, r2                    ! OR 0x2 -- set bit 1
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r5)           ! write back with bit 1 set
.L_check_opt_bit7:
    ! === Test r4 bit 7 (0x80) -> set config bits 1+0 (0x0003) ===
    mov.w   .L_test_bit7, r3     ! r3 = 0x0080 (test mask for opt bit 7)
    and r4, r3                    ! r3 = r4 & 0x80
    tst r3, r3
    bt      .L_check_opt_bit4    ! bit 7 clear -> skip
    mov r6, r0                    ! r0 = 0x1 (value)
    mov r7, r2                    ! r2 = target ptr
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov #0x1, r1                  ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    mov r0, r2
    extu.w r2, r2
    and r13, r2                   ! AND 0xFFFD -- clear bit 1
    or r14, r2                    ! OR 0x2 -- set bit 1
    extu.w r2, r2
    mov r2, r0
    mov.w r0, @(2, r5)           ! write back with bit 1 set
.L_check_opt_bit4:
    ! === Test r4 bit 4 (0x10) -> set config bit 2 (0x0004) ===
    mov #0x10, r3                 ! r3 = 0x10 (test mask for opt bit 4)
    and r4, r3                    ! r3 = r4 & 0x10
    tst r3, r3
    bt      .L_check_opt_bit5    ! bit 4 clear -> skip
    mov r6, r0                    ! r0 = 0x1 (value)
    mov r7, r2                    ! r2 = target ptr
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov #0x1, r1                  ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    extu.w r0, r0                 ! zero-extend
    mov.l   .L_mask_bit2_b, r3   ! r3 = 0xFFFB (clear bit 2)
    and r3, r0                    ! clear bit 2
    or #0x4, r0                   ! OR 0x4 -- set bit 2
    extu.w r0, r0
    mov.w r0, @(2, r5)           ! write back with bit 2 set
.L_check_opt_bit5:
    ! === Test r4 bit 5 (0x20) -> set config bit 3 (0x0008) ===
    mov #0x20, r2                 ! r2 = 0x20 (test mask for opt bit 5)
    and r4, r2                    ! r2 = r4 & 0x20
    tst r2, r2
    bt      .L_check_opt_bit0    ! bit 5 clear -> skip
    mov r6, r0                    ! r0 = 0x1 (value)
    mov r7, r2                    ! r2 = target ptr
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov #0x1, r1                  ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    extu.w r0, r0                 ! zero-extend
    mov.l   .L_mask_bit3_b, r3   ! r3 = 0xFFF7 (clear bit 3)
    and r3, r0                    ! clear bit 3
    or #0x8, r0                   ! OR 0x8 -- set bit 3
    extu.w r0, r0
    mov.w r0, @(2, r5)           ! write back with bit 3 set
.L_check_opt_bit0:
    ! === Test r4 bit 0 (0x01) -> set config bit 4 (0x0010) ===
    mov r4, r2                    ! r2 = option bitmask
    and r6, r2                    ! r2 = r4 & 0x1 -- test opt bit 0
    tst r2, r2
    bt      .L_check_opt_bit19   ! bit 0 clear -> skip
    mov r6, r0                    ! r0 = 0x1 (value)
    mov r7, r2                    ! r2 = target ptr
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov #0x1, r1                  ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    extu.w r0, r0                 ! zero-extend
    mov.l   .L_mask_bit4_b, r3   ! r3 = 0xFFEF (clear bit 4)
    and r3, r0                    ! clear bit 4
    or #0x10, r0                  ! OR 0x10 -- set bit 4
    extu.w r0, r0
    mov.w r0, @(2, r5)           ! write back with bit 4 set
.L_check_opt_bit19:
    ! === Test r4 bit 19 (0x80000) -> set config bit 5 (0x0020) ===
    mov.l   .L_mask_bit19, r2    ! r2 = 0x00080000 (test mask for bit 19)
    and r2, r4                    ! r4 = r4 & 0x80000
    tst r4, r4
    bt      .L_epilogue           ! bit 19 clear -> return
    mov r6, r0                    ! r0 = 0x1 (value)
    mov r7, r2                    ! r2 = target ptr
    mov.l   .L_fn_bitfield_rmw_b, r3
    jsr @r3                       ! bitfield_rmw(val=1, pos=1, target)
    mov #0x1, r1                  ! r1 = 0x1 (delay slot)
    mov.w @(2, r5), r0            ! r0 = config word
    extu.w r0, r0                 ! zero-extend
    mov.l   .L_mask_bit5_b, r3   ! r3 = 0xFFDF (clear bit 5)
    and r3, r0                    ! clear bit 5
    or #0x20, r0                  ! OR 0x20 -- set bit 5
    extu.w r0, r0
    mov.w r0, @(2, r5)           ! write back with bit 5 set
.L_epilogue:
    lds.l @r15+, pr               ! restore return address
    mov.l @r15+, r12              ! restore r12
    mov.l @r15+, r13              ! restore r13
    rts                           ! return
    mov.l @r15+, r14              ! restore r14 (delay slot)
.L_test_bit7:
    .2byte  0x0080                          /* test mask for opt bit 7 */
    .2byte  0xFFFF                          /* padding */
.L_fn_bitfield_rmw_b:
    .4byte  sym_06034F78                    /* bitfield RMW function (2nd pool) */
.L_mask_bit2_b:
    .4byte  0x0000FFFB                      /* clear-mask for bit 2 (2nd pool) */
.L_mask_bit3_b:
    .4byte  0x0000FFF7                      /* clear-mask for bit 3 (2nd pool) */
.L_mask_bit4_b:
    .4byte  0x0000FFEF                      /* clear-mask for bit 4 (2nd pool) */
.L_mask_bit19:
    .4byte  0x00080000                      /* test mask for opt bit 19 (0x80000) */
.L_mask_bit5_b:
    .4byte  0x0000FFDF                      /* clear-mask for bit 5 (2nd pool) */
