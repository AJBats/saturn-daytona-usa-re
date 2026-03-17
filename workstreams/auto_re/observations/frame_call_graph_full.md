---
function: Full frame call graph
address: N/A
explored: 2026-03-16
scenarios_tested: [straight_throttle_1_frame]
reachable: N/A
---

## Phase 1: Frame Call Graph — Complete Function Inventory

PC trace captured from usa_tt_straight.mc0, frame 1→2, C held.
241,901 PCs recorded. 843 unique function entries identified.

### Function Classification Summary

| Category | Functions | PCs | % Frame |
|----------|----------|-----|---------|
| PLAYER_PIPELINE (0x0602C-0x06030) | 137 | 1,896 | 0.8% |
| SHARED_PHYSICS (0x0600B-0x0600E) | 135 | 17,174 | 7.1% |
| MATH_UTILITY (0x06026-0x06028) | 103 | 38,570 | 16.0% |
| RENDERING_VDP (0x06029-0x0603F) | 234 | 140,054 | 57.9% |
| FRAME_LOOP (0x06000-0x0600A) | 156 | 21,630 | 8.9% |
| MISC_GAME (0x0601x-0x06025) | 78 | 22,577 | 9.3% |
| **TOTAL** | **843** | **241,901** | **100%** |

### Physics Box (transplant candidates)

**PLAYER_PIPELINE: 137 functions**

All in the 0x0602Cxxx-0x06030xxx range. These are the 18 pipeline calls
and their sub-functions. Key entry points already documented in
FUN_0602EEB8_obs.md and individual pipeline call observations.

Notable sub-function addresses (not previously observed as separate entries):
- 0x0602C6A0, 0x0602C7B8 — within FUN_0602C690 (collision magnitude)
- 0x0602CCEE — FUN_0602CCEC (traction model)
- 0x0602D592, 0x0602D6AE — within FUN_0602D43C (steering/collision)
- 0x0602F608-0x0602F71E — within FUN_0602F5B6 (surface writer)
- 0x0602F880-0x0602F99E — within sym_0602FDA4 (input handler)
- 0x0603053E, 0x06030726, 0x06030A08, 0x06030EE2 — late pipeline functions

**SHARED_PHYSICS: 135 functions**

In 0x0600Bxxx-0x0600Exxx. Includes:
- FUN_0600B6A0/B914 — car rendering/update loops
- FUN_0600C010+ — racing orchestrator and sub-calls
- FUN_0600CD42+ — track segment system (10+ sub-functions)
- FUN_0600D31E+ — track data management (20+ sub-functions)
- FUN_0600DF22+ — player physics caller chain
- FUN_0600E0C2 — AI car iteration loop
- FUN_0600E4F4-0x0600E67C — heading/state save chain (15+ entries)
- FUN_0600EA1A, 0x0600EA74 — late shared functions

**MATH_UTILITY: 103 functions**

In 0x06026xxx-0x06028xxx. Trig, atan2, fixed-point math, memory copy.
Called by both physics and rendering. ALL must be in the transplant.

Key groups:
- 0x06026CEE-0x06026F48: matrix/rotation operations (16 entries)
- 0x06027346-0x06027466: trig lookups (sin, cos, atan2) — 10 entries
- 0x06027554-0x060276CE: fixed-point arithmetic — 3 entries
- 0x060279A8-0x06027CE4: 3D transform chain — 40+ entries (heavy!)
- 0x06027D44-0x06028502: orientation/matrix operations — 20 entries

**FRAME_LOOP: 156 functions**

In 0x06000xxx-0x0600Axxx. Includes input polling, VDP sync, frame
management. Key addresses:
- 0x060007C2 — tight loop function (called 335×/frame in cycle 1)
- 0x0600305E — main loop entry
- 0x0600519A-0x0600543A — Y-axis/height computation (20+ entries)
- 0x06005AE4-0x06005DD6 — surface/terrain processing chain
- 0x06005ECE-0x060061BA — 3D world coordinate chain (20+ entries)
- 0x06006782-0x06006A58 — VDP1/sprite processing (15+ entries)
- 0x06007E0A-0x060081F6 — polygon submission chain (15+ entries)
- 0x060092D2-0x0600945C — per-frame game loop (8 entries)
- 0x0600A33E-0x0600AA6C — HUD/display update

### Transplant Boundary Analysis

For the CCE transplant, the physics box must include:
1. **PLAYER_PIPELINE** (137 functions) — the core physics
2. **SHARED_PHYSICS** (135 functions) — track segments, AI loop, heading
3. **MATH_UTILITY** (103 functions) — ALL of these (shared dependency)

That's **375 functions** minimum. The FRAME_LOOP and RENDERING categories
can be replaced by CCE equivalents.

### MISC_GAME: 78 functions (needs triage)

In 0x0601xxxx-0x0602xxxx. Includes:
- 0x06017816-0x06017B50 — unknown game system (20 entries)
- 0x0601BDEE-0x0601E286 — unknown (15 entries)
- 0x06020E76-0x06023016 — HUD/display math (20 entries)
- 0x06022142-0x06022B4A — VDP2/background layer (15 entries)

These need individual classification — some may be physics-adjacent
(e.g., HUD reads speed for display) while others are pure rendering.
