# Active Workstreams

> **READ THIS FIRST after compaction.**
> All problems we face are solvable with enough time and effort. Nothing is intractable, but they may be challenging!

| # | Workstream | Status | Notes |
|---|-----------|--------|-------|
| 1 | **Free Build Emulator Compat** | **ACTIVE** | workstreams/active_investigation.md — cache line mechanism proven at one site |
| 2 | Disc File RE | Complete | workstreams/disc_file_re.md — DISPROVEN: no offset-based APROG.BIN refs in disc files |
| 3 | Road To Boot | Paused | workstreams/PAUSED_road_to_boot.md |
| 4 | Daytona USA Re-implementation | Paused | workstreams/reimplementation.md |

**Free build**: `make free-disc` (no fixes by default). Add fixes explicitly: `make free-disc SCDQ_FIX=1 ICF_FIX=1 CD_FIX=1`.
**Proven mechanism (2026-02-20)**: The +4 code shift causes `MOV.L @(disp,PC),Rn` EAs to shift by +4,
and at FUN_060030FC D312, this crosses a 16-byte cache line boundary costing +7 cycles (verified in trace).
Hypothesis: this mechanism repeats globally, causing cumulative timing drift. Not yet proven end-to-end.
See `workstreams/active_investigation.md`.

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
