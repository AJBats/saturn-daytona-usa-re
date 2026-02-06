! ==========================================================================
! Race State Machine — In-Race State Handlers (States 14-29)
! ==========================================================================
!
! The game's 32-state machine dispatches through a jump table from main
! (0x06003000). The race gameplay spans states 14-29. This file documents
! all in-race states: active racing, lap transitions, time extensions,
! race completion, abort processing, and post-race menus.
!
! STATE TRANSITION GRAPH:
!
!   State 14 (first-frame setup) ──────→ State 15 (main race loop)
!                ↑                              │
!                │                        ┌─────┴──────┐
!                │                  countdown=0     start btn
!                │                        ↓             ↓
!                │                  State 16 ───→ State 18 (time ext setup)
!                │                  (cleanup)           │
!                │                        ↓             ↓
!                │                  State 17 ───→ State 19 (time ext active)
!                │                  (results)      │    │    │
!                │                 │    │    │     │    │    └→ saved state
!                │              abort mode=1 timer=0   A+B+C held
!                │                 │    │    │     │    ↓
!                │                 │    │    │     │  State 24 / 14
!                │                 ↓    ↓    ↓     │
!                │           St 20  St 28  St 24 ←─┘
!                │           (race   (abort  (post-race
!                │            end)    proc)   init)
!                │              │      │       │
!                │              ↓      ↓       ↓
!                │           St 21   St 29   St 25
!                │                   (menu)  (display loop)
!                │                     │
!                │               ┌─────┼──────────┐
!                │            start  mode=0    abort
!                │               ↓     ↓         ↓
!                │            St 18  St 17     St 20
!                └─────────────────(A+B+C in state 19)
!
! CALL GRAPH (per-state key functions):
!   State 14: FUN_0600A0C0, FUN_06018A3C, FUN_0601F784, FUN_0600EB14 (race update)
!             FUN_06033AAC (HUD), FUN_060321C0 (display)
!   State 15: FUN_060302C6 (per-car sound), FUN_0602EFF0/0602F0E8 (rendering)
!             FUN_0600DE54 (PER-CAR RACE UPDATE — physics, collision per frame)
!             FUN_0600C302 (car finalize), FUN_060078DC (frame sync)
!   State 16: FUN_060121A8 / FUN_06012198 (car cleanup)
!   State 17: FUN_0600A33C (general update), FUN_060192CA (reset sound)
!             FUN_06018E70 (sound transition), FUN_0600DE70, FUN_0600A914
!             FUN_0600BB94, FUN_060053AC (display), FUN_0601D9B0 (sound update)
!   State 18: FUN_06009FFC (time extension UI), FUN_060283E0 (VDP text)
!             FUN_060284AE (VDP number text), FUN_0601D5F4 (sound API)
!   State 19: FUN_0602834A (number display), FUN_060283E0 (text display)
!             FUN_0600A1B8 (secret input handler), FUN_06018DDC (difficulty setup)
!   State 20: FUN_06014A04, FUN_060210F6, FUN_06009FFC, FUN_06018DDC, FUN_0600A1B8
  State 24: FUN_06014A74, FUN_06019058, FUN_0600A1B8, FUN_060032D4, FUN_060210F6
  State 25: FUN_06014D2C, FUN_0600BB94, FUN_060053AC, FUN_0600BFFC, FUN_060078DC
  State 28: FUN_0600DFD0, FUN_0600BB94, FUN_060053AC, FUN_0600C218, FUN_060078DC
  State 29: FUN_0600E060, FUN_0600BB94, FUN_060053AC, FUN_0600C218, FUN_060078DC
!
! KEY DATA STRUCTURES:
!   Race state variables (0x0605AD00 region):
!     0x0605AD08  Back-to-title flag (1 = exit to menu)
!     0x0605AD10  Game state variable (the 32-state machine index)
!     0x0605A016  Phase flag (set to 4 on post-lap cleanup)
!     0x0605A1C4  Mode flag (1 = triggers state 28 transition)
!     0x0605AB18  Menu overlay active flag (non-zero = show pause menu)
!     0x0605B6D8  Display flags (bit 2=update, bit 30=race active, bit 31=special)
!
!   Race progress variables (0x0607EA00 region):
!     0x0607EAAC  Countdown timer (decremented each frame in state 15/17)
!     0x0607EACC  Resume state (saved before time extension detour)
!     0x0607EAD0  Race end flag (non-zero = race finished)
!     0x0607EAD8  Car object pointer (player car struct)
!     0x0607EBD0  Frame counter (incremented while in post-race states)
!     0x0607EBF4  Flags word (bit 0 = abort, triggers state 20)
!     0x0607ED88  Timer byte (per-car frame timing in state 15 inner loop)
!     0x0607ED8C  Init/phase flag (controls per-car first-iteration setup)
!
!   Race config variables (0x06078600 region):
!     0x06078634  Car count (how many cars to iterate per frame)
!     0x06078635  Phase flag (cleared to 0 on race start)
!     0x06078636  Display mode byte (controls car display in state 17)
!     0x06078638  Race result / finish position
!     0x06078648  Button event ID (0-3, mapped from controller input)
!     0x06078649  Speed byte (time extension speed selection, range 1-99)
!     0x0607864A  Mode byte (controls time extension behavior)
!     0x06078650  Frame counter word (time extension elapsed frames)
!     0x06078652  Saved difficulty (backed up before time extension)
!     0x06078654  Current difficulty
!
!   Car object struct (see also collision.s):
!     +0x82 (word)  Finish position / race result field
!
!   Input (0x06063D98):
!     0x06063D98  Held buttons (word, bits set = currently held)
!     0x06063D9A  New buttons (word, bits set = just pressed this frame)
!     Button masks: 0x0800 = Start, 0x8000 = Up, 0x4000 = Down, 0x0070 = A+B+C
!
!   Sound commands:
!     0xAE0004FF  Transition/stop sound (played on time extension enter/exit)
!     0xAE1134FF  Countdown sound (played when timer == 200 in state 17)
!
! ==========================================================================


! ==========================================================================
! FUN_06008EBC — State 14: First-Frame Race Setup
! ==========================================================================
! Single-frame initialization that runs once at race start.
! Sets up flags, maps button events, runs the main race pipeline once,
! then immediately transitions to state 15 (main loop).
!
! Called from: main state dispatch (state index 14)
! Transitions to: State 15 (always, same frame)

FUN_06008EBC:       ! 0x06008EBC
    sts.l   pr,@-r15
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15

    ! Clear phase flag, set race active
    mov     #0,r3
    mov.l   @(PC),r2                ! r2 = 0x06078635 (phase flag)
    mov.b   r3,@r2                  ! [phase_flag] = 0

    mov     #1,r3
    mov.l   @(PC),r2                ! r2 = 0x06078634 (car count / race active)
    mov.b   r3,@r2                  ! [car_count] = 1

    mov     #8,r3
    mov.l   @(PC),r2                ! r2 = 0x0607ED88 (timer byte)
    mov.l   r3,@r2                  ! [timer] = 8

    ! Button event mapping:
    !   Reads mask from [0x06063D98] (held buttons)
    !   ANDs with flag words at 0x06078656, 0x06078658, 0x0607865A, 0x0607865C
    !   First non-zero match determines event ID (0-3)
    !   Result stored to [0x06078648] (button event ID)
    !   This maps physical buttons to logical game events for the race

    ! Main race pipeline (called once for first-frame setup):
    !   FUN_0600A0C0  — pre-update (camera/object setup)
    !   FUN_06018A3C  — timing/sync initialization
    !   FUN_0601F784  — AI/course path setup
    !   FUN_0600EB14  — RACE UPDATE (full physics, collision, movement pass)
    !   FUN_06010A5C  — post-update processing
    !   FUN_06033AAC  — HUD rendering (lap counter, speed, position)
    !   FUN_060321C0  — display commit (push to VDP)

    ! Transition to state 15
    mov     #15,r3
    mov.l   @(PC),r2                ! r2 = 0x0605AD10 (state variable)
    mov.l   r3,@r2                  ! state = 15

    ! Set display flag bit 30 (marks race as active for rendering)
    mov.l   @(PC),r2                ! r2 = 0x0605B6D8 (display flags)
    mov.l   @r2,r3
    mov.l   @(PC),r0                ! r0 = 0x40000000
    or      r0,r3
    mov.l   r3,@r2                  ! display_flags |= 0x40000000

    ! Epilogue
    mov.l   @r15+,r8
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    mov.l   @r15+,r14
    lds.l   @r15+,pr
    rts
    nop


! ==========================================================================
! FUN_06009098 — State 15: Main Race Loop (CORE GAMEPLAY)
! ==========================================================================
! This is THE main gameplay state. Runs every frame during active racing.
! Contains the critical per-car inner loop that drives physics and rendering.
!
! Structure:
!   1. Start button check → time extension (state 18)
!   2. Decrement countdown timer
!   3. Optional: menu overlay, sub-initialization
!   4. Per-car inner loop (r12 = 0 to car_count):
!      - First iteration (player): set init_flag=1, load player car object
!      - Each iteration calls 4 functions per car:
!        a. FUN_060302C6 — per-car sound update
!        b. FUN_0602EFF0 — camera/viewport rendering
!        c. FUN_0602F0E8 — track position management
!        d. FUN_0600DE54 — RACE STATE UPDATE (physics, collision, position)
!   5. Post-loop: car finalization, race end checks
!   6. Tail call FUN_060078DC (frame timing/sync)
!
! Called from: main state dispatch (state index 15)
! Transitions to: State 16 (countdown=0 or race_end), State 18 (start button)

