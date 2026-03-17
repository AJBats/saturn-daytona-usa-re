# Explorer Priorities — Loop 2, Updated 2026-03-16

**Strategic direction**: TRANSPLANT MANIFEST. We need a complete, gap-free
inventory of every function, data table, global variable, and struct that
must be transplanted from DUSA APROG.BIN into CCE's race.bin. A single
missing dependency crashes the transplant.

The player physics pipeline is exhaustively mapped (18 calls, all verified).
The surrounding infrastructure is NOT. Tonight's goal: classify every
racing-only function as INSIDE or OUTSIDE the physics box.

---

## MISSION: Complete Physics Box Manifest

### Phase 1: Frame orchestrator call graph (top-down trace)

**Goal**: Starting from FUN_0600C010 (racing orchestrator), trace EVERY
function call downward. Build the complete call tree for one racing frame.
Prune at the rendering boundary (FUN_0600B6A0/B914 and everything they call).
Everything that remains is a candidate for the physics box.

**What to do**:
1. Load `usa_tt_straight.mc0`. Run `pc_trace_frame` starting from
   FUN_0600C010 for 1 frame with C held.
2. From the PC trace, extract every unique function address that executes.
   We already have this data from the cycle 6 observation (217K PCs) but
   need it broken down by call chain, not just region.
3. Classify each function:
   - **PHYSICS**: called from the player pipeline or AI loop
   - **RENDERING**: called from FUN_0600B6A0/B914 or FUN_0600D336
   - **SHARED**: called from both (math functions, etc.)
   - **ORCHESTRATION**: frame loop, timing, input polling
4. For each PHYSICS and SHARED function, record:
   - Address and size
   - Caller(s)
   - Pool constants (data table references)
   - Global variables read/written

**Deliverable**: `workstreams/auto_re/observations/frame_call_graph_full.md`

### Phase 2: AI pipeline deep trace

**Goal**: Trace FUN_0600E0C0 (AI car loop) with the same depth as the
player pipeline. The AI loop processes cars 1..39 using FUN_0600e71a
(normal mode) or FUN_0600e906 (AI mode). We need every sub-call and
every data table reference.

**What to do**:
1. Load `daytona_rebuilt.*.mc0` (race mode, 40 cars).
2. Set breakpoint at FUN_0600E0C0 entry. Run `pc_trace_frame` for 1 frame.
3. Extract the AI pipeline call tree. Key sub-functions (from call_tree.md):
   - FUN_0600e71a: normal mode physics (cars 1..N when sym_0607EBC4 bit 15 clear)
   - FUN_0600c5d6: core steering/force dispatcher
   - FUN_0600c4f8: speed/acceleration calculator
   - FUN_0600ca96: friction/drag
   - FUN_0600cf58: collision dispatch
   - FUN_0600cc38: force application
   - FUN_0600c8cc: heading calculator
   - FUN_0600c928: heading correction
   - FUN_0600c7d4: heading/speed damping
   - FUN_0600ceba: track segment advance
4. For each AI sub-function, dump its pool constants to find data table
   references. Use `read_memory` on the pool region (typically 0x20-0x80
   bytes after the function body).

**Deliverable**: `workstreams/auto_re/observations/ai_pipeline_full_obs.md`

### Phase 3: Collision detection system

**Goal**: Find the collision DETECTION code (not response — we have that).
Something sets car[+0x04] (collision target) and car[+0x9E] (collision
flag). That code must be in the physics box.

**What to do**:
1. Load `daytona_rebuilt.*.mc0`. Hold C + RIGHT to drive into the wall.
2. Set watchpoint on car[+0x04] (0x06078904) — it should trigger when
   collision is detected. Record the writer PC.
3. Also try watchpoint on car[+0x9E] (0x0607899E, 16-bit — may need
   the `sample_memory` approach instead due to watchpoint limitations).
4. If watchpoints fail: sample car[+0x04] every frame during the wall
   approach. The first frame it changes from 0 reveals the collision
   detection timing. Then use `pc_trace_frame` on THAT frame to find
   the detection code.

**Deliverable**: `workstreams/auto_re/observations/collision_detection_obs.md`

### Phase 4: Data section catalog

**Goal**: Dump every data table referenced by physics functions. These
are embedded in the code section (pool constants) or in the data region
(0x0604xxxx-0x0605xxxx). The transplant must include ALL of them.

**What to do**:
1. For each known physics function, read its pool constant region and
   extract all `.4byte` addresses that point to data tables (addresses
   in the 0x0604xxxx-0x0606xxxx range, NOT function addresses).
