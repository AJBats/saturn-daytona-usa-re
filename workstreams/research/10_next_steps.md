# Next Steps: Prioritized Action Plan

## Immediate Priority: Fix CD_FIX Guard Condition

**Goal**: Make CD_FIX work without triggering on APROG.BIN initial load.

**The problem**: CD_FIX fires at command #67 (APROG.BIN mid-transfer), preventing
`End Data Transfer` from being issued. Need to guard on `ctx[0x12]` state value
that's specific to the TABLE.BIN "wait for sectors" state.

### Step 1: Instrument ctx[0x12] logging

Add stderr print in `patches/FUN_0603B424.c` PAUSE case:
```c
case 1:  /* PAUSE */
{
    fprintf(stderr, "[CD_FIX] PAUSE: ctx[0x12]=0x%02X\n", ctx[0x12]);
    ...
}
```

Run `diag_cdb_commands.py --frames 2000` with CD_FIX=1.
Look at the log for when PAUSE fires:
- At command #67 (APROG.BIN load): `ctx[0x12] = ???`  ← DON'T fix this
- At command #2201+ (TABLE.BIN load): `ctx[0x12] = ???`  ← FIX this

### Step 2: Add the guard

```c
case 1:  /* PAUSE */
{
    unsigned char state = ctx[0x12];
    int bufret = GetBufSize(ctx);
    if (bufret == 1) {
        goto calculate_path;  /* original behavior */
    }
    /* Only apply fix for specific state */
    if (state == TABLE_BIN_WAIT_STATE) {
        break;  /* fall through to default path → Calculate */
    }
    ctx[0x12] = 0xE8;
    return FUN_0603B93C(-24);
}
```

### Step 3: Test

```bash
make -C reimpl LDSCRIPT=sawyer_free.ld ICF_FIX=1 SCDQ_FIX=0 CD_FIX=1
make -C reimpl disc
python3 tools/diag_cdb_commands.py --frames 2000
```

If `End Data Transfer` appears at command #68 → fix is working.
Check that full Calculate loop appears at command #2201+.

---

## Investigation Plan (from scdq_investigation_plan.md)

### Inv 1: Is SCDQ Pre-Armed?

**Hypothesis**: The game enters FUN_060423CC with SCDQ already set from a
preceding CD operation. The poll is for confirmation, not waiting.

**Method**: Count poll iterations. Add POLL_EXIT trace to CDB logging.
If production always exits in 1-2 iterations → SCDQ was pre-armed = state bug.

**How**: Extend `CDB_EnableSCDQTrace` to also count READ iterations per SCDQ period.
Add a `POLL_EXIT <sh2_ts> <iterations>` event: written when SCDQ is seen
in CDB_Read (after a SET event), logging how many reads were needed.

### Inv 2: Second Emulator (Kronos/Yabause)

**Hypothesis**: Everything we see on Mednafen might be emulator-specific.
Test on Kronos (independent CD Block implementation) to validate.

**Method**:
```bash
# In WSL:
git clone https://github.com/FCare/Kronos.git
cd Kronos && mkdir build && cmake .. && make -j$(nproc)
# Test free disc (ICF+SCDQ) → should boot
# Test free disc (ICF only) → does it hang same way?
```

If Kronos also hangs → binary bug (confirmed)
If Kronos works → Mednafen CDB timing artifact

### Inv 3: 0x034d vs 0x034f Propagation

**Hypothesis**: The 2-unit FAD difference at command #491 is just noise.

**Method**: Read `FUN_0603B424.s` carefully. Find where End Data Transfer CR2
is processed. Does 0x034d vs 0x034f cause different branching?

**Likely outcome**: It's noise. Both builds have 1700+ identical commands after
the divergence. Low priority.

### Inv 4: CD Code Quarantine (sawyer_cd_frozen.ld)

**Hypothesis**: The engine core (0x06034036–0x06047048) needs to stay at
production addresses. Only post-CD code can shift.

**Method**: Create `reimpl/sawyer_cd_frozen.ld`:
- Pre-CD code (0x06003100–0x06034036): at production addresses (no shift)
- CD engine core (0x06034036–0x06047048): at production addresses
- Post-CD code (0x06047048–0x06063690): +4 shift

If boots → confirms timing sensitivity + gives architecture for working free build.

**Implementation challenge**: The current `SORT_BY_NAME` approach doesn't
support splitting functions into pre/post groups. Would need to explicitly
name the sections or use address-based splitting.

---

## ICF Bug: Still Open

The secondary SH-2 crash in FUN_0600C170 (hits panic trap 0x06028296) is due to
wrong data state when the callback runs. The specific init functions that fail
to set up the required data have not been identified.

**To investigate**:
1. Without ICF_FIX, capture the secondary PC at panic trap
2. Dump secondary registers at 0x06028296
3. Stack trace: which function called which
4. The call chain: FUN_06034F08 → secondary ICF detected → FUN_0600C170 → crash
5. FUN_0600C170 calls: FUN_0603C000, FUN_0600B340, FUN_0600AFB2, FUN_0600B914
6. Which one crashes and why?

This is a separate investigation from SCDQ/CD.

---

## Quick Reference: Key Commands

```bash
# Rebuild known-working free build
make -C reimpl LDSCRIPT=sawyer_free.ld ICF_FIX=1 SCDQ_FIX=1 CD_FIX=0
make -C reimpl disc  # inject (verify .build_config first)

# Run CDB diagnostic
python3 tools/diag_cdb_commands.py --frames 1000

# Run SCDQ trace diagnostic
python3 tools/diag_scdq_state.py --trace-start 680 --max-frame 695

# Check what's built
cat reimpl/build/.build_config   # Linux/WSL
# or
type "reimpl\build\.build_config"  # Windows
```

---

## Files of Interest

| File | Purpose |
|------|---------|
| `reimpl/patches/FUN_060423CC.c` | SCDQ_FIX: force-ack after 1000 polls |
| `reimpl/patches/FUN_0603B424.c` | CD_FIX: PAUSE handler (has secondary bug) |
| `reimpl/patches/FUN_0600C010.s` | ICF_FIX: NOP the bf -7 secondary poll |
| `reimpl/sawyer_free.ld` | Free build linker script (+4 shift) |
| `tools/diag_cdb_commands.py` | CDB command sequence comparison |
| `tools/diag_scdq_state.py` | SCDQ trace analysis |
| `tools/parallel_compare.py` | MednafenInstance base class |
| `workstreams/scdq_hypothesis_2.md` | Root cause analysis |
| `workstreams/scdq_investigation_plan.md` | 4 investigations |
| `docs/mednafen_debug_tools.md` | Tool reference |
| `workstreams/research/` | This directory (all learnings) |
