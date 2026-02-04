# Function Catalog

Compilation and codegen status for 886 decompiled C sources against original SH-2 binary.
Generated from `catalog_raw.tsv`. See `docs/verification_results.md` for detailed diffs.

## Summary Dashboard

### Overall Status

| Category | Count |
|----------|------:|
| PASS (exact match) | 39 |
| FAIL (compiles, asm differs) | 479 |
| Compile error | 349 |
| No expected asm | 19 |
| **Total sources** | **886** |

### Coverage

| Metric | Count |
|--------|------:|
| C sources (Ghidra decompiled) | 886 |
| Symbols in aprog_syms.txt | 1234 |
| Functions in both src and syms | 505 |
| Compilable (PASS + FAIL) | 518 |
| PASS (exact instruction match) | 39 |
| Coverage gap (syms without src) | 729 |

### FAIL Breakdown by Delta

| Delta bucket | Count |
|-------------|------:|
| delta = 0 (opcode diffs only) | 45 |
| delta = +/-1 | 65 |
| delta 2-5 | 47 |
| delta 6-15 | 69 |
| delta 16+ | 104 |
| delta -2 to -5 | 70 |
| delta -6 to -15 | 35 |
| delta < -15 | 44 |

### FAIL by Codegen Category

| Category | Count | Description |
|----------|------:|-------------|
| call_encoding | 194 | BSR/JSR encoding, jmp vs bra, linker stubs |
| delay_slot | 156 | Different delay slot fill or branch scheduling |
| addressing | 35 | Displacement addressing mode differences |
| multiply | 32 | mulsi3 library call vs shift optimization |
| mixed | 16 | Multiple unrelated differences |
| sign_ext | 15 | Extra/missing sign extension (exts.w) |
| scheduling | 14 | Instruction reordering (same opcodes) |
| 1-swap | 13 | Single instruction pair swap |
| comparison | 4 | Different comparison encoding (cmp/hi vs cmp/gt) |

### Compile Errors by Category

| Category | Count |
|----------|------:|
| void_value | 247 |
| invalid_deref | 44 |
| cc1_crash | 35 |
| bad_subscript | 9 |
| parse_error | 8 |
| undeclared | 5 |
| other | 1 |

## PASS Functions (39)

Exact instruction-stream match with original binary. Sorted by instruction count.

| Function | Insns |
|----------|------:|
| FUN_0600D266 | 2 |
| FUN_0601E0DE | 2 |
| FUN_0601F8BC | 2 |
| FUN_0603F9F2 | 2 |
| FUN_0603F9F6 | 2 |
| FUN_060401E4 | 2 |
| FUN_0602754C | 3 |
| FUN_06035C48 | 3 |
| FUN_06035C4E | 3 |
| FUN_06035C6E | 3 |
| FUN_06012E00 | 4 |
| FUN_06012E62 | 4 |
| FUN_06012E7C | 4 |
| FUN_06012E84 | 4 |
| FUN_06012EBC | 4 |
| FUN_06012EC4 | 4 |
| FUN_06012EDC | 4 |
| FUN_06012F00 | 4 |
| FUN_06012F10 | 4 |
| FUN_06012F20 | 4 |
| FUN_06012F50 | 4 |
| FUN_06012F58 | 4 |
| FUN_06012F60 | 4 |
| FUN_060409DE | 4 |
| FUN_06041884 | 4 |
| FUN_06026DF8 | 5 |
| FUN_060349B6 | 7 |
| FUN_0603F92C | 8 |
| FUN_060058FA | 9 |
| FUN_06012E6A | 9 |
| FUN_06028560 | 9 |
| FUN_0603F4B0 | 9 |
| FUN_0600DE40 | 10 |
| FUN_060322E8 | 10 |
| FUN_06033504 | 10 |
| FUN_0603850C | 10 |
| FUN_0602853E | 12 |
| FUN_0600DE54 | 14 |
| FUN_0600F870 | 20 |

## Close Matches: delta=0 (45)

Same instruction count as original but opcode differences (scheduling, register allocation, etc.).
Sorted by diff line count ascending (closest to matching first).

| Function | Insns | Diff lines | Category |
|----------|------:|----------:|----------|
| FUN_0601164A | 7 | 2 | 1-swap |
| FUN_060192CA | 15 | 2 | 1-swap |
| FUN_06026E0C | 17 | 2 | 1-swap |
| FUN_060270D0 | 17 | 2 | 1-swap |
| FUN_06027344 | 9 | 2 | 1-swap |
| FUN_06027348 | 7 | 2 | 1-swap |
| FUN_060285E0 | 8 | 2 | 1-swap |
| FUN_06028600 | 8 | 2 | 1-swap |
| FUN_06035C80 | 9 | 2 | 1-swap |
| FUN_0603C05C | 15 | 2 | 1-swap |
| FUN_0603F3DA | 14 | 2 | 1-swap |
| FUN_0603F4CC | 10 | 2 | 1-swap |
| FUN_06040954 | 8 | 2 | 1-swap |
| FUN_06005174 | 18 | 4 | scheduling |
| FUN_06018EC8 | 7 | 4 | scheduling |
| FUN_06019324 | 29 | 4 | scheduling |
| FUN_0603C0A0 | 9 | 4 | scheduling |
| FUN_0603F8B8 | 11 | 4 | scheduling |
| FUN_06011494 | 12 | 6 | scheduling |
| FUN_0601FD20 | 20 | 6 | scheduling |
| FUN_06021128 | 23 | 6 | scheduling |
| FUN_0602760C | 9 | 6 | scheduling |
| FUN_0602761E | 9 | 6 | scheduling |
| FUN_06027630 | 9 | 6 | scheduling |
| FUN_060280C4 | 21 | 6 | scheduling |
| FUN_060281B8 | 19 | 6 | scheduling |
| FUN_06035C1C | 8 | 6 | scheduling |
| FUN_0601938C | 28 | 8 | addressing |
| FUN_0603F4E0 | 16 | 8 | call_encoding |
| FUN_0603F500 | 16 | 8 | call_encoding |
| FUN_060122F4 | 25 | 10 | comparison |
| FUN_0601F87A | 18 | 10 | sign_ext |
| FUN_06033520 | 19 | 12 | addressing |
| FUN_0600C970 | 18 | 14 | delay_slot |
| FUN_0600DF66 | 22 | 16 | call_encoding |
| FUN_0601AB8C | 29 | 16 | multiply |
| FUN_0601F900 | 27 | 20 | call_encoding |
| FUN_0603B878 | 24 | 20 | delay_slot |
| FUN_06040E88 | 25 | 20 | delay_slot |
| FUN_0603A72C | 29 | 28 | delay_slot |
| FUN_06041128 | 38 | 28 | delay_slot |
| FUN_060084CA | 74 | 30 | delay_slot |
| FUN_06010D94 | 133 | 54 | call_encoding |
| FUN_0602F71C | 64 | 78 | delay_slot |
| FUN_0600D12C | 99 | 98 | delay_slot |

