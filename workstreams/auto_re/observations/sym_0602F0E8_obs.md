---
function: sym_0602F0E8
address: 0x0602F0E8
address_end: 0x0602F178
source_file: reimpl/src/FUN_0602EFF0.s (line 163+)
explored: 2026-03-15
scenarios_tested: [straight_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 6 in FUN_0602EEB8 |

## Computation

### Normal Path (no collision — car[+0xB8] == 0 AND car[+0x1BC] == 0)

```
car[+0xD0] = (car[+0xB0] << 8 + car[+0xD0]) >> 1   // EMA of rotation
car[+0x84] = car[+0x94]                              // copy state
car[+0x68] = car[+0x78]                              // copy state
```

The +0xD0 update is an exponential moving average: the new value of +0xB0
(from FUN_0602EFF0's atan2 output) is blended with the old +0xD0 value.
The <<8 scaling and >>1 averaging produce a smoothed rotation signal.

The state copies (+0x94→+0x84, +0x78→+0x68) transfer "current" values
to "previous" slots each frame. This matches the struct map's "state
transfer group" hypothesis.

### Collision Path (car[+0xB8] != 0 OR car[+0x1BC] != 0)

```
car[+0x166] = 0       // clear effect timer (16-bit)
car[+0x90] = 0x38     // set collision recovery param
car[+0x74] = 0x38     // set collision recovery param
car[+0xD0] += 0x071C  // OR -= 0x071C (adjust rotation toward zero)
    // clamp: if result crosses zero, set to 0
```

The collision path resets the effect timer and sets two recovery parameters
to 0x38 (56 decimal). It also adjusts +0xD0 by ±0x071C (1820) toward zero,
clamping at zero — this smoothly reduces the rotation signal during collision.

## Field Access Summary

### Reads

| Offset | Notes |
|--------|-------|
| +0xB0 | Rotation from FUN_0602EFF0 (steering atan2 output). Scaled and blended |
| +0xD0 | Previous smoothed rotation. Updated with EMA |
| +0xB8 | Collision/gear flag. Nonzero = collision active |
| +0x1BC | Secondary collision flag. Nonzero = collision |
| +0x94 | Current state value (copied to +0x84 in normal path) |
| +0x78 | Current state value (copied to +0x68 in normal path) |

### Writes

| Offset | Path | Notes |
|--------|------|-------|
| +0xD0 | both | EMA update (normal) or ±0x071C adjust (collision) |
| +0x84 | normal | = car[+0x94] |
| +0x68 | normal | = car[+0x78] (RTS delay slot) |
| +0x166 | collision | Cleared to 0 (16-bit) |
| +0x90 | collision | Set to 0x38 |
| +0x74 | collision | Set to 0x38 |

## Other Observations

- The two gate flags (+0xB8 and +0x1BC) are checked sequentially. BOTH
  must be zero for the normal path. If either is nonzero, the collision
  path runs. This is a logical OR gate.
- The collision recovery parameters (0x38 = 56) match the initial values
  seen in the struct map for +0x78 (init=56) and the struct map hypothesis
  for +0x90 ("collision_recovery_param, set to 0x38 on collision").
- +0x68 is written in the RTS delay slot (line 190-191), consistent with
  the profiler PC artifact pattern seen throughout the pipeline.
