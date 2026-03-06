# Ground Truth & Empirical Verification

The emulator running unmodified production code is the oracle. Everything else — Ghidra
output, tool scripts, binary comparisons, static analysis — is inference that can be wrong.

## Ground Truth Principles

1. **Verify with the emulator** — breakpoints, memory dumps, register comparisons at
   deterministic code points. If you haven't run it in Mednafen, you don't know if it works.

2. **Never trust tool output as truth** — tools have bugs. Cross-validate with independent
   evidence sources. If a script says "all 5,027 entries are correct," verify a sample
   manually before declaring victory.

3. **Never bypass without understanding** — if unmodified code fails, the root cause must
   be found before any bypass is committed. A bypass proves proximity to the answer, not
   that the answer is found. Bypasses are diagnostic scaffolding, not fixes.

4. **Verify prior session diagnoses** — context loss between sessions can propagate wrong
   assumptions. Re-verify with breakpoints before building on old conclusions. "Last session
   we found X" is a hypothesis, not a fact.

5. **Production behavior is the spec** — if production boots and our build doesn't, we are
   wrong. Not the emulator, not the hardware docs, not our understanding of the code. We
   are wrong. Find out why.

## Validation Tiers

Every function annotation must earn its tier through emulator evidence. Static analysis
(Ghidra decompilation, code reading) is an experiment design tool — it tells you what to
test, not what is true. It cannot validate anything.

| Tier | Requirement | Action |
|------|-------------|--------|
| *(no tier)* | Static analysis only (Ghidra, code reading) | No tag. Use findings to design experiments. |
| **THEORY** | 1 empirical observation from the emulator (breakpoint, watchpoint, NOP test, etc.) | Comment tag, keep `FUN_*` name |
| **OBSERVED** | 2+ empirical datapoints from the emulator, none contradicting | Comment tag, keep `FUN_*` name |
| **VERIFIED** | Human user has reviewed, confirmed, and approved graduation | Rename function from `FUN_*` |

**No tier without the emulator.** Ghidra says a function does X? That's a hypothesis to
test, not a THEORY to tag. Run the experiment first.

## Empirical Verification Checklist

Before marking any function as THEORY, OBSERVED, or proposing for VERIFIED:

0. **Emulator evidence required.** No review is complete without running the function in
   the debugger — breakpoints, watchpoints, or screenshots. Static analysis alone is never
   sufficient.
1. **Every code path accounted for?** — Not just the ones you tested. Every branch, every
   button mask, every state write.
2. **Every experiment matched prediction?** — If a result surprised you, STOP. Investigate
   the mismatch before moving on. Surprises are discoveries.
3. **Any renameable symbols discovered?** — Did the investigation reveal what any `sym_*`
   variables actually are?

## Evidence Hierarchy

**Memory reads are evidence. Screenshots are context only.**

- Memory values (read_u32, read_memory, watchpoints) are precise and unambiguous — use
  these to draw conclusions about function behavior.
- Screenshots provide visual context (confirming we're in the right game state) but Claude
  cannot reliably interpret game visuals. Never claim to see specific behaviors in a
  screenshot (e.g., "AI cars are visible," "the car turned left"). If visual confirmation
  is needed, describe the screenshot to the user and let them interpret it.

## Static Analysis Role

Static analysis (Ghidra, code reading, disassembly) is valuable for:
- Identifying which functions to investigate
- Designing experiments (what to breakpoint, what memory to watch)
- Understanding control flow to plan test scenarios
- Forming hypotheses about struct fields and data flow

It is NOT valid for:
- Tagging functions at any tier
- Claiming to know what a function does
- Mass-producing annotations
- Background agent work on function behavior
