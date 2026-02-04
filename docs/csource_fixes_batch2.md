# C Source Fixes - Batch 2

Analysis of 9 functions where our GCC 2.6.3 output is longer than the original binary.
For each function: root cause analysis, original disassembly walkthrough, and proposed fix.

---

## FUN_06030EE0 (delta=+4, ours=14, orig=10)

### Original Assembly (06030EE0-06030EF2)
```
mov.w   @(0x10,PC),r0    ; r0 = 0x0150
mov.l   @(0x14,PC),r1    ; r1 = *(0x0607E940)  -- pointer to base
mov.l   @r1,r3           ; r3 = *r1 (dereference pointer)
mov.w   @(r0,r3),r2      ; r2 = *(short*)(r3 + 0x150)  -- indexed word read
cmp/pl  r2               ; test r2 > 0
bf      0x06030EF0       ; if not, skip
add     #-1,r2           ; r2--
mov.w   r2,@(r0,r3)      ; write back decremented value (indexed word write)
rts                       ; return
nop                       ; delay slot (return value is r0 = 0x0150)
```

**Key insight**: The original uses `mov.w @(r0,r3),r2` (indexed addressing with r0) and
`mov.w r2,@(r0,r3)` to both read and write the half-word. It keeps the displacement 0x0150
in r0 throughout, which also serves as the return value. This requires only 10 instructions.

### Our Compiler Output (14 instructions)
```
mov.l   L3,r0            ; r0 = *(0x0607E940)
mov.w   L4,r3            ; r3 = 0x0150
mov.l   @r0,r0           ; r0 = *r0 (dereference)
mov     r0,r2            ; r2 = r0 (copy base)
add     r3,r2            ; r2 = base + 0x0150
mov.w   @r2,r1           ; r1 = *(short*)r2
exts.w  r1,r0            ; sign-extend for comparison
cmp/pl  r0
bf.s    L2
mov     r1,r0            ; move (delay slot)
add     #-1,r0
mov.w   r0,@r2           ; write back
rts
mov     r3,r0            ; r0 = 0x0150 (return value in delay slot)
```

### Root Cause
1. **No indexed addressing**: GCC computes `base + 0x0150` into a register and uses `@r2`
   instead of the SH-2 indexed `@(r0,rN)` addressing mode. This costs +2 instructions
   (the `mov r0,r2` and `add r3,r2`).
2. **Unnecessary sign extension**: GCC inserts `exts.w r1,r0` before the `cmp/pl`. The
   original avoids this by doing `cmp/pl` directly on the `mov.w` result (which is already
   sign-extended on SH-2).
3. **Extra register shuffling**: The `mov r1,r0` in the delay slot is wasted.

### Diagnosis: COMPILER LIMITATION
This is fundamentally a register allocation and addressing mode selection issue in GCC 2.6.3.
The original compiler uses the `@(r0,rN)` indexed addressing mode (which requires the
displacement to be in r0 specifically). GCC 2.6.3 does not emit this addressing mode for
variable+offset patterns. **No C source fix is possible** -- the difference is in instruction
selection and addressing modes.

### Possible C Source Restructure (may reduce by 1-2 insns but not match)
```c
int FUN_06030ee0()
{
  short *p;
  int offset = 0x0150;

  p = (short *)(*(int *)0x0607E940 + offset);
  if (*p > 0) {
    *p = *p - 1;
  }
  return offset;
}
```
**Verdict**: No change possible. The delta is caused by GCC not using `@(r0,rN)` indexed
addressing. This is a **compiler limitation**, not a C source issue.

---

## FUN_060122F4 (delta=+3, ours=28, orig=25)

### Original Assembly (060122F4-06012324)
```
mov.l   @(0x3C,PC),r4    ; r4 = 0x060788B4  (base pointer, kept in r4 throughout)
mov.w   @(0x2C,PC),r3    ; r3 = 0x2999
mov.l   @(0x4,r4),r2     ; r2 = *(base+4)
sub     r3,r2             ; r2 -= 0x2999
mov.l   r2,@(0x4,r4)     ; *(base+4) = r2
mov.w   @(0x26,PC),r3    ; r3 = 0x4000
mov.l   @(0x8,r4),r2     ; r2 = *(base+8)
sub     r3,r2             ; r2 -= 0x4000
mov.l   r2,@(0x8,r4)     ; *(base+8) = r2
mov.l   @(0x30,PC),r5    ; r5 = 0x00020000
mov.l   @(0x4,r4),r3     ; r3 = *(base+4) [re-read]
cmp/ge  r5,r3             ; r3 >= 0x20000?
bt      skip1             ; yes -> skip
mov.l   r5,@(0x4,r4)     ; *(base+4) = 0x20000  (clamp)
; skip1:
mov.l   @(0x28,PC),r5    ; r5 = 0x0004CCCC
mov.l   @(0x8,r4),r3     ; r3 = *(base+8) [re-read]
cmp/ge  r5,r3             ; r3 >= 0x4CCCC?
bt      skip2             ; yes -> skip
mov.l   r5,@(0x8,r4)     ; *(base+8) = 0x4CCCC  (clamp)
; skip2:
mov.l   @(0x24,PC),r5    ; r5 = 0x060788B2
mov.w   @(0xA,PC),r3     ; r3 = 0x1800
mov.w   @r5,r2            ; r2 = *(short*)0x060788B2
add     r3,r2             ; r2 += 0x1800
rts
mov.w   r2,@r5            ; write back (in delay slot)
```

