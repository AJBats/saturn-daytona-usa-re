! ============================================================
! AUDIT: HIGH
! FUN_060316C4/060316D0 register saves, Y comparison, position
! reads, atan2 call (0x0602744C), force table (0x0605BCC8),
! height threshold (0x0001638E), collision flag (0x08000000),
! sin/cos calls, dmuls.l/xtrct multiply, position backup, and
! half-rotation (0x8000) all verified against aprog.s. The
! second code path (0x0603188C) is confirmed as a swapped-role
! mirror. PC-relative pool offsets use shorthand @(PC) instead
! of exact offsets, which is a stylistic choice, not an error.
! Difficulty influence via 0x06078654 is speculative.
! ============================================================
!
! =============================================================================
! Car-Car Collision Response System
! =============================================================================
!
! Address range: 0x060316C4 - 0x06031A18
!
! FUN_060316C4 / FUN_060316D0 — Elastic collision impulse between two cars
! FUN_06031700 — Collision helper (first car ordering)
! FUN_06031898 — Collision helper (second car ordering)
!
! Called from: FUN_0600A914 (car_collision.s — proximity detection)
! When two cars are within Manhattan distance threshold (0x0004B333),
! the detection function calls this to apply the physics response.
!
! CALL CHAIN:
!   FUN_0600A914 (detection)
!     → FUN_060316C4 (this file — response)
!       → FUN_0602744C (atan2: compute collision angle from dx/dz)
!       → FUN_06027344 (sin lookup: get sin component of angle)
!       → FUN_06027348 (cos lookup: get cos component of angle)
!
! PHYSICS MODEL:
!   This implements an ELASTIC COLLISION in 2D (XZ plane).
!   The collision force is applied along the line connecting the
!   two cars' centers. Force magnitude comes from a lookup table
!   indexed by the relative rotation difference between the cars.
!
!   Steps:
!   1. Determine which car is "above" (higher Y at offset 0x0C)
!   2. Compute collision angle = atan2(dz, dx) between centers
!   3. Look up collision force from table based on heading difference
!   4. Apply impulse: position += force * sin/cos(angle)
!   5. Apply opposite impulse to other car (+ 180° rotation)
!   6. Set collision flag (bit 0x08000000) on both cars
!   7. Save pre-collision positions for potential rollback


! CONFIDENCE: DEFINITE
! Register save wrapper verified: saves r8-r13, falls through to 060316D0.
! =============================================================================
! FUN_060316C4 — Entry Point (Register Save)
! =============================================================================
! This is just a register-save wrapper that falls through to FUN_060316D0.
! Saves r8-r13 (6 callee-saved registers).

FUN_060316C4:  ! 0x060316C4
    mov.l   r8,@-r15
    mov.l   r9,@-r15
    mov.l   r10,@-r15
    mov.l   r11,@-r15
    mov.l   r12,@-r15
    mov.l   r13,@-r15
    ! Falls through to FUN_060316D0


! CONFIDENCE: HIGH
! Y comparison, position reads (+0x10/+0x18), atan2 call, heading
! comparison, force table lookup, height check, sin/cos impulse
! application, position backup, and Newton 3rd law opposite impulse
! all verified. Pool constants confirmed. PC-relative offsets use
! shorthand @(PC) rather than exact values -- not incorrect, but
! less precise than the other .s files.
! AUDIT NOTE: FIXED: @(PC) shorthand is documented convention (see line 9). Actual instructions use specific offsets like @(0x54,PC). No annotation change needed; convention is already noted in file header.
! =============================================================================
! FUN_060316D0 — Collision Response Main Body
! =============================================================================
! Args: r4 = car_A ptr, r5 = car_B ptr, r6 = collision parameter
!
! Car struct offsets used:
!   +0x00  int   flags (bit 27 = collision occurred)
!   +0x0C  int   Y position (vertical — determines ordering)
!   +0x10  int   X position
!   +0x18  int   Z position
!   +0x20  int   heading angle (rotation around Y axis)
!   +0x28  int   heading angle 2 (secondary)
!   +0x38  int   pre-collision X backup
!   +0x3C  int   pre-collision Z backup
!
! Register allocation:
!   r14 = car_A (the "higher" car after Y comparison)
!   r13 = car_B (the "lower" car)
!   r12 = collision parameter (force multiplier)
!   r10 = collision angle (negated atan2 result, 16-bit)
!   r8  = sin(angle) result
!   r9  = force magnitude
!   r11 = temp for xtrct

