# C Source Fix Analysis - Batch 1

Analysis of four functions with highest instruction count delta between
our GCC 2.6.3 output and the original binary.

---

## FUN_060370C0 (delta=+7, ours=25, orig=18)

### What the function does

Zeroes out a 15-byte struct: two 4-byte words at offsets 0 and 4, then seven
individual bytes at offsets 8 through 14.

### Current C source (`src/FUN_060370C0.c`)

```c
void FUN_060370c0(param_1)
    int *param_1;
{
    *param_1 = 0;
    param_1[1] = 0;
    *(char *)(param_1 + 2) = 0;
    *(char *)((int)param_1 + 9) = 0;
    *(char *)((int)param_1 + 10) = 0;
    *(char *)((int)param_1 + 0xb) = 0;
    *(char *)(param_1 + 3) = 0;
    *(char *)((int)param_1 + 0xd) = 0;
    *(char *)((int)param_1 + 0xe) = 0;
}
```

### Original binary disassembly (18 instructions)

```
060370C0: mov #0,r5           ; r5 = 0
060370C2: extu.b r5,r0        ; r0 = (unsigned byte)r5 = 0
060370C4: mov.l r5,@r4        ; *(int*)param_1 = 0
060370C6: mov.l r5,@(0x4,r4)  ; param_1[1] = 0
060370C8: mov.b r0,@(0x8,r4)  ; byte store at offset 8
060370CA: extu.b r5,r0        ; reload r0 = 0
060370CC: mov.b r0,@(0x9,r4)  ; byte store at offset 9
060370CE: extu.b r5,r0
060370D0: mov.b r0,@(0xA,r4)
060370D2: extu.b r5,r0
060370D4: mov.b r0,@(0xB,r4)
060370D6: extu.b r5,r0
060370D8: mov.b r0,@(0xC,r4)
060370DA: extu.b r5,r0
060370DC: mov.b r0,@(0xD,r4)
060370DE: extu.b r5,r0
060370E0: rts
060370E2: mov.b r0,@(0xE,r4)  ; last store in delay slot
```

### Our compiler output (25 instructions)

```
mov  #0,r0
mov.l r0,@r4
mov.l r0,@(4,r4)
mov  r4,r0          ; \
add  #8,r0          ;  > 3 insns per byte store
mov.b r1,@r0        ; /  (vs 2 in original)
mov  r4,r0
add  #9,r0
mov.b r1,@r0
... (repeated 7 times for offsets 8-14)
```

### Root cause: Missing `mov.b r0,@(disp,Rn)` addressing mode

The SH-2 ISA has `mov.b R0,@(disp,Rn)` -- a byte store with 4-bit displacement
(0-15) that **requires R0 as the source register**. The original compiler
uses this instruction directly:

```
extu.b r5,r0          ; get zero into R0
mov.b r0,@(0x8,r4)   ; store R0 at param_1+8  (1 insn for the store)
```

Our GCC 2.6.3 SH backend does NOT have a pattern for QImode displacement
stores. The `movqi_i` pattern in sh.md only supports `"=r,r,>m,r,r,l"` /
`"ri,<m,r,t,l,r"` -- plain register indirect (`mov.b Rm,@Rn`) but not
displacement (`mov.b R0,@(disp,Rn)`). So GCC generates 3 instructions per
byte store: copy base to r0, add displacement, then store.

Each byte store costs 3 insns in our output vs 2 in the original. With 7
byte stores, that's exactly +7 instructions.

### C source fix: None possible

**This delta cannot be closed at the C source level.** Regardless of how
the C code is written (struct members, char* indexing, explicit casts),
GCC 2.6.3 will generate the same 3-instruction sequence because the
`mov.b R0,@(disp,Rn)` addressing mode is absent from the backend.

**Required fix: Compiler backend patch** -- add a QImode displacement
store pattern to sh.md:

```
;; Byte store with displacement: mov.b r0,@(disp,Rn)
;; SH-2 requires R0 as source for this addressing mode
(define_insn ""
  [(set (mem:QI (plus:SI (match_operand:SI 0 "arith_reg_operand" "r")
                         (match_operand:SI 1 "byte_index_operand" "I")))
        (match_operand:QI 2 "arith_reg_operand" "z"))]
  ""
  "mov.b  %2,@(%1,%0)"
  [(set_attr "type" "store")])
```

Plus an adjustment to `prepare_move_operands` in sh.c to route byte stores
with small constant displacement through this pattern.

### Opcode-level comparison

