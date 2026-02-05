# Additive Boot Test Results

Tracks per-function boot test results. Each DIFF function is tested by adding it
to the L2 baseline (23 functions: 8 L3 + 15 L2) and checking if the game still
boots to the title/attract screen in Mednafen.

## Baseline
- **L2 build**: 23 functions patched (all L3 byte-perfect + L2 structural matches)
- **Boot status**: PASS (title screen with "PRESS START BUTTON")
- **Screenshot**: `build/screenshots/baseline_vanilla.png`

## Test Method
1. Write single function name to `build/test_include.txt`
2. Run `patch_binary.py --patch --level 2 --include-funcs build/test_include.txt`
3. Run `test_boot.ps1` (launches Mednafen, skips BIOS, waits 17s, screenshots, kills)
4. Visually verify screenshot shows title screen (not black/crash)
5. Record result below

## Results

| # | Function | Insns | Type | Match% | Result | Notes |
|---|----------|-------|------|--------|--------|-------|
| 1 | FUN_0603316C | 2 | LEAF | 0% | PASS | |
| 2 | FUN_060336C8 | 2 | LEAF | 0% | PASS | |
| 3 | FUN_060336F2 | 2 | LEAF | 0% | PASS | |
| 4 | FUN_06035C6E | 3 | LEAF | 0% | **FAIL** | Black screen crash |
| 5 | FUN_0602ECCC | 4 | LEAF | 0% | PASS | |
| 6 | FUN_0603F8EE | 4 | LEAF | 0% | PASS | |
| 7 | FUN_0603F900 | 4 | LEAF | 0% | PASS | |
| 8 | FUN_0603F90E | 4 | LEAF | 0% | PASS | |
| 9 | FUN_0603F91C | 4 | LEAF | 0% | PASS | |
| 10 | FUN_060409DE | 4 | LEAF | 50% | PASS | |
| 11 | FUN_060337FC | 5 | LEAF | 40% | PASS | |
| 12 | FUN_06035C92 | 5 | LEAF | 0% | PASS | |
| 13 | FUN_0603FA00 | 5 | LEAF | 0% | PASS | |
| 14 | FUN_0602ECF2 | 6 | LEAF | 0% | PASS | |
| 15 | FUN_06035438 | 6 | LEAF | 0% | PASS | |
| 16 | FUN_06042BEE | 6 | LEAF | 17% | PASS | |
| 17 | FUN_0601164A | 7 | LEAF | 0% | PASS | |
| 18 | FUN_06018EC8 | 7 | LEAF | 14% | **FAIL** | Black screen crash |
| 19 | FUN_0601AEB6 | 7 | LEAF | 0% | PASS | |
| 20 | FUN_06034FE0 | 7 | LEAF | 0% | PASS | |
