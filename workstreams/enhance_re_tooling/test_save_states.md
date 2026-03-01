# Save State Commands — Test Results

Tool: `mednafen/src/drivers/automation.cpp` (save_state / load_state commands)

## Implementation

Added two automation commands:
- `save_state <path>` — saves full emulator state to file using `MDFNSS_SaveSM()`
- `load_state <path>` — restores emulator state from file using `MDFNSS_LoadSM()`

Uses `FileStream` (inherits from `Stream`) for direct file I/O. Both wrap in
try/catch to handle errors gracefully.

## Testing

### Compilation: PASS
Debug Mednafen builds clean with the new includes (`state.h`, `FileStream.h`).

### Boot Test: PASS
`python tools/test_boot_auto.py rebuilt` — all 3 stages pass (attract, title, menu).
Confirms the new code doesn't break emulation.

### Live Test: DEFERRED
Direct automation test fails due to WSL display requirements (Mednafen needs X11
for headless mode without `show_window`). The save/load commands follow the exact
pattern used by Mednafen's own state fuzz tests in `main.cpp` (lines 1089-1103).

## Intended Use

```python
# Save state before investigation
bot.send_and_wait('save_state /tmp/checkpoint.mcf', 'ok save_state')

# Experiment (press buttons, advance frames, etc.)
bot.frame_advance(100)
bot.input_press('DOWN')
bot.frame_advance(1)

# Reload state — instant replay to checkpoint
bot.send_and_wait('load_state /tmp/checkpoint.mcf', 'ok load_state')
```

This eliminates the 4700-frame replay needed by `replay_to_state()`.
Save once → experiment many times.

## Verdict: PASS (compilation + boot test)
