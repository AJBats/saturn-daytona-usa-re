# CD_FIX: Implementation, Bug, and Correct Guard Condition

## What CD_FIX Does

`CD_FIX=1` replaces `FUN_0603B424` with `reimpl/patches/FUN_0603B424.c`.
The C patch widens the "proceed to Calculate" condition in FUN_0603B424's
default path from `status == 2 (STANDBY)` to `status == 2 || status == 1 (PAUSE)`.

This is meant to fix the TABLE.BIN deadlock: when the drive enters "play end
pause" with all 14 sectors pre-buffered, the PAUSE handler falls through to
the default path, which (with the fix) proceeds to Calculate and reads the
buffered sectors.

## The Patch (patches/FUN_0603B424.c)

Key logic:
```c
case 1:  /* PAUSE */
{
    int bufret = GetBufSize(ctx);
    if (bufret == 1) {
        /* [Note: this is the original Calculate condition — retval==1 means
         * buffer ready. The comment says "buffer empty" but assembly shows
         * this actually branches to CALCULATE in original code.] */
        ctx[0x12] = 0xE8;
        return FUN_0603B93C(-24);
    }
    /* FIX: fall through to default path */
    break;
}

/* Default path: */
{
    int bdac_ret = FUN_0603BDAC(ctx);
    if ((saved_status == 2 || saved_status == 1) && bdac_ret == 5) {
        /* CALCULATE sequence */
        int subchan = *(int *)(ctx + 8);
        int calc_size = sym_0603F9F2(subchan);
        int actual_size = sym_0603F9F6(subchan);
        FUN_0603AFD0(ctx, calc_size - actual_size, 1);
        ctx[0x12] = 0;   /* ← state = DONE */
        FUN_0603B8B4(ctx);
        FUN_0603B8F8(ctx);
        FUN_0603B9D6(ctx);
    }
}
```

## The Conditional Logic Inversion

**From assembly analysis** (see `04_fun_0603b424_decode.md`):
- `GetBufSize retval == 1` → bt TAKEN → branch to CALCULATE path (+0xC4)
- `GetBufSize retval != 1` → fall through → state=0xE8, return retry

**The patch has this inverted**:
- `bufret == 1` → state=0xE8, return (what should be Calculate!)
- `bufret != 1` → fall through to FIX path

**Why it still works for TABLE.BIN (mostly)**:
In the TABLE.BIN pre-buffered case, `GetBufSize` returns some non-1 value
(186 free buffers, not "retval==1"). So the inverted branch never fires for
that specific case. The FIX path triggers correctly.

**Why it breaks the APROG.BIN load**:
See secondary bug below.

## The Secondary Bug: Triggers on APROG.BIN Load

The widened default path condition `(status == 1 || status == 2) && bdac_ret == 5`
fires not only for TABLE.BIN but also for the APROG.BIN initial file load.

**Evidence from CDB log**:
```
Both builds identical through cmd #67:
  Get and Delete Sector Data; Count=0xC1 → Results: 4180 4101 0100 016c

Production cmd #68: End Data Transfer
Free (CD_FIX) cmd #68: (nothing — log ends at 32 commands)
```

**What happens**: After `Get and Delete Sector Data Count=0xC1`, the state
machine is called again. Drive is in PAUSE (from the play-end-pause after
initial file read). The widened condition fires → sets `ctx[0x12] = 0` (DONE)
→ FUN_0603B21C exits its retry loop → `End Data Transfer` is never issued.

## The Correct Fix

The guard condition must distinguish:
1. **TABLE.BIN play-end-pause**: PAUSE with pre-buffered sectors that need Calculate
2. **APROG.BIN mid-transfer PAUSE**: PAUSE that occurs during/after `Get and Delete Sector Data`

**Key distinguishing factor**: `ctx[0x12]` (the state byte).

When FUN_0603B424 is called after `Get and Delete Sector Data Count=0xC1`,
the state byte `ctx[0x12]` has a specific value (the "confirm transfer" state).
When it's called during TABLE.BIN loading waiting for sectors, `ctx[0x12]` has
a different specific value (the "wait for sectors" state).

**Implementation approach**:
```c
case 1:  /* PAUSE */
{
    /* Only widen to Calculate if we're in the "waiting for sectors" state,
     * not in the "confirming a completed bulk transfer" state */
    unsigned char current_state = ctx[0x12];

    int bufret = GetBufSize(ctx);
    if (bufret == 1) {
        /* Normal Calculate path */
        goto calculate_path;  /* or equivalent */
    }

    /* FIX: check if we're in the TABLE.BIN waiting state */
    if (current_state == TABLE_BIN_WAIT_STATE) {
        /* fall through to default path which will Calculate */
        break;
    }

    /* Normal PAUSE retry */
    ctx[0x12] = 0xE8;  /* actually 0x1B per assembly? */
    return FUN_0603B93C(-24);
}
```

**To find `TABLE_BIN_WAIT_STATE`**: Add CDB logging to print `ctx[0x12]` when
the PAUSE handler fires. Compare the state value during TABLE.BIN loading
(the case to fix) vs during APROG.BIN loading (the case to NOT fix).

## How to Find the Guard Value

Add to the PAUSE handler in FUN_0603B424.c:
```c
case 1:  /* PAUSE */
{
    /* DEBUG: print ctx[0x12] to help find guard condition */
    extern void SS_DBG(unsigned which, const char* fmt, ...);
    /* or just fprintf(stderr, ...) */
    unsigned char state = ctx[0x12];
    /* Log state value and sector count */
    int sector_count = /* CR4 from last Get Sector Number */;
    fprintf(stderr, "[CD_FIX debug] PAUSE: ctx[0x12]=0x%02X sectors=%d\n",
            state, sector_count);
    ...
}
```

Run both production and free builds through the initial load sequence.
The state value when TABLE.BIN PAUSE fires (free build, cmd #2201+) will be
different from when APROG.BIN PAUSE fires (free build, cmd #67+).

## Build Status

Current state (2026-02-19):
- `patches/FUN_0603B424.c` exists but has the secondary bug
- `SCDQ_FIX=1 ICF_FIX=1 CD_FIX=0` is the known-working configuration
- CD_FIX needs the guard condition before use

To build with current CD_FIX (for debugging only):
```bash
make -C reimpl LDSCRIPT=sawyer_free.ld ICF_FIX=1 SCDQ_FIX=0 CD_FIX=1
make -C reimpl disc
```
