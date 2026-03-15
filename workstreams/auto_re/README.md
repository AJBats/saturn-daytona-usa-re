# auto_re — Autonomous Reverse Engineering Workstream

Automated claim-based testing of RE hypotheses against the emulator.
Focused on deep understanding of the Daytona USA ('95) driving model.

## Architecture: Three-Agent Pipeline

```
Mapper Agent                 Explorer Agent               Verifier Agent
(strategy + synthesis)       (debugger, free-form)        (claims + oracle only)

  Read struct map,           Read priority list,          Read observations
  observations, results      investigate with debugger    Write claim YAML
  Identify gaps ──────────>  Produce observations ─────>  Test against oracle
  Write priority list        Write sample captures        Record pass/fail
  Update struct map  <─────────────────────────────────── Results + questions
  Update journal
```

**Mapper** — sees the whole board. Maintains the struct map and investigation
journal. Reads all observations, claims, and results. Produces a prioritized
target list for the Explorer. Does static call-graph analysis to trace unknown
writers. Cannot use the debugger or oracle.

**Explorer** — uses the Mednafen debugger freely (breakpoints, watchpoints,
memory dumps, sampling). Works from the Mapper's priority list. Produces
structured observation reports with behavioral data.
Cannot write claims or run the oracle.

**Verifier** — reads observation reports and assembly. Writes claim YAML files
and tests them through the oracle test runner. Cannot use the debugger.

The Mapper keeps the effort focused on the driving model goal. The Explorer
does the runtime investigation. The Verifier confirms facts through the oracle.
Each agent's output feeds the others.

### Running the Pipeline

**Three-agent mode** (recommended)
```bash
# Terminal 1 — Mapper (runs first to set priorities)
cd <project_root>
# Tell Claude: "Read workstreams/auto_re/mapper_program.md and follow it."

# Terminal 2 — Explorer (works from Mapper's priority list)
cd <project_root>
# Tell Claude: "Read workstreams/auto_re/explorer_program.md and follow it."

# Terminal 3 — Verifier (after Explorer has produced observation files)
cd <project_root>
# Tell Claude: "Read workstreams/auto_re/verifier_program.md and follow it."
```

**Typical cycle**: Mapper sets priorities → Explorer investigates → Verifier
tests → Mapper integrates results and sets new priorities. Agents don't need
to run simultaneously — they communicate through files.

## File Layout

```
workstreams/auto_re/
  README.md                  ← you are here
  explorer_program.md        ← Explorer agent instructions
  verifier_program.md        ← Verifier agent instructions
  mapper_program.md          ← Mapper agent instructions
  claim_schema.md            ← vocabulary of test types + scenarios
  explorer_priorities.md     ← Mapper's priority list (Explorer reads this)
  claims/                    ← claim YAML files (Verifier writes these)
  observations/              ← observation reports (Explorer writes these)

workstreams/driving_model/
  struct_map.md              ← car struct knowledge (Mapper maintains)
  writer_map_car0.md         ← existing writer maps (starting knowledge)
  writer_map_comprehensive.md
  function_set.md            ← 572 racing-only functions from CDL
  boundary_mapping_plan.md   ← transplant boundary phases

build/save_states/
  README.md                  ← save state catalog with scenarios
  *.mc0                      ← emulator save states

build/samples/
  *.csv                      ← per-frame capture CSVs
```

## How It Works

1. **Observations** — raw data from the emulator about what a function does
   at runtime (call count, register state, memory writes, value changes).
2. **Claims** — structured YAML files that state testable predictions.
3. **Oracle** — test runner executes claims mechanically against Mednafen,
   reports pass/fail.
4. **Tier promotion** — 0 passed = Tier 0, 1 passed = Tier 1,
   3+ passed with 2+ types and 1 function-specific = Tier 2.

The oracle is read-only. Neither agent may modify it.

## Test Types (fixed vocabulary)

| Type | What it tests |
|------|---------------|
| `writes_to` | Function F writes to address A during scenario S |
| `call_count_per_frame` | Function F is called N±T times per frame |
| `value_changes_with_input` | Value at A increases/decreases with input I |
| `value_stable` | Value at A stays constant when idle |

Full definitions: `claim_schema.md`

## Existing Knowledge

This project already has substantial driving model RE work:
- **struct_map.md** — 3 empirically confirmed fields (+0x0C speed, +0x08 speed index, +0xFC accel delta)
- **writer_map_car0.md** — 81 offsets with writer PCs (scripted 60-frame capture)
- **writer_map_comprehensive.md** — 95 offsets, 62K writes (human-driven capture)
- **globals_writer_map.md** — 21 globals region writers
- **function_set.md** — 572 racing-only functions from CDL
- **boundary_mapping_plan.md** — Phase A complete, Phase B in progress

The auto-RE pipeline builds on this foundation — adding behavioral
classification (per-frame sampling), oracle confirmation, and systematic
coverage the manual workflow couldn't achieve.
