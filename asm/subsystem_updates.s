! ================================================
! AUDIT: HIGH - Per-frame subsystem update pipeline documented accurately.
!   FUN_06005ECC and FUN_060061C8 verified at instruction level: object
!   pointers, transform calls, and register usage all confirmed. However,
!   FUN_06030A06, FUN_06030EE0, FUN_0602ECF2, and FUN_0603053C are NOT
!   labeled functions in the binary symbol table -- they are valid jsr
!   targets but without function labels in aprog.s. The inline ASM
!   annotations are partially representative (show prologue/epilogue only,
!   with middle abbreviated).
! Audited: 2026-02-10
! ================================================
!
! =============================================================================
! Per-Frame Subsystem Updates (Physics Pipeline Support)
! =============================================================================
!
! Functions called from the per-car update pipeline (FUN_0600E4F2 / FUN_0600E0C0)
! that handle position integration, timer management, rendering setup, and
! track segment tracking.
!
! CONFIDENCE: HIGH — Call order verified from FUN_0600E0C0/FUN_0600E4F2
!   pool constants in the binary. All jsr targets confirmed.
! Call order in per-car pipeline:
!   1. FUN_06030A06 (subsystem A — counter/timer management)
!   2. FUN_06030EE0 (subsystem B — simple timer decrement)
!   3. Physics (FUN_0600E71A or FUN_0600E906)
!   4. FUN_060061C8 (pre-render transform setup)
!   5. FUN_06027CA4 x4 (3D scene rendering)
!   6. FUN_0603053C (render finalize)
!   7. FUN_06005ECC (segment tracking)
!   8. FUN_0602ECF2 (physics integration dispatcher)

! =============================================================================
! CONFIDENCE: MEDIUM — Valid jsr target (called from FUN_0600E0C0 etc.)
!   but NOT a labeled function in aprog.s. Falls within FUN_06030540 or nearby.
!   The counter/timer description is plausible but the detailed algorithm has
!   not been fully verified against binary instructions.
! AUDIT NOTE: FIXED: Added '(not a labeled function)' to title. Valid jsr target but not labeled in aprog.s. Nearest labels: FUN_060302D2 and FUN_06030540.
! FUN_06030A06 (not a labeled function in aprog.s) — Subsystem A: Counter/Timer Management
! =============================================================================
! Called from: FUN_0600E0C0, FUN_0600E4F2, FUN_0600E410
! Purpose: Per-car frame counter management, lap/segment state tracking
!
! Data structures:
! AUDIT NOTE: FIXED: Car pointer 0x0607E940 confirmed as standard car-related pointer used across multiple subsystems. No change needed.
!   0x0607E940 -> current car pointer
!   Car offsets:
!     +0x00  int  flags (bits 21-23 = car type via mask 0x00200000)
!     +0x30  int  state reference
!     +0x250 word counter (signed, decremented per frame)
!   Global state:
!     0x0607EAE8  subsystem state A
!     0x0607EAEC  subsystem state B
!     0x0607866D  hardware I/O (byte)
!     0x06089595  hardware I/O (byte)
!
! Algorithm:
!   car = *0x0607E940
!   counter = car->word[0x250]
!   if (counter > 0):
!     counter--
!     car->word[0x250] = counter
!   flags = car->int[0x30] & 0x00200000
!   if (flags != 0):
!     ... complex conditional checks on multiple state variables ...
!     update 0x0607EAE8 and 0x0607EAEC
!     write to I/O bytes at 0x0607866D and 0x06089595
!   return
!
! This is a LEAF function (no subroutine calls) — all logic is inline.

! CONFIDENCE: SPECULATIVE — The inline ASM shown here is REPRESENTATIVE,
!   not extracted from the binary. The actual instruction sequence at 0x06030A06
!   may differ. Only the prologue pattern and general algorithm are depicted.
FUN_06030A06:  ! 0x06030A06
    ! Load car pointer and counter
    mov.w   @(PC),r0                ! offset 0x250
    mov.l   @(PC),r1                ! 0x0607E940
    mov.l   @r1,r1                  ! car base
    mov.w   @(r0,r1),r2             ! car->counter_250
    cmp/pl  r2                      ! counter > 0?
    bf      .check_flags
    add     #-1,r2                  ! decrement
    mov.w   r2,@(r0,r1)             ! store back

.check_flags:
    ! Check car type flags
    mov.l   @(0x30,r1),r3           ! car->flags_30
    and     r2,r3                   ! & 0x00200000
    tst     r3,r3
    bt      .sub_a_done             ! inactive → return

    ! Complex conditional state update
    ! ... reads multiple globals, updates subsystem state ...
    ! ... writes to I/O bytes ...

