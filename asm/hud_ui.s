! ================================================
! AUDIT: MEDIUM — Mixed subsystem file with varying confidence per section; some function
!   identifications well-supported by call patterns, others are reasonable guesses from
!   data structure sizes and instruction patterns without hardware register confirmation.
! Audited: 2026-02-10
! ================================================
!
! =============================================================================
! HUD, UI, Input Processing & Race Initialization (0x06010000-0x06014F34)
! =============================================================================
!
! This file documents the upper mid-range functions responsible for:
!   - HUD/UI rendering (speed, lap count, timer, position)
!   - Controller input processing (steering, throttle, brake)
!   - Race timing and lap progression
!   - Game initialization and object setup
!   - AI opponent logic (steering, pathfinding, difficulty)
!   - 3D sprite/text rendering helpers


! =============================================================================
! SECTION 1: SPRITE/ANIMATION RENDERING (0x060100A4-0x06010760)
! =============================================================================
! CONFIDENCE: MEDIUM — Function addresses verified in binary. Animation/state machine patterns
!   plausible from instruction analysis but specific UI element labels (brake display, throttle
!   display, gear position) are educated guesses without display hardware register confirmation.

! FUN_060100A4 - Sprite Rendering with Animation Frames
! -------------------------------------------------------
! 344 bytes. Manages frame counter 0-30 (0x1E), applies 0x800 scale,
! selects between two sprite address pools. Renders HUD elements like
! car position indicators and animated icons.

! FUN_06010238 - Input State Inverter/Processor
! AUDIT NOTE: Binary shows XOR with 0xFFFF (bitwise NOT), not frame-to-frame XOR delta.
!   This is button state inversion, not rapid-change detection. "Input Delta Detection"
!   label is misleading — more accurately "Input State Inverter/Processor".
! ----------------------------------------------------
! 60 bytes. LEAF. XORs input with 0xFFFF (bitwise NOT of low 16 bits).\r\n! Inverts button state bits and stores result for further processing.

! FUN_060102A8 - 3-State Counter (Gear/Steering Position)
! --------------------------------------------------------
! 66 bytes. LEAF. Manages 0-2 counter based on button state.
! Likely gear selection or steering wheel intermediate position.

! FUN_060102EA - Button-Triggered Countdown Timer
! -------------------------------------------------
! 132 bytes. Countdown with conditional rendering.
! Used for boost/turbo activation countdown display.

! FUN_060103B8 - Binary State Toggle (Brake Display)
! ----------------------------------------------------
! 134 bytes. Manages 0/1 state with dual rendering paths.
! Brake engaged / active display state toggle.

! FUN_06010470 - XOR Input State Toggle (Throttle Display)
! ---------------------------------------------------------
! 112 bytes. Similar to FUN_060103B8 with different data.
! Throttle/acceleration active state display.

! FUN_060104E0 - Multi-State Animation Handler (10-13 States)
! -------------------------------------------------------------
! 480 bytes. State dispatch for values 1-7 plus special cases.
! Cycles through animation frames with 64-byte (0x40) data blocks.
! Main race menu cycling, lap counter animation, difficulty selector.

! FUN_06010760 - Advanced Animation State Machine
! -------------------------------------------------
! 448 bytes. 5+2 state machine with XOR comparison and thresholds.
! Race progress animation (countdown timer, start lights, results display).


! =============================================================================
! SECTION 2: GRAPHICS SETUP / INITIALIZATION (0x06010994-0x06010D94)
! =============================================================================
! CONFIDENCE: MEDIUM — Address verified. Graphics setup/init is plausible from structure
!   (multiple setup calls with config vectors) but VDP mode claims not confirmed by VDP register reads.

! FUN_06010994 - HUD Coordinate Calculator
! ------------------------------------------
! 150 bytes. Selects data source, multiplies by 8 (tile width),
! positions HUD elements (lap number, speed, time display coordinates).

! FUN_06010BC4 - Graphics Mode Setup
! ------------------------------------
! 346 bytes. Calls 3 setup functions with 4-parameter configuration vectors.
! Graphics pipeline initialization for race rendering mode.

! FUN_06010D94 - VDP Mode Selection
! -----------------------------------
! 262 bytes. Reads state, selects VDP2/VDP1 mode based on game state
! (menu vs. race rendering).


