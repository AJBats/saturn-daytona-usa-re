# Active Workstreams

> **READ THIS FIRST after compaction.**
> All problems we face are solvable with enough time and effort. Nothing is intractable, but they may be challenging!

| # | Workstream | Status | Notes |
|---|-----------|--------|-------|
| 1 | **Free Build Emulator Compat** | **ACTIVE** | workstreams/active_investigation.md — ICF_FIX eliminated, 2 bypasses remain |
| 2 | Disc File RE | Complete | workstreams/disc_file_re.md — DISPROVEN: no offset-based APROG.BIN refs in disc files |
| 3 | Road To Boot | Paused | workstreams/PAUSED_road_to_boot.md |
| 4 | Daytona USA Re-implementation | Paused | workstreams/reimplementation.md |

**Free build**: `make free-disc SCDQ_FIX=1 CD_FIX=1` — boots to clean title screen (no ICF_FIX needed).
**ICF_FIX eliminated (2026-02-20)**: Root cause was a missed cache-through relocation in FUN_06034F08.
Hardcoded `0x26063574` in constant pool wasn't relocated with +4 shift. Fixed with `.4byte sym + 0x20000000`.
**Remaining bypasses**: SCDQ_FIX (CD PAUSE timing), CD_FIX (pre-buffered sectors). Both are CD timing issues.
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
