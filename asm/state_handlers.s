! =============================================================================
! Complete 32-State Machine Handler Catalog
! =============================================================================
!
! Main loop at 0x06003000 dispatches through jump table at 0x0600307C.
! State variable at 0x0605AD10. Each state handler is called once per frame.
!
! This file documents ALL 32 state handlers. States 14-20, 24-25, 28-29
! are also documented in detail in asm/race_states.s.
!
! States 6-12, 31 are also documented in asm/pre_race_states.s.

! =============================================================================
! STATE OVERVIEW TABLE
! =============================================================================
!
! | State | Address    | Size  | Purpose |
! |-------|------------|-------|---------|
! | 0     | 0x060088CC | ~62   | Game/course init |
! | 1     | 0x0600890A | ~22   | Transition stub |
! | 2     | 0x06008938 | ~22   | Transition stub |
! | 3     | 0x06008A18 | ~114  | Attract mode / title timeout |
! | 4     | 0x06008CCC | ~52   | State boundary normalizer |
! | 5     | 0x06008D74 | ~62   | Timed/conditional branching |
! | 6     | 0x06008B04 | ~24   | Course select init |
! | 7     | 0x06008B34 | ~34   | Course select active |
! | 8     | 0x06008B78 | ~18   | Car select init |
! | 9     | 0x06008B9C | ~30   | Car select active |
! | 10    | 0x06008BD8 | ~18   | Loading init |
! | 11    | 0x06008BFC | ~14   | Loading check |
! | 12    | 0x06008C14 | ~48   | Resource check router |
! | 13    | 0x06008E00 | ~36   | Race preparation |
! | **14** | 0x06008EBC | 188  | **Race first-frame setup** |
! | **15** | 0x06009098 | 202  | **MAIN RACE LOOP** |
! | 16    | 0x06009290 | ~32   | Post-countdown cleanup |
! | **17** | 0x060092D0 | 228  | **Post-lap results** |
! | 18    | 0x060096DC | ~86   | Time extension setup |
! | **19** | 0x06009788 | 298  | **Time extension active** |
! | **20** | 0x06009A60 | ~195  | **Race completion init** |
! | 21    | 0x06009C48 | ~74   | Post-race with active cars |
! | 22    | 0x06009DD0 | ~24   | Post-race transition setup |
! | 23    | 0x06009E02 | ~26   | Counter transition |
! | **24** | 0x06009CFC | ~40   | **Post-race display init** |
! | **25** | 0x06009D4E | ~56   | **Post-race display loop** |
! | 26    | 0x06009DD0 | -     | Alias of state 22 |
! | 27    | 0x06009E02 | -     | Alias of state 23 |
! | **28** | 0x06009508 | ~42   | **Abort processing** |
! | **29** | 0x0600955E | ~140  | **Abort menu** |
! | 30    | 0x06008C76 | ~48   | Memory router |
! | 31    | 0x06009F10 | ~100  | Pre-race countdown (3-2-1-GO) |


! =============================================================================
! STARTUP & ATTRACT (States 0-5)
! =============================================================================

! STATE 0: FUN_060088CC — Game/Course Initialization (~62 insns)
!   Power-on setup. Calls init chain.
!   Tail-calls FUN_0601CAEE (rendering init).
!   Only runs once at startup.

! STATE 1: FUN_0600890A — Transition Stub (~22 insns)
!   Minimal handler. Sets next state and returns.
!   2-4 instructions of actual logic.

! STATE 2: FUN_06008938 — Transition Stub (~22 insns)
!   Similar to state 1. Simple transition.

! STATE 3: FUN_06008A18 — Attract Mode Timeout (~114 insns)
!   Countdown/timer manager for title screen.
!   Decrements counter each frame.
!   Transitions to state 4 on timeout.
!   Button press overrides timer for immediate transition.
!   Controls attract mode demo sequence.

! STATE 4: FUN_06008CCC — State Boundary Handler (~52 insns)
!   Normalizer wrapper.
!   Sets r14=0 (reset flag).
!   Jumps to continuation handler.
!   Entry point after attract mode or menu return.

