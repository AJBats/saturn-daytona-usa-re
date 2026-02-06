# Gameplay Extraction via Direct ASM Analysis

> **The Sawyer Approach**: Study the assembly directly, trace from hardware interfaces backwards, build understanding through observation — not translation.

## Goal

Extract Daytona USA gameplay code (physics, steering, collision, AI) by analyzing the original SH-2 assembly directly. Skip C decompilation entirely.

## Why This Pivot

- The C was only a means to an end — a format for Claude to study
- **Claude can read assembly directly** — skip the middle step

## Approach

### 1. Hardware Interface Tracing

Saturn hardware has well-documented entry points. We trace backwards from these:

| Interface | Hardware | What It Reveals |
|-----------|----------|-----------------|
| **Input** | SMPC (0x20100001+) | Controller reads → menus, driving controls |
| **Sprites** | VDP1 (0x25C00000+) | Car/object rendering → position/transform data |
| **Backgrounds** | VDP2 (0x25E00000+) | Track graphics → course loading |
| **Sound** | SCSP (0x25B00000+) | Audio triggers → collision, events |
| **Interrupts** | SCU (0x25FE0000+) | VBlank/HBlank → game loop timing |

### 2. Observable Behavior Mapping

1. Identify something visible (e.g., "that's the car sprite")
2. Find where that data gets loaded in code
3. Trace backwards to find what manipulates it
4. Build call graph of related functionality

### 3. Subsystem Isolation

Once we understand enough, isolate subsystems:
- Physics engine (acceleration, braking, friction)
- Steering model (input → wheel angle → trajectory)
- Collision detection (car-car, car-wall, car-track)
- AI behavior (opponent racing logic)

---

## Milestones

### M1: Saturn Hardware Documentation ✓
- [x] Collect SMPC (peripheral) documentation
- [x] Document known memory map regions
- [ ] Collect VDP1/VDP2 documentation
- [ ] Collect SCU interrupt documentation

### M2: Input System Mapping ✓
- [x] Find SMPC polling pattern in aprog.s
- [x] Trace all call sites that read controller input
- [x] Map button assignments (see Research Notes below)
- [ ] Identify which functions handle menu vs gameplay input (partial)

### M3: Game Loop Understanding ✓
- [x] Understand the 32-state machine at main (0x06003000)
- [x] Map state transitions (menu → race → results)
- [x] Find the per-frame update routine (FUN_0600A392)
- [x] Identify VBlank interrupt handler (FUN_06006F3C = VBlank-IN, FUN_06007268 = VBlank-OUT)

### M4: Car Rendering Chain (Mostly Complete)
- [x] Find VDP1 command list building code (FUN_0602C494-0x0602D43C, 7 functions)
- [x] Find VDP1 initialization (FUN_0600A140: clears 64KB VRAM at 0x25C80000)
- [x] Identify camera/viewport setup (FUN_0602EFF0: hardware division, clipping)
- [x] Identify VDP1 register usage (TVMR, FBCR, PTMR, EWDR/EWLR/EWRR)
- [x] Double-buffer mechanism (FBCR register swap during VBlank-IN/OUT handlers)
- [x] Identify polygon data format (52-byte entries at 0x060A6000, 4-vertex quads)
- [x] Identify 3D scene processor (FUN_06027CA4 — transforms, culls, generates commands)
- [x] Map data tables: polygon pool (0x060A6000), texture index (0x060BF000), course segments (0x060C2000)
- [x] Trace FUN_0602F0E8 — track position management (wrapping, segment boundaries, smoothing)
- [x] Trace sprite sorting/draw-order system — NO runtime sort, pre-baked order in course data

### M5: Physics Extraction ✓
- [x] Find velocity/acceleration calculations
- [x] Identify collision response code (FUN_0600C5D6 → FUN_0600CD40/CA96/CC38)
- [x] Locate friction/drag model (FUN_0600D266 = stub! Friction baked into force tables)
- [x] Extract steering angle → trajectory math (FUN_06008640 → FUN_060086C0)
- [x] Map complete player physics pipeline (FUN_0600E71A, 8-step chain)
- [x] Map gas/brake → acceleration path (car flag bits 0x40/0x80 → force table → speed)
- [x] Identify player vs AI branching (FUN_0600E1D4, car index 0 = player)
- [ ] Trace force table data structures (0x060453B4, 0x060453C4 — format TBD)
- [ ] Trace speed curve from course tables (0x060477EC, 0x060454CC)

### M7: Sound System ✓
- [x] Find sound trigger mechanism (FUN_0601D5F4 — mailbox to 68000 via 0x25A02C20)
- [x] Trace initialization path (FUN_06018EE4 — SMPC SNDOFF/SNDON, DMA driver, handshake)
- [x] Identify command format (0xAAGGIIFF — prefix, group, ID, play flag)
- [x] Correct FUN_0602766C misidentification (SCU DMA, NOT sound dispatch)
- [x] Map gameplay sound trigger call sites (~30 locations)
- [x] Document SCSP register access (slots 16/17, common register at 0x25B00400)
- [ ] Map remaining sound IDs to game events (partial — 6 IDs identified)

### M6: AI Analysis (Mostly Complete)
- [x] Find opponent car update routines (FUN_0600E906 → FUN_0600EA18)
- [x] Identify pathfinding/racing line logic (track-following: velocity = (target-current) >> 4)
- [x] Trace FUN_0600C74E (AI-specific processing) — COMPLETE, see asm/ai_behavior.s
- [x] Document AI decision points — waypoint targeting, speed zones, heading damping
- [x] Locate difficulty scaling — segment-based speed modulation, NOT traditional rubber-banding

### M8: Race State Machine ✓
- [x] Decode State 14 (FUN_06008EBC) — first-frame race setup, → state 15
- [x] Decode State 15 (FUN_06009098) — main race loop, per-car iteration, → state 16/18
- [x] Decode State 16 (FUN_06009290) — post-countdown cleanup, → state 17
- [x] Decode State 17 (FUN_060092D0) — post-lap processing/results, → state 18/20/24/28
- [x] Decode State 18 (FUN_060096DC) — time extension setup (single frame), → state 19
- [x] Decode State 19 (FUN_06009788) — time extension active/input, → state 14/24/saved
- [x] Decode State 20 (FUN_06009508) — abort processing, → state 29
- [x] Map complete state transition graph (see asm/race_states.s)
- [ ] Decode States 24, 28, 29 (post-race, mode transition, results screen)
- [ ] Trace FUN_0600DE54 (per-car race state update — physics/collision per frame)
- [ ] Trace FUN_060078DC (frame timing/sync)

