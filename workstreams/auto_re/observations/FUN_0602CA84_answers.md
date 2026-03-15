## Answers to Verifier Questions

### Watchpoint system does not catch writes to +0xC0, +0x108, +0x148

**Root cause: Systemic watchpoint limitation for `mov.l Rm, @(R0, Rn)` addressing mode.**

Tested:
1. Set watchpoint on 0x060789C0 (car[+0xC0]), ran 10 frames in race_throttle
   (daytona_rebuilt, ~179 mph). **0 hits.**
2. Verified the write instruction: at PC 0x0602CB38, `mov.l R10, @(R0, R1)`
   where R0=car_pointer, R1=0x0108. This is a normal 32-bit `mov.l` instruction,
   NOT in a delay slot. Address = 0x06078900 + 0x0108 = 0x06078A08.

The write is a standard `mov.l` (32-bit) using the `@(R0, Rn)` indexed addressing
mode. The watchpoint system does not catch these writes. This is NOT a write-size
issue (like +0x252 which uses `mov.w`).

**Affected addressing mode**: `mov.l Rm, @(R0, Rn)` — the SH-2 indexed store
where the effective address is R0 + Rn. This is the most common write mode in
the player physics pipeline because R0 = car pointer and Rn = field offset.

**Profiler PC artifact (also present)**: The writer map PCs are all +4 from the
actual write instruction. Disassembly at the recorded PCs shows load instructions
(mov.w, mov.l from pool), not stores:

| Field | Writer Map PC | Instruction at PC | Actual Write PC | Actual Instruction |
|-------|--------------|-------------------|-----------------|-------------------|
| +0xC0 | 0x0602CC46 | `mov.l @r15+, r5` | ~0x0602CC42 | `mov.l r7, @(r0, r2)` in RTS delay |
| +0x108 | 0x0602CB3C | `mov.w @(PC), r1` | 0x0602CB38 | `mov.l r10, @(r0, r1)` |
| +0x148 | 0x0602CAE0 | `mov.w @(PC), r2` | ~0x0602CADC | `mov.l r6, @(r0, r2)` (TBD) |

The +4 offset in all cases suggests the mem_profile tool records the PC of the
instruction 2 slots AFTER the write (possibly due to SH-2 pipeline stages where
the write commits after the next instruction fetches).

**Recommendation for oracle**: `writes_to` claims using watchpoints are unreliable
for the player physics pipeline. The `mov.l Rm, @(R0, Rn)` addressing mode is
used for virtually ALL car struct writes. Consider:
1. Using mem_profile instead of watchpoints for writes_to verification
2. Accepting per-frame CSV value changes as writes_to evidence
3. Documenting this as a known oracle limitation
