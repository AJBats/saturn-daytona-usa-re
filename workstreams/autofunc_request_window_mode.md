# autofunc feature request — window mode (island coverage)

**Date**: 2026-06-12
**Requesting project**: SaturnReverseTest (Daytona '95 / DUSA)
**Target**: SaturnAutoRE eval tool (`eval_server.py` / `analyzer.py`)
**Driver**: the embedded-DUSA transplant
(`DaytonaCCEReverse/workstreams/transplant/embedded_design.md`) needs
port-grade function boundaries for ~25 KB of the DUSA binary — a few
specific regions, not full coverage.

## Problem

The tool is built around a forward sweep from `vram` with a
no-internal-gaps invariant: every byte from the load address up to the
sweep frontier must be stamped, and the red gap banner fires on any
uncovered range between stamps. That was right for CCE race.bin
(100% coverage was the goal). For DUSA we want to verify a handful of
**windows** in the middle of a large binary and leave everything else
unswept indefinitely. Today that's impossible without either stamping
from 0x06000000 all the way to each region of interest, or polluting
the yaml with a giant fake "placeholder" subseg over territory nobody
verified (rejected: it lies about verification and corrupts progress
metrics).

## Requested feature

Support **islands**: verified coverage regions that begin at a
human/AI-chosen seed address, with legally-unswept territory before
and after them.

1. **Seeding.** A way to start a new island at an arbitrary address
   (`/pin-start` already expresses the intent; the change is that the
   unswept space before the island is legal, not a red-banner gap).
2. **Gap semantics.** Within an island, the existing invariant is
   unchanged — uncovered bytes between stamps inside an island still
   fire the red banner. Unswept space before the first island, between
   islands, and after the last stamp does not.
3. **Sweep behavior.** Forward sweep proceeds normally inside an
   island from its seed. Stopping a window (leaving the frontier and
   seeding a new island elsewhere) is a legal, supported state — no
   obligation to continue to the binary tail.
4. **Island merging.** When an island's forward sweep reaches the
   first stamp of a later island, they join into one contiguous
   region. Full coverage remains expressible as the degenerate case
   of one island starting at vram.
5. **Yaml compatibility.** Existing full-coverage projects must load
   and behave identically — `DaytonaCCEReverse/config/race.bin.yaml`
   (757 subsegs, 100%, audit mode) is the regression case. Whatever
   representation islands take in `config/<binary>.yaml`, a yaml with
   no island markers means today's semantics.
6. **Progress reporting.** Don't report island work as a misleading
   percent-of-whole-binary alone; per-island coverage (or
   verified-vs-windowed) should be visible.
7. **Everything else unchanged.** Verdict flow, evidence signals
   (reference verdict, static_callers, runtime hits, midpoints,
   yellow flags), partners/entries, analyze mode, unstamp/pin
   endpoints — all keep working within islands.

## Non-goals

- Single-function spot-stamping with no successor context. A
  function's end is only as trustworthy as the identification of the
  next function's start — windowed sweeping is the intended usage
  pattern, not isolated one-function stamps.
- Auto-approve / any change to the human-verdicts rule.

## Motivating windows (DUSA main binary)

| Window | Contents | ~Size |
|---|---|---|
| 0x0602C690–0x06030100 | player physics pipeline (18 calls + dispatcher) | 15 KB |
| 0x06027344–0x060275xx | shared math (sin/cos/atan2/clamp) | <1 KB |
| 0x0600CA96–0x0600CDxx | shared track query system | ~1 KB |
| 0x0600E0C0–0x0600E9xx | drone pipeline (later) | ~2.5 KB |

First real use: seed at 0x0602C690 and sweep the player-pipeline
window. A known open question it must help settle: reference disasm
shows activity at FUN_0602D8C6 while pipeline docs say the position
writer is sym_0602D8BC — midpoint/caller evidence inside this window
will adjudicate.

## Acceptance

1. Fresh DUSA project yaml (`subsegments: []`), seed an island at
   0x0602C690: no red banner for 0x06000000–0x0602C68F; stamping
   proceeds normally from the seed.
2. Introduce a genuine gap inside the island (skip bytes between two
   stamps): red banner fires as today.
3. Seed a second island at 0x06027344 while the first exists: both
   render; no banner between them.
4. Sweep from one island into the start of another: coverage merges.
5. Load `race.bin.yaml` (CCE, full coverage): behavior byte-for-byte
   identical to current master, including audit mode.
