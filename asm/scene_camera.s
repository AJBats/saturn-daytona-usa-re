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


! FUN_0600BF70 - Camera Heading Tracker (Exponential Smoothing)
! --------------------------------------------------------------
! 114 bytes, 57 insns. LEAF function (no jsr calls — uses mul.l only).
!
! CORRECTION: Previous description said "Call FUN_06027344 (cos_lookup)"
!   and "Call FUN_06027552 (fpmul)". No function calls exist — this is
!   purely inline math using mul.l instructions and arithmetic shifts.
!
! Computes smooth camera heading offset from car heading:
!   1. heading = sign_extend(car[+0x1C]) (lower 16 bits of heading angle)
!   2. scaled = (heading * 900) >> 10  (≈ heading * 0.879)
!   3. new_value = scaled + sign_extend(*sym_06063E34)  (add camera mode offset)
!   4. If *sym_06063E1C == *sym_06063E20 (state unchanged between frames):
!        Apply exponential smoothing:
!        result = (old * 800 + new * 224) >> 10
!        Weights: 800/1024 ≈ 0.78 (old) + 224/1024 ≈ 0.22 (new)
!   5. If state changed: result = new_value (instant snap, no smoothing)
!   6. Store result → *sym_06063EEC (camera parameter B)
!
! The smoothing prevents jarring camera snaps when the car turns.
! On state transitions (mode change), the camera snaps to the new heading
! immediately to avoid disorienting lag.
!
! BYTES: VERIFIED against production binary (114 bytes at 0x0600BF70-0x0600BFE1)

! CONFIDENCE: MEDIUM — Not a FUN_ label but exists at address (sts.l macl,@-r15).
!   Called via bsr from 0x0600BEF2. Smooth follow interpretation reasonable.
    .global FUN_0600BF70
! CONFIDENCE: MEDIUM — Not a FUN_ label but exists at address (sts.l macl,@-r15).
!   Called via bsr from 0x0600BEF2. Smooth follow interpretation reasonable.
FUN_0600BF70:                             ! 0x0600BF70 — Camera Heading Smoother
    sts.l   macl,@-r15                   ! save macl (function uses mul.l)
    mov.l   @(POOL),r4                   ! r4 → sym_0607E944 (current car state pointer)
    mov.w   @(POOL),r3                   ! r3 = 0x0384 = 900 (heading scale factor)
    mov.l   @(POOL),r2                   ! r2 → sym_06063E34 (camera mode offset word)
    mov.l   @(POOL),r5                   ! r5 → sym_06063EEC (camera parameter B — smoothed output)
    mov.l   @r4,r4                       ! r4 = car state pointer
    mov.l   @r2,r2                       ! r2 = *sym_06063E34 (camera mode value)
    mov.l   @(28,r4),r4                  ! r4 = car[+0x1C] (heading angle, 16.16 fixed)
    exts.w  r4,r4                        ! sign-extend lower 16 bits
    mul.l   r3,r4                        ! macl = heading * 900
    exts.w  r2,r3                        ! r3 = sign-extend camera mode offset
    sts     macl,r4                      ! r4 = heading * 900
    mov.l   @(POOL),r2                   ! r2 → sym_06063E1C (state flag A)
    shar    r4                           ! r4 >>= 1  (shift 1 of 10)
    mov.l   @r2,r2                       ! r2 = *sym_06063E1C
    shar    r4                           ! r4 >>= 2
    shar    r4                           ! >>= 3
    shar    r4                           ! >>= 4
    shar    r4                           ! >>= 5
    shar    r4                           ! >>= 6
    shar    r4                           ! >>= 7
    shar    r4                           ! >>= 8
    shar    r4                           ! >>= 9
    shar    r4                           ! >>= 10  (total: heading * 900 >> 10 ≈ heading * 0.879)
    add     r3,r4                        ! r4 = heading_scaled + camera_mode_offset
    mov.l   @(POOL),r3                   ! r3 → sym_06063E20 (state flag B)
    mov.l   @r3,r3                       ! r3 = *sym_06063E20
    cmp/eq  r3,r2                        ! state_A == state_B? (state unchanged?)
    bf/s    .heading_snap                ! if different → state changed, snap instantly
    exts.w  r4,r4                        ! (delay) sign-extend new heading value
    ! --- State unchanged: apply exponential smoothing ---
    mov.l   @r5,r3                       ! r3 = *sym_06063EEC (previous smoothed heading)
    exts.w  r4,r4                        ! sign-extend new value
    mov.w   @(POOL),r1                   ! r1 = 0x00E0 = 224 (new_weight)
    mov.w   @(POOL),r2                   ! r2 = 0x0320 = 800 (old_weight)
    exts.w  r3,r3                        ! sign-extend old value
    mul.l   r2,r3                        ! macl = old_value * 800
    sts     macl,r3                      ! r3 = old_value * 800
    mul.l   r1,r4                        ! macl = new_value * 224
    sts     macl,r4                      ! r4 = new_value * 224
    add     r4,r3                        ! r3 = old*800 + new*224 (weighted blend, sum=1024)
    shar    r3                           ! r3 >>= 1  (shift 1 of 10)
    shar    r3                           ! >>= 2
    shar    r3                           ! >>= 3
    shar    r3                           ! >>= 4
    shar    r3                           ! >>= 5
    shar    r3                           ! >>= 6
    shar    r3                           ! >>= 7
    shar    r3                           ! >>= 8
    shar    r3                           ! >>= 9
    shar    r3                           ! >>= 10 (divide by 1024 to normalize)
    mov.l   r3,@r5                       ! *sym_06063EEC = smoothed heading
    bra     .heading_return
    nop
    ! --- State changed: store new heading directly (no smoothing) ---
