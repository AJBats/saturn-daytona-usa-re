/* track_surface_validate -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06041B3C - 0x06041CC8
 *
 * Track surface validation state machine — 3-phase surface query and distance
 * computation for AI car track position updates.
 *
 * State machine (state stored at car_state[+0x030C]):
 *   State 1: Surface type query (track_surface_type_c) + checkpoint validate.
 *            Computes distance delta = result - base_distance, clamps to max
 *            threshold, stores to result pointer. If delta <= 0, resets state
 *            to 0, optionally clears completion pointer. Returns 0.
 *   State 2: Check completion flag (+0x34). Call track_surface_type_d with
 *            3 dereferenced position params. Validate checkpoint. Advance to 3.
 *   State 3: Call track_distance_calc on stack data. Validate checkpoint.
 *            Store shifted distance to result pointer. Reset state and
 *            completion flag to 0. Returns 0.
 *
 * Parameters:
 *   r4 = iteration counter pointer (incremented at each validation step)
 *
 * Returns:
 *   r0 = 0 (distance depleted / done), 1 (not in active state / fallthrough),
 *        2 (state 2 already complete or surface type failed)
 *
 * Persistent registers:
 *   r11 = ai_checkpoint_validate function pointer
 *   r12 = iteration counter pointer (passed as r4)
 *   r13 = constant 0 (used for reset/clear operations)
 *   r14 = car state base pointer (sym_060A5400, dereferenced)
 *
 * Car state struct offsets:
 *   +0x0034 = completion flag (state 2 guard)
 *   +0x0040 = checkpoint byte (written from validation result)
 *   +0x030C = state machine phase (0-3)
 *   +0x0310 = surface query parameter A
 *   +0x0314 = distance base value
 *   +0x0318 = max distance threshold
 *   +0x0320 = distance result pointer (indirect)
 *   +0x0324 = completion callback/flag pointer (indirect)
 */

    .section .text.FUN_06041B3C


    .global track_surface_validate
    .type track_surface_validate, @function
track_surface_validate:
    mov.l r14, @-r15             ! save r14 (callee-saved)
    mov.l r13, @-r15             ! save r13 (callee-saved)
    mov.l r12, @-r15             ! save r12 (callee-saved)
    mov #0x0, r13                ! r13 = 0 (constant zero for reset ops)
    mov.l r11, @-r15             ! save r11 (callee-saved)
    sts.l pr, @-r15              ! save return address
    add #-0x14, r15              ! allocate 20 bytes of stack frame
    mov.l   _pool_fn_checkpoint, r11  ! r11 = ai_checkpoint_validate
    mov.l   _pool_car_state_base, r14 ! r14 = &car_state_base (indirect ptr)
    mov.w   DAT_06041bc8, r1    ! r1 = 0x030C (state phase offset)
    mov.l @r14, r0               ! r0 = car_state (dereference base ptr)
    mov.l @(r0, r1), r0          ! r0 = car_state[+0x030C] = current phase
    cmp/eq #0x1, r0              ! === State 1: surface query + distance ===
    bf/s    .L_check_state2      ! not state 1 → skip to state 2 check
    mov r4, r12                  ! r12 = iteration counter ptr (delay slot)
    mov r15, r5                  ! r5 = stack ptr (output buffer for surface query)
    mov.l @r14, r4               ! r4 = car_state
    mov.w   _wpool_off_surface_param, r0 ! r0 = 0x0310 (surface param A offset)
    mov.l   _pool_fn_surface_type_c, r3 ! r3 = track_surface_type_c
    jsr @r3                      ! track_surface_type_c(car_state[+0x310], stack)
    mov.l @(r0, r4), r4          ! r4 = car_state[+0x0310] (delay: load param A)
    mov r15, r4                  ! r4 = stack + 8 (checkpoint output buffer)
    jsr @r11                     ! ai_checkpoint_validate(stack+8)
    add #0x8, r4                 ! (delay: adjust ptr to checkpoint area)
    mov.l @r14, r2               ! r2 = car_state
    mov r15, r3                  ! r3 = stack + 8
    mov #0x40, r0                ! r0 = 0x40 (checkpoint byte offset)
    add #0x8, r3                 ! r3 → checkpoint result byte on stack
    mov.b @r3, r1                ! r1 = checkpoint validation byte
    mov.b r1, @(r0, r2)          ! car_state[+0x40] = checkpoint byte
    mov.l @r12, r3               ! r3 = *counter
    add #0x1, r3                 ! counter++
    mov.l r3, @r12               ! store incremented counter
    mov.l @r14, r2               ! r2 = car_state
    mov.w   DAT_06041bcc, r0    ! r0 = 0x0314 (distance base offset)
    mov.l @(r0, r2), r3          ! r3 = car_state[+0x0314] = base distance
    mov.l @r15, r2               ! r2 = surface query result (from stack[0])
    sub r3, r2                   ! r2 = result - base_distance = delta
    mov.l r2, @r15               ! stack[0] = clamped delta (tentative)
    mov.l @r14, r4               ! r4 = car_state
    mov.w   _wpool_off_max_dist, r0 ! r0 = 0x0318 (max distance threshold offset)
    mov.l @(r0, r4), r4          ! r4 = car_state[+0x0318] = max threshold
    cmp/ge r4, r2                ! delta >= max threshold?
    bt      .L_clamp_to_max      ! yes → clamp delta to max
    bra     .L_store_distance    ! no → keep computed delta
    nop                          ! (delay slot)
