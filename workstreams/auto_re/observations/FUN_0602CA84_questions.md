## Question from Verifier

### Watchpoint system does not catch writes to multiple car struct fields

**Type**: Oracle limitation / systemic issue
**Function**: FUN_0602CA84
**Affected fields**: car[+0xC0], car[+0x108], car[+0x148]

The oracle's watchpoint system returns 0 hits for these addresses across both
straight_throttle and race_throttle scenarios (60 frames each). The writer map
(mem_profile) clearly shows these fields are written every frame:

| Field | Address | Writer PC | Writes (comprehensive) |
|-------|---------|-----------|----------------------|
| +0xC0 | 0x060789C0 | 0x0602CC46 | 493/493 |
| +0x108 | 0x06078A08 | 0x0602CB3C | 493/493 |
| +0x148 | 0x06078A48 | 0x0602CAE0 | 493/493 |

Fields that DO work with watchpoints: +0xFC (0x060789FC), +0x50 (0x06078950),
+0x10 (0x06078910 — untested but expected to work based on FUN_0602EEB8 results).

This pattern suggests the Mednafen watchpoint system has selective coverage. The
mem_profile tool captures writes that watchpoints miss.

**Can you**:
1. Set a watchpoint on 0x060789C0 (car[+0xC0]) in straight_throttle for 10 frames
   and confirm whether you see hits or not
2. If no hits: check whether the write at PC 0x0602CC46 is a `mov.w` (16-bit) or
   `mov.l` (32-bit) instruction — byte-size writes may bypass watchpoints
3. Consider whether mem_profile is more reliable than watchpoints for writes_to
   verification

**Impact on Tier assignment**: FUN_0602CA84 is stuck at Tier 1 (call_count +
accel_delta_increases pass, but no writes_to claims pass). The function clearly
writes car[+0xFC] but the profiler records the return-target PC (0x0602EF4E)
rather than the delay slot PC, placing it outside FUN_0602CA84's address range.
