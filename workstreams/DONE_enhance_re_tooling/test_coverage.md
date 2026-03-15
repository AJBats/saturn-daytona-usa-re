# Coverage Statistics — Test Results

Tool: `tools/coverage.py`
Run: `python tools/coverage.py --output build/coverage.json`

## Results

### Symbol Naming (4349 symbols in code range)
| Category | Count | % |
|---|---|---|
| Human-named | 1253 | 28.8% |
| FUN_ (unnamed functions) | 21 | 0.5% |
| sym_ (sublabels) | 1074 | 24.7% |
| DAT_ (data) | 1293 | 29.7% |
| loc_ (locations) | 708 | 16.3% |

### Byte Coverage
| Metric | Value | % |
|---|---|---|
| Total code bytes | 394,720 | 100% |
| Named bytes | 149,902 | 38.0% |
| Unnamed bytes | 244,818 | 62.0% |

### Source Files
- L3 assembly (.s): 1046
- C reimpl (.c): 0
- Retail .s files: 1049

### Function Database Enrichment
- SDK identified: 20 functions
- HW tagged: 7 functions
- String data: 249 locations
- Any tag: 276 entries

### Top 10 Largest Functions
1. FUN_0603990E — 1806 bytes
2. FUN_0601BE64 — 1408 bytes
3. FUN_06022AE0 — 1388 bytes
4. FUN_0602FDB0 — 1302 bytes
5. FUN_06029740 — 1204 bytes

### Key Insights

- Only 21 functions still have FUN_ prefix (0.5%) — most have been renamed
- sym_/DAT_/loc_ labels dominate (70.7%) — these are sub-labels within larger TUs
- 38% byte coverage means we've named the functions containing 38% of code
- The largest function (FUN_0603990E) is 1806 bytes
- No C reimplementations yet (all src/ is L3 assembly)

## Verdict: PASS

Coverage tool provides accurate project-wide metrics. JSON output supports
dashboard tracking over time.