### Our Compiler Output (28 instructions)
```
mov.l   L4,r3            ; r3 = 0x060788B4 -> wrong! loads @(4) into separate address
mov.l   L5,r2            ; r2 = 0x060788B8 (base+4 address direct)
mov.w   L6,r1            ; r1 = -10649 (0xD697 = -0x2999, signed)
mov.l   @r2,r0           ; r0 = *(base+4)
add     r1,r0            ; r0 -= 0x2999 (via add negative)
mov.l   r0,@r2           ; *(base+4) = r0
mov.w   L7,r0            ; r0 = -16384 (0xC000 = -0x4000, signed)
mov.l   @(8,r3),r1       ; r1 = *(base+8)
mov     r1,r2            ;   (extra copy)
add     r0,r2            ; r2 -= 0x4000
mov.l   r2,@(8,r3)       ; *(base+8) = r2
mov.l   L8,r1            ; r1 = 0x0001FFFF (131071 -- WRONG! should be 0x20000)
mov.l   @(4,r3),r0
cmp/gt  r1,r0            ; r0 > 0x1FFFF => r0 >= 0x20000
bt      L2
mov.l   L9,r0            ; r0 = 0x20000
mov.l   r0,@(4,r3)
; L2:
mov.l   L10,r0           ; r0 = 0x0004CCCC-1 = 0x4CCBB (314571)
cmp/gt  r0,r2
bt      L3
mov.l   L11,r0           ; r0 = 0x4CCCC
mov.l   r0,@(8,r3)
; L3:
mov.l   L12,r0           ; r0 = 0x060788B2
mov.w   L13,r1           ; r1 = 0x1800
mov.w   @r0,r2
add     r1,r2
rts
mov.w   r2,@r0
```

### Root Cause
1. **Subtraction encoded as `add negative`**: The original uses `sub r3,r2` with the positive
   constant 0x2999 loaded separately. Our C code uses `- 0x2999` which GCC encodes as
   `add #(-0x2999)` via a `mov.w` of the negative value. This is equivalent but uses
   a different constant pool layout.
2. **Comparison expansion**: The original uses `cmp/ge r5,r3` (compare-greater-or-equal)
   directly with the threshold value 0x20000. Our GCC generates `cmp/gt r1,r0` with
   the threshold minus one (0x1FFFF), requiring an extra constant pool entry. This costs
   +2 instructions (separate constants for cmp and clamp value).
3. **Address calculation for base+4**: GCC generates a separate address for `base+4`
   (`0x060788B8` in L5) instead of using `@(4,r4)` displacement addressing, costing +1.

### Diagnosis: C SOURCE STRUCTURE + COMPILER BEHAVIOR
The original code keeps the base pointer in `r4` and uses displacement addressing `@(4,r4)`
and `@(8,r4)` consistently. Our C source computes `puVar1 + 4` and `puVar1 + 8` as separate
memory operations rather than struct-field style accesses.

### Proposed C Source Fix
Use a struct pointer or int-pointer-based displacement to encourage GCC to use `@(disp,rN)`:

```c
void FUN_060122f4()
{
  int *base;
  int val4, val8;
  short *pw;

  base = (int *)0x060788B4;

  val4 = base[1] - 0x2999;
  base[1] = val4;

  val8 = base[2] - 0x4000;
  base[2] = val8;

  if (val4 < 0x00020000) {
    base[1] = 0x00020000;
  }

  if (val8 < 0x0004CCCC) {
    base[2] = 0x0004CCCC;
  }

  pw = (short *)0x060788B2;
  *pw = *pw + 0x1800;
}
```

The key changes:
- Use `int *base` and array indexing `base[1]`, `base[2]` to encourage displacement addressing
- Keep subtracted values in locals for the comparison (avoids re-reading from memory)
- Use `< threshold` instead of re-reading (matches original which re-reads but uses cmp/ge)

**Note**: The comparison direction difference (`cmp/ge` vs `cmp/gt`) is a compiler issue.
The original uses `cmp/ge r5,r3` checking if value >= threshold. GCC may encode
`value < threshold` as `!(value > threshold-1)`, which adds a constant. Using `val4 < X`
should produce `cmp/ge` on GCC 2.6.3.

---

## FUN_06011678 (delta=+3, ours=24, orig=21)

### Original Assembly (06011678-060116A0)
```
mov.l   r14,@-r15         ; save r14
mov.l   r13,@-r15         ; save r13
mov.l   r12,@-r15         ; save r12
sts.l   pr,@-r15           ; save PR
mov.w   @(0x1E,PC),r13    ; r13 = 0x0100 (loop limit)
mov.l   @(0x20,PC),r12    ; r12 = 0x25E5F800 (base address)
bsr     FUN_0601164A       ; call function
mov     #0,r14             ; r14 = 0 (loop counter) [delay slot]
extu.w  r14,r4             ; r4 = r14 & 0xFFFF  (loop body starts here)
extu.w  r4,r0              ; r0 = r4 & 0xFFFF (redundant but needed for shll2)
shll2   r0                 ; r0 = r0 * 4
add     #1,r4              ; r4++ (counter in r4 now!)
extu.w  r4,r3              ; r3 = r4 & 0xFFFF
cmp/ge  r13,r3             ; r3 >= 0x100?
bf/s    0x0601168A          ; loop back if not
mov.l   r14,@(r0,r12)      ; *(base + r0) = r14 = 0 [delay slot - uses r14 which is 0]
lds.l   @r15+,pr           ; restore PR
mov.l   @r15+,r12          ; restore r12
mov.l   @r15+,r13          ; restore r13
rts
mov.l   @r15+,r14          ; restore r14 [delay slot]
```

