# Matching Decompilation Workflow

This document captures techniques for writing C code that compiles to byte-identical
assembly as the original binary. The goal is not just "working" code but **matching** code.

## Core Principle

**The assembly diff is the primary diagnostic tool, not pass/fail testing.**

A function that "boots" may still be wrong. A function that "crashes" tells you nothing
about WHERE the code diverges. The diff tells you exactly what to fix.

---

## The Breakthrough: C Structure Affects Codegen

**This is the most important insight for matching work.**

Ghidra's decompilation is semantically correct but structurally wrong. GCC 2.6.3's instruction
scheduling is heavily influenced by HOW you write C, not just WHAT you compute.

### Assembly Is Ground Truth

The workflow is NOT:
```
Ghidra output → Fix syntax errors → Declare "challenging"
```

The workflow IS:
```
Assembly → Understand operation ORDER → Write C that mirrors that structure
```

### Variable Declaration Order Matters

GCC loads constants in the order they appear in the source. Declaring a variable early
causes its initializer to be loaded early.

**Example: FUN_06027348**

Expected assembly order:
```asm
mov.w   @(N,pc),r2    ; load mask 0x3FFC first
mov     r4,r0         ; then use param
shlr2   r0
add     #2,r0
and     r2,r0
...
```

Ghidra's C (WRONG order - mov.w comes too late):
```c
int FUN_06027348(param_1)
    unsigned int param_1;
{
    return *(int *)(0x002F2F20 + ((param_1 >> 2) + 2 & 0x3FFC));
}
```

Fixed C (MATCHES - declare mask first):
```c
int FUN_06027348(param_1)
    unsigned int param_1;
{
    unsigned int mask = 0x3FFC;
    unsigned int offset = ((param_1 >> 2) + 2) & mask;
    return *(int *)(0x002F2F20 + offset);
}
```

**Why it works**: Declaring `mask` as a separate variable FIRST causes GCC to emit the
`mov.w` constant load FIRST. The assembly order now matches production.

### Expression Decomposition

Complex expressions can be broken into steps to control instruction order:

| Ghidra Style | Matching Style |
|--------------|----------------|
| `*(base + (x >> 2) & mask)` | `tmp = (x >> 2) & mask; *(base + tmp)` |
| `func(a + b, c * d)` | `arg1 = a + b; arg2 = c * d; func(arg1, arg2)` |
| `if (a && b && c)` | Nested `if (a) { if (b) { if (c) {...}}}` |

### The Matching Mindset

1. **Read the expected assembly first** - not Ghidra
2. **Note the instruction order** - especially constant loads
3. **Identify what values are computed when**
4. **Write C that mirrors that computation order**
5. **Use intermediate variables liberally** - they often get optimized away anyway
6. **Iterate on structure, not just types**

### Ghidra Is NOT Sacred

Ghidra's decompilation is:
- ✅ Semantically correct (computes the same result)
- ❌ Structurally wrong (instructions in different order)
- ❌ Not optimized for matching (expressions too compact)

**Don't try to "fix" Ghidra's output. Rewrite from scratch based on assembly.**

---

## The Iterative Matching Loop

```
1. Read the C source (src/FUN_XXXX.c or Ghidra decompilation)
2. Read the expected assembly (tests/FUN_XXXX.expected or aprog.s)
3. Compile our C → get our assembly
4. Diff our assembly vs expected, line by line
5. Identify WHERE divergence starts
6. Reason about WHY (wrong type? wrong op? missing param?)
7. Make targeted edit to C code
8. Recompile, check if diff improved
9. Repeat until match or document the blocker
10. THEN boot test (functional validation comes after matching)
```

## Progress States & When to Commit

Not every function will reach PASS. **Commit improvements even if not perfect.**

### Progress Hierarchy (best to acceptable)

| State | Meaning | Action |
|-------|---------|--------|
| **PASS** | Exact opcode match | Keep - perfect |
| **delta<0** | Our code SHORTER, functionally correct | Keep - our compiler is smarter |
| **delta=0 improved** | Same count, fewer opcode diffs than before | Keep - progress made |
| **delta>0 reduced** | Our code longer, but less than before | Keep - closer to matching |
| **Challenging identified** | Root cause documented, no C-level fix | Keep current best state |

### Why delta<0 Is Good

