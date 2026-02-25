/* sys_boot_sequence -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060402BC - 0x0604053A
 *
 * Event command batch processor. Called from sys_boot_table_init as part of
 * the system boot handler table. Processes a batch of event commands against
 * the event queue system using a state machine with 6 states (0-5).
 *
 * Takes a context descriptor struct in r4 with fields:
 *   +0x00  (0)  : queue head pointer
 *   +0x04  (4)  : current position offset
 *   +0x08  (8)  : end position (updated during processing)
 *   +0x14 (20)  : source data pointer (passed to evt_cmd_enqueue)
 *   +0x18 (24)  : total byte count
 *   +0x1C (28)  : bytes consumed so far (subtracted from total to get remaining)
 *   +0x20 (32)  : target limit
 *   +0x24 (36)  : progress counter (accumulated bytes processed)
 *   +0x28 (40)  : max chunk size / event handle
 *
 * Return values in r0:
 *   0 = continue (more data to process)
 *   1 = surface check needed
 *   2 = batch complete (progress == target)
 *   3 = state 3 exit (error)
 *   4 = state 4 exit (error)
 *   6 = boundary lock / abort
 *
 * Key external calls:
 *   evt_validate_multi (BSR 0x060405B8) -- validate event params and get type
 *   sym_06040722 (BSR) -- compute position offset (r0 = #0x1E * field)
 *   sym_06040FEA -- release event boundary lock
 *   sym_06041014 -- check if event boundary is active
 *   sym_06040FB8 -- acquire event boundary lock
 *   evt_cmd_enqueue -- enqueue a command with size/offset
 *   sym_060409DE -- compute position + accumulated offset
 *   track_surface_check -- validate surface data
 *   queue_validator -- validate queue entry against handle
 *   state_field_read -- read current state field
 *   queue_helper -- commit queue entry
 */

    .section .text.FUN_060402BC


    .global sys_boot_sequence
    .type sys_boot_sequence, @function
sys_boot_sequence:
    /* --- prologue: save r14-r8 + pr, allocate 0x1C local frame --- */
    mov.l r14, @-r15          ! push r14 (callee-saved)
    mov r4, r14               ! r14 = context descriptor pointer
    mov.l r13, @-r15          ! push r13
    mov.l r12, @-r15          ! push r12
    mov.l r11, @-r15          ! push r11
    mov.l r10, @-r15          ! push r10
    mov.l r9, @-r15           ! push r9
    mov.l r8, @-r15           ! push r8
    sts.l pr, @-r15           ! push return address
    add #-0x1C, r15           ! allocate 0x1C bytes of local stack
    mov.l   .L_ptr_boundary_release, r10 ! r10 = &sym_06040FEA (boundary release fn)
    mov r15, r5               ! r5 = sp (output buffer for validate)
    mov.l   .L_ptr_game_state, r13 ! r13 = &game_state (sym_060A4D14)
    mov.l @(24, r14), r12     ! r12 = ctx->source_data (+0x18)
    mov.l @(32, r14), r11     ! r11 = ctx->target_limit (+0x20)
    mov.l @(36, r14), r3      ! r3 = ctx->progress (+0x24)
    add #0x4, r5              ! r5 = sp+4 (skip first local slot)
    sub r3, r11               ! r11 = remaining = target_limit - progress
    .byte   0xB1, 0x6A    /* bsr 0x060405B8 (external) */ ! call evt_validate_multi(sp, sp+4)
    mov r15, r4               ! (delay slot) r4 = sp
    bra     .L_state_dispatch ! jump to state dispatch switch
    mov r0, r9                ! (delay slot) r9 = validation result (state code)

    /* --- state 2: redirect to main data processing --- */
.L_state2_redirect:
    bra     .L_process_data   ! state 2 falls through to process_data
    nop
.L_ptr_boundary_release:
    .4byte  sym_06040FEA      ! boundary release function pointer
.L_ptr_game_state:
    .4byte  sym_060A4D14      ! global game state base pointer

    /* --- state 0: check track surface validity --- */
