---
function: sym_0602FDA4
address: 0x0602FDA4
address_end: ~0x060300B0
source_file: reimpl/src/FUN_0602F9A6.s (line 614, prologue) + reimpl/src/FUN_0602FDB0.s (body)
explored: 2026-03-15
scenarios_tested: [straight_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 1 in FUN_0602EEB8 — FIRST call in pipeline |

## KEY FINDING: This Function Reads Controller Input

**sym_0602FDA4 / FUN_0602FDB0 is the THROTTLE/GEAR INPUT HANDLER.**

It reads `sym_06063D9A` (g_pad_state + 2, the button state word) and writes
car struct fields based on which buttons are pressed. This is the missing link
in the throttle→speed pipeline.

## Controller Input Reading

```
r1 = *(sym_06063D9A)           // read pad state (16-bit button word)
r2 = *(sym_0608188A)           // read state flag

// Test button bits against multiple button mapping tables:
// sym_0608188A, sym_06081888, sym_06081896, sym_06081894, sym_06081892
// Each table entry maps a button bit to a car[+0xDE] value

if (r2 > 0):                  // positive state
    if (r1 & *(sym_0608188A)):
        car[+0xDE] -= 1 (if > 0)  // decrement toward 0
    elif (r1 & *(sym_06081888)):
        car[+0xDE] += 1 (max 3)   // increment toward 3
else:                              // negative state (different buttons)
    if (r1 & *(sym_06081896)):  car[+0xDE] = 3
    elif (r1 & *(sym_06081894)): car[+0xDE] = 2
    elif (r1 & *(sym_06081892)): car[+0xDE] = 1
    else if (another button):    car[+0xDE] = 0
```

## Field Access (Partial — First 60 Lines of Body)

### Reads

| Source | Notes |
|--------|-------|
| sym_0607E944 | Player car pointer |
| sym_0607ED8C | State flag (16-bit). Nonzero = alternate path |
| sym_06063D9A | **g_pad_state + 2** — controller button word |
| sym_0608188A | Button mapping table entry 1 |
| sym_06081888 | Button mapping table entry 2 |
| sym_06081896 | Button mapping table entry 3 |
| sym_06081894 | Button mapping table entry 4 |
| sym_06081892 | Button mapping table entry 5 |

### Writes

| Offset | Notes |
|--------|-------|
| +0xDE | Button/gear state (16-bit). Set to 0, 1, 2, or 3 based on input |

## Throttle Pipeline (Updated)

```
C button (bit in g_pad_state+2, read at sym_06063D9A)
    ↓ sym_0602FDA4/FUN_0602FDB0 (pipeline call 1)
    ↓ tests button bits against sym_0608188x mapping tables
car[+0xDE] (button state: 0, 1, 2, or 3)
    ↓ [downstream pipeline stages read +0xDE]
    ↓ ... → force accumulation → accel delta
car[+0xFC] (accel delta, CONFIRMED)
    ↓ sym_0602D814 (pipeline call 18)
car[+0x0C] (speed, CONFIRMED)
```

The gap between g_pad_state and the force accumulator is partially filled:
the input handler writes car[+0xDE]. The remaining gap is how +0xDE feeds
into the force computation. +0xDE may be read by one of the pipeline stages
(calls 2-15) that produces the force terms (+0x108, +0x10C, +0x110).

## Observations

- The function body (FUN_0602FDB0) falls through from the prologue (sym_0602FDA4),
  which is the fall-through prologue pattern documented in `.claude/rules`.
- The button mapping tables at sym_0608188x are 16-bit masks that identify
  specific buttons. Reading these tables would reveal which bit corresponds
  to C (throttle), B (brake), etc.
- The function is much larger than shown here (~300+ instructions). The full
  body continues past the initial button handling into additional state setup.
  Full observation deferred to a future cycle.
- car[+0xDE] values 0-3 may represent: 0=no throttle, 1=partial, 2=more,
  3=full throttle. Or they may represent gear positions in manual mode.

## Per-Frame Field Analysis

| Offset | Idle | Throttle | Category |
|--------|------|----------|----------|
| +0xDE | Not in CSV (16-bit sub-field of +0xDC word) | N/A | Needs investigation |

car[+0xDE] is a 16-bit field at offset 0xDE. The CSV captures 32-bit values
at 4-byte aligned offsets. +0xDE falls within the +0xDC word's upper 16 bits.
Check: the +0xDC column in CSVs may contain +0xDE in its upper half.
