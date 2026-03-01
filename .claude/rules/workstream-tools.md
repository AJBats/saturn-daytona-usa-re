# Workstream Tool Co-location

When a workstream needs its own scripts/tools, promote it to a directory:

```
workstreams/<name>/
  <name>.md          # the workstream doc (same name as the dir)
  tool_a.py          # workstream-specific tools live here
  tool_b.py
```

`tools/` is for shared infrastructure only (build, validation, codegen, toolchain).
Workstream-specific scripts never go in `tools/`.