! STATE 5: FUN_06008D74 — Input Detection Router (~62 insns)
!   Timed/conditional branching.
!   Checks key code 0x70 (Start button).
!   Manages timed transitions to:
!     state 3 (back to attract)
!     state 4 (boundary handler)
!     state 6 (course select)
!   Calls FUN_06018E70 (general init).


! =============================================================================
! MENU FLOW (States 6-12)
! =============================================================================
!
! Linear menu progression: Course Select -> Car Select -> Loading -> Race

! STATE 6: FUN_06008B04 — Course Select Init (~24 insns)
!   One-frame setup.
!   Calls FUN_060193F4 (course select initialization).
!   Transitions immediately to state 7.

! STATE 7: FUN_06008B34 — Course Select Active (~34 insns)
!   Menu loop. Runs every frame until player confirms.
!   FUN_060196A4 — processes controller input (course navigation)
!   FUN_0601950C — renders course select display
!   Transitions to state 8 on confirm (Start).

! STATE 8: FUN_06008B78 — Car Select Init (~18 insns)
!   One-frame setup.
!   Calls FUN_060198E0 (car select initialization).
!   Transitions immediately to state 9.

! STATE 9: FUN_06008B9C — Car Select Active (~30 insns)
!   Menu loop. Runs every frame.
!   FUN_06019A48 — processes controller input (car navigation)
!   FUN_06019928 — renders car select display
!   Transitions to state 10 on confirm.

! STATE 10: FUN_06008BD8 — Loading Init (~18 insns)
!   One-frame setup.
!   Calls FUN_0601B160 (initiates course data loading from disc).
!   Transitions immediately to state 11.

! STATE 11: FUN_06008BFC — Loading Check (~14 insns)
!   Polls loading status each frame.
!   Calls FUN_0601B418 (check disc load completion).
!   Routes to:
!     state 6 (error -> re-select course)
!     state 12 (success -> resource check)

! STATE 12: FUN_06008C14 — Resource Check Router (~48 insns)
!   Calls FUN_0601F8C0 (resource availability check).
!   Checks 0x0605E0A2 (resource status flag).
!   Routes to:
!     state 4 (retry -> back to boundary)
!     state 6 (re-select -> course select)
!     state 31 (success -> pre-race countdown)


! =============================================================================
! PRE-RACE (States 13, 31)
! =============================================================================

! STATE 13: FUN_06008E00 — Race Preparation (~36 insns)
!   Final pre-race setup.
!   Calls:
!     FUN_0600A0C0 — resource validation
!     FUN_0600EC78 — car/physics initialization
!   Sets race_ready flag: 0x0605B6D8 |= 0x40000000
!   Dispatches FUN_06018DDC(5, 5, 15) for transition to state 14.

! STATE 31: FUN_06009F10 — Pre-Race Countdown (~100 insns)
!   "3...2...1...GO!" countdown.
!   Decrements counter each frame.
!   On expire:
!     - Positions cars on starting grid
!     - Loads initial camera
!     - Transitions to state 14 (first race frame)


! =============================================================================
! ACTIVE RACING (States 14-17)
! =============================================================================
!
! *** CORE GAMEPLAY - See asm/race_states.s for detailed analysis ***

! STATE 14: FUN_06008EBC — Race First-Frame Setup (188 insns)
!   One-frame initialization.
!   Button event mapping.
!   Runs race pipeline once (warm-up).
!   Transitions to state 15.

! STATE 15: FUN_06009098 — MAIN RACE LOOP (202 insns)
!   *** THE CORE GAMEPLAY STATE ***
!   Called every frame during active racing.
!   Per-car loop calling:
!     FUN_0600DE54 — physics engine (per car)
!     FUN_0602EFF0 — camera/rendering (per car)
!     FUN_0602F0E8 — track position (per car)
!     FUN_060302C6 — sound update (per car)
!     FUN_0600A914 — collision detection
!     FUN_060053AC — display commit
!   Tail-calls FUN_060078DC (frame sync).
!   Decrements race timer at 0x0607EAAC.
!   Transitions to:
!     state 16 (countdown expired)
!     state 18 (Start pressed)

