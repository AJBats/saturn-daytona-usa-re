! ==========================================================================
! Collision Detection & Response System
! ==========================================================================
!
! Complete collision pipeline for Daytona USA Saturn.
! This covers car-car and car-track boundary interactions.
!
! CALL GRAPH:
!   FUN_0600C5D6 (player collision + integration)
!     +-- FUN_0600CD40 (track-relative position query)
!     |     +-- FUN_0602744C (atan2 angle computation)
!     +-- FUN_0600CA96 (course correction - gentle heading smoothing)
!     +-- FUN_0600CC38 (heading update - stronger correction)
!     +-- FUN_0600CF58 (collision response dispatcher)
!     |     +-- FUN_06035168 (collision geometry classification)
!     |     +-- FUN_0600D0B8 (simple collision - no partner)
!     |     +-- FUN_0600D12C (passive response - position separation)
!     |     +-- FUN_0600D210 (aggressive response - speed-based push)
!     +-- FUN_0600C928 (speed reduction on collision)
!     +-- FUN_0600C8CC / FUN_0600C7D4 (heading correction from waypoints)
!     +-- FUN_06027358 (heading -> direction vectors via sin/cos)
!     +-- FUN_06027552 (fixed-point multiply: (r4*r5)>>16)
!     +-- FUN_06006838 (elevation/terrain query)
!     +-- FUN_06027EDE (terrain position update)
!
!   FUN_0600C74E (AI collision + integration) - simplified player path
!     +-- FUN_0600CD40, FUN_0600CA96, FUN_0600C8CC, FUN_0600C928
!     +-- FUN_0600C970 (speed boost from course table)
!
! KEY DATA STRUCTURES:
!   Car struct (pointed to by [0x0607E940]):
!     +0x00: flags (bits 0x00C00000 = collision type, 0x00E00000 = active collision)
!     +0x03: byte flags (bit 3 = collision active)
!     +0x04: collision partner pointer (0 = none)
!     +0x08: speed (32-bit signed)
!     +0x0C: direction/heading value
!     +0x10: X position (32-bit)
!     +0x14: Y position (32-bit, set to 0 for ground)
!     +0x18: Z position (32-bit)
!     +0x1C: rotation X
!     +0x20: heading (16-bit unsigned, 0-65535 = full circle)
!     +0x24: rotation Z
!     +0x28: current heading (for smoothing)
!     +0x30: target heading
!     +0xB8: collision timer A (>0 = in correction)
!     +0x1BC: collision timer B
!     +0x1EC: collision counter
!
!   Sin/Cos Vector Table at 0x0607EB88:
!     - Array of (X,Z) direction pairs indexed by heading
!     - 16-byte entries: [X_int, X_next, Z_int, Z_next]
!     - Heading byte (0-255) maps to 0-360 degrees
!     - Supports linear interpolation between adjacent entries
!     - Integer index = heading >> 8, fraction = (heading & 0xFF) >> 2
!
!   Waypoint data at 0x06078680:
!     - Per-segment track data
!     - +0x08: segment position X
!     - +0x0A: segment normal X (scaled)
!     - +0x0C: segment width
!     - +0x0E: segment heading delta (x4)
!     - +0x10: segment position Z
!     - +0x12: segment normal Z
!
!   Collision state at 0x0607EBDC:
!     - Global collision accumulator
!
!   Track bounds threshold at [0x0607EA9C]:
!     - Maximum off-track frame count before reset
!
! ==========================================================================

! ==========================================================================
! FUN_0600C5D6 - Player Collision Detection & Position Integration
! ==========================================================================
! Main per-frame collision handler for the player car.
! Three possible paths based on game state and collision status:
!   Path A: Course correction (gentle steering towards track center)
!   Path B: Heading update (normal driving, adjust heading towards waypoint)
!   Path C: Collision response (car-car collision detected)
! After collision/heading handling, integrates position:
!   X += speed * sin(heading)
!   Z += speed * cos(heading)
!   Y = 0
!
! Called from: FUN_0600E71A (player physics pipeline, step 5 of 8)

FUN_0600C5D6:       ! 0x0600C5D6
    mov.l   r14,@-r15           ! save callee-saved regs
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    sts.l   pr,@-r15
    add     #-4,r15             ! 4 bytes local storage

    ! Load constants
    mov.l   @(0x38,PC),r10      ! r10 = 0x06027552 (fixed-point multiply fn)
    mov.l   @(0x3C,PC),r11      ! r11 = 0x0607EBDC (collision state)
    mov.l   @(0x3C,PC),r14      ! r14 = 0x0607E940 (car struct ptr ptr)
    mov.l   @(0x40,PC),r13      ! r13 = 0x06078680 (waypoint data)

    ! Step 1: Query track-relative position
    bsr     FUN_0600CD40        ! track geometry query
    mov.l   @r14,r14            ! r14 = *car_struct_ptr (delay slot)
    mov     r0,r12              ! r12 = track segment pointer (return value)

    ! Step 2: Check game mode
    mov.l   @(0x3C,PC),r0      ! r0 = 0x06087804 (game mode word)
    mov.w   @r0,r0
    extu.w  r0,r0
    cmp/eq  #2,r0               ! mode == 2? (replay/demo)
    bt/s    .course_correct     ! yes -> always do course correction
    add     #24,r12             ! r12 += 24 (adjust segment pointer to data area)

    ! Step 3: Check collision timers
    mov.w   @(0x14,PC),r0      ! offset = 0x01BC
    mov.l   @(r0,r14),r2       ! r2 = car[+0x1BC] (collision timer B)
    cmp/pl  r2                  ! timer > 0?
    bt      .course_correct     ! yes -> still recovering from collision

    mov.w   @(0xE,PC),r0       ! offset = 0x00B8
    mov.l   @(r0,r14),r2       ! r2 = car[+0xB8] (collision timer A)
    cmp/pl  r2                  ! timer > 0?
    bf      .check_collision    ! no -> check for new collision

.course_correct:                ! Path A: gentle course correction
    bsr     FUN_0600CA96        ! smooth heading towards track center
    mov     r13,r4              ! r4 = waypoint data (delay slot)
    bra     .do_integration     ! skip to position integration
    nop

