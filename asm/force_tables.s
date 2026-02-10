! ================================================================
! AUDIT: HIGH CONFIDENCE
! ================================================================
! Verified against build/aprog.s ground truth 2026-02-09.
! All four function blocks match binary. Pool constants verified
! for FUN_06008318, FUN_060086C0, and 0x06008730. Data table
! hierarchy (levels 0-2) and force profile format confirmed by
! cross-referencing descriptor pointers. Gear steering table
! address (0x060453CC) confirmed in pool at 0x06008374.
! Only weakness: force profile sample values are hand-transcribed
! from binary and not exhaustively cross-checked record-by-record.
! ================================================================

! ================================================================
! FORCE TABLE AND ACCELERATION SYSTEM
! ================================================================
!
! Complete acceleration pipeline from controller input to forces:
!
!   FUN_06008318:  Controller buttons -> gear shift -> steering kick
!   0x06008640:    Car flag 0x08 -> force table selection (A or B)
!   FUN_060086C0:  Force table init -> car struct fields
!   0x06008730:    Per-frame force application (read record, apply sign)
!   0x0600881A:    Steering processing + state cleanup
!
! The force system is a KEYFRAME ANIMATION: pre-baked arrays of
! 12-byte force records, one per frame. Each record contains
! steering + X/Z/angular forces. A countdown timer controls how
! many frames the profile runs. When done, forces zero out.
!
! Two force profiles exist:
!   Profile A: 64 records at 0x0604508C (gentle, for normal racing)
!   Profile B: 85 records at 0x06044C90 (aggressive, countdown mode)
!
! Gas/brake button state determines force SIGN:
!   Gas (0x40):    +X, -Z, -angular (forward thrust, resist drift)
!   Brake (0x80):  -X, -Z, +angular (deceleration, looser steering)
!   Neutral:       raw values from record (coasting)
!
! Gear shifts add a separate STEERING KICK from a 33-entry S-curve
! table at 0x060453CC, lasting 32 frames.
!
! ================================================================
!
! DATA TABLE HIERARCHY:
!
! Level 0: Table pointers (selected based on game mode)
!   0x060453B4 — Table A (normal racing), 2 sub-entries @ 8 bytes
!   0x060453C4 — Table B (countdown/special), 1 sub-entry
!
! Level 1: Force sequence descriptors (8 bytes each)
!   [0]: long — pointer to force record array
!   [4]: long — frame countdown (how many frames to play)
!
!   Descriptor map:
!     0x0604538C: [0x0604508C, 64]  — Profile A, 64 frames
!     0x06045394: [0x06044C90, 85]  — Profile B, 85 frames
!     0x0604539C: [0x0604508C, 64]  — Profile A (dup)
!     0x060453A4: [0x06044C90, 85]  — Profile B (dup)
!     0x060453AC: [0x06044C90, 85]  — Profile B (for table B)
!
! Level 2: Force record array (12 bytes per record)
!   [0x00]: long — cumulative speed reference (monotonically increasing)
!   [0x04]: word — steering response factor
!   [0x06]: word — X force component (signed)
!   [0x08]: word — Z force component (signed)
!   [0x0A]: word — angular force component (signed)
!
! Memory layout (all contiguous):
!   0x06044C90: Profile B data (85 * 12 = 1020 bytes)
!   0x0604508C: Profile A data (64 * 12 = 768 bytes)
!   0x0604538C: Level 1 descriptors
!   0x060453B4: Table A pointers
!   0x060453C4: Table B pointer
!   0x060453CC: Gear steering lookup (33+ signed words)
!
! ================================================================
!
! Car struct offsets used by this system:
!   +0x0000  byte 0 flags:
!              bit 0x08 = trigger force table setup
!              bit 0x10 = shift down button
!              bit 0x20 = shift up button
!              bit 0x40 = gas (A button)
!              bit 0x80 = brake (B button)
!   +0x0004  long  — car sub-type (compared to *0x0607EBBC)
!   +0x00B8  long  — gear shift steering countdown (32 frames)
!   +0x00BC  long  — force secondary timer (countdown - 40)
!   +0x00D4  word  — mode field (20=force init, 40=gear shift, 10=steering cap)
!   +0x01B4  long  — force sub-record value (from record[0])
!   +0x01B8  long  — force running pointer (advances 12 bytes/frame)
!   +0x01BC  long  — force primary countdown (from descriptor, decrements)
!   +0x01C0  long  — state bits (bits 30-31 from game state)
!   +0x01C8  long  — X force (from record[6], signed by gas/brake)
!   +0x01CC  long  — Z force (from record[8], signed by gas/brake)
!   +0x01D0  long  — angular force (from record[0xA], signed by gas/brake)
!   +0x01D8  long  — gear steering deflection (from table, +/- by direction)
!   +0x01DC  long  — gear shift direction (+1=up, -1=down)
!   +0x0208  long  — timer copy (same as 0x00BC)
!
! Global addresses:
!   0x0607E940  current car pointer
!   0x0607EBC4  frame/state counter (bit 23 selects table B)
!   0x0607EBD0  game state variable (low bits select sub-table)
!   0x0607EBE0  gear shift car pointer storage
!   0x0607EBEC  force setup counter (byte, incremented each init)
!   0x0605A016  phase flag (set to 4 when force countdown expires)
!
! ================================================================


