! ================================================
! AUDIT: DEFINITE -- Main loop and jump table verified byte-for-byte against binary
! Audited: 2026-02-10
! ================================================
! ============================================================================
! game_loop.s — Main Loop & 32-State Machine
! ============================================================================
!
! The entire game runs as a 32-state machine dispatched from an infinite loop
! at 0x06003000 (the entry point of APROG.BIN).
!
! Each frame:
!   1. Call FUN_0600A392 (per-frame update: input polling, timers, etc.)
!   2. Read state variable from 0x0605AD10
!   3. Index into jump table at 0x0600307C to get handler address
!   4. Call the handler
!   5. Loop back to step 1
!
! Key addresses:
!   0x0605AD10  = game state variable (0-31)
!   0x0607EBC0  = previous state (saved each frame)
!   0x0607EBC4  = state-related counter/flags
!   0x0607EBC8  = frame counter (incremented every loop iteration)
!   0x0600307C  = jump table base (32 entries, 4 bytes each)
!
! The state variable at 0x0605AD10 controls the entire game flow.
! Handlers can write a new state value there to trigger transitions.
! ============================================================================


! ============================================================================
! Entry point — 0x06003000
! ============================================================================
! First call: FUN_060030FC (one-time init: SMPC, BSS clear, subsystems)
! Then falls into the infinite main loop.
! CONFIDENCE: DEFINITE -- Entry point, stack init, jsr FUN_060030FC, ldc r0,sr all verified byte-for-byte

_start:                             ! 0x06003000
    mov.l   @(0x5C,PC),r1         ! r1 = 0x060030FC (FUN_060030FC — system init)
    mov     #0,r0                  ! r0 = 0 (initial SR value: all interrupts enabled)
    mov.l   @(0x60,PC),r15        ! r15 = 0x06003000 (stack pointer — top of program!)
    jsr     @r1                    ! Call FUN_060030FC: SMPC init, BSS clear, subsystem init
    ldc     r0,sr                  ! (delay slot) Set SR = 0 (enable all interrupts)

! ============================================================================
! Main loop — runs forever, one iteration per frame
! ============================================================================
! CONFIDENCE: DEFINITE — All addresses (0x0600A392, 0x0605AD10, 0x0607EBC0, 0x0607EBC4, 0x0607EBC8) verified in binary pool data
.main_loop:                         ! 0x0600300A
    mov.l   @(0x58,PC),r0         ! r0 = 0x0600A392 (FUN_0600A392 — per-frame update)
    jsr     @r0                    ! Call per-frame update (input polling, timers, VBlank sync)
    nop

! --- Read state and compute jump table index ---
    mova    @(0x68,PC),r0          ! r0 = 0x0600307C (jump table base address)
    mov.l   @(0x60,PC),r1         ! r1 -> 0x0605AD10 (game state variable pointer)
    mov.l   @(0x54,PC),r2         ! r2 -> 0x0607EBC0 (previous state storage)
    mov.l   @r1,r1                 ! r1 = current state value (0-31)
    mov.l   @(0x54,PC),r3         ! r3 -> 0x0607EBC4 (state counter/flags)
    mov.l   r1,@r2                 ! Save current state to previous-state slot

! --- Compute a bitmask from the state value ---
! This builds r4 = (1 << state) as a bitmask, stored at 0x0607EBC4.
! The code manually shifts in groups: <<16 if state>=16, <<8 if >=8, etc.
! Purpose: quick bitmask for testing which states have been visited.
    mov     r1,r6                  ! r6 = state value (working copy)
    mov     #1,r4                  ! r4 = 1 (will become 1<<state)
    mov     #16,r5
    cmp/gt  r6,r5                  ! state < 16?
    bt/s    .skip_shll16
    mov     #8,r5
    shll16  r4                     ! state >= 16: shift left 16
    add     #-16,r6               ! subtract 16 from working copy
.skip_shll16:
    cmp/gt  r6,r5                  ! remaining < 8?
    bt/s    .skip_shll8
    mov     #6,r5
    shll8   r4                     ! remaining >= 8: shift left 8
    add     #-8,r6
.skip_shll8:
    cmp/gt  r6,r5                  ! remaining < 6?
    bt      .skip_shll_loop
    shll2   r4                     ! remaining >= 6: shift left 4
    shll2   r4
    shll2   r4
    add     #-6,r6
.skip_shll_loop:
    tst     r6,r6                  ! any remaining shifts?
    bt      .do_dispatch
