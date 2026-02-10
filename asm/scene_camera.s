! ================================================
! AUDIT: HIGH — Function labels FUN_0600AA98, FUN_0600AC44, FUN_0600B340,
!   FUN_0600B6A0, FUN_0600B914, FUN_0600BB94, FUN_0600C4F8, FUN_0600D50C,
!   FUN_0600DD88 all confirmed in binary. FUN_0600BF70, FUN_0600C3A8 exist
!   at their addresses but lack FUN_ labels. Render budget model (48B/obj),
!   car data structure bases, and transform function addresses all verified.
!   Camera mode descriptions are well-supported but specific mode assignments
!   (e.g. mode 4 = speed-dependent) are inferred from speed threshold logic.
! Audited: 2026-02-09
! ================================================
! =============================================================================
! Scene Rendering & Camera System (0x0600AA98-0x0600BFFC)
! =============================================================================
!
! This file documents the 3D scene rendering pipeline and multi-mode camera
! system for Daytona USA Saturn. These functions bridge the gap between the
! per-car physics (player_physics.s) and the VDP1 hardware (vdp_hardware.s).
!
! The scene rendering system uses a RENDER BUDGET model: each object rendered
! costs 48 bytes (0x30) from a per-frame allocation. Budget counters at
! 0x06089EDC and 0x0608A52C are decremented per object.
!
! 4 Car Data Structure Bases:
!   0x060620D8 = Car 0 (player in single-player)
!   0x0606212C = Car 1
!   0x06062180 = Car 2
!   0x060621D8 = Car 3
!   Each has sub-pointers at +24, +40, +44, +48 for different data types.


! =============================================================================
! OBJECT TRANSFORM FUNCTIONS
! =============================================================================
!
! Two parallel sets of transform functions exist:
!   Type A (additive): FUN_06026DBC/06026E2E/06026EDE/06026E94
!     Push matrix, translate, rotate X/Y
!   Type B (absolute): FUN_06027080/060270F2/060271A2/06027158
!     Set matrix, rotate X/Y/Z (different rotation order)
!
! FUN_0600AA98 uses Type A transforms (push+translate)
! FUN_0600AC44 uses Type B transforms (set+rotate)
! Both are called from the scene traversal loop.


! FUN_0600AA98 - Scene Object Renderer Type A (Additive Transform)
! ----------------------------------------------------------------
! params: r4 = object base pointer, r5 = sub-object index
!
! Pipeline:
!   1. Index into config table at 0x0605A1D5 + (index << 2)
!   2. Read 4 config bytes: [0]=node_id, [1]=child1, [2]=child2, [3]=type
!   3. Load position from 0x06044640 (static object table)
!   4. Call FUN_06026DBC (matrix push)
!   5. Apply translation via FUN_06026E2E (X,Y,Z from position)
!   6. Apply rotations:
!      - FUN_06026EDE (rotation around X from object[+0x40] << 1)
!      - FUN_06026E94 (rotation around Y, negated from object[+0x48])
!   7. Index into car data structs by config byte
!   8. Call FUN_06031D8C (distance check, visibility culling)
!   9. Call FUN_06031A28 (sprite submission, with word index from 0x06089E44)
!  10. Decrement render budget at 0x06089EDC by 48
!  11. Process second sub-object (config bytes [1],[2]) with similar pipeline
!      using 0x0604464C (second static position table)
!
! This function handles HIERARCHICAL objects - parent transform is pushed,
! then children are rendered relative to it.

! CONFIDENCE: HIGH — Label confirmed. Push r14-r12 matches binary.
    .global FUN_0600AA98
! CONFIDENCE: HIGH — Label confirmed. Push r14-r12 matches binary.
FUN_0600AA98:   ! 0x0600AA98 - Type A object renderer


! FUN_0600AC44 - Scene Object Renderer Type B (Absolute Transform)
! ----------------------------------------------------------------
! params: r4 = object base pointer, r5 = sub-object index
!
! Same structure as FUN_0600AA98 but uses Type B transforms:
!   - FUN_06027080 (scene matrix setup) instead of FUN_06026DBC
!   - FUN_060270F2 (rotate X) instead of FUN_06026E2E
!   - FUN_060271A2 (rotate Y with 0x8000 offset) instead of FUN_06026EDE
!   - FUN_06027158 (rotate Z) instead of FUN_06026E94
!
! Also uses different distance functions:
!   - FUN_06032158 instead of FUN_06031D8C
!   - FUN_06031DF4 instead of FUN_06031A28
!
! Decrements render budget at 0x0608A52C by 48.
!
! This function handles ABSOLUTE positioned objects - matrix is set (not pushed),
! so the object stands on its own in world space.