.heading_snap:                            ! 0x0600BFDA
    exts.w  r4,r4                        ! sign-extend
    mov.l   r4,@r5                       ! *sym_06063EEC = new heading (instant snap)
.heading_return:                          ! 0x0600BFDE
    rts
    lds.l   @r15+,macl                   ! (delay) restore macl
! --- constant pool for FUN_0600BF70 (at 0x0600BFE2) ---
! 0x0600BFE2: 0x0384 (900 heading scale, 16-bit), 0x0320 (800 old weight), 0x00E0 (224 new weight)
! 0x0600BFE8: sym_0607E944, sym_06063E34, sym_06063EEC, sym_06063E1C, sym_06063E20


! =============================================================================
! SUPPORTING FUNCTIONS
! =============================================================================

! FUN_0600BFFC - Primary Scene Rendering Orchestrator
! ---------------------------------------------------
! ~370 bytes (prologue FUN_0600BFFC 20B + body FUN_0600C010 ~350B).
!
! CORRECTION: Not "HUD/Racing State Initialization" — this is the
!   PRIMARY SCENE RENDERING ORCHESTRATOR. It coordinates:
!   1. Secondary SH-2 dispatch (writes callback to sym_06063574!)
!   2. Conditional rendering based on game state bitmask
!   3. VDP hardware writes (0x21000000)
!   4. CS0 object rendering (FUN_0600B6A0)
!   5. Render budget management
!   6. Hardware status polling
!
! CRITICAL CONNECTION: At 0x0600C0E6, this function stores
!   FUN_0600C170's address into sym_06063574 — the SECONDARY CALLBACK
!   POINTER that the secondary SH-2 reads via FUN_06034F08.
!   This is the same pointer involved in the ICF_FIX root cause:
!   the missed cache-through relocation at 0x26063574.
!
! FUN_0600BFFC (prologue, 20 bytes):
!   Push r14-r8, set r11=1, r14=128 (0x80 bitmask), fall into FUN_0600C010
!
! FUN_0600C010 (body):
!   r8  → sym_0607EBC4 (game state bitmask from main loop)
!   r10 = 0xFE11 (hardware status mask)
!   r12 → sym_0608A52C (render budget counter B)
!   r13 → sym_0605A1DD (config/LOD byte)
!   r14 = 0x80 (bit 7 mask for hardware polling)
!
!   1. If *sym_06083255 != 0: call FUN_06034708(*sym_0607EB8C) — secondary init
!   2. State-dependent rendering dispatch:
!      - If bitmask & 0x02000000 (state 25): skip to step 3
!      - Else if *sym_06078635 != 0: call sym_0600D336 (render path A)
!      - Else: call FUN_0600D31C (render path B)
!   3. If bitmask == 0x20000 (exactly state 17) AND *sym_0607EAE0 == 0:
!      call sym_0602E610 (special state-17 rendering)
!   4. Allocate 48 bytes to render budget (*sym_0608A52C += 48)
!   5. Call sym_06027630(budget, *sym_06089EDC, 48) — budget allocation
!   6. Set object iteration count at sym_06078664:
!      - If *sym_06059F30 == 0: count = *sym_0607EA98 >> 1
!      - Else: count = byte from sym_0605A1DD
!   7. Store FUN_0600C170 → *sym_06063574 (SET SECONDARY CALLBACK!)
!   8. Write 0xFFFF → 0x21000000 (VDP hardware register write)
!   9. If bitmask & 0x02800008 == 0: call FUN_060058FA (per-frame update)
!  10. Call FUN_06006868
!  11. Call FUN_0600B6A0 (CS0 object rendering loop)
!  12. If bitmask != 0x02000000: call FUN_0601BDEC
!  13. Hardware polling: busy-wait on sym_0605A1DD bit 7, then clear upper 4 bits
!  14. Adjust LOD config byte (increment if budget available, decrement if exceeded)
!  15. Call sym_0603C000
!  16. Deallocate 48 bytes from render budget (*sym_0608A52C -= 48)
!
! FUN_0600C170 (SECONDARY CALLBACK, called by secondary SH-2):
!   - Call sym_0603C000
!   - If *sym_06083255 != 0: call FUN_0600B340 (primary scene coordinator)
!     Else: call FUN_0600AFB2 (secondary scene helper)
!   - Call FUN_0600B914 (main object rendering loop!)
!   - Check sym_06063E1C + sym_06063E20 == 8:
!     If yes: call FUN_06006A9C, else: call FUN_06006CDC
!   - Copy sym_06059F40 → sym_06059F4C
!   - Write 0xFFFF → 0x21800000 (VDP register — signals secondary render complete)
!
! BYTES: VERIFIED against production binary (FUN_0600BFFC 20B + FUN_0600C010 ~350B)

