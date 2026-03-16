# Data Flow Chains — Stream to Ocean

Every value that contributes to the player car's world position and heading,
traced from its source (track data, controller, lookup table) through every
intermediate computation to the final output fields.

**Ocean** (final outputs consumed by rendering):
- car[+0x10] — World X position
- car[+0x14] — World Y position (always 0 on Three Seven)
- car[+0x18] — World Z position
- car[+0x20] — Heading angle (yaw)

**Format**: `source → [function] computation → destination`
Gaps marked with **[GAP]**. Pipeline call numbers in brackets.

---

## Chain 1: Throttle → Speed → Position X/Z

The main longitudinal force chain. Button press becomes forward motion.

```
=== SPRINGS (inputs) ===

C button (0x0200 in g_pad_state at sym_06063D98)
    ↓ [call 1] sym_0602FDA4/FUN_0602FDB0
    ↓   reads sym_06063D9A (button word)
    ↓   tests bit 0x0200 (mask at sym_0608188C)
    ↓   if C pressed: car[+0x74] += 10 (max 184)
    ↓   if C released: car[+0x74] decays toward 56
    ↓
car[+0x74] = throttle_force (range 56-184)

=== RIVER: throttle → force ===

car[+0x74]
    ↓ [call 6] sym_0602F0E8 (normal path: +0xB8==0 AND +0x1BC==0)
    ↓   car[+0x84] = car[+0x74]    (copy to "previous" slot)
    ↓
car[+0x84] = throttle_force_copy

car[+0x84]
    ↓ [call 15] FUN_0602CA84 reads +0x84 [GAP: exact usage within the
    ↓   440-instruction force accumulator not fully traced. Known: +0x84
    ↓   participates in the force formula alongside surface and geometry terms]
    ↓
    ↓   === TRIBUTARIES feeding into FUN_0602CA84 ===
    ↓
    ↓   car[+0x100] = sin(car[+0x24])     ← [call 12] sym_0602EFCC
    ↓   car[+0x104] = cos(car[+0x24])     ← [call 12] sym_0602EFCC
    ↓   car[+0x60]  = track angle X       ← [call 17] FUN_0602CDF6 via atan2
    ↓   car[+0x64]  = track angle Z       ← [call 17] FUN_0602CDF6 via atan2
    ↓   car[+0xEC]  = surface field 1     ← [call 11] FUN_0602F5B6 from track table
    ↓   car[+0xF0]  = surface field 2     ← [call 11] FUN_0602F5B6 from track table
    ↓   car[+0xF4]  = terrain lat. force  ← [call 11] FUN_0602F5B6 from track table
    ↓   car[+0x11C] = surface energy      ← [call 11] FUN_0602F5B6 from track table
    ↓   car[+0x140] = force magnitude X   ← [call 13] FUN_0602C690
    ↓   car[+0x144] = force magnitude Z   ← [call 13] FUN_0602C690
    ↓   car[+0x108] = force accum X       ← self-accumulated within FUN_0602CA84
    ↓   car[+0x10C] = force accum Z       ← self-accumulated within FUN_0602CA84
    ↓   car[+0x114] = resistance term     ← [call 9] sym_0602F474 lookup
    ↓   car[+0xD8]  = gear shift dir      ← [call 7a] sym_0602F17C
    ↓   car[+0x7C]  = gear state          ← (source unknown)
    ↓
    ↓   FORMULA (fully resolved from Ghidra + pool constants):
    ↓
    ↓   STEP 1 — Roll projection:
    ↓     a = -car[+0x100] × 0x3700000 >> 16    (sin(roll) × constant)
    ↓     b = -car[+0x100] × 0x2D00000 >> 16    (sin(roll) × constant)
    ↓     c = -car[+0x104] × car[+0x60] >> 16   (cos(roll) × track_angle_X)
    ↓     d = -car[+0x104] × car[+0x64] >> 16   (cos(roll) × track_angle_Z)
    ↓     if sign(c) == sign(a): a = -a
    ↓     force_X = a + c
    ↓     if sign(d) == sign(b): b = -b
    ↓     force_Z = b + d
    ↓     car[+0x148] = force_Z   (stored)
    ↓
    ↓   STEP 2 — Force magnitude X:
    ↓     diff = car[+0xEC] - car[+0x140]     (surface - force_mag threshold)
    ↓     mag = manhattan_approx(force_X, diff) (= max + min/4)
    ↓     if mag < car[+0x140]:
    ↓       car[+0x108] = 0x10000  (full force)
    ↓     else:
    ↓       car[+0x108] = FUN_0602755C(car[+0x140], mag)  (scaled)
    ↓
    ↓   STEP 3 — Force magnitude Z:
    ↓     combined = car[+0xF4] + car[+0x140] - car[+0x11C]
    ↓     mag_Z = manhattan_approx(force_Z, combined)
    ↓     if mag_Z < car[+0x144]:
    ↓       car[+0x10C] = 0x10000
    ↓     else:
    ↓       car[+0x10C] = FUN_0602755C(car[+0x144], mag_Z)
    ↓
    ↓   STEP 4 — Drift detection:
    ↓     if force_Z dominates AND car[+0x10C] ≤ 0xCCCC AND car[+0xD8] ≤ 0:
    ↓       call FUN_0602CCD0 → may set car[+0x152] = 0xA (drift timer)
    ↓
    ↓   STEP 5 — Drift reset (if car[+0x250] active):
    ↓     zero: car[+0x40], +0x58, +0x5C, +0x60, +0x64
    ↓     set: car[+0x110] = 0xFFFF0000
    ↓
    ↓   STEP 6 — Traction model (FUN_0602CCEC sub-call):
    ↓     [see Chain 5 for full traction computation]
    ↓
    ↓   STEP 7 — Final accel delta:
    ↓     gear = 0x140 (if car[+0x7C] is 4 or 5) else 0x100
    ↓     term_A = iVar5 × car[+0x108] >> 16
    ↓     term_B = car[+0x10C] × combined_force >> 16
    ↓     car[+0xFC] = gear × (term_A + term_B - car[+0x114]) >> 24
    ↓
    ↓   [iVar5 and combined_force are derived from step 1 intermediates]
    ↓
car[+0xFC] = accel_delta (CONFIRMED: +70/frame with C held)

=== RIVER: force → speed ===

car[+0xFC]
    ↓ [call 17] sym_0602D814
    ↓   car[+0x0C] = car[+0x0C] + car[+0xFC]
    ↓   if car[+0x0C] < 0: car[+0x0C] = 0, car[+0xFC] = 0
    ↓
car[+0x0C] = speed (CONFIRMED: HUD mph = value / 1467)

    ↓ also in sym_0602D814:
    ↓   gear_ratio = sym_060477BC[car[+0xDC]]
    ↓   raw = (car[+0x0C] × gear_ratio) >> 16
    ↓   scaled = (raw × 0x0221AC91) >> 16
    ↓   car[+0xE0] = clamp(scaled >> 16, 0, 8500)
    ↓   car[+0xE8] = max(0, scaled - clamped)
    ↓
car[+0xE0] = gear_scaled_speed (feeds back into traction, see Chain 5)

=== RIVER: speed → position ===

car[+0x0C] (speed, scalar)
    ↓ [call 18] sym_0602D8BC
    ↓
    ↓   SAVE: car[+0x38] = car[+0x10]   (pre-update X)
    ↓   SAVE: car[+0x3C] = car[+0x18]   (pre-update Z)
    ↓
    ↓   FIRST: car[+0x20] = car[+0x30]   (copy converged heading)
    ↓   car[+0x08] = car[+0x0C]          (copy speed → speed index field)
    ↓
    ↓   if car[+0x250] == 0 (normal path):
    ↓     slip = car[+0x28]               (**SLIP ANGLE, not heading**)
    ↓     cos_s = FUN_06027344(-slip)     (cos of negated slip)
    ↓     sin_s = FUN_06027348(-slip)     (sin of negated slip)
    ↓     velocity_x = (speed_factor × sin_s) >> 16    [16.16 fixed-point]
    ↓     velocity_z = (speed × cos_s) >> 16
    ↓     NOTE: car moves in SLIP direction, not heading direction.
    ↓     The slip angle = direction of travel. Heading = where nose points.
    ↓
    ↓   if car[+0x250] != 0 (drift path, counter 1-10):
    ↓     drift_scale = sym_0602E8B8[car[+0x250]]
    ↓       counter 7: 0.9, counter 8: 0.8, counter 9: 0.7, else: 1.0
    ↓     velocity_x = (drift_scale × speed × sin_h) >> 16
    ↓     velocity_z = (drift_scale × speed × cos_h) >> 16
    ↓
    ↓   car[+0x18C] = velocity_x
    ↓   car[+0x190] = velocity_z
    ↓   car[+0x10] = car[+0x10] + velocity_x
    ↓   car[+0x18] = car[+0x18] + velocity_z
    ↓
car[+0x10] = WORLD X POSITION (ocean)
car[+0x18] = WORLD Z POSITION (ocean)

    ↓ VERIFIED: car[+0x18C] = car[+0x10] - car[+0x38]  (300/300 frames match)
    ↓ VERIFIED: car[+0x190] = car[+0x18] - car[+0x3C]  (300/300 frames match)
```

