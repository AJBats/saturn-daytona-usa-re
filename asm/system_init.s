! ================================================
! AUDIT: MEDIUM -- Function addresses verified; some hardware subsystem labels are inaccurate
! Audited: 2026-02-10
! ================================================
! =============================================================================
! System Bootstrap & Low-Address Utilities
! =============================================================================
!
! Address range: 0x06003218-0x06005DD4 (25 functions)
!
! This file covers the system bootstrap, hardware initialization,
! game data setup, and per-frame utility functions in the low-address range.
!
! These functions run at power-on (init) and every frame (update loop).

! =============================================================================
! HARDWARE INITIALIZATION (0x06003218-0x06003508)
! =============================================================================
! CONFIDENCE: MEDIUM -- All function addresses verified; hardware subsystem labels need correction
!
! Called once during power-on to configure Saturn hardware.

! CONFIDENCE: MEDIUM -- Address verified; calls through indirect ptr 0x06000310 with command 0x65
! AUDIT NOTE: NOT SCU registers. Addresses are work RAM (0x0600xxxx), not SCU (0x25FE0000+). Likely SCSP sound control via BIOS driver.
! FUN_06003218 — SCU register initialization (46 insns, LEAF)
!   Configures Sound Control Unit hardware registers.
!   Calls hardware function via PTR_DAT_060032c0 with command 0x65.
!   Bit-manipulates control registers at FE10, FE11, FE16, FE14
!   through AND/OR sequences to set up sound system control flags.

! CONFIDENCE: HIGH -- Address verified; command codes 4, 6, 9 plausible for VDP
! FUN_06003274 — VDP initialization dispatcher (31 insns, CALL)
!   Configures VDP rendering pipeline.
!   6 hardware command calls through indirect function pointer.
!   Command codes: 4, 6, 9 with paired render pointer arguments.
!   Sets up initial rendering mode.

! CONFIDENCE: HIGH -- Address verified; VDP-relative offsets confirmed
! FUN_0600330A — Advanced VDP initialization (44 insns, CALL)
!   Complex VDP setup with 3 repeated render calls through FUN_06003388.
!   Base addresses computed from data array plus dynamic offsets:
!     0x0D00, 0x0D80, 0x0370
!   Uses shll2 x3 + add 11 + shll for address computation.
!   Command code 0x0C (12).

! CONFIDENCE: HIGH -- Address verified; pool constants 0x25F00800, 0x25E34000 confirmed
! AUDIT NOTE: NOT SCU DMA. 0x25F00xxx/0x25E3xxxx are VDP2 VRAM/CRAM, not SCU DMA regs (0x25FE0000+). Should be VDP2 VRAM transfer.
! FUN_06003466 — SCU DMA init variant 1 (31 insns, CALL)
!   DMA setup for course 0 data.
!   Addresses: 0x25F00800, 0x25F00200, 0x25E34000, 0x25E4363C, 0x25E40000
!   Three transfer operations.

! CONFIDENCE: HIGH -- Address verified; same VDP2 transfer pattern
! AUDIT NOTE: Same mislabel -- VDP2 VRAM transfer, not SCU DMA.
! FUN_060034D4 — SCU DMA init variant 2 (41 insns, CALL)
!   DMA setup for course 1 data.
!   Addresses: 0x25F00940, 0x25E4EFEC, 0x25E42300, 0x25E42C78
!   Three transfer sequences.

! CONFIDENCE: HIGH -- Address verified; same VDP2 transfer pattern
! AUDIT NOTE: Same mislabel -- VDP2 VRAM transfer, not SCU DMA.
! FUN_06003508 — SCU DMA init variant 3 (31 insns, CALL)
!   DMA setup for course 2 data.
!   Same pattern as variants 1 and 2, course-specific addresses.


! =============================================================================
! GAME DATA INITIALIZATION (0x06003A3C-0x06004A98)
! =============================================================================
! CONFIDENCE: HIGH -- All addresses verified; function size estimates plausible

