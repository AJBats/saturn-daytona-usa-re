! ============================================================
! AUDIT: HIGH
! Core race update chain. FUN_0600DE54 and FUN_0600E0C0 verified as real
! function labels. FUN_0600EA18, FUN_0600D0B8, and position integration
! at 0x0600E5AE are NOT separate function labels in aprog.s -- they are
! mid-function code (inline within FUN_0600E4F2/FUN_0600E71A). Annotations
! treat them as standalone functions which is misleading but the code
! analysis at those addresses is accurate. All AUDIT NOTEs resolved.
! Velocity calculation and position integration code verified byte-level.
! ============================================================
!
! ============================================================================
! race_update.s — Race State Update & Vehicle Physics
! ============================================================================
!
! This file covers the per-frame race update chain called during in-race
! gameplay states (14, 15, 17, 19). The chain processes physics, position
! updates, rendering, and race logic every frame.
!
! CALL CHAIN (from game_loop.s state 15):
!   FUN_06009098 (state handler)
!     → FUN_0600DE54 (race state update dispatcher)
!       → FUN_0600E99C (pre-update)
!       → FUN_0600E0C0 (main race frame)
!         → FUN_0600E1D4 or FUN_0600E4F2 (per-car update, calls physics chain)
!           → FUN_0600E71A (frame physics + position integration)
!             → FUN_06008318  (frame processing)
!             → FUN_0600C4F8  (race timer update)
!             → FUN_0600C5D6  (race position calculation)
!             → FUN_0600EA18  (velocity calculation)
!             → POSITION INTEGRATION (at 0x0600E5B4)
!               → FUN_06006838  (world→tile coordinate lookup)
!           → FUN_0600D780 (vehicle state — lap tracking, overtake detection)
!           → FUN_0600CE66 (collision/interaction?)
!           → FUN_0600DA7C (?)
!
! KEY DATA ADDRESSES:
!   0x0607E940  = "previous" car object pointer (copied from E944 each frame)
!   0x0607E944  = "current" car object pointer
!   0x0607E94C  = car object list (array of pointers, one per car)
!   0x0607EA98  = total car count (used as loop bound)
!   0x0607EBC4  = frame/state flags (bitmask, checked for state transitions)
!   0x060786B4  = physics state variable
!   0x060786BC  = steering/heading constant (gets 16 written to it)
!   0x060786C0  = velocity X (written by FUN_0600EA18, consumed by integrator)
!   0x060786C4  = velocity Z (written by FUN_0600EA18, consumed by integrator)
!   0x060786C8  = angular velocity (written by FUN_0600EA18, consumed by integrator)
!   0x06078635  = flag: if nonzero, skip position integration (pause/demo mode?)
!
! CAR OBJECT STRUCT (at pointer from 0x0607E944 or object list):
!   +0x00: long  — flags/type (bit 0x00C00000 checked for physics enable)
!   +0x10: long  — X position (fixed-point)
!   +0x14: long  — Y position (fixed-point)
!   +0x18: long  — Z position (fixed-point)
!   +0x1C: long  — rotation/heading A
!   +0x20: long  — rotation/heading B (primary heading used in physics)
!   +0x24: long  — rotation/heading C
!   +0x28: long  — heading copy (set = +0x20 each frame)
!   +0x30: long  — heading copy 2 (set = +0x20 each frame)
!   +0x200: long — physics field (compared between cars for clamping)
!   +0x204: long — physics field
!   +0x238: long — track progress counter
!   +0x23C: long — track progress counter (alt)
! ============================================================================


! ============================================================================
! CONFIDENCE: DEFINITE — fully verified against ground truth byte-for-byte
! Pool addresses confirmed: 0x0607EA98, 0x060786CA, 0x0607E944, 0x0607E940.
! bsr FUN_0600E99C and bra FUN_0600E0C0 confirmed. Delay slot pr restore confirmed.
! FUN_0600DE54 — Race State Update Dispatcher
! ============================================================================
! Small function: copies frame pointer, calls pre-update, then tail-calls
! into the main race update.
! Called from state handlers 14, 15, 17.