When our code is shorter (delta<0), it means:
- Functionally identical (same computation)
- Our GCC optimized better than original
- Example: FUN_06018EC8 skips redundant `extu.b` before byte store

**These are keepers.** The original compiler just wasn't as good at this optimization.

### Commit Discipline

```
After investigating a function:
1. If PASS → commit with "PASS: FUN_XXXXXX"
2. If improved (any delta reduction or opcode fix) → commit with "improve: FUN_XXXXXX delta=N"
3. If challenging but documented → commit with "challenging: FUN_XXXXXX (reason)"
4. If no change → don't commit, move on
```

This ensures progress survives context compaction across 800+ functions.

---

## Assembly Diff Workflow

```bash
# Compile a single function
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- /mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1 \
  -quiet -O2 -m2 -mbsr src/FUN_XXXX.c -o /tmp/test.s

# Extract opcodes from our output (strip operands for mnemonic comparison)
grep -v '^\s*[.#;]' /tmp/test.s | awk '{print $1}' > /tmp/ours.txt

# Compare against expected
diff /tmp/ours.txt tests/FUN_XXXX.expected
```

## Common Mismatch Patterns & Fixes

### Type Width Mismatches
| Symptom | Cause | Fix |
|---------|-------|-----|
| Extra `exts.w` or `exts.b` | Using `short`/`char` where original uses `int` | Change to `int` |
| Extra `extu.w` or `extu.b` | Signed type where original is unsigned | Add `unsigned` |
| `mov.w` vs `mov.l` | Wrong pointer/data size | Check if `short*` vs `int*` |

### Operator Mismatches
| Symptom | Cause | Fix |
|---------|-------|-----|
| Call to `___mulsi3` | Using `* N` | Use `<< log2(N)` instead |
| `cmp/hi` vs `cmp/gt` | Range check optimization | Restructure conditional |
| Different branch type | Signed vs unsigned comparison | Check signedness |

### Structure/Offset Mismatches
| Symptom | Cause | Fix |
|---------|-------|-----|
| Wrong displacement value | Ghidra got offset wrong | Check raw disassembly |
| Extra adds for offset | Offset > displacement range | May need temp variable |

### Control Flow Mismatches
| Symptom | Cause | Fix |
|---------|-------|-----|
| Instructions reordered | Scheduler differences | Try `-fno-schedule-insns2` |
| Different branch structure | Loop type mismatch | Try do-while vs while vs for |
| Extra/missing code | Ghidra missed a branch | Re-analyze control flow |

### Parameter/Calling Mismatches
| Symptom | Cause | Fix |
|---------|-------|-----|
| Missing register setup before call | Wrong parameter count | Check callers for actual args |
| Wrong return handling | Wrong return type | Check callers for usage |

---

## Advanced Technique: Register Control with `register asm("rN")`

GCC 2.6.3 supports forcing specific registers for variables using the `register asm` syntax.
This is a powerful technique for fixing register allocation issues and enabling tail calls.

### Why It Works

GCC prefers callee-saved registers (r8-r14) even when unnecessary, adding push/pop overhead.
By forcing caller-saved registers (r0-r7), we can:
1. **Avoid push/pop overhead** - no callee-saved register spill
2. **Enable tail call optimization** - function pointers in r3 can become `jmp @r3`
3. **Match original register choices** - original compiler often used caller-saved

### Syntax

```c
register int var asm("r3");  // Force 'var' into r3
register int *ptr asm("r1"); // Force 'ptr' into r1
```

### Example: Enabling Tail Call (FUN_0600DC74)

**Before** (delta +3 - uses callee-saved r8, r9 with push/pop):
```c
void FUN_0600dc74()
{
    (*(int(*)())0x060284AE)(8,(int)DAT_0600dc9c,0x60,0x0605ACE8);
    (*(int(*)())0x060284AE)(8,(int)DAT_0600dc9e,0x60,0x0605ACE8);
}
```

**After** (delta -2 - forces r0, r3, enables tail call):
```c
void FUN_0600dc74()
{
    register int addr asm("r0") = 0x0605ACE8;
    register int func asm("r3") = 0x060284AE;
    (*(int(*)())func)(8,(int)DAT_0600dc9c,0x60,addr);
    (*(int(*)())func)(8,(int)DAT_0600dc9e,0x60,addr);  // Becomes jmp @r3
}
```