| Line | Expected (orig) | Ours (current) |
|------|----------------|----------------|
| 1    | mov            | mov            |
| 2    | extu.b         | mov.l          |
| 3    | mov.l          | mov.l          |
| 4    | mov.l          | mov (extra)    |
| 5    | mov.b          | add (extra)    |
| ...  | 2-insn pattern | 3-insn pattern |

---

## FUN_06040EEC (delta=+7, ours=28, orig=21)

### What the function does

Searches a byte array (base address stored at 0x060A5400) for the first
zero slot. If found (index < 24), marks it with 1 and returns 0 via
`*param_1 = index`. Otherwise sets `*param_1 = -1` and returns -4.

### Current C source (`src/FUN_06040EEC.c`)

```c
int FUN_06040eec(param_1)
    int *param_1;
{
    int iVar1;
    iVar1 = 0;
    do {
        if (*(char *)(iVar1 + *(int *)0x060A5400) == '\0') {
            *(char *)(iVar1 + *(int *)0x060A5400) = 1;
            *param_1 = iVar1;
            return 0;
        }
        iVar1 = iVar1 + 1;
    } while (iVar1 < 0x18);
    *param_1 = -1;
    return 0xfffffffc;
}
```

### Original binary disassembly (21 instructions)

```
06040EEC: mov #1,r1             ; r1 = 1 (constant for marking)
06040EEE: mov #24,r7            ; r7 = 24 (loop limit)
06040EF0: mov.l @(0x48,PC),r6  ; r6 = &0x060A5400 (pointer to base ptr)
06040EF2: mov #0,r5             ; r5 = 0 (counter)
; loop:
06040EF4: mov.l @r6,r0          ; r0 = base address
06040EF6: mov.b @(r0,r5),r3    ; r3 = base[counter]
06040EF8: tst r3,r3             ; test zero
06040EFA: bf 0x06040F06          ; if non-zero, skip
; found:
06040EFC: mov.l @r6,r0          ; r0 = base address (reload)
06040EFE: mov.b r1,@(r0,r5)    ; base[counter] = 1
06040F00: mov.l r5,@r4          ; *param_1 = counter
06040F02: rts
06040F04: mov #0,r0             ; return 0 (in delay slot)
; skip:
06040F06: add #1,r5             ; counter++
06040F08: cmp/ge r7,r5          ; counter >= 24 ?
06040F0A: bf 0x06040EF4          ; loop if not
; fall-through:
06040F0C: mov #-1,r3
06040F0E: mov.l r3,@r4          ; *param_1 = -1
06040F10: mov #-4,r0            ; return -4
06040F12: rts
06040F14: nop
```

### Our compiler output (28 instructions)

The major issues are:

1. **Loop branch: `cmp/gt` + `bf.s` vs `cmp/ge` + `bf`** -- Our GCC compares
   against 23 with `cmp/gt` (greater than), while the original compares against
   24 with `cmp/ge` (greater or equal). Both are semantically correct but the
   original's form matches the natural `< 24` expression better. This is a
   minor difference that doesn't add instructions by itself, but our GCC also
   puts a `mov #-4,r0` in the delay slot of `bf.s`, adding complexity.

2. **"Found" branch has massive overhead** -- The original does the byte
   write `base[counter] = 1` in just 2 instructions:
   ```
   mov.l @r6,r0           ; reload base into R0
   mov.b r1,@(r0,r5)     ; indexed byte store: R1 via R0+R5
   ```
   Our GCC generates ~8 instructions for the same operation, including:
   - Reload of constant pool address
   - Stack spills (`mov.b r0,@(r0,r15)` / `mov.b @(r0,r15),r6`)
   - Extra register shuffles

   The root cause is the SH-2 indexed byte store `mov.b Rm,@(R0,Rn)` which
   requires R0 as one of the address components. The original compiler kept
   R0 available for this purpose. GCC's register allocator cannot manage
   the R0 constraint efficiently, so it spills through the stack.

3. **Stack frame**: Our code allocates a stack frame (`add #-4,r15` /
   `add #4,r15`) that the original doesn't need. The original is a leaf
   function with no stack usage.

### C source fixes: Partial improvements possible

The C source structure is already close to the original logic. The main
issue is compiler code generation quality, not C source structure.

**Minor fix -- re-read base pointer in found path:**

The current code reads `*(int *)0x060A5400` twice in the "found" path (once
for the read, once for the write). This is correct but GCC can't optimize
this well because the pointer is volatile-like (comes from a fixed address).
However, since both reads use the same address, GCC should CSE them -- and
it does, but the R0 constraint for indexed byte store still causes spills.

