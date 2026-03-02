# Save State Commands — Test Results

Tool: `mednafen/src/drivers/automation.cpp` (save_state / load_state commands)

## Implementation

Added two automation commands:
- `save_state <path>` — saves full emulator state to file (gzip, matching GUI format)
- `load_state <path>` — restores emulator state from file (gzip, matching GUI format)

Uses `GZFileStream` + `MemoryStream` to match `MDFNI_SaveState`/`MDFNI_LoadState`
exactly. This means save states created interactively (T key) are fully compatible
with automation load_state, and vice versa.

## Testing

### Compilation: PASS
Debug Mednafen builds clean with includes (`MemoryStream.h`, `compress/GZFileStream.h`, `endian.h`).

### Boot Test: PASS
`python tools/test_boot_auto.py rebuilt` — all 3 stages pass (attract, title, menu).

### Live Test: PASS
- User created save state at circuit select screen via T key in WSL debug Mednafen
- Script loaded it via automation `load_state` — instant restore in 0.1s
- Screenshot verified correct circuit select screen

## Usage

Template: `tools/save_state_template.py`

```python
bot = MednafenBot(ipc_dir, wsl_path(cue_path))
bot.start(timeout=30)
bot.frame_advance(1)
ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
# Now at game state — run experiment
bot.quit()
```

Existing save states in `build/save_states/`:
- `circuit_select_slot0.mc0` — circuit select screen (user T-key save)

## Verdict: PASS (compilation + boot + live load)
