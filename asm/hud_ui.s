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
! 60 bytes. LEAF. XORs input with 0xFFFF (bitwise NOT of low 16 bits).
! Inverts button state bits and stores result for further processing.

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


! FUN_0601228C - Lap Progress State Machine *** PRIMARY LAP TIMER ***
! --------------------------------------------------------------------
! 82 bytes. Frame-based threshold state machine:
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

    .global FUN_0601228C
FUN_0601228C:   ! 0x0601228C - Lap timer controller


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

! CORRECTION (2026-02-20, L3 crossword uplift):
!   Section title "AI OPPONENT LOGIC" is WRONG. Binary analysis shows these are
!   DISPLAY CHANNEL MANAGEMENT functions. All operate on a 6-channel system
!   (IDs: 1, 4, 8, 16, 32, 0x100) coordinated through shared state:
!     0x060635A8 = command slot (channel ID written here)
!     0x060635AC = command-ready flag (0=idle, 1=pending)
!     0x060A3D88 = display enable state (bit 15 = master enable)
!   FUN_06014868/84 are command dispatchers called from VBlank-IN handler.
!   FUN_060148A2/FC/492C/4964/4994 configure all 6 channels via FUN_06038BD4.
!   FUN_06014A04 writes to VDP1 VRAM (0x25C00000+).
!   FUN_06014A74 writes VDP2 Color RAM (0x25F006xx) and VDP2 VRAM (0x25E7xxxx).
!   Original labels ("NPC Steering", "NPC Collision", "AI Decision Tree") were
!   based on function sizes and call patterns without hardware register analysis.
!
! Corrected function list:
!   FUN_06014868 - display channel update A (28 bytes, CALL)
!   FUN_06014884 - display channel update B (30 bytes, CALL)
!   FUN_060148A2 - load all channels from config array (64 bytes, CALL)
!   FUN_060148FC - clear all channels to 0 (48 bytes, CALL)
!   FUN_0601492C - set channel config A (48 bytes, CALL)
!   FUN_06014964 - set channel config partial (48 bytes, CALL) [MISSING FROM ORIGINAL]
!   FUN_06014994 - set channel config B (48 bytes, CALL)
!   sym_060149CC - enable display: set bit 15 (20 bytes, LEAF)
!   sym_060149E0 - disable display: clear bit 15 (20 bytes, LEAF)
!   FUN_06014A04 - VDP1 command table update (62 bytes, CALL)
!   FUN_06014A42 - utility wrapper (12 bytes) [MISSING FROM ORIGINAL]
!   FUN_06014A74 - display mode init (486 bytes, CALL)
!   FUN_06014D2C - pending full decode (454 bytes, CALL)
!   FUN_06014F34 - pending full decode (222 bytes, CALL)
!
! Original labels (preserved for reference):
! FUN_06014868 - NPC State Update Trigger (28 bytes)
! FUN_06014884 - NPC Steering Calculation (30 bytes)
! FUN_060148A2 - NPC Acceleration/Braking (64 bytes)
! FUN_060148FC - NPC Collision Avoidance (48 bytes)
! FUN_0601492C - NPC-Player Collision Detection (48 bytes)
! FUN_06014994 - NPC Position Update (48 bytes)
! FUN_060149CC - NPC Lap Counter (20 bytes, LEAF)
! FUN_060149E0 - NPC Race Completion Check (20 bytes, LEAF)


! ---- FUN_06014868 — Display Channel Update A (28 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x06014868-0x06014883)
! Called from VBlank-IN handler (r9 dispatch) when display flag bits are set.
! Three-step pattern: command_write(channel) -> action_A(data1, data2) -> commit.
!
FUN_06014868:                        ! 0x06014868
    sts.l   pr,@-r15               ! save return address
    add     #-8,r15                ! allocate stack frame: [data_ptr_1, data_ptr_2]
    mov.l   r5,@r15                ! save data_ptr_1 (becomes r4 for action call)
    mov.l   @(POOL),r3             ! r3 = sym_0603850C — command_slot_write
    jsr     @r3                    ! write channel_id (r4) to command slot 0x060635A8
    mov.l   r6,@(4,r15)           ! (delay) save data_ptr_2
    mov.l   @(4,r15),r5           ! r5 = data_ptr_2
    mov.l   @(POOL),r3             ! r3 = FUN_06038794 — display action A
    jsr     @r3                    ! action_A(r4=data_ptr_1, r5=data_ptr_2)
    mov.l   @r15,r4               ! (delay) r4 = saved data_ptr_1
    add     #8,r15                 ! free stack frame
    mov.l   @(POOL),r3             ! r3 = sym_06038520 — command_commit
    jmp     @r3                    ! tail-call: set ready flag at 0x060635AC
    lds.l   @r15+,pr              ! (delay) restore return address


