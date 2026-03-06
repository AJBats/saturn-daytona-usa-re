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

## Standard

If the commit wouldn't survive these five questions from the human reviewer,
don't commit it. Revise the theory text until it would.
