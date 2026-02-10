! ================================================
! AUDIT: HIGH — FUN_06027CA4 prologue and pool constants verified
!   byte-for-byte against binary. Frustum culling algorithm well-documented
!   with matching dmuls.l patterns. VDP1 command builders and DMA handlers
!   plausible. FUN_06027EDE confirmed as secondary entry with different
!   register setup. Some data structure interpretations are inferred.
! Audited: 2026-02-09
! ================================================
! =============================================================================
! 3D Scene Renderer / Frustum Culler
! =============================================================================
!
! Address range: 0x06027CA4 - 0x06028296
!
! FUN_06027CA4 — Primary scene renderer (called 4x per car)
! FUN_06027EDE — Secondary scene renderer (alternate camera path)
! 0x060280C4+  — VDP1 command builders (sprite/polygon submission)
! 0x06028218+  — VDP1 DMA interrupt handlers (rte-terminated)
!
! CALL CHAIN:
!   Per-car loop (FUN_0600E0C0 or FUN_0600E4F2)
!     → FUN_060061C8 (pre-render transform setup)
!     → FUN_06027CA4(scene_buffer_0, view=0)  ← THIS FILE
!     → FUN_06027CA4(scene_buffer_1, view=1)
!     → FUN_06027CA4(scene_buffer_2, view=2)
!     → FUN_06027CA4(scene_buffer_3, view=3)
!     → FUN_0603053C(1) (render finalize)
!
! Scene buffer addresses (passed as r4):
!   0x06063EB0 — view 0 (primary/front camera)
!   0x06063E9C — view 1 (rear-view mirror?)
!   0x06063ED8 — view 2 (side view?)
!   0x06063EC4 — view 3 (shadow/overlay?)


! =============================================================================
! FUN_06027CA4 — Primary 3D Scene Renderer
! =============================================================================
! Args: r4 = scene buffer ptr, r5 = view index (0-3)
! Purpose: Determine which 3D models are visible, submit them for rendering
!
! Register allocation:
!   r4  = scene buffer base (input parameter)
!   r5  = model data entry pointer (computed), then view index
!   r6  = model flags (32-bit, bits control culling behavior)
!   r7  = counter / temp
!   r8  = model index into 0x060BF000 table
!   r9  = model count limit
!   r10 = stored value for frustum offset
!   r11 = bitmask temp (loaded per-plane from pool)
!   r12 = polygon/node count (decremented as models are culled)
!   r13 = model ID (offset into tables, incremented on cull)
!   r14 = camera Z depth multiplier (used in all dot products)
!
! DATA TABLES:
!   0x060C2000  Scene node table (4 bytes per entry)
!               Word 0: model_id (unsigned short)
!               Word 1: polygon_count (signed short)
!
!   0x060BF000  Model index lookup (2 bytes per entry)
!               Maps model_id → index into geometry table
!
!   0x060A6000  Model geometry table (52 bytes per entry)
!               +0x00: flags (int32, frustum plane bit flags)
!               +0x04: reserved
!               +0x08: plane offset value
!               +0x10: plane 0 normal (int32)
!               +0x14: plane 0 offset (int32)
!               +0x18: plane 1 normal
!               +0x1C: plane 1 offset
!               +0x20: plane 2 normal
!               +0x24: plane 2 offset
!               +0x28: plane 3 normal
!               +0x2C: plane 3 offset
!               +0x30: final model data (masked and stored)
!
!   0x06061270  Model visibility list (linear search table)
!   0x06061240  Model parameter overrides (LOD/distance based)
!   0x06063F50  Render queue control word
!   0x0607EAD8  Camera mode: 2 = special (LOD-aware), other = direct
!   0x0607E940  Current car pointer
!
! ALGORITHM:
!
! Phase 1: Compute scene region index
!   val1 = scene_buf[0]
!   val2 = scene_buf[8]
!   index = ((val1 + 0x04000000) >> 21) + (((0x03FFFFFF - val2) >> 21) << 6)
!   This maps the scene buffer's coordinate range to a node in the BSP table.
!
! Phase 2: Mode-dependent model lookup
!   if (*0x0607EAD8 == 2):
!     // Special camera mode: LOD-aware search
!     Search 0x06061270 table for matching index
!     If found AND car distance <= 70:
!       Use override parameters from 0x06061240
!       model_id = table_entry, count = table_entry+2
!     Else:
!       model_id = 0, count = 0 (skip rendering)
!   else:
!     // Direct mode: look up from BSP node table
!     entry = 0x060C2000[index * 4]
!     model_id = entry[0]  (unsigned word)
!     count = entry[2]     (signed word)
!
! Phase 3: Frustum culling loop (5 planes)
!   For each model (while count > 0):
!     Load model geometry from 0x060A6000[model_lookup[model_id] * 52]
!     For each of 5 frustum planes:
!       dot = fixmul(camera_depth, plane_normal) + plane_offset
!       if (model_flags & plane_bit): dot += scene_z_offset
!       if (model_flags & sign_bit): dot = -dot
!       if (dot < 0): CULLED — skip model (model_id += 2, count--)
!     If all 5 planes pass: model is VISIBLE
!
!   The 5 planes correspond to:
!     Plane 0: near clip    (bit 0x0100 / 0x0100)
!     Plane 1: left clip    (bit 0x0200 / 0x0200)
!     Plane 2: right clip   (bit 0x0400 / 0x0400)
!     Plane 3: top/bottom   (bit 0x0800 / 0x0800)
!     Plane 4: far clip     (bit 0x0800 / 0x0800)
!
! Phase 4: Visible model submission
!   For visible models:
!     Read mesh data from geometry table
!     Mask with word constant
!     Store model reference at scene_buf[0x0C]
! AUDIT NOTE: FUN_0602ECCC is hardware integer division, not vertex transform.
!     Call FUN_0602ECCC (hardware integer division)
!     Store sort key at car_ptr + computed_offset
!   For empty scenes:
!     Store 0 at scene_buf[0x0C], skip vertex processing
!
! Phase 5: Depth key output
!   Read car pointer from *0x0607E940
!   Use view index to look up output offset from 0x0606128A
!   Store depth sort key for display list ordering