.L_clamp_to_max:
    mov.l r4, @r15               ! stack[0] = max threshold (clamp)
.L_store_distance:
    mov.l @r14, r2               ! r2 = car_state
    mov.w   _wpool_off_result_ptr, r0 ! r0 = 0x0320 (result pointer offset)
    mov.l @(r0, r2), r3          ! r3 = car_state[+0x0320] = result ptr
    mov.l @r15, r2               ! r2 = clamped distance delta
    mov.l r2, @r3                ! *result_ptr = clamped delta
    mov.l @r15, r3               ! r3 = clamped delta
    cmp/pl r3                    ! delta > 0?
    bt      .L_distance_positive ! yes → distance still positive, advance state
    mov.l @r14, r2               ! --- distance depleted → reset state ---
    mov.w   DAT_06041bc8, r0    ! r0 = 0x030C (state phase offset)
    mov.l r13, @(r0, r2)         ! car_state[+0x030C] = 0 (reset phase)
    add #0x18, r0                ! r0 = 0x0324 (completion ptr offset)
    mov.l @r14, r3               ! r3 = car_state
    mov.l @(r0, r3), r0          ! r0 = car_state[+0x0324] = completion ptr
    tst r0, r0                   ! completion ptr == NULL?
    bt      .L_exit_zero         ! yes → skip clearing, just return 0
    mov.l @r14, r3               ! r3 = car_state
    mov.w   DAT_06041bd2, r0    ! r0 = 0x0324 (completion ptr offset, dup)
    mov.l @(r0, r3), r2          ! r2 = car_state[+0x0324] = completion ptr
    mov.l r13, @r2               ! *completion_ptr = 0 (clear completion)
.L_exit_zero:
    bra     .L_epilogue          ! → return 0
    mov #0x0, r0                 ! r0 = 0 (return value, delay slot)

    .global DAT_06041bc6
DAT_06041bc6:
    mov.b r0, @(r0, r3)         ! (orphan instruction in constant pool gap)

    .global DAT_06041bc8
DAT_06041bc8:
    .2byte  0x030C               /* car state offset: state machine phase */
_wpool_off_surface_param:
    .2byte  0x0310               /* car state offset: surface query param A */

    .global DAT_06041bcc
DAT_06041bcc:
    .2byte  0x0314               /* car state offset: distance base value */
_wpool_off_max_dist:
    .2byte  0x0318               /* car state offset: max distance threshold */
_wpool_off_result_ptr:
    .2byte  0x0320               /* car state offset: distance result pointer */

    .global DAT_06041bd2
DAT_06041bd2:
    .2byte  0x0324               /* car state offset: completion callback ptr */
_pool_fn_checkpoint:
    .4byte  ai_checkpoint_validate  /* checkpoint validation function */
_pool_car_state_base:
    .4byte  sym_060A5400            /* AI/game state base pointer (indirect) */
_pool_fn_surface_type_c:
    .4byte  track_surface_type_c    /* surface type query variant C */
