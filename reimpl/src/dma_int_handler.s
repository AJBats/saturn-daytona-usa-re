/* dma_int_handler -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060416A8 - 0x06041826
 *
 * DMA interrupt state handler -- processes CD block transfer completion and
 * dispatches event callbacks from the AI/game state structure.
 *
 * Entry: dma_int_handler
 *   Called with callee-saved registers r9-r14 already pushed by the caller.
 *   Returns: r0 = 0 (no events processed), 1 (event triggered), 3 (state reset)
 *
 * Flow:
 *   1. Check pending transfer counter at state[+0x3C]. If non-zero, decrement.
 *      When it reaches zero, call sym_0604231E (AI state full reset) and return 3.
 *   2. Read CD block HIRQ status via sym_06035C4E.
 *   3. If CSCT bit (0x0400) is set -- CD sector transfer complete:
 *      a. Acknowledge interrupt via smpc_cmd_helper_b (mask 0xFBFF clears bit 10)
 *      b. Process section data via ai_checkpoint_section into stack locals
 *      c. Copy 12 bytes (3 longs) from stack+8 into state[+0x40] via memcpy_long
 *      d. If callback at state[+0x4C] is non-null, call it with arg from state[+0x50]
 *   4. If CSCT bit is NOT set:
 *      a. Call ai_section_transition. If it returns 0 (success),
 *         copy 12 bytes from stack+8 into state[+0x40] via memcpy_long
 *   5. Iterate event channels (r14 = 0..r11-1):
 *      For each channel, call the helper to resolve the callback pointer.
 *      If callback is null, invoke evt_callback_handler and accumulate result.
 *      If accumulated overflow count (r12) > 0 or stack[0] > r10, return 1.
 *   6. Return 0 if no events triggered.
 *
 * Internal helper (resolve_event_channel):
 *   Given channel index 0-7 in r4, returns r0=0 if callback exists, r0=1 if null.
 *   Maps index to struct field offset via switch/case:
 *     0->+0x58, 1->+0x0304, 2->+0x030C, 3->+0x0328,
 *     4->+0x0338, 5->+0x0348, 6->+0x01E0, 7->external offset
 *
 * Key symbols:
 *   sym_060A5400      -- AI/game state base pointer (indirect)
 *   sym_06035C4E      -- read CD block HIRQ status word
 *   sym_06035168      -- memcpy_long(r0=count, r1=dst, r2=src)
 *   sym_0604231E      -- AI state full reset (in validator_dispatch)
 *   smpc_cmd_helper_b -- acknowledge CD interrupt (write HIRQ)
 *   ai_checkpoint_section -- process input for section checkpoint
 *   ai_section_transition -- section transition handler
 *   evt_callback_handler  -- event callback dispatch (index in r4, buf in r5)
 */

    .section .text.FUN_060416A8


    .global dma_int_handler
    .type dma_int_handler, @function
dma_int_handler:
    sts.l pr, @-r15                      ! save return address
    mov #0x0, r9                         ! r9 = 0 (init accumulator)
    add #-0x14, r15                      ! allocate 0x14 bytes of locals
    mov.l   .L_state_base_ptr, r13       ! r13 = &state_base_ptr (persists across calls)
    mov.l r9, @r15                       ! stack[0] = 0 (event overflow counter)
    mov.l @r13, r3                       ! r3 = state base
    mov.l @(60, r3), r0                  ! r0 = state[+0x3C] (pending transfer counter)
    tst r0, r0                           ! counter == 0?
    bt/s    .L_check_cd_status           ! yes -> skip decrement, check CD status
    mov r9, r12                          ! r12 = 0 (callback accumulator, in delay slot)
    mov.l @r13, r3                       ! r3 = state base (reload)
    mov.l @(60, r3), r2                  ! r2 = pending counter
    add #-0x1, r2                        ! decrement counter
    mov.l r2, @(60, r3)                  ! store decremented counter
    cmp/pl r2                            ! counter still > 0?
    bt      .L_check_cd_status           ! yes -> continue to CD status check
    .byte   0xB6, 0x29    /* bsr 0x0604231E (external) */  ! call AI state full reset
    nop
    bra     .L_epilogue                  ! return 3 (state was reset)
    mov #0x3, r0                         ! r0 = 3 (delay slot)
