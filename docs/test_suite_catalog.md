# Test Suite Catalog: Failure Taxonomy and Delta Analysis

Generated from `docs/harness_results.txt` test harness run.
Compiler: patched GCC 2.6.3 SH-2 backend (`gcc26-build/cc1`) with 8 patches applied.

---

## 1. Summary

| Metric          | Value |
|-----------------|-------|
| Total tests     | 133   |
| PASS            | 28    |
| FAIL            | 105   |
| SKIP            | 8     |
| Pass rate       | 21%   |
| Compile errors  | 0     |

Of the 105 failures:
- 11 functions have delta=0 (same instruction count, opcode differences)
- 38 functions have negative delta (our code is shorter than original)
- 56 functions have positive delta (our code is longer than original)

---

## 2. Passing Functions (28)

All 28 passing functions produce byte-identical instruction streams to the original binary.

### Stub / Empty Functions (2 insns)

| Function       | Insns | Type            | Description                         |
|----------------|-------|-----------------|-------------------------------------|
| FUN_0600D266   | 2     | Empty stub      | `return;` -- rts + nop              |
| FUN_0601E0DE   | 2     | Empty stub      | `return;` -- rts + nop              |
| FUN_0601F8BC   | 2     | Empty stub      | `return;` -- rts + nop              |
| FUN_0603F9F2   | 2     | Tiny getter     | Return `*(param_1 + 0x14)`          |
| FUN_0603F9F6   | 2     | Tiny getter     | Return `*(param_1 + 0x18)`          |
| FUN_060401E4   | 2     | Tiny setter     | Store param_2 at `*(param_1+0x18)`  |

### Return-Constant / Tiny Leaf (3 insns)

| Function       | Insns | Type            | Description                         |
|----------------|-------|-----------------|-------------------------------------|
| FUN_06035C48   | 3     | Return constant | Return 0x25818000                   |
| FUN_06035C4E   | 3     | Read mem+return | Return `*(short*)0x25890008`        |
| FUN_06035C6E   | 3     | Write mem       | Store param to `*(short*)0x25890008`|

### Pure Wrapper / Tail-Call (4 insns)

| Function       | Insns | Type            | Description                           |
|----------------|-------|-----------------|---------------------------------------|
| FUN_06012E00   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012E62   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012E7C   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012E84   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012EBC   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012EC4   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012EDC   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012F00   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012F10   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012F20   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012F50   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012F58   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_06012F60   | 4     | Pure wrapper    | Call FUN_06012c3c with 2 const args   |
| FUN_060409DE   | 4     | Leaf arithmetic | Add two struct fields, return         |
| FUN_06041884   | 4     | Indirect setter | Store via double-deref                |

### Medium Leaf / CALL Functions (5-9 insns)

| Function       | Insns | Type            | Description                           |
|----------------|-------|-----------------|---------------------------------------|
| FUN_06026DF8   | 5     | Leaf mem-op     | Subtract 0x30 from `*(int*)addr`      |
| FUN_0603F92C   | 8     | Leaf multi-store| Store 4 fields at struct offsets       |
| FUN_060058FA   | 9     | CALL chain      | 4 sequential function calls           |
| FUN_06012E6A   | 9     | CALL wrapper    | 2 calls to FUN_06012c3c               |

### Passing Summary by Type

| Category           | Count | Pct  |
|--------------------|-------|------|
| Empty stub (2 ins) | 3     | 11%  |
| Tiny leaf (2-3)    | 6     | 21%  |
| Pure wrapper (4)   | 13    | 46%  |
| Leaf arithmetic    | 4     | 14%  |
| CALL functions     | 2     | 7%   |
| **Total**          | **28**| 100% |

---

## 3. Failure Taxonomy

### 3.1 delta=0: Same Count, Opcode Differences (11 functions)

These produce the exact same number of instructions but differ in opcode selection,
scheduling, or combiner decisions.

| Function       | Ours | Orig | Root Cause Pattern                                   |
|----------------|------|------|------------------------------------------------------|
| FUN_06005174   | 18   | 18   | Scheduling: `add`/`mov.w` swapped order              |
| FUN_0600C970   | 18   | 18   | Range check: orig uses `mov.w`+`cmp/ge`+`bf`; ours uses `mov.l`+`mov.l` (constant pool vs inline) |
| FUN_0600F870   | 20   | 20   | Delayed branch: orig uses `bt`, ours uses `bt.s`     |
| FUN_060149E0   | 10   | 10   | Constant pool: `mov.w` vs `mov.l` + scheduling diff  |
| FUN_06026E0C   | 17   | 17   | Register allocation: `mov` operand regs differ       |
| FUN_060270D0   | 17   | 17   | Register allocation: `mov` operand regs differ       |
| FUN_06032E6C   | 18   | 18   | Combiner: orig has tighter scheduling for muls setup; ours emits extra mov.w/mov sequences |
| FUN_06033520   | 19   | 19   | Scheduling: multiple `mov` operand register diffs    |
| FUN_0603C05C   | 15   | 15   | Constant pool: `mov.l` literal address differs       |
| FUN_06040E88   | 25   | 25   | Combiner: loop compare `bf` vs `bt` + different add/cmp/gt sequence |
| FUN_06042BBE   | 9    | 9    | Multiply avoidance: orig uses `shll2`+`shll2`; ours uses `mul.l`+`sts` |

