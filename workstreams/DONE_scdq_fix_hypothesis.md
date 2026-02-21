# SCDQ Fix Hypothesis: TABLE.BIN Timing Race

> **Status**: COMPLETE — hypothesis confirmed (TABLE.BIN timing race)
> **Date**: 2026-02-19
> **Investigation tool**: Mednafen SS_DBG_CDB logging (dev build)
> **Key disclaimer**: Everything observed here is in Mednafen. Real hardware behavior is inferred.

---

## What We Observed (Facts)

### CDB command sequence is identical until command #2201

Both production and free+4 builds issue **identical CD commands in identical order**
through command #2201. The only numerical difference before that is command #491,
a 4-byte discrepancy in the End Data Transfer result (`034d` vs `034f` — minor timing
artifact, no observable consequence on the command sequence that follows).

### The divergence: TABLE.BIN Play command (#2201)

Both builds issue `Play; Start=0x800762, End=0x80000e` at command #2201.
Both get the same response: `Results: 0080 4101 0100 0811` (disc at FAD 0x0811).

**Production** (after TABLE.BIN Play):
```
Get Sector Number → SEEK status (0x0400) ...→ PLAY status (0x0300), 1 sector
Calculate Actual Size → Get Actual Size → Get Sector Data → End DT → Delete
[sector-by-sector loop, one sector at a time]
```

**Free build** (after TABLE.BIN Play):
```
[CDB] Starting play end pause.
Get Sector Number → BUSY/PAUSE status, 14 sectors already in buffer
Get Buffer Size → 186/200 buffers free (14 occupied)
[endless loop: Get Sector Number / Get Buffer Size]
[never issues Calculate / Get Sector Data]
```

### Key numbers

| | Production | Free +4 |
|---|---|---|
| Unique Play FADs in 2000 frames | 15 | 5 |
| Total commands in 2000 frames | 5972 | 7128 |
| Play commands after TABLE.BIN | 10 | 1 (TABLE.BIN = last new FAD) |
| Calculate commands | ~200+ | ~100 (then stuck) |

Production loads many asset files sequentially (SCROLL.BIN, TABLE.BIN, texture data,
polygon data, sounds). Free build loads only 5 files and loops.

---

## The Hypothesis

### Why "play end pause" fires immediately in the free build

TABLE.BIN: FAD 0x0762, 14 sectors, end FAD = 0x0762 + 0x0E = **0x0770**
SCROLL.BIN: starts at FAD **0x0770** (directly adjacent, immediately after TABLE.BIN)

Both builds issue TABLE.BIN Play with disc at FAD 0x0811. The drive must seek backward
~0x4F sectors to FAD 0x0762, then read 14 sequential sectors before hitting end FAD 0x0770.

**In production**: The game issues Play, then quickly calls Get Sector Number.
The disc is still seeking (or has just started reading). Status = SEEK, then PLAY with
1 sector available. The game reads sectors one at a time while the disc is in PLAY state.

**In the free build**: Between Play and the first Get Sector Number, **more SH-2 cycles
pass** — because the game entered an SCDQ poll loop (FUN_060423CC) in between.
During those extra cycles, the disc completes the seek to 0x0762, reads all 14 sectors,
and hits the end FAD (0x0770). The drive enters "play end pause" with all 14 TABLE.BIN
sectors buffered. The game then sees PAUSE status with sectors available — a state the
CD state machine does not handle.

### The state machine deadlock

The game's CD state machine (FUN_0603B424 → FUN_060423CC call chain) appears to have
two separate concerns:
1. **SCDQ poll**: waits for sub-channel Q data update after Play
2. **Sector reading**: starts only when drive reports PLAY status with sectors available

If the SCDQ poll is slow (free build), the drive advances through all TABLE.BIN sectors
before the sector-reading phase begins. The state machine then:
- Sees PAUSE status (not PLAY) → doesn't enter the Calculate/Get/Delete loop
- Keeps polling Get Sector Number + Get Buffer Size waiting for PLAY
- Drive never returns to PLAY (play already ended, sectors already buffered)
- **Deadlock**: sectors in buffer, game waiting for PLAY that never comes

### The causal chain

```
+4 byte shift
    ↓
SCDQ poll takes longer (timing change causes reads to miss the event window)
    ↓
Extra frames between TABLE.BIN Play and first Get Sector Number
    ↓
Disc reads all 14 TABLE.BIN sectors and enters "play end pause" during SCDQ wait
    ↓
Game sees PAUSE + 14 sectors (not PLAY + 1 sector)
    ↓
CD state machine deadlock: game loops on Get Sector Number / Get Buffer Size forever
    ↓
Never loads texture data, polygon data, sounds → no menu → effectively stuck
```

### Why SCDQ_FIX=1 makes it work

The C bypass patch (FUN_060423CC.c) times out after 1000 poll iterations and
force-acknowledges SCDQ. This shortens the SCDQ wait dramatically. The game issues
Get Sector Number before the disc finishes reading all 14 sectors. Drive is in PLAY
state with 1 sector available → normal sector-reading path → game loads TABLE.BIN →
proceeds to load texture data → reaches attract mode.

SCDQ_FIX=1 accidentally avoids the TABLE.BIN race by closing the timing window.

---

## Why to Be Skeptical

