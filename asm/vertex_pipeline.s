! ================================================
! AUDIT: MEDIUM — FUN_0602ECCC (hardware division) verified DEFINITE.
!   FUN_0602EEB8 (orchestrator) confirmed with pool constants. FUN_0602FDA4
!   exists at address but is not a FUN_ label. Most sub-function descriptions
!   (collision response, lighting, fog, color blending) are reasonable inferences
!   from instruction patterns but specific roles (e.g. damage flash, boost glow)
!   are speculative. The overall pipeline structure is well-documented.
! Audited: 2026-02-09
! ================================================
! =============================================================================
! Per-Car Rendering State Pipeline
! =============================================================================
!
! Address range: 0x0602ECCC - 0x0602F7E2
!
! This file documents the per-car rendering pipeline that transforms
! 3D car state into renderable output. It is called from FUN_0602EEB8
! (the main rendering orchestrator) which dispatches to a chain of
! 10+ sub-functions per frame.
!
! The pipeline processes each car's state to produce:
!   - Coordinate clipping & bounds validation
!   - Perspective projection (3D → 2D screen)
!   - Collision damage effects
!   - Lighting/intensity selection
!   - Distance fog attenuation
!   - Material color blending
!   - Animation timer management
!
! Orchestrator call chain (FUN_0602EEB8):
!   FUN_0602FDA4 → register setup (prologue)
!   FUN_0602EFF0 → coordinate bounds clipping
!   FUN_0602F3EC → fixed-point MAC (damage core)
!   FUN_0602F7BC → animation timer decrements
!   FUN_0602F0E8 → perspective projection
!   FUN_0602F17C or FUN_0602F270 → collision response (conditional)
!   FUN_0602F474 → lighting intensity selection
!   FUN_0602F4B4 → distance fog calculation
!   FUN_0602F5B6 → color/material blending
!   FUN_0602EFCC → sin/cos for orientation
!   FUN_0602C690, FUN_0602C8E2, FUN_0602CA84 → VDP display list
!   FUN_0602D08A or FUN_0602D43C → final display submission
!   FUN_0602CDF6, FUN_0602D814, FUN_0602D8BC → cleanup


! =============================================================================
! FUN_0602ECCC — Protected Hardware Integer Divide
! =============================================================================
! Input:  r0 = divisor, r1 = dividend
! Output: r0 = quotient, r1 = quotient
!
! Wraps the SH-2 hardware divider (0xFFFFFF00) in a critical section.
! Disables ALL interrupts during division to prevent corruption if an
! ISR also uses the divider.
!
! The hardware divider is a single shared resource. Without protection,
! an interrupt during division would overwrite the in-progress state,
! producing incorrect results in both the interrupt AND the caller.
!
! Sequence:
!   stc.l sr,@-r15          ; save status register
!   ldc 0xF0,sr             ; disable interrupts (mask = 1111)
!   DVSR = r0               ; set divisor at 0xFFFFFF00
!   DVDNT = r1              ; set dividend at 0xFFFFFF04 (triggers 32/32 div)
!   r0 = @(0x14,div_base)   ; read quotient from 0xFFFFFF14
!   ldc.l @r15+,sr          ; restore interrupts

! CONFIDENCE: DEFINITE — Verified byte-for-byte. Hardware divider at 0xFFFFFF00.
!   Interrupt disable/restore sequence matches SH-2 manual exactly.
FUN_0602ECCC:  ! hw_divide_protected at 0x0602ECCC
    ! 16 instructions, LEAF function


! =============================================================================
! FUN_0602ECF2 — Physics Integration Dispatcher (Jump Table)
! =============================================================================
! Dispatches to physics sub-steps via jump table.
! Step counter at 0x0607EAE4, incremented each call.
! Jump table base at 0x0602ED0C (4-byte entries).
!
! Targets:
!   0x0602ED18 — primary physics step (car state init)
!   0x0602EE90 — secondary step
!   0x0602EE20 — conditional branch A
!   0x0602EE58 — conditional branch B
!
! The data at 0x0602EE20-0x0602EE8E is lookup table data, NOT code.
! It contains pre-computed rendering parameters indexed by the step counter.

