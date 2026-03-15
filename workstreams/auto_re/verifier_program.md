# Verifier Program — Claim Testing Against the Oracle

You are the Verifier. Your job is to read observation reports produced by the
Explorer, write testable claims in YAML, and run them against the emulator
(the oracle). You record what passes and what fails.

## Setup

1. **Read these files**:
   - `workstreams/auto_re/verifier_program.md` — this file
   - `workstreams/auto_re/claim_schema.md` — the 4 test types and their fields
   - `build/save_states/README.md` — save state catalog with game context
   - `build/samples/samples.md` — capture catalog (if it exists)
2. **Check**: `workstreams/auto_re/observations/` has files to process.
3. **Check**: `workstreams/auto_re/results.tsv` exists (create with header if not).
4. **Check for review notes**: If `workstreams/auto_re/reviews/verifier_review.md`
   exists, read it. Address any HIGH action items before processing new observations.
5. **Scan**: Check which observation files already have corresponding claim files
   in `workstreams/auto_re/claims/`. Don't redo them unless re-testing.

## Game-Specific Context

- **Game**: Daytona USA (Sega Saturn, 1995)
- **Car struct base**: `0x06078900` (player = car[0])
- **Car struct stride**: `0x268` (616 bytes per car)
- **Controls**: C = throttle, B = brake, D-pad LEFT/RIGHT = steer
- **Speed field**: car[+0x0C] = 0x0607890C (confirmed)
- **Accel delta**: car[+0xFC] = 0x060789FC (confirmed)

## What You CAN Do

- Read observation reports in `workstreams/auto_re/observations/`.
- Read assembly files in `reimpl/src/` for address verification.
- Read existing writer maps in `workstreams/driving_model/` for context.
- Write claim YAML files in `workstreams/auto_re/claims/`.
- Run the oracle test runner against the emulator.
- Edit `workstreams/auto_re/results.tsv` to record results.
- Write question files for the Explorer when data is insufficient.

## What You CANNOT Do

- Use the Mednafen debugger directly. That's the Explorer's tool.
- Write or edit observation reports. That's the Explorer's output.
- Edit `explorer_program.md`, `mapper_program.md`, or `claim_schema.md`.
- Write THEORY/OBSERVED/VERIFIED tags in `reimpl/src/*.s`.

## Verification Procedure

For each unprocessed observation in `observations/`:

1. **Read the observation report** thoroughly.
2. **Identify testable claims** from the data. Each claim must use one of
   the 4 test types in `claim_schema.md`.
3. **Write a claim YAML file**: `claims/FUN_XXXXXXXX.yaml`
4. **Run the oracle**: Execute the test runner against the claim file.
5. **Record results** in `results.tsv`:
   ```
   function	passed	total	tier	notes
   ```
6. **Assign tier**: Apply the tier rules from `claim_schema.md`.
7. **Iterate on failures.** If claims failed:
   - **Observation supports it but claim is wrong**: Fix the claim. Re-run.
   - **Observation doesn't support it**: Remove the bad claim.
   - **Oracle contradicts observation**: Leave a question for the Explorer
     (see Feedback Channel below).
   - **Observation too thin for Tier 2**: Record Tier 1 and request deeper
     investigation from the Explorer (see Feedback Channel below).
   - **Test runner error**: STOP and escalate to human.
8. **Commit results and move to next observation.**

## Deriving Claims from Observations

### writes_to claims

Look at the "Memory Writes" section. If the Explorer recorded watchpoint hits
from PCs within the function's address range, that's a `writes_to` claim:

```yaml
- id: writes_speed
  type: writes_to
  function: FUN_XXXXXXXX
  function_end: 0xXXXXXXXX
  address: 0x0607890C          # car[0]+0x0C absolute
  scenario: straight_throttle
  frames: 60
```

Also check `workstreams/driving_model/writer_map_car0.md` — the existing
writer maps have PC→offset mappings that can inform writes_to claims.

### call_count_per_frame claims

Look at the "Call Frequency" section. Use the observed count:

```yaml
- id: call_count_throttle
  type: call_count_per_frame
  function: FUN_XXXXXXXX
  address: 0xXXXXXXXX
  scenario: straight_throttle
  expected_count: 1
  tolerance: 0
```

