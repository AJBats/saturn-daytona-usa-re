# Explorer Priorities — Updated 2026-03-15

**Strategic direction**: Phase 2 pipelines ~75% mapped. Throttle/brake/gear/
traction/position all traced end-to-end. **Steering and collision are the
remaining blockers before Phase 3 (sim-level documentation) can begin.**

A sim without steering isn't playable. Steering is Priority #1.

## COMPLETED

- [x] Player physics call tree — 18/18 calls validated, all Tier 2
- [x] Position fields — +0x10/+0x18 confirmed, write-only output
- [x] Heading/slip angles — +0x20, +0x28, +0x30 (copy of +0x20)
- [x] Velocity fields — +0x18C = +0x10 - +0x38, +0x190 = +0x18 - +0x3C
- [x] Surface fields — +0x1FC surface type, +0xF4 terrain lateral force
- [x] Frame execution order — player first (3.4%), rendering last (93.1%)
- [x] Throttle pipeline — C → +0x74 → +0x84 → FUN_0602CA84 → +0xFC → speed
- [x] Brake pipeline — B → +0x90 → +0x8C → force
- [x] Gear pipeline — UP/DOWN → +0xDE, auto via +0xDC thresholds
- [x] Traction model — FUN_0602CCEC confirmed via NOP (grip, not speed cap)
- [x] Dual position theory — DISPROVED + human confirmed
- [x] NOP tests: sym_0602D814, sym_0602D8BC, FUN_0602EFF0, FUN_0602F5B6,
  FUN_0602CA84, FUN_0602CCEC (6 total, 5 passed, 1 partial)

## HIGH PRIORITY — Steering Pipeline (blocks Phase 3)

### 1. Where does D-pad steering enter the car struct?

- **Why**: This is THE blocker. We know:
  - FUN_0602EFF0 (call 2) reads car[+0xAC] for steering rotation
  - car[+0xAC] does NOT respond to D-pad LEFT/RIGHT (rolling_steer_left obs)
  - sym_0602FDA4 (call 1) reads g_pad_state for C/B/UP/DOWN but NOT LEFT/RIGHT
  - LEFT/RIGHT masks are 0x4000/0x8000 (from known button mapping)
  - Steering IS visible at 65+ mph via +0x20, +0x58, +0x5C changes
  - FUN_0602D43C (call 16a) gates heading correction on speed > 240

  The D-pad steering signal enters the car struct through a path OUTSIDE
  the 18-call player pipeline. This is likely in the shared code that runs
  between frames (input polling → car struct) or in the rendering/camera
  system that reads car fields.

- **What to do**: Two approaches:

  **(A) Trace from button to field**: Set a read watchpoint on g_pad_state+2
  (sym_06063D9A) during a frame with LEFT held. Every function that reads the
  pad state is a candidate for the steering writer. Compare the reader list
  between LEFT-held and idle frames — the DIFFERENCE is the steering path.

  **(B) Trace from field back to writer**: We know +0x58 and +0x5C respond
  to steering at 65 mph. Set watchpoint on car[+0x58] (0x06078958). Find
  which PC writes the different value when LEFT is held vs not. That writer
  is in the steering chain. Then trace backward: what does THAT function
  read that changes with LEFT?

  Approach B is more likely to succeed because +0x58 uses displacement-based
  `mov.l` addressing (the watchpoint WORKS for those — see sym_0602D814).

- **What this unblocks**: Completes the steering pipeline — the last major
  gap before sim-level documentation can cover all player inputs.

### 2. Collision response pipeline

- **Why**: FUN_0602D08A (call 16b) is the only untested pipeline call. It
  activates when car[+0x9E] != 0, which hasn't been observed in time trial.
  Collision is the second major gap — a sim needs to handle wall/car contact.

- **What to do**: Load `daytona_rebuilt.*.mc0` (race mode, 40 cars). Hold C
  and steer into AI cars or walls. Monitor car[+0x9E] — when it becomes
  nonzero, the alternate collision path activates. Capture the full car struct
  during collision to identify which fields change (compare pre/during/post
  collision frames).

- **What this unblocks**: Maps the collision response pipeline. Identifies
  which fields carry collision force, deflection angle, bounce behavior.

### 3. Lookup table extraction (blocks Phase 3 math documentation)

- **Why**: The driving model uses ~8 lookup tables for gear ratios, traction
  constants, force scaling. We know the table addresses but haven't dumped
  the actual values. Phase 3 documentation needs the exact constants to
  specify the computation formulas.

- **Tables to dump**:
  | Table | Address | Size hint | Role |
  |-------|---------|-----------|------|
  | sym_060477BC | gear ratios | indexed by +0xDC | speed → force scaling |
  | sym_060477AC | gear-up thresholds | indexed by +0xDC | section advance trigger |
  | sym_0604779C | gear-down thresholds | indexed by +0xDC | section retreat trigger |
  | sym_060477CC | section scaling | indexed by +0xDC | speed recomputation on shift |
  | sym_060477D8 | animation states | 4 entries | +0x114 lookup |
  | sym_0602E938 | force constants | indexed by +0x7C × +0xDC | gear × section force |
  | sym_0602F3CC | track force bounds | used by FUN_0602F270 | track force clamping |
  | sym_0602E8B8 | drift scaling | indexed by +0x250 | drift path rotation |

- **What to do**: `read_memory` on each table address, dump 64-128 bytes.
  Cross-reference entry count with the max index values from observations
  (e.g., +0xDC goes 0-3 in time trial = 4 gear sections minimum).

- **What this unblocks**: Enables Phase 3 — exact formulas with real constants.

## MEDIUM PRIORITY

### 4. Phase 3 readiness — sim-level documentation

- **Status**: Ready to begin for throttle/speed/position pipeline. Blocked
  on steering and collision for complete sim coverage.
- **Approach**: Write `workstreams/driving_model/sim_spec.md` documenting
  each pipeline stage's computation in pseudocode with actual constants.
  Start with the speed pipeline (fully traced), expand as steering/collision
  are resolved.

### 5. Remaining unknown fields

- ~40 car struct offsets have writer data but no pipeline role assigned.
  Low priority unless they turn up in steering/collision investigation.

## NOP Test Results (6 completed)

| Test | Poke | Result | Key Finding |
|------|------|--------|-------------|
| sym_0602D814 (speed) | 0602EF98 | PASS | Speed gate — sole speed integrator |
| sym_0602D8BC (position) | 0602EF9E | PASS | Write-only output, no dual position |
| FUN_0602EFF0 (rotation) | 0602EEC4 | PARTIAL | Kills ALL input — rotation is directional reference |
| FUN_0602F5B6 (surface) | 0602EF30 | UNEXPECTED | Kills throttle — surface feeds force directly |
| FUN_0602CA84 (force) | 0602EF48 | PASS | Clean throttle gate, steering independent |
| FUN_0602CCEC (traction) | 0602CC40 | PASS | Traction model — grip, not speed cap |
