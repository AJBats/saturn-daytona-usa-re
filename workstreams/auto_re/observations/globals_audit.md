---
function: N/A (globals audit)
explored: 2026-03-17
scenarios_tested: [source_analysis]
reachable: N/A
---

## Phase 5: Globals Region Audit

Scanned all physics source files (0x0600B-0x0603 range) for references to
global variables in the 0x0606-0x0608 address space.

### Core Physics Globals (0x0607E940-0x0607ED91)

37 globals referenced by physics code. Top references by count:

| Address | Refs | Known Role |
|---------|------|-----------|
| 0x0607E940 | 46 | Current car pointer (per-iteration) |
| 0x0607EAD8 | 43 | Unknown (43 refs — heavily used!) |
| 0x0607E944 | 41 | Player car pointer |
| 0x0607EAE0 | 18 | Optimization gate (skip proximity etc) |
| 0x0607EBCC | 18 | Unknown (18 refs) |
| 0x0607EA98 | 14 | Car count |
| 0x0607EBF4 | 14 | Unknown (14 refs) |
| 0x0607EA9C | 13 | Unknown (13 refs) |
| 0x0607EAB8 | 12 | Unknown (12 refs) |
| 0x0607EBC4 | 10 | Pipeline mode flag (bit 15 selects AI mode) |
| 0x0607EADC | 10 | Unknown (10 refs) |
| 0x0607EBC8 | 9 | Frame counter / VBlank counter |
| 0x0607ED8C | 8 | State flag (gates input handler paths) |
| 0x0607EBD0 | 6 | Speed/progress threshold (>0x258) |
| 0x0607EAC8 | 6 | Zeroed by dispatcher (sym_0607EAC8) |
| 0x0607EB88 | 5 | Surface property table pointer |
| 0x0607E948 | 5 | Car array base (car[1] = 0x06078B68) |
| 0x0607ED88 | 5 | Unknown |
| 0x0607EB8C | 4 | Unknown (rendering-related?) |
| 0x0607EAE4 | 4 | Unknown |
| 0x0607EAAC | 3 | Race countdown timer (decrements 1/physics frame) |
| 0x0607EABC | 3 | Unknown |
| 0x0607ED90 | 3 | Input handler state |
| 0x0607EB84 | 2 | Track segment table pointer |
| 0x0607EBDC | 2 | Car iteration index |

### Other Global Regions Referenced by Physics

548 additional globals across wider address ranges:

| Region | Count | Likely Purpose |
|--------|-------|---------------|
| 0x060635xx | 39 | Display/VDP state |
| 0x060786xx | 40 | Car struct header/metadata |
| 0x060788xx | 37 | Car struct init values |
| 0x06085Fxx | 27 | Unknown game state |
| 0x060860xx | 26 | Unknown game state |
| 0x06089Exx | 27 | Unknown game state |
| 0x06082Axx | 23 | Unknown (rendering?) |
| 0x060878xx | 17 | Unknown |
| 0x06063Exx | 18 | g_pad_state region + nearby |
| 0x06063Fxx | 17 | Input/controller state |
| 0x0606xxxx (other) | ~100 | Display, VDP2, rendering config |
| 0x0608xxxx (other) | ~200 | Car data, track data, AI state |

### Transplant Implications

For the physics box, the MINIMUM globals needed are the 37 in the
0x0607E940-0x0607ED91 range. These include car pointers, car count,
pipeline flags, and table pointers. The 548 others are mostly rendering
and display state that the CCE replacement would provide.

Key physics globals that MUST be transplanted or replicated:
1. sym_0607E940 (current car ptr) — set per iteration
2. sym_0607E944 (player car ptr) — set at init
3. sym_0607E948 (car array base) — set at init
4. sym_0607EA98 (car count) — set at init
5. sym_0607EBC4 (pipeline mode flag) — controls AI behavior
6. sym_0607EB84 (segment table ptr) — track geometry
7. sym_0607EB88 (surface table ptr) — track physics
8. sym_06063D98 (g_pad_state) — controller input
9. sym_06081888 (button mapping) — input config
10. sym_06078900 (car struct array) — the main data
