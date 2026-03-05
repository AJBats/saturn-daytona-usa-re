# THEORY Tagging Convention

Functions and symbols keep their current names until VERIFIED. Theories are
recorded as comments, not renames.

## Format

Place a `/* THEORY: ... */` block comment immediately before the `.global`
directive in the source file:

```asm
    /* THEORY: suggested_name — what it does.
       Evidence: what we observed (Ghidra, watchpoint, etc). */
    .global FUN_0600XXXX
```

## Rules

1. **Never rename to match a theory.** Keep `FUN_*` / `sym_*` / `DAT_*` names
   until the function reaches VERIFIED (2+ independent empirical observations).

2. **If a theory disagrees with an existing annotation name, revert the name.**
   The file and symbol go back to their `FUN_*` / `sym_*` / `DAT_*` form.
   The old guess was wrong — don't let it mislead. The THEORY comment replaces
   it as the current best hypothesis.

3. **Cite evidence in every THEORY comment.** At minimum: "Ghidra decompilation",
   "watchpoint on X", "breakpoint at Y", "NOP test", "call-trace diff", etc.
   A theory with no cited evidence is just a guess — leave it as UNNAMED.

4. **One theory per symbol.** If competing theories exist, pick the strongest
   and note the alternative briefly.

## Prior art

- `reimpl/src/FUN_0600B6A0.s` — THEORY comment with empirical NOP-test evidence
- `reimpl/src/FUN_0600B914.s` — same pattern, secondary CPU equivalent
