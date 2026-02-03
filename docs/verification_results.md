# Compiler Verification Results

Compiled with GCC 2.6.3 (patched for Saturn SH-2) at -O2.
Comparison against original Daytona USA binary disassembly.

## Summary Table

| # | Function | Type | Our Insns | Orig Insns | Delta | Delay Slot | Match Quality |
|---|----------|------|-----------|------------|-------|------------|---------------|
| 1 | FUN_0600D266 | LEAF | 2 | 2 | 0 | n/a | **PERFECT** |
| 2 | FUN_06035C48 | LEAF | 3 | 3 | 0 | - | **PERFECT** |
| 3 | FUN_06035C4E | LEAF | 4 | 3 | +1 | no/yes | sign-extend diff |
| 4 | FUN_06026DF8 | LEAF | 5 | 5 | 0 | yes/yes | **STRUCTURAL MATCH** |
| 5 | FUN_06018EC8 | LEAF | 7 | 7 | 0 | yes/yes | **STRUCTURAL MATCH** |
| 6 | FUN_0601164A | LEAF | 9 | 7 | +2 | yes/yes | extern val overhead |
| 7 | FUN_060149CC | LEAF | 9 | 10 | **-1** | yes/yes | **BETTER** - avoids addr reload |
| 8 | FUN_060149E0 | LEAF | 9 | 10 | **-1** | yes/yes | **BETTER** - avoids addr reload |
| 9 | FUN_060322E8 | LEAF | 11 | 10 | +1 | partial | duplicate rts for 2 paths |
| 10 | FUN_06033504 | LEAF | 9 | 10 | **-1** | yes/no | **BETTER** - fills delay slot |
| 11 | FUN_06030EE0 | LEAF | 16 | 10 | +6 | partial | extern var load overhead |
| 12 | FUN_060192B4 | LEAF | 11 | 11 | 0 | no/no | same count, diff loop |
| 13 | FUN_06005174 | LEAF | 24 | 18 | +6 | yes/yes | no disp addressing mode |
| 14 | FUN_0600C970 | LEAF | 18 | 18 | 0 | no/no | **STRUCTURAL MATCH** |
| 15 | FUN_060054EA | LEAF | 11 | 12 | **-1** | yes/yes | **BETTER** - skips reload |
| 16 | FUN_06006838 | LEAF | 17* | 19 | **-2** | yes/yes | **BETTER** (<<6 version) |
| 17 | FUN_06012E00 | LEAF | 10 | 4 | +6 | no/- | no tail call opt |
| 18 | FUN_0600F870 | CALL | 20 | 20 | 0 | no/no | **STRUCTURAL MATCH** |
| 19 | FUN_06009E02 | CALL | 26 | 25 | +1 | no/yes | unfilled rts delay slot |
| 20 | FUN_06018E70 | CALL | 11 | 12 | **-1** | yes/yes | **BETTER** - direct SP store |
| 21 | FUN_06018EAC | CALL | 10 | 14 | **-4** | yes/yes | **BETTER** - and #imm,r0 |
| 22 | FUN_0600DE40 | CALL | 15 | 10 | +5 | no/yes | no tail call, no bsr |
| 23 | FUN_0600DE54 | CALL | 19 | 14 | +5 | no/yes | no tail call, no bsr |
| 24 | FUN_060210F6 | CALL | 17 | 14 | +3 | yes/yes | no tail call (jmp) |
| 25 | FUN_06014868 | CALL | 18 | 14 | +4 | yes/yes | no tail call + callee-save |

*FUN_06006838 row shows the corrected <<6 version (verify_batch2.sh)

### Statistics
- **Total verified**: 25 functions (17 LEAF + 8 CALL)
- **Perfect/structural match**: 8 functions (32%)
- **Our code shorter**: 7 functions (28%) — up to 4 insns less!
- **Our code longer by 1**: 3 functions (12%)
- **Our code longer by 2+**: 7 functions (28%) — tail call and extern overhead

---

## Batch 3 Detailed Results (13 new functions)

### FUN_0600D266 (2 insns) - PERFECT MATCH
Trivial void return.
```
Our GCC:                    Original:
  rts                       0600D266: rts
  nop                       0600D268: nop
```
Identical.

### FUN_06035C48 (3 insns) - PERFECT MATCH
Return pointer to global.
```
Our GCC:                    Original:
  mov.l L2,r0              06035C48: mov.l @(0x28,PC),r0
  rts                       06035C4A: rts
  nop                       06035C4C: nop
```
Identical instructions, same register r0.

