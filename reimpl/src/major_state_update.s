/* major_state_update -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06041D74 - 0x06041EE8
 *
 * Multi-phase state machine for the major game state transition pipeline.
 * Drives the game through sequential phases of a state transition (e.g.,
 * race start, checkpoint crossing, lap completion) by advancing a phase
 * counter at state[+0x338] through values 1 -> 2 -> 3 -> 4 -> done.
 *
 * Phase 1: Surface type query + checkpoint validation
 *   - Checks that state[+0x340] == 0 (no pending work)
 *   - Checks state[+0x344] == 0xFFFF (sentinel: uninitialized)
 *   - Calls track_surface_type_a(0, state[+0x33C]) to classify terrain
 *   - If surface type is non-zero, returns early (state changed = 1)
 *   - Otherwise calls ai_checkpoint_validate, stores result byte at state[+0x40]
 *   - Increments caller's counter via @r15, advances phase to 4
 *
 * Phase 2: Track impact response
 *   - Loads three parameters from state[+0x338..+0x344]
 *   - Calls track_impact_response(state[+0x338], state[+0x33C], state[+0x344])
 *   - Increments caller's counter, advances phase to 3 on success
 *   - Calls ai_checkpoint_validate, stores result byte at state[+0x40]
 *
 * Phase 3: HIRQ bit check (bit 7 = 0x0080)
 *   - Calls sym_06035C4E (HIRQ register reader)
 *   - Tests bit 0x0080; if set, flags state change
 *
 * Phase 4: HIRQ bit check (bit 6 = 0x0040)
 *   - Calls sym_06035C4E (HIRQ register reader)
 *   - Tests bit 0x0040; if set, flags state change
 *
 * Args:    r4 = pointer to caller's counter (long)
 * Returns: r0 = 1 if state changed, 0 if no change
 *
 * Callee-saved: r12 = state-changed flag (0 or 1), r13 = constant 0, r14 = &game_state_ptr
 */

    .section .text.FUN_06041D74


    .global major_state_update
    .type major_state_update, @function
