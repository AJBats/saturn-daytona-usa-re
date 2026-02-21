# Elevation Validation Protocol

Every elevation (rename, L3 conversion, L4 reimplementation) must pass all three
validation classes before it can be committed. No exceptions.

## The Command

```bash
python tools/validate_build.py
```

## What It Checks

1. **Retail binary match** — The retail build must remain byte-identical to the
   original APROG.BIN. This proves the elevation was cosmetic (rename) or
   correctly isolated (reimpl in src/ doesn't affect retail/).

2. **Free build boots to menu** — Build with `make -C reimpl disc`, launch WSL
   Mednafen headlessly, replay frame-precise inputs through attract mode, title
   screen, and mode select. Compare 3 screenshots against golden baselines using
   4 image comparison methods (phash, histogram, pixels, rmse). All must pass.

3. **Free+4shift boots to menu** — Same as above but with `SHIFT=4`. This
   validates relocation correctness — if a pointer wasn't relocated properly,
   the +4 layout will crash or render garbage.

## Why All Three

- Retail match catches broken references, changed section names, stale symbols.
- Free boot catches runtime bugs in reimplemented code.
- Free+4 catches relocation bugs that free (no shift) would mask.

A passing retail match does NOT mean the free build works. A passing free build
does NOT mean +4 shift works. All three are required.

## If Validation Fails

- **Retail fails**: You changed something that affects the binary. Check section
  names, missed references, accidental edits to retail/ files.
- **Free boot fails**: Your reimplementation has a bug. The retail ASM is ground
  truth — diff behavior against it.
- **Free+4 fails but free passes**: Relocation issue. A pointer wasn't relocated
  or was incorrectly relocated. Check constant pools for hardcoded addresses.
