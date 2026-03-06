# Driving Model Boundary Mapping Plan

Canonical copy: `.claude/plans/silly-baking-origami.md`

This file is a snapshot for the workstream directory. If the plan evolves,
the `.claude/plans/` version is authoritative.

See the plan file for full details. Summary of phases:

| Phase | Goal | Deliverable |
|-------|------|-------------|
| A | Code coverage map (CDL) | `function_set.md` |
| B | Data flow boundaries (mem_profile) | `boundary_map.md` |
| C | Call graph boundary (call trace) | `call_boundary.md` |
| D | Guided theory work (NOP tests, watchpoints) | THEORY tags in `reimpl/src/*.s` |
| E | Transplant specification | `transplant_spec.md` |
