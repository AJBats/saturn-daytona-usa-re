# C Source Fix Analysis - Batch 3 (delta=+1 functions)

All 8 functions listed here emit exactly 1 extra instruction compared to the
original binary. For each one we identify the root cause and propose a C source
fix.

---

## 1. FUN_06018EC8 (ours=8, orig=7, delta=+1)

### Original disassembly (7 insns)
```
06018EC8: mov.w  @(0xA,PC),r4      ; r4 = DAT_06018ed6 (0x00E0, a 16-bit literal via constant pool)
06018ECA: mov.l  @(0x10,PC),r2     ; r2 = 0x25B00217  (REG_25B00217)
06018ECC: extu.b r4,r3             ; r3 = r4 & 0xFF   (unsigned byte extract)
06018ECE: mov.b  r3,@r2            ; *REG_25B00217 = r3  (the low byte)
06018ED0: mov.l  @(0xC,PC),r3      ; r3 = 0x25B00237  (REG_25B00237)
06018ED2: rts
06018ED4: mov.b  r4,@r3            ; *REG_25B00237 = r4  (the full byte, written in rts delay slot)
```
Key: The value `DAT_06018ed6` is loaded once with `mov.w` (16-bit), then the
same register is used for both stores -- the first store uses `extu.b` to mask
to the low byte, and the second stores the full `r4` directly (the hardware
register only sees the low 8 bits of a byte write anyway).

### Our compiler output (8 insns)
```
mov.l  L3,r0       ; r0 = &DAT_06018ed6+1   (address of byte within the short)
mov.l  L2,r2       ; r2 = &REG_25B00217
mov.b  @r0,r1      ; r1 = byte load from DAT_06018ed6+1
mov.b  r1,@r2      ; *REG_25B00217 = r1
mov.l  L4,r0       ; r0 = &REG_25B00237
mov.b  r1,@r0      ; *REG_25B00237 = r1
rts
nop                 ; wasted delay slot
```
Our code emits 8 insns (including the nop). The original is 7 insns because it
fills the rts delay slot with `mov.b r4,@r3`.

### Root cause analysis
Two issues:
1. **Extern byte load vs inline constant pool short**: Our C declares
   `extern short DAT_06018ed6` and accesses it as `(unsigned char)DAT_06018ed6`
   and `(char)DAT_06018ed6`. GCC emits `mov.l` to load the address of the
   extern plus offset +1 (big-endian byte), then a `mov.b` load. The original
   compiler embedded the 16-bit value directly in the constant pool with
   `mov.w` (one fewer instruction, no address indirection).
2. **Delay slot not filled**: Our GCC fails to fill the rts delay slot. The
   original puts the second `mov.b` store in the delay slot.

The fundamental issue is that the extern reference costs an extra instruction
because GCC emits a constant pool entry for the *address* of the extern, then
a *load* from it. The original binary has the actual *value* (0x00E0) embedded
in the constant pool.

### Proposed fix

To match the original binary, we need to embed the value directly in the
constant pool rather than referencing an extern. Since the value is a
compile-time constant (0x00E0), we should use a literal:

```c
extern volatile char REG_25B00217;
extern volatile char REG_25B00237;

void FUN_06018ec8()
{
    short val = 0x00E0;
    REG_25B00217 = (unsigned char)val;
    REG_25B00237 = (char)val;
}
```