! STATE 16: FUN_06009290 — Post-Countdown Cleanup (~32 insns)
!   One-frame cleanup after countdown expires.
!   Calls FUN_060121A8 or FUN_06012198 (car cleanup).
!   Sets phase_flag = 4.
!   Transitions to state 17.

! STATE 17: FUN_060092D0 — Post-Lap Results Display (228 insns)
!   Complex multi-path state.
!   Processes countdown timer.
!   Reads finish position from car_obj[+0x82].
!   Checks abort flag, mode flags.
!   Transitions to:
!     state 18 (Start -> time extension)
!     state 20 (abort)
!     state 24 (countdown expired)
!     state 28 (mode=1)
!     loops in state 17 (otherwise)


! =============================================================================
! TIME EXTENSION (States 18-19)
! =============================================================================

! STATE 18: FUN_060096DC — Time Extension Setup (~86 insns)
!   One-frame UI initialization.
!   Saves current difficulty level.
!   Displays "TIME EXTENSION" overlay.
!   Saves resume_state to 0x0607EACC.
!   Tail-calls FUN_0601D5F4 (play sound effect).
!   Transitions to state 19.

! STATE 19: FUN_06009788 — Time Extension Active (298 insns)
!   Complex input loop.
!   Speed selection with up/down buttons (range 1-99).
!   Debounce timer: 20 frames between button repeats.
!   Start button confirms: returns to saved_state (15 or 17).
!   Secret input: A+B+C (0x0070) -> state 24 or state 14.
!   Button addresses:
!     0x06063D9A = new button presses (edge-triggered)
!     0x06063D98 = held buttons
!   Button masks:
!     0x0800 = Start
!     0x8000 = Up
!     0x4000 = Down
!     0x0070 = A+B+C (secret combo)


! =============================================================================
! RACE COMPLETION (States 20-25)
! =============================================================================

! STATE 20: FUN_06009A60 — Race Completion Init (~195 insns)
!   Calls FUN_06014A04 (final calculations).
!   Reads car_obj[+0x82] -> race_result (finish position).
!   Complex flag dispatch based on player_mode and conditions.
!   Sets difficulty = 4, timer = 86.
!   Transitions to state 21.

! STATE 21: FUN_06009C48 — Post-Race Gameplay Loop (~74 insns)
!   *** Cars still move and collide during results ***
!   Not a static screen.
!   Calls:
!     FUN_0600DF66 — car update (physics still running!)
!     FUN_0600A914 — collision still active!
!     FUN_060053AC — display commit
!   Tail-calls FUN_060078DC (frame sync).

! STATE 22: FUN_06009DD0 — Post-Race Transition Setup (~24 insns)
!   Shared with state 26 (same handler).
!   Calls FUN_060190B8.
!   Sets state = 27.
!   Loads countdown from pool constant.
!   Calls FUN_06028560.
!   Dispatches FUN_06018DDC(19, 19, 0).

! STATE 23: FUN_06009E02 — Counter Transition (~26 insns)
!   Shared with state 27 (same handler).
!   Decrements countdown.
!   If countdown <= 0: state = 30.
!   Calls FUN_0601389E.
!   Conditional FUN_06018E70.

! STATE 24: FUN_06009CFC — Post-Race Display Init (~40 insns)
!   One-frame setup.
!   Sets phase = 3.
!   Cleanup calls.
!   state = 25, difficulty = 6.
!   Clears car.speed = 0.
!   Sets display_flag bit 30.

! STATE 25: FUN_06009D4E — Post-Race Display Loop (~56 insns)
!   Results display every frame.
!   Checks display_enable at 0x06085F8A.
!   Conditionally runs:
!     FUN_0600BB94 — camera/HUD overlay
!     FUN_060053AC — display commit
!   Tail-calls FUN_060078DC (frame sync).


