---
function: sym_0602FDA4 (manual gear input)
address: 0x0602FDA4
explored: 2026-03-16
scenarios_tested: [manual_trans_race]
reachable: true
---

## Experiment 2: Manual Gear Writer for +0xDC

### Result: UP/DOWN writes +0xDE only, NOT +0xDC

| Action | car[+0xDC] | car[+0xDE] |
|--------|-----------|-----------|
| Initial (manual, ~179 mph) | 3 | 3 |
| After UP × 5 frames | 3 (unchanged) | 2 (decreased!) |
| After DOWN × 5 frames | 3 (unchanged) | 3 (restored) |
| After 100 more frames (C held) | 3 (unchanged) | 3 |

### Key Findings

1. **UP button DOWNSHIFTS** (decreases +0xDE from 3 to 2). DOWN UPSHIFTS
   (increases +0xDE back to 3). The mapping is inverted from typical racing
   game conventions — or the d-pad direction mapping differs.

2. **+0xDC is NOT written by UP/DOWN buttons.** It stays at 3 throughout
   manual mode at high speed. The auto-shift threshold system (sym_0602F17C)
   manages +0xDC independently based on car[+0xE0] vs threshold tables.

3. **+0xDE and +0xDC are independent systems:**
   - +0xDE: player manual gear selection (0-3, written by sym_0602FDA4)
   - +0xDC: auto-shift section index (written by sym_0602F17C thresholds)

   In manual mode, BOTH still run. The auto-shift continues managing +0xDC
   while the player manages +0xDE. The force formula likely uses BOTH:
   sym_0602D814 uses +0xDC for the gear ratio table, while FUN_0602CCEC
   uses +0xDC for the force constant table.

### +0xDE → +0xDC Link: NONE (Independent Systems)

The Mapper's question was whether manual gear input writes +0xDC. Answer:
**NO**. The manual button writes +0xDE exclusively. +0xDC is always managed
by the auto-shift threshold system regardless of transmission mode.

This means in manual mode, the player's gear selection (+0xDE) and the
speed-based section index (+0xDC) can DIVERGE — the player may select
gear 1 while +0xDC says section 3 (because speed is still high). The
game may use +0xDE to override the gear ratio lookup in manual mode,
or +0xDE may affect a different computation path entirely.

### Save State Used
- `daytona_manual_trans.8180a74b2162ad4393a9630de58615e3.mc0`
- Mode: Race, 40 cars, Three Seven, manual transmission, ~179 mph
