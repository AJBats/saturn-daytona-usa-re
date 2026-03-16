# Explorer Priorities — Loop 2, Updated 2026-03-16

**Strategic direction**: Frame timing is the new #1. The DUSA physics uses
fixed per-frame constants with no dt variable. Every `+= K` assumes a specific
frame interval. If DUSA runs at 20fps and CCE at 30fps, the transplanted
physics runs 1.5× too fast. We need to: (1) measure DUSA's actual framerate,
(2) find the frame timing mechanism, (3) modify DUSA to 30fps as a proving
ground before transplanting to CCE.

## HIGH PRIORITY — Frame Timing

### Experiment A: Measure DUSA frame rate

**Goal**: Determine exactly how many VBlanks pass between consecutive
physics frames. NTSC VBlank = 60Hz. If physics runs every 3 VBlanks = 20fps.
Every 2 VBlanks = 30fps.

**What to do**:
1. Load `usa_tt_straight.mc0`. Set breakpoint at FUN_0600C010 (racing
   orchestrator, the first game code each frame).
2. Read the VBlank counter. On Saturn, the SCU's timer or the VBlank
   interrupt counter tracks this. Check sym_0607EAAC (we identified this
   as a frame counter that increments +1/frame). If this increments by 1
   each physics frame, it doesn't tell us VBlank count.
3. **Better approach**: Use `dump_cycle` to read the cycle counter at two
   consecutive FUN_0600C010 breakpoint hits. The delta in CPU cycles ÷
   the SH-2 clock rate (28.6MHz) gives the exact frame interval.
   - 20fps = 50ms = 1,430,000 cycles between frames
   - 30fps = 33ms = 953,333 cycles between frames
4. Measure during idle (no input) AND during racing (C held) — the
   frame time may vary if it's not VBlank-locked.

**What this tells us**: The exact N in "60/N fps" and whether the game
runs at fixed or variable frame rate.

### Experiment B: Find the VBlank wait mechanism

**Goal**: Identify which function in the main loop chain waits for VBlank.
This is the framerate governor — changing it would change the fps.

**What to do**:
1. The main loop chain is: BIOS → 0x06000310 → 0x060072E4 → 0x0600305C
   → 0x0600943C → FUN_0600C010.
2. One of these early functions (likely 0x060072E4 or 0x0600305C) contains
   a VBlank wait loop. On Saturn, this typically looks like:
   - Reading SMPC or SCU interrupt status register
   - OR: writing to the VBlank semaphore and spinning until cleared
   - OR: calling SGL's `slSynch()` which waits for VBlank count
3. Set breakpoint at each function in the chain. At each break, read the
   cycle counter. The function with the LARGEST cycle count between entry
   and exit is the one doing the wait (it's spinning).
4. Alternatively, search for reads of the VBlank counter register or
   the string "slSynch" in the binary.

**What this tells us**: Where to patch for 30fps. If the wait counts 3
VBlanks (20fps), changing it to 2 gives 30fps.

### Experiment C: Catalog all per-frame fixed constants

**Goal**: Build the complete list of constants that need 20/30 scaling
for the 30fps conversion.

**What to do**: This can largely be done from existing data (Mapper work).
From the data flow chains, every `+= K` or `-= K` per frame is a fixed
constant. Catalog:

| Constant | Location | Current Value | 30fps Value (×2/3) |
|----------|----------|---------------|-------------------|
| Throttle ramp | sym_0602FDA4 | +10/frame | +6.67 → +7 |
| Brake ramp | sym_0602FDA4 | +40/frame | +26.67 → +27 |
| Drag amount | sym_0602F3EC | speed_idx × 64 | speed_idx × 43 |
| Traction decay | FUN_0602CCEC | -1474/frame | -983 |
| Heading correction | FUN_0602CDF6 | ±60/frame | ±40 |
| Throttle decay | sym_0602FDA4 | toward 56 | rate × 2/3 |
| Brake decay | sym_0602FDA4 | r4 - r4/2 | same formula, runs less often |
| Timer decrements | sym_0602F7BC | -1/frame | -1/frame (but frame count changes) |
| Steering deadzone | FUN_0602EFF0 | ×255 scale | ×170 |
| EMA blend | sym_0602F0E8 | (B0<<8 + D0)>>1 | blend rate needs adjustment |

**What this tells us**: The exact patch list for 30fps conversion.
Some constants can use integer 2/3 approximation. Others (like EMA blend
rates and exponential decays) need more careful recalculation.

## COMPLETED (data flow gaps)

Both previous experiments resolved:
- Experiment 1 (brake): CLOSED via CSV analysis — symmetric with throttle
- Experiment 2 (manual gear): CLOSED — +0xDC and +0xDE synchronized

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
