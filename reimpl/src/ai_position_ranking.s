/* ai_position_ranking -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06014F34 - 0x0601503A
 *
 * AI position/ranking update — assigns position data to AI car slots
 * by iterating through a ranking table. Selects one of three table
 * variants depending on game state (0x19 = time attack) and display
 * mode flags (bit 0 toggles between two race-mode tables).
 *
 * Persistent registers:
 *   r12 = &countdown_timer (16-bit, sym_06085F94)
 *   r13 = ranking_table_ptr (one of three tables in data segment)
 *   r14 = &car_index (16-bit, sym_06085F90)
 *
 * Ranking table format (3 bytes per entry, indexed by car_index * 3):
 *   byte[0] = car type ID → written to slot_base[0]
 *   byte[1] = next countdown value → written to countdown_timer
 *   byte[2] = secondary flag → written to slot_base[+0x40]
 *
 * Termination:
 *   car type 0x15 → sets car_index = 0x64 (sentinel for "all done")
 *   countdown_timer reaching 0 → process next entry immediately
 *
 * Note: .word 0x0029/0x0129 are MOVT R0/R1 instructions (store T bit).
 * The L3 generator didn't decode these — they compute boolean results
 * from the preceding CMP instructions.
 */

    .section .text.FUN_06014F34


    .global ai_position_ranking
    .type ai_position_ranking, @function
ai_position_ranking:
    mov.l r14, @-r15                      ! save r14 (callee-saved)
    mov.l r13, @-r15                      ! save r13 (callee-saved)
    mov.l r12, @-r15                      ! save r12 (callee-saved)
    sts.l pr, @-r15                       ! save return address
    mov.l   _pool_countdown_timer, r12    ! r12 = &countdown_timer (16-bit)
    mov.l   _pool_car_index, r14          ! r14 = &car_index (16-bit)
    mov.l   _pool_rank_table_default, r13 ! r13 = default ranking table base
    mov.l   _pool_game_state, r5          ! r5 = &game_state
    mov.l @r5, r0                         ! r0 = current game state
    cmp/eq #0x19, r0                      ! is game state == 0x19 (time attack)?
    .word 0x0029 /* MOVT R0 */            ! r0 = T (1 if time attack, else 0)
    mov.l   _pool_display_flags, r3       ! r3 = &display_flags
    mov.l @r3, r3                         ! r3 = display_flags value
    and r3, r0                            ! r0 = time_attack & display_flags
    tst #0x1, r0                          ! test bit 0 of combined flags
    bt/s    .L_check_time_attack          ! if bit 0 clear → check time attack variant
    mov #0x23, r4                         ! r4 = 0x23 (35 = default max car count)
    mov.l   _pool_rank_table_mode_a, r13  ! r13 = mode-A ranking table (display bit set)
    bra     .L_table_selected             ! skip to table-selected
    mov #0x28, r4                         ! r4 = 0x28 (40 = mode-A max car count)
.L_check_time_attack:
    mov.l @r5, r0                         ! r0 = game state (re-read)
    cmp/eq #0x15, r0                      ! is game state == 0x15 (specific mode)?
    bf      .L_table_selected             ! if not → keep default table
    mov.l   _pool_rank_table_mode_b, r13  ! r13 = mode-B ranking table (state 0x15)
    mov #0x6, r4                          ! r4 = 0x6 (6 = mode-B max car count)
.L_table_selected:
    extu.b r4, r4                         ! zero-extend max_cars to 32-bit
    mov.w @r14, r5                        ! r5 = current car_index (16-bit)
    extu.w r5, r5                         ! zero-extend car_index to 32-bit
    cmp/gt r4, r5                         ! is car_index > max_cars?
    .word 0x0029 /* MOVT R0 */            ! r0 = T (1 if over limit, else 0)
    xor #0x1, r0                          ! r0 = !over_limit (1 if within range)
    mov r0, r3                            ! r3 = within_range flag
    mov r5, r0                            ! r0 = car_index
    cmp/eq #0x64, r0                      ! is car_index == 0x64 (done sentinel)?
    .word 0x0129 /* MOVT R1 */            ! r1 = T (1 if done)
    add #-0x1, r1                         ! r1 = done - 1 (0 if done, -1 if not)
    neg r1, r1                            ! r1 = 1 - done (0 if done, 1 if not) → not_done
    and r1, r3                            ! r3 = within_range & not_done
    tst r3, r3                            ! any work to do?
    bt      .L_epilogue                   ! if not → exit
    mov.l   _pool_frame_decrement, r3     ! r3 = &frame_decrement value
    mov.w @r12, r2                        ! r2 = current countdown_timer
    mov.l @r3, r3                         ! r3 = frame_decrement amount
    sub r3, r2                            ! r2 = countdown_timer - decrement
    mov.w r2, @r12                        ! store updated countdown_timer
    mov.w @r12, r3                        ! r3 = updated countdown_timer (re-read)
    cmp/pl r3                             ! is countdown_timer > 0?
    bt      .L_epilogue                   ! if still positive → exit (wait more frames)
