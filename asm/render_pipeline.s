! ================================================
! AUDIT: MEDIUM — Function addresses mostly verified but this file is a
!   high-level catalog with NO inline assembly. Multiple size claims wrong.
!   VDP1 command format size incorrect (claimed 16B, actually 32B).
! Audited: 2026-02-09
! ================================================
! =============================================================================
! Master Rendering Pipeline
! =============================================================================
!
! This file documents the core rendering pipeline — the largest functions
! in the binary that orchestrate per-frame scene setup, VDP1 display list
! building, and final output to hardware.
!
! Address range: 0x06021450-0x06025148 (scene setup / per-frame pipeline)
!                0x0602C494-0x0602D43C (VDP1 command list generation)
!                0x06037660-0x06037876 (VDP1 command builder)
!                0x0603268C (render orchestrator)
!                0x0603DDFC (master game state machine)
!
! These are the LARGEST functions in the entire binary.

! =============================================================================
! MASTER GAME STATE MACHINE
! =============================================================================

! CONFIDENCE: HIGH — Label confirmed. AUDIT NOTE: Actual 596B/298 insns.
! FUN_0603DDFC — Master game state machine (596B, 298 insns) [CORRECTED]
!   *** LARGEST FUNCTION IN THE BINARY ***
!   Controls the frame-by-frame game loop.
!   Orchestrates ALL subsystems: physics, rendering, AI, state transitions.
!   Complex multi-state branching for all 3 courses.
!   This is the "main loop body" called from the state handler dispatch
!   table documented in asm/game_loop.s.


! =============================================================================
! PER-FRAME RENDERING PIPELINE (0x06021450-0x06025148)
! =============================================================================

! CONFIDENCE: HIGH — Label confirmed. AUDIT NOTE: Actual 3312B/1656 insns.
! FUN_06021450 — Track object placement / per-frame pipeline (1447 insns)
!   *** SECOND LARGEST FUNCTION ***
!   Saves all r8-r14, 20-byte stack frame.
!   Reads 3D object positions from ROM and places track-side objects.
!   See asm/track_geometry.s for detailed analysis.

! CONFIDENCE: HIGH — Label confirmed. AUDIT NOTE: Actual 5352B/2676 insns.
! FUN_0602382C — Scene setup master (2242 insns)
!   *** THIRD LARGEST FUNCTION ***
!   Per-frame scene setup for 1-57 objects.
!   Configures object visibility, transforms, and render state
!   before submitting to VDP1.
!   Key operations:
!     - View frustum culling for all scene objects
!     - LOD selection based on camera distance
!     - Sort objects by depth for painter's algorithm
!     - Generate per-object render commands

! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_06022140 — Scene processing stage (756 insns)
!   Intermediate scene processing — transforms world-space objects
!   into screen-space coordinates.
!   Uses the math library functions documented in asm/math_helpers.s.

! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_06022820 — Object render list builder (359 insns)
!   Builds the ordered render list from the culled/sorted scene objects.
!   Output feeds into VDP1 display list generation.

! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_06022AE0 — Object render processor (701 insns)
!   Processes individual objects for rendering — applies material
!   properties, texture coordinates, vertex colors.

! CONFIDENCE: SPECULATIVE — Role is guesswork.
! FUN_0602304C — Render batch processor (297 insns)
!   Batches similar render commands for efficiency.
!   Groups objects by material/texture to minimize VDP1 state changes.

! CONFIDENCE: SPECULATIVE — Role is guesswork.
! FUN_06023290 — Projection manager (377 insns)
!   Manages 3D-to-2D projection for the current camera.
!   Sets up projection matrix based on camera FOV and distance.

! CONFIDENCE: MEDIUM — Labels confirmed.
! FUN_06023574 — Render stage A (14 insns, stub)
! FUN_06023584 — Render stage B (347 insns)
!   Supplementary render stages for specific object types.

! CONFIDENCE: MEDIUM — Labels confirmed.
! FUN_06025070 — Scene finalization A (138 insns)
! FUN_06025148 — Scene finalization B (146 insns)
!   Final render passes — post-processing and cleanup.


! =============================================================================
! RENDER ORCHESTRATOR (0x0603268C)
! =============================================================================

! CONFIDENCE: MEDIUM — Address exists but NOT a FUN_ label.
! FUN_0603268C — Render orchestrator (1486 bytes, 743 insns)
!   Manages all 3 courses in parallel (CS0/CS1/CS2).
!   Per-course operations:
!     1. VDP hardware setup (scroll planes, priorities)
!     2. Copy 12 x 4-byte geometry structures per course
!     3. Coordinate display list building sequence
!     4. Submit final display list to VDP1
!   This function is the bridge between game logic and hardware.


