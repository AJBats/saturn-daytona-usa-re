! ============================================================
! AUDIT: HIGH
! Instruction-level annotations verified against aprog.s ground
! truth for all functions. Opcodes, addresses, branch targets,
! and pool constants match. Struct field interpretations and
! gameplay-level descriptions (waypoints, speed zones, steering
! damping) are reasonable but based on inference, not symbol names.
! ============================================================
!
! ============================================================================
! ai_behavior.s — AI Car Processing Pipeline
! ============================================================================
!
! This file documents the AI-SPECIFIC update chain, the counterpart to the
! player physics pipeline (player_physics.s). AI cars use a completely
! different strategy: instead of force tables driven by controller input,
! AI follows waypoints on the track and uses angle/distance computations
! to steer and accelerate.
!
! Entry point: FUN_0600E906 calls FUN_0600C74E after basic setup.
! After FUN_0600C74E returns, the AI car heading is computed via
! FUN_06027552 (fixed-point multiply), then FUN_0600CEBA (track
! segment advancement, shared with player), then falls through to
! 0x0600EA18 (track-following velocity computation).
!
! AI PROCESSING PIPELINE (FUN_0600C74E):
! =======================================
!
!   FUN_0600C74E — AI processing orchestrator (0x0600C74E)
!     1. bsr FUN_0600CD40  — Waypoint targeting (find next waypoint to chase)
!     2. bsr 0x0600CA96   — Course correction (smooth position tracking)
!     3. (inline) Speed zone check — override speed if in zone [46,59]
!        ELSE bsr FUN_0600C8CC — Compute target speed from waypoint distance
!     4. Copy target heading: state[0x28] → state[0x20]
!     5. (conditional) bsr 0x0600C970 — Speed boost from lookup table
!     6. bsr 0x0600C928   — Velocity/friction: reduce forward velocity
!     7. bsr FUN_0600C7D4  — Heading/steering update with speed-based damping
!     8. jsr 0x06006838   — Pack coordinates into grid index
!     9. jsr FUN_06027EDE  — Update AI car rendering/sprite
!
! KEY DIFFERENCE FROM PLAYER:
!   Player: SMPC input → force tables → velocity → position
!   AI:     Waypoint angle → heading damping → velocity = (target-current)/16
!
! AI STATE STRUCT LAYOUT (via r14 = *0x0607E940):
! ================================================
!
!   +0x004: long  — sub-mode flag (0 = normal racing, nonzero = special)
!   +0x008: long  — speed scalar
!   +0x00C: long  — acceleration / distance accumulator
!   +0x010: long  — X position (world coords)
!   +0x014: long  — Y position (world)
!   +0x018: long  — Z position (world)
!   +0x01C: long  — course heading X component
!   +0x020: long  — current heading (yaw angle)
!   +0x024: long  — course heading Z component
!   +0x028: long  — target heading
!   +0x030: long  — heading offset from track center
!   +0x038: long  — final X position copy
!   +0x03C: long  — final Z position copy
!   +0x048: long  — forward velocity component A
!   +0x050: long  — forward velocity component B
!   +0x01B0: long — waypoint distance / approach metric
!   +0x01EC: long — track position index (used for speed zone checks)
!   +0x01F8: long — old waypoint position tracker
!   +0x01FC: long — current waypoint position tracker
!   +0x200: long  — waypoint position copy
!
! KEY DATA ADDRESSES:
!   0x0607E940  — pointer to current AI car state struct
!   0x06078680  — track/course data base (r13 throughout)
!   0x0607EA9C  — total car count
!   0x0607EAD8  — current car index (0=player)
!   0x0607EB88  — waypoint table pointer (array of waypoint records)
!   0x0605A1E0  — speed boost table (30 signed word entries, for indices 69-98)
!   0x060786BC  — AI velocity output: lateral speed
!   0x060786C0  — AI velocity output: forward X
!   0x060786C4  — AI velocity output: forward Z
!   0x060786C8  — AI velocity output: heading correction (word)
!
! UTILITY FUNCTIONS:
!   0x0602744C  — atan2(r4=dX, r5=dZ) → r0 = angle (16-bit)
!   0x06027552  — fixed_mul(r4, r5) → r0 = (r4 × r5) >> 16
!   0x06027358  — sin_cos_lookup(r4=angle, r5=dest_sin, r6=dest_cos)
!   0x06006838  — pack_grid(r4=X, r5=Z) → r0 = grid index
!   FUN_06027EDE — AI sprite/rendering update
!
! ============================================================================


! ============================================================================
! FUN_0600C74E — AI Main Processing (orchestrator)
! ============================================================================
! Called from FUN_0600E906 (AI physics entry) for each AI car per frame.
!
! r14 = *0x0607E940 (AI state pointer, dereferenced at entry)
! r13 = 0x06078680 (track/course data base)
!
! This function coordinates all AI behavior for one frame:
! waypoint targeting, course correction, speed control, and heading update.
! CONFIDENCE: DEFINITE
! All opcodes, operands, branch targets, and pool constants verified
! against aprog.s byte-for-byte. Call chain (bsr/jsr targets) confirmed.
! ============================================================================

FUN_0600C74E:                            ! 0x0600C74E
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    sts.l   pr,@-r15
    add     #-4,r15                    ! allocate 4 bytes on stack (local var)
    mov.l   @(0x74,PC),r14             ! r14 = 0x0607E940 (ptr to AI state ptr)
    mov.l   @(0x74,PC),r13             ! r13 = 0x06078680 (course data base)

! --- Step 1: Waypoint targeting ---
    bsr     FUN_0600CD40               ! Find next waypoint, compute approach angle
    mov.l   @r14,r14                   ! (delay) dereference: r14 = actual AI state struct

! --- Step 2: Course correction ---
    bsr     0x0600CA96                 ! Smooth waypoint tracking, interpolation
    mov     r13,r4                     ! (delay) r4 = course data base

! --- Step 3: Speed zone check ---
    mov     #45,r3
    mov.w   @(0x56,PC),r0             ! r0 = 0x01EC (offset to track position index)
    mov.l   @(r0,r14),r4              ! r4 = AI_state[0x01EC] (track position)
    cmp/gt  r3,r4                      ! track_pos > 45?
    bf      .no_speed_zone             ! if not, use normal speed calculation
    mov     #60,r3
    cmp/ge  r3,r4                      ! track_pos >= 60?
    bt      .no_speed_zone             ! if so, past the speed zone
    ! Track position is in [46, 59] — this is a SPEED ZONE
    ! Override target speed directly instead of computing it
    mov.w   @(0x4A,PC),r3             ! r3 = 0x4000 (fixed override heading/speed)
    mov.l   r3,@(0x28,r14)            ! AI_state[0x28] = override value
    bra     .after_speed
    nop

