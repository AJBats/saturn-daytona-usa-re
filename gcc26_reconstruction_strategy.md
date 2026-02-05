# GCC 2.6 Compiler Reconstruction Strategy

## Context

This document captures findings from a side investigation into whether we can build GCC 2.6 from source and reconstruct the Saturn-specific patches, rather than relying solely on the preserved cygnus-2.7-96Q3 compiler (which cannot byte-match due to register allocation order differences).

---

## The Proposal

Build vanilla GCC 2.6 from source targeting SH-2, compile test functions, compare the assembly output against the Daytona binary, and use the differences to reverse-engineer what the Saturn-specific patches likely changed. Iteratively patch the 2.6 source until the output converges on the original binary's codegen patterns.

---

## Why This Is Feasible

### The Biggest Blocker Is Already Solved by Using 2.6

The documented reason 2.7 can't byte-match is register allocation order:

```
Daytona binary (GCC 2.6):          96Q3 output (GCC 2.7):
  mov.l  r14,@-r15  ; descending    mov.l  r8,@-r15   ; ascending
  mov.l  r13,@-r15                   mov.l  r9,@-r15
  mov.l  r12,@-r15                   mov.l  r10,@-r15
  sts.l  pr,@-r15                    mov.l  r14,@-r15
                                     sts.l  pr,@-r15
```

This is a GCC version-level difference, not a patch. Vanilla GCC 2.6 already produces descending register saves. Every non-leaf function in the binary is affected by this — switching to 2.6 fixes them all for free.

### The SH-2 Backend Is Small and Readable

The SH-2 target in GCC 2.6 is defined in `sh.c`, `sh.h`, and `sh.md` (machine description). This is a few thousand lines total — manageable for full human or AI review. The space of "things that could differ" is bounded.

### Existing Build Infrastructure

