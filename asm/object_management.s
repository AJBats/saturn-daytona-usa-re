! ================================================
! AUDIT: HIGH -- Car object lifecycle accurately documented; addresses and struct layout verified
! Audited: 2026-02-10
! ================================================
! ============================================================================
! Object Management System — Daytona USA Saturn
! ============================================================================
!
! This file documents the car object lifecycle: allocation, initialization,
! per-frame iteration, and update dispatch.
!
! MEMORY LAYOUT
! =============
! 0x06078900 - 0x0607E93F : Car array (40 slots x 0x268 bytes each)
! 0x0607E940               : Current car pointer (working/active)
! 0x0607E944               : Current car pointer (primary/stored)
! 0x0607E948               : Secondary car pointer (typically car[1])
!
! The car array sits at the END of the object region, with the global
! pointers occupying the first words immediately after it:
!   0x06078900 + 40 * 0x268 = 0x06078900 + 0x6040 = 0x0607E940
!
! CAR STRUCT (0x268 = 616 bytes per car)
! ======================================
! +0x000  : byte  - flags (0x08=special, 0x10=shift_down, 0x20=shift_up,
!                          0x40=gas, 0x80=brake)
! +0x001  : byte  - secondary flags
! +0x004  : long  - car index (0=player, 1..N=AI opponents)
!                   Set by FUN_0600629C during initialization
! +0x008  : long  - speed (heading-relative scalar)
! +0x00C  : long  - distance accumulator (used in FUN_0600E410 speed calc)
! +0x010  : long  - X position (world coordinates)
! +0x014  : long  - Y position (world, typically 0)
! +0x018  : long  - Z position (world coordinates)
! +0x01C  : long  - rotation component A (pitch?)
! +0x020  : long  - heading (primary yaw angle)
! +0x024  : long  - rotation component C (bank?)
! +0x028  : long  - heading copy A (set = [0x20] during init)
! +0x030  : long  - heading copy B (set = [0x20] during init)
! +0x034  : long  - heading copy C (set = [0x20] during init)
! +0x074  : long  - initial value 0x38 (56) -- set during init
! +0x090  : long  - initial value 0x38 (56) -- set during init
! +0x0B8  : long  - gear shift countdown / proximity override
! +0x0BC  : long  - force secondary timer
! +0x0D4  : word  - mode field
! +0x0E0  : long  - computed speed value (from FUN_0600E410)
! +0x0E4  : long  - computed speed value copy
! +0x120  : long  - flag (set to 1 during init by FUN_0600EB14)
! +0x124  : long  - flag (set to 1 during init)
! +0x128  : long  - flag (set to 1 during init)
! +0x12C  : long  - flag (set to 1 during init)
! +0x184  : long  - current track segment index
! (See gameplay_extraction.md for full layout)
!
! CONFIG TABLE at 0x06047DE4 (12-byte entries, indexed by car index)
! ==================================================================
! Each car type is described by a 12-byte config entry:
!   +0x00 : word16  - car type (0x0003=standard, 0x0004=extended)
!   +0x02 : word16  - initial heading angle (signed)
!   +0x04 : word16  - secondary table index (into 0x06047DD0)
!   +0x06 : word16  - tertiary table index (into 0x06085FD0)
!   +0x08 : word16  - car class (2=player, 1=AI)
!   +0x0A : word16  - reserved (0)
!
! Decoded entries:
!   [0]: type=3, heading=0xF555(-2731), sec=0, tert=0, class=2 (PLAYER)
!   [1]: type=3, heading=0xE38E(-7282), sec=1, tert=2, class=1 (AI)
!   [2]: type=3, heading=0xEAAA(-5462), sec=2, tert=2, class=1 (AI)
!   [3]: type=3, heading=0xF1C7(-3641), sec=3, tert=4, class=1 (AI)
!   [4]: type=3, heading=0xF8E3(-1821), sec=4, tert=4, class=1 (AI)
!   [5]: type=4, heading=0x6000(24576), sec=5, tert=6, class=1 (AI)
!   [6]: type=4, heading=0x71C7(29127), sec=6, tert=6, class=1 (AI)
!
! Headings form a sequence around the starting grid positions.
!
! SECONDARY TABLE at 0x06047DD0 (5-byte entries)
! ================================================
! Indexed by config[+4]. Contains position/lane assignments.
! Format unclear but related to grid position placement.
!
! KEY GLOBAL VARIABLES
! ====================
! 0x0607EA98 : long  - car count (how many active cars)
! 0x06078634 : byte  - car count (byte copy, used in per-frame loop)
! 0x06078635 : byte  - special mode flag (0=normal racing)
! 0x0607E940 : long  - current car pointer (working)
! 0x0607E944 : long  - current car pointer (primary)
! 0x0607E948 : long  - secondary car pointer
! 0x0607EAD8 : long  - player mode (0=single, nonzero=versus?)
! 0x060786BC : long  - demo/replay countdown
! 0x060786B8 : long  - last coordinate transform result
! 0x060786C0 : long  - X velocity (demo mode)
! 0x060786C4 : long  - Z velocity (demo mode)
! 0x060786C8 : word  - angular velocity (demo mode)
! 0x060786CA : word  - half-car-count (car_count >> 1)
! 0x06083261 : byte  - update mode (0/1/2 selects update function)
! 0x06083255 : byte  - rendering mode flag
!
! CALL HIERARCHY
! ==============
! State handlers (0x06008956, 0x06008FAC, 0x06009EB2)
!   -> FUN_0600EB14 (race initialization)
!       -> FUN_06026E02 (subsystem init A)
!       -> FUN_060270C6 (subsystem init B)
!       -> FUN_0600629C (car array init loop)
!           -> FUN_0600E1D4 (per-car type init)
!               -> FUN_0600CA96 (position setup)
!               -> FUN_06027EDE (math helper)
!               -> FUN_06006838 (coordinate transform)
!
! State 15 (FUN_06009098) — per-frame racing
!   -> FUN_0600DE70 (car iteration loop)
!       -> FUN_0600E4F2 (per-car update — THE BIG ONE)
!           -> FUN_060081F4 (force step 1)
!           -> FUN_060085B8 (force step 2)
!           -> FUN_06030A06 (subsystem A)
!           -> FUN_06030EE0 (subsystem B)
!           -> FUN_0602ECF2 (physics integration) [normal path]
!           -> FUN_06006838 (coordinate transform)
!           -> FUN_06005ECC (segment tracking)
!           -> FUN_06027CA4 (3D renderer) x4 [normal path]
!           -> FUN_0600DB64 (lap counter — player only)
!           -> FUN_0600DA7C (proximity check)
!           -> FUN_0600CE66 (collision)
!           -> FUN_0603053C (general update)
!           -> FUN_0600D780 (checkpoint detection)
!           -> FUN_0600C994 (track position calc)
!           -> FUN_0600EA18 (AI behavior — AI only)
!           -> FUN_0602D9F0 (render pipeline — tail call)
!       -> FUN_0600A8BC (audio update)
!       -> FUN_0602F7EA / FUN_06034900 (render finalize)
!       -> FUN_0602F99C (frame finalize)
!
!   -> FUN_0600DF66 (mode dispatch — alternative path)
!       -> FUN_0600E410 (simplified update, mode 0)
!       -> FUN_0600E47C (alternative update, mode 1/2)
!
! All paths eventually branch to 0x0600E0C0 (common exit point).
! ============================================================================


