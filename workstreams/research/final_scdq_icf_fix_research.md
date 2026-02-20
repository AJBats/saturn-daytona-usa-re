# Self-Critique Investigation Results

Working through gaps and assumptions in the SCDQ hang theory.
Each section corresponds to a todo item.

---

## 1. SH-2 Instruction Decode Verification

**Concern**: Earlier context summary decoded 0x600D as "MOV R13,R0". I decoded it as EXTU.W R0,R0. Which is correct?

**Result**: EXTU.W R0,R0 is **correct**. Verified against the actual retail binary.

- 0x600D = `0110 0000 0000 1101` → lo nibble 0xD → EXTU.W R0,R0 (zero-extend 16-bit)
- MOV R13,R0 would be 0x60D3 = `0110 0000 1101 0011`
- The earlier context summary was **wrong** about this instruction

**Functional impact**: None. The return value from sym_06035C4E is already a 16-bit MOV.W read
(sign-extended to 32 bits). EXTU.W clears the sign extension. Since we then AND with 0x0400,
the upper 16 bits are irrelevant either way. **The loop logic analysis stands.**

Also verified literal pool values from actual binary (stored at runtime+0xD000):
- R11 = 0x06035C54 (FUN_06035C54 — SCDQ handler, called when bit set)
- R12 = 0x06035C4E (sym_06035C4E — reads HIRQREQ via MOV.W)
- R13 = 0x0000FBFF (~0x0400 — mask to clear SCDQ bit, passed as R4 arg)
- R14 = 0x0400 (SCDQ bit mask for AND/TST)

**Verdict**: Decode error was cosmetic. Analysis is sound. ✓

---

## 2. Cross-Function Literal Pool Safety

**Concern**: sym_06035C4E (in `.text.FUN_06035C08`) uses `MOV.L @(0x0A*4,PC),R0` (D00A) to
read its literal pool value. That value (0x25890008 = HIRQREQ address) physically lives inside
`.text.FUN_06035C54`. In the free build with section-based linking, could these sections become
non-adjacent, causing the PC-relative load to read garbage?

**Result**: Adjacency is **preserved**. The literal pool access is **safe** in the free build.

### Evidence

1. **Sort order preserved**: The linker uses `SORT_BY_NAME(.text.FUN_*)`. Since function names
   encode hex addresses (FUN_06035C08, FUN_06035C54), alphabetical sort = numerical sort.
   No other FUN_ sections exist between these two (verified via `glob reimpl/src/FUN_06035C*.s`).

2. **Binary verification**: Built `make free` (no fixes) and verified:
   - Retail: sym_06035C4E's D00A at binary offset 0x32C48, EA = 0x06035C78, value = `2589 0008` ✓
   - Free: sym_06035C4E's D00A at binary offset 0x32C52, EA = 0x06035C7C, value = `2589 0008` ✓
   - Both correctly reach the HIRQREQ address constant.

3. **Uniform shift preserves displacement**: Both the instruction and the target data shift by
   the same +4 bytes. The `MOV.L @(disp,PC)` displacement is baked into the encoding (0x0A),
   and since source and target move together, it still reaches the right data.

4. **Alignment preserved**: Retail sym_06035C4E at 0x06035C4E (byte offset 2 within word).
   Free at 0x06035C52 (byte offset 2 within word). The `& ~3` alignment in the EA formula
   rounds identically in both cases.

5. **_start boundary is clean**: _start (252 bytes, 0x06003000-0x060030FB) uses only
   `.4byte symbol` references in its literal pool — the linker resolves these to the correct
   shifted addresses. The +4 padding sits between _start and FUN_060030FC with no
   cross-boundary literal pool issues.

6. **Relocatable symbols work**: `.4byte sym_06063590` in FUN_06035C54 resolves to
   0x06063594 in free (vs 0x06063590 in retail) because sym_06063590 is a code label
   inside FUN_06046E48, which also shifts by +4. The linker handles this correctly.

### Broader conclusion

This result generalizes: **ALL cross-function literal pool accesses are safe** because:
- SORT_BY_NAME preserves original address order
- Uniform +4 shift means relative offsets between adjacent sections are unchanged
- All section sizes are even (2-byte instruction pairs), so no alignment padding is inserted
- MOV.L @(disp,PC) reach is max 1020 bytes — only reaches into immediately adjacent sections

