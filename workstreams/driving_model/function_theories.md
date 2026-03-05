# Driving Model Function Theories

All theories below are from STATIC ANALYSIS ONLY (Ghidra decompilation + ASM pool constant resolution).
None are empirically verified. Names are hypotheses. See `driving_model.md` for verification status.

## Player Physics Pipeline (callees of FUN_0600e71a)

### FUN_0600d266 — Empty function (CONFIRMED via decompilation)
- Ghidra decompilation: `return;`
- Called first in the pipeline. Likely a disabled/debug hook.
- Trivially confirmable with one breakpoint.

### FUN_06008318 — Gear shift handler
**Theory**: Handles gear shifting via UP/DOWN pad buttons.
**Evidence** (static):
- Checks car[+0xB8] countdown (0=ready to shift)
- On pad UP (flags & 0x10): sets shift direction to -1, starts 0x20-frame countdown
- On pad DOWN (flags & 0x20): sets shift direction to +1, starts countdown
- During countdown: looks up value from table at 0x060453CC indexed by countdown timer
- Writes result to car[+0x1D8] (gear effect on speed?)
- Only when sym_0607EBD0 > 0x258 (minimum speed/progress for shifting)
- Calls FUN_06034F78 twice (unknown purpose — maybe applies gear to drivetrain)
**Verification plan**: Watchpoint on car[+0xB8]. Press UP/DOWN during racing. Should see 0x20 written then decrement.

### FUN_06008640 — Collision/bounce flag handler
**Theory**: Processes collision bounce state and triggers bounce animation.
**Evidence** (static):
- Checks car flags byte & 0x08 (collision event flag?)
- If flag set: clears it, checks car[+0x1BC] for active collision state
- If car[+0x1BC] != 0: calls FUN_06008730 (bounce continuation)
- Else: sets car[+0xD4]=0x14, calls FUN_060086C0 with speed table lookup
- Uses tables at 0x060453B4/0x060453C4 (speed-indexed)
**Verification plan**: Drive into wall. Watchpoint car[+0x00] for flag & 0x08 being set.

### FUN_0600c4f8 — Speed/acceleration calculator
**Theory**: Computes acceleration from table lookups and updates car speed.
**Evidence** (static):
- Only runs for player cars (checks 0x0607EBC4 & 0x8000 == 0)
- Reads car[+0x08] as index into two tables (0x060477EC and 0x060454CC)
- Acceleration = table difference, scaled by fpmul with car[+0x198]
- Clamped between -4014 and half the scaled value
- Updates car[+0x0C] (speed): `+= acceleration`, floored at 0
- Then: `car[+0x08] = fpmul(car[+0x0C], 0x480000)` — converts speed back to table index
- Decrements car[+0xD4] timer if > 0
**Verification plan**: Watchpoint car[+0x0C] during acceleration. Should see it increase frame by frame.

### FUN_0600c5d6 — Core steering/force dispatcher
**Theory**: The central physics function — computes heading, applies forces, dispatches collision.
**Evidence** (static):
- Calls FUN_0600cd40 first (track position query)
- Three-way branch based on game state and collision timers:
  1. If mode==2 OR collision cooldowns active → friction only (CA96)
  2. If normal driving → collision check (CF58) then force application (CC38)
  3. If collision bounce active → decrement timer, friction only, increment counter
- Then speed calculation (C8CC)
- Final two-way branch based on car flags & 0x00E00000:
  - Ground: set heading from track, update XZ velocity via speed × sincos
  - Airborne: heading correction (C928), damping (C7D4), atan2 + vector rotation
**Verification plan**: This is the most complex function. Verify by NOPing individual callees and observing effects.

### FUN_0600ceba — Track segment advance
**Theory**: Detects when car crosses track segment boundaries and increments segment counter.
**Evidence** (static):
- Reads from segment table via car[+0x184] and sym_0607EB84
- Saves previous segment data to history field
- Calls FUN_06035228 twice (unknown — maybe segment transition processing)
- Detects large heading changes between frames
- If heading change > threshold: increments car[+0x228], saves progress timestamps
- car[+0x228] wrapping would indicate lap completion
**Verification plan**: Watchpoint car[+0x228]. Should increment ~15-30 times per lap as segments are crossed.

## Shared Physics Subfunctions (callees of FUN_0600c5d6)

### FUN_0600cd40 — Track segment data lookup
**Theory**: Looks up current track segment and checks for segment advance.
**Evidence** (static):
- Uses car[+0x1E4] as index into 24-byte entries in track table at car[+0x1E0]
- Reads table[+0x16] → car[+0x184]
- Calls FUN_0602744c (atan2): `atan2(car_x - segment_x, segment_z - car_z)` — angle to segment center
- If angle deviation exceeds 0x4000: advance to next segment (increment car[+0x1E4])
- Returns pointer to current segment entry (used by caller)
**Verification plan**: Watchpoint car[+0x1E4]. Should increment as car passes segment boundaries.