### FUN_06035C4E (3→4 insns) - +1 sign-extend overhead
Read short from hardware register and return as int.
```
Our GCC:                    Original:
  mov.l L2,r1              06035C4E: mov.l @(0x28,PC),r0
  mov.w @r1,r0             06035C50: rts
  rts                       06035C52: mov.w @r0,r0  (delay slot!)
  exts.w r0,r0
```
Original loads address into r0, then in rts delay slot does `mov.w @r0,r0` which
loads 16-bit AND sign-extends in one instruction. Our GCC loads address into r1,
reads through r1, then separately sign-extends. The original's trick of using the
same register for both address and result (exploiting mov.w implicit sign-extend)
is a 1-instruction win.

### FUN_06026DF8 (5 insns) - STRUCTURAL MATCH
Subtract 0x30 from a memory word.
```
Our GCC:                    Original:
  mov.l L2,r2              06026DF8: mov.l @(PC),r1
  mov.l @r2,r1             06026DFA: mov.l @r1,r0
  add #-48,r1              06026DFC: add #-48,r0
  rts                       06026DFE: rts
  mov.l r1,@r2             06026E00: mov.l r0,@r1  (delay slot)
```
Same 5 instructions, same pattern. Both fill rts delay slot with the store.
Only difference is register numbers (r2/r1 vs r1/r0).

### FUN_06018EC8 (7 insns) - STRUCTURAL MATCH
Copy byte value to two VDP2 register addresses.
```
Our GCC:                    Original:
  mov.l L2,r1              06018EC8: mov.w @(0xA,PC),r4
  mov.b @r1,r2             06018ECA: mov.l @(0x10,PC),r2
  mov.l L3,r1              06018ECC: extu.b r4,r3
  mov.b r2,@r1             06018ECE: mov.b r3,@r2
  mov.l L4,r1              06018ED0: mov.l @(0xC,PC),r3
  rts                       06018ED2: rts
  mov.b r2,@r1             06018ED4: mov.b r4,@r3  (delay slot)
```
Same 7 instructions, both fill rts delay slot. Our GCC loads the byte directly
from `val_src+1` (found the byte offset in big-endian short). Original loads
word then uses extu.b to extract byte.

### FUN_0601164A (7→9 insns) - +2 extern value overhead
Write a long constant and a short constant to VDP2 registers.
```
Our GCC (9 insns):
  mov.l L2,r1      ; load addr of dst_long
  mov.l L3,r2      ; load addr of val_long (EXTRA - original has value inline)
  mov.l @r2,r2     ; load val_long (EXTRA)
  mov.l r2,@r1     ; store long
  add #-10,r1      ; offset to second register
  mov.l L4,r2      ; load addr of val_short (EXTRA vs inline value)
  mov.w @r2,r2     ; load val_short (EXTRA)
  rts
  mov.w r2,@r1     ; store short (delay slot)

Original (7 insns):
  mov.l @(PC),r3   ; load VALUE 0x12F2FC00 directly from constant pool
  mov.l @(PC),r2   ; load dst address
  mov.l r3,@r2     ; store long
  mov.w @(PC),r3   ; load VALUE 0x0200 directly from constant pool
  add #-10,r2      ; offset to second register
  rts
  mov.w r3,@r2     ; store short (delay slot)
```
The original stores compile-time constants directly in the constant pool. Our C
uses extern variables requiring address-then-value loads (2 insns per value vs 1).
This is a fundamental toolchain difference for hardware register initialization.