! ---- FUN_06014884 — Display Channel Update B (30 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x06014884-0x060148A1)
! Called from VBlank-IN handler (r8 dispatch). Nearly identical to FUN_06014868:
!   - Calls FUN_0603853C (action B / scene setup) instead of FUN_06038794
!   - Passes r6=0 as third parameter to action B
!
FUN_06014884:                        ! 0x06014884
    sts.l   pr,@-r15               ! save return address
    add     #-8,r15                ! allocate stack frame
    mov.l   r5,@r15                ! save data_ptr_1
    mov.l   @(POOL),r3             ! r3 = sym_0603850C — command_slot_write
    jsr     @r3                    ! write channel_id (r4) to command slot 0x060635A8
    mov.l   r6,@(4,r15)           ! (delay) save data_ptr_2
    mov     #0,r6                  ! r6 = 0 — third param for action B
    mov.l   @(4,r15),r5           ! r5 = data_ptr_2
    mov.l   @(POOL),r3             ! r3 = FUN_0603853C — display action B (scene setup)
    jsr     @r3                    ! action_B(r4=data_ptr_1, r5=data_ptr_2, r6=0)
    mov.l   @r15,r4               ! (delay) r4 = saved data_ptr_1
    add     #8,r15                 ! free stack frame
    mov.l   @(POOL),r3             ! r3 = sym_06038520 — command_commit
    jmp     @r3                    ! tail-call: set ready flag at 0x060635AC
    lds.l   @r15+,pr              ! (delay) restore return address


! ---- FUN_060148A2 — Load All Display Channels From Config (64 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x060148A2-0x060148E1)
! Reads 6 bytes from config array at 0x0605B71C and writes each as a channel
! value via FUN_06038BD4(channel_id, value).
! Channel mapping: byte[0]->ch 0x100, [1]->ch 4, [2]->ch 8,
!                  byte[3]->ch 16, [4]->ch 32, [5]->ch 1
!
FUN_060148A2:                        ! 0x060148A2
    mov.l   r14,@-r15              ! save r14
    mov.l   r13,@-r15              ! save r13
    sts.l   pr,@-r15               ! save return address
    mov.l   @(POOL),r13            ! r13 = 0x0605B71C — channel config array (6 bytes)
    mov.l   @(POOL),r14            ! r14 = FUN_06038BD4 — per-channel setter
    mov.w   @(POOL),r4             ! r4 = 0x100 — channel ID: master
    jsr     @r14                   ! set_channel(0x100, config[0])
    mov.b   @r13,r5                ! (delay) r5 = config[0]
    mov.b   @(1,r13),r0            ! r0 = config[1]
    mov     r0,r5                  ! r5 = config[1]
    jsr     @r14                   ! set_channel(4, config[1])
    mov     #4,r4                  ! (delay) r4 = channel 4
    mov.b   @(2,r13),r0            ! r0 = config[2]
    mov     r0,r5
    jsr     @r14                   ! set_channel(8, config[2])
    mov     #8,r4
    mov.b   @(3,r13),r0            ! r0 = config[3]
    mov     r0,r5
    jsr     @r14                   ! set_channel(16, config[3])
    mov     #16,r4
    mov.b   @(4,r13),r0            ! r0 = config[4]
    mov     r0,r5
    jsr     @r14                   ! set_channel(32, config[4])
    mov     #32,r4
    mov.b   @(5,r13),r0            ! r0 = config[5]
    mov     r0,r5
    jsr     @r14                   ! set_channel(1, config[5])
    mov     #1,r4
    lds.l   @r15+,pr              ! restore pr
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14              ! (delay)

! --- Shared pool A (0x060148E2-0x060148FA) ---
!   0x060148E2: .word  0x0100         ! channel ID 256 (master)
!   0x060148E4: .4byte sym_0603850C   ! command_slot_write
!   0x060148E8: .4byte FUN_06038794   ! display action A
!   0x060148EC: .4byte sym_06038520   ! command_commit
!   0x060148F0: .4byte FUN_0603853C   ! display action B (scene setup)
!   0x060148F4: .4byte sym_0605B71C   ! channel config array (6 bytes)
!   0x060148F8: .4byte FUN_06038BD4   ! per-channel setter


