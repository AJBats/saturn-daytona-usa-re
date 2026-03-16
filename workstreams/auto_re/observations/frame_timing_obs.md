---
function: FUN_0600C010 (frame timing measurement)
address: 0x0600C010
explored: 2026-03-16
scenarios_tested: [idle]
reachable: true
---

## Experiment A: DUSA Frame Rate Measurement

### Result: 20 fps (3 VBlanks per physics frame)

Breakpoint at FUN_0600C010 (racing orchestrator), measured cycle counter
at consecutive hits. Double-hit artifact filtered (same frame, +3 cycles).

| Hit | Mednafen Frame | Cycle | Delta (cycles) | Delta (frames) |
|-----|---------------|-------|---------------|----------------|
| 1 | 1 | 948,703 | — | — |
| 2 | 4 | 2,384,871 | 1,436,168 | 3 |
| 3 | 7 | 3,820,768 | 1,435,897 | 3 |

### Calculations

- **Cycles per physics frame**: ~478,700 (1,436,000 / 3)
- **SH-2 clock**: 28.636 MHz
- **Frame interval**: 478,700 / 28,636,000 = **16.72 ms**
- **Frame rate**: 1 / 0.01672 = **59.8 fps Mednafen** (≈60 Hz NTSC VBlank)
- **Physics frames per VBlank**: 1 physics frame per 3 VBlanks
- **Physics frame rate**: 60 / 3 = **20 fps**

### Implications for CCE Transplant

CCE runs at 30 fps (60/2 VBlanks). Every per-frame constant in the DUSA
physics needs scaling by **2/3** (20→30 fps means each frame is 2/3 as long):

| Constant | DUSA (20fps) | CCE (30fps) | Ratio |
|----------|-------------|-------------|-------|
| Throttle ramp | +10/frame | +6.67 → +7 | ×0.667 |
| Brake ramp | +40/frame | +26.67 → +27 | ×0.667 |
| Traction decay | -1474/frame | -983 | ×0.667 |
| Heading correction | ±60/frame | ±40 | ×0.667 |
| Drag amount | idx × 64 | idx × 43 | ×0.667 |
| Timer decrements | -1/frame | -1/frame | same (but fewer frames) |
| Steering scale | ×255 | ×170 | ×0.667 |

### VBlank Wait Location (Experiment B — Partial)

The VBlank wait is in the SGL library (`slSynch` from SEGA_SGL.A).
The call stack addresses (0x06000310, 0x060072E4, 0x0600305C) are
boot-time return addresses on the stack, NOT per-frame loop functions
— breakpoints on them don't fire during racing.

The per-frame loop is at ~0x06009400, called from 0x060092F8. It contains
multiple `jsr @R3` calls from pool constants. Measured cycle delta from
loop entry (0x06009400) to FUN_0600C010 entry: **20,273 cycles** (~0.7ms).
This means virtually no setup before physics — the VBlank wait is at the
**END of the loop** (after physics + rendering complete), not the beginning.

**Cycle budget per physics frame**:
- Physics computation: ~478K cycles (33% of frame)
- VBlank wait: ~958K cycles (67% of frame — spinning for 2 VBlanks)
- Total: ~1.44M cycles = 3 VBlanks at 28.636 MHz

### sym_0607EAAC Is a Countdown Timer

sym_0607EAAC (struct map: "frame counter?") is a **countdown timer**,
not a frame counter. Decrements by 1 per physics frame (every 3 VBlanks).
Observed: 634 → 512 (initial read was mid-frame) → 511 → 510.
Counts physics frames remaining until some event (likely lap/race timer).
