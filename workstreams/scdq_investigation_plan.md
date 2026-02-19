# SCDQ Root Cause Investigation Plan

> **Created**: 2026-02-19
> **Context**: Free+4 build fails on both Mednafen and real Saturn hardware.
> SCDQ poll hangs. Three competing hypotheses need investigation.

## Background

The CDB command log (SS_DBG_CDB) shows both builds execute **identical CD commands**
through command #2201 (TABLE.BIN Play). The only numerical difference before that is
at command #491: `End Data Transfer CR2 = 0x034d` (production) vs `0x034f` (free).
After TABLE.BIN Play, free build gets immediate "play end pause" and deadlocks.

Three open questions:

1. **Is SCDQ pre-armed?** Production may enter FUN_060423CC with SCDQ already set.
   If so, the bug is not a timing race — it's a state failure. Find what arms SCDQ
   before the poll, and why that step fails in the free build.

2. **Is this Mednafen-specific?** Test on a second independent Saturn emulator
   (Yabause/Kronos) with completely different CD Block emulation. If free build
   hangs there too → binary bug. If it works → Mednafen CDB timing artifact.

3. **Does 0x034d vs 0x034f matter?** The 2-unit FAD difference in command #491's
   End Data Transfer result propagates through the state machine. Does it cause
   a wrong state transition that explains the TABLE.BIN deadlock?

---

## Investigation 1: Is SCDQ Pre-Armed?

### The Hypothesis

The SCDQ poll (FUN_060423CC) is not designed to *wait* for SCDQ. It's designed to
*confirm* SCDQ is already set. In production, some preceding CD operation sets
HIRQ_SCDQ before the poll begins. The poll reads HIRQ, sees SCDQ=1, acknowledges,
returns in 1-2 iterations. No timing sensitivity.

In the free build, the arming step fails — SCDQ is NOT already set. The poll enters
a genuine wait. On real hardware: SCDQ never fires (disc in wrong state). On Mednafen:
SCDQ fires eventually but after the disc has advanced past TABLE.BIN's end FAD.

### What to Do

**Step 1: Count SCDQ poll iterations per call.**

Mednafen's SCDQ SET trace already logs when PeriodicIdleCounter fires. Extend it
to also log how many READ iterations happen per FUN_060423CC invocation. Compare:

- Production: if always 1-3 iterations, SCDQ was pre-armed
- Free build: if always 1000+ iterations (near timeout), SCDQ was not set

Add a counter to the trace: on SET event, record iterations since last SET.
This requires extending `CDB_EnableSCDQTrace` to also track READ events but
**only log the count** (not each read — avoids the 10k/frame observer effect).

New trace event: `POLL_EXIT <sh2_ts> <iterations>` — written when SCDQ is finally
seen in a CDB_Read call after a SET event.

**Step 2: Find the CD command that arms SCDQ.**

Look at the CD Block spec (ST-162). Which commands trigger HIRQ_SCDQ as part of
their response? SCDQ fires when:
- Sub-channel Q data is updated (periodic, every ~13ms)
- Certain commands that explicitly trigger SCDQ in their response

Check whether any command in the CDB log immediately BEFORE the SCDQ poll issues
fires SCDQ. Look for HIRQ state changes: the `HIRQ=0x????` field in the command log
will show SCDQ (bit 10 = 0x0400) being set at some point before the poll.

**Step 3: Trace FUN_0603B424 call to FUN_060423CC.**

In the reimpl source, find where FUN_0603B424 calls FUN_060423CC. What CD command
was just processed? What are the conditions for entering the SCDQ poll? This reveals
whether there's a code path that should set SCDQ before calling the poll.

The key: if production has a command that fires SCDQ as part of its normal response,
and the free build's timing means that command completes at a slightly different CD
phase (disc in different state), SCDQ might not be in the response.

**Expected output**: A clear statement of whether FUN_060423CC is entered with
SCDQ pre-armed or entered to genuinely wait.

### Files to Touch

- `mednafen/src/ss/cdb.cpp`: Extend SCDQ trace to log poll exit count
- `tools/diag_scdq_state.py`: Parse new POLL_EXIT events
- `reimpl/src/FUN_0603B424.s`: Read and trace the call chain

---

## Investigation 2: Second Emulator Cross-Reference (Yabause/Kronos)

### The Purpose

Yabause and its fork Kronos have a **completely independent CD Block implementation**,
written from the same hardware spec but by different engineers. If the free build:

- **Also hangs in Yabause** → the bug is in the binary. Both emulators faithfully
  reproduce a real hardware failure. CD Block spec behavior is consistent.
- **Works in Yabause** → the behavior is Mednafen-specific. Mednafen's CDB timing
  diverges from real hardware in a way that exposes timing sensitivity that wouldn't
  exist on the real Saturn.