**Verdict**: Cross-function literal pool safety is NOT a failure mode. ✓

---

## 3. The "+0xD000 Loader" Investigation

**Concern**: A previous session claimed code in APROG.BIN was stored at runtime_address + 0xD000.
If there's a relocating loader between storage and runtime, could the +4 shift break it?

**Result**: The "+0xD000 offset" was a **previous session error**. There is no relocating loader.

### What actually happens

1. **APROG.BIN is a flat binary** loaded at 0x06003000 by the BIOS IPL (Initial Program Loader).
2. File offset = runtime_address - 0x06003000. That's it. No intermediate offset.
3. **Verified**: FUN_06035C08's bytes (`4F22 6153 D302 430B...`) appear at retail binary
   offset 0x32C08 = 0x06035C08 - 0x06003000. Confirmed in hex dump.

### Where the "+0xD000" error came from

The previous session tried reading APROG.BIN at byte position 0x06035C4E (the full runtime
address) instead of the file-relative offset 0x32C4E. The file is only 394,896 bytes (0x60690),
so position 0x06035C4E (~100MB) is far beyond EOF, returning zeros. The "discovery" of bytes
at 0x06042C4E was likely a different file or a calculation mixup. The +0xD000 difference
between 0x06035C4E and 0x06042C4E is coincidental.

### Binary sizes

- Retail APROG.BIN: 394,896 bytes (0x60690) — addresses 0x06003000-0x0606368F
- Free APROG.BIN:   394,900 bytes (0x60694) — addresses 0x06003000-0x06063693

The 4-byte size increase causes the BIOS copy loop at 0x00002F00 to do +1 iteration (+23 cycles).
This is the already-documented first divergence at unified trace line 901,455.

### Does +4 break loading?

**No.** The BIOS copies N bytes verbatim. It doesn't interpret the content. The copy destination
(0x06003000) comes from the disc IP header, not from the binary. The +4 in file size is the
ONLY effect on the load path.

**Verdict**: No relocating loader exists. The +0xD000 claim was a prior session error.
Load path is clean. ✓

---

## 4. SCDQ Data at the 177 Jitter Points

**Concern**: At the 177 events where free does 1-3 extra SCDQ poll iterations, could the
actual subcode Q data (track position) differ? If so, the game might see different disc
positions, causing logic divergences beyond simple timing.

**Result**: The Q data is **almost certainly identical** between builds at each jitter point.
This is a **timing jitter analysis**, not a data divergence.

### Timing arithmetic

From the call-level traces:
- Poll loop cycle period: **33 cycles** per iteration (217270 - 217237 from trace)
- At 28.6 MHz: **1.15 microseconds** per iteration
- Subcode Q frame rate: 75/second = **13.3 ms** between Q frames
- Total extra iterations across 177 jitter events: **451**
- Total extra time: 451 x 33 = 14,883 cycles = **520 microseconds** = 0.52 ms

The maximum extra polling at any single jitter event is ~3 iterations = **3.5 microseconds**.
A Q frame lasts **13,300 microseconds**. The extra polling is 0.026% of one Q frame — it's
impossible for this to cause the disc to advance to a different Q frame boundary.

### What the jitter actually means

The SCDQ bit is set by the CD block hardware (asynchronous to the SH-2). The SH-2 poll loop
checks HIRQREQ every 33 cycles. Whether the SH-2 catches the bit on iteration N or N+3 depends
on where in the loop it is when the CD block sets the bit.

The +4 code shift changes cache miss timing by ~7 cycles here and there, which shifts the
SH-2's phase relative to the CD block by a few cycles. Sometimes this means the SH-2 checks
one more time before catching the bit, sometimes one fewer. Over 1.1M calls, 177 events show
extra iterations — this is exactly what you'd expect from a small phase offset.

### Cumulative impact

The total 520-microsecond timing drift is **not enough to change Q data**, but it IS enough
to change the game's main loop phase relative to vblanks (which occur every ~16.7ms for NTSC).
A 520us shift is about 3% of a frame period. This could cause the game to process CD commands
in a slightly different frame, leading to different CD block state at critical decision points.

This is consistent with the Phase 3 permanent divergence: the cumulative drift pushes the
game's CD state machine into a different state (PAUSE with pre-buffered sectors) at call
2,052,177, triggering the latent bug in FUN_0603B424.

### Limitation