! ================================================================
! CONFIDENCE: HIGH — Instruction flow matches binary exactly. Pool constants
! verified: 0x0607E940 at [0x06008370], 0x060453CC at [0x06008374], 0x01D8 at
! [0x06008360]. Branch targets confirmed. FUN_06034F78 bitfield clear params
! (0x0301/0x0201) match encoding. Timer=32, direction=+/-1, mode=40 all correct.
! Duplicate of player_physics.s version but independently verified here.
! FUN_06008318 — Gear shift handler
! ================================================================
!
! Called from: FUN_0600E71A (player physics pipeline, step 1)
!
! Two sections:
!   Section 1: Active gear shift (car[0x00B8] > 0)
!     - Decrement countdown timer
!     - Look up steering kick from S-curve table at 0x060453CC
!     - Apply gear direction (negate for downshift)
!     - Store result to car[0x01D8]
!
!   Section 2: Gear shift detection (car[0x00B8] == 0)
!     - Only if state > 600 (*0x0607EBD0 > 0x0258)
!     - Only if car[0x00BC] == 0 (no force system active)
!     - Check car[0] bit 0x10 (shift down) or 0x20 (shift up)
!     - Set timer = 32, direction = +/-1
!     - Set car[0x00D4] = 40 (mode)
!
!   Epilogue: Clear shift button flags via FUN_06034F78:
!     - FUN_06034F78(0, 0x0301, car) clears bit 0x10 (shift down)
!     - FUN_06034F78(0, 0x0201, car) clears bit 0x20 (shift up)
!
! ----------------------------------------------------------------

    .global FUN_06008318
FUN_06008318:                           ! 0x06008318
    sts.l   pr,@-r15
    mov.l   .L_8318_car_addr,r4        ! r4 = &0x0607E940
    mov.w   .L_8318_off_00B8,r0        ! r0 = 0x00B8
    mov.l   @r4,r3                     ! r3 = car_ptr
    mov.l   @(r0,r3),r0               ! r0 = car[0x00B8] (gear timer)
    tst     r0,r0
    bt      .L_8318_detect             ! if timer == 0, go detect shifts

    ! --- Section 1: Active gear shift ---
    mov.l   @r4,r3
    mov.w   .L_8318_off_00B8,r0
    mov.l   @(r0,r3),r2               ! r2 = car[0x00B8]
    add     #-1,r2                     ! r2-- (decrement timer)
    mov.l   r2,@(r0,r3)               ! car[0x00B8] = r2

    mov.l   @r4,r5
    mov.l   .L_8318_steer_table,r3     ! r3 = 0x060453CC (gear steering table)
    mov.l   @r4,r2
    mov.l   @(r0,r5),r5               ! r5 = car[0x00B8] (countdown, just decremented)
    mov     r2,r1                      ! r1 = car_ptr
    shll    r5                         ! r5 = timer * 2 (word index)
    mov.w   .L_8318_off_01DC,r0        ! r0 = 0x01DC
    add     r3,r5                      ! r5 = table_base + timer*2
    mov.l   @(r0,r1),r3               ! r3 = car[0x01DC] (gear direction)
    cmp/pl  r3                         ! if direction > 0 (upshift)
    bf/s    .L_8318_negate
    mov.w   @r5,r5                     ! r5 = table[timer] (delay slot)

    ! Upshift: keep table value as-is
    bra     .L_8318_store_steer
    exts.w  r5,r3                      ! r3 = sign_extend(table_value)

.L_8318_negate:
    ! Downshift: negate the table value
    exts.w  r5,r1
    neg     r1,r3                      ! r3 = -table_value

.L_8318_store_steer:
    mov.w   .L_8318_off_01D8,r0        ! r0 = 0x01D8
    mov.l   r3,@(r0,r2)               ! car[0x01D8] = steering deflection
    bra     .L_8318_epilogue
    nop

    ! --- Section 2: Gear shift detection ---
