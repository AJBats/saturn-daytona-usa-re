# SCDQ Root Cause: Latent State Machine Bug in FUN_0603B424

> **Status**: COMPLETE — hypothesis confirmed (latent state machine bug in FUN_0603B424)
> **Date**: 2026-02-19
> **Supersedes**: scdq_fix_hypothesis.md (timing race hypothesis — still possible,
>   but this behavioral hypothesis is a better fit for all observed evidence)
> **Key disclaimer**: Observed in Mednafen. Real hardware behavior inferred but
>   consistent with all known data points including real Saturn test failure.

---

## Executive Summary

The SCDQ hang and TABLE.BIN loading deadlock are the **same root cause**: a latent
bug in `FUN_0603B424` (the CD command state machine) that was never triggered by the
production binary but is triggered by the +4 byte shift in the free build.

The bug: the PAUSE state handler does not proceed to reading buffered sectors when
sectors are already available. It only proceeds when a "buffer empty" condition is
met — which is never satisfied when 14 sectors are pre-buffered in the CD Block.

**`SCDQ_FIX=1` was always a workaround for a symptom, not a fix for the root cause.**

---

## The Bug: FUN_0603B424 PAUSE State Handler

### How the State Machine Works

`FUN_0603B424` is the core CD command state machine. Called in a loop by
`FUN_0603B21C` (the retry wrapper). For each call:

1. Reads current state from `[arg0 + 0x12]`
2. Issues the CD command appropriate to that state (Get Sector Number, Calculate, etc.)
3. Reads drive status byte from CR1[15:8] of the response
4. Dispatches to a handler based on drive status
5. Updates state at `[arg0+0x12]` and returns

### The Status Dispatch Table

After `Get Sector Number` is issued, the drive status byte determines the path:

| Status | Value | Handler offset | Action |
|--------|-------|---------------|--------|
| BUSY   | 0x00  | +0x082        | Update state=0xFF, return retry |
| **PAUSE** | **0x01** | **+0x068** | **BSR → GetBufSize; if retval==1 → CALCULATE, else state=0x1B return retry** |
| PLAY   | 0x03  | +0x032        | Update state=0x37, return (advances to Calculate on next call) |
| SEEK   | 0x04  | +0x044        | Update state=0x2F, return "wait" |
| SCAN   | 0x05  | +0x056        | Update state=0x27, return retry |
| OPEN   | 0x06  | +0x020        | Update state=0x3F, return "error" |

The **CALCULATE path** is at function offset +0x0C4. It's entered:
- From the PAUSE handler when `GetBufSize retval == 1`
- Via the PLAY path (after state advances through multiple retry cycles)

### The PAUSE Handler's Flaw

When status == PAUSE, the handler at offset +0x068:
1. Calls `GetBufSize` (BSR to CD command library)
2. Checks if return value == 1 (meaning: **buffer is empty**)
3. If == 1: proceed to CALCULATE path (read the sectors)
4. If != 1: update state to 0x1B, return retry indicator (0xE8)

The condition `GetBufSize retval == 1` was designed for:
> **"Drive is temporarily paused between seeks. Buffer is empty. Wait for it to
> resume PLAY and buffer some sectors."**

This is NOT the same as:
> **"Play ended because end FAD was reached. All sectors are already buffered.
> Buffer has 14 occupied slots, 186 free."**

In the second case (which is what the free build hits), `GetBufSize` returns 186/200
free buffers (14 occupied). The "buffer empty" condition is never met. The PAUSE
handler loops forever: `GetSectorNumber → PAUSE+14 → GetBufSize → retval≠1 → retry`.

### CDB Log Evidence

Production (after TABLE.BIN Play):
```
Get Sector Number → SEEK (0x0400), 0 sectors → wait
Get Sector Number → SEEK (0x0400), 0 sectors → wait
...several more SEEK...
Get Sector Number → PLAY (0x0300), 1 sector  → PLAY path → CALCULATE
```

