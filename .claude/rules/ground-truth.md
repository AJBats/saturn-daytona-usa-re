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

## Evidence Hierarchy

**Memory reads are evidence. Screenshots are context only.**

- Memory values (read_u32, read_memory, watchpoints) are precise and unambiguous — use
  these to draw conclusions about function behavior.
- Screenshots provide visual context (confirming we're in the right game state) but Claude
  cannot reliably interpret game visuals. Never claim to see specific behaviors in a
  screenshot (e.g., "AI cars are visible," "the car turned left"). If visual confirmation
  is needed, describe the screenshot to the user and let them interpret it.

## Validation Tiers & Tagging

See `.claude/rules/theory-tagging.md` for the THEORY/OBSERVED/VERIFIED tier system
and tagging conventions.
