! =============================================================================
! Track Geometry & Course Data System
! =============================================================================
!
! This file documents the track/course geometry pipeline — functions that
! construct track segments, manage road surfaces, handle terrain collision
! meshes, and load course-specific data from ROM.
!
! Address range: 0x06015000-0x0601A000 (primary)
!                0x0603449C-0x06034B9A (terrain collision mesh)
!
! The Saturn Daytona has 3 courses:
!   Course 0: Three Seven Speedway (Beginner, oval)
!   Course 1: Dinosaur Canyon (Advanced, technical)
!   Course 2: Seaside Street Galaxy (Expert, city)

! =============================================================================
! TRACK SEGMENT CONSTRUCTION (0x06016CDC-0x06017CEC)
! =============================================================================
!
! Track geometry is organized as a linked list of segments, each with a
! 0x44-byte (68-byte) stride containing position, rotation, and visual data.
!
! Core segment structure:
!   +0x00: Type/ID byte
!   +0x10: X position (32-bit fixed-point)
!   +0x14: Y position
!   +0x18: Z position
!   +0x1C: Rotation X
!   +0x20: Rotation Y
!   +0x24: Rotation Z
!   +0x30-0x38: Position variants (LOD/collision)
!   +0x40-0x41: Status flags

! FUN_06016CDC — Track segment initialization (228 bytes, 114 insns)
!   Initializes segment data from ROM with 0x44-byte stride.
!   Called during course loading.

! FUN_06016DD8 — Track vertex array builder (740 bytes, 370 insns)
!   MAJOR: Constructs vertex arrays for track display.
!   Reads segment data and generates renderable vertex lists for VDP1.
!   One of the largest track functions — processes entire visible track.

! FUN_06017814 — Track geometry processor with culling (718 bytes, 359 insns)
!   Processes track geometry with view frustum culling.
!   Determines which track segments are visible from current camera.
!   Uses distance-based LOD selection.

! FUN_06017CEC — Track state machine & animation (978 bytes, 489 insns)
!   LARGEST TRACK FUNCTION. Complex state machine that handles:
!   - Track segment animation (dynamic elements)
!   - State transitions during race
!   - Per-frame track updates

! FUN_060173AC — Geometry pipeline coordinator (794 bytes, 397 insns)
!   Coordinates the track geometry pipeline:
!   1. Segment selection (which segments to render)
!   2. Vertex generation (via FUN_06016DD8)
!   3. Culling (via FUN_06017814)
!   4. Submission to render queue

! FUN_06019928 — Track segment handler + physics init (252 bytes, 126 insns)
!   Handles track segment transitions and initializes physics
!   parameters for the current track section.


! =============================================================================
! TRACK SUPPORT UTILITIES (0x0601772E-0x06018634)
! =============================================================================

! FUN_0601772E — Track segment utility (86 bytes, 43 insns)
! FUN_06017784 — Geometry computation (134 bytes, 67 insns, LEAF)
! FUN_06017BF4 — Coordinate transform (94 bytes, 47 insns, LEAF)
!   Converts between world and track-local coordinates.
! FUN_06017C78 — Track data accessor (36 bytes, 18 insns, LEAF)
! FUN_06017C9C — Track state handler (56 bytes, 28 insns)
! FUN_06018166 — Geometry math (224 bytes, 112 insns, LEAF)
!   Pure math for track geometry calculations.
! FUN_06018278 — Track calculation (122 bytes, 61 insns)
! FUN_060185D8 — Track utility (92 bytes, 46 insns)
! FUN_06018634 — Data accessor (100 bytes, 50 insns, LEAF)


! =============================================================================
! VDP2 BACKGROUND CONFIGURATION (0x06015EB8-0x060171AC)
! =============================================================================
!
! VDP2 manages scrolling background layers. These functions configure
! scroll planes, tilemap pointers, and layer priorities for each course.

! FUN_06015EB8 — VDP2 layer initialization (226 bytes, 113 insns)
!   Sets up VDP2 scroll layers for the current course.
!   Configures tilemap base addresses in VDP2 VRAM.

! FUN_060171AC — VDP2 state handler (242 bytes, 121 insns)
!   Per-frame VDP2 updates — scroll offsets, layer enables.
!   Called from frame timing system (tail-called from FUN_06011DC0).

! FUN_0601712C — VDP2 utility loop (108 bytes, 54 insns)
! FUN_060172BC — VDP2 loop controller (40 bytes, 20 insns)
! FUN_060172E4 — Clear VDP2 registers (72 bytes, 36 insns, LEAF)
! FUN_06017330 — VDP2 data init (66 bytes, 33 insns, LEAF)
! FUN_06017372 — VDP2 lookup (50 bytes, 25 insns, LEAF)

! FUN_06018320 — Large VDP2 scroll register config (568 bytes, 284 insns)
!   Major VDP2 configuration function. Sets up all scroll plane
!   registers, layer priorities, and transparency modes.

! FUN_06018A3C — Large VDP2 configuration (648 bytes, 324 insns)
!   Extended VDP2 setup — handles all three courses' background
!   layer configuration with course-dependent parameters.


! =============================================================================
! THREE-COURSE PHYSICS INITIALIZATION (0x06019BC8-0x0601A5F8)
! =============================================================================
!
! Three identical-sized functions confirm the 3-course architecture.
! Each function initializes course-specific physics parameters:
! friction, gravity, traction, speed limits, etc.

