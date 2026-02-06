! =============================================================================
! Math Helpers & Utility Library
! =============================================================================
!
! Address range: 0x06027344 - 0x0602766A
!
! This file documents the core math utility functions used throughout
! the game engine. These are the lowest-level building blocks upon which
! physics, 3D rendering, collision, and AI all depend.
!
! The math_transform.s file documents the 3D matrix pipeline built ON TOP
! of these helpers.
!
! Function catalog:
!   0x06027344  cos_lookup       — cos(angle) via lookup table
!   0x06027348  sin_lookup       — sin(angle) via lookup table (cos + 0x4000)
!   0x06027358  sincos_pair      — returns both sin and cos for an angle
!   0x06027378  atan_piecewise   — piecewise linear atan approximation
!   0x0602744C  atan2            — full atan2(y, x) with quadrant handling
!   0x0602745C  atan2_full       — atan2 inner computation (non-degenerate case)
!   0x06027476  isqrt            — integer square root via binary search
!   0x06027498  vec3_normalize   — normalize 3D vector to unit length
!   0x060274DA  vec3_dot         — dot product using MAC unit
!   0x0602754C  swap_sign_ext    — swap.w + exts.w helper
!   0x06027552  fpmul            — 16.16 fixed-point multiply
!   0x0602755C  fpdiv_setup      — fixed-point divide via SH-2 hardware divider
!   0x06027574  memcpy_byte      — byte-level memory copy (bidirectional)
!   0x060275A4  memcpy_word      — word-level memory copy (bidirectional)
!   0x060275D8  memcpy_long      — long-level memory copy (bidirectional)
!   0x0602760C  memcpy_byte_idx  — byte copy (index-based, forward only)
!   0x0602761E  memcpy_word_idx  — word copy (index-based, forward only)
!   0x06027630  memcpy_long_idx  — long copy (index-based, forward only)
!   0x06027642  memcpy_block32   — 32-byte block copy (8 longs per iteration)
!   0x0602766C  dma_transfer     — DMA transfer to VDP1
!   0x0602769C  viewport_project — perspective projection to screen coords
!   0x0602ECCC  hw_divide        — protected hardware integer divide
!
! Also documents key data structures:
!   0x002F2F20  sin/cos lookup table (ROM space, 256 entries, 4 bytes each)
!   0x002F0000  atan lookup table (ROM space)
!   0xFFFFFF00  SH-2 hardware division unit registers
!   0x25FE0000  VDP1 DMA controller registers


