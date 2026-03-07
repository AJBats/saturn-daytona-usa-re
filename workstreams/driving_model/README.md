# Driving Model Workstream

Map the Daytona USA driving model boundaries and API surfaces
for transplanting gameplay code to Daytona USA CCE.

## Files

### Workstream docs
| File | Purpose |
|------|---------|
| `driving_model.md` | Workstream status, resolved/open questions |
| `struct_map.md` | Car struct fields — empirically confirmed only |
| `call_tree.md` | Ghidra-derived call tree (structural, not verified) |
| `static_hypotheses.md` | Untested Ghidra hypotheses for experiment design |
| `boundary_mapping_plan.md` | Phase A-D plan for systematic boundary mapping |

### Empirical data (committed artifacts)
| File | Purpose |
|------|---------|
| `function_set.md` | 572 racing-only functions from merged CDL captures |
| `writer_map_car0.md` | Car[0] writer map — which PCs write which struct offsets (60f scripted) |
| `writer_map_comprehensive.md` | Car[0]+Car[1] writer map — 95 offsets, 62K writes (human-driven) |
| `globals_writer_map.md` | Globals region (0x0607E940-0x0607EBE0) writer map — 21 globals |
| `mem_profile_car0_60f.txt` | Raw mem_profile log (60 frames: idle/throttle/steer) |
| `dma_trace_60f.txt` | DMA trace confirming zero DMA writes to car struct |

### Tools
| File | Purpose |
|------|---------|
| `merge_cdl.py` | Merges multiple CDL captures into combined function_set.md |
| `cdl_boundary.py` | CDL report generator for racing vs menu classification |
| `parse_mem_profile.py` | Parses mem_profile into car[N] writer maps (address-only) |
| `parse_globals_profile.py` | Parses mem_profile of globals region into writer map |
| `watch_car_fields.py` | Watchpoint tool for car struct field investigation |

## Reproduction Steps

### CDL function set (function_set.md)

4 captures merged. Each follows the same pattern:

```
boot(cue_path="...Daytona USA (USA).cue", sound=True)
load_state("build/save_states/daytona_rebuilt.*.mc0")  # or manual_trans variant
show_window()
cdl_start()
run_free()
# Human drives (steering, gas, brake, gear shifts, wall hits, etc.)
# pause() when done
cdl_stop()
cdl_dump("build/cdl_<scenario>.bin")
```

Raw CDL bins in `build/`:
- `cdl_racing.csv` — 300 frames idle rolling start (baseline)
- `cdl_racing_input_variant.csv` — ~1,746 frames steering + grass + wall crash
- `cdl_racing_gears.csv` — ~2,194 frames gas/idle/brake, auto transmission
- `cdl_racing_manual_gears.csv` — ~1,732 frames manual transmission gear shifts
- `cdl_menu.csv` — 300 frames menu idle (for SHARED vs RACING_ONLY classification)

Each `.bin` is converted to `.csv` via:
```
python tools/cdl_report.py build/<file>.bin --map reimpl/build/daytona.map --csv > build/<file>.csv
```

Then merged:
```
python workstreams/driving_model/merge_cdl.py
```

### Writer map (writer_map_car0.md)

```
boot(cue_path="...Daytona USA (USA).cue", sound=False)
load_state("build/save_states/daytona_rebuilt.*.mc0")

# Start both traces
mem_profile_start("0x06078900", "0x06078B67")  # car[0], 0x268 bytes exclusive
dma_trace_start()                               # verify no DMA writes

# Phase 1: 20 frames idle (coasting)
frame_advance(20)

# Phase 2: 20 frames throttle
input_press("C")
frame_advance(20)
input_release("C")

# Phase 3: 20 frames steering
input_press("LEFT")
frame_advance(20)
input_release("LEFT")

# Collect
mem_profile_stop()   # -> mem_profile_car0_60f.txt
dma_trace_stop()     # -> dma_trace_60f.txt
```

**Range note**: high address is 0x06078B67 (car base + stride - 1), NOT
0x06078B68. The endpoint is inclusive — using 0x06078B68 captures car[1]+0x00.

**DMA check**: grep the dma_trace for `06078` — should be zero hits.
If any appear, the writer map is incomplete (DMA writes bypass mem_profile).

**Name stripping**: the writer map uses function start addresses from
`reimpl/build/daytona.map`, NOT the LLM-generated symbol names. This prevents
name bias from polluting analysis. Look up names separately if needed.

### Comprehensive writer map (writer_map_comprehensive.md)

Human-driven capture covering collision, braking, steering, grass, cones.
Covers car[0] (95 offsets) and car[1] (32 offsets).

```
boot(cue_path="...Daytona USA (USA).cue", sound=True)
load_state("build/save_states/daytona_rebuilt.*.mc0")
show_window()

# Start all 4 traces simultaneously
mem_profile_start("0x06078900", "0x06078DCF")  # car[0] + car[1]
input_trace_start()
cdl_start()
dma_trace_start()

run_free()
# Human drives: ram car ahead, wall collision, gas/brake/steer, grass, cones
# pause() when done

mem_profile_stop()
input_trace_stop()
cdl_stop()
cdl_dump("build/cdl_racing_comprehensive.bin")
dma_trace_stop()
```

Parse with: `python workstreams/driving_model/parse_mem_profile.py build/mem_profile_comprehensive.txt`

### Globals writer map (globals_writer_map.md)

Scripted 60-frame capture of globals region during idle racing (no input).

```
boot(cue_path="...Daytona USA (USA).cue", sound=False)
load_state("build/save_states/daytona_rebuilt.*.mc0")

mem_profile_start("0x0607E940", "0x0607EBE0")
frame_advance(60)
mem_profile_stop()
```

Parse with: `python workstreams/driving_model/parse_globals_profile.py build/mem_profile_globals_60f.txt`
