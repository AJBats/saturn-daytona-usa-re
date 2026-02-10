! =============================================================================
! AI Physics Pipeline & Object Transform (0x06034000-0x06037FFF)
! =============================================================================
!
! 160 functions total, 111 previously unmapped
! Mix of 3D object transforms, AI car updates, and peripheral I/O
!
! ARCHITECTURE:
!   This range implements the per-car physics dispatch for AI opponents.
!   Functions follow a chained-call pattern:
!     1. jsr @r0 (call a transform or physics function passed in r0)
!     2. dmuls.l (64-bit fixed-point multiply for position/velocity)
!     3. Read/write object struct fields at r14+offset
!     4. Fall through to next step or branch on conditions
!
!   Object struct access pattern:
!     r14 = object base pointer (typically car struct at 0x06078900+N*0x268)
!     +0x04 = Y position
!     +0x08 = Z position
!     +0x0C = heading angle
!     +0x10 = X velocity
!     +0x14 = Y velocity
!     +0x18 = Z velocity
!     +0x1C = X rotation
!     +0x20 = Y rotation
!     +0x24 = steering angle
!
!   Key external references:
!     0x06027344 = FUN_06027344 (3D position transform)
!     0x06027348 = FUN_06027348 (3D rotation apply)
!     0x0602755C = FUN_0602755C (3D perspective project)
!     0x06027EDE = FUN_06027EDE (3D lighting calc)
!     0x06083238 = Shared X position register
!     0x06083240 = Shared Y position register
!     0x06083244 = Shared Z position register
!     0x06006838 = Trig lookup dispatcher
!
! =============================================================================
! FUNCTION CATALOG
! =============================================================================
!
! === 3D Transform Chain (fall-through pipeline) ===
!
! FUN_06034036 (36B) - Phase 1: Position load
!   jsr @r0, store result in r12
!   Load object+0x20 into r11, dmuls.l r12*r11
!   Add object+0x14, store to object+0x04
!   Calls FUN_06027348 for rotation
!
! FUN_0603405A (102B) - Phase 2: Velocity integrate
!   jsr @r0, dmuls.l result * r11
!   Reads object+0x1C, adds integrated velocity
!   Stores to object+0x0C
!   Branch to FUN_0603410C if car_type==2
!   Otherwise reads object+0x24 (steering)
!
! FUN_060340C0 (14B) - Phase 3: Result store
!   jsr @r0, saves result r9
!   Passes r10 as r4, calls FUN_06027344
!
! FUN_060340CE (14B) - Phase 4: Perspective
!   jsr @r0, saves result r5
!   Passes r9 as r4, calls FUN_0602755C
!
! FUN_060340DC (66B) - Phase 5: Final integration
!   jsr @r0, dmuls.l for Z-axis
!   Reads object+0x18, adds, stores to object+0x08
!   Branches to FUN_0603413E (commit)
!
! FUN_0603411E (16B) - Phase 6: Lighting setup
!   jsr @r0, stores result in r4
!   Loads shared registers r5=0x06083238, r6=0x06083244
!   Calls FUN_06027EDE (lighting)
!
! FUN_0603412E (68B) - Phase 7: AI steering response
!   Reads object+0x24, applies steering deflection
!   Updates heading angle with damping
!
! === Per-Axis Update Blocks (repeated X/Y/Z pattern) ===
!
! FUN_06034172 (26B) FUN_0603418C (14B) FUN_0603419A (14B)
! FUN_060341A8 (10B) - X-axis velocity update group
!
! FUN_060341B2 (72B) - X-axis position integration with damping
! FUN_060341FA (26B) FUN_06034214 (20B) FUN_06034228 (14B)
! FUN_06034236 (10B) - X-axis cleanup
!
! FUN_06034240 (70B) - Y-axis position integration
! FUN_06034286 (26B) FUN_060342A0 (14B) FUN_060342AE (14B)
! FUN_060342BC (10B) - Y-axis cleanup
!
! FUN_060342C6 (72B) - Z-axis position integration
! FUN_0603430E (26B) FUN_06034328 (14B) FUN_06034336 (14B)
! FUN_06034344 (10B) - Z-axis cleanup
!
! === Angle/Rotation Update Blocks ===
!
! FUN_0603434E (24B) FUN_06034366 (34B) FUN_06034388 (14B)
! FUN_06034396 (14B) FUN_060343A4 (10B)
!   Heading angle update group - applies steering to heading
!
! FUN_060343AE (24B) FUN_060343C6 (34B) FUN_060343E8 (16B)
! FUN_060343F8 (14B) FUN_06034406 (10B)
!   Pitch angle update group - applies slope to pitch
!
! === AI Behavior Controller ===
!
! FUN_06034410 (236B) - AI decision maker
!   Complex function reading:
!   - Track segment data for current position
!   - Distance to next waypoint
!   - Speed differential with player
!   - Rubber-banding parameters
!   Outputs: target speed, target steering angle
!
! FUN_060344FC (42B) - AI speed limiter
!   Clamps AI car speed based on difficulty level
!
! FUN_06034526 (118B) - AI waypoint follower
!   Calculates steering angle toward next waypoint
!   Uses atan2-equivalent lookup for heading correction
!
! FUN_0603459C (28B) - AI collision avoidance trigger
! FUN_060345B8 (42B) - AI collision response
! FUN_060345E2 (16B) - AI reset stub
!
! === AI Car Spawn/Init ===
!
! FUN_060345F2 (80B) - AI car position initializer
!   Sets starting grid position based on car index
! FUN_06034642 (26B) FUN_0603465C (14B) FUN_0603466A (14B)
! FUN_06034678 (10B) - Spawn helpers
!
! FUN_06034682 (134B) - AI car full initialization
!   Sets initial speed=0, heading from grid slot, car type
!
! === AI Ranking/Position Tracking ===
!
! FUN_06034720 (8B)  - Rank stub
! FUN_06034728 (8B)  - Rank stub
! FUN_06034730 (50B) - Current position calculator
! FUN_06034762 (388B) - Full ranking system
!   Sorts all cars by track progress, assigns positions 1-8
!   Updates position display data
!
! === AI Race Logic ===
!
! FUN_060348E6 (26B)  - Lap completion check
! FUN_0603493A (34B)  - Checkpoint validator
! FUN_0603495C (40B)  - Section transition handler
! FUN_06034A9C (4B)   - NOP stub (rts;nop)
! FUN_06034AA0 (78B)  - AI pit stop logic (unused in Daytona?)
! FUN_06034B5C (62B)  - AI recovery from crash
! FUN_06034BA8 (160B) - AI drafting/slipstream calculator
! FUN_06034CCC (80B)  - AI brake zone calculator
! FUN_06034D20 (62B)  - AI throttle modulator
!
! === SMPC Peripheral Controller ===
!
! FUN_06034E20 (4B)   - NOP stub
! FUN_06034E24 (228B) - SMPC command sequence builder
!   Constructs SMPC command frames for controller polling
!
! FUN_06034F08 (2816B) - MAIN SMPC PERIPHERAL HANDLER
!   *** LARGEST FUNCTION IN THIS RANGE ***
!   Full Saturn peripheral controller implementation:
!   - Manipulates SR register interrupt mask (stc sr / ldc sr)
!   - Writes to SMPC ports: 0xFEE2, 0xFE60, 0xFE10
!   - Polls controller state (digital + analog)
!   - Debounce processing
!   - Multi-tap support
!   - Stores button state to 0x06063D9A (new presses), 0x06063D98 (held)
!   - Reads steering wheel analog input
!   NOTE: This is the ONLY SMPC handler in the binary.
!   Critical for input mapping in CCE transplant.
!
! FUN_06035A08 (512B) - Secondary input processor
!   Processes raw SMPC data into game-usable format
!   Maps physical buttons to game actions
!   Handles analog dead zones and calibration
!
! === Track Segment Helpers ===
!
! FUN_06036148 (42B) - Segment boundary check
! FUN_06036172 (70B) - Segment data loader
! FUN_060361B8 (4B)  - NOP stub
! FUN_060361BC (64B) - Segment interpolation
! FUN_06036208 (54B) - Segment curvature reader
! FUN_0603623E (10B) - Segment stub
! FUN_06036248 (96B) - Track bank angle calculator
! FUN_060362B0 (88B) - Road width calculator
!
! === Course-Specific Data Accessors ===
!
! FUN_06036308 (8B)   FUN_06036310 (112B)  FUN_06036388 (52B)
! FUN_060363C4 (80B)  FUN_06036424 (72B)   FUN_0603646C (12B)
! FUN_06036478 (92B)  FUN_060364DC (60B)   FUN_06036524 (78B)
! FUN_06036578 (76B)  FUN_060365D0 (62B)
!   Per-course track data readers. Each accesses different offsets
!   into course geometry tables (Three Seven / Dinosaur / Seaside).
!
! === Object Distance/Collision Helpers ===
!
! FUN_0603667E (10B)  - Distance stub
! FUN_06036688 (124B) - 3D distance calculator (fixed-point)
! FUN_06036704 (12B)  - Distance threshold check
! FUN_06036710 (58B)  - Bounding box overlap test
! FUN_0603674A (10B)  - Collision stub
! FUN_06036754 (88B)  - Collision normal calculator
! FUN_060367AC (8B)   - Collision stub
! FUN_060367B4 (52B)  - Impact force calculator
! FUN_060367F4 (72B)  - Collision response velocity
! FUN_06036848 (62B)  - Post-collision position adjust
!
! === Object Rendering Dispatch ===
!
! FUN_06036886 (10B)  FUN_06036890 (76B)  FUN_060368DC (8B)
! FUN_060368E4 (52B)  FUN_06036918 (16B)  FUN_06036928 (84B)
! FUN_0603698C (72B)  FUN_060369D4 (4B)   FUN_060369D8 (68B)
!   Object visibility check and render queue insertion.
!   Tests view frustum, distance culling, LOD selection.
!
! === Shadow/Effect Rendering ===
!
! FUN_06036A24 (48B) - Shadow projection
! FUN_06036A54 (8B)  - Shadow stub
! FUN_06036A5C (60B) - Ground shadow renderer
! FUN_06036AA4 (78B) - Dynamic shadow shape
! FUN_06036AF8 (108B) - Shadow color/alpha
! FUN_06036B64 (12B) - Effect stub
! FUN_06036B70 (54B) - Particle spawner
!
! === AI System Main Loop ===
!
! FUN_06036BA6 (566B) - AI master update loop
!   Iterates over all AI cars, calls physics pipeline for each
!   Manages AI state transitions (racing, crashed, recovering)
!   Updates positions, applies collisions
!   Called from main race loop (State 15)
!
! =============================================================================
! KEY DATA STRUCTURES
! =============================================================================
!
! 0x06078900 - Car object array base (40 cars * 0x268 bytes each)
! 0x06083238 - Shared X register (for cross-function parameter passing)
! 0x06083240 - Shared Y register
! 0x06083244 - Shared Z register
! 0x06063574 - SMPC callback pointer
! 0x06063D9A - New button presses (edge-triggered, per-frame)
! 0x06063D98 - Held button state
! SMPC ports: 0xFEE2, 0xFE60, 0xFE10 (hardware I/O)
!
! =============================================================================
! EXTRACTION PRIORITY: HIGH
! =============================================================================
! - AI behavior (FUN_06034410, FUN_06036BA6): CRITICAL for CCE
! - SMPC handler (FUN_06034F08): CRITICAL for input mapping
! - Track segment helpers: HIGH for course data integration
! - 3D transform chain: MEDIUM (CCE has own renderer but may reuse logic)
