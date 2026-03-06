# Driving Model Mapping Workstream

**Goal**: Map the Daytona USA driving model boundaries and API surfaces for
transplanting gameplay code to Daytona USA CCE.

## Function Status — Source Is King

Do not maintain a scoreboard here. The source files are the record of truth.
To audit what is theorized and what isn't:

```bash
grep -r 'THEORY\|OBSERVED\|VERIFIED' reimpl/src/*.s
```

## Resolved Questions

1. **C button = throttle** — CONFIRMED via watchpoint on car[+0xFC]. C shifts accel delta
   +70 units/update vs idle drift of -1 to -7. See struct_map.md.
2. **Car 0 = player** — CONFIRMED. HUD speedometer reads car 0's speed field (ratio 1,467
   stable). Car 0 is processed by FUN_0602D814, separate from the AI loop.
3. **sym_0607EBC4 bit 15 = global mode flag** — when clear, ALL cars in the loop use
   FUN_0600e71a. The loop (i=1..N) processes AI cars only. Player car 0
   has its own code path rooted at ~0x0602EF00.

## Open Questions

1. **Player physics pipeline is UNMAPPED** — FUN_0602D814 writes car 0's speed at
   pc=0x0602D822. Called from ~0x0602EF00. This is THE player driving code — throttle,
   steering, everything the human controls. The entire FUN_0600e71a tree we mapped is
   for AI opponent cars (1..N), not the player.
2. **sym_0607EBC4** — what sets bit 15? When is it non-zero? Controls normal vs AI pipeline
   for the car iteration loop. During our testing it was always 0 (normal mode).
3. **What does "normal mode" vs "AI mode" mean?** — We assumed "player" vs "AI" but
   the loop processes cars 1..N regardless. Maybe it's a race phase distinction
   (e.g., rolling start vs racing vs replay)?

## Workstream Files

| File | Purpose |
|------|---------|
| `struct_map.md` | Car struct fields — empirically confirmed only |
| `call_tree.md` | Ghidra call tree (structural, mechanically derived) |
| `static_hypotheses.md` | Untested Ghidra hypotheses — experiment design seeds |
| `watch_car_fields.py` | Watchpoint tool for car struct field investigation |