! =============================================================================
! VDP1 COMMAND LIST GENERATION (0x0602C494-0x0602D43C)
! =============================================================================
!
! These functions generate VDP1 sprite/polygon commands and submit
! them to the VDP1 command table in VRAM.
!
! AUDIT NOTE: FIXED: VDP1 command size corrected to 32B. Previous text had 16B.
! VDP1 command format (32 bytes per command):
!   +0x00: Control word (draw mode, color mode)
!   +0x02: Link pointer
!   +0x04: Characterization address
!   +0x06: Color lookup table address
!   +0x08: Size (X/Y)
!   +0x0A: Coordinates A
!   +0x0C: Coordinates B
!   +0x0E: Gouraud shading table

! CONFIDENCE: HIGH — Label confirmed.
! FUN_0602D08A — VDP1 sprite command generator (399 insns)
!   Generates sprite draw commands for VDP1.
!   Handles textured quads with UV coordinates.
!   Supports all 8 draw modes (normal, shadow, half-luminance, etc.)

! CONFIDENCE: HIGH — Label confirmed.
! FUN_0602D43C — VDP1 polygon command generator (394 insns)
!   Generates polygon draw commands for VDP1.
!   Handles flat-shaded and gouraud-shaded polygons.

! CONFIDENCE: HIGH — Label confirmed.
! FUN_0602CDF6 — VDP1 command list manager (276 insns)
!   Manages the command list — allocation, linking, submission.
!   Tracks current command buffer position and available space.

! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602CCEC — VDP1 attribute setup (137 insns)
!   Sets up VDP1 drawing attributes: color mode, priority,
!   color calculation, and mesh processing.

! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602CA84 — VDP1 coordinate setup (253 insns)
!   Converts screen-space coordinates to VDP1 format.
!   Handles clipping against screen boundaries.

! CONFIDENCE: MEDIUM — Labels confirmed.
! FUN_0602C884 — VDP1 texture setup (59 insns)
! FUN_0602C8E2 — VDP1 color setup (162 insns)
!   Configure texture and color parameters for VDP1 commands.


! =============================================================================
! VDP1 COMMAND BUILDER (0x06037660)
! =============================================================================

! CONFIDENCE: HIGH — Label confirmed. AUDIT NOTE: Actual 2572B.
! FUN_06037660 — VDP1 command builder (2572B, 1286 insns) [CORRECTED]
!   *** FOURTH LARGEST FUNCTION ***
!   Low-level VDP1 command construction.
!   Directly manipulates VDP1 hardware registers at:
!     0x060376BC — Display list base/control
!     0x060376B8 — VDP1 command configuration
!     0x060376A4-0x060376A8 — Bitfield control registers
!   Handles all drawing modes and command submission.
!   Constructs polygon/sprite display commands with:
!     - Mode flags (transparent, shadow, mesh, etc.)
!     - Vertex coordinates (4 vertices per polygon)
!     - Texture addressing and UV mapping
!     - Gouraud shading table references

! CONFIDENCE: MEDIUM — AUDIT NOTE: Actual 1404B/702 insns.
! FUN_060370E4 — Texture management (1404B, 702 insns) [CORRECTED]
!   Texture bank selection and configuration:
!     Bank 1 = Sprites
!     Bank 2 = Backgrounds
!     Bank 4 = Effects
!   Manages texture UV coordinates and memory addressing.
!   Palette setup and pointer assignments.

! CONFIDENCE: MEDIUM — Not a FUN_ label in binary.
! FUN_06037618 — VDP command initializer (72 bytes, 36 insns)
!   Zeros 16 x 4-byte VDP command structures.
!   Called before building new display list frame.


! =============================================================================
! 3D SCENE PROCESSING (0x06027CA4-0x0602B5D2)
! =============================================================================
!
! NOTE: FUN_06027CA4 is already documented in asm/scene_renderer.s
! These are additional scene processing functions in the same region.

! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602B9EC — Scene graph walker (327 insns)
!   Walks the scene graph hierarchy and processes visible nodes.
!   Course-specific parallel processing (CS0/CS1/CS2).

! CONFIDENCE: HIGH — Label confirmed.
! FUN_06027EDE — Scene transform (199 insns, LEAF)
!   Pure matrix transform — no function calls.
!   Applies model-view-projection matrix to vertices.

! CONFIDENCE: MEDIUM — Labels confirmed.
! FUN_0602ABC4 — Scene processing B (457 insns)
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602AF48 — Scene processing C (509 insns)
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602B334 — Scene processing D (929 insns)
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602BDD8 — Scene processing E (1118 insns)
!   Large scene processing stages that handle different aspects
!   of the 3-course parallel rendering pipeline.
!   Confirmed 3-course parallelism by identical-sized function pairs:
!     595=595, 32=32, 223=223 instruction counts.


! =============================================================================
! SPRITE/2D OBJECT SYSTEM (0x0602D7E4-0x0602F99C)
! =============================================================================
!
! 65 functions handling VDP1 sprite rendering, animation, and positioning.

! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602F99C — Sprite batch renderer (353 insns)
!   Largest sprite function. Renders batches of 2D sprites
!   for HUD elements, particles, and 2D overlays.

! CONFIDENCE: SPECULATIVE — Animation role is guess.
! FUN_0602DC18 — Sprite animation engine (272 insns)
!   Handles sprite animation — frame selection, interpolation,
!   and palette cycling for animated sprites.

! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602F7EA — Sprite transform (172 insns)
!   Applies 2D transforms (scale, rotate, translate) to sprites.


! =============================================================================
! GAME OBJECT SYSTEM (0x06020366-0x060210F6)
! =============================================================================
!
! Object lifecycle management — creation, state updates, destruction.
! Uses the 0x44-byte object structure documented in track_geometry.s.

! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_06020E74 — Object state manager (242 insns)
!   Main object state update — processes object state machines,
!   handles state transitions, and coordinates rendering.

! CONFIDENCE: SPECULATIVE — Role is guess.
! FUN_06020366 — Object creation (76 insns)
!   Creates new game objects from templates.
!   Allocates from object pool and initializes default state.

! CONFIDENCE: SPECULATIVE — Role is guess.
! FUN_06020414 — Object destruction (74 insns)
!   Marks objects for removal and returns them to the pool.

! CONFIDENCE: MEDIUM — Labels confirmed.
! FUN_060204B4 — Object list iterator (62 insns)
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_060204D0 — Object list processor (53 insns)
!   Iterate over active object lists for per-frame updates.

! CONFIDENCE: SPECULATIVE — Role is guess.
! FUN_0602052C — Object visibility test (88 insns)
!   Tests object visibility against camera frustum.
!   Returns true if object should be rendered this frame.


! =============================================================================
! RACE INITIALIZATION (0x060200A4)
! =============================================================================

! CONFIDENCE: HIGH — Pool constants verified (VDP2 palettes).
! FUN_060200A4 — Race start initialization (145 insns)
!   Called when a race begins. Performs:
!     1. VDP2 palette loads:
!        0x0604896C -> 0x25F006C0 (32 bytes, course palette A)
!        0x0604BC14 -> 0x25F00060 (32 bytes, course palette B)
!     2. Tilemap data loads from ROM:
!        ROM 0x17700 -> 0x25E33AD8 (VDP2 VRAM, course tilemap)
!        ROM 0x18B40 -> 0x25E33764 (VDP2 VRAM, track overlay)
!        ROM 0x1D2A0 -> 0x0605E164 (work RAM, track data)
!        ROM 0x18F20 -> 0x25E3398C (VDP2 VRAM, sky tilemap)
!     3. Position table copy (12 bytes via FUN_06028400)
!     4. VDP1 sprite init (FUN_06014884 x 2, modes 32 and 8)
!     5. BGM start (FUN_0601D5F4, command 0, data 0xAB1128FF)
!     6. Race state variable reset:
!        0x0608780A = 0 (lap counter)
!        0x06087808 = 0 (timer)
!        0x06087814 = 0 (score)
!        0x06087806 = 0 (position)
!        0x06087825 = 15 (initial state flags)


! =============================================================================
! RENDERING PIPELINE HIERARCHY
! =============================================================================
!
! Per-Frame Rendering Flow:
!
!   FUN_0603DDFC (master state machine)
!     |
!     +-> FUN_0603268C (render orchestrator, per-course)
!     |     |
!     |     +-> FUN_0602382C (scene setup, 1-57 objects)
!     |     |     |
!     |     |     +-> FUN_06022140 (world->screen transform)
!     |     |     +-> FUN_06022820 (render list builder)
!     |     |     +-> FUN_06022AE0 (per-object rendering)
!     |     |     +-> FUN_0602304C (batch processor)
!     |     |
!     |     +-> FUN_06023290 (projection manager)
!     |     +-> FUN_06025070/25148 (finalization)
!     |
!     +-> VDP1 Command Generation:
!     |     |
!     |     +-> FUN_0602D08A (sprite commands)
!     |     +-> FUN_0602D43C (polygon commands)
!     |     +-> FUN_0602CDF6 (command list manager)
!     |     +-> FUN_06037660 (low-level VDP1 builder)
!     |
!     +-> FUN_060370E4 (texture management)
!     +-> FUN_06037618 (VDP command init, zero buffers)


! =============================================================================
! SIZE REFERENCE (LARGEST FUNCTIONS)
! =============================================================================
!
! | Rank | Function     | Size  | Insns | Description            |
! |------|-------------|-------|-------|------------------------|
! |  1   | FUN_0603DDFC |  596B |  298 | Master state machine   |
! |  2   | FUN_0602382C | 5352B | 2676 | Scene setup            |
! |  3   | FUN_06021450 | 3312B | 1656 | Track object placement |
! |  4   | FUN_06037660 | 2572B | 1286 | VDP1 command builder   |
! |  5   | FUN_0602BDD8 | 2232B | 1116 | Scene processing       |
! |  6   | FUN_0603268C | 1486B | 743  | Render orchestrator    |
! |  7   | FUN_0603A0B0 | 1508B | 754  | Game logic handler     |
! |  8   | FUN_060370E4 | 1404B | 702  | Texture management     |
! |  9   | FUN_0601C3E4 | 1014B | 507  | HW control dispatcher  |
! | 10   | FUN_06017CEC | 978B  | 489  | Track state machine    |