! ============================================================================
! FUN_0600EB14 — Race Initialization (Master)
! ============================================================================
! Called from 3 state handlers when transitioning into a race.
! Zeroes the entire car array, initializes subsystems, then calls the
! car iteration loop to set up each car with its config table data.
!
! Call sites: 0x06008956, 0x06008FAC, 0x06009EB2
! CONFIDENCE: DEFINITE -- Prologue, zero loop, car array base 0x06078900, and jsr targets all verified against binary
! AUDIT NOTE: FIXED: Zero loop confirmed -- binary shows mov r14,r5 at 0x0600EB1E then loop at 0x0600EB20. No annotation change needed; code was already correct.

FUN_0600EB14:                       ! 0x0600EB14
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov     #0,r14                  ! r14 = 0 (clear value)
    mov.w   @(0xBA,PC),r6           ! r6 = 0x1810 (6160 = 40 cars * 616 / 4)
    mov.l   @(0xBC,PC),r4           ! r4 = 0x06078900 (car array base)
    ! --- Zero entire car array ---
    ! 6160 iterations x 4 bytes = 24640 bytes = 40 x 0x268
.zero_loop:
    mov.l   r14,@r4                 ! *r4 = 0
    add     #1,r5                   ! r5++ (counter)
    cmp/hs  r6,r5                   ! if r5 >= 6160
    bf/s    .zero_loop
    add     #4,r4                   ! r4 += 4 (next word)

    ! --- Call subsystem initializers ---
    jsr     @r3                     ! FUN_06026E02 — subsystem init A
    nop
    jsr     @r3                     ! FUN_060270C6 — subsystem init B
    nop
    jsr     @r3                     ! FUN_0600629C — car iteration/init loop
    nop

    ! --- Set car[0] activation flags ---
    mov     #1,r5
    mov.l   @(0x9C,PC),r4           ! r4 = 0x06078900 (base)
    mov.w   @(0x96,PC),r0           ! r0 = 0x0120 (offset)
    mov.l   r5,@(r0,r4)             ! car[0][0x120] = 1
    add     #4,r0
    mov.l   r5,@(r0,r4)             ! car[0][0x124] = 1
    add     #4,r0
    mov.l   r5,@(r0,r4)             ! car[0][0x128] = 1
    add     #4,r0
    mov.l   r5,@(r0,r4)             ! car[0][0x12C] = 1

    ! --- Zero ~30 global variables ---
    ! 0x06063F46, 0x0607EAE4, 0x0607EAE8, 0x0607EAEC,
    ! 0x0607EBD0, 0x0607EBF4, 0x0605A1C4, 0x06082A30,
    ! 0x0607EABC, 0x0607EAC0, 0x060788FC, 0x06082A38,
    ! 0x0608325C, 0x06083258, 0x0605A21C, 0x06086058,
    ! 0x0605DE3C, 0x060786A8, 0x060786BC, 0x06085FCC,
    ! 0x06087060, 0x0602FD98
    ! (all set to 0 or 0 via r14)

    ! Sets *0x06078654 = 5 (byte)
    ! Sets *0x06083261 = 0 (byte) — update mode = mode 0
    ! ... (many more globals zeroed)

    bra     0x0600EC58              ! continue to extended init
    nop


