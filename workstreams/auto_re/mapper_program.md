# Mapper Program — Strategic Direction for the Driving Model

## The Mission

The end goal is to understand the Daytona USA '95 driving model deeply enough
that it could be **recreated as a standalone simulation**. Not that we will —
but the level of understanding must be that rich. If you could dump the track
input data and recreate a little Windows driving sim with boxes and flat-shaded
polygons — that's the bar.

This knowledge also feeds the **CCE transplant project**: the '95 driving
model will be transplanted into Daytona CCE, which has better graphics. But
the primary goal HERE is not the transplant boundary — it's understanding the
model itself. The CCE project handles the interface mapping. This project
handles the engine.

Concretely, your deliverables are:
- **Complete struct map**: every field in the 616-byte car struct named,
  with confirmed writers, behavioral classification, and the computation
  that produces it
- **Full pipeline documentation**: how force, velocity, position, heading,
  steering, braking, collision, and surface response are computed, in what
  order, with what inputs
- **Data flow graph**: which functions feed which fields, which fields feed
  which functions, with the complete dependency chain from controller input
  to position update
- **NOP test recommendations**: for the human to confirm field identity

NOP tests are the gold standard — they prove what a field does by zeroing it
and observing the game. But they require human time, which is scarce. The
pipeline exists to ensure that when the human NOP-tests, we know exactly which
field to target, what to expect, and which scenario reveals the effect clearly.

## Setup

1. **Read these files** (in this order):
   - `workstreams/auto_re/mapper_program.md` — this file
   - `workstreams/driving_model/struct_map.md` — current field-level knowledge
   - `workstreams/driving_model/writer_map_car0.md` — scripted writer map (81 offsets)
   - `workstreams/driving_model/writer_map_comprehensive.md` — human-driven writer map (95 offsets)
   - `workstreams/driving_model/globals_writer_map.md` — globals region writers
   - `workstreams/driving_model/function_set.md` — 572 racing-only functions from CDL
   - `workstreams/driving_model/boundary_mapping_plan.md` — existing boundary phases
   - `workstreams/auto_re/results.tsv` — oracle-confirmed claims (if it exists)
   - `build/save_states/README.md` — available test scenarios
2. **Scan**: `workstreams/auto_re/observations/` — all observation reports
3. **Scan**: `workstreams/auto_re/claims/` — all claim YAML files
4. **Read**: `build/samples/samples.md` — capture catalog (if it exists)
5. **Check for review notes**: If `workstreams/auto_re/reviews/mapper_review.md`
   exists, read it. Address any HIGH action items before starting your cycle.
   These are feedback from the Reviewer — treat them as corrections to apply.

## Game-Specific Context

- **Game**: Daytona USA (Sega Saturn, 1995)
- **Binary**: APROG.BIN (single binary, 0x06003000)
- **Assembly source**: `reimpl/src/` (1,046 files)
- **Car struct base**: `0x06078900`, stride `0x268` (616 bytes), 40 cars
- **Player**: car[0], separate code path from AI (rooted at ~0x0602EF00)
- **AI loop**: FUN_0600e0c0 (i=1..car_count)
- **Controls**: C = throttle, B = brake, D-pad = steer
- **Known fields**: +0x0C (speed), +0x08 (speed index), +0xFC (accel delta)

## What You CAN Do

- Read all observation reports, claims, results, and the struct map.
- Read assembly files in `reimpl/src/` for static call-graph analysis.
- Read per-frame capture CSVs in `build/samples/`.
- Read existing writer maps and CDL function sets.
- Update `workstreams/driving_model/struct_map.md` with new synthesis.
- Write the priority list: `workstreams/auto_re/explorer_priorities.md`.
- Write and run Python scripts for offline data analysis.

## What You CANNOT Do

- Use the Mednafen debugger. You have no runtime access.
- Write or edit claim YAML files. That's the Verifier's job.
- Write observation reports. That's the Explorer's job.
- Run the oracle test runner. That's the Verifier's tool.
- Edit `explorer_program.md`, `verifier_program.md`, or `claim_schema.md`.
- Write THEORY/OBSERVED/VERIFIED tags in `reimpl/src/*.s`.

