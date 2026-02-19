# Mednafen Debug Tools — Discovery and Usage

> Created: 2026-02-19
> Context: Saturn free-build investigation (SCDQ / ICF / CD state machine bugs)

This documents the Mednafen instrumentation capabilities discovered and built
during the sawyer_free.ld investigation. These go beyond standard Mednafen
debugging and are specific to our debug build fork.

---

## 1. Automation IPC System

**What it is**: A file-based IPC protocol built into our Mednafen fork that
lets external Python scripts control the emulator: advance frames, set
breakpoints, dump memory, trace CPU execution.

**How to use**:
```bash
# Mednafen launched with --automation <ipc_dir>
# Python scripts read/write files in ipc_dir:
#   mednafen_action.txt  — commands written by Python
#   mednafen_ack.txt     — responses written by Mednafen
```

**Key commands** (from `tools/parallel_compare.py` `MednafenInstance`):
| Command | What it does |
|---------|-------------|
| `frame_advance N` | Run N emulated frames, then pause |
| `dump_mem_bin <addr> <size> <path>` | Dump raw memory to file (no CPU hook) |
| `dump_regs_bin <path>` | Dump all SH-2 registers to binary file |
| `pc_trace_frame <path>` | Log every instruction PC for 1 frame |
| `call_trace <path>` | Log BSR/JSR/BSRF calls to text file |
| `breakpoint <addr>` | Set PC breakpoint (hex) |
| `continue` | Resume until next breakpoint |
| `step N` | Step N CPU instructions |
| `scdq_trace <path>` | Enable CDB-internal SCDQ trace (no CPU hook) |
| `watchpoint <addr>` | Break on memory write to address |

**Critical warning**: Commands that enable the CPU debug hook
(`pc_trace_frame`, `call_trace`, `breakpoint`, `step`) cause
`ForceEventUpdates()` to be called on every SH-2 instruction. This fires
all pending emulator events (including CDB PeriodicIdleCounter) on every
instruction, masking timing-sensitive bugs. **Do not use these for timing
diagnostics.**

---

## 2. CDB SCDQ Trace (no CPU hook)

**What it is**: CDB-internal tracing of SCDQ events implemented directly
in `cdb.cpp`. Fires from inside `Drive_Run()` (when PeriodicIdleCounter
hits zero) and optionally from `CDB_Read()`. No CPU hook involved.

**Source**: `mednafen/src/ss/cdb.cpp`
- `CDB_EnableSCDQTrace(const char* path)` — opens trace log file
- `CDB_DisableSCDQTrace(void)` — flushes and closes

**Trace format**:
```
# header line
SET <sh2_ts> <drv_status> <hirq_after>   <- SCDQ fired (PeriodicIdleCounter hit 0)
```

**Drive status values** (from `CurPosInfo.status`):
- 0=BUSY, 1=PAUSE, 2=STANDBY, 3=PLAY, 4=SEEK, 5=SCAN, 6=OPEN

**Activation**: via automation command `scdq_trace /path/to/log.txt`

**Key finding from use**: Showed that SCDQ fires in ALL drive states in
Mednafen (including PAUSE/STANDBY), but on real Saturn hardware SCDQ only
fires when the disc is actively reading sectors. This explains why bugs that
manifest as SCDQ hangs on real hardware may appear to work on Mednafen.

**Observer effect**: If `CDB_Read()` READ logging is also enabled (not the
default), it generates ~10,000 fprintf calls/frame, slowing the emulation
main loop enough to change disc read scheduling — a significant observer
effect. The SET-only trace (default) is safe (~30 events per 20 frames).

---

## 3. SS_DBG_CDB — Built-in Mednafen CD Block Logging

**What it is**: Mednafen's own debug logging system for the Saturn CD Block,
implemented throughout `cdb.cpp`. Logs every command issued, response values,
drive state transitions, and data transfer events.

**How to enable**:

In `mednafen/src/ss/ss.cpp`, line ~1464 (inside `#ifdef MDFN_ENABLE_DEV_BUILD`):
```c
ss_dbg_mask = MDFN_GetSettingMultiM("ss.dbg_mask") | SS_DBG_ERROR | SS_DBG_CDB;
```

Also requires `MDFN_ENABLE_DEV_BUILD` to be defined. In `mednafen/include/config.h`:
```c
#define MDFN_ENABLE_DEV_BUILD 1  // was: /* #undef MDFN_ENABLE_DEV_BUILD */
```

**Output**: Goes to `trio_vprintf` → stdout. In automation mode, stdout is
redirected to `mednafen_stdout.log` in the IPC directory.

**Log format** (examples):
```
[CDB] Command: Play; Start=0x800762, End=0x80000e, Mode=0x00 --- HIRQ=0x0bd4 --- 73057
[CDB]   Results: 0103 034f 0000 0000
[CDB] Starting play end pause.
[CDB] Data transfer ended prematurely at 364 bytes left!
[CDB] DT FAD: 0000016b --- 8 1024
```

**What it reveals**:
- Every CD command and its CR1-CR4 response
- Drive state transitions (play end pause, buffer full pause, seek)
- Data transfer FAD tracking (sector-by-sector progress)
- Timing within-frame (SH-2 timestamp in `--- NNNN` suffix)

