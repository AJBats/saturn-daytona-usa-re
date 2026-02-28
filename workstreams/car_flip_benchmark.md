# Car Flip Benchmark — Empirical Annotation Validation

> **Status**: Active — experiments 1 & 3 done (no visible change), 2 & 4 pending
> **Created**: 2026-02-27
> **Updated**: 2026-02-27

## The Goal

Flip the car graphics upside down as a visual benchmark to judge how much our
annotations are helping with real reverse engineering. An eyecatching modification
that proves we understand the rendering pipeline well enough to modify it.

## Approach

Theoretical pipeline tracing produced medium-confidence guesses about what each
function does. We shifted to **empirical poke-and-observe**: change one value,
build, run, observe. This tests both our annotations AND our pipeline understanding.

### Build/Launch Commands

```bash
# Build (from Windows, invokes WSL)
echo 'make -C /mnt/d/Projects/SaturnReverseTest/reimpl clean 2>&1 && make -C /mnt/d/Projects/SaturnReverseTest/reimpl disc 2>&1' | wsl -d Ubuntu -- bash 2>&1

# Launch (from Windows PowerShell)
.\external_resources\mednafen-1.32.1-win64\mednafen.exe "d:\Projects\SaturnReverseTest\build\disc\rebuilt_disc\daytona_rebuilt.cue"
```

### Build Chain Verification

To confirm a change reached the disc image:
1. Check `git diff` shows the source change
2. Find the symbol address in `reimpl/build/daytona.map`
3. Subtract load base `0x06003000` for binary file offset
4. `xxd` the binary at that offset to confirm changed bytes
5. Find the same bytes in the disc image (`.cue` file offset)

**Load base**: `0x06003000` (from `reimpl/free.ld`, NOT `0x06004000`)

## Experiment Plan

From pipeline analysis, four experiments ordered easiest-first:

1. Change Y base constants in `perspective_project`
2. Add offset to orientation angle in `orientation_sincos` (car[0x24])
3. Change `mat_rot_y` call in `pre_render_transform` to `mat_rot_z`
4. Modify VDP1 direction bits in `vdp1_polygon_build`

## Experiments

### Experiment 1: perspective_project Y base constants — NO CHANGE

**File**: `reimpl/src/perspective_project.s`
**Change**: Negated the Y base constants:
- `_pool_positive_y_base`: `0x01A00000` → `0xFE600000`
- `_pool_negative_y_base`: `0xFFA00000` → `0x00600000`

**Result**: NO visible change during racing (ran a full lap).
**Conclusion**: `perspective_project` is not active during normal racing view,
or these constants don't control what we thought. Reverted.

### Experiment 2: orientation_sincos angle force — AUDIO, NOT VISUAL

**File**: `reimpl/src/render_orchestrator.s` (contains `sym_0602EFCC`)
**Change**: Forced orientation angle to zero:
- `mov.l @(36, r0), r4` → `mov #0x0, r4`

**Result**: Car engine sound stopped working. No visual change.
**Conclusion**: `sym_0602EFCC` feeds the **audio system** (spatial sound panning),
not the visual rendering. The sin/cos output is used for stereo positioning of
engine sounds, not car sprite orientation. Our annotation "orientation_sincos" was
half right — it IS sin/cos of the angle, but for audio, not graphics. Reverted.

### Experiment 3: pre_render_transform rotation axis swap — NO CHANGE

**File**: `reimpl/src/pre_render_transform.s`
**Change**: Swapped the rotation function in the pool:
- `_pool_fn_mat_rot_y`: `mat_rot_y` → `mat_rot_z`

**Result**: NO visible change during racing.
**Build verified**: Confirmed `mat_rot_z` address (`0x06026F2A`) present at the
correct pool location in both the built binary (offset `0x3270`) and disc image
(offset `0xFA90`). The change definitely reached the game.
**Conclusion**: `pre_render_transform`'s rotation matrix does NOT affect visible
car rendering. This function may handle the 3D polygon path (body sub-objects)
while actual car visuals use the sprite display path through `render_orchestrator`.

### Experiment 4: VDP1 direction bits — PENDING

**File**: `reimpl/src/vdp1_polygon_build.s`
**Change**: TBD — modify VDP1 CMDCTRL flip bits

## Key Finding: Two Parallel Rendering Paths

The car rendering has (at least) two parallel systems:

1. **3D polygon path**: `pre_render_transform` → `scene_3d_processor` → `vdp1_polygon_build`
   - Handles geometry channels (car body sub-objects?)
   - Experiments 1-2 targeted this path — no visible effect

2. **Sprite display path**: `render_orchestrator` → 18-step pipeline → VDP1 commands
   - Steps include: perspective projection, orientation sin/cos, display list setup,
     color setup, coordinate setup, sprite/list submit
   - This path likely controls what we actually SEE on screen

## Next Experiments to Try

Targeting the sprite display path through `render_orchestrator`:

- **VDP1 display scale**: `vdp1_display_list_setup.s` — negate Y scale factor
  (`0x02D00000` → negative) or swap X/Y scale constants
- **Orientation sin/cos**: `render_orchestrator.s` → `sym_0602EFCC` — modify the
  sin/cos values that control car heading display
- **VDP1 coordinate commands**: `vdp1_coord_setup.s` — negate Y coordinates in
  the VDP1 command output
- **VDP1 CMDCTRL flip bits**: Find where VDP1 command CMDCTRL is written and set
  bit 5 (vertical flip, `0x0020`)

## Pipeline Reference

### Car struct layout (stride 0x268, array base sym_06078900)
- `+0x10` X position, `+0x14` Y position, `+0x18` Z position
- `+0x24` orientation angle, `+0x30` heading
- `+0x140` X display scale, `+0x144` Y display scale

### VDP1 command format (32 bytes)
- CMDCTRL: bit 4 = horizontal flip, bit 5 = vertical flip
- Vertex coords: XA/YA through XD/YD (4 corner positions)

### Matrix format (48 bytes)
- 3x3 rotation (9 x int32, row-major, 16.16 fixed-point) + translation (3 x int32)
- Two stacks: Stack A (camera/world), Stack B (object/model)
