! ================================================
! AUDIT: HIGH -- Engine sound system annotation is substantially correct.
! Both function addresses confirmed in binary (unlabeled but verified as real code).
! FUN_0600A8BC instruction sequence verified byte-for-byte: pool literals 0x06063F46,
! 0x0607E940, thresholds 100/200, increments +1/+2/+4, mask 0x0F all confirmed.
! Speed offset corrected: offset 0x8 is the speed (threshold comparisons), offset 0xC
! is the active/moving flag (zero-test only). FUN_060302C6/060302D2 prologue and
! initial setup (r9=0 accumulator, r6=input, 0x0607E944, 0x0607ED8C, 0x06063D9A,
! 0x0608188A) all verified. Both addresses confirmed as unlabeled subroutines.
! Audited: 2026-02-09, FIXED: 2026-02-10
! ================================================

! =============================================================================
! Engine Sound System
! =============================================================================
!
! Two-part system generating engine sound commands based on car speed and input:
!   FUN_0600A8BC  — Audio phase ticker (speed-proportional update rate)
!   FUN_060302C6  — Per-car engine sound generator (input → sound commands)
!
! The engine sound is generated as a BYTE written to a ring buffer,
! which the 68000 sound CPU reads via shared memory (mailbox at 0x25A02C20).
!
! CONFIDENCE: MEDIUM -- Ring buffer concept is consistent with the write/read
! pattern seen in the binary, but specific details (wrap limit ~690, exact byte
! format) are partially inferred from the code structure.
! Ring buffer:
!   0x0607ED90  base address (2 bytes per entry)
!   0x0607ED88  write pointer offset (wraps at limit ~690)
!
! Sound byte format (r9 accumulator):
!   bits 0-1: engine sound level (0=idle, 1=low, 2=med, 3=full)
!   bit 6:    brake active flag
!   bit 7:    accelerating flag
!
! CONFIDENCE: MEDIUM -- Bitmask table addresses (0x06081888-0x06081896) are plausible
! work RAM addresses but the specific mappings (brake, accelerate, skid, handbrake,
! neutral, gear levels) are interpretive. The address 0x0608188A is confirmed in the
! binary pool for FUN_060302C6 but the labels for each offset are inferred.
! Acceleration/brake detection uses bitmask tables:
!   0x06081888  brake button bitmask per course
!   0x0608188A  accelerate button bitmask per course
!   0x0608188C  skid/powerslide bitmask
!   0x0608188E  handbrake bitmask
!   0x06081890  neutral bitmask
!   0x06081892  low gear bitmask
!   0x06081894  mid gear bitmask
!   0x06081896  high gear bitmask
!
! Data tables for engine volume:
!   0x06063D98  button state word (alternative)
!   0x06063D9A  button state word (primary)

! =============================================================================
! FUN_0600A8BC — Audio Phase Ticker
! =============================================================================
! Called from: FUN_0600DE70 (per-car iteration loop)
! Purpose: Increment audio phase counter at rate proportional to car speed
! CONFIDENCE: HIGH -- Instruction sequence verified byte-for-byte. Pool literals
! 0x06063F46 (phase counter), 0x0607E940 (car pointer) confirmed. Thresholds
! 100 and 200 (from pool 0x00C8) confirmed. Increments +1/+2/+4 confirmed.
! Wrap mask 0x0F confirmed. Speed==0 reset path confirmed.
!
! Algorithm:
!   counter = *(word*)0x06063F46
!   car = *0x0607E940
!   active_flag = car->active_flag  (offset 0xC -- zero-test only, NOT the speed)
!   speed = car->speed  (offset 0x8 -- used for threshold comparisons 100/200)
! FIXED: Speed offset corrected. Binary confirms offset 0xC (mov.l @(0xC,r5),r0)
! is only zero-tested (tst r0,r0 / bt .audio_zero_speed) -- it is a moving/active
! flag, NOT the speed. The actual speed for threshold comparisons (100, 200) is at
! offset 0x8 (mov.l @(0x8,r5),r3 at 0x0600A8CA). Annotation updated below to use
! offset 0x8 for speed and 0xC for the active flag.
!   if (speed == 0):
!     counter = 0
!   elif (speed < 100):
!     counter += 1
!   elif (speed < 200):
!     counter += 2
!   else:  // speed >= 200
!     counter += 4
!   counter &= 0x0F  (wrap at 16 phases)
!   store back