! CONFIDENCE: HIGH -- Address verified; many calls to FUN_06004F14 confirmed
! FUN_06003A3C — Master initialization dispatcher (~700+ bytes, CALL)
!   Orchestrates setup of ALL game entities and state structures.
!   Makes ~20+ calls to FUN_06004F14 with varying parameters
!   to set up courses, player objects, AI opponents, collision
!   data, and physics parameters.
!   Called once during power-on after hardware init.

! CONFIDENCE: MEDIUM -- Address verified; template interpretation speculative but consistent with init pattern
! FUN_06004670 — Object template initializer (500 insns, LEAF)
!   Pure computation. No external calls.
!   Initializes 12+ distinct object templates with:
!     - Rotation parameters (combinations of 1,2,3)
!     - Collision scaling: (0x40 - width*height) * 2
!     - Graphics/texture data references
!   Template structure (per object):
!     +0x00: graphics_pointer
!     +0x04: width_value
!     +0x06: height_value
!     +0x08: collision_scale = (0x40 - width*height) * 2
!     ...rotation params...
!   Objects: ground plane, track collision, vehicle, obstacles, pickups.

! CONFIDENCE: HIGH -- Address verified; large prologue pushing r14-r10,pr confirmed
! FUN_06004A98 — Global engine initialization (424 insns, CALL)
!   Large-scale system init coordinating multiple subsystems:
!     Graphics: color setup, VDP config
!     Sound: audio system init
!     Input: controller setup
!     SCU: command codes 0x40, 0x41
!     State machine: initializes 7 major state buffers
!     Render: layer buffer setup
!     DMA: memory buffer clearing
!   Called once at power-on.


! =============================================================================
! OBJECT TRANSFORM & PHYSICS SETUP (0x06004F14-0x0600508C)
! =============================================================================
! CONFIDENCE: MEDIUM -- Addresses verified; physics label is speculative

! CONFIDENCE: MEDIUM -- Address verified; called many times from FUN_06003A3C confirmed
! FUN_06004F14 — Object transform parameter cache (~100+ bytes, CALL)
!   Called ~20+ times from FUN_06003A3C with different params.
!   Sets per-object physics parameters (mass, friction, drag),
!   rotation matrices, or collision shapes.
!   r4=object_type, r5=course_id/parameter
!   Uses macl register for fixed-point math.

! CONFIDENCE: MEDIUM -- Address verified; uses macl for fixed-point math; calls FUN_06028654 confirmed
! FUN_06004F28 — Object position/state update (~200+ bytes, CALL)
!   Per-frame object position update with conditional physics.
!   Tests object state flags.
!   Uses macl register for fixed-point calculations.
!   Calls FUN_06028654 (DMA/memory transfer).
!   Handles signed position updates with conditional branching.

! CONFIDENCE: MEDIUM -- Address verified; coordinate update interpretation reasonable
! FUN_0600508C — Object coordinate setter (~150+ bytes, CALL)
!   Updates 3D object positions in game world.
!   Loads width/height from lookup tables via r11.
!   Performs sign-extension.
!   Writes updated coordinates to position arrays.


! =============================================================================
! MATH & COLLISION UTILITIES (0x06005120-0x0600553C)
! =============================================================================
! CONFIDENCE: HIGH -- Addresses verified; math function signatures clear from instruction sequences

! CONFIDENCE: MEDIUM -- Address verified; conditional dispatch confirmed
! FUN_06005120 — Hardware rendering dispatcher (~100 bytes, CALL)
!   Conditionally routes rendering commands based on hardware state.
!   Tests r7 bit mask against feature flags in r3.
!   If true: calls FUN_06028654 (DMA write path)
!   If false: calls FUN_06027630 (alternative path)
!   VDP command routing or double-buffer swap logic.