### Our Compiler Output (24 instructions)
```
mov.l   r9,@-r15
mov.l   r8,@-r15
sts.l   pr,@-r15
mov.l   L6,r9              ; r9 = 0x25E5F800
mov.w   L7,r8              ; r8 = 0x0100
bsr     _FUN_0601164a
nop                         ; <-- wasted delay slot
mov     #0,r1              ; counter = 0
mov.l   L8,r2              ; r2 = 0xFFFF (mask constant!)
mov     r1,r0
; L10 (loop):
and     r2,r0              ; r0 = counter & 0xFFFF
add     #1,r1
shll2   r0
mov     #0,r3              ; <-- reloads zero EVERY iteration!
mov.l   r3,@(r0,r9)
mov     r1,r0
and     r2,r0              ; <-- extra extu.w emulation
cmp/ge  r8,r0
bf.s    L10
mov     r1,r0              ; delay slot
lds.l   @r15+,pr
mov.l   @r15+,r8
rts
mov.l   @r15+,r9
```

### Root Cause
1. **Wasted bsr delay slot**: The `nop` after `bsr` wastes 1 instruction. The original puts
   `mov #0,r14` in the delay slot.
2. **`& 0xFFFF` emulated with AND mask**: GCC loads `0xFFFF` into a register and uses `and`,
   costing a constant pool load (+1) plus repeated `and` in the loop. The original uses
   `extu.w` (zero-extend word) which is a single instruction, no constant needed.
3. **Zero reloaded every iteration**: `mov #0,r3` is inside the loop body. The original
   cleverly stores r14 (which remains 0 throughout) via `mov.l r14,@(r0,r12)` in the
   bf/s delay slot.
4. **Extra register save/restore**: Original saves r12/r13/r14 (3 callee-saved). Ours saves
   r8/r9 (2 callee-saved) but uses more instructions in the loop body, netting worse.

### Diagnosis: C SOURCE ISSUE + COMPILER BEHAVIOR
The `& 0xffff` masks in the C source force GCC to emit AND with a constant. The original
uses `extu.w` because it treats the variable as `unsigned short`. Also, the loop structure
with `uVar3 & 0xffff` before and after increment is redundant.

### Proposed C Source Fix
```c
extern void FUN_0601164a();

void FUN_06011678()
{
  int *p;
  int i;

  p = (int *)0x25E5F800;

  FUN_0601164a();

  for (i = 0; i < 0x0100; i++) {
    p[i] = 0;
  }
}
```

Key changes:
- Remove the explicit `& 0xffff` masking. Since the loop counter goes 0..255, unsigned
  short truncation is unnecessary. A simple `int i < 0x100` produces the same `extu.w`
  or direct comparison.
- Use `int *p` with array indexing `p[i]` instead of manual shift-and-cast. GCC should
  generate `shll2` + indexed store automatically.
- Remove `uVar2`/`uVar3` indirection.

**Note**: Even with this fix, the bsr delay slot nop is a compiler scheduling issue. We may
still be +1 from the original.

---

## FUN_0602766C (delta=+3, ours=18, orig=15)

### Original Assembly (0602766C-06027688)
```
mov.l   @(0x1C,PC),r0    ; r0 = 0x25FE007C (poll register address)
mov.l   @r0,r0            ; r0 = *0x25FE007C (read status)
mov.l   @(0x1C,PC),r1    ; r1 = 0x0000272E (mask)
tst     r1,r0             ; test r0 & r1
bf      0x0602766C        ; loop if non-zero (busy wait)
mov.l   @(0x1C,PC),r1    ; r1 = 0x25FE0000 (DMA base)
mov.w   @(0xE,PC),r2     ; r2 = DAT_0602768a (short value = 0x0101)
mov.l   r4,@(0x4,r1)     ; base[1] = param_1
mov.l   r5,@(0x0,r1)     ; base[0] = param_2
mov.l   r6,@(0x8,r1)     ; base[2] = param_3
mov.l   r2,@(0xC,r1)     ; base[3] = val (sign-extended short)
mov     #7,r0             ; r0 = 7
mov.l   r0,@(0x14,r1)    ; base[5] = 7
rts
mov.l   r2,@(0x10,r1)    ; base[4] = val [delay slot]
```

### Our Compiler Output (18 instructions)
```
mov.l   L6,r2            ; r2 = 0x25FE0000 (base, loaded eagerly)
mov.l   L7,r3            ; r3 = &REG_25FE007C (extern address!)
mov.w   L8,r1            ; r1 = 0x272E (mask as immediate)
; L4:
mov.l   @r3,r0           ; r0 = *(&REG_25FE007C) -- extra indirection!
and     r1,r0            ; r0 &= mask
tst     r0,r0
bf      L4
mov.l   L9,r0            ; r0 = &DAT_0602768a (extern address!)
mov.w   @r0,r1           ; r1 = *DAT_0602768a -- extra indirection!
mov.l   r4,@(4,r2)
mov.l   r5,@r2
mov.l   r6,@(8,r2)
mov.l   r1,@(12,r2)
mov     #7,r0
mov.l   r0,@(20,r2)
mov.l   r1,@(16,r2)
rts
nop
```

