# Free Build Emulator Compatibility

> **Status**: ACTIVE — root cause identified, fix in progress
> **Real hardware**: TESTED (2026-02-19) — confirmed FAILS without SCDQ_FIX
> **Mednafen**: Boots to menu with SCDQ_FIX=1 + ICF_FIX=1
> **Current build**: `LDSCRIPT=sawyer_free.ld ICF_FIX=1 SCDQ_FIX=1 CD_FIX=0`
> **Deep research**: `workstreams/research/` — read `00_INDEX.md` first

---

## CRITICAL UPDATE: Root Cause Found (2026-02-19)

The SCDQ hang is caused by a **latent bug in the CD state machine
`FUN_0603B424`**, not by Mednafen CDB timing. See `workstreams/scdq_hypothesis_2.md`
and `workstreams/research/03_bugs_found.md` for full analysis.

---

## What Was Learned This Session (2026-02-19)

### 1. Real Hardware Confirmed the Bug Is Real

Free build with `ICF_FIX=1, SCDQ_FIX=0` was tested on real Saturn hardware
and **failed to boot**. This is NOT a Mednafen emulation artifact. The SCDQ
hang is a real code issue that manifests on real hardware.

### 2. SS_DBG_CDB Command Logging Revealed the Divergence

By enabling Mednafen's built-in CDB logging (`SS_DBG_CDB`), we captured the
complete CD command sequence for both production and free builds (2000 frames).

**Key finding**: Both builds issue **identical CD commands** through command
#2201. The first behavioral divergence is at the TABLE.BIN Play command.

### 3. Root Cause: FUN_0603B424 PAUSE Handler

After TABLE.BIN Play (`Start=0x800762, End=0x80000e`), the free build gets
**"play end pause" immediately** — all 14 sectors pre-buffered before the
first `Get Sector Number` poll.

The CD state machine's PAUSE handler calls `GetBufSize` and only proceeds to
read sectors when `retval == 1` (buffer empty). With 14 pre-buffered sectors,
retval is never 1 → **infinite retry loop → SCDQ poll never exits → black screen**.

Production binary never triggers this because it always reads TABLE.BIN
sectors one-at-a-time during PLAY state (not pre-buffered in PAUSE state).

### 4. Why the Timing Changed

The +4 byte shift changes the phase of SH-2 execution relative to disc
operations. More time passes in the SCDQ poll between SCROLL.BIN and TABLE.BIN
operations. During this extra time, the disc advances past FAD 0x0770 (TABLE.BIN
end FAD). When TABLE.BIN Play is issued with end FAD = 0x0770, the disc has
already reached that point → immediate play-end-pause.

**NOTE**: TABLE.BIN (FAD 0x0762) and SCROLL.BIN (FAD 0x0770) are directly
adjacent on disc. The end of TABLE.BIN = the start of SCROLL.BIN. This
adjacency is the key geometric fact enabling the timing race.

### 5. SCDQ_FIX=1 Works as a Workaround

`SCDQ_FIX=1` shortens the SCDQ poll (timeout after 1000 iterations). This
prevents the disc from advancing past FAD 0x0770 during the poll. TABLE.BIN
Play then succeeds via normal PLAY state sector-reading. **It's a workaround,
not a root-cause fix.**

### 6. CD_FIX Attempt — Has a Secondary Bug

A C patch for `FUN_0603B424` was implemented that widens the "proceed to
Calculate" condition from `status==2` to `status==2 || status==1 (PAUSE)`.