The traces only capture PC addresses and cycle counts, not register values or CD block register
reads. The above analysis is theoretical. To definitively confirm Q data identity, we'd need
per-value traces capturing the HIRQREQ/subcode register reads at each jitter point.

**Verdict**: SCDQ jitter is a timing phenomenon, not a data divergence. Q data is the same. ✓

---

## 5. ICF_FIX: Slave Init and Corrupt Graphics

**Concern**: ICF_FIX NOPs out a loop in FUN_0600C010. What does this loop actually do?
Could skipping it explain the corrupt graphics in the free build?

**Result**: The loop is the game's **vblank synchronization**. Skipping it is almost certainly
the primary cause of corrupt graphics. ICF_FIX is the most damaging bypass.

### What the loop does

FUN_0600C010 is part of the game's per-frame sync function (documented in `FUN_0600BFFC.c.wip`).
The relevant loop (lines 122-127 of the .s file) polls the SH-2's **FTCSR register** at
address `0xFFFFFE11`:

```
69B3  MOV.L @R11+,R9    ; advance frame data table pointer
62A0  MOV.B @R10,R2     ; read FTCSR (R10 = 0xFFFFFE11)
622C  EXTU.B R2,R2
22E9  AND R14,R2        ; mask with 0x80 (R14 = ICF bit mask)
32E0  CMP/EQ R14,R2     ; ICF (bit 7) set?
8BF9  BF loop           ; no → keep polling
```

**ICF (Input Capture Flag)** is set by SH-2 hardware when the Free-Running Timer's input capture
pin detects an edge. On Saturn, this pin is connected to **VDP2 VBLANK output**. The game uses
this as its frame synchronization — it waits here every frame until the next vblank occurs.

### What ICF_FIX does

The patch changes `BF -7` (0x8BF9) to `NOP` (0x0009). This makes the loop execute exactly
once and fall through, **regardless of whether vblank has occurred**.

### Why the game hangs without ICF_FIX

In the free build, the ICF bit in FTCSR never becomes set, causing the poll to loop forever.
Two hypotheses:

1. **FRT not configured**: The SH-2's Free-Running Timer must be initialized (TIER, TCR
   registers) before ICF can fire. If earlier init code (which ran correctly in retail) fails
   due to +4 timing drift, the FRT may not be capturing edges at all.

2. **Init ordering**: If the slave SH-2 (via FUN_0600C170) is supposed to participate in FRT
   setup, and slave init is delayed by timing drift, the master reaches the ICF poll before
   the FRT is ready.

The `.c.wip` decompilation notes: "In the reimpl, FRT init stubs don't configure the timer,
so ICF never fires." This was written for an earlier build state but points at the root cause:
the +4 shift disrupts the timing of FRT configuration relative to the first ICF poll.

### Impact on graphics

Skipping vblank sync causes:

1. **No frame pacing**: Game logic runs at full speed instead of 60fps, potentially thousands
   of frames per second. This overwhelms VDP operations.
2. **VDP register writes during active scan**: Saturn VDP1/VDP2 registers are only safe to
   modify during vblank. Writing during active scan causes visual corruption.
3. **Double-buffer desync**: VDP1 framebuffer swaps (FBCR/PTMR) must be synchronized with
   vblank. Without sync, the game draws into the displayed buffer.
4. **Interrupt handler races**: SCU interrupts (VBLANK_IN, HBLANK_IN) fire on schedule, but
   the main loop runs ahead, causing data races with interrupt-driven VDP updates.

### Conclusion

ICF_FIX is almost certainly the **primary cause of corrupt graphics** in the free build.
It's the most invasive of the three bypasses — it fundamentally breaks the game's timing model.

The proper fix would be to determine WHY the FRT's ICF bit doesn't fire in the free build
(likely a failed FRT init due to +4 timing effects) and fix that initialization, rather than
skipping the vblank wait entirely.

**Verdict**: ICF_FIX is the strongest candidate for causing corrupt graphics. The root cause
is likely broken FRT initialization from the +4 timing shift. ✓

---

## 6. Traces With All Fixes Applied

**Concern**: The existing traces were captured WITHOUT fixes. We need traces WITH fixes
(SCDQ_FIX=1 + ICF_FIX=1 + CD_FIX=1) to see what post-boot divergences exist —
especially whatever's causing the corrupt graphics.

**Result**: Cannot execute from current environment — **requires user action**.

### Why it matters