### FUN_0600ca96 — Track surface lookup (friction path)
**Theory**: Looks up track surface properties at current position and writes to surface buffer.
**Evidence** (static):
- Takes param_1 = track surface buffer (sym_06078680)
- Reads car[+0x1F8] and car[+0x1FC] for current/previous surface indices
- Adjusts car[+0x1FC] by ±4 based on delta clamping
- Computes table index from car[+0x1FC], looks up in surface table at sym_0607EB88
- Interpolates between two adjacent entries if fractional position is nonzero
- Writes surface normals/properties to param_1 buffer
- Called on the "friction only" path (no force application)
**Verification plan**: Compare surface buffer values on straight vs curve. Should differ significantly.

### FUN_0600cc38 — Track surface lookup (force path)
**Theory**: Similar to CA96 but reads from track query result instead of car struct.
**Evidence** (static):
- Nearly identical code structure to CA96
- But source index comes from param_1+0x14 (track segment data) instead of car struct
- Adjusts car[+0x1FC] by ±8 (vs ±4 in CA96) — faster convergence?
- Same table lookup and interpolation from sym_0607EB88
- Called on the "force application" path (active driving)
**Verification plan**: Compare with CA96 output on same frame. Should reference different but nearby table entries.

### FUN_0600c8cc — Heading-to-track angle calculator
**Theory**: Computes angle between car and track direction, adjusts car slip angle toward track.
**Evidence** (static):
- Calls FUN_0602744c (atan2): `atan2(track_x - car_x, track_z - car_z)` → target angle
- Computes delta: `(-target_angle) - car[+0x28]` — how far slip angle is from track
- Clamps adjustment per frame: max ±0x600 (±1536 in angle units)
- Updates car[+0x28] (slip angle) toward target
- Returns the target angle
**Verification plan**: Watchpoint car[+0x28]. On straight: should be near 0. On turn: should shift.

### FUN_0600c928 — Airborne angular velocity reduction
**Theory**: Reduces angular velocity based on speed when airborne.
**Evidence** (static):
- Computes damping: `min((car[+0x0C] >> 9) * 0xFFFF >> 8, 0x2000)`
  - Higher speed → more damping (capped at 0x2000)
- Subtracts from car[+0x48]: `car[+0x48] -= damping`
- Copies to car[+0x50] = car[+0x48]
- Only called in airborne path
**Verification plan**: Need airborne car to test. Could use a jump or ramp.

### FUN_0600c7d4 — Airborne heading/velocity update
**Theory**: Updates heading, pitch, roll, and velocity components for airborne cars.
**Evidence** (static):
- Saves heading: car[+0x1B0] = car[+0x20]
- Computes slip toward heading: `car[+0x28] - car[+0x20]`, shifted right by 1/2/3 based on speed
  - Speed > 0x118: shift 3 (least correction)
  - Speed > 0xFA: shift 2
  - Speed > 0xDC: shift 1
  - Slower = more heading correction per frame
- Updates heading: car[+0x20] += damped_slip
- car[+0x30] = heading change - track_yaw_rate
- car[+0x1C] = averaged with track pitch
- car[+0x24] = averaged with track roll
- Saves velocity: car[+0x38] = car[+0x10], car[+0x3C] = car[+0x18]
- Recomputes velocity via sincos(-car[+0x28]) × speed, same as ground path
**Verification plan**: Need airborne car. Watchpoint +0x1C, +0x24 during jump.

### FUN_0600cf58 — Collision dispatch (player only)
**Theory**: Checks for active collisions and dispatches to appropriate collision handler.
**Evidence** (static):
- Checks car[+0x04] (collision target) and car[+0x08] (speed index)
- If collision active AND speed > 0x96: checks flags for collision type
- Branch based on car[+0x0210] collision type:
  - Type 1: speed-based response, may set car[+0x1F8]=0x300/0x400 and car[+0x204]=0x80
  - Type 2: calls FUN_0600d210 if fast enough (>0xAF0), else FUN_0600d12c
- Calls FUN_06035168 for collision processing
- FUN_0600d12c appears to be the default collision response
- FUN_0600d0b8 called when collision sub-field is zero
**Verification plan**: Drive into wall or car. Watch car[+0x04] and car[+0x0210].

## AI-Specific

### FUN_0600c74e — AI core physics (equivalent of C5D6)
**Theory**: AI version of the steering/force function. Shares many callees with C5D6 but lacks collision dispatch and force application.
**Not yet decompiled — read FUN_0600C74E.c next.**

### FUN_0600c970 — AI-specific steering
**Theory**: Replaces the player's steering input with AI waypoint following.
**Not yet analyzed.**