FUN_06009098:       ! 0x06009098
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    add     #-4,r15

    ! Cache key addresses in callee-saved registers
    mov.l   @(PC),r8                ! r8 = 0x0607ED88 (&timer_byte)
    mov.l   @(PC),r9                ! r9 = 0x0607E940 (&current_car_ptr)
    mov.l   @(PC),r10               ! r10 = 0x0605AD10 (&state_var)
    mov.l   @(PC),r11               ! r11 = 0x0607ED8C (&init_flag)
    mov.l   @(PC),r14               ! r14 = 0x0607E944 (&current_car_2)

    ! === Start button check ===
    mov.l   @(PC),r3                ! r3 = 0x06063D9A (&new_buttons)
    mov.w   @r3,r2                  ! r2 = new_buttons
    extu.w  r2,r2
    mov.w   @(PC),r3                ! r3 = 0x0800 (start button mask)
    and     r3,r2
    tst     r2,r2
    bt      .s15_no_start           ! start not pressed

    ! Start pressed: save resume point, enter time extension
    mov     #15,r3
    mov.l   @(PC),r2                ! r2 = 0x0607EACC (&resume_state)
    mov.l   r3,@r2                  ! resume_state = 15
    mov     #18,r3
    mov.l   r3,@r10                 ! state = 18 (time extension setup)
.s15_no_start:

    ! === Decrement countdown timer ===
    mov.l   @(PC),r2                ! r2 = 0x0607EAAC (&countdown)
    mov.l   @r2,r3
    add     #-1,r3
    mov.l   r3,@r2                  ! countdown--

    ! === Optional: menu overlay ===
    mov.l   @(PC),r0                ! r0 = 0x0605AB18 (&menu_overlay)
    mov.b   @r0,r0
    tst     r0,r0
    bt      .s15_no_menu
    mov.l   @(PC),r3                ! r3 = 0x060268B0 (FUN_060268B0)
    jsr     @r3                     ! call menu overlay
    mov     #0,r4
.s15_no_menu:

    ! === Optional: sub-initialization ===
    mov.w   @r11,r0                 ! r0 = [init_flag] (word)
    extu.w  r0,r0
    tst     r0,r0
    bt      .s15_no_subinit
    mov.l   @(PC),r3                ! r3 = 0x060033E6
    jsr     @r3                     ! call FUN_060033E6 (sub-init)
    nop
.s15_no_subinit:

    ! ==========================================================
    ! PER-CAR INNER LOOP
    ! r12 = car index, iterates from 0 to [car_count]
    ! This is the heartbeat of the race — every car gets
    ! sound, rendering, and physics updated each frame.
    ! ==========================================================
    mov     #0,r12                  ! r12 = 0 (car_index)

.s15_car_loop:
    cmp/eq  #0,r12
    bf      .s15_not_first_car

    ! First iteration (r12==0): player car
    mov     #1,r3
    mov.w   r3,@r11                 ! [init_flag] = 1 (trigger per-car init)
    mov.l   @r14,r3                 ! r3 = car_object_ptr
    mov.l   @(PC),r2                ! r2 = 0x0607E940
    mov.l   r3,@r2                  ! copy to working car pointer
    bra     .s15_do_car_update
    nop

.s15_not_first_car:
    ! Subsequent iterations: AI cars
    mov     #0,r3
    mov.w   r3,@r11                 ! [init_flag] = 0
    ! Load next car from array at 0x06078900
    ! Decrement timer: [timer_byte] -= 2
    mov.l   @r8,r3
    add     #-2,r3
    mov.l   r3,@r8

.s15_do_car_update:
    ! --- Four per-car function calls ---
    mov.l   @(PC),r3                ! r3 = 0x060302C6
    jsr     @r3                     ! FUN_060302C6 — per-car SOUND update
    nop

    mov.l   @(PC),r3                ! r3 = 0x0602EFF0
    jsr     @r3                     ! FUN_0602EFF0 — camera/viewport RENDERING
    nop

    mov.l   @(PC),r3                ! r3 = 0x0602F0E8
    jsr     @r3                     ! FUN_0602F0E8 — track position MANAGEMENT
    nop

    mov.l   @(PC),r3                ! r3 = 0x0600DE54
    jsr     @r3                     ! FUN_0600DE54 — RACE STATE UPDATE
    nop                             ! (physics, collision, position per car)

    ! Increment car index and loop
    add     #1,r12
    mov.l   @(PC),r2                ! r2 = 0x06078634 (&car_count)
    mov.b   @r2,r2
    extu.b  r2,r2
    cmp/ge  r2,r12
    bf      .s15_car_loop
    ! ==========================================================
    ! END PER-CAR LOOP
    ! ==========================================================

    ! === Post-loop: car finalization ===
    mov.l   @(PC),r0                ! r0 = 0x0607EAD8 (&car_object)
    mov.l   @r0,r0
    tst     r0,r0
    bt      .s15_no_car_cleanup
    mov.l   @(PC),r3                ! r3 = 0x0600C302
    jsr     @r3                     ! FUN_0600C302 — car state finalize
    nop
.s15_no_car_cleanup:

    ! === Race end condition checks ===
    ! Path A: countdown reached zero
    mov.l   @(PC),r2                ! r2 = 0x0607EAAC (&countdown)
    mov.l   @r2,r3
    tst     r3,r3
    bf      .s15_check_raceend
    mov     #16,r13                 ! prepare: state = 16 (post-countdown)
.s15_check_raceend:
    ! Path B: external race end flag set
    mov.l   @(PC),r0                ! r0 = 0x0607EAD0 (&race_end_flag)
    mov.l   @r0,r0
    tst     r0,r0
    bt      .s15_no_raceend
    mov     #16,r13                 ! prepare: state = 16
.s15_no_raceend:
    ! If r13 was set to 16 above, it gets written to state_var
    ! (the actual write uses delayed state transition logic)

    ! === Tail call frame sync ===
    lds.l   @r15+,pr
    mov.l   @r15+,r8
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    mov.l   @(PC),r3                ! r3 = 0x060078DC
    jmp     @r3                     ! tail call FUN_060078DC (frame timing/sync)
    mov.l   @r15+,r14               ! restore r14 (delay slot)


! ==========================================================================
! FUN_06009290 — State 16: Post-Countdown Cleanup
! ==========================================================================
! Transition state that runs for a single frame after the race timer
! expires. Cleans up the car object and immediately moves to state 17.
!
! Called from: main state dispatch (state index 16)
! Transitions to: State 17 (always, same frame)

FUN_06009290:       ! 0x06009290
    sts.l   pr,@-r15

    ! Immediately transition to state 17
    mov     #17,r3
    mov.l   @(0x24,PC),r2          ! r2 = 0x0605AD10 (state_var)
    mov.l   r3,@r2                  ! state = 17

    ! Check car object existence for cleanup variant
    mov.l   @(0x24,PC),r0          ! r0 = 0x0607EAD8 (&car_object)
    mov.l   @r0,r0                  ! r0 = car_object pointer
    tst     r0,r0
    bt      .s16_no_car

    ! Car exists: call cleanup A
    mov.l   @(0x20,PC),r3          ! r3 = 0x060121A8 (FUN_060121A8)
    jsr     @r3                     ! cleanup A — full car teardown
    nop
    bra     .s16_done
    nop

.s16_no_car:
    ! No car: call cleanup B (lighter path)
    mov.l   @(0x1C,PC),r3          ! r3 = 0x06012198 (FUN_06012198)
    jsr     @r3                     ! cleanup B — minimal teardown
    nop

.s16_done:
    ! Set phase flag = 4 (signals post-lap phase to other subsystems)
    mov     #4,r2
    mov.l   @(0x18,PC),r3          ! r3 = 0x0605A016 (phase flag)
    lds.l   @r15+,pr
    rts
    mov.w   r2,@r3                  ! [phase_flag] = 4 (delay slot)


! ==========================================================================
! FUN_060092D0 — State 17: Post-Lap Processing / Results Display
! ==========================================================================
! Complex state that handles the period after a lap/countdown expires.
! Manages result display, sound triggers, and multiple exit paths.
!
! This state has FIVE possible transitions:
!   → State 18: Start button pressed (time extension)
!   → State 20: Abort flag (bit 0 of FLAGS_WORD) set
!   → State 24: Countdown timer expires (finish position stored)
!   → State 28: Mode flag == 1 (special mode transition)
!   → (stays): None of the above, continues processing
!
! Key behavior:
!   - Decrements its own countdown at [0x0607EAAC]
!   - When countdown == 200: plays sound 0xAE1134FF (approaching end)
!   - When countdown == 0: reads car_obj[+0x82] as finish position,
!     stores to [0x06078638], transitions to state 24 (post-race)
!   - Runs update pipeline: FUN_0600DE70, FUN_0600A914, FUN_0600BB94,
!     FUN_060053AC (display), FUN_0601D9B0 (sound), FUN_0600BFFC
!   - Tail-calls FUN_060078DC (frame sync)
!
! Called from: main state dispatch (state index 17)

FUN_060092D0:       ! 0x060092D0
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    sts.l   pr,@-r15

    mov.l   @(0x78,PC),r13         ! r13 = 0x0607EAD8 (&car_object)
    mov.l   @(0x78,PC),r14         ! r14 = 0x0605AD10 (&state_var)

    ! === Start button check ===
    mov.l   @(0x7C,PC),r3         ! r3 = 0x06063D9A (&new_buttons)
    mov.w   @r3,r2
    extu.w  r2,r2
    mov.w   @(0x68,PC),r3         ! r3 = 0x0800 (start mask)
    and     r3,r2
    tst     r2,r2
    bt      .s17_no_start

    ! Start pressed: save resume=17, go to time extension
    mov     #17,r3
    mov.l   @(0x70,PC),r2         ! r2 = 0x0607EACC (&resume_state)
    mov.l   r3,@r2                  ! resume_state = 17
    mov     #18,r3
    mov.l   r3,@r14                 ! state = 18