---

## Key Resources

- `build/aprog.s` — Full disassembly (206K lines, 1234 functions)
- `build/aprog_syms.txt` — Function addresses
- `ghidra_project/` — Ghidra analysis (cross-reference, call graphs)
- `docs/subsystem_map.md` — Existing architecture notes

## Output Artifacts

**Annotated `.s` files only** in the `asm/` directory. No markdown, no docs — just assembly with inline comments.

These comments are written by Claude for Claude. They should capture everything needed to understand the code without re-doing any research. Optimize for:
- What each function/block achieves (not just what each instruction does)
- Data structure layouts and field meanings
- Hardware register purposes and addresses
- Cross-references to callers/callees
- Why the code works the way it does (intent, not mechanics)

Research notes and progress tracking go in THIS file (the workstream md), not in `asm/`.

**Format**: SH-2 mnemonics with `!` comments:
```asm
! === SMPC INTBACK Response Handler ===
! Reads controller data from Output Registers after INTBACK command completes.
! Called from the SMPC interrupt path. Stores raw peripheral data to 0x060A4C9C.
! This is the bottom of the input chain — everything above consumes the struct this builds.

    mov.l   @(0xE0,PC),r2   ! r2 = 0x060A4C9C (peripheral data struct base)
    mov.l   @(0xE4,PC),r3   ! r3 = 0x20100031 (SMPC OREG8)
    mov.b   @r3,r3           ! Read OREG8 — peripheral ID upper nibble
    mov.b   r3,@r2           ! Store to struct+0x00
```

## Saturn Documentation (to gather)

- Sega Saturn Hardware Manual
- SH-2 Programming Manual
- VDP1/VDP2 User's Manual
- SMPC User's Manual

---

## Research Notes

### SMPC Input System

Three-stage pipeline:
```
SMPC INTBACK (HW)  →  Raw OREG struct (0x060A4C9C)  →  Processed input (0x0605B6D8)  →  Game code
```

**SMPC registers used in aprog.s:**
| Address     | Register | Purpose |
|-------------|----------|---------|
| 0x2010001F  | COMREG   | Command register — write 0x19 for INTBACK |
| 0x20100021  | OREG0    | First output register |
| 0x20100031  | OREG8    | Peripheral ID upper |
| 0x20100033  | OREG9    | Peripheral ID lower / data size |
| 0x20100035  | OREG10   | Button data byte 1 |
| 0x20100037  | OREG11   | Button data byte 2 |
| 0x20100039-3F | OREG12-15 | Extended button/analog data |
| 0x20100061  | SR       | Status register |
| 0x20100063  | SF       | Status flag (bit 0 = busy) |

**Functions touching SMPC:**
| Function | Role |
|----------|------|
| FUN_060030FC (0x060030FC) | Sends INTBACK command (0x19) to COMREG, polls SF for completion |
| 0x06039924+ (inside FUN_0603953C) | INTBACK response handler — reads OREGs, writes to 0x060A4C9C |
| FUN_06006F3C (0x06006F3C) | Button input consumer — reads processed state from 0x0605B6D8 |

**Raw peripheral struct at 0x060A4C9C:**
```
+0x00: byte  — OREG8 (peripheral ID upper)
+0x01: byte  — OREG9 (peripheral ID lower)
+0x02: word  — OREG10<<8 | OREG11 (button data 1)
+0x04: long  — OREG12-15 combined (button data 2 + extended)
+0x08: byte  — OREG0 (additional peripheral data)
```

**Button bit assignments (from tst instructions in FUN_06006F3C):**
| Bit | Hex  | Likely Button | Context |
|-----|------|---------------|---------|
| 2   | 0x04 | Right?        | Calls 0x0602766C with sound params |
| 4   | 0x10 | Left?         | Similar dispatch pattern |
| 5   | 0x20 | Start?        | Similar dispatch pattern |
| 6   | 0x40 | A (gas)       | Loads data from 0x0605B710/0C area |
| 7   | 0x80 | B (brake)     | Longest handler, jumps to 0x0600713C |
| 29  | 0x20000000 | Special? | Tested separately before button checks |

### Game State Machine

32-state dispatch at main (0x06003000). Jump table at 0x0600307C.
State variable lives at 0x0605AD10.

**State handlers (from jump table):**
| State | Address    | Purpose |
|-------|------------|---------|
| 0     | 0x060088CC | Startup/init |
| 1     | 0x0600890A | Transition |
| 2     | 0x06008938 | Attract mode setup |
| 3     | 0x06008A18 | Title/demo |
| 4     | 0x06008CCC | Mode select |
| 5     | 0x06008D74 | Course select |
| 6-11  | various    | Transitions |
| 12    | 0x06008E00 | Pre-race setup |
| 13    | 0x06008E48 | Race countdown |
| **14**| 0x06008EBC | **In-race gameplay** (188 insns) |
| **15**| 0x06009098 | **In-race gameplay** (202 insns) |
| 16    | 0x06009290 | Lap transition |
| **17**| 0x060092D0 | **In-race gameplay** (228 insns) |
| 18    | 0x060096DC | Time extension |
| **19**| 0x06009788 | **Complex race state** (298 insns) |
| 20    | 0x06009A60 | Race end / results |
| 21-31 | various    | Post-race, menus, diagnostics |

**State 15 call chain (in-race):**
```
FUN_06009098 (state 15)
  → FUN_060268B0  (UI/menu — only if flag at 0x0605AB18 set)
  → FUN_060033E6  (sub-init — only if flag at 0x0607ED8C set)
  → FUN_060302C6  (sound system update)
  → FUN_0602EFF0  (rendering)
  → FUN_0602F0E8  (rendering)
  → FUN_0600DE54  (RACE STATE UPDATE — the key call)
    → FUN_0600E99C  (pre-update)
    → FUN_0600E0C0  (main race update — calls 3D scene processing at FUN_06027CA4)
```