---

## Chain 2: Steering → Heading

D-pad input becomes heading angle change.

```
=== SPRINGS ===

LEFT button (0x4000 in g_pad_state)
RIGHT button (0x8000 in g_pad_state)
    ↓ [call 1] sym_0602FDA4 → sub-call FUN_0603006A
    ↓   LEFT: car[+0xAC] = negative value (e.g., -16 first frame)
    ↓   RIGHT: car[+0xAC] = positive value (presumed)
    ↓
car[+0xAC] = raw_steering_value

=== RIVER: raw steering → rotation state ===

car[+0xAC]
    ↓ [call 2] FUN_0602EFF0
    ↓   processed = abs(car[+0xAC])
    ↓   processed -= 5                (deadzone: values ±5 produce 0)
    ↓   processed = min(processed, 80) (clamp to max 80)
    ↓   processed = restore_sign(processed)
    ↓   processed *= 255              (scale: max output = 80 × 255 = 20400)
    ↓
    ↓   FUN_0602ECCC(processed, 150)  → rotation_1
    ↓   car[+0xB4] = car[+0xB0]      (save previous)
    ↓   car[+0xB0] = rotation_1
    ↓
    ↓   FUN_0602ECCC(?, ?)            → car[+0x78]
    ↓   FUN_0602ECCC(?, ?)            → car[+0x94]
    ↓
car[+0xB0] = steering_rotation
car[+0x78] = rotation_state_2
car[+0x94] = rotation_state_3

=== RIVER: rotation state → smoothed rotation ===

car[+0xB0]
    ↓ [call 6] sym_0602F0E8 (normal path)
    ↓   car[+0xD0] = (car[+0xB0] << 8 + car[+0xD0]) >> 1
    ↓   (exponential moving average, blends new rotation with history)
    ↓
    ↓   car[+0x84] = car[+0x94]    (state transfer)
    ↓   car[+0x68] = car[+0x78]    (state transfer)
    ↓
car[+0xD0] = smoothed_rotation

=== RIVER: smoothed rotation → heading correction ===

car[+0xD0]
    ↓ [call 16a] FUN_0602D43C
    ↓   GATE: speed_index > 240 AND angular_velocity != 0 AND force ≤ 0x6800
    ↓   [GAP: if gate closed, heading correction skipped — but heading
    ↓    still changes via other path. The exact alternative mechanism
    ↓    that changes heading at low speeds is not fully traced]
    ↓
    ↓   if gate open:
    ↓     heading_intensity = clamp(abs(car[+0x154]) - 760, 4, 10)
    ↓     car[+0x168] = heading_intensity
    ↓     → 3× atan2 calls (FUN_06027344)
    ↓     → 3× rotation calls (FUN_0602ECCC)
    ↓     → modifies car[+0x58], car[+0x5C], car[+0x178]
    ↓
car[+0x58] = updated_steering
car[+0x5C] = updated_steering_accumulator

=== RIVER: heading computation → final heading ===

car[+0x58], car[+0x5C], car[+0x40]
    ↓ [call 17] FUN_0602CDF6
    ↓   reads car[+0x30] (heading copy, = car[+0x20])
    ↓   reads car[+0x25C] (computed angle)
    ↓   delta = car[+0x30] - car[+0x25C]
    ↓   if |delta| > 0x0444 (~6°): increment car[+0x258] (divergence counter)
    ↓   correction = clamp(delta, ±60 per frame)
    ↓   car[+0x30] += correction
    ↓
    ↓   also computes:
    ↓   car[+0x60] = atan2(track_angle_x)    (track angle)
    ↓   car[+0x64] = atan2(track_angle_z)    (track angle)
    ↓
car[+0x30] = heading (converged toward target, clamped ±60/frame)

    ↓ [call 18] sym_0602D8BC (Ghidra-verified):
    ↓   FIRST: car[+0x20] = car[+0x30]  (copy converged heading)
    ↓   velocity direction = sin/cos(-car[+0x28])  (SLIP ANGLE, not heading)
    ↓   Car moves in slip direction. Heading is where the nose points.
    ↓
car[+0x20] = HEADING ANGLE (ocean) — set from car[+0x30]
    ↓ NOTE: car[+0x30] is written by FUN_0602CDF6 (call 17) BEFORE
    ↓ sym_0602D8BC (call 18) copies it to +0x20. So the chain is:
    ↓ call 17 writes +0x30 → call 18 copies +0x30→+0x20 and uses -0x28 for direction
```

