# Tagging Convention

Functions and symbols keep their current names until VERIFIED. Findings are
recorded as comments, not renames.

## Validation Tiers

See `.claude/rules/ground-truth.md` for full tier definitions. Summary:

| Tier | Requirement | Action |
|------|-------------|--------|
| *(no tier)* | Static analysis only | No tag. Design experiments. |
| **THEORY** | 1 emulator observation | Comment tag, keep `FUN_*` name |
| **OBSERVED** | 2+ emulator datapoints | Comment tag, keep `FUN_*` name |
| **VERIFIED** | Human reviewed and approved | Rename function from `FUN_*` |

## Comment Format

Place a block comment immediately before the `.global` directive:

```asm
    /* THEORY: suggested_name — what it does.
       Evidence: breakpoint at X showed Y. */
    .global FUN_0600XXXX
```

```asm
    /* OBSERVED: suggested_name — what it does.
       Evidence 1: watchpoint on car[+0x0C] — written by this function every frame.
       Evidence 2: NOP test — car stops accelerating. */
    .global FUN_0600XXXX
```

## Rules

1. **Never rename to match a theory or observation.** Keep `FUN_*` / `sym_*` / `DAT_*`
   names until the function reaches VERIFIED (human approved).

2. **If a theory disagrees with an existing annotation name, revert the name.**
   The file and symbol go back to their `FUN_*` / `sym_*` / `DAT_*` form.
   The old guess was wrong — don't let it mislead. The tag comment replaces
   it as the current best hypothesis.

3. **Cite emulator evidence in every tag.** At minimum: "breakpoint at X",
   "watchpoint on Y", "NOP test showed Z", "call-trace diff found W".
   Ghidra/static analysis is NOT evidence — it's experiment design.

4. **One theory per symbol.** If competing theories exist, pick the strongest
   and note the alternative briefly.

## Prior art

- `reimpl/src/FUN_0600B6A0.s` — THEORY comment with empirical NOP-test evidence
- `reimpl/src/FUN_0600B914.s` — same pattern, secondary CPU equivalent
