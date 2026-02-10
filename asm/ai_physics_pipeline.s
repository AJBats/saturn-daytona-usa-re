! ============================================================
! AUDIT: HIGH
! 111 of 111 function addresses verified in aprog_syms.txt.
! All 111 function sizes verified correct against symbol table.
! 5 external reference addresses (0x06027344, 0x06027348, 0x0602755C,
! 0x0603410C, 0x0603413E) are valid code locations but lack function
! labels in the symbol table -- they are mid-function entry points.
! Data structure addresses (0x06078900, 0x06083238, etc.) all verified.
! Key issues: FUN_06027EDE mislabeled as '3D lighting calc' (it is a
! VDP/sprite rendering function), 0x06006838 mislabeled as 'Trig lookup
! dispatcher' (it is coordinate grid packing within FUN_060067C8), and
! FUN_06034410 described as 'AI decision maker' but is actually a
! dispatch stub + table initializer + distance calculator.
! Object struct offsets (r14+0x04..+0x24) conflict with standard layout
! documented elsewhere (X/Y/Z at +0x10/+0x14/+0x18) -- may indicate
! a different struct or different base pointer offset.
! ============================================================

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
! AUDIT NOTE FIXED: Object struct offsets below (+0x04..+0x24) differ from the
!   standard layout (X/Y/Z at +0x10/+0x14/+0x18) documented in subsystem_map.
!   This indicates either a different struct type or a shifted base pointer
!   (e.g., r14 points to struct+0x0C instead of struct base). The offsets
!   are verified from opcode inspection of FUN_06034036 and FUN_0603405A.
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
! AUDIT NOTE FIXED: 0x06027344, 0x06027348, 0x0602755C are valid code addresses
!   (confirmed as pool constant references in aprog.s) but are NOT function
!   labels in aprog_syms.txt. They are mid-function entry points within other
!   functions in the 0x06027xxx range.
!     0x06027344 = mid-function entry (3D position transform, no symbol)
!     0x06027348 = mid-function entry (3D rotation apply, no symbol)
!     0x0602755C = mid-function entry (3D perspective project, no symbol)
! AUDIT NOTE FIXED: FUN_06027EDE is a VDP/sprite rendering function, not
!   '3D lighting calc'. Verified: prologue pushes r14-r8+r6, loads 0x060C2000
!   (sprite defs), 0x060BF000 (sprite positions), checks car_count at 0x0607EAD8.
!     0x06027EDE = FUN_06027EDE (VDP/sprite rendering update)
!     0x06083238 = Shared X position register
!     0x06083240 = Shared Y position register
!     0x06083244 = Shared Z position register
! AUDIT NOTE FIXED: 0x06006838 is NOT a function label. It is a mid-function
!   entry point within FUN_060067C8 (0x060067C8-0x06006867) that performs
!   coordinate grid packing: packs world X/Z into a grid tile index via
!   (X+0x04000000)>>21 and (0x03FFFFFF-Z)>>21. NOT a 'Trig lookup dispatcher'.
!     0x06006838 = coordinate grid packing (within FUN_060067C8, no own symbol)
!
! =============================================================================
! FUNCTION CATALOG
! =============================================================================
!
! CONFIDENCE: HIGH
! All functions in the transform chain are real labels with correct sizes.
! The chained-call pattern (jsr @r0, dmuls.l, r14+offset) is confirmed
! from opcode inspection of FUN_06034036 and FUN_0603405A.
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
! AUDIT NOTE FIXED: 0x0603410C and 0x0603413E are not function labels.
!   0x0603410C is a branch target within FUN_060340DC (bt 0x0603410C at
!   0x0603407A, cross-function branch from FUN_0603405A).
!   0x0603413E is within FUN_0603412E (bra target from 0x060340F4).
!   These are intra-/cross-function branch targets, not function boundaries.
!   Branch to 0x0603410C if car_type==2
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
! AUDIT NOTE FIXED: FUN_06027EDE is VDP/sprite rendering, not lighting.
!   Calls FUN_06027EDE (VDP/sprite rendering)
!
! FUN_0603412E (68B) - Phase 7: AI steering response
!   Reads object+0x24, applies steering deflection
!   Updates heading angle with damping
!
! CONFIDENCE: HIGH
! All function addresses and sizes verified. X/Y/Z repeated pattern
! is a plausible description for this regular structure.
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
! CONFIDENCE: HIGH
! All function addresses and sizes verified.
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
! CONFIDENCE: MEDIUM
!
! AUDIT NOTE FIXED: FUN_06034410 starts with sts.l pr,@-r15 / jsr @r0 / nop /
!   lds.l @r15+,pr (dispatch stub), loads 0x06089EDC, then branches to
!   0x06034468. The body (0x0603446C+) loops over 5 entries at 0x06082A7C
!   stride 0x2C, zeroing byte at offset+0x26. Then checks car_type==2, loads
!   object fields, writes to shared registers 0x06083238, and computes distance
!   via dmuls.l. More accurately a dispatch stub + table initializer + distance
!   calculator. 'AI decision maker' with 'rubber-banding' was SPECULATIVE.
! FUN_06034410 (236B) - AI decision maker
!   Complex function reading:
!   - Track segment data for current position
!   - Distance to next waypoint
!   - Speed differential with player
!   - Rubber-banding parameters
!   Outputs: target speed, target steering angle
!
! CONFIDENCE: MEDIUM
! FUN_060344FC (42B) - AI speed limiter
!   Clamps AI car speed based on difficulty level
!
! CONFIDENCE: MEDIUM
! FUN_06034526 (118B) - AI waypoint follower
!   Calculates steering angle toward next waypoint
!   Uses atan2-equivalent lookup for heading correction
!
! CONFIDENCE: MEDIUM
! FUN_0603459C (28B) - AI collision avoidance trigger
! FUN_060345B8 (42B) - AI collision response
! FUN_060345E2 (16B) - AI reset stub
!
! CONFIDENCE: MEDIUM
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
! CONFIDENCE: MEDIUM
! === AI Ranking/Position Tracking ===
!
! FUN_06034720 (8B)  - Rank stub
! FUN_06034728 (8B)  - Rank stub
! FUN_06034730 (50B) - Current position calculator
! FUN_06034762 (388B) - Full ranking system
!   Sorts all cars by track progress, assigns positions 1-8
!   Updates position display data
!
! CONFIDENCE: MEDIUM
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
! CONFIDENCE: DEFINITE
! === SMPC Peripheral Controller ===
!
! FUN_06034E20 (4B)   - NOP stub
! FUN_06034E24 (228B) - SMPC command sequence builder
!   Constructs SMPC command frames for controller polling
!
! AUDIT NOTE FIXED: SMPC handler confirmed and verified. Opcodes: stc sr
!   (0x0002) at 0x06034F14, ldc sr (0x400E) at 0x06034F1C, pool constants
!   0xFEE2 at 0x06034F64, 0xFE60 at 0x06034F66. Pool ref 0x06063574 at
!   0x06034F48. This is the ONLY SMPC handler in the binary (2816 bytes).
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
! CONFIDENCE: HIGH
! FUN_06035A08 verified as 512B. Prologue pushes r14, macl, mach.
! FUN_06035A08 (512B) - Secondary input processor
!   Processes raw SMPC data into game-usable format
!   Maps physical buttons to game actions
!   Handles analog dead zones and calibration
!
! CONFIDENCE: MEDIUM
! All addresses and sizes verified. Functional descriptions are plausible
! but not individually confirmed from opcodes.
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
! CONFIDENCE: MEDIUM
! All addresses and sizes verified. Course name assignments (Three Seven /
! Dinosaur / Seaside) not individually confirmed.
! === Course-Specific Data Accessors ===
!
! FUN_06036308 (8B)   FUN_06036310 (112B)  FUN_06036388 (52B)
! FUN_060363C4 (80B)  FUN_06036424 (72B)   FUN_0603646C (12B)
! FUN_06036478 (92B)  FUN_060364DC (60B)   FUN_06036524 (78B)
! FUN_06036578 (76B)  FUN_060365D0 (62B)
!   Per-course track data readers. Each accesses different offsets
!   into course geometry tables (Three Seven / Dinosaur / Seaside).
!
! CONFIDENCE: MEDIUM
! All addresses and sizes verified. Functional descriptions (distance calc,
! bounding box, collision normal, impact force) are plausible.
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
! CONFIDENCE: MEDIUM
! === Object Rendering Dispatch ===
!
! FUN_06036886 (10B)  FUN_06036890 (76B)  FUN_060368DC (8B)
! FUN_060368E4 (52B)  FUN_06036918 (16B)  FUN_06036928 (84B)
! FUN_0603698C (72B)  FUN_060369D4 (4B)   FUN_060369D8 (68B)
!   Object visibility check and render queue insertion.
!   Tests view frustum, distance culling, LOD selection.
!
! CONFIDENCE: MEDIUM
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
! CONFIDENCE: MEDIUM
! FUN_06036BA6 size (566B) verified. Prologue confirmed: sts.l pr,
! add #-8 r15, calls FUN_06035E90 and FUN_06035C92 and FUN_06035EC8.
! 'Called from State 15' claim not individually verified.
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
! CONFIDENCE: HIGH
! All addresses verified as pool constant references in the binary.
! 0x06078900 appears 10+ times, 0x06083238 appears 3+ times,
! 0x06063D9A/0x06063D98 appear 3+ times each.
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
