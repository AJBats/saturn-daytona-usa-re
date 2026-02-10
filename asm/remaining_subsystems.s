! =============================================================================
! Remaining Subsystems - Closing All Coverage Gaps
! =============================================================================
!
! This file documents all remaining unmapped functions across:
! - Core game loop helpers (0x06007xxx, 0x06008-9, 0x0600A)
! - HUD/File loading (0x06010-13)
! - Object rendering (0x06020-27, 0x06028-2B)
! Total: 58 previously unmapped functions
!
! =============================================================================
! CORE GAME LOOP HELPERS (0x06007xxx) — 6 unmapped
! =============================================================================
!
! FUN_060072E6 (134B) - Frame buffer swap controller
!   Manages double-buffering for VDP1 frame buffer
!   Toggles between display and draw buffers each VBlank
!
! FUN_06007370 (268B) - Main loop frame timing
!   NTSC/PAL frame rate management (60fps/50fps)
!   Handles frame skip on lag
!   Reads VBlank counter from VDP2
!
! FUN_0600747C (476B) - System watchdog and error recovery
!   Monitors system health each frame
!   Resets subsystems on detected hang
!   Manages debug output (disabled in release)
!
! FUN_06007CEC (162B) - DMA queue manager
!   Queues DMA transfers for VDP1 command table updates
!   Prioritizes transfers by display deadline
!
! FUN_06007D8E (122B) - DMA queue commit
!   Triggers queued DMA transfers at VBlank
!
! FUN_06007E08 (1004B) - VBlank main handler
!   *** CRITICAL SYSTEM FUNCTION ***
!   Called every VBlank interrupt (60x/second):
!   - Updates controller state
!   - Commits VDP1 command list
!   - Swaps frame buffers
!   - Updates sound subsystem
!   - Increments frame counter
!   - Processes deferred events
!
! =============================================================================
! GAME STATE SUB-FUNCTIONS (0x06008-9) — 3 unmapped
! =============================================================================
!
! FUN_0600893C (220B) - State 2 extended handler
!   Extended version of transition stub (state 2)
!   Handles attract mode initialization:
!   - Loads demo replay data
!   - Sets camera to attract mode path
!   - Enables AI-only racing
!
! FUN_06008E48 (116B) - Pre-state-14 setup helper
!   Called by state 13 (race preparation)
!   Initializes race-specific variables:
!   - Lap counter = 0
!   - Position = starting grid slot
!   - Timer = race time limit
!   - Physics state = ready
!
! FUN_06009E60 (176B) - Post-state-27 handler
!   Cleanup after counter transition state
!   Handles return-to-menu flow:
!   - Frees course resources
!   - Resets display elements
!   - Transitions to state 30 (memory router)
!
! =============================================================================
! SCENE CAMERA HELPERS (0x0600A) — 2 unmapped
! =============================================================================
!
! FUN_0600A478 (50B) - Camera distance clamper
!   Prevents camera from getting too close/far from car
!   Min/max distance parameters from course data
!
! FUN_0600A614 (344B) - Camera collision avoidance
!   Prevents camera from going through track geometry:
!   - Ray-cast from car to camera position
!   - If intersection found, pulls camera closer
!   - Smooth recovery when obstruction clears
!
! =============================================================================
! HUD / FILE SYSTEM (0x06010-13) — 24 unmapped
! =============================================================================
!
! === HUD Element Controllers (0x06010xxx) ===
!
! FUN_060102EC (204B) - Speedometer controller
!   Reads car speed, converts to display units, drives gauge
!
! FUN_06010AA4 (176B) - Tachometer controller
!   Reads RPM, drives needle rotation
!
! FUN_06010F04 (400B) - Race position tracker
!   Calculates and displays current position among all cars
!   Updates position change events (+/- position flash)
!
! === HUD Rendering (0x06011xxx) ===
!
! FUN_060114B8 (166B) - HUD layer compositor
! FUN_060115F0 (136B) - HUD transparency handler
! FUN_060116BC (700B) - Main HUD draw call
!   Largest HUD function - orchestrates all elements
!
! FUN_0601198C (360B) - Split-screen HUD layout
!   Repositions all HUD elements for 2-player mode
!
! FUN_06011B08 (696B) - HUD damage/warning display
!   Shows damage indicators, overheat, tire wear
!
! === File I/O Helpers (0x06012xxx) ===
!
! FUN_06012054 (44B)  - File seek helper
! FUN_06012084 (28B)  - File size getter
! FUN_060120A0 (40B)  - File close handler
! FUN_060120CC (220B) - File read with callback
!   Async file read with completion callback
!
! FUN_0601228C (184B) - File decompress (LZ variant)
!   Decompresses loaded file data
!
! FUN_06012454 (184B) - File format parser
!   Parses structured game data files
!
! === Data Table Accessors (0x06012Axxx) ===
!
! FUN_06012AC4 (54B)  - Course data table lookup
! FUN_06012AFA (94B)  - Car parameter table lookup
! FUN_06012BE4 (88B)  - Track segment table lookup
!
! === Timing/Score (0x06013xxx) ===
!
! FUN_060138BE (138B) - Race timer formatter
!   Converts frame count to MM:SS:CC format
!
! FUN_06013948 (300B) - Score calculator
!   Calculates final score from: time, position, laps, bonuses
!
! FUN_06013A74 (144B) - Best time comparator
!   Checks if current time beats stored best
!
! FUN_06013B04 (284B) - Ranking point calculator
!   Awards ranking points based on difficulty and position
!
! FUN_06013C20 (56B)  - Bonus multiplier getter
! FUN_06013E14 (40B)  - Score commit to save data
! FUN_06013E7A (330B) - Full end-of-race scoring pipeline
!
! =============================================================================
! OBJECT/RENDER SYSTEM (0x06020-27, 0x06028-2B) — 23 unmapped
! =============================================================================
!
! === Object Management (0x06020xxx) ===
!
! FUN_060201B8 (204B) - Object pool allocator
!   Allocates game objects from fixed-size pool
!
! FUN_06020284 (172B) - Object pool deallocator
!   Returns object to pool, clears state
!
! FUN_06020330 (54B)  - Object type setter
! FUN_06020430 (132B) - Object initializer
!   Sets default values for new game object
!
! FUN_0602070C (264B) - Object update dispatcher
!   Calls per-type update function for each active object
!
! FUN_06020814 (306B) - Object culling pass
!   Determines which objects are visible this frame
!   Distance culling + frustum test
!
! FUN_06020950 (92B)  - Object LOD selector
!   Chooses detail level based on distance
!
! FUN_060209AC (428B) - Object animation driver
!   Advances animation frames for animated objects
!   Handles looping, blending, events
!
! FUN_06020B58 (118B) - Object collision box updater
!   Updates bounding boxes after position change
!
! FUN_06020D50 (128B) - Object state serializer
!   Packs object state for replay recording
!
! FUN_06020E84 (564B) - Object render setup
!   Prepares object for rendering:
!   - World matrix from position/rotation
!   - Material/texture binding
!   - Vertex buffer selection
!
! FUN_060210B8 (62B)  - Object cleanup
!
! === Scene Graph (0x06024-25) ===
!
! FUN_06024D14 (16B) - Scene node stub
! FUN_06024D24 (844B) - Scene graph traversal
!   Hierarchical scene traversal for rendering
!   Handles parent-child transform chains
!
! === Transform System (0x06027xxx) ===
!
! FUN_060279B0 (756B) - Complete transform pipeline
!   Model-to-screen transform for complex objects
!   Includes skinning for articulated models (car body parts)
!
! === Post-Processing / Effects (0x06028xxx) ===
!
! FUN_06028368 (28B)  - Effect init stub
! FUN_06028384 (182B) - Screen flash effect
!   Camera flash on impacts, start signal
!
! FUN_0602843A (128B) - Screen fade controller
!   Linear fade in/out with configurable duration
!
! FUN_060284BA (198B) - Motion blur effect
!   Speed-dependent screen blur
!
! FUN_06028580 (24B)  - Effect cleanup stub
! FUN_06028598 (188B) - Particle system manager
!   Tire smoke, sparks, exhaust particles
!
! === Large Rendering Functions (0x06029-2B) ===
!
! FUN_06029740 (4352B) - MEGA RENDER FUNCTION
!   *** ONE OF THE LARGEST IN THE BINARY ***
!   Complete object rendering pipeline for all 3 courses.
!   Course-specific object setup and rendering dispatch.
!   Handles: cars, track objects, scenery, dynamic elements
!
! FUN_0602A840 (900B) - Secondary render pass
!   Renders transparent objects, overlays, effects
!
! =============================================================================
! EXTRACTION PRIORITY
! =============================================================================
! - VBlank handler (FUN_06007E08): HIGH (core system timing)
! - State sub-functions: HIGH (game flow)
! - Camera collision (FUN_0600A614): HIGH (gameplay feel)
! - Object management: MEDIUM (reusable patterns)
! - HUD controllers: LOW (CCE has own HUD)
! - Effects: LOW (platform-specific)
! - Scene graph: MEDIUM (useful architecture reference)
