# Research Index: Daytona USA Saturn Free Build Investigation

> Session: 2026-02-19
> Investigator: Claude Sonnet 4.6 (1M context)
> Goal: Free build (sawyer_free.ld +4 shift) that boots Daytona USA

---

## Quick Start

The known-working free build:
```bash
make -C reimpl LDSCRIPT=sawyer_free.ld ICF_FIX=1 SCDQ_FIX=1 CD_FIX=0
make -C reimpl disc
# Test: external_resources/mednafen-1.32.1-win64/mednafen.exe
```

The immediate next task:
→ Fix `patches/FUN_0603B424.c` guard condition (see file 06 and 10).

---

## File Index

| File | Contents | Priority for 200k model |
|------|----------|------------------------|
| `01_free_build_mechanics.md` | How the +4 shift works, linker scripts, what relocates | HIGH — context for everything |
| `02_cd_block_hardware.md` | HIRQ register, SCDQ bit, Saturn CD Block spec | HIGH — needed for CD bug understanding |
| `03_bugs_found.md` | All three bugs: ICF, SCDQ timing, CD PAUSE handler | CRITICAL — the root causes |
| `04_fun_0603b424_decode.md` | Complete ASM decode of the CD state machine | HIGH — needed for CD_FIX fix |
| `05_cdb_command_sequences.md` | Command logs, divergence points, evidence | HIGH — debugging evidence |
| `06_cd_fix_implementation.md` | The patch, its bug, correct guard condition | CRITICAL — what to fix next |
| `07_mednafen_cdb_internals.md` | PeriodicIdleCounter, event system, observer effects | MEDIUM — emulator internals |
| `08_binary_layout_map.md` | What every function in the binary does | MEDIUM — orientation |
| `09_test_matrix.md` | What was tested, what worked | HIGH — avoid repeating experiments |
| `10_next_steps.md` | Prioritized action plan | CRITICAL — what to do |
| `11_key_addresses.md` | All critical addresses, disc FADs, hardware regs | HIGH — quick reference |

---

## Three-Sentence Summary

The free build (+4 shift) fails because a 4-byte timing change causes the
disc to enter "play end pause" with all TABLE.BIN sectors pre-buffered before
the CD state machine can process them. The CD state machine's PAUSE handler
in `FUN_0603B424` only proceeds to read sectors when `GetBufSize returns 1`
(buffer empty), which is never true when 14 sectors are pre-buffered. The
current workaround (`SCDQ_FIX=1`) shortens the SCDQ poll so the disc doesn't
advance past TABLE.BIN's end FAD; the real fix is to patch `FUN_0603B424`'s
PAUSE handler to also proceed when sectors are available (with a guard on
`ctx[0x12]` state value to avoid breaking the APROG.BIN initial load).

---

## Current Binary State

After this session, the reimpl build directory contains:
- `build/.build_config`: `LDSCRIPT=sawyer_free.ld SCDQ_FIX=1 ICF_FIX=1 CD_FIX=0`
- `build/APROG.BIN`: 394,880 bytes (known-working free build)
- `build/disc/rebuilt_disc/daytona_rebuilt.cue`: disc with current binary injected

## Mednafen State

After this session, the Mednafen debug build has:
- `config.h`: `MDFN_ENABLE_DEV_BUILD 1` (enabled for SS_DBG_CDB logging)
- `ss.cpp`: `ss_dbg_mask |= SS_DBG_CDB` (CDB logging always on in debug build)
- `cdb.cpp`: SCDQ trace stubs implemented (CDB_EnableSCDQTrace, CDB_DisableSCDQTrace)
- `ss.cpp`: FTI logging removed (was observer effect)
- `ss.cpp`: BusRW_DB_CS0 canary removed (was observer effect)

---

## Hypotheses (for the 200k model to reason about)

### H1: SCDQ is always pre-armed (Investigation 1)
The game enters FUN_060423CC with SCDQ already set. The poll is confirmation,
not waiting. If true: 1-2 iterations in production → state bug not timing bug.

### H2: Mednafen CDB timing inaccuracy (see H4)
Mednafen fires SCDQ in all drive states; real hardware doesn't. The timing
issue is real (confirmed by real Saturn failure) but the mechanism differs.

### H3: CD state machine behavioral bug (CONFIRMED)
FUN_0603B424's PAUSE handler doesn't handle "play end pause with pre-buffered
sectors". This is the root cause. CD_FIX addresses this but has a secondary bug.

### H4: Sega CD code quarantine (Investigation 4)
Sega may have kept the engine core (0x06034036–0x06047048) at fixed addresses
in their linker script. A sawyer_cd_frozen.ld that only shifts post-CD code
might boot without any code patches.

### H5: 0x034d vs 0x034f propagation (Investigation 3)
The 2-unit FAD difference at command #491 is likely noise (both builds run
1700+ identical commands after). Low priority to investigate.
