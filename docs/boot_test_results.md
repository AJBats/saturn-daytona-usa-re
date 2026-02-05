# Additive Boot Test Results

Tracks per-function boot test results. Each DIFF function is tested by adding it
to the L2 baseline (23 functions: 8 L3 + 15 L2) and checking if the game still
boots to the title/attract screen in Mednafen.

**IMPORTANT**: "BOOT" means the game reaches the title screen — it does NOT mean
the function is correct. A 0% match function that boots may:
- Not be called during boot at all
- Be called but return garbage that doesn't crash
- Be called but its bad output isn't used until gameplay

## Baseline
- **L2 build**: 23 functions patched (all L3 byte-perfect + L2 structural matches)
- **Boot status**: OK (title screen with "PRESS START BUTTON")
- **Screenshot**: `build/screenshots/baseline_vanilla.png`

## Test Method
1. Add function to verified list in `build/test_include.txt`
2. Run `patch_binary.py --patch --level 2 --include-funcs build/test_include.txt`
3. Run `test_boot.ps1` (launches Mednafen, skips BIOS, waits 17s, screenshots, kills)
4. Compare screenshot with all 4 methods (phash, histogram, pixels, rmse)
5. Record result below

## Results (Session: 2026-02-05)

### Verified BOOT (35 functions)

| # | Function | Insns | Type | Match% | Result | Notes |
|---|----------|-------|------|--------|--------|-------|
| 1 | FUN_0603316C | 2 | LEAF | 0% | BOOT | |
| 2 | FUN_060336C8 | 2 | LEAF | 0% | BOOT | |
| 3 | FUN_060336F2 | 2 | LEAF | 0% | BOOT | |
| 4 | FUN_06035C6E | 3 | LEAF | 0% | BOOT | |
| 5 | FUN_0602ECCC | 4 | LEAF | 0% | BOOT | |
| 6 | FUN_0603F8EE | 4 | LEAF | 0% | BOOT | |
| 7 | FUN_0603F900 | 4 | LEAF | 0% | BOOT | |
| 8 | FUN_0603F90E | 4 | LEAF | 0% | BOOT | |
| 9 | FUN_0603F91C | 4 | LEAF | 0% | BOOT | |
| 10 | FUN_060409DE | 4 | LEAF | 50% | BOOT | |
| 11 | FUN_060337FC | 5 | LEAF | 40% | BOOT | |
| 12 | FUN_06035C92 | 5 | LEAF | 0% | BOOT | |
| 13 | FUN_0603FA00 | 5 | LEAF | 0% | BOOT | |
| 14 | FUN_0602ECF2 | 6 | LEAF | 0% | BOOT | |
| 15 | FUN_06035438 | 6 | LEAF | 0% | BOOT | |
| 16 | FUN_0601164A | 7 | LEAF | 0% | BOOT | |
| 17 | FUN_06018EC8 | 7 | LEAF | 14% | BOOT | |
| 18 | FUN_0601AEB6 | 7 | LEAF | 0% | BOOT | |
| 19 | FUN_06035C2C | 7 | LEAF | 0% | BOOT | |
| 20 | FUN_0603EF54 | 7 | LEAF | 14% | BOOT | |
| 21 | FUN_0603F1E0 | 7 | LEAF | 14% | BOOT | |
| 22 | FUN_060285E0 | 8 | LEAF | 62% | BOOT | |
| 23 | FUN_06028600 | 8 | LEAF | 62% | BOOT | |
| 24 | FUN_0603F1F0 | 8 | LEAF | 12% | BOOT | |
| 25 | FUN_0602761E | 9 | LEAF | 44% | BOOT | New |
| 26 | FUN_060322E8 | 10 | LEAF | 40% | BOOT | New - in test harness |
| 27 | FUN_0603C05C | 15 | LEAF | 33% | BOOT | New |
| 28 | FUN_060192E8 | 16 | LEAF | 12% | BOOT | New |
| 29 | FUN_0601F87A | 18 | LEAF | 11% | BOOT | New |
| 30 | FUN_0601AE2C | 20 | LEAF | 10% | BOOT | New |
| 31 | FUN_06034560 | 14 | LEAF | 7% | BOOT | New |
| 32 | FUN_0603F8B8 | 11 | LEAF | 9% | BOOT | New |
| 33 | FUN_0603F216 | 10 | LEAF | 10% | BOOT | New |
| 34 | FUN_0603C08C | 10 | LEAF | 0% | BOOT | New |
| 35 | FUN_06041014 | 11 | LEAF | 9% | BOOT | New |

### Failed - CRASH (Black Screen)

| # | Function | Insns | Match% | Notes |
|---|----------|-------|--------|-------|
| 1 | FUN_06042BEE | 6 | 17% | Bisection: was in original list |
| 2 | FUN_06042BAC | 7 | 0% | Bisection: was in original list |
| 3 | FUN_06038520 | 8 | 0% | Bisection: was in original list |
| 4 | FUN_0602D88E | 2 | 0% | Ghidra boundary error |
| 5 | FUN_06012E62 | 4 | 0% | Slot overflow |
| 6 | FUN_06035C08 | 7 | 14% | Missing parameters |
| 7 | FUN_0603F92C | 8 | 25% | Tested new |
| 8 | FUN_0603F9DA | 8 | 0% | Tested new |
| 9 | FUN_06042BBE | 8 | 0% | Tested new |
| 10 | FUN_06028560 | 9 | 78% | Tested new |
| 11 | FUN_0602760C | 9 | 44% | Tested new |
| 12 | FUN_06027630 | 9 | 44% | Tested new |
| 13 | FUN_060394C2 | 7 | 0% | Tested new |
| 14 | FUN_0603BF5A | 12 | 0% | Tested new |
| 15 | FUN_0603EF34 | 11 | 0% | Tested new |
| 16 | FUN_060400B4 | 10 | 0% | Tested new |
| 17 | FUN_0603FFE6 | 16 | 0% | Tested new |
| 18 | FUN_06038A48 | 12 | 8% | Tested new |

### Failed - CORRUPT (Visual Issues)

| # | Function | Insns | Match% | Notes |
|---|----------|-------|--------|-------|
| 1 | FUN_06034FE0 | 7 | 0% | Bisection: was in original list |
| 2 | FUN_06035C1C | 8 | 12% | Bisection: was in original list |
| 3 | FUN_0603F202 | 8 | 0% | Bisection: was in original list |
| 4 | FUN_06033520 | 16 | 44% | Tested new |
| 5 | FUN_06034708 | 11 | 0% | Tested new |
| 6 | FUN_0603C0A0 | 9 | 11% | Tested new |

## Summary
- **35 BOOT** functions confirmed working together (verified 2026-02-05)
- **18 CRASH** functions (black screen)
- **6 CORRUPT** functions (visual issues)
- **59 total tested**

## Bisection Testing

Original 30 "passing" functions were re-verified using bisection testing:

**Found 6 hidden failures:**
- 3 **CRASH**: FUN_06042BEE, FUN_06042BAC, FUN_06038520
- 3 **CORRUPT**: FUN_06034FE0, FUN_06035C1C, FUN_0603F202

**Result: 24 confirmed** from original + 11 new = **35 total verified BOOT**

## Notes
- "BOOT" only means title screen reached — NOT functional correctness
- 0% match functions that boot may not be called during boot sequence
- All 4 comparison methods must pass for BOOT verdict
- Functions may interact; bisection testing required to find hidden failures
- Current verified list: `build/test_include.txt`