.check_collision:               ! 0x0600C634
    ! Check car byte flag [+3] bit 3 (active collision)
    mov.l   @(0xCC,PC),r2      ! r2 = ptr to [0x0607E944] (other car ptr)
    mov.l   @r2,r2              ! r2 = other car struct
    mov     r2,r0
    mov.b   @(3,r0),r0          ! r0 = other_car[+3] flags byte
    tst     #0x08,r0            ! bit 3 set? (collision flag)
    bf      .heading_update     ! set -> no collision, just update heading

    ! Check collision state at car[+0x1EC]
    mov.w   @(0xB2,PC),r0      ! offset for car[+0x1EC]
    mov.l   @(r0,r14),r3       ! r3 = car[+0x1EC] (collision count)
    cmp/pl  r3                  ! count > 0?
    bt      .heading_update     ! yes -> already handled this frame

    ! Check car[+0x161] byte & 0x20
    mov.w   @(0xAC,PC),r0      ! offset for byte flag
    mov.b   @(r0,r14),r0
    tst     #0x20,r0            ! bit 5 clear?
    bf      .heading_update     ! set -> skip collision

    ! Speed threshold check: collision_state > 10?
    mov     #10,r2
    mov.l   @r11,r3             ! r3 = [0x0607EBDC] (collision accumulator)
    cmp/gt  r2,r3               ! > 10?
    bt      .maybe_collide      ! yes -> check further

    ! Course profile check: car[+0x1EC-like] >= 102 (0x66)?
    mov.w   @(0x9E,PC),r0
    mov     #102,r3
    mov.l   @(r0,r14),r2
    cmp/ge  r3,r2               ! value >= 102?
    bt      .maybe_collide      ! yes -> enter collision response

    ! No collision detected - call collision response anyway for passive handling
    bsr     FUN_0600CF58        ! collision response (may early-exit)
    mov     r12,r4              ! r4 = segment pointer (delay slot)

.maybe_collide:
    ! Check if there's an active collision timer to decrement
    mov.w   @(0x90,PC),r0
    mov.l   @(r0,r14),r2       ! get collision timer
    cmp/pl  r2                  ! > 0?
    bf      .heading_update_from_waypoint

    ! Decrement timer and do course correction
    mov.w   @(0x88,PC),r0
    mov.l   @(r0,r14),r2
    add     #-2,r2              ! timer -= 2
    mov.l   r2,@(r0,r14)       ! store back
    bsr     FUN_0600CA96        ! course correction
    mov     r13,r4
    mov.l   @r11,r2             ! collision accumulator
    add     #1,r2               ! increment
    bra     .do_integration
    mov.l   r2,@r11             ! store back (delay slot)

.heading_update_from_waypoint:
    mov     r13,r5              ! r5 = waypoint data
    bsr     FUN_0600CC38        ! heading correction (stronger)
    mov     r12,r4              ! r4 = segment pointer
    bra     .do_integration
    nop

.heading_update:                ! 0x0600C68C
    mov     r13,r5              ! r5 = waypoint data
    bsr     FUN_0600CC38        ! heading correction
    mov     r12,r4              ! r4 = segment pointer

.do_integration:                ! 0x0600C692
    ! Check game mode for Z-axis special handling
    mov.l   @(0x74,PC),r0      ! 0x06087804 (game mode)
    mov.w   @r0,r0
    extu.w  r0,r0
    cmp/eq  #3,r0               ! mode == 3? (time trial / special)
    bf      .normal_integration

    ! Mode 3: extra speed calculation for Z
    mov.w   @(0x5C,PC),r0
    mov.l   @(r0,r14),r5       ! r5 = car[speed_field]
    jsr     @r10                ! FUN_06027552: (speed * direction) >> 16
    mov.l   @(8,r12),r4        ! r4 = direction from segment (delay slot)
    mov.w   @(0x56,PC),r1
    add     r14,r1
    mov.l   r0,@r1              ! store Z velocity component

.normal_integration:
    ! Update heading/direction subsystem
    mov     r13,r5              ! r5 = waypoint data
    bsr     FUN_0600C8CC        ! heading/position setup
    mov     r14,r4              ! r4 = car struct

    ! Check collision flags in car[0]
    mov.l   @(0x58,PC),r2      ! ptr to [0x0607E940]
    mov.l   @r2,r2              ! car struct
    mov.l   @r2,r3              ! car[0] = flags word
    mov.l   @(0x58,PC),r2      ! 0x00E00000 (collision mask)
    and     r2,r3               ! mask collision bits
    tst     r3,r3               ! any collision bits set?
    bf      .collision_path     ! yes -> special collision integration

    ! === NORMAL POSITION INTEGRATION ===
    ! Convert heading to direction vector
    mov.w   @(0xE,r13),r0      ! heading from waypoint
    mov     r0,r3
    mov.l   r0,@(0x20,r14)     ! car[+0x20] = heading
    mov.w   @(0x38,PC),r6      ! offset for direction output X
    mov.w   @(0x38,PC),r5      ! offset for direction output Z
    mov.l   @(0x28,r14),r4     ! r4 = car[+0x28] (current heading)
    mov.l   @(0x48,PC),r3      ! r3 = 0x06027358 (heading->direction fn)
    add     r14,r6              ! r6 = &car[+dir_x]
    add     r14,r5              ! r5 = &car[+dir_z]
    jsr     @r3                 ! FUN_06027358(heading, &dir_x, &dir_z)
    neg     r4,r4               ! negate heading (SH-2 convention, delay slot)

    ! X += speed * direction_X
    mov.w   @(0x2A,PC),r0
    mov.l   @(r0,r14),r5       ! r5 = direction_X
    jsr     @r10                ! FUN_06027552: r0 = (r4 * r5) >> 16
    mov.l   @(0xC,r14),r4      ! r4 = car[+0x0C] (speed, delay slot)
    mov.l   @(0x10,r14),r3     ! r3 = car.X
    add     r0,r3               ! X += velocity_X
    mov.l   r3,@(0x10,r14)     ! car.X = new X

    ! Z += speed * direction_Z
    mov.w   @(0x1A,PC),r0
    mov.l   @(r0,r14),r5       ! r5 = direction_Z
    jsr     @r10                ! FUN_06027552: r0 = (r4 * r5) >> 16
    mov.l   @(0xC,r14),r4      ! r4 = speed again (delay slot)
    mov.l   @(0x18,r14),r3     ! r3 = car.Z
    add     r0,r3               ! Z += velocity_Z
    mov.l   r3,@(0x18,r14)     ! car.Z = new Z

    ! Y = 0 (car is on ground plane)
    mov     #0,r2
    bra     .epilogue
    mov.l   r2,@(0x14,r14)     ! car.Y = 0 (delay slot)