---

## Chain 3: Brake → Deceleration

```
=== SPRING ===

B button (0x0100 in g_pad_state)
    ↓ [call 1] sym_0602FDA4
    ↓   if B pressed: car[+0x88] = 1, car[+0x90] += 40 (max 184+)
    ↓   if B released: car[+0x90] = car[+0x90] - car[+0x90]/2 (floor 56)
    ↓
car[+0x90] = brake_force (range 56-184+)
    ↓ copies to car[+0x8C] each frame

=== RIVER ===

car[+0x90]
    ↓ [GAP: exact path from brake force to negative accel_delta
    ↓  is not fully traced. Known: during braking, car[+0xFC] goes
    ↓  negative (peaks at -303 at frame 20 from 27 mph). The brake
    ↓  force must feed into FUN_0602CA84 similarly to throttle, but
    ↓  producing negative force. The mechanism is likely:
    ↓  car[+0x90] → copied to car[+0x8C] → read by force accumulator
    ↓  as a drag/deceleration term]
    ↓
car[+0xFC] = negative accel_delta (decelerating)
    ↓ → same chain as Chain 1 (speed → position)
```

---

## Chain 4: Surface/Track Data → Physics Properties

Track geometry from disc-loaded tables enters the physics pipeline.

```
=== SPRING (disc-loaded, in memory at race start) ===

Surface table at sym_0607EB88 (= 0x060C6000)
    784 entries × 16 bytes each
    Per entry: [X_world, Z_world, lateral_direction, curvature_constant]
    Edge-pair zigzag: alternating left/right track boundary points

Segment table at sym_0607EB84 (= 0x060D5840)
    147 entries × 4 bytes each
    Incrementing distance milestones (0x8000 → 0x1E8000)

=== RIVER: track tables → car struct fields ===

Surface table
    ↓ FUN_0600CA96 (shared code, NOT in player pipeline)
    ↓   index = car[+0x1FC] (surface type: 0x300/400/500/600)
    ↓   adjusts car[+0x1FC] by ±4/frame
    ↓   interpolates between adjacent table entries
    ↓   writes to surface buffer at sym_06078680
    ↓
surface buffer (sym_06078680)
    ↓ [call 11] FUN_0602F5B6 / FUN_0602F5EE
    ↓   reads surface buffer
    ↓   writes:
    ↓     car[+0xEC]  = surface property 1 (zero on flat, spikes on slopes)
    ↓     car[+0xF0]  = surface property 2 (paired with +0xEC)
    ↓     car[+0xF4]  = terrain lateral force (oscillates on grass)
    ↓     car[+0x11C] = surface energy (large values, increases with speed)
    ↓
    ↓   → these 4 fields feed DIRECTLY into FUN_0602CA84 (Chain 1)
    ↓     for surface modulation of the force computation

Segment table
    ↓ FUN_0600CD40 (shared code, reads car[+0x10] for position)
    ↓   car[+0x1E4] = segment index (increments as car crosses boundaries)
    ↓   car[+0x184] = segment properties (60 unique values)
    ↓   car[+0x1EC] = track progress
    ↓   car[+0x1F0] = track progress B
    ↓
    ↓   → segment index feeds sym_0602F17C (gear state machine, Chain 5)
    ↓   → THIS IS THE ONLY PHYSICS CODE THAT READS car[+0x10] (position)
    ↓     Position is write-only for the player pipeline; only the shared
    ↓     track segment system reads it back.
```