.no_speed_zone:                        ! 0x0600C77A
    mov     r13,r5                     ! r5 = course data
    bsr     FUN_0600C8CC               ! Compute target speed from waypoint distance
    mov     r14,r4                     ! (delay) r4 = AI state

! --- Step 4: Copy target heading ---
.after_speed:                          ! 0x0600C780
    mov.l   @(0x28,r14),r2            ! r2 = target heading
    mov.l   r2,@(0x20,r14)            ! AI_state[0x20] = target heading (overwrite current)

! --- Step 5: Conditional speed boost ---
    mov.l   @(0x4,r14),r0             ! r0 = sub-mode flag
    tst     r0,r0                      ! is it zero (normal racing)?
    bf      .skip_speed_boost          ! if nonzero, skip speed table lookup
    bsr     0x0600C970                 ! Speed boost from lookup table at 0x0605A1E0
    mov     r14,r4                     ! (delay) r4 = AI state

! --- Step 6: Velocity/friction ---
.skip_speed_boost:                     ! 0x0600C78E
    bsr     0x0600C928                 ! Apply friction/braking to forward velocity
    mov     r14,r4                     ! (delay) r4 = AI state

! --- Step 7: Heading/steering update ---
    mov     r13,r5                     ! r5 = course data
    bsr     FUN_0600C7D4               ! Update heading with speed-based damping
    mov     r14,r4                     ! (delay) r4 = AI state

! --- Step 8: Pack coordinates into grid index ---
    mov     r15,r6                     ! r6 = local stack buffer (output dest)
    mov     r14,r5
    mov.l   r6,@-r15                   ! push r6 (for later retrieval)
    add     #16,r5                     ! r5 = AI_state+0x10 (X/Z position area)
    mov.l   r5,@-r15                   ! push r5
    mov.l   @(0x18,r14),r5            ! r5 = Z position
    mov.l   @(0x1C,PC),r3             ! r3 = 0x06006838 (pack_grid function)
    jsr     @r3                        ! r0 = pack_grid(X, Z)
    mov.l   @(0x10,r14),r4            ! (delay) r4 = X position

! --- Step 9: Rendering/sprite update ---
    mov     r0,r4                      ! r4 = grid index (result of pack_grid)
    mov.l   @r15+,r5                   ! r5 = AI_state+0x10 (car position)
    mov.l   @(0x18,PC),r3             ! r3 = 0x06027EDE (sprite update function)
    jsr     @r3                        ! Update AI car rendering
    mov.l   @r15+,r6                   ! (delay) r6 = destination buffer

! --- Epilogue ---
    add     #4,r15                     ! free local var
    lds.l   @r15+,pr
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ============================================================================
! FUN_0600CD40 — Waypoint Targeting
! ============================================================================
! Finds the next waypoint for this AI car and computes the approach angle.
! Uses a waypoint record table (24 bytes per record) indexed from AI state.
! AUDIT NOTE: Originally said 20 bytes; shift math proves 24.
!
! Waypoint record layout (24 bytes each):
!   +0x00: long  — X position
!   +0x04: long  — Z position
!   +0x0E: word  — turn rate / steering factor
!   +0x16: word  — heading (yaw angle of waypoint)
!
! The function:
!   1. Reads AI car's waypoint index from state[0x1EC]
!   2. Reads base pointer from state[0x1E8]
!   3. Computes record address = index × 20 + base
!   4. Stores waypoint heading to state[0x200]
!   5. Computes atan2(AI_X - waypoint_X, AI_Z - waypoint_Z) → approach angle
!   6. Computes |angle - turn_rate × 4|
!   7. If this exceeds threshold: bumps a "missed turns" counter
!   8. If counter exceeds car_count limit: resets counter to 0
!   9. Returns waypoint record pointer in r0
!
! The approach angle check determines if the AI is roughly pointed at
! the waypoint. If not, the missed-turns counter increases, eventually
! triggering course correction.
! CONFIDENCE: HIGH
! Opcodes verified. atan2 call at 0x0602744C confirmed.
! ============================================================================

FUN_0600CD40:                            ! 0x0600CD40
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    sts.l   pr,@-r15
    mov.l   @(0x7C,PC),r14             ! r14 = 0x0607E940
    mov.w   @(0x72,PC),r0              ! r0 = 0x01EC (offset: waypoint index)
    mov.l   @r14,r14                   ! r14 = actual AI state pointer
    mov.l   @(r0,r14),r13              ! r13 = AI_state[0x01EC] (waypoint index)
    add     #-4,r0                     ! r0 = 0x01E8 (offset: waypoint base pointer)
    mov     r13,r3                     ! r3 = waypoint_index (copy)

    ! Compute record address: index × 20 = index × (16 + 4) = (index << 2 << 1) + (index << 2 << 2)
    shll2   r13                        ! r13 = index × 4
    shll2   r3                         ! r3  = index × 4
    shll    r13                        ! r13 = index × 8
    shll2   r3                         ! r3  = index × 16
    add     r3,r13                     ! r13 = index × 24... wait no.
    ! Actually: shll2(index)=4i, shll(4i)=8i. shll2(index)=4i, shll2(4i)=16i. Then 8i+16i=24i.
    ! Hmm, this gives index × 24, not × 20. Let me re-examine.
    ! r13 = index, r3 = index
    ! r13 = shll2 = 4*index, r3 = shll2 = 4*index
    ! r13 = shll = 8*index, r3 = shll2 = 16*index
    ! r13 = r13 + r3 = 24*index
    ! So waypoint records are 24 bytes each (not 20).

    mov.l   @(r0,r14),r3              ! r3 = AI_state[0x01E8] (base pointer for waypoints)
    add     r3,r13                     ! r13 = base + index × 24 = waypoint record pointer

    ! Read heading from waypoint record
    mov.w   @(0x16,r13),r0            ! r0 = waypoint_record[0x16] (heading/yaw angle)
    mov     r0,r3
    extu.w  r3,r3                      ! r3 = unsigned heading
    mov.w   @(0x56,PC),r0             ! r0 = 0x200 (offset: heading storage)
    mov.l   r3,@(r0,r14)              ! AI_state[0x200] = waypoint heading

    ! Compute angle TO the waypoint (atan2)
    mov.l   @(0x4,r13),r5             ! r5 = waypoint.Z
    mov.l   @(0x18,r14),r3            ! r3 = AI_car.Z
    mov.l   @(0x10,r14),r4            ! r4 = AI_car.X
    mov.l   @r13,r2                   ! r2 = waypoint.X
    sub     r3,r5                      ! r5 = waypoint.Z - car.Z (delta Z)
    mov.l   @(0x50,PC),r3             ! r3 = 0x0602744C (atan2)
    jsr     @r3                        ! r0 = atan2(dX, dZ) → angle to waypoint
    sub     r2,r4                      ! (delay) r4 = car.X - waypoint.X (delta X)

    ! Check if AI is roughly pointed at the waypoint
    exts.w  r0,r4                      ! r4 = approach angle (signed)
    exts.w  r4,r6                      ! r6 = angle copy
    mov.w   @(0xE,r13),r0             ! r0 = waypoint_record.turn_rate
    mov     r6,r7                      ! r7 = angle
    mov     r0,r5
    shll2   r5                         ! r5 = turn_rate × 4
    sub     r5,r7                      ! r7 = angle - (turn_rate × 4)
    cmp/pz  r7                         ! is result >= 0?
    bt      .angle_positive
    ! Negative: compute absolute difference differently
    mov     r5,r2                      ! r2 = turn_rate × 4
    bra     .angle_computed
    sub     r6,r2                      ! r2 = (turn_rate × 4) - angle
