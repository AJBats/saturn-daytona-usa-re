# Boot Testing Dashboard

## Summary

| Status | Count | Description |
|--------|-------|-------------|
| BOOT | 35 | Reaches title screen |
| CRASH | 18 | Black screen |
| CORRUPT | 6 | Visual issues |
| **Total Tested** | **59** | |

## Baseline

- **L2 build**: 23 functions patched (8 L3 byte-perfect + 15 L2 structural)
- **Boot status**: OK (title screen with "PRESS START BUTTON")

## Verified BOOT (35)

| Function | Insns | Type | Match% | Notes |
|----------|-------|------|--------|-------|
| FUN_0601164A | 7 | LEAF | 0% | |
| FUN_06018EC8 | 7 | LEAF | 14% | |
| FUN_0601AE2C | 20 | LEAF | 10% | |
| FUN_0601AEB6 | 7 | LEAF | 0% | |
| FUN_0601F87A | 18 | LEAF | 11% | |
| FUN_060192E8 | 16 | LEAF | 12% | |
| FUN_060285E0 | 8 | LEAF | 62% | |
| FUN_06028600 | 8 | LEAF | 62% | |
| FUN_0602761E | 9 | LEAF | 44% | |
| FUN_0602ECCC | 4 | LEAF | 0% | |
| FUN_0602ECF2 | 6 | LEAF | 0% | |
| FUN_060322E8 | 10 | LEAF | 40% | |
| FUN_0603316C | 2 | LEAF | 0% | |
| FUN_060336C8 | 2 | LEAF | 0% | |
| FUN_060336F2 | 2 | LEAF | 0% | |
| FUN_060337FC | 5 | LEAF | 40% | |
| FUN_06034560 | 14 | LEAF | 7% | |
| FUN_06035438 | 6 | LEAF | 0% | |
| FUN_06035C2C | 7 | LEAF | 0% | |
| FUN_06035C6E | 3 | LEAF | 0% | |
| FUN_06035C92 | 5 | LEAF | 0% | |
| FUN_0603C05C | 15 | LEAF | 33% | |
| FUN_0603C08C | 10 | LEAF | 0% | |
| FUN_0603EF54 | 7 | LEAF | 14% | |
| FUN_0603F1E0 | 7 | LEAF | 14% | |
| FUN_0603F1F0 | 8 | LEAF | 12% | |
| FUN_0603F216 | 10 | LEAF | 10% | |
| FUN_0603F8B8 | 11 | LEAF | 9% | |
| FUN_0603F8EE | 4 | LEAF | 0% | |
| FUN_0603F900 | 4 | LEAF | 0% | |
| FUN_0603F90E | 4 | LEAF | 0% | |
| FUN_0603F91C | 4 | LEAF | 0% | |
| FUN_0603FA00 | 5 | LEAF | 0% | |
| FUN_060409DE | 4 | LEAF | 50% | |
| FUN_06041014 | 11 | LEAF | 9% | |

## CRASH (18)

| Function | Insns | Match% | Notes |
|----------|-------|--------|-------|
| FUN_06012E62 | 4 | 100% | Const pool overflow into next func |
| FUN_0602760C | 9 | 44% | |
| FUN_06027630 | 9 | 44% | |
| FUN_06028560 | 9 | 100% | Crash not code-related |
| FUN_0602D88E | 2 | 0% | Ghidra boundary error |
| FUN_06035C08 | 7 | 62% | ABI mismatch |
| FUN_06038520 | 8 | 56% | extu.w removal, bf.s vs bf |
| FUN_06038A48 | 12 | 8% | |
| FUN_060394C2 | 7 | 0% | |
| FUN_0603BF5A | 12 | 0% | |
| FUN_0603EF34 | 11 | 0% | |
| FUN_0603F92C | 8 | 100% | Crash not code-related |
| FUN_0603F9DA | 8 | 0% | |
| FUN_0603FFE6 | 16 | 0% | |
| FUN_060400B4 | 10 | 0% | |
| FUN_06042BAC | 7 | 78% | Immediate OR optimization |
| FUN_06042BBE | 8 | 0% | |
| FUN_06042BEE | 6 | 86% | Immediate AND optimization |

## CORRUPT (6)

| Function | Insns | Match% | Notes |
|----------|-------|--------|-------|
| FUN_06033520 | 16 | 44% | `in_r2` implicit register param |
| FUN_06034708 | 11 | 0% | Ghidra boundary error |
| FUN_06034FE0 | 7 | 0% | `in_r0`/`in_r1` implicit params |
| FUN_06035C1C | 8 | 12% | strlen - rts delay slot diff |
| FUN_0603C0A0 | 9 | 11% | Constant loading strategy diff |
| FUN_0603F202 | 8 | 0% | Better optimization |

## Reimpl Boot Progress

| Date | Build | Screenshot | Notes |
|------|-------|------------|-------|
| 2026-02-10 | L1 pass complete (no-op stubs) | Black screen | Expected: 729 ASM stubs are no-ops |
| 2026-02-12 | ASM import (630/729 real bytes) | **SEGA logo** | Past black screen — but may be hung at SEGA logo |
| 2026-02-12 | ASM import (675/729 real bytes) | Saturn BIOS menu | "Start Application" shown — disc recognized as game |

### 2026-02-12: ASM Import Progress
- Imported 675 ASM-only functions as raw binary bytes via `__asm__()` blocks
- Binary: 552KB (675 blocks) → now 564KB (675 blocks, named stubs resolved)
- 3 stubs remain: FUN_060302C6 (no aprog.s entry), 2 already implemented elsewhere
- HWRAM expanded from 512KB to 896KB to fit larger binary
- **Concern**: Binary is 43% larger than original (565KB vs 385KB) — may overwrite disc data

---
*Last updated: 2026-02-12*