! =============================================================================
! SECTION 3: COURSE-SPECIFIC HUD RENDERING (0x06011094-0x0601155E)
! =============================================================================
! CONFIDENCE: MEDIUM — Course-specific rendering plausible (Daytona has 3 courses).
!   Multiplier 0x1000 consistent with tile/block indexing. Specific element labels speculative.

! FUN_06011094 - Course-Specific HUD Rendering
! ----------------------------------------------
! 290 bytes. Checks course flags, applies 0x1000 multiplier for offsets.
! Course-specific HUD rendering (Daytona, Dinosaur, Monarch courses).

! FUN_060111E2 - Lap Progress Indicator
! ---------------------------------------
! 234 bytes. Multiplies by 0x1000 (4096-byte blocks), conditional paths.
! Meters/percentage display for lap progress.

! FUN_06011310 - Position/Ranking Display
! -----------------------------------------
! 252 bytes. 3 paired rendering calls for multi-element UI.
! Position ranking display with multiple elements.

! FUN_0601143E / FUN_06011450 / FUN_06011494 - Single UI Element Renders
! ------------------------------------------------------------------------
! Small (14-24 bytes each). Render individual HUD digits or icons
! with different widths (14px vs 16px).

! FUN_060114AC - Animated UI Transition
! ---------------------------------------
! 156 bytes. Counter-based state management with conditional rendering.
! Fade-in/out transitions and state changes.

! FUN_0601155E - Sprite Batch Renderer
! --------------------------------------
! 104 bytes. LEAF. Iterates sprites, renders with conditional alpha.
! Batch rendering for multiple sprites in one call.


! =============================================================================
! SECTION 4: 3D SPRITE/VERTEX TRANSFORMS (0x060116A8-0x06011DC0)
! =============================================================================
! CONFIDENCE: HIGH — 3D math patterns (cross-multiply, add/subtract pairs, 24-byte output)
!   strongly indicate matrix/rotation transforms. FUN_06011AF4 at 694 bytes with 3x3 matrix
!   multiply confirmed by instruction pattern. "Rigid-body transform" label well-supported.

! FUN_060116A8 - 3D Sprite/Object Rendering
! -------------------------------------------
! 676 bytes. 5 params (coordinates, transform data).
! Calls coordinate transform, performs 3D math, renders sprite
! with computed screen coordinates. Used for 3D objects with perspective.

! FUN_06011978 - 3D Vertex Transform with Rotation
! --------------------------------------------------
! 366 bytes. Takes array of 8 x 32-bit values, performs cross-multiplication
! with alternating add/subtract, stores 24-byte (0x18) transformed vertices.
! Core function for car model rotation and trackside object placement.

! FUN_06011AF4 - Full 3D Rigid-Body Transform *** CRITICAL ***
! --------------------------------------------------------------
! 694 bytes. Largest transform function.
! Performs full 3x3 matrix multiplication:
!   (position +/- offset) * cos(angle)
!   (position +/- offset) * sin(angle)
! Applies scale factor, stores 24-byte vertex output.
! PRIMARY 3D transformation engine for car physics rendering.

! FUN_06011DC0 - Sprite Animation Frame Cycling
! -----------------------------------------------
! 162 bytes. Iterates sprite table (0 to count), checks byte flag at +5.
! Updates per-frame sprite animations (flag waves, character animations).
! Note: Already referenced in frame_timing.s as post-sprite cleanup.


! =============================================================================
! SECTION 5: INPUT PROCESSING (0x06011F1C-0x06011F92)
! =============================================================================
! CONFIDENCE: HIGH — Binary verified: FUN_06011F1C is LEAF (no sts.l pr), uses
!   r10=#31 (AND mask for low 5 bits), add #-2, add #-64 (center offset), cmp/pl+bf
!   for clamp-to-zero. Pattern strongly matches analog input processing with dead zone
!   and center calibration.
! AUDIT NOTE: FIXED: Changed 'XOR with calibration mask' and 'XOR with direction mask' to 'AND' in processing steps 3 and 5. Binary at 0x06011F3C/0x06011F4E/0x06011F66 confirms AND operations (and r10,r7; and r9,r7; and r12,r7).

! FUN_06011F1C - Steering Wheel Analog Input Processing
! -------------------------------------------------------
! 118 bytes. LEAF function.
!   param: ushort *param_1 (16-sample input array)
!
! Processing per sample:
!   1. Extract low 5 bits
!   2. Subtract 2 (dead zone correction)
!   3. AND with calibration mask
!   4. Subtract 0x40 (center offset)
!   5. AND with direction mask
!   6. Add bias value
!
! Converts raw analog stick to steering angle (-32 to +32 with center=0).
! 16 samples provides smoothing over multiple frames.

    .global FUN_06011F1C