**Proposed C source (no change recommended):**

The current source is already a faithful representation of the original
logic. The +7 delta is entirely due to:
- Missing R0-indexed byte store optimization in the GCC register allocator
- cmp/gt vs cmp/ge difference (cosmetic, same instruction count)

**Required fix: Compiler backend improvement** -- better R0 allocation
for indexed byte stores. This is the same class of issue as FUN_060370C0
(R0-specific addressing modes).

### Opcode-level comparison

| Phase     | Expected      | Ours          | Delta |
|-----------|--------------|---------------|-------|
| Prologue  | 4 insns      | 6 insns       | +2    |
| Loop body | 4 insns      | 5 insns       | +1    |
| Found     | 5 insns      | 9 insns       | +4    |
| Not-found | 5 insns      | 5 insns       | 0     |
| Epilogue  | 3 insns      | 3 insns       | 0     |
| **Total** | **21**       | **28**        | **+7**|

---

## FUN_06038044 (delta=+6, ours=24, orig=18)

### What the function does

Copies 8 consecutive short values from a source address (param_1) into a
fixed destination struct at 0x060A3D88, starting at offset +0x10. Returns
the base pointer 0x060A3D88.

### Current C source (`src/FUN_06038044.c`)

```c
char * FUN_06038044(param_1)
    int param_1;
{
    char *puVar1;
    unsigned short uVar2;
    unsigned int uVar3;

    puVar1 = 0x060A3D88;
    uVar2 = 0;
    do {
        uVar3 = (unsigned int)uVar2;
        uVar2 = uVar2 + 1;
        *(short *)(puVar1 + (uVar3 << 1) + 0x10) =
            *(short *)((uVar3 << 1) + param_1);
    } while (uVar2 < 8);
    return puVar1;
}
```

### Original binary disassembly (18 instructions)

```
06038044: mov.l @(0x20,PC),r0  ; r0 = 0x060A3D88 (dest base)
06038046: mov #8,r7             ; r7 = 8 (loop limit)
06038048: mov #0,r5             ; r5 = 0 (counter)
; loop top:
0603804A: extu.w r5,r6          ; r6 = (unsigned short)counter
0603804C: mov r0,r3             ; r3 = dest base
0603804E: shll r6               ; r6 <<= 1 (word offset to byte offset)
06038050: add #1,r5             ; counter++
06038052: add #16,r3            ; r3 = dest base + 16
06038054: mov r6,r2             ; r2 = byte offset
06038056: add r6,r3             ; r3 = dest + 16 + offset (dest addr)
06038058: add r4,r2             ; r2 = param_1 + offset (src addr)
0603805A: mov.w @r2,r1          ; read source short
0603805C: mov.w r1,@r3          ; write dest short
0603805E: extu.w r5,r3          ; r3 = (unsigned short)(counter)
06038060: cmp/ge r7,r3          ; counter >= 8 ?
06038062: bf 0x0603804A          ; loop back
06038064: rts
06038066: nop
```

### Our compiler output (24 instructions)

```
add  #-4,r15        ; allocate stack frame (not in original!)
mov  r4,r7          ; save param_1
mov.l L6,r3         ; load 0x060A3D88
mov  #0,r2          ; counter = 0
mov  #7,r6          ; limit (7, for cmp/hi)
extu.w r2,r0        ; extend counter
; loop:
mov.l r0,@r15       ; SPILL to stack
add  #1,r2          ; counter++
mov  r0,r1
shll r1              ; byte offset
mov  r3,r0
add  r1,r0
add  #16,r0
mov.l r0,@r15       ; SPILL dest addr to stack
mov  r7,r0          ;
mov.w @(r0,r1),r1   ; read source (uses R0 for indexed load)
mov.l @r15,r0       ; RELOAD dest addr from stack
mov.w r1,@r0        ; write dest
extu.w r2,r0        ; extend new counter
cmp/hi r6,r0        ; counter > 7 ?
bf loop
mov  r3,r0          ; return value
rts
add  #4,r15         ; deallocate stack frame
```

### Root cause: Register pressure and R0 contention

The original uses all 8 caller-saved registers (r0-r7) without any stack
spills. The register assignment is:
- r0 = dest base (constant across loop, never modified in body)
- r4 = param_1 (argument, constant)
- r5 = counter
- r7 = limit (8)
- r6, r2, r3, r1 = loop temporaries

