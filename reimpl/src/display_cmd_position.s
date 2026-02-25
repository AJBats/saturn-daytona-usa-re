/* display_cmd_position -- Display command handlers for position/scroll flags
 *
 * Handles display commands 8-12 from the display dispatch table (sym_06032334).
 * Each sub-handler manipulates flag bits in the display flags byte (sym_06082A25)
 * or resets display state, then branches back to the display dispatch return
 * path at 0x0603230A.
 *
 * Commands:
 *   display_cmd_position (cmd entry) - dispatch sound_cmd_dispatch, return
 *   loc_0603243C (cmd 8)  - set scroll enable (bit 0), clear scroll position
 *   loc_0603245C (cmd 9)  - clear scroll enable (bit 0)
 *   loc_06032474 (cmd 10) - clear position lock (bit 1)
 *   loc_0603248C (cmd 11) - set position lock (bit 1)
 *   loc_060324A0 (cmd 12) - full display reset: clear car flag bit 16,
 *                           clear cmd state byte, set reset flag (bit 2)
 *
 * Translation unit: 0x0603242A - 0x060324EC
 */

    .section .text.FUN_0603242A


    .global display_cmd_position
    .type display_cmd_position, @function
display_cmd_position:
    sts.l pr, @-r15                         ! save return address to stack
    jsr @r0                                 ! call sound_cmd_dispatch (addr in r0 from caller)
    nop                                     ! delay slot
    lds.l @r15+, pr                         ! restore return address from stack
    .byte   0xAF, 0x6A    /* bra 0x0603230A (external) */
    nop                                     ! delay slot: return to display dispatch loop
    .2byte  0x0000                          ! alignment padding
    .4byte  sound_cmd_dispatch              ! pool: address of sound_cmd_dispatch

/*----------------------------------------------------------------------
 * cmd 8: set scroll enable — sets bit 0 of display flags byte,
 *        then clears scroll position (sym_06082A28) to zero.
 *----------------------------------------------------------------------*/
    .global loc_0603243C
loc_0603243C:
    .byte   0xD2, 0x04    /* mov.l _pool_scroll_enable_bit, r2 */
    .byte   0xD0, 0x05    /* mov.l _pool_disp_flags_a, r0 */
    mov.b @r0, r1                           ! r1 = current display flags byte
    or r2, r1                               ! r1 |= 0x01 — set scroll enable bit
    mov.b r1, @r0                           ! store updated flags
    xor r1, r1                              ! r1 = 0
    .byte   0xD0, 0x03    /* mov.l _pool_scroll_pos, r0 */
    .byte   0xAF, 0x5E    /* bra 0x0603230A (external) */
    mov.l r1, @r0                           ! delay slot: clear scroll position to 0
    .2byte  0x0000                          ! alignment padding
_pool_scroll_enable_bit:
    .4byte  0x00000001                      ! bit 0 mask — scroll enable
_pool_disp_flags_a:
    .4byte  sym_06082A25                    ! display flags byte
_pool_scroll_pos:
    .4byte  sym_06082A28                    ! scroll position (32-bit)

/*----------------------------------------------------------------------
 * cmd 9: clear scroll enable — clears bit 0 of display flags byte.
 *----------------------------------------------------------------------*/
    .global loc_0603245C
loc_0603245C:
    .byte   0xD2, 0x03    /* mov.l _pool_scroll_clear_bit, r2 */
    .byte   0xD0, 0x04    /* mov.l _pool_disp_flags_b, r0 */
    not r2, r2                              ! r2 = ~0x01 = 0xFFFFFFFE
    mov.b @r0, r1                           ! r1 = current display flags byte
    and r2, r1                              ! r1 &= ~0x01 — clear scroll enable bit
    .byte   0xAF, 0x50    /* bra 0x0603230A (external) */
    mov.b r1, @r0                           ! delay slot: store updated flags
    .2byte  0x0000                          ! alignment padding
_pool_scroll_clear_bit:
    .4byte  0x00000001                      ! bit 0 mask (inverted before AND)
_pool_disp_flags_b:
    .4byte  sym_06082A25                    ! display flags byte