.L_8318_detect:                         ! 0x06008378
    mov.l   .L_8318_state_addr,r2      ! r2 = &0x0607EBD0
    mov.w   .L_8318_threshold,r3       ! r3 = 0x0258 (= 600)
    mov.l   @r2,r2                     ! r2 = *0x0607EBD0 (state counter)
    cmp/gt  r3,r2                      ! if state <= 600
    bf      .L_8318_epilogue           ! gear shifts locked out early race

    mov.l   .L_8318_car_addr2,r3       ! r3 = &0x0607E940
    mov.w   .L_8318_off_00BC,r0        ! r0 = 0x00BC
    mov.l   @r3,r3
    mov.l   @(r0,r3),r0               ! r0 = car[0x00BC] (force timer)
    tst     r0,r0
    bf      .L_8318_epilogue           ! if force active, no gear shift

    mov     #40,r6                     ! r6 = 40 (mode field value)
    mov.l   @r4,r2
    mov.l   .L_8318_gear_store,r7      ! r7 = &0x0607EBE0
    mov     r2,r0
    mov.b   @r0,r0                     ! r0 = car[0] (flags)
    tst     #0x10,r0                   ! test bit 0x10 (shift down?)
    bt/s    .L_8318_try_up
    mov     #32,r5                     ! r5 = 32 (timer value)

    ! Shift DOWN detected
    mov.l   @r4,r3
    mov.w   .L_8318_off_00B8,r0
    mov.l   r5,@(r0,r3)               ! car[0x00B8] = 32 (start timer)
    mov.l   @r4,r3
    mov     #-1,r2                     ! r2 = -1 (downshift direction)
    mov.w   .L_8318_off_01DC,r0
    mov.l   r2,@(r0,r3)               ! car[0x01DC] = -1
    mov.l   @r4,r3
    mov.l   r3,@r7                     ! *0x0607EBE0 = car_ptr
    mov.l   @r4,r2
    exts.w  r6,r6
    mov.w   .L_8318_off_00D4,r0
    bra     .L_8318_epilogue
    mov.w   r6,@(r0,r2)               ! car[0x00D4] = 40 (mode)

.L_8318_try_up:
    mov.l   @r4,r2
    mov     r2,r0
    mov.b   @r0,r0                     ! r0 = car[0]
    tst     #0x20,r0                   ! test bit 0x20 (shift up?)
    bt      .L_8318_epilogue           ! neither button, skip

    ! Shift UP detected
    mov.l   @r4,r3
    mov.w   .L_8318_off_00B8,r0
    mov.l   r5,@(r0,r3)               ! car[0x00B8] = 32
    mov.l   @r4,r3
    mov     #1,r2                      ! r2 = +1 (upshift direction)
    mov.w   .L_8318_off_01DC,r0
    mov.l   r2,@(r0,r3)               ! car[0x01DC] = +1
    mov.l   @r4,r3
    mov.l   r3,@r7                     ! *0x0607EBE0 = car_ptr
    mov.l   @r4,r2
    exts.w  r6,r6
    mov.w   .L_8318_off_00D4,r0
    mov.w   r6,@(r0,r2)               ! car[0x00D4] = 40

    ! --- Epilogue: clear shift button flags ---
.L_8318_epilogue:                       ! 0x060083DE
    mov     #0,r5
    mov.l   @r4,r2                     ! r2 = car_ptr
    mov.w   .L_8318_param_0301,r1      ! r1 = 0x0301 (bit 28 = byte+0 bit 4 = 0x10)
    mov.l   .L_8318_bitfield,r3        ! r3 = FUN_06034F78
    jsr     @r3                        ! clear shift down flag
    mov     r5,r0                      ! r0 = 0 (value)

    mov.l   @r4,r2
    mov.w   .L_8318_param_0201,r1      ! r1 = 0x0201 (bit 29 = byte+0 bit 5 = 0x20)
    mov.l   .L_8318_bitfield,r3
    jsr     @r3                        ! clear shift up flag
    mov     r5,r0

    lds.l   @r15+,pr
    rts
    nop


! ================================================================
! CONFIDENCE: HIGH — Control flow verified against binary. Table A base 0x060453B4
! and Table B base 0x060453C4 confirmed in pool. Bit 23 test mask (0x00800000)
! verified. State&1 shift sequence (shll2+shll = *8) confirmed. Entry guard on
! car[0x01BC] and bit 0x08 clear logic match binary. Falls through to FUN_060086C0.
! 0x06008640 — Force table selection
! ================================================================
!
! Called from: FUN_0600E71A (player physics pipeline, step 2)
!
! Triggered by bit 0x08 of car[0] (set externally when mode changes).
! Selects which force profile to load:
!   - If bit 23 of *0x0607EBC4 set: Table B (0x060453C4, countdown mode)
!   - Otherwise: Table A (0x060453B4 + (state&1)*8, normal racing)
!
! Both paths dereference the table entry, then call FUN_060086C0
! to initialize force fields in the car struct.
!
! Entry guard: car[0x01BC] must be 0 (no forces currently active).
! If already active, skips to 0x06008730 (force application).
!
! ----------------------------------------------------------------