### Vehicle Physics Area (0x0600D0B8-0x0600DC74)

Key data pointers:
- 0x0607E940 — game object pointer (copied each frame)
- 0x0607E944 — game object pointer (current)
- 0x0607EA98 — race position / car count
- 0x0607EBC4 — frame/state counter
- 0x06078900 — object data base

FUN_0600D0B8 does position/velocity clamping:
- Reads flags via mask 0x00C00000 from object+0
- Compares values at offset 0x200 between two objects (player vs track?)
- Clamps result between 0 and 0x0800
- Uses constants: 0x0200 (offset), 0x01FC (alt offset), 0xFE00 (negative clamp), 0x01F8, 0x0800 (max)

FUN_0600D3C4 does car sorting/ordering by track position:
- Reads from 0x0607E9EC (object list)
- Compares track position values
- Swaps object pointers when out of order (bubble sort)
- Stores final count to object

### Velocity Calculation (FUN_0600EA18)

This LEAF function computes per-frame velocity from track segment data:
1. Reads 4 fields from car+0x120..0x12C (track segment flags)
2. OR of all 4 = "any data present"; AND with bit 0x80 = special case
3. Maintains approach counter at 0x0605A228 (max 160 frames = ~2.7 sec at 60fps)
4. Computes delta: target_pos (from track segment at 0x0607EB88) minus current_pos
5. Divides by 16 (4x shar): velocity = delta >> 4
6. Angular velocity = (target_heading * 4 - current_heading), sign-extended

Track segment indexing: index * 512 + 48 bytes into the table.
Each segment has: X (long), Z (long), heading (word at +0xA).

**Velocity outputs (consumed by position integrator):**
| Address    | Value | Update |
|------------|-------|--------|
| 0x060786C0 | vel_X | (target_X - car_X) >> 4 |
| 0x060786C4 | vel_Z | (target_Z - car_Z) >> 4 |
| 0x060786C8 | ang_vel | sign_ext(target_heading*4 - heading) |

### Position Integration (at 0x0600E5B4)

Runs each frame when timer > 0 and flag 0x06078635 == 0:
```
car.X     += velocity_X     (offset +0x10)
car.Z     += velocity_Z     (offset +0x18)
car.heading += angular_vel  (offset +0x20, read as word not long!)
car[+0x28] = car[+0x30] = heading  (copy to secondary fields)
```
Then calls FUN_06006838(car.X, car.Z) to update tile grid coordinates.

### RESOLVED: Player vs AI Physics Path

**Branching point**: FUN_0600E1D4 (per-car update dispatcher)
- Reads car index from `0x0607EAD8`
- Car index 0 = player → calls **FUN_0600E71A** (controller-driven physics)
- Car index != 0 = AI → calls **FUN_0600E906** (track-following physics)

**Player physics pipeline** (FUN_0600E71A):
```
1. FUN_06008318 — Controller input: gear shift, steering column
2. 0x06008640  — Gear/force table selection
3. FUN_0600D266 — (stub: rts immediately, friction placeholder?)
4. FUN_0600C4F8 — Speed computation & velocity clamping
5. FUN_0600C5D6 — Collision detection, heading→position integration
6. (inline)     — Timer countdown, track segment check
7. FUN_0600CEBA — Track segment advancement & heading interpolation
8. (inline)     — Score/ranking computation
```

**AI physics pipeline** (FUN_0600E906):
```
1. FUN_0600D266 — (same stub as player)
2. FUN_0600C74E — AI-specific processing
3. FUN_06027552 — Heading computation (fixed-point multiply)
4. FUN_0600CEBA — Same track segment advancement as player
5. FUN_0600EA18 — Track-following velocity (target - current) >> 4
```

**Key difference**: Player uses force lookup tables driven by controller
buttons (gas/brake/steering). AI uses simple track-segment chasing.

### Gas/Brake → Acceleration Path

The acceleration chain from controller to position:

1. **SMPC → car flags**: Controller buttons are written to car object byte 0.
   Bit 0x40 = gas (A button), bit 0x80 = brake (B button).

2. **FUN_06008318**: Handles gear shifting (bits 0x10/0x20). Sets gear
   direction (+1/-1) and countdown timer. Looks up steering deflection
   from table at `0x060453CC`.

3. **0x06008640 → FUN_060086C0**: Selects force table based on game state:
   - Normal: `0x060453B4` (indexed by player_state & 1)
   - Special: `0x060453C4` (countdown mode)
   Calls `FUN_06034F78` twice (interpolation), then reads a 12-byte record:
   - word +0x04: steering factor
   - word +0x06: X force (negated)
   - word +0x08: Z force (negated)
   - word +0x0A: angular force (negated)

4. **Post-force (0x06008730+)**: Reads the current steering record.
   Car flag bits 0x40 (gas) and 0x80 (brake) determine which forces apply:
   - Gas: full force application from record
   - Brake: alternative force path
   Forces stored into car struct fields.

5. **FUN_0600C4F8**: Computes speed scalar from course data tables.
   `base_speed = table_A[segment] - table_B[segment] + 0xFEC00000`.
   Clamps to valid range. Stores to car+0x08.

6. **FUN_0600C5D6**: Position integration:
   ```
   heading = track_data[segment].heading → FUN_06027358 → (sin,cos)
   car.X += FUN_06027552(car.speed, X_direction)
   car.Z += FUN_06027552(car.speed, Z_direction)
   ```

### Car Object Struct Layout (Partial)

