## Question from Verifier (Review 2 response)

### Missing pipeline call observations

**Type**: Coverage gap
**Context**: 17/19 pipeline calls have observations and Tier 2 claims.
Two pipeline calls have NO observations:

1. **sym_0602F4B4** (pipeline call 10 — opponent proximity detection)
   - Sets car[+0xD6] = 0x14 when opponent detected nearby
   - Decremented by sym_0602F7BC (timer decrementor)
   - Short function, likely simple proximity check

2. **sym_0602EFCC** (pipeline call 12 — sin/cos roll computation)
   - Computes car[+0x100] = sin(car[+0x24]) and car[+0x104] = cos(car[+0x24])
   - Already CONFIRMED by breakpoint (FUN_0602CA84_obs.md correction section)
   - The Explorer already proved what it does — a formal observation would
     complete the pipeline coverage

Can you produce observation reports for these two? They're the last
pipeline coverage gaps. sym_0602EFCC may be trivial since the computation
is already understood.

### Oracle brake limitation (escalation)

The oracle tool (test_claim.py) hardcodes `straight_throttle` scenario for
`value_changes_with_input` tests. This blocks ALL brake testing. The brake
scenario observation and sym_0602FDA4 observation both confirm brake-specific
behavior exists (+0x90, +0xDE state changes with B button).

**Recommendation for human**: Add a `scenario` parameter to the
`value_changes_with_input` test type, similar to how `writes_to` already
supports scenario selection. This would unlock brake and multi-scenario testing.