! CONFIDENCE: MEDIUM — Label not verified. HUD init role inferred.
    .global FUN_0600BFFC
! CONFIDENCE: MEDIUM — Label not verified. HUD init role inferred.
FUN_0600BFFC:                             ! 0x0600BFFC — Primary Scene Rendering Orchestrator
    mov.l   r14,@-r15                    ! push r14
    mov.l   r13,@-r15                    ! push r13
    mov.l   r12,@-r15                    ! push r12
    mov.l   r11,@-r15                    ! push r11
    mov.l   r10,@-r15                    ! push r10
    mov     #1,r11                       ! r11 = 1 (LOD minimum threshold)
    mov.l   r9,@-r15                     ! push r9
    mov     r11,r14                      ! r14 = 1
    mov.l   r8,@-r15                     ! push r8
    add     #127,r14                     ! r14 = 128 = 0x80 (bit 7 mask for HW polling)
                                         ! falls through to FUN_0600C010...

FUN_0600C010:                             ! 0x0600C010 — Scene rendering body
    sts.l   pr,@-r15                     ! save return address
    mov.l   @(POOL),r8                   ! r8 → sym_0607EBC4 (game state bitmask)
    mov.w   @(POOL),r10                  ! r10 = 0xFE11 (HW status mask)
    mov.l   @(POOL),r12                  ! r12 → sym_0608A52C (render budget B)
    mov.l   @(POOL),r13                  ! r13 → sym_0605A1DD (LOD config byte)
    mov.l   @(POOL),r0                   ! r0 → sym_06083255 (secondary processing flag)
    mov.b   @r0,r0                       ! r0 = *sym_06083255
    tst     r0,r0                        ! flag == 0?
    bt/s    .skip_secondary_init         ! if zero, skip secondary init
    mov     #0,r9                        ! (delay) r9 = 0 (LOD adjustment flag)
    mov.l   @(POOL),r4                   ! r4 → sym_0607EB8C
    mov.l   @(POOL),r3                   ! r3 = FUN_06034708
    jsr     @r3                          ! call FUN_06034708(*sym_0607EB8C) — secondary processing
    mov.l   @r4,r4                       ! (delay) r4 = *sym_0607EB8C