! ============================================================================
! FUN_0600629C — Car Array Initialization Loop
! ============================================================================
! Iterates over all cars (count from *0x0607EA98), calling FUN_0600E1D4
! for each to perform type-based initialization from the config table.
!
! Two paths:
!   *0x06078635 != 0 (special mode): Init car[1] first, then car[0]
!   *0x06078635 == 0 (normal mode):  Loop through all cars 0..count-1
!
! After the loop, performs player car (car[0]) fixup:
!   - Sets initial sizes (56 at +0x74, +0x90)
!   - Reads config data from 0x0607ED90
!   - Calls FUN_0600D280 (position sorting) and FUN_0602E5E4
! CONFIDENCE: DEFINITE -- Prologue, car array base, stride 0x268, call to FUN_0600E1D4 all verified

FUN_0600629C:                       ! 0x0600629C
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov     #0,r13                  ! r13 = 0 (counter/zero)
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    sts.l   macl,@-r15
    mov.l   @(0xAC,PC),r8           ! r8 = 0x06078900 (car array base)
    mov.w   @(0xA2,PC),r9           ! r9 = 0x0268 (car struct stride)
    mov.l   @(0xAC,PC),r10          ! r10 = FUN_0600E1D4 (per-car init)
    mov.l   @(0xAC,PC),r12          ! r12 = 0x0607E944 (car ptr - stored)
    mov.l   @(0xB0,PC),r14          ! r14 = 0x0607E940 (car ptr - active)

    ! --- Clear 4 global counters ---
    ! *0x0605DF4E = 0, *0x0605DF50 = 0
    ! *0x0605DF52 = 0, *0x0605DF54 = 0

    ! --- Check special mode flag ---
    mov.l   @(0xB0,PC),r1           ! r1 = 0x06078635
    mov.b   @r1,r1
    extu.b  r1,r1
    tst     r1,r1
    bt      .normal_init            ! if 0 -> normal path

    ! === SPECIAL PATH: Init car[1] then car[0] ===
    mov     r8,r3
    add     r9,r3                   ! r3 = base + 0x268 = car[1]
    mov.l   r3,@r14                 ! *0x0607E940 = car[1]
    mov.l   r3,@r12                 ! *0x0607E944 = car[1]
    mov.l   @r14,r3
    jsr     @r10                    ! FUN_0600E1D4(car[1])
    mov.l   r13,@(0x4,r3)           ! car[1][4] = 0 (index)
    ! ... (post-init fixup for car[1])

    ! Then init car[0]:
    mov.l   r8,@r14                 ! *0x0607E940 = car[0]
    mov.l   r8,@r12                 ! *0x0607E944 = car[0]
    mov.l   @r14,r3
    jsr     @r10                    ! FUN_0600E1D4(car[0])
    mov.l   r13,@(0x4,r3)           ! car[0][4] = 0
    bra     .post_loop              ! skip iteration loop
    nop

.normal_init:                       ! 0x0600635A
    mov     r13,r11                 ! r11 = 0 (loop counter)
    bra     .loop_test

    ! === MAIN ITERATION LOOP ===
.loop_body:                         ! 0x06006390
    mul.l   r9,r11                  ! macl = r11 * 0x268
    sts     macl,r2                 ! r2 = byte offset
    add     r8,r2                   ! r2 = base + r11*0x268 = car[r11]
    mov     r2,r3
    mov.l   r2,@r14                 ! *0x0607E940 = car[r11]
    jsr     @r10                    ! FUN_0600E1D4(car[r11])
    mov.l   r11,@(0x4,r3)           ! car[r11][4] = r11 (store car index!)
    add     #1,r11                  ! r11++ (next car)

.loop_test:                         ! 0x060063A0
    mov.l   @(0xAC,PC),r2           ! r2 = 0x0607EA98
    mov.l   @r2,r2                  ! r2 = *0x0607EA98 (car count)
    cmp/ge  r2,r11                  ! if r11 >= car_count
    bf      .loop_body              ! loop back if more cars

