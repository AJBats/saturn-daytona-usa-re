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

### VBlank Wait Location

The VBlank wait is in the main loop chain BEFORE FUN_0600C010. The
cycle gap between physics frames (~1.44M cycles) includes:
- Physics computation: ~478K cycles (one frame)
- VBlank wait: ~958K cycles (two VBlanks of idle waiting)

The wait function is likely in 0x060072E4 or 0x0600305C (the early
main loop functions). Experiment B should identify the exact function.