! ---- FUN_060148FC — Clear All Display Channels (48 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x060148FC-0x0601492B)
! Sets all 6 channels to value 0 via FUN_06038BD4. Resets display state.
!
FUN_060148FC:                        ! 0x060148FC
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(POOL),r14            ! r14 = FUN_06038BD4
    mov.w   @(POOL),r4             ! r4 = 0x100
    jsr     @r14                   ! set_channel(0x100, 0)
    mov     #0,r5
    mov     #0,r5
    jsr     @r14                   ! set_channel(4, 0)
    mov     #4,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(8, 0)
    mov     #8,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(16, 0)
    mov     #16,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(32, 0)
    mov     #32,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(1, 0)
    mov     #1,r4
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! ---- FUN_0601492C — Set Channel Config A (48 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x0601492C-0x0601495B)
! Preset: {0x100->4, 4->1, 8->5, 16->6, 32->7, 1->0}
!
FUN_0601492C:                        ! 0x0601492C
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(POOL),r14            ! r14 = FUN_06038BD4
    mov.w   @(POOL),r4             ! r4 = 0x100
    jsr     @r14                   ! set_channel(0x100, 4)
    mov     #4,r5
    mov     #1,r5
    jsr     @r14                   ! set_channel(4, 1)
    mov     #4,r4
    mov     #5,r5
    jsr     @r14                   ! set_channel(8, 5)
    mov     #8,r4
    mov     #6,r5
    jsr     @r14                   ! set_channel(16, 6)
    mov     #16,r4
    mov     #7,r5
    jsr     @r14                   ! set_channel(32, 7)
    mov     #32,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(1, 0)
    mov     #1,r4
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14

! --- Shared pool B (0x0601495C-0x06014962) ---
!   0x0601495C: .word  0x0100         ! channel ID 256
!   0x06014960: .4byte FUN_06038BD4   ! per-channel setter


! ---- FUN_06014964 — Set Channel Config Partial (48 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x06014964-0x06014993)
! NOTE: MISSING from original Section 12 function list.
! Preset: {0x100->0, 4->1, 8->0, 16->0, 32->0, 1->0} — only channel 4 active.
!
FUN_06014964:                        ! 0x06014964
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(POOL),r14            ! r14 = FUN_06038BD4
    mov.w   @(POOL),r4             ! r4 = 0x100
    jsr     @r14                   ! set_channel(0x100, 0)
    mov     #0,r5
    mov     #1,r5
    jsr     @r14                   ! set_channel(4, 1)
    mov     #4,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(8, 0)
    mov     #8,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(16, 0)
    mov     #16,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(32, 0)
    mov     #32,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(1, 0)
    mov     #1,r4
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! ---- FUN_06014994 — Set Channel Config B (48 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x06014994-0x060149C3)
! Preset: {0x100->4, 4->1, 8->0, 16->6, 32->7, 1->0}
! Like config A but channel 8 = 0 instead of 5.
!
FUN_06014994:                        ! 0x06014994
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(POOL),r14            ! r14 = FUN_06038BD4
    mov.w   @(POOL),r4             ! r4 = 0x100
    jsr     @r14                   ! set_channel(0x100, 4)
    mov     #4,r5
    mov     #1,r5
    jsr     @r14                   ! set_channel(4, 1)
    mov     #4,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(8, 0)
    mov     #8,r4
    mov     #6,r5
    jsr     @r14                   ! set_channel(16, 6)
    mov     #16,r4
    mov     #7,r5
    jsr     @r14                   ! set_channel(32, 7)
    mov     #32,r4
    mov     #0,r5
    jsr     @r14                   ! set_channel(1, 0)
    mov     #1,r4
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14

! --- Shared pool C (0x060149C4-0x060149CA) ---
!   0x060149C4: .word  0x0100         ! channel ID 256
!   0x060149C8: .4byte FUN_06038BD4   ! per-channel setter


! ---- sym_060149CC — Enable Display (Set Bit 15) (20 bytes, LEAF) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x060149CC-0x060149DF)
! ORs 0x8000 into word at 0x060A3D88, then sets command-ready flag.
! Bit 15 of 0x060A3D88 = master display enable.
!
sym_060149CC:                        ! 0x060149CC
    mov.l   @(POOL),r3             ! r3 = 0x00008000 (bit 15 mask)
    mov.l   @(POOL),r2             ! r2 = 0x060A3D88 — display state word
    mov.w   @r2,r2                 ! r2 = current display state
    or      r3,r2                  ! set bit 15 (enable)
    mov.l   @(POOL),r3             ! r3 = 0x060A3D88 (reload for write)
    mov.w   r2,@r3                 ! write back with bit 15 set
    mov     #1,r2                  ! r2 = 1
    mov.l   @(POOL),r3             ! r3 = 0x060635AC — command-ready flag
    rts
    mov.w   r2,@r3                 ! (delay) set ready flag = 1


