# Physics Output Boundary — Who Reads the Driving Model

**Source: Static analysis (consumer_map.md + CDL function_set.md).**
Not validated with the emulator.

Corresponds to Phase B4 of `boundary_mapping_plan.md`.

## Purpose

The driving model writes car struct fields. External systems (rendering, HUD,
sound, AI decision-making) READ these fields. This document maps the output
interface — which fields cross the physics boundary and who consumes them.

**Internal** = function is part of the physics pipeline (player 0x0602xxxx or
AI 0x0600Cxxx-0x0600Exxx). These read/write fields as part of computation.

**External** = function is OUTSIDE the physics pipeline. These are boundary
consumers that read physics output for rendering, display, sound, etc.

## External Pure Consumers

These functions ONLY read the car struct. They are the cleanest boundary
outputs — physics writes, they read, no feedback loop.

### Rendering (confirmed via Car Flip Benchmark)

| Function | CDL Status | Fields Read | Evidence |
|----------|-----------|-------------|---------|
| FUN_0600B6A0 | RACING_ONLY | +0x01, +0x10, +0x14, +0x18, +0x1C, +0x20, +0x24, +0xB8, +0x1C8, +0x1D0, +0x1D8 + DATs | NOP test: removing this function makes ALL opponent cars vanish from rendering AND collision |
| FUN_0600B914 | RACING_ONLY | +0x01, +0x10, +0x14, +0x18, +0x1C, +0x20, +0x24, +0xB8, +0x1C8, +0x1D0, +0x1D8 + DATs | NOP test: same effect as B6A0 — cars vanish |

**Rendering reads these physics fields:**
- Position: +0x10 (X), +0x14 (Y), +0x18 (Z)
- Orientation: +0x1C (pitch), +0x20 (heading), +0x24 (roll)
- Status: +0x01 (active flag), +0xB8 (gear/collision state?)
- Extended: +0x1C8, +0x1D0, +0x1D8 (unknown — possibly animation/visual state)

### HUD / Speed Display

| Function | CDL Status | Fields Read | Hypothesis |
|----------|-----------|-------------|-----------|
| FUN_0600A8BC | RACING_ONLY | +0x08, +0x0C | Speed display: reads speed (+0x0C) and speed index (+0x08) for HUD speedometer |
| FUN_0601DBB8 | unknown | +0x0C | Another speed reader — minimap or lap timer? |

### Position Readers (rendering helpers or minimap)

| Function | CDL Status | Fields Read | Hypothesis |
|----------|-----------|-------------|-----------|
| FUN_0600553C | RACING_ONLY | +0x10, +0x14, +0x18 | Reads XYZ position — possibly minimap or camera |
| FUN_060061C8 | RACING_ONLY | +0x10, +0x14, +0x18, +0x30 | Position + heading delta — camera follow? |
| FUN_0600DCC8 | RACING_ONLY | +0x10, +0x18 + DATs | Position reader — collision detection or rendering helper |
| FUN_0600DD88 | RACING_ONLY | +0x10, +0x18 + DATs | Same pattern as DCC8 |
| FUN_06021178 | RACING_ONLY | +0x10, +0x18 + DATs | Position reader in 0x0602xxxx range |

### Heading / Angle Readers

| Function | CDL Status | Fields Read | Hypothesis |
|----------|-----------|-------------|-----------|
| FUN_0600DA7C | RACING_ONLY | +0x20, +0x28 + DATs | Reads heading and slip angle — camera or AI decision |

### Track / Status Readers

| Function | CDL Status | Fields Read | Hypothesis |
|----------|-----------|-------------|-----------|
| FUN_0600CB90 | RACING_ONLY | +0x1F8 | Surface index reader |
| FUN_0600D8A4 | RACING_ONLY | +0x1EC | Track progress reader |
| FUN_06018320 | unknown | +0x03, +0x08 + DATs | Reads status byte and speed index |
| FUN_06030EE0 | RACING_ONLY | +0x150 | Reads +0x150 only |

### Sound / Other

| Function | CDL Status | Fields Read | Hypothesis |
|----------|-----------|-------------|-----------|
| FUN_06013C58 | unknown | DATs only | Unknown purpose, reads car_base |
| FUN_060173AC | unknown | DATs only | Unknown, reads car_base |
| FUN_06017814 | unknown | DATs only | Unknown, reads car_ptr |
| FUN_0601ADB0 | unknown | DATs only | Unknown, reads car_base |
| FUN_0601DE50 | unknown | DATs only | Unknown, reads car_base |
| FUN_0601DF88 | unknown | DATs only | Unknown, reads car_base |

## Physics Output API (minimum field set for rendering)

Based on what the rendering consumers read, the minimum output interface
from the physics pipeline to the rendering system is:

| Field | Type | Purpose |
|-------|------|---------|
| +0x01 | u8 | Active/visible flag |
| +0x08 | u32 | Speed index (for HUD) |
| +0x0C | u32 | Speed magnitude (for HUD) |
| +0x10 | s32 | World X position |
| +0x14 | s32 | World Y position |
| +0x18 | s32 | World Z position |
| +0x1C | s32 | Pitch angle |
| +0x20 | s32 | Heading angle (yaw) |
| +0x24 | s32 | Roll angle |
| +0x28 | s32 | Slip angle (for camera/visual effects?) |
| +0x30 | s32 | Heading delta (for camera follow?) |
| +0xB8 | u32 | Gear/collision state |
| +0x1C8 | u32 | Unknown (rendering-related) |
| +0x1D0 | u32 | Unknown (rendering-related) |
| +0x1D8 | u32 | Unknown (rendering-related) |

This is **15 fields** that must be maintained for rendering to work.
The physics pipeline writes many more (95+ offsets), but only these
cross the boundary to rendering consumers.

## Implications for Transplant

For the CCE transplant, the physics pipeline must produce at minimum
these 15 fields. The CCE rendering system may read different offsets
or use different struct layouts, but the SEMANTIC interface is:
- 3D position (X, Y, Z)
- 3D orientation (pitch, yaw, roll)
- Speed (scalar + indexed)
- Status flags (active, gear, collision)
- 3 unknown rendering state fields

The transplant specification (Phase E) will map these semantic outputs
to CCE's car struct layout.