.shift_loop:
    dt      r6                     ! decrement remaining
    bf/s    .shift_loop
    shll    r4                     ! shift left 1 each iteration

! --- Dispatch to state handler ---
.do_dispatch:                       ! 0x0600304C
    mov.l   @(0x28,PC),r2         ! r2 -> 0x0607EBC8 (frame counter)
    mov.l   r4,@r3                 ! Store bitmask to 0x0607EBC4
    mov.l   @r2,r5                 ! r5 = current frame count
    shll2   r1                     ! r1 = state * 4 (table index)
    mov.l   @(r0,r1),r0           ! r0 = jump_table[state] (handler address)
    add     #1,r5                  ! Increment frame counter
    jsr     @r0                    ! CALL THE STATE HANDLER
    mov.l   r5,@r2                 ! (delay slot) Store incremented frame count

    bra     .main_loop             ! Loop forever
    nop


! ============================================================================
! Jump Table (0x0600307C) — 32 state handler addresses
! ============================================================================
! CONFIDENCE: DEFINITE — All 32 entries decoded from binary and cross-checked against function labels
! Each entry is a 32-bit pointer to a handler function.
! States 14, 15, 17, 19 are the in-race gameplay handlers (largest).
!
!  State | Address    | Purpose
!  ------+------------+--------------------------------------------------
!    0   | 0x060088CC | Startup / initialization
!    1   | 0x0600890A | Transition
!    2   | 0x06008938 | Attract mode setup
!    3   | 0x06008A18 | Title screen / demo mode
!    4   | 0x06008CCC | Mode select (arcade/time trial)
!    5   | 0x06008D74 | Course select
!    6   | 0x06008B04 | Transition (small, 24 insns)
!    7   | 0x06008B34 | Transition
!    8   | 0x06008B78 | Transition
!    9   | 0x06008B9C | Transition
!   10   | 0x06008BD8 | Transition
!   11   | 0x06008BFC | Transition
!   12   | 0x06008E00 | Pre-race setup (loading, grid positions)
!   13   | 0x06008E48 | Race countdown ("3... 2... 1... GO!")
!  *14   | 0x06008EBC | IN-RACE GAMEPLAY (188 insns)
!  *15   | 0x06009098 | IN-RACE GAMEPLAY (202 insns) — see race_update.s
!   16   | 0x06009290 | Lap transition
!  *17   | 0x060092D0 | IN-RACE GAMEPLAY (228 insns)
!   18   | 0x060096DC | Time extension display
!  *19   | 0x06009788 | COMPLEX RACE STATE (298 insns, largest handler)
!   20   | 0x06009A60 | Race end / results
!   21   | 0x06009C48 | Results display
!   22   | 0x06009E60 | Game over
!   23   | 0x06009F10 | Name entry
!   24   | 0x06009CFC | Post-race
!   25   | 0x06009D4E | Score tally
!   26   | 0x06009DD0 | Transition
!   27   | 0x06009E02 | Timer/counter (VERIFIED — simple decrement)
!   28   | 0x06009508 | Special state
!   29   | 0x0600955E | Special state
!   30   | 0x06008C14 | Service menu / diagnostics
!   31   | 0x06008C76 | Diagnostics
!
! State transitions observed:
!   0 (init) → 2 (attract) → 3 (title) → 4 (mode select) → 5 (course select)
!   → 6-11 (transitions/loading) → 12 (pre-race) → 13 (countdown) → 14 (race)
!   14/15/17/19 cycle during race → 20 (results) → 21-25 (post-race) → 2 (loop)
!
! CONFIDENCE: HIGH -- State 15 call chain verified; FUN_0600DE54 confirmed as called at 0x06009174
! State 15 in-race call chain (the core gameplay path):
!   FUN_06009098
!     → FUN_060302C6  (sound system update)
!     → FUN_0602EFF0  (rendering pass 1)
!     → FUN_0602F0E8  (rendering pass 2)
!     → FUN_0600DE54  (RACE STATE UPDATE — key function)
!       → FUN_0600E99C  (pre-update)
!       → FUN_0600E0C0  (main race update)
!         → FUN_06027CA4  (3D scene processing)
!         → FUN_06005ECC  (course data processing)
!         → FUN_06063EB0  (frame/rendering finalization)
! AUDIT NOTE: 0x06063EB0 is a data address (scene buffer pointer), not a function. It is passed as r4 argument to FUN_06027CA4.
! ============================================================================
