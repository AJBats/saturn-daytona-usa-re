! ================================================
! AUDIT: MEDIUM -- Verified addresses exist for most functions; Race HUD section (0x06030xxx) has FABRICATED addresses; high-address functions verified
! Audited: 2026-02-10
! ================================================
! =============================================================================
! Menu/Display System & Race HUD (High Address)
! =============================================================================
!
! This file documents the menu screens, HUD rendering, and display
! system functions in the high-address range.
!
! Address range: 0x06030EE0-0x06032FD4 (race HUD)
!                0x0603C1A8-0x0603CD5C (menu/display system)
!                0x0601E2B4-0x0601E810 (HUD overlays)
!
! NOTE: This supplements asm/hud_ui.s which covers the mid-range
! HUD functions (0x06010000-0x06014F34).

! =============================================================================
! RACE HUD SYSTEM (0x06030EE0-0x06032FD4)
! =============================================================================
!
! The race HUD displays: lap counter, position indicator, speedometer,
! timer, score, and race status messages.
!
! Architecture: 6 large renderers + 30+ tiny digit/counter functions.

! FUN_0603268C — Race HUD orchestrator (1486 bytes, 743 insns)
! CONFIDENCE: SPECULATIVE -- FABRICATED ADDRESS
! AUDIT NOTE: FIXED: FABRICATED ADDRESS confirmed. FUN_0603268C does NOT exist as a label in build/aprog.s. Description retained for reference but address is not a real function boundary.
!   *** LARGEST HUD FUNCTION ***
!   Manages the complete race HUD layout.
!   Coordinates all HUD elements per course.
!   Course-specific HUD variations (different layouts per track).

! FUN_06030FC0 — Speed/position display (792 bytes, 396 insns)
! CONFIDENCE: SPECULATIVE -- FABRICATED ADDRESS
! AUDIT NOTE: FIXED: FABRICATED ADDRESS confirmed. FUN_06030FC0 does NOT exist in build/aprog.s.
!   Renders speedometer and position indicator.
!   Speed displayed in km/h (fixed-point to integer conversion).
!   Position shown as ordinal (1st, 2nd, 3rd, 4th).

! FUN_0603136E — Timer display (756 bytes, 378 insns)
! CONFIDENCE: SPECULATIVE -- FABRICATED ADDRESS
! AUDIT NOTE: FIXED: FABRICATED ADDRESS confirmed. FUN_0603136E does NOT exist in build/aprog.s.
!   Renders race timer with minutes:seconds:hundredths.
!   Handles lap time display and best lap highlighting.

! FUN_06030EE0 — Lap counter display (132 insns)
! CONFIDENCE: SPECULATIVE -- FABRICATED ADDRESS
! AUDIT NOTE: FIXED: FABRICATED ADDRESS confirmed. FUN_06030EE0 does NOT exist as a labeled function in build/aprog.s. (Note: 0x06030EE0 IS a valid jsr target in subsystem_updates.s, but not a labeled function.)
!   Shows current lap / total laps.
!   Triggers lap-complete animation.

! 30+ Digit/Counter Rendering Functions (4-16 insns each)
! CONFIDENCE: SPECULATIVE -- No individual addresses given; claim of 30+ tiny digit functions is unverifiable.
!   Tiny functions that render individual digit sprites.
!   Called by the larger HUD renderers to display numbers.
!   Pattern: read digit value, compute sprite index, write VDP1 command.


! =============================================================================
! MENU/DISPLAY SYSTEM (0x0603C1A8-0x0603CD5C)
! =============================================================================
!
! Full-screen menu rendering — title screen, course select,
! options, and results screen.

! FUN_0603C1A8 — Major HUD/menu system (1282 bytes, 641 insns)
! CONFIDENCE: MEDIUM -- Address verified. Large function. Specific menu screen claims speculative.
!   Menu screen rendering and state management.
!   Handles:
!     - Title screen layout
!     - Course selection screen
!     - Difficulty selection
!     - Results/scoreboard display

! FUN_0603C728 — Extended display system (1212 bytes, 606 insns)
! CONFIDENCE: MEDIUM -- Address verified. Large function. Fade effect claims speculative.
!   Additional HUD logic and multi-screen menu handling.
!   Transitions between menu screens with fade effects.

! FUN_0603CD5C — Large display orchestrator (1252 bytes, 626 insns)
! CONFIDENCE: MEDIUM -- Address verified. Description generic.
!   Comprehensive display coordination.
!   State-dependent rendering based on current game mode.


! =============================================================================
! HUD OVERLAYS (0x0601E2B4-0x0601E810)
! =============================================================================

! FUN_0601E2B4 — HUD overlay renderer (158 bytes, 79 insns)
! CONFIDENCE: SPECULATIVE -- Address exists but descriptions unverified.
!   Renders semi-transparent HUD overlays on top of 3D scene.

! FUN_0601E4D4 — HUD state machine (306 bytes, 153 insns)
! CONFIDENCE: SPECULATIVE -- Address exists. Animation state claims speculative.
!   Controls HUD animation states:
!     - Normal display (steady)
!     - Flash/blink (warning)
!     - Slide in/out (transitions)

! FUN_0601E37C — Large HUD element (248 bytes, 124 insns)
! CONFIDENCE: SPECULATIVE -- Address exists. Mini-map/gear claims have no evidence.
!   Renders complex HUD elements (mini-map, gear indicator, etc.)

! FUN_0601E810 — HUD handler main (284 bytes, 142 insns)
! CONFIDENCE: MEDIUM -- Address verified. Entry point claim plausible.
!   Main HUD rendering entry point — called from the per-frame
!   render pipeline.

