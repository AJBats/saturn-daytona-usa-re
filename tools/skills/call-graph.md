---
name: mednafen-debugger
description: Custom Mednafen automation/debug interface for Saturn reverse engineering. Use when you need to boot-test, set breakpoints, compare memory, trace calls, or debug execution in the emulator.
---

# Call Graph Exploration

DFS "rat race" through a function's call graph using the debugger. Step into every new function, skip already-explored ones, stop when you loop back. Output is an ASCII call graph.

## Batch runner

`python tools/explore_callgraph.py` runs DFS across game states and button inputs.
Each scenario auto-discovers the state handler, DFS's from it, saves the tree + screenshot.

```
python tools/explore_callgraph.py --list          # show all scenarios
python tools/explore_callgraph.py menu_idle        # run one
python tools/explore_callgraph.py                  # run all
```

Results go to `call_graphs/<state>/` (committed artifacts, not build ephemera).

## How state handler discovery works

Can't breakpoint on the main loop (sym_06003000) — it's _start, reached via reset vector not JSR.
Instead: break on per_frame_update (fires every frame), step out to main loop, step forward
to find the next function called. That's the per-state handler (e.g., state_course_select_active
for mode select). DFS from there.

## What the DFS shows (and doesn't)

The DFS tracks symbol name changes as PC moves. This captures both:
- **Real calls** (JSR/BSR) — actual function calls
- **Intra-function branches** (BT/BF/BRA) — if/else, switch, loops

DAT_* and loc_* in the tree are usually branch targets WITHIN a function, not real calls.
FUN_* labels are unnamed functions (missed during rename pass). Both are accurate observations.

## API

```python
from debugger_utils import DebugSession
s = DebugSession("menu")
s.run_to("function_name")
s.where()         # dict: pc, pc_sym, pr, pr_sym, r0-r15
s.step_into(n=1)  # step N instructions, returns where()
s.step_over()     # detects JSR/BSR, BP at PC+4, skip subroutine
s.step_out()      # BP at PR, return to caller
s.quit()
```

## Gotchas

- step_into is expensive: each step = step IPC + dump_regs IPC. ~200ms/step. Budget ~2000 max.
- 100 steps in same function with no call = loop detected, auto step_out
- game_state_dispatch is NOT called in all states (absent during mode select)
- per_frame_update and state handler are siblings in the main loop, not parent-child
- For button scenarios: press button + frame_advance(1) before DFS so SMPC reads the input
- Windows cp1252 can't handle Unicode box-drawing — use ASCII tree chars
- Mednafen dump_regs outputs bare hex (R0=06008B38 not R0=0x06008B38)
- Breakpoints at branch targets fire at PC=target+2 (SH-2 pipeline fetch offset)