**Sub-patterns in delta=0:**
- Scheduling/instruction order (3): FUN_06005174, FUN_06033520, FUN_06032E6C
- Constant pool width `mov.w` vs `mov.l` (2): FUN_0600C970, FUN_060149E0
- Register allocation (2): FUN_06026E0C, FUN_060270D0
- Delayed branch insertion (1): FUN_0600F870
- Combiner/loop transform (1): FUN_06040E88
- Multiply vs shift (1): FUN_06042BBE
- Constant pool address (1): FUN_0603C05C

### 3.2 delta=-1 to -2: Our Code Slightly Shorter (21 functions)

Our compiler produces 1-2 fewer instructions, typically from delay slot fills,
branch optimizations, or tail call improvements.

#### delta=-1 (14 functions)

| Function       | Ours | Orig | Root Cause                                            |
|----------------|------|------|-------------------------------------------------------|
| FUN_060054EA   | 11   | 12   | Delay slot fill: eliminated a `mov.l` by filling slot |
| FUN_0600DE40   | 9    | 10   | Delay slot fill: removed `nop` in delay slot (filled with `mov.w`) |
| FUN_0600DE54   | 13   | 14   | Delay slot fill: removed `nop` in delay slot (filled with `mov.l`) |
| FUN_060149CC   | 9    | 10   | Constant pool + scheduling: `mov.w` vs `mov.l` + saved a mov |
| FUN_060192B4   | 10   | 11   | Loop: orig has extra `exts.b` + `dt`+`bf.s`; ours uses `tst`+`bf.s` |
| FUN_06033504   | 9    | 10   | Delay slot fill: removed `nop` in delay slot (filled with `mov.l`) |
| FUN_06035438   | 6    | 7    | Branch sense: orig uses `cmp/pl`+`bf`+`bra`; ours uses `cmp/pl`+`bt` (inverted, no bra) |
| FUN_06035C1C   | 7    | 8    | Delayed branch: orig `bra`+`add`+`bf`; ours `bf.s`+`add` |
| FUN_0603850C   | 9    | 10   | Delayed branch: orig `extu.w`+`bf`; ours `bf.s` fills delay slot |
| FUN_06038520   | 8    | 9    | Delayed branch: orig `extu.w`+`bf`; ours `bf.s` fills delay slot |
| FUN_0603B734   | 11   | 12   | Saved an `add` via address calculation optimization   |
| FUN_0603EF54   | 7    | 8    | Register allocation: saved one `mov` register copy    |
| FUN_06042BAC   | 8    | 9    | Multiply vs shift: orig `shll2`+`shll2`; ours `mul.l`+`sts` (saves 1) |
| FUN_0603F4E0   | 17   | 16   | *Actually delta=+1, miscounted* -- scheduling diff    |

#### delta=-2 (7 functions)

| Function       | Ours | Orig | Root Cause                                            |
|----------------|------|------|-------------------------------------------------------|
| FUN_06006838   | 17   | 19   | Shift combiner: orig `shlr16`+extra moves; ours combines shift ops |
| FUN_06009E02   | 23   | 25   | dt peephole: orig still has `add`+`tst` where we emit `dt` + saved mov |
| FUN_0603307C   | 13   | 15   | Callee-save: orig has extra `sts.l`+`lds.l`+`sts.l` PR save/restore |
| FUN_06035C92   | 5    | 7    | Byte extraction: orig has extra `extu.w`+`mov.l`      |
| FUN_0603B9A4   | 23   | 25   | Branch optimization: ours collapses `add`+`mov.l`+`cmp/eq`+`bf.s` into fewer insns |
| FUN_0603EFD4   | 7    | 9    | Callee-save: orig saves/restores PR (`sts.l`+`lds.l`) where ours does not |
| FUN_0603F1E0   | 6    | 8    | Multiply strength: orig `shll2`+`shll2`+`shll`+`mov`; ours `add`+`shll2` |
| FUN_0603FA00   | 5    | 7    | Address calculation: orig extra `mov`+`mov`+`mov.b`; ours direct |
| FUN_06038A48   | 12   | 14   | Combiner: orig `cmp/hs`+`bt`+`add`; ours `tst`+`bt.s` |
| FUN_060394F0   | 10   | 12   | Delayed branch: orig `bt`+`mov.w`+`bra`+`nop`+`mov.l`; ours `bf.s` |
| FUN_0603F202   | 8    | 10   | Multiply strength: orig shift sequence; ours `add`+`add` |

### 3.3 delta=-3 to -5: Multiple Optimizations (12 functions)

Our compiler is significantly shorter, often due to stacking multiple optimizations
(delay slot fills + branch inversion + tail calls).