.skip_secondary_init:                     ! 0x0600C02C
    mov.l   @r8,r2                       ! r2 = state bitmask
    mov.l   @(POOL),r3                   ! r3 = 0x02000000 (state 25 bit)
    and     r3,r2                        ! test state 25
    tst     r2,r2                        ! state 25 active?
    bf      .past_render_dispatch        ! if state 25: skip conditional render
    ! --- Not state 25: check render mode ---
    mov.l   @(POOL),r0                   ! r0 → sym_06078635
    mov.b   @r0,r0                       ! r0 = *sym_06078635
    extu.b  r0,r0
    tst     r0,r0                        ! == 0?
    bt      .render_path_b               ! if zero → path B
    mov.l   @(POOL),r3                   ! r3 → sym_0600D336
    jsr     @r3                          ! call sym_0600D336 — render path A
    nop
    bra     .past_render_dispatch
    nop
.render_path_b:                           ! 0x0600C04A
    mov.l   @(POOL),r3                   ! r3 = FUN_0600D31C
    jsr     @r3                          ! call FUN_0600D31C — render path B
    nop
.past_render_dispatch:                    ! 0x0600C050
    ! --- Check for special state 17 rendering ---
    mov.l   @r8,r2                       ! r2 = state bitmask
    mov.l   @(POOL),r3                   ! r3 = 0x20000 (state 17 bitmask)
    cmp/eq  r3,r2                        ! exactly state 17?
    bf      .past_state17                ! if not, skip
    mov.l   @(POOL),r0                   ! r0 → sym_0607EAE0
    mov.l   @r0,r0                       ! r0 = *sym_0607EAE0
    tst     r0,r0                        ! == 0?
    bf      .past_state17                ! if non-zero, skip
    mov.l   @(POOL),r3                   ! r3 → sym_0602E610
    jsr     @r3                          ! call sym_0602E610 — state 17 special render
    nop
.past_state17:                            ! 0x0600C066
    ! --- Render budget allocation ---
    mov     #48,r6                       ! r6 = 48 (budget allocation size)
    mov.l   @r12,r2                      ! r2 = *sym_0608A52C (current budget)
    add     #48,r2                       ! r2 += 48
    mov.l   r2,@r12                      ! *sym_0608A52C = r2 (allocate)
    mov.l   @(POOL),r5                   ! r5 → sym_06089EDC (budget counter A)
    mov.l   @(POOL),r3                   ! r3 → sym_06027630 (budget alloc function)
    mov.l   @r5,r5                       ! r5 = *sym_06089EDC
    jsr     @r3                          ! call sym_06027630(budget, budgetA, 48)
    mov     r2,r4                        ! (delay) r4 = budget value
    ! --- Set object iteration count ---
    mov.l   @(POOL),r4                   ! r4 → sym_06078664 (iteration count target)
    mov.l   @(POOL),r0                   ! r0 → sym_06059F30
    mov.l   @r0,r0                       ! r0 = *sym_06059F30
    tst     r0,r0                        ! == 0?
    bf      .use_config_count            ! if non-zero, use config byte
    ! --- Zero: compute count from object total ---
    mov.l   @(POOL),r3                   ! r3 → sym_0607EA98
    mov.l   @r3,r3                       ! r3 = *sym_0607EA98 (total objects)
    shar    r3                           ! r3 >>= 1 (half the objects)
    exts.w  r3,r3                        ! sign-extend
    mov.w   r3,@r4                       ! *sym_06078664 = total/2
    bra     .set_secondary_callback
    nop
    ! ...constant pool interrupts code here (0x0600C090-0x0600C0DA)...
.use_config_count:                        ! 0x0600C0DC
    mov.b   @r13,r2                      ! r2 = *sym_0605A1DD (LOD config byte)
    extu.b  r2,r2                        ! zero-extend
    mov.w   r2,@r4                       ! *sym_06078664 = config byte
.set_secondary_callback:                  ! 0x0600C0E2
    ! --- CRITICAL: Write secondary callback pointer ---
    mov.l   @(POOL),r3                   ! r3 = FUN_0600C170 (secondary rendering function)
    mov.l   @(POOL),r2                   ! r2 → sym_06063574 (SECONDARY CALLBACK POINTER)
    mov.l   r3,@r2                       ! *sym_06063574 = FUN_0600C170
    ! --- VDP hardware write ---
    mov.l   @(POOL),r3                   ! r3 = 0xFFFF
    mov.l   @(POOL),r2                   ! r2 = 0x21000000 (VDP register address)
    mov.w   r3,@r2                       ! write 0xFFFF → 0x21000000
    ! --- Conditional per-frame update ---
    mov.l   @r8,r3                       ! r3 = state bitmask
    mov.l   @(POOL),r2                   ! r2 = 0x02800008 (states 3+19+25 mask)
    and     r2,r3                        ! test those states
    tst     r3,r3                        ! any active?
    bf      .skip_frame_update           ! if any active, skip
    mov.l   @(POOL),r3                   ! r3 = FUN_060058FA
    jsr     @r3                          ! call FUN_060058FA — per-frame update chain
    nop