.L_check_cd_status:
    mov.w   .L_csct_bit_mask, r2         ! r2 = 0x0400 (CSCT bit mask)
    mov.l   .L_fn_read_cd_status, r3     ! r3 = sym_06035C4E (read CD HIRQ status)
    jsr @r3                              ! call read_cd_status -> r0 = HIRQ word
    mov.l r2, @(4, r15)                  ! stack[4] = 0x0400 (save mask, delay slot)
    mov r0, r4                           ! r4 = HIRQ status word
    mov.l @(4, r15), r3                  ! r3 = 0x0400 (reload CSCT mask)
    exts.w r4, r5                        ! r5 = sign-extend status to 32-bit
    and r3, r5                           ! r5 = status & 0x0400 (isolate CSCT bit)
    tst r5, r5                           ! CSCT bit set?
    bt      .L_csct_not_set              ! no -> r5 = 0
    bra     .L_csct_is_set               ! yes -> r5 = 1
    mov #0x1, r5                         ! (delay slot)
.L_csct_not_set:
    mov #0x0, r5                         ! r5 = 0 (CSCT not set)
.L_csct_is_set:
    mov r5, r0                           ! r0 = CSCT flag (0 or 1)
    cmp/eq #0x1, r0                      ! CSCT bit was set?
    bf      .L_no_csct_path              ! no -> take non-CSCT path
    /* --- CSCT set: CD sector transfer complete --- */
    mov.l   .L_csct_ack_mask, r4         ! r4 = 0xFBFF (acknowledge mask, clears bit 10)
    mov.l   .L_fn_ack_cd_irq, r3         ! r3 = smpc_cmd_helper_b
    jsr @r3                              ! acknowledge CD interrupt
    nop
    mov r15, r4                          ! r4 = &stack[0]
    mov.l   .L_fn_checkpoint_section, r3 ! r3 = ai_checkpoint_section
    jsr @r3                              ! process section input -> result in stack[+8]
    add #0x8, r4                         ! r4 = &stack[+8] (delay slot)
    mov r15, r2                          ! r2 = stack pointer
    mov.l   .L_fn_memcpy_long, r3        ! r3 = memcpy_long
    mov.l @r13, r1                       ! r1 = state base
    add #0x8, r2                         ! r2 = &stack[+8] (src)
    add #0x40, r1                        ! r1 = &state[+0x40] (dst: section data area)
    jsr @r3                              ! memcpy_long(r0=0xC, r1=dst, r2=src)
    mov #0xC, r0                         ! r0 = 12 bytes to copy (delay slot)
    mov.l @r13, r2                       ! r2 = state base
    mov #0x4C, r0                        ! offset +0x4C = callback pointer
    mov.l @(r0, r2), r0                  ! r0 = state[+0x4C] (callback fn ptr)
    tst r0, r0                           ! callback is null?
    bt      .L_begin_event_loop          ! yes -> skip callback, go to event loop
    mov.l @r13, r3                       ! r3 = state base
    mov #0x4C, r0                        ! offset +0x4C
    mov r3, r4                           ! r4 = state base (for arg load below)
    mov.l @(r0, r3), r2                  ! r2 = state[+0x4C] (callback fn ptr)
    mov #0x50, r0                        ! offset +0x50 = callback argument
    jsr @r2                              ! call callback(state[+0x50])
    mov.l @(r0, r4), r4                  ! r4 = state[+0x50] (delay slot: load arg)
    bra     .L_begin_event_loop          ! proceed to event channel loop
    nop
.L_csct_bit_mask:
    .2byte  0x0400                         ! CSCT interrupt bit mask (CD sector complete)
    .4byte  ai_checkpoint_validate
.L_state_base_ptr:
    .4byte  sym_060A5400                   ! AI/game state base pointer
.L_fn_read_cd_status:
    .4byte  sym_06035C4E                   ! read CD block HIRQ status word
.L_csct_ack_mask:
    .4byte  0x0000FBFF                     ! HIRQ acknowledge mask (clear CSCT bit 10)
.L_fn_ack_cd_irq:
    .4byte  smpc_cmd_helper_b              ! acknowledge CD interrupt
.L_fn_checkpoint_section:
    .4byte  ai_checkpoint_section          ! process section checkpoint input
.L_fn_memcpy_long:
    .4byte  sym_06035168                   ! memcpy_long(r0=count, r1=dst, r2=src)