### FUN_06030EE0 (10→16 insns) - +6 extern constant overhead
Conditional decrement of short at indexed array position.
```
Our GCC (16 insns):
  mov.l L3,r1      ; load addr of idx variable
  mov.w @r1,r1     ; load idx as short
  exts.w r1,r0     ; sign-extend
  mov.l L4,r1      ; load addr of base_ptr
  mov.l @r1,r1     ; load base_ptr value
  mov.l @r1,r3     ; load *base_ptr (double deref!)
  mov.w @(r0,r3),r2 ; load short at offset
  exts.w r2,r1     ; sign-extend for comparison
  cmp/pl r1        ; compare > 0
  bf L6            ; branch if not positive
  ... (decrement path with rts+delay)
  L6: rts / nop    ; second exit path

Original (10 insns):
  mov.w @(PC),r0   ; load CONSTANT 0x0150 from pool (1 insn!)
  mov.l @(PC),r1   ; load base_ptr address
  mov.l @r1,r3     ; load *base_ptr
  mov.w @(r0,r3),r2 ; load short at offset
  cmp/pl r2        ; compare > 0
  bf exit          ; branch if not positive
  add #-1,r2       ; decrement
  mov.w r2,@(r0,r3); store back
  rts / nop
```
The original's idx (0x0150) is a compile-time CONSTANT in the constant pool,
loaded with a single `mov.w @(PC),r0`. Our code treats it as an extern variable
requiring 3 instructions (load addr, load val, sign-extend). Also our base_ptr
is `int *` (pointer to pointer) requiring an extra dereference level.

### FUN_060322E8 (10→11 insns) - +1 duplicate rts
Conditional increment of counter, return pointer.
```
Our GCC (11 insns):              Original (10 insns):
  mov.l L4,r0                   060322E8: mov.l @(PC),r0
  mov.b @r0,r1                  060322EA: mov.b @r0,r1
  tst r1,r1                     060322EC: tst r1,r1
  bt L7                         060322EE: bt 0x060322F8
  mov.l L5,r0                   060322F0: mov.l @(PC),r0
  mov.l @r0,r1                  060322F2: mov.l @r0,r1
  add #1,r1                     060322F4: add #1,r1
  rts                            060322F6: mov.l r1,@r0
  mov.l r1,@r0  (delay slot!)   060322F8: rts
  ...                            060322FA: nop
  L7: rts / nop
```
Very close match! Our true-path fills the rts delay slot (BETTER than original's
linear `mov.l / rts / nop`). But we need a separate rts for the false path,
costing +1 instruction. The original shares one rts for both paths.

### FUN_06033504 (10→9 insns) - BETTER by 1
Increment counter by 1, increment offset by 0x20, return base pointer.
```
Our GCC (9 insns):              Original (10 insns):
  mov.l L2,r0                  06033504: mov.l @(PC),r0
  mov.l @r0,r1                 06033506: mov.l @r0,r1
  mov.l L3,r2  ← scheduled!   06033508: add #1,r1
  add #1,r1                    0603350A: mov.l r1,@r0
  mov.l r1,@r0                 0603350C: mov.l @(PC),r2
  mov.l @r2,r1                 0603350E: mov.l @r2,r1
  add #32,r1                   06033510: add #32,r1
  rts                           06033512: mov.l r1,@r2
  mov.l r1,@r2 (delay slot!)   06033514: rts
                                06033516: nop
```
Our GCC schedules the load of the second address earlier (instruction 3) to
eliminate a pipeline stall, then fills the rts delay slot with the final store.
Original doesn't fill the rts delay slot. NET: 1 instruction shorter.

### FUN_060192B4 (11 insns) - SAME COUNT, different loop
Byte-clear loop over memory region.
```
Our GCC loop:                   Original loop:
  mov.b r3,@r2                 060192BA: mov r6,r3
  add #1,r2                    060192BC: exts.b r5,r2
  add #-1,r1                   060192BE: add #1,r6
  tst r1,r1                    060192C0: dt r4
  bf L2                        060192C2: bf/s 0x060192BA
                                060192C4: mov.b r2,@r3  (delay slot)
```
Both 11 total instructions. Key differences:
- Original uses `dt` (decrement-and-test), a single SH-2 instruction. Ours uses `add #-1 / tst`.
- Original uses `bf/s` (branch with delay slot) to execute the store during branching.
- Original has `exts.b r5,r2` sign-extending zero each iteration (wasteful but matches compiler).
- Loop body: 5 insns (ours) vs 5 insns + delay (theirs, effectively 4.5 in throughput).

### FUN_06005174 (18→24 insns) - +6 no displacement addressing
Zero 8 consecutive shorts through a pointer.
```
Our GCC pattern (per short):    Original pattern (per short):
  mov r1,r2                    extu.w r4,r0
  add #N,r2                    mov.w r0,@(N,r5)
  mov.w r3,@r2
```
Original uses `mov.w r0,@(disp,r5)` displacement addressing to store at offset
from base register. Our compiler doesn't emit this form; instead computes each
address with `mov + add + mov.w @r,@r`. This costs 3 insns per store vs 2.
Both fill the rts delay slot with the last store.