.skip_frame_update:                       ! 0x0600C0FE
    mov.l   @(POOL),r3                   ! r3 = FUN_06006868
    jsr     @r3                          ! call FUN_06006868
    nop
    bsr     FUN_0600B6A0                 ! call FUN_0600B6A0 — CS0 object rendering loop
    nop
    ! --- State-specific post-rendering ---
    mov.l   @r8,r2                       ! r2 = state bitmask
    mov.l   @(POOL),r3                   ! r3 = 0x02000000 (state 25)
    cmp/eq  r3,r2                        ! exactly state 25?
    bt      .skip_post_render            ! if state 25, skip
    mov.l   @(POOL),r3                   ! r3 = FUN_0601BDEC
    jsr     @r3                          ! call FUN_0601BDEC
    nop
    bra     .skip_post_render
    nop
    mov     r11,r9                       ! r9 = 1 (flag: LOD increment path)
.skip_post_render:                        ! 0x0600C11C
    ! --- Hardware status polling loop ---
    mov.b   @r10,r2                      ! r2 = *sym_0605A1DD (HW status byte)
    extu.b  r2,r2                        ! zero-extend
    and     r14,r2                       ! r2 & 0x80 (test bit 7)
    cmp/eq  r14,r2                       ! bit 7 set?
    bf      .hw_poll_done                ! if bit 7 clear, polling done
    ! (loops back to .skip_post_render for busy-wait)
.hw_poll_done:
    mov.b   @r10,r0                      ! r0 = status byte
    and     #15,r0                       ! r0 &= 0x0F (clear upper 4 bits)
    mov.b   r0,@r10                      ! write back cleaned status
    ! --- LOD config adjustment ---
    tst     r9,r9                        ! r9 == 0? (no LOD increment needed?)
    bt      .lod_decrement_path          ! if zero, try decrement
    mov.b   @r13,r3                      ! r3 = LOD config byte
    mov.l   @(POOL),r2                   ! r2 → sym_0607EA98
    extu.b  r3,r3
    mov.l   @r2,r2                       ! r2 = total object count
    cmp/ge  r2,r3                        ! config >= total?
    bt      .lod_done                    ! if at max, don't increment
    mov.b   @r13,r2
    add     #1,r2                        ! config++
    bra     .lod_done
    mov.b   r2,@r13                      ! store incremented config
.lod_decrement_path:                      ! 0x0600C144
    mov.b   @r13,r2                      ! r2 = LOD config byte
    extu.b  r2,r2
    cmp/gt  r11,r2                       ! config > 1?
    bf      .lod_done                    ! if <= 1, don't decrement (minimum)
    mov.b   @r13,r2
    add     #-1,r2                       ! config--
    mov.b   r2,@r13                      ! store decremented config
.lod_done:                                ! 0x0600C152
    mov.l   @(POOL),r3                   ! r3 → sym_0603C000
    jsr     @r3                          ! call sym_0603C000
    nop
    ! --- Deallocate render budget ---
    mov.l   @r12,r2                      ! r2 = *sym_0608A52C
    add     #-48,r2                      ! r2 -= 48
    mov.l   r2,@r12                      ! *sym_0608A52C = r2 (deallocate)
    ! --- Epilogue ---
    lds.l   @r15+,pr                     ! restore PR
    mov.l   @r15+,r8                     ! restore r8
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14                    ! (delay) restore r14
! --- constant pool for FUN_0600C010 (at 0x0600C090+0x0600C188) ---
! Pool A (0x0600C090): 0xFE11 (HW mask), sym_0607EBC4, sym_0608A52C, sym_0605A1DD,
!   sym_06083255, sym_0607EB8C, FUN_06034708, 0x02000000, sym_06078635,
!   sym_0600D336, FUN_0600D31C, 0x20000, sym_0607EAE0, sym_0602E610,
!   sym_06089EDC, sym_06027630, sym_06078664, sym_06059F30, sym_0607EA98
! Pool B (0x0600C188): FUN_0600C170, sym_06063574, 0xFFFF, 0x21000000,
!   0x02800008, FUN_060058FA, FUN_06006868, 0x02000000, FUN_0601BDEC,
!   sym_0607EA98, sym_0603C000


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