Our GCC has two problems:

1. **R0 contention**: GCC uses `mov.w @(r0,r1),r1` for the indexed short
   load, which requires R0 to hold part of the address. But R0 is also
   needed for the `add #16,r0` destination computation. This creates a
   conflict that forces register spills to the stack.

2. **Stack frame overhead**: Two stack spills (`mov.l r0,@r15` / `mov.l @r15,r0`)
   add 4 instructions to the loop body. Plus `add #-4,r15` / `add #4,r15`
   for stack frame setup/teardown = +6 total.

3. **Loop limit style**: Original uses `cmp/ge r7,r3` with r7=8, ours uses
   `cmp/hi r6,r0` with r6=7. Same semantics, different constant.

### C source fix: Use `int` counter and simpler addressing

The `unsigned short` counter causes the `extu.w` extension, which matches
the original. But the bigger issue is the address computation that creates
R0 pressure. Let me try a variant that uses pointer arithmetic to reduce
register demand.

**Proposed C source:**

```c
char * FUN_06038044(param_1)
    int param_1;
{
    char *puVar1;
    unsigned short uVar2;
    unsigned int uVar3;

    puVar1 = (char *)0x060A3D88;
    uVar2 = 0;

    do {
        uVar3 = (unsigned int)uVar2;
        uVar2 = uVar2 + 1;
        *(short *)(puVar1 + (uVar3 << 1) + 0x10) =
            *(short *)((uVar3 << 1) + param_1);
    } while ((unsigned int)uVar2 < 8);

    return puVar1;
}
```

**Result: No improvement (still 24 instructions).** The register spilling
is caused by GCC's register allocator limitations, not the C source structure.
Any reformulation of the address computation leads to the same R0 contention.

**Tested alternative (int counter, pointer increment):**

```c
char * FUN_06038044(param_1)
    int param_1;
{
    char *puVar1;
    int i;

    puVar1 = (char *)0x060A3D88;
    i = 0;
    do {
        *(short *)(puVar1 + (i << 1) + 0x10) = *(short *)(param_1 + (i << 1));
        i = i + 1;
    } while (i < 8);
    return puVar1;
}
```

**Result: 14 instructions** -- fewer than original, but wrong opcode
sequence (uses `mov.w @r4+` autoincrement, no `extu.w`, no `shll`).
This doesn't match the original's instruction pattern.

### Verdict: Compiler limitation, not C source issue

The +6 delta is caused by GCC 2.6.3's register allocator running out of
caller-saved registers and spilling to the stack. The original compiler
had a better register allocator that could keep all loop variables in
registers simultaneously by keeping R0 as a constant base pointer and
using other registers for indexed addressing.

**Required fix: Compiler backend improvement** -- the register allocator
would need to be smarter about R0 allocation in loops with indexed
addressing. This is a known weakness of GCC 2.6.3's local register
allocator.

---

## FUN_06012198 (delta=+6, ours=14, orig=8)

### What the function does

Pure dispatcher: tests a global flag (DAT_0607EAD8). If non-zero, jumps to
FUN_0601228a. Otherwise jumps to FUN_060127e0. Neither call returns to this
function -- both are tail calls.

### Current C source (`src/FUN_06012198.c`)

```c
extern void FUN_0601228a();
extern void FUN_060127e0();
extern int DAT_0607EAD8;

void FUN_06012198()
{
  if (DAT_0607EAD8 != 0) {
    FUN_0601228a();
    return;
  }
  FUN_060127e0();
  return;
}
```

### Original binary disassembly (8 instructions)

```
06012198: mov.l @(0x84,PC),r0  ; r0 = &DAT_0607EAD8
0601219A: mov.l @r0,r0          ; r0 = DAT_0607EAD8
0601219C: tst r0,r0             ; test
0601219E: bt 0x060121A4          ; if zero, goto second path
060121A0: bra _FUN_0601228a     ; tail jump to first function
060121A2: nop
060121A4: bra _FUN_060127e0     ; tail jump to second function
060121A6: nop
```

The original does NOT save PR at all. Both paths use `bra` (unconditional
jump), not `bsr` (subroutine call). This is a "dual tail call" -- the
function is a pure dispatcher that delegates to one of two targets.

### Our compiler output (14 instructions)

```
sts.l  pr,@-r15       ; save PR (unnecessary!)
mov.l  L3,r0
mov.l  @r0,r0
tst    r0,r0
bt     L2
bsr    _FUN_0601228a  ; CALL (not tail jump!)
nop
bra    L1
nop
L2:
bsr    _FUN_060127e0  ; CALL (not tail jump!)
nop
L1:
lds.l  @r15+,pr       ; restore PR
rts                    ; return
nop
```

