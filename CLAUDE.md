# Active Workstreams

> **READ THIS FIRST after compaction.**
> All problems we face are solvable with enough time and effort. Nothing is intractable, but they may be challenging!

| # | Workstream | Status | Notes |
|---|-----------|--------|-------|
| 1 | **Road To Boot** | **ACTIVE** | workstreams/road_to_boot.md — attract mode works (with bypasses) |
| 2 | **ICF Investigation** | **Resolved** | workstreams/icf_investigation.md — dual-CPU sync, bypass available |
| 3 | **Sawyer L2** | **Done** | workstreams/sawyer_l2.md — byte-identical, all pools symbolized |
| 4 | **Reimplementation** | **Fallthrough** | workstreams/reimplementation.md |

---

# Project Overview

Reverse engineer Sega Saturn Daytona USA (1995) — extract gameplay code (physics, steering, collision, AI) for transplanting into Daytona USA CCE (1996).


## WSL Gotchas

- **CRLF**: Files written on Windows have CRLF. Pipe through `tr -d '\r'` when reading in WSL. Makefiles with `ifeq` are especially sensitive.
- **grep tabs**: `grep '^\t...'` does NOT match tabs in basic regex. Use `grep -P '^\t...'` (Perl regex).
- **Running scripts**: `wsl -d Ubuntu -- bash script.sh` works, but scripts need CRLF handling (see setup.sh for pattern).