---

## Chain 5: Traction Feedback Loop

Speed feeds back into available force via the traction model.

```
=== LOOP (frame N → frame N+1) ===

car[+0xE0] (gear_scaled_speed, from sym_0602D814 in Chain 1)
    ↓ [within call 15] FUN_0602CCEC (called by BSR from FUN_0602CA84)
    ↓   GATE: car[+0x08] (speed_index) must be > 0
    ↓   force_deficit = 0x2134 - car[+0xE0]
    ↓   [this represents AVAILABLE TRACTION: as speed rises, less grip remains]
    ↓
    ↓   car[+0x110] = f(force_deficit, car[+0x11C], car[+0x10C], car[+0x144])
    ↓   car[+0x110] -= 1474/frame (linear traction recovery decay)
    ↓   car[+0x264] = computed via FUN_0602755C (clamp)
    ↓   car[+0xC0] = final traction output
    ↓   car[+0x10C] = updated force accumulator Z
    ↓
car[+0x110] = traction_term
    ↓ → feeds back into FUN_0602CA84 force formula (Chain 1)
    ↓   as part of the accel_delta computation

EFFECT (NOP-confirmed):
  Without FUN_0602CCEC: no tire spin, no grass traction loss,
  speed exceeds normal gear limits. This IS the traction model.

=== GEAR RATIO SELECTION ===

car[+0xE0] (gear_scaled_speed)
    ↓ [call 7a] sym_0602F17C (called 2× per frame)
    ↓   if car[+0xE0] > sym_060477AC[car[+0xDC]]: UPSHIFT
    ↓     car[+0xDC] += 1, car[+0xD8] = +5
    ↓   if car[+0xE0] < sym_0604779C[car[+0xDC]]: DOWNSHIFT
    ↓     car[+0xDC] -= 1, car[+0xD8] = -5
    ↓
car[+0xDC] = gear_section_index (selects gear ratio)
    ↓ → sym_0602D814 reads sym_060477BC[car[+0xDC]] as gear_ratio
    ↓   (closes the loop back to Chain 1)

GEAR RATIO TABLE (sym_060477BC):
  index 0: 603990 (gear 1 — high ratio, high accel, low top speed)
  index 1: 369187 (gear 2)
  index 2: 255607 (gear 3)
  index 3: 201259 (gear 4 — low ratio, low accel, high top speed)

THRESHOLD TABLES:
  Upshift (sym_060477AC):   [7400, 7400, 7400, 50000]
  Downshift (sym_0604779C): [-5000, 3092, 3970, 5000]
  Hysteresis gap: ~4300 units prevents oscillation at boundary
```