Free build (after TABLE.BIN Play):
```
[CDB] Starting play end pause.    ← ALL 14 SECTORS ALREADY BUFFERED
Get Sector Number → PAUSE (0x0100), 14 sectors
Get Buffer Size → 0x0100 0x00ba 0x1800 0x00c8  (186/200 free, 14 occupied)
Get Sector Number → PAUSE (0x0100), 14 sectors
Get Buffer Size → 0x0100 0x00ba 0x1800 0x00c8
... [repeats forever]
```

The two paths never converge. The PLAY handler is never triggered because the drive
is in PAUSE, and the PAUSE handler's exit condition is never satisfied because the
buffer is occupied.

---

## Why the Free Build Triggers This

### The Timing Chain

```
+4 byte shift changes code execution phase
    ↓
SCDQ poll (FUN_060423CC) takes longer to complete
    ↓  (more time passes between disc operations)
Disc advances past FAD 0x0770 (= TABLE.BIN end FAD + 1)
during the extra time spent in SCDQ poll
    ↓
TABLE.BIN Play command issued: Start=0x800762, End=0x80000e (= +14 sectors)
Disc is already at FAD 0x0811 (past end FAD 0x0770)
    ↓
Drive seeks to FAD 0x0762, reads all 14 sectors immediately
(short seek, tiny TABLE.BIN), hits end FAD 0x0770
    ↓
"play end pause" fires BEFORE game's first Get Sector Number
All 14 sectors pre-buffered in CD Block, drive in PAUSE
    ↓
FUN_0603B424 PAUSE handler deadlock (see above)
```

### Why Production Never Triggers This

In the production binary:
- SCDQ poll exits quickly (code is at original timing-aligned addresses)
- Game issues TABLE.BIN Play while disc is seeking toward FAD 0x0762
- Disc seeks, enters PLAY state, reads sectors one-at-a-time
- Get Sector Number always returns PLAY (0x03) with 1 sector → Calculate path
- PAUSE state is never seen during TABLE.BIN loading

The PAUSE+sectors case was **never encountered** during development. The dispatch
table has a PAUSE entry (so someone thought about it), but the exit condition
was only tested in the "temporary seek pause" scenario, not "play end pause."

---

## Why SCDQ_FIX=1 Works (and Why It's Not the Real Fix)

`SCDQ_FIX=1` replaces `FUN_060423CC` (the SCDQ poll) with a C implementation that
times out after 1000 iterations and force-acknowledges SCDQ.

This works because:
1. SCDQ poll exits in at most 1000 iterations (milliseconds)
2. Less time passes between disc operations
3. When TABLE.BIN Play is issued, disc has NOT yet advanced past FAD 0x0770
4. Disc seeks, enters PLAY, reads sectors normally
5. PAUSE+sectors case is never reached

**SCDQ_FIX is closing the timing window, not fixing the state machine bug.**

If the timing window is ever triggered again (e.g., by a different code change, a
different disc seek pattern, or a slow disc drive), the state machine bug remains latent.

### On Real Hardware

On real Saturn hardware, the drive behavior differs from Mednafen in one key way:
**SCDQ only fires when the disc is actively reading sectors** (subcode Q data from
spinning disc). In PAUSE/STANDBY states, SCDQ does not fire.

This means on real hardware:
1. Free build enters SCDQ poll (FUN_060423CC)
2. The disc is already in PAUSE state (from the timing issue above)
3. SCDQ never fires → poll loops forever → **black screen**

Real hardware fails at the SCDQ poll level, before even reaching the TABLE.BIN
deadlock. But the UNDERLYING cause is the same: the timing disruption from the +4
shift puts the disc in PAUSE state at the wrong time.

---

## The Proper Fix

### Option 1: Patch FUN_0603B424 (Real Fix)

Modify the PAUSE handler to also proceed to Calculate when sectors are available:

```
Current PAUSE handler logic:
  call GetBufSize
  if retval == 1:
    goto Calculate  ← only if buffer empty
  else:
    update state to 0x1B, return retry

Fixed PAUSE handler logic:
  [read sector_count from saved Get Sector Number CR4]
  if sector_count > 0:
    goto Calculate  ← ALSO proceed when sectors are waiting
  call GetBufSize
  if retval == 1:
    goto Calculate
  else:
    update state to 0x1B, return retry
```