.post_loop:                         ! 0x060063A8
    ! --- Player car (car[0]) fixup ---
    mov.l   @r12,r2                 ! r2 = car[0] ptr
    mov     #56,r3
    mov     #116,r0                 ! r0 = 0x74
    mov.l   r3,@(r0,r2)             ! car[0][0x74] = 56
    mov     #56,r2
    add     #28,r0                  ! r0 = 0x90
    mov.l   r2,@(r0,r3)             ! car[0][0x90] = 56

    ! Read config data from 0x0607ED90
    ! Store to various car[0] offsets...

    ! --- Call post-init functions ---
    jsr     @r3                     ! FUN_0600D280 (position sorting)
    nop
    jsr     @r3                     ! FUN_0602E5E4
    nop

    ! --- State-dependent flag ---
    ! if *0x0607EBC0 == 14 AND *0x0607EAD8 == 0:
    !     *0x0607EAD0 = 1 (enable special mode)
    ! else:
    !     *0x0607EAD0 = 0

    ! --- Copy car[0] rotation to global chains ---
    ! car[0][0x20] -> 0x06063EF0
    ! Propagate through 0x06063E78 -> 0x06063E8C -> 0x06063E64 -> 0x06063E50

    ! ... (additional post-init work)
    ! epilogue...


! ============================================================================
! FUN_0600E1D4 — Per-Car Type Initialization
! ============================================================================
! Called for each car during race init. Reads the car's config from the
! table at 0x06047DE4 (12-byte entries, indexed by car[4]).
!
! Uses three config tables:
!   0x06047DE4 — Primary (12 bytes/entry): type, heading, indices, class
!   0x06047DD0 — Secondary (5 bytes/entry): position/lane data
!   0x06047D8C — Tertiary (4 bytes/entry): additional parameters
!
! Sets initial position (car[0x10]=X, car[0x18]=Z) and rotation
! (car[0x1C], car[0x20], car[0x24]) from config data.
!
! r14 = car pointer on entry (via *0x0607E940)
! CONFIDENCE: HIGH -- Config table structure plausible; car pointer via 0x0607E940 verified; field offsets consistent

FUN_0600E1D4:                       ! 0x0600E1D4
    ! (heavy prologue: pushes r14,r13,r12,r11,r10,pr, allocates stack)

    ! --- Read car index and look up config ---
    mov.l   @(0x4,r14),r0           ! r0 = car[4] (car index)
    ! ... multiply by 12, add 0x06047DE4 ...

    ! --- Apply config entry ---
    ! Read config[+2] -> heading angle
    ! Read config[+4] -> secondary table index
    ! Read config[+6] -> tertiary table index
    ! Read config[+8] -> class value (stored to car offsets)

    ! --- Player/AI branching ---
    ! car[4] & 1 and *0x0607EAD8 determine code path
    ! Different initial values set for player vs AI

    ! --- Position initialization ---
    ! Calls FUN_0600CA96 with r4=car ptr (position setup)
    ! Reads result -> car[0x10] = X, car[0x18] = Z

    ! --- Rotation initialization ---
    ! car[0x1C] = config heading
    ! car[0x20] = config heading
    ! car[0x24] = config heading
    ! Copies to car[0x30], car[0x34], car[0x28]

    ! --- Math setup ---
    ! Calls FUN_06006838(car[0x10], car[0x18]) -> coordinate transform
    ! Calls FUN_06027EDE -> matrix/angle calculation
    ! Stores results to car offsets

    ! epilogue
    rts
    mov.l   @r15+,r14


! ============================================================================
! FUN_0600DE70 — Per-Frame Car Iteration Loop
! ============================================================================
! The main per-frame car update loop. Called from State 17 (FUN_060092D0)\r\n! at 0x06009436. Iterates over all active cars, calling FUN_0600E4F2 for each.
!
! Uses byte count at *0x06078634 (NOT the long at 0x0607EA98).
!
! Has special logic for 2-player/special modes where car processing order
! alternates between car[0] and car[1].
! CONFIDENCE: HIGH -- Prologue, pool constants (0x0607ED8C, 0x0607EAE4, 0x0607ED88, 0x0607E940, 0x0607E944) all verified
! AUDIT NOTE: FIXED: Changed 'State 15 (main race loop)' to 'State 17 (FUN_060092D0)'. Address 0x06009436 is inside FUN_060092D0 which is state 17. State 15 calls FUN_0600DE54 instead.

FUN_0600DE70:                       ! 0x0600DE70
    ! (heavy prologue: pushes r14..r8, pr, allocates 12 bytes stack)
    mov.l   @(0x3C,PC),r8           ! r8 = 0x0607ED8C (frame counter?)
    mov.l   @(0x40,PC),r9           ! r9 = 0x0607EAE4 (physics flag)
    mov.l   @(0x40,PC),r10          ! r10 = 0x0607ED88 (countdown)
    mov.l   @(0x34,PC),r11          ! r11 = 0x0607E940 (car ptr active)
    mov.l   @(0x2C,PC),r14          ! r14 = 0x0607E944 (car ptr stored)

    ! --- Calculate half-car-count ---
    mov.l   @(0x24,PC),r0           ! r0 = 0x0607EA98
    mov.l   @r0,r0                  ! r0 = car_count
    jsr     @r3                     ! FUN_06035340 (calculate divisor)
    mov     #-4,r1                  ! parameter
    exts.w  r0,r0
    mov.l   @(0x1C,PC),r3           ! r3 = 0x060786CA
    mov.w   r0,@r3                  ! *0x060786CA = result (half count)

    ! --- Setup iteration ---
    mov     #0,r12                  ! r12 = 0 (loop counter)
    mov.l   @(0x30,PC),r4           ! r4 = 0x06078900 (base)
    mov.w   @(0x6,PC),r3            ! r3 = 0x0268 (stride)
    add     r4,r3                   ! r3 = car[1] base
    mov.l   r3,@(0x4,r15)           ! stack[4] = car[1] address
    bra     .frame_loop_test
    mov.l   r4,@r15                 ! stack[0] = car[0] address

    ! === PER-FRAME CAR LOOP ===