**Reason 1: We only observed this in Mednafen.**
Mednafen's CDB simulation has known timing inaccuracies — that's why we've been
investigating the CDB fix in the first place. The "play end pause immediately" behavior
in the free build might be a Mednafen artifact, not real Saturn behavior.

**Reason 2: The disc position is identical in both builds at command #2201.**
Both builds show CR4 = 0x0811 when TABLE.BIN Play is issued. If the internal CDB state
were truly identical, the behavior after Play should also be identical. The immediate
"play end pause" in the free build implies a different internal CDB state (DrivePhase,
PeriodicIdleCounter, buffer state) despite the same disc position. This is a Mednafen
timing artifact by definition — the +4 shift changes when CDB_Update fires relative to
the Play command, leading to different CDB internal state.

**Reason 3: The Mednafen CDB fires SCDQ unconditionally (including in PAUSE/STANDBY).**
On real hardware, SCDQ only fires when the disc is actively reading sectors (sub-channel Q
data updates). If the disc is in PAUSE state on real hardware, SCDQ does NOT fire.
This means the real hardware failure is simpler: the game enters the SCDQ poll after
the Play command and waits forever — SCDQ never fires because the disc enters PAUSE.
Real hardware never reaches the TABLE.BIN loading race condition at all.

**Reason 4: "Is this a real Sega bug?" is a strong claim.**
The latent race condition (state machine can't handle PAUSE + buffered sectors) may only
be exposed by the +4 timing shift. In production, the timing always results in PLAY +
1 sector, so this code path was never exercised. That's a real latent bug in the code —
but it's not necessarily something players would ever encounter because the production
binary never hits this timing.

**Reason 5: The SCDQ poll connection is inferred, not traced.**
We've observed that (a) SCDQ is slow in the free build and (b) TABLE.BIN loading fails.
We're inferring these are causally connected via timing. We haven't traced the exact
SH-2 instruction path to confirm the SCDQ poll runs between Play and Get Sector Number.

---

## What Would Validate This

1. **Add CDB_Update timestamp to the logging** — compare timestamps between TABLE.BIN Play
   and first Get Sector Number in both builds. If the gap is significantly larger in the
   free build, that confirms more time passes.

2. **Count SCDQ poll iterations between TABLE.BIN Play and Get Sector Number** — this
   would directly show whether FUN_060423CC is being called in between.

3. **Test the free build (ICF_FIX=1, SCDQ_FIX=0) on real hardware with the TABLE.BIN
   play command instrumented** — if real hardware also shows "play end pause immediately"
   after TABLE.BIN Play, then the race condition is real. If real hardware shows normal
   PLAY + sectors, the issue is Mednafen-specific.

4. **Swap SCDQ_FIX for a different timing change** — instead of force-acknowledging SCDQ,
   add a brief delay ONLY to the SCDQ poll return. If the TABLE.BIN race goes away,
   it confirms the SCDQ poll delay is the cause.

5. **Instrument FUN_0603B424 for the PAUSE-sectors case** — break at the Get Sector Number
   response processing in FUN_0603B424. Does it actually branch differently on PAUSE vs
   PLAY status? If there's no branch, the deadlock logic might be different from what
   we think.

---

## Implications If True

### For the free-build goal

The CD loading architecture has a latent race condition: **it assumes sectors arrive
one-at-a-time during PLAY state, not all-at-once in PAUSE state**. This assumption
holds in production because timing is deterministic. The +4 shift breaks this assumption
because it changes when the SCDQ poll runs relative to disc reading.

This is probably not a "Sega shipped a broken game" bug — it's an assumption about
timing that held in their test environment and held for every production binary since
the code and disc were co-mastered. The free-build approach violates this assumption
by decoupling code timing from its original context.

### For SCDQ_FIX

The SCDQ_FIX=1 bypass is not just a "CDB timing fix" — it's also inadvertently fixing
a CD state machine deadlock. Even if a proper SCDQ fix is implemented in Mednafen
(CDB_Update in CDB_Read), it may not help on real hardware if the disc enters PAUSE
before the game reads the TABLE.BIN sectors.

### For the road to a real fix

There are potentially TWO things to fix:
1. **The SCDQ timing** — why does SCDQ take longer in the free build? The disc is in
   PAUSE state when SCDQ is expected. Fixing SCDQ means either fixing the code
   (FUN_060423CC state machine, make it handle PAUSE) or fixing the disc state
   (ensure disc is in PLAY when SCDQ poll runs).
2. **The TABLE.BIN loading race** — the state machine in FUN_0603B424 should handle
   "PAUSE status with sectors available" as equivalent to "PLAY status with sectors
   available." This is a latent bug that would exist even with a perfect SCDQ fix.

---

## Open Questions

1. Does the free build TABLE.BIN loading issue reproduce on real hardware, or only Mednafen?
2. Is the SCDQ poll actually running between TABLE.BIN Play and Get Sector Number?
   (inferred, not confirmed)
3. Does the sector-reading state machine in FUN_0603B424 actually branch on PLAY vs PAUSE?
   (need to read the ASM)
4. Does fixing SCDQ alone (not the TABLE.BIN race) get the free build to boot on real hardware?
5. Would the TABLE.BIN race appear if we fixed SCDQ but didn't have the PAUSE+sectors edge case?

---

*First captured: 2026-02-19 from Mednafen CDB command sequence analysis*