/*----------------------------------------------------------------------
 * cmd 10: clear position lock — clears bit 1 of display flags byte.
 *----------------------------------------------------------------------*/
    .global loc_06032474
loc_06032474:
    .byte   0xD2, 0x03    /* mov.l _pool_poslock_clear_bit, r2 */
    .byte   0xD0, 0x04    /* mov.l _pool_disp_flags_c, r0 */
    not r2, r2                              ! r2 = ~0x02 = 0xFFFFFFFD
    mov.b @r0, r1                           ! r1 = current display flags byte
    and r2, r1                              ! r1 &= ~0x02 — clear position lock bit
    .byte   0xAF, 0x44    /* bra 0x0603230A (external) */
    mov.b r1, @r0                           ! delay slot: store updated flags
    .2byte  0x0000                          ! alignment padding
_pool_poslock_clear_bit:
    .4byte  0x00000002                      ! bit 1 mask (inverted before AND)
_pool_disp_flags_c:
    .4byte  sym_06082A25                    ! display flags byte

/*----------------------------------------------------------------------
 * cmd 11: set position lock — sets bit 1 of display flags byte.
 *----------------------------------------------------------------------*/
    .global loc_0603248C
loc_0603248C:
    .byte   0xD2, 0x02    /* mov.l _pool_poslock_set_bit, r2 */
    .byte   0xD0, 0x03    /* mov.l _pool_disp_flags_d, r0 */
    mov.b @r0, r1                           ! r1 = current display flags byte
    or r2, r1                               ! r1 |= 0x02 — set position lock bit
    .byte   0xAF, 0x39    /* bra 0x0603230A (external) */
    mov.b r1, @r0                           ! delay slot: store updated flags
_pool_poslock_set_bit:
    .4byte  0x00000002                      ! bit 1 mask — position lock
_pool_disp_flags_d:
    .4byte  sym_06082A25                    ! display flags byte

/*----------------------------------------------------------------------
 * cmd 12: full display reset — clears bit 16 from car state flags word,
 *         clears cmd state byte, sets bit 2 (reset flag) in display flags.
 *----------------------------------------------------------------------*/
    .global loc_060324A0
loc_060324A0:
    .byte   0xD0, 0x07    /* mov.l _pool_car_base_ptr, r0 */
    mov.l @r0, r0                           ! r0 = car array base address (deref pointer)
    mov.l @r0, r1                           ! r1 = car state flags word [0]
    .byte   0xD2, 0x07    /* mov.l _pool_car_flag_mask, r2 */
    and r2, r1                              ! r1 &= 0xFFFEFFFF — clear bit 16 (display active)
    mov.l r1, @r0                           ! write back car state flags
    .byte   0xD0, 0x06    /* mov.l _pool_cmd_state_byte, r0 */
    xor r1, r1                              ! r1 = 0
    mov.b r1, @r0                           ! clear display cmd state byte to 0
    .byte   0xD0, 0x06    /* mov.l _pool_disp_flags_e, r0 */
    mov.b @r0, r1                           ! r1 = current display flags byte
    .byte   0xD2, 0x06    /* mov.l _pool_reset_flag_bit, r2 */
    or r2, r1                               ! r1 |= 0x04 — set reset flag (bit 2)
    .byte   0xAF, 0x26    /* bra 0x0603230A (external) */
    mov.b r1, @r0                           ! delay slot: store updated flags
    .2byte  0x0000                          ! alignment padding
_pool_car_base_ptr:
    .4byte  sym_0607E944                    ! car array base pointer
_pool_car_flag_mask:
    .4byte  0xFFFEFFFF                      ! mask: clears bit 16 (display active flag)
_pool_cmd_state_byte:
    .4byte  sym_06082A24                    ! display cmd state byte
_pool_disp_flags_e:
    .4byte  sym_06082A25                    ! display flags byte
_pool_reset_flag_bit:
    .4byte  0x00000004                      ! bit 2 mask — reset flag
    .4byte  0xD00401EC                      ! (unreachable code / next TU data)
    .4byte  0x21188919
    .4byte  0xE0042108
    .4byte  0x8B04A021
    .4byte  0x00090000
    .4byte  0x000002DC
