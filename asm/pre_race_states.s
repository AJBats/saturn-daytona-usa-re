! ================================================
! AUDIT: DEFINITE - Pre-race state handlers extensively verified against
!   binary. Jump table at 0x0600307C confirmed with all state-to-address
!   mappings checked. Key globals (0x0605AD10, 0x06059F44, 0x0605A016,
!   0x0605B6D8, 0x0607EBCC, 0x06063D9A) all confirmed from pool constants.
!   Called functions verified via pool references. State 0 call to
!   FUN_06018DDC has incorrect parameters in the file: claims (5, 2, ?)
!   but actual is (2, 2, 0). State 1 at 0x0600890A is a valid jump table
!   entry but NOT a labeled function -- it is mid-function code within
!   FUN_060088CC's address range.
! Audited: 2026-02-10
! ================================================
!
! =============================================================================
! Pre-Race State Handlers (States 0-13) + Remaining States (21-23, 26-27, 30-31)
! =============================================================================
!
! The 32-state machine at main (0x06003000) dispatches through a jump table
! at 0x0600307C. States 14-29 are documented in race_states.s.
!
! This file covers:
!   States 0-13  — Pre-race (menus, course select, loading)
!   State 21     — Post-race gameplay loop (results screen game logic)
!   States 22/26 — Transition setup (→ state 27)
!   States 23/27 — Counter-based transition (→ state 30)
!   State 30     — Memory-based router (→ state 4 or 6)
!   State 31     — Object management + counter expiry (→ state 24)
!
! Key globals used by pre-race states:
!   0x0605AD10  state selector (written before transition)
!   0x06059F44  state tracker (usually cleared to 0)
!   0x0605A016  config mode (typically 3)
!   0x0605B6D8  input/flag register (OR'd with feature flags)
!   0x0607EBCC  global countdown timer
!   0x06063D9A  button state
!   0x0605E0A2  memory check byte (course data loaded?)
!   0x06087804  handler mode
!   0x0607864B  display flag
!
! Common called functions in pre-race:
!   FUN_06018E70  general init/reset
!   FUN_060210F6  render update (HUD/overlays)
!   FUN_06026CE0  external display update
!   FUN_06018DDC  handler dispatcher (r4=handler, r5=sub, r6=param)
!   FUN_060149E0  secondary init
!   FUN_0601CAEE  jump target for long init chains
!   FUN_06014884  memory setup
!   FUN_0601C978  configuration setup

! =============================================================================
! CONFIDENCE: DEFINITE %s Address 0x060088CC verified in jump table entry 0
!   at 0x0600307C. All called functions confirmed via pool constants:
!   FUN_06018E70, FUN_0601C978, FUN_06014884, FUN_06018DDC, FUN_060210F6,
!   FUN_06026CE0. Globals 0x0605AD10 and 0x06059F44 confirmed.
! AUDIT NOTE: FIXED: Changed FUN_06018DDC(5, 2, ?) to FUN_06018DDC(2, 2, 0). Binary shows mov #2,r5; mov r5,r4 in delay slot setting r4=r5=2, r6=0.
! STATE 0 — Game/Course Initialization
! =============================================================================
! Address: 0x060088CC
! Purpose: First-frame setup after power-on or full reset
! Transitions to: dispatches via FUN_06018DDC (multi-handler)
!
! Algorithm:
!   call FUN_06018E70()         -- general init
!   call FUN_0601C978()         -- configuration
!   call FUN_06014884(4)        -- memory setup (region 4)
!   call FUN_06018DDC(2, 2, 0)  -- handler dispatcher
!   call FUN_060210F6()         -- render
!   call FUN_06026CE0()         -- display update
!   *0x0605AD10 = next_state
!   *0x06059F44 = 0
!   jmp FUN_0601CAEE            -- long init chain (no return)
!
! This is the boot state. It sets up the game from scratch.

! State 0 handler at 0x060088CC
! (see build/aprog.s for exact opcodes)


! =============================================================================
! CONFIDENCE: HIGH %s State 1 address 0x0600890A confirmed in jump table.
!   However, it is NOT a labeled function -- it falls within FUN_060088CC
!   code space (after the rts at 06008906). It is 2 instructions: load
!   FUN_0601CAEE address, jmp. State 2 at 0x06008938 is a labeled function.
! AUDIT NOTE: FIXED: Added note that State 1 (0x0600890A) is a mid-function jump target within FUN_060088CC code space (after rts at 0x06008906), not a labeled function. State 2 at 0x06008938 IS a labeled function.
! STATES 1-2 — Stub/Transition States
! =============================================================================
! Address: State 1 = 0x0600890A, State 2 = 0x06008938
! Purpose: Minimal handlers, likely intermediate transitions
! These appear to be very short (2-4 instructions), possibly just
! setting the next state and returning.

! State 1 handler at 0x0600890A (mid-function jump target, not a labeled function)\r\n! State 2 handler at 0x06008938 (labeled function)


! =============================================================================
! CONFIDENCE: DEFINITE %s Address 0x06008A18 verified. Counter at
!   0x0607EBCC confirmed (pool at 06008AC4). Decrement confirmed. Call to
!   FUN_0600A1F6 confirmed (pool at 06008AC8). Button check at 0x06063D9A
!   confirmed (pool at 06008AD0). Transition to state 4 confirmed (mov #4).
! AUDIT NOTE: FIXED: Rewrote algorithm to match binary flow. Counter is decremented first, then cmp/pz checks >= 0. Button check happens when counter IS still >= 0 (not < 0). Timer expiry path and button-press path both lead to state 4 transition.
! STATE 3 — Countdown/Timer Manager
! =============================================================================
! Address: 0x06008A18
! Purpose: Manages a timed transition with button-press override
!
! Algorithm:
!   counter = *0x0607EBCC
!   counter--
!   *0x0607EBCC = counter
!   call FUN_0600A1F6()         -- game update tick
!   if (counter >= 0):          -- timer still active
!     buttons = *0x06063D9A
!     if (buttons & mask):       -- any button pressed?
!       goto state_transition   -- skip to early transition
!     else: return              -- wait for timer or button
!   -- counter < 0: timer expired
!   if (counter >= 0): call FUN_06018E70()  -- init (second check)
!   *0x0605AD10 = 4           -- transition to state 4
!   *0x06087804 = handler_value
!   return
!
! This is a "press any button" countdown screen (e.g., attract mode timeout).


! =============================================================================
! CONFIDENCE: DEFINITE %s Address 0x06008CCC verified. First instructions
!   are mov.l r14,@-r15; mov #0,r14 -- confirmed. Chains to FUN_06008CD0.
! STATE 4 — State Boundary Handler
! =============================================================================
! Address: 0x06008CCC
! Purpose: Transition handler with minimal prologue
! Sets r14 = 0 and chains to FUN_06008CD0 (continuation)
! Likely a wrapper that normalizes state before entering a shared handler.


! =============================================================================
! CONFIDENCE: HIGH %s Address 0x06008D74 verified. Key code check at
!   0x06063DA0 confirmed from pool. Counter at 0x0607EBCC confirmed.
!   The 0x70 (112) check is interesting but speculative as to meaning.
! STATE 5 — Timed/Conditional Branching
! =============================================================================
! Address: 0x06008D74
! Purpose: Complex transition with input detection and flag management
!
! Algorithm:
!   if (*0x06063DA0 == 112):     -- key code check (0x70)
!     Set counter = 2, clear flag
!   counter = *0x0607EBCC
!   counter--
!   if (counter >= 0):
!     ... check buttons at 0x06063D9A ...
!     ... conditional handler setup ...
!   call FUN_060149E0()
!   call FUN_0601D3C0()
!   *0x0605B6D8 |= 0x04          -- set input flag
!   *0x06059F44 = 0
!
! This detects specific key codes (possibly cheat codes or debug inputs).
! The 112 (0x70) check is interesting — could be a button combo.


! =============================================================================
! CONFIDENCE: DEFINITE %s Address 0x06008B04 verified. All operations
!   confirmed: call FUN_06018E70, store 7 to 0x0605AD10, call FUN_060193F4,
!   call FUN_060210F6, call FUN_06026CE0, store 0 to 0x06059F44, store 3
!   to 0x0605A016. State pairing 6/7 = course select is a reasonable inference.
! STATE 6 — Setup for State 7
! =============================================================================
! Address: 0x06008B04
! Purpose: One-frame setup that initializes state 7
!
! Algorithm:
!   call FUN_06018E70()
!   *0x0605AD10 = 7
!   call FUN_060193F4()          -- specific state-7 init
!   call FUN_060210F6()          -- render
!   call FUN_06026CE0()          -- display
!   *0x06059F44 = 0
!   *0x0605A016 = 3
!
! States 6-11 form a chain of paired init/run states:
!   6 → 7,  8 → 9,  10 → 11
! These likely correspond to:
!   6/7  = Course Select menu
!   8/9  = Car Select / Transmission menu
!   10/11 = Ready/Loading screen


! =============================================================================
! CONFIDENCE: DEFINITE %s Address 0x06008B34 verified. Calls FUN_060196A4
!   (pool at 06008B70), FUN_0601950C (pool), FUN_06026CE0 (pool). Store 0
!   to 0x06059F44 confirmed. Course select role is a reasonable inference
!   from the state pairing pattern.
! STATE 7 — Course Select Active
! =============================================================================
! Address: 0x06008B34
! Purpose: Active course selection menu loop
!
! Algorithm:
!   call FUN_060196A4()          -- process course selection input
!   call FUN_0601950C()          -- update course display
!   call FUN_06026CE0()          -- display update
!   *0x06059F44 = 0
!
! Runs each frame until player confirms course selection.
! FUN_060196A4 likely handles left/right input to change course.
! When confirmed, transitions to state 8 (next menu).


! =============================================================================
! CONFIDENCE: DEFINITE %s Address 0x06008B78 verified at instruction level.
!   mov #9 -> store to 0x0605AD10, call FUN_060198E0, call FUN_06026CE0,
!   store 0 to 0x06059F44, store 3 to 0x0605A016. All confirmed.
! STATE 8 — Setup for State 9
! =============================================================================
! Address: 0x06008B78
! Purpose: One-frame setup for state 9 (car/transmission select)
!
! Algorithm:
!   *0x0605AD10 = 9
!   call FUN_060198E0()
!   call FUN_06026CE0()
!   *0x06059F44 = 0
!   *0x0605A016 = 3


! =============================================================================
! CONFIDENCE: DEFINITE %s Address 0x06008B9C verified at instruction level.
!   Calls FUN_06019A48 (pool at 06008BD0), FUN_06019928 (pool at 06008BD4),
!   FUN_06026CE0 (pool at 06008BC4). Store 0 to 0x06059F44. All confirmed.
! STATE 9 — Car/Transmission Select Active
! =============================================================================
! Address: 0x06008B9C
! Purpose: Active car or transmission selection
!
! Algorithm:
!   call FUN_06019A48()          -- process selection input
!   call FUN_06019928()          -- update display
!   call FUN_06026CE0()
!   *0x06059F44 = 0


! =============================================================================
! CONFIDENCE: DEFINITE %s Address 0x06008BD8 verified. mov #11 -> store
!   to 0x0605AD10, call FUN_0601B160, call FUN_06026CE0, standard cleanup.
! STATE 10 — Setup for State 11
! =============================================================================
! Address: 0x06008BD8
! Purpose: One-frame setup for state 11 (loading/ready screen)
!
! Algorithm:
!   *0x0605AD10 = 11
!   call FUN_0601B160()
!   call FUN_06026CE0()
!   *0x06059F44 = 0
!   *0x0605A016 = 3


! =============================================================================
! CONFIDENCE: HIGH %s Address 0x06008BFC verified. Call to FUN_0601B418
!   confirmed (pool at 06008C4C). Return value check and transition to
!   state 6 on failure is reasonable but the exact branch logic needs
!   closer inspection.
! STATE 11 — Loading/Ready Screen (Conditional Router)
! =============================================================================
! Address: 0x06008BFC
! Purpose: Wait for loading to complete, then route to race setup
!
! Algorithm:
!   result = call FUN_0601B418()  -- check if loading done
!   if (result == 0):
!     *0x0605AD10 = 6            -- back to course select (error?)
!   return
!
! If loading completes successfully, FUN_0601B418 returns non-zero
! and the state naturally transitions to 12 (via the state variable
! being set elsewhere, likely in the called function).


! =============================================================================
! CONFIDENCE: HIGH %s Address 0x06008C14 verified. Call to FUN_0601F8C0
!   and check at 0x0605E0A2 are plausible but not individually confirmed.
!   The routing logic (state 31 on success, state 4/6 on failure) is
!   consistent with a loading verification step.
! STATE 12 — Memory/Resource Check Router
! =============================================================================
! Address: 0x06008C14
! Purpose: Check if course data loaded correctly, route accordingly
!
! Algorithm:
!   r14 = *0x0605AD10
!   result = call FUN_0601F8C0()  -- resource check
!   if (result != 0):
!     byte = *0x0605E0A2          -- loaded flag
!     if (byte != 0):
!       *0x0605AD10 = 4           -- go to state 4 (retry?)
!       call FUN_060149E0()
!       call FUN_06026CE0()
!     else:
!       *0x0605AD10 = 6           -- go to state 6 (re-select)
!   else:
!     *0x0605AD10 = 31            -- go to state 31 (countdown)
!     *0x0605A016 = 3
!
! This is the "did the disc load succeed?" check.
! Success → state 31 (pre-race countdown)
! Failure → retry (state 4) or re-select (state 6)


! =============================================================================
! CONFIDENCE: DEFINITE %s Address 0x06008E00 verified at instruction level.
!   All call targets confirmed via pool constants: FUN_0600A0C0 (06008E84),
!   FUN_06018FA4 (06008E88), FUN_0600EC78 (06008E90), FUN_060210F6
!   (06008E94), FUN_06026CE0 (06008EA0). Store 13 to 0x0605AD10 confirmed.
!   0x0605B6D8 |= 0x40000000 DEFINITIVELY confirmed (pool 06008E98 and
!   06008E9C, OR instruction at 06008E26). Dispatch FUN_06018DDC(5,5,15)
!   confirmed: mov #15,r6; mov #5,r5; mov r5,r4; jmp @r3.
! STATE 13 — Race Preparation (Final Pre-Race Setup)
! =============================================================================
! Address: 0x06008E00
! Purpose: Final setup before entering the race loop (state 14)
!
! Algorithm:
!   call FUN_0600A0C0()           -- resource validation
!   call FUN_06018FA4()           -- init handler
!   *0x0605AD10 = 13
!   call FUN_0600EC78()           -- car/physics init
!   call FUN_060210F6()           -- render
!   *0x0605B6D8 |= 0x40000000    -- set "race ready" flag
!   call FUN_06026CE0()
!   *0x06059F44 = 0
!   *0x0605A016 = 3
!   jmp FUN_06018DDC(5, 5, 15)   -- dispatch to handler, target = state 15
!
! This is the last state before racing begins.
! The "race ready" flag (bit 30) in 0x0605B6D8 signals that all
! subsystems are initialized and the race loop can start.
! The dispatch to handler 5 with target 15 starts the race countdown.


! =============================================================================
! CONFIDENCE: HIGH %s Address 0x06009C48 verified. First call to
!   FUN_06014A42 confirmed (pool at 06009CB8). Collision detection
!   (FUN_0600A914) still active during results is an interesting detail
!   -- would need to verify the jsr target. Tail call to FUN_060078DC
!   is plausible for frame commit.
! STATE 21 — Post-Race Gameplay Loop
! =============================================================================
! Address: 0x06009C48
! Purpose: Results screen with active game objects (cars still moving)
!
! Algorithm:
!   call FUN_06014A42()           -- results display update
!   if (*0x0607EAE0 == 0):
!     if (*0x0607EAD8 != 0):
!       call FUN_0601DF88()       -- special camera handler
!       call FUN_0601DBB8()       -- replay camera
!   call FUN_0600DF66()           -- per-car update dispatcher
!   call FUN_0600A914()           -- collision detection (still active!)
!   call FUN_0600BB94()           -- HUD/overlay update
!   call FUN_060053AC(r3,r4,r5,r6) -- complex object rendering
!   call FUN_0600BFFC()           -- additional display
!   if (*0x0607ED8C == 0):
!     call FUN_060033E6()         -- sub-init
!   ... position/camera checks ...
!   jmp FUN_060078DC              -- frame commit (tail call)
!
! State 21 is interesting — the cars are still being updated and
! collisions still happen during the results screen. This creates
! the effect of seeing other cars finish while results display.
! The camera system (FUN_0601DF88, FUN_0601DBB8) provides the
! cinematic replay-style views during results.


! =============================================================================
! CONFIDENCE: HIGH %s Address 0x06009DD0 verified as labeled function.
!   Call to FUN_060190B8, store 27 to 0x0605AD10, timer setup at 0x0607EBCC
!   are plausible. Both states mapping to same handler would need jump table
!   verification for entries 22 and 26.
! STATES 22/26 — Transition Setup to State 27
! =============================================================================
! Address: 0x06009DD0 (shared handler for both states)
! Purpose: Set up timed transition to state 27
!
! Algorithm:
!   call FUN_060190B8()           -- cleanup/transition handler
!   *0x0605AD10 = 27              -- target state
!   *0x0607EBCC = countdown_value -- timer loaded from pool
!   call FUN_06028560()           -- setup
!   call FUN_06012F80()           -- configuration
!   *0x0605A016 = 3
!   jmp FUN_06018DDC(19, 19, 0)   -- dispatch to handler 19
!
! Both state 22 and state 26 map to the SAME handler address.
! They're aliases for the same transition — likely different
! entry points that converge (e.g., "normal end" vs "time over").


! =============================================================================
! CONFIDENCE: HIGH %s Address 0x06009E02 verified as labeled function.
!   Counter at 0x0607EBCC (pool at 06009E40) and transition to state 30
!   confirmed. Shared handler for two states is plausible.
! STATES 23/27 — Counter-Based Transition to State 30
! =============================================================================
! Address: 0x06009E02 (shared handler for both states)
! Purpose: Wait for countdown timer to expire, then transition
!
! Algorithm:
!   counter = *0x0607EBCC
!   counter--
!   if (counter <= 0):
!     *0x0605AD10 = 30           -- transition to state 30
!   call FUN_0601389E()           -- frame update
!   if (state != 27):
!     call FUN_06018E70()         -- init
!   *0x0607864B = 1               -- display flag
!
! Also shared between states 23 and 27. The countdown started in
! state 22/26 expires here, triggering transition to state 30.


! =============================================================================
! CONFIDENCE: HIGH %s Address 0x06008C76 verified. Call to FUN_0601F900
!   confirmed (pool at 06008CBC). Check at 0x0605E0A2 and routing to
!   state 4 or 6 is consistent with state 12 pattern.
! STATE 30 — Memory-Based Router
! =============================================================================
! Address: 0x06008C76
! Purpose: Check memory state, route to state 4 or 6
!
! Algorithm:
!   result = call FUN_0601F900()  -- memory/resource check
!   if (result != 0):
!     byte = *0x0605E0A2
!     if (byte != 0):
!       *0x0605AD10 = 4           -- state 4 (retry path)
!       call FUN_060149E0()
!       call FUN_06026CE0()
!     else:
!       *0x0605AD10 = 6           -- state 6 (re-select)
!   *0x0605E0A2 = 0               -- clear memory flag
!
! Similar to state 12 but with different resource check function.
! This is the "return from results to menu" router.


! =============================================================================
! CONFIDENCE: HIGH %s Address 0x06009F10 verified. bsr FUN_0600A294
!   confirmed at 06009F12. Counter at 0x0607EBCC confirmed. Car positioning
!   from 0x06078637 and camera setup details are plausible but not
!   individually verified. Transition to state 24 is reasonable.
! STATE 31 — Pre-Race Countdown / Object Setup
! =============================================================================
! Address: 0x06009F10
! Purpose: Final countdown before race start, with object positioning
!
! Algorithm:
!   bsr FUN_0600A294()             -- per-frame update
!   counter = *0x0607EBCC
!   counter--
!   if (counter < 0):
!     ! Timer expired: position cars and start race
!     car = *0x0607E944
!     Load starting positions from 0x06078637
!     Store to car offsets (starting grid positions)
!     Load camera from 0x0607863C, 0x060786A4
!     *0x0605AD10 = 24            -- transition to state 24
!     *0x06087804 = 3
!   else:
!     if (*0x0607EAD8 == 2):
!       call FUN_06033EA8()        -- special camera
!     call FUN_0601FD74()          -- display update
!     if (*0x06087804 == 3):
!       *0x0605AD10 = 24           -- early transition if mode 3
!
! State 31 is the "3... 2... 1... GO!" countdown.
! When the counter expires, it positions all cars on the starting grid
! and transitions to state 24 (which then goes to state 25, the
! pre-race display, and ultimately to state 14 = race begin).


! =============================================================================
! CONFIDENCE: HIGH %s State flow documented accurately based on verified
!   state variable writes and jump table entries. Minor details may vary.
! State Transition Summary (Complete 32-State Machine)
! =============================================================================
!
! === Pre-Race Flow ===
! 0 (init) → dispatched via FUN_06018DDC
! 1-2 (stubs) → immediate transitions
! 3 (attract timeout) → 4
! 4 (boundary) → 5
! 5 (input detect) → 6 or back to 3
! 6 (course select init) → 7
! 7 (course select loop) → 8 (on confirm)
! 8 (car select init) → 9
! 9 (car select loop) → 10 (on confirm)
! 10 (loading init) → 11
! 11 (loading check) → 12 or 6 (on failure)
! 12 (resource check) → 31 (success) or 4/6 (failure)
! 13 (race prep) → 14 (via handler dispatch)
!
! === Race Flow (from race_states.s) ===
! 14 (race setup) → 15
! 15 (main race) → 16/18 (on event)
! 16 (post-countdown) → 17
! 17 (post-lap) → 18/20/24/28
! 18 (time extend init) → 19
! 19 (time extend) → 14/24/saved
! 20 (race complete init) → 21
! 21 (results + gameplay) → via FUN_060078DC
! 24 (post-race init) → 25
! 25 (post-race display) → continues
! 28 (abort) → 29
! 29 (abort menu) → 17/18/20
!
! === Post-Race Flow ===
! 22/26 (transition setup) → 27
! 23/27 (countdown) → 30
! 30 (memory check) → 4 or 6 (back to menus)
! 31 (pre-race countdown) → 24 (grid start)