! CONFIDENCE: MEDIUM — Not a FUN_ label. Jump table dispatch interpretation reasonable.
FUN_0602ECF2:  ! physics_dispatcher at 0x0602ECF2


! =============================================================================
! FUN_0602FDA4 — Pipeline Prologue (Register Save)
! =============================================================================
! Saves r8-r13 to stack (6 registers, 24 bytes).
! Pure prologue — no logic. Sets up register context for the
! entire pipeline sequence. The epilogue (pop r8-r13) is in
! FUN_0602EEB8 at 0x0602EFAA.

! CONFIDENCE: HIGH — Not a FUN_ label but confirmed at address 0x0602FDA4
!   (mov.l r8,@-r15). Called from FUN_0602EEB8 via pool constant at 0x0602EF00.
FUN_0602FDA4:  ! pipeline_prologue at 0x0602FDA4
    mov.l   r8,@-r15
    mov.l   r9,@-r15
    mov.l   r10,@-r15
    mov.l   r11,@-r15
    mov.l   r12,@-r15
    mov.l   r13,@-r15


! =============================================================================
! FUN_0602EFF0 — Coordinate Bounds Clipping & State Setup
! =============================================================================
! Tests vertex coordinates against multiple state flags.
! Implements conditional increment/decrement based on bounds tests.
! Sets direct state values (0, 1, 2, 3) for different coordinate states.
!
! Key data:
!   0x0607E944 — car pointer
!   0x0607ED8C — bounds table
!   0x06063D9A — state flags
!   0x0608188A — secondary flags
!
! This is the "gatekeeper" that validates vertex data before projection.
! Different state flags trigger different clipping paths.

! CONFIDENCE: HIGH — Label confirmed in binary. Called from FUN_0602EEB8.
!   Bounds clipping interpretation reasonable but field names are inferred.
FUN_0602EFF0:  ! bounds_clipping at 0x0602EFF0
    ! ~62 instructions
    ! Multiple conditional paths with state flags
    ! Decrements/increments counters based on flag tests
    ! Sets state to 0, 1, 2, or 3 depending on coordinate validity


! =============================================================================
! FUN_0602F0E8 — Perspective Projection (3D → 2D)
! =============================================================================
! Converts homogeneous 3D coordinates to 2D screen space.
! Heavily branched — handles multiple vertex attribute types.
! This is where the Z-divide happens for perspective correct rendering.

! CONFIDENCE: MEDIUM — Not a FUN_ label. Called from FUN_0602EEB8 via pool.
!   Perspective projection role inferred from the context of the pipeline.
FUN_0602F0E8:  ! perspective_project at 0x0602F0E8
    ! ~88 instructions


! =============================================================================
! FUN_0602F17C — Collision Response Path A (Primary)
! =============================================================================
! Applies collision damage effects to the primary car object.
!
! Algorithm:
!   value = car->offset_0xC
!   scaled = (value * 0x00480000) >> 16   (fixed-point scale)
!   clamped = clamp(scaled, 0, 344)
!   car->offset_0x8 = clamped
!   attenuation = clamped * 64            (shll8 + shlr2)
!   attenuation = clamp(attenuation, 0, 0x2AAA)  (multi-stage clamp)
!   car->property_A -= attenuation
!   if (car->property_B != 0):
!     car->property_C -= 0x2AAA
!
! Fixed-point constants:
!   0x00480000 — scale factor (~1/547)
!   0x00000158 — upper clamp (344)
!   0x00002AAA — mid clamp (1/3 in fixed-point)
!   0x00000AAA — lower clamp (1/10 in fixed-point)

! CONFIDENCE: MEDIUM — Not a FUN_ label. Collision response interpretation
!   is based on the fixed-point scale/clamp pattern with 0x00480000.
FUN_0602F17C:  ! collision_response_A at 0x0602F17C
    ! ~100 instructions with dmuls.l, clamping, and property modification


