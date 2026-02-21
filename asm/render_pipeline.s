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
! SCENE COLOR MATRIX SETUP & RENDER TRIGGER (0x0603DDFC)
! =============================================================================
!
! CORRECTION (2026-02-20, L3 crossword uplift):
!   Original label "Master game state machine" / "LARGEST FUNCTION IN THE
!   BINARY" is WRONG on both counts:
!   1. It's 596B, not the largest (FUN_0602382C is 5352B)
!   2. It's not a game state machine — it's a scene color matrix initializer
!      that conditionally triggers downstream render processing.
!
!   Called from: menu_display.s scene data channel system
!     FUN_0603853C/FUN_06038642/FUN_06038794 tail-call FUN_0603DDFC(0,0,0)
!     when render dirty flags are set after scene data writes.
!
!   What it does:
!   1. Dispatches on channel ID from command slot (only handles 1/2)
!   2. Initializes a 36-byte scene buffer at sym_060A53B8[index*36] as a
!      3x3 identity color matrix: diag = 0x10000 (1.0), off-diag = 0
!   3. Checks render enable flags, accumulates config at sym_060A4C60[index]
!   4. Copies view colors from sym_060A3E68[index*8] offsets 76/80 into
!      the matrix diagonal
!   5. Tail-calls FUN_0603E050 or FUN_0603E5BC for downstream processing
!
!   Data structures:
!     sym_060A53B8 = scene color matrix buffer (36 bytes per scene × 2)
!       [0]=R scale, [4-12]=0, [16]=G scale, [20-28]=0, [32]=B scale
!     sym_060A4C60 = per-scene config accumulator (indexed by scene 0/1)
!     sym_060A4C68 = per-scene update accumulator (indexed)
!     sym_060A4C44 = per-scene primary enable (indexed)
!     sym_060A4C4C = per-scene secondary enable (indexed)
!     sym_060A4C70 = per-scene override disable (indexed)
!     sym_060A4C78 = per-scene render dirty flag (indexed)
!     sym_060A4C54 = per-scene dispatch selector (word, indexed)
!     sym_060A3E38+4 = scene enable flags (low byte=scene 0, high byte=scene 1)

! CONFIDENCE: HIGH — Label confirmed. AUDIT NOTE: Actual 596B/298 insns.
! FUN_0603DDFC — Scene color matrix setup (596B, CALL)
! BYTES: VERIFIED — objdump-checked against prod ELF (0x0603DDFC-0x0603E04F)
!
! Args: r4 = config delta, r5 = update delta, r6 = optional callback param
! Typically called with (0,0,0) from scene data channel invalidation.
!
FUN_0603DDFC:                            ! 0x0603DDFC
    mov.l   r14,@-r15                   ! save callee-saved registers
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    sts.l   pr,@-r15
    add     #-4,r15                     ! allocate 4-byte stack frame
    mov.l   @(POOL),r10                 ! r10 = &sym_060A53B8 (color matrix buffer base)
    mov.l   @(POOL),r11                 ! r11 = &sym_060A4C68 (update accumulator array)
    mov.l   @(POOL),r12                 ! r12 = &sym_060A4C60 (config accumulator array)
    mov     #0,r13                      ! r13 = 0 constant (used for clearing)
    mov.l   r6,@r15                     ! save r6 (callback param) on stack
    mov.l   @(POOL),r0                  ! r0 = &sym_060635A8 (command slot)
    bra     .cm_dispatch                ! jump to channel dispatch
    mov.l   @r0,r0                      ! (delay) r0 = channel_id
! ---- Channel 1 handler: scene index 0 ----
.cm_ch1:
    bra     .cm_init_matrix             ! go to matrix init
    extu.w  r13,r14                     ! (delay) r14 = 0 (scene index 0)
! ---- Channel 2 handler: scene index 1 ----
.cm_ch2:
    bra     .cm_init_matrix
    mov     #1,r14                      ! (delay) r14 = 1 (scene index 1)
! ---- No matching channel: early return ----
.cm_no_match:
    bra     .cm_epilogue                ! go to return
    nop
! ---- Channel dispatch ----
.cm_dispatch:
    cmp/eq  #1,r0                       ! channel 1?
    bt      .cm_ch1                     ! → scene A (index 0)
    cmp/eq  #2,r0                       ! channel 2?
    bt      .cm_ch2                     ! → scene B (index 1)
    bra     .cm_no_match                ! unhandled channel
    nop