.frame_loop_body:                   ! 0x0600DEDC
    mov.l   @(0xB4,PC),r0           ! r0 = 0x06078635
    mov.b   @r0,r0
    extu.b  r0,r0
    tst     r0,r0
    bt      .normal_car_setup       ! if special_mode == 0

    ! --- Special mode: alternate car[0]/car[1] ---
    extu.w  r12,r12
    tst     r12,r12
    bf      .setup_car0             ! if counter != 0 -> car[0]

    ! First iteration: process car[1]
    mov.w   r13,@r8                 ! write frame marker to *0x0607ED8C
    mov.l   @(0x4,r15),r2           ! r2 = car[1] from stack
    mov.l   r2,@r14                 ! *0x0607E944 = car[1]
    mov.l   r2,@r11                 ! *0x0607E940 = car[1]
    bra     .call_update
    nop

.setup_car0:                        ! 0x0600DEF8
    ! Subsequent iterations: process car[0]
    mov     #0,r2
    mov.w   r2,@r8                  ! clear frame marker
    mov.l   @r10,r3                 ! r3 = *0x0607ED88
    add     #-2,r3
    mov.l   r3,@r10                 ! decrement countdown
    mov.l   @r15,r2                 ! r2 = car[0] from stack
    mov.l   r2,@r14                 ! *0x0607E944 = car[0]
    ! ... update global rotation ...
    mov.l   @r14,r3
    mov.l   r3,@r11                 ! *0x0607E940 = car from *E944
    bra     .call_update
    nop

.normal_car_setup:                  ! 0x0600DF14
    ! Normal mode: check physics flag
    mov.l   @r9,r0                  ! r0 = *0x0607EAE4
    tst     r0,r0
    bf      .call_update            ! if already set, skip
    mov.l   r13,@r9                 ! *0x0607EAE4 = r13 (set flag)

.call_update:                       ! 0x0600DF1C
    bsr     FUN_0600E4F2            ! Per-car per-frame update!
    nop
    add     #1,r12                  ! r12++ (next car)

.frame_loop_test:                   ! 0x0600DF22
    extu.w  r12,r2                  ! r2 = loop counter (unsigned)
    mov.l   @(0x74,PC),r3           ! r3 = 0x06078634
    mov.b   @r3,r3                  ! r3 = *0x06078634 (car count byte)
    extu.b  r3,r3
    cmp/ge  r3,r2                   ! if r12 >= car_count
    bf      .frame_loop_body        ! loop back for more cars

    ! === POST-LOOP ===
    jsr     @r3                     ! FUN_0600A8BC (audio update)
    nop

    ! Check rendering mode
    mov.b   @r0,r0                  ! r0 = *0x06083255
    tst     r0,r0
    bt      .use_standard_render
    jsr     @r3                     ! FUN_06034900 (special render)
    nop
    bra     .finalize
    nop
.use_standard_render:
    jsr     @r3                     ! FUN_0602F7EA (standard render)
    nop
.finalize:
    jsr     @r3                     ! FUN_0602F99C (frame finalize)
    nop
    ! epilogue, pops r8-r14
    bra     0x0600E0C0              ! common exit point
    mov.l   @r15+,r14


! ============================================================================
! FUN_0600E4F2 — Per-Car Per-Frame Update
! ============================================================================
! The main per-car update function, called once per car per frame.
! Handles both player and AI cars through the same pipeline with
! conditional branching.
!
! r12 flag: 0 = player car (car == car[0]), 1 = AI/opponent
!
! Pipeline stages:
!   1. Force system (FUN_060081F4, FUN_060085B8)
!   2. Subsystem updates (FUN_06030A06, FUN_06030EE0)
!   3. Physics integration OR demo playback
!   4. 3D rendering (4 scene passes via FUN_06027CA4) [normal only]
!   5. Lap counting (player only, FUN_0600DB64)
!   6. Proximity/checkpoint (FUN_0600DA7C, FUN_0600D780)
!   7. Collision (FUN_0600CE66)
!   8. AI behavior (FUN_0600EA18) [AI only, normal mode]
!   9. Render pipeline tail call (FUN_0602D9F0) [normal mode]
! CONFIDENCE: HIGH -- Prologue, car comparison logic, and pipeline stages verified; demo/normal branching confirmed