! CONFIDENCE: HIGH -- Address verified; dx/dz subtraction + sqrt + atan2 clearly a vector angle calc
! FUN_06005294 — 3D vector angle calculator (108 insns, CALL)
!   Computes relative distance & angle between two 3D points.
!   Parameters:
!     param_1: first 3D point (x, y, z)
!     param_2: second 3D point (x, y, z)
!     param_3: output (angle, magnitude)
!   Algorithm:
!     1. dx = param_2.x - param_1.x, dz = param_2.z - param_1.z
!     2. magnitude via FUN_060052F8 (sqrt)
!     3. Determine dominant axis (dz >= dx or dx > dz)
!     4. Call appropriate atan2 variant (FUN_06005380 or FUN_06005300)
!     5. Store results: angle in x, magnitude in z, 0 in y
!   Used for: AI targeting, collision checks, visibility tests.

! CONFIDENCE: MEDIUM -- Address verified; property writer label speculative
! FUN_06005494 — Object state property writer (~100 bytes, CALL)
!   Writes computed physics/position values to final output addresses.
!   Called as final step after position/collision calculations.
!   Conditional writes to alternative output addresses.

! CONFIDENCE: MEDIUM -- Address verified; table stride 0x28 confirmed
! FUN_0600553C — Sprite frame selector (50 insns, CALL)
!   Selects and sets up animation/sprite frames.
!   Parameters:
!     param_1: object ID (0-255)
!     param_2: comparison object ID (NULL for unconditional)
!   Animation table: 0x28 (40) bytes per entry.
!   Reads sprite frame pointer from table + 0x10.
!   Calls 4 setup functions for different frame aspects.


! =============================================================================
! GRAPHICS RENDERING (0x060055BC-0x0600579C)
! =============================================================================
! CONFIDENCE: HIGH -- Addresses verified; perspective math clear from fixed-point operations

! CONFIDENCE: HIGH -- Address verified; 0x10000 scaling factor confirms 16.16 fixed-point perspective
! FUN_060055BC — 3D perspective projection (199 insns, CALL)
!   Core perspective transform & camera projection pipeline.
!   Parameters: 4 values (3D coordinates + depth)
!   Loads camera transform matrix from viewport data.
!   Scales by 0x10000 for fixed-point 16.16 perspective.
!   3 matrix operation helper calls.
!   Returns screen-space coordinates.

! CONFIDENCE: HIGH -- Address verified; multi-phase graphics init confirmed
! FUN_06005788 — Background layer initializer (162 insns, CALL)
!   Initializes game background graphics for all 3 courses.
!   Phase 1: Load palette/metadata (command 0x08)
!   Phase 2: Copy texture data (21-byte chunks, triple word copy)
!   Phase 3: Conditional sprite/effect layer
!   Phase 4: Final background layer with computed offset:
!     (iVar10 * 0x40 + 0x16) * 2 where iVar10 = 4 or 6 per course

! CONFIDENCE: HIGH -- Address verified; pool data at 0x06085FF4 and 0x06063750 confirmed
! FUN_0600579C — VDP mode setup dispatcher (~300+ bytes, CALL)
!   Master graphics setup dispatcher.
!   Configures multiple rendering modes.
!   Manages palette, texture, sprite, and effect layers.
!   3+ rendering configurations based on mode flags.


! =============================================================================
! PER-FRAME UPDATE CHAIN (0x060058FA-0x06005DD4)
! =============================================================================
! CONFIDENCE: DEFINITE -- FUN_060058FA call chain verified byte-for-byte in binary
!
! Called every frame (60 fps) from the main game loop.
! FUN_060058FA is the entry point that dispatches to 4 subsystems.

! CONFIDENCE: DEFINITE -- All 4 call targets verified; 4th is tail-call via bra not bsr
! FUN_060058FA — Frame dispatcher (9 insns, CALL)
!   Simple sequential dispatch, no conditional logic:
!     1. FUN_06005C98 (world/camera state update)
!     2. FUN_06005A22 (input/event handler)
!     3. FUN_06005928 (animation/frame timing)
!     4. FUN_06005AE8 (display/rendering state)
!   Called 60x per second.