! FUN_06019BC8 — Course 0 (Beginner) car physics init (282 bytes, 141 insns)
! FUN_06019DB8 — Course 1 (Advanced) car physics init (282 bytes, 141 insns)
! FUN_06019FB2 — Course 2 (Expert) car physics init (282 bytes, 141 insns)
!
! All three are exactly 282 bytes — they share the same structure
! but with different constant values for each course's physics model.
!
! Physics parameters initialized include:
!   - Road surface friction coefficients
!   - Gravity vector magnitude
!   - Maximum speed limits
!   - Cornering grip factors
!   - Acceleration curves

! FUN_0601A3F4 — Car physics finalization (328 bytes, 164 insns)
!   Post-init physics setup — connects car objects to track segments
!   and initializes runtime physics state.

! FUN_0601A65E — Car initialization handler (196 bytes, 98 insns)
!   Initializes car data structures for all 4 cars.

! FUN_0601A5F8 — Car data utility (22 bytes, 11 insns, LEAF)


! =============================================================================
! COURSE DATA LOADING (0x0601A80C-0x0601B0D8)
! =============================================================================
!
! Functions that load course-specific data from ROM/CD to work RAM.

! FUN_0601A940 — Course init pipeline (344 bytes, 172 insns)
!   Master course initialization — loads all data for selected course.

! FUN_0601A80C — Course data loader (264 bytes, 132 insns)
!   Loads course geometry from ROM addresses. Maps ROM offsets to
!   work RAM destinations for track data.

! FUN_0601ABC6 — Course setup handler (128 bytes, 64 insns)
! FUN_0601AC7C — Course configuration (248 bytes, 124 insns)
!   Per-course configuration of rendering and physics parameters.

! FUN_0601B0D8 — Course state setup (124 bytes, 62 insns)
! FUN_0601B074 — Setup handler (34 bytes, 17 insns)
! FUN_0601AE80 — Data handler (54 bytes, 27 insns)
! FUN_0601ADB0 — Pure math computation (124 bytes, 62 insns, LEAF)
! FUN_0601AE2C — Lookup function (38 bytes, 19 insns, LEAF)
! FUN_0601AEB6 — Trivial utility (18 bytes, 9 insns, LEAF)
! FUN_0601B09A — Data processor (44 bytes, 22 insns, LEAF)


! =============================================================================
! TERRAIN COLLISION MESH (0x0603449C-0x06034B9A)
! =============================================================================
!
! Low-level terrain collision detection — queries the track's
! collision mesh to determine surface properties at a given position.

! FUN_0603449C — Terrain collision mesh lookup (150 bytes, 75 insns)
!   Queries terrain mesh for collision data at a world position.
!   Returns surface normal, material type, friction.

! FUN_0603458C — Track segment accessor (122 bytes, 61 insns)
!   Retrieves track segment information for physics calculations.
!   Maps world position to nearest track segment.

! FUN_06034900 — Terrain data lookup (104 bytes, 52 insns)
!   Queries elevation and surface properties at given XZ coordinates.
!   Used for ground-clamping vehicles to track surface.

! FUN_06034AEE — Track intersection test (84 bytes, 42 insns)
!   Tests object position against track boundaries.
!   Detects when car leaves track surface.

! FUN_06034B54 — Mesh boundary check (70 bytes, 35 insns)
!   Validates object positions within track bounds.
!   Out-of-bounds detection for wall collisions.

! FUN_06034B9A — Road segment query (162 bytes, 81 insns)
!   Retrieves road surface information — traction and friction
!   properties that vary by track position (asphalt vs grass vs sand).


! =============================================================================
! TRACK OBJECT PLACEMENT (0x06021450)
! =============================================================================
!
! FUN_06021450 — Track object placement system (1447 insns, ~2894 bytes)
!   SECOND LARGEST function in the binary.
!   Reads 3D positions from ROM (base 0x00200000 + offset) and places
!   track-side objects (trees, signs, barriers, buildings) into the
!   game world with course-specific offsets.
!
!   Key data tables:
!     0x060897D0  Object type registry
!     0x0608962C  Object position table A
!     0x06089744  Object position table B
!     0x060895A0  Object attributes
!     0x060896B8  Object render parameters
!     0x06089D98  Object state table
!     0x060507A4  Object template data
!
!   ROM data loaded from:
!     0x00200000 + 0x37F08 (course 0 objects)
!     0x00200000 + 0x37F98 (additional objects)
!
!   Object structure (per object):
!     +0x00: X position (from ROM, negates Z)
!     +0x04: Y position
!     +0x08: Z position (negated from source)
!     +0x0C: Object type index
!     +0x10: Object state
!     +0x14: LOD level (word)
!
!   Calls FUN_06034FE0 for geometry transforms.
!   Course-dependent: checks 0x0607EAD8 for course index.


! =============================================================================
! FUNCTION HIERARCHY
! =============================================================================
!
! Course Loading Sequence:
!   1. FUN_0601A940 (course init pipeline)
!      -> FUN_0601A80C (load course data from ROM)
!      -> FUN_0601AC7C (configure course parameters)
!   2. FUN_06019BC8/06019DB8/06019FB2 (physics init per course)
!   3. FUN_0601A3F4 (physics finalization)
!   4. FUN_06021450 (place track objects)
!
! Per-Frame Track Rendering:
!   1. FUN_060173AC (geometry pipeline coordinator)
!      -> FUN_06016DD8 (build vertex arrays)
!      -> FUN_06017814 (cull invisible segments)
!   2. FUN_06017CEC (track state machine / animation)
!   3. FUN_060171AC (VDP2 background updates)
!
! Terrain Collision Query:
!   FUN_0603449C (mesh lookup)
!     -> FUN_0603458C (segment accessor)
!     -> FUN_06034900 (elevation query)
!     -> FUN_06034AEE (boundary test)
!     -> FUN_06034B9A (surface properties)
