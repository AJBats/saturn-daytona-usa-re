---
function: sym_0602F7BC
address: 0x0602F7BC
address_end: 0x0602F7E2
source_file: reimpl/src/FUN_0602F5B6.s (line 326+)
explored: 2026-03-15
scenarios_tested: [straight_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 5 in FUN_0602EEB8 |

## Computation (Complete — 12 instructions)

Three independent countdown timers, each decremented by 1 per frame if nonzero:

```
if car[+0x166] > 0: car[+0x166] -= 1    // 16-bit (mov.w)
if car[+0x152] > 0: car[+0x152] -= 1    // 16-bit (mov.w)
if car[+0x208] > 0: car[+0x208] -= 1    // 32-bit (mov.l)
```

### Timer Sources (from struct map)

| Offset | Size | Set by | Set value | Role hypothesis |
|--------|------|--------|-----------|----------------|
| +0x166 | 16-bit | sym_0602D814 (speed writer) | 7 or 10 | Speed-related timer, reset on collision by sym_0602F0E8 |
| +0x152 | 16-bit | FUN_0602CCF0 (drift detect) | 10 (0xA) | Drift mode timer, set when drift detected |
| +0x208 | 32-bit | FUN_060305E0 | 8 | Unknown trigger, rare (6 writes in comprehensive map) |

All three are simple frame-based countdowns. No computation, no reads
of other fields, no branching beyond the zero check.

## Other Observations

- +0x166 and +0x152 use `mov.w` (16-bit read/write). The watchpoint system
  will NOT catch these writes (same limitation as +0x252).
- +0x208 uses `mov.l` (32-bit) but the watchpoint may still miss it due to
  the `mov.l Rm, @(R0, Rn)` addressing mode limitation.
- This is the simplest function in the player physics pipeline — pure
  timer maintenance with no physics computation.