FUN_0600DE54:                       ! Race state update entry
    sts.l   pr,@-r15
    mov.l   @(0x5C,PC),r3         ! r3 -> 0x0607EA98 (car count / race data)
    mov.l   @(0x5C,PC),r2         ! r2 -> 0x060786CA
    mov.l   @r3,r3                 ! r3 = car count value
    shar    r3                     ! r3 >>= 1 (arithmetic — halve it)
    mov.w   r3,@r2                 ! Store halved count to 0x060786CA
    mov.l   @(0x58,PC),r1         ! r1 -> 0x0607E944 (current car pointer)
    mov.l   @(0x5C,PC),r2         ! r2 -> 0x0607E940 (previous car pointer)
    mov.l   @r1,r1                 ! r1 = current car object
    mov.l   r1,@r2                 ! previous = current (save for delta calcs)
    bsr     FUN_0600E99C           ! Call pre-update
    nop
    bra     FUN_0600E0C0           ! Tail-call into main race update
    lds.l   @r15+,pr              ! (delay slot) restore return address


! ============================================================================
! CONFIDENCE: HIGH — prologue and register assignments verified
! r8=0x0607EBC4, r9=0x06078900, r10=word from pool, r11=0x00008000,
! r12=0x0607E940, r14=0x06027CA4 all confirmed against ground truth.
! 0x0607EAE0 check for demo mode skip confirmed.
! FIXED: r14 = FUN_06027CA4 confirmed from pool constant at 0x0600E114.
! FUN_06027CA4 is a verified labeled function in aprog.s (3D scene renderer).
! FUN_0600E0C0 — Main Race Frame Update
! ============================================================================
! Iterates through all cars and processes physics/rendering for each.
! r8  = 0x0607EBC4 (frame flags)
! r9  = 0x06078900 (object data base)
! r12 = 0x0607E940 (car object pointer)
! r14 = 0x06027CA4 (3D scene processing function — called for each car)
!
! The loop walks through the car object list, calling the per-car update
! chain and 3D scene processing for each one.

FUN_0600E0C0:                       ! Main per-frame race update
    mov.l   r14,@-r15             ! Save all callee-saved (this is a big function)
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    sts.l   macl,@-r15
    mov.l   @(0x58,PC),r8         ! r8  = 0x0607EBC4 (frame flags)
    mov.l   @(0x58,PC),r9         ! r9  = 0x06078900 (object data)
    mov.w   @(0x10,PC),r10        ! r10 = constant (loop step/offset?)
    mov.l   @(0x58,PC),r11        ! r11 = 0x00008000 (half-unit constant)
    mov.l   @(0x1C,PC),r12        ! r12 = 0x0607E940 (car pointer)
    mov.l   @(0x34,PC),r14        ! r14 = 0x06027CA4 (3D scene processing fn)
    mov.l   @(0x58,PC),r0         ! r0 -> 0x0607EAE0 (rendering flag?)
    mov.l   @r0,r0                 ! Read flag
    tst     r0,r0                  ! Is it zero?
    bf      .has_cars              ! If nonzero, proceed to car loop
    bra     .loop_entry            ! Otherwise skip to end check
    mov     #1,r13

! ... (car processing loop iterates through object list,
!      calling per-car update and 3D scene processing for each)