.L_distance_positive:                ! --- distance > 0: check completion ptr ---
    mov.l @r14, r3               ! r3 = car_state
    mov.w   DAT_06041ca8, r0    ! r0 = 0x0324 (completion ptr offset)
    mov.l @(r0, r3), r0          ! r0 = car_state[+0x0324] = completion ptr
    tst r0, r0                   ! completion ptr == NULL?
    bf      .L_advance_state2    ! non-NULL → advance to state 2
    mov.l @r14, r3               ! --- NULL completion ptr → reset state ---
    mov.w   DAT_06041caa, r0    ! r0 = 0x030C (state phase offset)
    mov.l r13, @(r0, r3)         ! car_state[+0x030C] = 0 (reset phase)
    bra     .L_epilogue          ! → return 0
    mov r13, r0                  ! r0 = 0 (return value, delay slot)
.L_advance_state2:
    mov.l @r14, r3               ! r3 = car_state
    mov #0x2, r2                 ! r2 = 2 (next state)
    mov.w   DAT_06041caa, r0    ! r0 = 0x030C (state phase offset)
    mov.l r2, @(r0, r3)          ! car_state[+0x030C] = 2 (advance to state 2)
.L_check_state2:                      ! === State 2: surface type D query ===
    mov.l @r14, r0               ! r0 = car_state
    mov.w   DAT_06041caa, r1    ! r1 = 0x030C (state phase offset)
    mov.l @(r0, r1), r0          ! r0 = car_state[+0x030C] = current phase
    cmp/eq #0x2, r0              ! phase == 2?
    bf      .L_check_state3      ! no → skip to state 3 check
    mov.l @r14, r0               ! r0 = car_state
    mov.l @(52, r0), r0          ! r0 = car_state[+0x34] = completion flag
    cmp/eq #0x1, r0              ! already completed?
    bf      .L_state2_exec       ! no → execute state 2 logic
    bra     .L_epilogue          ! yes → return 2 (already done)
    mov #0x2, r0                 ! r0 = 2 (return value, delay slot)
.L_state2_exec:
    mov #0x1, r3                 ! r3 = 1
    mov.l @r14, r2               ! r2 = car_state
    mov.l r3, @(52, r2)          ! car_state[+0x34] = 1 (mark completion started)
    mov.l @r14, r6               ! --- load 3 position params for surface_type_d ---
    mov.w   _wpool_off_result_ptr_b, r0 ! r0 = 0x0320 (result ptr offset)
    mov.l @r14, r5               ! r5 = car_state (will index +0x0314)
    mov.l @r14, r4               ! r4 = car_state (will index +0x0310)
    mov.l   _pool_fn_surface_type_d, r3 ! r3 = track_surface_type_d
    mov.l @(r0, r6), r6          ! r6 = car_state[+0x0320] = result ptr
    add #-0xC, r0                ! r0 = 0x0314 (distance base offset)
    mov.l @r6, r6                ! r6 = *result_ptr (deref to get value)
    mov.l @(r0, r5), r5          ! r5 = car_state[+0x0314] = distance base
    add #-0x4, r0                ! r0 = 0x0310 (surface param A offset)
    jsr @r3                      ! track_surface_type_d(param_a, dist_base, *result_ptr)
    mov.l @(r0, r4), r4          ! r4 = car_state[+0x0310] (delay: load param A)
    mov r0, r4                   ! r4 = surface query result
    tst r4, r4                   ! result == 0 (success)?
    bt      .L_state2_checkpoint ! yes → validate checkpoint and advance
    bra     .L_epilogue          ! no → return 2 (surface type failed)
    mov #0x2, r0                 ! r0 = 2 (return value, delay slot)
.L_state2_checkpoint:
    mov r15, r4                  ! r4 = stack + 8 (checkpoint output buffer)
    jsr @r11                     ! ai_checkpoint_validate(stack+8)
    add #0x8, r4                 ! (delay: adjust to checkpoint area)
    mov.l @r14, r3               ! r3 = car_state
    mov r15, r2                  ! r2 = stack + 8
    add #0x8, r2                 ! r2 → checkpoint result byte
    mov.b @r2, r1                ! r1 = checkpoint validation byte
    mov #0x40, r0                ! r0 = 0x40 (checkpoint byte offset)
    mov.b r1, @(r0, r3)          ! car_state[+0x40] = checkpoint byte
    mov.l @r12, r3               ! r3 = *counter
    add #0x1, r3                 ! counter++
    mov.l r3, @r12               ! store incremented counter
    mov.l @r14, r2               ! r2 = car_state
    mov #0x3, r3                 ! r3 = 3 (next state)
    mov.w   DAT_06041caa, r0    ! r0 = 0x030C (state phase offset)
    mov.l r3, @(r0, r2)          ! car_state[+0x030C] = 3 (advance to state 3)