.L_process_next_entry:
    mov.l   _pool_fn_data_lookup, r3      ! r3 = &vdp2_data_lookup function
    jsr @r3                               ! call vdp2_data_lookup(0) → get slot index
    mov #0x0, r4                          ! r4 = 0 (arg: query type)
    extu.b r0, r5                         ! r5 = slot_index (zero-extended byte)
    extu.b r5, r0                         ! r0 = slot_index (redundant zero-extend)
    cmp/eq #0x11, r0                      ! is slot_index == 0x11 (invalid/end)?
    bt      .L_epilogue                   ! if invalid → exit
    extu.b r5, r4                         ! r4 = slot_index
    mov.l   _pool_slot_data_base, r2      ! r2 = slot_data array base (sym_06084FC8)
    mov.w @r14, r0                        ! r0 = car_index
    mov r4, r3                            ! r3 = slot_index
    extu.w r0, r0                         ! zero-extend car_index
    shll2 r4                              ! r4 = slot_index * 4
    shll2 r3                              ! r3 = slot_index * 4
    shll2 r3                              ! r3 = slot_index * 16
    shll2 r3                              ! r3 = slot_index * 64
    add r3, r4                            ! r4 = slot_index * 68 (slot struct size)
    exts.w r4, r4                         ! sign-extend slot offset
    mov r0, r3                            ! r3 = car_index
    add r2, r4                            ! r4 = &slot_data[slot_index] (struct base)
    shll r0                               ! r0 = car_index * 2
    add r3, r0                            ! r0 = car_index * 3 (table entry offset)
    mov.b @(r0, r13), r2                  ! r2 = rank_table[car_index].car_type
    mov.b r2, @r4                         ! slot_data[slot].byte[0] = car_type
    mov.w @r14, r3                        ! r3 = car_index
    extu.w r3, r3                         ! zero-extend car_index
    mov r3, r2                            ! r2 = car_index
    shll r3                               ! r3 = car_index * 2
    add r2, r3                            ! r3 = car_index * 3
    add r13, r3                           ! r3 = &rank_table[car_index]
    mov.b @(2, r3), r0                    ! r0 = rank_table[car_index].secondary_flag
    mov r0, r1                            ! r1 = secondary_flag
    mov #0x40, r0                         ! r0 = 0x40 (offset within slot struct)
    mov.b r1, @(r0, r4)                   ! slot_data[slot].byte[0x40] = secondary_flag
    mov.w @r14, r3                        ! r3 = car_index
    extu.w r3, r3                         ! zero-extend car_index
    mov r3, r2                            ! r2 = car_index
    shll r3                               ! r3 = car_index * 2
    add r2, r3                            ! r3 = car_index * 3
    add r13, r3                           ! r3 = &rank_table[car_index]
    mov.b @(1, r3), r0                    ! r0 = rank_table[car_index].next_countdown
    mov r0, r3                            ! r3 = next_countdown (signed)
    extu.b r3, r3                         ! zero-extend to 16-bit clean value
    mov.w r3, @r12                        ! countdown_timer = next_countdown
    mov.w @r14, r3                        ! r3 = car_index
    add #0x1, r3                          ! r3 = car_index + 1 (advance to next entry)
    mov.w r3, @r14                        ! store updated car_index
    mov.b @r4, r0                         ! r0 = slot_data[slot].byte[0] (car_type just written)
    extu.b r0, r0                         ! zero-extend car_type
    cmp/eq #0x15, r0                      ! is car_type == 0x15 (end-of-sequence marker)?
    bf      .L_check_countdown            ! if not → check if more entries to process
    mov #0x64, r2                         ! r2 = 0x64 (done sentinel)
    mov.w r2, @r14                        ! car_index = 0x64 → mark sequence complete
.L_check_countdown:
    mov.w @r12, r3                        ! r3 = countdown_timer
    tst r3, r3                            ! is countdown_timer == 0?
    bf      .L_epilogue                   ! if nonzero → exit (wait for next call)
    bra     .L_process_next_entry         ! countdown expired → process next entry now
    nop
_pool_countdown_timer:
    .4byte  sym_06085F94                  ! countdown timer (16-bit word)
_pool_car_index:
    .4byte  sym_06085F90                  ! current car index (16-bit word)
_pool_rank_table_default:
    .4byte  sym_0605B73A                  ! default ranking table (35 entries)
_pool_game_state:
    .4byte  g_game_state                  ! game state variable (32-bit)
_pool_display_flags:
    .4byte  sym_0607EBF4                  ! display/mode flags (32-bit)
_pool_rank_table_mode_a:
    .4byte  sym_0605B7A6                  ! mode-A ranking table (40 entries, display bit set)
_pool_rank_table_mode_b:
    .4byte  sym_0605B821                  ! mode-B ranking table (6 entries, state 0x15)
_pool_frame_decrement:
    .4byte  sym_0606BDF8                  ! frame decrement value (32-bit)
_pool_fn_data_lookup:
    .4byte  vdp2_data_lookup              ! function: data lookup for slot assignment
_pool_slot_data_base:
    .4byte  sym_06084FC8                  ! slot data array base (68-byte structs)
.L_epilogue:
    lds.l @r15+, pr                       ! restore return address
    mov.l @r15+, r12                      ! restore r12
    mov.l @r15+, r13                      ! restore r13
    rts                                   ! return
    mov.l @r15+, r14                      ! restore r14 (delay slot)
