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
| `writer_map_car0.md` | Car[0] writer map — which PCs write which struct offsets |
| `mem_profile_car0_60f.txt` | Raw mem_profile log (60 frames: idle/throttle/steer) |
| `dma_trace_60f.txt` | DMA trace confirming zero DMA writes to car struct |

### Tools
| File | Purpose |
|------|---------|
| `merge_cdl.py` | Merges multiple CDL captures into combined function_set.md |
| `cdl_boundary.py` | CDL report generator for racing vs menu classification |
| `watch_car_fields.py` | Watchpoint tool for car struct field investigation |