**Why tail call works**: With the function pointer in r3 and no callee-saved registers,
the final call can become `jmp @r3` instead of `jsr @r3 / rts`.

### Example: Shared Offset Calculation (FUN_06011E7C)

**Before** (delta +1 - GCC uses r8-r10 for temporaries):
```c
void FUN_06011e7c()
{
    int off = (int)DAT_06011efe;
    (*(int(*)())0x06028400)(0xc,*(int *)0x060638B0,(int)DAT_06011f00, *(int *)0x060638B4 + off);
    (*(int(*)())0x06028400)(0xc,*(int *)0x060638A0,(int)DAT_06011f02, *(int *)0x060638A4 + off);
}
```

**After** (delta -3 - forces r2, r3):
```c
void FUN_06011e7c()
{
    register int func asm("r3") = 0x06028400;
    register int off asm("r2");
    off = (int)DAT_06011efe;
    (*(int(*)())func)(0xc,*(int *)0x060638B0,(int)DAT_06011f00, *(int *)0x060638B4 + off);
    (*(int(*)())func)(0xc,*(int *)0x060638A0,(int)DAT_06011f02, *(int *)0x060638A4 + off);
}
```

### When To Use

| Use Case | Benefit |
|----------|---------|
| Repeated function calls | Put function address in r3, reuse across calls |
| Shared values across calls | Put common values in r0-r2, avoid reloads |
| Tail call optimization | Function ptr in r3 + no callee-saved = `jmp @r3` |
| Pointer variables | Force into specific register to match original codegen |

### Caveats

1. **Don't use with complex code** - if too many register constraints, GCC fails with
   "fixed or forbidden register was spilled"
2. **Caller-saved registers only** - r0-r7 are safe; r8-r14 defeat the purpose
3. **r0 is special** - often used for return value and displacement addressing
4. **Check the assembly** - verify the technique actually helped before committing

### Register Reference

| Register | Role | Safe to Force? |
|----------|------|----------------|
| r0 | Return value, special displacement | Yes, but check usage |
| r1-r3 | Temps, function ptrs | Yes - best for forcing |
| r4-r7 | Arguments | Yes, but may conflict with params |
| r8-r14 | Callee-saved | No - defeats purpose |
| r15 | Stack pointer | Never |

---

## Challenging Patterns (Not Yet Solved)

> **Mindset shift**: "Challenging" means "not yet solved", NOT "proven impossible."
> The `register asm("rN")` fix for FUN_06005174 was discovered by accident.
> More techniques likely exist that we haven't found yet.

These patterns are caused by differences between GCC 2.6.3 and the original compiler.
Many require compiler patches, but some may have undiscovered C-level fixes.

### Register Allocation
| Pattern | Example | Cause |
|---------|---------|-------|
| Callee-saved vs caller-saved | `push r8` vs no push | GCC prefers r8-r14 |
| extu.w destination | `extu.w r4,r4` vs `extu.w r4,r0` | Allocator choice |
| Indexed addressing | `mov.l @(r0,r1),r0` vs `add` + `mov.l` | Our patch combines them |

### Instruction Scheduling
| Pattern | Example | Cause |
|---------|---------|-------|
| Prologue ordering | mov/sts order differs | RTL expansion order |
| Argument evaluation | param setup before computation | Scheduler choice |
| Loop compare placement | cmp at end vs interleaved | Loop scheduling |

### RTL Combiner Optimizations
| Pattern | Example | Cause |
|---------|---------|-------|
| Missing extu.b | No zero-extend before byte store | RTL knows mov.b only uses 8 bits |
| Range check | `cmp/hi` vs `cmp/gt` + `cmp/ge` | fold_truthop combines tests |

### Tail Call Optimization
| Pattern | Example | Cause |
|---------|---------|-------|
| bra vs bsr | Original uses `bra` (jmp), we use `bsr` (jsr) | GCC doesn't see as tail call |
| jmp vs jsr | Function ptr `jmp @rN` vs `jsr @rN` | Same - tail call not detected |
| lds.l placement | `lds.l` before `bra` vs after `bsr` | Tail call avoids PR restore |