| Function       | Ours | Orig | Delta | Root Cause                                         |
|----------------|------|------|-------|----------------------------------------------------|
| FUN_06012D7C   | 17   | 20   | -3    | Branch: orig `bf`+`mov`+extra; ours `bf.s`+`cmp/eq` delayed |
| FUN_0603FFE6   | 16   | 19   | -3    | Delayed branch: orig `bf`+`mov`; ours `bf.s`+`add` |
| FUN_06040680   | 10   | 13   | -3    | Tail call + delay slot: orig `bf`+`lds.l`+`rts`; ours `bf.s` combines |
| FUN_06040EBA   | 20   | 23   | -3    | Range check: orig `cmp/pz`+`bf`+`cmp/ge`+`bf`+`rts`; ours `cmp/hi` single |
| FUN_0603F1F0   | 5    | 9    | -4    | Multiply strength: orig `shll2`*2+`shll`+`shll2`+`add`; ours eliminates |
| FUN_0603F216   | 7    | 11   | -4    | Multiply strength: same pattern as FUN_0603F1F0    |
| FUN_0603F9DA   | 8    | 12   | -4    | Byte extraction: orig `extu.b`*2+extra loads; ours optimized |
| FUN_06034FE0   | 8    | 13   | -5    | Bad decomp: orig has extern const pool ref; ours inlines (in_r0/in_r1 usage) |
| FUN_060336F2   | 2    | 7    | -5    | Bad decomp: ours is trivial `rts`+`nop`; orig has real code (in_r0 passthrough) |
| FUN_0603C156   | 13   | 18   | -5    | Callee-save + constant pool: orig extra `sts.l`+`shar`+`shar`+`mov.w` |
| FUN_0603EF34   | 11   | 16   | -5    | Bad decomp: orig stores 6 fields; ours fewer (struct init mismatch) |
| FUN_06036DDC   | 25   | 30   | -5    | Branch + combiner: orig `bra`+`mov` sequence; ours `cmp/hs`+`bt.s` |

### 3.4 delta < -5: Significantly Shorter (5 functions)

Our output is dramatically shorter, usually indicating decompilation quality issues
where the C source does not accurately represent the original function.

| Function       | Ours | Orig | Delta | Root Cause                                         |
|----------------|------|------|-------|----------------------------------------------------|
| FUN_060192E8   | 17   | 9    | +8*   | **INVERTED**: ours=17 > orig=9; misclassified -- see delta>+5 |
| FUN_06017372   | 19   | 25   | -6    | Byte extraction: orig `extu.b`*2; ours `exts.b` + shift combiner |
| FUN_06035C54   | 10   | 16   | -6    | Callee-save + sign ext: orig `sts.l`+`extu.w`+`mov.l`; ours eliminated |
| FUN_0603316C   | 2    | 9    | -7    | Bad decomp: C source is empty `return;` but orig has real code |
| FUN_060400B4   | 10   | 17   | -7    | Bad decomp + delayed branch: orig `bt`+`bra`+`nop`; ours `bt.s` |
| FUN_0604188C   | 16   | 24   | -8    | Delayed branch + loop: orig `bra`+`nop`*2+`sts`+`mov.l`; ours optimized |
| FUN_0602ECCC   | 4    | 14   | -10   | Bad decomp: orig has `ldc`+`extu.b`+multiple mov.l; C source is oversimplified |
| FUN_06035E00   | 19   | 29   | -10   | Bad decomp: orig has far more memory ops; C source missing logic |

### 3.5 delta=+1 to +2: Our Code Slightly Longer (27 functions)

These are near-matches where our compiler emits 1-2 extra instructions, typically
from constant pool width differences or register allocation.

#### delta=+1 (16 functions)

| Function       | Ours | Orig | Root Cause                                            |
|----------------|------|------|-------------------------------------------------------|
| FUN_0600C928   | 30   | 29   | Callee-save: extra `sts.l`+`mov`+`mov.l` for PR save; orig avoids with `mov.w`+`extu.w` |
| FUN_06011494   | 13   | 12   | Scheduling: extra `extu.w` positioning differs         |
| FUN_0601164A   | 8    | 7    | Constant pool: `mov.l` (4-byte) vs `mov.w` (2-byte) for small constant |
| FUN_0602754C   | 4    | 3    | Instruction choice: orig uses `swap.w`+`rts`+`exts.w` in delay; ours `shlr16`+`rts`+`mov` |
| FUN_0602755C   | 11   | 10   | Constant pool: `mov.l`*2 vs `mov.w`+`mov`             |
| FUN_06028560   | 10   | 9    | Constant pool: `mov.l`*2 vs `mov.w`                   |
| FUN_06034560   | 15   | 14   | Address calc: `mov`+`add`+`mov` vs `mov.l`*3 (constant pool load) |
| FUN_060359DA   | 6    | 5    | Missing tail call: orig `bra`; ours `mov.l`+`rts`     |
| FUN_06035C80   | 10   | 9    | Constant pool: `mov.l`*2 vs `mov.w`+`nop`+`mov`       |
| FUN_06035E3C   | 18   | 17   | Address calc: extra `add` vs orig `mov.w`+`mov` combo  |
| FUN_0603BF5A   | 12   | 10   | Byte extraction: orig `extu.b`; ours `and` + extra add |
| FUN_0603C0A0   | 10   | 9    | Instruction choice: orig `swap.w` vs ours `shlr16`     |
| FUN_0603F3DA   | 15   | 14   | Constant pool: `mov.l`*2 vs `mov.w`+`mov`              |
| FUN_0603F500   | 17   | 16   | Scheduling: `mov.l` load reordered                     |
| FUN_06038F34   | 16   | 15   | Register allocation: extra `mov` register copy          |
| FUN_06040EEC   | 22   | 21   | Combiner: loop compare `bt`+`add`+`cmp/gt` vs `mov.b` direct |

