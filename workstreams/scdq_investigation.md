# SCDQ Investigation — REOPENED

> **Status**: REOPENED — CDB fix reverted (unvalidated), bypass still required
> **Theory**: Mednafen `CDB_Read()` returns stale HIRQ — plausible but fix had no validated delta
> **CDB fix**: REVERTED (mednafen commit 97c572d). Patch preserved below if needed for future A/B test.
> **Bypass**: `reimpl/patches/FUN_060423CC.c` — REQUIRED for Mednafen testing
> **Real hardware**: NOT TESTED — previous test was production binary (make disc bug)
> **Continued in**: workstreams/active_investigation.md

## Root Cause

`CDB_Read()` in Mednafen returns the HIRQ register value **without first synchronizing
the CD Block's internal state** via `CDB_Update()`. Meanwhile, `CDB_Write_DBM()` DOES
call `CDB_Update()` first. This creates a race condition:

1. SCDQ bit 10 only gets set inside `CDB_Update()` → `Drive_Run()` → `TriggerIRQ(HIRQ_SCDQ)`
   when `PeriodicIdleCounter` expires (reload = 187065 ticks)
2. If SH-2 reads HIRQ before the event system fires `CDB_Update`, it gets stale value (SCDQ=0)
3. The +4 byte shift changes SH-2 instruction cache alignment → changes exact cycle when
   HIRQ is read → read lands in gap BEFORE CDB event fires (production lands AFTER)

Mednafen's own TODO at `cdb.cpp:119` acknowledges this:
*"Consider serializing HIRQ_PEND and HIRQ_SCDQ with command execution."*

## The Fix Attempt (REVERTED)

The following patch was applied to `mednafen/src/ss/cdb.cpp` but reverted because we
could not validate it produced a measurable delta. The "boot test" that appeared to
confirm it was actually testing an unshifted production binary due to a `make disc` bug.

The patch remains here on standby — re-apply via `git revert 97c572d` if a proper
A/B test can be designed.

```c
uint16 CDB_Read(uint32 offset)
{
 // Synchronize CD Block state before reading registers.
 sscpu_timestamp_t nt = CDB_Update(SH7095_mem_timestamp);
 SS_SetEventNT(&events[SS_EVENT_CDB], nt);
 // ... rest of function unchanged
```

## Evidence Chain

1. **Hang at frame 683** — free build stuck in FUN_060423CC SCDQ poll loop
2. **Breakpoints mask the bug** — with BPs, both builds return identical values
3. **Call trace shows drift** — free build's SCDQ calls stay constant while prod's decrease
4. **CDB_Read has no sync** — writes call `CDB_Update()`, reads don't
5. ~~**Fix applied** — free build advances past frame 1200, boots to menu~~
6. ~~**Real hardware verification** — free build boots and runs on real Saturn hardware~~
   INVALIDATED: same `make disc` bug — disc contained production binary, not free +4

### Correction (2026-02-18)

Evidence item 5 was wrong. The test that "verified" the CDB fix was sufficient used
`make free` followed by bare `make disc`, which silently rebuilt the binary with default
flags (production layout, no shift). The disc that booted was actually the unshifted
production binary, not the free +4 build.

**Proof**: `make disc` depended on `$(BIN)` and would re-link with `sawyer.ld` when
`build/FUN_0600C010.o` was missing (only `build/FUN_0600C010_patch.o` existed from the
ICF_FIX build). This has been fixed — `make disc` no longer rebuilds (commit 3f554a1).

The CDB fix theory is plausible (Mednafen's own TODO acknowledges the issue), but without
a validated before/after delta, we can't confirm it helps. The fix has been reverted from
Mednafen (commit 97c572d) and the bypass (`SCDQ_FIX=1`) remains required for dev-testing.

## Real Hardware (UNTESTED)

In theory, a real Saturn reading HIRQ at 0x25890008 returns the **current** hardware
register value from the CD Block (SH1 processor) — no emulation layer to serve stale
data. So SCDQ *should* work on real hardware. But this is unverified — the free +4
build has never been properly tested on real Saturn (previous test was production binary).

## Call Chain (for reference)

```
FUN_0603B21C (retry loop)
  → FUN_0603B424 (CD command state machine, returns 0=done, >0=retry)
    → FUN_060423CC (SCDQ poll — waits for HIRQ bit 10)
```

---
*Created: 2026-02-18, Prematurely closed: 2026-02-18, Reopened: 2026-02-18*