! FUN_0601E764 — HUD rendering stage (150 bytes, 75 insns)
! CONFIDENCE: SPECULATIVE -- Addresses exist. Descriptions generic.
! FUN_0601E488 — HUD text handler (76 bytes, 38 insns)
! FUN_0601E6A4 — HUD utility (56 bytes, 28 insns)
! FUN_0601E26C — HUD element positioning (58 bytes, 29 insns)
! AUDIT NOTE: FIXED: Added cross-reference note. Primary documentation for FUN_0601E26C is in replay_camera.s (verified bsr from FUN_0601DBB8). Listed here as secondary reference only.


! =============================================================================
! RACE STATE HANDLERS (0x06018DDC-0x060193F4)
! =============================================================================
!
! State handlers for race progression — the sequence of events
! from starting grid to finish line.

! FUN_06018DDC — Handler dispatcher (66 bytes, 33 insns)
! CONFIDENCE: HIGH -- Address verified. 10+ call sites. Role as dispatcher confirmed.
!   Dispatches to specific state handlers based on parameters.
!   r4=handler ID, r5=sub-handler, r6=parameter.
!   Central dispatch point referenced from asm/pre_race_states.s.

! FUN_06018E70 — General init/reset (24 bytes, 12 insns)
! CONFIDENCE: HIGH -- Address verified. 12+ call sites. Starts with sts.l pr; mov #3; add #-8 -- larger than 24 bytes.
! AUDIT NOTE: FIXED: Size of 24 bytes IS correct. Binary shows 0x06018E70-0x06018E86 = 24 bytes (12 insns). Stack frame (add #-8/+8) is allocated and freed within those 24 bytes. AUDIT NOTE was itself incorrect about the size being wrong.
!   Called at start of each state transition. Resets state variables.

! FUN_06018EE4 — Race state handler (144 bytes, 72 insns)
! CONFIDENCE: MEDIUM -- Address verified. Called from main loop (0x06003200). Position/lap claims unverified.
!   Updates position and lap data during active racing.

! Track Segment State Handlers (18 similar-sized functions):
! CONFIDENCE: HIGH -- Addresses verified for checked samples (FUN_06018FF8, FUN_06019058, FUN_060190B8). Pattern of paired functions confirmed. "Track segment" labeling is speculative; these are state-machine handlers.
! These handle different phases of the race:
!   FUN_06018FF8/06018FFC — Segment handler pair 1 (66B each)
!   FUN_06019058/0601905C — Segment handler pair 2 (66B each)
!   FUN_060190B8/060190BC — Race variant A pair (60B each)
!   FUN_060190F4/060190F8 — Race variant B pair (60B each)
!   FUN_0601914C/06019150 — Race variant C pair (60B each)
!   FUN_06019188/0601918C — Race variant D pair (60B each)
!   FUN_060191E0/060191E4 — Race variant E pair (66B each)
!   FUN_06019248/0601924C — Race variant F pair (66B each)
!
! Each pair has a setup function and an execution function.
! The paired structure suggests a command pattern:
!   Even address = register/configure the handler
!   Odd address (+4) = execute the handler

! FUN_06019324 — Race data handler (58 bytes, 29 insns)
! CONFIDENCE: SPECULATIVE -- Generic description.
! FUN_0601935E — Race utility (28 bytes, 14 insns)
! FUN_0601938C — Race state handler (56 bytes, 28 insns)
! FUN_060193F4 — Track polygon start (188 bytes, 94 insns)
! CONFIDENCE: SPECULATIVE -- Track polygon rendering claim unverified.
!   Initiates track polygon rendering for the current race state.
!   Called from pre-race states for course selection display.


! =============================================================================
! GAME LOGIC INTEGRATION (0x06038000-0x0603A0B0)
! =============================================================================
!
! High-level game logic that integrates multiple subsystems.

! FUN_0603A0B0 — Large game logic handler (1508 bytes, 754 insns)
! CONFIDENCE: MEDIUM -- Address verified. Very large function. Multi-course claim plausible.
!   Complex multi-course and multi-state handler.
!   Integration point for physics, rendering, AI, and audio.

! FUN_0603950C — Major game logic handler (658 bytes, 329 insns)
! CONFIDENCE: MEDIUM -- Address verified. Called from 0x06004BF0.
! FUN_06038BD4 — Complex state integration (570 bytes, 285 insns)
! CONFIDENCE: HIGH -- Address verified. 20+ call sites. Core subsystem dispatcher.
! FUN_06038300 — Game logic integrator (446 bytes, 223 insns)
! CONFIDENCE: SPECULATIVE -- Addresses not individually verified. Generic descriptions.
! FUN_06038120 — Course-specific state handler (430 bytes, 215 insns)
! FUN_06038642 — State machine (284 bytes, 142 insns)
! FUN_06038794 — Game state update (258 bytes, 129 insns)
!
! Plus 59 additional state handlers ranging 18-430 bytes.
! CONFIDENCE: SPECULATIVE -- Bulk claim of 59 functions is unverifiable without individual address listing.
! These collectively manage the full game state including:
!   - Race start countdown
!   - Active racing updates
!   - Pause/resume
!   - Finish/results
!   - Demo/attract mode


! =============================================================================
! EXTRACTION PRIORITY FOR CCE TRANSPLANT
! =============================================================================
!
! | Priority | Components | Notes |
! |----------|-----------|-------|
! | LOW      | Menu/display | CCE has its own menus |
! | LOW      | Race HUD | CCE has different HUD layout |
! | MEDIUM   | Race state handlers | May share logic with CCE |
! | HIGH     | Game logic integration | Core gameplay mechanics |