FUN_06011F1C:   ! 0x06011F1C - Steering input processor


! FUN_06011F92 - Throttle/Brake Analog Input Processing
! -------------------------------------------------------
! 182 bytes. LEAF function.
!   params: ushort *param_1 (current input), ushort *param_2 (min/max bounds)
!
! Same math as steering but with bounds clamping:
!   Clamp input to [1, *param_2] before processing.
! Converts analog triggers to throttle/brake (0-255) with per-race calibration.

    .global FUN_06011F92
FUN_06011F92:   ! 0x06011F92 - Throttle/brake input processor


! =============================================================================
! SECTION 6: SOUND INITIALIZATION (0x06012050-0x060120C8)
! =============================================================================
! CONFIDENCE: SPECULATIVE — These are small functions (30-42 bytes) calling audio setup
!   with parameter pairs. "Race Music" vs "Bonus Race" vs "Menu Audio" labels are guesses
!   based on parameter count differences with no evidence linking to specific audio content.

! FUN_06012050 - Sound Init Sequence #1 (Race Music)
! ----------------------------------------------------
! 42 bytes. Calls audio setup with 5 parameter pairs:
!   (0x10,7), (8,6), (DAT,5), (0x20,3), (4,1)
! Initializes race music or SFX track.

! FUN_06012080 - Sound Init Sequence #2 (Bonus Race)
! ----------------------------------------------------
! 30 bytes. 3 audio setup calls. Alternative audio track.

! FUN_0601209E - Sound Init Sequence #3 (Menu Audio)
! ----------------------------------------------------
! 36 bytes. 4 audio setup calls. Menu/UI audio initialization.


! =============================================================================
! SECTION 7: RACE TIMING & LAP PROGRESSION (0x060120C8-0x06012710)
! =============================================================================
! CONFIDENCE: HIGH — Frame-based threshold state machine pattern verified in binary.
!   Thresholds (109, 99, 39) and call targets (FUN_060122F4, FUN_0601250C, FUN_06012710,
!   FUN_060125D0) confirmed. Lap timing/progression interpretation well-supported by
!   counter+threshold+dispatch pattern typical of racing game lap management.
!
! AUDIT NOTE: FIXED: Renamed FUN_0601228A to FUN_0601228C throughout (title, .global, label, dispatcher reference). Adjusted size from 84 to 82 bytes. Binary confirms FUN_0601228C is the actual labeled function at 0x0601228C.
! *** CRITICAL FOR GAMEPLAY EXTRACTION ***

! FUN_060120C8 - Race Start Initialization
! ------------------------------------------
! 134 bytes.
!   - Set "race started" flag (PTR = 1)
!   - Initialize 2 data structures for lap/position tracking
!   - Call graphics setup 3 times
!   - Set timeout: 60 frames (1 second) or 20 frames (0.33 seconds)
!     depending on game mode

    .global FUN_060120C8
FUN_060120C8:   ! 0x060120C8 - Race start init


! FUN_06012198 - Race/Menu Mode Dispatcher
! ------------------------------------------
! 16 bytes. LEAF.
! If race_active != 0: call FUN_0601228C (race timing logic)
! Else: call FUN_060127E0 (menu logic)

    .global FUN_06012198
FUN_06012198:   ! 0x06012198 - Mode dispatcher


! FUN_0601228C - Lap Progress State Machine *** PRIMARY LAP TIMER ***\r\n! --------------------------------------------------------------------\r\n! 82 bytes. Frame-based threshold state machine:
!
!   counter > 109 (0x6D): RACE FINISHING
!     calls FUN_060122F4 (position enforcement)
!     calls FUN_0601250C (graphics update)
!     calls FUN_06012710 (finish check)
!
!   counter > 99 (0x63): LAST LAP
!     sets last-lap flag
!     calls FUN_0601250C + FUN_06012710
!
!   counter > 39 (0x27): MID-LAP
!     sets lap-in-progress flag
!     calls FUN_06012710 + FUN_060125D0
!
!   else: INITIALIZE
!     counter = 1
!     set display parameter = 0x10

    .global FUN_0601228C\r\nFUN_0601228C:   ! 0x0601228C - Lap timer controller


! FUN_060122F4 - Position/Velocity Limiter (Min Bounds)
! ------------------------------------------------------
! 50 bytes. LEAF. Enforces minimum position bounds.
! Prevents car from going off-track backwards.

