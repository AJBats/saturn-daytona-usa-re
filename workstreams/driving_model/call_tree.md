# Driving Model Call Tree

Source: Ghidra MCP decompilation of daytona_data.iso (2026-03-04)

## Frame-Level Entry Points

```
FUN_0600c010 (FUN_0600C010) — per-frame racing orchestrator
  ├─ FUN_060058fa
  ├─ FUN_0601bdec
  ├─ FUN_0602e610
  ├─ FUN_06006868
  ├─ FUN_0600d31c
  ├─ FUN_06027630
  ├─ FUN_0600b6a0  — per-car update loop (primary CPU)
  ├─ FUN_0603c000
  ├─ FUN_06034708
  └─ FUN_0600d336
```

## Car Iteration Loop

```
FUN_0600e0c0 (FUN_0600E0C0) — iterates cars 1..car_count
  │
  │  for (i = 1; i < car_count; i++):
  │    car_ptr = base + i * 0x268
  │    sym_0607E940 = car_ptr  (current car pointer global)
  │
  ├─ if (sym_0607EBC4 & 0x8000 == 0):   ← GLOBAL mode flag, NOT per-car
  │    FUN_0600e71a  ← "normal mode" physics pipeline (ALL cars 1..N take this path)
  │    if (car[+0x01] & 0x80):
  │      extra processing (4 indirect calls + 1 return)
  │
  └─ else:
       FUN_0600e906  ← "AI mode" physics pipeline (ALL cars take this path)

  NOTE: The branch is on a GLOBAL flag (sym_0607EBC4), not per-car flags.
  In normal racing, ALL cars go through the same pipeline. The "player" vs "AI"
  distinction is at the game mode level, not per-car. Individual functions inside
  the pipeline (e.g. FUN_0600c4f8) also check this same global flag to decide
  whether to run player-specific logic like throttle response.

  Car 0 is skipped by the loop (i starts at 1). Car 0 = PLAYER (confirmed
  via HUD speed correlation, ratio 1,467). Player has its own physics path
  rooted at ~0x0602EF00 → FUN_0602D814. NOT a dummy object.
```

## "Normal Mode" Physics Pipeline (FUN_0600e71a)

```
FUN_0600e71a — car physics pipeline (runs for cars 1..N when sym_0607EBC4 bit 15 clear)
NOTE: Despite the name, this does NOT process the player (car 0).
Car 0 has its own path at ~0x0602EF00 → FUN_0602D814.
  │
  ├─ [1] FUN_0600d266  — empty (NOP function, no-op)
  ├─ [2] FUN_0600c4f8  — calls FUN_06027552 (06027552)
  ├─ [3] FUN_0600c5d6  — CORE steering/forces/collision
  │       ├─ FUN_0600cd40  — track position query → FUN_0602744c
  │       ├─ FUN_0600ca96  — friction/drag (leaf)
  │       ├─ FUN_0600cf58  — collision dispatch
  │       │    ├─ FUN_0600d12c
  │       │    ├─ FUN_06035168
  │       │    ├─ FUN_0600d210
  │       │    └─ FUN_0600d0b8
  │       ├─ FUN_0600cc38  — force application (leaf)
  │       ├─ FUN_0600c8cc  — speed calc (leaf)
  │       ├─ FUN_0600c928  — heading correction (leaf)
  │       ├─ FUN_0600c7d4  — heading/speed damping (leaf)
  │       ├─ FUN_06006838  — atan2
  │       ├─ FUN_06027ede  — vector rotation
  │       └─ FUN_06027358  — sin/cos application
  ├─ [4] FUN_0600ceba  — track segment advance → FUN_06035228
  ├─ [5] FUN_06008318  — → FUN_06034f78
  └─ [6] FUN_06008640  — → FUN_060086c0, FUN_06008730
  │
  └─ velocity integration:
       car[+0x1C0] = car[+0x1F4] * scale + car[+0x1B8]
       (offsets approximate — from Ghidra PTR_DAT indirection)
```

## AI Physics Pipeline (FUN_0600e906)

```
FUN_0600e906 — AI physics orchestrator
  │
  ├─ FUN_0600d266  — empty (shared with player)
  ├─ FUN_06027552  — FUN_06027552 (shared)
  ├─ FUN_0600c74e  — AI core (equivalent of player's c5d6)
  │    ├─ FUN_0600c970  — AI-SPECIFIC (no player equivalent)
  │    ├─ FUN_0600cd40  — track position query (shared)
  │    ├─ FUN_06006838  — atan2 (shared)
  │    ├─ FUN_06027ede  — vector rotation (shared)
  │    ├─ FUN_0600c928  — heading correction (shared)
  │    ├─ FUN_0600ca96  — friction/drag (shared)
  │    ├─ FUN_0600c8cc  — speed calc (shared)
  │    └─ FUN_0600c7d4  — heading/speed damping (shared)
  └─ FUN_0600ceba  — track segment advance (shared)
```

### Normal Mode vs AI Mode Comparison

The two pipeline branches for the car iteration loop (cars 1..N).
"Normal mode" = sym_0607EBC4 bit 15 clear. "AI mode" = bit 15 set.
Neither processes car 0 (player) — that has its own path.

| Function | Normal (c5d6) | AI (c74e) | Notes |
|----------|:---:|:---:|-------|
| FUN_0600cd40 track query | Y | Y | Shared |
| FUN_0600ca96 friction | Y | Y | Shared |
| FUN_0600cf58 collision | Y | **N** | Normal-mode only |
| FUN_0600cc38 force app | Y | **N** | Normal-mode only |
| FUN_0600c8cc speed | Y | Y | Shared |
| FUN_0600c928 heading | Y | Y | Shared |
| FUN_0600c7d4 damping | Y | Y | Shared |
| FUN_06006838 atan2 | Y | Y | Shared |
| FUN_06027ede vector rot | Y | Y | Shared |
| FUN_06027358 sin/cos | Y | **N** | Normal-mode only |
| FUN_0600c970 AI steer | **N** | Y | AI-only |

AI mode has NO collision dispatch and NO force application.
AI mode has its own steering function (FUN_0600c970) instead.