.s17_no_start:

    ! Call FUN_0600A33C (general update)
    mov.l   @(0x6C,PC),r3         ! r3 = 0x0600A33C
    jsr     @r3
    nop

    ! Check skip-flag [0x06085FF4] — if set, bypass countdown logic
    mov.l   @(0x68,PC),r0         ! r0 = 0x06085FF4
    mov.b   @r0,r0
    tst     r0,r0
    bf      .s17_post_section       ! flag set: skip to post-section

    ! Check race end flag — if already set, skip countdown
    mov.l   @(0x64,PC),r0         ! r0 = 0x0607EAD0 (&race_end_flag)
    mov.l   @r0,r0
    tst     r0,r0
    bf      .s17_post_section

    ! === Countdown timer ===
    mov.l   @(0x60,PC),r3         ! r3 = 0x0607EAAC (&countdown)
    mov.l   @(0x60,PC),r2         ! r2 = same (for writeback)
    mov.l   @r3,r3                  ! r3 = countdown value
    add     #-1,r3                  ! countdown--
    cmp/pl  r3                      ! countdown > 0?
    bt/s    .s17_post_section       ! yes: continue (not expired)
    mov.l   r3,@r2                  ! store countdown (delay slot)

    ! === Timer expired! Race over. ===
    mov.l   @(0x58,PC),r3         ! r3 = 0x060192CA (FUN_060192CA)
    jsr     @r3                     ! reset sound channels
    nop

    ! Read finish position from car object
    mov.l   @(0x54,PC),r2         ! r2 = 0x0607E944 (&current_car)
    mov.l   @r2,r2                  ! r2 = car_object pointer
    mov.w   @(0x2A,PC),r0         ! r0 = 0x0082 (offset to finish position)
    mov.l   @(r0,r2),r3            ! r3 = car_obj[+0x82] (finish position)
    mov.l   @(0x50,PC),r1         ! r1 = 0x06078638 (&race_result)
    mov.l   r3,@r1                  ! [race_result] = finish_position

    mov     #24,r3
    mov.l   r3,@r14                 ! state = 24 (post-race!)

.s17_post_section:
    ! === Check abort flag (bit 0 of [0x0607EBF4]) ===
    mov.l   @(0x4C,PC),r4         ! r4 = 0x0607EBF4 (&flags_word)
    mov.l   @r4,r0
    tst     #0x01,r0                ! bit 0 set?
    bt      .s17_no_abort

    ! Abort: clear bit 0, reset sound, transition to state 20
    mov     #-2,r3                  ! mask = 0xFFFFFFFE
    mov.l   @r4,r2
    and     r3,r2
    mov.l   @(0x34,PC),r3         ! r3 = 0x060192CA (reset sound)
    jsr     @r3
    mov.l   r2,@r4                  ! [flags_word] &= ~1 (delay slot)

    mov     #20,r2
    mov.l   @(0x3C,PC),r3         ! r3 = 0x06018E70 (sound transition fn)
    jsr     @r3
    mov.l   r2,@r14                 ! state = 20 (delay slot)
    bra     .s17_section3
    nop

.s17_no_abort:
    ! If race not ended, increment idle frame counter
    mov.l   @(PC),r0               ! r0 = 0x0607EAD0
    mov.l   @r0,r0
    tst     r0,r0
    bf      .s17_section3
    mov.l   @(PC),r4               ! r4 = 0x0607EBD0 (&frame_counter)
    mov.l   @r4,r3
    add     #1,r3
    mov.l   r3,@r4                  ! frame_counter++

.s17_section3:
    ! === Sound trigger: countdown == 200 → play 0xAE1134FF ===
    mov.l   @(PC),r2               ! r2 = 0x06086054 (&sound_timer)
    mov.w   @r2,r2
    extu.w  r2,r2
    tst     r2,r2
    bf      .s17_no_sound           ! sound_timer != 0: skip (cooldown active)

    mov.l   @(PC),r3               ! r3 = 0x0607EAAC (&countdown)
    mov.w   @(PC),r2               ! r2 = 200 (0xC8)
    mov.l   @r3,r3                  ! r3 = countdown
    cmp/eq  r2,r3                   ! countdown == 200?
    bf      .s17_no_sound

    ! Play countdown warning sound
    mov.l   @(PC),r5               ! r5 = 0xAE1134FF (sound command)
    mov.l   @(PC),r3               ! r3 = 0x0601D5F4 (sound API)
    jsr     @r3
    mov     #0,r4                   ! r4 = 0 (type 0: direct command)

    mov     #40,r2
    mov.l   @(PC),r3               ! r3 = 0x06086054 (&sound_timer)
    mov.w   r2,@r3                  ! [sound_timer] = 40 (cooldown frames)
.s17_no_sound:

    ! === Car display/cleanup ===
    mov.l   @(PC),r0               ! r0 = 0x06078636 (&display_mode)
    mov.b   @r0,r0
    tst     r0,r0
    bt      .s17_no_display

    mov.l   @r13,r0                 ! r0 = car_object
    tst     r0,r0
    bt      .s17_cleanup_b
    mov.l   @(PC),r3               ! r3 = 0x060121A8 (cleanup A)
    jsr     @r3
    nop
    bra     .s17_no_display
    nop
.s17_cleanup_b:
    mov.l   @(PC),r3               ! r3 = 0x06012198 (cleanup B)
    jsr     @r3
    nop
.s17_no_display:

    ! === External event handling ===
    mov.l   @(PC),r0               ! r0 = 0x0607EAE0 (&external_event)
    mov.l   @r0,r0
    tst     r0,r0
    bt      .s17_no_ext
    mov.l   @(PC),r3               ! r3 = 0x0601DE50
    jsr     @r3                     ! FUN_0601DE50 — external event handler
    nop
    mov.l   @r13,r0                 ! car_object
    tst     r0,r0
    bt      .s17_no_ext
    mov.l   @(PC),r3               ! r3 = 0x0601DBB8
    jsr     @r3                     ! FUN_0601DBB8 — sound event
    nop
.s17_no_ext:

    ! === Menu overlay check ===
    mov.l   @(PC),r0               ! r0 = 0x0605AB18 (&menu_overlay)
    mov.b   @r0,r0
    tst     r0,r0
    bt      .s17_no_menu
    mov.l   @(PC),r3               ! r3 = 0x060268B0
    jsr     @r3                     ! FUN_060268B0 — menu overlay
    mov     #0,r4
.s17_no_menu:

    ! === Mode check: mode == 1 → state 28 ===
    mov.l   @(PC),r0               ! r0 = 0x0605A1C4 (&mode_flag)
    mov.l   @r0,r0
    cmp/eq  #1,r0
    bf      .s17_no_mode28
    mov     #28,r3
    mov.l   r3,@r14                 ! state = 28
.s17_no_mode28:

    ! === Car object == 2: HUD update ===
    mov.l   @r13,r0                 ! r0 = car_object
    cmp/eq  #2,r0
    bf      .s17_no_hud
    mov.l   @(PC),r3               ! r3 = 0x06033BC8
    jsr     @r3                     ! FUN_06033BC8 — HUD update
    nop
.s17_no_hud:

    ! === Main update pipeline ===
    mov.l   @(PC),r3               ! r3 = 0x0600DE70
    jsr     @r3                     ! FUN_0600DE70
    nop
    mov.l   @(PC),r3               ! r3 = 0x0600A914
    jsr     @r3                     ! FUN_0600A914
    nop
    mov.l   @(PC),r3               ! r3 = 0x0600BB94
    jsr     @r3                     ! FUN_0600BB94
    nop

    ! Display system
    mov.l   @(PC),r6               ! r6 = 0x06063E24
    mov.l   @(PC),r5               ! r5 = 0x06063EEC
    mov.l   @(PC),r4               ! r4 = 0x06063EF8
    mov.l   @(PC),r3               ! r3 = 0x060053AC
    jsr     @r3                     ! FUN_060053AC — display commit
    mov.l   @r6,r6                  ! dereference r6 (delay slot)

    mov.l   @(PC),r3               ! r3 = 0x0601D9B0
    jsr     @r3                     ! FUN_0601D9B0 — sound update
    nop
    mov.l   @(PC),r3               ! r3 = 0x0600BFFC
    jsr     @r3                     ! FUN_0600BFFC
    nop

    ! === Sub-init and position checks ===
    mov.l   @(PC),r0               ! r0 = 0x0607ED8C (&init_flag)
    mov.w   @r0,r0
    extu.w  r0,r0
    tst     r0,r0
    bt      .s17_no_subinit
    mov.l   @(PC),r3               ! r3 = 0x060033E6
    jsr     @r3                     ! FUN_060033E6 — sub-init
    nop
.s17_no_subinit:

    ! Check car finish position: car_obj[+0x82] > 0 → process result
    mov.l   @(PC),r2               ! r2 = 0x0607E944 (&current_car)
    mov.w   @(PC),r0               ! r0 = 0x0082
    mov.l   @r2,r2
    mov.l   @(r0,r2),r3            ! r3 = car_obj[+0x82]
    cmp/pl  r3                      ! position > 0?
    bf      .s17_no_score
    bsr     FUN_0600A084            ! process race result
    nop