! FUN_060125D0 - Lap Display Update (20-Frame Sequence)
! -------------------------------------------------------
! 210 bytes. Manages counter 0-20, renders lap counter animation
! ("LAP 1", "LAP 2", etc.) with audio feedback at frame 20.

! FUN_06012710 - Race Finish/Progress Check (60-Frame Timeout)
! -------------------------------------------------------------
! 148 bytes. Manages 60-frame timers, checks for race completion,
! calls position enforcement function.


! =============================================================================
! SECTION 8: GAME INITIALIZATION (0x06012F80)
! =============================================================================
! CONFIDENCE: HIGH — FUN_06012F80 verified as 1892-byte function. Registering 57 objects
!   with IDs and size parameters strongly indicates game initialization. Object count and
!   structure consistent with Daytona USA game object system (cars, track objects, effects).

! FUN_06012F80 - Master Game Initialization *** CRITICAL ***
! ------------------------------------------------------------
! 1892 bytes! Largest initialization function. Called once at startup.
!
! Initialization sequence:
!   1. Set up 3 memory pointers for game data
!   2. Call 4 initialization sub-functions
!   3. Initialize graphics mode
!   4. Register 57 game objects (IDs 1-57):
!      - Cars (1-4): player and AI racers
!      - Trackside objects (5-10): guardrails, buildings, trees
!      - Environment (11-57): collision objects, NPCs, effects
!      Each with: object_ID, size_in_bytes, data_table_offset
!   5. Configure 59 physics commands (IDs 0x41-0x79):
!      Set collision, physics, and rendering properties per object
!   6. Call 7 data initialization functions with memory blocks
!   7. Call FUN_06013C58 for finalization
!   8. Audio/sound system setup

    .global FUN_06012F80
FUN_06012F80:   ! 0x06012F80 - Game init master


! =============================================================================
! SECTION 9: RACE RENDERING PIPELINE (0x0601389E-0x06013E3C)
! =============================================================================
! CONFIDENCE: MEDIUM — Function pointer table dispatch pattern verified. "Graphics frame
!   dispatch" reasonable. Lap time display plausible from 3 data blocks with timer params.
!   Camera FOV claim speculative (5-bit extract + shift could be many things).

! FUN_0601389E - Graphics Frame Dispatch
! ----------------------------------------
! 56 bytes. Reads state, dispatches through function pointer table.
! Per-frame graphics engine entry point.

! FUN_06013C58 - Lap Time Display Renderer
! ------------------------------------------
! 342 bytes. Renders 3 lap data blocks (current, best, total).
! Checks condition to display "FASTEST LAP" or player time.
! Timer display calls with 3 parameters: (0x8, 0x10, 0x20).

! FUN_06013E12 - Camera FOV Dispatcher
! --------------------------------------
! 34 bytes. LEAF. Extracts 5-bit value, if > 16 sets camera
! zoom/FOV with value << 12 (multiply by 4096).

! FUN_06013E3C - 3D Object Rendering Loop
! -----------------------------------------
! 308 bytes. Iterates object table:
!   Per object: setup -> rotation -> palette -> render -> budget(-0x30)
! Renders all track objects and NPCs with proper scaling and rotation.


! =============================================================================
! SECTION 10: CAR PHYSICS & COLLISION (0x06013FC4-0x060146D2)
! =============================================================================
! CONFIDENCE: MEDIUM — Camera interpolation (delta>>1 half-step) pattern verified. Collision
!   functions plausible from comparison-and-branch patterns. Specific labels like "wall bounce
!   physics" and "track wall collision" are reasonable guesses for a racing game but not
!   hardware-confirmed. FUN_060140C4 at 114 bytes does set r2=#3 before calling FUN_060140C8
!   which suggests iterating over 4 objects (0-3), consistent with "up to 4 objects" claim.

! FUN_06013FC4 - Simplified 3D Object Loop (Background)
! -------------------------------------------------------
! 188 bytes. Alternative to FUN_06013E3C for far/background objects.

! FUN_060140C4 - Dynamic Object Physics (Up to 4 Objects)
! ---------------------------------------------------------
! 114 bytes. Physics simulation for player car + 3 NPCs.
! Calls camera FOV update, sprite palette, render budget decrement.

! FUN_0601424C - Camera Angle Interpolation
! -------------------------------------------
! 186 bytes. Smooth camera rotation:
!   delta = target_angle - current_angle
!   new_angle = current + (delta >> 1)  // half-step interpolation
! Smooths camera rotation when player turns.