### Root Cause
1. **Extern indirection for REG_25FE007C**: The C source declares `extern volatile int
   REG_25FE007C`, which means GCC loads the address of the extern symbol from the constant
   pool, then dereferences. The original embeds the address `0x25FE007C` directly in the
   constant pool and dereferences it in one step. This costs +1 per extern.
2. **Extern indirection for DAT_0602768a**: Same issue -- `extern short DAT_0602768a` causes
   a two-step load (load address of symbol, then load value). The original loads the address
   as a constant and reads directly. Cost: +1.
3. **`and` + `tst` instead of just `tst`**: The original uses `tst r1,r0` which computes
   `r1 & r0` and sets T flag without modifying registers. Our GCC emits `and r1,r0` then
   `tst r0,r0`, costing +1. This is because GCC uses `and` to mask, then `tst` to check,
   while the original just uses `tst` which is an AND-and-test in one instruction.

### Diagnosis: EXTERN SYMBOL INDIRECTION + TST PATTERN
The extern variables cause an extra level of indirection. The `& mask` comparison pattern
does not produce the `tst` instruction directly.

### Proposed C Source Fix
```c
void FUN_0602766c(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  volatile int *base;
  volatile int *poll;
  short val;

  poll = (volatile int *)0x25FE007C;
  base = (volatile int *)0x25FE0000;

  do {
  } while ((*poll & 0x0000272E) != 0);

  val = *(short *)0x0602768A;
  base[1] = param_1;
  base[0] = param_2;
  base[2] = param_3;
  base[3] = (int)val;
  base[5] = 7;
  base[4] = (int)val;
}
```

Key changes:
- Replace `extern volatile int REG_25FE007C` with a direct volatile pointer
  `*(volatile int *)0x25FE007C`. This embeds the address directly in the constant pool.
- Replace `extern short DAT_0602768a` with `*(short *)0x0602768A`. Same reason.
- The `& mask` vs `tst` issue may still remain as a compiler pattern (+1).

---

## FUN_0600D336 (delta=+2, ours=28, orig=26)

### Original Assembly (0600D336-06027688)
```
mov.l   @(0x40,PC),r5    ; r5 = 0x06078900 (base A)
mov.w   @(0x2E,PC),r3    ; r3 = 0x0268 (offset to base B)
mov.l   @(0x34,PC),r2    ; r2 = 0x0607EBC4 (flags address)
mov     r5,r4             ; r4 = base A (copy)
mov.l   @r2,r2            ; r2 = *flags
add     r3,r5             ; r5 = base A + 0x268 = base B
mov.l   @(0x30,PC),r3    ; r3 = 0x00200000 (bit mask)
and     r3,r2             ; r2 &= 0x200000
tst     r2,r2             ; test if zero
bf      end               ; skip if flag is set
mov     #1,r7             ; r7 = 1 (constant for winner)
mov.w   @(0x1C,PC),r0    ; r0 = 0x01F4 (offset for comparison field)
mov.l   @(r0,r4),r3      ; r3 = base_A[0x1F4] (player A value)
mov.l   @(r0,r5),r2      ; r2 = base_B[0x1F4] (player B value)
cmp/ge  r2,r3             ; r3 >= r2? (A >= B?)
bf/s    else              ; branch if A < B
mov     #0,r6             ; r6 = 0 (loser) [delay slot]
mov.w   @(0x12,PC),r0    ; r0 = 0x0224 (offset for result field)
mov.l   r6,@(r0,r4)      ; base_A[0x224] = 0 (A wins -> A gets 0?? actually: A >= B, skip)
bra     end
mov.l   r7,@(r0,r5)      ; base_B[0x224] = 1 [delay slot]
; else:
mov.w   @(0xA,PC),r0     ; r0 = 0x0224
mov.l   r7,@(r0,r4)      ; base_A[0x224] = 1 (A < B, A loses)
mov.l   r6,@(r0,r5)      ; base_B[0x224] = 0 (B wins)
; end:
rts
nop
```

### Our Compiler Output (28 instructions)
Key differences from original:
- GCC computes `0x06078900 + 0x0268` as a constant `iVar2` = 0x06078B68, loading it from
  constant pool separately. The original computes it at runtime with `add r3,r5`.
- GCC uses `cmp/ge` comparison but then generates `bt.s` with extra register manipulation
  (`movt`) for the if/else assignment, adding instructions.
- GCC generates separate constant pool entries and `mov.l` loads for what the original
  encodes as `mov.w` (small displacements from PC).
- The separate `mov.w L11` and `mov.l L12` in both branches instead of sharing the offset
  costs extra.

### Root Cause
1. **Separate constant for `base + 0x268`**: The C source computes `iVar2 = 0x06078900 +
   0x0268` as a compile-time constant. The original compiler computed it at runtime from
   the base + offset, sharing the base address with subsequent indexed accesses. Cost: ~+1.
2. **No `@(r0,rN)` indexed stores**: The original uses `mov.l r7,@(r0,r4)` and `mov.l
   r6,@(r0,r5)` indexed by r0 (the 0x0224 offset). GCC does not use this addressing mode,
   needing extra register arithmetic. Cost: +1-2.
3. **`movt` instruction**: GCC generates a `movt` (move T-bit to register) pattern for the
   conditional assignment, which the original avoids by using explicit branch paths.

