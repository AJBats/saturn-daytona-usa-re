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

.L_vdp1_clear_loop_A:                   ! 0x0600A150
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
!   0x0600A19C = 0x80000000  (VDP1 enable/reset value)
!   0x0600A1A0 = 0x25C00000  (VDP1 control register base)
!   0x0600A1A4 = 0x25C80000  (VDP1 VRAM start)
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