.L_state0_surface_check:
    mov.l   .L_ptr_surface_check, r3 ! r3 = &track_surface_check
    jsr @r3                   ! call track_surface_check()
    nop
    tst r0, r0                ! test surface check result
    bf      .L_process_data   ! if nonzero (valid), proceed to process data
    bra     .L_epilogue       ! surface invalid -- return 1 (needs check)
    mov #0x1, r0              ! (delay slot) return code = 1

    /* --- state 3: exit with error code 3 --- */
.L_state3_exit:
    bra     .L_epilogue
    mov #0x3, r0              ! (delay slot) return code = 3

    /* --- state 4: exit with error code 4 --- */
.L_state4_exit:
    bra     .L_epilogue
    mov #0x4, r0              ! (delay slot) return code = 4

    /* --- state 5 / default: release boundary lock and abort --- */
.L_state5_release_lock:
    jsr @r10                  ! call sym_06040FEA (release boundary lock)
    mov.l @(40, r12), r4      ! (delay slot) r4 = source->event_handle (+0x28)
    bra     .L_epilogue
    mov #0x6, r0              ! (delay slot) return code = 6 (abort)

    /* --- state machine dispatch (switch on r0) --- */
.L_state_dispatch:
    cmp/eq #0x0, r0           ! state == 0?
    bt      .L_state0_surface_check ! -> surface check
    cmp/eq #0x1, r0           ! state == 1?
    bt      .L_process_data   ! -> main data processing
    cmp/eq #0x2, r0           ! state == 2?
    bt      .L_state2_redirect ! -> redirect (also goes to process_data)
    cmp/eq #0x3, r0           ! state == 3?
    bt      .L_state3_exit    ! -> exit with code 3
    cmp/eq #0x4, r0           ! state == 4?
    bt      .L_state4_exit    ! -> exit with code 4
    bra     .L_state5_release_lock ! default: state >= 5 -> release lock
    nop

    /* --- main data processing path (states 1, 2) --- */
.L_process_data:
    mov.l @(32, r14), r4      ! r4 = ctx->target_limit (+0x20)
    tst r4, r4                ! target_limit == 0?
    bf      .L_clamp_remaining ! if nonzero, continue
    mov.l @(36, r14), r3      ! r3 = ctx->progress (+0x24)
    cmp/eq r3, r4             ! progress == target_limit (both 0)?
    bf      .L_clamp_remaining ! if not equal, continue processing
    bra     .L_epilogue       ! both zero and equal -- batch complete
    mov #0x2, r0              ! (delay slot) return code = 2

    /* --- clamp remaining bytes to max chunk size --- */
.L_clamp_remaining:
    mov.l @(40, r14), r4      ! r4 = ctx->max_chunk (+0x28)
    cmp/ge r4, r11            ! remaining >= max_chunk?
    bt      .L_use_max_chunk  ! if so, cap at max_chunk
    bra     .L_check_boundary ! otherwise use remaining as-is
    nop
.L_ptr_surface_check:
    .4byte  track_surface_check ! track surface validation function
.L_use_max_chunk:
    mov r4, r11               ! r11 = max_chunk (cap remaining)

    /* --- check if event boundary is currently active --- */
.L_check_boundary:
    mov.l   .L_ptr_boundary_active, r3 ! r3 = &sym_06041014
    jsr @r3                   ! call sym_06041014(event_handle)
    mov.l @(40, r12), r4      ! (delay slot) r4 = source->event_handle
    tst r0, r0                ! boundary active? (0 = no)
    bt      .L_enqueue_command ! not active -- proceed to enqueue
    bra     .L_boundary_active_path ! active -- handle boundary case
    nop

    /* --- enqueue event command into queue --- */
.L_enqueue_command:
    mov #0x0, r6              ! r6 = 0 (flags: no special mode)
    mov.l   .L_fp_max, r5     ! r5 = 0x7FFFFFFF (max positive 16.16)
    mov.l   .L_ptr_evt_cmd_enqueue, r3 ! r3 = &evt_cmd_enqueue
    jsr @r3                   ! call evt_cmd_enqueue(src_data, max, 0)
    mov.l @(24, r14), r4      ! (delay slot) r4 = ctx->source_data (+0x18)
    mov r0, r9                ! r9 = enqueued byte count
    cmp/pz r9                 ! enqueued >= 0?
    bt      .L_calc_dest_offset ! if non-negative, proceed
    mov #0x0, r9              ! clamp negative result to 0

    /* --- calculate destination offset for position tracking --- */