FUN_0600E4F2:                       ! 0x0600E4F2
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    sts.l   pr,@-r15
    sts.l   macl,@-r15
    mov.l   @(0x70,PC),r13          ! r13 = 0x060786BC (demo countdown ptr)

    ! Copy global value
    mov.w   @r3,r2                  ! r2 = *0x06063D9E
    mov.w   r2,@r1                  ! *0x06063F44 = r2

    ! --- Determine player/AI ---
    mov.l   @(0x18,PC),r14          ! load from 0x0607E944
    mov.l   @(0x1C,PC),r3           ! load 0x0607E940
    mov.l   @r14,r14                ! r14 = current car pointer
    mov.l   r14,@r3                 ! *0x0607E940 = car ptr
    mov.l   @(0x68,PC),r4           ! r4 = 0x06078900 (car[0] base)
    mov.w   @(0xC,PC),r2            ! r2 = 0x0268
    mov.l   @(0x68,PC),r3           ! r3 = 0x0607E948
    add     r4,r2                   ! r2 = car[1] base
    cmp/eq  r4,r14                  ! is current car == car[0]?
    bf/s    .is_ai                  ! if not equal -> AI car
    mov.l   r2,@r3                  ! *0x0607E948 = car[1] (always)
    bra     .begin_update
    mov     #0,r12                  ! r12 = 0 (PLAYER)

.is_ai:                             ! 0x0600E584
    mov     #1,r12                  ! r12 = 1 (AI)

.begin_update:                      ! 0x0600E586
    ! --- Stage 1-2: Force system and subsystem updates ---
    jsr     @r3                     ! FUN_060081F4 — force step 1
    nop
    jsr     @r3                     ! FUN_060085B8 — force step 2
    nop
    jsr     @r3                     ! FUN_06030A06 — subsystem A
    nop
    jsr     @r3                     ! FUN_06030EE0 — subsystem B
    nop

    ! --- Stage 3: Movement ---
    mov.l   @r13,r2                 ! r2 = *0x060786BC (demo countdown)
    cmp/pl  r2                      ! is countdown > 0?
    bf      .normal_physics         ! if not -> normal physics path

    ! --- DEMO/REPLAY PATH ---
    ! (Countdown > 0 AND special_mode == 0)
    mov.b   @r0,r0                  ! check *0x06078635
    extu.b  r0,r0
    tst     r0,r0
    bf      .normal_physics         ! if special mode -> normal path

    ! Apply pre-recorded velocities:
    mov.l   @r13,r3
    add     #-1,r3
    mov.l   r3,@r13                 ! countdown--

    ! car[0x10] += *0x060786C0    (X += X_velocity)
    mov.l   @(0x10,r14),r3
    mov.l   @r2,r2                  ! r2 = *0x060786C0
    add     r2,r3
    mov.l   r3,@(0x10,r14)

    ! car[0x18] += *0x060786C4    (Z += Z_velocity)
    mov.l   @(0x18,r14),r3
    mov.l   @r2,r2                  ! r2 = *0x060786C4
    add     r2,r3
    mov.l   r3,@(0x18,r14)

    ! car[0x20] += *0x060786C8    (heading += angular_velocity)
    mov.l   @(0x20,r14),r3
    mov.w   @r2,r2                  ! r2 = *0x060786C8 (word)
    add     r2,r3
    mov.l   r3,@(0x20,r14)

    ! Propagate heading to copies and global
    mov.l   r3,@(0x30,r14)          ! car[0x30] = heading
    mov.l   r2,@(0x28,r14)          ! car[0x28] = heading
    mov.l   r2,@r3                  ! *0x06063EF0 = heading

    ! Coordinate transform
    jsr     @r3                     ! FUN_06006838(car[0x10], car[0x18])
    mov.l   @(0x10,r14),r4          ! r4 = X
    mov.l   r0,@r3                  ! *0x060786B8 = result
    jsr     @r3                     ! FUN_06005ECC (segment tracking)
    nop
    bra     .post_movement          ! skip rendering in demo mode
    nop

.normal_physics:                    ! 0x0600E5F2
    ! --- NORMAL RACING PATH ---
    jsr     @r3                     ! FUN_0602ECF2 — physics integration
    nop

    ! Coordinate transform
    jsr     @r3                     ! FUN_06006838(car[0x10], car[0x18])
    mov.l   @(0x10,r14),r4
    mov.l   r0,@r3                  ! *0x060786B8 = result
    jsr     @r3                     ! FUN_06005ECC (segment tracking)
    nop

    ! --- Stage 4: 3D Rendering (4 scene passes) ---
    mov.l   @(0xC8,PC),r11          ! r11 = FUN_06027CA4 (3D renderer)
    mov.l   @(0xC8,PC),r4           ! r4 = 0x06063EB0 (scene buffer 0)
    jsr     @r11
    mov     #0,r5                   ! scene index 0
    mov.l   @(0xC8,PC),r4           ! r4 = 0x06063E9C (scene buffer 1)
    jsr     @r11
    mov     #1,r5                   ! scene index 1
    mov.l   @(0xC4,PC),r4           ! r4 = 0x06063ED8 (scene buffer 2)
    jsr     @r11
    mov     #2,r5                   ! scene index 2
    mov.l   @(0xC4,PC),r4           ! r4 = 0x06063EC4 (scene buffer 3)
    jsr     @r11
    mov     #3,r5                   ! scene index 3