.s17_no_score:

    ! === Tail call frame sync ===
    lds.l   @r15+,pr
    mov.l   @r15+,r13
    mov.l   @(PC),r3               ! r3 = 0x060078DC
    jmp     @r3                     ! tail call FUN_060078DC
    mov.l   @r15+,r14               ! restore r14 (delay slot)


! ==========================================================================
! FUN_060096DC — State 18: Time Extension Setup (SINGLE FRAME)
! ==========================================================================
! One-shot setup state that prepares the time extension UI.
! Saves current difficulty, displays "TIME EXTENSION" overlay text,
! plays transition sound, and immediately advances to state 19.
!
! Called from: main state dispatch (state index 18)
! Entered via: Start button in states 15, 17, or 29
! Transitions to: State 19 (always, same frame)

FUN_060096DC:       ! 0x060096DC
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    add     #-4,r15

    ! Call time extension UI initialization
    bsr     FUN_06009FFC            ! FUN_06009FFC — set up time extension UI
    nop

    ! Transition to state 19
    mov     #19,r2
    mov.l   @(0x64,PC),r3         ! r3 = 0x0605AD10 (&state_var)
    mov     #0,r14                  ! r14 = 0 (used as zero constant below)
    mov.l   r2,@r3                  ! state = 19

    ! Save current difficulty, then clear it
    mov.l   @(0x64,PC),r4         ! r4 = 0x06078654 (&difficulty_current)
    mov.l   @(0x64,PC),r3         ! r3 = 0x06078652 (&difficulty_saved)
    mov.b   @r4,r2                  ! r2 = current difficulty
    mov.b   r2,@r3                  ! [difficulty_saved] = current (backup!)
    extu.b  r14,r2                  ! r2 = 0
    mov.b   r2,@r4                  ! [difficulty_current] = 0 (clear)

    ! Clear frame counter (used for start button debounce in state 19)
    mov.l   @(0x60,PC),r2         ! r2 = 0x06078650 (&frame_count_word)
    mov.w   r14,@r2                 ! [frame_counter] = 0

    ! Display "TIME EXTENSION" text via VDP
    mov.l   @(0x60,PC),r7         ! r7 = 0x060446CC (text data address)
    mov.w   @(0x44,PC),r6         ! r6 = screen position Y
    mov.w   @(0x44,PC),r5         ! r5 = screen position X
    mov.l   @(0x5C,PC),r2         ! r2 = 0x060284AE (FUN_060284AE — VDP text+number)
    jsr     @r2
    mov     #8,r4                   ! r4 = 8 (VDP layer/priority)

    ! Display additional overlay lines (positioned below main text)
    mov.l   @(0x5C,PC),r3         ! r3 = 0x0605AC9C (HUD area base)
    mov.l   r3,@r15                 ! save to stack
    mov     r3,r7
    mov.l   @(0x58,PC),r6         ! r6 = 0x0000F000 (VDP color: white)
    mov.w   @(0x36,PC),r5         ! r5 = position offset
    add     #46,r7                  ! r7 += 46 (position within HUD area)
    mov.l   @(0x58,PC),r3         ! r3 = 0x060283E0 (FUN_060283E0 — VDP text)
    jsr     @r3
    mov     #8,r4

    ! Second overlay line
    mov.l   @r15,r7                 ! r7 = HUD area base (from stack)
    mov.l   @(0x4C,PC),r6         ! r6 = 0x0000F000
    mov.w   @(0x2A,PC),r5         ! r5 = position offset
    mov.l   @(0x4C,PC),r3         ! r3 = 0x060283E0
    add     #47,r7                  ! r7 += 47
    jsr     @r3
    mov     #8,r4

    ! Set display flag bit 2 (triggers display update)
    mov.l   @(0x48,PC),r4         ! r4 = 0x0605B6D8 (&display_flags)
    mov.l   @(0x48,PC),r3         ! r3 = 0x06026CE0 (FUN_06026CE0)
    mov.l   @r4,r0
    or      #0x04,r0                ! display_flags |= 0x04
    jsr     @r3                     ! call display update
    mov.l   r0,@r4                  ! store flags (delay slot)

    ! Clear results flag
    mov.l   @(0x44,PC),r3         ! r3 = 0x06059F44 (&results_flag)
    mov.l   r14,@r3                 ! [results_flag] = 0

    ! Play transition sound (tail call)
    mov.l   @(0x44,PC),r5         ! r5 = 0xAE0004FF (transition sound)
    mov     r14,r4                  ! r4 = 0 (type 0: direct command)
    add     #4,r15
    lds.l   @r15+,pr
    mov.l   @(0x40,PC),r3         ! r3 = 0x0601D5F4 (sound API)
    jmp     @r3                     ! tail call — play sound and return
    mov.l   @r15+,r14               ! restore r14 (delay slot)


! ==========================================================================
! FUN_06009788 — State 19: Time Extension Active / Input Processing
! ==========================================================================
! The main time extension state. Runs every frame while the player
! decides whether to continue racing. Complex state with multiple paths:
!
! If mode_byte [0x0607864A] != 0 (speed selection mode):
!   - Up button (0x8000): speed++ at [0x06078649], max 99
!   - Down button (0x4000): speed--, min 1
!   - Displays speed number and label text on screen
!
! Start button confirmation (only after >= 20 frames):
!   - Plays 0xAE0004FF (transition sound)
!   - Restores saved state from [0x0607EACC] → state_var (returns to race!)
!   - Restores difficulty from [0x06078652] → [0x06078654]
!   - If mode was set: calls FUN_06018DDC(speed) for difficulty config
!
! Secret input — A+B+C held simultaneously (mask 0x70 on held buttons):
!   - Calls FUN_0600A1B8 (special/debug function)
!   - Sets bit 31 in display_flags (0x80000000)
!   - If init_flag [0x0607ED8C] set: → state 24 (force post-race)
!   - If init_flag clear: → state 14 (BACK TO TITLE SCREEN!)
!
! Normal frame (no button input):
!   - Increments frame counter at [0x06078650]
!   - Blinks "TIME EXTENSION" text every 16 frames (bit 4 of counter)
!
! Called from: main state dispatch (state index 19)
! Transitions to: saved_state (start), State 24 (A+B+C+init), State 14 (A+B+C)

FUN_06009788:       ! 0x06009788
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    add     #-8,r15                 ! 8 bytes local storage

    ! Cache constants in callee-saved registers
    mov.l   @(0x48,PC),r8         ! r8 = 0x0000F000 (VDP color: white)
    mov.l   @(0x48,PC),r10        ! r10 = 0x0605B6D8 (&display_flags)
    mov.l   @(0x4C,PC),r11        ! r11 = 0x0607ED8C (&init_flag)
    mov.l   @(0x4C,PC),r12        ! r12 = 0x06078649 (&speed_byte)

    ! Read button states into stack locals
    mov.l   @(0x50,PC),r4         ! r4 = 0x06063D98 (&buttons_held)
    mov.w   @(2,r4),r0             ! r0 = [buttons_new] (at +2)
    mov     r0,r3
    mov.w   r3,@r15                 ! stack[0] = new_buttons
    mov.w   @r4,r3                  ! r3 = [buttons_held]
    mov     r3,r0
    mov.w   r0,@(4,r15)            ! stack[4] = held_buttons

    ! === Menu overlay check ===
    mov.l   @(0x44,PC),r0         ! r0 = 0x0605AB18 (&menu_overlay)
    mov.b   @r0,r0
    tst     r0,r0
    bt      .s19_no_menu
    mov.l   @(0x40,PC),r3         ! r3 = 0x060268B0
    jsr     @r3                     ! FUN_060268B0 — menu overlay
    mov     #0,r4
.s19_no_menu:

    ! === Mode flag check ===
    mov.l   @(0x40,PC),r0         ! r0 = 0x0607864A (&mode_byte)
    mov.b   @r0,r0
    tst     r0,r0
    bt      .s19_frame_counter      ! mode == 0: skip speed selection UI

    ! === SPEED SELECTION UI (mode != 0) ===
    ! Up button: speed++ (max 99)
    mov.w   @r15,r3                 ! r3 = new_buttons
    mov.l   @(0x38,PC),r2         ! r2 = 0x00008000 (up button mask)
    extu.w  r3,r3
    and     r2,r3
    tst     r3,r3
    bt      .s19_check_down         ! up not pressed

    mov     #99,r2                  ! max speed = 99
    mov.b   @r12,r3                 ! r3 = current speed
    extu.b  r3,r3
    cmp/ge  r2,r3                   ! speed >= 99?
    bt      .s19_display_speed      ! at max, don't increment
    mov.b   @r12,r2
    add     #1,r2                   ! speed++
    bra     .s19_display_speed
    mov.b   r2,@r12                 ! store (delay slot)

.s19_check_down:
    ! Down button: speed-- (min 1)
    mov.w   @r15,r2                 ! r2 = new_buttons
    mov.w   @(PC),r3               ! r3 = 0x4000 (down button mask)
    extu.w  r2,r2
    and     r3,r2
    tst     r2,r2
    bt      .s19_display_speed      ! down not pressed

    mov     #1,r2                   ! min speed = 1
    mov.b   @r12,r3
    extu.b  r3,r3
    cmp/gt  r2,r3                   ! speed > 1?
    bf      .s19_display_speed      ! at min, don't decrement
    mov.b   @r12,r2
    add     #-1,r2                  ! speed--
    mov.b   r2,@r12