### Function Boundary Issues
| Pattern | Example | Functions Affected |
|---------|---------|-------------------|
| Fall-through entry | `mov #N,rX` then falls into main | FUN_0601209E, FUN_06013E12 |
| Shared code bodies | Two entry points, same body | Adjacent function pairs |

### When to Stop Trying

If you see these patterns, document and move on:
1. `push rN` in prologue that original doesn't have → register allocation
2. Instruction order matches but different registers → scheduling
3. Fewer instructions than original (delta<0) → our code is better optimized
4. Function address falls inside another function → Ghidra boundary error

---

## Cross-Reference Analysis

Before editing a function, understand its context:

### Find Callers
```bash
# Search for calls to function address
grep -n "jsr.*06035C08\|bsr.*06035C08" build/aprog.s
```

### Analyze Caller Context
Look at what the caller puts in r4-r7 before the call:
- r4 = first parameter
- r5 = second parameter
- r6 = third parameter
- r7 = fourth parameter

This reveals actual parameter types that Ghidra may have missed.

### Find Callees
Look at what functions this one calls - helps understand data flow.

## Context Building (Structs & Types)

When you see repeated offset patterns like:
```c
*(param_1 + 0x10)  // X position?
*(param_1 + 0x14)  // Y position?
*(param_1 + 0x18)  // Z position?
```

Define a struct:
```c
typedef struct {
    char padding[0x10];
    int x;
    int y;
    int z;
} Object3D;
```

Benefits:
- One fix propagates to all functions using this struct
- Makes code readable
- Ghidra can re-import and propagate types

## Ghidra As Reference (Not Source of Truth)

**Critical insight from decomp community**: Ghidra's output is NOT accurate enough to copy-paste.
It's a **reference** to help understand what assembly does, not the source of matching C code.

> "The decompiler in Ghidra is primarily useful for reference. It helps when analyzing
> assembly, but it's not suitable for producing high-level source code that compiles
> to an identical binary." — [BotW Decompilation](https://botw.link/contribute/decompiler-setup)

### What Ghidra Gets Wrong

Ghidra frequently misses or misinterprets:
- **Parameter counts** - may show `void` when function takes 2+ params
- **Parameter types** - may use wrong width (int vs short)
- **Return types** - may not detect return value
- **Indirect calls** - shows as `(*(code*)PTR)()` without context

### Verify Signatures Against Call Sites

**ALWAYS check actual callers before trusting Ghidra's signature.**

Example - FUN_06035C08:
```
Ghidra says:    undefined4 FUN_06035c08(void)     ← WRONG, no params

Caller shows:   mov r9,r5      ; r5 = second param
                mov r12,r4     ; r4 = first param
                jsr @r3        ; call FUN_06035C08

Reality:        int FUN_06035c08(int* param1, int param2)  ← TWO params
```

### How To Verify Function Signature

```bash
# 1. Find all callers
grep -n "06035C08" build/aprog.s

# 2. Look at instructions BEFORE each call
#    - What's in r4? → first param
#    - What's in r5? → second param
#    - What's in r6? → third param
#    - What's in r7? → fourth param

# 3. Look at instructions AFTER the call
#    - Is r0 used? → function returns a value
```

### What We Use Ghidra For

| Use | How |
|-----|-----|
| **Understand intent** | Read pseudocode to get rough mental model |
| **Find callees** | See what functions are called inside |
| **Offset patterns** | Notice `param+0x10`, `param+0x14` → struct fields |
| **Control flow** | Loops, conditionals, early returns |

### What We DON'T Use Ghidra For

| Don't | Why |
|-------|-----|
| Copy-paste signatures | Often wrong - verify against callers |
| Copy-paste expressions | Compiler generates different code |
| Trust parameter counts | Ghidra misses params frequently |
| Trust types | Width/signedness often wrong |

### Our Files

| File | Contains |
|------|----------|
| `ghidra_project/decomp_all.txt` | Static dump of all decompilations (reference) |
| `build/aprog.s` | Actual disassembly (ground truth for call sites) |

## Compiler-Specific Knowledge (GCC 2.6.3 SH-2)

### Flags We Use
- `-O2` - optimization level 2
- `-m2` - SH-2 target (enables dt, bf.s/bt.s)
- `-mbsr` - enable BSR for direct calls

