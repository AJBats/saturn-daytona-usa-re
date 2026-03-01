# SDK Signature Matching — Test Results

Tool: `tools/sdk_match.py`
Source: `tools/cygnus-2.7-96Q3/LIB/*.A` (53 archives, 6200 SDK function signatures)
Target: `reimpl/build/APROG.BIN` (394,884 bytes)
Run: `python tools/sdk_match.py reimpl/build/APROG.BIN --map reimpl/build/daytona.map --match-bytes 32 --fuzzy --fuzzy-threshold 0.95 --max-hits 3`

## Results

14 exact matches, 6 fuzzy matches (>=0.95 similarity) with <=3 hit locations.

### Exact Matches (HIGH confidence)

| SDK Function | Library | Address | Our Symbol | Notes |
|---|---|---|---|---|
| MTH_Sin | SEGA_SAT.A | 0x060433D0 | sym_060430CE+0x34A | Sine function |
| MTH_Cos | SEGA_SAT.A | 0x06043410 | sym_060430CE+0x38A | Cosine function |
| MTH_Mul | SEGA_SAT.A | 0x0603D090 | DAT_0603d034+0x58 | Fixed-point multiply |
| MTH_FixedToInt | SEGA_SAT.A | 0x0603D0C0 | DAT_0603d034+0x88 | Fixed→int conversion |
| SINTBL | SEGA_SPR.A | 0x06043480 | sym_060430CE+0x3FA | Sine lookup table (data) |
| tanTbl | SEGA_SAT.A | 0x060436CC | sym_060430CE+0x646 | Tangent lookup table (data) |
| atan_6 | SEGA_SAT.A | 0x06043630 | sym_060430CE+0x5AA | Atan helper |
| atan_10 | SEGA_SAT.A | 0x0604367C | sym_060430CE+0x5F6 | Atan helper |
| atan_14 | SEGA_SAT.A | 0x0604369C | sym_060430CE+0x616 | Atan helper |
| slInnerProduct | SEGA_SGL.A | 0x060284DE | motion_blur_effect+0x20 | Vector inner product |
| divls | SEGA_SAT.A | 0x0602FCD0, 0x0603D0E4 | 2 locations | Long division |
| unitMatrix | LIBSAT/SPR | 0x0602F8CC, 0x0605C6A8 | 2 locations | Identity matrix constant |

### Fuzzy Matches (>=0.95 similarity)

| SDK Function | Library | Address | Similarity | Our Symbol |
|---|---|---|---|---|
| MTH_Atan | SEGA_SAT.A | 0x060435EC | 0.985 | sym_060430CE+0x566 |
| atan_9 | SEGA_SAT.A | 0x0604365C | 0.976 | sym_060430CE+0x5D6 |
| MTH_Product | SEGA_SAT.A | 0x0603D0C8 | 0.973 | DAT_0603d034+0x90 |
| bmSizeTbl | LIBSGL.A | 0x0605A05A | 0.962 | sym_0605A018+0x8A |
| lconv | LIBG.A | 0x06063654 | 0.956 | cdb_wait_scdq+0xC |
| tan_jmp_tbl | SEGA_SGL.A | 0x06033AA4 | 0.956 | sym_06033A8C+0x14 |

### Key Discoveries

**1. SGL Math Library Block (0x060430CE — 0x060437xx)**
Contiguous block of SGL math functions: sin, cos, atan, and their lookup tables.
All within `sym_060430CE` in our symbol map. This entire TU is SGL LIBMTH.

**2. Math Utility Block (0x0603D034 — 0x0603D0E4)**
Fixed-point arithmetic: MTH_Mul, MTH_FixedToInt, MTH_Product, divls.
All within `DAT_0603d034` in our symbol map. This TU is SGL math utilities.

**3. slInnerProduct in motion_blur_effect**
Vector dot product at 0x060284DE, inside what we named `motion_blur_effect`.
This suggests the function is computing dot products for 3D math, consistent
with a motion blur or projection calculation.

**4. Identity Matrix at Two Locations**
unitMatrix (3x3 identity) found at 0x0602F8CC and 0x0605C6A8.
Likely used for initializing rotation/transformation matrices.

### Tuning Notes

- **16-byte sigs**: 79 exact matches but 54 were false positives (common prologues)
- **32-byte sigs**: 17 exact matches, much cleaner. Only Fix48_lsb/blanks/dspl_08 are false positives.
- **--max-hits 3**: Filters out multi-hit false positives effectively.
- **Fuzzy >=0.95**: 6 high-quality near-matches. At 0.92 threshold, 84 fuzzy matches but many are noise.
- Full scan of all 53 archives takes ~3 minutes (objdump extraction dominates).

### False Positive Analysis

At 32 bytes with no hit filter, these are false positives:
- `Fix48_lsb`: 47 hits — common 32-byte sequence in data regions
- `blanks`: 166 hits — runs of 0x20 (space) characters in string data
- `dspl_08`: 11 hits — common SH-2 prologue pattern

The --max-hits filter eliminates all of these.

## Verdict: PASS

Tool correctly identifies SDK functions in the binary. The math library
discovery (MTH_Sin/Cos/Atan/Mul and lookup tables) provides immediate
rename candidates for the sym_060430CE and DAT_0603d034 TUs.