.s19_display_speed:
    ! Display speed number on screen
    mov.b   @r12,r7                 ! r7 = speed value
    mov     r8,r6                   ! r6 = 0xF000 (color)
    mov.w   @(PC),r5               ! r5 = screen position
    mov.l   @(PC),r3               ! r3 = 0x0602834A (FUN_0602834A — number display)
    extu.b  r7,r7
    jsr     @r3
    mov     #8,r4

    ! Display "SPEED" label text
    mov     r8,r6                   ! r6 = color
    mov.w   @(PC),r5               ! r5 = position
    mov.l   @(PC),r7               ! r7 = 0x060446E0 (text: "SPEED" or similar)
    mov.l   @(PC),r3               ! r3 = 0x060283E0 (VDP text)
    jsr     @r3
    mov     #8,r4

.s19_frame_counter:
    ! === START BUTTON CONFIRMATION ===
    ! Requires >= 20 frames elapsed (debounce)
    mov.w   @(PC),r9               ! r9 = VDP constant
    mov.w   @(PC),r13              ! r13 = VDP constant
    mov.l   @(PC),r14              ! r14 = 0x060284AE (FUN_060284AE — VDP num+text)

    mov.w   @r15,r2                 ! r2 = new_buttons
    mov.w   @(PC),r3               ! r3 = 0x0800 (start button)
    extu.w  r2,r2
    and     r3,r2
    tst     r2,r2
    bt      .s19_no_start           ! start not pressed

    ! Start pressed — check debounce timer
    mov     #20,r2
    mov.l   @(PC),r3               ! r3 = 0x06078650 (&frame_counter)
    mov.w   @r3,r3
    extu.w  r3,r3
    cmp/ge  r2,r3                   ! counter >= 20?
    bf      .s19_no_start           ! too early, ignore

    ! Check if already confirmed
    mov.l   @(PC),r0               ! r0 = 0x0607864A (&mode_byte)
    mov.b   @r0,r0
    cmp/eq  #1,r0                   ! mode == 1?
    bt      .s19_no_start           ! already processed

    ! === CONFIRMED! Restore state and return to race ===
    mov.l   @(PC),r5               ! r5 = 0xAE0004FF (transition sound)
    mov.l   @(PC),r3               ! r3 = 0x0601D5F4 (sound API)
    jsr     @r3                     ! play confirmation sound
    mov     #0,r4

    ! Display final overlay (3 VDP text calls for UI elements)
    ! ... (3 jsr @r14 calls with different r7/r5/r6 for HUD positions) ...

    ! Restore game state from saved resume point
    mov.l   @(PC),r3               ! r3 = 0x0607EACC (&resume_state)
    mov.l   @(PC),r2               ! r2 = 0x0605AD10 (&state_var)
    mov.l   @r3,r3                  ! r3 = saved_state (15 or 17)
    mov.l   r3,@r2                  ! state = saved_state (RETURN TO RACE!)

    ! Restore difficulty from backup
    mov.l   @(PC),r3               ! r3 = 0x06078652 (&difficulty_saved)
    mov.l   @(PC),r2               ! r2 = 0x06078654 (&difficulty_current)
    mov.b   @r3,r3
    mov.b   r3,@r2                  ! difficulty_current = difficulty_saved

    ! Check mode byte for difficulty reconfiguration
    mov.l   @(PC),r0               ! r0 = 0x0607864A (&mode_byte)
    mov.b   @r0,r0
    tst     r0,r0
    bf      .s19_mode_setup         ! mode != 0: reconfigure difficulty
    bra     .s19_common_end         ! mode 0: just return to race
    nop

.s19_mode_setup:
    ! Clear mode, apply selected speed as difficulty
    mov     #0,r3
    mov     #15,r6
    mov.l   @(PC),r2               ! r2 = 0x0607864A
    mov.b   r3,@r2                  ! [mode_byte] = 0

    mov.b   @r12,r5                 ! r5 = speed [0x06078649]
    extu.b  r5,r5
    mov.l   r5,@r15                 ! save to stack
    mov.l   @(PC),r3               ! r3 = 0x06018DDC
    jsr     @r3                     ! FUN_06018DDC(speed) — DIFFICULTY SETUP!
    mov     r5,r4                   ! r4 = speed (delay slot)

    ! Display updated difficulty text
    mov.l   @(PC),r7               ! r7 = 0x060446EC (text data)
    mov     r8,r6                   ! r6 = color
    mov.w   @(PC),r5               ! r5 = position
    mov.l   @(PC),r3               ! r3 = 0x060283E0 (VDP text)
    jsr     @r3
    mov     #8,r4
    bra     .s19_common_end
    nop

.s19_no_start:
    ! === Check secret button combo: A+B+C held (0x70) ===
    mov     #0x70,r4               ! mask = A+B+C buttons
    mov.w   @(4,r15),r0            ! r0 = held_buttons
    mov     r0,r2
    extu.w  r2,r2
    and     r4,r2
    cmp/eq  r4,r2                   ! all three held simultaneously?
    bf      .s19_normal_frame       ! no: normal frame

    ! === SECRET INPUT: A+B+C held ===
    bsr     FUN_0600A1B8            ! call special/debug function
    nop
    mov.l   @(PC),r2               ! r2 = 0x80000000
    mov.l   @r10,r3                 ! r3 = display_flags
    or      r2,r3
    mov.l   r3,@r10                 ! display_flags |= 0x80000000 (bit 31)

    ! Check init flag to determine exit path
    mov.w   @r11,r0                 ! r0 = [init_flag]
    extu.w  r0,r0
    tst     r0,r0
    bt      .s19_back_to_title      ! init_flag == 0: go to title

    ! init_flag set: force to post-race results (state 24)
    mov     #1,r3
    mov.l   @(PC),r2               ! r2 = 0x0607EBF4 (&flags_word)
    mov.l   r3,@r2                  ! [flags_word] = 1
    mov     #2,r3
    mov     #24,r2
    mov.w   r3,@r11                 ! [init_flag] = 2
    mov.l   @(PC),r3               ! r3 = 0x0605AD10 (&state_var)
    mov.l   r2,@r3                  ! state = 24 (POST-RACE)
    mov.l   @(PC),r3               ! r3 = 0x06026CE0 (display update)
    jsr     @r3
    nop
    mov     #0,r2
    mov.l   @(PC),r3               ! r3 = 0x06059F44 (&results_flag)
    mov.l   r2,@r3                  ! clear results
    bra     .s19_common_end
    nop

.s19_back_to_title:
    ! A+B+C held with no init flag: EXIT TO TITLE SCREEN
    mov     #1,r2
    mov.l   @(PC),r3               ! r3 = 0x0605AD08 (&back_to_title)
    mov.l   r2,@r3                  ! [back_to_title] = 1
    mov     #14,r2
    mov.l   @(PC),r3               ! r3 = 0x0605AD10 (&state_var)
    mov.l   r2,@r3                  ! state = 14 (RESTART AT RACE SETUP!)
    bra     .s19_common_end
    nop

.s19_normal_frame:
    ! === Normal frame: increment counter, blink text ===
    mov.l   @(PC),r4               ! r4 = 0x06078650 (&frame_counter)
    mov.w   @r4,r0
    add     #1,r0
    mov.w   r0,@r4                  ! frame_counter++
    extu.w  r0,r0
    tst     #0x10,r0                ! test bit 4 (toggles every 16 frames)
    bt      .s19_blink_off

    ! Bit 4 set: show "TIME EXTENSION" text (blinking ON phase)
    ! ... (2 jsr @r14 calls for VDP text display) ...
    bra     .s19_common_end
    nop

.s19_blink_off:
    ! Bit 4 clear: check init flag for display variant
    mov.w   @r11,r0                 ! r0 = [init_flag]
    extu.w  r0,r0
    tst     r0,r0
    bt      .s19_standard_display

    ! Active time extension: text from 0x060446FC / 0x06044718
    ! ... (2 jsr @r14 calls) ...
    bra     .s19_display_tail
    nop

.s19_standard_display:
    ! Standard: text from 0x060446FC / 0x0604472C
    ! ... (2 jsr @r14 calls) ...

.s19_display_tail:
    ! Common display tail (second text line)
    ! ... (jsr @r14 for final text line) ...

.s19_common_end:
    ! === Sub-init check ===
    mov.w   @r11,r0                 ! r0 = [init_flag]
    extu.w  r0,r0
    tst     r0,r0
    bt      .s19_no_subinit
    mov.l   @(PC),r3               ! r3 = 0x060033E6
    jsr     @r3                     ! FUN_060033E6 — sub-init
    nop
.s19_no_subinit:

    ! === Debug display check ===
    mov.l   @(PC),r0               ! r0 = 0x06086030 (&debug_flag)
    mov.b   @r0,r0
    extu.b  r0,r0
    tst     r0,r0
    bt      .s19_no_debug
    mov     r8,r6                   ! color
    mov.w   @(PC),r5               ! position
    mov.l   @(PC),r7               ! r7 = 0x0605A1C8 (debug data)
    mov.l   @(PC),r3               ! r3 = 0x060283E0 (VDP text)
    jsr     @r3                     ! debug display
    mov     #8,r4
.s19_no_debug:

    ! === Display update + cleanup ===
    mov.l   @r10,r0                 ! r0 = display_flags
    mov.l   @(PC),r3               ! r3 = 0x06026CE0 (FUN_06026CE0)
    or      #0x04,r0                ! display_flags |= 0x04 (bit 2)
    jsr     @r3                     ! call display update
    mov.l   r0,@r10                 ! store flags (delay slot)

    mov     #0,r2
    mov.l   @(PC),r3               ! r3 = 0x06059F44 (&results_flag)
    mov.l   r2,@r3                  ! [results_flag] = 0

    ! Epilogue
    add     #8,r15
    lds.l   @r15+,pr
    mov.l   @r15+,r8
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14               ! restore r14 (delay slot)


