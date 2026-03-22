# Call Graph Exploration Process

How we mapped the function call structure of Daytona USA '95 using
the Mednafen debugger. This process preceded the auto-RE pipeline
(Explorer/Verifier/Mapper) and produced the foundational call tree
that all subsequent analysis builds on.

## Process Overview

1. **Boot game in emulator** → navigate to target game state (menu, race, etc.)
2. **Capture call traces** per game state + button input combination
3. **Diff traces** to find button-responsive functions
4. **Cross-reference** all scenarios to find common core vs state-unique edges
5. **Build the call tree** from aggregated traces

## Timeline

| Date | Commit | Milestone |
|------|--------|-----------|
| 2026-02-28 | `0e03e8a7` | First DFS call graph explorer + debugger_utils.py |
| 2026-02-28 | `d661e949` | Rewrite: DFS → call_trace (passive capture, 100x faster) |
| 2026-02-28 | `e847edf5` | 18 scenarios captured (5 game states × button inputs) |
| 2026-02-28 | `bde70902` | Cross-reference tool + analysis (130 unique edges) |
| 2026-03-01 | `6178531a` | Circuit select save state + graph refresh |
| 2026-03-01 | `3925e850` | 4 wrong function names found by call graph audit |
| 2026-03-04 | `7dc37aa7` | Driving model workstream created from call tree data |
| 2026-03-04 | `c22d5e54` | Mapper produces player physics pipeline static call tree |

## Tools

### Primary: `tools/debugger_utils.py`

Interactive debugger session with symbol resolution, stepping,
breakpoints, and call trace capture.

```python
from debugger_utils import DebugSession
s = DebugSession("menu")
s.run_to("function_name")
s.where()         # pc, pc_sym, pr, pr_sym, registers
s.step_into(n=1)  # step N instructions
s.step_over()     # skip subroutine
s.step_out()      # return to caller
s.frame_calls(1)  # capture 1 frame of call trace
s.frame_calls_diff("LEFT")  # diff: idle vs LEFT held
```

### Batch: `workstreams/empirical_validation/explore_callgraph.py`

Automated runner across game states and button inputs.

```bash
python workstreams/empirical_validation/explore_callgraph.py --list     # show scenarios
python workstreams/empirical_validation/explore_callgraph.py menu_idle  # one scenario
python workstreams/empirical_validation/explore_callgraph.py            # all 18
```

### Analysis: `workstreams/empirical_validation/callgraph_diff.py`

Call-trace differential analysis. Captures baseline (N frames idle)
vs input (N frames with button), identifies functions with MORE calls
during input = button-responsive. NEW functions that appear ONLY
during input are the strongest leads.

### Cross-reference: `tools/archive/call_trace_compare.py`

Compares all 18 scenario graphs to find common core edges, state-unique
edges, and per-function state reach.

## Artifacts (checked in)

### `call_graphs/` directory

18 captured scenarios, each with:
- `.txt` — ASCII call tree + edge list with hit counts
- `.png` — Screenshot of game state for human verification

Organized by game state:
```
call_graphs/
  attract/     # attract_idle, attract_START
  car/         # car_idle, car_B, car_C, car_LEFT, car_RIGHT
  circuit/     # circuit_idle, circuit_B, circuit_C, circuit_LEFT, circuit_RIGHT
  menu/        # menu_idle, menu_B, menu_C, menu_UP, menu_DOWN
  title/       # title_idle, title_START
  cross_reference.txt   # aggregated analysis
```

### Sample artifact: `call_graphs/car/car_idle.txt`

```
CALL GRAPH: car idle
79 edges, 80 functions

TREE:
framebuf_swap_ctrl
    `-- sym_06000358
        |-- vblank_out_handler
        |   `-- controller_input_update
        |       `-- smpc_data_manage
        |           `-- DAT_0603a2ca
        |-- master_menu_render
        |   |-- sym_0603AB46
        ...
```

### Cross-reference summary: `call_graphs/cross_reference.txt`

```
18 scenarios, 130 unique edges across all

COMMON CORE (12 edges — present in all 18 scenarios)
  controller_input_update -> smpc_data_manage
  framebuf_swap_ctrl -> sym_06000358
  master_menu_render -> data_table_copy
  ...

STATE-UNIQUE edges show what code activates per screen.
```

## Derived outputs

### `workstreams/driving_model/call_tree.md`

The definitive call tree for the driving model. Built from call graph
artifacts + Ghidra decompilation. Covers:
- Frame-level entry points (FUN_0600C010 orchestrator)
- Car iteration loop (FUN_0600E0C0, cars 1..N)
- Normal mode vs AI mode pipeline comparison
- Player physics path (separate from AI, rooted at ~0x0602EF00)

### `workstreams/research/frame_architecture.md`

Frame architecture discovered during call graph work:
- Two execution contexts: game thread + timer interrupt (334×/frame)
- Rendering happens IN the interrupt, not from the main loop
- Timer math: OCRA=358 cycles, 50us interval, 28.636 MHz CPU

### `workstreams/empirical_validation/DONE_empirical_validation.md`

Mode select call chain empirically traced via step-through:
FUN_06008B34 → FUN_060196A4 → mode_select_handler → FUN_06026110

## Key Methodology Insights

### DFS vs Passive Call Trace

First approach (DFS stepping): slow (~minutes/scenario), missed
interrupt-driven rendering entirely. Replaced with passive call_trace
capture (~seconds/scenario) which captures the full frame including
interrupts.

### Call-Trace Differential

The most powerful technique: baseline (idle) vs input (button held).
Functions with MORE calls during input are button-responsive.
Functions that appear ONLY during input are the strongest leads.

### State Handler Discovery

Can't breakpoint on main loop (_start) — it's the reset vector.
Instead: break on per_frame_update, step out to main loop, step
forward to find the per-state handler. DFS from there.

### What Call Graphs Show (and Don't)

The DFS tracks symbol name changes as PC moves. This captures both
real calls (JSR/BSR) AND intra-function branches (BT/BF/BRA).
DAT_*/loc_* in the tree are usually branch targets within a function,
not real calls. FUN_* labels are unnamed functions.

## How This Fed Into Auto-RE

The call tree and frame architecture directly informed:
1. **Explorer priorities** — which functions to investigate first
2. **Pipeline call order** — the 18-call sequence in FUN_0602EEB8
3. **NOP test design** — knowing which function to skip and what to expect
4. **Transplant manifest** — the physics box boundary comes from the call tree
