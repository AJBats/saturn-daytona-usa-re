# Self-Directed Theory Work (temporary rule)

This branch builds on prior art from three human-reviewed commits:

- `27f44da0` — FUN_06030548 (player_collision_response_chain), revert sound_music_ctrl
- `bd78326c` — FUN_06030E72 (speed_damping), revert sound_channel_mgr
- `ee0c9555` — FUN_0600C4F8 (speed_update) + evidence hierarchy rule

## Pre-Commit Checklist

Before every commit on this branch, put the following questions to yourself.
These are the kinds of scrutiny the human applied during the prior art reviews.

### 1. Does the theory match the evidence scope exactly?

"My observation is that this test only did AI car speed. Should the name be
ai_speed_update, or does this function do more things?"

- If you only tested in the AI pipeline, don't claim it applies to the player.
- If you only observed behavior during collision, don't say "each frame."
- The theory description must be exactly as broad as the evidence — no broader.

### 2. Are you conflating two theories into one?

"Sounds like you have two theories? Let's see your evidence."

- If you have multiple hypotheses, separate them. Each gets its own evidence.
- Don't merge "it does X" and "it does Y" into one vague umbrella theory.

### 3. Would this theory survive a "when does it actually fire?" challenge?

"Player_physics_pipeline — wouldn't this fire every frame, and not only when
we collide with the wall? What was the breakpoint behavior precisely?"

- If you call something a "pipeline" or "main loop" function, did you verify
  it runs every frame? Or only under specific conditions?
- State the trigger condition precisely: every frame, only during collision,
  only when a flag is set, etc.

### 4. Does the theory overstate what was observed?

"If FUN_06030E72 is only called during collision we should update that theory
as well."

- Re-read the theory text literally. Does every claim have a corresponding
  emulator observation?
- "Multiplies speed each frame" vs "multiplies speed during collision" is the
  difference between a correct and incorrect theory.

### 5. Does the function actually write the field you're attributing to it?

"This function doesn't write speed — it reads speed and writes position.
The speed effect you observed is indirect."

- After a NOP test shows "removing function X changed outcome Y," open the
  Ghidra C (or trace the ASM) and list what the function actually reads and
  writes.
- If the function doesn't directly write the affected field, the effect is
  **indirect** — it writes something else that feeds a downstream dependency
  chain. The theory must say so.
- A NOP test proves involvement, not direct causation. The read/write set
  tells you the mechanism. You need both before writing the theory.

Origin: FUN_0600C7D4 was tagged "speed_deceleration" because NOPping it
caused cars to hold speed. But the function only reads car[+0x0c] (speed)
and writes car[+0x10]/[+0x18] (position). Speed held because position
stopped updating, which starved downstream track-driven speed changes.
Two bad theories (speed_delta_calc, speed_deceleration) passed checklist
items 1-4 but would have been caught by checking the read/write set.

### 6. Is this a fall-through prologue? Which function has the real logic?

"This function is 2 instructions and falls through to the next one. Could
it be the next function actually contains all this logic?"

- SH-2 ASM uses **split prologue/epilogue**: a short function (2-4
  instructions) pushes registers and sets up parameters, then falls through
  (no `rts`) into the next function which contains the real body. The body's
  epilogue pops both its own saves and the prologue's.
- Before tagging a function, check its size. If it's tiny and has no `rts`,
  look at the next function in the binary — that's likely the real body.
- **Both functions can have THEORY tags**, but each must describe its own role:
  - Prologue: "Fall-through prologue for FUN_XXXX. Pushes r14, sets r14=r4
    (car pointer). Falls through into FUN_XXXX which contains the actual logic."
  - Body: "heading_angle_update — computes X, writes Y. Evidence: ..."
- If two functions both contain real logic and one falls through to the other,
  describe each independently: "Function A does X then falls through to
  Function B" on A, "Function B does Y" on B. Don't attribute B's logic to A.
- **A NOP on the BSR to the prologue skips BOTH functions.** Any observed
  effect could come from either. Check the body's read/write set (item #5)
  before attributing the effect.

Origin: FUN_0600C8CC (2 instructions, no rts) was tagged "speed_delta_calc"
based on a NOP test. The actual logic was in FUN_0600C8D0 (heading angle via
atan2). Corrected in `12404109` — prologue tag points to body, body has its
own THEORY tag with the real evidence. Same pattern repeated with FUN_0600C7D4
falling through to FUN_0600C7D8.

## Save States

Humans create save states for experiments. Do not create new save states.
If an experiment would benefit from a different starting state (e.g., mid-corner,
post-collision, different track), ask the user to create one and document it in
`build/save_states/README.md`.

Use only save states documented in README.md. Pass Windows paths (not WSL paths)
to load_state.

## Standard

If the commit wouldn't survive these five questions from the human reviewer,
don't commit it. Revise the theory text until it would.
