# Test Matrix: What Was Tested and What Happened

## Legend

- **Disc**: which binary is in the disc image
- **Mednafen**: which Mednafen build was used
- **Result**: what happened
- **Valid?**: whether the test result is trustworthy

## Historical Tests (Pre-make-disc-bug-fix)

Tests before commit 3f554a1 (which fixed `make disc` silently rebuilding):

| # | Disc | Mednafen | Result | Valid? |
|---|------|----------|--------|--------|
| H1 | "Free+4 (ICF only)" | Stock Win | **Black** (SCDQ hang) | ❌ Disc was production binary due to make disc bug |
| H2 | "Free+4 (ICF+SCDQ fix)" | Stock Win | **Boot to menu** | ❌ Same disc bug |
| H3 | Real Saturn | "Free+4 ICF only" | Claimed boot | ❌ Same disc bug — was testing production |

**None of these tests are valid.** `make disc` silently rebuilt the binary with
production settings. Every "free build" test before commit 3f554a1 was testing
the production binary.

## Validated Tests (Post-make-disc-bug-fix, 2026-02-18)

| # | Disc | Mednafen | Result | Notes |
|---|------|----------|--------|-------|
| 1 | Production | Stock Win | **Boot to attract** | Oracle — always works |
| 2 | Free+4 (ICF only) | Stock Win | **Black** (SCDQ hang) | Mednafen timing issue |
| 3 | Production | Debug – CDB fix | **Boot** | CDB fix Mednafen |
| 4 | Free+4 (ICF only) | Debug – CDB fix | **Black** (PC 0x060423E6) | Still SCDQ hang |
| 5 | Production | Debug + CDB fix | **Boot** | Same as test 3 |
| 6 | Free+4 (ICF only) | Debug + CDB fix | **Black** (frame 701, PC 0x060423EA) | SCDQ hang shifted |

**Notes on tests 4/6**: CDB fix (CDB_Update in CDB_Read) shifted the stuck PC
slightly but did NOT resolve the hang. This confirms the root cause is NOT
just the CDB read timing — it's the PAUSE handler bug in FUN_0603B424.

## 2026-02-19 Tests (This Session)

| # | Build Config | Mednafen | Result | Notes |
|---|-------------|----------|--------|-------|
| A | Free (SCDQ+ICF) | Stock Win | Boot to menu | 12/12 state transitions, confirmed |
| B | Free (ICF only) | Instrumented debug | Advances past frame 2000 | Observer effect: FTI logging etc. masked bug |
| C | Free (ICF only, observer effects removed) | Instrumented debug | Still passes frame 2000 | Remaining observer effects from debug code |
| D | Free (ICF+SCDQ, no CD_FIX) | Instrumented debug | **Works** | Known-good baseline |
| E | Free (ICF+CD_FIX, no SCDQ) | Instrumented debug | **Black screen** | CD_FIX too broad (see 06_cd_fix) |

### Real Saturn Test (2026-02-19)

| Build | Result | Notes |
|-------|--------|-------|
| Free (ICF only, no SCDQ) | **Failed to boot** | Confirmed: SCDQ bug is real, not emulator artifact |

This is the critical data point: the free build with only ICF_FIX=1 fails on
real hardware too. SCDQ not firing in PAUSE state on real hardware → hang.

## Current Known-Working Configuration

```
LDSCRIPT=sawyer_free.ld
ICF_FIX=1     (bypasses secondary SH-2 crash)
SCDQ_FIX=1    (bypasses SCDQ timing/PAUSE issue)
CD_FIX=0      (not used — CD_FIX has secondary bug)
```

**Build**: 394,880 bytes
**Test result**: Boots to attract mode on Mednafen, 12/12 state transitions.
**Real Saturn**: NOT TESTED with this configuration (previous real Saturn test used wrong binary).

## What Needs Testing Next

| Test | Config | What it validates |
|------|--------|------------------|
| Test 1 | SCDQ+ICF, no CD_FIX | Real Saturn boot (confirm bypasses work on HW) |
| Test 2 | ICF+CD_FIX (fixed guard), no SCDQ | Tests CD_FIX concept on Mednafen |
| Test 3 | ICF+CD_FIX (fixed), no SCDQ | Real Saturn — if pass: CD_FIX is the real fix |
| Test 4 | ICF only, Kronos | Cross-validate with different emulator |

## Context: What "Boots to Menu" Means

The game boot sequence (state machine, frame-counted):
1. BIOS → IP.BIN → APROG.BIN loads
2. Initial disc read (authentication area)
3. SCROLL.BIN load (background graphics)
4. TABLE.BIN load (asset manifest)
5. ICF secondary sync (bypassed by ICF_FIX)
6. Texture/model loading
7. Menu display → attract mode

For 12/12 state transitions to be verified, the game must:
- Display Daytona USA title screen
- Cycle through demo states
- Show course selection screens
- Complete a full attract mode cycle

## Binary Size Reference

| Config | Size | Notes |
|--------|------|-------|
| Production (validate passes) | 394,896 bytes | Byte-identical to original |
| Free +4, no patches | 394,900 bytes | +4 bytes from shift pad |
| Free +4, SCDQ_FIX=1 | 394,880 bytes | FUN_060423CC.c is smaller than .s |
| Free +4, SCDQ+ICF | 394,880 bytes | ICF patch adds ~0 net (same .s size) |
| Free +4, CD_FIX=1 | 394,920 bytes | FUN_0603B424.c is larger than .s |
