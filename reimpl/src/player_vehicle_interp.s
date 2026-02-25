/* player_vehicle_interp -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06042134 - 0x060422F0
 *
 * Vehicle interpolation queue processor.
 *
 * Iterates over a queue of pending vehicle interpolation entries stored
 * at game_state[+0x01E4]. Each entry is 12 bytes (3 longwords):
 *   [+0] = car/segment ID (passed to track_road_edge_c as r4)
 *   [+4] = source car index A (or -2 = sentinel "none")
 *   [+8] = source car index B (or -2 = sentinel "none")
 *
 * For each entry:
 *   - Checks field [+4]: if -2, sets r5=0 and r6=0xFF (no source A)
 *     Otherwise sets r5=1 (has source A) and r6=field[+4] value
 *   - Checks field [+8]: if -2, sets r7=0xFF (no source B)
 *     Otherwise ORs r5 with 2 (has source B) and r7=field[+8] value
 *   - Calls track_road_edge_c(r4=entry[+0], r5=flags, r6=srcA, r7=srcB)
 *   - If result is 0 (success):
 *     - Calls ai_checkpoint_validate(&local[4]) to process input
 *     - Stores result byte at game_state[+0x40]
 *     - Increments caller's processed-entry counter
 *   - If result is non-zero, aborts the loop early
 *
 * After the processing loop, compacts remaining unprocessed entries
 * by shifting them to the front of the array and updating the count.
 * Then calls the HIRQ reader (sym_06035C4E); if bit 6 (0x0040) is set
 * AND the compacted count is zero, clears game_state[+0x01E0].
 *
 * Args:    r4 = pointer to caller's processed-entry counter (long)
 * Returns: r0 = updated vehicle entry count after compaction
 */

    .section .text.FUN_06042134


    .global player_vehicle_interp
    .type player_vehicle_interp, @function