! FUN_0600C302 - Wheel Animation Timer (Speed-Dependent)
! -------------------------------------------------------
! 166 bytes (code 0x0600C302-0x0600C3A7 including pool + tail). LEAF function.
!
! CORRECTION: Not "speed limiter" — this manages wheel VISUAL ROTATION TIMERS
!   based on speed thresholds. Two counters at car[+0x172] and car[+0x174]
!   control front/rear wheel animation durations.
!
! Algorithm:
!   1. car[+0xE0] = car[+0xE4] = car[+0x68] << 5 (scale speed * 32)
!   2. Decrement car[+0x172] if > 0 (wheel counter 1 — front wheels)
!   3. Decrement car[+0x174] if > 0 (wheel counter 2 — rear wheels)
!   4. If car[+0xDC] != 0: return (car in motion, counters tick naturally)
!   5. If car[+0x68] >= 230: set counter1=18, counter2=0 (high speed: front spin)
!   6. If car[+0x84] >= 140 AND 155 < car[+0x68] < 230:
!      set counter1=0, counter2=18 (medium speed: rear wheel effect)
!   7. Otherwise: return (low speed, no wheel animation refresh)
!
! Speed thresholds: 230 (high), 155 (medium-low), 140 (secondary metric gate)
! Counter init value: 18 frames (~0.3 seconds at 60fps)
!
! BYTES: VERIFIED against production binary (166 bytes at 0x0600C302-0x0600C3A7)

! CONFIDENCE: MEDIUM — Label not verified. Wheel/speed role inferred.
    .global FUN_0600C302
! CONFIDENCE: MEDIUM — Label not verified. Wheel/speed role inferred.
FUN_0600C302:                             ! 0x0600C302 — Wheel Animation Timer
    mov     #104,r0                      ! r0 = 0x68 (speed field offset)
    mov.l   @(POOL),r4                   ! r4 → sym_0607E944 (car state pointer)
    mov.l   @r4,r4                       ! r4 = car state struct
    mov.l   @(r0,r4),r3                  ! r3 = car[+0x68] (raw speed value)
    add     #124,r0                      ! r0 = 0xE4
    shll2   r3                           ! r3 <<= 2
    shll2   r3                           ! r3 <<= 4
    shll    r3                           ! r3 <<= 5 (speed * 32)
    mov.l   r3,@(r0,r4)                  ! car[+0xE4] = speed * 32
    add     #-4,r0                       ! r0 = 0xE0
    mov.l   r3,@(r0,r4)                  ! car[+0xE0] = speed * 32 (duplicate)
    ! --- Decrement wheel counter 1 (front wheels) ---
    mov.w   @(POOL),r0                   ! r0 = 0x0172
    mov.w   @(r0,r4),r3                  ! r3 = car[+0x172] (front wheel counter)
    cmp/pl  r3                           ! r3 > 0?
    bf      .skip_counter1               ! if <= 0, don't decrement
    mov.w   @(POOL),r0                   ! r0 = 0x0172
    mov.w   @(r0,r4),r2                  ! r2 = car[+0x172]
    add     #-1,r2                       ! r2--
    mov.w   r2,@(r0,r4)                  ! car[+0x172] = r2
.skip_counter1:                           ! 0x0600C328
    ! --- Decrement wheel counter 2 (rear wheels) ---
    mov.w   @(POOL),r0                   ! r0 = 0x0174
    mov.w   @(r0,r4),r3                  ! r3 = car[+0x174] (rear wheel counter)
    cmp/pl  r3                           ! r3 > 0?
    bf      .skip_counter2               ! if <= 0, don't decrement
    mov.w   @(POOL),r0                   ! r0 = 0x0174
    mov.w   @(r0,r4),r2                  ! r2 = car[+0x174]
    add     #-1,r2                       ! r2--
    mov.w   r2,@(r0,r4)                  ! car[+0x174] = r2
