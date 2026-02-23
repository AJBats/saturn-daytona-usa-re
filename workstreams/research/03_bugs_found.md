# Bugs Found: ICF, SCDQ, CD State Machine

## Bug 1: ICF — Secondary SH-2 Crash (INDEPENDENT, SEPARATE)

**Status**: Known, bypass active (ICF_FIX=1), root cause not fully fixed.

**Symptom**: Primary SH-2 hangs forever at `FUN_0600C010`'s `bf -7` poll loop
waiting for the secondary SH-2 to write SINIT (0x21800000 = primary FRT input
capture). The secondary never writes it.

**Why**: Secondary SH-2 is activated via SSHON command. It enters `FUN_06034F08`
polling its own FTCSR for ICF. Primary writes MINIT (0x01000000) to wake secondary.
Secondary detects ICF, calls callback `FUN_0600C170`. This callback's call chain
hits incorrect data state and crashes into the `SETT; BT $` panic trap at
`0x06028296`. Secondary never writes SINIT back.

**Evidence from Mednafen FTI logging**:
```
FTI: addr=01000000 target_cpu=1 master_PC=0600C0F0 slave_PC=06034F3E  ← primary writes MINIT ✓
FTI: addr=01000000 target_cpu=1 master_PC=0600C0F0 slave_PC=0602829A  ← secondary stuck at panic (×178)
# No addr=01800000 (secondary SINIT write) ever appears
```

**Bypass**: `ICF_FIX=1` NOPs the `bf -7` at `FUN_0600C010.s` line ~127.
In patches/FUN_0600C010.s: `0x8B, 0xF9` → `0x00, 0x09` (bf -7 → nop).

**Real root cause**: The init functions called by `FUN_0600C170`'s call chain
don't set up RAM correctly. Which specific init functions are responsible has
not been identified. **This is unresolved.**

**This is UNRELATED to SCDQ and CD bugs.**

---

## Bug 2: SCDQ Timing (Mednafen-specific, real hardware is different)

**Status**: Bypassed by SCDQ_FIX=1. Root cause is Bug 3 (CD state machine).

**Symptom in Mednafen**: Free build hangs at `FUN_060423CC` (SCDQ poll loop).
The +4 byte shift changes the phase of code execution relative to Mednafen's
CDB event system. The SCDQ poll reads HIRQ at a slightly different time,
sometimes missing the window when SCDQ_bit is set.

**Symptom on real hardware**: SCDQ never fires because the disc is in PAUSE
state when the SCDQ poll runs. On real Saturn, SCDQ only fires during PLAY/SEEK
(active disc reading). PAUSE → no sub-Q updates → infinite poll → black screen.

**Why the disc is in PAUSE when SCDQ is polled**: This is the downstream effect
of Bug 3. The CD state machine's TABLE.BIN loading fails (Bug 3), causing
excessive time in the retry loop. During this time, the disc advances past
TABLE.BIN's end FAD, enters PAUSE. Subsequent SCDQ polls find the disc in PAUSE.

**SCDQ_FIX=1**: Replaces `FUN_060423CC` with a C timeout (max 1000 iterations).
This shortens the SCDQ wait, preventing the disc from advancing past TABLE.BIN's
end FAD. Avoids Bug 3 by keeping the timing window closed.

**The fix is a workaround**: It patches the symptom (SCDQ poll timing) not
the cause (CD state machine not handling PAUSE+sectors case). See Bug 3.

---

## Bug 3: CD State Machine PAUSE Handler — THE ROOT CAUSE

**Status**: Identified, partially implemented fix (CD_FIX=1) but has a
secondary bug. Needs more targeted implementation.

**Location**: `FUN_0603B424` — the CD command state machine.
Called in a loop by `FUN_0603B21C` (retry wrapper).

### What FUN_0603B424 Does

After issuing a Get Sector Number command, it reads drive status from CR1[15:8]
and dispatches to a handler:

| Status | Value | Handler | Action |
|--------|-------|---------|--------|
| BUSY   | 0x00  | +0x082  | state=0xFF, return retry |
| **PAUSE** | **0x01** | **+0x068** | **BSR→GetBufSize; if retval==1 goto CALCULATE else state=0x1B retry** |
| PLAY   | 0x03  | +0x032  | state=0x37, return (advances toward Calculate) |
| SEEK   | 0x04  | +0x044  | state=0x2F, return wait |
| SCAN   | 0x05  | +0x056  | state=0x27, retry |
| OPEN   | 0x06  | +0x020  | state=0x3F, error |
| STANDBY| 0x02  | (default path) | FUN_0603BDAC==5 → CALCULATE |

**Calculate path entry** at function offset +0x0C4:
calls sym_0603F9F2/F9F6 (Calculate Actual Size / Get Actual Size),
then FUN_0603AFD0, sets state=0, returns.