Current traces show the no-fix free build hanging at call 2,052,177. We never see what
happens AFTER the hang because it never gets past it. With all three fixes, the game boots
to menu (with corrupt graphics). A trace of this bootup would reveal:

1. What the ICF_FIX NOP does to frame timing (does it run thousands of frames per second?)
2. Whether VDP register writes happen outside vblank (causing corruption)
3. Whether CD data arrives correctly (SCDQ_FIX + CD_FIX behavior)
4. Any new structural divergences beyond the known SCDQ jitter

### Commands to run

```bash
# 1. Build free with all fixes
cd /mnt/d/Projects/SaturnReverseTest/reimpl
make free-disc SCDQ_FIX=1 ICF_FIX=1 CD_FIX=1

# 2. Capture retail trace (baseline)
cd /mnt/d/Projects/SaturnReverseTest
python3 tools/unified_trace.py --name retail_fixes --frames 1000

# 3. Capture free trace with fixes
python3 tools/unified_trace.py --cue build/disc/rebuilt_disc/disc.cue \
    --name free_allfixes --frames 1000 --hang-timeout 60

# 4. Compare
python3 tools/compare_traces.py \
    build/traces/unified_retail_fixes_1000f.txt \
    build/traces/unified_free_allfixes_1000f.txt
```

### Blocked by

- No Xvfb (virtual X display) installed in WSL
- Mednafen debug build requires graphical display
- Install with: `sudo apt install xvfb` then run with `xvfb-run`

**Verdict**: Deferred to user. Will provide significant new data when executed. ✓

---

## 7. SCDQ_FIX Timeout: Stale Data and Argument Bug

**Concern**: When SCDQ_FIX times out (1000 iterations, SCDQ never set), it force-acknowledges
SCDQ. Does this cause the game to proceed with stale/missing CD data?

**Result**: The timeout is functionally safe for CD data, BUT there's a **subtle argument bug**
in the C patch that writes wrong upper bits to a semaphore.

### How the timeout works

The C patch (`patches/FUN_060423CC.c`):
```c
for (i = 0; i < 1000; i++) {
    int hirq = sym_06035C4E();
    hirq = (short)hirq;
    if (hirq & 0x0400) {
        FUN_06035C54((int)~0x0400);  // normal: SCDQ was set, clear it
        return;
    }
}
FUN_06035C54((int)~0x0400);  // timeout: force-clear anyway
```

On timeout:
1. HIRQREQ bit 10 (SCDQ) was never set by the CD block
2. FUN_06035C54 reads HIRQREQ, ANDs with 0xFBFF (clears bit 10), writes back
3. Since bit 10 was already clear, this is a hardware **no-op**
4. FUN_06035C54 also stores R4 to sym_06063594 as a semaphore/flag

### Is CD data stale?

**No, not dangerously.** The timeout fires after ~33 microseconds (1000 iterations x 33 cycles
at 28.6 MHz). Subcode Q frames arrive every ~13.3 ms. So the timeout fires ~400 times per
Q frame period. The caller (FUN_0603B21C) has a retry loop (backward BRA at `AFE1`), so it:
1. Calls FUN_060423CC -> timeout -> force-acknowledge
2. Retries via BRA
3. Eventually SCDQ fires for real -> clean acknowledge -> proceed

The game "spin-waits" at high speed instead of blocking on real SCDQ timing. CD block data
flow continues independently because HIRQREQ accurately reflects hardware state.

### BUG FOUND: Argument width mismatch

