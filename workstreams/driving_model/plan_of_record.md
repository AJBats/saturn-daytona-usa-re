# Plan: Systematic Driving Model Mapping

## Context

We need "perfect understanding" of the Daytona USA driving model to transplant gameplay code to Daytona USA CCE. All ~1,025 function names in `reimpl/src/` are LLM-generated guesses. We recently adopted a soft naming convention: revert misleading names to `FUN_*` + add `/* THEORY: ... */` comments with only empirical observations.

The driving model is the core target — physics, steering, collision, AI, track interaction. From Ghidra call graph analysis, this is approximately **25-30 core functions** plus **20-30 supporting math/track functions**.

## Ghidra-Confirmed Call Tree (ground truth)

```
FUN_0600e0c0 — car iteration loop (i=1..car_count, skips player at 0)
  ├─ if (flags == 0): FUN_0600e71a — PLAYER physics pipeline
  │    ├─ FUN_0600d266 — empty (NOP function)
  │    ├─ FUN_0600c4f8 — calls fpmul (06027552)
  │    ├─ FUN_0600c5d6 — CORE: steering/forces/collision dispatch
  │    │    ├─ FUN_0600cd40 — track position query
  │    │    ├─ FUN_0600ca96 — friction/drag
  │    │    ├─ FUN_0600cf58 — collision dispatch
  │    │    ├─ FUN_0600cc38 — force application
  │    │    ├─ FUN_0600c8cc — speed calc
  │    │    ├─ FUN_0600c928 — heading correction
  │    │    ├─ FUN_0600c7d4 — heading/speed damping
  │    │    ├─ FUN_06006838 — atan2
  │    │    ├─ FUN_06027ede — vector rotation
  │    │    └─ FUN_06027358 — sin/cos application
  │    ├─ FUN_0600ceba — track segment advance
  │    ├─ FUN_06008318 — calls FUN_06034f78
  │    └─ FUN_06008640 — calls 060086c0, 06008730
  │
  └─ else: FUN_0600e906 — AI physics pipeline
       ├─ FUN_0600d266 — empty (shared)
       ├─ FUN_06027552 — fpmul (shared)
       ├─ FUN_0600c74e — AI core (equivalent of c5d6)
       │    ├─ FUN_0600c970 — AI-specific steering
       │    ├─ FUN_0600cd40, 06006838, 06027ede — shared
       │    ├─ FUN_0600c928, 0600ca96, 0600c8cc, 0600c7d4 — shared
       │    (no collision dispatch cf58, no force application cc38)
       └─ FUN_0600ceba — track segment advance (shared)
```

Velocity integration at end of both pipelines: `position = velocity * scale + old_position`

## Methodology

### Verification Tiers

| Tier | Meaning | Commit? |
|------|---------|---------|
| **THEORY** | Static analysis only (Ghidra + code reading). Hypothesis. | Yes, as comment |
| **OBSERVED** | One empirical observation supports the theory | Yes, as comment |
| **VERIFIED** | 2+ independent observations, none contradicting | Yes, rename function |

Functions only get renamed from `FUN_*` when they reach **VERIFIED**. THEORY/OBSERVED stay as comments on `FUN_*` files.

### Verification Loop (per function)

1. **READ**: Ghidra decompilation — what does it access? Car struct offsets? Globals?
2. **PREDICT**: Make a testable prediction based on the theory
3. **TEST**: Run experiment (breakpoint, watchpoint, NOP, call-trace diff)
4. **EVALUATE**: Did observation match prediction? If NO → stop, investigate
5. **CONVERGE**: After 2+ agreeing observations → VERIFIED, propose name

### Tools Available

- **Ghidra MCP**: Decompilation, call graphs, xrefs, data types (connected to Daytona)
- **RE_TESTS framework**: `make RE_TESTS=1 MODS=1 disc` for experimental modifications
- **Interactive debugger**: `tools/debugger_utils.py` — breakpoints, watchpoints, step-through
- **Call-trace differential**: `frame_calls` / `frame_calls_diff` for input-responsive function discovery
- **Boot test**: `tools/test_boot_auto.py`, `tools/test_race_screenshot.py`

## Phases

### Phase 1: Car Struct Field Map (first priority)

The car object struct (base `0x06078900`, stride `0x268`, 40 cars) is THE central data structure. Every physics function reads/writes it. Understanding the struct fields unlocks understanding of every function that uses them.

