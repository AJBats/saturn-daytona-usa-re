# ASM Matching to Boot Workstream

## Goal
Systematically convert FAIL functions to PASS by matching production assembly, then verify each boots correctly.

## Selection Criteria

1. **Primary**: Smallest instruction count (easier to reason about)
2. **Tiebreaker**: Larger |delta| (more room for improvement)
3. **Ignore**: Historical boot status (fresh pass through all candidates)

### Candidate Pool
From `docs/function_catalog.md`:
- 819 FAIL functions available
- Prioritize: small functions (≤20 insns) with |delta| > 5

## Workflow Per Function

### Step 1: SELECT
```bash
# Review catalog for next candidate
cat docs/function_catalog.md | grep FAIL | head -20
```
Pick smallest FAIL function. Record in this doc under "Progress" section.

### Step 2: MATCH (decomp.md workflow)

```bash
# Compile and diff against expected
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash -c "
  cd /mnt/d/Projects/SaturnReverseTest
  ./tools/gcc26-build/cc1 -quiet -O2 -m2 -mbsr src/FUN_XXXXXXXX.c -o /tmp/test.s 2>&1
  grep -P '^\t[a-z]' /tmp/test.s | sed 's/\t/ /g' | awk '{print \$1}' > /tmp/got.txt
  diff -u tests/FUN_XXXXXXXX.expected /tmp/got.txt
"
```

Iterate:
1. **Identify WHERE**: Line-by-line diff shows first divergence point
2. **Reason WHY**: Wrong type? Wrong op? Missing cast? Ghidra error?
3. **Fix C source**: Edit `src/FUN_XXXXXXXX.c`
4. **Recompile**: Check if delta improved
5. **Repeat** until `diff` shows no differences (PASS)

Common fixes (from decomp.md):
- Function pointer casts: `(*(int(*)())0xADDR)(args)`
- Shift precedence: `ptr + (expr << n)`
- Type narrowing: `short` vs `int` for sign extension
- Volatile for load ordering
- Explicit casts to match original width

### Step 3: PATCH
```bash
# Add function to include list
echo "FUN_XXXXXXXX" >> build/test_include.txt

# Build patched disc
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash tools/build_disc.sh
```

### Step 4: BOOT TEST
```powershell
# Run automated boot test (captures screenshot at title screen)
powershell -ExecutionPolicy Bypass -File tools\test_boot.ps1 -Cue patched

# Compare against vanilla baseline
python tools/compare_screenshot.py build/screenshots/patched_latest.png build/screenshots/vanilla_latest.png
```

Exit codes:
- `0` = PASS (screenshots match within tolerance)
- `1` = FAIL (black screen, visual corruption, or mismatch)
- `2` = ERROR (file not found)

### Step 5: STAMP RESULT

Record in `docs/boot_test_results.md`:
```markdown
| FUN_XXXXXXXX | BOOT | delta before → 0 | notes |
```

Status values:
- **BOOT**: Screenshot comparison passed
- **CRASH**: Black screen detected
- **CORRUPT**: Visual differences from baseline

### Step 6: NEXT FUNCTION
Remove from candidate pool, pick next smallest FAIL function.

## Success Metrics

- Each function that reaches PASS + BOOT gets added to `build/test_include.txt`
- Track: functions attempted, functions matched, functions booting
- Goal: Expand the 48 PASS → 79 BOOT baseline

## Known Challenging Patterns

### Compiler Limitations (from MEMORY.md)
- **Instruction scheduling**: GCC orders instructions differently (constant loads interleaved)
- **Register allocation**: GCC prefers r8-r11 (callee-saved) vs original r4-r7
- **Better optimization**: Our GCC genuinely produces shorter code (immediate AND, etc.)

### Ghidra Decompilation Errors
- **Fall-through functions**: 2-6 instruction prologues that fall into next function
- **Register setup functions**: Set r8/r10 (callee-saved) before tail jump — can't express in C
- **Boundary errors**: Function merged with following code by Ghidra

### Patching Limitations
- **Constant pool overflow**: Original shares pools with neighbors; our code has embedded pools
- **Function size mismatch**: Our code may be larger due to embedded constants

### Identification
- **delta > 0 + tiny expected**: Likely Ghidra boundary error (fall-through)
- **delta = 0**: Scheduling or register allocation
- **delta < 0**: Better optimization — our code is shorter