- **Hangs differently** → the emulators disagree on CD Block behavior in some edge
  case. This pinpoints the exact hardware behavior we need to match.

### What to Do

**Step 1: Get Kronos (modern Yabause fork) source.**

```bash
# In WSL:
git clone https://github.com/FCare/Kronos.git
```

Kronos is the actively maintained fork (last updated 2024). It has better accuracy
than the original Yabause and still has accessible source code for the CD Block.

**Step 2: Build Kronos for WSL.**

Kronos uses CMake. Check for SDL2 dependencies. Build should be:
```bash
mkdir build && cd build
cmake .. -DYAB_PORTS=qt5  # or headless if possible
make -j$(nproc)
```

A headless/libretro build would be ideal for automation testing.

**Step 3: Test both discs.**

Boot production disc → should reach attract mode. ✓
Boot free disc (ICF_FIX=1, SCDQ_FIX=0) → does it hang at SCDQ?

Record: does it black screen? Does it hang at the same frame? Does it get further?

**Step 4: Enable Kronos CD logging if available.**

Yabause/Kronos has similar debug logging infrastructure. Find the equivalent of
`ss_dbg_mask` and enable CD Block logging. Compare command sequences against
our Mednafen log.

**Step 5: Compare CD Block implementations.**

Side-by-side read of Mednafen `cdb.cpp` vs Kronos CD implementation (likely in
`src/cdbase.cpp` or `src/scsp.c` / CD-related files). Key differences to look for:

- How is HIRQ_SCDQ triggered? (What drive states allow it?)
- How does `Play` command handle "already past end FAD"?
- Does Kronos fire SCDQ in PAUSE/STANDBY states like Mednafen does?
- The specific "play end pause immediately" behavior — does Kronos reproduce it?

### Key File to Compare

| Mednafen | Kronos |
|---------|--------|
| `mednafen/src/ss/cdb.cpp` | `src/titan/cdrom/*.c` or similar |
| `PeriodicIdleCounter` SCDQ trigger | Equivalent periodic CD update |
| `StartSeek()` → play end check | Equivalent seek/play logic |

### Expected Output

A clear statement: "In Kronos, the free build [hangs identically / works / hangs differently]."
Plus: specific code differences in the CD Block that explain divergent behavior.

---

## Investigation 3: Does 0x034d vs 0x034f Propagate?

### The Setup

At command #491 (End Data Transfer), both builds diverge by exactly 2 units in CR2:
```
Production: Results: 0103 034d 0000 0000   (368 bytes left)
Free build: Results: 0103 034f 0000 0000   (364 bytes left)
```

CR2 = 0x034d or 0x034f in the End Data Transfer response. Per the Saturn CD spec,
CR2 in the End Data Transfer response is the **highest FAD that was successfully
processed** during the transfer. Values: FAD 845 (production) vs FAD 847 (free) —
a 2-sector difference.

Following this: both builds issue the same Abort File, Initialize (x2), Get CD Status
commands identically. So the 2-unit difference didn't immediately cause a divergence.

But does it accumulate? Does it affect the FAD target of a later Play command? Does
it change which sectors get buffered? Does it explain the "play end pause immediately"
for TABLE.BIN?

### What to Do

**Step 1: Identify what causes the 2-unit difference.**

End Data Transfer CR2 = last FAD processed. The free build processed 2 more sectors
(FAD 847 vs 845) before End Data Transfer was issued. This means either:
  a) The free build read 2 more sectors before the game called End Data Transfer
  b) The game called End Data Transfer at a different point in its sector loop

Since the DT FAD log shows both builds read identical FADs (0x0157 to 0x016b),
the difference must be in WHAT SECTORS were "processed" (buffered into the CD block
sector buffer vs just transferred to host). FAD 845-847 are in TEX_C1.BIN area.

This could indicate the free build's disc was slightly further along (had pre-buffered
2 extra sectors into the CD Block buffer) when End Data Transfer was called. This is
a consequence of timing — the disc kept reading while the SH-2 was doing something
else (possibly the SCDQ poll).

**Step 2: Trace through FUN_0603B424 after End Data Transfer.**

Read FUN_0603B424.s carefully. Find where CR2 (Results[1]) from the End Data Transfer
response is used. Does the state machine compare CR2 against an expected value? If so:
- What is the expected value?
- Does 0x034d pass the check but 0x034f fail (or vice versa)?
- Does a failed check cause the state machine to retry from a different state?

This is a code reading task. FUN_0603B424.s is ~155 bytes. Decode the state machine.

**Step 3: Map the state machine around End Data Transfer.**