.L_no_csct_path:
    /* --- CSCT not set: try section transition --- */
    mov r15, r4                          ! r4 = &stack[0]
    mov.l   .L_fn_section_transition, r3 ! r3 = ai_section_transition
    jsr @r3                              ! call section transition handler
    add #0x8, r4                         ! r4 = &stack[+8] (delay slot)
    mov r0, r4                           ! r4 = transition result
    tst r4, r4                           ! result != 0? (error)
    bf      .L_begin_event_loop          ! yes -> skip copy, go to event loop
    mov.l @r13, r1                       ! r1 = state base
    mov r15, r2                          ! r2 = stack pointer
    mov.l   .L_fn_memcpy_long_2, r3      ! r3 = memcpy_long
    add #0x40, r1                        ! r1 = &state[+0x40] (dst: section data area)
    add #0x8, r2                         ! r2 = &stack[+8] (src)
    jsr @r3                              ! memcpy_long(r0=0xC, r1=dst, r2=src)
    mov #0xC, r0                         ! r0 = 12 bytes (delay slot)
.L_begin_event_loop:
    /* --- Event channel dispatch loop --- */
    bra     .L_event_loop_test           ! jump to loop condition
    mov r9, r14                          ! r14 = 0 (channel index, delay slot)
.L_event_loop_body:
    bsr     .L_resolve_event_channel     ! resolve callback for channel r14
    mov r14, r4                          ! r4 = channel index (delay slot)
    tst r0, r0                           ! r0 == 0? (callback exists)
    bt      .L_dispatch_callback         ! yes -> dispatch it
    bra     .L_next_channel              ! no callback -> skip
    nop
.L_dispatch_callback:
    mov r15, r5                          ! r5 = &stack[0] (output buffer)
    .byte   0xB0, 0x56    /* bsr 0x06041826 (external) */  ! call evt_callback_handler
    mov r14, r4                          ! r4 = channel index (delay slot)
    add r0, r12                          ! r12 += handler result (accumulate)
    mov.l @r15, r2                       ! r2 = stack[0] (overflow counter)
    cmp/gt r10, r2                       ! overflow > threshold (r10)?
    bf      .L_next_channel              ! no -> continue
    bra     .L_epilogue                  ! yes -> early exit with r0=1
    mov #0x1, r0                         ! r0 = 1 (delay slot)
.L_next_channel:
    add #0x1, r14                        ! r14++ (next channel index)
.L_event_loop_test:
    cmp/ge r11, r14                      ! r14 >= r11? (all channels processed)
    bf      .L_event_loop_body           ! no -> process next channel
    cmp/pl r12                           ! accumulated result > 0?
    bf      .L_no_events                 ! no -> return 0
    bra     .L_epilogue                  ! yes -> return 1
    mov #0x1, r0                         ! r0 = 1 (delay slot)
.L_no_events:
    mov #0x0, r0                         ! r0 = 0 (no events triggered)