### FUN_0600C970 (18 insns) - STRUCTURAL MATCH
Range check (69 ≤ val ≤ 98) then table lookup and accumulate.
```
Our GCC:                        Original:
  (load offset, compute val)    0600C970: mov.w @(PC),r0 (offset)
  add #-69,r2                   0600C972: mov #69,r3
  cmp/hi r1,r2                  0600C974: mov.l @(r0,r4),r5
  bt L2 (skip)                  0600C976: cmp/ge r3,r5
  mov r3,r0                     0600C978: bf (skip)
  add r3,r0  (val*2)            0600C97A: mov #98,r3
  mov.l L4,r1 (table-138)      0600C97C: cmp/gt r3,r5
  mov.w @(r0,r1),r1             0600C97E: bt (skip)
  mov.l @(12,r4),r2             0600C980: add #-69,r5
  add r2,r1                     0600C982: shll r5
  mov.l r1,@(12,r4)             0600C984-8E: table lookup + add
```
Same 18 instructions but different strategies:
- **Range check**: GCC transforms `val>=69 && val<=98` into `(unsigned)(val-69) <= 29`
  using one `cmp/hi` instead of two comparisons. Clever optimization!
- **Table index**: GCC pre-adjusts base address (table-138) to avoid subtracting 69
  from index at runtime. Uses `add r3,r3` (val*2) instead of `shll` (same effect).
- Original uses two separate comparisons (`cmp/ge` + `cmp/gt`).

### FUN_060054EA (12→11 insns) - BETTER by 1
Store parameter, zero three memory locations.
```
Our GCC (11 insns):             Original (12 insns):
  mov.l L2,r1                  060054EA: mov.l @(PC),r3
  mov.l r4,@r1                 060054EC: mov.l r4,@r3
  mov.l L3,r1                  060054EE: mov #0,r4
  mov #0,r2                    060054F0: mov.l @(PC),r3
  mov.w r2,@r1                 060054F2: mov.w r4,@r3
  mov.l L4,r1                  060054F4: mov.l @(PC),r3
  mov #0,r2 ← redundant!      060054F6: mov.l r4,@r3
  mov.l r2,@r1                 060054F8: mov r3,r1 ← wasteful
  mov.l L5,r1                  060054FA: mov.l @r1,r1 ← reads back 0
  rts                           060054FC: mov.l @(PC),r3
  mov.l r2,@r1 (delay slot)   060054FE: rts
                                06005500: mov.l r1,@r3 (delay slot)
```
Both fill rts delay slot. Our code has a redundant `mov #0,r2` (GCC doesn't track
that r2 is already 0). Original has a wasteful read-after-write (`mov r3,r1 /
mov.l @r1,r1` reads back the 0 it just wrote). Both sides have a 1-instruction
inefficiency, but ours is still 1 instruction shorter overall.

### FUN_06012E00 (4→10 insns) - No tail call optimization
Load two constant args and call file loader function.
```
Our GCC (10 insns):             Original (4 insns):
  sts.l pr,@-r15               06012E00: mov.l @(PC),r5
  mov.l L2,r1                  06012E02: mov.l @(PC),r4
  mov.l @r1,r5                 06012E04: bra FUN_06012C3C
  mov.l L3,r4                  06012E06: nop
  mov.l L4,r1
  jsr @r1
  nop
  lds.l @r15+,pr
  rts
  nop
```
The original uses `bra` (branch always) as a tail call - no pr save/restore
needed. GCC 2.6.3 always uses full jsr/rts calling convention. This is a known
compiler limitation and the biggest single source of code bloat for wrapper functions.
Also: original loads constant VALUES directly from pool; our code loads extern
variable addresses then dereferences.

---

## Batch 4: CALL Functions (6 new)

### FUN_06018E70 (12→11 insns) - BETTER by 1
Stack local initialization + indirect function call.
```
Our GCC (11 insns):             Original (12 insns):
  sts.l pr,@-r15               06018E70: sts.l pr,@-r15
  add #-8,r15                  06018E72: mov #3,r2
  mov #3,r1                    06018E74: add #-8,r15
  mov.l r1,@r15 ← direct!     06018E76: mov r15,r3 ← copy SP
  mov.l L2,r0                  06018E78: mov.l r2,@r3
  jsr @r0                      06018E7A: mov.l @(PC),r3
  mov r15,r4  (delay slot!)    06018E7C: jsr @r3
  add #8,r15                   06018E7E: mov r15,r4  (delay slot)
  lds.l @r15+,pr               06018E80-86: dealloc + rts
  rts / nop
```
Our GCC stores directly to `@r15` without copying SP to another register.
Original copies r15→r3 then stores through r3 (1 extra insn). Both fill
jsr delay slot with argument setup.