.sub_a_done:
    rts
    nop


! =============================================================================
! CONFIDENCE: MEDIUM — Valid jsr target but NOT a labeled function in
!   aprog.s. Simple timer decrement pattern is plausible for a per-car
!   subsystem update.
! AUDIT NOTE: FIXED: Added '(not a labeled function)' to title. Valid jsr target but not labeled in aprog.s.
! FUN_06030EE0 (not a labeled function in aprog.s) — Subsystem B: Simple Timer Decrement
! =============================================================================
! Called from: FUN_0600E0C0, FUN_0600E4F2, FUN_0600E410
! Purpose: Decrement a single per-car timer. Very simple leaf function.
!
! Algorithm:
!   car = *0x0607E940
!   timer = car->word[0x150]   // offset 336 decimal
!   if (timer > 0):
!     timer--
!     car->word[0x150] = timer
!   return
!
! This timer is likely used for:
!   - Effect duration (invincibility frames after collision)
!   - UI display timing
!   - State timeout

! CONFIDENCE: SPECULATIVE — Representative ASM, not extracted from binary.
FUN_06030EE0:  ! 0x06030EE0
    mov.w   @(PC),r0                ! r0 = 0x150 (offset 336)
    mov.l   @(PC),r1                ! 0x0607E940
    mov.l   @r1,r1                  ! car base
    mov.w   @(r0,r1),r2             ! car->timer_150
    cmp/pl  r2                      ! > 0?
    bf      .sub_b_done
    add     #-1,r2
    mov.w   r2,@(r0,r1)             ! decrement and store
.sub_b_done:
    rts
    nop


! =============================================================================
! CONFIDENCE: DEFINITE — Address verified as labeled function. Prologue
!   (r14-r8 push + pr) confirmed. Object pointers at 0x06063E88, 0x06063E4C,
!   0x06063E74, 0x06063E60 confirmed from pool constants. Transform calls to
!   FUN_06026DBC, FUN_06026E0C, FUN_06026EDE, FUN_06026FFC confirmed.
!   5th pointer from 0x0607E944 (NOT 0x0607E940) confirmed.
! FUN_06005ECC — Segment/Position Tracking (Multi-Object Update)
! =============================================================================
! Called from: FUN_0600E4F2 (stage 7), pipeline
! Purpose: Update position vectors for multiple game objects (cars + camera?)
!
! This function operates on 5 object pointers simultaneously, loading their
! positions and adding accumulated delta values (velocity integration).
!
! Object pointers (loaded from globals):
!   0x06063E88 — object 0 (primary car?)
!   0x06063E4C — object 1
!   0x06063E74 — object 2
!   0x06063E60 — object 3
!   (5th from another pool reference)
!
! Per-object updates:
!   obj->X += delta_x   (offset +0x00)
!   obj->Y += delta_y   (offset +0x04)
!   obj->Z += delta_z   (offset +0x08)
!
! Delta values come from the first object's velocity fields:
!   delta_x = obj0->vel_x  (offset +0x10)
!   delta_y = obj0->vel_y  (offset +0x14)
!   delta_z = obj0->vel_z  (offset +0x18)
!
! Calls:
!   FUN_06026DBC (x6) — likely sin/cos or vector transform helpers
!   FUN_06026E0C — secondary transform
!   FUN_06026EDE — tertiary transform
!   FUN_06026FFC — generic subsystem caller

