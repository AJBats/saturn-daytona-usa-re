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
!   call FUN_06018DDC(5, 2, ?)  -- handler dispatcher
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
! STATES 1-2 — Stub/Transition States
! =============================================================================
! Address: State 1 = 0x0600890A, State 2 = 0x06008938
! Purpose: Minimal handlers, likely intermediate transitions
! These appear to be very short (2-4 instructions), possibly just
! setting the next state and returning.

! State 1 handler at 0x0600890A
! State 2 handler at 0x06008938


! =============================================================================
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
!   if (counter < 0):
!     buttons = *0x06063D9A
!     if (buttons & mask):       -- any button pressed?
!       call FUN_06018E70()     -- init
!       ... setup next state ...
!     *0x0605AD10 = 4           -- transition to state 4
!     *0x06087804 = handler_value
!   return
!
! This is a "press any button" countdown screen (e.g., attract mode timeout).


! =============================================================================
! STATE 4 — State Boundary Handler
! =============================================================================
! Address: 0x06008CCC
! Purpose: Transition handler with minimal prologue
! Sets r14 = 0 and chains to FUN_06008CD0 (continuation)
! Likely a wrapper that normalizes state before entering a shared handler.


! =============================================================================
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