.collision_path:                ! 0x0600C718
    ! Collision active: reduce speed and correct heading from waypoints
    bsr     FUN_0600C928        ! speed reduction
    mov     r14,r4
    mov     r13,r5
    bsr     FUN_0600C7D4        ! heading correction from waypoint data
    mov     r14,r4

    ! Terrain/elevation query
    mov     r15,r6              ! r6 = stack frame
    mov     r14,r5
    mov.l   r6,@-r15
    add     #16,r5              ! r5 = &car[+0x10] (position)
    mov.l   r5,@-r15
    mov.l   @(0x18,r14),r5     ! r5 = car.Z
    mov.l   @(0x94,PC),r3      ! r3 = 0x06006838 (elevation query)
    jsr     @r3
    mov.l   @(0x10,r14),r4     ! r4 = car.X (delay slot)

    ! Apply terrain result
    mov     r0,r4               ! r4 = terrain height
    mov.l   @r15+,r5
    mov.l   @(0x8C,PC),r3      ! r3 = 0x06027EDE (terrain update)
    jsr     @r3
    mov.l   @r15+,r6            ! restore stack (delay slot)

.epilogue:                      ! 0x0600C73E
    add     #4,r15              ! free local storage
    lds.l   @r15+,pr
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ==========================================================================
! FUN_0600CA96 - Course Correction (Gentle Heading Smoothing)
! ==========================================================================
! Steers the car heading gently towards the track center.
! Dead zone: |delta| < 8 -> snap heading, else adjust by +4 or -4 per frame.
! Then looks up sin/cos direction vectors from heading via interpolated table.
!
! r4 = output struct (waypoint position data, 0x06078680)
! Uses: car struct from [0x0607E940]
!
! Called from: FUN_0600C5D6 (Path A), FUN_0600C74E (AI version)

FUN_0600CA96:       ! 0x0600CA96
    mov.l   r13,@-r15
    sts.l   macl,@-r15
    mov.l   @(0x28,PC),r5      ! r5 = [0x0607E940]
    mov.w   @(0x22,PC),r0      ! offset = 0x01FC
    mov.l   @r5,r5              ! r5 = car struct

    ! Read two heading values and compute delta
    mov.l   @(r0,r5),r6        ! r6 = car[+0x1FC] (target heading)
    add     #4,r0               ! offset = 0x200
    mov.l   @(r0,r5),r3        ! r3 = car[+0x200] (current heading)
    sub     r3,r6               ! r6 = delta = target - current

    ! Dead zone check: |delta| < 8?
    mov     #8,r3
    cmp/ge  r3,r6               ! delta >= 8?
    bt      .ca96_turn_right    ! yes -> turn right
    mov     #-8,r3
    cmp/gt  r3,r6               ! delta > -8?
    bf      .ca96_turn_left     ! no (delta <= -8) -> turn left

    ! Within dead zone: snap current heading to target
    mov.w   @(0x0A,PC),r0      ! offset = 0x01FC
    mov.l   @(r0,r5),r3        ! r3 = target heading
    add     #4,r0               ! offset = 0x200
    mov.l   r3,@(r0,r5)        ! current = target (snap)
    bra     .ca96_lookup
    nop

.ca96_turn_right:
    ! delta >= 8: nudge heading right by +4
    mov.w   @(0xB4,PC),r0      ! offset for heading
    mov.l   @(r0,r5),r3
    add     #4,r3               ! heading += 4
    mov.l   r3,@(r0,r5)
    bra     .ca96_lookup
    nop

.ca96_turn_left:
    ! delta <= -8: nudge heading left by -4
    mov.w   @(0xA8,PC),r0
    mov.l   @(r0,r5),r2
    add     #-4,r2              ! heading -= 4
    mov.l   r2,@(r0,r5)

.ca96_lookup:
    ! === Sin/Cos Table Lookup ===
    ! heading[+0x1FC] -> 256-entry direction vector table at 0x0607EB88
    mov.w   @(0xA0,PC),r0
    mov.l   @(r0,r5),r7        ! r7 = heading (full 16-bit value)
    mov.l   @(0xA4,PC),r13     ! r13 = 0x0607EB88 (sin/cos table ptr)
    extu.w  r7,r6               ! r6 = heading as unsigned
    ! Extract interpolation fraction = (heading & 0xFF) >> 2
    and     #0xFF,r0            ! mask low byte... (re-reads heading)
    extu.w  r0,r14              ! r14 = low byte
    shlr2   r14                 ! r14 >>= 2
    shlr2   r14                 ! r14 >>= 4 total
    shlr2   r14                 ! r14 >>= 6 total -> fraction (0-3)
    tst     r14,r14             ! fraction == 0?
    bt/s    .ca96_direct        ! yes -> direct lookup (no interp needed)
    shlr8   r6                  ! r6 = integer index (delay slot)

    ! Interpolation check
    mov     #7,r3
    cmp/ge  r3,r6               ! index >= 7?
    bt      .ca96_direct        ! yes -> clamp, direct lookup

    ! === Interpolated lookup ===
    ! weight1 = 4 - fraction, weight2 = fraction
    mov     #4,r1
    mov.w   @(0x82,PC),r0
    sub     r14,r1              ! r1 = 4 - fraction (weight for current entry)
    mov.l   @(r0,r5),r3        ! additional offset
    shll2   r3
    shll    r3                  ! r3 *= 5 (entry stride adjustment)
    add     r3,r6               ! r6 = final table index

    ! Table[index]: each entry is 16 bytes (4 longs: X, X_next, Z, Z_next)
    mov     r6,r0
    mov.l   @r13,r3             ! r3 = table base
    mov     r6,r6               ! (nop equivalent)
    shll2   r0                  ! r0 = index * 4
    add     #1,r6               ! next index
    shll2   r0                  ! r0 = index * 16
    shll2   r6
    add     r3,r0               ! r0 = &table[index]
    shll2   r6
    mov.l   @r0,r2              ! r2 = table[index].X
    add     r3,r6               ! r6 = &table[index+1]

    ! Interpolate X: result = (X * weight1 + X_next * weight2) >> 2
    mul.l   r1,r2               ! X * weight1
    mov.l   @r6,r3              ! r3 = table[index+1].X
    sts     macl,r2
    mul.l   r14,r3              ! X_next * weight2
    sts     macl,r3
    add     r3,r2               ! sum
    shar    r2                  ! >> 1
    shar    r2                  ! >> 2
    mov.l   r2,@r5              ! output dir_X

    ! Interpolate Z: same formula
    mov.l   @(4,r0),r2         ! table[index].Z
    mul.l   r1,r2
    sts     macl,r1
    mov.l   @(4,r6),r3         ! table[index+1].Z
    mul.l   r14,r3
    sts     macl,r14
    add     r14,r1
    shar    r1
    shar    r1
    bra     .ca96_store_z
    mov.l   r1,@(8,r5)         ! output dir_Z (delay slot)