! ==========================================================================
! FUN_06009A60 — State 20: Race Completion Initialization
! ==========================================================================
! Runs when the race timer expires in state 17. Performs end-of-race setup:
! reads finish position from car struct, configures difficulty for results
! screen, sets flag bits based on player mode, and transitions to state 21.
!
! This is a COMPLEX initialization state with multiple dispatch tables
! based on player mode (single/vs/3-player from *0x0607EAD8):
!   Mode 0: set overlay bit 0x01
!   Mode 1: set overlay bit 0x02
!   Mode 2: set overlay bit 0x04
!
! Called from: main state dispatch (state index 20)
! Transitions to: State 21 (always)

FUN_06009A60:       ! 0x06009A60
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov     #0,r13                  ! r13 = 0 (zero constant)
    mov.l   r11,@-r15
    mov     #1,r11                  ! r11 = 1 (one constant)
    mov.l   r10,@-r15
    mov     #4,r10                  ! r10 = 4 (four constant)
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    add     #-4,r15

    ! Cache key addresses
    mov.l   @(0x98,PC),r9         ! r9 = 0x06078637 (&result_byte)
    mov.l   @(0x9C,PC),r12        ! r12 = 0x0607E944 (&car_ptr_pri)
    mov.l   @(0x9C,PC),r14        ! r14 = 0x0605AB17 (&overlay_flags_hi)

    ! === Initialize race completion ===
    mov.l   @(0xA0,PC),r3         ! r3 = 0x06014A04
    jsr     @r3                     ! FUN_06014A04 — race end initialization
    mov.l   @r12,r8                 ! r8 = car_object (delay slot, cached for later)

    mov.l   @(0x9C,PC),r3         ! r3 = 0x060210F6
    jsr     @r3                     ! FUN_060210F6 — reset/cleanup
    nop

    bsr     FUN_06009FFC            ! FUN_06009FFC — time extension UI setup
    nop

    ! === Read button event, compute difficulty ===
    mov     r13,r6                  ! r6 = 0
    mov.l   @(0x94,PC),r5         ! r5 = 0x06078648 (&button_event)
    mov.b   @r5,r5                  ! r5 = button_event_id (0-3)
    add     #10,r5                  ! r5 = event + 10 (difficulty param)
    mov.l   r5,@r15                 ! save to stack
    mov.l   @(0x90,PC),r3         ! r3 = 0x06018DDC
    jsr     @r3                     ! FUN_06018DDC(event+10) — DIFFICULTY SETUP
    mov     r5,r4                   ! r4 = event+10 (delay slot)

    ! === Read finish position from car object ===
    mov.l   @r12,r2                 ! r2 = car_object
    mov.w   @(0x6C,PC),r0         ! r0 = 0x0082 (finish position offset)
    mov.l   @(r0,r2),r3            ! r3 = car_obj[+0x82] (finish position)
    add     #28,r0                  ! r0 = 0x009E (secondary result offset)
    mov.b   r3,@r9                  ! [result_byte 0x06078637] = finish position (byte)
    mov.l   @r12,r3                 ! reload car ptr
    mov.l   @(0x84,PC),r1         ! r1 = 0x06078638 (&race_result)
    mov.l   @(r0,r3),r2            ! r2 = car_obj[+0x9E] (detailed result)
    mov.l   r2,@r1                  ! [race_result] = detailed_result

    ! Copy race data
    mov.l   @(0x80,PC),r3         ! r3 = 0x060786A4
    mov.l   @(0x84,PC),r2         ! r2 = 0x0607863C
    mov.l   @r3,r3
    mov.l   r3,@r2                  ! [0x0607863C] = [0x060786A4]

    ! === Flag setting: first condition block ===
    ! If [0x06083255] != 0 AND [0x0605AD00] > 1 AND result_byte == 0 AND [0x0607EAE0] == 0:
    !   Set bit 0x08 in overlay_flags_hi [0x0605AB17]
    mov.l   @(PC),r0               ! r0 = 0x06083255
    mov.b   @r0,r0
    tst     r0,r0
    bt      .s20_skip_flag1
    mov     #1,r2
    mov.l   @(PC),r3               ! r3 = 0x0605AD00
    mov.l   @r3,r3
    cmp/gt  r2,r3                   ! [0x0605AD00] > 1?
    bf      .s20_skip_flag1
    mov.b   @r9,r2                  ! r2 = result_byte
    tst     r2,r2                   ! result == 0? (first place)
    bf      .s20_skip_flag1
    mov.l   @(PC),r0               ! r0 = 0x0607EAE0
    mov.l   @r0,r0
    tst     r0,r0
    bf      .s20_skip_flag1
    mov.b   @r14,r0                 ! read overlay flags
    or      #0x08,r0                ! set bit 3
    exts.b  r0,r0
    mov.b   r0,@r14                 ! write back

.s20_skip_flag1:
    ! === Flag setting: second condition block (skip flag path) ===
    ! If [0x06085FF4] != 0 AND [0x0605AD04] > 1 AND [0x0607EAE0] == 0:
    !   Dispatch on player mode to set overlay bits in [0x0605AB16/17]
    mov.l   @(PC),r0               ! r0 = 0x06085FF4
    mov.b   @r0,r0
    tst     r0,r0
    bt      .s20_common             ! skip flag clear: skip entire block

    mov     #1,r2
    mov.l   @(PC),r3               ! r3 = 0x0605AD04
    mov.l   @r3,r3
    cmp/gt  r2,r3
    bf      .s20_common

    mov.l   @(PC),r0               ! r0 = 0x0607EAE0
    mov.l   @r0,r0
    tst     r0,r0
    bf      .s20_common

    ! Result < 3 check, then dispatch on player mode
    mov.b   @r9,r3                  ! r3 = result_byte
    mov     #3,r2
    cmp/ge  r2,r3                   ! result >= 3?
    bt      .s20_overlay_b          ! yes: skip to second overlay

    ! === First overlay dispatch: [0x0605AB16] ===
    mov.l   @(PC),r4               ! r4 = 0x0605AB16 (&overlay_flags_lo)
    mov.l   @(PC),r0               ! r0 = 0x0607EAD8 (&player_mode)
    bra     .s20_dispatch_a
    mov.l   @r0,r0                  ! r0 = player_mode (delay slot)

    ! Mode 0: OR bit 1 into [0x0605AB16]
.s20_mode0_a:
    mov.b   @r4,r2
    bra     .s20_write_a
    or      r11,r2                  ! r2 |= 1

    ! Mode 1: OR bit 2 into [0x0605AB16]
.s20_mode1_a:
    mov.b   @r4,r0
    or      #0x02,r0
    exts.b  r0,r0
    bra     .s20_overlay_b
    mov.b   r0,@r4

    ! Mode 2: OR bit 4 into [0x0605AB16]
.s20_mode2_a:
    mov.b   @r4,r2
    or      r10,r2                  ! r2 |= 4

.s20_write_a:
    exts.b  r2,r2
    bra     .s20_overlay_b
    mov.b   r2,@r4

.s20_dispatch_a:
    cmp/eq  #0,r0
    bt      .s20_mode0_a
    cmp/eq  #1,r0
    bt      .s20_mode1_a
    cmp/eq  #2,r0
    bt      .s20_mode2_a

.s20_overlay_b:
    ! If result_byte != 0, skip second overlay
    mov.b   @r9,r2
    tst     r2,r2
    bf      .s20_common

    ! === Second overlay dispatch: [0x0605AB17] ===
    mov.l   @(PC),r0               ! r0 = 0x0607EAD8
    bra     .s20_dispatch_b
    mov.l   @r0,r0

.s20_mode0_b:
    mov.b   @r14,r2
    bra     .s20_write_b
    or      r11,r2                  ! |= 1

.s20_mode1_b:
    mov.b   @r14,r0
    or      #0x02,r0
    exts.b  r0,r0
    bra     .s20_common
    mov.b   r0,@r14

.s20_mode2_b:
    mov.b   @r14,r2
    or      r10,r2                  ! |= 4

.s20_write_b:
    exts.b  r2,r2
    bra     .s20_common
    mov.b   r2,@r14

.s20_dispatch_b:
    cmp/eq  #0,r0
    bt      .s20_mode0_b
    cmp/eq  #1,r0
    bt      .s20_mode1_b
    cmp/eq  #2,r0
    bt      .s20_mode2_b

.s20_common:
    ! === Special input handler ===
    bsr     FUN_0600A1B8
    nop

    ! === Determine update mode based on car position ===
    ! r4 = 0x06083261 (&update_mode)
    mov     r8,r0                   ! r0 = car_object
    mov.l   @(PC),r4               ! r4 = 0x06083261
    mov.b   @(0x3,r0),r0           ! r0 = car_obj[+3] (byte flags)
    tst     #0x08,r0                ! bit 3 set?
    bf      .s20_mode2              ! yes: force update_mode = 2

    ! Bit 3 clear: dispatch on player mode
    mov.l   @(PC),r0               ! r0 = 0x0607EAD8
    bra     .s20_mode_dispatch
    mov.l   @r0,r0                  ! r0 = player_mode

    ! Mode 0: check car Z position
