# Mednafen CDB Internals: How CD Block Emulation Works

## The Event System

Mednafen uses a sorted event list. Each subsystem has an event entry scheduled
for its next "wake-up time". The main loop runs:

```c
// In RunLoop_INLINE (ss.cpp):
do {
    CPU[0].Step();          // Execute one SH-2 instruction
    eff_ts = max(CPU[0].timestamp, SH7095_mem_timestamp);
} while(eff_ts < next_event_ts);  // Run until next event
EventHandler(eff_ts);              // Fire all due events
```

CDB_Update is registered as `events[SS_EVENT_CDB].event_handler`.
It fires whenever `eff_ts >= events[SS_EVENT_CDB].event_time`.

## CDB_Update: The Core Timer

```c
sscpu_timestamp_t CDB_Update(sscpu_timestamp_t timestamp) {
    int64 clocks = (int64)(timestamp - lastts) * CDB_ClockRatio;
    lastts = timestamp;
    Drive_Run(clocks);
    // ... command processing state machine ...
    // Calculate next event time:
    int64 net = min(-CommandClockCounter, DriveCounter, PeriodicIdleCounter);
    return timestamp + (net + CDB_ClockRatio - 1) / CDB_ClockRatio;
}
```

Key: `CDB_ClockRatio = (1ULL << 32) * 11289600 * CurrentClockDivisor / MasterClock`
≈ 1,694,066,133 for NTSC. This converts SH-2 ticks to CDB ticks (fixed-point).

## PeriodicIdleCounter: The SCDQ Source

```c
static int64 PeriodicIdleCounter;
enum : int64 { PeriodicIdleCounter_Reload = (int64)187065 << 32 };
```

In Drive_Run():
```c
PeriodicIdleCounter -= clocks;
if (PeriodicIdleCounter <= 0) {
    PeriodicIdleCounter = PeriodicIdleCounter_Reload;
    // ... play/pause handling ...
    PeriodicIdleCounter = PeriodicIdleCounter_Reload;
    TriggerIRQ(HIRQ_SCDQ);   // ← SCDQ fires here
}
```

**Period calculation**: 187065 << 32 fractional CDB ticks ÷ CDB_ClockRatio
≈ 187065 * 4.295e9 / 1.694e9 ≈ **474,940 SH-2 ticks ≈ 16.7ms ≈ 1 NTSC frame**.

**Critical difference from real hardware**: This fires in ALL drive states
(PLAY, PAUSE, STANDBY, SEEK, BUSY). On real Saturn hardware, SCDQ only fires
when the disc is actively reading sectors.

## TriggerIRQ

```c
static INLINE void TriggerIRQ(unsigned bs) {
    HIRQ |= bs;
    RecalcIRQOut();
}

static INLINE void RecalcIRQOut(void) {
    SCU_SetInt(16, (bool)(HIRQ & HIRQ_Mask));
}
```

Sets HIRQ bit and potentially asserts an SCU interrupt to the SH-2.

## CDB_Read: The HIRQ Reader

```c
uint16 CDB_Read(uint32 offset) {
    uint16 ret = 0;
    switch(offset) {
    case 0x2:   // HIRQ register
        ret = HIRQ;
        // SET-only trace here (if enabled, no READ trace to avoid observer effect)
        break;
    case 0x3:   ret = HIRQ_Mask; break;
    case 0x6-0x9: Results[N]; break;
    }
    return ret;
}
```

**The bug in the original analysis**: Early investigation proposed a fix
(CDB_Update in CDB_Read) to make HIRQ reads always see current state.
This was implemented, tested, and showed partial results but the real root
cause is the PAUSE handler in FUN_0603B424 (Bug 3 in `03_bugs_found.md`).

## CDB_Write_DBM: Why Writes Sync But Reads Don't