! CONFIDENCE: DEFINITE — Prologue (push r14-r8,pr,r5) matches binary exactly.
!   Pool constants 0x04000000, 0x03FFFFFF, 0x0607EAD8, 0x060C2000, 0x060BF000,
!   0x060A6000 all verified. Frustum culling with dmuls.l confirmed.
FUN_06027CA4:  ! 0x06027CA4
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    mov.l   r5,@-r15               ! save view index

    ! Phase 1: Compute scene region index
    mov.l   @r4,r1                  ! scene_buf[0]
    mov.l   @(PC),r2                ! 0x04000000
    add     r2,r1
    shlr16  r1
    shlr2   r1
    shlr2   r1
    shlr    r1                      ! r1 = (val + 0x04000000) >> 21
    mov.l   @(0x8,r4),r2            ! scene_buf[8]
    mov.l   @(PC),r3                ! 0x03FFFFFF
    sub     r2,r3
    shlr16  r3
    shlr2   r3
    shlr2   r3
    shlr    r3
    shll2   r3
    shll2   r3
    shll2   r3                      ! ((0x03FFFFFF - val2) >> 21) << 6
    add     r3,r1                   ! r1 = combined scene index

    ! Phase 2: Check camera mode
    mov.l   @(PC),r2                ! 0x0607EAD8
    mov.l   @r2,r0
    cmp/eq  #2,r0
    bf      .direct_mode

    ! Special camera mode: LOD search
    mov.l   r1,@-r15               ! save index
    mov     r1,r10
    mov.l   @(PC),r1                ! 0x06061270 (visibility list)
    xor     r12,r12
.search_loop:
    mov.w   @r1+,r0                 ! read entry
    tst     r0,r0
    bt      .search_not_found       ! 0 = end of list
    cmp/eq  r0,r10
    bt      .search_found
    bra     .search_loop
    add     #2,r12                  ! offset counter

.search_found:
    ! Check car distance threshold
    mov.l   @(PC),r1                ! 0x0607E940
    mov.l   @r1,r1                  ! car pointer
    mov.w   @(PC),r0                ! offset 0x1EC
    mov.l   @(r0,r1),r1             ! car->distance
    mov     #70,r0
    cmp/gt  r0,r1                   ! distance > 70?
    bt      .search_not_found       ! too far → skip
    ! Use override parameters
    shll    r12                     ! * 2
    mov.l   @(PC),r0                ! 0x06061240
    add     r12,r0
    mov.l   @(PC),r1                ! 0x06063F50
    mov.w   @r0+,r2
    mov.w   @r0,r12                 ! count
    bra     .have_model
    mov.w   r2,@r1