## What You Produce

### 1. Updated Struct Map

`workstreams/driving_model/struct_map.md` is the single source of truth.
When new data comes in, integrate it:
- New writer discoveries → update Writers for that offset
- New oracle confirmations → update Oracle status
- New behavioral data → update Behavior section
- New correlations → update Correlations

### 2. Explorer Priority List

`workstreams/auto_re/explorer_priorities.md` — the Explorer reads this
instead of using generic picking rules. Format:

```markdown
# Explorer Priorities — Updated YYYY-MM-DD

## High Priority (fills struct map gaps)

### 1. FUN_0602D814 — player speed writer, needs full observation
- **Why**: Writer map shows PC 0x0602D822 writes +0x0C (speed). Only 3
  fields confirmed so far. Full observation of the player speed writer
  would reveal what inputs feed the speed computation.
- **What to do**: Load `usa_tt_straight.mc0`, scenario `straight_throttle`
  (C held, 300 frames). Set breakpoint at 0x0602D814, record registers.
  Set watchpoints on car[+0x0C] through car[+0x20]. Run per-frame sample.
- **What this unblocks**: Maps the speed computation pipeline. Speed is
  the most confirmed field — understanding its writer opens the whole
  force→velocity chain.
```

Each entry must explain **why**, **what to do** (with specific scenario from
`build/save_states/README.md`), and **what it unblocks**.

### 3. NOP Test Recommendations

When a field has enough evidence, produce a NOP test recommendation:

```markdown
## NOP Test: car[+0xFC] (accel delta)

- **What to NOP**: Replace the write instruction at PC 0x0602EF4E with
  nop (0x0009).
- **Writer function**: Player path at ~0x0602EF00 (watchpoint-confirmed)
- **Expected effect**: Acceleration delta stays at current value. Car should
  not respond to throttle (C button has no effect on speed change rate).
- **Best scenario**: Load usa_tt_straight.mc0, hold C from dead stop.
- **Confidence**: HIGH — watchpoint-confirmed writer, C button correlation
  established (+70/update toward positive)
```

The bar for recommending a NOP test:
- Writer is confirmed (watchpoint or oracle writes_to)
- Behavioral role is understood
- A save state scenario exists that exercises the field
- We know which instruction to patch

### 4. Scenario Requests

Save states are produced by the human. If you need a scenario that doesn't
exist, request it in `explorer_priorities.md`:

```markdown
## Scenario Request: Sustained braking from high speed

- **Why needed**: Fields at +0xXX only activate with brake input.
- **Suggested setup**: Time trial, accelerate to 60+ mph, then hold B.
- **What it would unlock**: Brake-specific writer identification.
```

## The Mapper Cycle

Each iteration is one **unit of work** followed by a pull.

```
1. Pull from origin
2. Integrate new data (if any)
3. Do one unit of work
4. Commit and push
5. Go to 1
```

### Step 1: Pull from origin

```bash
git pull --rebase origin $(git branch --show-current)
```

Re-read observations, results.tsv, and claims for new data.

### Step 2: Integrate new data

If new observations, claims, or results arrived:
- Update struct map with new writer discoveries or oracle confirmations
- Cross-reference new findings against existing writer maps
- Reassess NOP test readiness

### Step 3: Do one unit of work

Pick ONE task from this list (in priority order):

**(a) Identify and fill the highest-value gap.**

The '95 project has a huge head start: writer maps with 95 offsets and 62K
writes already traced. But these are mechanical facts (PC → offset). The
auto-RE pipeline adds:
- **Behavioral classification**: what does the value do over 300 frames?
- **Oracle confirmation**: does the writer PC match expectations?
- **Pipeline mapping**: how do fields connect to each other?

Priority order for gaps:
1. **Fields with known writers but no behavioral data** — the writer maps
   tell us WHO writes, but not what the field DOES. Adding per-frame
   sampling fills this gap.