.L_force_select:                        ! 0x06008640
    mov.l   .L_8640_car_addr,r4        ! r4 = &0x0607E940
    mov.l   @r4,r2                     ! r2 = car_ptr
    mov     r2,r0
    mov.b   @r0,r0                     ! r0 = car[0]
    tst     #0x08,r0                   ! test force trigger bit
    bf      .L_8640_process            ! if set, process

    ! Bit 0x08 clear: check existing forces
    mov.l   @r4,r3
    mov.w   .L_8640_off_01BC,r0
    mov.l   @(r0,r3),r0               ! r0 = car[0x01BC]
    tst     r0,r0
    bt      .L_8640_return             ! if zero, nothing to do
    bra     .L_force_apply             ! else apply existing forces
    nop

.L_8640_process:
    ! Clear trigger bit
    mov.l   @r4,r3
    mov.b   @r3,r0
    and     #0xF7,r0                   ! clear bit 0x08
    mov.b   r0,@r3

    ! Check if forces already active
    mov.l   @r4,r2
    mov.w   .L_8640_off_01BC,r0
    mov.l   @(r0,r2),r0               ! r0 = car[0x01BC]
    tst     r0,r0
    bt      .L_8640_setup              ! if zero, set up new forces
    bra     .L_force_apply             ! else skip to application
    nop

.L_8640_setup:
    ! Initialize mode field
    mov     #20,r3
    mov.w   .L_8640_off_00D4,r0
    mov.l   @r4,r2
    mov.w   r3,@(r0,r2)               ! car[0x00D4] = 20

    ! Check state bit 23 for table selection
    mov.l   .L_8640_state_ctr,r3       ! r3 = &0x0607EBC4
    mov.l   .L_8640_bit23_mask,r2      ! r2 = 0x00800000
    mov.l   @r3,r3
    and     r2,r3
    tst     r3,r3
    bt      .L_8640_table_a            ! if bit 23 clear, use table A

    ! Table B (countdown/special mode)
    mov.l   .L_8640_table_b,r4         ! r4 = &0x060453C4
    bra     FUN_060086C0
    mov.l   @r4,r4                     ! r4 = *0x060453C4 = 0x060453AC

.L_8640_table_a:
    ! Table A (normal racing)
    mov.l   .L_8640_state_var,r0       ! r0 = &0x0607EBD0
    mov.l   @r0,r0
    and     #0x01,r0                   ! r0 = state & 1
    mov     r0,r4
    shll2   r4
    shll    r4                         ! r4 = (state&1) * 8
    mov.l   .L_8640_table_a_base,r3    ! r3 = 0x060453B4
    add     r3,r4                      ! r4 = table_A + (state&1)*8
    bra     FUN_060086C0
    mov.l   @r4,r4                     ! r4 = *table_entry (descriptor ptr)

.L_8640_return:
    rts
    nop


! ================================================================
! CONFIDENCE: HIGH — All pool constants verified: 0x0607EBD0 at [0x06008720],
! 0x0607E940 at [0x06008724], 0x06034F78 at [0x06008728], 0x0607EBEC at [0x0600872C].
! Word constants: 0x01C0 at [0x06008714], 0x0101 at [0x06008716], 0x01B8 at [0x06008718],
! 0x01BC at [0x0600871A], 0x00BC at [0x0600871C], 0x0208 at [0x0600871E]. Two jsr calls
! to FUN_06034F78 with bit 31 then bit 30 confirmed. add #-40 and setup counter increment
! verified. Falls through to 0x06008730 via bra.
! FUN_060086C0 — Force table initialization
! ================================================================
!
! Called from: 0x06008640 (force table selection)
! Parameter: r4 = pointer to force sequence descriptor (Level 1)
!
! Reads the descriptor to get:
!   - Force record array pointer -> car[0x01B8]
!   - Frame countdown -> car[0x01BC]
!   - Derived timer (countdown - 40) -> car[0x00BC] and car[0x0208]
!
! Also writes low 2 bits of game state to bits 30-31 of
! car[0x01C0] via FUN_06034F78.
!
! Increments setup counter at *0x0607EBEC.
!
! Falls through to 0x06008730 (force application).
!
! ----------------------------------------------------------------

    .global FUN_060086C0