### Proposed C Source Fix
```c
void FUN_0600d336()
{
  int *baseA;
  int *baseB;
  int off_cmp, off_res;

  baseA = (int *)0x06078900;
  baseB = (int *)(0x06078900 + 0x0268);

  if ((*(unsigned int *)0x0607EBC4 & 0x00200000) == 0) {
    off_cmp = 0x01F4 >> 2;  /* word index = 0x7D */
    off_res = 0x0224 >> 2;  /* word index = 0x89 */

    if (baseA[off_cmp] < baseB[off_cmp]) {
      baseA[off_res] = 1;
      baseB[off_res] = 0;
    } else {
      baseA[off_res] = 0;
      baseB[off_res] = 1;
    }
  }
}
```

**Note**: The indexed `@(r0,rN)` addressing mode issue is a compiler limitation. The original
uses byte offsets in r0 with `@(r0,r4)`, which GCC 2.6.3 does not emit for struct-like
accesses. The fix may reduce delta by 1 but likely not achieve perfect match.

**Verdict**: Partially fixable. The explicit if/else with constants 0 and 1 (rather than
`movt` pattern) should help. The indexed addressing is a compiler limitation.

---

## FUN_060283B8 (delta=+2, ours=20, orig=18)

### Original Assembly (060283B8-060283DA)
```
mov     #14,r3            ; r3 = 14 (loop counter / write offset, counts down by 2)
mov.l   @(0x20,PC),r0    ; r0 = 0x06028614 (table base)
mov.l   @(r0,r4),r2      ; r2 = table[param_1] (indexed load)
mov.l   @r2,r2            ; r2 = *r2 (double dereference)
add     r5,r2             ; r2 += param_2 (destination base)
mov     #15,r5            ; r5 = 0xF (nibble mask)
; loop:
mov     r7,r1             ; r1 = param_4 (current nibble source)
mov     r3,r0             ; r0 = offset counter
and     r5,r1             ; r1 = param_4 & 0xF
shlr2   r7                ; param_4 >>= 2
add     r6,r1             ; r1 += param_3
shlr2   r7                ; param_4 >>= 2 (total >>= 4)
mov.w   r1,@(r0,r2)      ; write word at dest[offset]
tst     r3,r3             ; test offset == 0
bf/s    loop              ; loop if not zero
add     #-2,r3            ; r3 -= 2 [delay slot]
rts
nop
```

### Our Compiler Output (20 instructions)
```
mov.l   L6,r0            ; r0 = 0x06028614
mov.l   @(r0,r4),r0      ; r0 = table[param_1]
mov.l   @r0,r0            ; r0 = *r0
add     r5,r0             ; r0 += param_2
mov     r0,r1             ; r1 = destination base
add     #16,r1            ; r1 = dest + 16 (pointer to end)
mov     r0,r2             ; r2 = dest base (for comparison)
mov     r7,r0             ; r0 = param_4
; L8 (loop):
and     #15,r0            ; r0 &= 0xF  (uses r0-specific AND #imm)
add     r6,r0             ; r0 += param_3
mov.w   r0,@-r1           ; write and pre-decrement r1
mov     r7,r0             ; r0 = param_4
shlr2   r0                ; r0 >>= 2
mov     r0,r7             ; r7 = r0 (store back)
shlr2   r7                ; r7 >>= 2 (total >>= 4)
cmp/eq  r2,r1             ; r1 == base? (end of buffer?)
bf.s    L8                ; loop if not equal
mov     r7,r0             ; delay slot: r0 = next param_4
rts
mov     #0,r0             ; return 0
```

### Root Cause
1. **Loop termination strategy**: The original uses a decrementing counter `r3` (14,12,10,...0)
   and `tst r3,r3` to check for zero, with `mov.w r1,@(r0,r2)` using the counter as offset.
   Our GCC uses a pointer `r1` counting down with `mov.w r0,@-r1` and compares against end
   pointer `r2`. This requires extra setup (`add #16,r1` and `mov r0,r2`), costing +2.
2. **`and #15,r0` vs `and r5,r1`**: GCC uses the r0-specific `and #imm,r0` form (1 insn).
   The original loads 15 into r5 outside the loop and uses `and r5,r1` (register form).
   These are equivalent in cost.
3. **`shlr2` x2 + register shuffle**: Both implementations do two shlr2 for >>4. But GCC
   generates extra `mov r0,r7` and `mov r7,r0` shuffles because it uses r0 for the AND.

### Diagnosis: LOOP STRUCTURE DIFFERENCE
The original uses offset-based writing with `@(r0,r2)` indexed addressing (offset in r0).
GCC uses pre-decrement `@-r1`. The pre-decrement approach needs 2 extra setup instructions.

### Proposed C Source Fix
```c
int FUN_060283b8(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    unsigned int param_4;
{
  int base;
  int offset;

  base = **(int **)(0x06028614 + param_1) + param_2;
  offset = 14;
  do {
    *(unsigned short *)(base + offset) = (param_4 & 0xf) + param_3;
    param_4 >>= 4;
    offset -= 2;
  } while (offset >= 0);
  return 0;
}
```

Key changes:
- Use explicit `offset` variable counting down from 14 to 0 instead of pointer arithmetic.
  This may encourage GCC to use the `@(r0,rN)` pattern or at least a simpler loop.
- Changed `iVar4 -= 2` before use to `offset -= 2` after use (matching the original where
  the decrement is in the delay slot after the `bf/s`).
- Changed `while (iVar4)` to `while (offset >= 0)` to match the `tst` check semantics.