.L_calc_dest_offset:
    mov.l   .L_ptr_calc_position, r3 ! r3 = &sym_060409DE (calc position)
    jsr @r3                   ! call sym_060409DE(source_data)
    mov r12, r4               ! (delay slot) r4 = source data pointer
    mov r0, r5                ! r5 = calculated position
    .byte   0xB1, 0xD6    /* bsr 0x06040722 (external) */ ! call offset_compute(ctx)
    mov r14, r4               ! (delay slot) r4 = context descriptor
    mov.l @(4, r14), r8       ! r8 = ctx->current_pos (+0x04)
    cmp/pl r9                 ! enqueued > 0?
    bf/s    .L_check_batch_fits ! if not, skip adjustment
    add r0, r8                ! (delay slot) r8 += computed offset
    mov.l   .L_ptr_game_state_b, r3 ! r3 = &game_state
    mov.w   .L_off_state_pos_ac, r0 ! r0 = 0xAC (state field offset)
    mov.l @r3, r3             ! r3 = *game_state (deref pointer)
    mov.l @(r0, r3), r2       ! r2 = game_state[0xAC] (position limit)
    cmp/ge r2, r8             ! current_pos + offset >= limit?
    bt      .L_check_batch_fits ! if so, skip adjustment
    mov.l @r13, r2            ! r2 = *game_state (via r13)
    mov.w   .L_off_state_pos_ac, r0 ! r0 = 0xAC
    mov.l @(r0, r2), r3       ! r3 = game_state[0xAC] (position limit)
    sub r8, r3                ! r3 = limit - current_pos (gap)
    sub r3, r9                ! r9 -= gap (reduce enqueued by gap)

    /* --- check if enqueued amount covers remaining batch --- */
.L_check_batch_fits:
    cmp/ge r11, r9            ! enqueued >= remaining?
    bf      .L_partial_remaining ! if not enough, handle partial
    mov.l @(36, r14), r2      ! r2 = ctx->progress (+0x24)
    add r11, r2               ! r2 += remaining (advance progress)
    mov.l r2, @(36, r14)      ! ctx->progress = updated value
    mov.l @(32, r14), r3      ! r3 = ctx->target_limit (+0x20)
    sub r2, r3                ! r3 = target - progress (how much left)
    tst r3, r3                ! progress == target?
    bf      .L_batch_continue ! if not done, return 0
    bra     .L_epilogue       ! batch complete
    mov #0x2, r0              ! (delay slot) return code = 2

    /* --- batch not complete, but chunk processed --- */
.L_batch_continue:
    bra     .L_epilogue
    mov #0x0, r0              ! (delay slot) return code = 0 (continue)

    /* --- partial: enqueued less than remaining --- */
.L_partial_remaining:
    sub r9, r11               ! r11 -= enqueued (reduce remaining)
    cmp/pl r11                ! remaining > 0?
    bt      .L_acquire_lock   ! if data remains, acquire lock for next batch
    mov.l @(32, r14), r3      ! r3 = ctx->target_limit
    mov.l @(36, r14), r2      ! r2 = ctx->progress
    sub r2, r3                ! r3 = target - progress
    tst r3, r3                ! fully consumed?
    bf      .L_partial_continue ! not done -- return 0
    bra     .L_epilogue       ! done
    mov #0x2, r0              ! (delay slot) return code = 2

    /* --- partial batch processed, not yet done --- */
.L_partial_continue:
    bra     .L_epilogue
    mov #0x0, r0              ! (delay slot) return code = 0 (continue)

    /* --- acquire boundary lock for multi-step processing --- */
.L_acquire_lock:
    mov.l   .L_ptr_boundary_acquire, r3 ! r3 = &sym_06040FB8
    jsr @r3                   ! call sym_06040FB8() -- acquire lock
    nop
    mov r0, r9                ! r9 = lock handle (or error)
    cmp/pz r9                 ! lock acquired? (>= 0)
    bt      .L_build_sub_batch ! success -- build sub-batch descriptor
    bra     .L_epilogue       ! failed -- abort
    mov #0x6, r0              ! (delay slot) return code = 6 (lock fail)

    /* --- constant pool (mid-function) --- */
.L_off_state_pos_ac:
    .2byte  0x00AC            ! offset 0xAC into game state (position field)