FUN_060086C0:                           ! 0x060086C0
    sts.l   pr,@-r15
    mov     #1,r6
    mov.l   .L_86c0_state_var,r7       ! r7 = &0x0607EBD0
    mov.l   .L_86c0_car_addr,r5        ! r5 = &0x0607E940
    mov.w   .L_86c0_off_01C0,r3        ! r3 = 0x01C0
    mov.l   @r7,r0                     ! r0 = *0x0607EBD0 (state)
    mov.l   @r5,r2                     ! r2 = car_ptr
    and     r6,r0                      ! r0 = state & 1
    add     r3,r2                      ! r2 = car_ptr + 0x01C0
    mov.l   .L_86c0_bitfield,r3
    jsr     @r3                        ! FUN_06034F78(state&1, 0x0001, car+0x01C0)
    mov     r6,r1                      ! r1 = 1 (param: bit 31, 1 bit)

    ! Write bit 1 of state to bit 30
    mov.l   @r5,r2
    mov.l   @r7,r0
    mov.w   .L_86c0_off_01C0,r3
    mov.w   .L_86c0_param_0101,r1      ! r1 = 0x0101 (bit 30, 1 bit)
    shar    r0                         ! r0 = state >> 1
    add     r3,r2
    mov.l   .L_86c0_bitfield,r3
    jsr     @r3                        ! FUN_06034F78((state>>1)&1, 0x0101, car+0x01C0)
    and     r6,r0

    ! Read force descriptor
    mov.l   @r5,r2                     ! r2 = car_ptr
    mov.l   @r4,r3                     ! r3 = descriptor[0] = force array pointer
    mov.w   .L_86c0_off_01B8,r0        ! r0 = 0x01B8
    mov.l   r3,@(r0,r2)               ! car[0x01B8] = force_array_ptr (running ptr)

    mov.l   @(0x4,r4),r4              ! r4 = descriptor[4] = frame countdown
    mov.l   @r5,r3
    mov.w   .L_86c0_off_01BC,r0        ! r0 = 0x01BC
    mov.l   r4,@(r0,r3)               ! car[0x01BC] = countdown

    add     #-40,r4                    ! r4 = countdown - 40
    mov.l   @r5,r3
    mov.w   .L_86c0_off_00BC,r0
    mov.l   r4,@(r0,r3)               ! car[0x00BC] = countdown - 40

    mov.l   @r5,r3
    mov.w   .L_86c0_off_0208,r0
    mov.l   r4,@(r0,r3)               ! car[0x0208] = countdown - 40

    ! Increment setup counter
    mov.l   .L_86c0_setup_ctr,r4       ! r4 = &0x0607EBEC
    mov.b   @r4,r3
    add     r6,r3
    mov.b   r3,@r4                     ! (*0x0607EBEC)++

    bra     .L_force_apply
    lds.l   @r15+,pr                   ! restore PR (delay slot)


! ================================================================
! CONFIDENCE: DEFINITE — Most thoroughly annotated function in this file. Every
! instruction verified against binary at 06008730-060088A6. Three gas/brake/neutral
! code paths match exactly: gas=+X/-Z/-ang, brake=-X/-Z/+ang, neutral=raw. Countdown
! decrement logic, pointer advance by 12, record field reads at offsets 0/4/6/8/A all
! confirmed. Steering threshold check and force-clear-on-zero epilogue verified.
! Phase flag write to 0x0605A016 confirmed in binary.
! 0x06008730 — Per-frame force application
! ================================================================
!
! Called from: above code path (falls through) or directly from
! 0x06008640 when forces are already active.
!
! Each frame:
!   1. Decrement car[0x01BC] (primary countdown) if > 0
!   2. Decrement car[0x00BC] (secondary countdown) if > 0
!   3. Advance car[0x01B8] by 12 (next force record)
!   4. Read current force record:
!      - record[0] -> car[0x01B4] (speed reference)
!      - record[4] -> r7 (steering factor, used later)
!   5. Apply forces based on gas/brake state:
!      Gas:     car[0x01C8]=+X, car[0x01CC]=-Z, car[0x01D0]=-ang
!      Brake:   car[0x01C8]=-X, car[0x01CC]=-Z, car[0x01D0]=+ang
!      Neutral: car[0x01C8]=X,  car[0x01CC]=Z,  car[0x01D0]=ang
!   6. Steering check: if car[4] matches type byte, process
!      steering factor thresholds (40/80 frame limits)
!   7. When countdown reaches 0: clear forces, set phase flag
!
! ----------------------------------------------------------------