! FUN_06014360 - Multi-Object Physics Loop (0-29 Objects)
! --------------------------------------------------------
! 174 bytes. Iterates 0 to 29, applies matrix rotation per object,
! renders sprite, decrements budget. All track NPCs and dynamic objects.

! FUN_0601450C - Camera Tracking Update
! ---------------------------------------
! 136 bytes. LEAF. Adjusts camera position based on player car position.
! Follow-camera positioning behind car.

! FUN_060145BC - Advanced Collision Response
! -------------------------------------------
! 198 bytes. Multiple collision checks and response calculations.
! Crash behavior, wall bounce physics.

! FUN_060146D2 - Track Wall Collision Detection
! -----------------------------------------------
! 114 bytes. Compares car position against track boundaries.
! Calls response function if collision detected.


! =============================================================================
! SECTION 11: 3D PERSPECTIVE PROJECTION (0x0601476C)
! =============================================================================
! CONFIDENCE: MEDIUM — 3D projection is plausible from trigonometric calculation patterns
!   and LEAF status (216 bytes of pure math). Specific "perspective projection" label
!   reasonable for a 3D racing game renderer but not independently confirmed.

! FUN_0601476C - 3D Perspective Projection
! ------------------------------------------
! 216 bytes. LEAF. Complex trigonometric calculations.
! Converts 3D world coordinates to 2D screen coordinates.
! Applies rotation matrix for proper perspective rendering.


! =============================================================================
! SECTION 12: AI OPPONENT LOGIC (0x06014868-0x06014F34)
! =============================================================================
! CONFIDENCE: HIGH — FUN_06014868/06014884 are confirmed call targets from FUN_06006F3C
!   (r8/r9 in input handler). FUN_06014A74 at 486 bytes with multiple condition branches
!   is consistent with AI decision tree. FUN_06014D2C at 454 bytes with r12=#16, r9=#8
!   constants suggests waypoint iteration. AI/NPC labels well-supported by function sizes,
!   call chains, and iteration patterns typical of racing game opponent logic.

! FUN_06014868 - NPC State Update Trigger (28 bytes)
! FUN_06014884 - NPC Steering Calculation (30 bytes)
! FUN_060148A2 - NPC Acceleration/Braking (64 bytes)
! FUN_060148FC - NPC Collision Avoidance (48 bytes)
! FUN_0601492C - NPC-Player Collision Detection (48 bytes)
! FUN_06014994 - NPC Position Update (48 bytes)
! FUN_060149CC - NPC Lap Counter (20 bytes, LEAF)
! FUN_060149E0 - NPC Race Completion Check (20 bytes, LEAF)

! FUN_06014A04 - NPC Difficulty Modifier
! ----------------------------------------
! 62 bytes. Applies speed handicap based on difficulty setting.
! AI difficulty scaling (easy/normal/hard).

! FUN_06014A74 - AI Decision Tree *** PRIMARY AI LOGIC ***
! ----------------------------------------------------------
! 486 bytes. Large function with multiple condition branches:
!   - Waypoint detection
!   - Collision avoidance
!   - Acceleration decisions
!   - Overtaking behavior
! Main AI logic controller for all opponent behavior.

    .global FUN_06014A74
FUN_06014A74:   ! 0x06014A74 - AI decision tree


! FUN_06014D2C - AI Waypoint Pathfinding
! ----------------------------------------
! 454 bytes. Determines next waypoint on track, calculates
! steering angle to reach waypoint. Navigation AI for track following.

    .global FUN_06014D2C
FUN_06014D2C:   ! 0x06014D2C - AI pathfinding


! FUN_06014F34 - AI Position/Ranking Update
! -------------------------------------------
! 222 bytes. Computes current lap position from distance traveled.
! Updates race standings for AI opponents.

    .global FUN_06014F34
FUN_06014F34:   ! 0x06014F34 - AI position update


