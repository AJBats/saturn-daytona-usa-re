! ================================================
! AUDIT: MEDIUM — This is a high-level catalog of 72 functions. Most
!   FUN_ labels verified in binary. VDP1/VDP2 hardware address claims are
!   mostly correct but some register base addresses are swapped (see AUDIT
!   NOTEs). Function role descriptions are reasonable inferences from size
!   and position in the address space but many are speculative. FUN_0602D934
!   size (472B) verified. FUN_0602E892 size (1296B) verified.
! Audited: 2026-02-09
! ================================================
! =============================================================================
! VDP Scene Rendering Pipeline (0x0602C000-0x0602FFFF)
! =============================================================================
!
! 72 functions total, 56 previously unmapped
! VDP1/VDP2 rendering, vertex processing, scene composition
!
! ARCHITECTURE:
!   This range implements the Saturn's VDP1 sprite drawing and VDP2
!   background layer management. Functions operate on the VDP command
!   tables and transform vertices from 3D world space to 2D screen space.
!
!   Large functions (500B+) are main rendering passes:
!   - Scene traversal (object list iteration)
!   - Vertex transform (world->camera->screen)
!   - VDP1 command generation (sprite/polygon draw commands)
!   - VDP2 scroll plane updates (track surface, sky)
!
! =============================================================================
! FUNCTION CATALOG
! =============================================================================
!
! === Already Documented (in vertex_pipeline.s, render_pipeline.s) ===
! 16 functions documented in existing asm/ files
!
! === Vertex Transform Helpers ===
!
! CONFIDENCE: MEDIUM — Label likely exists. Clip flag role inferred from size.
! FUN_0602D89A (44B) - Vertex clip flag setter
! CONFIDENCE: MEDIUM — Label likely exists.
! FUN_0602D8C6 (94B) - Clip region test (4-plane frustum)
! CONFIDENCE: HIGH — Label confirmed. Size 472B verified (next: FUN_0602DB0C).
! FUN_0602D934 (472B) - Full vertex transform pipeline
!   World-to-screen transform: multiply by view matrix, perspective divide,
!   screen-space offset. Operates on vertex arrays.
!
! CONFIDENCE: MEDIUM — Label confirmed. Stub (rts;nop).
! FUN_0602DB0C (8B)  - Transform stub (rts;nop)
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602DB14 (14B) - Transform chain entry
!
! === VDP1 Command Builders ===
!
! CONFIDENCE: MEDIUM — Label needs verification.
! FUN_0602DC24 (12B)  - VDP1 command init
! CONFIDENCE: MEDIUM — Label needs verification.
! FUN_0602DC30 (56B)  - VDP1 normal sprite command
! CONFIDENCE: MEDIUM — Label needs verification.
! FUN_0602DC68 (312B) - VDP1 scaled sprite command
!   Builds VDP1 command table entry for scaled/rotated sprite
! CONFIDENCE: MEDIUM — Label needs verification.
! FUN_0602DDA0 (42B)  - VDP1 line draw command
! CONFIDENCE: MEDIUM — Label needs verification.
! FUN_0602DDCA (46B)  - VDP1 polyline command
! CONFIDENCE: MEDIUM — Label needs verification.
! FUN_0602DDF8 (42B)  - VDP1 polygon command (3-vertex)
! CONFIDENCE: MEDIUM — Label needs verification.
! FUN_0602DE22 (42B)  - VDP1 polygon command (4-vertex)
! CONFIDENCE: MEDIUM — Label needs verification.
! FUN_0602DE4C (22B)  - VDP1 end-of-list marker
!
! CONFIDENCE: MEDIUM — Label needs verification. Distorted sprite role inferred.
! FUN_0602DE62 (536B) - VDP1 distorted sprite command builder
!   Complex: handles texture UV mapping, gouraud shading setup,
!   color bank selection, priority bits. This is the main polygon
!   renderer for 3D car/track surfaces.
!
! === Scene Composition ===
!
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E07A (272B) - Scene object sorter (Z-sort for painter's algorithm)
!   Sorts draw commands by depth for correct overlap rendering
!
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E18A (138B) - Draw priority resolver
!   Handles special cases: cockpit always on top, sky always behind
!
! === VDP2 Background Layer Management ===
!
! CONFIDENCE: HIGH — Label confirmed. VDP2 register writers verified by
!   their tiny size (10-16 bytes) and writes to 0x25F80000+ range.
! FUN_0602E214 (12B)  FUN_0602E220 (12B)  - VDP2 register writers
! FUN_0602E22C (10B)  FUN_0602E236 (10B)  - VDP2 scroll position
! FUN_0602E240 (10B)  FUN_0602E24A (16B)  - VDP2 priority
! FUN_0602E25A (10B)  - VDP2 color offset
!   These tiny functions write single VDP2 registers.
!   VDP2 controls: scroll planes (NBG0-3), rotation scroll (RBG0/1)
!
! CONFIDENCE: HIGH — Label confirmed. VDP2 scroll plane setup inferred
!   from writes to VDP2 register space.
! FUN_0602E264 (124B) - VDP2 scroll plane setup
!   Configures NBG0-NBG3 for track surface, sky, HUD layer
!
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E2E0 (44B)  - VDP2 coefficient table loader
! FUN_0602E30C (20B)  - VDP2 coefficient stub
! FUN_0602E320 (12B)  FUN_0602E32C (12B)  - Coefficient helpers
! FUN_0602E338 (12B)  FUN_0602E344 (12B)  - Coefficient helpers
!
! === Rotation Scroll (Mode 7-like effect) ===
!
! CONFIDENCE: HIGH — Label confirmed. Rotation scroll interpretation
!   well-supported by coefficient computation pattern (Mode 7-like).
! FUN_0602E350 (222B) - RBG rotation matrix calculator
!   Computes rotation scroll coefficients for pseudo-3D ground plane
!   (the track surface that stretches to the horizon)
!
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E42E (52B)  - Rotation scroll parameter commit
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E462 (146B) - Rotation scroll interpolator
!   Smooths coefficient transitions between frames
!
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E4F4 (132B) - Rotation scroll vertical scaling
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E578 (164B) - Rotation scroll horizontal scaling
!
! === Color/Palette Management ===
!
! CONFIDENCE: MEDIUM — Label confirmed. Palette fade inferred.
! FUN_0602E61C (92B)  - Palette fade calculator
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E678 (18B)  - Palette commit stub
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E68A (20B)  - Color bank selector
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E69E (38B)  - Color offset animator
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E6C4 (80B)  - Full palette update
!
! === Lighting/Shading ===
!
! CONFIDENCE: SPECULATIVE — Label confirmed. Light direction is guess.
! FUN_0602E714 (18B)  - Light direction stub
! CONFIDENCE: SPECULATIVE — Label confirmed. Light intensity is guess.
! FUN_0602E726 (20B)  - Light intensity setter
! CONFIDENCE: MEDIUM — Label confirmed. Gouraud color inferred from size.
! FUN_0602E73A (46B)  - Gouraud color calculator
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602E768 (108B) - Per-vertex lighting
!   Calculates light intensity per vertex for gouraud shading
!
! CONFIDENCE: SPECULATIVE — Label confirmed. Shadow intensity is guess.
! FUN_0602E7D4 (82B)  - Shadow intensity calculator
!
! === Sprite/Billboard Rendering ===
!
! CONFIDENCE: SPECULATIVE — Label confirmed. Billboard role is guess.
! FUN_0602E826 (36B)  - Billboard facing calculator
! CONFIDENCE: SPECULATIVE — Label confirmed.
! FUN_0602E84A (38B)  - Billboard scale calculator
! CONFIDENCE: SPECULATIVE — Label confirmed.
! FUN_0602E870 (34B)  - Billboard UV mapper
!
! === Master Scene Renderer ===
!
! CONFIDENCE: HIGH — Label confirmed. Size 1296B verified
!   (FUN_0602E892 to FUN_0602EDA2 = 0x510 = 1296 bytes).
! FUN_0602E892 (1296B) - MAIN SCENE RENDER PASS
!   *** LARGEST FUNCTION IN THIS RANGE ***
!   Full scene rendering orchestrator:
!   - Iterates visible object list
!   - Calls vertex transform for each object
!   - Generates VDP1 commands
!   - Handles transparency sorting
!   - Manages VDP1 command table overflow
!   - LOD selection based on distance
!
! CONFIDENCE: MEDIUM — Label confirmed. Secondary pass role inferred.
! FUN_0602EDA2 (278B) - Secondary render pass
!   Renders transparent/additive objects after main pass
!
! === Track Surface Rendering ===
!
! CONFIDENCE: MEDIUM — Label confirmed.
! FUN_0602EFDA (22B)  - Track segment visibility check
! CONFIDENCE: SPECULATIVE — Label needs verification. Track rendering inferred.
! FUN_0602F214 (92B)  - Track segment renderer setup
! CONFIDENCE: SPECULATIVE — Label needs verification.
! FUN_0602F550 (102B) - Track polygon builder
!   Generates quad strips for road surface
!
! CONFIDENCE: SPECULATIVE — Label needs verification. Texture mapper inferred.
! FUN_0602F7F2 (426B) - Track texture mapper
!   UV coordinate generation for road textures
!   Handles mip-mapping (texture level selection by distance)
!
! CONFIDENCE: SPECULATIVE — Label needs verification. Track render inferred.
! FUN_0602F9A6 (1034B) - Full track render pipeline
!   Complete road surface rendering from segment data
!   Includes road markings, kerbs, rumble strips
!
! CONFIDENCE: SPECULATIVE — Label needs verification. Scenery renderer inferred.
! FUN_0602FDB0 (1314B) - Track scenery renderer
!   Renders roadside objects: signs, trees, buildings, barriers
!   Object instancing with per-course data tables
!
! =============================================================================
! KEY HARDWARE ADDRESSES
! =============================================================================
!
! AUDIT NOTE: VDP1 addresses below are swapped. VDP1 VRAM is at 0x25C00000,
!   VDP1 registers at 0x25D00000. Corrected:
! VDP1:
!   0x25C00000 - VDP1 VRAM (command tables + texture data)
!   0x25D00000 - VDP1 registers
! VDP2:
!   0x25E00000 - VDP2 VRAM (scroll data + coefficient tables)
!   0x25F80000 - VDP2 registers
!   0x25F00000 - VDP2 color RAM (palette data)
!
! =============================================================================
! EXTRACTION PRIORITY: LOW-MEDIUM
! =============================================================================
! Saturn-specific VDP rendering cannot be directly ported to CCE.
! However, the scene graph structure and object visibility logic
! may be reusable for understanding object relationships.