```
+0x000: byte  — flags (0x08=special, 0x10=shift_down, 0x20=shift_up,
                        0x40=gas, 0x80=brake)
+0x001: byte  — secondary flags
+0x004: long  — car sub-type / secondary pointer
+0x008: long  — speed (heading-relative scalar)
+0x00C: long  — acceleration / distance accumulator
+0x010: long  — X position (world)
+0x014: long  — Y position (world, always 0)
+0x018: long  — Z position (world)
+0x020: long  — heading (yaw angle)
+0x028: long  — heading copy A
+0x030: long  — heading copy B
+0x0B8: long  — steering input timer
+0x0D4: long  — mode field
+0x120..0x12C — track segment flags (4 longs, used by FUN_0600EA18)
+0x184: long  — current track segment index
+0x1BC: byte  — collision flags
+0x1DC: long  — gear shift countdown timer
+0x1E4: long  — sub-timer (decremented per frame)
+0x1EC: long  — distance remaining on track
+0x1F0: long  — segment counter (incremented at boundaries)
+0x1F4: long  — ranking/position value
+0x200: long  — track position comparison value
+0x208: long  — main timer
+0x228: long  — race position value (× car count for ranking)
+0x258: word  — gear shift sound parameter
+0x301: long  — gear direction (+1=up, -1=down)
+0x350: long  — steering deflection value
```

### Key Data Tables

| Address | Purpose |
|---------|---------|
| 0x060453B4 | Steering/force table A (normal racing) |
| 0x060453C4 | Steering/force table B (special state) |
| 0x060453CC | Gear steering lookup (signed word per frame) |
| 0x060454CC | Course speed table B |
| 0x060477EC | Course speed table A |
| 0x06078680 | Track collision/physics data base |
| 0x0607EB84 | Track segment table pointer |

### Shared Functions (Used by Both Player and AI)

| Function | Purpose |
|----------|---------|
| FUN_0600D266 | Friction stub (rts — no-op, called by both) |
| FUN_0600CEBA | Track segment advancement & heading interpolation |
| FUN_06027552 | Fixed-point multiply: r0 = (r4 × r5) >> 16 |
| FUN_06027358 | Heading → direction vector (sin/cos) |
| FUN_06035228 | Heading interpolation toward target |
| FUN_06034F78 | General interpolation function |

### Force Table Data Structures

The tables at 0x060453B4 and 0x060453C4 are **pointers TO** force data, not the data itself.
After dereferencing (`mov.l @r4,r4`), you get a pointer to a force record array.

**Selection logic** (in FUN_06008640):
- Table A (0x060453B4): indexed by `(player_state & 1) × 8` (two sub-tables, 8 bytes apart)
- Table B (0x060453C4): used during countdown/special state
- Both lead to FUN_060086C0 which reads force records

**Force record structure** (12 bytes per record):
```
+0x00: long  — indirect pointer (to sub-record or next record)
+0x04: word  — steering factor (applied to heading)
+0x06: word  — X force component (negated when applied to car)
+0x08: word  — Z force component (negated when applied to car)
+0x0A: word  — angular force (negated when applied to car)
```

**Gear steering lookup** (0x060453CC):
- Array of signed 16-bit words
- Indexed by countdown timer value (word-indexed: `timer × 2 + base`)
- Value is sign-extended and either kept or negated based on gear direction
- Stored as steering deflection in car struct

### VDP1 Rendering System

**Rendering pipeline** (called every in-race frame from states 14/15/17/19):
```
FUN_0602EFF0 — Rendering Pass 1: Camera/viewport setup
  → Hardware DIVISION via FUN_0602ECCC (called 3× — NOT matrix multiply)
  → FUN_0602ECCC uses SH-2 divider at 0xFFFFFF00 (DVSR/DVDNT registers)
  → Disables interrupts during division (ldc #0xF0,sr)
  → Three divisions: horizontal, vertical, depth viewport dimensions
  → Viewport clipping against boundaries [0x38, 0xB8]

FUN_0602F0E8 — Rendering Pass 2: Frame buffer / command table
  → Read FBCR register (frame buffer swap control)
  → Build VDP1 command table entries
  → Sprite/polygon sorting by priority
  → Write draw-end marker
```

**VDP1 registers used:**
| Address | Register | Purpose |
|---------|----------|---------|
| 0x25C00000 | VDP1 base | Command list control |
| 0x25C80000 | VDP1 VRAM | 64KB command table buffer |
| 0x25D00000 | TVMR | TV mode (3-bit) |
| 0x25D00002 | FBCR | Frame buffer swap |
| 0x25D00004 | PTMR | Polygon timing (set to 2) |
| 0x25D00008 | EWDR | Erase/write data register |
| 0x25D0000A | EWLR | Erase window left |
| 0x25D0000E | EWRR | Erase window right |

**VDP1 initialization** (FUN_0600A140):
- Clears 64KB VRAM at 0x25C80000 (two passes for double-buffer)
- Sets TVMR register
- Calls FUN_06026CE0 (texture/palette setup)

**Double-buffer mechanism**: FBCR register alternates each frame between
two 32KB halves of VDP1 VRAM.

### AI Processing Pipeline (FUN_0600C74E) — COMPLETE

The AI main processing function at FUN_0600C74E orchestrates all behavior for one AI car per frame. It's called from FUN_0600E906 after basic setup.

**9-step pipeline:**
1. **FUN_0600CD40** — Waypoint targeting: finds next waypoint using 24-byte records, computes atan2 approach angle, bumps "missed" counter if angle too far off
2. **0x0600CA96** — Course correction: smooths position tracking between waypoints, interpolates between adjacent records using weighted average (mul + shar×2)
3. **Inline speed zone check** — If track position in [46, 59]: override target speed with fixed value 0x4000; otherwise call FUN_0600C8CC
4. **FUN_0600C8CC** — Speed targeting: computes distance/angle to waypoint, adjusts speed based on approach angle mismatch
5. **Copy** target heading from +0x28 to +0x20
6. **0x0600C970** (conditional) — Speed boost lookup: 30-entry table at 0x0605A1E0, indexed by track position [69-98], adds signed word to acceleration
7. **0x0600C928** — Velocity/friction: computes drag proportional to speed (speed >> 9, then scale × 256), subtracts from both velocity components at +0x48 and +0x50
8. **FUN_0600C7D4** — Heading/steering: SPEED-BASED DAMPING is the key insight:
   - Speed > 280: shar×3 (heavy damping, sluggish at high speed)
   - Speed > 250: shar×2 (medium)
   - Speed > 220: shar×1 (light)
   - Speed ≤ 220: no damping (full steering)
   Then converts heading to X/Z via sin/cos lookup (0x06027358), multiplies by speed (0x06027552), updates position
