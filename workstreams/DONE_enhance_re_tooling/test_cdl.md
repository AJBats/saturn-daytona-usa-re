# Code/Data Logging (CDL) — Test Results

Feature: E2 (Code/Data Logging in Mednafen)
Commands: `cdl_start`, `cdl_stop`, `cdl_dump <path>`, `cdl_reset`, `cdl_status`

## Implementation

Per-byte bitfield for High WRAM (0x06000000-0x060FFFFF, 1MB):
- Bit 0 (0x01): CODE — fetched as instruction (hooked in FetchIF)
- Bit 1 (0x02): DATA_READ — read as data (hooked in MemRead)
- Bit 2 (0x04): DATA_WRITE — written as data (hooked in MemWrite)

Guarded by `MDFN_UNLIKELY(cdl_active)` — zero overhead when CDL is off.

## Testing

### 60 Frames at Mode Select: PASS
```
CODE:       3,600 bytes (0.34%)
DATA_READ:  1,544 bytes (0.15%)
DATA_WRITE:    419 bytes (0.04%)
Any access: 5,227 bytes (0.50%)
Untouched:  1,043,349 bytes (99.50%)
```

Numbers are reasonable for 60 frames of idle menu loop. Most code executes
during boot/transitions, not during steady-state menu rendering.

## Verdict: PASS