! =============================================================================
! Number Representations
! =============================================================================
!
! All arithmetic in this engine is INTEGER. The SH-2 has no FPU.
!
! 16.16 Fixed-Point:
!   Upper 16 bits = integer part, lower 16 bits = fractional part
!   0x00010000 = 1.0
!   0x00008000 = 0.5
!   0xFFFF0000 = -1.0 (two's complement)
!
! Angles:
!   Full circle = 0x10000 (65536 units)
!   90 degrees  = 0x4000
!   180 degrees = 0x8000
!   The angle unit is 360/65536 = ~0.0055 degrees
!
! The key instruction for 16.16 multiply:
!   dmuls.l r4,r5    ; 32x32 → 64-bit result in mach:macl
!   sts mach,rN      ; high 32 bits
!   sts macl,rM      ; low 32 bits
!   xtrct rN,rM      ; rM = (rN<<16) | (rM>>16) = middle 32 bits
!
! The xtrct instruction (opcode 0x2NMD) extracts the middle 32 bits
! of a 64-bit value, implementing (a * b) >> 16 in a single instruction.
! The disassembler shows these as .word 0xNNNN since it doesn't know xtrct.
!
! Note: the disassembler also shows movt Rn (0x0N29) as .word values.
! movt Rn copies the T flag (from cmp instructions) into register Rn.


! =============================================================================
! 0x06027344 — cos_lookup(angle)
! =============================================================================
! Input:  r4 = angle (16-bit, 0-0xFFFF = 0-360 degrees)
! Output: r0 = cos(angle) in 16.16 fixed-point
!
! Algorithm:
!   r4 += cos_offset     (add 0x4000 = 90 degrees to convert cos to sin)
!   r4 >>= 2             (reduce to 8-bit table index)
!   r4 += 2              (skip header)
!   r4 &= table_mask     (0x3FC = wrap around 256 entries * 4 bytes)
!   r0 = table[r4]       (load from 0x002F2F20)
!   return r0
!
! The sin/cos table at 0x002F2F20 contains 256 entries of 4 bytes each.
! One full sine wave covers entries 0-255. Cosine is sine shifted by 64.

FUN_06027344:  ! cos_lookup at 0x06027344
    mov.w   @(PC_offset),r0        ! cos offset (0x4000 = 90 degrees)
    add     r0,r4                  ! angle + 90
    mov.w   @(PC_offset),r0        ! table mask (0x3FC)
    shlr2   r4                     ! /4 for table index
    add     #2,r4                  ! skip header
    and     r0,r4                  ! wrap to table size
    mov.l   @(PC_offset),r0        ! 0x002F2F20 (table base)
    rts
    mov.l   @(r0,r4),r0            ! return table[index]


! =============================================================================
! 0x06027348 — sin_lookup(angle)
! =============================================================================
! Input:  r4 = angle
! Output: r0 = sin(angle) in 16.16 fixed-point
!
! Same as cos_lookup but adds sin_offset instead of cos_offset.
! (sin_offset = 0, so r4 is used directly)

FUN_06027348:  ! sin_lookup at 0x06027348
    ! Same algorithm as cos_lookup but with sin phase offset


! =============================================================================
! 0x06027358 — sincos_pair(angle, &sin_out, &cos_out)
! =============================================================================
! Input:  r4 = angle, r5 = sin output ptr, r6 = cos output ptr
! Output: *r5 = sin(angle), *r6 = cos(angle)
!
! Algorithm:
!   r3 = angle + 8       (rounding offset)
!   r1 = table mask
!   r3 += r4             (adjust)
!   Load table base 0x002F2F20
!   r4 >>= 2, r4 &= mask  (sin index)
!   r3 >>= 2, r3 &= mask  (cos index, phase-shifted)
!   *r5 = table[r4]      (sin)
!   *r6 = table[r3]      (cos)

FUN_06027358:  ! sincos_pair at 0x06027358
    mov.w   @(PC),r3               ! phase offset (for cos)
    add     #8,r4                  ! rounding
    mov.w   @(PC),r1               ! table mask (0x3FC)
    add     r4,r3                  ! r3 = angle + cos_phase
    mov.l   @(PC),r0               ! 0x002F2F20 table base
    shlr2   r4                     ! sin index
    and     r1,r4
    shlr2   r3                     ! cos index
    mov.l   @(r0,r4),r2            ! sin value
    and     r1,r3
    mov.l   r2,@r5                 ! *sin_out = sin(angle)
    nop
    mov.l   @(r0,r3),r1            ! cos value
    rts
    mov.l   r1,@r6                 ! *cos_out = cos(angle)


! =============================================================================
! 0x06027378 — atan_piecewise(value, sign_flag)
! =============================================================================
! Input:  r4 = absolute value (positive), r6 = sign flag (0=negate, 1=keep)
! Output: r0 = atan(value) as angle (0-0x4000 range)
!
! This is a PIECEWISE LINEAR approximation of arctangent.
! The input range is divided into 8 segments, each with its own
! slope and intercept.
!
! Algorithm:
!   if (r4 < 0): r4 = -r4, save sign via movt r6
!   r0 = 16 << 16 = 0x100000 (upper bound check)
!   r4 += 128                 (rounding)
!   if r4 < 0x100000:
!     ! Small angle: use lookup table directly
!     r4 >>= 8               (reduce precision)
!     r4 <<= 1               (word index)
!     r0 = atan_table[r4]    (load from 0x002F0000)
!   else:
!     ! Large angle: piecewise interpolation
!     r5 = r4 >> 16          (integer part)
!     ! 8 range checks with increasing thresholds:
!     !   1000, 500, 250, 150, 100, 70, 50, 40, 30, 16
!     ! For matching range:
!     !   r4 -= segment_base
!     !   r0 = (r4 * slope) >> 16  (via dmuls.l + sts mach)
!     !   r0 = sign_extend(r0)
!     !   r0 += intercept
!
!   if (r6 == 0): r0 = -r0   (negate for original sign)
!   return r0
!
! Piecewise segment data (slopes and intercepts from pool constants):
!   Segment 1 (>1000): slope=0x00000AC0, intercept from pool
!   Segment 2 (>500):  slope=0x00001581
!   Segment 3 (>250):  slope=0x000047AE
!   Segment 4 (>150):  slope=0x0000B333
!   Segment 5 (>100):  slope=0x00018000
!   Segment 6 (>70):   slope=0x0002F333
!   Segment 7 (>50):   slope=0x00053333
!   Segment 8 (>40):   slope=0x0008B333
!   Segment 9 (>30):   slope=0x0015B6DB
!   Segment 10 (>16):  base case

FUN_06027378:  ! atan_piecewise at 0x06027378
    cmp/pz  r4                     ! r4 >= 0?
    bt/s    .atan_abs_done         ! skip negate
    movt    r6                     ! r6 = sign (1=positive, 0=negative)
    neg     r4,r4                  ! r4 = abs(r4)
.atan_abs_done:
    ! ... 8 range checks with piecewise interpolation ...
    ! Final formula: r0 = intercept + (value - base) * slope
    rts


! =============================================================================
! 0x0602744C — atan2(y, x)
! =============================================================================
! Input:  r4 = x, r5 = y
! Output: r0 = atan2(y, x) as angle (0-0xFFFF = 0-360 degrees)
!
! Special cases:
!   y == 0: return +/- 0x4000 (90 degrees) based on sign of x
!   y != 0: fall through to atan2_full
!
! Algorithm:
!   if (r5 == 0):             ! y == 0
!     r0 = 0x4000             ! 90 degrees
!     if (r4 >= 0): return r0
!     else: return -r0        ! 270 degrees
!   else:
!     call atan2_full

FUN_0602744C:  ! atan2 at 0x0602744C
    tst     r5,r5                  ! y == 0?
    bf      FUN_0602745C           ! y != 0 → full computation
    mov.w   @(PC),r0               ! r0 = 0x4000 (90 degrees)
    cmp/pz  r4                     ! x >= 0?
    bt      .atan2_ret             ! positive → return 0x4000
    neg     r0,r0                  ! negative → return -0x4000
.atan2_ret:
    rts
    nop


! =============================================================================
! 0x0602745C — atan2_full(x, y)
! =============================================================================
! Input:  r4 = x, r5 = y (y guaranteed non-zero)
! Output: r0 = atan2(y, x) as angle
!
! Algorithm:
!   1. Save sign of y into r7 via cmp/pz + movt
!   2. Call fpdiv_setup to compute x/y (or y/x)
!   3. Call atan_piecewise to get base angle
!   4. Adjust for quadrant using r7:
!      if (r7 == 0): add 0x8000 (180 degrees) for negative y
!   5. Sign-extend result to 32 bits

FUN_0602745C:  ! atan2_full at 0x0602745C
    sts.l   pr,@-r15               ! save return address
    cmp/pz  r5                     ! y >= 0?
    bsr     FUN_0602755C           ! call fpdiv_setup (divide x/y)
    movt    r7                     ! r7 = sign of y (1=pos, 0=neg)
    bsr     FUN_06027378           ! call atan_piecewise
    mov     r0,r4                  ! r4 = ratio for atan
    lds.l   @r15+,pr               ! restore return
    tst     r7,r7                  ! check quadrant
    bf      .atan2_no_adjust       ! y was positive → no adjustment
    mov.l   @(PC),r2               ! r2 = 0x00008000 (180 degrees)
    add     r2,r0                  ! add 180 degrees for quadrants 3-4
.atan2_no_adjust:
    rts
    exts.w  r0,r0                  ! sign-extend to 32 bits


! =============================================================================
! 0x06027476 — isqrt(value)
! =============================================================================
! Input:  r4 = value (32-bit unsigned)
! Output: r0 = floor(sqrt(value)) << 8 (shifted for fixed-point)
!
! Uses binary search (bit-by-bit refinement):
!   guess = 0
!   bit = 0x8000 (start with MSB)
!   loop:
!     trial = guess + bit
!     if (trial * trial <= value):
!       guess = trial       (keep the bit)
!     bit >>= 1
!     repeat while bit > 0
!   return guess << 8
!
! The final shll8 scales the integer root into a format compatible
! with the 16.16 fixed-point system (giving ~8 bits of fractional precision).

FUN_06027476:  ! isqrt at 0x06027476
    cmp/pl  r4                     ! value > 0?
    bf/s    .sqrt_done             ! zero/negative → return 0
    mov     #0,r0                  ! guess = 0
    mov.l   @(PC),r2               ! r2 = 0x8000 (initial bit)
    add     r2,r0                  ! trial = guess + bit
.sqrt_loop:
    mul.l   r0,r0                  ! trial * trial
    sts     macl,r3                ! r3 = trial^2
    cmp/eq  r4,r3                  ! exact match?
    bt      .sqrt_done             ! perfect square found
    cmp/hi  r4,r3                  ! trial^2 > value?
    bf      .sqrt_keep             ! trial^2 <= value: keep bit
    sub     r2,r0                  ! trial^2 > value: remove bit
.sqrt_keep:
    shlr    r2                     ! bit >>= 1
    cmp/pl  r2                     ! more bits to test?
    bt      .sqrt_loop
.sqrt_done:
    rts
    shll8   r0                     ! scale result << 8


! =============================================================================
! 0x06027498 — vec3_normalize(vec*)
! =============================================================================
! Input:  r4 = pointer to 3-element int vector (12 bytes: X, Y, Z)
! Output: vector normalized to unit length in-place
!
! Algorithm:
!   r14 = vec pointer
!   mag_sq = vec3_dot(vec, vec)          (call 0x060274DA)
!   mag = isqrt(mag_sq)                  (call 0x06027476)
!   if (mag <= 0): return (zero vector)
!   inv_mag = fpdiv(0x00010000, mag)     (call 0x0602755C: 1.0 / mag)
!   vec->X = fpmul(vec->X, inv_mag)     (dmuls.l + xtrct)
!   vec->Y = fpmul(vec->Y, inv_mag)
!   vec->Z = fpmul(vec->Z, inv_mag)
!
! Uses callee-saved r14 to preserve vector pointer across calls.

FUN_06027498:  ! vec3_normalize at 0x06027498
    mov.l   r14,@-r15              ! save r14
    sts.l   pr,@-r15               ! save return
    mov     r4,r14                 ! r14 = vec pointer
    bsr     FUN_060274DA           ! vec3_dot(vec, vec)
    mov     r4,r5                  ! r5 = r4 (dot with self)
    bsr     FUN_06027476           ! isqrt(magnitude_squared)
    mov     r0,r4                  ! r4 = magnitude_squared
    cmp/pl  r0                     ! magnitude > 0?
    bf      .norm_done             ! zero vector → skip
    mov.l   @(PC),r4               ! r4 = 0x00010000 (1.0 in 16.16)
    bsr     FUN_0602755C           ! fpdiv(1.0, magnitude)
    mov     r0,r5                  ! r5 = magnitude

    ! Scale each component by 1/magnitude
    mov.l   @(0x0,r14),r1         ! X
    dmuls.l r0,r1                  ! X * inv_mag (64-bit)
    mov.l   @(0x8,r14),r3         ! Z (load early for pipeline)
    sts     mach,r4
    sts     macl,r1
    xtrct   r4,r1                  ! r1 = (X * inv_mag) >> 16
    dmuls.l r0,r2                  ! Y * inv_mag
    mov.l   r1,@(0x0,r14)         ! store X
    sts     mach,r4
    sts     macl,r2
    xtrct   r4,r2                  ! r2 = (Y * inv_mag) >> 16
    dmuls.l r0,r3                  ! Z * inv_mag
    mov.l   r2,@(0x4,r14)         ! store Y
    sts     mach,r4
    sts     macl,r3
    xtrct   r4,r3                  ! r3 = (Z * inv_mag) >> 16
    mov.l   r3,@(0x8,r14)         ! store Z

.norm_done:
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! =============================================================================
! 0x060274DA — vec3_dot(a*, b*)
! =============================================================================
! Input:  r4 = pointer to vec3 A, r5 = pointer to vec3 B
! Output: r0 = A.X*B.X + A.Y*B.Y + A.Z*B.Z (16.16 fixed-point)
!
! Uses the SH-2 MAC (Multiply-Accumulate) unit:
!   clrmac                   ; clear accumulator
!   mac.l @r4+,@r5+         ; mach:macl += A.X * B.X
!   mac.l @r4+,@r5+         ; mach:macl += A.Y * B.Y
!   mac.l @r4+,@r5+         ; mach:macl += A.Z * B.Z
!   sts mach,r1              ; high 32 bits
!   sts macl,r0              ; low 32 bits
!   xtrct r1,r0              ; r0 = middle 32 bits = result >> 16
!
! LEAF function (no subroutine calls). Total: 7 instructions.

FUN_060274DA:  ! vec3_dot at 0x060274DA
    clrmac                         ! clear accumulator
    mac.l   @r4+,@r5+             ! acc += A.X * B.X
    mac.l   @r4+,@r5+             ! acc += A.Y * B.Y
    mac.l   @r4+,@r5+             ! acc += A.Z * B.Z
    sts     mach,r1                ! high 32
    sts     macl,r0                ! low 32
    rts
    xtrct   r1,r0                  ! r0 = (mach<<16)|(macl>>16)


! =============================================================================
! 0x06027552 — fpmul(a, b) — Fixed-Point Multiply
! =============================================================================
! Input:  r4 = a (16.16), r5 = b (16.16)
! Output: r0 = (a * b) >> 16 (16.16 result)
!
! This is THE fundamental fixed-point multiply used everywhere.
! 4 instructions total. Called hundreds of times per frame.
!
! The dmuls.l gives a 64-bit signed result in mach:macl.
! The xtrct picks out the middle 32 bits, which is exactly
! (a * b) >> 16 — the correct 16.16 fixed-point product.

FUN_06027552:  ! fpmul at 0x06027552
    dmuls.l r4,r5                  ! mach:macl = r4 * r5 (signed 64-bit)
    sts     mach,r4                ! r4 = high 32 bits
    sts     macl,r0                ! r0 = low 32 bits
    rts
    xtrct   r4,r0                  ! r0 = middle 32 = (a*b) >> 16


! =============================================================================
! 0x0602755C — fpdiv_setup(dividend, divisor) — SH-2 Hardware Divide
! =============================================================================
! Input:  r4 = dividend (16.16), r5 = divisor (16.16)
! Output: r0 = r4 / r5 (16.16 result)
!
! Uses the SH-2 hardware division unit at 0xFFFFFF00:
!   Register map:
!     +0x00  DVSR    — Divisor
!     +0x04  DVDNT   — Dividend (32/32 mode, triggers division)
!     +0x10  DVDNTH  — Dividend High (64/32 mode)
!     +0x14  DVDNTL  — Dividend Low  (64/32 mode, triggers division)
!     +0x1C  result  — Quotient (read after division completes)
!
! This function performs 64/32-bit division:
!   DVSR = r5                          (divisor)
!   DVDNTH = sign_extend(r4 >> 16)    (dividend high = integer part)
!   DVDNTL = r4 << 16                 (dividend low = fractional part)
!   r0 = result at +0x1C
!
! By shifting the dividend left 16 bits into the 64-bit pair,
! the hardware divide effectively computes (r4 << 16) / r5,
! which gives r4/r5 in 16.16 format.
!
! NOTE: This function does NOT disable interrupts. For interrupt-safe
! division, use FUN_0602ECCC (hw_divide_protected).

FUN_0602755C:  ! fpdiv_setup at 0x0602755C
    mov.w   @(PC),r2               ! r2 = 0xFFFFFF00 (sign-extended from 0xFF00)
    mov     r4,r3                  ! r3 = dividend
    mov.l   r5,@(0x0,r2)          ! DVSR = divisor
    shlr16  r3                     ! r3 = dividend >> 16 (integer part)
    exts.w  r3,r3                  ! sign extend
    mov.l   r3,@(0x10,r2)         ! DVDNTH = sign_extend(dividend >> 16)
    shll16  r4                     ! r4 = dividend << 16 (fractional part)
    mov.l   r4,@(0x14,r2)         ! DVDNTL = dividend << 16 (triggers division)
    rts
    mov.l   @(0x1C,r2),r0         ! r0 = quotient result


! =============================================================================
! 0x0602ECCC — hw_divide_protected(divisor, dividend) — Interrupt-Safe Divide
! =============================================================================
! Input:  r0 = divisor, r1 = dividend
! Output: r0 = r1 / r0, r1 = r0 (quotient)
!
! Same as fpdiv_setup but wraps the division in a critical section:
!   1. Save SR (status register) to stack
!   2. Set interrupt mask to 0xF0 (all interrupts disabled)
!   3. Perform 32/32 division using hardware unit
!   4. Restore SR (re-enable interrupts)
!
! This is necessary because the division unit is a SHARED RESOURCE.
! If an interrupt fires during division and the ISR also divides,
! the in-progress result gets corrupted.
!
! Uses DVSR (+0x00) and DVDNT (+0x04) for simple 32/32 division,
! reading result from DVDNTL (+0x14).

FUN_0602ECCC:  ! hw_divide_protected at 0x0602ECCC
    mov.l   r3,@-r15              ! save r3
    mov     #-16,r3               ! r3 = 0xFFFFFFF0
    stc.l   sr,@-r15              ! save status register
    extu.b  r3,r3                  ! r3 = 0xF0 (interrupt mask bits)
    ldc     r3,sr                  ! SR = 0xF0 (disable all interrupts)
    mov.l   @(PC),r3               ! r3 = 0xFFFFFF00 (division unit)
    mov.l   r0,@r3                 ! DVSR = divisor
    nop                            ! pipeline wait
    mov.l   r1,@(0x4,r3)          ! DVDNT = dividend (triggers 32/32 divide)
    nop                            ! wait for result
    mov.l   @(0x14,r3),r0         ! r0 = quotient
    nop
    ldc.l   @r15+,sr              ! restore SR (re-enable interrupts)
    mov.l   @r15+,r3              ! restore r3
    rts
    mov     r0,r1                  ! r1 = quotient (also)


! =============================================================================
! Memory Copy Functions (0x06027574 - 0x0602766A)
! =============================================================================
!
! Six memcpy variants optimized for different data widths.
! All share the same interface:
!   r4 = destination pointer
!   r5 = source pointer
!   r6 = byte count
!
! Bidirectional variants (0x06027574, 0x060275A4, 0x060275D8):
!   Detect overlap by comparing r4 vs r5.
!   If dst > src: copy backward (prevents corruption on overlap)
!   If dst <= src: copy forward
!   If dst == src or count == 0: return immediately
!
! Forward-only variants (0x0602760C, 0x0602761E, 0x06027630):
!   Use index register r0 starting at 0, incrementing by stride
!   Slightly more compact but no overlap handling


! =============================================================================
! 0x06027574 — memcpy_byte(dst, src, count)
! =============================================================================
! Byte-by-byte copy with overlap detection.
! Most flexible but slowest. Used for odd-sized or unaligned data.

FUN_06027574:  ! memcpy_byte at 0x06027574
    cmp/eq  r4,r5                  ! dst == src?
    bt      .byte_done             ! same address → nop
    mov     #0,r7
    cmp/eq  r7,r6                  ! count == 0?
    bt      .byte_done
    cmp/hi  r4,r5                  ! src > dst?
    bt      .byte_fwd              ! no overlap → forward copy

    ! Backward copy (dst > src, potential overlap)
    add     r6,r5                  ! src = src + count
    add     r6,r4                  ! dst = dst + count
    add     #-1,r5                 ! pre-decrement
.byte_bwd:
    mov.b   @r5,r7                 ! load byte
    dt      r6                     ! count--
    mov.b   r7,@-r4               ! store, pre-decrement dst
    bf/s    .byte_bwd
    add     #-1,r5                 ! pre-decrement src
.byte_done:
    rts
    nop

    ! Forward copy
.byte_fwd:
    mov.b   @r5+,r7               ! load, post-increment src
    dt      r6                     ! count--
    mov.b   r7,@r4                 ! store
    bf/s    .byte_fwd
    add     #1,r4                  ! post-increment dst
    rts
    nop


! =============================================================================
! 0x060275A4 — memcpy_word(dst, src, count)
! =============================================================================
! Word (16-bit) copy with overlap detection.
! count is in BYTES (divided by 2 internally via shlr).

FUN_060275A4:  ! memcpy_word at 0x060275A4
    ! Same structure as byte copy but uses mov.w and increments by 2


! =============================================================================
! 0x060275D8 — memcpy_long(dst, src, count)
! =============================================================================
! Long (32-bit) copy with overlap detection.
! count is in BYTES (divided by 4 internally via shlr2).

FUN_060275D8:  ! memcpy_long at 0x060275D8
    ! Same structure as byte copy but uses mov.l and increments by 4


! =============================================================================
! 0x0602760C — memcpy_byte_idx(dst, src, count)
! =============================================================================
! Forward-only byte copy using index register.
! Slightly more compact than bidirectional variant.

FUN_0602760C:  ! memcpy_byte_idx at 0x0602760C
    mov     #0,r0                  ! index = 0
    add     #-1,r6                 ! count-- (for loop termination)
.bidx_loop:
    mov.b   @(r0,r5),r1            ! r1 = src[index]
    cmp/gt  r0,r6                  ! index < count?
    mov.b   r1,@(r0,r4)            ! dst[index] = r1
    bt/s    .bidx_loop
    add     #1,r0                  ! index++
    rts
    add     #1,r6                  ! restore count (cosmetic)


! =============================================================================
! 0x0602761E — memcpy_word_idx(dst, src, count)
! =============================================================================
FUN_0602761E:  ! memcpy_word_idx at 0x0602761E
    ! Same as byte_idx but uses mov.w and increments by 2


! =============================================================================
! 0x06027630 — memcpy_long_idx(dst, src, count)
! =============================================================================
FUN_06027630:  ! memcpy_long_idx at 0x06027630
    ! Same as byte_idx but uses mov.l and increments by 4


! =============================================================================
! 0x06027642 — memcpy_block32(dst, src, block_count)
! =============================================================================
! High-performance block copy: copies 32 bytes per iteration.
! Loads 8 longwords into r0-r3 (4 at a time), stores 8, advances by 32.
! Used for large structure copies (matrix data, model geometry).
!
! Algorithm:
!   for each block:
!     r0 = @r5+, r1 = @r5+, r2 = @r5+, r3 = @r5+  (first 16 bytes)
!     @r4 = r0,r1,r2,r3 at offsets +0,+4,+8,+12
!     r0 = @r5+, r1 = @r5+, r2 = @r5+, r3 = @r5+  (next 16 bytes)
!     @r4 = r0,r1,r2,r3 at offsets +16,+20,+24,+28
!     r4 += 32
!     count--; repeat if > 0

FUN_06027642:  ! memcpy_block32 at 0x06027642
    mov.l   @r5+,r0
    mov.l   @r5+,r1
    mov.l   @r5+,r2
    mov.l   @r5+,r3
    mov.l   r0,@(0x00,r4)
    mov.l   r1,@(0x04,r4)
    mov.l   r2,@(0x08,r4)
    mov.l   r3,@(0x0C,r4)
    mov.l   @r5+,r0
    mov.l   @r5+,r1
    mov.l   @r5+,r2
    mov.l   @r5+,r3
    mov.l   r0,@(0x10,r4)
    mov.l   r1,@(0x14,r4)
    mov.l   r2,@(0x18,r4)
    mov.l   r3,@(0x1C,r4)
    dt      r6                     ! count--
    bf/s    FUN_06027642           ! loop
    add     #32,r4                 ! advance dst
    rts
    nop


! =============================================================================
! 0x0602766C — dma_transfer(src, dst, size)
! =============================================================================
! Input:  r4 = source address, r5 = dest address, r6 = size
! Output: DMA transfer initiated to VDP1
!
! VDP1 DMA controller at 0x25FE0000:
!   +0x00  source address
!   +0x04  destination address
!   +0x08  transfer size
!   +0x0C  transfer mode/control
!   +0x10  enable (written last to start transfer)
!   +0x14  enable copy
!
! Status register at 0x25FE007C:
!   Bit check with mask 0x0000272E — busy wait until clear
!
! Algorithm:
!   do {
!     status = *0x25FE007C
!   } while (status & 0x272E)     ! wait for DMA idle
!   0x25FE0004 = r4               ! source
!   0x25FE0000 = r5               ! destination
!   0x25FE0008 = r6               ! size
!   0x25FE000C = 0x0101           ! mode (word transfer, auto-increment)
!   0x25FE0014 = 7                ! enable flags
!   0x25FE0010 = 0x0101           ! start transfer

FUN_0602766C:  ! dma_transfer at 0x0602766C
    mov.l   @(PC),r0               ! 0x25FE007C (status register)
.dma_wait:
    mov.l   @r0,r0                 ! read status
    mov.l   @(PC),r1               ! 0x0000272E (busy mask)
    tst     r1,r0                  ! all busy bits clear?
    bf      .dma_wait              ! still busy → wait
    mov.l   @(PC),r1               ! 0x25FE0000 (DMA base)
    mov.w   @(PC),r2               ! 0x0101 (mode word)
    mov.l   r4,@(0x04,r1)         ! source
    mov.l   r5,@(0x00,r1)         ! destination
    mov.l   r6,@(0x08,r1)         ! size
    mov.l   r2,@(0x0C,r1)         ! mode = 0x0101
    mov     #7,r0
    mov.l   r0,@(0x14,r1)         ! enable = 7
    rts
    mov.l   r2,@(0x10,r1)         ! start = 0x0101 (delay slot)


! =============================================================================
! 0x0602769C — viewport_project(obj_ptr, screen_ptr)
! =============================================================================
! Input:  r4 = 3D object pointer, r5 = screen coordinate output
! Output: writes projected X,Y to *r5
!
! Uses dmuls.l with the camera projection matrix to convert
! 3D world coordinates into 2D screen coordinates.
!
! The projection constant at @(0x1C,r2) scales world units to screen pixels.
! The neg r0,r0 negates the Y coordinate (screen Y is inverted from world Y).

FUN_0602769C:  ! viewport_project at 0x0602769C
    mov.w   @(PC),r1               ! screen buffer offset
    mov.w   @(PC),r0               ! projection constants offset
    mov.l   @(0x8,r4),r2          ! obj->Z
    mov.l   r0,@(0x10,r1)         ! store projection constant
    mov.l   r2,@(0x0,r1)          ! store Z for depth
    mov     #0,r0
    mov.l   r0,@(0x14,r1)         ! clear Y projection
    mov.l   @(0x4,r4),r0          ! obj->Y
    mov.l   @r4,r2                 ! obj->X
    neg     r0,r0                  ! negate Y (screen inversion)
    mov.l   @(0x1C,r1),r4         ! projection factor
    dmuls.l r2,r4                  ! X * projection
    sts     mach,r2                ! high bits
    dmuls.l r0,r4                  ! Y * projection
    mov.w   r2,@r5                 ! screen_X = X_projected (high bits only)
    sts     mach,r0                ! high bits of Y projection
    rts
    mov.w   r0,@(0x2,r5)          ! screen_Y = Y_projected


! =============================================================================
! Pool Constants (0x060274EC - 0x06027550)
! =============================================================================
!
! Key literal values referenced by these functions:
!
! 0x060274EC:  0x002F2F20  — sin/cos lookup table base (ROM address)
! 0x060274F0:  0x002F0000  — atan lookup table base (ROM address)
! 0x060274F4:  0x00008000  — 0.5 in 16.16 OR 90 degrees in angle units
! 0x060274F8:  0x00010000  — 1.0 in 16.16 fixed-point
! 0x060274FC:  0x40003FFC  — atan lookup table limits
!
! Atan piecewise segment thresholds (at 0x06027516-0x06027528):
!   1000 (0x03E8), 500, 250, 150, 100, 70, 50, 40, 30, 16
!
! Atan piecewise slopes (at 0x06027528-0x0602754A):
!   0x00000AC0, 0x00001581, 0x000047AE, 0x0000B333,
!   0x00018000, 0x0002F333, 0x00053333, 0x0008B333,
!   0x0015B6DB
!
! VDP1 DMA registers:
!   0x25FE0000  DMA base address
!   0x25FE007C  DMA status register
!   0x0000272E  DMA busy mask


! =============================================================================
! FUN_060276CC — Spring/Damper Physics Interpolation
! =============================================================================
! Address: 0x060276CC
! Called from: rendering/physics pipeline
!
! This is a velocity integration function with damping (friction).
! It processes a variable-length structure with multiple modes.
!
! Coefficients:
!   r1 = 0xE666 = ~0.9 in 16.16 (friction/retention factor)
!   r2 = 0x1999 = ~0.1 in 16.16 (acceleration factor)
!   Note: 0xE666 + 0x1999 = 0xFFFF (~1.0), confirming this is
!   a weighted blend: new = 0.9 * current + 0.1 * target
!
! Data pointer: loaded from 0x06063F04 → r14
!
! Mode dispatch (from word at r5):
!   Mode 1: Standard integration with target comparison
!   Mode 2: Second axis integration
!   Mode 3: Third axis integration
!
! Per-axis computation (repeated pattern):
!   For each velocity component V and target T:
!     V_new = V * 0.9 + T * 0.1    (dmuls.l + xtrct for each)
!     position += V_new + 4         (constant bias + velocity)
!     if (position >= limit): exit
!
! The "+4" bias suggests this is a gravitational or wind constant.
! The 0.9/0.1 blend implements exponential smoothing (IIR filter).

FUN_060276CC:  ! spring_damper at 0x060276CC
    mov.l   r14,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    ! ... mode dispatch and integration loops ...
    ! Each mode handles a different axis configuration
    ! All use the same 0.9/0.1 weighted blend pattern


! =============================================================================
! Significance
! =============================================================================
!
! These functions are the computational bedrock of the entire game:
!
! 1. PHYSICS: fpmul, fpdiv, vec3_dot, vec3_normalize, atan2, isqrt
!    Every force calculation, every velocity update, every collision
!    normal computation flows through these functions.
!
! 2. RENDERING: sincos_pair, fpmul, viewport_project, dma_transfer
!    Every 3D transform, perspective projection, and VDP1 sprite
!    submission depends on these.
!
! 3. MEMORY: memcpy variants handle matrix copies, model data loading,
!    and state backup/restore for the undo system.
!
! 4. HARDWARE: hw_divide_protected is the ONLY safe way to divide
!    during gameplay (interrupts could corrupt the divider state).
!    The DMA transfer function is the primary path for pushing
!    sprite data to the VDP1.
!
! The xtrct instruction (SH-2 specific, not in SH-1) is the key to
! efficient 16.16 fixed-point arithmetic. Without it, every multiply
! would need a shift sequence. With it, the entire 3D pipeline runs
! at acceptable frame rates on 28.6 MHz hardware.
!
! Connection to math_transform.s:
!   The matrix stack functions in math_transform.s call fpmul (0x06027552)
!   and sincos_pair (0x06027358) extensively. The rotation matrices are
!   built from sin/cos values, and every matrix*vector operation is a
!   chain of fpmul calls (or inlined dmuls.l+xtrct sequences).