[decompals/old-gcc](https://github.com/decompals/old-gcc) already builds GCC 2.6.3 from source on modern systems. The hard work of getting a 30-year-old compiler to build is done.

### 1,234 Functions of Ground Truth

The Daytona binary contains ~1,234 identified functions. That's an enormous corpus for calibrating compiler output. Unlike guessing at patches in the abstract, every codegen pattern can be directly compared.

---

## The Layer Cake: What's Actually Missing

The original compiler isn't just "GCC 2.6 + Saturn patches." There are three layers:

```
Layer 1:  FSF GCC 2.6.0           (source available at gnu.org and decompals/old-gcc)
Layer 2:  Cygnus quarterly patches (95q1 snapshot — not preserved as source)
Layer 3:  SOA patches              (Toshiyasu Morita's Saturn-specific fixes — not preserved)
```

Both layers 2 and 3 are missing. However:

- **Cygnus was contributing upstream to FSF GCC.** Many of their fixes landed in point releases (2.6.1, 2.6.2, 2.6.3). The diff between FSF 2.6.3 and a Cygnus 2.6 snapshot from the same period may be small, especially for the SH backend which was a smaller target.

- **SOA patches were likely incremental fixes.** The changelog shows SOA releases every 1-2 weeks (Feb 1, Feb 8, Feb 15, Mar 17...). That cadence suggests bug fixes and minor tweaks, not fundamental codegen changes. Plausible patch scope:
  - SH-2 instruction correctness fixes
  - Delay slot filling improvements
  - Addressing mode preferences for Saturn memory map
  - libgcc tweaks (division routines, etc.)
  - Workarounds for SH7604 silicon errata

---

## Correction: The Compiler Version Is Less Certain Than the Doc Implies

The main decomp doc states that `cygnus-2.6-95q1-SOA-950317` "matches Daytona build date" (March 17, 1995). This is a date coincidence, not a compiler identification.

### What is confirmed
- It's GCC, not Hitachi SHC (prologue analysis is unambiguous)
- It's GCC 2.6 era, not 2.7 (register allocation order proves this)
- GCC 2.6 was the current SOA toolchain in early 1995

### What is NOT confirmed
- **The specific distribution.** The SOA changelog documents releases to third-party North American developers. AM2 was Sega's internal arcade division in Japan. They may have received compilers through a different channel, used a Japanese-maintained distribution, had a direct Cygnus relationship, or used stock Cygnus releases without SOA patches at all.
- **The specific date.** No team adopts a compiler release the same day they do a final build. If anything, the date match argues against `SOA-950317` being the exact compiler — AM2 would have been using whatever they'd been developing with for weeks or months prior (`SOA-950215`, `SOA-950208`, or the earlier `941014` base).
- **Whether the IP.BIN build date (1995-03-17) is even the APROG.BIN compilation date.** It could be a disc mastering date or a manually-set version stamp.

### Corrected assessment

```
Confirmed:     GCC 2.6.x for SH-2
Likely:        Cygnus distribution (they were the dominant SH-2 GCC maintainer)
Plausible:     95q1 base (timeline fits) or 941014 base (earlier, more stable)
Speculative:   SOA-950317 specifically (date coincidence, wrong organization)
Unknown:       Whether AM2 used SOA patches, stock Cygnus, or something else entirely
```

This uncertainty actually strengthens the case for building from source — even if someone found `SOA-950317` binaries, that might not be the right compiler. Converging on actual codegen behavior is more reliable than guessing which distribution label to hunt for.

---

## Per-Subproblem Confidence Assessment

| Subproblem | Confidence | Reasoning |
|---|---|---|
| **Register allocation order** | ~100% | GCC version-level. Vanilla 2.6 already correct. |
| **Prologue/epilogue structure** | ~95% | Directly controlled by target macros in `sh.c`. Differences visible immediately, fix is mechanical. |
| **Delay slot filling** | ~90% | Controlled by reorg pass + `.md` attributes. Systematic comparison across all 1,234 functions reveals any pattern differences. |
| **Instruction selection / addressing modes** | ~85% | `.md` pattern entries. Differences show as "same operation, different encoding." Catalog all instances, write the `.md` entry. |
| **Instruction scheduling** | ~75% | Harder — subtle reorderings from pipeline cost model tuning. But 1,234 functions of examples is enough data to fit the cost model empirically. |
| **Constant pool placement** | ~65% | Hardest subproblem. Pool placement depends on distance thresholds, alignment, branch target interaction. Small changes cascade. Deterministic algorithm with readable parameters, but most moving pieces. |
| **Cygnus middle layer** | ~70% | Unknown delta between FSF 2.6.3 and Cygnus snapshot. Cygnus contributed upstream, SH was a smaller target. Probably no major surprises, but can't rule it out. |

---

## Expected Outcomes

| Goal | Probability | Description |
|---|---|---|
| **Practical decomp utility** | 90%+ | Output close enough for reliable C-to-asm comparison and decompiled function validation. Major upgrade over 2.7. |
| **Byte-match majority of functions** | 65-75% | >80% of 1,234 functions match byte-for-byte. Prologue/epilogue and instruction selection are high-confidence; scheduling and constant pool are wildcards. |
| **100% byte-match** | 25-35% | Likely at least one obscure edge case that's hard to reverse-engineer from output alone. |

Even the low-end outcome (90%+ practical utility) is a massive improvement over the current situation where 2.7's register ordering makes every function comparison noisy.

---

## Recommended Approach

### Phase A: Baseline Build
1. Use decompals/old-gcc to build GCC 2.6.3 for `sh-hms` target
2. Also build GCC 2.6.0 if straightforward — the Cygnus base was tagged `cygnus-2.6.0-941014`, so 2.6.0 might be closer than 2.6.3
3. Compare both against the binary to determine which baseline is closer

### Phase B: Systematic Comparison
1. Write test functions exercising every codegen pattern visible in the Daytona binary: prologue shapes, switch tables, loop constructs, struct access, calling conventions, arithmetic operations, leaf vs non-leaf functions
2. Compile with vanilla 2.6, compare all output systematically
3. Catalog every difference by category (prologue, scheduling, instruction selection, constant pool, etc.)

### Phase C: Targeted Patching
1. For each difference category, read the relevant GCC source (`.md` patterns, `sh.c` target hooks, reorg pass, etc.)
2. Identify the controlling code, write a patch
3. Recompile test suite, verify the category is fixed, check for regressions
4. Iterate

### Phase D: Full Binary Validation
1. Start comparing against actual Daytona functions — all 1,234, not samples
2. Any new difference patterns get the same Phase C treatment
3. Converge until differences reach zero or a characterized residual set

### Phase E: Integration
1. Once the reconstructed compiler is stable, swap it into the build pipeline alongside or replacing 96Q3
2. Re-evaluate whether matching decomp is now viable for some or all functions
3. If matching becomes feasible, it provides automated verification that the non-matching decomp was already getting right

---

## Relationship to Main Project Phases

This work is **independent of and parallel to** the main decomp phases. The current build pipeline uses sh-elf-binutils for assembling raw bytes back to a binary — no compiler involved yet. The compiler only becomes necessary when replacing assembly with C (Phase 2 progressive replacement onward).

Building the 2.6 compiler now means it's ready when the first C replacement is attempted. If reconstruction goes well enough, it could upgrade the project from non-matching to partially or fully matching — which would provide automated binary-diff verification for every decompiled function.

Even if reconstruction stalls at "good enough for comparison but not byte-matching," it's still a better tool than 2.7 for eyeball-comparing decompiled C output against the original binary.

---

## Progress (as of Session 14)

### Phase A: Complete
- GCC 2.6.3 SH-2 backend builds from source (gcc26-build/)
- 22 patches applied to sh.c, sh.h, sh.md, toplev.c
- dt, bsr, tail call, pure wrapper, displacement load/store, sign ext, return dedup, delay slot sign ext, swap.w, add-to-shll, indexed addressing, delay slot control flags, multiply cost, dt combining, redundant exts.w elimination, lds.l reordering, delay slot unfill flags

### Phase B: Complete
- 133 test functions with .c source and .expected opcodes
- Automated tooling: gen_expected.py, gen_test_skeleton.py, test_harness.sh
- Per-function compiler flags (.flags files) for fine-grained control
- **Result: 38 PASS / 95 FAIL (28% pass rate)**

### Phase C: Largely Complete (diminishing returns)
- 22 patches implemented, all low-hanging peepholes exhausted
- Remaining failures are deep compiler internals (register allocation, instruction scheduling, loop optimization)
- All delta>0 functions analyzed: none fixable from C source alone
- All delta=+1 functions (7): callee-save strategy, byte extraction, loop structure — challenging
- Unfilled rts delay slots: Patch 21 (lds.l reordering) enables filling for CALL functions; 14 remain challenging (loop-exit, shared labels, complex control flow)
- Delta=-1 analysis: 27 functions where our code is shorter; 3 fixed via Patch 22 (delay slot unfill flags)

### Phase D: In Progress
- 133 functions tested against binary (from 1234 total in binary)
- Test expansion exhausted: remaining 1424 untested .expected files are fall-through prologues, indirect calls (jsr @r0/r12), or non-standard calling conventions
- To expand further: need Ghidra re-export of ~40 missing game state handlers

### Phase E: Not Started
- Full binary build system (linker script + stubs) not yet implemented
- Pool constant sharing between adjacent functions remains unaddressed

### Key Findings
1. **Register allocation order**: Confirmed GCC 2.6.3 uses descending order matching original — this was the right version choice
2. **Post-reload scheduling**: Has NO effect on output (both schedulers effectively disabled in SH backend)
3. **Optimization ceiling**: 28% exact match (38/133). 44 functions have our code SHORTER than original (better optimization). Only 24 are longer.
4. **Challenging diffs**: Register allocation internal decisions, loop entry strategy (mid vs bottom-test), delay slot filling aggressiveness, lds.l placement blocking rts delay slots
5. **C source quality matters**: Correct types (int vs short), literal constants vs externs, operator precedence, and struct access patterns each affect codegen significantly