### Known Codegen Patterns
- Post-reload scheduling is ON (can cause reordering)
- Range checks get optimized to unsigned comparisons
- Multiply by power of 2 should use shifts
- Sign extension inserted for narrow loads to wide registers

### Patches Applied
See `docs/compiler_patches.md` for patches we've made to match original codegen.

## Function Triage

When picking which function to work on:

### Good Candidates
- Higher match% (fewer differences to fix)
- Smaller instruction count (less to analyze)
- Called by functions we understand (better context)
- Similar to functions we've already matched (pattern reuse)

### Avoid Initially
- 0% match with complex logic (likely major decompilation errors)
- Functions with switch/case tables (complex codegen)
- Functions calling unknown externals (missing context)

## Known Patcher Limitations

### Constant Pool Overflow

Our GCC generates inline constant pools (constants placed right after function code).
The original compiler used shared constant pools (constants in dedicated areas, accessed via
large PC-relative offsets).

**Problem**: When our function is patched into the binary, our inline constants may overflow
into the next function's space, corrupting it.

**Symptoms**: Function PASSES test harness but CRASHES at boot.

**Example**: FUN_06012E62
- Original: 8 bytes code, constants 0x32 bytes away in shared pool
- Ours: 8 bytes code + 8 bytes constants = 16 bytes total
- Next function (FUN_06012E6A) starts 8 bytes after → our constants overwrite it!

**Workaround**: None currently. Would require patcher changes to handle constant relocation.

## Documenting Blockers

When a function can't be matched, document WHY:

```markdown
### FUN_XXXXXXXX - BLOCKED
- **Issue**: Compiler generates X but original has Y
- **Root cause**: [scheduler/combiner/allocator/etc.]
- **Possible fixes**: [compiler patch / C rewrite / accept mismatch]
- **Priority**: [high/medium/low based on function importance]
```

## Automated Ghidra Queries

We have headless Ghidra scripts for automated lookups. These eliminate the need for manual
Ghidra interaction for common queries.

### Usage

```bash
# Query function info (signature, callers, callees)
tools\ghidra_query.bat GetInfo 0x06028560

# Query data at address (type, value, references)
tools\ghidra_query.bat GetData 0x0609A240
```

### Available Scripts

| Script | Purpose |
|--------|---------|
| `GetInfo <addr>` | Function signature, all callers, all callees |
| `GetData <addr>` | Data type, value, and references to this address |

### Script Location

Scripts are in `ghidra_scripts/*.java` (Java required for headless - Ghidra 12 uses PyGhidra for Python).

### Example Output

```
=== Address: 0x06028560 ===
FUNCTION: FUN_06028560
Entry: 0x06028560
Signature: undefined FUN_06028560(void)    ← NOTE: Ghidra often wrong, verify with callers!
Size: 18 bytes

CALLERS (references TO this function):
  0x0601f9ec in FUN_0601f9cc
  0x0600a03e in FUN_0600a026
  ...
```

### When To Use

1. **Before investigating a function** - Get caller context, understand who uses it
2. **When encountering a hardcoded address** - Query what data/code is there
3. **To verify Ghidra's signature** - Compare `Signature:` line against caller r4-r7 setup

## Tools Reference

| Tool | Purpose |
|------|---------|
| `tools/gcc26-build/cc1` | Our patched GCC 2.6.3 compiler |
| `tools/test_harness.sh` | Batch compile & compare |
| `tools/ghidra_query.bat` | Headless Ghidra queries |
| `build/aprog.s` | Original binary disassembly |
| `build/aprog_syms.txt` | Function addresses |
| `ghidra_project/decomp_all.txt` | Ghidra decompilation dump |
| `tests/*.expected` | Expected opcode sequences |
| `src/*.c` | Our C source files |

## Advanced Techniques from Decomp Community

These techniques come from the broader matching decompilation community (Mario 64, Zelda OoT, etc.)
and may apply to GCC 2.6.3 SH-2 with adaptation.

### Temporary Variable Introduction

Creating temp variables can force different register allocation:

```c
// Before - compiler decides register assignment
result = func(a + b, c * d);

// After - temp forces value into register before call
int tmp1 = a + b;
int tmp2 = c * d;
result = func(tmp1, tmp2);
```

**Key insight**: A temp variable doesn't change semantics, but MAY change regalloc if the
assignment is moved to another basic block.

### Expression Duplication