.ca96_direct:
    ! Direct lookup (no interpolation)
    ! Similar index calculation but reads directly
    mov.w   @(0x38,PC),r0
    mov.l   @(r0,r5),r2
    shll2   r2
    shll    r2
    add     r2,r6
    mov     r6,r5
    mov.l   @r13,r3
    shll2   r5
    shll2   r5
    add     r3,r5
    mov.l   @r5,r2              ! X direction
    mov.l   r2,@r4              ! output[0] = dir_X
    mov.l   @(4,r5),r3         ! Z direction
    mov.l   r3,@(8,r4)         ! output[8] = dir_Z

.ca96_store_z:
    ! Copy additional segment data to output
    mov.w   @(8,r5),r0         ! segment data
    mov.w   r0,@(0xC,r4)       ! output width
    mov.w   @(0xA,r5),r0
    mov     r0,r3
    shll2   r3
    exts.w  r3,r0
    mov.w   r0,@(0xE,r4)       ! output heading delta (x4)
    mov.w   @(0xC,r5),r0
    mov.w   r0,@(0x10,r4)      ! output extra
    mov     #0,r0
    mov.w   r0,@(0x12,r4)      ! output Z offset = 0

    lds.l   @r15+,macl
    rts
    mov.l   @r15+,r13


! ==========================================================================
! FUN_0600CC38 - Heading Update (Stronger Correction)
! ==========================================================================
! Like FUN_0600CA96 but with larger correction step: +/-8 instead of +/-4.
! Also uses same sin/cos interpolated vector table lookup.
! This is the "normal driving" heading update path.
!
! r4 = segment pointer (from FUN_0600CD40 return + 24)
! r5 = waypoint data base (0x06078680)
! Uses: car struct from [0x0607E940]

FUN_0600CC38:       ! 0x0600CC38
    mov.l   r14,@-r15
    mov.l   r11,@-r15
    sts.l   macl,@-r15
    add     #-4,r15

    mov.l   @(0xB8,PC),r6      ! r6 = [0x0607E940]
    mov.w   @(0xB0,PC),r0      ! offset for heading pair
    mov.l   @r6,r6              ! r6 = car struct
    mov.l   @(r0,r6),r7        ! r7 = car[heading_A]
    add     #4,r0
    mov.l   @(r0,r6),r3        ! r3 = car[heading_B]
    sub     r3,r7               ! r7 = delta = A - B

    ! Dead zone: |delta| < 8 -> snap
    mov     #8,r3
    cmp/ge  r3,r7               ! delta >= 8?
    bt      .cc38_right         ! yes -> turn right by 8
    mov     #-8,r3
    cmp/gt  r3,r7               ! delta > -8?
    bf      .cc38_left          ! no -> turn left by 8

    ! Snap: copy heading_A to heading_B
    mov.w   @(0x98,PC),r0
    mov.l   @(r0,r6),r3
    add     #4,r0
    mov.l   r3,@(r0,r6)
    bra     .cc38_lookup
    nop

.cc38_right:                    ! 0x0600CC66
    cmp/pl  r7                  ! delta > 0? (should be yes if >= 8)
    bf      .cc38_left_8
    mov.w   @(0x8A,PC),r0
    mov.l   @(r0,r6),r3
    add     #8,r3               ! heading += 8 (faster correction)
    mov.l   r3,@(r0,r6)
    bra     .cc38_lookup
    nop

.cc38_left_8:
    mov.w   @(0x7E,PC),r0
    mov.l   @(r0,r6),r2
    add     #-8,r2              ! heading -= 8
    mov.l   r2,@(r0,r6)

.cc38_lookup:
    ! Same sin/cos vector table lookup as FUN_0600CA96
    ! (Identical interpolation algorithm, outputs to r4/r5 struct)
    ! ... [same logic as CA96 lookup section]
    ! Reads heading, extracts fraction, interpolates between adjacent
    ! sin/cos table entries at 0x0607EB88

    ! [Outputs segment data to r4 struct: width, heading delta, etc.]
    add     #4,r15
    lds.l   @r15+,macl
    mov.l   @r15+,r11
    rts
    mov.l   @r15+,r14


! ==========================================================================
! FUN_0600CD40 - Track-Relative Position Query
! ==========================================================================
! Determines where the car is relative to the current track segment.
! Computes the angle between the car and the segment center point,
! then checks if the car is within the segment's width boundary.
!
! If off-track (beyond segment width), increments an off-track counter.
! When counter exceeds global threshold, resets it (triggers recovery).
!
! Returns: r0 = pointer to current track segment data structure
!
! Called from: FUN_0600C5D6, FUN_0600C74E, FUN_0600CE66

FUN_0600CD40:       ! 0x0600CD40
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    sts.l   pr,@-r15

    mov.l   @(0x7C,PC),r14     ! r14 = [0x0607E940]
    mov.w   @(0x72,PC),r0      ! offset for segment index field
    mov.l   @r14,r14            ! r14 = car struct

    ! Calculate segment pointer: index * 20 + base
    mov.l   @(r0,r14),r13      ! r13 = segment index
    add     #-4,r0
    mov     r13,r3
    shll2   r13                 ! r13 *= 4
    shll2   r3                  ! r3 *= 4
    shll    r13                 ! r13 *= 8 (total: index * 8)
    shll2   r3                  ! r3 *= 16 (total: index * 16)
    add     r3,r13              ! r13 = index * 24 (= index * (8+16))
    mov.l   @(r0,r14),r3       ! r3 = segment table base
    add     r3,r13              ! r13 = &segment[index]

    ! Read segment heading
    mov.w   @(0x16,r13),r0     ! segment heading
    mov     r0,r3
    extu.w  r3,r3
    mov.w   @(0x56,PC),r0
    mov.l   r3,@(r0,r14)       ! store to car heading field

    ! Compute angle from car to segment center
    ! delta_X = segment.X - car.X
    ! delta_Z = segment.Z - car.Z
    mov.l   @(4,r13),r5        ! r5 = segment.Z
    mov.l   @(0x18,r14),r3     ! r3 = car.Z
    mov.l   @(0x10,r14),r4     ! r4 = car.X
    mov.l   @r13,r2             ! r2 = segment.X
    sub     r3,r5               ! r5 = delta_Z
    mov.l   @(0x50,PC),r3      ! r3 = 0x0602744C (atan2 fn)
    jsr     @r3                 ! r0 = atan2(delta_Z, delta_X)
    sub     r2,r4               ! r4 = delta_X (delay slot)

    ! Compare angle vs track width
    exts.w  r0,r4               ! r4 = angle (signed)
    exts.w  r4,r6               ! r6 = angle copy
    mov.w   @(0xE,r13),r0      ! r0 = segment half-width
    mov     r6,r7
    mov     r0,r5
    shll2   r5                  ! r5 = width * 4 (scaled boundary)
    sub     r5,r7               ! r7 = angle - width*4

    ! Determine lateral offset (absolute distance from center)
    cmp/pz  r7                  ! angle >= width*4? (right of center)
    bt      .cd40_right_side
    mov     r5,r2               ! r2 = width*4
    bra     .cd40_check_bounds
    sub     r6,r2               ! r2 = width*4 - angle (left offset)