## Near Matches: delta=+/-1 (65)

Off by a single instruction. Sorted by function name.

| Function | Ours | Orig | Delta | Category |
|----------|-----:|-----:|------:|----------|
| FUN_0600338C | 44 | 45 | -1 | call_encoding |
| FUN_060038D4 | 71 | 70 | 1 | call_encoding |
| FUN_060054EA | 11 | 12 | -1 | addressing |
| FUN_0600553C | 49 | 50 | -1 | call_encoding |
| FUN_0600A140 | 44 | 45 | -1 | addressing |
| FUN_0600A5B2 | 28 | 27 | 1 | call_encoding |
| FUN_0600D8A4 | 57 | 58 | -1 | delay_slot |
| FUN_0600E410 | 36 | 35 | 1 | multiply |
| FUN_06010238 | 29 | 30 | -1 | delay_slot |
| FUN_060102A8 | 34 | 33 | 1 | delay_slot |
| FUN_06010A5C | 22 | 21 | 1 | call_encoding |
| FUN_06011E7C | 29 | 28 | 1 | call_encoding |
| FUN_06011EB4 | 38 | 37 | 1 | call_encoding |
| FUN_0601209E | 19 | 18 | 1 | addressing |
| FUN_06012400 | 27 | 26 | 1 | call_encoding |
| FUN_0601416C | 82 | 83 | -1 | call_encoding |
| FUN_060148FC | 25 | 24 | 1 | addressing |
| FUN_0601492C | 25 | 24 | 1 | addressing |
| FUN_06014994 | 25 | 24 | 1 | addressing |
| FUN_060149CC | 9 | 10 | -1 | addressing |
| FUN_060149E0 | 9 | 10 | -1 | addressing |
| FUN_06014A42 | 5 | 6 | -1 | addressing |
| FUN_06018E70 | 11 | 12 | -1 | mixed |
| FUN_060192B4 | 10 | 11 | -1 | delay_slot |
| FUN_060198E0 | 24 | 23 | 1 | call_encoding |
| FUN_0601D014 | 34 | 33 | 1 | addressing |
| FUN_0601D074 | 37 | 36 | 1 | addressing |
| FUN_0601D2DC | 72 | 71 | 1 | call_encoding |
| FUN_0601DB84 | 14 | 13 | 1 | delay_slot |
| FUN_06020366 | 82 | 83 | -1 | call_encoding |
| FUN_06027358 | 16 | 15 | 1 | multiply |
| FUN_0602755C | 9 | 10 | -1 | multiply |
| FUN_0602E5E4 | 13 | 12 | 1 | addressing |
| FUN_06033AAC | 105 | 106 | -1 | call_encoding |
| FUN_0603446C | 14 | 15 | -1 | delay_slot |
| FUN_06034560 | 13 | 14 | -1 | multiply |
| FUN_06034708 | 11 | 12 | -1 | call_encoding |
| FUN_060347A8 | 63 | 62 | 1 | delay_slot |
| FUN_06034C48 | 15 | 16 | -1 | mixed |
| FUN_06034DEA | 24 | 23 | 1 | call_encoding |
| FUN_06035438 | 6 | 7 | -1 | delay_slot |
| FUN_060359DA | 6 | 5 | 1 | addressing |
| FUN_06037618 | 37 | 36 | 1 | delay_slot |
| FUN_06038520 | 8 | 9 | -1 | delay_slot |
| FUN_06038A64 | 43 | 42 | 1 | delay_slot |
| FUN_06038F34 | 16 | 15 | 1 | mixed |
| FUN_06039FE8 | 15 | 16 | -1 | delay_slot |
| FUN_0603B734 | 11 | 12 | -1 | mixed |
| FUN_0603B96A | 25 | 26 | -1 | delay_slot |
| FUN_0603B9A4 | 24 | 25 | -1 | addressing |
| FUN_0603BB86 | 68 | 67 | 1 | call_encoding |
| FUN_0603BF5A | 12 | 13 | -1 | sign_ext |
| FUN_0603C08C | 10 | 9 | 1 | multiply |
| FUN_0603EF54 | 7 | 8 | -1 | mixed |
| FUN_0603EFD4 | 8 | 9 | -1 | addressing |
| FUN_0603F1E0 | 7 | 8 | -1 | multiply |
| FUN_0603F1F0 | 8 | 9 | -1 | multiply |
| FUN_0603F216 | 10 | 11 | -1 | multiply |
| FUN_0603F520 | 9 | 10 | -1 | mixed |
| FUN_0603FF9C | 29 | 30 | -1 | call_encoding |
| FUN_06040964 | 10 | 11 | -1 | mixed |
| FUN_06041310 | 15 | 16 | -1 | delay_slot |
| FUN_06041470 | 43 | 42 | 1 | delay_slot |
| FUN_06042BBE | 8 | 9 | -1 | mixed |
| FUN_06042BEE | 6 | 7 | -1 | mixed |

## Compile Errors by Category (349)

### void_value (247)