! ============================================================================
! CONFIDENCE: HIGH — code at address verified, arithmetic confirmed
! FIXED: FUN_0600EA18 has NO function label in aprog.s -- it is
! mid-function code reached via bsr from 0x0600E676 (inside FUN_0600E4F2).
! The address 0x0600EA18 exists and the instruction (add #-12,r15) is
! verified at binary line 24996. The velocity calculation
! (target - current) >> 4 for X and Z is verified byte-level against
! ground truth. Angular velocity calculation also matches.
! The "chase/lerp" interpretation is plausible for AI/demo path.
! FUN_0600EA18 — Velocity Calculation (LEAF function)
! ============================================================================
! Computes velocity vector for position integration.
! Input: r4 = car object pointer
!
! Algorithm:
!   1. Read car's current position (X at +0x10, Z at +0x18, heading at +0x30)
!   2. Read target position from track segment data (indexed from 0x0607EB88)
!   3. velocity = (target - current) >> N  (approach target at fraction of delta)
!   4. Write velocity X to 0x060786C0, Z to 0x060786C4, heading to 0x060786C8
!
! This is a "chase" / lerp behavior — car smoothly approaches its target
! position along the track. The >> shifts control approach speed (larger = slower).
!
! NOTE: This may be the demo/replay/AI path rather than the player physics path.
! The player path likely uses acceleration from input (gas/brake) instead of
! direct position targeting. Need to trace the conditional that selects between
! player and AI update paths.

FUN_0600EA18:                       ! Velocity calculation
    add     #-12,r15              ! Allocate 3 longs on stack (temp storage)
    mov.w   @(0x58,PC),r5        ! r5 = offset constant (0x0120 — into car struct)
    add     r4,r5                  ! r5 = &car_object + 0x120 (physics substructure?)
    mov.l   @(0x4,r5),r3         ! r3 = car.field_0x124
    mov.l   r3,@r15               ! Save to stack[0]
    mov.l   @(0x8,r5),r3         ! r3 = car.field_0x128
    mov.l   r3,@(0x8,r15)        ! Save to stack[2]
    mov.l   @r15,r6               ! r6 = field_0x124
    mov.l   @(0xC,r5),r7         ! r7 = car.field_0x12C
    or      r3,r6                  ! r6 |= field_0x128
    or      r7,r6                  ! r6 |= field_0x12C
    mov.l   @r5,r3                ! r3 = car.field_0x120
    mov.l   r3,@(0x4,r15)        ! Save to stack[1]
    or      r3,r6                  ! r6 |= field_0x120
    ! r6 is now OR of all 4 fields — if zero, no track segment data

    and     r3,r7                  ! r7 = field_0x120 & field_0x12C
    mov.l   @(0x8,r15),r2        ! r2 = field_0x128
    mov.l   @r15,r1               ! r1 = field_0x124
    and     r2,r7                  ! r7 &= field_0x128
    and     r1,r7                  ! r7 &= field_0x124
    ! r7 = AND of all 4 — if bit 7 set in all, special handling

    mov.l   r7,@r15               ! Save AND result
    mov.l   @(0x38,PC),r5        ! r5 -> 0x0605A228 (approach speed counter)
    tst     r6,r6                  ! Any track data at all?
    bt/s    .no_track_data         ! If OR is zero, skip — no valid track segment
    mov     #0,r7

    mov.l   @r15,r0               ! Load AND result
    tst     #0x80,r0              ! Is bit 7 set in ALL fields?
    bt      .normal_approach       ! If not, use normal approach speed

.no_track_data:
    mov.l   r7,@r5                ! Zero out approach counter
    bra     .vel_done
    add     #12,r15               ! Clean up stack

.normal_approach:                   ! 0x0600EA54
    mov     #51,r2                ! 0x33 — mask for checking specific bits
    and     r2,r6                  ! Test bits in OR result
    tst     r6,r6
    bt      .increment_approach    ! If those bits clear, increment approach counter
    bra     .compute_velocity
    mov.l   r7,@r5                ! Reset counter

.increment_approach:                ! 0x0600EA60
    mov.l   @r5,r2                ! r2 = current approach counter
    add     #1,r2                  ! Increment
    mov.l   r2,@r5                ! Store back
    mov.w   @(0xE,PC),r3          ! r3 = max approach count (0x00A0 = 160)
    cmp/ge  r3,r2                  ! counter >= 160?
    bf      .compute_velocity      ! If under limit, proceed to velocity calc
    mov.l   r7,@r5                ! Reset counter to 0
    bra     .vel_done
    add     #12,r15

! --- Compute velocity from track segment delta ---
.compute_velocity:                  ! 0x0600EA80
    mov.w   @(0x76,PC),r0        ! r0 = offset into car struct
    mov.l   @(0x7C,PC),r3        ! r3 -> 0x0607EB88 (track segment table base)
    mov.l   @(0x10,r4),r2        ! r2 = car.X (current X position)
    mov.l   @(r0,r4),r5          ! r5 = car.track_segment_index
    mov.l   @r3,r3                ! r3 = track segment table pointer
    shll2   r5                     ! r5 = index * 4
    shll    r5                     ! r5 = index * 8
    add     #3,r5                  ! r5 = index * 8 + 3 (skip header?)
    shll2   r5                     ! r5 *= 4
    shll2   r5                     ! r5 *= 4  (total: index * 512 + 48)
    add     r3,r5                  ! r5 = &track_segments[index] (with offset)

    mov.l   @r5,r6                ! r6 = segment.target_X
    mov.l   @(0x4,r5),r7         ! r7 = segment.target_Z
    mov.l   @(0x18,r4),r3        ! r3 = car.Z (current Z position)
    mov.w   @(0xA,r5),r0         ! r0 = segment.target_heading (16-bit)

    sub     r2,r6                  ! r6 = target_X - current_X (delta X)
    sub     r3,r7                  ! r7 = target_Z - current_Z (delta Z)
    mov     r0,r2                  ! r2 = target heading
    shar    r6                     ! r6 >>= 1 (halve delta X)
    mov.l   @(0x30,r4),r3        ! r3 = car.heading (current heading)
    shll2   r2                     ! r2 = target_heading * 4 (scale to 32-bit)
    shar    r6                     ! r6 >>= 1 again (delta X / 4 total)
    sub     r3,r2                  ! r2 = target_heading*4 - current_heading
    shar    r6                     ! r6 >>= 1 again (delta X / 8)
    exts.w  r2,r5                  ! r5 = sign-extended heading delta (angular vel)

    mov.l   @(0x50,PC),r3        ! r3 -> 0x060786BC
    mov     #16,r2
    mov.l   r2,@r3                 ! Write 16 to 0x060786BC (steering constant?)

    shar    r6                     ! r6 >>= 1 (delta X / 16 total)
    mov.l   @(0x4C,PC),r3        ! r3 -> 0x060786C0 (velocity X output)
    mov.l   r6,@r3                 ! WRITE VELOCITY X = (target_X - car_X) >> 4

    shar    r7                     ! r7 >>= 1 (delta Z / 2)
    mov.l   @(0x48,PC),r3        ! r3 -> 0x060786C4 (velocity Z output)
    shar    r7                     ! r7 >>= 1 (delta Z / 4)
    shar    r7                     ! r7 >>= 1 (delta Z / 8)
    shar    r7                     ! r7 >>= 1 (delta Z / 16)
    mov.l   r7,@r3                 ! WRITE VELOCITY Z = (target_Z - car_Z) >> 4

    mov.l   @(0x44,PC),r3        ! r3 -> 0x060786C8 (angular velocity output)
    mov.l   r5,@r3                 ! WRITE ANGULAR VEL = (target_heading*4 - heading)
    rts
    add     #12,r15               ! Clean up stack


! ============================================================================
! CONFIDENCE: DEFINITE — verified byte-for-byte against ground truth
! All addresses confirmed: 0x060786C0 (vel X), 0x060786C4 (vel Z),
! 0x060786C8 (angular vel), 0x06063EF0 (heading global).
! car.X += velX, car.Z += velZ, car.heading += angular_vel all confirmed.
! FUN_06006838 call for coordinate lookup confirmed.
! Address 0x0600E5AE (not 0x0600E5B4) is the actual start of the
! countdown decrement; integration proper starts at 0x0600E5B4.
! Position Integration (at 0x0600E5B4, inside FUN_0600E4F2 or E1D4)
! ============================================================================
! After velocity is calculated, this code applies it to the car's position.
! Only runs when:
!   - Timer at @r13 > 0 (countdown still active)
!   - Flag at 0x06078635 == 0 (not paused/demo)
!
! This is the core physics step: position += velocity

.position_integration:              ! 0x0600E5AE (approximate)
    mov.l   @r13,r3               ! r3 = remaining frames countdown
    add     #-1,r3                ! Decrement
    mov.l   r3,@r13               ! Store back

    ! --- X position: car.X += velocity_X ---
    mov.l   @(0xFC,PC),r2        ! r2 -> 0x060786C0 (velocity X)
    mov.l   @(0x10,r14),r3       ! r3 = car.X (object + 0x10)
    mov.l   @r2,r2                ! r2 = velocity X value
    add     r2,r3                  ! r3 = car.X + velocity_X
    mov.l   r3,@(0x10,r14)       ! Store updated X back to car object

    ! --- Z position: car.Z += velocity_Z ---
    mov.l   @(0xF8,PC),r2        ! r2 -> 0x060786C4 (velocity Z)
    mov.l   @(0x18,r14),r3       ! r3 = car.Z (object + 0x18)
    mov.l   @r2,r2                ! r2 = velocity Z value
    add     r2,r3                  ! r3 = car.Z + velocity_Z
    mov.l   r3,@(0x18,r14)       ! Store updated Z

    ! --- Heading: car.heading += angular_velocity ---
    mov.l   @(0xF0,PC),r2        ! r2 -> 0x060786C8 (angular velocity)
    mov.l   @(0x20,r14),r3       ! r3 = car.heading (object + 0x20)
    mov.w   @r2,r2                ! r2 = angular velocity (16-bit!)
    add     r2,r3                  ! r3 = heading + angular_vel
    mov.l   r3,@(0x20,r14)       ! Store updated heading

    ! --- Copy heading to secondary fields ---
    mov     r3,r2
    mov.l   r3,@(0x30,r14)       ! car.heading_copy_2 = heading
    mov.l   r2,@(0x28,r14)       ! car.heading_copy_1 = heading

    ! --- Update tile map coordinates from new position ---
    mov.l   @(0xE4,PC),r3        ! r3 -> 0x06063EF0
    mov.l   r2,@r3                ! Store heading to global
    mov.l   @(0x18,r14),r5       ! r5 = car.Z (param 2)
    mov.l   @(0xE4,PC),r3        ! r3 = FUN_06006838 (coordinate→tile)
    jsr     @r3                    ! Call map coordinate lookup
    mov.l   @(0x10,r14),r4       ! (delay slot) r4 = car.X (param 1)
    ! Returns tile grid index for the car's current world position


! ============================================================================
! CONFIDENCE: MEDIUM — code at address verified but interpretation speculative
! FIXED: FUN_0600D0B8 has NO function label in aprog.s -- it is
! mid-function code reached via bsr from 0x0600CFA8. The address
! 0x0600D0B8 exists and starts with mov.w @(0x56,PC),r7 (verified at
! binary line 21552). The clamping logic (bounds check between 0 and
! 0x800) is verified structurally. The "physics clamping" label is
! reasonable given the context (between car objects, offset 0x200),
! but the specific meaning (speed? position delta?) is uncertain.
! FUN_0600D0B8 — Physics Clamping (LEAF function)
! ============================================================================
! Clamps a physics value (likely speed or position delta) between bounds.
! Reads from two car objects and applies min/max limiting.
!
! r5 -> 0x0607E944 (current car)
! r4 -> 0x0607E940 (previous car)
! Uses object offset 0x200 and 0x204 for comparison

FUN_0600D0B8:                       ! Physics value clamper
    mov.w   @(0x56,PC),r7        ! r7 = adjustment value (from constant pool)
    mov.l   @(0x64,PC),r5        ! r5 -> 0x0607E944
    mov.l   @(0x64,PC),r4        ! r4 -> 0x0607E940
    mov.l   @r4,r6                ! r6 = previous car object pointer
    mov     r6,r3                  ! r3 = same
    mov.l   @r3,r2                ! r2 = prev_car.flags (at +0x00)
    mov.l   @(0x60,PC),r3        ! r3 = 0x00C00000 (physics enable mask)
    and     r3,r2                  ! Check bits 22-23
    tst     r2,r2                  ! Physics enabled?
    bt/s    .clamp_done            ! If not, skip entirely
    mov.l   @r5,r5                 ! (delay) r5 = current car object

    ! Compare physics field between current and previous car
    mov.w   @(0x42,PC),r0        ! r0 = 0x0200 (offset into car struct)
    mov.l   @(r0,r5),r3          ! r3 = current_car[0x200]
    mov.l   @(r0,r6),r2          ! r2 = prev_car[0x200]
    cmp/ge  r2,r3                  ! current >= previous?
    bt      .use_alt_offset

    ! current < previous: use offset 0x01FC, add r7 adjustment
    mov.w   @(0x38,PC),r0        ! r0 = 0x01FC
    mov.l   @(r0,r5),r4          ! r4 = current_car[0x1FC]
    bra     .check_bounds
    add     r7,r4                  ! r4 += adjustment

.use_alt_offset:
    mov.w   @(0x30,PC),r0        ! r0 = 0x01F8
    mov.l   @(r0,r5),r4          ! r4 = current_car[0x1F8]
    mov.w   @(0x2E,PC),r2        ! r2 = 0xFE00 (negative bound)
    add     r2,r4                  ! r4 += -512

.check_bounds:
    cmp/pz  r4                     ! r4 >= 0?
    bt      .check_upper

    ! Clamp to zero (underflow)
    mov     #0,r2
    mov.w   @(0x26,PC),r0        ! r0 = offset for storage
    mov.l   r2,@(r0,r6)          ! Store 0 to prev_car[offset]
    bra     .store_result
    nop

.check_upper:
    mov.w   @(0x20,PC),r3        ! r3 = 0x0800 (max value = 2048)
    cmp/gt  r3,r4                  ! r4 > 2048?
    bf      .store_value           ! If not, store as-is

    ! Clamp to max
    mov.w   @(0x1A,PC),r3        ! r3 = 0x0800
    mov.w   @(0x16,PC),r0        ! r0 = storage offset
    mov.l   r3,@(r0,r6)          ! Store max to prev_car[offset]
    bra     .store_result
    nop

.store_value:
    mov.w   @(0xE,PC),r0         ! r0 = storage offset
    mov.l   r4,@(r0,r6)          ! Store clamped value

.store_result:
    mov.w   @(0xE,PC),r0
    mov.l   r7,@(r0,r6)          ! Store adjustment value too

.clamp_done:
    rts
    nop