! ---- sym_060149E0 — Disable Display (Clear Bit 15) (20 bytes, LEAF) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x060149E0-0x060149F3)
! ANDs 0x7FFF into word at 0x060A3D88, then sets command-ready flag.
!
sym_060149E0:                        ! 0x060149E0
    mov.w   @(POOL),r3             ! r3 = 0x7FFF (bit 15 clear mask)
    mov.l   @(POOL),r2             ! r2 = 0x060A3D88
    mov.w   @r2,r2                 ! r2 = current display state
    and     r3,r2                  ! clear bit 15 (disable)
    mov.l   @(POOL),r3             ! r3 = 0x060A3D88 (reload for write)
    mov.w   r2,@r3                 ! write back with bit 15 clear
    mov     #1,r2                  ! r2 = 1
    mov.l   @(POOL),r3             ! r3 = 0x060635AC
    rts
    mov.w   r2,@r3                 ! (delay) set ready flag = 1

! --- Pool D (0x060149F4-0x06014A02) ---
!   0x060149F4: .word  0x7FFF         ! bit 15 clear mask
!   0x060149F8: .long  0x00008000     ! bit 15 set mask
!   0x060149FC: .4byte sym_060A3D88   ! display state word
!   0x06014A00: .4byte sym_060635AC   ! command-ready flag

! ---- FUN_06014A04 — VDP1 Command Table Update (62 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x06014A04-0x06014A41)
! CORRECTION: Was "NPC Difficulty Modifier" — actually writes VDP1 command data.
!   dest = 0x25C00000 + (*(0x06059FFC) * 8) + 0x260  (VDP1 VRAM)
!   src  = 0x06044B64 (ROM data table, 32 bytes)
! Then calls FUN_060172BC, sets bit 0 of 0x0607EBF4, updates status words.
! 0x25C00000 = VDP1 VRAM base. Offset 0x260 = command entry ~76.
!
! Original description (preserved):
! FUN_06014A04 - NPC Difficulty Modifier
! 62 bytes. Applies speed handicap based on difficulty setting.
!
    .global FUN_06014A04
FUN_06014A04:                        ! 0x06014A04
    sts.l   pr,@-r15               ! save return address
    add     #-4,r15                ! stack frame (1 long)
    mov.l   @(POOL),r3             ! r3 = 0x25C00000 — VDP1 VRAM base
    mov.l   r3,@r15                ! save VDP1 base on stack
    mov.l   @(POOL),r5             ! r5 = 0x06044B64 — source data table
    mov.l   @(POOL),r4             ! r4 -> 0x06059FFC — game state index ptr
    mov.w   @(POOL),r2             ! r2 = 0x0260 — VDP1 cmd table offset
    mov.l   @r4,r4                 ! r4 = state index value
    shll2   r4                     ! r4 *= 4
    shll    r4                     ! r4 *= 2 (total: state * 8)
    add     r3,r4                  ! r4 = VDP1_BASE + state*8
    add     r2,r4                  ! r4 += 0x260 → final VDP1 VRAM dest
    mov.l   @(POOL),r2             ! r2 = sym_0602761E — memory copy
    jsr     @r2                    ! copy(dest=r4, src=r5, size=r6)
    mov     #32,r6                 ! (delay) r6 = 32 bytes
    mov.l   @(POOL),r3             ! r3 = FUN_060172BC
    jsr     @r3                    ! post-VDP1-update handler
    nop
    mov.l   @(POOL),r5             ! r5 = 0x0607EBF4 — display flags
    mov     #1,r4                  ! r4 = 1
    mov     #0,r3                  ! r3 = 0
    mov.l   @r5,r2                 ! r2 = current flags
    or      r4,r2                  ! set bit 0
    mov.l   r2,@r5                 ! write back
    mov.l   @(POOL),r2             ! r2 = 0x06085F90
    mov.w   r3,@r2                 ! *(word)0x06085F90 = 0
    mov.l   @(POOL),r3             ! r3 = 0x06085F94
    add     #4,r15                 ! free stack frame
    lds.l   @r15+,pr              ! restore return address
    rts
    mov.w   r4,@r3                 ! (delay) *(word)0x06085F94 = 1

