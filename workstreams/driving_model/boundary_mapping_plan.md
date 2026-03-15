# Driving Model Boundary Mapping Plan

**Goal**: Map the Daytona USA driving model boundaries and API surfaces
for transplanting gameplay code to Daytona USA CCE.

"Draw the box first (what goes in, what comes out), then explore inside it."

## Phase A: Code coverage (CDL) — DONE

| # | Task | Status | Notes |
|---|------|--------|-------|
| A1 | Rolling start baseline CDL | Done | 300 frames idle |
| A2 | Steering + crash CDL | Done | ~1,746 frames |
| A3 | Auto transmission CDL | Done | ~2,194 frames |
| A4 | Manual transmission CDL | Done | ~1,732 frames |
| A5 | Merge into function_set.md | Done | 572 racing-only, 30 shared |

Artifact: `function_set.md`
Tool: `merge_cdl.py`, `cdl_boundary.py`

---

## Phase B: Data flow boundaries (mem_profile) — 50% done

Maps who WRITES and who READS the driving model's data. Defines the
edges of the box: what flows in, what flows out.

| # | Task | Status | Artifact |
|---|------|--------|----------|
| B1 | Car[0] writer map (scripted 60f: idle/throttle/steer) | Done | `writer_map_car0.md` — 81 offsets |
| B2 | Car[0]+Car[1] writer map (human-driven: collision, braking, grass, cones) | Done | `writer_map_comprehensive.md` — 95 offsets, 62K writes |
| B3 | Globals region writer map (0x0607E940-0x0607EBE0) | Done | `globals_writer_map.md` — 21 globals |
| B4 | Boundary consumer map — who READS car struct fields | Static draft | `output_boundary.md` — 25 pure consumers classified, 15-field rendering API identified. Needs CDL cross-validation. |
| B5 | Rendering output boundary — which PCs write VDP1 commands | Not started | mem_profile on VDP1 command table |
| B6 | Track data inputs — which read-only tables feed the model | Not started | Ghidra xrefs on known table addresses |

### B4: Boundary consumers

Find all functions that READ the car struct. These are the consumers of
driving model output — rendering, HUD, sound, AI decision-making.

Method: Ghidra xrefs on `sym_06078900` (car array base), `sym_0607E940`
(current car pointer), and key struct offsets (+0x0C speed, +0x10 position,
+0x18 position, +0x20 heading). Cross-reference with CDL function_set to
classify as RACING_ONLY vs SHARED.

Deliverable: consumer map — which functions read which car fields, classified
as physics-writer vs rendering-reader vs HUD-reader vs sound-reader.

### B5: Rendering output boundary

Find where driving model data becomes VDP1 draw commands. This is the
physics-to-rendering handoff.

Method: mem_profile the VDP1 command table region during racing. Compare
writer PCs against the car struct writer map — functions that read car
fields AND write VDP1 are the boundary.

We already know FUN_0600B6A0 iterates cars for rendering (from Goal 5
of the car flip benchmark). B5 confirms this empirically and checks for
other rendering entry points.

### B6: Track data inputs

Map the read-only data tables that feed the driving model. These must be
included in the transplant or replaced with CCE equivalents.

Known table references (from static_hypotheses.md):
- 0x060453CC — gear shift timing table
- 0x060453B4/0x060453C4 — speed-indexed collision tables
- 0x060454CC, 0x060477EC — acceleration lookup tables
- sym_0607EB84 — track segment table pointer
- sym_0607EB88 — surface property table pointer

Method: Ghidra xrefs on these addresses to find all readers. Identify
which are inside vs outside the driving model boundary.

---

## Phase C: Call graph boundary (call trace) — 40% done

Maps the function call structure. Who calls whom, and in what order.

| # | Task | Status | Artifact |
|---|------|--------|----------|
| C1 | AI pipeline call tree (FUN_0600e71a, FUN_0600e906) | Done | `call_tree.md` |
| C2 | Player pipeline call tree (~0x0602EF00 -> FUN_0602D814) | **Done** | `player_pipeline.md` — 18-call sequence validated via pc_trace_frame. Conditional paths observed. |
| C3 | Frame orchestration — FUN_0600c010 call order per frame | **Done** | `FUN_0600C010_obs.md` — Player physics first (3.4%), AI loop, rendering last (93.1%). 217K PCs analyzed. |
| C4 | Primary vs secondary SH-2 work split during racing | Not started | Dual-CPU call trace |