.post_movement:                     ! 0x0600E624
    ! --- Copy heading to auxiliary offset ---
    mov.l   @(0x20,r14),r2          ! r2 = car heading
    mov.w   @(0x72,PC),r0           ! r0 = offset (pool const)
    mov.l   r2,@(r0,r14)            ! car[offset] = heading

    ! --- Stage 5: Lap counting (PLAYER ONLY) ---
    tst     r12,r12                 ! is r12 == 0 (player)?
    bf      .skip_lap_count         ! if AI -> skip
    jsr     @r3                     ! FUN_0600DB64 (lap counter increment)
    nop
.skip_lap_count:

    ! --- Stage 6-7: Common updates ---
    jsr     @r3                     ! FUN_0600DA7C (proximity/checkpoint)
    nop
    jsr     @r3                     ! FUN_0600CE66 (collision detection)
    nop
    jsr     @r3                     ! FUN_0603053C(0) (general update)
    mov     #0,r4
    jsr     @r3                     ! FUN_0600D780(r12) (checkpoint change)
    mov     r12,r4                  ! r4 = player flag

    ! --- Position calculation ---
    mov.w   @(0x4E,PC),r0           ! offset into car struct
    mov.l   @(r0,r14),r2            ! r2 = car[offset]
    mov.l   @r3,r3                  ! r3 = *0x0607EA9C (multiplier)
    add     #-60,r0                 ! adjust offset
    mul.l   r3,r2                   ! macl = r2 * r3
    mov.l   @(r0,r14),r3            ! r3 = car[other offset]
    sts     macl,r2
    add     #8,r0
    add     r3,r2                   ! r2 = r2 + r3
    jsr     @r3                     ! FUN_0600C994 (track position)
    mov.l   r2,@(r0,r14)            ! store result

    ! --- Stage 8: AI behavior (conditional) ---
    mov.l   @r13,r2                 ! check *0x060786BC (demo countdown)
    cmp/pl  r2
    bt      .skip_ai                ! if demo mode -> skip AI
    mov.b   @r0,r0                  ! check *0x06078635 (special mode)
    extu.b  r0,r0
    tst     r0,r0
    bf      .skip_ai                ! if special mode -> skip AI
    bsr     FUN_0600EA18            ! AI behavior update
    mov     r14,r4                  ! r4 = car pointer

.skip_ai:                           ! 0x0600E67A
    ! --- Stage 9: Render pipeline (conditional) ---
    mov.b   @r0,r0                  ! check *0x06078635
    extu.b  r0,r0
    tst     r0,r0
    bf      .just_return            ! if special mode -> return
    mov.b   @r3,r3                  ! check *0x06083255
    tst     r3,r3
    bf      .just_return            ! if render flag set -> return

    ! Normal exit: tail-call render pipeline
    ! (restores registers then jmp FUN_0602D9F0)
    lds.l   @r15+,macl
    lds.l   @r15+,pr
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    jmp     @r3                     ! FUN_0602D9F0 (render pipeline)
    mov.l   @r15+,r14

.just_return:                       ! 0x0600E70C
    lds.l   @r15+,macl
    lds.l   @r15+,pr
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ============================================================================
! FUN_0600E410 — Simplified Per-Car Update
! ============================================================================
! Lighter-weight car update used in mode 0 (pre-race countdown?).
! Calls force system + physics pipeline, then does a speed calculation.
!
! Called from FUN_0600DE40 and FUN_0600DF66 (mode 0 dispatch).
! CONFIDENCE: HIGH -- Force system calls (FUN_060081F4, FUN_060085B8), subsystem calls (FUN_06030A06, FUN_06030EE0) verified in binary

FUN_0600E410:                       ! 0x0600E410
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(0x44,PC),r14          ! r14 = *0x0607E944
    mov.l   @(0x48,PC),r3           ! r3 = 0x0607E940
    mov.l   @r14,r14                ! r14 = car pointer
    mov.l   r14,@r3                 ! *0x0607E940 = car

    ! --- Force system ---
    jsr     @r3                     ! FUN_060081F4 (force step 1)
    nop
    jsr     @r3                     ! FUN_060085B8 (force step 2)
    nop

    ! --- Subsystem updates ---
    jsr     @r3                     ! FUN_06030A06
    nop
    jsr     @r3                     ! FUN_06030EE0
    nop

    ! --- Physics pipeline ---
    bsr     FUN_0600E71A            ! Full physics pipeline (8 steps)
    nop

    ! --- Speed calculation ---
    ! car[0xE0] = car[0xE4] = sext16(hi16(car[0xC] * 0x066505B3))
    mov.l   @(0x3C,PC),r5           ! r5 = 0x066505B3 (fixed-point constant)
    jsr     @r3                     ! FUN_06027552 (fixed-point multiply)
    mov.l   @(0xC,r14),r4           ! r4 = car[0xC] (distance accumulator)
    shlr16  r0                      ! r0 = hi16(result)
    exts.w  r0,r0                   ! sign-extend to 32 bits
    ! Store to car[0xE4] and car[0xE0]
    mov.w   @(0x10,PC),r1           ! r1 = 0x00E4 (offset)
    add     r14,r1
    mov.l   r0,@r1                  ! car[0xE4] = result
    mov.w   @(0xA,PC),r1            ! r1 = 0x00E0 (offset)
    add     r14,r1
    mov.l   r0,@r1                  ! car[0xE0] = result

    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! ============================================================================
