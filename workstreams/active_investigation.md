# Active Investigation: SCDQ Root Cause

> **Status**: Active — root cause investigation
> **Bypass exists**: `reimpl/patches/FUN_060423CC.c` — timeout + forced ack. NOT a fix.
> **Goal**: Understand WHY SCDQ never fires in the free-layout build, and fix the cause.

## The Question

In the free-layout build (+4 byte shift), `FUN_060423CC` polls HIRQ bit 10 (SCDQ)
forever. In production, SCDQ fires normally. Why?

SCDQ = "Subcode Q data ready" — the CD Block signals it finished a data query.

## What We Know

### The poll function
- **FUN_060423CC** (prod: 0x060423CC, reimpl: 0x060423D0)
- Reads HIRQ via `sym_06035C4E()`, checks bit 10 (0x0400)
- If set: calls `FUN_06035C54(~0x0400)` to acknowledge, returns
- If not set: loops forever

### The caller
- **FUN_0603B21C** (prod: 0x0603B21C, reimpl: 0x0603B220)
- Calls FUN_060423CC, then has a BRA retry loop
- The retry loop checks if SCDQ was acknowledged
- Source: `reimpl/src/FUN_0603B21C.s` (65 lines of .byte ASM)

### CD Block registers
- HIRQ: `0x25890008` (interrupt request flags, bit 10 = SCDQ)
- CR1-CR4: `0x25890018-0x2589001E` (command registers)
- The CD Block is a separate SH1 processor with its own command protocol

### The bypass (DO NOT LEAN ON THIS)
- `reimpl/patches/FUN_060423CC.c` — polls 1000 times, then force-acks
- This WORKS (game boots, menus match production) but hides the real issue
- Committed in `dc64817` — should be replaced once root cause is found

## What We Don't Know

1. **What CD command does FUN_0603B21C issue before polling SCDQ?**
   - Haven't analyzed FUN_0603B21C instruction-by-instruction
   - Need to decode the .byte ASM and identify CR1-CR4 writes

2. **Is the command being sent in the reimpl?**
   - Never compared CD Block register state between builds
   - Need: breakpoint at FUN_0603B21C entry, dump CR1-CR4 in both builds

3. **Is this a timing issue or a command issue?**
   - If command is sent identically, it's timing (CD Block needs specific wait)
   - If command is different/missing, something upstream broke

4. **What calls FUN_0603B21C?**
   - Part of boot init chain — need to trace the call hierarchy

## Investigation Plan

### Step 1: Decode FUN_0603B21C
Read `reimpl/src/FUN_0603B21C.s`, decode every instruction. Identify:
- What CD Block commands (CR1-CR4 writes) it issues
- What other functions it calls before FUN_060423CC
- What the retry loop actually checks

### Step 2: Instrument both builds
Set breakpoints in both production and reimpl at:
- FUN_0603B21C entry
- Just before the FUN_060423CC call
Dump CD Block registers (HIRQ, CR1-CR4) at each point.

### Step 3: Compare and hypothesize
With register dumps from both builds:
- Are the same commands being sent?
- Is HIRQ in the same state?
- What's different?

### Step 4: Fix the cause
Based on findings, fix the actual issue — not the symptom.

## Key Addresses

| Symbol | Production | Reimpl (+4) | Purpose |
|--------|-----------|-------------|---------|
| FUN_060423CC | 0x060423CC | 0x060423D0 | SCDQ poll (the symptom) |
| FUN_0603B21C | 0x0603B21C | 0x0603B220 | Caller with retry loop |
| FUN_06035C54 | 0x06035C54 | 0x06035C58 | SCDQ acknowledge |
| sym_06035C4E | 0x06035C4E | 0x06035C52 | HIRQ read |
| HIRQ register | 0x25890008 | 0x25890008 | CD Block interrupt flags |
| CR1 | 0x25890018 | 0x25890018 | CD Block command reg 1 |

## Build Commands

```bash
# Build with bypass (current workaround):
cd reimpl && make free

# Build WITHOUT bypass (to reproduce the hang):
cd reimpl && make LDSCRIPT=sawyer_free.ld
```

## Rule

> **No bypass commits without root cause.** A bypass is a diagnostic tool, not a fix.
> If you find yourself writing a workaround, you've found the symptom — now find the cause.

---
*Created: 2026-02-18*