.cd40_right_side:
    mov     r7,r2               ! r2 = angle - width*4 (right offset)

.cd40_check_bounds:
    ! If offset > threshold -> car is off-track
    mov.w   @(0x2A,PC),r3      ! threshold value
    cmp/gt  r3,r2               ! offset > threshold?
    bf      .cd40_done          ! no -> on-track, done

    ! Off-track: increment counter
    mov.w   @(0x20,PC),r0      ! offset for off-track counter
    mov.l   @(r0,r14),r3       ! counter value
    add     #1,r3
    mov.l   r3,@(r0,r14)       ! counter++

    ! Check against global max threshold
    mov.l   @(r0,r14),r3
    mov.l   @(0x24,PC),r2      ! r2 = [0x0607EA9C] (max off-track frames)
    mov.l   @r2,r2
    cmp/gt  r2,r3               ! counter > max?
    bf      .cd40_done          ! no -> keep counting
    mov     #0,r2
    mov.w   @(0xC,PC),r0
    mov.l   r2,@(r0,r14)       ! reset counter to 0

.cd40_done:
    mov     r13,r0              ! return segment pointer in r0
    lds.l   @r15+,pr
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ==========================================================================
! FUN_0600CF58 - Collision Response Dispatcher
! ==========================================================================
! Main collision response entry point. Classifies collision type and
! dispatches to appropriate handler.
!
! Three-stage pipeline:
!   1. Early exit checks (no partner, low speed, no collision flags)
!   2. Collision geometry classification via FUN_06035168
!   3. Response dispatch:
!      - Head-on (bit 0x02): speed comparison -> passive or heading adjust
!      - Side hit (bit 0x01): speed+mode check -> aggressive or passive
!      - Default: passive response
!
! r4 = segment pointer (from caller)
! Uses: car struct [0x0607E940], other car [0x0607E944]

FUN_0600CF58:       ! 0x0600CF58
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    sts.l   pr,@-r15
    add     #-4,r15
    mov     r15,r11             ! r11 = local stack (collision result byte)

    mov.w   @(0x78,PC),r12     ! r12 = collision timer value (constant)
    mov.l   @(0x80,PC),r13     ! r13 = [0x0607E944] (other car ptr)
    mov.l   @(0x84,PC),r4      ! r4 = [0x0607E940]
    mov.l   @r4,r14             ! r14 = car struct

    ! --- Early exit 1: no collision partner ---
    mov.l   @(4,r14),r0        ! car[+4] = collision partner
    tst     r0,r0
    bf/s    .cf58_has_partner
    mov.l   @r13,r13            ! r13 = other car struct (delay slot)
    bra     .cf58_no_collision  ! no partner -> skip
    nop

.cf58_has_partner:
    ! --- Early exit 2: speed too low ---
    mov.l   @(8,r14),r3        ! r3 = car speed
    mov.w   @(0x64,PC),r2      ! r2 = min speed threshold (0x0096 = 150)
    cmp/gt  r2,r3               ! speed > threshold?
    bt      .cf58_speed_ok
    bra     .cf58_no_collision
    nop

.cf58_speed_ok:
    ! --- Check collision type flags ---
    mov.l   @r4,r2              ! re-read car ptr
    mov.l   @r2,r3              ! car[0] = flags
    mov.l   @(0x68,PC),r2      ! 0x00C00000 (collision type mask)
    and     r2,r3
    tst     r3,r3               ! any collision type bits?
    bf      .cf58_classify      ! yes -> classify collision
    bra     .cf58_exit          ! no collision type -> exit
    nop

.cf58_classify:
    ! --- Compute collision geometry ---
    mov     r11,r1              ! r1 = &result_byte (on stack)
    mov     r14,r2              ! r2 = car struct
    mov.l   @(0x5C,PC),r3      ! r3 = 0x06035168 (collision geometry fn)
    jsr     @r3                 ! classify collision into result byte
    mov     #4,r0               ! r0 = 4 (mode param, delay slot)

    ! Read classification result
    mov.w   @(0x42,PC),r0
    mov.l   @(r0,r14),r0       ! check collision field
    tst     r0,r0
    bf      .cf58_check_type    ! field set -> check collision type
    bsr     FUN_0600D0B8        ! simple collision (no detailed partner)
    nop
    bra     .cf58_exit
    nop

.cf58_check_type:
    ! Read collision result byte from stack
    mov     r11,r0
    mov.b   @r0,r0              ! r0 = collision result byte

    ! --- Head-on collision? (bit 0x02) ---
    tst     #0x02,r0
    bt      .cf58_not_head_on   ! bit 2 clear -> not head-on

    ! Head-on: compare speeds
    mov.l   @(8,r13),r3        ! other car speed
    mov.l   @(8,r14),r2        ! self speed
    cmp/ge  r2,r3               ! other >= self?
    bt      .cf58_head_on_slower ! other is faster or equal -> passive

    ! Self is faster: passive response
    bsr     FUN_0600D12C        ! passive collision response
    nop
    bra     .cf58_not_head_on
    nop

.cf58_head_on_slower:
    ! Other is faster: copy heading, set collision timer
    mov.w   @(0x1C,PC),r0
    mov.l   @(r0,r14),r2       ! heading value
    add     #-4,r0
    mov.l   r2,@(r0,r14)       ! copy heading
    add     #12,r0
    bra     .cf58_exit
    mov.l   r12,@(r0,r14)      ! store collision timer

.cf58_not_head_on:              ! 0x0600CFD6
    ! Speed comparison (same as head-on path)
    mov.l   @(8,r13),r3        ! other speed
    mov.l   @(8,r14),r2        ! self speed
    cmp/ge  r2,r3               ! other >= self?
    bt      .cf58_check_side
    bra     .cf58_exit          ! other slower -> no response
    nop