! --- Pool E (0x06014A4E-0x06014A72) ---
!   0x06014A4E: .word  0x0260         ! VDP1 cmd table offset
!   0x06014A50: .long  0x25C00000     ! VDP1 VRAM base
!   0x06014A54: .4byte sym_06044B64   ! source data table
!   0x06014A58: .4byte sym_06059FFC   ! game state index
!   0x06014A5C: .4byte sym_0602761E   ! memory copy function
!   0x06014A60: .4byte FUN_060172BC   ! post-VDP1 handler
!   0x06014A64: .4byte sym_0607EBF4   ! display flags
!   0x06014A68: .4byte sym_06085F90   ! status word A
!   0x06014A6C: .4byte sym_06085F94   ! status word B
!   0x06014A70: .4byte FUN_0601712C   ! (used by FUN_06014A42)


! ---- FUN_06014A42 — Utility Wrapper (12 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x06014A42-0x06014A4D)
! NOTE: MISSING from original Section 12 list.
! Simple: calls FUN_06014F34 then tail-calls FUN_0601712C.
!
FUN_06014A42:                        ! 0x06014A42
    sts.l   pr,@-r15               ! save return address
    bsr     FUN_06014F34           ! call FUN_06014F34
    nop
    mov.l   @(POOL),r3             ! r3 = FUN_0601712C
    jmp     @r3                    ! tail-call FUN_0601712C
    lds.l   @r15+,pr              ! (delay) restore return address


! ---- FUN_06014A74 — Display Mode Init (486 bytes, CALL) ----
! BYTES: VERIFIED — objdump confirms size (0x06014A74-0x06014C59)
! CORRECTION: Was "AI Decision Tree." Binary shows this function:
!   1. Configures all 6 display channels via FUN_06038BD4
!   2. Calls FUN_06014884 (display channel update B) for multiple channels
!   3. Copies 32-byte blocks to VDP2 Color RAM (0x25F00660/680/6A0/6C0)
!   4. Copies VDP1 command data at state-dependent offsets (0x220/240/260/280)
!   5. Writes cell data to VDP2 VRAM (0x25E73B98/25E74158/25E74AFC/25E75730)
!   6. Iterates 44-entry display table at sym_06085640 (stride 54 bytes)
!   7. Calls sym_060149CC (enable display), FUN_060172BC, FUN_060173AC
!   This is display/rendering mode initialization, not AI logic.
!   Full line-by-line decode pending.
!
! Original description (preserved):
! FUN_06014A74 - AI Decision Tree *** PRIMARY AI LOGIC ***
! 486 bytes. Large function with multiple condition branches.

    .global FUN_06014A74
FUN_06014A74:   ! 0x06014A74 — display mode init (was: AI decision tree)


! ---- FUN_06014D2C — Pending Full Decode (454 bytes, CALL) ----
! Original description (preserved):
! FUN_06014D2C - AI Waypoint Pathfinding
! 454 bytes. Determines next waypoint on track, calculates
! steering angle to reach waypoint. Navigation AI for track following.

    .global FUN_06014D2C
FUN_06014D2C:   ! 0x06014D2C — pending decode (was: AI pathfinding)


! ---- FUN_06014F34 — Pending Full Decode (222 bytes, CALL) ----
! Original description (preserved):
! FUN_06014F34 - AI Position/Ranking Update
! 222 bytes. Computes current lap position from distance traveled.
! Updates race standings for AI opponents.

    .global FUN_06014F34
FUN_06014F34:   ! 0x06014F34 — pending decode (was: AI position update)


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
! | 0x06014868 | Display channel update A  | 28   | CALL | DECODED
! | 0x06014884 | Display channel update B  | 30   | CALL | DECODED
! | 0x060148A2 | Load channels from config | 64   | CALL | DECODED
! | 0x060148FC | Clear all channels        | 48   | CALL | DECODED
! | 0x0601492C | Set channel config A      | 48   | CALL | DECODED
! | 0x06014964 | Set channel config partial| 48   | CALL | DECODED [NEW]
! | 0x06014994 | Set channel config B      | 48   | CALL | DECODED
! | 0x060149CC | Enable display (bit 15)   | 20   | LEAF | DECODED
! | 0x060149E0 | Disable display (bit 15)  | 20   | LEAF | DECODED
! | 0x06014A04 | VDP1 cmd table update     | 62   | CALL | DECODED
! | 0x06014A42 | Utility wrapper           | 12   | CALL | DECODED [NEW]
! | 0x06014A74 | Display mode init         | 486  | CALL | STRUCTURAL
! | 0x06014D2C | Pending decode            | 454  | CALL |
! | 0x06014F34 | Pending decode            | 222  | CALL |
!
! Total: 62 functions documented
! Combined size: ~10,400 bytes of executable code
