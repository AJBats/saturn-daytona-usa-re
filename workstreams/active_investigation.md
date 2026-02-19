# ICF Root Cause Investigation

> **Status**: ACTIVE
> **Symptom**: Slave SH-2 crashes at 0x06028296 (panic trap) after first ICF trigger in free build
> **Bypass**: `ICF_FIX=1` — NOPs the master's `bf -7` poll loop in patches/FUN_0600C010.s
> **Prior work**: workstreams/icf_investigation.md (mechanism documented, root cause not found)

## The Problem

In the free-layout build (+4 shift), the slave SH-2's callback (FUN_0600C170) crashes
on its first invocation. The slave hits a panic trap (`SETT; BT $`) at 0x06028296
inside FUN_06027EDE. Since the slave never completes, it never writes SINIT, so the
master hangs forever at the ICF poll.

**This is real code breakage from the +4 shift**, not an emulator bug (unlike SCDQ).

## What We Know

- All code is byte-identical to production — the shift doesn't change instruction bytes
- The crash is caused by **incorrect data state** in RAM when the callback runs
- FUN_0600C170 calls: FUN_0603BF22, FUN_0600B340, FUN_0600AFB2, FUN_0600B914, FUN_06006A9C/FUN_06006CDC
- The panic trap is at 0x06028296: `sett; bt $` (standard SH-2 halt pattern)
- Production: alternating MINIT/SINIT every frame. Reimpl: 178x MINIT, 0x SINIT.

## Key Question

**Why does a +4 code shift cause wrong data state?**

Most likely: some function earlier in the boot sequence has a PC-relative data reference
or embedded absolute address that doesn't get relocated in the shifted build. This would
cause init code to read/write wrong memory, leaving RAM in a bad state for the slave callback.

## Investigation Plan

1. Reproduce the crash without the bypass
2. Compare RAM state at the moment of first ICF trigger (prod vs free)
3. Trace FUN_0600C170's call chain to find which data read is wrong
4. Walk backwards to find the init function that wrote the wrong data
5. Identify the non-relocatable reference causing the corruption

## Log

*(investigation entries go here)*
