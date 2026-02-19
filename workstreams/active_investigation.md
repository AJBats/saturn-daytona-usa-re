# Free Build Emulator Compatibility

> **Status**: ACTIVE
> **Real hardware**: NOT TESTED — previous "real Saturn" test was production binary (make disc bug)
> **Mednafen**: Two bypasses required — SCDQ_FIX=1 and ICF_FIX=1
> **Build command**: `make free-disc` (one command, correct flags guaranteed)

## The Situation

The free-layout build (+4 byte shift) has NOT been tested on real hardware.
A previous "real Saturn test" was actually testing the production binary due to
the `make disc` rebuild bug (fixed in 3f554a1). On Mednafen, two issues prevent
it from booting without bypasses:

| Issue | Symptom | Bypass | Root Cause |
|-------|---------|--------|------------|
| **SCDQ** | Master hangs polling HIRQ bit 10 | `SCDQ_FIX=1` | Mednafen CDB timing — theory plausible, fix reverted (unvalidated) |
| **ICF** | Slave SH-2 panic at 0x0602829A | `ICF_FIX=1` | Unknown — can't test independently (SCDQ blocks first) |

## SCDQ: What We Know

The SCDQ poll loop (FUN_060423CC) reads HIRQ register (0x25890008) bit 10 in a tight loop.

**CDB fix theory**: `CDB_Read()` doesn't call `CDB_Update()` before returning registers,
so reads can return stale HIRQ. A patch was attempted but reverted — no validated delta
(the test that "confirmed" it was actually testing an unshifted binary due to `make disc` bug).
See `workstreams/scdq_investigation.md` for the patch on standby.

**Real hardware theory**: Real Saturn CD Block registers always return current values —
no emulation layer to serve stale data. SCDQ *should* work on real hardware, but this
is unverified. The free build has never been properly tested on real Saturn.

**Previous false resolution**: A prior session concluded SCDQ was fully resolved, but the
test was flawed — `make disc` silently rebuilt the production binary (no shift). The disc
that booted was actually unshifted production code. Fixed by commit 3f554a1.

### Open Questions

1. Can we design a proper A/B test for the CDB fix? (needs controlled before/after comparison)
2. Is there accumulated timing drift that makes later polls miss their window?
3. Would a more aggressive Mednafen fix (e.g., always-sync on every HIRQ read) resolve it?

## ICF: What We Know

With SCDQ_FIX=1 active, the master SH-2 reaches the ICF synchronization point
(FUN_0600C010) and writes to MINIT (0x01000000), waking the slave. The slave's
callback (FUN_0600C170) crashes, hitting a panic trap at 0x0602829A.

**Bypass**: ICF_FIX=1 NOPs the master's `bf -7` poll loop that waits for SINIT.

**Status**: Cannot determine if this is a real code bug or emulator artifact.
The free build has never been tested on real Saturn, so we don't know if ICF
works on hardware.

### Open Questions

1. Is the ICF crash Mednafen-only (like SCDQ)?
2. What data is wrong in RAM when the slave callback runs?
3. Does the SCDQ_FIX itself change timing enough to cause the ICF crash?

## Strategic Options

1. **Test on real Saturn** — build with `make free-disc`, burn disc, verify on hardware
2. **Revisit CDB fix with proper A/B test** — re-apply patch, design controlled validation
3. **Investigate ICF independently** — build a test that triggers ICF without going through SCDQ
4. **Root-cause both** — full investigation, proper fixes, no bypasses needed

## Log

- 2026-02-18: SCDQ investigation reopened after discovering `make disc` rebuild flaw
- 2026-02-18: "Real Saturn" test invalidated — same make disc bug, was testing production binary
- 2026-02-18: Makefile hardened — `make disc` no longer rebuilds, `make free-disc` added
- 2026-02-18: CDB fix reverted — no validated delta, patch on standby in scdq_investigation.md