Duplicate expressions to trigger compiler deduplication:

```c
// Original doesn't match
x = arr[i];

// Duplicating the expression can change codegen
x = arr[i];
(void)arr[i];  // Force compiler to see it twice
```

### Statement Separation & Joining

The way statements are separated affects instruction interleaving:

```c
// Separated statements - independent scheduling
a = x;
b = y;

// Comma-separated - forces specific ordering
a = x, b = y;

// Same line can affect IDO-style compilers (may not affect GCC)
a = x; b = y;
```

### Loop Anti-Unrolling

Prevent loop unrolling for small loops:

```c
// Add meaningless increment/decrement to confuse unroller
for (i = 0; i < 4; i++) {
    body();
    i++; i--;  // Prevents unrolling
}

// Or use continue statement
for (i = 0; i < 4; i++) {
    body();
    continue;  // May prevent unrolling
}
```

### Pointer vs Array Iteration

Different loop forms produce different codegen:

```c
// Array indexing
for (i = 0; i < 10; i++) {
    arr[i] = 0;
}

// Pointer iteration (often different codegen)
for (ptr = arr; ptr < arr + 10; ptr++) {
    *ptr = 0;
}

// Explicit end pointer
int *end = &arr[10];
for (ptr = arr; ptr != end; ptr++) {
    *ptr = 0;
}
```

### Type Cast Effects on Ordering

Casts can affect operand ordering in commutative operations:

```c
// These may produce different instruction order
a + b
(unsigned)a + b
a + (unsigned)b
```

### Conditional Form Variations

Different ways to write conditions produce different codegen:

```c
// These compile differently
if (x)
if (x != 0)
if (x == 1)
if ((x ^ 0) < 1)  // May be recognized as x == 0
```

### Ternary vs If-Else

Generally equivalent but can have reordering differences:

```c
// Ternary
a = b ? c : d;

// If-else (may generate same code with different ordering)
if (b) a = c;
else a = d;
```

### Struct Copy vs Member Copy

Copying whole struct vs members can differ:

```c
// Member-by-member
dst->x = src->x;
dst->y = src->y;
dst->z = src->z;

// Whole struct copy (includes padding, different codegen)
*dst = *src;
```

### Volatile for Memory Ordering

`volatile` forces address computation before access:

```c
// Normal - compiler may fold address into load
int val = *(int*)0x12345678;

// Volatile - separate address computation
int val = *(volatile int*)0x12345678;
```

### Loop Header Initialization

Multiple initializations in loop header:

```c
// Separate initialization
i = 0;
other = 4;
for (; i < 4; i++) { ... }

// Combined in header (different codegen)
for (i = 0, other = 4; i < 4; i++) { ... }
```

### Integer Promotion

Explicit promotion for small types:

```c
// Implicit
unsigned char mask = var;
result = data & mask;

// Explicit (may affect codegen)
unsigned char mask = var;
unsigned int mask32 = mask;
result = data & mask32;
```

### Early Return vs Normal Flow

Can produce different instruction ordering:

```c
// Early return
if (error) return -1;
do_work();
return 0;

// Else branch
if (error) {
    return -1;
} else {
    do_work();
    return 0;
}
```

### Decomp Permuter

[decomp-permuter](https://github.com/simonlindholm/decomp-permuter) is a tool that
automatically tries code variations to find matches. Key macros:

| Macro | Effect |
|-------|--------|
| `PERM_GENERAL(a, b, c)` | Try each alternative |
| `PERM_LINESWAP(...)` | Try statement permutations |
| `PERM_RANDOMIZE(code)` | Allow random variations in region |
| `PERM_FORCE_SAMELINE` | Join statements on one line |

**Note**: Permuter works best for regalloc tweaks at the end, not structural changes.

## External Resources

- [decomp.me](https://decomp.me) - Interactive matching scratches
- [decomp.dev](https://decomp.dev) - Project progress tracking
- [Decompedia](https://decomp.wiki/) - Community knowledge base
- [RetroReversing](https://www.retroreversing.com/) - Tutorials and guides
- [OoT -O2 Decompilation Guide](https://github.com/n64decomp/oot/blob/master/docs/guides/-O2%20decompilation%20(for%20IDO%205.3).md) - IDO-specific but many patterns apply
- [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) - Automatic code permutation tool