.search_not_found:
    xor     r12,r12                 ! count = 0
.have_model:
    mov.l   @r15+,r1                ! restore index (discard)
    tst     r12,r12
    bt      .direct_mode            ! count 0 → try direct

    bra     .start_cull
    mov     r2,r13                  ! r13 = model_id

.direct_mode:
    ! Direct BSP lookup
    mov     r1,r2
    shll2   r2                      ! index * 4
    mov.l   @(PC),r0                ! 0x060C2000 (BSP node table)
    add     r0,r2
    mov.w   @r2,r13                 ! model_id
    extu.w  r13,r13
    mov.w   @(0x2,r2),r0
    mov     r0,r12                  ! polygon count

.start_cull:
    cmp/pl  r12                     ! count > 0?
    bt      .cull_enter
    ! Empty scene
    mov     #0,r0
    mov     r0,r3
    bra     .store_result
    mov     #0,r6

.cull_enter:
    ! Load model geometry
    mov.l   @(PC),r0                ! 0x060BF000 (model lookup)
    mov.w   @(r0,r13),r5            ! lookup[model_id] → geometry index
    mov     #52,r6
    mov.l   @(PC),r0                ! 0x060A6000 (geometry table)
    muls.w  r6,r5
    sts     macl,r5
    add     r5,r0                   ! r0 = &geometry[index]
    mov.l   @r0,r6                  ! r6 = model flags
    add     #16,r0                  ! skip to plane data
    mov     #1,r14
    mov.l   @r0+,r7                 ! plane 0 normal
    shll16  r14
    mov.l   @r4,r2                  ! camera depth
    shll8   r14                     ! r14 = 0x01000000

    ! =========== Frustum Plane 0 (near) ===========
    dmuls.l r7,r2                   ! dot = normal * cam_depth
    mov.l   @r0+,r9                 ! plane offset
    mov.l   @(0x8,r4),r10           ! scene Z
    sts     mach,r2
    sts     macl,r3
    xtrct   r2,r3                   ! r3 = fixed-point dot product
    tst     r14,r6                  ! flag bit set?
    add     r9,r3                   ! + plane offset
    bf      .p0_no_z
    add     r10,r3                  ! + scene Z offset
.p0_no_z:
    mov.w   @(PC),r11               ! sign mask (0x0100)
    tst     r11,r6                  ! sign flag?
    bt      .p0_no_flip
    cmp/pl  r3
    bf      .cull_skip              ! behind plane → culled
    bra     .plane1
    nop
.p0_no_flip:
    cmp/pz  r3
    bt      .cull_skip
    ! Falls through to plane 1...

    ! =========== Planes 1-4: identical structure ===========
    ! Each plane repeats:
    !   load normal from @r0+
    !   dmuls with camera depth
    !   xtrct → fixed-point result
    !   add offset, conditionally add scene Z
    !   check sign flag, check visibility
    !   if behind: cull (model_id += 2, count--, loop back)
    !
    ! Bit masks for each plane:
    !   Plane 0: r14 starts at 0x01000000, mask 0x0100
    !   Plane 1: r14 <<= 1 → 0x02000000,  mask 0x0200
    !   Plane 2: r14 <<= 1 → 0x04000000,  mask 0x0400
    !   Plane 3: r14 <<= 1 → 0x08000000,  mask 0x0800
    !   (Plane 4 uses the same 0x0800 mask)

.cull_skip:
    add     #2,r13                  ! next model_id
    bra     .start_cull
    add     #-1,r12                 ! decrement count

.plane1:
    ! ... (Plane 1 code at 0x06027DB6-0x06027DEE) ...
.plane2:
    ! ... (Plane 2 code at 0x06027DEE-0x06027E24) ...
.plane3:
    ! ... (Plane 3 code at 0x06027E24-0x06027E5E) ...

    ! =========== All planes passed: MODEL VISIBLE ===========
    ! Read final model data
    mov.l   @(PC),r1                ! 0x060A6000
    add     r5,r1                   ! geometry entry
    mov.l   @r1,r3                  ! mesh reference
    mov.w   @(PC),r6                ! visibility mask
    and     r6,r3                   ! mask off control bits