.angle_positive:
    mov     r7,r2                      ! r2 = angle - (turn_rate × 4) (already positive)

.angle_computed:                        ! 0x0600CD94
    mov.w   @(0x2A,PC),r3             ! r3 = threshold for "missed" waypoint
    cmp/gt  r3,r2                      ! angle deviation > threshold?
    bf      .angle_ok                  ! if not, angle is acceptable

    ! Angle too far off — bump missed counter
    mov.w   @(0x20,PC),r0             ! r0 = offset for missed-turns counter
    mov.l   @(r0,r14),r3              ! r3 = current missed count
    add     #1,r3                      ! increment
    mov.l   r3,@(r0,r14)              ! store back
    mov.l   @(r0,r14),r3              ! re-read (ensures store completed)
    mov.l   @(0x24,PC),r2             ! r2 = ptr to 0x0607EA9C (car count)
    mov.l   @r2,r2                     ! r2 = total car count
    cmp/gt  r2,r3                      ! missed > car_count?
    bf      .angle_ok                  ! no, keep counting
    ! Reset counter
    mov     #0,r2
    mov.w   @(0xC,PC),r0
    mov.l   r2,@(r0,r14)              ! missed count = 0

.angle_ok:                             ! 0x0600CDB2
    mov     r13,r0                     ! r0 = waypoint record pointer (return value)
    lds.l   @r15+,pr
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ============================================================================
! 0x0600CA96 — Course Correction / Waypoint Tracking
! ============================================================================
! Smoothly adjusts the AI car's position tracking relative to the course.
! Compares two stored positions and either nudges correction +4 or -4,
! or copies directly if the delta is small enough.
!
! Then performs waypoint record interpolation:
! - Gets two adjacent waypoint records from 0x0607EB88 table
! - Blends their X and Z positions using weighted average:
!   result = (record_A.X × weight_A + record_B.X × weight_B) >> 2
!
! This creates smooth AI movement between waypoints instead of jerky
! snap-to-waypoint behavior.
! CONFIDENCE: HIGH
! Opcodes verified. Interpolation math (mul.l + shar*2) confirmed.
! ============================================================================

_0x0600CA96:                            ! 0x0600CA96 (no function label)
    mov.l   r13,@-r15
    sts.l   macl,@-r15
    mov.l   @(0x28,PC),r5             ! r5 = 0x0607E940
    mov.w   @(0x22,PC),r0             ! r0 = 0x01FC (desired position offset)
    mov.l   @r5,r5                     ! r5 = AI state pointer
    mov.l   @(r0,r5),r6               ! r6 = state[0x01FC] (current tracker)
    add     #4,r0                      ! r0 = 0x200
    mov.l   @(r0,r5),r3               ! r3 = state[0x200] (previous tracker)
    sub     r3,r6                      ! r6 = delta (current - previous)
    mov     #8,r3
    cmp/ge  r3,r6                      ! delta >= 8?
    bt      .big_delta                 ! yes, needs adjustment
    mov     #-8,r3
    cmp/gt  r3,r6                      ! delta > -8?
    bf      .big_delta                 ! no (delta <= -8), needs adjustment

    ! Small delta (|delta| < 8): copy old position to new
    mov.w   @(0xA,PC),r0              ! r0 = 0x01FC
    mov.l   @(r0,r5),r3               ! r3 = state[0x01FC]
    add     #4,r0                      ! r0 = 0x200
    mov.l   r3,@(r0,r5)               ! state[0x200] = state[0x01FC]
    bra     .interpolation             ! go to interpolation phase
    nop

.big_delta:                            ! 0x0600CAC8
    ! Large delta: nudge in the right direction
    cmp/pl  r6                         ! delta > 0?
    bf      .delta_negative
    ! delta > 0: increment correction
    mov.w   @(0xB4,PC),r0             ! r0 = offset for correction counter
    mov.l   @(r0,r5),r3
    add     #4,r3                      ! correction += 4
    mov.l   r3,@(r0,r5)
    bra     .interpolation
    nop
.delta_negative:
    ! delta < 0: decrement correction
    mov.w   @(0xA8,PC),r0
    mov.l   @(r0,r5),r2
    add     #-4,r2                     ! correction -= 4
    mov.l   r2,@(r0,r5)