9. **0x06006838 + FUN_06027EDE** — Grid index packing and sprite/rendering update

**Key AI data structures:**
| Address | Size | Description |
|---------|------|-------------|
| 0x0607E940 | ptr→struct | AI state pointer (indirected) |
| 0x06078680 | struct | Track/course data base |
| 0x0607EB88 | ptr→array | Waypoint table (24 bytes per record) |
| 0x0605A1E0 | 30 words | Speed boost table (for track positions 69-98) |

**Waypoint record layout (24 bytes):**
```
+0x00: long  — X position
+0x04: long  — Z position
+0x08: word  — turn rate
+0x0A: word  — scaled turn rate
+0x0C: word  — heading data
+0x0E: word  — steering factor
+0x16: word  — yaw angle (heading)
```

**AI decision points identified:**
1. Speed zone [46,59] — fixed override speed (perhaps a straight section)
2. Speed boost zone [69,98] — per-segment speed profile from table
3. Heading damping varies with speed — realistic physics: less agile at high speed
4. Waypoint "missed" counter resets after exceeding car_count — prevents permanent locking
5. Timeout at 160 frames in track-following (0x0600EA18) — resets if AI gets stuck

**AI vs Player comparison summary:**
| Aspect | Player | AI |
|--------|--------|----|
| Speed control | Force tables from gas/brake buttons | Waypoint distance + speed table |
| Steering | Controller input → force lookup | Heading delta with speed-based damping |
| Velocity | Force → speed → heading × speed | (target - current) >> 4 |
| Friction | Stub (FUN_0600D266 = nop) | Drag proportional to speed (0x0600C928) |
| Track advancement | FUN_0600CEBA (shared) | FUN_0600CEBA (shared) |

## Progress Log

### Session 2026-02-06
- Workstream created
- Pivot from C decompilation to direct ASM analysis
- Goal: trace from hardware interfaces to gameplay code
- Traced SMPC input chain end-to-end (HW → struct → game code)
- Mapped all 32 game state handlers from jump table
- Traced state 15 call chain to race update system
- Traced full velocity calculation chain:
  - FUN_0600EA18 computes velocity from track segment delta
  - velocity = (target_position - current_position) >> 4
  - Writes to 0x060786C0/C4/C8 (X vel, Z vel, angular vel)
  - Position integration at 0x0600E5B4: pos += vel each frame
- Created annotated .s files: input_smpc.s, game_loop.s, race_update.s
- Open question: FUN_0600EA18 appears to be a track-following "chase" behavior
  (approaching target positions along track segments). This may be the AI/demo
  path. Player input → acceleration path still needs to be traced separately.
- **RESOLVED**: Traced player vs AI branching at FUN_0600E1D4:
  - Car index 0 (player) → FUN_0600E71A (controller-driven, force tables)
  - Car index != 0 (AI) → FUN_0600E906 (track-following via FUN_0600EA18)
- Traced complete player physics pipeline (8 steps):
  FUN_06008318 → 0x06008640 → FUN_0600D266 → FUN_0600C4F8 → FUN_0600C5D6 → timers → FUN_0600CEBA → score
- Traced gas/brake → acceleration path:
  - Car flag byte 0: bit 0x40 = gas, bit 0x80 = brake
  - Force tables at 0x060453B4/C4 contain 12-byte records (steering, X/Z/angular forces)
  - FUN_060086C0 reads forces, negates, stores to car struct
  - FUN_0600C5D6 integrates: car.X/Z += FUN_06027552(speed, direction)
- Discovered FUN_0600D266 is a stub (rts only) — friction is NOT a separate step
- Created annotated asm/player_physics.s documenting full player + AI physics
- Documented partial car object struct (25+ fields identified)
- Identified 6 shared utility functions used by both player and AI
- Traced force table data structures:
  - 0x060453B4/C4 are pointers TO force records (not direct data)
  - Force records are 12 bytes: pointer + steering + X/Z/angular forces
  - 0x060453CC is the direct gear steering lookup (signed words)
- Traced VDP1 rendering chain:
  - FUN_0600A140 initializes VDP1 (clears 64KB VRAM at 0x25C80000)
  - FUN_0602EFF0: camera/viewport setup (3× matrix multiply, clipping)
  - FUN_0602F0E8: frame buffer management, command table building
  - Double-buffer via FBCR register at 0x25D00002
  - Identified 7 VDP1 registers used (TVMR, FBCR, PTMR, EWDR, EWLR, EWRR)
- Updated milestones: M4 (Rendering) now partial, M5 (Physics) complete, M6 (AI) partial
- Traced FUN_0600C74E complete AI processing pipeline (9 steps):
  - FUN_0600CD40: waypoint targeting with atan2 angle check
  - 0x0600CA96: waypoint interpolation (weighted average between adjacent records)
  - Inline speed zone [46,59] with override value
  - FUN_0600C8CC: speed targeting from waypoint distance
  - 0x0600C970: speed boost table (30 entries at 0x0605A1E0 for positions 69-98)
  - 0x0600C928: drag/friction proportional to speed
  - FUN_0600C7D4: heading with SPEED-BASED DAMPING (3 thresholds: 280/250/220)
  - 0x06006838: grid coordinate packing (64×N grid, 21-bit shift)
  - FUN_06027EDE: sprite/rendering update
- Traced 0x0600EA18 track-following velocity in detail:
  - 160-frame timeout mechanism (resets if AI stuck for ~2.7 seconds)
  - Flag checking: bits 0x80 and 0x33 control velocity reset
  - Velocity = (waypoint - car) >> 4 for X, Z, heading
  - Zeroes speed/acceleration fields, sets flag words to 1
- Waypoint records are 24 bytes each (not 20 as initially estimated)
- Created asm/ai_behavior.s with full annotated AI pipeline
- Updated M6: AI Analysis now mostly complete (only difficulty scaling remains)
- Key insight: AI speed-based heading damping creates realistic behavior —
  at high speed the car steers sluggishly, at low speed it's very responsive
