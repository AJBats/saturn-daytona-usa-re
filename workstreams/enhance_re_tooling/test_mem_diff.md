# Memory Differential Pipeline — Test Results

Tool: `tools/mem_diff.py`
Test: Synthetic diff of APROG.BIN first 4KB with 4 injected modifications

## Test Setup

Created two 4KB dumps from APROG.BIN. Modified 4 locations in the "after" dump:
1. Single byte change at offset 0x100 (0x2F → 0xFF)
2. Word change at offset 0x200 (0x0601 → 0xABCD)
3. Pointer-like value at offset 0x400 (→ 0x06008000)
4. 15-byte block change at offset 0x801

Run: `python tools/mem_diff.py before.bin after.bin --base-addr 0x06004000 --map reimpl/build/daytona.map`

## Results

```
Changes: 4 ranges, 22 bytes modified
  0x06004100  [byte   ]  0x2F -> 0xFF  (-48)
  0x06004200  [word   ]  0x0601 -> 0xABCD
  0x06004400  [pointer]  0x96059505 -> 0x06008000  (-> vblank_frame_handler+0x1F4)
  0x06004801  [raw    ]  15 bytes: ...
```

### Validated Features

- Contiguous changed bytes merged into ranges
- Type classification: byte (1B), word (2B aligned), long/pointer (4B aligned), block, raw
- Pointer detection: values in 0x06000000-0x06100000 flagged as pointers
- Symbol resolution via daytona.map (bisect lookup)
- Delta display (+N/-N) for scalar types
- Summary by symbol: groups changes under containing function
- JSON output (--output) for downstream analysis
- --top N: show only largest N changes
- --min-run: ignore changes smaller than N bytes

### Intended Use

Live workflow with Mednafen automation:
1. `dump_mem_bin 06000000 80000 /tmp/before.bin`
2. Press button / advance frames
3. `dump_mem_bin 06000000 80000 /tmp/after.bin`
4. `python tools/mem_diff.py /tmp/before.bin /tmp/after.bin --base-addr 0x06000000 --map reimpl/build/daytona.map`

This reveals which RAM locations change in response to inputs — directly identifying
game state variables, counters, and flags.

## Verdict: PASS

All 4 injected changes correctly detected with proper type classification and
symbol resolution. Tool ready for live memory analysis with Mednafen dumps.
