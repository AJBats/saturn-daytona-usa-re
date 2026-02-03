# Daytona USA Binary Function Catalog

Generated from Ghidra decompiler export of 880 functions.
Binary: aprog.bin loaded at 0x06003000, 394,896 bytes.

## Summary Statistics

- **Total functions exported**: 880
- **LEAF functions** (no subroutine calls): ~320
- **CALL functions** (has subroutine calls): ~560
- **Named functions**: `security_check`, `initial_program`, `main`
- **Largest function**: FUN_0602382c (4484 bytes, 2242 insns)
- **Smallest functions**: 4 bytes / 2 insns (return stubs)

## Size Distribution

| Instruction Range | Count (approx) | Notes |
|-------------------|----------------|-------|
| 2-4 insns | ~30 | Return stubs, trivial getters |
| 5-10 insns | ~40 | Simple setters, flag operations |
| 11-20 insns | ~50 | Good verification candidates |
| 21-50 insns | ~200 | Medium complexity |
| 51-100 insns | ~200 | Moderate functions |
| 101-200 insns | ~180 | Substantial functions |
| 201-500 insns | ~130 | Large functions |
| 500+ insns | ~50 | Very large / main logic |

## Key Named Functions

| Address | Name | Size | Type | Notes |
|---------|------|------|------|-------|
| 0x06002100 | security_check | 268B/134i | CALL | Copy protection check |
| 0x06002e80 | initial_program | 8B/4i | LEAF | Entry point stub |
| 0x06003000 | main | 96B/48i | CALL | Main loop / state machine |
| 0x060030fc | FUN_060030fc | 200B/100i | CALL | Init chain dispatcher |

## Verification Candidates (Priority)

### Tier 1: Small LEAF functions (best for compiler verification)

| Address | Insns | Ghidra Summary |
|---------|-------|----------------|
| 0x06006838 | 19 | Pure arithmetic: `((0x03FFFFFF - p2) >> 21) * 64 + ((0x04000000 + p1) >> 21)` |
| 0x060149cc | 10 | Bit OR: `reg |= 0x8000; flag = 1` |
| 0x060149e0 | 10 | Bit AND: `reg &= mask; flag = 1` |
| 0x0600c970 | 18 | Conditional + table lookup with range check |
| 0x060054ea | 12 | Init: store param, zero fields, copy value |
| 0x060033e6 | 16 | Unknown - needs analysis |
| 0x06005174 | 18 | Unknown - needs analysis |
| 0x060192b4 | 11 | Memory clear loop (memset-like) |
| 0x060192e8 | 15 | Unknown - needs analysis |
| 0x0601a5f8 | 11 | Unknown - needs analysis |
| 0x0601a73e | 12 | Unknown - needs analysis |
| 0x06012198 | 8 | Conditional tail-call dispatch |
| 0x06030ee0 | 10 | Unknown - needs analysis |
| 0x060322e8 | 10 | Unknown - needs analysis |
| 0x06033504 | 10 | Unknown - needs analysis |
| 0x0600c928 | 29 | Unknown - needs analysis |

### Tier 2: Small CALL functions (already verified pattern)

| Address | Insns | Ghidra Summary |
|---------|-------|----------------|
| 0x0600f870 | ~20 | **VERIFIED** - counter decrement + conditional flag set |
| 0x06009e02 | ~25 | **VERIFIED** - counter--, conditional state set, calls, flag |
| 0x0600de40 | 10 | Shift + store + 2 calls (has tail call) |
| 0x0600de54 | 14 | Shift + store + copy + 2 calls (has tail call) |
| 0x0600d31c | 13 | Conditional bit test + 3 calls (has tail call) |
| 0x06018e70 | 12 | Stack local + indirect call |

### Tier 3: Medium LEAF functions (deeper verification)

| Address | Insns | Ghidra Summary |
|---------|-------|----------------|
| 0x060023e6 | 11 | Hardware polling spin loop |
| 0x06002404 | 22 | Unknown |
| 0x0600bf70 | 57 | Unknown |
| 0x0600d0b8 | 45 | Unknown |
| 0x0600d12c | 94 | Unknown |
| 0x0600ea18 | 108 | Unknown |

## Compiler Verification Results

### Verified: FUN_0600F870 (CALL, ~20 insns)
- **Match quality**: Structural match
- **C source**: `func(0); result = func2(); counter--; if (counter <= 0) flag = 4; return result;`
- **Differences**: Register numbering (r0,r1,r2 vs r2,r3,r4), 2 instructions reordered
- **Instruction count**: Match (20 vs 20)

### Verified: FUN_06009E02 (CALL, 25-26 insns)
- **Match quality**: Structural match, 1 instruction gap
- **C source**: `counter--; if (counter == 0) state = 30; func1(); if (state != 27) func2(); flag = 1;`
- **Differences**: Register numbering, bf vs bf/s scheduling, unfilled rts delay slot
- **Instruction count**: 26 (ours) vs 25 (original) - 1 insn gap from rts delay slot

### Systematic Differences Observed
1. **Caller-saved register preference**: Our compiler uses r1,r2; original uses r3,r4
2. **bf/s optimization**: Original uses bf/s (delayed branch) to fill delay slot with store; ours uses plain bf
3. **rts delay slot**: Original fills rts delay slot with useful instruction; ours emits nop
4. **Tail calls**: Original optimizes last call as `bra target` + `lds.l @r15+,pr` in delay slot