- CORRECTED: FUN_0602ECCC is NOT a matrix multiply — it's HARDWARE DIVISION
  - Uses SH-2 divider unit at 0xFFFFFF00 (DVSR, DVDNT, quotient registers)
  - Disables all interrupts during division (SR = 0xF0) to protect registers
  - Three calls in FUN_0602EFF0: one per viewport dimension (H, V, depth)
- Camera pipeline detailed analysis:
  - Raw delta → |abs| → subtract deadzone 0xAC → clamp → sign restore
  - Scale by 0xFF → divide by base → store as viewport coordinate
  - Clamp to [0x38, 0xB8] (56-184 pixels on 320-wide display)
  - Exponential smoothing: (raw<<8 + running_avg) >> 1
  - Track position wrapping at 0x71C (1820 units = course length)
  - Course-aware boundaries from tables at 0x060477AC / 0x0604779C
- Updated asm/rendering.s with corrected FUN_0602ECCC analysis + annotated code
- Began tracing speed curves from course tables (FUN_0600C4F8):
  - table_A at 0x060477EC and table_B at 0x060454CC are arrays of 32-bit values
  - Indexed by car[+0x08] × 4 (track segment index)
  - base_speed = table_A[segment] - table_B[segment] + 0xFEC00000
  - Result passed through FUN_06027552 (fixed-point multiply) twice
  - First multiply: base_speed × 1 (identity/sign normalization)
  - Second multiply: result × car[field] (some scaling factor)
  - Final clamping: value / 2, clamp between r12 and computed bounds
  - Accumulator at car[+0x0C] updated: acc += delta, floor at 0
  - Final speed = (acc × 0x00480000) >> 16, sign-extended to word
  - Stored to car[+0x08] — this IS the speed field
  - table_B data at 0x060454CC: starts with ascending values (0x0010, 0x0010, 0x08A1, ...)
    suggesting per-segment speed differentials
  - table_A data at 0x060477EC: values like 0x0BD5_2BD3 — large fixed-point numbers
  - 0x060454CC also referenced by FUN_0602F6B6 (rendering) — dual-use table
  - Speed curve = difference between two course profiles, creating hills/valleys of speed
- Traced VBlank interrupt system (M3 complete):
  - VBlank-IN handler: FUN_06006F3C (registered as SCU vector 0x40)
  - VBlank-OUT handler: FUN_06007268 (registered as SCU vector 0x41)
  - Registration via BIOS function at 0x06000300(vector, handler)
  - SCU interrupt mask at 0x25FE00A4 — bit 1 enables VBlank-OUT
  - VBlank counter at 0x0607864C (incremented every 1/60s)
  - Phase tracking at 0x06059F54: 1=IN, 3=OUT-start, 4=OUT-end
  - Frame buffer swap via VDP1 FBCR register (0x25D00002)
  - ADAPTIVE frame timing: per-state target table at 0x06059F58+state_index
  - VBlank-OUT handler compares OUT count vs target before swapping
  - Main loop does NOT explicitly wait for VBlank — sync is implicit
  - VBlank-IN also processes controller input (button -> sound dispatch)
  - Frame buffer state machine manages TVMR/FBCR writes during VBlank
- Traced CD block status reading chain:
  - FUN_06018EAC -> FUN_060349C4 -> FUN_06034A10 -> FUN_06035E5E
  - Reads CD response registers at 0x25890018-0x25890024 (CR1-CR4)
  - Uses consistent double-read (interrupts disabled, compare, retry 100x)
  - Per-frame check in FUN_0600A392: if CD status == 6 (tray open), call BIOS
- Traced sound system reset (FUN_06018EE4):
  - SMPC SNDOFF (command 7) -> halt 68000
  - SCSP master control write (0x25B00400 = 0x0200)
  - Sound data setup -> SMPC SNDON (command 6) -> restart 68000
  - Handshake: poll 0x25A02DBC until 68000 writes 0x4F4B ("OK")
  - SCSP volume init: 0x25B00217 = 0x25B00237 = 0xE0
- Updated BIOS function table understanding:
  - 0x06000300: interrupt handler registration (r4=vector, r5=handler)
  - 0x06000344: interrupt mask control (r4=mask, r5=flags)
  - 0x0600026C: BIOS service call (used when CD tray open)
- Created asm/vblank_system.s with full annotated VBlank system
- Traced 3D rendering pipeline data structures (M4):
  - Polygon data pool at 0x060A6000: 52-byte entries (0x34 per polygon)
    - 4-vertex quadrilaterals with per-vertex transform parameters
    - Bit flags: 0x01/02/04/08000000 control coordinate system transforms
    - Each entry: flags, multiply factors, add offsets, base color/material
  - Course segment lookup at 0x060C2000: maps course sections to polygon indices
    - 4-byte entries: polygon_index (word) + polygon_count (word)
  - Texture/material index at 0x060BF000: maps visual properties to texture resources
  - VDP1 command generation: 7 functions at 0x0602C494-0x0602D43C
    - Build standard 32-byte VDP1 command blocks (CMDCTRL, CMDLINK, CMDPMOD, etc.)
    - Write to 0x25C80000 (VDP1 VRAM command table)
    - Link commands via CMDLINK fields for hardware traversal
  - FUN_06027CA4: main 3D scene processor
    - Reads polygon data from 0x060A6000 pool
    - Transforms vertices using 32-bit fixed-point matrix math
    - Culls back-facing polygons
    - Outputs to VDP1 command builders
  - FUN_0602F0E8: track position management (NOT command building)
    - Exponential smoothing on obj[+0x68] = (obj[+0xB0] << 8 + old) >> 1
    - Position wrapping within course length (0x71C = 1820 units)
    - Segment boundary detection using tables at 0x060477AC/0x0604779C
    - Per-segment scaling via 0x060477CC table with fixed-point multiply
