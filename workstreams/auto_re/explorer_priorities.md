# Explorer Priorities — Updated 2026-03-15

Phase 1 targets. Focus on the player physics pipeline — the code we're transplanting.

## High Priority (fills struct map gaps)

### 1. Player physics call tree — full observation of FUN_0602EEB8

- **Why**: The player pipeline is the #1 unmapped area. Static analysis (Ghidra +
  ASM) suggests FUN_0602EEB8 is the player physics dispatcher, calling ~15
  sub-functions via `jsr @r13`. But the call ORDER, execution frequency, and
  field writes are all unconfirmed. The AI pipeline (FUN_0600e71a) has a call
  tree from Ghidra — the player pipeline has none from the emulator.
- **What to do**: Load `usa_tt_straight.mc0`, scenario `straight_throttle`
  (hold C, 300 frames). Use call_trace on FUN_0602EEB8 to capture the full
  call tree for player car 0 during straight-line throttle. Record which
  sub-functions are called, in what order, and how many times per frame.
  Then repeat with LEFT held to see steering-specific branches.
- **What this unblocks**: Maps the entire player physics pipeline. Every
  subsequent priority depends on knowing which functions are called and in
  what order. This is the single most valuable observation.

### 2. Position fields — per-frame sample of +0x10, +0x14, +0x18, +0x1C

- **Why**: Offset +0x10 has 455 unique values across 475 writes (comprehensive
  map). Written by FUN_0602D8CA (PC 0x0602D902). Also written during collision
  by FUN_0602D9BC and FUN_06030E88. +0x18 has the same pattern. Initial dump
  shows large signed values (0xFFDCEBC7, 0xFF7AA916) — consistent with 32-bit
  fixed-point world coordinates. These are almost certainly X and Z position.
  +0x14 and +0x1C are written by FUN_060060B2 and FUN_06006188 respectively,
  with fewer unique values (106, 54) — likely Y components or derivatives.
  15 functions READ +0x10, 14 READ +0x18 — these are the most-consumed fields
  in the entire struct after +0x20.
- **What to do**: Load `usa_tt_straight.mc0`, scenario `straight_throttle`
  (hold C, 300 frames). Sample car[0] offsets +0x10, +0x14, +0x18, +0x1C
  every frame. Then repeat with `right_wall_strike` scenario (C + RIGHT,
  662 frames) to see position change during turning and collision.
  Plot the values — if they're X/Z coordinates, they should show a smooth
  trajectory that matches the track layout.
- **What this unblocks**: Position is the output of the velocity integration.
  Confirming +0x10 and +0x18 as position completes the speed→position chain:
  +0xFC (accel delta) → +0x0C (speed) → +0x10/+0x18 (position).

### 3. Heading angle field — per-frame sample of +0x20, +0x28, +0x30

- **Why**: Offset +0x20 is written by FUN_0602D8CA (PC 0x0602D8CE) with 361
  unique values across 475 writes. It's READ by 8 consumer functions — the 3rd
  most-read numeric offset. Static analysis of the AI pipeline says FUN_0600c7d4
  saves heading as car[+0x1B0] = car[+0x20], and FUN_0600c8cc adjusts car[+0x28]
  (slip angle) toward a track-derived target angle. In the rendering consumers
  (FUN_0600B6A0, FUN_0600B914), +0x20 is read alongside +0x10, +0x18, +0x1C,
  +0x24 — exactly the fields you'd need for 3D object placement (pos + orientation).
  +0x28 has 390 unique values and 14 total consumer references — likely slip angle.
  +0x30 is written by both FUN_0602CE4E (493 writes) and FUN_0602D086 (211 writes)
  — dual writers suggest it has two update paths (normal + collision).
- **What to do**: Load `usa_tt_straight.mc0`. Sample +0x20, +0x28, +0x30 during:
  (a) straight_throttle (300 frames) — heading should be constant on a straight,
  (b) LEFT held (300 frames) — heading should change monotonically during turn.
  If +0x20 is heading, it should be nearly constant during straight and sweep
  during steering. If +0x28 is slip angle, it should be near zero on straight
  and diverge from +0x20 during hard turns.
- **What this unblocks**: Heading completes the core kinematic state vector
  (position + heading + speed). With heading confirmed, we can map the full
  steering pipeline: controller input → heading delta → heading → velocity direction.

### 4. Velocity fields — per-frame sample of +0x38, +0x3C, +0x18C, +0x190

- **Why**: +0x38 and +0x3C are written by FUN_0602D8CA (same function as position),
  with the same write counts (475) and similar unique value counts (455, 372).
  Initial dump shows 0xFFD97340 and 0xFF7CA977 — large signed values like position
  but different from +0x10/+0x18. Static hypothesis from FUN_0600c7d4: "Saves
  velocity: car[+0x38] = car[+0x10], car[+0x3C] = car[+0x18]" — but this is
  Ghidra-only, for the AI path. If true in the player path, +0x38/+0x3C are
  previous-frame position (used for velocity computation). +0x18C and +0x190
  are also written by FUN_0602D8CA with different PCs (0x0602D8FE, 0x0602D90E)
  and different value ranges — possibly velocity components.
