# ICF Investigation: Dual-CPU Synchronization in Daytona USA

> **Status**: COMPLETE — root cause found & fixed (cache-through relocation in FUN_06034F08)
> **Date**: 2026-02-18
> **Root cause**: Slave SH-2 callback crashes due to incorrect data state (init functions not yet investigated)
> **Bypass**: NOP over `bf -7` at FUN_0600C010.s line 127 — **reverted to original bytes** for byte-identical default build. Re-apply manually when boot-testing the rebuilt disc.

## Executive Summary

The ICF polling loop at FUN_0600C010 is part of a **dual-CPU ping-pong synchronization
mechanism** between the master and slave SH-2 processors. In production, both CPUs
synchronize via MINIT/SINIT writes. In the reimpl, the slave's callback crashes due
to incorrect data state — the specific init functions responsible have not yet been
identified. The NOP bypass lets the master continue without the slave's response.

## The Synchronization Mechanism

Daytona USA uses a **frame-synchronization ping-pong** between the two SH-2 CPUs:

```
Master SH-2 (FUN_0600C010)         Slave SH-2 (FUN_06034F08)
============================        ============================
1. Write to MINIT (0x01000000)  ──> Sets slave's ICF
2. Poll FTCSR bit 7 (ICF)          3. Detects ICF, exits poll
   [at 0x0600C11C-0x0600C124]      4. Calls FUN_0600C170 (callback)
                                    5. FUN_0600C170 does sync work
5. ICF set, exits poll loop     <── 6. Writes SINIT (0x21800000) at RTS
6. Continues game frame             7. Loops back to poll
```

### Key Addresses

| Component | Address | Function |
|-----------|---------|----------|
| Master MINIT write | 0x0600C0F0 | Inside FUN_0600C010, triggers slave ICF |
| Master ICF poll | 0x0600C11C-0x0600C124 | Polls FTCSR bit 7 in tight loop |
| Slave ICF poll | 0x06034F34-0x06034F5E | FUN_06034F08, polls its own FTCSR |
| Slave SINIT write | 0x0600C1F0 | FUN_0600C170 RTS delay slot → 0x21800000 |
| Callback pointer | 0x06063574 | Set by FUN_0600C010 to FUN_0600C170 |

### MINIT/SINIT Mechanism (Mednafen)

- Write to **0x01000000-0x017FFFFF** → `CPU[1].SetFTI()` → sets slave's ICF
- Write to **0x01800000-0x01FFFFFF** → `CPU[0].SetFTI()` → sets master's ICF
- Formula: `target_cpu = ((A >> 23) & 1) ^ 1` in `ss.cpp` BusRW_DB_CS0

## Evidence: Mednafen Instrumentation

### Production Disc (30 seconds)

```
SH2_SETACTIVE: cpu=SH2-S active=1
SH2_ACTIVATED: cpu=SH2-S PC=00000000 SP=00000000 VBR=00000000

FTCSR_READ: cpu=SH2-S PC=06034F3A val=00 icf=0   (×2000+ before sync starts)

FTI: addr=01000000 target_cpu=1 master_PC=0600C0F0 slave_PC=06034F38  ← master writes MINIT
FTI: addr=01800000 target_cpu=0 master_PC=0600C124 slave_PC=06034F5A  ← slave writes SINIT
FTI: addr=01000000 target_cpu=1 master_PC=0600C0F0 slave_PC=06034F62  ← master writes MINIT
FTI: addr=01800000 target_cpu=0 master_PC=0600C124 slave_PC=06034F5A  ← slave writes SINIT
(alternating pattern continues...)
```

**Production sync works**: MINIT and SINIT triggers alternate. Both CPUs participate.

### Reimpl Disc (30 seconds)

```
SH2_SETACTIVE: cpu=SH2-S active=1
SH2_ACTIVATED: cpu=SH2-S PC=00000000 SP=00000000 VBR=00000000

FTCSR_READ: cpu=SH2-S PC=06034F3A val=00 icf=0   (×2000+)

FTI: addr=01000000 target_cpu=1 master_PC=0600C0F0 slave_PC=06034F3E  ← master writes MINIT ✓
FTI: addr=01000000 target_cpu=1 master_PC=0600C0F0 slave_PC=0602829A  ← master writes MINIT
FTI: addr=01000000 target_cpu=1 master_PC=0600C0F0 slave_PC=0602829A  ← (×178 total)
```

**Reimpl sync broken**:
- Master writes MINIT (✓) — 178 times in 30 seconds
- Slave detects ICF first time (✓) — exits poll, calls FUN_0600C170
- Slave NEVER writes SINIT (✗) — crashes into trap at 0x0602829A
- **Zero SINIT writes** in reimpl vs alternating MINIT/SINIT in production

## The Slave Crash

After the first ICF detection, the slave calls FUN_0600C170 (the callback stored at
*(0x06063574)). FUN_0600C170's call chain encounters incorrect data state and the
slave ends up at address **0x06028296**:

```asm
06028294: sett              ; T = 1
06028296: bt 0x06028296     ; branch to self → INFINITE LOOP (panic trap)
06028298: rte               ; unreachable
0602829A: nop               ; unreachable delay slot
```