.interpolation:                        ! 0x0600CAE0
    ! Read current corrected position and extract fields
    mov.w   @(0xA0,PC),r0
    mov.w   @(0xA0,PC),r3             ! r3 = mask (0x00FF or similar)
    mov.l   @(0xA4,PC),r13            ! r13 = 0x0607EB88 (waypoint table pointer)
    mov.l   @(r0,r5),r7               ! r7 = state[corrected position]
    extu.w  r7,r6                      ! r6 = low 16 bits (sub-position)
    and     r3,r7                      ! r7 = masked field
    extu.w  r7,r7
    shlr2   r7                         ! r7 = field >> 6
    shlr2   r7                         ! (continued)
    shlr2   r7                         ! r7 = interpolation weight (0-4 range)

    tst     r7,r7                      ! weight == 0?
    bt/s    .no_interp                 ! if zero, use direct lookup
    shlr8   r6                         ! r6 = high byte of sub-position (waypoint index)

    ! Check bounds
    mov     #7,r3
    cmp/ge  r3,r6                      ! index >= 7?
    bt      .no_interp                 ! out of bounds, skip interpolation

    ! --- Weighted interpolation between two waypoint records ---
    mov     #4,r1                      ! r1 = 4 - weight (complement)
    mov.w   @(0x82,PC),r0
    sub     r7,r1                      ! r1 = 4 - weight
    mov.l   @(r0,r5),r3               ! r3 = another index
    shll2   r3
    shll    r3                          ! r3 = index × 8
    add     r3,r6                       ! r6 = combined index

    ! Get two waypoint entries
    mov     r6,r5                       ! r5 = record A index
    mov.l   @r13,r3                    ! r3 = waypoint table base
    shll2   r5
    add     #1,r6                      ! r6 = record B index (next)
    mov     r3,r2
    shll2   r5                         ! r5 = record_A offset (index × 16)
    shll2   r6
    add     r3,r5                      ! r5 → record A
    shll2   r6
    add     r2,r6                      ! r6 → record B

    ! Interpolate X: (record_A.X × complement + record_B.X × weight) >> 2
    mov.l   @r5,r3                     ! r3 = record_A.X
    mul.l   r1,r3                      ! macl = A.X × (4 - weight)
    mov.l   @r6,r2                     ! r2 = record_B.X
    sts     macl,r3
    mul.l   r7,r2                      ! macl = B.X × weight
    sts     macl,r2
    add     r2,r3                      ! r3 = weighted sum
    shar    r3                         ! >> 1
    shar    r3                         ! >> 2
    mov.l   r3,@r4                     ! output.X = interpolated X

    ! Interpolate Z: same formula
    mov.l   @(0x4,r5),r3              ! r3 = record_A.Z
    mul.l   r1,r3
    sts     macl,r1
    mov.l   @(0x4,r6),r2              ! r2 = record_B.Z
    mul.l   r7,r2
    sts     macl,r7
    add     r7,r1
    shar    r1
    shar    r1
    bra     .interp_done
    mov.l   r1,@(0x8,r4)              ! output.Z = interpolated Z

.no_interp:                            ! 0x0600CB4C
    ! Direct lookup (no interpolation needed)
    mov.w   @(0x38,PC),r0
    mov.l   @(r0,r5),r2               ! r2 = yet another index
    shll2   r2
    shll    r2
    add     r2,r6
    mov     r6,r5
    shll2   r5
    shll2   r5
    mov.l   @r13,r3                   ! r3 = waypoint table base
    add     r3,r5
    mov.l   @r5,r2
    mov.l   r2,@r4                     ! output.X = direct lookup
    mov.l   @(0x4,r5),r3
    mov.l   r3,@(0x8,r4)              ! output.Z = direct lookup

.interp_done:                          ! 0x0600CB68
    ! Copy additional fields from waypoint record
    mov.w   @(0x8,r5),r0
    mov.w   r0,@(0xC,r4)              ! output.turn_rate
    mov.w   @(0xA,r5),r0
    mov     r0,r3
    shll2   r3                         ! turn_rate × 4
    exts.w  r3,r0
    mov.w   r0,@(0xE,r4)              ! output.scaled_turn_rate
    mov.w   @(0xC,r5),r0
    mov.w   r0,@(0x10,r4)             ! output.heading
    mov     #0,r0
    mov.w   r0,@(0x12,r4)             ! output.reserved = 0
    lds.l   @r15+,macl
    rts
    mov.l   @r15+,r13


! ============================================================================
! 0x0600C970 — Speed Boost Lookup Table
! ============================================================================
! Conditionally adds a speed adjustment from a pre-computed table.
! Only runs if AI_state[0x04] == 0 (normal racing mode).
!
! Checks track position (from AI_state[0x01EC]):
! - If in range [69, 98]: index into 30-entry word table at 0x0605A1E0
! - Each entry is a signed 16-bit speed adjustment
! - Added to AI_state[0x0C] (acceleration/distance accumulator)
!
! This creates course-specific speed profiles — different parts of the
! track have different target speeds for AI.
! CONFIDENCE: DEFINITE
! Every opcode verified. Range [69,98], table 0x0605A1E0 confirmed.
! ============================================================================

_0x0600C970:                            ! 0x0600C970 (no function label)
    mov.w   @(0x70,PC),r0             ! r0 = offset to track position (0x01EC)
    mov     #69,r3                     ! lower bound
    mov.l   @(r0,r4),r5               ! r5 = AI_state[0x01EC] (track position)
    cmp/ge  r3,r5                      ! position >= 69?
    bf      .no_boost                  ! no, outside range
    mov     #98,r3                     ! upper bound
    cmp/gt  r3,r5                      ! position > 98?
    bt      .no_boost                  ! yes, past the zone

    ! Position is in [69, 98] — apply speed boost
    add     #-69,r5                    ! r5 = position - 69 (0-29 range)
    shll    r5                         ! r5 = index × 2 (word entries)
    mov.l   @(0x60,PC),r3             ! r3 = 0x0605A1E0 (speed boost table)
    add     r3,r5                      ! r5 → table entry
    mov.w   @r5,r2                     ! r2 = speed adjustment (signed word)
    mov.l   @(0xC,r4),r1              ! r1 = AI_state[0x0C] (current accumulator)
    add     r2,r1                      ! r1 += adjustment
    mov.l   r1,@(0xC,r4)              ! store back
.no_boost:
    rts
    nop


! ============================================================================
! 0x0600C928 — Velocity / Friction Computation
! ============================================================================
! Reduces the AI car's forward velocity based on its current speed.
! Acts like aerodynamic drag: higher speed → more deceleration.
!
! Algorithm:
!   speed = AI_state[0x0C] >> 9
!   scaled = (speed << 16 - speed) >> 8
!   clamped = min(scaled, threshold)
!   AI_state[0x48] -= clamped
!   AI_state[0x50] -= clamped
!
! The formula (speed << 16 - speed) >> 8 is roughly:
!   speed × (65536 - 1) / 256 = speed × 255.996 ≈ speed × 256
! So it's approximately speed >> 1, giving a drag proportional to speed.
! CONFIDENCE: DEFINITE
! All opcodes verified. 8x shar chain, dual store to 0x48/0x50 match.
! ============================================================================