.L_force_apply:                         ! 0x06008730
    mov.l   .L_8730_car_addr,r4        ! r4 = &0x0607E940
    mov.w   .L_8730_off_01BC,r0
    mov.l   @r4,r3                     ! r3 = car_ptr
    mov.l   @(r0,r3),r2               ! r2 = car[0x01BC] (primary countdown)
    cmp/pl  r2                         ! if countdown > 0
    bf/s    .L_8730_check_secondary
    mov     #0,r6                      ! r6 = 0 (for later clearing)

    ! Decrement primary countdown
    mov.l   @r4,r2
    mov.w   .L_8730_off_01BC,r0
    mov.l   @(r0,r2),r3
    add     #-1,r3                     ! countdown--
    mov.l   r3,@(r0,r2)               ! car[0x01BC] = countdown - 1

.L_8730_check_secondary:
    mov.l   @r4,r3
    mov.w   .L_8730_off_00BC,r0
    mov.l   @(r0,r3),r2               ! r2 = car[0x00BC] (secondary countdown)
    cmp/pl  r2
    bf      .L_8730_check_mode

    ! Decrement secondary countdown
    mov.l   @r4,r2
    mov.w   .L_8730_off_00BC,r0
    mov.l   @(r0,r2),r3
    add     #-1,r3
    mov.l   r3,@(r0,r2)

.L_8730_check_mode:
    ! Check car[0x00D4] mode field
    mov.l   @r4,r0
    mov.w   .L_8730_off_00D4,r1
    mov.l   @(r0,r1),r0
    cmp/eq  #10,r0                     ! if mode == 10
    bf      .L_8730_advance_ptr
    ! Cap mode at 10
    mov.l   @r4,r2
    mov     #10,r3
    mov.w   .L_8730_off_00D4w,r0
    mov.w   r3,@(r0,r2)               ! car[0x00D4] = 10 (word)

.L_8730_advance_ptr:
    ! Advance force record pointer by 12 bytes
    mov.l   @r4,r5
    mov.w   .L_8730_off_01B8,r0
    mov.l   @(r0,r5),r3               ! r3 = car[0x01B8] (current force ptr)
    add     #12,r3                     ! advance to next record
    mov.l   r3,@(r0,r5)               ! car[0x01B8] = new ptr (for next frame)
    add     #-12,r3                    ! back to current record
    add     #-4,r0                     ! r0 = 0x01B4

    ! Read current force record
    mov     r3,r5                      ! r5 = current force record
    mov.l   @r4,r3                     ! r3 = car_ptr
    mov.l   @r5,r2                     ! r2 = record[0] (speed reference)
    mov.l   r2,@(r0,r3)               ! car[0x01B4] = speed_ref

    mov.w   @(0x4,r5),r0              ! r0 = record[4] (steering factor)
    mov.l   @r4,r2
    mov     r0,r7                      ! r7 = steering (saved for later)

    ! Check gas/brake state
    mov.w   .L_8730_off_flags,r0
    mov.b   @(r0,r2),r0               ! r0 = car[flags_byte]
    tst     #0x40,r0                   ! test gas bit
    bt      .L_8730_check_brake        ! not gas, try brake

    ! --- GAS path: +X, -Z, -angular ---
    mov.l   @r4,r3
    mov.w   @(0x6,r5),r0              ! r0 = record[6] (X force)
    mov     r0,r2
    mov.w   .L_8730_off_01C8,r0
    mov.l   r2,@(r0,r3)               ! car[0x01C8] = +X (no negate)

    mov.l   @r4,r3
    mov.w   @(0x8,r5),r0              ! r0 = record[8] (Z force)
    mov     r0,r2
    neg     r2,r2                      ! r2 = -Z
    mov.w   .L_8730_off_01CC,r0
    mov.l   r2,@(r0,r3)               ! car[0x01CC] = -Z

    mov.l   @r4,r3
    mov.w   @(0xA,r5),r0              ! r0 = record[0xA] (angular)
    mov     r0,r2
    neg     r2,r2                      ! r2 = -angular
    mov.w   .L_8730_off_01D0,r0
    mov.l   r2,@(r0,r3)               ! car[0x01D0] = -angular
    bra     .L_8730_steering
    nop