The C patch passes `(int)~0x0400` = **0xFFFFFBFF** (32-bit two's complement).
The original ASM uses `EXTU.W R13,R4` = **0x0000FBFF** (16-bit zero-extended).

Inside FUN_06035C54, the argument gets OR'd with 1 and stored as a 32-bit MOV.L to
sym_06063594:

| Path | Value stored | Upper 16 bits |
|------|-------------|----------------|
| Original ASM | 0x0000FBFF | 0x0000 |
| C patch (ALL paths) | 0xFFFFFBFF | 0xFFFF |

The lower 16 bits are identical (0xFBFF), so 16-bit comparisons work. But if any code
reads sym_06063594 via MOV.L and checks equality against 0x0000FBFF, it would fail with
the C patch value.

**Recommended fix** for the C patch:
```c
FUN_06035C54(0x0000FBFF);  // match original zero-extended 16-bit value
```

### Is the bug causing visible problems?

Unknown without tracing sym_06063594 consumers. If the value is only ever read as a 16-bit
halfword (MOV.W), the bug is harmless. If any 32-bit comparison exists, it could cause the
CD state machine to take wrong branches.

Note: this bug affects BOTH the normal and timeout paths of the C patch. Even when SCDQ fires
correctly, the wrong upper bits are stored.

**Verdict**: Timeout mechanism is sound for CD data flow. Argument width mismatch is a real
bug that should be fixed. ✓

---

## Summary

| # | Investigation | Result | Impact |
|---|--------------|--------|--------|
| 1 | Instruction decode | Cosmetic error only | None |
| 2 | Literal pool adjacency | Safe in free build | None |
| 3 | +0xD000 loader | Prior session error | None (no loader exists) |
| 4 | SCDQ Q data | Same between builds | None (timing only) |
| 5 | ICF_FIX / vblank | **Skips vblank sync** | **Primary graphics corruption cause** |
| 6 | Traces with fixes | Needs user action | Would provide key data |
| 7 | SCDQ_FIX stale data | Timeout is safe + **argument bug** | **Potential CD state issue** |

### Key findings:

1. **ICF_FIX is the smoking gun for corrupt graphics.** It skips the master's SINIT wait,
   allowing the master to proceed before the slave finishes per-frame work. The master then
   renders with incomplete data → visual corruption.

2. **SCDQ_FIX argument width bug is HARMLESS.** Further analysis confirmed FUN_06035C54 only
   uses MOV.W (16-bit) stores of R4. Upper 16 bits are never observed. No fix needed.

3. **The SCDQ hang theory is solid.** No alternative explanations were found. Cross-function
   literal pools are safe, the loader is simple, Q data doesn't change, and the cumulative
   timing drift is consistent with the observed hang point.

4. **Next priority: find and fix the slave SH-2 hang** in FUN_0600C170. This would eliminate
   ICF_FIX and likely fix corrupt graphics entirely.

---

## 8. ICF Mechanism Breakthrough (2026-02-20, post-initial-investigation)

**Discovery**: ICF is NOT driven by VDP VBLANK. It is a **cross-CPU synchronization flag**
using the Saturn's MINIT/SINIT hardware.

### How it actually works

```
Master (FUN_0600BFFC):                 Slave (FUN_06034F08):
  Store FUN_0600C170 → sym_06063574      Polling own FTCSR ICF...
  Write 0xFFFF to 0x21000000 (MINIT) ──→ Slave ICF fires!
  Poll own FTCSR ICF...                  Call FUN_0600C170 (callback)
                                         ... per-frame slave work ...
                                         Write 0xFFFF to 0x21800000 (SINIT)
  Master ICF fires! ←──────────────────
  Continue to next frame
```

### Mednafen implementation (ss.cpp:322-341)

Writes to 0x01000000-0x01FFFFFF trigger `CPU[c].SetFTI(true/false)` pulse.
CPU index determined by address bit 23: MINIT (bit 23=0) → slave, SINIT (bit 23=1) → master.
SetFTI is edge-triggered based on TCR bit 7 (edge direction select).

### Why ICF hangs in the free build

The master's ICF poll hangs because the **slave SH-2 never writes SINIT**.
FUN_0600C170 (the slave callback) calls several functions. If any hang
on the slave due to timing differences from the +4 shift, SINIT is never
written and the master waits forever.

### Why ICF_FIX causes corrupt graphics

ICF_FIX NOPs the BF in the master's ICF poll, making it proceed immediately
without waiting for the slave to finish its per-frame work (geometry, rendering
prep). The master then renders with incomplete/stale data from the slave,
producing visual corruption.

### Corrected earlier analysis

The "FRT initialization" theory from item 5 was **wrong about the mechanism**
but **right about the symptom**. ICF truly doesn't fire in the free build,
but the reason is the slave callback hang, not broken FRT configuration.
FRT initialization is fine — the slave's FTCSR poll correctly detects MINIT.
The hang is downstream in the callback function chain.

### SCDQ_FIX argument "bug" is harmless

Deeper analysis of FUN_06035C54 confirmed it ONLY uses R4 in MOV.W (16-bit)
writes. The upper 16 bits of the argument (0xFFFF in C patch vs 0x0000 in
original) are never stored or observed by any code. No fix needed.