### The PAUSE Handler Bug

The PAUSE handler calls GetBufSize. If `retval == 1` (original code: branch
to Calculate at +0xC4). If `retval != 1` (retry loop, state=0x1B).

**The condition `GetBufSize retval == 1` was designed for**:
"Drive temporarily paused between seeks. Buffer is empty. Wait for PLAY."

**The case it fails for**:
"Play ended because end FAD reached. ALL sectors already pre-buffered.
Buffer has 14 occupied slots → GetBufSize retval != 1 → eternal retry loop."

### Why Production Never Hits This

In production, TABLE.BIN sectors arrive one-at-a-time during PLAY state.
The PLAY handler processes them via Calculate loop. The drive never enters
PAUSE state with sectors still buffered during TABLE.BIN loading.

### The Timing Chain That Causes the Bug

```
+4 shift changes execution phase
  → SCDQ poll runs slightly longer (timing window changes)
  → Extra SH-2 cycles pass between SCROLL.BIN read and TABLE.BIN Play cmd
  → Disc advances past FAD 0x0770 (TABLE.BIN end FAD)
  → TABLE.BIN Play issued: Start=0x0762, End=FAD+14 sectors = 0x0770
  → Disc already past end FAD → "play end pause" immediately
  → All 14 sectors pre-buffered → GetBufSize retval != 1 → PAUSE handler loops
  → Game retries forever → SCDQ poll never called / called in PAUSE context
  → Black screen (real hw: SCDQ never fires in PAUSE)
               (Mednafen: SCDQ fires anyway but timing creates loop)
```

### The CDB Log Evidence

From `tools/diag_cdb_commands.py` (2000 frames):
```
Production (after TABLE.BIN Play):
  Get Sector Number → SEEK (0x0400), 0 sectors → wait
  ...several more SEEK...
  Get Sector Number → PLAY (0x0300), 1 sector → Calculate path ✓

Free build (after TABLE.BIN Play):
  [CDB] Starting play end pause.         ← all 14 sectors already buffered
  Get Sector Number → PAUSE (0x0100), 14 sectors
  Get Buffer Size → 186/200 free (14 occupied) → retval != 1
  Get Sector Number → PAUSE, 14 sectors
  Get Buffer Size → same
  [loops forever]
```

### The CD_FIX Attempt (patches/FUN_0603B424.c)

The C patch widened the Calculate gate condition from `status == 2` to
`status == 2 || status == 1`. This allows the PAUSE case to proceed to
the Calculate path when `FUN_0603BDAC` returns 5.

**However, it has a secondary bug**: The widened condition also triggers
during the NORMAL APROG.BIN initial file load (command #67 in the CDB log).
After `Get and Delete Sector Data Count=0xC1`, FUN_0603B424 is called again
for `End Data Transfer`. The CD_FIX fires (PAUSE + sectors), sets `ctx[0x12]=0`
(DONE state), returns. The retry loop exits without issuing `End Data Transfer`.
The initial load is left in an inconsistent state → black screen.

### The Correct Fix

The PAUSE handler fix needs a guard that distinguishes:
- **TABLE.BIN "play end pause"**: all sectors buffered before first Get Sector Number
- **Normal mid-transfer PAUSE**: PAUSE that occurs during an in-progress transfer

The distinguishing factor is the `ctx[0x12]` state byte. When the PAUSE handler
should proceed to Calculate, the state is at a specific "wait for sectors" value
in the TABLE.BIN loading phase. When the state is at the "confirm transfer complete"
phase (before `End Data Transfer`), the PAUSE handler should NOT fire the fix.

**Next step**: Read `ctx[0x12]` value when the PAUSE handler fires for the TABLE.BIN
case vs the APROG.BIN case. Add `if (ctx[0x12] == SPECIFIC_STATE)` guard.

---

## Combined Status

| Bug | Status | Fix | Notes |
|-----|--------|-----|-------|
| ICF secondary crash | Active bypass | ICF_FIX=1 | Root cause unknown, separate from CD bugs |
| SCDQ timing (Mednafen) | Active bypass | SCDQ_FIX=1 | Workaround; root cause is Bug 3 |
| SCDQ hang (real hw) | Active bypass | SCDQ_FIX=1 | Bypass closes timing window; Bug 3 is real |
| CD PAUSE handler | Identified | CD_FIX=1 attempted | Guard condition too broad; needs ctx[0x12] check |

**Known working configuration**: `LDSCRIPT=sawyer_free.ld ICF_FIX=1 SCDQ_FIX=1 CD_FIX=0`
→ Boots to Mednafen menu with 12/12 state transitions verified.
→ NOT tested on real Saturn with correct disc (previous test used wrong binary).