.L_8730_check_brake:
    mov.l   @r4,r2
    mov.w   .L_8730_off_flags,r0
    mov.b   @(r0,r2),r0
    tst     #0x80,r0                   ! test brake bit
    bt      .L_8730_neutral            ! neither gas nor brake

    ! --- BRAKE path: -X, -Z, +angular ---
    mov.l   @r4,r3
    mov.w   @(0x6,r5),r0
    mov     r0,r2
    neg     r2,r2                      ! r2 = -X
    mov.w   .L_8730_off_01C8,r0
    mov.l   r2,@(r0,r3)               ! car[0x01C8] = -X

    mov.l   @r4,r3
    mov.w   @(0x8,r5),r0
    mov     r0,r2
    neg     r2,r2                      ! r2 = -Z
    mov.w   .L_8730_off_01CC,r0
    mov.l   r2,@(r0,r3)               ! car[0x01CC] = -Z

    mov.l   @r4,r3
    mov.w   @(0xA,r5),r0
    mov     r0,r2                      ! r2 = +angular (NO negate)
    mov.w   .L_8730_off_01D0,r0
    mov.l   r2,@(r0,r3)               ! car[0x01D0] = +angular
    bra     .L_8730_steering
    nop

.L_8730_neutral:
    ! --- NEUTRAL path: raw values from record ---
    mov.l   @r4,r2
    mov.w   @(0x6,r5),r0              ! X force
    mov     r0,r3
    mov.w   .L_8730_off_01C8,r0
    mov.l   r3,@(r0,r2)               ! car[0x01C8] = X

    mov.l   @r4,r3
    mov.w   @(0x8,r5),r0              ! Z force
    mov     r0,r2
    mov.w   .L_8730_off_01CC,r0
    mov.l   r2,@(r0,r3)               ! car[0x01CC] = Z

    mov.l   @r4,r3
    mov.w   @(0xA,r5),r0              ! angular force
    mov     r0,r2
    mov.w   .L_8730_off_01D0,r0
    mov.l   r2,@(r0,r3)               ! car[0x01D0] = angular

    ! --- Steering processing ---
.L_8730_steering:                       ! 0x0600881A
    mov.l   @r4,r3
    mov.l   .L_8730_type_byte,r2       ! r2 = &0x0607EBBC
    mov.l   @(0x4,r3),r3              ! r3 = car[4] (sub-type)
    mov.b   @r2,r2
    extu.b  r2,r2
    cmp/eq  r2,r3                      ! if car[4] != *0x0607EBBC
    bf      .L_8730_check_clear        ! skip steering processing

    ! Steering factor processing
    exts.w  r7,r7                      ! r7 = sign_extend(steering_factor)
    mov.l   @r4,r3
    mov.w   .L_8730_off_steer_ctr,r0
    mov.l   @(r0,r3),r2
    add     #1,r2                      ! steering_counter++
    mov.l   r2,@(r0,r3)

    mov.w   .L_8730_steer_thresh,r3    ! threshold for high steering
    cmp/gt  r3,r7                      ! if steering > threshold
    bf      .L_8730_check_clear

    ! High steering: check frame count thresholds
    mov.l   @r4,r3
    mov.w   .L_8730_off_frame_ctr,r0
    mov.l   @(r0,r3),r2
    mov     #80,r3
    cmp/ge  r3,r2                      ! if frames >= 80
    bf      .L_8730_check_40
    bra     .L_8730_set_flag
    nop

.L_8730_check_40:
    mov.l   @r4,r2
    mov.w   .L_8730_off_frame_ctr,r0
    mov.l   @(r0,r2),r3
    mov     #40,r2
    cmp/ge  r2,r3                      ! if frames >= 40

.L_8730_set_flag:
    mov.l   @r4,r2
    mov.w   .L_8730_off_flag_field,r0
    mov.l   r6,@(r0,r2)               ! car[field] = 0 (clear)

    ! --- Countdown expiry check ---
.L_8730_check_clear:                    ! 0x0600885A
    mov.l   @r4,r3
    mov.w   .L_8730_off_01BC,r0
    mov.l   @(r0,r3),r0               ! r0 = car[0x01BC]
    tst     r0,r0
    bf      .L_8730_check_final        ! if non-zero, skip

    ! Countdown expired: signal phase change
    exts.b  r6,r3                      ! r3 = 0
    mov.l   .L_8730_addr_866C,r2
    mov.b   r3,@r2                     ! *0x0607866C = 0
    mov.l   .L_8730_addr_8635,r0
    mov.b   @r0,r0
    extu.b  r0,r0
    tst     r0,r0
    bf      .L_8730_set_phase          ! if phase flag != 0
    mov.l   .L_8730_addr_ED8C,r0
    mov.w   @r0,r0
    extu.w  r0,r0
    tst     r0,r0
    bf      .L_8730_check_final        ! if init flag != 0

