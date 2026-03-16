# Explorer Priorities — Loop 2, Updated 2026-03-16

**Strategic direction**: Clearing ALL fog. The transplant may need to meld
CCE coordinate spaces and track data with the DUSA physics model. Every
internal data path must be fully traced — not just the interface boundary.

Two remaining unknowns. Both are single-experiment tasks.

## Experiment 1: Brake force path inside FUN_0602CA84

**Goal**: Find exactly how car[+0x90] (brake force, range 56-184) produces
negative car[+0xFC] (accel delta, observed peak -303).

**What we know**:
- B button → sym_0602FDA4 → car[+0x90] += 40/frame (max 184+), car[+0x88] = 1
- The force formula's final step subtracts car[+0x114] (resistance term)
- During braking, +0x114 = 26214400 (from animation lookup table sym_060477D8)
- car[+0x90] is NOT in FUN_0602CA84's 28 pool constants (no 0x0090 offset)
- So the brake signal enters through a register argument or through an
  intermediate field that changes when braking

**What to do**:
1. Load `usa_tt_straight.mc0`. Hold C for 200 frames (build to ~27 mph).
2. Release C, hold B. Set breakpoint at FUN_0602CA84 entry (0x0602EF48 is
   the JSR in the dispatcher — break AFTER it, at 0x0602CA84 itself... but
   this is the free-build address. Use retail address 0x0602CA84).
3. At the breakpoint, read car[+0x90], car[+0x8C], car[+0x84], car[+0x74].
   Compare these with values from a no-brake run at the same frame.
4. The field that DIFFERS is the brake carrier. If +0x84 differs (which call 6
   copies from +0x74 in normal path), then brake may override +0x84.
5. Alternative approach: just compare ALL fields in the +0x60-+0xFC range
   between brake-held and idle at the same speed. The differences reveal
   every brake-affected intermediate.

**Simplest approach**: Use existing CSV captures. We have `tt_brake_300f.csv`
(B held from 27 mph) and `tt_throttle_300f.csv` (C held from 0). Compare
fields at the frame where both runs have similar speed (~15 mph, around
frame 50 of brake and frame 200 of throttle). Fields that differ between
"accelerating at 15 mph" and "braking at 15 mph" carry the brake signal.

**What this closes**: The exact field that distinguishes throttle from brake
inside the force accumulator.

## Experiment 2: Manual gear writer for +0xDC

**Goal**: Confirm that FUN_06008318 (or another function) writes car[+0xDC]
when the player presses UP/DOWN in manual transmission mode.

**What to do**:
1. Load `daytona_manual_trans.mc0` (manual transmission save state).
2. Read car[+0xDC] at 0x06078ADC. Note initial value.
3. Hold UP for 1 frame. Read car[+0xDC] again.
4. If it changed: set watchpoint on 0x06078ADC, press UP again, record
   the writer PC. That PC is the manual gear → +0xDC bridge.
5. If it didn't change: UP may need speed > 0. Hold C for 100 frames to
   build speed, then press UP.

**What this closes**: The +0xDE → +0xDC link (or discovery that manual mode
uses a completely different path than auto's sym_0602F17C threshold system).
