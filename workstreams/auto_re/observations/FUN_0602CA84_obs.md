---
function: FUN_0602CA84
address: 0x0602CA84
address_end: 0x0602CCEE
source_file: reimpl/src/FUN_0602CA84.s
explored: 2026-03-15
scenarios_tested: [race_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle (race) | 1 | Pipeline call 15 in FUN_0602EEB8 |

## Register Context at Entry

Breakpoint at 0x0602EF4C (dispatcher, just after call 15 returns):

| Register | Value | Notes |
|----------|-------|-------|
| R0 | 0x06078900 | Car pointer (player car[0]) |
| R14 | 0x06078900 | Car pointer (preserved) |
| R13 | 0x0602CA84 | Function address (just called) |
| PR | 0x0602EF46 | Return address in dispatcher |

## Key Finding: FUN_0602CA84 Writes car[+0xFC] (Accel Delta)

**The writer map entry for +0xFC with function_start=0x0602EF4C and PC=0x0602EF4E
is a profiler artifact.** The actual write occurs in the RTS delay slot of
FUN_0602CA84 (source line 327):

```asm
    lds.l @r15+, pr      ; restore PR
    rts                   ; return to dispatcher
    mov.l r3, @(r0, r4)  ; delay slot: car[+0xFC] = r3
```

Where r4 = 0xFC (loaded from DAT_0602ccba at source line 313/389-391). The
profiler recorded the POST-RTS PC (the return target in the dispatcher) rather
than the delay slot instruction's PC.

## Field Access (Static Analysis of Assembly)

### Reads

| Offset | Line | Notes |
|--------|------|-------|
| +0x100 | 10 | Negated, then multiplied by 0x03700000 and 0x02D00000 |
| +0x104 | 14 | Negated, then multiplied by same constants |
| +0x60 | 27 | Multiplied by -car[+0x104] |
| +0x64 | 30 | Multiplied by -car[+0x104] |
| +0x140 | 114/199 | Compared against accumulated force, triggers FUN_0602755C (clamp?) |
| +0x144 | 199 | Same role as +0x140 for second component |
| +0xEC | 57/99 | Surface property, compared against accumulated value |
| +0xF0 | 169 | Surface property |
| +0xF8 | 100 | Surface progress |
| +0x11C | 173 | Energy/force field |
| +0xF4 | 165 | Surface grip |
| +0x114 | 287 | Animation state |
| +0x108 | 285/379 | Physics value, multiplied in final accel computation |
| +0x10C | 288/335 | Physics value |
| +0xD8 | 339 | Gear state — selects between two force constants |
| +0x7C | 292 | Checked for gear state 4 or 5 |
| +0x250 | 371 | Drift counter — nonzero triggers drift mode |

### Writes

| Offset | Line | Notes |
|--------|------|-------|
| +0x148 | 54 | Accumulated force component (cross product of roll × track angles) |
| +0x108 | 124 | Clamped force value |
| +0x10C | 209 | Clamped force value (second component) |
| +0xFC | 327 | **Accel delta** — final output, written in RTS delay slot |
| +0x40 | 258,269 | Zeroed when +0x250 (drift) is active |
| +0x58 | 258,270 | Zeroed when +0x250 (drift) is active |
| +0x5C | 258,270 | Zeroed when +0x250 (drift) is active |
| +0x60 | 258,269 | Zeroed when +0x250 (drift) is active |
| +0x64 | 258,270 | Zeroed when +0x250 (drift) is active |
| +0x110 | 278 | Set to 0xFFFF0000 when +0x250 is active |
| +0x152 | 415 | Set to 0xA (10) when drift detected via sym_0602CCD0 |

## Accel Delta Computation Pipeline

The function computes accel delta (+0xFC) as a multi-stage fixed-point
force accumulation:

1. **Roll projection**: car[+0x100] × 0x03700000, car[+0x100] × 0x02D00000,
   car[+0x104] × 0x03700000, car[+0x104] × 0x02D00000. Cross-multiplied
   with car[+0x60] and car[+0x64] (track angles).

2. **Force accumulation**: Multiple intermediate values combined with
   add/sub, clamped via FUN_0602755C, stored in +0x108 and +0x10C.

3. **Surface modulation**: car[+0xEC], +0xF0, +0xF4, +0xF8, +0x11C
   factor into the computation (surface grip, normals).

4. **Final force**: `r3 = (car[+0x108] × r5 + car[+0x10C] × r9 - car[+0x114])
   × gear_constant >> 8`, written to car[+0xFC].

5. **Gear selection**: DAT_0602ccb8 = car[+0x7C] selects between two constants
   (0x140 or 0x100) based on gear state 4/5 vs other gears.

## Correction: car[+0x100] Is NOT Throttle Input

**car[+0x100] = sin(car[+0x24])** — computed by FUN_06027358, called from
sym_0602EFCC (pipeline call 12). Verified by breakpoint at 0x06027370:
R5 = 0x06078A00 (car[+0x100] address), called from PR=0x0602EFE0 (within
sym_0602EFCC). On flat track, car[+0x24] (roll) = 0, so sin(0) = 0, so
car[+0x100] = 0. The struct map hypothesis "throttle_input?" is wrong.

car[+0x104] = cos(car[+0x24]) — paired output from the same sin/cos call.

## Where Does the C Button Enter?

On flat track (+0x100 = 0, +0x104 = 0), the roll projection terms are zero.
The accel delta (+0xFC) still changes with C button (+70/frame). This means
the throttle signal enters through one of:

- **car[+0x108]** or **car[+0x10C]**: These are the intermediate force
  values that feed the final multiplication. They're both read AND written
  by this function — suggesting they accumulate frame over frame. One of
  their upstream writers (from a prior pipeline stage) likely carries the
  throttle signal.
- **car[+0x114]**: Subtracted in the final force computation. If this is
  a drag/resistance term, the C button might reduce it.

**Recommended next step**: Set watchpoint on car[+0x108] (0x06078A08) and
car[+0x10C] (0x06078A0C) to find which upstream pipeline stage writes the
throttle-dependent value. Compare values with C held vs idle.

## Other Observations

- FUN_0602CA84 is much larger than "collision impact" suggests (lines 7-327,
  ~440 instructions). It's the central force accumulator for the player
  physics pipeline, not just collision handling.
- The function has a drift detection sub-call (sym_0602CCD0) that checks
  car[+0x152] and car[+0x08] (speed index). If drift conditions are met,
  it sets car[+0x152] = 0xA (starts a 10-frame drift timer).
- When car[+0x250] (drift counter) is nonzero, the function zeros out
  multiple fields (+0x40, +0x58, +0x5C, +0x60, +0x64) and sets +0x110
  to 0xFFFF0000. This "resets" the force state during drift.

### Sample captures
Existing captures from cycle 1-2 apply. No new captures needed for this
function — the field analysis uses the same car struct data.
