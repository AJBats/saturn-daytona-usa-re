/* display_dispatch_pop -- Display dispatch epilogue + command handlers
 *
 * This TU contains:
 *   1. display_dispatch_pop — epilogue for the display command dispatcher.
 *      Calls check_cmd_state to optionally increment the display command
 *      counter, then restores callee-saved registers r8-r14 and returns.
 *
 *   2. check_cmd_state (internal) — reads the display cmd state byte
 *      (sym_06082A24). If nonzero (commands active), increments the
 *      display command counter (sym_06082A20).
 *
 *   3. sym_06032334 — the display command dispatch table (13 entries).
 *      Indexed by command ID to jump to the appropriate handler.
 *
 *   4. loc_0603237C (cmd 3) — sets bit 1 (hscroll pending) in the display
 *      control word at r14+0x0E, clears bit 0 (vscroll pending), then
 *      falls through to shared return path.
 *
 *   5. loc_0603239C (cmd 0) — clears bit 1 (hscroll pending) in the
 *      display control word, then falls through to shared code that
 *      checks whether the current element index (r7) matches the stored
 *      value at r14+0x10 and conditionally updates r4.
 *
 * Translation unit: 0x060322B6 - 0x060323B2
 */

    .section .text.FUN_060322B6


/*----------------------------------------------------------------------
 * display_dispatch_pop — display dispatcher epilogue
 *
 * Called at the end of display command processing. Checks whether
 * the display command system is active (via check_cmd_state), then
 * restores all callee-saved registers (r8-r14) from the stack and
 * returns to the caller.
 *----------------------------------------------------------------------*/
    .global display_dispatch_pop
    .type display_dispatch_pop, @function
display_dispatch_pop:
    sts.l pr, @-r15                             ! push return address onto stack
    bsr     check_cmd_state                     ! call internal: check if cmd state active, bump counter
    nop                                         ! delay slot
    lds.l @r15+, pr                             ! pop return address from stack
    mov.l @r15+, r8                             ! restore r8 from stack
    mov.l @r15+, r9                             ! restore r9 from stack
    mov.l @r15+, r10                            ! restore r10 from stack
    mov.l @r15+, r11                            ! restore r11 from stack
    mov.l @r15+, r12                            ! restore r12 from stack
    mov.l @r15+, r13                            ! restore r13 from stack
    mov.l @r15+, r14                            ! restore r14 from stack
    rts                                         ! return to caller
    nop                                         ! delay slot
    .4byte  0x00000000                          ! padding / data (index 0)
    .4byte  0x00000001                          ! data constant 1
    .4byte  0x00000002                          ! data constant 2
    .4byte  0x00000003                          ! data constant 3
    .4byte  0x00000004                          ! data constant 4
    .4byte  0x00000005                          ! data constant 5

/*----------------------------------------------------------------------
 * check_cmd_state — conditionally increment display command counter
 *
 * Reads the cmd state byte (sym_06082A24). If it is nonzero (display
 * commands are active), increments the display command counter word
 * (sym_06082A20) by 1. If zero, returns immediately.
 *----------------------------------------------------------------------*/
check_cmd_state:
    .byte   0xD0, 0x04    /* mov.l _pool_cmd_state_byte, r0 */
    mov.b @r0, r1                               ! r1 = cmd state byte value
    tst r1, r1                                  ! test if cmd state is zero
    bt      .L_cmd_state_zero                   ! if zero, skip increment — no active commands
    .byte   0xD0, 0x03    /* mov.l _pool_cmd_counter, r0 */
    mov.l @r0, r1                               ! r1 = current command counter value
    add #0x1, r1                                ! r1 += 1
    mov.l r1, @r0                               ! store incremented counter back
.L_cmd_state_zero:
    rts                                         ! return to caller
    nop                                         ! delay slot
_pool_cmd_state_byte:
    .4byte  sym_06082A24                        ! display cmd state byte
_pool_cmd_counter:
    .4byte  sym_06082A20                        ! display command counter (32-bit)
    .4byte  0xD0074408                          ! (following TU code — not part of this function)
    .4byte  0x0E4ED007
    .4byte  0x01EE6516
    .4byte  0x66166716
    .4byte  0xD0056202
    .4byte  0x35208B09
    .4byte  0xD002A023
    .4byte  0x0E160000
    .4byte  sym_060623B0
    .4byte  0x000002D8
    .4byte  sym_06082A20
    .4byte  0xA0D00009