#### delta=+2 (11 functions)

| Function       | Ours | Orig | Root Cause                                            |
|----------------|------|------|-------------------------------------------------------|
| FUN_0601DB84   | 15   | 13   | dt missing: ours `add`+`tst` vs orig `dt`+`bf`+`bra`  |
| FUN_06027348   | 9    | 7    | Constant pool: `mov.l`*2+`add` vs `mov.w` (extern access) |
| FUN_0602853E   | 14   | 12   | Constant pool + scheduling: extra `mov`+`mov.l`*2      |
| FUN_06035E5E   | 18   | 16   | Address calc: extra `mov`+`add` for address computation |

### 3.6 delta=+3 to +5: Decompilation or Constant Pool Issues (13 functions)

| Function       | Ours | Orig | Delta | Root Cause                                         |
|----------------|------|------|-------|----------------------------------------------------|
| FUN_060285E0   | 11   | 8    | +3    | Constant pool + scheduling: `mov.l`*2+`shll8` reordered |
| FUN_06028600   | 11   | 8    | +3    | Constant pool + scheduling: `mov.l`*2+`shll8` reordered (same as above) |
| FUN_06030EE0   | 13   | 10   | +3    | Constant pool + sign ext: `mov.l`*2+`exts.w` vs `mov.w`+`bf` |
| FUN_06038044   | 21   | 18   | +3    | Multiply: ours `mul.l`+`sts` vs orig `shll` shift sequence |
| FUN_0603A766   | 29   | 26   | +3    | Constant pool + byte ext: `mov.l`*2+`extu.w` vs orig inline |
| FUN_06027358   | 19   | 15   | +4    | Extern constant pool: `mov.l`*2 per extern vs `mov.w`+`add` |
| FUN_06027476   | 21   | 17   | +4    | Branch structure: extra `bra`+`mov`+`bt`+`sub` sequence |
| FUN_0602760C   | 13   | 9    | +4    | Loop + movt: extra `mov`*2+`movt`+`mov.b` vs direct `bt.s` loop |
| FUN_0602761E   | 13   | 9    | +4    | Loop + movt: same pattern as FUN_0602760C (word variant) |
| FUN_06027630   | 13   | 9    | +4    | Loop + movt: same pattern as FUN_0602760C (long variant) |
| FUN_06035BC8   | 33   | 29   | +4    | Constant pool + branch: `mov.w` vs `mov.l`*2 + branch diff |
| FUN_06041310   | 20   | 16   | +4    | Extern constant pool: `mov.l`*3 vs `mov.w`*2          |
| FUN_0603B878   | 26   | 21   | +5    | Constant pool + address: `mov`+`mov.l`*2 vs `mov.w`+`add`+`bra` |

### 3.7 delta=+6 to +10: Significant Bloat (14 functions)

| Function       | Ours | Orig | Delta | Root Cause                                         |
|----------------|------|------|-------|----------------------------------------------------|
| FUN_06011678   | 27   | 21   | +6    | Constant pool + byte ext: `mov.l`*2 + missing `extu.w` elim |
| FUN_060122F4   | 31   | 25   | +6    | Extern constant pool: `mov.l`*4 vs `mov.w`*2 (4 extern refs) |
| FUN_0602F7BC   | 26   | 20   | +6    | Constant pool + delayed branch: `mov.l`*2+`mov`+`bt.s` vs `mov.w`+`bt` |
| FUN_06031340   | 23   | 17   | +6    | Combiner + constant pool: `mov`+`shll`+`mov.l` vs `mov.w`+`cmp/ge`+`bt` |
| FUN_0603B96A   | 30   | 24   | +6    | Address calc + constant pool: extra `mov.w`+`mov`+`mov.l`+`cmp/ge` |
| FUN_060359D2   | 10   | 4    | +6    | Bad decomp: C source overcomplicates what is 4-insn function |
| FUN_0601AB8C   | 36   | 29   | +7    | Byte extraction + constant pool: `mov.l`+`mov`+`add`+`mov.b` vs `exts.b`+`shll2` |
| FUN_060283B8   | 25   | 18   | +7    | Loop + byte extraction: extra `mov`+`add`+`mov` vs `and`+`add` |
| FUN_060370C0   | 25   | 18   | +7    | Byte extraction + address: `mov`+`add`+`mov` vs `extu.b`*2 |
| FUN_060192E8   | 17   | 9    | +8    | Bad decomp: C loop with dt; orig is tight 9-insn loop |
| FUN_060424A2   | 23   | 15   | +8    | Multiply + mova: orig uses `mova` for table; ours `shlr16`+`mul.l`+`sts` |
| FUN_0600D336   | 36   | 26   | +10   | Extern constant pool: multiple `mov.l` for extern DAT_ refs vs `mov.w` inline |
| FUN_060282C0   | 39   | 29   | +10   | Constant pool + address calc: `add`+`mov`+`mov.l`*2 vs `mov.w` |
| FUN_06028306   | 39   | 29   | +10   | Constant pool + address calc: identical pattern to FUN_060282C0 |
| FUN_06027344   | 12   | 2    | +10   | Bad decomp: orig is 2-insn inline; C has full extern calculation |