### FUN_06018EAC (14→10 insns) - BETTER by 4!
Stack array + function call + byte mask.
```
Our GCC (10 insns):             Original (14 insns):
  sts.l pr,@-r15               06018EAC: sts.l pr,@-r15
  add #-16,r15                 06018EAE: add #-12,r15
  mov.l L2,r0                  06018EB0: mov.l @(PC),r3
  jsr @r0                      06018EB2: jsr @r3
  mov r15,r4  (delay!)         06018EB4: mov r15,r4  (delay)
  mov.b @r15,r0                06018EB6: mov r15,r0
  add #16,r15                  06018EB8: mov #31,r4
  lds.l @r15+,pr               06018EBA: mov.b @r0,r0
  rts                           06018EBC: add #12,r15
  and #31,r0 (delay!)          06018EBE: extu.b r0,r0
                                06018EC0: lds.l @r15+,pr
                                06018EC2: and r0,r4
                                06018EC4: rts
                                06018EC6: mov r4,r0 (delay)
```
**KEY FINDING**: Our GCC uses `and #31,r0` (R0-specific immediate AND, 1 insn).
Original doesn't use this form — instead does `mov #31,r4 / extu.b r0,r0 /
and r0,r4 / mov r4,r0` (4 insns for the same operation!). Our GCC also reads
byte directly with `mov.b @r15,r0` (1 insn) vs original's `mov r15,r0 /
mov.b @r0,r0` (2 insns).

### FUN_0600DE40 (10→15 insns) - +5 no tail call
Arithmetic shift + store + 2 direct function calls.
```
Our GCC (15 insns):             Original (10 insns):
  sts.l pr,@-r15               0600DE40: sts.l pr,@-r15
  mov.l L2,r1                  0600DE42: mov.l @(PC),r3 (source)
  mov.l @r1,r1                 0600DE44: mov.l @(PC),r2 (target)
  mov.l L3,r2                  0600DE46: mov.l @r3,r3
  shar r1                      0600DE48: shar r3
  mov.w r1,@r2                 0600DE4A: mov.w r3,@r2
  mov.l L4,r1                  0600DE4C: bsr FUN_0600E410
  jsr @r1 / nop                0600DE4E: nop
  mov.l L5,r1                  0600DE50: bra FUN_0600E0C0 (TAIL!)
  jsr @r1 / nop                0600DE52: lds.l @r15+,pr  (delay!)
  lds.l @r15+,pr / rts / nop
```
All +5 insns from calling convention: original uses `bsr` (direct relative call,
no const pool entry) + `bra/lds.l` tail call. GCC uses `jsr @r1` (needs const
pool load) + full jsr/lds.l/rts for second call.

### FUN_0600DE54 (14→19 insns) - +5 no tail call
Same pattern as FUN_0600DE40 with additional memory copy. Same +5 overhead
from no tail call + jsr-through-register vs bsr direct.

### FUN_060210F6 (14→17 insns) - +3 no tail call (jmp)
Three function calls + flag set.
```
Our GCC fills 1st jsr delay slot with `mov #8,r4` — good!
Original uses `jmp @r3` for tail call (indirect jump, no PR involvement).
GCC uses full jsr/lds.l/rts for last call = +3 insns.
```
Original uses `jmp @r3 / lds.l @r15+,pr` for indirect tail calls (complement
to `bra target` for direct tail calls).

### FUN_06014868 (14→18 insns) - +4 no tail call + callee-save overhead
Three calls with parameter pass-through.
```
Our GCC: saves params in callee-saved r12/r13 (2 push + 2 pop + 2 mov = 6 insns)
Original: saves params on STACK using displacement stores (2 stores + 2 reloads = 4 insns)
  + fills jsr delay slots with param saves!
  + uses jmp @r3 tail call for last function