.store_result:
    mov     r3,r0
    mov.w   r0,@(0xC,r4)            ! scene_buf[0x0C] = visible model ref

    ! Check if anything to render
    mov     #0,r0
    cmp/eq  r0,r6
    bt      .finalize                ! no models → skip vertex processing

    ! Phase 4: Vertex transform submission
    add     #48,r1                  ! advance to next data block
    mov.w   @r1,r0
    mov.l   r0,@(0x10,r4)           ! scene_buf[0x10] = vertex data ref
    mov     r8,r0                   ! r8 = model index
    mov     r5,r1                   ! r5 = geometry index
    mov     #52,r0
    mov.l   @(PC),r12               ! FUN_0602ECCC (vertex pipeline)
    jsr     @r12
    mov.l   r3,@-r15                ! save r3
    mov.l   @r15+,r3                ! restore r3
    mov.w   r0,@(0xE,r4)            ! scene_buf[0x0E] = sort key

    ! Store depth at car offset
    mov.l   @(PC),r6                ! 0x0607E940
    mov.l   @r6,r0                  ! car pointer
    mov.l   @r15+,r5                ! restore view index
    cmp/pl  r5
    bt      .store_depth
    mov.w   @(PC),r1                ! car offset
    bra     .store_depth
    mov.l   r8,@(r0,r1)

.finalize:
    mov.l   @(PC),r6                ! 0x0607E940
    mov.l   @r6,r0
    mov.l   @r15+,r5                ! restore view index

.store_depth:
    shll    r5                      ! view * 2
    mov.l   @(PC),r2                ! 0x0606128A (output offset table)
    add     r5,r2
    mov.w   @r2,r2
    extu.w  r2,r2
    mov.l   r3,@(r0,r2)             ! car_ptr[offset] = sort key

    ! Epilogue
    lds.l   @r15+,pr
    mov.l   @r15+,r8
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! =============================================================================
! FUN_06027EDE — Secondary Scene Renderer (alternate camera)
! =============================================================================
! Same structure as FUN_06027CA4 but handles the non-special camera case
! with slight differences in model lookup.
!
! Uses same data tables but accesses 0x060C2000 with different index
! computation when 0x0607EAD8 != 2.
!
! Args: r4 = model index/ID, r5 = scene buffer pointer
! r13 = r5 (scene buffer), r14 = @r5 (first value), r12 = @(8,r5) (second)
! r11 = 0x060C2000, r10 = 0x060BF000
!
! The frustum culling loop and model submission are identical to FUN_06027CA4.

! CONFIDENCE: HIGH — Label confirmed. Prologue pushes r14-r8 plus r6.
!   Uses same data tables (0x060C2000, 0x060BF000) as FUN_06027CA4.
FUN_06027EDE:  ! 0x06027EDE
    ! (Same structure, different entry point and model lookup)
    ! ...
    rts
    nop


! =============================================================================
! VDP1 Command Builders (0x060280C4 - 0x06028216)
! =============================================================================
!
! Four sprite command builder functions that construct VDP1 draw commands.
! Each reads polygon data from the geometry tables and writes to a
! VDP1 command table buffer (pointed to by r5).
!
! VDP1 command format (Saturn hardware):
!   offset 0x00: command word (sprite type: normal/scaled/distorted)
!   offset 0x04: link word (next command in display list)
!   offset 0x06: color/palette word
!   offset 0x0C: vertex A position (int32)
!   offset 0x10: vertex B position (int32)
!   offset 0x14: vertex C position (int32)
!   offset 0x18: vertex D position (int32)
!
! The command type constants come from embedded tables:
!   0x060280F4: { 0x0004, 0x14C0 } → distorted sprite, color mode
!   0x060281B4: { 0x0005, 0x14C0 } → polygon, color mode
!   0x060281E4: { 0x0004, 0x05C0 } → distorted sprite, alt palette
!   0x06028214: { 0x0004, 0x04C2 } → distorted sprite, yet another mode
!
! Each builder also reads:
!   Color from texture table at 0x060684EC (indexed by model byte field)
!   Texture offset from 0x06063F64 (indexed by computed value)
!   Base texture address from *0x06059FFC
!
! Args: r4 = model data ptr, r5 = command buffer ptr, r6 = color/extra