! CONFIDENCE: HIGH -- Address verified; counter decrement + conditional frame update confirmed
! FUN_06005928 — Animation frame counter (94 insns, CALL)
!   Manages animation timing and sprite frame selection.
!   Decrements animation counter at PTR_DAT_060059f0.
!   When counter reaches 0 AND animation enabled:
!     - Reads animation table pointer
!     - Loads frame index
!     - Calls frame update with command 0x08 and offset 0x78
!   Handles both active animation state (bit 1) and frame selection.

! CONFIDENCE: MEDIUM -- Address verified; input event handler label speculative; odd/even frame logic visible
! FUN_06005A22 — Input event handler (80 insns, CALL)
!   Processes input events with conditional rendering updates.
!   Decrements counter at PTR_DAT_06005ac4.
!   Odd frames: event trigger path (table offset 0x21)
!   Even frames: alternative rendering path
!   Updates input indicator sprites every 1-2 frames.

! CONFIDENCE: MEDIUM -- Address verified; complex renderer with feature flags; effect specifics speculative
! FUN_06005AE8 — Display compositor (166 insns, CALL)
!   Complex renderer managing display layer composition.
!   Loads 4 renderer function pointers.
!   Tests multiple feature flags:
!     - Scale mode (affects coordinate math)
!     - Extra layer enable
!     - Alternative offset table
!   Per enabled feature: perspective fixed-point scaling (0x10000).
!   Render offsets: 0x24 (Y), 0x30 (Z), 0x6C (effect layer).
!   Special effects: fade, overlay, checkerboard pattern.
!     Effect timer decrements by 3/frame until < 8.

! CONFIDENCE: MEDIUM -- Address verified; world/camera label speculative but plausible from call position
! FUN_06005C98 — World/camera state update (variable, CALL)
!   Updates global game state, camera position, world coordinates.
!   Reads controller input.
!   Updates player position in world.
!   Recalculates camera view matrix.
!   Updates viewport parameters.

! CONFIDENCE: MEDIUM -- Address verified; pool data at 0x06063E14 confirmed
! FUN_06005DD4 — Animation frame transform (variable, CALL)
!   Called from FUN_06005928 with animation index.
!   Returns transformed frame offset for rendering.
!   Table lookup or computed transform.


! =============================================================================
! INITIALIZATION SEQUENCE (POWER-ON)
! =============================================================================
!
!   1. FUN_06003218 (SCU hardware init)
!   2. FUN_06003274 (VDP init)
!   3. FUN_0600330A (advanced VDP)
!   4. FUN_06003466/060034D4/06003508 (DMA per course)
!   5. FUN_06003A3C (master object init)
!   6. FUN_06004670 (object templates)
!   7. FUN_06004A98 (global engine init)
!   8. FUN_0600579C (graphics mode setup)
!   9. FUN_06005788 (background init)
!
! PER-FRAME LOOP:
!   FUN_060058FA (dispatcher)
!     -> FUN_06005C98 (world update)
!     -> FUN_06005A22 (input events)
!     -> FUN_06005928 (animation timing)
!     -> FUN_06005AE8 (display composition)


! =============================================================================
! EXTRACTION PRIORITY FOR CCE TRANSPLANT
! =============================================================================
!
! | Priority | Component | Notes |
! |----------|-----------|-------|
! | LOW      | Hardware init (SCU/VDP/DMA) | CCE has own init |
! | LOW      | Background/graphics init | CCE has own renderer |
! | MEDIUM   | Object template init | Shared object layout? |
! | MEDIUM   | 3D vector angle calc | Reusable math utility |
! | HIGH     | Object transform/physics | Core position updates |
! | HIGH     | Per-frame update chain | Frame loop structure |