.L_ptr_boundary_active:
    .4byte  sym_06041014      ! check-boundary-active function
.L_fp_max:
    .4byte  0x7FFFFFFF                  /* max positive 16.16 */
.L_ptr_evt_cmd_enqueue:
    .4byte  evt_cmd_enqueue   ! event command enqueue function
.L_ptr_calc_position:
    .4byte  sym_060409DE      ! position calculation helper
.L_ptr_game_state_b:
    .4byte  sym_060A4D14      ! game state pointer (second ref)
.L_ptr_boundary_acquire:
    .4byte  sym_06040FB8      ! boundary lock acquire function

    /* --- build sub-batch descriptor and validate --- */
.L_build_sub_batch:
    mov.l r9, @(40, r12)      ! source->event_handle = lock handle
    mov.l   .L_ptr_calc_position_b, r3 ! r3 = &sym_060409DE
    jsr @r3                   ! call sym_060409DE(source_data)
    mov r12, r4               ! (delay slot) r4 = source data pointer
    mov r11, r5               ! r5 = remaining bytes
    add r0, r5                ! r5 += position offset
    .byte   0xB1, 0x91    /* bsr 0x06040722 (external) */ ! call offset_compute(ctx)
    mov r14, r4               ! (delay slot) r4 = context descriptor
    mov.l @(4, r14), r2       ! r2 = ctx->current_pos (+0x04)
    mov #0x1, r4              ! r4 = 1 (sub-batch flag)
    mov r15, r3               ! r3 = sp
    add r2, r0                ! r0 = current_pos + computed offset
    add #0x8, r3              ! r3 = sp+8 (local sub-batch struct)
    mov r15, r2               ! r2 = sp
    mov.l r0, @(8, r14)       ! ctx->end_pos = new end position (+0x08)
    add #0x8, r2              ! r2 = sp+8
    mov.l r4, @r3             ! local[+0] = 1 (sub-batch active flag)
    mov #0x10, r0             ! r0 = 0x10 (offset for type byte)
    mov.l r8, @(4, r2)        ! local[+4] = saved position (r8)
    mov r15, r3               ! r3 = sp
    mov r15, r2               ! r2 = sp
    add #0x8, r3              ! r3 = sp+8
    add #0x8, r2              ! r2 = sp+8
    mov.l r4, @(8, r3)        ! local[+8] = 1 (sub-batch count)
    mov r15, r3               ! r3 = sp
    mov.l @(8, r14), r1       ! r1 = ctx->end_pos
    add #0x8, r3              ! r3 = sp+8
    mov.l @(4, r3), r3        ! r3 = local[+4] (saved position)
    sub r3, r1                ! r1 = end_pos - saved_pos (delta)
    mov #0x0, r3              ! r3 = 0
    mov.l r1, @(12, r2)       ! local[+12] = position delta
    mov r3, r5                ! r5 = 0 (no output buffer)
    mov r15, r2               ! r2 = sp
    add #0x8, r2              ! r2 = sp+8
    mov.b r3, @(r0, r2)       ! local[+0x10] = 0 (type byte = default)
    .byte   0xB0, 0xBF    /* bsr 0x060405B8 (external) */ ! call evt_validate_multi(sp, 0)
    mov r15, r4               ! (delay slot) r4 = sp

    /* --- compare sub-batch positions against state boundaries --- */
    mov r15, r3               ! r3 = sp
    mov.l @r13, r4            ! r4 = *game_state
    mov.w   .L_off_state_pos_ac_b, r0 ! r0 = 0xAC
    add #0x8, r3              ! r3 = sp+8 (local struct)
    mov.l @(r0, r4), r4       ! r4 = game_state[0xAC] (position A)
    mov.l @(4, r3), r2        ! r2 = local[+4] (saved position)
    cmp/gt r2, r4             ! state_pos_A > saved_pos?
    bt      .L_validate_and_commit ! if so, needs validation
    mov r15, r2               ! r2 = sp
    mov.l @r13, r3            ! r3 = *game_state
    mov.w   .L_off_state_pos_b0, r0 ! r0 = 0xB0
    add #0x8, r2              ! r2 = sp+8
    mov.l @(r0, r3), r3       ! r3 = game_state[0xB0] (position B)
    mov.l @(4, r2), r2        ! r2 = local[+4] (saved position)
    cmp/ge r3, r2             ! saved_pos >= state_pos_B?
    bt      .L_validate_and_commit ! if so, needs validation
    mov.l @(8, r14), r2       ! r2 = ctx->end_pos
    cmp/ge r2, r4             ! state_pos_A >= end_pos?
    bt      .L_validate_and_commit ! if so, needs validation
    mov.l @r13, r2            ! r2 = *game_state
    mov.l @(8, r14), r3       ! r3 = ctx->end_pos
    mov.w   .L_off_state_pos_b0, r0 ! r0 = 0xB0
    mov.l @(r0, r2), r2       ! r2 = game_state[0xB0] (position B)
    cmp/gt r2, r3             ! end_pos > state_pos_B?
    bt      .L_validate_and_commit ! if so, needs validation

    /* --- all bounds checks passed: update state and return --- */
    mov.l @r13, r2            ! r2 = *game_state
    mov r15, r3               ! r3 = sp
    add #0x8, r3              ! r3 = sp+8
    mov.l @(4, r3), r1        ! r1 = local[+4] (saved position)
    mov.w   .L_off_state_pos_ac_b, r0 ! r0 = 0xAC
    mov.l r1, @(r0, r2)       ! game_state[0xAC] = saved position
    bra     .L_epilogue       ! done -- return continue
    mov #0x0, r0              ! (delay slot) return code = 0

    /* --- bounds exceeded: validate queue and commit --- */