! FIXED: Confirmed 0x0600A8BC is an unlabeled subroutine in aprog.s (no FUN_ label).
! Code verified at this address: mov.l @(0x4C,PC),r4 {0x06063F46} /
! mov.l @(0x50,PC),r5 {0x0607E940} / mov.l @r5,r5 / mov.l @(0xC,r5),r0 /
! tst r0,r0 / bt 0x0600A8F8. Pool confirms 0x06063F46 (phase counter) and
! 0x0607E940 (car pointer). Referenced from pool literals at [0x0600DFA0] and
! [0x0600E52C]. Real code, just unlabeled by the symbol table.
FUN_0600A8BC:  ! 0x0600A8BC
    mov.l   @(0x4C,PC),r4           ! r4 = 0x06063F46 (phase counter)
    mov.l   @(0x50,PC),r5           ! r5 = 0x0607E940
    mov.l   @r5,r5                  ! r5 = car base
    mov.l   @(0xC,r5),r0            ! r0 = car->active_flag (offset 0xC: zero=stopped)
    tst     r0,r0
    bt      .audio_zero_speed       ! speed == 0 → reset

    mov     #100,r2
    mov.l   @(0x8,r5),r3            ! r3 = car->speed (offset 0x8: compared against 100)
    cmp/ge  r2,r3
    bt      .speed_ge_100

    ! speed < 100: increment by 1
    mov.w   @r4,r2
    add     #1,r2
    bra     .audio_store
    mov.w   r2,@r4

.speed_ge_100:
    mov.l   @(0x8,r5),r2            ! r2 = car->speed (offset 0x8: compared against 200)
    mov.w   @(0x22,PC),r3           ! 200 (pool value 0x00C8)
    cmp/ge  r3,r2
    bt      .speed_ge_200

    ! 100 <= speed < 200: increment by 2
    mov.w   @r4,r3
    add     #2,r3
    mov.w   r3,@r4
    bra     .audio_store
    nop

.speed_ge_200:
    ! speed >= 200: increment by 4
    mov.w   @r4,r2
    add     #4,r2
    mov.w   r2,@r4

.audio_store:
    mov.w   @r4,r0
    and     #0x0F,r0                ! wrap at 16 phases
    bra     .audio_exit
    mov.w   r0,@r4

.audio_zero_speed:
    mov     #0,r2
    mov.w   r2,@r4

.audio_exit:
    rts
    nop