! ---- Initialize 3x3 identity color matrix ----
! Buffer at sym_060A53B8[index * 36], 9 longwords:
!   [0]=1.0  [4]=0    [8]=0      ← R row
!   [12]=0   [16]=1.0 [20]=0     ← G row
!   [24]=0   [28]=0   [32]=1.0   ← B row
.cm_init_matrix:
    exts.b  r14,r6                      ! r6 = sign-extended index
    extu.w  r14,r2                      ! r2 = index
    mov.l   @(POOL),r7                  ! r7 = 0x10000 (1.0 in fp16.16)
    mov     r6,r3
    shll2   r2                          ! r2 = index * 4
    shll2   r6                          ! r6 = index * 4
    shll2   r3                          !
    shll2   r3                          ! r3 = index * 16
    shll    r3                          ! r3 = index * 32
    add     r3,r6                       ! r6 = index * 36 (struct stride)
    exts.b  r6,r6                       ! sign-extend offset
    add     r10,r6                      ! r6 = &color_matrix[index]
    ! -- Fill identity matrix --
    mov.l   r7,@r6                      ! [0] = 1.0 (R scale)
    mov.l   r13,@(4,r6)                ! [4] = 0
    mov.l   r13,@(8,r6)                ! [8] = 0
    mov.l   r13,@(12,r6)               ! [12] = 0
    mov.l   r7,@(16,r6)                ! [16] = 1.0 (G scale)
    mov.l   r13,@(20,r6)               ! [20] = 0
    mov.l   r13,@(24,r6)               ! [24] = 0
    mov.l   r13,@(28,r6)               ! [28] = 0
    mov.l   r7,@(32,r6)                ! [32] = 1.0 (B scale)
    ! -- Update config accumulator if scene enabled --
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C44 (primary enable base)
    add     r3,r2                       ! r2 = &enable[index]
    mov.l   @r2,r0                      ! r0 = primary enable for this scene
    tst     r0,r0
    bt      .cm_config_clear            ! not enabled → clear config
    extu.w  r14,r0
    shll2   r0
    mov.l   @(r0,r12),r3               ! r3 = current config[index]
    add     r4,r3                       ! r3 += r4 (config delta from args)
    mov.l   r3,@(r0,r12)               ! store updated config
    bra     .cm_update_accum
    nop
.cm_config_clear:
    extu.w  r14,r0
    shll2   r0
    mov.l   r13,@(r0,r12)              ! config[index] = 0 (disabled)
    ! -- Update accumulator and check further processing --
.cm_update_accum:
    extu.w  r14,r6
    shll2   r6
    mov     r6,r3
    add     r11,r3                      ! r3 = &update_accum[index]
    add     r12,r6                      ! r6 = &config[index]
    mov.l   @r3,r2
    add     r5,r2                       ! r2 += r5 (update delta from args)
    mov.l   r2,@r3                      ! store updated accumulator
    mov.l   @r6,r0                      ! r0 = config[index]
    tst     r0,r0                       ! config zero?
    bf      .cm_enable_flags            ! nonzero → process enable flags
    tst     r4,r4                       ! r4 (config delta) also zero?
    bt      .cm_enable_flags            ! both zero → skip enable flag update
    ! -- Modify scene enable flags based on channel --
    mov.l   @(POOL),r4                  ! r4 = &sym_060A3E38 (enable flags)
    mov.l   @(POOL),r0                  ! r0 = &sym_060635A8
    bra     .cm_flag_dispatch
    mov.l   @r0,r0                      ! (delay) r0 = channel_id
.cm_flag_ch1:                            ! Channel 1: clear low byte, keep high
    mov.l   @(POOL),r2                  ! r2 = 0xFF00
    mov.w   @(4,r4),r0                  ! r0 = enable_flags[4]
    mov     r0,r3
    and     r2,r3                       ! mask low byte (clear scene A bits)
    mov     r3,r0
    bra     .cm_flag_store
    nop
.cm_flag_ch2:                            ! Channel 2: clear high byte, keep low
    mov.w   @(4,r4),r0                  ! r0 = enable_flags[4]
    and     #255,r0                     ! mask high byte (clear scene B bits)
.cm_flag_store:
    bra     .cm_enable_flags
    mov.w   r0,@(4,r4)                 ! (delay) store modified enable flags
! Pool 1: sym_060A53B8, sym_060A4C68, sym_060A4C60, sym_060635A8,
!          0x10000, sym_060A4C44, sym_060A3E38, 0xFF00
.cm_flag_dispatch:
    cmp/eq  #1,r0
    bt      .cm_flag_ch1
    cmp/eq  #2,r0
    bt      .cm_flag_ch2
    ! -- Check callback parameter --