---

## 4. Delta Distribution Table

### Full Function List (sorted by delta)

| Function       | Ours | Orig | Delta | Category                    |
|----------------|------|------|-------|-----------------------------|
| FUN_0602ECCC   | 4    | 14   | -10   | Bad decomp                  |
| FUN_06035E00   | 19   | 29   | -10   | Bad decomp                  |
| FUN_0604188C   | 16   | 24   | -8    | Delayed branch + loop opt   |
| FUN_060400B4   | 10   | 17   | -7    | Bad decomp + delay slot     |
| FUN_0603316C   | 2    | 9    | -7    | Bad decomp (empty vs real)  |
| FUN_06017372   | 19   | 25   | -6    | Byte extraction combiner    |
| FUN_06035C54   | 10   | 16   | -6    | Callee-save + sign ext elim |
| FUN_06034FE0   | 8    | 13   | -5    | Bad decomp (in_r0/in_r1)   |
| FUN_060336F2   | 2    | 7    | -5    | Bad decomp (in_r0)         |
| FUN_0603C156   | 13   | 18   | -5    | Callee-save + const pool    |
| FUN_0603EF34   | 11   | 16   | -5    | Bad decomp (struct init)    |
| FUN_06036DDC   | 25   | 30   | -5    | Branch + combiner           |
| FUN_0603F1F0   | 5    | 9    | -4    | Multiply strength reduction |
| FUN_0603F216   | 7    | 11   | -4    | Multiply strength reduction |
| FUN_0603F9DA   | 8    | 12   | -4    | Byte extraction combiner    |
| FUN_06012D7C   | 17   | 20   | -3    | Delayed branch fill         |
| FUN_0603FFE6   | 16   | 19   | -3    | Delayed branch fill         |
| FUN_06040680   | 10   | 13   | -3    | Tail call + delay slot      |
| FUN_06040EBA   | 20   | 23   | -3    | Range check combiner        |
| FUN_06006838   | 17   | 19   | -2    | Shift combiner              |
| FUN_06009E02   | 23   | 25   | -2    | dt peephole + scheduling    |
| FUN_0603307C   | 13   | 15   | -2    | Callee-save overhead diff   |
| FUN_06035C92   | 5    | 7    | -2    | Byte extraction elimination |
| FUN_0603B9A4   | 23   | 25   | -2    | Branch optimization         |
| FUN_0603EFD4   | 7    | 9    | -2    | Callee-save PR elim         |
| FUN_0603F1E0   | 6    | 8    | -2    | Multiply strength reduction |
| FUN_0603FA00   | 5    | 7    | -2    | Address calc optimization   |
| FUN_06038A48   | 12   | 14   | -2    | Combiner + delayed branch   |
| FUN_060394F0   | 10   | 12   | -2    | Delayed branch fill         |
| FUN_0603F202   | 8    | 10   | -2    | Multiply strength reduction |
| FUN_060054EA   | 11   | 12   | -1    | Delay slot fill             |
| FUN_0600DE40   | 9    | 10   | -1    | Delay slot nop removal      |
| FUN_0600DE54   | 13   | 14   | -1    | Delay slot nop removal      |
| FUN_060149CC   | 9    | 10   | -1    | Constant pool + scheduling  |
| FUN_060192B4   | 10   | 11   | -1    | Loop: tst vs dt pattern     |
| FUN_06033504   | 9    | 10   | -1    | Delay slot nop removal      |
| FUN_06035438   | 6    | 7    | -1    | Branch sense inversion      |
| FUN_06035C1C   | 7    | 8    | -1    | Delayed branch fill         |
| FUN_0603850C   | 9    | 10   | -1    | Delayed branch fill         |
| FUN_06038520   | 8    | 9    | -1    | Delayed branch fill         |
| FUN_0603B734   | 11   | 12   | -1    | Address calc optimization   |
| FUN_0603EF54   | 7    | 8    | -1    | Register alloc saved mov    |
| FUN_06042BAC   | 8    | 9    | -1    | Multiply vs shift           |
| FUN_06005174   | 18   | 18   | 0     | Scheduling order            |
| FUN_0600C970   | 18   | 18   | 0     | Constant pool width         |
| FUN_0600F870   | 20   | 20   | 0     | Delayed branch insertion    |
| FUN_060149E0   | 10   | 10   | 0     | Constant pool + scheduling  |
| FUN_06026E0C   | 17   | 17   | 0     | Register allocation         |
| FUN_060270D0   | 17   | 17   | 0     | Register allocation         |
| FUN_06032E6C   | 18   | 18   | 0     | Combiner scheduling         |
| FUN_06033520   | 19   | 19   | 0     | Scheduling order            |
| FUN_0603C05C   | 15   | 15   | 0     | Constant pool address       |
| FUN_06040E88   | 25   | 25   | 0     | Combiner loop transform     |
| FUN_06042BBE   | 9    | 9    | 0     | Multiply vs shift           |
| FUN_0600C928   | 30   | 29   | +1    | Callee-save overhead        |
| FUN_06011494   | 13   | 12   | +1    | Scheduling                  |
| FUN_0601164A   | 8    | 7    | +1    | Constant pool width         |
| FUN_0602754C   | 4    | 3    | +1    | Instruction choice (swap.w) |
| FUN_0602755C   | 11   | 10   | +1    | Constant pool width         |
| FUN_06028560   | 10   | 9    | +1    | Constant pool width         |
| FUN_06034560   | 15   | 14   | +1    | Address calc                |
| FUN_060359DA   | 6    | 5    | +1    | Missing tail call           |
| FUN_06035C80   | 10   | 9    | +1    | Constant pool width         |
| FUN_06035E3C   | 18   | 17   | +1    | Address calc                |
| FUN_0603BF5A   | 12   | 10   | +2    | Byte extraction             |
| FUN_0603C0A0   | 10   | 9    | +1    | Instruction (swap.w)        |
| FUN_0603F3DA   | 15   | 14   | +1    | Constant pool width         |
| FUN_0603F4E0   | 17   | 16   | +1    | Scheduling                  |
| FUN_0603F500   | 17   | 16   | +1    | Scheduling                  |
| FUN_06038F34   | 16   | 15   | +1    | Register allocation         |
| FUN_06040EEC   | 22   | 21   | +1    | Combiner loop transform     |
| FUN_0601DB84   | 15   | 13   | +2    | dt missing in loop          |
| FUN_06027348   | 9    | 7    | +2    | Extern constant pool        |
| FUN_0602853E   | 14   | 12   | +2    | Constant pool + scheduling  |
| FUN_06035E5E   | 18   | 16   | +2    | Address calc                |
| FUN_060285E0   | 11   | 8    | +3    | Constant pool + scheduling  |
| FUN_06028600   | 11   | 8    | +3    | Constant pool + scheduling  |
| FUN_06030EE0   | 13   | 10   | +3    | Constant pool + sign ext    |
| FUN_06038044   | 21   | 18   | +3    | Multiply pattern            |
| FUN_0603A766   | 29   | 26   | +3    | Constant pool + byte ext    |
| FUN_06027358   | 19   | 15   | +4    | Extern constant pool        |
| FUN_06027476   | 21   | 17   | +4    | Branch structure            |
| FUN_0602760C   | 13   | 9    | +4    | Loop movt pattern           |
| FUN_0602761E   | 13   | 9    | +4    | Loop movt pattern           |
| FUN_06027630   | 13   | 9    | +4    | Loop movt pattern           |
| FUN_06035BC8   | 33   | 29   | +4    | Constant pool + branch      |
| FUN_06041310   | 20   | 16   | +4    | Extern constant pool        |
| FUN_0603B878   | 26   | 21   | +5    | Constant pool + address     |
| FUN_06011678   | 27   | 21   | +6    | Constant pool + byte ext    |
| FUN_060122F4   | 31   | 25   | +6    | Extern constant pool        |
| FUN_0602F7BC   | 26   | 20   | +6    | Constant pool + delay branch|
| FUN_06031340   | 23   | 17   | +6    | Combiner + constant pool    |
| FUN_0603B96A   | 30   | 24   | +6    | Address + constant pool     |
| FUN_060359D2   | 10   | 4    | +6    | Bad decomp                  |
| FUN_0601AB8C   | 36   | 29   | +7    | Byte ext + constant pool    |
| FUN_060283B8   | 25   | 18   | +7    | Loop + byte extraction      |
| FUN_060370C0   | 25   | 18   | +7    | Byte ext + address calc     |
| FUN_060192E8   | 17   | 9    | +8    | Bad decomp (loop mismatch)  |
| FUN_060424A2   | 23   | 15   | +8    | Multiply + mova instruction |
| FUN_0600D336   | 36   | 26   | +10   | Extern constant pool        |
| FUN_060282C0   | 39   | 29   | +10   | Constant pool + address     |
| FUN_06028306   | 39   | 29   | +10   | Constant pool + address     |
| FUN_06027344   | 12   | 2    | +10   | Bad decomp                  |