.cf58_check_side:               ! 0x0600CFFC
    ! --- Side collision? (bit 0x01) ---
    mov     r11,r0
    mov.b   @r0,r0
    tst     #0x01,r0            ! bit 0 set?
    bt      .cf58_default_passive ! not side hit -> default passive

    ! Check car collision mode field
    mov.w   @(0xA2,PC),r0
    mov.l   @(r0,r14),r0       ! car[+0x210] collision mode
    cmp/eq  #2,r0               ! mode == 2? (high-speed collision)
    bf      .cf58_mode_1        ! no -> check mode 1

    ! Mode 2: aggressive collision check
    mov.l   @(8,r13),r2        ! other car speed
    mov.w   @(0x9A,PC),r3      ! speed threshold (0x0AF0 = 2800)
    cmp/gt  r3,r2               ! other speed > 2800?
    bf      .cf58_mode2_passive ! no -> passive
    mov     #10,r2
    mov.w   @(0x94,PC),r0
    mov.l   @(r0,r14),r3       ! collision count
    cmp/ge  r2,r3               ! count >= 10?
    bt      .cf58_mode2_passive ! yes -> too many, go passive
    bsr     FUN_0600D210        ! AGGRESSIVE collision response
    nop
    bra     .cf58_post_side
    nop

.cf58_mode2_passive:
    bsr     FUN_0600D12C        ! passive response
    nop
    bra     .cf58_post_side
    nop

.cf58_mode_1:                   ! 0x0600D02E
    ! Mode 1: low-speed side collision - heading adjustment
    mov.w   @(0x78,PC),r0
    mov.l   @(r0,r14),r0
    cmp/eq  #1,r0               ! mode == 1?
    bf      .cf58_post_side     ! no -> skip

    ! Classify by speed magnitude (shift both speeds right 8)
    mov.w   @(0x76,PC),r0
    mov     #2,r3
    mov.l   @(r0,r13),r4       ! other car[field]
    mov.l   @(r0,r14),r5       ! self car[field]
    shar    r4                  ! other >>= 1
    shar    r5                  ! self >>= 1
    shar    r4                  ! >>= 2
    shar    r5
    shar    r4                  ! >>= 3
    shar    r5
    shar    r4                  ! >>= 4
    shar    r5
    shar    r4                  ! >>= 5
    shar    r5
    shar    r4                  ! >>= 6
    shar    r5
    shar    r4                  ! >>= 7
    shar    r5
    shar    r4                  ! >>= 8 (divide by 256)
    shar    r5

    ! Small speed: both cars slow -> minor heading adjustment
    cmp/hs  r3,r4               ! other_norm >= 2?
    bt      .cf58_large_speed
    mov     #3,r3
    cmp/hs  r3,r5               ! self_norm >= 3?
    bt      .cf58_large_speed

    ! Both slow: set heading to fixed value, store collision timer
    mov.w   @(0x46,PC),r3      ! heading value (pool constant)
    mov.w   @(0x46,PC),r0      ! offset
    mov.l   r3,@(r0,r14)       ! store heading
    add     #12,r0
    bra     .cf58_post_side
    mov.l   r12,@(r0,r14)      ! store collision timer (delay slot)

.cf58_large_speed:
    ! At least one car moving fast: stronger heading correction
    mov     #5,r2
    cmp/hi  r2,r4               ! other_norm > 5?
    bf      .cf58_post_side     ! no -> done
    mov     #4,r2
    cmp/hi  r2,r5               ! self_norm > 4?
    bf      .cf58_post_side     ! no -> done

    ! Both fast: larger heading correction + collision timer
    mov.w   @(0x32,PC),r2      ! larger heading value
    mov.w   @(0x2E,PC),r0      ! offset
    mov.l   r2,@(r0,r14)
    add     #12,r0
    mov.l   r12,@(r0,r14)      ! collision timer

.cf58_post_side:                ! 0x0600D08A
    bra     .cf58_exit
    nop

.cf58_default_passive:          ! 0x0600D08E
    bsr     FUN_0600D12C        ! passive response
    nop

.cf58_no_collision:             ! 0x0600D092
    ! Additional check: if car[+4] == 0 -> passive response
    mov.l   @(4,r14),r0
    tst     r0,r0
    bf      .cf58_exit
    bsr     FUN_0600D12C        ! passive response (safety net)
    nop

.cf58_exit:                     ! 0x0600D09C
    add     #4,r15
    lds.l   @r15+,pr
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ==========================================================================
! FUN_0600D12C - Passive Collision Response (Position Separation)
! ==========================================================================
! Checks Z-axis distance between two cars. If they're close enough,
! this is a confirmed collision. Compares distances against thresholds
! 0x80000 and 0x0F0000.
!
! Uses: car struct [0x0607E940] and other car

FUN_0600D12C:       ! 0x0600D12C
    mov.l   r14,@-r15
    mov.l   @(0x68,PC),r5      ! r5 = [0x0607E940]
    mov.w   @(0x5E,PC),r0      ! offset for collision partner
    mov.l   @(0x68,PC),r6      ! r6 = 0x000F0000 (X distance threshold)
    mov.l   @r5,r5              ! r5 = car struct

    mov.l   @(r0,r5),r4        ! r4 = collision partner ptr (or car[+0x118])
    mov.w   @(0x58,PC),r0      ! offset for collision partner field B
    mov.l   @(r0,r5),r14       ! r14 = other car struct (or null)
    tst     r14,r14             ! other car exists?
    bt      .d12c_no_other      ! no -> use own car distances

    ! === Has collision partner ===
    ! Z distance = other.Z - self.Z + other.bump_Z - self.bump_Z
    mov.l   @(0x10,r14),r7     ! other.X
    mov.l   @(0x10,r5),r3      ! self.X
    mov.l   @(0x18,r14),r2     ! other.bump_Z
    sub     r3,r7               ! delta_X = other.X - self.X
    add     r2,r7               ! + other.bump_Z
    mov.l   @(0x18,r5),r3      ! self.bump_Z
    mov.l   @(0x50,PC),r2      ! 0x00080000 (Z proximity threshold)
    sub     r3,r7               ! delta_Z = full Z separation
    cmp/ge  r2,r7               ! Z separation >= 0x80000?
    bt      .d12c_z_ok          ! no collision on Z

    ! Z too close: use other car as collision target
    mov     r14,r4              ! r4 = other car
    bra     .d12c_exit
    mov.l   @r15+,r14           ! (delay slot, popping r14)