.cm_enable_flags:
    mov.l   @r15,r0                     ! r0 = saved r6 (callback param)
    tst     r0,r0
    bt      .cm_skip_callback
    bsr     FUN_0603EC40                ! call FUN_0603EC40(r4=callback_param)
    mov.l   @r15,r4                     ! (delay) r4 = callback param
    ! -- Check secondary enable / override --
.cm_skip_callback:
    extu.w  r14,r4
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C4C (secondary enable)
    shll2   r4
    add     r4,r3
    mov.l   @r3,r0
    tst     r0,r0                       ! secondary enable?
    bt      .cm_check_view              ! no → go check view
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C70 (override disable)
    add     r4,r3
    mov.l   @r3,r0
    tst     r0,r0
    bt      .cm_check_view              ! no override → check view
    extu.w  r14,r0
    shll2   r0
    mov.l   r13,@(r0,r12)              ! config[index] = 0 (override clears it)
    ! -- Check view struct for color data to copy --
.cm_check_view:
    mov.l   @(POOL),r5                  ! r5 = &sym_060A3E68 (scene view base)
    extu.w  r14,r4
    shll2   r4
    mov     r4,r3
    add     r12,r3                      ! r3 = &config[index]
    mov.l   @r3,r0                      ! config nonzero?
    tst     r0,r0
    bf      .cm_copy_colors             ! yes → copy colors to matrix
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C78 (dirty flags)
    add     r4,r3
    mov.l   @r3,r0                      ! dirty?
    tst     r0,r0
    bt      .cm_check_enable            ! not dirty → check enable flags
    ! -- Copy view colors into color matrix --
.cm_copy_colors:
    ! Compute: r6 = &color_matrix[index], r4 = &view_struct[index*8]
    exts.b  r14,r6
    extu.w  r14,r4
    mov     r6,r3
    shll2   r4
    shll2   r6
    shll2   r3
    shll2   r4                          ! r4 = index * 16
    shll2   r3                          ! r3 = index * 16
    shll2   r4                          ! r4 = index * 64
    shll    r3                          ! r3 = index * 32
    add     r3,r6                       ! r6 = index * 36
    exts.b  r6,r6
    add     r10,r6                      ! r6 = &color_matrix[index]
    shll    r4                          ! r4 = index * 128
    add     r5,r4                       ! r4 = &view_struct[index * 128]
    mov     #76,r0
    mov.l   @(r0,r4),r3                ! r3 = view[76] (color channel 1)
    mov.l   r3,@r6                      ! matrix[0] = color_1 (R diagonal)
    mov     #80,r0
    mov.l   @(r0,r4),r3                ! r3 = view[80] (color channel 2)
    mov.l   r3,@(16,r6)                ! matrix[16] = color_2 (G diagonal)
    bra     .cm_check_update_accum
    nop
! Pool 2: sym_060A4C4C, sym_060A4C70, sym_060A3E68, sym_060A4C78
    ! -- Not dirty: check enable flags for forced update --
.cm_check_enable:
    extu.w  r14,r4
    tst     r4,r4                       ! index == 0?
    bf      .cm_check_enable_ch2
    mov.l   @(POOL),r0                  ! r0 = &sym_060A3E3C (enable flags word)
    mov.w   @r0,r0
    extu.w  r0,r0
    tst     #255,r0                     ! low byte: scene 0 enable?
    bf      .cm_copy_colors_ext         ! has bits → go copy (extended path)
.cm_check_enable_ch2:
    mov     r4,r0
    cmp/eq  #1,r0                       ! index == 1?
    bf      .cm_check_update_accum      ! neither → skip
    mov.l   @(POOL),r2                  ! r2 = &sym_060A3E3C
    mov.l   @(POOL),r3                  ! r3 = 0xFF00
    mov.w   @r2,r2
    extu.w  r2,r2
    and     r3,r2                       ! high byte: scene 1 enable?
    tst     r2,r2
    bt      .cm_check_update_accum      ! no bits → skip
    ! -- Extended color copy: also writes to view struct backup offsets --