**Note**: The `@(r0,rN)` indexed write is still a compiler limitation. This fix restructures
the loop to potentially match better.

---

## FUN_06027476 (delta=+2, ours=19, orig=17)

### Original Assembly (06027476-06027496)
```
cmp/pl  r4                ; param_1 > 0?
bf/s    end               ; if not, skip (result = 0)
mov     #0,r0             ; r0 = 0 (result) [delay slot]
mov.l   @(0x74,PC),r2    ; r2 = 0x8000 (bit)
; loop:
add     r2,r0             ; result += bit
mul.l   r0,r0             ; compute result * result
sts     macl,r3           ; r3 = result^2
cmp/eq  r4,r3             ; result^2 == param_1?
bt      end               ; if equal, done (exact sqrt found)
cmp/hi  r4,r3             ; result^2 > param_1? (unsigned)
bf      skip              ; if not, skip subtraction
sub     r2,r0             ; result -= bit (undo addition)
; skip:
shlr    r2                ; bit >>= 1
cmp/pl  r2                ; bit > 0? (signed positive)
bt      loop              ; continue if bit still positive
; end:
rts
shll8   r0                ; return result << 8 [delay slot]
```

### Our Compiler Output (19 instructions)
```
cmp/pl  r4
bf.s    L2
mov     #0,r0
mov.l   L11,r0            ; r0 = 0x8000
bra     L10               ; <-- extra unconditional branch!
mov     r0,r2             ; r2 = bit [delay slot]
; L6:
bf      L7
sub     r2,r0             ; result -= bit
; L7:
shlr    r2                ; bit >>= 1
cmp/pl  r2
bf      L2                ; <-- changed from bt/loop to bf/exit
add     r2,r0             ; result += bit
; L10:
mul.l   r0,r0
sts     macl,r1
cmp/eq  r4,r1
bf.s    L6                ; <-- branch with delay slot
cmp/hi  r4,r1
; L2:
rts
shll8   r0
```

### Root Cause
1. **Extra `bra L10` entry jump**: GCC restructures the loop to put the initial `add r2,r0`
   before the mul.l at the bottom. This requires a `bra L10` to jump into the middle of the
   loop on first entry. The original simply falls through into the loop. Cost: +1 (bra)
   plus the delay slot `mov r0,r2` which is needed anyway = net +1.
2. **Loop inversion**: GCC inverts the loop exit condition from `bt loop` to `bf L2` (exit).
   This is semantically equivalent but changes the flow. The `bf` to exit is actually the
   same instruction count, but combined with the entry jump it costs +1.
3. **Register initialization**: `mov.l L11,r0` + `mov r0,r2` = 2 instructions to set up
   `bit = 0x8000` in r2. The original does `mov.l @(0x74,PC),r2` directly into r2 = 1 insn.
   Cost: +1.

### Diagnosis: LOOP STRUCTURE + REGISTER ASSIGNMENT
The entry jump and constant load routing through r0 add 2 extra instructions.

### Proposed C Source Fix
```c
int FUN_06027476(param_1)
    unsigned int param_1;
{
  int result;
  int bit;
  int sq;

  result = 0;
  if (0 < (int)param_1) {
    bit = 0x8000;
    do {
      result += bit;
      sq = result * result;
      if (sq == param_1) break;
      if ((unsigned int)sq > param_1) {
        result -= bit;
      }
      bit >>= 1;
    } while (bit > 0);
  }
  return result << 8;
}
```

Key changes:
- Changed `bit` and `sq` from `unsigned int` to `int`. This may avoid the `mov.l` + `mov`
  dance for loading 0x8000, since GCC might route it differently with signed types.
- Changed `result + (int)bit` to `result += bit` and `result - (int)bit` to `result -= bit`
  to reduce unnecessary casts that may confuse register allocation.
- Changed `bit = bit >> 1` to `bit >>= 1` for clarity.

**Note**: The loop entry jump (`bra`) is a compiler loop restructuring decision. The C
source structure (do-while with break) matches the original's loop layout. The remaining
delta may be unavoidable due to GCC's loop header duplication optimization.

**Verdict**: Likely reduces from +2 to +1. The entry branch is a compiler scheduling issue.

---

## FUN_06035E5E (delta=+2, ours=18, orig=16)

### Original Assembly (06035E5E-06035E7C)
```
mov.l   @(0x20,PC),r3    ; r3 = 0x25890018
mov.w   @r3,r3            ; r3 = *(short*)0x25890018
mov.w   r3,@r4            ; param_1[0] = r3
mov.l   @(0x1C,PC),r2    ; r2 = 0x2589001C
mov.w   @r2,r2            ; r2 = *(short*)0x2589001C
mov     r2,r0             ; r0 = r2 (need r0 for displacement store)
mov.w   r0,@(0x2,r4)     ; param_1[1] = r0  (displacement store!)
mov.l   @(0x18,PC),r3    ; r3 = 0x25890020
mov.w   @r3,r3            ; r3 = *(short*)0x25890020
mov     r3,r0             ; r0 = r3
mov.w   r0,@(0x4,r4)     ; param_1[2] = r0  (displacement store!)
mov.l   @(0x14,PC),r3    ; r3 = 0x25890024
mov.w   @r3,r3            ; r3 = *(short*)0x25890024
mov     r3,r0             ; r0 = r3
rts
mov.w   r0,@(0x6,r4)     ; param_1[3] = r0  (displacement store in delay slot!)
```