### Delta Histogram

```
delta <= -10 : ##            (2 functions)
delta  -9..-6: ####          (4 functions)
delta  -5..-3: ############  (12 functions)
delta  -2..-1: ####################  (20 functions)
delta     0  : ###########   (11 functions)
delta  +1..+2: ####################  (20 functions)
delta  +3..+5: #############  (13 functions)
delta  +6..+8: ###########   (11 functions)
delta  +9..+10: ####          (4 functions)
delta >= +11 : (none)
```

### Statistical Summary

| Metric              | Value   |
|---------------------|---------|
| Min delta           | -10     |
| Max delta           | +10     |
| Mean delta          | -0.2    |
| Median delta        | 0       |
| Functions < 0       | 38 (36%)|
| Functions = 0       | 11 (10%)|
| Functions > 0       | 56 (53%)|

---

## 5. Root Cause Pattern Frequency

### Cross-cutting patterns identified from diff analysis

| Pattern ID | Pattern Description                          | Affected Fns | Impact        |
|------------|----------------------------------------------|--------------|---------------|
| CP-WIDTH   | Constant pool `mov.w` vs `mov.l` width       | 32           | +1 to +10 ea |
| SCHED      | Instruction scheduling/ordering differences   | 14           | 0 to +1 ea   |
| DELAY-BR   | Delayed branch (bf.s/bt.s) fill differences   | 15           | -3 to +1 ea  |
| REGALLOC   | Register allocation choices differ            | 8            | 0 to +1 ea   |
| BYTE-EXT   | Byte/word extraction (extu.b/extu.w) combiner | 10           | -2 to +7 ea  |
| MUL-SHIFT  | `mul.l`+`sts` vs `shll2`+`shll` shift seq    | 9            | -4 to +3 ea  |
| CALLEE-SAV | Extra callee-save sts.l/lds.l PR overhead     | 5            | -2 to +1 ea  |
| BAD-DECOMP | C source doesn't match original function      | 9            | -10 to +10   |
| ADDR-CALC  | Address computation strategy differs           | 7            | -2 to +2 ea  |
| LOOP-XFORM | Loop transformation / compare structure        | 6            | -3 to +4 ea  |
| BRANCH-INV | Branch sense inversion (bt vs bf)              | 4            | -3 to -1 ea  |
| MOVT-LOOP  | GCC emits movt for loop-carried boolean        | 3            | +4 each      |
| DT-MISSING | Loop not using dt where original does          | 2            | +2 to +8 ea  |
| TAIL-CALL  | Missing or different tail call optimization    | 2            | +1 ea        |
| SWAP-W     | Original uses swap.w; ours uses shlr16         | 2            | +1 each      |
| MOVA       | Original uses mova for PC-relative table access| 1            | +8           |