Error messages:
- `void value not ignored as it ought to be` (222)
- `invalid type argument of `unary *'` (10)
- `subscripted value is neither array nor pointer` (6)
- `parse error before `{'` (6)
- ``stack0xffffffec' undeclared (first use this function)` (1)
- ``UNK_00000002' undeclared (first use this function)` (1)
- ``UNK_00000008' undeclared (first use this function)` (1)

| | | | | | |
|---|---|---|---|---|---|
| FUN_06003274 | FUN_06003A3C | FUN_06004A98 | FUN_06005294 | FUN_060053AC | FUN_060055BC |
| FUN_06005AE8 | FUN_06005C98 | FUN_06005ECC | FUN_060064F2 | FUN_060067C8 | FUN_06006868 |
| FUN_06006A9C | FUN_06007658 | FUN_06007790 | FUN_06007A50 | FUN_06008318 | FUN_0600A392 |
| FUN_0600A4CA | FUN_0600A914 | FUN_0600B6A0 | FUN_0600BB94 | FUN_0600C4F8 | FUN_0600C5D6 |
| FUN_0600C74E | FUN_0600C7D4 | FUN_0600C8CC | FUN_0600C994 | FUN_0600CD40 | FUN_0600CDD0 |
| FUN_0600D50C | FUN_0600D9BC | FUN_0600DB64 | FUN_0600DB9E | FUN_0600DCC8 | FUN_0600DD88 |
| FUN_0600DE70 | FUN_0600DFD0 | FUN_0600E060 | FUN_0600E0C0 | FUN_0600E1D4 | FUN_0600E47C |
| FUN_0600E4F2 | FUN_0600F424 | FUN_0600FFD0 | FUN_060100A4 | FUN_060104E0 | FUN_06010760 |
| FUN_06010B54 | FUN_06010BC4 | FUN_060116A8 | FUN_06011978 | FUN_06011AF4 | FUN_06012344 |
| FUN_06012450 | FUN_060125D0 | FUN_06012710 | FUN_060127E0 | FUN_06012B58 | FUN_06012BDC |
| FUN_06012C3C | FUN_06012CF4 | FUN_06013C58 | FUN_06013E3C | FUN_06013FC4 | FUN_0601424C |
| FUN_0601444C | FUN_06014466 | FUN_06014F34 | FUN_06015338 | FUN_06015EB8 | FUN_06016DD8 |
| FUN_060173AC | FUN_06017C9C | FUN_06018278 | FUN_06018A3C | FUN_06018DDC | FUN_06018E1E |
| FUN_0601950C | FUN_060196A4 | FUN_06019A48 | FUN_06019BC8 | FUN_06019DB8 | FUN_06019FB2 |
| FUN_0601B074 | FUN_0601BA50 | FUN_0601BBCC | FUN_0601BDEC | FUN_0601C3E4 | FUN_0601CAEE |
| FUN_0601CDC0 | FUN_0601CEFC | FUN_0601DBB8 | FUN_0601DE50 | FUN_0601DF88 | FUN_0601E26C |
| FUN_0601E488 | FUN_0601E4D4 | FUN_0601E6A4 | FUN_0601E764 | FUN_0601E810 | FUN_0601E958 |
| FUN_0601F5E0 | FUN_0601F784 | FUN_0601F936 | FUN_0601FEC0 | FUN_06020C3C | FUN_06020E74 |
| FUN_06021178 | FUN_0602382C | FUN_06026110 | FUN_060266CC | FUN_06027CA4 | FUN_0602A834 |
| FUN_0602AAA0 | FUN_0602AB00 | FUN_0602AB3A | FUN_0602ABB8 | FUN_0602AE24 | FUN_0602AE84 |
| FUN_0602AEBE | FUN_0602AF3C | FUN_0602B1D6 | FUN_0602B258 | FUN_0602B298 | FUN_0602B5CE |
| FUN_0602B5D2 | FUN_0602B9E0 | FUN_0602BC7A | FUN_0602BCFC | FUN_0602BD3C | FUN_0602C690 |
| FUN_0602CA84 | FUN_0602D8BC | FUN_0602D924 | FUN_0602DB00 | FUN_0602DC18 | FUN_0602E450 |
| FUN_0602E4BC | FUN_0602E610 | FUN_0602F4B4 | FUN_0602F5B6 | FUN_0602F99C | FUN_06030FC0 |
| FUN_0603136E | FUN_060316C4 | FUN_06031A28 | FUN_06031D1A | FUN_06031DF4 | FUN_060320E6 |
| FUN_06032304 | FUN_06032584 | FUN_0603268C | FUN_06032EA4 | FUN_06033188 | FUN_06033330 |
| FUN_06033354 | FUN_06033550 | FUN_060335F4 | FUN_06034000 | FUN_06034168 | FUN_0603449C |
| FUN_0603458C | FUN_06034640 | FUN_06034754 | FUN_06034848 | FUN_06034900 | FUN_06034984 |
| FUN_06034AEE | FUN_06034B54 | FUN_06034B9A | FUN_06034C68 | FUN_06034CC8 | FUN_06034D5E |
| FUN_06035340 | FUN_06035C08 | FUN_06035CBC | FUN_06035E90 | FUN_06035EA2 | FUN_06035EC8 |
| FUN_06035F04 | FUN_060363BC | FUN_06036518 | FUN_06036572 | FUN_06036650 | FUN_06036A98 |
| FUN_06036AF2 | FUN_06036D14 | FUN_060370E4 | FUN_06037660 | FUN_0603806C | FUN_06038642 |
| FUN_06038794 | FUN_0603AC1C | FUN_0603AE08 | FUN_0603AEE8 | FUN_0603AFD0 | FUN_0603B058 |
| FUN_0603B424 | FUN_0603B7C0 | FUN_0603B8B4 | FUN_0603BA2C | FUN_0603BAC6 | FUN_0603BC12 |
| FUN_0603BC86 | FUN_0603BD1C | FUN_0603BDAC | FUN_0603C728 | FUN_0603D3A8 | FUN_0603D5D0 |
| FUN_0603D9EC | FUN_0603DA88 | FUN_0603EACC | FUN_0603EC40 | FUN_0603EF64 | FUN_0603F0FC |
| FUN_0603F148 | FUN_0603F22C | FUN_0603F342 | FUN_0603FC60 | FUN_0603FCE4 | FUN_0603FD40 |
| FUN_0604000C | FUN_060400D6 | FUN_060401F8 | FUN_060405B8 | FUN_06040722 | FUN_0604077C |
| FUN_060408B0 | FUN_060409E6 | FUN_06040B32 | FUN_06040C10 | FUN_06040C98 | FUN_06041258 |
| FUN_060415C8 | FUN_06041648 | FUN_06041698 | FUN_060418BE | FUN_06041AA0 | FUN_06041B3C |
| FUN_06041CC8 | FUN_06041D6C | FUN_06041EE8 | FUN_06042088 | FUN_06042134 | FUN_060423CC |
| FUN_060429EC |  |  |  |  |  |

### invalid_deref (44)

Error messages:
- `invalid type argument of `unary *'` (42)
- `subscripted value is neither array nor pointer` (1)
- `parse error before `{'` (1)

| | | | | | |
|---|---|---|---|---|---|
| FUN_0600629C | FUN_06008730 | FUN_0600C3A8 | FUN_06010994 | FUN_0601389E | FUN_060148A2 |
| FUN_06014A74 | FUN_0601712C | FUN_06019928 | FUN_0601A65E | FUN_0601AEB6 | FUN_0601B09A |
| FUN_0601B418 | FUN_0601B7F4 | FUN_0601D3C0 | FUN_0601D9B0 | FUN_0601E37C | FUN_0601EAA0 |
| FUN_0601EB1C | FUN_0601EB70 | FUN_0601EBDA | FUN_0601EFC4 | FUN_0601F40C | FUN_0601FD74 |
| FUN_06020D46 | FUN_06031D8C | FUN_06032158 | FUN_06033020 | FUN_06033648 | FUN_06033700 |
| FUN_06033EA8 | FUN_06036068 | FUN_0603950C | FUN_06039808 | FUN_0603A01C | FUN_0603A0B0 |
| FUN_0603A7B0 | FUN_0603AB46 | FUN_0603B93C | FUN_0603F8EE | FUN_0603F900 | FUN_0603F90E |
| FUN_0603F91C | FUN_0603FACE |  |  |  |  |

### cc1_crash (35)

Error messages:
- `void value not ignored as it ought to be` (25)
- `internal error--unrecognizable insn:` (8)
- `subscripted value is neither array nor pointer` (1)
- ``UNK_00000001' undeclared (first use this function)` (1)

| | | | | | |
|---|---|---|---|---|---|
| FUN_06006CDC | FUN_0600B914 | FUN_0600E7C8 | FUN_0600EA18 | FUN_06017814 | FUN_06021450 |
| FUN_06022140 | FUN_060256CC | FUN_06025BF4 | FUN_06029BF4 | FUN_0602A134 | FUN_0602A214 |
| FUN_0602A754 | FUN_0602B328 | FUN_0602B546 | FUN_0602B55A | FUN_0602B55E | FUN_0602B572 |
| FUN_0602B58E | FUN_0602B5A2 | FUN_0602B5BE | FUN_0602B8DC | FUN_0602BDCC | FUN_0602C380 |
| FUN_0602C8E2 | FUN_0602CCD0 | FUN_0602CDF6 | FUN_0602D08A | FUN_0602D43C | FUN_0602D7E4 |
| FUN_0602F17C | FUN_0602F474 | FUN_06030A06 | FUN_0603DDFC | FUN_060414D0 |  |

### bad_subscript (9)

| | | | | | |
|---|---|---|---|---|---|
| FUN_0600AFB2 | FUN_0601450C | FUN_0601A3F4 | FUN_06025224 | FUN_06025478 | FUN_060268B0 |
| FUN_0602C494 | FUN_06033278 | FUN_06035280 |  |  |  |

### parse_error (8)

Error messages:
- `parse error before `{'` (4)
- ``switchD_06026332' undeclared (first use this function)` (1)
- ``switchD_060263be' undeclared (first use this function)` (1)
- ``switchD_0602645e' undeclared (first use this function)` (1)
- ``switchD_060264ea' undeclared (first use this function)` (1)

| | | | | | |
|---|---|---|---|---|---|
| FUN_060262C0 | FUN_06026362 | FUN_060263EC | FUN_0602648E | FUN_06039100 | FUN_06040220 |
| FUN_06041034 | FUN_060411A0 |  |  |  |  |

### undeclared (5)

Error messages:
- ``UNK_00000008' undeclared (first use this function)` (1)
- ``_local_18' undeclared (first use this function)` (1)
- ``_uStack_10' undeclared (first use this function)` (1)
- ``Onchip_DMA0R' undeclared (first use this function)` (1)
- ``UNK_00000001' undeclared (first use this function)` (1)

| | | | | | |
|---|---|---|---|---|---|
| FUN_06035460 | FUN_060361FC | FUN_06036A1C | FUN_06042A8C | FUN_06042BFC |  |

### other (1)

| | | | | | |
|---|---|---|---|---|---|
| FUN_06040F82 |  |  |  |  |  |

## Codegen Failures by Delta Bucket

FAIL functions grouped by how far our instruction count is from original.
Positive delta = our code is longer; negative = our code is shorter.

### delta 2-5 (47)

| Function | Ours | Orig | Delta | Category |
|----------|-----:|-----:|------:|----------|
| FUN_060032D4 | 29 | 27 | 2 | addressing |
| FUN_0600D0B8 | 47 | 45 | 2 | delay_slot |
| FUN_0600D336 | 28 | 26 | 2 | delay_slot |
| FUN_06013E12 | 19 | 17 | 2 | call_encoding |
| FUN_06017C78 | 20 | 18 | 2 | call_encoding |
| FUN_0601A5F8 | 10 | 8 | 2 | delay_slot |
| FUN_06027476 | 19 | 17 | 2 | delay_slot |
| FUN_060283B8 | 20 | 18 | 2 | multiply |
| FUN_0602EFCC | 15 | 13 | 2 | addressing |
| FUN_0603072E | 20 | 18 | 2 | call_encoding |
| FUN_06035E5E | 18 | 16 | 2 | mixed |
| FUN_060370C0 | 20 | 18 | 2 | sign_ext |
| FUN_06039250 | 77 | 75 | 2 | multiply |
| FUN_0603B8F4 | 21 | 19 | 2 | call_encoding |
| FUN_06008640 | 53 | 50 | 3 | call_encoding |
| FUN_0600A084 | 33 | 30 | 3 | call_encoding |
| FUN_0600A1B8 | 34 | 31 | 3 | delay_slot |
| FUN_0600DC74 | 21 | 18 | 3 | call_encoding |
| FUN_0601A73E | 15 | 12 | 3 | call_encoding |
| FUN_0601AE80 | 30 | 27 | 3 | call_encoding |
| FUN_06020BCE | 28 | 25 | 3 | call_encoding |
| FUN_0602766C | 18 | 15 | 3 | addressing |
| FUN_060283E0 | 14 | 11 | 3 | delay_slot |
| FUN_060393FC | 76 | 73 | 3 | delay_slot |
| FUN_0603B1B6 | 54 | 51 | 3 | call_encoding |
| FUN_060033E6 | 20 | 16 | 4 | call_encoding |
| FUN_06008418 | 40 | 36 | 4 | call_encoding |
| FUN_060085B8 | 58 | 54 | 4 | delay_slot |
| FUN_0600E99C | 39 | 35 | 4 | delay_slot |
| FUN_0601143E | 13 | 9 | 4 | call_encoding |
| FUN_06011450 | 13 | 9 | 4 | call_encoding |
| FUN_06014868 | 18 | 14 | 4 | call_encoding |
| FUN_06014884 | 19 | 15 | 4 | call_encoding |
| FUN_06030EE0 | 14 | 10 | 4 | delay_slot |
| FUN_06031340 | 21 | 17 | 4 | delay_slot |
| FUN_06032E6C | 22 | 18 | 4 | delay_slot |
| FUN_060358EC | 42 | 38 | 4 | delay_slot |
| FUN_06035BC8 | 33 | 29 | 4 | delay_slot |
| FUN_0603B74C | 48 | 44 | 4 | delay_slot |
| FUN_0604231E | 65 | 61 | 4 | delay_slot |
| main | 52 | 48 | 4 | call_encoding |
| FUN_06014360 | 92 | 87 | 5 | call_encoding |
| FUN_0602ECF2 | 13 | 8 | 5 | call_encoding |
| FUN_0603253C | 26 | 21 | 5 | delay_slot |
| FUN_060337FC | 11 | 6 | 5 | call_encoding |
| FUN_060359D2 | 9 | 4 | 5 | addressing |
| FUN_0603FA1A | 90 | 85 | 5 | call_encoding |

### delta 6-15 (69)

| Function | Ours | Orig | Delta | Category |
|----------|-----:|-----:|------:|----------|
| FUN_0600A0C0 | 44 | 38 | 6 | call_encoding |
| FUN_06012198 | 14 | 8 | 6 | call_encoding |
| FUN_06020CF4 | 47 | 41 | 6 | sign_ext |
| FUN_0603320C | 52 | 46 | 6 | call_encoding |
| FUN_06038044 | 24 | 18 | 6 | comparison |
| FUN_0603BE7C | 18 | 12 | 6 | call_encoding |
| FUN_06041826 | 52 | 46 | 6 | call_encoding |
| FUN_0600330A | 51 | 44 | 7 | addressing |
| FUN_060061C8 | 84 | 77 | 7 | call_encoding |
| FUN_06007540 | 47 | 40 | 7 | multiply |
| FUN_0601250C | 68 | 61 | 7 | call_encoding |
| FUN_06014A04 | 38 | 31 | 7 | multiply |
| FUN_06018166 | 139 | 132 | 7 | call_encoding |
| FUN_060192E8 | 16 | 9 | 7 | delay_slot |
| FUN_06036414 | 15 | 8 | 7 | call_encoding |
| FUN_06036F0C | 202 | 195 | 7 | delay_slot |
| FUN_0603931C | 68 | 61 | 7 | delay_slot |
| FUN_06040EEC | 28 | 21 | 7 | delay_slot |
| FUN_060424A2 | 22 | 15 | 7 | multiply |
| FUN_060039C8 | 29 | 21 | 8 | call_encoding |
| FUN_060039F2 | 31 | 23 | 8 | call_encoding |
| FUN_0601155E | 60 | 52 | 8 | call_encoding |
| FUN_0601DDF6 | 31 | 23 | 8 | call_encoding |
| FUN_06020B20 | 27 | 19 | 8 | multiply |
| FUN_0603697C | 16 | 8 | 8 | call_encoding |
| FUN_06007590 | 71 | 62 | 9 | delay_slot |
| FUN_0600D210 | 52 | 43 | 9 | delay_slot |
| FUN_0600D37C | 45 | 36 | 9 | delay_slot |
| FUN_0600EB14 | 107 | 98 | 9 | call_encoding |
| FUN_06017330 | 42 | 33 | 9 | delay_slot |
| FUN_06026518 | 54 | 45 | 9 | call_encoding |
| FUN_06034F78 | 61 | 52 | 9 | delay_slot |
| FUN_060365C4 | 15 | 6 | 9 | call_encoding |
| FUN_0600A33C | 33 | 23 | 10 | delay_slot |
| FUN_0600CC38 | 141 | 131 | 10 | delay_slot |
| FUN_0601D57C | 57 | 47 | 10 | call_encoding |
| FUN_0602744C | 30 | 20 | 10 | delay_slot |
| FUN_0603226C | 18 | 8 | 10 | call_encoding |
| FUN_06032E18 | 31 | 21 | 10 | delay_slot |
| FUN_060367E8 | 16 | 6 | 10 | call_encoding |
| FUN_0603683C | 16 | 6 | 10 | call_encoding |
| FUN_0600A76C | 127 | 116 | 11 | call_encoding |
| FUN_0600CB90 | 88 | 77 | 11 | delay_slot |
| FUN_0600D84C | 46 | 35 | 11 | delay_slot |
| FUN_0601228A | 43 | 32 | 11 | call_encoding |
| FUN_0601ADB0 | 73 | 62 | 11 | delay_slot |
| FUN_0601AE2C | 20 | 9 | 11 | delay_slot |
| FUN_06032D90 | 57 | 46 | 11 | multiply |
| FUN_060362A8 | 15 | 4 | 11 | call_encoding |
| FUN_06036380 | 15 | 4 | 11 | call_encoding |
| FUN_060364D4 | 15 | 4 | 11 | call_encoding |
| FUN_060417A8 | 55 | 44 | 11 | delay_slot |
| FUN_06003218 | 58 | 46 | 12 | sign_ext |
| FUN_060282C0 | 41 | 29 | 12 | delay_slot |
| FUN_06028306 | 41 | 29 | 12 | delay_slot |
| FUN_06026E02 | 18 | 5 | 13 | addressing |
| FUN_060270C6 | 18 | 5 | 13 | addressing |
| FUN_06036144 | 15 | 2 | 13 | call_encoding |
| FUN_0600A294 | 57 | 43 | 14 | delay_slot |
| FUN_0600D92C | 67 | 53 | 14 | delay_slot |
| FUN_0600E71A | 79 | 65 | 14 | delay_slot |
| FUN_06012080 | 16 | 2 | 14 | call_encoding |
| FUN_06035F16 | 30 | 16 | 14 | addressing |
| FUN_0603F9B8 | 16 | 2 | 14 | call_encoding |
| FUN_0600D3C4 | 155 | 140 | 15 | delay_slot |
| FUN_06028400 | 37 | 22 | 15 | multiply |
| FUN_0603B81E | 39 | 24 | 15 | delay_slot |
| FUN_0603EDC4 | 185 | 170 | 15 | delay_slot |
| FUN_06042ACA | 120 | 105 | 15 | delay_slot |

### delta 16+ (104)

| Function | Ours | Orig | Delta | Category |
|----------|-----:|-----:|------:|----------|
| FUN_06026DBC | 46 | 30 | 16 | mixed |
| FUN_06027080 | 46 | 30 | 16 | mixed |
| FUN_06033470 | 76 | 59 | 17 | delay_slot |
| FUN_0602F7BC | 38 | 20 | 18 | delay_slot |
| FUN_06009FFC | 21 | 2 | 19 | call_encoding |
| FUN_0602F3EC | 58 | 39 | 19 | delay_slot |
| FUN_0603F93C | 25 | 6 | 19 | call_encoding |
| FUN_06012050 | 22 | 2 | 20 | call_encoding |
| FUN_060280F8 | 72 | 52 | 20 | multiply |
| FUN_06035FEC | 57 | 37 | 20 | call_encoding |
| FUN_0603F970 | 22 | 2 | 20 | call_encoding |
| FUN_0600CEBA | 85 | 64 | 21 | call_encoding |
| FUN_06035228 | 49 | 28 | 21 | delay_slot |
| FUN_0604249C | 24 | 3 | 21 | multiply |
| FUN_060284AE | 88 | 66 | 22 | delay_slot |
| FUN_06030B68 | 292 | 270 | 22 | call_encoding |
| FUN_06035168 | 31 | 8 | 23 | call_encoding |
| FUN_0601ABC6 | 62 | 38 | 24 | delay_slot |
| FUN_06025148 | 124 | 100 | 24 | delay_slot |
| FUN_060146D2 | 75 | 50 | 25 | delay_slot |
| FUN_06025070 | 124 | 99 | 25 | delay_slot |
| FUN_06028430 | 83 | 58 | 25 | delay_slot |
| FUN_0600A474 | 28 | 2 | 26 | call_encoding |
| FUN_0602D82A | 52 | 26 | 26 | delay_slot |
| FUN_06017784 | 97 | 70 | 27 | delay_slot |
| FUN_060346C0 | 51 | 24 | 27 | delay_slot |
| FUN_06034D1C | 29 | 2 | 27 | call_encoding |
| FUN_0603F84C | 75 | 48 | 27 | delay_slot |
| FUN_0600C302 | 93 | 62 | 31 | delay_slot |
| FUN_0602834A | 43 | 12 | 31 | delay_slot |
| FUN_0601772E | 41 | 9 | 32 | call_encoding |
| FUN_0600CA96 | 147 | 114 | 33 | delay_slot |
| FUN_06018FA4 | 35 | 2 | 33 | call_encoding |
| FUN_060190B8 | 35 | 2 | 33 | call_encoding |
| FUN_060190F4 | 35 | 2 | 33 | call_encoding |
| FUN_0601914C | 35 | 2 | 33 | call_encoding |
| FUN_06019188 | 35 | 2 | 33 | call_encoding |
| FUN_0601C978 | 131 | 97 | 34 | call_encoding |
| FUN_06018FF8 | 37 | 2 | 35 | call_encoding |
| FUN_06027378 | 140 | 105 | 35 | delay_slot |
| FUN_060321C0 | 49 | 14 | 35 | call_encoding |
| FUN_06019058 | 38 | 2 | 36 | call_encoding |
| FUN_060191E0 | 38 | 2 | 36 | call_encoding |
| FUN_06019248 | 38 | 2 | 36 | call_encoding |
| FUN_06018634 | 43 | 6 | 37 | delay_slot |
| FUN_06020946 | 42 | 5 | 37 | call_encoding |
| FUN_0603C104 | 41 | 4 | 37 | call_encoding |
| FUN_060102EA | 67 | 29 | 38 | call_encoding |
| FUN_0603F2E0 | 46 | 6 | 40 | call_encoding |
| FUN_0603F534 | 44 | 2 | 42 | call_encoding |
| FUN_06026E60 | 67 | 23 | 44 | multiply |
| FUN_06027124 | 67 | 23 | 44 | multiply |
| FUN_0603B31C | 54 | 4 | 50 | call_encoding |
| FUN_0602F0E8 | 79 | 27 | 52 | delay_slot |
| FUN_0603D514 | 54 | 2 | 52 | call_encoding |
| FUN_06040F16 | 55 | 3 | 52 | call_encoding |
| FUN_0603F582 | 408 | 353 | 55 | call_encoding |
| FUN_060140C4 | 59 | 2 | 57 | call_encoding |
| FUN_0603D2CC | 59 | 2 | 57 | call_encoding |
| FUN_0603D438 | 59 | 2 | 57 | call_encoding |
| FUN_060120C8 | 64 | 2 | 62 | call_encoding |
| FUN_06020414 | 79 | 14 | 65 | call_encoding |
| FUN_060302C6 | 271 | 205 | 66 | delay_slot |
| FUN_060114AC | 73 | 6 | 67 | call_encoding |
| FUN_0603053C | 251 | 184 | 67 | call_encoding |
| FUN_0602D814 | 86 | 11 | 75 | delay_slot |
| FUN_06036CB0 | 123 | 46 | 77 | delay_slot |
| FUN_060193F4 | 85 | 5 | 80 | call_encoding |
| FUN_0601D5F4 | 143 | 62 | 81 | call_encoding |
| FUN_06027EDE | 295 | 211 | 84 | delay_slot |
| FUN_0600736C | 95 | 2 | 93 | call_encoding |
| FUN_0601B6DC | 111 | 10 | 101 | call_encoding |
| FUN_06030A9C | 169 | 68 | 101 | call_encoding |
| FUN_0601D7D0 | 208 | 101 | 107 | call_encoding |
| FUN_0601AC7C | 124 | 6 | 118 | call_encoding |
| FUN_0600B340 | 306 | 187 | 119 | call_encoding |
| FUN_0600BFFC | 136 | 10 | 126 | call_encoding |
| FUN_06036E1C | 179 | 53 | 126 | call_encoding |
| FUN_06005788 | 153 | 10 | 143 | call_encoding |
| FUN_06016CDC | 148 | 5 | 143 | call_encoding |
| FUN_06033BC8 | 176 | 28 | 148 | call_encoding |
| FUN_06004F14 | 167 | 10 | 157 | call_encoding |
| FUN_06017CEC | 707 | 548 | 159 | call_encoding |
| FUN_0602F7EA | 184 | 4 | 180 | call_encoding |
| FUN_06038300 | 226 | 35 | 191 | call_encoding |
| FUN_06018320 | 322 | 100 | 222 | call_encoding |
| FUN_0601B160 | 275 | 8 | 267 | call_encoding |
| FUN_06026E2E | 297 | 24 | 273 | delay_slot |
| FUN_060270F2 | 297 | 24 | 273 | delay_slot |
| FUN_06026FFC | 314 | 29 | 285 | delay_slot |
| FUN_060359E4 | 451 | 137 | 314 | call_encoding |
| FUN_06026EDE | 381 | 36 | 345 | delay_slot |
| FUN_060271A2 | 381 | 36 | 345 | delay_slot |
| FUN_06026F2A | 381 | 34 | 347 | delay_slot |
| FUN_060271EE | 381 | 34 | 347 | delay_slot |
| FUN_06026E94 | 383 | 35 | 348 | delay_slot |
| FUN_06027158 | 383 | 35 | 348 | delay_slot |
| FUN_06026F72 | 660 | 67 | 593 | delay_slot |
| FUN_0600EC78 | 861 | 135 | 726 | call_encoding |
| FUN_06012F80 | 1056 | 104 | 952 | call_encoding |
| FUN_06035F44 | 2714 | 14 | 2700 | call_encoding |
| FUN_06036BE4 | 3940 | 21 | 3919 | call_encoding |
| FUN_06034FFC | 3969 | 15 | 3954 | call_encoding |
| FUN_060350B0 | 4865 | 23 | 4842 | call_encoding |

### delta -2 to -5 (70)

| Function | Ours | Orig | Delta | Category |
|----------|-----:|-----:|------:|----------|
| FUN_06006838 | 17 | 19 | -2 | multiply |
| FUN_0600A4AA | 14 | 16 | -2 | call_encoding |
| FUN_0600A8BC | 32 | 34 | -2 | delay_slot |
| FUN_0600C218 | 53 | 55 | -2 | call_encoding |
| FUN_06011678 | 19 | 21 | -2 | comparison |
| FUN_0601476C | 117 | 119 | -2 | call_encoding |
| FUN_060172E4 | 34 | 36 | -2 | multiply |
| FUN_0601B0D8 | 60 | 62 | -2 | call_encoding |
| FUN_060200A4 | 81 | 83 | -2 | call_encoding |
| FUN_06020DEE | 34 | 36 | -2 | multiply |
| FUN_06020E3C | 23 | 25 | -2 | delay_slot |
| FUN_0603307C | 13 | 15 | -2 | mixed |
| FUN_060349C4 | 33 | 35 | -2 | delay_slot |
| FUN_06035C92 | 5 | 7 | -2 | sign_ext |
| FUN_06038A48 | 12 | 14 | -2 | delay_slot |
| FUN_060394C2 | 7 | 9 | -2 | sign_ext |
| FUN_060394F0 | 10 | 12 | -2 | delay_slot |
| FUN_0603A766 | 24 | 26 | -2 | sign_ext |
| FUN_0603BF22 | 22 | 24 | -2 | call_encoding |
| FUN_0603F202 | 8 | 10 | -2 | multiply |
| FUN_0603FA00 | 5 | 7 | -2 | addressing |
| FUN_06041330 | 13 | 15 | -2 | call_encoding |
| FUN_0604188C | 19 | 21 | -2 | mixed |
| FUN_06042BAC | 7 | 9 | -2 | mixed |
| FUN_06003430 | 24 | 27 | -3 | call_encoding |
| FUN_0600508A | 58 | 61 | -3 | multiply |
| FUN_06009E02 | 22 | 25 | -3 | call_encoding |
| FUN_0600C928 | 26 | 29 | -3 | call_encoding |
| FUN_06012D7C | 17 | 20 | -3 | delay_slot |
| FUN_060171AC | 114 | 117 | -3 | delay_slot |
| FUN_06018EE4 | 69 | 72 | -3 | call_encoding |
| FUN_0601D12C | 196 | 199 | -3 | call_encoding |
| FUN_0601F8C0 | 23 | 26 | -3 | delay_slot |
| FUN_0601FE20 | 56 | 59 | -3 | delay_slot |
| FUN_060210F6 | 11 | 14 | -3 | call_encoding |
| FUN_06026CA4 | 21 | 24 | -3 | multiply |
| FUN_06035D5A | 76 | 79 | -3 | delay_slot |
| FUN_06035E3C | 14 | 17 | -3 | addressing |
| FUN_0603B9D6 | 39 | 42 | -3 | delay_slot |
| FUN_0603FFE6 | 16 | 19 | -3 | delay_slot |
| FUN_06040680 | 10 | 13 | -3 | delay_slot |
| FUN_06040EBA | 20 | 23 | -3 | delay_slot |
| FUN_06041180 | 13 | 16 | -3 | call_encoding |
| FUN_06041204 | 39 | 42 | -3 | delay_slot |
| FUN_060412B2 | 39 | 42 | -3 | delay_slot |
| FUN_0600511E | 26 | 30 | -4 | call_encoding |
| FUN_0600A026 | 30 | 34 | -4 | mixed |
| FUN_0600CE66 | 37 | 41 | -4 | multiply |
| FUN_060185D8 | 42 | 46 | -4 | call_encoding |
| FUN_06018EAC | 10 | 14 | -4 | sign_ext |
| FUN_06028654 | 97 | 101 | -4 | call_encoding |
| FUN_06036E90 | 44 | 48 | -4 | delay_slot |
| FUN_0603A6C0 | 25 | 29 | -4 | sign_ext |
| FUN_0603ADAC | 33 | 37 | -4 | call_encoding |
| FUN_0603B3FA | 13 | 17 | -4 | addressing |
| FUN_0603F9DA | 8 | 12 | -4 | sign_ext |
| FUN_06040FEA | 15 | 19 | -4 | delay_slot |
| FUN_060103B8 | 62 | 67 | -5 | call_encoding |
| FUN_06011094 | 159 | 164 | -5 | delay_slot |
| FUN_06017BF4 | 42 | 47 | -5 | call_encoding |
| FUN_060336F2 | 2 | 7 | -5 | addressing |
| FUN_06034FE0 | 8 | 13 | -5 | addressing |
| FUN_06035C2C | 8 | 13 | -5 | addressing |
| FUN_06035C54 | 11 | 16 | -5 | sign_ext |
| FUN_06036DDC | 25 | 30 | -5 | delay_slot |
| FUN_0603B28E | 58 | 63 | -5 | call_encoding |
| FUN_0603C156 | 13 | 18 | -5 | call_encoding |
| FUN_0603EF34 | 11 | 16 | -5 | addressing |
| FUN_06041014 | 11 | 16 | -5 | delay_slot |
| FUN_0604134E | 15 | 20 | -5 | delay_slot |

### delta -6 to -15 (35)

| Function | Ours | Orig | Delta | Category |
|----------|-----:|-----:|------:|----------|
| FUN_06012DB4 | 32 | 38 | -6 | call_encoding |
| FUN_06026590 | 150 | 156 | -6 | delay_slot |
| FUN_0603660E | 21 | 27 | -6 | addressing |
| FUN_0603AF94 | 24 | 30 | -6 | call_encoding |
| FUN_06040FB8 | 19 | 25 | -6 | delay_slot |
| FUN_0600E906 | 59 | 66 | -7 | delay_slot |
| FUN_06010470 | 49 | 56 | -7 | call_encoding |
| FUN_06017372 | 18 | 25 | -7 | delay_slot |
| FUN_0601A80C | 133 | 140 | -7 | delay_slot |
| FUN_0601E2B4 | 72 | 79 | -7 | call_encoding |
| FUN_0603316C | 2 | 9 | -7 | addressing |
| FUN_060360FC | 29 | 36 | -7 | delay_slot |
| FUN_060400B4 | 10 | 17 | -7 | delay_slot |
| FUN_06005198 | 117 | 125 | -8 | delay_slot |
| FUN_06007BCC | 103 | 111 | -8 | call_encoding |
| FUN_0600A1F6 | 46 | 54 | -8 | delay_slot |
| FUN_060333D8 | 54 | 62 | -8 | delay_slot |
| FUN_06035B34 | 62 | 70 | -8 | delay_slot |
| FUN_06036D94 | 28 | 36 | -8 | delay_slot |
| FUN_0600D280 | 57 | 66 | -9 | delay_slot |
| FUN_06011F92 | 80 | 89 | -9 | delay_slot |
| FUN_0601E100 | 141 | 150 | -9 | delay_slot |
| FUN_0603B21C | 47 | 56 | -9 | call_encoding |
| FUN_0602ECCC | 4 | 14 | -10 | sign_ext |
| FUN_06035E00 | 19 | 29 | -10 | delay_slot |
| FUN_06008460 | 40 | 51 | -11 | call_encoding |
| FUN_06011F1C | 48 | 59 | -11 | delay_slot |
| FUN_0601D0BC | 16 | 27 | -11 | multiply |
| FUN_0603F3F6 | 75 | 87 | -12 | call_encoding |
| FUN_0600BF70 | 43 | 57 | -14 | call_encoding |
| FUN_06034E58 | 58 | 72 | -14 | delay_slot |
| FUN_060078DC | 129 | 144 | -15 | call_encoding |
| FUN_0600D780 | 119 | 134 | -15 | call_encoding |
| FUN_060330A0 | 66 | 81 | -15 | call_encoding |
| FUN_06033F54 | 55 | 70 | -15 | call_encoding |

### delta < -15 (44)

| Function | Ours | Orig | Delta | Category |
|----------|-----:|-----:|------:|----------|
| FUN_060030FC | 95 | 111 | -16 | delay_slot |
| FUN_06012E08 | 17 | 33 | -16 | delay_slot |
| FUN_0602C7FC | 77 | 93 | -16 | delay_slot |
| FUN_060111E2 | 107 | 124 | -17 | call_encoding |
| FUN_0603C000 | 29 | 46 | -17 | sign_ext |
| FUN_06005A22 | 77 | 96 | -19 | call_encoding |
| FUN_06005DD4 | 99 | 118 | -19 | delay_slot |
| FUN_0602D88E | 2 | 21 | -19 | call_encoding |
| FUN_060336C8 | 2 | 21 | -19 | delay_slot |
| FUN_0600AA98 | 168 | 189 | -21 | call_encoding |
| FUN_06011DC0 | 60 | 81 | -21 | delay_slot |
| FUN_0601A940 | 164 | 185 | -21 | delay_slot |
| FUN_06005928 | 94 | 116 | -22 | call_encoding |
| FUN_060081F4 | 119 | 141 | -22 | call_encoding |
| FUN_06035D22 | 6 | 28 | -22 | multiply |
| FUN_06011310 | 125 | 148 | -23 | delay_slot |
| FUN_060145BC | 107 | 130 | -23 | call_encoding |
| FUN_06026CE0 | 10 | 33 | -23 | addressing |
| FUN_0600AC44 | 168 | 192 | -24 | call_encoding |
| FUN_060121A8 | 80 | 105 | -25 | call_encoding |
| FUN_0603853C | 98 | 123 | -25 | call_encoding |
| FUN_06038120 | 202 | 228 | -26 | delay_slot |
| FUN_06038E54 | 57 | 83 | -26 | delay_slot |
| FUN_060388C0 | 78 | 105 | -27 | call_encoding |
| FUN_06034A10 | 33 | 63 | -30 | delay_slot |
| FUN_0603BF7C | 32 | 62 | -30 | sign_ext |
| FUN_0603CC88 | 66 | 98 | -32 | call_encoding |
| FUN_0601F9CC | 345 | 378 | -33 | call_encoding |
| FUN_06038AC8 | 81 | 118 | -37 | call_encoding |
| FUN_06020DD0 | 13 | 51 | -38 | comparison |
| FUN_0601F4B4 | 97 | 136 | -39 | multiply |
| FUN_06003578 | 295 | 336 | -41 | call_encoding |
| FUN_06014D2C | 183 | 224 | -41 | delay_slot |
| FUN_0600CF58 | 166 | 210 | -44 | call_encoding |
| FUN_06038BD4 | 245 | 294 | -49 | delay_slot |
| FUN_0600DA7C | 86 | 140 | -54 | call_encoding |
| FUN_060389A6 | 36 | 91 | -55 | call_encoding |
| FUN_0602EFF0 | 43 | 105 | -62 | call_encoding |
| FUN_060172BC | 19 | 89 | -70 | delay_slot |
| FUN_0603C1A8 | 555 | 651 | -96 | call_encoding |
| FUN_0600D31C | 13 | 113 | -100 | delay_slot |
| FUN_060086C0 | 36 | 235 | -199 | call_encoding |
| FUN_06004670 | 304 | 520 | -216 | multiply |
| FUN_0603CD5C | 318 | 633 | -315 | call_encoding |

## Coverage Gap

Of the 1234 function symbols in `build/aprog_syms.txt`, only 505 have corresponding
C sources in `src/`. The remaining **729 functions** were not decompiled by Ghidra,
typically because they are:

- Hand-written assembly (startup, interrupt handlers, DMA setup)
- Data tables misidentified as functions
- Overlapping or aliased entry points
- Functions in memory regions Ghidra could not analyze

Additionally, Ghidra produced 381 C sources for addresses NOT in the symbol table
(internal/unnamed functions discovered during analysis). These 886 total sources
(505 matched + 381 extras) form the basis of this catalog.

---

*Generated from catalog_raw.tsv. Rebuild with `python docs/_gen_catalog.py`.*