- **What to do**: Load `usa_tt_straight.mc0`, scenario `straight_throttle`.
  Sample +0x38, +0x3C, +0x18C, +0x190 alongside +0x10, +0x18 (position).
  Compare: if +0x38 = prev_position_x, then `+0x38[frame N] == +0x10[frame N-1]`.
  If +0x18C/+0x190 are velocity, they should be the frame-to-frame delta of position.
- **What this unblocks**: Identifies the velocity representation. Critical for
  understanding how speed (+0x0C, scalar) relates to directional movement.

## Medium Priority (deepens existing knowledge)

### 5. Throttle-to-speed pipeline — trace the gap

- **Why**: Static analysis mapped the speed pipeline end-to-end EXCEPT the
  link between C button (g_pad_state) and car[+0x100]. The pipeline is:
  `C button → [GAP] → car[+0x100] → FUN_0602EF4C → car[+0xFC] → sym_0602D814 → car[+0x0C]`.
  car[+0x100] is written by FUN_0602735C (near sin/cos functions, 72 unique
  values). The function that reads g_pad_state and eventually produces
  car[+0x100] is the missing link. FUN_0602EF4C writes +0xFC (accel delta, confirmed) but ALSO writes
  +0x00 (493 writes, value 0x800000) and +0x5C (493 writes, 301 unique values).
  +0x00 looks like a status/flags word (only 6 unique values total: 0x0, 0x80,
  0x100, 0x800000, 0x800080, 0x800100). +0x5C has high cardinality — maybe
  a computed derivative. Understanding what FUN_0602EF4C reads to compute
  +0xFC would reveal the throttle→accel pipeline.
- **What to do**: Load `usa_tt_straight.mc0`. Set breakpoint at FUN_0602EF4C
  entry (use map file for free-build address). Record r0-r7, r14 (car pointer)
  at entry and exit for 10 frames with C held, then 10 frames idle. Focus on
  which registers change between throttle vs idle — those carry the input signal.
- **What this unblocks**: Reveals how controller input (C button) becomes the
  +70/update accel delta shift. Maps the input→force stage of the pipeline.

### 6. Surface/terrain fields — per-frame sample of +0xEC, +0xF0, +0xF4, +0xF8

- **Why**: Written by FUN_0602F5EE. +0xEC and +0xF0 have only 5 unique values
  each, all large (0x1F197C0, 0x7C680C0, 0xB400000) — these look like quantized
  constants, possibly surface normal vectors or terrain type codes. +0xF4 has
  54 unique values (smaller range: 0x13880-0x91340). +0xF8 has 259 unique values
  starting from 0x80000 — possibly surface friction coefficient.
  FUN_0600CA96 (friction/drag in AI pipeline) reads from a surface table at
  sym_0607EB88 — these fields may be the player-path equivalent.
- **What to do**: Load `usa_tt_offtrack_stop.mc0`, scenario `offtrack_throttle`
  (hold C, 566 frames). Sample +0xEC, +0xF0, +0xF4, +0xF8 every frame.
  The car crosses from road to grass at frame ~109. If these are surface
  properties, they should change sharply at the road/grass boundary.
- **What this unblocks**: Maps the surface response pipeline. Essential for
  understanding traction loss (grass causes speed cap at 51 mph gear 1).

### 7. Frame-level execution order — call trace of FUN_0600c010

- **Why**: FUN_0600c010 is the per-frame racing orchestrator (from call tree).
  It calls FUN_0600b6a0 (car update loop), FUN_0600d336, and others. But we
  don't know where the player physics dispatcher (FUN_0602EEB8) is called from,
  or whether it runs before or after the AI car loop. Understanding frame-level
  execution order is critical for the transplant — we need to know the update
  sequence.
- **What to do**: Load `usa_tt_straight.mc0`. Use call_trace on FUN_0600c010
  for exactly 1 frame. Record the top-level call sequence. Identify where
  in the frame FUN_0602EEB8 (or its caller) appears relative to FUN_0600e0c0
  (AI loop) and FUN_0600b6a0 (rendering loop).
- **What this unblocks**: Maps Phase C3 (frame orchestration). Determines
  whether physics runs before rendering, and whether player updates before AI.

## Scenario Requests

### Sustained braking from high speed

- **Why needed**: The writer map was captured with idle/throttle/steer but NO
  brake input. Fields written only during braking (B button) may be completely
  missing from the writer map. Brake-specific fields are needed for the
  speed pipeline.
- **Suggested setup**: Time trial, Three Seven, accelerate to 60+ mph on
  straight, then hold B (brake) while steering straight. Capture 300+ frames
  of braking.