.s20_pos_mode0:
    mov.l   @(0x18,r8),r2         ! r2 = car.Z
    mov.l   @(PC),r3               ! r3 = 0xFFB80000 (-4718592)
    cmp/ge  r3,r2                   ! car.Z >= -4718592?
    bf      .s20_mode_0_set         ! no: update_mode = 0
    bra     .s20_finalize
    nop                             ! yes: update_mode = 1 (in delay slot path)

    ! Mode 1: check car X position
.s20_pos_mode1:
    mov.l   @(0x10,r8),r2         ! r2 = car.X
    mov.l   @(PC),r3               ! r3 = 0xFEC60000 (-1286144)
    cmp/gt  r3,r2                   ! car.X > -1286144?
    bt      .s20_mode_0_set         ! yes: update_mode = 0
    bra     .s20_finalize           ! no: update_mode = 1
    mov.b   r11,@r4                 ! [update_mode] = 1 (delay slot)

.s20_mode_0_set:
    exts.b  r13,r2                  ! r2 = 0
    bra     .s20_finalize
    mov.b   r2,@r4                  ! [update_mode] = 0 (delay slot)

    ! Mode 2: always update_mode = 0
.s20_pos_mode2:
    bra     .s20_finalize
    exts.b  r13,r2                  ! (writes 0 below)

.s20_mode_dispatch:
    cmp/eq  #0,r0
    bt      .s20_pos_mode0
    cmp/eq  #1,r0
    bt      .s20_pos_mode1
    cmp/eq  #2,r0
    bt      .s20_pos_mode2
    bra     .s20_finalize
    nop

.s20_mode2:
    mov     #2,r2
    mov.b   r2,@r4                  ! [update_mode] = 2

.s20_finalize:
    ! Clear car[0x40]
    mov     #64,r0                  ! r0 = 0x40
    mov.l   @r12,r3                 ! r3 = car_object
    mov.l   r13,@(r0,r3)           ! car[0x40] = 0

    ! Transition to state 21
    mov     #21,r3
    mov.l   @(PC),r2               ! r2 = 0x0605AD10 (&state_var)
    mov.l   r3,@r2                  ! state = 21

    ! Set timer = 86
    mov     #86,r3
    mov.l   @(PC),r2               ! r2 = 0x0607EBCC (&timer)
    mov.l   r3,@r2                  ! [timer] = 86 (~1.4 sec)

    ! Set difficulty = 4, phase = 4
    mov.l   @(PC),r2               ! r2 = 0x06078654 (&difficulty)
    mov.b   r10,@r2                 ! [difficulty] = 4

    mov.l   @(PC),r2               ! r2 = 0x0605A016 (&phase_flag)
    mov.w   r10,@r2                 ! [phase_flag] = 4

    ! Epilogue
    add     #4,r15
    lds.l   @r15+,pr
    mov.l   @r15+,r8
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ==========================================================================
! FUN_06009CFC — State 24: Post-Race Initialization
! ==========================================================================
! Single-frame setup for post-race sequence. Sets phase=3, performs
! cleanup, clears car speed, sets display flag, and transitions to state 25.
!
! Called from: main state dispatch (state index 24)
! Also entered from: state 17 (timer=0), state 19 (A+B+C with init flag)
! Transitions to: State 25 (always, same frame)

FUN_06009CFC:       ! 0x06009CFC
    sts.l   pr,@-r15

    ! Set phase = 3
    mov     #3,r3
    mov.l   @(0x78,PC),r2         ! r2 = 0x0605A016 (&phase_flag)
    mov.w   r3,@r2                  ! [phase_flag] = 3

    ! Cleanup calls
    mov.l   @(0x78,PC),r3         ! r3 = 0x06014A74
    jsr     @r3                     ! FUN_06014A74 — post-race cleanup A
    nop
    mov.l   @(0x78,PC),r3         ! r3 = 0x06019058
    jsr     @r3                     ! FUN_06019058 — post-race cleanup B
    nop

    ! Special input handler
    bsr     FUN_0600A1B8
    nop

    ! Transition to state 25
    mov     #25,r2
    mov.l   @(0x70,PC),r3         ! r3 = 0x0605AD10 (&state_var)
    mov.l   r2,@r3                  ! state = 25

    ! Set difficulty = 6
    mov     #6,r2
    mov.l   @(0x6C,PC),r3         ! r3 = 0x06078654 (&difficulty)
    mov.b   r2,@r3                  ! [difficulty] = 6

    ! Call additional setup
    mov.l   @(0x6C,PC),r3         ! r3 = 0x060032D4
    jsr     @r3                     ! FUN_060032D4
    nop
    mov.l   @(0x6C,PC),r3         ! r3 = 0x060210F6
    jsr     @r3                     ! FUN_060210F6
    nop

    ! Clear car speed
    mov.l   @(0x68,PC),r2         ! r2 = 0x0607E944 (&car_ptr)
    mov     #0,r3
    mov.l   @r2,r2                  ! r2 = car_object
    mov.l   r3,@(0x8,r2)           ! car[0x08] = 0 (speed = 0)

    ! Set display flag bit 30 (race display active)
    mov.l   @(0x64,PC),r4         ! r4 = 0x0605B6D8 (&display_flags)
    mov.l   @(0x68,PC),r2         ! r2 = 0x40000000
    mov.l   @r4,r3
    or      r2,r3
    mov.l   r3,@r4                  ! display_flags |= 0x40000000

    ! Display update
    mov.l   @(0x64,PC),r3         ! r3 = 0x06026CE0
    jsr     @r3                     ! FUN_06026CE0 — display update
    nop

    ! Clear results flag
    mov     #0,r2
    mov.l   @(0x60,PC),r3         ! r3 = 0x06059F44 (&results_flag)
    lds.l   @r15+,pr
    rts
    mov.l   r2,@r3                  ! [results_flag] = 0 (delay slot)


! ==========================================================================
! FUN_06009D4E — State 25: Post-Race Display Loop
! ==========================================================================
! Runs every frame after state 24 initialization. Displays the results
! screen until an external state change occurs (e.g., from state 29).
!
! Conditionally runs the display pipeline based on a flag byte at
! [0x06085F8A]. If flag is 0, runs full display; if non-zero, skips
! directly to frame sync.
!
! Called from: main state dispatch (state index 25)
! Transitions to: (none — stays in 25 until external change)
! Always tail-calls FUN_060078DC (frame timing/sync)

FUN_06009D4E:       ! 0x06009D4E
    sts.l   pr,@-r15

    ! Results screen processing
    mov.l   @(0x58,PC),r3         ! r3 = 0x06014D2C
    jsr     @r3                     ! FUN_06014D2C — results display logic
    nop

    ! Check display enable flag
    mov.l   @(0x58,PC),r2         ! r2 = 0x06085F8A (&display_enable)
    mov.b   @r2,r2
    tst     r2,r2
    bf      .s25_frame_sync         ! flag != 0: skip display, go to sync

    ! === Full display pipeline ===
    mov.l   @(0x54,PC),r3         ! r3 = 0x0600BB94
    jsr     @r3                     ! FUN_0600BB94 — update
    nop

    mov.l   @(0x50,PC),r6         ! r6 = 0x06063E24
    mov.l   @(0x54,PC),r5         ! r5 = 0x06063EEC
    mov.l   @(0x54,PC),r4         ! r4 = 0x06063EF8
    mov.l   @(0x58,PC),r3         ! r3 = 0x060053AC
    jsr     @r3                     ! FUN_060053AC — display commit
    mov.l   @r6,r6                  ! dereference r6 (delay slot)

    mov.l   @(0x54,PC),r3         ! r3 = 0x0600BFFC
    jsr     @r3                     ! FUN_0600BFFC
    nop

.s25_frame_sync:
    ! Tail call frame timing (unconditional — both paths end here)
    mov.l   @(0x54,PC),r3         ! r3 = 0x060078DC
    jmp     @r3                     ! tail call FUN_060078DC
    lds.l   @r15+,pr                ! restore pr (delay slot)


! ==========================================================================
! FUN_06009508 — State 28: Abort Processing
! ==========================================================================
! Handles the abort path after bit 0 of FLAGS_WORD is set (from state 17
! when mode_flag == 1). Simplified update pipeline — no per-car loop,
! no physics. Always transitions to state 29 (post-race menu).
!
! NOTE: If abort flag is STILL set on entry (re-entry case), clears it
! and writes state=20 — but this is immediately overwritten by state=29
! at .s28_main. The state=20 write is effectively dead code.
!
! Called from: main state dispatch (state index 28)
! Transitions to: State 29 (always)

FUN_06009508:       ! 0x06009508
    sts.l   pr,@-r15

    ! Check if abort flag is STILL set (re-entry case)
    mov.l   @(0x8C,PC),r4         ! r4 = 0x0607EBF4 (&flags_word)
    mov.l   @r4,r0
    tst     #0x01,r0                ! bit 0 still set?
    bt      .s28_no_abort

    ! Abort flag still active: clear it
    mov     #-2,r3                  ! mask 0xFFFFFFFE
    mov.l   @r4,r2
    and     r3,r2
    mov.l   r2,@r4                  ! clear bit 0
    mov     #20,r3                  ! (dead write — overwritten by state=29 below)
    mov.l   @(0x7C,PC),r2         ! r2 = 0x0605AD10 (&state_var)
    mov.l   r3,@r2                  ! state = 20 (immediately overwritten)
    bra     .s28_main
    nop

.s28_no_abort:
    ! Normal path: increment frame counter if race not ended
    mov.l   @(0x78,PC),r0         ! r0 = 0x0607EAD0 (&race_end_flag)
    mov.l   @r0,r0
    tst     r0,r0
    bf      .s28_main               ! race ended: skip counter
    mov.l   @(0x74,PC),r4         ! r4 = 0x0607EBD0 (&frame_counter)
    mov.l   @r4,r3
    add     #1,r3
    mov.l   r3,@r4                  ! frame_counter++