.d12c_z_ok:
    ! Check X distance for the collision partner
    mov.l   @(0x10,r4),r2      ! partner.X
    mov.l   @(0x10,r5),r3      ! self.X
    mov.l   @(0x18,r4),r1      ! partner.Z
    sub     r3,r2               ! delta_X
    add     r1,r2               ! + partner.bump_Z
    mov.l   @(0x18,r5),r3      ! self.bump_Z
    mov     r2,r5
    sub     r3,r5               ! full X separation
    cmp/ge  r6,r5               ! >= 0x0F0000? (too far for collision)
    bt      .d12c_confirmed     ! close enough -> confirmed
    bra     .d12c_exit
    mov.l   @r15+,r14

.d12c_confirmed:
    bra     .d12c_return
    nop

.d12c_no_other:
    ! Same X distance check but without the Z partner
    mov.l   @(0x10,r4),r2
    mov.l   @(0x10,r5),r3
    mov.l   @(0x18,r4),r1
    sub     r3,r2
    add     r1,r2
    mov.l   @(0x18,r5),r3
    mov     r2,r5
    sub     r3,r5
    cmp/ge  r6,r5
    bt      .d12c_confirmed_2
    bra     .d12c_exit
    mov.l   @r15+,r14

.d12c_confirmed_2:
.d12c_return:
    rts
    mov.l   @r15+,r14

.d12c_exit:
    ! Fall through to exit (already popped r14 in delay slot above)
    ! ...


! ==========================================================================
! FUN_0600D210 - Aggressive Collision Response (Speed-Based Push)
! ==========================================================================
! Applies a speed-based force when two cars collide at high speed.
! Pushes the slower car back by adjusting its speed field.
!
! Speed delta must be within range [pool1, pool2] to trigger.
! Push direction: if other > self, push self back (-16); else push forward (+16).
! Result clamped to [0, 0x0800].
! Sets collision counter to 64 frames.

FUN_0600D210:       ! 0x0600D210
    mov.l   @(0x64,PC),r5      ! r5 = [0x0607E940]
    mov.l   @(0x68,PC),r4      ! r4 = [0x0607E944]
    mov.w   @(0x52,PC),r0      ! offset for speed field (0x01FC)
    mov.l   @r5,r5              ! r5 = self car
    mov.l   @r4,r4              ! r4 = other car

    mov.l   @(r0,r5),r3        ! self speed value
    mov.l   @(r0,r4),r4        ! other speed value
    mov     r4,r6
    sub     r3,r6               ! r6 = speed delta = other - self

    ! Range check on speed delta
    mov.w   @(0x46,PC),r3      ! lower bound (0xFD00 = -768 signed)
    cmp/ge  r3,r6               ! delta >= lower bound?
    bf      .d210_exit          ! too negative -> skip
    mov.w   @(0x42,PC),r3      ! upper bound (0x0300 = 768)
    cmp/gt  r3,r6               ! delta > upper bound?
    bt      .d210_exit          ! too positive -> skip

    ! Determine push direction
    mov.w   @(0x38,PC),r0      ! offset for force field
    mov.l   @(r0,r5),r3        ! current force value
    cmp/gt  r4,r3               ! self force > other speed?
    bf      .d210_push_back
    bra     .d210_apply
    add     #-16,r4             ! push back (delay slot)
.d210_push_back:
    add     #16,r4              ! push forward

.d210_apply:
    ! Clamp result to [0, max]
    cmp/pz  r4                  ! result >= 0?
    bt      .d210_check_max     ! yes -> check upper bound
    mov     #0,r3               ! clamp to 0
    mov.w   @(0x2A,PC),r0      ! offset
    bra     .d210_store
    mov.l   r3,@(r0,r5)        ! store 0

.d210_check_max:
    mov.w   @(0x20,PC),r3      ! max value (0x0800 = 2048)
    cmp/gt  r3,r4               ! result > max?
    bf      .d210_store_val     ! no -> store as-is
    mov.w   @(0x1A,PC),r3      ! max value again
    mov.w   @(0x16,PC),r0      ! offset
    mov.l   r3,@(r0,r5)        ! store max
    bra     .d210_set_timer
    nop

.d210_store_val:
    mov.w   @(0xE,PC),r0       ! offset
    mov.l   r4,@(r0,r5)        ! store result

.d210_set_timer:
    ! Set collision counter to 64 frames
    mov     #64,r3
    mov.w   @(0x12,PC),r0      ! offset for collision counter
    mov.l   r3,@(r0,r5)        ! counter = 64

.d210_exit:
    rts
    nop


! ==========================================================================
! FUN_0600D0B8 - Simple Collision (No Detailed Partner Info)
! ==========================================================================
! Fallback collision handler when geometry classification returns no details.
! Checks collision flags (0x00C00000), compares car positions and speeds,
! then adjusts the force/speed field with clamping.
!
! Used when FUN_06035168 returns 0 for the collision detail field.

FUN_0600D0B8:       ! 0x0600D0B8
    mov.w   @(0x56,PC),r7      ! r7 = negative adjustment value
    mov.l   @(0x64,PC),r5      ! r5 = [0x0607E944] (other car ptr)
    mov.l   @(0x64,PC),r4      ! r4 = [0x0607E940] (self car ptr)
    mov.l   @r4,r6              ! r6 = self car struct
    mov     r6,r3
    mov.l   @r3,r2              ! car[0] = flags
    mov.l   @(0x60,PC),r3      ! 0x00C00000 (collision mask)
    and     r3,r2
    tst     r2,r2               ! collision bits set?
    bt/s    .d0b8_exit          ! no -> exit
    mov.l   @r5,r5              ! r5 = other car struct (delay slot)

    ! Compare position fields between cars
    mov.w   @(0x42,PC),r0      ! offset for position/force field
    mov.l   @(r0,r5),r3        ! other car value
    mov.l   @(r0,r6),r2        ! self car value
    cmp/ge  r2,r3               ! other >= self?
    bt      .d0b8_other_ahead

    ! Self ahead: read force, add negative adjustment
    mov.w   @(0x38,PC),r0
    mov.l   @(r0,r5),r4
    bra     .d0b8_clamp
    add     r7,r4               ! force += negative (push back)

.d0b8_other_ahead:
    ! Other ahead: read force, add positive adjustment
    mov.w   @(0x30,PC),r0
    mov.l   @(r0,r5),r4
    mov.w   @(0x2E,PC),r2      ! positive adjustment (0xFE00 or similar)
    add     r2,r4               ! force += positive (push forward)