major_state_update:
    sts.l pr, @-r15                         ! save return address
    add #-0x10, r15                         ! allocate 16 bytes of locals
    mov.l   _pool_game_state_ptr, r14       ! r14 = &game_state_ptr (kept across function)
    mov.l r4, @r15                          ! local[0] = r4 (pointer to caller's counter)
    mov #0x1, r4                            ! r4 = 1 (comparison constant)
    mov.l @r14, r3                          ! r3 = game state base
    mov.w   _wpool_phase_offset_a, r0       ! r0 = 0x0338 (phase field offset)
    mov.l @(r0, r3), r2                     ! r2 = state[+0x338] (current phase)
    cmp/eq r4, r2                           ! phase == 1?
    bf/s    .L_check_phase_2                ! if not phase 1, skip to phase 2 check
    mov r4, r12                             ! r12 = 1 (assume state changed; delay slot)
    mov.l @r14, r2                          ! r2 = game state base
    mov.w   _wpool_pending_work, r0         ! r0 = 0x0340 (pending work offset)
    mov.l @(r0, r2), r0                     ! r0 = state[+0x340] (pending work flag)
    tst r0, r0                              ! pending work == 0?
    bf      .L_phase1_alt                   ! if pending work != 0, take alternate path
    mov.l @r14, r3                          ! r3 = game state base
    mov.w   DAT_06041df0, r0                ! r0 = 0x0344 (surface data offset)
    mov.l @(r0, r3), r2                     ! r2 = state[+0x344] (surface data field)
    mov.l   .L_mask_low16, r3               ! r3 = 0x0000FFFF (sentinel value)
    cmp/eq r3, r2                           ! surface data == 0xFFFF (uninitialized)?
    bf      .L_phase1_alt                   ! if not sentinel, take alternate path
    mov.l @r14, r5                          ! r5 = game state base (for param load)
    mov.w   DAT_06041df2, r0                ! r0 = 0x033C (terrain param offset)
    mov.l   _pool_fn_surface_type, r3       ! r3 = &track_surface_type_a
    mov.l @(r0, r5), r5                     ! r5 = state[+0x33C] (terrain param)
    jsr @r3                                 ! track_surface_type_a(r4=0, r5=terrain_param)
    mov #0x0, r4                            ! r4 = 0 (first arg; delay slot)
    mov r0, r4                              ! r4 = surface type result
    tst r4, r4                              ! surface type == 0 (normal)?
    bt      .L_surface_ok                   ! if normal surface, continue validation
    bra     .L_epilogue                     ! abnormal surface: return early
    mov #0x1, r0                            ! r0 = 1 (state changed; delay slot)
.L_surface_ok:
    mov r15, r4                             ! r4 = stack pointer (for output)
    mov.l   _pool_fn_chkpt_validate_a, r3   ! r3 = &ai_checkpoint_validate
    jsr @r3                                 ! ai_checkpoint_validate(r4=&local[4])
    add #0x4, r4                            ! r4 -> local[4] (output buffer; delay slot)
    mov.l @r14, r2                          ! r2 = game state base
    mov r15, r3                             ! r3 = stack pointer
    add #0x4, r3                            ! r3 -> local[4] (validation result)
    mov.b @r3, r1                           ! r1 = result byte from checkpoint validate
    mov #0x40, r0                           ! r0 = 0x40 (checkpoint byte offset)
    mov.b r1, @(r0, r2)                     ! state[+0x40] = checkpoint result byte
    mov.l @r15, r3                          ! r3 = caller's counter pointer
    mov.l @r3, r2                           ! r2 = *counter (current value)
    add #0x1, r2                            ! r2 = counter + 1
    mov.l r2, @r3                           ! *counter = incremented value
    mov.l @r14, r3                          ! r3 = game state base
    mov #0x4, r2                            ! r2 = 4 (next phase value)
    mov.w   _wpool_phase_offset_a, r0       ! r0 = 0x0338 (phase field offset)
    mov.l r2, @(r0, r3)                     ! state[+0x338] = 4 (advance to phase 4)
    bra     .L_check_phase_2                ! fall through to phase 2 check
    nop                                     ! delay slot (no-op)
.L_phase1_alt:
    mov.l @r14, r4                          ! r4 = game state base
    mov.w   DAT_06041df0, r0                ! r0 = 0x0344 (surface data offset)
    mov.l @(r0, r4), r4                     ! r4 = state[+0x344] (surface data)
    tst r4, r4                              ! surface data == 0?
    bf      .L_set_phase_2                  ! if non-zero, set phase to 2
    bra     .L_check_phase_2               ! otherwise skip (no state change)
    mov r13, r12                            ! r12 = 0 (no state change; delay slot)
_wpool_phase_offset_a:
    .2byte  0x0338
_wpool_pending_work:
    .2byte  0x0340

    .global DAT_06041df0
DAT_06041df0:
    .2byte  0x0344

    .global DAT_06041df2
DAT_06041df2:
    .2byte  0x033C
_pool_game_state_ptr:
    .4byte  sym_060A5400
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
_pool_fn_surface_type:
    .4byte  track_surface_type_a
_pool_fn_chkpt_validate_a:
    .4byte  ai_checkpoint_validate
.L_set_phase_2:
    mov.l @r14, r2
    mov #0x2, r3
    mov.w   _wpool_phase_offset_b, r0
    mov.l r3, @(r0, r2)
.L_check_phase_2:
    mov.l @r14, r0
    mov.w   _wpool_phase_offset_b, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x2, r0
    bf      .L_check_phase_3
    mov.l @r14, r6
    mov.w   DAT_06041eb6, r0
    mov.l @r14, r5
    mov.l @r14, r4
    mov.l   _pool_fn_impact_response, r3
    mov.l @(r0, r6), r6
    add #-0x4, r0
    mov.l @(r0, r5), r5
    add #-0x4, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    mov.l @r15, r2
    mov.l @r2, r3
    add #0x1, r3
    tst r4, r4
    bf/s    .L_check_phase_3
    mov.l r3, @r2
    mov.l @r14, r3
    mov #0x3, r2
    mov.w   _wpool_phase_offset_b, r0
    mov r15, r4
    mov.l r2, @(r0, r3)
    mov.l   _pool_fn_chkpt_validate_b, r3
    jsr @r3
    add #0x4, r4
    mov.l @r14, r2
    mov r15, r3
    add #0x4, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
.L_check_phase_3:
    mov.l @r14, r0
    mov.w   _wpool_phase_offset_b, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x3, r0
    bf      .L_check_phase_4
    mov.w   _wpool_hirq_bit7_mask, r2
    mov.l   _pool_fn_hirq_reader, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r5
    mov.l @r15, r3
    exts.w r5, r4
    and r3, r4
    tst r4, r4
    bt      .L_hirq_bit7_clear
    bra     .L_test_hirq_bit7
    mov #0x1, r4
.L_hirq_bit7_clear:
    mov #0x0, r4
.L_test_hirq_bit7:
    tst r4, r4
    bt      .L_check_phase_4
    mov r13, r12
.L_check_phase_4:
    mov.l @r14, r0
    mov.w   _wpool_phase_offset_b, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x4, r0
    bf      .L_check_changed
    mov #0x40, r2
    mov.l   _pool_fn_hirq_reader, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r4
    mov.l @r15, r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_hirq_bit6_clear
    bra     .L_test_hirq_bit6
    mov #0x1, r5
.L_hirq_bit6_clear:
    mov #0x0, r5
.L_test_hirq_bit6:
    tst r5, r5
    bt      .L_check_changed
    mov r13, r12
.L_check_changed:
    mov r12, r0
    cmp/eq #0x1, r0
    bf      .L_no_change_cleanup
    bra     .L_epilogue
    mov #0x1, r0
_wpool_phase_offset_b:
    .2byte  0x0338

    .global DAT_06041eb6
DAT_06041eb6:
    .2byte  0x0344
_wpool_hirq_bit7_mask:
    .2byte  0x0080
    .2byte  0xFFFF
_pool_fn_impact_response:
    .4byte  track_impact_response
_pool_fn_chkpt_validate_b:
    .4byte  ai_checkpoint_validate
_pool_fn_hirq_reader:
    .4byte  sym_06035C4E
.L_no_change_cleanup:
    .byte   0xD4, 0x33    /* mov.l .L_pool_06041F98, r4 */
    .byte   0xD3, 0x34    /* mov.l .L_pool_06041F9C, r3 */
    jsr @r3
    nop
    mov.l @r14, r2
    .byte   0x90, 0x5D    /* mov.w .L_wpool_06041F90, r0 */
    mov.l r13, @(r0, r2)
    mov.l @r14, r3
    mov.l r13, @(52, r3)
    mov r13, r0
.L_epilogue:
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