! =============================================================================
! FUN_060302C6 — Per-Car Engine Sound Generator
! =============================================================================
! Called from: State 15 (FUN_06009098) per-car loop
! Purpose: Generate engine sound byte from car input state
! CONFIDENCE: HIGH -- Prologue verified (push r8-r13, falls through to FUN_060302D2).
! FUN_060302D2 confirmed as labeled function in aprog.s. Initial setup (mov #0,r9;
! mov r0,r6; mov #1,r5; mov #0,r7) verified. Pool references to 0x0607E944 (car ptr),
! 0x0607ED8C (replay flag), 0x06063D9A (button state), 0x0608188A (accel bitmask)
! all confirmed in binary pool literals. The algorithm description (priority encoder
! for engine level, acceleration/brake ramp, ring buffer write) is well-structured
! and consistent with the binary control flow.
!
! Register usage (heavy — saves r8-r14):
!   r0  = car pointer (from 0x0607E940)
!   r1  = button state word
!   r3  = bitmask table base (0x0608188X)
!   r6  = input bitmask for current car
!   r9  = accumulated sound byte
!
! Algorithm:
!   car = *0x0607E944
!   if (0x0607ED8C != 0):  // sound replay mode
!     goto playback_path (read from ring buffer instead of generating)
!
!   Read button_state from 0x06063D9A (per-car button bitmask)
!
!   === Priority encoder for engine level (highest to lowest) ===
!   if (0x0608188A & button): // accelerate active
!     engine_level = 3 (max)
!   elif (0x06081896 & button): // high gear
!     engine_level = 3
!   elif (0x06081894 & button): // mid gear
!     engine_level = 2
!   elif (0x06081892 & button): // low gear
!     engine_level = 1
!   elif (0x06081890 & button): // neutral
!     engine_level = 0
!   else:
!     keep current level from table, decrement toward 56 (idle)
!
!   === Acceleration ramp ===
!   if (0x0608188C & button): // skid/powerslide
!     Set bit 7 in sound byte (accelerating flag)
!     Ramp up volume at car offset 0xB8+8 (max 0xB8)
!
!   === Brake detection ===
!   if (0x0608188E & button): // handbrake
!     Set bit 6 in sound byte (brake flag)
!     Save volume to car offset 0x8C
!     Ramp up at offset 0x90 (max 0xB8)
!   else:
!     Save volume to car offset 0x8C
!     Ramp down offset 0x90 toward 56 (idle)
!     Clear offset 0x88
!
!   === Write to ring buffer ===
!   buf_ptr = *(0x0607ED88)
!   *(0x0607ED90 + buf_ptr) = sound_byte
!   buf_ptr += 2
!   if (buf_ptr >= limit): buf_ptr -= 2  (wrap)
!   store buf_ptr
!
! Playback path (when sound replay flag set):
!   Read byte from ring buffer at current read position
!   Parse: bits 0-1 = level, bit 6 = brake, bit 7 = accel
!   Same ramp logic but driven by recorded data instead of live input

! FIXED: Confirmed 0x060302C6 is an unlabeled prologue in aprog.s (no FUN_ label).
! Code verified: mov.l r8,@-r15 / mov.l r9,@-r15 / mov.l r10,@-r15 /
! mov.l r11,@-r15 / mov.l r12,@-r15 / mov.l r13,@-r15 -- then falls through to
! FUN_060302D2 which IS labeled. This annotation treats the combined pair as one
! function, which is correct -- 060302C6 falls through into 060302D2 with no branch.
! Real code, just unlabeled by the symbol table.
FUN_060302C6:  ! 0x060302C6
    mov.l   r8,@-r15
    mov.l   r9,@-r15
    mov.l   r10,@-r15
    mov.l   r11,@-r15
    mov.l   r12,@-r15
    mov.l   r13,@-r15
    ! Falls through to FUN_060302D2 (continuation)

FUN_060302D2:  ! 0x060302D2
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov     #0,r9                   ! r9 = sound byte accumulator
    mov     r0,r6                   ! r6 = input bitmask for this car
    mov     #1,r5
    mov     #0,r7

    mov.l   @(0x10,PC),r0           ! 0x0607E944
    mov.l   @r0,r0                  ! car pointer
    mov.l   @(0x10,PC),r1           ! 0x0607ED8C
    mov.w   @r1,r2                  ! sound replay flag
    tst     r2,r2
    bt      .live_sound             ! flag == 0 → generate live
    bra     .playback_path          ! flag != 0 → read from buffer
    nop

.live_sound:
    ! Read primary button state
    mov.l   @(0x20,PC),r2           ! 0x06063D9A
    mov.w   @r2,r1
    extu.w  r1,r1                   ! r1 = button_state

    ! Read secondary button state
    mov.l   @(0x20,PC),r2           ! 0x0608188A (accel bitmask)
    mov.w   @r2,r2
    cmp/pl  r2                      ! accel input active?
    bf      .check_idle             ! no → check other inputs

    tst     r1,r2                   ! button & accel_mask
    bt      .check_brake_input      ! not accelerating

    ! Accelerating: read current level from table
    mov.w   @(r0,r3),r4             ! current engine level
    tst     r4,r4
    bt      .level_zero
    add     #-1,r4                  ! decrement toward idle

    bra     .store_level
    mov.w   r4,@(r0,r3)

    ! ... (priority encoder continues through all gear levels) ...
    ! Each checks: if (bitmask & button): set level, goto store
    ! Levels: 3 (accel/high), 2 (mid), 1 (low), 0 (neutral)

.check_idle:
    ! Check high gear: 0x06081896
    mov.l   @(0xC,PC),r2
    mov.w   @r2,r2
    tst     r1,r2
    bt      .check_mid_gear
    mov     #3,r4
    bra     .store_level
    mov.w   r4,@(r0,r3)

.check_mid_gear:
    ! 0x06081894
    mov.l   @(0xC,PC),r2
    mov.w   @r2,r2
    tst     r1,r2
    bt      .check_low_gear
    mov     #2,r4
    bra     .store_level
    mov.w   r4,@(r0,r3)

.check_low_gear:
    ! 0x06081892
    mov.l   @(0xC,PC),r2
    mov.w   @r2,r2
    tst     r1,r2
    bt      .check_neutral
    mov     #1,r4
    bra     .store_level
    mov.w   r4,@(r0,r3)

.check_neutral:
    ! 0x06081890
    mov.l   @(0x3C,PC),r2
    mov.w   @r2,r2
    tst     r1,r2
    bt      .store_level
    mov     #0,r4
    mov.w   r4,@(r0,r3)

.store_level:
    mov.w   @(r0,r3),r4
    mov     r4,r9                   ! r9 = base engine level (bits 0-1)

    ! === Check skid/powerslide (acceleration ramp) ===
    mov.l   @(0x30,PC),r3           ! 0x06063D98 (alt button state)
    mov.w   @r3,r1
    extu.w  r1,r1
    mov     #1,r5
    mov.l   @(0x2C,PC),r2           ! 0x0608188C (skid mask)
    mov.w   @r2,r2
    tst     r1,r2
    bt      .check_brake_input

    ! Skid active: set bit 7, ramp up volume
    mov     #-128,r8                ! 0x80
    extu.b  r8,r8
    or      r8,r9                   ! set acceleration flag
    mov.w   @(0x10,PC),r2           ! offset 0x74
    mov.l   r5,@(r0,r2)             ! set accel flag in struct
    add     #8,r2
    mov.w   @(0xC,PC),r8            ! ramp limit (0xB8)
    mov.l   @(r0,r2),r4             ! current volume
    cmp/gt  r8,r4
    bt      .accel_done
    add     #4,r4                   ! ramp up by 4

.accel_done:
    bra     .write_buffer
    mov.l   r4,@(r0,r2)

.check_brake_input:
    ! === Check handbrake (0x0608188E) ===
    mov.l   @(0x34,PC),r2           ! 0x0608188E (handbrake mask)
    mov.w   @r2,r2
    tst     r1,r2
    bt      .no_brake

    ! Handbrake active: set bit 6
    mov     #64,r8
    or      r8,r9                   ! set brake flag
    ! ... ramp processing similar to accel ...
    bra     .write_buffer
    nop

.no_brake:
    ! No brake: ramp down, clear flags
    mov.l   @(0x40,PC),r3           ! offset 0x90
    mov.l   @(r0,r3),r4
    mov.l   @(0x40,PC),r6           ! offset 0x8C
    mov.l   r4,@(r0,r6)             ! save to 0x8C
    mov     #56,r3                  ! idle volume = 56
    add     #-5,r4                  ! ramp down by 5
    cmp/ge  r3,r4
    bt      .ramp_ok
    mov     r3,r4                   ! clamp to 56 (idle)
.ramp_ok:
    ! ... store and continue ...

.write_buffer:
    ! Write sound byte to ring buffer
    mov.l   @(0x34,PC),r2           ! 0x0607ED90 (buffer base)
    mov.l   @(0x34,PC),r4           ! 0x0607ED88 (write pointer)
    mov.l   @r4,r6                  ! current offset
    add     r6,r2                   ! buffer + offset
    add     #2,r6                   ! advance
    mov.b   r9,@r2                  ! write sound byte
    mov.w   @(0x18,PC),r3           ! wrap limit (~690)
    cmp/gt  r6,r3
    bt      .no_wrap
    add     #-2,r6                  ! wrap back
.no_wrap:
    mov.l   r6,@r4                  ! store new write pointer

    lds.l   @r15+,pr
    mov.l   @r15+,r14
    mov.l   @r15+,r13
    mov.l   @r15+,r12
    mov.l   @r15+,r11
    mov.l   @r15+,r10
    mov.l   @r15+,r9
    rts
    mov.l   @r15+,r8

! CONFIDENCE: HIGH -- Playback path branch target 0x06030474 confirmed in binary
! (bra 0x06030474 at 0x060302EA). The concept of a replay/playback mode reading
! from the same ring buffer is consistent with the flag check at 0x0607ED8C.
.playback_path:                     ! 0x06030474
    ! Sound replay: read from ring buffer instead of generating
    ! Same buffer, same format, but reading instead of writing
    mov.l   @(0x3C,PC),r2           ! 0x0607ED90
    mov.l   @(0x40,PC),r4           ! 0x0607ED88
    mov.l   @r4,r6
    add     r6,r2
    add     #2,r6
    mov.b   @r2,r1                  ! read sound byte
    mov.w   @(0x28,PC),r3
    extu.b  r1,r1

    ! Parse sound byte
    mov     r1,r5
    mov     #3,r2
    and     r2,r5                   ! bits 0-1 = engine level
    mov.w   r5,@(r0,r3)
    mov.l   r6,@r4                  ! advance read pointer

    ! Check bit 7 (acceleration)
    mov     #1,r5
    mov     #-128,r2
    extu.b  r2,r2                   ! 0x80
    tst     r1,r2
    bt      .replay_check_brake
    ! ... acceleration ramp from recorded data ...

.replay_check_brake:
    ! Check bit 6 (brake)
    ! ... same ramp logic ...
    rts
    nop