.d0b8_clamp:
    ! Clamp to [0, max]
    cmp/pz  r4
    bt      .d0b8_check_max
    mov     #0,r2
    mov.w   @(0x26,PC),r0
    mov.l   r2,@(r0,r6)        ! force = 0
    bra     .d0b8_store_timer
    nop

.d0b8_check_max:
    mov.w   @(0x20,PC),r3      ! max value (0x0800)
    cmp/gt  r3,r4
    bf      .d0b8_store
    mov.w   @(0x1A,PC),r3      ! max value
    mov.w   @(0x16,PC),r0
    mov.l   r3,@(r0,r6)
    bra     .d0b8_store_timer
    nop

.d0b8_store:
    mov.w   @(0xE,PC),r0
    mov.l   r4,@(r0,r6)        ! store clamped force

.d0b8_store_timer:
    mov.w   @(0xE,PC),r0
    mov.l   r7,@(r0,r6)        ! store timer/flag value

.d0b8_exit:
    rts
    nop


! ==========================================================================
! FUN_0600C928 - Speed Reduction on Collision
! ==========================================================================
! Reduces car speed when active collision is happening.
! Reads car[+0x0C] (speed-related field), shifts right and masks to get
! a reduction factor, clamps it to a minimum, then subtracts from
! car[+0x48] and car[+0x50].
!
! Called from: FUN_0600C5D6 (collision path), FUN_0600C74E (AI path)

FUN_0600C928:       ! 0x0600C928
    mov.l   @(0xC,r4),r5       ! r5 = car[+0xC] (speed/direction)
    mov.w   @(0x38,PC),r7      ! r7 = min reduction (pool constant)
    shlr8   r5                  ! r5 >>= 8
    shlr    r5                  ! r5 >>= 1 (total >>= 9)
    extu.w  r5,r5               ! mask to 16-bit
    mov     r5,r3
    shll16  r5                  ! r5 <<= 16
    sub     r3,r5               ! r5 = (val<<16) - val = val * 65535
    shar    r5                  ! >>= 1
    shar    r5                  ! >>= 2
    shar    r5                  ! >>= 3
    shar    r5                  ! >>= 4
    shar    r5                  ! >>= 5
    shar    r5                  ! >>= 6
    shar    r5                  ! >>= 7
    shar    r5                  ! >>= 8 (total: val * 65535 >> 8 = val * ~256)
    extu.w  r5,r6

    ! Clamp to minimum
    cmp/ge  r7,r6               ! reduction >= min?
    bt      .c928_use_min       ! yes -> clamp to min
    bra     .c928_apply
    mov     r6,r2               ! use calculated value
.c928_use_min:
    mov     r7,r2               ! use minimum

.c928_apply:
    ! Subtract from two speed-related fields
    mov     #72,r0              ! offset 0x48
    mov.l   @(r0,r4),r3        ! car[+0x48]
    sub     r2,r3               ! reduce speed
    mov.l   r3,@(r0,r4)        ! store back

    mov     #80,r0              ! offset 0x50
    rts
    mov.l   r3,@(r0,r4)        ! car[+0x50] = same reduced value


! ==========================================================================
! FUN_0600C970 - Speed Boost from Course Table
! ==========================================================================
! Reads a per-segment speed boost value from a lookup table and applies it.
! Table at 0x0605A1E0 is indexed by (segment_index - 69) * 2.
! Only applies when segment index is in range [69, 98].
!
! This is likely a difficulty/rubber-banding mechanism:
! certain course segments give AI cars a speed boost.
!
! Called from: FUN_0600C74E (AI path only, when car[+4] == 0)

FUN_0600C970:       ! 0x0600C970
    mov.w   @(0x70,PC),r0      ! offset for segment index field
    mov     #69,r3              ! lower bound (0x45)
    mov.l   @(r0,r4),r5        ! r5 = segment index
    cmp/ge  r3,r5               ! index >= 69?
    bf      .c970_exit          ! no -> no boost

    mov     #98,r3              ! upper bound (0x62)
    cmp/gt  r3,r5               ! index > 98?
    bt      .c970_exit          ! yes -> no boost

    ! Calculate table offset: (index - 69) * 2
    add     #-69,r5             ! r5 -= 69
    shll    r5                  ! r5 *= 2 (word-sized entries)
    mov.l   @(0x60,PC),r3      ! r3 = 0x0605A1E0 (speed boost table)
    add     r3,r5               ! r5 = &table[index - 69]
    mov.w   @r5,r2              ! r2 = boost value (signed word)

    ! Apply boost to speed
    mov.l   @(0xC,r4),r1       ! r1 = car[+0x0C] (accumulator)
    add     r2,r1               ! acc += boost
    mov.l   r1,@(0xC,r4)       ! store back

.c970_exit:
    rts
    nop


! ==========================================================================
! SUMMARY: Collision System Flow
! ==========================================================================
!
! Every frame, FUN_0600C5D6 runs for the player car:
!
!   1. FUN_0600CD40: "Where am I on the track?"
!      - Computes angle to track segment center
!      - Detects if car is off-track (beyond segment width)
!      - Returns track segment pointer
!
!   2. Decision tree:
!      - Mode 2 (replay): always course-correct (FUN_0600CA96)
!      - Active collision timer: course-correct (healing)
!      - No collision partner + flags clear: heading update (FUN_0600CC38)
!      - Collision detected: dispatch to response (FUN_0600CF58)
!
!   3. FUN_0600CF58 classifies the collision:
!      - Head-on (bit 2): passive response or heading snap
!      - Side hit (bit 1):
!        - High speed (mode 2): aggressive push (FUN_0600D210)
!        - Low speed (mode 1): heading adjustment proportional to speed
!        - Default: passive separation (FUN_0600D12C)
!
!   4. Position integration:
!      - Heading -> direction via sin/cos table (FUN_06027358)
!      - X += speed * sin(heading)
!      - Z += speed * cos(heading)
!      - Y = 0 (ground plane)
!      - OR: collision path adjusts position via terrain query
!
! AI cars use FUN_0600C74E which is a simplified version:
!   - Always does course correction (no collision response dispatch)
!   - Gets speed boost from course table (segments 69-98)
!   - Same heading->position integration
!
! Key Constants:
!   Speed threshold for collision: 150 (0x96)
!   Heading dead zone: ±8
!   Course correction step: ±4 (gentle) or ±8 (normal)
!   Off-track threshold: [0x0607EA9C] (configurable)
!   Aggressive collision range: [-768, 768] speed delta
!   Max force from collision: 2048 (0x800)
!   Collision timer from aggressive: 64 frames
!   Speed boost table: 0x0605A1E0, segments [69,98], AI only