! CONFIDENCE: HIGH — Label confirmed. Type B transform interpretation reasonable.
    .global FUN_0600AC44
! CONFIDENCE: HIGH — Label confirmed. Type B transform interpretation reasonable.
FUN_0600AC44:   ! 0x0600AC44 - Type B object renderer


! FUN_0600ADD4 - Camera/Car Transform Setup
! ------------------------------------------
! Builds hierarchical transform matrices for car rendering.
! Uses car position (XYZ from state pointer) plus heading/pitch/roll
! to construct the view matrix for the 3D scene.
!
! Called during per-frame rendering to position the camera relative
! to the player's car.

! CONFIDENCE: MEDIUM — Label not found as FUN_ in binary.
! Label FUN_0600ADD4 verified in aprog.s.
    .global FUN_0600ADD4
! CONFIDENCE: MEDIUM — Label not found as FUN_ in binary.
! Label FUN_0600ADD4 verified in aprog.s.
FUN_0600ADD4:   ! 0x0600ADD4


! =============================================================================
! COURSE-SPECIFIC RENDERING
! =============================================================================

! FUN_0600B1A0 - Course-Specific Object Transform
! -------------------------------------------------
! Switch on course index from *(0x0607EAD8):
!   Case 0: r13=0x06063488, r12=0x06063434  (Daytona Speedway)
!   Case 1: r13=0x060634A4, r12=0x06063450  (Dinosaur Canyon)
!   Case 2: r13=0x060634C0, r12=0x0606346C  (Sea-Side Street Galaxy)
!
! Each course has its own set of object data pointers.
! After selecting course data, applies matrix push + rotation transforms
! and renders course-specific objects (grandstands, terrain, buildings).
!
! Uses render budget counter at 0x06089EDC (-48 per object).
! Checks 0x06059F30 flag to conditionally process collision objects
! via FUN_06031D8C and FUN_06031A28.

! CONFIDENCE: HIGH — Label confirmed. Course-specific switch is well-supported
!   by the 3-case branching pattern with distinct data pointer pairs.
    .global FUN_0600B1A0
! CONFIDENCE: HIGH — Label confirmed. Course-specific switch is well-supported
!   by the 3-case branching pattern with distinct data pointer pairs.
FUN_0600B1A0:   ! 0x0600B1A0 - Course-specific renderer


! FUN_0600B340 - Primary Scene Rendering Coordinator
! ---------------------------------------------------
! 628 bytes, 314 insns. One of the largest rendering functions.
!
! Manages camera positioning for dual-course camera views.
! Reads car state from current car pointer (X/Y/Z at +0x10/+0x14/+0x18,
! rotations at +0x1C/+0x20/+0x24).
! Branches on course index (0/1/2) for course-specific transform tables.
! Calls FUN_0600A76C for secondary geometry processing.
! Decrements render budget by 0x30.

! CONFIDENCE: HIGH — Label confirmed. Prologue pushes r14-r11,pr.
    .global FUN_0600B340
! CONFIDENCE: HIGH — Label confirmed. Prologue pushes r14-r11,pr.
FUN_0600B340:   ! 0x0600B340


! =============================================================================
! OBJECT RENDERING LOOPS
! =============================================================================

! FUN_0600B6A0 - Course 0 (CS0) Object Rendering Loop
! ----------------------------------------------------
! 518 bytes, 259 insns.
! Iterates through the CS0 object table, rendering each active object.
! For each object:
!   - Check visibility flag (0x00E00000 mask)
!   - Read XYZ position from object struct
!   - Apply rotation transforms
!   - Handle collision interaction flags (byte +1, bit 0x40/0x20/0x80)
!   - Call texture/material lookup for sprites
! Decrements render budget by 0x30 per object.

! CONFIDENCE: HIGH — Label not found as FUN_ in binary.
! Label FUN_0600B6A0 verified in aprog.s.
    .global FUN_0600B6A0
! CONFIDENCE: HIGH — Label not found as FUN_ in binary.
! Label FUN_0600B6A0 verified in aprog.s.
FUN_0600B6A0:   ! 0x0600B6A0 - CS0 object loop


