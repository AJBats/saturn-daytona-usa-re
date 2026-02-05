# Next Human Session Actions

> Created: 2026-02-05
> Context: After reviewing decomp status and realizing gaps in approach

---

## 1. Decomp Skill Gaps

**Observation**: Claude has been applying a limited set of decomp techniques and may be declaring functions "challenging" prematurely.

**Known techniques being used**:
- Variable declaration order (controls constant load order)
- Type casting (short vs int, signed vs unsigned)
- Expression decomposition (intermediate variables)
- `register asm("rN")` trick (forces register allocation)
- Volatile for memory ordering

**Unknown / unexplored**:
- Techniques from other decomp projects (Mario 64, Zelda OoT, BotW)
- SH-2 / Hitachi compiler-specific patterns
- GCC 2.6.3 quirks beyond current documentation
- Academic papers or forums on 90s-era compiler matching
- What knobs exist at RTL/reload stages

**Key insight**: The `register asm("r5")` fix for FUN_06005174 was discovered by accident. This suggests more techniques exist that we don't know yet. "Challenging" might just mean "don't know how to fix yet."

**Potential action**:
- Research decomp community resources (decomp.me, decomp.wiki, RetroReversing)
- Study GCC 2.6.3 internals more deeply
- Build first-principles understanding of "what C patterns produce what asm"
- Develop new decomp skills from experimentation

---

## 2. MD Files Need Careful Cleanup

**Observation**: The documentation is both helping and hurting:

**Helping**:
- Fast ramp-up after context compaction
- Preserves techniques and patterns

**Hurting**:
- "Challenging" labels become self-fulfilling prophecies
- Anchors thinking to previous session conclusions
- Claude stops trying because docs say "don't bother"
- Creates premature pattern matching ("this looks like X, so skip it")

**Reality check**: Only ~15 functions were actually hands-on attempted this session. The "800 challenging" claim was extrapolation from patterns, not systematic verification.

**Potential action**:
- Carefully review and clean up MD files interactively
- Remove or soften premature "challenging" conclusions
- Keep useful technique documentation
- Add nuance: "not yet solved" vs "proven impossible"

---

## Session Notes

These observations came from a frank discussion about why 800 functions were declared challenging without being individually attempted. The documentation was creating a limiting mindset rather than enabling exploration.

Next session should:
1. Discuss approach to finding/developing new decomp skills
2. Interactively clean up MD files to reduce noise
3. Consider systematic grinding through functions with fresh eyes