! =============================================================================
! ABORT / SPECIAL STATES (States 26-30)
! =============================================================================

! STATE 26: (Alias of state 22) — Same handler at 0x06009DD0
! STATE 27: (Alias of state 23) — Same handler at 0x06009E02

! STATE 28: FUN_06009508 — Abort Processing (~42 insns)
!   Checks abort flag at 0x0607EBF4 bit 0.
!   Simplified update pipeline (NO per-car physics loop).
!   Transitions to state 29.
!   Tail-calls FUN_060078DC.

! STATE 29: FUN_0600955E — Abort Menu (~140 insns)
!   Menu loop during abort sequence.
!   Similar update pipeline to state 28.
!   Handles button input for menu selection.
!   Transitions to:
!     state 17 (continue racing)
!     state 18 (time extension)
!     state 20 (finish race)

! STATE 30: FUN_06008C76 — Memory Router (~48 insns)
!   Calls FUN_0601F900 (memory check).
!   Checks memory_flag at 0x0605E0A2.
!   Routes to:
!     state 4 (retry)
!     state 6 (re-select course)


! =============================================================================
! STATE TRANSITION GRAPH
! =============================================================================
!
!   [0] Init
!    |
!    v
!   [1] -> [2] -> [3] Attract/Title (timeout loop)
!                   |
!                   v (button press or timeout)
!   [4] Boundary -> [5] Input Router
!                       |
!                       v (Start)
!   [6] Course Init -> [7] Course Select (loop)
!                           |
!                           v (confirm)
!   [8] Car Init -> [9] Car Select (loop)
!                       |
!                       v (confirm)
!   [10] Load Init -> [11] Load Check
!                       |
!                       +-> [6] (error)
!                       v (success)
!   [12] Resource Check
!        |
!        +-> [4] (retry)
!        +-> [6] (re-select)
!        v (success)
!   [31] Countdown (3-2-1-GO!)
!        |
!        v
!   [13] Race Prep -> [14] First Frame
!                          |
!                          v
!   *** [15] MAIN RACE LOOP *** <---------+
!        |                                  |
!        +-> [16] -> [17] Post-Lap --------+
!        |              |                   |
!        +-> [18] -> [19] Time Extension ---+
!        |              |
!        |              v
!        +-> [20] Race Complete
!                |
!                v
!   [21] Results (cars active!) -> [22]/[26] -> [23]/[27] -> [30]
!        |
!        v
!   [24] Display Init -> [25] Display Loop
!
!   [28] Abort -> [29] Abort Menu -> [17] or [18] or [20]


! =============================================================================
! KEY STATE VARIABLES
! =============================================================================
!
! 0x0605AD10   = current state index (0-31)
! 0x0605A016   = phase flag (0=init, 3=post, 4=post-lap)
! 0x0607EAAC   = race countdown timer (frames)
! 0x0607EACC   = resume_state (saved before time extension)
! 0x0607ED8C   = init_flag (marks first iteration of state)
! 0x0605B6D8   = display flags (bit 30=race active, bit 31=special)
! 0x0607EBF4   = abort flag (bit 0)
! 0x0605E0A2   = resource/memory status flag
! 0x06063D9A   = new button presses (edge-triggered)
! 0x06063D98   = held buttons


! =============================================================================
! EXTRACTION PRIORITY FOR CCE TRANSPLANT
! =============================================================================
!
! | Priority | States | Notes |
! |----------|--------|-------|
! | CRITICAL | 15     | Main race loop — core gameplay |
! | HIGH     | 14,16,17 | Race setup/cleanup/lap handling |
! | HIGH     | 13,31  | Pre-race init & countdown |
! | MEDIUM   | 18,19  | Time extension mechanics |
! | MEDIUM   | 20-25  | Race completion & results |
! | LOW      | 0-12   | Menus — CCE has its own |
! | LOW      | 26-30  | Transitions/abort — game-specific |