---

## 6. Priority Fixes

Ranked by number of functions that would improve (move closer to delta=0 or become PASS).

### Priority 1: Constant Pool Width Optimization (32 functions)

**Impact**: Would improve 32 functions, potentially converting 5-10 to PASS.

The original binary uses `mov.w @(disp,pc),rN` (16-bit constant pool entries) extensively
for values that fit in 16 bits, while our GCC always emits `mov.l @(disp,pc),rN` (32-bit
entries). Each `mov.l` literal costs +1 instruction over `mov.w` for the pool entry itself,
and sometimes +1 for an extra load if the pool is farther away.

**Affected functions**: FUN_0600C970, FUN_0601164A, FUN_0602755C, FUN_06028560, FUN_06035C80,
FUN_0603F3DA, FUN_060285E0, FUN_06028600, FUN_06030EE0, FUN_06027348, FUN_06027358,
FUN_06041310, FUN_060122F4, FUN_0600D336, FUN_060282C0, FUN_06028306, FUN_0602F7BC,
FUN_0603B878, FUN_0603B96A, FUN_06035BC8, FUN_0603A766, FUN_06011678, FUN_06031340,
and 9 more.

**Root cause**: GCC 2.6.3 SH backend puts all symbolic addresses and large constants into
32-bit constant pool entries. The original compiler (likely Hitachi SHC) uses 16-bit
entries for values where the high 16 bits are 0 or 0xFFFF, or for displacement offsets
that fit in a signed 16-bit range.

**Possible fix**: Modify the constant pool output in `sh.c` to prefer `mov.w` when the
constant value fits in signed 16-bit range. This requires changes to `output_far_jump`,
constant pool handling, and possibly the `mov` patterns in `sh.md`.

### Priority 2: Multiply Strength Reduction Pattern (9 functions)

**Impact**: Would improve 9 functions; could convert 3-4 to delta=0.

The original binary uses shift sequences (`shll2`, `shll`, `shll2`+`shll2`) for
multiplication by small constants (0xC, 0x10, 0x18). Our GCC 2.6.3 emits `mul.l`+`sts`
which is 2 instructions but the original compiler avoids the hardware multiplier entirely,
using 3-5 shifts/adds instead.

For some functions our `mul.l` approach is shorter (e.g., FUN_06042BAC at delta=-1), but
for others the shift sequence is what the original uses (FUN_06042BBE at delta=0 uses
shifts, so this is inconsistent).

**Affected functions**: FUN_06042BAC, FUN_06042BBE, FUN_06042BEE, FUN_0603F1E0,
FUN_0603F1F0, FUN_0603F202, FUN_0603F216, FUN_06038044, FUN_060424A2.

