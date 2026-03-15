# Claim Schema — Test Vocabulary

Every claim must use one of these test types. The test runner executes
them mechanically against the emulator. The agent cannot define new
test types — only fill in parameters for existing ones.

---

## writes_to

**"Function F writes to address A during scenario S."**

Test procedure:
1. Load save state for scenario S
2. Set watchpoint on address A
3. Advance N frames
4. Parse watchpoint hits
5. PASS if any hit's PC is within function F's address range

```yaml
type: writes_to
function: FUN_XXXXXXXX      # function under test
function_end: 0xXXXXXXXX    # end address (exclusive)
address: 0xXXXXXXXX         # absolute address to watch
scenario: straight_throttle  # which save state + input
frames: 60                   # how long to run
```

---

## call_count_per_frame

**"Function F is called N times per frame during scenario S."**

Test procedure:
1. Load save state for scenario S
2. Set breakpoint at function F entry
3. Advance 1 frame, counting breakpoint hits
4. PASS if hit count is within [expected - tolerance, expected + tolerance]

```yaml
type: call_count_per_frame
function: FUN_XXXXXXXX
address: 0xXXXXXXXX         # function entry address
scenario: straight_throttle
expected_count: 40           # expected hits per frame
tolerance: 5                 # allowed deviation
```

---

## value_changes_with_input

**"Value at address A increases/decreases when input I is held."**

Test procedure:
1. Load save state for scenario S
2. Read 4 bytes at address A (before)
3. Hold input I for N frames
4. Read 4 bytes at address A (after)
5. PASS if value moved in the expected direction

```yaml
type: value_changes_with_input
address: 0xXXXXXXXX         # absolute address to read
input: C                     # button: A B C X Y Z START L R UP DOWN LEFT RIGHT
direction: increases         # increases | decreases
frames: 60
```

Note: "none" as input means idle (no buttons). Use this to test
"value decreases when no input" (e.g. speed decays when coasting).

---

## value_stable

**"Value at address A does not change when idle for N frames."**

Test procedure:
1. Load save state for scenario S
2. Read 4 bytes at address A (before)
3. Advance N frames with no input
4. Read 4 bytes at address A (after)
5. PASS if before == after

```yaml
type: value_stable
address: 0xXXXXXXXX
scenario: straight_throttle
frames: 60
```

---

## Scenarios

A scenario is a save state + input + frame count. The `scenario` field in
a claim must match a key in the test runner's scenario configuration.

The canonical list of available scenarios, their save states, game context,
and temporal boundaries lives in `build/save_states/README.md`.

---

## Address Resolution

Addresses in claims must be absolute (e.g. `0x0607890C`). The agent must
resolve any struct-relative addresses before writing the claim.

The player car struct base is `0x06078900`. For car[0] fields, compute:
`address = 0x06078900 + offset`

Example: car[0]+0x0C (speed) = `0x0607890C`

---

## Tier Assignment

- **0 claims passed**: Tier 0 (hypothesis unconfirmed)
- **1 claim passed**: Tier 1 (one empirical data point)
- **3+ claims passed, at least 2 different test types, at least 1 function-specific**: Tier 2 (converging evidence)

### Function-specific claim requirement

A claim is **function-specific** if it tests something unique to this function:
- `writes_to` where the expected writer PC is within the function's address range
- `value_changes_with_input` on a field the observation shows this function writes to
- `call_count_per_frame` counts as function-specific (it's inherently about this function)

A claim is **NOT function-specific** if it would pass identically for any function:
- `value_stable` on a field that is globally static
- `value_stable` on a field the function doesn't read or write

Generic `value_stable` claims can still be included but don't count toward the
Tier 2 minimum.

---

## Relationship to Project Validation Tiers

This project has existing validation tiers (THEORY / OBSERVED / VERIFIED)
defined in `.claude/rules/ground-truth.md`. Those tiers are for **function
annotations in `reimpl/src/*.s` files** and require human review for VERIFIED.

The claim-based Tier 0/1/2 system is a **separate, parallel system** for
oracle-confirmed behavioral facts. Auto-RE agents use this tier system for
their claims. They do NOT write THEORY/OBSERVED/VERIFIED tags in source files
— that is the domain of the existing manual RE workflow.