```c
void CDB_Write_DBM(uint32 offset, uint16 DB, uint16 mask) {
    sscpu_timestamp_t nt = CDB_Update(SH7095_mem_timestamp); // ← SYNCS!
    SS_SetEventNT(&events[SS_EVENT_CDB], nt);
    // ... process write ...
}
```

Writes call CDB_Update first (syncing CDB state). Reads don't. This was
identified as a potential timing issue early in the investigation, but
subsequent analysis showed the real problem is FUN_0603B424's PAUSE handler.

## The SCDQ Trace (our addition)

Added to cdb.cpp:
```c
static FILE* scdq_trace_file = NULL;

// In Drive_Run, after TriggerIRQ(HIRQ_SCDQ):
if(MDFN_UNLIKELY(scdq_trace_file))
    fprintf(scdq_trace_file, "SET %d %d 0x%04X\n",
            (int)lastts, (int)CurPosInfo.status, (unsigned)HIRQ);

void CDB_EnableSCDQTrace(const char* path) {
    scdq_trace_file = fopen(path, "w");
}
void CDB_DisableSCDQTrace(void) {
    fclose(scdq_trace_file); scdq_trace_file = NULL;
}
```

Activated via automation command: `scdq_trace /path/to/log.txt`

**READ trace deliberately omitted**: Adding `fprintf` to every `CDB_Read`
case 0x2 generates ~10,000 writes/frame, creating massive observer effect
by slowing the emulation main loop.

## SS_DBG_CDB Logging

Mednafen's built-in CDB logging (requires `MDFN_ENABLE_DEV_BUILD`):

```c
// ss.cpp:
ss_dbg_mask = MDFN_GetSettingMultiM("ss.dbg_mask") | SS_DBG_ERROR | SS_DBG_CDB;
```

Logs every command issued, response, drive state transitions, DT FAD tracking.
Goes to `trio_vprintf` → stdout → `mednafen_stdout.log` in automation mode.

Key log points in cdb.cpp:
- `[CDB] Command: NAME --- HIRQ=0x????, HIRQ_Mask=0x???? --- timestamp`
- `[CDB]   Results: CR1 CR2 CR3 CR4`
- `[CDB] Starting play end pause.`
- `[CDB] Starting buffer full pause.`
- `[CDB] Resuming from buffer full pause.`
- `[CDB] DT FAD: 0x???????? --- 8 1024` (sector data transfer progress)

## Observer Effect Summary

| Operation | Observer effect? | Why |
|-----------|-----------------|-----|
| `frame_advance` | None | Pure SH-2 execution |
| `dump_mem_bin` | None | FastMap reads only |
| SCDQ SET trace | None | CDB event system, no CPU hook |
| SCDQ READ trace | YES (severe) | 10k fprintf/frame slows emulation |
| `ss.dbg_mask=cdb` | Minimal | ~40 log points/frame, small overhead |
| `pc_trace_frame` | YES (severe) | Enables CPU hook → ForceEventUpdates every insn |
| `call_trace` | YES (severe) | Same as above |
| `breakpoint` | YES (severe) | Same as above |

`ForceEventUpdates()` calls all event handlers (including `CDB_Update`) at
every single SH-2 instruction, making SCDQ fire almost instantly instead of
every 474,940 cycles. This is why breakpoints "fixed" the SCDQ hang in early
testing — the fix was masking the bug.

## Drive Phase Transitions

Relevant transitions in Drive_Run:
- `DRIVEPHASE_SEEK_*` → `DRIVEPHASE_PLAY`: after seek completes
- `DRIVEPHASE_PLAY` → `DRIVEPHASE_PAUSE` when:
  - End FAD reached ("play end pause")
  - Buffer full (`!FreeBufferCount`) ("buffer full pause")
  - `PauseCounter` conditions

When `CurPosInfo.status` is PAUSE (0x01):
- Mednafen: PeriodicIdleCounter still fires SCDQ
- Real hardware: disc not reading → no sub-Q updates → SCDQ doesn't fire
