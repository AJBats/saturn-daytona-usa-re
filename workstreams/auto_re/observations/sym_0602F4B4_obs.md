---
function: sym_0602F4B4
address: 0x0602F4B4
address_end: ~0x0602F5B6
source_file: reimpl/src/FUN_0602F270.s (line 357+)
explored: 2026-03-15
scenarios_tested: [straight_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 10 in FUN_0602EEB8 |

## Computation (from Static Analysis)

Opponent proximity detection — checks distance and angle to all other cars.

```
if *sym_0607EAE0 != 0: return    // optimization gate (nonzero = skip)

if car[+0xD6] > 0:               // proximity counter active
    car[+0xD6] -= 1              // decrement (16-bit)

car_count = *sym_0607EA98        // total car count
car_array = *sym_0607E948        // car array base

for each opponent car:
    dx = abs(car[+0x10] - opponent[+0x10])   // X distance
    dz = abs(car[+0x18] - opponent[+0x18])   // Z distance
    dist = max(dx, dz) + min(dx, dz) / 2    // Manhattan-ish approximation

    if dist < threshold:                      // ~0x1E0000 from static analysis
        // check heading angle within ±0x071C
        if within angle:
            car[+0xD6] = 0x14                // set proximity counter to 20
            return                            // early exit on first match
```

## Field Access

### Reads

| Offset | Notes |
|--------|-------|
| +0xD6 | Proximity counter (16-bit). Decremented if > 0 |
| +0x10 | Position X (player car — for distance computation) |
| +0x18 | Position Z (player car) |
| +0x28 | Heading (for angle check against opponent direction) |

### Writes

| Offset | Notes |
|--------|-------|
| +0xD6 | Set to 0x14 (20) on opponent detection. 16-bit write (mov.w) |

### Globals Read

| Address | Notes |
|---------|-------|
| sym_0607EAE0 | Optimization gate (skip if nonzero) |
| sym_0607EA98 | Car count |
| sym_0607E948 | Car array base pointer |

## Per-Frame Field Analysis

| Offset | Idle | Throttle | Category |
|--------|------|----------|----------|
| +0xD6 | Not in 32-bit CSV | N/A | 16-bit field within +0xD4 word |

car[+0xD6] is a 16-bit field. In time trial (no opponents), the proximity
counter is never set — it stays at 0 or decrements from a prior value.
To observe detection behavior, the race save state (40 cars) would be needed.

## Other Observations

- The distance approximation `max(dx,dz) + min(dx,dz)/2` is a fast
  Manhattan-like metric that avoids square root. It's ~12% larger than
  Euclidean distance in the worst case (45° angle).
- The function uses sym_0607EAE0 as a gate — this global may be set
  during certain game states (menu, pause) to skip proximity checks.
- In time trial mode, this function runs but the car count loop has
  zero iterations (only player car exists), so it returns quickly.