- Traced collision detection & response system (M5 collision complete):
  - FUN_0600C5D6: main player collision handler + position integration
    - Three paths: course correction, heading update, collision response
    - Position integration: X += speed*sin(heading), Z += speed*cos(heading), Y=0
  - FUN_0600CD40: track-relative position query
    - Computes angle to track segment center via FUN_0602744C (atan2)
    - Detects off-track condition (angle > segment_width * 4)
    - Off-track counter with global threshold at [0x0607EA9C]
  - FUN_0600CA96: gentle course correction (dead zone ±8, step ±4)
    - Sin/cos vector table at 0x0607EB88 with linear interpolation
    - 256-entry direction table indexed by heading byte
  - FUN_0600CC38: stronger heading correction (step ±8)
    - Same sin/cos lookup, wider correction for normal driving
  - FUN_0600CF58: collision response dispatcher (224 instructions)
    - Early exits: no partner, speed < 150 (0x96), no collision flags
    - Calls FUN_06035168 for geometry classification
    - Head-on (bit 0x02): speed comparison → passive or heading snap
    - Side hit (bit 0x01): mode 2 = aggressive, mode 1 = proportional heading
    - Default: passive response
  - FUN_0600D12C: passive collision response (position separation)
    - Z threshold: 0x80000, X threshold: 0x0F0000
  - FUN_0600D210: aggressive collision response (speed-based push)
    - Speed delta must be in [-768, 768] range
    - Push ±16 per frame, clamped to [0, 2048]
    - Sets 64-frame collision timer
  - FUN_0600C928: speed reduction during collision
    - Reduces car[+0x48] and car[+0x50] by computed deceleration
  - FUN_0600C970: AI-only speed boost from course table
    - Table at 0x0605A1E0, segments [69,98] only
    - This is likely rubber-banding / difficulty mechanism
  - Created asm/collision.s with full annotated assembly
- Traced VDP1 sprite sorting / draw-order system (M4 complete):
  - FUN_06027CA4: 3D scene processor (culling, transform, command generation)
  - **NO runtime sorting algorithm** — polygon draw order is pre-baked in course data
  - Course segment table at 0x060C2000: (polygon_start, polygon_count) per segment
  - Segments traversed back-to-front based on camera Z position
  - Camera position → segment range: (cam_Z + 0x04000000) >> 21
  - Per polygon: material lookup at 0x060BF000, data from 0x060A6000 (52-byte entries)
  - Matrix transform via dmuls.l (64-bit signed multiply)
  - Backface/frustum culling via sign tests on transformed coordinates
  - Flag bits control coordinate system (0x01/02/04/08000000)
  - VDP1 commands built incrementally in traversal order → painter's algorithm
  - 7 command builders at 0x0602C494-0x0602D43C create 32-byte VDP1 command blocks
  - CMDLINK field chains commands for VDP1 hardware linked-list traversal
  - FUN_0602DB22: per-frame command list reset (zeros state vars, sets depth scaling)
  - Mode 2 path uses overlay table at 0x06061270 for special segment rendering
  - Updated asm/rendering.s with scene processor documentation
- Traced difficulty scaling system (M6 complete):
  - **No traditional rubber-banding** — AI speed does NOT depend on race position
  - Speed boost table at 0x0605A1E0: 30 signed word entries, segments [69, 98]
    - Segments 69-73: deceleration (-200 to -800) — entering a major corner
    - Segments 74-75: neutral (0)
    - Segments 76-98: acceleration (+50 to +400) — exiting corner, progressively weaker
    - Profile: brake hard into corner, strong acceleration out, tapering off
  - FUN_0600C970: applies table values to car[+0x0C] (speed accumulator)
    - Only called for AI cars (from FUN_0600C74E)
    - Only when car[+4] == 0 (no active collision partner)
  - FUN_0600C74E segments [45, 60]: AI forced heading override
    - Cars get a fixed heading angle forced at specific turn
    - Prevents AI from computing its own racing line through this section
  - FUN_0600CD40: off-track detection with configurable threshold
    - Counter at car[+offset] incremented each frame when off-track
    - Threshold at [0x0607EA9C] controls max off-track frames before reset
  - Game mode/difficulty params around 0x0605AD00-0x0605AD20
    - 0x0605AD10: game state (32-state machine index)
    - Referenced by state handlers for configuration
  - **Summary**: difficulty comes from track geometry design + per-segment speed profiles,
    not from adaptive rubber-banding. All AI cars use the same speed table.
- Traced complete sound/SCSP system:
  - **Architecture**: SH-2 → shared sound RAM mailbox → 68000 sound driver → SCSP
  - **Command mailbox**: 0x25A02C20 in sound RAM
    - SH-2 writes 32-bit command, 68000 reads and clears to 0
    - FUN_0601DB84: busy-wait with 100K iteration timeout
  - **Sound command format**: 0xAAGGIIFF
    - 0xAE = sound trigger prefix, GG = group, II = ID, FF = play flag
    - Group 00 = system/stop, 06 = BGM, 11 = gameplay SFX
  - **Main API**: FUN_0601D5F4 (r4=type, r5=param) — 30+ call sites
    - type 0: direct command, type 1-5: channel volume/config, type 15: alias for 0
  - **Sound init** (FUN_06018EE4):
    - SMPC SNDOFF (cmd 7) → clear 512KB sound RAM → DMA driver code/data
    - SMPC SNDON (cmd 6) → wait for 68000 ready (0x25A02DBE == 0xFFFF)
    - SCSP common register config at 0x25B00400
    - Master volume: 0xE0 to slot 16/17 EFSDL registers
  - **CORRECTION**: FUN_0602766C is NOT sound dispatch — it's generic SCU DMA
    - Registers: D0R/D0W/D0C at 0x25FE0000, DSTA poll at 0x25FE007C
    - Used for VDP2 palette uploads, sound data, general transfers
  - **Known sound IDs from gameplay callers**:
    - 0xAE0001FF: system/stop sound (state transitions)
    - 0xAE0600FF: BGM start
    - 0xAE1114FF: periodic in-race SFX (engine? triggered at 120-frame intervals)
    - 0xAE111BFF: button-triggered SFX (controller bit 0x10)
    - 0xAE1138FF: race countdown beep (every 64 frames)
    - 0xAE1139FF: race countdown variant (course 1 specific)
  - Created asm/sound.s with full annotated assembly