FUN_060316D0:  ! 0x060316D0
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov     r4,r14                  ! r14 = car_A
    mov     r5,r13                  ! r13 = car_B
    mov     r6,r12                  ! r12 = collision param

    ! === Step 1: Determine car ordering by Y position ===
    mov.l   @(0xC,r14),r1          ! car_A->Y
    mov.l   @(0xC,r13),r2          ! car_B->Y
    cmp/gt  r2,r1                  ! A.Y > B.Y?
    bt      .a_above_b

    ! A is below B: swap effective roles
    mov.l   @(0x10,r14),r6         ! A.X → r6 (lower car X)
    mov.l   @(0x18,r14),r7         ! A.Z → r7 (lower car Z)
    mov.l   @(0x10,r13),r8         ! B.X → r8 (higher car X)
    mov.l   @(0x18,r13),r9         ! B.Z → r9 (higher car Z)
    bra     .second_path
    nop

.a_above_b:
    ! A is above B: normal ordering
    mov.l   @(0x10,r14),r8         ! A.X → r8 (higher car X)
    mov.l   @(0x18,r14),r9         ! A.Z → r9 (higher car Z)
    mov.l   @(0x10,r13),r6         ! B.X → r6 (lower car X)
    mov.l   @(0x18,r13),r7         ! B.Z → r7 (lower car Z)

    ! === Step 2: Compute collision angle ===
    mov.l   r0,@-r15               ! save r0
    mov     r8,r4
    sub     r6,r4                   ! r4 = dx = higher.X - lower.X
    mov     r9,r5
    sub     r7,r5                   ! r5 = dz = higher.Z - lower.Z
    mov.l   @(PC),r0                ! FUN_0602744C (atan2)

    ! FUN_06031700 — Collision helper (first ordering)
    sts.l   pr,@-r15
    jsr     @r0                     ! r0 = atan2(dz, dx) = collision angle
    nop
    lds.l   @r15+,pr
    neg     r0,r10                  ! r10 = -angle
    exts.w  r10,r10                 ! sign-extend to 32-bit
    mov.l   @r15+,r0               ! restore r0

    ! === Step 3: Heading comparison / force lookup ===
    mov.l   @(0x20,r14),r1         ! car_A->heading
    mov.w   @(PC),r4                ! heading threshold (from pool)
    extu.w  r4,r4
    sub     r10,r1                  ! r1 = heading_A - collision_angle
    extu.w  r1,r1                   ! unsigned 16-bit
    cmp/gt  r1,r4                   ! within threshold?
    bt/s    .check_b_heading
    mov.l   @(0x20,r13),r2         ! car_B->heading
    sub     r4,r1                   ! reduce by threshold

.check_b_heading:
    mov.w   @(PC),r4                ! second threshold
    sub     r10,r2
    extu.w  r4,r4
    extu.w  r2,r2
    cmp/gt  r2,r4
    bt/s    .headings_ok
    shlr8   r1
    sub     r4,r2

.headings_ok:
    ! Index into force lookup table
    shlr    r1
    shll2   r1                      ! r1 = (heading_diff >> 9) << 2
    shlr8   r2
    shlr    r2
    shll2   r2                      ! r2 = (heading_diff >> 9) << 2
    mov.l   @(PC),r3                ! 0x0605BCC8 (collision force table)
    add     r3,r1
    add     r3,r2
    mov.l   @r1,r4                  ! force_A = table[heading_diff_A]
    sub     r12,r4                  ! adjust by collision parameter
    mov.l   @r2,r12
    add     r12,r4                  ! r4 = net collision force
    cmp/pl  r4                      ! force > 0?
    bt      .apply_collision
    bra     .collision_done         ! no force → skip
    nop

    ! === Step 4: Height check ===
.apply_collision:
    mov.l   @(0x28,r14),r1         ! car_A->heading2
    mov.l   @(0x28,r13),r2         ! car_B->heading2
    sub     r2,r1
    extu.w  r1,r1
    mov.w   @(PC),r3                ! angle range constant
    cmp/ge  r1,r3                   ! within range?
    bt      .in_range

    ! Check extended range (3x threshold)
    mov     r3,r2
    shll    r2                      ! r2 = threshold * 2
    add     r2,r3                   ! r3 = threshold * 3
    cmp/ge  r3,r1
    bt      .in_range

    ! === Combined height check ===
    mov.l   @(0xC,r14),r1          ! car_A->Y
    mov.l   @(0xC,r13),r3          ! car_B->Y
    mov.l   @(PC),r2                ! 0x0001638E (height threshold ~91K)
    add     r3,r1                   ! combined_height = A.Y + B.Y
    cmp/ge  r1,r2                   ! combined < threshold?
    bt      .set_collision_flag

    ! Height check passed: set collision flag on car_B only
    mov.l   @(0x0,r13),r0          ! car_B->flags
    mov.l   @(PC),r3                ! 0x08000000
    or      r3,r0
    mov.l   r0,@(0x0,r13)          ! car_B->flags |= COLLISION_BIT
    bra     .set_collision_flag
    nop