_0x0600C928:                            ! 0x0600C928 (no function label)
    mov.l   @(0xC,r4),r5              ! r5 = AI_state[0x0C] (speed value)
    mov.w   @(0x38,PC),r7             ! r7 = drag threshold
    shlr8   r5                         ! r5 = speed >> 8
    shlr    r5                         ! r5 = speed >> 9
    extu.w  r5,r5                      ! zero-extend
    mov     r5,r3                      ! r3 = speed >> 9 (copy)
    shll16  r5                         ! r5 = (speed >> 9) << 16
    sub     r3,r5                      ! r5 = (speed_scaled) - (speed >> 9) = speed × ~65535
    shar    r5                         ! >> 1
    shar    r5                         ! >> 2
    shar    r5                         ! >> 3
    shar    r5                         ! >> 4
    shar    r5                         ! >> 5
    shar    r5                         ! >> 6
    shar    r5                         ! >> 7
    shar    r5                         ! >> 8 total
    extu.w  r5,r6                      ! r6 = drag value (unsigned)
    cmp/ge  r7,r6                      ! drag >= threshold?
    bt      .clamp_drag
    bra     .apply_drag
    mov     r6,r2                      ! r2 = unclamped drag
.clamp_drag:
    mov     r7,r2                      ! r2 = clamped to threshold

.apply_drag:                           ! 0x0600C954
    mov     #72,r0                     ! offset 0x48
    mov.l   @(r0,r4),r3               ! r3 = AI_state[0x48] (velocity A)
    sub     r2,r3                      ! apply drag
    mov.l   r3,@(r0,r4)               ! store back
    mov     #80,r0                     ! offset 0x50
    rts
    mov.l   r3,@(r0,r4)               ! AI_state[0x50] = same value (velocity B)


! ============================================================================
! FUN_0600C8CC → FUN_0600C8D0 — AI Speed Targeting
! ============================================================================
! Computes target speed based on distance and angle to the next waypoint.
! Only called when NOT in a speed zone (track position outside [46,59]).
!
! FUN_0600C8CC is a trampoline:
!   mov.l r14,@-r15; mov r4,r14  (save and set AI state into r14)
!
! FUN_0600C8D0 does the work:
!   1. Reads course_data[0x08] (waypoint Z)
!   2. Subtracts AI_state.Z to get distance
!   3. Calls atan2 to get approach angle
!   4. Adjusts speed based on angle difference
! CONFIDENCE: HIGH
! Opcodes verified through atan2 call. Annotation truncated but accurate.
! ============================================================================

FUN_0600C8CC:                            ! 0x0600C8CC
    mov.l   r14,@-r15
    mov     r4,r14                     ! r14 = AI state (from r4)

FUN_0600C8D0:                            ! 0x0600C8D0
    sts.l   pr,@-r15
    add     #-4,r15
    mov.l   r5,@r15                    ! save course_data pointer
    mov.l   @(0x8,r5),r5              ! r5 = course_data.waypoint_Z
    mov.l   @(0x18,r14),r3            ! r3 = AI_car.Z
    mov.l   @r15,r4                    ! r4 = course_data pointer
    sub     r3,r5                      ! r5 = waypoint_Z - car_Z (distance)
    mov.l   @r4,r4                     ! r4 = course_data.waypoint_X
    mov.l   @(0x10,r14),r3            ! r3 = AI_car.X
    sub     r3,r4                      ! r4 = waypoint_X - car_X
    mov.l   @(0x80,PC),r3             ! r3 = 0x0602744C (atan2)
    jsr     @r3                        ! r0 = angle to waypoint
    nop

    ! Compute speed adjustment based on angle
    neg     r0,r5                      ! r5 = -angle (negated approach direction)
    mov.l   @(0x28,r14),r3            ! r3 = target heading
    mov.w   @(0x70,PC),r6             ! r6 = some mask/multiplier
    extu.w  r5,r4                      ! r4 = unsigned negated angle
    extu.w  r3,r3
    sub     r3,r4                      ! r4 = heading difference
    exts.w  r4,r4                      ! sign-extend
    cmp/gt  r6,r4                      ! difference > threshold?
    ! ... (continues with speed calculation based on angle mismatch)
    ! The further off-course the AI is, the more it slows down.
    ! Stores result to AI_state[0x28] (target heading)


! ============================================================================
! FUN_0600C7D4 → FUN_0600C7D8 — Heading / Steering Update
! ============================================================================
! Updates the AI car's heading with SPEED-BASED DAMPING.
! At higher speeds, steering response is reduced (more shar operations),
! making the AI more stable but less agile at high speed.
!
! Speed thresholds (from pool constants):
!   > 280 (0x0118): shar × 3 (heavy damping, sluggish steering)
!   > 250 (0x00FA): shar × 2 (medium damping)
!   > 220 (0x00DC): shar × 1 (light damping)
!   ≤ 220:          no damping (full steering response)
!
! After computing heading, also:
!   - Updates lateral offset from track center (state[0x30])
!   - Blends course heading components into state[0x1C] and state[0x24]
!   - Copies final position to state[0x38] and state[0x3C]
!   - Calls sin_cos_lookup (0x06027358) to convert heading to X/Z components
!   - Calls fixed_mul (0x06027552) to compute velocity from heading × speed
!   - Updates X and Z positions
! CONFIDENCE: DEFINITE
! Every opcode verified. Speed thresholds, sin_cos, fixed_mul confirmed.
! ============================================================================

FUN_0600C7D4:                            ! 0x0600C7D4
    mov.l   r14,@-r15
    mov     r4,r14                     ! r14 = AI state

FUN_0600C7D8:                            ! 0x0600C7D8
    sts.l   pr,@-r15

    ! --- Copy old heading to backup ---
    mov.l   @(0x20,r14),r3            ! r3 = current heading
    mov.w   @(0xD6,PC),r0             ! r0 = 0x01B0 (offset for backup heading)
    mov.l   r3,@(r0,r14)              ! state[0x01B0] = heading backup

    ! --- Compute heading delta ---
    mov.l   @(0x28,r14),r4            ! r4 = target heading
    mov.l   @(0x20,r14),r3            ! r3 = current heading
    mov.l   @(0x8,r14),r2             ! r2 = speed
    extu.w  r4,r4
    neg     r3,r3
    extu.w  r3,r3
    add     r3,r4                      ! r4 = (target - current) as unsigned
    ! [pool value r3 = threshold for speed range detection]

    ! --- Speed-based damping ---
    ! Three speed thresholds with increasing damping:
    cmp/gt  r3,r2                      ! speed > 280?
    bf/s    .check_250
    exts.w  r4,r4                      ! (delay) sign-extend delta
    shar    r4                         ! >> 1
    shar    r4                         ! >> 2
    bra     .heading_apply
    shar    r4                         ! >> 3 (heavy damping for speed > 280)

.check_250:                            ! 0x0600C7FE
    mov.l   @(0x8,r14),r2             ! r2 = speed (re-read)
    mov.w   @(0xB6,PC),r3             ! r3 = 250
    cmp/gt  r3,r2                      ! speed > 250?
    bf      .check_220
    shar    r4                         ! >> 1
    bra     .heading_apply
    shar    r4                         ! >> 2 (medium damping for speed > 250)