The dispatch table at DAT_0603b4c6 contains values 0x00FF, 0x00E9, 0x00FE, 0x00EC,
0x00E8 — these look like CR1 low-byte expected values (command response codes).
The CMP/BT dispatch after the switch case compares against these values.

Map: which dispatch entry handles End Data Transfer (0x06)? What does it do with
the result? Does it check CR2?

**Step 4: Check whether 0x034d vs 0x034f affects the next Play FAD.**

After the full Initialize sequence (commands #493-499), both builds continue identically.
So the 0x034d/0x034f difference doesn't affect the NEXT ~1700 commands. This strongly
suggests it is NOT directly causal.

However: does it affect any buffered data state that matters later, near TABLE.BIN?
Trace through the ~1700 identical commands to see if a CD buffer state difference
from command #491 could manifest at command #2201.

**Step 5: Check whether "play end pause immediately" is FAD-related.**

The TABLE.BIN Play command uses `End=0x80000e` — end FAD = TABLE.BIN start + 14.
Does this End FAD come from a hardcoded pool in APROG.BIN, or from disc data?

If it comes from a pool entry: check whether the pool is correctly relocated in
the free build. Find the instruction in FUN_0603B424 or its callees that loads the
End FAD for the TABLE.BIN Play command.

If it comes from TABLE.BIN's data: TABLE.BIN has essentially no code pointers.
But does it have sector position data that could affect the End FAD calculation?
Check byte offset 0x4C (the only suspicious value we found: `0x06010628`).

### Expected Output

Either:
- "The 0x034d/0x034f difference doesn't affect anything — it's timing noise"
- "CR2 is compared against X in FUN_0603B424, 0x034f fails, causes state Y which
  leads to missing the SCDQ arming step" → genuine bug path to fix

---

## Prioritization

| Priority | Investigation | Why |
|----------|--------------|-----|
| **1** | Is SCDQ Pre-Armed? | Answers the fundamental question. Cheap to test (extend existing trace infrastructure, no new emulator). Directly actionable. |
| **2** | Second Emulator | Validates whether anything we see is real. Without this, everything is "Mednafen says." Could take time to build Kronos. |
| **3** | 0x034d Propagation | Requires reading FUN_0603B424 ASM carefully. Likely to show it's noise (both builds continue identically for 1700 commands after). Low expected yield but should be closed off. |

---

## Investigation 4: CD Code Quarantine (The "Sega LD File" Hypothesis)

### The Hypothesis

Sega's linker script pinned the CD Block subsystem to a fixed address range. During
normal development, adding or modifying gameplay code would shift other functions
around, but the CD Block section always loaded at the same VMA. Engineers could add
functions freely without worrying about CD timing, because CD timing was never touched.

This is a plausible professional engineering practice. If you know a 75KB block is
timing-sensitive, you isolate it. The rest of the binary can move freely around it.

If this is correct: a binary where the CD functions are at their **exact production
addresses** but everything else is shifted should boot correctly. This directly tests
the timing hypothesis without requiring any understanding of the root cause.

### The CD Block Subsystem in Numbers

From `daytona.map` analysis:
- **375 functions**
- **Address range**: `0x06034036` – `0x06047048` (span: ~75KB)
- **Key functions**: FUN_060423CC (SCDQ poll), FUN_0603B21C/B424 (state machine),
  FUN_06035C08/C54 (HIRQ helpers), FUN_06040C98+ (CD command handlers)
- **Predecessor** in layout: non-CD code ends at `0x0603403A` in production
- **No gaps**: `Code bytes = Span bytes` — no internal holes, fully packed

### The Layout Goal

```
Production layout (sawyer.ld):
  0x06003000  startup               (0xFC bytes)
  0x06003100  non-CD FUN_*          (~198KB: 0x06003100–0x06034036)
  0x06034036  CD FUN_*              (~75KB:  0x06034036–0x06047048)
  0x06047048  more non-CD FUN_*     (~up to 0x06063690)

Target quarantine layout (sawyer_cd_frozen.ld):
  0x06003000  startup               (same, no shift)
  0x06003104  non-CD FUN_* [PRE]    (+4 shift: 0x06003104–0x0603403A)
              [4-byte fill/NOP]     (bridges the 4-byte gap)
  0x06034036  CD FUN_*              (FROZEN at production addresses)
  0x06047048  non-CD FUN_* [POST]   (shifted, resumes after CD range)
```

The critical challenge: shifting pre-CD code by +4 makes it end at `0x0603403A`
(4 bytes into the frozen CD zone). A 4-byte bridge is needed to absorb this gap.

### Implementation Approach

**Option A: No pre-CD shift — only shift post-CD code** (simpler, cleaner)

```ld
. = 0x06003000;
.text : {
    *(.text.startup)
    /* Pre-CD: NO shift, production addresses preserved */
    *(SORT_BY_NAME(.text.FUN_[0-9A-F][0-9A-F][0-9A-F][0-9A-F][0-9A-F][0-9A-F][0-9A-F][0-3]_*))
    /* CD Block: frozen at exact production addresses */
    /* (falls here naturally since pre-CD code is unshifted) */
    *(SORT_BY_NAME(.text.FUN_06034*))
    *(SORT_BY_NAME(.text.FUN_06035*))
    ... (all FUN_0603[4-9]* and FUN_0604[0-4]*)
    /* Post-CD: +4 shift reintroduced HERE */
    . = . + 4;
    *(SORT_BY_NAME(.text.FUN_0604[5-9]*))
    *(SORT_BY_NAME(.text.FUN_0605*))
    *(SORT_BY_NAME(.text.FUN_0606*))
}
```

This means:
- Pre-CD code: byte-identical to production (no shift)
- CD code: byte-identical to production (frozen)
- Post-CD code: shifted +4 from production

**Option B: +4 shift everywhere except CD zone** (harder, requires explicit gap fill)

Requires a FILL(0x00) or explicit `. = 0x06034036` snap-back in the linker script.
Risk: linker may refuse to decrease `.` within a section. Would need two separate
`.text` sections, one before the CD range and one after.

### What Each Outcome Means

| Result | Meaning |
|--------|---------|
| **Option A boots to menu** | The CD timing issue is in pre-CD code position. CD code itself is fine at production addresses. Pre-CD shift (+4) is the cause of the bug. |
| **Option A fails same way** | Post-CD code position doesn't matter. The issue is either in CD code itself or something more fundamental. |
| **Option A fails differently** | Post-CD shift breaks something else (new bug). Address the new failure point. |
| **Option B boots to menu** | Pure timing hypothesis confirmed: CD code at exact production addresses is sufficient. Pre-CD code can be freely shifted. This is Sega's model. |
| **Option B fails** | CD timing is not position-dependent. The issue is behavioral (state machine bug, command parameter bug), not address-dependent. |

### Why This Matters for Sega's Workflow

If Option A or B boots, it confirms:
1. Sega could add/remove functions from their codebase freely as long as the CD Block
   section stayed at its fixed address
2. Their linker script likely had an explicit `CDROM_SECTION_BASE = 0x06034036`
   address for the CD subsystem
3. The +4 shift test is artificially producing a timing bug that would never appear
   in normal development because Sega never shifted their CD code
4. **Our actual goal** (moving non-CD code while keeping CD code fixed) is achievable
   and is the correct architecture for a working free build

### Implementation Steps

1. Create `reimpl/sawyer_cd_frozen.ld` based on `sawyer_free.ld`
2. Remove the `+4` padding from before `SORT_BY_NAME(.text.FUN_*)`
3. Add explicit address separation: CD functions placed at their natural production
   addresses (since no pre-CD shift is applied)
4. Add `+4` padding only AFTER the CD range ends
5. Add `make cd-frozen` target: `$(MAKE) LDSCRIPT=sawyer_cd_frozen.ld ICF_FIX=1`
6. Verify via `make validate` subset — CD functions should be byte-identical to
   production at their exact offsets
7. Build disc and test

### Relationship to SCDQ_FIX

If the quarantine build boots WITHOUT SCDQ_FIX=1:
- The CD code's own addresses are what matter (timing confirmed)
- SCDQ_FIX is just compensating for CD code being at wrong addresses

If the quarantine build still needs SCDQ_FIX=1:
- CD code address alone doesn't solve it — there's more to it
- Could be the calling code's address that matters (when in the frame the call happens)

---

## Updated Prioritization

| Priority | Investigation | Rationale |
|----------|--------------|-----------|
| **1** | CD Quarantine (Inv 4) | Fastest decisive test. New linker script only. No instrumentation. Direct binary result. Answers the Sega workflow question definitively. |
| **2** | Is SCDQ Pre-Armed? (Inv 1) | Answers what the bug fundamentally IS. If combined with Inv 4 result, gives the full picture. |
| **3** | Second Emulator (Inv 2) | Validates whether any of this is real. Time-consuming build. Should be running in parallel with 1 and 4. |
| **4** | 0x034d Propagation (Inv 3) | Likely noise. Confirm and close. Low priority. |

---

## Shared Resources Needed

- `reimpl/sawyer_cd_frozen.ld` (new) — for Inv 4
- `tools/diag_scdq_state.py` — extend with POLL_EXIT counter (Inv 1)
- `reimpl/src/FUN_0603B424.s` — decode the CD state machine (Inv 3)
- `workstreams/scdq_fix_hypothesis.md` — update with findings
- Kronos build (new) — for Inv 2

---

*Plan created: 2026-02-19*
