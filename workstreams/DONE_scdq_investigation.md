# SCDQ Investigation — RESOLVED

> **Status**: RESOLVED — root cause found and fixed
> **Root cause**: Mednafen emulator bug — `CDB_Read()` returns stale HIRQ values
> **Fix**: Added `CDB_Update()` sync call to `CDB_Read()` in `mednafen/src/ss/cdb.cpp`
> **Bypass**: `reimpl/patches/FUN_060423CC.c` — NO LONGER NEEDED, can be removed

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

## The Fix (5 lines in `mednafen/src/ss/cdb.cpp`)

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
5. **Fix applied** — free build advances past frame 1200, boots to menu
6. **Real hardware prediction** — real CD Block has no stale register issue

## Why This Doesn't Affect Real Hardware

On a real Saturn, reading HIRQ at 0x25890008 returns the **current** hardware register
value from the CD Block (SH1 processor). There's no emulation layer that could serve
stale data. The SCDQ bypass was never needed for real hardware — only for Mednafen.

## Call Chain (for reference)

```
FUN_0603B21C (retry loop)
  → FUN_0603B424 (CD command state machine, returns 0=done, >0=retry)
    → FUN_060423CC (SCDQ poll — waits for HIRQ bit 10)
```

---
*Created: 2026-02-18, Resolved: 2026-02-18*