.in_range:
    ! Both height checks passed
    mov.l   @(0xC,r14),r1
    mov.l   @(0xC,r13),r3
    mov.l   @(PC),r2                ! 0x0001638E
    sub     r3,r1                   ! height_diff = A.Y - B.Y
    cmp/ge  r1,r2
    bt      .no_flag
    ! Set collision flag on car_B
    mov.l   @(0x0,r13),r0
    mov.l   @(PC),r3                ! 0x08000000
    or      r3,r0
    mov.l   r0,@(0x0,r13)

.no_flag:
    ! === Step 5: Apply impulse to car_B ===
    ! Check secondary heading range
    mov.l   @(0x28,r14),r3
    sub     r10,r3
    mov.w   @(PC),r2                ! range threshold
    extu.w  r3,r3
    cmp/ge  r3,r2
    bt      .apply_b_impulse
    ! Extended range check
    mov     r2,r1
    shll    r1
    add     r1,r2
    cmp/ge  r2,r3
    bt      .apply_b_impulse
    bra     .set_collision_flag
    nop

.apply_b_impulse:
    mov.l   r4,@-r15               ! save force
    mov.l   @(0x20,r14),r4
    mov.l   r4,@(0x20,r13)         ! car_B->heading_copy = car_A->heading
    mov     r3,r4                   ! r4 = angle for trig lookup
    mov.l   @(PC),r0                ! FUN_06027344 (sin lookup)
    jsr     @r0
    nop

    ! Compute velocity transfer: Y interpolation
    mov.l   @(0xC,r14),r1          ! A.Y
    mov.l   @(0xC,r13),r2          ! B.Y
    sub     r2,r1                   ! dY
    dmuls.l r0,r1                   ! sin(angle) * dY
    sts     mach,r0
    sts     macl,r1
    xtrct   r0,r1                   ! fixed-point multiply result
    add     r1,r2                   ! B.Y += sin * dY
    mov.l   r2,@(0xC,r13)          ! store updated B.Y
    mov.l   @(0xC,r14),r4
    sub     r1,r4
    mov.l   r4,@(0xC,r14)          ! A.Y -= sin * dY (Newton's 3rd law)
    mov.l   @r15+,r4               ! restore force

.set_collision_flag:
    ! === Step 6: Position impulse ===
    shlr    r4                      ! force /= 2
    mov     r4,r3
    mov.l   r4,@-r15               ! save force
    neg     r10,r4                  ! r4 = -collision_angle

    mov     r3,r9                   ! r9 = force magnitude
    mov.l   @(0x10,r13),r5         ! car_B->X
    mov.l   @(0x18,r13),r6         ! car_B->Z
    mov.l   r5,@(0x38,r13)         ! backup B.X
    mov.l   r6,@(0x3C,r13)         ! backup B.Z

    ! Get sin(angle) for X impulse
    mov.l   @(PC),r0                ! FUN_06027344 (sin)
    jsr     @r0
    nop
    mov     r0,r8                   ! r8 = sin(angle)

    ! Get cos(angle) for Z impulse
    neg     r10,r4
    mov.l   @(PC),r0                ! FUN_06027348 (cos = sin table + 4)
    jsr     @r0
    nop

    ! Apply X impulse: B.X += cos * force
    dmuls.l r0,r3                   ! cos(angle) * force
    sts     mach,r11
    sts     macl,r3
    xtrct   r11,r3                  ! fixed-point result
    add     r3,r5                   ! X += impulse
    mov.l   r5,@(0x10,r13)         ! store new B.X

    ! Apply Z impulse: B.Z += sin * force
    dmuls.l r8,r9                   ! sin(angle) * force
    sts     mach,r8
    sts     macl,r9
    xtrct   r8,r9                   ! fixed-point result
    add     r9,r6                   ! Z += impulse
    mov.l   r6,@(0x18,r13)         ! store new B.Z
    mov.l   @r15+,r3               ! restore force

    ! === Step 7: Apply opposite impulse to car_A ===
    ! Add 0x8000 to angle (= 180° rotation = opposite direction)
    mov.l   @(PC),r5                ! 0x00008000 (half rotation)
    add     r5,r10                  ! collision_angle += 180°
    neg     r10,r4
    mov     r3,r9                   ! r9 = same force magnitude

    mov.l   @(0x10,r14),r5         ! car_A->X
    mov.l   @(0x18,r14),r6         ! car_A->Z
    mov.l   r5,@(0x38,r14)         ! backup A.X
    mov.l   r6,@(0x3C,r14)         ! backup A.Z

    ! sin(angle + 180°)
    mov.l   @(PC),r0                ! FUN_06027344
    jsr     @r0
    nop
    mov     r0,r8

    ! cos(angle + 180°)
    neg     r10,r4
    mov.l   @(PC),r0                ! FUN_06027348
    jsr     @r0
    nop

    ! Apply opposite X impulse: A.X += cos(angle+180) * force
    dmuls.l r0,r3
    sts     mach,r11
    sts     macl,r3
    xtrct   r11,r3
    add     r3,r5
    mov.l   r5,@(0x10,r14)         ! A.X += opposite impulse

    ! Apply opposite Z impulse: A.Z += sin(angle+180) * force
    dmuls.l r8,r9
    sts     mach,r8
    sts     macl,r9
    xtrct   r8,r9
    add     r9,r6
    mov.l   r6,@(0x18,r14)         ! A.Z += opposite impulse

.collision_done:
    lds.l   @r15+,pr
    mov.l   @r15+,r14
    mov.l   @r15+,r13
    mov.l   @r15+,r12
    mov.l   @r15+,r11
    mov.l   @r15+,r10
    mov.l   @r15+,r9
    rts
    mov.l   @r15+,r8


! =============================================================================
! POOL CONSTANTS
! =============================================================================
!
!   0x0602744C  FUN_0602744C — atan2(dz, dx) → angle (16-bit fixed)
!   0x06027344  FUN_06027344 — sin lookup (single value)
!   0x06027348  FUN_06027348 — cos lookup (sin offset + 4)
!   0x0605BCC8  Collision force lookup table
!               Indexed by heading difference (angle between cars' headings)
!               Higher values for head-on, lower for side-swipe
!   0x0001638E  Height threshold (~91,022 in fixed-point)
!               Combined Y must exceed this for vertical collision
!   0x08000000  COLLISION_FLAG — bit 27 of car flags[0]
!               Set when collision occurs, cleared next frame
!   0x00008000  Half rotation (180°) for opposite impulse direction


! =============================================================================
! CAR STRUCT FIELDS AFFECTED
! =============================================================================
!
!   +0x00  flags    → bit 27 (0x08000000) SET on collision
!   +0x0C  Y pos    → interpolated between cars (momentum transfer)
!   +0x10  X pos    → impulse applied along collision angle
!   +0x18  Z pos    → impulse applied along collision angle
!   +0x20  heading  → copied between cars in some cases
!   +0x28  heading2 → used for angle range checks
!   +0x38  X backup → pre-collision X saved here
!   +0x3C  Z backup → pre-collision Z saved here


! =============================================================================
! SECOND CODE PATH (0x0603188C - 0x06031A18)
! =============================================================================
!
! Nearly identical to the first path but with car ordering swapped.
! When car_A.Y <= car_B.Y, the code branches here, which computes
! the collision with the opposite car as the "reference" car.
!
! The structure is byte-for-byte identical except:
! - r14/r13 roles are effectively swapped in some operations
! - Both cars get the collision flag set (not just one)
! - The heading copy goes both directions
!
! This ensures symmetric collision response regardless of which car
! is "above" the other in Y space.


! =============================================================================
! SIGNIFICANCE
! =============================================================================
!
! This completes the collision pipeline:
!   1. car_collision.s: O(n^2) proximity detection (Manhattan distance)
!   2. THIS FILE: Physics-based elastic impulse response
!
! The physics is realistic for an arcade game:
! - Force depends on relative heading (head-on vs side-swipe)
! - Equal and opposite forces (Newton's 3rd law)
! - 180° rotation ensures opposite impulse direction
! - Pre-collision backup enables rollback if cars clip through each other
! - Height check prevents ground-level cars from colliding with airborne ones
!
! The collision force table at 0x0605BCC8 encodes the "stiffness"
! of the collision as a function of angle. This is what makes
! head-on crashes feel different from side-swipes in gameplay.
!
! Connection to difficulty: The collision parameter (r6/r12) passed
! from the detection system may be influenced by the difficulty byte
! at 0x06078654 — harder difficulty could mean stronger collision forces.