**Root cause**: GCC's RTL expander converts `* constant` to `mul.l` when the constant is
not a power of 2. The original Hitachi compiler decomposes multiplications into
shift-add sequences. This is actually a case where BOTH approaches appear in the original
binary depending on context, making this hard to fix without breaking other functions.

### Priority 3: Loop movt Pattern (3 functions, +4 each)

**Impact**: Would improve 3 functions by 4 instructions each.

GCC emits `movt rN` to materialize boolean comparison results for loop-carried variables,
generating extra `mov` register copies. The original compiler integrates the comparison
result directly into the loop control flow with `bt.s` or `bf.s`.

**Affected functions**: FUN_0602760C, FUN_0602761E, FUN_06027630.

**Root cause**: Ghidra decompiles the loop with an explicit boolean variable `bVar1 = iVar2 < param_3 - 1`
that the compiler must materialize with `movt`. If the C source used a `do-while (iVar2 < param_3 - 1)`
structure directly, the branch would be generated without `movt`.

**Fix**: Rewrite C source to use direct comparison in loop condition instead of storing
to intermediate boolean.

### Priority 4: Decompilation Quality (9 functions)

**Impact**: 9 functions with large delta magnitude could be fixed entirely.

Several functions have C source that does not accurately represent the original binary,
causing extreme delta values (both positive and negative).

**Affected functions**:
- FUN_0603316C (delta=-7): C is empty `return;` but orig has real code
- FUN_060336F2 (delta=-5): C is trivial but orig has real code
- FUN_0602ECCC (delta=-10): C oversimplified; orig has register I/O with ldc
- FUN_06035E00 (delta=-10): C missing memory operations
- FUN_0603EF34 (delta=-5): Struct init mismatch
- FUN_06034FE0 (delta=-5): Uses `in_r0`/`in_r1` Ghidra artifacts
- FUN_060192E8 (delta=+8): Loop structure mismatch
- FUN_060359D2 (delta=+6): Overcomplicated C for simple function
- FUN_06027344 (delta=+10): Full C calculation for what is 2-insn inline

**Fix**: Re-examine original disassembly and rewrite C source to match actual behavior.
Functions using Ghidra `in_rN` artifacts need manual decompilation.

### Priority 5: Instruction Scheduling (14 functions)

**Impact**: Would convert 3 delta=0 functions to PASS, improve 11 others by 1 insn.

GCC's instruction scheduler orders operations differently from the original compiler.
This mainly affects delta=0 functions where the instruction count matches but the
sequence differs.

**Root cause**: GCC 2.6.3's instruction scheduler has different heuristics than the
Hitachi compiler. This is extremely difficult to fix as it would require modifying
the scheduler's priority functions.

### Priority 6: Delayed Branch Fill Differences (15 functions)

**Impact**: Mixed -- helps 10 functions (our fill is better), hurts 5 (our fill is wrong).

GCC fills delay slots differently than the original compiler. In many cases our fill is
actually better (saving 1 instruction), but in some cases the original compiler makes
a fill we miss, or we fill where the original intentionally leaves a `nop`.

**Affected delta<0 functions** (our fill better): FUN_0600DE40, FUN_0600DE54, FUN_06033504,
FUN_06035C1C, FUN_0603850C, FUN_06038520, FUN_060394F0, FUN_0603FFE6, FUN_06040680.

**Affected delta>0 functions** (orig fill better): FUN_0600F870, FUN_0602F7BC, FUN_06030EE0.

---

## 7. Appendix: Skip List

8 functions skipped (have .c file but no .expected file):

| Function        | Reason                                         |
|-----------------|------------------------------------------------|
| FUN_060023E6    | No .expected file (no original asm extracted)  |
| FUN_06002404    | No .expected file                              |
| FUN_0600245C    | No .expected file                              |
| FUN_060024D8    | No .expected file                              |
| FUN_0600255C    | No .expected file                              |
| FUN_060026DC    | No .expected file                              |
| FUN_06027552    | No .expected file                              |
| FUN_0603C08C    | No .expected file                              |
| initial_program | No .expected file (special entry point)        |

---

## 8. Path Forward

Based on this analysis, the most impactful improvements would be:

1. **Constant pool width** (Priority 1) -- fix the compiler to emit `mov.w` for
   16-bit-range constants. This is the single largest pattern affecting 32 functions.
   However, it requires significant changes to the constant pool machinery in `sh.c`.

2. **Decompilation re-work** (Priority 4) -- fix 9 functions with bad C source.
   This is purely a decompilation effort with no compiler changes needed, and would
   eliminate the most extreme outliers.

3. **Loop movt elimination** (Priority 3) -- rewrite 3 C sources to avoid boolean
   intermediates. Pure source-level fix, -12 insns total improvement.

4. **Multiply pattern alignment** (Priority 2) -- complex trade-off since both
   `mul.l` and shift-sequence appear in original binary depending on function.

The current pass rate of 21% (28/133) is dominated by small, simple functions
(stubs, wrappers, tiny leafs). The primary blockers for larger functions are:
- Constant pool width differences (affects nearly all non-trivial functions)
- Instruction scheduling (affects delta=0 near-misses)
- Decompilation accuracy (affects extreme outliers)