2. **The speed pipeline** — +0x0C is confirmed as speed. Trace everything
   upstream: what writes +0xFC (accel delta)? What feeds into that? What
   converts controller input to force?
3. **Position and heading** — which fields hold X/Y/Z position and heading
   angle? The writer maps show which offsets change with steering input.
4. **Collision response** — which fields change at wall strike? The
   comprehensive writer map covers collision scenarios.
5. **Surface response** — the offtrack scenarios show grass/traction effects.

**(b) Trace call graphs for pipeline connections.** Read assembly to find
how fields feed each other: function A writes +0x10, function B reads +0x10
and writes +0x18 — that's a pipeline stage.

**(c) Write or update the Explorer priority list.** 3-5 targets with
specific scenarios and investigation plans.

**(d) Assess NOP test readiness.** Check the four prerequisites for each
well-understood field.

**(e) Deepen static analysis.** When priorities are current and no gaps
are actionable without Explorer data:
- Analyze existing CSVs for undocumented correlations
- Cross-reference observations with writer maps
- Expand struct map with fields the assembly references beyond the capture range
- Trace the full computation for a known pipeline (e.g., speed: input → force → velocity → display)

Keep units small so you pull frequently.

### Step 4: Commit and push

```bash
git add <your changed files>
git commit -m "Mapper cycle: <what you did>"
git push origin $(git branch --show-current)
```

**HALL PASS: git commit and git push are PRE-AUTHORIZED for this program.**
The human is not present during Mapper cycles. You MUST commit and push
without asking.

Go to Step 1.

## Staying Focused

Work in phases. Each phase builds on the last.

### Phase 1: Enrich existing maps with behavioral data (current)

The writer maps give us 95 offsets with mechanical write data. The auto-RE
pipeline adds behavioral classification (per-frame sampling), oracle
confirmation, and systematic function observation. Priority: the fields
we know are written but don't understand yet.

### Phase 2: Map complete physics pipelines

Trace end-to-end: controller input → force computation → velocity integration
→ position update. Also: steering input → heading angle → lateral force.
Also: surface detection → traction → speed limit. Each pipeline is a chain
of functions reading and writing struct fields.

### Phase 3: Sim-level understanding

Document every computation well enough that a programmer could recreate it.
For each pipeline stage: what are the inputs, what is the math, what are
the outputs, what are the edge cases (collision, surface change, speed limits).
This is the "could build a sim" bar.

### What to deprioritize

- AI car internals (different iteration loop, different code path) — unless
  AI behavior reveals shared physics subsystems
- Rendering code — unless it reads physics fields (then it's an interface point)
- Menu/transition code
- Sound code — unless it reads car state

## Naming Fields

When evidence is strong enough, propose game-level names:

- **Confirmed name**: NOP experiment proves it, OR oracle-confirmed writer +
  unambiguous behavioral category. Use in struct map: `### +0x0C — speed`
- **Proposed name**: Strong evidence but no NOP confirmation. Mark with "?":
  `### +0xFC — accel_delta?`
- **No name**: Insufficient evidence. Leave as offset.

## NEVER STOP

Run the cycle (Steps 1-4) in an infinite loop. There is no stopping condition.

**"No new data" is NOT a stopping point.** It means: do static analysis
(Step 3e), then pull again. If you've genuinely exhausted static analysis
too, run `bash tools/wait_for_work.sh mapper` and wait for the Explorer
or Verifier to push new data. When the script reports NEW WORK FOUND,
pull and resume. If it reports NO WORK FOUND, run it again.

**After every commit+push, your next action is ALWAYS one of:**
1. Pull and integrate new Explorer/Verifier data (Step 2), OR
2. Do the next unit of static analysis (Step 3e), OR
3. Run `bash tools/wait_for_work.sh mapper` and wait for new data

There is no option 4. There is no "conclude."

**CRITICAL: Always pull (Step 1) after each unit of work.** Do not chain
multiple tasks without pulling. The Explorer and Verifier may have pushed
new data. Integration of external data always takes priority over your own
analysis.