! =============================================================================
! FUN_0602F270 — Collision Response Path B (State-Driven)
! =============================================================================
! Alternative collision path with a state machine controlling animation.
!
! State machine:
!   positive state → decrement each frame
!   negative state → increment each frame
!   zero state → idle
!
! Two computation paths based on comparison of state values:
!   Path A (high value): Index into table at 0x060477BC, multiply, divide
!   Path B (low value):  Same computation with different parameters
!
! Both paths call FUN_0602755C (fixed-point normalize/divide).
! Stores result values: +5 or -5 depending on direction.
! Sets error flag 0xFF on out-of-bounds.
!
! This implements animated collision response — the state counter
! controls the animation phase while the computation varies the intensity.

! CONFIDENCE: MEDIUM — Not a FUN_ label. State machine interpretation
!   reasonable from increment/decrement pattern.
FUN_0602F270:  ! collision_response_B at 0x0602F270
    sts.l   pr,@-r15
    ! ~110 instructions with state machine + dual multiply paths


! =============================================================================
! FUN_0602F3EC — Fixed-Point MAC Core (Damage Modifier)
! =============================================================================
! The core damage calculation unit, shared between collision paths.
!
! Algorithm:
!   value = car->offset_0xC
!   scaled = (value * 0x00480000) >> 16
!   sign_extend(scaled)
!   clamped = clamp(scaled, 0, 344)     ; store to car->offset_0x8
!   attn = clamped * 64                 ; (shll8 + shlr2)
!   attn = multi_clamp(attn, 0, 0x2AAA, 0x0AAA)
!   car->propertyA -= attn
!   if (car->propertyB != 0):
!     car->propertyC -= 0x2AAA
!
! The 3-stage clamp ensures smooth falloff:
!   Stage 1: [0, 344] — raw damage range
!   Stage 2: [0, 0x2AAA] — 1/3 max attenuation
!   Stage 3: [0, 0x0AAA] — 1/10 max (fine detail)

! CONFIDENCE: MEDIUM — Not a FUN_ label. Confirmed at address (mov.l @(0xC,r0),r2).
!   dmuls.l with 0x00480000 and multi-stage clamp pattern verified.
FUN_0602F3EC:  ! damage_mac_core at 0x0602F3EC
    mov.l   @(0xC,r0),r2              ! load input value
    mov.l   @(PC),r3                   ! 0x00480000 (scale factor)
    dmuls.l r2,r3                      ! 64-bit multiply
    ! ... clamp chain and store ...
    rts


! =============================================================================
! FUN_0602F474 — Lighting Intensity Selection
! =============================================================================
! Selects from 4 different lighting intensities based on a countdown timer.
!
! State machine:
!   Timer >= 4: intensity index = 1 (brightest active)
!   Timer == 3: intensity index = 2
!   Timer == 2: intensity index = 3
!   Timer == 1: intensity index = 4 (dimmest)
!   Timer == 0: intensity index = 4 (off/default)
!
! Lighting lookup table at 0x060477D8 (4 entries, 4 bytes each).
! The timer decrements each frame, creating a fade-in/fade-out effect.
! Used for damage flash, boost glow, brake light intensity, etc.

! CONFIDENCE: SPECULATIVE — Not a FUN_ label. Lighting intensity role is
!   inferred from 4-way state machine and table lookup at 0x060477D8.
FUN_0602F474:  ! lighting_select at 0x0602F474
    mov     r14,r0                     ! base address
    mov     #0,r5                      ! counter = 0
    ! ... 4-way state machine ...
    ! ... table lookup at 0x060477D8[r5*4] ...
    rts


! =============================================================================
! FUN_0602F4B4 — Distance Fog / Attenuation
! =============================================================================
! Calculates visibility attenuation based on distance from camera.
!
! Algorithm:
!   table_ptr = *0x0607EAE0
!   if (*table_ptr == 0): skip    (fog disabled)
!   distance = car->distance_param
!   falloff = table[distance * 4]
!   intensity = |car->accumulated_value|
!   fog_factor = |falloff| * intensity
!   result = normalize(fog_factor)       (call FUN_0602755C)
!   car->fog_value = result
!
! The fog table at 0x0607EAE0 provides distance-dependent curves.
! The absolute value handling ensures correct behavior for both
! positive and negative coordinate spaces.

