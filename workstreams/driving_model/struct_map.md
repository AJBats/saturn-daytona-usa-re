# Car Object Struct Field Map

Base: `0x06078900` (sym_06078900)
Stride: `0x268` (616 bytes per car)
Count: 40 entries (index 0 = player)
Current car pointer: `sym_0607E940` (updated by FUN_0600e0c0 each iteration)
Car count: `sym_0607EA98`

## Key Globals

Addresses are mechanical facts. Usage descriptions require empirical verification.

| Address | Name |
|---------|------|
| 0x0607E940 | sym_0607E940 |
| 0x0607E944 | sym_0607E944 |
| 0x0607EA98 | sym_0607EA98 |
| 0x0607EA9C | sym_0607EA9C |
| 0x0607EAD8 | sym_0607EAD8 |
| 0x0607EAE0 | sym_0607EAE0 |
| 0x0607EB84 | sym_0607EB84 |
| 0x0607EB88 | sym_0607EB88 |
| 0x0607EBC4 | sym_0607EBC4 |
| 0x0607EBD0 | sym_0607EBD0 |
| 0x0607EBDC | sym_0607EBDC |
| 0x0607EBE0 | sym_0607EBE0 |
| 0x06078680 | sym_06078680 |
| 0x06087804 | sym_06087804 |

## Empirically Confirmed Fields

Only fields with emulator evidence. Offset labels come from observations, not Ghidra.

| Offset | Evidence | Finding |
|--------|----------|---------|
| +0x0C | Watchpoint + HUD correlation | Speed magnitude. HUD mph = value / 1,467. Written by FUN_0602D814 (pc=0x0602D822) for player car. |
| +0x08 | Observed formula | Speed index: `fpmul(car[+0x0C], 0x480000)` — fixed-point multiply by 72 |
| +0xFC | Watchpoint with C button | Acceleration delta. C button shifts +70/update toward positive. Writer PC: 0x0602EF4E (player path). |

## Empirical Observations (2026-03-05)

### g_pad_state read-consume-clear pattern

`sym_06063D98` (g_pad_state) IS the pad state during racing — CONFIRMED with breakpoint
at FUN_06008318 mid-frame. A held = 0x0400 at +2, matching known button mapping.

**Critical**: The game CLEARS g_pad_state before frame end. Reading between frames always
returns zero. Must use breakpoints to read transient per-frame state. Persistent car struct
fields (speed, position, heading) are safe to read between frames.

### Save state + input injection verified

Save state `daytona_rebuilt.*.mc0` loads to race start (lap 1/8, pos 40/40, ~179 mph).
Input injection works immediately after load:
- LEFT held 60 frames: car steered onto grass, speed dropped to 6 mph
- A held 30 frames: speed barely dropped (262K → 258K vs idle 262K → 86K)

### Player car = index 0 (CONFIRMED)

Car 0 (base 0x06078900) IS the player car. Confirmed by:
1. Speed field +0x0C correlates perfectly with HUD speedometer (ratio ~1,467 stable)
2. Watchpoint on 0x0607890C: written by FUN_0602D814 (pc=0x0602D822), NOT the main
   physics loop. Player is processed separately from the AI car iteration loop.

The FUN_0600e0c0 loop (i=1..car_count) processes AI cars only. Player car 0 is
handled by a separate code path rooted at ~0x0602EF00.

### C button = throttle (CONFIRMED)

Watchpoint on car[+0xFC] (acceleration delta) at 0x060789FC:

| Frame delta | C held | Idle |
|-------------|--------|------|
| +3 | -468 → -394 (+74) | -468 → -469 (-1) |
| +6 | -394 → -325 (+69) | -469 → -474 (-5) |
| +9 | -325 → -256 (+69) | -474 → -481 (-7) |

C shifts the accel delta toward zero/positive by ~70 units/update. Without C, it drifts
more negative (engine braking). At rolling start speed (~179 mph) the car still
decelerates with C held because it's above the natural max speed for that throttle level.
Writer PC: 0x0602EF4E (in the player-specific physics path, not FUN_0600c4f8).

### Speed unit conversion (CONFIRMED)

Internal speed (+0x0C) → kph-ish (+0x08) → mph (HUD):
- `car[+0x08] = fpmul(car[+0x0C], 0x480000)` — 16.16 fixed-point multiply by 72
- HUD mph = car[+0x0C] / 1,467 (stable across 3 data points)
- 262,577 / 1,467 = 179 mph, 258,164 / 1,467 = 176 mph, 253,749 / 1,467 = 173 mph

### Initial car struct dump at race start

```
+0x00: 00 80 00 00
+0x04: 00 00 00 00
+0x08: 00 00 01 20
+0x0C: 00 04 01 B1  — speed: 262,577 (CONFIRMED via HUD)
+0x10: FF DC EB C7
+0x14: 00 00 00 00
+0x18: FF 7A A9 16
+0x1C: 00 00 00 00
+0x20: FF FF AA AB
+0x24: 00 00 00 00
+0x28: FF FF AA AB
+0x30: FF FF AA AB
+0x38: FF D9 73 40
+0x3C: FF 7C A9 77
+0x78: 00 00 00 38
+0x7C: 00 00 07 05
+0xB8: 00 00 00 00
+0x1E4: 00 00 00 05
+0x228: 00 00 00 00
```
