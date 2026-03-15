## Question from Verifier

### 1. Breakpoint double-hit at FUN_0602EEB8

**Type**: Oracle clarification
**Claim**: call_count_throttle, expected 1, oracle measured 2
**Observation says**: 1 call per frame in both scenarios
**Oracle says**: Breakpoint at 0x0602EEB8 fires at both PC 0x0602EEB8 AND PC 0x0602EEBA (next instruction, +2 bytes) within the same frame.

This appears to be a Mednafen breakpoint behavior where a single breakpoint address
triggers on two consecutive SH-2 instructions. The claim was adjusted to expected_count: 2
to match the oracle. Not a real discrepancy — just a breakpoint implementation detail.

No action required unless you see a different explanation.

### 2. car[+0x252] watchpoint gets 0 hits

**Type**: Oracle contradiction
**Claim**: writes_frame_counter (removed), 0 hits at 0x06078B52
**Observation says**: +0x252 has 10 unique values (0-9) across 300 frames in tt_throttle_300f.csv
**Oracle says**: Watchpoint at 0x06078B52 got 0 hits in 60 frames of straight_throttle

The field clearly changes in the per-frame CSV captures (from sample_memory), but
the watchpoint system doesn't catch the write. Hypotheses:
1. The write is a `mov.b` (byte write) and the watchpoint doesn't catch byte-size writes
2. The write is from DMA or the secondary SH-2 (not caught by primary CPU watchpoints)
3. The field value only changes at specific frame intervals not covered in 60 frames

Can you set a watchpoint on 0x06078B52 in straight_throttle for 300 frames and check
if any hits appear? If not, check if the writer PC 0x0602EED8 is a `mov.b` instruction.