! CONFIDENCE: SPECULATIVE — Not a FUN_ label. Distance fog role inferred
!   from 0x0607EAE0 pointer dereference and absolute value computation.
FUN_0602F4B4:  ! distance_fog at 0x0602F4B4
    mov.l   @(PC),r1                   ! 0x0607EAE0 (fog table ptr)
    mov.l   @r1,r1                     ! dereference
    mov.l   @r1,r4                     ! load enable flag
    tst     r4,r4
    bt      .fog_skip                  ! disabled → skip
    ! ... distance lookup, abs multiply, normalize ...
.fog_skip:
    rts
    nop


! =============================================================================
! FUN_0602F5B6 — Material/Color Blending
! =============================================================================
! Blends multiple color components using fixed-point fractional weights.
!
! Blend weights (pool constants):
!   0x00016666 — 1/6 (~16.7%)
!   0x07800000 — 1/2 (50%)
!   0x0B400000 — 7/10 (70%)
!
! Note: 1/6 + 1/2 + 1/3 ≈ 1.0, suggesting RGB component mixing.
!
! Algorithm:
!   For each color channel:
!     component = input * weight
!     component >>= 16 (normalize)
!     component >>= 4  (additional reduction via 4x shlr2)
!     component = clamp(component, 0, 0x2134)
!   Lookup material property from table at 0x060477BC
!   Final = material * component (via dmuls.l)
!   Normalize and store
!
! The clamp to 0x2134 (8500 decimal) limits to ~16-bit color range.
! Material table at 0x060477BC provides per-material reflectance values.

! CONFIDENCE: SPECULATIVE — Not a FUN_ label. Color blending role inferred
!   from fractional weight constants (0x00016666, 0x07800000, 0x0B400000).
FUN_0602F5B6:  ! color_blend at 0x0602F5B6
    sts.l   pr,@-r15
    ! ~140 instructions with fractional blending
    ! Multiple dmuls.l operations with different weights
    ! 4x shlr2 chains for normalization (total >>8)
    ! 3-stage clamping like the damage core
    ! Material table lookup and final multiply


! =============================================================================
! FUN_0602F7BC — Animation Timer Decrements
! =============================================================================
! Decrements 3 independent per-car timers each frame.
! LEAF function — no subroutine calls.
!
! Timer A (16-bit word): animation frame counter
! Timer B (16-bit word): effect duration counter
! Timer C (32-bit long): extended timer (invincibility, cooldown)
!
! Each timer: if (timer > 0) timer--
! Zero-check prevents underflow.

! CONFIDENCE: HIGH — Not a FUN_ label but confirmed at address. Timer
!   decrement pattern (load, test zero, decrement, store) is unmistakable.
FUN_0602F7BC:  ! timer_tick at 0x0602F7BC
    mov.w   @(PC),r1                   ! offset for timer A
    mov.w   @(r0,r1),r2               ! load timer A
    tst     r2,r2                      ! zero?
    bt      .timer_b                   ! skip if zero
    add     #-1,r2                     ! decrement
    mov.w   r2,@(r0,r1)               ! store

.timer_b:
    mov.w   @(PC),r1                   ! offset for timer B
    mov.w   @(r0,r1),r2
    tst     r2,r2
    bt      .timer_c
    add     #-1,r2
    mov.w   r2,@(r0,r1)

.timer_c:
    mov.w   @(PC),r1                   ! offset for timer C
    mov.l   @(r0,r1),r2               ! 32-bit load
    tst     r2,r2
    bt      .timers_done
    add     #-1,r2
    mov.l   r2,@(r0,r1)               ! 32-bit store

.timers_done:
    rts
    nop