.L_check_state3:                      ! === State 3: distance calc + finalize ===
    mov.l @r14, r0               ! r0 = car_state
    mov.w   DAT_06041caa, r1    ! r1 = 0x030C (state phase offset)
    mov.l @(r0, r1), r0          ! r0 = car_state[+0x030C] = current phase
    cmp/eq #0x3, r0              ! phase == 3?
    bf      .L_fallthrough_exit  ! no → return 1 (not in any active state)
    mov r15, r4                  ! r4 = stack + 4 (distance input buffer)
    mov.l   _pool_fn_distance_calc, r3 ! r3 = track_distance_calc
    jsr @r3                      ! track_distance_calc(stack+4)
    add #0x4, r4                 ! (delay: adjust to distance data area)
    mov r0, r4                   ! r4 = distance calc result
    tst r4, r4                   ! result == 0 (success)?
    bt      .L_state3_finalize   ! yes → finalize and reset
    bra     .L_epilogue          ! no → return 1 (distance calc failed)
    mov #0x1, r0                 ! r0 = 1 (return value, delay slot)
.L_state3_finalize:
    mov r15, r4                  ! r4 = stack + 8 (checkpoint output buffer)
    jsr @r11                     ! ai_checkpoint_validate(stack+8)
    add #0x8, r4                 ! (delay: adjust to checkpoint area)
    mov.l @r14, r3               ! r3 = car_state
    mov r15, r2                  ! r2 = stack + 8
    mov #0x40, r0                ! r0 = 0x40 (checkpoint byte offset)
    add #0x8, r2                 ! r2 → checkpoint result byte
    mov.b @r2, r1                ! r1 = checkpoint validation byte
    mov.b r1, @(r0, r3)          ! car_state[+0x40] = checkpoint byte
    mov.l @r12, r3               ! r3 = *counter
    add #0x1, r3                 ! counter++
    mov.l r3, @r12               ! store incremented counter
    mov.l @r14, r2               ! r2 = car_state
    mov.w   DAT_06041caa, r0    ! r0 = 0x030C (state phase offset)
    mov.l r13, @(r0, r2)         ! car_state[+0x030C] = 0 (reset to idle)
    mov.l @r14, r3               ! r3 = car_state
    add #0x18, r0                ! r0 = 0x0324 (completion ptr offset)
    mov.l @(r0, r3), r2          ! r2 = car_state[+0x0324] = completion ptr
    mov.l @(4, r15), r3          ! r3 = stack[4] = distance calc raw value
    shll r3                      ! r3 <<= 1 (scale distance by 2)
    mov.l r3, @r2                ! *completion_ptr = scaled distance
    mov.l @r14, r3               ! r3 = car_state
    mov.l r13, @(52, r3)         ! car_state[+0x34] = 0 (clear completion flag)
    bra     .L_epilogue          ! → return 0
    mov r13, r0                  ! r0 = 0 (return value, delay slot)

    .global DAT_06041ca8
DAT_06041ca8:
    .2byte  0x0324               /* car state offset: completion callback ptr (dup) */

    .global DAT_06041caa
DAT_06041caa:
    .2byte  0x030C               /* car state offset: state machine phase (dup) */
_wpool_off_result_ptr_b:
    .2byte  0x0320               /* car state offset: result pointer (dup for reach) */
    .2byte  0xFFFF               /* alignment padding */
_pool_fn_surface_type_d:
    .4byte  track_surface_type_d    /* surface type query variant D */
_pool_fn_distance_calc:
    .4byte  track_distance_calc     /* track distance computation */
.L_fallthrough_exit:
    mov #0x1, r0                 ! r0 = 1 (not in any active state)
.L_epilogue:
    add #0x14, r15               ! deallocate 20-byte stack frame
    lds.l @r15+, pr              ! restore return address
    mov.l @r15+, r11             ! restore r11
    mov.l @r15+, r12             ! restore r12
    mov.l @r15+, r13             ! restore r13
    rts                          ! return to caller
    mov.l @r15+, r14             ! restore r14 (delay slot)