### Root cause: Tail call optimization only handles one path

Our tail call patch (in `machine_dependent_reorg`) scans backward from the
last instruction, looking for the pattern:

```
CALL_INSN (bsr target)
INSN (lds.l @r15+,pr)
JUMP_INSN (rts)
```

It converts the LAST such sequence to `bra target / lds.l @r15+,pr` (in
delay slot). But when there are TWO calls in different branches of an
if/else, only one can be "the last call before return." The other call
(`bsr _FUN_0601228a`) is separated from the return by a `bra L1` jump,
so the pass doesn't recognize it.

Furthermore, the "pure wrapper" detection requires `call_count == 1 &&
push_count == 1`. With two calls, `call_count == 2`, so the pure wrapper
path is not taken. The regular tail call conversion path does fire for the
last call, but it deletes the shared return block (rts + lds.l), which
would break the first call's return path. It appears the pass either
detects this conflict or the pattern doesn't match because of the
intervening `bra L1`.

### C source fix: None possible for full match

No restructuring of the C source makes both calls into tail calls under
the current compiler. Tested alternatives:

```c
// v1: if/else with returns
if (DAT != 0) { FUN_a(); return; }
FUN_b(); return;

// v2: if/else without returns
if (DAT != 0) FUN_a(); else FUN_b();

// v3: reversed condition
if (DAT == 0) { FUN_b(); return; }
FUN_a();
```

All produce the same 14-instruction output with `sts.l pr / bsr / bsr /
lds.l pr / rts`.

### Required fix: Compiler backend enhancement

The `machine_dependent_reorg` tail call pass needs to be extended to
handle the "dual tail call dispatcher" pattern:

1. Detect when ALL calls in a function are at tail position (each call is
   immediately followed by a jump to the epilogue or is the last call).
2. When both calls are tail calls AND the only stack push is PR, convert
   the function to a pure dispatcher:
   - Remove `sts.l pr,@-r15` (PR push)
   - Convert each `bsr target / ... / bra epilogue` to `bra target / nop`
   - Remove the epilogue entirely (`lds.l @r15+,pr / rts / nop`)

This would produce exactly the 8-instruction output matching the original.

The detection logic would be:
```
if (call_count >= 1 && push_count == 1) {
    /* Check if ALL calls are in tail position */
    int all_tail = 1;
    for each call_insn:
        if (not followed by bra-to-epilogue and not the last call):
            all_tail = 0;
    if (all_tail):
        /* Pure dispatcher: remove PR save, convert all calls to bra */
}
```

---

## Summary

| Function      | Delta | Root Cause             | C Fix? | Compiler Fix Needed?  |
|---------------|-------|------------------------|--------|-----------------------|
| FUN_060370C0  | +7    | Missing QI disp store  | No     | Yes: `mov.b R0,@(d,Rn)` pattern |
| FUN_06040EEC  | +7    | R0 constraint spills   | No     | Yes: Better R0 alloc for indexed stores |
| FUN_06038044  | +6    | Register pressure/R0   | No     | Yes: Better R0 alloc in loops |
| FUN_06012198  | +6    | Single tail call limit | No     | Yes: Dual tail call detection |

**Key finding**: All four functions have deltas caused by **compiler backend
limitations**, not C source issues. The C source is already a faithful
representation of the original logic. The fixes needed are:

1. **QImode displacement store pattern** (sh.md) -- would fix FUN_060370C0
   and partially help FUN_06040EEC. This is the most impactful single patch.

2. **Dual tail call dispatcher** (sh.c) -- would fix FUN_06012198 and
   similar if/else dispatcher functions.

3. **Register allocator R0 handling** -- would help FUN_06038044 and
   FUN_06040EEC, but this is a deep change to the register allocator and
   may not be practical for GCC 2.6.3.

### Recommended compiler patch priority

1. **QI displacement store** -- highest ROI, likely affects many functions
   beyond these four. The pattern `mov.b R0,@(disp,Rn)` is a standard
   SH-2 instruction that GCC 2.6.3 inexplicably lacks support for.

2. **Dual tail call** -- targeted fix for dispatcher functions. The pattern
   is common in game state machines (the Saturn Daytona code has a 32-state
   dispatcher at main).

3. **Register alloc improvements** -- lowest priority due to high complexity
   and risk of regressions.