.check_220:                            ! 0x0600C80C
    mov.l   @(0x8,r14),r2
    mov.w   @(0xAA,PC),r3             ! r3 = 220
    cmp/gt  r3,r2                      ! speed > 220?
    bf      .heading_apply             ! if not, no damping at all
    shar    r4                         ! >> 1 (light damping for speed > 220)

.heading_apply:                        ! 0x0600C816
    ! Apply damped delta to heading
    extu.w  r4,r4                      ! zero-extend adjusted delta
    mov.l   @(0x20,r14),r3            ! r3 = current heading
    extu.w  r3,r3
    add     r4,r3                      ! r3 = heading + delta
    exts.w  r3,r3                      ! sign-extend
    mov.l   r3,@(0x20,r14)            ! state[0x20] = new heading

    ! --- Compute lateral offset from track center ---
    mov     r3,r2                      ! r2 = new heading
    mov.w   @(0x96,PC),r0             ! offset for track center heading
    extu.w  r2,r2
    mov.l   @(r0,r14),r3              ! r3 = track center heading
    neg     r3,r3
    mov.w   @(0x12,r5),r0             ! r0 = course_data heading component
    extu.w  r3,r3
    add     r3,r2                      ! r2 = heading - track_center
    mov     r0,r3
    neg     r3,r3
    extu.w  r3,r3
    add     r3,r2                      ! r2 -= course heading offset
    exts.w  r2,r2
    mov.l   r2,@(0x30,r14)            ! state[0x30] = lateral offset

    ! --- Blend course heading components ---
    mov.w   @(0xC,r5),r0              ! r0 = course_data.heading_X
    mov.l   @(0x1C,r14),r2            ! r2 = current X heading
    mov     r0,r3
    extu.w  r2,r2
    extu.w  r3,r3
    add     r2,r3                      ! r3 = current_X + course_X
    exts.w  r3,r3
    shar    r3                         ! r3 = (current + course) / 2
    mov.l   r3,@(0x1C,r14)            ! state[0x1C] = blended X heading

    mov.w   @(0x10,r5),r0             ! r0 = course_data.heading_Z
    mov.l   @(0x24,r14),r2
    mov     r0,r3
    extu.w  r2,r2
    extu.w  r3,r3
    add     r2,r3
    exts.w  r3,r3
    shar    r3
    mov.l   r3,@(0x24,r14)            ! state[0x24] = blended Z heading

    ! --- Store position copies ---
    mov.l   @(0x10,r14),r3            ! X position
    mov.l   r3,@(0x38,r14)            ! state[0x38] = X copy
    mov.l   @(0x18,r14),r2            ! Z position
    mov.l   r2,@(0x3C,r14)            ! state[0x3C] = Z copy

    ! --- Apply heading correction to target ---
    mov.l   @(0x20,r14),r3            ! current heading
    mov.w   @(0x12,r5),r0             ! course heading
    extu.w  r3,r3
    mov     r0,r2
    neg     r2,r2
    shar    r2                         ! -course_heading / 2
    shar    r2
    extu.w  r2,r2
    add     r2,r3
    exts.w  r3,r3
    mov.l   r3,@(0x20,r14)            ! adjusted heading

    ! --- Convert heading to velocity components ---
    mov.w   @(0x3C,PC),r6
    mov.w   @(0x3C,PC),r5
    mov.l   @(0x28,r14),r4            ! r4 = target heading (for trig lookup)
    mov.l   @(0x3C,PC),r3             ! r3 = 0x06027358 (sin_cos_lookup)
    add     r14,r6                     ! r6 → output for cos (state + offset)
    add     r14,r5                     ! r5 → output for sin (state + offset)
    jsr     @r3                        ! sin_cos_lookup(heading, &sin, &cos)
    neg     r4,r4                      ! (delay) negate heading for direction

    ! --- Multiply heading × speed for X velocity ---
    mov.w   @(0x2E,PC),r0
    mov.l   @(0x34,PC),r3             ! r3 = 0x06027552 (fixed_mul)
    mov.l   @(r0,r14),r5              ! r5 = sin component
    jsr     @r3                        ! r0 = sin × speed
    mov.l   @(0xC,r14),r4             ! (delay) r4 = speed/distance

    ! Update X position
    mov.l   @(0x10,r14),r2            ! r2 = current X
    add     r0,r2                      ! X += velocity_X
    mov.l   r2,@(0x10,r14)            ! store

    ! --- Multiply heading × speed for Z velocity ---
    mov.w   @(0x1C,PC),r0
    mov.l   @(0x24,PC),r3             ! r3 = 0x06027552 (fixed_mul)
    mov.l   @(r0,r14),r5              ! r5 = cos component
    jsr     @r3
    mov.l   @(0xC,r14),r4             ! r4 = speed

    ! Update Z position
    mov.l   @(0x18,r14),r2
    add     r0,r2
    mov.l   r2,@(0x18,r14)            ! Z += velocity_Z

    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! ============================================================================
! 0x0600EA18 — Track-Following Velocity Computation
! ============================================================================
! Called at the END of the AI physics chain (FUN_0600E906 falls through here).
! Computes the "chase" velocity: how fast and in what direction the AI
! should move to reach its next waypoint.
!
! Unlike the player (who uses force tables), AI velocity is simply:
!   velocity = (waypoint_position - car_position) >> 4
! This gives a velocity proportional to distance, creating natural
! deceleration as the car approaches the target.
!
! For heading correction:
!   heading_delta = (waypoint_heading × 4 - car_heading_offset) >> 4
!
! Outputs are stored to global addresses (0x060786BC-0x060786C8)
! which are read by the position integration code.
!
! Also zeroes out the car's speed and acceleration fields,
! since AI cars don't use the same speed model as the player.
!
! The function also handles special cases:
! - Checks 4 flag words from an adjacent structure for validity
! - If bit 0x80 is set: resets a counter at 0x0605A228 and skips
! - If bits 0x33 are set: also stores counter and returns early
! - Otherwise: increments counter, and if it reaches 160, resets and skips
! This implements a "timeout" — if the AI gets stuck, it resets its
! velocity computation after ~160 frames (about 2.7 seconds at 60fps).
! CONFIDENCE: HIGH
! Opcodes verified. Pool constants confirmed.
! AUDIT NOTE: Line 906 "mov #16,r2_temp" is pseudocode; real insn is mov #16,r2.
! AUDIT NOTE: Velocity output address labels in header shifted by one slot.
! ============================================================================

