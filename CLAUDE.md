# Active Workstreams

> **READ THIS FIRST after compaction.**
> All problems we face are solvable with enough time and effort. Nothing is intractable, but they may be challenging!

| # | Workstream | Status | Notes |
|---|-----------|--------|-------|
| 1 | **Free Build Emulator Compat** | **ACTIVE** | workstreams/active_investigation.md — SCDQ + ICF bypasses needed for Mednafen |
| 2 | Road To Boot | Paused | workstreams/PAUSED_road_to_boot.md |
| 3 | Daytona USA Re-implementation | Paused | workstreams/reimplementation.md |

**Key fact**: Free build (+4 shift) boots on real Saturn. SCDQ and ICF are Mednafen emulator issues.
Bypasses (`SCDQ_FIX=1`, `ICF_FIX=1`) are legitimate emulator workarounds, not hiding code bugs.
Build: `make free-disc` (one command, correct flags).

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
