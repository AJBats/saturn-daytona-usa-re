# Elevation Validation Protocol

Every elevation (rename, L3 conversion, L4 reimplementation) must pass all three
validation classes before it can be committed. No exceptions.

## Quick Path

Run all three tests with one command:

```bash
python tools/validate_build.py
```

## Manual Steps (what validate_build.py does)

### Test 1: Retail binary match

```bash
make -C reimpl retail-validate
```

Must print `PASS: retail byte-identical to original`. The retail build (sega.ld)
must remain byte-identical to the original APROG.BIN. This proves the elevation
was cosmetic (rename) or correctly isolated (reimpl in src/ doesn't affect retail/).

### Test 2: Free build match

```bash
make -C reimpl validate
```

Must print `PASS: free build byte-identical to original`. The free-layout build
(free.ld) must remain byte-identical to the original APROG.BIN. This proves the
src/ overrides produce identical code to the retail/ originals.

### Test 3: Free+4shift golden match + boot test

```bash
make -C reimpl SHIFT=4 MODS=1
```

The shifted binary (`reimpl/build/APROG.BIN`) must byte-match the golden shifted
binary (`build/golden_free4_APROG.BIN`). Then inject and boot-test:

```bash
make -C reimpl SHIFT=4 MODS=1 disc
python tools/test_boot_auto.py rebuilt
```

The boot test takes 3 screenshots (attract, title, menu) and compares against
golden baselines. Title uses all 4 comparison methods (phash, histogram, pixels,
rmse). Attract and menu use histogram-only (attract varies due to MODS=1 CD
timing changes; menu has ARCADE MODE text blink). Must print `OVERALL: PASS`.

This validates relocation correctness — if a pointer wasn't relocated properly,
the +4 layout will crash or render garbage.

## Why All Three

- Retail match catches broken references, changed section names, stale symbols.
- Free match catches src/ override bugs that don't affect retail/.
- Free+4 catches relocation bugs that free (no shift) would mask.

A passing retail match does NOT mean the free build works. A passing free build
does NOT mean +4 shift works. All three are required.

## If Validation Fails

- **Retail fails**: You changed something that affects the binary. Check section
  names, missed references, accidental edits to retail/ files.
- **Free fails**: Your src/ override doesn't byte-match. Check section layout,
  assembler encoding differences, or Makefile override logic.
- **Free+4 fails but free passes**: Relocation issue. A pointer wasn't relocated
  or was incorrectly relocated. Check constant pools for hardcoded addresses.