player_vehicle_interp:
    mov.l r14, @-r15                       ! save r14 (will hold game state pointer)
    mov.l r13, @-r15                       ! save r13 (loop index / entry iterator)
    mov.l r12, @-r15                       ! save r12 (constant 0)
    mov.l r11, @-r15                       ! save r11 (sentinel value 0xFF)
    mov.l r10, @-r15                       ! save r10 (constant 1)
    mov.l r9, @-r15                        ! save r9 (constant 2, "has source B" flag)
    mov.l r8, @-r15                        ! save r8 (&ai_checkpoint_validate function)
    sts.l pr, @-r15                        ! save return address
    add #-0x10, r15                        ! allocate 16 bytes of local space
    mov.l   pool_fn_chkpt_validate, r8     ! r8 = &ai_checkpoint_validate
    mov #0x2, r9                           ! r9 = 2 (flag: "has source B")
    mov #0x1, r10                          ! r10 = 1 (flag: "has source A")
    mov.w   DAT_0604222c, r11              ! r11 = 0xFF (sentinel: no source car)
    mov #0x0, r12                          ! r12 = 0 (constant zero / default flags)
    mov.l   pool_game_state_ptr, r14       ! r14 = &game_state_ptr (indirect)
    mov.l r4, @r15                         ! local[0] = r4 (caller's counter pointer)
    bra     .loop_cond_check               ! jump to loop condition check
    mov r12, r13                           ! r13 = 0 (loop index; delay slot)
.loop_body:
    mov.l @r14, r0                         ! r0 = game state base
    exts.w r13, r3                         ! r3 = sign-extended loop index
    mov r3, r2                             ! r2 = index (for offset calc)
    shll2 r2                               ! r2 = index * 4
    shll2 r3                               ! r3 = index * 4
    shll r3                                ! r3 = index * 8
    add r3, r2                             ! r2 = index * 4 + index * 8 = index * 12
    exts.w r2, r2                          ! sign-extend the 12-byte entry offset
    mov.w   DAT_0604222e, r3               ! r3 = 0x01E4 (entry array base offset)
    add r3, r0                             ! r0 = &state[+0x01E4] (array base)
    add r2, r0                             ! r0 = &entry[index] (current entry)
    mov.l @(4, r0), r0                     ! r0 = entry[index].srcA (field +4)
    cmp/eq #-0x2, r0                       ! srcA == -2 (sentinel)?
    bf      .srcA_present                  ! if not sentinel, source A is present
    mov r12, r5                            ! r5 = 0 (no source flags)
    bra     .check_srcB                    ! skip to source B check
    mov r11, r6                            ! r6 = 0xFF (sentinel: no source A; delay slot)
.srcA_present:
    mov r10, r5                            ! r5 = 1 (flag: has source A)
    mov.l @r14, r6                         ! r6 = game state base (reload for address calc)
    exts.w r13, r3                         ! r3 = sign-extended loop index
    mov r3, r2                             ! r2 = index copy
    shll2 r2                               ! r2 = index * 4
    shll2 r3                               ! r3 = index * 4
    shll r3                                ! r3 = index * 8
    add r3, r2                             ! r2 = index * 12
    exts.w r2, r2                          ! sign-extend the entry offset
    mov.w   DAT_0604222e, r3               ! r3 = 0x01E4 (entry array base offset)
    add r3, r6                             ! r6 = &state[+0x01E4]
    add r2, r6                             ! r6 = &entry[index]
    mov.l @(4, r6), r6                     ! r6 = entry[index].srcA value
.check_srcB:
    mov.l @r14, r0                         ! r0 = game state base
    exts.w r13, r3                         ! r3 = sign-extended loop index
    mov r3, r2                             ! r2 = index copy
    shll2 r2                               ! r2 = index * 4
    shll2 r3                               ! r3 = index * 4
    shll r3                                ! r3 = index * 8
    add r3, r2                             ! r2 = index * 12
    exts.w r2, r2                          ! sign-extend the entry offset
    mov.w   DAT_0604222e, r3               ! r3 = 0x01E4 (entry array base offset)
    add r3, r0                             ! r0 = &state[+0x01E4]
    add r2, r0                             ! r0 = &entry[index]
    mov.l @(8, r0), r0                     ! r0 = entry[index].srcB (field +8)
    cmp/eq #-0x2, r0                       ! srcB == -2 (sentinel)?
    bf      .srcB_present                  ! if not sentinel, source B is present
    bra     .call_road_edge                ! skip to function call
    mov r11, r7                            ! r7 = 0xFF (sentinel: no source B; delay slot)
.srcB_present:
    or r9, r5                              ! r5 |= 2 (set "has source B" flag)
    exts.w r13, r3                         ! r3 = sign-extended loop index
    mov.l @r14, r7                         ! r7 = game state base (reload for address calc)
    mov r3, r2                             ! r2 = index copy
    shll2 r2                               ! r2 = index * 4
    shll2 r3                               ! r3 = index * 4
    shll r3                                ! r3 = index * 8
    add r3, r2                             ! r2 = index * 12
    exts.w r2, r2                          ! sign-extend the entry offset
    mov.w   DAT_0604222e, r3               ! r3 = 0x01E4 (entry array base offset)
    add r3, r7                             ! r7 = &state[+0x01E4]
    add r2, r7                             ! r7 = &entry[index]
    mov.l @(8, r7), r7                     ! r7 = entry[index].srcB value
.call_road_edge:
    exts.w r13, r3                         ! r3 = sign-extended loop index
    mov.l @r14, r4                         ! r4 = game state base
    mov r3, r2                             ! r2 = index copy
    shll2 r2                               ! r2 = index * 4
    shll2 r3                               ! r3 = index * 4
    shll r3                                ! r3 = index * 8
    add r3, r2                             ! r2 = index * 12
    exts.w r2, r2                          ! sign-extend the entry offset
    mov.w   DAT_0604222e, r3               ! r3 = 0x01E4 (entry array base offset)
    add r3, r4                             ! r4 = &state[+0x01E4]
    add r2, r4                             ! r4 = &entry[index]
    mov.l   pool_fn_road_edge, r3          ! r3 = &track_road_edge_c
    jsr @r3                                ! track_road_edge_c(r4=entry[0], r5=flags, r6=srcA, r7=srcB)
    mov.l @r4, r4                          ! r4 = entry[index].carID (field +0; delay slot)
    mov r0, r4                             ! r4 = road edge result
    tst r4, r4                             ! result == 0 (success)?
    bt      .edge_check_ok                 ! if success, proceed to validate
    bra     .loop_exit                     ! non-zero: abort processing loop
    nop                                    ! delay slot
.edge_check_ok:
    mov r15, r4                            ! r4 = &local[0] (stack pointer)
    jsr @r8                                ! ai_checkpoint_validate(&local[4])
    add #0x4, r4                           ! r4 = &local[4] (output buffer; delay slot)
    mov.l @r14, r2                         ! r2 = game state base
    mov r15, r3                            ! r3 = stack pointer
    add #0x4, r3                           ! r3 = &local[4] (validation result)
    mov.b @r3, r1                          ! r1 = result byte from checkpoint validate
    mov #0x40, r0                          ! r0 = 0x40 (checkpoint byte offset in state)
    mov.b r1, @(r0, r2)                    ! game_state[+0x40] = checkpoint result byte
    mov.l @r15, r3                         ! r3 = caller's counter pointer
    mov.l @r3, r2                          ! r2 = *counter (current value)
    add #0x1, r2                           ! r2 = counter + 1
    mov.l r2, @r3                          ! *counter = incremented value
    add #0x1, r13                          ! r13++ (advance to next entry)
.loop_cond_check:
    mov.l @r14, r3                         ! r3 = game state base
    mov.w   wpool_entry_count_off, r0      ! r0 = 0x01DC (entry count offset)
    mov.l @(r0, r3), r2                    ! r2 = state[+0x01DC] (total entry count)
    cmp/ge r2, r13                         ! loop index >= entry count?
    bf      .loop_body                     ! if more entries remain, continue loop
.loop_exit:
    mov.l @r14, r2                         ! r2 = game state base
    mov.w   wpool_entry_count_off, r0      ! r0 = 0x01DC (entry count offset)
    mov.l @(r0, r2), r3                    ! r3 = state[+0x01DC] (total entry count)
    cmp/ge r3, r13                         ! did we process all entries?
    bf      .compact_remaining             ! if not all processed, compact remainder
    mov.l @r14, r2                         ! r2 = game state base (all processed)
    mov.w   wpool_entry_count_off, r0      ! r0 = 0x01DC (entry count offset)
    bra     .post_compact                  ! skip compaction, go to HIRQ check
    mov.l r12, @(r0, r2)                   ! state[+0x01DC] = 0 (clear count; delay slot)

    .global DAT_0604222c
DAT_0604222c:
    .2byte  0x00FF

    .global DAT_0604222e
DAT_0604222e:
    .2byte  0x01E4
wpool_entry_count_off:
    .2byte  0x01DC
    .2byte  0xFFFF
pool_fn_chkpt_validate:
    .4byte  ai_checkpoint_validate
pool_game_state_ptr:
    .4byte  sym_060A5400
pool_fn_road_edge:
    .4byte  track_road_edge_c
.compact_remaining:
    bra     .compact_cond_check            ! jump to compaction loop condition
    mov r12, r5                            ! r5 = 0 (destination index; delay slot)
.compact_body:
    mov.l @r14, r7                         ! r7 = game state base
    exts.w r5, r4                          ! r4 = sign-extended dest index
    exts.w r13, r6                         ! r6 = sign-extended source index (first unprocessed)
    .byte   0x93, 0x5E    /* mov.w .L_wpool_0604230A, r3 */  ! r3 = 0x01E4 (array base offset)
    add r3, r7                             ! r7 = &state[+0x01E4] (array base)
    mov r4, r3                             ! r3 = dest index
    mov r7, r2                             ! r2 = array base (for dest calc)
    shll2 r4                               ! r4 = dest * 4
    shll2 r3                               ! r3 = dest * 4
    shll r3                                ! r3 = dest * 8
    add r3, r4                             ! r4 = dest * 12
    exts.w r4, r4                          ! sign-extend dest entry offset
    mov r6, r3                             ! r3 = source index
    add r4, r2                             ! r2 = &entry[dest] (destination pointer)
    shll2 r6                               ! r6 = source * 4
    shll2 r3                               ! r3 = source * 4
    shll r3                                ! r3 = source * 8
    add r3, r6                             ! r6 = source * 12
    exts.w r6, r6                          ! sign-extend source entry offset
    mov r7, r1                             ! r1 = array base (for source calc)
    add r6, r1                             ! r1 = &entry[source] (source pointer)
    mov.l @r1, r3                          ! r3 = entry[source].carID (field +0)
    mov.l r3, @r2                          ! entry[dest].carID = entry[source].carID
    mov.l @r14, r7                         ! r7 = game state base (reload)
    .byte   0x93, 0x49    /* mov.w .L_wpool_0604230A, r3 */  ! r3 = 0x01E4 (array base offset)
    add r3, r7                             ! r7 = &state[+0x01E4]
    mov r7, r2                             ! r2 = array base (for dest)
    add r4, r2                             ! r2 = &entry[dest]
    mov r7, r3                             ! r3 = array base (for source)
    add r6, r3                             ! r3 = &entry[source]
    mov.l @(4, r3), r1                     ! r1 = entry[source].srcA (field +4)
    mov.l r1, @(4, r2)                     ! entry[dest].srcA = entry[source].srcA
    mov.l @r14, r7                         ! r7 = game state base (reload)
    .byte   0x93, 0x40    /* mov.w .L_wpool_0604230A, r3 */  ! r3 = 0x01E4 (array base offset)
    add r3, r7                             ! r7 = &state[+0x01E4]
    add r7, r4                             ! r4 = &entry[dest]
    add r7, r6                             ! r6 = &entry[source]
    mov.l @(8, r6), r2                     ! r2 = entry[source].srcB (field +8)
    mov.l r2, @(8, r4)                     ! entry[dest].srcB = entry[source].srcB
    add #0x1, r13                          ! r13++ (advance source index)
    add #0x1, r5                           ! r5++ (advance dest index)
.compact_cond_check:
    mov.l @r14, r3                         ! r3 = game state base
    .byte   0x90, 0x38    /* mov.w .L_wpool_0604230C, r0 */  ! r0 = 0x01DC (entry count offset)
    mov.l @(r0, r3), r2                    ! r2 = state[+0x01DC] (total entry count)
    cmp/ge r2, r13                         ! source index >= total count?
    bf      .compact_body                  ! if more entries, continue compaction
    mov.l @r14, r2                         ! r2 = game state base
    .byte   0x90, 0x33    /* mov.w .L_wpool_0604230C, r0 */  ! r0 = 0x01DC (entry count offset)
    mov.l r5, @(r0, r2)                    ! state[+0x01DC] = new count (dest index = remaining entries)
.post_compact:
    mov #0x40, r3                          ! r3 = 0x40 (HIRQ bit 6 mask)
    mov.l r3, @r15                         ! local[0] = 0x40 (save mask for later)
    .byte   0xD3, 0x19    /* mov.l .L_pool_06042310, r3 */   ! r3 = &sym_06035C4E (HIRQ reader)
    jsr @r3                                ! call HIRQ reader: r0 = HIRQ status
    nop                                    ! delay slot
    mov r0, r5                             ! r5 = HIRQ status word
    mov.l @r15, r3                         ! r3 = 0x40 (saved bit mask)
    exts.w r5, r4                          ! r4 = sign-extended HIRQ status
    and r3, r4                             ! r4 = status & 0x40 (test bit 6)
    tst r4, r4                             ! bit 6 clear?
    bt      .hirq_bit_clear                ! if bit 6 not set, skip
    bra     .hirq_bit_test                 ! bit 6 set, proceed to test
    mov #0x1, r4                           ! r4 = 1 (bit present; delay slot)
.hirq_bit_clear:
    mov #0x0, r4                           ! r4 = 0 (bit not present)
.hirq_bit_test:
    tst r4, r4                             ! HIRQ bit 6 present?
    bt      .return_count                  ! if not set, go to return
    mov.l @r14, r3                         ! r3 = game state base
    .byte   0x90, 0x20    /* mov.w .L_wpool_0604230C, r0 */  ! r0 = 0x01DC (entry count offset)
    mov.l @(r0, r3), r0                    ! r0 = state[+0x01DC] (current entry count)
    tst r0, r0                             ! entry count == 0?
    bf      .return_count                  ! if entries remain, skip clear
    mov.l @r14, r3                         ! r3 = game state base
    .byte   0x90, 0x1C    /* mov.w .L_wpool_0604230E, r0 */  ! r0 = 0x01E0 (ready flag offset)
    mov.l r12, @(r0, r3)                   ! state[+0x01E0] = 0 (clear ready flag)
.return_count:
    mov.l @r14, r0                         ! r0 = game state base
    .byte   0x91, 0x18    /* mov.w .L_wpool_0604230C, r1 */  ! r1 = 0x01DC (entry count offset)
    mov.l @(r0, r1), r0                    ! r0 = state[+0x01DC] (entry count = return value)
    add #0x10, r15                         ! deallocate 16 bytes of locals
    lds.l @r15+, pr                        ! restore return address
    mov.l @r15+, r8                        ! restore r8
    mov.l @r15+, r9                        ! restore r9
    mov.l @r15+, r10                       ! restore r10
    mov.l @r15+, r11                       ! restore r11
    mov.l @r15+, r12                       ! restore r12
    mov.l @r15+, r13                       ! restore r13
    rts                                    ! return r0 = updated entry count
    mov.l @r15+, r14                       ! restore r14 (delay slot)