**This has a secondary bug**: The widened condition also fires during the
APROG.BIN initial file load (at command #67 in the CDB log), preventing
`End Data Transfer` from being issued. The game loads incorrectly → black screen.

**Fix needed**: Guard the PAUSE→Calculate path with the specific `ctx[0x12]`
state byte value that only occurs during the TABLE.BIN "waiting for sectors"
state. See `workstreams/research/06_cd_fix_implementation.md`.

---

## Current Status Table

| Issue | Root Cause | Bypass | Fix Status |
|-------|-----------|--------|------------|
| **ICF** | Slave SH-2 FUN_0600C170 crash (wrong init data) | `ICF_FIX=1` | Unresolved, separate from CD bugs |
| **SCDQ timing** | Disc in PAUSE when SCDQ polled (downstream of Bug 3) | `SCDQ_FIX=1` | Workaround only |
| **CD PAUSE handler** | `FUN_0603B424` doesn't handle PAUSE+pre-buffered sectors | None yet | `CD_FIX=1` attempted, secondary bug |

---

## Immediate Next Steps

### Priority 1: Fix CD_FIX Guard Condition

Find the `ctx[0x12]` state value that distinguishes:
- TABLE.BIN "play end pause" (FIX should trigger)
- APROG.BIN mid-transfer PAUSE (FIX should NOT trigger)

**How**: Add `fprintf(stderr, "[CD_FIX] PAUSE: ctx[0x12]=0x%02X\n", ctx[0x12])`
to the PAUSE case in `patches/FUN_0603B424.c`. Run both builds. Compare state
values at command #67 vs command #2201+.

### Priority 2: Test CD_FIX on Mednafen

Once guard is added:
```bash
make -C reimpl LDSCRIPT=sawyer_free.ld ICF_FIX=1 SCDQ_FIX=0 CD_FIX=1
make -C reimpl disc
python3 tools/diag_cdb_commands.py --frames 2000
```
Look for: `End Data Transfer` at command #68, Calculate loop at command #2201+.

### Priority 3: Real Saturn Test

Test `SCDQ_FIX=1 ICF_FIX=1 CD_FIX=0` on real Saturn hardware.
Previous real Saturn test was invalidated (was testing production binary).
This combination is verified to boot on Mednafen (12/12 state transitions).

---

## Investigation Plan (4 Investigations)

See `workstreams/scdq_investigation_plan.md` for full details.

| # | Investigation | Priority | Status |
|---|--------------|----------|--------|
| 1 | Is SCDQ pre-armed? | High | Not done |
| 2 | Second emulator (Kronos) | Medium | Not started |
| 3 | 0x034d vs 0x034f propagation | Low | Not done (likely noise) |
| 4 | CD code quarantine linker script | Medium | Not started |

---

## Key Files Changed This Session

```
mednafen/src/ss/cdb.cpp    — SCDQ trace implemented (CDB_EnableSCDQTrace)
mednafen/src/ss/ss.cpp     — SS_DBG_CDB always on, FTI logging removed
mednafen/include/config.h  — MDFN_ENABLE_DEV_BUILD = 1
reimpl/patches/FUN_0603B424.c  — CD_FIX patch (has secondary bug, needs guard)
tools/diag_cdb_commands.py — NEW: CDB command sequence comparison tool
tools/diag_scdq_state.py   — NEW: SCDQ trace analysis tool
workstreams/research/      — NEW: 12 research files, comprehensive knowledge base
workstreams/scdq_hypothesis_2.md — NEW: Root cause analysis
workstreams/scdq_investigation_plan.md — UPDATED: 4 investigations
docs/mednafen_debug_tools.md — NEW: Tool reference
```

## Bootstrap: How to Read Into This Investigation

**Load these files in order** to get fully up to speed:

1. `CLAUDE.md` — auto-loaded, gives project overview and workstream table
2. `workstreams/active_investigation.md` — this file, start here
3. `workstreams/research/00_INDEX.md` — three-sentence summary + file map for all research
4. `workstreams/research/03_bugs_found.md` — the three bugs, their status, root causes
5. `workstreams/research/06_cd_fix_implementation.md` — the patch attempt and what's still broken
6. `workstreams/research/10_next_steps.md` — concrete action plan with code examples

### The Investigation Story in One Paragraph

We started believing the SCDQ hang was a Mednafen CDB timing bug (reads landing
before the CDB event fires). We enabled Mednafen's built-in SS_DBG_CDB logging
and captured the full CD command sequence for both production and free builds.
The logs showed both builds issue **identical commands** until command #2201
(TABLE.BIN Play), where the free build immediately hits "play end pause" with
all 14 sectors pre-buffered. We decoded `FUN_0603B424`'s ASM dispatch table
and found the root cause: the PAUSE handler only proceeds to read sectors when
`GetBufSize returns 1` (buffer empty), but with 14 pre-buffered sectors the
condition is never satisfied → infinite retry loop. Real hardware confirmed the
bug is real (not emulator-specific). We implemented `CD_FIX=1` which widens the
PAUSE→Calculate condition, but it has a secondary bug: it also fires during the
APROG.BIN initial load at command #67, preventing `End Data Transfer` from being
issued. The fix needs a `ctx[0x12]` state-byte guard to distinguish the TABLE.BIN
waiting state from the APROG.BIN mid-transfer state. `SCDQ_FIX=1` remains the
working workaround: it shortens the SCDQ poll enough to prevent the disc from
advancing past TABLE.BIN's end FAD, avoiding the PAUSE deadlock entirely.

### The One Thing to Do Next

Add `ctx[0x12]` logging to `patches/FUN_0603B424.c` PAUSE case, run
`diag_cdb_commands.py` on both builds, compare state values at command #67
(APROG.BIN, should NOT fix) vs command #2201+ (TABLE.BIN, SHOULD fix). Add
the guard and test. See `workstreams/research/06_cd_fix_implementation.md`.

---

## Log

- 2026-02-18: SCDQ investigation reopened after make disc bug discovered
- 2026-02-18: Makefile hardened — `make disc` no longer rebuilds
- 2026-02-19: Real Saturn test — free build (ICF only) FAILS to boot (confirmed real bug)
- 2026-02-19: SS_DBG_CDB logging enabled — captured full CDB command sequences
- 2026-02-19: Root cause identified — FUN_0603B424 PAUSE handler, TABLE.BIN timing race
- 2026-02-19: CD_FIX attempt — widened PAUSE→Calculate condition
- 2026-02-19: CD_FIX secondary bug found — also fires on APROG.BIN load (cmd #67)
- 2026-02-19: Comprehensive research directory created: `workstreams/research/`