- Traced complete in-race state machine (M8):
  - **State transition graph**:
    ```
    State 14 (first-frame setup) ──→ State 15 (main race loop)
                 ↑                          │
                 │                    ┌─────┴─────┐
                 │              countdown=0    start btn
                 │                    ↓           ↓
                 │              State 16 ──→ State 18 (time ext setup)
                 │              (cleanup)         │
                 │                    ↓           ↓
                 │              State 17 ──→ State 19 (time ext active)
                 │              (results)    │    │    │
                 │                │    │     │    │    └─→ saved_state
                 │            abort  timer=0 │   A+B+C held
                 │              ↓     ↓     │    ↓
                 │         State 20  State 24│   State 24 / State 14
                 │              │   (post)   │
                 │              ↓            │
                 │         State 29 ←────────┘
                 │              │
                 │              └─→ State 18 (start)
                 └──────────────────(A+B+C in state 19)
    ```
  - **State 14** (FUN_06008EBC): First-frame race setup
    - Clears phase flag [0x06078635]=0, sets race_active [0x06078634]=1, timer [0x0607ED88]=8
    - Button event mapping: reads masks from 0x06063D98, maps to event IDs 0-3 at [0x06078648]
    - Main pipeline: FUN_0600A0C0 → FUN_06018A3C → FUN_0601F784 → FUN_0600EB14 (race update)
    - HUD: FUN_06033AAC → FUN_060321C0 (display)
    - Sets display flag bit 30 (0x40000000) in [0x0605B6D8]
    - Immediate transition to state 15
  - **State 15** (FUN_06009098): Main race loop (CORE GAMEPLAY)
    - Start button check: save resume=15, → state 18 (time extension)
    - Decrements countdown at [0x0607EAAC] each frame
    - Per-car inner loop: r12 iterates 0 to [car_count]:
      - First iteration (r12==0): player car, sets [0x0607ED8C]=1
      - Each car: FUN_060302C6 (sound) → FUN_0602EFF0 (render) → FUN_0602F0E8 (render) → FUN_0600DE54 (RACE UPDATE)
    - Post-loop: FUN_0600C302 (if car object exists)
    - Race end: countdown→0 or [0x0607EAD0] set → state 16
    - Tail call FUN_060078DC (frame timing/sync)
  - **State 16** (FUN_06009290): Post-countdown cleanup
    - Immediate transition to state 17
    - If car object exists: call FUN_060121A8 (cleanup A), else FUN_06012198 (cleanup B)
    - Sets [0x0605A016] = 4 (phase flag)
  - **State 17** (FUN_060092D0): Post-lap processing / results display
    - Start button → save resume=17, → state 18
    - Calls FUN_0600A33C (general update)
    - Countdown timer: decrement, when expired → reset sound, read finish position from car_obj[0x82], store at [0x06078638], → state 24 (post-race)
    - Abort flag (bit 0 of [0x0607EBF4]): clear bit, reset sound, call FUN_06018E70, → state 20
    - Sound: plays 0xAE1134FF when countdown==200 (with 40-frame cooldown timer at [0x06086054])
    - Mode 1 check [0x0605A1C4]==1 → state 28
    - Update pipeline: FUN_0600DE70, FUN_0600A914, FUN_0600BB94, FUN_060053AC (display), FUN_0601D9B0 (sound), FUN_0600BFFC
    - Tail call FUN_060078DC
  - **State 18** (FUN_060096DC): Time extension setup (SINGLE FRAME)
    - Calls FUN_06009FFC (time extension UI initialization)
    - Immediate transition to state 19
    - Saves difficulty: [0x06078654] → [0x06078652], clears current to 0
    - Clears frame counter [0x06078650] = 0
    - Displays "TIME EXTENSION" overlay via VDP (FUN_060284AE, FUN_060283E0)
    - Sets display flag bit 2, calls FUN_06026CE0
    - Plays transition sound 0xAE0004FF
  - **State 19** (FUN_06009788): Time extension active/input (COMPLEX)
    - Mode byte [0x0607864A] controls speed selection UI:
      - Up button (0x8000): speed++ (max 99) at [0x06078649]
      - Down button: speed-- (min 1)
      - Displays speed number + label text
    - Start button confirmation (debounced: frame_counter >= 20):
      - Plays 0xAE0004FF, displays overlay, restores saved state from [0x0607EACC]
      - Restores difficulty from [0x06078652] → [0x06078654]
      - If mode set: calls FUN_06018DDC(speed) for difficulty setup, clears mode
    - Secret input: A+B+C held simultaneously (mask 0x70):
      - Calls FUN_0600A1B8, sets bit 31 in display_flags
      - If init_flag set: [0x0607EBF4]=1, state=24, [0x0607ED8C]=2
      - If init_flag clear: [0x0605AD08]=1, state=14 (BACK TO TITLE!)
    - Normal frame: counter++ at [0x06078650], blink text every 16 frames
  - **State 20** (FUN_06009508): Abort processing
    - Checks abort flag bit 0 in [0x0607EBF4]: if set, clear it, self-loop state=20
    - Otherwise: frame_counter++ (if no race end), → state 29
    - Simplified pipeline: FUN_0600DFD0, FUN_0600BB94, FUN_060053AC, FUN_0600C218
  - **Key memory map for race states**:
    - 0x0605AD10: game state variable (32-state machine index)
    - 0x0607EACC: resume state (saved before time extension detour)
    - 0x0607EAAC: countdown timer (decremented each frame)
    - 0x0607EAD0: race end flag (non-zero = race over)
    - 0x0607EAD8: car object pointer
    - 0x0607EBF4: flags word (bit 0 = abort, bit 1 = ?)
    - 0x0607EBD0: frame counter (incremented while waiting)
    - 0x0607ED8C: init/phase flag (controls per-car setup)
    - 0x06078634: car count (how many cars per frame)
    - 0x06078638: race result / finish position
    - 0x06078649: speed byte (time extension speed selection, 1-99)
    - 0x0607864A: mode byte (controls time extension behavior)
    - 0x06078650: frame counter word (time extension frame count)
    - 0x06078652/54: saved/current difficulty
    - 0x0605B6D8: display flags (bit 2 = update, bit 30 = race active, bit 31 = special)
    - 0x0605A016: phase flag (set to 4 on cleanup)
    - 0x06059F44: results flag
  - Created asm/race_states.s with complete annotated state machine