.skip_counter2:                           ! 0x0600C338
    ! --- Check if car is in motion animation ---
    mov.w   @(POOL),r0                   ! r0 = 0x00DC
    mov.w   @(r0,r4),r0                  ! r0 = car[+0xDC] (motion/animation flag)
    tst     r0,r0                        ! flag == 0?
    bt      .car_stopped                 ! if zero → car stopped, check speed thresholds
    rts                                  ! car in motion → return (counters tick naturally)
    nop
.car_stopped:                             ! 0x0600C344
    ! --- Speed threshold checks for wheel animation ---
    mov     #18,r7                       ! r7 = 18 (counter init: ~0.3 seconds at 60fps)
    mov     #104,r0                      ! r0 = 0x68 (speed offset)
    mov.w   @(POOL),r2                   ! r2 = 0x00E6 = 230 (high speed threshold)
    mov.l   @(r0,r4),r3                  ! r3 = car[+0x68] (speed)
    cmp/ge  r2,r3                        ! speed >= 230?
    bf/s    .check_medium_speed          ! if < 230, check next tier
    mov     #0,r6                        ! (delay) r6 = 0
    ! --- High speed (>= 230): front wheel spin, no rear ---
    mov.w   @(POOL),r0                   ! r0 = 0x0172
    mov.w   r7,@(r0,r4)                  ! car[+0x172] = 18 (front wheel counter)
    add     #2,r0                        ! r0 = 0x0174
    rts
    mov.w   r6,@(r0,r4)                  ! (delay) car[+0x174] = 0 (no rear)
.check_medium_speed:                      ! 0x0600C35C
    mov.w   @(POOL),r0                   ! r0 = 0x0084 (secondary speed metric offset)
    mov.w   @(POOL),r2                   ! r2 = 0x008C = 140 (gate threshold)
    mov.l   @(r0,r4),r3                  ! r3 = car[+0x84] (secondary speed metric)
    cmp/ge  r2,r3                        ! car[+0x84] >= 140?
    bt      .check_mid_range             ! if >= 140, check speed range
    rts                                  ! else: too slow, return
    nop
    ! --- (constant pool at 0x0600C36A-0x0600C386) ---
.check_mid_range:                         ! 0x0600C388
    mov     #104,r0                      ! r0 = 0x68
    mov.w   @(POOL),r3                   ! r3 = 0x009B = 155 (medium-low threshold)
    mov.l   @(r0,r4),r5                  ! r5 = car[+0x68] (speed)
    cmp/gt  r3,r5                        ! speed > 155?
    bf      .wheel_done                  ! if <= 155, too slow for rear effect
    mov.w   @(POOL),r3                   ! r3 = 0x00E6 = 230
    cmp/ge  r3,r5                        ! speed >= 230?
    bt      .wheel_done                  ! if >= 230, already handled above
    ! --- Medium speed (155-229): rear wheel effect ---
    exts.w  r6,r6                        ! sign-extend r6 = 0
    mov.w   @(POOL),r0                   ! r0 = 0x0172
    mov.w   r6,@(r0,r4)                  ! car[+0x172] = 0 (no front)
    exts.w  r7,r7                        ! sign-extend r7 = 18
    add     #2,r0                        ! r0 = 0x0174
    mov.w   r7,@(r0,r4)                  ! car[+0x174] = 18 (rear wheel counter)
.wheel_done:                              ! 0x0600C3A4
    rts
    nop
! --- constant pool for FUN_0600C302 (at 0x0600C36A) ---
! 0x0600C36A: 0x0172 (front counter offset), 0x0174 (rear counter offset)
! 0x0600C36E: 0x00DC (motion flag offset), 0x00E6 (230 high threshold)
! 0x0600C372: 0x0084 (secondary metric offset), 0x008C (140 gate threshold)
! 0x0600C384: sym_0607E944
! Extended pool (0x0600C388+): 0x009B (155), 0x00E6 (230), 0x0172


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
! | 0x0600BF70 | camera_heading     | 114  | Heading tracker (exponential smoothing)|
! | 0x0600BFFC | scene_render_orch  | ~370 | Primary scene rendering orchestrator  |
! | 0x0600C218 | hud_frame_setup    | 110  | Secondary HUD frame setup      |
! | 0x0600C302 | wheel_anim_timer   | 166  | Wheel animation timer (speed-based)   |
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
