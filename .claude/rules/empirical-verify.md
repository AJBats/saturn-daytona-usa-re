# Empirical Verify Checklist

Before marking any VERIFIED function as reviewed (GOOD or RENAMED), walk through:

0. **Emulator evidence required.** No review is complete without running the function in the debugger — breakpoints, watchpoints, or screenshots. Static analysis alone is never sufficient.
1. **Every code path accounted for?** — Not just the ones you tested. Every branch, every button mask, every state write.
2. **Every experiment matched prediction?** — If a result surprised you, STOP. Investigate the mismatch before moving on. Surprises are discoveries.
3. **Every comment accurate?** — Could a future reader trust every annotation? Wrong comments are worse than no comments.
4. **Any renameable symbols discovered?** — Did the investigation reveal what any `sym_*` variables actually are?