! =============================================================================
! FUN_0602EEB8 — Main Rendering Orchestrator
! =============================================================================
! Called from the per-car pipeline after physics. Dispatches to the full
! chain of rendering sub-functions documented above.
!
! Call sequence:
!   1. FUN_0602FDA4 — save registers
!   2. FUN_0602EFF0 — bounds clipping
!   3. Clear 0x0607EAC8
!   4. FUN_0602F3EC — damage MAC
!   5. FUN_0602F7BC — timer tick
!   6. FUN_0602F0E8 — perspective projection
!   7. FUN_0602F270 or FUN_0602F17C — collision response (conditional)
!   8. FUN_0602F474 — lighting selection
!   9. FUN_0602F4B4 — distance fog
!  10. FUN_0602F5B6 — color blending
!  11. FUN_0602EFCC — orientation sin/cos (uses FUN_06027358)
!  12. FUN_0602C690 — VDP display list setup
!  13. FUN_0602C8E2 — VDP command generation
!  14. FUN_0602CA84 — VDP secondary commands
!  15. FUN_0602D08A or FUN_0602D43C — display list submission (conditional)
!  16. FUN_0602CDF6 — display list finalization
!  17. FUN_0602D814 — render state cleanup
!  18. FUN_0602D8BC — final flags (mask with 0xFFFFFC3F)
!  19. Restore registers (pop r8-r14)
!
! The conditional branch at step 7 and step 15 depends on a word value
! at car offset 0x250 (checked with tst). If zero, takes path A (simpler).
! If non-zero, takes path B (state-driven with animation).

! CONFIDENCE: HIGH — Label confirmed. Prologue (push r14, sts.l pr)
!   matches. Pool constants for sub-functions verified: 0x0602FDA4 at 0x0602EF00,
!   0x0602EFF0 at 0x0602EF04, 0x0607EAC8 at 0x0602EF08, 0x0602F3EC at 0x0602EF0C,
!   0x0602F7BC at 0x0602EF10, 0x0602F0E8 at 0x0602EF14, 0x0602F17C at 0x0602EF64.
FUN_0602EEB8:  ! render_orchestrator at 0x0602EEB8
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    ! ... 19-step orchestration sequence ...
    ! ... ~200 bytes total ...
    lds.l   @r15+,pr
    ! ... pop r14-r8 ...
    rts


! =============================================================================
! Key Data Tables
! =============================================================================
!
! 0x060477BC — Material/reflectance lookup table
!   Indexed by clamped value, provides per-material light response
!   Used by both collision damage and color blending functions
!
! 0x060477D8 — Lighting intensity table
!   4 entries (16 bytes), indexed by countdown timer state
!   Provides lighting levels for damage flash / boost glow
!
! 0x0607EAE0 — Fog enable/table pointer
!   If *ptr == 0: fog disabled
!   Otherwise: points to distance attenuation curve table
!
! 0x0607EAE4 — Physics step counter (for dispatcher)
!
! 0x0607E944 — Current car pointer (global)


! =============================================================================
! Significance
! =============================================================================
!
! This pipeline is the VISUAL OUTPUT stage of the game engine. Every
! frame, for each car:
!   1. Physics determines position, velocity, collision state
!   2. THIS PIPELINE converts that state into rendering commands
!   3. The VDP1 executes those commands to produce the display
!
! AUDIT NOTE: FIXED: Added caveat that pipeline stage names (collision response, damage MAC, lighting, fog) are inferential. Fixed-point math patterns are verified but specific game mechanic assignments are speculative.
! The pipeline handles both the mathematical transforms (projection,
! fog, color) AND the visual effects (damage flash, boost glow,
! animation timers). It is the bridge between gameplay state and
! the player's visual experience.
!
! Connection to other subsystems:
!   - Reads from car struct populated by physics (player_physics.s)
!   - Reads collision state from car_collision.s / collision_response.s
!   - Calls math helpers (math_helpers.s) for fpmul, fpdiv
!   - Outputs to VDP1 via display list commands (scene_renderer.s)
!   - Timer decrements drive animation in subsystem_updates.s