/*----------------------------------------------------------------------
 * Display command dispatch table (sym_06032334)
 *
 * 13-entry jump table indexed by command ID (0-12). Each entry is a
 * pointer to the handler function for that display command:
 *
 *   [0]  loc_0603239C  — cmd 0: clear hscroll pending bit
 *   [1]  loc_060323CC  — cmd 1: set hscroll pending bit (in display_cmd_hscroll)
 *   [2]  display_cmd_vscroll — cmd 2: vertical scroll dispatch
 *   [3]  loc_0603237C  — cmd 3: set hscroll pending, clear vscroll pending
 *   [4]  loc_060323F0  — cmd 4: write byte to display buffer
 *   [5]  loc_06032404  — cmd 5: OR bits into display control word
 *   [6]  loc_06032414  — cmd 6: AND-NOT bits from display control word
 *   [7]  loc_06032424  — cmd 7: call with args r4=0, r5=r7
 *   [8]  loc_0603243C  — cmd 8: set scroll enable
 *   [9]  loc_0603245C  — cmd 9: clear scroll enable
 *   [10] loc_06032474  — cmd 10: clear position lock
 *   [11] loc_0603248C  — cmd 11: set position lock
 *   [12] loc_060324A0  — cmd 12: full display reset
 *----------------------------------------------------------------------*/
    .global sym_06032334
sym_06032334:
    .4byte  loc_0603239C
    .4byte  loc_060323CC
    .4byte  display_cmd_vscroll
    .4byte  loc_0603237C
    .4byte  loc_060323F0
    .4byte  loc_06032404
    .4byte  loc_06032414
    .4byte  loc_06032424
    .4byte  loc_0603243C
    .4byte  loc_0603245C
    .4byte  loc_06032474
    .4byte  loc_0603248C
    .4byte  loc_060324A0
    .4byte  0x6163D002                          ! (following TU code — dispatch trampoline bytes)
    .4byte  0x4108001E
    .4byte  0x402B0009
    .4byte  sym_06032334
    .4byte  0xAFC70009

/*----------------------------------------------------------------------
 * cmd 3: set hscroll pending, clear vscroll pending
 *
 * Sets bit 1 (0x02 = hscroll pending) in the display control word at
 * r14+0x0E, then clears bit 0 (0x01 = vscroll pending) from the same
 * word. Falls through to the shared return path at .L_check_element_idx.
 *----------------------------------------------------------------------*/
    .global loc_0603237C
loc_0603237C:
    .byte   0xD0, 0x04    /* mov.l _pool_ctrl_word_offset_a, r0 */
    mov.w @(r0, r14), r1                        ! r1 = display control word at r14+0x0E
    .byte   0xD2, 0x04    /* mov.l _pool_hscroll_set_bit, r2 */
    or r2, r1                                   ! r1 |= 0x02 — set hscroll pending (bit 1)
    .byte   0xD2, 0x04    /* mov.l _pool_vscroll_clear_bit, r2 */
    not r2, r2                                  ! r2 = ~0x01 = 0xFFFFFFFE
    and r2, r1                                  ! r1 &= ~0x01 — clear vscroll pending (bit 0)
    mov.w r1, @(r0, r14)                        ! store updated display control word
    bra     .L_check_element_idx                ! jump to shared return path
    nop                                         ! delay slot
_pool_ctrl_word_offset_a:
    .4byte  0x0000000E                          ! offset to display control word in context (r14)
_pool_hscroll_set_bit:
    .4byte  0x00000002                          ! bit 1 mask — hscroll pending
_pool_vscroll_clear_bit:
    .4byte  0x00000001                          ! bit 0 mask (inverted before AND) — vscroll pending

/*----------------------------------------------------------------------
 * cmd 0: clear hscroll pending
 *
 * Clears bit 1 (0x02 = hscroll pending) from the display control word
 * at r14+0x0E, then falls through to check_element_idx which compares
 * r7 against the stored element index at r14+0x10.
 *----------------------------------------------------------------------*/
    .global loc_0603239C
loc_0603239C:
    .byte   0xD0, 0x08    /* mov.l _pool_ctrl_word_offset_b, r0 */
    mov.w @(r0, r14), r1                        ! r1 = display control word at r14+0x0E
    .byte   0xD2, 0x08    /* mov.l _pool_hscroll_clear_bit, r2 */
    not r2, r2                                  ! r2 = ~0x02 = 0xFFFFFFFD
    and r2, r1                                  ! r1 &= ~0x02 — clear hscroll pending (bit 1)
    mov.w r1, @(r0, r14)                        ! store updated display control word

/*----------------------------------------------------------------------
 * Shared return path: check whether r7 matches the stored element
 * index at r14+0x10 (the current display element). If they differ,
 * copy r7 into r4 (for the next stage). Either way, continues to
 * the external dispatch return at 0x060323BA.
 *----------------------------------------------------------------------*/
.L_check_element_idx:
    .byte   0xD0, 0x07    /* mov.l _pool_element_idx_offset, r0 */
    mov.l @(r0, r14), r2                        ! r2 = stored element index at r14+0x10
    cmp/eq r7, r2                               ! compare r7 (current) against stored index
    .byte   0x89, 0x04    /* bt 0x060323BA (external) */
    mov r7, r4                                  ! r4 = r7 (pass current index to next stage)