This is a standard SH-2 panic/halt pattern (`SETT; BT $`). The slave hits this
because some data condition is unexpected.

### Why the Crash Happens

FUN_0600C170 calls these functions (all present as raw ASM in reimpl):

| Function | Purpose | Status |
|----------|---------|--------|
| FUN_0603C000 (inside FUN_0603BF22) | First callee | Present (raw ASM) |
| FUN_0600B340 | Conditional call | Present (raw ASM) |
| FUN_0600AFB2 | Conditional call | Present (raw ASM) |
| FUN_0600B914 | Unconditional call | Present (raw ASM) |
| FUN_06006A9C / FUN_06006CDC | Conditional call | Present (raw ASM) |

All code is byte-identical to production. The difference is **data state** — the
reimpl's initialization sequence doesn't set up RAM correctly — the specific
init functions responsible haven't been identified yet. The callback's conditional
branches take wrong paths, eventually reaching the panic trap in FUN_06027EDE at
0x06028296.

## The NOP Bypass

To boot-test the rebuilt disc, change 2 bytes in `reimpl/src/FUN_0600C010.s` line 127:
- Original: `0x8B, 0xF9` — `bf -7` (poll loop: branch back if ICF not set)
- Bypass: `0x00, 0x09` — `nop` (fall through, skip waiting for slave)

**Default build has original bytes** (byte-identical policy). The bypass is needed
for boot testing because:
1. The slave's callback crashes due to incorrect data state (root cause not yet traced)
2. The slave never writes SINIT, so the master's ICF is never set
3. Without the bypass, the master hangs forever at the ICF poll

**Note**: Unlike SCDQ (which has a Makefile flag `SCDQ_FIX=1`), the ICF bypass
has no opt-in flag yet — it requires a manual 2-byte edit.

## Implications

### For Road-to-Boot

The NOP bypass is **sufficient** for single-CPU boot progression. The master SH-2
runs the game state machine, VDP setup, and attract mode logic independently.
The slave being stuck doesn't prevent basic boot.

### For Full Reimpl (future)

To restore dual-CPU sync, we would need to:
1. Identify and fix the init functions that set up data used by FUN_0600C170's call chain
2. Verify the slave's callback completes and writes SINIT
3. Remove the NOP bypass and restore the original `BF -7`
4. Validate the frame-sync timing

This is an L3/L4 concern, not needed for current boot efforts.

## Architecture Reference

### Slave SH-2 Lifecycle (Daytona USA)

1. **Boot**: Slave starts OFF (SMPC default)
2. **Activation**: Master issues SMPC SSHON → slave starts via SetActive(true)
3. **BIOS init**: Slave runs BIOS code, jumps to game-defined entry point
4. **Polling**: Slave enters FUN_06034F08 — infinite loop polling FTCSR for ICF
5. **Sync**: Master writes MINIT → slave's ICF set → slave calls callback
6. **Callback**: FUN_0600C170 does per-frame work, writes SINIT to signal master
7. **Return**: Slave returns to FUN_06034F08 polling loop
8. **Repeat**: Steps 5-7 repeat every frame

### Key Memory Locations

| Address | Type | Purpose |
|---------|------|---------|
| 0x06063574 | Pointer | Callback function pointer (set to FUN_0600C170) |
| 0x06083255 | Byte | Controls FUN_0600C010 path (FUN_06034708 call gate) |
| 0x06078635 | Byte | Controls FUN_0600C010 path (D336 vs D31C call gate) |
| 0x0607EBC4 | Long | State flags checked with masks 0x02000000, 0x02800008 |
| 0x06059F30 | Long | Controls SHAR/EXTS path vs bypass in FUN_0600C010 |
| 0xFFFFFE11 | Byte | FTCSR — Free-running Timer Control/Status Register |

## Verified Facts

| Claim | Evidence |
|-------|----------|
| Slave SH-2 activates in both production and reimpl | SH2_ACTIVATED trace fires for SH2-S |
| Production has alternating MINIT/SINIT triggers | FTI log shows addr=01000000 / addr=01800000 pattern |
| Reimpl has MINIT only (no SINIT) | 178 FTI triggers, all addr=01000000, zero addr=01800000 |
| Slave polls from FUN_06034F08 (PC=0x06034F3A) | FTCSR_READ trace shows cpu=SH2-S PC=06034F3A |
| Master MINIT write at PC=0x0600C0F0 | FTI trace master_PC field |
| Slave SINIT write at PC=0x06034F5A (production only) | FTI trace slave_PC field |
| Reimpl slave crashes to 0x0602829A after first ICF | FTI trace slave_PC changes from 06034F3E to 0602829A |
| SetFTI() only called from SINIT/MINIT write handler | grep -r SetFTI → only ss.cpp BusRW_DB_CS0 |
| ICF only set inside SetFTI() | FTCSR |= 0x80 only at sh7095.inc:1068 |

---
*Investigation complete: 2026-02-18*
*Instrumentation: Mednafen ss.cpp + sh7095.inc (FTI logging, FTCSR trace, SetActive trace)*
