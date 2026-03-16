---
function: VBlank sync mechanism (multiple functions)
address: 0x06026CE0 (slSynch), 0x060072E6 (VBlank ISR), 0x060007C0 (ISR dispatch)
explored: 2026-03-16
scenarios_tested: [usa_tt_straight, paused + breakpoint timing]
reachable: true
---

## Goal: Find and patch the VBlank count for 30fps mod

Change the game from 20fps (3 VBlanks/frame) to 30fps (2 VBlanks/frame).

## What We Found

### slSynch function at 0x06026CE0 (Ghidra-verified)

```c
void FUN_06026ce0(void) {
    *(int *)0x060635C4 = 1;       // set semaphore = "I'm waiting"
    int iVar3 = 0;
    do {
        iVar3 = iVar3 + 1;
    } while (*(int *)0x060635C4 == 1);  // spin until ISR clears it
    *(int *)0x0605A010 = iVar3;   // store iteration count (frame time)
}
```

- Semaphore at **0x060635C4**: set to 1 by slSynch, cleared to 0 by VBlank ISR
- Frame time counter at **0x0605A010**: stores spin iterations (26245 at save state)
- The "3" is NOT in this function — it just waits for the ISR to signal

### VBlank ISR chain

1. **VBlank vector** at 0x06000100 → points to **0x06000840**
2. 0x06000840 is a dispatch trampoline: saves r0, branches to shared handler at
   ~0x060008F2 with r0=0x40 (interrupt ID)
3. Shared handler eventually calls **FUN_060072E6** (the actual VBlank handler)

### VBlank handler FUN_060072E6 (Ghidra-verified)

```c
void FUN_060072e6(void) {
    (**(code **)0x06000344)(0xffffffff, (int)DAT_0600735c);  // tick callback
    *(int *)0x06059F40 = *(int *)0x06059F40 + 1;             // increment counter
    *(byte *)DAT_0600735e = *(byte *)DAT_0600735e & 0x87;    // clear VDP2 status bits
    (**(code **)0x06000344)(DAT_06007360, 0);                 // second callback
}
```

- Calls through function pointer at `[0x06000344]` = **0x060007C0** (timer/callback manager)
- Increments a counter at **0x06059F40** (currently 1189912 — total VBlanks since boot)
- Clears VDP2 status bits (0x87 mask)
- The VBlank counting/semaphore logic is NOT directly in this function —
  it's handled by the callback at 0x060007C0

### FUN_060007C0 (timer callback, NOT decompiled by Ghidra)

This is the function called twice per VBlank by FUN_060072E6. It manages a
timer/callback system. The logic that counts VBlanks and clears the semaphore
at 0x060635C4 is likely inside this function. **Not yet traced.**

## What We Tested (FAILED)

### False positive: mov #3 at 0x060073EC

Found `mov #3, r2` at 0x060073EC followed by `mov.l r2, @r3` storing to
**0x0605A008**. Thought this was the VBlank count reset.

**Poked**: `E2 03` → `E2 02` at 0x060073EC (change 3 to 2).

**Result**: No effect. Measured frame timing with breakpoint at FUN_060092D0:
- Baseline (no poke): 1,436,176 cycles between game loop iterations = 3 VBlanks
- With poke: 1,436,176 cycles = still 3 VBlanks (identical)

**Conclusion**: 0x0605A008 is not the VBlank frame count. The value 3 stored
there serves a different purpose (possibly a state counter).

### Baseline timing confirmed

| Measurement | Value |
|-------------|-------|
| Cycles between game loops (baseline) | 1,436,176 |
| Expected 3 VBlanks at 28.6MHz | 1,431,818 |
| Difference | +4,358 (0.3%) |
| Game FPS | 20.0 fps (confirmed) |
| Target 2 VBlanks | ~954,545 cycles |

## Where to Look Next

The VBlank count is managed by **FUN_060007C0** (the timer callback at
`[0x06000344]`). This function:
- Is called twice per VBlank from FUN_060072E6
- First call: args (-1, value) — probably "tick all timers"
- Second call: args (0xFF7C, 0) — probably "set up next cycle"

The function is ~60 bytes starting at 0x060007C0. No Ghidra decompilation
available (address falls inside _start section). Manual disassembly needed.

**Key question**: Where in FUN_060007C0 does it:
1. Decrement a counter
2. Compare against a target (3)
3. Clear the semaphore at 0x060635C4 when counter reaches 0
4. Reset the counter to 3

The constant "3" might be:
- A `mov #3, rN` instruction inside FUN_060007C0
- Stored at a global variable read by FUN_060007C0
- Passed as an argument during initialization (not per-VBlank)

**Alternative approach**: Set a write watchpoint on 0x060635C4 and catch the
exact PC that clears the semaphore. That PC is inside the countdown logic,
and the "3" will be nearby.

## Other mov #3 locations near semaphore references

These were also found but not tested:
- 0x06006FC0: `mov #3, r3` (near 0x06006FE8 semaphore ref)
- 0x06038FC8: `mov #3, r3` (near 0x06038F54 semaphore ref)

These may also be false positives, but worth checking if FUN_060007C0
doesn't pan out.