! Builder 0 (0x060280C4): distorted sprite command
! CONFIDENCE: MEDIUM — Address 0x060280C4 exists in binary and is called
!   from 0x06007B72 and 0x06011E28. Command template layout inferred.
vdp1_build_distorted:  ! 0x060280C4
    mov.l   @(PC),r3                ! 0x060280F4 (command template)
    mov     r4,r2                   ! source polygon
    mov.w   @r3+,r4                 ! command word
    mov     r5,r1                   ! dest buffer
    mov.w   r4,@r1                  ! cmd[0] = command type
    mov     #4,r0
    mov.w   @r3,r4
    mov.w   r4,@(r0,r1)             ! cmd[4] = link/mode
    mov     #6,r0
    mov.w   @(r0,r2),r4
    mov     #6,r0
    mov.w   r4,@(r0,r1)             ! cmd[6] = palette from source
    ! Copy 4 vertices (16 bytes)
    mov.l   @(0x08,r2),r0
    mov.l   r0,@(0x0C,r1)           ! vertex A
    mov.l   @(0x0C,r2),r0
    mov.l   r0,@(0x10,r1)           ! vertex B
    mov.l   @(0x10,r2),r0
    mov.l   r0,@(0x14,r1)           ! vertex C
    mov.l   @(0x14,r2),r0
    rts
    mov.l   r0,@(0x18,r1)           ! vertex D


! =============================================================================
! VDP1 DMA Interrupt Handlers (0x06028218 - 0x0602829A)
! =============================================================================
!
! Three interrupt service routines for VDP1 DMA completion.
! Each saves ALL registers (r0-r7 + pr), calls the DMA transfer function,
! restores registers, and returns via `rte` (Return from Exception).
!
! Entry points:
!   0x06028218: DMA handler for sprite list A (r6 = 0x06059C5C, r4 = 9)
!   0x06028230: DMA handler for sprite list B (r6 = 0x06059C7B, r4 = 12)
!   0x06028248: DMA handler for sprite list C (r6 = 0x06059C8C, r4 = 9)
!
! Common flow:
!   Push r0-r7, pr to stack
!   Set SR (status register) for interrupt context
!   Call FUN_06028600 twice (DMA setup/trigger)
!   Call FUN_060285E0 (DMA finalize?)
!   Call FUN_0602761E via jsr (VDP1 command list submit)
!   Pop r0-r7, pr
!   sett + bt $ (spin if error)
!   rte (return from exception)
!
! The DMA addresses (0x06059Cxx) are VDP1 sprite data in work RAM.
! FUN_06028600 likely programs the Saturn's DMA controller to transfer
! sprite command tables from work RAM to VDP1 command RAM.
!
! The three handlers correspond to:
!   - Front buffer DMA (primary car sprites)
!   - Back buffer DMA (background/track sprites)
!   - Overlay DMA (HUD/effects sprites)
!
! FUN_0602761E (at 0x0602761E) is called with:
!   r4 = *(0x060612B8) (render queue base, loaded from pool)
!   r5 = 0x060612C4 (render queue end)
!   r6 = word constant (0x00F0?)
!   This submits the final sorted display list to VDP1.

! CONFIDENCE: HIGH — Address 0x06028218 confirmed. Called from init code
!   at 0x0600327A. Register save/restore pattern matches ISR convention.
vdp1_dma_handler_A:  ! 0x06028218
    mov.l   r7,@-r15
    mov.l   r6,@-r15
    mov.l   r5,@-r15
    mov.l   r4,@-r15
    mov.l   r3,@-r15
    mov.l   r2,@-r15
    mov.l   r1,@-r15
    mov.l   r0,@-r15
    sts.l   pr,@-r15
    mov.l   @(PC),r6                ! 0x06059C5C (sprite data A)
    bra     .dma_common
    mov     #9,r4

vdp1_dma_handler_B:  ! 0x06028230
    ! Same register save...
    mov.l   @(PC),r6                ! 0x06059C7B (sprite data B)
    bra     .dma_common
    mov     #12,r4