.L_validate_and_commit:
    mov r9, r5                ! r5 = lock handle
    mov.l   .L_ptr_queue_validator, r3 ! r3 = &queue_validator
    jsr @r3                   ! call queue_validator(queue_ptr, handle)
    mov.l @(20, r12), r4      ! (delay slot) r4 = source->queue_ptr (+0x14)
    mov.l   .L_ptr_state_field_read, r3 ! r3 = &state_field_read
    jsr @r3                   ! call state_field_read()
    nop
    tst r0, r0                ! state field == 0?
    bt      .L_commit_queue_entry ! if zero, proceed to commit
    bra     .L_epilogue       ! nonzero -- abort
    mov #0x6, r0              ! (delay slot) return code = 6

    /* --- commit the queue entry and update progress --- */
.L_commit_queue_entry:
    mov r9, r5                ! r5 = lock handle
    mov r15, r4               ! r4 = sp
    mov.l   .L_ptr_queue_helper, r3 ! r3 = &queue_helper
    jsr @r3                   ! call queue_helper(sp+8, handle)
    add #0x8, r4              ! (delay slot) r4 = sp+8 (local struct)
    mov.l @(36, r14), r2      ! r2 = ctx->progress (+0x24)
    add r11, r2               ! r2 += remaining (advance progress)
    mov.l r2, @(36, r14)      ! ctx->progress = updated value
    mov.l @r13, r3            ! r3 = *game_state
    mov r15, r2               ! r2 = sp
    add #0x8, r2              ! r2 = sp+8
    mov.l @(4, r2), r1        ! r1 = local[+4] (saved position)
    mov.w   .L_off_state_pos_ac_b, r0 ! r0 = 0xAC
    mov.l r1, @(r0, r3)       ! game_state[0xAC] = saved position
    mov.l @r13, r3            ! r3 = *game_state
    mov.l @(8, r14), r2       ! r2 = ctx->end_pos
    add #0x4, r0              ! r0 = 0xB0
    mov.l r2, @(r0, r3)       ! game_state[0xB0] = end_pos
    bra     .L_epilogue       ! done
    mov #0x0, r0              ! (delay slot) return code = 0

    /* --- constant pool (second mid-function pool) --- */
.L_off_state_pos_ac_b:
    .2byte  0x00AC            ! offset 0xAC into game state
.L_off_state_pos_b0:
    .2byte  0x00B0            ! offset 0xB0 into game state
    .2byte  0xFFFF            ! padding (alignment)
.L_ptr_calc_position_b:
    .4byte  sym_060409DE      ! position calculation helper (second ref)
.L_ptr_queue_validator:
    .4byte  queue_validator   ! queue validation function
.L_ptr_state_field_read:
    .4byte  state_field_read  ! state field reader function
