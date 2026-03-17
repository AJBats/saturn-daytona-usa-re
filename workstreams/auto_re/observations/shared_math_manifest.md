---
function: N/A (shared math inventory)
explored: 2026-03-17
scenarios_tested: [source_analysis]
reachable: N/A
---

## Phase 6: Shared Math Function Inventory

57 shared math/utility functions referenced by physics source files.
All in the 0x06026xxx-0x06028xxx range.

### Function List

| Address | Known Name | Category |
|---------|-----------|----------|
| 0x06026110 | | Matrix/rotation |
| 0x060262C0 | | Matrix/rotation |
| 0x06026362 | | Matrix/rotation |
| 0x060263EC | | Matrix/rotation |
| 0x0602648E | | Matrix/rotation |
| 0x06026518 | | Matrix/rotation |
| 0x06026590 | | Matrix/rotation |
| 0x060266CC | | Matrix/rotation |
| 0x060268B0 | | Matrix/rotation |
| 0x06026CA4 | | Matrix/rotation |
| 0x06026E60 | | VDP/3D math |
| 0x06026E94 | | VDP/3D math |
| 0x06026EDE | | VDP/3D math |
| 0x06026F2A | | VDP/3D math |
| 0x06026FFC | | VDP/3D math |
| 0x06027124 | | VDP/3D math |
| 0x06027158 | | VDP/3D math |
| 0x060271A2 | | VDP/3D math |
| 0x060271EE | | VDP/3D math |
| 0x060272C0 | | VDP/3D math |
| 0x06027344 | FUN_06027344 | cos lookup |
| 0x06027348 | cos_lookup | cos table entry |
| 0x06027358 | FUN_06027358 | sin/cos pair |
| 0x06027378 | FUN_06027378 | inverse trig |
| 0x0602744C | FUN_0602744C | atan2 variant |
| 0x0602745C | | atan2 |
| 0x06027476 | | atan2 |
| 0x06027498 | | isqrt |
| 0x0602754C | | sign handling |
| 0x06027552 | FUN_06027552 | fixed-point multiply |
| 0x0602755C | FUN_0602755C | clamp/normalize |
| 0x06027574 | | FP math |
| 0x060275A4 | | FP math |
| 0x060275D8 | | FP math |
| 0x0602760C | | FP divide |
| 0x0602761E | | FP divide |
| 0x06027630 | | memcpy byte |
| 0x06027642 | | memcpy word |
| 0x0602766C | | memcpy long |
| 0x0602769C | | memory utility |
| 0x060276CC | | memory utility |
| 0x060279B0 | | 3D transform |
| 0x06027CA4 | | 3D transform |
| 0x06027EDE | | orientation matrix |
| 0x060282C0 | | matrix math |
| 0x06028306 | | matrix math |
| 0x0602834A | | matrix math |
| 0x06028368 | | matrix math |
| 0x06028384 | | matrix math |
| 0x06028398 | | matrix math |
| 0x0602843A | | rendering math |
| 0x060284BA | | rendering math |
| 0x06028580 | | rendering math |
| 0x06028598 | | rendering math |
| 0x060285E0 | | rendering math |
| 0x06028600 | | rendering math |
| 0x06028654 | | rendering math |

### Category Breakdown

| Category | Count | Address Range |
|----------|-------|--------------|
| Matrix/rotation | 10 | 0x06026110-0x06026CA4 |
| VDP/3D math | 10 | 0x06026E60-0x060272C0 |
| Trig (sin/cos/atan2) | 7 | 0x06027344-0x06027498 |
| Fixed-point arithmetic | 8 | 0x0602754C-0x0602761E |
| Memory copy | 3 | 0x06027630-0x0602766C |
| Memory utility | 2 | 0x0602769C-0x060276CC |
| 3D transform | 2 | 0x060279B0-0x06027CA4 |
| Orientation/matrix | 7 | 0x06027EDE-0x06028398 |
| Rendering math | 8 | 0x0602843A-0x06028654 |

### Transplant Notes

ALL 57 functions must be included in the physics box — they're called
by both physics and rendering code. The trig functions (0x06027344-0x06027498)
likely read from sin/cos lookup tables embedded in the code section. These
tables are part of the function bodies, not separate data sections.

The rendering math functions (0x0602843A+) may only be needed if the
transplant includes rendering. For physics-only transplant, the first
~40 functions are sufficient.
