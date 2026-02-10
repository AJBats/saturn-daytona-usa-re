! ================================================
! AUDIT: HIGH -- VDP1 init and hardware division verified byte-for-byte against
!   binary. Camera/viewport functions plausible but annotated mnemonics have
!   minor ordering discrepancies vs ground truth. VDP1 register map in header
!   contains address labeling errors (see AUDIT NOTEs below).
! Audited: 2026-02-09
! ================================================
! ============================================================================
! rendering.s — VDP1 Rendering Pipeline
! ============================================================================
!
! This file documents the Sega Saturn VDP1 rendering system used by Daytona
! USA during in-race states (14/15/17/19). The rendering pipeline runs every
! frame as part of each state handler.
!
! RENDERING PIPELINE (called from each in-race state):
! =====================================================
!
!   State Handler (e.g. FUN_06009098 for state 15)
!     → FUN_0602EFF0  (Rendering Pass 1: Camera/viewport setup)
!     → FUN_0602F0E8  (Rendering Pass 2: Frame buffer / smoothing)
!
! These run AFTER physics updates but before the race state finalizer.
!
! VDP1 HARDWARE OVERVIEW:
! ========================
!
! The VDP1 is the Saturn's sprite/polygon processor. The SH-2 CPU writes
! "command tables" to VDP1 VRAM, which VDP1 processes autonomously to
! render sprites and textured polygons into a frame buffer.
!
! Register Map (as used by this game):
!   0x25C00000  — VDP1 control register base
!   0x25C80000  — VDP1 VRAM start (64KB command table buffer)
!   0x25D00000  — TVMR (TV Mode Register): display mode, 3-bit field
!   0x25D00002  — FBCR (Frame Buffer Control): swap double-buffer
!   0x25D00004  — PTMR (Plot Trigger Mode Register): set to 2
!   0x25D00008  — EWDR (Erase/Write Data Register)
!   0x25D0000A  — EWLR (Erase Window Left Region)
!   0x25D0000E  — EWRR (Erase Window Right Region)
!
! Double-buffering: FBCR register alternates which 32KB half of VRAM the
! VDP1 reads from, while the CPU writes new commands to the other half.
!
! KEY DATA ADDRESSES:
!   0x0607E944  — camera/render state object pointer
!   0x0605A00C  — VDP1 command buffer state variable
!   0x06059F44  — VDP1 rendering flag
!   0x06078635  — global render enable flag (byte)
!   0x0607ED8C  — render mode (word)
!   0x0605AD00  — render state variable
!   0x0607ED90  — render parameter byte
!   0x06063F44  — source for render parameter
!
! ============================================================================


! ============================================================================
! FUN_0600A140 — VDP1 Initialization
! ============================================================================
! Called once during system startup (from FUN_060030FC init chain).
! Clears both VDP1 VRAM frame buffers and initializes texture/palette state.
!
! Steps:
!   1. Write 0x80000000 to VDP1 control reg (0x25C00000) — enable/reset
!   2. Clear buffer A: fill 64K words at 0x25C80000 with 0 (loop)
!   3. Clear 0x0605A00C (command buffer state)
!   4. Call FUN_06026CE0 (texture/palette setup)
!   5. Clear 0x06059F44 (rendering flag)
!   6. Clear buffer B: fill 64K words again (double-buffer B)
!   7. Same cleanup as steps 3-5

! CONFIDENCE: DEFINITE -- Pool constants verified: 0x80000000, 0x25C00000,
!   0x25C80000, 0x00010000, 0x0605A00C, 0x06026CE0, 0x06059F44 all match
!   binary exactly. Instruction sequence matches byte-for-byte.
FUN_0600A140:                            ! 0x0600A140
    mov.l   r14,@-r15                    ! Save r14
    sts.l   pr,@-r15                     ! Save return address
    mov     #0,r14                       ! r14 = 0 (fill value)

    ! --- Enable VDP1 ---
    mov.l   @(0x54,PC),r3              ! r3 = 0x80000000
    mov.l   @(0x54,PC),r2              ! r2 = 0x25C00000 (VDP1 control base)
    mov.l   r3,@r2                       ! Write 0x80000000 → VDP1 enable/reset

    ! --- Clear frame buffer A ---
    mov.l   @(0x54,PC),r5              ! r5 = 0x25C80000 (VDP1 VRAM base)
    mov.l   @(0x58,PC),r4              ! r4 = 0x00010000 (64K words = 256KB)

