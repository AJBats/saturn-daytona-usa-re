# Active Workstreams

> **READ THIS FIRST after compaction.**
> All problems we face are solvable with enough time and effort. Nothing is intractable, but they may be challenging!

| # | Workstream | Status | Notes |
|---|-----------|--------|-------|
| 1 | **Disc File RE** | **ACTIVE** | workstreams/disc_file_re.md — RE TABLE.BIN + SCROLL.BIN to find offset-based APROG.BIN refs |
| 2 | Free Build Emulator Compat | Paused | workstreams/active_investigation.md — SCDQ + ICF + CD_FIX bypasses boot to menu |
| 3 | Road To Boot | Paused | workstreams/PAUSED_road_to_boot.md |
| 4 | Daytona USA Re-implementation | Paused | workstreams/reimplementation.md |

**Free build**: `make free-disc` (SCDQ_FIX=1 + ICF_FIX=1 + CD_FIX=1). Boots to menu with corrupt graphics.
**New direction**: Instead of chasing SCDQ root cause (circular), RE the disc files the game loads
to understand if they contain offset-based references back into APROG.BIN that break under +4 shift.

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
