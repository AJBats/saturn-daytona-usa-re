# Our Current Tooling Inventory

Catalog of what our custom Mednafen + Python tools can do today (2026-03-01).

## Mednafen Automation Commands (automation.cpp)

### Frame/Execution Control
- `frame_advance [N]` — run N frames then pause
- `run_to_frame <N>` — free-run to frame N
- `run` / `pause` — play/pause
- `step [N]` — step N CPU instructions
- `continue` — resume from breakpoint

### Breakpoints
- `breakpoint <addr>` — set PC breakpoint (hex)
- `breakpoint_remove <addr>` — remove one
- `breakpoint_clear` — remove all
- `breakpoint_list` — list active
- Pipeline fix: checks both `pc` and `pc-2` for JSR/BSR targets

### Watchpoints
- `watchpoint <addr>` — break on memory write (32-bit aligned)
- `watchpoint_clear` — remove
- Reports: PC, PR, old/new values, frame, write source (CPU vs DMA)
- DMA-aware: catches SCU DMA writes, not just CPU

### Memory/Registers
- `dump_regs` / `dump_regs_bin <path>` — primary SH-2 registers
- `dump_slave_regs` / `dump_slave_regs_bin <path>` — secondary SH-2
- `dump_mem <addr> <size>` — hex text (max 4KB)
- `dump_mem_bin <addr> <sz> <path>` — raw binary (max 1MB)

### Input
- `input <button>` — press (additive, ORed into state)
- `input_release <button>` — release
- `input_clear` — release all
- Buttons: START, A, B, C, X, Y, Z, UP, DOWN, LEFT, RIGHT, L, R

### Call Tracing
- `call_trace <path>` — log JSR/BSR calls (both SH-2s)
- `call_trace_stop`
- Format: `<timestamp> M/S <caller> <target>`

### CD Block Tracing
- `scdq_trace <path>` / `cdb_trace <path>` — CD subsystem events
- `unified_trace <path>` — interleaved CPU + CD events

### Other
- `screenshot <path>` — PNG framebuffer capture
- `deterministic` — fixed RTC for reproducible traces
- `status` — frame count, pause state, etc
- `quit` — clean shutdown
- `dump_cycle` / `run_to_cycle <N>` — cycle-level control
- `vdp2_watchpoint <lo> <hi> <path>` — watch VDP2 VRAM range
- `input_trace <path>` — log real keyboard events
- `insn_trace` — per-instruction trace with line-count triggers

## NOT YET: Save States
Mednafen has save state internals but automation.cpp doesn't expose them.
Adding `save_state <path>` and `load_state <path>` would be straightforward.

## Python: MednafenBot (investigate.py)

Low-level IPC wrapper. File-based protocol (action/ack text files).
- start(), quit()
- frame_advance(n), input_press/release(button)
- dump_regs(), dump_mem_bin(addr, size, path)
- set_breakpoint(addr), clear_breakpoints(), continue_to_break()
- set_watchpoint(addr), clear_watchpoint(), read_watchpoint_hits()
- start_call_trace(path), stop_call_trace()
- screenshot(path)

## Python: DebugSession (debugger_utils.py)

High-level interactive debugging on top of MednafenBot.
- where() — PC/PR with symbol resolution
- step_into(n), step_over(), step_out()
- run_to(name_or_addr)
- frame_calls(n) — capture call tree for N frames
- frame_calls_diff(button, n) — idle vs input differential
- resolve(addr), sym(name) — symbol lookup from daytona.map

## Python: Experiment Helpers (investigate.py)

- experiment_watchpoint(bot, addr, button, label)
- experiment_watchpoint_passive(bot, addr, label)
- experiment_call_trace_diff(bot, button, label, n_frames)
- experiment_memory_diff(bot, addr_start, size, button, label)

## Predefined Replay Points (GAME_STATES)

| Name | Frame | Description |
|------|-------|-------------|
| bios | 174 | Before BIOS skip |
| attract | 1168 | Attract mode |
| title | 1344 | Title screen |
| menu | 1537 | Mode Select |
| circuit | 2688 | Circuit Select |
| car | 3625 | Car/Transmission Select |
| race | 4732 | Racing (before steering) |

## What's Missing (from enhance_re_tooling.md)

1. Save state support in automation
2. Memory value scanner (Cheat Engine style)
3. Full WRAM dump convenience wrapper
4. HW register function tagger
5. String detector
6. SDK signature matcher