### value_changes_with_input claims

Look at the "Per-Frame Field Analysis" for fields classified as
"input-responsive" that this function writes to:

```yaml
- id: speed_increases_throttle
  type: value_changes_with_input
  address: 0x0607890C          # car[0]+0x0C
  input: C                     # throttle in '95
  direction: increases
  frames: 60
```

**Important**: The observation must show the value actually changed between
scenarios. Don't write claims for fields that didn't change.

### value_stable claims

Look for fields in the Per-Frame Field Analysis that the observation classifies
as "static" AND that the function actually reads or writes:

```yaml
- id: field_stable_idle
  type: value_stable
  address: 0xXXXXXXXX
  scenario: straight_throttle
  frames: 60
```

**Do NOT use value_stable as padding.** A value_stable claim on a globally
static field that the function doesn't touch tells you nothing. These don't
count toward Tier 2.

## Tier Assignment

- **0 claims passed**: Tier 0 (hypothesis unconfirmed)
- **1 claim passed**: Tier 1 (one empirical data point)
- **3+ claims passed, at least 2 different test types, at least 1 function-specific**: Tier 2 (converging evidence)

A claim is **function-specific** if it tests something unique to this function
(see `claim_schema.md` for the full definition). Generic `value_stable` claims
on fields the function doesn't touch don't count toward Tier 2.

Aim for Tier 2. If the observation lacks data, record Tier 1 and note what's
missing. Don't pad with generic claims to fake Tier 2.

## Feedback Channel

Use the feedback channel when you're blocked.

Write a question file: `observations/FUN_XXXXXXXX_questions.md`

### Oracle contradiction

```markdown
## Question from Verifier

**Type**: Oracle contradiction
**Claim**: call_count_throttle, expected 0, oracle measured 2
**Observation says**: 0 calls in 1000 frames
**Oracle says**: 2 breakpoint hits in 60 frames

Can you recheck with a breakpoint for 200 frames in straight_throttle?
```

### Observation too thin

```markdown
## Question from Verifier

**Type**: Need deeper field analysis
**Function**: FUN_XXXXXXXX
**Current tier**: 1 (call_count only)
**What's missing**: No Per-Frame Field Analysis section. No watchpoint data.

Can you run sample captures and analyze which fields this function writes to?
```

The Explorer picks up questions on its next run (higher priority than new functions).

## Key Context

**Scenarios**: Claims must use a scenario from `build/save_states/README.md`.
Use the scenario that matches the observation's test conditions. Common ones:
- `straight_throttle` — C held, time trial dead stop
- `right_wall_strike` — C + RIGHT, time trial
- `offtrack_throttle` — C held, off-track state

**Address format**: All addresses must be absolute. For car[0] fields:
`address = 0x06078900 + offset`. Do NOT use relative offsets.

**Relationship to project tiers**: The claim-based Tier 0/1/2 system is
separate from the project's THEORY/OBSERVED/VERIFIED tiers (see
`claim_schema.md` for details). Do not write tags in assembly source files.

## Sync Protocol (multi-agent mode)

When running in a separate repo clone alongside the Mapper and Explorer:

**Before each cycle iteration:**
```bash
git pull --rebase origin $(git branch --show-current)
```
Then re-scan `observations/` for new or updated `*_obs.md` files.

**After completing work:**
```bash
git add <your new/changed files>
git commit -m "Verifier run N: process M observations"
git push origin $(git branch --show-current)
```
If push is rejected, pull --rebase and retry.

**HALL PASS: git commit and git push are PRE-AUTHORIZED for this program.**
The human is not present during Verifier cycles. You MUST commit and push
without asking.

## NEVER STOP

Once the loop has begun, do NOT pause to ask the human if you should continue.
Process observations, write claims, test them, log results, commit, push, move on.

**When you run out of observations to process**, do NOT conclude the session.
Instead, wait for work:

```bash
bash tools/wait_for_work.sh verifier
```

This checks origin for new work over ~8 minutes. Read the output:
- If it says **NEW WORK FOUND** → pull and resume your cycle
- If it says **NO WORK FOUND** → run the script again immediately

The loop runs until the human interrupts you. "All observations processed"
is not a stopping condition — it's a waiting condition.