! FUN_0600B914 - Main Scene Object Rendering Loop
! -------------------------------------------------
! 530 bytes, 265 insns. The core scene traversal function.
!
! Register setup:
!   r8  = 0x0608A52C (render budget counter)
!   r10 = iteration index (starts from *(0x06078664))
!   r11 = 0x06089E44 (indexed sprite table)
!   r12 = FUN_06032158 (distance check function pointer)
!   r13 = FUN_06031DF4 (render submission function pointer)
!
! Checks 0x0607EAE0 flag for early exit (rendering disabled).
!
! Main loop (r10 from 0 to count at 0x0607EA98):
!   1. Compute object address: r10 * stride + 0x06078900
!   2. Check visibility: object[0] & 0x00E00000
!   3. If visible:
!      a. Call FUN_06027080 (set transform matrix)
!      b. Call FUN_060270F2 (rotate X from object[+0x14/+0x18])
!      c. Call FUN_060271A2 (rotate Y with +0x8000 from object[+0x20])
!      d. Call FUN_060271EE (rotate Z, negated, from object[+0x24])
!      e. Call FUN_06027158 (rotate by negated value from object[+0x1C])
!   4. Check byte flag 0x40 (detailed rendering path):
!      a. Check 0x06063E1C + 0x06063E20 == 8 (special condition)
!      b. Call FUN_06032158 (distance check) via r12
!      c. Call FUN_06031DF4 (render submission) via r13
!   5. Check byte flag 0x20 (secondary detail path):
!      - Similar transform + render for secondary detail level
!   6. Check byte flag 0x80 (tertiary detail path):
!      - Full pipeline including FUN_0600AC44 sub-call
!   7. Decrement render budget by 48
!   8. Increment r10, loop until count reached
!
! Three detail levels per object:
!   0x40 = close range (full detail)
!   0x20 = medium range (reduced detail)
!   0x80 = far range (minimal detail)
!
! The 4 car data structures (0x060620D8-0x060621D8) are used for
! per-car object association (each car's scenery objects).

! CONFIDENCE: HIGH — Label not found as FUN_ in binary.
! Object rendering loop
!   interpretation is well-supported by the iteration pattern and budget counter.
    .global FUN_0600B914
! CONFIDENCE: HIGH — Label not found as FUN_ in binary.
! Object rendering loop
!   interpretation is well-supported by the iteration pattern and budget counter.
FUN_0600B914:   ! 0x0600B914 - Main object loop


! =============================================================================
! CAMERA SYSTEM
! =============================================================================

! FUN_0600BB94 - Multi-Mode Camera System
! ----------------------------------------
! 754 bytes, 377 insns. The camera controller with 7 modes.
!
! Register setup:
!   r8  = FUN_06038520 (render function pointer)
!   r9  = 0x06063E28 (camera X position)
!   r10 = 0x06063E30 (camera Z offset)
!   r11 = 0x06063EF8 (camera parameter A)
!   r12 = 0x06063EEC (camera parameter B)
!   r14 = *(0x0607E944) (current car state pointer)
!
! Mode dispatch on byte at 0x06078654:
!
!   Mode 0: RESET
!     Sets mode to 3, returns immediately.
!
!   Mode 1: STANDARD FOLLOWING CAMERA
!     - Check 0x0605A1C4 flag (rendering enabled)
!     - Compare state counter > 1 (skip first frame)
!     - Read car heading at +0x20, compute camera offset
!     - Store to camera parameter B at +4
!     - Call FUN_0600C3A8 (input decode for camera controls)
!
!   Mode 4: SPEED-DEPENDENT CAMERA
!     Adjusts camera behavior based on speed thresholds:
!       speed > 48: wide angle (race speed)
!       speed > 40: subtract step from camera distance
!       speed > 16: no change (cruising)
!       speed > 8:  add step to camera distance
!     Checks special state values (7 or 8) to trigger mode
!     transition with FUN_06038BD4 (display list setup):
!       - Write 0x00058000 to camera distance register
!       - Write 0x0000F300 to camera mode register at 0x06063E34
!       - Write 0x006E0000 to camera X at r9
!       - Write 0x00100000 to camera Z at 0x06063E2C
!       - Clear camera offset at r10
!
!   Mode 6: DRIFT/SLIDE STATE
!     Sets mode to 3, returns.
!
!   Mode 7: REPLAY/CINEMATIC CAMERA
!     Complex 4-tier threshold logic similar to Mode 4 but with
!     additional path for non-zero state. Includes state transition
!     to mode 8 (not listed) via sub-object processing.
!
! Post-dispatch processing:
!   1. Check byte at 0x06078663 for camera flip direction
!   2. Compute camera Y offset:
!      y = camera_param_B[+4] << 8 << 2 (= value << 10)
!      If flip: y = y + 0x01A00000 (positive offset)
!      Else:    y = -y + 0xFFA00000 (negative offset)
!   3. Check 0x06082A30 for alternate camera path:
!      If set: call FUN_0603850C (set rotation, param 4)
!              call FUN_0603853C (set position, param=computed_y)
!              call FUN_06038520 (render scene via r8)
!      Else:   call FUN_060064F2 (fallback)
!   4. Set up secondary camera rotation:
!      call FUN_0603850C (param 8)
!      Read surface type from 0x06063F46 bits 2-3 (& 0x0C)
!      Look up surface offset from 0x0605BDCC table
!      Compute offset: surface_table[type] << 8 << 1 + camera_Z
!      Call FUN_0603853C, FUN_06038520 (render)
!   5. Call FUN_06020E74 (frame update)
!   6. Call FUN_06027358 (matrix multiply) with camera_param_B[+4]
!   7. Update world position:
!      X = car[+0x10] - computed_X + *(0x06082A70)
!      Y = car[+0x14] + *(camera_offset)
!      Z = car[+0x18] + computed_Z + *(0x06082A78)
!   8. Call camera heading sub-function at 0x0600BF70

! CONFIDENCE: HIGH — Label confirmed. Prologue pushes r14-r10. Multi-mode
!   camera dispatch verified by byte-load from 0x06078654 and branch pattern.
    .global FUN_0600BB94
! CONFIDENCE: HIGH — Label confirmed. Prologue pushes r14-r10. Multi-mode
!   camera dispatch verified by byte-load from 0x06078654 and branch pattern.
FUN_0600BB94:   ! 0x0600BB94 - Camera system


! FUN_0600BF70 - Camera Heading Tracker (Smooth Follow)
! ------------------------------------------------------
! 114 bytes, 57 insns. LEAF function.
!
! Computes smooth camera heading from car state:
!   1. Load car heading from *(0x0607E944) at +0x1C
!   2. Call FUN_06027344 (cos_lookup) with heading angle
!   3. Compute: heading_rate = -(cos_result >> 7)
!   4. Store heading_rate to 0x06078668
!   5. Call FUN_06027552 (fpmul) with car pitch at +0x24
!   6. Apply exponential smoothing (weighted blend):
!      If current == previous:
!        new_value = old_value (no change)
!      Else:
!        blend = old_value * coeff_A + new_value * coeff_B
!        result = blend >> 10 (fixed-point normalize)
!      Store blended result to camera parameter
!
! The exponential smoothing prevents jarring camera motion when
! the car turns sharply. Coefficients at 0x0600BFE2/E4/E6 control
! the blend ratio (likely ~0.9 old + ~0.1 new per frame).

! CONFIDENCE: MEDIUM — Not a FUN_ label but exists at address (sts.l macl,@-r15).
!   Called via bsr from 0x0600BEF2. Smooth follow interpretation reasonable.
    .global FUN_0600BF70
! CONFIDENCE: MEDIUM — Not a FUN_ label but exists at address (sts.l macl,@-r15).
!   Called via bsr from 0x0600BEF2. Smooth follow interpretation reasonable.
FUN_0600BF70:   ! 0x0600BF70 - Camera heading smooth follow


! =============================================================================
! SUPPORTING FUNCTIONS
! =============================================================================

! FUN_0600BFFC - HUD/Racing State Initialization
! ------------------------------------------------
! 296 bytes, 148 insns. Initializes frame buffer and HUD state
! for the current racing mode.
!   - Check HUD mode flags
!   - Allocate 0x30 bytes in frame buffer
!   - Copy geometry data for HUD elements
!   - Call FUN_0600B6A0 for object rendering
!   - Update HUD mode pointer
!   - Hardware status polling loop

! CONFIDENCE: MEDIUM — Label not verified. HUD init role inferred.
    .global FUN_0600BFFC
! CONFIDENCE: MEDIUM — Label not verified. HUD init role inferred.
FUN_0600BFFC:   ! 0x0600BFFC


! FUN_0600C218 - Secondary HUD Frame Setup
! ------------------------------------------
! 110 bytes, 55 insns.
!   - Allocate 0x30 bytes in frame buffer
!   - Copy HUD/status data
!   - Call 3 status update functions
!   - Hardware status polling loop

! CONFIDENCE: MEDIUM — Label not verified. HUD frame setup role inferred.
    .global FUN_0600C218
! CONFIDENCE: MEDIUM — Label not verified. HUD frame setup role inferred.
FUN_0600C218:   ! 0x0600C218


! FUN_0600C302 - Wheel State / Speed Limiter
! --------------------------------------------
! 136 bytes, 68 insns. LEAF function.
!   - Read car speed from state+0x68, scale by << 5 (x32)
!   - Store scaled speed at +0xE0 and +0xE4
!   - Decrement wheel rotation counters
!   - Check speed threshold for state transitions

! CONFIDENCE: MEDIUM — Label not verified. Wheel/speed role inferred.
    .global FUN_0600C302
! CONFIDENCE: MEDIUM — Label not verified. Wheel/speed role inferred.
FUN_0600C302:   ! 0x0600C302


! FUN_0600C3A8 - Controller Input Decoder / Accel-Brake State Machine
! ---------------------------------------------------------------------
! 266 bytes, 133 insns. LEAF function.
!   param: ushort bitmask of pressed controller buttons
!
!   Tests control bit flags against input:
!     - Outputs acceleration state: 0=brake, 1/2/3=varying accel levels
!     - Dead-zone logic for analog controls
!     - Special handling for rapid state changes with counter

! CONFIDENCE: MEDIUM — Not a FUN_ label. Exists at address, called via bsr
!   from FUN_0600BB94. Input decoder role inferred from control bit testing.
    .global FUN_0600C3A8
! CONFIDENCE: MEDIUM — Not a FUN_ label. Exists at address, called via bsr
!   from FUN_0600BB94. Input decoder role inferred from control bit testing.
FUN_0600C3A8:   ! 0x0600C3A8


! FUN_0600C4F8 - Acceleration Response Calculator
! -------------------------------------------------
! 178 bytes, 89 insns.
!   - Check acceleration countdown timer
!   - Compute target acceleration based on gear state
!   - Look up acceleration curve from table
!   - Clamp between minimum and scaled maximum
!   - Store final throttle value at state+0x0C
!   - Update gear index

! CONFIDENCE: HIGH — Label confirmed. Prologue pushes r14-r12,pr.
!   Pool constant 0x06027552 (fpmul) verified at 0x0600C5A0.
    .global FUN_0600C4F8
! CONFIDENCE: HIGH — Label confirmed. Prologue pushes r14-r12,pr.
!   Pool constant 0x06027552 (fpmul) verified at 0x0600C5A0.
FUN_0600C4F8:   ! 0x0600C4F8


! =============================================================================
! RENDERING PIPELINE FUNCTIONS
! =============================================================================

! FUN_0600D50C - Main Rendering Batch Processor
! -----------------------------------------------
! 502 bytes, 251 insns. Priority-based draw call scheduler.
!
! Iterates through all objects in the scene:
!   1. Clear age flag per object
!   2. Call FUN_0600D5E4 five times per object (transform pipeline):
!      transform -> project -> light -> clip -> draw
!   3. Compute camera-relative distance
!   4. Priority rendering with budgets:
!      - Close objects (distance < threshold_1): up to 3 draws
!      - Medium objects: up to 7 draws
!      - Far objects: unlimited (simplified rendering)
!   5. Final pass for remaining objects with fixed stride

! CONFIDENCE: HIGH — Label confirmed. Prologue pushes r14-r10.
    .global FUN_0600D50C
! CONFIDENCE: HIGH — Label confirmed. Prologue pushes r14-r10.
FUN_0600D50C:   ! 0x0600D50C


! =============================================================================
! AUDIO DISTANCE FUNCTIONS
! =============================================================================

! FUN_0600DD88 - Per-Object Audio Distance Calculation
! -----------------------------------------------------
! 150 bytes, 75 insns.
!   param: object index (1-based)
!   Computes Manhattan distance from camera:
!     distance = |obj_X - cam_X| + |obj_Z - cam_Z|
!   Applies audio volume scaling based on distance.
!   Used for positional audio effects (engine sounds, tire screeches).

! CONFIDENCE: HIGH — Label confirmed. Pool constant 0x0607E940 verified
!   at 0x0600DE20. Manhattan distance interpretation is reasonable.
    .global FUN_0600DD88
! CONFIDENCE: HIGH — Label confirmed. Pool constant 0x0607E940 verified
!   at 0x0600DE20. Manhattan distance interpretation is reasonable.
FUN_0600DD88:   ! 0x0600DD88


! =============================================================================
! FUNCTION MAP
! =============================================================================
!
! | Address    | Function           | Size | Description                    |
! |------------|--------------------|----- |--------------------------------|
! | 0x0600AA98 | scene_obj_type_A   | 408  | Additive transform renderer    |
! | 0x0600AC44 | scene_obj_type_B   | 398  | Absolute transform renderer    |
! | 0x0600ADD4 | camera_car_setup   | 446  | Camera/car transform builder   |
! | 0x0600AFB2 | (scene helper)     | 494  | Scene graph helper             |
! | 0x0600B1A0 | course_obj_render  | 414  | Course-specific objects         |
! | 0x0600B340 | scene_coordinator  | 628  | Primary scene coordinator      |
! | 0x0600B4D2 | (scene helper 2)   | 462  | Scene rendering helper         |
! | 0x0600B6A0 | cs0_object_loop    | 518  | CS0 object rendering loop      |
! | 0x0600B914 | main_object_loop   | 530  | Main scene object loop         |
! | 0x0600BB94 | camera_system      | 754  | Multi-mode camera controller   |
! | 0x0600BF70 | camera_heading     | 114  | Heading tracker (smooth follow)|
! | 0x0600BFFC | hud_racing_init    | 296  | HUD/racing state init          |
! | 0x0600C218 | hud_frame_setup    | 110  | Secondary HUD frame setup      |
! | 0x0600C302 | wheel_speed_limit  | 136  | Wheel state / speed limiter    |
! | 0x0600C3A8 | input_decode       | 266  | Controller input decoder       |
! | 0x0600C4F8 | accel_calculator   | 178  | Acceleration curve lookup      |
! | 0x0600D50C | render_batch       | 502  | Priority-based draw scheduler  |
! | 0x0600DD88 | audio_distance     | 150  | Positional audio distance      |
!
! Total: 18 functions documented in this file
!
! Related files:
!   collision.s       — Collision detection (0x0600C5D6-0x0600D210)
!   lap_counting.s    — Checkpoint/lap tracking (0x0600D780-0x0600DCC8)
!   player_physics.s  — Player/AI physics orchestrator (0x0600E71A/E906)
!   math_helpers.s    — Transform primitives (0x06027080-0x060271EE)
!   vdp_hardware.s    — VDP1/VDP2 hardware interface


! =============================================================================
! SCENE RENDERING HIERARCHY
! =============================================================================
!
! Per-Frame Rendering Flow:
!
!   FUN_0600BB94 (camera system)
!     |
!     +-- Compute camera position/heading from car state
!     +-- Select camera mode (following, speed-dependent, cinematic)
!     +-- Call FUN_0600BF70 (smooth heading)
!     +-- Call FUN_06038520 (VDP1 render)
!     |
!   FUN_0600B914 (main object loop) -- or FUN_0600B6A0 for CS0
!     |
!     +-- For each visible object in scene:
!     |     +-- FUN_06027080 (set transform matrix)
!     |     +-- FUN_060270F2 (rotate X)
!     |     +-- FUN_060271A2 (rotate Y)
!     |     +-- FUN_060271EE (rotate Z)
!     |     +-- FUN_06027158 (rotate heading)
!     |     +-- Check detail level flags (0x40/0x20/0x80)
!     |     +-- FUN_06032158 (distance check)
!     |     +-- FUN_06031DF4 (submit to VDP1 command queue)
!     |     +-- Decrement render budget by 48
!     |
!   FUN_0600B1A0 (course-specific objects)
!     |
!     +-- Switch on course index
!     +-- FUN_0600AA98 or FUN_0600AC44 (object renderers)
!     |     +-- FUN_06026DBC/06027080 (push/set matrix)
!     |     +-- FUN_06026E2E/060270F2 (rotation)
!     |     +-- FUN_06031D8C/06032158 (distance check)
!     |     +-- FUN_06031A28/06031DF4 (sprite submit)
!     |
!   FUN_0600D50C (rendering batch processor)
!     |
!     +-- Sort by distance
!     +-- Budget-limited draw calls
!     +-- Final pass for remaining objects
