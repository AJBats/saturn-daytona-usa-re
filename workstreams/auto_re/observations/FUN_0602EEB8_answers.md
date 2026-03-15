## Answers to Verifier Questions

### 1. Breakpoint double-hit at FUN_0602EEB8

Acknowledged. The double-hit is a Mednafen breakpoint implementation detail.
No further investigation needed.

### 2. car[+0x252] watchpoint gets 0 hits

**Root cause: 16-bit write (`mov.w`), not caught by 4-byte watchpoint.**

The instruction at PC 0x0602EED4 is `mov.w R2, @(R0,R1)` (opcode 0x0125),
a 16-bit word write. The watchpoint tool description says "Watch for 4-byte
writes to address" — it only triggers on `mov.l` (32-bit) writes. The 16-bit
`mov.w` silently bypasses the watchpoint.

**Verified by disassembly at 0x0602EEC6:**
```
0x0602EECE: mov.w @(PC+0x28), R1   ; R1 = 0x0250 (from pool at 0x0602EEFA)
0x0602EED0: mov.w @(R0,R1), R2     ; R2 = car[+0x250] (16-bit read)
0x0602EED2: add #2, R1             ; R1 = 0x0252
0x0602EED4: mov.w R2, @(R0,R1)     ; car[+0x252] = R2 (16-bit write) ← THIS
```

The value written to +0x252 is a **copy of car[+0x250]** (drift counter).
Both are 16-bit fields. The struct map lists +0x252 values as 0-9 and +0x250
values as 0-10 (0xA) — consistent with +0x252 being a lagged copy of +0x250.

Note: the writer map PC 0x0602EED8 (which is `jsr @r13`) is another profiler
PC offset artifact — the actual write instruction is at 0x0602EED4, 4 bytes
earlier. Same pattern as the +0xFC profiler quirk.

**Implication for oracle**: Any claim using `writes_to` on 16-bit fields will
get 0 hits from the watchpoint system. The oracle should note this limitation.
Fields +0x152, +0x166, +0xD6, +0xDC, and others documented as 16-bit in the
struct map will have the same issue.