- **What it would unlock**: Brake-specific field identification, deceleration
  curve characterization.

### Airborne / jump scenario

- **Why needed**: Static analysis shows an airborne code path in FUN_0600c5d6
  (checks car flags & 0x00E00000 for ground vs airborne). FUN_0600c928
  (angular velocity reduction) and FUN_0600c7d4 (airborne heading update)
  only execute when airborne. No current save state exercises this path.
- **Suggested setup**: Race mode, find a bump or ramp that launches the car.
  If no natural jump exists, a wall collision at high speed may produce
  brief airborne state.
- **What it would unlock**: Airborne physics path validation, fields +0x48
  and +0x50 (angular velocity, only 31 unique values — rarely exercised).

## NOP Test Recommendations (for human)

These fields have enough evidence for targeted NOP tests. Each test patches
one write instruction and observes the effect. Requires `MODS=1` build.

### NOP Test: sym_0602D814 (speed accumulator, pipeline call 18) — PASSED 2026-03-15

- **What to NOP**: `jsr @r13` at 0x0602EF98 (opcode `4D 0B` → `00 09`).
  Poke command: `poke 0602EF98 00 09`. Skips the call to sym_0602D814
  (speed += accel_delta integration) in the player physics dispatcher.
- **Writer function**: sym_0602D814 in FUN_0602D43C.s (writes +0x0C, +0xE0, +0xE8)
- **Expected effect**: Speed freezes at its current value. Throttle (C) and
  braking (B) have no effect on speed.
- **Actual result**: **CONFIRMED.** Speed stayed at 0. Holding C had zero effect —
  "like C is unbound." Restoring save state restored normal behavior (C worked).
  sym_0602D814 is the sole gate for accel_delta → speed.
- **Best scenario**: Load `usa_tt_straight.mc0`, hold C from dead stop.
- **Confidence**: HIGH → **CONFIRMED**

### NOP Test: sym_0602D8BC (position writer, pipeline call 19) — PASSED 2026-03-15

- **What to NOP**: `jsr @r13` at 0x0602EF9E (opcode `4D 0B` → `00 09`).
  Poke command: `poke 0602EF9E 00 09`. Skips the call to sym_0602D8BC
  (position writer) in the player physics dispatcher.
- **Writer function**: sym_0602D8BC in FUN_0602D89A.s (writes +0x10, +0x18, +0x38, +0x3C, +0x18C, +0x190)
- **Expected effect**: Car position freezes. Speed still changes but car
  does not move on screen.
- **Actual result**: **CONFIRMED — with additional discoveries.** Tested twice.
  Raw observations:
  - Car graphic stayed locked at starting position. Never moved.
  - Speed/RPM/gears all worked normally — acceleration, gear shifts responded to C.
  - LEFT/RIGHT caused tire animation and camera rotation around the frozen car,
    as if the camera was following a heading change on a stationary car.
  - After sustained throttle + steering, acceleration behavior changed — consistent
    with the car's physics position having advanced onto grass (surface change).
  - At rest, camera pointed in a direction consistent with the car's simulated
    position around the circular track.
  - **Human theory (needs more data)**: The physics simulation has an internal
    position that continued advancing. sym_0602D8BC copies this to the rendered
    position fields (+0x10, +0x18). NOPping disconnected the visible car from
    the simulation. This suggests two position representations: physics-internal
    and render-output.
- **Best scenario**: Load `usa_tt_straight.mc0`, hold C from dead stop.
- **Confidence**: HIGH → **CONFIRMED** (position freeze). Human theory about
  dual position representations is plausible but unverified — needs Explorer
  investigation to identify the internal physics position fields.

### NOP Test: car[+0xFC] accel delta write — BLOCKED (bad address)

- **What to NOP**: Replace the write instruction at PC 0x0602EF4E with
  `nop` (0x0009).
- **Writer function**: FUN_0602EF4C (writes +0xFC at pc=0x0602EF4E)
- **Expected effect**: Acceleration delta stays at its current value. C button
  (throttle) has no effect on speed change rate.
- **Best scenario**: Load `usa_tt_straight.mc0`, hold C from dead stop.
- **Confidence**: HIGH — watchpoint-confirmed writer, C button correlation
  established (+70/update toward positive).
- **BLOCKED (2026-03-15)**: Instruction at 0x0602EF4E in the retail binary is
  `DC 0D` (`mov.l @(disp,PC), r12`) — a pool load, NOT a store to car[+0xFC].
  The preceding instruction at 0x0602EF4C is `91 08` (`mov.w @(disp,PC), r1`)
  — also a load. The PC 0x0602EF4E likely came from a free-build watchpoint
  trace where addresses differ from retail. **Mapper: please re-derive the
  write PC from retail addresses or identify which called function contains
  the actual `mov.l rN, @(0xFC, rM)` store instruction.**