### C2: Player pipeline

The #1 open question from `driving_model.md`. Car 0 (player) has its own
physics path separate from the AI car loop. We know the entry point
(~0x0602EF00) and one writer (0x0602D822 writes speed). Everything else
is unmapped.

Method: Watchpoint break on car[0] fields (+0x0C, +0x10, +0x20, +0xFC)
captures writer PC + caller (PR register). Ghidra xrefs on the entry
point give the static call tree. Reconcile into player_pipeline.md.

This is the code we're actually transplanting — the player driving model.

### C3: Frame orchestration

FUN_0600c010 is the per-frame racing entry point. What order does it call
things? Physics before rendering? Primary before secondary SH-2?

Method: Call trace for 1 full racing frame. Annotate the call sequence
with phase labels (physics, rendering, HUD, sound).

### C4: CPU work split

Which driving model functions run on the primary SH-2 vs secondary SH-2?
We know car select rendering is split (Goal 4), but racing may differ.

Method: Dual-CPU call trace or insn_trace with CPU tags.

---

## Phase D: Guided theory work (NOP tests, watchpoints) — 15% done

Test specific functions empirically. Each NOP test removes one function
and observes what breaks, confirming its role.

| # | Task | Status | Target |
|---|------|--------|--------|
| D1 | NOP FUN_0600C4F8 (speed/accel) | Done (#26) | AI cars stop accelerating |
| D2 | NOP FUN_0600CF58 (collision) | Pending (#27) | No wall/car collisions |
| D3 | NOP FUN_0600CA96 (friction/drag) | Pending (#28) | No friction/drag |
| D4 | NOP FUN_0600C8CC (steering calc) | Pending (#29) | No steering correction |
| D5 | NOP FUN_0600C928 (heading correction) | Pending (#30) | No heading correction |
| D6 | NOP FUN_0600CC38 (force application) | Pending (#31) | No force application |
| D7 | NOP FUN_0600CEBA (track segment advance) | Pending (#32) | Lap counter breaks |
| D8 | Field semantics — name the 92 unknown car struct offsets | Not started | Requires B4, C2 |
| D9 | Watchpoint break on player car fields during inputs | Not started | Requires C2 |

D2-D7 test the AI pipeline functions (already designed).
D8-D9 target the player pipeline (blocked until C2 maps it).

---

## Phase E: Transplant specification — READY TO START (partially)

The final deliverable. Draws the box and specifies everything needed to
move the driving model from Daytona USA to Daytona USA CCE.

| # | Task | Status | Notes |
|---|------|--------|-------|
| E1 | Function list: everything inside the driving model | **Ready** | 18 pipeline calls + sub-functions, all Tier 2. 21 functions total. |
| E2 | Input API: controller, track data, game mode flags | **Partial** | Buttons mapped (throttle/brake/gear). **Steering input unknown.** Track tables identified but format undocumented. |
| E3 | Output API: car struct fields read by rendering/HUD/sound | **Ready** | 15-field rendering API in output_boundary.md. |
| E4 | Shared infrastructure: math, memory, sync | **Ready** | Frame order known. Math functions (atan2, sin/cos, fixed-mul) identified. |
| E5 | CCE compatibility analysis | Blocked on E2 | Need steering + track data format to compare with CCE. |

**NO REMAINING BLOCKERS.** All 6 racing inputs traced to car struct fields
(2026-03-15). Steering enters via sym_0602FDA4 sub-call → +0xAC.
Transplant spec can now be written in full.

Deliverable: `transplant_spec.md`

---

## Execution Order

```
B4 (boundary consumers) — who reads car struct
  |
B5 (rendering boundary) — physics-to-VDP1 handoff
  |
B6 (track data inputs) — what feeds the model
  |
C2 (player pipeline) — the code we're transplanting
  |
C3 (frame orchestration) — call order within a frame
  |
D2-D7 (NOP tests) — confirm AI pipeline function roles
  |
C4 (CPU work split) — primary vs secondary during racing
  |
D8-D9 (field semantics + player watchpoints) — detail work
  |
E1-E5 (transplant spec) — final deliverable
```

B4 is next. It completes the "outside of the box" mapping before we
dive into internals.