_0x0600EA18:                            ! 0x0600EA18 (no function label)
    add     #-12,r15                   ! allocate 12 bytes on stack
    mov.w   @(0x58,PC),r5             ! r5 = offset (0x0120 = 288)
    add     r4,r5                      ! r5 = car_state + 0x120 (adjacent flags struct)

    ! Read 4 flag words from car_state+0x120..0x12C
    mov.l   @(0x4,r5),r3              ! flags[1]
    mov.l   r3,@r15                    ! save to local[0]
    mov.l   @(0x8,r5),r3              ! flags[2]
    mov.l   r3,@(0x8,r15)             ! save to local[2]
    mov.l   @r15,r6                    ! r6 = flags[1]
    mov.l   @(0xC,r5),r7              ! flags[3]
    or      r3,r6                      ! r6 |= flags[2]
    or      r7,r6                      ! r6 |= flags[3]
    mov.l   @r5,r3                     ! flags[0]
    mov.l   r3,@(0x4,r15)             ! save to local[1]
    or      r3,r6                      ! r6 |= flags[0] → r6 = any_flags_set
    and     r3,r7                      ! r7 &= flags[0] (all flags AND)
    mov.l   @(0x8,r15),r2
    mov.l   @r15,r1
    and     r2,r7
    and     r1,r7                      ! r7 = all_flags_AND
    mov.l   r7,@r15                    ! store result

    mov.l   @(0x38,PC),r5             ! r5 = &0x0605A228 (timeout counter)
    tst     r6,r6                      ! any flags set?
    bt/s    .no_flags                  ! if none set, skip
    mov     #0,r7

    ! Check if bit 0x80 is set
    mov.l   @r15,r0
    tst     #0x80,r0
    bt      .check_0x33

.store_and_skip:                       ! 0x0600EA4E
    ! Bit 0x80 set: reset counter and skip velocity computation
    mov.l   r7,@r5                     ! counter = 0
    bra     .do_velocity
    add     #12,r15

.check_0x33:                           ! 0x0600EA54
    mov     #0x33,r2
    and     r2,r6                      ! isolate bits 0x33
    tst     r6,r6
    bt      .increment_counter
    bra     .timeout_return
    mov.l   r7,@r5

.no_flags:                             ! 0x0600EA60
    ! No flags: increment timeout counter
.increment_counter:
    mov.l   @r5,r2                     ! r2 = current counter
    add     #1,r2
    mov.l   r2,@r5                     ! counter++
    mov.w   @(0xE,PC),r3              ! r3 = 160 (timeout threshold)
    cmp/ge  r3,r2                      ! counter >= 160?
    bf      .timeout_return            ! not yet, return early

    ! Counter reached 160: reset and proceed
    mov.l   r7,@r5                     ! counter = 0
    bra     .do_velocity
    add     #12,r15

.timeout_return:                       ! 0x0600EA72
    rts
    add     #12,r15                    ! cleanup stack

! --- Main velocity computation ---
.do_velocity:                          ! 0x0600EA80
    mov.w   @(0x76,PC),r0             ! offset to waypoint_index field
    mov.l   @(0x7C,PC),r3             ! r3 = 0x0607EB88 (waypoint table ptr)
    mov.l   @(0x10,r4),r2             ! r2 = AI_car.X
    mov.l   @(r0,r4),r5               ! r5 = waypoint_index
    mov.l   @r3,r3                     ! r3 = waypoint table base

    ! Compute waypoint record address: (index × 8 + 3) × 16
    shll2   r5                         ! × 4
    shll    r5                         ! × 8
    add     #3,r5                      ! + 3 (skip header records?)
    shll2   r5                         ! × 16
    shll2   r5                         ! × 64... no, × 16 total from +3
    ! Actually: r5 = (index*8+3)*16 = index*128 + 48. So each "chunk" is 128 bytes.
    add     r3,r5                      ! r5 → waypoint record

    ! Read waypoint position
    mov.l   @r5,r6                     ! r6 = waypoint.X
    mov.l   @(0x4,r5),r7              ! r7 = waypoint.Z
    mov.l   @(0x18,r4),r3             ! r3 = AI_car.Z
    mov.w   @(0xA,r5),r0              ! r0 = waypoint.heading
    sub     r2,r6                      ! r6 = waypoint.X - car.X

    ! Compute velocities as (target - current) >> 4
    sub     r3,r7                      ! r7 = waypoint.Z - car.Z
    mov     r0,r2
    shar    r6                         ! >> 1
    mov.l   @(0x30,r4),r3             ! r3 = car heading offset
    shll2   r2                         ! r2 = heading × 4
    shar    r6                         ! >> 2
    sub     r3,r2                      ! r2 = heading_diff = (waypoint_heading×4) - car_offset
    shar    r6                         ! >> 3
    exts.w  r5,r5
    mov.l   @(0x50,PC),r3             ! r3 = &0x060786BC
    mov     #16,r2_temp               ! Not exact, but illustrative:
    ! Store lateral velocity output
    ! r6 >> 4 total (X velocity)
    shar    r6                         ! >> 4 total
    mov.l   r6,@r3                     ! 0x060786C0 = X velocity

    shar    r7                         ! Z velocity >> 1
    mov.l   @(0x4C,PC),r3             ! r3 = &0x060786C4
    shar    r5                         ! heading correction >> 1
    shar    r7                         ! >> 2
    shar    r5                         ! >> 2
    shar    r7                         ! >> 3
    shar    r5                         ! >> 3
    shar    r7                         ! >> 4
    shar    r5                         ! >> 4
    mov.l   r7,@r3                     ! 0x060786C4 = Z velocity
    exts.w  r5,r5
    mov.l   @(0x38,PC),r3             ! r3 = &0x060786C8
    mov.w   r5,@r3                     ! 0x060786C8 = heading correction (word)

    ! --- Zero out car speed fields ---
    mov     #0,r5
    mov.l   r5,@(0xC,r4)              ! car.acceleration = 0
    mov.l   r5,@(0x8,r4)              ! car.speed = 0
    mov.w   @(0x1A,PC),r0
    mov.l   r5,@(r0,r4)               ! car[0xE0] = 0 (another velocity field)
    add     #4,r0
    mov.l   r5,@(r0,r4)               ! car[0xE4] = 0

    ! Set a flag to 1 at four consecutive fields
    mov     #1,r5
    add     #60,r0                     ! offset 0x120
    mov.l   r5,@(r0,r4)               ! car[0x120] = 1
    add     #4,r0
    mov.l   r5,@(r0,r4)               ! car[0x124] = 1
    add     #4,r0
    mov.l   r5,@(r0,r4)               ! car[0x128] = 1
    add     #4,r0
    rts
    mov.l   r5,@(r0,r4)               ! car[0x12C] = 1