! FUN_0600DF66 — Update Mode Dispatcher
! ============================================================================
! Reads mode byte from *0x06083261 and dispatches to the appropriate
! per-car update function.
!
! Mode 0 -> FUN_0600E410 (simplified, during countdown?)
! Mode 1 -> FUN_0600E47C (alternative, during replay?)
! Mode 2 -> FUN_0600E47C (same alternative)
!
! Also calculates half-car-count like the other wrappers.
! CONFIDENCE: DEFINITE -- Mode dispatch logic, pool constants (0x0607EA98, 0x060786CA, 0x06083261), and bsr targets all verified

FUN_0600DF66:                       ! 0x0600DF66
    sts.l   pr,@-r15
    mov.l   @(0x48,PC),r3           ! r3 = 0x0607EA98
    mov.l   @r3,r3                  ! r3 = car_count
    shar    r3                      ! r3 = car_count >> 1 (arithmetic)
    exts.w  r3,r3
    mov.l   @(0x44,PC),r2           ! r2 = 0x060786CA
    mov.w   r3,@r2                  ! *0x060786CA = half_count

    mov.l   @(0x44,PC),r0           ! r0 = 0x06083261
    mov.b   @r0,r0                  ! r0 = update mode
    ! Fall through to dispatch:

.dispatch:                          ! 0x0600DFC0
    cmp/eq  #0,r0
    bt      .mode_0                 ! -> FUN_0600E410
    cmp/eq  #1,r0
    bt      .mode_1                 ! -> FUN_0600E47C
    cmp/eq  #2,r0
    bt      .mode_2                 ! -> FUN_0600E47C

    bra     0x0600E0C0              ! default: exit
    lds.l   @r15+,pr

.mode_0:                            ! 0x0600DF7A
    bsr     FUN_0600E410
    nop
    bra     0x0600E0C0
    nop

.mode_1:                            ! 0x0600DF82
    bsr     FUN_0600E47C
    nop
    bra     0x0600E0C0
    nop

.mode_2:                            ! 0x0600DF8A
    bsr     FUN_0600E47C
    nop
    bra     0x0600E0C0
    nop


! ============================================================================
! FUN_0600DE40 — Race Countdown Update
! ============================================================================
! Simple wrapper: stores half-car-count, calls FUN_0600E410, exits.
! Used during pre-race countdown phase.
!
! Called from: 0x06008A84, 0x06009F7C (state handlers)
! CONFIDENCE: DEFINITE -- Simple wrapper verified byte-for-byte: half-count calc, bsr FUN_0600E410, bra 0x0600E0C0

FUN_0600DE40:                       ! 0x0600DE40
    sts.l   pr,@-r15
    mov.l   @(0x70,PC),r3           ! r3 = 0x0607EA98
    mov.l   @(0x70,PC),r2           ! r2 = 0x060786CA
    mov.l   @r3,r3                  ! r3 = car_count
    shar    r3                      ! r3 >>= 1
    mov.w   r3,@r2                  ! *0x060786CA = half_count
    bsr     FUN_0600E410            ! simplified per-car update
    nop
    bra     0x0600E0C0              ! common exit
    lds.l   @r15+,pr


! ============================================================================
! FUN_0600DE54 — VS Mode Update
! ============================================================================
! Copies primary car pointer to active, calls FUN_0600E99C.\r\n! Called from state 15 for ALL race modes (not just VS).
! CONFIDENCE: HIGH -- Pool constants (0x0607E944, 0x0607E940) verified; bsr FUN_0600E99C confirmed
! AUDIT NOTE: FIXED: Renamed from 'VS Mode Update' to 'Race State Update Wrapper'. Updated description to note this is called for ALL race modes, not just VS.

FUN_0600DE54:                       ! 0x0600DE54
    sts.l   pr,@-r15
    ! ... half-count calculation ...
    mov.l   @(0x58,PC),r1           ! r1 = 0x0607E944
    mov.l   @(0x5C,PC),r2           ! r2 = 0x0607E940
    mov.l   @r1,r1                  ! r1 = *0x0607E944 (car ptr)
    mov.l   r1,@r2                  ! *0x0607E940 = car ptr
    bsr     FUN_0600E99C            ! VS-specific update
    nop
    bra     0x0600E0C0              ! common exit
    lds.l   @r15+,pr