.cm_copy_colors_ext:
    ! Same matrix computation as .cm_copy_colors, plus:
    ! view[28] = view[76], view[44] = view[80] (backup copy)
    exts.b  r14,r6
    extu.w  r14,r4
    mov     r6,r3
    shll2   r4
    shll2   r6
    shll2   r3
    shll2   r4
    shll2   r3
    shll2   r4
    shll    r3
    add     r3,r6
    exts.b  r6,r6
    add     r10,r6
    shll    r4
    add     r5,r4
    mov     #76,r0
    mov.l   @(r0,r4),r3                ! view[76] → matrix[0]
    mov.l   r3,@r6
    mov     #80,r0
    mov.l   @(r0,r4),r3                ! view[80] → matrix[16]
    mov.l   r3,@(16,r6)
    mov     #76,r0
    mov.l   @(r0,r4),r3                ! view[76] → view[28] (color backup)
    mov.l   r3,@(28,r4)
    mov     #80,r0
    mov.l   @(r0,r4),r3                ! view[80] → view[44] (color backup)
    mov.l   r3,@(44,r4)
    ! -- Check update accumulator --
.cm_check_update_accum:
    extu.w  r14,r0
    shll2   r0
    mov.l   @(r0,r11),r3               ! r3 = update_accum[index]
    tst     r3,r3
    bt      .cm_final_check             ! zero → skip
    extu.w  r14,r0
    shll2   r0
    bsr     FUN_0603EACC                ! call FUN_0603EACC(r4=accum_value)
    mov.l   @(r0,r11),r4               ! (delay) r4 = update_accum[index]
    ! -- Final dispatch: choose render path --
.cm_final_check:
    extu.w  r14,r4
    shll2   r4
    mov     r4,r3
    add     r12,r3                      ! r3 = &config[index]
    mov.l   @r3,r0                      ! config nonzero?
    tst     r0,r0
    bf      .cm_dispatch_render         ! yes → dispatch to render
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C78
    add     r4,r3
    mov.l   @r3,r0                      ! dirty?
    tst     r0,r0
    bt      .cm_epilogue                ! not dirty → return (nothing to render)
    ! -- Choose between two render paths --
.cm_dispatch_render:
    extu.w  r14,r3
    mov.l   @(POOL),r2                  ! r2 = &sym_060A4C54 (dispatch selector)
    shll    r3
    add     r2,r3
    mov.w   @r3,r3                      ! selector word for this scene
    extu.w  r3,r3
    tst     r3,r3
    bt      .cm_render_path_B           ! selector == 0 → path B
    extu.w  r14,r3
    mov.l   @(POOL),r2                  ! r2 = &sym_060A4C4C (secondary enable)
    shll2   r3
    add     r2,r3
    mov.l   @r3,r0                      ! secondary enable?
    tst     r0,r0
    bt      .cm_render_path_A           ! no secondary → path A
    ! -- Render path A: tail-call FUN_0603E050 (color processing) --
.cm_render_path_A:
    extu.w  r14,r0
    shll2   r0
    mov.l   @(r0,r12),r4               ! r4 = config[index]
    add     #4,r15                      ! free stack frame
    lds.l   @r15+,pr
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    bra     FUN_0603E050                ! tail-call color processing (next function)
    mov.l   @r15+,r14                   ! (delay) restore r14
    ! -- Render path B: tail-call FUN_0603E5BC --
.cm_render_path_B:
    extu.w  r14,r0
    shll2   r0
    mov.l   @(r0,r12),r4               ! r4 = config[index]
    add     #4,r15
    lds.l   @r15+,pr
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    bra     FUN_0603E5BC                ! tail-call alternate render path
    mov.l   @r15+,r14
    ! -- Normal return --
.cm_epilogue:
    add     #4,r15                      ! free stack frame
    lds.l   @r15+,pr
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14
! Pool: sym_060A53B8, sym_060A4C68, sym_060A4C60, sym_060635A8, 0x10000,
!       sym_060A4C44, sym_060A3E38, 0xFF00, sym_060A4C4C, sym_060A4C70,
!       sym_060A3E68, sym_060A4C78, sym_060A3E3C, sym_060A4C54


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
!   FUN_0603DDFC (scene color matrix setup — NOT "master state machine")
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
! |  1   | FUN_0603DDFC |  596B |  298 | Scene color matrix     |
! |  2   | FUN_0602382C | 5352B | 2676 | Scene setup            |
! |  3   | FUN_06021450 | 3312B | 1656 | Track object placement |
! |  4   | FUN_06037660 | 2572B | 1286 | VDP1 command builder   |
! |  5   | FUN_0602BDD8 | 2232B | 1116 | Scene processing       |
! |  6   | FUN_0603268C | 1486B | 743  | Render orchestrator    |
! |  7   | FUN_0603A0B0 | 1508B | 754  | Game logic handler     |
! |  8   | FUN_060370E4 | 1404B | 702  | Texture management     |
! |  9   | FUN_0601C3E4 | 1014B | 507  | HW control dispatcher  |
! | 10   | FUN_06017CEC | 978B  | 489  | Track state machine    |