.s28_main:
    ! Transition to state 29
    mov     #29,r2
    mov.l   @(0x64,PC),r3         ! r3 = 0x0605AD10 (&state_var)
    mov.l   r2,@r3                  ! state = 29

    ! Simplified update pipeline (no per-car loop!)
    mov.l   @(0x6C,PC),r3         ! r3 = 0x0600DFD0
    jsr     @r3                     ! FUN_0600DFD0 — simplified car update
    nop
    mov.l   @(0x68,PC),r3         ! r3 = 0x0600BB94
    jsr     @r3                     ! FUN_0600BB94 — general update
    nop

    ! Display system
    mov.l   @(0x68,PC),r6         ! r6 = 0x06063E24
    mov.l   @(0x68,PC),r5         ! r5 = 0x06063EEC
    mov.l   @(0x6C,PC),r4         ! r4 = 0x06063EF8
    mov.l   @(0x6C,PC),r3         ! r3 = 0x060053AC
    jsr     @r3                     ! FUN_060053AC — display commit
    mov.l   @r6,r6                  ! dereference (delay slot)

    mov.l   @(0x6C,PC),r3         ! r3 = 0x0600C218
    jsr     @r3                     ! FUN_0600C218 — post-display
    nop

    ! Tail call frame sync
    mov.l   @(0x68,PC),r3         ! r3 = 0x060078DC
    jmp     @r3                     ! tail call FUN_060078DC
    lds.l   @r15+,pr                ! restore pr (delay slot)


! ==========================================================================
! FUN_0600955E — State 29: Post-Race Menu / Results Screen
! ==========================================================================
! The main post-race state. Runs every frame while the results screen is
! displayed. Complex state with multiple exit paths:
!
!   → State 18: Start button pressed (save resume=29, enter time extension)
!   → State 20: Abort flag set (clear flag, go to race completion)
!   → State 17: Mode flag [0x0605A1C4] == 0 (loop back to results processing)
!   → (stays in 29): Otherwise, continues display loop
!
! Runs a simplified update pipeline each frame:
!   FUN_0600E060 (car/object update), FUN_0600BB94, FUN_060053AC (display),
!   FUN_0600C218 (post-display), FUN_060078DC (frame sync)
!
! Also handles: sub-init check, debug display, overlay rendering,
! race result scoring (FUN_0600A084 if car_obj[+0x82] > 0)
!
! Called from: main state dispatch (state index 29)
! Also entered from: State 28 (always)

FUN_0600955E:       ! 0x0600955E
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    add     #-4,r15
    mov.l   @(0x34,PC),r14        ! r14 = 0x0605AD10 (&state_var)

    ! === Start button check ===
    mov.l   @(0x60,PC),r3         ! r3 = 0x06063D9A (&new_buttons)
    mov.w   @r3,r2
    extu.w  r2,r2
    mov.w   @(0x26,PC),r3         ! r3 = 0x0800 (start button mask)
    and     r3,r2
    tst     r2,r2
    bt      .s29_no_start

    ! Start pressed: save resume=29, enter time extension
    mov     #29,r3
    mov.l   @(0x54,PC),r2         ! r2 = 0x0607EACC (&resume_state)
    mov.l   r3,@r2                  ! resume_state = 29
    mov     #18,r3
    mov.l   r3,@r14                 ! state = 18 (time extension setup)

.s29_no_start:
    ! === Abort flag check ===
    mov.l   @(0x18,PC),r4         ! r4 = 0x0607EBF4 (&flags_word)
    mov.l   @r4,r0
    tst     #0x01,r0                ! bit 0 set?
    bt      .s29_no_abort

    ! Abort: clear flag, transition to state 20 (race completion)
    mov     #-2,r3                  ! mask 0xFFFFFFFE
    mov.l   @r4,r2
    and     r3,r2
    mov.l   r2,@r4                  ! [flags_word] &= ~1
    mov     #20,r3
    mov.l   r3,@r14                 ! state = 20
    bra     .s29_main
    nop

.s29_no_abort:
    ! No abort: check race end for frame counter
    mov.l   @(0xB0,PC),r0         ! r0 = 0x0607EAD0 (&race_end_flag)
    mov.l   @r0,r0
    tst     r0,r0
    bf      .s29_main               ! race ended: skip counter
    mov.l   @(0xAC,PC),r4         ! r4 = 0x0607EBD0 (&frame_counter)
    mov.l   @r4,r3
    add     #1,r3
    mov.l   r3,@r4                  ! frame_counter++

.s29_main:
    ! === Menu overlay check ===
    mov.l   @(0xA8,PC),r0         ! r0 = 0x0605AB18 (&menu_overlay)
    mov.b   @r0,r0
    tst     r0,r0
    bt      .s29_no_menu
    mov.l   @(0xA4,PC),r3         ! r3 = 0x060268B0
    jsr     @r3                     ! FUN_060268B0 — menu overlay
    mov     #0,r4
.s29_no_menu:

    ! === Update pipeline ===
    mov.l   @(0xA4,PC),r3         ! r3 = 0x0600E060
    jsr     @r3                     ! FUN_0600E060 — car/object update
    nop

    mov.l   @(0xA0,PC),r3         ! r3 = 0x0600BB94
    jsr     @r3                     ! FUN_0600BB94 — general update
    nop

    ! Display commit
    mov.l   @(0xA0,PC),r6         ! r6 = 0x06063E24
    mov.l   @(0xA0,PC),r5         ! r5 = 0x06063EEC
    mov.l   @(0xA4,PC),r4         ! r4 = 0x06063EF8
    mov.l   @(0xA4,PC),r3         ! r3 = 0x060053AC
    jsr     @r3                     ! FUN_060053AC — display commit
    mov.l   @r6,r6                  ! dereference (delay slot)

    mov.l   @(0xA4,PC),r3         ! r3 = 0x0600C218
    jsr     @r3                     ! FUN_0600C218 — post-display
    nop

    ! === Sub-init check ===
    mov.l   @(0xA0,PC),r0         ! r0 = 0x0607ED8C (&init_flag)
    mov.w   @r0,r0
    extu.w  r0,r0
    tst     r0,r0
    bt      .s29_no_subinit
    mov.l   @(0x9C,PC),r3         ! r3 = 0x060033E6
    jsr     @r3                     ! FUN_060033E6 — sub-init
    nop
.s29_no_subinit:

    ! === Debug display ===
    mov.l   @(0x98,PC),r0         ! r0 = 0x06086030 (&debug_flag)
    mov.b   @r0,r0
    extu.b  r0,r0
    tst     r0,r0
    bt      .s29_no_debug
    mov.l   @(0x94,PC),r7         ! r7 = 0x0605A1C8 (debug data)
    mov.l   @(0x94,PC),r6         ! r6 = 0x0000F000 (color white)
    mov.w   @(0x4E,PC),r5         ! r5 = position
    mov.l   @(0x94,PC),r3         ! r3 = 0x060283E0 (VDP text)
    jsr     @r3                     ! debug text display
    mov     #8,r4
.s29_no_debug:

    ! === Scoring check ===
    mov.l   @(0x94,PC),r2         ! r2 = 0x0607E944 (&car_ptr)
    mov.w   @(0x46,PC),r0         ! r0 = 0x0082
    mov.l   @r2,r2                  ! r2 = car_object
    mov.l   @(r0,r2),r3            ! r3 = car_obj[+0x82] (finish position)
    cmp/pl  r3                      ! position > 0?
    bf      .s29_no_score
    bsr     FUN_0600A084            ! process race result / scoring
    nop
.s29_no_score:

    ! === Frame sync ===
    mov.l   @(0x88,PC),r3         ! r3 = 0x060078DC
    jsr     @r3                     ! FUN_060078DC — frame timing/sync
    nop

    ! === Overlay rendering (after frame sync) ===
    mov.l   @(PC),r0               ! r0 = 0x0607E944
    mov.w   @(PC),r1               ! r1 = 0x00BC
    mov.l   @r0,r0                  ! r0 = car_object
    mov.l   @(r0,r1),r0            ! r0 = car_obj[+0xBC] (overlay flags)
    tst     #0xCC,r0                ! test bits 0xCC
    bf      .s29_check_mode         ! bits set: skip overlay rendering

    ! Overlay display from 0x06063798 area
    mov.l   @(PC),r3               ! r3 = 0x06063798 (&overlay_data)
    mov.l   r3,@r15                 ! save to stack
    mov     r3,r7
    mov     r3,r5
    mov.w   @(PC),r6               ! r6 = display params
    mov.l   @(0x4,r7),r7           ! r7 = overlay_data[1]
    mov.l   @r5,r5                  ! r5 = overlay_data[0]
    mov.l   @(0x70,PC),r3         ! r3 = 0x06028400
    jsr     @r3                     ! FUN_06028400 — overlay rendering
    mov     #4,r4

.s29_check_mode:
    ! === Mode flag: if 0, loop back to state 17 ===
    mov.l   @(0x6C,PC),r0         ! r0 = 0x0605A1C4 (&mode_flag)
    mov.l   @r0,r0
    tst     r0,r0
    bf      .s29_done               ! mode != 0: stay in state 29
    mov     #17,r3
    mov.l   r3,@r14                 ! state = 17 (loop back to results)

.s29_done:
    ! Epilogue
    add     #4,r15
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14               ! restore r14 (delay slot)