```
Original is more efficient at parameter preservation across calls: uses stack
with displacement addressing (`mov.l r6,@(0x4,r15)`) instead of callee-saved
registers. This avoids the push/pop overhead for r12/r13.

---

## Previously Verified (Batch 1-2)

### FUN_06006838 (19→17 insns) - BETTER by 2 (with <<6 fix)
Coordinate-to-tile arithmetic. **CRITICAL**: Must use `<< 6` not `* 64` to avoid
`___mulsi3` library call. With shift fix, our output is 17 insns vs original's 19.
See verify_batch2.sh for the corrected version.

### FUN_060149CC (10→9 insns) - BETTER by 1
Bit OR with 0x8000 + set flag. Our GCC keeps address in register, avoiding the
original's redundant address reload. Both fill rts delay slot.

### FUN_060149E0 (10→9 insns) - BETTER by 1
Bit AND with 0x7FFF + set flag. Same improvement as FUN_060149CC.

### FUN_0600F870 (CALL, 20 insns) - STRUCTURAL MATCH
Counter decrement + conditional flag set. Same instruction count.
Differences: register numbering, 2 instructions reordered.

### FUN_06009E02 (CALL, 25→26 insns) - +1
Counter decrement, conditional state set, two calls, flag set.
1-instruction gap from unfilled rts delay slot.

---

## Key Findings

### Compiler Capabilities Confirmed
1. **rts delay slot filling**: GCC fills rts delay slot in many cases
   (FUN_06026DF8, FUN_06018EC8, FUN_06033504, FUN_060054EA, FUN_060322E8, FUN_06018EAC)
2. **jsr delay slot filling**: GCC fills jsr delay slots with argument setup
   (FUN_06018E70, FUN_060210F6, FUN_06014868)
3. **Instruction scheduling**: GCC schedules loads earlier to avoid stalls
   (FUN_06033504 loads second address during first increment)
4. **Range check optimization**: GCC transforms `a <= x <= b` into `(unsigned)(x-a) <= (b-a)`
   using single unsigned compare (FUN_0600C970)
5. **R0-specific immediate instructions**: GCC uses `and #imm,r0` (1 insn) where
   original uses 4-insn sequence. Major win for byte masking (FUN_06018EAC: -4 insns!)
6. **Direct SP access**: GCC stores through r15 directly instead of copying SP to
   another register (FUN_06018E70: -1 insn)
7. **Address pre-adjustment**: GCC pre-subtracts constant offsets from base addresses
   to eliminate runtime index adjustment (FUN_0600C970: table-138)

### Systematic Compiler Limitations
1. **No tail call optimization** (BIGGEST impact): GCC always uses full jsr/lds.l/rts.
   Original uses `bra target` (direct) or `jmp @rN` (indirect) for tail calls.
   Costs +3 to +5 insns per wrapper function. Affects ALL CALL functions ending in a call.
2. **No `bsr` direct relative calls**: GCC uses `mov.l @(PC),rN / jsr @rN` (2 insns).
   Original uses `bsr target` (1 insn) for calls within ±4KB. Costs +1 per call.
3. **No `dt` instruction**: GCC emits `add #-1 / tst` instead of SH-2's `dt`
   (decrement-and-test). Affects all counted loops.
4. **No `bf/s` delayed branch**: GCC never uses `bf/s` or `bt/s` to fill branch
   delay slots. Original compiler does this frequently.
5. **No displacement store addressing**: GCC doesn't emit `mov.w Rm,@(disp,Rn)`.
   Costs +1 insn per store with offset.
6. **Callee-saved register preference**: GCC saves params to callee-saved regs
   (r8-r14) across calls, requiring push/pop. Original saves to stack with
   displacement stores (`mov.l rN,@(disp,r15)`), which is more efficient.
7. **Extern vs. constant pool values**: C externs cost +1 insn per constant load
   vs original's inline constant pool values.

### Patch Priority for Improving Match Rate
1. **Tail call optimization** (HIGHEST) - Would save 3-5 insns per CALL function.
   Most impactful single change. Original uses `bra`/`jmp` + `lds.l` in delay slot.
2. **`bsr` for nearby calls** (HIGH) - Would save 1 insn per function call within range.
3. **`dt` instruction emission** (HIGH) - Would fix loop codegen for all counted loops.
4. **`bf/s` delayed branch** (HIGH) - Would improve branch-heavy code throughout.
5. **Displacement store modes** (MEDIUM) - Would fix sequential memory initialization.
6. **Stack-based param preservation** (LOW) - Alternative to callee-saved registers.
7. **Register value tracking** (LOW) - Would eliminate occasional redundant loads.