.L_epilogue:
    add #0x14, r15                       ! deallocate locals
    lds.l @r15+, pr                      ! restore return address
    mov.l @r15+, r9                      ! restore r9 (from caller's frame)
    mov.l @r15+, r10                     ! restore r10
    mov.l @r15+, r11                     ! restore r11
    mov.l @r15+, r12                     ! restore r12
    mov.l @r15+, r13                     ! restore r13
    rts                                  ! return
    mov.l @r15+, r14                     ! restore r14 (delay slot)

/* ----- resolve_event_channel (internal helper) -----
 * Input:  r4 = channel index (0-7)
 * Output: r0 = 0 if callback pointer is non-null, 1 if null
 * Uses:   r5 = state base ptr, r4 = state base (loaded from *r5)
 *
 * Maps channel index to a struct field offset, loads the callback
 * pointer from state[offset], and returns whether it is null.
 */
.L_resolve_event_channel:
    mov.l   .L_state_base_ptr_2, r5      ! r5 = &state_base_ptr
    bra     .L_switch_index              ! jump to switch dispatch
    mov r4, r0                           ! r0 = channel index (delay slot)
.L_case_0:                                 ! channel 0: offset +0x58
    mov.l @r5, r4                        ! r4 = state base
    bra     .L_load_callback_ptr         ! load callback from state[+0x58]
    mov #0x58, r0                        ! r0 = 0x58 (delay slot)
.L_case_1:                                 ! channel 1: offset +0x0304
    mov.w   DAT_060417d8, r0             ! r0 = 0x0304
    bra     .L_load_callback_ptr         ! load callback from state[+0x0304]
    mov.l @r5, r4                        ! r4 = state base (delay slot)
.L_case_2:                                 ! channel 2: offset +0x030C
    mov.w   DAT_060417da, r0             ! r0 = 0x030C
    bra     .L_load_callback_ptr         ! load callback from state[+0x030C]
    mov.l @r5, r4                        ! r4 = state base (delay slot)
.L_case_3:                                 ! channel 3: offset +0x0328
    mov.w   .L_off_chan3, r0             ! r0 = 0x0328
    bra     .L_load_callback_ptr         ! load callback from state[+0x0328]
    mov.l @r5, r4                        ! r4 = state base (delay slot)
.L_case_4:                                 ! channel 4: offset +0x0338
    mov.w   .L_off_chan4, r0             ! r0 = 0x0338
    bra     .L_load_callback_ptr         ! load callback from state[+0x0338]
    mov.l @r5, r4                        ! r4 = state base (delay slot)
.L_case_5:                                 ! channel 5: offset +0x0348
    mov.w   .L_off_chan5, r0             ! r0 = 0x0348
    bra     .L_load_callback_ptr         ! load callback from state[+0x0348]
    mov.l @r5, r4                        ! r4 = state base (delay slot)
.L_case_6:                                 ! channel 6: offset +0x01E0
    mov.w   .L_off_chan6, r0             ! r0 = 0x01E0
    bra     .L_load_callback_ptr         ! load callback from state[+0x01E0]
    mov.l @r5, r4                        ! r4 = state base (delay slot)

    .global DAT_060417d8
DAT_060417d8:
    .2byte  0x0304                         ! channel 1 struct offset

    .global DAT_060417da
DAT_060417da:
    .2byte  0x030C                         ! channel 2 struct offset
.L_off_chan3:
    .2byte  0x0328                         ! channel 3 struct offset
.L_off_chan4:
    .2byte  0x0338                         ! channel 4 struct offset
.L_off_chan5:
    .2byte  0x0348                         ! channel 5 struct offset
.L_off_chan6:
    .2byte  0x01E0                         ! channel 6 struct offset
.L_fn_section_transition:
    .4byte  ai_section_transition          ! section transition handler
.L_fn_memcpy_long_2:
    .4byte  sym_06035168                   ! memcpy_long (second pool entry)
.L_state_base_ptr_2:
    .4byte  sym_060A5400                   ! AI/game state base pointer (helper copy)
.L_case_7:                                 ! channel 7: offset from external word pool
    mov.l @r5, r4                        ! r4 = state base
    .byte   0x90, 0x34    /* mov.w .L_wpool_0604185E, r0 */  ! r0 = external offset
.L_load_callback_ptr:
    bra     .L_check_null                ! go test if callback ptr is null
    mov.l @(r0, r4), r4                  ! r4 = state[offset] (callback ptr, delay slot)
.L_switch_index:                           ! --- switch(r0) dispatch table ---
    cmp/eq #0x0, r0                      ! index == 0?
    bt      .L_case_0
    cmp/eq #0x1, r0                      ! index == 1?
    bt      .L_case_1
    cmp/eq #0x2, r0                      ! index == 2?
    bt      .L_case_2
    cmp/eq #0x3, r0                      ! index == 3?
    bt      .L_case_3
    cmp/eq #0x4, r0                      ! index == 4?
    bt      .L_case_4
    cmp/eq #0x5, r0                      ! index == 5?
    bt      .L_case_5
    cmp/eq #0x6, r0                      ! index == 6?
    bt      .L_case_6
    cmp/eq #0x7, r0                      ! index == 7?
    bt      .L_case_7
.L_check_null:                             ! --- test callback pointer ---
    tst r4, r4                           ! callback ptr == 0? (null)
    bf      .L_has_callback              ! non-null -> return 0 (has callback)
    bra     .L_resolve_return            ! null -> return 1 (no callback)
    mov #0x1, r0                         ! r0 = 1 (delay slot)
.L_has_callback:
    mov #0x0, r0                         ! r0 = 0 (callback exists)
.L_resolve_return:
    rts                                  ! return to caller
    nop