2. Known tables to verify are present:
   | Table | Address | Size | Purpose |
   |-------|---------|------|---------|
   | Gear ratios | sym_060477BC | 32 bytes | Speed→force scaling |
   | Gear-up thresholds | sym_060477AC | 16 bytes | Upshift triggers |
   | Gear-down thresholds | sym_0604779C | 16 bytes | Downshift triggers |
   | Section scaling | sym_060477CC | 16 bytes | Gear change speed recomp |
   | Traction force | sym_0602E938 | 128 bytes | Gear × section force |
   | Track force bounds | sym_0602F3CC | 32 bytes | Force clamp per gear |
   | Drift scaling | sym_0602E8B8 | 64 bytes | Drift velocity multiplier |
   | Animation states | sym_060477D8 | 20 bytes | Display state lookup |
   | Surface table | [sym_0607EB88] | 12544 bytes | Track physics geometry |
   | Segment table | [sym_0607EB84] | 588 bytes | Track progress milestones |
   | Button mapping | sym_06081888 | 12 bytes | Controller button masks |
   | Speed tables (AI) | 0x060477EC | TBD | AI acceleration lookup |
   | Speed tables (AI) #2 | 0x060454CC | TBD | AI second accel table |
   | Collision speed | 0x060453B4 | TBD | Collision bounce magnitude |
   | Collision speed #2 | 0x060453C4 | TBD | Collision bounce #2 |
   | Gear shift timing | 0x060453CC | TBD | Gear shift animation |
   | Steering kick S-curve | 0x060453CC | 33 entries | Gear shift steering kick |
3. For any NEW table addresses found in Phase 2 (AI pipeline), dump those too.
4. Also check: are there tables in the 0x0605xxxx range? Or in WRAM High
   outside the binary (like the track data at 0x060Cxxxx)?

**Deliverable**: `workstreams/auto_re/observations/data_tables_manifest.md`

### Phase 5: Globals region complete audit

**Goal**: Identify EVERY global variable the physics box reads or writes.
The globals_writer_map.md has 21 globals with WRITE data. We need READS too.

**What to do**:
1. Known physics globals (from struct_map.md and writer_map):
   | Address | Name | Role |
   |---------|------|------|
   | 0x0607E940 | sym_0607E940 | Current car pointer |
   | 0x0607E944 | sym_0607E944 | Player car pointer |
   | 0x0607E948 | sym_0607E948 | Car array base (car[1]) |
   | 0x0607EA98 | sym_0607EA98 | Car count |
   | 0x0607EAAC | sym_0607EAAC | Race countdown timer |
   | 0x0607EBC4 | sym_0607EBC4 | Pipeline mode flag |
   | 0x0607EBD0 | sym_0607EBD0 | Speed/progress threshold |
   | 0x0607EBDC | sym_0607EBDC | Car iteration index |
   | 0x0607EB84 | sym_0607EB84 | Track segment table ptr |
   | 0x0607EB88 | sym_0607EB88 | Surface table ptr |
   | 0x06063D98 | sym_06063D98 | g_pad_state (controller) |
   | 0x060635C4 | (unnamed) | VBlank semaphore |
   | 0x06078680 | sym_06078680 | Surface buffer |
   | 0x06078900 | sym_06078900 | Car struct array base |
2. Use `mem_profile` on the globals region (0x0607E940-0x0607EC00) for
   60 frames of racing. This captures ALL writes. Cross-reference with
   the existing globals_writer_map.md to find any new globals.
3. For READS: search all physics function pool constants for addresses
   in the 0x0607xxxx range. Each is a global variable read.
4. Also check: does the physics read from the button mapping table region
   (0x06081888)? From the car struct region header? From any other
   fixed address outside the code section?

**Deliverable**: `workstreams/auto_re/observations/globals_audit.md`

### Phase 6: Shared math function inventory

**Goal**: List every shared math/utility function called by physics code.
These are small but critical — a missing sin/cos lookup crashes everything.

**Known shared functions** (from pipeline observations):
| Address | Name | Size | Purpose |
|---------|------|------|---------|
| 0x06027344 | FUN_06027344 | ~4 | cos lookup |
| 0x06027348 | cos_lookup | ~16 | cos table entry |
| 0x0602734C | sin_lookup | ~16 | sin table entry |
| 0x0602735C | FUN_06027358 | ~32 | sin/cos pair call |
| 0x0602737C | FUN_06027378 | ~212 | inverse trig |
| 0x06027450 | atan2 | ~16 | atan2 entry |
| 0x0602744C | FUN_0602744C | ~4+ | atan2 variant |
| 0x0602749C | isqrt | ~34 | integer sqrt |
| 0x06027550 | swap_sign_ext | ~6 | sign extension |
| 0x06027556 | fpdiv_setup | ~10+ | fixed-point divide |
| 0x06027560 | fpdiv_setup | ~24 | FP divide setup |
| 0x06027610 | memcpy_byte_idx | ~18 | byte copy |
| 0x06027622 | memcpy_word_idx | ~18 | word copy |
| 0x06027634 | memcpy_long_idx | ~18 | long copy |
| 0x0602755C | FUN_0602755C | ~TBD | clamp/normalize |
| 0x0602ECCC | FUN_0602ECCC | ~TBD | atan2/rotation computation |

**What to do**:
1. Verify this list is complete by scanning all physics function pool
   constants for addresses in the 0x06027xxx range.
2. For each shared function, read its pool constants to find any data
   table dependencies (sin/cos lookup tables, etc.).
3. Check: do the sin/cos functions read from a lookup table in the data
   section? If so, that table must be transplanted too.