.L_ptr_queue_helper:
    .4byte  queue_helper      ! queue commit helper function

    /* --- boundary was active: handle overlap with existing lock --- */
.L_boundary_active_path:
    mov.l @(8, r14), r3       ! r3 = ctx->end_pos (+0x08)
    mov.l @r15, r2            ! r2 = local[+0] (stack top value)
    cmp/gt r2, r3             ! end_pos > stack value?
    bt      .L_end_exceeds_boundary ! if so, end exceeds current boundary
    jsr @r10                  ! call sym_06040FEA (release boundary lock)
    mov.l @(40, r12), r4      ! (delay slot) r4 = event handle
    mov.l @r13, r2            ! r2 = *game_state
    mov.w   .L_off_state_pos_b0_b, r0 ! r0 = 0xB0
    mov.l @(r0, r2), r3       ! r3 = game_state[0xB0] (position B)
    mov.l @r15, r2            ! r2 = stack top value
    cmp/gt r2, r3             ! state_pos_B > stack value?
    bt      .L_boundary_within_range ! if so, position is within range
    mov.l @r13, r2            ! r2 = *game_state
    mov r2, r3                ! r3 = *game_state (copy)
    mov.w   .L_off_state_pos_b0_b, r0 ! r0 = 0xB0
    mov.l @(r0, r3), r1       ! r1 = game_state[0xB0]
    add #-0x4, r0             ! r0 = 0xAC
    mov.l r1, @(r0, r2)       ! game_state[0xAC] = game_state[0xB0] (copy B->A)
    bra     .L_epilogue       ! done -- batch complete
    mov #0x2, r0              ! (delay slot) return code = 2

    /* --- boundary within range: no action needed --- */
.L_boundary_within_range:
    bra     .L_epilogue
    mov #0x0, r0              ! (delay slot) return code = 0 (continue)

    /* --- end position exceeds current boundary --- */
.L_end_exceeds_boundary:
    mov.l @r13, r3            ! r3 = *game_state
    mov.l @r15, r2            ! r2 = stack top value
    mov.w   .L_off_state_pos_ac_c, r0 ! r0 = 0xAC
    mov.l @(r0, r3), r3       ! r3 = game_state[0xAC] (position A)
    sub r3, r2                ! r2 = stack_val - position_A (delta)
    mov.l @(32, r14), r3      ! r3 = ctx->target_limit
    cmp/ge r3, r2             ! delta >= target_limit?
    bf      .L_check_enqueue_result ! if not, check enqueue status
    jsr @r10                  ! call sym_06040FEA (release boundary lock)
    mov.l @(40, r12), r4      ! (delay slot) r4 = event handle
    bra     .L_epilogue       ! done -- batch complete
    mov #0x2, r0              ! (delay slot) return code = 2

    /* --- check if enqueue produced any result --- */
.L_check_enqueue_result:
    tst r9, r9                ! enqueued count == 0?
    bf      .L_return_continue ! if nonzero, return continue
    jsr @r10                  ! call sym_06040FEA (release boundary lock)
    mov.l @(40, r12), r4      ! (delay slot) r4 = event handle
    bra     .L_epilogue       ! nothing enqueued -- abort
    mov #0x6, r0              ! (delay slot) return code = 6

    /* --- return with code 0 (continue processing) --- */
.L_return_continue:
    mov #0x0, r0              ! return code = 0 (continue)

    /* --- function epilogue: deallocate frame, restore registers --- */
.L_epilogue:
    add #0x1C, r15            ! deallocate 0x1C local frame
    lds.l @r15+, pr           ! restore return address
    mov.l @r15+, r8           ! restore r8
    mov.l @r15+, r9           ! restore r9
    mov.l @r15+, r10          ! restore r10
    mov.l @r15+, r11          ! restore r11
    mov.l @r15+, r12          ! restore r12
    mov.l @r15+, r13          ! restore r13
    rts                       ! return to caller
    mov.l @r15+, r14          ! (delay slot) restore r14

    /* --- trailing constant pool --- */
.L_off_state_pos_b0_b:
    .2byte  0x00B0            ! offset 0xB0 into game state
.L_off_state_pos_ac_c:
    .2byte  0x00AC            ! offset 0xAC into game state