When hitting these patterns:
1. Document the specific pattern
2. Record as "challenging - [reason]"
3. Move to next function (don't waste time)

## Commands Quick Reference

```bash
# Compile single function
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash -c "cd /mnt/d/Projects/SaturnReverseTest && ./tools/gcc26-build/cc1 -quiet -O2 -m2 -mbsr src/FUN_X.c -o /tmp/test.s"

# Extract opcodes from compiled output
grep -P '^\t[a-z]' /tmp/test.s | sed 's/\t/ /g' | awk '{print $1}'

# Full test harness (all functions)
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash tools/test_harness.sh

# Build patched disc
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash tools/build_disc.sh

# Boot test
powershell -ExecutionPolicy Bypass -File tools\test_boot.ps1 -Cue patched

# Screenshot comparison
python tools/compare_screenshot.py build/screenshots/patched_latest.png build/screenshots/vanilla_latest.png
```

## Progress

### Session 2026-02-05 (continued)

**New findings from C-level matching attempts:**

| Function | Size | Before → After | Status | Root Cause |
|----------|------|----------------|--------|------------|
| FUN_06018EC8 | 7 | delta=0 → delta=-1 | **improved** | Removed volatile, enabled delay slot fill |
| FUN_06005174 | 18 | broken → correct | **improved** | register asm("r5") fixed displacement stores |
| FUN_06011494 | 12 | delta=0 | challenging | Register allocation + indexed addressing |
| FUN_0601209E | 18 | delta=0 | challenging | Fall-through entry pattern |
| FUN_060285E0 | 8 | delta=0 | challenging | Argument evaluation order |
| FUN_0602760C | 9 | delta=0 | challenging | Loop scheduling (cmp placement) |
| FUN_060192CA | 15 | delta=0 | challenging | Fall-through entry pattern |
| FUN_06013E12 | 17 | delta=2 | challenging | Fall-through + tail jump |

**Key technique discovered**: `register int var asm("rN")` can force specific register allocation, fixing broken codegen (FUN_06005174 had mov.w r0,@(2,r0) which was wrong).

---

### Session 2026-02-05 (earlier)

| Function | Size | Delta | Status | Notes |
|----------|------|-------|--------|-------|
| FUN_060359DA | 5 | +1 | challenging | Register setup (r8/r10) before tail jump |
| FUN_060361FC | 6 | +7 | challenging | Fall-through function (6-insn prologue) |
| FUN_06036144 | 2 | +13 | challenging | Fall-through function (2-insn prologue) |
| FUN_06027348 | 7 | 0 | challenging | Instruction scheduling (constant load order) |
| FUN_06018EC8 | 7 | 0 | challenging | RTL combiner removes extu.b; delay slot diff |
| FUN_06042BEE | 7 | -1 | challenging | Better optimization (immediate AND) |
| FUN_06012E62 | 4 | 0 (PASS) | CRASH | Constant pool overflow into next function |

### Key Findings

1. **Most small positive-delta functions are Ghidra boundary errors** — fall-through code merged with following functions
2. **delta=0 functions are scheduling/register differences** — challenging at C level
3. **delta<0 functions are better optimization** — our code is correct but shorter
4. **PASS functions can still CRASH** — constant pool collision with neighbors
5. **BOOT functions don't need to PASS** — 79 functions boot with various match rates (0-100%)

### Patcher Behavior (Corrected)

**DIFF functions CAN be patched** if force-included AND their code fits in the original slot.

The patcher has three code paths:
1. `level == 3`: Byte-perfect match — patch if code+pool fits in slot
2. `level == 2`: Structural match — patch with displacement fixup
3. `else`: L1/DIFF — patch if code+pool fits in slot AND force-included

With `--include-funcs`, DIFF functions that fit in their slots DO get patched:
- **Before fix**: 23 functions (only L2+, no `--include-funcs`)
- **After fix**: 65 functions (23 L2+ plus 42 force-included DIFF that fit)

Functions that don't get patched are those where `code + pool > slot_size`.

### Fixed Issues

- **build_disc.sh** was missing `--include-funcs` flag — now fixed
- With fix, 65 functions patched (vs 23 without)
- Baseline still boots with 65 patched functions

### Recommendations

1. **Focus on FAIL → L2 conversion** — functions need structural match to be patchable
2. **PASS is not enough** — constant pool overflow can still cause CRASH
3. **Patcher needs enhancement** — to patch level 0/1 functions (unsafe patching mode)
4. **Expand L2+ baseline** — find more functions that compile to structural match

---

## Conclusion (Session 2026-02-05)

### What We Achieved
1. **Fixed build_disc.sh** — now uses `--include-funcs test_include.txt`
2. **Discovered patcher limitation** — only L2+ functions get patched
3. **Verified baseline** — 65 functions in list, 23 actually patched, boots fine
4. **Documented challenging patterns** — scheduling, register allocation, better optimization

### Reality Check
- **65 functions** get patched (23 L2+ plus 42 DIFF that fit in slots)
- **~20 functions** in test_include.txt are DIFF but too large for their slots
- **Most FAIL → PASS conversions are challenging** at C level
- **Slot overflow** is the main barrier for remaining functions

### Next Steps Options
1. **Patcher enhancement** — add `--unsafe` mode to patch level 0/1 functions
2. **Deeper compiler work** — more peephole passes for specific patterns
3. **Different goal** — accept 23 patched functions as baseline, focus on understanding game code

### Recommendation
The ASM matching workstream has reached diminishing returns. Consider:
- Documenting the 23 working patches as a milestone
- Pivoting to game code understanding/extraction
- Or enhancing the patcher for unsafe DIFF patching

---

*Created: 2026-02-05*
*Workstream: ASM Matching to Boot*