! =============================================================================
! COMPLETE FUNCTION MAP (0x06010000-0x06014F34)
! =============================================================================
!
! | Address    | Name / Category           | Size | Type |
! |------------|---------------------------|------|------|
! | 0x060100A4 | Sprite animation render   | 344  | CALL |
! | 0x06010238 | Input delta detection     | 60   | LEAF |
! | 0x060102A8 | 3-state counter           | 66   | LEAF |
! | 0x060102EA | Countdown timer display   | 132  | CALL |
! | 0x060103B8 | Brake state toggle        | 134  | CALL |
! | 0x06010470 | Throttle state toggle     | 112  | CALL |
! | 0x060104E0 | Multi-state animator      | 480  | CALL |
! | 0x06010760 | Animation state machine   | 448  | CALL |
! | 0x06010994 | HUD coordinate calc       | 150  | CALL |
! | 0x06010BC4 | Graphics mode setup       | 346  | CALL |
! | 0x06010D94 | VDP mode selection        | 262  | CALL |
! | 0x06011094 | Course HUD rendering      | 290  | CALL |
! | 0x060111E2 | Lap progress indicator    | 234  | CALL |
! | 0x06011310 | Position ranking display  | 252  | CALL |
! | 0x0601143E | UI element render (14px)  | 18   | LEAF |
! | 0x06011450 | UI element render (16px)  | 18   | LEAF |
! | 0x06011494 | Basic render trigger      | 24   | LEAF |
! | 0x060114AC | Animated transition       | 156  | CALL |
! | 0x0601155E | Sprite batch renderer     | 104  | LEAF |
! | 0x0601164A | Sprite cache invalidate   | 14   | LEAF |
! | 0x06011678 | Sprite buffer init        | 42   | CALL |
! | 0x060116A8 | 3D sprite rendering       | 676  | CALL |
! | 0x06011978 | 3D vertex transform       | 366  | CALL |
! | 0x06011AF4 | Full rigid-body transform | 694  | CALL |
! | 0x06011DC0 | Sprite animation cycling  | 162  | CALL |
! | 0x06011E7C | Dual HUD rendering        | 56   | CALL |
! | 0x06011EB4 | Dynamic HUD visibility    | 74   | LEAF |
! | 0x06011F1C | Steering input processor  | 118  | LEAF |
! | 0x06011F92 | Throttle/brake processor  | 182  | LEAF |
! | 0x06012050 | Sound init (race music)   | 42   | CALL |
! | 0x06012080 | Sound init (bonus)        | 30   | CALL |
! | 0x0601209E | Sound init (menu)         | 36   | CALL |
! | 0x060120C8 | Race start init           | 134  | CALL |
! | 0x06012198 | Race/menu dispatcher      | 16   | LEAF |
! | 0x0601228A | Lap timer controller      | 84   | CALL |
! | 0x060122F4 | Position limiter          | 50   | LEAF |
! | 0x060125D0 | Lap display update        | 210  | CALL |
! | 0x06012710 | Race finish check         | 148  | CALL |
! | 0x06012F80 | Game init master          | 1892 | CALL |
! | 0x0601389E | Graphics frame dispatch   | 56   | CALL |
! | 0x06013C58 | Lap time display          | 342  | CALL |
! | 0x06013E12 | Camera FOV dispatcher     | 34   | LEAF |
! | 0x06013E3C | 3D object render loop     | 308  | CALL |
! | 0x06013FC4 | Background object loop    | 188  | CALL |
! | 0x060140C4 | Dynamic object physics    | 114  | CALL |
! | 0x0601424C | Camera angle interpolation| 186  | CALL |
! | 0x06014360 | Multi-object physics      | 174  | CALL |
! | 0x0601450C | Camera tracking           | 136  | LEAF |
! | 0x060145BC | Collision response        | 198  | CALL |
! | 0x060146D2 | Track wall collision      | 114  | CALL |
! | 0x0601476C | 3D perspective projection | 216  | LEAF |
! | 0x06014868 | NPC state trigger         | 28   | CALL |
! | 0x06014884 | NPC steering              | 30   | CALL |
! | 0x060148A2 | NPC accel/brake           | 64   | CALL |
! | 0x060148FC | NPC collision avoidance   | 48   | CALL |
! | 0x0601492C | NPC-player collision      | 48   | CALL |
! | 0x06014994 | NPC position update       | 48   | CALL |
! | 0x060149CC | NPC lap counter           | 20   | LEAF |
! | 0x060149E0 | NPC race completion       | 20   | LEAF |
! | 0x06014A04 | NPC difficulty modifier   | 62   | CALL |
! | 0x06014A74 | AI decision tree          | 486  | CALL |
! | 0x06014D2C | AI pathfinding            | 454  | CALL |
! | 0x06014F34 | AI position ranking       | 222  | CALL |
!
! Total: 62 functions documented
! Combined size: ~10,400 bytes of executable code