**Tool**: `tools/diag_cdb_commands.py` — runs production and free discs in
parallel, captures CDB logs, finds first command sequence divergence.

**Key finding from use**: Both production and free builds issued **identical
CD commands** through command #491 (the initial APROG.BIN load). The first
numerical difference was 2 units in `End Data Transfer` CR2 (FAD 845 vs 847,
a timing artifact). The real behavioral divergence was at command #2201
(TABLE.BIN Play), where the free build entered a PAUSE-state deadlock.

---

## 4. Diagnostic Scripts

### `tools/diag_cdb_commands.py`
Runs prod + free discs in parallel, captures `mednafen_stdout.log` from both,
extracts `[CDB]` lines, finds command sequence divergence. Strips timestamps
for comparison.

```bash
python3 tools/diag_cdb_commands.py --frames 1000
```

**Observer effect**: None — uses only `frame_advance`, no CPU hook.

### `tools/diag_scdq_state.py`
Runs prod + free discs to a target frame, enables SCDQ trace on both,
steps frame-by-frame watching for hang. Analyzes trace for drive state
at SCDQ fires.

```bash
python3 tools/diag_scdq_state.py --trace-start 680 --max-frame 700
```

**Observer effect**: Only if READ trace is enabled (default: SET only = safe).

### `tools/parallel_compare.py`
Original frame-by-frame comparison tool. Advances both discs in lockstep,
comparing CPU register state each frame. Finds first frame where registers
diverge.

**Observer effect**: CPU register dumps use no hook. But the frame-level
comparison still runs normally.

---

## 5. Key Lessons: Observer Effects

### What triggers observer effects

Anything that enables the Mednafen CPU debug hook causes `ForceEventUpdates()`
to fire on every SH-2 instruction. This includes:
- `DBG_SetCPUCallback()` (breakpoints, PC trace, step, call trace)
- Old `FTI` logging (500 stderr writes during boot — removed)
- Old `CANARY` in BusRW_DB_CS0 (one write on first call — removed)
- SS_DBG_CDB READ logging (~10k fprintf/frame — disabled by default)

### What does NOT trigger observer effects
- `frame_advance` (pure SH-2 execution, no hooks)
- `dump_mem_bin` (reads from FastMap, no hooks)
- `dump_regs_bin` (no hooks)
- SET-only SCDQ trace (fires from CDB event system, no CPU hook)
- SS_DBG_CDB command logging (~30-40 log lines/frame, minimal overhead)

### The timing trap
The SCDQ hang bug is timing-sensitive: the +4 code shift changes when
(in absolute SH-2 cycles) the SCDQ poll runs relative to the CDB
PeriodicIdleCounter firing. Any debug tool that fires `ForceEventUpdates()`
on every instruction causes CDB events to fire continuously, making the
timing issue disappear. This is why breakpoints "fixed" the SCDQ hang
during early investigation.

**Rule**: For timing-sensitive diagnosis, only use `frame_advance` +
`dump_mem_bin` + SET-only SCDQ trace. Never use CPU hook-based tools.

---

## 6. MDFN_ENABLE_DEV_BUILD: What It Unlocks

When enabled (via `config.h`), the following become active:

| Feature | File | What it does |
|---------|------|-------------|
| `ss_dbg_mask` runtime | `ss.cpp` | Reads `ss.dbg_mask` setting at startup |
| `SS_DBG_CDB` logging | `cdb.cpp` | ~40 log points for CD commands/state |
| `SS_DBG_WARNING` | throughout | Bus errors, overflows, CDB warnings |
| `DBG_CPUHandler` | `debug.inc` | Full CPU hook infrastructure |
| Memory watchpoints | `ss.cpp` | BusRW write detection in Work RAM-H |
| `CheckDMARace` | `sh7095.inc` | DMA-vs-CPU timing warnings |

**Gotcha**: `MDFN_ENABLE_DEV_BUILD` is set in `config.h` (generated by
`./configure --enable-dev-build`). Changing it there requires recompiling
ALL Mednafen source files (the header is included everywhere). A full
rebuild may take several minutes.

The flag was discovered as `/* #undef MDFN_ENABLE_DEV_BUILD */` in
`mednafen/include/config.h` and was enabled manually:
```c
#define MDFN_ENABLE_DEV_BUILD 1
```

---

## 7. Parallel Execution Pattern

Most diagnostics run two Mednafen instances simultaneously for A/B comparison:

```python
from parallel_compare import MednafenInstance

prod = MednafenInstance("prod", CUE_PROD, ipc_prod_dir)
free = MednafenInstance("free", CUE_FREE, ipc_free_dir)
prod.start()
free.start()

prod.frame_advance(60)   # skip BIOS
free.frame_advance(60)

# Enable CDB trace (no CPU hook)
prod.send(f"scdq_trace {trace_path_wsl}")
free.send(f"scdq_trace {trace_path_wsl}")

# Step frame by frame watching for hang
for f in range(680, 700):
    prod.frame_advance(1)
    try:
        free.frame_advance(1)
    except TimeoutError:
        print(f"Free build hung at frame {f}")
        break
```

Each instance gets an isolated Mednafen home directory under `/tmp/mdfn_home_<name>/`
to avoid config file collisions.

---

*This document covers tools developed during investigation of the Daytona USA*
*Saturn free-layout build SCDQ / ICF / CD state machine bugs (Feb 2026).*