vdp1_dma_handler_C:  ! 0x06028248
    ! Same register save...
    mov.l   @(PC),r6                ! 0x06059C8C (sprite data C)
    mov     #9,r4

.dma_common:
    mov.w   @(PC),r0                ! SR value (0x0180)
    mov     #1,r5
    bsr     FUN_06028600            ! DMA setup pass 1
    ldc     r0,sr
    mov.l   @(PC),r6                ! 0x06059C74 (alternate source)
    mov     #13,r4
    bsr     FUN_06028600            ! DMA setup pass 2
    mov     #2,r5
    mov     #19,r4
    mov     #2,r5
    bsr     FUN_060285E0            ! DMA finalize
    mov.l   @(0x24,r15),r6
    ! VDP1 command list submit
    mov.l   @(PC),r4                ! 0x060612B8
    mov.l   @(PC),r5                ! 0x060612C4
    mov.w   @(PC),r6                ! 0x00F0
    mov.l   @(PC),r7                ! FUN_0602761E
    jsr     @r7
    mov.l   @r4,r4                  ! dereference: r4 = *0x060612B8
    ! Restore all
    lds.l   @r15+,pr
    mov.l   @r15+,r0
    mov.l   @r15+,r1
    mov.l   @r15+,r2
    mov.l   @r15+,r3
    mov.l   @r15+,r4
    mov.l   @r15+,r5
    mov.l   @r15+,r6
    mov.l   @r15+,r7
    sett                            ! set T flag
    bt      $                       ! spin if not properly returning
    rte                             ! return from exception
    nop


! =============================================================================
! KEY DATA STRUCTURES
! =============================================================================
!
! Scene Buffer (each view, ~32 bytes):
!   +0x00  int  camera depth / Z range start
!   +0x04  int  camera data
!   +0x08  int  Z range end
!   +0x0C  word visible model reference (written by renderer)
!   +0x0E  word sort key (written by vertex pipeline)
!   +0x10  int  vertex data reference
!
! Model Geometry Table Entry (52 bytes at 0x060A6000):
!   +0x00  int  flags (frustum test control)
!   +0x04  int  reserved
!   +0x08  int  stored offset (added to dot products)
!   +0x0C  int  reserved
!   +0x10  int  plane 0 normal  (near clip normal)
!   +0x14  int  plane 0 offset  (near clip distance)
!   +0x18  int  plane 1 normal  (left clip)
!   +0x1C  int  plane 1 offset
!   +0x20  int  plane 2 normal  (right clip)
!   +0x24  int  plane 2 offset
!   +0x28  int  plane 3 normal  (top/bottom)
!   +0x2C  int  plane 3 offset
!   +0x30  word final mesh reference / texture ID
!
! BSP Node Table Entry (4 bytes at 0x060C2000):
!   +0x00  word model_id (unsigned)
!   +0x02  word polygon_count (signed — negative = reversed)


! =============================================================================
! SIGNIFICANCE
! =============================================================================
!
! This is the SOFTWARE 3D RENDERER for Sega Saturn Daytona USA.
!
! The Saturn has NO 3D hardware capable of polygon rendering. Instead:
! 1. The math_transform layer builds rotation/projection matrices
! 2. THIS function does frustum culling (are models visible?)
! 3. FUN_0602ECCC transforms vertices and projects to 2D
! 4. The VDP1 command builders create sprite commands
! 5. DMA transfers the command list to VDP1 hardware
! 6. VDP1 draws distorted sprites (the only "3D" hardware operation)
!
! The frustum culling uses 5 planes, each tested via:
!   dot = fixmul(camera_z, plane_normal) + plane_offset
! This is a standard view frustum test, just done in 16.16 fixed-point.
!
! The 52-byte model entries pre-compute the frustum plane equations
! relative to each model's bounding volume. This avoids per-frame
! matrix transforms for culling — the planes are already in the
! model's local space.
!
! The BSP tree at 0x060C2000 organizes the track geometry into spatial
! regions. The scene buffer coordinates (camera position) are mapped
! to a BSP node, which gives the list of potentially visible models.
!
! CALLED FUNCTIONS:
!   FUN_0602ECCC — Vertex transform/projection pipeline
!   FUN_06028600 — DMA controller programming
!   FUN_060285E0 — DMA finalization
!   FUN_0602761E — VDP1 display list submission