However, GCC 2.6.3 may still emit different code for a local variable vs constant pool.
The real problem is that with externs, there is always one extra instruction for the
address load indirection. **This is an instance of the "extern vs constant pool"
known issue (#6 in the known differences list).** The original code had the value 0x00E0
as a literal in the constant pool; our extern-based approach needs an address load +
memory load (2 insns) where the original used just a `mov.w` PC-relative load (1 insn).

**Verdict**: This delta is caused by the **extern vs constant pool** issue. The fix
requires replacing the extern `DAT_06018ed6` with a constant pool literal. Also
note the rts delay slot may or may not be filled -- that depends on register
scheduling.

**Concrete fix**:
```c
extern volatile char REG_25B00217;
extern volatile char REG_25B00237;

void FUN_06018ec8()
{
    /* Original loaded 0x00E0 from constant pool via mov.w */
    REG_25B00217 = (unsigned char)0xE0;
    REG_25B00237 = (char)0xE0;
}
```

This should emit `mov #0xE0,rN` (or `mov.w` for the constant pool) plus two
`mov.b` stores and eliminate the extern address indirection.

---

## 2. FUN_0601DB84 (ours=14, orig=13, delta=+1)

### Original disassembly (13 insns)
```
0601DB84: mov.l  @(0x18,PC),r7     ; r7 = 0x06086050  (store target)
0601DB86: mov.l  @(0x1C,PC),r6     ; r6 = 0x25A02C20  (poll address)
0601DB88: mov    #1,r5             ; r5 = 1
0601DB8A: mov.l  @(0x1C,PC),r4     ; r4 = 0x000186A0  (100000 = counter)
0601DB8C: dt     r4                ; r4--, set T if r4==0
0601DB8E: bf     0x0601DB94        ; if T==0 goto L_continue
0601DB90: bra    0x0601DB9A        ; goto L_exit
0601DB92: mov.l  r5,@r7            ; (delay slot) *0x06086050 = 1
0601DB94: mov.l  @r6,r0            ; r0 = *(0x25A02C20)
0601DB96: tst    r0,r0             ; test r0
0601DB98: bf     0x0601DB8C        ; if r0 != 0, loop back to dt
0601DB9A: rts
0601DB9C: nop
```
Original opcode stream: `mov.l, mov.l, mov, mov.l, dt, bf, bra, mov.l, mov.l, tst, bf, rts, nop` (13 insns).

### Our compiler output (14 insns)
```
mov.l  L7,r1       ; r1 = 100000
mov.l  L8,r3       ; r3 = 0x06086050
mov.l  L9,r2       ; r2 = 0x25A02C20  (but literal shows 631254048 = 0x25A02C20)
dt     r1           ; r1--, set T
bf.s   L4           ; if T==0 goto L4 (delay slot: movt)
movt   r7           ; r7 = T  (so r7=1 when counter hits zero)
rts
mov.l  r7,@r3       ; (delay slot) *0x06086050 = r7 (=1)
L4:
mov.l  @r2,r0       ; r0 = *0x25A02C20
tst    r0,r0
bf.s   L11          ; if r0 != 0, loop
dt     r1           ; (delay slot) decrement counter
rts
nop
```
Our opcode stream: `mov.l, mov.l, mov.l, dt, bf.s, movt, rts, mov.l, mov.l, tst, bf.s, dt, rts, nop` (14 insns).

### Root cause analysis

The original uses `mov #1,r5` (1-byte immediate) plus a plain `bf` and
`bra+mov.l` to store `1` at the target. Our GCC uses a clever `movt` to
capture the T flag (T=1 when dt reaches zero), but this requires `bf.s`
(delayed branch), which means the `movt` runs unconditionally before the
branch resolution. That adds 1 instruction overall.

The key difference: the original loads the constant `1` upfront with
`mov #1,r5` (which is a single SH instruction for small immediates), then
stores `r5` to the target via the `bra` delay slot. It uses plain `bf`
(not delayed), so the control flow is simpler:
- `dt r4` / `bf L_continue` / `bra L_exit` / `mov.l r5,@r7` (delay)
- = 4 insns for the "counter exhausted" path

Our compiler restructured the loop to put the dt in the delay slot of `bf.s`
and uses `movt` to capture T=1, costing an extra instruction.

**The extra instruction is `movt r7`** which wouldn't be needed if the constant
`1` was loaded before the loop like the original does.

### Proposed fix

The C source currently uses `puVar1 + -1` and an `if (puVar1 == 0)` check,
which maps to the dt+bf pattern. The issue is that GCC generates `movt` to
derive the value `1` rather than loading it upfront. We can try to help GCC
by explicitly providing the value `1` as a pre-loaded variable:

```c
void FUN_0601db84()
{
    int counter;
    int flag;

    flag = 1;
    counter = 0x000186A0;

    do {
        counter = counter - 1;
        if (counter == 0) {
            *(int *)0x06086050 = flag;
            return;
        }
    } while (*(int *)0x25A02C20 != 0);

    return;
}
```

**However**, the real issue is structural. The original's `bf`/`bra` pair
uses 2 branch insns where we use `bf.s`+`movt` (also 2 insns). The extra
instruction is the `movt`. The original avoids `movt` by pre-loading `1` into
a register with `mov #1,r5`.

The C source fix should avoid `movt` by making the store value explicitly a
pre-computed variable rather than letting GCC derive it from the T flag.

**Verdict**: This is a **register allocation / code generation** difference.
GCC 2.6.3 "cleverly" uses `movt` to capture T=1, but this costs +1 compared
to the original's simpler `mov #1,r5`. This may be hard to fix in C alone
since it depends on GCC's internal optimization decisions. The C source above
may produce identical output or may still generate movt. Testing required.

---

## 3. FUN_06027358 (ours=16, orig=15, delta=+1)

### Original disassembly (15 insns)
```
06027358: mov.w  @(0x1A0,PC),r3    ; r3 = 0x4000 (constant pool short)
0602735A: add    #8,r4             ; r4 = param_1 + 8
0602735C: mov.w  @(0x19E,PC),r1    ; r1 = 0x3FFC (mask)
0602735E: add    r4,r3             ; r3 = r4 + 0x4000 = param_1 + 8 + 0x4000
06027360: mov.l  @(0x188,PC),r0    ; r0 = 0x002F2F20 (base address)
06027362: shlr2  r4                ; r4 = (param_1 + 8) >> 2
06027364: and    r1,r4             ; r4 = r4 & 0x3FFC
06027366: shlr2  r3                ; r3 = (param_1 + 8 + 0x4000) >> 2
06027368: mov.l  @(r0,r4),r2       ; r2 = *(base + offset1)
0602736A: and    r1,r3             ; r3 = r3 & 0x3FFC
0602736C: mov.l  r2,@r5            ; *param_2 = r2
0602736E: nop
06027370: mov.l  @(r0,r3),r1       ; r1 = *(base + offset2)
06027372: rts
06027374: mov.l  r1,@r6            ; *param_3 = r1  (delay slot)
```
Opcode stream: `mov.w, add, mov.w, add, mov.l, shlr2, and, shlr2, mov.l, and, mov.l, nop, mov.l, rts, mov.l` (15 insns)

### Our compiler output (16 insns)
```
mov.l  L2,r2       ; r2 = 0x002F2F20 (base)
mov.w  L3,r1       ; r1 = 0x3FFC (mask)
mov    r4,r0       ; r0 = param_1
add    #8,r0       ; r0 = param_1 + 8
shlr2  r0          ; r0 = (param_1+8) >> 2
and    r1,r0       ; r0 &= 0x3FFC
mov.l  @(r0,r2),r0 ; r0 = *(base + offset1)
mov.l  r0,@r5      ; *param_2 = r0
mov.w  L4,r0       ; r0 = 0x4008  (= 0x4000 + 8)
add    r0,r4       ; r4 = param_1 + 0x4008
shlr2  r4          ; r4 >>= 2
mov    r4,r0       ; r0 = r4  (extra mov!)
and    r1,r0       ; r0 &= 0x3FFC
mov.l  @(r0,r2),r2 ; r2 = *(base + offset2)
rts
mov.l  r2,@r6      ; *param_3 = r2  (delay slot)
```
Opcode stream: 16 insns.

### Root cause analysis

The extra instruction is `mov r4,r0` on line 12 of our output. This happens
because:
1. GCC computes the second offset in `r4` (using `add r0,r4` / `shlr2 r4`)
2. The `and` with the mask r1 needs to produce a result in a register that
   can be used with `mov.l @(r0,rN)` -- the indexed addressing mode requires
   `r0` as one operand.
3. So GCC copies r4 to r0 just to do `and r1,r0`.

The original avoids this by computing the second offset directly in `r3` and
never needing to move it to `r0` -- it uses `mov.l @(r0,r3)` where r0 is the
base address (0x002F2F20). GCC chose r0 for the base address load early on and
reuses it, but the indexed addressing constraint means the computed index must
go into r0 or r0 must hold the base.

The original loads the base in r0 and keeps offsets in r3/r4. Our GCC loads
the base in r2 and needs offsets in r0 (for `@(r0,r2)` addressing), forcing
a copy.

### Proposed fix

We can try to restructure the C so GCC doesn't need the extra copy. The core
issue is the SH `mov.l @(r0,Rn)` indexed addressing, which always requires
r0. If we make the computation flow so that the second offset naturally ends
up in a usable register, we can avoid the copy.

One approach: compute both offsets before doing the stores:

```c
void FUN_06027358(param_1, param_2, param_3)
    int param_1;
    int *param_2;
    int *param_3;
{
    unsigned int off1;
    unsigned int off2;

    off1 = (unsigned)(param_1 + 8) >> 2 & 0x3FFCu;
    off2 = (unsigned)(param_1 + 0x4008) >> 2 & 0x3FFCu;
    *param_2 = *(int *)(0x002F2F20 + off1);
    *param_3 = *(int *)(0x002F2F20 + off2);
}
```

This merges the `+8` and `+0x4000` additions into a single `+0x4008` for the
second expression, which matches what GCC already does. The key question is
whether GCC can avoid the extra `mov` to r0.

**Verdict**: This is a **register allocation** issue. GCC's indexed addressing
on SH requires r0, and moving the computed offset to r0 costs one extra insn.
The original compiler was smarter about register assignment (keeping the base
in r0 and offsets in other registers). This may not be fixable in C without
compiler changes.

---

## 4. FUN_0602E5E4 (ours=13, orig=12, delta=+1)

### Original disassembly (12 insns)
```
0602E5E4: mov.l  @(0x14,PC),r2     ; r2 = &DAT_0607E944 (pointer variable addr)
0602E5E6: mov.l  @r2,r2            ; r2 = *DAT_0607E944 (the pointer value)
0602E5E8: mov.l  @(0x14,PC),r0     ; r0 = 0x00000238   (offset)
0602E5EA: mov.l  @(r0,r2),r1       ; r1 = *(ptr + 0x238)
0602E5EC: mov.l  @(0x14,PC),r0     ; r0 = &DAT_06083264 (destination)
0602E5EE: mov.l  r1,@r0            ; *DAT_06083264 = r1
0602E5F0: mov.l  @(0x14,PC),r0     ; r0 = 0x0000023C   (offset)
0602E5F2: mov.l  @(r0,r2),r1       ; r1 = *(ptr + 0x23C)
0602E5F4: mov.l  @(0x14,PC),r0     ; r0 = &DAT_06083268 (destination)
0602E5F6: mov.l  r1,@r0            ; *DAT_06083268 = r1
0602E5F8: rts
0602E5FA: nop
```
Opcode stream: `mov.l, mov.l, mov.l, mov.l, mov.l, mov.l, mov.l, mov.l, mov.l, mov.l, rts, nop` (12 insns)

Key: The original loads the offsets 0x238 and 0x23C from the constant pool
via `mov.l @(disp,PC),r0`. These are 32-bit values (not shorts), stored in
the .long pool after the function.

### Our compiler output (13 insns)
```
mov.l  L2,r0       ; r0 = &DAT_0607E944
mov.l  @r0,r1      ; r1 = *DAT_0607E944
mov.w  L3,r2       ; r2 = 0x238  (loaded as SHORT from constant pool)
mov    r1,r0       ; r0 = r1   *** EXTRA INSTRUCTION ***
mov.l  @(r0,r2),r2 ; r2 = *(ptr + 0x238)
mov.l  L4,r0       ; r0 = &DAT_06083264
mov.l  r2,@r0      ; *DAT_06083264 = r2
mov.w  L5,r2       ; r2 = 0x23C
mov    r1,r0       ; r0 = r1   *** EXTRA INSTRUCTION ***
mov.l  @(r0,r2),r1 ; r1 = *(ptr + 0x23C)
mov.l  L6,r0       ; r0 = &DAT_06083268
rts
mov.l  r1,@r0      ; delay slot filled
```
Opcode stream: 13 insns.

### Root cause analysis

There are two `mov r1,r0` instructions (lines 4 and 9). The original avoids
these by loading the offsets directly into r0 (using `mov.l @(disp,PC),r0`),
so the `mov.l @(r0,r2)` can use r0 as the offset. Our GCC loads the offsets
into r2 (using `mov.w` for the short constants 0x238/0x23C), then needs to
put the base pointer into r0 for the indexed addressing `@(r0,r2)`.

The original uses `mov.l` (32-bit constant pool) for the offsets, while our
GCC uses `mov.w` (16-bit constant pool). The `mov.w` is actually more
efficient (2-byte pool entry vs 4-byte), but because GCC loads them into r2
instead of r0, it needs to `mov r1,r0` to get the base pointer into r0 for
the indexed load.

Net effect: GCC saves one pool entry size but costs one extra `mov` instruction.
The original's approach of using `mov.l` to load offsets directly into r0 avoids
the extra register copy.

This is again the **r0-indexed addressing constraint**: `mov.l @(r0,Rn)` requires
one of the two registers to be r0. The original puts offsets in r0; our GCC puts
the base pointer in r0 the first time but then loses r0 to other uses.

### Proposed fix

The C source uses `(char *)p + 0x238` which GCC compiles with a `mov.w` load
for the offset. We could try using an int pointer with array-style offset to
hint GCC differently, but fundamentally this is a register allocation issue.

```c
extern int *DAT_0607E944;
extern int DAT_06083264;
extern int DAT_06083268;

void FUN_0602e5e4()
{
    int *p;
    p = DAT_0607E944;
    /* Use word-aligned access: offset 0x238/4 = 0x8E, offset 0x23C/4 = 0x8F */
    DAT_06083264 = p[0x8E];
    DAT_06083268 = p[0x8F];
}
```

Using `p[0x8E]` (array index) instead of `*(int *)((char *)p + 0x238)` might
change GCC's addressing mode selection. The array index translates to
`*(p + 0x8E)` = `*(p + 142)`, which requires `0x8E * 4 = 0x238`. GCC may then
compute the offset differently.

**Verdict**: This is the **r0 indexed addressing constraint** issue. The original
loads offsets into r0 using `mov.l` (32-bit constant pool), while GCC uses `mov.w`
for smaller offsets and puts them in a non-r0 register, forcing a copy of the
base pointer into r0. May not be fully fixable in C.

---

## 5. FUN_06038F34 (ours=16, orig=15, delta=+1)

### Original disassembly (15 insns)
```
06038F34: mov    #0,r4             ; r4 = 0
06038F36: mov    #1,r1             ; r1 = 1
06038F38: mov.l  @(0x20,PC),r2     ; r2 = 0x060635B4
06038F3A: mov.w  r4,@r2            ; *(short*)0x060635B4 = 0
06038F3C: mov.l  @(0x20,PC),r2     ; r2 = 0x060635B8
06038F3E: mov.l  r1,@r2            ; *(int*)0x060635B8 = 1
06038F40: mov.l  @(0x14,PC),r2     ; r2 = 0x060635BC
06038F42: mov.l  r4,@r2            ; *(int*)0x060635BC = 0
06038F44: mov.l  @(0x1C,PC),r2     ; r2 = 0x060635C0
06038F46: mov.l  r4,@r2            ; *(int*)0x060635C0 = 0
06038F48: mov.l  @(0x08,PC),r2     ; r2 = 0x060635C4
06038F4A: mov.l  r4,@r2            ; *(int*)0x060635C4 = 0
06038F4C: mov.l  @(0x18,PC),r2     ; r2 = 0x060635C8
06038F4E: rts
06038F50: mov.l  r4,@r2            ; delay slot: *(int*)0x060635C8 = 0
```
Opcode stream: `mov, mov, mov.l, mov.w, mov.l, mov.l, mov.l, mov.l, mov.l, mov.l, mov.l, mov.l, mov.l, rts, mov.l` (15 insns)

### Our compiler output (16 insns)
```
mov.l  L2,r0       ; r0 = 0x060635B4
mov    #0,r1       ; r1 = 0
mov.w  r1,@r0      ; *(short*)0x060635B4 = 0
mov.l  L3,r0       ; r0 = 0x060635B8
mov    #1,r1       ; r1 = 1          *** ISSUE: r1 was already 0, reloaded to 1
mov.l  r1,@r0      ; *(int*)0x060635B8 = 1
mov.l  L4,r0       ; r0 = 0x060635BC
mov    #0,r1       ; r1 = 0          *** ISSUE: r1 reloaded back to 0
mov.l  r1,@r0      ; *(int*)0x060635BC = 0
mov.l  L5,r0       ; r0 = 0x060635C0
mov.l  r1,@r0      ; *(int*)0x060635C0 = 0
mov.l  L6,r0       ; r0 = 0x060635C4
mov.l  r1,@r0      ; *(int*)0x060635C4 = 0
mov.l  L7,r0       ; r0 = 0x060635C8
rts
mov.l  r1,@r0      ; delay slot
```
Opcode stream: 16 insns.

### Root cause analysis

The original loads `mov #0,r4` and `mov #1,r1` once at the top and reuses
both constants throughout. Our GCC reloads the constants multiple times:
`mov #0,r1` / `mov #1,r1` / `mov #0,r1`. It keeps switching r1 between 0
and 1, costing one extra `mov` instruction.

The original keeps both `0` and `1` in separate registers (r4 for 0, r1 for
1), using 2 registers but only 2 `mov` instructions. Our GCC only uses r1
for both values, requiring 3 `mov` instructions.

**The extra instruction is the third `mov #0,r1`** after the `mov #1,r1` line.

### Proposed fix

Reorder the stores so that the `0` stores happen consecutively and the `1`
store is separate, or use explicit local variables to hint the compiler to
keep both values alive:

```c
void FUN_06038f34()
{
    int zero = 0;
    int one = 1;

    *(short *)0x060635B4 = zero;
    *(int *)0x060635B8 = one;
    *(int *)0x060635BC = zero;
    *(int *)0x060635C0 = zero;
    *(int *)0x060635C4 = zero;
    *(int *)0x060635C8 = zero;
}
```

By assigning `0` and `1` to named variables, GCC may keep both in separate
registers throughout. Alternatively, reorder the stores:

```c
void FUN_06038f34()
{
    *(short *)0x060635B4 = 0;
    *(int *)0x060635BC = 0;
    *(int *)0x060635C0 = 0;
    *(int *)0x060635C4 = 0;
    *(int *)0x060635C8 = 0;
    *(int *)0x060635B8 = 1;
}
```

This groups all zero stores together, allowing GCC to load `0` once and reuse.
But this changes the store order which may not match the expected opcode
sequence. The first approach with named variables is more likely to match.

**Verdict**: This is a **register allocation** issue. GCC only allocates one
register for both constant values, while the original uses two. Using named
variables for the constants may help.

---

## 6. FUN_0603B878 (ours=25, orig=24, delta=+1)

### Original disassembly (24 insns)
```
0603B878: mov.l  @(0x18,PC),r7     ; r7 = &DAT_060A4D14
0603B87A: mov.l  @r7,r5            ; r5 = *DAT_060A4D14 (pointer)
0603B87C: mov.w  @(0x10,PC),r3     ; r3 = 0x0C3C (offset)
0603B87E: add    r3,r5             ; r5 = ptr + 0x0C3C (iVar1 initial value)
0603B880: bra    0x0603B89E        ; goto loop_test
0603B882: mov    #0,r6             ; r6 = 0 (delay slot: iVar2 = 0)
; --- loop body ---
0603B884: cmp/eq r4,r5             ; if iVar1 == param_1
0603B886: bf     0x0603B898        ; if not equal, skip to increment
0603B888: bra    0x0603B8A6        ; break out of loop
0603B88A: nop
; --- (constant pool data interspersed) ---
0603B898: mov.w  @(0x7E,PC),r2     ; r2 = 0x00F0 (step)
0603B89A: add    r2,r5             ; iVar1 += 0xF0
0603B89C: add    #1,r6             ; iVar2++
; --- loop test ---
0603B89E: mov.l  @r7,r3            ; r3 = *DAT_060A4D14
0603B8A0: mov.l  @r3,r2            ; r2 = **DAT_060A4D14 (count limit)
0603B8A2: cmp/ge r2,r6             ; if iVar2 >= limit
0603B8A4: bf     0x0603B884        ; if not, continue loop
; --- post loop ---
0603B8A6: mov.l  @r7,r2            ; r2 = *DAT_060A4D14
0603B8A8: mov.l  @r2,r3            ; r3 = **DAT_060A4D14
0603B8AA: cmp/eq r3,r6             ; if iVar2 == limit
0603B8AC: bf     0x0603B8B0        ; if not, skip
0603B8AE: mov    #0,r5             ; iVar1 = 0
0603B8B0: rts
0603B8B2: mov    r5,r0             ; return iVar1
```
Opcode stream (24 insns): `mov.l, mov.l, mov.w, add, bra, mov, cmp/eq, bf, bra, nop, mov.w, add, add, mov.l, mov.l, cmp/ge, bf, mov.l, mov.l, cmp/eq, bf, mov, rts, mov`

### Our compiler output (25 insns)
```
mov    #0,r2       ; r2 = 0 (iVar2)
mov.l  L9,r0       ; r0 = &DAT_060A4D14
mov.w  L10,r1      ; r1 = 0x0C3C
mov.l  @r0,r0      ; r0 = *DAT_060A4D14
add    r0,r1       ; r1 = ptr + 0x0C3C (iVar1)
mov.l  @r0,r0      ; r0 = *DAT_060A4D14 (re-dereference... wait, double load)
cmp/ge r0,r2       ; if iVar2 >= limit
bt     L3          ; if so, skip loop
mov.w  L11,r3      ; r3 = 0x00F0 (step)
; --- loop ---
cmp/eq r4,r1       ; if iVar1 == param_1
bt     L3          ; break
add    #1,r2       ; iVar2++
cmp/ge r0,r2       ; if iVar2 >= limit
bf.s   L7          ; loop back (delayed)
add    r3,r1       ; iVar1 += 0xF0 (delay slot)
; --- post loop ---
L3:
mov.l  L9,r0       ; r0 = &DAT_060A4D14  *** RE-LOAD ***
mov.l  @r0,r0      ; r0 = *DAT_060A4D14
mov.l  @r0,r0      ; r0 = **DAT_060A4D14
cmp/eq r0,r2       ; if iVar2 == limit
bf.s   L14         ; if not, skip
mov    r1,r0       ; return value = iVar1
mov    #0,r1       ; iVar1 = 0
mov    r1,r0       ; return value = 0
L14:
rts
nop
```
Opcode stream: 25 insns.

### Root cause analysis

The extra instruction comes from GCC's handling of the post-loop section.
Comparing the two:

**Original** (post-loop, 6 insns):
```
mov.l  @r7,r2      ; r7 still holds &DAT_060A4D14 (kept alive across loop)
mov.l  @r2,r3      ; double deref
cmp/eq r3,r6
bf     skip
mov    #0,r5
rts / mov r5,r0
```

**Ours** (post-loop, 8 insns):
```
mov.l  L9,r0       ; RELOAD &DAT_060A4D14 from constant pool
mov.l  @r0,r0      ; dereference
mov.l  @r0,r0      ; double deref
cmp/eq r0,r2
bf.s   L14
mov    r1,r0
mov    #0,r1
mov    r1,r0
rts / nop
```

The original keeps `r7 = &DAT_060A4D14` alive across the entire function
(it uses r7 both in the loop at `mov.l @r7,r3` and after the loop). This
saves one `mov.l` constant pool load.

Our GCC uses r0 for this address and loses it during the loop, requiring a
re-load from the constant pool after the loop. The original uses a dedicated
register (r7) for the pointer, while GCC uses r0 (which gets clobbered).

### Proposed fix

We need GCC to keep the `DAT_060A4D14` pointer in a register across the loop.
Using a local variable that's referenced both in the loop and after may help:

```c
int FUN_0603b878(param_1)
    int param_1;
{
    int iVar1;
    int iVar2;
    int **pp;

    pp = (int **)*(int *)0x060A4D14;
    iVar2 = 0;
    for (iVar1 = (int)pp + 0x0C3C;
        (iVar2 < *pp && (iVar1 != param_1)); iVar1 = iVar1 + 0x00F0) {
        iVar2 = iVar2 + 1;
    }
    if (iVar2 == *pp) {
        iVar1 = 0;
    }
    return iVar1;
}
```

By dereferencing `*(int *)0x060A4D14` into a local `pp` and using `*pp` for
both the loop condition and the post-loop check, GCC should keep `pp` in a
callee-saved register. However, the original actually re-dereferences
`*0x060A4D14` each time (through `r7` which holds the address 0x060A4D14,
not the value). So the key is keeping the *address* 0x060A4D14 in a register.

**Verdict**: This is a **register allocation / spill** issue. GCC doesn't keep
the constant pool address alive across the loop, requiring a reload. The
original compiler keeps it in r7. This may be partially fixable by ensuring
the pointer is used in a way that GCC recognizes it should stay live.

---

## 7. FUN_0603F4E0 (ours=17, orig=16, delta=+1)

### Original disassembly (16 insns)
```
0603F4E0: sts.l  pr,@-r15          ; save PR
0603F4E2: mov    #2,r6             ; r6 = 2 (arg3)
0603F4E4: add    #-12,r15          ; allocate 12 bytes stack
0603F4E6: mov    r15,r5            ; r5 = sp (will be auStack_8)
0603F4E8: mov.l  r4,@(0x4,r15)    ; save param_1 on stack
0603F4EA: bsr    FUN_0603f3f6      ; call(param_1, sp+8, 2)
0603F4EC: add    #8,r5             ; (delay slot) r5 = sp + 8
0603F4EE: mov    #2,r6             ; r6 = 2 (arg3)
0603F4F0: mov    r15,r5            ; r5 = sp (local_10)
0603F4F2: bsr    FUN_0603f3f6      ; call(saved_param, sp, 2)
0603F4F4: mov.l  @(0x4,r15),r4    ; (delay slot) reload param_1
0603F4F6: mov.w  @r15,r0           ; r0 = *(short*)sp (return value)
0603F4F8: add    #12,r15           ; deallocate stack
0603F4FA: lds.l  @r15+,pr          ; restore PR
0603F4FC: rts
0603F4FE: nop
```
Opcode stream (16 insns): `sts.l, mov, add, mov, mov.l, bsr, add, mov, mov, bsr, mov.l, mov.w, add, lds.l, rts, nop`

### Our compiler output (17 insns)
```
mov.l  r8,@-r15    ; *** EXTRA: save r8 ***
sts.l  pr,@-r15    ; save PR
add    #-12,r15    ; allocate stack
mov    r4,r8       ; r8 = param_1 (save in callee-saved reg)
mov    r15,r5      ; r5 = sp
add    #4,r5       ; r5 = sp + 4  (but original does sp+8 via add #8)
bsr    FUN_0603f3f6
mov    #2,r6       ; delay slot
mov    #2,r6
mov    r15,r5
bsr    FUN_0603f3f6
mov    r8,r4       ; delay slot: restore param_1 from r8
mov.w  @r15,r0     ; return value
add    #12,r15
lds.l  @r15+,pr
rts
mov.l  @r15+,r8    ; *** EXTRA: restore r8 ***
```
Opcode stream (17 insns): `mov.l, sts.l, add, mov, mov, add, bsr, mov, mov, mov, bsr, mov, mov.w, add, lds.l, rts, mov.l`

### Root cause analysis

The original saves `param_1` on the stack with `mov.l r4,@(0x4,r15)` and
reloads it with `mov.l @(0x4,r15),r4` in the delay slot of the second bsr.
This uses 0 extra registers (just the stack).

Our GCC saves `param_1` in callee-saved register `r8`, which requires:
- `mov.l r8,@-r15` (save r8 on entry) = +1 insn
- `mov r4,r8` (copy param to r8) = +1 insn
- `mov r8,r4` (restore param from r8) replaces `mov.l @(0x4,r15),r4` = same
- `mov.l @r15+,r8` (restore r8 in rts delay slot) replaces `nop` = same

Net cost: +1 instruction (`mov.l r8,@-r15` at entry; the `mov r4,r8` replaces
the `mov.l r4,@(0x4,r15)` so that's a wash).

Wait, let me recount. Original has `mov.l r4,@(0x4,r15)` which is a
displacement store using the displacement addressing mode. Our code has
`mov r4,r8` (register copy) which is also 1 instruction. The difference is
the `mov.l r8,@-r15` save at the top -- the original doesn't need this
because it uses the stack for param preservation instead of a callee-saved
register.

**The extra instruction is `mov.l r8,@-r15`** (callee-saved register save).

This is the **callee-save vs stack params** known issue (#12). GCC prefers
to save parameters in callee-saved registers across calls, adding push/pop
overhead. The original compiler saves them directly on the stack.

### Proposed fix

The C source already uses stack-based parameter preservation (`uStack_c = param_1`),
but GCC's optimizer promotes this to a register. The variable `uStack_c` is stored
to the stack, but GCC sees that a callee-saved register is more efficient for a
value that needs to survive across two calls.

To force stack-based preservation, we can try using `volatile`:

```c
extern void FUN_0603f3f6();

int FUN_0603f4e0(param_1)
    int param_1;
{
    short local_10[2];
    volatile int saved_param;
    char auStack_8[8];

    saved_param = param_1;
    FUN_0603f3f6(param_1, auStack_8, 2);
    FUN_0603f3f6(saved_param, local_10, 2);
    return (int)local_10[0];
}
```

Making the saved parameter `volatile` prevents GCC from promoting it to a
register, forcing a stack store/load. But this might produce different
addressing than the original.

**Verdict**: This is the **callee-save vs stack params** known issue. GCC uses
r8 (callee-saved) to preserve param_1 across calls, adding a push/pop pair,
while the original uses a stack slot with displacement addressing. The C source
fix with `volatile` may help but needs testing.

---

## 8. FUN_0603F500 (ours=17, orig=16, delta=+1)

### Original disassembly (16 insns)
```
0603F500: sts.l  pr,@-r15          ; save PR
0603F502: mov    #4,r6             ; r6 = 4 (arg3)
0603F504: add    #-12,r15          ; allocate 12 bytes
0603F506: mov    r15,r5            ; r5 = sp
0603F508: mov.l  r4,@(0x4,r15)    ; save param_1 on stack
0603F50A: bsr    FUN_0603f3f6      ; call(param_1, sp+8, 4)
0603F50C: add    #8,r5             ; (delay slot) r5 = sp + 8
0603F50E: mov    #4,r6             ; r6 = 4
0603F510: mov    r15,r5            ; r5 = sp
0603F512: bsr    FUN_0603f3f6      ; call(saved_param, sp, 4)
0603F514: mov.l  @(0x4,r15),r4    ; (delay slot) reload param_1
0603F516: mov.l  @r15,r0           ; r0 = *(int*)sp (return value)
0603F518: add    #12,r15           ; deallocate
0603F51A: lds.l  @r15+,pr          ; restore PR
0603F51C: rts
0603F51E: nop
```
Opcode stream (16 insns): `sts.l, mov, add, mov, mov.l, bsr, add, mov, mov, bsr, mov.l, mov.l, add, lds.l, rts, nop`

### Our compiler output (17 insns)
```
mov.l  r8,@-r15    ; *** EXTRA: save r8 ***
sts.l  pr,@-r15    ; save PR
add    #-12,r15    ; allocate stack
mov    r4,r8       ; r8 = param_1
mov    #4,r6       ; r6 = 4
bsr    FUN_0603f3f6
mov    r15,r5      ; delay slot: r5 = sp
mov    r15,r5      ; r5 = sp
add    #8,r5       ; r5 = sp + 8
mov    #4,r6       ; r6 = 4
bsr    FUN_0603f3f6
mov    r8,r4       ; delay slot: restore param_1
mov.l  @(8,r15),r0 ; r0 = return value (from sp+8)
add    #12,r15
lds.l  @r15+,pr
rts
mov.l  @r15+,r8    ; *** EXTRA: restore r8 ***
```
Opcode stream (17 insns): `mov.l, sts.l, add, mov, mov, bsr, mov, mov, add, mov, bsr, mov, mov.l, add, lds.l, rts, mov.l`

### Root cause analysis

This is the exact same issue as FUN_0603F4E0. The original saves param_1 on
the stack with `mov.l r4,@(0x4,r15)` and reloads it in the delay slot. Our
GCC uses callee-saved r8, adding a push/pop pair.

Additionally, note a subtle difference in the first call: the original
computes `r5 = sp` then uses `add #8,r5` in the delay slot to get `sp+8` for
the first call. The second call passes `sp` directly. Our GCC seems to have
the two calls' buffer arguments swapped compared to the original (first call
gets sp, second gets sp+8 in ours).

Wait, looking more carefully:
- Original: 1st call r5 = sp, then add #8 in delay = sp+8. 2nd call r5 = sp.
- Ours: 1st call r5 = sp (delay slot). 2nd call: r5 = sp, add #8 = sp+8.

The call order in C is: first call with `auStack_8` (sp+8), second with
`&local_10` (sp). The original does this correctly. Our GCC appears to have
swapped which call gets which buffer, but actually looking at the C source,
the first call has `param_1,auStack_8,4` and the second has `uStack_c,&local_10,4`.

The C source has `auStack_8` declared as `char auStack_8[8]` after `local_10` and
`uStack_c`, so their stack layout is: local_10 at sp, uStack_c at sp+4,
auStack_8 at sp+8. The first call passes `auStack_8` (sp+8) and the second
passes `&local_10` (sp). In our output the first call gets sp and the second
gets sp+8 -- this is swapped! The C source needs to swap the buffer arguments
to match.

But the fundamental delta=+1 issue is the **callee-save vs stack params** issue,
identical to FUN_0603F4E0.

### Proposed fix

Same approach as FUN_0603F4E0 -- use volatile for the saved parameter:

```c
extern void FUN_0603f3f6();

int FUN_0603f500(param_1)
    int param_1;
{
    int local_10;
    volatile int saved_param;
    char auStack_8[8];

    saved_param = param_1;
    FUN_0603f3f6(param_1, auStack_8, 4);
    FUN_0603f3f6(saved_param, &local_10, 4);
    return local_10;
}
```

**Verdict**: Same as FUN_0603F4E0 -- **callee-save vs stack params** issue.

---

## Summary Table

| Function | Delta | Root Cause | Category | Fixable in C? |
|-----------|-------|-----------|----------|---------------|
| FUN_06018EC8 | +1 | Extern address load vs inline constant pool | Extern vs const pool (#6) | Yes - use literal 0xE0 |
| FUN_0601DB84 | +1 | GCC uses movt to derive 1 instead of pre-loading | Register alloc / codegen | Maybe - use explicit variable |
| FUN_06027358 | +1 | Extra mov to r0 for indexed addressing | r0 constraint / reg alloc | Unlikely |
| FUN_0602E5E4 | +1 | Extra mov to r0 for indexed addressing | r0 constraint / reg alloc | Unlikely |
| FUN_06038F34 | +1 | Constants 0/1 not kept in separate regs | Register allocation | Maybe - named variables |
| FUN_0603B878 | +1 | Pointer address reloaded from const pool | Register alloc / spill | Maybe - restructure pointer |
| FUN_0603F4E0 | +1 | Callee-saved r8 push/pop vs stack save | Callee-save vs stack (#12) | Maybe - volatile param |
| FUN_0603F500 | +1 | Callee-saved r8 push/pop vs stack save | Callee-save vs stack (#12) | Maybe - volatile param |

### Category breakdown
- **r0 indexed addressing constraint**: 2 functions (FUN_06027358, FUN_0602E5E4)
- **Callee-save vs stack params**: 2 functions (FUN_0603F4E0, FUN_0603F500)
- **Register allocation**: 2 functions (FUN_0601DB84, FUN_06038F34)
- **Extern vs constant pool**: 1 function (FUN_06018EC8)
- **Register spill/reload**: 1 function (FUN_0603B878)

### Experimentally verified fixes

All proposed fixes were compiled with the patched GCC 2.6.3 cc1. Results:

#### CONFIRMED WORKING (count matches target):

1. **FUN_06018EC8**: `short val = 0x00E0` produces 7 insns (was 8). Uses `mov.w`
   from constant pool. Opcode sequence differs from original (no `extu.b`, unfilled
   delay slot) but count matches. Alternative with literal `0xE0` also produces 7.

2. **FUN_0603F4E0**: `volatile int saved_param` produces 16 insns (was 17). GCC
   now uses stack-based `mov.l r4,@(4,r15)` / `mov.l @(4,r15),r4` instead of
   callee-saved r8. Opcode sequence differs in ordering but count matches.

3. **FUN_0603F500**: Struct-based approach `{ int val; int saved; char buf[8]; }`
   produces 16 insns (was 17). The `volatile` approach did NOT work for this one
   (produced 18 insns), but the struct layout forces the right stack frame.

#### NOT FIXABLE IN C (compiler limitation):

4. **FUN_0601DB84**: All C variants still produce 14 insns. GCC's `movt` codegen
   is deeply embedded in the dt+branch pattern handling. Would need a compiler
   patch to prefer `mov #1,rN` over `movt rN` when the stored value is known
   to be exactly 1.

5. **FUN_06027358**: All C variants still produce 16 insns. The `mov r4,r0`
   copy for r0-indexed addressing is unavoidable with GCC's register allocator.

6. **FUN_0602E5E4**: All C variants still produce 13 insns. Same r0-indexed
   addressing constraint as FUN_06027358.

7. **FUN_06038F34**: All C variants still produce 16 insns (or worse). GCC
   consistently reloads constants rather than keeping both in separate registers.
   `register int` keyword, named variables, volatile, reordering -- none helped.
   Would need a compiler patch to improve constant CSE across stores.

8. **FUN_0603B878**: Not tested extensively but root cause (constant pool reload
   after loop) is a fundamental register allocation limitation.

### Recommended C source changes

Apply these 3 fixes to reduce the total delta by 3:

**src/FUN_06018EC8.c** -- replace extern with constant pool literal:
```c
extern volatile char REG_25B00217;
extern volatile char REG_25B00237;

void FUN_06018ec8()
{
    short val = 0x00E0;
    REG_25B00217 = (unsigned char)val;
    REG_25B00237 = (char)val;
}
```

**src/FUN_0603F4E0.c** -- volatile saved parameter:
```c
extern void FUN_0603f3f6();

int FUN_0603f4e0(param_1)
    int param_1;
{
    short local_10[2];
    volatile int saved_param;
    char auStack_8[8];

    saved_param = param_1;
    FUN_0603f3f6(param_1, auStack_8, 2);
    FUN_0603f3f6(saved_param, local_10, 2);
    return (int)local_10[0];
}
```

**src/FUN_0603F500.c** -- struct-based stack layout:
```c
extern void FUN_0603f3f6();

int FUN_0603f500(param_1)
    int param_1;
{
    struct { int val; int saved; char buf[8]; } frame;

    frame.saved = param_1;
    FUN_0603f3f6(param_1, frame.buf, 4);
    FUN_0603f3f6(frame.saved, &frame.val, 4);
    return frame.val;
}
```

### Fixes requiring compiler patches

- **FUN_0601DB84**: Patch GCC to emit `mov #1,rN` instead of `movt rN` when
  the value stored is known to be 1 and it would eliminate a `bf.s`/`movt` pair
- **FUN_06027358, FUN_0602E5E4**: Improve r0 allocation for indexed addressing;
  prefer loading base address into r0 and computing offsets in other registers
- **FUN_06038F34**: Improve constant CSE to keep both 0 and 1 in separate registers
  rather than reloading between uses
- **FUN_0603B878**: Keep loop-invariant constant pool addresses in dedicated registers
  across loop bodies