### Our Compiler Output (18 instructions)
```
mov.l   L2,r0            ; r0 = 0x25890018
mov.w   @r0,r0            ; r0 = *(short*)0x25890018
mov.w   r0,@r4            ; param_1[0] = r0
mov     r4,r1             ; <-- extra: compute param_1+2
add     #2,r1             ; r1 = param_1 + 2
mov.l   L3,r0             ; r0 = 0x2589001C
mov.w   @r0,r0
mov.w   r0,@r1            ; param_1[1] = r0  (via pointer, not displacement!)
mov     r4,r1             ; <-- extra: compute param_1+4
add     #4,r1
mov.l   L4,r0
mov.w   @r0,r0
mov.w   r0,@r1            ; param_1[2]
add     #6,r4             ; param_1 += 6
mov.l   L5,r0
mov.w   @r0,r0
rts
mov.w   r0,@r4            ; param_1[3]
```

### Root Cause
1. **No `mov.w r0,@(disp,r4)` displacement stores**: The original uses `mov.w r0,@(2,r4)`,
   `mov.w r0,@(4,r4)`, `mov.w r0,@(6,r4)` -- displacement word stores that require the
   source to be r0. GCC instead computes the target address with `mov r4,r1` + `add #N,r1`
   and writes via `mov.w r0,@r1`. This costs +1 per displaced store.
2. Specifically: 3 displacement stores need `mov rX,r0` (to get value into r0) but GCC adds
   `mov r4,r1` + `add #2,r1` instead of using the displacement. Cost: 2 extra `mov+add`
   pairs vs 2 `mov rX,r0` copies = net +2.

