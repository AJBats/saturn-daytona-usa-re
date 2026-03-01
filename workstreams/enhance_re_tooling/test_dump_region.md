# dump_region Command — Test Results

Feature: E1 (WRAM dump command)
Tool: `mednafen/src/drivers/automation.cpp` (dump_region command)
Support: `mednafen/src/ss/ss.cpp` (Automation_ReadMemBlock bulk reader)

## Implementation

Added `dump_region <name> <path>` command to automation.cpp. Named regions:

| Region | Address Range | Size |
|--------|--------------|------|
| wram_high | 0x06000000-0x060FFFFF | 1MB |
| wram_low | 0x00200000-0x002FFFFF | 1MB |
| vdp1_vram | 0x05C00000-0x05C7FFFF | 512KB |
| vdp2_vram | 0x05E00000-0x05E7FFFF | 512KB |
| vdp2_cram | 0x05F00000-0x05F00FFF | 4KB |
| sound_ram | 0x05A00000-0x05A7FFFF | 512KB |

Also added `Automation_ReadMemBlock()` in ss.cpp for bulk reads (reads backing
store directly, bypasses SH-2 cache for speed on large dumps).

## Testing

### Compilation: PASS
Debug Mednafen builds clean with the new function.

### Boot Test: PASS
`python tools/test_boot_auto.py rebuilt` — all 3 stages pass.

### Live Test: PASS
`python workstreams/enhance_re_tooling/test_dump_region.py`

Booted to menu state, dumped all 6 regions:

| Region | Size | Unique Bytes | Zero % | Status |
|--------|------|-------------|--------|--------|
| wram_high | 1,048,576 | 256 | 48.6% | PASS |
| wram_low | 1,048,576 | 256 | 45.2% | PASS |
| vdp1_vram | 524,288 | 256 | 14.7% | PASS |
| vdp2_vram | 524,288 | 256 | 21.5% | PASS |
| vdp2_cram | 4,096 | 220 | 26.9% | PASS |
| sound_ram | 524,288 | 256 | 4.4% | PASS |

All regions contain valid data (all 256 byte values present, reasonable zero percentages).
21,882 ASCII 4-byte+ sequences found in high WRAM (game strings, debug text, etc.).

## Usage

```python
# From Python via MednafenBot:
bot.send_and_wait("dump_region wram_high /tmp/wram.bin", "ok dump_region")

# Then analyze with mem_diff.py or memory scanner
```

## Verdict: PASS