4. Measure exact sizes (read_memory at each address, find the `rts`).

**Deliverable**: `workstreams/auto_re/observations/shared_math_manifest.md`

---

## Output Format

For each phase, produce the observation file with:

```
FUNCTIONS:
  0xADDRESS | size_bytes | name | caller | role

DATA TABLES:
  0xADDRESS | size_bytes | name | referenced_by | content_description

GLOBALS:
  0xADDRESS | size_bytes | name | readers | writers | initial_value

STRUCTS:
  base_address | stride | count | description
```

The final manifest will be assembled from all 6 phase outputs into:
`workstreams/driving_model/transplant_manifest.md`

---

## Priority Order

1. Phase 1 (frame call graph) — gives us the total function count
2. Phase 4 (data tables) — can run in parallel with Phase 1
3. Phase 2 (AI pipeline) — fills the biggest function gap
4. Phase 3 (collision detection) — fills the biggest behavioral gap
5. Phase 5 (globals audit) — completeness check
6. Phase 6 (shared math) — can partially derive from Phase 1 output

Phases 1+4 first, then 2+3 in parallel, then 5+6 as cleanup.

---

## QUICK WINS (from Mapper static analysis, cycle 56)

### QW1: Dump 5 AI-exclusive data tables

The Mapper cataloged all AI pipeline pool constants. 5 tables need their
contents dumped to determine sizes:

```
read_memory 0x060477EC 128    # AI speed table 1 (FUN_0600C4F8)
read_memory 0x060454CC 128    # AI speed table 2 (FUN_0600C4F8)
read_memory 0x060453B4 32     # Collision speed 1 (sym_06008640)
read_memory 0x060453C4 32     # Collision speed 2 (sym_06008640)
read_memory 0x060453CC 128    # Gear shift timing (FUN_06008318)
```

These are from the race-start save state (tables are static in APROG.BIN).
Look for the end of meaningful data (zeros or repeating patterns) to
determine actual table sizes.

### QW2: FUN_0600D26A identification

FUN_0600D26A is called by FUN_0600E71A (AI pipeline) for every car but
is not in the call_tree.md or any observation. Read its Ghidra decompilation
or disassemble ~64 bytes to identify its role and data dependencies.

```
read_memory 0x0600D26A 64     # Disassemble to identify
```

### QW3: Classify 3 unknown orchestrator sub-calls

Three functions called by FUN_0600C010 have unknown roles:

```
# FUN_060058FA — subsystem init, calls 4 sub-functions
read_memory 0x060058FA 64     # Or check ghidra_reference/FUN_060058FA.c

# FUN_0600D31C — input/rendering gate, conditional on sym_0607EBC4 bit 21
read_memory 0x0600D31C 64     # Does it do input polling?

# FUN_06034708 — secondary SH-2 dispatch, copies car[+0x10]=car[+0x0C]
read_memory 0x06034708 64     # What does it send to secondary CPU?
```

For each: does it read/write car struct fields? If yes, it may need transplanting.
If it's pure rendering/sound, it can be excluded.

### QW4: Collision mechanism — call-trace differential at graze frame

**Goal**: Determine if car-to-car collision uses a separate detection function
or is emergent from the existing pipeline taking different paths.

**Static analysis leads** (Mapper cycle 59):

1. **sym_06078680 (shared surface buffer)**: FUN_0600CA96 writes to it for
   EVERY car. FUN_0602F5B6 (player call 11) reads from it. If AI car writes
   change this buffer before the player reads it, that's the collision path.
   **Test**: read_u32 at sym_06078680 (and +4, +8, +0xC, +0x10) at frame 100
   (pre-graze) and frame 101 (graze). If values differ, the buffer IS shared.

2. **sym_0602F4B4 (proximity check, call 10)**: Sets car[+0xD6] = 0x14 when
   opponent within 0x1E0000 distance. This ONLY writes +0xD6 in the assembly.
   But it runs BEFORE the surface writer (call 11) and force accumulator (call 15).
   **Test**: read car[+0xD6] at frames 98-103 during graze. If it goes from 0 to
   20 (0x14) at the contact frame, proximity detection IS triggering.

3. **FUN_0600C5D6 (AI steering/force)**: Has a conditional at car[+0x208] and
   car[+0x204] that triggers a SECOND call to FUN_0600CA96. If collision state
   is active, the surface buffer gets re-sampled.
   **Test**: read car[+0x204] and car[+0x208] for the AI car being grazed during
   frames 98-105.

**The definitive experiment**: Run `pc_trace_frame` at frame 100 (pre-contact)
AND frame 101 (contact) of the car_graze replay. Diff the two traces:
- Same functions, same order → pipeline paths diverge (branch-level change)
- New function appears → explicit collision detection we missed
- Same functions, different CALL COUNTS → some function runs extra iterations

This tells us exactly what code changes behavior at the collision moment.

### QW5: Globals read audit (sym_0607EA9C)

The AI pipeline reads sym_0607EA9C (segment distance limit) which is NOT
in the globals_writer_map.md. Check its value and whether it changes
during racing.

```
read_u32 0x0607EA9C           # Read current value
```