### Diagnosis: DISPLACEMENT STORE PEEPHOLE NOT TRIGGERING
The existing disp store peephole (patch #5) handles `mov rN,rM / add #D,rM / mov.w rK,@rM`
-> `mov.w r0,@(D,rN)`. It should be catching this pattern. The issue might be that the
peephole requires `rK == r0` specifically, or the first store pattern (`mov.w r0,@r4` with
no displacement) is confusing the sequence.

### Proposed C Source Fix
The C source itself looks correct and clean. The issue is the compiler's peephole not firing.
Let me check if rewriting the stores differently helps:

```c
void FUN_06035e5e(param_1)
    short *param_1;
{
  param_1[0] = *(volatile short *)0x25890018;
  param_1[1] = *(volatile short *)0x2589001C;
  param_1[2] = *(volatile short *)0x25890020;
  param_1[3] = *(volatile short *)0x25890024;
}
```

The C source is already essentially this. The real fix needs to be in the compiler peephole
to ensure `mov.w r0,@(disp,rN)` is generated for consecutive short-pointer stores.

**Alternate approach**: Use `int` base with byte arithmetic to force displacement:
```c
void FUN_06035e5e(param_1)
    int param_1;
{
  *(short *)param_1 = *(volatile short *)0x25890018;
  *(short *)(param_1 + 2) = *(volatile short *)0x2589001C;
  *(short *)(param_1 + 4) = *(volatile short *)0x25890020;
  *(short *)(param_1 + 6) = *(volatile short *)0x25890024;
}
```

**Verdict**: Likely a compiler peephole issue, not a C source issue. The existing disp store
peephole may need adjustment to handle the case where r0 is already the source value.

---

## FUN_0603A766 (delta=+2, ours=28, orig=26)

### Original Assembly (0603A766-0603A798)
```
mov.l   r14,@-r15         ; save r14
mov.l   r13,@-r15         ; save r13
mov.l   r12,@-r15         ; save r12
sts.l   pr,@-r15           ; save PR
mov.l   @(0x38,PC),r12    ; r12 = 0x060A4CAC (limit pointer)
mov.w   @(0x26,PC),r13    ; r13 = 0x00FF (constant for arg)
mov.l   @(0x38,PC),r14    ; r14 = 0x060A4CB4 (counter pointer)
bra     check              ; jump to loop test
nop                        ; delay slot
; loop body:
bsr     FUN_0603AB46       ; call FUN_0603AB46
extu.b  r13,r4             ; r4 = (unsigned char)0xFF = 255 [delay slot]
bsr     FUN_0603A7B0       ; call FUN_0603A7B0
nop
mov.l   @r14,r2           ; r2 = *counter
add     #1,r2             ; r2++
mov.l   r2,@r14           ; *counter = r2
; check:
mov.w   @r12,r3           ; r3 = *(short*)limit
mov.l   @r14,r2           ; r2 = *counter
extu.w  r3,r3             ; zero-extend limit to unsigned
cmp/ge  r3,r2             ; counter >= limit?
bf      loop_body          ; loop if counter < limit
; epilogue:
lds.l   @r15+,pr
mov.l   @r15+,r12
mov.l   @r15+,r13
rts
mov.l   @r15+,r14
```

### Our Compiler Output (28 instructions)
```
mov.l   r10,@-r15         ; save r10 (not r14!)
mov.l   r9,@-r15          ; save r9
mov.l   r8,@-r15          ; save r8
sts.l   pr,@-r15
mov.l   L6,r8             ; r8 = 0x060A4CB4 (counter)
mov.l   L7,r9             ; r9 = 0x060A4CAC (limit)
mov.w   L8,r10            ; r10 = 0x00FF
mov.w   @r9,r0            ; <-- initial loop test DUPLICATED
extu.w  r0,r0
mov.l   @r8,r1
cmp/ge  r0,r1
bt      L1                ; skip loop entirely if already done
; L4 (loop body):
bsr     _FUN_0603ab46
exts.b  r10,r4            ; <-- exts.b instead of extu.b!
bsr     _FUN_0603a7b0
nop
mov.l   @r8,r1            ; reload counter
add     #1,r1
mov.l   r1,@r8            ; store counter
mov.w   @r9,r0            ; reload limit
extu.w  r0,r0
cmp/ge  r0,r1
bf      L4
; L1 (epilogue):
lds.l   @r15+,pr
mov.l   @r15+,r8
mov.l   @r15+,r9
rts
mov.l   @r15+,r10
```

### Root Cause
1. **Loop header duplication**: GCC duplicates the loop condition test before entering the
   loop (lines mov.w @r9,r0 through bt L1). The original uses `bra check` to jump to the
   loop test at the bottom. This costs +4 instructions for the duplicated test, but saves
   1 (no `bra`+nop), netting +2.
2. **`exts.b` vs `extu.b`**: Our compiler uses `exts.b r10,r4` (sign-extend byte) instead
   of `extu.b r13,r4` (zero-extend byte). For 0xFF, `exts.b` gives -1 while `extu.b` gives
   255. The original wants 255 (unsigned). The C source casts `(char)uVar1` which is signed,
   producing the wrong extension. This should be `(unsigned char)`.
3. **Register naming**: Uses r8/r9/r10 instead of r12/r13/r14. This is cosmetic but the
   different callee-saved register choice doesn't affect instruction count.

### Diagnosis: WHILE-LOOP CODEGEN + SIGNED CAST
GCC's `while` loop optimization duplicates the condition check before the loop. The original
uses a `do-while` structure with an initial `bra` to the check. Also the argument cast is
wrong (signed vs unsigned byte).

### Proposed C Source Fix
```c
extern void FUN_0603a7b0();
extern void FUN_0603ab46();

void FUN_0603a766()
{
  int *counter;
  unsigned short *limit;

  counter = (int *)0x060A4CB4;
  limit = (unsigned short *)0x060A4CAC;

  goto check;

loop:
  FUN_0603ab46(255);      /* pass 0xFF directly as int, not cast */
  FUN_0603a7b0();
  *counter = *counter + 1;

check:
  if (*counter < (int)(unsigned int)*limit) {
    goto loop;
  }
}
```

Key changes:
- Use `goto check` / `goto loop` to force the `bra check` structure instead of while-loop
  header duplication. This exactly matches the original's `bra check` entry.
- Pass `255` (int literal) instead of `(char)uVar1` to avoid sign extension. The
  original passes `extu.b r13,r4` = zero-extend of 0xFF = 255.
- Use `int *counter` and `unsigned short *limit` for proper typed access.
- Compare counter against zero-extended limit value.

**Verdict**: Should fix both issues. The `goto` pattern matches the original loop structure,
and passing `255` instead of `(char)0xFF` fixes the exts.b/extu.b mismatch.

---

## Summary Table

| Function | Delta | Root Cause | Fixable in C? | Expected After Fix |
|----------|-------|-----------|---------------|-------------------|
| FUN_06030EE0 | +4 | `@(r0,rN)` indexed addressing not generated | No | +4 (compiler limitation) |
| FUN_060122F4 | +3 | Separate address for base+4, cmp/gt vs cmp/ge | Partial | +1 to +2 |
| FUN_06011678 | +3 | `& 0xFFFF` mask emulation, zero reload in loop | Yes | +0 to +1 |
| FUN_0602766C | +3 | Extern indirection (+2), and+tst vs tst (+1) | Mostly | +0 to +1 |
| FUN_0600D336 | +2 | Runtime base+offset vs const, `@(r0,rN)` stores | Partial | +1 |
| FUN_060283B8 | +2 | Pre-decrement vs indexed loop, extra setup | Partial | +1 |
| FUN_06027476 | +2 | Loop entry jump, constant load via r0 | Partial | +1 |
| FUN_06035E5E | +2 | Displacement store peephole not firing | Compiler fix | +0 to +2 |
| FUN_0603A766 | +2 | While-loop header duplication, signed byte cast | Yes | +0 |

### Common Patterns

1. **Extern symbol indirection** (FUN_0602766C): Using `extern` variables causes GCC to
   load the symbol address then dereference, vs the original which embeds the address as a
   constant. Fix: use direct `*(type*)0xADDRESS` instead of `extern` declarations.

2. **`@(r0,rN)` indexed addressing** (FUN_06030EE0, FUN_0600D336, FUN_060283B8): The SH-2
   has a powerful indexed addressing mode `@(r0,rN)` that uses r0 as the index register.
   GCC 2.6.3 rarely generates this. No C source fix; would require a compiler pattern.

3. **Loop structure mismatch** (FUN_06011678, FUN_0603A766, FUN_06027476): GCC's loop
   optimizations (header duplication, inversion) produce different shapes than the original.
   Using `goto` or `do-while` with specific structure can help.

4. **Displacement store peephole gaps** (FUN_06035E5E): The existing `mov.w r0,@(disp,rN)`
   peephole should catch these patterns but isn't firing. May need compiler peephole fix.

5. **Unnecessary masking/extension** (FUN_06011678, FUN_0603A766): Explicit `& 0xFFFF` or
   `(char)` casts produce extra instructions. Using natural int-width operations when the
   compiler can prove the range is sufficient eliminates these.
