# Active Workstreams

> **READ THIS FIRST after compaction.**
> All problems we face are solvable with enough time and effort. Nothing is intractable, but they may be challenging!

| # | Workstream | Status | Notes |
|---|-----------|--------|-------|
| 1 | **Free Build Emulator Compat** | **ACTIVE** | workstreams/active_investigation.md — first instruction divergence found |
| 2 | Disc File RE | Complete | workstreams/disc_file_re.md — DISPROVEN: no offset-based APROG.BIN refs in disc files |
| 3 | Road To Boot | Paused | workstreams/PAUSED_road_to_boot.md |
| 4 | Daytona USA Re-implementation | Paused | workstreams/reimplementation.md |

**Free build**: `make free-disc` (no fixes by default). Add fixes explicitly: `make free-disc SCDQ_FIX=1 ICF_FIX=1 CD_FIX=1`.
**Milestone (2026-02-20)**: Deterministic tracing found first divergence — BIOS copy loop at 0x00002F00 does
one extra iteration in free build (+23 cycles). This is a DATA divergence from the +4 shift, not cache timing.
Next: identify caller, dump registers, trace the mismatched loop bound to its source.

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