---

## Chain 6: Gear Selection (Manual)

```
=== SPRING ===

UP button (0x2000): car[+0xDE] += 1 (max 3)
DOWN button (0x1000): car[+0xDE] -= 1 (min 0)
    ↓ [call 1] sym_0602FDA4
    ↓
car[+0xDE] = manual_gear_position (0-3)

    ↓ [NARROWED: FUN_06008318 (gear shift handler) manages UP/DOWN with a
    ↓  32-frame timer at +0xB8 and a steering kick from table at 0x060453CC.
    ↓  In manual mode, the handler likely writes +0xDC directly during the
    ↓  shift event. Explorer: watchpoint on +0xDC during manual UP press
    ↓  to confirm the writer PC and verify +0xDE→+0xDC relationship.]
```

---

## Chain 7: Drag Accumulators

Speed-dependent aerodynamic drag, computed every frame.

```
car[+0x0C] (speed)
    ↓ [call 4] sym_0602F3EC
    ↓   speed_index = clamp((car[+0x0C] × 0x00480000) >> 32, 0, 344)
    ↓   car[+0x08] = speed_index
    ↓
    ↓   drag_amount = clamp(speed_index × 64, 0, 10922)  [0x2AAA]
    ↓   car[+0x48] -= drag_amount
    ↓
    ↓   if car[+0xC0] != 0:
    ↓     car[+0x50] -= alternate_constant (from pool)
    ↓   else:
    ↓     car[+0x50] -= drag_amount
    ↓
car[+0x48] = drag_accumulator (monotonic decrease with speed)
car[+0x50] = drag_accumulator_b (diverges from +0x48 when +0xC0 active)

    ↓ DOWNSTREAM: +0x48/+0x50 are NOT read by the player force accumulator
    ↓ (no pool constant 0x0048 or 0x0050 in FUN_0602CA84). They feed into
    ↓ the SHARED track/segment system (FUN_0600CA96, FUN_0600C928) which
    ↓ computes surface properties that the player pipeline reads indirectly
    ↓ through +0xEC/+0xF0/+0xF4/+0x11C (surface fields from call 11).
    ↓ The drag effect on acceleration is INDIRECT: accumulated drag →
    ↓ shared surface system → surface energy → force formula.
    ↓ [CLOSED — drag accumulators affect force through surface system, not directly]
```

