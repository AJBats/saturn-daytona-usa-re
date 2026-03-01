# Memory Write Profiling — Test Results

Feature: E4 (Memory write profiling)
Commands: `mem_profile <lo_hex> <hi_hex> <path>`, `mem_profile_stop`

## Implementation

Hooks MemWrite macro in sh7095.inc. Logs {pc, addr, value, size} for writes
in configurable address range. Guarded by `MDFN_UNLIKELY(memprofile_file)`.

## Testing

### Button Input Area (0x06063D00-0x06063EFF, 60 frames): PASS
```
100+ KB of write logs captured.
Key pattern: viewport_coord_calc (pc=0x060051FA) writes button bits:
  pc=0x060051FA addr=0x06063D98 val=0x2000 sz=2   (DOWN button pressed)
  pc=0x060051FA addr=0x06063D98 val=0x0 sz=2       (no button)
  pc=0x06005202 addr=0x06063D9C val=0xFFFF sz=2    (analog stick default)
```
Menu animation system (pc=0x0603A354-0x0603A45E) writes to 0x06063DCC-0x06063DEC.

## Verdict: PASS
