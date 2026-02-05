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
Ghidra output → Fix syntax errors → Declare "intractable"
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
| **Intractable identified** | Root cause documented, no C-level fix | Keep current best state |

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
3. If intractable but documented → commit with "intractable: FUN_XXXXXX (reason)"
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

## External Resources

- [decomp.me](https://decomp.me) - Interactive matching scratches
- [decomp.dev](https://decomp.dev) - Project progress tracking
- [Decompedia](https://decomp.wiki/) - Community knowledge base
- [RetroReversing](https://www.retroreversing.com/) - Tutorials and guides
