# HW Register Tagging — Test Results

Tool: `tools/hw_tag.py`
Source: `reimpl/src/*.s` (L3 disassembly, 1046 files)
Run: `python tools/hw_tag.py reimpl/src --summary -o build/hw_tags.json`

## Results

130 of 1046 files contain hardware register references (12.4%).
467 total HW address references. 34 files touch multiple subsystems.

### Tag Distribution

| Subsystem | Files | Confidence |
|-----------|-------|------------|
| VDP2 Color RAM | 33 | HIGH |
| VDP2 VRAM | 25 | HIGH |
| A-Bus CS1 | 22 | MEDIUM (large range, some false positives) |
| A-Bus CS2 | 20 | MEDIUM (large range, some false positives) |
| A-Bus CS0 | 16 | MEDIUM (large range, some false positives) |
| SH-2 Internal | 12 | HIGH |
| SMPC Input | 12 | HIGH |
| SCU DSP | 11 | HIGH |
| VDP1 Registers | 6 | HIGH |
| VDP1 VRAM | 5 | HIGH |
| VDP2 Registers | 5 | HIGH |
| SCU Registers | 4 | HIGH |
| SCSP Sound | 2 | HIGH |
| VDP1 Framebuffer | 2 | HIGH |

### Spot-Check Validation

- `sound_scsp_boot`: Tagged scu_dsp (0x25A00000, 0x25A03000, 0x25A10000) — CORRECT, boots sound DSP
- `vdp1_init`: Tagged vdp1_vram, vdp1_fb, cs0, cs2 — CORRECT for vdp1, cs0/cs2 may be data constants
- `smpc_peripheral_query`: NOT tagged — its SMPC access is via `sym_` indirection, not raw address
- `scu_dma_transfer`: Tagged scu_reg — CORRECT (0x25FE000C is SCU DMA register)
- `vdp2_register_init`: 35 VDP2 references — CORRECT, this is the VDP2 register init function

### Known Limitation

Static analysis only catches pool entries with raw hex addresses (`.4byte 0x25xxxxxx`).
Functions that access HW via symbol indirection (load address from a variable) are invisible.
Dynamic tracing (future feature) would catch these.

The A-Bus CS0/CS1/CS2 ranges (0x20000000-0x25800000) are very large and include data
constants that aren't actual HW accesses. These tags should be treated as MEDIUM confidence.

## Verdict: PASS

Core subsystem tags (VDP1, VDP2, SCSP, SCU, SMPC, SH-2) are high confidence.
130 files automatically classified by hardware subsystem with zero manual effort.
