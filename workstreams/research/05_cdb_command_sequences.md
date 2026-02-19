# CD Block Command Sequences: Production vs Free Build

## How to Capture

Enable `SS_DBG_CDB` in Mednafen (requires `MDFN_ENABLE_DEV_BUILD = 1` in config.h):
```c
// ss.cpp line ~1464:
ss_dbg_mask = MDFN_GetSettingMultiM("ss.dbg_mask") | SS_DBG_ERROR | SS_DBG_CDB;
```
Output goes to stdout → `mednafen_stdout.log` in each IPC dir.

Run: `python3 tools/diag_cdb_commands.py --frames 2000`

## Initial Boot Sequence (IDENTICAL in both builds through cmd #67)

Both builds issue exactly the same commands through command #67:

```
Get Hardware Info
Abort File + End Data Transfer (cleanup)
Get Hardware Info + Get Copy Error
Reset Selector
Set Sector Length
Get TOC + End Data Transfer
Get Session Info ×2
Authenticate Device
Get Device Authentication Status
Change Directory
Abort File
Initialize
Set CD Device Connection
Get Session Info ×2
Play; Start=0x800096, End=0x800010, Mode=0x00    ← initial disc read
[Starting play end pause]
Get Sector Number → PAUSE (0x01), 0x10 sectors
Get and Delete Sector Data; Count=0x10           ← reads 16 sectors
End Data Transfer
Change Directory
Get Filesystem Scope
[Starting pause]
Read File; ID=0x000002                            ← reads APROG.BIN
[Starting play end pause]
Get CD Status ×2
Get File Info
End Data Transfer
Get Sector Number → PAUSE, 0xC1 sectors
Get and Delete Sector Data; Count=0xC1           ← reads 193 sectors
                                                 ← cmd #66 (last identical)
End Data Transfer → Results: 0103 034d 0000 0000 ← cmd #67 (last identical)
```

## First Numerical Divergence: Command #491 (MINOR)

Both production and free build issue `End Data Transfer` at command #491.
The only difference is CR2 (last processed FAD):
```
Production: Results: 0103 034d 0000 0000  (FAD 845 = 0x034D)
Free build: Results: 0103 034f 0000 0000  (FAD 847 = 0x034F)
```
Difference: 2 sectors. This is a timing artifact (the free build's disc
read slightly different amount of TEX_C1.BIN data before End Data Transfer).

**Impact**: Both builds then issue identical commands for ~1700 more commands.
This divergence is noise — it does NOT cause the TABLE.BIN deadlock.

## Major Behavioral Divergence: Command #2201 (TABLE.BIN Play)

Up through command #2201, both builds issue identical commands (including
the SCROLL.BIN sector-by-sector read loop: ~100+ Calculate/Get/Delete cycles).

At command #2201:
```
BOTH: Play; Start=0x800762, End=0x80000e, Mode=0x00
      Results: 0080 4101 0100 0811  (disc at FAD 0x0811)
```

**Then they diverge**:

**Production**:
```
Get Sector Number → SEEK (0x0400), 0 sectors
Get Sector Number → SEEK, 0 sectors
... (several more SEEK)
Get Sector Number → PLAY (0x0300), 1 sector
Calculate Actual Size; Count=0x01
Get Actual Size
Get Sector Data; Count=0x0001
End Data Transfer
Delete Sector Data; Count=0x0001
[loop: 14 iterations for 14 TABLE.BIN sectors]
```

**Free build**:
```
[CDB] Starting play end pause.   ← fires IMMEDIATELY
Get Sector Number → PAUSE (0x0100), 14 sectors
Get Buffer Size → 0x0100 0x00ba 0x1800 0x00c8  (186/200 free, 14 occupied)
Get Sector Number → PAUSE, 14 sectors
Get Buffer Size → same
[infinite loop]
```

## Why "Play End Pause" Fires Immediately

TABLE.BIN spans FAD 0x0762 to FAD 0x076F (14 sectors). End FAD = 0x0770.
SCROLL.BIN starts at FAD 0x0770. The game just finished reading SCROLL.BIN
(which ends past FAD 0x0770). The disc is at FAD 0x0811 when TABLE.BIN Play
is issued.

The disc seeks backward to 0x0762 and reads all 14 sectors... but because the
+4 shift means more time passed during the SCDQ poll between SCROLL.BIN and
TABLE.BIN operations, the disc is ALREADY past 0x0770 by the time Play is
issued → immediate play-end-pause → all 14 sectors pre-buffered.

In production: game issues TABLE.BIN Play while disc is still seeking back.
Sectors arrive one-at-a-time during PLAY state. Normal Calculate loop.

## CD_FIX Divergence: Command #67 (NEW BUG)

With `CD_FIX=1`, the widened PAUSE condition triggers during the APROG.BIN
initial load:

```
BOTH up to cmd #67:
  Get and Delete Sector Data; Count=0xC1 → Results: 4180 4101 0100 016c

PRODUCTION cmd #68: End Data Transfer
FREE (CD_FIX):  [nothing — log ends]
```

After `Get and Delete Sector Data` completes, FUN_0603B424 is called again.
The drive is in PAUSE (from play-end-pause after the initial file read).
CD_FIX sees PAUSE + FUN_0603BDAC==5 → fires → sets `ctx[0x12]=0` (DONE) →
FUN_0603B21C exits → `End Data Transfer` is NEVER issued → inconsistent state.

## Stats Summary (2000 frames, SS_DBG_CDB enabled)

| Metric | Production | Free+CD_FIX | Free+SCDQ_FIX |
|--------|-----------|-------------|---------------|
| Total commands | ~5,972 | ~32 | ~7,128 |
| Play commands | 15 | 1 | 5 |
| Calculate commands | 200+ | 0 | ~100 |
| Where divergence | N/A | cmd #68 | cmd #2201 |
| Result | Boots menu | Black screen | Advances to 2000+ frames |

## Key Log File Paths

After running `diag_cdb_commands.py`:
- `.tmp/cdb_cmd_prod.log` — production [CDB] lines
- `.tmp/cdb_cmd_free.log` — free build [CDB] lines