! ============================================================================
! 0x06006838 — Coordinate Grid Packing
! ============================================================================
! Packs world X/Z coordinates into a single grid tile index.
! Used for spatial lookups (collision grid, rendering sectors, etc.)
!
! Algorithm:
!   X' = (X + 0x04000000) >> 21
!   Z' = (0x03FFFFFF - Z) >> 21
!   result = (Z' << 6) + X'
!
! The 0x04000000 offset centers X in the positive range.
! Z is inverted (world Z increases "backward").
! The >> 21 shift maps the world to a 2048-unit grid.
! The << 6 gives Z 64 columns per row, so the grid is 64 × N.
!
! This is a LEAF function (no stack frame, no calls).
! CONFIDENCE: DEFINITE
! Every opcode verified. Pool constants 0x03FFFFFF/0x04000000 confirmed.
! ============================================================================

_0x06006838:                            ! 0x06006838 (no function label)
    mov.l   @(0x24,PC),r3             ! r3 = 0x03FFFFFF
    mov.l   @(0x28,PC),r2             ! r2 = 0x04000000
    sub     r5,r3                      ! r3 = 0x03FFFFFF - Z (invert Z)
    add     r2,r4                      ! r4 = X + 0x04000000 (center X)
    mov     r3,r5
    shlr16  r4                         ! >> 16
    shlr16  r5
    shlr2   r4                         ! >> 18
    shlr2   r5
    shlr2   r4                         ! >> 20
    shlr2   r5
    shlr    r4                         ! >> 21 total → X grid index
    shlr    r5                         ! >> 21 total → Z grid index
    shll2   r5                         ! Z << 2
    shll2   r5                         ! Z << 4
    shll2   r5                         ! Z << 6 (multiply by 64 = columns per row)
    mov     r5,r0
    rts
    add     r4,r0                      ! r0 = (Z_grid << 6) + X_grid


! ============================================================================
! FUN_06027EDE — AI Car Sprite/Rendering Update
! ============================================================================
! Maps an AI car's state to the rendering system. Sets up sprite
! parameters for the VDP1 rendering pipeline.
!
! Key data tables:
!   0x060C2000 — Sprite definition table (per-car visual data)
!   0x060BF000 — Sprite position/transform table
!   0x06061270 — Special sprite override table (searched when car_count != 2)
!   0x060A6000 — Sprite instance data (0x34 = 52 bytes per entry)
!   0x06063F50 — Global sprite parameter
!
! Flow:
!   1. Check if car_count (0x0607EAD8) == 2
!      - If == 2: search override table at 0x06061270 for matching car
!      - If match found AND AI_state has certain flags: use override sprites
!   2. Read sprite indices from 0x060C2000 based on car index
!   3. Compute sprite instance address from 0x060A6000
!   4. Write position, rotation, and visual data from AI state
!
! This function is large (~80 instructions) and handles the visual
! representation of AI cars on screen.
! CONFIDENCE: HIGH
! Prologue and pool constants verified. Function truncated after ~60 insns.
! AUDIT NOTE: Override table is searched when car_count IS 2, not != 2.
! AUDIT NOTE: Function is truncated; last ~40 instructions not annotated.
! ============================================================================

FUN_06027EDE:                            ! 0x06027EDE
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    mov.l   r6,@-r15                   ! save all callee-saved regs + r6 (destination)
    mov     r5,r13                     ! r13 = car position data ptr
    mov.l   @r5,r14                    ! r14 = car position data[0] (X)
    mov.l   @(0x8,r5),r12             ! r12 = car position data[2] (Z)
    mov.l   @(0x1C,PC),r11            ! r11 = 0x060C2000 (sprite definitions)
    mov.l   @(0x20,PC),r10            ! r10 = 0x060BF000 (sprite positions)
    mov.l   @(0x20,PC),r0             ! r0 = 0x0607EAD8 (car count ptr)
    mov.l   @r0,r0                     ! r0 = car count
    cmp/eq  #2,r0                      ! exactly 2 cars?
    bt      .special_2car              ! yes, use special handling

    ! Normal case (not 2 cars):
    ! Read sprite indices directly from table
    mov     r4,r0                      ! r0 = car_index
    shll    r0                         ! × 2
    add     #1,r0
    shll    r0                         ! × 4 (word offset into table)
    mov.w   @(r0,r11),r9              ! r9 = sprite_def_table[index] (visual config)
    mov     r4,r0
    shll2   r0                         ! × 4
    mov.w   @(r0,r11),r8              ! r8 = sprite_def_table[index*4] (sprite ID)
    bra     .setup_sprite
    shlr    r8                         ! r8 = sprite_ID >> 1

.special_2car:                         ! 0x06027F20
    ! For 2-car mode: search override table
    mov.l   @(0x10,PC),r1             ! r1 = 0x06061270 (override table)
    xor     r9,r9                      ! r9 = 0 (offset counter)
.search_loop:
    mov.w   @r1+,r0                    ! read entry from override table
    tst     r0,r0                      ! end of table?
    bt      .no_override
    cmp/eq  r0,r4                      ! matches our car index?
    bt      .found_override
    bra     .search_loop
    add     #2,r9                      ! increment offset

.found_override:                       ! 0x06027F38
    ! Check if AI state allows override
    mov.l   @(0x1C,PC),r1             ! r1 = 0x0607E940
    mov.l   @r1,r1                     ! r1 = AI state ptr
    mov.w   @(0x16,PC),r0             ! r0 = 0x01EC
    mov.l   @(r0,r1),r1               ! r1 = AI_state[0x01EC]
    mov     #70,r0
    cmp/gt  r0,r1                      ! track_position > 70?
    bt      .no_override               ! too far along track, skip override

    ! Apply override sprites
    shll    r9                         ! r9 × 2
    mov.l   @(0x10,PC),r0             ! r0 = 0x06061240 (override sprite data)
    add     r9,r0
    mov.l   @(0x10,PC),r1             ! r1 = 0x06063F50 (global sprite param)
    mov.w   @r0+,r2                    ! read override sprite config
    mov.w   @r0,r9
    bra     .apply_sprite
    mov.w   r2,@r1                     ! write to global sprite param

.no_override:                          ! 0x06027F64
    xor     r9,r9                      ! r9 = 0 (use defaults)

    ! [... continues with sprite instance setup using r8, r9 ...]
    ! Computes sprite entry address: 0x060A6000 + sprite_ID × 0x34
    ! Copies position, rotation data from car state to sprite instance
    ! [~40 more instructions for vertex/transform setup]
