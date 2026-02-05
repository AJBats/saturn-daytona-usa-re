# Boot Test Automation

Automated visual regression testing for patched Daytona USA Saturn disc images.

## Overview

The boot test pipeline validates that patched disc images boot correctly by:
1. Launching Mednafen with the disc image
2. Skipping the BIOS animation (Enter key)
3. Waiting 17 seconds for the game to reach the title/attract screen
4. Taking a screenshot (F9)
5. Comparing the screenshot against a baseline from the vanilla (unpatched) game

## Key Files

| File | Purpose |
|------|---------|
| `tools/test_boot.ps1` | PowerShell script that launches Mednafen, captures screenshot |
| `tools/compare_screenshot.py` | Python script with 4 image comparison methods |
| `build/screenshots/baseline_vanilla.png` | Golden reference from unpatched vanilla disc |
| `build/screenshots/patched_latest.png` | Latest screenshot from patched disc test |
| `build/screenshots/vanilla_latest.png` | Latest screenshot from vanilla disc test |

## Usage

### Run a boot test
```powershell
# Test patched disc:
powershell -ExecutionPolicy Bypass -File tools\test_boot.ps1 -Cue patched

# Test vanilla disc (to regenerate baseline):
powershell -ExecutionPolicy Bypass -File tools\test_boot.ps1 -Cue vanilla
```

### Compare screenshots
```bash
# Compare patched against vanilla baseline (all 4 methods):
python tools/compare_screenshot.py build/screenshots/patched_latest.png build/screenshots/baseline_vanilla.png --method all

# Single method:
python tools/compare_screenshot.py patched.png baseline.png --method histogram
```

## Comparison Methods

| Method | What it checks | Threshold | Best for |
|--------|---------------|-----------|----------|
| **black_detect** | % of black pixels | 90% = crash | Detecting hard crashes |
| **phash** | Perceptual hash distance | diff ≤ 10 | Overall visual similarity |
| **histogram** | Color distribution correlation | corr ≥ 0.85 | Detecting wrong colors/corruption |
| **pixels** | Specific pixel locations | 3/5 match | Checking known UI elements |
| **rmse** | Root mean square error | RMSE ≤ 25 | Pixel-level accuracy |

## Test Results

**CRITICAL**: ALL 4 comparison methods must pass for a PASS verdict. If ANY method fails, the test is FAIL.

Screenshots are classified as:
- **PASS**: ALL 4 methods pass (phash, histogram, pixels, rmse) — game boots correctly
- **FAIL (black)**: Black screen detected (>90% black pixels) — crash/hang before rendering
- **FAIL (corruption)**: One or more comparison methods fail — graphics corruption or wrong screen

Do NOT manually judge screenshots. The 4-method comparison is the authoritative result:
1. Run `compare_screenshot.py` — if it says PASS, record PASS
2. If it says FAIL, record FAIL and note which methods failed
3. Only look at the screenshot image to classify the failure type (black vs corruption)

## Timing

The 17-second wait after Enter is calibrated to land on a consistent frame in the attract mode sequence. This makes screenshot comparison deterministic.

| Phase | Duration |
|-------|----------|
| Mednafen startup | ~2s |
| BIOS animation (skipped) | - |
| SEGA license screen | ~3s |
| Game loading | ~5s |
| Attract mode start | ~7s |
| **Total** | ~17s |

## Baseline Management

The baseline (`baseline_vanilla.png`) should be regenerated if:
- Timing changes (different frame in attract sequence)
- Mednafen version changes
- Display settings change

To regenerate:
```powershell
powershell -ExecutionPolicy Bypass -File tools\test_boot.ps1 -Cue vanilla
copy build\screenshots\vanilla_latest.png build\screenshots\baseline_vanilla.png
```

## Additive Testing Workflow

For testing individual DIFF functions one at a time:

1. **Prepare test_include.txt**: Write all known-passing functions + one new test function
   ```
   # Known passing functions (18 tested)
   FUN_0603316C
   FUN_060336C8
   ... (all previously passed functions)
   # Testing single new function
   FUN_XXXXXXXX
   ```

2. **Build patched disc**:
   ```bash
   wsl -- python3 tools/patch_binary.py --patch --level 2 --include-funcs build/test_include.txt
   ```

3. **Run boot test**:
   ```powershell
   powershell -ExecutionPolicy Bypass -File tools\test_boot.ps1 -Cue patched
   ```

4. **Compare screenshot** (automated, ALL 4 methods must pass):
   ```bash
   python tools/compare_screenshot.py build/screenshots/patched_latest.png build/screenshots/baseline_vanilla.png
   ```

5. **Record result IMMEDIATELY** in `docs/boot_test_results.md`:
   - If OVERALL: PASS → mark as PASS, add function to known-passing list
   - If OVERALL: FAIL → mark as FAIL, note failure type (black/corruption)

**IMPORTANT**: Update `docs/boot_test_results.md` after EVERY test, not in batches.

## Dependencies

- **Mednafen 1.32.1** in `external_resources/mednafen-1.32.1-win64/`
- **Saturn BIOS** in `C:\Users\albat\.mednafen\firmware\` (mpr-17933.bin, sega_101.bin)
- **Python packages**: `pip install pillow imagehash`
