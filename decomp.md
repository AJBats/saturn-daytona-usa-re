# Matching Decompilation Workflow

This document captures techniques for writing C code that compiles to byte-identical
assembly as the original binary. The goal is not just "working" code but **matching** code.

## Core Principle

**The assembly diff is the primary diagnostic tool, not pass/fail testing.**

A function that "boots" may still be wrong. A function that "crashes" tells you nothing
about WHERE the code diverges. The diff tells you exactly what to fix.

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

## Ghidra Interactive Workflow

We should be using Ghidra iteratively, not one-shot:

1. **Fix function signatures** - correct parameter count/types
2. **Define structs** - from observed offset patterns
3. **Label globals** - `DAT_06061234` → `g_PlayerData`
4. **Set data types** - mark arrays, pointers, etc.
5. **Re-export** - get improved decompilation
6. **Repeat** - each fix helps other functions

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

## Documenting Blockers

When a function can't be matched, document WHY:

```markdown
### FUN_XXXXXXXX - BLOCKED
- **Issue**: Compiler generates X but original has Y
- **Root cause**: [scheduler/combiner/allocator/etc.]
- **Possible fixes**: [compiler patch / C rewrite / accept mismatch]
- **Priority**: [high/medium/low based on function importance]
```

## Tools Reference

| Tool | Purpose |
|------|---------|
| `tools/gcc26-build/cc1` | Our patched GCC 2.6.3 compiler |
| `tools/test_harness.sh` | Batch compile & compare |
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