! AUDIT NOTE: Loop A first instruction is mov r5,r3 (not add #-2,r4).
!   Binary at 0x0600A150: mov r5,r3; add #-2,r4; add #4,r5; mov.l r14,@r3
.L_vdp1_clear_loop_A:                   ! 0x0600A150
    mov     r5,r3                        ! r3 = current write address
    add     #-2,r4                       ! Decrement counter by 2 (word pairs)
    add     #4,r5                        ! Advance write pointer
    mov.l   r14,@r3                      ! Write 0 to current address
    mov     r5,r2
    add     #4,r5
    tst     r4,r4                        ! Counter reached 0?
    bf/s    .L_vdp1_clear_loop_A         ! No → continue clearing
    mov.l   r14,@r2                      ! (delay) Write 0 to next address

    ! --- Post-clear A: reset state, init textures ---
    mov.l   @(0x48,PC),r3              ! r3 = &0x0605A00C (cmd buffer state)
    mov.l   r14,@r3                      ! Clear command buffer state
    mov.l   @(0x48,PC),r3              ! r3 = 0x06026CE0 (texture/palette init)
    jsr     @r3                          ! FUN_06026CE0: setup texture tables
    nop
    mov.l   @(0x44,PC),r3              ! r3 = &0x06059F44 (render flag)
    mov.l   r14,@r3                      ! Clear render flag

    ! --- Clear frame buffer B (identical loop) ---
    mov.l   @(0x30,PC),r5              ! r5 = 0x25C80000
    mov.l   @(0x34,PC),r4              ! r4 = 0x00010000

.L_vdp1_clear_loop_B:                   ! 0x0600A174
    mov     r5,r2
    add     #-2,r4
    add     #4,r5
    mov.l   r14,@r2                      ! Write 0
    mov     r5,r3
    add     #4,r5
    tst     r4,r4
    bf/s    .L_vdp1_clear_loop_B
    mov.l   r14,@r3                      ! (delay) Write 0

    ! --- Post-clear B: same cleanup ---
    mov.l   @(0x24,PC),r3
    mov.l   r14,@r3                      ! Clear 0x0605A00C again
    mov.l   @(0x24,PC),r3
    jsr     @r3                          ! FUN_06026CE0 again (for buffer B)
    nop
    mov.l   @(0x20,PC),r3
    mov.l   r14,@r3                      ! Clear 0x06059F44

    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14

! Pool constants for FUN_0600A140:
!   0x0600A19C = 0x80000000  (VDP1 VRAM init marker)
!   0x0600A1A0 = 0x25C00000  (VDP1 VRAM base)
!   0x0600A1A4 = 0x25C80000  (VDP1 VRAM midpoint)
!   0x0600A1A8 = 0x00010000  (64K words = buffer size)
!   0x0600A1AC = 0x0605A00C  (command buffer state)
!   0x0600A1B0 = 0x06026CE0  (texture/palette init function)
!   0x0600A1B4 = 0x06059F44  (rendering flag)


! ============================================================================
! FUN_0602EFF0 — Rendering Pass 1: Camera/Viewport Computation
! ============================================================================
! Computes the camera viewport parameters for the current frame.
! Called every in-race frame before FUN_0602F0E8.
!
! Input: reads camera state from object at [0x0607E944]
! Output: writes computed viewport bounds back to the camera object
!
! Algorithm:
!   1. Load camera movement delta from object (signed value)
!   2. Take absolute value, subtract constant 0x00AC (172)
!   3. Clamp result to range [0x38, 0xB8] (56 to 184 pixels)
!   4. If original value was negative, negate clamped result
!   5. Scale clamped value: multiply by 0xFF (255), compute scaled offset
!   6. Call FUN_0602ECCC three times with different base/scale pairs:
!      - Call 1: scale × base, offset 0x96/0x50 (horizontal viewport)
!      - Call 2: base 0x78(120), offset 0x80(128) (vertical viewport)
!      - Call 3: offset 0x90 (depth/Z viewport)
!   7. Write viewport bounds to camera object
!
! FUN_0602ECCC is a HARDWARE DIVISION function using the SH-2 divider unit:
!   - Disables interrupts (ldc #0xF0,sr) to protect the division registers
!   - Writes divisor (r0) to 0xFFFFFF00 (DVSR register)
!   - Writes dividend (r1) to 0xFFFFFF04 (DVDNT register, triggers division)
!   - Reads quotient from 0xFFFFFF14 after nop wait cycles
!   - Restores SR and returns quotient in r0
!   - Signature: r0 = divide(r0=divisor, r1=dividend) → r0 = r1 / r0
!
! Each call computes one dimension of the viewport by dividing the
! scaled camera delta by a base value, producing viewport coordinates.
!
! Viewport clipping constants:
!   0xB8 (184) = maximum viewport extent
!   0x38 (56)  = minimum viewport extent
!   0x78 (120) = horizontal center
!   0x80 (128) = vertical center
!   0x98 (152) = secondary clamp value
!   0x84 (132) = tertiary field

! CONFIDENCE: HIGH -- Address confirmed as FUN_0602EFF0 label in binary.
!   Pool constant 0x0607E944 verified. Instruction sequence matches ground
!   truth. Algorithm interpretation is reasonable but field names are inferred.
! AUDIT NOTE: Called from FUN_0602EEB8 (per-car rendering orchestrator), NOT
!   directly from state handlers as the file header implies.
FUN_0602EFF0:                            ! 0x0602EFF0
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(0x2C,PC),r0              ! r0 = &0x0607E944 (camera state pointer)
    mov.l   @r0,r0                       ! r0 = camera_object
    mov     #0,r1                        ! Clear working registers
    mov     #0,r2
    mov     #0,r3
    mov     #0,r4
    mov     #0,r7
    mov     r0,r14                       ! r14 = camera_object

    ! Read camera movement delta
    mov.w   @(0x16,PC),r1              ! r1 = offset
    mov.l   @(r0,r1),r1               ! r1 = camera[offset] (movement delta)
    mov     r1,r6                        ! r6 = delta (save original sign)

    mov.w   @(0x12,PC),r2              ! r2 = 0x00AC (172, viewport base)
    mov.w   @(0x12,PC),r3              ! r3 = 0x00AC
    cmp/pz  r1                           ! delta >= 0?
    bt      .L_skip_abs
    neg     r1,r1                        ! r1 = abs(delta)

.L_skip_abs:
    sub     r2,r1                        ! r1 = abs(delta) - 0xAC
    cmp/pz  r1                           ! result >= 0?
    bt      .L_clamp_upper
    bra     .L_store_viewport
    mov     #0,r1                        ! Negative → clamp to 0

.L_clamp_upper:                          ! 0x0602F028
    sub     r2,r3                        ! r3 = 0xAC - 0xAC = 0 (or different val)
    cmp/gt  r1,r3                        ! r3 > r1?
    bt      .L_no_clamp
    mov     r3,r1                        ! Clamp r1 to r3

.L_no_clamp:                             ! 0x0602F030
    cmp/pz  r6                           ! Original delta >= 0?
    bt      .L_store_viewport
    neg     r1,r1                        ! Restore sign

.L_store_viewport:                       ! 0x0602F036
    mov     r0,r14                       ! r14 = camera_object
    mov.w   @(0x24,PC),r2              ! r2 = 0xFF (scale factor)
    muls.w  r1,r2                        ! macl = delta × 255
    mov.w   @(0x22,PC),r0              ! r0 = offset for first result
    sts     macl,r1                      ! r1 = scaled delta

    ! === First viewport dimension (horizontal) ===
    bsr     FUN_0602ECCC                 ! Hardware divide: r0 = r1 / r0
    nop

    ! Store result and load previous value for smoothing
    mov     r0,r2                        ! r2 = new value
    mov     r14,r0                       ! r0 = camera base
    mov.w   @(0x18,PC),r6              ! r6 = offset A
    mov.w   @(0x18,PC),r1              ! r1 = offset B
    mov.l   @(r0,r6),r4               ! r4 = old_value_A
    mov.l   r2,@(r0,r6)               ! Write new_value_A
    mov.l   r4,@(r0,r1)               ! old_A → slot_B (for smoothing)

    ! Check horizontal boundary (0xB8 = 184)
    mov.w   @(0x12,PC),r3
    mov.l   @(r0,r3),r1               ! r1 = current viewport width
    mov.l   @(0x14,PC),r2              ! r2 = 0xB8 (max extent)
    cmp/ge  r1,r2                        ! max >= width?
    bt      .L_upper_ok                  ! Yes → check lower bound
    bra     .L_clamp_and_store
    mov     r2,r1                        ! Clamp to max

.L_upper_ok:                             ! 0x0602F070
    ! Check lower boundary (0x38 = 56)
    mov.l   @(0x30,PC),r2              ! r2 = 0x38 (min extent)
    cmp/ge  r1,r2                        ! min >= width?
    bf      .L_no_hclamp
    mov     r2,r1                        ! Clamp to min

.L_no_hclamp:                            ! 0x0602F078
    ! === Second viewport dimension (vertical) ===
    mov.l   @(0x28,PC),r2              ! r2 = 0x38 (base subtract)
    sub     r2,r1                        ! r1 -= 0x38
    mov.w   @(0x20,PC),r3
    mulu.w  r3,r1                        ! Scale
    mov.l   r0,@-r15                     ! Save camera ptr on stack
    mov.l   @(0x24,PC),r3              ! r3 = 0x78 (120, center)
    sts     macl,r1
    mov.l   @(0x24,PC),r0              ! r0 = 0x80 (128, V center)
    bsr     FUN_0602ECCC                 ! HW divide: vertical dimension
    nop
    mov.l   @r15+,r0                     ! Restore camera ptr

    ! Store vertical result
    mov.l   @(r0,r3),r2
    mov.l   r1,@(r0,r3)

    ! === Third viewport dimension (depth) ===
    mov.w   @(0xC,PC),r3
    mov.l   @(r0,r3),r1               ! r1 = Z viewport param
    mov.l   @(0x18,PC),r2              ! r2 = 0x98 (secondary clamp)
    cmp/ge  r1,r2
    bt      .L_z_upper_ok
    bra     .L_z_store
    mov     r2,r1                        ! Clamp Z to 0x98

.L_z_upper_ok:
    mov.l   @(0x2C,PC),r2              ! r2 = 0x38
    cmp/ge  r1,r2
    bf      .L_z_no_clamp
    mov     r2,r1

.L_z_no_clamp:
    mov.l   @(0x24,PC),r2
    sub     r2,r1
    mov.w   @(0x18,PC),r3
    mulu.w  r3,r1
    mov.l   r0,@-r15
    sts     macl,r1
    mov.w   @(0x12,PC),r0
    bsr     FUN_0602ECCC                 ! HW divide: depth dimension
    nop
    mov.l   @r15+,r0

    ! Store depth result
    mov.w   @(0xC,PC),r3
    mov.l   r1,@(r0,r3)

    lds.l   @r15+,pr
    mov.l   @r15+,r14
    rts
    nop


! ============================================================================
! 0x0602F0E8 — Rendering Pass 2: Frame Buffer Smoothing
! ============================================================================
! Called after FUN_0602EFF0. This is NOT labeled as a separate function in
! aprog.s (no FUN_ prefix), but is called via pool constant references.
!
! Performs exponential smoothing on the camera/render state:
!   1. Read value from camera[offset_B0]
!   2. Shift left 8 (scale up)
!   3. Add to camera[offset_D0] (running average)
!   4. Arithmetic shift right (divide by 2 = exponential decay)
!   5. Store back to camera[offset_D0]
!
! This creates smooth camera tracking — the viewport follows the car with
! a weighted average rather than snapping instantly.
!
! Then checks several flags to decide what to update:
!   - If camera[offset_B8] is nonzero → skip (rendering locked)
!   - If camera[offset_1BC] is nonzero → skip
!   - Otherwise: Copy camera[offset_94] → camera[offset_84]
!                 Copy camera[offset_68] → camera[offset_78]
!     (Update active viewport from computed viewport)
!
! If none of those copies happened, zeros out specific fields and performs
! a position-wrapping check using constant 0x71C (1820):
!   - If camera[offset_D0] < 0 → add 0x71C (wrap around track)
!   - If result >= 0x71C → subtract 0x71C (wrap other direction)
!   - Clamp to [0, 0x71C) range

! CONFIDENCE: HIGH -- Address exists in binary. Called from FUN_0602EEB8
!   and state handler FUN_06009098. Exponential smoothing interpretation
!   consistent with shar instruction. Not a FUN_ label in aprog.s.
! 0x0602F0E8:
    mov.l   @(0x40,PC),r2              ! r2 = &0x0607E944
    mov.l   @r2,r0                       ! r0 = camera_object
    mov.w   @(0x2E,PC),r1              ! r1 = 0xB0 (source offset)
    mov.l   @(r0,r1),r2               ! r2 = camera[0xB0] (raw tracking value)
    shll8   r2                           ! r2 <<= 8 (scale up for smoothing)
    mov.w   @(0x2A,PC),r3              ! r3 = 0xD0 (running average offset)
    mov.l   @(r0,r3),r4               ! r4 = camera[0xD0] (previous average)
    add     r4,r2                        ! r2 = scaled_raw + previous_avg
    shar    r2                           ! r2 >>= 1 (arithmetic: exponential decay)
    mov.l   r2,@(r0,r3)               ! camera[0xD0] = new smoothed value

    ! Check rendering lock flags
    mov.w   @(0x22,PC),r1              ! r1 = 0xB8 offset
    mov.l   @(r0,r1),r3               ! r3 = camera[0xB8]
    tst     r3,r3                        ! Zero?
    bf      .L_render_skip               ! Non-zero → rendering locked, skip

    mov.w   @(0x1C,PC),r2              ! r2 = 0x1BC offset
    mov.l   @(r0,r2),r4               ! r4 = camera[0x1BC]
    tst     r4,r4
    bf      .L_render_skip               ! Non-zero → skip

    ! Copy computed viewport to active viewport
    mov.w   @(0x16,PC),r1              ! r1 = 0x94 (computed viewport offset)
    mov.l   @(r0,r1),r2               ! r2 = camera[0x94]
    mov.l   @(0x1C,PC),r3              ! r3 = 0x84 (active viewport offset)
    mov.l   r2,@(r0,r3)               ! camera[0x84] = computed value

    mov.w   @(0x10,PC),r1              ! r1 = 0x68
    mov.l   @(r0,r1),r2               ! r2 = camera[0x68]
    mov.w   @(0xE,PC),r3               ! r3 = 0x78
    rts
    mov.l   r2,@(r0,r3)               ! (delay) camera[0x78] = camera[0x68]

.L_render_skip:                          ! 0x0602F134
    ! Clear fields and perform position wrap
    mov     #0,r5
    mov.w   @(0x20,PC),r1
    mov.w   r5,@(r0,r1)               ! Clear a word field

    mov.w   @(0x1E,PC),r5
    mov.w   @(0x1E,PC),r1
    mov.l   r5,@(r0,r1)               ! Write constant value
    mov.w   @(0x1C,PC),r1
    mov.l   r5,@(r0,r1)               ! Write to secondary field

    ! Position wrapping (track loop: 0 to 0x71C range)
    mov     #0,r5
    mov.w   @(0x18,PC),r1
    mov.l   @(r0,r1),r4               ! r4 = camera[position]
    mov.l   @(0x18,PC),r2              ! r2 = 0x71C (1820 = track length?)
    cmp/pz  r4                           ! position >= 0?
    bt      .L_check_upper

    ! Position negative → wrap forward
    add     r2,r4                        ! position += 0x71C
    cmp/pz  r4
    bt      .L_pos_wrapped               ! Now positive → done
    bra     .L_pos_store
    nop

.L_check_upper:                          ! 0x0602F168
    sub     r2,r4                        ! position -= 0x71C
    cmp/pz  r4                           ! Still positive?
    bt      .L_pos_wrapped               ! Yes → wrapped (went past end)

.L_pos_store:                            ! 0x0602F16E
    mov.l   r4,@(r0,r1)               ! Store position
    rts
    nop

.L_pos_wrapped:                          ! 0x0602F174
    mov     #0,r5
    mov.l   r5,@(r0,r1)               ! Reset position to 0
    rts
    nop


! ============================================================================
! 0x0602F17C — Extended Frame Buffer State Machine
! ============================================================================
! Continuation of the frame buffer update code. Handles per-frame state
! transitions for the rendering pipeline.
!
! After 0x0602F0E8's position wrapping, this section:
!   1. Decrements/increments a frame counter toward zero (→0 convergence)
!   2. Reads a course-specific speed table from 0x060477AC
!   3. Compares camera position against course boundary values
!   4. If camera is outside boundaries, triggers a viewport adjustment
!
! This implements the course-aware camera system — the camera behaves
! differently on different sections of each course.
! ============================================================================

! CONFIDENCE: MEDIUM -- Address 0x0602F17C exists in binary (mov r0,r14).
!   Course boundary table addresses (0x060477AC, 0x0604779C) are plausible
!   but not independently verified. The course-aware camera interpretation
!   is reasonable but speculative.
_0x0602F17C:                            ! 0x0602F17C
    mov     r0,r14                     ! r14 = camera_object
    mov     #0,r5

    ! Frame counter convergence toward zero
    mov.w   @(0x36,PC),r8             ! r8 = offset (0xD8)
    mov.l   @(r0,r8),r2               ! r2 = camera[0xD8] (frame counter)
    tst     r2,r2                      ! counter == 0?
    bt      .counter_zero              ! already at zero
    cmp/pz  r2                         ! counter > 0?
    bf      .counter_neg
    add     #-2,r2                     ! positive: decrement by 2
.counter_neg:
    add     #1,r2                      ! negative: increment by 1 (or post-dec adjust)
.counter_zero:                         ! 0x0602F190
    mov.l   r2,@(r0,r8)               ! store adjusted counter

    ! Read course speed parameter
    mov.w   @(0x26,PC),r9             ! r9 = offset for course_index (word)
    mov.w   @(r0,r9),r2               ! r2 = camera[course_index] (course segment)
    mov.w   @(0x24,PC),r3             ! r3 = offset for camera position field
    shll2   r2                         ! r2 = segment × 4 (index into table)
    mov.l   @(r0,r3),r4               ! r4 = camera position
    mov.l   @(0x8,r0),r7              ! r7 = camera[0x08] (mode/state flag)
    tst     r7,r7
    bt      .use_default_table

    ! Active mode: use course boundary table A
    mov.l   @(0x1C,PC),r6             ! r6 = 0x060477AC (course table A)
    add     r2,r6                      ! r6 → table_A[segment]
    mov.l   @r6,r6                     ! r6 = boundary value A
    cmp/gt  r6,r4                      ! camera_pos > boundary_A?
    bt      .adjust_viewport           ! yes → trigger adjustment

.use_default_table:                    ! 0x0602F1AC
    ! Fallback: use course boundary table B
    mov.l   @(0x14,PC),r6             ! r6 = 0x0604779C (course table B)
    add     r2,r6
    mov.l   @r6,r6                     ! r6 = boundary value B
    cmp/ge  r4,r6                      ! boundary_B >= camera_pos?
    bt      .no_adjustment             ! camera within bounds
    bra     .do_viewport_update        ! outside bounds
    nop

.adjust_viewport:                      ! (triggered from table A check)
    ! ... viewport adjustment code continues ...
    ! Adjusts camera position based on course-specific parameters

.no_adjustment:                        ! (camera within bounds, return)
    ! ... return path ...


! ============================================================================
! FUN_0602ECCC — SH-2 Hardware Division
! ============================================================================
! Uses the SH-2's built-in 32-bit divider at 0xFFFFFF00.
! This is a critical performance function — division takes 39 cycles on SH-2,
! so the hardware unit is essential for real-time rendering.
!
! Signature: divide(r0=divisor, r1=dividend) → r0 = quotient, r1 = quotient
!
! The function disables interrupts during division to prevent corruption
! of the division registers (which are shared system resources).
!
! SH-2 Division Unit registers:
!   0xFFFFFF00  — DVSR (Divisor Register)
!   0xFFFFFF04  — DVDNT (Dividend Register) — writing triggers division
!   0xFFFFFF14  — DVDNT (Result Register) — quotient available after ~39 cycles
!
! The nop instructions between write and read provide the minimum wait
! time for the division to complete.
! ============================================================================

! CONFIDENCE: DEFINITE -- Every instruction verified byte-for-byte against
!   binary. Pool constant 0xFFFFFF00 confirmed at 0x0602ECEC. Hardware
!   divider register addresses (DVSR, DVDNT, result) match SH-2 manual.
FUN_0602ECCC:                            ! 0x0602ECCC
    mov.l   r3,@-r15                   ! save r3
    mov     #-16,r3                    ! r3 = 0xFFFFFFF0
    stc.l   SR,@-r15                   ! save current SR (interrupt state)
    extu.b  r3,r3                      ! r3 = 0xF0 (interrupt mask bits)
    ldc     r3,sr                      ! SR = 0xF0 → DISABLE ALL INTERRUPTS

    ! Perform hardware division
    mov.l   @(0x14,PC),r3             ! r3 = 0xFFFFFF00 (divider unit base)
    mov.l   r0,@r3                     ! DVSR = r0 (write divisor)
    nop                                ! wait
    mov.l   r1,@(0x4,r3)              ! DVDNT = r1 (write dividend → triggers division)
    nop                                ! wait for division to complete
    mov.l   @(0x14,r3),r0             ! r0 = quotient (read result)
    nop                                ! pipeline flush

    ldc.l   @r15+,sr                   ! RESTORE INTERRUPTS (load saved SR)
    mov.l   @r15+,r3                   ! restore r3
    rts
    mov     r0,r1                      ! (delay) r1 = quotient copy


! ============================================================================
! FUN_06027CA4 — 3D Scene Processor (Polygon Culling & Depth Ordering)
! ============================================================================
! CONFIDENCE: HIGH -- Function label confirmed. Prologue matches exactly.
!   Pool constants 0x04000000, 0x03FFFFFF, 0x0607EAD8, 0x060C2000, 0x060BF000,
!   0x060A6000 all verified. Frustum culling interpretation well-supported by
!   dmuls.l instructions and flag bit testing.
!
! This is the main 3D polygon rendering processor. It processes course
! segments and their polygons, performing matrix transforms, backface
! culling, and generating VDP1 commands in the correct draw order.
!
! CRITICAL INSIGHT: There is NO runtime sorting algorithm.
! Polygon draw order is pre-baked into the course segment data.
! The course segment table at 0x060C2000 lists polygons in back-to-front
! order relative to the camera direction. This is standard for racing
! games where the camera always faces along the track.
!
! INPUTS:
!   r4 = camera/view matrix structure:
!     r4[0]  = camera Z position (for segment calculation)
!     r4[4]  = camera matrix column A
!     r4[8]  = camera matrix column B
!
!   r5 = rendering context (pushed to stack)
!
! ALGORITHM:
!   1. Compute visible segment range from camera position:
!      - start_segment = (cam_Z + 0x04000000) >> 21
!      - count = (0x03FFFFFF - cam[8]) >> 21, scaled up
!      - start += count (adjusts for camera facing direction)
!
!   2. Mode check: [0x0607EAD8]
!      - Mode 2: use overlay table at 0x06061270 (scans for matching segment)
!      - Otherwise: standard segment processing
!
!   3. For each visible course segment:
!      a. Look up course segment table at 0x060C2000:
!         - segment[0] (word) = first polygon index
!         - segment[2] (word) = polygon count
!      b. While polygon count > 0:
!         - Look up material/texture at 0x060BF000[polygon_index]
!         - Calculate polygon data address: 0x060A6000 + (material * 52)
!         - Read polygon flags (word at +0) and vertex data (at +16)
!         - Transform vertex using camera matrix (dmuls.l for 64-bit multiply)
!         - Add offsets based on flag bits:
!           * Flag 0x01000000: add camera column B
!           * Flag 0x02000000: use different coordinate system
!           * Flag 0x04000000: check positive Z (backface test)
!           * Flag 0x08000000: check negative Z (frustum test)
!         - If polygon fails cull test: skip (advance index, decrement count)
!         - If polygon passes: transform second vertex, generate VDP1 command
!
! KEY DATA STRUCTURES:
!   0x060C2000 — Course segment table (4 bytes per segment)
!     Each entry: [polygon_start_index : word][polygon_count : word]
!     Segments are ordered by track position (back-to-front from camera)
!
!   0x060BF000 — Texture/material index table
!     Maps polygon index → material index (word entries)
!     Material index selects which 52-byte entry from polygon pool
!
!   0x060A6000 — Polygon data pool (52 bytes per entry = 0x34)
!     +0x00: flags word (coordinate system, cull mode bits)
!     +0x10: vertex A transform parameters (2 x 32-bit: multiply, add)
!     +0x18: vertex B transform parameters
!     +0x20: vertex C transform parameters
!     +0x28: vertex D transform parameters (4-vertex quads)
!     +0x30: color/material byte
!
!   0x06061270 — Overlay/sprite segment table (mode 2)
!     Word entries listing segment IDs for overlay rendering pass
!     Zero-terminated
!
! RENDERING ORDER:
!   The VDP1 command list is built in the order polygons are processed.
!   Since course segments are traversed back-to-front, and each segment's
!   polygon list is pre-ordered by the track data toolchain, the resulting
!   VDP1 command chain implements the painter's algorithm:
!
!   1. Furthest track segment → polygons rendered first (background)
!   2. Nearest track segment → polygons rendered last (foreground)
!   3. VDP1 draws later commands on top of earlier ones
!
!   This avoids any runtime sorting. For a racing game with a fixed
!   camera-along-track perspective, pre-baked ordering is optimal.
!
! VDP1 COMMAND CHAIN:
!   The 7 command builder functions at 0x0602C494-0x0602D43C create
!   32-byte VDP1 command blocks:
!     +0x00: CMDCTRL (command type: distorted sprite, polygon, etc.)
!     +0x04: CMDLINK (pointer to next command in chain)
!     +0x08: CMDPMOD (polygon mode: Gouraud, texture, etc.)
!     +0x0C: CMDCOLR (color bank / palette)
!     +0x10: CMDSRCA (texture source address in VRAM)
!     +0x14: CMDSIZE (texture dimensions)
!     +0x18: CMDXA/CMDYA (vertex A screen coordinates)
!     +0x1C: CMDXB/CMDYB (vertex B screen coordinates)
!
!   CMDLINK fields chain commands into a linked list that VDP1
!   hardware traverses autonomously during display.
!
! FUN_0602DB22 — Per-Frame Command List Reset
!   Zeros out command buffer state variables:
!     0x06082A30 = 0 (command count reset)
!     0x06082A26 = 0 (command index reset)
!     0x060788FC = 0 (render state)
!     0x06082A38 = 0 (auxiliary buffer)
!   Sets initial depth scaling: 0x00FA0000 * 0x0000038E (dmuls.l)
!   Configures draw distance: 0xFA (250) units, 0x0C near plane
!   References speed table at 0x0605A1C4 (same as AI speed boost)