**Method**:
1. Use Ghidra to decompile `FUN_0600ec78` (car_physics_init) — see which offsets get initialized and to what values
2. Cross-reference offsets used in FUN_0600e71a and FUN_0600c5d6 decompilation
3. Use watchpoints at key offsets during racing to see which functions write them
4. Create `workstreams/driving_model/struct_map.md` documenting offset/size/name/evidence

**Key offsets to investigate first** (from Ghidra decompilation of FUN_0600c5d6):
- `+0x0C`, `+0x10`, `+0x18`, `+0x20`, `+0x28` — used in steering/heading math
- `+0x1EC`, `+0x1F4`, `+0x228` — velocity integration formula
- `+0x01` — flags byte (bit 7 triggers extra processing in FUN_0600e0c0)

**Deliverable**: Struct field map with 20+ identified fields.

### Phase 2: Core Physics Pipeline (12 functions)

Attack the player physics pipeline top-down, verifying each function's purpose:

| Priority | Address | Current File | Ghidra Callees | Investigation |
|----------|---------|-------------|----------------|---------------|
| 1 | 0600d266 | heading_correct.s | (none — NOP) | Trivial: breakpoint + step confirms empty |
| 2 | 0600e71a | FUN_0600E71A.s | 6 callees | Orchestrator: call-trace during racing |
| 3 | 0600c5d6 | FUN_0600C5D6.s | 11 callees | Core forces: watchpoint on car struct fields |
| 4 | 0600c4f8 | FUN_0600C4F8.s | fpmul | Accel-related: NOP test + watchpoint |
| 5 | 0600cd40 | FUN_0600CD40.s | FUN_0602744c | Track query: watchpoint on track data |
| 6 | 0600ca96 | (in ai_orchestrator?) | (leaf) | Friction: NOP → car slides? |
| 7 | 0600cf58 | collision_dispatch.s | 4 callees | Collision: NOP → no wall bounce? |
| 8 | 0600cc38 | (unnamed) | (leaf) | Force application: watchpoint |
| 9 | 0600c8cc | FUN_0600C8CC.s | (leaf) | Speed calc: watchpoint on speed field |
| 10 | 0600c928 | heading_correct.s | (leaf) | Heading: NOP → car drifts straight? |
| 11 | 0600c7d4 | heading_speed_damping.s | (leaf) | Damping: NOP → oscillation? |
| 12 | 0600ceba | FUN_0600CEBA.s | FUN_06035228 | Track advance: breakpoint at lap cross |

**Method**: For each function, read Ghidra decompilation, form theory, predict NOP/watchpoint behavior, test in emulator. ~3-5 functions per session.

### Phase 3: AI Pipeline Delta

Compare AI path (FUN_0600e906 → FUN_0600c74e) against verified player path. Focus on differences:

- FUN_0600c970 — AI-specific (no player equivalent). What does it do?
- FUN_0600c74e vs FUN_0600c5d6 — shared callees but missing cf58 (collision) and cc38 (force). Why?
- AI steering input source (waypoints? track spline?)

### Phase 4: Surrounding Systems

Once core physics is mapped: collision response (FUN_060316c4), track geometry, camera, car iteration/dispatch. These are less critical for transplanting but needed for completeness.

## Workstream Organization

```
workstreams/driving_model/
  driving_model.md           — scoreboard + status tracking
  struct_map.md              — car object struct field documentation
  call_tree.md               — verified call tree (from Ghidra, annotated)
```

Investigation scripts stay in the workstream directory per `workstream-tools.md` rule.

## Concrete First Steps (Session 1)

1. Create `workstreams/driving_model/` directory structure
2. Use Ghidra MCP to decompile `FUN_0600ec78` (car_physics_init) — extract struct initialization offsets
3. Use Ghidra MCP to decompile FUN_0600e71a's callees — map car struct offset usage
4. Create initial `struct_map.md` with offsets found in decompilation
5. Verify FUN_0600d266 is truly empty (trivial — 1 breakpoint)
6. Begin FUN_0600e71a investigation: call-trace during racing to confirm it runs every frame per car

## Verification

- Each verified function gets a commit with THEORY/OBSERVED/VERIFIED comment
- Build validation (`python tools/validate_build.py`) after any file rename
- No function renamed without 2+ independent empirical observations
- Progress tracked in `workstreams/driving_model/driving_model.md` scoreboard
