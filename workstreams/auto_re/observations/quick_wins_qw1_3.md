---
function: N/A (quick wins QW1-QW3)
explored: 2026-03-17
scenarios_tested: [race_start_state]
reachable: N/A
---

## QW1: AI-Exclusive Data Tables

### 0x060477EC — AI Speed Table 1 (FUN_0600C4F8)

128 bytes = 32 entries × 4 bytes. Values are large 32-bit constants
(0x0BD52BD3 to 0x0F69E50B), monotonically increasing. These are
speed-to-force conversion factors for 32 AI speed levels.

```
0BD52BD3 0BD52BD3 0BFCE38E 0C249B4A
0C249B4A 0C4C4BFB 0C73EF27 0C9B8831
0C9B8831 0CC31055 0CEA8793 0D11E381
0D392780 0D392780 0D604D14 0D875096
0DAE324D 0DD4EB2F 0DFB7B3D 0E21DBB2
0E480930 0E480930 0E480930 0E6DEF6F
0E93844D 0EB8AC2F 0EDD5D3C 0F017F83
0F017F83 0F250268 0F47D7D5 0F69E50B
```

### 0x060454CC — AI Speed Table 2 (FUN_0600C4F8)

128 bytes = 32 entries × 4 bytes. Values start at 0x00100000 (1,048,576)
and increase to 0x0014897C. Monotonically increasing — likely speed
thresholds or acceleration curve control points.

### 0x060453B4 — Collision Speed 1

32 bytes. Contains POINTERS (0x0604538C, 0x0604539C, 0x060453AC) and
small integers. This is a table-of-tables structure, not raw values.

### 0x060453C4 — Collision Speed 2

Overlaps with the gear shift table below. Contains pointer 0x060453AC
then byte-sized values forming an S-curve pattern.

### 0x060453CC — Gear Shift Steering Kick S-curve

128 bytes of byte-sized values forming a smooth S-curve from 0x00 to 0xFF
and back. This is likely a steering kick table indexed by frame offset
during a gear shift animation. 33 entries each way (up-curve and
down-curve), total ~66 entries used.

Pattern: 00 00 00 9E 02 76 05 83 09 BF 0F 1E 15 93 1D 0E
(ascending sine-like curve from 0 to ~255, then descending)

## QW2: FUN_0600D26A Identification

64 bytes disassembled. The function:
- Reads from 0x0607E940 (current car pointer) and 0x0607E944 (player car)
- Uses pool constants with offsets suggesting car struct field access
- Short function (~30 instructions) called once per AI car
- Contains a loop (`8B F8` = bf loop_back) iterating over something

**Hypothesis**: Per-car distance or position update function. Reads
current car pointer and player pointer, likely computes relative
position or distance for AI behavior. The loop suggests iterating
over nearby cars or track segments.

## QW3: sym_0607EA9C Value

**Value: 0x00000061 (97 decimal)**

This is read by the AI pipeline as a segment distance limit. Value 97
suggests it represents a track segment count or distance threshold.
Three Seven Speedway has ~93 track segments (from +0x1E4 observations
showing values 5-93), so 97 may be the total segment count + margin.

Static during the save state — needs verification whether it changes
during racing (e.g., different tracks would have different segment counts).
