# Active Workstreams

> **READ THIS FIRST after compaction.**
> All problems we face are solvable with enough time and effort. Nothing is intractable, but they may be challenging!

| # | Workstream | Status | Notes |
|---|-----------|--------|-------|
| 1 | Empirical Validation — Ground Truth via Debugger | **Active** | workstreams/empirical_validation/ |
| 2 | Car Flip Benchmark — Empirical Annotation Validation | Paused | workstreams/car_flip_benchmark.md |

**Free build**: `make disc` — builds free-layout binary, injects into disc. Boots to title, races laps.
**Build system**: `reimpl/retail/` = original Sega ASM, `reimpl/src/` = reimplemented functions (C or ASM).
**Linker scripts**: `free.ld` (free-layout, normal and +4 shift modes — see Makefile), `sega.ld` (byte-identical retail).
**MODS flag**: `MODS=1` enables relocation patches in `src/mods/` (currently: SCDQ poll timeout fix).
**Validation**: `make retail-validate` (retail match), `make validate` (free match), `python tools/validate_build.py` (all 3 + shifted boot test).
See `workstreams/DONE_free_build_compat.md`.

## Investigation Discipline

**No bypass commits without root cause.** A bypass (timeout, NOP, skip) is a diagnostic tool,
not a fix. You can USE a bypass to unblock testing, but never COMMIT one as the solution.
If you find yourself writing a workaround, you've found the symptom — now find the cause.

---

# Project Overview

Reverse engineer Sega Saturn Daytona USA (1995) — extract gameplay code (physics, steering, collision, AI) for transplanting into Daytona USA CCE (1996).


## WSL Gotchas

- **CRLF**: Files written on Windows have CRLF. Pipe through `tr -d '\r'` when reading in WSL. Makefiles with `ifeq` are especially sensitive.
- **grep tabs**: `grep '^\t...'` does NOT match tabs in basic regex. Use `grep -P '^\t...'` (Perl regex).
- **Running scripts**: `wsl -d Ubuntu -- bash script.sh` works, but scripts need CRLF handling (see setup.sh for pattern).