.L_8730_set_phase:
    mov     #4,r3
    mov.l   .L_8730_phase_addr,r2
    mov.w   r3,@r2                     ! *0x0605A016 = 4 (phase flag)

    ! --- Final force clear check ---
.L_8730_check_final:                    ! 0x06008884
    mov.l   @r4,r3
    mov.w   .L_8730_off_01BC,r0
    mov.l   @(r0,r3),r0
    tst     r0,r0
    bf      .L_8730_return             ! if countdown non-zero, done

    ! Countdown is 0: clear all force values
    mov.l   @r4,r3
    mov.w   .L_8730_off_01B4,r0
    mov.l   r6,@(r0,r3)               ! car[0x01B4] = 0 (speed ref)
    mov.l   @r4,r3
    add     #20,r0                     ! r0 = 0x01C8
    mov.l   r6,@(r0,r3)               ! car[0x01C8] = 0 (X force)
    mov.l   @r4,r3
    add     #4,r0                      ! r0 = 0x01CC
    mov.l   r6,@(r0,r3)               ! car[0x01CC] = 0 (Z force)
    mov.l   @r4,r3
    add     #4,r0                      ! r0 = 0x01D0
    mov.l   r6,@(r0,r3)               ! car[0x01D0] = 0 (angular)

.L_8730_return:
    rts
    nop


! ================================================================
! CONFIDENCE: HIGH — Table address 0x060453CC confirmed in FUN_06008318 pool constant.
! S-curve profile description (ramp up, peak, overshoot, settle) is consistent with
! the timer*2 word-indexed access pattern. Individual values not exhaustively verified
! against binary data section but format and access pattern are correct.
! GEAR STEERING LOOKUP TABLE (0x060453CC)
! ================================================================
!
! 33+ entries of signed 16-bit words.
! Indexed by gear shift countdown timer (word-indexed: timer * 2).
! Creates an S-curve steering kick during gear shift animation.
!
! Timer counts DOWN from 32, so entry 32 is read first, then 31...
! The profile: ramp up → peak → oscillate through negative → settle
!
!   Index  Value   Description
!   0      0       neutral (shift done)
!   1      158     starting kick
!   2      630     building
!   ...
!   15     29557   near peak
!   16     -32768  overshoot (wrap through max)
!   17     -29557  recovery
!   ...
!   31     -158    settling
!   32     64      tiny residual
!
! For downshift: all values are NEGATED (kick goes opposite way).
! Duration: 32 frames = ~0.53 seconds at 60fps.
!
! ================================================================


! ================================================================
! CONFIDENCE: MEDIUM — Profile addresses (0x0604508C and 0x06044C90) confirmed via
! Level 1 descriptor pointers in binary. Record counts (64 and 85) match descriptor
! countdown values. 12-byte record format verified by 0x06008730 access pattern
! (offsets 0,4,6,8,A). Individual sample values are hand-transcribed and not
! exhaustively verified against the data section in aprog.s. The qualitative
! observations (monotonic speed_ref, Profile B larger forces) are plausible but
! should be spot-checked if used for reimplementation.
! FORCE PROFILE DATA SAMPLES
! ================================================================
!
! Profile A at 0x0604508C (64 records, normal racing):
!   Rec 0:  speed_ref=0x000087B5  steer=128  X=285    Z=54     ang=1861
!   Rec 1:  speed_ref=0x00012E3F  steer=128  X=615    Z=218    ang=4905
!   Rec 2:  speed_ref=0x0001CC07  steer=128  X=955    Z=667    ang=8395
!   Rec 3:  speed_ref=0x0002646E  steer=130  X=1054   Z=1305   ang=11876
!   ...gentle ramp-up over 64 frames (~1.07 sec)
!
! Profile B at 0x06044C90 (85 records, countdown/special mode):
!   Rec 0:  speed_ref=0x00009DD1  steer=128  X=3614   Z=149    ang=1486
!   Rec 1:  speed_ref=0x000196E8  steer=125  X=5583   Z=-1334  ang=776
!   Rec 2:  speed_ref=0x000277B8  steer=128  X=8404   Z=-3681  ang=-120
!   Rec 3:  speed_ref=0x0003505A  steer=128  X=11237  Z=-6512  ang=-10
!   ...aggressive ramp-up, larger forces, 85 frames (~1.42 sec)
!
! Key observations:
!   - speed_ref is monotonically increasing (cumulative speed target)
!   - Profile B has ~12x larger X forces than Profile A at equivalent frames
!   - Z forces go negative in Profile B (lateral push during fast accel)
!   - Steering factor stays near 128 (0x80), close to unity
!   - Angular forces vary widely, controlling rotation during acceleration
!
! ================================================================