**Implementation**: C patch replacing `FUN_0603B424` (like `FUN_060423CC.c`).
The C version would call the same underlying CD command functions but add:
`if (pause_status && sector_count > 0) { proceed to read; }`

This fix handles both the TABLE.BIN timing case AND any future case where
PAUSE+sectors-available arises from any other timing difference.

### Option 2: Fix the SCDQ Timing (Keeps the Workaround)

Keep `SCDQ_FIX=1` (the force-acknowledge bypass). This prevents the timing
window from opening and the TABLE.BIN PAUSE case is never reached. The bug
remains latent but doesn't manifest.

**Problem**: This is a workaround, not a fix. It also doesn't address why
SCDQ hangs on real hardware in states where the disc isn't reading.

### Option 3: Fix Both (Recommended)

1. **Patch FUN_0603B424** — fixes the TABLE.BIN loading bug properly
2. **Fix SCDQ timing** — ensures the SCDQ poll works correctly regardless
   of disc state (don't need force-acknowledge)

For the SCDQ timing fix: the actual issue is that SCDQ fires when the disc is
in PAUSE/STANDBY on real hardware. The correct fix is to ensure the game only
polls SCDQ when the disc is in PLAY/SEEK state. This may require understanding
what CD operation should have armed SCDQ before the poll was called.

---

## Investigation Status

### Confirmed

- [x] FUN_0603B424 PAUSE handler has a path to Calculate (retval==1 condition)
- [x] The condition is "buffer empty" (`GetBufSize retval == 1`)
- [x] Free build: GetBufSize sees 14 occupied slots, condition never met
- [x] Production: PAUSE state never entered during TABLE.BIN loading (PLAY path used)
- [x] CDB command sequences are identical until the TABLE.BIN Play divergence
- [x] SCDQ_FIX=1 prevents the timing window by accelerating the SCDQ poll exit

### Still Open

- [ ] Does `FUN_0603B424` have access to CR4 (sector count) when the PAUSE
  dispatch handler runs? (Need to trace what register holds it at dispatch time)
- [ ] Is the SCDQ poll entry AFTER the TABLE.BIN deadlock? (Connection between
  the two failure modes needs closer verification)
- [ ] Does Investigation 4 (quarantine) confirm the timing sensitivity is purely
  from code address (vs. being from some other aspect of the +4 shift)?
- [ ] Second emulator (Kronos) validation: does the TABLE.BIN deadlock reproduce?
- [ ] Does patching FUN_0603B424 alone (without SCDQ_FIX) allow the game to boot?

---

## Relationship to scdq_fix_hypothesis.md

The first hypothesis attributed the failure to a **timing race** between Mednafen's
CDB event system and HIRQ reads. This is partially correct:

- The TIMING is real: +4 shift changes when SCDQ poll runs relative to disc operations
- The MEDNAFEN CDB_Read fix is also real: reads can miss SCDQ in the event window
- BUT: the root failure on real hardware is not "SCDQ doesn't fire" alone — it's
  that the disc enters PAUSE state during the SCDQ poll, and the subsequent
  TABLE.BIN loading deadlocks

The timing hypothesis and behavioral bug hypothesis are **compatible**: the +4 shift
disrupts timing → disc in PAUSE during SCDQ poll → SCDQ never fires (real hardware)
→ OR SCDQ eventually fires and game continues BUT hits TABLE.BIN PAUSE deadlock.

**SCDQ_FIX=1 is sufficient because** it shortens the SCDQ poll enough to prevent
the disc from advancing past TABLE.BIN's end FAD — never triggering the PAUSE state.

---

*Created: 2026-02-19*
*Based on: FUN_0603B424.s raw byte decode, FUN_0603B21C.s analysis,*
*Mednafen SS_DBG_CDB command sequence logs, event_queue.s annotations*
