# Driving Model Transplant Proposal: Manual Rewrite with Debug Draw

**Date**: 2026-03-17
**Status**: PROPOSAL — awaiting CCE engineer review
**Authors**: Human + DUSA Engineer

## Goal

Transplant the Daytona USA '95 driving model into Daytona CCE. The '95
model has better physics feel; CCE has better graphics. Combine them.

## Approach: Bottom-Up Manual Rewrite

Instead of copying DUSA binary code into CCE (which requires DUSA's build
infrastructure to match CCE's maturity), manually rewrite each physics
function into CCE's codebase using DUSA source as line-by-line reference.

### Why not direct code copy?

- DUSA's free build can't safely resize functions (hidden hardcoded BSR/BRA
  pairs break when code shifts — proved by 30fps mod crash)
- TU consolidation incomplete (560 functions still in one raw data blob)
- Fog clearing not done (many functions still as .byte pairs)
- CCE already has full code resizability (134 commits of clear-fog-work)

### Why manual rewrite works

- DUSA driving model functions ARE readable (L3 mnemonics in src/)
- The Mapper documented every function, field, pipeline stage, and data
  flow chain — this is the translation guide
- Each function is 50-200 lines of SH-2 assembly — small enough to
  hand-translate accurately
- The 1% that changes: coordinate space, struct offsets, frame rate
  constants, CCE integration points

## Incremental Build-Up with Debug Draw

The key insight: build the physics model one function at a time in CCE,
with a debug draw overlay showing the DUSA-physics car on the CCE track.

### Step-by-step validation

| Step | What to add | How to validate |
|------|-------------|-----------------|
| 1 | Car struct + position writer | Feed hardcoded speed. Debug car moves along track? |
| 2 | Speed writer (sym_0602D814) | Feed hardcoded accel_delta. Speed accumulates? |
| 3 | Force accumulator (FUN_0602CA84) | Hook up C button. Throttle works? |
| 4 | Traction model (FUN_0602CCEC) | Car reaches correct top speed? |
| 5 | Steering (FUN_0602EFF0 + heading chain) | Car turns? |
| 6 | Surface/track data (FUN_0602F5B6) | Car slows on grass? |
| 7 | Input handler (sym_0602FDA4) | Full controller: throttle, brake, steer, gear |
| 8 | AI pipeline (FUN_0600E0C0) | AI cars drive with DUSA physics? |

Each step is independently testable. If step 3 breaks, the problem is
in the force accumulator — not downstream. The debug draw car is the
oracle at every stage.

### Debug draw concept

CCE renders its normal race. Overlaid: a wireframe or flat-shaded car
driven entirely by DUSA physics code. Both cars start at the same
position. Visual divergence immediately reveals:
- Coordinate space errors (car flies off into space)
- Speed scaling errors (DUSA car much faster/slower)
- Heading errors (car turns wrong direction)
- Surface errors (car doesn't slow on grass)

## What we bring from DUSA

### Reference materials (already complete)

- `workstreams/driving_model/struct_map.md` — 95+ car struct fields mapped
- `workstreams/driving_model/data_flow_chains.md` — complete pipeline
  from button press to position update, all gaps closed
- `workstreams/driving_model/player_pipeline.md` — 18 pipeline calls documented
- `workstreams/auto_re/explorer_priorities.md` — transplant manifest
  (functions, data tables, globals, shared math)
- 6 NOP tests empirically confirming function roles
- Per-frame CSV captures for behavioral validation

### Source code reference

- `reimpl/src/FUN_0602*.s` — all player physics functions in L3 mnemonics
- `reimpl/src/FUN_0600C*.s` — shared physics (AI + collision)
- `ghidra_reference/*.c` — Ghidra C decompilations for complex functions
- Pool constants visible in each .s file (data table addresses, magic numbers)

### Data tables to transplant

From `explorer_priorities.md` Phase 4 manifest:
- Gear ratio tables (sym_060477BC, 32 bytes)
- Traction force tables (sym_0602E938, 128 bytes)
- Drift scaling (sym_0602E8B8, 64 bytes)
- Button mapping (sym_06081888, 12 bytes)
- Track surface table (disc-loaded, 12,544 bytes)
- Track segment table (disc-loaded, 588 bytes)
- Sin/cos lookup tables (referenced by FUN_06027344)
- ~15 more tables documented in the manifest

## Known Challenges

### Coordinate space

DUSA and CCE may use different world scales. The track data tables are
course-specific and disc-loaded. CCE's Three Seven Speedway data may
use different units or coordinate orientation. The debug draw will
reveal this immediately.

### Frame rate

DUSA runs at 20fps. CCE runs at 30fps. Every per-frame constant needs
x2/3 scaling. The 30fps mod work documented all 17 constants and their
scaling rules (see `data_flow_chains.md` Per-Frame Constants section).
Key lesson: position integration DOES need scaling (velocity is
computed from raw speed, not cascading delta). Throttle/brake ramp
should NOT be scaled (player intent is frame-rate independent).

### Struct layout differences

DUSA car struct: base 0x06078900, stride 0x268 (616 bytes), 40 cars.
CCE car struct: TBD — need CCE engineer to confirm layout.
Field offsets may differ. Each field reference in the transplanted code
needs mapping from DUSA offset to CCE offset.

### Surface/track data format

DUSA track data: 784-entry waypoint table (16 bytes each) + 147 segment
milestones. Zigzag edge-pair format. Fields 3/4 correlate with
curvature. CCE track data: TBD — may differ in format, density, or
coordinate system.

## Questions for CCE Engineer

1. Is the debug draw overlay feasible in CCE? Where in the rendering
   pipeline would you hook it?
2. What's CCE's car struct layout? Same 616 bytes, or different?
3. Does CCE use the same track data format as DUSA?
4. Where should the transplanted physics code live in CCE's build
   system? New module, or integrated into existing race.bin?
5. What's the best way to handle the 20fps→30fps constant scaling?
   Apply at transplant time, or keep DUSA values and scale at runtime?
6. Any concerns about the incremental approach? Anything that would
   force an all-or-nothing integration?

## Decision

Pending CCE engineer review. If approved, start with Step 1 (car struct
+ position writer + debug draw) as a proof of concept.