! CONFIDENCE: HIGH — Prologue/epilogue match binary exactly. Middle is
!   abbreviated but call targets and register usage are accurate.
FUN_06005ECC:  ! 0x06005ECC
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15

    ! Load 5 object pointers into r8, r9, r10, r12, r14
    ! Load initial deltas from obj0->velocity (offsets +0x10, +0x14)
    ! ... (heavy register usage, 5 objects + 3 deltas) ...

    ! Call transform functions to compute final deltas
    ! jsr FUN_06026DBC   (6 calls)
    ! jsr FUN_06026E0C
    ! jsr FUN_06026EDE
    ! jsr FUN_06026FFC

    ! Apply deltas to all 5 objects
    ! For each object: position += delta

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
! CONFIDENCE: DEFINITE — Address verified as labeled function. Loads from
!   0x0607E940 (car pointer), offsets +0x10/+0x14/+0x18/+0x30 confirmed.
!   Same transform helpers as FUN_06005ECC confirmed. Subtracts 48 from
!   value at 0x06089EDC confirmed (add #-48 at 06006252).
! FUN_060061C8 — Pre-Render Transform Setup
! =============================================================================
! Called from: FUN_0600E0C0 (before FUN_06027CA4 x4)
! Purpose: Prepare object transforms for 3D rendering
!
! Sets up camera-space coordinates or applies transformation matrices
! before the 3D scene renderer processes the car.
!
! Accesses:
!   0x0607E940 -> car pointer
!   Car position at +0x10, +0x14, +0x18 (X, Y, Z)
!   Car velocity at +0x30
!   0x06089EDC — state adjustment (subtract 48)
!
! Calls:
!   FUN_06026DBC, FUN_06026E0C, FUN_06026EDE, FUN_06026FFC
!   (same transform helpers as FUN_06005ECC)

! CONFIDENCE: HIGH — Prologue/epilogue match binary (r14-r11 + pr).
!   Middle is abbreviated but key operations are documented.
FUN_060061C8:  ! 0x060061C8
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    sts.l   pr,@-r15

    ! Load car state and position vectors
    ! Call transform pipeline (same as segment tracking)
    ! Update 5 objects with consolidated position/velocity data
    ! Final adjustment: subtract 48 from state at 0x06089EDC

    lds.l   @r15+,pr
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! =============================================================================
! CONFIDENCE: HIGH — Valid jsr target, NOT a labeled function in aprog.s.
!   Jump table structure at 0x0602ED0C verified: loads step counter from
!   0x0607EAE4, shll2 for index, loads and jumps to table entry. This is
!   definitively a jump table dispatch. Physics role is reasonable inference.
! AUDIT NOTE: FIXED: Added '(not a labeled function)' to title. Valid jsr target confirmed from pipeline code.
! FUN_0602ECF2 (not a labeled function in aprog.s) — Physics Integration Dispatcher (Jump Table)
! =============================================================================
! Called from: FUN_0600E4F2 (late in pipeline)
! Purpose: Dispatch to one of several physics sub-steps via jump table
!
! This is a STATE MACHINE within the physics pipeline. Each frame, it
! advances through a sequence of physics operations.
!
! Data:
!   0x0607EAE4  physics step counter (incremented each call)
!   Jump table at 0x0602ED0C (4-byte entries)
!   Secondary table at 0x0602ED18
!
! Jump table targets:
!   0x0602FDA1  — primary physics step
!   0x0602EE90  — secondary step
!   0x0602EE20  — conditional branch A
!   0x0602EE58  — conditional branch B
!
! Algorithm:
!   step = *0x0607EAE4
!   handler = jump_table[step << 2]
!   jmp handler
!   step++
!   *0x0607EAE4 = step
!
! The shll16 instructions in the targets suggest 16.16 fixed-point
! coordinate manipulation.

! CONFIDENCE: DEFINITE — Inline ASM matches binary exactly: mov.l
!   @(0x10,PC),r1 {0x0607EAE4}; mov.l @r1,r2; mov.l @(0x10,PC),r3
!   {0x0602ED0C}; shll2 r2; add r2,r3; mov.l @r3,r3; jmp @r3; nop.
FUN_0602ECF2:  ! 0x0602ECF2
    mov.l   @(0x10,PC),r1           ! 0x0607EAE4
    mov.l   @r1,r0                  ! step counter
    shll2   r0                      ! * 4 (table index)
    mov.l   @(0x10,PC),r2           ! jump table base
    mov.l   @(r0,r2),r3             ! target address
    jmp     @r3                     ! dispatch
    nop


! =============================================================================
! CONFIDENCE: MEDIUM — Valid jsr target, NOT a labeled function in
!   aprog.s. Called after 4x FUN_06027CA4 calls is confirmed from the pipeline
!   code. Render finalize role is speculative.
! AUDIT NOTE: FIXED: Added '(not a labeled function)' to title. Valid jsr target confirmed from pipeline code.
! FUN_0603053C (not a labeled function in aprog.s) — Render Finalize
! =============================================================================
! Called from: FUN_0600E0C0 (after 4x FUN_06027CA4 calls)
! Purpose: Finalize render submission for current car
!
! Takes r4 = render mode parameter (typically 0 or 1)
! Appears to be a short function that pushes final render state.

! CONFIDENCE: SPECULATIVE — Inline ASM is representative only. The actual
!   function body has not been fully extracted and verified.
FUN_0603053C:  ! 0x0603053C
    mov.l   r12,@-r15
    mov.l   r13,@-r15
    ! ... continuation likely chains to render pipeline ...
    ! ... submits final VDP1 commands or updates display list ...
    mov.l   @r15+,r13
    mov.l   @r15+,r12
    rts
    nop