---

## Summary: Complete Data Flow Map

```
                    SPRINGS
                    ═══════
    C button ──→ +0x74 (throttle)
    B button ──→ +0x90 (brake)
    LEFT/RIGHT → +0xAC (steering)
    UP/DOWN ───→ +0xDE (gear)
    Track table → +0xEC/F0/F4/11C (surface)
    Track table → +0x1E4 (segment)

                    RIVERS
                    ══════
    +0x74 → [call 6 copy] → +0x84 ─────────────────────────┐
    +0x90 → [copy] → +0x8C ────────────────────────────────┐│
    +0xAC → [call 2 deadzone/atan2] → +0xB0 ──────────┐   ││
    +0xB0 → [call 6 EMA] → +0xD0 ─────────────┐       │   ││
    +0xD0 → [call 16a heading correction] ─────┤       │   ││
    +0xEC/F0/F4/11C → [call 11 surface] ───────┤       │   ││
    +0x140/+0x144 → [call 13 force mag] ───────┤       │   ││
    +0x100/+0x104 → [call 12 sin/cos roll] ────┤       │   ││
                                               ↓       ↓   ↓↓
                                    ┌──────────────────────────┐
                                    │   FUN_0602CA84 (call 15) │
                                    │   FORCE ACCUMULATOR      │
                                    │                          │
                                    │  +0x108/+0x10C (self)    │
                                    │  +0x110 (traction loop)  │
                                    │  gear_constant (from +0x7C)
                                    └──────────┬───────────────┘
                                               ↓
                                    car[+0xFC] = accel_delta
                                               ↓
                                    ┌──────────────────────────┐
                                    │  sym_0602D814 (call 17)  │
                                    │  SPEED WRITER            │
                                    │  +0x0C += +0xFC          │
                                    │  +0xE0 = gear_scaled     │
                                    └──────────┬───────────────┘
                                               ↓
                                    car[+0x0C] = speed
                                               ↓
                              ┌────────────────┴────────────────┐
                              ↓                                 ↓
                    ┌─────────────────┐              ┌──────────────────┐
                    │ sym_0602D8BC    │              │ FUN_0602CCEC     │
                    │ POSITION WRITER │              │ TRACTION MODEL   │
                    │ (call 18)       │              │ (within call 15) │
                    │                 │              │ +0xE0 → +0x110   │
                    │ vel_x = speed   │              │ → feeds back to  │
                    │   × sin(heading)│              │   +0xFC next     │
                    │ vel_z = speed   │              │   frame          │
                    │   × cos(heading)│              └──────────────────┘
                    │ +0x10 += vel_x  │
                    │ +0x18 += vel_z  │
                    └────────┬────────┘
                             ↓
                    ═════════════════
                         OCEAN
                    ═════════════════
                    car[+0x10] = X position
                    car[+0x18] = Z position
                    car[+0x20] = heading
                    car[+0x14] = Y position (flat, always 0)
```

---

## Gaps Status

| Gap | Status | Resolution |
|-----|--------|------------|
| Force formula internals | **CLOSED** | 7-step formula with all 28 pool constants resolved. Ghidra-verified. |
| Heading source for position writer | **CLOSED** | Uses -car[+0x28] (slip angle). Copies +0x30→+0x20. Ghidra-verified. |
| Drag → force feedback | **CLOSED** | Drag accumulators feed the shared surface system, not the player force accumulator directly. Indirect path: +0x48/+0x50 → shared track system → +0xEC/+0xF0/+0xF4/+0x11C → force formula. |
| Heading computation details | **CLOSED** | Full offset chain: +0xAC → +0xB0/+0x78/+0x94 → EMA→+0xD0 → +0x58/+0x5C → +0x30 += correction → +0x30→+0x20. Direction via -sin(+0x28). |
| Brake → negative force | **NARROWED** | B→+0x90. Force formula subtracts +0x114 (resistance). +0x114 comes from animation lookup table (sym_060477D8). During braking, +0x114 increases → negative accel_delta. **Explorer needed**: which upstream call reads +0x90 and triggers the +0x114 state change? Breakpoint in FUN_0602CA84 during B-held. |
| Manual gear → +0xDC | **NARROWED** | FUN_06008318 handles UP/DOWN with 32-frame timer. Likely writes +0xDC directly. **Explorer needed**: watchpoint on +0xDC during manual UP press to confirm. |
